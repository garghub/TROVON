static int hi6421_pmic_probe(struct platform_device *pdev)
{
struct hi6421_pmic *pmic;
struct resource *res;
void __iomem *base;
int ret;
pmic = devm_kzalloc(&pdev->dev, sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
pmic->regmap = devm_regmap_init_mmio_clk(&pdev->dev, NULL, base,
&hi6421_regmap_config);
if (IS_ERR(pmic->regmap)) {
dev_err(&pdev->dev,
"regmap init failed: %ld\n", PTR_ERR(pmic->regmap));
return PTR_ERR(pmic->regmap);
}
regmap_update_bits(pmic->regmap, HI6421_OCP_DEB_CTRL_REG,
(HI6421_OCP_DEB_SEL_MASK
| HI6421_OCP_EN_DEBOUNCE_MASK
| HI6421_OCP_AUTO_STOP_MASK),
(HI6421_OCP_DEB_SEL_8MS
| HI6421_OCP_EN_DEBOUNCE_ENABLE));
platform_set_drvdata(pdev, pmic);
ret = devm_mfd_add_devices(&pdev->dev, 0, hi6421_devs,
ARRAY_SIZE(hi6421_devs), NULL, 0, NULL);
if (ret) {
dev_err(&pdev->dev, "add mfd devices failed: %d\n", ret);
return ret;
}
return 0;
}
