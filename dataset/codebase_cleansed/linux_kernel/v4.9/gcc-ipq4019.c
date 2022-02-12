static int gcc_ipq4019_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
clk_register_fixed_rate(dev, "fepll125", "xo", 0, 200000000);
clk_register_fixed_rate(dev, "fepll125dly", "xo", 0, 200000000);
clk_register_fixed_rate(dev, "fepllwcss2g", "xo", 0, 200000000);
clk_register_fixed_rate(dev, "fepllwcss5g", "xo", 0, 200000000);
clk_register_fixed_rate(dev, "fepll200", "xo", 0, 200000000);
clk_register_fixed_rate(dev, "fepll500", "xo", 0, 200000000);
clk_register_fixed_rate(dev, "ddrpllapss", "xo", 0, 666000000);
return qcom_cc_probe(pdev, &gcc_ipq4019_desc);
}
static int __init gcc_ipq4019_init(void)
{
return platform_driver_register(&gcc_ipq4019_driver);
}
static void __exit gcc_ipq4019_exit(void)
{
platform_driver_unregister(&gcc_ipq4019_driver);
}
