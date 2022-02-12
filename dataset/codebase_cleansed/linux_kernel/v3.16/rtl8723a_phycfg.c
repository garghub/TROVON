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
PHY_QueryBBReg(struct rtw_adapter *Adapter, u32 RegAddr, u32 BitMask)
{
u32 ReturnValue = 0, OriginalValue, BitShift;
OriginalValue = rtl8723au_read32(Adapter, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
ReturnValue = (OriginalValue & BitMask) >> BitShift;
return ReturnValue;
}
void
PHY_SetBBReg(struct rtw_adapter *Adapter, u32 RegAddr, u32 BitMask, u32 Data)
{
u32 OriginalValue, BitShift;
if (BitMask != bMaskDWord) {
OriginalValue = rtl8723au_read32(Adapter, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
Data = ((OriginalValue & (~BitMask)) | (Data << BitShift));
}
rtl8723au_write32(Adapter, RegAddr, Data);
}
static u32
phy_RFSerialRead(struct rtw_adapter *Adapter, enum RF_RADIO_PATH eRFPath,
u32 Offset)
{
u32 retValue = 0;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct bb_reg_define *pPhyReg = &pHalData->PHYRegDef[eRFPath];
u32 NewOffset;
u32 tmplong, tmplong2;
u8 RfPiEnable = 0;
Offset &= 0x3f;
NewOffset = Offset;
tmplong = PHY_QueryBBReg(Adapter, rFPGA0_XA_HSSIParameter2, bMaskDWord);
if (eRFPath == RF_PATH_A)
tmplong2 = tmplong;
else
tmplong2 = PHY_QueryBBReg(Adapter, pPhyReg->rfHSSIPara2,
bMaskDWord);
tmplong2 = (tmplong2 & ~bLSSIReadAddress) |
(NewOffset << 23) | bLSSIReadEdge;
PHY_SetBBReg(Adapter, rFPGA0_XA_HSSIParameter2,
bMaskDWord, tmplong & (~bLSSIReadEdge));
udelay(10);
PHY_SetBBReg(Adapter, pPhyReg->rfHSSIPara2, bMaskDWord, tmplong2);
udelay(100);
PHY_SetBBReg(Adapter, rFPGA0_XA_HSSIParameter2, bMaskDWord,
tmplong | bLSSIReadEdge);
udelay(10);
if (eRFPath == RF_PATH_A)
RfPiEnable = (u8)PHY_QueryBBReg(Adapter,
rFPGA0_XA_HSSIParameter1,
BIT(8));
else if (eRFPath == RF_PATH_B)
RfPiEnable = (u8)PHY_QueryBBReg(Adapter,
rFPGA0_XB_HSSIParameter1,
BIT(8));
if (RfPiEnable) {
retValue = PHY_QueryBBReg(Adapter, pPhyReg->rfLSSIReadBackPi,
bLSSIReadBackData);
} else {
retValue = PHY_QueryBBReg(Adapter, pPhyReg->rfLSSIReadBack,
bLSSIReadBackData);
}
return retValue;
}
static void
phy_RFSerialWrite(struct rtw_adapter *Adapter, enum RF_RADIO_PATH eRFPath,
u32 Offset, u32 Data)
{
u32 DataAndAddr = 0;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct bb_reg_define *pPhyReg = &pHalData->PHYRegDef[eRFPath];
u32 NewOffset;
Offset &= 0x3f;
NewOffset = Offset;
DataAndAddr = ((NewOffset<<20) | (Data&0x000fffff)) & 0x0fffffff;
PHY_SetBBReg(Adapter, pPhyReg->rf3wireOffset, bMaskDWord, DataAndAddr);
}
u32
PHY_QueryRFReg(struct rtw_adapter *Adapter, enum RF_RADIO_PATH eRFPath,
u32 RegAddr, u32 BitMask)
{
u32 Original_Value, Readback_Value, BitShift;
Original_Value = phy_RFSerialRead(Adapter, eRFPath, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
Readback_Value = (Original_Value & BitMask) >> BitShift;
return Readback_Value;
}
void
PHY_SetRFReg(struct rtw_adapter *Adapter, enum RF_RADIO_PATH eRFPath,
u32 RegAddr, u32 BitMask, u32 Data)
{
u32 Original_Value, BitShift;
if (BitMask != bRFRegOffsetMask) {
Original_Value = phy_RFSerialRead(Adapter, eRFPath, RegAddr);
BitShift = phy_CalculateBitShift(BitMask);
Data = ((Original_Value & (~BitMask)) | (Data << BitShift));
}
phy_RFSerialWrite(Adapter, eRFPath, RegAddr, Data);
}
int PHY_MACConfig8723A(struct rtw_adapter *Adapter)
{
int rtStatus = _SUCCESS;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
bool is92C = IS_92C_SERIAL(pHalData->VersionID);
if (ODM_ConfigMACWithHeaderFile23a(&pHalData->odmpriv) == _FAIL)
rtStatus = _FAIL;
rtl8723au_write8(Adapter, REG_MAX_AGGR_NUM, 0x0A);
if (is92C && (BOARD_USB_DONGLE == pHalData->BoardType))
rtl8723au_write8(Adapter, 0x40, 0x04);
return rtStatus;
}
static void
phy_InitBBRFRegisterDefinition(struct rtw_adapter *Adapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
pHalData->PHYRegDef[RF_PATH_A].rfintfs = rFPGA0_XAB_RFInterfaceSW;
pHalData->PHYRegDef[RF_PATH_B].rfintfs = rFPGA0_XAB_RFInterfaceSW;
pHalData->PHYRegDef[RF_PATH_A].rfintfi = rFPGA0_XAB_RFInterfaceRB;
pHalData->PHYRegDef[RF_PATH_B].rfintfi = rFPGA0_XAB_RFInterfaceRB;
pHalData->PHYRegDef[RF_PATH_A].rfintfo = rFPGA0_XA_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_B].rfintfo = rFPGA0_XB_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_A].rfintfe = rFPGA0_XA_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_B].rfintfe = rFPGA0_XB_RFInterfaceOE;
pHalData->PHYRegDef[RF_PATH_A].rf3wireOffset = rFPGA0_XA_LSSIParameter;
pHalData->PHYRegDef[RF_PATH_B].rf3wireOffset = rFPGA0_XB_LSSIParameter;
pHalData->PHYRegDef[RF_PATH_A].rfLSSI_Select = rFPGA0_XAB_RFParameter;
pHalData->PHYRegDef[RF_PATH_B].rfLSSI_Select = rFPGA0_XAB_RFParameter;
pHalData->PHYRegDef[RF_PATH_A].rfTxGainStage = rFPGA0_TxGainStage;
pHalData->PHYRegDef[RF_PATH_B].rfTxGainStage = rFPGA0_TxGainStage;
pHalData->PHYRegDef[RF_PATH_A].rfHSSIPara1 = rFPGA0_XA_HSSIParameter1;
pHalData->PHYRegDef[RF_PATH_B].rfHSSIPara1 = rFPGA0_XB_HSSIParameter1;
pHalData->PHYRegDef[RF_PATH_A].rfHSSIPara2 = rFPGA0_XA_HSSIParameter2;
pHalData->PHYRegDef[RF_PATH_B].rfHSSIPara2 = rFPGA0_XB_HSSIParameter2;
pHalData->PHYRegDef[RF_PATH_A].rfSwitchControl =
rFPGA0_XAB_SwitchControl;
pHalData->PHYRegDef[RF_PATH_B].rfSwitchControl =
rFPGA0_XAB_SwitchControl;
pHalData->PHYRegDef[RF_PATH_A].rfAGCControl1 = rOFDM0_XAAGCCore1;
pHalData->PHYRegDef[RF_PATH_B].rfAGCControl1 = rOFDM0_XBAGCCore1;
pHalData->PHYRegDef[RF_PATH_A].rfAGCControl2 = rOFDM0_XAAGCCore2;
pHalData->PHYRegDef[RF_PATH_B].rfAGCControl2 = rOFDM0_XBAGCCore2;
pHalData->PHYRegDef[RF_PATH_A].rfRxIQImbalance = rOFDM0_XARxIQImbalance;
pHalData->PHYRegDef[RF_PATH_B].rfRxIQImbalance = rOFDM0_XBRxIQImbalance;
pHalData->PHYRegDef[RF_PATH_A].rfRxAFE = rOFDM0_XARxAFE;
pHalData->PHYRegDef[RF_PATH_B].rfRxAFE = rOFDM0_XBRxAFE;
pHalData->PHYRegDef[RF_PATH_A].rfTxIQImbalance = rOFDM0_XATxIQImbalance;
pHalData->PHYRegDef[RF_PATH_B].rfTxIQImbalance = rOFDM0_XBTxIQImbalance;
pHalData->PHYRegDef[RF_PATH_A].rfTxAFE = rOFDM0_XATxAFE;
pHalData->PHYRegDef[RF_PATH_B].rfTxAFE = rOFDM0_XBTxAFE;
pHalData->PHYRegDef[RF_PATH_A].rfLSSIReadBack = rFPGA0_XA_LSSIReadBack;
pHalData->PHYRegDef[RF_PATH_B].rfLSSIReadBack = rFPGA0_XB_LSSIReadBack;
pHalData->PHYRegDef[RF_PATH_A].rfLSSIReadBackPi =
TransceiverA_HSPI_Readback;
pHalData->PHYRegDef[RF_PATH_B].rfLSSIReadBackPi =
TransceiverB_HSPI_Readback;
}
static void
storePwrIndexDiffRateOffset(struct rtw_adapter *Adapter, u32 RegAddr,
u32 BitMask, u32 Data)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
if (RegAddr == rTxAGC_A_Rate18_06) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][0] = Data;
}
if (RegAddr == rTxAGC_A_Rate54_24) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][1] = Data;
}
if (RegAddr == rTxAGC_A_CCK1_Mcs32) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][6] = Data;
}
if (RegAddr == rTxAGC_B_CCK11_A_CCK2_11 && BitMask == 0xffffff00) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][7] = Data;
}
if (RegAddr == rTxAGC_A_Mcs03_Mcs00) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][2] = Data;
}
if (RegAddr == rTxAGC_A_Mcs07_Mcs04) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][3] = Data;
}
if (RegAddr == rTxAGC_A_Mcs11_Mcs08) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][4] = Data;
}
if (RegAddr == rTxAGC_A_Mcs15_Mcs12) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][5] = Data;
}
if (RegAddr == rTxAGC_B_Rate18_06) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][8] = Data;
}
if (RegAddr == rTxAGC_B_Rate54_24) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][9] = Data;
}
if (RegAddr == rTxAGC_B_CCK1_55_Mcs32) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][14] = Data;
}
if (RegAddr == rTxAGC_B_CCK11_A_CCK2_11 && BitMask == 0x000000ff) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][15] = Data;
}
if (RegAddr == rTxAGC_B_Mcs03_Mcs00) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][10] = Data;
}
if (RegAddr == rTxAGC_B_Mcs07_Mcs04) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][11] = Data;
}
if (RegAddr == rTxAGC_B_Mcs11_Mcs08) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][12] = Data;
}
if (RegAddr == rTxAGC_B_Mcs15_Mcs12) {
pHalData->MCSTxPowerLevelOriginalOffset[pHalData->pwrGroupCnt][13] = Data;
pHalData->pwrGroupCnt++;
}
}
static int
phy_ConfigBBWithPgHeaderFile(struct rtw_adapter *Adapter, u8 ConfigType)
{
int i;
u32 *Rtl819XPHY_REGArray_Table_PG;
u16 PHY_REGArrayPGLen;
PHY_REGArrayPGLen = Rtl8723_PHY_REG_Array_PGLength;
Rtl819XPHY_REGArray_Table_PG = (u32 *)Rtl8723_PHY_REG_Array_PG;
if (ConfigType == BaseBand_Config_PHY_REG) {
for (i = 0; i < PHY_REGArrayPGLen; i = i + 3) {
storePwrIndexDiffRateOffset(Adapter,
Rtl819XPHY_REGArray_Table_PG[i],
Rtl819XPHY_REGArray_Table_PG[i+1],
Rtl819XPHY_REGArray_Table_PG[i+2]);
}
}
return _SUCCESS;
}
static void
phy_BB8192C_Config_1T(struct rtw_adapter *Adapter)
{
PHY_SetBBReg(Adapter, rFPGA0_TxInfo, 0x3, 0x2);
PHY_SetBBReg(Adapter, rFPGA1_TxInfo, 0x300033, 0x200022);
PHY_SetBBReg(Adapter, rCCK0_AFESetting, bMaskByte3, 0x45);
PHY_SetBBReg(Adapter, rOFDM0_TRxPathEnable, bMaskByte0, 0x23);
PHY_SetBBReg(Adapter, rOFDM0_AGCParameter1, 0x30, 0x1);
PHY_SetBBReg(Adapter, 0xe74, 0x0c000000, 0x2);
PHY_SetBBReg(Adapter, 0xe78, 0x0c000000, 0x2);
PHY_SetBBReg(Adapter, 0xe7c, 0x0c000000, 0x2);
PHY_SetBBReg(Adapter, 0xe80, 0x0c000000, 0x2);
PHY_SetBBReg(Adapter, 0xe88, 0x0c000000, 0x2);
}
static int
phy_BB8723a_Config_ParaFile(struct rtw_adapter *Adapter)
{
struct eeprom_priv *pEEPROM = GET_EEPROM_EFUSE_PRIV(Adapter);
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
int rtStatus = _SUCCESS;
if (ODM_ConfigBBWithHeaderFile23a(&pHalData->odmpriv,
CONFIG_BB_PHY_REG) == _FAIL)
rtStatus = _FAIL;
if (rtStatus != _SUCCESS)
goto phy_BB8190_Config_ParaFile_Fail;
if (pHalData->rf_type == RF_1T2R) {
phy_BB8192C_Config_1T(Adapter);
DBG_8723A("phy_BB8723a_Config_ParaFile():Config to 1T!!\n");
}
if (pEEPROM->bautoload_fail_flag == false) {
pHalData->pwrGroupCnt = 0;
rtStatus = phy_ConfigBBWithPgHeaderFile(Adapter,
BaseBand_Config_PHY_REG);
}
if (rtStatus != _SUCCESS)
goto phy_BB8190_Config_ParaFile_Fail;
if (ODM_ConfigBBWithHeaderFile23a(&pHalData->odmpriv,
CONFIG_BB_AGC_TAB) == _FAIL)
rtStatus = _FAIL;
phy_BB8190_Config_ParaFile_Fail:
return rtStatus;
}
int
PHY_BBConfig8723A(struct rtw_adapter *Adapter)
{
int rtStatus = _SUCCESS;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
u8 TmpU1B = 0;
u8 CrystalCap;
phy_InitBBRFRegisterDefinition(Adapter);
TmpU1B = rtl8723au_read8(Adapter, REG_AFE_PLL_CTRL);
udelay(2);
rtl8723au_write8(Adapter, REG_AFE_PLL_CTRL, TmpU1B | BIT(1));
udelay(2);
rtl8723au_write8(Adapter, REG_AFE_PLL_CTRL+1, 0xff);
udelay(2);
TmpU1B = rtl8723au_read8(Adapter, REG_SYS_FUNC_EN);
rtl8723au_write8(Adapter, REG_SYS_FUNC_EN,
(TmpU1B | FEN_BB_GLB_RSTn | FEN_BBRSTB));
TmpU1B = rtl8723au_read8(Adapter, REG_AFE_XTAL_CTRL + 1);
rtl8723au_write8(Adapter, REG_AFE_XTAL_CTRL+1, TmpU1B & ~BIT(6));
TmpU1B = rtl8723au_read8(Adapter, REG_AFE_XTAL_CTRL+2);
rtl8723au_write8(Adapter, REG_AFE_XTAL_CTRL+2, TmpU1B & ~BIT(4));
rtl8723au_write8(Adapter, REG_RF_CTRL, 0x07);
rtStatus = phy_BB8723a_Config_ParaFile(Adapter);
if (pHalData->EEPROMVersion >= 0x01) {
CrystalCap = pHalData->CrystalCap & 0x3F;
PHY_SetBBReg(Adapter, REG_MAC_PHY_CTRL, 0xFFF000,
(CrystalCap | (CrystalCap << 6)));
}
PHY_SetBBReg(Adapter, REG_LDOA15_CTRL, bMaskDWord, 0x01572505);
return rtStatus;
}
int
PHY_RFConfig8723A(struct rtw_adapter *Adapter)
{
int rtStatus = _SUCCESS;
rtStatus = PHY_RF6052_Config8723A(Adapter);
return rtStatus;
}
static void getTxPowerIndex(struct rtw_adapter *Adapter,
u8 channel, u8 *cckPowerLevel, u8 *ofdmPowerLevel)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
u8 index = (channel - 1);
cckPowerLevel[RF_PATH_A] = pHalData->TxPwrLevelCck[RF_PATH_A][index];
cckPowerLevel[RF_PATH_B] = pHalData->TxPwrLevelCck[RF_PATH_B][index];
if (GET_RF_TYPE(Adapter) == RF_1T2R || GET_RF_TYPE(Adapter) == RF_1T1R) {
ofdmPowerLevel[RF_PATH_A] =
pHalData->TxPwrLevelHT40_1S[RF_PATH_A][index];
ofdmPowerLevel[RF_PATH_B] =
pHalData->TxPwrLevelHT40_1S[RF_PATH_B][index];
} else if (GET_RF_TYPE(Adapter) == RF_2T2R) {
ofdmPowerLevel[RF_PATH_A] =
pHalData->TxPwrLevelHT40_2S[RF_PATH_A][index];
ofdmPowerLevel[RF_PATH_B] =
pHalData->TxPwrLevelHT40_2S[RF_PATH_B][index];
}
}
static void ccxPowerIndexCheck(struct rtw_adapter *Adapter, u8 channel,
u8 *cckPowerLevel, u8 *ofdmPowerLevel)
{
}
void PHY_SetTxPowerLevel8723A(struct rtw_adapter *Adapter, u8 channel)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
u8 cckPowerLevel[2], ofdmPowerLevel[2];
if (pHalData->bTXPowerDataReadFromEEPORM == false)
return;
getTxPowerIndex(Adapter, channel, &cckPowerLevel[0],
&ofdmPowerLevel[0]);
ccxPowerIndexCheck(Adapter, channel, &cckPowerLevel[0],
&ofdmPowerLevel[0]);
rtl823a_phy_rf6052setccktxpower(Adapter, &cckPowerLevel[0]);
rtl8723a_PHY_RF6052SetOFDMTxPower(Adapter, &ofdmPowerLevel[0], channel);
}
static void
_PHY_SetBWMode23a92C(struct rtw_adapter *Adapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
u8 regBwOpMode;
u8 regRRSR_RSC;
if (pHalData->rf_chip == RF_PSEUDO_11N)
return;
if (pHalData->rf_chip == RF_8225)
return;
if (Adapter->bDriverStopped)
return;
regBwOpMode = rtl8723au_read8(Adapter, REG_BWOPMODE);
regRRSR_RSC = rtl8723au_read8(Adapter, REG_RRSR+2);
switch (pHalData->CurrentChannelBW) {
case HT_CHANNEL_WIDTH_20:
regBwOpMode |= BW_OPMODE_20MHZ;
rtl8723au_write8(Adapter, REG_BWOPMODE, regBwOpMode);
break;
case HT_CHANNEL_WIDTH_40:
regBwOpMode &= ~BW_OPMODE_20MHZ;
rtl8723au_write8(Adapter, REG_BWOPMODE, regBwOpMode);
regRRSR_RSC = (regRRSR_RSC & 0x90) |
(pHalData->nCur40MhzPrimeSC << 5);
rtl8723au_write8(Adapter, REG_RRSR+2, regRRSR_RSC);
break;
default:
break;
}
switch (pHalData->CurrentChannelBW) {
case HT_CHANNEL_WIDTH_20:
PHY_SetBBReg(Adapter, rFPGA0_RFMOD, bRFMOD, 0x0);
PHY_SetBBReg(Adapter, rFPGA1_RFMOD, bRFMOD, 0x0);
PHY_SetBBReg(Adapter, rFPGA0_AnalogParameter2, BIT(10), 1);
break;
case HT_CHANNEL_WIDTH_40:
PHY_SetBBReg(Adapter, rFPGA0_RFMOD, bRFMOD, 0x1);
PHY_SetBBReg(Adapter, rFPGA1_RFMOD, bRFMOD, 0x1);
PHY_SetBBReg(Adapter, rCCK0_System, bCCKSideBand,
(pHalData->nCur40MhzPrimeSC >> 1));
PHY_SetBBReg(Adapter, rOFDM1_LSTF, 0xC00,
pHalData->nCur40MhzPrimeSC);
PHY_SetBBReg(Adapter, rFPGA0_AnalogParameter2, BIT(10), 0);
PHY_SetBBReg(Adapter, 0x818, BIT(26) | BIT(27),
(pHalData->nCur40MhzPrimeSC ==
HAL_PRIME_CHNL_OFFSET_LOWER) ? 2:1);
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
rtl8723a_phy_rf6052set_bw(Adapter, pHalData->CurrentChannelBW);
break;
default:
break;
}
}
void
PHY_SetBWMode23a8723A(struct rtw_adapter *Adapter,
enum ht_channel_width Bandwidth, unsigned char Offset)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
enum ht_channel_width tmpBW = pHalData->CurrentChannelBW;
pHalData->CurrentChannelBW = Bandwidth;
pHalData->nCur40MhzPrimeSC = Offset;
if ((!Adapter->bDriverStopped) && (!Adapter->bSurpriseRemoved))
_PHY_SetBWMode23a92C(Adapter);
else
pHalData->CurrentChannelBW = tmpBW;
}
static void _PHY_SwChnl8723A(struct rtw_adapter *Adapter, u8 channel)
{
u8 eRFPath;
u32 param1, param2;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
if (Adapter->bNotifyChannelChange)
DBG_8723A("[%s] ch = %d\n", __func__, channel);
PHY_SetTxPowerLevel8723A(Adapter, channel);
param1 = RF_CHNLBW;
param2 = channel;
for (eRFPath = 0; eRFPath < pHalData->NumTotalRFPath; eRFPath++) {
pHalData->RfRegChnlVal[eRFPath] =
(pHalData->RfRegChnlVal[eRFPath] & 0xfffffc00) | param2;
PHY_SetRFReg(Adapter, (enum RF_RADIO_PATH)eRFPath, param1,
bRFRegOffsetMask, pHalData->RfRegChnlVal[eRFPath]);
}
}
void PHY_SwChnl8723A(struct rtw_adapter *Adapter, u8 channel)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
u8 tmpchannel = pHalData->CurrentChannel;
bool result = true;
if (pHalData->rf_chip == RF_PSEUDO_11N) {
return;
}
if (channel == 0)
channel = 1;
pHalData->CurrentChannel = channel;
if ((!Adapter->bDriverStopped) && (!Adapter->bSurpriseRemoved)) {
_PHY_SwChnl8723A(Adapter, channel);
if (!result)
pHalData->CurrentChannel = tmpchannel;
} else {
pHalData->CurrentChannel = tmpchannel;
}
}
