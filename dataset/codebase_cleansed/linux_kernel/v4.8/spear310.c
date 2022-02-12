static void __init spear310_dt_init(void)
{
pl080_plat_data.slave_channels = spear310_dma_info;
pl080_plat_data.num_slave_channels = ARRAY_SIZE(spear310_dma_info);
of_platform_default_populate(NULL, spear310_auxdata_lookup, NULL);
}
static void __init spear310_map_io(void)
{
spear3xx_map_io();
}
