static void __init sama5d3_register_clocks(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(periph_clocks); i++)
clk_register(periph_clocks[i]);
clkdev_add_table(periph_clocks_lookups,
ARRAY_SIZE(periph_clocks_lookups));
clk_register(&pck0);
clk_register(&pck1);
clk_register(&pck2);
}
static void __init sama5d3_map_io(void)
{
at91_init_sram(0, SAMA5D3_SRAM_BASE, SAMA5D3_SRAM_SIZE);
}
