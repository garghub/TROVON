static int exynos_pd_power(struct generic_pm_domain *domain, bool power_on)
{
struct exynos_pm_domain *pd;
void __iomem *base;
u32 timeout, pwr;
char *op;
pd = container_of(domain, struct exynos_pm_domain, pd);
base = pd->base;
if (!power_on) {
int i;
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
if (IS_ERR(pd->clk[i]))
break;
if (clk_set_parent(pd->clk[i], pd->oscclk))
pr_err("%s: error setting oscclk as parent to clock %d\n",
pd->name, i);
}
}
pwr = power_on ? INT_LOCAL_PWR_EN : 0;
__raw_writel(pwr, base);
timeout = 10;
while ((__raw_readl(base + 0x4) & INT_LOCAL_PWR_EN) != pwr) {
if (!timeout) {
op = (power_on) ? "enable" : "disable";
pr_err("Power domain %s %s failed\n", domain->name, op);
return -ETIMEDOUT;
}
timeout--;
cpu_relax();
usleep_range(80, 100);
}
if (power_on) {
int i;
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
if (IS_ERR(pd->clk[i]))
break;
if (clk_set_parent(pd->clk[i], pd->pclk[i]))
pr_err("%s: error setting parent to clock%d\n",
pd->name, i);
}
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
static __init int exynos4_pm_init_power_domain(void)
{
struct platform_device *pdev;
struct device_node *np;
for_each_compatible_node(np, NULL, "samsung,exynos4210-pd") {
struct exynos_pm_domain *pd;
int on, i;
struct device *dev;
pdev = of_find_device_by_node(np);
dev = &pdev->dev;
pd = kzalloc(sizeof(*pd), GFP_KERNEL);
if (!pd) {
pr_err("%s: failed to allocate memory for domain\n",
__func__);
return -ENOMEM;
}
pd->pd.name = kstrdup(np->name, GFP_KERNEL);
pd->name = pd->pd.name;
pd->base = of_iomap(np, 0);
pd->pd.power_off = exynos_pd_power_off;
pd->pd.power_on = exynos_pd_power_on;
pd->oscclk = clk_get(dev, "oscclk");
if (IS_ERR(pd->oscclk))
goto no_clk;
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
char clk_name[8];
snprintf(clk_name, sizeof(clk_name), "clk%d", i);
pd->clk[i] = clk_get(dev, clk_name);
if (IS_ERR(pd->clk[i]))
break;
snprintf(clk_name, sizeof(clk_name), "pclk%d", i);
pd->pclk[i] = clk_get(dev, clk_name);
if (IS_ERR(pd->pclk[i])) {
clk_put(pd->clk[i]);
pd->clk[i] = ERR_PTR(-EINVAL);
break;
}
}
if (IS_ERR(pd->clk[0]))
clk_put(pd->oscclk);
no_clk:
on = __raw_readl(pd->base + 0x4) & INT_LOCAL_PWR_EN;
pm_genpd_init(&pd->pd, NULL, !on);
of_genpd_add_provider_simple(np, &pd->pd);
}
return 0;
}
