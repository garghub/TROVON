void __init armada_370_xp_map_io(void)
{
iotable_init(armada_370_xp_io_desc, ARRAY_SIZE(armada_370_xp_io_desc));
}
void __init armada_370_xp_timer_and_clk_init(void)
{
mvebu_clocks_init();
armada_370_xp_timer_init();
}
void __init armada_370_xp_init_early(void)
{
init_dma_coherent_pool_size(SZ_1M);
}
static void __init armada_370_xp_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
coherency_init();
}
