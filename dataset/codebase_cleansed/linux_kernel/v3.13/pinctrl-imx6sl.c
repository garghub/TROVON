static int imx6sl_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx6sl_pinctrl_info);
}
static int __init imx6sl_pinctrl_init(void)
{
return platform_driver_register(&imx6sl_pinctrl_driver);
}
static void __exit imx6sl_pinctrl_exit(void)
{
platform_driver_unregister(&imx6sl_pinctrl_driver);
}
