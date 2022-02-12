static int dnv_pinctrl_probe(struct platform_device *pdev)
{
return intel_pinctrl_probe(pdev, &dnv_soc_data);
}
static int __init dnv_pinctrl_init(void)
{
return platform_driver_register(&dnv_pinctrl_driver);
}
static void __exit dnv_pinctrl_exit(void)
{
platform_driver_unregister(&dnv_pinctrl_driver);
}
