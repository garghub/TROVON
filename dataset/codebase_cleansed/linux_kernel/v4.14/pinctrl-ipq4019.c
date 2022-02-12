static int ipq4019_pinctrl_probe(struct platform_device *pdev)
{
return msm_pinctrl_probe(pdev, &ipq4019_pinctrl);
}
static int __init ipq4019_pinctrl_init(void)
{
return platform_driver_register(&ipq4019_pinctrl_driver);
}
static void __exit ipq4019_pinctrl_exit(void)
{
platform_driver_unregister(&ipq4019_pinctrl_driver);
}
