static int mmcc_msm8996_probe(struct platform_device *pdev)
{
struct clk *clk;
struct device *dev = &pdev->dev;
int i;
struct regmap *regmap;
regmap = qcom_cc_map(pdev, &mmcc_msm8996_desc);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
regmap_update_bits(regmap, 0x50d8, BIT(31), 0);
regmap_update_bits(regmap, 0x5054, BIT(15), 0);
for (i = 0; i < ARRAY_SIZE(mmcc_msm8996_hws); i++) {
clk = devm_clk_register(dev, mmcc_msm8996_hws[i]);
if (IS_ERR(clk))
return PTR_ERR(clk);
}
return qcom_cc_really_probe(pdev, &mmcc_msm8996_desc, regmap);
}
