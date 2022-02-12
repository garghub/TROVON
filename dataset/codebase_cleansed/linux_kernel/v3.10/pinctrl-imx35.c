static int imx35_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx35_pinctrl_info);
}
static int __init imx35_pinctrl_init(void)
{
return platform_driver_register(&imx35_pinctrl_driver);
}
static void __exit imx35_pinctrl_exit(void)
{
platform_driver_unregister(&imx35_pinctrl_driver);
}
