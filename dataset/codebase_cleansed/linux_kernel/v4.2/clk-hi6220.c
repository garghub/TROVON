static void __init hi6220_clk_ao_init(struct device_node *np)
{
struct hisi_clock_data *clk_data_ao;
clk_data_ao = hisi_clk_init(np, HI6220_AO_NR_CLKS);
if (!clk_data_ao)
return;
hisi_clk_register_fixed_rate(hi6220_fixed_rate_clks,
ARRAY_SIZE(hi6220_fixed_rate_clks), clk_data_ao);
hisi_clk_register_fixed_factor(hi6220_fixed_factor_clks,
ARRAY_SIZE(hi6220_fixed_factor_clks), clk_data_ao);
hisi_clk_register_gate_sep(hi6220_separated_gate_clks_ao,
ARRAY_SIZE(hi6220_separated_gate_clks_ao), clk_data_ao);
}
static void __init hi6220_clk_sys_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
clk_data = hisi_clk_init(np, HI6220_SYS_NR_CLKS);
if (!clk_data)
return;
hisi_clk_register_gate_sep(hi6220_separated_gate_clks_sys,
ARRAY_SIZE(hi6220_separated_gate_clks_sys), clk_data);
hisi_clk_register_mux(hi6220_mux_clks_sys,
ARRAY_SIZE(hi6220_mux_clks_sys), clk_data);
hi6220_clk_register_divider(hi6220_div_clks_sys,
ARRAY_SIZE(hi6220_div_clks_sys), clk_data);
}
static void __init hi6220_clk_media_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
clk_data = hisi_clk_init(np, HI6220_MEDIA_NR_CLKS);
if (!clk_data)
return;
hisi_clk_register_gate_sep(hi6220_separated_gate_clks_media,
ARRAY_SIZE(hi6220_separated_gate_clks_media), clk_data);
hisi_clk_register_mux(hi6220_mux_clks_media,
ARRAY_SIZE(hi6220_mux_clks_media), clk_data);
hi6220_clk_register_divider(hi6220_div_clks_media,
ARRAY_SIZE(hi6220_div_clks_media), clk_data);
}
static void __init hi6220_clk_power_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
clk_data = hisi_clk_init(np, HI6220_POWER_NR_CLKS);
if (!clk_data)
return;
hisi_clk_register_gate(hi6220_gate_clks_power,
ARRAY_SIZE(hi6220_gate_clks_power), clk_data);
hi6220_clk_register_divider(hi6220_div_clks_power,
ARRAY_SIZE(hi6220_div_clks_power), clk_data);
}
