static unsigned long hi6220_clkdiv_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned int val;
struct hi6220_clk_divider *dclk = to_hi6220_clk_divider(hw);
val = readl_relaxed(dclk->reg) >> dclk->shift;
val &= div_mask(dclk->width);
return divider_recalc_rate(hw, parent_rate, val, dclk->table,
CLK_DIVIDER_ROUND_CLOSEST);
}
static long hi6220_clkdiv_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct hi6220_clk_divider *dclk = to_hi6220_clk_divider(hw);
return divider_round_rate(hw, rate, prate, dclk->table,
dclk->width, CLK_DIVIDER_ROUND_CLOSEST);
}
static int hi6220_clkdiv_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
int value;
unsigned long flags = 0;
u32 data;
struct hi6220_clk_divider *dclk = to_hi6220_clk_divider(hw);
value = divider_get_val(rate, parent_rate, dclk->table,
dclk->width, CLK_DIVIDER_ROUND_CLOSEST);
if (dclk->lock)
spin_lock_irqsave(dclk->lock, flags);
data = readl_relaxed(dclk->reg);
data &= ~(div_mask(dclk->width) << dclk->shift);
data |= value << dclk->shift;
data |= dclk->mask;
writel_relaxed(data, dclk->reg);
if (dclk->lock)
spin_unlock_irqrestore(dclk->lock, flags);
return 0;
}
struct clk *hi6220_register_clkdiv(struct device *dev, const char *name,
const char *parent_name, unsigned long flags, void __iomem *reg,
u8 shift, u8 width, u32 mask_bit, spinlock_t *lock)
{
struct hi6220_clk_divider *div;
struct clk *clk;
struct clk_init_data init;
struct clk_div_table *table;
u32 max_div, min_div;
int i;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return ERR_PTR(-ENOMEM);
max_div = div_mask(width) + 1;
min_div = 1;
table = kcalloc(max_div + 1, sizeof(*table), GFP_KERNEL);
if (!table) {
kfree(div);
return ERR_PTR(-ENOMEM);
}
for (i = 0; i < max_div; i++) {
table[i].div = min_div + i;
table[i].val = table[i].div - 1;
}
init.name = name;
init.ops = &hi6220_clkdiv_ops;
init.flags = flags;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
div->reg = reg;
div->shift = shift;
div->width = width;
div->mask = mask_bit ? BIT(mask_bit) : 0;
div->lock = lock;
div->hw.init = &init;
div->table = table;
clk = clk_register(dev, &div->hw);
if (IS_ERR(clk)) {
kfree(table);
kfree(div);
}
return clk;
}
