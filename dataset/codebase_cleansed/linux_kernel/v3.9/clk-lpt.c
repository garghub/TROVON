static int lpt_clk_probe(struct platform_device *pdev)
{
struct clk *clk;
clk = clk_register_fixed_rate(&pdev->dev, "lpss_clk", NULL, CLK_IS_ROOT,
100000000);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk_register_clkdev(clk, "hclk", "INTL9C60.0.auto");
clk = clk_register_lpss_gate("spi0_clk", "lpss_clk", "INT33C0", NULL,
PRV_CLOCK_PARAMS);
if (!IS_ERR(clk))
clk_register_clkdev(clk, NULL, "INT33C0:00");
clk = clk_register_lpss_gate("spi1_clk", "lpss_clk", "INT33C1", NULL,
PRV_CLOCK_PARAMS);
if (!IS_ERR(clk))
clk_register_clkdev(clk, NULL, "INT33C1:00");
clk = clk_register_lpss_gate("i2c0_clk", "lpss_clk", "INT33C2", NULL,
PRV_CLOCK_PARAMS);
if (!IS_ERR(clk))
clk_register_clkdev(clk, NULL, "INT33C2:00");
clk = clk_register_lpss_gate("i2c1_clk", "lpss_clk", "INT33C3", NULL,
PRV_CLOCK_PARAMS);
if (!IS_ERR(clk))
clk_register_clkdev(clk, NULL, "INT33C3:00");
clk = clk_register_lpss_gate("uart0_clk", "lpss_clk", "INT33C4", NULL,
PRV_CLOCK_PARAMS);
if (!IS_ERR(clk))
clk_register_clkdev(clk, NULL, "INT33C4:00");
clk = clk_register_lpss_gate("uart1_clk", "lpss_clk", "INT33C5", NULL,
PRV_CLOCK_PARAMS);
if (!IS_ERR(clk))
clk_register_clkdev(clk, NULL, "INT33C5:00");
return 0;
}
static int __init lpt_clk_init(void)
{
return platform_driver_register(&lpt_clk_driver);
}
