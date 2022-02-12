static void __init lager_add_standard_devices(void)
{
#ifdef CONFIG_COMMON_CLK
static const char * const scif_names[] = {
"scifa0", "scifa1", "scifb0", "scifb1",
"scifb2", "scifa2", "scif0", "scif1",
"hscif0", "hscif1",
};
struct clk *clk;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(scif_names); ++i) {
clk = clk_get(NULL, scif_names[i]);
if (clk) {
clk_register_clkdev(clk, NULL, "sh-sci.%u", i);
clk_put(clk);
}
}
clk = clk_get(NULL, "cmt0");
if (clk) {
clk_register_clkdev(clk, NULL, "sh_cmt.0");
clk_put(clk);
}
#else
r8a7790_clock_init();
#endif
r8a7790_add_dt_devices();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
