static int rfkill_gpio_set_power(void *data, bool blocked)
{
struct rfkill_gpio_data *rfkill = data;
if (blocked) {
gpiod_set_value(rfkill->shutdown_gpio, 0);
gpiod_set_value(rfkill->reset_gpio, 0);
if (!IS_ERR(rfkill->clk) && rfkill->clk_enabled)
clk_disable(rfkill->clk);
} else {
if (!IS_ERR(rfkill->clk) && !rfkill->clk_enabled)
clk_enable(rfkill->clk);
gpiod_set_value(rfkill->reset_gpio, 1);
gpiod_set_value(rfkill->shutdown_gpio, 1);
}
rfkill->clk_enabled = blocked;
return 0;
}
static int rfkill_gpio_acpi_probe(struct device *dev,
struct rfkill_gpio_data *rfkill)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return -ENODEV;
rfkill->name = dev_name(dev);
rfkill->type = (unsigned)id->driver_data;
return 0;
}
static int rfkill_gpio_probe(struct platform_device *pdev)
{
struct rfkill_gpio_platform_data *pdata = pdev->dev.platform_data;
struct rfkill_gpio_data *rfkill;
const char *clk_name = NULL;
struct gpio_desc *gpio;
int ret;
int len;
rfkill = devm_kzalloc(&pdev->dev, sizeof(*rfkill), GFP_KERNEL);
if (!rfkill)
return -ENOMEM;
if (ACPI_HANDLE(&pdev->dev)) {
ret = rfkill_gpio_acpi_probe(&pdev->dev, rfkill);
if (ret)
return ret;
} else if (pdata) {
clk_name = pdata->power_clk_name;
rfkill->name = pdata->name;
rfkill->type = pdata->type;
} else {
return -ENODEV;
}
len = strlen(rfkill->name);
rfkill->reset_name = devm_kzalloc(&pdev->dev, len + 7, GFP_KERNEL);
if (!rfkill->reset_name)
return -ENOMEM;
rfkill->shutdown_name = devm_kzalloc(&pdev->dev, len + 10, GFP_KERNEL);
if (!rfkill->shutdown_name)
return -ENOMEM;
snprintf(rfkill->reset_name, len + 6 , "%s_reset", rfkill->name);
snprintf(rfkill->shutdown_name, len + 9, "%s_shutdown", rfkill->name);
rfkill->clk = devm_clk_get(&pdev->dev, clk_name);
gpio = devm_gpiod_get_index(&pdev->dev, rfkill->reset_name, 0);
if (!IS_ERR(gpio)) {
ret = gpiod_direction_output(gpio, 0);
if (ret)
return ret;
rfkill->reset_gpio = gpio;
}
gpio = devm_gpiod_get_index(&pdev->dev, rfkill->shutdown_name, 1);
if (!IS_ERR(gpio)) {
ret = gpiod_direction_output(gpio, 0);
if (ret)
return ret;
rfkill->shutdown_gpio = gpio;
}
if ((!rfkill->reset_gpio && !rfkill->shutdown_gpio) || !rfkill->name) {
dev_err(&pdev->dev, "invalid platform data\n");
return -EINVAL;
}
if (pdata && pdata->gpio_runtime_setup) {
ret = pdata->gpio_runtime_setup(pdev);
if (ret) {
dev_err(&pdev->dev, "can't set up gpio\n");
return ret;
}
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
struct rfkill_gpio_platform_data *pdata = pdev->dev.platform_data;
if (pdata && pdata->gpio_runtime_close)
pdata->gpio_runtime_close(pdev);
rfkill_unregister(rfkill->rfkill_dev);
rfkill_destroy(rfkill->rfkill_dev);
return 0;
}
