/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* X-SPDX-Copyright-Text: (c) Copyright 2019-2020 Xilinx, Inc. */

#ifndef CI_EFHW_EFCT_H
#define CI_EFHW_EFCT_H
#include <etherfabric/internal/efct_uk_api.h>
#include <ci/driver/ci_efct.h>

extern struct efhw_func_ops efct_char_functional_units;

struct efhw_efct_rxq;
struct xlnx_efct_hugepage;
typedef void efhw_efct_rxq_free_func_t(struct efhw_efct_rxq*);

struct efhw_efct_rxq {
  struct efhw_efct_rxq *next;
  struct efab_efct_rxq_uk_shm *shm;
  unsigned qid;
  bool destroy;
  uint32_t next_sbuf_seq;
  size_t n_hugepages;
  uint32_t current_owned_superbufs;
  uint32_t max_allowed_superbufs;
  DECLARE_BITMAP(owns_superbuf, CI_EFCT_MAX_SUPERBUFS);
  efhw_efct_rxq_free_func_t *freer;
};

/* TODO EFCT find somewhere better to put this */
#define CI_EFCT_MAX_RXQS  8

struct efhw_nic_efct_rxq {
  struct efhw_efct_rxq *new_apps;  /* Owned by process context */
  struct efhw_efct_rxq *live_apps; /* Owned by NAPI context */
  struct efhw_efct_rxq *destroy_apps; /* Owned by NAPI context */
  uint32_t superbuf_refcount[CI_EFCT_MAX_SUPERBUFS];
  /* Tracks buffers passed to us from the driver in order they are going
   * to be filled by HW. We need to do this to:
   *  * progressively refill client app superbuf queues,
   *    as x3net can refill RX ring with more superbufs than an app can hold
   *    (or if queues are equal there is a race)
   *  * resume a stopped app (subset of the above really),
   *  * start new app (without rollover)
   */
  struct efab_efct_rx_superbuf_queue sbufs;
  struct work_struct destruct_wq;
};

struct efhw_nic_efct {
  struct efhw_nic_efct_rxq rxq[CI_EFCT_MAX_RXQS];
  struct xlnx_efct_device *edev;
  struct xlnx_efct_client *client;
};

#if CI_HAVE_EFCT_AUX
int efct_nic_rxq_bind(struct efhw_nic *nic, int qid,
                      const struct cpumask *mask, bool timestamp_req,
                      size_t n_hugepages, struct file* memfd, off_t* memfd_off,
                      struct efab_efct_rxq_uk_shm *shm,
                      struct efhw_efct_rxq *rxq);
void efct_nic_rxq_free(struct efhw_nic *nic, struct efhw_efct_rxq *rxq,
                       efhw_efct_rxq_free_func_t *freer);
int efct_get_hugepages(struct efhw_nic *nic, int hwqid,
                       struct xlnx_efct_hugepage *pages, size_t n_pages);
#endif

static inline void efct_app_list_push(struct efhw_efct_rxq **head,
                                      struct efhw_efct_rxq *app)
{
  struct efhw_efct_rxq *next;
  do {
    app->next = next = *head;
  } while( cmpxchg(head, next, app) != next );
}

#endif /* CI_EFHW_EFCT_H */
