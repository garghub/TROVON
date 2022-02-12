void __init r8a7779_map_io(void)
{
iotable_init(r8a7779_io_desc, ARRAY_SIZE(r8a7779_io_desc));
}
void __init r8a7779_add_standard_devices(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_init((void __iomem __force *)(0xf0100000), 0x40470000, 0x82000fff);
#endif
r8a7779_pm_init();
r8a7779_init_pm_domain(&r8a7779_sh4a);
r8a7779_init_pm_domain(&r8a7779_sgx);
r8a7779_init_pm_domain(&r8a7779_vdp1);
r8a7779_init_pm_domain(&r8a7779_impx3);
platform_add_devices(r8a7779_early_devices,
ARRAY_SIZE(r8a7779_early_devices));
platform_add_devices(r8a7779_late_devices,
ARRAY_SIZE(r8a7779_late_devices));
}
void __init __weak r8a7779_register_twd(void) { }
static void __init r8a7779_earlytimer_init(void)
{
r8a7779_clock_init();
shmobile_earlytimer_init();
r8a7779_register_twd();
}
void __init r8a7779_add_early_devices(void)
{
early_platform_add_devices(r8a7779_early_devices,
ARRAY_SIZE(r8a7779_early_devices));
shmobile_timer.init = r8a7779_earlytimer_init;
}
