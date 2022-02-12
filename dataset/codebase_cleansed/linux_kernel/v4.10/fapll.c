static bool ti_fapll_clock_is_bypass(struct fapll_data *fd)
{
u32 v = readl_relaxed(fd->base);
if (fd->bypass_bit_inverted)
return !(v & FAPLL_MAIN_BP);
else
return !!(v & FAPLL_MAIN_BP);
}
static void ti_fapll_set_bypass(struct fapll_data *fd)
{
u32 v = readl_relaxed(fd->base);
if (fd->bypass_bit_inverted)
v &= ~FAPLL_MAIN_BP;
else
v |= FAPLL_MAIN_BP;
writel_relaxed(v, fd->base);
}
static void ti_fapll_clear_bypass(struct fapll_data *fd)
{
u32 v = readl_relaxed(fd->base);
if (fd->bypass_bit_inverted)
v |= FAPLL_MAIN_BP;
else
v &= ~FAPLL_MAIN_BP;
writel_relaxed(v, fd->base);
}
static int ti_fapll_wait_lock(struct fapll_data *fd)
{
int retries = FAPLL_MAX_RETRIES;
u32 v;
while ((v = readl_relaxed(fd->base))) {
if (v & FAPLL_MAIN_LOCK)
return 0;
if (retries-- <= 0)
break;
udelay(1);
}
pr_err("%s failed to lock\n", fd->name);
return -ETIMEDOUT;
}
static int ti_fapll_enable(struct clk_hw *hw)
{
struct fapll_data *fd = to_fapll(hw);
u32 v = readl_relaxed(fd->base);
v |= FAPLL_MAIN_PLLEN;
writel_relaxed(v, fd->base);
ti_fapll_wait_lock(fd);
return 0;
}
static void ti_fapll_disable(struct clk_hw *hw)
{
struct fapll_data *fd = to_fapll(hw);
u32 v = readl_relaxed(fd->base);
v &= ~FAPLL_MAIN_PLLEN;
writel_relaxed(v, fd->base);
}
static int ti_fapll_is_enabled(struct clk_hw *hw)
{
struct fapll_data *fd = to_fapll(hw);
u32 v = readl_relaxed(fd->base);
return v & FAPLL_MAIN_PLLEN;
}
static unsigned long ti_fapll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct fapll_data *fd = to_fapll(hw);
u32 fapll_n, fapll_p, v;
u64 rate;
if (ti_fapll_clock_is_bypass(fd))
return parent_rate;
rate = parent_rate;
v = readl_relaxed(fd->base);
fapll_p = (v >> 8) & 0xff;
if (fapll_p)
do_div(rate, fapll_p);
fapll_n = v >> 16;
if (fapll_n)
rate *= fapll_n;
return rate;
}
static u8 ti_fapll_get_parent(struct clk_hw *hw)
{
struct fapll_data *fd = to_fapll(hw);
if (ti_fapll_clock_is_bypass(fd))
return 1;
return 0;
}
static int ti_fapll_set_div_mult(unsigned long rate,
unsigned long parent_rate,
u32 *pre_div_p, u32 *mult_n)
{
if (rate < parent_rate) {
pr_warn("FAPLL main divider rates unsupported\n");
return -EINVAL;
}
*mult_n = rate / parent_rate;
if (*mult_n > FAPLL_MAIN_MAX_MULT_N)
return -EINVAL;
*pre_div_p = 1;
return 0;
}
static long ti_fapll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
u32 pre_div_p, mult_n;
int error;
if (!rate)
return -EINVAL;
error = ti_fapll_set_div_mult(rate, *parent_rate,
&pre_div_p, &mult_n);
if (error)
return error;
rate = *parent_rate / pre_div_p;
rate *= mult_n;
return rate;
}
static int ti_fapll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct fapll_data *fd = to_fapll(hw);
u32 pre_div_p, mult_n, v;
int error;
if (!rate)
return -EINVAL;
error = ti_fapll_set_div_mult(rate, parent_rate,
&pre_div_p, &mult_n);
if (error)
return error;
ti_fapll_set_bypass(fd);
v = readl_relaxed(fd->base);
v &= ~FAPLL_MAIN_CLEAR_MASK;
v |= pre_div_p << FAPLL_MAIN_DIV_P_SHIFT;
v |= mult_n << FAPLL_MAIN_MULT_N_SHIFT;
writel_relaxed(v, fd->base);
if (ti_fapll_is_enabled(hw))
ti_fapll_wait_lock(fd);
ti_fapll_clear_bypass(fd);
return 0;
}
static int ti_fapll_synth_enable(struct clk_hw *hw)
{
struct fapll_synth *synth = to_synth(hw);
u32 v = readl_relaxed(synth->fd->base + FAPLL_PWD_OFFSET);
v &= ~(1 << synth->index);
writel_relaxed(v, synth->fd->base + FAPLL_PWD_OFFSET);
return 0;
}
static void ti_fapll_synth_disable(struct clk_hw *hw)
{
struct fapll_synth *synth = to_synth(hw);
u32 v = readl_relaxed(synth->fd->base + FAPLL_PWD_OFFSET);
v |= 1 << synth->index;
writel_relaxed(v, synth->fd->base + FAPLL_PWD_OFFSET);
}
static int ti_fapll_synth_is_enabled(struct clk_hw *hw)
{
struct fapll_synth *synth = to_synth(hw);
u32 v = readl_relaxed(synth->fd->base + FAPLL_PWD_OFFSET);
return !(v & (1 << synth->index));
}
static unsigned long ti_fapll_synth_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct fapll_synth *synth = to_synth(hw);
u32 synth_div_m;
u64 rate;
if (!synth->div)
return 32768;
if (ti_fapll_clock_is_bypass(synth->fd))
return parent_rate;
rate = parent_rate;
if (synth->freq) {
u32 v, synth_int_div, synth_frac_div, synth_div_freq;
v = readl_relaxed(synth->freq);
synth_int_div = (v >> 24) & 0xf;
synth_frac_div = v & 0xffffff;
synth_div_freq = (synth_int_div * 10000000) + synth_frac_div;
rate *= 10000000;
do_div(rate, synth_div_freq);
rate *= SYNTH_PHASE_K;
}
synth_div_m = readl_relaxed(synth->div) & SYNTH_MAX_DIV_M;
return DIV_ROUND_UP_ULL(rate, synth_div_m);
}
static unsigned long ti_fapll_synth_get_frac_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct fapll_synth *synth = to_synth(hw);
unsigned long current_rate, frac_rate;
u32 post_div_m;
current_rate = ti_fapll_synth_recalc_rate(hw, parent_rate);
post_div_m = readl_relaxed(synth->div) & SYNTH_MAX_DIV_M;
frac_rate = current_rate * post_div_m;
return frac_rate;
}
static u32 ti_fapll_synth_set_frac_rate(struct fapll_synth *synth,
unsigned long rate,
unsigned long parent_rate)
{
u32 post_div_m, synth_int_div = 0, synth_frac_div = 0, v;
post_div_m = DIV_ROUND_UP_ULL((u64)parent_rate * SYNTH_PHASE_K, rate);
post_div_m = post_div_m / SYNTH_MAX_INT_DIV;
if (post_div_m > SYNTH_MAX_DIV_M)
return -EINVAL;
if (!post_div_m)
post_div_m = 1;
for (; post_div_m < SYNTH_MAX_DIV_M; post_div_m++) {
synth_int_div = DIV_ROUND_UP_ULL((u64)parent_rate *
SYNTH_PHASE_K *
10000000,
rate * post_div_m);
synth_frac_div = synth_int_div % 10000000;
synth_int_div /= 10000000;
if (synth_int_div <= SYNTH_MAX_INT_DIV)
break;
}
if (synth_int_div > SYNTH_MAX_INT_DIV)
return -EINVAL;
v = readl_relaxed(synth->freq);
v &= ~0x1fffffff;
v |= (synth_int_div & SYNTH_MAX_INT_DIV) << 24;
v |= (synth_frac_div & 0xffffff);
v |= SYNTH_LDFREQ;
writel_relaxed(v, synth->freq);
return post_div_m;
}
static long ti_fapll_synth_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct fapll_synth *synth = to_synth(hw);
struct fapll_data *fd = synth->fd;
unsigned long r;
if (ti_fapll_clock_is_bypass(fd) || !synth->div || !rate)
return -EINVAL;
if (!synth->freq) {
unsigned long frac_rate;
u32 synth_post_div_m;
frac_rate = ti_fapll_synth_get_frac_rate(hw, *parent_rate);
synth_post_div_m = DIV_ROUND_UP(frac_rate, rate);
r = DIV_ROUND_UP(frac_rate, synth_post_div_m);
goto out;
}
r = *parent_rate * SYNTH_PHASE_K;
if (rate > r)
goto out;
r = DIV_ROUND_UP_ULL(r, SYNTH_MAX_INT_DIV * SYNTH_MAX_DIV_M);
if (rate < r)
goto out;
r = rate;
out:
return r;
}
static int ti_fapll_synth_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct fapll_synth *synth = to_synth(hw);
struct fapll_data *fd = synth->fd;
unsigned long frac_rate, post_rate = 0;
u32 post_div_m = 0, v;
if (ti_fapll_clock_is_bypass(fd) || !synth->div || !rate)
return -EINVAL;
frac_rate = ti_fapll_synth_get_frac_rate(hw, parent_rate);
if (frac_rate < rate) {
if (!synth->freq)
return -EINVAL;
} else {
post_div_m = DIV_ROUND_UP(frac_rate, rate);
if (post_div_m && (post_div_m <= SYNTH_MAX_DIV_M))
post_rate = DIV_ROUND_UP(frac_rate, post_div_m);
if (!synth->freq && !post_rate)
return -EINVAL;
}
if ((post_rate != rate) && synth->freq)
post_div_m = ti_fapll_synth_set_frac_rate(synth,
rate,
parent_rate);
v = readl_relaxed(synth->div);
v &= ~SYNTH_MAX_DIV_M;
v |= post_div_m;
v |= SYNTH_LDMDIV1;
writel_relaxed(v, synth->div);
return 0;
}
static struct clk * __init ti_fapll_synth_setup(struct fapll_data *fd,
void __iomem *freq,
void __iomem *div,
int index,
const char *name,
const char *parent,
struct clk *pll_clk)
{
struct clk_init_data *init;
struct fapll_synth *synth;
init = kzalloc(sizeof(*init), GFP_KERNEL);
if (!init)
return ERR_PTR(-ENOMEM);
init->ops = &ti_fapll_synt_ops;
init->name = name;
init->parent_names = &parent;
init->num_parents = 1;
synth = kzalloc(sizeof(*synth), GFP_KERNEL);
if (!synth)
goto free;
synth->fd = fd;
synth->index = index;
synth->freq = freq;
synth->div = div;
synth->name = name;
synth->hw.init = init;
synth->clk_pll = pll_clk;
return clk_register(NULL, &synth->hw);
free:
kfree(synth);
kfree(init);
return ERR_PTR(-ENOMEM);
}
static void __init ti_fapll_setup(struct device_node *node)
{
struct fapll_data *fd;
struct clk_init_data *init = NULL;
const char *parent_name[2];
struct clk *pll_clk;
int i;
fd = kzalloc(sizeof(*fd), GFP_KERNEL);
if (!fd)
return;
fd->outputs.clks = kzalloc(sizeof(struct clk *) *
MAX_FAPLL_OUTPUTS + 1,
GFP_KERNEL);
if (!fd->outputs.clks)
goto free;
init = kzalloc(sizeof(*init), GFP_KERNEL);
if (!init)
goto free;
init->ops = &ti_fapll_ops;
init->name = node->name;
init->num_parents = of_clk_get_parent_count(node);
if (init->num_parents != 2) {
pr_err("%s must have two parents\n", node->name);
goto free;
}
of_clk_parent_fill(node, parent_name, 2);
init->parent_names = parent_name;
fd->clk_ref = of_clk_get(node, 0);
if (IS_ERR(fd->clk_ref)) {
pr_err("%s could not get clk_ref\n", node->name);
goto free;
}
fd->clk_bypass = of_clk_get(node, 1);
if (IS_ERR(fd->clk_bypass)) {
pr_err("%s could not get clk_bypass\n", node->name);
goto free;
}
fd->base = of_iomap(node, 0);
if (!fd->base) {
pr_err("%s could not get IO base\n", node->name);
goto free;
}
if (fapll_is_ddr_pll(fd->base))
fd->bypass_bit_inverted = true;
fd->name = node->name;
fd->hw.init = init;
pll_clk = clk_register(NULL, &fd->hw);
if (IS_ERR(pll_clk))
goto unmap;
fd->outputs.clks[0] = pll_clk;
fd->outputs.clk_num++;
for (i = 0; i < MAX_FAPLL_OUTPUTS; i++) {
const char *output_name;
void __iomem *freq, *div;
struct clk *synth_clk;
int output_instance;
u32 v;
if (of_property_read_string_index(node, "clock-output-names",
i, &output_name))
continue;
if (of_property_read_u32_index(node, "clock-indices", i,
&output_instance))
output_instance = i;
freq = fd->base + (output_instance * 8);
div = freq + 4;
if (is_audio_pll_clk1(freq)) {
freq = NULL;
div = NULL;
} else {
v = readl_relaxed(freq);
if (!v)
freq = NULL;
}
synth_clk = ti_fapll_synth_setup(fd, freq, div, output_instance,
output_name, node->name,
pll_clk);
if (IS_ERR(synth_clk))
continue;
fd->outputs.clks[output_instance] = synth_clk;
fd->outputs.clk_num++;
clk_register_clkdev(synth_clk, output_name, NULL);
}
of_clk_add_provider(node, of_clk_src_onecell_get, &fd->outputs);
kfree(init);
return;
unmap:
iounmap(fd->base);
free:
if (fd->clk_bypass)
clk_put(fd->clk_bypass);
if (fd->clk_ref)
clk_put(fd->clk_ref);
kfree(fd->outputs.clks);
kfree(fd);
kfree(init);
}
