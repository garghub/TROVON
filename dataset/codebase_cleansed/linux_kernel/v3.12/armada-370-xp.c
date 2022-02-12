static void __init armada_370_xp_map_io(void)
{
debug_ll_io_init();
}
static void __init armada_370_xp_timer_and_clk_init(void)
{
of_clk_init(NULL);
clocksource_of_init();
coherency_init();
BUG_ON(mvebu_mbus_dt_init());
#ifdef CONFIG_CACHE_L2X0
l2x0_of_init(0, ~0UL);
#endif
}
static void __init armada_370_xp_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
