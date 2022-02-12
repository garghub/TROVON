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
mtk_clk_register_fixed_clks(fixed_clks, ARRAY_SIZE(fixed_clks), clk_data);
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
mtk_clk_register_factors(infra_divs, ARRAY_SIZE(infra_divs), clk_data);
mtk_clk_register_cpumuxes(node, cpu_muxes, ARRAY_SIZE(cpu_muxes),
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
void __iomem *base;
struct clk *clk;
int r, i;
base = of_iomap(node, 0);
if (!base) {
pr_err("%s(): ioremap failed\n", __func__);
return;
}
mt8173_pll_clk_data = clk_data = mtk_alloc_clk_data(CLK_APMIXED_NR_CLK);
if (!clk_data) {
iounmap(base);
return;
}
mtk_clk_register_plls(node, plls, ARRAY_SIZE(plls), clk_data);
for (i = 0; i < ARRAY_SIZE(apmixed_usb); i++) {
const struct mtk_clk_usb *cku = &apmixed_usb[i];
clk = mtk_clk_register_ref2usb_tx(cku->name, cku->parent,
base + cku->reg_ofs);
if (IS_ERR(clk)) {
pr_err("Failed to register clk %s: %ld\n", cku->name,
PTR_ERR(clk));
continue;
}
clk_data->clks[cku->id] = clk;
}
clk = clk_register_divider(NULL, "hdmi_ref", "tvdpll_594m", 0,
base + 0x40, 16, 3, CLK_DIVIDER_POWER_OF_TWO,
NULL);
clk_data->clks[CLK_APMIXED_HDMI_REF] = clk;
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
mtk_clk_enable_critical();
}
static void __init mtk_imgsys_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
int r;
clk_data = mtk_alloc_clk_data(CLK_IMG_NR_CLK);
mtk_clk_register_gates(node, img_clks, ARRAY_SIZE(img_clks),
clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
}
static void __init mtk_mmsys_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
int r;
clk_data = mtk_alloc_clk_data(CLK_MM_NR_CLK);
mtk_clk_register_gates(node, mm_clks, ARRAY_SIZE(mm_clks),
clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
}
static void __init mtk_vdecsys_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
int r;
clk_data = mtk_alloc_clk_data(CLK_VDEC_NR_CLK);
mtk_clk_register_gates(node, vdec_clks, ARRAY_SIZE(vdec_clks),
clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
}
static void __init mtk_vencsys_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
int r;
clk_data = mtk_alloc_clk_data(CLK_VENC_NR_CLK);
mtk_clk_register_gates(node, venc_clks, ARRAY_SIZE(venc_clks),
clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
}
static void __init mtk_vencltsys_init(struct device_node *node)
{
struct clk_onecell_data *clk_data;
int r;
clk_data = mtk_alloc_clk_data(CLK_VENCLT_NR_CLK);
mtk_clk_register_gates(node, venclt_clks, ARRAY_SIZE(venclt_clks),
clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
}
