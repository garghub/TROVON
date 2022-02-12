static int gsbi_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct resource *res;
void __iomem *base;
struct clk *hclk;
u32 mode, crci = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
if (of_property_read_u32(node, "qcom,mode", &mode)) {
dev_err(&pdev->dev, "missing mode configuration\n");
return -EINVAL;
}
of_property_read_u32(node, "qcom,crci", &crci);
dev_info(&pdev->dev, "GSBI port protocol: %d crci: %d\n", mode, crci);
hclk = devm_clk_get(&pdev->dev, "iface");
if (IS_ERR(hclk))
return PTR_ERR(hclk);
clk_prepare_enable(hclk);
writel_relaxed((mode << GSBI_PROTOCOL_SHIFT) | crci,
base + GSBI_CTRL_REG);
wmb();
clk_disable_unprepare(hclk);
return of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
}
