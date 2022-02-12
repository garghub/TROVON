static int msm8994_pinctrl_probe(struct platform_device *pdev)
{
return msm_pinctrl_probe(pdev, &msm8994_pinctrl);
}
static int __init msm8994_pinctrl_init(void)
{
return platform_driver_register(&msm8994_pinctrl_driver);
}
static void __exit msm8994_pinctrl_exit(void)
{
platform_driver_unregister(&msm8994_pinctrl_driver);
}
