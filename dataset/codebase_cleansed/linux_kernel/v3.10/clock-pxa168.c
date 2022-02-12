void __init pxa168_clk_init(void)
{
clkdev_add_table(ARRAY_AND_SIZE(pxa168_clkregs));
}
