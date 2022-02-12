void __init trimslice_pinmux_init(void)
{
tegra_pinmux_config_table(trimslice_pinmux, ARRAY_SIZE(trimslice_pinmux));
tegra_gpio_config(gpio_table, ARRAY_SIZE(gpio_table));
}
