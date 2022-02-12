static int alt_pr_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
void __iomem *reg_base;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg_base = devm_ioremap_resource(dev, res);
if (IS_ERR(reg_base))
return PTR_ERR(reg_base);
return alt_pr_register(dev, reg_base);
}
static int alt_pr_platform_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
return alt_pr_unregister(dev);
}
