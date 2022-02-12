static void sun9i_a80_cpu_pll_fixup(void __iomem *reg)
{
u32 val = readl(reg);
if (!(val & BIT(SUN9I_A80_PLL_P_SHIFT)))
return;
val &= ~GENMASK(SUN9I_A80_PLL_N_SHIFT + SUN9I_A80_PLL_N_WIDTH - 1,
SUN9I_A80_PLL_N_SHIFT);
val |= 17 << SUN9I_A80_PLL_N_SHIFT;
val &= ~BIT(SUN9I_A80_PLL_P_SHIFT);
writel(val, reg);
}
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
sun9i_a80_cpu_pll_fixup(reg + SUN9I_A80_PLL_C0CPUX_REG);
sun9i_a80_cpu_pll_fixup(reg + SUN9I_A80_PLL_C1CPUX_REG);
return sunxi_ccu_probe(pdev->dev.of_node, reg, &sun9i_a80_ccu_desc);
}
