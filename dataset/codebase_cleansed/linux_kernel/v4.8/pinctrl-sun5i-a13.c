static int sun5i_a13_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn sunxi_pinctrl_init(pdev,\r\n&sun5i_a13_pinctrl_data);\r\n}
