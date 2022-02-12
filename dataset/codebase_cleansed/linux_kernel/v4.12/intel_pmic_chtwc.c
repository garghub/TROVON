static int intel_cht_wc_pmic_get_power(struct regmap *regmap, int reg,
int bit, u64 *value)
{
int data;
if (regmap_read(regmap, reg, &data))
return -EIO;
*value = (data & bit) ? 1 : 0;
return 0;
}
static int intel_cht_wc_pmic_update_power(struct regmap *regmap, int reg,
int bitmask, bool on)
{
return regmap_update_bits(regmap, reg, bitmask, on ? 1 : 0);
}
static int intel_cht_wc_pmic_opregion_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
return intel_pmic_install_opregion_handler(&pdev->dev,
ACPI_HANDLE(pdev->dev.parent),
pmic->regmap,
&intel_cht_wc_pmic_opregion_data);
}
