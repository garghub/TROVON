static int sun9i_a80_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn sunxi_pinctrl_init(pdev,\r\n&sun9i_a80_pinctrl_data);\r\n}
