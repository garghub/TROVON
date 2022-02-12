static const struct clksel *_get_clksel_by_parent(struct clk *clk,
struct clk *src_clk)
{
const struct clksel *clks;
for (clks = clk->clksel; clks->parent; clks++)
if (clks->parent == src_clk)
break;
if (!clks->parent) {
WARN(1, "clock: %s: could not find parent clock %s in clksel array\n",
__clk_get_name(clk), __clk_get_name(src_clk));
return NULL;
}
return clks;
}
static u8 _get_div_and_fieldval(struct clk *src_clk, struct clk *clk,
u32 *field_val)
{
const struct clksel *clks;
const struct clksel_rate *clkr, *max_clkr = NULL;
u8 max_div = 0;
clks = _get_clksel_by_parent(clk, src_clk);
if (!clks)
return 0;
for (clkr = clks->rates; clkr->div; clkr++) {
if (!(clkr->flags & cpu_mask))
continue;
if (clkr->div > max_div) {
max_div = clkr->div;
max_clkr = clkr;
}
}
if (max_div == 0) {
WARN(1, "clock: %s: could not find divisor for parent %s\n",
__clk_get_name(clk),
__clk_get_name(__clk_get_parent(src_clk)));
return 0;
}
*field_val = max_clkr->val;
return max_div;
}
static void _write_clksel_reg(struct clk *clk, u32 field_val)
{
u32 v;
v = __raw_readl(clk->clksel_reg);
v &= ~clk->clksel_mask;
v |= field_val << __ffs(clk->clksel_mask);
__raw_writel(v, clk->clksel_reg);
v = __raw_readl(clk->clksel_reg);
}
static u32 _clksel_to_divisor(struct clk *clk, u32 field_val)
{
const struct clksel *clks;
const struct clksel_rate *clkr;
struct clk *parent;
parent = __clk_get_parent(clk);
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
__clk_get_name(clk), field_val, __clk_get_name(parent));
return 0;
}
return clkr->div;
}
static u32 _divisor_to_clksel(struct clk *clk, u32 div)
{
const struct clksel *clks;
const struct clksel_rate *clkr;
struct clk *parent;
WARN_ON(div == 0);
parent = __clk_get_parent(clk);
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
__clk_get_name(clk), div, __clk_get_name(parent));
return ~0;
}
return clkr->val;
}
static u32 _read_divisor(struct clk *clk)
{
u32 v;
if (!clk->clksel || !clk->clksel_mask)
return 0;
v = __raw_readl(clk->clksel_reg);
v &= clk->clksel_mask;
v >>= __ffs(clk->clksel_mask);
return _clksel_to_divisor(clk, v);
}
u32 omap2_clksel_round_rate_div(struct clk *clk, unsigned long target_rate,
u32 *new_div)
{
unsigned long test_rate;
const struct clksel *clks;
const struct clksel_rate *clkr;
u32 last_div = 0;
struct clk *parent;
unsigned long parent_rate;
const char *clk_name;
parent = __clk_get_parent(clk);
parent_rate = __clk_get_rate(parent);
clk_name = __clk_get_name(clk);
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
void omap2_init_clksel_parent(struct clk *clk)
{
const struct clksel *clks;
const struct clksel_rate *clkr;
u32 r, found = 0;
struct clk *parent;
const char *clk_name;
if (!clk->clksel || !clk->clksel_mask)
return;
parent = __clk_get_parent(clk);
clk_name = __clk_get_name(clk);
r = __raw_readl(clk->clksel_reg) & clk->clksel_mask;
r >>= __ffs(clk->clksel_mask);
for (clks = clk->clksel; clks->parent && !found; clks++) {
for (clkr = clks->rates; clkr->div && !found; clkr++) {
if (!(clkr->flags & cpu_mask))
continue;
if (clkr->val == r) {
if (parent != clks->parent) {
pr_debug("clock: %s: inited parent to %s (was %s)\n",
clk_name,
__clk_get_name(clks->parent),
((parent) ?
__clk_get_name(parent) :
"NULL"));
clk_reparent(clk, clks->parent);
}
found = 1;
}
}
}
WARN(!found, "clock: %s: init parent: could not find regval %0x\n",
clk_name, r);
return;
}
unsigned long omap2_clksel_recalc(struct clk *clk)
{
unsigned long rate;
u32 div = 0;
struct clk *parent;
div = _read_divisor(clk);
if (div == 0)
return __clk_get_rate(clk);
parent = __clk_get_parent(clk);
rate = __clk_get_rate(parent) / div;
pr_debug("clock: %s: recalc'd rate is %ld (div %d)\n",
__clk_get_name(clk), rate, div);
return rate;
}
long omap2_clksel_round_rate(struct clk *clk, unsigned long target_rate)
{
u32 new_div;
return omap2_clksel_round_rate_div(clk, target_rate, &new_div);
}
int omap2_clksel_set_rate(struct clk *clk, unsigned long rate)
{
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
clk->rate = __clk_get_rate(__clk_get_parent(clk)) / new_div;
pr_debug("clock: %s: set rate to %ld\n", __clk_get_name(clk),
__clk_get_rate(clk));
return 0;
}
int omap2_clksel_set_parent(struct clk *clk, struct clk *new_parent)
{
u32 field_val = 0;
u32 parent_div;
if (!clk->clksel || !clk->clksel_mask)
return -EINVAL;
parent_div = _get_div_and_fieldval(new_parent, clk, &field_val);
if (!parent_div)
return -EINVAL;
_write_clksel_reg(clk, field_val);
clk_reparent(clk, new_parent);
clk->rate = __clk_get_rate(new_parent);
if (parent_div > 0)
__clk_get_rate(clk) /= parent_div;
pr_debug("clock: %s: set parent to %s (new rate %ld)\n",
__clk_get_name(clk),
__clk_get_name(__clk_get_parent(clk)),
__clk_get_rate(clk));
return 0;
}
