static const struct rockchip_pll_rate_table *rockchip_get_pll_settings(
struct rockchip_clk_pll *pll, unsigned long rate)
{
const struct rockchip_pll_rate_table *rate_table = pll->rate_table;
int i;
for (i = 0; i < pll->rate_count; i++) {
if (rate == rate_table[i].rate)
return &rate_table[i];
}
return NULL;
}
static long rockchip_pll_round_rate(struct clk_hw *hw,
unsigned long drate, unsigned long *prate)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
const struct rockchip_pll_rate_table *rate_table = pll->rate_table;
int i;
for (i = 0; i < pll->rate_count; i++) {
if (drate >= rate_table[i].rate)
return rate_table[i].rate;
}
return rate_table[i - 1].rate;
}
static int rockchip_pll_wait_lock(struct rockchip_clk_pll *pll)
{
struct regmap *grf = pll->ctx->grf;
unsigned int val;
int delay = 24000000, ret;
while (delay > 0) {
ret = regmap_read(grf, pll->lock_offset, &val);
if (ret) {
pr_err("%s: failed to read pll lock status: %d\n",
__func__, ret);
return ret;
}
if (val & BIT(pll->lock_shift))
return 0;
delay--;
}
pr_err("%s: timeout waiting for pll to lock\n", __func__);
return -ETIMEDOUT;
}
static void rockchip_rk3036_pll_get_params(struct rockchip_clk_pll *pll,
struct rockchip_pll_rate_table *rate)
{
u32 pllcon;
pllcon = readl_relaxed(pll->reg_base + RK3036_PLLCON(0));
rate->fbdiv = ((pllcon >> RK3036_PLLCON0_FBDIV_SHIFT)
& RK3036_PLLCON0_FBDIV_MASK);
rate->postdiv1 = ((pllcon >> RK3036_PLLCON0_POSTDIV1_SHIFT)
& RK3036_PLLCON0_POSTDIV1_MASK);
pllcon = readl_relaxed(pll->reg_base + RK3036_PLLCON(1));
rate->refdiv = ((pllcon >> RK3036_PLLCON1_REFDIV_SHIFT)
& RK3036_PLLCON1_REFDIV_MASK);
rate->postdiv2 = ((pllcon >> RK3036_PLLCON1_POSTDIV2_SHIFT)
& RK3036_PLLCON1_POSTDIV2_MASK);
rate->dsmpd = ((pllcon >> RK3036_PLLCON1_DSMPD_SHIFT)
& RK3036_PLLCON1_DSMPD_MASK);
pllcon = readl_relaxed(pll->reg_base + RK3036_PLLCON(2));
rate->frac = ((pllcon >> RK3036_PLLCON2_FRAC_SHIFT)
& RK3036_PLLCON2_FRAC_MASK);
}
static unsigned long rockchip_rk3036_pll_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
struct rockchip_pll_rate_table cur;
u64 rate64 = prate;
rockchip_rk3036_pll_get_params(pll, &cur);
rate64 *= cur.fbdiv;
do_div(rate64, cur.refdiv);
if (cur.dsmpd == 0) {
u64 frac_rate64 = prate * cur.frac;
do_div(frac_rate64, cur.refdiv);
rate64 += frac_rate64 >> 24;
}
do_div(rate64, cur.postdiv1);
do_div(rate64, cur.postdiv2);
return (unsigned long)rate64;
}
static int rockchip_rk3036_pll_set_params(struct rockchip_clk_pll *pll,
const struct rockchip_pll_rate_table *rate)
{
const struct clk_ops *pll_mux_ops = pll->pll_mux_ops;
struct clk_mux *pll_mux = &pll->pll_mux;
struct rockchip_pll_rate_table cur;
u32 pllcon;
int rate_change_remuxed = 0;
int cur_parent;
int ret;
pr_debug("%s: rate settings for %lu fbdiv: %d, postdiv1: %d, refdiv: %d, postdiv2: %d, dsmpd: %d, frac: %d\n",
__func__, rate->rate, rate->fbdiv, rate->postdiv1, rate->refdiv,
rate->postdiv2, rate->dsmpd, rate->frac);
rockchip_rk3036_pll_get_params(pll, &cur);
cur.rate = 0;
cur_parent = pll_mux_ops->get_parent(&pll_mux->hw);
if (cur_parent == PLL_MODE_NORM) {
pll_mux_ops->set_parent(&pll_mux->hw, PLL_MODE_SLOW);
rate_change_remuxed = 1;
}
writel_relaxed(HIWORD_UPDATE(rate->fbdiv, RK3036_PLLCON0_FBDIV_MASK,
RK3036_PLLCON0_FBDIV_SHIFT) |
HIWORD_UPDATE(rate->postdiv1, RK3036_PLLCON0_POSTDIV1_MASK,
RK3036_PLLCON0_POSTDIV1_SHIFT),
pll->reg_base + RK3036_PLLCON(0));
writel_relaxed(HIWORD_UPDATE(rate->refdiv, RK3036_PLLCON1_REFDIV_MASK,
RK3036_PLLCON1_REFDIV_SHIFT) |
HIWORD_UPDATE(rate->postdiv2, RK3036_PLLCON1_POSTDIV2_MASK,
RK3036_PLLCON1_POSTDIV2_SHIFT) |
HIWORD_UPDATE(rate->dsmpd, RK3036_PLLCON1_DSMPD_MASK,
RK3036_PLLCON1_DSMPD_SHIFT),
pll->reg_base + RK3036_PLLCON(1));
pllcon = readl_relaxed(pll->reg_base + RK3036_PLLCON(2));
pllcon &= ~(RK3036_PLLCON2_FRAC_MASK << RK3036_PLLCON2_FRAC_SHIFT);
pllcon |= rate->frac << RK3036_PLLCON2_FRAC_SHIFT;
writel_relaxed(pllcon, pll->reg_base + RK3036_PLLCON(2));
ret = rockchip_pll_wait_lock(pll);
if (ret) {
pr_warn("%s: pll update unsuccessful, trying to restore old params\n",
__func__);
rockchip_rk3036_pll_set_params(pll, &cur);
}
if (rate_change_remuxed)
pll_mux_ops->set_parent(&pll_mux->hw, PLL_MODE_NORM);
return ret;
}
static int rockchip_rk3036_pll_set_rate(struct clk_hw *hw, unsigned long drate,
unsigned long prate)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
const struct rockchip_pll_rate_table *rate;
pr_debug("%s: changing %s to %lu with a parent rate of %lu\n",
__func__, __clk_get_name(hw->clk), drate, prate);
rate = rockchip_get_pll_settings(pll, drate);
if (!rate) {
pr_err("%s: Invalid rate : %lu for pll clk %s\n", __func__,
drate, __clk_get_name(hw->clk));
return -EINVAL;
}
return rockchip_rk3036_pll_set_params(pll, rate);
}
static int rockchip_rk3036_pll_enable(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
writel(HIWORD_UPDATE(0, RK3036_PLLCON1_PWRDOWN, 0),
pll->reg_base + RK3036_PLLCON(1));
rockchip_pll_wait_lock(pll);
return 0;
}
static void rockchip_rk3036_pll_disable(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
writel(HIWORD_UPDATE(RK3036_PLLCON1_PWRDOWN,
RK3036_PLLCON1_PWRDOWN, 0),
pll->reg_base + RK3036_PLLCON(1));
}
static int rockchip_rk3036_pll_is_enabled(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
u32 pllcon = readl(pll->reg_base + RK3036_PLLCON(1));
return !(pllcon & RK3036_PLLCON1_PWRDOWN);
}
static void rockchip_rk3036_pll_init(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
const struct rockchip_pll_rate_table *rate;
struct rockchip_pll_rate_table cur;
unsigned long drate;
if (!(pll->flags & ROCKCHIP_PLL_SYNC_RATE))
return;
drate = clk_hw_get_rate(hw);
rate = rockchip_get_pll_settings(pll, drate);
if (!rate)
return;
rockchip_rk3036_pll_get_params(pll, &cur);
pr_debug("%s: pll %s@%lu: Hz\n", __func__, __clk_get_name(hw->clk),
drate);
pr_debug("old - fbdiv: %d, postdiv1: %d, refdiv: %d, postdiv2: %d, dsmpd: %d, frac: %d\n",
cur.fbdiv, cur.postdiv1, cur.refdiv, cur.postdiv2,
cur.dsmpd, cur.frac);
pr_debug("new - fbdiv: %d, postdiv1: %d, refdiv: %d, postdiv2: %d, dsmpd: %d, frac: %d\n",
rate->fbdiv, rate->postdiv1, rate->refdiv, rate->postdiv2,
rate->dsmpd, rate->frac);
if (rate->fbdiv != cur.fbdiv || rate->postdiv1 != cur.postdiv1 ||
rate->refdiv != cur.refdiv || rate->postdiv2 != cur.postdiv2 ||
rate->dsmpd != cur.dsmpd ||
(!cur.dsmpd && (rate->frac != cur.frac))) {
struct clk *parent = clk_get_parent(hw->clk);
if (!parent) {
pr_warn("%s: parent of %s not available\n",
__func__, __clk_get_name(hw->clk));
return;
}
pr_debug("%s: pll %s: rate params do not match rate table, adjusting\n",
__func__, __clk_get_name(hw->clk));
rockchip_rk3036_pll_set_params(pll, rate);
}
}
static void rockchip_rk3066_pll_get_params(struct rockchip_clk_pll *pll,
struct rockchip_pll_rate_table *rate)
{
u32 pllcon;
pllcon = readl_relaxed(pll->reg_base + RK3066_PLLCON(0));
rate->nr = ((pllcon >> RK3066_PLLCON0_NR_SHIFT)
& RK3066_PLLCON0_NR_MASK) + 1;
rate->no = ((pllcon >> RK3066_PLLCON0_OD_SHIFT)
& RK3066_PLLCON0_OD_MASK) + 1;
pllcon = readl_relaxed(pll->reg_base + RK3066_PLLCON(1));
rate->nf = ((pllcon >> RK3066_PLLCON1_NF_SHIFT)
& RK3066_PLLCON1_NF_MASK) + 1;
pllcon = readl_relaxed(pll->reg_base + RK3066_PLLCON(2));
rate->nb = ((pllcon >> RK3066_PLLCON2_NB_SHIFT)
& RK3066_PLLCON2_NB_MASK) + 1;
}
static unsigned long rockchip_rk3066_pll_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
struct rockchip_pll_rate_table cur;
u64 rate64 = prate;
u32 pllcon;
pllcon = readl_relaxed(pll->reg_base + RK3066_PLLCON(3));
if (pllcon & RK3066_PLLCON3_BYPASS) {
pr_debug("%s: pll %s is bypassed\n", __func__,
clk_hw_get_name(hw));
return prate;
}
rockchip_rk3066_pll_get_params(pll, &cur);
rate64 *= cur.nf;
do_div(rate64, cur.nr);
do_div(rate64, cur.no);
return (unsigned long)rate64;
}
static int rockchip_rk3066_pll_set_params(struct rockchip_clk_pll *pll,
const struct rockchip_pll_rate_table *rate)
{
const struct clk_ops *pll_mux_ops = pll->pll_mux_ops;
struct clk_mux *pll_mux = &pll->pll_mux;
struct rockchip_pll_rate_table cur;
int rate_change_remuxed = 0;
int cur_parent;
int ret;
pr_debug("%s: rate settings for %lu (nr, no, nf): (%d, %d, %d)\n",
__func__, rate->rate, rate->nr, rate->no, rate->nf);
rockchip_rk3066_pll_get_params(pll, &cur);
cur.rate = 0;
cur_parent = pll_mux_ops->get_parent(&pll_mux->hw);
if (cur_parent == PLL_MODE_NORM) {
pll_mux_ops->set_parent(&pll_mux->hw, PLL_MODE_SLOW);
rate_change_remuxed = 1;
}
writel(HIWORD_UPDATE(RK3066_PLLCON3_RESET, RK3066_PLLCON3_RESET, 0),
pll->reg_base + RK3066_PLLCON(3));
writel(HIWORD_UPDATE(rate->nr - 1, RK3066_PLLCON0_NR_MASK,
RK3066_PLLCON0_NR_SHIFT) |
HIWORD_UPDATE(rate->no - 1, RK3066_PLLCON0_OD_MASK,
RK3066_PLLCON0_OD_SHIFT),
pll->reg_base + RK3066_PLLCON(0));
writel_relaxed(HIWORD_UPDATE(rate->nf - 1, RK3066_PLLCON1_NF_MASK,
RK3066_PLLCON1_NF_SHIFT),
pll->reg_base + RK3066_PLLCON(1));
writel_relaxed(HIWORD_UPDATE(rate->nb - 1, RK3066_PLLCON2_NB_MASK,
RK3066_PLLCON2_NB_SHIFT),
pll->reg_base + RK3066_PLLCON(2));
writel(HIWORD_UPDATE(0, RK3066_PLLCON3_RESET, 0),
pll->reg_base + RK3066_PLLCON(3));
udelay(RK3066_PLL_RESET_DELAY(rate->nr));
ret = rockchip_pll_wait_lock(pll);
if (ret) {
pr_warn("%s: pll update unsuccessful, trying to restore old params\n",
__func__);
rockchip_rk3066_pll_set_params(pll, &cur);
}
if (rate_change_remuxed)
pll_mux_ops->set_parent(&pll_mux->hw, PLL_MODE_NORM);
return ret;
}
static int rockchip_rk3066_pll_set_rate(struct clk_hw *hw, unsigned long drate,
unsigned long prate)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
const struct rockchip_pll_rate_table *rate;
pr_debug("%s: changing %s to %lu with a parent rate of %lu\n",
__func__, clk_hw_get_name(hw), drate, prate);
rate = rockchip_get_pll_settings(pll, drate);
if (!rate) {
pr_err("%s: Invalid rate : %lu for pll clk %s\n", __func__,
drate, clk_hw_get_name(hw));
return -EINVAL;
}
return rockchip_rk3066_pll_set_params(pll, rate);
}
static int rockchip_rk3066_pll_enable(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
writel(HIWORD_UPDATE(0, RK3066_PLLCON3_PWRDOWN, 0),
pll->reg_base + RK3066_PLLCON(3));
rockchip_pll_wait_lock(pll);
return 0;
}
static void rockchip_rk3066_pll_disable(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
writel(HIWORD_UPDATE(RK3066_PLLCON3_PWRDOWN,
RK3066_PLLCON3_PWRDOWN, 0),
pll->reg_base + RK3066_PLLCON(3));
}
static int rockchip_rk3066_pll_is_enabled(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
u32 pllcon = readl(pll->reg_base + RK3066_PLLCON(3));
return !(pllcon & RK3066_PLLCON3_PWRDOWN);
}
static void rockchip_rk3066_pll_init(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
const struct rockchip_pll_rate_table *rate;
struct rockchip_pll_rate_table cur;
unsigned long drate;
if (!(pll->flags & ROCKCHIP_PLL_SYNC_RATE))
return;
drate = clk_hw_get_rate(hw);
rate = rockchip_get_pll_settings(pll, drate);
if (!rate)
return;
rockchip_rk3066_pll_get_params(pll, &cur);
pr_debug("%s: pll %s@%lu: nr (%d:%d); no (%d:%d); nf(%d:%d), nb(%d:%d)\n",
__func__, clk_hw_get_name(hw), drate, rate->nr, cur.nr,
rate->no, cur.no, rate->nf, cur.nf, rate->nb, cur.nb);
if (rate->nr != cur.nr || rate->no != cur.no || rate->nf != cur.nf
|| rate->nb != cur.nb) {
pr_debug("%s: pll %s: rate params do not match rate table, adjusting\n",
__func__, clk_hw_get_name(hw));
rockchip_rk3066_pll_set_params(pll, rate);
}
}
static int rockchip_rk3399_pll_wait_lock(struct rockchip_clk_pll *pll)
{
u32 pllcon;
int delay = 24000000;
while (delay > 0) {
pllcon = readl_relaxed(pll->reg_base + RK3399_PLLCON(2));
if (pllcon & RK3399_PLLCON2_LOCK_STATUS)
return 0;
delay--;
}
pr_err("%s: timeout waiting for pll to lock\n", __func__);
return -ETIMEDOUT;
}
static void rockchip_rk3399_pll_get_params(struct rockchip_clk_pll *pll,
struct rockchip_pll_rate_table *rate)
{
u32 pllcon;
pllcon = readl_relaxed(pll->reg_base + RK3399_PLLCON(0));
rate->fbdiv = ((pllcon >> RK3399_PLLCON0_FBDIV_SHIFT)
& RK3399_PLLCON0_FBDIV_MASK);
pllcon = readl_relaxed(pll->reg_base + RK3399_PLLCON(1));
rate->refdiv = ((pllcon >> RK3399_PLLCON1_REFDIV_SHIFT)
& RK3399_PLLCON1_REFDIV_MASK);
rate->postdiv1 = ((pllcon >> RK3399_PLLCON1_POSTDIV1_SHIFT)
& RK3399_PLLCON1_POSTDIV1_MASK);
rate->postdiv2 = ((pllcon >> RK3399_PLLCON1_POSTDIV2_SHIFT)
& RK3399_PLLCON1_POSTDIV2_MASK);
pllcon = readl_relaxed(pll->reg_base + RK3399_PLLCON(2));
rate->frac = ((pllcon >> RK3399_PLLCON2_FRAC_SHIFT)
& RK3399_PLLCON2_FRAC_MASK);
pllcon = readl_relaxed(pll->reg_base + RK3399_PLLCON(3));
rate->dsmpd = ((pllcon >> RK3399_PLLCON3_DSMPD_SHIFT)
& RK3399_PLLCON3_DSMPD_MASK);
}
static unsigned long rockchip_rk3399_pll_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
struct rockchip_pll_rate_table cur;
u64 rate64 = prate;
rockchip_rk3399_pll_get_params(pll, &cur);
rate64 *= cur.fbdiv;
do_div(rate64, cur.refdiv);
if (cur.dsmpd == 0) {
u64 frac_rate64 = prate * cur.frac;
do_div(frac_rate64, cur.refdiv);
rate64 += frac_rate64 >> 24;
}
do_div(rate64, cur.postdiv1);
do_div(rate64, cur.postdiv2);
return (unsigned long)rate64;
}
static int rockchip_rk3399_pll_set_params(struct rockchip_clk_pll *pll,
const struct rockchip_pll_rate_table *rate)
{
const struct clk_ops *pll_mux_ops = pll->pll_mux_ops;
struct clk_mux *pll_mux = &pll->pll_mux;
struct rockchip_pll_rate_table cur;
u32 pllcon;
int rate_change_remuxed = 0;
int cur_parent;
int ret;
pr_debug("%s: rate settings for %lu fbdiv: %d, postdiv1: %d, refdiv: %d, postdiv2: %d, dsmpd: %d, frac: %d\n",
__func__, rate->rate, rate->fbdiv, rate->postdiv1, rate->refdiv,
rate->postdiv2, rate->dsmpd, rate->frac);
rockchip_rk3399_pll_get_params(pll, &cur);
cur.rate = 0;
cur_parent = pll_mux_ops->get_parent(&pll_mux->hw);
if (cur_parent == PLL_MODE_NORM) {
pll_mux_ops->set_parent(&pll_mux->hw, PLL_MODE_SLOW);
rate_change_remuxed = 1;
}
writel_relaxed(HIWORD_UPDATE(rate->fbdiv, RK3399_PLLCON0_FBDIV_MASK,
RK3399_PLLCON0_FBDIV_SHIFT),
pll->reg_base + RK3399_PLLCON(0));
writel_relaxed(HIWORD_UPDATE(rate->refdiv, RK3399_PLLCON1_REFDIV_MASK,
RK3399_PLLCON1_REFDIV_SHIFT) |
HIWORD_UPDATE(rate->postdiv1, RK3399_PLLCON1_POSTDIV1_MASK,
RK3399_PLLCON1_POSTDIV1_SHIFT) |
HIWORD_UPDATE(rate->postdiv2, RK3399_PLLCON1_POSTDIV2_MASK,
RK3399_PLLCON1_POSTDIV2_SHIFT),
pll->reg_base + RK3399_PLLCON(1));
pllcon = readl_relaxed(pll->reg_base + RK3399_PLLCON(2));
pllcon &= ~(RK3399_PLLCON2_FRAC_MASK << RK3399_PLLCON2_FRAC_SHIFT);
pllcon |= rate->frac << RK3399_PLLCON2_FRAC_SHIFT;
writel_relaxed(pllcon, pll->reg_base + RK3399_PLLCON(2));
writel_relaxed(HIWORD_UPDATE(rate->dsmpd, RK3399_PLLCON3_DSMPD_MASK,
RK3399_PLLCON3_DSMPD_SHIFT),
pll->reg_base + RK3399_PLLCON(3));
ret = rockchip_rk3399_pll_wait_lock(pll);
if (ret) {
pr_warn("%s: pll update unsuccessful, trying to restore old params\n",
__func__);
rockchip_rk3399_pll_set_params(pll, &cur);
}
if (rate_change_remuxed)
pll_mux_ops->set_parent(&pll_mux->hw, PLL_MODE_NORM);
return ret;
}
static int rockchip_rk3399_pll_set_rate(struct clk_hw *hw, unsigned long drate,
unsigned long prate)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
const struct rockchip_pll_rate_table *rate;
pr_debug("%s: changing %s to %lu with a parent rate of %lu\n",
__func__, __clk_get_name(hw->clk), drate, prate);
rate = rockchip_get_pll_settings(pll, drate);
if (!rate) {
pr_err("%s: Invalid rate : %lu for pll clk %s\n", __func__,
drate, __clk_get_name(hw->clk));
return -EINVAL;
}
return rockchip_rk3399_pll_set_params(pll, rate);
}
static int rockchip_rk3399_pll_enable(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
writel(HIWORD_UPDATE(0, RK3399_PLLCON3_PWRDOWN, 0),
pll->reg_base + RK3399_PLLCON(3));
rockchip_rk3399_pll_wait_lock(pll);
return 0;
}
static void rockchip_rk3399_pll_disable(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
writel(HIWORD_UPDATE(RK3399_PLLCON3_PWRDOWN,
RK3399_PLLCON3_PWRDOWN, 0),
pll->reg_base + RK3399_PLLCON(3));
}
static int rockchip_rk3399_pll_is_enabled(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
u32 pllcon = readl(pll->reg_base + RK3399_PLLCON(3));
return !(pllcon & RK3399_PLLCON3_PWRDOWN);
}
static void rockchip_rk3399_pll_init(struct clk_hw *hw)
{
struct rockchip_clk_pll *pll = to_rockchip_clk_pll(hw);
const struct rockchip_pll_rate_table *rate;
struct rockchip_pll_rate_table cur;
unsigned long drate;
if (!(pll->flags & ROCKCHIP_PLL_SYNC_RATE))
return;
drate = clk_hw_get_rate(hw);
rate = rockchip_get_pll_settings(pll, drate);
if (!rate)
return;
rockchip_rk3399_pll_get_params(pll, &cur);
pr_debug("%s: pll %s@%lu: Hz\n", __func__, __clk_get_name(hw->clk),
drate);
pr_debug("old - fbdiv: %d, postdiv1: %d, refdiv: %d, postdiv2: %d, dsmpd: %d, frac: %d\n",
cur.fbdiv, cur.postdiv1, cur.refdiv, cur.postdiv2,
cur.dsmpd, cur.frac);
pr_debug("new - fbdiv: %d, postdiv1: %d, refdiv: %d, postdiv2: %d, dsmpd: %d, frac: %d\n",
rate->fbdiv, rate->postdiv1, rate->refdiv, rate->postdiv2,
rate->dsmpd, rate->frac);
if (rate->fbdiv != cur.fbdiv || rate->postdiv1 != cur.postdiv1 ||
rate->refdiv != cur.refdiv || rate->postdiv2 != cur.postdiv2 ||
rate->dsmpd != cur.dsmpd ||
(!cur.dsmpd && (rate->frac != cur.frac))) {
struct clk *parent = clk_get_parent(hw->clk);
if (!parent) {
pr_warn("%s: parent of %s not available\n",
__func__, __clk_get_name(hw->clk));
return;
}
pr_debug("%s: pll %s: rate params do not match rate table, adjusting\n",
__func__, __clk_get_name(hw->clk));
rockchip_rk3399_pll_set_params(pll, rate);
}
}
struct clk *rockchip_clk_register_pll(struct rockchip_clk_provider *ctx,
enum rockchip_pll_type pll_type,
const char *name, const char *const *parent_names,
u8 num_parents, int con_offset, int grf_lock_offset,
int lock_shift, int mode_offset, int mode_shift,
struct rockchip_pll_rate_table *rate_table,
unsigned long flags, u8 clk_pll_flags)
{
const char *pll_parents[3];
struct clk_init_data init;
struct rockchip_clk_pll *pll;
struct clk_mux *pll_mux;
struct clk *pll_clk, *mux_clk;
char pll_name[20];
if ((pll_type != pll_rk3328 && num_parents != 2) ||
(pll_type == pll_rk3328 && num_parents != 1)) {
pr_err("%s: needs two parent clocks\n", __func__);
return ERR_PTR(-EINVAL);
}
snprintf(pll_name, sizeof(pll_name), "pll_%s", name);
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
pll->pll_mux_ops = &clk_mux_ops;
pll_mux = &pll->pll_mux;
pll_mux->reg = ctx->reg_base + mode_offset;
pll_mux->shift = mode_shift;
if (pll_type == pll_rk3328)
pll_mux->mask = PLL_RK3328_MODE_MASK;
else
pll_mux->mask = PLL_MODE_MASK;
pll_mux->flags = 0;
pll_mux->lock = &ctx->lock;
pll_mux->hw.init = &init;
if (pll_type == pll_rk3036 ||
pll_type == pll_rk3066 ||
pll_type == pll_rk3328 ||
pll_type == pll_rk3399)
pll_mux->flags |= CLK_MUX_HIWORD_MASK;
pll_parents[0] = parent_names[0];
pll_parents[1] = pll_name;
pll_parents[2] = parent_names[1];
init.name = name;
init.flags = CLK_SET_RATE_PARENT;
init.ops = pll->pll_mux_ops;
init.parent_names = pll_parents;
if (pll_type == pll_rk3328)
init.num_parents = 2;
else
init.num_parents = ARRAY_SIZE(pll_parents);
mux_clk = clk_register(NULL, &pll_mux->hw);
if (IS_ERR(mux_clk))
goto err_mux;
init.name = pll_name;
init.flags = flags | CLK_IGNORE_UNUSED;
init.parent_names = &parent_names[0];
init.num_parents = 1;
if (rate_table) {
int len;
for (len = 0; rate_table[len].rate != 0; )
len++;
pll->rate_count = len;
pll->rate_table = kmemdup(rate_table,
pll->rate_count *
sizeof(struct rockchip_pll_rate_table),
GFP_KERNEL);
WARN(!pll->rate_table,
"%s: could not allocate rate table for %s\n",
__func__, name);
}
switch (pll_type) {
case pll_rk3036:
case pll_rk3328:
if (!pll->rate_table || IS_ERR(ctx->grf))
init.ops = &rockchip_rk3036_pll_clk_norate_ops;
else
init.ops = &rockchip_rk3036_pll_clk_ops;
break;
case pll_rk3066:
if (!pll->rate_table || IS_ERR(ctx->grf))
init.ops = &rockchip_rk3066_pll_clk_norate_ops;
else
init.ops = &rockchip_rk3066_pll_clk_ops;
break;
case pll_rk3399:
if (!pll->rate_table)
init.ops = &rockchip_rk3399_pll_clk_norate_ops;
else
init.ops = &rockchip_rk3399_pll_clk_ops;
break;
default:
pr_warn("%s: Unknown pll type for pll clk %s\n",
__func__, name);
}
pll->hw.init = &init;
pll->type = pll_type;
pll->reg_base = ctx->reg_base + con_offset;
pll->lock_offset = grf_lock_offset;
pll->lock_shift = lock_shift;
pll->flags = clk_pll_flags;
pll->lock = &ctx->lock;
pll->ctx = ctx;
pll_clk = clk_register(NULL, &pll->hw);
if (IS_ERR(pll_clk)) {
pr_err("%s: failed to register pll clock %s : %ld\n",
__func__, name, PTR_ERR(pll_clk));
goto err_pll;
}
return mux_clk;
err_pll:
clk_unregister(mux_clk);
mux_clk = pll_clk;
err_mux:
kfree(pll);
return mux_clk;
}
