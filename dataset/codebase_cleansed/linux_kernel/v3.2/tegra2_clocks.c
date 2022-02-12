unsigned long clk_measure_input_freq(void)
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
pr_err("%s: Unexpected clock autodetect value %d", __func__, clock_autodetect);
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
if (divider_u16 - 1 > 255)
return -EINVAL;
return divider_u16 - 1;
}
static unsigned long tegra2_clk_m_autodetect_rate(struct clk *c)
{
u32 auto_clock_control = clk_readl(OSC_CTRL) & ~OSC_CTRL_OSC_FREQ_MASK;
c->rate = clk_measure_input_freq();
switch (c->rate) {
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
pr_err("%s: Unexpected clock rate %ld", __func__, c->rate);
BUG();
}
clk_writel(auto_clock_control, OSC_CTRL);
return c->rate;
}
static void tegra2_clk_m_init(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
tegra2_clk_m_autodetect_rate(c);
}
static int tegra2_clk_m_enable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
return 0;
}
static void tegra2_clk_m_disable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
BUG();
}
void tegra2_periph_reset_assert(struct clk *c)
{
BUG_ON(!c->ops->reset);
c->ops->reset(c, true);
}
void tegra2_periph_reset_deassert(struct clk *c)
{
BUG_ON(!c->ops->reset);
c->ops->reset(c, false);
}
static void tegra2_super_clk_init(struct clk *c)
{
u32 val;
int source;
int shift;
const struct clk_mux_sel *sel;
val = clk_readl(c->reg + SUPER_CLK_MUX);
c->state = ON;
BUG_ON(((val & SUPER_STATE_MASK) != SUPER_STATE_RUN) &&
((val & SUPER_STATE_MASK) != SUPER_STATE_IDLE));
shift = ((val & SUPER_STATE_MASK) == SUPER_STATE_IDLE) ?
SUPER_IDLE_SOURCE_SHIFT : SUPER_RUN_SOURCE_SHIFT;
source = (val >> shift) & SUPER_SOURCE_MASK;
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->value == source)
break;
}
BUG_ON(sel->input == NULL);
c->parent = sel->input;
}
static int tegra2_super_clk_enable(struct clk *c)
{
clk_writel(0, c->reg + SUPER_CLK_DIVIDER);
return 0;
}
static void tegra2_super_clk_disable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
BUG();
}
static int tegra2_super_clk_set_parent(struct clk *c, struct clk *p)
{
u32 val;
const struct clk_mux_sel *sel;
int shift;
val = clk_readl(c->reg + SUPER_CLK_MUX);
BUG_ON(((val & SUPER_STATE_MASK) != SUPER_STATE_RUN) &&
((val & SUPER_STATE_MASK) != SUPER_STATE_IDLE));
shift = ((val & SUPER_STATE_MASK) == SUPER_STATE_IDLE) ?
SUPER_IDLE_SOURCE_SHIFT : SUPER_RUN_SOURCE_SHIFT;
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->input == p) {
val &= ~(SUPER_SOURCE_MASK << shift);
val |= sel->value << shift;
if (c->refcnt)
clk_enable(p);
clk_writel(val, c->reg);
if (c->refcnt && c->parent)
clk_disable(c->parent);
clk_reparent(c, p);
return 0;
}
}
return -EINVAL;
}
static int tegra2_super_clk_set_rate(struct clk *c, unsigned long rate)
{
return clk_set_rate(c->parent, rate);
}
static void tegra2_cpu_clk_init(struct clk *c)
{
}
static int tegra2_cpu_clk_enable(struct clk *c)
{
return 0;
}
static void tegra2_cpu_clk_disable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
BUG();
}
static int tegra2_cpu_clk_set_rate(struct clk *c, unsigned long rate)
{
int ret;
clk_enable(c->u.cpu.main);
ret = clk_set_parent(c->parent, c->u.cpu.backup);
if (ret) {
pr_err("Failed to switch cpu to clock %s\n", c->u.cpu.backup->name);
goto out;
}
if (rate == clk_get_rate(c->u.cpu.backup))
goto out;
ret = clk_set_rate(c->u.cpu.main, rate);
if (ret) {
pr_err("Failed to change cpu pll to %lu\n", rate);
goto out;
}
ret = clk_set_parent(c->parent, c->u.cpu.main);
if (ret) {
pr_err("Failed to switch cpu to clock %s\n", c->u.cpu.main->name);
goto out;
}
out:
clk_disable(c->u.cpu.main);
return ret;
}
static void tegra2_cop_clk_reset(struct clk *c, bool assert)
{
unsigned long reg = assert ? RST_DEVICES_SET : RST_DEVICES_CLR;
pr_debug("%s %s\n", __func__, assert ? "assert" : "deassert");
clk_writel(1 << 1, reg);
}
static void tegra2_bus_clk_init(struct clk *c)
{
u32 val = clk_readl(c->reg);
c->state = ((val >> c->reg_shift) & BUS_CLK_DISABLE) ? OFF : ON;
c->div = ((val >> c->reg_shift) & BUS_CLK_DIV_MASK) + 1;
c->mul = 1;
}
static int tegra2_bus_clk_enable(struct clk *c)
{
u32 val;
unsigned long flags;
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
val &= ~(BUS_CLK_DISABLE << c->reg_shift);
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
return 0;
}
static void tegra2_bus_clk_disable(struct clk *c)
{
u32 val;
unsigned long flags;
spin_lock_irqsave(&clock_register_lock, flags);
val = clk_readl(c->reg);
val |= BUS_CLK_DISABLE << c->reg_shift;
clk_writel(val, c->reg);
spin_unlock_irqrestore(&clock_register_lock, flags);
}
static int tegra2_bus_clk_set_rate(struct clk *c, unsigned long rate)
{
u32 val;
unsigned long parent_rate = clk_get_rate(c->parent);
unsigned long flags;
int ret = -EINVAL;
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
static void tegra2_blink_clk_init(struct clk *c)
{
u32 val;
val = pmc_readl(PMC_CTRL);
c->state = (val & PMC_CTRL_BLINK_ENB) ? ON : OFF;
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
}
static int tegra2_blink_clk_enable(struct clk *c)
{
u32 val;
val = pmc_readl(PMC_DPD_PADS_ORIDE);
pmc_writel(val | PMC_DPD_PADS_ORIDE_BLINK_ENB, PMC_DPD_PADS_ORIDE);
val = pmc_readl(PMC_CTRL);
pmc_writel(val | PMC_CTRL_BLINK_ENB, PMC_CTRL);
return 0;
}
static void tegra2_blink_clk_disable(struct clk *c)
{
u32 val;
val = pmc_readl(PMC_CTRL);
pmc_writel(val & ~PMC_CTRL_BLINK_ENB, PMC_CTRL);
val = pmc_readl(PMC_DPD_PADS_ORIDE);
pmc_writel(val & ~PMC_DPD_PADS_ORIDE_BLINK_ENB, PMC_DPD_PADS_ORIDE);
}
static int tegra2_blink_clk_set_rate(struct clk *c, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(c->parent);
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
static int tegra2_pll_clk_wait_for_lock(struct clk *c)
{
udelay(c->u.pll.lock_delay);
return 0;
}
static void tegra2_pll_clk_init(struct clk *c)
{
u32 val = clk_readl(c->reg + PLL_BASE);
c->state = (val & PLL_BASE_ENABLE) ? ON : OFF;
if (c->flags & PLL_FIXED && !(val & PLL_BASE_OVERRIDE)) {
pr_warning("Clock %s has unknown fixed frequency\n", c->name);
c->mul = 1;
c->div = 1;
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
}
static int tegra2_pll_clk_enable(struct clk *c)
{
u32 val;
pr_debug("%s on clock %s\n", __func__, c->name);
val = clk_readl(c->reg + PLL_BASE);
val &= ~PLL_BASE_BYPASS;
val |= PLL_BASE_ENABLE;
clk_writel(val, c->reg + PLL_BASE);
tegra2_pll_clk_wait_for_lock(c);
return 0;
}
static void tegra2_pll_clk_disable(struct clk *c)
{
u32 val;
pr_debug("%s on clock %s\n", __func__, c->name);
val = clk_readl(c->reg);
val &= ~(PLL_BASE_BYPASS | PLL_BASE_ENABLE);
clk_writel(val, c->reg);
}
static int tegra2_pll_clk_set_rate(struct clk *c, unsigned long rate)
{
u32 val;
unsigned long input_rate;
const struct clk_pll_freq_table *sel;
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
input_rate = clk_get_rate(c->parent);
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
tegra2_pll_clk_enable(c);
return 0;
}
}
return -EINVAL;
}
static void tegra2_pllx_clk_init(struct clk *c)
{
tegra2_pll_clk_init(c);
if (tegra_sku_id() == 7)
c->max_rate = 750000000;
}
static int tegra2_plle_clk_enable(struct clk *c)
{
u32 val;
pr_debug("%s on clock %s\n", __func__, c->name);
mdelay(1);
val = clk_readl(c->reg + PLL_BASE);
if (!(val & PLLE_MISC_READY))
return -EBUSY;
val = clk_readl(c->reg + PLL_BASE);
val |= PLL_BASE_ENABLE | PLL_BASE_BYPASS;
clk_writel(val, c->reg + PLL_BASE);
return 0;
}
static void tegra2_pll_div_clk_init(struct clk *c)
{
u32 val = clk_readl(c->reg);
u32 divu71;
val >>= c->reg_shift;
c->state = (val & PLL_OUT_CLKEN) ? ON : OFF;
if (!(val & PLL_OUT_RESET_DISABLE))
c->state = OFF;
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
}
static int tegra2_pll_div_clk_enable(struct clk *c)
{
u32 val;
u32 new_val;
unsigned long flags;
pr_debug("%s: %s\n", __func__, c->name);
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
static void tegra2_pll_div_clk_disable(struct clk *c)
{
u32 val;
u32 new_val;
unsigned long flags;
pr_debug("%s: %s\n", __func__, c->name);
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
static int tegra2_pll_div_clk_set_rate(struct clk *c, unsigned long rate)
{
u32 val;
u32 new_val;
int divider_u71;
unsigned long parent_rate = clk_get_rate(c->parent);
unsigned long flags;
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
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
static long tegra2_pll_div_clk_round_rate(struct clk *c, unsigned long rate)
{
int divider;
unsigned long parent_rate = clk_get_rate(c->parent);
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
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
static void tegra2_periph_clk_init(struct clk *c)
{
u32 val = clk_readl(c->reg);
const struct clk_mux_sel *mux = NULL;
const struct clk_mux_sel *sel;
if (c->flags & MUX) {
for (sel = c->inputs; sel->input != NULL; sel++) {
if (val >> PERIPH_CLK_SOURCE_SHIFT == sel->value)
mux = sel;
}
BUG_ON(!mux);
c->parent = mux->input;
} else {
c->parent = c->inputs[0].input;
}
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
}
c->state = ON;
if (!c->u.periph.clk_num)
return;
if (!(clk_readl(CLK_OUT_ENB + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c)))
c->state = OFF;
if (!(c->flags & PERIPH_NO_RESET))
if (clk_readl(RST_DEVICES + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c))
c->state = OFF;
}
static int tegra2_periph_clk_enable(struct clk *c)
{
u32 val;
unsigned long flags;
int refcount;
pr_debug("%s on clock %s\n", __func__, c->name);
if (!c->u.periph.clk_num)
return 0;
spin_lock_irqsave(&clock_register_lock, flags);
refcount = tegra_periph_clk_enable_refcount[c->u.periph.clk_num]++;
if (refcount > 1)
goto out;
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
out:
spin_unlock_irqrestore(&clock_register_lock, flags);
return 0;
}
static void tegra2_periph_clk_disable(struct clk *c)
{
unsigned long flags;
pr_debug("%s on clock %s\n", __func__, c->name);
if (!c->u.periph.clk_num)
return;
spin_lock_irqsave(&clock_register_lock, flags);
if (c->refcnt)
tegra_periph_clk_enable_refcount[c->u.periph.clk_num]--;
if (tegra_periph_clk_enable_refcount[c->u.periph.clk_num] == 0)
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
CLK_OUT_ENB_CLR + PERIPH_CLK_TO_ENB_SET_REG(c));
spin_unlock_irqrestore(&clock_register_lock, flags);
}
static void tegra2_periph_clk_reset(struct clk *c, bool assert)
{
unsigned long base = assert ? RST_DEVICES_SET : RST_DEVICES_CLR;
pr_debug("%s %s on clock %s\n", __func__,
assert ? "assert" : "deassert", c->name);
BUG_ON(!c->u.periph.clk_num);
if (!(c->flags & PERIPH_NO_RESET))
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
base + PERIPH_CLK_TO_ENB_SET_REG(c));
}
static int tegra2_periph_clk_set_parent(struct clk *c, struct clk *p)
{
u32 val;
const struct clk_mux_sel *sel;
pr_debug("%s: %s %s\n", __func__, c->name, p->name);
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->input == p) {
val = clk_readl(c->reg);
val &= ~PERIPH_CLK_SOURCE_MASK;
val |= (sel->value) << PERIPH_CLK_SOURCE_SHIFT;
if (c->refcnt)
clk_enable(p);
clk_writel(val, c->reg);
if (c->refcnt && c->parent)
clk_disable(c->parent);
clk_reparent(c, p);
return 0;
}
}
return -EINVAL;
}
static int tegra2_periph_clk_set_rate(struct clk *c, unsigned long rate)
{
u32 val;
int divider;
unsigned long parent_rate = clk_get_rate(c->parent);
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
static long tegra2_periph_clk_round_rate(struct clk *c,
unsigned long rate)
{
int divider;
unsigned long parent_rate = clk_get_rate(c->parent);
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
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
void tegra2_sdmmc_tap_delay(struct clk *c, int delay)
{
u32 reg;
delay = clamp(delay, 0, 15);
reg = clk_readl(c->reg);
reg &= ~SDMMC_CLK_INT_FB_DLY_MASK;
reg |= SDMMC_CLK_INT_FB_SEL;
reg |= delay << SDMMC_CLK_INT_FB_DLY_SHIFT;
clk_writel(reg, c->reg);
}
static void tegra2_emc_clk_init(struct clk *c)
{
tegra2_periph_clk_init(c);
c->max_rate = clk_get_rate_locked(c);
}
static long tegra2_emc_clk_round_rate(struct clk *c, unsigned long rate)
{
long new_rate = rate;
new_rate = tegra_emc_round_rate(new_rate);
if (new_rate < 0)
return c->max_rate;
BUG_ON(new_rate != tegra2_periph_clk_round_rate(c, new_rate));
return new_rate;
}
static int tegra2_emc_clk_set_rate(struct clk *c, unsigned long rate)
{
int ret;
ret = tegra_emc_set_rate(rate);
if (ret < 0)
return ret;
ret = tegra2_periph_clk_set_rate(c, rate);
udelay(1);
return ret;
}
static void tegra2_clk_double_init(struct clk *c)
{
c->mul = 2;
c->div = 1;
c->state = ON;
if (!c->u.periph.clk_num)
return;
if (!(clk_readl(CLK_OUT_ENB + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c)))
c->state = OFF;
}
static int tegra2_clk_double_set_rate(struct clk *c, unsigned long rate)
{
if (rate != 2 * clk_get_rate(c->parent))
return -EINVAL;
c->mul = 2;
c->div = 1;
return 0;
}
static void tegra2_audio_sync_clk_init(struct clk *c)
{
int source;
const struct clk_mux_sel *sel;
u32 val = clk_readl(c->reg);
c->state = (val & (1<<4)) ? OFF : ON;
source = val & 0xf;
for (sel = c->inputs; sel->input != NULL; sel++)
if (sel->value == source)
break;
BUG_ON(sel->input == NULL);
c->parent = sel->input;
}
static int tegra2_audio_sync_clk_enable(struct clk *c)
{
clk_writel(0, c->reg);
return 0;
}
static void tegra2_audio_sync_clk_disable(struct clk *c)
{
clk_writel(1, c->reg);
}
static int tegra2_audio_sync_clk_set_parent(struct clk *c, struct clk *p)
{
u32 val;
const struct clk_mux_sel *sel;
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->input == p) {
val = clk_readl(c->reg);
val &= ~0xf;
val |= sel->value;
if (c->refcnt)
clk_enable(p);
clk_writel(val, c->reg);
if (c->refcnt && c->parent)
clk_disable(c->parent);
clk_reparent(c, p);
return 0;
}
}
return -EINVAL;
}
static void tegra2_cdev_clk_init(struct clk *c)
{
c->state = ON;
BUG_ON(!c->u.periph.clk_num);
if (!(clk_readl(CLK_OUT_ENB + PERIPH_CLK_TO_ENB_REG(c)) &
PERIPH_CLK_TO_ENB_BIT(c)))
c->state = OFF;
}
static int tegra2_cdev_clk_enable(struct clk *c)
{
BUG_ON(!c->u.periph.clk_num);
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
CLK_OUT_ENB_SET + PERIPH_CLK_TO_ENB_SET_REG(c));
return 0;
}
static void tegra2_cdev_clk_disable(struct clk *c)
{
BUG_ON(!c->u.periph.clk_num);
clk_writel(PERIPH_CLK_TO_ENB_BIT(c),
CLK_OUT_ENB_CLR + PERIPH_CLK_TO_ENB_SET_REG(c));
}
static int tegra_clk_shared_bus_update(struct clk *bus)
{
struct clk *c;
unsigned long rate = bus->min_rate;
list_for_each_entry(c, &bus->shared_bus_list, u.shared_bus_user.node)
if (c->u.shared_bus_user.enabled)
rate = max(c->u.shared_bus_user.rate, rate);
if (rate == clk_get_rate_locked(bus))
return 0;
return clk_set_rate_locked(bus, rate);
}
static void tegra_clk_shared_bus_init(struct clk *c)
{
unsigned long flags;
c->max_rate = c->parent->max_rate;
c->u.shared_bus_user.rate = c->parent->max_rate;
c->state = OFF;
c->set = true;
spin_lock_irqsave(&c->parent->spinlock, flags);
list_add_tail(&c->u.shared_bus_user.node,
&c->parent->shared_bus_list);
spin_unlock_irqrestore(&c->parent->spinlock, flags);
}
static int tegra_clk_shared_bus_set_rate(struct clk *c, unsigned long rate)
{
unsigned long flags;
int ret;
long new_rate = rate;
new_rate = clk_round_rate(c->parent, new_rate);
if (new_rate < 0)
return new_rate;
spin_lock_irqsave(&c->parent->spinlock, flags);
c->u.shared_bus_user.rate = new_rate;
ret = tegra_clk_shared_bus_update(c->parent);
spin_unlock_irqrestore(&c->parent->spinlock, flags);
return ret;
}
static long tegra_clk_shared_bus_round_rate(struct clk *c, unsigned long rate)
{
return clk_round_rate(c->parent, rate);
}
static int tegra_clk_shared_bus_enable(struct clk *c)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&c->parent->spinlock, flags);
c->u.shared_bus_user.enabled = true;
ret = tegra_clk_shared_bus_update(c->parent);
spin_unlock_irqrestore(&c->parent->spinlock, flags);
return ret;
}
static void tegra_clk_shared_bus_disable(struct clk *c)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&c->parent->spinlock, flags);
c->u.shared_bus_user.enabled = false;
ret = tegra_clk_shared_bus_update(c->parent);
WARN_ON_ONCE(ret);
spin_unlock_irqrestore(&c->parent->spinlock, flags);
}
static void init_audio_sync_clock_mux(void)
{
int i;
struct clk_mux_sel *sel = mux_audio_sync_clk;
const struct audio_sources *src = mux_audio_sync_clk_sources;
struct clk_lookup *lookup;
for (i = 0; src->name; i++, sel++, src++) {
sel->input = tegra_get_clock_by_name(src->name);
if (!sel->input)
pr_err("%s: could not find clk %s\n", __func__,
src->name);
sel->value = src->value;
}
lookup = tegra_audio_clk_lookups;
for (i = 0; i < ARRAY_SIZE(tegra_audio_clk_lookups); i++, lookup++) {
clk_init(lookup->clk);
clkdev_add(lookup);
}
}
static void tegra2_init_one_clock(struct clk *c)
{
clk_init(c);
INIT_LIST_HEAD(&c->shared_bus_list);
if (!c->lookup.dev_id && !c->lookup.con_id)
c->lookup.con_id = c->name;
c->lookup.clk = c;
clkdev_add(&c->lookup);
}
void __init tegra2_init_clocks(void)
{
int i;
struct clk *c;
for (i = 0; i < ARRAY_SIZE(tegra_ptr_clks); i++)
tegra2_init_one_clock(tegra_ptr_clks[i]);
for (i = 0; i < ARRAY_SIZE(tegra_list_clks); i++)
tegra2_init_one_clock(&tegra_list_clks[i]);
for (i = 0; i < ARRAY_SIZE(tegra_clk_duplicates); i++) {
c = tegra_get_clock_by_name(tegra_clk_duplicates[i].name);
if (!c) {
pr_err("%s: Unknown duplicate clock %s\n", __func__,
tegra_clk_duplicates[i].name);
continue;
}
tegra_clk_duplicates[i].lookup.clk = c;
clkdev_add(&tegra_clk_duplicates[i].lookup);
}
init_audio_sync_clock_mux();
}
void tegra_clk_suspend(void)
{
unsigned long off, i;
u32 *ctx = clk_rst_suspend;
*ctx++ = clk_readl(OSC_CTRL) & OSC_CTRL_MASK;
*ctx++ = clk_readl(tegra_pll_c.reg + PLL_BASE);
*ctx++ = clk_readl(tegra_pll_c.reg + PLL_MISC(&tegra_pll_c));
*ctx++ = clk_readl(tegra_pll_a.reg + PLL_BASE);
*ctx++ = clk_readl(tegra_pll_a.reg + PLL_MISC(&tegra_pll_a));
*ctx++ = clk_readl(tegra_pll_s.reg + PLL_BASE);
*ctx++ = clk_readl(tegra_pll_s.reg + PLL_MISC(&tegra_pll_s));
*ctx++ = clk_readl(tegra_pll_d.reg + PLL_BASE);
*ctx++ = clk_readl(tegra_pll_d.reg + PLL_MISC(&tegra_pll_d));
*ctx++ = clk_readl(tegra_pll_u.reg + PLL_BASE);
*ctx++ = clk_readl(tegra_pll_u.reg + PLL_MISC(&tegra_pll_u));
*ctx++ = clk_readl(tegra_pll_m_out1.reg);
*ctx++ = clk_readl(tegra_pll_a_out0.reg);
*ctx++ = clk_readl(tegra_pll_c_out1.reg);
*ctx++ = clk_readl(tegra_clk_cclk.reg);
*ctx++ = clk_readl(tegra_clk_cclk.reg + SUPER_CLK_DIVIDER);
*ctx++ = clk_readl(tegra_clk_sclk.reg);
*ctx++ = clk_readl(tegra_clk_sclk.reg + SUPER_CLK_DIVIDER);
*ctx++ = clk_readl(tegra_clk_pclk.reg);
*ctx++ = clk_readl(tegra_clk_audio.reg);
for (off = PERIPH_CLK_SOURCE_I2S1; off <= PERIPH_CLK_SOURCE_OSC;
off += 4) {
if (off == PERIPH_CLK_SOURCE_EMC)
continue;
*ctx++ = clk_readl(off);
}
off = RST_DEVICES;
for (i = 0; i < RST_DEVICES_NUM; i++, off += 4)
*ctx++ = clk_readl(off);
off = CLK_OUT_ENB;
for (i = 0; i < CLK_OUT_ENB_NUM; i++, off += 4)
*ctx++ = clk_readl(off);
*ctx++ = clk_readl(MISC_CLK_ENB);
*ctx++ = clk_readl(CLK_MASK_ARM);
BUG_ON(ctx - clk_rst_suspend != ARRAY_SIZE(clk_rst_suspend));
}
void tegra_clk_resume(void)
{
unsigned long off, i;
const u32 *ctx = clk_rst_suspend;
u32 val;
val = clk_readl(OSC_CTRL) & ~OSC_CTRL_MASK;
val |= *ctx++;
clk_writel(val, OSC_CTRL);
clk_writel(*ctx++, tegra_pll_c.reg + PLL_BASE);
clk_writel(*ctx++, tegra_pll_c.reg + PLL_MISC(&tegra_pll_c));
clk_writel(*ctx++, tegra_pll_a.reg + PLL_BASE);
clk_writel(*ctx++, tegra_pll_a.reg + PLL_MISC(&tegra_pll_a));
clk_writel(*ctx++, tegra_pll_s.reg + PLL_BASE);
clk_writel(*ctx++, tegra_pll_s.reg + PLL_MISC(&tegra_pll_s));
clk_writel(*ctx++, tegra_pll_d.reg + PLL_BASE);
clk_writel(*ctx++, tegra_pll_d.reg + PLL_MISC(&tegra_pll_d));
clk_writel(*ctx++, tegra_pll_u.reg + PLL_BASE);
clk_writel(*ctx++, tegra_pll_u.reg + PLL_MISC(&tegra_pll_u));
udelay(1000);
clk_writel(*ctx++, tegra_pll_m_out1.reg);
clk_writel(*ctx++, tegra_pll_a_out0.reg);
clk_writel(*ctx++, tegra_pll_c_out1.reg);
clk_writel(*ctx++, tegra_clk_cclk.reg);
clk_writel(*ctx++, tegra_clk_cclk.reg + SUPER_CLK_DIVIDER);
clk_writel(*ctx++, tegra_clk_sclk.reg);
clk_writel(*ctx++, tegra_clk_sclk.reg + SUPER_CLK_DIVIDER);
clk_writel(*ctx++, tegra_clk_pclk.reg);
clk_writel(*ctx++, tegra_clk_audio.reg);
clk_writel(0xbffffff9ul, CLK_OUT_ENB);
clk_writel(0xfefffff7ul, CLK_OUT_ENB + 4);
clk_writel(0x77f01bfful, CLK_OUT_ENB + 8);
wmb();
for (off = PERIPH_CLK_SOURCE_I2S1; off <= PERIPH_CLK_SOURCE_OSC;
off += 4) {
if (off == PERIPH_CLK_SOURCE_EMC)
continue;
clk_writel(*ctx++, off);
}
wmb();
off = RST_DEVICES;
for (i = 0; i < RST_DEVICES_NUM; i++, off += 4)
clk_writel(*ctx++, off);
wmb();
off = CLK_OUT_ENB;
for (i = 0; i < CLK_OUT_ENB_NUM; i++, off += 4)
clk_writel(*ctx++, off);
wmb();
clk_writel(*ctx++, MISC_CLK_ENB);
clk_writel(*ctx++, CLK_MASK_ARM);
}
