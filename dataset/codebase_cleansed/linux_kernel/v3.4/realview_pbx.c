static void __init realview_pbx_map_io(void)
{
iotable_init(realview_pbx_io_desc, ARRAY_SIZE(realview_pbx_io_desc));
if (core_tile_pbx11mp() || core_tile_pbxa9mp())
iotable_init(realview_local_io_desc, ARRAY_SIZE(realview_local_io_desc));
}
static void __init gic_init_irq(void)
{
if (core_tile_pbx11mp() || core_tile_pbxa9mp()) {
gic_init(0, 29, __io_address(REALVIEW_PBX_TILE_GIC_DIST_BASE),
__io_address(REALVIEW_PBX_TILE_GIC_CPU_BASE));
} else {
gic_init(0, IRQ_PBX_GIC_START,
__io_address(REALVIEW_PBX_GIC_DIST_BASE),
__io_address(REALVIEW_PBX_GIC_CPU_BASE));
}
}
static void __init realview_pbx_twd_init(void)
{
int err = twd_local_timer_register(&twd_local_timer);
if (err)
pr_err("twd_local_timer_register failed %d\n", err);
}
static void __init realview_pbx_timer_init(void)
{
timer0_va_base = __io_address(REALVIEW_PBX_TIMER0_1_BASE);
timer1_va_base = __io_address(REALVIEW_PBX_TIMER0_1_BASE) + 0x20;
timer2_va_base = __io_address(REALVIEW_PBX_TIMER2_3_BASE);
timer3_va_base = __io_address(REALVIEW_PBX_TIMER2_3_BASE) + 0x20;
realview_timer_init(IRQ_PBX_TIMER0_1);
realview_pbx_twd_init();
}
static void realview_pbx_fixup(struct tag *tags, char **from,
struct meminfo *meminfo)
{
#ifdef CONFIG_SPARSEMEM
meminfo->bank[0].start = 0;
meminfo->bank[0].size = SZ_256M;
meminfo->bank[1].start = 0x20000000;
meminfo->bank[1].size = SZ_512M;
meminfo->bank[2].start = 0x80000000;
meminfo->bank[2].size = SZ_256M;
meminfo->nr_banks = 3;
#else
realview_fixup(tags, from, meminfo);
#endif
}
static void realview_pbx_restart(char mode, const char *cmd)
{
void __iomem *reset_ctrl = __io_address(REALVIEW_SYS_RESETCTL);
void __iomem *lock_ctrl = __io_address(REALVIEW_SYS_LOCK);
__raw_writel(REALVIEW_SYS_LOCK_VAL, lock_ctrl);
__raw_writel(0x00F0, reset_ctrl);
__raw_writel(0x00F4, reset_ctrl);
dsb();
}
static void __init realview_pbx_init(void)
{
int i;
#ifdef CONFIG_CACHE_L2X0
if (core_tile_pbxa9mp()) {
void __iomem *l2x0_base =
__io_address(REALVIEW_PBX_TILE_L220_BASE);
writel(0, l2x0_base + L2X0_TAG_LATENCY_CTRL);
writel(0, l2x0_base + L2X0_DATA_LATENCY_CTRL);
l2x0_init(l2x0_base, 0x02520000, 0xc0000fff);
platform_device_register(&pmu_device);
}
#endif
realview_flash_register(realview_pbx_flash_resources,
ARRAY_SIZE(realview_pbx_flash_resources));
realview_eth_register(NULL, realview_pbx_smsc911x_resources);
platform_device_register(&realview_i2c_device);
platform_device_register(&realview_cf_device);
realview_usb_register(realview_pbx_isp1761_resources);
for (i = 0; i < ARRAY_SIZE(amba_devs); i++) {
struct amba_device *d = amba_devs[i];
amba_device_register(d, &iomem_resource);
}
#ifdef CONFIG_LEDS
leds_event = realview_leds_event;
#endif
}
