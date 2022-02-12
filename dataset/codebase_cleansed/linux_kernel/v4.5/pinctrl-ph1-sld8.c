static int ph1_sld8_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn uniphier_pinctrl_probe(pdev, &ph1_sld8_pinctrl_desc,\r\n&ph1_sld8_pindata);\r\n}
