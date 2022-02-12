static int intel_xpower_pmic_get_power(struct regmap *regmap, int reg,
int bit, u64 *value)
{
int data;
if (regmap_read(regmap, reg, &data))
return -EIO;
*value = (data & BIT(bit)) ? 1 : 0;
return 0;
}
static int intel_xpower_pmic_update_power(struct regmap *regmap, int reg,
int bit, bool on)
{
int data;
if (regmap_read(regmap, reg, &data))
return -EIO;
if (on)
data |= BIT(bit);
else
data &= ~BIT(bit);
if (regmap_write(regmap, reg, data))
return -EIO;
return 0;
}
static int intel_xpower_pmic_get_raw_temp(struct regmap *regmap, int reg)
{
u8 buf[2];
if (regmap_bulk_read(regmap, AXP288_GP_ADC_H, buf, 2))
return -EIO;
return (buf[0] << 4) + ((buf[1] >> 4) & 0x0F);
}
static acpi_status intel_xpower_pmic_gpio_handler(u32 function,
acpi_physical_address address, u32 bit_width, u64 *value,
void *handler_context, void *region_context)
{
return AE_OK;
}
static int intel_xpower_pmic_opregion_probe(struct platform_device *pdev)
{
struct device *parent = pdev->dev.parent;
struct axp20x_dev *axp20x = dev_get_drvdata(parent);
acpi_status status;
int result;
status = acpi_install_address_space_handler(ACPI_HANDLE(parent),
ACPI_ADR_SPACE_GPIO, intel_xpower_pmic_gpio_handler,
NULL, NULL);
if (ACPI_FAILURE(status))
return -ENODEV;
result = intel_pmic_install_opregion_handler(&pdev->dev,
ACPI_HANDLE(parent), axp20x->regmap,
&intel_xpower_pmic_opregion_data);
if (result)
acpi_remove_address_space_handler(ACPI_HANDLE(parent),
ACPI_ADR_SPACE_GPIO,
intel_xpower_pmic_gpio_handler);
return result;
}
static int __init intel_xpower_pmic_opregion_driver_init(void)
{
return platform_driver_register(&intel_xpower_pmic_opregion_driver);
}
