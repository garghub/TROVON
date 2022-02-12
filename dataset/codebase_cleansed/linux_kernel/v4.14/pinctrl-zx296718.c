static int zx296718_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn zx_pinctrl_init(pdev, &zx296718_pinctrl_info);\r\n}
