static void __init sunxi_osc_clk_setup(struct device_node *node)
{
struct clk *clk;
struct clk_fixed_rate *fixed;
struct clk_gate *gate;
const char *clk_name = node->name;
u32 rate;
fixed = kzalloc(sizeof(struct clk_fixed_rate), GFP_KERNEL);
if (!fixed)
return;
gate = kzalloc(sizeof(struct clk_gate), GFP_KERNEL);
if (!gate) {
kfree(fixed);
return;
}
if (of_property_read_u32(node, "clock-frequency", &rate))
return;
gate->reg = of_iomap(node, 0);
gate->bit_idx = SUNXI_OSC24M_GATE;
gate->lock = &clk_lock;
fixed->fixed_rate = rate;
clk = clk_register_composite(NULL, clk_name,
NULL, 0,
NULL, NULL,
&fixed->hw, &clk_fixed_rate_ops,
&gate->hw, &clk_gate_ops,
CLK_IS_ROOT);
if (clk) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
}
static void sunxi_get_pll1_factors(u32 *freq, u32 parent_rate,
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
static void sunxi_get_apb1_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 calcm, calcp;
if (parent_rate < *freq)
*freq = parent_rate;
parent_rate = (parent_rate + (*freq - 1)) / *freq;
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
static void __init sunxi_factors_clk_setup(struct device_node *node,
struct factors_data *data)
{
struct clk *clk;
const char *clk_name = node->name;
const char *parent;
void *reg;
reg = of_iomap(node, 0);
parent = of_clk_get_parent_name(node, 0);
clk = clk_register_factors(NULL, clk_name, parent, 0, reg,
data->table, data->getter, &clk_lock);
if (clk) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
}
static void __init sunxi_mux_clk_setup(struct device_node *node,
struct mux_data *data)
{
struct clk *clk;
const char *clk_name = node->name;
const char *parents[5];
void *reg;
int i = 0;
reg = of_iomap(node, 0);
while (i < 5 && (parents[i] = of_clk_get_parent_name(node, i)) != NULL)
i++;
clk = clk_register_mux(NULL, clk_name, parents, i, 0, reg,
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
void *reg;
reg = of_iomap(node, 0);
clk_parent = of_clk_get_parent_name(node, 0);
clk = clk_register_divider(NULL, clk_name, clk_parent, 0,
reg, data->shift, SUNXI_DIVISOR_WIDTH,
data->pow ? CLK_DIVIDER_POWER_OF_TWO : 0,
&clk_lock);
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
void *reg;
int qty;
int i = 0;
int j = 0;
int ignore;
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
ignore = !strcmp("ahb_sdram", clk_name) ? CLK_IGNORE_UNUSED : 0;
clk_data->clks[i] = clk_register_gate(NULL, clk_name,
clk_parent, ignore,
reg + 4 * (i/32), i % 32,
0, &clk_lock);
WARN_ON(IS_ERR(clk_data->clks[i]));
j++;
}
clk_data->clk_num = i;
of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
}
static void __init of_sunxi_table_clock_setup(const struct of_device_id *clk_match,
void *function)
{
struct device_node *np;
const struct div_data *data;
const struct of_device_id *match;
void (*setup_function)(struct device_node *, const void *) = function;
for_each_matching_node(np, clk_match) {
match = of_match_node(clk_match, np);
data = match->data;
setup_function(np, data);
}
}
void __init sunxi_init_clocks(void)
{
of_clk_init(clk_match);
of_sunxi_table_clock_setup(clk_factors_match, sunxi_factors_clk_setup);
of_sunxi_table_clock_setup(clk_div_match, sunxi_divider_clk_setup);
of_sunxi_table_clock_setup(clk_mux_match, sunxi_mux_clk_setup);
of_sunxi_table_clock_setup(clk_gates_match, sunxi_gates_clk_setup);
}
