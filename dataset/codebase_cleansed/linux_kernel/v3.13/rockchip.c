static void __init rockchip_dt_init(void)
{
l2x0_of_init(0, ~0UL);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
