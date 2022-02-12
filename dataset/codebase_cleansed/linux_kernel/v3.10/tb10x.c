static void __init tb10x_platform_init(void)
{
of_clk_init(NULL);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
