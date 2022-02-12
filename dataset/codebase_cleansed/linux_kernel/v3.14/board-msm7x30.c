static void __init msm7x30_fixup(struct tag *tag, char **cmdline,
struct meminfo *mi)
{
for (; tag->hdr.size; tag = tag_next(tag))
if (tag->hdr.tag == ATAG_MEM && tag->u.mem.start == 0x200000) {
tag->u.mem.start = 0;
tag->u.mem.size += SZ_2M;
}
}
static void __init msm7x30_reserve(void)
{
memblock_remove(0x0, SZ_2M);
}
static int hsusb_link_clk_reset(struct clk *link_clk, bool assert)
{
int ret;
if (assert) {
ret = clk_reset(link_clk, CLK_RESET_ASSERT);
if (ret)
pr_err("usb hs_clk assert failed\n");
} else {
ret = clk_reset(link_clk, CLK_RESET_DEASSERT);
if (ret)
pr_err("usb hs_clk deassert failed\n");
}
return ret;
}
static int hsusb_phy_clk_reset(struct clk *phy_clk)
{
int ret;
ret = clk_reset(phy_clk, CLK_RESET_ASSERT);
if (ret) {
pr_err("usb phy clk assert failed\n");
return ret;
}
usleep_range(10000, 12000);
ret = clk_reset(phy_clk, CLK_RESET_DEASSERT);
if (ret)
pr_err("usb phy clk deassert failed\n");
return ret;
}
static void __init msm7x30_init_irq(void)
{
msm_init_irq();
}
static void __init msm7x30_init(void)
{
msm_device_otg.dev.platform_data = &msm_otg_pdata;
msm_device_hsusb.dev.parent = &msm_device_otg.dev;
msm_device_hsusb_host.dev.parent = &msm_device_otg.dev;
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init msm7x30_map_io(void)
{
msm_map_msm7x30_io();
}
static void __init msm7x30_init_late(void)
{
smd_debugfs_init();
}
