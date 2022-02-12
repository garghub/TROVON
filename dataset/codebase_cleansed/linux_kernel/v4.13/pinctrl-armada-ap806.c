static int armada_ap806_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_ap806_pinctrl_info;
const struct of_device_id *match =
of_match_device(armada_ap806_pinctrl_of_match, &pdev->dev);
if (!match || !pdev->dev.parent)
return -ENODEV;
soc->variant = 0;
soc->controls = armada_ap806_mpp_controls;
soc->ncontrols = ARRAY_SIZE(armada_ap806_mpp_controls);
soc->gpioranges = armada_ap806_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(armada_ap806_mpp_gpio_ranges);
soc->modes = armada_ap806_mpp_modes;
soc->nmodes = armada_ap806_mpp_controls[0].npins;
pdev->dev.platform_data = soc;
return mvebu_pinctrl_simple_regmap_probe(pdev, pdev->dev.parent, 0);
}
