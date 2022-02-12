static void __init exynos5410_clk_init(struct device_node *np)
{
struct clk *xxti = of_clk_get(np, 0);
if (!IS_ERR(xxti) && clk_get_rate(xxti) == 24 * MHZ)
exynos5410_plls[epll].rate_table = exynos5410_pll2550x_24mhz_tbl;
samsung_cmu_register_one(np, &cmu);
pr_debug("Exynos5410: clock setup completed.\n");
}
