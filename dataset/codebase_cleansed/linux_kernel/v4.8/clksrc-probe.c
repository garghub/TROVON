void __init clocksource_probe(void)
{
struct device_node *np;
const struct of_device_id *match;
of_init_fn_1_ret init_func_ret;
unsigned clocksources = 0;
int ret;
for_each_matching_node_and_match(np, __clksrc_of_table, &match) {
if (!of_device_is_available(np))
continue;
init_func_ret = match->data;
ret = init_func_ret(np);
if (ret) {
pr_err("Failed to initialize '%s': %d",
of_node_full_name(np), ret);
continue;
}
clocksources++;
}
clocksources += acpi_probe_device_table(clksrc);
if (!clocksources)
pr_crit("%s: no matching clocksources found\n", __func__);
}
