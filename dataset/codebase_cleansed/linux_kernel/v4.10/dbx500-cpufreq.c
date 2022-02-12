static int dbx500_cpufreq_target(struct cpufreq_policy *policy,
unsigned int index)
{
return clk_set_rate(armss_clk, freq_table[index].frequency * 1000);
}
static int dbx500_cpufreq_init(struct cpufreq_policy *policy)
{
policy->clk = armss_clk;
return cpufreq_generic_init(policy, freq_table, 20 * 1000);
}
static int dbx500_cpufreq_probe(struct platform_device *pdev)
{
struct cpufreq_frequency_table *pos;
freq_table = dev_get_platdata(&pdev->dev);
if (!freq_table) {
pr_err("dbx500-cpufreq: Failed to fetch cpufreq table\n");
return -ENODEV;
}
armss_clk = clk_get(&pdev->dev, "armss");
if (IS_ERR(armss_clk)) {
pr_err("dbx500-cpufreq: Failed to get armss clk\n");
return PTR_ERR(armss_clk);
}
pr_info("dbx500-cpufreq: Available frequencies:\n");
cpufreq_for_each_entry(pos, freq_table)
pr_info(" %d Mhz\n", pos->frequency / 1000);
return cpufreq_register_driver(&dbx500_cpufreq_driver);
}
static int __init dbx500_cpufreq_register(void)
{
return platform_driver_register(&dbx500_cpufreq_plat_driver);
}
