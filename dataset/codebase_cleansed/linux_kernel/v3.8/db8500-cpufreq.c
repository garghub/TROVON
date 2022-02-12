static int db8500_cpufreq_verify_speed(struct cpufreq_policy *policy)
{
return cpufreq_frequency_table_verify(policy, freq_table);
}
static int db8500_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_freqs freqs;
unsigned int idx;
if (target_freq < policy->cpuinfo.min_freq)
target_freq = policy->cpuinfo.min_freq;
if (target_freq > policy->cpuinfo.max_freq)
target_freq = policy->cpuinfo.max_freq;
if (cpufreq_frequency_table_target
(policy, freq_table, target_freq, relation, &idx)) {
return -EINVAL;
}
freqs.old = policy->cur;
freqs.new = freq_table[idx].frequency;
if (freqs.old == freqs.new)
return 0;
for_each_cpu(freqs.cpu, policy->cpus)
cpufreq_notify_transition(&freqs, CPUFREQ_PRECHANGE);
if (clk_set_rate(armss_clk, freq_table[idx].frequency * 1000)) {
pr_err("db8500-cpufreq: Failed to update armss clk\n");
return -EINVAL;
}
for_each_cpu(freqs.cpu, policy->cpus)
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
return 0;
}
static unsigned int db8500_cpufreq_getspeed(unsigned int cpu)
{
int i = 0;
unsigned long freq = clk_get_rate(armss_clk) / 1000;
while (freq_table[i].frequency != CPUFREQ_TABLE_END) {
if (freq <= freq_table[i].frequency)
return freq_table[i].frequency;
i++;
}
pr_err("db8500-cpufreq: Failed to find cpufreq speed\n");
return 0;
}
static int __cpuinit db8500_cpufreq_init(struct cpufreq_policy *policy)
{
int i = 0;
int res;
armss_clk = clk_get(NULL, "armss");
if (IS_ERR(armss_clk)) {
pr_err("db8500-cpufreq : Failed to get armss clk\n");
return PTR_ERR(armss_clk);
}
pr_info("db8500-cpufreq : Available frequencies:\n");
while (freq_table[i].frequency != CPUFREQ_TABLE_END) {
pr_info(" %d Mhz\n", freq_table[i].frequency/1000);
i++;
}
res = cpufreq_frequency_table_cpuinfo(policy, freq_table);
if (!res)
cpufreq_frequency_table_get_attr(freq_table, policy->cpu);
else {
pr_err("db8500-cpufreq : Failed to read policy table\n");
clk_put(armss_clk);
return res;
}
policy->min = policy->cpuinfo.min_freq;
policy->max = policy->cpuinfo.max_freq;
policy->cur = db8500_cpufreq_getspeed(policy->cpu);
policy->governor = CPUFREQ_DEFAULT_GOVERNOR;
policy->cpuinfo.transition_latency = 20 * 1000;
cpumask_copy(policy->cpus, cpu_present_mask);
policy->shared_type = CPUFREQ_SHARED_TYPE_ALL;
return 0;
}
static int db8500_cpufreq_probe(struct platform_device *pdev)
{
freq_table = dev_get_platdata(&pdev->dev);
if (!freq_table) {
pr_err("db8500-cpufreq: Failed to fetch cpufreq table\n");
return -ENODEV;
}
return cpufreq_register_driver(&db8500_cpufreq_driver);
}
static int __init db8500_cpufreq_register(void)
{
if (!cpu_is_u8500_family())
return -ENODEV;
pr_info("cpufreq for DB8500 started\n");
return platform_driver_register(&db8500_cpufreq_plat_driver);
}
