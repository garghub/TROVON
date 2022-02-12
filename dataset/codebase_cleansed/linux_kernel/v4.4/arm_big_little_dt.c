static struct device_node *get_cpu_node_with_valid_op(int cpu)
{
struct device_node *np = of_cpu_device_node_get(cpu);
if (!of_get_property(np, "operating-points", NULL)) {
of_node_put(np);
np = NULL;
}
return np;
}
static int dt_init_opp_table(struct device *cpu_dev)
{
struct device_node *np;
int ret;
np = of_node_get(cpu_dev->of_node);
if (!np) {
pr_err("failed to find cpu%d node\n", cpu_dev->id);
return -ENOENT;
}
ret = dev_pm_opp_of_add_table(cpu_dev);
of_node_put(np);
return ret;
}
static int dt_get_transition_latency(struct device *cpu_dev)
{
struct device_node *np;
u32 transition_latency = CPUFREQ_ETERNAL;
np = of_node_get(cpu_dev->of_node);
if (!np) {
pr_info("Failed to find cpu node. Use CPUFREQ_ETERNAL transition latency\n");
return CPUFREQ_ETERNAL;
}
of_property_read_u32(np, "clock-latency", &transition_latency);
of_node_put(np);
pr_debug("%s: clock-latency: %d\n", __func__, transition_latency);
return transition_latency;
}
static int generic_bL_probe(struct platform_device *pdev)
{
struct device_node *np;
np = get_cpu_node_with_valid_op(0);
if (!np)
return -ENODEV;
of_node_put(np);
return bL_cpufreq_register(&dt_bL_ops);
}
static int generic_bL_remove(struct platform_device *pdev)
{
bL_cpufreq_unregister(&dt_bL_ops);
return 0;
}
