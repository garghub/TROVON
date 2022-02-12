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
at91_ioremap_shdwc(AT91SAM9G45_BASE_SHDWC);
at91_ioremap_rstc(AT91SAM9G45_BASE_RSTC);
at91_ioremap_ramc(0, AT91SAM9G45_BASE_DDRSDRC1, 512);
at91_ioremap_ramc(1, AT91SAM9G45_BASE_DDRSDRC0, 512);
at91sam926x_ioremap_pit(AT91SAM9G45_BASE_PIT);
at91sam9_ioremap_smc(0, AT91SAM9G45_BASE_SMC);
at91_ioremap_matrix(AT91SAM9G45_BASE_MATRIX);
}
static void __init at91sam9g45_initialize(void)
{
arm_pm_idle = at91sam9_idle;
arm_pm_restart = at91sam9g45_restart;
at91_extern_irq = (1 << AT91SAM9G45_ID_IRQ0);
at91_gpio_init(at91sam9g45_gpio, 5);
}
