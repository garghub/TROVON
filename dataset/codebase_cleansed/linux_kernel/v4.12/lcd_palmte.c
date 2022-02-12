static int palmte_panel_probe(struct platform_device *pdev)\r\n{\r\nomapfb_register_panel(&palmte_panel);\r\nreturn 0;\r\n}
