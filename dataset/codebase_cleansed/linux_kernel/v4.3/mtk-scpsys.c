static int scpsys_domain_is_on(struct scp_domain *scpd)
{
struct scp *scp = scpd->scp;
u32 status = readl(scp->base + SPM_PWR_STATUS) & scpd->sta_mask;
u32 status2 = readl(scp->base + SPM_PWR_STATUS_2ND) & scpd->sta_mask;
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
void __iomem *ctl_addr = scpd->ctl_addr;
u32 sram_pdn_ack = scpd->sram_pdn_ack_bits;
u32 val;
int ret;
if (scpd->clk) {
ret = clk_prepare_enable(scpd->clk);
if (ret)
goto err_clk;
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
val &= ~scpd->sram_pdn_bits;
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
if (scpd->bus_prot_mask) {
ret = mtk_infracfg_clear_bus_protection(scp->infracfg,
scpd->bus_prot_mask);
if (ret)
goto err_pwr_ack;
}
return 0;
err_pwr_ack:
clk_disable_unprepare(scpd->clk);
err_clk:
dev_err(scp->dev, "Failed to power on domain %s\n", genpd->name);
return ret;
}
static int scpsys_power_off(struct generic_pm_domain *genpd)
{
struct scp_domain *scpd = container_of(genpd, struct scp_domain, genpd);
struct scp *scp = scpd->scp;
unsigned long timeout;
bool expired;
void __iomem *ctl_addr = scpd->ctl_addr;
u32 pdn_ack = scpd->sram_pdn_ack_bits;
u32 val;
int ret;
if (scpd->bus_prot_mask) {
ret = mtk_infracfg_set_bus_protection(scp->infracfg,
scpd->bus_prot_mask);
if (ret)
goto out;
}
val = readl(ctl_addr);
val |= scpd->sram_pdn_bits;
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
if (scpd->clk)
clk_disable_unprepare(scpd->clk);
return 0;
out:
dev_err(scp->dev, "Failed to power off domain %s\n", genpd->name);
return ret;
}
static int __init scpsys_probe(struct platform_device *pdev)
{
struct genpd_onecell_data *pd_data;
struct resource *res;
int i, ret;
struct scp *scp;
struct clk *clk[MT8173_CLK_MAX];
scp = devm_kzalloc(&pdev->dev, sizeof(*scp), GFP_KERNEL);
if (!scp)
return -ENOMEM;
scp->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
scp->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(scp->base))
return PTR_ERR(scp->base);
pd_data = &scp->pd_data;
pd_data->domains = devm_kzalloc(&pdev->dev,
sizeof(*pd_data->domains) * NUM_DOMAINS, GFP_KERNEL);
if (!pd_data->domains)
return -ENOMEM;
clk[MT8173_CLK_MM] = devm_clk_get(&pdev->dev, "mm");
if (IS_ERR(clk[MT8173_CLK_MM]))
return PTR_ERR(clk[MT8173_CLK_MM]);
clk[MT8173_CLK_MFG] = devm_clk_get(&pdev->dev, "mfg");
if (IS_ERR(clk[MT8173_CLK_MFG]))
return PTR_ERR(clk[MT8173_CLK_MFG]);
scp->infracfg = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"infracfg");
if (IS_ERR(scp->infracfg)) {
dev_err(&pdev->dev, "Cannot find infracfg controller: %ld\n",
PTR_ERR(scp->infracfg));
return PTR_ERR(scp->infracfg);
}
pd_data->num_domains = NUM_DOMAINS;
for (i = 0; i < NUM_DOMAINS; i++) {
struct scp_domain *scpd = &scp->domains[i];
struct generic_pm_domain *genpd = &scpd->genpd;
const struct scp_domain_data *data = &scp_domain_data[i];
pd_data->domains[i] = genpd;
scpd->scp = scp;
scpd->sta_mask = data->sta_mask;
scpd->ctl_addr = scp->base + data->ctl_offs;
scpd->sram_pdn_bits = data->sram_pdn_bits;
scpd->sram_pdn_ack_bits = data->sram_pdn_ack_bits;
scpd->bus_prot_mask = data->bus_prot_mask;
if (data->clk_id != MT8173_CLK_NONE)
scpd->clk = clk[data->clk_id];
genpd->name = data->name;
genpd->power_off = scpsys_power_off;
genpd->power_on = scpsys_power_on;
genpd->power_on(genpd);
pm_genpd_init(genpd, NULL, false);
}
ret = pm_genpd_add_subdomain(pd_data->domains[MT8173_POWER_DOMAIN_MFG_ASYNC],
pd_data->domains[MT8173_POWER_DOMAIN_MFG_2D]);
if (ret && IS_ENABLED(CONFIG_PM))
dev_err(&pdev->dev, "Failed to add subdomain: %d\n", ret);
ret = pm_genpd_add_subdomain(pd_data->domains[MT8173_POWER_DOMAIN_MFG_2D],
pd_data->domains[MT8173_POWER_DOMAIN_MFG]);
if (ret && IS_ENABLED(CONFIG_PM))
dev_err(&pdev->dev, "Failed to add subdomain: %d\n", ret);
ret = of_genpd_add_provider_onecell(pdev->dev.of_node, pd_data);
if (ret)
dev_err(&pdev->dev, "Failed to add OF provider: %d\n", ret);
return 0;
}
