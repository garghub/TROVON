static int imx53_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx53_pinctrl_info);
}
static int __init imx53_pinctrl_init(void)
{
return platform_driver_register(&imx53_pinctrl_driver);
}
