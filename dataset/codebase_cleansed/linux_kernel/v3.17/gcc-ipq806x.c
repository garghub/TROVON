static int gcc_ipq806x_probe(struct platform_device *pdev)
{
struct clk *clk;
struct device *dev = &pdev->dev;
clk = clk_register_fixed_rate(dev, "cxo", NULL, CLK_IS_ROOT, 25000000);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk = clk_register_fixed_rate(dev, "pxo", NULL, CLK_IS_ROOT, 25000000);
if (IS_ERR(clk))
return PTR_ERR(clk);
return qcom_cc_probe(pdev, &gcc_ipq806x_desc);
}
static int gcc_ipq806x_remove(struct platform_device *pdev)
{
qcom_cc_remove(pdev);
return 0;
}
static int __init gcc_ipq806x_init(void)
{
return platform_driver_register(&gcc_ipq806x_driver);
}
static void __exit gcc_ipq806x_exit(void)
{
platform_driver_unregister(&gcc_ipq806x_driver);
}
