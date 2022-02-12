static int armada_xp_pinctrl_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct mvebu_pinctrl_soc_info *soc =
platform_get_drvdata(pdev);
int i, nregs;
nregs = DIV_ROUND_UP(soc->nmodes, MVEBU_MPPS_PER_REG);
for (i = 0; i < nregs; i++)
mpp_saved_regs[i] = readl(soc->control_data[0].base + i * 4);
return 0;
}
static int armada_xp_pinctrl_resume(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc =
platform_get_drvdata(pdev);
int i, nregs;
nregs = DIV_ROUND_UP(soc->nmodes, MVEBU_MPPS_PER_REG);
for (i = 0; i < nregs; i++)
writel(mpp_saved_regs[i], soc->control_data[0].base + i * 4);
return 0;
}
static int armada_xp_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc = &armada_xp_pinctrl_info;
const struct of_device_id *match =
of_match_device(armada_xp_pinctrl_of_match, &pdev->dev);
int nregs;
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
case V_98DX3236:
case V_98DX3336:
case V_98DX4251:
soc->controls = mv98dx3236_mpp_controls;
soc->ncontrols = ARRAY_SIZE(mv98dx3236_mpp_controls);
soc->modes = mv98dx3236_mpp_modes;
soc->nmodes = mv98dx3236_mpp_controls[0].npins;
soc->gpioranges = mv98dx3236_mpp_gpio_ranges;
soc->ngpioranges = ARRAY_SIZE(mv98dx3236_mpp_gpio_ranges);
break;
}
nregs = DIV_ROUND_UP(soc->nmodes, MVEBU_MPPS_PER_REG);
mpp_saved_regs = devm_kmalloc(&pdev->dev, nregs * sizeof(u32),
GFP_KERNEL);
if (!mpp_saved_regs)
return -ENOMEM;
pdev->dev.platform_data = soc;
return mvebu_pinctrl_simple_mmio_probe(pdev);
}
