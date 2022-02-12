static int __init cpufreq_dt_platdev_init(void)
{
struct device_node *np = of_find_node_by_path("/");
const struct of_device_id *match;
if (!np)
return -ENODEV;
match = of_match_node(machines, np);
of_node_put(np);
if (!match)
return -ENODEV;
return PTR_ERR_OR_ZERO(platform_device_register_simple("cpufreq-dt", -1,
NULL, 0));
}
