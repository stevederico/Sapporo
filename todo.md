# Sapporo TODO — full M-series gap list (Sep 2026)

Independent fork. No upstream merges (`upstream` remote removed).
Cherry-pick from AsahiLinux/linux by hand. AI-assisted work can never
go upstream (Asahi slop ban) — this fork is the permanent home.

Status key: yes / WIP / TBA / no. Source: Asahi feature-support docs
plus LKML/lore patch series, checked Sep 2026.

## SoC-block gaps (all chips)

- [ ] Thunderbolt/USB4: Sven Peter 19-patch series (Aug 2026, ACIO
      bring-up). XDomain + USB3 tunnels work. Missing: PCIe tunnels,
      DP tunnels, suspend with active connection (SErr on resume).
      M1/M2 device-tree nodes in series; M3 nodes pending. Track lore
      series `20260830-b4-apple-soc-tbt`.
- [ ] DP Alt Mode single-port: Asahi `fairydust` branch. One blessed
      port per machine, hotplug quirks, DCP color/timing bugs. Not
      officially supported. Base for our work.
- [ ] DP Alt Mode multi-port: nobody upstream. Our branch only.
- [ ] TouchID: TBA on every chip. Feasibility unknown — research SEP
      dependency first.
- [ ] SEP driver: WIP M1/M2, TBA M3/M4. Track.
- [ ] ANE: out-of-tree module https://github.com/eiln/ane/tree/main —
      merge into our tree.
- [ ] Video encoder: TBA everywhere. Scope only on demand.
- [ ] ProRes codec: TBA (M1 plain absent). Defer.
- [ ] cpuidle: hacked WFI driver, never upstreamable. Watch UEFI
      Runtime Service PSCI-conduit RFC. Adopt if accepted.
- [ ] GPU direct scan-out (DCP reads AGX / Interchange frames):
      experimental in Mesa + DCP driver. Track, adopt when stable.

## M1 (T8103/T600x) — installer yes, ~90%

- [ ] Thunderbolt / DP altmode (see SoC-block items)
- [ ] iMac 2021 speakers TBA; iMac mic WIP
- [ ] TouchID / SEP / ANE / encoder (see SoC-block items)
- [ ] Mac Studio HDMI audio excluded on Ultra — verify

## M2 (T8112/T602x) — installer yes (Mac Pro WIP), ~85%

- [ ] Mac Pro (2023): installer WIP, HDMI audio WIP, speakers TBA
- [ ] Thunderbolt / DP altmode (see SoC-block items)
- [ ] TouchID / SEP / ANE / encoder (see SoC-block items)

## M3 (T8122/T603x) — installer WIP, ~50%

- [ ] Installer + main display + brightness (all WIP, depend on DCP)
- [ ] DCP WIP all variants; GPU WIP base, TBA Pro/Max/Ultra
- [ ] USB2/USB3 + USB-PD WIP (ACE3 SPMI done, integrate)
- [ ] Thunderbolt TBA (USB4 series covers M3 code, nodes pending)
- [ ] Webcam WIP (laptops); iMac speakers/mic TBA
- [ ] PMU, SEP, ANE, encoder, ProRes: all TBA — triage by demand
- [ ] HDMI out WIP (laptops + Studio); SD slot WIP (Studio);
      10GbE WIP (Studio); Studio WiFi/BT WIP
- [ ] M3 Ultra: nearly all TBA — defer until Pro/Max daily-drivable
- [ ] M3 release incoming (Asahi "coming weeks" Aug 2026) — review
      release notes, cherry-pick eligible fixes

## M4 (T8132/T604x) — installer no, 0%

- [ ] Reproduce lab results: NVMe + PCIe enumeration + multicore boot
- [ ] Devicetree for T8132/T604x (all TBA)
- [ ] No installer until display + input land — sequence: UART,
      cpufreq, I2C/GPIO, USB-PD, DCP, then rest
- [ ] M4 NVMe firmware breakage (macOS 15.x builds) + WFI issue —
      mitigations exist upstream, verify here

## Studio Display (studio-display branch — in flight)

- [x] Case-duplicate lowercase netfilter/litmus files removed
- [x] Stash WIP committed (0f5313e9b): DTS altmode, tipd DRM oob
      hotplug, CD321x data_status, ATC PHY, DCP/DPTX parser + iomfb,
      new `include/linux/apple_dcp_dptx.h`
- [ ] Boot-test on 96775a0 baseline before further changes (stash guard)
- [ ] Verify DP-altmode link training per SoC: t8103, t8112, t60xx, t6020
- [ ] Multi-port: extend beyond fairydust single blessed port
- [ ] Brightness: userspace solved (`asdbctl`, `apple_bl_usb`) —
      wire into Omarchy stack, no kernel work needed
- [ ] Camera / Center Stage / speakers / firmware: macOS-only, no
      community effort — long-term research, expect closed firmware
- [ ] Cherry-pick `rgvxsthi` HDMI-suspend fix (2-line `dcp.c`
      resume) — adjacent code, same driver

## Omarchy integration (downstream of kernel)

- [ ] Test studio-display kernel under Omarchy Mac (M1/M2 first)
- [ ] External-monitor discussion #73: feed results back
- [ ] Touch Bar: mainline 6.15 + `tiny-dfr`/`macarchy-dfr` — package,
      no kernel work
- [ ] ALS auto-brightness daemons exist (`asahi-brightnessd`,
      `asahi-brightness`) — evaluate, adopt one

## Fork hygiene

- [x] `upstream` remote removed
- [ ] Cherry-pick log: record every Asahi commit taken (hash + reason)
- [ ] Watch: Asahi M3 release, USB4 series v2, PSCI RFC, 120Hz DCP work
