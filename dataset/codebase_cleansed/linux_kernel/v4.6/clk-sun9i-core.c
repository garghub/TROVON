static void sun9i_a80_get_pll4_factors(struct factors_request *req)
{
int n;
int m = 1;
int p = 1;
n = DIV_ROUND_UP(req->rate, 6000000);
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
req->rate = ((24000000 * n) >> p) / (m + 1);
req->n = n;
req->m = m;
req->p = p;
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
static void sun9i_a80_get_gt_factors(struct factors_request *req)
{
u32 div;
if (req->parent_rate < req->rate)
req->rate = req->parent_rate;
div = DIV_ROUND_UP(req->parent_rate, req->rate);
if (div > 4)
div = 4;
req->rate = req->parent_rate / div;
req->m = div;
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
static void sun9i_a80_get_ahb_factors(struct factors_request *req)
{
u32 _p;
if (req->parent_rate < req->rate)
req->rate = req->parent_rate;
_p = order_base_2(DIV_ROUND_UP(req->parent_rate, req->rate));
if (_p > 3)
_p = 3;
req->rate = req->parent_rate >> _p;
req->p = _p;
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
static void sun9i_a80_get_apb1_factors(struct factors_request *req)
{
u32 div;
if (req->parent_rate < req->rate)
req->rate = req->parent_rate;
div = DIV_ROUND_UP(req->parent_rate, req->rate);
if (div > 256)
div = 256;
req->p = order_base_2(div);
req->m = (req->parent_rate >> req->p) - 1;
req->rate = (req->parent_rate >> req->p) / (req->m + 1);
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
