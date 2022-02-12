static int htcherald_panel_probe(struct platform_device *pdev)\r\n{\r\nomapfb_register_panel(&htcherald_panel_1);\r\nreturn 0;\r\n}
