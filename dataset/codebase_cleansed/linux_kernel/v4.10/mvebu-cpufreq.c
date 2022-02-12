static int __init armada_xp_pmsu_cpufreq_init(void)
{
struct device_node *np;
struct resource res;
int ret, cpu;
if (!of_machine_is_compatible("marvell,armadaxp"))
return 0;
np = of_find_compatible_node(NULL, NULL, "marvell,armada-xp-cpu-clock");
if (!np)
return 0;
ret = of_address_to_resource(np, 1, &res);
if (ret) {
pr_warn(FW_WARN "not enabling cpufreq, deprecated armada-xp-cpu-clock binding\n");
of_node_put(np);
return 0;
}
of_node_put(np);
for_each_possible_cpu(cpu) {
struct device *cpu_dev;
struct clk *clk;
int ret;
cpu_dev = get_cpu_device(cpu);
if (!cpu_dev) {
pr_err("Cannot get CPU %d\n", cpu);
continue;
}
clk = clk_get(cpu_dev, NULL);
if (IS_ERR(clk)) {
pr_err("Cannot get clock for CPU %d\n", cpu);
return PTR_ERR(clk);
}
ret = dev_pm_opp_add(cpu_dev, clk_get_rate(clk), 0);
if (ret) {
clk_put(clk);
return ret;
}
ret = dev_pm_opp_add(cpu_dev, clk_get_rate(clk) / 2, 0);
if (ret) {
clk_put(clk);
return ret;
}
ret = dev_pm_opp_set_sharing_cpus(cpu_dev,
cpumask_of(cpu_dev->id));
if (ret)
dev_err(cpu_dev, "%s: failed to mark OPPs as shared: %d\n",
__func__, ret);
}
platform_device_register_simple("cpufreq-dt", -1, NULL, 0);
return 0;
}
