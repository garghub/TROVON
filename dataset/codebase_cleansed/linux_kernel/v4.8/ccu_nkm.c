static void ccu_nkm_find_best(unsigned long parent, unsigned long rate,
struct _ccu_nkm *nkm)
{
unsigned long best_rate = 0;
unsigned long best_n = 0, best_k = 0, best_m = 0;
unsigned long _n, _k, _m;
for (_k = 1; _k <= nkm->max_k; _k++) {
unsigned long tmp_rate;
rational_best_approximation(rate / _k, parent,
nkm->max_n, nkm->max_m, &_n, &_m);
tmp_rate = parent * _n * _k / _m;
if (tmp_rate > rate)
continue;
if ((rate - tmp_rate) < (rate - best_rate)) {
best_rate = tmp_rate;
best_n = _n;
best_k = _k;
best_m = _m;
}
}
nkm->n = best_n;
nkm->k = best_k;
nkm->m = best_m;
}
static void ccu_nkm_disable(struct clk_hw *hw)
{
struct ccu_nkm *nkm = hw_to_ccu_nkm(hw);
return ccu_gate_helper_disable(&nkm->common, nkm->enable);
}
static int ccu_nkm_enable(struct clk_hw *hw)
{
struct ccu_nkm *nkm = hw_to_ccu_nkm(hw);
return ccu_gate_helper_enable(&nkm->common, nkm->enable);
}
static int ccu_nkm_is_enabled(struct clk_hw *hw)
{
struct ccu_nkm *nkm = hw_to_ccu_nkm(hw);
return ccu_gate_helper_is_enabled(&nkm->common, nkm->enable);
}
static unsigned long ccu_nkm_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ccu_nkm *nkm = hw_to_ccu_nkm(hw);
unsigned long n, m, k;
u32 reg;
reg = readl(nkm->common.base + nkm->common.reg);
n = reg >> nkm->n.shift;
n &= (1 << nkm->n.width) - 1;
k = reg >> nkm->k.shift;
k &= (1 << nkm->k.width) - 1;
m = reg >> nkm->m.shift;
m &= (1 << nkm->m.width) - 1;
return parent_rate * (n + 1) * (k + 1) / (m + 1);
}
static long ccu_nkm_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct ccu_nkm *nkm = hw_to_ccu_nkm(hw);
struct _ccu_nkm _nkm;
_nkm.max_n = 1 << nkm->n.width;
_nkm.max_k = 1 << nkm->k.width;
_nkm.max_m = 1 << nkm->m.width;
ccu_nkm_find_best(*parent_rate, rate, &_nkm);
return *parent_rate * _nkm.n * _nkm.k / _nkm.m;
}
static int ccu_nkm_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct ccu_nkm *nkm = hw_to_ccu_nkm(hw);
struct _ccu_nkm _nkm;
unsigned long flags;
u32 reg;
_nkm.max_n = 1 << nkm->n.width;
_nkm.max_k = 1 << nkm->k.width;
_nkm.max_m = 1 << nkm->m.width;
ccu_nkm_find_best(parent_rate, rate, &_nkm);
spin_lock_irqsave(nkm->common.lock, flags);
reg = readl(nkm->common.base + nkm->common.reg);
reg &= ~GENMASK(nkm->n.width + nkm->n.shift - 1, nkm->n.shift);
reg &= ~GENMASK(nkm->k.width + nkm->k.shift - 1, nkm->k.shift);
reg &= ~GENMASK(nkm->m.width + nkm->m.shift - 1, nkm->m.shift);
reg |= (_nkm.n - 1) << nkm->n.shift;
reg |= (_nkm.k - 1) << nkm->k.shift;
reg |= (_nkm.m - 1) << nkm->m.shift;
writel(reg, nkm->common.base + nkm->common.reg);
spin_unlock_irqrestore(nkm->common.lock, flags);
ccu_helper_wait_for_lock(&nkm->common, nkm->lock);
return 0;
}
