void __init spear6xx_map_io(void)
{
iotable_init(spear6xx_io_desc, ARRAY_SIZE(spear6xx_io_desc));
}
static void __init spear6xx_timer_init(void)
{
char pclk_name[] = "pll3_clk";
struct clk *gpt_clk, *pclk;
spear6xx_clk_init();
gpt_clk = clk_get_sys("gpt0", NULL);
if (IS_ERR(gpt_clk)) {
pr_err("%s:couldn't get clk for gpt\n", __func__);
BUG();
}
pclk = clk_get(NULL, pclk_name);
if (IS_ERR(pclk)) {
pr_err("%s:couldn't get %s as parent for gpt\n",
__func__, pclk_name);
BUG();
}
clk_set_parent(gpt_clk, pclk);
clk_put(gpt_clk);
clk_put(pclk);
spear_setup_of_timer();
}
static void __init spear600_dt_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table,
spear6xx_auxdata_lookup, NULL);
}
static void __init spear6xx_dt_init_irq(void)
{
of_irq_init(vic_of_match);
}
