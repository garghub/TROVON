static u32 i2c_dw_get_clk_rate_khz(struct dw_i2c_dev *dev)
{
return clk_get_rate(dev->clk)/1000;
}
static void dw_i2c_acpi_params(struct platform_device *pdev, char method[],
u16 *hcnt, u16 *lcnt, u32 *sda_hold)
{
struct acpi_buffer buf = { ACPI_ALLOCATE_BUFFER };
acpi_handle handle = ACPI_HANDLE(&pdev->dev);
union acpi_object *obj;
if (dmi_check_system(dw_i2c_no_acpi_params))
return;
if (ACPI_FAILURE(acpi_evaluate_object(handle, method, NULL, &buf)))
return;
obj = (union acpi_object *)buf.pointer;
if (obj->type == ACPI_TYPE_PACKAGE && obj->package.count == 3) {
const union acpi_object *objs = obj->package.elements;
*hcnt = (u16)objs[0].integer.value;
*lcnt = (u16)objs[1].integer.value;
if (sda_hold)
*sda_hold = (u32)objs[2].integer.value;
}
kfree(buf.pointer);
}
static int dw_i2c_acpi_configure(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
const struct acpi_device_id *id;
dev->adapter.nr = -1;
dev->tx_fifo_depth = 32;
dev->rx_fifo_depth = 32;
dw_i2c_acpi_params(pdev, "SSCN", &dev->ss_hcnt, &dev->ss_lcnt, NULL);
dw_i2c_acpi_params(pdev, "FMCN", &dev->fs_hcnt, &dev->fs_lcnt,
&dev->sda_hold_time);
dw_i2c_acpi_params(pdev, "FPCN", &dev->fp_hcnt, &dev->fp_lcnt, NULL);
dw_i2c_acpi_params(pdev, "HSCN", &dev->hs_hcnt, &dev->hs_lcnt, NULL);
id = acpi_match_device(pdev->dev.driver->acpi_match_table, &pdev->dev);
if (id && id->driver_data)
dev->accessor_flags |= (u32)id->driver_data;
return 0;
}
static inline int dw_i2c_acpi_configure(struct platform_device *pdev)
{
return -ENODEV;
}
static int i2c_dw_plat_prepare_clk(struct dw_i2c_dev *i_dev, bool prepare)
{
if (IS_ERR(i_dev->clk))
return PTR_ERR(i_dev->clk);
if (prepare)
return clk_prepare_enable(i_dev->clk);
clk_disable_unprepare(i_dev->clk);
return 0;
}
static int dw_i2c_plat_probe(struct platform_device *pdev)
{
struct dw_i2c_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct dw_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem;
int irq, r;
u32 acpi_speed, ht = 0;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
dev = devm_kzalloc(&pdev->dev, sizeof(struct dw_i2c_dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dev->base))
return PTR_ERR(dev->base);
dev->dev = &pdev->dev;
dev->irq = irq;
platform_set_drvdata(pdev, dev);
dev->clk_freq = 400000;
if (pdata) {
dev->clk_freq = pdata->i2c_scl_freq;
} else {
device_property_read_u32(&pdev->dev, "i2c-sda-hold-time-ns",
&ht);
device_property_read_u32(&pdev->dev, "i2c-sda-falling-time-ns",
&dev->sda_falling_time);
device_property_read_u32(&pdev->dev, "i2c-scl-falling-time-ns",
&dev->scl_falling_time);
device_property_read_u32(&pdev->dev, "clock-frequency",
&dev->clk_freq);
}
acpi_speed = i2c_acpi_find_bus_speed(&pdev->dev);
if (acpi_speed)
dev->clk_freq = acpi_speed;
if (has_acpi_companion(&pdev->dev))
dw_i2c_acpi_configure(pdev);
if (dev->clk_freq != 100000 && dev->clk_freq != 400000
&& dev->clk_freq != 1000000 && dev->clk_freq != 3400000) {
dev_err(&pdev->dev,
"Only 100kHz, 400kHz, 1MHz and 3.4MHz supported");
return -EINVAL;
}
r = i2c_dw_eval_lock_support(dev);
if (r)
return r;
dev->functionality =
I2C_FUNC_I2C |
I2C_FUNC_10BIT_ADDR |
I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK;
dev->master_cfg = DW_IC_CON_MASTER | DW_IC_CON_SLAVE_DISABLE |
DW_IC_CON_RESTART_EN;
switch (dev->clk_freq) {
case 100000:
dev->master_cfg |= DW_IC_CON_SPEED_STD;
break;
case 3400000:
dev->master_cfg |= DW_IC_CON_SPEED_HIGH;
break;
default:
dev->master_cfg |= DW_IC_CON_SPEED_FAST;
}
dev->clk = devm_clk_get(&pdev->dev, NULL);
if (!i2c_dw_plat_prepare_clk(dev, true)) {
dev->get_clk_rate_khz = i2c_dw_get_clk_rate_khz;
if (!dev->sda_hold_time && ht)
dev->sda_hold_time = div_u64(
(u64)dev->get_clk_rate_khz(dev) * ht + 500000,
1000000);
}
if (!dev->tx_fifo_depth) {
u32 param1 = i2c_dw_read_comp_param(dev);
dev->tx_fifo_depth = ((param1 >> 16) & 0xff) + 1;
dev->rx_fifo_depth = ((param1 >> 8) & 0xff) + 1;
dev->adapter.nr = pdev->id;
}
adap = &dev->adapter;
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DEPRECATED;
ACPI_COMPANION_SET(&adap->dev, ACPI_COMPANION(&pdev->dev));
adap->dev.of_node = pdev->dev.of_node;
if (dev->pm_runtime_disabled) {
pm_runtime_forbid(&pdev->dev);
} else {
pm_runtime_set_autosuspend_delay(&pdev->dev, 1000);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
}
r = i2c_dw_probe(dev);
if (r && !dev->pm_runtime_disabled)
pm_runtime_disable(&pdev->dev);
return r;
}
static int dw_i2c_plat_remove(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
pm_runtime_get_sync(&pdev->dev);
i2c_del_adapter(&dev->adapter);
i2c_dw_disable(dev);
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
if (!dev->pm_runtime_disabled)
pm_runtime_disable(&pdev->dev);
return 0;
}
static int dw_i2c_plat_prepare(struct device *dev)
{
return pm_runtime_suspended(dev);
}
static void dw_i2c_plat_complete(struct device *dev)
{
if (dev->power.direct_complete)
pm_request_resume(dev);
}
static int dw_i2c_plat_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_i2c_dev *i_dev = platform_get_drvdata(pdev);
i2c_dw_disable(i_dev);
i2c_dw_plat_prepare_clk(i_dev, false);
return 0;
}
static int dw_i2c_plat_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_i2c_dev *i_dev = platform_get_drvdata(pdev);
i2c_dw_plat_prepare_clk(i_dev, true);
if (!i_dev->pm_runtime_disabled)
i2c_dw_init(i_dev);
return 0;
}
static int __init dw_i2c_init_driver(void)
{
return platform_driver_register(&dw_i2c_driver);
}
static void __exit dw_i2c_exit_driver(void)
{
platform_driver_unregister(&dw_i2c_driver);
}
