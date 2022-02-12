void rtl8723a_phy_rf6052set_bw(struct rtw_adapter *Adapter,
enum ht_channel_width Bandwidth)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
switch (Bandwidth) {
case HT_CHANNEL_WIDTH_20:
pHalData->RfRegChnlVal[0] =
(pHalData->RfRegChnlVal[0] & 0xfffff3ff) | 0x0400;
PHY_SetRFReg(Adapter, RF_PATH_A, RF_CHNLBW, bRFRegOffsetMask,
pHalData->RfRegChnlVal[0]);
break;
case HT_CHANNEL_WIDTH_40:
pHalData->RfRegChnlVal[0] =
(pHalData->RfRegChnlVal[0] & 0xfffff3ff);
PHY_SetRFReg(Adapter, RF_PATH_A, RF_CHNLBW, bRFRegOffsetMask,
pHalData->RfRegChnlVal[0]);
break;
default:
break;
}
}
void rtl823a_phy_rf6052setccktxpower(struct rtw_adapter *Adapter,
u8 *pPowerlevel)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
struct mlme_ext_priv *pmlmeext = &Adapter->mlmeextpriv;
u32 TxAGC[2] = {0, 0}, tmpval = 0;
u8 idx1, idx2;
u8 *ptr;
if (pmlmeext->sitesurvey_res.state == SCAN_PROCESS) {
TxAGC[RF_PATH_A] = 0x3f3f3f3f;
TxAGC[RF_PATH_B] = 0x3f3f3f3f;
for (idx1 = RF_PATH_A; idx1 <= RF_PATH_B; idx1++) {
TxAGC[idx1] = pPowerlevel[idx1] |
(pPowerlevel[idx1] << 8) |
(pPowerlevel[idx1] << 16) |
(pPowerlevel[idx1] << 24);
if (TxAGC[idx1] > 0x20 && pHalData->ExternalPA)
TxAGC[idx1] = 0x20;
}
} else {
if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_Level1) {
TxAGC[RF_PATH_A] = 0x10101010;
TxAGC[RF_PATH_B] = 0x10101010;
} else if (pdmpriv->DynamicTxHighPowerLvl ==
TxHighPwrLevel_Level2) {
TxAGC[RF_PATH_A] = 0x00000000;
TxAGC[RF_PATH_B] = 0x00000000;
} else {
for (idx1 = RF_PATH_A; idx1 <= RF_PATH_B; idx1++) {
TxAGC[idx1] = pPowerlevel[idx1] |
(pPowerlevel[idx1] << 8) |
(pPowerlevel[idx1] << 16) |
(pPowerlevel[idx1] << 24);
}
if (pHalData->EEPROMRegulatory == 0) {
tmpval = (pHalData->MCSTxPowerLevelOriginalOffset[0][6]) +
(pHalData->MCSTxPowerLevelOriginalOffset[0][7]<<8);
TxAGC[RF_PATH_A] += tmpval;
tmpval = (pHalData->MCSTxPowerLevelOriginalOffset[0][14]) +
(pHalData->MCSTxPowerLevelOriginalOffset[0][15]<<24);
TxAGC[RF_PATH_B] += tmpval;
}
}
}
for (idx1 = RF_PATH_A; idx1 <= RF_PATH_B; idx1++) {
ptr = (u8 *)(&TxAGC[idx1]);
for (idx2 = 0; idx2 < 4; idx2++) {
if (*ptr > RF6052_MAX_TX_PWR)
*ptr = RF6052_MAX_TX_PWR;
ptr++;
}
}
tmpval = TxAGC[RF_PATH_A] & 0xff;
PHY_SetBBReg(Adapter, rTxAGC_A_CCK1_Mcs32, bMaskByte1, tmpval);
tmpval = TxAGC[RF_PATH_A] >> 8;
PHY_SetBBReg(Adapter, rTxAGC_B_CCK11_A_CCK2_11, 0xffffff00, tmpval);
tmpval = TxAGC[RF_PATH_B] >> 24;
PHY_SetBBReg(Adapter, rTxAGC_B_CCK11_A_CCK2_11, bMaskByte0, tmpval);
tmpval = TxAGC[RF_PATH_B] & 0x00ffffff;
PHY_SetBBReg(Adapter, rTxAGC_B_CCK1_55_Mcs32, 0xffffff00, tmpval);
}
static void getPowerBase(struct rtw_adapter *Adapter, u8 *pPowerLevel,
u8 Channel, u32 *OfdmBase, u32 *MCSBase)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
u32 ofdm, mcs;
u8 Legacy_pwrdiff = 0;
s8 HT20_pwrdiff = 0;
u8 i, powerlevel[2];
for (i = 0; i < 2; i++) {
powerlevel[i] = pPowerLevel[i];
Legacy_pwrdiff = pHalData->TxPwrLegacyHtDiff[i][Channel-1];
ofdm = powerlevel[i] + Legacy_pwrdiff;
ofdm = ofdm << 24 | ofdm << 16 | ofdm << 8 | ofdm;
*(OfdmBase + i) = ofdm;
}
for (i = 0; i < 2; i++) {
if (pHalData->CurrentChannelBW == HT_CHANNEL_WIDTH_20) {
HT20_pwrdiff = pHalData->TxPwrHt20Diff[i][Channel-1];
powerlevel[i] += HT20_pwrdiff;
}
mcs = powerlevel[i];
mcs = mcs << 24 | mcs << 16 | mcs << 8 | mcs;
*(MCSBase + i) = mcs;
}
}
static void
getTxPowerWriteValByRegulatory(struct rtw_adapter *Adapter, u8 Channel,
u8 index, u32 *powerBase0, u32 *powerBase1,
u32 *pOutWriteVal)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
u8 i, chnlGroup = 0, pwr_diff_limit[4];
u32 writeVal, customer_limit, rf;
for (rf = 0; rf < 2; rf++) {
switch (pHalData->EEPROMRegulatory) {
case 0:
chnlGroup = 0;
writeVal = pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index+(rf?8:0)] +
((index < 2) ? powerBase0[rf] : powerBase1[rf]);
break;
case 1:
if (pHalData->pwrGroupCnt == 1)
chnlGroup = 0;
if (pHalData->pwrGroupCnt >= 3) {
if (Channel <= 3)
chnlGroup = 0;
else if (Channel >= 4 && Channel <= 9)
chnlGroup = 1;
else if (Channel > 9)
chnlGroup = 2;
if (pHalData->CurrentChannelBW ==
HT_CHANNEL_WIDTH_20)
chnlGroup++;
else
chnlGroup += 4;
}
writeVal = pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index+(rf?8:0)] +
((index < 2) ? powerBase0[rf] :
powerBase1[rf]);
break;
case 2:
writeVal = (index < 2) ? powerBase0[rf] :
powerBase1[rf];
break;
case 3:
chnlGroup = 0;
for (i = 0; i < 4; i++) {
pwr_diff_limit[i] = (u8)((pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index +
(rf ? 8 : 0)]&(0x7f << (i*8))) >> (i*8));
if (pHalData->CurrentChannelBW == HT_CHANNEL_WIDTH_40) {
if (pwr_diff_limit[i] > pHalData->PwrGroupHT40[rf][Channel-1])
pwr_diff_limit[i] = pHalData->PwrGroupHT40[rf][Channel-1];
} else {
if (pwr_diff_limit[i] > pHalData->PwrGroupHT20[rf][Channel-1])
pwr_diff_limit[i] = pHalData->PwrGroupHT20[rf][Channel-1];
}
}
customer_limit = (pwr_diff_limit[3]<<24) | (pwr_diff_limit[2]<<16) |
(pwr_diff_limit[1]<<8) | (pwr_diff_limit[0]);
writeVal = customer_limit + ((index<2)?powerBase0[rf]:powerBase1[rf]);
break;
default:
chnlGroup = 0;
writeVal = pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index+(rf?8:0)] +
((index < 2) ? powerBase0[rf] : powerBase1[rf]);
break;
}
if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_Level1)
writeVal = 0x14141414;
else if (pdmpriv->DynamicTxHighPowerLvl ==
TxHighPwrLevel_Level2)
writeVal = 0x00000000;
if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_BT1)
writeVal = writeVal - 0x06060606;
else if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_BT2)
writeVal = writeVal;
*(pOutWriteVal + rf) = writeVal;
}
}
static void writeOFDMPowerReg(struct rtw_adapter *Adapter, u8 index,
u32 *pValue)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
u16 RegOffset_A[6] = {
rTxAGC_A_Rate18_06, rTxAGC_A_Rate54_24,
rTxAGC_A_Mcs03_Mcs00, rTxAGC_A_Mcs07_Mcs04,
rTxAGC_A_Mcs11_Mcs08, rTxAGC_A_Mcs15_Mcs12
};
u16 RegOffset_B[6] = {
rTxAGC_B_Rate18_06, rTxAGC_B_Rate54_24,
rTxAGC_B_Mcs03_Mcs00, rTxAGC_B_Mcs07_Mcs04,
rTxAGC_B_Mcs11_Mcs08, rTxAGC_B_Mcs15_Mcs12
};
u8 i, rf, pwr_val[4];
u32 writeVal;
u16 RegOffset;
for (rf = 0; rf < 2; rf++) {
writeVal = pValue[rf];
for (i = 0; i < 4; i++) {
pwr_val[i] = (u8)((writeVal &
(0x7f << (i * 8))) >> (i * 8));
if (pwr_val[i] > RF6052_MAX_TX_PWR)
pwr_val[i] = RF6052_MAX_TX_PWR;
}
writeVal = pwr_val[3] << 24 | pwr_val[2] << 16 |
pwr_val[1] << 8 | pwr_val[0];
if (rf == 0)
RegOffset = RegOffset_A[index];
else
RegOffset = RegOffset_B[index];
rtl8723au_write32(Adapter, RegOffset, writeVal);
if (((pHalData->rf_type == RF_2T2R) &&
(RegOffset == rTxAGC_A_Mcs15_Mcs12 ||
RegOffset == rTxAGC_B_Mcs15_Mcs12)) ||
((pHalData->rf_type != RF_2T2R) &&
(RegOffset == rTxAGC_A_Mcs07_Mcs04 ||
RegOffset == rTxAGC_B_Mcs07_Mcs04))) {
writeVal = pwr_val[3];
if (RegOffset == rTxAGC_A_Mcs15_Mcs12 ||
RegOffset == rTxAGC_A_Mcs07_Mcs04)
RegOffset = 0xc90;
if (RegOffset == rTxAGC_B_Mcs15_Mcs12 ||
RegOffset == rTxAGC_B_Mcs07_Mcs04)
RegOffset = 0xc98;
for (i = 0; i < 3; i++) {
if (i != 2)
writeVal = (writeVal > 8) ?
(writeVal - 8) : 0;
else
writeVal = (writeVal > 6) ?
(writeVal - 6) : 0;
rtl8723au_write8(Adapter, RegOffset + i,
(u8)writeVal);
}
}
}
}
void rtl8723a_PHY_RF6052SetOFDMTxPower(struct rtw_adapter *Adapter,
u8 *pPowerLevel, u8 Channel)
{
u32 writeVal[2], powerBase0[2], powerBase1[2];
u8 index = 0;
getPowerBase(Adapter, pPowerLevel, Channel,
&powerBase0[0], &powerBase1[0]);
for (index = 0; index < 6; index++) {
getTxPowerWriteValByRegulatory(Adapter, Channel, index,
&powerBase0[0], &powerBase1[0], &writeVal[0]);
writeOFDMPowerReg(Adapter, index, &writeVal[0]);
}
}
static int phy_RF6052_Config_ParaFile(struct rtw_adapter *Adapter)
{
u32 u4RegValue = 0;
u8 eRFPath;
struct bb_reg_define *pPhyReg;
int rtStatus = _SUCCESS;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
for (eRFPath = 0; eRFPath < pHalData->NumTotalRFPath; eRFPath++) {
pPhyReg = &pHalData->PHYRegDef[eRFPath];
switch (eRFPath) {
case RF_PATH_A:
u4RegValue = PHY_QueryBBReg(Adapter, pPhyReg->rfintfs,
bRFSI_RFENV);
break;
case RF_PATH_B:
u4RegValue = PHY_QueryBBReg(Adapter, pPhyReg->rfintfs,
bRFSI_RFENV << 16);
break;
}
PHY_SetBBReg(Adapter, pPhyReg->rfintfe, bRFSI_RFENV << 16, 0x1);
udelay(1);
PHY_SetBBReg(Adapter, pPhyReg->rfintfo, bRFSI_RFENV, 0x1);
udelay(1);
PHY_SetBBReg(Adapter, pPhyReg->rfHSSIPara2, b3WireAddressLength,
0x0);
udelay(1);
PHY_SetBBReg(Adapter, pPhyReg->rfHSSIPara2, b3WireDataLength,
0x0);
udelay(1);
switch (eRFPath) {
case RF_PATH_A:
ODM_ReadAndConfig_RadioA_1T_8723A(&pHalData->odmpriv);
break;
case RF_PATH_B:
break;
}
switch (eRFPath) {
case RF_PATH_A:
PHY_SetBBReg(Adapter, pPhyReg->rfintfs,
bRFSI_RFENV, u4RegValue);
break;
case RF_PATH_B:
PHY_SetBBReg(Adapter, pPhyReg->rfintfs,
bRFSI_RFENV << 16, u4RegValue);
break;
}
if (rtStatus != _SUCCESS) {
goto phy_RF6052_Config_ParaFile_Fail;
}
}
phy_RF6052_Config_ParaFile_Fail:
return rtStatus;
}
int PHY_RF6052_Config8723A(struct rtw_adapter *Adapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
if (pHalData->rf_type == RF_1T1R)
pHalData->NumTotalRFPath = 1;
else
pHalData->NumTotalRFPath = 2;
return phy_RF6052_Config_ParaFile(Adapter);
}
