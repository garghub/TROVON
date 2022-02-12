static void gpio_poweroff_do_poweroff(void)
{
BUG_ON(!gpio_is_valid(gpio_num));
gpio_direction_output(gpio_num, !gpio_active_low);
mdelay(100);
gpio_set_value(gpio_num, gpio_active_low);
mdelay(100);
gpio_set_value(gpio_num, !gpio_active_low);
mdelay(3000);
WARN_ON(1);
}
static int gpio_poweroff_probe(struct platform_device *pdev)
{
enum of_gpio_flags flags;
bool input = false;
int ret;
if (pm_power_off != NULL) {
pr_err("%s: pm_power_off function already registered",
__func__);
return -EBUSY;
}
gpio_num = of_get_gpio_flags(pdev->dev.of_node, 0, &flags);
if (!gpio_is_valid(gpio_num))
return gpio_num;
gpio_active_low = flags & OF_GPIO_ACTIVE_LOW;
input = of_property_read_bool(pdev->dev.of_node, "input");
ret = gpio_request(gpio_num, "poweroff-gpio");
if (ret) {
pr_err("%s: Could not get GPIO %d", __func__, gpio_num);
return ret;
}
if (input) {
if (gpio_direction_input(gpio_num)) {
pr_err("Could not set direction of GPIO %d to input",
gpio_num);
goto err;
}
} else {
if (gpio_direction_output(gpio_num, gpio_active_low)) {
pr_err("Could not set direction of GPIO %d", gpio_num);
goto err;
}
}
pm_power_off = &gpio_poweroff_do_poweroff;
return 0;
err:
gpio_free(gpio_num);
return -ENODEV;
}
static int gpio_poweroff_remove(struct platform_device *pdev)
{
gpio_free(gpio_num);
if (pm_power_off == &gpio_poweroff_do_poweroff)
pm_power_off = NULL;
return 0;
}
