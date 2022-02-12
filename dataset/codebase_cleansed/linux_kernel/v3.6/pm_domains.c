static int exynos_pd_power(struct generic_pm_domain *domain, bool power_on)
{
struct exynos_pm_domain *pd;
void __iomem *base;
u32 timeout, pwr;
char *op;
pd = container_of(domain, struct exynos_pm_domain, pd);
base = pd->base;
pwr = power_on ? S5P_INT_LOCAL_PWR_EN : 0;
__raw_writel(pwr, base);
timeout = 10;
while ((__raw_readl(base + 0x4) & S5P_INT_LOCAL_PWR_EN) != pwr) {
if (!timeout) {
op = (power_on) ? "enable" : "disable";
pr_err("Power domain %s %s failed\n", domain->name, op);
return -ETIMEDOUT;
}
timeout--;
cpu_relax();
usleep_range(80, 100);
}
return 0;
}
static int exynos_pd_power_on(struct generic_pm_domain *domain)
{
return exynos_pd_power(domain, true);
}
static int exynos_pd_power_off(struct generic_pm_domain *domain)
{
return exynos_pd_power(domain, false);
}
static __init int exynos_pm_dt_parse_domains(void)
{
struct device_node *np;
for_each_compatible_node(np, NULL, "samsung,exynos4210-pd") {
struct exynos_pm_domain *pd;
pd = kzalloc(sizeof(*pd), GFP_KERNEL);
if (!pd) {
pr_err("%s: failed to allocate memory for domain\n",
__func__);
return -ENOMEM;
}
if (of_get_property(np, "samsung,exynos4210-pd-off", NULL))
pd->is_off = true;
pd->name = np->name;
pd->base = of_iomap(np, 0);
pd->pd.power_off = exynos_pd_power_off;
pd->pd.power_on = exynos_pd_power_on;
pd->pd.of_node = np;
pm_genpd_init(&pd->pd, NULL, false);
}
return 0;
}
static __init int exynos_pm_dt_parse_domains(void)
{
return 0;
}
static __init __maybe_unused void exynos_pm_add_dev_to_genpd(struct platform_device *pdev,
struct exynos_pm_domain *pd)
{
if (pdev->dev.bus) {
if (!pm_genpd_add_device(&pd->pd, &pdev->dev))
pm_genpd_dev_need_restore(&pdev->dev, true);
else
pr_info("%s: error in adding %s device to %s power"
"domain\n", __func__, dev_name(&pdev->dev),
pd->name);
}
}
static __init int exynos4_pm_init_power_domain(void)
{
int idx;
if (of_have_populated_dt())
return exynos_pm_dt_parse_domains();
for (idx = 0; idx < ARRAY_SIZE(exynos4_pm_domains); idx++) {
struct exynos_pm_domain *pd = exynos4_pm_domains[idx];
int on = __raw_readl(pd->base + 0x4) & S5P_INT_LOCAL_PWR_EN;
pm_genpd_init(&pd->pd, NULL, !on);
}
#ifdef CONFIG_S5P_DEV_FIMD0
exynos_pm_add_dev_to_genpd(&s5p_device_fimd0, &exynos4_pd_lcd0);
#endif
#ifdef CONFIG_S5P_DEV_TV
exynos_pm_add_dev_to_genpd(&s5p_device_hdmi, &exynos4_pd_tv);
exynos_pm_add_dev_to_genpd(&s5p_device_mixer, &exynos4_pd_tv);
#endif
#ifdef CONFIG_S5P_DEV_MFC
exynos_pm_add_dev_to_genpd(&s5p_device_mfc, &exynos4_pd_mfc);
#endif
#ifdef CONFIG_S5P_DEV_FIMC0
exynos_pm_add_dev_to_genpd(&s5p_device_fimc0, &exynos4_pd_cam);
#endif
#ifdef CONFIG_S5P_DEV_FIMC1
exynos_pm_add_dev_to_genpd(&s5p_device_fimc1, &exynos4_pd_cam);
#endif
#ifdef CONFIG_S5P_DEV_FIMC2
exynos_pm_add_dev_to_genpd(&s5p_device_fimc2, &exynos4_pd_cam);
#endif
#ifdef CONFIG_S5P_DEV_FIMC3
exynos_pm_add_dev_to_genpd(&s5p_device_fimc3, &exynos4_pd_cam);
#endif
#ifdef CONFIG_S5P_DEV_CSIS0
exynos_pm_add_dev_to_genpd(&s5p_device_mipi_csis0, &exynos4_pd_cam);
#endif
#ifdef CONFIG_S5P_DEV_CSIS1
exynos_pm_add_dev_to_genpd(&s5p_device_mipi_csis1, &exynos4_pd_cam);
#endif
#ifdef CONFIG_S5P_DEV_G2D
exynos_pm_add_dev_to_genpd(&s5p_device_g2d, &exynos4_pd_lcd0);
#endif
#ifdef CONFIG_S5P_DEV_JPEG
exynos_pm_add_dev_to_genpd(&s5p_device_jpeg, &exynos4_pd_cam);
#endif
return 0;
}
int __init exynos_pm_late_initcall(void)
{
pm_genpd_poweroff_unused();
return 0;
}
