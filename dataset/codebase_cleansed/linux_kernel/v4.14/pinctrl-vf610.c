static int vf610_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset, bool input)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
u32 reg;
pin_reg = &info->pin_regs[offset];
if (pin_reg->mux_reg == -1)
return -EINVAL;
reg = readl(ipctl->base + pin_reg->mux_reg);
if (input)
reg &= ~0x2;
else
reg |= 0x2;
writel(reg, ipctl->base + pin_reg->mux_reg);
return 0;
}
static int vf610_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &vf610_pinctrl_info);
}
static int __init vf610_pinctrl_init(void)
{
return platform_driver_register(&vf610_pinctrl_driver);
}
