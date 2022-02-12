static int gcc_msm8660_probe(struct platform_device *pdev)
{
struct clk *clk;
struct device *dev = &pdev->dev;
clk = clk_register_fixed_rate(dev, "cxo", NULL, CLK_IS_ROOT, 19200000);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk = clk_register_fixed_rate(dev, "pxo", NULL, CLK_IS_ROOT, 27000000);
if (IS_ERR(clk))
return PTR_ERR(clk);
return qcom_cc_probe(pdev, &gcc_msm8660_desc);
}
static int __init gcc_msm8660_init(void)
{
return platform_driver_register(&gcc_msm8660_driver);
}
static void __exit gcc_msm8660_exit(void)
{
platform_driver_unregister(&gcc_msm8660_driver);
}
