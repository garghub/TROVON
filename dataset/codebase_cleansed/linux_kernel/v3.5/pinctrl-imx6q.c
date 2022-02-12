static int __devinit imx6q_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &imx6q_pinctrl_info);
}
static int __init imx6q_pinctrl_init(void)
{
return platform_driver_register(&imx6q_pinctrl_driver);
}
static void __exit imx6q_pinctrl_exit(void)
{
platform_driver_unregister(&imx6q_pinctrl_driver);
}
