static void pxa910_pll_init(struct pxa910_clk_unit *pxa_unit)
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
mmp_clk_add(unit, PXA910_CLK_UART_PLL, clk);
}
static void pxa910_apb_periph_clk_init(struct pxa910_clk_unit *pxa_unit)
{
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_mux_clks(unit, apbc_mux_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_mux_clks));
mmp_register_mux_clks(unit, apbcp_mux_clks, pxa_unit->apbcp_base,
ARRAY_SIZE(apbcp_mux_clks));
mmp_register_gate_clks(unit, apbc_gate_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_gate_clks));
mmp_register_gate_clks(unit, apbcp_gate_clks, pxa_unit->apbcp_base,
ARRAY_SIZE(apbcp_gate_clks));
}
static void pxa910_axi_periph_clk_init(struct pxa910_clk_unit *pxa_unit)
{
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_mux_clks(unit, apmu_mux_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_mux_clks));
mmp_register_div_clks(unit, apmu_div_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_div_clks));
mmp_register_gate_clks(unit, apmu_gate_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_gate_clks));
}
static void pxa910_clk_reset_init(struct device_node *np,
struct pxa910_clk_unit *pxa_unit)
{
struct mmp_clk_reset_cell *cells;
int i, base, nr_resets_apbc, nr_resets_apbcp, nr_resets;
nr_resets_apbc = ARRAY_SIZE(apbc_gate_clks);
nr_resets_apbcp = ARRAY_SIZE(apbcp_gate_clks);
nr_resets = nr_resets_apbc + nr_resets_apbcp;
cells = kcalloc(nr_resets, sizeof(*cells), GFP_KERNEL);
if (!cells)
return;
base = 0;
for (i = 0; i < nr_resets_apbc; i++) {
cells[base + i].clk_id = apbc_gate_clks[i].id;
cells[base + i].reg =
pxa_unit->apbc_base + apbc_gate_clks[i].offset;
cells[base + i].flags = 0;
cells[base + i].lock = apbc_gate_clks[i].lock;
cells[base + i].bits = 0x4;
}
base = nr_resets_apbc;
for (i = 0; i < nr_resets_apbcp; i++) {
cells[base + i].clk_id = apbcp_gate_clks[i].id;
cells[base + i].reg =
pxa_unit->apbc_base + apbc_gate_clks[i].offset;
cells[base + i].flags = 0;
cells[base + i].lock = apbc_gate_clks[i].lock;
cells[base + i].bits = 0x4;
}
mmp_clk_reset_register(np, cells, nr_resets);
}
static void __init pxa910_clk_init(struct device_node *np)
{
struct pxa910_clk_unit *pxa_unit;
pxa_unit = kzalloc(sizeof(*pxa_unit), GFP_KERNEL);
if (!pxa_unit)
return;
pxa_unit->mpmu_base = of_iomap(np, 0);
if (!pxa_unit->mpmu_base) {
pr_err("failed to map mpmu registers\n");
return;
}
pxa_unit->apmu_base = of_iomap(np, 1);
if (!pxa_unit->mpmu_base) {
pr_err("failed to map apmu registers\n");
return;
}
pxa_unit->apbc_base = of_iomap(np, 2);
if (!pxa_unit->apbc_base) {
pr_err("failed to map apbc registers\n");
return;
}
pxa_unit->apbcp_base = of_iomap(np, 3);
if (!pxa_unit->mpmu_base) {
pr_err("failed to map apbcp registers\n");
return;
}
mmp_clk_init(np, &pxa_unit->unit, PXA910_NR_CLKS);
pxa910_pll_init(pxa_unit);
pxa910_apb_periph_clk_init(pxa_unit);
pxa910_axi_periph_clk_init(pxa_unit);
pxa910_clk_reset_init(np, pxa_unit);
}
