static int cppc_cpufreq_set_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpudata *cpu;
struct cpufreq_freqs freqs;
int ret = 0;
cpu = all_cpu_data[policy->cpu];
cpu->perf_ctrls.desired_perf = target_freq;
freqs.old = policy->cur;
freqs.new = target_freq;
cpufreq_freq_transition_begin(policy, &freqs);
ret = cppc_set_perf(cpu->cpu, &cpu->perf_ctrls);
cpufreq_freq_transition_end(policy, &freqs, ret != 0);
if (ret)
pr_debug("Failed to set target on CPU:%d. ret:%d\n",
cpu->cpu, ret);
return ret;
}
static int cppc_verify_policy(struct cpufreq_policy *policy)
{
cpufreq_verify_within_cpu_limits(policy);
return 0;
}
static void cppc_cpufreq_stop_cpu(struct cpufreq_policy *policy)
{
int cpu_num = policy->cpu;
struct cpudata *cpu = all_cpu_data[cpu_num];
int ret;
cpu->perf_ctrls.desired_perf = cpu->perf_caps.lowest_perf;
ret = cppc_set_perf(cpu_num, &cpu->perf_ctrls);
if (ret)
pr_debug("Err setting perf value:%d on CPU:%d. ret:%d\n",
cpu->perf_caps.lowest_perf, cpu_num, ret);
}
static int cppc_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
struct cpudata *cpu;
unsigned int cpu_num = policy->cpu;
int ret = 0;
cpu = all_cpu_data[policy->cpu];
cpu->cpu = cpu_num;
ret = cppc_get_perf_caps(policy->cpu, &cpu->perf_caps);
if (ret) {
pr_debug("Err reading CPU%d perf capabilities. ret:%d\n",
cpu_num, ret);
return ret;
}
policy->min = cpu->perf_caps.lowest_perf;
policy->max = cpu->perf_caps.highest_perf;
policy->cpuinfo.min_freq = policy->min;
policy->cpuinfo.max_freq = policy->max;
policy->shared_type = cpu->shared_type;
if (policy->shared_type == CPUFREQ_SHARED_TYPE_ANY)
cpumask_copy(policy->cpus, cpu->shared_cpu_map);
else if (policy->shared_type == CPUFREQ_SHARED_TYPE_ALL) {
pr_debug("Unsupported CPU co-ord type\n");
return -EFAULT;
}
cpumask_set_cpu(policy->cpu, policy->cpus);
cpu->cur_policy = policy;
policy->cur = cpu->perf_ctrls.desired_perf = cpu->perf_caps.highest_perf;
ret = cppc_set_perf(cpu_num, &cpu->perf_ctrls);
if (ret)
pr_debug("Err setting perf value:%d on CPU:%d. ret:%d\n",
cpu->perf_caps.highest_perf, cpu_num, ret);
return ret;
}
static int __init cppc_cpufreq_init(void)
{
int i, ret = 0;
struct cpudata *cpu;
if (acpi_disabled)
return -ENODEV;
all_cpu_data = kzalloc(sizeof(void *) * num_possible_cpus(), GFP_KERNEL);
if (!all_cpu_data)
return -ENOMEM;
for_each_possible_cpu(i) {
all_cpu_data[i] = kzalloc(sizeof(struct cpudata), GFP_KERNEL);
if (!all_cpu_data[i])
goto out;
cpu = all_cpu_data[i];
if (!zalloc_cpumask_var(&cpu->shared_cpu_map, GFP_KERNEL))
goto out;
}
ret = acpi_get_psd_map(all_cpu_data);
if (ret) {
pr_debug("Error parsing PSD data. Aborting cpufreq registration.\n");
goto out;
}
ret = cpufreq_register_driver(&cppc_cpufreq_driver);
if (ret)
goto out;
return ret;
out:
for_each_possible_cpu(i)
kfree(all_cpu_data[i]);
kfree(all_cpu_data);
return -ENODEV;
}
static void __exit cppc_cpufreq_exit(void)
{
struct cpudata *cpu;
int i;
cpufreq_unregister_driver(&cppc_cpufreq_driver);
for_each_possible_cpu(i) {
cpu = all_cpu_data[i];
free_cpumask_var(cpu->shared_cpu_map);
kfree(cpu);
}
kfree(all_cpu_data);
}
