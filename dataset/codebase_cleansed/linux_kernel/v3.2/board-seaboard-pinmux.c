static void __init update_pinmux(struct tegra_pingroup_config *newtbl, int size)
{
int i, j;
struct tegra_pingroup_config *new_pingroup, *base_pingroup;
for (i = 0; i < size; i++) {
new_pingroup = &newtbl[i];
for (j = 0; j < ARRAY_SIZE(seaboard_pinmux); j++) {
base_pingroup = &seaboard_pinmux[j];
if (new_pingroup->pingroup == base_pingroup->pingroup) {
*base_pingroup = *new_pingroup;
break;
}
}
}
}
void __init seaboard_common_pinmux_init(void)
{
if (!of_machine_is_compatible("nvidia,tegra20"))
platform_add_devices(pinmux_devices,
ARRAY_SIZE(pinmux_devices));
tegra_pinmux_config_table(seaboard_pinmux, ARRAY_SIZE(seaboard_pinmux));
tegra_drive_pinmux_config_table(seaboard_drive_pinmux,
ARRAY_SIZE(seaboard_drive_pinmux));
tegra_gpio_config(common_gpio_table, ARRAY_SIZE(common_gpio_table));
}
void __init seaboard_pinmux_init(void)
{
seaboard_common_pinmux_init();
}
void __init ventana_pinmux_init(void)
{
update_pinmux(ventana_pinmux, ARRAY_SIZE(ventana_pinmux));
seaboard_common_pinmux_init();
}
