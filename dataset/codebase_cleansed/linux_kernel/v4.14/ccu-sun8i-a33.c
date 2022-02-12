static void __init sun8i_a33_ccu_setup(struct device_node *node)
{
void __iomem *reg;
u32 val;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("%pOF: Could not map the clock registers\n", node);
return;
}
val = readl(reg + SUN8I_A33_PLL_AUDIO_REG);
val &= ~GENMASK(19, 16);
writel(val | (3 << 16), reg + SUN8I_A33_PLL_AUDIO_REG);
val = readl(reg + SUN8I_A33_PLL_MIPI_REG);
val &= ~BIT(16);
writel(val, reg + SUN8I_A33_PLL_MIPI_REG);
sunxi_ccu_probe(node, reg, &sun8i_a33_ccu_desc);
ccu_pll_notifier_register(&sun8i_a33_pll_cpu_nb);
ccu_mux_notifier_register(pll_cpux_clk.common.hw.clk,
&sun8i_a33_cpu_nb);
}
