static int fimc_is_i2c_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct fimc_is_i2c *isp_i2c;
struct i2c_adapter *i2c_adap;
int ret;
isp_i2c = devm_kzalloc(&pdev->dev, sizeof(*isp_i2c), GFP_KERNEL);
if (!isp_i2c)
return -ENOMEM;
isp_i2c->clock = devm_clk_get(&pdev->dev, "i2c_isp");
if (IS_ERR(isp_i2c->clock)) {
dev_err(&pdev->dev, "failed to get the clock\n");
return PTR_ERR(isp_i2c->clock);
}
i2c_adap = &isp_i2c->adapter;
i2c_adap->dev.of_node = node;
i2c_adap->dev.parent = &pdev->dev;
strlcpy(i2c_adap->name, "exynos4x12-isp-i2c", sizeof(i2c_adap->name));
i2c_adap->owner = THIS_MODULE;
i2c_adap->algo = &fimc_is_i2c_algorithm;
i2c_adap->class = I2C_CLASS_SPD;
ret = i2c_add_adapter(i2c_adap);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add I2C bus %s\n",
node->full_name);
return ret;
}
platform_set_drvdata(pdev, isp_i2c);
pm_runtime_enable(&pdev->dev);
pm_runtime_enable(&i2c_adap->dev);
of_i2c_register_devices(i2c_adap);
return 0;
}
static int fimc_is_i2c_remove(struct platform_device *pdev)
{
struct fimc_is_i2c *isp_i2c = platform_get_drvdata(pdev);
pm_runtime_disable(&isp_i2c->adapter.dev);
pm_runtime_disable(&pdev->dev);
i2c_del_adapter(&isp_i2c->adapter);
return 0;
}
static int fimc_is_i2c_suspend(struct device *dev)
{
struct fimc_is_i2c *isp_i2c = dev_get_drvdata(dev);
clk_disable_unprepare(isp_i2c->clock);
return 0;
}
static int fimc_is_i2c_resume(struct device *dev)
{
struct fimc_is_i2c *isp_i2c = dev_get_drvdata(dev);
return clk_prepare_enable(isp_i2c->clock);
}
int fimc_is_register_i2c_driver(void)
{
return platform_driver_register(&fimc_is_i2c_driver);
}
void fimc_is_unregister_i2c_driver(void)
{
platform_driver_unregister(&fimc_is_i2c_driver);
}
