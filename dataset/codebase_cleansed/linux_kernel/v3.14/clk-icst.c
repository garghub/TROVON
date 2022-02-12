static struct icst_vco vco_get(void __iomem *vcoreg)
{
u32 val;
struct icst_vco vco;
val = readl(vcoreg);
vco.v = val & 0x1ff;
vco.r = (val >> 9) & 0x7f;
vco.s = (val >> 16) & 03;
return vco;
}
static void vco_set(void __iomem *lockreg,
void __iomem *vcoreg,
struct icst_vco vco)
{
u32 val;
val = readl(vcoreg) & ~0x7ffff;
val |= vco.v | (vco.r << 9) | (vco.s << 16);
writel(0xa05f, lockreg);
writel(val, vcoreg);
writel(0, lockreg);
}
static unsigned long icst_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_icst *icst = to_icst(hw);
struct icst_vco vco;
vco = vco_get(icst->vcoreg);
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
vco_set(icst->lockreg, icst->vcoreg, vco);
return 0;
}
struct clk *icst_clk_register(struct device *dev,
const struct clk_icst_desc *desc,
const char *name,
void __iomem *base)
{
struct clk *clk;
struct clk_icst *icst;
struct clk_init_data init;
icst = kzalloc(sizeof(struct clk_icst), GFP_KERNEL);
if (!icst) {
pr_err("could not allocate ICST clock!\n");
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &icst_ops;
init.flags = CLK_IS_ROOT;
init.parent_names = NULL;
init.num_parents = 0;
icst->hw.init = &init;
icst->params = desc->params;
icst->vcoreg = base + desc->vco_offset;
icst->lockreg = base + desc->lock_offset;
clk = clk_register(dev, &icst->hw);
if (IS_ERR(clk))
kfree(icst);
return clk;
}
