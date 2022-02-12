static void pxa1928_pll_init(struct pxa1928_clk_unit *pxa_unit)
{
struct clk *clk;
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_fixed_rate_clks(unit, fixed_rate_clks,
ARRAY_SIZE(fixed_rate_clks));
mmp_register_fixed_factor_clks(unit, fixed_factor_clks,
ARRAY_SIZE(fixed_factor_clks));
clk = mmp_clk_register_factor("uart_pll", "pll1_416",
CLK_SET_RATE_PARENT,
pxa_unit->mpmu_base + MPMU_UART_PLL,
&uart_factor_masks, uart_factor_tbl,
ARRAY_SIZE(uart_factor_tbl), NULL);
}
static void pxa1928_apb_periph_clk_init(struct pxa1928_clk_unit *pxa_unit)
{
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_mux_clks(unit, apbc_mux_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_mux_clks));
mmp_register_gate_clks(unit, apbc_gate_clks, pxa_unit->apbc_base,
ARRAY_SIZE(apbc_gate_clks));
}
static void pxa1928_axi_periph_clk_init(struct pxa1928_clk_unit *pxa_unit)
{
struct mmp_clk_unit *unit = &pxa_unit->unit;
mmp_register_mux_clks(unit, apmu_mux_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_mux_clks));
mmp_register_div_clks(unit, apmu_div_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_div_clks));
mmp_register_gate_clks(unit, apmu_gate_clks, pxa_unit->apmu_base,
ARRAY_SIZE(apmu_gate_clks));
}
static void pxa1928_clk_reset_init(struct device_node *np,
struct pxa1928_clk_unit *pxa_unit)
{
struct mmp_clk_reset_cell *cells;
int i, base, nr_resets;
nr_resets = ARRAY_SIZE(apbc_gate_clks);
cells = kcalloc(nr_resets, sizeof(*cells), GFP_KERNEL);
if (!cells)
return;
base = 0;
for (i = 0; i < nr_resets; i++) {
cells[base + i].clk_id = apbc_gate_clks[i].id;
cells[base + i].reg =
pxa_unit->apbc_base + apbc_gate_clks[i].offset;
cells[base + i].flags = 0;
cells[base + i].lock = apbc_gate_clks[i].lock;
cells[base + i].bits = 0x4;
}
mmp_clk_reset_register(np, cells, nr_resets);
}
static void __init pxa1928_mpmu_clk_init(struct device_node *np)
{
struct pxa1928_clk_unit *pxa_unit;
pxa_unit = kzalloc(sizeof(*pxa_unit), GFP_KERNEL);
if (!pxa_unit)
return;
pxa_unit->mpmu_base = of_iomap(np, 0);
if (!pxa_unit->mpmu_base) {
pr_err("failed to map mpmu registers\n");
kfree(pxa_unit);
return;
}
pxa1928_pll_init(pxa_unit);
}
static void __init pxa1928_apmu_clk_init(struct device_node *np)
{
struct pxa1928_clk_unit *pxa_unit;
pxa_unit = kzalloc(sizeof(*pxa_unit), GFP_KERNEL);
if (!pxa_unit)
return;
pxa_unit->apmu_base = of_iomap(np, 0);
if (!pxa_unit->apmu_base) {
pr_err("failed to map apmu registers\n");
kfree(pxa_unit);
return;
}
mmp_clk_init(np, &pxa_unit->unit, PXA1928_APMU_NR_CLKS);
pxa1928_axi_periph_clk_init(pxa_unit);
}
static void __init pxa1928_apbc_clk_init(struct device_node *np)
{
struct pxa1928_clk_unit *pxa_unit;
pxa_unit = kzalloc(sizeof(*pxa_unit), GFP_KERNEL);
if (!pxa_unit)
return;
pxa_unit->apbc_base = of_iomap(np, 0);
if (!pxa_unit->apbc_base) {
pr_err("failed to map apbc registers\n");
kfree(pxa_unit);
return;
}
mmp_clk_init(np, &pxa_unit->unit, PXA1928_APBC_NR_CLKS);
pxa1928_apb_periph_clk_init(pxa_unit);
pxa1928_clk_reset_init(np, pxa_unit);
}
