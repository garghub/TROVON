static void __init berlin_init_machine(void)
{
l2x0_of_init(0x70c00000, 0xfeffffff);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
