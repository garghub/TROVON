static int rfkill_gpio_set_power(void *data, bool blocked)
{
struct rfkill_gpio_data *rfkill = data;
if (!blocked && !IS_ERR(rfkill->clk) && !rfkill->clk_enabled)
clk_enable(rfkill->clk);
gpiod_set_value_cansleep(rfkill->shutdown_gpio, !blocked);
gpiod_set_value_cansleep(rfkill->reset_gpio, !blocked);
if (blocked && !IS_ERR(rfkill->clk) && rfkill->clk_enabled)
clk_disable(rfkill->clk);
rfkill->clk_enabled = !blocked;
return 0;
}
static int rfkill_gpio_acpi_probe(struct device *dev,
struct rfkill_gpio_data *rfkill)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return -ENODEV;
rfkill->type = (unsigned)id->driver_data;
return acpi_dev_add_driver_gpios(ACPI_COMPANION(dev),
acpi_rfkill_default_gpios);
}
static int rfkill_gpio_probe(struct platform_device *pdev)
{
struct rfkill_gpio_data *rfkill;
struct gpio_desc *gpio;
const char *type_name;
int ret;
rfkill = devm_kzalloc(&pdev->dev, sizeof(*rfkill), GFP_KERNEL);
if (!rfkill)
return -ENOMEM;
device_property_read_string(&pdev->dev, "name", &rfkill->name);
device_property_read_string(&pdev->dev, "type", &type_name);
if (!rfkill->name)
rfkill->name = dev_name(&pdev->dev);
rfkill->type = rfkill_find_type(type_name);
if (ACPI_HANDLE(&pdev->dev)) {
ret = rfkill_gpio_acpi_probe(&pdev->dev, rfkill);
if (ret)
return ret;
}
rfkill->clk = devm_clk_get(&pdev->dev, NULL);
gpio = devm_gpiod_get_optional(&pdev->dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(gpio))
return PTR_ERR(gpio);
rfkill->reset_gpio = gpio;
gpio = devm_gpiod_get_optional(&pdev->dev, "shutdown", GPIOD_OUT_LOW);
if (IS_ERR(gpio))
return PTR_ERR(gpio);
rfkill->shutdown_gpio = gpio;
if (!rfkill->reset_gpio && !rfkill->shutdown_gpio) {
dev_err(&pdev->dev, "invalid platform data\n");
return -EINVAL;
}
rfkill->rfkill_dev = rfkill_alloc(rfkill->name, &pdev->dev,
rfkill->type, &rfkill_gpio_ops,
rfkill);
if (!rfkill->rfkill_dev)
return -ENOMEM;
ret = rfkill_register(rfkill->rfkill_dev);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, rfkill);
dev_info(&pdev->dev, "%s device registered.\n", rfkill->name);
return 0;
}
static int rfkill_gpio_remove(struct platform_device *pdev)
{
struct rfkill_gpio_data *rfkill = platform_get_drvdata(pdev);
rfkill_unregister(rfkill->rfkill_dev);
rfkill_destroy(rfkill->rfkill_dev);
acpi_dev_remove_driver_gpios(ACPI_COMPANION(&pdev->dev));
return 0;
}
