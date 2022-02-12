static void timer_init(void)
{
}
static void __init board_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL,
&platform_bus);
}
