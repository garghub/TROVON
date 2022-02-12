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
static int __init am335x_child_init(void)
{
return platform_driver_register(&am335x_child_driver);
}
