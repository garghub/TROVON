static void tegra30_utmi_param_configure(void)
{
u32 reg;
int i;
for (i = 0; i < ARRAY_SIZE(utmi_parameters); i++) {
if (input_freq == utmi_parameters[i].osc_frequency)
break;
}
if (i >= ARRAY_SIZE(utmi_parameters)) {
pr_err("%s: Unexpected input rate %lu\n", __func__, input_freq);
return;
}
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG2);
reg &= ~UTMIP_PLL_CFG2_STABLE_COUNT(~0);
reg |= UTMIP_PLL_CFG2_STABLE_COUNT(
utmi_parameters[i].stable_count);
reg &= ~UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(~0);
reg |= UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(
utmi_parameters[i].active_delay_count);
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_A_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_B_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_C_POWERDOWN;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG2);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG1);
reg &= ~UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(~0);
reg |= UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(
utmi_parameters[i].enable_delay_count);
reg &= ~UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(~0);
reg |= UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(
utmi_parameters[i].xtal_freq_count);
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERDOWN;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ACTIVE_POWERDOWN;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLLU_POWERDOWN;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG1);
}
static void __init tegra30_pll_init(void)
{
struct clk *clk;
clk = tegra_clk_register_pll("pll_c", "pll_ref", clk_base, pmc_base, 0,
&pll_c_params, NULL);
clks[TEGRA30_CLK_PLL_C] = clk;
clk = tegra_clk_register_divider("pll_c_out1_div", "pll_c",
clk_base + PLLC_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c_out1", "pll_c_out1_div",
clk_base + PLLC_OUT, 1, 0, CLK_SET_RATE_PARENT,
0, NULL);
clks[TEGRA30_CLK_PLL_C_OUT1] = clk;
clk = tegra_clk_register_pll("pll_m", "pll_ref", clk_base, pmc_base,
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE,
&pll_m_params, NULL);
clks[TEGRA30_CLK_PLL_M] = clk;
clk = tegra_clk_register_divider("pll_m_out1_div", "pll_m",
clk_base + PLLM_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_m_out1", "pll_m_out1_div",
clk_base + PLLM_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
clks[TEGRA30_CLK_PLL_M_OUT1] = clk;
clk = tegra_clk_register_pll("pll_x", "pll_ref", clk_base, pmc_base, 0,
&pll_x_params, NULL);
clks[TEGRA30_CLK_PLL_X] = clk;
clk = clk_register_fixed_factor(NULL, "pll_x_out0", "pll_x",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA30_CLK_PLL_X_OUT0] = clk;
clk = tegra_clk_register_pll("pll_u", "pll_ref", clk_base, pmc_base, 0,
&pll_u_params, NULL);
clks[TEGRA30_CLK_PLL_U] = clk;
tegra30_utmi_param_configure();
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, pmc_base, 0,
&pll_d_params, &pll_d_lock);
clks[TEGRA30_CLK_PLL_D] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA30_CLK_PLL_D_OUT0] = clk;
clk = tegra_clk_register_pll("pll_d2", "pll_ref", clk_base, pmc_base, 0,
&pll_d2_params, NULL);
clks[TEGRA30_CLK_PLL_D2] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d2_out0", "pll_d2",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA30_CLK_PLL_D2_OUT0] = clk;
clk = clk_register_mux(NULL, "pll_e_mux", pll_e_parents,
ARRAY_SIZE(pll_e_parents),
CLK_SET_RATE_NO_REPARENT,
clk_base + PLLE_AUX, 2, 1, 0, NULL);
clk = tegra_clk_register_plle("pll_e", "pll_e_mux", clk_base, pmc_base,
CLK_GET_RATE_NOCACHE, &pll_e_params, NULL);
clks[TEGRA30_CLK_PLL_E] = clk;
}
static void __init tegra30_super_clk_init(void)
{
struct clk *clk;
clk = tegra_clk_register_divider("pll_p_cclkg", "pll_p",
clk_base + SUPER_CCLKG_DIVIDER, 0,
TEGRA_DIVIDER_INT, 16, 8, 1, NULL);
clk_register_clkdev(clk, "pll_p_cclkg", NULL);
clk = tegra_clk_register_divider("pll_p_out3_cclkg", "pll_p_out3",
clk_base + SUPER_CCLKG_DIVIDER, 0,
TEGRA_DIVIDER_INT, 16, 8, 1, NULL);
clk_register_clkdev(clk, "pll_p_out3_cclkg", NULL);
clk = tegra_clk_register_divider("pll_p_out4_cclkg", "pll_p_out4",
clk_base + SUPER_CCLKG_DIVIDER, 0,
TEGRA_DIVIDER_INT, 16, 8, 1, NULL);
clk_register_clkdev(clk, "pll_p_out4_cclkg", NULL);
clk = tegra_clk_register_super_mux("cclk_g", cclk_g_parents,
ARRAY_SIZE(cclk_g_parents),
CLK_SET_RATE_PARENT,
clk_base + CCLKG_BURST_POLICY,
0, 4, 0, 0, NULL);
clks[TEGRA30_CLK_CCLK_G] = clk;
clk = tegra_clk_register_divider("pll_p_cclklp", "pll_p",
clk_base + SUPER_CCLKLP_DIVIDER, 0,
TEGRA_DIVIDER_INT, 16, 8, 1, NULL);
clk_register_clkdev(clk, "pll_p_cclklp", NULL);
clk = tegra_clk_register_divider("pll_p_out3_cclklp", "pll_p_out3",
clk_base + SUPER_CCLKG_DIVIDER, 0,
TEGRA_DIVIDER_INT, 16, 8, 1, NULL);
clk_register_clkdev(clk, "pll_p_out3_cclklp", NULL);
clk = tegra_clk_register_divider("pll_p_out4_cclklp", "pll_p_out4",
clk_base + SUPER_CCLKLP_DIVIDER, 0,
TEGRA_DIVIDER_INT, 16, 8, 1, NULL);
clk_register_clkdev(clk, "pll_p_out4_cclklp", NULL);
clk = tegra_clk_register_super_mux("cclk_lp", cclk_lp_parents,
ARRAY_SIZE(cclk_lp_parents),
CLK_SET_RATE_PARENT,
clk_base + CCLKLP_BURST_POLICY,
TEGRA_DIVIDER_2, 4, 8, 9,
NULL);
clks[TEGRA30_CLK_CCLK_LP] = clk;
clk = tegra_clk_register_super_mux("sclk", sclk_parents,
ARRAY_SIZE(sclk_parents),
CLK_SET_RATE_PARENT,
clk_base + SCLK_BURST_POLICY,
0, 4, 0, 0, NULL);
clks[TEGRA30_CLK_SCLK] = clk;
clk = clk_register_fixed_factor(NULL, "twd", "cclk_g",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA30_CLK_TWD] = clk;
tegra_super_clk_gen4_init(clk_base, pmc_base, tegra30_clks, NULL);
}
static void __init tegra30_periph_clk_init(void)
{
struct tegra_periph_init_data *data;
struct clk *clk;
int i;
clk = tegra_clk_register_periph_gate("dsia", "pll_d_out0", 0, clk_base,
0, 48, periph_clk_enb_refcnt);
clks[TEGRA30_CLK_DSIA] = clk;
clk = tegra_clk_register_periph_gate("pcie", "clk_m", 0, clk_base, 0,
70, periph_clk_enb_refcnt);
clks[TEGRA30_CLK_PCIE] = clk;
clk = tegra_clk_register_periph_gate("afi", "clk_m", 0, clk_base, 0, 72,
periph_clk_enb_refcnt);
clks[TEGRA30_CLK_AFI] = clk;
clk = clk_register_mux(NULL, "emc_mux", mux_pllmcp_clkm,
ARRAY_SIZE(mux_pllmcp_clkm),
CLK_SET_RATE_NO_REPARENT,
clk_base + CLK_SOURCE_EMC,
30, 2, 0, &emc_lock);
clk = tegra_clk_register_periph_gate("emc", "emc_mux", 0, clk_base, 0,
57, periph_clk_enb_refcnt);
clks[TEGRA30_CLK_EMC] = clk;
clk = tegra_clk_register_mc("mc", "emc_mux", clk_base + CLK_SOURCE_EMC,
&emc_lock);
clks[TEGRA30_CLK_MC] = clk;
clk = clk_register_gate(NULL, "cml0", "pll_e", 0, clk_base + PLLE_AUX,
0, 0, &cml_lock);
clks[TEGRA30_CLK_CML0] = clk;
clk = clk_register_gate(NULL, "cml1", "pll_e", 0, clk_base + PLLE_AUX,
1, 0, &cml_lock);
clks[TEGRA30_CLK_CML1] = clk;
for (i = 0; i < ARRAY_SIZE(tegra_periph_clk_list); i++) {
data = &tegra_periph_clk_list[i];
clk = tegra_clk_register_periph(data->name, data->p.parent_names,
data->num_parents, &data->periph,
clk_base, data->offset, data->flags);
clks[data->clk_id] = clk;
}
for (i = 0; i < ARRAY_SIZE(tegra_periph_nodiv_clk_list); i++) {
data = &tegra_periph_nodiv_clk_list[i];
clk = tegra_clk_register_periph_nodiv(data->name,
data->p.parent_names,
data->num_parents, &data->periph,
clk_base, data->offset);
clks[data->clk_id] = clk;
}
tegra_periph_clk_init(clk_base, pmc_base, tegra30_clks, &pll_p_params);
}
static void tegra30_wait_cpu_in_reset(u32 cpu)
{
unsigned int reg;
do {
reg = readl(clk_base +
TEGRA30_CLK_RST_CONTROLLER_CPU_CMPLX_STATUS);
cpu_relax();
} while (!(reg & (1 << cpu)));
return;
}
static void tegra30_put_cpu_in_reset(u32 cpu)
{
writel(CPU_RESET(cpu),
clk_base + TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET);
dmb();
}
static void tegra30_cpu_out_of_reset(u32 cpu)
{
writel(CPU_RESET(cpu),
clk_base + TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_CLR);
wmb();
}
static void tegra30_enable_cpu_clock(u32 cpu)
{
unsigned int reg;
writel(CPU_CLOCK(cpu),
clk_base + TEGRA30_CLK_RST_CONTROLLER_CLK_CPU_CMPLX_CLR);
reg = readl(clk_base +
TEGRA30_CLK_RST_CONTROLLER_CLK_CPU_CMPLX_CLR);
}
static void tegra30_disable_cpu_clock(u32 cpu)
{
unsigned int reg;
reg = readl(clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
writel(reg | CPU_CLOCK(cpu),
clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
}
static bool tegra30_cpu_rail_off_ready(void)
{
unsigned int cpu_rst_status;
int cpu_pwr_status;
cpu_rst_status = readl(clk_base +
TEGRA30_CLK_RST_CONTROLLER_CPU_CMPLX_STATUS);
cpu_pwr_status = tegra_powergate_is_powered(TEGRA_POWERGATE_CPU1) ||
tegra_powergate_is_powered(TEGRA_POWERGATE_CPU2) ||
tegra_powergate_is_powered(TEGRA_POWERGATE_CPU3);
if (((cpu_rst_status & 0xE) != 0xE) || cpu_pwr_status)
return false;
return true;
}
static void tegra30_cpu_clock_suspend(void)
{
tegra30_cpu_clk_sctx.clk_csite_src =
readl(clk_base + CLK_RESET_SOURCE_CSITE);
writel(3<<30, clk_base + CLK_RESET_SOURCE_CSITE);
tegra30_cpu_clk_sctx.cpu_burst =
readl(clk_base + CLK_RESET_CCLK_BURST);
tegra30_cpu_clk_sctx.pllx_base =
readl(clk_base + CLK_RESET_PLLX_BASE);
tegra30_cpu_clk_sctx.pllx_misc =
readl(clk_base + CLK_RESET_PLLX_MISC);
tegra30_cpu_clk_sctx.cclk_divider =
readl(clk_base + CLK_RESET_CCLK_DIVIDER);
}
static void tegra30_cpu_clock_resume(void)
{
unsigned int reg, policy;
reg = readl(clk_base + CLK_RESET_CCLK_BURST);
policy = (reg >> CLK_RESET_CCLK_BURST_POLICY_SHIFT) & 0xF;
if (policy == CLK_RESET_CCLK_IDLE_POLICY)
reg = (reg >> CLK_RESET_CCLK_IDLE_POLICY_SHIFT) & 0xF;
else if (policy == CLK_RESET_CCLK_RUN_POLICY)
reg = (reg >> CLK_RESET_CCLK_RUN_POLICY_SHIFT) & 0xF;
else
BUG();
if (reg != CLK_RESET_CCLK_BURST_POLICY_PLLX) {
writel(tegra30_cpu_clk_sctx.pllx_misc,
clk_base + CLK_RESET_PLLX_MISC);
writel(tegra30_cpu_clk_sctx.pllx_base,
clk_base + CLK_RESET_PLLX_BASE);
if (tegra30_cpu_clk_sctx.pllx_base & (1 << 30))
udelay(300);
}
writel(tegra30_cpu_clk_sctx.cclk_divider,
clk_base + CLK_RESET_CCLK_DIVIDER);
writel(tegra30_cpu_clk_sctx.cpu_burst,
clk_base + CLK_RESET_CCLK_BURST);
writel(tegra30_cpu_clk_sctx.clk_csite_src,
clk_base + CLK_RESET_SOURCE_CSITE);
}
static void __init tegra30_clock_apply_init_table(void)
{
tegra_init_from_table(init_table, clks, TEGRA30_CLK_CLK_MAX);
}
static void __init tegra30_clock_init(struct device_node *np)
{
struct device_node *node;
clk_base = of_iomap(np, 0);
if (!clk_base) {
pr_err("ioremap tegra30 CAR failed\n");
return;
}
node = of_find_matching_node(NULL, pmc_match);
if (!node) {
pr_err("Failed to find pmc node\n");
BUG();
}
pmc_base = of_iomap(node, 0);
if (!pmc_base) {
pr_err("Can't map pmc registers\n");
BUG();
}
clks = tegra_clk_init(clk_base, TEGRA30_CLK_CLK_MAX,
TEGRA30_CLK_PERIPH_BANKS);
if (!clks)
return;
if (tegra_osc_clk_init(clk_base, tegra30_clks, tegra30_input_freq,
ARRAY_SIZE(tegra30_input_freq), 1, &input_freq,
NULL) < 0)
return;
tegra_fixed_clk_init(tegra30_clks);
tegra30_pll_init();
tegra30_super_clk_init();
tegra30_periph_clk_init();
tegra_audio_clk_init(clk_base, pmc_base, tegra30_clks, &pll_a_params);
tegra_pmc_clk_init(pmc_base, tegra30_clks);
tegra_init_dup_clks(tegra_clk_duplicates, clks, TEGRA30_CLK_CLK_MAX);
tegra_add_of_provider(np);
tegra_register_devclks(devclks, ARRAY_SIZE(devclks));
tegra_clk_apply_init_table = tegra30_clock_apply_init_table;
tegra_cpu_car_ops = &tegra30_cpu_car_ops;
}
