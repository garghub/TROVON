void __init pxa910_clk_init(void)\r\n{\r\nclkdev_add_table(ARRAY_AND_SIZE(pxa910_clkregs));\r\n}
