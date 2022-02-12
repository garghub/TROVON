static void __init tegra30_dt_init(void)
{
of_platform_populate(NULL, tegra_dt_match_table,
NULL, NULL);
}
