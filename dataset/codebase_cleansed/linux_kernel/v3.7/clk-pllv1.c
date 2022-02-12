static unsigned long clk_pllv1_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv1 *pll = to_clk_pllv1(hw);
long long ll;
int mfn_abs;
unsigned int mfi, mfn, mfd, pd;
u32 reg;
unsigned long rate;
reg = readl(pll->base);
mfi = (reg >> 10) & 0xf;
mfn = reg & 0x3ff;
mfd = (reg >> 16) & 0x3ff;
pd = (reg >> 26) & 0xf;
mfi = mfi <= 5 ? 5 : mfi;
mfn_abs = mfn;
if (!cpu_is_mx1() && !cpu_is_mx21() && mfn >= 0x200)
mfn_abs = 0x400 - mfn;
rate = parent_rate * 2;
rate /= pd + 1;
ll = (unsigned long long)rate * mfn_abs;
do_div(ll, mfd + 1);
if (!cpu_is_mx1() && !cpu_is_mx21() && mfn >= 0x200)
ll = -ll;
ll = (rate * mfi) + ll;
return ll;
}
struct clk *imx_clk_pllv1(const char *name, const char *parent,
void __iomem *base)
{
struct clk_pllv1 *pll;
struct clk *clk;
struct clk_init_data init;
pll = kmalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
pll->base = base;
init.name = name;
init.ops = &clk_pllv1_ops;
init.flags = 0;
init.parent_names = &parent;
init.num_parents = 1;
pll->hw.init = &init;
clk = clk_register(NULL, &pll->hw);
if (IS_ERR(clk))
kfree(pll);
return clk;
}
