static int cpufreq_set(struct cpufreq_policy *policy, unsigned int freq)
{
int ret = -EINVAL;
unsigned int *setspeed = policy->governor_data;
pr_debug("cpufreq_set for cpu %u, freq %u kHz\n", policy->cpu, freq);
mutex_lock(&userspace_mutex);
if (!per_cpu(cpu_is_managed, policy->cpu))
goto err;
*setspeed = freq;
ret = __cpufreq_driver_target(policy, freq, CPUFREQ_RELATION_L);
err:
mutex_unlock(&userspace_mutex);
return ret;
}
static ssize_t show_speed(struct cpufreq_policy *policy, char *buf)
{
return sprintf(buf, "%u\n", policy->cur);
}
static int cpufreq_userspace_policy_init(struct cpufreq_policy *policy)
{
unsigned int *setspeed;
setspeed = kzalloc(sizeof(*setspeed), GFP_KERNEL);
if (!setspeed)
return -ENOMEM;
policy->governor_data = setspeed;
return 0;
}
static int cpufreq_governor_userspace(struct cpufreq_policy *policy,
unsigned int event)
{
unsigned int *setspeed = policy->governor_data;
unsigned int cpu = policy->cpu;
int rc = 0;
if (event == CPUFREQ_GOV_POLICY_INIT)
return cpufreq_userspace_policy_init(policy);
if (!setspeed)
return -EINVAL;
switch (event) {
case CPUFREQ_GOV_POLICY_EXIT:
mutex_lock(&userspace_mutex);
policy->governor_data = NULL;
kfree(setspeed);
mutex_unlock(&userspace_mutex);
break;
case CPUFREQ_GOV_START:
BUG_ON(!policy->cur);
pr_debug("started managing cpu %u\n", cpu);
mutex_lock(&userspace_mutex);
per_cpu(cpu_is_managed, cpu) = 1;
*setspeed = policy->cur;
mutex_unlock(&userspace_mutex);
break;
case CPUFREQ_GOV_STOP:
pr_debug("managing cpu %u stopped\n", cpu);
mutex_lock(&userspace_mutex);
per_cpu(cpu_is_managed, cpu) = 0;
*setspeed = 0;
mutex_unlock(&userspace_mutex);
break;
case CPUFREQ_GOV_LIMITS:
mutex_lock(&userspace_mutex);
pr_debug("limit event for cpu %u: %u - %u kHz, currently %u kHz, last set to %u kHz\n",
cpu, policy->min, policy->max, policy->cur, *setspeed);
if (policy->max < *setspeed)
__cpufreq_driver_target(policy, policy->max,
CPUFREQ_RELATION_H);
else if (policy->min > *setspeed)
__cpufreq_driver_target(policy, policy->min,
CPUFREQ_RELATION_L);
else
__cpufreq_driver_target(policy, *setspeed,
CPUFREQ_RELATION_L);
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
struct cpufreq_governor *cpufreq_default_governor(void)
{
return &cpufreq_gov_userspace;
}
