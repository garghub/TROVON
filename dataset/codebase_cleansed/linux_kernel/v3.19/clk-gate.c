static int mmp_clk_gate_enable(struct clk_hw *hw)
{
struct mmp_clk_gate *gate = to_clk_mmp_gate(hw);
struct clk *clk = hw->clk;
unsigned long flags = 0;
unsigned long rate;
u32 tmp;
if (gate->lock)
spin_lock_irqsave(gate->lock, flags);
tmp = readl(gate->reg);
tmp &= ~gate->mask;
tmp |= gate->val_enable;
writel(tmp, gate->reg);
if (gate->lock)
spin_unlock_irqrestore(gate->lock, flags);
if (gate->flags & MMP_CLK_GATE_NEED_DELAY) {
rate = __clk_get_rate(clk);
udelay(2000000/rate);
}
return 0;
}
static void mmp_clk_gate_disable(struct clk_hw *hw)
{
struct mmp_clk_gate *gate = to_clk_mmp_gate(hw);
unsigned long flags = 0;
u32 tmp;
if (gate->lock)
spin_lock_irqsave(gate->lock, flags);
tmp = readl(gate->reg);
tmp &= ~gate->mask;
tmp |= gate->val_disable;
writel(tmp, gate->reg);
if (gate->lock)
spin_unlock_irqrestore(gate->lock, flags);
}
static int mmp_clk_gate_is_enabled(struct clk_hw *hw)
{
struct mmp_clk_gate *gate = to_clk_mmp_gate(hw);
unsigned long flags = 0;
u32 tmp;
if (gate->lock)
spin_lock_irqsave(gate->lock, flags);
tmp = readl(gate->reg);
if (gate->lock)
spin_unlock_irqrestore(gate->lock, flags);
return (tmp & gate->mask) == gate->val_enable;
}
struct clk *mmp_clk_register_gate(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u32 mask, u32 val_enable, u32 val_disable,
unsigned int gate_flags, spinlock_t *lock)
{
struct mmp_clk_gate *gate;
struct clk *clk;
struct clk_init_data init;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate) {
pr_err("%s:%s could not allocate gate clk\n", __func__, name);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &mmp_clk_gate_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
gate->reg = reg;
gate->mask = mask;
gate->val_enable = val_enable;
gate->val_disable = val_disable;
gate->flags = gate_flags;
gate->lock = lock;
gate->hw.init = &init;
clk = clk_register(dev, &gate->hw);
if (IS_ERR(clk))
kfree(gate);
return clk;
}
