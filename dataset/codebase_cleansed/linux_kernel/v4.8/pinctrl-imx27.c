static int imx27_pinctrl_probe(struct platform_device *pdev)
{
return imx1_pinctrl_core_probe(pdev, &imx27_pinctrl_info);
}
static int __init imx27_pinctrl_init(void)
{
return platform_driver_register(&imx27_pinctrl_driver);
}
