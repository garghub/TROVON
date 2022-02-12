static int sun6i_a31_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn sunxi_pinctrl_init(pdev,\r\n&sun6i_a31_pinctrl_data);\r\n}
