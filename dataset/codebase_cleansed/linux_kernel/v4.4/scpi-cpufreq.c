static struct scpi_dvfs_info *scpi_get_dvfs_info(struct device *cpu_dev)
{
int domain = topology_physical_package_id(cpu_dev->id);
if (domain < 0)
return ERR_PTR(-EINVAL);
return scpi_ops->dvfs_get_info(domain);
}
static int scpi_opp_table_ops(struct device *cpu_dev, bool remove)
{
int idx, ret = 0;
struct scpi_opp *opp;
struct scpi_dvfs_info *info = scpi_get_dvfs_info(cpu_dev);
if (IS_ERR(info))
return PTR_ERR(info);
if (!info->opps)
return -EIO;
for (opp = info->opps, idx = 0; idx < info->count; idx++, opp++) {
if (remove)
dev_pm_opp_remove(cpu_dev, opp->freq);
else
ret = dev_pm_opp_add(cpu_dev, opp->freq,
opp->m_volt * 1000);
if (ret) {
dev_warn(cpu_dev, "failed to add opp %uHz %umV\n",
opp->freq, opp->m_volt);
while (idx-- > 0)
dev_pm_opp_remove(cpu_dev, (--opp)->freq);
return ret;
}
}
return ret;
}
static int scpi_get_transition_latency(struct device *cpu_dev)
{
struct scpi_dvfs_info *info = scpi_get_dvfs_info(cpu_dev);
if (IS_ERR(info))
return PTR_ERR(info);
return info->latency;
}
static int scpi_init_opp_table(struct device *cpu_dev)
{
return scpi_opp_table_ops(cpu_dev, false);
}
static void scpi_free_opp_table(struct device *cpu_dev)
{
scpi_opp_table_ops(cpu_dev, true);
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
