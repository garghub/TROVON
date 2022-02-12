static int gcc_msm8994_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct clk *clk;
clk = devm_clk_register(dev, &xo.hw);
if (IS_ERR(clk))
return PTR_ERR(clk);
return qcom_cc_probe(pdev, &gcc_msm8994_desc);
}
static int __init gcc_msm8994_init(void)
{
return platform_driver_register(&gcc_msm8994_driver);
}
static void __exit gcc_msm8994_exit(void)
{
platform_driver_unregister(&gcc_msm8994_driver);
}
