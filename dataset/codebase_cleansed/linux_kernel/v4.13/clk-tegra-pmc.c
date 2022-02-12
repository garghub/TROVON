void __init tegra_pmc_clk_init(void __iomem *pmc_base,
struct tegra_clk *tegra_clks)
{
struct clk *clk;
struct clk **dt_clk;
int i;
for (i = 0; i < ARRAY_SIZE(pmc_clks); i++) {
struct pmc_clk_init_data *data;
data = pmc_clks + i;
dt_clk = tegra_lookup_dt_id(data->mux_id, tegra_clks);
if (!dt_clk)
continue;
clk = clk_register_mux(NULL, data->mux_name, data->parents,
data->num_parents,
CLK_SET_RATE_NO_REPARENT | CLK_SET_RATE_PARENT,
pmc_base + PMC_CLK_OUT_CNTRL, data->mux_shift,
3, 0, &clk_out_lock);
*dt_clk = clk;
dt_clk = tegra_lookup_dt_id(data->gate_id, tegra_clks);
if (!dt_clk)
continue;
clk = clk_register_gate(NULL, data->gate_name, data->mux_name,
CLK_SET_RATE_PARENT,
pmc_base + PMC_CLK_OUT_CNTRL,
data->gate_shift, 0, &clk_out_lock);
*dt_clk = clk;
clk_register_clkdev(clk, data->dev_name, data->gate_name);
}
writel_relaxed(0, pmc_base + PMC_BLINK_TIMER);
clk = clk_register_gate(NULL, "blink_override", "clk_32k", 0,
pmc_base + PMC_DPD_PADS_ORIDE,
PMC_DPD_PADS_ORIDE_BLINK_ENB, 0, NULL);
dt_clk = tegra_lookup_dt_id(tegra_clk_blink, tegra_clks);
if (!dt_clk)
return;
clk = clk_register_gate(NULL, "blink", "blink_override", 0,
pmc_base + PMC_CTRL,
PMC_CTRL_BLINK_ENB, 0, NULL);
clk_register_clkdev(clk, "blink", NULL);
*dt_clk = clk;
}
