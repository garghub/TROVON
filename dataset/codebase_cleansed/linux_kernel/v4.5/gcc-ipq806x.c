static int gcc_ipq806x_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct regmap *regmap;
int ret;
ret = qcom_cc_register_board_clk(dev, "cxo_board", "cxo", 19200000);
if (ret)
return ret;
ret = qcom_cc_register_board_clk(dev, "pxo_board", "pxo", 27000000);
if (ret)
return ret;
ret = qcom_cc_probe(pdev, &gcc_ipq806x_desc);
if (ret)
return ret;
regmap = dev_get_regmap(dev, NULL);
if (!regmap)
return -ENODEV;
regmap_update_bits(regmap, 0x31a4, 0xffffffc0, 0x40000400);
regmap_write(regmap, 0x31b0, 0x3080);
regmap_write(regmap, 0x3cb8, 8);
regmap_write(regmap, 0x3cd8, 8);
regmap_write(regmap, 0x3cf8, 8);
regmap_write(regmap, 0x3d18, 8);
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
