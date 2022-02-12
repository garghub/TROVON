static int exynos5260_clk_suspend(void)
{
struct exynos5260_clock_reg_cache *cache;
list_for_each_entry(cache, &clock_reg_cache_list, node)
samsung_clk_save(cache->reg_base, cache->rdump,
cache->rd_num);
return 0;
}
static void exynos5260_clk_resume(void)
{
struct exynos5260_clock_reg_cache *cache;
list_for_each_entry(cache, &clock_reg_cache_list, node)
samsung_clk_restore(cache->reg_base, cache->rdump,
cache->rd_num);
}
static void exynos5260_clk_sleep_init(void __iomem *reg_base,
unsigned long *rdump,
unsigned long nr_rdump)
{
struct exynos5260_clock_reg_cache *reg_cache;
reg_cache = kzalloc(sizeof(struct exynos5260_clock_reg_cache),
GFP_KERNEL);
if (!reg_cache)
panic("could not allocate register cache.\n");
reg_cache->rdump = samsung_clk_alloc_reg_dump(rdump, nr_rdump);
if (!reg_cache->rdump)
panic("could not allocate register dump storage.\n");
if (list_empty(&clock_reg_cache_list))
register_syscore_ops(&exynos5260_clk_syscore_ops);
reg_cache->rd_num = nr_rdump;
reg_cache->reg_base = reg_base;
list_add_tail(&reg_cache->node, &clock_reg_cache_list);
}
static void exynos5260_clk_sleep_init(void __iomem *reg_base,
unsigned long *rdump,
unsigned long nr_rdump){}
void __init exynos5260_cmu_register_one(struct device_node *np,
struct exynos5260_cmu_info *cmu)
{
void __iomem *reg_base;
struct samsung_clk_provider *ctx;
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
ctx = samsung_clk_init(np, reg_base, cmu->nr_clk_ids);
if (!ctx)
panic("%s: unable to alllocate ctx\n", __func__);
if (cmu->pll_clks)
samsung_clk_register_pll(ctx, cmu->pll_clks, cmu->nr_pll_clks,
reg_base);
if (cmu->mux_clks)
samsung_clk_register_mux(ctx, cmu->mux_clks,
cmu->nr_mux_clks);
if (cmu->div_clks)
samsung_clk_register_div(ctx, cmu->div_clks, cmu->nr_div_clks);
if (cmu->gate_clks)
samsung_clk_register_gate(ctx, cmu->gate_clks,
cmu->nr_gate_clks);
if (cmu->fixed_clks)
samsung_clk_register_fixed_rate(ctx, cmu->fixed_clks,
cmu->nr_fixed_clks);
if (cmu->clk_regs)
exynos5260_clk_sleep_init(reg_base, cmu->clk_regs,
cmu->nr_clk_regs);
}
static void __init exynos5260_clk_aud_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = aud_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(aud_mux_clks);
cmu.div_clks = aud_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(aud_div_clks);
cmu.gate_clks = aud_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(aud_gate_clks);
cmu.nr_clk_ids = AUD_NR_CLK;
cmu.clk_regs = aud_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(aud_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_disp_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = disp_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(disp_mux_clks);
cmu.div_clks = disp_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(disp_div_clks);
cmu.gate_clks = disp_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(disp_gate_clks);
cmu.nr_clk_ids = DISP_NR_CLK;
cmu.clk_regs = disp_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(disp_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_egl_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.pll_clks = egl_pll_clks;
cmu.nr_pll_clks = ARRAY_SIZE(egl_pll_clks);
cmu.mux_clks = egl_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(egl_mux_clks);
cmu.div_clks = egl_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(egl_div_clks);
cmu.nr_clk_ids = EGL_NR_CLK;
cmu.clk_regs = egl_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(egl_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_fsys_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = fsys_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(fsys_mux_clks);
cmu.gate_clks = fsys_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(fsys_gate_clks);
cmu.nr_clk_ids = FSYS_NR_CLK;
cmu.clk_regs = fsys_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(fsys_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_g2d_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = g2d_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(g2d_mux_clks);
cmu.div_clks = g2d_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(g2d_div_clks);
cmu.gate_clks = g2d_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(g2d_gate_clks);
cmu.nr_clk_ids = G2D_NR_CLK;
cmu.clk_regs = g2d_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(g2d_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_g3d_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.pll_clks = g3d_pll_clks;
cmu.nr_pll_clks = ARRAY_SIZE(g3d_pll_clks);
cmu.mux_clks = g3d_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(g3d_mux_clks);
cmu.div_clks = g3d_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(g3d_div_clks);
cmu.gate_clks = g3d_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(g3d_gate_clks);
cmu.nr_clk_ids = G3D_NR_CLK;
cmu.clk_regs = g3d_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(g3d_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_gscl_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = gscl_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(gscl_mux_clks);
cmu.div_clks = gscl_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(gscl_div_clks);
cmu.gate_clks = gscl_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(gscl_gate_clks);
cmu.nr_clk_ids = GSCL_NR_CLK;
cmu.clk_regs = gscl_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(gscl_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_isp_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = isp_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(isp_mux_clks);
cmu.div_clks = isp_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(isp_div_clks);
cmu.gate_clks = isp_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(isp_gate_clks);
cmu.nr_clk_ids = ISP_NR_CLK;
cmu.clk_regs = isp_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(isp_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_kfc_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.pll_clks = kfc_pll_clks;
cmu.nr_pll_clks = ARRAY_SIZE(kfc_pll_clks);
cmu.mux_clks = kfc_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(kfc_mux_clks);
cmu.div_clks = kfc_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(kfc_div_clks);
cmu.nr_clk_ids = KFC_NR_CLK;
cmu.clk_regs = kfc_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(kfc_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_mfc_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = mfc_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(mfc_mux_clks);
cmu.div_clks = mfc_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(mfc_div_clks);
cmu.gate_clks = mfc_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(mfc_gate_clks);
cmu.nr_clk_ids = MFC_NR_CLK;
cmu.clk_regs = mfc_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(mfc_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_mif_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.pll_clks = mif_pll_clks;
cmu.nr_pll_clks = ARRAY_SIZE(mif_pll_clks);
cmu.mux_clks = mif_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(mif_mux_clks);
cmu.div_clks = mif_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(mif_div_clks);
cmu.gate_clks = mif_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(mif_gate_clks);
cmu.nr_clk_ids = MIF_NR_CLK;
cmu.clk_regs = mif_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(mif_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_peri_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.mux_clks = peri_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(peri_mux_clks);
cmu.div_clks = peri_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(peri_div_clks);
cmu.gate_clks = peri_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(peri_gate_clks);
cmu.nr_clk_ids = PERI_NR_CLK;
cmu.clk_regs = peri_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(peri_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
static void __init exynos5260_clk_top_init(struct device_node *np)
{
struct exynos5260_cmu_info cmu = {0};
cmu.pll_clks = top_pll_clks;
cmu.nr_pll_clks = ARRAY_SIZE(top_pll_clks);
cmu.mux_clks = top_mux_clks;
cmu.nr_mux_clks = ARRAY_SIZE(top_mux_clks);
cmu.div_clks = top_div_clks;
cmu.nr_div_clks = ARRAY_SIZE(top_div_clks);
cmu.gate_clks = top_gate_clks;
cmu.nr_gate_clks = ARRAY_SIZE(top_gate_clks);
cmu.fixed_clks = fixed_rate_clks;
cmu.nr_fixed_clks = ARRAY_SIZE(fixed_rate_clks);
cmu.nr_clk_ids = TOP_NR_CLK;
cmu.clk_regs = top_clk_regs;
cmu.nr_clk_regs = ARRAY_SIZE(top_clk_regs);
exynos5260_cmu_register_one(np, &cmu);
}
