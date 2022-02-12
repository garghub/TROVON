static void __init at91sam9260_register_clocks(void)
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
}
void __init at91sam9260_set_console_clock(int id)
{
if (id >= ARRAY_SIZE(usart_clocks_lookups))
return;
console_clock_lookup.con_id = "usart";
console_clock_lookup.clk = usart_clocks_lookups[id].clk;
clkdev_add(&console_clock_lookup);
}
static void at91sam9260_poweroff(void)
{
at91_sys_write(AT91_SHDW_CR, AT91_SHDW_KEY | AT91_SHDW_SHDW);
}
static void __init at91sam9xe_map_io(void)
{
unsigned long cidr, sram_size;
cidr = at91_sys_read(AT91_DBGU_CIDR);
switch (cidr & AT91_CIDR_SRAMSIZ) {
case AT91_CIDR_SRAMSIZ_32K:
sram_size = 2 * SZ_16K;
break;
case AT91_CIDR_SRAMSIZ_16K:
default:
sram_size = SZ_16K;
}
at91sam9xe_sram_desc->virtual = AT91_IO_VIRT_BASE - sram_size;
at91sam9xe_sram_desc->length = sram_size;
iotable_init(at91sam9xe_sram_desc, ARRAY_SIZE(at91sam9xe_sram_desc));
}
void __init at91sam9260_map_io(void)
{
iotable_init(at91sam9260_io_desc, ARRAY_SIZE(at91sam9260_io_desc));
if (cpu_is_at91sam9xe())
at91sam9xe_map_io();
else if (cpu_is_at91sam9g20())
iotable_init(at91sam9g20_sram_desc, ARRAY_SIZE(at91sam9g20_sram_desc));
else
iotable_init(at91sam9260_sram_desc, ARRAY_SIZE(at91sam9260_sram_desc));
}
void __init at91sam9260_initialize(unsigned long main_clock)
{
at91_arch_reset = at91sam9_alt_reset;
pm_power_off = at91sam9260_poweroff;
at91_extern_irq = (1 << AT91SAM9260_ID_IRQ0) | (1 << AT91SAM9260_ID_IRQ1)
| (1 << AT91SAM9260_ID_IRQ2);
at91_clock_init(main_clock);
at91sam9260_register_clocks();
at91_gpio_init(at91sam9260_gpio, 3);
}
void __init at91sam9260_init_interrupts(unsigned int priority[NR_AIC_IRQS])
{
if (!priority)
priority = at91sam9260_default_irq_priority;
at91_aic_init(priority);
at91_gpio_irq_setup();
}
