static u8 clk_mux_get_parent(struct clk_hw *hw)
{
struct clk_mux *mux = to_clk_mux(hw);
u32 val;
val = readl(mux->reg) >> mux->shift;
val &= (1 << mux->width) - 1;
if (val && (mux->flags & CLK_MUX_INDEX_BIT))
val = ffs(val) - 1;
if (val && (mux->flags & CLK_MUX_INDEX_ONE))
val--;
if (val >= __clk_get_num_parents(hw->clk))
return -EINVAL;
return val;
}
static int clk_mux_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_mux *mux = to_clk_mux(hw);
u32 val;
unsigned long flags = 0;
if (mux->flags & CLK_MUX_INDEX_BIT)
index = (1 << ffs(index));
if (mux->flags & CLK_MUX_INDEX_ONE)
index++;
if (mux->lock)
spin_lock_irqsave(mux->lock, flags);
val = readl(mux->reg);
val &= ~(((1 << mux->width) - 1) << mux->shift);
val |= index << mux->shift;
writel(val, mux->reg);
if (mux->lock)
spin_unlock_irqrestore(mux->lock, flags);
return 0;
}
struct clk *clk_register_mux(struct device *dev, const char *name,
char **parent_names, u8 num_parents, unsigned long flags,
void __iomem *reg, u8 shift, u8 width,
u8 clk_mux_flags, spinlock_t *lock)
{
struct clk_mux *mux;
mux = kmalloc(sizeof(struct clk_mux), GFP_KERNEL);
if (!mux) {
pr_err("%s: could not allocate mux clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
mux->reg = reg;
mux->shift = shift;
mux->width = width;
mux->flags = clk_mux_flags;
mux->lock = lock;
return clk_register(dev, name, &clk_mux_ops, &mux->hw,
parent_names, num_parents, flags);
}
