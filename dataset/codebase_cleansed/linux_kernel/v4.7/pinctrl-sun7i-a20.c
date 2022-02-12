static int sun7i_a20_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn sunxi_pinctrl_init(pdev,\r\n&sun7i_a20_pinctrl_data);\r\n}
