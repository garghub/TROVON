static int twl_set_voltage(void *data, int target_uV)
{
struct voltagedomain *voltdm = (struct voltagedomain *)data;
return voltdm_scale(voltdm, target_uV);
}
static int twl_get_voltage(void *data)
{
struct voltagedomain *voltdm = (struct voltagedomain *)data;
return voltdm_get_voltage(voltdm);
}
void __init omap_pmic_init(int bus, u32 clkrate,
const char *pmic_type, int pmic_irq,
struct twl4030_platform_data *pmic_data)
{
omap_mux_init_signal("sys_nirq", OMAP_PIN_INPUT_PULLUP | OMAP_PIN_OFF_WAKEUPENABLE);
strncpy(pmic_i2c_board_info.type, pmic_type,
sizeof(pmic_i2c_board_info.type));
pmic_i2c_board_info.irq = pmic_irq;
pmic_i2c_board_info.platform_data = pmic_data;
omap_register_i2c_bus(bus, clkrate, &pmic_i2c_board_info, 1);
}
void __init omap4_pmic_init(const char *pmic_type,
struct twl4030_platform_data *pmic_data,
struct twl6040_platform_data *twl6040_data, int twl6040_irq)
{
omap_mux_init_signal("sys_nirq1", OMAP_PIN_INPUT_PULLUP | OMAP_PIN_OFF_WAKEUPENABLE);
strncpy(omap4_i2c1_board_info[0].type, pmic_type,
sizeof(omap4_i2c1_board_info[0].type));
omap4_i2c1_board_info[0].irq = OMAP44XX_IRQ_SYS_1N;
omap4_i2c1_board_info[0].platform_data = pmic_data;
omap4_i2c1_board_info[1].irq = twl6040_irq;
omap4_i2c1_board_info[1].platform_data = twl6040_data;
omap_register_i2c_bus(1, 400, omap4_i2c1_board_info, 2);
}
void __init omap_pmic_late_init(void)
{
if (pmic_i2c_board_info.irq)
omap3_twl_init();
if (omap4_i2c1_board_info[0].irq)
omap4_twl_init();
}
void __init omap3_pmic_get_config(struct twl4030_platform_data *pmic_data,
u32 pdata_flags, u32 regulators_flags)
{
if (!pmic_data->vdd1) {
omap3_vdd1.driver_data = &omap3_vdd1_drvdata;
omap3_vdd1_drvdata.data = voltdm_lookup("mpu_iva");
pmic_data->vdd1 = &omap3_vdd1;
}
if (!pmic_data->vdd2) {
omap3_vdd2.driver_data = &omap3_vdd2_drvdata;
omap3_vdd2_drvdata.data = voltdm_lookup("core");
pmic_data->vdd2 = &omap3_vdd2;
}
if (pdata_flags & TWL_COMMON_PDATA_USB && !pmic_data->usb)
pmic_data->usb = &omap3_usb_pdata;
if (pdata_flags & TWL_COMMON_PDATA_BCI && !pmic_data->bci)
pmic_data->bci = &omap3_bci_pdata;
if (pdata_flags & TWL_COMMON_PDATA_MADC && !pmic_data->madc)
pmic_data->madc = &omap3_madc_pdata;
if (pdata_flags & TWL_COMMON_PDATA_AUDIO && !pmic_data->audio)
pmic_data->audio = &omap3_audio_pdata;
if (regulators_flags & TWL_COMMON_REGULATOR_VDAC && !pmic_data->vdac)
pmic_data->vdac = &omap3_vdac_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VPLL2 && !pmic_data->vpll2)
pmic_data->vpll2 = &omap3_vpll2_idata;
}
void __init omap4_pmic_get_config(struct twl4030_platform_data *pmic_data,
u32 pdata_flags, u32 regulators_flags)
{
if (!pmic_data->vdd1) {
omap4_vdd1.driver_data = &omap4_vdd1_drvdata;
omap4_vdd1_drvdata.data = voltdm_lookup("mpu");
pmic_data->vdd1 = &omap4_vdd1;
}
if (!pmic_data->vdd2) {
omap4_vdd2.driver_data = &omap4_vdd2_drvdata;
omap4_vdd2_drvdata.data = voltdm_lookup("iva");
pmic_data->vdd2 = &omap4_vdd2;
}
if (!pmic_data->vdd3) {
omap4_vdd3.driver_data = &omap4_vdd3_drvdata;
omap4_vdd3_drvdata.data = voltdm_lookup("core");
pmic_data->vdd3 = &omap4_vdd3;
}
if (pdata_flags & TWL_COMMON_PDATA_USB && !pmic_data->usb)
pmic_data->usb = &omap4_usb_pdata;
if (regulators_flags & TWL_COMMON_REGULATOR_VDAC && !pmic_data->vdac)
pmic_data->vdac = &omap4_vdac_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VAUX2 && !pmic_data->vaux2)
pmic_data->vaux2 = &omap4_vaux2_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VAUX3 && !pmic_data->vaux3)
pmic_data->vaux3 = &omap4_vaux3_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VMMC && !pmic_data->vmmc)
pmic_data->vmmc = &omap4_vmmc_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VPP && !pmic_data->vpp)
pmic_data->vpp = &omap4_vpp_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VANA && !pmic_data->vana)
pmic_data->vana = &omap4_vana_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VCXIO && !pmic_data->vcxio)
pmic_data->vcxio = &omap4_vcxio_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_VUSB && !pmic_data->vusb)
pmic_data->vusb = &omap4_vusb_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_CLK32KG &&
!pmic_data->clk32kg)
pmic_data->clk32kg = &omap4_clk32kg_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_V1V8 && !pmic_data->v1v8)
pmic_data->v1v8 = &omap4_v1v8_idata;
if (regulators_flags & TWL_COMMON_REGULATOR_V2V1 && !pmic_data->v2v1)
pmic_data->v2v1 = &omap4_v2v1_idata;
}
