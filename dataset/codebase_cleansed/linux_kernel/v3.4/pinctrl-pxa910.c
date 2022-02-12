static int __devinit pxa910_pinmux_probe(struct platform_device *pdev)
{
return pxa3xx_pinctrl_register(pdev, &pxa910_info);
}
static int __devexit pxa910_pinmux_remove(struct platform_device *pdev)
{
return pxa3xx_pinctrl_unregister(pdev);
}
static int __init pxa910_pinmux_init(void)
{
return platform_driver_register(&pxa910_pinmux_driver);
}
static void __exit pxa910_pinmux_exit(void)
{
platform_driver_unregister(&pxa910_pinmux_driver);
}
