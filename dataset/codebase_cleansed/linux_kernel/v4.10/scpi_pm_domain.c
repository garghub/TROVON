static int scpi_pd_power(struct scpi_pm_domain *pd, bool power_on)
{
int ret;
enum scpi_power_domain_state state;
if (power_on)
state = SCPI_PD_STATE_ON;
else
state = SCPI_PD_STATE_OFF;
ret = pd->ops->device_set_power_state(pd->domain, state);
if (ret)
return ret;
return !(state == pd->ops->device_get_power_state(pd->domain));
}
static int scpi_pd_power_on(struct generic_pm_domain *domain)
{
struct scpi_pm_domain *pd = to_scpi_pd(domain);
return scpi_pd_power(pd, true);
}
static int scpi_pd_power_off(struct generic_pm_domain *domain)
{
struct scpi_pm_domain *pd = to_scpi_pd(domain);
return scpi_pd_power(pd, false);
}
static int scpi_pm_domain_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct scpi_pm_domain *scpi_pd;
struct genpd_onecell_data *scpi_pd_data;
struct generic_pm_domain **domains;
struct scpi_ops *scpi_ops;
int ret, num_domains, i;
scpi_ops = get_scpi_ops();
if (!scpi_ops)
return -EPROBE_DEFER;
if (!np) {
dev_err(dev, "device tree node not found\n");
return -ENODEV;
}
if (!scpi_ops->device_set_power_state ||
!scpi_ops->device_get_power_state) {
dev_err(dev, "power domains not supported in the firmware\n");
return -ENODEV;
}
ret = of_property_read_u32(np, "num-domains", &num_domains);
if (ret) {
dev_err(dev, "number of domains not found\n");
return -EINVAL;
}
scpi_pd = devm_kcalloc(dev, num_domains, sizeof(*scpi_pd), GFP_KERNEL);
if (!scpi_pd)
return -ENOMEM;
scpi_pd_data = devm_kzalloc(dev, sizeof(*scpi_pd_data), GFP_KERNEL);
if (!scpi_pd_data)
return -ENOMEM;
domains = devm_kcalloc(dev, num_domains, sizeof(*domains), GFP_KERNEL);
if (!domains)
return -ENOMEM;
for (i = 0; i < num_domains; i++, scpi_pd++) {
domains[i] = &scpi_pd->genpd;
scpi_pd->domain = i;
scpi_pd->ops = scpi_ops;
sprintf(scpi_pd->name, "%s.%d", np->name, i);
scpi_pd->genpd.name = scpi_pd->name;
scpi_pd->genpd.power_off = scpi_pd_power_off;
scpi_pd->genpd.power_on = scpi_pd_power_on;
pm_genpd_init(&scpi_pd->genpd, NULL, true);
}
scpi_pd_data->domains = domains;
scpi_pd_data->num_domains = num_domains;
of_genpd_add_provider_onecell(np, scpi_pd_data);
return 0;
}
