void paz00_pinmux_init(void)
{
tegra_pinmux_config_table(paz00_pinmux, ARRAY_SIZE(paz00_pinmux));
tegra_gpio_config(gpio_table, ARRAY_SIZE(gpio_table));
}
