static int vf610_pinctrl_probe(struct platform_device *pdev)
{
return imx_pinctrl_probe(pdev, &vf610_pinctrl_info);
}
static int __init vf610_pinctrl_init(void)
{
return platform_driver_register(&vf610_pinctrl_driver);
}
