static bool set_baseband_agc_config(struct adapter *adapt)
{
u32 i;
u32 arraylen = sizeof(array_agc_tab_1t_8188e)/sizeof(u32);
u32 *array = array_agc_tab_1t_8188e;
for (i = 0; i < arraylen; i += 2) {
u32 v1 = array[i];
u32 v2 = array[i+1];
if (v1 < 0xCDCDCDCD) {
phy_set_bb_reg(adapt, v1, bMaskDWord, v2);
udelay(1);
}
}
return true;
}
static void rtl_bb_delay(struct adapter *adapt, u32 addr, u32 data)
{
if (addr == 0xfe) {
msleep(50);
} else if (addr == 0xfd) {
mdelay(5);
} else if (addr == 0xfc) {
mdelay(1);
} else if (addr == 0xfb) {
udelay(50);
} else if (addr == 0xfa) {
udelay(5);
} else if (addr == 0xf9) {
udelay(1);
} else {
phy_set_bb_reg(adapt, addr, bMaskDWord, data);
udelay(1);
}
}
static bool set_baseband_phy_config(struct adapter *adapt)
{
u32 i;
u32 arraylen = sizeof(array_phy_reg_1t_8188e)/sizeof(u32);
u32 *array = array_phy_reg_1t_8188e;
for (i = 0; i < arraylen; i += 2) {
u32 v1 = array[i];
u32 v2 = array[i+1];
if (v1 < 0xCDCDCDCD)
rtl_bb_delay(adapt, v1, v2);
}
return true;
}
static void store_pwrindex_offset(struct adapter *Adapter, u32 regaddr, u32 bitmask, u32 data)
{
struct hal_data_8188e *hal_data = GET_HAL_DATA(Adapter);
if (regaddr == rTxAGC_A_Rate18_06)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][0] = data;
if (regaddr == rTxAGC_A_Rate54_24)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][1] = data;
if (regaddr == rTxAGC_A_CCK1_Mcs32)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][6] = data;
if (regaddr == rTxAGC_B_CCK11_A_CCK2_11 && bitmask == 0xffffff00)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][7] = data;
if (regaddr == rTxAGC_A_Mcs03_Mcs00)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][2] = data;
if (regaddr == rTxAGC_A_Mcs07_Mcs04)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][3] = data;
if (regaddr == rTxAGC_A_Mcs11_Mcs08)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][4] = data;
if (regaddr == rTxAGC_A_Mcs15_Mcs12) {
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][5] = data;
if (hal_data->rf_type == RF_1T1R)
hal_data->pwrGroupCnt++;
}
if (regaddr == rTxAGC_B_Rate18_06)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][8] = data;
if (regaddr == rTxAGC_B_Rate54_24)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][9] = data;
if (regaddr == rTxAGC_B_CCK1_55_Mcs32)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][14] = data;
if (regaddr == rTxAGC_B_CCK11_A_CCK2_11 && bitmask == 0x000000ff)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][15] = data;
if (regaddr == rTxAGC_B_Mcs03_Mcs00)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][10] = data;
if (regaddr == rTxAGC_B_Mcs07_Mcs04)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][11] = data;
if (regaddr == rTxAGC_B_Mcs11_Mcs08)
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][12] = data;
if (regaddr == rTxAGC_B_Mcs15_Mcs12) {
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt][13] = data;
if (hal_data->rf_type != RF_1T1R)
hal_data->pwrGroupCnt++;
}
}
static void rtl_addr_delay(struct adapter *adapt, u32 addr, u32 bit_mask, u32 data)
{
if (addr == 0xfe) {
msleep(50);
} else if (addr == 0xfd) {
mdelay(5);
} else if (addr == 0xfc) {
mdelay(1);
} else if (addr == 0xfb) {
udelay(50);
} else if (addr == 0xfa) {
udelay(5);
} else if (addr == 0xf9) {
udelay(1);
} else{
store_pwrindex_offset(adapt, addr, bit_mask, data);
}
}
static bool config_bb_with_pgheader(struct adapter *adapt)
{
u32 i = 0;
u32 arraylen = sizeof(array_phy_reg_pg_8188e) / sizeof(u32);
u32 *array = array_phy_reg_pg_8188e;
for (i = 0; i < arraylen; i += 3) {
u32 v1 = array[i];
u32 v2 = array[i+1];
u32 v3 = array[i+2];
if (v1 < 0xCDCDCDCD)
rtl_addr_delay(adapt, v1, v2, v3);
}
return true;
}
static void rtl88e_phy_init_bb_rf_register_definition(struct adapter *Adapter)
{
struct hal_data_8188e *hal_data = GET_HAL_DATA(Adapter);
hal_data->PHYRegDef[RF_PATH_A].rfintfs = rFPGA0_XAB_RFInterfaceSW;
hal_data->PHYRegDef[RF_PATH_B].rfintfs = rFPGA0_XAB_RFInterfaceSW;
hal_data->PHYRegDef[RF_PATH_C].rfintfs = rFPGA0_XCD_RFInterfaceSW;
hal_data->PHYRegDef[RF_PATH_D].rfintfs = rFPGA0_XCD_RFInterfaceSW;
hal_data->PHYRegDef[RF_PATH_A].rfintfi = rFPGA0_XAB_RFInterfaceRB;
hal_data->PHYRegDef[RF_PATH_B].rfintfi = rFPGA0_XAB_RFInterfaceRB;
hal_data->PHYRegDef[RF_PATH_C].rfintfi = rFPGA0_XCD_RFInterfaceRB;
hal_data->PHYRegDef[RF_PATH_D].rfintfi = rFPGA0_XCD_RFInterfaceRB;
hal_data->PHYRegDef[RF_PATH_A].rfintfo = rFPGA0_XA_RFInterfaceOE;
hal_data->PHYRegDef[RF_PATH_B].rfintfo = rFPGA0_XB_RFInterfaceOE;
hal_data->PHYRegDef[RF_PATH_A].rfintfe = rFPGA0_XA_RFInterfaceOE;
hal_data->PHYRegDef[RF_PATH_B].rfintfe = rFPGA0_XB_RFInterfaceOE;
hal_data->PHYRegDef[RF_PATH_A].rf3wireOffset = rFPGA0_XA_LSSIParameter;
hal_data->PHYRegDef[RF_PATH_B].rf3wireOffset = rFPGA0_XB_LSSIParameter;
hal_data->PHYRegDef[RF_PATH_A].rfLSSI_Select = rFPGA0_XAB_RFParameter;
hal_data->PHYRegDef[RF_PATH_B].rfLSSI_Select = rFPGA0_XAB_RFParameter;
hal_data->PHYRegDef[RF_PATH_C].rfLSSI_Select = rFPGA0_XCD_RFParameter;
hal_data->PHYRegDef[RF_PATH_D].rfLSSI_Select = rFPGA0_XCD_RFParameter;
hal_data->PHYRegDef[RF_PATH_A].rfTxGainStage = rFPGA0_TxGainStage;
hal_data->PHYRegDef[RF_PATH_B].rfTxGainStage = rFPGA0_TxGainStage;
hal_data->PHYRegDef[RF_PATH_C].rfTxGainStage = rFPGA0_TxGainStage;
hal_data->PHYRegDef[RF_PATH_D].rfTxGainStage = rFPGA0_TxGainStage;
hal_data->PHYRegDef[RF_PATH_A].rfHSSIPara1 = rFPGA0_XA_HSSIParameter1;
hal_data->PHYRegDef[RF_PATH_B].rfHSSIPara1 = rFPGA0_XB_HSSIParameter1;
hal_data->PHYRegDef[RF_PATH_A].rfHSSIPara2 = rFPGA0_XA_HSSIParameter2;
hal_data->PHYRegDef[RF_PATH_B].rfHSSIPara2 = rFPGA0_XB_HSSIParameter2;
hal_data->PHYRegDef[RF_PATH_A].rfSwitchControl = rFPGA0_XAB_SwitchControl;
hal_data->PHYRegDef[RF_PATH_B].rfSwitchControl = rFPGA0_XAB_SwitchControl;
hal_data->PHYRegDef[RF_PATH_C].rfSwitchControl = rFPGA0_XCD_SwitchControl;
hal_data->PHYRegDef[RF_PATH_D].rfSwitchControl = rFPGA0_XCD_SwitchControl;
hal_data->PHYRegDef[RF_PATH_A].rfAGCControl1 = rOFDM0_XAAGCCore1;
hal_data->PHYRegDef[RF_PATH_B].rfAGCControl1 = rOFDM0_XBAGCCore1;
hal_data->PHYRegDef[RF_PATH_C].rfAGCControl1 = rOFDM0_XCAGCCore1;
hal_data->PHYRegDef[RF_PATH_D].rfAGCControl1 = rOFDM0_XDAGCCore1;
hal_data->PHYRegDef[RF_PATH_A].rfAGCControl2 = rOFDM0_XAAGCCore2;
hal_data->PHYRegDef[RF_PATH_B].rfAGCControl2 = rOFDM0_XBAGCCore2;
hal_data->PHYRegDef[RF_PATH_C].rfAGCControl2 = rOFDM0_XCAGCCore2;
hal_data->PHYRegDef[RF_PATH_D].rfAGCControl2 = rOFDM0_XDAGCCore2;
hal_data->PHYRegDef[RF_PATH_A].rfRxIQImbalance = rOFDM0_XARxIQImbalance;
hal_data->PHYRegDef[RF_PATH_B].rfRxIQImbalance = rOFDM0_XBRxIQImbalance;
hal_data->PHYRegDef[RF_PATH_C].rfRxIQImbalance = rOFDM0_XCRxIQImbalance;
hal_data->PHYRegDef[RF_PATH_D].rfRxIQImbalance = rOFDM0_XDRxIQImbalance;
hal_data->PHYRegDef[RF_PATH_A].rfRxAFE = rOFDM0_XARxAFE;
hal_data->PHYRegDef[RF_PATH_B].rfRxAFE = rOFDM0_XBRxAFE;
hal_data->PHYRegDef[RF_PATH_C].rfRxAFE = rOFDM0_XCRxAFE;
hal_data->PHYRegDef[RF_PATH_D].rfRxAFE = rOFDM0_XDRxAFE;
hal_data->PHYRegDef[RF_PATH_A].rfTxIQImbalance = rOFDM0_XATxIQImbalance;
hal_data->PHYRegDef[RF_PATH_B].rfTxIQImbalance = rOFDM0_XBTxIQImbalance;
hal_data->PHYRegDef[RF_PATH_C].rfTxIQImbalance = rOFDM0_XCTxIQImbalance;
hal_data->PHYRegDef[RF_PATH_D].rfTxIQImbalance = rOFDM0_XDTxIQImbalance;
hal_data->PHYRegDef[RF_PATH_A].rfTxAFE = rOFDM0_XATxAFE;
hal_data->PHYRegDef[RF_PATH_B].rfTxAFE = rOFDM0_XBTxAFE;
hal_data->PHYRegDef[RF_PATH_C].rfTxAFE = rOFDM0_XCTxAFE;
hal_data->PHYRegDef[RF_PATH_D].rfTxAFE = rOFDM0_XDTxAFE;
hal_data->PHYRegDef[RF_PATH_A].rfLSSIReadBack = rFPGA0_XA_LSSIReadBack;
hal_data->PHYRegDef[RF_PATH_B].rfLSSIReadBack = rFPGA0_XB_LSSIReadBack;
hal_data->PHYRegDef[RF_PATH_C].rfLSSIReadBack = rFPGA0_XC_LSSIReadBack;
hal_data->PHYRegDef[RF_PATH_D].rfLSSIReadBack = rFPGA0_XD_LSSIReadBack;
hal_data->PHYRegDef[RF_PATH_A].rfLSSIReadBackPi = TransceiverA_HSPI_Readback;
hal_data->PHYRegDef[RF_PATH_B].rfLSSIReadBackPi = TransceiverB_HSPI_Readback;
}
static bool config_parafile(struct adapter *adapt)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(adapt);
struct hal_data_8188e *hal_data = GET_HAL_DATA(adapt);
set_baseband_phy_config(adapt);
if (!pEEPROM->bautoload_fail_flag) {
hal_data->pwrGroupCnt = 0;
config_bb_with_pgheader(adapt);
}
set_baseband_agc_config(adapt);
return true;
}
bool rtl88eu_phy_bb_config(struct adapter *adapt)
{
int rtstatus = true;
struct hal_data_8188e *hal_data = GET_HAL_DATA(adapt);
u32 regval;
u8 crystal_cap;
rtl88e_phy_init_bb_rf_register_definition(adapt);
regval = usb_read16(adapt, REG_SYS_FUNC_EN);
usb_write16(adapt, REG_SYS_FUNC_EN, (u16)(regval|BIT13|BIT0|BIT1));
usb_write8(adapt, REG_RF_CTRL, RF_EN|RF_RSTB|RF_SDMRSTB);
usb_write8(adapt, REG_SYS_FUNC_EN, FEN_USBA | FEN_USBD | FEN_BB_GLB_RSTn | FEN_BBRSTB);
rtstatus = config_parafile(adapt);
crystal_cap = hal_data->CrystalCap & 0x3F;
phy_set_bb_reg(adapt, REG_AFE_XTAL_CTRL, 0x7ff800, (crystal_cap | (crystal_cap << 6)));
return rtstatus;
}
