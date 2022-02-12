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
parent_rate = parent_rate / 2;
div = *freq / parent_rate;
*freq = parent_rate * div;
if (n == NULL)
return;
*k = div / 32;
if (*k > 3)
*k = 3;
*n = DIV_ROUND_UP(div, (*k+1));
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
static void sun4i_get_mod0_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div, calcm, calcp;
if (*freq > parent_rate)
*freq = parent_rate;
div = DIV_ROUND_UP(parent_rate, *freq);
if (div < 16)
calcp = 0;
else if (div / 2 < 16)
calcp = 1;
else if (div / 4 < 16)
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
void clk_sunxi_mmc_phase_control(struct clk *clk, u8 sample, u8 output)
{
#define to_clk_composite(_hw) container_of(_hw, struct clk_composite, hw)
#define to_clk_factors(_hw) container_of(_hw, struct clk_factors, hw)
struct clk_hw *hw = __clk_get_hw(clk);
struct clk_composite *composite = to_clk_composite(hw);
struct clk_hw *rate_hw = composite->rate_hw;
struct clk_factors *factors = to_clk_factors(rate_hw);
unsigned long flags = 0;
u32 reg;
if (factors->lock)
spin_lock_irqsave(factors->lock, flags);
reg = readl(factors->reg);
reg &= ~(0x7 << 20);
reg |= ((sample & 0x7) << 20);
reg &= ~(0x7 << 8);
reg |= ((output & 0x7) << 8);
writel(reg, factors->reg);
if (factors->lock)
spin_unlock_irqrestore(factors->lock, flags);
}
static struct clk * __init sunxi_factors_clk_setup(struct device_node *node,
const struct factors_data *data)
{
struct clk *clk;
struct clk_factors *factors;
struct clk_gate *gate = NULL;
struct clk_mux *mux = NULL;
struct clk_hw *gate_hw = NULL;
struct clk_hw *mux_hw = NULL;
const char *clk_name = node->name;
const char *parents[SUNXI_MAX_PARENTS];
void *reg;
int i = 0;
reg = of_iomap(node, 0);
while (i < SUNXI_MAX_PARENTS &&
(parents[i] = of_clk_get_parent_name(node, i)) != NULL)
i++;
if (data->name)
clk_name = data->name;
else
of_property_read_string(node, "clock-output-names", &clk_name);
factors = kzalloc(sizeof(struct clk_factors), GFP_KERNEL);
if (!factors)
return NULL;
if (data->enable) {
gate = kzalloc(sizeof(struct clk_gate), GFP_KERNEL);
if (!gate) {
kfree(factors);
return NULL;
}
gate->reg = reg;
gate->bit_idx = data->enable;
gate->lock = &clk_lock;
gate_hw = &gate->hw;
}
if (data->mux) {
mux = kzalloc(sizeof(struct clk_mux), GFP_KERNEL);
if (!mux) {
kfree(factors);
kfree(gate);
return NULL;
}
mux->reg = reg;
mux->shift = data->mux;
mux->mask = SUNXI_FACTORS_MUX_MASK;
mux->lock = &clk_lock;
mux_hw = &mux->hw;
}
factors->reg = reg;
factors->config = data->table;
factors->get_factors = data->getter;
factors->lock = &clk_lock;
clk = clk_register_composite(NULL, clk_name,
parents, i,
mux_hw, &clk_mux_ops,
&factors->hw, &clk_factors_ops,
gate_hw, &clk_gate_ops, 0);
if (!IS_ERR(clk)) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
return clk;
}
static void __init sunxi_mux_clk_setup(struct device_node *node,
struct mux_data *data)
{
struct clk *clk;
const char *clk_name = node->name;
const char *parents[SUNXI_MAX_PARENTS];
void *reg;
int i = 0;
reg = of_iomap(node, 0);
while (i < SUNXI_MAX_PARENTS &&
(parents[i] = of_clk_get_parent_name(node, i)) != NULL)
i++;
of_property_read_string(node, "clock-output-names", &clk_name);
clk = clk_register_mux(NULL, clk_name, parents, i,
CLK_SET_RATE_NO_REPARENT, reg,
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
of_property_read_string(node, "clock-output-names", &clk_name);
clk = clk_register_divider(NULL, clk_name, clk_parent, 0,
reg, data->shift, data->width,
data->pow ? CLK_DIVIDER_POWER_OF_TWO : 0,
&clk_lock);
if (clk) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
}
static int sunxi_gates_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gates_reset_data *data = container_of(rcdev,
struct gates_reset_data,
rcdev);
unsigned long flags;
u32 reg;
spin_lock_irqsave(data->lock, flags);
reg = readl(data->reg);
writel(reg & ~BIT(id), data->reg);
spin_unlock_irqrestore(data->lock, flags);
return 0;
}
static int sunxi_gates_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gates_reset_data *data = container_of(rcdev,
struct gates_reset_data,
rcdev);
unsigned long flags;
u32 reg;
spin_lock_irqsave(data->lock, flags);
reg = readl(data->reg);
writel(reg | BIT(id), data->reg);
spin_unlock_irqrestore(data->lock, flags);
return 0;
}
static void __init sunxi_gates_clk_setup(struct device_node *node,
struct gates_data *data)
{
struct clk_onecell_data *clk_data;
struct gates_reset_data *reset_data;
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
if (data->reset_mask == 0)
return;
reset_data = kzalloc(sizeof(*reset_data), GFP_KERNEL);
if (!reset_data)
return;
reset_data->reg = reg;
reset_data->lock = &clk_lock;
reset_data->rcdev.nr_resets = __fls(data->reset_mask) + 1;
reset_data->rcdev.ops = &sunxi_gates_reset_ops;
reset_data->rcdev.of_node = node;
reset_controller_register(&reset_data->rcdev);
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
void *reg;
int i = 0;
int flags, clkflags;
pclk = sunxi_factors_clk_setup(node, data->factors);
parent = __clk_get_name(pclk);
reg = of_iomap(node, 0);
clk_data = kmalloc(sizeof(struct clk_onecell_data), GFP_KERNEL);
if (!clk_data)
return;
clks = kzalloc((SUNXI_DIVS_MAX_QTY+1) * sizeof(*clks), GFP_KERNEL);
if (!clks)
goto free_clkdata;
clk_data->clks = clks;
clkflags = !strcmp("pll5", parent) ? 0 : CLK_SET_RATE_PARENT;
for (i = 0; i < SUNXI_DIVS_MAX_QTY; i++) {
if (of_property_read_string_index(node, "clock-output-names",
i, &clk_name) != 0)
break;
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
clks[i++] = pclk;
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
of_sunxi_table_clock_setup(clk_factors_match, sunxi_factors_clk_setup);
of_sunxi_table_clock_setup(clk_div_match, sunxi_divider_clk_setup);
of_sunxi_table_clock_setup(clk_divs_match, sunxi_divs_clk_setup);
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
