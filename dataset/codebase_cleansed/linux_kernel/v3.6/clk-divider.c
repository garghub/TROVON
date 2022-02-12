static unsigned int _get_table_maxdiv(const struct clk_div_table *table)
{
unsigned int maxdiv = 0;
const struct clk_div_table *clkt;
for (clkt = table; clkt->div; clkt++)
if (clkt->div > maxdiv)
maxdiv = clkt->div;
return maxdiv;
}
static unsigned int _get_maxdiv(struct clk_divider *divider)
{
if (divider->flags & CLK_DIVIDER_ONE_BASED)
return div_mask(divider);
if (divider->flags & CLK_DIVIDER_POWER_OF_TWO)
return 1 << div_mask(divider);
if (divider->table)
return _get_table_maxdiv(divider->table);
return div_mask(divider) + 1;
}
static unsigned int _get_table_div(const struct clk_div_table *table,
unsigned int val)
{
const struct clk_div_table *clkt;
for (clkt = table; clkt->div; clkt++)
if (clkt->val == val)
return clkt->div;
return 0;
}
static unsigned int _get_div(struct clk_divider *divider, unsigned int val)
{
if (divider->flags & CLK_DIVIDER_ONE_BASED)
return val;
if (divider->flags & CLK_DIVIDER_POWER_OF_TWO)
return 1 << val;
if (divider->table)
return _get_table_div(divider->table, val);
return val + 1;
}
static unsigned int _get_table_val(const struct clk_div_table *table,
unsigned int div)
{
const struct clk_div_table *clkt;
for (clkt = table; clkt->div; clkt++)
if (clkt->div == div)
return clkt->val;
return 0;
}
static unsigned int _get_val(struct clk_divider *divider, u8 div)
{
if (divider->flags & CLK_DIVIDER_ONE_BASED)
return div;
if (divider->flags & CLK_DIVIDER_POWER_OF_TWO)
return __ffs(div);
if (divider->table)
return _get_table_val(divider->table, div);
return div - 1;
}
static unsigned long clk_divider_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_divider *divider = to_clk_divider(hw);
unsigned int div, val;
val = readl(divider->reg) >> divider->shift;
val &= div_mask(divider);
div = _get_div(divider, val);
if (!div) {
WARN(1, "%s: Invalid divisor for clock %s\n", __func__,
__clk_get_name(hw->clk));
return parent_rate;
}
return parent_rate / div;
}
static bool _is_valid_table_div(const struct clk_div_table *table,
unsigned int div)
{
const struct clk_div_table *clkt;
for (clkt = table; clkt->div; clkt++)
if (clkt->div == div)
return true;
return false;
}
static bool _is_valid_div(struct clk_divider *divider, unsigned int div)
{
if (divider->flags & CLK_DIVIDER_POWER_OF_TWO)
return is_power_of_two(div);
if (divider->table)
return _is_valid_table_div(divider->table, div);
return true;
}
static int clk_divider_bestdiv(struct clk_hw *hw, unsigned long rate,
unsigned long *best_parent_rate)
{
struct clk_divider *divider = to_clk_divider(hw);
int i, bestdiv = 0;
unsigned long parent_rate, best = 0, now, maxdiv;
if (!rate)
rate = 1;
maxdiv = _get_maxdiv(divider);
if (!(__clk_get_flags(hw->clk) & CLK_SET_RATE_PARENT)) {
parent_rate = *best_parent_rate;
bestdiv = DIV_ROUND_UP(parent_rate, rate);
bestdiv = bestdiv == 0 ? 1 : bestdiv;
bestdiv = bestdiv > maxdiv ? maxdiv : bestdiv;
return bestdiv;
}
maxdiv = min(ULONG_MAX / rate, maxdiv);
for (i = 1; i <= maxdiv; i++) {
if (!_is_valid_div(divider, i))
continue;
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
bestdiv = _get_maxdiv(divider);
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
unsigned int div, value;
unsigned long flags = 0;
u32 val;
div = parent_rate / rate;
value = _get_val(divider, div);
if (value > div_mask(divider))
value = div_mask(divider);
if (divider->lock)
spin_lock_irqsave(divider->lock, flags);
val = readl(divider->reg);
val &= ~(div_mask(divider) << divider->shift);
val |= value << divider->shift;
writel(val, divider->reg);
if (divider->lock)
spin_unlock_irqrestore(divider->lock, flags);
return 0;
}
static struct clk *_register_divider(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 shift, u8 width,
u8 clk_divider_flags, const struct clk_div_table *table,
spinlock_t *lock)
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
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
div->reg = reg;
div->shift = shift;
div->width = width;
div->flags = clk_divider_flags;
div->lock = lock;
div->hw.init = &init;
div->table = table;
clk = clk_register(dev, &div->hw);
if (IS_ERR(clk))
kfree(div);
return clk;
}
struct clk *clk_register_divider(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 shift, u8 width,
u8 clk_divider_flags, spinlock_t *lock)
{
return _register_divider(dev, name, parent_name, flags, reg, shift,
width, clk_divider_flags, NULL, lock);
}
struct clk *clk_register_divider_table(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 shift, u8 width,
u8 clk_divider_flags, const struct clk_div_table *table,
spinlock_t *lock)
{
return _register_divider(dev, name, parent_name, flags, reg, shift,
width, clk_divider_flags, table, lock);
}
