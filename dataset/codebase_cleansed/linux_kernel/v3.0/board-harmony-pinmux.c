void harmony_pinmux_init(void)
{
tegra_pinmux_config_table(harmony_pinmux, ARRAY_SIZE(harmony_pinmux));
tegra_gpio_config(gpio_table, ARRAY_SIZE(gpio_table));
}
