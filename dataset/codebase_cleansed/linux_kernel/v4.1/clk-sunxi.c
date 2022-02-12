static unsigned long sun6i_ahb1_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct sun6i_ahb1_clk *ahb1 = to_sun6i_ahb1_clk(hw);
unsigned long rate;
u32 reg;
reg = readl(ahb1->reg);
if (SUN6I_AHB1_MUX_GET_PARENT(reg) == SUN6I_AHB1_MUX_PARENT_PLL6)
parent_rate /= SUN6I_AHB1_PLL6_DIV_GET(reg) + 1;
rate = parent_rate >> SUN6I_AHB1_DIV_GET(reg);
return rate;
}
static long sun6i_ahb1_clk_round(unsigned long rate, u8 *divp, u8 *pre_divp,
u8 parent, unsigned long parent_rate)
{
u8 div, calcp, calcm = 1;
if (parent_rate && rate > parent_rate)
rate = parent_rate;
div = DIV_ROUND_UP(parent_rate, rate);
if (parent == SUN6I_AHB1_MUX_PARENT_PLL6) {
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
if (divp) {
*divp = calcp;
*pre_divp = calcm - 1;
}
return (parent_rate / calcm) >> calcp;
}
static long sun6i_ahb1_clk_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long min_rate,
unsigned long max_rate,
unsigned long *best_parent_rate,
struct clk_hw **best_parent_clk)
{
struct clk *clk = hw->clk, *parent, *best_parent = NULL;
int i, num_parents;
unsigned long parent_rate, best = 0, child_rate, best_child_rate = 0;
num_parents = __clk_get_num_parents(clk);
for (i = 0; i < num_parents; i++) {
parent = clk_get_parent_by_index(clk, i);
if (!parent)
continue;
if (__clk_get_flags(clk) & CLK_SET_RATE_PARENT)
parent_rate = __clk_round_rate(parent, rate);
else
parent_rate = __clk_get_rate(parent);
child_rate = sun6i_ahb1_clk_round(rate, NULL, NULL, i,
parent_rate);
if (child_rate <= rate && child_rate > best_child_rate) {
best_parent = parent;
best = parent_rate;
best_child_rate = child_rate;
}
}
if (best_parent)
*best_parent_clk = __clk_get_hw(best_parent);
*best_parent_rate = best;
return best_child_rate;
}
static int sun6i_ahb1_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct sun6i_ahb1_clk *ahb1 = to_sun6i_ahb1_clk(hw);
unsigned long flags;
u8 div, pre_div, parent;
u32 reg;
spin_lock_irqsave(&clk_lock, flags);
reg = readl(ahb1->reg);
parent = SUN6I_AHB1_MUX_GET_PARENT(reg);
sun6i_ahb1_clk_round(rate, &div, &pre_div, parent, parent_rate);
reg = SUN6I_AHB1_DIV_SET(reg, div);
reg = SUN6I_AHB1_PLL6_DIV_SET(reg, pre_div);
writel(reg, ahb1->reg);
spin_unlock_irqrestore(&clk_lock, flags);
return 0;
}
static void __init sun6i_ahb1_clk_setup(struct device_node *node)
{
struct clk *clk;
struct sun6i_ahb1_clk *ahb1;
struct clk_mux *mux;
const char *clk_name = node->name;
const char *parents[SUN6I_AHB1_MAX_PARENTS];
void __iomem *reg;
int i = 0;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
while (i < SUN6I_AHB1_MAX_PARENTS &&
(parents[i] = of_clk_get_parent_name(node, i)) != NULL)
i++;
of_property_read_string(node, "clock-output-names", &clk_name);
ahb1 = kzalloc(sizeof(struct sun6i_ahb1_clk), GFP_KERNEL);
if (!ahb1)
return;
mux = kzalloc(sizeof(struct clk_mux), GFP_KERNEL);
if (!mux) {
kfree(ahb1);
return;
}
mux->reg = reg;
mux->shift = SUN6I_AHB1_MUX_SHIFT;
mux->mask = SUN6I_AHB1_MUX_MASK;
mux->lock = &clk_lock;
ahb1->reg = reg;
clk = clk_register_composite(NULL, clk_name, parents, i,
&mux->hw, &clk_mux_ops,
&ahb1->hw, &sun6i_ahb1_clk_ops,
NULL, NULL, 0);
if (!IS_ERR(clk)) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
}
static void sun4i_get_pll1_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div;
div = *freq / 6000000;
*freq = 6000000 * div;
if (n == NULL)
return;
*m = 0;
if (*freq >= 768000000 || *freq == 42000000 || *freq == 54000000)
*k = 1;
else
*k = 0;
if (div < 10)
*p = 3;
else if (div < 20 || (div < 32 && (div & 1)))
*p = 2;
else if (div < 40 || (div < 64 && (div & 2)))
*p = 1;
else
*p = 0;
div <<= *p;
div /= (*k + 1);
*n = div / 4;
}
static void sun6i_a31_get_pll1_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u32 freq_mhz = *freq / 1000000;
u32 parent_freq_mhz = parent_rate / 1000000;
u32 round_freq_6 = round_down(freq_mhz, 6);
u32 round_freq_16 = round_down(freq_mhz, 16);
if (round_freq_6 > round_freq_16)
freq_mhz = round_freq_6;
else
freq_mhz = round_freq_16;
*freq = freq_mhz * 1000000;
if (n == NULL)
return;
if (!(freq_mhz % 32))
*k = 3;
else if (!(freq_mhz % 9))
*k = 2;
else if (!(freq_mhz % 8))
*k = 1;
else
*k = 0;
if ((freq_mhz % 6) == 2 || (freq_mhz % 6) == 4)
*m = 2;
else if ((freq_mhz / 6) & 1)
*m = 3;
else
*m = 1;
*n = freq_mhz * (*m + 1) / ((*k + 1) * parent_freq_mhz) - 1;
if ((*n + 1) > 31 && (*m + 1) > 1) {
*n = (*n + 1) / 2 - 1;
*m = (*m + 1) / 2 - 1;
}
}
static void sun8i_a23_get_pll1_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div;
div = *freq / 6000000;
*freq = 6000000 * div;
if (n == NULL)
return;
*m = 0;
if (*freq >= 768000000 || *freq == 42000000 || *freq == 54000000)
*k = 1;
else
*k = 0;
if (div < 20 || (div < 32 && (div & 1)))
*p = 2;
else if (div < 40 || (div < 64 && (div & 2)))
*p = 1;
else
*p = 0;
div <<= *p;
div /= (*k + 1);
*n = div / 4 - 1;
}
static void sun4i_get_pll5_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div;
div = *freq / parent_rate;
*freq = parent_rate * div;
if (n == NULL)
return;
if (div < 31)
*k = 0;
else if (div / 2 < 31)
*k = 1;
else if (div / 3 < 31)
*k = 2;
else
*k = 3;
*n = DIV_ROUND_UP(div, (*k+1));
}
static void sun6i_a31_get_pll6_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div;
div = *freq / parent_rate;
*freq = parent_rate * div;
if (n == NULL)
return;
*k = div / 32;
if (*k > 3)
*k = 3;
*n = DIV_ROUND_UP(div, (*k+1)) - 1;
}
static void sun5i_a13_get_ahb_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u32 div;
if (parent_rate < *freq)
*freq = parent_rate;
if (*freq < 8000)
*freq = 8000;
if (*freq > 300000000)
*freq = 300000000;
div = order_base_2(DIV_ROUND_UP(parent_rate, *freq));
if (div > 3)
div = 3;
*freq = parent_rate >> div;
if (p == NULL)
return;
*p = div;
}
static void sun4i_get_apb1_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 calcm, calcp;
if (parent_rate < *freq)
*freq = parent_rate;
parent_rate = DIV_ROUND_UP(parent_rate, *freq);
if (parent_rate > 32)
return;
if (parent_rate <= 4)
calcp = 0;
else if (parent_rate <= 8)
calcp = 1;
else if (parent_rate <= 16)
calcp = 2;
else
calcp = 3;
calcm = (parent_rate >> calcp) - 1;
*freq = (parent_rate >> calcp) / (calcm + 1);
if (n == NULL)
return;
*m = calcm;
*p = calcp;
}
static void sun7i_a20_get_out_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div, calcm, calcp;
if (*freq > parent_rate)
*freq = parent_rate;
div = DIV_ROUND_UP(parent_rate, *freq);
if (div < 32)
calcp = 0;
else if (div / 2 < 32)
calcp = 1;
else if (div / 4 < 32)
calcp = 2;
else
calcp = 3;
calcm = DIV_ROUND_UP(div, 1 << calcp);
*freq = (parent_rate >> calcp) / calcm;
if (n == NULL)
return;
*m = calcm - 1;
*p = calcp;
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
static void __init sunxi_mux_clk_setup(struct device_node *node,
struct mux_data *data)
{
struct clk *clk;
const char *clk_name = node->name;
const char *parents[SUNXI_MAX_PARENTS];
void __iomem *reg;
int i = 0;
reg = of_iomap(node, 0);
while (i < SUNXI_MAX_PARENTS &&
(parents[i] = of_clk_get_parent_name(node, i)) != NULL)
i++;
of_property_read_string(node, "clock-output-names", &clk_name);
clk = clk_register_mux(NULL, clk_name, parents, i,
CLK_SET_RATE_PARENT, reg,
data->shift, SUNXI_MUX_GATE_WIDTH,
0, &clk_lock);
if (clk) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
}
static void __init sunxi_divider_clk_setup(struct device_node *node,
struct div_data *data)
{
struct clk *clk;
const char *clk_name = node->name;
const char *clk_parent;
void __iomem *reg;
reg = of_iomap(node, 0);
clk_parent = of_clk_get_parent_name(node, 0);
of_property_read_string(node, "clock-output-names", &clk_name);
clk = clk_register_divider_table(NULL, clk_name, clk_parent, 0,
reg, data->shift, data->width,
data->pow ? CLK_DIVIDER_POWER_OF_TWO : 0,
data->table, &clk_lock);
if (clk) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
}
static void __init sunxi_gates_clk_setup(struct device_node *node,
struct gates_data *data)
{
struct clk_onecell_data *clk_data;
const char *clk_parent;
const char *clk_name;
void __iomem *reg;
int qty;
int i = 0;
int j = 0;
reg = of_iomap(node, 0);
clk_parent = of_clk_get_parent_name(node, 0);
qty = find_last_bit(data->mask, SUNXI_GATES_MAX_SIZE);
clk_data = kmalloc(sizeof(struct clk_onecell_data), GFP_KERNEL);
if (!clk_data)
return;
clk_data->clks = kzalloc((qty+1) * sizeof(struct clk *), GFP_KERNEL);
if (!clk_data->clks) {
kfree(clk_data);
return;
}
for_each_set_bit(i, data->mask, SUNXI_GATES_MAX_SIZE) {
of_property_read_string_index(node, "clock-output-names",
j, &clk_name);
clk_data->clks[i] = clk_register_gate(NULL, clk_name,
clk_parent, 0,
reg + 4 * (i/32), i % 32,
0, &clk_lock);
WARN_ON(IS_ERR(clk_data->clks[i]));
clk_register_clkdev(clk_data->clks[i], clk_name, NULL);
j++;
}
clk_data->clk_num = i;
of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
}
static void __init sunxi_divs_clk_setup(struct device_node *node,
struct divs_data *data)
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
void __iomem *reg;
int ndivs = SUNXI_DIVS_MAX_QTY, i = 0;
int flags, clkflags;
if (data->ndivs)
ndivs = data->ndivs;
pclk = sunxi_factors_clk_setup(node, data->factors);
parent = __clk_get_name(pclk);
reg = of_iomap(node, 0);
clk_data = kmalloc(sizeof(struct clk_onecell_data), GFP_KERNEL);
if (!clk_data)
return;
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
clk_register_clkdev(clks[i], clk_name, NULL);
}
clk_data->clk_num = i;
of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
return;
free_gate:
kfree(gate);
free_clks:
kfree(clks);
free_clkdata:
kfree(clk_data);
}
static void __init of_sunxi_table_clock_setup(const struct of_device_id *clk_match,
void *function)
{
struct device_node *np;
const struct div_data *data;
const struct of_device_id *match;
void (*setup_function)(struct device_node *, const void *) = function;
for_each_matching_node_and_match(np, clk_match, &match) {
data = match->data;
setup_function(np, data);
}
}
static void __init sunxi_init_clocks(const char *clocks[], int nclocks)
{
unsigned int i;
of_sunxi_table_clock_setup(clk_divs_match, sunxi_divs_clk_setup);
of_sunxi_table_clock_setup(clk_factors_match, sunxi_factors_clk_setup);
of_sunxi_table_clock_setup(clk_div_match, sunxi_divider_clk_setup);
of_sunxi_table_clock_setup(clk_mux_match, sunxi_mux_clk_setup);
of_sunxi_table_clock_setup(clk_gates_match, sunxi_gates_clk_setup);
for (i = 0; i < nclocks; i++) {
struct clk *clk = clk_get(NULL, clocks[i]);
if (!IS_ERR(clk))
clk_prepare_enable(clk);
}
}
static void __init sun4i_a10_init_clocks(struct device_node *node)
{
sunxi_init_clocks(sun4i_a10_critical_clocks,
ARRAY_SIZE(sun4i_a10_critical_clocks));
}
static void __init sun5i_init_clocks(struct device_node *node)
{
sunxi_init_clocks(sun5i_critical_clocks,
ARRAY_SIZE(sun5i_critical_clocks));
}
static void __init sun6i_init_clocks(struct device_node *node)
{
sunxi_init_clocks(sun6i_critical_clocks,
ARRAY_SIZE(sun6i_critical_clocks));
}
static void __init sun9i_init_clocks(struct device_node *node)
{
sunxi_init_clocks(NULL, 0);
}
