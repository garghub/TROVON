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
static unsigned long ti_clk_divider_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_divider *divider = to_clk_divider(hw);
unsigned int div, val;
val = ti_clk_ll_ops->clk_readl(divider->reg) >> divider->shift;
val &= div_mask(divider);
div = _get_div(divider, val);
if (!div) {
WARN(!(divider->flags & CLK_DIVIDER_ALLOW_ZERO),
"%s: Zero divisor and CLK_DIVIDER_ALLOW_ZERO not set\n",
__clk_get_name(hw->clk));
return parent_rate;
}
return DIV_ROUND_UP(parent_rate, div);
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
return is_power_of_2(div);
if (divider->table)
return _is_valid_table_div(divider->table, div);
return true;
}
static int ti_clk_divider_bestdiv(struct clk_hw *hw, unsigned long rate,
unsigned long *best_parent_rate)
{
struct clk_divider *divider = to_clk_divider(hw);
int i, bestdiv = 0;
unsigned long parent_rate, best = 0, now, maxdiv;
unsigned long parent_rate_saved = *best_parent_rate;
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
if (rate * i == parent_rate_saved) {
*best_parent_rate = parent_rate_saved;
return i;
}
parent_rate = __clk_round_rate(__clk_get_parent(hw->clk),
MULT_ROUND_UP(rate, i));
now = DIV_ROUND_UP(parent_rate, i);
if (now <= rate && now > best) {
bestdiv = i;
best = now;
*best_parent_rate = parent_rate;
}
}
if (!bestdiv) {
bestdiv = _get_maxdiv(divider);
*best_parent_rate =
__clk_round_rate(__clk_get_parent(hw->clk), 1);
}
return bestdiv;
}
static long ti_clk_divider_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int div;
div = ti_clk_divider_bestdiv(hw, rate, prate);
return DIV_ROUND_UP(*prate, div);
}
static int ti_clk_divider_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_divider *divider;
unsigned int div, value;
unsigned long flags = 0;
u32 val;
if (!hw || !rate)
return -EINVAL;
divider = to_clk_divider(hw);
div = DIV_ROUND_UP(parent_rate, rate);
value = _get_val(divider, div);
if (value > div_mask(divider))
value = div_mask(divider);
if (divider->lock)
spin_lock_irqsave(divider->lock, flags);
if (divider->flags & CLK_DIVIDER_HIWORD_MASK) {
val = div_mask(divider) << (divider->shift + 16);
} else {
val = ti_clk_ll_ops->clk_readl(divider->reg);
val &= ~(div_mask(divider) << divider->shift);
}
val |= value << divider->shift;
ti_clk_ll_ops->clk_writel(val, divider->reg);
if (divider->lock)
spin_unlock_irqrestore(divider->lock, flags);
return 0;
}
static struct clk *_register_divider(struct device *dev, const char *name,
const char *parent_name,
unsigned long flags, void __iomem *reg,
u8 shift, u8 width, u8 clk_divider_flags,
const struct clk_div_table *table,
spinlock_t *lock)
{
struct clk_divider *div;
struct clk *clk;
struct clk_init_data init;
if (clk_divider_flags & CLK_DIVIDER_HIWORD_MASK) {
if (width + shift > 16) {
pr_warn("divider value exceeds LOWORD field\n");
return ERR_PTR(-EINVAL);
}
}
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div) {
pr_err("%s: could not allocate divider clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &ti_clk_divider_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name : NULL);
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
static struct clk_div_table *
__init ti_clk_get_div_table(struct device_node *node)
{
struct clk_div_table *table;
const __be32 *divspec;
u32 val;
u32 num_div;
u32 valid_div;
int i;
divspec = of_get_property(node, "ti,dividers", &num_div);
if (!divspec)
return NULL;
num_div /= 4;
valid_div = 0;
for (i = 0; i < num_div; i++) {
of_property_read_u32_index(node, "ti,dividers", i, &val);
if (val)
valid_div++;
}
if (!valid_div) {
pr_err("no valid dividers for %s table\n", node->name);
return ERR_PTR(-EINVAL);
}
table = kzalloc(sizeof(*table) * (valid_div + 1), GFP_KERNEL);
if (!table)
return ERR_PTR(-ENOMEM);
valid_div = 0;
for (i = 0; i < num_div; i++) {
of_property_read_u32_index(node, "ti,dividers", i, &val);
if (val) {
table[valid_div].div = val;
table[valid_div].val = i;
valid_div++;
}
}
return table;
}
static int _get_divider_width(struct device_node *node,
const struct clk_div_table *table,
u8 flags)
{
u32 min_div;
u32 max_div;
u32 val = 0;
u32 div;
if (!table) {
if (of_property_read_u32(node, "ti,min-div", &min_div))
min_div = 1;
if (of_property_read_u32(node, "ti,max-div", &max_div)) {
pr_err("no max-div for %s!\n", node->name);
return -EINVAL;
}
if (flags & CLK_DIVIDER_ONE_BASED)
val = 1;
div = min_div;
while (div < max_div) {
if (flags & CLK_DIVIDER_POWER_OF_TWO)
div <<= 1;
else
div++;
val++;
}
} else {
div = 0;
while (table[div].div) {
val = table[div].val;
div++;
}
}
return fls(val);
}
static int __init ti_clk_divider_populate(struct device_node *node,
void __iomem **reg, const struct clk_div_table **table,
u32 *flags, u8 *div_flags, u8 *width, u8 *shift)
{
u32 val;
*reg = ti_clk_get_reg_addr(node, 0);
if (!*reg)
return -EINVAL;
if (!of_property_read_u32(node, "ti,bit-shift", &val))
*shift = val;
else
*shift = 0;
*flags = 0;
*div_flags = 0;
if (of_property_read_bool(node, "ti,index-starts-at-one"))
*div_flags |= CLK_DIVIDER_ONE_BASED;
if (of_property_read_bool(node, "ti,index-power-of-two"))
*div_flags |= CLK_DIVIDER_POWER_OF_TWO;
if (of_property_read_bool(node, "ti,set-rate-parent"))
*flags |= CLK_SET_RATE_PARENT;
*table = ti_clk_get_div_table(node);
if (IS_ERR(*table))
return PTR_ERR(*table);
*width = _get_divider_width(node, *table, *div_flags);
return 0;
}
static void __init of_ti_divider_clk_setup(struct device_node *node)
{
struct clk *clk;
const char *parent_name;
void __iomem *reg;
u8 clk_divider_flags = 0;
u8 width = 0;
u8 shift = 0;
const struct clk_div_table *table = NULL;
u32 flags = 0;
parent_name = of_clk_get_parent_name(node, 0);
if (ti_clk_divider_populate(node, &reg, &table, &flags,
&clk_divider_flags, &width, &shift))
goto cleanup;
clk = _register_divider(NULL, node->name, parent_name, flags, reg,
shift, width, clk_divider_flags, table, NULL);
if (!IS_ERR(clk)) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
of_ti_clk_autoidle_setup(node);
return;
}
cleanup:
kfree(table);
}
static void __init of_ti_composite_divider_clk_setup(struct device_node *node)
{
struct clk_divider *div;
u32 val;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return;
if (ti_clk_divider_populate(node, &div->reg, &div->table, &val,
&div->flags, &div->width, &div->shift) < 0)
goto cleanup;
if (!ti_clk_add_component(node, &div->hw, CLK_COMPONENT_TYPE_DIVIDER))
return;
cleanup:
kfree(div->table);
kfree(div);
}
