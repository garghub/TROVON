static int clk_audio_pll_frac_enable(struct clk_hw *hw)
{
struct clk_audio_frac *frac = to_clk_audio_frac(hw);
regmap_update_bits(frac->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_RESETN, 0);
regmap_update_bits(frac->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_RESETN,
AT91_PMC_AUDIO_PLL_RESETN);
regmap_update_bits(frac->regmap, AT91_PMC_AUDIO_PLL1,
AT91_PMC_AUDIO_PLL_FRACR_MASK, frac->fracr);
regmap_update_bits(frac->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_PLLEN |
AT91_PMC_AUDIO_PLL_ND_MASK,
AT91_PMC_AUDIO_PLL_PLLEN |
AT91_PMC_AUDIO_PLL_ND(frac->nd));
return 0;
}
static int clk_audio_pll_pad_enable(struct clk_hw *hw)
{
struct clk_audio_pad *apad_ck = to_clk_audio_pad(hw);
regmap_update_bits(apad_ck->regmap, AT91_PMC_AUDIO_PLL1,
AT91_PMC_AUDIO_PLL_QDPAD_MASK,
AUDIO_PLL_QDPAD(apad_ck->qdaudio, apad_ck->div));
regmap_update_bits(apad_ck->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_PADEN, AT91_PMC_AUDIO_PLL_PADEN);
return 0;
}
static int clk_audio_pll_pmc_enable(struct clk_hw *hw)
{
struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);
regmap_update_bits(apmc_ck->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_PMCEN |
AT91_PMC_AUDIO_PLL_QDPMC_MASK,
AT91_PMC_AUDIO_PLL_PMCEN |
AT91_PMC_AUDIO_PLL_QDPMC(apmc_ck->qdpmc));
return 0;
}
static void clk_audio_pll_frac_disable(struct clk_hw *hw)
{
struct clk_audio_frac *frac = to_clk_audio_frac(hw);
regmap_update_bits(frac->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_PLLEN, 0);
regmap_update_bits(frac->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_RESETN, 0);
}
static void clk_audio_pll_pad_disable(struct clk_hw *hw)
{
struct clk_audio_pad *apad_ck = to_clk_audio_pad(hw);
regmap_update_bits(apad_ck->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_PADEN, 0);
}
static void clk_audio_pll_pmc_disable(struct clk_hw *hw)
{
struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);
regmap_update_bits(apmc_ck->regmap, AT91_PMC_AUDIO_PLL0,
AT91_PMC_AUDIO_PLL_PMCEN, 0);
}
static unsigned long clk_audio_pll_fout(unsigned long parent_rate,
unsigned long nd, unsigned long fracr)
{
unsigned long long fr = (unsigned long long)parent_rate * fracr;
pr_debug("A PLL: %s, fr = %llu\n", __func__, fr);
fr = DIV_ROUND_CLOSEST_ULL(fr, AUDIO_PLL_DIV_FRAC);
pr_debug("A PLL: %s, fr = %llu\n", __func__, fr);
return parent_rate * (nd + 1) + fr;
}
static unsigned long clk_audio_pll_frac_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_audio_frac *frac = to_clk_audio_frac(hw);
unsigned long fout;
fout = clk_audio_pll_fout(parent_rate, frac->nd, frac->fracr);
pr_debug("A PLL: %s, fout = %lu (nd = %u, fracr = %lu)\n", __func__,
fout, frac->nd, (unsigned long)frac->fracr);
return fout;
}
static unsigned long clk_audio_pll_pad_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_audio_pad *apad_ck = to_clk_audio_pad(hw);
unsigned long apad_rate = 0;
if (apad_ck->qdaudio && apad_ck->div)
apad_rate = parent_rate / (apad_ck->qdaudio * apad_ck->div);
pr_debug("A PLL/PAD: %s, apad_rate = %lu (div = %u, qdaudio = %u)\n",
__func__, apad_rate, apad_ck->div, apad_ck->qdaudio);
return apad_rate;
}
static unsigned long clk_audio_pll_pmc_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);
unsigned long apmc_rate = 0;
apmc_rate = parent_rate / (apmc_ck->qdpmc + 1);
pr_debug("A PLL/PMC: %s, apmc_rate = %lu (qdpmc = %u)\n", __func__,
apmc_rate, apmc_ck->qdpmc);
return apmc_rate;
}
static int clk_audio_pll_frac_compute_frac(unsigned long rate,
unsigned long parent_rate,
unsigned long *nd,
unsigned long *fracr)
{
unsigned long long tmp, rem;
if (!rate)
return -EINVAL;
tmp = rate;
rem = do_div(tmp, parent_rate);
if (!tmp || tmp >= AUDIO_PLL_ND_MAX)
return -EINVAL;
*nd = tmp - 1;
tmp = rem * AUDIO_PLL_DIV_FRAC;
tmp = DIV_ROUND_CLOSEST_ULL(tmp, parent_rate);
if (tmp > AT91_PMC_AUDIO_PLL_FRACR_MASK)
return -EINVAL;
*fracr = (unsigned long)tmp;
return 0;
}
static int clk_audio_pll_frac_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
unsigned long fracr, nd;
int ret;
pr_debug("A PLL: %s, rate = %lu (parent_rate = %lu)\n", __func__,
req->rate, req->best_parent_rate);
req->rate = clamp(req->rate, AUDIO_PLL_FOUT_MIN, AUDIO_PLL_FOUT_MAX);
req->min_rate = max(req->min_rate, AUDIO_PLL_FOUT_MIN);
req->max_rate = min(req->max_rate, AUDIO_PLL_FOUT_MAX);
ret = clk_audio_pll_frac_compute_frac(req->rate, req->best_parent_rate,
&nd, &fracr);
if (ret)
return ret;
req->rate = clk_audio_pll_fout(req->best_parent_rate, nd, fracr);
req->best_parent_hw = clk_hw_get_parent(hw);
pr_debug("A PLL: %s, best_rate = %lu (nd = %lu, fracr = %lu)\n",
__func__, req->rate, nd, fracr);
return 0;
}
static long clk_audio_pll_pad_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct clk_hw *pclk = clk_hw_get_parent(hw);
long best_rate = -EINVAL;
unsigned long best_parent_rate;
unsigned long tmp_qd;
u32 div;
long tmp_rate;
int tmp_diff;
int best_diff = -1;
pr_debug("A PLL/PAD: %s, rate = %lu (parent_rate = %lu)\n", __func__,
rate, *parent_rate);
for (tmp_qd = 1; tmp_qd < AT91_PMC_AUDIO_PLL_QDPAD_EXTDIV_MAX; tmp_qd++)
for (div = 2; div <= 3; div++) {
if (div == 2 && tmp_qd % 3 == 0)
continue;
best_parent_rate = clk_hw_round_rate(pclk,
rate * tmp_qd * div);
tmp_rate = best_parent_rate / (div * tmp_qd);
tmp_diff = abs(rate - tmp_rate);
if (best_diff < 0 || best_diff > tmp_diff) {
*parent_rate = best_parent_rate;
best_rate = tmp_rate;
best_diff = tmp_diff;
}
}
pr_debug("A PLL/PAD: %s, best_rate = %ld, best_parent_rate = %lu\n",
__func__, best_rate, best_parent_rate);
return best_rate;
}
static long clk_audio_pll_pmc_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct clk_hw *pclk = clk_hw_get_parent(hw);
long best_rate = -EINVAL;
unsigned long best_parent_rate = 0;
u32 tmp_qd = 0, div;
long tmp_rate;
int tmp_diff;
int best_diff = -1;
pr_debug("A PLL/PMC: %s, rate = %lu (parent_rate = %lu)\n", __func__,
rate, *parent_rate);
for (div = 1; div <= AUDIO_PLL_QDPMC_MAX; div++) {
best_parent_rate = clk_round_rate(pclk->clk, rate * div);
tmp_rate = best_parent_rate / div;
tmp_diff = abs(rate - tmp_rate);
if (best_diff < 0 || best_diff > tmp_diff) {
*parent_rate = best_parent_rate;
best_rate = tmp_rate;
best_diff = tmp_diff;
tmp_qd = div;
}
}
pr_debug("A PLL/PMC: %s, best_rate = %ld, best_parent_rate = %lu (qd = %d)\n",
__func__, best_rate, *parent_rate, tmp_qd - 1);
return best_rate;
}
static int clk_audio_pll_frac_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_audio_frac *frac = to_clk_audio_frac(hw);
unsigned long fracr, nd;
int ret;
pr_debug("A PLL: %s, rate = %lu (parent_rate = %lu)\n", __func__, rate,
parent_rate);
if (rate < AUDIO_PLL_FOUT_MIN || rate > AUDIO_PLL_FOUT_MAX)
return -EINVAL;
ret = clk_audio_pll_frac_compute_frac(rate, parent_rate, &nd, &fracr);
if (ret)
return ret;
frac->nd = nd;
frac->fracr = fracr;
return 0;
}
static int clk_audio_pll_pad_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_audio_pad *apad_ck = to_clk_audio_pad(hw);
u8 tmp_div;
pr_debug("A PLL/PAD: %s, rate = %lu (parent_rate = %lu)\n", __func__,
rate, parent_rate);
if (!rate)
return -EINVAL;
tmp_div = parent_rate / rate;
if (tmp_div % 3 == 0) {
apad_ck->qdaudio = tmp_div / 3;
apad_ck->div = 3;
} else {
apad_ck->qdaudio = tmp_div / 2;
apad_ck->div = 2;
}
return 0;
}
static int clk_audio_pll_pmc_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);
if (!rate)
return -EINVAL;
pr_debug("A PLL/PMC: %s, rate = %lu (parent_rate = %lu)\n", __func__,
rate, parent_rate);
apmc_ck->qdpmc = parent_rate / rate - 1;
return 0;
}
static int of_sama5d2_clk_audio_pll_setup(struct device_node *np,
struct clk_init_data *init,
struct clk_hw *hw,
struct regmap **clk_audio_regmap)
{
struct regmap *regmap;
const char *parent_names[1];
int ret;
regmap = syscon_node_to_regmap(of_get_parent(np));
if (IS_ERR(regmap))
return PTR_ERR(regmap);
init->name = np->name;
of_clk_parent_fill(np, parent_names, 1);
init->parent_names = parent_names;
init->num_parents = 1;
hw->init = init;
*clk_audio_regmap = regmap;
ret = clk_hw_register(NULL, hw);
if (ret)
return ret;
return of_clk_add_hw_provider(np, of_clk_hw_simple_get, hw);
}
static void __init of_sama5d2_clk_audio_pll_frac_setup(struct device_node *np)
{
struct clk_audio_frac *frac_ck;
struct clk_init_data init = {};
frac_ck = kzalloc(sizeof(*frac_ck), GFP_KERNEL);
if (!frac_ck)
return;
init.ops = &audio_pll_frac_ops;
init.flags = CLK_SET_RATE_GATE;
if (of_sama5d2_clk_audio_pll_setup(np, &init, &frac_ck->hw,
&frac_ck->regmap))
kfree(frac_ck);
}
static void __init of_sama5d2_clk_audio_pll_pad_setup(struct device_node *np)
{
struct clk_audio_pad *apad_ck;
struct clk_init_data init = {};
apad_ck = kzalloc(sizeof(*apad_ck), GFP_KERNEL);
if (!apad_ck)
return;
init.ops = &audio_pll_pad_ops;
init.flags = CLK_SET_RATE_GATE | CLK_SET_PARENT_GATE |
CLK_SET_RATE_PARENT;
if (of_sama5d2_clk_audio_pll_setup(np, &init, &apad_ck->hw,
&apad_ck->regmap))
kfree(apad_ck);
}
static void __init of_sama5d2_clk_audio_pll_pmc_setup(struct device_node *np)
{
struct clk_audio_pad *apmc_ck;
struct clk_init_data init = {};
apmc_ck = kzalloc(sizeof(*apmc_ck), GFP_KERNEL);
if (!apmc_ck)
return;
init.ops = &audio_pll_pmc_ops;
init.flags = CLK_SET_RATE_GATE | CLK_SET_PARENT_GATE |
CLK_SET_RATE_PARENT;
if (of_sama5d2_clk_audio_pll_setup(np, &init, &apmc_ck->hw,
&apmc_ck->regmap))
kfree(apmc_ck);
}
