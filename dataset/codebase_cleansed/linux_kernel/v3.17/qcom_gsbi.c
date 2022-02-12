static int gsbi_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct resource *res;
void __iomem *base;
struct gsbi_info *gsbi;
gsbi = devm_kzalloc(&pdev->dev, sizeof(*gsbi), GFP_KERNEL);
if (!gsbi)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
if (of_property_read_u32(node, "qcom,mode", &gsbi->mode)) {
dev_err(&pdev->dev, "missing mode configuration\n");
return -EINVAL;
}
of_property_read_u32(node, "qcom,crci", &gsbi->crci);
dev_info(&pdev->dev, "GSBI port protocol: %d crci: %d\n",
gsbi->mode, gsbi->crci);
gsbi->hclk = devm_clk_get(&pdev->dev, "iface");
if (IS_ERR(gsbi->hclk))
return PTR_ERR(gsbi->hclk);
clk_prepare_enable(gsbi->hclk);
writel_relaxed((gsbi->mode << GSBI_PROTOCOL_SHIFT) | gsbi->crci,
base + GSBI_CTRL_REG);
wmb();
platform_set_drvdata(pdev, gsbi);
return of_platform_populate(node, NULL, NULL, &pdev->dev);
}
static int gsbi_remove(struct platform_device *pdev)
{
struct gsbi_info *gsbi = platform_get_drvdata(pdev);
clk_disable_unprepare(gsbi->hclk);
return 0;
}
