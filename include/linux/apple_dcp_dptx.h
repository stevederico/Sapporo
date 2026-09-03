/* SPDX-License-Identifier: GPL-2.0-only OR MIT */
#ifndef __LINUX_APPLE_DCP_DPTX_H__
#define __LINUX_APPLE_DCP_DPTX_H__

#include <linux/types.h>

struct platform_device;

void dcp_dptx_prefer_atc(struct platform_device *pdev, u32 atc);
bool dcp_dptx_owns_atc(struct platform_device *pdev, u32 atc);

#endif
