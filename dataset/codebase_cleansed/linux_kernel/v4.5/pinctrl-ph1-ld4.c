static int ph1_ld4_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn uniphier_pinctrl_probe(pdev, &ph1_ld4_pinctrl_desc,\r\n&ph1_ld4_pindata);\r\n}
