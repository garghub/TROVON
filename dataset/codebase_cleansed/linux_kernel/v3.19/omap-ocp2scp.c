static int ocp2scp_remove_devices(struct device *dev, void *c)
{
struct platform_device *pdev = to_platform_device(dev);
platform_device_unregister(pdev);
return 0;
}
static int omap_ocp2scp_probe(struct platform_device *pdev)
{
int ret;
struct device_node *np = pdev->dev.of_node;
if (np) {
ret = of_platform_populate(np, NULL, NULL, &pdev->dev);
if (ret) {
dev_err(&pdev->dev,
"failed to add resources for ocp2scp child\n");
goto err0;
}
}
pm_runtime_enable(&pdev->dev);
return 0;
err0:
device_for_each_child(&pdev->dev, NULL, ocp2scp_remove_devices);
return ret;
}
static int omap_ocp2scp_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
device_for_each_child(&pdev->dev, NULL, ocp2scp_remove_devices);
return 0;
}
