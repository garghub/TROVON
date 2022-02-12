void __init spear13xx_l2x0_init(void)
{
if (!IS_ENABLED(CONFIG_CACHE_L2X0))
return;
writel_relaxed(0x06, VA_L2CC_BASE + L310_PREFETCH_CTRL);
writel_relaxed(0x221, VA_L2CC_BASE + L310_TAG_LATENCY_CTRL);
writel_relaxed(0x441, VA_L2CC_BASE + L310_DATA_LATENCY_CTRL);
l2x0_init(VA_L2CC_BASE, 0x30a00001, 0xfe0fffff);
}
void __init spear13xx_map_io(void)
{
iotable_init(spear13xx_io_desc, ARRAY_SIZE(spear13xx_io_desc));
}
static void __init spear13xx_clk_init(void)
{
if (of_machine_is_compatible("st,spear1310"))
spear1310_clk_init(VA_MISC_BASE, VA_SPEAR1310_RAS_BASE);
else if (of_machine_is_compatible("st,spear1340"))
spear1340_clk_init(VA_MISC_BASE);
else
pr_err("%s: Unknown machine\n", __func__);
}
void __init spear13xx_timer_init(void)
{
char pclk_name[] = "osc_24m_clk";
struct clk *gpt_clk, *pclk;
spear13xx_clk_init();
gpt_clk = clk_get_sys("gpt0", NULL);
if (IS_ERR(gpt_clk)) {
pr_err("%s:couldn't get clk for gpt\n", __func__);
BUG();
}
pclk = clk_get(NULL, pclk_name);
if (IS_ERR(pclk)) {
pr_err("%s:couldn't get %s as parent for gpt\n", __func__,
pclk_name);
BUG();
}
clk_set_parent(gpt_clk, pclk);
clk_put(gpt_clk);
clk_put(pclk);
spear_setup_of_timer();
timer_probe();
}
