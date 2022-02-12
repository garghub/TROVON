static void __init virt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init virt_timer_init(void)
{
WARN_ON(arch_timer_of_register() != 0);
WARN_ON(arch_timer_sched_clock_init() != 0);
}
