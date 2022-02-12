static int davinci_verify_speed(struct cpufreq_policy *policy)
{
struct davinci_cpufreq_config *pdata = cpufreq.dev->platform_data;
struct cpufreq_frequency_table *freq_table = pdata->freq_table;
struct clk *armclk = cpufreq.armclk;
if (freq_table)
return cpufreq_frequency_table_verify(policy, freq_table);
if (policy->cpu)
return -EINVAL;
cpufreq_verify_within_limits(policy, policy->cpuinfo.min_freq,
policy->cpuinfo.max_freq);
policy->min = clk_round_rate(armclk, policy->min * 1000) / 1000;
policy->max = clk_round_rate(armclk, policy->max * 1000) / 1000;
cpufreq_verify_within_limits(policy, policy->cpuinfo.min_freq,
policy->cpuinfo.max_freq);
return 0;
}
static unsigned int davinci_getspeed(unsigned int cpu)
{
if (cpu)
return 0;
return clk_get_rate(cpufreq.armclk) / 1000;
}
static int davinci_target(struct cpufreq_policy *policy,
unsigned int target_freq, unsigned int relation)
{
int ret = 0;
unsigned int idx;
struct cpufreq_freqs freqs;
struct davinci_cpufreq_config *pdata = cpufreq.dev->platform_data;
struct clk *armclk = cpufreq.armclk;
freqs.old = davinci_getspeed(0);
freqs.new = clk_round_rate(armclk, target_freq * 1000) / 1000;
if (freqs.old == freqs.new)
return ret;
dev_dbg(cpufreq.dev, "transition: %u --> %u\n", freqs.old, freqs.new);
ret = cpufreq_frequency_table_target(policy, pdata->freq_table,
freqs.new, relation, &idx);
if (ret)
return -EINVAL;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
if (pdata->set_voltage && freqs.new > freqs.old) {
ret = pdata->set_voltage(idx);
if (ret)
goto out;
}
ret = clk_set_rate(armclk, idx);
if (ret)
goto out;
if (cpufreq.asyncclk) {
ret = clk_set_rate(cpufreq.asyncclk, cpufreq.asyncrate);
if (ret)
goto out;
}
if (pdata->set_voltage && freqs.new < freqs.old)
pdata->set_voltage(idx);
out:
if (ret)
freqs.new = freqs.old;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
return ret;
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
policy->cur = davinci_getspeed(0);
result = cpufreq_frequency_table_cpuinfo(policy, freq_table);
if (result) {
pr_err("%s: cpufreq_frequency_table_cpuinfo() failed",
__func__);
return result;
}
cpufreq_frequency_table_get_attr(freq_table, policy->cpu);
policy->cpuinfo.transition_latency = 2000 * 1000;
return 0;
}
static int davinci_cpu_exit(struct cpufreq_policy *policy)
{
cpufreq_frequency_table_put_attr(policy->cpu);
return 0;
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
