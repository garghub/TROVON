static int kirkwood_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
writel(0x7, ddr_operation_base);
cpu_do_idle();
return index;
}
static int kirkwood_cpuidle_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL)
return -EINVAL;
ddr_operation_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ddr_operation_base))
return PTR_ERR(ddr_operation_base);
return cpuidle_register(&kirkwood_idle_driver, NULL);
}
int kirkwood_cpuidle_remove(struct platform_device *pdev)
{
cpuidle_unregister(&kirkwood_idle_driver);
return 0;
}
