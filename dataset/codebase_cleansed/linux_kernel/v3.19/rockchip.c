static void __init rockchip_timer_init(void)
{
if (of_machine_is_compatible("rockchip,rk3288")) {
struct regmap *grf;
grf = syscon_regmap_lookup_by_compatible("rockchip,rk3288-grf");
if (!IS_ERR(grf))
regmap_write(grf, RK3288_GRF_SOC_CON0, 0x10000000);
else
pr_err("rockchip: could not get grf syscon\n");
}
of_clk_init(NULL);
clocksource_of_init();
}
static void __init rockchip_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
platform_device_register_simple("cpufreq-dt", 0, NULL, 0);
}
