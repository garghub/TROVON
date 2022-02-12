static int ph1_pro5_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn uniphier_pinctrl_probe(pdev, &ph1_pro5_pinctrl_desc,\r\n&ph1_pro5_pindata);\r\n}
