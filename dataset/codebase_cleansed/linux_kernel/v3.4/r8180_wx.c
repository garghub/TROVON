static int r8180_wx_get_freq(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8180_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_freq(priv->ieee80211, a, wrqu, b);
}
int r8180_wx_set_key(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8180_priv *priv = ieee80211_priv(dev);
struct iw_point *erq = &(wrqu->encoding);
if (priv->ieee80211->bHwRadioOff)
return 0;
if (erq->flags & IW_ENCODE_DISABLED)
if (erq->length > 0) {
u32* tkey = (u32*) key;
priv->key0[0] = tkey[0];
priv->key0[1] = tkey[1];
priv->key0[2] = tkey[2];
priv->key0[3] = tkey[3] & 0xff;
DMESG("Setting wep key to %x %x %x %x",
tkey[0], tkey[1], tkey[2], tkey[3]);
rtl8180_set_hw_wep(dev);
}
return 0;
}
static int r8180_wx_set_beaconinterval(struct net_device *dev, struct iw_request_info *aa,
union iwreq_data *wrqu, char *b)
{
int *parms = (int *)b;
int bi = parms[0];
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
DMESG("setting beacon interval to %x", bi);
priv->ieee80211->current_network.beacon_interval = bi;
rtl8180_commit(dev);
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_get_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8180_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_mode(priv->ieee80211, a, wrqu, b);
}
static int r8180_wx_get_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_rate(priv->ieee80211, info, wrqu, extra);
}
static int r8180_wx_set_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_rate(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_crcmon(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int *parms = (int *)extra;
int enable = (parms[0] > 0);
short prev = priv->crcmon;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (enable)
priv->crcmon = 1;
else
priv->crcmon = 0;
DMESG("bad CRC in monitor mode are %s",
priv->crcmon ? "accepted" : "rejected");
if (prev != priv->crcmon && priv->up) {
rtl8180_down(dev);
rtl8180_up(dev);
}
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_set_mode(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (priv->bInactivePs) {
if (wrqu->mode == IW_MODE_ADHOC)
IPSLeave(dev);
}
ret = ieee80211_wx_set_mode(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int rtl8180_wx_get_range(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct iw_range *range = (struct iw_range *)extra;
struct r8180_priv *priv = ieee80211_priv(dev);
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
range->pm_capa = 0;
range->we_version_compiled = WIRELESS_EXT;
range->we_version_source = 16;
range->num_channels = 14;
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
range->enc_capa = IW_ENC_CAPA_WPA | IW_ENC_CAPA_WPA2 |
IW_ENC_CAPA_CIPHER_TKIP | IW_ENC_CAPA_CIPHER_CCMP;
return 0;
}
static int r8180_wx_set_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret;
struct ieee80211_device* ieee = priv->ieee80211;
if (priv->ieee80211->bHwRadioOff)
return 0;
if (wrqu->data.flags & IW_SCAN_THIS_ESSID) {
struct iw_scan_req* req = (struct iw_scan_req*)b;
if (req->essid_len) {
ieee->current_network.ssid_len = req->essid_len;
memcpy(ieee->current_network.ssid, req->essid, req->essid_len);
}
}
down(&priv->wx_sem);
if (priv->up) {
priv->ieee80211->actscanning = true;
if (priv->bInactivePs && (priv->ieee80211->state != IEEE80211_LINKED)) {
IPSLeave(dev);
ieee80211_softmac_ips_scan_syncro(priv->ieee80211);
ret = 0;
} else {
if ((priv->link_detect.bBusyTraffic) && (true)) {
ret = 0;
printk("Now traffic is busy, please try later!\n");
} else
ret = ieee80211_wx_set_scan(priv->ieee80211, a, wrqu, b);
}
} else
ret = -1;
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_scan(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8180_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
if (priv->up)
ret = ieee80211_wx_get_scan(priv->ieee80211, a, wrqu, b);
else
ret = -1;
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (priv->bInactivePs)
IPSLeave(dev);
ret = ieee80211_wx_set_essid(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_essid(struct net_device *dev,
struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8180_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_get_essid(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_freq(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
int ret;
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_freq(priv->ieee80211, a, wrqu, b);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_name(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_name(priv->ieee80211, info, wrqu, extra);
}
static int r8180_wx_set_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
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
static int r8180_wx_get_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
wrqu->frag.value = priv->ieee80211->fts;
wrqu->frag.fixed = 0;
wrqu->frag.disabled = (wrqu->frag.value == DEFAULT_FRAG_THRESHOLD);
return 0;
}
static int r8180_wx_set_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *awrq,
char *extra)
{
int ret;
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_wap(priv->ieee80211, info, awrq, extra);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_wap(priv->ieee80211, info, wrqu, extra);
}
static int r8180_wx_set_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (priv->hw_wep) ret = r8180_wx_set_key(dev, info, wrqu, key);
else {
DMESG("Setting SW wep key");
ret = ieee80211_wx_set_encode(priv->ieee80211, info, wrqu, key);
}
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_enc(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct r8180_priv *priv = ieee80211_priv(dev);
return ieee80211_wx_get_encode(priv->ieee80211, info, wrqu, key);
}
static int r8180_wx_set_scan_type(struct net_device *dev, struct iw_request_info *aa, union
iwreq_data *wrqu, char *p) {
struct r8180_priv *priv = ieee80211_priv(dev);
int *parms = (int*)p;
int mode = parms[0];
if (priv->ieee80211->bHwRadioOff)
return 0;
priv->ieee80211->active_scan = mode;
return 1;
}
static int r8180_wx_set_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int err = 0;
if (priv->ieee80211->bHwRadioOff)
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
rtl8180_commit(dev);
exit:
up(&priv->wx_sem);
return err;
}
static int r8180_wx_get_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
wrqu->retry.disabled = 0;
if ((wrqu->retry.flags & IW_RETRY_TYPE) ==
IW_RETRY_LIFETIME)
return -EINVAL;
if (wrqu->retry.flags & IW_RETRY_MAX) {
wrqu->retry.flags = IW_RETRY_LIMIT & IW_RETRY_MAX;
wrqu->retry.value = priv->retry_rts;
} else {
wrqu->retry.flags = IW_RETRY_LIMIT & IW_RETRY_MIN;
wrqu->retry.value = priv->retry_data;
}
return 0;
}
static int r8180_wx_get_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->rf_set_sens == NULL)
return -1;
wrqu->sens.value = priv->sens;
return 0;
}
static int r8180_wx_set_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
short err = 0;
if (priv->ieee80211->bHwRadioOff)
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
static int r8180_wx_set_rawtx(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_rawtx(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8180_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
ret = ieee80211_wx_get_power(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret;
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
printk("=>>>>>>>>>>=============================>set power:%d, %d!\n", wrqu->power.disabled, wrqu->power.flags);
if (wrqu->power.disabled == 0) {
wrqu->power.flags |= IW_POWER_ALL_R;
wrqu->power.flags |= IW_POWER_TIMEOUT;
wrqu->power.value = 1000;
}
ret = ieee80211_wx_set_power(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
if (wrqu->rts.disabled)
priv->rts = DEFAULT_RTS_THRESHOLD;
else {
if (wrqu->rts.value < MIN_RTS_THRESHOLD ||
wrqu->rts.value > MAX_RTS_THRESHOLD)
return -EINVAL;
priv->rts = wrqu->rts.value;
}
return 0;
}
static int r8180_wx_get_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
wrqu->rts.value = priv->rts;
wrqu->rts.fixed = 0;
wrqu->rts.disabled = (wrqu->rts.value == 0);
return 0;
}
static int dummy(struct net_device *dev, struct iw_request_info *a,
union iwreq_data *wrqu, char *b)
{
return -1;
}
static int r8180_wx_get_iwmode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee;
int ret = 0;
down(&priv->wx_sem);
ieee = priv->ieee80211;
strcpy(extra, "802.11");
if (ieee->modulation & IEEE80211_CCK_MODULATION) {
strcat(extra, "b");
if (ieee->modulation & IEEE80211_OFDM_MODULATION)
strcat(extra, "/g");
} else if (ieee->modulation & IEEE80211_OFDM_MODULATION)
strcat(extra, "g");
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_iwmode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
struct ieee80211_device *ieee = priv->ieee80211;
int *param = (int *)extra;
int ret = 0;
int modulation = 0, mode = 0;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (*param == 1) {
modulation |= IEEE80211_CCK_MODULATION;
mode = IEEE_B;
printk(KERN_INFO "B mode!\n");
} else if (*param == 2) {
modulation |= IEEE80211_OFDM_MODULATION;
mode = IEEE_G;
printk(KERN_INFO "G mode!\n");
} else if (*param == 3) {
modulation |= IEEE80211_CCK_MODULATION;
modulation |= IEEE80211_OFDM_MODULATION;
mode = IEEE_B|IEEE_G;
printk(KERN_INFO "B/G mode!\n");
}
if (ieee->proto_started) {
ieee80211_stop_protocol(ieee);
ieee->mode = mode;
ieee->modulation = modulation;
ieee80211_start_protocol(ieee);
} else {
ieee->mode = mode;
ieee->modulation = modulation;
}
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_preamble(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
*extra = (char) priv->plcp_preamble_mode;
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_set_preamble(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret = 0;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (*extra < 0 || *extra > 2)
ret = -1;
else
priv->plcp_preamble_mode = *((short *)extra) ;
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_siglevel(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret = 0;
down(&priv->wx_sem);
*((int *)extra) = priv->wstats.qual.level;
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_get_sigqual(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret = 0;
down(&priv->wx_sem);
*((int *)extra) = priv->wstats.qual.qual;
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_reset_stats(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
priv->stats.txrdu = 0;
priv->stats.rxrdu = 0;
priv->stats.rxnolast = 0;
priv->stats.rxnodata = 0;
priv->stats.rxnopointer = 0;
priv->stats.txnperr = 0;
priv->stats.txresumed = 0;
priv->stats.rxerr = 0;
priv->stats.rxoverflow = 0;
priv->stats.rxint = 0;
priv->stats.txnpokint = 0;
priv->stats.txhpokint = 0;
priv->stats.txhperr = 0;
priv->stats.ints = 0;
priv->stats.shints = 0;
priv->stats.txoverflow = 0;
priv->stats.rxdmafail = 0;
priv->stats.txbeacon = 0;
priv->stats.txbeaconerr = 0;
priv->stats.txlpokint = 0;
priv->stats.txlperr = 0;
priv->stats.txretry = 0;
priv->stats.rxcrcerrmin = 0 ;
priv->stats.rxcrcerrmid = 0;
priv->stats.rxcrcerrmax = 0;
priv->stats.rxicverr = 0;
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_radio_on(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
priv->rf_wakeup(dev);
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_radio_off(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
priv->rf_sleep(dev);
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_get_channelplan(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
*extra = priv->channel_plan;
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_set_channelplan(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int *val = (int *)extra;
int i;
printk("-----in fun %s\n", __func__);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
if (DefaultChannelPlan[*val].Len != 0) {
priv->channel_plan = *val;
for (i = 1; i <= MAX_CHANNEL_NUMBER; i++)
GET_DOT11D_INFO(priv->ieee80211)->channel_map[i] = 0;
for (i = 1; i <= DefaultChannelPlan[*val].Len; i++)
GET_DOT11D_INFO(priv->ieee80211)->channel_map[DefaultChannelPlan[*val].Channel[i-1]] = 1;
}
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_get_version(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
down(&priv->wx_sem);
strcpy(extra, "1020.0808");
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_set_forcerate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u8 forcerate = *extra;
down(&priv->wx_sem);
printk("==============>%s(): forcerate is %d\n", __func__, forcerate);
if ((forcerate == 2) || (forcerate == 4) || (forcerate == 11) || (forcerate == 22) || (forcerate == 12) ||
(forcerate == 18) || (forcerate == 24) || (forcerate == 36) || (forcerate == 48) || (forcerate == 72) ||
(forcerate == 96) || (forcerate == 108))
{
priv->ForcedDataRate = 1;
priv->ieee80211->rate = forcerate * 5;
} else if (forcerate == 0) {
priv->ForcedDataRate = 0;
printk("OK! return rate adaptive\n");
} else
printk("ERR: wrong rate\n");
up(&priv->wx_sem);
return 0;
}
static int r8180_wx_set_enc_ext(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret = 0;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_encode_ext(priv->ieee80211, info, wrqu, extra);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int ret = 0;
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
ret = ieee80211_wx_set_auth(priv->ieee80211, info, &wrqu->param, extra);
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_mlme(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret = 0;
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
#if 1
ret = ieee80211_wx_set_mlme(priv->ieee80211, info, wrqu, extra);
#endif
up(&priv->wx_sem);
return ret;
}
static int r8180_wx_set_gen_ie(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
int ret = 0;
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->bHwRadioOff)
return 0;
down(&priv->wx_sem);
#if 1
ret = ieee80211_wx_set_gen_ie(priv->ieee80211, extra, wrqu->data.length);
#endif
up(&priv->wx_sem);
return ret;
}
static inline int is_same_network(struct ieee80211_network *src,
struct ieee80211_network *dst,
struct ieee80211_device *ieee)
{
return (((src->ssid_len == dst->ssid_len) || (ieee->iw_mode == IW_MODE_INFRA)) &&
(src->channel == dst->channel) &&
!memcmp(src->bssid, dst->bssid, ETH_ALEN) &&
(!memcmp(src->ssid, dst->ssid, src->ssid_len) || (ieee->iw_mode == IW_MODE_INFRA)) &&
((src->capability & WLAN_CAPABILITY_IBSS) ==
(dst->capability & WLAN_CAPABILITY_IBSS)) &&
((src->capability & WLAN_CAPABILITY_BSS) ==
(dst->capability & WLAN_CAPABILITY_BSS)));
}
static struct iw_statistics *r8180_get_wireless_stats(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
struct ieee80211_device* ieee = priv->ieee80211;
struct iw_statistics* wstats = &priv->wstats;
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
tmp_level = (&ieee->current_network)->stats.signal;
tmp_qual = (&ieee->current_network)->stats.signalstrength;
tmp_noise = (&ieee->current_network)->stats.noise;
wstats->qual.level = tmp_level;
wstats->qual.qual = tmp_qual;
wstats->qual.noise = tmp_noise;
wstats->qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
return wstats;
}
