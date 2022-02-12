void __init timer_probe(void)
{
struct device_node *np;
const struct of_device_id *match;
of_init_fn_1_ret init_func_ret;
unsigned timers = 0;
int ret;
for_each_matching_node_and_match(np, __timer_of_table, &match) {
if (!of_device_is_available(np))
continue;
init_func_ret = match->data;
ret = init_func_ret(np);
if (ret) {
pr_err("Failed to initialize '%s': %d\n",
of_node_full_name(np), ret);
continue;
}
timers++;
}
timers += acpi_probe_device_table(timer);
if (!timers)
pr_crit("%s: no matching timers found\n", __func__);
}
