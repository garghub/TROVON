static void __init hip04_clk_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
clk_data = hisi_clk_init(np, HIP04_NR_CLKS);
if (!clk_data)
return;
hisi_clk_register_fixed_rate(hip04_fixed_rate_clks,
ARRAY_SIZE(hip04_fixed_rate_clks),
clk_data);
}
