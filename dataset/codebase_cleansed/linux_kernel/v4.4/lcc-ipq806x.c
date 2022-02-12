static int lcc_ipq806x_probe(struct platform_device *pdev)
{
u32 val;
struct regmap *regmap;
regmap = qcom_cc_map(pdev, &lcc_ipq806x_desc);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
val = regmap_read(regmap, 0x0, &val);
if (!val)
clk_pll_configure_sr(&pll4, regmap, &pll4_config, true);
regmap_write(regmap, 0xc4, 0x1);
return qcom_cc_really_probe(pdev, &lcc_ipq806x_desc, regmap);
}
