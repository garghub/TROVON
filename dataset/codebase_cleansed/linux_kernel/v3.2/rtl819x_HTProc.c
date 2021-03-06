void HTUpdateDefaultSetting(struct rtllib_device *ieee)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
pHTInfo->bAcceptAddbaReq = 1;
pHTInfo->bRegShortGI20MHz = 1;
pHTInfo->bRegShortGI40MHz = 1;
pHTInfo->bRegBW40MHz = 1;
if (pHTInfo->bRegBW40MHz)
pHTInfo->bRegSuppCCK = 1;
else
pHTInfo->bRegSuppCCK = true;
pHTInfo->nAMSDU_MaxSize = 7935UL;
pHTInfo->bAMSDU_Support = 0;
pHTInfo->bAMPDUEnable = 1;
pHTInfo->AMPDU_Factor = 2;
pHTInfo->MPDU_Density = 0;
pHTInfo->SelfMimoPs = 3;
if (pHTInfo->SelfMimoPs == 2)
pHTInfo->SelfMimoPs = 3;
ieee->bTxDisableRateFallBack = 0;
ieee->bTxUseDriverAssingedRate = 0;
ieee->bTxEnableFwCalcDur = 1;
pHTInfo->bRegRT2RTAggregation = 1;
pHTInfo->bRegRxReorderEnable = 1;
pHTInfo->RxReorderWinSize = 64;
pHTInfo->RxReorderPendingTime = 30;
}
void HTDebugHTCapability(u8 *CapIE, u8 *TitleString)
{
static u8 EWC11NHTCap[] = {0x00, 0x90, 0x4c, 0x33};
struct ht_capab_ele *pCapELE;
if (!memcmp(CapIE, EWC11NHTCap, sizeof(EWC11NHTCap))) {
RTLLIB_DEBUG(RTLLIB_DL_HT, "EWC IE in %s()\n", __func__);
pCapELE = (struct ht_capab_ele *)(&CapIE[4]);
} else
pCapELE = (struct ht_capab_ele *)(&CapIE[0]);
RTLLIB_DEBUG(RTLLIB_DL_HT, "<Log HT Capability>. Called by %s\n",
TitleString);
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tSupported Channel Width = %s\n",
(pCapELE->ChlWidth) ? "20MHz" : "20/40MHz");
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tSupport Short GI for 20M = %s\n",
(pCapELE->ShortGI20Mhz) ? "YES" : "NO");
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tSupport Short GI for 40M = %s\n",
(pCapELE->ShortGI40Mhz) ? "YES" : "NO");
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tSupport TX STBC = %s\n",
(pCapELE->TxSTBC) ? "YES" : "NO");
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tMax AMSDU Size = %s\n",
(pCapELE->MaxAMSDUSize) ? "3839" : "7935");
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tSupport CCK in 20/40 mode = %s\n",
(pCapELE->DssCCk) ? "YES" : "NO");
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tMax AMPDU Factor = %d\n",
pCapELE->MaxRxAMPDUFactor);
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tMPDU Density = %d\n",
pCapELE->MPDUDensity);
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tMCS Rate Set = [%x][%x][%x][%x][%x]\n",
pCapELE->MCS[0], pCapELE->MCS[1], pCapELE->MCS[2],
pCapELE->MCS[3], pCapELE->MCS[4]);
return;
}
void HTDebugHTInfo(u8 *InfoIE, u8 *TitleString)
{
static u8 EWC11NHTInfo[] = {0x00, 0x90, 0x4c, 0x34};
struct ht_info_ele *pHTInfoEle;
if (!memcmp(InfoIE, EWC11NHTInfo, sizeof(EWC11NHTInfo))) {
RTLLIB_DEBUG(RTLLIB_DL_HT, "EWC IE in %s()\n", __func__);
pHTInfoEle = (struct ht_info_ele *)(&InfoIE[4]);
} else
pHTInfoEle = (struct ht_info_ele *)(&InfoIE[0]);
RTLLIB_DEBUG(RTLLIB_DL_HT, "<Log HT Information Element>. "
"Called by %s\n", TitleString);
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tPrimary channel = %d\n",
pHTInfoEle->ControlChl);
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tSenondary channel =");
switch (pHTInfoEle->ExtChlOffset) {
case 0:
RTLLIB_DEBUG(RTLLIB_DL_HT, "Not Present\n");
break;
case 1:
RTLLIB_DEBUG(RTLLIB_DL_HT, "Upper channel\n");
break;
case 2:
RTLLIB_DEBUG(RTLLIB_DL_HT, "Reserved. Eooro!!!\n");
break;
case 3:
RTLLIB_DEBUG(RTLLIB_DL_HT, "Lower Channel\n");
break;
}
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tRecommended channel width = %s\n",
(pHTInfoEle->RecommemdedTxWidth) ? "20Mhz" : "40Mhz");
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tOperation mode for protection = ");
switch (pHTInfoEle->OptMode) {
case 0:
RTLLIB_DEBUG(RTLLIB_DL_HT, "No Protection\n");
break;
case 1:
RTLLIB_DEBUG(RTLLIB_DL_HT, "HT non-member protection mode\n");
break;
case 2:
RTLLIB_DEBUG(RTLLIB_DL_HT, "Suggest to open protection\n");
break;
case 3:
RTLLIB_DEBUG(RTLLIB_DL_HT, "HT mixed mode\n");
break;
}
RTLLIB_DEBUG(RTLLIB_DL_HT, "\tBasic MCS Rate Set = [%x][%x][%x][%x]"
"[%x]\n", pHTInfoEle->BasicMSC[0], pHTInfoEle->BasicMSC[1],
pHTInfoEle->BasicMSC[2], pHTInfoEle->BasicMSC[3],
pHTInfoEle->BasicMSC[4]);
return;
}
static bool IsHTHalfNmode40Bandwidth(struct rtllib_device *ieee)
{
bool retValue = false;
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
if (pHTInfo->bCurrentHTSupport == false)
retValue = false;
else if (pHTInfo->bRegBW40MHz == false)
retValue = false;
else if (!ieee->GetHalfNmodeSupportByAPsHandler(ieee->dev))
retValue = false;
else if (((struct ht_capab_ele *)(pHTInfo->PeerHTCapBuf))->ChlWidth)
retValue = true;
else
retValue = false;
return retValue;
}
static bool IsHTHalfNmodeSGI(struct rtllib_device *ieee, bool is40MHz)
{
bool retValue = false;
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
if (pHTInfo->bCurrentHTSupport == false)
retValue = false;
else if (!ieee->GetHalfNmodeSupportByAPsHandler(ieee->dev))
retValue = false;
else if (is40MHz) {
if (((struct ht_capab_ele *)
(pHTInfo->PeerHTCapBuf))->ShortGI40Mhz)
retValue = true;
else
retValue = false;
} else {
if (((struct ht_capab_ele *)
(pHTInfo->PeerHTCapBuf))->ShortGI20Mhz)
retValue = true;
else
retValue = false;
}
return retValue;
}
u16 HTHalfMcsToDataRate(struct rtllib_device *ieee, u8 nMcsRate)
{
u8 is40MHz;
u8 isShortGI;
is40MHz = (IsHTHalfNmode40Bandwidth(ieee)) ? 1 : 0;
isShortGI = (IsHTHalfNmodeSGI(ieee, is40MHz)) ? 1 : 0;
return MCS_DATA_RATE[is40MHz][isShortGI][(nMcsRate & 0x7f)];
}
u16 HTMcsToDataRate(struct rtllib_device *ieee, u8 nMcsRate)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
u8 is40MHz = (pHTInfo->bCurBW40MHz) ? 1 : 0;
u8 isShortGI = (pHTInfo->bCurBW40MHz) ?
((pHTInfo->bCurShortGI40MHz) ? 1 : 0) :
((pHTInfo->bCurShortGI20MHz) ? 1 : 0);
return MCS_DATA_RATE[is40MHz][isShortGI][(nMcsRate & 0x7f)];
}
u16 TxCountToDataRate(struct rtllib_device *ieee, u8 nDataRate)
{
u16 CCKOFDMRate[12] = {0x02, 0x04, 0x0b, 0x16, 0x0c, 0x12, 0x18,
0x24, 0x30, 0x48, 0x60, 0x6c};
u8 is40MHz = 0;
u8 isShortGI = 0;
if (nDataRate < 12) {
return CCKOFDMRate[nDataRate];
} else {
if (nDataRate >= 0x10 && nDataRate <= 0x1f) {
is40MHz = 0;
isShortGI = 0;
} else if (nDataRate >= 0x20 && nDataRate <= 0x2f) {
is40MHz = 1;
isShortGI = 0;
} else if (nDataRate >= 0x30 && nDataRate <= 0x3f) {
is40MHz = 0;
isShortGI = 1;
} else if (nDataRate >= 0x40 && nDataRate <= 0x4f) {
is40MHz = 1;
isShortGI = 1;
}
return MCS_DATA_RATE[is40MHz][isShortGI][nDataRate&0xf];
}
}
bool IsHTHalfNmodeAPs(struct rtllib_device *ieee)
{
bool retValue = false;
struct rtllib_network *net = &ieee->current_network;
if ((memcmp(net->bssid, BELKINF5D8233V1_RALINK, 3) == 0) ||
(memcmp(net->bssid, BELKINF5D82334V3_RALINK, 3) == 0) ||
(memcmp(net->bssid, PCI_RALINK, 3) == 0) ||
(memcmp(net->bssid, EDIMAX_RALINK, 3) == 0) ||
(memcmp(net->bssid, AIRLINK_RALINK, 3) == 0) ||
(net->ralink_cap_exist))
retValue = true;
else if (!memcmp(net->bssid, UNKNOWN_BORADCOM, 3) ||
!memcmp(net->bssid, LINKSYSWRT330_LINKSYSWRT300_BROADCOM, 3) ||
!memcmp(net->bssid, LINKSYSWRT350_LINKSYSWRT150_BROADCOM, 3) ||
(net->broadcom_cap_exist))
retValue = true;
else if (net->bssht.bdRT2RTAggregation)
retValue = true;
else
retValue = false;
return retValue;
}
static void HTIOTPeerDetermine(struct rtllib_device *ieee)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
struct rtllib_network *net = &ieee->current_network;
if (net->bssht.bdRT2RTAggregation) {
pHTInfo->IOTPeer = HT_IOT_PEER_REALTEK;
if (net->bssht.RT2RT_HT_Mode & RT_HT_CAP_USE_92SE)
pHTInfo->IOTPeer = HT_IOT_PEER_REALTEK_92SE;
if (net->bssht.RT2RT_HT_Mode & RT_HT_CAP_USE_SOFTAP)
pHTInfo->IOTPeer = HT_IOT_PEER_92U_SOFTAP;
} else if (net->broadcom_cap_exist)
pHTInfo->IOTPeer = HT_IOT_PEER_BROADCOM;
else if (!memcmp(net->bssid, UNKNOWN_BORADCOM, 3) ||
!memcmp(net->bssid, LINKSYSWRT330_LINKSYSWRT300_BROADCOM, 3) ||
!memcmp(net->bssid, LINKSYSWRT350_LINKSYSWRT150_BROADCOM, 3))
pHTInfo->IOTPeer = HT_IOT_PEER_BROADCOM;
else if ((memcmp(net->bssid, BELKINF5D8233V1_RALINK, 3) == 0) ||
(memcmp(net->bssid, BELKINF5D82334V3_RALINK, 3) == 0) ||
(memcmp(net->bssid, PCI_RALINK, 3) == 0) ||
(memcmp(net->bssid, EDIMAX_RALINK, 3) == 0) ||
(memcmp(net->bssid, AIRLINK_RALINK, 3) == 0) ||
net->ralink_cap_exist)
pHTInfo->IOTPeer = HT_IOT_PEER_RALINK;
else if ((net->atheros_cap_exist) ||
(memcmp(net->bssid, DLINK_ATHEROS_1, 3) == 0) ||
(memcmp(net->bssid, DLINK_ATHEROS_2, 3) == 0))
pHTInfo->IOTPeer = HT_IOT_PEER_ATHEROS;
else if ((memcmp(net->bssid, CISCO_BROADCOM, 3) == 0) ||
net->cisco_cap_exist)
pHTInfo->IOTPeer = HT_IOT_PEER_CISCO;
else if ((memcmp(net->bssid, LINKSYS_MARVELL_4400N, 3) == 0) ||
net->marvell_cap_exist)
pHTInfo->IOTPeer = HT_IOT_PEER_MARVELL;
else if (net->airgo_cap_exist)
pHTInfo->IOTPeer = HT_IOT_PEER_AIRGO;
else
pHTInfo->IOTPeer = HT_IOT_PEER_UNKNOWN;
RTLLIB_DEBUG(RTLLIB_DL_IOT, "Joseph debug!! IOTPEER: %x\n",
pHTInfo->IOTPeer);
}
static u8 HTIOTActIsDisableMCS14(struct rtllib_device *ieee, u8 *PeerMacAddr)
{
return 0;
}
static bool HTIOTActIsDisableMCS15(struct rtllib_device *ieee)
{
bool retValue = false;
return retValue;
}
static bool HTIOTActIsDisableMCSTwoSpatialStream(struct rtllib_device *ieee)
{
return false;
}
static u8 HTIOTActIsDisableEDCATurbo(struct rtllib_device *ieee, u8 *PeerMacAddr)
{
return false;
}
static u8 HTIOTActIsMgntUseCCK6M(struct rtllib_device *ieee,
struct rtllib_network *network)
{
u8 retValue = 0;
if (ieee->pHTInfo->IOTPeer == HT_IOT_PEER_BROADCOM)
retValue = 1;
return retValue;
}
static u8 HTIOTActIsCCDFsync(struct rtllib_device *ieee)
{
u8 retValue = 0;
if (ieee->pHTInfo->IOTPeer == HT_IOT_PEER_BROADCOM)
retValue = 1;
return retValue;
}
static void HTIOTActDetermineRaFunc(struct rtllib_device *ieee, bool bPeerRx2ss)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
pHTInfo->IOTRaFunc &= HT_IOT_RAFUNC_DISABLE_ALL;
if (pHTInfo->IOTPeer == HT_IOT_PEER_RALINK && !bPeerRx2ss)
pHTInfo->IOTRaFunc |= HT_IOT_RAFUNC_PEER_1R;
if (pHTInfo->IOTAction & HT_IOT_ACT_AMSDU_ENABLE)
pHTInfo->IOTRaFunc |= HT_IOT_RAFUNC_TX_AMSDU;
}
void HTResetIOTSetting(struct rt_hi_throughput *pHTInfo)
{
pHTInfo->IOTAction = 0;
pHTInfo->IOTPeer = HT_IOT_PEER_UNKNOWN;
pHTInfo->IOTRaFunc = 0;
}
void HTConstructCapabilityElement(struct rtllib_device *ieee, u8 *posHTCap,
u8 *len, u8 IsEncrypt, bool bAssoc)
{
struct rt_hi_throughput *pHT = ieee->pHTInfo;
struct ht_capab_ele *pCapELE = NULL;
if ((posHTCap == NULL) || (pHT == NULL)) {
RTLLIB_DEBUG(RTLLIB_DL_ERR, "posHTCap or pHTInfo can't be "
"null in HTConstructCapabilityElement()\n");
return;
}
memset(posHTCap, 0, *len);
if ((bAssoc) && (pHT->ePeerHTSpecVer == HT_SPEC_VER_EWC)) {
u8 EWC11NHTCap[] = {0x00, 0x90, 0x4c, 0x33};
memcpy(posHTCap, EWC11NHTCap, sizeof(EWC11NHTCap));
pCapELE = (struct ht_capab_ele *)&(posHTCap[4]);
*len = 30 + 2;
} else {
pCapELE = (struct ht_capab_ele *)posHTCap;
*len = 26 + 2;
}
pCapELE->AdvCoding = 0;
if (ieee->GetHalfNmodeSupportByAPsHandler(ieee->dev))
pCapELE->ChlWidth = 0;
else
pCapELE->ChlWidth = (pHT->bRegBW40MHz ? 1 : 0);
pCapELE->MimoPwrSave = pHT->SelfMimoPs;
pCapELE->GreenField = 0;
pCapELE->ShortGI20Mhz = 1;
pCapELE->ShortGI40Mhz = 1;
pCapELE->TxSTBC = 1;
pCapELE->RxSTBC = 0;
pCapELE->DelayBA = 0;
pCapELE->MaxAMSDUSize = (MAX_RECEIVE_BUFFER_SIZE >= 7935) ? 1 : 0;
pCapELE->DssCCk = ((pHT->bRegBW40MHz) ? (pHT->bRegSuppCCK ? 1 : 0) : 0);
pCapELE->PSMP = 0;
pCapELE->LSigTxopProtect = 0;
RTLLIB_DEBUG(RTLLIB_DL_HT, "TX HT cap/info ele BW=%d MaxAMSDUSize:%d "
"DssCCk:%d\n", pCapELE->ChlWidth, pCapELE->MaxAMSDUSize,
pCapELE->DssCCk);
if (IsEncrypt) {
pCapELE->MPDUDensity = 7;
pCapELE->MaxRxAMPDUFactor = 2;
} else {
pCapELE->MaxRxAMPDUFactor = 3;
pCapELE->MPDUDensity = 0;
}
memcpy(pCapELE->MCS, ieee->Regdot11HTOperationalRateSet, 16);
memset(&pCapELE->ExtHTCapInfo, 0, 2);
memset(pCapELE->TxBFCap, 0, 4);
pCapELE->ASCap = 0;
if (bAssoc) {
if (pHT->IOTAction & HT_IOT_ACT_DISABLE_MCS15)
pCapELE->MCS[1] &= 0x7f;
if (pHT->IOTAction & HT_IOT_ACT_DISABLE_MCS14)
pCapELE->MCS[1] &= 0xbf;
if (pHT->IOTAction & HT_IOT_ACT_DISABLE_ALL_2SS)
pCapELE->MCS[1] &= 0x00;
if (pHT->IOTAction & HT_IOT_ACT_DISABLE_RX_40MHZ_SHORT_GI)
pCapELE->ShortGI40Mhz = 0;
if (ieee->GetHalfNmodeSupportByAPsHandler(ieee->dev)) {
pCapELE->ChlWidth = 0;
pCapELE->MCS[1] = 0;
}
}
return;
}
void HTConstructInfoElement(struct rtllib_device *ieee, u8 *posHTInfo,
u8 *len, u8 IsEncrypt)
{
struct rt_hi_throughput *pHT = ieee->pHTInfo;
struct ht_info_ele *pHTInfoEle = (struct ht_info_ele *)posHTInfo;
if ((posHTInfo == NULL) || (pHTInfoEle == NULL)) {
RTLLIB_DEBUG(RTLLIB_DL_ERR, "posHTInfo or pHTInfoEle can't be "
"null in HTConstructInfoElement()\n");
return;
}
memset(posHTInfo, 0, *len);
if ((ieee->iw_mode == IW_MODE_ADHOC) ||
(ieee->iw_mode == IW_MODE_MASTER)) {
pHTInfoEle->ControlChl = ieee->current_network.channel;
pHTInfoEle->ExtChlOffset = ((pHT->bRegBW40MHz == false) ?
HT_EXTCHNL_OFFSET_NO_EXT :
(ieee->current_network.channel <= 6)
? HT_EXTCHNL_OFFSET_UPPER :
HT_EXTCHNL_OFFSET_LOWER);
pHTInfoEle->RecommemdedTxWidth = pHT->bRegBW40MHz;
pHTInfoEle->RIFS = 0;
pHTInfoEle->PSMPAccessOnly = 0;
pHTInfoEle->SrvIntGranularity = 0;
pHTInfoEle->OptMode = pHT->CurrentOpMode;
pHTInfoEle->NonGFDevPresent = 0;
pHTInfoEle->DualBeacon = 0;
pHTInfoEle->SecondaryBeacon = 0;
pHTInfoEle->LSigTxopProtectFull = 0;
pHTInfoEle->PcoActive = 0;
pHTInfoEle->PcoPhase = 0;
memset(pHTInfoEle->BasicMSC, 0, 16);
*len = 22 + 2;
} else {
*len = 0;
}
return;
}
void HTConstructRT2RTAggElement(struct rtllib_device *ieee, u8 *posRT2RTAgg,
u8 *len)
{
if (posRT2RTAgg == NULL) {
RTLLIB_DEBUG(RTLLIB_DL_ERR, "posRT2RTAgg can't be null in "
"HTConstructRT2RTAggElement()\n");
return;
}
memset(posRT2RTAgg, 0, *len);
*posRT2RTAgg++ = 0x00;
*posRT2RTAgg++ = 0xe0;
*posRT2RTAgg++ = 0x4c;
*posRT2RTAgg++ = 0x02;
*posRT2RTAgg++ = 0x01;
*posRT2RTAgg = 0x30;
if (ieee->bSupportRemoteWakeUp)
*posRT2RTAgg |= RT_HT_CAP_USE_WOW;
*len = 6 + 2;
return;
}
static u8 HT_PickMCSRate(struct rtllib_device *ieee, u8 *pOperateMCS)
{
u8 i;
if (pOperateMCS == NULL) {
RTLLIB_DEBUG(RTLLIB_DL_ERR, "pOperateMCS can't be null"
" in HT_PickMCSRate()\n");
return false;
}
switch (ieee->mode) {
case IEEE_A:
case IEEE_B:
case IEEE_G:
for (i = 0; i <= 15; i++)
pOperateMCS[i] = 0;
break;
case IEEE_N_24G:
case IEEE_N_5G:
pOperateMCS[0] &= RATE_ADPT_1SS_MASK;
pOperateMCS[1] &= RATE_ADPT_2SS_MASK;
pOperateMCS[3] &= RATE_ADPT_MCS32_MASK;
break;
default:
break;
}
return true;
}
u8 HTGetHighestMCSRate(struct rtllib_device *ieee, u8 *pMCSRateSet,
u8 *pMCSFilter)
{
u8 i, j;
u8 bitMap;
u8 mcsRate = 0;
u8 availableMcsRate[16];
if (pMCSRateSet == NULL || pMCSFilter == NULL) {
RTLLIB_DEBUG(RTLLIB_DL_ERR, "pMCSRateSet or pMCSFilter can't "
"be null in HTGetHighestMCSRate()\n");
return false;
}
for (i = 0; i < 16; i++)
availableMcsRate[i] = pMCSRateSet[i] & pMCSFilter[i];
for (i = 0; i < 16; i++) {
if (availableMcsRate[i] != 0)
break;
}
if (i == 16)
return false;
for (i = 0; i < 16; i++) {
if (availableMcsRate[i] != 0) {
bitMap = availableMcsRate[i];
for (j = 0; j < 8; j++) {
if ((bitMap%2) != 0) {
if (HTMcsToDataRate(ieee, (8*i+j)) >
HTMcsToDataRate(ieee, mcsRate))
mcsRate = (8*i+j);
}
bitMap = bitMap>>1;
}
}
}
return mcsRate | 0x80;
}
u8 HTFilterMCSRate(struct rtllib_device *ieee, u8 *pSupportMCS, u8 *pOperateMCS)
{
u8 i;
for (i = 0; i <= 15; i++)
pOperateMCS[i] = ieee->Regdot11TxHTOperationalRateSet[i] &
pSupportMCS[i];
HT_PickMCSRate(ieee, pOperateMCS);
if (ieee->GetHalfNmodeSupportByAPsHandler(ieee->dev))
pOperateMCS[1] = 0;
for (i = 2; i <= 15; i++)
pOperateMCS[i] = 0;
return true;
}
void HTOnAssocRsp(struct rtllib_device *ieee)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
struct ht_capab_ele *pPeerHTCap = NULL;
struct ht_info_ele *pPeerHTInfo = NULL;
u16 nMaxAMSDUSize = 0;
u8 *pMcsFilter = NULL;
static u8 EWC11NHTCap[] = {0x00, 0x90, 0x4c, 0x33};
static u8 EWC11NHTInfo[] = {0x00, 0x90, 0x4c, 0x34};
if (pHTInfo->bCurrentHTSupport == false) {
RTLLIB_DEBUG(RTLLIB_DL_ERR, "<=== HTOnAssocRsp(): "
"HT_DISABLE\n");
return;
}
RTLLIB_DEBUG(RTLLIB_DL_HT, "===> HTOnAssocRsp_wq(): HT_ENABLE\n");
if (!memcmp(pHTInfo->PeerHTCapBuf, EWC11NHTCap, sizeof(EWC11NHTCap)))
pPeerHTCap = (struct ht_capab_ele *)(&pHTInfo->PeerHTCapBuf[4]);
else
pPeerHTCap = (struct ht_capab_ele *)(pHTInfo->PeerHTCapBuf);
if (!memcmp(pHTInfo->PeerHTInfoBuf, EWC11NHTInfo, sizeof(EWC11NHTInfo)))
pPeerHTInfo = (struct ht_info_ele *)
(&pHTInfo->PeerHTInfoBuf[4]);
else
pPeerHTInfo = (struct ht_info_ele *)(pHTInfo->PeerHTInfoBuf);
RTLLIB_DEBUG_DATA(RTLLIB_DL_DATA | RTLLIB_DL_HT, pPeerHTCap,
sizeof(struct ht_capab_ele));
HTSetConnectBwMode(ieee, (enum ht_channel_width)(pPeerHTCap->ChlWidth),
(enum ht_extchnl_offset)(pPeerHTInfo->ExtChlOffset));
pHTInfo->bCurTxBW40MHz = ((pPeerHTInfo->RecommemdedTxWidth == 1) ?
true : false);
pHTInfo->bCurShortGI20MHz = ((pHTInfo->bRegShortGI20MHz) ?
((pPeerHTCap->ShortGI20Mhz == 1) ?
true : false) : false);
pHTInfo->bCurShortGI40MHz = ((pHTInfo->bRegShortGI40MHz) ?
((pPeerHTCap->ShortGI40Mhz == 1) ?
true : false) : false);
pHTInfo->bCurSuppCCK = ((pHTInfo->bRegSuppCCK) ?
((pPeerHTCap->DssCCk == 1) ? true :
false) : false);
pHTInfo->bCurrent_AMSDU_Support = pHTInfo->bAMSDU_Support;
nMaxAMSDUSize = (pPeerHTCap->MaxAMSDUSize == 0) ? 3839 : 7935;
if (pHTInfo->nAMSDU_MaxSize > nMaxAMSDUSize)
pHTInfo->nCurrent_AMSDU_MaxSize = nMaxAMSDUSize;
else
pHTInfo->nCurrent_AMSDU_MaxSize = pHTInfo->nAMSDU_MaxSize;
pHTInfo->bCurrentAMPDUEnable = pHTInfo->bAMPDUEnable;
if (ieee->rtllib_ap_sec_type &&
(ieee->rtllib_ap_sec_type(ieee)&(SEC_ALG_WEP|SEC_ALG_TKIP))) {
if ((pHTInfo->IOTPeer == HT_IOT_PEER_ATHEROS) ||
(pHTInfo->IOTPeer == HT_IOT_PEER_UNKNOWN))
pHTInfo->bCurrentAMPDUEnable = false;
}
if (!pHTInfo->bRegRT2RTAggregation) {
if (pHTInfo->AMPDU_Factor > pPeerHTCap->MaxRxAMPDUFactor)
pHTInfo->CurrentAMPDUFactor =
pPeerHTCap->MaxRxAMPDUFactor;
else
pHTInfo->CurrentAMPDUFactor = pHTInfo->AMPDU_Factor;
} else {
if (ieee->current_network.bssht.bdRT2RTAggregation) {
if (ieee->pairwise_key_type != KEY_TYPE_NA)
pHTInfo->CurrentAMPDUFactor =
pPeerHTCap->MaxRxAMPDUFactor;
else
pHTInfo->CurrentAMPDUFactor = HT_AGG_SIZE_64K;
} else {
if (pPeerHTCap->MaxRxAMPDUFactor < HT_AGG_SIZE_32K)
pHTInfo->CurrentAMPDUFactor =
pPeerHTCap->MaxRxAMPDUFactor;
else
pHTInfo->CurrentAMPDUFactor = HT_AGG_SIZE_32K;
}
}
if (pHTInfo->MPDU_Density > pPeerHTCap->MPDUDensity)
pHTInfo->CurrentMPDUDensity = pHTInfo->MPDU_Density;
else
pHTInfo->CurrentMPDUDensity = pPeerHTCap->MPDUDensity;
if (pHTInfo->IOTAction & HT_IOT_ACT_TX_USE_AMSDU_8K) {
pHTInfo->bCurrentAMPDUEnable = false;
pHTInfo->ForcedAMSDUMode = HT_AGG_FORCE_ENABLE;
pHTInfo->ForcedAMSDUMaxSize = 7935;
}
pHTInfo->bCurRxReorderEnable = pHTInfo->bRegRxReorderEnable;
if (pPeerHTCap->MCS[0] == 0)
pPeerHTCap->MCS[0] = 0xff;
HTIOTActDetermineRaFunc(ieee, ((pPeerHTCap->MCS[1]) != 0));
HTFilterMCSRate(ieee, pPeerHTCap->MCS, ieee->dot11HTOperationalRateSet);
pHTInfo->PeerMimoPs = pPeerHTCap->MimoPwrSave;
if (pHTInfo->PeerMimoPs == MIMO_PS_STATIC)
pMcsFilter = MCS_FILTER_1SS;
else
pMcsFilter = MCS_FILTER_ALL;
ieee->HTHighestOperaRate = HTGetHighestMCSRate(ieee,
ieee->dot11HTOperationalRateSet, pMcsFilter);
ieee->HTCurrentOperaRate = ieee->HTHighestOperaRate;
pHTInfo->CurrentOpMode = pPeerHTInfo->OptMode;
}
void HTInitializeHTInfo(struct rtllib_device *ieee)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
RTLLIB_DEBUG(RTLLIB_DL_HT, "===========>%s()\n", __func__);
pHTInfo->bCurrentHTSupport = false;
pHTInfo->bCurBW40MHz = false;
pHTInfo->bCurTxBW40MHz = false;
pHTInfo->bCurShortGI20MHz = false;
pHTInfo->bCurShortGI40MHz = false;
pHTInfo->bForcedShortGI = false;
pHTInfo->bCurSuppCCK = true;
pHTInfo->bCurrent_AMSDU_Support = false;
pHTInfo->nCurrent_AMSDU_MaxSize = pHTInfo->nAMSDU_MaxSize;
pHTInfo->CurrentMPDUDensity = pHTInfo->MPDU_Density;
pHTInfo->CurrentAMPDUFactor = pHTInfo->AMPDU_Factor;
memset((void *)(&(pHTInfo->SelfHTCap)), 0,
sizeof(pHTInfo->SelfHTCap));
memset((void *)(&(pHTInfo->SelfHTInfo)), 0,
sizeof(pHTInfo->SelfHTInfo));
memset((void *)(&(pHTInfo->PeerHTCapBuf)), 0,
sizeof(pHTInfo->PeerHTCapBuf));
memset((void *)(&(pHTInfo->PeerHTInfoBuf)), 0,
sizeof(pHTInfo->PeerHTInfoBuf));
pHTInfo->bSwBwInProgress = false;
pHTInfo->ChnlOp = CHNLOP_NONE;
pHTInfo->ePeerHTSpecVer = HT_SPEC_VER_IEEE;
pHTInfo->bCurrentRT2RTAggregation = false;
pHTInfo->bCurrentRT2RTLongSlotTime = false;
pHTInfo->RT2RT_HT_Mode = (enum rt_ht_capability)0;
pHTInfo->IOTPeer = 0;
pHTInfo->IOTAction = 0;
pHTInfo->IOTRaFunc = 0;
{
u8 *RegHTSuppRateSets = &(ieee->RegHTSuppRateSet[0]);
RegHTSuppRateSets[0] = 0xFF;
RegHTSuppRateSets[1] = 0xFF;
RegHTSuppRateSets[4] = 0x01;
}
}
void HTInitializeBssDesc(struct bss_ht *pBssHT)
{
pBssHT->bdSupportHT = false;
memset(pBssHT->bdHTCapBuf, 0, sizeof(pBssHT->bdHTCapBuf));
pBssHT->bdHTCapLen = 0;
memset(pBssHT->bdHTInfoBuf, 0, sizeof(pBssHT->bdHTInfoBuf));
pBssHT->bdHTInfoLen = 0;
pBssHT->bdHTSpecVer = HT_SPEC_VER_IEEE;
pBssHT->bdRT2RTAggregation = false;
pBssHT->bdRT2RTLongSlotTime = false;
pBssHT->RT2RT_HT_Mode = (enum rt_ht_capability)0;
}
void HTResetSelfAndSavePeerSetting(struct rtllib_device *ieee,
struct rtllib_network *pNetwork)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
u8 bIOTAction = 0;
RTLLIB_DEBUG(RTLLIB_DL_HT, "==============>%s()\n", __func__);
if (pNetwork->bssht.bdSupportHT) {
pHTInfo->bCurrentHTSupport = true;
pHTInfo->ePeerHTSpecVer = pNetwork->bssht.bdHTSpecVer;
if (pNetwork->bssht.bdHTCapLen > 0 &&
pNetwork->bssht.bdHTCapLen <= sizeof(pHTInfo->PeerHTCapBuf))
memcpy(pHTInfo->PeerHTCapBuf,
pNetwork->bssht.bdHTCapBuf,
pNetwork->bssht.bdHTCapLen);
if (pNetwork->bssht.bdHTInfoLen > 0 &&
pNetwork->bssht.bdHTInfoLen <=
sizeof(pHTInfo->PeerHTInfoBuf))
memcpy(pHTInfo->PeerHTInfoBuf,
pNetwork->bssht.bdHTInfoBuf,
pNetwork->bssht.bdHTInfoLen);
if (pHTInfo->bRegRT2RTAggregation) {
pHTInfo->bCurrentRT2RTAggregation =
pNetwork->bssht.bdRT2RTAggregation;
pHTInfo->bCurrentRT2RTLongSlotTime =
pNetwork->bssht.bdRT2RTLongSlotTime;
pHTInfo->RT2RT_HT_Mode = pNetwork->bssht.RT2RT_HT_Mode;
} else {
pHTInfo->bCurrentRT2RTAggregation = false;
pHTInfo->bCurrentRT2RTLongSlotTime = false;
pHTInfo->RT2RT_HT_Mode = (enum rt_ht_capability)0;
}
HTIOTPeerDetermine(ieee);
pHTInfo->IOTAction = 0;
bIOTAction = HTIOTActIsDisableMCS14(ieee, pNetwork->bssid);
if (bIOTAction)
pHTInfo->IOTAction |= HT_IOT_ACT_DISABLE_MCS14;
bIOTAction = HTIOTActIsDisableMCS15(ieee);
if (bIOTAction)
pHTInfo->IOTAction |= HT_IOT_ACT_DISABLE_MCS15;
bIOTAction = HTIOTActIsDisableMCSTwoSpatialStream(ieee);
if (bIOTAction)
pHTInfo->IOTAction |= HT_IOT_ACT_DISABLE_ALL_2SS;
bIOTAction = HTIOTActIsDisableEDCATurbo(ieee, pNetwork->bssid);
if (bIOTAction)
pHTInfo->IOTAction |= HT_IOT_ACT_DISABLE_EDCA_TURBO;
bIOTAction = HTIOTActIsMgntUseCCK6M(ieee, pNetwork);
if (bIOTAction)
pHTInfo->IOTAction |= HT_IOT_ACT_MGNT_USE_CCK_6M;
bIOTAction = HTIOTActIsCCDFsync(ieee);
if (bIOTAction)
pHTInfo->IOTAction |= HT_IOT_ACT_CDD_FSYNC;
} else {
pHTInfo->bCurrentHTSupport = false;
pHTInfo->bCurrentRT2RTAggregation = false;
pHTInfo->bCurrentRT2RTLongSlotTime = false;
pHTInfo->RT2RT_HT_Mode = (enum rt_ht_capability)0;
pHTInfo->IOTAction = 0;
pHTInfo->IOTRaFunc = 0;
}
}
void HTUpdateSelfAndPeerSetting(struct rtllib_device *ieee,
struct rtllib_network *pNetwork)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
struct ht_info_ele *pPeerHTInfo =
(struct ht_info_ele *)pNetwork->bssht.bdHTInfoBuf;
if (pHTInfo->bCurrentHTSupport) {
if (pNetwork->bssht.bdHTInfoLen != 0)
pHTInfo->CurrentOpMode = pPeerHTInfo->OptMode;
}
}
void HTUseDefaultSetting(struct rtllib_device *ieee)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
if (pHTInfo->bEnableHT) {
pHTInfo->bCurrentHTSupport = true;
pHTInfo->bCurSuppCCK = pHTInfo->bRegSuppCCK;
pHTInfo->bCurBW40MHz = pHTInfo->bRegBW40MHz;
pHTInfo->bCurShortGI20MHz = pHTInfo->bRegShortGI20MHz;
pHTInfo->bCurShortGI40MHz = pHTInfo->bRegShortGI40MHz;
if (ieee->iw_mode == IW_MODE_ADHOC)
ieee->current_network.qos_data.active =
ieee->current_network.qos_data.supported;
pHTInfo->bCurrent_AMSDU_Support = pHTInfo->bAMSDU_Support;
pHTInfo->nCurrent_AMSDU_MaxSize = pHTInfo->nAMSDU_MaxSize;
pHTInfo->bCurrentAMPDUEnable = pHTInfo->bAMPDUEnable;
pHTInfo->CurrentAMPDUFactor = pHTInfo->AMPDU_Factor;
pHTInfo->CurrentMPDUDensity = pHTInfo->CurrentMPDUDensity;
HTFilterMCSRate(ieee, ieee->Regdot11TxHTOperationalRateSet,
ieee->dot11HTOperationalRateSet);
ieee->HTHighestOperaRate = HTGetHighestMCSRate(ieee,
ieee->dot11HTOperationalRateSet,
MCS_FILTER_ALL);
ieee->HTCurrentOperaRate = ieee->HTHighestOperaRate;
} else {
pHTInfo->bCurrentHTSupport = false;
}
return;
}
u8 HTCCheck(struct rtllib_device *ieee, u8 *pFrame)
{
if (ieee->pHTInfo->bCurrentHTSupport) {
if ((IsQoSDataFrame(pFrame) && Frame_Order(pFrame)) == 1) {
RTLLIB_DEBUG(RTLLIB_DL_HT, "HT CONTROL FILED "
"EXIST!!\n");
return true;
}
}
return false;
}
static void HTSetConnectBwModeCallback(struct rtllib_device *ieee)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
RTLLIB_DEBUG(RTLLIB_DL_HT, "======>%s()\n", __func__);
if (pHTInfo->bCurBW40MHz) {
if (pHTInfo->CurSTAExtChnlOffset == HT_EXTCHNL_OFFSET_UPPER)
ieee->set_chan(ieee->dev,
ieee->current_network.channel + 2);
else if (pHTInfo->CurSTAExtChnlOffset ==
HT_EXTCHNL_OFFSET_LOWER)
ieee->set_chan(ieee->dev,
ieee->current_network.channel - 2);
else
ieee->set_chan(ieee->dev,
ieee->current_network.channel);
ieee->SetBWModeHandler(ieee->dev, HT_CHANNEL_WIDTH_20_40,
pHTInfo->CurSTAExtChnlOffset);
} else {
ieee->set_chan(ieee->dev, ieee->current_network.channel);
ieee->SetBWModeHandler(ieee->dev, HT_CHANNEL_WIDTH_20,
HT_EXTCHNL_OFFSET_NO_EXT);
}
pHTInfo->bSwBwInProgress = false;
}
void HTSetConnectBwMode(struct rtllib_device *ieee,
enum ht_channel_width Bandwidth,
enum ht_extchnl_offset Offset)
{
struct rt_hi_throughput *pHTInfo = ieee->pHTInfo;
if (pHTInfo->bRegBW40MHz == false)
return;
if (ieee->GetHalfNmodeSupportByAPsHandler(ieee->dev))
Bandwidth = HT_CHANNEL_WIDTH_20;
if (pHTInfo->bSwBwInProgress) {
printk(KERN_INFO "%s: bSwBwInProgress!!\n", __func__);
return;
}
if (Bandwidth == HT_CHANNEL_WIDTH_20_40) {
if (ieee->current_network.channel < 2 &&
Offset == HT_EXTCHNL_OFFSET_LOWER)
Offset = HT_EXTCHNL_OFFSET_NO_EXT;
if (Offset == HT_EXTCHNL_OFFSET_UPPER ||
Offset == HT_EXTCHNL_OFFSET_LOWER) {
pHTInfo->bCurBW40MHz = true;
pHTInfo->CurSTAExtChnlOffset = Offset;
} else {
pHTInfo->bCurBW40MHz = false;
pHTInfo->CurSTAExtChnlOffset = HT_EXTCHNL_OFFSET_NO_EXT;
}
} else {
pHTInfo->bCurBW40MHz = false;
pHTInfo->CurSTAExtChnlOffset = HT_EXTCHNL_OFFSET_NO_EXT;
}
printk(KERN_INFO "%s():pHTInfo->bCurBW40MHz:%x\n", __func__,
pHTInfo->bCurBW40MHz);
pHTInfo->bSwBwInProgress = true;
HTSetConnectBwModeCallback(ieee);
}
