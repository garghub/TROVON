static int clk_pll_out_is_enabled(struct clk_hw *hw)
{
struct tegra_clk_pll_out *pll_out = to_clk_pll_out(hw);
u32 val = readl_relaxed(pll_out->reg);
int state;
state = (val & pll_out_enb(pll_out)) ? 1 : 0;
if (!(val & (pll_out_rst(pll_out))))
state = 0;
return state;
}
static int clk_pll_out_enable(struct clk_hw *hw)
{
struct tegra_clk_pll_out *pll_out = to_clk_pll_out(hw);
unsigned long flags = 0;
u32 val;
if (pll_out->lock)
spin_lock_irqsave(pll_out->lock, flags);
val = readl_relaxed(pll_out->reg);
val |= (pll_out_enb(pll_out) | pll_out_rst(pll_out));
writel_relaxed(val, pll_out->reg);
udelay(2);
if (pll_out->lock)
spin_unlock_irqrestore(pll_out->lock, flags);
return 0;
}
static void clk_pll_out_disable(struct clk_hw *hw)
{
struct tegra_clk_pll_out *pll_out = to_clk_pll_out(hw);
unsigned long flags = 0;
u32 val;
if (pll_out->lock)
spin_lock_irqsave(pll_out->lock, flags);
val = readl_relaxed(pll_out->reg);
val &= ~(pll_out_enb(pll_out) | pll_out_rst(pll_out));
writel_relaxed(val, pll_out->reg);
udelay(2);
if (pll_out->lock)
spin_unlock_irqrestore(pll_out->lock, flags);
}
struct clk *tegra_clk_register_pll_out(const char *name,
const char *parent_name, void __iomem *reg, u8 enb_bit_idx,
u8 rst_bit_idx, unsigned long flags, u8 pll_out_flags,
spinlock_t *lock)
{
struct tegra_clk_pll_out *pll_out;
struct clk *clk;
struct clk_init_data init;
pll_out = kzalloc(sizeof(*pll_out), GFP_KERNEL);
if (!pll_out)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &tegra_clk_pll_out_ops;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
init.flags = flags;
pll_out->reg = reg;
pll_out->enb_bit_idx = enb_bit_idx;
pll_out->rst_bit_idx = rst_bit_idx;
pll_out->flags = pll_out_flags;
pll_out->lock = lock;
pll_out->hw.init = &init;
clk = clk_register(NULL, &pll_out->hw);
if (IS_ERR(clk))
kfree(pll_out);
return clk;
}
