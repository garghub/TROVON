static void __init at91sam9g45_register_clocks(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(periph_clocks); i++)
clk_register(periph_clocks[i]);
clkdev_add_table(periph_clocks_lookups,
ARRAY_SIZE(periph_clocks_lookups));
clkdev_add_table(usart_clocks_lookups,
ARRAY_SIZE(usart_clocks_lookups));
if (cpu_is_at91sam9m10() || cpu_is_at91sam9m11())
clk_register(&vdec_clk);
clk_register(&pck0);
clk_register(&pck1);
}
static void __init at91sam9g45_map_io(void)
{
at91_init_sram(0, AT91SAM9G45_SRAM_BASE, AT91SAM9G45_SRAM_SIZE);
}
static void __init at91sam9g45_ioremap_registers(void)
{
at91_ioremap_ramc(0, AT91SAM9G45_BASE_DDRSDRC1, 512);
at91_ioremap_ramc(1, AT91SAM9G45_BASE_DDRSDRC0, 512);
at91sam926x_ioremap_pit(AT91SAM9G45_BASE_PIT);
at91sam9_ioremap_smc(0, AT91SAM9G45_BASE_SMC);
at91_ioremap_matrix(AT91SAM9G45_BASE_MATRIX);
at91_pm_set_standby(at91_ddr_standby);
}
static void __init at91sam9g45_initialize(void)
{
arm_pm_idle = at91sam9_idle;
at91_sysirq_mask_rtc(AT91SAM9G45_BASE_RTC);
at91_sysirq_mask_rtt(AT91SAM9G45_BASE_RTT);
at91_gpio_init(at91sam9g45_gpio, 5);
}
static void __init at91sam9g45_register_devices(void)
{
platform_device_register(&rstc_device);
platform_device_register(&shdwc_device);
}
static void __init at91sam9g45_init_time(void)
{
at91sam926x_pit_init(NR_IRQS_LEGACY + AT91_ID_SYS);
}
