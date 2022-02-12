static void __init sun8i_r40_ccu_setup(struct device_node *node)
{
void __iomem *reg;
u32 val;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("%s: Could not map the clock registers\n",
of_node_full_name(node));
return;
}
val = readl(reg + SUN8I_R40_PLL_AUDIO_REG);
val &= ~GENMASK(19, 16);
writel(val | (3 << 16), reg + SUN8I_R40_PLL_AUDIO_REG);
val = readl(reg + SUN8I_R40_PLL_MIPI_REG);
val &= ~BIT(16);
writel(val, reg + SUN8I_R40_PLL_MIPI_REG);
val = readl(reg + SUN8I_R40_USB_CLK_REG);
val &= ~GENMASK(25, 20);
writel(val, reg + SUN8I_R40_USB_CLK_REG);
sunxi_ccu_probe(node, reg, &sun8i_r40_ccu_desc);
ccu_pll_notifier_register(&sun8i_r40_pll_cpu_nb);
ccu_mux_notifier_register(pll_cpu_clk.common.hw.clk,
&sun8i_r40_cpu_nb);
}
