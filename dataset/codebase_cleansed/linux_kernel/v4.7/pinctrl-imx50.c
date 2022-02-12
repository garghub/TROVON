static int imx50_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx50_pinctrl_info);
}
static int __init imx50_pinctrl_init(void)
{
return platform_driver_register(&imx50_pinctrl_driver);
}
static void __exit imx50_pinctrl_exit(void)
{
platform_driver_unregister(&imx50_pinctrl_driver);
}
