static void __init at91rm9200_dt_timer_init(void)
{
#if defined(CONFIG_COMMON_CLK)
of_clk_init(NULL);
#endif
at91rm9200_timer_init();
}
