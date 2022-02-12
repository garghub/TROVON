static int ipq8064_pinctrl_probe(struct platform_device *pdev)
{
return msm_pinctrl_probe(pdev, &ipq8064_pinctrl);
}
static int __init ipq8064_pinctrl_init(void)
{
return platform_driver_register(&ipq8064_pinctrl_driver);
}
static void __exit ipq8064_pinctrl_exit(void)
{
platform_driver_unregister(&ipq8064_pinctrl_driver);
}
