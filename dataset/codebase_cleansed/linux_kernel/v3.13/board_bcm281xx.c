static int __init kona_l2_cache_init(void)
{
if (!IS_ENABLED(CONFIG_CACHE_L2X0))
return 0;
if (bcm_kona_smc_init() < 0) {
pr_info("Kona secure API not available. Skipping L2 init\n");
return 0;
}
bcm_kona_smc(SSAPI_ENABLE_L2_CACHE, 0, 0, 0, 0);
return l2x0_of_init(0, ~0);
}
static void bcm_board_setup_restart(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "brcm,bcm11351");
if (np) {
if (of_device_is_available(np))
bcm_kona_setup_restart();
of_node_put(np);
}
}
static void __init board_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL,
&platform_bus);
bcm_board_setup_restart();
kona_l2_cache_init();
}
