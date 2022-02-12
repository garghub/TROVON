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
clk_register_clkdev(clk, "clk_m", NULL);
clks[clk_m] = clk;
val = (val >> OSC_CTRL_PLL_REF_DIV_SHIFT) & 3;
pll_ref_div = 1 << val;
clk = clk_register_fixed_factor(NULL, "pll_ref", "clk_m",
CLK_SET_RATE_PARENT, 1, pll_ref_div);
clk_register_clkdev(clk, "pll_ref", NULL);
clks[pll_ref] = clk;
pll_ref_freq = osc_freq / pll_ref_div;
return 0;
}
static void __init tegra114_fixed_clk_init(void __iomem *clk_base)
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
static void __init _clip_vco_min(struct tegra_clk_pll_params *pll_params)
{
pll_params->vco_min =
DIV_ROUND_UP(pll_params->vco_min, pll_ref_freq) * pll_ref_freq;
}
static int __init _setup_dynamic_ramp(struct tegra_clk_pll_params *pll_params,
void __iomem *clk_base)
{
u32 val;
u32 step_a, step_b;
switch (pll_ref_freq) {
case 12000000:
case 13000000:
case 26000000:
step_a = 0x2B;
step_b = 0x0B;
break;
case 16800000:
step_a = 0x1A;
step_b = 0x09;
break;
case 19200000:
step_a = 0x12;
step_b = 0x08;
break;
default:
pr_err("%s: Unexpected reference rate %lu\n",
__func__, pll_ref_freq);
WARN_ON(1);
return -EINVAL;
}
val = step_a << pll_params->stepa_shift;
val |= step_b << pll_params->stepb_shift;
writel_relaxed(val, clk_base + pll_params->dyn_ramp_reg);
return 0;
}
static void __init _init_iddq(struct tegra_clk_pll_params *pll_params,
void __iomem *clk_base)
{
u32 val, val_iddq;
val = readl_relaxed(clk_base + pll_params->base_reg);
val_iddq = readl_relaxed(clk_base + pll_params->iddq_reg);
if (val & BIT(30))
WARN_ON(val_iddq & BIT(pll_params->iddq_bit_idx));
else {
val_iddq |= BIT(pll_params->iddq_bit_idx);
writel_relaxed(val_iddq, clk_base + pll_params->iddq_reg);
}
}
static void __init tegra114_pll_init(void __iomem *clk_base,
void __iomem *pmc)
{
u32 val;
struct clk *clk;
_clip_vco_min(&pll_c_params);
if (_setup_dynamic_ramp(&pll_c_params, clk_base) >= 0) {
_init_iddq(&pll_c_params, clk_base);
clk = tegra_clk_register_pllxc("pll_c", "pll_ref", clk_base,
pmc, 0, 0, &pll_c_params, TEGRA_PLL_USE_LOCK,
pll_c_freq_table, NULL);
clk_register_clkdev(clk, "pll_c", NULL);
clks[pll_c] = clk;
clk = tegra_clk_register_divider("pll_c_out1_div", "pll_c",
clk_base + PLLC_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c_out1", "pll_c_out1_div",
clk_base + PLLC_OUT, 1, 0,
CLK_SET_RATE_PARENT, 0, NULL);
clk_register_clkdev(clk, "pll_c_out1", NULL);
clks[pll_c_out1] = clk;
}
_clip_vco_min(&pll_c2_params);
clk = tegra_clk_register_pllc("pll_c2", "pll_ref", clk_base, pmc, 0, 0,
&pll_c2_params, TEGRA_PLL_USE_LOCK,
pll_cx_freq_table, NULL);
clk_register_clkdev(clk, "pll_c2", NULL);
clks[pll_c2] = clk;
_clip_vco_min(&pll_c3_params);
clk = tegra_clk_register_pllc("pll_c3", "pll_ref", clk_base, pmc, 0, 0,
&pll_c3_params, TEGRA_PLL_USE_LOCK,
pll_cx_freq_table, NULL);
clk_register_clkdev(clk, "pll_c3", NULL);
clks[pll_c3] = clk;
clk = tegra_clk_register_pll("pll_p", "pll_ref", clk_base, pmc, 0,
408000000, &pll_p_params,
TEGRA_PLL_FIXED | TEGRA_PLL_USE_LOCK,
pll_p_freq_table, NULL);
clk_register_clkdev(clk, "pll_p", NULL);
clks[pll_p] = clk;
clk = tegra_clk_register_divider("pll_p_out1_div", "pll_p",
clk_base + PLLP_OUTA, 0, TEGRA_DIVIDER_FIXED |
TEGRA_DIVIDER_ROUND_UP, 8, 8, 1, &pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out1", "pll_p_out1_div",
clk_base + PLLP_OUTA, 1, 0,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out1", NULL);
clks[pll_p_out1] = clk;
clk = tegra_clk_register_divider("pll_p_out2_div", "pll_p",
clk_base + PLLP_OUTA, 0, TEGRA_DIVIDER_FIXED |
TEGRA_DIVIDER_ROUND_UP | TEGRA_DIVIDER_INT, 24,
8, 1, &pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out2", "pll_p_out2_div",
clk_base + PLLP_OUTA, 17, 16,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out2", NULL);
clks[pll_p_out2] = clk;
clk = tegra_clk_register_divider("pll_p_out3_div", "pll_p",
clk_base + PLLP_OUTB, 0, TEGRA_DIVIDER_FIXED |
TEGRA_DIVIDER_ROUND_UP, 8, 8, 1, &pll_div_lock);
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
_clip_vco_min(&pll_m_params);
clk = tegra_clk_register_pllm("pll_m", "pll_ref", clk_base, pmc,
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE, 0,
&pll_m_params, TEGRA_PLL_USE_LOCK,
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
clk = clk_register_fixed_factor(NULL, "pll_m_ud", "pll_m",
CLK_SET_RATE_PARENT, 1, 1);
_clip_vco_min(&pll_x_params);
if (_setup_dynamic_ramp(&pll_x_params, clk_base) >= 0) {
_init_iddq(&pll_x_params, clk_base);
clk = tegra_clk_register_pllxc("pll_x", "pll_ref", clk_base,
pmc, CLK_IGNORE_UNUSED, 0, &pll_x_params,
TEGRA_PLL_USE_LOCK, pll_x_freq_table, NULL);
clk_register_clkdev(clk, "pll_x", NULL);
clks[pll_x] = clk;
}
clk = clk_register_fixed_factor(NULL, "pll_x_out0", "pll_x",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_x_out0", NULL);
clks[pll_x_out0] = clk;
val = readl(clk_base + pll_u_params.base_reg);
val &= ~BIT(24);
writel(val, clk_base + pll_u_params.base_reg);
clk = tegra_clk_register_pll("pll_u", "pll_ref", clk_base, pmc, 0,
0, &pll_u_params, TEGRA_PLLU |
TEGRA_PLL_HAS_CPCON | TEGRA_PLL_SET_LFCON |
TEGRA_PLL_USE_LOCK, pll_u_freq_table, &pll_u_lock);
clk_register_clkdev(clk, "pll_u", NULL);
clks[pll_u] = clk;
tegra114_utmi_param_configure(clk_base);
clk = clk_register_gate(NULL, "pll_u_480M", "pll_u",
CLK_SET_RATE_PARENT, clk_base + PLLU_BASE,
22, 0, &pll_u_lock);
clk_register_clkdev(clk, "pll_u_480M", NULL);
clks[pll_u_480M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_60M", "pll_u",
CLK_SET_RATE_PARENT, 1, 8);
clk_register_clkdev(clk, "pll_u_60M", NULL);
clks[pll_u_60M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_48M", "pll_u",
CLK_SET_RATE_PARENT, 1, 10);
clk_register_clkdev(clk, "pll_u_48M", NULL);
clks[pll_u_48M] = clk;
clk = clk_register_fixed_factor(NULL, "pll_u_12M", "pll_u",
CLK_SET_RATE_PARENT, 1, 40);
clk_register_clkdev(clk, "pll_u_12M", NULL);
clks[pll_u_12M] = clk;
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, pmc, 0,
0, &pll_d_params,
TEGRA_PLL_HAS_CPCON | TEGRA_PLL_SET_LFCON |
TEGRA_PLL_USE_LOCK, pll_d_freq_table, &pll_d_lock);
clk_register_clkdev(clk, "pll_d", NULL);
clks[pll_d] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_d_out0", NULL);
clks[pll_d_out0] = clk;
clk = tegra_clk_register_pll("pll_d2", "pll_ref", clk_base, pmc, 0,
0, &pll_d2_params,
TEGRA_PLL_HAS_CPCON | TEGRA_PLL_SET_LFCON |
TEGRA_PLL_USE_LOCK, pll_d_freq_table, &pll_d2_lock);
clk_register_clkdev(clk, "pll_d2", NULL);
clks[pll_d2] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d2_out0", "pll_d2",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_d2_out0", NULL);
clks[pll_d2_out0] = clk;
clk = tegra_clk_register_pll("pll_a", "pll_p_out1", clk_base, pmc, 0,
0, &pll_a_params, TEGRA_PLL_HAS_CPCON |
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
_clip_vco_min(&pll_re_vco_params);
clk = tegra_clk_register_pllre("pll_re_vco", "pll_ref", clk_base, pmc,
0, 0, &pll_re_vco_params, TEGRA_PLL_USE_LOCK,
NULL, &pll_re_lock, pll_ref_freq);
clk_register_clkdev(clk, "pll_re_vco", NULL);
clks[pll_re_vco] = clk;
clk = clk_register_divider_table(NULL, "pll_re_out", "pll_re_vco", 0,
clk_base + PLLRE_BASE, 16, 4, 0,
pll_re_div_table, &pll_re_lock);
clk_register_clkdev(clk, "pll_re_out", NULL);
clks[pll_re_out] = clk;
clk = tegra_clk_register_plle_tegra114("pll_e_out0", "pll_re_vco",
clk_base, 0, 100000000, &pll_e_params,
pll_e_freq_table, NULL);
clk_register_clkdev(clk, "pll_e_out0", NULL);
clks[pll_e_out0] = clk;
}
static void __init tegra114_audio_clk_init(void __iomem *clk_base)
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
clk_base + AUDIO_SYNC_CLK_I2S0, 0, 3, 0,
NULL);
clks[audio0_mux] = clk;
clk = clk_register_gate(NULL, "audio0", "audio0_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S0, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio0", NULL);
clks[audio0] = clk;
clk = clk_register_mux(NULL, "audio1_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S1, 0, 3, 0,
NULL);
clks[audio1_mux] = clk;
clk = clk_register_gate(NULL, "audio1", "audio1_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S1, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio1", NULL);
clks[audio1] = clk;
clk = clk_register_mux(NULL, "audio2_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S2, 0, 3, 0,
NULL);
clks[audio2_mux] = clk;
clk = clk_register_gate(NULL, "audio2", "audio2_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S2, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio2", NULL);
clks[audio2] = clk;
clk = clk_register_mux(NULL, "audio3_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S3, 0, 3, 0,
NULL);
clks[audio3_mux] = clk;
clk = clk_register_gate(NULL, "audio3", "audio3_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S3, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio3", NULL);
clks[audio3] = clk;
clk = clk_register_mux(NULL, "audio4_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_I2S4, 0, 3, 0,
NULL);
clks[audio4_mux] = clk;
clk = clk_register_gate(NULL, "audio4", "audio4_mux", 0,
clk_base + AUDIO_SYNC_CLK_I2S4, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio4", NULL);
clks[audio4] = clk;
clk = clk_register_mux(NULL, "spdif_mux", mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK_SPDIF, 0, 3, 0,
NULL);
clks[spdif_mux] = clk;
clk = clk_register_gate(NULL, "spdif", "spdif_mux", 0,
clk_base + AUDIO_SYNC_CLK_SPDIF, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "spdif", NULL);
clks[spdif] = clk;
clk = clk_register_fixed_factor(NULL, "audio0_doubler", "audio0",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio0_div", "audio0_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 24, 1,
0, &clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio0_2x", "audio0_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 113, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio0_2x", NULL);
clks[audio0_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio1_doubler", "audio1",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio1_div", "audio1_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 25, 1,
0, &clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio1_2x", "audio1_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 114, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio1_2x", NULL);
clks[audio1_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio2_doubler", "audio2",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio2_div", "audio2_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 26, 1,
0, &clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio2_2x", "audio2_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 115, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio2_2x", NULL);
clks[audio2_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio3_doubler", "audio3",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio3_div", "audio3_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 27, 1,
0, &clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio3_2x", "audio3_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 116, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio3_2x", NULL);
clks[audio3_2x] = clk;
clk = clk_register_fixed_factor(NULL, "audio4_doubler", "audio4",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("audio4_div", "audio4_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 28, 1,
0, &clk_doubler_lock);
clk = tegra_clk_register_periph_gate("audio4_2x", "audio4_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 117, &periph_v_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio4_2x", NULL);
clks[audio4_2x] = clk;
clk = clk_register_fixed_factor(NULL, "spdif_doubler", "spdif",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider("spdif_div", "spdif_doubler",
clk_base + AUDIO_SYNC_DOUBLER, 0, 0, 29, 1,
0, &clk_doubler_lock);
clk = tegra_clk_register_periph_gate("spdif_2x", "spdif_div",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 118,
&periph_v_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "spdif_2x", NULL);
clks[spdif_2x] = clk;
}
static void __init tegra114_pmc_clk_init(void __iomem *pmc_base)
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
clks[clk_out_2_mux] = clk;
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
clks[clk_out_3_mux] = clk;
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
static void __init tegra114_super_clk_init(void __iomem *clk_base)
{
struct clk *clk;
clk = tegra_clk_register_super_mux("cclk_g", cclk_g_parents,
ARRAY_SIZE(cclk_g_parents),
CLK_SET_RATE_PARENT,
clk_base + CCLKG_BURST_POLICY,
0, 4, 0, 0, NULL);
clk_register_clkdev(clk, "cclk_g", NULL);
clks[cclk_g] = clk;
clk = tegra_clk_register_super_mux("cclk_lp", cclk_lp_parents,
ARRAY_SIZE(cclk_lp_parents),
CLK_SET_RATE_PARENT,
clk_base + CCLKLP_BURST_POLICY,
0, 4, 8, 9, NULL);
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
clk = clk_register_gate(NULL, "hclk", "hclk_div", CLK_SET_RATE_PARENT |
CLK_IGNORE_UNUSED, clk_base + SYSTEM_CLK_RATE,
7, CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
clk_register_clkdev(clk, "hclk", NULL);
clks[hclk] = clk;
clk = clk_register_divider(NULL, "pclk_div", "hclk", 0,
clk_base + SYSTEM_CLK_RATE, 0, 2, 0,
&sysrate_lock);
clk = clk_register_gate(NULL, "pclk", "pclk_div", CLK_SET_RATE_PARENT |
CLK_IGNORE_UNUSED, clk_base + SYSTEM_CLK_RATE,
3, CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
clk_register_clkdev(clk, "pclk", NULL);
clks[pclk] = clk;
}
static __init void tegra114_periph_clk_init(void __iomem *clk_base)
{
struct tegra_periph_init_data *data;
struct clk *clk;
int i;
u32 val;
clk = tegra_clk_register_periph_gate("apbdma", "clk_m", 0, clk_base,
0, 34, &periph_h_regs,
periph_clk_enb_refcnt);
clks[apbdma] = clk;
clk = tegra_clk_register_periph_gate("rtc", "clk_32k",
TEGRA_PERIPH_ON_APB |
TEGRA_PERIPH_NO_RESET, clk_base,
0, 4, &periph_l_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "rtc-tegra");
clks[rtc] = clk;
clk = tegra_clk_register_periph_gate("kbc", "clk_32k",
TEGRA_PERIPH_ON_APB |
TEGRA_PERIPH_NO_RESET, clk_base,
0, 36, &periph_h_regs,
periph_clk_enb_refcnt);
clks[kbc] = clk;
clk = tegra_clk_register_periph_gate("timer", "clk_m", 0, clk_base,
0, 5, &periph_l_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "timer");
clks[timer] = clk;
clk = tegra_clk_register_periph_gate("kfuse", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 40,
&periph_h_regs, periph_clk_enb_refcnt);
clks[kfuse] = clk;
clk = tegra_clk_register_periph_gate("fuse", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 39,
&periph_h_regs, periph_clk_enb_refcnt);
clks[fuse] = clk;
clk = tegra_clk_register_periph_gate("fuse_burn", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 39,
&periph_h_regs, periph_clk_enb_refcnt);
clks[fuse_burn] = clk;
clk = tegra_clk_register_periph_gate("apbif", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 107,
&periph_v_regs, periph_clk_enb_refcnt);
clks[apbif] = clk;
clk = tegra_clk_register_periph_gate("hda2hdmi", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 128,
&periph_w_regs, periph_clk_enb_refcnt);
clks[hda2hdmi] = clk;
clk = tegra_clk_register_periph_gate("vcp", "clk_m", 0, clk_base, 0,
29, &periph_l_regs,
periph_clk_enb_refcnt);
clks[vcp] = clk;
clk = tegra_clk_register_periph_gate("bsea", "clk_m", 0, clk_base,
0, 62, &periph_h_regs,
periph_clk_enb_refcnt);
clks[bsea] = clk;
clk = tegra_clk_register_periph_gate("bsev", "clk_m", 0, clk_base,
0, 63, &periph_h_regs,
periph_clk_enb_refcnt);
clks[bsev] = clk;
clk = tegra_clk_register_periph_gate("mipi-cal", "clk_m", 0, clk_base,
0, 56, &periph_h_regs,
periph_clk_enb_refcnt);
clks[mipi_cal] = clk;
clk = tegra_clk_register_periph_gate("usbd", "clk_m", 0, clk_base,
0, 22, &periph_l_regs,
periph_clk_enb_refcnt);
clks[usbd] = clk;
clk = tegra_clk_register_periph_gate("usb2", "clk_m", 0, clk_base,
0, 58, &periph_h_regs,
periph_clk_enb_refcnt);
clks[usb2] = clk;
clk = tegra_clk_register_periph_gate("usb3", "clk_m", 0, clk_base,
0, 59, &periph_h_regs,
periph_clk_enb_refcnt);
clks[usb3] = clk;
clk = tegra_clk_register_periph_gate("csi", "pll_p_out3", 0, clk_base,
0, 52, &periph_h_regs,
periph_clk_enb_refcnt);
clks[csi] = clk;
clk = tegra_clk_register_periph_gate("isp", "clk_m", 0, clk_base, 0,
23, &periph_l_regs,
periph_clk_enb_refcnt);
clks[isp] = clk;
clk = tegra_clk_register_periph_gate("csus", "clk_m",
TEGRA_PERIPH_NO_RESET, clk_base, 0, 92,
&periph_u_regs, periph_clk_enb_refcnt);
clks[csus] = clk;
clk = tegra_clk_register_periph_gate("dds", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 150,
&periph_w_regs, periph_clk_enb_refcnt);
clks[dds] = clk;
clk = tegra_clk_register_periph_gate("dp2", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 152,
&periph_w_regs, periph_clk_enb_refcnt);
clks[dp2] = clk;
clk = tegra_clk_register_periph_gate("dtv", "clk_m",
TEGRA_PERIPH_ON_APB, clk_base, 0, 79,
&periph_u_regs, periph_clk_enb_refcnt);
clks[dtv] = clk;
clk = clk_register_mux(NULL, "dsia_mux", mux_plld_out0_plld2_out0,
ARRAY_SIZE(mux_plld_out0_plld2_out0),
CLK_SET_RATE_NO_REPARENT,
clk_base + PLLD_BASE, 25, 1, 0, &pll_d_lock);
clks[dsia_mux] = clk;
clk = tegra_clk_register_periph_gate("dsia", "dsia_mux", 0, clk_base,
0, 48, &periph_h_regs,
periph_clk_enb_refcnt);
clks[dsia] = clk;
clk = clk_register_mux(NULL, "dsib_mux", mux_plld_out0_plld2_out0,
ARRAY_SIZE(mux_plld_out0_plld2_out0),
CLK_SET_RATE_NO_REPARENT,
clk_base + PLLD2_BASE, 25, 1, 0, &pll_d2_lock);
clks[dsib_mux] = clk;
clk = tegra_clk_register_periph_gate("dsib", "dsib_mux", 0, clk_base,
0, 82, &periph_u_regs,
periph_clk_enb_refcnt);
clks[dsib] = clk;
val = readl(clk_base + CLK_SOURCE_XUSB_SS_SRC);
val |= BIT(25);
writel(val, clk_base + CLK_SOURCE_XUSB_SS_SRC);
clk = clk_register_fixed_factor(NULL, "xusb_hs_src", "pll_u_60M", 0,
1, 1);
clks[xusb_hs_src] = clk;
clk = tegra_clk_register_periph_gate("xusb_host", "xusb_host_src", 0,
clk_base, 0, 89, &periph_u_regs,
periph_clk_enb_refcnt);
clks[xusb_host] = clk;
clk = tegra_clk_register_periph_gate("xusb_ss", "xusb_ss_src", 0,
clk_base, 0, 156, &periph_w_regs,
periph_clk_enb_refcnt);
clks[xusb_host] = clk;
clk = tegra_clk_register_periph_gate("xusb_dev", "xusb_dev_src", 0,
clk_base, 0, 95, &periph_u_regs,
periph_clk_enb_refcnt);
clks[xusb_dev] = clk;
clk = clk_register_mux(NULL, "emc_mux", mux_pllmcp_clkm,
ARRAY_SIZE(mux_pllmcp_clkm),
CLK_SET_RATE_NO_REPARENT,
clk_base + CLK_SOURCE_EMC,
29, 3, 0, NULL);
clk = tegra_clk_register_periph_gate("emc", "emc_mux", 0, clk_base,
CLK_IGNORE_UNUSED, 57, &periph_h_regs,
periph_clk_enb_refcnt);
clks[emc] = clk;
for (i = 0; i < ARRAY_SIZE(tegra_periph_clk_list); i++) {
data = &tegra_periph_clk_list[i];
clk = tegra_clk_register_periph(data->name, data->parent_names,
data->num_parents, &data->periph,
clk_base, data->offset, data->flags);
clks[data->clk_id] = clk;
}
for (i = 0; i < ARRAY_SIZE(tegra_periph_nodiv_clk_list); i++) {
data = &tegra_periph_nodiv_clk_list[i];
clk = tegra_clk_register_periph_nodiv(data->name,
data->parent_names, data->num_parents,
&data->periph, clk_base, data->offset);
clks[data->clk_id] = clk;
}
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
tegra_init_from_table(init_table, clks, clk_max);
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
int i;
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
if (tegra114_osc_clk_init(clk_base) < 0)
return;
tegra114_fixed_clk_init(clk_base);
tegra114_pll_init(clk_base, pmc_base);
tegra114_periph_clk_init(clk_base);
tegra114_audio_clk_init(clk_base);
tegra114_pmc_clk_init(pmc_base);
tegra114_super_clk_init(clk_base);
for (i = 0; i < ARRAY_SIZE(clks); i++) {
if (IS_ERR(clks[i])) {
pr_err
("Tegra114 clk %d: register failed with %ld\n",
i, PTR_ERR(clks[i]));
}
if (!clks[i])
clks[i] = ERR_PTR(-EINVAL);
}
clk_data.clks = clks;
clk_data.clk_num = ARRAY_SIZE(clks);
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
tegra_clk_apply_init_table = tegra114_clock_apply_init_table;
tegra_cpu_car_ops = &tegra114_cpu_car_ops;
}
