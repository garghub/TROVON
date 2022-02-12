static int imx6sx_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx6sx_pinctrl_info);
}
static int __init imx6sx_pinctrl_init(void)
{
return platform_driver_register(&imx6sx_pinctrl_driver);
}
