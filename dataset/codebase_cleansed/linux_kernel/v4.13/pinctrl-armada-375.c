static int armada_375_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_375_pinctrl_info;
soc->variant = 0;
soc->controls = mv88f6720_mpp_controls;
soc->ncontrols = ARRAY_SIZE(mv88f6720_mpp_controls);
soc->modes = mv88f6720_mpp_modes;
soc->nmodes = ARRAY_SIZE(mv88f6720_mpp_modes);
soc->gpioranges = mv88f6720_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(mv88f6720_mpp_gpio_ranges);
pdev->dev.platform_data = soc;
return mvebu_pinctrl_simple_mmio_probe(pdev);
}
