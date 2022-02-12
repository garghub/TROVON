void __init integrator_clk_init(bool is_cp)
{
struct clk *clk;
clk = clk_register_fixed_rate(NULL, "apb_pclk", NULL, CLK_IS_ROOT, 0);
clk_register_clkdev(clk, "apb_pclk", NULL);
clk = clk_register_fixed_rate(NULL, "uartclk", NULL, CLK_IS_ROOT,
14745600);
clk_register_clkdev(clk, NULL, "uart0");
clk_register_clkdev(clk, NULL, "uart1");
if (is_cp)
clk_register_clkdev(clk, NULL, "mmci");
clk = clk_register_fixed_rate(NULL, "clk24mhz", NULL, CLK_IS_ROOT,
24000000);
clk_register_clkdev(clk, NULL, "kmi0");
clk_register_clkdev(clk, NULL, "kmi1");
if (!is_cp)
clk_register_clkdev(clk, NULL, "ap_timer");
if (!is_cp)
return;
clk = clk_register_fixed_rate(NULL, "clk1mhz", NULL, CLK_IS_ROOT,
1000000);
clk_register_clkdev(clk, NULL, "sp804");
clk = icst_clk_register(NULL, &cp_icst_desc,
__io_address(INTEGRATOR_HDR_BASE));
clk_register_clkdev(clk, NULL, "clcd");
}
