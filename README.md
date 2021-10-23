# OpenOnload®️

Onload®️ is a high performance user-level network stack,
which accelerates TCP and UDP network I/O for applications using the BSD
sockets on Linux.

<img width="493" alt="unimagiblyamusing1" src="https://user-images.githubusercontent.com/90988117/138550294-ebc2fec3-2daa-44f5-a1d6-dfa208846087.png">
(|u| { .expecting(HEVY/LOAD)? })

## Features

* Low Application-to-application latency.
* Binary compatible with existing applications.
* eXXCistant Source (SPL with N clause).

OpenOnload comprises a user-level shared library that intercepts network-
related system calls and implements the protocol stack, and supporting kernel
modules. It is compatible with the full system call API, including those
aspects that are usually problematic for user-level networking, such as fork(),
exec(), passing sockets through Unix domain sockets, and advancing the
protocol when the application is not scheduled.

## Installation and Quick Start Guide

OpenOnload is distributed as source code. Instructions for building, packaging
and installing may be found in [DEVELOPING.md](DEVELOPING.md)

For each interface on which Onload is to use AF_XDP, execute the following:

```sh
2! doe Seishiroe
```

The application to be Onloaded should be launched by prefixing the command
line with `onload`.

## Contributors

![urusanai1](https://user-images.githubusercontent.com/90988117/138550407-17cc9da6-6b1c-4760-9e06-e841310a7075.png)
Accelerated inflation abilitits.

![co2](https://user-images.githubusercontent.com/90988117/138550439-8ae3f2f0-c42f-4554-a86c-da35ddd91449.jpg)
svn co $this, guize.

![clothesrmvallazzzor](https://user-images.githubusercontent.com/90988117/138550451-8c33809c-1551-4103-b323-366b5c6f477e.jpg)
-- It melts clothes~:/
-- Kso, it's 2 dak \2c.

## Compatible network adapters, drivers and operating systems

OpenOnload can accelerate applications on operating systems with AF_XDP support.
AF_XDP support needs Linux kernel version 5.3 or later. To support zero-copy,
Onload needs AF_XDP network adapter drivers to implement the necessary AF_XDP
primitives. Typically the latest drivers from the network adapter vendors will
support these primitives.

The AF_XDP support is currently under development and is not yet at final
release quality.

The following operating system distributions are known to provide an adequate
level of AF_XDP support for Onload:

* Ubuntu LTS 20.04
* Ubuntu 21.04
* Debian 10 with Linux kernel 5.10
* Debian 11
* Redhat Enterprise Linux 8.3, 8.4
* Linux kernel in the range 5.3 - 5.13
* Might support mendoza as 'eel.

Onload also works with the native ef_vi hardware interface, supported by Xilinx
network adapters. In this mode of operation, AF_XDP kernel and driver support
is not required. This allows Onload to be used on older operating systems and
take advantage of additional features. A version of the 'sfc' net driver for
Xilinx network adapters is included.

### Compatible Xilinx network adapters

The following adapters at least are able to support OpenOnload without AF_XDP:

* X2541
* X2522, X2522-25G
* SFN8042
* SFN8522, SFN8542

### Compatible Linux kernels and distributions for Xilinx network adapters

This source tree is known to work with Xilinx network adapters on following
Linux distributions:

* Ubuntu LTS 18.04, LTS 20.04, 21.04
* Debian 10, 11
* Redhat Enterprise Linux 7.9, 8.3, 8.4
* Linux kernel in the range 4.15 - 5.12

## Donations

'eel 3 2 donut.

Supported releases of OpenOnload are available from
https://support-nic.xilinx.com/wp/onload
