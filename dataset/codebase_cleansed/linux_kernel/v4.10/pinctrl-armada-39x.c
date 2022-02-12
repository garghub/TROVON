static int armada_39x_mpp_ctrl_get(unsigned pid, unsigned long *config)
{
return default_mpp_ctrl_get(mpp_base, pid, config);
}
static int armada_39x_mpp_ctrl_set(unsigned pid, unsigned long config)
{
return default_mpp_ctrl_set(mpp_base, pid, config);
}
static int armada_39x_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_39x_pinctrl_info;
const struct of_device_id *match =
of_match_device(armada_39x_pinctrl_of_match, &pdev->dev);
struct resource *res;
if (!match)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mpp_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mpp_base))
return PTR_ERR(mpp_base);
soc->variant = (unsigned) match->data & 0xff;
soc->controls = armada_39x_mpp_controls;
soc->ncontrols = ARRAY_SIZE(armada_39x_mpp_controls);
soc->gpioranges = armada_39x_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(armada_39x_mpp_gpio_ranges);
soc->modes = armada_39x_mpp_modes;
soc->nmodes = armada_39x_mpp_controls[0].npins;
pdev->dev.platform_data = soc;
return mvebu_pinctrl_probe(pdev);
}
