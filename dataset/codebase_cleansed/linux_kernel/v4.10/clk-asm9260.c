static void __init asm9260_acc_init(struct device_node *np)
{
struct clk_hw *hw;
struct clk_hw **hws;
const char *ref_clk, *pll_clk = "pll";
u32 rate;
int n;
u32 accuracy = 0;
clk_data = kzalloc(sizeof(*clk_data) +
sizeof(*clk_data->hws) * MAX_CLKS, GFP_KERNEL);
if (!clk_data)
return;
clk_data->num = MAX_CLKS;
hws = clk_data->hws;
base = of_io_request_and_map(np, 0, np->name);
if (IS_ERR(base))
panic("%s: unable to map resource", np->name);
rate = (ioread32(base + HW_SYSPLLCTRL) & 0xffff) * 1000000;
ref_clk = of_clk_get_parent_name(np, 0);
accuracy = clk_get_accuracy(__clk_lookup(ref_clk));
hw = clk_hw_register_fixed_rate_with_accuracy(NULL, pll_clk,
ref_clk, 0, rate, accuracy);
if (IS_ERR(hw))
panic("%s: can't register REFCLK. Check DT!", np->name);
for (n = 0; n < ARRAY_SIZE(asm9260_mux_clks); n++) {
const struct asm9260_mux_clock *mc = &asm9260_mux_clks[n];
mc->parent_names[0] = ref_clk;
mc->parent_names[1] = pll_clk;
hw = clk_hw_register_mux_table(NULL, mc->name, mc->parent_names,
mc->num_parents, mc->flags, base + mc->offset,
0, mc->mask, 0, mc->table, &asm9260_clk_lock);
}
for (n = 0; n < ARRAY_SIZE(asm9260_mux_gates); n++) {
const struct asm9260_gate_data *gd = &asm9260_mux_gates[n];
hw = clk_hw_register_gate(NULL, gd->name,
gd->parent_name, gd->flags | CLK_SET_RATE_PARENT,
base + gd->reg, gd->bit_idx, 0, &asm9260_clk_lock);
}
for (n = 0; n < ARRAY_SIZE(asm9260_div_clks); n++) {
const struct asm9260_div_clk *dc = &asm9260_div_clks[n];
hws[dc->idx] = clk_hw_register_divider(NULL, dc->name,
dc->parent_name, CLK_SET_RATE_PARENT,
base + dc->reg, 0, 8, CLK_DIVIDER_ONE_BASED,
&asm9260_clk_lock);
}
for (n = 0; n < ARRAY_SIZE(asm9260_ahb_gates); n++) {
const struct asm9260_gate_data *gd = &asm9260_ahb_gates[n];
hws[gd->idx] = clk_hw_register_gate(NULL, gd->name,
gd->parent_name, gd->flags, base + gd->reg,
gd->bit_idx, 0, &asm9260_clk_lock);
}
for (n = 0; n < MAX_CLKS; n++) {
if (!IS_ERR(hws[n]))
continue;
pr_err("%s: Unable to register leaf clock %d\n",
np->full_name, n);
goto fail;
}
of_clk_add_hw_provider(np, of_clk_hw_onecell_get, clk_data);
return;
fail:
iounmap(base);
}
