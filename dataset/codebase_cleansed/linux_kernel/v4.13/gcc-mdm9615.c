static int gcc_mdm9615_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct regmap *regmap;
int ret;
int i;
regmap = qcom_cc_map(pdev, &gcc_mdm9615_desc);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
for (i = 0; i < ARRAY_SIZE(gcc_mdm9615_hws); i++) {
ret = devm_clk_hw_register(dev, gcc_mdm9615_hws[i]);
if (ret)
return ret;
}
return qcom_cc_really_probe(pdev, &gcc_mdm9615_desc, regmap);
}
static int __init gcc_mdm9615_init(void)
{
return platform_driver_register(&gcc_mdm9615_driver);
}
static void __exit gcc_mdm9615_exit(void)
{
platform_driver_unregister(&gcc_mdm9615_driver);
}
