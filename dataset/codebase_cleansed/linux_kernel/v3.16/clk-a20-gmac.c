static void __init sun7i_a20_gmac_clk_setup(struct device_node *node)
{
struct clk *clk;
struct clk_mux *mux;
struct clk_gate *gate;
const char *clk_name = node->name;
const char *parents[SUN7I_A20_GMAC_PARENTS];
void *reg;
if (of_property_read_string(node, "clock-output-names", &clk_name))
return;
mux = kzalloc(sizeof(struct clk_mux), GFP_KERNEL);
if (!mux)
return;
gate = kzalloc(sizeof(struct clk_gate), GFP_KERNEL);
if (!gate)
goto free_mux;
parents[0] = of_clk_get_parent_name(node, 0);
parents[1] = of_clk_get_parent_name(node, 1);
if (!parents[0] || !parents[1])
goto free_gate;
reg = of_iomap(node, 0);
if (!reg)
goto free_gate;
gate->reg = reg;
gate->bit_idx = SUN7I_A20_GMAC_GPIT;
gate->lock = &gmac_lock;
mux->reg = reg;
mux->mask = SUN7I_A20_GMAC_MASK;
mux->flags = CLK_MUX_INDEX_BIT;
mux->lock = &gmac_lock;
clk = clk_register_composite(NULL, clk_name,
parents, SUN7I_A20_GMAC_PARENTS,
&mux->hw, &clk_mux_ops,
NULL, NULL,
&gate->hw, &clk_gate_ops,
0);
if (IS_ERR(clk))
goto iounmap_reg;
of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
return;
iounmap_reg:
iounmap(reg);
free_gate:
kfree(gate);
free_mux:
kfree(mux);
}
