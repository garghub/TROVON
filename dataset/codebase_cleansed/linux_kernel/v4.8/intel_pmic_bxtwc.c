static int intel_bxtwc_pmic_get_power(struct regmap *regmap, int reg,
int bit, u64 *value)
{
int data;
if (regmap_read(regmap, reg, &data))
return -EIO;
*value = (data & bit) ? 1 : 0;
return 0;
}
static int intel_bxtwc_pmic_update_power(struct regmap *regmap, int reg,
int bit, bool on)
{
u8 val, mask = bit;
if (on)
val = 0xFF;
else
val = 0x0;
return regmap_update_bits(regmap, reg, mask, val);
}
static int intel_bxtwc_pmic_get_raw_temp(struct regmap *regmap, int reg)
{
unsigned int val, adc_val, reg_val;
u8 temp_l, temp_h, cursrc;
unsigned long rlsb;
static const unsigned long rlsb_array[] = {
0, 260420, 130210, 65100, 32550, 16280,
8140, 4070, 2030, 0, 260420, 130210 };
if (regmap_read(regmap, reg, &val))
return -EIO;
temp_l = (u8) val;
if (regmap_read(regmap, (reg - 1), &val))
return -EIO;
temp_h = (u8) val;
reg_val = temp_l | WHISKEY_COVE_ADC_HIGH_BIT(temp_h);
cursrc = WHISKEY_COVE_ADC_CURSRC(temp_h);
rlsb = rlsb_array[cursrc];
adc_val = reg_val * rlsb / 1000;
return adc_val;
}
static int
intel_bxtwc_pmic_update_aux(struct regmap *regmap, int reg, int raw)
{
u32 bsr_num;
u16 resi_val, count = 0, thrsh = 0;
u8 alrt_h, alrt_l, cursel = 0;
bsr_num = raw;
bsr_num /= (1 << 5);
count = fls(bsr_num) - 1;
cursel = clamp_t(s8, (count - 7), 0, 7);
thrsh = raw / (1 << (4 + cursel));
resi_val = (cursel << 9) | thrsh;
alrt_h = (resi_val >> 8) & WHISKEY_COVE_ALRT_HIGH_BIT_MASK;
if (regmap_update_bits(regmap,
reg - 1,
WHISKEY_COVE_ALRT_HIGH_BIT_MASK,
alrt_h))
return -EIO;
alrt_l = (u8)resi_val;
return regmap_write(regmap, reg, alrt_l);
}
static int
intel_bxtwc_pmic_get_policy(struct regmap *regmap, int reg, int bit, u64 *value)
{
u8 mask = BIT(bit);
unsigned int val;
if (regmap_read(regmap, reg, &val))
return -EIO;
*value = (val & mask) >> bit;
return 0;
}
static int
intel_bxtwc_pmic_update_policy(struct regmap *regmap,
int reg, int bit, int enable)
{
u8 mask = BIT(bit), val = enable << bit;
return regmap_update_bits(regmap, reg, mask, val);
}
static int intel_bxtwc_pmic_opregion_probe(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(pdev->dev.parent);
return intel_pmic_install_opregion_handler(&pdev->dev,
ACPI_HANDLE(pdev->dev.parent),
pmic->regmap,
&intel_bxtwc_pmic_opregion_data);
}
static int __init intel_bxtwc_pmic_opregion_driver_init(void)
{
return platform_driver_register(&intel_bxtwc_pmic_opregion_driver);
}
