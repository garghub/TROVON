static int r8192_wx_get_freq(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_freq(priv->ieee80211, a, wrqu, b);
}
static int r8192_wx_get_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_mode(priv->ieee80211, a, wrqu, b);
}
static int r8192_wx_get_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_rate(priv->ieee80211, info, wrqu, extra);
}
static int r8192_wx_set_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_rate(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_rts(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_rts(priv->ieee80211, info, wrqu, extra);
}
static int r8192_wx_set_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_power(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_power(priv->ieee80211, info, wrqu, extra);
}
static int r8192_wx_force_reset(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
printk("%s(): force reset ! extra is %d\n", __func__, *extra);
priv->force_reset = *extra;
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_set_rawtx(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int ret;
down(&priv->wx_sem);
ret = ieee80211_wx_set_rawtx(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_crcmon(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int *parms = (int *)extra;
int enable = (parms[0] > 0);
short prev = priv->crcmon;
down(&priv->wx_sem);
if (enable)
priv->crcmon = 1;
else
priv->crcmon = 0;
DMESG("bad CRC in monitor mode are %s",
priv->crcmon ? "accepted" : "rejected");
if (prev != priv->crcmon && priv->up) {
}
up(&priv->wx_sem);
return 0;
}
static int r8192_wx_set_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int ret;
down(&priv->wx_sem);
ret = ieee80211_wx_set_mode(priv->ieee80211, a, wrqu, b);
rtl8192_set_rxconf(dev);
up(&priv->wx_sem);
return ret;
}
static int rtl8180_wx_get_range(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct iw_range *range = (struct iw_range *)extra;
struct iw_range_with_scan_capa *tmp = (struct iw_range_with_scan_capa *)range;
struct r8192_priv *priv = ieee80211_priv(dev);
u16 val;
int i;
wrqu->data.length = sizeof(*range);
memset(range, 0, sizeof(*range));
range->throughput = 5 * 1000 * 1000;
if (priv->rf_set_sens != NULL)
range->sensitivity = priv->max_sens;
range->max_qual.qual = 100;
range->max_qual.level = 0;
range->max_qual.noise = -98;
range->max_qual.updated = 7;
range->avg_qual.qual = 92;
range->avg_qual.level = 20 + -98;
range->avg_qual.noise = 0;
range->avg_qual.updated = 7;
range->num_bitrates = RATE_COUNT;
for (i = 0; i < RATE_COUNT && i < IW_MAX_BITRATES; i++)
range->bitrate[i] = rtl8180_rates[i];
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
range->we_version_source = 16;
for (i = 0, val = 0; i < 14; i++) {
if ((GET_DOT11D_INFO(priv->ieee80211)->channel_map)[i+1]) {
range->freq[val].i = i + 1;
range->freq[val].m = ieee80211_wlan_frequencies[i] * 100000;
range->freq[val].e = 1;
val++;
} else {
}
if (val == IW_MAX_FREQUENCIES)
break;
}
range->num_frequency = val;
range->num_channels = val;
range->enc_capa = IW_ENC_CAPA_WPA|IW_ENC_CAPA_WPA2|
IW_ENC_CAPA_CIPHER_TKIP|IW_ENC_CAPA_CIPHER_CCMP;
tmp->scan_capa = 0x01;
return 0;
}
static int r8192_wx_set_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
int ret = 0;
if (!priv->up)
return -ENETDOWN;
if (priv->ieee80211->LinkDetectInfo.bBusyTraffic == true)
return -EAGAIN;
if (wrqu->data.flags & IW_SCAN_THIS_ESSID) {
struct iw_scan_req *req = (struct iw_scan_req *)b;
if (req->essid_len) {
ieee->current_network.ssid_len = req->essid_len;
memcpy(ieee->current_network.ssid, req->essid, req->essid_len);
}
}
down(&priv->wx_sem);
if (priv->ieee80211->state != IEEE80211_LINKED) {
priv->ieee80211->scanning = 0;
ieee80211_softmac_scan_syncro(priv->ieee80211);
ret = 0;
} else {
ret = ieee80211_wx_set_scan(priv->ieee80211, a, wrqu, b);
}
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
if (!priv->up)
return -ENETDOWN;
down(&priv->wx_sem);
ret = ieee80211_wx_get_scan(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int ret;
down(&priv->wx_sem);
ret = ieee80211_wx_set_essid(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_get_essid(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_freq(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_freq(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_name(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_name(priv->ieee80211, info, wrqu, extra);
}
static int r8192_wx_set_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
if (wrqu->frag.disabled)
priv->ieee80211->fts = DEFAULT_FRAG_THRESHOLD;
else {
if (wrqu->frag.value < MIN_FRAG_THRESHOLD ||
wrqu->frag.value > MAX_FRAG_THRESHOLD)
return -EINVAL;
priv->ieee80211->fts = wrqu->frag.value & ~0x1;
}
return 0;
}
static int r8192_wx_get_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
wrqu->frag.value = priv->ieee80211->fts;
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
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_wap(priv->ieee80211, info, awrq, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_get_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_wap(priv->ieee80211, info, wrqu, extra);
}
static int r8192_wx_get_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8192_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_encode(priv->ieee80211, info, wrqu, key);
}
static int r8192_wx_set_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
int ret;
u32 hwkey[4] = {0, 0, 0, 0};
u8 mask = 0xff;
u32 key_idx = 0;
u8 zero_addr[4][6] = { {0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x02},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x03} };
int i;
if (!priv->up)
return -ENETDOWN;
down(&priv->wx_sem);
RT_TRACE(COMP_SEC, "Setting SW wep key");
ret = ieee80211_wx_set_encode(priv->ieee80211, info, wrqu, key);
up(&priv->wx_sem);
if (wrqu->encoding.length != 0) {
for (i = 0; i < 4; i++) {
hwkey[i] |= key[4*i+0]&mask;
if (i == 1 && (4*i+1) == wrqu->encoding.length)
mask = 0x00;
if (i == 3 && (4*i+1) == wrqu->encoding.length)
mask = 0x00;
hwkey[i] |= (key[4*i+1]&mask)<<8;
hwkey[i] |= (key[4*i+2]&mask)<<16;
hwkey[i] |= (key[4*i+3]&mask)<<24;
}
#define CONF_WEP40 0x4
#define CONF_WEP104 0x14
switch (wrqu->encoding.flags & IW_ENCODE_INDEX) {
case 0:
key_idx = ieee->tx_keyidx;
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
setKey(dev,
key_idx,
key_idx,
KEY_TYPE_WEP40,
zero_addr[key_idx],
0,
hwkey);
}
else if (wrqu->encoding.length == 0xd) {
ieee->pairwise_key_type = KEY_TYPE_WEP104;
EnableHWSecurityConfig8192(dev);
setKey(dev,
key_idx,
key_idx,
KEY_TYPE_WEP104,
zero_addr[key_idx],
0,
hwkey);
} else {
printk("wrong type in WEP, not WEP40 and WEP104\n");
}
}
return ret;
}
static int r8192_wx_set_scan_type(struct net_device *dev, struct iw_request_info *aa,
union iwreq_data *wrqu, char *p)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int *parms = (int *)p;
int mode = parms[0];
priv->ieee80211->active_scan = mode;
return 1;
}
static int r8192_wx_set_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
int err = 0;
down(&priv->wx_sem);
if (wrqu->retry.flags & IW_RETRY_LIFETIME ||
wrqu->retry.disabled){
err = -EINVAL;
goto exit;
}
if (!(wrqu->retry.flags & IW_RETRY_LIMIT)) {
err = -EINVAL;
goto exit;
}
if (wrqu->retry.value > R8180_MAX_RETRY) {
err = -EINVAL;
goto exit;
}
if (wrqu->retry.flags & IW_RETRY_MAX) {
priv->retry_rts = wrqu->retry.value;
DMESG("Setting retry for RTS/CTS data to %d", wrqu->retry.value);
} else {
priv->retry_data = wrqu->retry.value;
DMESG("Setting retry for non RTS/CTS data to %d", wrqu->retry.value);
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
struct r8192_priv *priv = ieee80211_priv(dev);
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
struct r8192_priv *priv = ieee80211_priv(dev);
if (priv->rf_set_sens == NULL)
return -1;
wrqu->sens.value = priv->sens;
return 0;
}
static int r8192_wx_set_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8192_priv *priv = ieee80211_priv(dev);
short err = 0;
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
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
down(&priv->wx_sem);
ret = ieee80211_wx_set_encode_ext(priv->ieee80211, info, wrqu, extra);
{
u8 broadcast_addr[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
u8 zero[6] = {0};
u32 key[4] = {0};
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
struct iw_point *encoding = &wrqu->encoding;
u8 idx = 0, alg = 0, group = 0;
if ((encoding->flags & IW_ENCODE_DISABLED) || ext->alg == IW_ENCODE_ALG_NONE)
goto end_hw_sec;
alg = (ext->alg == IW_ENCODE_ALG_CCMP)?KEY_TYPE_CCMP:ext->alg;
idx = encoding->flags & IW_ENCODE_INDEX;
if (idx)
idx--;
group = ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY;
if ((!group) || (IW_MODE_ADHOC == ieee->iw_mode) || (alg == KEY_TYPE_WEP40)) {
if ((ext->key_len == 13) && (alg == KEY_TYPE_WEP40))
alg = KEY_TYPE_WEP104;
ieee->pairwise_key_type = alg;
EnableHWSecurityConfig8192(dev);
}
memcpy((u8 *)key, ext->key, 16);
if ((alg & KEY_TYPE_WEP40) && (ieee->auth_mode != 2)) {
setKey(dev,
idx,
idx,
alg,
zero,
0,
key);
} else if (group) {
ieee->group_key_type = alg;
setKey(dev,
idx,
idx,
alg,
broadcast_addr,
0,
key);
} else {
setKey(dev,
4,
idx,
alg,
(u8 *)ieee->ap_mac_addr,
0,
key);
}
}
end_hw_sec:
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *data, char *extra)
{
int ret = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_auth(priv->ieee80211, info, &(data->param), extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_mlme(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_mlme(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8192_wx_set_gen_ie(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *data, char *extra)
{
int ret = 0;
struct r8192_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_set_gen_ie(priv->ieee80211, extra, data->data.length);
up(&priv->wx_sem);
return ret;
}
static int dummy(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
return -1;
}
struct iw_statistics *r8192_get_wireless_stats(struct net_device *dev)
{
struct r8192_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
struct iw_statistics *wstats = &priv->wstats;
int tmp_level = 0;
int tmp_qual = 0;
int tmp_noise = 0;
if (ieee->state < IEEE80211_LINKED) {
wstats->qual.qual = 0;
wstats->qual.level = 0;
wstats->qual.noise = 0;
wstats->qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
return wstats;
}
tmp_level = (&ieee->current_network)->stats.rssi;
tmp_qual = (&ieee->current_network)->stats.signal;
tmp_noise = (&ieee->current_network)->stats.noise;
wstats->qual.level = tmp_level;
wstats->qual.qual = tmp_qual;
wstats->qual.noise = tmp_noise;
wstats->qual.updated = IW_QUAL_ALL_UPDATED| IW_QUAL_DBM;
return wstats;
}
