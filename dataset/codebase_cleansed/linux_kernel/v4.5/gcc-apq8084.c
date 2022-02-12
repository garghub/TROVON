static int gcc_apq8084_probe(struct platform_device *pdev)
{
int ret;
struct device *dev = &pdev->dev;
ret = qcom_cc_register_board_clk(dev, "xo_board", "xo", 19200000);
if (ret)
return ret;
ret = qcom_cc_register_sleep_clk(dev);
if (ret)
return ret;
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
