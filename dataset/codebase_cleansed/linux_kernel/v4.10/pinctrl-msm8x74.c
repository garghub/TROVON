static int msm8x74_pinctrl_probe(struct platform_device *pdev)
{
return msm_pinctrl_probe(pdev, &msm8x74_pinctrl);
}
static int __init msm8x74_pinctrl_init(void)
{
return platform_driver_register(&msm8x74_pinctrl_driver);
}
static void __exit msm8x74_pinctrl_exit(void)
{
platform_driver_unregister(&msm8x74_pinctrl_driver);
}
