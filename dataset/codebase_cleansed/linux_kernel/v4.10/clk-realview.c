void __init realview_clk_init(void __iomem *sysbase, bool is_pb1176)
{
struct clk *clk;
clk = clk_register_fixed_rate(NULL, "apb_pclk", NULL, 0, 0);
clk_register_clkdev(clk, "apb_pclk", NULL);
clk = clk_register_fixed_rate(NULL, "clk24mhz", NULL, 0, 24000000);
clk_register_clkdev(clk, NULL, "dev:uart0");
clk_register_clkdev(clk, NULL, "dev:uart1");
clk_register_clkdev(clk, NULL, "dev:uart2");
clk_register_clkdev(clk, NULL, "fpga:kmi0");
clk_register_clkdev(clk, NULL, "fpga:kmi1");
clk_register_clkdev(clk, NULL, "fpga:mmc0");
clk_register_clkdev(clk, NULL, "dev:ssp0");
if (is_pb1176) {
clk_register_clkdev(clk, NULL, "dev:uart3");
clk_register_clkdev(clk, NULL, "dev:uart4");
} else
clk_register_clkdev(clk, NULL, "fpga:uart3");
clk = clk_register_fixed_rate(NULL, "clk1mhz", NULL, 0, 1000000);
clk_register_clkdev(clk, NULL, "sp804");
if (is_pb1176)
clk = icst_clk_register(NULL, &realview_osc0_desc,
"osc0", NULL, sysbase);
else
clk = icst_clk_register(NULL, &realview_osc4_desc,
"osc4", NULL, sysbase);
clk_register_clkdev(clk, NULL, "dev:clcd");
clk_register_clkdev(clk, NULL, "issp:clcd");
}
