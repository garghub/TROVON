int __init tegra_osc_clk_init(void __iomem *clk_base,
struct tegra_clk *tegra_clks,
unsigned long *input_freqs, int num,
unsigned long *osc_freq,
unsigned long *pll_ref_freq)
{
struct clk *clk;
struct clk **dt_clk;
u32 val, pll_ref_div;
unsigned osc_idx;
val = readl_relaxed(clk_base + OSC_CTRL);
osc_idx = val >> OSC_CTRL_OSC_FREQ_SHIFT;
if (osc_idx < num)
*osc_freq = input_freqs[osc_idx];
else
*osc_freq = 0;
if (!*osc_freq) {
WARN_ON(1);
return -EINVAL;
}
dt_clk = tegra_lookup_dt_id(tegra_clk_clk_m, tegra_clks);
if (!dt_clk)
return 0;
clk = clk_register_fixed_rate(NULL, "clk_m", NULL, CLK_IS_ROOT,
*osc_freq);
*dt_clk = clk;
val = (val >> OSC_CTRL_PLL_REF_DIV_SHIFT) & 3;
pll_ref_div = 1 << val;
dt_clk = tegra_lookup_dt_id(tegra_clk_pll_ref, tegra_clks);
if (!dt_clk)
return 0;
clk = clk_register_fixed_factor(NULL, "pll_ref", "clk_m",
0, 1, pll_ref_div);
*dt_clk = clk;
if (pll_ref_freq)
*pll_ref_freq = *osc_freq / pll_ref_div;
return 0;
}
void __init tegra_fixed_clk_init(struct tegra_clk *tegra_clks)
{
struct clk *clk;
struct clk **dt_clk;
dt_clk = tegra_lookup_dt_id(tegra_clk_clk_32k, tegra_clks);
if (dt_clk) {
clk = clk_register_fixed_rate(NULL, "clk_32k", NULL,
CLK_IS_ROOT, 32768);
*dt_clk = clk;
}
dt_clk = tegra_lookup_dt_id(tegra_clk_clk_m_div2, tegra_clks);
if (dt_clk) {
clk = clk_register_fixed_factor(NULL, "clk_m_div2", "clk_m",
CLK_SET_RATE_PARENT, 1, 2);
*dt_clk = clk;
}
dt_clk = tegra_lookup_dt_id(tegra_clk_clk_m_div4, tegra_clks);
if (dt_clk) {
clk = clk_register_fixed_factor(NULL, "clk_m_div4", "clk_m",
CLK_SET_RATE_PARENT, 1, 4);
*dt_clk = clk;
}
}
