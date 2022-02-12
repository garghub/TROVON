static unsigned long clk_divider_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_divider *divider = to_clk_divider(hw);
unsigned int div;
div = readl(divider->reg) >> divider->shift;
div &= div_mask(divider);
if (!(divider->flags & CLK_DIVIDER_ONE_BASED))
div++;
return parent_rate / div;
}
static int clk_divider_bestdiv(struct clk_hw *hw, unsigned long rate,
unsigned long *best_parent_rate)
{
struct clk_divider *divider = to_clk_divider(hw);
int i, bestdiv = 0;
unsigned long parent_rate, best = 0, now, maxdiv;
if (!rate)
rate = 1;
maxdiv = (1 << divider->width);
if (divider->flags & CLK_DIVIDER_ONE_BASED)
maxdiv--;
if (!(__clk_get_flags(hw->clk) & CLK_SET_RATE_PARENT)) {
parent_rate = *best_parent_rate;
bestdiv = DIV_ROUND_UP(parent_rate, rate);
bestdiv = bestdiv == 0 ? 1 : bestdiv;
bestdiv = bestdiv > maxdiv ? maxdiv : bestdiv;
return bestdiv;
}
maxdiv = min(ULONG_MAX / rate, maxdiv);
for (i = 1; i <= maxdiv; i++) {
parent_rate = __clk_round_rate(__clk_get_parent(hw->clk),
MULT_ROUND_UP(rate, i));
now = parent_rate / i;
if (now <= rate && now > best) {
bestdiv = i;
best = now;
*best_parent_rate = parent_rate;
}
}
if (!bestdiv) {
bestdiv = (1 << divider->width);
if (divider->flags & CLK_DIVIDER_ONE_BASED)
bestdiv--;
*best_parent_rate = __clk_round_rate(__clk_get_parent(hw->clk), 1);
}
return bestdiv;
}
static long clk_divider_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int div;
div = clk_divider_bestdiv(hw, rate, prate);
return *prate / div;
}
static int clk_divider_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_divider *divider = to_clk_divider(hw);
unsigned int div;
unsigned long flags = 0;
u32 val;
div = parent_rate / rate;
if (!(divider->flags & CLK_DIVIDER_ONE_BASED))
div--;
if (div > div_mask(divider))
div = div_mask(divider);
if (divider->lock)
spin_lock_irqsave(divider->lock, flags);
val = readl(divider->reg);
val &= ~(div_mask(divider) << divider->shift);
val |= div << divider->shift;
writel(val, divider->reg);
if (divider->lock)
spin_unlock_irqrestore(divider->lock, flags);
return 0;
}
struct clk *clk_register_divider(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 shift, u8 width,
u8 clk_divider_flags, spinlock_t *lock)
{
struct clk_divider *div;
struct clk *clk;
struct clk_init_data init;
div = kzalloc(sizeof(struct clk_divider), GFP_KERNEL);
if (!div) {
pr_err("%s: could not allocate divider clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &clk_divider_ops;
init.flags = flags;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
div->reg = reg;
div->shift = shift;
div->width = width;
div->flags = clk_divider_flags;
div->lock = lock;
div->hw.init = &init;
clk = clk_register(dev, &div->hw);
if (IS_ERR(clk))
kfree(div);
return clk;
}
