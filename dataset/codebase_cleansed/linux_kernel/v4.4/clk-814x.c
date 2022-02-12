int __init dm814x_dt_clk_init(void)\r\n{\r\nti_dt_clocks_register(dm814_clks);\r\nomap2_clk_disable_autoidle_all();\r\nomap2_clk_enable_init_clocks(NULL, 0);\r\nreturn 0;\r\n}
