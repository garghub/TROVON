static void __init tegra_audio_sync_clk_init(void __iomem *clk_base,
struct tegra_clk *tegra_clks,
struct tegra_audio_clk_initdata *sync,
int num_sync_clks,
const char * const *mux_names,
int num_mux_inputs)
{
struct clk *clk;
struct clk **dt_clk;
struct tegra_audio_clk_initdata *data;
int i;
for (i = 0, data = sync; i < num_sync_clks; i++, data++) {
dt_clk = tegra_lookup_dt_id(data->mux_clk_id, tegra_clks);
if (!dt_clk)
continue;
clk = clk_register_mux(NULL, data->mux_name, mux_names,
num_mux_inputs,
CLK_SET_RATE_NO_REPARENT,
clk_base + data->offset, 0, 3, 0,
NULL);
*dt_clk = clk;
dt_clk = tegra_lookup_dt_id(data->gate_clk_id, tegra_clks);
if (!dt_clk)
continue;
clk = clk_register_gate(NULL, data->gate_name, data->mux_name,
0, clk_base + data->offset, 4,
CLK_GATE_SET_TO_DISABLE, NULL);
*dt_clk = clk;
}
}
void __init tegra_audio_clk_init(void __iomem *clk_base,
void __iomem *pmc_base, struct tegra_clk *tegra_clks,
struct tegra_audio_clk_info *audio_info,
unsigned int num_plls)
{
struct clk *clk;
struct clk **dt_clk;
int i;
if (!audio_info || num_plls < 1) {
pr_err("No audio data passed to tegra_audio_clk_init\n");
WARN_ON(1);
return;
}
for (i = 0; i < num_plls; i++) {
struct tegra_audio_clk_info *info = &audio_info[i];
dt_clk = tegra_lookup_dt_id(info->clk_id, tegra_clks);
if (dt_clk) {
clk = tegra_clk_register_pll(info->name, info->parent,
clk_base, pmc_base, 0, info->pll_params,
NULL);
*dt_clk = clk;
}
}
dt_clk = tegra_lookup_dt_id(tegra_clk_pll_a_out0, tegra_clks);
if (dt_clk) {
clk = tegra_clk_register_divider("pll_a_out0_div", "pll_a",
clk_base + PLLA_OUT, 0, TEGRA_DIVIDER_ROUND_UP,
8, 8, 1, NULL);
clk = tegra_clk_register_pll_out("pll_a_out0", "pll_a_out0_div",
clk_base + PLLA_OUT, 1, 0, CLK_IGNORE_UNUSED |
CLK_SET_RATE_PARENT, 0, NULL);
*dt_clk = clk;
}
for (i = 0; i < ARRAY_SIZE(sync_source_clks); i++) {
struct tegra_sync_source_initdata *data;
data = &sync_source_clks[i];
dt_clk = tegra_lookup_dt_id(data->clk_id, tegra_clks);
if (!dt_clk)
continue;
clk = tegra_clk_register_sync_source(data->name,
data->rate, data->max_rate);
*dt_clk = clk;
}
tegra_audio_sync_clk_init(clk_base, tegra_clks, audio_clks,
ARRAY_SIZE(audio_clks), mux_audio_sync_clk,
ARRAY_SIZE(mux_audio_sync_clk));
for (i = 0; i < ARRAY_SIZE(dmic_clks); i++)
writel_relaxed(1, clk_base + dmic_clks[i].offset);
tegra_audio_sync_clk_init(clk_base, tegra_clks, dmic_clks,
ARRAY_SIZE(dmic_clks), mux_dmic_sync_clk,
ARRAY_SIZE(mux_dmic_sync_clk));
for (i = 0; i < ARRAY_SIZE(audio2x_clks); i++) {
struct tegra_audio2x_clk_initdata *data;
data = &audio2x_clks[i];
dt_clk = tegra_lookup_dt_id(data->clk_id, tegra_clks);
if (!dt_clk)
continue;
clk = clk_register_fixed_factor(NULL, data->name_2x,
data->parent, CLK_SET_RATE_PARENT, 2, 1);
clk = tegra_clk_register_divider(data->div_name,
data->name_2x, clk_base + AUDIO_SYNC_DOUBLER,
0, 0, data->div_offset, 1, 0,
&clk_doubler_lock);
clk = tegra_clk_register_periph_gate(data->gate_name,
data->div_name, TEGRA_PERIPH_NO_RESET,
clk_base, CLK_SET_RATE_PARENT, data->clk_num,
periph_clk_enb_refcnt);
*dt_clk = clk;
}
}
