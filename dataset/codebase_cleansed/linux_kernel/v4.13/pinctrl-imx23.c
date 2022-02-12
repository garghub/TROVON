static int imx23_pinctrl_probe(struct platform_device *pdev)
{
return mxs_pinctrl_probe(pdev, &imx23_pinctrl_data);
}
static int __init imx23_pinctrl_init(void)
{
return platform_driver_register(&imx23_pinctrl_driver);
}
