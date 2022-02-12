static const char ** __init clkgen_mux_get_parents(struct device_node *np,
int *num_parents)
{
const char **parents;
unsigned int nparents;
nparents = of_clk_get_parent_count(np);
if (WARN_ON(!nparents))
return ERR_PTR(-EINVAL);
parents = kcalloc(nparents, sizeof(const char *), GFP_KERNEL);
if (!parents)
return ERR_PTR(-ENOMEM);
*num_parents = of_clk_parent_fill(np, parents, nparents);
return parents;
}
static void __init st_of_clkgen_mux_setup(struct device_node *np,
struct clkgen_mux_data *data)
{
struct clk *clk;
void __iomem *reg;
const char **parents;
int num_parents = 0;
reg = of_iomap(np, 0);
if (!reg) {
pr_err("%s: Failed to get base address\n", __func__);
return;
}
parents = clkgen_mux_get_parents(np, &num_parents);
if (IS_ERR(parents)) {
pr_err("%s: Failed to get parents (%ld)\n",
__func__, PTR_ERR(parents));
goto err_parents;
}
clk = clk_register_mux(NULL, np->name, parents, num_parents,
data->clk_flags | CLK_SET_RATE_PARENT,
reg + data->offset,
data->shift, data->width, data->mux_flags,
data->lock);
if (IS_ERR(clk))
goto err;
pr_debug("%s: parent %s rate %u\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
(unsigned int)clk_get_rate(clk));
kfree(parents);
of_clk_add_provider(np, of_clk_src_simple_get, clk);
return;
err:
kfree(parents);
err_parents:
iounmap(reg);
}
static void __init st_of_clkgen_a9_mux_setup(struct device_node *np)
{
st_of_clkgen_mux_setup(np, &stih407_a9_mux_data);
}
