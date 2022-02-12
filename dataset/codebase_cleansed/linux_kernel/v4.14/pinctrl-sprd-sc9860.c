static int sprd_pinctrl_probe(struct platform_device *pdev)
{
return sprd_pinctrl_core_probe(pdev, sprd_sc9860_pins_info,
ARRAY_SIZE(sprd_sc9860_pins_info));
}
static int sprd_pinctrl_init(void)
{
return platform_driver_register(&sprd_pinctrl_driver);
}
static void sprd_pinctrl_exit(void)
{
platform_driver_unregister(&sprd_pinctrl_driver);
}
