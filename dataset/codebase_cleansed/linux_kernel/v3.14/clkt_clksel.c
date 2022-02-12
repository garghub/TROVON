static const struct clksel *_get_clksel_by_parent(struct clk_hw_omap *clk,
struct clk *src_clk)
{
const struct clksel *clks;
if (!src_clk)
return NULL;
for (clks = clk->clksel; clks->parent; clks++)
if (clks->parent == src_clk)
break;
if (!clks->parent) {
WARN(1, "clock: %s: could not find parent clock %s in clksel array\n",
__clk_get_name(clk->hw.clk), __clk_get_name(src_clk));
return NULL;
}
return clks;
}
static void _write_clksel_reg(struct clk_hw_omap *clk, u32 field_val)
{
u32 v;
v = omap2_clk_readl(clk, clk->clksel_reg);
v &= ~clk->clksel_mask;
v |= field_val << __ffs(clk->clksel_mask);
omap2_clk_writel(v, clk, clk->clksel_reg);
v = omap2_clk_readl(clk, clk->clksel_reg);
}
static u32 _clksel_to_divisor(struct clk_hw_omap *clk, u32 field_val)
{
const struct clksel *clks;
const struct clksel_rate *clkr;
struct clk *parent;
parent = __clk_get_parent(clk->hw.clk);
clks = _get_clksel_by_parent(clk, parent);
if (!clks)
return 0;
for (clkr = clks->rates; clkr->div; clkr++) {
if (!(clkr->flags & cpu_mask))
continue;
if (clkr->val == field_val)
break;
}
if (!clkr->div) {
WARN(1, "clock: %s: could not find fieldval %d for parent %s\n",
__clk_get_name(clk->hw.clk), field_val,
__clk_get_name(parent));
return 0;
}
return clkr->div;
}
static u32 _divisor_to_clksel(struct clk_hw_omap *clk, u32 div)
{
const struct clksel *clks;
const struct clksel_rate *clkr;
struct clk *parent;
WARN_ON(div == 0);
parent = __clk_get_parent(clk->hw.clk);
clks = _get_clksel_by_parent(clk, parent);
if (!clks)
return ~0;
for (clkr = clks->rates; clkr->div; clkr++) {
if (!(clkr->flags & cpu_mask))
continue;
if (clkr->div == div)
break;
}
if (!clkr->div) {
pr_err("clock: %s: could not find divisor %d for parent %s\n",
__clk_get_name(clk->hw.clk), div,
__clk_get_name(parent));
return ~0;
}
return clkr->val;
}
static u32 _read_divisor(struct clk_hw_omap *clk)
{
u32 v;
if (!clk->clksel || !clk->clksel_mask)
return 0;
v = omap2_clk_readl(clk, clk->clksel_reg);
v &= clk->clksel_mask;
v >>= __ffs(clk->clksel_mask);
return _clksel_to_divisor(clk, v);
}
u32 omap2_clksel_round_rate_div(struct clk_hw_omap *clk,
unsigned long target_rate,
u32 *new_div)
{
unsigned long test_rate;
const struct clksel *clks;
const struct clksel_rate *clkr;
u32 last_div = 0;
struct clk *parent;
unsigned long parent_rate;
const char *clk_name;
parent = __clk_get_parent(clk->hw.clk);
clk_name = __clk_get_name(clk->hw.clk);
parent_rate = __clk_get_rate(parent);
if (!clk->clksel || !clk->clksel_mask)
return ~0;
pr_debug("clock: clksel_round_rate_div: %s target_rate %ld\n",
clk_name, target_rate);
*new_div = 1;
clks = _get_clksel_by_parent(clk, parent);
if (!clks)
return ~0;
for (clkr = clks->rates; clkr->div; clkr++) {
if (!(clkr->flags & cpu_mask))
continue;
if (clkr->div <= last_div)
pr_err("clock: %s: clksel_rate table not sorted\n",
clk_name);
last_div = clkr->div;
test_rate = parent_rate / clkr->div;
if (test_rate <= target_rate)
break;
}
if (!clkr->div) {
pr_err("clock: %s: could not find divisor for target rate %ld for parent %s\n",
clk_name, target_rate, __clk_get_name(parent));
return ~0;
}
*new_div = clkr->div;
pr_debug("clock: new_div = %d, new_rate = %ld\n", *new_div,
(parent_rate / clkr->div));
return parent_rate / clkr->div;
}
u8 omap2_clksel_find_parent_index(struct clk_hw *hw)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
const struct clksel *clks;
const struct clksel_rate *clkr;
u32 r, found = 0;
struct clk *parent;
const char *clk_name;
int ret = 0, f = 0;
parent = __clk_get_parent(hw->clk);
clk_name = __clk_get_name(hw->clk);
WARN((!clk->clksel || !clk->clksel_mask),
"clock: %s: attempt to call on a non-clksel clock", clk_name);
r = omap2_clk_readl(clk, clk->clksel_reg) & clk->clksel_mask;
r >>= __ffs(clk->clksel_mask);
for (clks = clk->clksel; clks->parent && !found; clks++) {
for (clkr = clks->rates; clkr->div && !found; clkr++) {
if (!(clkr->flags & cpu_mask))
continue;
if (clkr->val == r) {
found = 1;
ret = f;
}
}
f++;
}
WARN(!found, "clock: %s: init parent: could not find regval %0x\n",
clk_name, r);
return ret;
}
unsigned long omap2_clksel_recalc(struct clk_hw *hw, unsigned long parent_rate)
{
unsigned long rate;
u32 div = 0;
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
if (!parent_rate)
return 0;
div = _read_divisor(clk);
if (!div)
rate = parent_rate;
else
rate = parent_rate / div;
pr_debug("%s: recalc'd %s's rate to %lu (div %d)\n", __func__,
__clk_get_name(hw->clk), rate, div);
return rate;
}
long omap2_clksel_round_rate(struct clk_hw *hw, unsigned long target_rate,
unsigned long *parent_rate)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 new_div;
return omap2_clksel_round_rate_div(clk, target_rate, &new_div);
}
int omap2_clksel_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 field_val, validrate, new_div = 0;
if (!clk->clksel || !clk->clksel_mask)
return -EINVAL;
validrate = omap2_clksel_round_rate_div(clk, rate, &new_div);
if (validrate != rate)
return -EINVAL;
field_val = _divisor_to_clksel(clk, new_div);
if (field_val == ~0)
return -EINVAL;
_write_clksel_reg(clk, field_val);
pr_debug("clock: %s: set rate to %ld\n", __clk_get_name(hw->clk),
__clk_get_rate(hw->clk));
return 0;
}
int omap2_clksel_set_parent(struct clk_hw *hw, u8 field_val)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
if (!clk->clksel || !clk->clksel_mask)
return -EINVAL;
_write_clksel_reg(clk, field_val);
return 0;
}
