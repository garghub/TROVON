void rtl8188e_RF_ChangeTxPath(struct adapter *Adapter, u16 DataRate)
{
}
void rtl8188e_PHY_RF6052SetBandwidth(struct adapter *Adapter,
enum ht_channel_width Bandwidth)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
switch (Bandwidth) {
case HT_CHANNEL_WIDTH_20:
pHalData->RfRegChnlVal[0] = ((pHalData->RfRegChnlVal[0] & 0xfffff3ff) | BIT(10) | BIT(11));
PHY_SetRFReg(Adapter, RF_PATH_A, RF_CHNLBW, bRFRegOffsetMask, pHalData->RfRegChnlVal[0]);
break;
case HT_CHANNEL_WIDTH_40:
pHalData->RfRegChnlVal[0] = ((pHalData->RfRegChnlVal[0] & 0xfffff3ff) | BIT(10));
PHY_SetRFReg(Adapter, RF_PATH_A, RF_CHNLBW, bRFRegOffsetMask, pHalData->RfRegChnlVal[0]);
break;
default:
break;
}
}
void
rtl8188e_PHY_RF6052SetCckTxPower(
struct adapter *Adapter,
u8 *pPowerlevel)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
struct mlme_ext_priv *pmlmeext = &Adapter->mlmeextpriv;
u32 TxAGC[2] = {0, 0}, tmpval = 0, pwrtrac_value;
bool TurboScanOff = false;
u8 idx1, idx2;
u8 *ptr;
u8 direction;
TurboScanOff = true;
if (pmlmeext->sitesurvey_res.state == SCAN_PROCESS) {
TxAGC[RF_PATH_A] = 0x3f3f3f3f;
TxAGC[RF_PATH_B] = 0x3f3f3f3f;
TurboScanOff = true;
if (TurboScanOff) {
for (idx1 = RF_PATH_A; idx1 <= RF_PATH_B; idx1++) {
TxAGC[idx1] =
pPowerlevel[idx1] | (pPowerlevel[idx1]<<8) |
(pPowerlevel[idx1]<<16) | (pPowerlevel[idx1]<<24);
if (TxAGC[idx1] > 0x20 && pHalData->ExternalPA)
TxAGC[idx1] = 0x20;
}
}
} else {
if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_Level1) {
TxAGC[RF_PATH_A] = 0x10101010;
TxAGC[RF_PATH_B] = 0x10101010;
} else if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_Level2) {
TxAGC[RF_PATH_A] = 0x00000000;
TxAGC[RF_PATH_B] = 0x00000000;
} else {
for (idx1 = RF_PATH_A; idx1 <= RF_PATH_B; idx1++) {
TxAGC[idx1] =
pPowerlevel[idx1] | (pPowerlevel[idx1]<<8) |
(pPowerlevel[idx1]<<16) | (pPowerlevel[idx1]<<24);
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
ptr = (u8 *)(&(TxAGC[idx1]));
for (idx2 = 0; idx2 < 4; idx2++) {
if (*ptr > RF6052_MAX_TX_PWR)
*ptr = RF6052_MAX_TX_PWR;
ptr++;
}
}
ODM_TxPwrTrackAdjust88E(&pHalData->odmpriv, 1, &direction, &pwrtrac_value);
if (direction == 1) {
TxAGC[0] += pwrtrac_value;
TxAGC[1] += pwrtrac_value;
} else if (direction == 2) {
TxAGC[0] -= pwrtrac_value;
TxAGC[1] -= pwrtrac_value;
}
tmpval = TxAGC[RF_PATH_A]&0xff;
PHY_SetBBReg(Adapter, rTxAGC_A_CCK1_Mcs32, bMaskByte1, tmpval);
tmpval = TxAGC[RF_PATH_A]>>8;
PHY_SetBBReg(Adapter, rTxAGC_B_CCK11_A_CCK2_11, 0xffffff00, tmpval);
tmpval = TxAGC[RF_PATH_B]>>24;
PHY_SetBBReg(Adapter, rTxAGC_B_CCK11_A_CCK2_11, bMaskByte0, tmpval);
tmpval = TxAGC[RF_PATH_B]&0x00ffffff;
PHY_SetBBReg(Adapter, rTxAGC_B_CCK1_55_Mcs32, 0xffffff00, tmpval);
}
static void getpowerbase88e(struct adapter *Adapter, u8 *pPowerLevelOFDM,
u8 *pPowerLevelBW20, u8 *pPowerLevelBW40, u8 Channel, u32 *OfdmBase, u32 *MCSBase)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u32 powerBase0, powerBase1;
u8 i, powerlevel[2];
for (i = 0; i < 2; i++) {
powerBase0 = pPowerLevelOFDM[i];
powerBase0 = (powerBase0<<24) | (powerBase0<<16) | (powerBase0<<8) | powerBase0;
*(OfdmBase+i) = powerBase0;
}
for (i = 0; i < pHalData->NumTotalRFPath; i++) {
if (pHalData->CurrentChannelBW == HT_CHANNEL_WIDTH_20)
powerlevel[i] = pPowerLevelBW20[i];
else
powerlevel[i] = pPowerLevelBW40[i];
powerBase1 = powerlevel[i];
powerBase1 = (powerBase1<<24) | (powerBase1<<16) | (powerBase1<<8) | powerBase1;
*(MCSBase+i) = powerBase1;
}
}
static void get_rx_power_val_by_reg(struct adapter *Adapter, u8 Channel,
u8 index, u32 *powerBase0, u32 *powerBase1,
u32 *pOutWriteVal)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
u8 i, chnlGroup = 0, pwr_diff_limit[4], customer_pwr_limit;
s8 pwr_diff = 0;
u32 writeVal, customer_limit, rf;
u8 Regulatory = pHalData->EEPROMRegulatory;
for (rf = 0; rf < 2; rf++) {
switch (Regulatory) {
case 0:
chnlGroup = 0;
writeVal = pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index+(rf ? 8 : 0)] +
((index < 2) ? powerBase0[rf] : powerBase1[rf]);
break;
case 1:
if (pHalData->pwrGroupCnt == 1)
chnlGroup = 0;
if (pHalData->pwrGroupCnt >= pHalData->PGMaxGroup) {
if (Channel < 3)
chnlGroup = 0;
else if (Channel < 6)
chnlGroup = 1;
else if (Channel < 9)
chnlGroup = 2;
else if (Channel < 12)
chnlGroup = 3;
else if (Channel < 14)
chnlGroup = 4;
else if (Channel == 14)
chnlGroup = 5;
}
writeVal = pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index+(rf ? 8 : 0)] +
((index < 2) ? powerBase0[rf] : powerBase1[rf]);
break;
case 2:
writeVal = ((index < 2) ? powerBase0[rf] : powerBase1[rf]);
break;
case 3:
chnlGroup = 0;
if (index < 2)
pwr_diff = pHalData->TxPwrLegacyHtDiff[rf][Channel-1];
else if (pHalData->CurrentChannelBW == HT_CHANNEL_WIDTH_20)
pwr_diff = pHalData->TxPwrHt20Diff[rf][Channel-1];
if (pHalData->CurrentChannelBW == HT_CHANNEL_WIDTH_40)
customer_pwr_limit = pHalData->PwrGroupHT40[rf][Channel-1];
else
customer_pwr_limit = pHalData->PwrGroupHT20[rf][Channel-1];
if (pwr_diff >= customer_pwr_limit)
pwr_diff = 0;
else
pwr_diff = customer_pwr_limit - pwr_diff;
for (i = 0; i < 4; i++) {
pwr_diff_limit[i] = (u8)((pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index+(rf ? 8 : 0)]&(0x7f<<(i*8)))>>(i*8));
if (pwr_diff_limit[i] > pwr_diff)
pwr_diff_limit[i] = pwr_diff;
}
customer_limit = (pwr_diff_limit[3]<<24) | (pwr_diff_limit[2]<<16) |
(pwr_diff_limit[1]<<8) | (pwr_diff_limit[0]);
writeVal = customer_limit + ((index < 2) ? powerBase0[rf] : powerBase1[rf]);
break;
default:
chnlGroup = 0;
writeVal = pHalData->MCSTxPowerLevelOriginalOffset[chnlGroup][index+(rf ? 8 : 0)] +
((index < 2) ? powerBase0[rf] : powerBase1[rf]);
break;
}
if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_Level1)
writeVal = 0x14141414;
else if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_Level2)
writeVal = 0x00000000;
if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_BT1)
writeVal = writeVal - 0x06060606;
else if (pdmpriv->DynamicTxHighPowerLvl == TxHighPwrLevel_BT2)
writeVal = writeVal;
*(pOutWriteVal+rf) = writeVal;
}
}
static void writeOFDMPowerReg88E(struct adapter *Adapter, u8 index, u32 *pValue)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u16 regoffset_a[6] = {
rTxAGC_A_Rate18_06, rTxAGC_A_Rate54_24,
rTxAGC_A_Mcs03_Mcs00, rTxAGC_A_Mcs07_Mcs04,
rTxAGC_A_Mcs11_Mcs08, rTxAGC_A_Mcs15_Mcs12};
u16 regoffset_b[6] = {
rTxAGC_B_Rate18_06, rTxAGC_B_Rate54_24,
rTxAGC_B_Mcs03_Mcs00, rTxAGC_B_Mcs07_Mcs04,
rTxAGC_B_Mcs11_Mcs08, rTxAGC_B_Mcs15_Mcs12};
u8 i, rf, pwr_val[4];
u32 writeVal;
u16 regoffset;
for (rf = 0; rf < 2; rf++) {
writeVal = pValue[rf];
for (i = 0; i < 4; i++) {
pwr_val[i] = (u8)((writeVal & (0x7f<<(i*8)))>>(i*8));
if (pwr_val[i] > RF6052_MAX_TX_PWR)
pwr_val[i] = RF6052_MAX_TX_PWR;
}
writeVal = (pwr_val[3]<<24) | (pwr_val[2]<<16) | (pwr_val[1]<<8) | pwr_val[0];
if (rf == 0)
regoffset = regoffset_a[index];
else
regoffset = regoffset_b[index];
PHY_SetBBReg(Adapter, regoffset, bMaskDWord, writeVal);
if (((pHalData->rf_type == RF_2T2R) &&
(regoffset == rTxAGC_A_Mcs15_Mcs12 || regoffset == rTxAGC_B_Mcs15_Mcs12)) ||
((pHalData->rf_type != RF_2T2R) &&
(regoffset == rTxAGC_A_Mcs07_Mcs04 || regoffset == rTxAGC_B_Mcs07_Mcs04))) {
writeVal = pwr_val[3];
if (regoffset == rTxAGC_A_Mcs15_Mcs12 || regoffset == rTxAGC_A_Mcs07_Mcs04)
regoffset = 0xc90;
if (regoffset == rTxAGC_B_Mcs15_Mcs12 || regoffset == rTxAGC_B_Mcs07_Mcs04)
regoffset = 0xc98;
for (i = 0; i < 3; i++) {
if (i != 2)
writeVal = (writeVal > 8) ? (writeVal-8) : 0;
else
writeVal = (writeVal > 6) ? (writeVal-6) : 0;
rtw_write8(Adapter, (u32)(regoffset+i), (u8)writeVal);
}
}
}
}
void
rtl8188e_PHY_RF6052SetOFDMTxPower(
struct adapter *Adapter,
u8 *pPowerLevelOFDM,
u8 *pPowerLevelBW20,
u8 *pPowerLevelBW40,
u8 Channel)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u32 writeVal[2], powerBase0[2], powerBase1[2], pwrtrac_value;
u8 direction;
u8 index = 0;
getpowerbase88e(Adapter, pPowerLevelOFDM, pPowerLevelBW20, pPowerLevelBW40, Channel, &powerBase0[0], &powerBase1[0]);
ODM_TxPwrTrackAdjust88E(&pHalData->odmpriv, 0, &direction, &pwrtrac_value);
for (index = 0; index < 6; index++) {
get_rx_power_val_by_reg(Adapter, Channel, index,
&powerBase0[0], &powerBase1[0],
&writeVal[0]);
if (direction == 1) {
writeVal[0] += pwrtrac_value;
writeVal[1] += pwrtrac_value;
} else if (direction == 2) {
writeVal[0] -= pwrtrac_value;
writeVal[1] -= pwrtrac_value;
}
writeOFDMPowerReg88E(Adapter, index, &writeVal[0]);
}
}
static int phy_RF6052_Config_ParaFile(struct adapter *Adapter)
{
struct bb_reg_def *pPhyReg;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
u32 u4RegValue = 0;
u8 eRFPath;
int rtStatus = _SUCCESS;
for (eRFPath = 0; eRFPath < pHalData->NumTotalRFPath; eRFPath++) {
pPhyReg = &pHalData->PHYRegDef[eRFPath];
switch (eRFPath) {
case RF_PATH_A:
case RF_PATH_C:
u4RegValue = PHY_QueryBBReg(Adapter, pPhyReg->rfintfs, bRFSI_RFENV);
break;
case RF_PATH_B:
case RF_PATH_D:
u4RegValue = PHY_QueryBBReg(Adapter, pPhyReg->rfintfs, bRFSI_RFENV<<16);
break;
}
PHY_SetBBReg(Adapter, pPhyReg->rfintfe, bRFSI_RFENV<<16, 0x1);
udelay(1);
PHY_SetBBReg(Adapter, pPhyReg->rfintfo, bRFSI_RFENV, 0x1);
udelay(1);
PHY_SetBBReg(Adapter, pPhyReg->rfHSSIPara2, b3WireAddressLength, 0x0);
udelay(1);
PHY_SetBBReg(Adapter, pPhyReg->rfHSSIPara2, b3WireDataLength, 0x0);
udelay(1);
switch (eRFPath) {
case RF_PATH_A:
if (HAL_STATUS_FAILURE == ODM_ConfigRFWithHeaderFile(&pHalData->odmpriv, (enum rf_radio_path)eRFPath, (enum rf_radio_path)eRFPath))
rtStatus = _FAIL;
break;
case RF_PATH_B:
if (HAL_STATUS_FAILURE == ODM_ConfigRFWithHeaderFile(&pHalData->odmpriv, (enum rf_radio_path)eRFPath, (enum rf_radio_path)eRFPath))
rtStatus = _FAIL;
break;
case RF_PATH_C:
break;
case RF_PATH_D:
break;
}
;
switch (eRFPath) {
case RF_PATH_A:
case RF_PATH_C:
PHY_SetBBReg(Adapter, pPhyReg->rfintfs, bRFSI_RFENV, u4RegValue);
break;
case RF_PATH_B:
case RF_PATH_D:
PHY_SetBBReg(Adapter, pPhyReg->rfintfs, bRFSI_RFENV<<16, u4RegValue);
break;
}
if (rtStatus != _SUCCESS)
goto phy_RF6052_Config_ParaFile_Fail;
}
return rtStatus;
phy_RF6052_Config_ParaFile_Fail:
return rtStatus;
}
int PHY_RF6052_Config8188E(struct adapter *Adapter)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
int rtStatus = _SUCCESS;
if (pHalData->rf_type == RF_1T1R)
pHalData->NumTotalRFPath = 1;
else
pHalData->NumTotalRFPath = 2;
rtStatus = phy_RF6052_Config_ParaFile(Adapter);
return rtStatus;
}
