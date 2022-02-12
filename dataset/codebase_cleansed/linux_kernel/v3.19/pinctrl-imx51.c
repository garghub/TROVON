static int imx51_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx51_pinctrl_info);
}
static int __init imx51_pinctrl_init(void)
{
return platform_driver_register(&imx51_pinctrl_driver);
}
static void __exit imx51_pinctrl_exit(void)
{
platform_driver_unregister(&imx51_pinctrl_driver);
}
