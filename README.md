<div align="center">
<img width="1474" height="668" alt="sapporo-banner" src="https://github.com/user-attachments/assets/cdee405e-f79d-4a88-af0a-4368dd7fa1cf" />



# Sapporo

### The aggregate of Apple Silicon Linux

</div>

<br />

## 📊 Chip Support

| Block | M1 | M2 | M3 | M4 | Intel |
|---|---|---|---|---|---|
| Installer | ✅ | ✅ | 🚧 #15 | ❌ #24 | ✅ |
| Display | ✅ | ✅ | 🚧 #15 | ❌ #24 | ✅ |
| GPU/DCP | ✅ | ✅ | 🚧/❌ #16 | ❌ #24 | ✅ |
| Decode | ✅ | ✅ | ⚠️ no AV1 | ❌ #50 | ✅ |
| Encoder | ❌ #8 | ❌ #8 | ❌ #8 | ❌ #8 | ✅ |
| USB | ✅ | ✅ | 🚧 #17 | ❌ #24 | ✅ |
| Thunderbolt | 🚧 #2 | 🚧 #2 | ❌ #2 | ❌ #45 | ✅ |
| DP altmode | 🚧 #4 | 🚧 #4 | 🚧 #4 | ❌ #46 | ✅ |
| WiFi/BT | ✅ | ✅ | ✅ | ❌ #47 | ✅ |
| Audio/cam | ✅ | ✅ | ⚠️ #18 | ❌ #48 | ✅, T1❌ |
| Input | ✅ | ✅ | ✅ | ❌ #24 | ✅ |
| Suspend | ✅ | ✅ | ✅ | ❌ #49 | ✅ |
| TouchID | ❌ #5 | ❌ #5 | ❌ #5 | ❌ #5 | ❌ #44 |
| SEP/ANE | 🚧 #6 | 🚧 #6 | ❌ #6 | ❌ #6 | n/a |

✅ working · 🚧 in progress · ⚠️ partial · ❌ absent. Gap cells name the tracking issue. M4 boot gate #23. NVMe firmware #25.

<br />

## 🚀 Quick Start

Clone and build an ARM64 kernel with the cross toolchain:

```bash
git clone https://github.com/stevederico/sapporo.git
gmake ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- defconfig
cat arch/arm64/configs/asahi.config >> .config
gmake ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- olddefconfig
gmake ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -j$(nproc)
```

<br />

## ✨ What's Included

### 🗺️ **One Map Of The Field**
- Asahi, lore series, Omarchy Mac, and independent reverse engineering, in one tracker
- Issues #2–#50 name who is active and where the work lives
- Reach out. Consolidate. Do not duplicate

