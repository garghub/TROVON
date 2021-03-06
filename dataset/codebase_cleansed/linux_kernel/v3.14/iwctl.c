struct iw_statistics *iwctl_get_wireless_stats(struct net_device *dev)
{
PSDevice pDevice = netdev_priv(dev);
long ldBm;
pDevice->wstats.status = pDevice->eOPMode;
#ifdef Calcu_LinkQual
if (pDevice->scStatistic.LinkQuality > 100)
pDevice->scStatistic.LinkQuality = 100;
pDevice->wstats.qual.qual = (unsigned char)pDevice->scStatistic.LinkQuality;
#else
pDevice->wstats.qual.qual = pDevice->byCurrSQ;
#endif
RFvRSSITodBm(pDevice, (unsigned char)(pDevice->uCurrRSSI), &ldBm);
pDevice->wstats.qual.level = ldBm;
pDevice->wstats.qual.noise = 0;
pDevice->wstats.qual.updated = 1;
pDevice->wstats.discard.nwid = 0;
pDevice->wstats.discard.code = 0;
pDevice->wstats.discard.fragment = 0;
pDevice->wstats.discard.retries = (unsigned long)pDevice->scStatistic.dwTsrErr;
pDevice->wstats.discard.misc = 0;
pDevice->wstats.miss.beacon = 0;
return &pDevice->wstats;
}
static int iwctl_commit(struct net_device *dev,
struct iw_request_info *info,
void *wrq,
char *extra)
{
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWCOMMIT \n");
return 0;
}
int iwctl_giwname(struct net_device *dev,
struct iw_request_info *info,
char *wrq,
char *extra)
{
strcpy(wrq, "802.11-a/b/g");
return 0;
}
int iwctl_siwscan(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
struct iw_scan_req *req = (struct iw_scan_req *)extra;
unsigned char abyScanSSID[WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1];
PWLAN_IE_SSID pItemSSID = NULL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWSCAN \n");
if (pDevice->byReAssocCount > 0) {
union iwreq_data wrqu;
PRINT_K("wireless_send_event--->SIOCGIWSCAN(scan done)\n");
memset(&wrqu, 0, sizeof(wrqu));
wireless_send_event(pDevice->dev, SIOCGIWSCAN, &wrqu, NULL);
return 0;
}
spin_lock_irq(&pDevice->lock);
BSSvClearBSSList((void *)pDevice, pDevice->bLinkPass);
if (wrq->length == sizeof(struct iw_scan_req)) {
if (wrq->flags & IW_SCAN_THIS_ESSID) {
memset(abyScanSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
pItemSSID = (PWLAN_IE_SSID)abyScanSSID;
pItemSSID->byElementID = WLAN_EID_SSID;
memcpy(pItemSSID->abySSID, req->essid, (int)req->essid_len);
if (pItemSSID->abySSID[req->essid_len - 1] == '\0') {
if (req->essid_len > 0)
pItemSSID->len = req->essid_len - 1;
} else
pItemSSID->len = req->essid_len;
pMgmt->eScanType = WMAC_SCAN_PASSIVE;
PRINT_K("SIOCSIWSCAN:[desired_ssid=%s,len=%d]\n", ((PWLAN_IE_SSID)abyScanSSID)->abySSID,
((PWLAN_IE_SSID)abyScanSSID)->len);
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, abyScanSSID);
spin_unlock_irq(&pDevice->lock);
return 0;
} else if (req->scan_type == IW_SCAN_TYPE_PASSIVE) {
pMgmt->eScanType = WMAC_SCAN_PASSIVE;
}
} else {
pMgmt->eScanType = WMAC_SCAN_ACTIVE;
}
pMgmt->eScanType = WMAC_SCAN_PASSIVE;
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, NULL);
spin_unlock_irq(&pDevice->lock);
return 0;
}
int iwctl_giwscan(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
int ii, jj, kk;
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
PKnownBSS pBSS;
PWLAN_IE_SSID pItemSSID;
PWLAN_IE_SUPP_RATES pSuppRates, pExtSuppRates;
char *current_ev = extra;
char *end_buf = extra + IW_SCAN_MAX_DATA;
char *current_val = NULL;
struct iw_event iwe;
long ldBm;
char buf[MAX_WPA_IE_LEN * 2 + 30];
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWSCAN \n");
if (pMgmt->eScanState == WMAC_IS_SCANNING) {
return -EAGAIN;
}
pBSS = &(pMgmt->sBSSList[0]);
for (ii = 0, jj = 0; jj < MAX_BSS_NUM; jj++) {
if (current_ev >= end_buf)
break;
pBSS = &(pMgmt->sBSSList[jj]);
if (pBSS->bActive) {
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWAP;
iwe.u.ap_addr.sa_family = ARPHRD_ETHER;
memcpy(iwe.u.ap_addr.sa_data, pBSS->abyBSSID, WLAN_BSSID_LEN);
current_ev = iwe_stream_add_event(info, current_ev, end_buf, &iwe, IW_EV_ADDR_LEN);
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWESSID;
pItemSSID = (PWLAN_IE_SSID)pBSS->abySSID;
iwe.u.data.length = pItemSSID->len;
iwe.u.data.flags = 1;
current_ev = iwe_stream_add_point(info, current_ev, end_buf, &iwe, pItemSSID->abySSID);
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWMODE;
if (WLAN_GET_CAP_INFO_ESS(pBSS->wCapInfo)) {
iwe.u.mode = IW_MODE_INFRA;
} else {
iwe.u.mode = IW_MODE_ADHOC;
}
iwe.len = IW_EV_UINT_LEN;
current_ev = iwe_stream_add_event(info, current_ev, end_buf, &iwe, IW_EV_UINT_LEN);
pSuppRates = (PWLAN_IE_SUPP_RATES)pBSS->abySuppRates;
pExtSuppRates = (PWLAN_IE_SUPP_RATES)pBSS->abyExtSuppRates;
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWFREQ;
iwe.u.freq.m = pBSS->uChannel;
iwe.u.freq.e = 0;
iwe.u.freq.i = 0;
current_ev = iwe_stream_add_event(info, current_ev, end_buf, &iwe, IW_EV_FREQ_LEN);
{
int f = (int)pBSS->uChannel - 1;
if (f < 0)f = 0;
iwe.u.freq.m = frequency_list[f] * 100000;
iwe.u.freq.e = 1;
}
current_ev = iwe_stream_add_event(info, current_ev, end_buf, &iwe, IW_EV_FREQ_LEN);
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = IWEVQUAL;
RFvRSSITodBm(pDevice, (unsigned char)(pBSS->uRSSI), &ldBm);
iwe.u.qual.level = ldBm;
iwe.u.qual.noise = 0;
if (-ldBm < 50) {
iwe.u.qual.qual = 100;
} else if (-ldBm > 90) {
iwe.u.qual.qual = 0;
} else {
iwe.u.qual.qual = (40 - (-ldBm - 50)) * 100 / 40;
}
iwe.u.qual.updated = 7;
current_ev = iwe_stream_add_event(info, current_ev, end_buf, &iwe, IW_EV_QUAL_LEN);
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWENCODE;
iwe.u.data.length = 0;
if (WLAN_GET_CAP_INFO_PRIVACY(pBSS->wCapInfo)) {
iwe.u.data.flags = IW_ENCODE_ENABLED | IW_ENCODE_NOKEY;
} else {
iwe.u.data.flags = IW_ENCODE_DISABLED;
}
current_ev = iwe_stream_add_point(info, current_ev, end_buf, &iwe, pItemSSID->abySSID);
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = SIOCGIWRATE;
iwe.u.bitrate.fixed = iwe.u.bitrate.disabled = 0;
current_val = current_ev + IW_EV_LCP_LEN;
for (kk = 0; kk < 12; kk++) {
if (pSuppRates->abyRates[kk] == 0)
break;
iwe.u.bitrate.value = ((pSuppRates->abyRates[kk] & 0x7f) * 500000);
current_val = iwe_stream_add_value(info, current_ev, current_val, end_buf, &iwe, IW_EV_PARAM_LEN);
}
for (kk = 0; kk < 8; kk++) {
if (pExtSuppRates->abyRates[kk] == 0)
break;
iwe.u.bitrate.value = ((pExtSuppRates->abyRates[kk] & 0x7f) * 500000);
current_val = iwe_stream_add_value(info, current_ev, current_val, end_buf, &iwe, IW_EV_PARAM_LEN);
}
if ((current_val - current_ev) > IW_EV_LCP_LEN)
current_ev = current_val;
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = IWEVCUSTOM;
sprintf(buf, "bcn_int=%d", pBSS->wBeaconInterval);
iwe.u.data.length = strlen(buf);
current_ev = iwe_stream_add_point(info, current_ev, end_buf, &iwe, buf);
if ((pBSS->wWPALen > 0) && (pBSS->wWPALen <= MAX_WPA_IE_LEN)) {
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = IWEVGENIE;
iwe.u.data.length = pBSS->wWPALen;
current_ev = iwe_stream_add_point(info, current_ev, end_buf, &iwe, pBSS->byWPAIE);
}
if ((pBSS->wRSNLen > 0) && (pBSS->wRSNLen <= MAX_WPA_IE_LEN)) {
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = IWEVGENIE;
iwe.u.data.length = pBSS->wRSNLen;
current_ev = iwe_stream_add_point(info, current_ev, end_buf, &iwe, pBSS->byRSNIE);
}
}
}
wrq->length = current_ev - extra;
return 0;
}
int iwctl_siwfreq(struct net_device *dev,
struct iw_request_info *info,
struct iw_freq *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
int rc = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWFREQ \n");
if ((wrq->e == 1) &&
(wrq->m >= (int) 2.412e8) &&
(wrq->m <= (int) 2.487e8)) {
int f = wrq->m / 100000;
int c = 0;
while ((c < 14) && (f != frequency_list[c]))
c++;
wrq->e = 0;
wrq->m = c + 1;
}
if ((wrq->m > 14) || (wrq->e > 0))
rc = -EOPNOTSUPP;
else {
int channel = wrq->m;
if ((channel < 1) || (channel > 14)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "%s: New channel value of %d is invalid!\n", dev->name, wrq->m);
rc = -EINVAL;
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " Set to channel = %d\n", channel);
pDevice->uChannel = channel;
pDevice->bCommit = true;
}
}
return rc;
}
int iwctl_giwfreq(struct net_device *dev,
struct iw_request_info *info,
struct iw_freq *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWFREQ \n");
#ifdef WEXT_USECHANNELS
wrq->m = (int)pMgmt->uCurrChannel;
wrq->e = 0;
#else
{
int f = (int)pMgmt->uCurrChannel - 1;
if (f < 0)
f = 0;
wrq->m = frequency_list[f] * 100000;
wrq->e = 1;
}
#endif
return 0;
}
int iwctl_siwmode(struct net_device *dev,
struct iw_request_info *info,
__u32 *wmode,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
int rc = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWMODE \n");
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP && pDevice->bEnableHostapd) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Can't set operation mode, hostapd is running \n");
return rc;
}
switch (*wmode) {
case IW_MODE_ADHOC:
if (pMgmt->eConfigMode != WMAC_CONFIG_IBSS_STA) {
pMgmt->eConfigMode = WMAC_CONFIG_IBSS_STA;
if (pDevice->flags & DEVICE_FLAGS_OPENED) {
pDevice->bCommit = true;
}
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "set mode to ad-hoc \n");
break;
case IW_MODE_AUTO:
case IW_MODE_INFRA:
if (pMgmt->eConfigMode != WMAC_CONFIG_ESS_STA) {
pMgmt->eConfigMode = WMAC_CONFIG_ESS_STA;
if (pDevice->flags & DEVICE_FLAGS_OPENED) {
pDevice->bCommit = true;
}
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "set mode to infrastructure \n");
break;
case IW_MODE_MASTER:
pMgmt->eConfigMode = WMAC_CONFIG_ESS_STA;
rc = -EOPNOTSUPP;
break;
if (pMgmt->eConfigMode != WMAC_CONFIG_AP) {
pMgmt->eConfigMode = WMAC_CONFIG_AP;
if (pDevice->flags & DEVICE_FLAGS_OPENED) {
pDevice->bCommit = true;
}
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "set mode to Access Point \n");
break;
case IW_MODE_REPEAT:
pMgmt->eConfigMode = WMAC_CONFIG_ESS_STA;
rc = -EOPNOTSUPP;
break;
default:
rc = -EINVAL;
}
return rc;
}
int iwctl_giwmode(struct net_device *dev,
struct iw_request_info *info,
__u32 *wmode,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWMODE \n");
switch (pMgmt->eConfigMode) {
case WMAC_CONFIG_ESS_STA:
*wmode = IW_MODE_INFRA;
break;
case WMAC_CONFIG_IBSS_STA:
*wmode = IW_MODE_ADHOC;
break;
case WMAC_CONFIG_AUTO:
*wmode = IW_MODE_INFRA;
break;
case WMAC_CONFIG_AP:
*wmode = IW_MODE_MASTER;
break;
default:
*wmode = IW_MODE_ADHOC;
}
return 0;
}
int iwctl_giwrange(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
struct iw_range *range = (struct iw_range *)extra;
int i, k;
unsigned char abySupportedRates[13] = {0x02, 0x04, 0x0B, 0x16, 0x0c, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C, 0x90};
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWRANGE \n");
if (wrq->pointer) {
wrq->length = sizeof(struct iw_range);
memset(range, 0, sizeof(struct iw_range));
range->min_nwid = 0x0000;
range->max_nwid = 0x0000;
range->num_channels = 14;
k = 0;
for (i = 0; i < 14; i++) {
range->freq[k].i = i + 1;
range->freq[k].m = frequency_list[i] * 100000;
range->freq[k++].e = 1;
}
range->num_frequency = k;
#ifdef Calcu_LinkQual
range->max_qual.qual = 100;
#else
range->max_qual.qual = 255;
#endif
range->max_qual.level = 0;
range->max_qual.noise = 0;
range->sensitivity = 255;
for (i = 0; i < 13; i++) {
range->bitrate[i] = abySupportedRates[i] * 500000;
if (range->bitrate[i] == 0)
break;
}
range->num_bitrates = i;
if (i > 2)
range->throughput = 5 * 1000 * 1000;
else
range->throughput = 1.5 * 1000 * 1000;
range->min_rts = 0;
range->max_rts = 2312;
range->min_frag = 256;
range->max_frag = 2312;
range->num_encoding_sizes = 3;
range->encoding_size[0] = 5;
range->encoding_size[1] = 13;
range->encoding_size[2] = 32;
range->max_encoding_tokens = 4;
range->enc_capa = IW_ENC_CAPA_WPA | IW_ENC_CAPA_WPA2 |
IW_ENC_CAPA_CIPHER_TKIP | IW_ENC_CAPA_CIPHER_CCMP;
range->min_pmp = 0;
range->max_pmp = 1000000;
range->min_pmt = 0;
range->max_pmt = 1000000;
range->pmp_flags = IW_POWER_PERIOD;
range->pmt_flags = IW_POWER_TIMEOUT;
range->pm_capa = IW_POWER_PERIOD | IW_POWER_TIMEOUT | IW_POWER_ALL_R;
range->txpower[0] = 100;
range->num_txpower = 1;
range->txpower_capa = IW_TXPOW_MWATT;
range->we_version_source = SUPPORTED_WIRELESS_EXT;
range->we_version_compiled = WIRELESS_EXT;
range->retry_capa = IW_RETRY_LIMIT | IW_RETRY_LIFETIME;
range->retry_flags = IW_RETRY_LIMIT;
range->r_time_flags = IW_RETRY_LIFETIME;
range->min_retry = 1;
range->max_retry = 65535;
range->min_r_time = 1024;
range->max_r_time = 65535 * 1024;
range->avg_qual.qual = 6;
range->avg_qual.level = 176;
range->avg_qual.noise = 0;
}
return 0;
}
int iwctl_siwap(struct net_device *dev,
struct iw_request_info *info,
struct sockaddr *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
int rc = 0;
unsigned char ZeroBSSID[WLAN_BSSID_LEN] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWAP \n");
if (pMgmt->eScanState == WMAC_IS_SCANNING) {
printk("SIOCSIWAP(??)-->In scanning...\n");
}
if (wrq->sa_family != ARPHRD_ETHER)
rc = -EINVAL;
else {
memcpy(pMgmt->abyDesireBSSID, wrq->sa_data, 6);
if ((pDevice->bLinkPass == true) &&
(memcmp(pMgmt->abyDesireBSSID, pMgmt->abyCurrBSSID, 6) == 0)) {
return rc;
}
if ((is_broadcast_ether_addr(pMgmt->abyDesireBSSID)) ||
(memcmp(pMgmt->abyDesireBSSID, ZeroBSSID, 6) == 0)) {
PRINT_K("SIOCSIWAP:invalid desired BSSID return!\n");
return rc;
}
{
unsigned int ii, uSameBssidNum = 0;
for (ii = 0; ii < MAX_BSS_NUM; ii++) {
if (pMgmt->sBSSList[ii].bActive &&
ether_addr_equal(pMgmt->sBSSList[ii].abyBSSID,
pMgmt->abyDesireBSSID)) {
uSameBssidNum++;
}
}
if (uSameBssidNum >= 2) {
PRINT_K("SIOCSIWAP:ignore for desired AP in hidden mode\n");
return rc;
}
}
if (pDevice->flags & DEVICE_FLAGS_OPENED) {
pDevice->bCommit = true;
}
}
return rc;
}
int iwctl_giwap(struct net_device *dev,
struct iw_request_info *info,
struct sockaddr *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWAP \n");
memcpy(wrq->sa_data, pMgmt->abyCurrBSSID, 6);
if ((pDevice->bLinkPass == false) && (pMgmt->eCurrMode != WMAC_MODE_ESS_AP))
memset(wrq->sa_data, 0, 6);
if (pMgmt->eCurrMode == WMAC_MODE_ESS_AP) {
memcpy(wrq->sa_data, pMgmt->abyCurrBSSID, 6);
}
wrq->sa_family = ARPHRD_ETHER;
return 0;
}
int iwctl_giwaplist(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
int ii, jj, rc = 0;
struct sockaddr sock[IW_MAX_AP];
struct iw_quality qual[IW_MAX_AP];
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWAPLIST \n");
if (!capable(CAP_NET_ADMIN)) {
rc = -EPERM;
return rc;
}
if (wrq->pointer) {
PKnownBSS pBSS = &(pMgmt->sBSSList[0]);
for (ii = 0, jj = 0; ii < MAX_BSS_NUM; ii++) {
pBSS = &(pMgmt->sBSSList[ii]);
if (!pBSS->bActive)
continue;
if (jj >= IW_MAX_AP)
break;
memcpy(sock[jj].sa_data, pBSS->abyBSSID, 6);
sock[jj].sa_family = ARPHRD_ETHER;
qual[jj].level = pBSS->uRSSI;
qual[jj].qual = qual[jj].noise = 0;
qual[jj].updated = 2;
jj++;
}
wrq->flags = 1;
wrq->length = jj;
memcpy(extra, sock, sizeof(struct sockaddr)*jj);
memcpy(extra + sizeof(struct sockaddr)*jj, qual, sizeof(struct iw_quality)*jj);
}
return rc;
}
int iwctl_siwessid(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
PWLAN_IE_SSID pItemSSID;
unsigned char len;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWESSID \n");
pDevice->fWPA_Authened = false;
if (pMgmt->eScanState == WMAC_IS_SCANNING) {
printk("SIOCSIWESSID(??)-->In scanning...\n");
}
if (wrq->flags == 0) {
memset(pMgmt->abyDesireSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
memset(pMgmt->abyDesireBSSID, 0xFF, 6);
PRINT_K("set essid to 'any' \n");
#ifdef WPA_SUPPLICANT_DRIVER_WEXT_SUPPORT
return 0;
#endif
} else {
memset(pMgmt->abyDesireSSID, 0, WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1);
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyDesireSSID;
pItemSSID->byElementID = WLAN_EID_SSID;
memcpy(pItemSSID->abySSID, extra, wrq->length);
if (pItemSSID->abySSID[wrq->length - 1] == '\0') {
if (wrq->length > 0)
pItemSSID->len = wrq->length - 1;
} else
pItemSSID->len = wrq->length;
printk("set essid to %s \n", pItemSSID->abySSID);
len = (pItemSSID->len > ((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->len) ? pItemSSID->len : ((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->len;
if ((pDevice->bLinkPass == true) &&
(memcmp(pItemSSID->abySSID, ((PWLAN_IE_SSID)pMgmt->abyCurrSSID)->abySSID, len) == 0))
return 0;
if (pItemSSID->len == 0) {
memset(pMgmt->abyDesireBSSID, 0xFF, 6);
return 0;
}
#ifdef WPA_SUPPLICANT_DRIVER_WEXT_SUPPORT
if (pDevice->bWPASuppWextEnabled == true) {
{
PKnownBSS pCurr = NULL;
unsigned char abyTmpDesireSSID[WLAN_IEHDR_LEN + WLAN_SSID_MAXLEN + 1];
unsigned int ii, uSameBssidNum = 0;
memcpy(abyTmpDesireSSID, pMgmt->abyDesireSSID, sizeof(abyTmpDesireSSID));
pCurr = BSSpSearchBSSList(pDevice,
NULL,
abyTmpDesireSSID,
pMgmt->eConfigPHYMode
);
if (pCurr == NULL) {
PRINT_K("SIOCSIWESSID:hidden ssid site survey before associate.......\n");
vResetCommandTimer((void *)pDevice);
pMgmt->eScanType = WMAC_SCAN_ACTIVE;
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, pMgmt->abyDesireSSID);
bScheduleCommand((void *)pDevice, WLAN_CMD_SSID, pMgmt->abyDesireSSID);
} else {
for (ii = 0; ii < MAX_BSS_NUM; ii++) {
if (pMgmt->sBSSList[ii].bActive &&
ether_addr_equal(pMgmt->sBSSList[ii].abyBSSID,
pCurr->abyBSSID)) {
uSameBssidNum++;
}
}
if (uSameBssidNum >= 2) {
printk("SIOCSIWESSID:hidden ssid directly associate.......\n");
vResetCommandTimer((void *)pDevice);
pMgmt->eScanType = WMAC_SCAN_PASSIVE;
bScheduleCommand((void *)pDevice, WLAN_CMD_BSSID_SCAN, pMgmt->abyDesireSSID);
bScheduleCommand((void *)pDevice, WLAN_CMD_SSID, pMgmt->abyDesireSSID);
}
}
}
return 0;
}
#endif
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "set essid = %s \n", pItemSSID->abySSID);
}
if (pDevice->flags & DEVICE_FLAGS_OPENED) {
pDevice->bCommit = true;
}
return 0;
}
int iwctl_giwessid(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
PWLAN_IE_SSID pItemSSID;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWESSID \n");
pItemSSID = (PWLAN_IE_SSID)pMgmt->abyCurrSSID;
memcpy(extra, pItemSSID->abySSID , pItemSSID->len);
extra[pItemSSID->len] = '\0';
wrq->length = pItemSSID->len + 1;
wrq->length = pItemSSID->len;
wrq->flags = 1;
return 0;
}
int iwctl_siwrate(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
int rc = 0;
u8 brate = 0;
int i;
unsigned char abySupportedRates[13] = {0x02, 0x04, 0x0B, 0x16, 0x0c, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C, 0x90};
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWRATE \n");
if (!(pDevice->flags & DEVICE_FLAGS_OPENED)) {
rc = -EINVAL;
return rc;
}
if ((wrq->value < 13) &&
(wrq->value >= 0)) {
brate = wrq->value;
} else {
u8 normvalue = (u8) (wrq->value/500000);
for (i = 0; i < 13; i++) {
if (normvalue == abySupportedRates[i]) {
brate = i;
break;
}
}
}
if (wrq->value == -1) {
for (i = 0; i < 13; i++) {
if (abySupportedRates[i] == 0)
break;
}
if (i != 0)
brate = i - 1;
}
if (brate > 13) {
rc = -EINVAL;
return rc;
}
if (wrq->fixed != 0) {
printk("Rate Fix\n");
pDevice->bFixRate = true;
if ((pDevice->byBBType == BB_TYPE_11B) && (brate > 3)) {
pDevice->uConnectionRate = 3;
} else {
pDevice->uConnectionRate = brate;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Fixed to Rate %d \n", pDevice->uConnectionRate);
}
} else {
pDevice->bFixRate = false;
pDevice->uConnectionRate = 13;
printk("auto rate:connection_rate is 13\n");
}
return rc;
}
int iwctl_giwrate(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWRATE \n");
{
unsigned char abySupportedRates[13] = {0x02, 0x04, 0x0B, 0x16, 0x0c, 0x12, 0x18, 0x24, 0x30, 0x48, 0x60, 0x6C, 0x90};
int brate = 0;
if (pDevice->bLinkPass) {
if (pDevice->bFixRate == true) {
if (pDevice->uConnectionRate < 13) {
brate = abySupportedRates[pDevice->uConnectionRate];
} else {
if (pDevice->byBBType == BB_TYPE_11B)
brate = 0x16;
if (pDevice->byBBType == BB_TYPE_11G)
brate = 0x6C;
if (pDevice->byBBType == BB_TYPE_11A)
brate = 0x6C;
}
} else {
brate = abySupportedRates[TxRate_iwconfig];
}
} else brate = 0;
wrq->value = brate * 500000;
if (pDevice->bFixRate == true)
wrq->fixed = true;
}
return 0;
}
int iwctl_siwrts(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
int rc = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWRTS \n");
{
int rthr = wrq->value;
if (wrq->disabled)
rthr = 2312;
if ((rthr < 0) || (rthr > 2312)) {
rc = -EINVAL;
} else {
pDevice->wRTSThreshold = rthr;
}
}
return 0;
}
int iwctl_giwrts(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWRTS \n");
wrq->value = pDevice->wRTSThreshold;
wrq->disabled = (wrq->value >= 2312);
wrq->fixed = 1;
return 0;
}
int iwctl_siwfrag(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
int rc = 0;
int fthr = wrq->value;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWFRAG \n");
if (wrq->disabled)
fthr = 2312;
if ((fthr < 256) || (fthr > 2312)) {
rc = -EINVAL;
} else {
fthr &= ~0x1;
pDevice->wFragmentationThreshold = (u16)fthr;
}
return rc;
}
int iwctl_giwfrag(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWFRAG \n");
wrq->value = pDevice->wFragmentationThreshold;
wrq->disabled = (wrq->value >= 2312);
wrq->fixed = 1;
return 0;
}
int iwctl_siwretry(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
int rc = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWRETRY \n");
if (wrq->disabled) {
rc = -EINVAL;
return rc;
}
if (wrq->flags & IW_RETRY_LIMIT) {
if (wrq->flags & IW_RETRY_MAX)
pDevice->byLongRetryLimit = wrq->value;
else if (wrq->flags & IW_RETRY_MIN)
pDevice->byShortRetryLimit = wrq->value;
else {
pDevice->byShortRetryLimit = wrq->value;
pDevice->byLongRetryLimit = wrq->value;
}
}
if (wrq->flags & IW_RETRY_LIFETIME) {
pDevice->wMaxTransmitMSDULifetime = wrq->value;
}
return rc;
}
int iwctl_giwretry(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWRETRY \n");
wrq->disabled = 0;
if ((wrq->flags & IW_RETRY_TYPE) == IW_RETRY_LIFETIME) {
wrq->flags = IW_RETRY_LIFETIME;
wrq->value = (int)pDevice->wMaxTransmitMSDULifetime;
} else if ((wrq->flags & IW_RETRY_MAX)) {
wrq->flags = IW_RETRY_LIMIT | IW_RETRY_MAX;
wrq->value = (int)pDevice->byLongRetryLimit;
} else {
wrq->flags = IW_RETRY_LIMIT;
wrq->value = (int)pDevice->byShortRetryLimit;
if ((int)pDevice->byShortRetryLimit != (int)pDevice->byLongRetryLimit)
wrq->flags |= IW_RETRY_MIN;
}
return 0;
}
int iwctl_siwencode(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
unsigned long dwKeyIndex = (unsigned long)(wrq->flags & IW_ENCODE_INDEX);
int ii, uu, rc = 0;
int index = (wrq->flags & IW_ENCODE_INDEX);
PSKeyTable pkeytab;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWENCODE \n");
if ((wrq->flags & IW_ENCODE_DISABLED) == 0) {
if (dwKeyIndex > WLAN_WEP_NKEYS) {
rc = -EINVAL;
return rc;
}
if (dwKeyIndex < 1 && ((wrq->flags & IW_ENCODE_NOKEY) == 0)) {
if (pDevice->byKeyIndex < WLAN_WEP_NKEYS) {
dwKeyIndex = pDevice->byKeyIndex;
} else dwKeyIndex = 0;
} else dwKeyIndex--;
if (wrq->length > WLAN_WEP232_KEYLEN) {
rc = -EINVAL;
return rc;
}
if (wrq->length > 0) {
if (wrq->length == WLAN_WEP232_KEYLEN) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Set 232 bit wep key\n");
} else if (wrq->length == WLAN_WEP104_KEYLEN) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Set 104 bit wep key\n");
} else if (wrq->length == WLAN_WEP40_KEYLEN) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Set 40 bit wep key, index= %d\n", (int)dwKeyIndex);
} else {
rc = -EINVAL;
return rc;
}
memset(pDevice->abyKey, 0, WLAN_WEP232_KEYLEN);
memcpy(pDevice->abyKey, extra, wrq->length);
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "abyKey: ");
for (ii = 0; ii < wrq->length; ii++) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "%02x ", pDevice->abyKey[ii]);
}
if (pDevice->flags & DEVICE_FLAGS_OPENED) {
spin_lock_irq(&pDevice->lock);
KeybSetDefaultKey(&(pDevice->sKey),
(unsigned long)(dwKeyIndex | (1 << 31)),
wrq->length,
NULL,
pDevice->abyKey,
KEY_CTL_WEP,
pDevice->PortOffset,
pDevice->byLocalID
);
spin_unlock_irq(&pDevice->lock);
}
pDevice->byKeyIndex = (unsigned char)dwKeyIndex;
pDevice->uKeyLength = wrq->length;
pDevice->bTransmitKey = true;
pDevice->bEncryptionEnable = true;
pDevice->eEncryptionStatus = Ndis802_11Encryption1Enabled;
} else if (index > 0) {
if (pDevice->bEncryptionEnable == false) {
rc = -EINVAL;
return rc;
}
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Just set Default key Index:\n");
pkeytab = &(pDevice->sKey.KeyTable[MAX_KEY_TABLE - 1]);
if (pkeytab->GroupKey[(unsigned char)dwKeyIndex].uKeyLength == 0) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Default key len is 0\n");
rc = -EINVAL;
return rc;
}
pDevice->byKeyIndex = (unsigned char)dwKeyIndex;
pkeytab->dwGTKeyIndex = dwKeyIndex | (1 << 31);
pkeytab->GroupKey[(unsigned char)dwKeyIndex].dwKeyIndex = dwKeyIndex | (1 << 31);
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Disable WEP function\n");
if (pDevice->bEncryptionEnable == false)
return 0;
pMgmt->bShareKeyAlgorithm = false;
pDevice->bEncryptionEnable = false;
pDevice->eEncryptionStatus = Ndis802_11EncryptionDisabled;
if (pDevice->flags & DEVICE_FLAGS_OPENED) {
spin_lock_irq(&pDevice->lock);
for (uu = 0; uu < MAX_KEY_TABLE; uu++)
MACvDisableKeyEntry(pDevice->PortOffset, uu);
spin_unlock_irq(&pDevice->lock);
}
}
if (wrq->flags & IW_ENCODE_RESTRICTED) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Enable WEP & ShareKey System\n");
pMgmt->bShareKeyAlgorithm = true;
}
if (wrq->flags & IW_ENCODE_OPEN) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Enable WEP & Open System\n");
pMgmt->bShareKeyAlgorithm = false;
}
return rc;
}
int iwctl_giwencode(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
char abyKey[WLAN_WEP232_KEYLEN];
unsigned int index = (unsigned int)(wrq->flags & IW_ENCODE_INDEX);
PSKeyItem pKey = NULL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWENCODE\n");
if (index > WLAN_WEP_NKEYS) {
return -EINVAL;
}
if (index < 1) {
if (pDevice->byKeyIndex < WLAN_WEP_NKEYS) {
index = pDevice->byKeyIndex;
} else
index = 0;
} else
index--;
memset(abyKey, 0, WLAN_WEP232_KEYLEN);
wrq->flags = IW_ENCODE_NOKEY;
if (pDevice->bEncryptionEnable)
wrq->flags |= IW_ENCODE_ENABLED;
else
wrq->flags |= IW_ENCODE_DISABLED;
if (pMgmt->bShareKeyAlgorithm)
wrq->flags |= IW_ENCODE_RESTRICTED;
else
wrq->flags |= IW_ENCODE_OPEN;
wrq->length = 0;
if ((index == 0) && (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled ||
pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled)) {
if (KeybGetKey(&(pDevice->sKey), pMgmt->abyCurrBSSID, 0xffffffff, &pKey)) {
wrq->length = pKey->uKeyLength;
memcpy(abyKey, pKey->abyKey, pKey->uKeyLength);
memcpy(extra, abyKey, WLAN_WEP232_KEYLEN);
}
} else if (KeybGetKey(&(pDevice->sKey), pDevice->abyBroadcastAddr, (unsigned char)index , &pKey)) {
wrq->length = pKey->uKeyLength;
memcpy(abyKey, pKey->abyKey, pKey->uKeyLength);
memcpy(extra, abyKey, WLAN_WEP232_KEYLEN);
}
wrq->flags |= index+1;
return 0;
}
int iwctl_siwpower(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
int rc = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWPOWER \n");
if (!(pDevice->flags & DEVICE_FLAGS_OPENED)) {
rc = -EINVAL;
return rc;
}
if (wrq->disabled) {
pDevice->ePSMode = WMAC_POWER_CAM;
PSvDisablePowerSaving(pDevice);
return rc;
}
if ((wrq->flags & IW_POWER_TYPE) == IW_POWER_TIMEOUT) {
pDevice->ePSMode = WMAC_POWER_FAST;
PSvEnablePowerSaving((void *)pDevice, pMgmt->wListenInterval);
} else if ((wrq->flags & IW_POWER_TYPE) == IW_POWER_PERIOD) {
pDevice->ePSMode = WMAC_POWER_FAST;
PSvEnablePowerSaving((void *)pDevice, pMgmt->wListenInterval);
}
switch (wrq->flags & IW_POWER_MODE) {
case IW_POWER_UNICAST_R:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWPOWER: IW_POWER_UNICAST_R \n");
rc = -EINVAL;
break;
case IW_POWER_ALL_R:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWPOWER: IW_POWER_ALL_R \n");
rc = -EINVAL;
case IW_POWER_ON:
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWPOWER: IW_POWER_ON \n");
break;
default:
rc = -EINVAL;
}
return rc;
}
int iwctl_giwpower(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
int mode = pDevice->ePSMode;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWPOWER \n");
wrq->disabled = (mode == WMAC_POWER_CAM);
if (wrq->disabled)
return 0;
if ((wrq->flags & IW_POWER_TYPE) == IW_POWER_TIMEOUT) {
wrq->value = (int)((pMgmt->wListenInterval * pMgmt->wCurrBeaconPeriod) << 10);
wrq->flags = IW_POWER_TIMEOUT;
} else {
wrq->value = (int)((pMgmt->wListenInterval * pMgmt->wCurrBeaconPeriod) << 10);
wrq->flags = IW_POWER_PERIOD;
}
wrq->flags |= IW_POWER_ALL_R;
return 0;
}
int iwctl_giwsens(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
long ldBm;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCGIWSENS \n");
if (pDevice->bLinkPass == true) {
RFvRSSITodBm(pDevice, (unsigned char)(pDevice->uCurrRSSI), &ldBm);
wrq->value = ldBm;
} else {
wrq->value = 0;
}
wrq->disabled = (wrq->value == 0);
wrq->fixed = 1;
return 0;
}
int iwctl_siwauth(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
int ret = 0;
static int wpa_version = 0;
static int pairwise = 0;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO " SIOCSIWAUTH \n");
switch (wrq->flags & IW_AUTH_INDEX) {
case IW_AUTH_WPA_VERSION:
wpa_version = wrq->value;
if (wrq->value == IW_AUTH_WPA_VERSION_DISABLED) {
PRINT_K("iwctl_siwauth:set WPADEV to disable at 1??????\n");
} else if (wrq->value == IW_AUTH_WPA_VERSION_WPA) {
PRINT_K("iwctl_siwauth:set WPADEV to WPA1******\n");
} else {
PRINT_K("iwctl_siwauth:set WPADEV to WPA2******\n");
}
break;
case IW_AUTH_CIPHER_PAIRWISE:
pairwise = wrq->value;
if (pairwise == IW_AUTH_CIPHER_CCMP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption3Enabled;
} else if (pairwise == IW_AUTH_CIPHER_TKIP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption2Enabled;
} else if (pairwise == IW_AUTH_CIPHER_WEP40 || pairwise == IW_AUTH_CIPHER_WEP104) {
pDevice->eEncryptionStatus = Ndis802_11Encryption1Enabled;
} else if (pairwise == IW_AUTH_CIPHER_NONE) {
} else pDevice->eEncryptionStatus = Ndis802_11EncryptionDisabled;
break;
case IW_AUTH_CIPHER_GROUP:
if (wpa_version == IW_AUTH_WPA_VERSION_DISABLED)
break;
if (pairwise == IW_AUTH_CIPHER_NONE) {
if (wrq->value == IW_AUTH_CIPHER_CCMP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption3Enabled;
} else {
pDevice->eEncryptionStatus = Ndis802_11Encryption2Enabled;
}
}
break;
case IW_AUTH_KEY_MGMT:
if (wpa_version == IW_AUTH_WPA_VERSION_WPA2) {
if (wrq->value == IW_AUTH_KEY_MGMT_PSK)
pMgmt->eAuthenMode = WMAC_AUTH_WPA2PSK;
else pMgmt->eAuthenMode = WMAC_AUTH_WPA2;
} else if (wpa_version == IW_AUTH_WPA_VERSION_WPA) {
if (wrq->value == 0) {
pMgmt->eAuthenMode = WMAC_AUTH_WPANONE;
} else if (wrq->value == IW_AUTH_KEY_MGMT_PSK)
pMgmt->eAuthenMode = WMAC_AUTH_WPAPSK;
else pMgmt->eAuthenMode = WMAC_AUTH_WPA;
}
break;
case IW_AUTH_TKIP_COUNTERMEASURES:
break;
case IW_AUTH_DROP_UNENCRYPTED:
break;
case IW_AUTH_80211_AUTH_ALG:
if (wrq->value == IW_AUTH_ALG_OPEN_SYSTEM) {
pMgmt->bShareKeyAlgorithm = false;
} else if (wrq->value == IW_AUTH_ALG_SHARED_KEY) {
pMgmt->bShareKeyAlgorithm = true;
}
break;
case IW_AUTH_WPA_ENABLED:
break;
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
break;
case IW_AUTH_ROAMING_CONTROL:
ret = -EOPNOTSUPP;
break;
case IW_AUTH_PRIVACY_INVOKED:
pDevice->bEncryptionEnable = !!wrq->value;
if (pDevice->bEncryptionEnable == false) {
wpa_version = 0;
pairwise = 0;
pDevice->eEncryptionStatus = Ndis802_11EncryptionDisabled;
pMgmt->bShareKeyAlgorithm = false;
pMgmt->eAuthenMode = false;
}
break;
default:
ret = -EOPNOTSUPP;
break;
}
return ret;
}
int iwctl_giwauth(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrq,
char *extra)
{
return -EOPNOTSUPP;
}
int iwctl_siwgenie(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
int ret = 0;
if (wrq->length) {
if ((wrq->length < 2) || (extra[1]+2 != wrq->length)) {
ret = -EINVAL;
goto out;
}
if (wrq->length > MAX_WPA_IE_LEN) {
ret = -ENOMEM;
goto out;
}
memset(pMgmt->abyWPAIE, 0, MAX_WPA_IE_LEN);
if (copy_from_user(pMgmt->abyWPAIE, extra, wrq->length)) {
ret = -EFAULT;
goto out;
}
pMgmt->wWPAIELen = wrq->length;
} else {
memset(pMgmt->abyWPAIE, 0, MAX_WPA_IE_LEN);
pMgmt->wWPAIELen = 0;
}
out:
return ret;
}
int iwctl_giwgenie(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
int ret = 0;
int space = wrq->length;
wrq->length = 0;
if (pMgmt->wWPAIELen > 0) {
wrq->length = pMgmt->wWPAIELen;
if (pMgmt->wWPAIELen <= space) {
if (copy_to_user(extra, pMgmt->abyWPAIE, pMgmt->wWPAIELen)) {
ret = -EFAULT;
}
} else
ret = -E2BIG;
}
return ret;
}
int iwctl_siwencodeext(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
struct viawget_wpa_param *param = NULL;
enum wpa_alg alg_name;
u8 addr[6];
int key_idx, set_tx = 0;
u8 seq[IW_ENCODE_SEQ_MAX_SIZE];
u8 key[64];
size_t seq_len = 0, key_len = 0;
u8 *buf;
size_t blen;
u8 key_array[64];
int ret = 0;
PRINT_K("SIOCSIWENCODEEXT...... \n");
blen = sizeof(*param);
buf = kmalloc((int)blen, (int)GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
memset(buf, 0, blen);
param = (struct viawget_wpa_param *)buf;
switch (ext->alg) {
case IW_ENCODE_ALG_NONE:
alg_name = WPA_ALG_NONE;
break;
case IW_ENCODE_ALG_WEP:
alg_name = WPA_ALG_WEP;
break;
case IW_ENCODE_ALG_TKIP:
alg_name = WPA_ALG_TKIP;
break;
case IW_ENCODE_ALG_CCMP:
alg_name = WPA_ALG_CCMP;
break;
default:
PRINT_K("Unknown alg = %d\n", ext->alg);
ret = -ENOMEM;
goto error;
}
memcpy(addr, ext->addr.sa_data, ETH_ALEN);
key_idx = (wrq->flags&IW_ENCODE_INDEX) - 1;
if (ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY)
set_tx = 1;
if (ext->ext_flags & IW_ENCODE_EXT_RX_SEQ_VALID) {
seq_len = IW_ENCODE_SEQ_MAX_SIZE;
memcpy(seq, ext->rx_seq, seq_len);
}
if (ext->key_len) {
key_len = ext->key_len;
memcpy(key, &ext->key[0], key_len);
}
memset(key_array, 0, 64);
if (key_len > 0) {
memcpy(key_array, key, key_len);
if (key_len == 32) {
memcpy(&key_array[16], &key[24], 8);
memcpy(&key_array[24], &key[16], 8);
}
}
memcpy(param->addr, addr, ETH_ALEN);
param->u.wpa_key.alg_name = (int)alg_name;
param->u.wpa_key.set_tx = set_tx;
param->u.wpa_key.key_index = key_idx;
param->u.wpa_key.key_len = key_len;
param->u.wpa_key.key = (u8 *)key_array;
param->u.wpa_key.seq = (u8 *)seq;
param->u.wpa_key.seq_len = seq_len;
if (param->u.wpa_key.alg_name == WPA_ALG_NONE) {
if (param->u.wpa_key.key_index == 0) {
pDevice->bwextcount++;
}
if ((pDevice->bwextcount == 1) && (param->u.wpa_key.key_index == 1)) {
pDevice->bwextcount++;
}
if ((pDevice->bwextcount == 2) && (param->u.wpa_key.key_index == 2)) {
pDevice->bwextcount++;
}
if ((pDevice->bwextcount == 3) && (param->u.wpa_key.key_index == 3)) {
pDevice->bwextcount++;
}
}
if (pDevice->bwextcount == 4) {
printk("SIOCSIWENCODEEXT:Enable WPA WEXT SUPPORT!!!!!\n");
pDevice->bwextcount = 0;
pDevice->bWPASuppWextEnabled = true;
}
spin_lock_irq(&pDevice->lock);
ret = wpa_set_keys(pDevice, param, true);
spin_unlock_irq(&pDevice->lock);
error:
kfree(param);
return ret;
}
int iwctl_giwencodeext(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
return -EOPNOTSUPP;
}
int iwctl_siwmlme(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *wrq,
char *extra)
{
PSDevice pDevice = (PSDevice)netdev_priv(dev);
PSMgmtObject pMgmt = &(pDevice->sMgmtObj);
struct iw_mlme *mlme = (struct iw_mlme *)extra;
int ret = 0;
if (memcmp(pMgmt->abyCurrBSSID, mlme->addr.sa_data, ETH_ALEN)) {
ret = -EINVAL;
return ret;
}
switch (mlme->cmd) {
case IW_MLME_DEAUTH:
break;
case IW_MLME_DISASSOC:
if (pDevice->bLinkPass == true) {
printk("iwctl_siwmlme--->send DISASSOCIATE\n");
memset(pMgmt->abyDesireBSSID, 0xFF, 6);
KeyvInitTable(&pDevice->sKey, pDevice->PortOffset);
bScheduleCommand((void *)pDevice, WLAN_CMD_DISASSOCIATE, NULL);
}
break;
default:
ret = -EOPNOTSUPP;
}
return ret;
}
