static void __init tegra30_dt_init(void)
{
tegra_clk_init_from_table(tegra_dt_clk_init_table);
of_platform_populate(NULL, tegra_dt_match_table,
tegra30_auxdata_lookup, NULL);
}
