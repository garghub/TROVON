void __init plat_time_init(void)
{
ralink_of_remap();
of_clk_init(NULL);
clocksource_probe();
}
