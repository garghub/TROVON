static unsigned long icst_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_icst *icst = to_icst(hw);
struct icst_vco vco;
vco = icst->getvco();
icst->rate = icst_hz(icst->params, vco);
return icst->rate;
}
static long icst_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_icst *icst = to_icst(hw);
struct icst_vco vco;
vco = icst_hz_to_vco(icst->params, rate);
return icst_hz(icst->params, vco);
}
static int icst_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_icst *icst = to_icst(hw);
struct icst_vco vco;
vco = icst_hz_to_vco(icst->params, rate);
icst->rate = icst_hz(icst->params, vco);
icst->setvco(vco);
return 0;
}
struct clk * __init icst_clk_register(struct device *dev,
const struct clk_icst_desc *desc)
{
struct clk *clk;
struct clk_icst *icst;
struct clk_init_data init;
icst = kzalloc(sizeof(struct clk_icst), GFP_KERNEL);
if (!icst) {
pr_err("could not allocate ICST clock!\n");
return ERR_PTR(-ENOMEM);
}
init.name = "icst";
init.ops = &icst_ops;
init.flags = CLK_IS_ROOT;
init.parent_names = NULL;
init.num_parents = 0;
icst->hw.init = &init;
icst->params = desc->params;
icst->getvco = desc->getvco;
icst->setvco = desc->setvco;
clk = clk_register(dev, &icst->hw);
if (IS_ERR(clk))
kfree(icst);
return clk;
}
