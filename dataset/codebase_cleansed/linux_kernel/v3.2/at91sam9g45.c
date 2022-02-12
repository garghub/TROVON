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
void __init at91sam9g45_set_console_clock(int id)
{
if (id >= ARRAY_SIZE(usart_clocks_lookups))
return;
console_clock_lookup.con_id = "usart";
console_clock_lookup.clk = usart_clocks_lookups[id].clk;
clkdev_add(&console_clock_lookup);
}
static void at91sam9g45_reset(void)
{
at91_sys_write(AT91_RSTC_CR, AT91_RSTC_KEY | AT91_RSTC_PROCRST | AT91_RSTC_PERRST);
}
static void at91sam9g45_poweroff(void)
{
at91_sys_write(AT91_SHDW_CR, AT91_SHDW_KEY | AT91_SHDW_SHDW);
}
static void __init at91sam9g45_map_io(void)
{
at91_init_sram(0, AT91SAM9G45_SRAM_BASE, AT91SAM9G45_SRAM_SIZE);
init_consistent_dma_size(SZ_4M);
}
static void __init at91sam9g45_initialize(void)
{
at91_arch_reset = at91sam9g45_reset;
pm_power_off = at91sam9g45_poweroff;
at91_extern_irq = (1 << AT91SAM9G45_ID_IRQ0);
at91_gpio_init(at91sam9g45_gpio, 5);
}
