static void sun8i_a23_get_mbus_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div;
if (*freq > parent_rate)
*freq = parent_rate;
div = DIV_ROUND_UP(parent_rate, *freq);
if (div > 8)
div = 8;
*freq = parent_rate / div;
if (m == NULL)
return;
*m = div - 1;
}
static void __init sun8i_a23_mbus_setup(struct device_node *node)
{
struct clk *mbus;
void __iomem *reg;
reg = of_iomap(node, 0);
if (!reg) {
pr_err("Could not get registers for a23-mbus-clk\n");
return;
}
mbus = sunxi_factors_register(node, &sun8i_a23_mbus_data,
&sun8i_a23_mbus_lock, reg);
__clk_get(mbus);
clk_prepare_enable(mbus);
}
