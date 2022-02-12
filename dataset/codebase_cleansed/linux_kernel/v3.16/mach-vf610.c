static void __init vf610_init_machine(void)
{
mxc_arch_reset_init_dt();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
