static void __init bockw_init(void)
{
r8a7778_clock_init();
pinctrl_register_mappings(bockw_pinctrl_map,
ARRAY_SIZE(bockw_pinctrl_map));
r8a7778_pinmux_init();
r8a7778_add_dt_devices();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
