void __init spear3xx_init(void)
{
}
void __init spear3xx_init_irq(void)
{
vic_init((void __iomem *)VA_SPEAR3XX_ML1_VIC_BASE, 0, ~0, 0);
}
void __init spear3xx_map_io(void)
{
iotable_init(spear3xx_io_desc, ARRAY_SIZE(spear3xx_io_desc));
spear3xx_clk_init();
}
static void __init spear3xx_timer_init(void)
{
char pclk_name[] = "pll3_48m_clk";
struct clk *gpt_clk, *pclk;
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
spear_setup_timer();
}
