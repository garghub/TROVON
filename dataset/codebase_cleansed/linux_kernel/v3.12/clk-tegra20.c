static unsigned long tegra20_clk_measure_input_freq(void)
{
u32 osc_ctrl = readl_relaxed(clk_base + OSC_CTRL);
u32 auto_clk_control = osc_ctrl & OSC_CTRL_OSC_FREQ_MASK;
u32 pll_ref_div = osc_ctrl & OSC_CTRL_PLL_REF_DIV_MASK;
unsigned long input_freq;
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
default:
pr_err("Unexpected clock autodetect value %d",
auto_clk_control);
BUG();
return 0;
}
return input_freq;
}
static unsigned int tegra20_get_pll_ref_div(void)
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
pr_err("Invalied pll ref divider %d\n", pll_ref_div);
BUG();
}
return 0;
}
static void tegra20_pll_init(void)
{
struct clk *clk;
clk = tegra_clk_register_pll("pll_c", "pll_ref", clk_base, NULL, 0,
0, &pll_c_params, TEGRA_PLL_HAS_CPCON,
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
clk = tegra_clk_register_pll("pll_p", "pll_ref", clk_base, NULL, 0,
216000000, &pll_p_params, TEGRA_PLL_FIXED |
TEGRA_PLL_HAS_CPCON, pll_p_freq_table, NULL);
clk_register_clkdev(clk, "pll_p", NULL);
clks[pll_p] = clk;
clk = tegra_clk_register_divider("pll_p_out1_div", "pll_p",
clk_base + PLLP_OUTA, 0,
TEGRA_DIVIDER_FIXED | TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, &pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out1", "pll_p_out1_div",
clk_base + PLLP_OUTA, 1, 0,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out1", NULL);
clks[pll_p_out1] = clk;
clk = tegra_clk_register_divider("pll_p_out2_div", "pll_p",
clk_base + PLLP_OUTA, 0,
TEGRA_DIVIDER_FIXED | TEGRA_DIVIDER_ROUND_UP,
24, 8, 1, &pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out2", "pll_p_out2_div",
clk_base + PLLP_OUTA, 17, 16,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out2", NULL);
clks[pll_p_out2] = clk;
clk = tegra_clk_register_divider("pll_p_out3_div", "pll_p",
clk_base + PLLP_OUTB, 0,
TEGRA_DIVIDER_FIXED | TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, &pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out3", "pll_p_out3_div",
clk_base + PLLP_OUTB, 1, 0,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out3", NULL);
clks[pll_p_out3] = clk;
clk = tegra_clk_register_divider("pll_p_out4_div", "pll_p",
clk_base + PLLP_OUTB, 0,
TEGRA_DIVIDER_FIXED | TEGRA_DIVIDER_ROUND_UP,
24, 8, 1, &pll_div_lock);
clk = tegra_clk_register_pll_out("pll_p_out4", "pll_p_out4_div",
clk_base + PLLP_OUTB, 17, 16,
CLK_IGNORE_UNUSED | CLK_SET_RATE_PARENT, 0,
&pll_div_lock);
clk_register_clkdev(clk, "pll_p_out4", NULL);
clks[pll_p_out4] = clk;
clk = tegra_clk_register_pll("pll_m", "pll_ref", clk_base, NULL,
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE, 0,
&pll_m_params, TEGRA_PLL_HAS_CPCON,
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
clk = tegra_clk_register_pll("pll_x", "pll_ref", clk_base, NULL, 0,
0, &pll_x_params, TEGRA_PLL_HAS_CPCON,
pll_x_freq_table, NULL);
clk_register_clkdev(clk, "pll_x", NULL);
clks[pll_x] = clk;
clk = tegra_clk_register_pll("pll_u", "pll_ref", clk_base, NULL, 0,
0, &pll_u_params, TEGRA_PLLU | TEGRA_PLL_HAS_CPCON,
pll_u_freq_table, NULL);
clk_register_clkdev(clk, "pll_u", NULL);
clks[pll_u] = clk;
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, NULL, 0,
0, &pll_d_params, TEGRA_PLL_HAS_CPCON,
pll_d_freq_table, NULL);
clk_register_clkdev(clk, "pll_d", NULL);
clks[pll_d] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clk_register_clkdev(clk, "pll_d_out0", NULL);
clks[pll_d_out0] = clk;
clk = tegra_clk_register_pll("pll_a", "pll_p_out1", clk_base, NULL, 0,
0, &pll_a_params, TEGRA_PLL_HAS_CPCON,
pll_a_freq_table, NULL);
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
clk = tegra_clk_register_plle("pll_e", "pll_ref", clk_base, pmc_base,
0, 100000000, &pll_e_params,
0, pll_e_freq_table, NULL);
clk_register_clkdev(clk, "pll_e", NULL);
clks[pll_e] = clk;
}
static void tegra20_super_clk_init(void)
{
struct clk *clk;
clk = tegra_clk_register_super_mux("cclk", cclk_parents,
ARRAY_SIZE(cclk_parents), CLK_SET_RATE_PARENT,
clk_base + CCLK_BURST_POLICY, 0, 4, 0, 0, NULL);
clk_register_clkdev(clk, "cclk", NULL);
clks[cclk] = clk;
clk = tegra_clk_register_super_mux("sclk", sclk_parents,
ARRAY_SIZE(sclk_parents), CLK_SET_RATE_PARENT,
clk_base + SCLK_BURST_POLICY, 0, 4, 0, 0, NULL);
clk_register_clkdev(clk, "sclk", NULL);
clks[sclk] = clk;
clk = clk_register_divider(NULL, "hclk_div", "sclk", 0,
clk_base + CLK_SYSTEM_RATE, 4, 2, 0,
&sysrate_lock);
clk = clk_register_gate(NULL, "hclk", "hclk_div", CLK_SET_RATE_PARENT,
clk_base + CLK_SYSTEM_RATE, 7,
CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
clk_register_clkdev(clk, "hclk", NULL);
clks[hclk] = clk;
clk = clk_register_divider(NULL, "pclk_div", "hclk", 0,
clk_base + CLK_SYSTEM_RATE, 0, 2, 0,
&sysrate_lock);
clk = clk_register_gate(NULL, "pclk", "pclk_div", CLK_SET_RATE_PARENT,
clk_base + CLK_SYSTEM_RATE, 3,
CLK_GATE_SET_TO_DISABLE, &sysrate_lock);
clk_register_clkdev(clk, "pclk", NULL);
clks[pclk] = clk;
clk = clk_register_fixed_factor(NULL, "twd", "cclk", 0, 1, 4);
clk_register_clkdev(clk, "twd", NULL);
clks[twd] = clk;
}
static void __init tegra20_audio_clk_init(void)
{
struct clk *clk;
clk = clk_register_mux(NULL, "audio_mux", audio_parents,
ARRAY_SIZE(audio_parents),
CLK_SET_RATE_NO_REPARENT,
clk_base + AUDIO_SYNC_CLK, 0, 3, 0, NULL);
clk = clk_register_gate(NULL, "audio", "audio_mux", 0,
clk_base + AUDIO_SYNC_CLK, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
clk_register_clkdev(clk, "audio", NULL);
clks[audio] = clk;
clk = clk_register_fixed_factor(NULL, "audio_doubler", "audio",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_periph_gate("audio_2x", "audio_doubler",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 89, &periph_u_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "audio_2x", NULL);
clks[audio_2x] = clk;
}
static void __init tegra20_periph_clk_init(void)
{
struct tegra_periph_init_data *data;
struct clk *clk;
int i;
clk = tegra_clk_register_periph_gate("ac97", "pll_a_out0",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 3, &periph_l_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra20-ac97");
clks[ac97] = clk;
clk = tegra_clk_register_periph_gate("apbdma", "pclk", 0, clk_base,
0, 34, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra-apbdma");
clks[apbdma] = clk;
clk = tegra_clk_register_periph_gate("rtc", "clk_32k",
TEGRA_PERIPH_NO_RESET,
clk_base, 0, 4, &periph_l_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "rtc-tegra");
clks[rtc] = clk;
clk = tegra_clk_register_periph_gate("timer", "clk_m", 0, clk_base,
0, 5, &periph_l_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "timer");
clks[timer] = clk;
clk = tegra_clk_register_periph_gate("kbc", "clk_32k",
TEGRA_PERIPH_NO_RESET | TEGRA_PERIPH_ON_APB,
clk_base, 0, 36, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "tegra-kbc");
clks[kbc] = clk;
clk = tegra_clk_register_periph_gate("csus", "clk_m",
TEGRA_PERIPH_NO_RESET,
clk_base, 0, 92, &periph_u_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "csus", "tengra_camera");
clks[csus] = clk;
clk = tegra_clk_register_periph_gate("vcp", "clk_m", 0,
clk_base, 0, 29, &periph_l_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "vcp", "tegra-avp");
clks[vcp] = clk;
clk = tegra_clk_register_periph_gate("bsea", "clk_m", 0,
clk_base, 0, 62, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "bsea", "tegra-avp");
clks[bsea] = clk;
clk = tegra_clk_register_periph_gate("bsev", "clk_m", 0,
clk_base, 0, 63, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "bsev", "tegra-aes");
clks[bsev] = clk;
clk = clk_register_mux(NULL, "emc_mux", mux_pllmcp_clkm,
ARRAY_SIZE(mux_pllmcp_clkm),
CLK_SET_RATE_NO_REPARENT,
clk_base + CLK_SOURCE_EMC,
30, 2, 0, NULL);
clk = tegra_clk_register_periph_gate("emc", "emc_mux", 0, clk_base, 0,
57, &periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "emc", NULL);
clks[emc] = clk;
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
clk = tegra_clk_register_periph_gate("dsi", "pll_d", 0, clk_base, 0,
48, &periph_h_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "dsi");
clks[dsi] = clk;
clk = tegra_clk_register_periph_gate("csi", "pll_p_out3", 0, clk_base,
0, 52, &periph_h_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "csi", "tegra_camera");
clks[csi] = clk;
clk = tegra_clk_register_periph_gate("isp", "clk_m", 0, clk_base, 0, 23,
&periph_l_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "isp", "tegra_camera");
clks[isp] = clk;
clk = tegra_clk_register_periph_gate("pex", "clk_m", 0, clk_base, 0, 70,
&periph_u_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "pex", NULL);
clks[pex] = clk;
clk = tegra_clk_register_periph_gate("afi", "clk_m", 0, clk_base, 0, 72,
&periph_u_regs, periph_clk_enb_refcnt);
clk_register_clkdev(clk, "afi", NULL);
clks[afi] = clk;
clk = tegra_clk_register_periph_gate("pcie_xclk", "clk_m", 0, clk_base,
0, 74, &periph_u_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "pcie_xclk", NULL);
clks[pcie_xclk] = clk;
clk = clk_register_fixed_rate(NULL, "cdev1_fixed", NULL, CLK_IS_ROOT,
26000000);
clk = tegra_clk_register_periph_gate("cdev1", "cdev1_fixed", 0,
clk_base, 0, 94, &periph_u_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "cdev1", NULL);
clks[cdev1] = clk;
clk = clk_register_fixed_rate(NULL, "cdev2_fixed", NULL, CLK_IS_ROOT,
26000000);
clk = tegra_clk_register_periph_gate("cdev2", "cdev2_fixed", 0,
clk_base, 0, 93, &periph_u_regs,
periph_clk_enb_refcnt);
clk_register_clkdev(clk, "cdev2", NULL);
clks[cdev2] = clk;
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
static void __init tegra20_fixed_clk_init(void)
{
struct clk *clk;
clk = clk_register_fixed_rate(NULL, "clk_32k", NULL, CLK_IS_ROOT,
32768);
clk_register_clkdev(clk, "clk_32k", NULL);
clks[clk_32k] = clk;
}
static void __init tegra20_pmc_clk_init(void)
{
struct clk *clk;
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
static void __init tegra20_osc_clk_init(void)
{
struct clk *clk;
unsigned long input_freq;
unsigned int pll_ref_div;
input_freq = tegra20_clk_measure_input_freq();
clk = clk_register_fixed_rate(NULL, "clk_m", NULL, CLK_IS_ROOT |
CLK_IGNORE_UNUSED, input_freq);
clk_register_clkdev(clk, "clk_m", NULL);
clks[clk_m] = clk;
pll_ref_div = tegra20_get_pll_ref_div();
clk = clk_register_fixed_factor(NULL, "pll_ref", "clk_m",
CLK_SET_RATE_PARENT, 1, pll_ref_div);
clk_register_clkdev(clk, "pll_ref", NULL);
clks[pll_ref] = clk;
}
static void tegra20_wait_cpu_in_reset(u32 cpu)
{
unsigned int reg;
do {
reg = readl(clk_base +
TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET);
cpu_relax();
} while (!(reg & (1 << cpu)));
return;
}
static void tegra20_put_cpu_in_reset(u32 cpu)
{
writel(CPU_RESET(cpu),
clk_base + TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET);
dmb();
}
static void tegra20_cpu_out_of_reset(u32 cpu)
{
writel(CPU_RESET(cpu),
clk_base + TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_CLR);
wmb();
}
static void tegra20_enable_cpu_clock(u32 cpu)
{
unsigned int reg;
reg = readl(clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
writel(reg & ~CPU_CLOCK(cpu),
clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
barrier();
reg = readl(clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
}
static void tegra20_disable_cpu_clock(u32 cpu)
{
unsigned int reg;
reg = readl(clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
writel(reg | CPU_CLOCK(cpu),
clk_base + TEGRA_CLK_RST_CONTROLLER_CLK_CPU_CMPLX);
}
static bool tegra20_cpu_rail_off_ready(void)
{
unsigned int cpu_rst_status;
cpu_rst_status = readl(clk_base +
TEGRA_CLK_RST_CONTROLLER_RST_CPU_CMPLX_SET);
return !!(cpu_rst_status & 0x2);
}
static void tegra20_cpu_clock_suspend(void)
{
tegra20_cpu_clk_sctx.clk_csite_src =
readl(clk_base + CLK_SOURCE_CSITE);
writel(3<<30, clk_base + CLK_SOURCE_CSITE);
tegra20_cpu_clk_sctx.cpu_burst =
readl(clk_base + CCLK_BURST_POLICY);
tegra20_cpu_clk_sctx.pllx_base =
readl(clk_base + PLLX_BASE);
tegra20_cpu_clk_sctx.pllx_misc =
readl(clk_base + PLLX_MISC);
tegra20_cpu_clk_sctx.cclk_divider =
readl(clk_base + SUPER_CCLK_DIVIDER);
}
static void tegra20_cpu_clock_resume(void)
{
unsigned int reg, policy;
reg = readl(clk_base + CCLK_BURST_POLICY);
policy = (reg >> CCLK_BURST_POLICY_SHIFT) & 0xF;
if (policy == CCLK_IDLE_POLICY)
reg = (reg >> CCLK_IDLE_POLICY_SHIFT) & 0xF;
else if (policy == CCLK_RUN_POLICY)
reg = (reg >> CCLK_RUN_POLICY_SHIFT) & 0xF;
else
BUG();
if (reg != CCLK_BURST_POLICY_PLLX) {
writel(tegra20_cpu_clk_sctx.pllx_misc,
clk_base + PLLX_MISC);
writel(tegra20_cpu_clk_sctx.pllx_base,
clk_base + PLLX_BASE);
if (tegra20_cpu_clk_sctx.pllx_base & (1 << 30))
udelay(300);
}
writel(tegra20_cpu_clk_sctx.cclk_divider,
clk_base + SUPER_CCLK_DIVIDER);
writel(tegra20_cpu_clk_sctx.cpu_burst,
clk_base + CCLK_BURST_POLICY);
writel(tegra20_cpu_clk_sctx.clk_csite_src,
clk_base + CLK_SOURCE_CSITE);
}
static void __init tegra20_clock_apply_init_table(void)
{
tegra_init_from_table(init_table, clks, clk_max);
}
static void __init tegra20_clock_init(struct device_node *np)
{
int i;
struct device_node *node;
clk_base = of_iomap(np, 0);
if (!clk_base) {
pr_err("Can't map CAR registers\n");
BUG();
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
tegra20_osc_clk_init();
tegra20_pmc_clk_init();
tegra20_fixed_clk_init();
tegra20_pll_init();
tegra20_super_clk_init();
tegra20_periph_clk_init();
tegra20_audio_clk_init();
for (i = 0; i < ARRAY_SIZE(clks); i++) {
if (IS_ERR(clks[i])) {
pr_err("Tegra20 clk %d: register failed with %ld\n",
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
tegra_clk_apply_init_table = tegra20_clock_apply_init_table;
tegra_cpu_car_ops = &tegra20_cpu_car_ops;
}
