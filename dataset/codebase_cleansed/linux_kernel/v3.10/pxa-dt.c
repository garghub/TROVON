static void __init pxa3xx_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
pxa3xx_auxdata_lookup, NULL);
}
