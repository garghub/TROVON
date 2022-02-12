static int gpio_restart_notify(struct notifier_block *this,
unsigned long mode, void *cmd)
{
struct gpio_restart *gpio_restart =
container_of(this, struct gpio_restart, restart_handler);
gpiod_direction_output(gpio_restart->reset_gpio, 1);
mdelay(gpio_restart->active_delay_ms);
gpiod_set_value(gpio_restart->reset_gpio, 0);
mdelay(gpio_restart->inactive_delay_ms);
gpiod_set_value(gpio_restart->reset_gpio, 1);
mdelay(gpio_restart->wait_delay_ms);
WARN_ON(1);
return NOTIFY_DONE;
}
static int gpio_restart_probe(struct platform_device *pdev)
{
struct gpio_restart *gpio_restart;
bool open_source = false;
u32 property;
int ret;
gpio_restart = devm_kzalloc(&pdev->dev, sizeof(*gpio_restart),
GFP_KERNEL);
if (!gpio_restart)
return -ENOMEM;
open_source = of_property_read_bool(pdev->dev.of_node, "open-source");
gpio_restart->reset_gpio = devm_gpiod_get(&pdev->dev, NULL,
open_source ? GPIOD_IN : GPIOD_OUT_LOW);
if (IS_ERR(gpio_restart->reset_gpio)) {
dev_err(&pdev->dev, "Could net get reset GPIO\n");
return PTR_ERR(gpio_restart->reset_gpio);
}
gpio_restart->restart_handler.notifier_call = gpio_restart_notify;
gpio_restart->restart_handler.priority = 129;
gpio_restart->active_delay_ms = 100;
gpio_restart->inactive_delay_ms = 100;
gpio_restart->wait_delay_ms = 3000;
ret = of_property_read_u32(pdev->dev.of_node, "priority", &property);
if (!ret) {
if (property > 255)
dev_err(&pdev->dev, "Invalid priority property: %u\n",
property);
else
gpio_restart->restart_handler.priority = property;
}
of_property_read_u32(pdev->dev.of_node, "active-delay",
&gpio_restart->active_delay_ms);
of_property_read_u32(pdev->dev.of_node, "inactive-delay",
&gpio_restart->inactive_delay_ms);
of_property_read_u32(pdev->dev.of_node, "wait-delay",
&gpio_restart->wait_delay_ms);
platform_set_drvdata(pdev, gpio_restart);
ret = register_restart_handler(&gpio_restart->restart_handler);
if (ret) {
dev_err(&pdev->dev, "%s: cannot register restart handler, %d\n",
__func__, ret);
return -ENODEV;
}
return 0;
}
static int gpio_restart_remove(struct platform_device *pdev)
{
struct gpio_restart *gpio_restart = platform_get_drvdata(pdev);
int ret;
ret = unregister_restart_handler(&gpio_restart->restart_handler);
if (ret) {
dev_err(&pdev->dev,
"%s: cannot unregister restart handler, %d\n",
__func__, ret);
return -ENODEV;
}
return 0;
}
