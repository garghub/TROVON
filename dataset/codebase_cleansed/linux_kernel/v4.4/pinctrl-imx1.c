static int __init imx1_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn imx1_pinctrl_core_probe(pdev, &imx1_pinctrl_info);\r\n}
