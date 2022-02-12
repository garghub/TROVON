static void pxa168_pll_init(struct pxa168_clk_unit *pxa_unit)
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
mmp_clk_add(unit, PXA168_CLK_UART_PLL, clk);
}
static void pxa168_apb_periph_clk_init(struct pxa168_clk_unit *pxa_unit)
{
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_mux_clks(unit, apbc_mux_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_mux_clks));
mmp_register_gate_clks(unit, apbc_gate_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_gate_clks));
}
static void pxa168_axi_periph_clk_init(struct pxa168_clk_unit *pxa_unit)
{
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_mux_clks(unit, apmu_mux_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_mux_clks));
mmp_register_div_clks(unit, apmu_div_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_div_clks));
mmp_register_gate_clks(unit, apmu_gate_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_gate_clks));
}
static void pxa168_clk_reset_init(struct device_node *np,
struct pxa168_clk_unit *pxa_unit)
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
static void __init pxa168_clk_init(struct device_node *np)
{
struct pxa168_clk_unit *pxa_unit;
pxa_unit = kzalloc(sizeof(*pxa_unit), GFP_KERNEL);
if (!pxa_unit)
return;
pxa_unit->mpmu_base = of_iomap(np, 0);
if (!pxa_unit->mpmu_base) {
pr_err("failed to map mpmu registers\n");
return;
}
pxa_unit->apmu_base = of_iomap(np, 1);
if (!pxa_unit->apmu_base) {
pr_err("failed to map apmu registers\n");
return;
}
pxa_unit->apbc_base = of_iomap(np, 2);
if (!pxa_unit->apbc_base) {
pr_err("failed to map apbc registers\n");
return;
}
mmp_clk_init(np, &pxa_unit->unit, PXA168_NR_CLKS);
pxa168_pll_init(pxa_unit);
pxa168_apb_periph_clk_init(pxa_unit);
pxa168_axi_periph_clk_init(pxa_unit);
pxa168_clk_reset_init(np, pxa_unit);
}
