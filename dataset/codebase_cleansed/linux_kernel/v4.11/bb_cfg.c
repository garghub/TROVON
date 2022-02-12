static bool set_baseband_agc_config(struct adapter *adapt)
{
u32 i;
const u32 arraylen = ARRAY_SIZE(array_agc_tab_1t_8188e);
u32 *array = array_agc_tab_1t_8188e;
for (i = 0; i < arraylen; i += 2) {
u32 v1 = array[i];
u32 v2 = array[i + 1];
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
const u32 arraylen = ARRAY_SIZE(array_phy_reg_1t_8188e);
u32 *array = array_phy_reg_1t_8188e;
for (i = 0; i < arraylen; i += 2) {
u32 v1 = array[i];
u32 v2 = array[i + 1];
if (v1 < 0xCDCDCDCD)
rtl_bb_delay(adapt, v1, v2);
}
return true;
}
static void store_pwrindex_offset(struct adapter *adapter,
u32 regaddr, u32 bitmask, u32 data)
{
struct hal_data_8188e *hal_data = adapter->HalData;
u32 * const power_level_offset =
hal_data->MCSTxPowerLevelOriginalOffset[hal_data->pwrGroupCnt];
if (regaddr == rTxAGC_A_Rate18_06)
power_level_offset[0] = data;
if (regaddr == rTxAGC_A_Rate54_24)
power_level_offset[1] = data;
if (regaddr == rTxAGC_A_CCK1_Mcs32)
power_level_offset[6] = data;
if (regaddr == rTxAGC_B_CCK11_A_CCK2_11 && bitmask == 0xffffff00)
power_level_offset[7] = data;
if (regaddr == rTxAGC_A_Mcs03_Mcs00)
power_level_offset[2] = data;
if (regaddr == rTxAGC_A_Mcs07_Mcs04)
power_level_offset[3] = data;
if (regaddr == rTxAGC_A_Mcs11_Mcs08)
power_level_offset[4] = data;
if (regaddr == rTxAGC_A_Mcs15_Mcs12) {
power_level_offset[5] = data;
hal_data->pwrGroupCnt++;
}
if (regaddr == rTxAGC_B_Rate18_06)
power_level_offset[8] = data;
if (regaddr == rTxAGC_B_Rate54_24)
power_level_offset[9] = data;
if (regaddr == rTxAGC_B_CCK1_55_Mcs32)
power_level_offset[14] = data;
if (regaddr == rTxAGC_B_CCK11_A_CCK2_11 && bitmask == 0x000000ff)
power_level_offset[15] = data;
if (regaddr == rTxAGC_B_Mcs03_Mcs00)
power_level_offset[10] = data;
if (regaddr == rTxAGC_B_Mcs07_Mcs04)
power_level_offset[11] = data;
if (regaddr == rTxAGC_B_Mcs11_Mcs08)
power_level_offset[12] = data;
if (regaddr == rTxAGC_B_Mcs15_Mcs12)
power_level_offset[13] = data;
}
static void rtl_addr_delay(struct adapter *adapt,
u32 addr, u32 bit_mask, u32 data)
{
switch (addr) {
case 0xfe:
msleep(50);
break;
case 0xfd:
mdelay(5);
break;
case 0xfc:
mdelay(1);
break;
case 0xfb:
udelay(50);
break;
case 0xfa:
udelay(5);
break;
case 0xf9:
udelay(1);
break;
default:
store_pwrindex_offset(adapt, addr, bit_mask, data);
}
}
static bool config_bb_with_pgheader(struct adapter *adapt)
{
u32 i;
const u32 arraylen = ARRAY_SIZE(array_phy_reg_pg_8188e);
u32 *array = array_phy_reg_pg_8188e;
for (i = 0; i < arraylen; i += 3) {
u32 v1 = array[i];
u32 v2 = array[i + 1];
u32 v3 = array[i + 2];
if (v1 < 0xCDCDCDCD)
rtl_addr_delay(adapt, v1, v2, v3);
}
return true;
}
static void rtl88e_phy_init_bb_rf_register_definition(struct adapter *adapter)
{
struct bb_reg_def *reg[4];
reg[RF_PATH_A] = &adapter->HalData->PHYRegDef[RF_PATH_A];
reg[RF_PATH_B] = &adapter->HalData->PHYRegDef[RF_PATH_B];
reg[RF_PATH_A]->rfintfs = rFPGA0_XAB_RFInterfaceSW;
reg[RF_PATH_B]->rfintfs = rFPGA0_XAB_RFInterfaceSW;
reg[RF_PATH_A]->rfintfi = rFPGA0_XAB_RFInterfaceRB;
reg[RF_PATH_B]->rfintfi = rFPGA0_XAB_RFInterfaceRB;
reg[RF_PATH_A]->rfintfo = rFPGA0_XA_RFInterfaceOE;
reg[RF_PATH_B]->rfintfo = rFPGA0_XB_RFInterfaceOE;
reg[RF_PATH_A]->rfintfe = rFPGA0_XA_RFInterfaceOE;
reg[RF_PATH_B]->rfintfe = rFPGA0_XB_RFInterfaceOE;
reg[RF_PATH_A]->rf3wireOffset = rFPGA0_XA_LSSIParameter;
reg[RF_PATH_B]->rf3wireOffset = rFPGA0_XB_LSSIParameter;
reg[RF_PATH_A]->rfLSSI_Select = rFPGA0_XAB_RFParameter;
reg[RF_PATH_B]->rfLSSI_Select = rFPGA0_XAB_RFParameter;
reg[RF_PATH_A]->rfTxGainStage = rFPGA0_TxGainStage;
reg[RF_PATH_B]->rfTxGainStage = rFPGA0_TxGainStage;
reg[RF_PATH_A]->rfHSSIPara1 = rFPGA0_XA_HSSIParameter1;
reg[RF_PATH_B]->rfHSSIPara1 = rFPGA0_XB_HSSIParameter1;
reg[RF_PATH_A]->rfHSSIPara2 = rFPGA0_XA_HSSIParameter2;
reg[RF_PATH_B]->rfHSSIPara2 = rFPGA0_XB_HSSIParameter2;
reg[RF_PATH_A]->rfSwitchControl = rFPGA0_XAB_SwitchControl;
reg[RF_PATH_B]->rfSwitchControl = rFPGA0_XAB_SwitchControl;
reg[RF_PATH_A]->rfAGCControl1 = rOFDM0_XAAGCCore1;
reg[RF_PATH_B]->rfAGCControl1 = rOFDM0_XBAGCCore1;
reg[RF_PATH_A]->rfAGCControl2 = rOFDM0_XAAGCCore2;
reg[RF_PATH_B]->rfAGCControl2 = rOFDM0_XBAGCCore2;
reg[RF_PATH_A]->rfRxIQImbalance = rOFDM0_XARxIQImbalance;
reg[RF_PATH_B]->rfRxIQImbalance = rOFDM0_XBRxIQImbalance;
reg[RF_PATH_A]->rfRxAFE = rOFDM0_XARxAFE;
reg[RF_PATH_B]->rfRxAFE = rOFDM0_XBRxAFE;
reg[RF_PATH_A]->rfTxIQImbalance = rOFDM0_XATxIQImbalance;
reg[RF_PATH_B]->rfTxIQImbalance = rOFDM0_XBTxIQImbalance;
reg[RF_PATH_A]->rfTxAFE = rOFDM0_XATxAFE;
reg[RF_PATH_B]->rfTxAFE = rOFDM0_XBTxAFE;
reg[RF_PATH_A]->rfLSSIReadBack = rFPGA0_XA_LSSIReadBack;
reg[RF_PATH_B]->rfLSSIReadBack = rFPGA0_XB_LSSIReadBack;
reg[RF_PATH_A]->rfLSSIReadBackPi = TransceiverA_HSPI_Readback;
reg[RF_PATH_B]->rfLSSIReadBackPi = TransceiverB_HSPI_Readback;
}
static bool config_parafile(struct adapter *adapt)
{
struct eeprom_priv *eeprom = GET_EEPROM_EFUSE_PRIV(adapt);
set_baseband_phy_config(adapt);
if (!eeprom->bautoload_fail_flag) {
adapt->HalData->pwrGroupCnt = 0;
config_bb_with_pgheader(adapt);
}
set_baseband_agc_config(adapt);
return true;
}
bool rtl88eu_phy_bb_config(struct adapter *adapt)
{
int rtstatus = true;
u32 regval;
u8 crystal_cap;
rtl88e_phy_init_bb_rf_register_definition(adapt);
regval = usb_read16(adapt, REG_SYS_FUNC_EN);
usb_write16(adapt, REG_SYS_FUNC_EN,
(u16)(regval | BIT(13) | BIT(0) | BIT(1)));
usb_write8(adapt, REG_RF_CTRL, RF_EN | RF_RSTB | RF_SDMRSTB);
usb_write8(adapt, REG_SYS_FUNC_EN, FEN_USBA |
FEN_USBD | FEN_BB_GLB_RSTn | FEN_BBRSTB);
rtstatus = config_parafile(adapt);
crystal_cap = adapt->HalData->CrystalCap & 0x3F;
phy_set_bb_reg(adapt, REG_AFE_XTAL_CTRL, 0x7ff800,
(crystal_cap | (crystal_cap << 6)));
return rtstatus;
}
