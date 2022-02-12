static inline int clk_set_div(struct clk *c, u32 n)
{
return clk_set_rate(c, (clk_get_rate(c->parent) + n-1) / n);
}
static inline u32 periph_clk_to_reg(
struct clk *c, u32 reg_L, u32 reg_V, int offs)
{
u32 reg = c->u.periph.clk_num / 32;
BUG_ON(reg >= RST_DEVICES_NUM);
if (reg < 3)
reg = reg_L + (reg * offs);
else
reg = reg_V + ((reg - 3) * offs);
return reg;
}
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
} else if (clock_autodetect >= 1025 - 3 && clock_autodetect <= 1025 + 3) {
return 16800000;
} else if (clock_autodetect >= 2344 - 3 && clock_autodetect <= 2344 + 3) {
return 38400000;
} else if (clock_autodetect >= 2928 - 3 && clock_autodetect <= 2928 + 3) {
return 48000000;
} else {
pr_err("%s: Unexpected clock autodetect value %d", __func__,
clock_autodetect);
BUG();
return 0;
}
}
static int clk_div71_get_divider(unsigned long parent_rate, unsigned long rate,
u32 flags, u32 round_mode)
{
s64 divider_u71 = parent_rate;
if (!rate)
return -EINVAL;
if (!(flags & DIV_U71_INT))
divider_u71 *= 2;
if (round_mode == ROUND_DIVIDER_UP)
divider_u71 += rate - 1;
do_div(divider_u71, rate);
if (flags & DIV_U71_INT)
divider_u71 *= 2;
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
if (!rate)
return -EINVAL;
divider_u16 += rate - 1;
do_div(divider_u16, rate);
if (divider_u16 - 1 < 0)
return 0;
if (divider_u16 - 1 > 0xFFFF)
return -EINVAL;
return divider_u16 - 1;
}
static unsigned long tegra30_clk_m_autodetect_rate(struct clk *c)
{
u32 osc_ctrl = clk_readl(OSC_CTRL);
u32 auto_clock_control = osc_ctrl & ~OSC_CTRL_OSC_FREQ_MASK;
u32 pll_ref_div = osc_ctrl & OSC_CTRL_PLL_REF_DIV_MASK;
c->rate = clk_measure_input_freq();
switch (c->rate) {
case 12000000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_12MHZ;
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
break;
case 13000000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_13MHZ;
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
break;
case 19200000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_19_2MHZ;
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
break;
case 26000000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_26MHZ;
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
break;
case 16800000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_16_8MHZ;
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
break;
case 38400000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_38_4MHZ;
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_2);
break;
case 48000000:
auto_clock_control |= OSC_CTRL_OSC_FREQ_48MHZ;
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_4);
break;
default:
pr_err("%s: Unexpected clock rate %ld", __func__, c->rate);
BUG();
}
clk_writel(auto_clock_control, OSC_CTRL);
return c->rate;
}
static void tegra30_clk_m_init(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
tegra30_clk_m_autodetect_rate(c);
}
static int tegra30_clk_m_enable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
return 0;
}
static void tegra30_clk_m_disable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
WARN(1, "Attempting to disable main SoC clock\n");
}
static void tegra30_pll_ref_init(struct clk *c)
{
u32 pll_ref_div = clk_readl(OSC_CTRL) & OSC_CTRL_PLL_REF_DIV_MASK;
pr_debug("%s on clock %s\n", __func__, c->name);
switch (pll_ref_div) {
case OSC_CTRL_PLL_REF_DIV_1:
c->div = 1;
break;
case OSC_CTRL_PLL_REF_DIV_2:
c->div = 2;
break;
case OSC_CTRL_PLL_REF_DIV_4:
c->div = 4;
break;
default:
pr_err("%s: Invalid pll ref divider %d", __func__, pll_ref_div);
BUG();
}
c->mul = 1;
c->state = ON;
}
static void tegra30_super_clk_init(struct clk *c)
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
if (c->flags & DIV_2)
source |= val & SUPER_LP_DIV2_BYPASS;
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->value == source)
break;
}
BUG_ON(sel->input == NULL);
c->parent = sel->input;
if (c->flags & DIV_U71) {
clk_writel(SUPER_CLOCK_DIV_U71_MIN << SUPER_CLOCK_DIV_U71_SHIFT,
c->reg + SUPER_CLK_DIVIDER);
c->mul = 2;
c->div = 2;
if (!(c->parent->flags & PLLX))
c->div += SUPER_CLOCK_DIV_U71_MIN;
} else
clk_writel(0, c->reg + SUPER_CLK_DIVIDER);
}
static int tegra30_super_clk_enable(struct clk *c)
{
return 0;
}
static void tegra30_super_clk_disable(struct clk *c)
{
}
static int tegra30_super_clk_set_parent(struct clk *c, struct clk *p)
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
if ((c->flags & DIV_2) && (p->flags & PLLX) &&
((sel->value ^ val) & SUPER_LP_DIV2_BYPASS)) {
if (c->parent->flags & PLLX)
return -EINVAL;
val ^= SUPER_LP_DIV2_BYPASS;
clk_writel_delay(val, c->reg);
}
val &= ~(SUPER_SOURCE_MASK << shift);
val |= (sel->value & SUPER_SOURCE_MASK) << shift;
if (c->flags & DIV_U71) {
u32 div = 0;
if (!(p->flags & PLLX)) {
div = clk_readl(c->reg +
SUPER_CLK_DIVIDER);
div &= SUPER_CLOCK_DIV_U71_MASK;
div >>= SUPER_CLOCK_DIV_U71_SHIFT;
}
c->div = div + 2;
c->mul = 2;
}
if (c->refcnt)
clk_enable(p);
clk_writel_delay(val, c->reg);
if (c->refcnt && c->parent)
clk_disable(c->parent);
clk_reparent(c, p);
return 0;
}
}
return -EINVAL;
}
static int tegra30_super_clk_set_rate(struct clk *c, unsigned long rate)
{
if ((c->flags & DIV_U71) && (c->parent->flags & PLL_FIXED)) {
int div = clk_div71_get_divider(c->parent->u.pll.fixed_rate,
rate, c->flags, ROUND_DIVIDER_DOWN);
div = max(div, SUPER_CLOCK_DIV_U71_MIN);
clk_writel(div << SUPER_CLOCK_DIV_U71_SHIFT,
c->reg + SUPER_CLK_DIVIDER);
c->div = div + 2;
c->mul = 2;
return 0;
}
return clk_set_rate(c->parent, rate);
}
static int tegra30_twd_clk_set_rate(struct clk *c, unsigned long rate)
{
c->rate = (rate * c->mul) / c->div;
return 0;
}
static void tegra30_blink_clk_init(struct clk *c)
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
static int tegra30_blink_clk_enable(struct clk *c)
{
u32 val;
val = pmc_readl(PMC_DPD_PADS_ORIDE);
pmc_writel(val | PMC_DPD_PADS_ORIDE_BLINK_ENB, PMC_DPD_PADS_ORIDE);
val = pmc_readl(PMC_CTRL);
pmc_writel(val | PMC_CTRL_BLINK_ENB, PMC_CTRL);
return 0;
}
static void tegra30_blink_clk_disable(struct clk *c)
{
u32 val;
val = pmc_readl(PMC_CTRL);
pmc_writel(val & ~PMC_CTRL_BLINK_ENB, PMC_CTRL);
val = pmc_readl(PMC_DPD_PADS_ORIDE);
pmc_writel(val & ~PMC_DPD_PADS_ORIDE_BLINK_ENB, PMC_DPD_PADS_ORIDE);
}
static int tegra30_blink_clk_set_rate(struct clk *c, unsigned long rate)
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
static int tegra30_pll_clk_wait_for_lock(struct clk *c, u32 lock_reg,
u32 lock_bit)
{
#if USE_PLL_LOCK_BITS
int i;
for (i = 0; i < c->u.pll.lock_delay; i++) {
if (clk_readl(lock_reg) & lock_bit) {
udelay(PLL_POST_LOCK_DELAY);
return 0;
}
udelay(2);
}
pr_err("Timed out waiting for lock bit on pll %s", c->name);
return -1;
#endif
udelay(c->u.pll.lock_delay);
return 0;
}
static void tegra30_utmi_param_configure(struct clk *c)
{
u32 reg;
int i;
unsigned long main_rate =
clk_get_rate(c->parent->parent);
for (i = 0; i < ARRAY_SIZE(utmi_parameters); i++) {
if (main_rate == utmi_parameters[i].osc_frequency)
break;
}
if (i >= ARRAY_SIZE(utmi_parameters)) {
pr_err("%s: Unexpected main rate %lu\n", __func__, main_rate);
return;
}
reg = clk_readl(UTMIP_PLL_CFG2);
reg &= ~UTMIP_PLL_CFG2_STABLE_COUNT(~0);
reg |= UTMIP_PLL_CFG2_STABLE_COUNT(
utmi_parameters[i].stable_count);
reg &= ~UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(~0);
reg |= UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(
utmi_parameters[i].active_delay_count);
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_A_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_B_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_C_POWERDOWN;
clk_writel(reg, UTMIP_PLL_CFG2);
reg = clk_readl(UTMIP_PLL_CFG1);
reg &= ~UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(~0);
reg |= UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(
utmi_parameters[i].enable_delay_count);
reg &= ~UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(~0);
reg |= UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(
utmi_parameters[i].xtal_freq_count);
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERDOWN;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ACTIVE_POWERDOWN;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLLU_POWERDOWN;
clk_writel(reg, UTMIP_PLL_CFG1);
}
static void tegra30_pll_clk_init(struct clk *c)
{
u32 val = clk_readl(c->reg + PLL_BASE);
c->state = (val & PLL_BASE_ENABLE) ? ON : OFF;
if (c->flags & PLL_FIXED && !(val & PLL_BASE_OVERRIDE)) {
const struct clk_pll_freq_table *sel;
unsigned long input_rate = clk_get_rate(c->parent);
for (sel = c->u.pll.freq_table; sel->input_rate != 0; sel++) {
if (sel->input_rate == input_rate &&
sel->output_rate == c->u.pll.fixed_rate) {
c->mul = sel->n;
c->div = sel->m * sel->p;
return;
}
}
pr_err("Clock %s has unknown fixed frequency\n", c->name);
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
c->div *= (0x1 << ((val & PLL_BASE_DIVP_MASK) >>
PLL_BASE_DIVP_SHIFT));
if (c->flags & PLL_FIXED) {
unsigned long rate = clk_get_rate_locked(c);
BUG_ON(rate != c->u.pll.fixed_rate);
}
}
if (c->flags & PLLU)
tegra30_utmi_param_configure(c);
}
static int tegra30_pll_clk_enable(struct clk *c)
{
u32 val;
pr_debug("%s on clock %s\n", __func__, c->name);
#if USE_PLL_LOCK_BITS
val = clk_readl(c->reg + PLL_MISC(c));
val |= PLL_MISC_LOCK_ENABLE(c);
clk_writel(val, c->reg + PLL_MISC(c));
#endif
val = clk_readl(c->reg + PLL_BASE);
val &= ~PLL_BASE_BYPASS;
val |= PLL_BASE_ENABLE;
clk_writel(val, c->reg + PLL_BASE);
if (c->flags & PLLM) {
val = pmc_readl(PMC_PLLP_WB0_OVERRIDE);
val |= PMC_PLLP_WB0_OVERRIDE_PLLM_ENABLE;
pmc_writel(val, PMC_PLLP_WB0_OVERRIDE);
}
tegra30_pll_clk_wait_for_lock(c, c->reg + PLL_BASE, PLL_BASE_LOCK);
return 0;
}
static void tegra30_pll_clk_disable(struct clk *c)
{
u32 val;
pr_debug("%s on clock %s\n", __func__, c->name);
val = clk_readl(c->reg);
val &= ~(PLL_BASE_BYPASS | PLL_BASE_ENABLE);
clk_writel(val, c->reg);
if (c->flags & PLLM) {
val = pmc_readl(PMC_PLLP_WB0_OVERRIDE);
val &= ~PMC_PLLP_WB0_OVERRIDE_PLLM_ENABLE;
pmc_writel(val, PMC_PLLP_WB0_OVERRIDE);
}
}
static int tegra30_pll_clk_set_rate(struct clk *c, unsigned long rate)
{
u32 val, p_div, old_base;
unsigned long input_rate;
const struct clk_pll_freq_table *sel;
struct clk_pll_freq_table cfg;
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
if (c->flags & PLL_FIXED) {
int ret = 0;
if (rate != c->u.pll.fixed_rate) {
pr_err("%s: Can not change %s fixed rate %lu to %lu\n",
__func__, c->name, c->u.pll.fixed_rate, rate);
ret = -EINVAL;
}
return ret;
}
if (c->flags & PLLM) {
if (rate != clk_get_rate_locked(c)) {
pr_err("%s: Can not change memory %s rate in flight\n",
__func__, c->name);
return -EINVAL;
}
return 0;
}
p_div = 0;
input_rate = clk_get_rate(c->parent);
for (sel = c->u.pll.freq_table; sel->input_rate != 0; sel++) {
if (sel->input_rate == input_rate && sel->output_rate == rate) {
if (c->flags & PLLU) {
BUG_ON(sel->p < 1 || sel->p > 2);
if (sel->p == 1)
p_div = PLLU_BASE_POST_DIV;
} else {
BUG_ON(sel->p < 1);
for (val = sel->p; val > 1; val >>= 1)
p_div++;
p_div <<= PLL_BASE_DIVP_SHIFT;
}
break;
}
}
if (sel->input_rate == 0) {
unsigned long cfreq;
BUG_ON(c->flags & PLLU);
sel = &cfg;
switch (input_rate) {
case 12000000:
case 26000000:
cfreq = (rate <= 1000000 * 1000) ? 1000000 : 2000000;
break;
case 13000000:
cfreq = (rate <= 1000000 * 1000) ? 1000000 : 2600000;
break;
case 16800000:
case 19200000:
cfreq = (rate <= 1200000 * 1000) ? 1200000 : 2400000;
break;
default:
pr_err("%s: Unexpected reference rate %lu\n",
__func__, input_rate);
BUG();
}
for (cfg.output_rate = rate; cfg.output_rate < 200 * cfreq;
cfg.output_rate <<= 1)
p_div++;
cfg.p = 0x1 << p_div;
cfg.m = input_rate / cfreq;
cfg.n = cfg.output_rate / cfreq;
cfg.cpcon = OUT_OF_TABLE_CPCON;
if ((cfg.m > (PLL_BASE_DIVM_MASK >> PLL_BASE_DIVM_SHIFT)) ||
(cfg.n > (PLL_BASE_DIVN_MASK >> PLL_BASE_DIVN_SHIFT)) ||
(p_div > (PLL_BASE_DIVP_MASK >> PLL_BASE_DIVP_SHIFT)) ||
(cfg.output_rate > c->u.pll.vco_max)) {
pr_err("%s: Failed to set %s out-of-table rate %lu\n",
__func__, c->name, rate);
return -EINVAL;
}
p_div <<= PLL_BASE_DIVP_SHIFT;
}
c->mul = sel->n;
c->div = sel->m * sel->p;
old_base = val = clk_readl(c->reg + PLL_BASE);
val &= ~(PLL_BASE_DIVM_MASK | PLL_BASE_DIVN_MASK |
((c->flags & PLLU) ? PLLU_BASE_POST_DIV : PLL_BASE_DIVP_MASK));
val |= (sel->m << PLL_BASE_DIVM_SHIFT) |
(sel->n << PLL_BASE_DIVN_SHIFT) | p_div;
if (val == old_base)
return 0;
if (c->state == ON) {
tegra30_pll_clk_disable(c);
val &= ~(PLL_BASE_BYPASS | PLL_BASE_ENABLE);
}
clk_writel(val, c->reg + PLL_BASE);
if (c->flags & PLL_HAS_CPCON) {
val = clk_readl(c->reg + PLL_MISC(c));
val &= ~PLL_MISC_CPCON_MASK;
val |= sel->cpcon << PLL_MISC_CPCON_SHIFT;
if (c->flags & (PLLU | PLLD)) {
val &= ~PLL_MISC_LFCON_MASK;
if (sel->n >= PLLDU_LFCON_SET_DIVN)
val |= 0x1 << PLL_MISC_LFCON_SHIFT;
} else if (c->flags & (PLLX | PLLM)) {
val &= ~(0x1 << PLL_MISC_DCCON_SHIFT);
if (rate >= (c->u.pll.vco_max >> 1))
val |= 0x1 << PLL_MISC_DCCON_SHIFT;
}
clk_writel(val, c->reg + PLL_MISC(c));
}
if (c->state == ON)
tegra30_pll_clk_enable(c);
return 0;
}
static int
tegra30_plld_clk_cfg_ex(struct clk *c, enum tegra_clk_ex_param p, u32 setting)
{
u32 val, mask, reg;
switch (p) {
case TEGRA_CLK_PLLD_CSI_OUT_ENB:
mask = PLLD_BASE_CSI_CLKENABLE;
reg = c->reg + PLL_BASE;
break;
case TEGRA_CLK_PLLD_DSI_OUT_ENB:
mask = PLLD_MISC_DSI_CLKENABLE;
reg = c->reg + PLL_MISC(c);
break;
case TEGRA_CLK_PLLD_MIPI_MUX_SEL:
if (!(c->flags & PLL_ALT_MISC_REG)) {
mask = PLLD_BASE_DSIB_MUX_MASK;
reg = c->reg + PLL_BASE;
break;
}
default:
return -EINVAL;
}
val = clk_readl(reg);
if (setting)
val |= mask;
else
val &= ~mask;
clk_writel(val, reg);
return 0;
}
static void tegra30_plle_clk_init(struct clk *c)
{
u32 val;
val = clk_readl(PLLE_AUX);
c->parent = (val & PLLE_AUX_PLLP_SEL) ?
tegra_get_clock_by_name("pll_p") :
tegra_get_clock_by_name("pll_ref");
val = clk_readl(c->reg + PLL_BASE);
c->state = (val & PLLE_BASE_ENABLE) ? ON : OFF;
c->mul = (val & PLLE_BASE_DIVN_MASK) >> PLLE_BASE_DIVN_SHIFT;
c->div = (val & PLLE_BASE_DIVM_MASK) >> PLLE_BASE_DIVM_SHIFT;
c->div *= (val & PLLE_BASE_DIVP_MASK) >> PLLE_BASE_DIVP_SHIFT;
}
static void tegra30_plle_clk_disable(struct clk *c)
{
u32 val;
pr_debug("%s on clock %s\n", __func__, c->name);
val = clk_readl(c->reg + PLL_BASE);
val &= ~(PLLE_BASE_CML_ENABLE | PLLE_BASE_ENABLE);
clk_writel(val, c->reg + PLL_BASE);
}
static void tegra30_plle_training(struct clk *c)
{
u32 val;
val = pmc_readl(PMC_SATA_PWRGT);
val |= PMC_SATA_PWRGT_PLLE_IDDQ_VALUE;
pmc_writel(val, PMC_SATA_PWRGT);
val = pmc_readl(PMC_SATA_PWRGT);
val |= PMC_SATA_PWRGT_PLLE_IDDQ_SWCTL;
pmc_writel(val, PMC_SATA_PWRGT);
val = pmc_readl(PMC_SATA_PWRGT);
val &= ~PMC_SATA_PWRGT_PLLE_IDDQ_VALUE;
pmc_writel(val, PMC_SATA_PWRGT);
do {
val = clk_readl(c->reg + PLL_MISC(c));
} while (!(val & PLLE_MISC_READY));
}
static int tegra30_plle_configure(struct clk *c, bool force_training)
{
u32 val;
const struct clk_pll_freq_table *sel;
unsigned long rate = c->u.pll.fixed_rate;
unsigned long input_rate = clk_get_rate(c->parent);
for (sel = c->u.pll.freq_table; sel->input_rate != 0; sel++) {
if (sel->input_rate == input_rate && sel->output_rate == rate)
break;
}
if (sel->input_rate == 0)
return -ENOSYS;
tegra30_plle_clk_disable(c);
val = clk_readl(c->reg + PLL_MISC(c));
val &= ~(PLLE_MISC_LOCK_ENABLE | PLLE_MISC_SETUP_MASK);
clk_writel(val, c->reg + PLL_MISC(c));
val = clk_readl(c->reg + PLL_MISC(c));
if (force_training || (!(val & PLLE_MISC_READY)))
tegra30_plle_training(c);
val = clk_readl(c->reg + PLL_BASE);
val &= ~PLLE_BASE_DIV_MASK;
val |= PLLE_BASE_DIV(sel->m, sel->n, sel->p, sel->cpcon);
clk_writel(val, c->reg + PLL_BASE);
c->mul = sel->n;
c->div = sel->m * sel->p;
val = clk_readl(c->reg + PLL_MISC(c));
val |= PLLE_MISC_SETUP_VALUE;
val |= PLLE_MISC_LOCK_ENABLE;
clk_writel(val, c->reg + PLL_MISC(c));
val = clk_readl(PLLE_SS_CTRL);
val |= PLLE_SS_DISABLE;
clk_writel(val, PLLE_SS_CTRL);
val = clk_readl(c->reg + PLL_BASE);
val |= (PLLE_BASE_CML_ENABLE | PLLE_BASE_ENABLE);
clk_writel(val, c->reg + PLL_BASE);
tegra30_pll_clk_wait_for_lock(c, c->reg + PLL_MISC(c), PLLE_MISC_LOCK);
return 0;
}
static int tegra30_plle_clk_enable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
return tegra30_plle_configure(c, !c->set);
}
static void tegra30_pll_div_clk_init(struct clk *c)
{
if (c->flags & DIV_U71) {
u32 divu71;
u32 val = clk_readl(c->reg);
val >>= c->reg_shift;
c->state = (val & PLL_OUT_CLKEN) ? ON : OFF;
if (!(val & PLL_OUT_RESET_DISABLE))
c->state = OFF;
divu71 = (val & PLL_OUT_RATIO_MASK) >> PLL_OUT_RATIO_SHIFT;
c->div = (divu71 + 2);
c->mul = 2;
} else if (c->flags & DIV_2) {
c->state = ON;
if (c->flags & (PLLD | PLLX)) {
c->div = 2;
c->mul = 1;
} else
BUG();
} else {
c->state = ON;
c->div = 1;
c->mul = 1;
}
}
static int tegra30_pll_div_clk_enable(struct clk *c)
{
u32 val;
u32 new_val;
pr_debug("%s: %s\n", __func__, c->name);
if (c->flags & DIV_U71) {
val = clk_readl(c->reg);
new_val = val >> c->reg_shift;
new_val &= 0xFFFF;
new_val |= PLL_OUT_CLKEN | PLL_OUT_RESET_DISABLE;
val &= ~(0xFFFF << c->reg_shift);
val |= new_val << c->reg_shift;
clk_writel_delay(val, c->reg);
return 0;
} else if (c->flags & DIV_2) {
return 0;
}
return -EINVAL;
}
static void tegra30_pll_div_clk_disable(struct clk *c)
{
u32 val;
u32 new_val;
pr_debug("%s: %s\n", __func__, c->name);
if (c->flags & DIV_U71) {
val = clk_readl(c->reg);
new_val = val >> c->reg_shift;
new_val &= 0xFFFF;
new_val &= ~(PLL_OUT_CLKEN | PLL_OUT_RESET_DISABLE);
val &= ~(0xFFFF << c->reg_shift);
val |= new_val << c->reg_shift;
clk_writel_delay(val, c->reg);
}
}
static int tegra30_pll_div_clk_set_rate(struct clk *c, unsigned long rate)
{
u32 val;
u32 new_val;
int divider_u71;
unsigned long parent_rate = clk_get_rate(c->parent);
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
if (c->flags & DIV_U71) {
divider_u71 = clk_div71_get_divider(
parent_rate, rate, c->flags, ROUND_DIVIDER_UP);
if (divider_u71 >= 0) {
val = clk_readl(c->reg);
new_val = val >> c->reg_shift;
new_val &= 0xFFFF;
if (c->flags & DIV_U71_FIXED)
new_val |= PLL_OUT_OVERRIDE;
new_val &= ~PLL_OUT_RATIO_MASK;
new_val |= divider_u71 << PLL_OUT_RATIO_SHIFT;
val &= ~(0xFFFF << c->reg_shift);
val |= new_val << c->reg_shift;
clk_writel_delay(val, c->reg);
c->div = divider_u71 + 2;
c->mul = 2;
return 0;
}
} else if (c->flags & DIV_2)
return clk_set_rate(c->parent, rate * 2);
return -EINVAL;
}
static long tegra30_pll_div_clk_round_rate(struct clk *c, unsigned long rate)
{
int divider;
unsigned long parent_rate = clk_get_rate(c->parent);
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
if (c->flags & DIV_U71) {
divider = clk_div71_get_divider(
parent_rate, rate, c->flags, ROUND_DIVIDER_UP);
if (divider < 0)
return divider;
return DIV_ROUND_UP(parent_rate * 2, divider + 2);
} else if (c->flags & DIV_2)
return rate;
return -EINVAL;
}
static inline u32 periph_clk_source_mask(struct clk *c)
{
if (c->flags & MUX8)
return 7 << 29;
else if (c->flags & MUX_PWM)
return 3 << 28;
else if (c->flags & MUX_CLK_OUT)
return 3 << (c->u.periph.clk_num + 4);
else if (c->flags & PLLD)
return PLLD_BASE_DSIB_MUX_MASK;
else
return 3 << 30;
}
static inline u32 periph_clk_source_shift(struct clk *c)
{
if (c->flags & MUX8)
return 29;
else if (c->flags & MUX_PWM)
return 28;
else if (c->flags & MUX_CLK_OUT)
return c->u.periph.clk_num + 4;
else if (c->flags & PLLD)
return PLLD_BASE_DSIB_MUX_SHIFT;
else
return 30;
}
static void tegra30_periph_clk_init(struct clk *c)
{
u32 val = clk_readl(c->reg);
const struct clk_mux_sel *mux = 0;
const struct clk_mux_sel *sel;
if (c->flags & MUX) {
for (sel = c->inputs; sel->input != NULL; sel++) {
if (((val & periph_clk_source_mask(c)) >>
periph_clk_source_shift(c)) == sel->value)
mux = sel;
}
BUG_ON(!mux);
c->parent = mux->input;
} else {
c->parent = c->inputs[0].input;
}
if (c->flags & DIV_U71) {
u32 divu71 = val & PERIPH_CLK_SOURCE_DIVU71_MASK;
if ((c->flags & DIV_U71_UART) &&
(!(val & PERIPH_CLK_UART_DIV_ENB))) {
divu71 = 0;
}
if (c->flags & DIV_U71_IDLE) {
val &= ~(PERIPH_CLK_SOURCE_DIVU71_MASK <<
PERIPH_CLK_SOURCE_DIVIDLE_SHIFT);
val |= (PERIPH_CLK_SOURCE_DIVIDLE_VAL <<
PERIPH_CLK_SOURCE_DIVIDLE_SHIFT);
clk_writel(val, c->reg);
}
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
if (!(clk_readl(PERIPH_CLK_TO_ENB_REG(c)) & PERIPH_CLK_TO_BIT(c)))
c->state = OFF;
if (!(c->flags & PERIPH_NO_RESET))
if (clk_readl(PERIPH_CLK_TO_RST_REG(c)) & PERIPH_CLK_TO_BIT(c))
c->state = OFF;
}
static int tegra30_periph_clk_enable(struct clk *c)
{
pr_debug("%s on clock %s\n", __func__, c->name);
tegra_periph_clk_enable_refcount[c->u.periph.clk_num]++;
if (tegra_periph_clk_enable_refcount[c->u.periph.clk_num] > 1)
return 0;
clk_writel_delay(PERIPH_CLK_TO_BIT(c), PERIPH_CLK_TO_ENB_SET_REG(c));
if (!(c->flags & PERIPH_NO_RESET) &&
!(c->flags & PERIPH_MANUAL_RESET)) {
if (clk_readl(PERIPH_CLK_TO_RST_REG(c)) &
PERIPH_CLK_TO_BIT(c)) {
udelay(5);
clk_writel(PERIPH_CLK_TO_BIT(c),
PERIPH_CLK_TO_RST_CLR_REG(c));
}
}
return 0;
}
static void tegra30_periph_clk_disable(struct clk *c)
{
unsigned long val;
pr_debug("%s on clock %s\n", __func__, c->name);
if (c->refcnt)
tegra_periph_clk_enable_refcount[c->u.periph.clk_num]--;
if (tegra_periph_clk_enable_refcount[c->u.periph.clk_num] == 0) {
if (c->flags & PERIPH_ON_APB)
val = chipid_readl();
clk_writel_delay(
PERIPH_CLK_TO_BIT(c), PERIPH_CLK_TO_ENB_CLR_REG(c));
}
}
static void tegra30_periph_clk_reset(struct clk *c, bool assert)
{
unsigned long val;
pr_debug("%s %s on clock %s\n", __func__,
assert ? "assert" : "deassert", c->name);
if (!(c->flags & PERIPH_NO_RESET)) {
if (assert) {
if (c->flags & PERIPH_ON_APB)
val = chipid_readl();
clk_writel(PERIPH_CLK_TO_BIT(c),
PERIPH_CLK_TO_RST_SET_REG(c));
} else
clk_writel(PERIPH_CLK_TO_BIT(c),
PERIPH_CLK_TO_RST_CLR_REG(c));
}
}
static int tegra30_periph_clk_set_parent(struct clk *c, struct clk *p)
{
u32 val;
const struct clk_mux_sel *sel;
pr_debug("%s: %s %s\n", __func__, c->name, p->name);
if (!(c->flags & MUX))
return (p == c->parent) ? 0 : (-EINVAL);
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->input == p) {
val = clk_readl(c->reg);
val &= ~periph_clk_source_mask(c);
val |= (sel->value << periph_clk_source_shift(c));
if (c->refcnt)
clk_enable(p);
clk_writel_delay(val, c->reg);
if (c->refcnt && c->parent)
clk_disable(c->parent);
clk_reparent(c, p);
return 0;
}
}
return -EINVAL;
}
static int tegra30_periph_clk_set_rate(struct clk *c, unsigned long rate)
{
u32 val;
int divider;
unsigned long parent_rate = clk_get_rate(c->parent);
if (c->flags & DIV_U71) {
divider = clk_div71_get_divider(
parent_rate, rate, c->flags, ROUND_DIVIDER_UP);
if (divider >= 0) {
val = clk_readl(c->reg);
val &= ~PERIPH_CLK_SOURCE_DIVU71_MASK;
val |= divider;
if (c->flags & DIV_U71_UART) {
if (divider)
val |= PERIPH_CLK_UART_DIV_ENB;
else
val &= ~PERIPH_CLK_UART_DIV_ENB;
}
clk_writel_delay(val, c->reg);
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
clk_writel_delay(val, c->reg);
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
static long tegra30_periph_clk_round_rate(struct clk *c,
unsigned long rate)
{
int divider;
unsigned long parent_rate = clk_get_rate(c->parent);
pr_debug("%s: %s %lu\n", __func__, c->name, rate);
if (c->flags & DIV_U71) {
divider = clk_div71_get_divider(
parent_rate, rate, c->flags, ROUND_DIVIDER_UP);
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
static int
tegra30_vi_clk_cfg_ex(struct clk *c, enum tegra_clk_ex_param p, u32 setting)
{
if (p == TEGRA_CLK_VI_INP_SEL) {
u32 val = clk_readl(c->reg);
val &= ~PERIPH_CLK_VI_SEL_EX_MASK;
val |= (setting << PERIPH_CLK_VI_SEL_EX_SHIFT) &
PERIPH_CLK_VI_SEL_EX_MASK;
clk_writel(val, c->reg);
return 0;
}
return -EINVAL;
}
static int
tegra30_nand_clk_cfg_ex(struct clk *c, enum tegra_clk_ex_param p, u32 setting)
{
if (p == TEGRA_CLK_NAND_PAD_DIV2_ENB) {
u32 val = clk_readl(c->reg);
if (setting)
val |= PERIPH_CLK_NAND_DIV_EX_ENB;
else
val &= ~PERIPH_CLK_NAND_DIV_EX_ENB;
clk_writel(val, c->reg);
return 0;
}
return -EINVAL;
}
static int
tegra30_dtv_clk_cfg_ex(struct clk *c, enum tegra_clk_ex_param p, u32 setting)
{
if (p == TEGRA_CLK_DTV_INVERT) {
u32 val = clk_readl(c->reg);
if (setting)
val |= PERIPH_CLK_DTV_POLARITY_INV;
else
val &= ~PERIPH_CLK_DTV_POLARITY_INV;
clk_writel(val, c->reg);
return 0;
}
return -EINVAL;
}
static int tegra30_dsib_clk_set_parent(struct clk *c, struct clk *p)
{
const struct clk_mux_sel *sel;
struct clk *d = tegra_get_clock_by_name("pll_d");
pr_debug("%s: %s %s\n", __func__, c->name, p->name);
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->input == p) {
if (c->refcnt)
clk_enable(p);
tegra_clk_cfg_ex(
d, TEGRA_CLK_PLLD_MIPI_MUX_SEL, sel->value);
if (c->refcnt && c->parent)
clk_disable(c->parent);
clk_reparent(c, p);
return 0;
}
}
return -EINVAL;
}
static void tegra30_clk_out_init(struct clk *c)
{
const struct clk_mux_sel *mux = 0;
const struct clk_mux_sel *sel;
u32 val = pmc_readl(c->reg);
c->state = (val & (0x1 << c->u.periph.clk_num)) ? ON : OFF;
c->mul = 1;
c->div = 1;
for (sel = c->inputs; sel->input != NULL; sel++) {
if (((val & periph_clk_source_mask(c)) >>
periph_clk_source_shift(c)) == sel->value)
mux = sel;
}
BUG_ON(!mux);
c->parent = mux->input;
}
static int tegra30_clk_out_enable(struct clk *c)
{
u32 val;
unsigned long flags;
pr_debug("%s on clock %s\n", __func__, c->name);
spin_lock_irqsave(&clk_out_lock, flags);
val = pmc_readl(c->reg);
val |= (0x1 << c->u.periph.clk_num);
pmc_writel(val, c->reg);
spin_unlock_irqrestore(&clk_out_lock, flags);
return 0;
}
static void tegra30_clk_out_disable(struct clk *c)
{
u32 val;
unsigned long flags;
pr_debug("%s on clock %s\n", __func__, c->name);
spin_lock_irqsave(&clk_out_lock, flags);
val = pmc_readl(c->reg);
val &= ~(0x1 << c->u.periph.clk_num);
pmc_writel(val, c->reg);
spin_unlock_irqrestore(&clk_out_lock, flags);
}
static int tegra30_clk_out_set_parent(struct clk *c, struct clk *p)
{
u32 val;
unsigned long flags;
const struct clk_mux_sel *sel;
pr_debug("%s: %s %s\n", __func__, c->name, p->name);
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->input == p) {
if (c->refcnt)
clk_enable(p);
spin_lock_irqsave(&clk_out_lock, flags);
val = pmc_readl(c->reg);
val &= ~periph_clk_source_mask(c);
val |= (sel->value << periph_clk_source_shift(c));
pmc_writel(val, c->reg);
spin_unlock_irqrestore(&clk_out_lock, flags);
if (c->refcnt && c->parent)
clk_disable(c->parent);
clk_reparent(c, p);
return 0;
}
}
return -EINVAL;
}
static void tegra30_clk_double_init(struct clk *c)
{
u32 val = clk_readl(c->reg);
c->mul = val & (0x1 << c->reg_shift) ? 1 : 2;
c->div = 1;
c->state = ON;
if (!(clk_readl(PERIPH_CLK_TO_ENB_REG(c)) & PERIPH_CLK_TO_BIT(c)))
c->state = OFF;
}
static int tegra30_clk_double_set_rate(struct clk *c, unsigned long rate)
{
u32 val;
unsigned long parent_rate = clk_get_rate(c->parent);
if (rate == parent_rate) {
val = clk_readl(c->reg) | (0x1 << c->reg_shift);
clk_writel(val, c->reg);
c->mul = 1;
c->div = 1;
return 0;
} else if (rate == 2 * parent_rate) {
val = clk_readl(c->reg) & (~(0x1 << c->reg_shift));
clk_writel(val, c->reg);
c->mul = 2;
c->div = 1;
return 0;
}
return -EINVAL;
}
static int tegra30_sync_source_set_rate(struct clk *c, unsigned long rate)
{
c->rate = rate;
return 0;
}
static void tegra30_audio_sync_clk_init(struct clk *c)
{
int source;
const struct clk_mux_sel *sel;
u32 val = clk_readl(c->reg);
c->state = (val & AUDIO_SYNC_DISABLE_BIT) ? OFF : ON;
source = val & AUDIO_SYNC_SOURCE_MASK;
for (sel = c->inputs; sel->input != NULL; sel++)
if (sel->value == source)
break;
BUG_ON(sel->input == NULL);
c->parent = sel->input;
}
static int tegra30_audio_sync_clk_enable(struct clk *c)
{
u32 val = clk_readl(c->reg);
clk_writel((val & (~AUDIO_SYNC_DISABLE_BIT)), c->reg);
return 0;
}
static void tegra30_audio_sync_clk_disable(struct clk *c)
{
u32 val = clk_readl(c->reg);
clk_writel((val | AUDIO_SYNC_DISABLE_BIT), c->reg);
}
static int tegra30_audio_sync_clk_set_parent(struct clk *c, struct clk *p)
{
u32 val;
const struct clk_mux_sel *sel;
for (sel = c->inputs; sel->input != NULL; sel++) {
if (sel->input == p) {
val = clk_readl(c->reg);
val &= ~AUDIO_SYNC_SOURCE_MASK;
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
static void tegra30_cml_clk_init(struct clk *c)
{
u32 val = clk_readl(c->reg);
c->state = val & (0x1 << c->u.periph.clk_num) ? ON : OFF;
}
static int tegra30_cml_clk_enable(struct clk *c)
{
u32 val = clk_readl(c->reg);
val |= (0x1 << c->u.periph.clk_num);
clk_writel(val, c->reg);
return 0;
}
static void tegra30_cml_clk_disable(struct clk *c)
{
u32 val = clk_readl(c->reg);
val &= ~(0x1 << c->u.periph.clk_num);
clk_writel(val, c->reg);
}
static void init_clk_out_mux(void)
{
int i;
struct clk *c;
for (i = 0; i < ARRAY_SIZE(tegra_clk_out_list); i++) {
c = tegra_get_clock_by_name(
tegra_clk_out_list[i].lookup.con_id);
if (!c)
pr_err("%s: could not find clk %s\n", __func__,
tegra_clk_out_list[i].lookup.con_id);
mux_extern_out_list[i][3].input = c;
}
}
static void tegra30_init_one_clock(struct clk *c)
{
clk_init(c);
INIT_LIST_HEAD(&c->shared_bus_list);
if (!c->lookup.dev_id && !c->lookup.con_id)
c->lookup.con_id = c->name;
c->lookup.clk = c;
clkdev_add(&c->lookup);
}
void __init tegra30_init_clocks(void)
{
int i;
struct clk *c;
for (i = 0; i < ARRAY_SIZE(tegra_ptr_clks); i++)
tegra30_init_one_clock(tegra_ptr_clks[i]);
for (i = 0; i < ARRAY_SIZE(tegra_list_clks); i++)
tegra30_init_one_clock(&tegra_list_clks[i]);
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
for (i = 0; i < ARRAY_SIZE(tegra_sync_source_list); i++)
tegra30_init_one_clock(&tegra_sync_source_list[i]);
for (i = 0; i < ARRAY_SIZE(tegra_clk_audio_list); i++)
tegra30_init_one_clock(&tegra_clk_audio_list[i]);
for (i = 0; i < ARRAY_SIZE(tegra_clk_audio_2x_list); i++)
tegra30_init_one_clock(&tegra_clk_audio_2x_list[i]);
init_clk_out_mux();
for (i = 0; i < ARRAY_SIZE(tegra_clk_out_list); i++)
tegra30_init_one_clock(&tegra_clk_out_list[i]);
}
