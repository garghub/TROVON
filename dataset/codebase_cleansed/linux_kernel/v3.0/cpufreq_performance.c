static int cpufreq_governor_performance(struct cpufreq_policy *policy,
unsigned int event)
{
switch (event) {
case CPUFREQ_GOV_START:
case CPUFREQ_GOV_LIMITS:
pr_debug("setting to %u kHz because of event %u\n",
policy->max, event);
__cpufreq_driver_target(policy, policy->max,
CPUFREQ_RELATION_H);
break;
default:
break;
}
return 0;
}
static int __init cpufreq_gov_performance_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_performance);
}
static void __exit cpufreq_gov_performance_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_performance);
}
