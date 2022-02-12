static void __init exynos7_clk_topc_init(struct device_node *np)
{
samsung_cmu_register_one(np, &topc_cmu_info);
}
static void __init exynos7_clk_top0_init(struct device_node *np)
{
samsung_cmu_register_one(np, &top0_cmu_info);
}
static void __init exynos7_clk_top1_init(struct device_node *np)
{
samsung_cmu_register_one(np, &top1_cmu_info);
}
static void __init exynos7_clk_ccore_init(struct device_node *np)
{
samsung_cmu_register_one(np, &ccore_cmu_info);
}
static void __init exynos7_clk_peric0_init(struct device_node *np)
{
samsung_cmu_register_one(np, &peric0_cmu_info);
}
static void __init exynos7_clk_peric1_init(struct device_node *np)
{
samsung_cmu_register_one(np, &peric1_cmu_info);
}
static void __init exynos7_clk_peris_init(struct device_node *np)
{
samsung_cmu_register_one(np, &peris_cmu_info);
}
static void __init exynos7_clk_fsys0_init(struct device_node *np)
{
samsung_cmu_register_one(np, &fsys0_cmu_info);
}
static void __init exynos7_clk_fsys1_init(struct device_node *np)
{
samsung_cmu_register_one(np, &fsys1_cmu_info);
}
static void __init exynos7_clk_mscl_init(struct device_node *np)
{
samsung_cmu_register_one(np, &mscl_cmu_info);
}
static void __init exynos7_clk_aud_init(struct device_node *np)
{
samsung_cmu_register_one(np, &aud_cmu_info);
}
