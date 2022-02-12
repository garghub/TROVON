void __init seaboard_pinmux_init(void)
{
tegra_pinmux_config_table(seaboard_pinmux, ARRAY_SIZE(seaboard_pinmux));
tegra_drive_pinmux_config_table(seaboard_drive_pinmux,
ARRAY_SIZE(seaboard_drive_pinmux));
tegra_gpio_config(gpio_table, ARRAY_SIZE(gpio_table));
}
