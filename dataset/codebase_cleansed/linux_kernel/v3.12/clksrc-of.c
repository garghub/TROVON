void __init clocksource_of_init(void)
{
struct device_node *np;
const struct of_device_id *match;
clocksource_of_init_fn init_func;
for_each_matching_node_and_match(np, __clksrc_of_table, &match) {
if (!of_device_is_available(np))
continue;
init_func = match->data;
init_func(np);
}
}
