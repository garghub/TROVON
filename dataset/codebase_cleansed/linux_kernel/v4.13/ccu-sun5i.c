static void __init sun5i_ccu_init(struct device_node *node,
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
val = readl(reg + SUN5I_PLL_AUDIO_REG);
val &= ~GENMASK(19, 16);
writel(val | (3 << 16), reg + SUN5I_PLL_AUDIO_REG);
val = readl(reg + SUN5I_AHB_REG);
val &= ~GENMASK(7, 6);
writel(val | (2 << 6), reg + SUN5I_AHB_REG);
sunxi_ccu_probe(node, reg, desc);
}
static void __init sun5i_a10s_ccu_setup(struct device_node *node)
{
sun5i_ccu_init(node, &sun5i_a10s_ccu_desc);
}
static void __init sun5i_a13_ccu_setup(struct device_node *node)
{
sun5i_ccu_init(node, &sun5i_a13_ccu_desc);
}
static void __init sun5i_gr8_ccu_setup(struct device_node *node)
{
sun5i_ccu_init(node, &sun5i_gr8_ccu_desc);
}
