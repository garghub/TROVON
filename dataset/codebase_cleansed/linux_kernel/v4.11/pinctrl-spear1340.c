static void gpio_request_endisable(struct spear_pmx *pmx, int pin,
bool enable)
{
unsigned int regoffset, regindex, bitoffset;
unsigned int val;
pin++;
regindex = pin / 32;
bitoffset = pin % 32;
if (regindex <= 3)
regoffset = PAD_FUNCTION_EN_1 + regindex * sizeof(int *);
else
regoffset = PAD_FUNCTION_EN_5 + (regindex - 4) * sizeof(int *);
val = pmx_readl(pmx, regoffset);
if (enable)
val &= ~(0x1 << bitoffset);
else
val |= 0x1 << bitoffset;
pmx_writel(pmx, val, regoffset);
}
static int spear1340_pinctrl_probe(struct platform_device *pdev)
{
return spear_pinctrl_probe(pdev, &spear1340_machdata);
}
static int __init spear1340_pinctrl_init(void)
{
return platform_driver_register(&spear1340_pinctrl_driver);
}
