static int gcc_msm8916_probe(struct platform_device *pdev)
{
int ret;
struct device *dev = &pdev->dev;
ret = qcom_cc_register_board_clk(dev, "xo_board", "xo", 19200000);
if (ret)
return ret;
ret = qcom_cc_register_sleep_clk(dev);
if (ret)
return ret;
return qcom_cc_probe(pdev, &gcc_msm8916_desc);
}
static int __init gcc_msm8916_init(void)
{
return platform_driver_register(&gcc_msm8916_driver);
}
static void __exit gcc_msm8916_exit(void)
{
platform_driver_unregister(&gcc_msm8916_driver);
}
