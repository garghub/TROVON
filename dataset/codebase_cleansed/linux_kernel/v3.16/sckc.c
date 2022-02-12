static void __init of_at91sam9x5_sckc_setup(struct device_node *np)
{
struct device_node *childnp;
void (*clk_setup)(struct device_node *, void __iomem *);
const struct of_device_id *clk_id;
void __iomem *regbase = of_iomap(np, 0);
if (!regbase)
return;
for_each_child_of_node(np, childnp) {
clk_id = of_match_node(sckc_clk_ids, childnp);
if (!clk_id)
continue;
clk_setup = clk_id->data;
clk_setup(childnp, regbase);
}
}
