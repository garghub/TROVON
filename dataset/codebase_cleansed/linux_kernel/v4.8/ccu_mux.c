void ccu_mux_helper_adjust_parent_for_prediv(struct ccu_common *common,
struct ccu_mux_internal *cm,
int parent_index,
unsigned long *parent_rate)
{
u8 prediv = 1;
u32 reg;
if (!((common->features & CCU_FEATURE_FIXED_PREDIV) ||
(common->features & CCU_FEATURE_VARIABLE_PREDIV)))
return;
reg = readl(common->base + common->reg);
if (parent_index < 0) {
parent_index = reg >> cm->shift;
parent_index &= (1 << cm->width) - 1;
}
if (common->features & CCU_FEATURE_FIXED_PREDIV)
if (parent_index == cm->fixed_prediv.index)
prediv = cm->fixed_prediv.div;
if (common->features & CCU_FEATURE_VARIABLE_PREDIV)
if (parent_index == cm->variable_prediv.index) {
u8 div;
div = reg >> cm->variable_prediv.shift;
div &= (1 << cm->variable_prediv.width) - 1;
prediv = div + 1;
}
*parent_rate = *parent_rate / prediv;
}
u8 ccu_mux_helper_get_parent(struct ccu_common *common,
struct ccu_mux_internal *cm)
{
u32 reg;
u8 parent;
reg = readl(common->base + common->reg);
parent = reg >> cm->shift;
parent &= (1 << cm->width) - 1;
return parent;
}
int ccu_mux_helper_set_parent(struct ccu_common *common,
struct ccu_mux_internal *cm,
u8 index)
{
unsigned long flags;
u32 reg;
spin_lock_irqsave(common->lock, flags);
reg = readl(common->base + common->reg);
reg &= ~GENMASK(cm->width + cm->shift - 1, cm->shift);
writel(reg | (index << cm->shift), common->base + common->reg);
spin_unlock_irqrestore(common->lock, flags);
return 0;
}
static void ccu_mux_disable(struct clk_hw *hw)
{
struct ccu_mux *cm = hw_to_ccu_mux(hw);
return ccu_gate_helper_disable(&cm->common, cm->enable);
}
static int ccu_mux_enable(struct clk_hw *hw)
{
struct ccu_mux *cm = hw_to_ccu_mux(hw);
return ccu_gate_helper_enable(&cm->common, cm->enable);
}
static int ccu_mux_is_enabled(struct clk_hw *hw)
{
struct ccu_mux *cm = hw_to_ccu_mux(hw);
return ccu_gate_helper_is_enabled(&cm->common, cm->enable);
}
static u8 ccu_mux_get_parent(struct clk_hw *hw)
{
struct ccu_mux *cm = hw_to_ccu_mux(hw);
return ccu_mux_helper_get_parent(&cm->common, &cm->mux);
}
static int ccu_mux_set_parent(struct clk_hw *hw, u8 index)
{
struct ccu_mux *cm = hw_to_ccu_mux(hw);
return ccu_mux_helper_set_parent(&cm->common, &cm->mux, index);
}
static unsigned long ccu_mux_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct ccu_mux *cm = hw_to_ccu_mux(hw);
ccu_mux_helper_adjust_parent_for_prediv(&cm->common, &cm->mux, -1,
&parent_rate);
return parent_rate;
}
