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
struct device *cpu_dev = get_cpu_device(policy->cpu);
unsigned int old_freq, new_freq;
old_freq = policy->cur;
new_freq = policy->freq_table[index].frequency;
clk_set_parent(policy->clk, cpufreq->osc_clk);
__raw_writel(__raw_readl(LS1X_CLK_PLL_DIV) | RST_CPU_EN | RST_CPU,
LS1X_CLK_PLL_DIV);
__raw_writel(__raw_readl(LS1X_CLK_PLL_DIV) & ~(RST_CPU_EN | RST_CPU),
LS1X_CLK_PLL_DIV);
clk_set_rate(cpufreq->mux_clk, new_freq * 1000);
clk_set_parent(policy->clk, cpufreq->mux_clk);
dev_dbg(cpu_dev, "%u KHz --> %u KHz\n", old_freq, new_freq);
return 0;
}
static int ls1x_cpufreq_init(struct cpufreq_policy *policy)
{
struct device *cpu_dev = get_cpu_device(policy->cpu);
struct cpufreq_frequency_table *freq_tbl;
unsigned int pll_freq, freq;
int steps, i, ret;
pll_freq = clk_get_rate(cpufreq->pll_clk) / 1000;
steps = 1 << DIV_CPU_WIDTH;
freq_tbl = kcalloc(steps, sizeof(*freq_tbl), GFP_KERNEL);
if (!freq_tbl)
return -ENOMEM;
for (i = 0; i < (steps - 1); i++) {
freq = pll_freq / (i + 1);
if ((freq < cpufreq->min_freq) || (freq > cpufreq->max_freq))
freq_tbl[i].frequency = CPUFREQ_ENTRY_INVALID;
else
freq_tbl[i].frequency = freq;
dev_dbg(cpu_dev,
"cpufreq table: index %d: frequency %d\n", i,
freq_tbl[i].frequency);
}
freq_tbl[i].frequency = CPUFREQ_TABLE_END;
policy->clk = cpufreq->clk;
ret = cpufreq_generic_init(policy, freq_tbl, 0);
if (ret)
kfree(freq_tbl);
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
struct plat_ls1x_cpufreq *pdata = dev_get_platdata(&pdev->dev);
struct clk *clk;
int ret;
if (!pdata || !pdata->clk_name || !pdata->osc_clk_name) {
dev_err(&pdev->dev, "platform data missing\n");
return -EINVAL;
}
cpufreq =
devm_kzalloc(&pdev->dev, sizeof(struct ls1x_cpufreq), GFP_KERNEL);
if (!cpufreq)
return -ENOMEM;
cpufreq->dev = &pdev->dev;
clk = devm_clk_get(&pdev->dev, pdata->clk_name);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to get %s clock\n",
pdata->clk_name);
return PTR_ERR(clk);
}
cpufreq->clk = clk;
clk = clk_get_parent(clk);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to get parent of %s clock\n",
__clk_get_name(cpufreq->clk));
return PTR_ERR(clk);
}
cpufreq->mux_clk = clk;
clk = clk_get_parent(clk);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to get parent of %s clock\n",
__clk_get_name(cpufreq->mux_clk));
return PTR_ERR(clk);
}
cpufreq->pll_clk = clk;
clk = devm_clk_get(&pdev->dev, pdata->osc_clk_name);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to get %s clock\n",
pdata->osc_clk_name);
return PTR_ERR(clk);
}
cpufreq->osc_clk = clk;
cpufreq->max_freq = pdata->max_freq;
cpufreq->min_freq = pdata->min_freq;
ret = cpufreq_register_driver(&ls1x_cpufreq_driver);
if (ret) {
dev_err(&pdev->dev,
"failed to register CPUFreq driver: %d\n", ret);
return ret;
}
ret = cpufreq_register_notifier(&ls1x_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
if (ret) {
dev_err(&pdev->dev,
"failed to register CPUFreq notifier: %d\n",ret);
cpufreq_unregister_driver(&ls1x_cpufreq_driver);
}
return ret;
}
