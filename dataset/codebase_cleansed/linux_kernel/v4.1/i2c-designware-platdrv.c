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
id = acpi_match_device(pdev->dev.driver->acpi_match_table, &pdev->dev);
if (id && id->driver_data)
clk_register_fixed_rate(&pdev->dev, dev_name(&pdev->dev), NULL,
CLK_IS_ROOT, id->driver_data);
return 0;
}
static void dw_i2c_acpi_unconfigure(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
const struct acpi_device_id *id;
id = acpi_match_device(pdev->dev.driver->acpi_match_table, &pdev->dev);
if (id && id->driver_data)
clk_unregister(dev->clk);
}
static inline int dw_i2c_acpi_configure(struct platform_device *pdev)
{
return -ENODEV;
}
static inline void dw_i2c_acpi_unconfigure(struct platform_device *pdev) { }
static int dw_i2c_probe(struct platform_device *pdev)
{
struct dw_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem;
struct dw_i2c_platform_data *pdata;
int irq, r;
u32 clk_freq, ht = 0;
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
init_completion(&dev->cmd_complete);
mutex_init(&dev->lock);
dev->dev = &pdev->dev;
dev->irq = irq;
platform_set_drvdata(pdev, dev);
clk_freq = 400000;
if (has_acpi_companion(&pdev->dev)) {
dw_i2c_acpi_configure(pdev);
} else if (pdev->dev.of_node) {
of_property_read_u32(pdev->dev.of_node,
"i2c-sda-hold-time-ns", &ht);
of_property_read_u32(pdev->dev.of_node,
"i2c-sda-falling-time-ns",
&dev->sda_falling_time);
of_property_read_u32(pdev->dev.of_node,
"i2c-scl-falling-time-ns",
&dev->scl_falling_time);
of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&clk_freq);
if (clk_freq != 100000 && clk_freq != 400000) {
dev_err(&pdev->dev, "Only 100kHz and 400kHz supported");
return -EINVAL;
}
} else {
pdata = dev_get_platdata(&pdev->dev);
if (pdata)
clk_freq = pdata->i2c_scl_freq;
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
if (clk_freq == 100000)
dev->master_cfg = DW_IC_CON_MASTER | DW_IC_CON_SLAVE_DISABLE |
DW_IC_CON_RESTART_EN | DW_IC_CON_SPEED_STD;
else
dev->master_cfg = DW_IC_CON_MASTER | DW_IC_CON_SLAVE_DISABLE |
DW_IC_CON_RESTART_EN | DW_IC_CON_SPEED_FAST;
dev->clk = devm_clk_get(&pdev->dev, NULL);
dev->get_clk_rate_khz = i2c_dw_get_clk_rate_khz;
if (IS_ERR(dev->clk))
return PTR_ERR(dev->clk);
clk_prepare_enable(dev->clk);
if (!dev->sda_hold_time && ht) {
u32 ic_clk = dev->get_clk_rate_khz(dev);
dev->sda_hold_time = div_u64((u64)ic_clk * ht + 500000,
1000000);
}
if (!dev->tx_fifo_depth) {
u32 param1 = i2c_dw_read_comp_param(dev);
dev->tx_fifo_depth = ((param1 >> 16) & 0xff) + 1;
dev->rx_fifo_depth = ((param1 >> 8) & 0xff) + 1;
dev->adapter.nr = pdev->id;
}
r = i2c_dw_init(dev);
if (r)
return r;
i2c_dw_disable_int(dev);
r = devm_request_irq(&pdev->dev, dev->irq, i2c_dw_isr, IRQF_SHARED,
pdev->name, dev);
if (r) {
dev_err(&pdev->dev, "failure requesting irq %i\n", dev->irq);
return r;
}
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DEPRECATED;
strlcpy(adap->name, "Synopsys DesignWare I2C adapter",
sizeof(adap->name));
adap->algo = &i2c_dw_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
r = i2c_add_numbered_adapter(adap);
if (r) {
dev_err(&pdev->dev, "failure adding adapter\n");
return r;
}
if (dev->pm_runtime_disabled) {
pm_runtime_forbid(&pdev->dev);
} else {
pm_runtime_set_autosuspend_delay(&pdev->dev, 1000);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
}
return 0;
}
static int dw_i2c_remove(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
pm_runtime_get_sync(&pdev->dev);
i2c_del_adapter(&dev->adapter);
i2c_dw_disable(dev);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (has_acpi_companion(&pdev->dev))
dw_i2c_acpi_unconfigure(pdev);
return 0;
}
static int dw_i2c_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_i2c_dev *i_dev = platform_get_drvdata(pdev);
i2c_dw_disable(i_dev);
clk_disable_unprepare(i_dev->clk);
return 0;
}
static int dw_i2c_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_i2c_dev *i_dev = platform_get_drvdata(pdev);
clk_prepare_enable(i_dev->clk);
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
