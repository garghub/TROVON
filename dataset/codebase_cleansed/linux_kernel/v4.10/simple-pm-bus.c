static int simple_pm_bus_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
dev_dbg(&pdev->dev, "%s\n", __func__);
pm_runtime_enable(&pdev->dev);
if (np)
of_platform_populate(np, NULL, NULL, &pdev->dev);
return 0;
}
static int simple_pm_bus_remove(struct platform_device *pdev)
{
dev_dbg(&pdev->dev, "%s\n", __func__);
pm_runtime_disable(&pdev->dev);
return 0;
}
