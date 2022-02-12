static int sun6i_prcm_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
const struct prcm_data *data;
struct resource *res;
int ret;
match = of_match_node(sun6i_prcm_dt_ids, np);
if (!match)
return -EINVAL;
data = match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no prcm memory region provided\n");
return -ENOENT;
}
ret = mfd_add_devices(&pdev->dev, 0, data->subdevs, data->nsubdevs,
res, -1, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to add subdevices\n");
return ret;
}
return 0;
}
