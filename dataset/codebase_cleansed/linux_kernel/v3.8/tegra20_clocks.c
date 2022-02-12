static unsigned long clk_measure_input_freq(void)
{
u32 clock_autodetect;
clk_writel(OSC_FREQ_DET_TRIG | 1, OSC_FREQ_DET);
do {} while (clk_readl(OSC_FREQ_DET_STATUS) & OSC_FREQ_DET_BUSY);
clock_autodetect = clk_readl(OSC_FREQ_DET_STATUS);
if (clock_autodetect >= 732 - 3 && clock_autodetect <= 732 + 3) {
return 12000000;
} else if (clock_autodetect >= 794 - 3 && clock_autodetect <= 794 + 3) {
return 13000000;
} else if (clock_autodetect >= 1172 - 3 && clock_autodetect <= 1172 + 3) {
return 19200000;
} else if (clock_autodetect >= 1587 - 3 && clock_autodetect <= 1587 + 3) {
return 26000000;
} else {
pr_err("%s: Unexpected clock autodetect value %d",
__func__, clock_autodetect);
BUG();
return 0;
}
}
static int clk_div71_get_divider(unsigned long parent_rate, unsigned long rate)
{
s64 divider_u71 = parent_rate * 2;
divider_u71 += rate - 1;
do_div(divider_u71, rate);
if (divider_u71 - 2 < 0)
return 0;
if (divider_u71 - 2 > 255)
return -EINVAL;
return divider_u71 - 2;
}
static int clk_div16_get_divider(unsigned long parent_rate, unsigned long rate)
{
s64 divider_u16;
divider_u16 = parent_rate;
divider_u16 += rate - 1;
do_div(divider_u16, rate);
if (divider_u16 - 1 < 0)
return 0;
if (divider_u16 - 1 > 0xFFFF)
return -EINVAL;
return divider_u16 - 1;
}
static unsigned long tegra_clk_fixed_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return to_clk_tegra(hw)->fixed_rate;
}
static unsigned long tegra20_clk_m_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
if (!to_clk_tegra(hw)->fixed_rate)
to_clk_tegra(hw)->fixed_rate = clk_measure_input_freq();
return to_clk_tegra(hw)->fixed_rate;
}
static void tegra20_clk_m_init(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 osc_ctrl = clk_readl(OSC_CTRL);
u32 auto_clock_control = osc_ctrl & ~OSC_CTRL_OSC_FREQ_MASK;
switch (c->fixed_rate) {
case 12000000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_12MHZ;
break;
case 13000000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_13MHZ;
break;
case 19200000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_19_2MHZ;
break;
case 26000000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_26MHZ;
break;
default:
BUG();
}
clk_writel(auto_clock_control, OSC_CTRL);
}
static int tegra20_super_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
val = clk_readl(c->reg + SUPER_CLK_MUX);
BUG_ON(((val & SUPER_STATE_MASK) != SUPER_STATE_RUN) &&
((val & SUPER_STATE_MASK) != SUPER_STATE_IDLE));
c->state = ON;
return c->state;
}
static int tegra20_super_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
clk_writel(0, c->reg + SUPER_CLK_DIVIDER);
return 0;
}
static void tegra20_super_clk_disable(struct clk_hw *hw)
{
pr_debug("%s on clock %s\n", __func__, __clk_get_name(hw->clk));
BUG();
}
static u8 tegra20_super_clk_get_parent(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
int val = clk_readl(c->reg + SUPER_CLK_MUX);
int source;
int shift;
BUG_ON(((val & SUPER_STATE_MASK) != SUPER_STATE_RUN) &&
((val & SUPER_STATE_MASK) != SUPER_STATE_IDLE));
shift = ((val & SUPER_STATE_MASK) == SUPER_STATE_IDLE) ?
SUPER_IDLE_SOURCE_SHIFT : SUPER_RUN_SOURCE_SHIFT;
source = (val >> shift) & SUPER_SOURCE_MASK;
return source;
}
static int tegra20_super_clk_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg + SUPER_CLK_MUX);
int shift;
BUG_ON(((val & SUPER_STATE_MASK) != SUPER_STATE_RUN) &&
((val & SUPER_STATE_MASK) != SUPER_STATE_IDLE));
shift = ((val & SUPER_STATE_MASK) == SUPER_STATE_IDLE) ?
SUPER_IDLE_SOURCE_SHIFT : SUPER_RUN_SOURCE_SHIFT;
val &= ~(SUPER_SOURCE_MASK << shift);
val |= index << shift;
clk_writel(val, c->reg);
return 0;
}
static unsigned long tegra20_super_clk_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
return prate;
}
static long tegra20_super_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
return *prate;
}
static int tegra20_super_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
return 0;
}
static unsigned long tegra20_twd_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_tegra *c = to_clk_tegra(hw);
u64 rate = parent_rate;
if (c->mul != 0 && c->div != 0) {
rate *= c->mul;
rate += c->div - 1;
do_div(rate, c->div);
}
return rate;
}
static u8 tegra20_cop_clk_get_parent(struct clk_hw *hw)
{
return 0;
}
void tegra2_cop_clk_reset(struct clk_hw *hw, bool assert)
{
unsigned long reg = assert ? RST_DEVICES_SET : RST_DEVICES_CLR;
pr_debug("%s %s\n", __func__, assert ? "assert" : "deassert");
clk_writel(1 << 1, reg);
}
static int tegra20_bus_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg);
c->state = ((val >> c->reg_shift) & BUS_CLK_DISABLE) ? OFF : ON;
return c->state;
}
static int tegra20_bus_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long flags;
u32 val;
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
val &= ~(BUS_CLK_DISABLE << c->reg_shift);
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
return 0;
}
static void tegra20_bus_clk_disable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long flags;
u32 val;
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
val |= BUS_CLK_DISABLE << c->reg_shift;
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
}
static unsigned long tegra20_bus_clk_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg);
u64 rate = prate;
c->div = ((val >> c->reg_shift) & BUS_CLK_DIV_MASK) + 1;
c->mul = 1;
if (c->mul != 0 && c->div != 0) {
rate *= c->mul;
rate += c->div - 1;
do_div(rate, c->div);
}
return rate;
}
static int tegra20_bus_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_tegra *c = to_clk_tegra(hw);
int ret = -EINVAL;
unsigned long flags;
u32 val;
int i;
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
for (i = 1; i <= 4; i++) {
if (rate == parent_rate / i) {
val &= ~(BUS_CLK_DIV_MASK << c->reg_shift);
val |= (i - 1) << c->reg_shift;
clk_writel(val, c->reg);
c->div = i;
c->mul = 1;
ret = 0;
break;
}
}
spin_unlock_irqrestore(&clock_register_lock, flags);
return ret;
}
static long tegra20_bus_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long parent_rate = *prate;
s64 divider;
if (rate >= parent_rate)
return rate;
divider = parent_rate;
divider += rate - 1;
do_div(divider, rate);
if (divider < 0)
return divider;
if (divider > 4)
divider = 4;
do_div(parent_rate, divider);
return parent_rate;
}
static int tegra20_blink_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
val = pmc_readl(PMC_CTRL);
c->state = (val & PMC_CTRL_BLINK_ENB) ? ON : OFF;
return c->state;
}
static unsigned long tegra20_blink_clk_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
u64 rate = prate;
u32 val;
c->mul = 1;
val = pmc_readl(c->reg);
if (val & PMC_BLINK_TIMER_ENB) {
unsigned int on_off;
on_off = (val >> PMC_BLINK_TIMER_DATA_ON_SHIFT) &
PMC_BLINK_TIMER_DATA_ON_MASK;
val >>= PMC_BLINK_TIMER_DATA_OFF_SHIFT;
val &= PMC_BLINK_TIMER_DATA_OFF_MASK;
on_off += val;
c->div = on_off * 4;
} else {
c->div = 1;
}
if (c->mul != 0 && c->div != 0) {
rate *= c->mul;
rate += c->div - 1;
do_div(rate, c->div);
}
return rate;
}
static int tegra20_blink_clk_enable(struct clk_hw *hw)
{
u32 val;
val = pmc_readl(PMC_DPD_PADS_ORIDE);
pmc_writel(val | PMC_DPD_PADS_ORIDE_BLINK_ENB, PMC_DPD_PADS_ORIDE);
val = pmc_readl(PMC_CTRL);
pmc_writel(val | PMC_CTRL_BLINK_ENB, PMC_CTRL);
return 0;
}
static void tegra20_blink_clk_disable(struct clk_hw *hw)
{
u32 val;
val = pmc_readl(PMC_CTRL);
pmc_writel(val & ~PMC_CTRL_BLINK_ENB, PMC_CTRL);
val = pmc_readl(PMC_DPD_PADS_ORIDE);
pmc_writel(val & ~PMC_DPD_PADS_ORIDE_BLINK_ENB, PMC_DPD_PADS_ORIDE);
}
static int tegra20_blink_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_tegra *c = to_clk_tegra(hw);
if (rate >= parent_rate) {
c->div = 1;
pmc_writel(0, c->reg);
} else {
unsigned int on_off;
u32 val;
on_off = DIV_ROUND_UP(parent_rate / 8, rate);
c->div = on_off * 8;
val = (on_off & PMC_BLINK_TIMER_DATA_ON_MASK) <<
PMC_BLINK_TIMER_DATA_ON_SHIFT;
on_off &= PMC_BLINK_TIMER_DATA_OFF_MASK;
on_off <<= PMC_BLINK_TIMER_DATA_OFF_SHIFT;
val |= on_off;
val |= PMC_BLINK_TIMER_ENB;
pmc_writel(val, c->reg);
}
return 0;
}
static long tegra20_blink_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int div;
int mul;
long round_rate = *prate;
mul = 1;
if (rate >= *prate) {
div = 1;
} else {
div = DIV_ROUND_UP(*prate / 8, rate);
div *= 8;
}
round_rate *= mul;
round_rate += div - 1;
do_div(round_rate, div);
return round_rate;
}
static int tegra20_pll_clk_wait_for_lock(struct clk_tegra *c)
{
udelay(c->u.pll.lock_delay);
return 0;
}
static int tegra20_pll_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg + PLL_BASE);
c->state = (val & PLL_BASE_ENABLE) ? ON : OFF;
return c->state;
}
static unsigned long tegra20_pll_clk_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg + PLL_BASE);
u64 rate = prate;
if (c->flags & PLL_FIXED && !(val & PLL_BASE_OVERRIDE)) {
const struct clk_pll_freq_table *sel;
for (sel = c->u.pll.freq_table; sel->input_rate != 0; sel++) {
if (sel->input_rate == prate &&
sel->output_rate == c->u.pll.fixed_rate) {
c->mul = sel->n;
c->div = sel->m * sel->p;
break;
}
}
pr_err("Clock %s has unknown fixed frequency\n",
__clk_get_name(hw->clk));
BUG();
} else if (val & PLL_BASE_BYPASS) {
c->mul = 1;
c->div = 1;
} else {
c->mul = (val & PLL_BASE_DIVN_MASK) >> PLL_BASE_DIVN_SHIFT;
c->div = (val & PLL_BASE_DIVM_MASK) >> PLL_BASE_DIVM_SHIFT;
if (c->flags & PLLU)
c->div *= (val & PLLU_BASE_POST_DIV) ? 1 : 2;
else
c->div *= (val & PLL_BASE_DIVP_MASK) ? 2 : 1;
}
if (c->mul != 0 && c->div != 0) {
rate *= c->mul;
rate += c->div - 1;
do_div(rate, c->div);
}
return rate;
}
static int tegra20_pll_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
pr_debug("%s on clock %s\n", __func__, __clk_get_name(hw->clk));
val = clk_readl(c->reg + PLL_BASE);
val &= ~PLL_BASE_BYPASS;
val |= PLL_BASE_ENABLE;
clk_writel(val, c->reg + PLL_BASE);
tegra20_pll_clk_wait_for_lock(c);
return 0;
}
static void tegra20_pll_clk_disable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
pr_debug("%s on clock %s\n", __func__, __clk_get_name(hw->clk));
val = clk_readl(c->reg);
val &= ~(PLL_BASE_BYPASS | PLL_BASE_ENABLE);
clk_writel(val, c->reg);
}
static int tegra20_pll_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long input_rate = parent_rate;
const struct clk_pll_freq_table *sel;
u32 val;
pr_debug("%s: %s %lu\n", __func__, __clk_get_name(hw->clk), rate);
if (c->flags & PLL_FIXED) {
int ret = 0;
if (rate != c->u.pll.fixed_rate) {
pr_err("%s: Can not change %s fixed rate %lu to %lu\n",
__func__, __clk_get_name(hw->clk),
c->u.pll.fixed_rate, rate);
ret = -EINVAL;
}
return ret;
}
for (sel = c->u.pll.freq_table; sel->input_rate != 0; sel++) {
if (sel->input_rate == input_rate && sel->output_rate == rate) {
c->mul = sel->n;
c->div = sel->m * sel->p;
val = clk_readl(c->reg + PLL_BASE);
if (c->flags & PLL_FIXED)
val |= PLL_BASE_OVERRIDE;
val &= ~(PLL_BASE_DIVP_MASK | PLL_BASE_DIVN_MASK |
PLL_BASE_DIVM_MASK);
val |= (sel->m << PLL_BASE_DIVM_SHIFT) |
(sel->n << PLL_BASE_DIVN_SHIFT);
BUG_ON(sel->p < 1 || sel->p > 2);
if (c->flags & PLLU) {
if (sel->p == 1)
val |= PLLU_BASE_POST_DIV;
} else {
if (sel->p == 2)
val |= 1 << PLL_BASE_DIVP_SHIFT;
}
clk_writel(val, c->reg + PLL_BASE);
if (c->flags & PLL_HAS_CPCON) {
val = clk_readl(c->reg + PLL_MISC(c));
val &= ~PLL_MISC_CPCON_MASK;
val |= sel->cpcon << PLL_MISC_CPCON_SHIFT;
clk_writel(val, c->reg + PLL_MISC(c));
}
if (c->state == ON)
tegra20_pll_clk_enable(hw);
return 0;
}
}
return -EINVAL;
}
static long tegra20_pll_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
const struct clk_pll_freq_table *sel;
unsigned long input_rate = *prate;
u64 output_rate = *prate;
int mul;
int div;
if (c->flags & PLL_FIXED)
return c->u.pll.fixed_rate;
for (sel = c->u.pll.freq_table; sel->input_rate != 0; sel++)
if (sel->input_rate == input_rate && sel->output_rate == rate) {
mul = sel->n;
div = sel->m * sel->p;
break;
}
if (sel->input_rate == 0)
return -EINVAL;
output_rate *= mul;
output_rate += div - 1;
do_div(output_rate, div);
return output_rate;
}
static void tegra20_pllx_clk_init(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
if (tegra_sku_id == 7)
c->max_rate = 750000000;
}
static int tegra20_plle_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
pr_debug("%s on clock %s\n", __func__, __clk_get_name(hw->clk));
mdelay(1);
val = clk_readl(c->reg + PLL_BASE);
if (!(val & PLLE_MISC_READY))
return -EBUSY;
val = clk_readl(c->reg + PLL_BASE);
val |= PLL_BASE_ENABLE | PLL_BASE_BYPASS;
clk_writel(val, c->reg + PLL_BASE);
return 0;
}
static int tegra20_pll_div_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg);
val >>= c->reg_shift;
c->state = (val & PLL_OUT_CLKEN) ? ON : OFF;
if (!(val & PLL_OUT_RESET_DISABLE))
c->state = OFF;
return c->state;
}
static unsigned long tegra20_pll_div_clk_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
u64 rate = prate;
u32 val = clk_readl(c->reg);
u32 divu71;
val >>= c->reg_shift;
if (c->flags & DIV_U71) {
divu71 = (val & PLL_OUT_RATIO_MASK) >> PLL_OUT_RATIO_SHIFT;
c->div = (divu71 + 2);
c->mul = 2;
} else if (c->flags & DIV_2) {
c->div = 2;
c->mul = 1;
} else {
c->div = 1;
c->mul = 1;
}
rate *= c->mul;
rate += c->div - 1;
do_div(rate, c->div);
return rate;
}
static int tegra20_pll_div_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long flags;
u32 new_val;
u32 val;
pr_debug("%s: %s\n", __func__, __clk_get_name(hw->clk));
if (c->flags & DIV_U71) {
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
new_val = val >> c->reg_shift;
new_val &= 0xFFFF;
new_val |= PLL_OUT_CLKEN | PLL_OUT_RESET_DISABLE;
val &= ~(0xFFFF << c->reg_shift);
val |= new_val << c->reg_shift;
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
return 0;
} else if (c->flags & DIV_2) {
BUG_ON(!(c->flags & PLLD));
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
val &= ~PLLD_MISC_DIV_RST;
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
return 0;
}
return -EINVAL;
}
static void tegra20_pll_div_clk_disable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long flags;
u32 new_val;
u32 val;
pr_debug("%s: %s\n", __func__, __clk_get_name(hw->clk));
if (c->flags & DIV_U71) {
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
new_val = val >> c->reg_shift;
new_val &= 0xFFFF;
new_val &= ~(PLL_OUT_CLKEN | PLL_OUT_RESET_DISABLE);
val &= ~(0xFFFF << c->reg_shift);
val |= new_val << c->reg_shift;
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
} else if (c->flags & DIV_2) {
BUG_ON(!(c->flags & PLLD));
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
val |= PLLD_MISC_DIV_RST;
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
}
}
static int tegra20_pll_div_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long flags;
int divider_u71;
u32 new_val;
u32 val;
pr_debug("%s: %s %lu\n", __func__, __clk_get_name(hw->clk), rate);
if (c->flags & DIV_U71) {
divider_u71 = clk_div71_get_divider(parent_rate, rate);
if (divider_u71 >= 0) {
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
new_val = val >> c->reg_shift;
new_val &= 0xFFFF;
if (c->flags & DIV_U71_FIXED)
new_val |= PLL_OUT_OVERRIDE;
new_val &= ~PLL_OUT_RATIO_MASK;
new_val |= divider_u71 << PLL_OUT_RATIO_SHIFT;
val &= ~(0xFFFF << c->reg_shift);
val |= new_val << c->reg_shift;
clk_writel(val, c->reg);
c->div = divider_u71 + 2;
c->mul = 2;
spin_unlock_irqrestore(&clock_register_lock, flags);
return 0;
}
} else if (c->flags & DIV_2) {
if (parent_rate == rate * 2)
return 0;
}
return -EINVAL;
}
static long tegra20_pll_div_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long parent_rate = *prate;
int divider;
pr_debug("%s: %s %lu\n", __func__, __clk_get_name(hw->clk), rate);
if (c->flags & DIV_U71) {
divider = clk_div71_get_divider(parent_rate, rate);
if (divider < 0)
return divider;
return DIV_ROUND_UP(parent_rate * 2, divider + 2);
} else if (c->flags & DIV_2) {
return DIV_ROUND_UP(parent_rate, 2);
}
return -EINVAL;
}
static int tegra20_periph_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
c->state = ON;
if (!c->u.periph.clk_num)
goto out;
if (!(clk_readl(CLK_OUT_ENB + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c)))
c->state = OFF;
if (!(c->flags & PERIPH_NO_RESET))
if (clk_readl(RST_DEVICES + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c))
c->state = OFF;
out:
return c->state;
}
static int tegra20_periph_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long flags;
u32 val;
pr_debug("%s on clock %s\n", __func__, __clk_get_name(hw->clk));
if (!c->u.periph.clk_num)
return 0;
tegra_periph_clk_enable_refcount[c->u.periph.clk_num]++;
if (tegra_periph_clk_enable_refcount[c->u.periph.clk_num] > 1)
return 0;
spin_lock_irqsave(&clock_register_lock, flags);
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
CLK_OUT_ENB_SET + PERIPH_CLK_TO_ENB_SET_REG(c));
if (!(c->flags & PERIPH_NO_RESET) && !(c->flags & PERIPH_MANUAL_RESET))
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
RST_DEVICES_CLR + PERIPH_CLK_TO_ENB_SET_REG(c));
if (c->flags & PERIPH_EMC_ENB) {
val = clk_readl(c->reg);
val |= 0x3 << 24;
clk_writel(val, c->reg);
}
spin_unlock_irqrestore(&clock_register_lock, flags);
return 0;
}
static void tegra20_periph_clk_disable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long flags;
pr_debug("%s on clock %s\n", __func__, __clk_get_name(hw->clk));
if (!c->u.periph.clk_num)
return;
tegra_periph_clk_enable_refcount[c->u.periph.clk_num]--;
if (tegra_periph_clk_enable_refcount[c->u.periph.clk_num] > 0)
return;
spin_lock_irqsave(&clock_register_lock, flags);
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
CLK_OUT_ENB_CLR + PERIPH_CLK_TO_ENB_SET_REG(c));
spin_unlock_irqrestore(&clock_register_lock, flags);
}
void tegra2_periph_clk_reset(struct clk_hw *hw, bool assert)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long base = assert ? RST_DEVICES_SET : RST_DEVICES_CLR;
pr_debug("%s %s on clock %s\n", __func__,
assert ? "assert" : "deassert", __clk_get_name(hw->clk));
BUG_ON(!c->u.periph.clk_num);
if (!(c->flags & PERIPH_NO_RESET))
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
base + PERIPH_CLK_TO_ENB_SET_REG(c));
}
static int tegra20_periph_clk_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
u32 mask;
u32 shift;
pr_debug("%s: %s %d\n", __func__, __clk_get_name(hw->clk), index);
if (c->flags & MUX_PWM) {
shift = PERIPH_CLK_SOURCE_PWM_SHIFT;
mask = PERIPH_CLK_SOURCE_PWM_MASK;
} else {
shift = PERIPH_CLK_SOURCE_SHIFT;
mask = PERIPH_CLK_SOURCE_MASK;
}
val = clk_readl(c->reg);
val &= ~mask;
val |= (index) << shift;
clk_writel(val, c->reg);
return 0;
}
static u8 tegra20_periph_clk_get_parent(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg);
u32 mask;
u32 shift;
if (c->flags & MUX_PWM) {
shift = PERIPH_CLK_SOURCE_PWM_SHIFT;
mask = PERIPH_CLK_SOURCE_PWM_MASK;
} else {
shift = PERIPH_CLK_SOURCE_SHIFT;
mask = PERIPH_CLK_SOURCE_MASK;
}
if (c->flags & MUX)
return (val & mask) >> shift;
else
return 0;
}
static unsigned long tegra20_periph_clk_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long rate = prate;
u32 val = clk_readl(c->reg);
if (c->flags & DIV_U71) {
u32 divu71 = val & PERIPH_CLK_SOURCE_DIVU71_MASK;
c->div = divu71 + 2;
c->mul = 2;
} else if (c->flags & DIV_U16) {
u32 divu16 = val & PERIPH_CLK_SOURCE_DIVU16_MASK;
c->div = divu16 + 1;
c->mul = 1;
} else {
c->div = 1;
c->mul = 1;
return rate;
}
if (c->mul != 0 && c->div != 0) {
rate *= c->mul;
rate += c->div - 1;
do_div(rate, c->div);
}
return rate;
}
static int tegra20_periph_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
int divider;
val = clk_readl(c->reg);
if (c->flags & DIV_U71) {
divider = clk_div71_get_divider(parent_rate, rate);
if (divider >= 0) {
val = clk_readl(c->reg);
val &= ~PERIPH_CLK_SOURCE_DIVU71_MASK;
val |= divider;
clk_writel(val, c->reg);
c->div = divider + 2;
c->mul = 2;
return 0;
}
} else if (c->flags & DIV_U16) {
divider = clk_div16_get_divider(parent_rate, rate);
if (divider >= 0) {
val = clk_readl(c->reg);
val &= ~PERIPH_CLK_SOURCE_DIVU16_MASK;
val |= divider;
clk_writel(val, c->reg);
c->div = divider + 1;
c->mul = 1;
return 0;
}
} else if (parent_rate <= rate) {
c->div = 1;
c->mul = 1;
return 0;
}
return -EINVAL;
}
static long tegra20_periph_clk_round_rate(struct clk_hw *hw,
unsigned long rate, unsigned long *prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
unsigned long parent_rate = __clk_get_rate(__clk_get_parent(hw->clk));
int divider;
pr_debug("%s: %s %lu\n", __func__, __clk_get_name(hw->clk), rate);
if (prate)
parent_rate = *prate;
if (c->flags & DIV_U71) {
divider = clk_div71_get_divider(parent_rate, rate);
if (divider < 0)
return divider;
return DIV_ROUND_UP(parent_rate * 2, divider + 2);
} else if (c->flags & DIV_U16) {
divider = clk_div16_get_divider(parent_rate, rate);
if (divider < 0)
return divider;
return DIV_ROUND_UP(parent_rate, divider + 1);
}
return -EINVAL;
}
static void tegra20_emc_clk_init(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
c->max_rate = __clk_get_rate(hw->clk);
}
static long tegra20_emc_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
long emc_rate;
long clk_rate;
emc_rate = tegra_emc_round_rate(rate);
if (emc_rate < 0)
return c->max_rate;
clk_rate = tegra20_periph_clk_round_rate(hw, emc_rate, NULL);
WARN_ONCE(emc_rate != clk_rate,
"emc_rate %ld != clk_rate %ld",
emc_rate, clk_rate);
return emc_rate;
}
static int tegra20_emc_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
int ret;
ret = tegra_emc_set_rate(rate);
if (ret < 0)
return ret;
ret = tegra20_periph_clk_set_rate(hw, rate, parent_rate);
udelay(1);
return ret;
}
static int tegra20_clk_double_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
c->state = ON;
if (!c->u.periph.clk_num)
goto out;
if (!(clk_readl(CLK_OUT_ENB + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c)))
c->state = OFF;
out:
return c->state;
}
static unsigned long tegra20_clk_double_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct clk_tegra *c = to_clk_tegra(hw);
u64 rate = prate;
c->mul = 2;
c->div = 1;
rate *= c->mul;
rate += c->div - 1;
do_div(rate, c->div);
return rate;
}
static long tegra20_clk_double_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long output_rate = *prate;
do_div(output_rate, 2);
return output_rate;
}
static int tegra20_clk_double_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
if (rate != 2 * parent_rate)
return -EINVAL;
return 0;
}
static int tegra20_audio_sync_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg);
c->state = (val & (1<<4)) ? OFF : ON;
return c->state;
}
static int tegra20_audio_sync_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
clk_writel(0, c->reg);
return 0;
}
static void tegra20_audio_sync_clk_disable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
clk_writel(1, c->reg);
}
static u8 tegra20_audio_sync_clk_get_parent(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val = clk_readl(c->reg);
int source;
source = val & 0xf;
return source;
}
static int tegra20_audio_sync_clk_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_tegra *c = to_clk_tegra(hw);
u32 val;
val = clk_readl(c->reg);
val &= ~0xf;
val |= index;
clk_writel(val, c->reg);
return 0;
}
static int tegra20_cdev_clk_is_enabled(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
c->state = ON;
BUG_ON(!c->u.periph.clk_num);
if (!(clk_readl(CLK_OUT_ENB + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c)))
c->state = OFF;
return c->state;
}
static int tegra20_cdev_clk_enable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
BUG_ON(!c->u.periph.clk_num);
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
CLK_OUT_ENB_SET + PERIPH_CLK_TO_ENB_SET_REG(c));
return 0;
}
static void tegra20_cdev_clk_disable(struct clk_hw *hw)
{
struct clk_tegra *c = to_clk_tegra(hw);
BUG_ON(!c->u.periph.clk_num);
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
CLK_OUT_ENB_CLR + PERIPH_CLK_TO_ENB_SET_REG(c));
}
static unsigned long tegra20_cdev_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
return to_clk_tegra(hw)->fixed_rate;
}
static void tegra20_wait_cpu_in_reset(u32 cpu)
{
unsigned int reg;
do {
reg = readl(reg_clk_base +
TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET);
cpu_relax();
} while (!(reg & (1 << cpu)));
return;
}
static void tegra20_put_cpu_in_reset(u32 cpu)
{
writel(CPU_RESET(cpu),
reg_clk_base + TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET);
dmb();
}
static void tegra20_cpu_out_of_reset(u32 cpu)
{
writel(CPU_RESET(cpu),
reg_clk_base + TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_CLR);
wmb();
}
static void tegra20_enable_cpu_clock(u32 cpu)
{
unsigned int reg;
reg = readl(reg_clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
writel(reg & ~CPU_CLOCK(cpu),
reg_clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
barrier();
reg = readl(reg_clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
}
static void tegra20_disable_cpu_clock(u32 cpu)
{
unsigned int reg;
reg = readl(reg_clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
writel(reg | CPU_CLOCK(cpu),
reg_clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
}
void __init tegra20_cpu_car_ops_init(void)
{
tegra_cpu_car_ops = &tegra20_cpu_car_ops;
}
