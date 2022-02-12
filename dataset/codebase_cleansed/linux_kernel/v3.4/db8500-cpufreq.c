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
if (prcmu_set_arm_opp(idx2opp[idx])) {
pr_err("db8500-cpufreq: Failed to set OPP level\n");
return -EINVAL;
}
for_each_cpu(freqs.cpu, policy->cpus)
cpufreq_notify_transition(&freqs, CPUFREQ_POSTCHANGE);
return 0;
}
static unsigned int db8500_cpufreq_getspeed(unsigned int cpu)
{
int i;
for (i = 0; prcmu_get_arm_opp() != idx2opp[i]; i++)
;
return freq_table[i].frequency;
}
static int __cpuinit db8500_cpufreq_init(struct cpufreq_policy *policy)
{
int i, res;
BUILD_BUG_ON(ARRAY_SIZE(idx2opp) + 1 != ARRAY_SIZE(freq_table));
if (prcmu_has_arm_maxopp())
freq_table[3].frequency = 1000000;
pr_info("db8500-cpufreq : Available frequencies:\n");
for (i = 0; freq_table[i].frequency != CPUFREQ_TABLE_END; i++)
pr_info(" %d Mhz\n", freq_table[i].frequency/1000);
res = cpufreq_frequency_table_cpuinfo(policy, freq_table);
if (!res)
cpufreq_frequency_table_get_attr(freq_table, policy->cpu);
else {
pr_err("db8500-cpufreq : Failed to read policy table\n");
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
static int __init db8500_cpufreq_register(void)
{
if (!cpu_is_u8500v20_or_later())
return -ENODEV;
pr_info("cpufreq for DB8500 started\n");
return cpufreq_register_driver(&db8500_cpufreq_driver);
}
