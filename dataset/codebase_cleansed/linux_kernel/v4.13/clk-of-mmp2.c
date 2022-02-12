static void mmp2_pll_init(struct mmp2_clk_unit *pxa_unit)
{
struct clk *clk;
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_fixed_rate_clks(unit, fixed_rate_clks,
ARRAY_SIZE(fixed_rate_clks));
mmp_register_fixed_factor_clks(unit, fixed_factor_clks,
ARRAY_SIZE(fixed_factor_clks));
clk = mmp_clk_register_factor("uart_pll", "pll1_4",
CLK_SET_RATE_PARENT,
pxa_unit->mpmu_base + MPMU_UART_PLL,
&uart_factor_masks, uart_factor_tbl,
ARRAY_SIZE(uart_factor_tbl), NULL);
mmp_clk_add(unit, MMP2_CLK_UART_PLL, clk);
}
static void mmp2_apb_periph_clk_init(struct mmp2_clk_unit *pxa_unit)
{
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_mux_clks(unit, apbc_mux_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_mux_clks));
mmp_register_gate_clks(unit, apbc_gate_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_gate_clks));
}
static void mmp2_axi_periph_clk_init(struct mmp2_clk_unit *pxa_unit)
{
struct clk *clk;
struct mmp_clk_unit *unit = &pxa_unit->unit;
sdh_mix_config.reg_info.reg_clk_ctrl = pxa_unit->apmu_base + APMU_SDH0;
clk = mmp_clk_register_mix(NULL, "sdh_mix_clk", sdh_parent_names,
ARRAY_SIZE(sdh_parent_names),
CLK_SET_RATE_PARENT,
&sdh_mix_config, &sdh_lock);
ccic0_mix_config.reg_info.reg_clk_ctrl = pxa_unit->apmu_base + APMU_CCIC0;
clk = mmp_clk_register_mix(NULL, "ccic0_mix_clk", ccic_parent_names,
ARRAY_SIZE(ccic_parent_names),
CLK_SET_RATE_PARENT,
&ccic0_mix_config, &ccic0_lock);
mmp_clk_add(unit, MMP2_CLK_CCIC0_MIX, clk);
ccic1_mix_config.reg_info.reg_clk_ctrl = pxa_unit->apmu_base + APMU_CCIC1;
clk = mmp_clk_register_mix(NULL, "ccic1_mix_clk", ccic_parent_names,
ARRAY_SIZE(ccic_parent_names),
CLK_SET_RATE_PARENT,
&ccic1_mix_config, &ccic1_lock);
mmp_clk_add(unit, MMP2_CLK_CCIC1_MIX, clk);
mmp_register_mux_clks(unit, apmu_mux_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_mux_clks));
mmp_register_div_clks(unit, apmu_div_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_div_clks));
mmp_register_gate_clks(unit, apmu_gate_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_gate_clks));
}
static void mmp2_clk_reset_init(struct device_node *np,
struct mmp2_clk_unit *pxa_unit)
{
struct mmp_clk_reset_cell *cells;
int i, nr_resets;
nr_resets = ARRAY_SIZE(apbc_gate_clks);
cells = kcalloc(nr_resets, sizeof(*cells), GFP_KERNEL);
if (!cells)
return;
for (i = 0; i < nr_resets; i++) {
cells[i].clk_id = apbc_gate_clks[i].id;
cells[i].reg = pxa_unit->apbc_base + apbc_gate_clks[i].offset;
cells[i].flags = 0;
cells[i].lock = apbc_gate_clks[i].lock;
cells[i].bits = 0x4;
}
mmp_clk_reset_register(np, cells, nr_resets);
}
static void __init mmp2_clk_init(struct device_node *np)
{
struct mmp2_clk_unit *pxa_unit;
pxa_unit = kzalloc(sizeof(*pxa_unit), GFP_KERNEL);
if (!pxa_unit)
return;
pxa_unit->mpmu_base = of_iomap(np, 0);
if (!pxa_unit->mpmu_base) {
pr_err("failed to map mpmu registers\n");
goto free_memory;
}
pxa_unit->apmu_base = of_iomap(np, 1);
if (!pxa_unit->apmu_base) {
pr_err("failed to map apmu registers\n");
goto unmap_mpmu_region;
}
pxa_unit->apbc_base = of_iomap(np, 2);
if (!pxa_unit->apbc_base) {
pr_err("failed to map apbc registers\n");
goto unmap_apmu_region;
}
mmp_clk_init(np, &pxa_unit->unit, MMP2_NR_CLKS);
mmp2_pll_init(pxa_unit);
mmp2_apb_periph_clk_init(pxa_unit);
mmp2_axi_periph_clk_init(pxa_unit);
mmp2_clk_reset_init(np, pxa_unit);
return;
unmap_apmu_region:
iounmap(pxa_unit->apmu_base);
unmap_mpmu_region:
iounmap(pxa_unit->mpmu_base);
free_memory:
kfree(pxa_unit);
}
