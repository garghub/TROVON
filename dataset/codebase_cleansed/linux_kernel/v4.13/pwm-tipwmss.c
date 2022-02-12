static int pwmss_probe(struct platform_device *pdev)
{
int ret;
struct device_node *node = pdev->dev.of_node;
pm_runtime_enable(&pdev->dev);
ret = of_platform_populate(node, NULL, NULL, &pdev->dev);
if (ret)
dev_err(&pdev->dev, "no child node found\n");
return ret;
}
static int pwmss_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
