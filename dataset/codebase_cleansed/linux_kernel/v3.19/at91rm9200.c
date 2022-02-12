static void at91rm9200_idle(void)
{
at91_pmc_write(AT91_PMC_SCDR, AT91_PMC_PCK);
}
static void at91rm9200_restart(enum reboot_mode reboot_mode, const char *cmd)
{
at91_st_write(AT91_ST_WDMR, AT91_ST_RSTEN | AT91_ST_EXTEN | 1);
at91_st_write(AT91_ST_CR, AT91_ST_WDRST);
}
static void __init at91rm9200_map_io(void)
{
at91_init_sram(0, AT91RM9200_SRAM_BASE, AT91RM9200_SRAM_SIZE);
}
static void __init at91rm9200_initialize(void)
{
arm_pm_idle = at91rm9200_idle;
arm_pm_restart = at91rm9200_restart;
}
