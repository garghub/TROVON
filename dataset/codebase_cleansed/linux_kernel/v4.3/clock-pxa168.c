void __init pxa168_clk_init(void)\r\n{\r\nclkdev_add_table(ARRAY_AND_SIZE(pxa168_clkregs));\r\n}
