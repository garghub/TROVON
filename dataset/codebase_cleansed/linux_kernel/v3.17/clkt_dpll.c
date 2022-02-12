static int _dpll_test_fint(struct clk_hw_omap *clk, unsigned int n)
{
struct dpll_data *dd;
long fint, fint_min, fint_max;
int ret = 0;
dd = clk->dpll_data;
fint = __clk_get_rate(__clk_get_parent(clk->hw.clk)) / n;
if (dd->flags & DPLL_J_TYPE) {
fint_min = OMAP3PLUS_DPLL_FINT_JTYPE_MIN;
fint_max = OMAP3PLUS_DPLL_FINT_JTYPE_MAX;
} else {
fint_min = ti_clk_features.fint_min;
fint_max = ti_clk_features.fint_max;
}
if (!fint_min || !fint_max) {
WARN(1, "No fint limits available!\n");
return DPLL_FINT_INVALID;
}
if (fint < ti_clk_features.fint_min) {
pr_debug("rejecting n=%d due to Fint failure, lowering max_divider\n",
n);
dd->max_divider = n;
ret = DPLL_FINT_UNDERFLOW;
} else if (fint > ti_clk_features.fint_max) {
pr_debug("rejecting n=%d due to Fint failure, boosting min_divider\n",
n);
dd->min_divider = n;
ret = DPLL_FINT_INVALID;
} else if (fint > ti_clk_features.fint_band1_max &&
fint < ti_clk_features.fint_band2_min) {
pr_debug("rejecting n=%d due to Fint failure\n", n);
ret = DPLL_FINT_INVALID;
}
return ret;
}
static unsigned long _dpll_compute_new_rate(unsigned long parent_rate,
unsigned int m, unsigned int n)
{
unsigned long long num;
num = (unsigned long long)parent_rate * m;
do_div(num, n);
return num;
}
static int _dpll_test_mult(int *m, int n, unsigned long *new_rate,
unsigned long target_rate,
unsigned long parent_rate)
{
int r = 0, carry = 0;
if (*m % DPLL_SCALE_FACTOR >= DPLL_ROUNDING_VAL)
carry = 1;
*m = (*m / DPLL_SCALE_FACTOR) + carry;
*new_rate = _dpll_compute_new_rate(parent_rate, *m, n);
if (*new_rate > target_rate) {
(*m)--;
*new_rate = 0;
}
if (*m < DPLL_MIN_MULTIPLIER) {
*m = DPLL_MIN_MULTIPLIER;
*new_rate = 0;
r = DPLL_MULT_UNDERFLOW;
}
if (*new_rate == 0)
*new_rate = _dpll_compute_new_rate(parent_rate, *m, n);
return r;
}
static int _omap2_dpll_is_in_bypass(u32 v)
{
u8 mask, val;
mask = ti_clk_features.dpll_bypass_vals;
while (mask) {
val = __ffs(mask);
mask ^= (1 << val);
if (v == val)
return 1;
}
return 0;
}
u8 omap2_init_dpll_parent(struct clk_hw *hw)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 v;
struct dpll_data *dd;
dd = clk->dpll_data;
if (!dd)
return -EINVAL;
v = omap2_clk_readl(clk, dd->control_reg);
v &= dd->enable_mask;
v >>= __ffs(dd->enable_mask);
if (_omap2_dpll_is_in_bypass(v))
return 1;
return 0;
}
unsigned long omap2_get_dpll_rate(struct clk_hw_omap *clk)
{
long long dpll_clk;
u32 dpll_mult, dpll_div, v;
struct dpll_data *dd;
dd = clk->dpll_data;
if (!dd)
return 0;
v = omap2_clk_readl(clk, dd->control_reg);
v &= dd->enable_mask;
v >>= __ffs(dd->enable_mask);
if (_omap2_dpll_is_in_bypass(v))
return __clk_get_rate(dd->clk_bypass);
v = omap2_clk_readl(clk, dd->mult_div1_reg);
dpll_mult = v & dd->mult_mask;
dpll_mult >>= __ffs(dd->mult_mask);
dpll_div = v & dd->div1_mask;
dpll_div >>= __ffs(dd->div1_mask);
dpll_clk = (long long) __clk_get_rate(dd->clk_ref) * dpll_mult;
do_div(dpll_clk, dpll_div + 1);
return dpll_clk;
}
long omap2_dpll_round_rate(struct clk_hw *hw, unsigned long target_rate,
unsigned long *parent_rate)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
int m, n, r, scaled_max_m;
int min_delta_m = INT_MAX, min_delta_n = INT_MAX;
unsigned long scaled_rt_rp;
unsigned long new_rate = 0;
struct dpll_data *dd;
unsigned long ref_rate;
long delta;
long prev_min_delta = LONG_MAX;
const char *clk_name;
if (!clk || !clk->dpll_data)
return ~0;
dd = clk->dpll_data;
ref_rate = __clk_get_rate(dd->clk_ref);
clk_name = __clk_get_name(hw->clk);
pr_debug("clock: %s: starting DPLL round_rate, target rate %lu\n",
clk_name, target_rate);
scaled_rt_rp = target_rate / (ref_rate / DPLL_SCALE_FACTOR);
scaled_max_m = dd->max_multiplier * DPLL_SCALE_FACTOR;
dd->last_rounded_rate = 0;
for (n = dd->min_divider; n <= dd->max_divider; n++) {
r = _dpll_test_fint(clk, n);
if (r == DPLL_FINT_UNDERFLOW)
break;
else if (r == DPLL_FINT_INVALID)
continue;
m = scaled_rt_rp * n;
if (m > scaled_max_m)
break;
r = _dpll_test_mult(&m, n, &new_rate, target_rate,
ref_rate);
if (r == DPLL_MULT_UNDERFLOW)
continue;
delta = target_rate - new_rate;
if (delta < 0)
continue;
if (delta < prev_min_delta) {
prev_min_delta = delta;
min_delta_m = m;
min_delta_n = n;
}
pr_debug("clock: %s: m = %d: n = %d: new_rate = %lu\n",
clk_name, m, n, new_rate);
if (delta == 0)
break;
}
if (prev_min_delta == LONG_MAX) {
pr_debug("clock: %s: cannot round to rate %lu\n",
clk_name, target_rate);
return ~0;
}
dd->last_rounded_m = min_delta_m;
dd->last_rounded_n = min_delta_n;
dd->last_rounded_rate = target_rate - prev_min_delta;
return dd->last_rounded_rate;
}
