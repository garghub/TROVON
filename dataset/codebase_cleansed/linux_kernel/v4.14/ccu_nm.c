static void ccu_nm_find_best(unsigned long parent, unsigned long rate,
struct _ccu_nm *nm)
{
unsigned long best_rate = 0;
unsigned long best_n = 0, best_m = 0;
unsigned long _n, _m;
for (_n = nm->min_n; _n <= nm->max_n; _n++) {
for (_m = nm->min_m; _m <= nm->max_m; _m++) {
unsigned long tmp_rate = parent * _n / _m;
if (tmp_rate > rate)
continue;
if ((rate - tmp_rate) < (rate - best_rate)) {
best_rate = tmp_rate;
best_n = _n;
best_m = _m;
}
}
}
nm->n = best_n;
nm->m = best_m;
}
static void ccu_nm_disable(struct clk_hw *hw)
{
struct ccu_nm *nm = hw_to_ccu_nm(hw);
return ccu_gate_helper_disable(&nm->common, nm->enable);
}
static int ccu_nm_enable(struct clk_hw *hw)
{
struct ccu_nm *nm = hw_to_ccu_nm(hw);
return ccu_gate_helper_enable(&nm->common, nm->enable);
}
static int ccu_nm_is_enabled(struct clk_hw *hw)
{
struct ccu_nm *nm = hw_to_ccu_nm(hw);
return ccu_gate_helper_is_enabled(&nm->common, nm->enable);
}
static unsigned long ccu_nm_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ccu_nm *nm = hw_to_ccu_nm(hw);
unsigned long n, m;
u32 reg;
if (ccu_frac_helper_is_enabled(&nm->common, &nm->frac))
return ccu_frac_helper_read_rate(&nm->common, &nm->frac);
reg = readl(nm->common.base + nm->common.reg);
n = reg >> nm->n.shift;
n &= (1 << nm->n.width) - 1;
n += nm->n.offset;
if (!n)
n++;
m = reg >> nm->m.shift;
m &= (1 << nm->m.width) - 1;
m += nm->m.offset;
if (!m)
m++;
return parent_rate * n / m;
}
static long ccu_nm_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct ccu_nm *nm = hw_to_ccu_nm(hw);
struct _ccu_nm _nm;
_nm.min_n = nm->n.min ?: 1;
_nm.max_n = nm->n.max ?: 1 << nm->n.width;
_nm.min_m = 1;
_nm.max_m = nm->m.max ?: 1 << nm->m.width;
ccu_nm_find_best(*parent_rate, rate, &_nm);
return *parent_rate * _nm.n / _nm.m;
}
static int ccu_nm_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct ccu_nm *nm = hw_to_ccu_nm(hw);
struct _ccu_nm _nm;
unsigned long flags;
u32 reg;
if (ccu_frac_helper_has_rate(&nm->common, &nm->frac, rate)) {
spin_lock_irqsave(nm->common.lock, flags);
reg = readl(nm->common.base + nm->common.reg);
reg &= ~GENMASK(nm->m.width + nm->m.shift - 1, nm->m.shift);
writel(reg, nm->common.base + nm->common.reg);
spin_unlock_irqrestore(nm->common.lock, flags);
ccu_frac_helper_enable(&nm->common, &nm->frac);
return ccu_frac_helper_set_rate(&nm->common, &nm->frac,
rate, nm->lock);
} else {
ccu_frac_helper_disable(&nm->common, &nm->frac);
}
_nm.min_n = nm->n.min ?: 1;
_nm.max_n = nm->n.max ?: 1 << nm->n.width;
_nm.min_m = 1;
_nm.max_m = nm->m.max ?: 1 << nm->m.width;
ccu_nm_find_best(parent_rate, rate, &_nm);
spin_lock_irqsave(nm->common.lock, flags);
reg = readl(nm->common.base + nm->common.reg);
reg &= ~GENMASK(nm->n.width + nm->n.shift - 1, nm->n.shift);
reg &= ~GENMASK(nm->m.width + nm->m.shift - 1, nm->m.shift);
reg |= (_nm.n - nm->n.offset) << nm->n.shift;
reg |= (_nm.m - nm->m.offset) << nm->m.shift;
writel(reg, nm->common.base + nm->common.reg);
spin_unlock_irqrestore(nm->common.lock, flags);
ccu_helper_wait_for_lock(&nm->common, nm->lock);
return 0;
}
