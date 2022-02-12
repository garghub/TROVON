static int iproc_asiu_clk_enable(struct clk_hw *hw)
{
struct iproc_asiu_clk *clk = to_asiu_clk(hw);
struct iproc_asiu *asiu = clk->asiu;
u32 val;
if (clk->gate.offset == IPROC_CLK_INVALID_OFFSET)
return 0;
val = readl(asiu->gate_base + clk->gate.offset);
val |= (1 << clk->gate.en_shift);
writel(val, asiu->gate_base + clk->gate.offset);
return 0;
}
static void iproc_asiu_clk_disable(struct clk_hw *hw)
{
struct iproc_asiu_clk *clk = to_asiu_clk(hw);
struct iproc_asiu *asiu = clk->asiu;
u32 val;
if (clk->gate.offset == IPROC_CLK_INVALID_OFFSET)
return;
val = readl(asiu->gate_base + clk->gate.offset);
val &= ~(1 << clk->gate.en_shift);
writel(val, asiu->gate_base + clk->gate.offset);
}
static unsigned long iproc_asiu_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct iproc_asiu_clk *clk = to_asiu_clk(hw);
struct iproc_asiu *asiu = clk->asiu;
u32 val;
unsigned int div_h, div_l;
if (parent_rate == 0) {
clk->rate = 0;
return 0;
}
val = readl(asiu->div_base + clk->div.offset);
if ((val & (1 << clk->div.en_shift)) == 0) {
clk->rate = parent_rate;
return parent_rate;
}
div_h = (val >> clk->div.high_shift) & bit_mask(clk->div.high_width);
div_h++;
div_l = (val >> clk->div.low_shift) & bit_mask(clk->div.low_width);
div_l++;
clk->rate = parent_rate / (div_h + div_l);
pr_debug("%s: rate: %lu. parent rate: %lu div_h: %u div_l: %u\n",
__func__, clk->rate, parent_rate, div_h, div_l);
return clk->rate;
}
static long iproc_asiu_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned int div;
if (rate == 0 || *parent_rate == 0)
return -EINVAL;
if (rate == *parent_rate)
return *parent_rate;
div = DIV_ROUND_UP(*parent_rate, rate);
if (div < 2)
return *parent_rate;
return *parent_rate / div;
}
static int iproc_asiu_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct iproc_asiu_clk *clk = to_asiu_clk(hw);
struct iproc_asiu *asiu = clk->asiu;
unsigned int div, div_h, div_l;
u32 val;
if (rate == 0 || parent_rate == 0)
return -EINVAL;
if (rate == parent_rate) {
val = readl(asiu->div_base + clk->div.offset);
val &= ~(1 << clk->div.en_shift);
writel(val, asiu->div_base + clk->div.offset);
return 0;
}
div = DIV_ROUND_UP(parent_rate, rate);
if (div < 2)
return -EINVAL;
div_h = div_l = div >> 1;
div_h--;
div_l--;
val = readl(asiu->div_base + clk->div.offset);
val |= 1 << clk->div.en_shift;
if (div_h) {
val &= ~(bit_mask(clk->div.high_width)
<< clk->div.high_shift);
val |= div_h << clk->div.high_shift;
} else {
val &= ~(bit_mask(clk->div.high_width)
<< clk->div.high_shift);
}
if (div_l) {
val &= ~(bit_mask(clk->div.low_width) << clk->div.low_shift);
val |= div_l << clk->div.low_shift;
} else {
val &= ~(bit_mask(clk->div.low_width) << clk->div.low_shift);
}
writel(val, asiu->div_base + clk->div.offset);
return 0;
}
void __init iproc_asiu_setup(struct device_node *node,
const struct iproc_asiu_div *div,
const struct iproc_asiu_gate *gate,
unsigned int num_clks)
{
int i, ret;
struct iproc_asiu *asiu;
if (WARN_ON(!gate || !div))
return;
asiu = kzalloc(sizeof(*asiu), GFP_KERNEL);
if (WARN_ON(!asiu))
return;
asiu->clk_data.clk_num = num_clks;
asiu->clk_data.clks = kcalloc(num_clks, sizeof(*asiu->clk_data.clks),
GFP_KERNEL);
if (WARN_ON(!asiu->clk_data.clks))
goto err_clks;
asiu->clks = kcalloc(num_clks, sizeof(*asiu->clks), GFP_KERNEL);
if (WARN_ON(!asiu->clks))
goto err_asiu_clks;
asiu->div_base = of_iomap(node, 0);
if (WARN_ON(!asiu->div_base))
goto err_iomap_div;
asiu->gate_base = of_iomap(node, 1);
if (WARN_ON(!asiu->gate_base))
goto err_iomap_gate;
for (i = 0; i < num_clks; i++) {
struct clk_init_data init;
struct clk *clk;
const char *parent_name;
struct iproc_asiu_clk *asiu_clk;
const char *clk_name;
ret = of_property_read_string_index(node, "clock-output-names",
i, &clk_name);
if (WARN_ON(ret))
goto err_clk_register;
asiu_clk = &asiu->clks[i];
asiu_clk->name = clk_name;
asiu_clk->asiu = asiu;
asiu_clk->div = div[i];
asiu_clk->gate = gate[i];
init.name = clk_name;
init.ops = &iproc_asiu_ops;
init.flags = 0;
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
asiu_clk->hw.init = &init;
clk = clk_register(NULL, &asiu_clk->hw);
if (WARN_ON(IS_ERR(clk)))
goto err_clk_register;
asiu->clk_data.clks[i] = clk;
}
ret = of_clk_add_provider(node, of_clk_src_onecell_get,
&asiu->clk_data);
if (WARN_ON(ret))
goto err_clk_register;
return;
err_clk_register:
for (i = 0; i < num_clks; i++)
clk_unregister(asiu->clk_data.clks[i]);
iounmap(asiu->gate_base);
err_iomap_gate:
iounmap(asiu->div_base);
err_iomap_div:
kfree(asiu->clks);
err_asiu_clks:
kfree(asiu->clk_data.clks);
err_clks:
kfree(asiu);
}
