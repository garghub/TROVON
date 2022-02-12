void __init sh73a0_map_io(void)
{
iotable_init(sh73a0_io_desc, ARRAY_SIZE(sh73a0_io_desc));
}
void __init sh73a0_pinmux_init(void)
{
platform_device_register(&sh73a0_pfc_device);
}
void __init sh73a0_add_standard_devices(void)
{
__raw_writel(__raw_readl(SRCR2) & ~(1 << 18), SRCR2);
platform_add_devices(sh73a0_early_devices_dt,
ARRAY_SIZE(sh73a0_early_devices_dt));
platform_add_devices(sh73a0_early_devices,
ARRAY_SIZE(sh73a0_early_devices));
platform_add_devices(sh73a0_late_devices,
ARRAY_SIZE(sh73a0_late_devices));
}
void __init __weak sh73a0_register_twd(void) { }
void __init sh73a0_earlytimer_init(void)
{
sh73a0_clock_init();
shmobile_earlytimer_init();
sh73a0_register_twd();
}
void __init sh73a0_add_early_devices(void)
{
early_platform_add_devices(sh73a0_early_devices_dt,
ARRAY_SIZE(sh73a0_early_devices_dt));
early_platform_add_devices(sh73a0_early_devices,
ARRAY_SIZE(sh73a0_early_devices));
shmobile_setup_console();
}
void __init sh73a0_add_early_devices_dt(void)
{
shmobile_setup_delay(1196, 44, 46);
early_platform_add_devices(sh73a0_early_devices_dt,
ARRAY_SIZE(sh73a0_early_devices_dt));
shmobile_setup_console();
}
void __init sh73a0_add_standard_devices_dt(void)
{
sh73a0_clock_init();
platform_add_devices(sh73a0_early_devices_dt,
ARRAY_SIZE(sh73a0_early_devices_dt));
of_platform_populate(NULL, of_default_bus_match_table,
sh73a0_auxdata_lookup, NULL);
}
