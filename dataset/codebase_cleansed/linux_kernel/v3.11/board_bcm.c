static int __init kona_l2_cache_init(void)
{
if (!IS_ENABLED(CONFIG_CACHE_L2X0))
return 0;
bcm_kona_smc(SSAPI_ENABLE_L2_CACHE, 0, 0, 0, 0);
l2x0_of_init(0, ~0);
return 0;
}
static void __init board_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL,
&platform_bus);
bcm_kona_smc_init();
kona_l2_cache_init();
}
