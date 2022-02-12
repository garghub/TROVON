static void __init berlin2_clock_setup(struct device_node *np)
{
const char *parent_names[9];
struct clk *clk;
u8 avpll_flags = 0;
int n;
gbase = of_iomap(np, 0);
if (!gbase)
return;
clk = of_clk_get_by_name(np, clk_names[REFCLK]);
if (!IS_ERR(clk)) {
clk_names[REFCLK] = __clk_get_name(clk);
clk_put(clk);
}
clk = of_clk_get_by_name(np, clk_names[VIDEO_EXT0]);
if (!IS_ERR(clk)) {
clk_names[VIDEO_EXT0] = __clk_get_name(clk);
clk_put(clk);
}
clk = berlin2_pll_register(&bg2_pll_map, gbase + REG_SYSPLLCTL0,
clk_names[SYSPLL], clk_names[REFCLK], 0);
if (IS_ERR(clk))
goto bg2_fail;
clk = berlin2_pll_register(&bg2_pll_map, gbase + REG_MEMPLLCTL0,
clk_names[MEMPLL], clk_names[REFCLK], 0);
if (IS_ERR(clk))
goto bg2_fail;
clk = berlin2_pll_register(&bg2_pll_map, gbase + REG_CPUPLLCTL0,
clk_names[CPUPLL], clk_names[REFCLK], 0);
if (IS_ERR(clk))
goto bg2_fail;
if (of_device_is_compatible(np, "marvell,berlin2-global-register"))
avpll_flags |= BERLIN2_AVPLL_SCRAMBLE_QUIRK;
clk = berlin2_avpll_vco_register(gbase + REG_AVPLLCTL0, "avpll_vcoA",
clk_names[REFCLK], avpll_flags, 0);
if (IS_ERR(clk))
goto bg2_fail;
for (n = 0; n < 8; n++) {
clk = berlin2_avpll_channel_register(gbase + REG_AVPLLCTL0,
clk_names[AVPLL_A1 + n], n, "avpll_vcoA",
avpll_flags, 0);
if (IS_ERR(clk))
goto bg2_fail;
}
clk = berlin2_avpll_vco_register(gbase + REG_AVPLLCTL31, "avpll_vcoB",
clk_names[REFCLK], BERLIN2_AVPLL_BIT_QUIRK |
avpll_flags, 0);
if (IS_ERR(clk))
goto bg2_fail;
for (n = 0; n < 8; n++) {
clk = berlin2_avpll_channel_register(gbase + REG_AVPLLCTL31,
clk_names[AVPLL_B1 + n], n, "avpll_vcoB",
BERLIN2_AVPLL_BIT_QUIRK | avpll_flags, 0);
if (IS_ERR(clk))
goto bg2_fail;
}
parent_names[0] = clk_names[SYSPLL];
parent_names[1] = clk_names[REFCLK];
clk = clk_register_mux(NULL, "syspll_byp", parent_names, 2,
0, gbase + REG_CLKSWITCH0, 0, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
clk_names[SYSPLL] = __clk_get_name(clk);
parent_names[0] = clk_names[MEMPLL];
parent_names[1] = clk_names[REFCLK];
clk = clk_register_mux(NULL, "mempll_byp", parent_names, 2,
0, gbase + REG_CLKSWITCH0, 1, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
clk_names[MEMPLL] = __clk_get_name(clk);
parent_names[0] = clk_names[CPUPLL];
parent_names[1] = clk_names[REFCLK];
clk = clk_register_mux(NULL, "cpupll_byp", parent_names, 2,
0, gbase + REG_CLKSWITCH0, 2, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
clk_names[CPUPLL] = __clk_get_name(clk);
parent_names[0] = clk_names[AVPLL_B3];
parent_names[1] = clk_names[AVPLL_A3];
clk = clk_register_mux(NULL, clk_names[AUDIO1_PLL], parent_names, 2,
0, gbase + REG_CLKSELECT2, 29, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
parent_names[0] = clk_names[VIDEO0_PLL];
parent_names[1] = clk_names[VIDEO_EXT0];
clk = clk_register_mux(NULL, clk_names[VIDEO0_IN], parent_names, 2,
0, gbase + REG_CLKSELECT3, 4, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
parent_names[0] = clk_names[VIDEO1_PLL];
parent_names[1] = clk_names[VIDEO_EXT0];
clk = clk_register_mux(NULL, clk_names[VIDEO1_IN], parent_names, 2,
0, gbase + REG_CLKSELECT3, 6, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
parent_names[0] = clk_names[AVPLL_A2];
parent_names[1] = clk_names[AVPLL_B2];
clk = clk_register_mux(NULL, clk_names[VIDEO1_PLL], parent_names, 2,
0, gbase + REG_CLKSELECT3, 7, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
parent_names[0] = clk_names[VIDEO2_PLL];
parent_names[1] = clk_names[VIDEO_EXT0];
clk = clk_register_mux(NULL, clk_names[VIDEO2_IN], parent_names, 2,
0, gbase + REG_CLKSELECT3, 9, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
parent_names[0] = clk_names[AVPLL_B1];
parent_names[1] = clk_names[AVPLL_A5];
clk = clk_register_mux(NULL, clk_names[VIDEO2_PLL], parent_names, 2,
0, gbase + REG_CLKSELECT3, 10, 1, 0, &lock);
if (IS_ERR(clk))
goto bg2_fail;
for (n = 0; n < ARRAY_SIZE(bg2_divs); n++) {
const struct berlin2_div_data *dd = &bg2_divs[n];
int k;
for (k = 0; k < dd->num_parents; k++)
parent_names[k] = clk_names[dd->parent_ids[k]];
clks[CLKID_SYS + n] = berlin2_div_register(&dd->map, gbase,
dd->name, dd->div_flags, parent_names,
dd->num_parents, dd->flags, &lock);
}
for (n = 0; n < ARRAY_SIZE(bg2_gates); n++) {
const struct berlin2_gate_data *gd = &bg2_gates[n];
clks[CLKID_GETH0 + n] = clk_register_gate(NULL, gd->name,
gd->parent_name, gd->flags, gbase + REG_CLKENABLE,
gd->bit_idx, 0, &lock);
}
clks[CLKID_TWD] =
clk_register_fixed_factor(NULL, "twd", "cpu", 0, 1, 3);
for (n = 0; n < MAX_CLKS; n++) {
if (!IS_ERR(clks[n]))
continue;
pr_err("%s: Unable to register leaf clock %d\n",
np->full_name, n);
goto bg2_fail;
}
clk_data.clks = clks;
clk_data.clk_num = MAX_CLKS;
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
return;
bg2_fail:
iounmap(gbase);
}
