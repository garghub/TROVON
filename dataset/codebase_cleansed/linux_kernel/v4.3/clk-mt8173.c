static void __init mtk_clk_enable_critical(void)
{
if (!mt8173_top_clk_data || !mt8173_pll_clk_data)
return;
clk_prepare_enable(mt8173_pll_clk_data->clks[CLK_APMIXED_ARMCA15PLL]);
clk_prepare_enable(mt8173_pll_clk_data->clks[CLK_APMIXED_ARMCA7PLL]);
clk_prepare_enable(mt8173_top_clk_data->clks[CLK_TOP_MEM_SEL]);
clk_prepare_enable(mt8173_top_clk_data->clks[CLK_TOP_DDRPHYCFG_SEL]);
clk_prepare_enable(mt8173_top_clk_data->clks[CLK_TOP_CCI400_SEL]);
clk_prepare_enable(mt8173_top_clk_data->clks[CLK_TOP_RTC_SEL]);
}
static void __init mtk_topckgen_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
void __iomem *base;
int r;
base = of_iomap(node, 0);
if (!base) {
pr_err("%s(): ioremap failed\n", __func__);
return;
}
mt8173_top_clk_data = clk_data = mtk_alloc_clk_data(CLK_TOP_NR_CLK);
mtk_clk_register_factors(root_clk_alias, ARRAY_SIZE(root_clk_alias), clk_data);
mtk_clk_register_factors(top_divs, ARRAY_SIZE(top_divs), clk_data);
mtk_clk_register_composites(top_muxes, ARRAY_SIZE(top_muxes), base,
&mt8173_clk_lock, clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
mtk_clk_enable_critical();
}
static void __init mtk_infrasys_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
int r;
clk_data = mtk_alloc_clk_data(CLK_INFRA_NR_CLK);
mtk_clk_register_gates(node, infra_clks, ARRAY_SIZE(infra_clks),
clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
mtk_register_reset_controller(node, 2, 0x30);
}
static void __init mtk_pericfg_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
int r;
void __iomem *base;
base = of_iomap(node, 0);
if (!base) {
pr_err("%s(): ioremap failed\n", __func__);
return;
}
clk_data = mtk_alloc_clk_data(CLK_PERI_NR_CLK);
mtk_clk_register_gates(node, peri_gates, ARRAY_SIZE(peri_gates),
clk_data);
mtk_clk_register_composites(peri_clks, ARRAY_SIZE(peri_clks), base,
&mt8173_clk_lock, clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
mtk_register_reset_controller(node, 2, 0);
}
static void __init mtk_apmixedsys_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
mt8173_pll_clk_data = clk_data = mtk_alloc_clk_data(CLK_APMIXED_NR_CLK);
if (!clk_data)
return;
mtk_clk_register_plls(node, plls, ARRAY_SIZE(plls), clk_data);
mtk_clk_enable_critical();
}
