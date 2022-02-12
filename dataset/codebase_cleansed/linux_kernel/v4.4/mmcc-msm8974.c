static int mmcc_msm8974_probe(struct platform_device *pdev)
{
struct regmap *regmap;
int ret;
regmap = qcom_cc_map(pdev, &mmcc_msm8974_desc);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
clk_pll_configure_sr_hpm_lp(&mmpll1, regmap, &mmpll1_config, true);
clk_pll_configure_sr_hpm_lp(&mmpll3, regmap, &mmpll3_config, false);
ret = qcom_cc_really_probe(pdev, &mmcc_msm8974_desc, regmap);
if (ret)
return ret;
return pm_genpd_add_subdomain(&oxili_gdsc.pd, &oxilicx_gdsc.pd);
}
static int mmcc_msm8974_remove(struct platform_device *pdev)
{
pm_genpd_remove_subdomain(&oxili_gdsc.pd, &oxilicx_gdsc.pd);
return 0;
}
