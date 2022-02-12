static void __init at91sam9x5_register_clocks(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(periph_clocks); i++)
clk_register(periph_clocks[i]);
clkdev_add_table(periph_clocks_lookups,
ARRAY_SIZE(periph_clocks_lookups));
if (cpu_is_at91sam9g25()
|| cpu_is_at91sam9x25())
clk_register(&usart3_clk);
if (cpu_is_at91sam9g25()
|| cpu_is_at91sam9x25()
|| cpu_is_at91sam9g35()
|| cpu_is_at91sam9x35())
clk_register(&macb0_clk);
if (cpu_is_at91sam9g15()
|| cpu_is_at91sam9g35()
|| cpu_is_at91sam9x35())
clk_register(&lcdc_clk);
if (cpu_is_at91sam9g25())
clk_register(&isi_clk);
if (cpu_is_at91sam9x25())
clk_register(&macb1_clk);
if (cpu_is_at91sam9x25()
|| cpu_is_at91sam9x35()) {
clk_register(&can0_clk);
clk_register(&can1_clk);
}
clk_register(&pck0);
clk_register(&pck1);
}
static void __init at91sam9x5_map_io(void)
{
at91_init_sram(0, AT91SAM9X5_SRAM_BASE, AT91SAM9X5_SRAM_SIZE);
}
