static void tegra_board_pinmux_setup_gpios(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(confs); i++) {
if (!confs[i])
continue;
tegra_gpio_config(confs[i]->gpios, confs[i]->gpio_count);
}
}
static void tegra_board_pinmux_setup_pinmux(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(confs); i++) {
if (!confs[i])
continue;
tegra_pinmux_config_table(confs[i]->pgs, confs[i]->pg_count);
if (confs[i]->drives)
tegra_drive_pinmux_config_table(confs[i]->drives,
confs[i]->drive_count);
}
}
static int tegra_board_pinmux_bus_notify(struct notifier_block *nb,
unsigned long event, void *vdev)
{
static bool had_gpio;
static bool had_pinmux;
struct device *dev = vdev;
const char *devname;
if (event != BUS_NOTIFY_BOUND_DRIVER)
return NOTIFY_DONE;
devname = dev_name(dev);
if (!had_gpio && !strcmp(devname, GPIO_DEV)) {
tegra_board_pinmux_setup_gpios();
had_gpio = true;
} else if (!had_pinmux && !strcmp(devname, PINMUX_DEV)) {
tegra_board_pinmux_setup_pinmux();
had_pinmux = true;
}
if (had_gpio && had_pinmux)
return NOTIFY_STOP_MASK;
else
return NOTIFY_DONE;
}
void tegra_board_pinmux_init(struct tegra_board_pinmux_conf *conf_a,
struct tegra_board_pinmux_conf *conf_b)
{
confs[0] = conf_a;
confs[1] = conf_b;
bus_register_notifier(&platform_bus_type, &nb);
if (!of_machine_is_compatible("nvidia,tegra20"))
platform_add_devices(devices, ARRAY_SIZE(devices));
}
