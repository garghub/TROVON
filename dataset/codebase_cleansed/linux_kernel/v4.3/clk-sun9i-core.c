static void sun9i_a80_get_pll4_factors(u32 *freq, u32 parent_rate,
u8 *n_ret, u8 *k, u8 *m_ret, u8 *p_ret)
{
int n;
int m = 1;
int p = 1;
n = DIV_ROUND_UP(*freq, 6000000);
if (n > 255) {
m = 0;
n = (n + 1) / 2;
}
if (n > 255) {
p = 0;
n = (n + 1) / 2;
}
if (n > 255)
n = 255;
else if (n < 12)
n = 12;
*freq = ((24000000 * n) >> p) / (m + 1);
if (n_ret == NULL)
return;
*n_ret = n;
*m_ret = m;
*p_ret = p;
}
static void __init sun9i_a80_pll4_setup(struct device_node *node)
{
void __iomem *reg;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("Could not get registers for a80-pll4-clk: %s\n",
node->name);
return;
}
sunxi_factors_register(node, &sun9i_a80_pll4_data,
&sun9i_a80_pll4_lock, reg);
}
static void sun9i_a80_get_gt_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u32 div;
if (parent_rate < *freq)
*freq = parent_rate;
div = DIV_ROUND_UP(parent_rate, *freq);
if (div > 4)
div = 4;
*freq = parent_rate / div;
if (!m)
return;
*m = div;
}
static void __init sun9i_a80_gt_setup(struct device_node *node)
{
void __iomem *reg;
struct clk *gt;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("Could not get registers for a80-gt-clk: %s\n",
node->name);
return;
}
gt = sunxi_factors_register(node, &sun9i_a80_gt_data,
&sun9i_a80_gt_lock, reg);
__clk_get(gt);
clk_prepare_enable(gt);
}
static void sun9i_a80_get_ahb_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u32 _p;
if (parent_rate < *freq)
*freq = parent_rate;
_p = order_base_2(DIV_ROUND_UP(parent_rate, *freq));
if (_p > 3)
_p = 3;
*freq = parent_rate >> _p;
if (!p)
return;
*p = _p;
}
static void __init sun9i_a80_ahb_setup(struct device_node *node)
{
void __iomem *reg;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("Could not get registers for a80-ahb-clk: %s\n",
node->name);
return;
}
sunxi_factors_register(node, &sun9i_a80_ahb_data,
&sun9i_a80_ahb_lock, reg);
}
static void __init sun9i_a80_apb0_setup(struct device_node *node)
{
void __iomem *reg;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("Could not get registers for a80-apb0-clk: %s\n",
node->name);
return;
}
sunxi_factors_register(node, &sun9i_a80_apb0_data,
&sun9i_a80_apb0_lock, reg);
}
static void sun9i_a80_get_apb1_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u32 div;
u8 calcm, calcp;
if (parent_rate < *freq)
*freq = parent_rate;
div = DIV_ROUND_UP(parent_rate, *freq);
if (div > 256)
div = 256;
calcp = order_base_2(div);
calcm = (parent_rate >> calcp) - 1;
*freq = (parent_rate >> calcp) / (calcm + 1);
if (n == NULL)
return;
*m = calcm;
*p = calcp;
}
static void __init sun9i_a80_apb1_setup(struct device_node *node)
{
void __iomem *reg;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("Could not get registers for a80-apb1-clk: %s\n",
node->name);
return;
}
sunxi_factors_register(node, &sun9i_a80_apb1_data,
&sun9i_a80_apb1_lock, reg);
}
