static int acpi_apd_setup(struct apd_private_data *pdata)
{
const struct apd_device_desc *dev_desc = pdata->dev_desc;
struct clk *clk = ERR_PTR(-ENODEV);
if (dev_desc->fixed_clk_rate) {
clk = clk_register_fixed_rate(&pdata->adev->dev,
dev_name(&pdata->adev->dev),
NULL, 0, dev_desc->fixed_clk_rate);
clk_register_clkdev(clk, NULL, dev_name(&pdata->adev->dev));
pdata->clk = clk;
}
return 0;
}
static int acpi_apd_create_device(struct acpi_device *adev,
const struct acpi_device_id *id)
{
const struct apd_device_desc *dev_desc = (void *)id->driver_data;
struct apd_private_data *pdata;
struct platform_device *pdev;
int ret;
if (!dev_desc) {
pdev = acpi_create_platform_device(adev, NULL);
return IS_ERR_OR_NULL(pdev) ? PTR_ERR(pdev) : 1;
}
pdata = kzalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->adev = adev;
pdata->dev_desc = dev_desc;
if (dev_desc->setup) {
ret = dev_desc->setup(pdata);
if (ret)
goto err_out;
}
adev->driver_data = pdata;
pdev = acpi_create_platform_device(adev, dev_desc->properties);
if (!IS_ERR_OR_NULL(pdev))
return 1;
ret = PTR_ERR(pdev);
adev->driver_data = NULL;
err_out:
kfree(pdata);
return ret;
}
void __init acpi_apd_init(void)
{
acpi_scan_add_handler(&apd_handler);
}
