static void gpio_poweroff_do_poweroff(void)
{
BUG_ON(!reset_gpio);
gpiod_direction_output(reset_gpio, 1);
mdelay(100);
gpiod_set_value(reset_gpio, 0);
mdelay(100);
gpiod_set_value(reset_gpio, 1);
mdelay(3000);
WARN_ON(1);
}
static int gpio_poweroff_probe(struct platform_device *pdev)
{
bool input = false;
if (pm_power_off != NULL) {
dev_err(&pdev->dev,
"%s: pm_power_off function already registered",
__func__);
return -EBUSY;
}
reset_gpio = devm_gpiod_get(&pdev->dev, NULL);
if (IS_ERR(reset_gpio))
return PTR_ERR(reset_gpio);
input = of_property_read_bool(pdev->dev.of_node, "input");
if (input) {
if (gpiod_direction_input(reset_gpio)) {
dev_err(&pdev->dev,
"Could not set direction of reset GPIO to input\n");
return -ENODEV;
}
} else {
if (gpiod_direction_output(reset_gpio, 0)) {
dev_err(&pdev->dev,
"Could not set direction of reset GPIO\n");
return -ENODEV;
}
}
pm_power_off = &gpio_poweroff_do_poweroff;
return 0;
}
static int gpio_poweroff_remove(struct platform_device *pdev)
{
if (pm_power_off == &gpio_poweroff_do_poweroff)
pm_power_off = NULL;
return 0;
}
