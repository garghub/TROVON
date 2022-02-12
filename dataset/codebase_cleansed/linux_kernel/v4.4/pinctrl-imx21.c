static int __init imx21_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn imx1_pinctrl_core_probe(pdev, &imx21_pinctrl_info);\r\n}
