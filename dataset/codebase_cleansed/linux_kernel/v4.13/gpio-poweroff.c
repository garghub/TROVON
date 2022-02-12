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
enum gpiod_flags flags;
if (pm_power_off != NULL) {
dev_err(&pdev->dev,
"%s: pm_power_off function already registered",
__func__);
return -EBUSY;
}
input = of_property_read_bool(pdev->dev.of_node, "input");
if (input)
flags = GPIOD_IN;
else
flags = GPIOD_OUT_LOW;
reset_gpio = devm_gpiod_get(&pdev->dev, NULL, flags);
if (IS_ERR(reset_gpio))
return PTR_ERR(reset_gpio);
pm_power_off = &gpio_poweroff_do_poweroff;
return 0;
}
static int gpio_poweroff_remove(struct platform_device *pdev)
{
if (pm_power_off == &gpio_poweroff_do_poweroff)
pm_power_off = NULL;
return 0;
}
