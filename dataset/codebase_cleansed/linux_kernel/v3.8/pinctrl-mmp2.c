static int mmp2_pinmux_probe(struct platform_device *pdev)
{
return pxa3xx_pinctrl_register(pdev, &mmp2_info);
}
static int mmp2_pinmux_remove(struct platform_device *pdev)
{
return pxa3xx_pinctrl_unregister(pdev);
}
static int __init mmp2_pinmux_init(void)
{
return platform_driver_register(&mmp2_pinmux_driver);
}
static void __exit mmp2_pinmux_exit(void)
{
platform_driver_unregister(&mmp2_pinmux_driver);
}
