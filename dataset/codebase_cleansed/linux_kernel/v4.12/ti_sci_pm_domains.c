static int ti_sci_dev_id(struct device *dev)
{
struct generic_pm_domain_data *genpd_data = dev_gpd_data(dev);
struct ti_sci_genpd_dev_data *sci_dev_data = genpd_data->data;
return sci_dev_data->idx;
}
static const struct ti_sci_handle *ti_sci_dev_to_sci_handle(struct device *dev)
{
struct generic_pm_domain *pd = pd_to_genpd(dev->pm_domain);
struct ti_sci_pm_domain *ti_sci_genpd = genpd_to_ti_sci_pd(pd);
return ti_sci_genpd->ti_sci;
}
static int ti_sci_dev_start(struct device *dev)
{
const struct ti_sci_handle *ti_sci = ti_sci_dev_to_sci_handle(dev);
int idx = ti_sci_dev_id(dev);
return ti_sci->ops.dev_ops.get_device(ti_sci, idx);
}
static int ti_sci_dev_stop(struct device *dev)
{
const struct ti_sci_handle *ti_sci = ti_sci_dev_to_sci_handle(dev);
int idx = ti_sci_dev_id(dev);
return ti_sci->ops.dev_ops.put_device(ti_sci, idx);
}
static int ti_sci_pd_attach_dev(struct generic_pm_domain *domain,
struct device *dev)
{
struct device_node *np = dev->of_node;
struct of_phandle_args pd_args;
struct ti_sci_pm_domain *ti_sci_genpd = genpd_to_ti_sci_pd(domain);
const struct ti_sci_handle *ti_sci = ti_sci_genpd->ti_sci;
struct ti_sci_genpd_dev_data *sci_dev_data;
struct generic_pm_domain_data *genpd_data;
int idx, ret = 0;
ret = of_parse_phandle_with_args(np, "power-domains",
"#power-domain-cells", 0, &pd_args);
if (ret < 0)
return ret;
if (pd_args.args_count != 1)
return -EINVAL;
idx = pd_args.args[0];
ret = ti_sci->ops.dev_ops.is_valid(ti_sci, idx);
if (ret)
return -EINVAL;
sci_dev_data = kzalloc(sizeof(*sci_dev_data), GFP_KERNEL);
if (!sci_dev_data)
return -ENOMEM;
sci_dev_data->idx = idx;
genpd_data = dev_gpd_data(dev);
genpd_data->data = sci_dev_data;
return 0;
}
static void ti_sci_pd_detach_dev(struct generic_pm_domain *domain,
struct device *dev)
{
struct generic_pm_domain_data *genpd_data = dev_gpd_data(dev);
struct ti_sci_genpd_dev_data *sci_dev_data = genpd_data->data;
kfree(sci_dev_data);
genpd_data->data = NULL;
}
static int ti_sci_pm_domain_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct ti_sci_pm_domain *ti_sci_pd;
int ret;
ti_sci_pd = devm_kzalloc(dev, sizeof(*ti_sci_pd), GFP_KERNEL);
if (!ti_sci_pd)
return -ENOMEM;
ti_sci_pd->ti_sci = devm_ti_sci_get_handle(dev);
if (IS_ERR(ti_sci_pd->ti_sci))
return PTR_ERR(ti_sci_pd->ti_sci);
ti_sci_pd->dev = dev;
ti_sci_pd->pd.attach_dev = ti_sci_pd_attach_dev;
ti_sci_pd->pd.detach_dev = ti_sci_pd_detach_dev;
ti_sci_pd->pd.dev_ops.start = ti_sci_dev_start;
ti_sci_pd->pd.dev_ops.stop = ti_sci_dev_stop;
pm_genpd_init(&ti_sci_pd->pd, NULL, true);
ret = of_genpd_add_provider_simple(np, &ti_sci_pd->pd);
return ret;
}
