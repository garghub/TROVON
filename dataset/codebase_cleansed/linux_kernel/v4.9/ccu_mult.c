static void ccu_mult_find_best(unsigned long parent, unsigned long rate,
unsigned int max_n, unsigned int *n)
{
*n = rate / parent;
}
static unsigned long ccu_mult_round_rate(struct ccu_mux_internal *mux,
unsigned long parent_rate,
unsigned long rate,
void *data)
{
struct ccu_mult *cm = data;
unsigned int n;
ccu_mult_find_best(parent_rate, rate, 1 << cm->mult.width, &n);
return parent_rate * n;
}
static void ccu_mult_disable(struct clk_hw *hw)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
return ccu_gate_helper_disable(&cm->common, cm->enable);
}
static int ccu_mult_enable(struct clk_hw *hw)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
return ccu_gate_helper_enable(&cm->common, cm->enable);
}
static int ccu_mult_is_enabled(struct clk_hw *hw)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
return ccu_gate_helper_is_enabled(&cm->common, cm->enable);
}
static unsigned long ccu_mult_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
unsigned long val;
u32 reg;
reg = readl(cm->common.base + cm->common.reg);
val = reg >> cm->mult.shift;
val &= (1 << cm->mult.width) - 1;
ccu_mux_helper_adjust_parent_for_prediv(&cm->common, &cm->mux, -1,
&parent_rate);
return parent_rate * (val + 1);
}
static int ccu_mult_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
return ccu_mux_helper_determine_rate(&cm->common, &cm->mux,
req, ccu_mult_round_rate, cm);
}
static int ccu_mult_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
unsigned long flags;
unsigned int n;
u32 reg;
ccu_mux_helper_adjust_parent_for_prediv(&cm->common, &cm->mux, -1,
&parent_rate);
ccu_mult_find_best(parent_rate, rate, 1 << cm->mult.width, &n);
spin_lock_irqsave(cm->common.lock, flags);
reg = readl(cm->common.base + cm->common.reg);
reg &= ~GENMASK(cm->mult.width + cm->mult.shift - 1, cm->mult.shift);
writel(reg | ((n - 1) << cm->mult.shift),
cm->common.base + cm->common.reg);
spin_unlock_irqrestore(cm->common.lock, flags);
return 0;
}
static u8 ccu_mult_get_parent(struct clk_hw *hw)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
return ccu_mux_helper_get_parent(&cm->common, &cm->mux);
}
static int ccu_mult_set_parent(struct clk_hw *hw, u8 index)
{
struct ccu_mult *cm = hw_to_ccu_mult(hw);
return ccu_mux_helper_set_parent(&cm->common, &cm->mux, index);
}
