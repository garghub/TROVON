static u32 i2c_dw_get_clk_rate_khz(struct dw_i2c_dev *dev)
{
return clk_get_rate(dev->clk)/1000;
}
static int dw_i2c_acpi_configure(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
if (!ACPI_HANDLE(&pdev->dev))
return -ENODEV;
dev->adapter.nr = -1;
dev->tx_fifo_depth = 32;
dev->rx_fifo_depth = 32;
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
adap->class = I2C_CLASS_HWMON;
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
of_i2c_register_devices(adap);
acpi_i2c_register_devices(adap);
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
return platform_driver_probe(&dw_i2c_driver, dw_i2c_probe);
}
static void __exit dw_i2c_exit_driver(void)
{
platform_driver_unregister(&dw_i2c_driver);
}
