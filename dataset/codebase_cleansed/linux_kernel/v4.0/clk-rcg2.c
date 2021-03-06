static int clk_rcg2_is_enabled(struct clk_hw *hw)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
u32 cmd;
int ret;
ret = regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CMD_REG, &cmd);
if (ret)
return ret;
return (cmd & CMD_ROOT_OFF) == 0;
}
static u8 clk_rcg2_get_parent(struct clk_hw *hw)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
int num_parents = __clk_get_num_parents(hw->clk);
u32 cfg;
int i, ret;
ret = regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG, &cfg);
if (ret)
return ret;
cfg &= CFG_SRC_SEL_MASK;
cfg >>= CFG_SRC_SEL_SHIFT;
for (i = 0; i < num_parents; i++)
if (cfg == rcg->parent_map[i])
return i;
return -EINVAL;
}
static int update_config(struct clk_rcg2 *rcg)
{
int count, ret;
u32 cmd;
struct clk_hw *hw = &rcg->clkr.hw;
const char *name = __clk_get_name(hw->clk);
ret = regmap_update_bits(rcg->clkr.regmap, rcg->cmd_rcgr + CMD_REG,
CMD_UPDATE, CMD_UPDATE);
if (ret)
return ret;
for (count = 500; count > 0; count--) {
ret = regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CMD_REG, &cmd);
if (ret)
return ret;
if (!(cmd & CMD_UPDATE))
return 0;
udelay(1);
}
WARN(1, "%s: rcg didn't update its configuration.", name);
return 0;
}
static int clk_rcg2_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
int ret;
ret = regmap_update_bits(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG,
CFG_SRC_SEL_MASK,
rcg->parent_map[index] << CFG_SRC_SEL_SHIFT);
if (ret)
return ret;
return update_config(rcg);
}
static unsigned long
calc_rate(unsigned long rate, u32 m, u32 n, u32 mode, u32 hid_div)
{
if (hid_div) {
rate *= 2;
rate /= hid_div + 1;
}
if (mode) {
u64 tmp = rate;
tmp *= m;
do_div(tmp, n);
rate = tmp;
}
return rate;
}
static unsigned long
clk_rcg2_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
u32 cfg, hid_div, m = 0, n = 0, mode = 0, mask;
regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG, &cfg);
if (rcg->mnd_width) {
mask = BIT(rcg->mnd_width) - 1;
regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + M_REG, &m);
m &= mask;
regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + N_REG, &n);
n = ~n;
n &= mask;
n += m;
mode = cfg & CFG_MODE_MASK;
mode >>= CFG_MODE_SHIFT;
}
mask = BIT(rcg->hid_width) - 1;
hid_div = cfg >> CFG_SRC_DIV_SHIFT;
hid_div &= mask;
return calc_rate(parent_rate, m, n, mode, hid_div);
}
static long _freq_tbl_determine_rate(struct clk_hw *hw,
const struct freq_tbl *f, unsigned long rate,
unsigned long *p_rate, struct clk_hw **p_hw)
{
unsigned long clk_flags;
struct clk *p;
f = qcom_find_freq(f, rate);
if (!f)
return -EINVAL;
clk_flags = __clk_get_flags(hw->clk);
p = clk_get_parent_by_index(hw->clk, f->src);
if (clk_flags & CLK_SET_RATE_PARENT) {
if (f->pre_div) {
rate /= 2;
rate *= f->pre_div + 1;
}
if (f->n) {
u64 tmp = rate;
tmp = tmp * f->n;
do_div(tmp, f->m);
rate = tmp;
}
} else {
rate = __clk_get_rate(p);
}
*p_hw = __clk_get_hw(p);
*p_rate = rate;
return f->freq;
}
static long clk_rcg2_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long min_rate, unsigned long max_rate,
unsigned long *p_rate, struct clk_hw **p)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
return _freq_tbl_determine_rate(hw, rcg->freq_tbl, rate, p_rate, p);
}
static int clk_rcg2_configure(struct clk_rcg2 *rcg, const struct freq_tbl *f)
{
u32 cfg, mask;
int ret;
if (rcg->mnd_width && f->n) {
mask = BIT(rcg->mnd_width) - 1;
ret = regmap_update_bits(rcg->clkr.regmap,
rcg->cmd_rcgr + M_REG, mask, f->m);
if (ret)
return ret;
ret = regmap_update_bits(rcg->clkr.regmap,
rcg->cmd_rcgr + N_REG, mask, ~(f->n - f->m));
if (ret)
return ret;
ret = regmap_update_bits(rcg->clkr.regmap,
rcg->cmd_rcgr + D_REG, mask, ~f->n);
if (ret)
return ret;
}
mask = BIT(rcg->hid_width) - 1;
mask |= CFG_SRC_SEL_MASK | CFG_MODE_MASK;
cfg = f->pre_div << CFG_SRC_DIV_SHIFT;
cfg |= rcg->parent_map[f->src] << CFG_SRC_SEL_SHIFT;
if (rcg->mnd_width && f->n)
cfg |= CFG_MODE_DUAL_EDGE;
ret = regmap_update_bits(rcg->clkr.regmap,
rcg->cmd_rcgr + CFG_REG, mask, cfg);
if (ret)
return ret;
return update_config(rcg);
}
static int __clk_rcg2_set_rate(struct clk_hw *hw, unsigned long rate)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
const struct freq_tbl *f;
f = qcom_find_freq(rcg->freq_tbl, rate);
if (!f)
return -EINVAL;
return clk_rcg2_configure(rcg, f);
}
static int clk_rcg2_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
return __clk_rcg2_set_rate(hw, rate);
}
static int clk_rcg2_set_rate_and_parent(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate, u8 index)
{
return __clk_rcg2_set_rate(hw, rate);
}
static int clk_edp_pixel_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
struct freq_tbl f = *rcg->freq_tbl;
const struct frac_entry *frac;
int delta = 100000;
s64 src_rate = parent_rate;
s64 request;
u32 mask = BIT(rcg->hid_width) - 1;
u32 hid_div;
if (src_rate == 810000000)
frac = frac_table_810m;
else
frac = frac_table_675m;
for (; frac->num; frac++) {
request = rate;
request *= frac->den;
request = div_s64(request, frac->num);
if ((src_rate < (request - delta)) ||
(src_rate > (request + delta)))
continue;
regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG,
&hid_div);
f.pre_div = hid_div;
f.pre_div >>= CFG_SRC_DIV_SHIFT;
f.pre_div &= mask;
f.m = frac->num;
f.n = frac->den;
return clk_rcg2_configure(rcg, &f);
}
return -EINVAL;
}
static int clk_edp_pixel_set_rate_and_parent(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate, u8 index)
{
return clk_edp_pixel_set_rate(hw, rate, parent_rate);
}
static long clk_edp_pixel_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long min_rate,
unsigned long max_rate,
unsigned long *p_rate, struct clk_hw **p)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
const struct freq_tbl *f = rcg->freq_tbl;
const struct frac_entry *frac;
int delta = 100000;
s64 src_rate = *p_rate;
s64 request;
u32 mask = BIT(rcg->hid_width) - 1;
u32 hid_div;
*p = __clk_get_hw(clk_get_parent_by_index(hw->clk, f->src));
if (src_rate == 810000000)
frac = frac_table_810m;
else
frac = frac_table_675m;
for (; frac->num; frac++) {
request = rate;
request *= frac->den;
request = div_s64(request, frac->num);
if ((src_rate < (request - delta)) ||
(src_rate > (request + delta)))
continue;
regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG,
&hid_div);
hid_div >>= CFG_SRC_DIV_SHIFT;
hid_div &= mask;
return calc_rate(src_rate, frac->num, frac->den, !!frac->den,
hid_div);
}
return -EINVAL;
}
static long clk_byte_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long min_rate, unsigned long max_rate,
unsigned long *p_rate, struct clk_hw **p_hw)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
const struct freq_tbl *f = rcg->freq_tbl;
unsigned long parent_rate, div;
u32 mask = BIT(rcg->hid_width) - 1;
struct clk *p;
if (rate == 0)
return -EINVAL;
p = clk_get_parent_by_index(hw->clk, f->src);
*p_hw = __clk_get_hw(p);
*p_rate = parent_rate = __clk_round_rate(p, rate);
div = DIV_ROUND_UP((2 * parent_rate), rate) - 1;
div = min_t(u32, div, mask);
return calc_rate(parent_rate, 0, 0, 0, div);
}
static int clk_byte_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
struct freq_tbl f = *rcg->freq_tbl;
unsigned long div;
u32 mask = BIT(rcg->hid_width) - 1;
div = DIV_ROUND_UP((2 * parent_rate), rate) - 1;
div = min_t(u32, div, mask);
f.pre_div = div;
return clk_rcg2_configure(rcg, &f);
}
static int clk_byte_set_rate_and_parent(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate, u8 index)
{
return clk_byte_set_rate(hw, rate, parent_rate);
}
static long clk_pixel_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long min_rate,
unsigned long max_rate,
unsigned long *p_rate, struct clk_hw **p)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
unsigned long request, src_rate;
int delta = 100000;
const struct freq_tbl *f = rcg->freq_tbl;
const struct frac_entry *frac = frac_table_pixel;
struct clk *parent = clk_get_parent_by_index(hw->clk, f->src);
*p = __clk_get_hw(parent);
for (; frac->num; frac++) {
request = (rate * frac->den) / frac->num;
src_rate = __clk_round_rate(parent, request);
if ((src_rate < (request - delta)) ||
(src_rate > (request + delta)))
continue;
*p_rate = src_rate;
return (src_rate * frac->num) / frac->den;
}
return -EINVAL;
}
static int clk_pixel_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
struct freq_tbl f = *rcg->freq_tbl;
const struct frac_entry *frac = frac_table_pixel;
unsigned long request, src_rate;
int delta = 100000;
u32 mask = BIT(rcg->hid_width) - 1;
u32 hid_div;
struct clk *parent = clk_get_parent_by_index(hw->clk, f.src);
for (; frac->num; frac++) {
request = (rate * frac->den) / frac->num;
src_rate = __clk_round_rate(parent, request);
if ((src_rate < (request - delta)) ||
(src_rate > (request + delta)))
continue;
regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG,
&hid_div);
f.pre_div = hid_div;
f.pre_div >>= CFG_SRC_DIV_SHIFT;
f.pre_div &= mask;
f.m = frac->num;
f.n = frac->den;
return clk_rcg2_configure(rcg, &f);
}
return -EINVAL;
}
static int clk_pixel_set_rate_and_parent(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate, u8 index)
{
return clk_pixel_set_rate(hw, rate, parent_rate);
}
