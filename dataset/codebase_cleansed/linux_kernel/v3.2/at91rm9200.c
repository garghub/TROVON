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
void __init at91rm9200_set_console_clock(int id)
{
if (id >= ARRAY_SIZE(usart_clocks_lookups))
return;
console_clock_lookup.con_id = "usart";
console_clock_lookup.clk = usart_clocks_lookups[id].clk;
clkdev_add(&console_clock_lookup);
}
static void at91rm9200_reset(void)
{
at91_sys_write(AT91_ST_WDMR, AT91_ST_RSTEN | AT91_ST_EXTEN | 1);
at91_sys_write(AT91_ST_CR, AT91_ST_WDRST);
}
static void __init at91rm9200_map_io(void)
{
at91_init_sram(0, AT91RM9200_SRAM_BASE, AT91RM9200_SRAM_SIZE);
iotable_init(at91rm9200_io_desc, ARRAY_SIZE(at91rm9200_io_desc));
}
static void __init at91rm9200_initialize(void)
{
at91_arch_reset = at91rm9200_reset;
at91_extern_irq = (1 << AT91RM9200_ID_IRQ0) | (1 << AT91RM9200_ID_IRQ1)
| (1 << AT91RM9200_ID_IRQ2) | (1 << AT91RM9200_ID_IRQ3)
| (1 << AT91RM9200_ID_IRQ4) | (1 << AT91RM9200_ID_IRQ5)
| (1 << AT91RM9200_ID_IRQ6);
at91_gpio_init(at91rm9200_gpio,
cpu_is_at91rm9200_bga() ? AT91RM9200_BGA : AT91RM9200_PQFP);
}
