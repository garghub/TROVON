static void __init exynos4415_cmu_init(struct device_node *np)
{
samsung_cmu_register_one(np, &cmu_info);
}
static void __init exynos4415_cmu_dmc_init(struct device_node *np)
{
samsung_cmu_register_one(np, &cmu_dmc_info);
}
