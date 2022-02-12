void paz00_pinmux_init(void)
{
if (!of_machine_is_compatible("nvidia,tegra20"))
platform_add_devices(pinmux_devices,
ARRAY_SIZE(pinmux_devices));
tegra_pinmux_config_table(paz00_pinmux, ARRAY_SIZE(paz00_pinmux));
tegra_gpio_config(gpio_table, ARRAY_SIZE(gpio_table));
}
