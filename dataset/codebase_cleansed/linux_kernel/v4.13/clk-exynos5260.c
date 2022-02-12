static void __init exynos5260_clk_aud_init(struct device_node *np)
{
samsung_cmu_register_one(np, &aud_cmu);
}
static void __init exynos5260_clk_disp_init(struct device_node *np)
{
samsung_cmu_register_one(np, &disp_cmu);
}
static void __init exynos5260_clk_egl_init(struct device_node *np)
{
samsung_cmu_register_one(np, &egl_cmu);
}
static void __init exynos5260_clk_fsys_init(struct device_node *np)
{
samsung_cmu_register_one(np, &fsys_cmu);
}
static void __init exynos5260_clk_g2d_init(struct device_node *np)
{
samsung_cmu_register_one(np, &g2d_cmu);
}
static void __init exynos5260_clk_g3d_init(struct device_node *np)
{
samsung_cmu_register_one(np, &g3d_cmu);
}
static void __init exynos5260_clk_gscl_init(struct device_node *np)
{
samsung_cmu_register_one(np, &gscl_cmu);
}
static void __init exynos5260_clk_isp_init(struct device_node *np)
{
samsung_cmu_register_one(np, &isp_cmu);
}
static void __init exynos5260_clk_kfc_init(struct device_node *np)
{
samsung_cmu_register_one(np, &kfc_cmu);
}
static void __init exynos5260_clk_mfc_init(struct device_node *np)
{
samsung_cmu_register_one(np, &mfc_cmu);
}
static void __init exynos5260_clk_mif_init(struct device_node *np)
{
samsung_cmu_register_one(np, &mif_cmu);
}
static void __init exynos5260_clk_peri_init(struct device_node *np)
{
samsung_cmu_register_one(np, &peri_cmu);
}
static void __init exynos5260_clk_top_init(struct device_node *np)
{
samsung_cmu_register_one(np, &top_cmu);
}
