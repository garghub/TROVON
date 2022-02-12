static u32 phy_CalculateBitShift(u32 BitMask)
{
u32 i;
for (i = 0; i <= 31; i++) {
if (((BitMask>>i) & 0x1) == 1)
break;
}
return i;
}
u32
rtl8188e_PHY_QueryBBReg(
struct adapter *Adapter,
u32 RegAddr,
u32 BitMask
)
{
u32 ReturnValue = 0, OriginalValue, BitShift;
OriginalValue = rtw_read32(Adapter, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
ReturnValue = (OriginalValue & BitMask) >> BitShift;
return ReturnValue;
}
void rtl8188e_PHY_SetBBReg(struct adapter *Adapter, u32 RegAddr, u32 BitMask, u32 Data)
{
u32 OriginalValue, BitShift;
if (BitMask != bMaskDWord) {
OriginalValue = rtw_read32(Adapter, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
Data = ((OriginalValue & (~BitMask)) | (Data << BitShift));
}
rtw_write32(Adapter, RegAddr, Data);
}
static u32
phy_RFSerialRead(
struct adapter *Adapter,
enum rf_radio_path eRFPath,
u32 Offset
)
{
u32 retValue = 0;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
struct bb_reg_def *pPhyReg = &pHalData->PHYRegDef[eRFPath];
u32 NewOffset;
u32 tmplong, tmplong2;
u8 RfPiEnable = 0;
Offset &= 0xff;
NewOffset = Offset;
tmplong = PHY_QueryBBReg(Adapter, rFPGA0_XA_HSSIParameter2, bMaskDWord);
if (eRFPath == RF_PATH_A)
tmplong2 = tmplong;
else
tmplong2 = PHY_QueryBBReg(Adapter, pPhyReg->rfHSSIPara2, bMaskDWord);
tmplong2 = (tmplong2 & (~bLSSIReadAddress)) | (NewOffset<<23) | bLSSIReadEdge;
PHY_SetBBReg(Adapter, rFPGA0_XA_HSSIParameter2, bMaskDWord, tmplong&(~bLSSIReadEdge));
udelay(10);
PHY_SetBBReg(Adapter, pPhyReg->rfHSSIPara2, bMaskDWord, tmplong2);
udelay(100);
udelay(10);
if (eRFPath == RF_PATH_A)
RfPiEnable = (u8)PHY_QueryBBReg(Adapter, rFPGA0_XA_HSSIParameter1, BIT8);
else if (eRFPath == RF_PATH_B)
RfPiEnable = (u8)PHY_QueryBBReg(Adapter, rFPGA0_XB_HSSIParameter1, BIT8);
if (RfPiEnable) {
retValue = PHY_QueryBBReg(Adapter, pPhyReg->rfLSSIReadBackPi, bLSSIReadBackData);
} else {
retValue = PHY_QueryBBReg(Adapter, pPhyReg->rfLSSIReadBack, bLSSIReadBackData);
}
return retValue;
}
static void
phy_RFSerialWrite(
struct adapter *Adapter,
enum rf_radio_path eRFPath,
u32 Offset,
u32 Data
)
{
u32 DataAndAddr = 0;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
struct bb_reg_def *pPhyReg = &pHalData->PHYRegDef[eRFPath];
u32 NewOffset;
Offset &= 0xff;
NewOffset = Offset;
DataAndAddr = ((NewOffset<<20) | (Data&0x000fffff)) & 0x0fffffff;
PHY_SetBBReg(Adapter, pPhyReg->rf3wireOffset, bMaskDWord, DataAndAddr);
}
u32 rtl8188e_PHY_QueryRFReg(struct adapter *Adapter, enum rf_radio_path eRFPath,
u32 RegAddr, u32 BitMask)
{
u32 Original_Value, Readback_Value, BitShift;
Original_Value = phy_RFSerialRead(Adapter, eRFPath, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
Readback_Value = (Original_Value & BitMask) >> BitShift;
return Readback_Value;
}
void
rtl8188e_PHY_SetRFReg(
struct adapter *Adapter,
enum rf_radio_path eRFPath,
u32 RegAddr,
u32 BitMask,
u32 Data
)
{
u32 Original_Value, BitShift;
if (BitMask != bRFRegOffsetMask) {
Original_Value = phy_RFSerialRead(Adapter, eRFPath, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
Data = ((Original_Value & (~BitMask)) | (Data << BitShift));
}
phy_RFSerialWrite(Adapter, eRFPath, RegAddr, Data);
}
s32 PHY_MACConfig8188E(struct adapter *Adapter)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
int rtStatus = _SUCCESS;
if (HAL_STATUS_FAILURE == ODM_ConfigMACWithHeaderFile(&pHalData->odmpriv))
rtStatus = _FAIL;
rtw_write16(Adapter, REG_MAX_AGGR_NUM, MAX_AGGR_NUM);
return rtStatus;
}
static void
phy_InitBBRFRegisterDefinition(
struct adapter *Adapter
)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
pHalData->PHYRegDef[RF_PATH_A].rfintfs = rFPGA0_XAB_RFInterfaceSW;
pHalData->PHYRegDef[RF_PATH_B].rfintfs = rFPGA0_XAB_RFInterfaceSW;
pHalData->PHYRegDef[RF_PATH_C].rfintfs = rFPGA0_XCD_RFInterfaceSW;
pHalData->PHYRegDef[RF_PATH_D].rfintfs = rFPGA0_XCD_RFInterfaceSW;
pHalData->PHYRegDef[RF_PATH_A].rfintfi = rFPGA0_XAB_RFInterfaceRB;
pHalData->PHYRegDef[RF_PATH_B].rfintfi = rFPGA0_XAB_RFInterfaceRB;
pHalData->PHYRegDef[RF_PATH_C].rfintfi = rFPGA0_XCD_RFInterfaceRB;
pHalData->PHYRegDef[RF_PATH_D].rfintfi = rFPGA0_XCD_RFInterfaceRB;
pHalData->PHYRegDef[RF_PATH_A].rfintfo = rFPGA0_XA_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_B].rfintfo = rFPGA0_XB_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_A].rfintfe = rFPGA0_XA_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_B].rfintfe = rFPGA0_XB_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_A].rf3wireOffset = rFPGA0_XA_LSSIParameter;
pHalData->PHYRegDef[RF_PATH_B].rf3wireOffset = rFPGA0_XB_LSSIParameter;
pHalData->PHYRegDef[RF_PATH_A].rfLSSI_Select = rFPGA0_XAB_RFParameter;
pHalData->PHYRegDef[RF_PATH_B].rfLSSI_Select = rFPGA0_XAB_RFParameter;
pHalData->PHYRegDef[RF_PATH_C].rfLSSI_Select = rFPGA0_XCD_RFParameter;
pHalData->PHYRegDef[RF_PATH_D].rfLSSI_Select = rFPGA0_XCD_RFParameter;
pHalData->PHYRegDef[RF_PATH_A].rfTxGainStage = rFPGA0_TxGainStage;
pHalData->PHYRegDef[RF_PATH_B].rfTxGainStage = rFPGA0_TxGainStage;
pHalData->PHYRegDef[RF_PATH_C].rfTxGainStage = rFPGA0_TxGainStage;
pHalData->PHYRegDef[RF_PATH_D].rfTxGainStage = rFPGA0_TxGainStage;
pHalData->PHYRegDef[RF_PATH_A].rfHSSIPara1 = rFPGA0_XA_HSSIParameter1;
pHalData->PHYRegDef[RF_PATH_B].rfHSSIPara1 = rFPGA0_XB_HSSIParameter1;
pHalData->PHYRegDef[RF_PATH_A].rfHSSIPara2 = rFPGA0_XA_HSSIParameter2;
pHalData->PHYRegDef[RF_PATH_B].rfHSSIPara2 = rFPGA0_XB_HSSIParameter2;
pHalData->PHYRegDef[RF_PATH_A].rfSwitchControl = rFPGA0_XAB_SwitchControl;
pHalData->PHYRegDef[RF_PATH_B].rfSwitchControl = rFPGA0_XAB_SwitchControl;
pHalData->PHYRegDef[RF_PATH_C].rfSwitchControl = rFPGA0_XCD_SwitchControl;
pHalData->PHYRegDef[RF_PATH_D].rfSwitchControl = rFPGA0_XCD_SwitchControl;
pHalData->PHYRegDef[RF_PATH_A].rfAGCControl1 = rOFDM0_XAAGCCore1;
pHalData->PHYRegDef[RF_PATH_B].rfAGCControl1 = rOFDM0_XBAGCCore1;
pHalData->PHYRegDef[RF_PATH_C].rfAGCControl1 = rOFDM0_XCAGCCore1;
pHalData->PHYRegDef[RF_PATH_D].rfAGCControl1 = rOFDM0_XDAGCCore1;
pHalData->PHYRegDef[RF_PATH_A].rfAGCControl2 = rOFDM0_XAAGCCore2;
pHalData->PHYRegDef[RF_PATH_B].rfAGCControl2 = rOFDM0_XBAGCCore2;
pHalData->PHYRegDef[RF_PATH_C].rfAGCControl2 = rOFDM0_XCAGCCore2;
pHalData->PHYRegDef[RF_PATH_D].rfAGCControl2 = rOFDM0_XDAGCCore2;
pHalData->PHYRegDef[RF_PATH_A].rfRxIQImbalance = rOFDM0_XARxIQImbalance;
pHalData->PHYRegDef[RF_PATH_B].rfRxIQImbalance = rOFDM0_XBRxIQImbalance;
pHalData->PHYRegDef[RF_PATH_C].rfRxIQImbalance = rOFDM0_XCRxIQImbalance;
pHalData->PHYRegDef[RF_PATH_D].rfRxIQImbalance = rOFDM0_XDRxIQImbalance;
pHalData->PHYRegDef[RF_PATH_A].rfRxAFE = rOFDM0_XARxAFE;
pHalData->PHYRegDef[RF_PATH_B].rfRxAFE = rOFDM0_XBRxAFE;
pHalData->PHYRegDef[RF_PATH_C].rfRxAFE = rOFDM0_XCRxAFE;
pHalData->PHYRegDef[RF_PATH_D].rfRxAFE = rOFDM0_XDRxAFE;
pHalData->PHYRegDef[RF_PATH_A].rfTxIQImbalance = rOFDM0_XATxIQImbalance;
pHalData->PHYRegDef[RF_PATH_B].rfTxIQImbalance = rOFDM0_XBTxIQImbalance;
pHalData->PHYRegDef[RF_PATH_C].rfTxIQImbalance = rOFDM0_XCTxIQImbalance;
pHalData->PHYRegDef[RF_PATH_D].rfTxIQImbalance = rOFDM0_XDTxIQImbalance;
pHalData->PHYRegDef[RF_PATH_A].rfTxAFE = rOFDM0_XATxAFE;
pHalData->PHYRegDef[RF_PATH_B].rfTxAFE = rOFDM0_XBTxAFE;
pHalData->PHYRegDef[RF_PATH_C].rfTxAFE = rOFDM0_XCTxAFE;
pHalData->PHYRegDef[RF_PATH_D].rfTxAFE = rOFDM0_XDTxAFE;
pHalData->PHYRegDef[RF_PATH_A].rfLSSIReadBack = rFPGA0_XA_LSSIReadBack;
pHalData->PHYRegDef[RF_PATH_B].rfLSSIReadBack = rFPGA0_XB_LSSIReadBack;
pHalData->PHYRegDef[RF_PATH_C].rfLSSIReadBack = rFPGA0_XC_LSSIReadBack;
pHalData->PHYRegDef[RF_PATH_D].rfLSSIReadBack = rFPGA0_XD_LSSIReadBack;
pHalData->PHYRegDef[RF_PATH_A].rfLSSIReadBackPi = TransceiverA_HSPI_Readback;
pHalData->PHYRegDef[RF_PATH_B].rfLSSIReadBackPi = TransceiverB_HSPI_Readback;
}
void storePwrIndexDiffRateOffset(struct adapter *Adapter, u32 RegAddr, u32 BitMask, u32 Data)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
if (RegAddr == rTxAGC_A_Rate18_06)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][0] = Data;
if (RegAddr == rTxAGC_A_Rate54_24)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][1] = Data;
if (RegAddr == rTxAGC_A_CCK1_Mcs32)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][6] = Data;
if (RegAddr == rTxAGC_B_CCK11_A_CCK2_11 && BitMask == 0xffffff00)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][7] = Data;
if (RegAddr == rTxAGC_A_Mcs03_Mcs00)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][2] = Data;
if (RegAddr == rTxAGC_A_Mcs07_Mcs04)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][3] = Data;
if (RegAddr == rTxAGC_A_Mcs11_Mcs08)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][4] = Data;
if (RegAddr == rTxAGC_A_Mcs15_Mcs12) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][5] = Data;
if (pHalData->rf_type == RF_1T1R)
pHalData->pwrGroupCnt++;
}
if (RegAddr == rTxAGC_B_Rate18_06)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][8] = Data;
if (RegAddr == rTxAGC_B_Rate54_24)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][9] = Data;
if (RegAddr == rTxAGC_B_CCK1_55_Mcs32)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][14] = Data;
if (RegAddr == rTxAGC_B_CCK11_A_CCK2_11 && BitMask == 0x000000ff)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][15] = Data;
if (RegAddr == rTxAGC_B_Mcs03_Mcs00)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][10] = Data;
if (RegAddr == rTxAGC_B_Mcs07_Mcs04)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][11] = Data;
if (RegAddr == rTxAGC_B_Mcs11_Mcs08)
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][12] = Data;
if (RegAddr == rTxAGC_B_Mcs15_Mcs12) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][13] = Data;
if (pHalData->rf_type != RF_1T1R)
pHalData->pwrGroupCnt++;
}
}
static int phy_BB8188E_Config_ParaFile(struct adapter *Adapter)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(Adapter);
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
int rtStatus = _SUCCESS;
if (HAL_STATUS_FAILURE == ODM_ConfigBBWithHeaderFile(&pHalData->odmpriv, CONFIG_BB_PHY_REG))
rtStatus = _FAIL;
if (rtStatus != _SUCCESS)
goto phy_BB8190_Config_ParaFile_Fail;
if (!pEEPROM->bautoload_fail_flag) {
pHalData->pwrGroupCnt = 0;
if (HAL_STATUS_FAILURE == ODM_ConfigBBWithHeaderFile(&pHalData->odmpriv, CONFIG_BB_PHY_REG_PG))
rtStatus = _FAIL;
}
if (rtStatus != _SUCCESS)
goto phy_BB8190_Config_ParaFile_Fail;
if (HAL_STATUS_FAILURE == ODM_ConfigBBWithHeaderFile(&pHalData->odmpriv, CONFIG_BB_AGC_TAB))
rtStatus = _FAIL;
if (rtStatus != _SUCCESS)
goto phy_BB8190_Config_ParaFile_Fail;
phy_BB8190_Config_ParaFile_Fail:
return rtStatus;
}
int
PHY_BBConfig8188E(
struct adapter *Adapter
)
{
int rtStatus = _SUCCESS;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u32 RegVal;
u8 CrystalCap;
phy_InitBBRFRegisterDefinition(Adapter);
RegVal = rtw_read16(Adapter, REG_SYS_FUNC_EN);
rtw_write16(Adapter, REG_SYS_FUNC_EN, (u16)(RegVal|BIT13|BIT0|BIT1));
rtw_write8(Adapter, REG_RF_CTRL, RF_EN|RF_RSTB|RF_SDMRSTB);
rtw_write8(Adapter, REG_SYS_FUNC_EN, FEN_USBA | FEN_USBD | FEN_BB_GLB_RSTn | FEN_BBRSTB);
rtStatus = phy_BB8188E_Config_ParaFile(Adapter);
CrystalCap = pHalData->CrystalCap & 0x3F;
PHY_SetBBReg(Adapter, REG_AFE_XTAL_CTRL, 0x7ff800, (CrystalCap | (CrystalCap << 6)));
return rtStatus;
}
int PHY_RFConfig8188E(struct adapter *Adapter)
{
int rtStatus = _SUCCESS;
rtStatus = PHY_RF6052_Config8188E(Adapter);
return rtStatus;
}
static void getTxPowerIndex88E(struct adapter *Adapter, u8 channel, u8 *cckPowerLevel,
u8 *ofdmPowerLevel, u8 *BW20PowerLevel,
u8 *BW40PowerLevel)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u8 index = (channel - 1);
u8 TxCount = 0, path_nums;
if ((RF_1T2R == pHalData->rf_type) || (RF_1T1R == pHalData->rf_type))
path_nums = 1;
else
path_nums = 2;
for (TxCount = 0; TxCount < path_nums; TxCount++) {
if (TxCount == RF_PATH_A) {
cckPowerLevel[TxCount] = pHalData->Index24G_CCK_Base[TxCount][index];
ofdmPowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->OFDM_24G_Diff[TxCount][RF_PATH_A];
BW20PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[TxCount][RF_PATH_A];
BW40PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[TxCount][index];
} else if (TxCount == RF_PATH_B) {
cckPowerLevel[TxCount] = pHalData->Index24G_CCK_Base[TxCount][index];
ofdmPowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[TxCount][index];
BW20PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[TxCount][RF_PATH_A]+
pHalData->BW20_24G_Diff[TxCount][index];
BW40PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[TxCount][index];
} else if (TxCount == RF_PATH_C) {
cckPowerLevel[TxCount] = pHalData->Index24G_CCK_Base[TxCount][index];
ofdmPowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_B][index]+
pHalData->BW20_24G_Diff[TxCount][index];
BW20PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_B][index]+
pHalData->BW20_24G_Diff[TxCount][index];
BW40PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[TxCount][index];
} else if (TxCount == RF_PATH_D) {
cckPowerLevel[TxCount] = pHalData->Index24G_CCK_Base[TxCount][index];
ofdmPowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_B][index]+
pHalData->BW20_24G_Diff[RF_PATH_C][index]+
pHalData->BW20_24G_Diff[TxCount][index];
BW20PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_A][index]+
pHalData->BW20_24G_Diff[RF_PATH_B][index]+
pHalData->BW20_24G_Diff[RF_PATH_C][index]+
pHalData->BW20_24G_Diff[TxCount][index];
BW40PowerLevel[TxCount] = pHalData->Index24G_BW40_Base[TxCount][index];
}
}
}
static void phy_PowerIndexCheck88E(struct adapter *Adapter, u8 channel, u8 *cckPowerLevel,
u8 *ofdmPowerLevel, u8 *BW20PowerLevel, u8 *BW40PowerLevel)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
pHalData->CurrentCckTxPwrIdx = cckPowerLevel[0];
pHalData->CurrentOfdm24GTxPwrIdx = ofdmPowerLevel[0];
pHalData->CurrentBW2024GTxPwrIdx = BW20PowerLevel[0];
pHalData->CurrentBW4024GTxPwrIdx = BW40PowerLevel[0];
}
void
PHY_SetTxPowerLevel8188E(
struct adapter *Adapter,
u8 channel
)
{
u8 cckPowerLevel[MAX_TX_COUNT] = {0};
u8 ofdmPowerLevel[MAX_TX_COUNT] = {0};
u8 BW20PowerLevel[MAX_TX_COUNT] = {0};
u8 BW40PowerLevel[MAX_TX_COUNT] = {0};
getTxPowerIndex88E(Adapter, channel, &cckPowerLevel[0], &ofdmPowerLevel[0], &BW20PowerLevel[0], &BW40PowerLevel[0]);
phy_PowerIndexCheck88E(Adapter, channel, &cckPowerLevel[0], &ofdmPowerLevel[0], &BW20PowerLevel[0], &BW40PowerLevel[0]);
rtl8188e_PHY_RF6052SetCckTxPower(Adapter, &cckPowerLevel[0]);
rtl8188e_PHY_RF6052SetOFDMTxPower(Adapter, &ofdmPowerLevel[0], &BW20PowerLevel[0], &BW40PowerLevel[0], channel);
}
static void
_PHY_SetBWMode92C(
struct adapter *Adapter
)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u8 regBwOpMode;
u8 regRRSR_RSC;
if (pHalData->rf_chip == RF_PSEUDO_11N)
return;
if (pHalData->rf_chip == RF_8225)
return;
if (Adapter->bDriverStopped)
return;
regBwOpMode = rtw_read8(Adapter, REG_BWOPMODE);
regRRSR_RSC = rtw_read8(Adapter, REG_RRSR+2);
switch (pHalData->CurrentChannelBW) {
case HT_CHANNEL_WIDTH_20:
regBwOpMode |= BW_OPMODE_20MHZ;
rtw_write8(Adapter, REG_BWOPMODE, regBwOpMode);
break;
case HT_CHANNEL_WIDTH_40:
regBwOpMode &= ~BW_OPMODE_20MHZ;
rtw_write8(Adapter, REG_BWOPMODE, regBwOpMode);
regRRSR_RSC = (regRRSR_RSC&0x90) | (pHalData->nCur40MhzPrimeSC<<5);
rtw_write8(Adapter, REG_RRSR+2, regRRSR_RSC);
break;
default:
break;
}
switch (pHalData->CurrentChannelBW) {
case HT_CHANNEL_WIDTH_20:
PHY_SetBBReg(Adapter, rFPGA0_RFMOD, bRFMOD, 0x0);
PHY_SetBBReg(Adapter, rFPGA1_RFMOD, bRFMOD, 0x0);
break;
case HT_CHANNEL_WIDTH_40:
PHY_SetBBReg(Adapter, rFPGA0_RFMOD, bRFMOD, 0x1);
PHY_SetBBReg(Adapter, rFPGA1_RFMOD, bRFMOD, 0x1);
PHY_SetBBReg(Adapter, rCCK0_System, bCCKSideBand, (pHalData->nCur40MhzPrimeSC>>1));
PHY_SetBBReg(Adapter, rOFDM1_LSTF, 0xC00, pHalData->nCur40MhzPrimeSC);
PHY_SetBBReg(Adapter, 0x818, (BIT26 | BIT27),
(pHalData->nCur40MhzPrimeSC == HAL_PRIME_CHNL_OFFSET_LOWER) ? 2 : 1);
break;
default:
break;
}
switch (pHalData->rf_chip) {
case RF_8225:
break;
case RF_8256:
break;
case RF_8258:
break;
case RF_PSEUDO_11N:
break;
case RF_6052:
rtl8188e_PHY_RF6052SetBandwidth(Adapter, pHalData->CurrentChannelBW);
break;
default:
break;
}
}
void PHY_SetBWMode8188E(struct adapter *Adapter, enum ht_channel_width Bandwidth,
unsigned char Offset)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
enum ht_channel_width tmpBW = pHalData->CurrentChannelBW;
pHalData->CurrentChannelBW = Bandwidth;
pHalData->nCur40MhzPrimeSC = Offset;
if ((!Adapter->bDriverStopped) && (!Adapter->bSurpriseRemoved))
_PHY_SetBWMode92C(Adapter);
else
pHalData->CurrentChannelBW = tmpBW;
}
static void _PHY_SwChnl8192C(struct adapter *Adapter, u8 channel)
{
u8 eRFPath;
u32 param1, param2;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
if (Adapter->bNotifyChannelChange)
DBG_88E("[%s] ch = %d\n", __func__, channel);
PHY_SetTxPowerLevel8188E(Adapter, channel);
param1 = RF_CHNLBW;
param2 = channel;
for (eRFPath = 0; eRFPath < pHalData->NumTotalRFPath; eRFPath++) {
pHalData->RfRegChnlVal[eRFPath] = ((pHalData->RfRegChnlVal[eRFPath] & 0xfffffc00) | param2);
PHY_SetRFReg(Adapter, (enum rf_radio_path)eRFPath, param1, bRFRegOffsetMask, pHalData->RfRegChnlVal[eRFPath]);
}
}
void PHY_SwChnl8188E(struct adapter *Adapter, u8 channel)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u8 tmpchannel = pHalData->CurrentChannel;
bool bResult = true;
if (pHalData->rf_chip == RF_PSEUDO_11N)
return;
if (channel == 0)
channel = 1;
pHalData->CurrentChannel = channel;
if ((!Adapter->bDriverStopped) && (!Adapter->bSurpriseRemoved)) {
_PHY_SwChnl8192C(Adapter, channel);
if (bResult)
;
else
pHalData->CurrentChannel = tmpchannel;
} else {
pHalData->CurrentChannel = tmpchannel;
}
}
