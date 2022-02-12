static int clkgate_separated_enable(struct clk_hw *hw)
{
struct clkgate_separated *sclk;
unsigned long flags = 0;
u32 reg;
sclk = container_of(hw, struct clkgate_separated, hw);
if (sclk->lock)
spin_lock_irqsave(sclk->lock, flags);
reg = BIT(sclk->bit_idx);
writel_relaxed(reg, sclk->enable);
readl_relaxed(sclk->enable + CLKGATE_SEPERATED_STATUS);
if (sclk->lock)
spin_unlock_irqrestore(sclk->lock, flags);
return 0;
}
static void clkgate_separated_disable(struct clk_hw *hw)
{
struct clkgate_separated *sclk;
unsigned long flags = 0;
u32 reg;
sclk = container_of(hw, struct clkgate_separated, hw);
if (sclk->lock)
spin_lock_irqsave(sclk->lock, flags);
reg = BIT(sclk->bit_idx);
writel_relaxed(reg, sclk->enable + CLKGATE_SEPERATED_DISABLE);
readl_relaxed(sclk->enable + CLKGATE_SEPERATED_STATUS);
if (sclk->lock)
spin_unlock_irqrestore(sclk->lock, flags);
}
static int clkgate_separated_is_enabled(struct clk_hw *hw)
{
struct clkgate_separated *sclk;
u32 reg;
sclk = container_of(hw, struct clkgate_separated, hw);
reg = readl_relaxed(sclk->enable + CLKGATE_SEPERATED_STATUS);
reg &= BIT(sclk->bit_idx);
return reg ? 1 : 0;
}
struct clk *hisi_register_clkgate_sep(struct device *dev, const char *name,
const char *parent_name,
unsigned long flags,
void __iomem *reg, u8 bit_idx,
u8 clk_gate_flags, spinlock_t *lock)
{
struct clkgate_separated *sclk;
struct clk *clk;
struct clk_init_data init;
sclk = kzalloc(sizeof(*sclk), GFP_KERNEL);
if (!sclk) {
pr_err("%s: fail to allocate separated gated clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &clkgate_separated_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
sclk->enable = reg + CLKGATE_SEPERATED_ENABLE;
sclk->bit_idx = bit_idx;
sclk->flags = clk_gate_flags;
sclk->hw.init = &init;
clk = clk_register(dev, &sclk->hw);
if (IS_ERR(clk))
kfree(sclk);
return clk;
}
