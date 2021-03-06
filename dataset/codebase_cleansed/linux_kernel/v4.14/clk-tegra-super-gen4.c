static void __init tegra_sclk_init(void __iomem *clk_base,
struct tegra_clk *tegra_clks,
const struct tegra_super_gen_info *gen_info)
{
struct clk *clk;
struct clk **dt_clk;
dt_clk = tegra_lookup_dt_id(tegra_clk_sclk_mux, tegra_clks);
if (dt_clk) {
clk = tegra_clk_register_super_mux("sclk_mux",
gen_info->sclk_parents,
gen_info->num_sclk_parents,
CLK_SET_RATE_PARENT,
clk_base + SCLK_BURST_POLICY,
0, 4, 0, 0, NULL);
*dt_clk = clk;
dt_clk = tegra_lookup_dt_id(tegra_clk_sclk, tegra_clks);
if (dt_clk) {
clk = clk_register_divider(NULL, "sclk", "sclk_mux", 0,
clk_base + SCLK_DIVIDER, 0, 8,
0, &sysrate_lock);
*dt_clk = clk;
}
} else {
dt_clk = tegra_lookup_dt_id(tegra_clk_sclk, tegra_clks);
if (dt_clk) {
clk = tegra_clk_register_super_mux("sclk",
gen_info->sclk_parents,
gen_info->num_sclk_parents,
CLK_SET_RATE_PARENT,
clk_base + SCLK_BURST_POLICY,
0, 4, 0, 0, NULL);
*dt_clk = clk;
}
}
dt_clk = tegra_lookup_dt_id(tegra_clk_hclk, tegra_clks);
if (dt_clk) {
clk = clk_register_divider(NULL, "hclk_div", "sclk", 0,
clk_base + SYSTEM_CLK_RATE, 4, 2, 0,
&sysrate_lock);
clk = clk_register_gate(NULL, "hclk", "hclk_div",
CLK_SET_RATE_PARENT | CLK_IGNORE_UNUSED,
clk_base + SYSTEM_CLK_RATE,
7, CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
*dt_clk = clk;
}
dt_clk = tegra_lookup_dt_id(tegra_clk_pclk, tegra_clks);
if (!dt_clk)
return;
clk = clk_register_divider(NULL, "pclk_div", "hclk", 0,
clk_base + SYSTEM_CLK_RATE, 0, 2, 0,
&sysrate_lock);
clk = clk_register_gate(NULL, "pclk", "pclk_div", CLK_SET_RATE_PARENT |
CLK_IGNORE_UNUSED, clk_base + SYSTEM_CLK_RATE,
3, CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
*dt_clk = clk;
}
static void __init tegra_super_clk_init(void __iomem *clk_base,
void __iomem *pmc_base,
struct tegra_clk *tegra_clks,
struct tegra_clk_pll_params *params,
const struct tegra_super_gen_info *gen_info)
{
struct clk *clk;
struct clk **dt_clk;
dt_clk = tegra_lookup_dt_id(tegra_clk_cclk_g, tegra_clks);
if (dt_clk) {
if (gen_info->gen == gen5) {
clk = tegra_clk_register_super_mux("cclk_g",
gen_info->cclk_g_parents,
gen_info->num_cclk_g_parents,
CLK_SET_RATE_PARENT,
clk_base + CCLKG_BURST_POLICY,
0, 4, 8, 0, NULL);
} else {
clk = tegra_clk_register_super_mux("cclk_g",
gen_info->cclk_g_parents,
gen_info->num_cclk_g_parents,
CLK_SET_RATE_PARENT,
clk_base + CCLKG_BURST_POLICY,
0, 4, 0, 0, NULL);
}
*dt_clk = clk;
}
dt_clk = tegra_lookup_dt_id(tegra_clk_cclk_lp, tegra_clks);
if (dt_clk) {
if (gen_info->gen == gen5) {
clk = tegra_clk_register_super_mux("cclk_lp",
gen_info->cclk_lp_parents,
gen_info->num_cclk_lp_parents,
CLK_SET_RATE_PARENT,
clk_base + CCLKLP_BURST_POLICY,
0, 4, 8, 0, NULL);
} else {
clk = tegra_clk_register_super_mux("cclk_lp",
gen_info->cclk_lp_parents,
gen_info->num_cclk_lp_parents,
CLK_SET_RATE_PARENT,
clk_base + CCLKLP_BURST_POLICY,
TEGRA_DIVIDER_2, 4, 8, 9, NULL);
}
*dt_clk = clk;
}
tegra_sclk_init(clk_base, tegra_clks, gen_info);
#if defined(CONFIG_ARCH_TEGRA_114_SOC) || \
defined(CONFIG_ARCH_TEGRA_124_SOC) || \
defined(CONFIG_ARCH_TEGRA_210_SOC)
dt_clk = tegra_lookup_dt_id(tegra_clk_pll_x, tegra_clks);
if (!dt_clk)
return;
#if defined(CONFIG_ARCH_TEGRA_210_SOC)
if (gen_info->gen == gen5)
clk = tegra_clk_register_pllc_tegra210("pll_x", "pll_ref",
clk_base, pmc_base, CLK_IGNORE_UNUSED, params, NULL);
else
#endif
clk = tegra_clk_register_pllxc("pll_x", "pll_ref", clk_base,
pmc_base, CLK_IGNORE_UNUSED, params, NULL);
*dt_clk = clk;
dt_clk = tegra_lookup_dt_id(tegra_clk_pll_x_out0, tegra_clks);
if (!dt_clk)
return;
clk = clk_register_fixed_factor(NULL, "pll_x_out0", "pll_x",
CLK_SET_RATE_PARENT, 1, 2);
*dt_clk = clk;
#endif
}
void __init tegra_super_clk_gen4_init(void __iomem *clk_base,
void __iomem *pmc_base,
struct tegra_clk *tegra_clks,
struct tegra_clk_pll_params *params)
{
tegra_super_clk_init(clk_base, pmc_base, tegra_clks, params,
&tegra_super_gen_info_gen4);
}
void __init tegra_super_clk_gen5_init(void __iomem *clk_base,
void __iomem *pmc_base,
struct tegra_clk *tegra_clks,
struct tegra_clk_pll_params *params)
{
tegra_super_clk_init(clk_base, pmc_base, tegra_clks, params,
&tegra_super_gen_info_gen5);
}
