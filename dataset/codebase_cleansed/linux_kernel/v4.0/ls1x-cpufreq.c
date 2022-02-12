static int ls1x_cpufreq_notifier(struct notifier_block *nb,
unsigned long val, void *data)
{
if (val == CPUFREQ_POSTCHANGE)
current_cpu_data.udelay_val = loops_per_jiffy;
return NOTIFY_OK;
}
static int ls1x_cpufreq_target(struct cpufreq_policy *policy,
unsigned int index)
{
unsigned int old_freq, new_freq;
old_freq = policy->cur;
new_freq = policy->freq_table[index].frequency;
dev_dbg(ls1x_cpufreq.dev, "%u KHz --> %u KHz\n", old_freq, new_freq);
clk_set_parent(policy->clk, ls1x_cpufreq.osc_clk);
__raw_writel(__raw_readl(LS1X_CLK_PLL_DIV) | RST_CPU_EN | RST_CPU,
LS1X_CLK_PLL_DIV);
__raw_writel(__raw_readl(LS1X_CLK_PLL_DIV) & ~(RST_CPU_EN | RST_CPU),
LS1X_CLK_PLL_DIV);
clk_set_rate(ls1x_cpufreq.mux_clk, new_freq * 1000);
clk_set_parent(policy->clk, ls1x_cpufreq.mux_clk);
return 0;
}
static int ls1x_cpufreq_init(struct cpufreq_policy *policy)
{
struct cpufreq_frequency_table *freq_tbl;
unsigned int pll_freq, freq;
int steps, i, ret;
pll_freq = clk_get_rate(ls1x_cpufreq.pll_clk) / 1000;
steps = 1 << DIV_CPU_WIDTH;
freq_tbl = kzalloc(sizeof(*freq_tbl) * steps, GFP_KERNEL);
if (!freq_tbl) {
dev_err(ls1x_cpufreq.dev,
"failed to alloc cpufreq_frequency_table\n");
ret = -ENOMEM;
goto out;
}
for (i = 0; i < (steps - 1); i++) {
freq = pll_freq / (i + 1);
if ((freq < ls1x_cpufreq.min_freq) ||
(freq > ls1x_cpufreq.max_freq))
freq_tbl[i].frequency = CPUFREQ_ENTRY_INVALID;
else
freq_tbl[i].frequency = freq;
dev_dbg(ls1x_cpufreq.dev,
"cpufreq table: index %d: frequency %d\n", i,
freq_tbl[i].frequency);
}
freq_tbl[i].frequency = CPUFREQ_TABLE_END;
policy->clk = ls1x_cpufreq.clk;
ret = cpufreq_generic_init(policy, freq_tbl, 0);
if (ret)
kfree(freq_tbl);
out:
return ret;
}
static int ls1x_cpufreq_exit(struct cpufreq_policy *policy)
{
kfree(policy->freq_table);
return 0;
}
static int ls1x_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_unregister_notifier(&ls1x_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
cpufreq_unregister_driver(&ls1x_cpufreq_driver);
return 0;
}
static int ls1x_cpufreq_probe(struct platform_device *pdev)
{
struct plat_ls1x_cpufreq *pdata = pdev->dev.platform_data;
struct clk *clk;
int ret;
if (!pdata || !pdata->clk_name || !pdata->osc_clk_name)
return -EINVAL;
ls1x_cpufreq.dev = &pdev->dev;
clk = devm_clk_get(&pdev->dev, pdata->clk_name);
if (IS_ERR(clk)) {
dev_err(ls1x_cpufreq.dev, "unable to get %s clock\n",
pdata->clk_name);
ret = PTR_ERR(clk);
goto out;
}
ls1x_cpufreq.clk = clk;
clk = clk_get_parent(clk);
if (IS_ERR(clk)) {
dev_err(ls1x_cpufreq.dev, "unable to get parent of %s clock\n",
__clk_get_name(ls1x_cpufreq.clk));
ret = PTR_ERR(clk);
goto out;
}
ls1x_cpufreq.mux_clk = clk;
clk = clk_get_parent(clk);
if (IS_ERR(clk)) {
dev_err(ls1x_cpufreq.dev, "unable to get parent of %s clock\n",
__clk_get_name(ls1x_cpufreq.mux_clk));
ret = PTR_ERR(clk);
goto out;
}
ls1x_cpufreq.pll_clk = clk;
clk = devm_clk_get(&pdev->dev, pdata->osc_clk_name);
if (IS_ERR(clk)) {
dev_err(ls1x_cpufreq.dev, "unable to get %s clock\n",
pdata->osc_clk_name);
ret = PTR_ERR(clk);
goto out;
}
ls1x_cpufreq.osc_clk = clk;
ls1x_cpufreq.max_freq = pdata->max_freq;
ls1x_cpufreq.min_freq = pdata->min_freq;
ret = cpufreq_register_driver(&ls1x_cpufreq_driver);
if (ret) {
dev_err(ls1x_cpufreq.dev,
"failed to register cpufreq driver: %d\n", ret);
goto out;
}
ret = cpufreq_register_notifier(&ls1x_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
if (!ret)
goto out;
dev_err(ls1x_cpufreq.dev, "failed to register cpufreq notifier: %d\n",
ret);
cpufreq_unregister_driver(&ls1x_cpufreq_driver);
out:
return ret;
}
