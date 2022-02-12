static unsigned long twl4030_vsel_to_uv(const u8 vsel)
{
return (((vsel * 125) + 6000)) * 100;
}
static u8 twl4030_uv_to_vsel(unsigned long uv)
{
return DIV_ROUND_UP(uv - 600000, 12500);
}
static unsigned long twl6030_vsel_to_uv(const u8 vsel)
{
if (!is_offset_valid) {
twl_i2c_read_u8(TWL6030_MODULE_ID0, &smps_offset,
REG_SMPS_OFFSET);
is_offset_valid = true;
}
if (!vsel)
return 0;
if (vsel == 0x3A)
return 1350000;
if (smps_offset & 0x8)
return ((((vsel - 1) * 1266) + 70900)) * 10;
else
return ((((vsel - 1) * 1266) + 60770)) * 10;
}
static u8 twl6030_uv_to_vsel(unsigned long uv)
{
if (!is_offset_valid) {
twl_i2c_read_u8(TWL6030_MODULE_ID0, &smps_offset,
REG_SMPS_OFFSET);
is_offset_valid = true;
}
if (!uv)
return 0x00;
if (uv > twl6030_vsel_to_uv(0x39)) {
if (uv == 1350000)
return 0x3A;
pr_err("%s:OUT OF RANGE! non mapped vsel for %ld Vs max %ld\n",
__func__, uv, twl6030_vsel_to_uv(0x39));
return 0x3A;
}
if (smps_offset & 0x8)
return DIV_ROUND_UP(uv - 709000, 12660) + 1;
else
return DIV_ROUND_UP(uv - 607700, 12660) + 1;
}
int __init omap4_twl_init(void)
{
struct voltagedomain *voltdm;
if (!cpu_is_omap44xx())
return -ENODEV;
voltdm = voltdm_lookup("mpu");
omap_voltage_register_pmic(voltdm, &omap4_mpu_pmic);
voltdm = voltdm_lookup("iva");
omap_voltage_register_pmic(voltdm, &omap4_iva_pmic);
voltdm = voltdm_lookup("core");
omap_voltage_register_pmic(voltdm, &omap4_core_pmic);
return 0;
}
int __init omap3_twl_init(void)
{
struct voltagedomain *voltdm;
if (!cpu_is_omap34xx())
return -ENODEV;
voltdm = voltdm_lookup("mpu_iva");
omap_voltage_register_pmic(voltdm, &omap3_mpu_pmic);
voltdm = voltdm_lookup("core");
omap_voltage_register_pmic(voltdm, &omap3_core_pmic);
return 0;
}
