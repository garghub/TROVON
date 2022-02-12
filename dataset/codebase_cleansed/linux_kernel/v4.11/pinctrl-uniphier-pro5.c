static int uniphier_pro5_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn uniphier_pinctrl_probe(pdev, &uniphier_pro5_pindata);\r\n}
