static void __init realview_pb1176_map_io(void)
{
iotable_init(realview_pb1176_io_desc, ARRAY_SIZE(realview_pb1176_io_desc));
}
static void __init gic_init_irq(void)
{
gic_init(0, IRQ_DC1176_GIC_START,
__io_address(REALVIEW_DC1176_GIC_DIST_BASE),
__io_address(REALVIEW_DC1176_GIC_CPU_BASE));
gic_init(1, IRQ_PB1176_GIC_START,
__io_address(REALVIEW_PB1176_GIC_DIST_BASE),
__io_address(REALVIEW_PB1176_GIC_CPU_BASE));
gic_cascade_irq(1, IRQ_DC1176_PB_IRQ1);
}
static void __init realview_pb1176_timer_init(void)
{
timer0_va_base = __io_address(REALVIEW_PB1176_TIMER0_1_BASE);
timer1_va_base = __io_address(REALVIEW_PB1176_TIMER0_1_BASE) + 0x20;
timer2_va_base = __io_address(REALVIEW_PB1176_TIMER2_3_BASE);
timer3_va_base = __io_address(REALVIEW_PB1176_TIMER2_3_BASE) + 0x20;
realview_clk_init(__io_address(REALVIEW_SYS_BASE), true);
realview_timer_init(IRQ_DC1176_TIMER0);
}
static void realview_pb1176_restart(char mode, const char *cmd)
{
void __iomem *reset_ctrl = __io_address(REALVIEW_SYS_RESETCTL);
void __iomem *lock_ctrl = __io_address(REALVIEW_SYS_LOCK);
__raw_writel(REALVIEW_SYS_LOCK_VAL, lock_ctrl);
__raw_writel(REALVIEW_PB1176_SYS_SOFT_RESET, reset_ctrl);
dsb();
}
static void realview_pb1176_fixup(struct tag *tags, char **from,
struct meminfo *meminfo)
{
meminfo->bank[0].start = 0;
meminfo->bank[0].size = SZ_128M;
meminfo->nr_banks = 1;
}
static void __init realview_pb1176_init(void)
{
int i;
#ifdef CONFIG_CACHE_L2X0
l2x0_init(__io_address(REALVIEW_PB1176_L220_BASE), 0x00730000, 0xfe000fff);
#endif
realview_flash_register(realview_pb1176_flash_resources,
ARRAY_SIZE(realview_pb1176_flash_resources));
platform_device_register(&pb1176_rom_device);
realview_eth_register(NULL, realview_pb1176_smsc911x_resources);
platform_device_register(&realview_i2c_device);
realview_usb_register(realview_pb1176_isp1761_resources);
platform_device_register(&pmu_device);
platform_device_register(&char_lcd_device);
for (i = 0; i < ARRAY_SIZE(amba_devs); i++) {
struct amba_device *d = amba_devs[i];
amba_device_register(d, &iomem_resource);
}
}
