static int gcc_msm8960_probe(struct platform_device *pdev)
{
struct clk *clk;
struct device *dev = &pdev->dev;
const struct of_device_id *match;
match = of_match_device(gcc_msm8960_match_table, &pdev->dev);
if (!match)
return -EINVAL;
clk = clk_register_fixed_rate(dev, "cxo", NULL, CLK_IS_ROOT, 19200000);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk = clk_register_fixed_rate(dev, "pxo", NULL, CLK_IS_ROOT, 27000000);
if (IS_ERR(clk))
return PTR_ERR(clk);
return qcom_cc_probe(pdev, match->data);
}
static int gcc_msm8960_remove(struct platform_device *pdev)
{
qcom_cc_remove(pdev);
return 0;
}
static int __init gcc_msm8960_init(void)
{
return platform_driver_register(&gcc_msm8960_driver);
}
static void __exit gcc_msm8960_exit(void)
{
platform_driver_unregister(&gcc_msm8960_driver);
}
