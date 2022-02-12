static void __init virt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
