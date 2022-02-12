static int mmcc_apq8084_probe(struct platform_device *pdev)
{
int ret;
struct regmap *regmap;
ret = qcom_cc_probe(pdev, &mmcc_apq8084_desc);
if (ret)
return ret;
regmap = dev_get_regmap(&pdev->dev, NULL);
clk_pll_configure_sr_hpm_lp(&mmpll1, regmap, &mmpll1_config, true);
clk_pll_configure_sr_hpm_lp(&mmpll3, regmap, &mmpll3_config, false);
return 0;
}
static int mmcc_apq8084_remove(struct platform_device *pdev)
{
qcom_cc_remove(pdev);
return 0;
}
