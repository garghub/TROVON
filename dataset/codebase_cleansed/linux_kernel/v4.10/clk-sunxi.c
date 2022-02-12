static void sun4i_get_pll1_factors(struct factors_request *req)
{
u8 div;
div = req->rate / 6000000;
req->rate = 6000000 * div;
req->m = 0;
if (req->rate >= 768000000 || req->rate == 42000000 ||
req->rate == 54000000)
req->k = 1;
else
req->k = 0;
if (div < 10)
req->p = 3;
else if (div < 20 || (div < 32 && (div & 1)))
req->p = 2;
else if (div < 40 || (div < 64 && (div & 2)))
req->p = 1;
else
req->p = 0;
div <<= req->p;
div /= (req->k + 1);
req->n = div / 4;
}
static void sun6i_a31_get_pll1_factors(struct factors_request *req)
{
u32 freq_mhz = req->rate / 1000000;
u32 parent_freq_mhz = req->parent_rate / 1000000;
u32 round_freq_6 = round_down(freq_mhz, 6);
u32 round_freq_16 = round_down(freq_mhz, 16);
if (round_freq_6 > round_freq_16)
freq_mhz = round_freq_6;
else
freq_mhz = round_freq_16;
req->rate = freq_mhz * 1000000;
if (!(freq_mhz % 32))
req->k = 3;
else if (!(freq_mhz % 9))
req->k = 2;
else if (!(freq_mhz % 8))
req->k = 1;
else
req->k = 0;
if ((freq_mhz % 6) == 2 || (freq_mhz % 6) == 4)
req->m = 2;
else if ((freq_mhz / 6) & 1)
req->m = 3;
else
req->m = 1;
req->n = freq_mhz * (req->m + 1) / ((req->k + 1) * parent_freq_mhz)
- 1;
if ((req->n + 1) > 31 && (req->m + 1) > 1) {
req->n = (req->n + 1) / 2 - 1;
req->m = (req->m + 1) / 2 - 1;
}
}
static void sun8i_a23_get_pll1_factors(struct factors_request *req)
{
u8 div;
div = req->rate / 6000000;
req->rate = 6000000 * div;
req->m = 0;
if (req->rate >= 768000000 || req->rate == 42000000 ||
req->rate == 54000000)
req->k = 1;
else
req->k = 0;
if (div < 20 || (div < 32 && (div & 1)))
req->p = 2;
else if (div < 40 || (div < 64 && (div & 2)))
req->p = 1;
else
req->p = 0;
div <<= req->p;
div /= (req->k + 1);
req->n = div / 4 - 1;
}
static void sun4i_get_pll5_factors(struct factors_request *req)
{
u8 div;
div = req->rate / req->parent_rate;
req->rate = req->parent_rate * div;
if (div < 31)
req->k = 0;
else if (div / 2 < 31)
req->k = 1;
else if (div / 3 < 31)
req->k = 2;
else
req->k = 3;
req->n = DIV_ROUND_UP(div, (req->k + 1));
}
static void sun6i_a31_get_pll6_factors(struct factors_request *req)
{
u8 div;
div = req->rate / req->parent_rate;
req->rate = req->parent_rate * div;
req->k = div / 32;
if (req->k > 3)
req->k = 3;
req->n = DIV_ROUND_UP(div, (req->k + 1)) - 1;
}
static void sun5i_a13_get_ahb_factors(struct factors_request *req)
{
u32 div;
if (req->parent_rate < req->rate)
req->rate = req->parent_rate;
if (req->rate < 8000)
req->rate = 8000;
if (req->rate > 300000000)
req->rate = 300000000;
div = order_base_2(DIV_ROUND_UP(req->parent_rate, req->rate));
if (div > 3)
div = 3;
req->rate = req->parent_rate >> div;
req->p = div;
}
static void sun6i_get_ahb1_factors(struct factors_request *req)
{
u8 div, calcp, calcm = 1;
if (req->parent_rate && req->rate > req->parent_rate)
req->rate = req->parent_rate;
div = DIV_ROUND_UP(req->parent_rate, req->rate);
if (req->parent_index == SUN6I_AHB1_PARENT_PLL6) {
if (div < 4)
calcp = 0;
else if (div / 2 < 4)
calcp = 1;
else if (div / 4 < 4)
calcp = 2;
else
calcp = 3;
calcm = DIV_ROUND_UP(div, 1 << calcp);
} else {
calcp = __roundup_pow_of_two(div);
calcp = calcp > 3 ? 3 : calcp;
}
req->rate = (req->parent_rate / calcm) >> calcp;
req->p = calcp;
req->m = calcm - 1;
}
static void sun6i_ahb1_recalc(struct factors_request *req)
{
req->rate = req->parent_rate;
if (req->parent_index == SUN6I_AHB1_PARENT_PLL6)
req->rate /= req->m + 1;
req->rate >>= req->p;
}
static void sun4i_get_apb1_factors(struct factors_request *req)
{
u8 calcm, calcp;
int div;
if (req->parent_rate < req->rate)
req->rate = req->parent_rate;
div = DIV_ROUND_UP(req->parent_rate, req->rate);
if (div > 32)
return;
if (div <= 4)
calcp = 0;
else if (div <= 8)
calcp = 1;
else if (div <= 16)
calcp = 2;
else
calcp = 3;
calcm = (div >> calcp) - 1;
req->rate = (req->parent_rate >> calcp) / (calcm + 1);
req->m = calcm;
req->p = calcp;
}
static void sun7i_a20_get_out_factors(struct factors_request *req)
{
u8 div, calcm, calcp;
if (req->rate > req->parent_rate)
req->rate = req->parent_rate;
div = DIV_ROUND_UP(req->parent_rate, req->rate);
if (div < 32)
calcp = 0;
else if (div / 2 < 32)
calcp = 1;
else if (div / 4 < 32)
calcp = 2;
else
calcp = 3;
calcm = DIV_ROUND_UP(div, 1 << calcp);
req->rate = (req->parent_rate >> calcp) / calcm;
req->m = calcm - 1;
req->p = calcp;
}
static struct clk * __init sunxi_factors_clk_setup(struct device_node *node,
const struct factors_data *data)
{
void __iomem *reg;
reg = of_iomap(node, 0);
if (!reg) {
pr_err("Could not get registers for factors-clk: %s\n",
node->name);
return NULL;
}
return sunxi_factors_register(node, data, &clk_lock, reg);
}
static void __init sun4i_pll1_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun4i_pll1_data);
}
static void __init sun6i_pll1_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun6i_a31_pll1_data);
}
static void __init sun8i_pll1_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun8i_a23_pll1_data);
}
static void __init sun7i_pll4_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun7i_a20_pll4_data);
}
static void __init sun5i_ahb_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun5i_a13_ahb_data);
}
static void __init sun6i_ahb1_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun6i_ahb1_data);
}
static void __init sun4i_apb1_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun4i_apb1_data);
}
static void __init sun7i_out_clk_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun7i_a20_out_data);
}
static struct clk * __init sunxi_mux_clk_setup(struct device_node *node,
const struct mux_data *data)
{
struct clk *clk;
const char *clk_name = node->name;
const char *parents[SUNXI_MAX_PARENTS];
void __iomem *reg;
int i;
reg = of_iomap(node, 0);
if (!reg) {
pr_err("Could not map registers for mux-clk: %s\n",
of_node_full_name(node));
return NULL;
}
i = of_clk_parent_fill(node, parents, SUNXI_MAX_PARENTS);
if (of_property_read_string(node, "clock-output-names", &clk_name)) {
pr_err("%s: could not read clock-output-names from \"%s\"\n",
__func__, of_node_full_name(node));
goto out_unmap;
}
clk = clk_register_mux(NULL, clk_name, parents, i,
CLK_SET_RATE_PARENT, reg,
data->shift, SUNXI_MUX_GATE_WIDTH,
0, &clk_lock);
if (IS_ERR(clk)) {
pr_err("%s: failed to register mux clock %s: %ld\n", __func__,
clk_name, PTR_ERR(clk));
goto out_unmap;
}
if (of_clk_add_provider(node, of_clk_src_simple_get, clk)) {
pr_err("%s: failed to add clock provider for %s\n",
__func__, clk_name);
clk_unregister_divider(clk);
goto out_unmap;
}
return clk;
out_unmap:
iounmap(reg);
return NULL;
}
static void __init sun4i_cpu_clk_setup(struct device_node *node)
{
struct clk *clk;
clk = sunxi_mux_clk_setup(node, &sun4i_cpu_mux_data);
if (!clk)
return;
__clk_get(clk);
clk_prepare_enable(clk);
}
static void __init sun6i_ahb1_mux_clk_setup(struct device_node *node)
{
sunxi_mux_clk_setup(node, &sun6i_a31_ahb1_mux_data);
}
static void __init sun8i_ahb2_clk_setup(struct device_node *node)
{
sunxi_mux_clk_setup(node, &sun8i_h3_ahb2_mux_data);
}
static void __init sunxi_divider_clk_setup(struct device_node *node,
const struct div_data *data)
{
struct clk *clk;
const char *clk_name = node->name;
const char *clk_parent;
void __iomem *reg;
reg = of_iomap(node, 0);
if (!reg) {
pr_err("Could not map registers for mux-clk: %s\n",
of_node_full_name(node));
return;
}
clk_parent = of_clk_get_parent_name(node, 0);
if (of_property_read_string(node, "clock-output-names", &clk_name)) {
pr_err("%s: could not read clock-output-names from \"%s\"\n",
__func__, of_node_full_name(node));
goto out_unmap;
}
clk = clk_register_divider_table(NULL, clk_name, clk_parent, 0,
reg, data->shift, data->width,
data->pow ? CLK_DIVIDER_POWER_OF_TWO : 0,
data->table, &clk_lock);
if (IS_ERR(clk)) {
pr_err("%s: failed to register divider clock %s: %ld\n",
__func__, clk_name, PTR_ERR(clk));
goto out_unmap;
}
if (of_clk_add_provider(node, of_clk_src_simple_get, clk)) {
pr_err("%s: failed to add clock provider for %s\n",
__func__, clk_name);
goto out_unregister;
}
if (clk_register_clkdev(clk, clk_name, NULL)) {
of_clk_del_provider(node);
goto out_unregister;
}
return;
out_unregister:
clk_unregister_divider(clk);
out_unmap:
iounmap(reg);
}
static void __init sun4i_ahb_clk_setup(struct device_node *node)
{
sunxi_divider_clk_setup(node, &sun4i_ahb_data);
}
static void __init sun4i_apb0_clk_setup(struct device_node *node)
{
sunxi_divider_clk_setup(node, &sun4i_apb0_data);
}
static void __init sun4i_axi_clk_setup(struct device_node *node)
{
sunxi_divider_clk_setup(node, &sun4i_axi_data);
}
static void __init sun8i_axi_clk_setup(struct device_node *node)
{
sunxi_divider_clk_setup(node, &sun8i_a23_axi_data);
}
static struct clk ** __init sunxi_divs_clk_setup(struct device_node *node,
const struct divs_data *data)
{
struct clk_onecell_data *clk_data;
const char *parent;
const char *clk_name;
struct clk **clks, *pclk;
struct clk_hw *gate_hw, *rate_hw;
const struct clk_ops *rate_ops;
struct clk_gate *gate = NULL;
struct clk_fixed_factor *fix_factor;
struct clk_divider *divider;
struct factors_data factors = *data->factors;
char *derived_name = NULL;
void __iomem *reg;
int ndivs = SUNXI_DIVS_MAX_QTY, i = 0;
int flags, clkflags;
if (data->ndivs)
ndivs = data->ndivs;
for (i = 0; i < ndivs; i++) {
if (data->div[i].self) {
of_property_read_string_index(node, "clock-output-names",
i, &factors.name);
break;
}
}
if (factors.name == NULL) {
char *endp;
of_property_read_string_index(node, "clock-output-names",
0, &clk_name);
endp = strchr(clk_name, '_');
if (endp) {
derived_name = kstrndup(clk_name, endp - clk_name,
GFP_KERNEL);
factors.name = derived_name;
} else {
factors.name = clk_name;
}
}
pclk = sunxi_factors_clk_setup(node, &factors);
if (!pclk)
return NULL;
parent = __clk_get_name(pclk);
kfree(derived_name);
reg = of_iomap(node, 0);
if (!reg) {
pr_err("Could not map registers for divs-clk: %s\n",
of_node_full_name(node));
return NULL;
}
clk_data = kmalloc(sizeof(struct clk_onecell_data), GFP_KERNEL);
if (!clk_data)
goto out_unmap;
clks = kcalloc(ndivs, sizeof(*clks), GFP_KERNEL);
if (!clks)
goto free_clkdata;
clk_data->clks = clks;
clkflags = !strcmp("pll5", parent) ? 0 : CLK_SET_RATE_PARENT;
for (i = 0; i < ndivs; i++) {
if (of_property_read_string_index(node, "clock-output-names",
i, &clk_name) != 0)
break;
if (data->div[i].self) {
clk_data->clks[i] = pclk;
continue;
}
gate_hw = NULL;
rate_hw = NULL;
rate_ops = NULL;
if (data->div[i].gate) {
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate)
goto free_clks;
gate->reg = reg;
gate->bit_idx = data->div[i].gate;
gate->lock = &clk_lock;
gate_hw = &gate->hw;
}
if (data->div[i].fixed) {
fix_factor = kzalloc(sizeof(*fix_factor), GFP_KERNEL);
if (!fix_factor)
goto free_gate;
fix_factor->mult = 1;
fix_factor->div = data->div[i].fixed;
rate_hw = &fix_factor->hw;
rate_ops = &clk_fixed_factor_ops;
} else {
divider = kzalloc(sizeof(*divider), GFP_KERNEL);
if (!divider)
goto free_gate;
flags = data->div[i].pow ? CLK_DIVIDER_POWER_OF_TWO : 0;
divider->reg = reg;
divider->shift = data->div[i].shift;
divider->width = SUNXI_DIVISOR_WIDTH;
divider->flags = flags;
divider->lock = &clk_lock;
divider->table = data->div[i].table;
rate_hw = &divider->hw;
rate_ops = &clk_divider_ops;
}
clks[i] = clk_register_composite(NULL, clk_name, &parent, 1,
NULL, NULL,
rate_hw, rate_ops,
gate_hw, &clk_gate_ops,
clkflags);
WARN_ON(IS_ERR(clk_data->clks[i]));
}
clk_data->clk_num = i;
if (of_clk_add_provider(node, of_clk_src_onecell_get, clk_data)) {
pr_err("%s: failed to add clock provider for %s\n",
__func__, clk_name);
goto free_gate;
}
return clks;
free_gate:
kfree(gate);
free_clks:
kfree(clks);
free_clkdata:
kfree(clk_data);
out_unmap:
iounmap(reg);
return NULL;
}
static void __init sun4i_pll5_clk_setup(struct device_node *node)
{
struct clk **clks;
clks = sunxi_divs_clk_setup(node, &pll5_divs_data);
if (!clks)
return;
__clk_get(clks[0]);
clk_prepare_enable(clks[0]);
}
static void __init sun4i_pll6_clk_setup(struct device_node *node)
{
sunxi_divs_clk_setup(node, &pll6_divs_data);
}
static void __init sun6i_pll6_clk_setup(struct device_node *node)
{
sunxi_divs_clk_setup(node, &sun6i_a31_pll6_divs_data);
}
static void sun6i_display_factors(struct factors_request *req)
{
u8 m;
if (req->rate > req->parent_rate)
req->rate = req->parent_rate;
m = DIV_ROUND_UP(req->parent_rate, req->rate);
req->rate = req->parent_rate / m;
req->m = m - 1;
}
static void __init sun6i_display_setup(struct device_node *node)
{
sunxi_factors_clk_setup(node, &sun6i_display_data);
}
