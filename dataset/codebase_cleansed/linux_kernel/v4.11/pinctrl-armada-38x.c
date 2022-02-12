static int armada_38x_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_38x_pinctrl_info;
const struct of_device_id *match =
of_match_device(armada_38x_pinctrl_of_match, &pdev->dev);
if (!match)
return -ENODEV;
soc->variant = (unsigned) match->data & 0xff;
soc->controls = armada_38x_mpp_controls;
soc->ncontrols = ARRAY_SIZE(armada_38x_mpp_controls);
soc->gpioranges = armada_38x_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(armada_38x_mpp_gpio_ranges);
soc->modes = armada_38x_mpp_modes;
soc->nmodes = armada_38x_mpp_controls[0].npins;
pdev->dev.platform_data = soc;
return mvebu_pinctrl_simple_mmio_probe(pdev);
}
