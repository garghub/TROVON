static void __init sunxi_h3_h5_ccu_init(struct device_node *node,
const struct sunxi_ccu_desc *desc)
{
void __iomem *reg;
u32 val;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("%s: Could not map the clock registers\n",
of_node_full_name(node));
return;
}
val = readl(reg + SUN8I_H3_PLL_AUDIO_REG);
val &= ~GENMASK(19, 16);
writel(val | (3 << 16), reg + SUN8I_H3_PLL_AUDIO_REG);
sunxi_ccu_probe(node, reg, desc);
ccu_mux_notifier_register(pll_cpux_clk.common.hw.clk,
&sun8i_h3_cpu_nb);
}
static void __init sun8i_h3_ccu_setup(struct device_node *node)
{
sunxi_h3_h5_ccu_init(node, &sun8i_h3_ccu_desc);
}
static void __init sun50i_h5_ccu_setup(struct device_node *node)
{
sunxi_h3_h5_ccu_init(node, &sun50i_h5_ccu_desc);
}
