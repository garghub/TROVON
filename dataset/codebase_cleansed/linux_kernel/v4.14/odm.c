void ODM_DMInit(PDM_ODM_T pDM_Odm)
{
odm_CommonInfoSelfInit(pDM_Odm);
odm_CmnInfoInit_Debug(pDM_Odm);
odm_DIGInit(pDM_Odm);
odm_NHMCounterStatisticsInit(pDM_Odm);
odm_AdaptivityInit(pDM_Odm);
odm_RateAdaptiveMaskInit(pDM_Odm);
ODM_CfoTrackingInit(pDM_Odm);
ODM_EdcaTurboInit(pDM_Odm);
odm_RSSIMonitorInit(pDM_Odm);
odm_TXPowerTrackingInit(pDM_Odm);
ODM_ClearTxPowerTrackingState(pDM_Odm);
if (*(pDM_Odm->mp_mode) != 1)
odm_PathDiversityInit(pDM_Odm);
odm_DynamicBBPowerSavingInit(pDM_Odm);
odm_DynamicTxPowerInit(pDM_Odm);
odm_SwAntDetectInit(pDM_Odm);
}
void ODM_DMWatchdog(PDM_ODM_T pDM_Odm)
{
odm_CommonInfoSelfUpdate(pDM_Odm);
odm_BasicDbgMessage(pDM_Odm);
odm_FalseAlarmCounterStatistics(pDM_Odm);
odm_NHMCounterStatistics(pDM_Odm);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG(): RSSI = 0x%x\n", pDM_Odm->RSSI_Min));
odm_RSSIMonitorCheck(pDM_Odm);
if ((adapter_to_pwrctl(pDM_Odm->Adapter)->pwr_mode != PS_MODE_ACTIVE)
) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("----Step1: odm_DIG is in LPS mode\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("---Step2: 8723AS is in LPS mode\n"));
odm_DIGbyRSSI_LPS(pDM_Odm);
} else
odm_DIG(pDM_Odm);
{
pDIG_T pDM_DigTable = &pDM_Odm->DM_DigTable;
odm_Adaptivity(pDM_Odm, pDM_DigTable->CurIGValue);
}
odm_CCKPacketDetectionThresh(pDM_Odm);
if (*(pDM_Odm->pbPowerSaving) == true)
return;
odm_RefreshRateAdaptiveMask(pDM_Odm);
odm_EdcaTurboCheck(pDM_Odm);
odm_PathDiversity(pDM_Odm);
ODM_CfoTracking(pDM_Odm);
ODM_TXPowerTrackingCheck(pDM_Odm);
pDM_Odm->PhyDbgInfo.NumQryBeaconPkt = 0;
}
void ODM_CmnInfoInit(PDM_ODM_T pDM_Odm, ODM_CMNINFO_E CmnInfo, u32 Value)
{
switch (CmnInfo) {
case ODM_CMNINFO_ABILITY:
pDM_Odm->SupportAbility = (u32)Value;
break;
case ODM_CMNINFO_RF_TYPE:
pDM_Odm->RFType = (u8)Value;
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
case ODM_CMNINFO_RFE_TYPE:
pDM_Odm->RFEType = (u8)Value;
break;
case ODM_CMNINFO_RF_ANTENNA_TYPE:
pDM_Odm->AntDivType = (u8)Value;
break;
case ODM_CMNINFO_BOARD_TYPE:
pDM_Odm->BoardType = (u8)Value;
break;
case ODM_CMNINFO_PACKAGE_TYPE:
pDM_Odm->PackageType = (u8)Value;
break;
case ODM_CMNINFO_EXT_LNA:
pDM_Odm->ExtLNA = (u8)Value;
break;
case ODM_CMNINFO_5G_EXT_LNA:
pDM_Odm->ExtLNA5G = (u8)Value;
break;
case ODM_CMNINFO_EXT_PA:
pDM_Odm->ExtPA = (u8)Value;
break;
case ODM_CMNINFO_5G_EXT_PA:
pDM_Odm->ExtPA5G = (u8)Value;
break;
case ODM_CMNINFO_GPA:
pDM_Odm->TypeGPA = (ODM_TYPE_GPA_E)Value;
break;
case ODM_CMNINFO_APA:
pDM_Odm->TypeAPA = (ODM_TYPE_APA_E)Value;
break;
case ODM_CMNINFO_GLNA:
pDM_Odm->TypeGLNA = (ODM_TYPE_GLNA_E)Value;
break;
case ODM_CMNINFO_ALNA:
pDM_Odm->TypeALNA = (ODM_TYPE_ALNA_E)Value;
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
}
void ODM_CmnInfoHook(PDM_ODM_T pDM_Odm, ODM_CMNINFO_E CmnInfo, void *pValue)
{
switch (CmnInfo) {
case ODM_CMNINFO_MAC_PHY_MODE:
pDM_Odm->pMacPhyMode = pValue;
break;
case ODM_CMNINFO_TX_UNI:
pDM_Odm->pNumTxBytesUnicast = pValue;
break;
case ODM_CMNINFO_RX_UNI:
pDM_Odm->pNumRxBytesUnicast = pValue;
break;
case ODM_CMNINFO_WM_MODE:
pDM_Odm->pwirelessmode = pValue;
break;
case ODM_CMNINFO_BAND:
pDM_Odm->pBandType = pValue;
break;
case ODM_CMNINFO_SEC_CHNL_OFFSET:
pDM_Odm->pSecChOffset = pValue;
break;
case ODM_CMNINFO_SEC_MODE:
pDM_Odm->pSecurity = pValue;
break;
case ODM_CMNINFO_BW:
pDM_Odm->pBandWidth = pValue;
break;
case ODM_CMNINFO_CHNL:
pDM_Odm->pChannel = pValue;
break;
case ODM_CMNINFO_DMSP_GET_VALUE:
pDM_Odm->pbGetValueFromOtherMac = pValue;
break;
case ODM_CMNINFO_BUDDY_ADAPTOR:
pDM_Odm->pBuddyAdapter = pValue;
break;
case ODM_CMNINFO_DMSP_IS_MASTER:
pDM_Odm->pbMasterOfDMSP = pValue;
break;
case ODM_CMNINFO_SCAN:
pDM_Odm->pbScanInProcess = pValue;
break;
case ODM_CMNINFO_POWER_SAVING:
pDM_Odm->pbPowerSaving = pValue;
break;
case ODM_CMNINFO_ONE_PATH_CCA:
pDM_Odm->pOnePathCCA = pValue;
break;
case ODM_CMNINFO_DRV_STOP:
pDM_Odm->pbDriverStopped = pValue;
break;
case ODM_CMNINFO_PNP_IN:
pDM_Odm->pbDriverIsGoingToPnpSetPowerSleep = pValue;
break;
case ODM_CMNINFO_INIT_ON:
pDM_Odm->pinit_adpt_in_progress = pValue;
break;
case ODM_CMNINFO_ANT_TEST:
pDM_Odm->pAntennaTest = pValue;
break;
case ODM_CMNINFO_NET_CLOSED:
pDM_Odm->pbNet_closed = pValue;
break;
case ODM_CMNINFO_FORCED_RATE:
pDM_Odm->pForcedDataRate = pValue;
break;
case ODM_CMNINFO_FORCED_IGI_LB:
pDM_Odm->pu1ForcedIgiLb = pValue;
break;
case ODM_CMNINFO_MP_MODE:
pDM_Odm->mp_mode = pValue;
break;
default:
break;
}
}
void ODM_CmnInfoPtrArrayHook(
PDM_ODM_T pDM_Odm,
ODM_CMNINFO_E CmnInfo,
u16 Index,
void *pValue
)
{
switch (CmnInfo) {
case ODM_CMNINFO_STA_STATUS:
pDM_Odm->pODM_StaInfo[Index] = (PSTA_INFO_T)pValue;
break;
default:
break;
}
}
void ODM_CmnInfoUpdate(PDM_ODM_T pDM_Odm, u32 CmnInfo, u64 Value)
{
switch (CmnInfo) {
case ODM_CMNINFO_LINK_IN_PROGRESS:
pDM_Odm->bLinkInProcess = (bool)Value;
break;
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
case ODM_CMNINFO_STATION_STATE:
pDM_Odm->bsta_state = (bool)Value;
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
case ODM_CMNINFO_BT_ENABLED:
pDM_Odm->bBtEnabled = (bool)Value;
break;
case ODM_CMNINFO_BT_HS_CONNECT_PROCESS:
pDM_Odm->bBtConnectProcess = (bool)Value;
break;
case ODM_CMNINFO_BT_HS_RSSI:
pDM_Odm->btHsRssi = (u8)Value;
break;
case ODM_CMNINFO_BT_OPERATION:
pDM_Odm->bBtHsOperation = (bool)Value;
break;
case ODM_CMNINFO_BT_LIMITED_DIG:
pDM_Odm->bBtLimitedDig = (bool)Value;
break;
case ODM_CMNINFO_BT_DISABLE_EDCA:
pDM_Odm->bBtDisableEdcaTurbo = (bool)Value;
break;
default:
break;
}
}
void odm_CommonInfoSelfInit(PDM_ODM_T pDM_Odm)
{
pDM_Odm->bCckHighPower = (bool) PHY_QueryBBReg(pDM_Odm->Adapter, ODM_REG(CCK_RPT_FORMAT, pDM_Odm), ODM_BIT(CCK_RPT_FORMAT, pDM_Odm));
pDM_Odm->RFPathRxEnable = (u8) PHY_QueryBBReg(pDM_Odm->Adapter, ODM_REG(BB_RX_PATH, pDM_Odm), ODM_BIT(BB_RX_PATH, pDM_Odm));
ODM_InitDebugSetting(pDM_Odm);
pDM_Odm->TxRate = 0xFF;
}
void odm_CommonInfoSelfUpdate(PDM_ODM_T pDM_Odm)
{
u8 EntryCnt = 0;
u8 i;
PSTA_INFO_T pEntry;
if (*(pDM_Odm->pBandWidth) == ODM_BW40M) {
if (*(pDM_Odm->pSecChOffset) == 1)
pDM_Odm->ControlChannel = *(pDM_Odm->pChannel)-2;
else if (*(pDM_Odm->pSecChOffset) == 2)
pDM_Odm->ControlChannel = *(pDM_Odm->pChannel)+2;
} else
pDM_Odm->ControlChannel = *(pDM_Odm->pChannel);
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
void odm_CmnInfoInit_Debug(PDM_ODM_T pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("odm_CmnInfoInit_Debug ==>\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportPlatform =%d\n", pDM_Odm->SupportPlatform));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportAbility = 0x%x\n", pDM_Odm->SupportAbility));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportInterface =%d\n", pDM_Odm->SupportInterface));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("SupportICType = 0x%x\n", pDM_Odm->SupportICType));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("CutVersion =%d\n", pDM_Odm->CutVersion));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("FabVersion =%d\n", pDM_Odm->FabVersion));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("RFType =%d\n", pDM_Odm->RFType));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("BoardType =%d\n", pDM_Odm->BoardType));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("ExtLNA =%d\n", pDM_Odm->ExtLNA));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("ExtPA =%d\n", pDM_Odm->ExtPA));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("ExtTRSW =%d\n", pDM_Odm->ExtTRSW));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("PatchID =%d\n", pDM_Odm->PatchID));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bInHctTest =%d\n", pDM_Odm->bInHctTest));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bWIFITest =%d\n", pDM_Odm->bWIFITest));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bDualMacSmartConcurrent =%d\n", pDM_Odm->bDualMacSmartConcurrent));
}
void odm_BasicDbgMessage(PDM_ODM_T pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("odm_BasicDbgMsg ==>\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bLinked = %d, RSSI_Min = %d,\n",
pDM_Odm->bLinked, pDM_Odm->RSSI_Min));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("RxRate = 0x%x, RSSI_A = %d, RSSI_B = %d\n",
pDM_Odm->RxRate, pDM_Odm->RSSI_A, pDM_Odm->RSSI_B));
}
void odm_RateAdaptiveMaskInit(PDM_ODM_T pDM_Odm)
{
PODM_RATE_ADAPTIVE pOdmRA = &pDM_Odm->RateAdaptive;
pOdmRA->Type = DM_Type_ByDriver;
if (pOdmRA->Type == DM_Type_ByDriver)
pDM_Odm->bUseRAMask = true;
else
pDM_Odm->bUseRAMask = false;
pOdmRA->RATRState = DM_RATR_STA_INIT;
pOdmRA->LdpcThres = 35;
pOdmRA->bUseLdpc = false;
pOdmRA->HighRSSIThresh = 50;
pOdmRA->LowRSSIThresh = 20;
}
u32 ODM_Get_Rate_Bitmap(
PDM_ODM_T pDM_Odm,
u32 macid,
u32 ra_mask,
u8 rssi_level
)
{
PSTA_INFO_T pEntry;
u32 rate_bitmap = 0;
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
case (ODM_WM_G):
case (ODM_WM_A):
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
case (ODM_WM_B|ODM_WM_N24G):
case (ODM_WM_G|ODM_WM_N24G):
case (ODM_WM_A|ODM_WM_N5G):
if (pDM_Odm->RFType == ODM_1T2R || pDM_Odm->RFType == ODM_1T1R) {
if (rssi_level == DM_RATR_STA_HIGH)
rate_bitmap = 0x000f0000;
else if (rssi_level == DM_RATR_STA_MIDDLE)
rate_bitmap = 0x000ff000;
else {
if (*(pDM_Odm->pBandWidth) == ODM_BW40M)
rate_bitmap = 0x000ff015;
else
rate_bitmap = 0x000ff005;
}
} else {
if (rssi_level == DM_RATR_STA_HIGH)
rate_bitmap = 0x0f8f0000;
else if (rssi_level == DM_RATR_STA_MIDDLE)
rate_bitmap = 0x0f8ff000;
else {
if (*(pDM_Odm->pBandWidth) == ODM_BW40M)
rate_bitmap = 0x0f8ff015;
else
rate_bitmap = 0x0f8ff005;
}
}
break;
case (ODM_WM_AC|ODM_WM_G):
if (rssi_level == 1)
rate_bitmap = 0xfc3f0000;
else if (rssi_level == 2)
rate_bitmap = 0xfffff000;
else
rate_bitmap = 0xffffffff;
break;
case (ODM_WM_AC|ODM_WM_A):
if (pDM_Odm->RFType == RF_1T1R) {
if (rssi_level == 1)
rate_bitmap = 0x003f8000;
else if (rssi_level == 2)
rate_bitmap = 0x003ff000;
else
rate_bitmap = 0x003ff010;
} else {
if (rssi_level == 1)
rate_bitmap = 0xfe3f8000;
else if (rssi_level == 2)
rate_bitmap = 0xfffff000;
else
rate_bitmap = 0xfffff010;
}
break;
default:
if (pDM_Odm->RFType == RF_1T2R)
rate_bitmap = 0x000fffff;
else
rate_bitmap = 0x0fffffff;
break;
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD, (" ==> rssi_level:0x%02x, WirelessMode:0x%02x, rate_bitmap:0x%08x\n", rssi_level, WirelessMode, rate_bitmap));
return (ra_mask&rate_bitmap);
}
void odm_RefreshRateAdaptiveMask(PDM_ODM_T pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_TRACE, ("odm_RefreshRateAdaptiveMask()---------->\n"));
if (!(pDM_Odm->SupportAbility & ODM_BB_RA_MASK)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_TRACE, ("odm_RefreshRateAdaptiveMask(): Return cos not supported\n"));
return;
}
odm_RefreshRateAdaptiveMaskCE(pDM_Odm);
}
void odm_RefreshRateAdaptiveMaskCE(PDM_ODM_T pDM_Odm)
{
u8 i;
struct adapter *padapter = pDM_Odm->Adapter;
if (padapter->bDriverStopped) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_TRACE, ("<---- odm_RefreshRateAdaptiveMask(): driver is going to unload\n"));
return;
}
if (!pDM_Odm->bUseRAMask) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD, ("<---- odm_RefreshRateAdaptiveMask(): driver does not control rate adaptive mask\n"));
return;
}
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
PSTA_INFO_T pstat = pDM_Odm->pODM_StaInfo[i];
if (IS_STA_VALID(pstat)) {
if (IS_MCAST(pstat->hwaddr))
continue;
if (IS_MCAST(pstat->hwaddr))
continue;
if (true == ODM_RAStateCheck(pDM_Odm, pstat->rssi_stat.UndecoratedSmoothedPWDB, false, &pstat->rssi_level)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD, ("RSSI:%d, RSSI_LEVEL:%d\n", pstat->rssi_stat.UndecoratedSmoothedPWDB, pstat->rssi_level));
rtw_hal_update_ra_mask(pstat, pstat->rssi_level);
}
}
}
}
bool ODM_RAStateCheck(
PDM_ODM_T pDM_Odm,
s32 RSSI,
bool bForceUpdate,
u8 *pRATRState
)
{
PODM_RATE_ADAPTIVE pRA = &pDM_Odm->RateAdaptive;
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
void odm_RSSIMonitorInit(PDM_ODM_T pDM_Odm)
{
pRA_T pRA_Table = &pDM_Odm->DM_RA_Table;
pRA_Table->firstconnect = false;
}
void odm_RSSIMonitorCheck(PDM_ODM_T pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_RSSI_MONITOR))
return;
odm_RSSIMonitorCheckCE(pDM_Odm);
}
static void FindMinimumRSSI(struct adapter *padapter)
{
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
PDM_ODM_T pDM_Odm = &(pHalData->odmpriv);
if (
(pDM_Odm->bLinked != true) &&
(pdmpriv->EntryMinUndecoratedSmoothedPWDB == 0)
) {
pdmpriv->MinUndecoratedPWDBForDM = 0;
} else
pdmpriv->MinUndecoratedPWDBForDM = pdmpriv->EntryMinUndecoratedSmoothedPWDB;
}
void odm_RSSIMonitorCheckCE(PDM_ODM_T pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
int i;
int tmpEntryMaxPWDB = 0, tmpEntryMinPWDB = 0xff;
u8 sta_cnt = 0;
u32 PWDB_rssi[NUM_STA] = {0};
bool FirstConnect = false;
pRA_T pRA_Table = &pDM_Odm->DM_RA_Table;
if (pDM_Odm->bLinked != true)
return;
FirstConnect = (pDM_Odm->bLinked) && (pRA_Table->firstconnect == false);
pRA_Table->firstconnect = pDM_Odm->bLinked;
{
struct sta_info *psta;
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
psta = pDM_Odm->pODM_StaInfo[i];
if (IS_STA_VALID(psta)) {
if (IS_MCAST(psta->hwaddr))
continue;
if (psta->rssi_stat.UndecoratedSmoothedPWDB == (-1))
continue;
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
if (pHalData->fw_ractrl == true)
rtl8723b_set_rssi_cmd(Adapter, (u8 *)(&PWDB_rssi[i]));
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
pDM_Odm->RSSI_Min = pdmpriv->MinUndecoratedPWDBForDM;
}
void odm_TXPowerTrackingInit(PDM_ODM_T pDM_Odm)
{
odm_TXPowerTrackingThermalMeterInit(pDM_Odm);
}
static u8 getSwingIndex(PDM_ODM_T pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
u8 i = 0;
u32 bbSwing;
u32 swingTableSize;
u32 *pSwingTable;
bbSwing = PHY_QueryBBReg(Adapter, rOFDM0_XATxIQImbalance, 0xFFC00000);
pSwingTable = OFDMSwingTable_New;
swingTableSize = OFDM_TABLE_SIZE;
for (i = 0; i < swingTableSize; ++i) {
u32 tableValue = pSwingTable[i];
if (tableValue >= 0x100000)
tableValue >>= 22;
if (bbSwing == tableValue)
break;
}
return i;
}
void odm_TXPowerTrackingThermalMeterInit(PDM_ODM_T pDM_Odm)
{
u8 defaultSwingIndex = getSwingIndex(pDM_Odm);
u8 p = 0;
struct adapter *Adapter = pDM_Odm->Adapter;
struct hal_com_data *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
pdmpriv->bTXPowerTracking = true;
pdmpriv->TXPowercount = 0;
pdmpriv->bTXPowerTrackingInit = false;
if (*(pDM_Odm->mp_mode) != 1)
pdmpriv->TxPowerTrackControl = true;
else
pdmpriv->TxPowerTrackControl = false;
pDM_Odm->RFCalibrateInfo.ThermalValue = pHalData->EEPROMThermalMeter;
pDM_Odm->RFCalibrateInfo.ThermalValue_IQK = pHalData->EEPROMThermalMeter;
pDM_Odm->RFCalibrateInfo.ThermalValue_LCK = pHalData->EEPROMThermalMeter;
pDM_Odm->DefaultOfdmIndex = (defaultSwingIndex >= OFDM_TABLE_SIZE) ? 30 : defaultSwingIndex;
pDM_Odm->DefaultCckIndex = 20;
pDM_Odm->BbSwingIdxCckBase = pDM_Odm->DefaultCckIndex;
pDM_Odm->RFCalibrateInfo.CCK_index = pDM_Odm->DefaultCckIndex;
for (p = ODM_RF_PATH_A; p < MAX_RF_PATH; ++p) {
pDM_Odm->BbSwingIdxOfdmBase[p] = pDM_Odm->DefaultOfdmIndex;
pDM_Odm->RFCalibrateInfo.OFDM_index[p] = pDM_Odm->DefaultOfdmIndex;
pDM_Odm->RFCalibrateInfo.DeltaPowerIndex[p] = 0;
pDM_Odm->RFCalibrateInfo.DeltaPowerIndexLast[p] = 0;
pDM_Odm->RFCalibrateInfo.PowerIndexOffset[p] = 0;
}
}
void ODM_TXPowerTrackingCheck(PDM_ODM_T pDM_Odm)
{
odm_TXPowerTrackingCheckCE(pDM_Odm);
}
void odm_TXPowerTrackingCheckCE(PDM_ODM_T pDM_Odm)
{
struct adapter *Adapter = pDM_Odm->Adapter;
if (!(pDM_Odm->SupportAbility & ODM_RF_TX_PWR_TRACK))
return;
if (!pDM_Odm->RFCalibrateInfo.TM_Trigger) {
PHY_SetRFReg(pDM_Odm->Adapter, ODM_RF_PATH_A, RF_T_METER_NEW, (BIT17 | BIT16), 0x03);
pDM_Odm->RFCalibrateInfo.TM_Trigger = 1;
return;
} else {
ODM_TXPowerTrackingCallback_ThermalMeter(Adapter);
pDM_Odm->RFCalibrateInfo.TM_Trigger = 0;
}
}
void odm_SwAntDetectInit(PDM_ODM_T pDM_Odm)
{
pSWAT_T pDM_SWAT_Table = &pDM_Odm->DM_SWAT_Table;
pDM_SWAT_Table->SWAS_NoLink_BK_Reg92c = rtw_read32(pDM_Odm->Adapter, rDPDT_control);
pDM_SWAT_Table->PreAntenna = MAIN_ANT;
pDM_SWAT_Table->CurAntenna = MAIN_ANT;
pDM_SWAT_Table->SWAS_NoLink_State = 0;
}
