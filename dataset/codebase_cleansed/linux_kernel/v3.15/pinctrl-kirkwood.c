static int kirkwood_mpp_ctrl_get(unsigned pid, unsigned long *config)
{
return default_mpp_ctrl_get(mpp_base, pid, config);
}
static int kirkwood_mpp_ctrl_set(unsigned pid, unsigned long config)
{
return default_mpp_ctrl_set(mpp_base, pid, config);
}
static int kirkwood_pinctrl_probe(struct platform_device *pdev)
{
struct resource *res;
const struct of_device_id *match =
of_match_device(kirkwood_pinctrl_of_match, &pdev->dev);
pdev->dev.platform_data = (void *)match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mpp_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mpp_base))
return PTR_ERR(mpp_base);
return mvebu_pinctrl_probe(pdev);
}
static int kirkwood_pinctrl_remove(struct platform_device *pdev)
{
return mvebu_pinctrl_remove(pdev);
}
