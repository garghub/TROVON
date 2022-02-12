void ccu_mux_helper_adjust_parent_for_prediv(struct ccu_common *common,
struct ccu_mux_internal *cm,
int parent_index,
unsigned long *parent_rate)
{
u16 prediv = 1;
u32 reg;
int i;
if (!((common->features & CCU_FEATURE_FIXED_PREDIV) ||
(common->features & CCU_FEATURE_VARIABLE_PREDIV) ||
(common->features & CCU_FEATURE_ALL_PREDIV)))
return;
if (common->features & CCU_FEATURE_ALL_PREDIV) {
*parent_rate = *parent_rate / common->prediv;
return;
}
reg = readl(common->base + common->reg);
if (parent_index < 0) {
parent_index = reg >> cm->shift;
parent_index &= (1 << cm->width) - 1;
}
if (common->features & CCU_FEATURE_FIXED_PREDIV)
for (i = 0; i < cm->n_predivs; i++)
if (parent_index == cm->fixed_predivs[i].index)
prediv = cm->fixed_predivs[i].div;
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
if (cm->table) {
int num_parents = clk_hw_get_num_parents(&common->hw);
int i;
for (i = 0; i < num_parents; i++)
if (cm->table[i] == parent)
return i;
}
return parent;
}
int ccu_mux_helper_set_parent(struct ccu_common *common,
struct ccu_mux_internal *cm,
u8 index)
{
unsigned long flags;
u32 reg;
if (cm->table)
index = cm->table[index];
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
static int ccu_mux_notifier_cb(struct notifier_block *nb,
unsigned long event, void *data)
{
struct ccu_mux_nb *mux = to_ccu_mux_nb(nb);
int ret = 0;
if (event == PRE_RATE_CHANGE) {
mux->original_index = ccu_mux_helper_get_parent(mux->common,
mux->cm);
ret = ccu_mux_helper_set_parent(mux->common, mux->cm,
mux->bypass_index);
} else if (event == POST_RATE_CHANGE) {
ret = ccu_mux_helper_set_parent(mux->common, mux->cm,
mux->original_index);
}
udelay(mux->delay_us);
return notifier_from_errno(ret);
}
int ccu_mux_notifier_register(struct clk *clk, struct ccu_mux_nb *mux_nb)
{
mux_nb->clk_nb.notifier_call = ccu_mux_notifier_cb;
return clk_notifier_register(clk, &mux_nb->clk_nb);
}
