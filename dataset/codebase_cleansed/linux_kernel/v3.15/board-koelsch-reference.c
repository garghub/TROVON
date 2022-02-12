static void __init koelsch_add_du_device(void)
{
struct platform_device_info info = {
.name = "rcar-du-r8a7791",
.id = -1,
.res = du_resources,
.num_res = ARRAY_SIZE(du_resources),
.data = &koelsch_du_pdata,
.size_data = sizeof(koelsch_du_pdata),
.dma_mask = DMA_BIT_MASK(32),
};
platform_device_register_full(&info);
}
static void __init koelsch_add_standard_devices(void)
{
static const struct clk_name {
const char *clk;
const char *con_id;
const char *dev_id;
} clk_names[] = {
{ "cmt0", NULL, "sh_cmt.0" },
{ "scifa0", NULL, "sh-sci.0" },
{ "scifa1", NULL, "sh-sci.1" },
{ "scifb0", NULL, "sh-sci.2" },
{ "scifb1", NULL, "sh-sci.3" },
{ "scifb2", NULL, "sh-sci.4" },
{ "scifa2", NULL, "sh-sci.5" },
{ "scif0", NULL, "sh-sci.6" },
{ "scif1", NULL, "sh-sci.7" },
{ "scif2", NULL, "sh-sci.8" },
{ "scif3", NULL, "sh-sci.9" },
{ "scif4", NULL, "sh-sci.10" },
{ "scif5", NULL, "sh-sci.11" },
{ "scifa3", NULL, "sh-sci.12" },
{ "scifa4", NULL, "sh-sci.13" },
{ "scifa5", NULL, "sh-sci.14" },
{ "du0", "du.0", "rcar-du-r8a7791" },
{ "du1", "du.1", "rcar-du-r8a7791" },
{ "lvds0", "lvds.0", "rcar-du-r8a7791" },
};
struct clk *clk;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(clk_names); ++i) {
clk = clk_get(NULL, clk_names[i].clk);
if (!IS_ERR(clk)) {
clk_register_clkdev(clk, clk_names[i].con_id,
clk_names[i].dev_id);
clk_put(clk);
}
}
r8a7791_add_dt_devices();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
koelsch_add_du_device();
}
