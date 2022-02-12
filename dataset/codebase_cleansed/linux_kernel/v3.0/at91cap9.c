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
static void at91cap9_reset(void)
{
at91_sys_write(AT91_RSTC_CR, AT91_RSTC_KEY | AT91_RSTC_PROCRST | AT91_RSTC_PERRST);
}
static void at91cap9_poweroff(void)
{
at91_sys_write(AT91_SHDW_CR, AT91_SHDW_KEY | AT91_SHDW_SHDW);
}
void __init at91cap9_map_io(void)
{
iotable_init(at91cap9_io_desc, ARRAY_SIZE(at91cap9_io_desc));
}
void __init at91cap9_initialize(unsigned long main_clock)
{
at91_arch_reset = at91cap9_reset;
pm_power_off = at91cap9_poweroff;
at91_extern_irq = (1 << AT91CAP9_ID_IRQ0) | (1 << AT91CAP9_ID_IRQ1);
at91_clock_init(main_clock);
at91cap9_register_clocks();
at91_gpio_init(at91cap9_gpio, 4);
if (cpu_is_at91cap9_revB())
system_rev = 0xB;
else if (cpu_is_at91cap9_revC())
system_rev = 0xC;
}
void __init at91cap9_init_interrupts(unsigned int priority[NR_AIC_IRQS])
{
if (!priority)
priority = at91cap9_default_irq_priority;
at91_aic_init(priority);
at91_gpio_irq_setup();
}
