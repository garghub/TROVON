static int clk_gate2_enable(struct clk_hw *hw)
{
struct clk_gate *gate = to_clk_gate(hw);
u32 reg;
unsigned long flags = 0;
if (gate->lock)
spin_lock_irqsave(gate->lock, flags);
reg = readl(gate->reg);
reg |= 3 << gate->bit_idx;
writel(reg, gate->reg);
if (gate->lock)
spin_unlock_irqrestore(gate->lock, flags);
return 0;
}
static void clk_gate2_disable(struct clk_hw *hw)
{
struct clk_gate *gate = to_clk_gate(hw);
u32 reg;
unsigned long flags = 0;
if (gate->lock)
spin_lock_irqsave(gate->lock, flags);
reg = readl(gate->reg);
reg &= ~(3 << gate->bit_idx);
writel(reg, gate->reg);
if (gate->lock)
spin_unlock_irqrestore(gate->lock, flags);
}
static int clk_gate2_is_enabled(struct clk_hw *hw)
{
u32 reg;
struct clk_gate *gate = to_clk_gate(hw);
reg = readl(gate->reg);
if (((reg >> gate->bit_idx) & 3) == 3)
return 1;
return 0;
}
struct clk *clk_register_gate2(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 bit_idx,
u8 clk_gate2_flags, spinlock_t *lock)
{
struct clk_gate *gate;
struct clk *clk;
struct clk_init_data init;
gate = kzalloc(sizeof(struct clk_gate), GFP_KERNEL);
if (!gate)
return ERR_PTR(-ENOMEM);
gate->reg = reg;
gate->bit_idx = bit_idx;
gate->flags = clk_gate2_flags;
gate->lock = lock;
init.name = name;
init.ops = &clk_gate2_ops;
init.flags = flags;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
gate->hw.init = &init;
clk = clk_register(dev, &gate->hw);
if (IS_ERR(clk))
kfree(clk);
return clk;
}
