void ODM23a_DMInit(struct dm_odm_t *pDM_Odm)
{
odm_CommonInfoSelfInit23a(pDM_Odm);
odm_CmnInfoInit_Debug23a(pDM_Odm);
odm_DIG23aInit(pDM_Odm);
odm_RateAdaptiveMaskInit23a(pDM_Odm);
odm23a_DynBBPSInit(pDM_Odm);
odm_DynamicTxPower23aInit(pDM_Odm);
odm_TXPowerTrackingInit23a(pDM_Odm);
ODM_EdcaTurboInit23a(pDM_Odm);
}
void ODM_DMWatchdog23a(struct rtw_adapter *adapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(adapter);
struct dm_odm_t *pDM_Odm = &pHalData->odmpriv;
struct pwrctrl_priv *pwrctrlpriv = &adapter->pwrctrlpriv;
odm_CmnInfoUpdate_Debug23a(pDM_Odm);
odm_CommonInfoSelfUpdate(pHalData);
odm_FalseAlarmCounterStatistics23a(pDM_Odm);
odm_RSSIMonitorCheck23a(pDM_Odm);
if ((pDM_Odm->Adapter->pwrctrlpriv.pwr_mode != PS_MODE_ACTIVE) &&
(pDM_Odm->SupportICType & ODM_RTL8723A)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("----Step1: odm_DIG23a is in LPS mode\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("---Step2: 8723AS is in LPS mode\n"));
odm_DIG23abyRSSI_LPS(pDM_Odm);
} else {
odm_DIG23a(adapter);
}
odm_CCKPacketDetectionThresh23a(pDM_Odm);
if (pwrctrlpriv->bpower_saving)
return;
odm_RefreshRateAdaptiveMask23a(pDM_Odm);
odm_DynamicBBPowerSaving23a(pDM_Odm);
ODM_TXPowerTrackingCheck23a(pDM_Odm);
odm_EdcaTurboCheck23a(pDM_Odm);
odm_dtc(pDM_Odm);
}
void ODM_CmnInfoInit23a(struct dm_odm_t *pDM_Odm,
enum odm_cmninfo CmnInfo,
u32 Value
)
{
switch (CmnInfo) {
case ODM_CMNINFO_PLATFORM:
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
void ODM_CmnInfoPtrArrayHook23a(struct dm_odm_t *pDM_Odm, enum odm_cmninfo CmnInfo,
u16 Index, void *pValue)
{
switch (CmnInfo) {
case ODM_CMNINFO_STA_STATUS:
pDM_Odm->pODM_StaInfo[Index] = (struct sta_info *)pValue;
break;
default:
break;
}
}
void ODM_CmnInfoUpdate23a(struct dm_odm_t *pDM_Odm, u32 CmnInfo, u64 Value)
{
switch (CmnInfo) {
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
void odm_CommonInfoSelfInit23a(struct dm_odm_t *pDM_Odm
)
{
pDM_Odm->bCckHighPower =
(bool) ODM_GetBBReg(pDM_Odm, rFPGA0_XA_HSSIParameter2, BIT(9));
pDM_Odm->RFPathRxEnable =
(u8) ODM_GetBBReg(pDM_Odm, rOFDM0_TRxPathEnable, 0x0F);
ODM_InitDebugSetting23a(pDM_Odm);
}
static void odm_CommonInfoSelfUpdate(struct hal_data_8723a *pHalData)
{
struct dm_odm_t *pDM_Odm = &pHalData->odmpriv;
struct sta_info *pEntry;
u8 EntryCnt = 0;
u8 i;
if (pHalData->CurrentChannelBW == HT_CHANNEL_WIDTH_40) {
if (pHalData->nCur40MhzPrimeSC == 1)
pDM_Odm->ControlChannel = pHalData->CurrentChannel - 2;
else if (pHalData->nCur40MhzPrimeSC == 2)
pDM_Odm->ControlChannel = pHalData->CurrentChannel + 2;
} else {
pDM_Odm->ControlChannel = pHalData->CurrentChannel;
}
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
pEntry = pDM_Odm->pODM_StaInfo[i];
if (pEntry)
EntryCnt++;
}
if (EntryCnt == 1)
pDM_Odm->bOneEntryOnly = true;
else
pDM_Odm->bOneEntryOnly = false;
}
void odm_CmnInfoInit_Debug23a(struct dm_odm_t *pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("odm_CmnInfoInit_Debug23a ==>\n"));
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
void odm_CmnInfoUpdate_Debug23a(struct dm_odm_t *pDM_Odm)
{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("odm_CmnInfoUpdate_Debug23a ==>\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bWIFI_Direct =%d\n", pDM_Odm->bWIFI_Direct));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bWIFI_Display =%d\n", pDM_Odm->bWIFI_Display));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("bLinked =%d\n", pDM_Odm->bLinked));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("RSSI_Min =%d\n", pDM_Odm->RSSI_Min));
}
void ODM_Write_DIG23a(struct dm_odm_t *pDM_Odm,
u8 CurrentIGI
)
{
struct dig_t *pDM_DigTable = &pDM_Odm->DM_DigTable;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("ODM_REG(IGI_A, pDM_Odm) = 0x%x, ODM_BIT(IGI, pDM_Odm) = 0x%x \n",
ODM_REG(IGI_A, pDM_Odm), ODM_BIT(IGI, pDM_Odm)));
if (pDM_DigTable->CurIGValue != CurrentIGI) {
ODM_SetBBReg(pDM_Odm, ODM_REG(IGI_A, pDM_Odm), ODM_BIT(IGI, pDM_Odm), CurrentIGI);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("CurrentIGI(0x%02x). \n", CurrentIGI));
pDM_DigTable->CurIGValue = CurrentIGI;
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("ODM_Write_DIG23a():CurrentIGI = 0x%x \n", CurrentIGI));
}
void odm_DIG23abyRSSI_LPS(struct dm_odm_t *pDM_Odm)
{
struct rtw_adapter *pAdapter = pDM_Odm->Adapter;
struct false_alarm_stats *pFalseAlmCnt = &pDM_Odm->FalseAlmCnt;
u8 RSSI_Lower = DM_DIG_MIN_NIC;
u8 bFwCurrentInPSMode = false;
u8 CurrentIGI = pDM_Odm->RSSI_Min;
if (!(pDM_Odm->SupportICType & ODM_RTL8723A))
return;
CurrentIGI = CurrentIGI+RSSI_OFFSET_DIG;
bFwCurrentInPSMode = pAdapter->pwrctrlpriv.bFwCurrentInPSMode;
if (bFwCurrentInPSMode) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("---Neil---odm_DIG23a is in LPS mode\n"));
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
ODM_Write_DIG23a(pDM_Odm, CurrentIGI);
}
void odm_DIG23aInit(struct dm_odm_t *pDM_Odm)
{
struct dig_t *pDM_DigTable = &pDM_Odm->DM_DigTable;
pDM_DigTable->CurIGValue = (u8) ODM_GetBBReg(pDM_Odm, ODM_REG(IGI_A, pDM_Odm), ODM_BIT(IGI, pDM_Odm));
pDM_DigTable->RssiLowThresh = DM_DIG_THRESH_LOW;
pDM_DigTable->RssiHighThresh = DM_DIG_THRESH_HIGH;
pDM_DigTable->FALowThresh = DM_FALSEALARM_THRESH_LOW;
pDM_DigTable->FAHighThresh = DM_FALSEALARM_THRESH_HIGH;
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
}
void odm_DIG23a(struct rtw_adapter *adapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(adapter);
struct dm_odm_t *pDM_Odm = &pHalData->odmpriv;
struct dig_t *pDM_DigTable = &pDM_Odm->DM_DigTable;
struct false_alarm_stats *pFalseAlmCnt = &pDM_Odm->FalseAlmCnt;
u8 DIG_Dynamic_MIN;
u8 DIG_MaxOfMin;
bool FirstConnect, FirstDisConnect;
u8 dm_dig_max, dm_dig_min;
u8 CurrentIGI = pDM_DigTable->CurIGValue;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a() ==>\n"));
if ((!(pDM_Odm->SupportAbility&ODM_BB_DIG)) || (!(pDM_Odm->SupportAbility&ODM_BB_FA_CNT))) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG23a() Return: SupportAbility ODM_BB_DIG or ODM_BB_FA_CNT is disabled\n"));
return;
}
if (adapter->mlmepriv.bScanInProcess) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a() Return: In Scan Progress \n"));
return;
}
DIG_Dynamic_MIN = pDM_DigTable->DIG_Dynamic_MIN_0;
FirstConnect = (pDM_Odm->bLinked) && (!pDM_DigTable->bMediaConnect_0);
FirstDisConnect = (!pDM_Odm->bLinked) && (pDM_DigTable->bMediaConnect_0);
if ((pDM_Odm->SupportICType & ODM_RTL8723A) &&
((pDM_Odm->BoardType == ODM_BOARD_HIGHPWR) || pDM_Odm->ExtLNA)) {
dm_dig_max = DM_DIG_MAX_NIC_HP;
dm_dig_min = DM_DIG_MIN_NIC_HP;
DIG_MaxOfMin = DM_DIG_MAX_AP_HP;
} else {
dm_dig_max = DM_DIG_MAX_NIC;
dm_dig_min = DM_DIG_MIN_NIC;
DIG_MaxOfMin = DM_DIG_MAX_AP;
}
if (pDM_Odm->bLinked) {
if (pDM_Odm->SupportICType == ODM_RTL8723A) {
if ((pDM_Odm->RSSI_Min + 10) > DM_DIG_MAX_NIC)
pDM_DigTable->rx_gain_range_max = DM_DIG_MAX_NIC;
else if ((pDM_Odm->RSSI_Min + 10) < DM_DIG_MIN_NIC)
pDM_DigTable->rx_gain_range_max = DM_DIG_MIN_NIC;
else
pDM_DigTable->rx_gain_range_max = pDM_Odm->RSSI_Min + 10;
DIG_Dynamic_MIN = DM_DIG_MIN_NIC;
} else {
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
("odm_DIG23a() : bOneEntryOnly = true, DIG_Dynamic_MIN = 0x%x\n",
DIG_Dynamic_MIN));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG23a() : pDM_Odm->RSSI_Min =%d\n",
pDM_Odm->RSSI_Min));
} else {
DIG_Dynamic_MIN = dm_dig_min;
}
}
} else {
pDM_DigTable->rx_gain_range_max = dm_dig_max;
DIG_Dynamic_MIN = dm_dig_min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a() : No Link\n"));
}
if (pFalseAlmCnt->Cnt_all > 10000) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("dm_DIG(): Abnornally false alarm case. \n"));
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
if ((pDM_DigTable->ForbiddenIGI - 1) < DIG_Dynamic_MIN) {
pDM_DigTable->ForbiddenIGI = DIG_Dynamic_MIN;
pDM_DigTable->rx_gain_range_min = DIG_Dynamic_MIN;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG23a(): Normal Case: At Lower Bound\n"));
} else {
pDM_DigTable->ForbiddenIGI--;
pDM_DigTable->rx_gain_range_min = (pDM_DigTable->ForbiddenIGI + 1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD,
("odm_DIG23a(): Normal Case: Approach Lower Bound\n"));
}
} else {
pDM_DigTable->LargeFAHit = 0;
}
}
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): pDM_DigTable->LargeFAHit =%d\n", pDM_DigTable->LargeFAHit));
if (pDM_Odm->bLinked) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): DIG AfterLink\n"));
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
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): DIG BeforeLink\n"));
if (FirstDisConnect) {
CurrentIGI = pDM_DigTable->rx_gain_range_min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): First DisConnect \n"));
} else {
if (pFalseAlmCnt->Cnt_all > 10000)
CurrentIGI = CurrentIGI + 2;
else if (pFalseAlmCnt->Cnt_all > 8000)
CurrentIGI = CurrentIGI + 1;
else if (pFalseAlmCnt->Cnt_all < 500)
CurrentIGI = CurrentIGI - 1;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): England DIG \n"));
}
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): DIG End Adjust IGI\n"));
if (CurrentIGI > pDM_DigTable->rx_gain_range_max)
CurrentIGI = pDM_DigTable->rx_gain_range_max;
if (CurrentIGI < pDM_DigTable->rx_gain_range_min)
CurrentIGI = pDM_DigTable->rx_gain_range_min;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): rx_gain_range_max = 0x%x, rx_gain_range_min = 0x%x\n",
pDM_DigTable->rx_gain_range_max, pDM_DigTable->rx_gain_range_min));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): TotalFA =%d\n", pFalseAlmCnt->Cnt_all));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_DIG, ODM_DBG_LOUD, ("odm_DIG23a(): CurIGValue = 0x%x\n", CurrentIGI));
ODM_Write_DIG23a(pDM_Odm, CurrentIGI);
pDM_DigTable->bMediaConnect_0 = pDM_Odm->bLinked;
pDM_DigTable->DIG_Dynamic_MIN_0 = DIG_Dynamic_MIN;
}
void odm_FalseAlarmCounterStatistics23a(struct dm_odm_t *pDM_Odm)
{
u32 ret_value;
struct false_alarm_stats *FalseAlmCnt = &pDM_Odm->FalseAlmCnt;
if (!(pDM_Odm->SupportAbility & ODM_BB_FA_CNT))
return;
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_HOLDC_11N, BIT(31), 1);
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_RSTD_11N, BIT(31), 1);
ret_value =
ODM_GetBBReg(pDM_Odm, ODM_REG_OFDM_FA_TYPE1_11N, bMaskDWord);
FalseAlmCnt->Cnt_Fast_Fsync = (ret_value&0xffff);
FalseAlmCnt->Cnt_SB_Search_fail = ((ret_value&0xffff0000)>>16);
ret_value =
ODM_GetBBReg(pDM_Odm, ODM_REG_OFDM_FA_TYPE2_11N, bMaskDWord);
FalseAlmCnt->Cnt_OFDM_CCA = (ret_value&0xffff);
FalseAlmCnt->Cnt_Parity_Fail = ((ret_value&0xffff0000)>>16);
ret_value =
ODM_GetBBReg(pDM_Odm, ODM_REG_OFDM_FA_TYPE3_11N, bMaskDWord);
FalseAlmCnt->Cnt_Rate_Illegal = (ret_value&0xffff);
FalseAlmCnt->Cnt_Crc8_fail = ((ret_value&0xffff0000)>>16);
ret_value =
ODM_GetBBReg(pDM_Odm, ODM_REG_OFDM_FA_TYPE4_11N, bMaskDWord);
FalseAlmCnt->Cnt_Mcs_fail = (ret_value&0xffff);
FalseAlmCnt->Cnt_Ofdm_fail = FalseAlmCnt->Cnt_Parity_Fail +
FalseAlmCnt->Cnt_Rate_Illegal +
FalseAlmCnt->Cnt_Crc8_fail +
FalseAlmCnt->Cnt_Mcs_fail +
FalseAlmCnt->Cnt_Fast_Fsync +
FalseAlmCnt->Cnt_SB_Search_fail;
ODM_SetBBReg(pDM_Odm, ODM_REG_CCK_FA_RST_11N, BIT(12), 1);
ODM_SetBBReg(pDM_Odm, ODM_REG_CCK_FA_RST_11N, BIT(14), 1);
ret_value = ODM_GetBBReg(pDM_Odm, ODM_REG_CCK_FA_LSB_11N, bMaskByte0);
FalseAlmCnt->Cnt_Cck_fail = ret_value;
ret_value = ODM_GetBBReg(pDM_Odm, ODM_REG_CCK_FA_MSB_11N, bMaskByte3);
FalseAlmCnt->Cnt_Cck_fail += (ret_value & 0xff) << 8;
ret_value = ODM_GetBBReg(pDM_Odm, ODM_REG_CCK_CCA_CNT_11N, bMaskDWord);
FalseAlmCnt->Cnt_CCK_CCA =
((ret_value&0xFF)<<8) | ((ret_value&0xFF00)>>8);
FalseAlmCnt->Cnt_all = (FalseAlmCnt->Cnt_Fast_Fsync +
FalseAlmCnt->Cnt_SB_Search_fail +
FalseAlmCnt->Cnt_Parity_Fail +
FalseAlmCnt->Cnt_Rate_Illegal +
FalseAlmCnt->Cnt_Crc8_fail +
FalseAlmCnt->Cnt_Mcs_fail +
FalseAlmCnt->Cnt_Cck_fail);
FalseAlmCnt->Cnt_CCA_all =
FalseAlmCnt->Cnt_OFDM_CCA + FalseAlmCnt->Cnt_CCK_CCA;
if (pDM_Odm->SupportICType >= ODM_RTL8723A) {
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_RSTC_11N, BIT(31), 1);
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_RSTC_11N, BIT(31), 0);
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_RSTD_11N, BIT(27), 1);
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_RSTD_11N, BIT(27), 0);
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_HOLDC_11N, BIT(31), 0);
ODM_SetBBReg(pDM_Odm, ODM_REG_OFDM_FA_RSTD_11N, BIT(31), 0);
ODM_SetBBReg(pDM_Odm, ODM_REG_CCK_FA_RST_11N,
BIT(13) | BIT(12), 0);
ODM_SetBBReg(pDM_Odm, ODM_REG_CCK_FA_RST_11N,
BIT(13) | BIT(12), 2);
ODM_SetBBReg(pDM_Odm, ODM_REG_CCK_FA_RST_11N,
BIT(15) | BIT(14), 0);
ODM_SetBBReg(pDM_Odm, ODM_REG_CCK_FA_RST_11N,
BIT(15) | BIT(14), 2);
}
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD,
("Enter odm_FalseAlarmCounterStatistics23a\n"));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD,
("Cnt_Fast_Fsync =%d, Cnt_SB_Search_fail =%d\n",
FalseAlmCnt->Cnt_Fast_Fsync,
FalseAlmCnt->Cnt_SB_Search_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD,
("Cnt_Parity_Fail =%d, Cnt_Rate_Illegal =%d\n",
FalseAlmCnt->Cnt_Parity_Fail,
FalseAlmCnt->Cnt_Rate_Illegal));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD,
("Cnt_Crc8_fail =%d, Cnt_Mcs_fail =%d\n",
FalseAlmCnt->Cnt_Crc8_fail, FalseAlmCnt->Cnt_Mcs_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD, ("Cnt_Cck_fail =%d\n", FalseAlmCnt->Cnt_Cck_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD, ("Cnt_Ofdm_fail =%d\n", FalseAlmCnt->Cnt_Ofdm_fail));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_FA_CNT, ODM_DBG_LOUD, ("Total False Alarm =%d\n", FalseAlmCnt->Cnt_all));
}
void odm_CCKPacketDetectionThresh23a(struct dm_odm_t *pDM_Odm)
{
struct false_alarm_stats *FalseAlmCnt = &pDM_Odm->FalseAlmCnt;
u8 CurCCK_CCAThres;
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
ODM_Write_CCK_CCA_Thres23a(pDM_Odm, CurCCK_CCAThres);
}
void ODM_Write_CCK_CCA_Thres23a(struct dm_odm_t *pDM_Odm, u8 CurCCK_CCAThres)
{
struct dig_t *pDM_DigTable = &pDM_Odm->DM_DigTable;
if (pDM_DigTable->CurCCK_CCAThres != CurCCK_CCAThres)
ODM_Write1Byte(pDM_Odm, ODM_REG(CCK_CCA, pDM_Odm), CurCCK_CCAThres);
pDM_DigTable->PreCCK_CCAThres = pDM_DigTable->CurCCK_CCAThres;
pDM_DigTable->CurCCK_CCAThres = CurCCK_CCAThres;
}
void odm23a_DynBBPSInit(struct dm_odm_t *pDM_Odm)
{
struct dynamic_pwr_sav *pDM_PSTable = &pDM_Odm->DM_PSTable;
pDM_PSTable->PreCCAState = CCA_MAX;
pDM_PSTable->CurCCAState = CCA_MAX;
pDM_PSTable->PreRFState = RF_MAX;
pDM_PSTable->CurRFState = RF_MAX;
pDM_PSTable->Rssi_val_min = 0;
pDM_PSTable->initialize = 0;
}
void odm_DynamicBBPowerSaving23a(struct dm_odm_t *pDM_Odm)
{
return;
}
void ODM_RF_Saving23a(struct dm_odm_t *pDM_Odm, u8 bForceInNormal)
{
struct dynamic_pwr_sav *pDM_PSTable = &pDM_Odm->DM_PSTable;
u8 Rssi_Up_bound = 30;
u8 Rssi_Low_bound = 25;
if (pDM_Odm->PatchID == 40) {
Rssi_Up_bound = 50;
Rssi_Low_bound = 45;
}
if (pDM_PSTable->initialize == 0) {
pDM_PSTable->Reg874 = (ODM_GetBBReg(pDM_Odm, 0x874, bMaskDWord)&0x1CC000)>>14;
pDM_PSTable->RegC70 =
(ODM_GetBBReg(pDM_Odm, 0xc70, bMaskDWord) & BIT(3)) >>3;
pDM_PSTable->Reg85C = (ODM_GetBBReg(pDM_Odm, 0x85c, bMaskDWord)&0xFF000000)>>24;
pDM_PSTable->RegA74 = (ODM_GetBBReg(pDM_Odm, 0xa74, bMaskDWord)&0xF000)>>12;
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
if (pDM_Odm->SupportICType == ODM_RTL8723A)
ODM_SetBBReg(pDM_Odm, 0x874, BIT(5), 0x1);
ODM_SetBBReg(pDM_Odm, 0x874, 0x1C0000, 0x2);
ODM_SetBBReg(pDM_Odm, 0xc70, BIT(3), 0);
ODM_SetBBReg(pDM_Odm, 0x85c, 0xFF000000, 0x63);
ODM_SetBBReg(pDM_Odm, 0x874, 0xC000, 0x2);
ODM_SetBBReg(pDM_Odm, 0xa74, 0xF000, 0x3);
ODM_SetBBReg(pDM_Odm, 0x818, BIT(28), 0x0);
ODM_SetBBReg(pDM_Odm, 0x818, BIT(28), 0x1);
} else {
ODM_SetBBReg(pDM_Odm, 0x874, 0x1CC000, pDM_PSTable->Reg874);
ODM_SetBBReg(pDM_Odm, 0xc70, BIT(3), pDM_PSTable->RegC70);
ODM_SetBBReg(pDM_Odm, 0x85c, 0xFF000000, pDM_PSTable->Reg85C);
ODM_SetBBReg(pDM_Odm, 0xa74, 0xF000, pDM_PSTable->RegA74);
ODM_SetBBReg(pDM_Odm, 0x818, BIT(28), 0x0);
if (pDM_Odm->SupportICType == ODM_RTL8723A)
ODM_SetBBReg(pDM_Odm, 0x874, BIT(5), 0x0);
}
pDM_PSTable->PreRFState = pDM_PSTable->CurRFState;
}
}
void odm_RateAdaptiveMaskInit23a(struct dm_odm_t *pDM_Odm)
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
u32 ODM_Get_Rate_Bitmap23a(struct hal_data_8723a *pHalData, u32 macid,
u32 ra_mask, u8 rssi_level)
{
struct dm_odm_t *pDM_Odm = &pHalData->odmpriv;
struct sta_info *pEntry;
u32 rate_bitmap = 0x0fffffff;
u8 WirelessMode;
pEntry = pDM_Odm->pODM_StaInfo[macid];
if (!pEntry)
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
if (pHalData->CurrentChannelBW ==
HT_CHANNEL_WIDTH_40)
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
if (pHalData->CurrentChannelBW ==
HT_CHANNEL_WIDTH_40)
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
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD, (" ==> rssi_level:0x%02x, WirelessMode:0x%02x, rate_bitmap:0x%08x \n", rssi_level, WirelessMode, rate_bitmap));
return rate_bitmap;
}
void odm_RefreshRateAdaptiveMask23a(struct dm_odm_t *pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_RA_MASK))
return;
odm_RefreshRateAdaptiveMask23aCE23a(pDM_Odm);
}
void odm_RefreshRateAdaptiveMask23aCE23a(struct dm_odm_t *pDM_Odm)
{
u8 i;
struct rtw_adapter *pAdapter = pDM_Odm->Adapter;
if (pAdapter->bDriverStopped) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_TRACE,
("<---- odm_RefreshRateAdaptiveMask23a(): driver is going to unload\n"));
return;
}
if (!pDM_Odm->bUseRAMask) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD,
("<---- odm_RefreshRateAdaptiveMask23a(): driver does not control rate adaptive mask\n"));
return;
}
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
struct sta_info *pstat = pDM_Odm->pODM_StaInfo[i];
if (pstat) {
if (ODM_RAStateCheck23a(pDM_Odm, pstat->rssi_stat.UndecoratedSmoothedPWDB, false, &pstat->rssi_level)) {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD,
("RSSI:%d, RSSI_LEVEL:%d\n",
pstat->rssi_stat.UndecoratedSmoothedPWDB,
pstat->rssi_level));
rtw_hal_update_ra_mask23a(pstat, pstat->rssi_level);
}
}
}
}
bool ODM_RAStateCheck23a(struct dm_odm_t *pDM_Odm, s32 RSSI, bool bForceUpdate,
u8 *pRATRState)
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
ODM_RT_TRACE(pDM_Odm, ODM_COMP_RA_MASK, ODM_DBG_LOUD,
("RSSI Level %d -> %d\n", *pRATRState, RATRState));
*pRATRState = RATRState;
return true;
}
return false;
}
void odm_DynamicTxPower23aInit(struct dm_odm_t *pDM_Odm)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
pdmpriv->DynamicTxHighPowerLvl = TxHighPwrLevel_Normal;
}
void odm_RSSIMonitorCheck23a(struct dm_odm_t *pDM_Odm)
{
if (!(pDM_Odm->SupportAbility & ODM_BB_RSSI_MONITOR))
return;
odm_RSSIMonitorCheck23aCE(pDM_Odm);
}
static void
FindMinimumRSSI(
struct rtw_adapter *pAdapter
)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(pAdapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
struct dm_odm_t *pDM_Odm = &pHalData->odmpriv;
if ((!pDM_Odm->bLinked) &&
(pdmpriv->EntryMinUndecoratedSmoothedPWDB == 0))
pdmpriv->MinUndecoratedPWDBForDM = 0;
else
pdmpriv->MinUndecoratedPWDBForDM = pdmpriv->EntryMinUndecoratedSmoothedPWDB;
}
void odm_RSSIMonitorCheck23aCE(struct dm_odm_t *pDM_Odm)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
int i;
int tmpEntryMaxPWDB = 0, tmpEntryMinPWDB = 0xff;
u8 sta_cnt = 0;
u32 PWDB_rssi[NUM_STA] = {0};
struct sta_info *psta;
if (!pDM_Odm->bLinked)
return;
for (i = 0; i < ODM_ASSOCIATE_ENTRY_NUM; i++) {
psta = pDM_Odm->pODM_StaInfo[i];
if (psta) {
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
if (pHalData->fw_ractrl)
rtl8723a_set_rssi_cmd(Adapter, (u8 *)&PWDB_rssi[i]);
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
ODM_CmnInfoUpdate23a(&pHalData->odmpriv, ODM_CMNINFO_RSSI_MIN, pdmpriv->MinUndecoratedPWDBForDM);
}
void odm_TXPowerTrackingInit23a(struct dm_odm_t *pDM_Odm)
{
odm_TXPowerTrackingThermalMeterInit23a(pDM_Odm);
}
void odm_TXPowerTrackingThermalMeterInit23a(struct dm_odm_t *pDM_Odm)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct dm_priv *pdmpriv = &pHalData->dmpriv;
pdmpriv->bTXPowerTracking = true;
pdmpriv->TXPowercount = 0;
pdmpriv->bTXPowerTrackingInit = false;
pdmpriv->TxPowerTrackControl = true;
MSG_8723A("pdmpriv->TxPowerTrackControl = %d\n", pdmpriv->TxPowerTrackControl);
pDM_Odm->RFCalibrateInfo.TxPowerTrackControl = true;
}
void ODM_TXPowerTrackingCheck23a(struct dm_odm_t *pDM_Odm)
{
odm_TXPowerTrackingCheckCE23a(pDM_Odm);
}
void odm_TXPowerTrackingCheckCE23a(struct dm_odm_t *pDM_Odm)
{
}
static void ODM_EdcaTurboInit23a(struct dm_odm_t *pDM_Odm)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = false;
pDM_Odm->DM_EDCA_Table.bIsCurRDLState = false;
Adapter->recvpriv.bIsAnyNonBEPkts = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial VO PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_VO_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial VI PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_VI_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial BE PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_BE_PARAM)));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial BK PARAM: 0x%x\n", ODM_Read4Byte(pDM_Odm, ODM_EDCA_BK_PARAM)));
}
static void odm_EdcaTurboCheck23a(struct dm_odm_t *pDM_Odm)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
struct hal_data_8723a *pHalData = GET_HAL_DATA(Adapter);
struct xmit_priv *pxmitpriv = &Adapter->xmitpriv;
struct recv_priv *precvpriv = &Adapter->recvpriv;
struct registry_priv *pregpriv = &Adapter->registrypriv;
struct mlme_ext_priv *pmlmeext = &Adapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
u32 trafficIndex;
u32 edca_param;
u64 cur_tx_bytes = 0;
u64 cur_rx_bytes = 0;
u8 bbtchange = false;
if (!(pDM_Odm->SupportAbility & ODM_MAC_EDCA_TURBO))
return;
if ((pregpriv->wifi_spec == 1))
goto dm_CheckEdcaTurbo_EXIT;
if (pmlmeinfo->assoc_AP_vendor >= HT_IOT_PEER_MAX)
goto dm_CheckEdcaTurbo_EXIT;
if (rtl8723a_BT_disable_EDCA_turbo(Adapter))
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
if ((pDM_Odm->DM_EDCA_Table.prv_traffic_idx != trafficIndex) ||
(!pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA)) {
if ((pmlmeinfo->assoc_AP_vendor == HT_IOT_PEER_CISCO) &&
(pmlmeext->cur_wireless_mode & WIRELESS_11_24N))
edca_param = EDCAParam[pmlmeinfo->assoc_AP_vendor][trafficIndex];
else
edca_param = EDCAParam[HT_IOT_PEER_UNKNOWN][trafficIndex];
rtl8723au_write32(Adapter, REG_EDCA_BE_PARAM,
edca_param);
pDM_Odm->DM_EDCA_Table.prv_traffic_idx = trafficIndex;
}
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = true;
} else {
if (pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA) {
rtl8723au_write32(Adapter, REG_EDCA_BE_PARAM,
pHalData->AcParam_BE);
pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = false;
}
}
dm_CheckEdcaTurbo_EXIT:
precvpriv->bIsAnyNonBEPkts = false;
pxmitpriv->last_tx_bytes = pxmitpriv->tx_bytes;
precvpriv->last_rx_bytes = precvpriv->rx_bytes;
}
u32 GetPSDData(struct dm_odm_t *pDM_Odm, unsigned int point, u8 initial_gain_psd)
{
u32 psd_report;
ODM_SetBBReg(pDM_Odm, 0x808, 0x3FF, point);
ODM_SetBBReg(pDM_Odm, 0x808, BIT(22), 1);
udelay(30);
ODM_SetBBReg(pDM_Odm, 0x808, BIT(22), 0);
psd_report = ODM_GetBBReg(pDM_Odm, 0x8B4, bMaskDWord) & 0x0000FFFF;
psd_report = (u32)(ConvertTo_dB23a(psd_report))+(u32)(initial_gain_psd-0x1c);
return psd_report;
}
u32
ConvertTo_dB23a(
u32 Value)
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
void ODM_SingleDualAntennaDefaultSetting(struct dm_odm_t *pDM_Odm)
{
struct sw_ant_sw *pDM_SWAT_Table = &pDM_Odm->DM_SWAT_Table;
pDM_SWAT_Table->ANTA_ON = true;
pDM_SWAT_Table->ANTB_ON = true;
}
static void odm_PHY_SaveAFERegisters(
struct dm_odm_t *pDM_Odm,
u32 *AFEReg,
u32 *AFEBackup,
u32 RegisterNum
)
{
u32 i;
for (i = 0 ; i < RegisterNum ; i++)
AFEBackup[i] = ODM_GetBBReg(pDM_Odm, AFEReg[i], bMaskDWord);
}
static void odm_PHY_ReloadAFERegisters(struct dm_odm_t *pDM_Odm, u32 *AFEReg,
u32 *AFEBackup, u32 RegiesterNum)
{
u32 i;
for (i = 0 ; i < RegiesterNum; i++)
ODM_SetBBReg(pDM_Odm, AFEReg[i], bMaskDWord, AFEBackup[i]);
}
bool ODM_SingleDualAntennaDetection(struct dm_odm_t *pDM_Odm, u8 mode)
{
struct sw_ant_sw *pDM_SWAT_Table = &pDM_Odm->DM_SWAT_Table;
u32 CurrentChannel, RfLoopReg;
u8 n;
u32 Reg88c, Regc08, Reg874, Regc50;
u8 initial_gain = 0x5a;
u32 PSD_report_tmp;
u32 AntA_report = 0x0, AntB_report = 0x0, AntO_report = 0x0;
bool bResult = true;
u32 AFE_Backup[16];
u32 AFE_REG_8723A[16] = {
rRx_Wait_CCA, rTx_CCK_RFON,
rTx_CCK_BBON, rTx_OFDM_RFON,
rTx_OFDM_BBON, rTx_To_Rx,
rTx_To_Tx, rRx_CCK,
rRx_OFDM, rRx_Wait_RIFS,
rRx_TO_Rx, rStandby,
rSleep, rPMPD_ANAEN,
rFPGA0_XCD_SwitchControl, rBlue_Tooth};
if (!(pDM_Odm->SupportICType & ODM_RTL8723A))
return bResult;
if (!(pDM_Odm->SupportAbility&ODM_BB_ANT_DIV))
return bResult;
CurrentChannel = ODM_GetRFReg(pDM_Odm, RF_PATH_A, ODM_CHANNEL, bRFRegOffsetMask);
RfLoopReg = ODM_GetRFReg(pDM_Odm, RF_PATH_A, 0x00, bRFRegOffsetMask);
ODM_SetBBReg(pDM_Odm, rFPGA0_XA_RFInterfaceOE, ODM_DPDT, Antenna_A);
udelay(10);
Reg88c = ODM_GetBBReg(pDM_Odm, rFPGA0_AnalogParameter4, bMaskDWord);
Regc08 = ODM_GetBBReg(pDM_Odm, rOFDM0_TRMuxPar, bMaskDWord);
Reg874 = ODM_GetBBReg(pDM_Odm, rFPGA0_XCD_RFInterfaceSW, bMaskDWord);
Regc50 = ODM_GetBBReg(pDM_Odm, rOFDM0_XAAGCCore1, bMaskDWord);
odm_PHY_SaveAFERegisters(pDM_Odm, AFE_REG_8723A, AFE_Backup, 16);
ODM_SetBBReg(pDM_Odm, rFPGA0_PSDFunction, BIT(14) | BIT(15), 0x0);
ODM_SetRFReg(pDM_Odm, RF_PATH_A, ODM_CHANNEL, bRFRegOffsetMask, 0x01);
ODM_SetBBReg(pDM_Odm, rRx_Wait_CCA, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rTx_CCK_RFON, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rTx_CCK_BBON, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rTx_OFDM_RFON, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rTx_OFDM_BBON, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rTx_To_Rx, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rTx_To_Tx, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rRx_CCK, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rRx_OFDM, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rRx_Wait_RIFS, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rRx_TO_Rx, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rStandby, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rSleep, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rPMPD_ANAEN, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rFPGA0_XCD_SwitchControl, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rBlue_Tooth, bMaskDWord, 0x6FDB25A4);
ODM_SetBBReg(pDM_Odm, rFPGA0_AnalogParameter4, bMaskDWord, 0xCCF000C0);
ODM_SetBBReg(pDM_Odm, rOFDM0_TRMuxPar, bMaskDWord, 0x000800E4);
ODM_SetBBReg(pDM_Odm, rFPGA0_XCD_RFInterfaceSW, bMaskDWord, 0x22208000);
ODM_SetBBReg(pDM_Odm, rTx_IQK_Tone_A, bMaskDWord, 0x10008C1C);
ODM_SetBBReg(pDM_Odm, rTx_IQK, bMaskDWord, 0x01007c00);
ODM_SetBBReg(pDM_Odm, rConfig_AntA, bMaskDWord, 0x00080000);
ODM_SetBBReg(pDM_Odm, rConfig_AntA, bMaskDWord, 0x0f600000);
ODM_SetBBReg(pDM_Odm, rRx_IQK, bMaskDWord, 0x01004800);
ODM_SetBBReg(pDM_Odm, rRx_IQK_Tone_A, bMaskDWord, 0x10008c1f);
ODM_SetBBReg(pDM_Odm, rTx_IQK_PI_A, bMaskDWord, 0x82150008);
ODM_SetBBReg(pDM_Odm, rRx_IQK_PI_A, bMaskDWord, 0x28150008);
ODM_SetBBReg(pDM_Odm, rIQK_AGC_Rsp, bMaskDWord, 0x001028d0);
ODM_SetRFReg(pDM_Odm, RF_PATH_A, 0x0, 0xFFFFF, 0x50008);
ODM_SetBBReg(pDM_Odm, rFPGA0_IQK, bMaskDWord, 0x80800000);
ODM_SetBBReg(pDM_Odm, rIQK_AGC_Pts, bMaskDWord, 0xf8000000);
udelay(1000);
PSD_report_tmp = 0x0;
for (n = 0; n < 2; n++) {
PSD_report_tmp = GetPSDData(pDM_Odm, 14, initial_gain);
if (PSD_report_tmp > AntA_report)
AntA_report = PSD_report_tmp;
}
PSD_report_tmp = 0x0;
ODM_SetBBReg(pDM_Odm, rFPGA0_XA_RFInterfaceOE, 0x300, Antenna_B);
udelay(10);
for (n = 0; n < 2; n++) {
PSD_report_tmp = GetPSDData(pDM_Odm, 14, initial_gain);
if (PSD_report_tmp > AntB_report)
AntB_report = PSD_report_tmp;
}
ODM_SetBBReg(pDM_Odm, rFPGA0_XA_RFInterfaceOE, 0x300, 0);
udelay(10);
for (n = 0; n < 2; n++) {
PSD_report_tmp = GetPSDData(pDM_Odm, 14, initial_gain);
if (PSD_report_tmp > AntO_report)
AntO_report = PSD_report_tmp;
}
ODM_SetBBReg(pDM_Odm, rFPGA0_IQK, bMaskDWord, 0x00000000);
PSD_report_tmp = 0x0;
ODM_SetBBReg(pDM_Odm, rFPGA0_XA_RFInterfaceOE, 0x300, Antenna_A);
ODM_SetBBReg(pDM_Odm, rFPGA0_AnalogParameter4, bMaskDWord, Reg88c);
ODM_SetBBReg(pDM_Odm, rOFDM0_TRMuxPar, bMaskDWord, Regc08);
ODM_SetBBReg(pDM_Odm, rFPGA0_XCD_RFInterfaceSW, bMaskDWord, Reg874);
ODM_SetBBReg(pDM_Odm, rOFDM0_XAAGCCore1, 0x7F, 0x40);
ODM_SetBBReg(pDM_Odm, rOFDM0_XAAGCCore1, bMaskDWord, Regc50);
ODM_SetRFReg(pDM_Odm, RF_PATH_A, RF_CHNLBW, bRFRegOffsetMask, CurrentChannel);
ODM_SetRFReg(pDM_Odm, RF_PATH_A, 0x00, bRFRegOffsetMask, RfLoopReg);
odm_PHY_ReloadAFERegisters(pDM_Odm, AFE_REG_8723A, AFE_Backup, 16);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("psd_report_A[%d]= %d \n", 2416, AntA_report));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("psd_report_B[%d]= %d \n", 2416, AntB_report));
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("psd_report_O[%d]= %d \n", 2416, AntO_report));
if (mode == ANTTESTB) {
if (AntA_report >= 100) {
if (AntB_report > (AntA_report+1)) {
pDM_SWAT_Table->ANTB_ON = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("ODM_SingleDualAntennaDetection(): Single Antenna A\n"));
} else {
pDM_SWAT_Table->ANTB_ON = true;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("ODM_SingleDualAntennaDetection(): Dual Antenna is A and B\n"));
}
} else {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("ODM_SingleDualAntennaDetection(): Need to check again\n"));
pDM_SWAT_Table->ANTB_ON = false;
bResult = false;
}
} else if (mode == ANTTESTALL) {
if ((AntO_report >= 100) & (AntO_report < 118)) {
if (AntA_report > (AntO_report+1)) {
pDM_SWAT_Table->ANTA_ON = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Ant A is OFF"));
} else {
pDM_SWAT_Table->ANTA_ON = true;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Ant A is ON"));
}
if (AntB_report > (AntO_report+2)) {
pDM_SWAT_Table->ANTB_ON = false;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Ant B is OFF"));
} else {
pDM_SWAT_Table->ANTB_ON = true;
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("Ant B is ON"));
}
}
} else {
ODM_RT_TRACE(pDM_Odm, ODM_COMP_ANT_DIV, ODM_DBG_LOUD, ("ODM_SingleDualAntennaDetection(): Need to check again\n"));
pDM_SWAT_Table->ANTA_ON = true;
pDM_SWAT_Table->ANTB_ON = false;
bResult = false;
}
return bResult;
}
void odm_dtc(struct dm_odm_t *pDM_Odm)
{
}
