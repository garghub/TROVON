static int pmic_spmi_probe(struct spmi_device *sdev)
{
struct device_node *root = sdev->dev.of_node;
struct regmap *regmap;
regmap = devm_regmap_init_spmi_ext(sdev, &spmi_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return of_platform_populate(root, NULL, NULL, &sdev->dev);
}
static void pmic_spmi_remove(struct spmi_device *sdev)
{
of_platform_depopulate(&sdev->dev);
}
