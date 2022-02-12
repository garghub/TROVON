static void __init of_integrator_cm_osc_setup(struct device_node *np)
{
struct clk *clk = ERR_PTR(-EINVAL);
const char *clk_name = np->name;
const struct clk_icst_desc *desc = &cm_auxosc_desc;
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
