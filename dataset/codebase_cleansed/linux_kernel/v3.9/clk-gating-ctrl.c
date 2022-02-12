static struct clk *mvebu_clk_gating_get_src(
struct of_phandle_args *clkspec, void *data)
{
struct mvebu_gating_ctrl *ctrl = (struct mvebu_gating_ctrl *)data;
int n;
if (clkspec->args_count < 1)
return ERR_PTR(-EINVAL);
for (n = 0; n < ctrl->num_gates; n++) {
struct clk_gate *gate =
to_clk_gate(__clk_get_hw(ctrl->gates[n]));
if (clkspec->args[0] == gate->bit_idx)
return ctrl->gates[n];
}
return ERR_PTR(-ENODEV);
}
static void __init mvebu_clk_gating_setup(
struct device_node *np, const struct mvebu_soc_descr *descr)
{
struct mvebu_gating_ctrl *ctrl;
struct clk *clk;
void __iomem *base;
const char *default_parent = NULL;
int n;
base = of_iomap(np, 0);
clk = of_clk_get(np, 0);
if (!IS_ERR(clk)) {
default_parent = __clk_get_name(clk);
clk_put(clk);
}
ctrl = kzalloc(sizeof(struct mvebu_gating_ctrl), GFP_KERNEL);
if (WARN_ON(!ctrl))
return;
spin_lock_init(&ctrl->lock);
for (n = 0; descr[n].name;)
n++;
ctrl->num_gates = n;
ctrl->gates = kzalloc(ctrl->num_gates * sizeof(struct clk *),
GFP_KERNEL);
if (WARN_ON(!ctrl->gates)) {
kfree(ctrl);
return;
}
for (n = 0; n < ctrl->num_gates; n++) {
u8 flags = 0;
const char *parent =
(descr[n].parent) ? descr[n].parent : default_parent;
if (!strcmp(descr[n].name, "ddr"))
flags |= CLK_IGNORE_UNUSED;
ctrl->gates[n] = clk_register_gate(NULL, descr[n].name, parent,
flags, base, descr[n].bit_idx, 0, &ctrl->lock);
WARN_ON(IS_ERR(ctrl->gates[n]));
}
of_clk_add_provider(np, mvebu_clk_gating_get_src, ctrl);
}
void __init mvebu_gating_clk_init(void)
{
struct device_node *np;
for_each_matching_node(np, clk_gating_match) {
const struct of_device_id *match =
of_match_node(clk_gating_match, np);
mvebu_clk_gating_setup(np,
(const struct mvebu_soc_descr *)match->data);
}
}
