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
static void __init at91sam9xe_map_io(void)
{
unsigned long sram_size;
switch (at91_soc_initdata.cidr & AT91_CIDR_SRAMSIZ) {
case AT91_CIDR_SRAMSIZ_32K:
sram_size = 2 * SZ_16K;
break;
case AT91_CIDR_SRAMSIZ_16K:
default:
sram_size = SZ_16K;
}
at91_init_sram(0, AT91SAM9XE_SRAM_BASE, sram_size);
}
static void __init at91sam9260_map_io(void)
{
if (cpu_is_at91sam9xe())
at91sam9xe_map_io();
else if (cpu_is_at91sam9g20())
at91_init_sram(0, AT91SAM9G20_SRAM_BASE, AT91SAM9G20_SRAM_SIZE);
else
at91_init_sram(0, AT91SAM9260_SRAM_BASE, AT91SAM9260_SRAM_SIZE);
}
static void __init at91sam9260_ioremap_registers(void)
{
at91_ioremap_shdwc(AT91SAM9260_BASE_SHDWC);
at91_ioremap_rstc(AT91SAM9260_BASE_RSTC);
at91_ioremap_ramc(0, AT91SAM9260_BASE_SDRAMC, 512);
at91sam926x_ioremap_pit(AT91SAM9260_BASE_PIT);
at91sam9_ioremap_smc(0, AT91SAM9260_BASE_SMC);
at91_ioremap_matrix(AT91SAM9260_BASE_MATRIX);
}
static void __init at91sam9260_initialize(void)
{
arm_pm_idle = at91sam9_idle;
arm_pm_restart = at91sam9_alt_restart;
at91_extern_irq = (1 << AT91SAM9260_ID_IRQ0) | (1 << AT91SAM9260_ID_IRQ1)
| (1 << AT91SAM9260_ID_IRQ2);
at91_gpio_init(at91sam9260_gpio, 3);
}
