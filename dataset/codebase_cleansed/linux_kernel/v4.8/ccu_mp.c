static void ccu_mp_find_best(unsigned long parent, unsigned long rate,
unsigned int max_m, unsigned int max_p,
unsigned int *m, unsigned int *p)
{
unsigned long best_rate = 0;
unsigned int best_m = 0, best_p = 0;
unsigned int _m, _p;
for (_p = 0; _p <= max_p; _p++) {
for (_m = 1; _m <= max_m; _m++) {
unsigned long tmp_rate = (parent >> _p) / _m;
if (tmp_rate > rate)
continue;
if ((rate - tmp_rate) < (rate - best_rate)) {
best_rate = tmp_rate;
best_m = _m;
best_p = _p;
}
}
}
*m = best_m;
*p = best_p;
}
static unsigned long ccu_mp_round_rate(struct ccu_mux_internal *mux,
unsigned long parent_rate,
unsigned long rate,
void *data)
{
struct ccu_mp *cmp = data;
unsigned int m, p;
ccu_mp_find_best(parent_rate, rate,
1 << cmp->m.width, (1 << cmp->p.width) - 1,
&m, &p);
return (parent_rate >> p) / m;
}
static void ccu_mp_disable(struct clk_hw *hw)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
return ccu_gate_helper_disable(&cmp->common, cmp->enable);
}
static int ccu_mp_enable(struct clk_hw *hw)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
return ccu_gate_helper_enable(&cmp->common, cmp->enable);
}
static int ccu_mp_is_enabled(struct clk_hw *hw)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
return ccu_gate_helper_is_enabled(&cmp->common, cmp->enable);
}
static unsigned long ccu_mp_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
unsigned int m, p;
u32 reg;
reg = readl(cmp->common.base + cmp->common.reg);
m = reg >> cmp->m.shift;
m &= (1 << cmp->m.width) - 1;
p = reg >> cmp->p.shift;
p &= (1 << cmp->p.width) - 1;
return (parent_rate >> p) / (m + 1);
}
static int ccu_mp_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
return ccu_mux_helper_determine_rate(&cmp->common, &cmp->mux,
req, ccu_mp_round_rate, cmp);
}
static int ccu_mp_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
unsigned long flags;
unsigned int m, p;
u32 reg;
ccu_mp_find_best(parent_rate, rate,
1 << cmp->m.width, (1 << cmp->p.width) - 1,
&m, &p);
spin_lock_irqsave(cmp->common.lock, flags);
reg = readl(cmp->common.base + cmp->common.reg);
reg &= ~GENMASK(cmp->m.width + cmp->m.shift - 1, cmp->m.shift);
reg &= ~GENMASK(cmp->p.width + cmp->p.shift - 1, cmp->p.shift);
writel(reg | (p << cmp->p.shift) | ((m - 1) << cmp->m.shift),
cmp->common.base + cmp->common.reg);
spin_unlock_irqrestore(cmp->common.lock, flags);
return 0;
}
static u8 ccu_mp_get_parent(struct clk_hw *hw)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
return ccu_mux_helper_get_parent(&cmp->common, &cmp->mux);
}
static int ccu_mp_set_parent(struct clk_hw *hw, u8 index)
{
struct ccu_mp *cmp = hw_to_ccu_mp(hw);
return ccu_mux_helper_set_parent(&cmp->common, &cmp->mux, index);
}
