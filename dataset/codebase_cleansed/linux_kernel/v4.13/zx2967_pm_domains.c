static int zx2967_power_on(struct generic_pm_domain *domain)
{
struct zx2967_pm_domain *zpd = (struct zx2967_pm_domain *)domain;
unsigned long loop = 1000;
u32 val;
val = readl_relaxed(pcubase + PCU_DM_PWREN(zpd));
if (zpd->polarity == PWREN)
val |= BIT(zpd->bit);
else
val &= ~BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_PWREN(zpd));
do {
udelay(1);
val = readl_relaxed(pcubase + PCU_DM_ACK_SYNC(zpd))
& BIT(zpd->bit);
} while (--loop && !val);
if (!loop) {
pr_err("Error: %s %s fail\n", __func__, domain->name);
return -EIO;
}
val = readl_relaxed(pcubase + PCU_DM_RSTEN(zpd));
val |= BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_RSTEN(zpd));
udelay(5);
val = readl_relaxed(pcubase + PCU_DM_ISOEN(zpd));
val &= ~BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_ISOEN(zpd));
udelay(5);
val = readl_relaxed(pcubase + PCU_DM_CLKEN(zpd));
val |= BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_CLKEN(zpd));
udelay(5);
pr_debug("poweron %s\n", domain->name);
return 0;
}
static int zx2967_power_off(struct generic_pm_domain *domain)
{
struct zx2967_pm_domain *zpd = (struct zx2967_pm_domain *)domain;
unsigned long loop = 1000;
u32 val;
val = readl_relaxed(pcubase + PCU_DM_CLKEN(zpd));
val &= ~BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_CLKEN(zpd));
udelay(5);
val = readl_relaxed(pcubase + PCU_DM_ISOEN(zpd));
val |= BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_ISOEN(zpd));
udelay(5);
val = readl_relaxed(pcubase + PCU_DM_RSTEN(zpd));
val &= ~BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_RSTEN(zpd));
udelay(5);
val = readl_relaxed(pcubase + PCU_DM_PWREN(zpd));
if (zpd->polarity == PWREN)
val &= ~BIT(zpd->bit);
else
val |= BIT(zpd->bit);
writel_relaxed(val, pcubase + PCU_DM_PWREN(zpd));
do {
udelay(1);
val = readl_relaxed(pcubase + PCU_DM_ACK_SYNC(zpd))
& BIT(zpd->bit);
} while (--loop && val);
if (!loop) {
pr_err("Error: %s %s fail\n", __func__, domain->name);
return -EIO;
}
pr_debug("poweroff %s\n", domain->name);
return 0;
}
int zx2967_pd_probe(struct platform_device *pdev,
struct generic_pm_domain **zx_pm_domains,
int domain_num)
{
struct genpd_onecell_data *genpd_data;
struct resource *res;
int i;
genpd_data = devm_kzalloc(&pdev->dev, sizeof(*genpd_data), GFP_KERNEL);
if (!genpd_data)
return -ENOMEM;
genpd_data->domains = zx_pm_domains;
genpd_data->num_domains = domain_num;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pcubase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pcubase))
return PTR_ERR(pcubase);
for (i = 0; i < domain_num; ++i) {
zx_pm_domains[i]->power_on = zx2967_power_on;
zx_pm_domains[i]->power_off = zx2967_power_off;
pm_genpd_init(zx_pm_domains[i], NULL, false);
}
of_genpd_add_provider_onecell(pdev->dev.of_node, genpd_data);
dev_info(&pdev->dev, "powerdomain init ok\n");
return 0;
}
