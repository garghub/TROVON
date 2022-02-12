static int __devinit armada_xp_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_xp_pinctrl_info;
const struct of_device_id *match =
of_match_device(armada_xp_pinctrl_of_match, &pdev->dev);
if (!match)
return -ENODEV;
soc->variant = (unsigned) match->data & 0xff;
switch (soc->variant) {
case V_MV78230:
soc->controls = mv78230_mpp_controls;
soc->ncontrols = ARRAY_SIZE(mv78230_mpp_controls);
soc->modes = armada_xp_mpp_modes;
soc->nmodes = mv78230_mpp_controls[0].npins;
soc->gpioranges = mv78230_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(mv78230_mpp_gpio_ranges);
break;
case V_MV78260:
soc->controls = mv78260_mpp_controls;
soc->ncontrols = ARRAY_SIZE(mv78260_mpp_controls);
soc->modes = armada_xp_mpp_modes;
soc->nmodes = mv78260_mpp_controls[0].npins;
soc->gpioranges = mv78260_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(mv78260_mpp_gpio_ranges);
break;
case V_MV78460:
soc->controls = mv78460_mpp_controls;
soc->ncontrols = ARRAY_SIZE(mv78460_mpp_controls);
soc->modes = armada_xp_mpp_modes;
soc->nmodes = mv78460_mpp_controls[0].npins;
soc->gpioranges = mv78460_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(mv78460_mpp_gpio_ranges);
break;
}
pdev->dev.platform_data = soc;
return mvebu_pinctrl_probe(pdev);
}
static int __devexit armada_xp_pinctrl_remove(struct platform_device *pdev)
{
return mvebu_pinctrl_remove(pdev);
}
