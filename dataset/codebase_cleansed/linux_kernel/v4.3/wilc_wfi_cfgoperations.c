void clear_shadow_scan(void *pUserVoid)
{
int i;
if (op_ifcs == 0) {
del_timer_sync(&hAgingTimer);
PRINT_INFO(CORECONFIG_DBG, "destroy aging timer\n");
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
if (astrLastScannedNtwrksShadow[u32LastScannedNtwrksCountShadow].pu8IEs != NULL) {
kfree(astrLastScannedNtwrksShadow[i].pu8IEs);
astrLastScannedNtwrksShadow[u32LastScannedNtwrksCountShadow].pu8IEs = NULL;
}
host_int_freeJoinParams(astrLastScannedNtwrksShadow[i].pJoinParams);
astrLastScannedNtwrksShadow[i].pJoinParams = NULL;
}
u32LastScannedNtwrksCountShadow = 0;
}
}
uint32_t get_rssi_avg(tstrNetworkInfo *pstrNetworkInfo)
{
uint8_t i;
int rssi_v = 0;
uint8_t num_rssi = (pstrNetworkInfo->strRssi.u8Full) ? NUM_RSSI : (pstrNetworkInfo->strRssi.u8Index);
for (i = 0; i < num_rssi; i++)
rssi_v += pstrNetworkInfo->strRssi.as8RSSI[i];
rssi_v /= num_rssi;
return rssi_v;
}
void refresh_scan(void *pUserVoid, uint8_t all, bool bDirectScan)
{
struct WILC_WFI_priv *priv;
struct wiphy *wiphy;
struct cfg80211_bss *bss = NULL;
int i;
int rssi = 0;
priv = (struct WILC_WFI_priv *)pUserVoid;
wiphy = priv->dev->ieee80211_ptr->wiphy;
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
tstrNetworkInfo *pstrNetworkInfo;
pstrNetworkInfo = &(astrLastScannedNtwrksShadow[i]);
if ((!pstrNetworkInfo->u8Found) || all) {
s32 s32Freq;
struct ieee80211_channel *channel;
if (pstrNetworkInfo != NULL) {
s32Freq = ieee80211_channel_to_frequency((s32)pstrNetworkInfo->u8channel, IEEE80211_BAND_2GHZ);
channel = ieee80211_get_channel(wiphy, s32Freq);
rssi = get_rssi_avg(pstrNetworkInfo);
if (memcmp("DIRECT-", pstrNetworkInfo->au8ssid, 7) || bDirectScan) {
bss = cfg80211_inform_bss(wiphy, channel, CFG80211_BSS_FTYPE_UNKNOWN, pstrNetworkInfo->au8bssid, pstrNetworkInfo->u64Tsf, pstrNetworkInfo->u16CapInfo,
pstrNetworkInfo->u16BeaconPeriod, (const u8 *)pstrNetworkInfo->pu8IEs,
(size_t)pstrNetworkInfo->u16IEsLen, (((s32)rssi) * 100), GFP_KERNEL);
cfg80211_put_bss(wiphy, bss);
}
}
}
}
}
void reset_shadow_found(void *pUserVoid)
{
int i;
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
astrLastScannedNtwrksShadow[i].u8Found = 0;
}
}
void update_scan_time(void *pUserVoid)
{
int i;
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
astrLastScannedNtwrksShadow[i].u32TimeRcvdInScan = jiffies;
}
}
static void remove_network_from_shadow(unsigned long arg)
{
unsigned long now = jiffies;
int i, j;
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
if (time_after(now, astrLastScannedNtwrksShadow[i].u32TimeRcvdInScan + (unsigned long)(SCAN_RESULT_EXPIRE))) {
PRINT_D(CFG80211_DBG, "Network expired in ScanShadow: %s\n", astrLastScannedNtwrksShadow[i].au8ssid);
if (astrLastScannedNtwrksShadow[i].pu8IEs != NULL) {
kfree(astrLastScannedNtwrksShadow[i].pu8IEs);
astrLastScannedNtwrksShadow[i].pu8IEs = NULL;
}
host_int_freeJoinParams(astrLastScannedNtwrksShadow[i].pJoinParams);
for (j = i; (j < u32LastScannedNtwrksCountShadow - 1); j++) {
astrLastScannedNtwrksShadow[j] = astrLastScannedNtwrksShadow[j + 1];
}
u32LastScannedNtwrksCountShadow--;
}
}
PRINT_D(CFG80211_DBG, "Number of cached networks: %d\n", u32LastScannedNtwrksCountShadow);
if (u32LastScannedNtwrksCountShadow != 0) {
hAgingTimer.data = arg;
mod_timer(&hAgingTimer, jiffies + msecs_to_jiffies(AGING_TIME));
} else {
PRINT_D(CFG80211_DBG, "No need to restart Aging timer\n");
}
}
static void clear_duringIP(unsigned long arg)
{
PRINT_D(GENERIC_DBG, "GO:IP Obtained , enable scan\n");
g_obtainingIP = false;
}
int8_t is_network_in_shadow(tstrNetworkInfo *pstrNetworkInfo, void *pUserVoid)
{
int8_t state = -1;
int i;
if (u32LastScannedNtwrksCountShadow == 0) {
PRINT_D(CFG80211_DBG, "Starting Aging timer\n");
hAgingTimer.data = (unsigned long)pUserVoid;
mod_timer(&hAgingTimer, jiffies + msecs_to_jiffies(AGING_TIME));
state = -1;
} else {
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
if (memcmp(astrLastScannedNtwrksShadow[i].au8bssid,
pstrNetworkInfo->au8bssid, 6) == 0) {
state = i;
break;
}
}
}
return state;
}
void add_network_to_shadow(tstrNetworkInfo *pstrNetworkInfo, void *pUserVoid, void *pJoinParams)
{
int8_t ap_found = is_network_in_shadow(pstrNetworkInfo, pUserVoid);
uint32_t ap_index = 0;
uint8_t rssi_index = 0;
if (u32LastScannedNtwrksCountShadow >= MAX_NUM_SCANNED_NETWORKS_SHADOW) {
PRINT_D(CFG80211_DBG, "Shadow network reached its maximum limit\n");
return;
}
if (ap_found == -1) {
ap_index = u32LastScannedNtwrksCountShadow;
u32LastScannedNtwrksCountShadow++;
} else {
ap_index = ap_found;
}
rssi_index = astrLastScannedNtwrksShadow[ap_index].strRssi.u8Index;
astrLastScannedNtwrksShadow[ap_index].strRssi.as8RSSI[rssi_index++] = pstrNetworkInfo->s8rssi;
if (rssi_index == NUM_RSSI) {
rssi_index = 0;
astrLastScannedNtwrksShadow[ap_index].strRssi.u8Full = 1;
}
astrLastScannedNtwrksShadow[ap_index].strRssi.u8Index = rssi_index;
astrLastScannedNtwrksShadow[ap_index].s8rssi = pstrNetworkInfo->s8rssi;
astrLastScannedNtwrksShadow[ap_index].u16CapInfo = pstrNetworkInfo->u16CapInfo;
astrLastScannedNtwrksShadow[ap_index].u8SsidLen = pstrNetworkInfo->u8SsidLen;
memcpy(astrLastScannedNtwrksShadow[ap_index].au8ssid,
pstrNetworkInfo->au8ssid, pstrNetworkInfo->u8SsidLen);
memcpy(astrLastScannedNtwrksShadow[ap_index].au8bssid,
pstrNetworkInfo->au8bssid, ETH_ALEN);
astrLastScannedNtwrksShadow[ap_index].u16BeaconPeriod = pstrNetworkInfo->u16BeaconPeriod;
astrLastScannedNtwrksShadow[ap_index].u8DtimPeriod = pstrNetworkInfo->u8DtimPeriod;
astrLastScannedNtwrksShadow[ap_index].u8channel = pstrNetworkInfo->u8channel;
astrLastScannedNtwrksShadow[ap_index].u16IEsLen = pstrNetworkInfo->u16IEsLen;
astrLastScannedNtwrksShadow[ap_index].u64Tsf = pstrNetworkInfo->u64Tsf;
if (ap_found != -1)
kfree(astrLastScannedNtwrksShadow[ap_index].pu8IEs);
astrLastScannedNtwrksShadow[ap_index].pu8IEs =
WILC_MALLOC(pstrNetworkInfo->u16IEsLen);
memcpy(astrLastScannedNtwrksShadow[ap_index].pu8IEs,
pstrNetworkInfo->pu8IEs, pstrNetworkInfo->u16IEsLen);
astrLastScannedNtwrksShadow[ap_index].u32TimeRcvdInScan = jiffies;
astrLastScannedNtwrksShadow[ap_index].u32TimeRcvdInScanCached = jiffies;
astrLastScannedNtwrksShadow[ap_index].u8Found = 1;
if (ap_found != -1)
host_int_freeJoinParams(astrLastScannedNtwrksShadow[ap_index].pJoinParams);
astrLastScannedNtwrksShadow[ap_index].pJoinParams = pJoinParams;
}
static void CfgScanResult(tenuScanEvent enuScanEvent, tstrNetworkInfo *pstrNetworkInfo, void *pUserVoid, void *pJoinParams)
{
struct WILC_WFI_priv *priv;
struct wiphy *wiphy;
s32 s32Freq;
struct ieee80211_channel *channel;
s32 s32Error = WILC_SUCCESS;
struct cfg80211_bss *bss = NULL;
priv = (struct WILC_WFI_priv *)pUserVoid;
if (priv->bCfgScanning == true) {
if (enuScanEvent == SCAN_EVENT_NETWORK_FOUND) {
wiphy = priv->dev->ieee80211_ptr->wiphy;
WILC_NULLCHECK(s32Error, wiphy);
if (wiphy->signal_type == CFG80211_SIGNAL_TYPE_UNSPEC
&&
((((s32)pstrNetworkInfo->s8rssi) * 100) < 0
||
(((s32)pstrNetworkInfo->s8rssi) * 100) > 100)
) {
WILC_ERRORREPORT(s32Error, WILC_FAIL);
}
if (pstrNetworkInfo != NULL) {
s32Freq = ieee80211_channel_to_frequency((s32)pstrNetworkInfo->u8channel, IEEE80211_BAND_2GHZ);
channel = ieee80211_get_channel(wiphy, s32Freq);
WILC_NULLCHECK(s32Error, channel);
PRINT_INFO(CFG80211_DBG, "Network Info:: CHANNEL Frequency: %d, RSSI: %d, CapabilityInfo: %d,"
"BeaconPeriod: %d\n", channel->center_freq, (((s32)pstrNetworkInfo->s8rssi) * 100),
pstrNetworkInfo->u16CapInfo, pstrNetworkInfo->u16BeaconPeriod);
if (pstrNetworkInfo->bNewNetwork == true) {
if (priv->u32RcvdChCount < MAX_NUM_SCANNED_NETWORKS) {
PRINT_D(CFG80211_DBG, "Network %s found\n", pstrNetworkInfo->au8ssid);
priv->u32RcvdChCount++;
if (pJoinParams == NULL) {
PRINT_INFO(CORECONFIG_DBG, ">> Something really bad happened\n");
}
add_network_to_shadow(pstrNetworkInfo, priv, pJoinParams);
if (!(memcmp("DIRECT-", pstrNetworkInfo->au8ssid, 7))) {
bss = cfg80211_inform_bss(wiphy, channel, CFG80211_BSS_FTYPE_UNKNOWN, pstrNetworkInfo->au8bssid, pstrNetworkInfo->u64Tsf, pstrNetworkInfo->u16CapInfo,
pstrNetworkInfo->u16BeaconPeriod, (const u8 *)pstrNetworkInfo->pu8IEs,
(size_t)pstrNetworkInfo->u16IEsLen, (((s32)pstrNetworkInfo->s8rssi) * 100), GFP_KERNEL);
cfg80211_put_bss(wiphy, bss);
}
} else {
PRINT_ER("Discovered networks exceeded the max limit\n");
}
} else {
u32 i;
for (i = 0; i < priv->u32RcvdChCount; i++) {
if (memcmp(astrLastScannedNtwrksShadow[i].au8bssid, pstrNetworkInfo->au8bssid, 6) == 0) {
PRINT_D(CFG80211_DBG, "Update RSSI of %s\n", astrLastScannedNtwrksShadow[i].au8ssid);
astrLastScannedNtwrksShadow[i].s8rssi = pstrNetworkInfo->s8rssi;
astrLastScannedNtwrksShadow[i].u32TimeRcvdInScan = jiffies;
break;
}
}
}
}
} else if (enuScanEvent == SCAN_EVENT_DONE) {
PRINT_D(CFG80211_DBG, "Scan Done[%p]\n", priv->dev);
PRINT_D(CFG80211_DBG, "Refreshing Scan ...\n");
refresh_scan(priv, 1, false);
if (priv->u32RcvdChCount > 0)
PRINT_D(CFG80211_DBG, "%d Network(s) found\n", priv->u32RcvdChCount);
else
PRINT_D(CFG80211_DBG, "No networks found\n");
down(&(priv->hSemScanReq));
if (priv->pstrScanReq != NULL) {
cfg80211_scan_done(priv->pstrScanReq, false);
priv->u32RcvdChCount = 0;
priv->bCfgScanning = false;
priv->pstrScanReq = NULL;
}
up(&(priv->hSemScanReq));
}
else if (enuScanEvent == SCAN_EVENT_ABORTED) {
down(&(priv->hSemScanReq));
PRINT_D(CFG80211_DBG, "Scan Aborted\n");
if (priv->pstrScanReq != NULL) {
update_scan_time(priv);
refresh_scan(priv, 1, false);
cfg80211_scan_done(priv->pstrScanReq, false);
priv->bCfgScanning = false;
priv->pstrScanReq = NULL;
}
up(&(priv->hSemScanReq));
}
}
WILC_CATCH(s32Error)
{
}
}
int WILC_WFI_Set_PMKSA(u8 *bssid, struct WILC_WFI_priv *priv)
{
u32 i;
s32 s32Error = WILC_SUCCESS;
for (i = 0; i < priv->pmkid_list.numpmkid; i++) {
if (!memcmp(bssid, priv->pmkid_list.pmkidlist[i].bssid,
ETH_ALEN)) {
PRINT_D(CFG80211_DBG, "PMKID successful comparison");
s32Error = host_int_set_pmkid_info(priv->hWILCWFIDrv, &priv->pmkid_list);
if (s32Error != WILC_SUCCESS)
PRINT_ER("Error in pmkid\n");
break;
}
}
return s32Error;
}
static void CfgConnectResult(tenuConnDisconnEvent enuConnDisconnEvent,
tstrConnectInfo *pstrConnectInfo,
u8 u8MacStatus,
tstrDisconnectNotifInfo *pstrDisconnectNotifInfo,
void *pUserVoid)
{
struct WILC_WFI_priv *priv;
struct net_device *dev;
#ifdef WILC_P2P
tstrWILC_WFIDrv *pstrWFIDrv;
#endif
u8 NullBssid[ETH_ALEN] = {0};
connecting = 0;
priv = (struct WILC_WFI_priv *)pUserVoid;
dev = priv->dev;
#ifdef WILC_P2P
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
#endif
if (enuConnDisconnEvent == CONN_DISCONN_EVENT_CONN_RESP) {
u16 u16ConnectStatus = WLAN_STATUS_SUCCESS;
u16ConnectStatus = pstrConnectInfo->u16ConnectStatus;
PRINT_D(CFG80211_DBG, " Connection response received = %d\n", u8MacStatus);
if ((u8MacStatus == MAC_DISCONNECTED) &&
(pstrConnectInfo->u16ConnectStatus == SUCCESSFUL_STATUSCODE)) {
u16ConnectStatus = WLAN_STATUS_UNSPECIFIED_FAILURE;
linux_wlan_set_bssid(priv->dev, NullBssid);
memset(u8ConnectedSSID, 0, ETH_ALEN);
#ifdef WILC_P2P
if (!pstrWFIDrv->u8P2PConnect)
u8WLANChannel = INVALID_CHANNEL;
#endif
PRINT_ER("Unspecified failure: Connection status %d : MAC status = %d\n", u16ConnectStatus, u8MacStatus);
}
if (u16ConnectStatus == WLAN_STATUS_SUCCESS) {
bool bNeedScanRefresh = false;
u32 i;
PRINT_INFO(CFG80211_DBG, "Connection Successful:: BSSID: %x%x%x%x%x%x\n", pstrConnectInfo->au8bssid[0],
pstrConnectInfo->au8bssid[1], pstrConnectInfo->au8bssid[2], pstrConnectInfo->au8bssid[3], pstrConnectInfo->au8bssid[4], pstrConnectInfo->au8bssid[5]);
memcpy(priv->au8AssociatedBss, pstrConnectInfo->au8bssid, ETH_ALEN);
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
if (memcmp(astrLastScannedNtwrksShadow[i].au8bssid,
pstrConnectInfo->au8bssid, ETH_ALEN) == 0) {
unsigned long now = jiffies;
if (time_after(now,
astrLastScannedNtwrksShadow[i].u32TimeRcvdInScanCached + (unsigned long)(nl80211_SCAN_RESULT_EXPIRE - (1 * HZ)))) {
bNeedScanRefresh = true;
}
break;
}
}
if (bNeedScanRefresh) {
refresh_scan(priv, 1, true);
}
}
PRINT_D(CFG80211_DBG, "Association request info elements length = %zu\n", pstrConnectInfo->ReqIEsLen);
PRINT_D(CFG80211_DBG, "Association response info elements length = %d\n", pstrConnectInfo->u16RespIEsLen);
cfg80211_connect_result(dev, pstrConnectInfo->au8bssid,
pstrConnectInfo->pu8ReqIEs, pstrConnectInfo->ReqIEsLen,
pstrConnectInfo->pu8RespIEs, pstrConnectInfo->u16RespIEsLen,
u16ConnectStatus, GFP_KERNEL);
} else if (enuConnDisconnEvent == CONN_DISCONN_EVENT_DISCONN_NOTIF) {
#ifdef DISABLE_PWRSAVE_AND_SCAN_DURING_IP
g_obtainingIP = false;
#endif
PRINT_ER("Received MAC_DISCONNECTED from firmware with reason %d on dev [%p]\n",
pstrDisconnectNotifInfo->u16reason, priv->dev);
u8P2Plocalrandom = 0x01;
u8P2Precvrandom = 0x00;
bWilc_ie = false;
memset(priv->au8AssociatedBss, 0, ETH_ALEN);
linux_wlan_set_bssid(priv->dev, NullBssid);
memset(u8ConnectedSSID, 0, ETH_ALEN);
#ifdef WILC_P2P
if (!pstrWFIDrv->u8P2PConnect)
u8WLANChannel = INVALID_CHANNEL;
#endif
if ((pstrWFIDrv->IFC_UP) && (dev == g_linux_wlan->strInterfaceInfo[1].wilc_netdev)) {
pstrDisconnectNotifInfo->u16reason = 3;
}
else if ((!pstrWFIDrv->IFC_UP) && (dev == g_linux_wlan->strInterfaceInfo[1].wilc_netdev)) {
pstrDisconnectNotifInfo->u16reason = 1;
}
cfg80211_disconnected(dev, pstrDisconnectNotifInfo->u16reason, pstrDisconnectNotifInfo->ie,
pstrDisconnectNotifInfo->ie_len, false,
GFP_KERNEL);
}
}
static int WILC_WFI_CfgSetChannel(struct wiphy *wiphy,
struct cfg80211_chan_def *chandef)
{
u32 channelnum = 0;
struct WILC_WFI_priv *priv;
s32 s32Error = WILC_SUCCESS;
priv = wiphy_priv(wiphy);
channelnum = ieee80211_frequency_to_channel(chandef->chan->center_freq);
PRINT_D(CFG80211_DBG, "Setting channel %d with frequency %d\n", channelnum, chandef->chan->center_freq);
u8CurrChannel = channelnum;
s32Error = host_int_set_mac_chnl_num(priv->hWILCWFIDrv, channelnum);
if (s32Error != WILC_SUCCESS)
PRINT_ER("Error in setting channel %d\n", channelnum);
return s32Error;
}
static int WILC_WFI_CfgScan(struct wiphy *wiphy, struct cfg80211_scan_request *request)
{
struct WILC_WFI_priv *priv;
u32 i;
s32 s32Error = WILC_SUCCESS;
u8 au8ScanChanList[MAX_NUM_SCANNED_NETWORKS];
tstrHiddenNetwork strHiddenNetwork;
priv = wiphy_priv(wiphy);
priv->pstrScanReq = request;
priv->u32RcvdChCount = 0;
host_int_set_wfi_drv_handler(priv->hWILCWFIDrv);
reset_shadow_found(priv);
priv->bCfgScanning = true;
if (request->n_channels <= MAX_NUM_SCANNED_NETWORKS) {
for (i = 0; i < request->n_channels; i++) {
au8ScanChanList[i] = (u8)ieee80211_frequency_to_channel(request->channels[i]->center_freq);
PRINT_INFO(CFG80211_DBG, "ScanChannel List[%d] = %d,", i, au8ScanChanList[i]);
}
PRINT_D(CFG80211_DBG, "Requested num of scan channel %d\n", request->n_channels);
PRINT_D(CFG80211_DBG, "Scan Request IE len = %zu\n", request->ie_len);
PRINT_D(CFG80211_DBG, "Number of SSIDs %d\n", request->n_ssids);
if (request->n_ssids >= 1) {
strHiddenNetwork.pstrHiddenNetworkInfo = WILC_MALLOC(request->n_ssids * sizeof(tstrHiddenNetwork));
strHiddenNetwork.u8ssidnum = request->n_ssids;
for (i = 0; i < request->n_ssids; i++) {
if (request->ssids[i].ssid != NULL && request->ssids[i].ssid_len != 0) {
strHiddenNetwork.pstrHiddenNetworkInfo[i].pu8ssid = WILC_MALLOC(request->ssids[i].ssid_len);
memcpy(strHiddenNetwork.pstrHiddenNetworkInfo[i].pu8ssid, request->ssids[i].ssid, request->ssids[i].ssid_len);
strHiddenNetwork.pstrHiddenNetworkInfo[i].u8ssidlen = request->ssids[i].ssid_len;
} else {
PRINT_D(CFG80211_DBG, "Received one NULL SSID\n");
strHiddenNetwork.u8ssidnum -= 1;
}
}
PRINT_D(CFG80211_DBG, "Trigger Scan Request\n");
s32Error = host_int_scan(priv->hWILCWFIDrv, USER_SCAN, ACTIVE_SCAN,
au8ScanChanList, request->n_channels,
(const u8 *)request->ie, request->ie_len,
CfgScanResult, (void *)priv, &strHiddenNetwork);
} else {
PRINT_D(CFG80211_DBG, "Trigger Scan Request\n");
s32Error = host_int_scan(priv->hWILCWFIDrv, USER_SCAN, ACTIVE_SCAN,
au8ScanChanList, request->n_channels,
(const u8 *)request->ie, request->ie_len,
CfgScanResult, (void *)priv, NULL);
}
} else {
PRINT_ER("Requested num of scanned channels is greater than the max, supported"
" channels\n");
}
if (s32Error != WILC_SUCCESS) {
s32Error = -EBUSY;
PRINT_WRN(CFG80211_DBG, "Device is busy: Error(%d)\n", s32Error);
}
return s32Error;
}
static int WILC_WFI_CfgConnect(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_connect_params *sme)
{
s32 s32Error = WILC_SUCCESS;
u32 i;
u8 u8security = NO_ENCRYPT;
AUTHTYPE_T tenuAuth_type = ANY;
char *pcgroup_encrypt_val = NULL;
char *pccipher_group = NULL;
char *pcwpa_version = NULL;
struct WILC_WFI_priv *priv;
tstrWILC_WFIDrv *pstrWFIDrv;
tstrNetworkInfo *pstrNetworkInfo = NULL;
connecting = 1;
priv = wiphy_priv(wiphy);
pstrWFIDrv = (tstrWILC_WFIDrv *)(priv->hWILCWFIDrv);
host_int_set_wfi_drv_handler(priv->hWILCWFIDrv);
PRINT_D(CFG80211_DBG, "Connecting to SSID [%s] on netdev [%p] host if [%p]\n", sme->ssid, dev, priv->hWILCWFIDrv);
#ifdef WILC_P2P
if (!(strncmp(sme->ssid, "DIRECT-", 7))) {
PRINT_D(CFG80211_DBG, "Connected to Direct network,OBSS disabled\n");
pstrWFIDrv->u8P2PConnect = 1;
} else
pstrWFIDrv->u8P2PConnect = 0;
#endif
PRINT_INFO(CFG80211_DBG, "Required SSID = %s\n , AuthType = %d\n", sme->ssid, sme->auth_type);
for (i = 0; i < u32LastScannedNtwrksCountShadow; i++) {
if ((sme->ssid_len == astrLastScannedNtwrksShadow[i].u8SsidLen) &&
memcmp(astrLastScannedNtwrksShadow[i].au8ssid,
sme->ssid,
sme->ssid_len) == 0) {
PRINT_INFO(CFG80211_DBG, "Network with required SSID is found %s\n", sme->ssid);
if (sme->bssid == NULL) {
PRINT_INFO(CFG80211_DBG, "BSSID is not passed from the user\n");
break;
} else {
if (memcmp(astrLastScannedNtwrksShadow[i].au8bssid,
sme->bssid,
ETH_ALEN) == 0) {
PRINT_INFO(CFG80211_DBG, "BSSID is passed from the user and matched\n");
break;
}
}
}
}
if (i < u32LastScannedNtwrksCountShadow) {
PRINT_D(CFG80211_DBG, "Required bss is in scan results\n");
pstrNetworkInfo = &(astrLastScannedNtwrksShadow[i]);
PRINT_INFO(CFG80211_DBG, "network BSSID to be associated: %x%x%x%x%x%x\n",
pstrNetworkInfo->au8bssid[0], pstrNetworkInfo->au8bssid[1],
pstrNetworkInfo->au8bssid[2], pstrNetworkInfo->au8bssid[3],
pstrNetworkInfo->au8bssid[4], pstrNetworkInfo->au8bssid[5]);
} else {
s32Error = -ENOENT;
if (u32LastScannedNtwrksCountShadow == 0)
PRINT_D(CFG80211_DBG, "No Scan results yet\n");
else
PRINT_D(CFG80211_DBG, "Required bss not in scan results: Error(%d)\n", s32Error);
goto done;
}
priv->WILC_WFI_wep_default = 0;
memset(priv->WILC_WFI_wep_key, 0, sizeof(priv->WILC_WFI_wep_key));
memset(priv->WILC_WFI_wep_key_len, 0, sizeof(priv->WILC_WFI_wep_key_len));
PRINT_INFO(CFG80211_DBG, "sme->crypto.wpa_versions=%x\n", sme->crypto.wpa_versions);
PRINT_INFO(CFG80211_DBG, "sme->crypto.cipher_group=%x\n", sme->crypto.cipher_group);
PRINT_INFO(CFG80211_DBG, "sme->crypto.n_ciphers_pairwise=%d\n", sme->crypto.n_ciphers_pairwise);
if (INFO) {
for (i = 0; i < sme->crypto.n_ciphers_pairwise; i++)
PRINT_D(CORECONFIG_DBG, "sme->crypto.ciphers_pairwise[%d]=%x\n", i, sme->crypto.ciphers_pairwise[i]);
}
if (sme->crypto.cipher_group != NO_ENCRYPT) {
pcwpa_version = "Default";
PRINT_D(CORECONFIG_DBG, ">> sme->crypto.wpa_versions: %x\n", sme->crypto.wpa_versions);
if (sme->crypto.cipher_group == WLAN_CIPHER_SUITE_WEP40) {
u8security = ENCRYPT_ENABLED | WEP;
pcgroup_encrypt_val = "WEP40";
pccipher_group = "WLAN_CIPHER_SUITE_WEP40";
PRINT_INFO(CFG80211_DBG, "WEP Default Key Idx = %d\n", sme->key_idx);
if (INFO) {
for (i = 0; i < sme->key_len; i++)
PRINT_D(CORECONFIG_DBG, "WEP Key Value[%d] = %d\n", i, sme->key[i]);
}
priv->WILC_WFI_wep_default = sme->key_idx;
priv->WILC_WFI_wep_key_len[sme->key_idx] = sme->key_len;
memcpy(priv->WILC_WFI_wep_key[sme->key_idx], sme->key, sme->key_len);
g_key_wep_params.key_len = sme->key_len;
g_key_wep_params.key = WILC_MALLOC(sme->key_len);
memcpy(g_key_wep_params.key, sme->key, sme->key_len);
g_key_wep_params.key_idx = sme->key_idx;
g_wep_keys_saved = true;
host_int_set_WEPDefaultKeyID(priv->hWILCWFIDrv, sme->key_idx);
host_int_add_wep_key_bss_sta(priv->hWILCWFIDrv, sme->key, sme->key_len, sme->key_idx);
} else if (sme->crypto.cipher_group == WLAN_CIPHER_SUITE_WEP104) {
u8security = ENCRYPT_ENABLED | WEP | WEP_EXTENDED;
pcgroup_encrypt_val = "WEP104";
pccipher_group = "WLAN_CIPHER_SUITE_WEP104";
priv->WILC_WFI_wep_default = sme->key_idx;
priv->WILC_WFI_wep_key_len[sme->key_idx] = sme->key_len;
memcpy(priv->WILC_WFI_wep_key[sme->key_idx], sme->key, sme->key_len);
g_key_wep_params.key_len = sme->key_len;
g_key_wep_params.key = WILC_MALLOC(sme->key_len);
memcpy(g_key_wep_params.key, sme->key, sme->key_len);
g_key_wep_params.key_idx = sme->key_idx;
g_wep_keys_saved = true;
host_int_set_WEPDefaultKeyID(priv->hWILCWFIDrv, sme->key_idx);
host_int_add_wep_key_bss_sta(priv->hWILCWFIDrv, sme->key, sme->key_len, sme->key_idx);
} else if (sme->crypto.wpa_versions & NL80211_WPA_VERSION_2) {
if (sme->crypto.cipher_group == WLAN_CIPHER_SUITE_TKIP) {
u8security = ENCRYPT_ENABLED | WPA2 | TKIP;
pcgroup_encrypt_val = "WPA2_TKIP";
pccipher_group = "TKIP";
} else {
u8security = ENCRYPT_ENABLED | WPA2 | AES;
pcgroup_encrypt_val = "WPA2_AES";
pccipher_group = "AES";
}
pcwpa_version = "WPA_VERSION_2";
} else if (sme->crypto.wpa_versions & NL80211_WPA_VERSION_1) {
if (sme->crypto.cipher_group == WLAN_CIPHER_SUITE_TKIP) {
u8security = ENCRYPT_ENABLED | WPA | TKIP;
pcgroup_encrypt_val = "WPA_TKIP";
pccipher_group = "TKIP";
} else {
u8security = ENCRYPT_ENABLED | WPA | AES;
pcgroup_encrypt_val = "WPA_AES";
pccipher_group = "AES";
}
pcwpa_version = "WPA_VERSION_1";
} else {
s32Error = -ENOTSUPP;
PRINT_ER("Not supported cipher: Error(%d)\n", s32Error);
goto done;
}
}
if ((sme->crypto.wpa_versions & NL80211_WPA_VERSION_1)
|| (sme->crypto.wpa_versions & NL80211_WPA_VERSION_2)) {
for (i = 0; i < sme->crypto.n_ciphers_pairwise; i++) {
if (sme->crypto.ciphers_pairwise[i] == WLAN_CIPHER_SUITE_TKIP) {
u8security = u8security | TKIP;
} else {
u8security = u8security | AES;
}
}
}
PRINT_D(CFG80211_DBG, "Adding key with cipher group = %x\n", sme->crypto.cipher_group);
PRINT_D(CFG80211_DBG, "Authentication Type = %d\n", sme->auth_type);
switch (sme->auth_type) {
case NL80211_AUTHTYPE_OPEN_SYSTEM:
PRINT_D(CFG80211_DBG, "In OPEN SYSTEM\n");
tenuAuth_type = OPEN_SYSTEM;
break;
case NL80211_AUTHTYPE_SHARED_KEY:
tenuAuth_type = SHARED_KEY;
PRINT_D(CFG80211_DBG, "In SHARED KEY\n");
break;
default:
PRINT_D(CFG80211_DBG, "Automatic Authentation type = %d\n", sme->auth_type);
}
if (sme->crypto.n_akm_suites) {
switch (sme->crypto.akm_suites[0]) {
case WLAN_AKM_SUITE_8021X:
tenuAuth_type = IEEE8021;
break;
default:
break;
}
}
PRINT_INFO(CFG80211_DBG, "Required Channel = %d\n", pstrNetworkInfo->u8channel);
PRINT_INFO(CFG80211_DBG, "Group encryption value = %s\n Cipher Group = %s\n WPA version = %s\n",
pcgroup_encrypt_val, pccipher_group, pcwpa_version);
u8CurrChannel = pstrNetworkInfo->u8channel;
if (!pstrWFIDrv->u8P2PConnect) {
u8WLANChannel = pstrNetworkInfo->u8channel;
}
linux_wlan_set_bssid(dev, pstrNetworkInfo->au8bssid);
s32Error = host_int_set_join_req(priv->hWILCWFIDrv, pstrNetworkInfo->au8bssid, sme->ssid,
sme->ssid_len, sme->ie, sme->ie_len,
CfgConnectResult, (void *)priv, u8security,
tenuAuth_type, pstrNetworkInfo->u8channel,
pstrNetworkInfo->pJoinParams);
if (s32Error != WILC_SUCCESS) {
PRINT_ER("host_int_set_join_req(): Error(%d)\n", s32Error);
s32Error = -ENOENT;
goto done;
}
done:
return s32Error;
}
static int WILC_WFI_disconnect(struct wiphy *wiphy, struct net_device *dev, u16 reason_code)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
#ifdef WILC_P2P
tstrWILC_WFIDrv *pstrWFIDrv;
#endif
uint8_t NullBssid[ETH_ALEN] = {0};
connecting = 0;
priv = wiphy_priv(wiphy);
#ifdef WILC_P2P
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
if (!pstrWFIDrv->u8P2PConnect)
u8WLANChannel = INVALID_CHANNEL;
#endif
linux_wlan_set_bssid(priv->dev, NullBssid);
PRINT_D(CFG80211_DBG, "Disconnecting with reason code(%d)\n", reason_code);
u8P2Plocalrandom = 0x01;
u8P2Precvrandom = 0x00;
bWilc_ie = false;
#ifdef WILC_P2P
pstrWFIDrv->u64P2p_MgmtTimeout = 0;
#endif
s32Error = host_int_disconnect(priv->hWILCWFIDrv, reason_code);
if (s32Error != WILC_SUCCESS) {
PRINT_ER("Error in disconnecting: Error(%d)\n", s32Error);
s32Error = -EINVAL;
}
return s32Error;
}
static int WILC_WFI_add_key(struct wiphy *wiphy, struct net_device *netdev, u8 key_index,
bool pairwise,
const u8 *mac_addr, struct key_params *params)
{
s32 s32Error = WILC_SUCCESS, KeyLen = params->key_len;
u32 i;
struct WILC_WFI_priv *priv;
const u8 *pu8RxMic = NULL;
const u8 *pu8TxMic = NULL;
u8 u8mode = NO_ENCRYPT;
#ifdef WILC_AP_EXTERNAL_MLME
u8 u8gmode = NO_ENCRYPT;
u8 u8pmode = NO_ENCRYPT;
AUTHTYPE_T tenuAuth_type = ANY;
#endif
priv = wiphy_priv(wiphy);
PRINT_D(CFG80211_DBG, "Adding key with cipher suite = %x\n", params->cipher);
PRINT_D(CFG80211_DBG, "%p %p %d\n", wiphy, netdev, key_index);
PRINT_D(CFG80211_DBG, "key %x %x %x\n", params->key[0],
params->key[1],
params->key[2]);
switch (params->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
#ifdef WILC_AP_EXTERNAL_MLME
if (priv->wdev->iftype == NL80211_IFTYPE_AP) {
priv->WILC_WFI_wep_default = key_index;
priv->WILC_WFI_wep_key_len[key_index] = params->key_len;
memcpy(priv->WILC_WFI_wep_key[key_index], params->key, params->key_len);
PRINT_D(CFG80211_DBG, "Adding AP WEP Default key Idx = %d\n", key_index);
PRINT_D(CFG80211_DBG, "Adding AP WEP Key len= %d\n", params->key_len);
for (i = 0; i < params->key_len; i++)
PRINT_D(CFG80211_DBG, "WEP AP key val[%d] = %x\n", i, params->key[i]);
tenuAuth_type = OPEN_SYSTEM;
if (params->cipher == WLAN_CIPHER_SUITE_WEP40)
u8mode = ENCRYPT_ENABLED | WEP;
else
u8mode = ENCRYPT_ENABLED | WEP | WEP_EXTENDED;
host_int_add_wep_key_bss_ap(priv->hWILCWFIDrv, params->key, params->key_len, key_index, u8mode, tenuAuth_type);
break;
}
#endif
if (memcmp(params->key, priv->WILC_WFI_wep_key[key_index], params->key_len)) {
priv->WILC_WFI_wep_default = key_index;
priv->WILC_WFI_wep_key_len[key_index] = params->key_len;
memcpy(priv->WILC_WFI_wep_key[key_index], params->key, params->key_len);
PRINT_D(CFG80211_DBG, "Adding WEP Default key Idx = %d\n", key_index);
PRINT_D(CFG80211_DBG, "Adding WEP Key length = %d\n", params->key_len);
if (INFO) {
for (i = 0; i < params->key_len; i++)
PRINT_INFO(CFG80211_DBG, "WEP key value[%d] = %d\n", i, params->key[i]);
}
host_int_add_wep_key_bss_sta(priv->hWILCWFIDrv, params->key, params->key_len, key_index);
}
break;
case WLAN_CIPHER_SUITE_TKIP:
case WLAN_CIPHER_SUITE_CCMP:
#ifdef WILC_AP_EXTERNAL_MLME
if (priv->wdev->iftype == NL80211_IFTYPE_AP || priv->wdev->iftype == NL80211_IFTYPE_P2P_GO) {
if (priv->wilc_gtk[key_index] == NULL) {
priv->wilc_gtk[key_index] = WILC_MALLOC(sizeof(struct wilc_wfi_key));
priv->wilc_gtk[key_index]->key = NULL;
priv->wilc_gtk[key_index]->seq = NULL;
}
if (priv->wilc_ptk[key_index] == NULL) {
priv->wilc_ptk[key_index] = WILC_MALLOC(sizeof(struct wilc_wfi_key));
priv->wilc_ptk[key_index]->key = NULL;
priv->wilc_ptk[key_index]->seq = NULL;
}
if (!pairwise) {
if (params->cipher == WLAN_CIPHER_SUITE_TKIP)
u8gmode = ENCRYPT_ENABLED | WPA | TKIP;
else
u8gmode = ENCRYPT_ENABLED | WPA2 | AES;
priv->wilc_groupkey = u8gmode;
if (params->key_len > 16 && params->cipher == WLAN_CIPHER_SUITE_TKIP) {
pu8TxMic = params->key + 24;
pu8RxMic = params->key + 16;
KeyLen = params->key_len - 16;
}
if (priv->wilc_gtk[key_index]->key)
kfree(priv->wilc_gtk[key_index]->key);
priv->wilc_gtk[key_index]->key = WILC_MALLOC(params->key_len);
memcpy(priv->wilc_gtk[key_index]->key, params->key, params->key_len);
if (priv->wilc_gtk[key_index]->seq)
kfree(priv->wilc_gtk[key_index]->seq);
if ((params->seq_len) > 0) {
priv->wilc_gtk[key_index]->seq = WILC_MALLOC(params->seq_len);
memcpy(priv->wilc_gtk[key_index]->seq, params->seq, params->seq_len);
}
priv->wilc_gtk[key_index]->cipher = params->cipher;
priv->wilc_gtk[key_index]->key_len = params->key_len;
priv->wilc_gtk[key_index]->seq_len = params->seq_len;
if (INFO) {
for (i = 0; i < params->key_len; i++)
PRINT_INFO(CFG80211_DBG, "Adding group key value[%d] = %x\n", i, params->key[i]);
for (i = 0; i < params->seq_len; i++)
PRINT_INFO(CFG80211_DBG, "Adding group seq value[%d] = %x\n", i, params->seq[i]);
}
host_int_add_rx_gtk(priv->hWILCWFIDrv, params->key, KeyLen,
key_index, params->seq_len, params->seq, pu8RxMic, pu8TxMic, AP_MODE, u8gmode);
} else {
PRINT_INFO(CFG80211_DBG, "STA Address: %x%x%x%x%x\n", mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4]);
if (params->cipher == WLAN_CIPHER_SUITE_TKIP)
u8pmode = ENCRYPT_ENABLED | WPA | TKIP;
else
u8pmode = priv->wilc_groupkey | AES;
if (params->key_len > 16 && params->cipher == WLAN_CIPHER_SUITE_TKIP) {
pu8TxMic = params->key + 24;
pu8RxMic = params->key + 16;
KeyLen = params->key_len - 16;
}
if (priv->wilc_ptk[key_index]->key)
kfree(priv->wilc_ptk[key_index]->key);
priv->wilc_ptk[key_index]->key = WILC_MALLOC(params->key_len);
if (priv->wilc_ptk[key_index]->seq)
kfree(priv->wilc_ptk[key_index]->seq);
if ((params->seq_len) > 0)
priv->wilc_ptk[key_index]->seq = WILC_MALLOC(params->seq_len);
if (INFO) {
for (i = 0; i < params->key_len; i++)
PRINT_INFO(CFG80211_DBG, "Adding pairwise key value[%d] = %x\n", i, params->key[i]);
for (i = 0; i < params->seq_len; i++)
PRINT_INFO(CFG80211_DBG, "Adding group seq value[%d] = %x\n", i, params->seq[i]);
}
memcpy(priv->wilc_ptk[key_index]->key, params->key, params->key_len);
if ((params->seq_len) > 0)
memcpy(priv->wilc_ptk[key_index]->seq, params->seq, params->seq_len);
priv->wilc_ptk[key_index]->cipher = params->cipher;
priv->wilc_ptk[key_index]->key_len = params->key_len;
priv->wilc_ptk[key_index]->seq_len = params->seq_len;
host_int_add_ptk(priv->hWILCWFIDrv, params->key, KeyLen, mac_addr,
pu8RxMic, pu8TxMic, AP_MODE, u8pmode, key_index);
}
break;
}
#endif
{
u8mode = 0;
if (!pairwise) {
if (params->key_len > 16 && params->cipher == WLAN_CIPHER_SUITE_TKIP) {
pu8RxMic = params->key + 24;
pu8TxMic = params->key + 16;
KeyLen = params->key_len - 16;
}
if (!g_gtk_keys_saved && netdev == g_linux_wlan->strInterfaceInfo[0].wilc_netdev) {
g_add_gtk_key_params.key_idx = key_index;
g_add_gtk_key_params.pairwise = pairwise;
if (!mac_addr) {
g_add_gtk_key_params.mac_addr = NULL;
} else {
g_add_gtk_key_params.mac_addr = WILC_MALLOC(ETH_ALEN);
memcpy(g_add_gtk_key_params.mac_addr, mac_addr, ETH_ALEN);
}
g_key_gtk_params.key_len = params->key_len;
g_key_gtk_params.seq_len = params->seq_len;
g_key_gtk_params.key = WILC_MALLOC(params->key_len);
memcpy(g_key_gtk_params.key, params->key, params->key_len);
if (params->seq_len > 0) {
g_key_gtk_params.seq = WILC_MALLOC(params->seq_len);
memcpy(g_key_gtk_params.seq, params->seq, params->seq_len);
}
g_key_gtk_params.cipher = params->cipher;
PRINT_D(CFG80211_DBG, "key %x %x %x\n", g_key_gtk_params.key[0],
g_key_gtk_params.key[1],
g_key_gtk_params.key[2]);
g_gtk_keys_saved = true;
}
host_int_add_rx_gtk(priv->hWILCWFIDrv, params->key, KeyLen,
key_index, params->seq_len, params->seq, pu8RxMic, pu8TxMic, STATION_MODE, u8mode);
} else {
if (params->key_len > 16 && params->cipher == WLAN_CIPHER_SUITE_TKIP) {
pu8RxMic = params->key + 24;
pu8TxMic = params->key + 16;
KeyLen = params->key_len - 16;
}
if (!g_ptk_keys_saved && netdev == g_linux_wlan->strInterfaceInfo[0].wilc_netdev) {
g_add_ptk_key_params.key_idx = key_index;
g_add_ptk_key_params.pairwise = pairwise;
if (!mac_addr) {
g_add_ptk_key_params.mac_addr = NULL;
} else {
g_add_ptk_key_params.mac_addr = WILC_MALLOC(ETH_ALEN);
memcpy(g_add_ptk_key_params.mac_addr, mac_addr, ETH_ALEN);
}
g_key_ptk_params.key_len = params->key_len;
g_key_ptk_params.seq_len = params->seq_len;
g_key_ptk_params.key = WILC_MALLOC(params->key_len);
memcpy(g_key_ptk_params.key, params->key, params->key_len);
if (params->seq_len > 0) {
g_key_ptk_params.seq = WILC_MALLOC(params->seq_len);
memcpy(g_key_ptk_params.seq, params->seq, params->seq_len);
}
g_key_ptk_params.cipher = params->cipher;
PRINT_D(CFG80211_DBG, "key %x %x %x\n", g_key_ptk_params.key[0],
g_key_ptk_params.key[1],
g_key_ptk_params.key[2]);
g_ptk_keys_saved = true;
}
host_int_add_ptk(priv->hWILCWFIDrv, params->key, KeyLen, mac_addr,
pu8RxMic, pu8TxMic, STATION_MODE, u8mode, key_index);
PRINT_D(CFG80211_DBG, "Adding pairwise key\n");
if (INFO) {
for (i = 0; i < params->key_len; i++)
PRINT_INFO(CFG80211_DBG, "Adding pairwise key value[%d] = %d\n", i, params->key[i]);
}
}
}
break;
default:
PRINT_ER("Not supported cipher: Error(%d)\n", s32Error);
s32Error = -ENOTSUPP;
}
return s32Error;
}
static int WILC_WFI_del_key(struct wiphy *wiphy, struct net_device *netdev,
u8 key_index,
bool pairwise,
const u8 *mac_addr)
{
struct WILC_WFI_priv *priv;
s32 s32Error = WILC_SUCCESS;
priv = wiphy_priv(wiphy);
if (netdev == g_linux_wlan->strInterfaceInfo[0].wilc_netdev) {
g_ptk_keys_saved = false;
g_gtk_keys_saved = false;
g_wep_keys_saved = false;
if (g_key_wep_params.key != NULL) {
kfree(g_key_wep_params.key);
g_key_wep_params.key = NULL;
}
#ifdef WILC_AP_EXTERNAL_MLME
if ((priv->wilc_gtk[key_index]) != NULL) {
if (priv->wilc_gtk[key_index]->key != NULL) {
kfree(priv->wilc_gtk[key_index]->key);
priv->wilc_gtk[key_index]->key = NULL;
}
if (priv->wilc_gtk[key_index]->seq) {
kfree(priv->wilc_gtk[key_index]->seq);
priv->wilc_gtk[key_index]->seq = NULL;
}
kfree(priv->wilc_gtk[key_index]);
priv->wilc_gtk[key_index] = NULL;
}
if ((priv->wilc_ptk[key_index]) != NULL) {
if (priv->wilc_ptk[key_index]->key) {
kfree(priv->wilc_ptk[key_index]->key);
priv->wilc_ptk[key_index]->key = NULL;
}
if (priv->wilc_ptk[key_index]->seq) {
kfree(priv->wilc_ptk[key_index]->seq);
priv->wilc_ptk[key_index]->seq = NULL;
}
kfree(priv->wilc_ptk[key_index]);
priv->wilc_ptk[key_index] = NULL;
}
#endif
if (g_key_ptk_params.key != NULL) {
kfree(g_key_ptk_params.key);
g_key_ptk_params.key = NULL;
}
if (g_key_ptk_params.seq != NULL) {
kfree(g_key_ptk_params.seq);
g_key_ptk_params.seq = NULL;
}
if (g_key_gtk_params.key != NULL) {
kfree(g_key_gtk_params.key);
g_key_gtk_params.key = NULL;
}
if (g_key_gtk_params.seq != NULL) {
kfree(g_key_gtk_params.seq);
g_key_gtk_params.seq = NULL;
}
Set_machw_change_vir_if(false);
}
if (key_index >= 0 && key_index <= 3) {
memset(priv->WILC_WFI_wep_key[key_index], 0, priv->WILC_WFI_wep_key_len[key_index]);
priv->WILC_WFI_wep_key_len[key_index] = 0;
PRINT_D(CFG80211_DBG, "Removing WEP key with index = %d\n", key_index);
host_int_remove_wep_key(priv->hWILCWFIDrv, key_index);
} else {
PRINT_D(CFG80211_DBG, "Removing all installed keys\n");
host_int_remove_key(priv->hWILCWFIDrv, mac_addr);
}
return s32Error;
}
static int WILC_WFI_get_key(struct wiphy *wiphy, struct net_device *netdev, u8 key_index,
bool pairwise,
const u8 *mac_addr, void *cookie, void (*callback)(void *cookie, struct key_params *))
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
struct key_params key_params;
u32 i;
priv = wiphy_priv(wiphy);
if (!pairwise)
{
PRINT_D(CFG80211_DBG, "Getting group key idx: %x\n", key_index);
key_params.key = priv->wilc_gtk[key_index]->key;
key_params.cipher = priv->wilc_gtk[key_index]->cipher;
key_params.key_len = priv->wilc_gtk[key_index]->key_len;
key_params.seq = priv->wilc_gtk[key_index]->seq;
key_params.seq_len = priv->wilc_gtk[key_index]->seq_len;
if (INFO) {
for (i = 0; i < key_params.key_len; i++)
PRINT_INFO(CFG80211_DBG, "Retrieved key value %x\n", key_params.key[i]);
}
} else {
PRINT_D(CFG80211_DBG, "Getting pairwise key\n");
key_params.key = priv->wilc_ptk[key_index]->key;
key_params.cipher = priv->wilc_ptk[key_index]->cipher;
key_params.key_len = priv->wilc_ptk[key_index]->key_len;
key_params.seq = priv->wilc_ptk[key_index]->seq;
key_params.seq_len = priv->wilc_ptk[key_index]->seq_len;
}
callback(cookie, &key_params);
return s32Error;
}
static int WILC_WFI_set_default_key(struct wiphy *wiphy, struct net_device *netdev, u8 key_index,
bool unicast, bool multicast)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
priv = wiphy_priv(wiphy);
PRINT_D(CFG80211_DBG, "Setting default key with idx = %d\n", key_index);
if (key_index != priv->WILC_WFI_wep_default) {
host_int_set_WEPDefaultKeyID(priv->hWILCWFIDrv, key_index);
}
return s32Error;
}
static int WILC_WFI_dump_survey(struct wiphy *wiphy, struct net_device *netdev,
int idx, struct survey_info *info)
{
s32 s32Error = WILC_SUCCESS;
if (idx != 0) {
s32Error = -ENOENT;
PRINT_ER("Error Idx value doesn't equal zero: Error(%d)\n", s32Error);
}
return s32Error;
}
static int WILC_WFI_get_station(struct wiphy *wiphy, struct net_device *dev,
const u8 *mac, struct station_info *sinfo)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
perInterface_wlan_t *nic;
#ifdef WILC_AP_EXTERNAL_MLME
u32 i = 0;
u32 associatedsta = 0;
u32 inactive_time = 0;
#endif
priv = wiphy_priv(wiphy);
nic = netdev_priv(dev);
#ifdef WILC_AP_EXTERNAL_MLME
if (nic->iftype == AP_MODE || nic->iftype == GO_MODE) {
PRINT_D(HOSTAPD_DBG, "Getting station parameters\n");
PRINT_INFO(HOSTAPD_DBG, ": %x%x%x%x%x\n", mac[0], mac[1], mac[2], mac[3], mac[4]);
for (i = 0; i < NUM_STA_ASSOCIATED; i++) {
if (!(memcmp(mac, priv->assoc_stainfo.au8Sta_AssociatedBss[i], ETH_ALEN))) {
associatedsta = i;
break;
}
}
if (associatedsta == -1) {
s32Error = -ENOENT;
PRINT_ER("Station required is not associated : Error(%d)\n", s32Error);
return s32Error;
}
sinfo->filled |= BIT(NL80211_STA_INFO_INACTIVE_TIME);
host_int_get_inactive_time(priv->hWILCWFIDrv, mac, &(inactive_time));
sinfo->inactive_time = 1000 * inactive_time;
PRINT_D(CFG80211_DBG, "Inactive time %d\n", sinfo->inactive_time);
}
#endif
if (nic->iftype == STATION_MODE) {
tstrStatistics strStatistics;
host_int_get_statistics(priv->hWILCWFIDrv, &strStatistics);
sinfo->filled |= BIT(NL80211_STA_INFO_SIGNAL) |
BIT(NL80211_STA_INFO_RX_PACKETS) |
BIT(NL80211_STA_INFO_TX_PACKETS) |
BIT(NL80211_STA_INFO_TX_FAILED) |
BIT(NL80211_STA_INFO_TX_BITRATE);
sinfo->signal = strStatistics.s8RSSI;
sinfo->rx_packets = strStatistics.u32RxCount;
sinfo->tx_packets = strStatistics.u32TxCount + strStatistics.u32TxFailureCount;
sinfo->tx_failed = strStatistics.u32TxFailureCount;
sinfo->txrate.legacy = strStatistics.u8LinkSpeed * 10;
#ifdef TCP_ENHANCEMENTS
if ((strStatistics.u8LinkSpeed > TCP_ACK_FILTER_LINK_SPEED_THRESH) && (strStatistics.u8LinkSpeed != DEFAULT_LINK_SPEED))
Enable_TCP_ACK_Filter(true);
else if (strStatistics.u8LinkSpeed != DEFAULT_LINK_SPEED)
Enable_TCP_ACK_Filter(false);
#endif
PRINT_D(CORECONFIG_DBG, "*** stats[%d][%d][%d][%d][%d]\n", sinfo->signal, sinfo->rx_packets, sinfo->tx_packets,
sinfo->tx_failed, sinfo->txrate.legacy);
}
return s32Error;
}
static int WILC_WFI_change_bss(struct wiphy *wiphy, struct net_device *dev,
struct bss_parameters *params)
{
PRINT_D(CFG80211_DBG, "Changing Bss parametrs\n");
return 0;
}
static int WILC_WFI_auth(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_auth_request *req)
{
PRINT_D(CFG80211_DBG, "In Authentication Function\n");
return 0;
}
static int WILC_WFI_assoc(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_assoc_request *req)
{
PRINT_D(CFG80211_DBG, "In Association Function\n");
return 0;
}
static int WILC_WFI_deauth(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_deauth_request *req, void *cookie)
{
PRINT_D(CFG80211_DBG, "In De-authentication Function\n");
return 0;
}
static int WILC_WFI_disassoc(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_disassoc_request *req, void *cookie)
{
PRINT_D(CFG80211_DBG, "In Disassociation Function\n");
return 0;
}
static int WILC_WFI_set_wiphy_params(struct wiphy *wiphy, u32 changed)
{
s32 s32Error = WILC_SUCCESS;
tstrCfgParamVal pstrCfgParamVal;
struct WILC_WFI_priv *priv;
priv = wiphy_priv(wiphy);
pstrCfgParamVal.u32SetCfgFlag = 0;
PRINT_D(CFG80211_DBG, "Setting Wiphy params\n");
if (changed & WIPHY_PARAM_RETRY_SHORT) {
PRINT_D(CFG80211_DBG, "Setting WIPHY_PARAM_RETRY_SHORT %d\n",
priv->dev->ieee80211_ptr->wiphy->retry_short);
pstrCfgParamVal.u32SetCfgFlag |= RETRY_SHORT;
pstrCfgParamVal.short_retry_limit = priv->dev->ieee80211_ptr->wiphy->retry_short;
}
if (changed & WIPHY_PARAM_RETRY_LONG) {
PRINT_D(CFG80211_DBG, "Setting WIPHY_PARAM_RETRY_LONG %d\n", priv->dev->ieee80211_ptr->wiphy->retry_long);
pstrCfgParamVal.u32SetCfgFlag |= RETRY_LONG;
pstrCfgParamVal.long_retry_limit = priv->dev->ieee80211_ptr->wiphy->retry_long;
}
if (changed & WIPHY_PARAM_FRAG_THRESHOLD) {
PRINT_D(CFG80211_DBG, "Setting WIPHY_PARAM_FRAG_THRESHOLD %d\n", priv->dev->ieee80211_ptr->wiphy->frag_threshold);
pstrCfgParamVal.u32SetCfgFlag |= FRAG_THRESHOLD;
pstrCfgParamVal.frag_threshold = priv->dev->ieee80211_ptr->wiphy->frag_threshold;
}
if (changed & WIPHY_PARAM_RTS_THRESHOLD) {
PRINT_D(CFG80211_DBG, "Setting WIPHY_PARAM_RTS_THRESHOLD %d\n", priv->dev->ieee80211_ptr->wiphy->rts_threshold);
pstrCfgParamVal.u32SetCfgFlag |= RTS_THRESHOLD;
pstrCfgParamVal.rts_threshold = priv->dev->ieee80211_ptr->wiphy->rts_threshold;
}
PRINT_D(CFG80211_DBG, "Setting CFG params in the host interface\n");
s32Error = hif_set_cfg(priv->hWILCWFIDrv, &pstrCfgParamVal);
if (s32Error)
PRINT_ER("Error in setting WIPHY PARAMS\n");
return s32Error;
}
static int WILC_WFI_set_bitrate_mask(struct wiphy *wiphy,
struct net_device *dev, const u8 *peer,
const struct cfg80211_bitrate_mask *mask)
{
s32 s32Error = WILC_SUCCESS;
PRINT_D(CFG80211_DBG, "Setting Bitrate mask function\n");
return s32Error;
}
static int WILC_WFI_set_pmksa(struct wiphy *wiphy, struct net_device *netdev,
struct cfg80211_pmksa *pmksa)
{
u32 i;
s32 s32Error = WILC_SUCCESS;
u8 flag = 0;
struct WILC_WFI_priv *priv = wiphy_priv(wiphy);
PRINT_D(CFG80211_DBG, "Setting PMKSA\n");
for (i = 0; i < priv->pmkid_list.numpmkid; i++) {
if (!memcmp(pmksa->bssid, priv->pmkid_list.pmkidlist[i].bssid,
ETH_ALEN)) {
flag = PMKID_FOUND;
PRINT_D(CFG80211_DBG, "PMKID already exists\n");
break;
}
}
if (i < WILC_MAX_NUM_PMKIDS) {
PRINT_D(CFG80211_DBG, "Setting PMKID in private structure\n");
memcpy(priv->pmkid_list.pmkidlist[i].bssid, pmksa->bssid,
ETH_ALEN);
memcpy(priv->pmkid_list.pmkidlist[i].pmkid, pmksa->pmkid,
PMKID_LEN);
if (!(flag == PMKID_FOUND))
priv->pmkid_list.numpmkid++;
} else {
PRINT_ER("Invalid PMKID index\n");
s32Error = -EINVAL;
}
if (!s32Error) {
PRINT_D(CFG80211_DBG, "Setting pmkid in the host interface\n");
s32Error = host_int_set_pmkid_info(priv->hWILCWFIDrv, &priv->pmkid_list);
}
return s32Error;
}
static int WILC_WFI_del_pmksa(struct wiphy *wiphy, struct net_device *netdev,
struct cfg80211_pmksa *pmksa)
{
u32 i;
u8 flag = 0;
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv = wiphy_priv(wiphy);
PRINT_D(CFG80211_DBG, "Deleting PMKSA keys\n");
for (i = 0; i < priv->pmkid_list.numpmkid; i++) {
if (!memcmp(pmksa->bssid, priv->pmkid_list.pmkidlist[i].bssid,
ETH_ALEN)) {
PRINT_D(CFG80211_DBG, "Reseting PMKID values\n");
memset(&priv->pmkid_list.pmkidlist[i], 0, sizeof(tstrHostIFpmkid));
flag = PMKID_FOUND;
break;
}
}
if (i < priv->pmkid_list.numpmkid && priv->pmkid_list.numpmkid > 0) {
for (; i < (priv->pmkid_list.numpmkid - 1); i++) {
memcpy(priv->pmkid_list.pmkidlist[i].bssid,
priv->pmkid_list.pmkidlist[i + 1].bssid,
ETH_ALEN);
memcpy(priv->pmkid_list.pmkidlist[i].pmkid,
priv->pmkid_list.pmkidlist[i].pmkid,
PMKID_LEN);
}
priv->pmkid_list.numpmkid--;
} else {
s32Error = -EINVAL;
}
return s32Error;
}
static int WILC_WFI_flush_pmksa(struct wiphy *wiphy, struct net_device *netdev)
{
struct WILC_WFI_priv *priv = wiphy_priv(wiphy);
PRINT_D(CFG80211_DBG, "Flushing PMKID key values\n");
memset(&priv->pmkid_list, 0, sizeof(tstrHostIFpmkidAttr));
return 0;
}
void WILC_WFI_CfgParseRxAction(u8 *buf, u32 len)
{
u32 index = 0;
u32 i = 0, j = 0;
#ifdef USE_SUPPLICANT_GO_INTENT
u8 intent;
u8 tie_breaker;
bool is_wilc_go = true;
#endif
u8 op_channel_attr_index = 0;
u8 channel_list_attr_index = 0;
while (index < len) {
if (buf[index] == GO_INTENT_ATTR_ID) {
#ifdef USE_SUPPLICANT_GO_INTENT
intent = GET_GO_INTENT(buf[index + 3]);
tie_breaker = GET_TIE_BREAKER(buf[index + 3]);
if (intent > SUPPLICANT_GO_INTENT
|| (intent == SUPPLICANT_GO_INTENT && tie_breaker == 1)) {
PRINT_D(GENERIC_DBG, "WILC will be client (intent %d tie breaker %d)\n", intent, tie_breaker);
is_wilc_go = false;
} else {
PRINT_D(GENERIC_DBG, "WILC will be GO (intent %d tie breaker %d)\n", intent, tie_breaker);
is_wilc_go = true;
}
#else
#ifdef FORCE_P2P_CLIENT
buf[index + 3] = (buf[index + 3] & 0x01) | (0x0f << 1);
#else
buf[index + 3] = (buf[index + 3] & 0x01) | (0x00 << 1);
#endif
#endif
}
#ifdef USE_SUPPLICANT_GO_INTENT
if (buf[index] == GROUP_BSSID_ATTR_ID) {
PRINT_D(GENERIC_DBG, "Group BSSID: %2x:%2x:%2x\n", buf[index + 3]
, buf[index + 4]
, buf[index + 5]);
is_wilc_go = false;
}
#endif
if (buf[index] == CHANLIST_ATTR_ID)
channel_list_attr_index = index;
else if (buf[index] == OPERCHAN_ATTR_ID)
op_channel_attr_index = index;
index += buf[index + 1] + 3;
}
#ifdef USE_SUPPLICANT_GO_INTENT
if (u8WLANChannel != INVALID_CHANNEL && is_wilc_go)
#else
if (u8WLANChannel != INVALID_CHANNEL)
#endif
{
if (channel_list_attr_index) {
PRINT_D(GENERIC_DBG, "Modify channel list attribute\n");
for (i = channel_list_attr_index + 3; i < ((channel_list_attr_index + 3) + buf[channel_list_attr_index + 1]); i++) {
if (buf[i] == 0x51) {
for (j = i + 2; j < ((i + 2) + buf[i + 1]); j++) {
buf[j] = u8WLANChannel;
}
break;
}
}
}
if (op_channel_attr_index) {
PRINT_D(GENERIC_DBG, "Modify operating channel attribute\n");
buf[op_channel_attr_index + 6] = 0x51;
buf[op_channel_attr_index + 7] = u8WLANChannel;
}
}
}
void WILC_WFI_CfgParseTxAction(u8 *buf, u32 len, bool bOperChan, u8 iftype)
{
u32 index = 0;
u32 i = 0, j = 0;
u8 op_channel_attr_index = 0;
u8 channel_list_attr_index = 0;
#ifdef USE_SUPPLICANT_GO_INTENT
bool is_wilc_go = false;
if (iftype == CLIENT_MODE)
return;
#endif
while (index < len) {
#ifdef USE_SUPPLICANT_GO_INTENT
if (buf[index] == GROUP_BSSID_ATTR_ID) {
PRINT_D(GENERIC_DBG, "Group BSSID: %2x:%2x:%2x\n", buf[index + 3]
, buf[index + 4]
, buf[index + 5]);
is_wilc_go = true;
}
#else
if (buf[index] == GO_INTENT_ATTR_ID) {
#ifdef FORCE_P2P_CLIENT
buf[index + 3] = (buf[index + 3] & 0x01) | (0x00 << 1);
#else
buf[index + 3] = (buf[index + 3] & 0x01) | (0x0f << 1);
#endif
break;
}
#endif
if (buf[index] == CHANLIST_ATTR_ID)
channel_list_attr_index = index;
else if (buf[index] == OPERCHAN_ATTR_ID)
op_channel_attr_index = index;
index += buf[index + 1] + 3;
}
#ifdef USE_SUPPLICANT_GO_INTENT
if (u8WLANChannel != INVALID_CHANNEL && is_wilc_go)
#else
if (u8WLANChannel != INVALID_CHANNEL && bOperChan)
#endif
{
if (channel_list_attr_index) {
PRINT_D(GENERIC_DBG, "Modify channel list attribute\n");
for (i = channel_list_attr_index + 3; i < ((channel_list_attr_index + 3) + buf[channel_list_attr_index + 1]); i++) {
if (buf[i] == 0x51) {
for (j = i + 2; j < ((i + 2) + buf[i + 1]); j++) {
buf[j] = u8WLANChannel;
}
break;
}
}
}
if (op_channel_attr_index) {
PRINT_D(GENERIC_DBG, "Modify operating channel attribute\n");
buf[op_channel_attr_index + 6] = 0x51;
buf[op_channel_attr_index + 7] = u8WLANChannel;
}
}
}
void WILC_WFI_p2p_rx (struct net_device *dev, uint8_t *buff, uint32_t size)
{
struct WILC_WFI_priv *priv;
u32 header, pkt_offset;
tstrWILC_WFIDrv *pstrWFIDrv;
u32 i = 0;
s32 s32Freq;
priv = wiphy_priv(dev->ieee80211_ptr->wiphy);
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
memcpy(&header, (buff - HOST_HDR_OFFSET), HOST_HDR_OFFSET);
pkt_offset = GET_PKT_OFFSET(header);
if (pkt_offset & IS_MANAGMEMENT_CALLBACK) {
if (buff[FRAME_TYPE_ID] == IEEE80211_STYPE_PROBE_RESP) {
PRINT_D(GENERIC_DBG, "Probe response ACK\n");
cfg80211_mgmt_tx_status(priv->wdev, priv->u64tx_cookie, buff, size, true, GFP_KERNEL);
return;
} else {
if (pkt_offset & IS_MGMT_STATUS_SUCCES) {
PRINT_D(GENERIC_DBG, "Success Ack - Action frame category: %x Action Subtype: %d Dialog T: %x OR %x\n", buff[ACTION_CAT_ID], buff[ACTION_SUBTYPE_ID],
buff[ACTION_SUBTYPE_ID + 1], buff[P2P_PUB_ACTION_SUBTYPE + 1]);
cfg80211_mgmt_tx_status(priv->wdev, priv->u64tx_cookie, buff, size, true, GFP_KERNEL);
} else {
PRINT_D(GENERIC_DBG, "Fail Ack - Action frame category: %x Action Subtype: %d Dialog T: %x OR %x\n", buff[ACTION_CAT_ID], buff[ACTION_SUBTYPE_ID],
buff[ACTION_SUBTYPE_ID + 1], buff[P2P_PUB_ACTION_SUBTYPE + 1]);
cfg80211_mgmt_tx_status(priv->wdev, priv->u64tx_cookie, buff, size, false, GFP_KERNEL);
}
return;
}
} else {
PRINT_D(GENERIC_DBG, "Rx Frame Type:%x\n", buff[FRAME_TYPE_ID]);
s32Freq = ieee80211_channel_to_frequency(u8CurrChannel, IEEE80211_BAND_2GHZ);
if (ieee80211_is_action(buff[FRAME_TYPE_ID])) {
PRINT_D(GENERIC_DBG, "Rx Action Frame Type: %x %x\n", buff[ACTION_SUBTYPE_ID], buff[P2P_PUB_ACTION_SUBTYPE]);
if (priv->bCfgScanning == true && time_after_eq(jiffies, (unsigned long)pstrWFIDrv->u64P2p_MgmtTimeout)) {
PRINT_D(GENERIC_DBG, "Receiving action frames from wrong channels\n");
return;
}
if (buff[ACTION_CAT_ID] == PUB_ACTION_ATTR_ID) {
switch (buff[ACTION_SUBTYPE_ID]) {
case GAS_INTIAL_REQ:
PRINT_D(GENERIC_DBG, "GAS INITIAL REQ %x\n", buff[ACTION_SUBTYPE_ID]);
break;
case GAS_INTIAL_RSP:
PRINT_D(GENERIC_DBG, "GAS INITIAL RSP %x\n", buff[ACTION_SUBTYPE_ID]);
break;
case PUBLIC_ACT_VENDORSPEC:
if (!memcmp(u8P2P_oui, &buff[ACTION_SUBTYPE_ID + 1], 4)) {
if ((buff[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_REQ || buff[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_RSP)) {
if (!bWilc_ie) {
for (i = P2P_PUB_ACTION_SUBTYPE; i < size; i++) {
if (!memcmp(u8P2P_vendorspec, &buff[i], 6)) {
u8P2Precvrandom = buff[i + 6];
bWilc_ie = true;
PRINT_D(GENERIC_DBG, "WILC Vendor specific IE:%02x\n", u8P2Precvrandom);
break;
}
}
}
}
if (u8P2Plocalrandom > u8P2Precvrandom) {
if ((buff[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_REQ || buff[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_RSP
|| buff[P2P_PUB_ACTION_SUBTYPE] == P2P_INV_REQ || buff[P2P_PUB_ACTION_SUBTYPE] == P2P_INV_RSP)) {
for (i = P2P_PUB_ACTION_SUBTYPE + 2; i < size; i++) {
if (buff[i] == P2PELEM_ATTR_ID && !(memcmp(u8P2P_oui, &buff[i + 2], 4))) {
WILC_WFI_CfgParseRxAction(&buff[i + 6], size - (i + 6));
break;
}
}
}
} else
PRINT_D(GENERIC_DBG, "PEER WILL BE GO LocaRand=%02x RecvRand %02x\n", u8P2Plocalrandom, u8P2Precvrandom);
}
if ((buff[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_REQ || buff[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_RSP) && (bWilc_ie)) {
PRINT_D(GENERIC_DBG, "Sending P2P to host without extra elemnt\n");
cfg80211_rx_mgmt(priv->wdev, s32Freq, 0, buff, size - 7, 0);
return;
}
break;
default:
PRINT_D(GENERIC_DBG, "NOT HANDLED PUBLIC ACTION FRAME TYPE:%x\n", buff[ACTION_SUBTYPE_ID]);
break;
}
}
}
cfg80211_rx_mgmt(priv->wdev, s32Freq, 0, buff, size - 7, 0);
}
}
static void WILC_WFI_mgmt_tx_complete(void *priv, int status)
{
struct p2p_mgmt_data *pv_data = (struct p2p_mgmt_data *)priv;
kfree(pv_data->buff);
kfree(pv_data);
}
static void WILC_WFI_RemainOnChannelReady(void *pUserVoid)
{
struct WILC_WFI_priv *priv;
priv = (struct WILC_WFI_priv *)pUserVoid;
PRINT_D(HOSTINF_DBG, "Remain on channel ready\n");
priv->bInP2PlistenState = true;
cfg80211_ready_on_channel(priv->wdev,
priv->strRemainOnChanParams.u64ListenCookie,
priv->strRemainOnChanParams.pstrListenChan,
priv->strRemainOnChanParams.u32ListenDuration,
GFP_KERNEL);
}
static void WILC_WFI_RemainOnChannelExpired(void *pUserVoid, u32 u32SessionID)
{
struct WILC_WFI_priv *priv;
priv = (struct WILC_WFI_priv *)pUserVoid;
if (u32SessionID == priv->strRemainOnChanParams.u32ListenSessionID) {
PRINT_D(GENERIC_DBG, "Remain on channel expired\n");
priv->bInP2PlistenState = false;
cfg80211_remain_on_channel_expired(priv->wdev,
priv->strRemainOnChanParams.u64ListenCookie,
priv->strRemainOnChanParams.pstrListenChan,
GFP_KERNEL);
} else {
PRINT_D(GENERIC_DBG, "Received ID 0x%x Expected ID 0x%x (No match)\n", u32SessionID
, priv->strRemainOnChanParams.u32ListenSessionID);
}
}
static int WILC_WFI_remain_on_channel(struct wiphy *wiphy,
struct wireless_dev *wdev,
struct ieee80211_channel *chan,
unsigned int duration, u64 *cookie)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
priv = wiphy_priv(wiphy);
PRINT_D(GENERIC_DBG, "Remaining on channel %d\n", chan->hw_value);
if (wdev->iftype == NL80211_IFTYPE_AP) {
PRINT_D(GENERIC_DBG, "Required remain-on-channel while in AP mode");
return s32Error;
}
u8CurrChannel = chan->hw_value;
priv->strRemainOnChanParams.pstrListenChan = chan;
priv->strRemainOnChanParams.u64ListenCookie = *cookie;
priv->strRemainOnChanParams.u32ListenDuration = duration;
priv->strRemainOnChanParams.u32ListenSessionID++;
s32Error = host_int_remain_on_channel(priv->hWILCWFIDrv
, priv->strRemainOnChanParams.u32ListenSessionID
, duration
, chan->hw_value
, WILC_WFI_RemainOnChannelExpired
, WILC_WFI_RemainOnChannelReady
, (void *)priv);
return s32Error;
}
static int WILC_WFI_cancel_remain_on_channel(struct wiphy *wiphy,
struct wireless_dev *wdev,
u64 cookie)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
priv = wiphy_priv(wiphy);
PRINT_D(CFG80211_DBG, "Cancel remain on channel\n");
s32Error = host_int_ListenStateExpired(priv->hWILCWFIDrv, priv->strRemainOnChanParams.u32ListenSessionID);
return s32Error;
}
void WILC_WFI_add_wilcvendorspec(u8 *buff)
{
memcpy(buff, u8P2P_vendorspec, sizeof(u8P2P_vendorspec));
}
int WILC_WFI_mgmt_tx(struct wiphy *wiphy,
struct wireless_dev *wdev,
struct cfg80211_mgmt_tx_params *params,
u64 *cookie)
{
struct ieee80211_channel *chan = params->chan;
unsigned int wait = params->wait;
const u8 *buf = params->buf;
size_t len = params->len;
const struct ieee80211_mgmt *mgmt;
struct p2p_mgmt_data *mgmt_tx;
struct WILC_WFI_priv *priv;
s32 s32Error = WILC_SUCCESS;
tstrWILC_WFIDrv *pstrWFIDrv;
u32 i;
perInterface_wlan_t *nic;
u32 buf_len = len + sizeof(u8P2P_vendorspec) + sizeof(u8P2Plocalrandom);
nic = netdev_priv(wdev->netdev);
priv = wiphy_priv(wiphy);
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
*cookie = (unsigned long)buf;
priv->u64tx_cookie = *cookie;
mgmt = (const struct ieee80211_mgmt *) buf;
if (ieee80211_is_mgmt(mgmt->frame_control)) {
mgmt_tx = WILC_MALLOC(sizeof(struct p2p_mgmt_data));
if (mgmt_tx == NULL) {
PRINT_ER("Failed to allocate memory for mgmt_tx structure\n");
return WILC_FAIL;
}
mgmt_tx->buff = WILC_MALLOC(buf_len);
if (mgmt_tx->buff == NULL) {
PRINT_ER("Failed to allocate memory for mgmt_tx buff\n");
return WILC_FAIL;
}
memcpy(mgmt_tx->buff, buf, len);
mgmt_tx->size = len;
if (ieee80211_is_probe_resp(mgmt->frame_control)) {
PRINT_D(GENERIC_DBG, "TX: Probe Response\n");
PRINT_D(GENERIC_DBG, "Setting channel: %d\n", chan->hw_value);
host_int_set_mac_chnl_num(priv->hWILCWFIDrv, chan->hw_value);
u8CurrChannel = chan->hw_value;
} else if (ieee80211_is_action(mgmt->frame_control)) {
PRINT_D(GENERIC_DBG, "ACTION FRAME:%x\n", (u16)mgmt->frame_control);
if (buf[ACTION_CAT_ID] == PUB_ACTION_ATTR_ID) {
if (buf[ACTION_SUBTYPE_ID] != PUBLIC_ACT_VENDORSPEC ||
buf[P2P_PUB_ACTION_SUBTYPE] != GO_NEG_CONF) {
PRINT_D(GENERIC_DBG, "Setting channel: %d\n", chan->hw_value);
host_int_set_mac_chnl_num(priv->hWILCWFIDrv, chan->hw_value);
u8CurrChannel = chan->hw_value;
}
switch (buf[ACTION_SUBTYPE_ID]) {
case GAS_INTIAL_REQ:
{
PRINT_D(GENERIC_DBG, "GAS INITIAL REQ %x\n", buf[ACTION_SUBTYPE_ID]);
break;
}
case GAS_INTIAL_RSP:
{
PRINT_D(GENERIC_DBG, "GAS INITIAL RSP %x\n", buf[ACTION_SUBTYPE_ID]);
break;
}
case PUBLIC_ACT_VENDORSPEC:
{
if (!memcmp(u8P2P_oui, &buf[ACTION_SUBTYPE_ID + 1], 4)) {
if ((buf[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_REQ || buf[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_RSP)) {
if (u8P2Plocalrandom == 1 && u8P2Precvrandom < u8P2Plocalrandom) {
get_random_bytes(&u8P2Plocalrandom, 1);
u8P2Plocalrandom++;
}
}
if ((buf[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_REQ || buf[P2P_PUB_ACTION_SUBTYPE] == GO_NEG_RSP
|| buf[P2P_PUB_ACTION_SUBTYPE] == P2P_INV_REQ || buf[P2P_PUB_ACTION_SUBTYPE] == P2P_INV_RSP)) {
if (u8P2Plocalrandom > u8P2Precvrandom) {
PRINT_D(GENERIC_DBG, "LOCAL WILL BE GO LocaRand=%02x RecvRand %02x\n", u8P2Plocalrandom, u8P2Precvrandom);
for (i = P2P_PUB_ACTION_SUBTYPE + 2; i < len; i++) {
if (buf[i] == P2PELEM_ATTR_ID && !(memcmp(u8P2P_oui, &buf[i + 2], 4))) {
if (buf[P2P_PUB_ACTION_SUBTYPE] == P2P_INV_REQ || buf[P2P_PUB_ACTION_SUBTYPE] == P2P_INV_RSP)
WILC_WFI_CfgParseTxAction(&mgmt_tx->buff[i + 6], len - (i + 6), true, nic->iftype);
#ifndef USE_SUPPLICANT_GO_INTENT
else
WILC_WFI_CfgParseTxAction(&mgmt_tx->buff[i + 6], len - (i + 6), false, nic->iftype);
#endif
break;
}
}
if (buf[P2P_PUB_ACTION_SUBTYPE] != P2P_INV_REQ && buf[P2P_PUB_ACTION_SUBTYPE] != P2P_INV_RSP) {
WILC_WFI_add_wilcvendorspec(&mgmt_tx->buff[len]);
mgmt_tx->buff[len + sizeof(u8P2P_vendorspec)] = u8P2Plocalrandom;
mgmt_tx->size = buf_len;
}
} else
PRINT_D(GENERIC_DBG, "PEER WILL BE GO LocaRand=%02x RecvRand %02x\n", u8P2Plocalrandom, u8P2Precvrandom);
}
} else {
PRINT_D(GENERIC_DBG, "Not a P2P public action frame\n");
}
break;
}
default:
{
PRINT_D(GENERIC_DBG, "NOT HANDLED PUBLIC ACTION FRAME TYPE:%x\n", buf[ACTION_SUBTYPE_ID]);
break;
}
}
}
PRINT_D(GENERIC_DBG, "TX: ACTION FRAME Type:%x : Chan:%d\n", buf[ACTION_SUBTYPE_ID], chan->hw_value);
pstrWFIDrv->u64P2p_MgmtTimeout = (jiffies + msecs_to_jiffies(wait));
PRINT_D(GENERIC_DBG, "Current Jiffies: %lu Timeout:%llu\n", jiffies, pstrWFIDrv->u64P2p_MgmtTimeout);
}
g_linux_wlan->oup.wlan_add_mgmt_to_tx_que(mgmt_tx, mgmt_tx->buff, mgmt_tx->size, WILC_WFI_mgmt_tx_complete);
} else {
PRINT_D(GENERIC_DBG, "This function transmits only management frames\n");
}
return s32Error;
}
int WILC_WFI_mgmt_tx_cancel_wait(struct wiphy *wiphy,
struct wireless_dev *wdev,
u64 cookie)
{
struct WILC_WFI_priv *priv;
tstrWILC_WFIDrv *pstrWFIDrv;
priv = wiphy_priv(wiphy);
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
PRINT_D(GENERIC_DBG, "Tx Cancel wait :%lu\n", jiffies);
pstrWFIDrv->u64P2p_MgmtTimeout = jiffies;
if (priv->bInP2PlistenState == false) {
cfg80211_remain_on_channel_expired(priv->wdev,
priv->strRemainOnChanParams.u64ListenCookie,
priv->strRemainOnChanParams.pstrListenChan,
GFP_KERNEL);
}
return 0;
}
void WILC_WFI_frame_register(struct wiphy *wiphy,
struct wireless_dev *wdev,
u16 frame_type, bool reg)
{
struct WILC_WFI_priv *priv;
perInterface_wlan_t *nic;
priv = wiphy_priv(wiphy);
nic = netdev_priv(priv->wdev->netdev);
if (!frame_type)
return;
PRINT_D(GENERIC_DBG, "Frame registering Frame Type: %x: Boolean: %d\n", frame_type, reg);
switch (frame_type) {
case PROBE_REQ:
{
nic->g_struct_frame_reg[0].frame_type = frame_type;
nic->g_struct_frame_reg[0].reg = reg;
}
break;
case ACTION:
{
nic->g_struct_frame_reg[1].frame_type = frame_type;
nic->g_struct_frame_reg[1].reg = reg;
}
break;
default:
{
break;
}
}
if (!g_linux_wlan->wilc1000_initialized) {
PRINT_D(GENERIC_DBG, "Return since mac is closed\n");
return;
}
host_int_frame_register(priv->hWILCWFIDrv, frame_type, reg);
}
static int WILC_WFI_set_cqm_rssi_config(struct wiphy *wiphy,
struct net_device *dev, s32 rssi_thold, u32 rssi_hyst)
{
PRINT_D(CFG80211_DBG, "Setting CQM RSSi Function\n");
return 0;
}
static int WILC_WFI_dump_station(struct wiphy *wiphy, struct net_device *dev,
int idx, u8 *mac, struct station_info *sinfo)
{
struct WILC_WFI_priv *priv;
PRINT_D(CFG80211_DBG, "Dumping station information\n");
if (idx != 0)
return -ENOENT;
priv = wiphy_priv(wiphy);
sinfo->filled |= BIT(NL80211_STA_INFO_SIGNAL);
host_int_get_rssi(priv->hWILCWFIDrv, &(sinfo->signal));
return 0;
}
int WILC_WFI_set_power_mgmt(struct wiphy *wiphy, struct net_device *dev,
bool enabled, int timeout)
{
struct WILC_WFI_priv *priv;
PRINT_D(CFG80211_DBG, " Power save Enabled= %d , TimeOut = %d\n", enabled, timeout);
if (wiphy == NULL)
return -ENOENT;
priv = wiphy_priv(wiphy);
if (priv->hWILCWFIDrv == NULL) {
PRINT_ER("Driver is NULL\n");
return -EIO;
}
if (bEnablePS)
host_int_set_power_mgmt(priv->hWILCWFIDrv, enabled, timeout);
return WILC_SUCCESS;
}
static int WILC_WFI_change_virt_intf(struct wiphy *wiphy, struct net_device *dev,
enum nl80211_iftype type, u32 *flags, struct vif_params *params)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
perInterface_wlan_t *nic;
u8 interface_type;
u16 TID = 0;
#ifdef WILC_P2P
u8 i;
#endif
nic = netdev_priv(dev);
priv = wiphy_priv(wiphy);
PRINT_D(HOSTAPD_DBG, "In Change virtual interface function\n");
PRINT_D(HOSTAPD_DBG, "Wireless interface name =%s\n", dev->name);
u8P2Plocalrandom = 0x01;
u8P2Precvrandom = 0x00;
bWilc_ie = false;
#ifdef DISABLE_PWRSAVE_AND_SCAN_DURING_IP
g_obtainingIP = false;
del_timer(&hDuringIpTimer);
PRINT_D(GENERIC_DBG, "Changing virtual interface, enable scan\n");
#endif
if (g_ptk_keys_saved && g_gtk_keys_saved) {
Set_machw_change_vir_if(true);
}
switch (type) {
case NL80211_IFTYPE_STATION:
connecting = 0;
PRINT_D(HOSTAPD_DBG, "Interface type = NL80211_IFTYPE_STATION\n");
dev->ieee80211_ptr->iftype = type;
priv->wdev->iftype = type;
nic->monitor_flag = 0;
nic->iftype = STATION_MODE;
memset(priv->assoc_stainfo.au8Sta_AssociatedBss, 0, MAX_NUM_STA * ETH_ALEN);
#ifdef WILC_P2P
interface_type = nic->iftype;
nic->iftype = STATION_MODE;
if (g_linux_wlan->wilc1000_initialized) {
host_int_del_All_Rx_BASession(priv->hWILCWFIDrv, g_linux_wlan->strInterfaceInfo[0].aBSSID, TID);
host_int_wait_msg_queue_idle();
linux_wlan_unlock((void *)&g_linux_wlan->cfg_event);
wilc1000_wlan_deinit(g_linux_wlan);
wilc1000_wlan_init(dev, nic);
g_wilc_initialized = 1;
nic->iftype = interface_type;
host_int_set_wfi_drv_handler(g_linux_wlan->strInterfaceInfo[0].drvHandler);
host_int_set_MacAddress(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_linux_wlan->strInterfaceInfo[0].aSrcAddress);
host_int_set_operation_mode(priv->hWILCWFIDrv, STATION_MODE);
if (g_wep_keys_saved) {
host_int_set_WEPDefaultKeyID(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_key_wep_params.key_idx);
host_int_add_wep_key_bss_sta(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_key_wep_params.key,
g_key_wep_params.key_len,
g_key_wep_params.key_idx);
}
host_int_flush_join_req(priv->hWILCWFIDrv);
if (g_ptk_keys_saved && g_gtk_keys_saved) {
PRINT_D(CFG80211_DBG, "ptk %x %x %x\n", g_key_ptk_params.key[0],
g_key_ptk_params.key[1],
g_key_ptk_params.key[2]);
PRINT_D(CFG80211_DBG, "gtk %x %x %x\n", g_key_gtk_params.key[0],
g_key_gtk_params.key[1],
g_key_gtk_params.key[2]);
WILC_WFI_add_key(g_linux_wlan->strInterfaceInfo[0].wilc_netdev->ieee80211_ptr->wiphy,
g_linux_wlan->strInterfaceInfo[0].wilc_netdev,
g_add_ptk_key_params.key_idx,
g_add_ptk_key_params.pairwise,
g_add_ptk_key_params.mac_addr,
(struct key_params *)(&g_key_ptk_params));
WILC_WFI_add_key(g_linux_wlan->strInterfaceInfo[0].wilc_netdev->ieee80211_ptr->wiphy,
g_linux_wlan->strInterfaceInfo[0].wilc_netdev,
g_add_gtk_key_params.key_idx,
g_add_gtk_key_params.pairwise,
g_add_gtk_key_params.mac_addr,
(struct key_params *)(&g_key_gtk_params));
}
if (g_linux_wlan->wilc1000_initialized) {
for (i = 0; i < num_reg_frame; i++) {
PRINT_D(INIT_DBG, "Frame registering Type: %x - Reg: %d\n", nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
host_int_frame_register(priv->hWILCWFIDrv,
nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
}
}
bEnablePS = true;
host_int_set_power_mgmt(priv->hWILCWFIDrv, 1, 0);
}
#endif
break;
case NL80211_IFTYPE_P2P_CLIENT:
bEnablePS = false;
host_int_set_power_mgmt(priv->hWILCWFIDrv, 0, 0);
connecting = 0;
PRINT_D(HOSTAPD_DBG, "Interface type = NL80211_IFTYPE_P2P_CLIENT\n");
host_int_del_All_Rx_BASession(priv->hWILCWFIDrv, g_linux_wlan->strInterfaceInfo[0].aBSSID, TID);
dev->ieee80211_ptr->iftype = type;
priv->wdev->iftype = type;
nic->monitor_flag = 0;
#ifdef WILC_P2P
PRINT_D(HOSTAPD_DBG, "Downloading P2P_CONCURRENCY_FIRMWARE\n");
nic->iftype = CLIENT_MODE;
if (g_linux_wlan->wilc1000_initialized) {
host_int_wait_msg_queue_idle();
wilc1000_wlan_deinit(g_linux_wlan);
wilc1000_wlan_init(dev, nic);
g_wilc_initialized = 1;
host_int_set_wfi_drv_handler(g_linux_wlan->strInterfaceInfo[0].drvHandler);
host_int_set_MacAddress(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_linux_wlan->strInterfaceInfo[0].aSrcAddress);
host_int_set_operation_mode(priv->hWILCWFIDrv, STATION_MODE);
if (g_wep_keys_saved) {
host_int_set_WEPDefaultKeyID(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_key_wep_params.key_idx);
host_int_add_wep_key_bss_sta(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_key_wep_params.key,
g_key_wep_params.key_len,
g_key_wep_params.key_idx);
}
host_int_flush_join_req(priv->hWILCWFIDrv);
if (g_ptk_keys_saved && g_gtk_keys_saved) {
PRINT_D(CFG80211_DBG, "ptk %x %x %x\n", g_key_ptk_params.key[0],
g_key_ptk_params.key[1],
g_key_ptk_params.key[2]);
PRINT_D(CFG80211_DBG, "gtk %x %x %x\n", g_key_gtk_params.key[0],
g_key_gtk_params.key[1],
g_key_gtk_params.key[2]);
WILC_WFI_add_key(g_linux_wlan->strInterfaceInfo[0].wilc_netdev->ieee80211_ptr->wiphy,
g_linux_wlan->strInterfaceInfo[0].wilc_netdev,
g_add_ptk_key_params.key_idx,
g_add_ptk_key_params.pairwise,
g_add_ptk_key_params.mac_addr,
(struct key_params *)(&g_key_ptk_params));
WILC_WFI_add_key(g_linux_wlan->strInterfaceInfo[0].wilc_netdev->ieee80211_ptr->wiphy,
g_linux_wlan->strInterfaceInfo[0].wilc_netdev,
g_add_gtk_key_params.key_idx,
g_add_gtk_key_params.pairwise,
g_add_gtk_key_params.mac_addr,
(struct key_params *)(&g_key_gtk_params));
}
refresh_scan(priv, 1, true);
Set_machw_change_vir_if(false);
if (g_linux_wlan->wilc1000_initialized) {
for (i = 0; i < num_reg_frame; i++) {
PRINT_D(INIT_DBG, "Frame registering Type: %x - Reg: %d\n", nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
host_int_frame_register(priv->hWILCWFIDrv,
nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
}
}
}
#endif
break;
case NL80211_IFTYPE_AP:
bEnablePS = false;
PRINT_D(HOSTAPD_DBG, "Interface type = NL80211_IFTYPE_AP %d\n", type);
dev->ieee80211_ptr->iftype = type;
priv->wdev->iftype = type;
nic->iftype = AP_MODE;
PRINT_D(CORECONFIG_DBG, "priv->hWILCWFIDrv[%p]\n", priv->hWILCWFIDrv);
PRINT_D(HOSTAPD_DBG, "Downloading AP firmware\n");
linux_wlan_get_firmware(nic);
#ifdef WILC_P2P
if (g_linux_wlan->wilc1000_initialized) {
nic->iftype = AP_MODE;
g_linux_wlan->wilc1000_initialized = 1;
mac_close(dev);
mac_open(dev);
for (i = 0; i < num_reg_frame; i++) {
PRINT_D(INIT_DBG, "Frame registering Type: %x - Reg: %d\n", nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
host_int_frame_register(priv->hWILCWFIDrv,
nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
}
}
#endif
break;
case NL80211_IFTYPE_P2P_GO:
PRINT_D(GENERIC_DBG, "start duringIP timer\n");
#ifdef DISABLE_PWRSAVE_AND_SCAN_DURING_IP
g_obtainingIP = true;
mod_timer(&hDuringIpTimer, jiffies + msecs_to_jiffies(duringIP_TIME));
#endif
host_int_set_power_mgmt(priv->hWILCWFIDrv, 0, 0);
host_int_del_All_Rx_BASession(priv->hWILCWFIDrv, g_linux_wlan->strInterfaceInfo[0].aBSSID, TID);
bEnablePS = false;
PRINT_D(HOSTAPD_DBG, "Interface type = NL80211_IFTYPE_GO\n");
dev->ieee80211_ptr->iftype = type;
priv->wdev->iftype = type;
PRINT_D(CORECONFIG_DBG, "priv->hWILCWFIDrv[%p]\n", priv->hWILCWFIDrv);
#ifdef WILC_P2P
PRINT_D(HOSTAPD_DBG, "Downloading P2P_CONCURRENCY_FIRMWARE\n");
#if 1
nic->iftype = GO_MODE;
host_int_wait_msg_queue_idle();
wilc1000_wlan_deinit(g_linux_wlan);
wilc1000_wlan_init(dev, nic);
g_wilc_initialized = 1;
host_int_set_wfi_drv_handler(g_linux_wlan->strInterfaceInfo[0].drvHandler);
host_int_set_MacAddress(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_linux_wlan->strInterfaceInfo[0].aSrcAddress);
host_int_set_operation_mode(priv->hWILCWFIDrv, AP_MODE);
if (g_wep_keys_saved) {
host_int_set_WEPDefaultKeyID(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_key_wep_params.key_idx);
host_int_add_wep_key_bss_sta(g_linux_wlan->strInterfaceInfo[0].drvHandler,
g_key_wep_params.key,
g_key_wep_params.key_len,
g_key_wep_params.key_idx);
}
host_int_flush_join_req(priv->hWILCWFIDrv);
if (g_ptk_keys_saved && g_gtk_keys_saved) {
PRINT_D(CFG80211_DBG, "ptk %x %x %x cipher %x\n", g_key_ptk_params.key[0],
g_key_ptk_params.key[1],
g_key_ptk_params.key[2],
g_key_ptk_params.cipher);
PRINT_D(CFG80211_DBG, "gtk %x %x %x cipher %x\n", g_key_gtk_params.key[0],
g_key_gtk_params.key[1],
g_key_gtk_params.key[2],
g_key_gtk_params.cipher);
#if 1
WILC_WFI_add_key(g_linux_wlan->strInterfaceInfo[0].wilc_netdev->ieee80211_ptr->wiphy,
g_linux_wlan->strInterfaceInfo[0].wilc_netdev,
g_add_ptk_key_params.key_idx,
g_add_ptk_key_params.pairwise,
g_add_ptk_key_params.mac_addr,
(struct key_params *)(&g_key_ptk_params));
WILC_WFI_add_key(g_linux_wlan->strInterfaceInfo[0].wilc_netdev->ieee80211_ptr->wiphy,
g_linux_wlan->strInterfaceInfo[0].wilc_netdev,
g_add_gtk_key_params.key_idx,
g_add_gtk_key_params.pairwise,
g_add_gtk_key_params.mac_addr,
(struct key_params *)(&g_key_gtk_params));
#endif
}
#endif
if (g_linux_wlan->wilc1000_initialized) {
for (i = 0; i < num_reg_frame; i++) {
PRINT_D(INIT_DBG, "Frame registering Type: %x - Reg: %d\n", nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
host_int_frame_register(priv->hWILCWFIDrv,
nic->g_struct_frame_reg[i].frame_type,
nic->g_struct_frame_reg[i].reg);
}
}
#endif
break;
default:
PRINT_ER("Unknown interface type= %d\n", type);
s32Error = -EINVAL;
return s32Error;
break;
}
return s32Error;
}
static int WILC_WFI_start_ap(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_ap_settings *settings)
{
struct cfg80211_beacon_data *beacon = &(settings->beacon);
struct WILC_WFI_priv *priv;
s32 s32Error = WILC_SUCCESS;
priv = wiphy_priv(wiphy);
PRINT_D(HOSTAPD_DBG, "Starting ap\n");
PRINT_D(HOSTAPD_DBG, "Interval = %d\n DTIM period = %d\n Head length = %zu Tail length = %zu\n",
settings->beacon_interval, settings->dtim_period, beacon->head_len, beacon->tail_len);
s32Error = WILC_WFI_CfgSetChannel(wiphy, &settings->chandef);
if (s32Error != WILC_SUCCESS)
PRINT_ER("Error in setting channel\n");
linux_wlan_set_bssid(dev, g_linux_wlan->strInterfaceInfo[0].aSrcAddress);
#ifndef WILC_FULLY_HOSTING_AP
s32Error = host_int_add_beacon(priv->hWILCWFIDrv,
settings->beacon_interval,
settings->dtim_period,
beacon->head_len, (u8 *)beacon->head,
beacon->tail_len, (u8 *)beacon->tail);
#else
s32Error = host_add_beacon(priv->hWILCWFIDrv,
settings->beacon_interval,
settings->dtim_period,
beacon->head_len, (u8 *)beacon->head,
beacon->tail_len, (u8 *)beacon->tail);
#endif
return s32Error;
}
static int WILC_WFI_change_beacon(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_beacon_data *beacon)
{
struct WILC_WFI_priv *priv;
s32 s32Error = WILC_SUCCESS;
priv = wiphy_priv(wiphy);
PRINT_D(HOSTAPD_DBG, "Setting beacon\n");
#ifndef WILC_FULLY_HOSTING_AP
s32Error = host_int_add_beacon(priv->hWILCWFIDrv,
0,
0,
beacon->head_len, (u8 *)beacon->head,
beacon->tail_len, (u8 *)beacon->tail);
#else
s32Error = host_add_beacon(priv->hWILCWFIDrv,
0,
0,
beacon->head_len, (u8 *)beacon->head,
beacon->tail_len, (u8 *)beacon->tail);
#endif
return s32Error;
}
static int WILC_WFI_stop_ap(struct wiphy *wiphy, struct net_device *dev)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
u8 NullBssid[ETH_ALEN] = {0};
WILC_NULLCHECK(s32Error, wiphy);
priv = wiphy_priv(wiphy);
PRINT_D(HOSTAPD_DBG, "Deleting beacon\n");
linux_wlan_set_bssid(dev, NullBssid);
#ifndef WILC_FULLY_HOSTING_AP
s32Error = host_int_del_beacon(priv->hWILCWFIDrv);
#else
s32Error = host_del_beacon(priv->hWILCWFIDrv);
#endif
WILC_ERRORCHECK(s32Error);
WILC_CATCH(s32Error)
{
}
return s32Error;
}
static int WILC_WFI_add_station(struct wiphy *wiphy, struct net_device *dev,
const u8 *mac, struct station_parameters *params)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
tstrWILC_AddStaParam strStaParams = { {0} };
perInterface_wlan_t *nic;
WILC_NULLCHECK(s32Error, wiphy);
priv = wiphy_priv(wiphy);
nic = netdev_priv(dev);
if (nic->iftype == AP_MODE || nic->iftype == GO_MODE) {
#ifndef WILC_FULLY_HOSTING_AP
memcpy(strStaParams.au8BSSID, mac, ETH_ALEN);
memcpy(priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid], mac, ETH_ALEN);
strStaParams.u16AssocID = params->aid;
strStaParams.u8NumRates = params->supported_rates_len;
strStaParams.pu8Rates = params->supported_rates;
PRINT_D(CFG80211_DBG, "Adding station parameters %d\n", params->aid);
PRINT_D(CFG80211_DBG, "BSSID = %x%x%x%x%x%x\n", priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][0], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][1], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][2], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][3], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][4],
priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][5]);
PRINT_D(HOSTAPD_DBG, "ASSOC ID = %d\n", strStaParams.u16AssocID);
PRINT_D(HOSTAPD_DBG, "Number of supported rates = %d\n", strStaParams.u8NumRates);
if (params->ht_capa == NULL) {
strStaParams.bIsHTSupported = false;
} else {
strStaParams.bIsHTSupported = true;
strStaParams.u16HTCapInfo = params->ht_capa->cap_info;
strStaParams.u8AmpduParams = params->ht_capa->ampdu_params_info;
memcpy(strStaParams.au8SuppMCsSet, &params->ht_capa->mcs, WILC_SUPP_MCS_SET_SIZE);
strStaParams.u16HTExtParams = params->ht_capa->extended_ht_cap_info;
strStaParams.u32TxBeamformingCap = params->ht_capa->tx_BF_cap_info;
strStaParams.u8ASELCap = params->ht_capa->antenna_selection_info;
}
strStaParams.u16FlagsMask = params->sta_flags_mask;
strStaParams.u16FlagsSet = params->sta_flags_set;
PRINT_D(HOSTAPD_DBG, "IS HT supported = %d\n", strStaParams.bIsHTSupported);
PRINT_D(HOSTAPD_DBG, "Capability Info = %d\n", strStaParams.u16HTCapInfo);
PRINT_D(HOSTAPD_DBG, "AMPDU Params = %d\n", strStaParams.u8AmpduParams);
PRINT_D(HOSTAPD_DBG, "HT Extended params = %d\n", strStaParams.u16HTExtParams);
PRINT_D(HOSTAPD_DBG, "Tx Beamforming Cap = %d\n", strStaParams.u32TxBeamformingCap);
PRINT_D(HOSTAPD_DBG, "Antenna selection info = %d\n", strStaParams.u8ASELCap);
PRINT_D(HOSTAPD_DBG, "Flag Mask = %d\n", strStaParams.u16FlagsMask);
PRINT_D(HOSTAPD_DBG, "Flag Set = %d\n", strStaParams.u16FlagsSet);
s32Error = host_int_add_station(priv->hWILCWFIDrv, &strStaParams);
WILC_ERRORCHECK(s32Error);
#else
PRINT_D(CFG80211_DBG, "Adding station parameters %d\n", params->aid);
memcpy(priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid], mac, ETH_ALEN);
PRINT_D(CFG80211_DBG, "BSSID = %x%x%x%x%x%x\n", priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][0], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][1], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][2], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][3], priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][4],
priv->assoc_stainfo.au8Sta_AssociatedBss[params->aid][5]);
WILC_AP_AddSta(mac, params);
WILC_ERRORCHECK(s32Error);
#endif
}
WILC_CATCH(s32Error)
{
}
return s32Error;
}
static int WILC_WFI_del_station(struct wiphy *wiphy, struct net_device *dev,
struct station_del_parameters *params)
{
const u8 *mac = params->mac;
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
perInterface_wlan_t *nic;
WILC_NULLCHECK(s32Error, wiphy);
priv = wiphy_priv(wiphy);
nic = netdev_priv(dev);
if (nic->iftype == AP_MODE || nic->iftype == GO_MODE) {
PRINT_D(HOSTAPD_DBG, "Deleting station\n");
if (mac == NULL) {
PRINT_D(HOSTAPD_DBG, "All associated stations\n");
s32Error = host_int_del_allstation(priv->hWILCWFIDrv, priv->assoc_stainfo.au8Sta_AssociatedBss);
} else {
PRINT_D(HOSTAPD_DBG, "With mac address: %x%x%x%x%x%x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}
#ifndef WILC_FULLY_HOSTING_AP
s32Error = host_int_del_station(priv->hWILCWFIDrv, mac);
#else
WILC_AP_RemoveSta(mac);
#endif
WILC_ERRORCHECK(s32Error);
}
WILC_CATCH(s32Error)
{
}
return s32Error;
}
static int WILC_WFI_change_station(struct wiphy *wiphy, struct net_device *dev,
const u8 *mac, struct station_parameters *params)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
tstrWILC_AddStaParam strStaParams = { {0} };
perInterface_wlan_t *nic;
PRINT_D(HOSTAPD_DBG, "Change station paramters\n");
WILC_NULLCHECK(s32Error, wiphy);
priv = wiphy_priv(wiphy);
nic = netdev_priv(dev);
if (nic->iftype == AP_MODE || nic->iftype == GO_MODE) {
#ifndef WILC_FULLY_HOSTING_AP
memcpy(strStaParams.au8BSSID, mac, ETH_ALEN);
strStaParams.u16AssocID = params->aid;
strStaParams.u8NumRates = params->supported_rates_len;
strStaParams.pu8Rates = params->supported_rates;
PRINT_D(HOSTAPD_DBG, "BSSID = %x%x%x%x%x%x\n", strStaParams.au8BSSID[0], strStaParams.au8BSSID[1], strStaParams.au8BSSID[2], strStaParams.au8BSSID[3], strStaParams.au8BSSID[4],
strStaParams.au8BSSID[5]);
PRINT_D(HOSTAPD_DBG, "ASSOC ID = %d\n", strStaParams.u16AssocID);
PRINT_D(HOSTAPD_DBG, "Number of supported rates = %d\n", strStaParams.u8NumRates);
if (params->ht_capa == NULL) {
strStaParams.bIsHTSupported = false;
} else {
strStaParams.bIsHTSupported = true;
strStaParams.u16HTCapInfo = params->ht_capa->cap_info;
strStaParams.u8AmpduParams = params->ht_capa->ampdu_params_info;
memcpy(strStaParams.au8SuppMCsSet, &params->ht_capa->mcs, WILC_SUPP_MCS_SET_SIZE);
strStaParams.u16HTExtParams = params->ht_capa->extended_ht_cap_info;
strStaParams.u32TxBeamformingCap = params->ht_capa->tx_BF_cap_info;
strStaParams.u8ASELCap = params->ht_capa->antenna_selection_info;
}
strStaParams.u16FlagsMask = params->sta_flags_mask;
strStaParams.u16FlagsSet = params->sta_flags_set;
PRINT_D(HOSTAPD_DBG, "IS HT supported = %d\n", strStaParams.bIsHTSupported);
PRINT_D(HOSTAPD_DBG, "Capability Info = %d\n", strStaParams.u16HTCapInfo);
PRINT_D(HOSTAPD_DBG, "AMPDU Params = %d\n", strStaParams.u8AmpduParams);
PRINT_D(HOSTAPD_DBG, "HT Extended params = %d\n", strStaParams.u16HTExtParams);
PRINT_D(HOSTAPD_DBG, "Tx Beamforming Cap = %d\n", strStaParams.u32TxBeamformingCap);
PRINT_D(HOSTAPD_DBG, "Antenna selection info = %d\n", strStaParams.u8ASELCap);
PRINT_D(HOSTAPD_DBG, "Flag Mask = %d\n", strStaParams.u16FlagsMask);
PRINT_D(HOSTAPD_DBG, "Flag Set = %d\n", strStaParams.u16FlagsSet);
s32Error = host_int_edit_station(priv->hWILCWFIDrv, &strStaParams);
WILC_ERRORCHECK(s32Error);
#else
WILC_AP_EditSta(mac, params);
WILC_ERRORCHECK(s32Error);
#endif
}
WILC_CATCH(s32Error)
{
}
return s32Error;
}
struct wireless_dev *WILC_WFI_add_virt_intf(struct wiphy *wiphy, const char *name,
unsigned char name_assign_type,
enum nl80211_iftype type, u32 *flags,
struct vif_params *params)
{
perInterface_wlan_t *nic;
struct WILC_WFI_priv *priv;
struct net_device *new_ifc = NULL;
priv = wiphy_priv(wiphy);
PRINT_D(HOSTAPD_DBG, "Adding monitor interface[%p]\n", priv->wdev->netdev);
nic = netdev_priv(priv->wdev->netdev);
if (type == NL80211_IFTYPE_MONITOR) {
PRINT_D(HOSTAPD_DBG, "Monitor interface mode: Initializing mon interface virtual device driver\n");
PRINT_D(HOSTAPD_DBG, "Adding monitor interface[%p]\n", nic->wilc_netdev);
new_ifc = WILC_WFI_init_mon_interface(name, nic->wilc_netdev);
if (new_ifc != NULL) {
PRINT_D(HOSTAPD_DBG, "Setting monitor flag in private structure\n");
nic = netdev_priv(priv->wdev->netdev);
nic->monitor_flag = 1;
} else
PRINT_ER("Error in initializing monitor interface\n ");
}
return priv->wdev;
}
int WILC_WFI_del_virt_intf(struct wiphy *wiphy, struct wireless_dev *wdev)
{
PRINT_D(HOSTAPD_DBG, "Deleting virtual interface\n");
return WILC_SUCCESS;
}
int WILC_WFI_update_stats(struct wiphy *wiphy, u32 pktlen, u8 changed)
{
struct WILC_WFI_priv *priv;
priv = wiphy_priv(wiphy);
#if 1
switch (changed) {
case WILC_WFI_RX_PKT:
{
priv->netstats.rx_packets++;
priv->netstats.rx_bytes += pktlen;
priv->netstats.rx_time = get_jiffies_64();
}
break;
case WILC_WFI_TX_PKT:
{
priv->netstats.tx_packets++;
priv->netstats.tx_bytes += pktlen;
priv->netstats.tx_time = get_jiffies_64();
}
break;
default:
break;
}
#endif
return 0;
}
struct wireless_dev *WILC_WFI_CfgAlloc(void)
{
struct wireless_dev *wdev;
PRINT_D(CFG80211_DBG, "Allocating wireless device\n");
wdev = kzalloc(sizeof(struct wireless_dev), GFP_KERNEL);
if (!wdev) {
PRINT_ER("Cannot allocate wireless device\n");
goto _fail_;
}
wdev->wiphy = wiphy_new(&WILC_WFI_cfg80211_ops, sizeof(struct WILC_WFI_priv));
if (!wdev->wiphy) {
PRINT_ER("Cannot allocate wiphy\n");
goto _fail_mem_;
}
#ifdef WILC_AP_EXTERNAL_MLME
WILC_WFI_band_2ghz.ht_cap.ht_supported = 1;
WILC_WFI_band_2ghz.ht_cap.cap |= (1 << IEEE80211_HT_CAP_RX_STBC_SHIFT);
WILC_WFI_band_2ghz.ht_cap.mcs.rx_mask[0] = 0xff;
WILC_WFI_band_2ghz.ht_cap.ampdu_factor = IEEE80211_HT_MAX_AMPDU_8K;
WILC_WFI_band_2ghz.ht_cap.ampdu_density = IEEE80211_HT_MPDU_DENSITY_NONE;
#endif
wdev->wiphy->bands[IEEE80211_BAND_2GHZ] = &WILC_WFI_band_2ghz;
return wdev;
_fail_mem_:
kfree(wdev);
_fail_:
return NULL;
}
struct wireless_dev *WILC_WFI_WiphyRegister(struct net_device *net)
{
struct WILC_WFI_priv *priv;
struct wireless_dev *wdev;
s32 s32Error = WILC_SUCCESS;
PRINT_D(CFG80211_DBG, "Registering wifi device\n");
wdev = WILC_WFI_CfgAlloc();
if (wdev == NULL) {
PRINT_ER("CfgAlloc Failed\n");
return NULL;
}
priv = wdev_priv(wdev);
sema_init(&(priv->SemHandleUpdateStats), 1);
priv->wdev = wdev;
wdev->wiphy->max_scan_ssids = MAX_NUM_PROBED_SSID;
wdev->wiphy->max_num_pmkids = WILC_MAX_NUM_PMKIDS;
PRINT_INFO(CFG80211_DBG, "Max number of PMKIDs = %d\n", wdev->wiphy->max_num_pmkids);
wdev->wiphy->max_scan_ie_len = 1000;
wdev->wiphy->signal_type = CFG80211_SIGNAL_TYPE_MBM;
wdev->wiphy->cipher_suites = cipher_suites;
wdev->wiphy->n_cipher_suites = ARRAY_SIZE(cipher_suites);
wdev->wiphy->mgmt_stypes = wilc_wfi_cfg80211_mgmt_types;
#ifdef WILC_P2P
wdev->wiphy->max_remain_on_channel_duration = 500;
wdev->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) | BIT(NL80211_IFTYPE_AP) | BIT(NL80211_IFTYPE_MONITOR) | BIT(NL80211_IFTYPE_P2P_GO) |
BIT(NL80211_IFTYPE_P2P_CLIENT);
wdev->wiphy->flags |= WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL;
#else
wdev->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) | BIT(NL80211_IFTYPE_AP) | BIT(NL80211_IFTYPE_MONITOR);
#endif
wdev->iftype = NL80211_IFTYPE_STATION;
PRINT_INFO(CFG80211_DBG, "Max scan ids = %d,Max scan IE len = %d,Signal Type = %d,Interface Modes = %d,Interface Type = %d\n",
wdev->wiphy->max_scan_ssids, wdev->wiphy->max_scan_ie_len, wdev->wiphy->signal_type,
wdev->wiphy->interface_modes, wdev->iftype);
#ifdef WILC_SDIO
set_wiphy_dev(wdev->wiphy, &local_sdio_func->dev);
#endif
s32Error = wiphy_register(wdev->wiphy);
if (s32Error) {
PRINT_ER("Cannot register wiphy device\n");
} else {
PRINT_D(CFG80211_DBG, "Successful Registering\n");
}
priv->dev = net;
return wdev;
}
int WILC_WFI_InitHostInt(struct net_device *net)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
PRINT_D(INIT_DBG, "Host[%p][%p]\n", net, net->ieee80211_ptr);
priv = wdev_priv(net->ieee80211_ptr);
if (op_ifcs == 0) {
setup_timer(&hAgingTimer, remove_network_from_shadow, 0);
#ifdef DISABLE_PWRSAVE_AND_SCAN_DURING_IP
setup_timer(&hDuringIpTimer, clear_duringIP, 0);
#endif
}
op_ifcs++;
if (s32Error < 0) {
PRINT_ER("Failed to creat refresh Timer\n");
return s32Error;
}
priv->gbAutoRateAdjusted = false;
priv->bInP2PlistenState = false;
sema_init(&(priv->hSemScanReq), 1);
s32Error = host_int_init(&priv->hWILCWFIDrv);
if (s32Error) {
PRINT_ER("Error while initializing hostinterface\n");
}
return s32Error;
}
int WILC_WFI_DeInitHostInt(struct net_device *net)
{
s32 s32Error = WILC_SUCCESS;
struct WILC_WFI_priv *priv;
priv = wdev_priv(net->ieee80211_ptr);
priv->gbAutoRateAdjusted = false;
priv->bInP2PlistenState = false;
op_ifcs--;
s32Error = host_int_deinit(priv->hWILCWFIDrv);
clear_shadow_scan(priv);
#ifdef DISABLE_PWRSAVE_AND_SCAN_DURING_IP
if (op_ifcs == 0) {
PRINT_D(CORECONFIG_DBG, "destroy during ip\n");
del_timer_sync(&hDuringIpTimer);
}
#endif
if (s32Error) {
PRINT_ER("Error while deintializing host interface\n");
}
return s32Error;
}
void WILC_WFI_WiphyFree(struct net_device *net)
{
PRINT_D(CFG80211_DBG, "Unregistering wiphy\n");
if (net == NULL) {
PRINT_D(INIT_DBG, "net_device is NULL\n");
return;
}
if (net->ieee80211_ptr == NULL) {
PRINT_D(INIT_DBG, "ieee80211_ptr is NULL\n");
return;
}
if (net->ieee80211_ptr->wiphy == NULL) {
PRINT_D(INIT_DBG, "wiphy is NULL\n");
return;
}
wiphy_unregister(net->ieee80211_ptr->wiphy);
PRINT_D(INIT_DBG, "Freeing wiphy\n");
wiphy_free(net->ieee80211_ptr->wiphy);
kfree(net->ieee80211_ptr);
}
