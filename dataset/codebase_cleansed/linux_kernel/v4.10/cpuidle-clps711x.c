static int clps711x_cpuidle_halt(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
writel(0xaa, clps711x_halt);
return index;
}
static int __init clps711x_cpuidle_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
clps711x_halt = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(clps711x_halt))
return PTR_ERR(clps711x_halt);
return cpuidle_register(&clps711x_idle_driver, NULL);
}
