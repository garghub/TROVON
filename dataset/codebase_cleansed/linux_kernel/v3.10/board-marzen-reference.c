static void __init marzen_init(void)
{
pinctrl_register_mappings(marzen_pinctrl_map,
ARRAY_SIZE(marzen_pinctrl_map));
r8a7779_pinmux_init();
r8a7779_add_standard_devices_dt();
}
