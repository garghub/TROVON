static int rfkill_gpio_set_power(void *data, bool blocked)
{
struct rfkill_gpio_data *rfkill = data;
if (blocked) {
if (gpio_is_valid(rfkill->shutdown_gpio))
gpio_set_value(rfkill->shutdown_gpio, 0);
if (gpio_is_valid(rfkill->reset_gpio))
gpio_set_value(rfkill->reset_gpio, 0);
if (!IS_ERR(rfkill->clk) && rfkill->clk_enabled)
clk_disable(rfkill->clk);
} else {
if (!IS_ERR(rfkill->clk) && !rfkill->clk_enabled)
clk_enable(rfkill->clk);
if (gpio_is_valid(rfkill->reset_gpio))
gpio_set_value(rfkill->reset_gpio, 1);
if (gpio_is_valid(rfkill->shutdown_gpio))
gpio_set_value(rfkill->shutdown_gpio, 1);
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
rfkill->reset_gpio = acpi_get_gpio_by_index(dev, 0, NULL);
rfkill->shutdown_gpio = acpi_get_gpio_by_index(dev, 1, NULL);
return 0;
}
static int rfkill_gpio_probe(struct platform_device *pdev)
{
struct rfkill_gpio_platform_data *pdata = pdev->dev.platform_data;
struct rfkill_gpio_data *rfkill;
const char *clk_name = NULL;
int ret = 0;
int len = 0;
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
rfkill->reset_gpio = pdata->reset_gpio;
rfkill->shutdown_gpio = pdata->shutdown_gpio;
} else {
return -ENODEV;
}
if ((!gpio_is_valid(rfkill->reset_gpio) &&
!gpio_is_valid(rfkill->shutdown_gpio)) || !rfkill->name) {
pr_warn("%s: invalid platform data\n", __func__);
return -EINVAL;
}
if (pdata && pdata->gpio_runtime_setup) {
ret = pdata->gpio_runtime_setup(pdev);
if (ret) {
pr_warn("%s: can't set up gpio\n", __func__);
return ret;
}
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
if (gpio_is_valid(rfkill->reset_gpio)) {
ret = devm_gpio_request_one(&pdev->dev, rfkill->reset_gpio,
0, rfkill->reset_name);
if (ret) {
pr_warn("%s: failed to get reset gpio.\n", __func__);
return ret;
}
}
if (gpio_is_valid(rfkill->shutdown_gpio)) {
ret = devm_gpio_request_one(&pdev->dev, rfkill->shutdown_gpio,
0, rfkill->shutdown_name);
if (ret) {
pr_warn("%s: failed to get shutdown gpio.\n", __func__);
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
