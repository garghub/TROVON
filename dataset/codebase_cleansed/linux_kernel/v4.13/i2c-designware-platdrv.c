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
*sda_hold = (u32)objs[2].integer.value;
}
kfree(buf.pointer);
}
static int dw_i2c_acpi_configure(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
u32 ss_ht = 0, fp_ht = 0, hs_ht = 0, fs_ht = 0;
acpi_handle handle = ACPI_HANDLE(&pdev->dev);
const struct acpi_device_id *id;
struct acpi_device *adev;
const char *uid;
dev->adapter.nr = -1;
dev->tx_fifo_depth = 32;
dev->rx_fifo_depth = 32;
dw_i2c_acpi_params(pdev, "SSCN", &dev->ss_hcnt, &dev->ss_lcnt, &ss_ht);
dw_i2c_acpi_params(pdev, "FPCN", &dev->fp_hcnt, &dev->fp_lcnt, &fp_ht);
dw_i2c_acpi_params(pdev, "HSCN", &dev->hs_hcnt, &dev->hs_lcnt, &hs_ht);
dw_i2c_acpi_params(pdev, "FMCN", &dev->fs_hcnt, &dev->fs_lcnt, &fs_ht);
switch (dev->clk_freq) {
case 100000:
dev->sda_hold_time = ss_ht;
break;
case 1000000:
dev->sda_hold_time = fp_ht;
break;
case 3400000:
dev->sda_hold_time = hs_ht;
break;
case 400000:
default:
dev->sda_hold_time = fs_ht;
break;
}
id = acpi_match_device(pdev->dev.driver->acpi_match_table, &pdev->dev);
if (id && id->driver_data)
dev->flags |= (u32)id->driver_data;
if (acpi_bus_get_device(handle, &adev))
return -ENODEV;
uid = adev->pnp.unique_id;
if ((dev->flags & MODEL_CHERRYTRAIL) && !strcmp(uid, "7"))
dev->pm_disabled = true;
return 0;
}
static inline int dw_i2c_acpi_configure(struct platform_device *pdev)
{
return -ENODEV;
}
static void i2c_dw_configure_master(struct dw_i2c_dev *dev)
{
dev->functionality = I2C_FUNC_10BIT_ADDR | DW_IC_DEFAULT_FUNCTIONALITY;
dev->master_cfg = DW_IC_CON_MASTER | DW_IC_CON_SLAVE_DISABLE |
DW_IC_CON_RESTART_EN;
dev->mode = DW_IC_MASTER;
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
}
static void i2c_dw_configure_slave(struct dw_i2c_dev *dev)
{
dev->functionality = I2C_FUNC_SLAVE | DW_IC_DEFAULT_FUNCTIONALITY;
dev->slave_cfg = DW_IC_CON_RX_FIFO_FULL_HLD_CTRL |
DW_IC_CON_RESTART_EN | DW_IC_CON_STOP_DET_IFADDRESSED;
dev->mode = DW_IC_SLAVE;
switch (dev->clk_freq) {
case 100000:
dev->slave_cfg |= DW_IC_CON_SPEED_STD;
break;
case 3400000:
dev->slave_cfg |= DW_IC_CON_SPEED_HIGH;
break;
default:
dev->slave_cfg |= DW_IC_CON_SPEED_FAST;
}
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
static void dw_i2c_set_fifo_size(struct dw_i2c_dev *dev, int id)
{
u32 param, tx_fifo_depth, rx_fifo_depth;
param = i2c_dw_read_comp_param(dev);
tx_fifo_depth = ((param >> 16) & 0xff) + 1;
rx_fifo_depth = ((param >> 8) & 0xff) + 1;
if (!dev->tx_fifo_depth) {
dev->tx_fifo_depth = tx_fifo_depth;
dev->rx_fifo_depth = rx_fifo_depth;
dev->adapter.nr = id;
} else if (tx_fifo_depth >= 2) {
dev->tx_fifo_depth = min_t(u32, dev->tx_fifo_depth,
tx_fifo_depth);
dev->rx_fifo_depth = min_t(u32, dev->rx_fifo_depth,
rx_fifo_depth);
}
}
static int dw_i2c_plat_probe(struct platform_device *pdev)
{
struct dw_i2c_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct i2c_adapter *adap;
struct dw_i2c_dev *dev;
u32 acpi_speed, ht = 0;
struct resource *mem;
int i, irq, ret;
const int supported_speeds[] = { 0, 100000, 400000, 1000000, 3400000 };
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
dev->rst = devm_reset_control_get_optional_exclusive(&pdev->dev, NULL);
if (IS_ERR(dev->rst)) {
if (PTR_ERR(dev->rst) == -EPROBE_DEFER)
return -EPROBE_DEFER;
} else {
reset_control_deassert(dev->rst);
}
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
for (i = 1; i < ARRAY_SIZE(supported_speeds); i++) {
if (acpi_speed < supported_speeds[i])
break;
}
acpi_speed = supported_speeds[i - 1];
if (acpi_speed && dev->clk_freq)
dev->clk_freq = min(dev->clk_freq, acpi_speed);
else if (acpi_speed || dev->clk_freq)
dev->clk_freq = max(dev->clk_freq, acpi_speed);
else
dev->clk_freq = 400000;
if (has_acpi_companion(&pdev->dev))
dw_i2c_acpi_configure(pdev);
if (dev->clk_freq != 100000 && dev->clk_freq != 400000
&& dev->clk_freq != 1000000 && dev->clk_freq != 3400000) {
dev_err(&pdev->dev,
"%d Hz is unsupported, only 100kHz, 400kHz, 1MHz and 3.4MHz are supported\n",
dev->clk_freq);
ret = -EINVAL;
goto exit_reset;
}
ret = i2c_dw_probe_lock_support(dev);
if (ret)
goto exit_reset;
if (i2c_detect_slave_mode(&pdev->dev))
i2c_dw_configure_slave(dev);
else
i2c_dw_configure_master(dev);
dev->clk = devm_clk_get(&pdev->dev, NULL);
if (!i2c_dw_plat_prepare_clk(dev, true)) {
dev->get_clk_rate_khz = i2c_dw_get_clk_rate_khz;
if (!dev->sda_hold_time && ht)
dev->sda_hold_time = div_u64(
(u64)dev->get_clk_rate_khz(dev) * ht + 500000,
1000000);
}
dw_i2c_set_fifo_size(dev, pdev->id);
adap = &dev->adapter;
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DEPRECATED;
ACPI_COMPANION_SET(&adap->dev, ACPI_COMPANION(&pdev->dev));
adap->dev.of_node = pdev->dev.of_node;
if (dev->pm_disabled) {
pm_runtime_forbid(&pdev->dev);
} else {
pm_runtime_set_autosuspend_delay(&pdev->dev, 1000);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
}
if (dev->mode == DW_IC_SLAVE)
ret = i2c_dw_probe_slave(dev);
else
ret = i2c_dw_probe(dev);
if (ret)
goto exit_probe;
return ret;
exit_probe:
if (!dev->pm_disabled)
pm_runtime_disable(&pdev->dev);
exit_reset:
if (!IS_ERR_OR_NULL(dev->rst))
reset_control_assert(dev->rst);
return ret;
}
static int dw_i2c_plat_remove(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
pm_runtime_get_sync(&pdev->dev);
i2c_del_adapter(&dev->adapter);
dev->disable(dev);
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
if (!dev->pm_disabled)
pm_runtime_disable(&pdev->dev);
if (!IS_ERR_OR_NULL(dev->rst))
reset_control_assert(dev->rst);
i2c_dw_remove_lock_support(dev);
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
static int dw_i2c_plat_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_i2c_dev *i_dev = platform_get_drvdata(pdev);
i_dev->disable(i_dev);
i2c_dw_plat_prepare_clk(i_dev, false);
return 0;
}
static int dw_i2c_plat_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_i2c_dev *i_dev = platform_get_drvdata(pdev);
i2c_dw_plat_prepare_clk(i_dev, true);
i_dev->init(i_dev);
return 0;
}
static int dw_i2c_plat_suspend(struct device *dev)
{
pm_runtime_resume(dev);
return dw_i2c_plat_runtime_suspend(dev);
}
static int __init dw_i2c_init_driver(void)
{
return platform_driver_register(&dw_i2c_driver);
}
static void __exit dw_i2c_exit_driver(void)
{
platform_driver_unregister(&dw_i2c_driver);
}
