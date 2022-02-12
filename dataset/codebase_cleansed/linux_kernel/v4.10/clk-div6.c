static int cpg_div6_clock_enable(struct clk_hw *hw)
{
struct div6_clock *clock = to_div6_clock(hw);
u32 val;
val = (clk_readl(clock->reg) & ~(CPG_DIV6_DIV_MASK | CPG_DIV6_CKSTP))
| CPG_DIV6_DIV(clock->div - 1);
clk_writel(val, clock->reg);
return 0;
}
static void cpg_div6_clock_disable(struct clk_hw *hw)
{
struct div6_clock *clock = to_div6_clock(hw);
u32 val;
val = clk_readl(clock->reg);
val |= CPG_DIV6_CKSTP;
if (!(val & CPG_DIV6_DIV_MASK))
val |= CPG_DIV6_DIV_MASK;
clk_writel(val, clock->reg);
}
static int cpg_div6_clock_is_enabled(struct clk_hw *hw)
{
struct div6_clock *clock = to_div6_clock(hw);
return !(clk_readl(clock->reg) & CPG_DIV6_CKSTP);
}
static unsigned long cpg_div6_clock_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct div6_clock *clock = to_div6_clock(hw);
return parent_rate / clock->div;
}
static unsigned int cpg_div6_clock_calc_div(unsigned long rate,
unsigned long parent_rate)
{
unsigned int div;
if (!rate)
rate = 1;
div = DIV_ROUND_CLOSEST(parent_rate, rate);
return clamp_t(unsigned int, div, 1, 64);
}
static long cpg_div6_clock_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned int div = cpg_div6_clock_calc_div(rate, *parent_rate);
return *parent_rate / div;
}
static int cpg_div6_clock_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct div6_clock *clock = to_div6_clock(hw);
unsigned int div = cpg_div6_clock_calc_div(rate, parent_rate);
u32 val;
clock->div = div;
val = clk_readl(clock->reg) & ~CPG_DIV6_DIV_MASK;
if (!(val & CPG_DIV6_CKSTP))
clk_writel(val | CPG_DIV6_DIV(clock->div - 1), clock->reg);
return 0;
}
static u8 cpg_div6_clock_get_parent(struct clk_hw *hw)
{
struct div6_clock *clock = to_div6_clock(hw);
unsigned int i;
u8 hw_index;
if (clock->src_width == 0)
return 0;
hw_index = (clk_readl(clock->reg) >> clock->src_shift) &
(BIT(clock->src_width) - 1);
for (i = 0; i < clk_hw_get_num_parents(hw); i++) {
if (clock->parents[i] == hw_index)
return i;
}
pr_err("%s: %s DIV6 clock set to invalid parent %u\n",
__func__, clk_hw_get_name(hw), hw_index);
return 0;
}
static int cpg_div6_clock_set_parent(struct clk_hw *hw, u8 index)
{
struct div6_clock *clock = to_div6_clock(hw);
u8 hw_index;
u32 mask;
if (index >= clk_hw_get_num_parents(hw))
return -EINVAL;
mask = ~((BIT(clock->src_width) - 1) << clock->src_shift);
hw_index = clock->parents[index];
clk_writel((clk_readl(clock->reg) & mask) |
(hw_index << clock->src_shift), clock->reg);
return 0;
}
struct clk * __init cpg_div6_register(const char *name,
unsigned int num_parents,
const char **parent_names,
void __iomem *reg)
{
unsigned int valid_parents;
struct clk_init_data init;
struct div6_clock *clock;
struct clk *clk;
unsigned int i;
clock = kzalloc(sizeof(*clock), GFP_KERNEL);
if (!clock)
return ERR_PTR(-ENOMEM);
clock->parents = kmalloc_array(num_parents, sizeof(*clock->parents),
GFP_KERNEL);
if (!clock->parents) {
clk = ERR_PTR(-ENOMEM);
goto free_clock;
}
clock->reg = reg;
clock->div = (clk_readl(clock->reg) & CPG_DIV6_DIV_MASK) + 1;
switch (num_parents) {
case 1:
clock->src_shift = clock->src_width = 0;
break;
case 4:
clock->src_shift = 6;
clock->src_width = 2;
break;
case 8:
clock->src_shift = 12;
clock->src_width = 3;
break;
default:
pr_err("%s: invalid number of parents for DIV6 clock %s\n",
__func__, name);
clk = ERR_PTR(-EINVAL);
goto free_parents;
}
for (i = 0, valid_parents = 0; i < num_parents; i++) {
if (parent_names[i]) {
parent_names[valid_parents] = parent_names[i];
clock->parents[valid_parents] = i;
valid_parents++;
}
}
init.name = name;
init.ops = &cpg_div6_clock_ops;
init.flags = CLK_IS_BASIC;
init.parent_names = parent_names;
init.num_parents = valid_parents;
clock->hw.init = &init;
clk = clk_register(NULL, &clock->hw);
if (IS_ERR(clk))
goto free_parents;
return clk;
free_parents:
kfree(clock->parents);
free_clock:
kfree(clock);
return clk;
}
static void __init cpg_div6_clock_init(struct device_node *np)
{
unsigned int num_parents;
const char **parent_names;
const char *clk_name = np->name;
void __iomem *reg;
struct clk *clk;
unsigned int i;
num_parents = of_clk_get_parent_count(np);
if (num_parents < 1) {
pr_err("%s: no parent found for %s DIV6 clock\n",
__func__, np->name);
return;
}
parent_names = kmalloc_array(num_parents, sizeof(*parent_names),
GFP_KERNEL);
if (!parent_names)
return;
reg = of_iomap(np, 0);
if (reg == NULL) {
pr_err("%s: failed to map %s DIV6 clock register\n",
__func__, np->name);
goto error;
}
of_property_read_string(np, "clock-output-names", &clk_name);
for (i = 0; i < num_parents; i++)
parent_names[i] = of_clk_get_parent_name(np, i);
clk = cpg_div6_register(clk_name, num_parents, parent_names, reg);
if (IS_ERR(clk)) {
pr_err("%s: failed to register %s DIV6 clock (%ld)\n",
__func__, np->name, PTR_ERR(clk));
goto error;
}
of_clk_add_provider(np, of_clk_src_simple_get, clk);
kfree(parent_names);
return;
error:
if (reg)
iounmap(reg);
kfree(parent_names);
}
