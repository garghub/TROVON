static u32 i2c_dw_get_clk_rate_khz(struct dw_i2c_dev *dev)
{
return clk_get_rate(dev->clk)/1000;
}
static int dw_i2c_probe(struct platform_device *pdev)
{
struct dw_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem, *ioarea;
int irq, r;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
ioarea = request_mem_region(mem->start, resource_size(mem),
pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "I2C region already claimed\n");
return -EBUSY;
}
dev = kzalloc(sizeof(struct dw_i2c_dev), GFP_KERNEL);
if (!dev) {
r = -ENOMEM;
goto err_release_region;
}
init_completion(&dev->cmd_complete);
mutex_init(&dev->lock);
dev->dev = get_device(&pdev->dev);
dev->irq = irq;
platform_set_drvdata(pdev, dev);
dev->clk = clk_get(&pdev->dev, NULL);
dev->get_clk_rate_khz = i2c_dw_get_clk_rate_khz;
if (IS_ERR(dev->clk)) {
r = -ENODEV;
goto err_free_mem;
}
clk_prepare_enable(dev->clk);
dev->functionality =
I2C_FUNC_I2C |
I2C_FUNC_10BIT_ADDR |
I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK;
dev->master_cfg = DW_IC_CON_MASTER | DW_IC_CON_SLAVE_DISABLE |
DW_IC_CON_RESTART_EN | DW_IC_CON_SPEED_FAST;
dev->base = ioremap(mem->start, resource_size(mem));
if (dev->base == NULL) {
dev_err(&pdev->dev, "failure mapping io resources\n");
r = -EBUSY;
goto err_unuse_clocks;
}
{
u32 param1 = i2c_dw_read_comp_param(dev);
dev->tx_fifo_depth = ((param1 >> 16) & 0xff) + 1;
dev->rx_fifo_depth = ((param1 >> 8) & 0xff) + 1;
}
r = i2c_dw_init(dev);
if (r)
goto err_iounmap;
i2c_dw_disable_int(dev);
r = request_irq(dev->irq, i2c_dw_isr, IRQF_DISABLED, pdev->name, dev);
if (r) {
dev_err(&pdev->dev, "failure requesting irq %i\n", dev->irq);
goto err_iounmap;
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
adap->nr = pdev->id;
r = i2c_add_numbered_adapter(adap);
if (r) {
dev_err(&pdev->dev, "failure adding adapter\n");
goto err_free_irq;
}
of_i2c_register_devices(adap);
return 0;
err_free_irq:
free_irq(dev->irq, dev);
err_iounmap:
iounmap(dev->base);
err_unuse_clocks:
clk_disable_unprepare(dev->clk);
clk_put(dev->clk);
dev->clk = NULL;
err_free_mem:
platform_set_drvdata(pdev, NULL);
put_device(&pdev->dev);
kfree(dev);
err_release_region:
release_mem_region(mem->start, resource_size(mem));
return r;
}
static int dw_i2c_remove(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
struct resource *mem;
platform_set_drvdata(pdev, NULL);
i2c_del_adapter(&dev->adapter);
put_device(&pdev->dev);
clk_disable_unprepare(dev->clk);
clk_put(dev->clk);
dev->clk = NULL;
i2c_dw_disable(dev);
free_irq(dev->irq, dev);
kfree(dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
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
