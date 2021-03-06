static unsigned long clk_sama5d4_h32mx_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_sama5d4_h32mx *h32mxclk = to_clk_sama5d4_h32mx(hw);
unsigned int mckr;
regmap_read(h32mxclk->regmap, AT91_PMC_MCKR, &mckr);
if (mckr & AT91_PMC_H32MXDIV)
return parent_rate / 2;
if (parent_rate > H32MX_MAX_FREQ)
pr_warn("H32MX clock is too fast\n");
return parent_rate;
}
static long clk_sama5d4_h32mx_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long div;
if (rate > *parent_rate)
return *parent_rate;
div = *parent_rate / 2;
if (rate < div)
return div;
if (rate - div < *parent_rate - rate)
return div;
return *parent_rate;
}
static int clk_sama5d4_h32mx_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_sama5d4_h32mx *h32mxclk = to_clk_sama5d4_h32mx(hw);
u32 mckr = 0;
if (parent_rate != rate && (parent_rate / 2) != rate)
return -EINVAL;
if ((parent_rate / 2) == rate)
mckr = AT91_PMC_H32MXDIV;
regmap_update_bits(h32mxclk->regmap, AT91_PMC_MCKR,
AT91_PMC_H32MXDIV, mckr);
return 0;
}
static void __init of_sama5d4_clk_h32mx_setup(struct device_node *np)
{
struct clk_sama5d4_h32mx *h32mxclk;
struct clk_init_data init;
const char *parent_name;
struct regmap *regmap;
struct clk *clk;
regmap = syscon_node_to_regmap(of_get_parent(np));
if (IS_ERR(regmap))
return;
h32mxclk = kzalloc(sizeof(*h32mxclk), GFP_KERNEL);
if (!h32mxclk)
return;
parent_name = of_clk_get_parent_name(np, 0);
init.name = np->name;
init.ops = &h32mx_ops;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
init.flags = CLK_SET_RATE_GATE;
h32mxclk->hw.init = &init;
h32mxclk->regmap = regmap;
clk = clk_register(NULL, &h32mxclk->hw);
if (IS_ERR(clk)) {
kfree(h32mxclk);
return;
}
of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
