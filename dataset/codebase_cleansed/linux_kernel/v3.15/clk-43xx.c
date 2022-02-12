int __init am43xx_dt_clk_init(void)\r\n{\r\nti_dt_clocks_register(am43xx_clks);\r\nomap2_clk_disable_autoidle_all();\r\nreturn 0;\r\n}
