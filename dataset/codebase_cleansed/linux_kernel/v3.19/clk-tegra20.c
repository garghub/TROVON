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
&pll_c_params, NULL);
clks[TEGRA20_CLK_PLL_C] = clk;
clk = tegra_clk_register_divider("pll_c_out1_div", "pll_c",
clk_base + PLLC_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_c_out1", "pll_c_out1_div",
clk_base + PLLC_OUT, 1, 0, CLK_SET_RATE_PARENT,
0, NULL);
clks[TEGRA20_CLK_PLL_C_OUT1] = clk;
clk = tegra_clk_register_pll("pll_m", "pll_ref", clk_base, NULL,
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE,
&pll_m_params, NULL);
clks[TEGRA20_CLK_PLL_M] = clk;
clk = tegra_clk_register_divider("pll_m_out1_div", "pll_m",
clk_base + PLLM_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_m_out1", "pll_m_out1_div",
clk_base + PLLM_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
clks[TEGRA20_CLK_PLL_M_OUT1] = clk;
clk = tegra_clk_register_pll("pll_x", "pll_ref", clk_base, NULL, 0,
&pll_x_params, NULL);
clks[TEGRA20_CLK_PLL_X] = clk;
clk = tegra_clk_register_pll("pll_u", "pll_ref", clk_base, NULL, 0,
&pll_u_params, NULL);
clks[TEGRA20_CLK_PLL_U] = clk;
clk = tegra_clk_register_pll("pll_d", "pll_ref", clk_base, NULL, 0,
&pll_d_params, NULL);
clks[TEGRA20_CLK_PLL_D] = clk;
clk = clk_register_fixed_factor(NULL, "pll_d_out0", "pll_d",
CLK_SET_RATE_PARENT, 1, 2);
clks[TEGRA20_CLK_PLL_D_OUT0] = clk;
clk = tegra_clk_register_pll("pll_a", "pll_p_out1", clk_base, NULL, 0,
&pll_a_params, NULL);
clks[TEGRA20_CLK_PLL_A] = clk;
clk = tegra_clk_register_divider("pll_a_out0_div", "pll_a",
clk_base + PLLA_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_a_out0", "pll_a_out0_div",
clk_base + PLLA_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
clks[TEGRA20_CLK_PLL_A_OUT0] = clk;
clk = tegra_clk_register_plle("pll_e", "pll_ref", clk_base, pmc_base,
0, &pll_e_params, NULL);
clks[TEGRA20_CLK_PLL_E] = clk;
}
static void tegra20_super_clk_init(void)
{
struct clk *clk;
clk = tegra_clk_register_super_mux("cclk", cclk_parents,
ARRAY_SIZE(cclk_parents), CLK_SET_RATE_PARENT,
clk_base + CCLK_BURST_POLICY, 0, 4, 0, 0, NULL);
clks[TEGRA20_CLK_CCLK] = clk;
clk = tegra_clk_register_super_mux("sclk", sclk_parents,
ARRAY_SIZE(sclk_parents), CLK_SET_RATE_PARENT,
clk_base + SCLK_BURST_POLICY, 0, 4, 0, 0, NULL);
clks[TEGRA20_CLK_SCLK] = clk;
clk = clk_register_fixed_factor(NULL, "twd", "cclk", 0, 1, 4);
clks[TEGRA20_CLK_TWD] = clk;
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
clks[TEGRA20_CLK_AUDIO] = clk;
clk = clk_register_fixed_factor(NULL, "audio_doubler", "audio",
CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_periph_gate("audio_2x", "audio_doubler",
TEGRA_PERIPH_NO_RESET, clk_base,
CLK_SET_RATE_PARENT, 89,
periph_clk_enb_refcnt);
clks[TEGRA20_CLK_AUDIO_2X] = clk;
}
static void __init tegra20_periph_clk_init(void)
{
struct tegra_periph_init_data *data;
struct clk *clk;
int i;
clk = tegra_clk_register_periph_gate("ac97", "pll_a_out0",
TEGRA_PERIPH_ON_APB,
clk_base, 0, 3, periph_clk_enb_refcnt);
clks[TEGRA20_CLK_AC97] = clk;
clk = tegra_clk_register_periph_gate("apbdma", "pclk", 0, clk_base,
0, 34, periph_clk_enb_refcnt);
clks[TEGRA20_CLK_APBDMA] = clk;
clk = clk_register_mux(NULL, "emc_mux", mux_pllmcp_clkm,
ARRAY_SIZE(mux_pllmcp_clkm),
CLK_SET_RATE_NO_REPARENT,
clk_base + CLK_SOURCE_EMC,
30, 2, 0, &emc_lock);
clk = tegra_clk_register_periph_gate("emc", "emc_mux", 0, clk_base, 0,
57, periph_clk_enb_refcnt);
clks[TEGRA20_CLK_EMC] = clk;
clk = tegra_clk_register_mc("mc", "emc_mux", clk_base + CLK_SOURCE_EMC,
&emc_lock);
clks[TEGRA20_CLK_MC] = clk;
clk = tegra_clk_register_periph_gate("dsi", "pll_d", 0, clk_base, 0,
48, periph_clk_enb_refcnt);
clk_register_clkdev(clk, NULL, "dsi");
clks[TEGRA20_CLK_DSI] = clk;
clk = tegra_clk_register_periph_gate("pex", "clk_m", 0, clk_base, 0, 70,
periph_clk_enb_refcnt);
clks[TEGRA20_CLK_PEX] = clk;
clk = clk_register_fixed_rate(NULL, "cdev1_fixed", NULL, CLK_IS_ROOT,
26000000);
clk = tegra_clk_register_periph_gate("cdev1", "cdev1_fixed", 0,
clk_base, 0, 94, periph_clk_enb_refcnt);
clks[TEGRA20_CLK_CDEV1] = clk;
clk = clk_register_fixed_rate(NULL, "cdev2_fixed", NULL, CLK_IS_ROOT,
26000000);
clk = tegra_clk_register_periph_gate("cdev2", "cdev2_fixed", 0,
clk_base, 0, 93, periph_clk_enb_refcnt);
clks[TEGRA20_CLK_CDEV2] = clk;
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
tegra_periph_clk_init(clk_base, pmc_base, tegra20_clks, &pll_p_params);
}
static void __init tegra20_osc_clk_init(void)
{
struct clk *clk;
unsigned long input_freq;
unsigned int pll_ref_div;
input_freq = tegra20_clk_measure_input_freq();
clk = clk_register_fixed_rate(NULL, "clk_m", NULL, CLK_IS_ROOT |
CLK_IGNORE_UNUSED, input_freq);
clks[TEGRA20_CLK_CLK_M] = clk;
pll_ref_div = tegra20_get_pll_ref_div();
clk = clk_register_fixed_factor(NULL, "pll_ref", "clk_m",
CLK_SET_RATE_PARENT, 1, pll_ref_div);
clks[TEGRA20_CLK_PLL_REF] = clk;
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
tegra_init_from_table(init_table, clks, TEGRA20_CLK_CLK_MAX);
}
static void __init tegra20_clock_init(struct device_node *np)
{
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
clks = tegra_clk_init(clk_base, TEGRA20_CLK_CLK_MAX,
TEGRA20_CLK_PERIPH_BANKS);
if (!clks)
return;
tegra20_osc_clk_init();
tegra_fixed_clk_init(tegra20_clks);
tegra20_pll_init();
tegra20_super_clk_init();
tegra_super_clk_gen4_init(clk_base, pmc_base, tegra20_clks, NULL);
tegra20_periph_clk_init();
tegra20_audio_clk_init();
tegra_pmc_clk_init(pmc_base, tegra20_clks);
tegra_init_dup_clks(tegra_clk_duplicates, clks, TEGRA20_CLK_CLK_MAX);
tegra_add_of_provider(np);
tegra_register_devclks(devclks, ARRAY_SIZE(devclks));
tegra_clk_apply_init_table = tegra20_clock_apply_init_table;
tegra_cpu_car_ops = &tegra20_cpu_car_ops;
}
