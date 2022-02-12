static void __init at91rm9200_dt_init_irq(void)
{
of_irq_init(irq_of_match);
}
static void __init at91rm9200_dt_timer_init(void)
{
#if defined(CONFIG_COMMON_CLK)
of_clk_init(NULL);
#endif
at91rm9200_timer_init();
}
