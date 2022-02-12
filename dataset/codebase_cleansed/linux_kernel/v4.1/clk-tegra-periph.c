static void __init periph_clk_init(void __iomem *clk_base,
struct tegra_clk *tegra_clks)
{
int i;
struct clk *clk;
struct clk **dt_clk;
for (i = 0; i < ARRAY_SIZE(periph_clks); i++) {
struct tegra_clk_periph_regs *bank;
struct tegra_periph_init_data *data;
data = periph_clks + i;
dt_clk = tegra_lookup_dt_id(data->clk_id, tegra_clks);
if (!dt_clk)
continue;
bank = get_reg_bank(data->periph.gate.clk_num);
if (!bank)
continue;
data->periph.gate.regs = bank;
clk = tegra_clk_register_periph(data->name,
data->p.parent_names, data->num_parents,
&data->periph, clk_base, data->offset,
data->flags);
*dt_clk = clk;
}
}
static void __init gate_clk_init(void __iomem *clk_base,
struct tegra_clk *tegra_clks)
{
int i;
struct clk *clk;
struct clk **dt_clk;
for (i = 0; i < ARRAY_SIZE(gate_clks); i++) {
struct tegra_periph_init_data *data;
data = gate_clks + i;
dt_clk = tegra_lookup_dt_id(data->clk_id, tegra_clks);
if (!dt_clk)
continue;
clk = tegra_clk_register_periph_gate(data->name,
data->p.parent_name, data->periph.gate.flags,
clk_base, data->flags,
data->periph.gate.clk_num,
periph_clk_enb_refcnt);
*dt_clk = clk;
}
}
static void __init init_pllp(void __iomem *clk_base, void __iomem *pmc_base,
struct tegra_clk *tegra_clks,
struct tegra_clk_pll_params *pll_params)
{
struct clk *clk;
struct clk **dt_clk;
int i;
dt_clk = tegra_lookup_dt_id(tegra_clk_pll_p, tegra_clks);
if (dt_clk) {
clk = tegra_clk_register_pll("pll_p", "pll_ref", clk_base,
pmc_base, 0, pll_params, NULL);
clk_register_clkdev(clk, "pll_p", NULL);
*dt_clk = clk;
}
for (i = 0; i < ARRAY_SIZE(pllp_out_clks); i++) {
struct pll_out_data *data;
data = pllp_out_clks + i;
dt_clk = tegra_lookup_dt_id(data->clk_id, tegra_clks);
if (!dt_clk)
continue;
clk = tegra_clk_register_divider(data->div_name, "pll_p",
clk_base + data->offset, 0, data->div_flags,
data->div_shift, 8, 1, data->lock);
clk = tegra_clk_register_pll_out(data->pll_out_name,
data->div_name, clk_base + data->offset,
data->rst_shift + 1, data->rst_shift,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
data->lock);
*dt_clk = clk;
}
}
void __init tegra_periph_clk_init(void __iomem *clk_base,
void __iomem *pmc_base, struct tegra_clk *tegra_clks,
struct tegra_clk_pll_params *pll_params)
{
init_pllp(clk_base, pmc_base, tegra_clks, pll_params);
periph_clk_init(clk_base, tegra_clks);
gate_clk_init(clk_base, tegra_clks);
}
