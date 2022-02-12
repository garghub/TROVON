static void __init hix5hd2_clk_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
clk_data = hisi_clk_init(np, HIX5HD2_NR_CLKS);
if (!clk_data)
return;
hisi_clk_register_fixed_rate(hix5hd2_fixed_rate_clks,
ARRAY_SIZE(hix5hd2_fixed_rate_clks),
clk_data);
hisi_clk_register_mux(hix5hd2_mux_clks, ARRAY_SIZE(hix5hd2_mux_clks),
clk_data);
hisi_clk_register_gate(hix5hd2_gate_clks,
ARRAY_SIZE(hix5hd2_gate_clks), clk_data);
}
