static int scpi_get_transition_latency(struct device *cpu_dev)
{
return scpi_ops->get_transition_latency(cpu_dev);
}
static int scpi_init_opp_table(const struct cpumask *cpumask)
{
int ret;
struct device *cpu_dev = get_cpu_device(cpumask_first(cpumask));
ret = scpi_ops->add_opps_to_device(cpu_dev);
if (ret) {
dev_warn(cpu_dev, "failed to add opps to the device\n");
return ret;
}
ret = dev_pm_opp_set_sharing_cpus(cpu_dev, cpumask);
if (ret)
dev_err(cpu_dev, "%s: failed to mark OPPs as shared: %d\n",
__func__, ret);
return ret;
}
static int scpi_cpufreq_probe(struct platform_device *pdev)
{
scpi_ops = get_scpi_ops();
if (!scpi_ops)
return -EIO;
return bL_cpufreq_register(&scpi_cpufreq_ops);
}
static int scpi_cpufreq_remove(struct platform_device *pdev)
{
bL_cpufreq_unregister(&scpi_cpufreq_ops);
scpi_ops = NULL;
return 0;
}
