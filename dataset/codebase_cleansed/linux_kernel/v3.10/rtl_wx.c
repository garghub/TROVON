static int r8192_wx_get_freq(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_freq(priv->rtllib, a, wrqu, b);
}
static int r8192_wx_get_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_mode(priv->rtllib, a, wrqu, b);
}
static int r8192_wx_get_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_rate(priv->rtllib, info, wrqu, extra);
}
static int r8192_wx_set_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_rate(priv->rtllib, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_rts(priv->rtllib, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_rts(priv->rtllib, info, wrqu, extra);
}
static int r8192_wx_set_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true) {
RT_TRACE(COMP_ERR, "%s():Hw is Radio Off, we can't set "
"Power,return\n", __func__);
return 0;
}
down(&priv->wx_sem);
ret = rtllib_wx_set_power(priv->rtllib, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_power(priv->rtllib, info, wrqu, extra);
}
static int r8192_wx_set_rawtx(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
int ret;
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_rawtx(priv->rtllib, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_force_reset(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
down(&priv->wx_sem);
RT_TRACE(COMP_DBG, "%s(): force reset ! extra is %d\n",
__func__, *extra);
priv->force_reset = *extra;
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_force_mic_error(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = priv->rtllib;
down(&priv->wx_sem);
RT_TRACE(COMP_DBG, "%s(): force mic error !\n", __func__);
ieee->force_mic_error = true;
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_get_adhoc_peers(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
return 0;
}
static int r8191se_wx_get_firm_version(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *wrqu, char *extra)
{
return 0;
}
static int r8192_wx_adapter_power_status(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rt_pwr_save_ctrl *pPSC = (struct rt_pwr_save_ctrl *)
(&(priv->rtllib->PowerSaveControl));
struct rtllib_device *ieee = priv->rtllib;
down(&priv->wx_sem);
RT_TRACE(COMP_POWER, "%s(): %s\n", __func__, (*extra == 6) ?
"DC power" : "AC power");
if (*extra || priv->force_lps) {
priv->ps_force = false;
pPSC->bLeisurePs = true;
} else {
if (priv->rtllib->state == RTLLIB_LINKED)
LeisurePSLeave(dev);
priv->ps_force = true;
pPSC->bLeisurePs = false;
ieee->ps = *extra;
}
up(&priv->wx_sem);
return 0;
}
static int r8192se_wx_set_radio(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
down(&priv->wx_sem);
printk(KERN_INFO "%s(): set radio ! extra is %d\n", __func__, *extra);
if ((*extra != 0) && (*extra != 1)) {
RT_TRACE(COMP_ERR, "%s(): set radio an err value,must 0(radio "
"off) or 1(radio on)\n", __func__);
up(&priv->wx_sem);
return -1;
}
priv->sw_radio_on = *extra;
up(&priv->wx_sem);
return 0;
}
static int r8192se_wx_set_lps_awake_interval(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rt_pwr_save_ctrl *pPSC = (struct rt_pwr_save_ctrl *)
(&(priv->rtllib->PowerSaveControl));
down(&priv->wx_sem);
printk(KERN_INFO "%s(): set lps awake interval ! extra is %d\n",
__func__, *extra);
pPSC->RegMaxLPSAwakeIntvl = *extra;
up(&priv->wx_sem);
return 0;
}
static int r8192se_wx_set_force_lps(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
down(&priv->wx_sem);
printk(KERN_INFO "%s(): force LPS ! extra is %d (1 is open 0 is "
"close)\n", __func__, *extra);
priv->force_lps = *extra;
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_set_debugflag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
u8 c = *extra;
if (priv->bHwRadioOff == true)
return 0;
printk(KERN_INFO "=====>%s(), *extra:%x, debugflag:%x\n", __func__,
*extra, rt_global_debug_component);
if (c > 0)
rt_global_debug_component |= (1<<c);
else
rt_global_debug_component &= BIT31;
return 0;
}
static int r8192_wx_set_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = netdev_priv_rsl(dev);
enum rt_rf_power_state rtState;
int ret;
if (priv->bHwRadioOff == true)
return 0;
rtState = priv->rtllib->eRFPowerState;
down(&priv->wx_sem);
if (wrqu->mode == IW_MODE_ADHOC || wrqu->mode == IW_MODE_MONITOR ||
ieee->bNetPromiscuousMode) {
if (priv->rtllib->PowerSaveControl.bInactivePs) {
if (rtState == eRfOff) {
if (priv->rtllib->RfOffReason >
RF_CHANGE_BY_IPS) {
RT_TRACE(COMP_ERR, "%s(): RF is OFF.\n",
__func__);
up(&priv->wx_sem);
return -1;
} else {
printk(KERN_INFO "=========>%s(): "
"IPSLeave\n", __func__);
down(&priv->rtllib->ips_sem);
IPSLeave(dev);
up(&priv->rtllib->ips_sem);
}
}
}
}
ret = rtllib_wx_set_mode(priv->rtllib, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int rtl8192_wx_get_range(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct iw_range *range = (struct iw_range *)extra;
struct r8192_priv *priv = rtllib_priv(dev);
u16 val;
int i;
wrqu->data.length = sizeof(*range);
memset(range, 0, sizeof(*range));
range->throughput = 130 * 1000 * 1000;
if (priv->rf_set_sens != NULL) {
range->sensitivity = priv->max_sens;
}
range->max_qual.qual = 100;
range->max_qual.level = 0;
range->max_qual.noise = 0;
range->max_qual.updated = 7;
range->avg_qual.qual = 70;
range->avg_qual.level = 0;
range->avg_qual.noise = 0;
range->avg_qual.updated = 7;
range->num_bitrates = min(RATE_COUNT, IW_MAX_BITRATES);
for (i = 0; i < range->num_bitrates; i++)
range->bitrate[i] = rtl8192_rates[i];
range->max_rts = DEFAULT_RTS_THRESHOLD;
range->min_frag = MIN_FRAG_THRESHOLD;
range->max_frag = MAX_FRAG_THRESHOLD;
range->min_pmp = 0;
range->max_pmp = 5000000;
range->min_pmt = 0;
range->max_pmt = 65535*1000;
range->pmp_flags = IW_POWER_PERIOD;
range->pmt_flags = IW_POWER_TIMEOUT;
range->pm_capa = IW_POWER_PERIOD | IW_POWER_TIMEOUT | IW_POWER_ALL_R;
range->we_version_compiled = WIRELESS_EXT;
range->we_version_source = 18;
for (i = 0, val = 0; i < 14; i++) {
if ((priv->rtllib->active_channel_map)[i+1]) {
range->freq[val].i = i + 1;
range->freq[val].m = rtllib_wlan_frequencies[i] *
100000;
range->freq[val].e = 1;
val++;
}
if (val == IW_MAX_FREQUENCIES)
break;
}
range->num_frequency = val;
range->num_channels = val;
range->enc_capa = IW_ENC_CAPA_WPA|IW_ENC_CAPA_WPA2|
IW_ENC_CAPA_CIPHER_TKIP|IW_ENC_CAPA_CIPHER_CCMP;
range->scan_capa = IW_SCAN_CAPA_ESSID | IW_SCAN_CAPA_TYPE;
return 0;
}
static int r8192_wx_set_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = priv->rtllib;
enum rt_rf_power_state rtState;
int ret;
if (!(ieee->softmac_features & IEEE_SOFTMAC_SCAN)) {
if ((ieee->state >= RTLLIB_ASSOCIATING) &&
(ieee->state <= RTLLIB_ASSOCIATING_AUTHENTICATED))
return 0;
if ((priv->rtllib->state == RTLLIB_LINKED) &&
(priv->rtllib->CntAfterLink < 2))
return 0;
}
if (priv->bHwRadioOff == true) {
printk(KERN_INFO "================>%s(): hwradio off\n",
__func__);
return 0;
}
rtState = priv->rtllib->eRFPowerState;
if (!priv->up)
return -ENETDOWN;
if (priv->rtllib->LinkDetectInfo.bBusyTraffic == true)
return -EAGAIN;
if (wrqu->data.flags & IW_SCAN_THIS_ESSID) {
struct iw_scan_req *req = (struct iw_scan_req *)b;
if (req->essid_len) {
ieee->current_network.ssid_len = req->essid_len;
memcpy(ieee->current_network.ssid, req->essid,
req->essid_len);
}
}
down(&priv->wx_sem);
priv->rtllib->FirstIe_InScan = true;
if (priv->rtllib->state != RTLLIB_LINKED) {
if (priv->rtllib->PowerSaveControl.bInactivePs) {
if (rtState == eRfOff) {
if (priv->rtllib->RfOffReason >
RF_CHANGE_BY_IPS) {
RT_TRACE(COMP_ERR, "%s(): RF is "
"OFF.\n", __func__);
up(&priv->wx_sem);
return -1;
} else {
RT_TRACE(COMP_PS, "=========>%s(): "
"IPSLeave\n", __func__);
down(&priv->rtllib->ips_sem);
IPSLeave(dev);
up(&priv->rtllib->ips_sem);
}
}
}
rtllib_stop_scan(priv->rtllib);
if (priv->rtllib->LedControlHandler)
priv->rtllib->LedControlHandler(dev,
LED_CTL_SITE_SURVEY);
if (priv->rtllib->eRFPowerState != eRfOff) {
priv->rtllib->actscanning = true;
if (ieee->ScanOperationBackupHandler)
ieee->ScanOperationBackupHandler(ieee->dev,
SCAN_OPT_BACKUP);
rtllib_start_scan_syncro(priv->rtllib, 0);
if (ieee->ScanOperationBackupHandler)
ieee->ScanOperationBackupHandler(ieee->dev,
SCAN_OPT_RESTORE);
}
ret = 0;
} else {
priv->rtllib->actscanning = true;
ret = rtllib_wx_set_scan(priv->rtllib, a, wrqu, b);
}
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = rtllib_priv(dev);
if (!priv->up)
return -ENETDOWN;
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_get_scan(priv->rtllib, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = rtllib_priv(dev);
int ret;
if ((rtllib_act_scanning(priv->rtllib, false)) &&
!(priv->rtllib->softmac_features & IEEE_SOFTMAC_SCAN)) {
;
}
if (priv->bHwRadioOff == true) {
printk(KERN_INFO "=========>%s():hw radio off,or Rf state is "
"eRfOff, return\n", __func__);
return 0;
}
down(&priv->wx_sem);
ret = rtllib_wx_set_essid(priv->rtllib, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = rtllib_priv(dev);
down(&priv->wx_sem);
ret = rtllib_wx_get_essid(priv->rtllib, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_nick(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
if (wrqu->data.length > IW_ESSID_MAX_SIZE)
return -E2BIG;
down(&priv->wx_sem);
wrqu->data.length = min((size_t) wrqu->data.length, sizeof(priv->nick));
memset(priv->nick, 0, sizeof(priv->nick));
memcpy(priv->nick, extra, wrqu->data.length);
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_get_nick(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
down(&priv->wx_sem);
wrqu->data.length = strlen(priv->nick);
memcpy(extra, priv->nick, wrqu->data.length);
wrqu->data.flags = 1;
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_set_freq(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_freq(priv->rtllib, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_name(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_name(priv->rtllib, info, wrqu, extra);
}
static int r8192_wx_set_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true)
return 0;
if (wrqu->frag.disabled)
priv->rtllib->fts = DEFAULT_FRAG_THRESHOLD;
else {
if (wrqu->frag.value < MIN_FRAG_THRESHOLD ||
wrqu->frag.value > MAX_FRAG_THRESHOLD)
return -EINVAL;
priv->rtllib->fts = wrqu->frag.value & ~0x1;
}
return 0;
}
static int r8192_wx_get_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
wrqu->frag.value = priv->rtllib->fts;
wrqu->frag.fixed = 0;
wrqu->frag.disabled = (wrqu->frag.value == DEFAULT_FRAG_THRESHOLD);
return 0;
}
static int r8192_wx_set_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *awrq,
char *extra)
{
int ret;
struct r8192_priv *priv = rtllib_priv(dev);
if ((rtllib_act_scanning(priv->rtllib, false)) &&
!(priv->rtllib->softmac_features & IEEE_SOFTMAC_SCAN)) {
;
}
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_wap(priv->rtllib, info, awrq, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_wap(priv->rtllib, info, wrqu, extra);
}
static int r8192_wx_get_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8192_priv *priv = rtllib_priv(dev);
return rtllib_wx_get_encode(priv->rtllib, info, wrqu, key);
}
static int r8192_wx_set_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8192_priv *priv = rtllib_priv(dev);
int ret;
struct rtllib_device *ieee = priv->rtllib;
u32 hwkey[4] = {0, 0, 0, 0};
u8 mask = 0xff;
u32 key_idx = 0;
u8 zero_addr[4][6] = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x02},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x03} };
int i;
if ((rtllib_act_scanning(priv->rtllib, false)) &&
!(priv->rtllib->softmac_features & IEEE_SOFTMAC_SCAN))
;
if (priv->bHwRadioOff == true)
return 0;
if (!priv->up)
return -ENETDOWN;
priv->rtllib->wx_set_enc = 1;
down(&priv->rtllib->ips_sem);
IPSLeave(dev);
up(&priv->rtllib->ips_sem);
down(&priv->wx_sem);
RT_TRACE(COMP_SEC, "Setting SW wep key");
ret = rtllib_wx_set_encode(priv->rtllib, info, wrqu, key);
up(&priv->wx_sem);
if (wrqu->encoding.flags & IW_ENCODE_DISABLED) {
ieee->pairwise_key_type = ieee->group_key_type = KEY_TYPE_NA;
CamResetAllEntry(dev);
memset(priv->rtllib->swcamtable, 0,
sizeof(struct sw_cam_table) * 32);
goto end_hw_sec;
}
if (wrqu->encoding.length != 0) {
for (i = 0; i < 4; i++) {
hwkey[i] |= key[4*i+0]&mask;
if (i == 1 && (4 * i + 1) == wrqu->encoding.length)
mask = 0x00;
if (i == 3 && (4 * i + 1) == wrqu->encoding.length)
mask = 0x00;
hwkey[i] |= (key[4 * i + 1] & mask) << 8;
hwkey[i] |= (key[4 * i + 2] & mask) << 16;
hwkey[i] |= (key[4 * i + 3] & mask) << 24;
}
#define CONF_WEP40 0x4
#define CONF_WEP104 0x14
switch (wrqu->encoding.flags & IW_ENCODE_INDEX) {
case 0:
key_idx = ieee->crypt_info.tx_keyidx;
break;
case 1:
key_idx = 0;
break;
case 2:
key_idx = 1;
break;
case 3:
key_idx = 2;
break;
case 4:
key_idx = 3;
break;
default:
break;
}
if (wrqu->encoding.length == 0x5) {
ieee->pairwise_key_type = KEY_TYPE_WEP40;
EnableHWSecurityConfig8192(dev);
}
else if (wrqu->encoding.length == 0xd) {
ieee->pairwise_key_type = KEY_TYPE_WEP104;
EnableHWSecurityConfig8192(dev);
setKey(dev, key_idx, key_idx, KEY_TYPE_WEP104,
zero_addr[key_idx], 0, hwkey);
set_swcam(dev, key_idx, key_idx, KEY_TYPE_WEP104,
zero_addr[key_idx], 0, hwkey, 0);
} else {
printk(KERN_INFO "wrong type in WEP, not WEP40 and WEP104\n");
}
}
end_hw_sec:
priv->rtllib->wx_set_enc = 0;
return ret;
}
static int r8192_wx_set_scan_type(struct net_device *dev,
struct iw_request_info *aa,
union iwreq_data *wrqu, char *p)
{
struct r8192_priv *priv = rtllib_priv(dev);
int *parms = (int *)p;
int mode = parms[0];
if (priv->bHwRadioOff == true)
return 0;
priv->rtllib->active_scan = mode;
return 1;
}
static int r8192_wx_set_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
int err = 0;
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
if (wrqu->retry.flags & IW_RETRY_LIFETIME ||
wrqu->retry.disabled) {
err = -EINVAL;
goto exit;
}
if (!(wrqu->retry.flags & IW_RETRY_LIMIT)) {
err = -EINVAL;
goto exit;
}
if (wrqu->retry.value > R8192_MAX_RETRY) {
err = -EINVAL;
goto exit;
}
if (wrqu->retry.flags & IW_RETRY_MAX) {
priv->retry_rts = wrqu->retry.value;
DMESG("Setting retry for RTS/CTS data to %d",
wrqu->retry.value);
} else {
priv->retry_data = wrqu->retry.value;
DMESG("Setting retry for non RTS/CTS data to %d",
wrqu->retry.value);
}
rtl8192_commit(dev);
exit:
up(&priv->wx_sem);
return err;
}
static int r8192_wx_get_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
wrqu->retry.disabled = 0;
if ((wrqu->retry.flags & IW_RETRY_TYPE) ==
IW_RETRY_LIFETIME)
return -EINVAL;
if (wrqu->retry.flags & IW_RETRY_MAX) {
wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_MAX;
wrqu->retry.value = priv->retry_rts;
} else {
wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_MIN;
wrqu->retry.value = priv->retry_data;
}
return 0;
}
static int r8192_wx_get_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->rf_set_sens == NULL)
return -1;
wrqu->sens.value = priv->sens;
return 0;
}
static int r8192_wx_set_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
short err = 0;
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
if (priv->rf_set_sens == NULL) {
err = -1;
goto exit;
}
if (priv->rf_set_sens(dev, wrqu->sens.value) == 0)
priv->sens = wrqu->sens.value;
else
err = -EINVAL;
exit:
up(&priv->wx_sem);
return err;
}
static int r8192_wx_set_enc_ext(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret = 0;
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = priv->rtllib;
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
priv->rtllib->wx_set_enc = 1;
down(&priv->rtllib->ips_sem);
IPSLeave(dev);
up(&priv->rtllib->ips_sem);
ret = rtllib_wx_set_encode_ext(ieee, info, wrqu, extra);
{
u8 broadcast_addr[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
u8 zero[6] = {0};
u32 key[4] = {0};
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
struct iw_point *encoding = &wrqu->encoding;
u8 idx = 0, alg = 0, group = 0;
if ((encoding->flags & IW_ENCODE_DISABLED) ||
ext->alg == IW_ENCODE_ALG_NONE) {
ieee->pairwise_key_type = ieee->group_key_type
= KEY_TYPE_NA;
CamResetAllEntry(dev);
memset(priv->rtllib->swcamtable, 0,
sizeof(struct sw_cam_table) * 32);
goto end_hw_sec;
}
alg = (ext->alg == IW_ENCODE_ALG_CCMP) ? KEY_TYPE_CCMP :
ext->alg;
idx = encoding->flags & IW_ENCODE_INDEX;
if (idx)
idx--;
group = ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY;
if ((!group) || (IW_MODE_ADHOC == ieee->iw_mode) ||
(alg == KEY_TYPE_WEP40)) {
if ((ext->key_len == 13) && (alg == KEY_TYPE_WEP40))
alg = KEY_TYPE_WEP104;
ieee->pairwise_key_type = alg;
EnableHWSecurityConfig8192(dev);
}
memcpy((u8 *)key, ext->key, 16);
if ((alg & KEY_TYPE_WEP40) && (ieee->auth_mode != 2)) {
if (ext->key_len == 13)
ieee->pairwise_key_type = alg = KEY_TYPE_WEP104;
setKey(dev, idx, idx, alg, zero, 0, key);
set_swcam(dev, idx, idx, alg, zero, 0, key, 0);
} else if (group) {
ieee->group_key_type = alg;
setKey(dev, idx, idx, alg, broadcast_addr, 0, key);
set_swcam(dev, idx, idx, alg, broadcast_addr, 0,
key, 0);
} else {
if ((ieee->pairwise_key_type == KEY_TYPE_CCMP) &&
ieee->pHTInfo->bCurrentHTSupport)
write_nic_byte(dev, 0x173, 1);
setKey(dev, 4, idx, alg, (u8 *)ieee->ap_mac_addr,
0, key);
set_swcam(dev, 4, idx, alg, (u8 *)ieee->ap_mac_addr,
0, key, 0);
}
}
end_hw_sec:
priv->rtllib->wx_set_enc = 0;
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *data, char *extra)
{
int ret = 0;
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_auth(priv->rtllib, info, &(data->param), extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_mlme(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret = 0;
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_mlme(priv->rtllib, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_gen_ie(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *data, char *extra)
{
int ret = 0;
struct r8192_priv *priv = rtllib_priv(dev);
if (priv->bHwRadioOff == true)
return 0;
down(&priv->wx_sem);
ret = rtllib_wx_set_gen_ie(priv->rtllib, extra, data->data.length);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_gen_ie(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *data, char *extra)
{
int ret = 0;
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = priv->rtllib;
if (ieee->wpa_ie_len == 0 || ieee->wpa_ie == NULL) {
data->data.length = 0;
return 0;
}
if (data->data.length < ieee->wpa_ie_len)
return -E2BIG;
data->data.length = ieee->wpa_ie_len;
memcpy(extra, ieee->wpa_ie, ieee->wpa_ie_len);
return ret;
}
static int r8192_wx_set_PromiscuousMode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = priv->rtllib;
u32 *info_buf = (u32 *)(wrqu->data.pointer);
u32 oid = info_buf[0];
u32 bPromiscuousOn = info_buf[1];
u32 bFilterSourceStationFrame = info_buf[2];
if (OID_RT_INTEL_PROMISCUOUS_MODE == oid) {
ieee->IntelPromiscuousModeInfo.bPromiscuousOn =
(bPromiscuousOn) ? (true) : (false);
ieee->IntelPromiscuousModeInfo.bFilterSourceStationFrame =
(bFilterSourceStationFrame) ? (true) : (false);
(bPromiscuousOn) ?
(rtllib_EnableIntelPromiscuousMode(dev, false)) :
(rtllib_DisableIntelPromiscuousMode(dev, false));
printk(KERN_INFO "=======>%s(), on = %d, filter src sta = %d\n",
__func__, bPromiscuousOn, bFilterSourceStationFrame);
} else {
return -1;
}
return 0;
}
static int r8192_wx_get_PromiscuousMode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = priv->rtllib;
down(&priv->wx_sem);
snprintf(extra, 45, "PromiscuousMode:%d, FilterSrcSTAFrame:%d",
ieee->IntelPromiscuousModeInfo.bPromiscuousOn,
ieee->IntelPromiscuousModeInfo.bFilterSourceStationFrame);
wrqu->data.length = strlen(extra) + 1;
up(&priv->wx_sem);
return 0;
}
static struct iw_statistics *r8192_get_wireless_stats(struct net_device *dev)
{
struct r8192_priv *priv = rtllib_priv(dev);
struct rtllib_device *ieee = priv->rtllib;
struct iw_statistics *wstats = &priv->wstats;
int tmp_level = 0;
int tmp_qual = 0;
int tmp_noise = 0;
if (ieee->state < RTLLIB_LINKED) {
wstats->qual.qual = 10;
wstats->qual.level = 0;
wstats->qual.noise = -100;
wstats->qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
return wstats;
}
tmp_level = (&ieee->current_network)->stats.rssi;
tmp_qual = (&ieee->current_network)->stats.signal;
tmp_noise = (&ieee->current_network)->stats.noise;
wstats->qual.level = tmp_level;
wstats->qual.qual = tmp_qual;
wstats->qual.noise = tmp_noise;
wstats->qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
return wstats;
}
