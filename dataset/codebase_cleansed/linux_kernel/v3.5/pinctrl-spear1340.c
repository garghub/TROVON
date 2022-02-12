static int __devinit spear1340_pinctrl_probe(struct platform_device *pdev)
{
return spear_pinctrl_probe(pdev, &spear1340_machdata);
}
static int __devexit spear1340_pinctrl_remove(struct platform_device *pdev)
{
return spear_pinctrl_remove(pdev);
}
static int __init spear1340_pinctrl_init(void)
{
return platform_driver_register(&spear1340_pinctrl_driver);
}
static void __exit spear1340_pinctrl_exit(void)
{
platform_driver_unregister(&spear1340_pinctrl_driver);
}
