static inline struct ar100_clk *to_ar100_clk(struct clk_hw *hw)
{
return container_of(hw, struct ar100_clk, hw);
}
static unsigned long ar100_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ar100_clk *clk = to_ar100_clk(hw);
u32 val = readl(clk->reg);
int shift = (val >> SUN6I_AR100_SHIFT_SHIFT) & SUN6I_AR100_SHIFT_MASK;
int div = (val >> SUN6I_AR100_DIV_SHIFT) & SUN6I_AR100_DIV_MASK;
return (parent_rate >> shift) / (div + 1);
}
static long ar100_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *best_parent_rate,
struct clk_hw **best_parent_clk)
{
int nparents = __clk_get_num_parents(hw->clk);
long best_rate = -EINVAL;
int i;
*best_parent_clk = NULL;
for (i = 0; i < nparents; i++) {
unsigned long parent_rate;
unsigned long tmp_rate;
struct clk *parent;
unsigned long div;
int shift;
parent = clk_get_parent_by_index(hw->clk, i);
parent_rate = __clk_get_rate(parent);
div = DIV_ROUND_UP(parent_rate, rate);
shift = ffs(div) - 1;
if (shift > SUN6I_AR100_SHIFT_MAX)
shift = SUN6I_AR100_SHIFT_MAX;
div >>= shift;
while (div > SUN6I_AR100_DIV_MAX) {
shift++;
div >>= 1;
if (shift > SUN6I_AR100_SHIFT_MAX)
break;
}
if (shift > SUN6I_AR100_SHIFT_MAX)
continue;
tmp_rate = (parent_rate >> shift) / div;
if (!*best_parent_clk || tmp_rate > best_rate) {
*best_parent_clk = __clk_get_hw(parent);
*best_parent_rate = parent_rate;
best_rate = tmp_rate;
}
}
return best_rate;
}
static int ar100_set_parent(struct clk_hw *hw, u8 index)
{
struct ar100_clk *clk = to_ar100_clk(hw);
u32 val = readl(clk->reg);
if (index >= SUN6I_AR100_MAX_PARENTS)
return -EINVAL;
val &= ~(SUN6I_AR100_MUX_MASK << SUN6I_AR100_MUX_SHIFT);
val |= (index << SUN6I_AR100_MUX_SHIFT);
writel(val, clk->reg);
return 0;
}
static u8 ar100_get_parent(struct clk_hw *hw)
{
struct ar100_clk *clk = to_ar100_clk(hw);
return (readl(clk->reg) >> SUN6I_AR100_MUX_SHIFT) &
SUN6I_AR100_MUX_MASK;
}
static int ar100_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
unsigned long div = parent_rate / rate;
struct ar100_clk *clk = to_ar100_clk(hw);
u32 val = readl(clk->reg);
int shift;
if (parent_rate % rate)
return -EINVAL;
shift = ffs(div) - 1;
if (shift > SUN6I_AR100_SHIFT_MAX)
shift = SUN6I_AR100_SHIFT_MAX;
div >>= shift;
if (div > SUN6I_AR100_DIV_MAX)
return -EINVAL;
val &= ~((SUN6I_AR100_SHIFT_MASK << SUN6I_AR100_SHIFT_SHIFT) |
(SUN6I_AR100_DIV_MASK << SUN6I_AR100_DIV_SHIFT));
val |= (shift << SUN6I_AR100_SHIFT_SHIFT) |
(div << SUN6I_AR100_DIV_SHIFT);
writel(val, clk->reg);
return 0;
}
static int sun6i_a31_ar100_clk_probe(struct platform_device *pdev)
{
const char *parents[SUN6I_AR100_MAX_PARENTS];
struct device_node *np = pdev->dev.of_node;
const char *clk_name = np->name;
struct clk_init_data init;
struct ar100_clk *ar100;
struct resource *r;
struct clk *clk;
int nparents;
int i;
ar100 = devm_kzalloc(&pdev->dev, sizeof(*ar100), GFP_KERNEL);
if (!ar100)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ar100->reg = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(ar100->reg))
return PTR_ERR(ar100->reg);
nparents = of_clk_get_parent_count(np);
if (nparents > SUN6I_AR100_MAX_PARENTS)
nparents = SUN6I_AR100_MAX_PARENTS;
for (i = 0; i < nparents; i++)
parents[i] = of_clk_get_parent_name(np, i);
of_property_read_string(np, "clock-output-names", &clk_name);
init.name = clk_name;
init.ops = &ar100_ops;
init.parent_names = parents;
init.num_parents = nparents;
init.flags = 0;
ar100->hw.init = &init;
clk = clk_register(&pdev->dev, &ar100->hw);
if (IS_ERR(clk))
return PTR_ERR(clk);
return of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
