static int scpsys_domain_is_on(struct scp_domain *scpd)
{
struct scp *scp = scpd->scp;
u32 status = readl(scp->base + SPM_PWR_STATUS) & scpd->data->sta_mask;
u32 status2 = readl(scp->base + SPM_PWR_STATUS_2ND) &
scpd->data->sta_mask;
if (status && status2)
return true;
if (!status && !status2)
return false;
return -EINVAL;
}
static int scpsys_power_on(struct generic_pm_domain *genpd)
{
struct scp_domain *scpd = container_of(genpd, struct scp_domain, genpd);
struct scp *scp = scpd->scp;
unsigned long timeout;
bool expired;
void __iomem *ctl_addr = scp->base + scpd->data->ctl_offs;
u32 sram_pdn_ack = scpd->data->sram_pdn_ack_bits;
u32 val;
int ret;
int i;
if (scpd->supply) {
ret = regulator_enable(scpd->supply);
if (ret)
return ret;
}
for (i = 0; i < MAX_CLKS && scpd->clk[i]; i++) {
ret = clk_prepare_enable(scpd->clk[i]);
if (ret) {
for (--i; i >= 0; i--)
clk_disable_unprepare(scpd->clk[i]);
goto err_clk;
}
}
val = readl(ctl_addr);
val |= PWR_ON_BIT;
writel(val, ctl_addr);
val |= PWR_ON_2ND_BIT;
writel(val, ctl_addr);
timeout = jiffies + HZ;
expired = false;
while (1) {
ret = scpsys_domain_is_on(scpd);
if (ret > 0)
break;
if (expired) {
ret = -ETIMEDOUT;
goto err_pwr_ack;
}
cpu_relax();
if (time_after(jiffies, timeout))
expired = true;
}
val &= ~PWR_CLK_DIS_BIT;
writel(val, ctl_addr);
val &= ~PWR_ISO_BIT;
writel(val, ctl_addr);
val |= PWR_RST_B_BIT;
writel(val, ctl_addr);
val &= ~scpd->data->sram_pdn_bits;
writel(val, ctl_addr);
timeout = jiffies + HZ;
expired = false;
while (sram_pdn_ack && (readl(ctl_addr) & sram_pdn_ack)) {
if (expired) {
ret = -ETIMEDOUT;
goto err_pwr_ack;
}
cpu_relax();
if (time_after(jiffies, timeout))
expired = true;
}
if (scpd->data->bus_prot_mask) {
ret = mtk_infracfg_clear_bus_protection(scp->infracfg,
scpd->data->bus_prot_mask);
if (ret)
goto err_pwr_ack;
}
return 0;
err_pwr_ack:
for (i = MAX_CLKS - 1; i >= 0; i--) {
if (scpd->clk[i])
clk_disable_unprepare(scpd->clk[i]);
}
err_clk:
if (scpd->supply)
regulator_disable(scpd->supply);
dev_err(scp->dev, "Failed to power on domain %s\n", genpd->name);
return ret;
}
static int scpsys_power_off(struct generic_pm_domain *genpd)
{
struct scp_domain *scpd = container_of(genpd, struct scp_domain, genpd);
struct scp *scp = scpd->scp;
unsigned long timeout;
bool expired;
void __iomem *ctl_addr = scp->base + scpd->data->ctl_offs;
u32 pdn_ack = scpd->data->sram_pdn_ack_bits;
u32 val;
int ret;
int i;
if (scpd->data->bus_prot_mask) {
ret = mtk_infracfg_set_bus_protection(scp->infracfg,
scpd->data->bus_prot_mask);
if (ret)
goto out;
}
val = readl(ctl_addr);
val |= scpd->data->sram_pdn_bits;
writel(val, ctl_addr);
timeout = jiffies + HZ;
expired = false;
while (pdn_ack && (readl(ctl_addr) & pdn_ack) != pdn_ack) {
if (expired) {
ret = -ETIMEDOUT;
goto out;
}
cpu_relax();
if (time_after(jiffies, timeout))
expired = true;
}
val |= PWR_ISO_BIT;
writel(val, ctl_addr);
val &= ~PWR_RST_B_BIT;
writel(val, ctl_addr);
val |= PWR_CLK_DIS_BIT;
writel(val, ctl_addr);
val &= ~PWR_ON_BIT;
writel(val, ctl_addr);
val &= ~PWR_ON_2ND_BIT;
writel(val, ctl_addr);
timeout = jiffies + HZ;
expired = false;
while (1) {
ret = scpsys_domain_is_on(scpd);
if (ret == 0)
break;
if (expired) {
ret = -ETIMEDOUT;
goto out;
}
cpu_relax();
if (time_after(jiffies, timeout))
expired = true;
}
for (i = 0; i < MAX_CLKS && scpd->clk[i]; i++)
clk_disable_unprepare(scpd->clk[i]);
if (scpd->supply)
regulator_disable(scpd->supply);
return 0;
out:
dev_err(scp->dev, "Failed to power off domain %s\n", genpd->name);
return ret;
}
static bool scpsys_active_wakeup(struct device *dev)
{
struct generic_pm_domain *genpd;
struct scp_domain *scpd;
genpd = pd_to_genpd(dev->pm_domain);
scpd = container_of(genpd, struct scp_domain, genpd);
return scpd->data->active_wakeup;
}
static void init_clks(struct platform_device *pdev, struct clk **clk)
{
int i;
for (i = CLK_NONE + 1; i < CLK_MAX; i++)
clk[i] = devm_clk_get(&pdev->dev, clk_names[i]);
}
static struct scp *init_scp(struct platform_device *pdev,
const struct scp_domain_data *scp_domain_data, int num)
{
struct genpd_onecell_data *pd_data;
struct resource *res;
int i, j;
struct scp *scp;
struct clk *clk[CLK_MAX];
scp = devm_kzalloc(&pdev->dev, sizeof(*scp), GFP_KERNEL);
if (!scp)
return ERR_PTR(-ENOMEM);
scp->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
scp->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(scp->base))
return ERR_CAST(scp->base);
scp->domains = devm_kzalloc(&pdev->dev,
sizeof(*scp->domains) * num, GFP_KERNEL);
if (!scp->domains)
return ERR_PTR(-ENOMEM);
pd_data = &scp->pd_data;
pd_data->domains = devm_kzalloc(&pdev->dev,
sizeof(*pd_data->domains) * num, GFP_KERNEL);
if (!pd_data->domains)
return ERR_PTR(-ENOMEM);
scp->infracfg = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"infracfg");
if (IS_ERR(scp->infracfg)) {
dev_err(&pdev->dev, "Cannot find infracfg controller: %ld\n",
PTR_ERR(scp->infracfg));
return ERR_CAST(scp->infracfg);
}
for (i = 0; i < num; i++) {
struct scp_domain *scpd = &scp->domains[i];
const struct scp_domain_data *data = &scp_domain_data[i];
scpd->supply = devm_regulator_get_optional(&pdev->dev, data->name);
if (IS_ERR(scpd->supply)) {
if (PTR_ERR(scpd->supply) == -ENODEV)
scpd->supply = NULL;
else
return ERR_CAST(scpd->supply);
}
}
pd_data->num_domains = num;
init_clks(pdev, clk);
for (i = 0; i < num; i++) {
struct scp_domain *scpd = &scp->domains[i];
struct generic_pm_domain *genpd = &scpd->genpd;
const struct scp_domain_data *data = &scp_domain_data[i];
pd_data->domains[i] = genpd;
scpd->scp = scp;
scpd->data = data;
for (j = 0; j < MAX_CLKS && data->clk_id[j]; j++) {
struct clk *c = clk[data->clk_id[j]];
if (IS_ERR(c)) {
dev_err(&pdev->dev, "%s: clk unavailable\n",
data->name);
return ERR_CAST(c);
}
scpd->clk[j] = c;
}
genpd->name = data->name;
genpd->power_off = scpsys_power_off;
genpd->power_on = scpsys_power_on;
genpd->dev_ops.active_wakeup = scpsys_active_wakeup;
}
return scp;
}
static void mtk_register_power_domains(struct platform_device *pdev,
struct scp *scp, int num)
{
struct genpd_onecell_data *pd_data;
int i, ret;
for (i = 0; i < num; i++) {
struct scp_domain *scpd = &scp->domains[i];
struct generic_pm_domain *genpd = &scpd->genpd;
genpd->power_on(genpd);
pm_genpd_init(genpd, NULL, false);
}
pd_data = &scp->pd_data;
ret = of_genpd_add_provider_onecell(pdev->dev.of_node, pd_data);
if (ret)
dev_err(&pdev->dev, "Failed to add OF provider: %d\n", ret);
}
static int __init scpsys_probe_mt2701(struct platform_device *pdev)
{
struct scp *scp;
scp = init_scp(pdev, scp_domain_data_mt2701, NUM_DOMAINS_MT2701);
if (IS_ERR(scp))
return PTR_ERR(scp);
mtk_register_power_domains(pdev, scp, NUM_DOMAINS_MT2701);
return 0;
}
static int __init scpsys_probe_mt8173(struct platform_device *pdev)
{
struct scp *scp;
struct genpd_onecell_data *pd_data;
int ret;
scp = init_scp(pdev, scp_domain_data_mt8173, NUM_DOMAINS_MT8173);
if (IS_ERR(scp))
return PTR_ERR(scp);
mtk_register_power_domains(pdev, scp, NUM_DOMAINS_MT8173);
pd_data = &scp->pd_data;
ret = pm_genpd_add_subdomain(pd_data->domains[MT8173_POWER_DOMAIN_MFG_ASYNC],
pd_data->domains[MT8173_POWER_DOMAIN_MFG_2D]);
if (ret && IS_ENABLED(CONFIG_PM))
dev_err(&pdev->dev, "Failed to add subdomain: %d\n", ret);
ret = pm_genpd_add_subdomain(pd_data->domains[MT8173_POWER_DOMAIN_MFG_2D],
pd_data->domains[MT8173_POWER_DOMAIN_MFG]);
if (ret && IS_ENABLED(CONFIG_PM))
dev_err(&pdev->dev, "Failed to add subdomain: %d\n", ret);
return 0;
}
static int scpsys_probe(struct platform_device *pdev)
{
int (*probe)(struct platform_device *);
const struct of_device_id *of_id;
of_id = of_match_node(of_scpsys_match_tbl, pdev->dev.of_node);
if (!of_id || !of_id->data)
return -EINVAL;
probe = of_id->data;
return probe(pdev);
}
