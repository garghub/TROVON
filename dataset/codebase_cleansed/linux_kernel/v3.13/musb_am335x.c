static int am335x_child_probe(struct platform_device *pdev)
{
int ret;
pm_runtime_enable(&pdev->dev);
ret = of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
if (ret)
goto err;
return 0;
err:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int of_remove_populated_child(struct device *dev, void *d)
{
struct platform_device *pdev = to_platform_device(dev);
of_device_unregister(pdev);
return 0;
}
static int am335x_child_remove(struct platform_device *pdev)
{
device_for_each_child(&pdev->dev, NULL, of_remove_populated_child);
pm_runtime_disable(&pdev->dev);
return 0;
}
