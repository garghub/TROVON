static void __init realview_pba8_map_io(void)
{
iotable_init(realview_pba8_io_desc, ARRAY_SIZE(realview_pba8_io_desc));
}
static void __init gic_init_irq(void)
{
gic_init(0, IRQ_PBA8_GIC_START,
__io_address(REALVIEW_PBA8_GIC_DIST_BASE),
__io_address(REALVIEW_PBA8_GIC_CPU_BASE));
}
static void __init realview_pba8_timer_init(void)
{
timer0_va_base = __io_address(REALVIEW_PBA8_TIMER0_1_BASE);
timer1_va_base = __io_address(REALVIEW_PBA8_TIMER0_1_BASE) + 0x20;
timer2_va_base = __io_address(REALVIEW_PBA8_TIMER2_3_BASE);
timer3_va_base = __io_address(REALVIEW_PBA8_TIMER2_3_BASE) + 0x20;
realview_timer_init(IRQ_PBA8_TIMER0_1);
}
static void realview_pba8_restart(char mode, const char *cmd)
{
void __iomem *reset_ctrl = __io_address(REALVIEW_SYS_RESETCTL);
void __iomem *lock_ctrl = __io_address(REALVIEW_SYS_LOCK);
__raw_writel(REALVIEW_SYS_LOCK_VAL, lock_ctrl);
__raw_writel(0x0000, reset_ctrl);
__raw_writel(0x0004, reset_ctrl);
dsb();
}
static void __init realview_pba8_init(void)
{
int i;
realview_flash_register(realview_pba8_flash_resource,
ARRAY_SIZE(realview_pba8_flash_resource));
realview_eth_register(NULL, realview_pba8_smsc911x_resources);
platform_device_register(&realview_i2c_device);
platform_device_register(&realview_cf_device);
realview_usb_register(realview_pba8_isp1761_resources);
platform_device_register(&pmu_device);
for (i = 0; i < ARRAY_SIZE(amba_devs); i++) {
struct amba_device *d = amba_devs[i];
amba_device_register(d, &iomem_resource);
}
#ifdef CONFIG_LEDS
leds_event = realview_leds_event;
#endif
}
