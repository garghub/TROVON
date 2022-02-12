int __init clockevent_probe(void)
{
struct device_node *np;
const struct of_device_id *match;
of_init_fn_1_ret init_func;
int ret, clockevents = 0;
for_each_matching_node_and_match(np, __clkevt_of_table, &match) {
if (!of_device_is_available(np))
continue;
init_func = match->data;
ret = init_func(np);
if (ret) {
pr_warn("Failed to initialize '%s' (%d)\n",
np->name, ret);
continue;
}
clockevents++;
}
if (!clockevents) {
pr_crit("%s: no matching clockevent found\n", __func__);
return -ENODEV;
}
return 0;
}
