static void tegra124_utmi_param_configure(void __iomem *clk_base)
{
unsigned int i;
u32 reg;
for (i = 0; i < ARRAY_SIZE(utmi_parameters); i++) {
if (osc_freq == utmi_parameters[i].osc_frequency)
break;
}
if (i >= ARRAY_SIZE(utmi_parameters)) {
pr_err("%s: Unexpected oscillator freq %lu\n", __func__,
osc_freq);
return;
}
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG2);
reg &= ~UTMIP_PLL_CFG2_STABLE_COUNT(~0);
reg |= UTMIP_PLL_CFG2_STABLE_COUNT(utmi_parameters[i].stable_count);
reg &= ~UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(~0);
reg |= UTMIP_PLL_CFG2_ACTIVE_DLY_COUNT(utmi_parameters[i].
active_delay_count);
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_A_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_B_POWERDOWN;
reg &= ~UTMIP_PLL_CFG2_FORCE_PD_SAMP_C_POWERDOWN;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG2);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG1);
reg &= ~UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(~0);
reg |= UTMIP_PLL_CFG1_ENABLE_DLY_COUNT(utmi_parameters[i].
enable_delay_count);
reg &= ~UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(~0);
reg |= UTMIP_PLL_CFG1_XTAL_FREQ_COUNT(utmi_parameters[i].
xtal_freq_count);
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERDOWN;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ACTIVE_POWERDOWN;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLLU_POWERUP;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLLU_POWERDOWN;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG1);
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg |= UTMIPLL_HW_PWRDN_CFG0_USE_LOCKDET;
reg &= ~UTMIPLL_HW_PWRDN_CFG0_CLK_ENABLE_SWCTL;
reg |= UTMIPLL_HW_PWRDN_CFG0_SEQ_START_STATE;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg = readl_relaxed(clk_base + UTMIP_PLL_CFG1);
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERUP;
reg &= ~UTMIP_PLL_CFG1_FORCE_PLL_ENABLE_POWERDOWN;
writel_relaxed(reg, clk_base + UTMIP_PLL_CFG1);
udelay(1);
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg |= UTMIPLL_HW_PWRDN_CFG0_IDDQ_SWCTL;
reg &= ~UTMIPLL_HW_PWRDN_CFG0_IDDQ_OVERRIDE;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
udelay(1);
reg = readl_relaxed(clk_base + UTMIPLL_HW_PWRDN_CFG0);
reg |= UTMIPLL_HW_PWRDN_CFG0_SEQ_ENABLE;
writel_relaxed(reg, clk_base + UTMIPLL_HW_PWRDN_CFG0);
}
static __init void tegra124_periph_clk_init(void __iomem *clk_base,
void __iomem *pmc_base)
{
struct clk *clk;
clk = clk_register_fixed_factor(NULL, "xusb_ss_div2", "xusb_ss_src", 0,
1, 2);
clks[TEGRA124_CLK_XUSB_SS_DIV2] = clk;
clk = tegra_clk_register_periph_fixed("dpaux", "pll_p", 0, clk_base,
1, 17, 181);
clks[TEGRA124_CLK_DPAUX] = clk;
clk = clk_register_gate(NULL, "pll_d_dsi_out", "pll_d_out0", 0,
clk_base + PLLD_MISC, 30, 0, &pll_d_lock);
clks[TEGRA124_CLK_PLL_D_DSI_OUT] = clk;
clk = tegra_clk_register_periph_gate("dsia", "pll_d_dsi_out", 0,
clk_base, 0, 48,
periph_clk_enb_refcnt);
clks[TEGRA124_CLK_DSIA] = clk;
clk = tegra_clk_register_periph_gate("dsib", "pll_d_dsi_out", 0,
clk_base, 0, 82,
periph_clk_enb_refcnt);
clks[TEGRA124_CLK_DSIB] = clk;
clk = tegra_clk_register_mc("mc", "emc", clk_base + CLK_SOURCE_EMC,
&emc_lock);
clks[TEGRA124_CLK_MC] = clk;
clk = clk_register_gate(NULL, "cml0", "pll_e", 0, clk_base + PLLE_AUX,
0, 0, &pll_e_lock);
clk_register_clkdev(clk, "cml0", NULL);
clks[TEGRA124_CLK_CML0] = clk;
clk = clk_register_gate(NULL, "cml1", "pll_e", 0, clk_base + PLLE_AUX,
1, 0, &pll_e_lock);
clk_register_clkdev(clk, "cml1", NULL);
clks[TEGRA124_CLK_CML1] = clk;
tegra_periph_clk_init(clk_base, pmc_base, tegra124_clks, &pll_p_params);
}
static void __init tegra124_pll_init(void __iomem *clk_base,
void __iomem *pmc)
{
u32 val;
struct clk *clk;
clk = tegra_clk_register_pllxc("pll_c", "pll_ref", clk_base,
pmc, 0, &pll_c_params, NULL);
clk_register_clkdev(clk, "pll_c", NULL);
clks[TEGRA124_CLK_PLL_C] = clk;
clk = tegra_clk_register_divider("pll_c_out1_div", "pll_c",
clk_base + PLLC_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c_out1", "pll_c_out1_div",
clk_base + PLLC_OUT, 1, 0,
CLK_SET_RATE_PARENT, 0, NULL);
clk_register_clkdev(clk, "pll_c_out1", NULL);
clks[TEGRA124_CLK_PLL_C_OUT1] = clk;
clk = clk_register_fixed_factor(NULL, "pll_c_ud", "pll_c",
CLK_SET_RATE_PARENT, 1, 1);
clk_register_clkdev(clk, "pll_c_ud", NULL);
clks[TEGRA124_CLK_PLL_C_UD] = clk;
clk = tegra_clk_register_pllc("pll_c2", "pll_ref", clk_base, pmc, 0,
&pll_c2_params, NULL);
clk_register_clkdev(clk, "pll_c2", NULL);
clks[TEGRA124_CLK_PLL_C2] = clk;
clk = tegra_clk_register_pllc("pll_c3", "pll_ref", clk_base, pmc, 0,
&pll_c3_params, NULL);
clk_register_clkdev(clk, "pll_c3", NULL);
clks[TEGRA124_CLK_PLL_C3] = clk;
clk = tegra_clk_register_pllm("pll_m", "pll_ref", clk_base, pmc,
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE,
&pll_m_params, NULL);
clk_register_clkdev(clk, "pll_m", NULL);
clks[TEGRA124_CLK_PLL_M] = clk;
clk = tegra_clk_register_divider("pll_m_out1_div", "pll_m",
clk_base + PLLM_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_m_out1", "pll_m_out1_div",
clk_base + PLLM_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
clk_register_clkdev(clk, "pll_m_out1", NULL);
clks[TEGRA124_CLK_PLL_M_OUT1] = clk;
clk = clk_register_fixed_factor(NULL, "pll_m_ud", "pll_m",
CLK_SET_RATE_PARENT, 1, 1);
clk_register_clkdev(clk, "pll_m_ud", NULL);
clks[TEGRA124_CLK_PLL_M_UD] = clk;
val = readl(clk_base + pll_u_params.base_reg);
val &= ~BIT(24);
writel(val, clk_base + pll_u_params.base_reg);
clk = tegra_clk_register_pll("pll_u", "pll_ref", clk_base, pmc, 0,
&pll_u_params, &pll_u_lock);
clk_register_clkdev(clk, "pll_u", NULL);
clks[TEGRA124_CLK_PLL_U] = clk;
tegra124_utmi_param_configure(clk_base);
clk = clk_register_gate(NULL, "pll_u_480M", "pll_u",
CLK_SET_RATE_PARENT, clk_base + PLLU_BASE,
22, 0, &pll_u_lock);
clk_register_clkdev(clk, "pll_u_480M", NULL);
clks[TEGRA124_CLK_PLL_U_480M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_60M", "pll_u",
CLK_SET_RATE_PARENT, 1, 8);
clk_register_clkdev(clk, "pll_u_60M", NULL);
clks[TEGRA124_CLK_PLL_U_60M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_48M", "pll_u",
CLK_SET_RATE_PARENT, 1, 10);
clk_register_clkdev(clk, "pll_u_48M", NULL);
clks[TEGRA124_CLK_PLL_U_48M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_12M", "pll_u",
CLK_SET_RATE_PARENT, 1, 40);
clk_register_clkdev(clk, "pll_u_12M", NULL);
clks[TEGRA124_CLK_PLL_U_12M] = clk;
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, pmc, 0,
&pll_d_params, &pll_d_lock);
clk_register_clkdev(clk, "pll_d", NULL);
clks[TEGRA124_CLK_PLL_D] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_d_out0", NULL);
clks[TEGRA124_CLK_PLL_D_OUT0] = clk;
clk = tegra_clk_register_pllre("pll_re_vco", "pll_ref", clk_base, pmc,
0, &pll_re_vco_params, &pll_re_lock, pll_ref_freq);
clk_register_clkdev(clk, "pll_re_vco", NULL);
clks[TEGRA124_CLK_PLL_RE_VCO] = clk;
clk = clk_register_divider_table(NULL, "pll_re_out", "pll_re_vco", 0,
clk_base + PLLRE_BASE, 16, 4, 0,
pll_re_div_table, &pll_re_lock);
clk_register_clkdev(clk, "pll_re_out", NULL);
clks[TEGRA124_CLK_PLL_RE_OUT] = clk;
clk = tegra_clk_register_plle_tegra114("pll_e", "pll_ref",
clk_base, 0, &pll_e_params, NULL);
clk_register_clkdev(clk, "pll_e", NULL);
clks[TEGRA124_CLK_PLL_E] = clk;
clk = tegra_clk_register_pllss("pll_c4", "pll_ref", clk_base, 0,
&pll_c4_params, NULL);
clk_register_clkdev(clk, "pll_c4", NULL);
clks[TEGRA124_CLK_PLL_C4] = clk;
clk = tegra_clk_register_pllss("pll_dp", "pll_ref", clk_base, 0,
&pll_dp_params, NULL);
clk_register_clkdev(clk, "pll_dp", NULL);
clks[TEGRA124_CLK_PLL_DP] = clk;
clk = tegra_clk_register_pllss("pll_d2", "pll_ref", clk_base, 0,
&tegra124_pll_d2_params, NULL);
clk_register_clkdev(clk, "pll_d2", NULL);
clks[TEGRA124_CLK_PLL_D2] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d2_out0", "pll_d2",
CLK_SET_RATE_PARENT, 1, 1);
clk_register_clkdev(clk, "pll_d2_out0", NULL);
clks[TEGRA124_CLK_PLL_D2_OUT0] = clk;
}
static void tegra124_wait_cpu_in_reset(u32 cpu)
{
unsigned int reg;
do {
reg = readl(clk_base + CLK_RST_CONTROLLER_CPU_CMPLX_STATUS);
cpu_relax();
} while (!(reg & (1 << cpu)));
}
static void tegra124_disable_cpu_clock(u32 cpu)
{
}
static void tegra124_cpu_clock_suspend(void)
{
tegra124_cpu_clk_sctx.clk_csite_src =
readl(clk_base + CLK_SOURCE_CSITE);
writel(3 << 30, clk_base + CLK_SOURCE_CSITE);
tegra124_cpu_clk_sctx.cclkg_burst =
readl(clk_base + CCLKG_BURST_POLICY);
tegra124_cpu_clk_sctx.cclkg_divider =
readl(clk_base + CCLKG_BURST_POLICY + 4);
}
static void tegra124_cpu_clock_resume(void)
{
writel(tegra124_cpu_clk_sctx.clk_csite_src,
clk_base + CLK_SOURCE_CSITE);
writel(tegra124_cpu_clk_sctx.cclkg_burst,
clk_base + CCLKG_BURST_POLICY);
writel(tegra124_cpu_clk_sctx.cclkg_divider,
clk_base + CCLKG_BURST_POLICY + 4);
}
static void __init tegra124_clock_apply_init_table(void)
{
tegra_init_from_table(common_init_table, clks, TEGRA124_CLK_CLK_MAX);
tegra_init_from_table(tegra124_init_table, clks, TEGRA124_CLK_CLK_MAX);
}
static void tegra124_car_barrier(void)
{
readl_relaxed(clk_base + RST_DFLL_DVCO);
}
static void tegra124_clock_assert_dfll_dvco_reset(void)
{
u32 v;
v = readl_relaxed(clk_base + RST_DFLL_DVCO);
v |= (1 << DVFS_DFLL_RESET_SHIFT);
writel_relaxed(v, clk_base + RST_DFLL_DVCO);
tegra124_car_barrier();
}
static void tegra124_clock_deassert_dfll_dvco_reset(void)
{
u32 v;
v = readl_relaxed(clk_base + RST_DFLL_DVCO);
v &= ~(1 << DVFS_DFLL_RESET_SHIFT);
writel_relaxed(v, clk_base + RST_DFLL_DVCO);
tegra124_car_barrier();
}
static int tegra124_reset_assert(unsigned long id)
{
if (id == TEGRA124_RST_DFLL_DVCO)
tegra124_clock_assert_dfll_dvco_reset();
else
return -EINVAL;
return 0;
}
static int tegra124_reset_deassert(unsigned long id)
{
if (id == TEGRA124_RST_DFLL_DVCO)
tegra124_clock_deassert_dfll_dvco_reset();
else
return -EINVAL;
return 0;
}
static void __init tegra132_clock_apply_init_table(void)
{
tegra_init_from_table(common_init_table, clks, TEGRA124_CLK_CLK_MAX);
tegra_init_from_table(tegra132_init_table, clks, TEGRA124_CLK_CLK_MAX);
}
static void __init tegra124_132_clock_init_pre(struct device_node *np)
{
struct device_node *node;
u32 plld_base;
clk_base = of_iomap(np, 0);
if (!clk_base) {
pr_err("ioremap tegra124/tegra132 CAR failed\n");
return;
}
node = of_find_matching_node(NULL, pmc_match);
if (!node) {
pr_err("Failed to find pmc node\n");
WARN_ON(1);
return;
}
pmc_base = of_iomap(node, 0);
if (!pmc_base) {
pr_err("Can't map pmc registers\n");
WARN_ON(1);
return;
}
clks = tegra_clk_init(clk_base, TEGRA124_CLK_CLK_MAX,
TEGRA124_CAR_BANK_COUNT);
if (!clks)
return;
if (tegra_osc_clk_init(clk_base, tegra124_clks, tegra124_input_freq,
ARRAY_SIZE(tegra124_input_freq), 1, &osc_freq,
&pll_ref_freq) < 0)
return;
tegra_fixed_clk_init(tegra124_clks);
tegra124_pll_init(clk_base, pmc_base);
tegra124_periph_clk_init(clk_base, pmc_base);
tegra_audio_clk_init(clk_base, pmc_base, tegra124_clks,
tegra124_audio_plls,
ARRAY_SIZE(tegra124_audio_plls));
tegra_pmc_clk_init(pmc_base, tegra124_clks);
plld_base = clk_readl(clk_base + PLLD_BASE);
plld_base &= ~BIT(25);
clk_writel(plld_base, clk_base + PLLD_BASE);
}
static void __init tegra124_132_clock_init_post(struct device_node *np)
{
tegra_super_clk_gen4_init(clk_base, pmc_base, tegra124_clks,
&pll_x_params);
tegra_init_special_resets(1, tegra124_reset_assert,
tegra124_reset_deassert);
tegra_add_of_provider(np);
clks[TEGRA124_CLK_EMC] = tegra_clk_register_emc(clk_base, np,
&emc_lock);
tegra_register_devclks(devclks, ARRAY_SIZE(devclks));
tegra_cpu_car_ops = &tegra124_cpu_car_ops;
}
static void __init tegra124_clock_init(struct device_node *np)
{
tegra124_132_clock_init_pre(np);
tegra_clk_apply_init_table = tegra124_clock_apply_init_table;
tegra124_132_clock_init_post(np);
}
static void __init tegra132_clock_init(struct device_node *np)
{
tegra124_132_clock_init_pre(np);
tegra124_clks[tegra_clk_cclk_g].present = false;
tegra124_clks[tegra_clk_cclk_lp].present = false;
tegra124_clks[tegra_clk_pll_x].present = false;
tegra124_clks[tegra_clk_pll_x_out0].present = false;
tegra_clk_apply_init_table = tegra132_clock_apply_init_table;
tegra124_132_clock_init_post(np);
}
