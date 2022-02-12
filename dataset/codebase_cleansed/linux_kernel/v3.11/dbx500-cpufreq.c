static int dbx500_cpufreq_verify_speed(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, freq_table);
}
static int dbx500_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_freqs freqs;
unsigned int idx;
int ret;
if (cpufreq_frequency_table_target(policy, freq_table, target_freq,
relation, &idx))
return -EINVAL;
freqs.old = policy->cur;
freqs.new = freq_table[idx].frequency;
if (freqs.old == freqs.new)
return 0;
cpufreq_notify_transition(policy, &freqs, CPUFREQ_PRECHANGE);
ret = clk_set_rate(armss_clk, freqs.new * 1000);
if (ret) {
pr_err("dbx500-cpufreq: Failed to set armss_clk to %d Hz: error %d\n",
freqs.new * 1000, ret);
freqs.new = freqs.old;
}
cpufreq_notify_transition(policy, &freqs, CPUFREQ_POSTCHANGE);
return ret;
}
static unsigned int dbx500_cpufreq_getspeed(unsigned int cpu)
{
int i = 0;
unsigned long freq = clk_get_rate(armss_clk) / 1000;
while (freq_table[i + 1].frequency != CPUFREQ_TABLE_END) {
if (freq < freq_table[i].frequency +
(freq_table[i + 1].frequency - freq_table[i].frequency) / 2)
return freq_table[i].frequency;
i++;
}
return freq_table[i].frequency;
}
static int dbx500_cpufreq_init(struct cpufreq_policy *policy)
{
int res;
res = cpufreq_frequency_table_cpuinfo(policy, freq_table);
if (!res)
cpufreq_frequency_table_get_attr(freq_table, policy->cpu);
else {
pr_err("dbx500-cpufreq: Failed to read policy table\n");
return res;
}
policy->min = policy->cpuinfo.min_freq;
policy->max = policy->cpuinfo.max_freq;
policy->cur = dbx500_cpufreq_getspeed(policy->cpu);
policy->governor = CPUFREQ_DEFAULT_GOVERNOR;
policy->cpuinfo.transition_latency = 20 * 1000;
cpumask_setall(policy->cpus);
return 0;
}
static int dbx500_cpufreq_probe(struct platform_device *pdev)
{
int i = 0;
freq_table = dev_get_platdata(&pdev->dev);
if (!freq_table) {
pr_err("dbx500-cpufreq: Failed to fetch cpufreq table\n");
return -ENODEV;
}
armss_clk = clk_get(&pdev->dev, "armss");
if (IS_ERR(armss_clk)) {
pr_err("dbx500-cpufreq: Failed to get armss clk\n");
return PTR_ERR(armss_clk);
}
pr_info("dbx500-cpufreq: Available frequencies:\n");
while (freq_table[i].frequency != CPUFREQ_TABLE_END) {
pr_info(" %d Mhz\n", freq_table[i].frequency/1000);
i++;
}
return cpufreq_register_driver(&dbx500_cpufreq_driver);
}
static int __init dbx500_cpufreq_register(void)
{
return platform_driver_register(&dbx500_cpufreq_plat_driver);
}
