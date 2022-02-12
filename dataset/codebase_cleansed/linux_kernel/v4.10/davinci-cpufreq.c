static int davinci_target(struct cpufreq_policy *policy, unsigned int idx)
{
struct davinci_cpufreq_config *pdata = cpufreq.dev->platform_data;
struct clk *armclk = cpufreq.armclk;
unsigned int old_freq, new_freq;
int ret = 0;
old_freq = policy->cur;
new_freq = pdata->freq_table[idx].frequency;
if (pdata->set_voltage && new_freq > old_freq) {
ret = pdata->set_voltage(idx);
if (ret)
return ret;
}
ret = clk_set_rate(armclk, idx);
if (ret)
return ret;
if (cpufreq.asyncclk) {
ret = clk_set_rate(cpufreq.asyncclk, cpufreq.asyncrate);
if (ret)
return ret;
}
if (pdata->set_voltage && new_freq < old_freq)
pdata->set_voltage(idx);
return 0;
}
static int davinci_cpu_init(struct cpufreq_policy *policy)
{
int result = 0;
struct davinci_cpufreq_config *pdata = cpufreq.dev->platform_data;
struct cpufreq_frequency_table *freq_table = pdata->freq_table;
if (policy->cpu != 0)
return -EINVAL;
if (pdata->init) {
result = pdata->init();
if (result)
return result;
}
policy->clk = cpufreq.armclk;
return cpufreq_generic_init(policy, freq_table, 2000 * 1000);
}
static int __init davinci_cpufreq_probe(struct platform_device *pdev)
{
struct davinci_cpufreq_config *pdata = pdev->dev.platform_data;
struct clk *asyncclk;
if (!pdata)
return -EINVAL;
if (!pdata->freq_table)
return -EINVAL;
cpufreq.dev = &pdev->dev;
cpufreq.armclk = clk_get(NULL, "arm");
if (IS_ERR(cpufreq.armclk)) {
dev_err(cpufreq.dev, "Unable to get ARM clock\n");
return PTR_ERR(cpufreq.armclk);
}
asyncclk = clk_get(cpufreq.dev, "async");
if (!IS_ERR(asyncclk)) {
cpufreq.asyncclk = asyncclk;
cpufreq.asyncrate = clk_get_rate(asyncclk);
}
return cpufreq_register_driver(&davinci_driver);
}
static int __exit davinci_cpufreq_remove(struct platform_device *pdev)
{
clk_put(cpufreq.armclk);
if (cpufreq.asyncclk)
clk_put(cpufreq.asyncclk);
return cpufreq_unregister_driver(&davinci_driver);
}
int __init davinci_cpufreq_init(void)
{
return platform_driver_probe(&davinci_cpufreq_driver,
davinci_cpufreq_probe);
}
