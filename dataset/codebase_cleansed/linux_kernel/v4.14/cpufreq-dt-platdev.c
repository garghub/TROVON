static bool __init cpu0_node_has_opp_v2_prop(void)
{
struct device_node *np = of_cpu_device_node_get(0);
bool ret = false;
if (of_get_property(np, "operating-points-v2", NULL))
ret = true;
of_node_put(np);
return ret;
}
static int __init cpufreq_dt_platdev_init(void)
{
struct device_node *np = of_find_node_by_path("/");
const struct of_device_id *match;
const void *data = NULL;
if (!np)
return -ENODEV;
match = of_match_node(whitelist, np);
if (match) {
data = match->data;
goto create_pdev;
}
if (cpu0_node_has_opp_v2_prop() && !of_match_node(blacklist, np))
goto create_pdev;
of_node_put(np);
return -ENODEV;
create_pdev:
of_node_put(np);
return PTR_ERR_OR_ZERO(platform_device_register_data(NULL, "cpufreq-dt",
-1, data,
sizeof(struct cpufreq_dt_platform_data)));
}
