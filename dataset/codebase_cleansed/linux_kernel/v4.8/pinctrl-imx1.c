static int __init imx1_pinctrl_probe(struct platform_device *pdev)
{
return imx1_pinctrl_core_probe(pdev, &imx1_pinctrl_info);
}
