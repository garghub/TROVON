static int rfkill_gpio_set_power(void *data, bool blocked)
{
struct rfkill_gpio_data *rfkill = data;
if (blocked) {
if (gpio_is_valid(rfkill->pdata->shutdown_gpio))
gpio_direction_output(rfkill->pdata->shutdown_gpio, 0);
if (gpio_is_valid(rfkill->pdata->reset_gpio))
gpio_direction_output(rfkill->pdata->reset_gpio, 0);
if (rfkill->pwr_clk && PWR_CLK_ENABLED(rfkill))
clk_disable(rfkill->pwr_clk);
} else {
if (rfkill->pwr_clk && PWR_CLK_DISABLED(rfkill))
clk_enable(rfkill->pwr_clk);
if (gpio_is_valid(rfkill->pdata->reset_gpio))
gpio_direction_output(rfkill->pdata->reset_gpio, 1);
if (gpio_is_valid(rfkill->pdata->shutdown_gpio))
gpio_direction_output(rfkill->pdata->shutdown_gpio, 1);
}
if (rfkill->pwr_clk)
PWR_CLK_SET(rfkill, blocked);
return 0;
}
static int rfkill_gpio_probe(struct platform_device *pdev)
{
struct rfkill_gpio_data *rfkill;
struct rfkill_gpio_platform_data *pdata = pdev->dev.platform_data;
int ret = 0;
int len = 0;
if (!pdata) {
pr_warn("%s: No platform data specified\n", __func__);
return -EINVAL;
}
if (!pdata->name || (!gpio_is_valid(pdata->reset_gpio) &&
!gpio_is_valid(pdata->shutdown_gpio))) {
pr_warn("%s: invalid platform data\n", __func__);
return -EINVAL;
}
rfkill = kzalloc(sizeof(*rfkill), GFP_KERNEL);
if (!rfkill)
return -ENOMEM;
if (pdata->gpio_runtime_setup) {
ret = pdata->gpio_runtime_setup(pdev);
if (ret) {
pr_warn("%s: can't set up gpio\n", __func__);
goto fail_alloc;
}
}
rfkill->pdata = pdata;
len = strlen(pdata->name);
rfkill->reset_name = kzalloc(len + 7, GFP_KERNEL);
if (!rfkill->reset_name) {
ret = -ENOMEM;
goto fail_alloc;
}
rfkill->shutdown_name = kzalloc(len + 10, GFP_KERNEL);
if (!rfkill->shutdown_name) {
ret = -ENOMEM;
goto fail_reset_name;
}
snprintf(rfkill->reset_name, len + 6 , "%s_reset", pdata->name);
snprintf(rfkill->shutdown_name, len + 9, "%s_shutdown", pdata->name);
if (pdata->power_clk_name) {
rfkill->pwr_clk = clk_get(&pdev->dev, pdata->power_clk_name);
if (IS_ERR(rfkill->pwr_clk)) {
pr_warn("%s: can't find pwr_clk.\n", __func__);
goto fail_shutdown_name;
}
}
if (gpio_is_valid(pdata->reset_gpio)) {
ret = gpio_request(pdata->reset_gpio, rfkill->reset_name);
if (ret) {
pr_warn("%s: failed to get reset gpio.\n", __func__);
goto fail_clock;
}
}
if (gpio_is_valid(pdata->shutdown_gpio)) {
ret = gpio_request(pdata->shutdown_gpio, rfkill->shutdown_name);
if (ret) {
pr_warn("%s: failed to get shutdown gpio.\n", __func__);
goto fail_reset;
}
}
rfkill->rfkill_dev = rfkill_alloc(pdata->name, &pdev->dev, pdata->type,
&rfkill_gpio_ops, rfkill);
if (!rfkill->rfkill_dev)
goto fail_shutdown;
ret = rfkill_register(rfkill->rfkill_dev);
if (ret < 0)
goto fail_rfkill;
platform_set_drvdata(pdev, rfkill);
dev_info(&pdev->dev, "%s device registered.\n", pdata->name);
return 0;
fail_rfkill:
rfkill_destroy(rfkill->rfkill_dev);
fail_shutdown:
if (gpio_is_valid(pdata->shutdown_gpio))
gpio_free(pdata->shutdown_gpio);
fail_reset:
if (gpio_is_valid(pdata->reset_gpio))
gpio_free(pdata->reset_gpio);
fail_clock:
if (rfkill->pwr_clk)
clk_put(rfkill->pwr_clk);
fail_shutdown_name:
kfree(rfkill->shutdown_name);
fail_reset_name:
kfree(rfkill->reset_name);
fail_alloc:
kfree(rfkill);
return ret;
}
static int rfkill_gpio_remove(struct platform_device *pdev)
{
struct rfkill_gpio_data *rfkill = platform_get_drvdata(pdev);
struct rfkill_gpio_platform_data *pdata = pdev->dev.platform_data;
if (pdata->gpio_runtime_close)
pdata->gpio_runtime_close(pdev);
rfkill_unregister(rfkill->rfkill_dev);
rfkill_destroy(rfkill->rfkill_dev);
if (gpio_is_valid(rfkill->pdata->shutdown_gpio))
gpio_free(rfkill->pdata->shutdown_gpio);
if (gpio_is_valid(rfkill->pdata->reset_gpio))
gpio_free(rfkill->pdata->reset_gpio);
if (rfkill->pwr_clk && PWR_CLK_ENABLED(rfkill))
clk_disable(rfkill->pwr_clk);
if (rfkill->pwr_clk)
clk_put(rfkill->pwr_clk);
kfree(rfkill->shutdown_name);
kfree(rfkill->reset_name);
kfree(rfkill);
return 0;
}
