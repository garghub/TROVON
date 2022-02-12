static int mdm9615_pinctrl_probe(struct platform_device *pdev)
{
return msm_pinctrl_probe(pdev, &mdm9615_pinctrl);
}
static int __init mdm9615_pinctrl_init(void)
{
return platform_driver_register(&mdm9615_pinctrl_driver);
}
static void __exit mdm9615_pinctrl_exit(void)
{
platform_driver_unregister(&mdm9615_pinctrl_driver);
}
