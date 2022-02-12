static void __init tegra_dt_init(void)
{
tegra_clk_init_from_table(tegra_dt_clk_init_table);
of_platform_populate(NULL, tegra_dt_match_table,
tegra20_auxdata_lookup, NULL);
}
