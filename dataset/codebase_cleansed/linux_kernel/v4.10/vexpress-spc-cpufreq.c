static int ve_spc_init_opp_table(const struct cpumask *cpumask)
{
struct device *cpu_dev = get_cpu_device(cpumask_first(cpumask));
return dev_pm_opp_get_opp_count(cpu_dev) <= 0;
}
static int ve_spc_get_transition_latency(struct device *cpu_dev)
{
return 1000000;
}
static int ve_spc_cpufreq_probe(struct platform_device *pdev)
{
return bL_cpufreq_register(&ve_spc_cpufreq_ops);
}
static int ve_spc_cpufreq_remove(struct platform_device *pdev)
{
bL_cpufreq_unregister(&ve_spc_cpufreq_ops);
return 0;
}
