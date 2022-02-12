static void at91rm9200_restart(enum reboot_mode reboot_mode, const char *cmd)
{
at91_st_write(AT91_ST_WDMR, AT91_ST_RSTEN | AT91_ST_EXTEN | 1);
at91_st_write(AT91_ST_CR, AT91_ST_WDRST);
}
static void __init at91rm9200_dt_timer_init(void)
{
of_clk_init(NULL);
at91rm9200_timer_init();
}
static void __init at91rm9200_dt_device_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
arm_pm_idle = at91rm9200_idle;
arm_pm_restart = at91rm9200_restart;
at91rm9200_pm_init();
}
