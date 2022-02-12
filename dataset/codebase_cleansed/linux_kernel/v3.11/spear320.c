static void __init spear320_dt_init(void)
{
pl080_plat_data.slave_channels = spear320_dma_info;
pl080_plat_data.num_slave_channels = ARRAY_SIZE(spear320_dma_info);
of_platform_populate(NULL, of_default_bus_match_table,
spear320_auxdata_lookup, NULL);
}
static void __init spear320_map_io(void)
{
iotable_init(spear320_io_desc, ARRAY_SIZE(spear320_io_desc));
spear3xx_map_io();
}
