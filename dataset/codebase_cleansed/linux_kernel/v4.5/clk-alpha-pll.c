static int wait_for_pll(struct clk_alpha_pll *pll)
{
u32 val, mask, off;
int count;
int ret;
const char *name = clk_hw_get_name(&pll->clkr.hw);
off = pll->offset;
ret = regmap_read(pll->clkr.regmap, off + PLL_MODE, &val);
if (ret)
return ret;
if (val & PLL_VOTE_FSM_ENA)
mask = PLL_ACTIVE_FLAG;
else
mask = PLL_LOCK_DET;
for (count = 100; count > 0; count--) {
ret = regmap_read(pll->clkr.regmap, off + PLL_MODE, &val);
if (ret)
return ret;
if ((val & mask) == mask)
return 0;
udelay(1);
}
WARN(1, "%s didn't enable after voting for it!\n", name);
return -ETIMEDOUT;
}
static int clk_alpha_pll_enable(struct clk_hw *hw)
{
int ret;
struct clk_alpha_pll *pll = to_clk_alpha_pll(hw);
u32 val, mask, off;
off = pll->offset;
mask = PLL_OUTCTRL | PLL_RESET_N | PLL_BYPASSNL;
ret = regmap_read(pll->clkr.regmap, off + PLL_MODE, &val);
if (ret)
return ret;
if (val & PLL_VOTE_FSM_ENA) {
ret = clk_enable_regmap(hw);
if (ret)
return ret;
return wait_for_pll(pll);
}
if ((val & mask) == mask)
return 0;
ret = regmap_update_bits(pll->clkr.regmap, off + PLL_MODE,
PLL_BYPASSNL, PLL_BYPASSNL);
if (ret)
return ret;
mb();
udelay(5);
ret = regmap_update_bits(pll->clkr.regmap, off + PLL_MODE,
PLL_RESET_N, PLL_RESET_N);
if (ret)
return ret;
ret = wait_for_pll(pll);
if (ret)
return ret;
ret = regmap_update_bits(pll->clkr.regmap, off + PLL_MODE,
PLL_OUTCTRL, PLL_OUTCTRL);
mb();
return ret;
}
static void clk_alpha_pll_disable(struct clk_hw *hw)
{
int ret;
struct clk_alpha_pll *pll = to_clk_alpha_pll(hw);
u32 val, mask, off;
off = pll->offset;
ret = regmap_read(pll->clkr.regmap, off + PLL_MODE, &val);
if (ret)
return;
if (val & PLL_VOTE_FSM_ENA) {
clk_disable_regmap(hw);
return;
}
mask = PLL_OUTCTRL;
regmap_update_bits(pll->clkr.regmap, off + PLL_MODE, mask, 0);
mb();
udelay(1);
mask = PLL_RESET_N | PLL_BYPASSNL;
regmap_update_bits(pll->clkr.regmap, off + PLL_MODE, mask, 0);
}
static unsigned long alpha_pll_calc_rate(u64 prate, u32 l, u32 a)
{
return (prate * l) + ((prate * a) >> ALPHA_BITWIDTH);
}
static unsigned long
alpha_pll_round_rate(unsigned long rate, unsigned long prate, u32 *l, u64 *a)
{
u64 remainder;
u64 quotient;
quotient = rate;
remainder = do_div(quotient, prate);
*l = quotient;
if (!remainder) {
*a = 0;
return rate;
}
quotient = remainder << ALPHA_BITWIDTH;
remainder = do_div(quotient, prate);
if (remainder)
quotient++;
*a = quotient;
return alpha_pll_calc_rate(prate, *l, *a);
}
static const struct pll_vco *
alpha_pll_find_vco(const struct clk_alpha_pll *pll, unsigned long rate)
{
const struct pll_vco *v = pll->vco_table;
const struct pll_vco *end = v + pll->num_vco;
for (; v < end; v++)
if (rate >= v->min_freq && rate <= v->max_freq)
return v;
return NULL;
}
static unsigned long
clk_alpha_pll_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
u32 l, low, high, ctl;
u64 a = 0, prate = parent_rate;
struct clk_alpha_pll *pll = to_clk_alpha_pll(hw);
u32 off = pll->offset;
regmap_read(pll->clkr.regmap, off + PLL_L_VAL, &l);
regmap_read(pll->clkr.regmap, off + PLL_USER_CTL, &ctl);
if (ctl & PLL_ALPHA_EN) {
regmap_read(pll->clkr.regmap, off + PLL_ALPHA_VAL, &low);
regmap_read(pll->clkr.regmap, off + PLL_ALPHA_VAL_U, &high);
a = (u64)high << 32 | low;
a >>= ALPHA_REG_BITWIDTH - ALPHA_BITWIDTH;
}
return alpha_pll_calc_rate(prate, l, a);
}
static int clk_alpha_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long prate)
{
struct clk_alpha_pll *pll = to_clk_alpha_pll(hw);
const struct pll_vco *vco;
u32 l, off = pll->offset;
u64 a;
rate = alpha_pll_round_rate(rate, prate, &l, &a);
vco = alpha_pll_find_vco(pll, rate);
if (!vco) {
pr_err("alpha pll not in a valid vco range\n");
return -EINVAL;
}
a <<= (ALPHA_REG_BITWIDTH - ALPHA_BITWIDTH);
regmap_write(pll->clkr.regmap, off + PLL_L_VAL, l);
regmap_write(pll->clkr.regmap, off + PLL_ALPHA_VAL, a);
regmap_write(pll->clkr.regmap, off + PLL_ALPHA_VAL_U, a >> 32);
regmap_update_bits(pll->clkr.regmap, off + PLL_USER_CTL,
PLL_VCO_MASK << PLL_VCO_SHIFT,
vco->val << PLL_VCO_SHIFT);
regmap_update_bits(pll->clkr.regmap, off + PLL_USER_CTL, PLL_ALPHA_EN,
PLL_ALPHA_EN);
return 0;
}
static long clk_alpha_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_alpha_pll *pll = to_clk_alpha_pll(hw);
u32 l;
u64 a;
unsigned long min_freq, max_freq;
rate = alpha_pll_round_rate(rate, *prate, &l, &a);
if (alpha_pll_find_vco(pll, rate))
return rate;
min_freq = pll->vco_table[0].min_freq;
max_freq = pll->vco_table[pll->num_vco - 1].max_freq;
return clamp(rate, min_freq, max_freq);
}
static unsigned long
clk_alpha_pll_postdiv_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
struct clk_alpha_pll_postdiv *pll = to_clk_alpha_pll_postdiv(hw);
u32 ctl;
regmap_read(pll->clkr.regmap, pll->offset + PLL_USER_CTL, &ctl);
ctl >>= PLL_POST_DIV_SHIFT;
ctl &= PLL_POST_DIV_MASK;
return parent_rate >> fls(ctl);
}
static long
clk_alpha_pll_postdiv_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_alpha_pll_postdiv *pll = to_clk_alpha_pll_postdiv(hw);
return divider_round_rate(hw, rate, prate, clk_alpha_div_table,
pll->width, CLK_DIVIDER_POWER_OF_TWO);
}
static int clk_alpha_pll_postdiv_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_alpha_pll_postdiv *pll = to_clk_alpha_pll_postdiv(hw);
int div;
div = DIV_ROUND_UP_ULL((u64)parent_rate, rate) - 1;
return regmap_update_bits(pll->clkr.regmap, pll->offset + PLL_USER_CTL,
PLL_POST_DIV_MASK << PLL_POST_DIV_SHIFT,
div << PLL_POST_DIV_SHIFT);
}
