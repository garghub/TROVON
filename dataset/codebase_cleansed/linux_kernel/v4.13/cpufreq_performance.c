static void cpufreq_gov_performance_limits(struct cpufreq_policy *policy)
{
pr_debug("setting to %u kHz\n", policy->max);
__cpufreq_driver_target(policy, policy->max, CPUFREQ_RELATION_H);
}
static int __init cpufreq_gov_performance_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_performance);
}
static void __exit cpufreq_gov_performance_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_performance);
}
struct cpufreq_governor *cpufreq_default_governor(void)
{
return &cpufreq_gov_performance;
}
struct cpufreq_governor *cpufreq_fallback_governor(void)
{
return &cpufreq_gov_performance;
}
