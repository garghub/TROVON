static int pbclk_is_enabled(struct clk_hw *hw)
{
struct pic32_periph_clk *pb = clkhw_to_pbclk(hw);
return readl(pb->ctrl_reg) & PB_DIV_ENABLE;
}
static int pbclk_enable(struct clk_hw *hw)
{
struct pic32_periph_clk *pb = clkhw_to_pbclk(hw);
writel(PB_DIV_ENABLE, PIC32_SET(pb->ctrl_reg));
return 0;
}
static void pbclk_disable(struct clk_hw *hw)
{
struct pic32_periph_clk *pb = clkhw_to_pbclk(hw);
writel(PB_DIV_ENABLE, PIC32_CLR(pb->ctrl_reg));
}
static unsigned long calc_best_divided_rate(unsigned long rate,
unsigned long parent_rate,
u32 divider_max,
u32 divider_min)
{
unsigned long divided_rate, divided_rate_down, best_rate;
unsigned long div, div_up;
div = parent_rate / rate;
div = clamp_val(div, divider_min, divider_max);
div_up = clamp_val(div + 1, divider_min, divider_max);
divided_rate = parent_rate / div;
divided_rate_down = parent_rate / div_up;
if (abs(rate - divided_rate_down) < abs(rate - divided_rate))
best_rate = divided_rate_down;
else
best_rate = divided_rate;
return best_rate;
}
static inline u32 pbclk_read_pbdiv(struct pic32_periph_clk *pb)
{
return ((readl(pb->ctrl_reg) >> PB_DIV_SHIFT) & PB_DIV_MASK) + 1;
}
static unsigned long pbclk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct pic32_periph_clk *pb = clkhw_to_pbclk(hw);
return parent_rate / pbclk_read_pbdiv(pb);
}
static long pbclk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
return calc_best_divided_rate(rate, *parent_rate,
PB_DIV_MAX, PB_DIV_MIN);
}
static int pbclk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct pic32_periph_clk *pb = clkhw_to_pbclk(hw);
unsigned long flags;
u32 v, div;
int err;
err = readl_poll_timeout(pb->ctrl_reg, v, v & PB_DIV_READY,
1, LOCK_TIMEOUT_US);
if (err)
return err;
div = DIV_ROUND_CLOSEST(parent_rate, rate);
spin_lock_irqsave(&pb->core->reg_lock, flags);
v = readl(pb->ctrl_reg);
v &= ~PB_DIV_MASK;
v |= (div - 1);
pic32_syskey_unlock();
writel(v, pb->ctrl_reg);
spin_unlock_irqrestore(&pb->core->reg_lock, flags);
err = readl_poll_timeout(pb->ctrl_reg, v, v & PB_DIV_READY,
1, LOCK_TIMEOUT_US);
if (err)
return err;
return (pbclk_read_pbdiv(pb) == div) ? 0 : -EBUSY;
}
struct clk *pic32_periph_clk_register(const struct pic32_periph_clk_data *desc,
struct pic32_clk_common *core)
{
struct pic32_periph_clk *pbclk;
struct clk *clk;
pbclk = devm_kzalloc(core->dev, sizeof(*pbclk), GFP_KERNEL);
if (!pbclk)
return ERR_PTR(-ENOMEM);
pbclk->hw.init = &desc->init_data;
pbclk->core = core;
pbclk->ctrl_reg = desc->ctrl_reg + core->iobase;
clk = devm_clk_register(core->dev, &pbclk->hw);
if (IS_ERR(clk)) {
dev_err(core->dev, "%s: clk_register() failed\n", __func__);
devm_kfree(core->dev, pbclk);
}
return clk;
}
static int roclk_is_enabled(struct clk_hw *hw)
{
struct pic32_ref_osc *refo = clkhw_to_refosc(hw);
return readl(refo->ctrl_reg) & REFO_ON;
}
static int roclk_enable(struct clk_hw *hw)
{
struct pic32_ref_osc *refo = clkhw_to_refosc(hw);
writel(REFO_ON | REFO_OE, PIC32_SET(refo->ctrl_reg));
return 0;
}
static void roclk_disable(struct clk_hw *hw)
{
struct pic32_ref_osc *refo = clkhw_to_refosc(hw);
writel(REFO_ON | REFO_OE, PIC32_CLR(refo->ctrl_reg));
}
static void roclk_init(struct clk_hw *hw)
{
roclk_disable(hw);
}
static u8 roclk_get_parent(struct clk_hw *hw)
{
struct pic32_ref_osc *refo = clkhw_to_refosc(hw);
u32 v, i;
v = (readl(refo->ctrl_reg) >> REFO_SEL_SHIFT) & REFO_SEL_MASK;
if (!refo->parent_map)
return v;
for (i = 0; i < clk_hw_get_num_parents(hw); i++)
if (refo->parent_map[i] == v)
return i;
return -EINVAL;
}
static unsigned long roclk_calc_rate(unsigned long parent_rate,
u32 rodiv, u32 rotrim)
{
u64 rate64;
if (rotrim) {
rodiv = (rodiv << 9) + rotrim;
rate64 = parent_rate;
rate64 <<= 8;
do_div(rate64, rodiv);
} else if (rodiv) {
rate64 = parent_rate / (rodiv << 1);
} else {
rate64 = parent_rate;
}
return rate64;
}
static void roclk_calc_div_trim(unsigned long rate,
unsigned long parent_rate,
u32 *rodiv_p, u32 *rotrim_p)
{
u32 div, rotrim, rodiv;
u64 frac;
if (parent_rate <= rate) {
div = 0;
frac = 0;
rodiv = 0;
rotrim = 0;
} else {
div = parent_rate / (rate << 1);
frac = parent_rate;
frac <<= 8;
do_div(frac, rate);
frac -= (u64)(div << 9);
rodiv = (div > REFO_DIV_MASK) ? REFO_DIV_MASK : div;
rotrim = (frac >= REFO_TRIM_MAX) ? REFO_TRIM_MAX : frac;
}
if (rodiv_p)
*rodiv_p = rodiv;
if (rotrim_p)
*rotrim_p = rotrim;
}
static unsigned long roclk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct pic32_ref_osc *refo = clkhw_to_refosc(hw);
u32 v, rodiv, rotrim;
v = readl(refo->ctrl_reg);
rodiv = (v >> REFO_DIV_SHIFT) & REFO_DIV_MASK;
v = readl(refo->ctrl_reg + REFO_TRIM_REG);
rotrim = (v >> REFO_TRIM_SHIFT) & REFO_TRIM_MASK;
return roclk_calc_rate(parent_rate, rodiv, rotrim);
}
static long roclk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
u32 rotrim, rodiv;
roclk_calc_div_trim(rate, *parent_rate, &rodiv, &rotrim);
return roclk_calc_rate(*parent_rate, rodiv, rotrim);
}
static int roclk_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_hw *parent_clk, *best_parent_clk = NULL;
unsigned int i, delta, best_delta = -1;
unsigned long parent_rate, best_parent_rate = 0;
unsigned long best = 0, nearest_rate;
for (i = 0; i < clk_hw_get_num_parents(hw); i++) {
parent_clk = clk_hw_get_parent_by_index(hw, i);
if (!parent_clk)
continue;
parent_rate = clk_hw_get_rate(parent_clk);
if (req->rate > parent_rate)
continue;
nearest_rate = roclk_round_rate(hw, req->rate, &parent_rate);
delta = abs(nearest_rate - req->rate);
if ((nearest_rate >= req->rate) && (delta < best_delta)) {
best_parent_clk = parent_clk;
best_parent_rate = parent_rate;
best = nearest_rate;
best_delta = delta;
if (delta == 0)
break;
}
}
if (!best_parent_clk) {
pr_err("%s:%s, no parent found for rate %lu.\n",
__func__, clk_hw_get_name(hw), req->rate);
return clk_hw_get_rate(hw);
}
pr_debug("%s,rate %lu, best_parent(%s, %lu), best %lu, delta %d\n",
clk_hw_get_name(hw), req->rate,
clk_hw_get_name(best_parent_clk), best_parent_rate,
best, best_delta);
if (req->best_parent_rate)
req->best_parent_rate = best_parent_rate;
if (req->best_parent_hw)
req->best_parent_hw = best_parent_clk;
return best;
}
static int roclk_set_parent(struct clk_hw *hw, u8 index)
{
struct pic32_ref_osc *refo = clkhw_to_refosc(hw);
unsigned long flags;
u32 v;
int err;
if (refo->parent_map)
index = refo->parent_map[index];
err = readl_poll_timeout(refo->ctrl_reg, v, !(v & REFO_ACTIVE),
1, LOCK_TIMEOUT_US);
if (err) {
pr_err("%s: poll failed, clk active\n", clk_hw_get_name(hw));
return err;
}
spin_lock_irqsave(&refo->core->reg_lock, flags);
pic32_syskey_unlock();
v = readl(refo->ctrl_reg);
v &= ~(REFO_SEL_MASK << REFO_SEL_SHIFT);
v |= index << REFO_SEL_SHIFT;
writel(v, refo->ctrl_reg);
spin_unlock_irqrestore(&refo->core->reg_lock, flags);
return 0;
}
static int roclk_set_rate_and_parent(struct clk_hw *hw,
unsigned long rate,
unsigned long parent_rate,
u8 index)
{
struct pic32_ref_osc *refo = clkhw_to_refosc(hw);
unsigned long flags;
u32 trim, rodiv, v;
int err;
roclk_calc_div_trim(rate, parent_rate, &rodiv, &trim);
pr_debug("parent_rate = %lu, rate = %lu, div = %d, trim = %d\n",
parent_rate, rate, rodiv, trim);
err = readl_poll_timeout(refo->ctrl_reg, v,
!(v & (REFO_ACTIVE | REFO_DIVSW_EN)),
1, LOCK_TIMEOUT_US);
if (err) {
pr_err("%s: poll timedout, clock is still active\n", __func__);
return err;
}
spin_lock_irqsave(&refo->core->reg_lock, flags);
v = readl(refo->ctrl_reg);
pic32_syskey_unlock();
if (refo->parent_map)
index = refo->parent_map[index];
v &= ~(REFO_SEL_MASK << REFO_SEL_SHIFT);
v |= index << REFO_SEL_SHIFT;
v &= ~(REFO_DIV_MASK << REFO_DIV_SHIFT);
v |= rodiv << REFO_DIV_SHIFT;
writel(v, refo->ctrl_reg);
v = readl(refo->ctrl_reg + REFO_TRIM_REG);
v &= ~(REFO_TRIM_MASK << REFO_TRIM_SHIFT);
v |= trim << REFO_TRIM_SHIFT;
writel(v, refo->ctrl_reg + REFO_TRIM_REG);
writel(REFO_ON | REFO_DIVSW_EN, PIC32_SET(refo->ctrl_reg));
err = readl_poll_timeout_atomic(refo->ctrl_reg, v, !(v & REFO_DIVSW_EN),
1, LOCK_TIMEOUT_US);
writel(REFO_ON, PIC32_CLR(refo->ctrl_reg));
spin_unlock_irqrestore(&refo->core->reg_lock, flags);
return err;
}
static int roclk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
u8 index = roclk_get_parent(hw);
return roclk_set_rate_and_parent(hw, rate, parent_rate, index);
}
struct clk *pic32_refo_clk_register(const struct pic32_ref_osc_data *data,
struct pic32_clk_common *core)
{
struct pic32_ref_osc *refo;
struct clk *clk;
refo = devm_kzalloc(core->dev, sizeof(*refo), GFP_KERNEL);
if (!refo)
return ERR_PTR(-ENOMEM);
refo->core = core;
refo->hw.init = &data->init_data;
refo->ctrl_reg = data->ctrl_reg + core->iobase;
refo->parent_map = data->parent_map;
clk = devm_clk_register(core->dev, &refo->hw);
if (IS_ERR(clk))
dev_err(core->dev, "%s: clk_register() failed\n", __func__);
return clk;
}
static inline u32 spll_odiv_to_divider(u32 odiv)
{
odiv = clamp_val(odiv, PLL_ODIV_MIN, PLL_ODIV_MAX);
return 1 << odiv;
}
static unsigned long spll_calc_mult_div(struct pic32_sys_pll *pll,
unsigned long rate,
unsigned long parent_rate,
u32 *mult_p, u32 *odiv_p)
{
u32 mul, div, best_mul = 1, best_div = 1;
unsigned long new_rate, best_rate = rate;
unsigned int best_delta = -1, delta, match_found = 0;
u64 rate64;
parent_rate /= pll->idiv;
for (mul = 1; mul <= PLL_MULT_MAX; mul++) {
for (div = PLL_ODIV_MIN; div <= PLL_ODIV_MAX; div++) {
rate64 = parent_rate;
rate64 *= mul;
do_div(rate64, 1 << div);
new_rate = rate64;
delta = abs(rate - new_rate);
if ((new_rate >= rate) && (delta < best_delta)) {
best_delta = delta;
best_rate = new_rate;
best_mul = mul;
best_div = div;
match_found = 1;
}
}
}
if (!match_found) {
pr_warn("spll: no match found\n");
return 0;
}
pr_debug("rate %lu, par_rate %lu/mult %u, div %u, best_rate %lu\n",
rate, parent_rate, best_mul, best_div, best_rate);
if (mult_p)
*mult_p = best_mul - 1;
if (odiv_p)
*odiv_p = best_div;
return best_rate;
}
static unsigned long spll_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct pic32_sys_pll *pll = clkhw_to_spll(hw);
unsigned long pll_in_rate;
u32 mult, odiv, div, v;
u64 rate64;
v = readl(pll->ctrl_reg);
odiv = ((v >> PLL_ODIV_SHIFT) & PLL_ODIV_MASK);
mult = ((v >> PLL_MULT_SHIFT) & PLL_MULT_MASK) + 1;
div = spll_odiv_to_divider(odiv);
pll_in_rate = parent_rate / pll->idiv;
rate64 = pll_in_rate;
rate64 *= mult;
do_div(rate64, div);
return rate64;
}
static long spll_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct pic32_sys_pll *pll = clkhw_to_spll(hw);
return spll_calc_mult_div(pll, rate, *parent_rate, NULL, NULL);
}
static int spll_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct pic32_sys_pll *pll = clkhw_to_spll(hw);
unsigned long ret, flags;
u32 mult, odiv, v;
int err;
ret = spll_calc_mult_div(pll, rate, parent_rate, &mult, &odiv);
if (!ret)
return -EINVAL;
if (unlikely(clk_hw_get_parent(pic32_sclk_hw) == hw)) {
pr_err("%s: failed, clk in-use\n", __func__);
return -EBUSY;
}
spin_lock_irqsave(&pll->core->reg_lock, flags);
v = readl(pll->ctrl_reg);
v &= ~(PLL_MULT_MASK << PLL_MULT_SHIFT);
v &= ~(PLL_ODIV_MASK << PLL_ODIV_SHIFT);
v |= (mult << PLL_MULT_SHIFT) | (odiv << PLL_ODIV_SHIFT);
pic32_syskey_unlock();
writel(v, pll->ctrl_reg);
cpu_relax();
cpu_nop5();
cpu_nop5();
err = readl_poll_timeout_atomic(pll->status_reg, v,
v & pll->lock_mask, 1, 100);
spin_unlock_irqrestore(&pll->core->reg_lock, flags);
return err;
}
struct clk *pic32_spll_clk_register(const struct pic32_sys_pll_data *data,
struct pic32_clk_common *core)
{
struct pic32_sys_pll *spll;
struct clk *clk;
spll = devm_kzalloc(core->dev, sizeof(*spll), GFP_KERNEL);
if (!spll)
return ERR_PTR(-ENOMEM);
spll->core = core;
spll->hw.init = &data->init_data;
spll->ctrl_reg = data->ctrl_reg + core->iobase;
spll->status_reg = data->status_reg + core->iobase;
spll->lock_mask = data->lock_mask;
spll->idiv = (readl(spll->ctrl_reg) >> PLL_IDIV_SHIFT) & PLL_IDIV_MASK;
spll->idiv += 1;
clk = devm_clk_register(core->dev, &spll->hw);
if (IS_ERR(clk))
dev_err(core->dev, "sys_pll: clk_register() failed\n");
return clk;
}
static unsigned long sclk_get_rate(struct clk_hw *hw, unsigned long parent_rate)
{
struct pic32_sys_clk *sclk = clkhw_to_sys_clk(hw);
u32 div;
div = (readl(sclk->slew_reg) >> SLEW_SYSDIV_SHIFT) & SLEW_SYSDIV;
div += 1;
return parent_rate / div;
}
static long sclk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
return calc_best_divided_rate(rate, *parent_rate, SLEW_SYSDIV, 1);
}
static int sclk_set_rate(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate)
{
struct pic32_sys_clk *sclk = clkhw_to_sys_clk(hw);
unsigned long flags;
u32 v, div;
int err;
div = parent_rate / rate;
spin_lock_irqsave(&sclk->core->reg_lock, flags);
v = readl(sclk->slew_reg);
v &= ~(SLEW_SYSDIV << SLEW_SYSDIV_SHIFT);
v |= (div - 1) << SLEW_SYSDIV_SHIFT;
pic32_syskey_unlock();
writel(v, sclk->slew_reg);
err = readl_poll_timeout_atomic(sclk->slew_reg, v,
!(v & SLEW_BUSY), 1, LOCK_TIMEOUT_US);
spin_unlock_irqrestore(&sclk->core->reg_lock, flags);
return err;
}
static u8 sclk_get_parent(struct clk_hw *hw)
{
struct pic32_sys_clk *sclk = clkhw_to_sys_clk(hw);
u32 i, v;
v = (readl(sclk->mux_reg) >> OSC_CUR_SHIFT) & OSC_CUR_MASK;
if (!sclk->parent_map)
return v;
for (i = 0; i < clk_hw_get_num_parents(hw); i++)
if (sclk->parent_map[i] == v)
return i;
return -EINVAL;
}
static int sclk_set_parent(struct clk_hw *hw, u8 index)
{
struct pic32_sys_clk *sclk = clkhw_to_sys_clk(hw);
unsigned long flags;
u32 nosc, cosc, v;
int err;
spin_lock_irqsave(&sclk->core->reg_lock, flags);
nosc = sclk->parent_map ? sclk->parent_map[index] : index;
v = readl(sclk->mux_reg);
v &= ~(OSC_NEW_MASK << OSC_NEW_SHIFT);
v |= nosc << OSC_NEW_SHIFT;
pic32_syskey_unlock();
writel(v, sclk->mux_reg);
writel(OSC_SWEN, PIC32_SET(sclk->mux_reg));
cpu_relax();
cpu_nop5();
err = readl_poll_timeout_atomic(sclk->slew_reg, v,
!(v & OSC_SWEN), 1, LOCK_TIMEOUT_US);
spin_unlock_irqrestore(&sclk->core->reg_lock, flags);
cosc = (readl(sclk->mux_reg) >> OSC_CUR_SHIFT) & OSC_CUR_MASK;
if (cosc != nosc) {
pr_err("%s: err, failed to set_parent() to %d, current %d\n",
clk_hw_get_name(hw), nosc, cosc);
err = -EBUSY;
}
return err;
}
static void sclk_init(struct clk_hw *hw)
{
struct pic32_sys_clk *sclk = clkhw_to_sys_clk(hw);
unsigned long flags;
u32 v;
pic32_sclk_hw = hw;
if (sclk->slew_div) {
spin_lock_irqsave(&sclk->core->reg_lock, flags);
v = readl(sclk->slew_reg);
v &= ~(SLEW_DIV << SLEW_DIV_SHIFT);
v |= sclk->slew_div << SLEW_DIV_SHIFT;
v |= SLEW_DOWNEN | SLEW_UPEN;
writel(v, sclk->slew_reg);
spin_unlock_irqrestore(&sclk->core->reg_lock, flags);
}
}
struct clk *pic32_sys_clk_register(const struct pic32_sys_clk_data *data,
struct pic32_clk_common *core)
{
struct pic32_sys_clk *sclk;
struct clk *clk;
sclk = devm_kzalloc(core->dev, sizeof(*sclk), GFP_KERNEL);
if (!sclk)
return ERR_PTR(-ENOMEM);
sclk->core = core;
sclk->hw.init = &data->init_data;
sclk->mux_reg = data->mux_reg + core->iobase;
sclk->slew_reg = data->slew_reg + core->iobase;
sclk->slew_div = data->slew_div;
sclk->parent_map = data->parent_map;
clk = devm_clk_register(core->dev, &sclk->hw);
if (IS_ERR(clk))
dev_err(core->dev, "%s: clk register failed\n", __func__);
return clk;
}
static int sosc_clk_enable(struct clk_hw *hw)
{
struct pic32_sec_osc *sosc = clkhw_to_sosc(hw);
u32 v;
pic32_syskey_unlock();
writel(sosc->enable_mask, PIC32_SET(sosc->enable_reg));
return readl_poll_timeout_atomic(sosc->status_reg, v,
v & sosc->status_mask, 1, 100);
}
static void sosc_clk_disable(struct clk_hw *hw)
{
struct pic32_sec_osc *sosc = clkhw_to_sosc(hw);
pic32_syskey_unlock();
writel(sosc->enable_mask, PIC32_CLR(sosc->enable_reg));
}
static int sosc_clk_is_enabled(struct clk_hw *hw)
{
struct pic32_sec_osc *sosc = clkhw_to_sosc(hw);
u32 enabled, ready;
enabled = readl(sosc->enable_reg) & sosc->enable_mask;
ready = readl(sosc->status_reg) & sosc->status_mask;
return enabled && ready;
}
static unsigned long sosc_clk_calc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return clkhw_to_sosc(hw)->fixed_rate;
}
struct clk *pic32_sosc_clk_register(const struct pic32_sec_osc_data *data,
struct pic32_clk_common *core)
{
struct pic32_sec_osc *sosc;
sosc = devm_kzalloc(core->dev, sizeof(*sosc), GFP_KERNEL);
if (!sosc)
return ERR_PTR(-ENOMEM);
sosc->core = core;
sosc->hw.init = &data->init_data;
sosc->fixed_rate = data->fixed_rate;
sosc->enable_mask = data->enable_mask;
sosc->status_mask = data->status_mask;
sosc->enable_reg = data->enable_reg + core->iobase;
sosc->status_reg = data->status_reg + core->iobase;
return devm_clk_register(core->dev, &sosc->hw);
}
