static void __init dnskw_gpio_register(unsigned gpio, char *name, int def)
{
if (gpio_request(gpio, name) == 0 &&
gpio_direction_output(gpio, 0) == 0) {
gpio_set_value(gpio, def);
if (gpio_export(gpio, 0) != 0)
pr_err("dnskw: Failed to export GPIO %s\n", name);
} else
pr_err("dnskw: Failed to register %s\n", name);
}
void __init dnskw_init(void)
{
kirkwood_ge00_init(&dnskw_ge00_data);
dnskw_gpio_register(37, "dnskw:power:recover", 1);
}
