void __init armada_370_xp_map_io(void)
{
iotable_init(armada_370_xp_io_desc, ARRAY_SIZE(armada_370_xp_io_desc));
}
static void __init armada_370_xp_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
