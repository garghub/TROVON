static inline bool is_imx1_pllv1(struct clk_pllv1 *pll)
{
return pll->type == IMX_PLLV1_IMX1;
}
static inline bool is_imx21_pllv1(struct clk_pllv1 *pll)
{
return pll->type == IMX_PLLV1_IMX21;
}
static inline bool is_imx27_pllv1(struct clk_pllv1 *pll)
{
return pll->type == IMX_PLLV1_IMX27;
}
static inline bool mfn_is_negative(struct clk_pllv1 *pll, unsigned int mfn)
{
return !is_imx1_pllv1(pll) && !is_imx21_pllv1(pll) && (mfn & MFN_SIGN);
}
static unsigned long clk_pllv1_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv1 *pll = to_clk_pllv1(hw);
unsigned long long ull;
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
if (mfn_is_negative(pll, mfn)) {
if (is_imx27_pllv1(pll))
mfn_abs = mfn & MFN_MASK;
else
mfn_abs = BIT(MFN_BITS) - mfn;
}
rate = parent_rate * 2;
rate /= pd + 1;
ull = (unsigned long long)rate * mfn_abs;
do_div(ull, mfd + 1);
if (mfn_is_negative(pll, mfn))
ull = (rate * mfi) - ull;
else
ull = (rate * mfi) + ull;
return ull;
}
struct clk *imx_clk_pllv1(enum imx_pllv1_type type, const char *name,
const char *parent, void __iomem *base)
{
struct clk_pllv1 *pll;
struct clk *clk;
struct clk_init_data init;
pll = kmalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
pll->base = base;
pll->type = type;
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
