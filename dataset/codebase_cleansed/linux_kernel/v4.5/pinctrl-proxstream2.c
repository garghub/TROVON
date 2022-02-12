static int proxstream2_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn uniphier_pinctrl_probe(pdev, &proxstream2_pinctrl_desc,\r\n&proxstream2_pindata);\r\n}
