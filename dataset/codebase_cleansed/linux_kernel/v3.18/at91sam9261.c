static void __init at91sam9261_register_clocks(void)
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
clk_register(&hck0);
clk_register(&hck1);
}
static void __init at91sam9261_map_io(void)
{
if (cpu_is_at91sam9g10())
at91_init_sram(0, AT91SAM9G10_SRAM_BASE, AT91SAM9G10_SRAM_SIZE);
else
at91_init_sram(0, AT91SAM9261_SRAM_BASE, AT91SAM9261_SRAM_SIZE);
}
static void __init at91sam9261_ioremap_registers(void)
{
at91_ioremap_ramc(0, AT91SAM9261_BASE_SDRAMC, 512);
at91sam926x_ioremap_pit(AT91SAM9261_BASE_PIT);
at91sam9_ioremap_smc(0, AT91SAM9261_BASE_SMC);
at91_ioremap_matrix(AT91SAM9261_BASE_MATRIX);
at91_pm_set_standby(at91sam9_sdram_standby);
}
static void __init at91sam9261_initialize(void)
{
arm_pm_idle = at91sam9_idle;
at91_sysirq_mask_rtt(AT91SAM9261_BASE_RTT);
at91_gpio_init(at91sam9261_gpio, 3);
}
static void __init at91sam9261_register_devices(void)
{
platform_device_register(&rstc_device);
platform_device_register(&shdwc_device);
}
static void __init at91sam9261_init_time(void)
{
at91sam926x_pit_init(NR_IRQS_LEGACY + AT91_ID_SYS);
}
