static int clk_gate2_enable(struct clk_hw *hw)
{
struct clk_gate2 *gate = to_clk_gate2(hw);
u32 reg;
unsigned long flags = 0;
spin_lock_irqsave(gate->lock, flags);
if (gate->share_count && (*gate->share_count)++ > 0)
goto out;
reg = readl(gate->reg);
reg |= 3 << gate->bit_idx;
writel(reg, gate->reg);
out:
spin_unlock_irqrestore(gate->lock, flags);
return 0;
}
static void clk_gate2_disable(struct clk_hw *hw)
{
struct clk_gate2 *gate = to_clk_gate2(hw);
u32 reg;
unsigned long flags = 0;
spin_lock_irqsave(gate->lock, flags);
if (gate->share_count) {
if (WARN_ON(*gate->share_count == 0))
goto out;
else if (--(*gate->share_count) > 0)
goto out;
}
reg = readl(gate->reg);
reg &= ~(3 << gate->bit_idx);
writel(reg, gate->reg);
out:
spin_unlock_irqrestore(gate->lock, flags);
}
static int clk_gate2_reg_is_enabled(void __iomem *reg, u8 bit_idx)
{
u32 val = readl(reg);
if (((val >> bit_idx) & 1) == 1)
return 1;
return 0;
}
static int clk_gate2_is_enabled(struct clk_hw *hw)
{
struct clk_gate2 *gate = to_clk_gate2(hw);
if (gate->share_count)
return !!(*gate->share_count);
else
return clk_gate2_reg_is_enabled(gate->reg, gate->bit_idx);
}
struct clk *clk_register_gate2(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 bit_idx,
u8 clk_gate2_flags, spinlock_t *lock,
unsigned int *share_count)
{
struct clk_gate2 *gate;
struct clk *clk;
struct clk_init_data init;
gate = kzalloc(sizeof(struct clk_gate2), GFP_KERNEL);
if (!gate)
return ERR_PTR(-ENOMEM);
gate->reg = reg;
gate->bit_idx = bit_idx;
gate->flags = clk_gate2_flags;
gate->lock = lock;
if (share_count)
*share_count = clk_gate2_reg_is_enabled(reg, bit_idx) ? 1 : 0;
gate->share_count = share_count;
init.name = name;
init.ops = &clk_gate2_ops;
init.flags = flags;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
gate->hw.init = &init;
clk = clk_register(dev, &gate->hw);
if (IS_ERR(clk))
kfree(gate);
return clk;
}
