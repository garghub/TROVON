void __init sh73a0_map_io(void)
{
debug_ll_io_init();
iotable_init(sh73a0_io_desc, ARRAY_SIZE(sh73a0_io_desc));
}
void __init sh73a0_pinmux_init(void)
{
platform_device_register_simple("pfc-sh73a0", -1, pfc_resources,
ARRAY_SIZE(pfc_resources));
}
void __init sh73a0_add_standard_devices(void)
{
__raw_writel(__raw_readl(SRCR2) & ~(1 << 18), SRCR2);
platform_add_devices(sh73a0_early_devices,
ARRAY_SIZE(sh73a0_early_devices));
platform_add_devices(sh73a0_late_devices,
ARRAY_SIZE(sh73a0_late_devices));
}
void __init __weak sh73a0_register_twd(void) { }
void __init sh73a0_earlytimer_init(void)
{
shmobile_init_delay();
sh73a0_clock_init();
shmobile_earlytimer_init();
sh73a0_register_twd();
}
void __init sh73a0_add_early_devices(void)
{
early_platform_add_devices(sh73a0_early_devices,
ARRAY_SIZE(sh73a0_early_devices));
shmobile_setup_console();
}
void __init sh73a0_add_standard_devices_dt(void)
{
sh73a0_clock_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void sh73a0_restart(enum reboot_mode mode, const char *cmd)
{
writel((1 << 31), RESCNT2);
}
