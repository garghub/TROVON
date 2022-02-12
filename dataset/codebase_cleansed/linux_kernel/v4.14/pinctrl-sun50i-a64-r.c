static int sun50i_a64_r_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn sunxi_pinctrl_init(pdev,\r\n&sun50i_a64_r_pinctrl_data);\r\n}
