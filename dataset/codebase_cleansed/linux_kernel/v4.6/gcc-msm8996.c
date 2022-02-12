static int gcc_msm8996_probe(struct platform_device *pdev)
{
struct clk *clk;
struct device *dev = &pdev->dev;
int i;
struct regmap *regmap;
regmap = qcom_cc_map(pdev, &gcc_msm8996_desc);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
regmap_update_bits(regmap, 0x52008, BIT(21), BIT(21));
for (i = 0; i < ARRAY_SIZE(gcc_msm8996_hws); i++) {
clk = devm_clk_register(dev, gcc_msm8996_hws[i]);
if (IS_ERR(clk))
return PTR_ERR(clk);
}
return qcom_cc_really_probe(pdev, &gcc_msm8996_desc, regmap);
}
static int __init gcc_msm8996_init(void)
{
return platform_driver_register(&gcc_msm8996_driver);
}
static void __exit gcc_msm8996_exit(void)
{
platform_driver_unregister(&gcc_msm8996_driver);
}
