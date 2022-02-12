void PHY_RF6052SetBandwidth8723B(
struct adapter *Adapter, enum CHANNEL_WIDTH Bandwidth
)
{
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
switch (Bandwidth) {
case CHANNEL_WIDTH_20:
pHalData->RfRegChnlVal[0] = ((pHalData->RfRegChnlVal[0] & 0xfffff3ff) | BIT10 | BIT11);
PHY_SetRFReg(Adapter, ODM_RF_PATH_A, RF_CHNLBW, bRFRegOffsetMask, pHalData->RfRegChnlVal[0]);
PHY_SetRFReg(Adapter, ODM_RF_PATH_B, RF_CHNLBW, bRFRegOffsetMask, pHalData->RfRegChnlVal[0]);
break;
case CHANNEL_WIDTH_40:
pHalData->RfRegChnlVal[0] = ((pHalData->RfRegChnlVal[0] & 0xfffff3ff) | BIT10);
PHY_SetRFReg(Adapter, ODM_RF_PATH_A, RF_CHNLBW, bRFRegOffsetMask, pHalData->RfRegChnlVal[0]);
PHY_SetRFReg(Adapter, ODM_RF_PATH_B, RF_CHNLBW, bRFRegOffsetMask, pHalData->RfRegChnlVal[0]);
break;
default:
break;
}
}
static int phy_RF6052_Config_ParaFile(struct adapter *Adapter)
{
u32 u4RegValue = 0;
u8 eRFPath;
struct bb_register_def *pPhyReg;
int rtStatus = _SUCCESS;
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
static char sz8723RadioAFile[] = RTL8723B_PHY_RADIO_A;
static char sz8723RadioBFile[] = RTL8723B_PHY_RADIO_B;
static s8 sz8723BTxPwrTrackFile[] = RTL8723B_TXPWR_TRACK;
char *pszRadioAFile, *pszRadioBFile, *pszTxPwrTrackFile;
pszRadioAFile = sz8723RadioAFile;
pszRadioBFile = sz8723RadioBFile;
pszTxPwrTrackFile = sz8723BTxPwrTrackFile;
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
if (PHY_ConfigRFWithParaFile(Adapter, pszRadioAFile, eRFPath) == _FAIL)
{
if (HAL_STATUS_FAILURE == ODM_ConfigRFWithHeaderFile(&pHalData->odmpriv, CONFIG_RF_RADIO, (ODM_RF_RADIO_PATH_E)eRFPath))
rtStatus = _FAIL;
}
break;
case RF_PATH_B:
if (PHY_ConfigRFWithParaFile(Adapter, pszRadioBFile, eRFPath) == _FAIL)
{
if (HAL_STATUS_FAILURE == ODM_ConfigRFWithHeaderFile(&pHalData->odmpriv, CONFIG_RF_RADIO, (ODM_RF_RADIO_PATH_E)eRFPath))
rtStatus = _FAIL;
}
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
if (rtStatus != _SUCCESS) {
goto phy_RF6052_Config_ParaFile_Fail;
}
}
if (PHY_ConfigRFWithTxPwrTrackParaFile(Adapter, pszTxPwrTrackFile) == _FAIL)
{
ODM_ConfigRFWithTxPwrTrackHeaderFile(&pHalData->odmpriv);
}
return rtStatus;
phy_RF6052_Config_ParaFile_Fail:
return rtStatus;
}
int PHY_RF6052_Config8723B(struct adapter *Adapter)
{
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
int rtStatus = _SUCCESS;
if (pHalData->rf_type == RF_1T1R)
pHalData->NumTotalRFPath = 1;
else
pHalData->NumTotalRFPath = 2;
rtStatus = phy_RF6052_Config_ParaFile(Adapter);
return rtStatus;
}
