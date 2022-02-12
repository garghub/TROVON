void __init nomadik_clk_init(void)
{
struct clk *clk;
clk = clk_register_fixed_rate(NULL, "apb_pclk", NULL, CLK_IS_ROOT, 0);
clk_register_clkdev(clk, "apb_pclk", NULL);
clk_register_clkdev(clk, NULL, "gpio.0");
clk_register_clkdev(clk, NULL, "gpio.1");
clk_register_clkdev(clk, NULL, "gpio.2");
clk_register_clkdev(clk, NULL, "gpio.3");
clk_register_clkdev(clk, NULL, "rng");
clk_register_clkdev(clk, NULL, "fsmc-nand");
clk = clk_register_fixed_rate(NULL, "TIMCLK", NULL, CLK_IS_ROOT,
2400000);
clk_register_clkdev(clk, NULL, "mtu0");
clk_register_clkdev(clk, NULL, "mtu1");
clk = clk_register_fixed_rate(NULL, "CLK48", NULL, CLK_IS_ROOT,
48000000);
clk_register_clkdev(clk, NULL, "uart0");
clk_register_clkdev(clk, NULL, "uart1");
clk_register_clkdev(clk, NULL, "mmci");
clk_register_clkdev(clk, NULL, "ssp");
clk_register_clkdev(clk, NULL, "nmk-i2c.0");
clk_register_clkdev(clk, NULL, "nmk-i2c.1");
}
