static void __init at91rm9200_register_clocks(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(periph_clocks); i++)
clk_register(periph_clocks[i]);
clkdev_add_table(periph_clocks_lookups,
ARRAY_SIZE(periph_clocks_lookups));
clkdev_add_table(usart_clocks_lookups,
ARRAY_SIZE(usart_clocks_lookups));
clk_register(&pck0);
clk_register(&pck1);
clk_register(&pck2);
clk_register(&pck3);
}
static void at91rm9200_idle(void)
{
at91_pmc_write(AT91_PMC_SCDR, AT91_PMC_PCK);
}
static void at91rm9200_restart(char mode, const char *cmd)
{
at91_st_write(AT91_ST_WDMR, AT91_ST_RSTEN | AT91_ST_EXTEN | 1);
at91_st_write(AT91_ST_CR, AT91_ST_WDRST);
}
static void __init at91rm9200_map_io(void)
{
at91_init_sram(0, AT91RM9200_SRAM_BASE, AT91RM9200_SRAM_SIZE);
}
static void __init at91rm9200_ioremap_registers(void)
{
at91rm9200_ioremap_st(AT91RM9200_BASE_ST);
at91_ioremap_ramc(0, AT91RM9200_BASE_MC, 256);
}
static void __init at91rm9200_initialize(void)
{
arm_pm_idle = at91rm9200_idle;
arm_pm_restart = at91rm9200_restart;
at91_extern_irq = (1 << AT91RM9200_ID_IRQ0) | (1 << AT91RM9200_ID_IRQ1)
| (1 << AT91RM9200_ID_IRQ2) | (1 << AT91RM9200_ID_IRQ3)
| (1 << AT91RM9200_ID_IRQ4) | (1 << AT91RM9200_ID_IRQ5)
| (1 << AT91RM9200_ID_IRQ6);
at91_gpio_init(at91rm9200_gpio,
cpu_is_at91rm9200_bga() ? AT91RM9200_BGA : AT91RM9200_PQFP);
}
