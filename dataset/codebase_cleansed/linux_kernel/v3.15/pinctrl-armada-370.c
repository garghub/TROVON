static int armada_370_mpp_ctrl_get(unsigned pid, unsigned long *config)
{
return default_mpp_ctrl_get(mpp_base, pid, config);
}
static int armada_370_mpp_ctrl_set(unsigned pid, unsigned long config)
{
return default_mpp_ctrl_set(mpp_base, pid, config);
}
static int armada_370_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_370_pinctrl_info;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mpp_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mpp_base))
return PTR_ERR(mpp_base);
soc->variant = 0;
soc->controls = mv88f6710_mpp_controls;
soc->ncontrols = ARRAY_SIZE(mv88f6710_mpp_controls);
soc->modes = mv88f6710_mpp_modes;
soc->nmodes = ARRAY_SIZE(mv88f6710_mpp_modes);
soc->gpioranges = mv88f6710_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(mv88f6710_mpp_gpio_ranges);
pdev->dev.platform_data = soc;
return mvebu_pinctrl_probe(pdev);
}
static int armada_370_pinctrl_remove(struct platform_device *pdev)
{
return mvebu_pinctrl_remove(pdev);
}
