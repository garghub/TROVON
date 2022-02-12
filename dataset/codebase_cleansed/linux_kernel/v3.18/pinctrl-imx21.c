static int __init imx21_pinctrl_probe(struct platform_device *pdev)
{
return imx1_pinctrl_core_probe(pdev, &imx21_pinctrl_info);
}
