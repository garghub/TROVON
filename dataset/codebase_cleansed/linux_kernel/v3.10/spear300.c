static void __init spear300_dt_init(void)
{
pl080_plat_data.slave_channels = spear300_dma_info;
pl080_plat_data.num_slave_channels = ARRAY_SIZE(spear300_dma_info);
of_platform_populate(NULL, of_default_bus_match_table,
spear300_auxdata_lookup, NULL);
}
static void __init spear300_map_io(void)
{
spear3xx_map_io();
}
