static int __init tango_cpufreq_init(void)
{
struct device *cpu_dev = get_cpu_device(0);
unsigned long max_freq;
struct clk *cpu_clk;
void *res;
if (!of_match_node(machines, of_root))
return -ENODEV;
cpu_clk = clk_get(cpu_dev, NULL);
if (IS_ERR(cpu_clk))
return -ENODEV;
max_freq = clk_get_rate(cpu_clk);
dev_pm_opp_add(cpu_dev, max_freq / 1, 0);
dev_pm_opp_add(cpu_dev, max_freq / 2, 0);
dev_pm_opp_add(cpu_dev, max_freq / 3, 0);
dev_pm_opp_add(cpu_dev, max_freq / 5, 0);
dev_pm_opp_add(cpu_dev, max_freq / 9, 0);
res = platform_device_register_data(NULL, "cpufreq-dt", -1, NULL, 0);
return PTR_ERR_OR_ZERO(res);
}
