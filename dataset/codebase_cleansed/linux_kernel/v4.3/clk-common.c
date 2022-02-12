static inline unsigned long clkc_readl(unsigned reg)
{
return readl(sirfsoc_clk_vbase + reg);
}
static inline void clkc_writel(u32 val, unsigned reg)
{
writel(val, sirfsoc_clk_vbase + reg);
}
static unsigned long pll_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long fin = parent_rate;
struct clk_pll *clk = to_pllclk(hw);
u32 regcfg2 = clk->regofs + SIRFSOC_CLKC_PLL1_CFG2 -
SIRFSOC_CLKC_PLL1_CFG0;
if (clkc_readl(regcfg2) & BIT(2)) {
return fin;
} else {
u32 cfg0 = clkc_readl(clk->regofs);
u32 nf = (cfg0 & (BIT(13) - 1)) + 1;
u32 nr = ((cfg0 >> 13) & (BIT(6) - 1)) + 1;
u32 od = ((cfg0 >> 19) & (BIT(4) - 1)) + 1;
WARN_ON(fin % MHZ);
return fin / MHZ * nf / nr / od * MHZ;
}
}
static long pll_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long fin, nf, nr, od;
u64 dividend;
rate = rate - rate % MHZ;
nf = rate / MHZ;
if (nf > BIT(13))
nf = BIT(13);
if (nf < 1)
nf = 1;
fin = *parent_rate;
nr = fin / MHZ;
if (nr > BIT(6))
nr = BIT(6);
od = 1;
dividend = (u64)fin * nf;
do_div(dividend, nr * od);
return (long)dividend;
}
static int pll_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pll *clk = to_pllclk(hw);
unsigned long fin, nf, nr, od, reg;
nf = rate / MHZ;
if (unlikely((rate % MHZ) || nf > BIT(13) || nf < 1))
return -EINVAL;
fin = parent_rate;
BUG_ON(fin < MHZ);
nr = fin / MHZ;
BUG_ON((fin % MHZ) || nr > BIT(6));
od = 1;
reg = (nf - 1) | ((nr - 1) << 13) | ((od - 1) << 19);
clkc_writel(reg, clk->regofs);
reg = clk->regofs + SIRFSOC_CLKC_PLL1_CFG1 - SIRFSOC_CLKC_PLL1_CFG0;
clkc_writel((nf >> 1) - 1, reg);
reg = clk->regofs + SIRFSOC_CLKC_PLL1_CFG2 - SIRFSOC_CLKC_PLL1_CFG0;
while (!(clkc_readl(reg) & BIT(6)))
cpu_relax();
return 0;
}
static long cpu_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct clk_hw *parent_clk = clk_hw_get_parent(hw);
struct clk_hw *pll_parent_clk = clk_hw_get_parent(parent_clk);
unsigned long pll_parent_rate = clk_hw_get_rate(pll_parent_clk);
return pll_clk_round_rate(parent_clk, rate, &pll_parent_rate);
}
static unsigned long cpu_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_hw *parent_clk = clk_hw_get_parent(hw);
return clk_hw_get_rate(parent_clk);
}
static int usb_pll_clk_enable(struct clk_hw *hw)
{
u32 reg = readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
reg &= ~(SIRFSOC_USBPHY_PLL_POWERDOWN | SIRFSOC_USBPHY_PLL_BYPASS);
writel(reg, sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
while (!(readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL) &
SIRFSOC_USBPHY_PLL_LOCK))
cpu_relax();
return 0;
}
static void usb_pll_clk_disable(struct clk_hw *clk)
{
u32 reg = readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
reg |= (SIRFSOC_USBPHY_PLL_POWERDOWN | SIRFSOC_USBPHY_PLL_BYPASS);
writel(reg, sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
}
static unsigned long usb_pll_clk_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
u32 reg = readl(sirfsoc_rsc_vbase + SIRFSOC_USBPHY_PLL_CTRL);
return (reg & SIRFSOC_USBPHY_PLL_BYPASS) ? parent_rate : 48*MHZ;
}
static u8 dmn_clk_get_parent(struct clk_hw *hw)
{
struct clk_dmn *clk = to_dmnclk(hw);
u32 cfg = clkc_readl(clk->regofs);
if (strcmp(hw->init->name, "io") == 0)
return 4;
WARN_ON((cfg & (BIT(3) - 1)) > 4);
return cfg & (BIT(3) - 1);
}
static int dmn_clk_set_parent(struct clk_hw *hw, u8 parent)
{
struct clk_dmn *clk = to_dmnclk(hw);
u32 cfg = clkc_readl(clk->regofs);
if (strcmp(hw->init->name, "io") == 0)
return -EINVAL;
cfg &= ~(BIT(3) - 1);
clkc_writel(cfg | parent, clk->regofs);
while (clkc_readl(clk->regofs) & BIT(3))
cpu_relax();
return 0;
}
static unsigned long dmn_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long fin = parent_rate;
struct clk_dmn *clk = to_dmnclk(hw);
u32 cfg = clkc_readl(clk->regofs);
if (cfg & BIT(24)) {
return fin;
} else {
u32 wait = (cfg >> 16) & (BIT(4) - 1);
u32 hold = (cfg >> 20) & (BIT(4) - 1);
return fin / (wait + hold + 2);
}
}
static long dmn_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long fin;
unsigned ratio, wait, hold;
unsigned bits = (strcmp(hw->init->name, "mem") == 0) ? 3 : 4;
fin = *parent_rate;
ratio = fin / rate;
if (ratio < 2)
ratio = 2;
if (ratio > BIT(bits + 1))
ratio = BIT(bits + 1);
wait = (ratio >> 1) - 1;
hold = ratio - wait - 2;
return fin / (wait + hold + 2);
}
static int dmn_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_dmn *clk = to_dmnclk(hw);
unsigned long fin;
unsigned ratio, wait, hold, reg;
unsigned bits = (strcmp(hw->init->name, "mem") == 0) ? 3 : 4;
fin = parent_rate;
ratio = fin / rate;
if (unlikely(ratio < 2 || ratio > BIT(bits + 1)))
return -EINVAL;
WARN_ON(fin % rate);
wait = (ratio >> 1) - 1;
hold = ratio - wait - 2;
reg = clkc_readl(clk->regofs);
reg &= ~(((BIT(bits) - 1) << 16) | ((BIT(bits) - 1) << 20));
reg |= (wait << 16) | (hold << 20) | BIT(25);
clkc_writel(reg, clk->regofs);
while (clkc_readl(clk->regofs) & BIT(25))
cpu_relax();
return 0;
}
static int cpu_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
int ret1, ret2;
struct clk *cur_parent;
if (rate == clk_get_rate(clk_pll1.hw.clk)) {
ret1 = clk_set_parent(hw->clk, clk_pll1.hw.clk);
return ret1;
}
if (rate == clk_get_rate(clk_pll2.hw.clk)) {
ret1 = clk_set_parent(hw->clk, clk_pll2.hw.clk);
return ret1;
}
if (rate == clk_get_rate(clk_pll3.hw.clk)) {
ret1 = clk_set_parent(hw->clk, clk_pll3.hw.clk);
return ret1;
}
cur_parent = clk_get_parent(hw->clk);
if (cur_parent == clk_pll1.hw.clk) {
ret1 = clk_set_parent(hw->clk, clk_pll2.hw.clk);
BUG_ON(ret1);
}
ret2 = clk_set_rate(clk_pll1.hw.clk, rate);
ret1 = clk_set_parent(hw->clk, clk_pll1.hw.clk);
return ret2 ? ret2 : ret1;
}
static int std_clk_is_enabled(struct clk_hw *hw)
{
u32 reg;
int bit;
struct clk_std *clk = to_stdclk(hw);
bit = clk->enable_bit % 32;
reg = clk->enable_bit / 32;
reg = SIRFSOC_CLKC_CLK_EN0 + reg * sizeof(reg);
return !!(clkc_readl(reg) & BIT(bit));
}
static int std_clk_enable(struct clk_hw *hw)
{
u32 val, reg;
int bit;
struct clk_std *clk = to_stdclk(hw);
BUG_ON(clk->enable_bit < 0 || clk->enable_bit > 63);
bit = clk->enable_bit % 32;
reg = clk->enable_bit / 32;
reg = SIRFSOC_CLKC_CLK_EN0 + reg * sizeof(reg);
val = clkc_readl(reg) | BIT(bit);
clkc_writel(val, reg);
return 0;
}
static void std_clk_disable(struct clk_hw *hw)
{
u32 val, reg;
int bit;
struct clk_std *clk = to_stdclk(hw);
BUG_ON(clk->enable_bit < 0 || clk->enable_bit > 63);
bit = clk->enable_bit % 32;
reg = clk->enable_bit / 32;
reg = SIRFSOC_CLKC_CLK_EN0 + reg * sizeof(reg);
val = clkc_readl(reg) & ~BIT(bit);
clkc_writel(val, reg);
}
