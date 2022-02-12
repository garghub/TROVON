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
bool fs_mode = dev->master_cfg & DW_IC_CON_SPEED_FAST;
if (!ACPI_HANDLE(&pdev->dev))
return -ENODEV;
dev->adapter.nr = -1;
dev->tx_fifo_depth = 32;
dev->rx_fifo_depth = 32;
dw_i2c_acpi_params(pdev, "SSCN", &dev->ss_hcnt, &dev->ss_lcnt,
fs_mode ? NULL : &dev->sda_hold_time);
dw_i2c_acpi_params(pdev, "FMCN", &dev->fs_hcnt, &dev->fs_lcnt,
fs_mode ? &dev->sda_hold_time : NULL);
return 0;
}
static inline int dw_i2c_acpi_configure(struct platform_device *pdev)
{
return -ENODEV;
}
static int dw_i2c_probe(struct platform_device *pdev)
{
struct dw_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem;
int irq, r;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
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
dev->clk = devm_clk_get(&pdev->dev, NULL);
dev->get_clk_rate_khz = i2c_dw_get_clk_rate_khz;
if (IS_ERR(dev->clk))
return PTR_ERR(dev->clk);
clk_prepare_enable(dev->clk);
if (pdev->dev.of_node) {
u32 ht = 0;
u32 ic_clk = dev->get_clk_rate_khz(dev);
of_property_read_u32(pdev->dev.of_node,
"i2c-sda-hold-time-ns", &ht);
dev->sda_hold_time = div_u64((u64)ic_clk * ht + 500000,
1000000);
of_property_read_u32(pdev->dev.of_node,
"i2c-sda-falling-time-ns",
&dev->sda_falling_time);
of_property_read_u32(pdev->dev.of_node,
"i2c-scl-falling-time-ns",
&dev->scl_falling_time);
}
dev->functionality =
I2C_FUNC_I2C |
I2C_FUNC_10BIT_ADDR |
I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK;
dev->master_cfg = DW_IC_CON_MASTER | DW_IC_CON_SLAVE_DISABLE |
DW_IC_CON_RESTART_EN | DW_IC_CON_SPEED_FAST;
r = dw_i2c_acpi_configure(pdev);
if (r) {
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
pm_runtime_set_autosuspend_delay(&pdev->dev, 1000);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
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
