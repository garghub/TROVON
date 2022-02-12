static int gcc_msm8660_probe(struct platform_device *pdev)
{
int ret;
struct device *dev = &pdev->dev;
ret = qcom_cc_register_board_clk(dev, "cxo_board", "cxo", 19200000);
if (ret)
return ret;
ret = qcom_cc_register_board_clk(dev, "pxo_board", "pxo", 27000000);
if (ret)
return ret;
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
