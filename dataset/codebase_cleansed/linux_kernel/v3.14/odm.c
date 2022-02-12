void ODM_DMInit(struct odm_dm_struct *pDM_Odm)
{
odm_CommonInfoSelfInit(pDM_Odm);
odm_CmnInfoInit_Debug(pDM_Odm);
odm_DIGInit(pDM_Odm);
odm_RateAdaptiveMaskInit(pDM_Odm);
odm_PrimaryCCA_Init(pDM_Odm);
odm_DynamicBBPowerSavingInit(pDM_Odm);
odm_DynamicTxPowerInit(pDM_Odm);
odm_TXPowerTrackingInit(pDM_Odm);
ODM_EdcaTurboInit(pDM_Odm);
ODM_RAInfo_Init_all(pDM_Odm);
if ((pDM_Odm->AntDivType == CG_TRX_HW_ANTDIV) ||
(pDM_Odm->AntDivType == CGCS_RX_HW_ANTDIV) ||
(pDM_Odm->AntDivType == CG_TRX_SMART_ANTDIV))
odm_InitHybridAntDiv(pDM_Odm);
}
void ODM_DMWatchdog(struct odm_dm_struct *pDM_Odm)
{
odm_CmnInfoHook_Debug(pDM_Odm);
odm_CmnInfoUpdate_Debug(pDM_Odm);
odm_CommonInfoSelfUpdate(pDM_Odm);
odm_FalseAlarmCounterStatistics(pDM_Odm);
odm_RSSIMonitorCheck(pDM_Odm);
odm_DIG(pDM_Odm);
odm_CCKPacketDetectionThresh(pDM_Odm);
if (*(pDM_Odm->pbPowerSaving))
return;
odm_RefreshRateAdaptiveMask(pDM_Odm);
odm_DynamicBBPowerSaving(pDM_Odm);
odm_DynamicPrimaryCCA(pDM_Odm);
if ((pDM_Odm->AntDivType == CG_TRX_HW_ANTDIV) ||
(pDM_Odm->AntDivType == CGCS_RX_HW_ANTDIV) ||
(pDM_Odm->AntDivType == CG_TRX_SMART_ANTDIV))
odm_HwAntDiv(pDM_Odm);
ODM_TXPowerTrackingCheck(pDM_Odm);
odm_EdcaTurboCheck(pDM_Odm);
odm_DynamicTxPower(pDM_Odm);
}
void ODM_CmnInfoInit(struct odm_dm_struct *pDM_Odm, enum odm_common_info_def CmnInfo, u32 Value)
{
switch (CmnInfo) {
case ODM_CMNINFO_ABILITY:
pDM_Odm->SupportAbility = (u32)Value;
break;
case ODM_CMNINFO_PLATFORM:
pDM_Odm->SupportPlatform = (u8)Value;
break;
case ODM_CMNINFO_INTERFACE:
pDM_Odm->SupportInterface = (u8)Value;
break;
case ODM_CMNINFO_MP_TEST_CHIP:
pDM_Odm->bIsMPChip = (u8)Value;
break;
case ODM_CMNINFO_IC_TYPE:
pDM_Odm->SupportICType = Value;
break;
case ODM_CMNINFO_CUT_VER:
pDM_Odm->CutVersion = (u8)Value;
break;
case ODM_CMNINFO_FAB_VER:
pDM_Odm->FabVersion = (u8)Value;
break;
case ODM_CMNINFO_RF_TYPE:
pDM_Odm->RFType = (u8)Value;
break;
case ODM_CMNINFO_RF_ANTENNA_TYPE:
pDM_Odm->AntDivType = (u8)Value;
break;
case ODM_CMNINFO_BOARD_TYPE:
pDM_Odm->BoardType = (u8)Value;
break;
case ODM_CMNINFO_EXT_LNA:
pDM_Odm->ExtLNA = (u8)Value;
break;
case ODM_CMNINFO_EXT_PA:
pDM_Odm->ExtPA = (u8)Value;
break;
case ODM_CMNINFO_EXT_TRSW:
pDM_Odm->ExtTRSW = (u8)Value;
break;
case ODM_CMNINFO_PATCH_ID:
pDM_Odm->PatchID = (u8)Value;
break;
case ODM_CMNINFO_BINHCT_TEST:
pDM_Odm->bInHctTest = (bool)Value;
break;
case ODM_CMNINFO_BWIFI_TEST:
pDM_Odm->bWIFITest = (bool)Value;
break;
case ODM_CMNINFO_SMART_CONCURRENT:
pDM_Odm->bDualMacSmartConcurrent = (bool)Value;
break;
default:
break;
}
pDM_Odm->BbSwingIdxOfdm = 12;
pDM_Odm->BbSwingIdxOfdmCurrent = 12;
pDM_Odm->BbSwingFlagOfdm = false;
}
void ODM_CmnInfoHook(struct odm_dm_struct *pDM_Odm, enum odm_common_info_def CmnInfo, void *pValue)
{
switch (CmnInfo) {
case ODM_CMNINFO_MAC_PHY_MODE:
pDM_Odm->pMacPhyMode = (u8 *)pValue;
break;
case ODM_CMNINFO_TX_UNI:
pDM_Odm->pNumTxBytesUnicast = (u64 *)pValue;
break;
case ODM_CMNINFO_RX_UNI:
pDM_Odm->pNumRxBytesUnicast = (u64 *)pValue;
break;
case ODM_CMNINFO_WM_MODE:
pDM_Odm->pWirelessMode = (u8 *)pValue;
break;
case ODM_CMNINFO_BAND:
pDM_Odm->pBandType = (u8 *)pValue;
break;
case ODM_CMNINFO_SEC_CHNL_OFFSET:
pDM_Odm->pSecChOffset = (u8 *)pValue;
break;
case ODM_CMNINFO_SEC_MODE:
pDM_Odm->pSecurity = (u8 *)pValue;
break;
case ODM_CMNINFO_BW:
pDM_Odm->pBandWidth = (u8 *)pValue;
break;
case ODM_CMNINFO_CHNL:
pDM_Odm->pChannel = (u8 *)pValue;
break;
case ODM_CMNINFO_DMSP_GET_VALUE:
pDM_Odm->pbGetValueFromOtherMac = (bool *)pValue;
break;
case ODM_CMNINFO_BUDDY_ADAPTOR:
pDM_Odm->pBuddyAdapter = (struct adapter **)pValue;
break;
case ODM_CMNINFO_DMSP_IS_MASTER:
pDM_Odm->pbMasterOfDMSP = (bool *)pValue;
break;
case ODM_CMNINFO_SCAN:
pDM_Odm->pbScanInProcess = (bool *)pValue;
break;
case ODM_CMNINFO_POWER_SAVING:
pDM_Odm->pbPowerSaving = (bool *)pValue;
break;
case ODM_CMNINFO_ONE_PATH_CCA:
pDM_Odm->pOnePathCCA = (u8 *)pValue;
break;
case ODM_CMNINFO_DRV_STOP:
pDM_Odm->pbDriverStopped = (bool *)pValue;
break;
case ODM_CMNINFO_PNP_IN:
pDM_Odm->pbDriverIsGoingToPnpSetPowerSleep = (bool *)pValue;
break;
case ODM_CMNINFO_INIT_ON:
pDM_Odm->pinit_adpt_in_progress = (bool *)pValue;
break;
case ODM_CMNINFO_ANT_TEST:
pDM_Odm->pAntennaTest = (u8 *)pValue;
break;
case ODM_CMNINFO_NET_CLOSED:
pDM_Odm->pbNet_closed = (bool *)pValue;
break;
case ODM_CMNINFO_MP_MODE:
pDM_Odm->mp_mode = (u8 *)pValue;
break;
default:
break;
}
}
void ODM_CmnInfoPtrArrayHook(struct odm_dm_struct *pDM_Odm, enum odm_common_info_def CmnInfo, u16 Index, void *pValue)
{
switch (CmnInfo) {
case ODM_CMNINFO_STA_STATUS:
pDM_Odm->pODM_StaInfo[Index] = (struct sta_info *)pValue;
break;
default:
break;
}
}
void ODM_CmnInfoUpdate(struct odm_dm_struct *pDM_Odm, u32 CmnInfo, u64 Value)
{
switch (CmnInfo) {
case ODM_CMNINFO_ABILITY:
pDM_Odm->SupportAbility = (u32)Value;
break;
case ODM_CMNINFO_RF_TYPE:
pDM_Odm->RFType = (u8)Value;
break;
case ODM_CMNINFO_WIFI_DIRECT:
pDM_Odm->bWIFI_Direct = (bool)Value;
break;
case ODM_CMNINFO_WIFI_DISPLAY:
pDM_Odm->bWIFI_Display = (bool)Value;
break;
case ODM_CMNINFO_LINK:
pDM_Odm->bLinked = (bool)Value;
break;
case ODM_CMNINFO_RSSI_MIN:
pDM_Odm->RSSI_Min = (u8)Value;
break;
case ODM_CMNINFO_DBG_COMP:
pDM_Odm->DebugComponents = Value;
break;
case ODM_CMNINFO_DBG_LEVEL:
pDM_Odm->DebugLevel = (u32)Value;
break;
case ODM_CMNINFO_RA_THRESHOLD_HIGH:
pDM_Odm->RateAdaptive.HighRSSIThresh = (u8)Value;
break;
case ODM_CMNINFO_RA_THRESHOLD_LOW:
pDM_Odm->RateAdaptive.LowRSSIThresh = (u8)Value;
break;
}
}
void odm_CommonInfoSelfInit(struct odm_dm_struct *pDM_Odm)
{
struct adapter *adapter = pDM_Odm->Adapter;
pDM_Odm->bCckHighPower = (bool) PHY_QueryBBReg(adapter, 0x824, BIT9);
pDM_Odm->RFPathRxEnable = (u8) PHY_QueryBBReg(adapter, 0xc04, 0x0F);
ODM_InitDebugSetting(pDM_Odm);
}
void odm_CommonInfoSelfUpdate(struct odm_dm_struct *pDM_Odm)
{
u8 EntryCnt = 0;
u8 i;
struct sta_info *pEntry;
if (*(pDM_Odm->pBandWidth) == ODM_BW40M) {
if (*(pDM_Odm->pSecChOffset) == 1)
pDM_Odm->ControlChannel = *(pDM_Odm->pChannel) - 2;
else if (*(pDM_Odm->pSecChOffset) == 2)
pDM_Odm->ControlChannel = *(pDM_Odm->pChannel) + 2;
} else {
pDM_Odm->ControlChannel = *(pDM_Odm->pChannel);
}
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
pEntry = pDM_Odm->pODM_StaInfo[i];
if (IS_STA_VALID(pEntry))
EntryCnt++;
}
if (EntryCnt == 1)
pDM_Odm->bOneEntryOnly = true;
else
pDM_Odm->bOneEntryOnly = false;
}
void odm_CmnInfoInit_Debug(struct odm_dm_struct *pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("odm_CmnInfoInit_Debug==>\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportPlatform=%d\n", pDM_Odm->SupportPlatform));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportAbility=0x%x\n", pDM_Odm->SupportAbility));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportInterface=%d\n", pDM_Odm->SupportInterface));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportICType=0x%x\n", pDM_Odm->SupportICType));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("CutVersion=%d\n", pDM_Odm->CutVersion));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("FabVersion=%d\n", pDM_Odm->FabVersion));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("RFType=%d\n", pDM_Odm->RFType));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("BoardType=%d\n", pDM_Odm->BoardType));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("ExtLNA=%d\n", pDM_Odm->ExtLNA));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("ExtPA=%d\n", pDM_Odm->ExtPA));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("ExtTRSW=%d\n", pDM_Odm->ExtTRSW));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("PatchID=%d\n", pDM_Odm->PatchID));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bInHctTest=%d\n", pDM_Odm->bInHctTest));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bWIFITest=%d\n", pDM_Odm->bWIFITest));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bDualMacSmartConcurrent=%d\n", pDM_Odm->bDualMacSmartConcurrent));
}
void odm_CmnInfoHook_Debug(struct odm_dm_struct *pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("odm_CmnInfoHook_Debug==>\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pNumTxBytesUnicast=%llu\n", *(pDM_Odm->pNumTxBytesUnicast)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pNumRxBytesUnicast=%llu\n", *(pDM_Odm->pNumRxBytesUnicast)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pWirelessMode=0x%x\n", *(pDM_Odm->pWirelessMode)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pSecChOffset=%d\n", *(pDM_Odm->pSecChOffset)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pSecurity=%d\n", *(pDM_Odm->pSecurity)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pBandWidth=%d\n", *(pDM_Odm->pBandWidth)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pChannel=%d\n", *(pDM_Odm->pChannel)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pbScanInProcess=%d\n", *(pDM_Odm->pbScanInProcess)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("pbPowerSaving=%d\n", *(pDM_Odm->pbPowerSaving)));
}
void odm_CmnInfoUpdate_Debug(struct odm_dm_struct *pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("odm_CmnInfoUpdate_Debug==>\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bWIFI_Direct=%d\n", pDM_Odm->bWIFI_Direct));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bWIFI_Display=%d\n", pDM_Odm->bWIFI_Display));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bLinked=%d\n", pDM_Odm->bLinked));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("RSSI_Min=%d\n", pDM_Odm->RSSI_Min));
}
void ODM_Write_DIG(struct odm_dm_struct *pDM_Odm, u8 CurrentIGI)
{
struct rtw_dig *pDM_DigTable = &pDM_Odm->DM_DigTable;
struct adapter *adapter = pDM_Odm->Adapter;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("ODM_REG(IGI_A,pDM_Odm)=0x%x, ODM_BIT(IGI,pDM_Odm)=0x%x\n",
ODM_REG(IGI_A, pDM_Odm), ODM_BIT(IGI, pDM_Odm)));
if (pDM_DigTable->CurIGValue != CurrentIGI) {
PHY_SetBBReg(adapter, ODM_REG(IGI_A, pDM_Odm), ODM_BIT(IGI, pDM_Odm), CurrentIGI);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("CurrentIGI(0x%02x).\n", CurrentIGI));
pDM_DigTable->CurIGValue = CurrentIGI;
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("ODM_Write_DIG():CurrentIGI=0x%x\n", CurrentIGI));
}
void odm_DIGbyRSSI_LPS(struct odm_dm_struct *pDM_Odm)
{
struct adapter *pAdapter = pDM_Odm->Adapter;
struct false_alarm_stats *pFalseAlmCnt = &pDM_Odm->FalseAlmCnt;
u8 RSSI_Lower = DM_DIG_MIN_NIC;
u8 bFwCurrentInPSMode = false;
u8 CurrentIGI = pDM_Odm->RSSI_Min;
CurrentIGI = CurrentIGI + RSSI_OFFSET_DIG;
bFwCurrentInPSMode = pAdapter->pwrctrlpriv.bFwCurrentInPSMode;
if (bFwCurrentInPSMode) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("---Neil---odm_DIG is in LPS mode\n"));
if (pFalseAlmCnt->Cnt_all > DM_DIG_FA_TH2_LPS)
CurrentIGI = CurrentIGI+2;
else if (pFalseAlmCnt->Cnt_all > DM_DIG_FA_TH1_LPS)
CurrentIGI = CurrentIGI+1;
else if (pFalseAlmCnt->Cnt_all < DM_DIG_FA_TH0_LPS)
CurrentIGI = CurrentIGI-1;
} else {
CurrentIGI = RSSI_Lower;
}
if ((pDM_Odm->RSSI_Min-10) > DM_DIG_MIN_NIC)
RSSI_Lower = (pDM_Odm->RSSI_Min-10);
else
RSSI_Lower = DM_DIG_MIN_NIC;
if (CurrentIGI > DM_DIG_MAX_NIC)
CurrentIGI = DM_DIG_MAX_NIC;
else if (CurrentIGI < RSSI_Lower)
CurrentIGI = RSSI_Lower;
ODM_Write_DIG(pDM_Odm, CurrentIGI);
}
void odm_DIGInit(struct odm_dm_struct *pDM_Odm)
{
struct adapter *adapter = pDM_Odm->Adapter;
struct rtw_dig *pDM_DigTable = &pDM_Odm->DM_DigTable;
pDM_DigTable->CurIGValue = (u8) PHY_QueryBBReg(adapter, ODM_REG(IGI_A, pDM_Odm), ODM_BIT(IGI, pDM_Odm));
pDM_DigTable->RssiLowThresh = DM_DIG_THRESH_LOW;
pDM_DigTable->RssiHighThresh = DM_DIG_THRESH_HIGH;
pDM_DigTable->FALowThresh = DM_false_ALARM_THRESH_LOW;
pDM_DigTable->FAHighThresh = DM_false_ALARM_THRESH_HIGH;
if (pDM_Odm->BoardType == ODM_BOARD_HIGHPWR) {
pDM_DigTable->rx_gain_range_max = DM_DIG_MAX_NIC;
pDM_DigTable->rx_gain_range_min = DM_DIG_MIN_NIC;
} else {
pDM_DigTable->rx_gain_range_max = DM_DIG_MAX_NIC;
pDM_DigTable->rx_gain_range_min = DM_DIG_MIN_NIC;
}
pDM_DigTable->BackoffVal = DM_DIG_BACKOFF_DEFAULT;
pDM_DigTable->BackoffVal_range_max = DM_DIG_BACKOFF_MAX;
pDM_DigTable->BackoffVal_range_min = DM_DIG_BACKOFF_MIN;
pDM_DigTable->PreCCK_CCAThres = 0xFF;
pDM_DigTable->CurCCK_CCAThres = 0x83;
pDM_DigTable->ForbiddenIGI = DM_DIG_MIN_NIC;
pDM_DigTable->LargeFAHit = 0;
pDM_DigTable->Recover_cnt = 0;
pDM_DigTable->DIG_Dynamic_MIN_0 = DM_DIG_MIN_NIC;
pDM_DigTable->DIG_Dynamic_MIN_1 = DM_DIG_MIN_NIC;
pDM_DigTable->bMediaConnect_0 = false;
pDM_DigTable->bMediaConnect_1 = false;
pDM_Odm->bDMInitialGainEnable = true;
}
void odm_DIG(struct odm_dm_struct *pDM_Odm)
{
struct rtw_dig *pDM_DigTable = &pDM_Odm->DM_DigTable;
struct false_alarm_stats *pFalseAlmCnt = &pDM_Odm->FalseAlmCnt;
u8 DIG_Dynamic_MIN;
u8 DIG_MaxOfMin;
bool FirstConnect, FirstDisConnect;
u8 dm_dig_max, dm_dig_min;
u8 CurrentIGI = pDM_DigTable->CurIGValue;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG()==>\n"));
if ((!(pDM_Odm->SupportAbility&ODM_BB_DIG)) || (!(pDM_Odm->SupportAbility&ODM_BB_FA_CNT))) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG() Return: SupportAbility ODM_BB_DIG or ODM_BB_FA_CNT is disabled\n"));
return;
}
if (*(pDM_Odm->pbScanInProcess)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG() Return: In Scan Progress\n"));
return;
}
if (pDM_Odm->bDMInitialGainEnable == false) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG() Return: PSD is Processing\n"));
return;
}
DIG_Dynamic_MIN = pDM_DigTable->DIG_Dynamic_MIN_0;
FirstConnect = (pDM_Odm->bLinked) && (!pDM_DigTable->bMediaConnect_0);
FirstDisConnect = (!pDM_Odm->bLinked) && (pDM_DigTable->bMediaConnect_0);
dm_dig_max = DM_DIG_MAX_NIC;
dm_dig_min = DM_DIG_MIN_NIC;
DIG_MaxOfMin = DM_DIG_MAX_AP;
if (pDM_Odm->bLinked) {
if ((pDM_Odm->RSSI_Min + 20) > dm_dig_max)
pDM_DigTable->rx_gain_range_max = dm_dig_max;
else if ((pDM_Odm->RSSI_Min + 20) < dm_dig_min)
pDM_DigTable->rx_gain_range_max = dm_dig_min;
else
pDM_DigTable->rx_gain_range_max = pDM_Odm->RSSI_Min + 20;
if (pDM_Odm->bOneEntryOnly) {
if (pDM_Odm->RSSI_Min < dm_dig_min)
DIG_Dynamic_MIN = dm_dig_min;
else if (pDM_Odm->RSSI_Min > DIG_MaxOfMin)
DIG_Dynamic_MIN = DIG_MaxOfMin;
else
DIG_Dynamic_MIN = pDM_Odm->RSSI_Min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG() : bOneEntryOnly=true, DIG_Dynamic_MIN=0x%x\n",
DIG_Dynamic_MIN));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG() : pDM_Odm->RSSI_Min=%d\n",
pDM_Odm->RSSI_Min));
} else if (pDM_Odm->SupportAbility & ODM_BB_ANT_DIV) {
if (pDM_Odm->AntDivType == CG_TRX_HW_ANTDIV) {
DIG_Dynamic_MIN = (u8) pDM_DigTable->AntDiv_RSSI_max;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD,
("odm_DIG(): pDM_DigTable->AntDiv_RSSI_max=%d\n",
pDM_DigTable->AntDiv_RSSI_max));
}
} else {
DIG_Dynamic_MIN = dm_dig_min;
}
} else {
pDM_DigTable->rx_gain_range_max = dm_dig_max;
DIG_Dynamic_MIN = dm_dig_min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG() : No Link\n"));
}
if (pFalseAlmCnt->Cnt_all > 10000) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("dm_DIG(): Abnornally false alarm case.\n"));
if (pDM_DigTable->LargeFAHit != 3)
pDM_DigTable->LargeFAHit++;
if (pDM_DigTable->ForbiddenIGI < CurrentIGI) {
pDM_DigTable->ForbiddenIGI = CurrentIGI;
pDM_DigTable->LargeFAHit = 1;
}
if (pDM_DigTable->LargeFAHit >= 3) {
if ((pDM_DigTable->ForbiddenIGI+1) > pDM_DigTable->rx_gain_range_max)
pDM_DigTable->rx_gain_range_min = pDM_DigTable->rx_gain_range_max;
else
pDM_DigTable->rx_gain_range_min = (pDM_DigTable->ForbiddenIGI + 1);
pDM_DigTable->Recover_cnt = 3600;
}
} else {
if (pDM_DigTable->Recover_cnt != 0) {
pDM_DigTable->Recover_cnt--;
} else {
if (pDM_DigTable->LargeFAHit < 3) {
if ((pDM_DigTable->ForbiddenIGI-1) < DIG_Dynamic_MIN) {
pDM_DigTable->ForbiddenIGI = DIG_Dynamic_MIN;
pDM_DigTable->rx_gain_range_min = DIG_Dynamic_MIN;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): Normal Case: At Lower Bound\n"));
} else {
pDM_DigTable->ForbiddenIGI--;
pDM_DigTable->rx_gain_range_min = (pDM_DigTable->ForbiddenIGI + 1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): Normal Case: Approach Lower Bound\n"));
}
} else {
pDM_DigTable->LargeFAHit = 0;
}
}
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG(): pDM_DigTable->LargeFAHit=%d\n",
pDM_DigTable->LargeFAHit));
if (pDM_Odm->bLinked) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): DIG AfterLink\n"));
if (FirstConnect) {
CurrentIGI = pDM_Odm->RSSI_Min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("DIG: First Connect\n"));
} else {
if (pFalseAlmCnt->Cnt_all > DM_DIG_FA_TH2)
CurrentIGI = CurrentIGI + 4;
else if (pFalseAlmCnt->Cnt_all > DM_DIG_FA_TH1)
CurrentIGI = CurrentIGI + 2;
else if (pFalseAlmCnt->Cnt_all < DM_DIG_FA_TH0)
CurrentIGI = CurrentIGI - 2;
}
} else {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): DIG BeforeLink\n"));
if (FirstDisConnect) {
CurrentIGI = pDM_DigTable->rx_gain_range_min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): First DisConnect\n"));
} else {
if (pFalseAlmCnt->Cnt_all > 10000)
CurrentIGI = CurrentIGI + 2;
else if (pFalseAlmCnt->Cnt_all > 8000)
CurrentIGI = CurrentIGI + 1;
else if (pFalseAlmCnt->Cnt_all < 500)
CurrentIGI = CurrentIGI - 1;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): England DIG\n"));
}
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): DIG End Adjust IGI\n"));
if (CurrentIGI > pDM_DigTable->rx_gain_range_max)
CurrentIGI = pDM_DigTable->rx_gain_range_max;
if (CurrentIGI < pDM_DigTable->rx_gain_range_min)
CurrentIGI = pDM_DigTable->rx_gain_range_min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG(): rx_gain_range_max=0x%x, rx_gain_range_min=0x%x\n",
pDM_DigTable->rx_gain_range_max, pDM_DigTable->rx_gain_range_min));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): TotalFA=%d\n", pFalseAlmCnt->Cnt_all));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): CurIGValue=0x%x\n", CurrentIGI));
ODM_Write_DIG(pDM_Odm, CurrentIGI);
pDM_DigTable->bMediaConnect_0 = pDM_Odm->bLinked;
pDM_DigTable->DIG_Dynamic_MIN_0 = DIG_Dynamic_MIN;
}
void odm_FalseAlarmCounterStatistics(struct odm_dm_struct *pDM_Odm)
{
struct adapter *adapter = pDM_Odm->Adapter;
u32 ret_value;
struct false_alarm_stats *FalseAlmCnt = &(pDM_Odm->FalseAlmCnt);
if (!(pDM_Odm->SupportAbility & ODM_BB_FA_CNT))
return;
PHY_SetBBReg(adapter, ODM_REG_OFDM_FA_HOLDC_11N, BIT31, 1);
PHY_SetBBReg(adapter, ODM_REG_OFDM_FA_RSTD_11N, BIT31, 1);
ret_value = PHY_QueryBBReg(adapter, ODM_REG_OFDM_FA_TYPE1_11N, bMaskDWord);
FalseAlmCnt->Cnt_Fast_Fsync = (ret_value&0xffff);
FalseAlmCnt->Cnt_SB_Search_fail = ((ret_value&0xffff0000)>>16);
ret_value = PHY_QueryBBReg(adapter, ODM_REG_OFDM_FA_TYPE2_11N, bMaskDWord);
FalseAlmCnt->Cnt_OFDM_CCA = (ret_value&0xffff);
FalseAlmCnt->Cnt_Parity_Fail = ((ret_value&0xffff0000)>>16);
ret_value = PHY_QueryBBReg(adapter, ODM_REG_OFDM_FA_TYPE3_11N, bMaskDWord);
FalseAlmCnt->Cnt_Rate_Illegal = (ret_value&0xffff);
FalseAlmCnt->Cnt_Crc8_fail = ((ret_value&0xffff0000)>>16);
ret_value = PHY_QueryBBReg(adapter, ODM_REG_OFDM_FA_TYPE4_11N, bMaskDWord);
FalseAlmCnt->Cnt_Mcs_fail = (ret_value&0xffff);
FalseAlmCnt->Cnt_Ofdm_fail = FalseAlmCnt->Cnt_Parity_Fail + FalseAlmCnt->Cnt_Rate_Illegal +
FalseAlmCnt->Cnt_Crc8_fail + FalseAlmCnt->Cnt_Mcs_fail +
FalseAlmCnt->Cnt_Fast_Fsync + FalseAlmCnt->Cnt_SB_Search_fail;
ret_value = PHY_QueryBBReg(adapter, ODM_REG_SC_CNT_11N, bMaskDWord);
FalseAlmCnt->Cnt_BW_LSC = (ret_value&0xffff);
FalseAlmCnt->Cnt_BW_USC = ((ret_value&0xffff0000)>>16);
PHY_SetBBReg(adapter, ODM_REG_CCK_FA_RST_11N, BIT12, 1);
PHY_SetBBReg(adapter, ODM_REG_CCK_FA_RST_11N, BIT14, 1);
ret_value = PHY_QueryBBReg(adapter, ODM_REG_CCK_FA_LSB_11N, bMaskByte0);
FalseAlmCnt->Cnt_Cck_fail = ret_value;
ret_value = PHY_QueryBBReg(adapter, ODM_REG_CCK_FA_MSB_11N, bMaskByte3);
FalseAlmCnt->Cnt_Cck_fail += (ret_value & 0xff)<<8;
ret_value = PHY_QueryBBReg(adapter, ODM_REG_CCK_CCA_CNT_11N, bMaskDWord);
FalseAlmCnt->Cnt_CCK_CCA = ((ret_value&0xFF)<<8) | ((ret_value&0xFF00)>>8);
FalseAlmCnt->Cnt_all = (FalseAlmCnt->Cnt_Fast_Fsync +
FalseAlmCnt->Cnt_SB_Search_fail +
FalseAlmCnt->Cnt_Parity_Fail +
FalseAlmCnt->Cnt_Rate_Illegal +
FalseAlmCnt->Cnt_Crc8_fail +
FalseAlmCnt->Cnt_Mcs_fail +
FalseAlmCnt->Cnt_Cck_fail);
FalseAlmCnt->Cnt_CCA_all = FalseAlmCnt->Cnt_OFDM_CCA + FalseAlmCnt->Cnt_CCK_CCA;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD, ("Enter odm_FalseAlarmCounterStatistics\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD,
("Cnt_Fast_Fsync=%d, Cnt_SB_Search_fail=%d\n",
FalseAlmCnt->Cnt_Fast_Fsync, FalseAlmCnt->Cnt_SB_Search_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD,
("Cnt_Parity_Fail=%d, Cnt_Rate_Illegal=%d\n",
FalseAlmCnt->Cnt_Parity_Fail, FalseAlmCnt->Cnt_Rate_Illegal));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD,
("Cnt_Crc8_fail=%d, Cnt_Mcs_fail=%d\n",
FalseAlmCnt->Cnt_Crc8_fail, FalseAlmCnt->Cnt_Mcs_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD, ("Cnt_Cck_fail=%d\n", FalseAlmCnt->Cnt_Cck_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD, ("Cnt_Ofdm_fail=%d\n", FalseAlmCnt->Cnt_Ofdm_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD, ("Total False Alarm=%d\n", FalseAlmCnt->Cnt_all));
}
void odm_CCKPacketDetectionThresh(struct odm_dm_struct *pDM_Odm)
{
u8 CurCCK_CCAThres;
struct false_alarm_stats *FalseAlmCnt = &(pDM_Odm->FalseAlmCnt);
if (!(pDM_Odm->SupportAbility & (ODM_BB_CCK_PD|ODM_BB_FA_CNT)))
return;
if (pDM_Odm->ExtLNA)
return;
if (pDM_Odm->bLinked) {
if (pDM_Odm->RSSI_Min > 25) {
CurCCK_CCAThres = 0xcd;
} else if ((pDM_Odm->RSSI_Min <= 25) && (pDM_Odm->RSSI_Min > 10)) {
CurCCK_CCAThres = 0x83;
} else {
if (FalseAlmCnt->Cnt_Cck_fail > 1000)
CurCCK_CCAThres = 0x83;
else
CurCCK_CCAThres = 0x40;
}
} else {
if (FalseAlmCnt->Cnt_Cck_fail > 1000)
CurCCK_CCAThres = 0x83;
else
CurCCK_CCAThres = 0x40;
}
ODM_Write_CCK_CCA_Thres(pDM_Odm, CurCCK_CCAThres);
}
void ODM_Write_CCK_CCA_Thres(struct odm_dm_struct *pDM_Odm, u8 CurCCK_CCAThres)
{
struct rtw_dig *pDM_DigTable = &pDM_Odm->DM_DigTable;
if (pDM_DigTable->CurCCK_CCAThres != CurCCK_CCAThres)
ODM_Write1Byte(pDM_Odm, ODM_REG(CCK_CCA, pDM_Odm), CurCCK_CCAThres);
pDM_DigTable->PreCCK_CCAThres = pDM_DigTable->CurCCK_CCAThres;
pDM_DigTable->CurCCK_CCAThres = CurCCK_CCAThres;
}
void odm_DynamicBBPowerSavingInit(struct odm_dm_struct *pDM_Odm)
{
struct rtl_ps *pDM_PSTable = &pDM_Odm->DM_PSTable;
pDM_PSTable->PreCCAState = CCA_MAX;
pDM_PSTable->CurCCAState = CCA_MAX;
pDM_PSTable->PreRFState = RF_MAX;
pDM_PSTable->CurRFState = RF_MAX;
pDM_PSTable->Rssi_val_min = 0;
pDM_PSTable->initialize = 0;
}
void odm_DynamicBBPowerSaving(struct odm_dm_struct *pDM_Odm)
{
}
void odm_1R_CCA(struct odm_dm_struct *pDM_Odm)
{
struct adapter *adapter = pDM_Odm->Adapter;
struct rtl_ps *pDM_PSTable = &pDM_Odm->DM_PSTable;
if (pDM_Odm->RSSI_Min != 0xFF) {
if (pDM_PSTable->PreCCAState == CCA_2R) {
if (pDM_Odm->RSSI_Min >= 35)
pDM_PSTable->CurCCAState = CCA_1R;
else
pDM_PSTable->CurCCAState = CCA_2R;
} else {
if (pDM_Odm->RSSI_Min <= 30)
pDM_PSTable->CurCCAState = CCA_2R;
else
pDM_PSTable->CurCCAState = CCA_1R;
}
} else {
pDM_PSTable->CurCCAState = CCA_MAX;
}
if (pDM_PSTable->PreCCAState != pDM_PSTable->CurCCAState) {
if (pDM_PSTable->CurCCAState == CCA_1R) {
if (pDM_Odm->RFType == ODM_2T2R)
PHY_SetBBReg(adapter, 0xc04, bMaskByte0, 0x13);
else
PHY_SetBBReg(adapter, 0xc04, bMaskByte0, 0x23);
} else {
PHY_SetBBReg(adapter, 0xc04, bMaskByte0, 0x33);
}
pDM_PSTable->PreCCAState = pDM_PSTable->CurCCAState;
}
}
void ODM_RF_Saving(struct odm_dm_struct *pDM_Odm, u8 bForceInNormal)
{
struct adapter *adapter = pDM_Odm->Adapter;
struct rtl_ps *pDM_PSTable = &pDM_Odm->DM_PSTable;
u8 Rssi_Up_bound = 30;
u8 Rssi_Low_bound = 25;
if (pDM_Odm->PatchID == 40) {
Rssi_Up_bound = 50;
Rssi_Low_bound = 45;
}
if (pDM_PSTable->initialize == 0) {
pDM_PSTable->Reg874 = (PHY_QueryBBReg(adapter, 0x874, bMaskDWord)&0x1CC000)>>14;
pDM_PSTable->RegC70 = (PHY_QueryBBReg(adapter, 0xc70, bMaskDWord)&BIT3)>>3;
pDM_PSTable->Reg85C = (PHY_QueryBBReg(adapter, 0x85c, bMaskDWord)&0xFF000000)>>24;
pDM_PSTable->RegA74 = (PHY_QueryBBReg(adapter, 0xa74, bMaskDWord)&0xF000)>>12;
pDM_PSTable->initialize = 1;
}
if (!bForceInNormal) {
if (pDM_Odm->RSSI_Min != 0xFF) {
if (pDM_PSTable->PreRFState == RF_Normal) {
if (pDM_Odm->RSSI_Min >= Rssi_Up_bound)
pDM_PSTable->CurRFState = RF_Save;
else
pDM_PSTable->CurRFState = RF_Normal;
} else {
if (pDM_Odm->RSSI_Min <= Rssi_Low_bound)
pDM_PSTable->CurRFState = RF_Normal;
else
pDM_PSTable->CurRFState = RF_Save;
}
} else {
pDM_PSTable->CurRFState = RF_MAX;
}
} else {
pDM_PSTable->CurRFState = RF_Normal;
}
if (pDM_PSTable->PreRFState != pDM_PSTable->CurRFState) {
if (pDM_PSTable->CurRFState == RF_Save) {
PHY_SetBBReg(adapter, 0x874 , 0x1C0000, 0x2);
PHY_SetBBReg(adapter, 0xc70, BIT3, 0);
PHY_SetBBReg(adapter, 0x85c, 0xFF000000, 0x63);
PHY_SetBBReg(adapter, 0x874, 0xC000, 0x2);
PHY_SetBBReg(adapter, 0xa74, 0xF000, 0x3);
PHY_SetBBReg(adapter, 0x818, BIT28, 0x0);
PHY_SetBBReg(adapter, 0x818, BIT28, 0x1);
} else {
PHY_SetBBReg(adapter, 0x874 , 0x1CC000, pDM_PSTable->Reg874);
PHY_SetBBReg(adapter, 0xc70, BIT3, pDM_PSTable->RegC70);
PHY_SetBBReg(adapter, 0x85c, 0xFF000000, pDM_PSTable->Reg85C);
PHY_SetBBReg(adapter, 0xa74, 0xF000, pDM_PSTable->RegA74);
PHY_SetBBReg(adapter, 0x818, BIT28, 0x0);
}
pDM_PSTable->PreRFState = pDM_PSTable->CurRFState;
}
}
void odm_RateAdaptiveMaskInit(struct odm_dm_struct *pDM_Odm)
{
struct odm_rate_adapt *pOdmRA = &pDM_Odm->RateAdaptive;
pOdmRA->Type = DM_Type_ByDriver;
if (pOdmRA->Type == DM_Type_ByDriver)
pDM_Odm->bUseRAMask = true;
else
pDM_Odm->bUseRAMask = false;
pOdmRA->RATRState = DM_RATR_STA_INIT;
pOdmRA->HighRSSIThresh = 50;
pOdmRA->LowRSSIThresh = 20;
}
u32 ODM_Get_Rate_Bitmap(struct odm_dm_struct *pDM_Odm, u32 macid, u32 ra_mask, u8 rssi_level)
{
struct sta_info *pEntry;
u32 rate_bitmap = 0x0fffffff;
u8 WirelessMode;
pEntry = pDM_Odm->pODM_StaInfo[macid];
if (!IS_STA_VALID(pEntry))
return ra_mask;
WirelessMode = pEntry->wireless_mode;
switch (WirelessMode) {
case ODM_WM_B:
if (ra_mask & 0x0000000c)
rate_bitmap = 0x0000000d;
else
rate_bitmap = 0x0000000f;
break;
case (ODM_WM_A|ODM_WM_G):
if (rssi_level == DM_RATR_STA_HIGH)
rate_bitmap = 0x00000f00;
else
rate_bitmap = 0x00000ff0;
break;
case (ODM_WM_B|ODM_WM_G):
if (rssi_level == DM_RATR_STA_HIGH)
rate_bitmap = 0x00000f00;
else if (rssi_level == DM_RATR_STA_MIDDLE)
rate_bitmap = 0x00000ff0;
else
rate_bitmap = 0x00000ff5;
break;
case (ODM_WM_B|ODM_WM_G|ODM_WM_N24G):
case (ODM_WM_A|ODM_WM_B|ODM_WM_G|ODM_WM_N24G):
if (pDM_Odm->RFType == ODM_1T2R || pDM_Odm->RFType == ODM_1T1R) {
if (rssi_level == DM_RATR_STA_HIGH) {
rate_bitmap = 0x000f0000;
} else if (rssi_level == DM_RATR_STA_MIDDLE) {
rate_bitmap = 0x000ff000;
} else {
if (*(pDM_Odm->pBandWidth) == ODM_BW40M)
rate_bitmap = 0x000ff015;
else
rate_bitmap = 0x000ff005;
}
} else {
if (rssi_level == DM_RATR_STA_HIGH) {
rate_bitmap = 0x0f8f0000;
} else if (rssi_level == DM_RATR_STA_MIDDLE) {
rate_bitmap = 0x0f8ff000;
} else {
if (*(pDM_Odm->pBandWidth) == ODM_BW40M)
rate_bitmap = 0x0f8ff015;
else
rate_bitmap = 0x0f8ff005;
}
}
break;
default:
if (pDM_Odm->RFType == RF_1T2R)
rate_bitmap = 0x000fffff;
else
rate_bitmap = 0x0fffffff;
break;
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD,
(" ==> rssi_level:0x%02x, WirelessMode:0x%02x, rate_bitmap:0x%08x\n",
rssi_level, WirelessMode, rate_bitmap));
return rate_bitmap;
}
void odm_RefreshRateAdaptiveMask(struct odm_dm_struct *pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_RA_MASK))
return;
odm_RefreshRateAdaptiveMaskCE(pDM_Odm);
}
void odm_RefreshRateAdaptiveMaskMP(struct odm_dm_struct *pDM_Odm)
{
}
void odm_RefreshRateAdaptiveMaskCE(struct odm_dm_struct *pDM_Odm)
{
u8 i;
struct adapter *pAdapter = pDM_Odm->Adapter;
if (pAdapter->bDriverStopped) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_TRACE, ("<---- odm_RefreshRateAdaptiveMask(): driver is going to unload\n"));
return;
}
if (!pDM_Odm->bUseRAMask) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD, ("<---- odm_RefreshRateAdaptiveMask(): driver does not control rate adaptive mask\n"));
return;
}
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
struct sta_info *pstat = pDM_Odm->pODM_StaInfo[i];
if (IS_STA_VALID(pstat)) {
if (ODM_RAStateCheck(pDM_Odm, pstat->rssi_stat.UndecoratedSmoothedPWDB, false , &pstat->rssi_level)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD,
("RSSI:%d, RSSI_LEVEL:%d\n",
pstat->rssi_stat.UndecoratedSmoothedPWDB, pstat->rssi_level));
rtw_hal_update_ra_mask(pAdapter, i, pstat->rssi_level);
}
}
}
}
void odm_RefreshRateAdaptiveMaskAPADSL(struct odm_dm_struct *pDM_Odm)
{
}
bool ODM_RAStateCheck(struct odm_dm_struct *pDM_Odm, s32 RSSI, bool bForceUpdate, u8 *pRATRState)
{
struct odm_rate_adapt *pRA = &pDM_Odm->RateAdaptive;
const u8 GoUpGap = 5;
u8 HighRSSIThreshForRA = pRA->HighRSSIThresh;
u8 LowRSSIThreshForRA = pRA->LowRSSIThresh;
u8 RATRState;
switch (*pRATRState) {
case DM_RATR_STA_INIT:
case DM_RATR_STA_HIGH:
break;
case DM_RATR_STA_MIDDLE:
HighRSSIThreshForRA += GoUpGap;
break;
case DM_RATR_STA_LOW:
HighRSSIThreshForRA += GoUpGap;
LowRSSIThreshForRA += GoUpGap;
break;
default:
ODM_RT_ASSERT(pDM_Odm, false, ("wrong rssi level setting %d !", *pRATRState));
break;
}
if (RSSI > HighRSSIThreshForRA)
RATRState = DM_RATR_STA_HIGH;
else if (RSSI > LowRSSIThreshForRA)
RATRState = DM_RATR_STA_MIDDLE;
else
RATRState = DM_RATR_STA_LOW;
if (*pRATRState != RATRState || bForceUpdate) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD, ("RSSI Level %d -> %d\n", *pRATRState, RATRState));
*pRATRState = RATRState;
return true;
}
return false;
}
void odm_DynamicTxPowerInit(struct odm_dm_struct *pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
pdmpriv->bDynamicTxPowerEnable = false;
pdmpriv->LastDTPLvl = TxHighPwrLevel_Normal;
pdmpriv->DynamicTxHighPowerLvl = TxHighPwrLevel_Normal;
}
void odm_DynamicTxPower(struct odm_dm_struct *pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_DYNAMIC_TXPWR))
return;
if (!pDM_Odm->ExtPA)
return;
odm_DynamicTxPowerNIC(pDM_Odm);
}
void odm_DynamicTxPowerNIC(struct odm_dm_struct *pDM_Odm)
{
}
void odm_RSSIMonitorCheck(struct odm_dm_struct *pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_RSSI_MONITOR))
return;
odm_RSSIMonitorCheckCE(pDM_Odm);
}
static void FindMinimumRSSI(struct adapter *pAdapter)
{
struct hal_data_8188e *pHalData = GET_HAL_DATA(pAdapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
struct mlme_priv *pmlmepriv = &pAdapter->mlmepriv;
if ((check_fwstate(pmlmepriv, _FW_LINKED) == false) &&
(pdmpriv->EntryMinUndecoratedSmoothedPWDB == 0))
pdmpriv->MinUndecoratedPWDBForDM = 0;
if (check_fwstate(pmlmepriv, _FW_LINKED) == true)
pdmpriv->MinUndecoratedPWDBForDM = pdmpriv->EntryMinUndecoratedSmoothedPWDB;
else
pdmpriv->MinUndecoratedPWDBForDM = pdmpriv->EntryMinUndecoratedSmoothedPWDB;
}
void odm_RSSIMonitorCheckCE(struct odm_dm_struct *pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
int i;
int tmpEntryMaxPWDB = 0, tmpEntryMinPWDB = 0xff;
u8 sta_cnt = 0;
u32 PWDB_rssi[NUM_STA] = {0};
struct sta_info *psta;
u8 bcast_addr[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
if (!check_fwstate(&Adapter->mlmepriv, _FW_LINKED))
return;
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
psta = pDM_Odm->pODM_StaInfo[i];
if (IS_STA_VALID(psta) &&
(psta->state & WIFI_ASOC_STATE) &&
!_rtw_memcmp(psta->hwaddr, bcast_addr, ETH_ALEN) &&
!_rtw_memcmp(psta->hwaddr, myid(&Adapter->eeprompriv), ETH_ALEN)) {
if (psta->rssi_stat.UndecoratedSmoothedPWDB < tmpEntryMinPWDB)
tmpEntryMinPWDB = psta->rssi_stat.UndecoratedSmoothedPWDB;
if (psta->rssi_stat.UndecoratedSmoothedPWDB > tmpEntryMaxPWDB)
tmpEntryMaxPWDB = psta->rssi_stat.UndecoratedSmoothedPWDB;
if (psta->rssi_stat.UndecoratedSmoothedPWDB != (-1))
PWDB_rssi[sta_cnt++] = (psta->mac_id | (psta->rssi_stat.UndecoratedSmoothedPWDB<<16));
}
}
for (i = 0; i < sta_cnt; i++) {
if (PWDB_rssi[i] != (0)) {
if (pHalData->fw_ractrl) {
} else {
ODM_RA_SetRSSI_8188E(
&(pHalData->odmpriv), (PWDB_rssi[i]&0xFF), (u8)((PWDB_rssi[i]>>16) & 0xFF));
}
}
}
if (tmpEntryMaxPWDB != 0)
pdmpriv->EntryMaxUndecoratedSmoothedPWDB = tmpEntryMaxPWDB;
else
pdmpriv->EntryMaxUndecoratedSmoothedPWDB = 0;
if (tmpEntryMinPWDB != 0xff)
pdmpriv->EntryMinUndecoratedSmoothedPWDB = tmpEntryMinPWDB;
else
pdmpriv->EntryMinUndecoratedSmoothedPWDB = 0;
FindMinimumRSSI(Adapter);
ODM_CmnInfoUpdate(&pHalData->odmpriv , ODM_CMNINFO_RSSI_MIN, pdmpriv->MinUndecoratedPWDBForDM);
}
void odm_TXPowerTrackingInit(struct odm_dm_struct *pDM_Odm)
{
odm_TXPowerTrackingThermalMeterInit(pDM_Odm);
}
void odm_TXPowerTrackingThermalMeterInit(struct odm_dm_struct *pDM_Odm)
{
pDM_Odm->RFCalibrateInfo.bTXPowerTracking = true;
pDM_Odm->RFCalibrateInfo.TXPowercount = 0;
pDM_Odm->RFCalibrateInfo.bTXPowerTrackingInit = false;
if (*(pDM_Odm->mp_mode) != 1)
pDM_Odm->RFCalibrateInfo.TxPowerTrackControl = true;
MSG_88E("pDM_Odm TxPowerTrackControl = %d\n", pDM_Odm->RFCalibrateInfo.TxPowerTrackControl);
pDM_Odm->RFCalibrateInfo.TxPowerTrackControl = true;
}
void ODM_TXPowerTrackingCheck(struct odm_dm_struct *pDM_Odm)
{
odm_TXPowerTrackingCheckCE(pDM_Odm);
}
void odm_TXPowerTrackingCheckCE(struct odm_dm_struct *pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
if (!(pDM_Odm->SupportAbility & ODM_RF_TX_PWR_TRACK))
return;
if (!pDM_Odm->RFCalibrateInfo.TM_Trigger) {
PHY_SetRFReg(Adapter, RF_PATH_A, RF_T_METER_88E, BIT17 | BIT16, 0x03);
pDM_Odm->RFCalibrateInfo.TM_Trigger = 1;
return;
} else {
odm_TXPowerTrackingCallback_ThermalMeter_8188E(Adapter);
pDM_Odm->RFCalibrateInfo.TM_Trigger = 0;
}
}
void odm_SwAntDivChkAntSwitchCallback(void *FunctionContext)
{
}
void odm_InitHybridAntDiv(struct odm_dm_struct *pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_ANT_DIV)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Return: Not Support HW AntDiv\n"));
return;
}
ODM_AntennaDiversityInit_88E(pDM_Odm);
}
void odm_HwAntDiv(struct odm_dm_struct *pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_ANT_DIV)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Return: Not Support HW AntDiv\n"));
return;
}
ODM_AntennaDiversity_88E(pDM_Odm);
}
void ODM_EdcaTurboInit(struct odm_dm_struct *pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = false;
pDM_Odm->DM_EDCA_Table.bIsCurRDLState = false;
Adapter->recvpriv.bIsAnyNonBEPkts = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial VO PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_VO_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial VI PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_VI_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial BE PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_BE_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial BK PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_BK_PARAM)));
}
void odm_EdcaTurboCheck(struct odm_dm_struct *pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("odm_EdcaTurboCheck========================>\n"));
if (!(pDM_Odm->SupportAbility & ODM_MAC_EDCA_TURBO))
return;
odm_EdcaTurboCheckCE(pDM_Odm);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("<========================odm_EdcaTurboCheck\n"));
}
void odm_EdcaTurboCheckCE(struct odm_dm_struct *pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
u32 trafficIndex;
u32 edca_param;
u64 cur_tx_bytes = 0;
u64 cur_rx_bytes = 0;
u8 bbtchange = false;
struct hal_data_8188e *pHalData = GET_HAL_DATA(Adapter);
struct xmit_priv *pxmitpriv = &(Adapter->xmitpriv);
struct recv_priv *precvpriv = &(Adapter->recvpriv);
struct registry_priv *pregpriv = &Adapter->registrypriv;
struct mlme_ext_priv *pmlmeext = &(Adapter->mlmeextpriv);
struct mlme_ext_info *pmlmeinfo = &(pmlmeext->mlmext_info);
if ((pregpriv->wifi_spec == 1))
goto dm_CheckEdcaTurbo_EXIT;
if (pmlmeinfo->assoc_AP_vendor >= HT_IOT_PEER_MAX)
goto dm_CheckEdcaTurbo_EXIT;
if ((bbtchange) || (!precvpriv->bIsAnyNonBEPkts)) {
cur_tx_bytes = pxmitpriv->tx_bytes - pxmitpriv->last_tx_bytes;
cur_rx_bytes = precvpriv->rx_bytes - precvpriv->last_rx_bytes;
if ((pmlmeinfo->assoc_AP_vendor == HT_IOT_PEER_RALINK) ||
(pmlmeinfo->assoc_AP_vendor == HT_IOT_PEER_ATHEROS)) {
if (cur_tx_bytes > (cur_rx_bytes << 2)) {
trafficIndex = UP_LINK;
} else {
trafficIndex = DOWN_LINK;
}
} else {
if (cur_rx_bytes > (cur_tx_bytes << 2)) {
trafficIndex = DOWN_LINK;
} else {
trafficIndex = UP_LINK;
}
}
if ((pDM_Odm->DM_EDCA_Table.prv_traffic_idx != trafficIndex) || (!pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA)) {
if ((pmlmeinfo->assoc_AP_vendor == HT_IOT_PEER_CISCO) && (pmlmeext->cur_wireless_mode & WIRELESS_11_24N))
edca_param = EDCAParam[pmlmeinfo->assoc_AP_vendor][trafficIndex];
else
edca_param = EDCAParam[HT_IOT_PEER_UNKNOWN][trafficIndex];
rtw_write32(Adapter, REG_EDCA_BE_PARAM, edca_param);
pDM_Odm->DM_EDCA_Table.prv_traffic_idx = trafficIndex;
}
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = true;
} else {
if (pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA) {
rtw_write32(Adapter, REG_EDCA_BE_PARAM, pHalData->AcParam_BE);
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = false;
}
}
dm_CheckEdcaTurbo_EXIT:
precvpriv->bIsAnyNonBEPkts = false;
pxmitpriv->last_tx_bytes = pxmitpriv->tx_bytes;
precvpriv->last_rx_bytes = precvpriv->rx_bytes;
}
u32 ConvertTo_dB(u32 Value)
{
u8 i;
u8 j;
u32 dB;
Value = Value & 0xFFFF;
for (i = 0; i < 8; i++) {
if (Value <= dB_Invert_Table[i][11])
break;
}
if (i >= 8)
return 96;
for (j = 0; j < 12; j++) {
if (Value <= dB_Invert_Table[i][j])
break;
}
dB = i*12 + j + 1;
return dB;
}
