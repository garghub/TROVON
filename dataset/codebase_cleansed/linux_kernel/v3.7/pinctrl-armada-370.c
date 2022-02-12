static int __devinit armada_370_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_370_pinctrl_info;
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
static int __devexit armada_370_pinctrl_remove(struct platform_device *pdev)
{
return mvebu_pinctrl_remove(pdev);
}
