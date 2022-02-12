static void __init mmp2_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
mmp2_auxdata_lookup, NULL);
}
