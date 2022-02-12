static u8 clk_mux_get_parent(struct clk_hw *hw)
{
struct clk_mux *mux = to_clk_mux(hw);
int num_parents = clk_hw_get_num_parents(hw);
u32 val;
val = clk_readl(mux->reg) >> mux->shift;
val &= mux->mask;
if (mux->table) {
int i;
for (i = 0; i < num_parents; i++)
if (mux->table[i] == val)
return i;
return -EINVAL;
}
if (val && (mux->flags & CLK_MUX_INDEX_BIT))
val = ffs(val) - 1;
if (val && (mux->flags & CLK_MUX_INDEX_ONE))
val--;
if (val >= num_parents)
return -EINVAL;
return val;
}
static int clk_mux_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_mux *mux = to_clk_mux(hw);
u32 val;
unsigned long flags = 0;
if (mux->table)
index = mux->table[index];
else {
if (mux->flags & CLK_MUX_INDEX_BIT)
index = 1 << index;
if (mux->flags & CLK_MUX_INDEX_ONE)
index++;
}
if (mux->lock)
spin_lock_irqsave(mux->lock, flags);
else
__acquire(mux->lock);
if (mux->flags & CLK_MUX_HIWORD_MASK) {
val = mux->mask << (mux->shift + 16);
} else {
val = clk_readl(mux->reg);
val &= ~(mux->mask << mux->shift);
}
val |= index << mux->shift;
clk_writel(val, mux->reg);
if (mux->lock)
spin_unlock_irqrestore(mux->lock, flags);
else
__release(mux->lock);
return 0;
}
struct clk *clk_register_mux_table(struct device *dev, const char *name,
const char * const *parent_names, u8 num_parents,
unsigned long flags,
void __iomem *reg, u8 shift, u32 mask,
u8 clk_mux_flags, u32 *table, spinlock_t *lock)
{
struct clk_mux *mux;
struct clk *clk;
struct clk_init_data init;
u8 width = 0;
if (clk_mux_flags & CLK_MUX_HIWORD_MASK) {
width = fls(mask) - ffs(mask) + 1;
if (width + shift > 16) {
pr_err("mux value exceeds LOWORD field\n");
return ERR_PTR(-EINVAL);
}
}
mux = kzalloc(sizeof(struct clk_mux), GFP_KERNEL);
if (!mux) {
pr_err("%s: could not allocate mux clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
if (clk_mux_flags & CLK_MUX_READ_ONLY)
init.ops = &clk_mux_ro_ops;
else
init.ops = &clk_mux_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = parent_names;
init.num_parents = num_parents;
mux->reg = reg;
mux->shift = shift;
mux->mask = mask;
mux->flags = clk_mux_flags;
mux->lock = lock;
mux->table = table;
mux->hw.init = &init;
clk = clk_register(dev, &mux->hw);
if (IS_ERR(clk))
kfree(mux);
return clk;
}
struct clk *clk_register_mux(struct device *dev, const char *name,
const char * const *parent_names, u8 num_parents,
unsigned long flags,
void __iomem *reg, u8 shift, u8 width,
u8 clk_mux_flags, spinlock_t *lock)
{
u32 mask = BIT(width) - 1;
return clk_register_mux_table(dev, name, parent_names, num_parents,
flags, reg, shift, mask, clk_mux_flags,
NULL, lock);
}
void clk_unregister_mux(struct clk *clk)
{
struct clk_mux *mux;
struct clk_hw *hw;
hw = __clk_get_hw(clk);
if (!hw)
return;
mux = to_clk_mux(hw);
clk_unregister(clk);
kfree(mux);
}
