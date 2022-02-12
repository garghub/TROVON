static int sun8i_h3_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn sunxi_pinctrl_init(pdev,\r\n&sun8i_h3_pinctrl_data);\r\n}
