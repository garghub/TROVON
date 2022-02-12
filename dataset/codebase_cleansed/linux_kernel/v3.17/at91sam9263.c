static void __init at91sam9263_register_clocks(void)
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
static void __init at91sam9263_map_io(void)
{
at91_init_sram(0, AT91SAM9263_SRAM0_BASE, AT91SAM9263_SRAM0_SIZE);
at91_init_sram(1, AT91SAM9263_SRAM1_BASE, AT91SAM9263_SRAM1_SIZE);
}
static void __init at91sam9263_ioremap_registers(void)
{
at91_ioremap_shdwc(AT91SAM9263_BASE_SHDWC);
at91_ioremap_rstc(AT91SAM9263_BASE_RSTC);
at91_ioremap_ramc(0, AT91SAM9263_BASE_SDRAMC0, 512);
at91_ioremap_ramc(1, AT91SAM9263_BASE_SDRAMC1, 512);
at91sam926x_ioremap_pit(AT91SAM9263_BASE_PIT);
at91sam9_ioremap_smc(0, AT91SAM9263_BASE_SMC0);
at91sam9_ioremap_smc(1, AT91SAM9263_BASE_SMC1);
at91_ioremap_matrix(AT91SAM9263_BASE_MATRIX);
at91_pm_set_standby(at91sam9_sdram_standby);
}
static void __init at91sam9263_initialize(void)
{
arm_pm_idle = at91sam9_idle;
arm_pm_restart = at91sam9_alt_restart;
at91_sysirq_mask_rtt(AT91SAM9263_BASE_RTT0);
at91_sysirq_mask_rtt(AT91SAM9263_BASE_RTT1);
at91_gpio_init(at91sam9263_gpio, 5);
}
