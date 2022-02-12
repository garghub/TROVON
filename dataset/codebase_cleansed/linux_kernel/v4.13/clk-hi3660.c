static void hi3660_clk_iomcu_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
int nr = ARRAY_SIZE(hi3660_iomcu_gate_sep_clks);
clk_data = hisi_clk_init(np, nr);
if (!clk_data)
return;
hisi_clk_register_gate_sep(hi3660_iomcu_gate_sep_clks,
ARRAY_SIZE(hi3660_iomcu_gate_sep_clks),
clk_data);
}
static void hi3660_clk_pmuctrl_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
int nr = ARRAY_SIZE(hi3660_pmu_gate_clks);
clk_data = hisi_clk_init(np, nr);
if (!clk_data)
return;
hisi_clk_register_gate(hi3660_pmu_gate_clks,
ARRAY_SIZE(hi3660_pmu_gate_clks), clk_data);
}
static void hi3660_clk_pctrl_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
int nr = ARRAY_SIZE(hi3660_pctrl_gate_clks);
clk_data = hisi_clk_init(np, nr);
if (!clk_data)
return;
hisi_clk_register_gate(hi3660_pctrl_gate_clks,
ARRAY_SIZE(hi3660_pctrl_gate_clks), clk_data);
}
static void hi3660_clk_sctrl_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
int nr = ARRAY_SIZE(hi3660_sctrl_gate_clks) +
ARRAY_SIZE(hi3660_sctrl_gate_sep_clks) +
ARRAY_SIZE(hi3660_sctrl_mux_clks) +
ARRAY_SIZE(hi3660_sctrl_divider_clks);
clk_data = hisi_clk_init(np, nr);
if (!clk_data)
return;
hisi_clk_register_gate(hi3660_sctrl_gate_clks,
ARRAY_SIZE(hi3660_sctrl_gate_clks), clk_data);
hisi_clk_register_gate_sep(hi3660_sctrl_gate_sep_clks,
ARRAY_SIZE(hi3660_sctrl_gate_sep_clks),
clk_data);
hisi_clk_register_mux(hi3660_sctrl_mux_clks,
ARRAY_SIZE(hi3660_sctrl_mux_clks), clk_data);
hisi_clk_register_divider(hi3660_sctrl_divider_clks,
ARRAY_SIZE(hi3660_sctrl_divider_clks),
clk_data);
}
static void hi3660_clk_crgctrl_early_init(struct device_node *np)
{
int nr = ARRAY_SIZE(hi3660_fixed_rate_clks) +
ARRAY_SIZE(hi3660_crgctrl_gate_sep_clks) +
ARRAY_SIZE(hi3660_crgctrl_gate_clks) +
ARRAY_SIZE(hi3660_crgctrl_mux_clks) +
ARRAY_SIZE(hi3660_crg_fixed_factor_clks) +
ARRAY_SIZE(hi3660_crgctrl_divider_clks);
int i;
clk_crgctrl_data = hisi_clk_init(np, nr);
if (!clk_crgctrl_data)
return;
for (i = 0; i < nr; i++)
clk_crgctrl_data->clk_data.clks[i] = ERR_PTR(-EPROBE_DEFER);
hisi_clk_register_fixed_rate(hi3660_fixed_rate_clks,
ARRAY_SIZE(hi3660_fixed_rate_clks),
clk_crgctrl_data);
}
static void hi3660_clk_crgctrl_init(struct device_node *np)
{
struct clk **clks;
int i;
if (!clk_crgctrl_data)
hi3660_clk_crgctrl_early_init(np);
if (!clk_crgctrl_data)
return;
hisi_clk_register_gate_sep(hi3660_crgctrl_gate_sep_clks,
ARRAY_SIZE(hi3660_crgctrl_gate_sep_clks),
clk_crgctrl_data);
hisi_clk_register_gate(hi3660_crgctrl_gate_clks,
ARRAY_SIZE(hi3660_crgctrl_gate_clks),
clk_crgctrl_data);
hisi_clk_register_mux(hi3660_crgctrl_mux_clks,
ARRAY_SIZE(hi3660_crgctrl_mux_clks),
clk_crgctrl_data);
hisi_clk_register_fixed_factor(hi3660_crg_fixed_factor_clks,
ARRAY_SIZE(hi3660_crg_fixed_factor_clks),
clk_crgctrl_data);
hisi_clk_register_divider(hi3660_crgctrl_divider_clks,
ARRAY_SIZE(hi3660_crgctrl_divider_clks),
clk_crgctrl_data);
clks = clk_crgctrl_data->clk_data.clks;
for (i = 0; i < clk_crgctrl_data->clk_data.clk_num; i++) {
if (IS_ERR(clks[i]) && PTR_ERR(clks[i]) != -EPROBE_DEFER)
pr_err("Failed to register crgctrl clock[%d] err=%ld\n",
i, PTR_ERR(clks[i]));
}
}
static int hi3660_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = pdev->dev.of_node;
void (*init_func)(struct device_node *np);
init_func = of_device_get_match_data(dev);
if (!init_func)
return -ENODEV;
init_func(np);
return 0;
}
static int __init hi3660_clk_init(void)
{
return platform_driver_register(&hi3660_clk_driver);
}
