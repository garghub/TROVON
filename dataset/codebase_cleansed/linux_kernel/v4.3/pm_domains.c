static int exynos_pd_power(struct generic_pm_domain *domain, bool power_on)
{
struct exynos_pm_domain *pd;
void __iomem *base;
u32 timeout, pwr;
char *op;
int i;
pd = container_of(domain, struct exynos_pm_domain, pd);
base = pd->base;
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
if (IS_ERR(pd->asb_clk[i]))
break;
clk_prepare_enable(pd->asb_clk[i]);
}
if (!power_on) {
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
if (IS_ERR(pd->clk[i]))
break;
pd->pclk[i] = clk_get_parent(pd->clk[i]);
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
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
if (IS_ERR(pd->clk[i]))
break;
if (IS_ERR(pd->clk[i]))
continue;
if (clk_set_parent(pd->clk[i], pd->pclk[i]))
pr_err("%s: error setting parent to clock%d\n",
pd->name, i);
}
}
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
if (IS_ERR(pd->asb_clk[i]))
break;
clk_disable_unprepare(pd->asb_clk[i]);
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
struct device_node *np;
for_each_compatible_node(np, NULL, "samsung,exynos4210-pd") {
struct exynos_pm_domain *pd;
int on, i;
pd = kzalloc(sizeof(*pd), GFP_KERNEL);
if (!pd) {
pr_err("%s: failed to allocate memory for domain\n",
__func__);
of_node_put(np);
return -ENOMEM;
}
pd->pd.name = kstrdup_const(strrchr(np->full_name, '/') + 1,
GFP_KERNEL);
if (!pd->pd.name) {
kfree(pd);
of_node_put(np);
return -ENOMEM;
}
pd->name = pd->pd.name;
pd->base = of_iomap(np, 0);
if (!pd->base) {
pr_warn("%s: failed to map memory\n", __func__);
kfree_const(pd->pd.name);
kfree(pd);
continue;
}
pd->pd.power_off = exynos_pd_power_off;
pd->pd.power_on = exynos_pd_power_on;
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
char clk_name[8];
snprintf(clk_name, sizeof(clk_name), "asb%d", i);
pd->asb_clk[i] = of_clk_get_by_name(np, clk_name);
if (IS_ERR(pd->asb_clk[i]))
break;
}
pd->oscclk = of_clk_get_by_name(np, "oscclk");
if (IS_ERR(pd->oscclk))
goto no_clk;
for (i = 0; i < MAX_CLK_PER_DOMAIN; i++) {
char clk_name[8];
snprintf(clk_name, sizeof(clk_name), "clk%d", i);
pd->clk[i] = of_clk_get_by_name(np, clk_name);
if (IS_ERR(pd->clk[i]))
break;
pd->pclk[i] = ERR_PTR(-EINVAL);
}
if (IS_ERR(pd->clk[0]))
clk_put(pd->oscclk);
no_clk:
on = __raw_readl(pd->base + 0x4) & INT_LOCAL_PWR_EN;
pm_genpd_init(&pd->pd, NULL, !on);
of_genpd_add_provider_simple(np, &pd->pd);
}
for_each_compatible_node(np, NULL, "samsung,exynos4210-pd") {
struct generic_pm_domain *child_domain, *parent_domain;
struct of_phandle_args args;
args.np = np;
args.args_count = 0;
child_domain = of_genpd_get_from_provider(&args);
if (IS_ERR(child_domain))
continue;
if (of_parse_phandle_with_args(np, "power-domains",
"#power-domain-cells", 0, &args) != 0)
continue;
parent_domain = of_genpd_get_from_provider(&args);
if (IS_ERR(parent_domain))
continue;
if (pm_genpd_add_subdomain(parent_domain, child_domain))
pr_warn("%s failed to add subdomain: %s\n",
parent_domain->name, child_domain->name);
else
pr_info("%s has as child subdomain: %s.\n",
parent_domain->name, child_domain->name);
}
return 0;
}
