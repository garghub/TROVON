void __init r8a7779_map_io(void)
{
iotable_init(r8a7779_io_desc, ARRAY_SIZE(r8a7779_io_desc));
}
void __init r8a7779_pinmux_init(void)
{
platform_add_devices(r8a7779_pinctrl_devices,
ARRAY_SIZE(r8a7779_pinctrl_devices));
}
void __init r8a7779_add_standard_devices(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x40470000, 0x82000fff);
#endif
r8a7779_pm_init();
r8a7779_init_pm_domains();
platform_add_devices(r8a7779_devices_dt,
ARRAY_SIZE(r8a7779_devices_dt));
platform_add_devices(r8a7779_late_devices,
ARRAY_SIZE(r8a7779_late_devices));
}
void __init r8a7779_add_ether_device(struct sh_eth_plat_data *pdata)
{
platform_device_register_resndata(&platform_bus, "sh_eth", -1,
ether_resources,
ARRAY_SIZE(ether_resources),
pdata, sizeof(*pdata));
}
void __init __weak r8a7779_register_twd(void) { }
void __init r8a7779_earlytimer_init(void)
{
r8a7779_clock_init();
shmobile_earlytimer_init();
r8a7779_register_twd();
}
void __init r8a7779_add_early_devices(void)
{
early_platform_add_devices(r8a7779_devices_dt,
ARRAY_SIZE(r8a7779_devices_dt));
}
void __init r8a7779_init_delay(void)
{
shmobile_setup_delay(1000, 2, 4);
}
void __init r8a7779_add_standard_devices_dt(void)
{
r8a7779_clock_init();
platform_add_devices(r8a7779_devices_dt,
ARRAY_SIZE(r8a7779_devices_dt));
of_platform_populate(NULL, of_default_bus_match_table,
r8a7779_auxdata_lookup, NULL);
}