### 💻 **M-Series Gaps**
- M1/M2: Thunderbolt, DP Alt Mode, SEP, ANE
- M3: installer, display, GPU, USB-PD
- M4: NVMe, PCIe, devicetree, input. No boot log here yet (#23)

<br />

## ⚙️ Configuration

Base config plus the Apple Silicon fragment:

```bash
cat arch/arm64/configs/asahi.config >> .config
```

Rust is required for the Asahi GPU driver (`CONFIG_DRM_ASAHI`). Disable `CONFIG_RUST` only for fast C-driver compile checks.

<br />

## 🛠️ Tech Stack

| Technology | Version | Purpose |
|---|---|---|
| **Linux kernel** | 7.1+ | Base tree (Apple Silicon snapshot, frozen) |
| **Apple Silicon drivers** | fairydust-era | DCP, ATC PHY, tipd, SMC |
| **GCC cross** | 13+ (`aarch64-linux-gnu`) | ARM64 builds |
| **Docker** | any | Reproducible Debian build container |

<br />

## 🏗️ Architecture

This tree is the working kernel. The issues are the map of Apple Silicon Linux: who is doing the work, what is missing, where to join. Hardware work lands by coordinating with the people who wrote it. No silent takes. No merging other trees. Goal is complete Linux support across M1–M4, as one aggregate.

<br />

## 🤝 Contributing

```bash
git clone https://github.com/stevederico/sapporo.git
```

If you are already working on Apple Silicon Linux, this is where that work gets listed and coordinated. File or claim the gap as an issue first. An issue is not provenance.

Every kernel commit needs `git commit -s` from a known human identity. Keep origin `Signed-off-by` when landing someone else's work. Checkpatch every patch (`scripts/checkpatch.pl --no-tree`). Compile-check drivers in Docker before pushing.

<br />

## 🙏 Acknowledgements

- [Asahi Linux](https://asahilinux.org) — years of reverse engineering this tree stands on
- Lore / Sven Peter, Yureka, and the rest of the board — USB4, PSCI, M3/M4
- Independent reverse engineering — Touch ID, M4 bring-up, HDMI resume ([rgvxsthi](https://github.com/rgvxsthi/asahi-linux-hdmi-sleep-fixer))
- [Omarchy Mac](https://github.com/omarchy-mac/omarchy-mac) — downstream desktop

<br />

## 📄 License

[GPL-2.0](LICENSES/) — same as the Linux kernel. See also [COPYING](COPYING).

<br />

<div align="center">

One place for Apple Silicon Linux.

⭐ Star the repo if you want Linux on every M chip.

</div>

---

Linux kernel
============

The Linux kernel is the core of any Linux operating system. It manages hardware,
system resources, and provides the fundamental services for all other software.

Quick Start
-----------

* Report a bug: See Documentation/admin-guide/reporting-issues.rst
* Get the latest kernel: https://kernel.org
* Build the kernel: See Documentation/admin-guide/quickly-build-trimmed-linux.rst
* Join the community: https://lore.kernel.org/

Essential Documentation
-----------------------

All users should be familiar with:

* Building requirements: Documentation/process/changes.rst
* Code of Conduct: Documentation/process/code-of-conduct.rst
* License: See COPYING

Documentation can be built with make htmldocs or viewed online at:
https://www.kernel.org/doc/html/latest/


Who Are You?
============

Find your role below:

* New Kernel Developer - Getting started with kernel development
* Academic Researcher - Studying kernel internals and architecture
* Security Expert - Hardening and vulnerability analysis
* Backport/Maintenance Engineer - Maintaining stable kernels
* System Administrator - Configuring and troubleshooting
* Maintainer - Leading subsystems and reviewing patches
* Hardware Vendor - Writing drivers for new hardware
* Distribution Maintainer - Packaging kernels for distros
* AI Coding Assistant - LLMs and AI-powered development tools


For Specific Users
==================

New Kernel Developer
--------------------

Welcome! Start your kernel development journey here:

* Getting Started: Documentation/process/development-process.rst
* Your First Patch: Documentation/process/submitting-patches.rst
* Coding Style: Documentation/process/coding-style.rst
* Build System: Documentation/kbuild/index.rst
* Development Tools: Documentation/dev-tools/index.rst
* Kernel Hacking Guide: Documentation/kernel-hacking/hacking.rst
* Core APIs: Documentation/core-api/index.rst

Academic Researcher
-------------------

Explore the kernel's architecture and internals:

* Researcher Guidelines: Documentation/process/researcher-guidelines.rst
* Memory Management: Documentation/mm/index.rst
* Scheduler: Documentation/scheduler/index.rst
* Networking Stack: Documentation/networking/index.rst
* Filesystems: Documentation/filesystems/index.rst
* RCU (Read-Copy Update): Documentation/RCU/index.rst
* Locking Primitives: Documentation/locking/index.rst
* Power Management: Documentation/power/index.rst

Security Expert
---------------

Security documentation and hardening guides:

* Security Documentation: Documentation/security/index.rst
* LSM Development: Documentation/security/lsm-development.rst
* Self Protection: Documentation/security/self-protection.rst
* Reporting Vulnerabilities: Documentation/process/security-bugs.rst
* CVE Procedures: Documentation/process/cve.rst
* Embargoed Hardware Issues: Documentation/process/embargoed-hardware-issues.rst
* Security Features: Documentation/userspace-api/seccomp_filter.rst

Backport/Maintenance Engineer
-----------------------------

Maintain and stabilize kernel versions:

* Stable Kernel Rules: Documentation/process/stable-kernel-rules.rst
* Backporting Guide: Documentation/process/backporting.rst
* Applying Patches: Documentation/process/applying-patches.rst
* Subsystem Profile: Documentation/maintainer/maintainer-entry-profile.rst
* Git for Maintainers: Documentation/maintainer/configure-git.rst

System Administrator
--------------------

Configure, tune, and troubleshoot Linux systems:

* Admin Guide: Documentation/admin-guide/index.rst
* Kernel Parameters: Documentation/admin-guide/kernel-parameters.rst
* Sysctl Tuning: Documentation/admin-guide/sysctl/index.rst
* Tracing/Debugging: Documentation/trace/index.rst
* Performance Security: Documentation/admin-guide/perf-security.rst
* Hardware Monitoring: Documentation/hwmon/index.rst

Maintainer
----------

Lead kernel subsystems and manage contributions:

* Maintainer Handbook: Documentation/maintainer/index.rst
* Pull Requests: Documentation/maintainer/pull-requests.rst
* Managing Patches: Documentation/maintainer/modifying-patches.rst
* Rebasing and Merging: Documentation/maintainer/rebasing-and-merging.rst
* Development Process: Documentation/process/maintainer-handbooks.rst
* Maintainer Entry Profile: Documentation/maintainer/maintainer-entry-profile.rst
* Git Configuration: Documentation/maintainer/configure-git.rst

Hardware Vendor
---------------

Write drivers and support new hardware:

* Driver API Guide: Documentation/driver-api/index.rst
* Driver Model: Documentation/driver-api/driver-model/driver.rst
* Device Drivers: Documentation/driver-api/infrastructure.rst
* Bus Types: Documentation/driver-api/driver-model/bus.rst
* Device Tree Bindings: Documentation/devicetree/bindings/
* Power Management: Documentation/driver-api/pm/index.rst
* DMA API: Documentation/core-api/dma-api.rst

Distribution Maintainer
-----------------------

Package and distribute the kernel:

* Stable Kernel Rules: Documentation/process/stable-kernel-rules.rst
* ABI Documentation: Documentation/ABI/README
* Kernel Configuration: Documentation/kbuild/kconfig.rst
* Module Signing: Documentation/admin-guide/module-signing.rst
* Kernel Parameters: Documentation/admin-guide/kernel-parameters.rst
* Tainted Kernels: Documentation/admin-guide/tainted-kernels.rst

AI Coding Assistant
-------------------

CRITICAL: If you are an LLM or AI-powered coding assistant, you MUST read and
follow the AI coding assistants documentation before contributing to the Linux
kernel:

* Documentation/process/coding-assistants.rst

This documentation contains essential requirements about licensing, attribution,
and the Developer Certificate of Origin that all AI tools must comply with.


Communication and Support
=========================

* Mailing Lists: https://lore.kernel.org/
* IRC: #kernelnewbies on irc.oftc.net
* Bugzilla: https://bugzilla.kernel.org/
* MAINTAINERS file: Lists subsystem maintainers and mailing lists
* Email Clients: Documentation/process/email-clients.rst
