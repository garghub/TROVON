static void __init sunxi_r_ccu_init(struct device_node *node,
const struct sunxi_ccu_desc *desc)
{
void __iomem *reg;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("%pOF: Could not map the clock registers\n", node);
return;
}
sunxi_ccu_probe(node, reg, desc);
}
static void __init sun8i_a83t_r_ccu_setup(struct device_node *node)
{
sunxi_r_ccu_init(node, &sun8i_a83t_r_ccu_desc);
}
static void __init sun8i_h3_r_ccu_setup(struct device_node *node)
{
sunxi_r_ccu_init(node, &sun8i_h3_r_ccu_desc);
}
static void __init sun50i_a64_r_ccu_setup(struct device_node *node)
{
sunxi_r_ccu_init(node, &sun50i_a64_r_ccu_desc);
}
