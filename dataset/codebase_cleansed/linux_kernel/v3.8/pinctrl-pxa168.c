static int pxa168_pinmux_probe(struct platform_device *pdev)
{
return pxa3xx_pinctrl_register(pdev, &pxa168_info);
}
static int pxa168_pinmux_remove(struct platform_device *pdev)
{
return pxa3xx_pinctrl_unregister(pdev);
}
static int __init pxa168_pinmux_init(void)
{
return platform_driver_register(&pxa168_pinmux_driver);
}
static void __exit pxa168_pinmux_exit(void)
{
platform_driver_unregister(&pxa168_pinmux_driver);
}
