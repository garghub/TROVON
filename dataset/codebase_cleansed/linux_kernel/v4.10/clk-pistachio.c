static void __init pistachio_clk_init(struct device_node *np)
{
struct pistachio_clk_provider *p;
struct clk *debug_clk;
p = pistachio_clk_alloc_provider(np, CLK_NR_CLKS);
if (!p)
return;
pistachio_clk_register_pll(p, pistachio_plls,
ARRAY_SIZE(pistachio_plls));
pistachio_clk_register_mux(p, pistachio_muxes,
ARRAY_SIZE(pistachio_muxes));
pistachio_clk_register_div(p, pistachio_divs,
ARRAY_SIZE(pistachio_divs));
pistachio_clk_register_fixed_factor(p, pistachio_ffs,
ARRAY_SIZE(pistachio_ffs));
pistachio_clk_register_gate(p, pistachio_gates,
ARRAY_SIZE(pistachio_gates));
debug_clk = clk_register_mux_table(NULL, "debug_mux", mux_debug,
ARRAY_SIZE(mux_debug),
CLK_SET_RATE_NO_REPARENT,
p->base + 0x200, 18, 0x1f, 0,
mux_debug_idx, NULL);
p->clk_data.clks[CLK_DEBUG_MUX] = debug_clk;
pistachio_clk_register_provider(p);
pistachio_clk_force_enable(p, pistachio_critical_clks_core,
ARRAY_SIZE(pistachio_critical_clks_core));
}
static void __init pistachio_clk_periph_init(struct device_node *np)
{
struct pistachio_clk_provider *p;
p = pistachio_clk_alloc_provider(np, PERIPH_CLK_NR_CLKS);
if (!p)
return;
pistachio_clk_register_div(p, pistachio_periph_divs,
ARRAY_SIZE(pistachio_periph_divs));
pistachio_clk_register_gate(p, pistachio_periph_gates,
ARRAY_SIZE(pistachio_periph_gates));
pistachio_clk_register_provider(p);
pistachio_clk_force_enable(p, pistachio_critical_clks_sys,
ARRAY_SIZE(pistachio_critical_clks_sys));
}
static void __init pistachio_cr_periph_init(struct device_node *np)
{
struct pistachio_clk_provider *p;
p = pistachio_clk_alloc_provider(np, SYS_CLK_NR_CLKS);
if (!p)
return;
pistachio_clk_register_gate(p, pistachio_sys_gates,
ARRAY_SIZE(pistachio_sys_gates));
pistachio_clk_register_provider(p);
}
static void __init pistachio_cr_top_init(struct device_node *np)
{
struct pistachio_clk_provider *p;
p = pistachio_clk_alloc_provider(np, EXT_CLK_NR_CLKS);
if (!p)
return;
pistachio_clk_register_gate(p, pistachio_ext_gates,
ARRAY_SIZE(pistachio_ext_gates));
pistachio_clk_register_provider(p);
}
