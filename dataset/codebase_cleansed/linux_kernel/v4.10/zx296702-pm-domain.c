static int normal_power_off(struct generic_pm_domain *domain)
{
struct zx_pm_domain *zpd = (struct zx_pm_domain *)domain;
unsigned long loop = 1000;
u32 tmp;
tmp = readl_relaxed(pcubase + PCU_DM_CLKEN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp, pcubase + PCU_DM_CLKEN);
udelay(5);
tmp = readl_relaxed(pcubase + PCU_DM_ISOEN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp | BIT(zpd->bit), pcubase + PCU_DM_ISOEN);
udelay(5);
tmp = readl_relaxed(pcubase + PCU_DM_RSTEN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp, pcubase + PCU_DM_RSTEN);
udelay(5);
tmp = readl_relaxed(pcubase + PCU_DM_PWRDN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp | BIT(zpd->bit), pcubase + PCU_DM_PWRDN);
do {
tmp = readl_relaxed(pcubase + PCU_DM_ACK_SYNC) & BIT(zpd->bit);
} while (--loop && !tmp);
if (!loop) {
pr_err("Error: %s %s fail\n", __func__, domain->name);
return -EIO;
}
return 0;
}
static int normal_power_on(struct generic_pm_domain *domain)
{
struct zx_pm_domain *zpd = (struct zx_pm_domain *)domain;
unsigned long loop = 10000;
u32 tmp;
tmp = readl_relaxed(pcubase + PCU_DM_PWRDN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp, pcubase + PCU_DM_PWRDN);
do {
tmp = readl_relaxed(pcubase + PCU_DM_ACK_SYNC) & BIT(zpd->bit);
} while (--loop && tmp);
if (!loop) {
pr_err("Error: %s %s fail\n", __func__, domain->name);
return -EIO;
}
tmp = readl_relaxed(pcubase + PCU_DM_RSTEN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp | BIT(zpd->bit), pcubase + PCU_DM_RSTEN);
udelay(5);
tmp = readl_relaxed(pcubase + PCU_DM_ISOEN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp, pcubase + PCU_DM_ISOEN);
udelay(5);
tmp = readl_relaxed(pcubase + PCU_DM_CLKEN);
tmp &= ~BIT(zpd->bit);
writel_relaxed(tmp | BIT(zpd->bit), pcubase + PCU_DM_CLKEN);
udelay(5);
return 0;
}
static int zx296702_pd_probe(struct platform_device *pdev)
{
struct genpd_onecell_data *genpd_data;
struct resource *res;
int i;
genpd_data = devm_kzalloc(&pdev->dev, sizeof(*genpd_data), GFP_KERNEL);
if (!genpd_data)
return -ENOMEM;
genpd_data->domains = zx296702_pm_domains;
genpd_data->num_domains = ARRAY_SIZE(zx296702_pm_domains);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no memory resource defined\n");
return -ENODEV;
}
pcubase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pcubase)) {
dev_err(&pdev->dev, "ioremap fail.\n");
return -EIO;
}
for (i = 0; i < ARRAY_SIZE(zx296702_pm_domains); ++i)
pm_genpd_init(zx296702_pm_domains[i], NULL, false);
of_genpd_add_provider_onecell(pdev->dev.of_node, genpd_data);
return 0;
}
static int __init zx296702_pd_init(void)
{
return platform_driver_register(&zx296702_pd_driver);
}
