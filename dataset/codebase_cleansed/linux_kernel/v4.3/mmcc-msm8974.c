static int mmcc_msm8974_probe(struct platform_device *pdev)
{
struct regmap *regmap;
regmap = qcom_cc_map(pdev, &mmcc_msm8974_desc);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
clk_pll_configure_sr_hpm_lp(&mmpll1, regmap, &mmpll1_config, true);
clk_pll_configure_sr_hpm_lp(&mmpll3, regmap, &mmpll3_config, false);
return qcom_cc_really_probe(pdev, &mmcc_msm8974_desc, regmap);
}
static int mmcc_msm8974_remove(struct platform_device *pdev)
{
qcom_cc_remove(pdev);
return 0;
}
