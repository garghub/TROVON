static int owl_sps_set_power(struct owl_sps_domain *pd, bool enable)
{
u32 pwr_mask, ack_mask;
ack_mask = BIT(pd->info->ack_bit);
pwr_mask = BIT(pd->info->pwr_bit);
return owl_sps_set_pg(pd->sps->base, pwr_mask, ack_mask, enable);
}
static int owl_sps_power_on(struct generic_pm_domain *domain)
{
struct owl_sps_domain *pd = to_owl_pd(domain);
dev_dbg(pd->sps->dev, "%s power on", pd->info->name);
return owl_sps_set_power(pd, true);
}
static int owl_sps_power_off(struct generic_pm_domain *domain)
{
struct owl_sps_domain *pd = to_owl_pd(domain);
dev_dbg(pd->sps->dev, "%s power off", pd->info->name);
return owl_sps_set_power(pd, false);
}
static int owl_sps_init_domain(struct owl_sps *sps, int index)
{
struct owl_sps_domain *pd;
pd = devm_kzalloc(sps->dev, sizeof(*pd), GFP_KERNEL);
if (!pd)
return -ENOMEM;
pd->info = &sps->info->domains[index];
pd->sps = sps;
pd->genpd.name = pd->info->name;
pd->genpd.power_on = owl_sps_power_on;
pd->genpd.power_off = owl_sps_power_off;
pd->genpd.flags = pd->info->genpd_flags;
pm_genpd_init(&pd->genpd, NULL, false);
sps->genpd_data.domains[index] = &pd->genpd;
return 0;
}
static int owl_sps_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct owl_sps_info *sps_info;
struct owl_sps *sps;
int i, ret;
if (!pdev->dev.of_node) {
dev_err(&pdev->dev, "no device node\n");
return -ENODEV;
}
match = of_match_device(pdev->dev.driver->of_match_table, &pdev->dev);
if (!match || !match->data) {
dev_err(&pdev->dev, "unknown compatible or missing data\n");
return -EINVAL;
}
sps_info = match->data;
sps = devm_kzalloc(&pdev->dev, sizeof(*sps) +
sps_info->num_domains * sizeof(sps->domains[0]),
GFP_KERNEL);
if (!sps)
return -ENOMEM;
sps->base = of_io_request_and_map(pdev->dev.of_node, 0, "owl-sps");
if (IS_ERR(sps->base)) {
dev_err(&pdev->dev, "failed to map sps registers\n");
return PTR_ERR(sps->base);
}
sps->dev = &pdev->dev;
sps->info = sps_info;
sps->genpd_data.domains = sps->domains;
sps->genpd_data.num_domains = sps_info->num_domains;
for (i = 0; i < sps_info->num_domains; i++) {
ret = owl_sps_init_domain(sps, i);
if (ret)
return ret;
}
ret = of_genpd_add_provider_onecell(pdev->dev.of_node, &sps->genpd_data);
if (ret) {
dev_err(&pdev->dev, "failed to add provider (%d)", ret);
return ret;
}
return 0;
}
static int __init owl_sps_init(void)
{
return platform_driver_register(&owl_sps_platform_driver);
}
