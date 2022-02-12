void __init bcm2835_init_clocks(void)
{
struct clk *clk;
int ret;
clk = clk_register_fixed_rate(NULL, "apb_pclk", NULL, CLK_IS_ROOT,
126000000);
if (IS_ERR(clk))
pr_err("apb_pclk not registered\n");
clk = clk_register_fixed_rate(NULL, "uart0_pclk", NULL, CLK_IS_ROOT,
3000000);
if (IS_ERR(clk))
pr_err("uart0_pclk not registered\n");
ret = clk_register_clkdev(clk, NULL, "20201000.uart");
if (ret)
pr_err("uart0_pclk alias not registered\n");
clk = clk_register_fixed_rate(NULL, "uart1_pclk", NULL, CLK_IS_ROOT,
125000000);
if (IS_ERR(clk))
pr_err("uart1_pclk not registered\n");
ret = clk_register_clkdev(clk, NULL, "20215000.uart");
if (ret)
pr_err("uart1_pclk alias not registered\n");
}
