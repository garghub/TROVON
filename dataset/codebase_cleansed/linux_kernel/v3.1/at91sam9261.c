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
void __init at91sam9261_set_console_clock(int id)
{
if (id >= ARRAY_SIZE(usart_clocks_lookups))
return;
console_clock_lookup.con_id = "usart";
console_clock_lookup.clk = usart_clocks_lookups[id].clk;
clkdev_add(&console_clock_lookup);
}
static void at91sam9261_poweroff(void)
{
at91_sys_write(AT91_SHDW_CR, AT91_SHDW_KEY | AT91_SHDW_SHDW);
}
static void __init at91sam9261_map_io(void)
{
if (cpu_is_at91sam9g10())
at91_init_sram(0, AT91SAM9G10_SRAM_BASE, AT91SAM9G10_SRAM_SIZE);
else
at91_init_sram(0, AT91SAM9261_SRAM_BASE, AT91SAM9261_SRAM_SIZE);
}
static void __init at91sam9261_initialize(void)
{
at91_arch_reset = at91sam9_alt_reset;
pm_power_off = at91sam9261_poweroff;
at91_extern_irq = (1 << AT91SAM9261_ID_IRQ0) | (1 << AT91SAM9261_ID_IRQ1)
| (1 << AT91SAM9261_ID_IRQ2);
at91_gpio_init(at91sam9261_gpio, 3);
}
