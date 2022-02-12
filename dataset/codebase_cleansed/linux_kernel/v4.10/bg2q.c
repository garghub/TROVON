static void __init berlin2q_clock_setup(struct device_node *np)
{
struct device_node *parent_np = of_get_parent(np);
const char *parent_names[9];
struct clk *clk;
struct clk_hw **hws;
int n, ret;
clk_data = kzalloc(sizeof(*clk_data) +
sizeof(*clk_data->hws) * MAX_CLKS, GFP_KERNEL);
if (!clk_data)
return;
clk_data->num = MAX_CLKS;
hws = clk_data->hws;
gbase = of_iomap(parent_np, 0);
if (!gbase) {
pr_err("%s: Unable to map global base\n", np->full_name);
return;
}
cpupll_base = of_iomap(parent_np, 1);
if (!cpupll_base) {
pr_err("%s: Unable to map cpupll base\n", np->full_name);
iounmap(gbase);
return;
}
clk = of_clk_get_by_name(np, clk_names[REFCLK]);
if (!IS_ERR(clk)) {
clk_names[REFCLK] = __clk_get_name(clk);
clk_put(clk);
}
ret = berlin2_pll_register(&bg2q_pll_map, gbase + REG_SYSPLLCTL0,
clk_names[SYSPLL], clk_names[REFCLK], 0);
if (ret)
goto bg2q_fail;
ret = berlin2_pll_register(&bg2q_pll_map, cpupll_base,
clk_names[CPUPLL], clk_names[REFCLK], 0);
if (ret)
goto bg2q_fail;
for (n = 0; n < ARRAY_SIZE(bg2q_divs); n++) {
const struct berlin2_div_data *dd = &bg2q_divs[n];
int k;
for (k = 0; k < dd->num_parents; k++)
parent_names[k] = clk_names[dd->parent_ids[k]];
hws[CLKID_SYS + n] = berlin2_div_register(&dd->map, gbase,
dd->name, dd->div_flags, parent_names,
dd->num_parents, dd->flags, &lock);
}
for (n = 0; n < ARRAY_SIZE(bg2q_gates); n++) {
const struct berlin2_gate_data *gd = &bg2q_gates[n];
hws[CLKID_GFX2DAXI + n] = clk_hw_register_gate(NULL, gd->name,
gd->parent_name, gd->flags, gbase + REG_CLKENABLE,
gd->bit_idx, 0, &lock);
}
hws[CLKID_CPU] =
clk_hw_register_fixed_factor(NULL, "cpu", clk_names[CPUPLL],
0, 1, 1);
hws[CLKID_TWD] =
clk_hw_register_fixed_factor(NULL, "twd", "cpu", 0, 1, 3);
for (n = 0; n < MAX_CLKS; n++) {
if (!IS_ERR(hws[n]))
continue;
pr_err("%s: Unable to register leaf clock %d\n",
np->full_name, n);
goto bg2q_fail;
}
of_clk_add_hw_provider(np, of_clk_hw_onecell_get, clk_data);
return;
bg2q_fail:
iounmap(cpupll_base);
iounmap(gbase);
}
