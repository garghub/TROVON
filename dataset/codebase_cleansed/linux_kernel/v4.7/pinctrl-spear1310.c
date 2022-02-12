static int spear1310_pinctrl_probe(struct platform_device *pdev)
{
return spear_pinctrl_probe(pdev, &spear1310_machdata);
}
static int __init spear1310_pinctrl_init(void)
{
return platform_driver_register(&spear1310_pinctrl_driver);
}
static void __exit spear1310_pinctrl_exit(void)
{
platform_driver_unregister(&spear1310_pinctrl_driver);
}
