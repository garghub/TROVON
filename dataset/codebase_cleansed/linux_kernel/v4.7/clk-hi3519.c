static int hi3519_clk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct hisi_clock_data *clk_data;
struct hisi_reset_controller *rstc;
rstc = hisi_reset_init(np);
if (!rstc)
return -ENOMEM;
clk_data = hisi_clk_init(np, HI3519_NR_CLKS);
if (!clk_data) {
hisi_reset_exit(rstc);
return -ENODEV;
}
hisi_clk_register_fixed_rate(hi3519_fixed_rate_clks,
ARRAY_SIZE(hi3519_fixed_rate_clks),
clk_data);
hisi_clk_register_mux(hi3519_mux_clks, ARRAY_SIZE(hi3519_mux_clks),
clk_data);
hisi_clk_register_gate(hi3519_gate_clks,
ARRAY_SIZE(hi3519_gate_clks), clk_data);
return 0;
}
static int __init hi3519_clk_init(void)
{
return platform_driver_register(&hi3519_clk_driver);
}
