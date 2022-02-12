static int gcc_apq8084_probe(struct platform_device *pdev)
{
struct clk *clk;
struct device *dev = &pdev->dev;
clk = clk_register_fixed_rate(dev, "xo", NULL, CLK_IS_ROOT, 19200000);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk = clk_register_fixed_rate(dev, "sleep_clk_src", NULL,
CLK_IS_ROOT, 32768);
if (IS_ERR(clk))
return PTR_ERR(clk);
return qcom_cc_probe(pdev, &gcc_apq8084_desc);
}
static int __init gcc_apq8084_init(void)
{
return platform_driver_register(&gcc_apq8084_driver);
}
static void __exit gcc_apq8084_exit(void)
{
platform_driver_unregister(&gcc_apq8084_driver);
}
