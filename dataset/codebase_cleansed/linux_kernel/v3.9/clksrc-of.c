void __init clocksource_of_init(void)
{
struct device_node *np;
const struct of_device_id *match;
void (*init_func)(void);
for_each_matching_node_and_match(np, __clksrc_of_table, &match) {
init_func = match->data;
init_func();
}
}
