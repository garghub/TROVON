static int imx25_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx25_pinctrl_info);
}
static int __init imx25_pinctrl_init(void)
{
return platform_driver_register(&imx25_pinctrl_driver);
}
static void __exit imx25_pinctrl_exit(void)
{
platform_driver_unregister(&imx25_pinctrl_driver);
}
