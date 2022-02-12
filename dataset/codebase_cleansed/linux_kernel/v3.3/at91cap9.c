static void __init at91cap9_register_clocks(void)
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
void __init at91cap9_set_console_clock(int id)
{
if (id >= ARRAY_SIZE(usart_clocks_lookups))
return;
console_clock_lookup.con_id = "usart";
console_clock_lookup.clk = usart_clocks_lookups[id].clk;
clkdev_add(&console_clock_lookup);
}
static void __init at91cap9_map_io(void)
{
at91_init_sram(0, AT91CAP9_SRAM_BASE, AT91CAP9_SRAM_SIZE);
}
static void __init at91cap9_ioremap_registers(void)
{
at91_ioremap_shdwc(AT91CAP9_BASE_SHDWC);
at91_ioremap_rstc(AT91CAP9_BASE_RSTC);
at91sam926x_ioremap_pit(AT91CAP9_BASE_PIT);
at91sam9_ioremap_smc(0, AT91CAP9_BASE_SMC);
}
static void __init at91cap9_initialize(void)
{
arm_pm_restart = at91sam9g45_restart;
at91_extern_irq = (1 << AT91CAP9_ID_IRQ0) | (1 << AT91CAP9_ID_IRQ1);
at91_gpio_init(at91cap9_gpio, 4);
if (cpu_is_at91cap9_revB())
system_rev = 0xB;
else if (cpu_is_at91cap9_revC())
system_rev = 0xC;
}
