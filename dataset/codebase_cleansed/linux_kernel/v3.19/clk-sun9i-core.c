static void sun9i_a80_get_pll4_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
int div;
div = DIV_ROUND_UP(*freq, 6000000);
if (div > 256)
div = round_up(div, 2);
if (div > 512)
div = round_up(div, 4);
*freq = 6000000 * div;
if (n == NULL)
return;
if (div < 512)
*p = 1;
else
*p = 0;
if (div & 1)
*m = 1;
else
*m = 0;
*n = div / (*p + 1) / (*m + 1);
}
static void __init sun9i_a80_pll4_setup(struct device_node *node)
{
sunxi_factors_register(node, &sun9i_a80_pll4_data, &sun9i_a80_pll4_lock);
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
struct clk *gt = sunxi_factors_register(node, &sun9i_a80_gt_data,
&sun9i_a80_gt_lock);
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
sunxi_factors_register(node, &sun9i_a80_ahb_data, &sun9i_a80_ahb_lock);
}
static void __init sun9i_a80_apb0_setup(struct device_node *node)
{
sunxi_factors_register(node, &sun9i_a80_apb0_data, &sun9i_a80_apb0_lock);
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
sunxi_factors_register(node, &sun9i_a80_apb1_data, &sun9i_a80_apb1_lock);
}
