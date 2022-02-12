static int sun9i_a80_ccu_probe(struct platform_device *pdev)
{
struct resource *res;
void __iomem *reg;
u32 val;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
val = readl(reg + SUN9I_A80_PLL_AUDIO_REG);
val &= (BIT(16) & BIT(18));
writel(val, reg + SUN9I_A80_PLL_AUDIO_REG);
return sunxi_ccu_probe(pdev->dev.of_node, reg, &sun9i_a80_ccu_desc);
}
