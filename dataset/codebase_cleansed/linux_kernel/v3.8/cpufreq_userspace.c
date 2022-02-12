static int
userspace_cpufreq_notifier(struct notifier_block *nb, unsigned long val,
void *data)
{
struct cpufreq_freqs *freq = data;
if (!per_cpu(cpu_is_managed, freq->cpu))
return 0;
if (val == CPUFREQ_POSTCHANGE) {
pr_debug("saving cpu_cur_freq of cpu %u to be %u kHz\n",
freq->cpu, freq->new);
per_cpu(cpu_cur_freq, freq->cpu) = freq->new;
}
return 0;
}
static int cpufreq_set(struct cpufreq_policy *policy, unsigned int freq)
{
int ret = -EINVAL;
pr_debug("cpufreq_set for cpu %u, freq %u kHz\n", policy->cpu, freq);
mutex_lock(&userspace_mutex);
if (!per_cpu(cpu_is_managed, policy->cpu))
goto err;
per_cpu(cpu_set_freq, policy->cpu) = freq;
if (freq < per_cpu(cpu_min_freq, policy->cpu))
freq = per_cpu(cpu_min_freq, policy->cpu);
if (freq > per_cpu(cpu_max_freq, policy->cpu))
freq = per_cpu(cpu_max_freq, policy->cpu);
ret = __cpufreq_driver_target(policy, freq, CPUFREQ_RELATION_L);
err:
mutex_unlock(&userspace_mutex);
return ret;
}
static ssize_t show_speed(struct cpufreq_policy *policy, char *buf)
{
return sprintf(buf, "%u\n", per_cpu(cpu_cur_freq, policy->cpu));
}
static int cpufreq_governor_userspace(struct cpufreq_policy *policy,
unsigned int event)
{
unsigned int cpu = policy->cpu;
int rc = 0;
switch (event) {
case CPUFREQ_GOV_START:
if (!cpu_online(cpu))
return -EINVAL;
BUG_ON(!policy->cur);
mutex_lock(&userspace_mutex);
if (cpus_using_userspace_governor == 0) {
cpufreq_register_notifier(
&userspace_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
cpus_using_userspace_governor++;
per_cpu(cpu_is_managed, cpu) = 1;
per_cpu(cpu_min_freq, cpu) = policy->min;
per_cpu(cpu_max_freq, cpu) = policy->max;
per_cpu(cpu_cur_freq, cpu) = policy->cur;
per_cpu(cpu_set_freq, cpu) = policy->cur;
pr_debug("managing cpu %u started "
"(%u - %u kHz, currently %u kHz)\n",
cpu,
per_cpu(cpu_min_freq, cpu),
per_cpu(cpu_max_freq, cpu),
per_cpu(cpu_cur_freq, cpu));
mutex_unlock(&userspace_mutex);
break;
case CPUFREQ_GOV_STOP:
mutex_lock(&userspace_mutex);
cpus_using_userspace_governor--;
if (cpus_using_userspace_governor == 0) {
cpufreq_unregister_notifier(
&userspace_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
per_cpu(cpu_is_managed, cpu) = 0;
per_cpu(cpu_min_freq, cpu) = 0;
per_cpu(cpu_max_freq, cpu) = 0;
per_cpu(cpu_set_freq, cpu) = 0;
pr_debug("managing cpu %u stopped\n", cpu);
mutex_unlock(&userspace_mutex);
break;
case CPUFREQ_GOV_LIMITS:
mutex_lock(&userspace_mutex);
pr_debug("limit event for cpu %u: %u - %u kHz, "
"currently %u kHz, last set to %u kHz\n",
cpu, policy->min, policy->max,
per_cpu(cpu_cur_freq, cpu),
per_cpu(cpu_set_freq, cpu));
if (policy->max < per_cpu(cpu_set_freq, cpu)) {
__cpufreq_driver_target(policy, policy->max,
CPUFREQ_RELATION_H);
} else if (policy->min > per_cpu(cpu_set_freq, cpu)) {
__cpufreq_driver_target(policy, policy->min,
CPUFREQ_RELATION_L);
} else {
__cpufreq_driver_target(policy,
per_cpu(cpu_set_freq, cpu),
CPUFREQ_RELATION_L);
}
per_cpu(cpu_min_freq, cpu) = policy->min;
per_cpu(cpu_max_freq, cpu) = policy->max;
per_cpu(cpu_cur_freq, cpu) = policy->cur;
mutex_unlock(&userspace_mutex);
break;
}
return rc;
}
static int __init cpufreq_gov_userspace_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_userspace);
}
static void __exit cpufreq_gov_userspace_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_userspace);
}
