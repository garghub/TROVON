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
int num_parents = clk_hw_get_num_parents(hw);
u32 cfg;
int i, ret;
ret = regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG, &cfg);
if (ret)
goto err;
cfg &= CFG_SRC_SEL_MASK;
cfg >>= CFG_SRC_SEL_SHIFT;
for (i = 0; i < num_parents; i++)
if (cfg == rcg->parent_map[i].cfg)
return i;
err:
pr_debug("%s: Clock %s has invalid parent, using default.\n",
__func__, clk_hw_get_name(hw));
return 0;
}
static int update_config(struct clk_rcg2 *rcg)
{
int count, ret;
u32 cmd;
struct clk_hw *hw = &rcg->clkr.hw;
const char *name = clk_hw_get_name(hw);
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
u32 cfg = rcg->parent_map[index].cfg << CFG_SRC_SEL_SHIFT;
ret = regmap_update_bits(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG,
CFG_SRC_SEL_MASK, cfg);
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
static int _freq_tbl_determine_rate(struct clk_hw *hw,
const struct freq_tbl *f, struct clk_rate_request *req)
{
unsigned long clk_flags, rate = req->rate;
struct clk_hw *p;
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
int index;
f = qcom_find_freq(f, rate);
if (!f)
return -EINVAL;
index = qcom_find_src_index(hw, rcg->parent_map, f->src);
if (index < 0)
return index;
clk_flags = clk_hw_get_flags(hw);
p = clk_hw_get_parent_by_index(hw, index);
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
rate = clk_hw_get_rate(p);
}
req->best_parent_hw = p;
req->best_parent_rate = rate;
req->rate = f->freq;
return 0;
}
static int clk_rcg2_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
return _freq_tbl_determine_rate(hw, rcg->freq_tbl, req);
}
static int clk_rcg2_configure(struct clk_rcg2 *rcg, const struct freq_tbl *f)
{
u32 cfg, mask;
struct clk_hw *hw = &rcg->clkr.hw;
int ret, index = qcom_find_src_index(hw, rcg->parent_map, f->src);
if (index < 0)
return index;
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
cfg |= rcg->parent_map[index].cfg << CFG_SRC_SEL_SHIFT;
if (rcg->mnd_width && f->n && (f->m != f->n))
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
static int clk_edp_pixel_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
const struct freq_tbl *f = rcg->freq_tbl;
const struct frac_entry *frac;
int delta = 100000;
s64 request;
u32 mask = BIT(rcg->hid_width) - 1;
u32 hid_div;
int index = qcom_find_src_index(hw, rcg->parent_map, f->src);
req->best_parent_hw = clk_hw_get_parent_by_index(hw, index);
req->best_parent_rate = clk_hw_get_rate(req->best_parent_hw);
if (req->best_parent_rate == 810000000)
frac = frac_table_810m;
else
frac = frac_table_675m;
for (; frac->num; frac++) {
request = req->rate;
request *= frac->den;
request = div_s64(request, frac->num);
if ((req->best_parent_rate < (request - delta)) ||
(req->best_parent_rate > (request + delta)))
continue;
regmap_read(rcg->clkr.regmap, rcg->cmd_rcgr + CFG_REG,
&hid_div);
hid_div >>= CFG_SRC_DIV_SHIFT;
hid_div &= mask;
req->rate = calc_rate(req->best_parent_rate,
frac->num, frac->den,
!!frac->den, hid_div);
return 0;
}
return -EINVAL;
}
static int clk_byte_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
const struct freq_tbl *f = rcg->freq_tbl;
int index = qcom_find_src_index(hw, rcg->parent_map, f->src);
unsigned long parent_rate, div;
u32 mask = BIT(rcg->hid_width) - 1;
struct clk_hw *p;
if (req->rate == 0)
return -EINVAL;
req->best_parent_hw = p = clk_hw_get_parent_by_index(hw, index);
req->best_parent_rate = parent_rate = clk_hw_round_rate(p, req->rate);
div = DIV_ROUND_UP((2 * parent_rate), req->rate) - 1;
div = min_t(u32, div, mask);
req->rate = calc_rate(parent_rate, 0, 0, 0, div);
return 0;
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
static int clk_pixel_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
unsigned long request, src_rate;
int delta = 100000;
const struct freq_tbl *f = rcg->freq_tbl;
const struct frac_entry *frac = frac_table_pixel;
int index = qcom_find_src_index(hw, rcg->parent_map, f->src);
req->best_parent_hw = clk_hw_get_parent_by_index(hw, index);
for (; frac->num; frac++) {
request = (req->rate * frac->den) / frac->num;
src_rate = clk_hw_round_rate(req->best_parent_hw, request);
if ((src_rate < (request - delta)) ||
(src_rate > (request + delta)))
continue;
req->best_parent_rate = src_rate;
req->rate = (src_rate * frac->num) / frac->den;
return 0;
}
return -EINVAL;
}
static int clk_pixel_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_rcg2 *rcg = to_clk_rcg2(hw);
struct freq_tbl f = *rcg->freq_tbl;
const struct frac_entry *frac = frac_table_pixel;
unsigned long request;
int delta = 100000;
u32 mask = BIT(rcg->hid_width) - 1;
u32 hid_div;
for (; frac->num; frac++) {
request = (rate * frac->den) / frac->num;
if ((parent_rate < (request - delta)) ||
(parent_rate > (request + delta)))
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
