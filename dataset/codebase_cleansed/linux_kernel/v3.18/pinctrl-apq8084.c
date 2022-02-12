static int apq8084_pinctrl_probe(struct platform_device *pdev)
{
return msm_pinctrl_probe(pdev, &apq8084_pinctrl);
}
static int __init apq8084_pinctrl_init(void)
{
return platform_driver_register(&apq8084_pinctrl_driver);
}
static void __exit apq8084_pinctrl_exit(void)
{
platform_driver_unregister(&apq8084_pinctrl_driver);
}
