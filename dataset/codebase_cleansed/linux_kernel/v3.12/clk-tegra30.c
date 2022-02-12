static void tegra30_clk_measure_input_freq(void)
{
u32 osc_ctrl = readl_relaxed(clk_base + OSC_CTRL);
u32 auto_clk_control = osc_ctrl & OSC_CTRL_OSC_FREQ_MASK;
u32 pll_ref_div = osc_ctrl & OSC_CTRL_PLL_REF_DIV_MASK;
switch (auto_clk_control) {
case OSC_CTRL_OSC_FREQ_12MHZ:
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
input_freq = 12000000;
break;
case OSC_CTRL_OSC_FREQ_13MHZ:
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
input_freq = 13000000;
break;
case OSC_CTRL_OSC_FREQ_19_2MHZ:
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
input_freq = 19200000;
break;
case OSC_CTRL_OSC_FREQ_26MHZ:
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
input_freq = 26000000;
break;
case OSC_CTRL_OSC_FREQ_16_8MHZ:
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_1);
input_freq = 16800000;
break;
case OSC_CTRL_OSC_FREQ_38_4MHZ:
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_2);
input_freq = 38400000;
break;
case OSC_CTRL_OSC_FREQ_48MHZ:
BUG_ON(pll_ref_div != OSC_CTRL_PLL_REF_DIV_4);
input_freq = 48000000;
break;
default:
pr_err("Unexpected auto clock control value %d",
auto_clk_control);
BUG();
return;
}
}
static unsigned int tegra30_get_pll_ref_div(void)
{
u32 pll_ref_div = readl_relaxed(clk_base + OSC_CTRL) &
OSC_CTRL_PLL_REF_DIV_MASK;
switch (pll_ref_div) {
case OSC_CTRL_PLL_REF_DIV_1:
return 1;
case OSC_CTRL_PLL_REF_DIV_2:
return 2;
case OSC_CTRL_PLL_REF_DIV_4:
return 4;
default:
pr_err("Invalid pll ref divider %d", pll_ref_div);
BUG();
}
return 0;
}
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
0, &pll_c_params,
TEGRA_PLL_HAS_CPCON | TEGRA_PLL_USE_LOCK,
pll_c_freq_table, NULL);
clk_register_clkdev(clk, "pll_c", NULL);
clks[pll_c] = clk;
clk = tegra_clk_register_divider("pll_c_out1_div", "pll_c",
clk_base + PLLC_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c_out1", "pll_c_out1_div",
clk_base + PLLC_OUT, 1, 0, CLK_SET_RATE_PARENT,
0, NULL);
clk_register_clkdev(clk, "pll_c_out1", NULL);
clks[pll_c_out1] = clk;
clk = tegra_clk_register_pll("pll_p", "pll_ref", clk_base, pmc_base, 0,
408000000, &pll_p_params,
TEGRA_PLL_FIXED | TEGRA_PLL_HAS_CPCON |
TEGRA_PLL_USE_LOCK, pll_p_freq_table, NULL);
clk_register_clkdev(clk, "pll_p", NULL);
clks[pll_p] = clk;
clk = tegra_clk_register_divider("pll_p_out1_div", "pll_p",
clk_base + PLLP_OUTA, 0, TEGRA_DIVIDER_FIXED |
TEGRA_DIVIDER_ROUND_UP, 8, 8, 1,
&pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out1", "pll_p_out1_div",
clk_base + PLLP_OUTA, 1, 0,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out1", NULL);
clks[pll_p_out1] = clk;
clk = tegra_clk_register_divider("pll_p_out2_div", "pll_p",
clk_base + PLLP_OUTA, 0, TEGRA_DIVIDER_FIXED |
TEGRA_DIVIDER_ROUND_UP, 24, 8, 1,
&pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out2", "pll_p_out2_div",
clk_base + PLLP_OUTA, 17, 16,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out2", NULL);
clks[pll_p_out2] = clk;
clk = tegra_clk_register_divider("pll_p_out3_div", "pll_p",
clk_base + PLLP_OUTB, 0, TEGRA_DIVIDER_FIXED |
TEGRA_DIVIDER_ROUND_UP, 8, 8, 1,
&pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out3", "pll_p_out3_div",
clk_base + PLLP_OUTB, 1, 0,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out3", NULL);
clks[pll_p_out3] = clk;
clk = tegra_clk_register_divider("pll_p_out4_div", "pll_p",
clk_base + PLLP_OUTB, 0, TEGRA_DIVIDER_FIXED |
TEGRA_DIVIDER_ROUND_UP, 24, 8, 1,
&pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out4", "pll_p_out4_div",
clk_base + PLLP_OUTB, 17, 16,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out4", NULL);
clks[pll_p_out4] = clk;
clk = tegra_clk_register_pll("pll_m", "pll_ref", clk_base, pmc_base,
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE, 0,
&pll_m_params, TEGRA_PLLM | TEGRA_PLL_HAS_CPCON |
TEGRA_PLL_SET_DCCON | TEGRA_PLL_USE_LOCK,
pll_m_freq_table, NULL);
clk_register_clkdev(clk, "pll_m", NULL);
clks[pll_m] = clk;
clk = tegra_clk_register_divider("pll_m_out1_div", "pll_m",
clk_base + PLLM_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_m_out1", "pll_m_out1_div",
clk_base + PLLM_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
clk_register_clkdev(clk, "pll_m_out1", NULL);
clks[pll_m_out1] = clk;
clk = tegra_clk_register_pll("pll_x", "pll_ref", clk_base, pmc_base, 0,
0, &pll_x_params, TEGRA_PLL_HAS_CPCON |
TEGRA_PLL_SET_DCCON | TEGRA_PLL_USE_LOCK,
pll_x_freq_table, NULL);
clk_register_clkdev(clk, "pll_x", NULL);
clks[pll_x] = clk;
clk = clk_register_fixed_factor(NULL, "pll_x_out0", "pll_x",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_x_out0", NULL);
clks[pll_x_out0] = clk;
clk = tegra_clk_register_pll("pll_u", "pll_ref", clk_base, pmc_base, 0,
0, &pll_u_params, TEGRA_PLLU | TEGRA_PLL_HAS_CPCON |
TEGRA_PLL_SET_LFCON,
pll_u_freq_table,
NULL);
clk_register_clkdev(clk, "pll_u", NULL);
clks[pll_u] = clk;
tegra30_utmi_param_configure();
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, pmc_base, 0,
0, &pll_d_params, TEGRA_PLL_HAS_CPCON |
TEGRA_PLL_SET_LFCON | TEGRA_PLL_USE_LOCK,
pll_d_freq_table, &pll_d_lock);
clk_register_clkdev(clk, "pll_d", NULL);
clks[pll_d] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_d_out0", NULL);
clks[pll_d_out0] = clk;
clk = tegra_clk_register_pll("pll_d2", "pll_ref", clk_base, pmc_base, 0,
0, &pll_d2_params, TEGRA_PLL_HAS_CPCON |
TEGRA_PLL_SET_LFCON | TEGRA_PLL_USE_LOCK,
pll_d_freq_table, NULL);
clk_register_clkdev(clk, "pll_d2", NULL);
clks[pll_d2] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d2_out0", "pll_d2",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_d2_out0", NULL);
clks[pll_d2_out0] = clk;
clk = tegra_clk_register_pll("pll_a", "pll_p_out1", clk_base, pmc_base,
0, 0, &pll_a_params, TEGRA_PLL_HAS_CPCON |
TEGRA_PLL_USE_LOCK, pll_a_freq_table, NULL);
clk_register_clkdev(clk, "pll_a", NULL);
clks[pll_a] = clk;
clk = tegra_clk_register_divider("pll_a_out0_div", "pll_a",
clk_base + PLLA_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_a_out0", "pll_a_out0_div",
clk_base + PLLA_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
clk_register_clkdev(clk, "pll_a_out0", NULL);
clks[pll_a_out0] = clk;
clk = clk_register_mux(NULL, "pll_e_mux", pll_e_parents,
ARRAY_SIZE(pll_e_parents),
CLK_SET_RATE_NO_REPARENT,
clk_base + PLLE_AUX, 2, 1, 0, NULL);
clk = tegra_clk_register_plle("pll_e", "pll_e_mux", clk_base, pmc_base,
CLK_GET_RATE_NOCACHE, 100000000, &pll_e_params,
TEGRA_PLLE_CONFIGURE, pll_e_freq_table, NULL);
clk_register_clkdev(clk, "pll_e", NULL);
clks[pll_e] = clk;
}
static void __init tegra30_audio_clk_init(void)
{
struct clk *clk;
clk = tegra_clk_register_sync_source("spdif_in_sync", 24000000,
24000000);
clk_register_clkdev(clk, "spdif_in_sync", NULL);
clks[spdif_in_sync] = clk;
clk = tegra_clk_register_sync_source("i2s0_sync", 24000000, 24000000);
clk_register_clkdev(clk, "i2s0_sync", NULL);
clks[i2s0_sync] = clk;
clk = tegra_clk_register_sync_source("i2s1_sync", 24000000, 24000000);
clk_register_clkdev(clk, "i2s1_sync", NULL);
clks[i2s1_sync] = clk;
clk = tegra_clk_register_sync_source("i2s2_sync", 24000000, 24000000);
clk_register_clkdev(clk, "i2s2_sync", NULL);
clks[i2s2_sync] = clk;
clk = tegra_clk_register_sync_source("i2s3_sync", 24000000, 24000000);
clk_register_clkdev(clk, "i2s3_sync", NULL);
clks[i2s3_sync] = clk;
clk = tegra_clk_register_sync_source("i2s4_sync", 24000000, 24000000);
clk_register_clkdev(clk, "i2s4_sync", NULL);
clks[i2s4_sync] = clk;
clk = tegra_clk_register_sync_source("vimclk_sync", 24000000, 24000000);
clk_register_clkdev(clk, "vimclk_sync", NULL);
clks[vimclk_sync] = clk;
clk = clk_register_mux(NULL, "audio0_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S0, 0, 3, 0, NULL);
clk = clk_register_gate(NULL, "audio0", "audio0_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S0, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio0", NULL);
clks[audio0] = clk;
clk = clk_register_mux(NULL, "audio1_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S1, 0, 3, 0, NULL);
clk = clk_register_gate(NULL, "audio1", "audio1_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S1, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio1", NULL);
clks[audio1] = clk;
clk = clk_register_mux(NULL, "audio2_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S2, 0, 3, 0, NULL);
clk = clk_register_gate(NULL, "audio2", "audio2_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S2, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio2", NULL);
clks[audio2] = clk;
clk = clk_register_mux(NULL, "audio3_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S3, 0, 3, 0, NULL);
clk = clk_register_gate(NULL, "audio3", "audio3_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S3, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio3", NULL);
clks[audio3] = clk;
clk = clk_register_mux(NULL, "audio4_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S4, 0, 3, 0, NULL);
clk = clk_register_gate(NULL, "audio4", "audio4_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S4, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio4", NULL);
clks[audio4] = clk;
clk = clk_register_mux(NULL, "spdif_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_SPDIF, 0, 3, 0, NULL);
clk = clk_register_gate(NULL, "spdif", "spdif_mux", 0,
clk_base + AUDIO_SYNC_CLK_SPDIF, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "spdif", NULL);
clks[spdif] = clk;
clk = clk_register_fixed_factor(NULL, "audio0_doubler", "audio0",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio0_div", "audio0_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 24, 1, 0,
&clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio0_2x", "audio0_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 113, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio0_2x", NULL);
clks[audio0_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio1_doubler", "audio1",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio1_div", "audio1_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 25, 1, 0,
&clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio1_2x", "audio1_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 114, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio1_2x", NULL);
clks[audio1_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio2_doubler", "audio2",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio2_div", "audio2_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 26, 1, 0,
&clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio2_2x", "audio2_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 115, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio2_2x", NULL);
clks[audio2_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio3_doubler", "audio3",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio3_div", "audio3_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 27, 1, 0,
&clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio3_2x", "audio3_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 116, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio3_2x", NULL);
clks[audio3_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio4_doubler", "audio4",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio4_div", "audio4_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 28, 1, 0,
&clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio4_2x", "audio4_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 117, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio4_2x", NULL);
clks[audio4_2x] = clk;
clk = clk_register_fixed_factor(NULL, "spdif_doubler", "spdif",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("spdif_div", "spdif_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 29, 1, 0,
&clk_doubler_lock);
clk = tegra_clk_register_periph_gate("spdif_2x", "spdif_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 118, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "spdif_2x", NULL);
clks[spdif_2x] = clk;
}
static void __init tegra30_pmc_clk_init(void)
{
struct clk *clk;
clk = clk_register_mux(NULL, "clk_out_1_mux", clk_out1_parents,
ARRAY_SIZE(clk_out1_parents),
CLK_SET_RATE_NO_REPARENT,
pmc_base + PMC_CLK_OUT_CNTRL, 6, 3, 0,
&clk_out_lock);
clks[clk_out_1_mux] = clk;
clk = clk_register_gate(NULL, "clk_out_1", "clk_out_1_mux", 0,
pmc_base + PMC_CLK_OUT_CNTRL, 2, 0,
&clk_out_lock);
clk_register_clkdev(clk, "extern1", "clk_out_1");
clks[clk_out_1] = clk;
clk = clk_register_mux(NULL, "clk_out_2_mux", clk_out2_parents,
ARRAY_SIZE(clk_out2_parents),
CLK_SET_RATE_NO_REPARENT,
pmc_base + PMC_CLK_OUT_CNTRL, 14, 3, 0,
&clk_out_lock);
clk = clk_register_gate(NULL, "clk_out_2", "clk_out_2_mux", 0,
pmc_base + PMC_CLK_OUT_CNTRL, 10, 0,
&clk_out_lock);
clk_register_clkdev(clk, "extern2", "clk_out_2");
clks[clk_out_2] = clk;
clk = clk_register_mux(NULL, "clk_out_3_mux", clk_out3_parents,
ARRAY_SIZE(clk_out3_parents),
CLK_SET_RATE_NO_REPARENT,
pmc_base + PMC_CLK_OUT_CNTRL, 22, 3, 0,
&clk_out_lock);
clk = clk_register_gate(NULL, "clk_out_3", "clk_out_3_mux", 0,
pmc_base + PMC_CLK_OUT_CNTRL, 18, 0,
&clk_out_lock);
clk_register_clkdev(clk, "extern3", "clk_out_3");
clks[clk_out_3] = clk;
writel_relaxed(0, pmc_base + PMC_BLINK_TIMER);
clk = clk_register_gate(NULL, "blink_override", "clk_32k", 0,
pmc_base + PMC_DPD_PADS_ORIDE,
PMC_DPD_PADS_ORIDE_BLINK_ENB, 0, NULL);
clk = clk_register_gate(NULL, "blink", "blink_override", 0,
pmc_base + PMC_CTRL,
PMC_CTRL_BLINK_ENB, 0, NULL);
clk_register_clkdev(clk, "blink", NULL);
clks[blink] = clk;
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
clk_register_clkdev(clk, "cclk_g", NULL);
clks[cclk_g] = clk;
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
clk_register_clkdev(clk, "cclk_lp", NULL);
clks[cclk_lp] = clk;
clk = tegra_clk_register_super_mux("sclk", sclk_parents,
ARRAY_SIZE(sclk_parents),
CLK_SET_RATE_PARENT,
clk_base + SCLK_BURST_POLICY,
0, 4, 0, 0, NULL);
clk_register_clkdev(clk, "sclk", NULL);
clks[sclk] = clk;
clk = clk_register_divider(NULL, "hclk_div", "sclk", 0,
clk_base + SYSTEM_CLK_RATE, 4, 2, 0,
&sysrate_lock);
clk = clk_register_gate(NULL, "hclk", "hclk_div", CLK_SET_RATE_PARENT,
clk_base + SYSTEM_CLK_RATE, 7,
CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
clk_register_clkdev(clk, "hclk", NULL);
clks[hclk] = clk;
clk = clk_register_divider(NULL, "pclk_div", "hclk", 0,
clk_base + SYSTEM_CLK_RATE, 0, 2, 0,
&sysrate_lock);
clk = clk_register_gate(NULL, "pclk", "pclk_div", CLK_SET_RATE_PARENT,
clk_base + SYSTEM_CLK_RATE, 3,
CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
clk_register_clkdev(clk, "pclk", NULL);
clks[pclk] = clk;
clk = clk_register_fixed_factor(NULL, "twd", "cclk_g",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "twd", NULL);
clks[twd] = clk;
}
static void __init tegra30_periph_clk_init(void)
{
struct tegra_periph_init_data *data;
struct clk *clk;
int i;
clk = tegra_clk_register_periph_gate("apbdma", "clk_m", 0, clk_base, 0, 34,
&periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra-apbdma");
clks[apbdma] = clk;
clk = tegra_clk_register_periph_gate("rtc", "clk_32k",
TEGRA_PERIPH_NO_RESET | TEGRA_PERIPH_ON_APB,
clk_base, 0, 4, &periph_l_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "rtc-tegra");
clks[rtc] = clk;
clk = tegra_clk_register_periph_gate("timer", "clk_m", 0, clk_base, 0,
5, &periph_l_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "timer");
clks[timer] = clk;
clk = tegra_clk_register_periph_gate("kbc", "clk_32k",
TEGRA_PERIPH_NO_RESET | TEGRA_PERIPH_ON_APB,
clk_base, 0, 36, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra-kbc");
clks[kbc] = clk;
clk = tegra_clk_register_periph_gate("csus", "clk_m",
TEGRA_PERIPH_NO_RESET | TEGRA_PERIPH_ON_APB,
clk_base, 0, 92, &periph_u_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "csus", "tengra_camera");
clks[csus] = clk;
clk = tegra_clk_register_periph_gate("vcp", "clk_m", 0, clk_base, 0, 29,
&periph_l_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "vcp", "tegra-avp");
clks[vcp] = clk;
clk = tegra_clk_register_periph_gate("bsea", "clk_m", 0, clk_base, 0,
62, &periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "bsea", "tegra-avp");
clks[bsea] = clk;
clk = tegra_clk_register_periph_gate("bsev", "clk_m", 0, clk_base, 0,
63, &periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "bsev", "tegra-aes");
clks[bsev] = clk;
clk = tegra_clk_register_periph_gate("usbd", "clk_m", 0, clk_base, 0,
22, &periph_l_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "fsl-tegra-udc");
clks[usbd] = clk;
clk = tegra_clk_register_periph_gate("usb2", "clk_m", 0, clk_base, 0,
58, &periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra-ehci.1");
clks[usb2] = clk;
clk = tegra_clk_register_periph_gate("usb3", "clk_m", 0, clk_base, 0,
59, &periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra-ehci.2");
clks[usb3] = clk;
clk = tegra_clk_register_periph_gate("dsia", "pll_d_out0", 0, clk_base,
0, 48, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "dsia", "tegradc.0");
clks[dsia] = clk;
clk = tegra_clk_register_periph_gate("csi", "pll_p_out3", 0, clk_base,
0, 52, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "csi", "tegra_camera");
clks[csi] = clk;
clk = tegra_clk_register_periph_gate("isp", "clk_m", 0, clk_base, 0, 23,
&periph_l_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "isp", "tegra_camera");
clks[isp] = clk;
clk = tegra_clk_register_periph_gate("pcie", "clk_m", 0, clk_base, 0,
70, &periph_u_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "pcie", "tegra-pcie");
clks[pcie] = clk;
clk = tegra_clk_register_periph_gate("afi", "clk_m", 0, clk_base, 0, 72,
&periph_u_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "afi", "tegra-pcie");
clks[afi] = clk;
clk = tegra_clk_register_periph_gate("pciex", "pll_e", 0, clk_base, 0,
74, &periph_u_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "pciex", "tegra-pcie");
clks[pciex] = clk;
clk = tegra_clk_register_periph_gate("kfuse", "clk_m",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 40, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "kfuse-tegra");
clks[kfuse] = clk;
clk = tegra_clk_register_periph_gate("fuse", "clk_m",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 39, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "fuse", "fuse-tegra");
clks[fuse] = clk;
clk = tegra_clk_register_periph_gate("fuse_burn", "clk_m",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 39, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "fuse_burn", "fuse-tegra");
clks[fuse_burn] = clk;
clk = tegra_clk_register_periph_gate("apbif", "clk_m", 0,
clk_base, 0, 107, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "apbif", "tegra30-ahub");
clks[apbif] = clk;
clk = tegra_clk_register_periph_gate("hda2hdmi", "clk_m",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 128, &periph_w_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "hda2hdmi", "tegra30-hda");
clks[hda2hdmi] = clk;
clk = tegra_clk_register_periph_gate("sata_cold", "clk_m",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 129, &periph_w_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra_sata_cold");
clks[sata_cold] = clk;
clk = tegra_clk_register_periph_gate("dtv", "clk_m",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 79, &periph_u_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "dtv");
clks[dtv] = clk;
clk = clk_register_mux(NULL, "emc_mux", mux_pllmcp_clkm,
ARRAY_SIZE(mux_pllmcp_clkm),
CLK_SET_RATE_NO_REPARENT,
clk_base + CLK_SOURCE_EMC,
30, 2, 0, NULL);
clk = tegra_clk_register_periph_gate("emc", "emc_mux", 0, clk_base, 0,
57, &periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "emc", NULL);
clks[emc] = clk;
for (i = 0; i < ARRAY_SIZE(tegra_periph_clk_list); i++) {
data = &tegra_periph_clk_list[i];
clk = tegra_clk_register_periph(data->name, data->parent_names,
data->num_parents, &data->periph,
clk_base, data->offset, data->flags);
clk_register_clkdev(clk, data->con_id, data->dev_id);
clks[data->clk_id] = clk;
}
for (i = 0; i < ARRAY_SIZE(tegra_periph_nodiv_clk_list); i++) {
data = &tegra_periph_nodiv_clk_list[i];
clk = tegra_clk_register_periph_nodiv(data->name,
data->parent_names,
data->num_parents, &data->periph,
clk_base, data->offset);
clk_register_clkdev(clk, data->con_id, data->dev_id);
clks[data->clk_id] = clk;
}
}
static void __init tegra30_fixed_clk_init(void)
{
struct clk *clk;
clk = clk_register_fixed_rate(NULL, "clk_32k", NULL, CLK_IS_ROOT,
32768);
clk_register_clkdev(clk, "clk_32k", NULL);
clks[clk_32k] = clk;
clk = clk_register_fixed_factor(NULL, "clk_m_div2", "clk_m",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "clk_m_div2", NULL);
clks[clk_m_div2] = clk;
clk = clk_register_fixed_factor(NULL, "clk_m_div4", "clk_m",
CLK_SET_RATE_PARENT, 1, 4);
clk_register_clkdev(clk, "clk_m_div4", NULL);
clks[clk_m_div4] = clk;
clk = clk_register_gate(NULL, "cml0", "pll_e", 0, clk_base + PLLE_AUX,
0, 0, &cml_lock);
clk_register_clkdev(clk, "cml0", NULL);
clks[cml0] = clk;
clk = clk_register_gate(NULL, "cml1", "pll_e", 0, clk_base + PLLE_AUX,
1, 0, &cml_lock);
clk_register_clkdev(clk, "cml1", NULL);
clks[cml1] = clk;
}
static void __init tegra30_osc_clk_init(void)
{
struct clk *clk;
unsigned int pll_ref_div;
tegra30_clk_measure_input_freq();
clk = clk_register_fixed_rate(NULL, "clk_m", NULL, CLK_IS_ROOT,
input_freq);
clk_register_clkdev(clk, "clk_m", NULL);
clks[clk_m] = clk;
pll_ref_div = tegra30_get_pll_ref_div();
clk = clk_register_fixed_factor(NULL, "pll_ref", "clk_m",
CLK_SET_RATE_PARENT, 1, pll_ref_div);
clk_register_clkdev(clk, "pll_ref", NULL);
clks[pll_ref] = clk;
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
tegra_init_from_table(init_table, clks, clk_max);
}
static void __init tegra30_clock_init(struct device_node *np)
{
struct device_node *node;
int i;
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
tegra30_osc_clk_init();
tegra30_fixed_clk_init();
tegra30_pll_init();
tegra30_super_clk_init();
tegra30_periph_clk_init();
tegra30_audio_clk_init();
tegra30_pmc_clk_init();
for (i = 0; i < ARRAY_SIZE(clks); i++) {
if (IS_ERR(clks[i])) {
pr_err("Tegra30 clk %d: register failed with %ld\n",
i, PTR_ERR(clks[i]));
BUG();
}
if (!clks[i])
clks[i] = ERR_PTR(-EINVAL);
}
tegra_init_dup_clks(tegra_clk_duplicates, clks, clk_max);
clk_data.clks = clks;
clk_data.clk_num = ARRAY_SIZE(clks);
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
tegra_clk_apply_init_table = tegra30_clock_apply_init_table;
tegra_cpu_car_ops = &tegra30_cpu_car_ops;
}
