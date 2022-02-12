static void __init at91sam9n12_register_clocks(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(periph_clocks); i++)
clk_register(periph_clocks[i]);
clk_register(&pck0);
clk_register(&pck1);
clkdev_add_table(periph_clocks_lookups,
ARRAY_SIZE(periph_clocks_lookups));
}
static void __init at91sam9n12_map_io(void)
{
at91_init_sram(0, AT91SAM9N12_SRAM_BASE, AT91SAM9N12_SRAM_SIZE);
}
void __init at91sam9n12_initialize(void)
{
at91_extern_irq = (1 << AT91SAM9N12_ID_IRQ0);
at91_gpio_init(NULL, 0);
}
