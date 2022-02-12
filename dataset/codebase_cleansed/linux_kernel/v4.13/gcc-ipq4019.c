static u64 clk_fepll_vco_calc_rate(struct clk_fepll *pll_div,
unsigned long parent_rate)
{
const struct clk_fepll_vco *pll_vco = pll_div->pll_vco;
u32 fdbkdiv, refclkdiv, cdiv;
u64 vco;
regmap_read(pll_div->cdiv.clkr.regmap, pll_vco->reg, &cdiv);
refclkdiv = (cdiv >> pll_vco->refclkdiv_shift) &
(BIT(pll_vco->refclkdiv_width) - 1);
fdbkdiv = (cdiv >> pll_vco->fdbkdiv_shift) &
(BIT(pll_vco->fdbkdiv_width) - 1);
vco = parent_rate / refclkdiv;
vco *= 2;
vco *= fdbkdiv;
return vco;
}
static long clk_cpu_div_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *p_rate)
{
struct clk_fepll *pll = to_clk_fepll(hw);
struct clk_hw *p_hw;
const struct freq_tbl *f;
f = qcom_find_freq(pll->freq_tbl, rate);
if (!f)
return -EINVAL;
p_hw = clk_hw_get_parent_by_index(hw, f->src);
*p_rate = clk_hw_get_rate(p_hw);
return f->freq;
}
static int clk_cpu_div_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_fepll *pll = to_clk_fepll(hw);
const struct freq_tbl *f;
u32 mask;
int ret;
f = qcom_find_freq(pll->freq_tbl, rate);
if (!f)
return -EINVAL;
mask = (BIT(pll->cdiv.width) - 1) << pll->cdiv.shift;
ret = regmap_update_bits(pll->cdiv.clkr.regmap,
pll->cdiv.reg, mask,
f->pre_div << pll->cdiv.shift);
udelay(1);
return 0;
}
static unsigned long
clk_cpu_div_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_fepll *pll = to_clk_fepll(hw);
u32 cdiv, pre_div;
u64 rate;
regmap_read(pll->cdiv.clkr.regmap, pll->cdiv.reg, &cdiv);
cdiv = (cdiv >> pll->cdiv.shift) & (BIT(pll->cdiv.width) - 1);
if (cdiv > 10)
pre_div = (cdiv + 1) * 2;
else
pre_div = cdiv + 12;
rate = clk_fepll_vco_calc_rate(pll, parent_rate) * 2;
do_div(rate, pre_div);
return rate;
}
static unsigned long
clk_regmap_clk_div_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_fepll *pll = to_clk_fepll(hw);
u32 cdiv, pre_div = 1;
u64 rate;
const struct clk_div_table *clkt;
if (pll->fixed_div) {
pre_div = pll->fixed_div;
} else {
regmap_read(pll->cdiv.clkr.regmap, pll->cdiv.reg, &cdiv);
cdiv = (cdiv >> pll->cdiv.shift) & (BIT(pll->cdiv.width) - 1);
for (clkt = pll->div_table; clkt->div; clkt++) {
if (clkt->val == cdiv)
pre_div = clkt->div;
}
}
rate = clk_fepll_vco_calc_rate(pll, parent_rate);
do_div(rate, pre_div);
return rate;
}
static int
gcc_ipq4019_cpu_clk_notifier_fn(struct notifier_block *nb,
unsigned long action, void *data)
{
int err = 0;
if (action == PRE_RATE_CHANGE)
err = clk_rcg2_ops.set_parent(&apps_clk_src.clkr.hw,
gcc_ipq4019_cpu_safe_parent);
return notifier_from_errno(err);
}
static int gcc_ipq4019_probe(struct platform_device *pdev)
{
int err;
err = qcom_cc_probe(pdev, &gcc_ipq4019_desc);
if (err)
return err;
return clk_notifier_register(apps_clk_src.clkr.hw.clk,
&gcc_ipq4019_cpu_clk_notifier);
}
static int gcc_ipq4019_remove(struct platform_device *pdev)
{
return clk_notifier_unregister(apps_clk_src.clkr.hw.clk,
&gcc_ipq4019_cpu_clk_notifier);
}
static int __init gcc_ipq4019_init(void)
{
return platform_driver_register(&gcc_ipq4019_driver);
}
static void __exit gcc_ipq4019_exit(void)
{
platform_driver_unregister(&gcc_ipq4019_driver);
}
