void __init pxa910_clk_init(void)
{
clkdev_add_table(ARRAY_AND_SIZE(pxa910_clkregs));
}
