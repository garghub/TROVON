static int __devinit imx28_pinctrl_probe(struct platform_device *pdev)
{
return mxs_pinctrl_probe(pdev, &imx28_pinctrl_data);
}
static int __init imx28_pinctrl_init(void)
{
return platform_driver_register(&imx28_pinctrl_driver);
}
static void __exit imx28_pinctrl_exit(void)
{
platform_driver_unregister(&imx28_pinctrl_driver);
}
