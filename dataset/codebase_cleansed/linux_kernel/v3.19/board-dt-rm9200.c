static void __init at91rm9200_dt_timer_init(void)
{
of_clk_init(NULL);
at91rm9200_timer_init();
}
