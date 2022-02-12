static int sun4i_a10_pinctrl_probe(struct platform_device *pdev)\r\n{\r\nreturn sunxi_pinctrl_init(pdev,\r\n&sun4i_a10_pinctrl_data);\r\n}
