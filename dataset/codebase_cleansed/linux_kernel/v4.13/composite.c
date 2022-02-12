static unsigned long ti_composite_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return ti_clk_divider_ops.recalc_rate(hw, parent_rate);
}
static long ti_composite_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
return -EINVAL;
}
static int ti_composite_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
return -EINVAL;
}
static struct device_node *_get_component_node(struct device_node *node, int i)
{
int rc;
struct of_phandle_args clkspec;
rc = of_parse_phandle_with_args(node, "clocks", "#clock-cells", i,
&clkspec);
if (rc)
return NULL;
return clkspec.np;
}
static struct component_clk *_lookup_component(struct device_node *node)
{
struct component_clk *comp;
list_for_each_entry(comp, &component_clks, link) {
if (comp->node == node)
return comp;
}
return NULL;
}
static inline struct clk_hw *_get_hw(struct clk_hw_omap_comp *clk, int idx)
{
if (!clk)
return NULL;
if (!clk->comp_clks[idx])
return NULL;
return clk->comp_clks[idx]->hw;
}
struct clk *ti_clk_register_composite(struct ti_clk *setup)
{
struct ti_clk_composite *comp;
struct clk_hw *gate;
struct clk_hw *mux;
struct clk_hw *div;
int num_parents = 1;
const char * const *parent_names = NULL;
struct clk *clk;
int ret;
comp = setup->data;
div = ti_clk_build_component_div(comp->divider);
gate = ti_clk_build_component_gate(comp->gate);
mux = ti_clk_build_component_mux(comp->mux);
if (div)
parent_names = &comp->divider->parent;
if (gate)
parent_names = &comp->gate->parent;
if (mux) {
num_parents = comp->mux->num_parents;
parent_names = comp->mux->parents;
}
clk = clk_register_composite(NULL, setup->name,
parent_names, num_parents, mux,
&ti_clk_mux_ops, div,
&ti_composite_divider_ops, gate,
&ti_composite_gate_ops, 0);
ret = ti_clk_add_alias(NULL, clk, setup->name);
if (ret) {
clk_unregister(clk);
return ERR_PTR(ret);
}
return clk;
}
static void __init _register_composite(struct clk_hw *hw,
struct device_node *node)
{
struct clk *clk;
struct clk_hw_omap_comp *cclk = to_clk_hw_comp(hw);
struct component_clk *comp;
int num_parents = 0;
const char **parent_names = NULL;
int i;
int ret;
for (i = 0; i < CLK_COMPONENT_TYPE_MAX; i++) {
if (!cclk->comp_nodes[i])
continue;
comp = _lookup_component(cclk->comp_nodes[i]);
if (!comp) {
pr_debug("component %s not ready for %s, retry\n",
cclk->comp_nodes[i]->name, node->name);
if (!ti_clk_retry_init(node, hw,
_register_composite))
return;
goto cleanup;
}
if (cclk->comp_clks[comp->type] != NULL) {
pr_err("duplicate component types for %s (%s)!\n",
node->name, component_clk_types[comp->type]);
goto cleanup;
}
cclk->comp_clks[comp->type] = comp;
cclk->comp_nodes[i] = NULL;
}
for (i = CLK_COMPONENT_TYPE_MAX - 1; i >= 0; i--) {
comp = cclk->comp_clks[i];
if (!comp)
continue;
if (comp->num_parents) {
num_parents = comp->num_parents;
parent_names = comp->parent_names;
break;
}
}
if (!num_parents) {
pr_err("%s: no parents found for %s!\n", __func__, node->name);
goto cleanup;
}
clk = clk_register_composite(NULL, node->name,
parent_names, num_parents,
_get_hw(cclk, CLK_COMPONENT_TYPE_MUX),
&ti_clk_mux_ops,
_get_hw(cclk, CLK_COMPONENT_TYPE_DIVIDER),
&ti_composite_divider_ops,
_get_hw(cclk, CLK_COMPONENT_TYPE_GATE),
&ti_composite_gate_ops, 0);
if (!IS_ERR(clk)) {
ret = ti_clk_add_alias(NULL, clk, node->name);
if (ret) {
clk_unregister(clk);
goto cleanup;
}
of_clk_add_provider(node, of_clk_src_simple_get, clk);
}
cleanup:
for (i = 0; i < CLK_COMPONENT_TYPE_MAX; i++) {
if (!cclk->comp_clks[i])
continue;
list_del(&cclk->comp_clks[i]->link);
kfree(cclk->comp_clks[i]);
}
kfree(cclk);
}
static void __init of_ti_composite_clk_setup(struct device_node *node)
{
unsigned int num_clks;
int i;
struct clk_hw_omap_comp *cclk;
num_clks = of_clk_get_parent_count(node);
if (!num_clks) {
pr_err("composite clk %s must have component(s)\n", node->name);
return;
}
cclk = kzalloc(sizeof(*cclk), GFP_KERNEL);
if (!cclk)
return;
for (i = 0; i < num_clks; i++)
cclk->comp_nodes[i] = _get_component_node(node, i);
_register_composite(&cclk->hw, node);
}
int __init ti_clk_add_component(struct device_node *node, struct clk_hw *hw,
int type)
{
unsigned int num_parents;
const char **parent_names;
struct component_clk *clk;
num_parents = of_clk_get_parent_count(node);
if (!num_parents) {
pr_err("component-clock %s must have parent(s)\n", node->name);
return -EINVAL;
}
parent_names = kzalloc((sizeof(char *) * num_parents), GFP_KERNEL);
if (!parent_names)
return -ENOMEM;
of_clk_parent_fill(node, parent_names, num_parents);
clk = kzalloc(sizeof(*clk), GFP_KERNEL);
if (!clk) {
kfree(parent_names);
return -ENOMEM;
}
clk->num_parents = num_parents;
clk->parent_names = parent_names;
clk->hw = hw;
clk->node = node;
clk->type = type;
list_add(&clk->link, &component_clks);
return 0;
}
