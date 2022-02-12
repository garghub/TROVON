static void __init sam9_dt_timer_init(void)
{
#if defined(CONFIG_COMMON_CLK)
of_clk_init(NULL);
#endif
at91sam926x_pit_init();
}
static void __init at91_dt_init_irq(void)
{
of_irq_init(irq_of_match);
}
