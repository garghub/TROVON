static u32 lpc18xx_pll0_mdec2msel(u32 x)
{
int i;
switch (x) {
case 0x18003: return 1;
case 0x10003: return 2;
default:
for (i = LPC18XX_PLL0_MSEL_MAX + 1; x != 0x4000 && i > 0; i--)
x = ((x ^ x >> 14) & 1) | (x << 1 & 0x7fff);
return i;
}
}
static u32 lpc18xx_pll0_msel2mdec(u32 msel)
{
u32 i, x = 0x4000;
switch (msel) {
case 0: return 0;
case 1: return 0x18003;
case 2: return 0x10003;
default:
for (i = msel; i <= LPC18XX_PLL0_MSEL_MAX; i++)
x = ((x ^ x >> 1) & 1) << 14 | (x >> 1 & 0xffff);
return x;
}
}
static u32 lpc18xx_pll0_msel2seli(u32 msel)
{
u32 tmp;
if (msel > 16384) return 1;
if (msel > 8192) return 2;
if (msel > 2048) return 4;
if (msel >= 501) return 8;
if (msel >= 60) {
tmp = 1024 / (msel + 9);
return ((1024 == (tmp * (msel + 9))) == 0) ? tmp * 4 : (tmp + 1) * 4;
}
return (msel & 0x3c) + 4;
}
static u32 lpc18xx_pll0_msel2selp(u32 msel)
{
if (msel < 60)
return (msel >> 1) + 1;
return 31;
}
static unsigned long lpc18xx_pll0_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct lpc18xx_pll *pll = to_lpc_pll(hw);
u32 ctrl, mdiv, msel, npdiv;
ctrl = clk_readl(pll->reg + LPC18XX_CGU_PLL0USB_CTRL);
mdiv = clk_readl(pll->reg + LPC18XX_CGU_PLL0USB_MDIV);
npdiv = clk_readl(pll->reg + LPC18XX_CGU_PLL0USB_NP_DIV);
if (ctrl & LPC18XX_PLL0_CTRL_BYPASS)
return parent_rate;
if (npdiv != LPC18XX_PLL0_NP_DIVS_1) {
pr_warn("%s: pre/post dividers not supported\n", __func__);
return 0;
}
msel = lpc18xx_pll0_mdec2msel(mdiv & LPC18XX_PLL0_MDIV_MDEC_MASK);
if (msel)
return 2 * msel * parent_rate;
pr_warn("%s: unable to calculate rate\n", __func__);
return 0;
}
static long lpc18xx_pll0_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long m;
if (*prate < rate) {
pr_warn("%s: pll dividers not supported\n", __func__);
return -EINVAL;
}
m = DIV_ROUND_UP_ULL(*prate, rate * 2);
if (m <= 0 && m > LPC18XX_PLL0_MSEL_MAX) {
pr_warn("%s: unable to support rate %lu\n", __func__, rate);
return -EINVAL;
}
return 2 * *prate * m;
}
static int lpc18xx_pll0_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct lpc18xx_pll *pll = to_lpc_pll(hw);
u32 ctrl, stat, m;
int retry = 3;
if (parent_rate < rate) {
pr_warn("%s: pll dividers not supported\n", __func__);
return -EINVAL;
}
m = DIV_ROUND_UP_ULL(parent_rate, rate * 2);
if (m <= 0 && m > LPC18XX_PLL0_MSEL_MAX) {
pr_warn("%s: unable to support rate %lu\n", __func__, rate);
return -EINVAL;
}
m = lpc18xx_pll0_msel2mdec(m);
m |= lpc18xx_pll0_msel2selp(m) << LPC18XX_PLL0_MDIV_SELP_SHIFT;
m |= lpc18xx_pll0_msel2seli(m) << LPC18XX_PLL0_MDIV_SELI_SHIFT;
ctrl = clk_readl(pll->reg + LPC18XX_CGU_PLL0USB_CTRL);
ctrl |= LPC18XX_PLL0_CTRL_PD;
ctrl &= ~(LPC18XX_PLL0_CTRL_BYPASS | LPC18XX_PLL0_CTRL_DIRECTI |
LPC18XX_PLL0_CTRL_DIRECTO | LPC18XX_PLL0_CTRL_CLKEN);
clk_writel(ctrl, pll->reg + LPC18XX_CGU_PLL0USB_CTRL);
clk_writel(m, pll->reg + LPC18XX_CGU_PLL0USB_MDIV);
clk_writel(LPC18XX_PLL0_NP_DIVS_1, pll->reg + LPC18XX_CGU_PLL0USB_NP_DIV);
ctrl &= ~LPC18XX_PLL0_CTRL_PD;
clk_writel(ctrl, pll->reg + LPC18XX_CGU_PLL0USB_CTRL);
do {
udelay(10);
stat = clk_readl(pll->reg + LPC18XX_CGU_PLL0USB_STAT);
if (stat & LPC18XX_PLL0_STAT_LOCK) {
ctrl |= LPC18XX_PLL0_CTRL_CLKEN;
clk_writel(ctrl, pll->reg + LPC18XX_CGU_PLL0USB_CTRL);
return 0;
}
} while (retry--);
pr_warn("%s: unable to lock pll\n", __func__);
return -EINVAL;
}
static unsigned long lpc18xx_pll1_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct lpc18xx_pll *pll = to_lpc_pll(hw);
u16 msel, nsel, psel;
bool direct, fbsel;
u32 stat, ctrl;
stat = clk_readl(pll->reg + LPC18XX_CGU_PLL1_STAT);
ctrl = clk_readl(pll->reg + LPC18XX_CGU_PLL1_CTRL);
direct = (ctrl & LPC18XX_PLL1_CTRL_DIRECT) ? true : false;
fbsel = (ctrl & LPC18XX_PLL1_CTRL_FBSEL) ? true : false;
msel = ((ctrl >> 16) & 0xff) + 1;
nsel = ((ctrl >> 12) & 0x3) + 1;
if (direct || fbsel)
return msel * (parent_rate / nsel);
psel = (ctrl >> 8) & 0x3;
psel = 1 << psel;
return (msel / (2 * psel)) * (parent_rate / nsel);
}
static int lpc18xx_cgu_gate_enable(struct clk_hw *hw)
{
return clk_gate_ops.enable(hw);
}
static void lpc18xx_cgu_gate_disable(struct clk_hw *hw)
{
clk_gate_ops.disable(hw);
}
static int lpc18xx_cgu_gate_is_enabled(struct clk_hw *hw)
{
const struct clk_hw *parent;
parent = clk_hw_get_parent(hw);
if (!parent)
return 0;
if (!clk_hw_is_enabled(parent))
return 0;
return clk_gate_ops.is_enabled(hw);
}
static void lpc18xx_fill_parent_names(const char **parent, u32 *id, int size)
{
int i;
for (i = 0; i < size; i++)
parent[i] = clk_src_names[id[i]];
}
static struct clk *lpc18xx_cgu_register_div(struct lpc18xx_cgu_src_clk_div *clk,
void __iomem *base, int n)
{
void __iomem *reg = base + LPC18XX_CGU_IDIV_CTRL(n);
const char *name = clk_src_names[clk->clk_id];
const char *parents[CLK_SRC_MAX];
clk->div.reg = reg;
clk->mux.reg = reg;
clk->gate.reg = reg;
lpc18xx_fill_parent_names(parents, clk->mux.table, clk->n_parents);
return clk_register_composite(NULL, name, parents, clk->n_parents,
&clk->mux.hw, &clk_mux_ops,
&clk->div.hw, &clk_divider_ops,
&clk->gate.hw, &lpc18xx_gate_ops, 0);
}
static struct clk *lpc18xx_register_base_clk(struct lpc18xx_cgu_base_clk *clk,
void __iomem *reg_base, int n)
{
void __iomem *reg = reg_base + LPC18XX_CGU_BASE_CLK(n);
const char *name = clk_base_names[clk->clk_id];
const char *parents[CLK_SRC_MAX];
if (clk->n_parents == 0)
return ERR_PTR(-ENOENT);
clk->mux.reg = reg;
clk->gate.reg = reg;
lpc18xx_fill_parent_names(parents, clk->mux.table, clk->n_parents);
if (n == BASE_SAFE_CLK)
return clk_register_composite(NULL, name, parents, clk->n_parents,
&clk->mux.hw, &clk_mux_ops,
NULL, NULL, NULL, NULL, 0);
return clk_register_composite(NULL, name, parents, clk->n_parents,
&clk->mux.hw, &clk_mux_ops,
NULL, NULL,
&clk->gate.hw, &lpc18xx_gate_ops, 0);
}
static struct clk *lpc18xx_cgu_register_pll(struct lpc18xx_cgu_pll_clk *clk,
void __iomem *base)
{
const char *name = clk_src_names[clk->clk_id];
const char *parents[CLK_SRC_MAX];
clk->pll.reg = base;
clk->mux.reg = base + clk->reg_offset + LPC18XX_CGU_PLL_CTRL_OFFSET;
clk->gate.reg = base + clk->reg_offset + LPC18XX_CGU_PLL_CTRL_OFFSET;
lpc18xx_fill_parent_names(parents, clk->mux.table, clk->n_parents);
return clk_register_composite(NULL, name, parents, clk->n_parents,
&clk->mux.hw, &clk_mux_ops,
&clk->pll.hw, clk->pll_ops,
&clk->gate.hw, &lpc18xx_gate_ops, 0);
}
static void __init lpc18xx_cgu_register_source_clks(struct device_node *np,
void __iomem *base)
{
const char *parents[CLK_SRC_MAX];
struct clk *clk;
int i;
clk = clk_register_fixed_rate(NULL, clk_src_names[CLK_SRC_IRC],
NULL, CLK_IS_ROOT, 12000000);
if (IS_ERR(clk))
pr_warn("%s: failed to register irc clk\n", __func__);
parents[0] = of_clk_get_parent_name(np, 0);
clk = clk_register_gate(NULL, clk_src_names[CLK_SRC_OSC], parents[0],
0, base + LPC18XX_CGU_XTAL_OSC_CTRL,
0, CLK_GATE_SET_TO_DISABLE, NULL);
if (IS_ERR(clk))
pr_warn("%s: failed to register osc clk\n", __func__);
for (i = 0; i < ARRAY_SIZE(lpc18xx_cgu_src_clk_plls); i++) {
clk = lpc18xx_cgu_register_pll(&lpc18xx_cgu_src_clk_plls[i],
base);
if (IS_ERR(clk))
pr_warn("%s: failed to register pll (%d)\n", __func__, i);
}
for (i = 0; i < ARRAY_SIZE(lpc18xx_cgu_src_clk_divs); i++) {
clk = lpc18xx_cgu_register_div(&lpc18xx_cgu_src_clk_divs[i],
base, i);
if (IS_ERR(clk))
pr_warn("%s: failed to register div %d\n", __func__, i);
}
}
static void __init lpc18xx_cgu_register_base_clks(void __iomem *reg_base)
{
int i;
for (i = BASE_SAFE_CLK; i < BASE_CLK_MAX; i++) {
clk_base[i] = lpc18xx_register_base_clk(&lpc18xx_cgu_base_clks[i],
reg_base, i);
if (IS_ERR(clk_base[i]) && PTR_ERR(clk_base[i]) != -ENOENT)
pr_warn("%s: register base clk %d failed\n", __func__, i);
}
}
static void __init lpc18xx_cgu_init(struct device_node *np)
{
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_warn("%s: failed to map address range\n", __func__);
return;
}
lpc18xx_cgu_register_source_clks(np, reg_base);
lpc18xx_cgu_register_base_clks(reg_base);
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_base_data);
}
