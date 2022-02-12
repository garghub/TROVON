static void __init mmp_init_time(void)
{
#ifdef CONFIG_CACHE_TAUROS2
tauros2_init(0);
#endif
mmp_dt_init_timer();
of_clk_init(NULL);
}
