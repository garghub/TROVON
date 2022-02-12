void __init omap_pmic_init(int bus, u32 clkrate,
const char *pmic_type, int pmic_irq,
struct twl4030_platform_data *pmic_data)
{
strncpy(pmic_i2c_board_info.type, pmic_type,
sizeof(pmic_i2c_board_info.type));
pmic_i2c_board_info.irq = pmic_irq;
pmic_i2c_board_info.platform_data = pmic_data;
omap_register_i2c_bus(bus, clkrate, &pmic_i2c_board_info, 1);
}
void __init omap_pmic_late_init(void)
{
if (!pmic_i2c_board_info.irq)
return;
omap3_twl_init();
omap4_twl_init();
}
void __init omap3_pmic_get_config(struct twl4030_platform_data *pmic_data,
u32 pdata_flags, u32 regulators_flags)
{
if (!pmic_data->irq_base)
pmic_data->irq_base = TWL4030_IRQ_BASE;
if (!pmic_data->irq_end)
pmic_data->irq_end = TWL4030_IRQ_END;
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
if (!pmic_data->irq_base)
pmic_data->irq_base = TWL6030_IRQ_BASE;
if (!pmic_data->irq_end)
pmic_data->irq_end = TWL6030_IRQ_END;
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
}
