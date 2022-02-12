static int gcc_msm8916_probe(struct platform_device *pdev)
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
return qcom_cc_probe(pdev, &gcc_msm8916_desc);
}
static int gcc_msm8916_remove(struct platform_device *pdev)
{
qcom_cc_remove(pdev);
return 0;
}
static int __init gcc_msm8916_init(void)
{
return platform_driver_register(&gcc_msm8916_driver);
}
static void __exit gcc_msm8916_exit(void)
{
platform_driver_unregister(&gcc_msm8916_driver);
}
