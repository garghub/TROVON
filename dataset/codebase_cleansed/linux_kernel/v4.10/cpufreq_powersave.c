static void cpufreq_gov_powersave_limits(struct cpufreq_policy *policy)
{
pr_debug("setting to %u kHz\n", policy->min);
__cpufreq_driver_target(policy, policy->min, CPUFREQ_RELATION_L);
}
static int __init cpufreq_gov_powersave_init(void)
{
return cpufreq_register_governor(&cpufreq_gov_powersave);
}
static void __exit cpufreq_gov_powersave_exit(void)
{
cpufreq_unregister_governor(&cpufreq_gov_powersave);
}
struct cpufreq_governor *cpufreq_default_governor(void)
{
return &cpufreq_gov_powersave;
}
