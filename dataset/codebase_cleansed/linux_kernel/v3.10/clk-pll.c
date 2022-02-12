static int clk_pll_prepare(struct clk_hw *hw)
{
struct clk_pll *pll = to_clk_pll(hw);
writel_relaxed(1 << pll->power, pll->base + SET);
udelay(10);
return 0;
}
static void clk_pll_unprepare(struct clk_hw *hw)
{
struct clk_pll *pll = to_clk_pll(hw);
writel_relaxed(1 << pll->power, pll->base + CLR);
}
static int clk_pll_enable(struct clk_hw *hw)
{
struct clk_pll *pll = to_clk_pll(hw);
writel_relaxed(1 << 31, pll->base + CLR);
return 0;
}
static void clk_pll_disable(struct clk_hw *hw)
{
struct clk_pll *pll = to_clk_pll(hw);
writel_relaxed(1 << 31, pll->base + SET);
}
static unsigned long clk_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pll *pll = to_clk_pll(hw);
return pll->rate;
}
struct clk *mxs_clk_pll(const char *name, const char *parent_name,
void __iomem *base, u8 power, unsigned long rate)
{
struct clk_pll *pll;
struct clk *clk;
struct clk_init_data init;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &clk_pll_ops;
init.flags = 0;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
pll->base = base;
pll->rate = rate;
pll->power = power;
pll->hw.init = &init;
clk = clk_register(NULL, &pll->hw);
if (IS_ERR(clk))
kfree(pll);
return clk;
}
