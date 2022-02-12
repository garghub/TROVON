static void __init cm_osc_setup(struct device_node *np,
const struct clk_icst_desc *desc)
{
struct clk *clk = ERR_PTR(-EINVAL);
const char *clk_name = np->name;
const char *parent_name;
if (!cm_base) {
struct device_node *parent;
parent = of_get_parent(np);
if (!np) {
pr_err("no parent on core module clock\n");
return;
}
cm_base = of_iomap(parent, 0);
if (!cm_base) {
pr_err("could not remap core module base\n");
return;
}
}
parent_name = of_clk_get_parent_name(np, 0);
clk = icst_clk_register(NULL, desc, clk_name, parent_name, cm_base);
if (!IS_ERR(clk))
of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
static void __init of_integrator_cm_osc_setup(struct device_node *np)
{
cm_osc_setup(np, &cm_auxosc_desc);
}
static void __init of_versatile_cm_osc_setup(struct device_node *np)
{
cm_osc_setup(np, &versatile_auxosc_desc);
}
