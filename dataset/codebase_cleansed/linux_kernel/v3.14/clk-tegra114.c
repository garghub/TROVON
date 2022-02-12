static int __init tegra114_osc_clk_init(void __iomem *clk_base)
{
struct clk *clk;
u32 val, pll_ref_div;
val = readl_relaxed(clk_base + OSC_CTRL);
osc_freq = tegra114_input_freq[val >> OSC_CTRL_OSC_FREQ_SHIFT];
if (!osc_freq) {
WARN_ON(1);
return -EINVAL;
}
clk = clk_register_fixed_rate(NULL, "clk_m", NULL, CLK_IS_ROOT,
osc_freq);
clks[TEGRA114_CLK_CLK_M] = clk;
val = (val >> OSC_CTRL_PLL_REF_DIV_SHIFT) & 3;
pll_ref_div = 1 << val;
clk = clk_register_fixed_factor(NULL, "pll_ref", "clk_m",
CLK_SET_RATE_PARENT, 1, pll_ref_div);
clks[TEGRA114_CLK_PLL_REF] = clk;
pll_ref_freq = osc_freq / pll_ref_div;
return 0;
}
static void __init tegra114_fixed_clk_init(void __iomem *clk_base)
{
struct clk *clk;
clk = clk_register_fixed_rate(NULL, "clk_32k", NULL, CLK_IS_ROOT,
32768);
clks[TEGRA114_CLK_CLK_32K] = clk;
clk = clk_register_fixed_factor(NULL, "clk_m_div2", "clk_m",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA114_CLK_CLK_M_DIV2] = clk;
clk = clk_register_fixed_factor(NULL, "clk_m_div4", "clk_m",
CLK_SET_RATE_PARENT, 1, 4);
clks[TEGRA114_CLK_CLK_M_DIV4] = clk;
}
static __init void tegra114_utmi_param_configure(void __iomem *clk_base)
{
u32 reg;
int i;
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
static void __init tegra114_pll_init(void __iomem *clk_base,
void __iomem *pmc)
{
u32 val;
struct clk *clk;
clk = tegra_clk_register_pllxc("pll_c", "pll_ref", clk_base,
pmc, 0, &pll_c_params, NULL);
clks[TEGRA114_CLK_PLL_C] = clk;
clk = tegra_clk_register_divider("pll_c_out1_div", "pll_c",
clk_base + PLLC_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c_out1", "pll_c_out1_div",
clk_base + PLLC_OUT, 1, 0,
CLK_SET_RATE_PARENT, 0, NULL);
clks[TEGRA114_CLK_PLL_C_OUT1] = clk;
clk = tegra_clk_register_pllc("pll_c2", "pll_ref", clk_base, pmc, 0,
&pll_c2_params, NULL);
clks[TEGRA114_CLK_PLL_C2] = clk;
clk = tegra_clk_register_pllc("pll_c3", "pll_ref", clk_base, pmc, 0,
&pll_c3_params, NULL);
clks[TEGRA114_CLK_PLL_C3] = clk;
clk = tegra_clk_register_pllm("pll_m", "pll_ref", clk_base, pmc,
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE,
&pll_m_params, NULL);
clks[TEGRA114_CLK_PLL_M] = clk;
clk = tegra_clk_register_divider("pll_m_out1_div", "pll_m",
clk_base + PLLM_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_m_out1", "pll_m_out1_div",
clk_base + PLLM_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
clks[TEGRA114_CLK_PLL_M_OUT1] = clk;
clk = clk_register_fixed_factor(NULL, "pll_m_ud", "pll_m",
CLK_SET_RATE_PARENT, 1, 1);
val = readl(clk_base + pll_u_params.base_reg);
val &= ~BIT(24);
writel(val, clk_base + pll_u_params.base_reg);
clk = tegra_clk_register_pll("pll_u", "pll_ref", clk_base, pmc, 0,
&pll_u_params, &pll_u_lock);
clks[TEGRA114_CLK_PLL_U] = clk;
tegra114_utmi_param_configure(clk_base);
clk = clk_register_gate(NULL, "pll_u_480M", "pll_u",
CLK_SET_RATE_PARENT, clk_base + PLLU_BASE,
22, 0, &pll_u_lock);
clks[TEGRA114_CLK_PLL_U_480M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_60M", "pll_u",
CLK_SET_RATE_PARENT, 1, 8);
clks[TEGRA114_CLK_PLL_U_60M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_48M", "pll_u",
CLK_SET_RATE_PARENT, 1, 10);
clks[TEGRA114_CLK_PLL_U_48M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_12M", "pll_u",
CLK_SET_RATE_PARENT, 1, 40);
clks[TEGRA114_CLK_PLL_U_12M] = clk;
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, pmc, 0,
&pll_d_params, &pll_d_lock);
clks[TEGRA114_CLK_PLL_D] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA114_CLK_PLL_D_OUT0] = clk;
clk = tegra_clk_register_pll("pll_d2", "pll_ref", clk_base, pmc, 0,
&pll_d2_params, &pll_d2_lock);
clks[TEGRA114_CLK_PLL_D2] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d2_out0", "pll_d2",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA114_CLK_PLL_D2_OUT0] = clk;
clk = tegra_clk_register_pllre("pll_re_vco", "pll_ref", clk_base, pmc,
0, &pll_re_vco_params, &pll_re_lock, pll_ref_freq);
clks[TEGRA114_CLK_PLL_RE_VCO] = clk;
clk = clk_register_divider_table(NULL, "pll_re_out", "pll_re_vco", 0,
clk_base + PLLRE_BASE, 16, 4, 0,
pll_re_div_table, &pll_re_lock);
clks[TEGRA114_CLK_PLL_RE_OUT] = clk;
clk = tegra_clk_register_plle_tegra114("pll_e_out0", "pll_ref",
clk_base, 0, &pll_e_params, NULL);
clks[TEGRA114_CLK_PLL_E_OUT0] = clk;
}
static __init void tegra114_periph_clk_init(void __iomem *clk_base,
void __iomem *pmc_base)
{
struct clk *clk;
u32 val;
val = readl(clk_base + CLK_SOURCE_XUSB_SS_SRC);
val |= BIT(25);
writel(val, clk_base + CLK_SOURCE_XUSB_SS_SRC);
clk = clk_register_fixed_factor(NULL, "xusb_hs_src", "pll_u_60M", 0,
1, 1);
clks[TEGRA114_CLK_XUSB_HS_SRC] = clk;
clk = clk_register_mux(NULL, "dsia_mux", mux_plld_out0_plld2_out0,
ARRAY_SIZE(mux_plld_out0_plld2_out0),
CLK_SET_RATE_NO_REPARENT,
clk_base + PLLD_BASE, 25, 1, 0, &pll_d_lock);
clks[TEGRA114_CLK_DSIA_MUX] = clk;
clk = clk_register_mux(NULL, "dsib_mux", mux_plld_out0_plld2_out0,
ARRAY_SIZE(mux_plld_out0_plld2_out0),
CLK_SET_RATE_NO_REPARENT,
clk_base + PLLD2_BASE, 25, 1, 0, &pll_d2_lock);
clks[TEGRA114_CLK_DSIB_MUX] = clk;
clk = clk_register_mux(NULL, "emc_mux", mux_pllmcp_clkm,
ARRAY_SIZE(mux_pllmcp_clkm),
CLK_SET_RATE_NO_REPARENT,
clk_base + CLK_SOURCE_EMC,
29, 3, 0, NULL);
tegra_periph_clk_init(clk_base, pmc_base, tegra114_clks,
&pll_p_params);
}
static void tegra114_wait_cpu_in_reset(u32 cpu)
{
unsigned int reg;
do {
reg = readl(clk_base + CLK_RST_CONTROLLER_CPU_CMPLX_STATUS);
cpu_relax();
} while (!(reg & (1 << cpu)));
}
static void tegra114_disable_cpu_clock(u32 cpu)
{
}
static void tegra114_cpu_clock_suspend(void)
{
tegra114_cpu_clk_sctx.clk_csite_src =
readl(clk_base + CLK_SOURCE_CSITE);
writel(3 << 30, clk_base + CLK_SOURCE_CSITE);
tegra114_cpu_clk_sctx.cclkg_burst =
readl(clk_base + CCLKG_BURST_POLICY);
tegra114_cpu_clk_sctx.cclkg_divider =
readl(clk_base + CCLKG_BURST_POLICY + 4);
}
static void tegra114_cpu_clock_resume(void)
{
writel(tegra114_cpu_clk_sctx.clk_csite_src,
clk_base + CLK_SOURCE_CSITE);
writel(tegra114_cpu_clk_sctx.cclkg_burst,
clk_base + CCLKG_BURST_POLICY);
writel(tegra114_cpu_clk_sctx.cclkg_divider,
clk_base + CCLKG_BURST_POLICY + 4);
}
static void __init tegra114_clock_apply_init_table(void)
{
tegra_init_from_table(init_table, clks, TEGRA114_CLK_CLK_MAX);
}
static void tegra114_car_barrier(void)
{
wmb();
readl_relaxed(clk_base + CPU_FINETRIM_SELECT);
}
void tegra114_clock_tune_cpu_trimmers_high(void)
{
u32 select = 0;
select |= ~(CPU_FINETRIM_1_FCPU_1 | CPU_FINETRIM_1_FCPU_2 |
CPU_FINETRIM_1_FCPU_3 | CPU_FINETRIM_1_FCPU_4 |
CPU_FINETRIM_1_FCPU_5 | CPU_FINETRIM_1_FCPU_6);
writel_relaxed(select, clk_base + CPU_FINETRIM_SELECT);
tegra114_car_barrier();
}
void tegra114_clock_tune_cpu_trimmers_low(void)
{
u32 select = 0;
select |= (CPU_FINETRIM_1_FCPU_1 | CPU_FINETRIM_1_FCPU_2 |
CPU_FINETRIM_1_FCPU_3 | CPU_FINETRIM_1_FCPU_4 |
CPU_FINETRIM_1_FCPU_5 | CPU_FINETRIM_1_FCPU_6);
writel_relaxed(select, clk_base + CPU_FINETRIM_SELECT);
tegra114_car_barrier();
}
void tegra114_clock_tune_cpu_trimmers_init(void)
{
u32 dr = 0, r = 0;
r |= (CPU_FINETRIM_R_FCPU_1_MASK | CPU_FINETRIM_R_FCPU_2_MASK |
CPU_FINETRIM_R_FCPU_3_MASK | CPU_FINETRIM_R_FCPU_4_MASK |
CPU_FINETRIM_R_FCPU_5_MASK | CPU_FINETRIM_R_FCPU_6_MASK);
writel_relaxed(r, clk_base + CPU_FINETRIM_R);
dr |= (CPU_FINETRIM_1_FCPU_1 | CPU_FINETRIM_1_FCPU_2 |
CPU_FINETRIM_1_FCPU_3 | CPU_FINETRIM_1_FCPU_4 |
CPU_FINETRIM_1_FCPU_5 | CPU_FINETRIM_1_FCPU_6);
writel_relaxed(dr, clk_base + CPU_FINETRIM_DR);
tegra114_clock_tune_cpu_trimmers_low();
}
void tegra114_clock_assert_dfll_dvco_reset(void)
{
u32 v;
v = readl_relaxed(clk_base + RST_DFLL_DVCO);
v |= (1 << DVFS_DFLL_RESET_SHIFT);
writel_relaxed(v, clk_base + RST_DFLL_DVCO);
tegra114_car_barrier();
}
void tegra114_clock_deassert_dfll_dvco_reset(void)
{
u32 v;
v = readl_relaxed(clk_base + RST_DFLL_DVCO);
v &= ~(1 << DVFS_DFLL_RESET_SHIFT);
writel_relaxed(v, clk_base + RST_DFLL_DVCO);
tegra114_car_barrier();
}
static void __init tegra114_clock_init(struct device_node *np)
{
struct device_node *node;
clk_base = of_iomap(np, 0);
if (!clk_base) {
pr_err("ioremap tegra114 CAR failed\n");
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
clks = tegra_clk_init(clk_base, TEGRA114_CLK_CLK_MAX,
TEGRA114_CLK_PERIPH_BANKS);
if (!clks)
return;
if (tegra114_osc_clk_init(clk_base) < 0)
return;
tegra114_fixed_clk_init(clk_base);
tegra114_pll_init(clk_base, pmc_base);
tegra114_periph_clk_init(clk_base, pmc_base);
tegra_audio_clk_init(clk_base, pmc_base, tegra114_clks, &pll_a_params);
tegra_pmc_clk_init(pmc_base, tegra114_clks);
tegra_super_clk_gen4_init(clk_base, pmc_base, tegra114_clks,
&pll_x_params);
tegra_add_of_provider(np);
tegra_register_devclks(devclks, ARRAY_SIZE(devclks));
tegra_clk_apply_init_table = tegra114_clock_apply_init_table;
tegra_cpu_car_ops = &tegra114_cpu_car_ops;
}
