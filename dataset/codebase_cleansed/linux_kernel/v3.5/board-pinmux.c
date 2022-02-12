void tegra_board_pinmux_init(struct tegra_board_pinmux_conf *conf_a,
struct tegra_board_pinmux_conf *conf_b)
{
if (conf_a)
pinctrl_register_mappings(conf_a->maps, conf_a->map_count);
if (conf_b)
pinctrl_register_mappings(conf_b->maps, conf_b->map_count);
platform_add_devices(devices, ARRAY_SIZE(devices));
}
