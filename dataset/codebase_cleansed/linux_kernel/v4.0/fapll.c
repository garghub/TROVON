static bool ti_fapll_clock_is_bypass(struct fapll_data *fd)
{
u32 v = readl_relaxed(fd->base);
if (fd->bypass_bit_inverted)
return !(v & FAPLL_MAIN_BP);
else
return !!(v & FAPLL_MAIN_BP);
}
static int ti_fapll_enable(struct clk_hw *hw)
{
struct fapll_data *fd = to_fapll(hw);
u32 v = readl_relaxed(fd->base);
v |= FAPLL_MAIN_PLLEN;
writel_relaxed(v, fd->base);
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
long long rate;
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
long long rate;
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
rate *= 8;
}
synth_div_m = readl_relaxed(synth->div) & 0xff;
do_div(rate, synth_div_m);
return rate;
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
parent_name[0] = of_clk_get_parent_name(node, 0);
parent_name[1] = of_clk_get_parent_name(node, 1);
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
freq = 0;
div = 0;
} else {
v = readl_relaxed(freq);
if (!v)
freq = 0;
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
