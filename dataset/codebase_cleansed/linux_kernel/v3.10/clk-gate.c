static void clk_gate_endisable(struct clk_hw *hw, int enable)
{
struct clk_gate *gate = to_clk_gate(hw);
int set = gate->flags & CLK_GATE_SET_TO_DISABLE ? 1 : 0;
unsigned long flags = 0;
u32 reg;
set ^= enable;
if (gate->lock)
spin_lock_irqsave(gate->lock, flags);
reg = readl(gate->reg);
if (set)
reg |= BIT(gate->bit_idx);
else
reg &= ~BIT(gate->bit_idx);
writel(reg, gate->reg);
if (gate->lock)
spin_unlock_irqrestore(gate->lock, flags);
}
static int clk_gate_enable(struct clk_hw *hw)
{
clk_gate_endisable(hw, 1);
return 0;
}
static void clk_gate_disable(struct clk_hw *hw)
{
clk_gate_endisable(hw, 0);
}
static int clk_gate_is_enabled(struct clk_hw *hw)
{
u32 reg;
struct clk_gate *gate = to_clk_gate(hw);
reg = readl(gate->reg);
if (gate->flags & CLK_GATE_SET_TO_DISABLE)
reg ^= BIT(gate->bit_idx);
reg &= BIT(gate->bit_idx);
return reg ? 1 : 0;
}
struct clk *clk_register_gate(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 bit_idx,
u8 clk_gate_flags, spinlock_t *lock)
{
struct clk_gate *gate;
struct clk *clk;
struct clk_init_data init;
gate = kzalloc(sizeof(struct clk_gate), GFP_KERNEL);
if (!gate) {
pr_err("%s: could not allocate gated clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &clk_gate_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
gate->reg = reg;
gate->bit_idx = bit_idx;
gate->flags = clk_gate_flags;
gate->lock = lock;
gate->hw.init = &init;
clk = clk_register(dev, &gate->hw);
if (IS_ERR(clk))
kfree(gate);
return clk;
}
