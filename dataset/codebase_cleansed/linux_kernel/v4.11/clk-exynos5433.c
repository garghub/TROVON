static void __init exynos5433_cmu_top_init(struct device_node *np)
{
samsung_cmu_register_one(np, &top_cmu_info);
}
static void __init exynos5433_cmu_cpif_init(struct device_node *np)
{
samsung_cmu_register_one(np, &cpif_cmu_info);
}
static void __init exynos5433_cmu_mif_init(struct device_node *np)
{
samsung_cmu_register_one(np, &mif_cmu_info);
}
static void __init exynos5433_cmu_peric_init(struct device_node *np)
{
samsung_cmu_register_one(np, &peric_cmu_info);
}
static void __init exynos5433_cmu_peris_init(struct device_node *np)
{
samsung_cmu_register_one(np, &peris_cmu_info);
}
static void __init exynos5433_cmu_fsys_init(struct device_node *np)
{
samsung_cmu_register_one(np, &fsys_cmu_info);
}
static void __init exynos5433_cmu_g2d_init(struct device_node *np)
{
samsung_cmu_register_one(np, &g2d_cmu_info);
}
static void __init exynos5433_cmu_disp_init(struct device_node *np)
{
samsung_cmu_register_one(np, &disp_cmu_info);
}
static void __init exynos5433_cmu_aud_init(struct device_node *np)
{
samsung_cmu_register_one(np, &aud_cmu_info);
}
static void __init exynos5433_cmu_g3d_init(struct device_node *np)
{
samsung_cmu_register_one(np, &g3d_cmu_info);
}
static void __init exynos5433_cmu_gscl_init(struct device_node *np)
{
samsung_cmu_register_one(np, &gscl_cmu_info);
}
static void __init exynos5433_cmu_apollo_init(struct device_node *np)
{
void __iomem *reg_base;
struct samsung_clk_provider *ctx;
reg_base = of_iomap(np, 0);
if (!reg_base) {
panic("%s: failed to map registers\n", __func__);
return;
}
ctx = samsung_clk_init(np, reg_base, APOLLO_NR_CLK);
if (!ctx) {
panic("%s: unable to allocate ctx\n", __func__);
return;
}
samsung_clk_register_pll(ctx, apollo_pll_clks,
ARRAY_SIZE(apollo_pll_clks), reg_base);
samsung_clk_register_mux(ctx, apollo_mux_clks,
ARRAY_SIZE(apollo_mux_clks));
samsung_clk_register_div(ctx, apollo_div_clks,
ARRAY_SIZE(apollo_div_clks));
samsung_clk_register_gate(ctx, apollo_gate_clks,
ARRAY_SIZE(apollo_gate_clks));
exynos_register_cpu_clock(ctx, CLK_SCLK_APOLLO, "apolloclk",
mout_apollo_p[0], mout_apollo_p[1], 0x200,
exynos5433_apolloclk_d, ARRAY_SIZE(exynos5433_apolloclk_d),
CLK_CPU_HAS_E5433_REGS_LAYOUT);
samsung_clk_sleep_init(reg_base, apollo_clk_regs,
ARRAY_SIZE(apollo_clk_regs));
samsung_clk_of_add_provider(np, ctx);
}
static void __init exynos5433_cmu_atlas_init(struct device_node *np)
{
void __iomem *reg_base;
struct samsung_clk_provider *ctx;
reg_base = of_iomap(np, 0);
if (!reg_base) {
panic("%s: failed to map registers\n", __func__);
return;
}
ctx = samsung_clk_init(np, reg_base, ATLAS_NR_CLK);
if (!ctx) {
panic("%s: unable to allocate ctx\n", __func__);
return;
}
samsung_clk_register_pll(ctx, atlas_pll_clks,
ARRAY_SIZE(atlas_pll_clks), reg_base);
samsung_clk_register_mux(ctx, atlas_mux_clks,
ARRAY_SIZE(atlas_mux_clks));
samsung_clk_register_div(ctx, atlas_div_clks,
ARRAY_SIZE(atlas_div_clks));
samsung_clk_register_gate(ctx, atlas_gate_clks,
ARRAY_SIZE(atlas_gate_clks));
exynos_register_cpu_clock(ctx, CLK_SCLK_ATLAS, "atlasclk",
mout_atlas_p[0], mout_atlas_p[1], 0x200,
exynos5433_atlasclk_d, ARRAY_SIZE(exynos5433_atlasclk_d),
CLK_CPU_HAS_E5433_REGS_LAYOUT);
samsung_clk_sleep_init(reg_base, atlas_clk_regs,
ARRAY_SIZE(atlas_clk_regs));
samsung_clk_of_add_provider(np, ctx);
}
static void __init exynos5433_cmu_mscl_init(struct device_node *np)
{
samsung_cmu_register_one(np, &mscl_cmu_info);
}
static void __init exynos5433_cmu_mfc_init(struct device_node *np)
{
samsung_cmu_register_one(np, &mfc_cmu_info);
}
static void __init exynos5433_cmu_hevc_init(struct device_node *np)
{
samsung_cmu_register_one(np, &hevc_cmu_info);
}
static void __init exynos5433_cmu_isp_init(struct device_node *np)
{
samsung_cmu_register_one(np, &isp_cmu_info);
}
static void __init exynos5433_cmu_cam0_init(struct device_node *np)
{
samsung_cmu_register_one(np, &cam0_cmu_info);
}
static void __init exynos5433_cmu_cam1_init(struct device_node *np)
{
samsung_cmu_register_one(np, &cam1_cmu_info);
}
