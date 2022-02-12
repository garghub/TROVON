static int vop_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
if (!dev->of_node) {
dev_err(dev, "can't find vop devices\n");
return -ENODEV;
}
return component_add(dev, &vop_component_ops);
}
static int vop_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vop_component_ops);
return 0;
}
