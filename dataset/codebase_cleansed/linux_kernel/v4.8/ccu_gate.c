void ccu_gate_helper_disable(struct ccu_common *common, u32 gate)
{
unsigned long flags;
u32 reg;
if (!gate)
return;
spin_lock_irqsave(common->lock, flags);
reg = readl(common->base + common->reg);
writel(reg & ~gate, common->base + common->reg);
spin_unlock_irqrestore(common->lock, flags);
}
static void ccu_gate_disable(struct clk_hw *hw)
{
struct ccu_gate *cg = hw_to_ccu_gate(hw);
return ccu_gate_helper_disable(&cg->common, cg->enable);
}
int ccu_gate_helper_enable(struct ccu_common *common, u32 gate)
{
unsigned long flags;
u32 reg;
if (!gate)
return 0;
spin_lock_irqsave(common->lock, flags);
reg = readl(common->base + common->reg);
writel(reg | gate, common->base + common->reg);
spin_unlock_irqrestore(common->lock, flags);
return 0;
}
static int ccu_gate_enable(struct clk_hw *hw)
{
struct ccu_gate *cg = hw_to_ccu_gate(hw);
return ccu_gate_helper_enable(&cg->common, cg->enable);
}
int ccu_gate_helper_is_enabled(struct ccu_common *common, u32 gate)
{
if (!gate)
return 1;
return readl(common->base + common->reg) & gate;
}
static int ccu_gate_is_enabled(struct clk_hw *hw)
{
struct ccu_gate *cg = hw_to_ccu_gate(hw);
return ccu_gate_helper_is_enabled(&cg->common, cg->enable);
}
