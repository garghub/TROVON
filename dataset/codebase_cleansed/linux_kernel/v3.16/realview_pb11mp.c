static void __init realview_pb11mp_map_io(void)
{
iotable_init(realview_pb11mp_io_desc, ARRAY_SIZE(realview_pb11mp_io_desc));
}
static void __init gic_init_irq(void)
{
unsigned int pldctrl;
writel(0x0000a05f, __io_address(REALVIEW_SYS_LOCK));
pldctrl = readl(__io_address(REALVIEW_SYS_BASE) + REALVIEW_PB11MP_SYS_PLD_CTRL1);
pldctrl |= 2 << 22;
writel(pldctrl, __io_address(REALVIEW_SYS_BASE) + REALVIEW_PB11MP_SYS_PLD_CTRL1);
writel(0x00000000, __io_address(REALVIEW_SYS_LOCK));
gic_init(0, 29, __io_address(REALVIEW_TC11MP_GIC_DIST_BASE),
__io_address(REALVIEW_TC11MP_GIC_CPU_BASE));
gic_init(1, IRQ_PB11MP_GIC_START,
__io_address(REALVIEW_PB11MP_GIC_DIST_BASE),
__io_address(REALVIEW_PB11MP_GIC_CPU_BASE));
gic_cascade_irq(1, IRQ_TC11MP_PB_IRQ1);
}
static void __init realview_pb11mp_twd_init(void)
{
int err = twd_local_timer_register(&twd_local_timer);
if (err)
pr_err("twd_local_timer_register failed %d\n", err);
}
static void __init realview_pb11mp_timer_init(void)
{
timer0_va_base = __io_address(REALVIEW_PB11MP_TIMER0_1_BASE);
timer1_va_base = __io_address(REALVIEW_PB11MP_TIMER0_1_BASE) + 0x20;
timer2_va_base = __io_address(REALVIEW_PB11MP_TIMER2_3_BASE);
timer3_va_base = __io_address(REALVIEW_PB11MP_TIMER2_3_BASE) + 0x20;
realview_clk_init(__io_address(REALVIEW_SYS_BASE), false);
realview_timer_init(IRQ_TC11MP_TIMER0_1);
realview_pb11mp_twd_init();
}
static void realview_pb11mp_restart(enum reboot_mode mode, const char *cmd)
{
void __iomem *reset_ctrl = __io_address(REALVIEW_SYS_RESETCTL);
void __iomem *lock_ctrl = __io_address(REALVIEW_SYS_LOCK);
__raw_writel(REALVIEW_SYS_LOCK_VAL, lock_ctrl);
__raw_writel(0x0000, reset_ctrl);
__raw_writel(0x0004, reset_ctrl);
dsb();
}
static void __init realview_pb11mp_init(void)
{
int i;
#ifdef CONFIG_CACHE_L2X0
l2x0_init(__io_address(REALVIEW_TC11MP_L220_BASE), 0x00790000, 0xfe000fff);
#endif
realview_flash_register(realview_pb11mp_flash_resource,
ARRAY_SIZE(realview_pb11mp_flash_resource));
realview_eth_register(NULL, realview_pb11mp_smsc911x_resources);
platform_device_register(&realview_i2c_device);
platform_device_register(&realview_cf_device);
platform_device_register(&realview_leds_device);
realview_usb_register(realview_pb11mp_isp1761_resources);
platform_device_register(&pmu_device);
for (i = 0; i < ARRAY_SIZE(amba_devs); i++) {
struct amba_device *d = amba_devs[i];
amba_device_register(d, &iomem_resource);
}
}
