static void _omap3_dpll_write_clken(struct clk *clk, u8 clken_bits)
{
const struct dpll_data *dd;
u32 v;
dd = clk->dpll_data;
v = __raw_readl(dd->control_reg);
v &= ~dd->enable_mask;
v |= clken_bits << __ffs(dd->enable_mask);
__raw_writel(v, dd->control_reg);
}
static int _omap3_wait_dpll_status(struct clk *clk, u8 state)
{
const struct dpll_data *dd;
int i = 0;
int ret = -EINVAL;
const char *clk_name;
dd = clk->dpll_data;
clk_name = __clk_get_name(clk);
state <<= __ffs(dd->idlest_mask);
while (((__raw_readl(dd->idlest_reg) & dd->idlest_mask) != state) &&
i < MAX_DPLL_WAIT_TRIES) {
i++;
udelay(1);
}
if (i == MAX_DPLL_WAIT_TRIES) {
printk(KERN_ERR "clock: %s failed transition to '%s'\n",
clk_name, (state) ? "locked" : "bypassed");
} else {
pr_debug("clock: %s transition to '%s' in %d loops\n",
clk_name, (state) ? "locked" : "bypassed", i);
ret = 0;
}
return ret;
}
static u16 _omap3_dpll_compute_freqsel(struct clk *clk, u8 n)
{
unsigned long fint;
u16 f = 0;
fint = __clk_get_rate(clk->dpll_data->clk_ref) / n;
pr_debug("clock: fint is %lu\n", fint);
if (fint >= 750000 && fint <= 1000000)
f = 0x3;
else if (fint > 1000000 && fint <= 1250000)
f = 0x4;
else if (fint > 1250000 && fint <= 1500000)
f = 0x5;
else if (fint > 1500000 && fint <= 1750000)
f = 0x6;
else if (fint > 1750000 && fint <= 2100000)
f = 0x7;
else if (fint > 7500000 && fint <= 10000000)
f = 0xB;
else if (fint > 10000000 && fint <= 12500000)
f = 0xC;
else if (fint > 12500000 && fint <= 15000000)
f = 0xD;
else if (fint > 15000000 && fint <= 17500000)
f = 0xE;
else if (fint > 17500000 && fint <= 21000000)
f = 0xF;
else
pr_debug("clock: unknown freqsel setting for %d\n", n);
return f;
}
static int _omap3_noncore_dpll_lock(struct clk *clk)
{
const struct dpll_data *dd;
u8 ai;
u8 state = 1;
int r = 0;
pr_debug("clock: locking DPLL %s\n", __clk_get_name(clk));
dd = clk->dpll_data;
state <<= __ffs(dd->idlest_mask);
if ((__raw_readl(dd->idlest_reg) & dd->idlest_mask) == state)
goto done;
ai = omap3_dpll_autoidle_read(clk);
if (ai)
omap3_dpll_deny_idle(clk);
_omap3_dpll_write_clken(clk, DPLL_LOCKED);
r = _omap3_wait_dpll_status(clk, 1);
if (ai)
omap3_dpll_allow_idle(clk);
done:
return r;
}
static int _omap3_noncore_dpll_bypass(struct clk *clk)
{
int r;
u8 ai;
if (!(clk->dpll_data->modes & (1 << DPLL_LOW_POWER_BYPASS)))
return -EINVAL;
pr_debug("clock: configuring DPLL %s for low-power bypass\n",
__clk_get_name(clk));
ai = omap3_dpll_autoidle_read(clk);
_omap3_dpll_write_clken(clk, DPLL_LOW_POWER_BYPASS);
r = _omap3_wait_dpll_status(clk, 0);
if (ai)
omap3_dpll_allow_idle(clk);
return r;
}
static int _omap3_noncore_dpll_stop(struct clk *clk)
{
u8 ai;
if (!(clk->dpll_data->modes & (1 << DPLL_LOW_POWER_STOP)))
return -EINVAL;
pr_debug("clock: stopping DPLL %s\n", __clk_get_name(clk));
ai = omap3_dpll_autoidle_read(clk);
_omap3_dpll_write_clken(clk, DPLL_LOW_POWER_STOP);
if (ai)
omap3_dpll_allow_idle(clk);
return 0;
}
static void _lookup_dco(struct clk *clk, u8 *dco, u16 m, u8 n)
{
unsigned long fint, clkinp;
clkinp = __clk_get_rate(__clk_get_parent(clk));
fint = (clkinp / n) * m;
if (fint < 1000000000)
*dco = 2;
else
*dco = 4;
}
static void _lookup_sddiv(struct clk *clk, u8 *sd_div, u16 m, u8 n)
{
unsigned long clkinp, sd;
int mod1, mod2;
clkinp = __clk_get_rate(__clk_get_parent(clk));
clkinp /= 100000;
mod1 = (clkinp * m) % (250 * n);
sd = (clkinp * m) / (250 * n);
mod2 = sd % 10;
sd /= 10;
if (mod1 || mod2)
sd++;
*sd_div = sd;
}
static int omap3_noncore_dpll_program(struct clk *clk, u16 m, u8 n, u16 freqsel)
{
struct dpll_data *dd = clk->dpll_data;
u8 dco, sd_div;
u32 v;
_omap3_noncore_dpll_bypass(clk);
if (!soc_is_am33xx() && !cpu_is_omap44xx() && !cpu_is_omap3630()) {
v = __raw_readl(dd->control_reg);
v &= ~dd->freqsel_mask;
v |= freqsel << __ffs(dd->freqsel_mask);
__raw_writel(v, dd->control_reg);
}
v = __raw_readl(dd->mult_div1_reg);
v &= ~(dd->mult_mask | dd->div1_mask);
v |= m << __ffs(dd->mult_mask);
v |= (n - 1) << __ffs(dd->div1_mask);
if (dd->dco_mask) {
_lookup_dco(clk, &dco, m, n);
v &= ~(dd->dco_mask);
v |= dco << __ffs(dd->dco_mask);
}
if (dd->sddiv_mask) {
_lookup_sddiv(clk, &sd_div, m, n);
v &= ~(dd->sddiv_mask);
v |= sd_div << __ffs(dd->sddiv_mask);
}
__raw_writel(v, dd->mult_div1_reg);
_omap3_noncore_dpll_lock(clk);
return 0;
}
unsigned long omap3_dpll_recalc(struct clk *clk)
{
return omap2_get_dpll_rate(clk);
}
int omap3_noncore_dpll_enable(struct clk *clk)
{
int r;
struct dpll_data *dd;
struct clk *parent;
dd = clk->dpll_data;
if (!dd)
return -EINVAL;
parent = __clk_get_parent(clk);
if (__clk_get_rate(clk) == __clk_get_rate(dd->clk_bypass)) {
WARN_ON(parent != dd->clk_bypass);
r = _omap3_noncore_dpll_bypass(clk);
} else {
WARN_ON(parent != dd->clk_ref);
r = _omap3_noncore_dpll_lock(clk);
}
if (!r)
clk->rate = (clk->recalc) ? clk->recalc(clk) :
omap2_get_dpll_rate(clk);
return r;
}
void omap3_noncore_dpll_disable(struct clk *clk)
{
_omap3_noncore_dpll_stop(clk);
}
int omap3_noncore_dpll_set_rate(struct clk *clk, unsigned long rate)
{
struct clk *new_parent = NULL;
unsigned long hw_rate, bypass_rate;
u16 freqsel = 0;
struct dpll_data *dd;
int ret;
if (!clk || !rate)
return -EINVAL;
dd = clk->dpll_data;
if (!dd)
return -EINVAL;
hw_rate = (clk->recalc) ? clk->recalc(clk) : omap2_get_dpll_rate(clk);
if (rate == hw_rate)
return 0;
omap2_clk_enable(dd->clk_bypass);
omap2_clk_enable(dd->clk_ref);
bypass_rate = __clk_get_rate(dd->clk_bypass);
if (bypass_rate == rate &&
(clk->dpll_data->modes & (1 << DPLL_LOW_POWER_BYPASS))) {
pr_debug("clock: %s: set rate: entering bypass.\n", clk->name);
ret = _omap3_noncore_dpll_bypass(clk);
if (!ret)
new_parent = dd->clk_bypass;
} else {
if (dd->last_rounded_rate != rate)
rate = clk->round_rate(clk, rate);
if (dd->last_rounded_rate == 0)
return -EINVAL;
if (!soc_is_am33xx() && !cpu_is_omap44xx() && !cpu_is_omap3630()) {
freqsel = _omap3_dpll_compute_freqsel(clk,
dd->last_rounded_n);
if (!freqsel)
WARN_ON(1);
}
pr_debug("clock: %s: set rate: locking rate to %lu.\n",
__clk_get_name(clk), rate);
ret = omap3_noncore_dpll_program(clk, dd->last_rounded_m,
dd->last_rounded_n, freqsel);
if (!ret)
new_parent = dd->clk_ref;
}
if (!ret) {
if (clk->usecount) {
omap2_clk_enable(new_parent);
omap2_clk_disable(clk->parent);
}
clk_reparent(clk, new_parent);
clk->rate = rate;
}
omap2_clk_disable(dd->clk_ref);
omap2_clk_disable(dd->clk_bypass);
return 0;
}
u32 omap3_dpll_autoidle_read(struct clk *clk)
{
const struct dpll_data *dd;
u32 v;
if (!clk || !clk->dpll_data)
return -EINVAL;
dd = clk->dpll_data;
if (!dd->autoidle_reg)
return -EINVAL;
v = __raw_readl(dd->autoidle_reg);
v &= dd->autoidle_mask;
v >>= __ffs(dd->autoidle_mask);
return v;
}
void omap3_dpll_allow_idle(struct clk *clk)
{
const struct dpll_data *dd;
u32 v;
if (!clk || !clk->dpll_data)
return;
dd = clk->dpll_data;
if (!dd->autoidle_reg) {
pr_debug("clock: DPLL %s: autoidle not supported\n",
__clk_get_name(clk));
return;
}
v = __raw_readl(dd->autoidle_reg);
v &= ~dd->autoidle_mask;
v |= DPLL_AUTOIDLE_LOW_POWER_STOP << __ffs(dd->autoidle_mask);
__raw_writel(v, dd->autoidle_reg);
}
void omap3_dpll_deny_idle(struct clk *clk)
{
const struct dpll_data *dd;
u32 v;
if (!clk || !clk->dpll_data)
return;
dd = clk->dpll_data;
if (!dd->autoidle_reg) {
pr_debug("clock: DPLL %s: autoidle not supported\n",
__clk_get_name(clk));
return;
}
v = __raw_readl(dd->autoidle_reg);
v &= ~dd->autoidle_mask;
v |= DPLL_AUTOIDLE_DISABLE << __ffs(dd->autoidle_mask);
__raw_writel(v, dd->autoidle_reg);
}
unsigned long omap3_clkoutx2_recalc(struct clk *clk)
{
const struct dpll_data *dd;
unsigned long rate;
u32 v;
struct clk *pclk;
unsigned long parent_rate;
pclk = __clk_get_parent(clk);
while (pclk && !pclk->dpll_data)
pclk = __clk_get_parent(pclk);
if (!pclk) {
WARN_ON(1);
return 0;
}
dd = pclk->dpll_data;
WARN_ON(!dd->enable_mask);
parent_rate = __clk_get_rate(__clk_get_parent(clk));
v = __raw_readl(dd->control_reg) & dd->enable_mask;
v >>= __ffs(dd->enable_mask);
if ((v != OMAP3XXX_EN_DPLL_LOCKED) || (dd->flags & DPLL_J_TYPE))
rate = parent_rate;
else
rate = parent_rate * 2;
return rate;
}
