static void __init sun6i_timer_init(void)
{
of_clk_init(NULL);
if (IS_ENABLED(CONFIG_RESET_CONTROLLER))
sun6i_reset_init();
clocksource_of_init();
}
