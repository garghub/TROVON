static int intel_crc_pmic_get_power(struct regmap *regmap, int reg,
int bit, u64 *value)
{
int data;
if (regmap_read(regmap, reg, &data))
return -EIO;
*value = (data & PWR_SOURCE_SELECT) && (data & BIT(bit)) ? 1 : 0;
return 0;
}
static int intel_crc_pmic_update_power(struct regmap *regmap, int reg,
int bit, bool on)
{
int data;
if (regmap_read(regmap, reg, &data))
return -EIO;
if (on) {
data |= PWR_SOURCE_SELECT | BIT(bit);
} else {
data &= ~BIT(bit);
data |= PWR_SOURCE_SELECT;
}
if (regmap_write(regmap, reg, data))
return -EIO;
return 0;
}
static int intel_crc_pmic_get_raw_temp(struct regmap *regmap, int reg)
{
int temp_l, temp_h;
if (regmap_read(regmap, reg, &temp_l) ||
regmap_read(regmap, reg - 1, &temp_h))
return -EIO;
return temp_l | (temp_h & 0x3) << 8;
}
static int intel_crc_pmic_update_aux(struct regmap *regmap, int reg, int raw)
{
return regmap_write(regmap, reg, raw) ||
regmap_update_bits(regmap, reg - 1, 0x3, raw >> 8) ? -EIO : 0;
}
static int intel_crc_pmic_get_policy(struct regmap *regmap,
int reg, int bit, u64 *value)
{
int pen;
if (regmap_read(regmap, reg, &pen))
return -EIO;
*value = pen >> 7;
return 0;
}
static int intel_crc_pmic_update_policy(struct regmap *regmap,
int reg, int bit, int enable)
{
int alert0;
if (regmap_read(regmap, PMIC_A0LOCK_REG, &alert0))
return -EIO;
if (regmap_update_bits(regmap, PMIC_A0LOCK_REG, 0x01, 0))
return -EIO;
if (regmap_update_bits(regmap, reg, 0x80, enable << 7))
return -EIO;
if (regmap_write(regmap, PMIC_A0LOCK_REG, alert0))
return -EIO;
return 0;
}
static int intel_crc_pmic_opregion_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
return intel_pmic_install_opregion_handler(&pdev->dev,
ACPI_HANDLE(pdev->dev.parent), pmic->regmap,
&intel_crc_pmic_opregion_data);
}
static int __init intel_crc_pmic_opregion_driver_init(void)
{
return platform_driver_register(&intel_crc_pmic_opregion_driver);
}
