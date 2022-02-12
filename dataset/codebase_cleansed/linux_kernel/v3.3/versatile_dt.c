static void __init versatile_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
versatile_auxdata_lookup, NULL);
}
