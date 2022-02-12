static void __init imx51_dt_init(void)
{
struct device_node *node;
const struct of_device_id *of_id;
void (*func)(void);
pinctrl_provide_dummies();
node = of_find_matching_node(NULL, imx51_iomuxc_of_match);
if (node) {
of_id = of_match_node(imx51_iomuxc_of_match, node);
func = of_id->data;
func();
of_node_put(node);
}
of_platform_populate(NULL, of_default_bus_match_table,
imx51_auxdata_lookup, NULL);
}
static void __init imx51_timer_init(void)
{
mx51_clocks_init_dt();
}
