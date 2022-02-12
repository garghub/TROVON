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
samsung_cmu_register_one(np, &apollo_cmu_info);
}
static void __init exynos5433_cmu_atlas_init(struct device_node *np)
{
samsung_cmu_register_one(np, &atlas_cmu_info);
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
