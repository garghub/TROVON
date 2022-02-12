static void __init pxa168_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
pxa168_auxdata_lookup, NULL);
}
static void __init pxa910_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
pxa910_auxdata_lookup, NULL);
}
