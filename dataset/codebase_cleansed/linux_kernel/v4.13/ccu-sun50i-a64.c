static int sun50i_a64_ccu_probe(struct platform_device *pdev)
{
struct resource *res;
void __iomem *reg;
u32 val;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
val = readl(reg + SUN50I_A64_PLL_AUDIO_REG);
val &= ~GENMASK(19, 16);
writel(val | (3 << 16), reg + SUN50I_A64_PLL_AUDIO_REG);
writel(0x515, reg + SUN50I_A64_PLL_MIPI_REG);
return sunxi_ccu_probe(pdev->dev.of_node, reg, &sun50i_a64_ccu_desc);
}
