static void sun8i_a83t_cpu_pll_fixup(void __iomem *reg)
{
u32 val = readl(reg);
if (!(val & BIT(SUN8I_A83T_PLL_P_SHIFT)))
return;
val &= ~GENMASK(SUN8I_A83T_PLL_N_SHIFT + SUN8I_A83T_PLL_N_WIDTH - 1,
SUN8I_A83T_PLL_N_SHIFT);
val |= 17 << SUN8I_A83T_PLL_N_SHIFT;
val &= ~BIT(SUN8I_A83T_PLL_P_SHIFT);
writel(val, reg);
}
static int sun8i_a83t_ccu_probe(struct platform_device *pdev)
{
struct resource *res;
void __iomem *reg;
u32 val;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
val = readl(reg + SUN8I_A83T_PLL_AUDIO_REG);
val &= ~(BIT(16) | BIT(18));
writel(val, reg + SUN8I_A83T_PLL_AUDIO_REG);
sun8i_a83t_cpu_pll_fixup(reg + SUN8I_A83T_PLL_C0CPUX_REG);
sun8i_a83t_cpu_pll_fixup(reg + SUN8I_A83T_PLL_C1CPUX_REG);
return sunxi_ccu_probe(pdev->dev.of_node, reg, &sun8i_a83t_ccu_desc);
}
