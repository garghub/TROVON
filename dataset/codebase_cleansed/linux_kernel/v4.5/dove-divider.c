static void dove_load_divider(void __iomem *base, u32 val, u32 mask, u32 load)
{
u32 v;
v = readl_relaxed(base + DIV_CTRL1) | DIV_CTRL1_N_RESET_MASK;
writel_relaxed(v, base + DIV_CTRL1);
v = (readl_relaxed(base + DIV_CTRL0) & ~(mask | load)) | val;
writel_relaxed(v, base + DIV_CTRL0);
writel_relaxed(v | load, base + DIV_CTRL0);
ndelay(250);
writel_relaxed(v, base + DIV_CTRL0);
}
static unsigned int dove_get_divider(struct dove_clk *dc)
{
unsigned int divider;
u32 val;
val = readl_relaxed(dc->base + DIV_CTRL0);
val >>= dc->div_bit_start;
divider = val & ~(~0 << dc->div_bit_size);
if (dc->divider_table)
divider = dc->divider_table[divider];
return divider;
}
static int dove_calc_divider(const struct dove_clk *dc, unsigned long rate,
unsigned long parent_rate, bool set)
{
unsigned int divider, max;
divider = DIV_ROUND_CLOSEST(parent_rate, rate);
if (dc->divider_table) {
unsigned int i;
for (i = 0; dc->divider_table[i]; i++)
if (divider == dc->divider_table[i]) {
divider = i;
break;
}
if (!dc->divider_table[i])
return -EINVAL;
} else {
max = 1 << dc->div_bit_size;
if (set && (divider == 0 || divider >= max))
return -EINVAL;
if (divider >= max)
divider = max - 1;
else if (divider == 0)
divider = 1;
}
return divider;
}
static unsigned long dove_recalc_rate(struct clk_hw *hw, unsigned long parent)
{
struct dove_clk *dc = to_dove_clk(hw);
unsigned int divider = dove_get_divider(dc);
unsigned long rate = DIV_ROUND_CLOSEST(parent, divider);
pr_debug("%s(): %s divider=%u parent=%lu rate=%lu\n",
__func__, dc->name, divider, parent, rate);
return rate;
}
static long dove_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent)
{
struct dove_clk *dc = to_dove_clk(hw);
unsigned long parent_rate = *parent;
int divider;
divider = dove_calc_divider(dc, rate, parent_rate, false);
if (divider < 0)
return divider;
rate = DIV_ROUND_CLOSEST(parent_rate, divider);
pr_debug("%s(): %s divider=%u parent=%lu rate=%lu\n",
__func__, dc->name, divider, parent_rate, rate);
return rate;
}
static int dove_set_clock(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct dove_clk *dc = to_dove_clk(hw);
u32 mask, load, div;
int divider;
divider = dove_calc_divider(dc, rate, parent_rate, true);
if (divider < 0)
return divider;
pr_debug("%s(): %s divider=%u parent=%lu rate=%lu\n",
__func__, dc->name, divider, parent_rate, rate);
div = (u32)divider << dc->div_bit_start;
mask = ~(~0 << dc->div_bit_size) << dc->div_bit_start;
load = BIT(dc->div_bit_load);
spin_lock(dc->lock);
dove_load_divider(dc->base, div, mask, load);
spin_unlock(dc->lock);
return 0;
}
static struct clk *clk_register_dove_divider(struct device *dev,
struct dove_clk *dc, const char **parent_names, size_t num_parents,
void __iomem *base)
{
char name[32];
struct clk_init_data init = {
.name = name,
.ops = &dove_divider_ops,
.parent_names = parent_names,
.num_parents = num_parents,
};
strlcpy(name, dc->name, sizeof(name));
dc->hw.init = &init;
dc->base = base;
dc->div_bit_size = dc->div_bit_end - dc->div_bit_start + 1;
return clk_register(dev, &dc->hw);
}
static int dove_divider_init(struct device *dev, void __iomem *base,
struct clk **clks)
{
struct clk *clk;
int i;
clk = clk_register_fixed_rate(dev, core_pll[0], NULL, CLK_IS_ROOT,
2000000000UL);
if (IS_ERR(clk))
return PTR_ERR(clk);
for (i = 0; i < ARRAY_SIZE(dove_hw_clocks); i++)
clks[i] = clk_register_dove_divider(dev, &dove_hw_clocks[i],
core_pll,
ARRAY_SIZE(core_pll), base);
return 0;
}
void __init dove_divider_clk_init(struct device_node *np)
{
void __iomem *base;
base = of_iomap(np, 0);
if (WARN_ON(!base))
return;
if (WARN_ON(dove_divider_init(NULL, base, dove_divider_clocks))) {
iounmap(base);
return;
}
of_clk_add_provider(np, of_clk_src_onecell_get, &dove_divider_data);
}
