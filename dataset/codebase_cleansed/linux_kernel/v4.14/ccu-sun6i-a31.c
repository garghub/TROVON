static void __init sun6i_a31_ccu_setup(struct device_node *node)
{
void __iomem *reg;
u32 val;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("%pOF: Could not map the clock registers\n", node);
return;
}
val = readl(reg + SUN6I_A31_PLL_AUDIO_REG);
val &= ~GENMASK(19, 16);
writel(val | (3 << 16), reg + SUN6I_A31_PLL_AUDIO_REG);
val = readl(reg + SUN6I_A31_PLL_MIPI_REG);
val &= BIT(16);
writel(val, reg + SUN6I_A31_PLL_MIPI_REG);
val = readl(reg + SUN6I_A31_AHB1_REG);
val &= ~GENMASK(7, 6);
val |= 0x2 << 6;
val &= ~GENMASK(13, 12);
val |= 0x3 << 12;
writel(val, reg + SUN6I_A31_AHB1_REG);
sunxi_ccu_probe(node, reg, &sun6i_a31_ccu_desc);
ccu_mux_notifier_register(pll_cpu_clk.common.hw.clk,
&sun6i_a31_cpu_nb);
}
