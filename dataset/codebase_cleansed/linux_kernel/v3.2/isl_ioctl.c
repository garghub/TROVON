static int
prism54_mib_mode_helper(islpci_private *priv, u32 iw_mode)
{
u32 config = INL_CONFIG_MANUALRUN;
u32 mode, bsstype;
if (iw_mode == IW_MODE_REPEAT || iw_mode == IW_MODE_SECOND) {
printk(KERN_DEBUG
"%s(): Sorry, Repeater mode and Secondary mode "
"are not yet supported by this driver.\n", __func__);
return -EINVAL;
}
priv->iw_mode = iw_mode;
switch (iw_mode) {
case IW_MODE_AUTO:
mode = INL_MODE_CLIENT;
bsstype = DOT11_BSSTYPE_ANY;
break;
case IW_MODE_ADHOC:
mode = INL_MODE_CLIENT;
bsstype = DOT11_BSSTYPE_IBSS;
break;
case IW_MODE_INFRA:
mode = INL_MODE_CLIENT;
bsstype = DOT11_BSSTYPE_INFRA;
break;
case IW_MODE_MASTER:
mode = INL_MODE_AP;
bsstype = DOT11_BSSTYPE_INFRA;
break;
case IW_MODE_MONITOR:
mode = INL_MODE_PROMISCUOUS;
bsstype = DOT11_BSSTYPE_ANY;
config |= INL_CONFIG_RXANNEX;
break;
default:
return -EINVAL;
}
if (init_wds)
config |= INL_CONFIG_WDS;
mgt_set(priv, DOT11_OID_BSSTYPE, &bsstype);
mgt_set(priv, OID_INL_CONFIG, &config);
mgt_set(priv, OID_INL_MODE, &mode);
return 0;
}
void
prism54_mib_init(islpci_private *priv)
{
u32 channel, authen, wep, filter, dot1x, mlme, conformance, power, mode;
struct obj_buffer psm_buffer = {
.size = PSM_BUFFER_SIZE,
.addr = priv->device_psm_buffer
};
channel = CARD_DEFAULT_CHANNEL;
authen = CARD_DEFAULT_AUTHEN;
wep = CARD_DEFAULT_WEP;
filter = CARD_DEFAULT_FILTER;
dot1x = CARD_DEFAULT_DOT1X;
mlme = CARD_DEFAULT_MLME_MODE;
conformance = CARD_DEFAULT_CONFORMANCE;
power = 127;
mode = CARD_DEFAULT_IW_MODE;
mgt_set(priv, DOT11_OID_CHANNEL, &channel);
mgt_set(priv, DOT11_OID_AUTHENABLE, &authen);
mgt_set(priv, DOT11_OID_PRIVACYINVOKED, &wep);
mgt_set(priv, DOT11_OID_PSMBUFFER, &psm_buffer);
mgt_set(priv, DOT11_OID_EXUNENCRYPTED, &filter);
mgt_set(priv, DOT11_OID_DOT1XENABLE, &dot1x);
mgt_set(priv, DOT11_OID_MLMEAUTOLEVEL, &mlme);
mgt_set(priv, OID_INL_DOT11D_CONFORMANCE, &conformance);
mgt_set(priv, OID_INL_OUTPUTPOWER, &power);
prism54_mib_mode_helper(priv, mode);
}
void
prism54_update_stats(struct work_struct *work)
{
islpci_private *priv = container_of(work, islpci_private, stats_work);
char *data;
int j;
struct obj_bss bss, *bss2;
union oid_res_t r;
mutex_lock(&priv->stats_lock);
mgt_get_request(priv, DOT11_OID_NOISEFLOOR, 0, NULL, &r);
priv->local_iwstatistics.qual.noise = r.u;
mgt_get_request(priv, DOT11_OID_BSSID, 0, NULL, &r);
data = r.ptr;
memcpy(bss.address, data, 6);
kfree(data);
j = mgt_get_request(priv, DOT11_OID_BSSFIND, 0, (void *) &bss, &r);
bss2 = r.ptr;
priv->local_iwstatistics.qual.level = bss2->rssi;
priv->local_iwstatistics.qual.qual =
bss2->rssi - priv->iwstatistics.qual.noise;
kfree(bss2);
priv->local_iwstatistics.qual.updated = 0x7;
mgt_get_request(priv, DOT11_OID_PRIVRXFAILED, 0, NULL, &r);
priv->local_iwstatistics.discard.code = r.u;
mgt_get_request(priv, DOT11_OID_MPDUTXFAILED, 0, NULL, &r);
priv->local_iwstatistics.discard.retries = r.u;
mutex_unlock(&priv->stats_lock);
}
struct iw_statistics *
prism54_get_wireless_stats(struct net_device *ndev)
{
islpci_private *priv = netdev_priv(ndev);
if (mutex_trylock(&priv->stats_lock)) {
memcpy(&priv->iwstatistics, &priv->local_iwstatistics,
sizeof (struct iw_statistics));
priv->local_iwstatistics.qual.updated = 0;
mutex_unlock(&priv->stats_lock);
} else
priv->iwstatistics.qual.updated = 0;
if ((priv->stats_timestamp == 0) ||
time_after(jiffies, priv->stats_timestamp + 1 * HZ)) {
schedule_work(&priv->stats_work);
priv->stats_timestamp = jiffies;
}
return &priv->iwstatistics;
}
static int
prism54_commit(struct net_device *ndev, struct iw_request_info *info,
char *cwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
if (priv->iw_mode != IW_MODE_MONITOR)
return mgt_set_request(priv, DOT11_OID_SSID, 0, NULL);
return 0;
}
static int
prism54_get_name(struct net_device *ndev, struct iw_request_info *info,
char *cwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
char *capabilities;
union oid_res_t r;
int rvalue;
if (islpci_get_state(priv) < PRV_STATE_INIT) {
strncpy(cwrq, "NOT READY!", IFNAMSIZ);
return 0;
}
rvalue = mgt_get_request(priv, OID_INL_PHYCAPABILITIES, 0, NULL, &r);
switch (r.u) {
case INL_PHYCAP_5000MHZ:
capabilities = "IEEE 802.11a/b/g";
break;
case INL_PHYCAP_FAA:
capabilities = "IEEE 802.11b/g - FAA Support";
break;
case INL_PHYCAP_2400MHZ:
default:
capabilities = "IEEE 802.11b/g";
break;
}
strncpy(cwrq, capabilities, IFNAMSIZ);
return rvalue;
}
static int
prism54_set_freq(struct net_device *ndev, struct iw_request_info *info,
struct iw_freq *fwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
int rvalue;
u32 c;
if (fwrq->m < 1000)
c = fwrq->m;
else
c = (fwrq->e == 1) ? channel_of_freq(fwrq->m / 100000) : 0;
rvalue = c ? mgt_set_request(priv, DOT11_OID_CHANNEL, 0, &c) : -EINVAL;
return (rvalue ? rvalue : -EINPROGRESS);
}
static int
prism54_get_freq(struct net_device *ndev, struct iw_request_info *info,
struct iw_freq *fwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
union oid_res_t r;
int rvalue;
rvalue = mgt_get_request(priv, DOT11_OID_CHANNEL, 0, NULL, &r);
fwrq->i = r.u;
rvalue |= mgt_get_request(priv, DOT11_OID_FREQUENCY, 0, NULL, &r);
fwrq->m = r.u;
fwrq->e = 3;
return rvalue;
}
static int
prism54_set_mode(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
u32 mlmeautolevel = CARD_DEFAULT_MLME_MODE;
if (*uwrq > IW_MODE_MONITOR || *uwrq < IW_MODE_AUTO) {
printk(KERN_DEBUG
"%s: %s() You passed a non-valid init_mode.\n",
priv->ndev->name, __func__);
return -EINVAL;
}
down_write(&priv->mib_sem);
if (prism54_mib_mode_helper(priv, *uwrq)) {
up_write(&priv->mib_sem);
return -EOPNOTSUPP;
}
if ((*uwrq == IW_MODE_MASTER) && (priv->acl.policy != MAC_POLICY_OPEN))
mlmeautolevel = DOT11_MLME_INTERMEDIATE;
if (priv->wpa)
mlmeautolevel = DOT11_MLME_EXTENDED;
mgt_set(priv, DOT11_OID_MLMEAUTOLEVEL, &mlmeautolevel);
if (mgt_commit(priv)) {
up_write(&priv->mib_sem);
return -EIO;
}
priv->ndev->type = (priv->iw_mode == IW_MODE_MONITOR)
? priv->monitor_type : ARPHRD_ETHER;
up_write(&priv->mib_sem);
return 0;
}
static int
prism54_get_mode(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
BUG_ON((priv->iw_mode < IW_MODE_AUTO) || (priv->iw_mode >
IW_MODE_MONITOR));
*uwrq = priv->iw_mode;
return 0;
}
static int
prism54_set_sens(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
u32 sens;
sens = vwrq->disabled ? 20 : vwrq->value;
return mgt_set_request(priv, DOT11_OID_EDTHRESHOLD, 0, &sens);
}
static int
prism54_get_sens(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
union oid_res_t r;
int rvalue;
rvalue = mgt_get_request(priv, DOT11_OID_EDTHRESHOLD, 0, NULL, &r);
vwrq->value = r.u;
vwrq->disabled = (vwrq->value == 0);
vwrq->fixed = 1;
return rvalue;
}
static int
prism54_get_range(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
struct iw_range *range = (struct iw_range *) extra;
islpci_private *priv = netdev_priv(ndev);
u8 *data;
int i, m, rvalue;
struct obj_frequencies *freq;
union oid_res_t r;
memset(range, 0, sizeof (struct iw_range));
dwrq->length = sizeof (struct iw_range);
range->we_version_source = SUPPORTED_WIRELESS_EXT;
range->we_version_compiled = WIRELESS_EXT;
range->num_encoding_sizes = 3;
range->encoding_size[0] = 5;
range->encoding_size[1] = 13;
range->encoding_size[2] = 32;
range->max_encoding_tokens = 4;
range->max_qual.level = 0;
range->max_qual.noise = 0;
range->max_qual.qual = 0;
range->avg_qual.level = -80;
range->avg_qual.noise = 0;
range->avg_qual.qual = 0;
range->sensitivity = 200;
range->retry_capa = IW_RETRY_LIMIT | IW_RETRY_LIFETIME;
range->retry_flags = IW_RETRY_LIMIT;
range->r_time_flags = IW_RETRY_LIFETIME;
range->min_retry = 1;
range->max_retry = 65535;
range->min_r_time = 1024;
range->max_r_time = 65535 * 1024;
range->txpower_capa = IW_TXPOW_DBM;
range->event_capa[0] = (IW_EVENT_CAPA_K_0 |
IW_EVENT_CAPA_MASK(SIOCGIWTHRSPY) |
IW_EVENT_CAPA_MASK(SIOCGIWAP));
range->event_capa[1] = IW_EVENT_CAPA_K_1;
range->event_capa[4] = IW_EVENT_CAPA_MASK(IWEVCUSTOM);
range->enc_capa = IW_ENC_CAPA_WPA | IW_ENC_CAPA_WPA2 |
IW_ENC_CAPA_CIPHER_TKIP;
if (islpci_get_state(priv) < PRV_STATE_INIT)
return 0;
rvalue =
mgt_get_request(priv, DOT11_OID_SUPPORTEDFREQUENCIES, 0, NULL, &r);
freq = r.ptr;
range->num_channels = freq->nr;
range->num_frequency = freq->nr;
m = min(IW_MAX_FREQUENCIES, (int) freq->nr);
for (i = 0; i < m; i++) {
range->freq[i].m = freq->mhz[i];
range->freq[i].e = 6;
range->freq[i].i = channel_of_freq(freq->mhz[i]);
}
kfree(freq);
rvalue |= mgt_get_request(priv, DOT11_OID_SUPPORTEDRATES, 0, NULL, &r);
data = r.ptr;
i = 0;
while ((i < IW_MAX_BITRATES) && (*data != 0)) {
range->bitrate[i] = *data * 500000;
i++;
data++;
}
range->num_bitrates = i;
kfree(r.ptr);
return rvalue;
}
static int
prism54_set_wap(struct net_device *ndev, struct iw_request_info *info,
struct sockaddr *awrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
char bssid[6];
int rvalue;
if (awrq->sa_family != ARPHRD_ETHER)
return -EINVAL;
memcpy(&bssid[0], awrq->sa_data, 6);
rvalue = mgt_set_request(priv, DOT11_OID_BSSID, 0, &bssid);
return (rvalue ? rvalue : -EINPROGRESS);
}
static int
prism54_get_wap(struct net_device *ndev, struct iw_request_info *info,
struct sockaddr *awrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
union oid_res_t r;
int rvalue;
rvalue = mgt_get_request(priv, DOT11_OID_BSSID, 0, NULL, &r);
memcpy(awrq->sa_data, r.ptr, 6);
awrq->sa_family = ARPHRD_ETHER;
kfree(r.ptr);
return rvalue;
}
static int
prism54_set_scan(struct net_device *dev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
return 0;
}
static char *
prism54_translate_bss(struct net_device *ndev, struct iw_request_info *info,
char *current_ev, char *end_buf, struct obj_bss *bss,
char noise)
{
struct iw_event iwe;
short cap;
islpci_private *priv = netdev_priv(ndev);
u8 wpa_ie[MAX_WPA_IE_LEN];
size_t wpa_ie_len;
memcpy(iwe.u.ap_addr.sa_data, bss->address, 6);
iwe.u.ap_addr.sa_family = ARPHRD_ETHER;
iwe.cmd = SIOCGIWAP;
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_ADDR_LEN);
iwe.u.data.length = bss->ssid.length;
iwe.u.data.flags = 1;
iwe.cmd = SIOCGIWESSID;
current_ev = iwe_stream_add_point(info, current_ev, end_buf,
&iwe, bss->ssid.octets);
#define CAP_ESS 0x01
#define CAP_IBSS 0x02
#define CAP_CRYPT 0x10
cap = bss->capinfo;
iwe.u.mode = 0;
if (cap & CAP_ESS)
iwe.u.mode = IW_MODE_MASTER;
else if (cap & CAP_IBSS)
iwe.u.mode = IW_MODE_ADHOC;
iwe.cmd = SIOCGIWMODE;
if (iwe.u.mode)
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_UINT_LEN);
if (cap & CAP_CRYPT)
iwe.u.data.flags = IW_ENCODE_ENABLED | IW_ENCODE_NOKEY;
else
iwe.u.data.flags = IW_ENCODE_DISABLED;
iwe.u.data.length = 0;
iwe.cmd = SIOCGIWENCODE;
current_ev = iwe_stream_add_point(info, current_ev, end_buf,
&iwe, NULL);
iwe.u.freq.m = bss->channel;
iwe.u.freq.e = 6;
iwe.cmd = SIOCGIWFREQ;
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_FREQ_LEN);
iwe.u.qual.level = bss->rssi;
iwe.u.qual.noise = noise;
iwe.u.qual.qual = bss->rssi - noise;
iwe.cmd = IWEVQUAL;
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_QUAL_LEN);
wpa_ie_len = prism54_wpa_bss_ie_get(priv, bss->address, wpa_ie);
if (wpa_ie_len > 0) {
iwe.cmd = IWEVGENIE;
iwe.u.data.length = min(wpa_ie_len, (size_t)MAX_WPA_IE_LEN);
current_ev = iwe_stream_add_point(info, current_ev, end_buf,
&iwe, wpa_ie);
}
{
char *current_val = current_ev + iwe_stream_lcp_len(info);
int i;
int mask;
iwe.cmd = SIOCGIWRATE;
iwe.u.bitrate.fixed = iwe.u.bitrate.disabled = 0;
mask = 0x1;
for(i = 0; i < sizeof(scan_rate_list); i++) {
if(bss->rates & mask) {
iwe.u.bitrate.value = (scan_rate_list[i] * 500000);
current_val = iwe_stream_add_value(
info, current_ev, current_val,
end_buf, &iwe, IW_EV_PARAM_LEN);
}
mask <<= 1;
}
if ((current_val - current_ev) > iwe_stream_lcp_len(info))
current_ev = current_val;
}
return current_ev;
}
static int
prism54_get_scan(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
int i, rvalue;
struct obj_bsslist *bsslist;
u32 noise = 0;
char *current_ev = extra;
union oid_res_t r;
if (islpci_get_state(priv) < PRV_STATE_INIT) {
dwrq->length = 0;
return 0;
}
rvalue = mgt_get_request(priv, DOT11_OID_NOISEFLOOR, 0, NULL, &r);
noise = r.u;
rvalue |= mgt_get_request(priv, DOT11_OID_BSSLIST, 0, NULL, &r);
bsslist = r.ptr;
for (i = 0; i < (int) bsslist->nr; i++) {
current_ev = prism54_translate_bss(ndev, info, current_ev,
extra + dwrq->length,
&(bsslist->bsslist[i]),
noise);
if((extra + dwrq->length - current_ev) <= IW_EV_ADDR_LEN) {
rvalue = -E2BIG;
break;
}
}
kfree(bsslist);
dwrq->length = (current_ev - extra);
dwrq->flags = 0;
return rvalue;
}
static int
prism54_set_essid(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct obj_ssid essid;
memset(essid.octets, 0, 33);
if (dwrq->flags && dwrq->length) {
if (dwrq->length > 32)
return -E2BIG;
essid.length = dwrq->length;
memcpy(essid.octets, extra, dwrq->length);
} else
essid.length = 0;
if (priv->iw_mode != IW_MODE_MONITOR)
return mgt_set_request(priv, DOT11_OID_SSID, 0, &essid);
mgt_set(priv, DOT11_OID_SSID, &essid);
return 0;
}
static int
prism54_get_essid(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct obj_ssid *essid;
union oid_res_t r;
int rvalue;
rvalue = mgt_get_request(priv, DOT11_OID_SSID, 0, NULL, &r);
essid = r.ptr;
if (essid->length) {
dwrq->flags = 1;
dwrq->length = min((u8)IW_ESSID_MAX_SIZE, essid->length);
} else {
dwrq->flags = 0;
dwrq->length = 0;
}
essid->octets[dwrq->length] = '\0';
memcpy(extra, essid->octets, dwrq->length);
kfree(essid);
return rvalue;
}
static int
prism54_set_nick(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
if (dwrq->length > IW_ESSID_MAX_SIZE)
return -E2BIG;
down_write(&priv->mib_sem);
memset(priv->nickname, 0, sizeof (priv->nickname));
memcpy(priv->nickname, extra, dwrq->length);
up_write(&priv->mib_sem);
return 0;
}
static int
prism54_get_nick(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
dwrq->length = 0;
down_read(&priv->mib_sem);
dwrq->length = strlen(priv->nickname);
memcpy(extra, priv->nickname, dwrq->length);
up_read(&priv->mib_sem);
return 0;
}
static int
prism54_set_rate(struct net_device *ndev,
struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
u32 rate, profile;
char *data;
int ret, i;
union oid_res_t r;
if (vwrq->value == -1) {
profile = 1;
return mgt_set_request(priv, DOT11_OID_PROFILES, 0, &profile);
}
ret = mgt_get_request(priv, DOT11_OID_SUPPORTEDRATES, 0, NULL, &r);
if (ret) {
kfree(r.ptr);
return ret;
}
rate = (u32) (vwrq->value / 500000);
data = r.ptr;
i = 0;
while (data[i]) {
if (rate && (data[i] == rate)) {
break;
}
if (vwrq->value == i) {
break;
}
data[i] |= 0x80;
i++;
}
if (!data[i]) {
kfree(r.ptr);
return -EINVAL;
}
data[i] |= 0x80;
data[i + 1] = 0;
if (vwrq->fixed) {
data[0] = data[i];
data[1] = 0;
}
profile = -1;
ret = mgt_set_request(priv, DOT11_OID_PROFILES, 0, &profile);
ret |= mgt_set_request(priv, DOT11_OID_EXTENDEDRATES, 0, data);
ret |= mgt_set_request(priv, DOT11_OID_RATES, 0, data);
kfree(r.ptr);
return ret;
}
static int
prism54_get_rate(struct net_device *ndev,
struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
int rvalue;
char *data;
union oid_res_t r;
if ((rvalue = mgt_get_request(priv, GEN_OID_LINKSTATE, 0, NULL, &r)))
return rvalue;
vwrq->value = r.u * 500000;
rvalue = mgt_get_request(priv, DOT11_OID_RATES, 0, NULL, &r);
if (rvalue) {
kfree(r.ptr);
return rvalue;
}
data = r.ptr;
vwrq->fixed = (data[0] != 0) && (data[1] == 0);
kfree(r.ptr);
return 0;
}
static int
prism54_set_rts(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
return mgt_set_request(priv, DOT11_OID_RTSTHRESH, 0, &vwrq->value);
}
static int
prism54_get_rts(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
union oid_res_t r;
int rvalue;
rvalue = mgt_get_request(priv, DOT11_OID_RTSTHRESH, 0, NULL, &r);
vwrq->value = r.u;
return rvalue;
}
static int
prism54_set_frag(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
return mgt_set_request(priv, DOT11_OID_FRAGTHRESH, 0, &vwrq->value);
}
static int
prism54_get_frag(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
union oid_res_t r;
int rvalue;
rvalue = mgt_get_request(priv, DOT11_OID_FRAGTHRESH, 0, NULL, &r);
vwrq->value = r.u;
return rvalue;
}
static int
prism54_set_retry(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
u32 slimit = 0, llimit = 0;
u32 lifetime = 0;
int rvalue = 0;
if (vwrq->disabled)
return -EINVAL;
if (vwrq->flags & IW_RETRY_LIMIT) {
if (vwrq->flags & IW_RETRY_SHORT)
slimit = vwrq->value;
else if (vwrq->flags & IW_RETRY_LONG)
llimit = vwrq->value;
else {
slimit = vwrq->value;
llimit = vwrq->value;
}
}
if (vwrq->flags & IW_RETRY_LIFETIME)
lifetime = vwrq->value / 1024;
if (slimit)
rvalue =
mgt_set_request(priv, DOT11_OID_SHORTRETRIES, 0, &slimit);
if (llimit)
rvalue |=
mgt_set_request(priv, DOT11_OID_LONGRETRIES, 0, &llimit);
if (lifetime)
rvalue |=
mgt_set_request(priv, DOT11_OID_MAXTXLIFETIME, 0,
&lifetime);
return rvalue;
}
static int
prism54_get_retry(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
union oid_res_t r;
int rvalue = 0;
vwrq->disabled = 0;
if ((vwrq->flags & IW_RETRY_TYPE) == IW_RETRY_LIFETIME) {
rvalue =
mgt_get_request(priv, DOT11_OID_MAXTXLIFETIME, 0, NULL, &r);
vwrq->value = r.u * 1024;
vwrq->flags = IW_RETRY_LIFETIME;
} else if ((vwrq->flags & IW_RETRY_LONG)) {
rvalue |=
mgt_get_request(priv, DOT11_OID_LONGRETRIES, 0, NULL, &r);
vwrq->value = r.u;
vwrq->flags = IW_RETRY_LIMIT | IW_RETRY_LONG;
} else {
rvalue |=
mgt_get_request(priv, DOT11_OID_SHORTRETRIES, 0, NULL, &r);
vwrq->value = r.u;
vwrq->flags = IW_RETRY_LIMIT | IW_RETRY_SHORT;
}
return rvalue;
}
static int
prism54_set_encode(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
int rvalue = 0, force = 0;
int authen = DOT11_AUTH_OS, invoke = 0, exunencrypt = 0;
union oid_res_t r;
if (dwrq->length > 0) {
int index = (dwrq->flags & IW_ENCODE_INDEX) - 1;
int current_index;
struct obj_key key = { DOT11_PRIV_WEP, 0, "" };
rvalue = mgt_get_request(priv, DOT11_OID_DEFKEYID, 0, NULL, &r);
current_index = r.u;
if (!(dwrq->flags & IW_ENCODE_NOKEY)) {
if (dwrq->length > KEY_SIZE_TKIP) {
return -EINVAL;
}
if (dwrq->length > KEY_SIZE_WEP104) {
key.type = DOT11_PRIV_TKIP;
key.length = KEY_SIZE_TKIP;
} else if (dwrq->length > KEY_SIZE_WEP40) {
key.length = KEY_SIZE_WEP104;
} else {
key.length = KEY_SIZE_WEP40;
}
memset(key.key, 0, sizeof (key.key));
memcpy(key.key, extra, dwrq->length);
if ((index < 0) || (index > 3))
index = current_index;
rvalue |=
mgt_set_request(priv, DOT11_OID_DEFKEYX, index,
&key);
}
if ((index == current_index) && (key.length > 0))
force = 1;
} else {
int index = (dwrq->flags & IW_ENCODE_INDEX) - 1;
if ((index >= 0) && (index <= 3)) {
rvalue |=
mgt_set_request(priv, DOT11_OID_DEFKEYID, 0,
&index);
} else {
if (!(dwrq->flags & IW_ENCODE_MODE)) {
return -EINVAL;
}
}
}
if (dwrq->flags & IW_ENCODE_DISABLED) {
}
if (dwrq->flags & IW_ENCODE_OPEN)
invoke = 1;
if ((dwrq->flags & IW_ENCODE_RESTRICTED) || force) {
authen = DOT11_AUTH_BOTH;
invoke = 1;
exunencrypt = 1;
}
if ((dwrq->flags & IW_ENCODE_MODE) || force) {
rvalue |=
mgt_set_request(priv, DOT11_OID_AUTHENABLE, 0, &authen);
rvalue |=
mgt_set_request(priv, DOT11_OID_PRIVACYINVOKED, 0, &invoke);
rvalue |=
mgt_set_request(priv, DOT11_OID_EXUNENCRYPTED, 0,
&exunencrypt);
}
return rvalue;
}
static int
prism54_get_encode(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct obj_key *key;
u32 devindex, index = (dwrq->flags & IW_ENCODE_INDEX) - 1;
u32 authen = 0, invoke = 0, exunencrypt = 0;
int rvalue;
union oid_res_t r;
rvalue = mgt_get_request(priv, DOT11_OID_AUTHENABLE, 0, NULL, &r);
authen = r.u;
rvalue |= mgt_get_request(priv, DOT11_OID_PRIVACYINVOKED, 0, NULL, &r);
invoke = r.u;
rvalue |= mgt_get_request(priv, DOT11_OID_EXUNENCRYPTED, 0, NULL, &r);
exunencrypt = r.u;
if (invoke && (authen == DOT11_AUTH_BOTH) && exunencrypt)
dwrq->flags = IW_ENCODE_RESTRICTED;
else if ((authen == DOT11_AUTH_OS) && !exunencrypt) {
if (invoke)
dwrq->flags = IW_ENCODE_OPEN;
else
dwrq->flags = IW_ENCODE_DISABLED;
} else
dwrq->flags = 0;
rvalue |= mgt_get_request(priv, DOT11_OID_DEFKEYID, 0, NULL, &r);
devindex = r.u;
if (index == -1 || index > 3)
index = devindex;
rvalue |= mgt_get_request(priv, DOT11_OID_DEFKEYX, index, NULL, &r);
key = r.ptr;
dwrq->length = key->length;
memcpy(extra, key->key, dwrq->length);
kfree(key);
dwrq->flags |= devindex + 1;
return rvalue;
}
static int
prism54_get_txpower(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
union oid_res_t r;
int rvalue;
rvalue = mgt_get_request(priv, OID_INL_OUTPUTPOWER, 0, NULL, &r);
vwrq->value = (s32) r.u / 4;
vwrq->fixed = 1;
vwrq->disabled = 0;
return rvalue;
}
static int
prism54_set_txpower(struct net_device *ndev, struct iw_request_info *info,
struct iw_param *vwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
s32 u = vwrq->value;
u *= 4;
if (vwrq->disabled) {
printk(KERN_DEBUG
"%s: %s() disabling radio is not yet supported.\n",
priv->ndev->name, __func__);
return -ENOTSUPP;
} else if (vwrq->fixed)
return mgt_set_request(priv, OID_INL_OUTPUTPOWER, 0, &u);
else {
printk(KERN_DEBUG
"%s: %s() auto power will be implemented later.\n",
priv->ndev->name, __func__);
return -ENOTSUPP;
}
}
static int prism54_set_genie(struct net_device *ndev,
struct iw_request_info *info,
struct iw_point *data, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
int alen, ret = 0;
struct obj_attachment *attach;
if (data->length > MAX_WPA_IE_LEN ||
(data->length && extra == NULL))
return -EINVAL;
memcpy(priv->wpa_ie, extra, data->length);
priv->wpa_ie_len = data->length;
alen = sizeof(*attach) + priv->wpa_ie_len;
attach = kzalloc(alen, GFP_KERNEL);
if (attach == NULL)
return -ENOMEM;
#define WLAN_FC_TYPE_MGMT 0
#define WLAN_FC_STYPE_ASSOC_REQ 0
#define WLAN_FC_STYPE_REASSOC_REQ 2
attach->type = (WLAN_FC_TYPE_MGMT << 2) |
(WLAN_FC_STYPE_ASSOC_REQ << 4);
attach->id = -1;
attach->size = priv->wpa_ie_len;
memcpy(attach->data, extra, priv->wpa_ie_len);
ret = mgt_set_varlen(priv, DOT11_OID_ATTACHMENT, attach,
priv->wpa_ie_len);
if (ret == 0) {
attach->type = (WLAN_FC_TYPE_MGMT << 2) |
(WLAN_FC_STYPE_REASSOC_REQ << 4);
ret = mgt_set_varlen(priv, DOT11_OID_ATTACHMENT, attach,
priv->wpa_ie_len);
if (ret == 0)
printk(KERN_DEBUG "%s: WPA IE Attachment was set\n",
ndev->name);
}
kfree(attach);
return ret;
}
static int prism54_get_genie(struct net_device *ndev,
struct iw_request_info *info,
struct iw_point *data, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
int len = priv->wpa_ie_len;
if (len <= 0) {
data->length = 0;
return 0;
}
if (data->length < len)
return -E2BIG;
data->length = len;
memcpy(extra, priv->wpa_ie, len);
return 0;
}
static int prism54_set_auth(struct net_device *ndev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct iw_param *param = &wrqu->param;
u32 mlmelevel = 0, authen = 0, dot1x = 0;
u32 exunencrypt = 0, privinvoked = 0, wpa = 0;
u32 old_wpa;
int ret = 0;
union oid_res_t r;
if (islpci_get_state(priv) < PRV_STATE_INIT)
return 0;
down_write(&priv->mib_sem);
wpa = old_wpa = priv->wpa;
up_write(&priv->mib_sem);
ret = mgt_get_request(priv, DOT11_OID_AUTHENABLE, 0, NULL, &r);
authen = r.u;
ret = mgt_get_request(priv, DOT11_OID_PRIVACYINVOKED, 0, NULL, &r);
privinvoked = r.u;
ret = mgt_get_request(priv, DOT11_OID_EXUNENCRYPTED, 0, NULL, &r);
exunencrypt = r.u;
ret = mgt_get_request(priv, DOT11_OID_DOT1XENABLE, 0, NULL, &r);
dot1x = r.u;
ret = mgt_get_request(priv, DOT11_OID_MLMEAUTOLEVEL, 0, NULL, &r);
mlmelevel = r.u;
if (ret < 0)
goto out;
switch (param->flags & IW_AUTH_INDEX) {
case IW_AUTH_CIPHER_PAIRWISE:
case IW_AUTH_CIPHER_GROUP:
case IW_AUTH_KEY_MGMT:
break;
case IW_AUTH_WPA_ENABLED:
if (param->value) {
wpa = 1;
privinvoked = 1;
exunencrypt = 1;
dot1x = 0x01;
mlmelevel = DOT11_MLME_EXTENDED;
authen = DOT11_AUTH_OS;
} else {
wpa = 0;
privinvoked = 0;
exunencrypt = 0;
dot1x = 0;
mlmelevel = DOT11_MLME_AUTO;
}
break;
case IW_AUTH_WPA_VERSION:
if (param->value & IW_AUTH_WPA_VERSION_DISABLED) {
wpa = 0;
privinvoked = 0;
exunencrypt = 0;
dot1x = 0;
mlmelevel = DOT11_MLME_AUTO;
} else {
if (param->value & IW_AUTH_WPA_VERSION_WPA)
wpa = 1;
else if (param->value & IW_AUTH_WPA_VERSION_WPA2)
wpa = 2;
privinvoked = 1;
exunencrypt = 1;
dot1x = 0x01;
mlmelevel = DOT11_MLME_EXTENDED;
authen = DOT11_AUTH_OS;
}
break;
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
dot1x = param->value ? 0 : 0x01;
break;
case IW_AUTH_PRIVACY_INVOKED:
privinvoked = param->value ? 1 : 0;
break;
case IW_AUTH_DROP_UNENCRYPTED:
exunencrypt = param->value ? 1 : 0;
break;
case IW_AUTH_80211_AUTH_ALG:
if (param->value & IW_AUTH_ALG_SHARED_KEY) {
if (wpa > 0) {
ret = -EINVAL;
goto out;
}
authen = DOT11_AUTH_SK;
} else if (param->value & IW_AUTH_ALG_OPEN_SYSTEM) {
authen = DOT11_AUTH_OS;
} else {
ret = -EINVAL;
goto out;
}
break;
default:
return -EOPNOTSUPP;
}
down_write(&priv->mib_sem);
priv->wpa = wpa;
up_write(&priv->mib_sem);
mgt_set_request(priv, DOT11_OID_AUTHENABLE, 0, &authen);
mgt_set_request(priv, DOT11_OID_PRIVACYINVOKED, 0, &privinvoked);
mgt_set_request(priv, DOT11_OID_EXUNENCRYPTED, 0, &exunencrypt);
mgt_set_request(priv, DOT11_OID_DOT1XENABLE, 0, &dot1x);
mgt_set_request(priv, DOT11_OID_MLMEAUTOLEVEL, 0, &mlmelevel);
out:
return ret;
}
static int prism54_get_auth(struct net_device *ndev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct iw_param *param = &wrqu->param;
u32 wpa = 0;
int ret = 0;
union oid_res_t r;
if (islpci_get_state(priv) < PRV_STATE_INIT)
return 0;
down_write(&priv->mib_sem);
wpa = priv->wpa;
up_write(&priv->mib_sem);
switch (param->flags & IW_AUTH_INDEX) {
case IW_AUTH_CIPHER_PAIRWISE:
case IW_AUTH_CIPHER_GROUP:
case IW_AUTH_KEY_MGMT:
ret = -EOPNOTSUPP;
break;
case IW_AUTH_WPA_VERSION:
switch (wpa) {
case 1:
param->value = IW_AUTH_WPA_VERSION_WPA;
break;
case 2:
param->value = IW_AUTH_WPA_VERSION_WPA2;
break;
case 0:
default:
param->value = IW_AUTH_WPA_VERSION_DISABLED;
break;
}
break;
case IW_AUTH_DROP_UNENCRYPTED:
ret = mgt_get_request(priv, DOT11_OID_EXUNENCRYPTED, 0, NULL, &r);
if (ret >= 0)
param->value = r.u > 0 ? 1 : 0;
break;
case IW_AUTH_80211_AUTH_ALG:
ret = mgt_get_request(priv, DOT11_OID_AUTHENABLE, 0, NULL, &r);
if (ret >= 0) {
switch (r.u) {
case DOT11_AUTH_OS:
param->value = IW_AUTH_ALG_OPEN_SYSTEM;
break;
case DOT11_AUTH_BOTH:
case DOT11_AUTH_SK:
param->value = IW_AUTH_ALG_SHARED_KEY;
case DOT11_AUTH_NONE:
default:
param->value = 0;
break;
}
}
break;
case IW_AUTH_WPA_ENABLED:
param->value = wpa > 0 ? 1 : 0;
break;
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
ret = mgt_get_request(priv, DOT11_OID_DOT1XENABLE, 0, NULL, &r);
if (ret >= 0)
param->value = r.u > 0 ? 1 : 0;
break;
case IW_AUTH_PRIVACY_INVOKED:
ret = mgt_get_request(priv, DOT11_OID_PRIVACYINVOKED, 0, NULL, &r);
if (ret >= 0)
param->value = r.u > 0 ? 1 : 0;
break;
default:
return -EOPNOTSUPP;
}
return ret;
}
static int prism54_set_encodeext(struct net_device *ndev,
struct iw_request_info *info,
union iwreq_data *wrqu,
char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct iw_point *encoding = &wrqu->encoding;
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
int idx, alg = ext->alg, set_key = 1;
union oid_res_t r;
int authen = DOT11_AUTH_OS, invoke = 0, exunencrypt = 0;
int ret = 0;
if (islpci_get_state(priv) < PRV_STATE_INIT)
return 0;
idx = (encoding->flags & IW_ENCODE_INDEX) - 1;
if (idx) {
if (idx < 0 || idx > 3)
return -EINVAL;
} else {
ret = mgt_get_request(priv, DOT11_OID_DEFKEYID, 0, NULL, &r);
if (ret < 0)
goto out;
idx = r.u;
}
if (encoding->flags & IW_ENCODE_DISABLED)
alg = IW_ENCODE_ALG_NONE;
if (ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY) {
ret = mgt_set_request(priv, DOT11_OID_DEFKEYID, 0, &idx);
set_key = ext->key_len > 0 ? 1 : 0;
}
if (set_key) {
struct obj_key key = { DOT11_PRIV_WEP, 0, "" };
switch (alg) {
case IW_ENCODE_ALG_NONE:
break;
case IW_ENCODE_ALG_WEP:
if (ext->key_len > KEY_SIZE_WEP104) {
ret = -EINVAL;
goto out;
}
if (ext->key_len > KEY_SIZE_WEP40)
key.length = KEY_SIZE_WEP104;
else
key.length = KEY_SIZE_WEP40;
break;
case IW_ENCODE_ALG_TKIP:
if (ext->key_len > KEY_SIZE_TKIP) {
ret = -EINVAL;
goto out;
}
key.type = DOT11_PRIV_TKIP;
key.length = KEY_SIZE_TKIP;
break;
default:
return -EINVAL;
}
if (key.length) {
memset(key.key, 0, sizeof(key.key));
memcpy(key.key, ext->key, ext->key_len);
ret = mgt_set_request(priv, DOT11_OID_DEFKEYX, idx,
&key);
if (ret < 0)
goto out;
}
}
if (encoding->flags & IW_ENCODE_DISABLED) {
}
if (encoding->flags & IW_ENCODE_OPEN) {
invoke = 1;
}
if (encoding->flags & IW_ENCODE_RESTRICTED) {
authen = DOT11_AUTH_BOTH;
invoke = 1;
exunencrypt = 1;
}
if (encoding->flags & IW_ENCODE_MODE) {
ret = mgt_set_request(priv, DOT11_OID_AUTHENABLE, 0,
&authen);
ret = mgt_set_request(priv, DOT11_OID_PRIVACYINVOKED, 0,
&invoke);
ret = mgt_set_request(priv, DOT11_OID_EXUNENCRYPTED, 0,
&exunencrypt);
}
out:
return ret;
}
static int prism54_get_encodeext(struct net_device *ndev,
struct iw_request_info *info,
union iwreq_data *wrqu,
char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct iw_point *encoding = &wrqu->encoding;
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
int idx, max_key_len;
union oid_res_t r;
int authen = DOT11_AUTH_OS, invoke = 0, exunencrypt = 0, wpa = 0;
int ret = 0;
if (islpci_get_state(priv) < PRV_STATE_INIT)
return 0;
ret = mgt_get_request(priv, DOT11_OID_AUTHENABLE, 0, NULL, &r);
authen = r.u;
ret = mgt_get_request(priv, DOT11_OID_PRIVACYINVOKED, 0, NULL, &r);
invoke = r.u;
ret = mgt_get_request(priv, DOT11_OID_EXUNENCRYPTED, 0, NULL, &r);
exunencrypt = r.u;
if (ret < 0)
goto out;
max_key_len = encoding->length - sizeof(*ext);
if (max_key_len < 0)
return -EINVAL;
idx = (encoding->flags & IW_ENCODE_INDEX) - 1;
if (idx) {
if (idx < 0 || idx > 3)
return -EINVAL;
} else {
ret = mgt_get_request(priv, DOT11_OID_DEFKEYID, 0, NULL, &r);
if (ret < 0)
goto out;
idx = r.u;
}
encoding->flags = idx + 1;
memset(ext, 0, sizeof(*ext));
switch (authen) {
case DOT11_AUTH_BOTH:
case DOT11_AUTH_SK:
wrqu->encoding.flags |= IW_ENCODE_RESTRICTED;
case DOT11_AUTH_OS:
default:
wrqu->encoding.flags |= IW_ENCODE_OPEN;
break;
}
down_write(&priv->mib_sem);
wpa = priv->wpa;
up_write(&priv->mib_sem);
if (authen == DOT11_AUTH_OS && !exunencrypt && !invoke && !wpa) {
ext->alg = IW_ENCODE_ALG_NONE;
ext->key_len = 0;
wrqu->encoding.flags |= IW_ENCODE_DISABLED;
} else {
struct obj_key *key;
ret = mgt_get_request(priv, DOT11_OID_DEFKEYX, idx, NULL, &r);
if (ret < 0)
goto out;
key = r.ptr;
if (max_key_len < key->length) {
ret = -E2BIG;
goto out;
}
memcpy(ext->key, key->key, key->length);
ext->key_len = key->length;
switch (key->type) {
case DOT11_PRIV_TKIP:
ext->alg = IW_ENCODE_ALG_TKIP;
break;
default:
case DOT11_PRIV_WEP:
ext->alg = IW_ENCODE_ALG_WEP;
break;
}
wrqu->encoding.flags |= IW_ENCODE_ENABLED;
}
out:
return ret;
}
static int
prism54_reset(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_reset(netdev_priv(ndev), 0);
return 0;
}
static int
prism54_get_oid(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
union oid_res_t r;
int rvalue;
enum oid_num_t n = dwrq->flags;
rvalue = mgt_get_request(netdev_priv(ndev), n, 0, NULL, &r);
dwrq->length = mgt_response_to_str(n, &r, extra);
if ((isl_oid[n].flags & OID_FLAG_TYPE) != OID_TYPE_U32)
kfree(r.ptr);
return rvalue;
}
static int
prism54_set_u32(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
u32 oid = uwrq[0], u = uwrq[1];
return mgt_set_request(netdev_priv(ndev), oid, 0, &u);
}
static int
prism54_set_raw(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
u32 oid = dwrq->flags;
return mgt_set_request(netdev_priv(ndev), oid, 0, extra);
}
void
prism54_acl_init(struct islpci_acl *acl)
{
mutex_init(&acl->lock);
INIT_LIST_HEAD(&acl->mac_list);
acl->size = 0;
acl->policy = MAC_POLICY_OPEN;
}
static void
prism54_clear_mac(struct islpci_acl *acl)
{
struct list_head *ptr, *next;
struct mac_entry *entry;
mutex_lock(&acl->lock);
if (acl->size == 0) {
mutex_unlock(&acl->lock);
return;
}
for (ptr = acl->mac_list.next, next = ptr->next;
ptr != &acl->mac_list; ptr = next, next = ptr->next) {
entry = list_entry(ptr, struct mac_entry, _list);
list_del(ptr);
kfree(entry);
}
acl->size = 0;
mutex_unlock(&acl->lock);
}
void
prism54_acl_clean(struct islpci_acl *acl)
{
prism54_clear_mac(acl);
}
static int
prism54_add_mac(struct net_device *ndev, struct iw_request_info *info,
struct sockaddr *awrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct islpci_acl *acl = &priv->acl;
struct mac_entry *entry;
struct sockaddr *addr = (struct sockaddr *) extra;
if (addr->sa_family != ARPHRD_ETHER)
return -EOPNOTSUPP;
entry = kmalloc(sizeof (struct mac_entry), GFP_KERNEL);
if (entry == NULL)
return -ENOMEM;
memcpy(entry->addr, addr->sa_data, ETH_ALEN);
if (mutex_lock_interruptible(&acl->lock)) {
kfree(entry);
return -ERESTARTSYS;
}
list_add_tail(&entry->_list, &acl->mac_list);
acl->size++;
mutex_unlock(&acl->lock);
return 0;
}
static int
prism54_del_mac(struct net_device *ndev, struct iw_request_info *info,
struct sockaddr *awrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct islpci_acl *acl = &priv->acl;
struct mac_entry *entry;
struct sockaddr *addr = (struct sockaddr *) extra;
if (addr->sa_family != ARPHRD_ETHER)
return -EOPNOTSUPP;
if (mutex_lock_interruptible(&acl->lock))
return -ERESTARTSYS;
list_for_each_entry(entry, &acl->mac_list, _list) {
if (memcmp(entry->addr, addr->sa_data, ETH_ALEN) == 0) {
list_del(&entry->_list);
acl->size--;
kfree(entry);
mutex_unlock(&acl->lock);
return 0;
}
}
mutex_unlock(&acl->lock);
return -EINVAL;
}
static int
prism54_get_mac(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct islpci_acl *acl = &priv->acl;
struct mac_entry *entry;
struct sockaddr *dst = (struct sockaddr *) extra;
dwrq->length = 0;
if (mutex_lock_interruptible(&acl->lock))
return -ERESTARTSYS;
list_for_each_entry(entry, &acl->mac_list, _list) {
memcpy(dst->sa_data, entry->addr, ETH_ALEN);
dst->sa_family = ARPHRD_ETHER;
dwrq->length++;
dst++;
}
mutex_unlock(&acl->lock);
return 0;
}
static int
prism54_set_policy(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct islpci_acl *acl = &priv->acl;
u32 mlmeautolevel;
prism54_clear_mac(acl);
if ((*uwrq < MAC_POLICY_OPEN) || (*uwrq > MAC_POLICY_REJECT))
return -EINVAL;
down_write(&priv->mib_sem);
acl->policy = *uwrq;
if ((priv->iw_mode == IW_MODE_MASTER) &&
(acl->policy != MAC_POLICY_OPEN))
mlmeautolevel = DOT11_MLME_INTERMEDIATE;
else
mlmeautolevel = CARD_DEFAULT_MLME_MODE;
if (priv->wpa)
mlmeautolevel = DOT11_MLME_EXTENDED;
mgt_set(priv, DOT11_OID_MLMEAUTOLEVEL, &mlmeautolevel);
if (mgt_commit(priv)) {
up_write(&priv->mib_sem);
return -EIO;
}
up_write(&priv->mib_sem);
return 0;
}
static int
prism54_get_policy(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct islpci_acl *acl = &priv->acl;
*uwrq = acl->policy;
return 0;
}
static int
prism54_mac_accept(struct islpci_acl *acl, char *mac)
{
struct mac_entry *entry;
int res = 0;
if (mutex_lock_interruptible(&acl->lock))
return -ERESTARTSYS;
if (acl->policy == MAC_POLICY_OPEN) {
mutex_unlock(&acl->lock);
return 1;
}
list_for_each_entry(entry, &acl->mac_list, _list) {
if (memcmp(entry->addr, mac, ETH_ALEN) == 0) {
res = 1;
break;
}
}
res = (acl->policy == MAC_POLICY_ACCEPT) ? !res : res;
mutex_unlock(&acl->lock);
return res;
}
static int
prism54_kick_all(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *dwrq, char *extra)
{
struct obj_mlme *mlme;
int rvalue;
mlme = kmalloc(sizeof (struct obj_mlme), GFP_KERNEL);
if (mlme == NULL)
return -ENOMEM;
mlme->id = 0;
rvalue =
mgt_set_request(netdev_priv(ndev), DOT11_OID_DISASSOCIATE, 0, mlme);
kfree(mlme);
return rvalue;
}
static int
prism54_kick_mac(struct net_device *ndev, struct iw_request_info *info,
struct sockaddr *awrq, char *extra)
{
struct obj_mlme *mlme;
struct sockaddr *addr = (struct sockaddr *) extra;
int rvalue;
if (addr->sa_family != ARPHRD_ETHER)
return -EOPNOTSUPP;
mlme = kmalloc(sizeof (struct obj_mlme), GFP_KERNEL);
if (mlme == NULL)
return -ENOMEM;
memcpy(mlme->address, addr->sa_data, ETH_ALEN);
mlme->id = -1;
rvalue =
mgt_set_request(netdev_priv(ndev), DOT11_OID_DISASSOCIATE, 0, mlme);
kfree(mlme);
return rvalue;
}
static void
format_event(islpci_private *priv, char *dest, const char *str,
const struct obj_mlme *mlme, u16 *length, int error)
{
int n = snprintf(dest, IW_CUSTOM_MAX,
"%s %s %pM %s (%2.2X)",
str,
((priv->iw_mode == IW_MODE_MASTER) ? "from" : "to"),
mlme->address,
(error ? (mlme->code ? " : REJECTED " : " : ACCEPTED ")
: ""), mlme->code);
BUG_ON(n > IW_CUSTOM_MAX);
*length = n;
}
static void
send_formatted_event(islpci_private *priv, const char *str,
const struct obj_mlme *mlme, int error)
{
union iwreq_data wrqu;
char *memptr;
memptr = kmalloc(IW_CUSTOM_MAX, GFP_KERNEL);
if (!memptr)
return;
wrqu.data.pointer = memptr;
wrqu.data.length = 0;
format_event(priv, memptr, str, mlme, &wrqu.data.length,
error);
wireless_send_event(priv->ndev, IWEVCUSTOM, &wrqu, memptr);
kfree(memptr);
}
static void
send_simple_event(islpci_private *priv, const char *str)
{
union iwreq_data wrqu;
char *memptr;
int n = strlen(str);
memptr = kmalloc(IW_CUSTOM_MAX, GFP_KERNEL);
if (!memptr)
return;
BUG_ON(n >= IW_CUSTOM_MAX);
wrqu.data.pointer = memptr;
wrqu.data.length = n;
strcpy(memptr, str);
wireless_send_event(priv->ndev, IWEVCUSTOM, &wrqu, memptr);
kfree(memptr);
}
static void
link_changed(struct net_device *ndev, u32 bitrate)
{
islpci_private *priv = netdev_priv(ndev);
if (bitrate) {
netif_carrier_on(ndev);
if (priv->iw_mode == IW_MODE_INFRA) {
union iwreq_data uwrq;
prism54_get_wap(ndev, NULL, (struct sockaddr *) &uwrq,
NULL);
wireless_send_event(ndev, SIOCGIWAP, &uwrq, NULL);
} else
send_simple_event(netdev_priv(ndev),
"Link established");
} else {
netif_carrier_off(ndev);
send_simple_event(netdev_priv(ndev), "Link lost");
}
}
static void
prism54_wpa_bss_ie_add(islpci_private *priv, u8 *bssid,
u8 *wpa_ie, size_t wpa_ie_len)
{
struct list_head *ptr;
struct islpci_bss_wpa_ie *bss = NULL;
if (wpa_ie_len > MAX_WPA_IE_LEN)
wpa_ie_len = MAX_WPA_IE_LEN;
mutex_lock(&priv->wpa_lock);
list_for_each(ptr, &priv->bss_wpa_list) {
bss = list_entry(ptr, struct islpci_bss_wpa_ie, list);
if (memcmp(bss->bssid, bssid, ETH_ALEN) == 0) {
list_move(&bss->list, &priv->bss_wpa_list);
break;
}
bss = NULL;
}
if (bss == NULL) {
if (priv->num_bss_wpa >= MAX_BSS_WPA_IE_COUNT) {
bss = list_entry(priv->bss_wpa_list.prev,
struct islpci_bss_wpa_ie, list);
list_del(&bss->list);
} else {
bss = kzalloc(sizeof (*bss), GFP_ATOMIC);
if (bss != NULL)
priv->num_bss_wpa++;
}
if (bss != NULL) {
memcpy(bss->bssid, bssid, ETH_ALEN);
list_add(&bss->list, &priv->bss_wpa_list);
}
}
if (bss != NULL) {
memcpy(bss->wpa_ie, wpa_ie, wpa_ie_len);
bss->wpa_ie_len = wpa_ie_len;
bss->last_update = jiffies;
} else {
printk(KERN_DEBUG "Failed to add BSS WPA entry for "
"%pM\n", bssid);
}
while (priv->num_bss_wpa > 0) {
bss = list_entry(priv->bss_wpa_list.prev,
struct islpci_bss_wpa_ie, list);
if (!time_after(jiffies, bss->last_update + 60 * HZ))
break;
list_del(&bss->list);
priv->num_bss_wpa--;
kfree(bss);
}
mutex_unlock(&priv->wpa_lock);
}
static size_t
prism54_wpa_bss_ie_get(islpci_private *priv, u8 *bssid, u8 *wpa_ie)
{
struct list_head *ptr;
struct islpci_bss_wpa_ie *bss = NULL;
size_t len = 0;
mutex_lock(&priv->wpa_lock);
list_for_each(ptr, &priv->bss_wpa_list) {
bss = list_entry(ptr, struct islpci_bss_wpa_ie, list);
if (memcmp(bss->bssid, bssid, ETH_ALEN) == 0)
break;
bss = NULL;
}
if (bss) {
len = bss->wpa_ie_len;
memcpy(wpa_ie, bss->wpa_ie, len);
}
mutex_unlock(&priv->wpa_lock);
return len;
}
void
prism54_wpa_bss_ie_init(islpci_private *priv)
{
INIT_LIST_HEAD(&priv->bss_wpa_list);
mutex_init(&priv->wpa_lock);
}
void
prism54_wpa_bss_ie_clean(islpci_private *priv)
{
struct islpci_bss_wpa_ie *bss, *n;
list_for_each_entry_safe(bss, n, &priv->bss_wpa_list, list) {
kfree(bss);
}
}
static void
prism54_process_bss_data(islpci_private *priv, u32 oid, u8 *addr,
u8 *payload, size_t len)
{
struct ieee80211_beacon_phdr *hdr;
u8 *pos, *end;
if (!priv->wpa)
return;
hdr = (struct ieee80211_beacon_phdr *) payload;
pos = (u8 *) (hdr + 1);
end = payload + len;
while (pos < end) {
if (pos + 2 + pos[1] > end) {
printk(KERN_DEBUG "Parsing Beacon/ProbeResp failed "
"for %pM\n", addr);
return;
}
if (pos[0] == WLAN_EID_GENERIC && pos[1] >= 4 &&
memcmp(pos + 2, wpa_oid, 4) == 0) {
prism54_wpa_bss_ie_add(priv, addr, pos, pos[1] + 2);
return;
}
pos += 2 + pos[1];
}
}
static void
handle_request(islpci_private *priv, struct obj_mlme *mlme, enum oid_num_t oid)
{
if (((mlme->state == DOT11_STATE_AUTHING) ||
(mlme->state == DOT11_STATE_ASSOCING))
&& mgt_mlme_answer(priv)) {
mlme->code = prism54_mac_accept(&priv->acl,
mlme->address) ? 0 : 1;
mgt_set_request(priv, oid, 0, mlme);
}
}
static int
prism54_process_trap_helper(islpci_private *priv, enum oid_num_t oid,
char *data)
{
struct obj_mlme *mlme = (struct obj_mlme *) data;
struct obj_mlmeex *mlmeex = (struct obj_mlmeex *) data;
struct obj_mlmeex *confirm;
u8 wpa_ie[MAX_WPA_IE_LEN];
int wpa_ie_len;
size_t len = 0;
u8 *payload = NULL, *pos = NULL;
int ret;
if (oid >= DOT11_OID_BEACON) {
len = mlmeex->size;
payload = pos = mlmeex->data;
}
if ((oid == DOT11_OID_BEACON) || (oid == DOT11_OID_PROBE))
prism54_process_bss_data(priv, oid, mlmeex->address,
payload, len);
mgt_le_to_cpu(isl_oid[oid].flags & OID_FLAG_TYPE, (void *) mlme);
switch (oid) {
case GEN_OID_LINKSTATE:
link_changed(priv->ndev, (u32) *data);
break;
case DOT11_OID_MICFAILURE:
send_simple_event(priv, "Mic failure");
break;
case DOT11_OID_DEAUTHENTICATE:
send_formatted_event(priv, "DeAuthenticate request", mlme, 0);
break;
case DOT11_OID_AUTHENTICATE:
handle_request(priv, mlme, oid);
send_formatted_event(priv, "Authenticate request", mlme, 1);
break;
case DOT11_OID_DISASSOCIATE:
send_formatted_event(priv, "Disassociate request", mlme, 0);
break;
case DOT11_OID_ASSOCIATE:
handle_request(priv, mlme, oid);
send_formatted_event(priv, "Associate request", mlme, 1);
break;
case DOT11_OID_REASSOCIATE:
handle_request(priv, mlme, oid);
send_formatted_event(priv, "ReAssociate request", mlme, 1);
break;
case DOT11_OID_BEACON:
send_formatted_event(priv,
"Received a beacon from an unknown AP",
mlme, 0);
break;
case DOT11_OID_PROBE:
send_formatted_event(priv, "Received a probe from client", mlme,
0);
break;
case DOT11_OID_DEAUTHENTICATEEX:
send_formatted_event(priv, "DeAuthenticate request", mlme, 0);
break;
case DOT11_OID_AUTHENTICATEEX:
handle_request(priv, mlme, oid);
send_formatted_event(priv, "Authenticate request (ex)", mlme, 1);
if (priv->iw_mode != IW_MODE_MASTER
&& mlmeex->state != DOT11_STATE_AUTHING)
break;
confirm = kmalloc(sizeof(struct obj_mlmeex) + 6, GFP_ATOMIC);
if (!confirm)
break;
memcpy(&confirm->address, mlmeex->address, ETH_ALEN);
printk(KERN_DEBUG "Authenticate from: address:\t%pM\n",
mlmeex->address);
confirm->id = -1;
confirm->state = 0;
confirm->code = 0;
confirm->size = 6;
confirm->data[0] = 0x00;
confirm->data[1] = 0x00;
confirm->data[2] = 0x02;
confirm->data[3] = 0x00;
confirm->data[4] = 0x00;
confirm->data[5] = 0x00;
ret = mgt_set_varlen(priv, DOT11_OID_ASSOCIATEEX, confirm, 6);
kfree(confirm);
if (ret)
return ret;
break;
case DOT11_OID_DISASSOCIATEEX:
send_formatted_event(priv, "Disassociate request (ex)", mlme, 0);
break;
case DOT11_OID_ASSOCIATEEX:
handle_request(priv, mlme, oid);
send_formatted_event(priv, "Associate request (ex)", mlme, 1);
if (priv->iw_mode != IW_MODE_MASTER
&& mlmeex->state != DOT11_STATE_ASSOCING)
break;
confirm = kmalloc(sizeof(struct obj_mlmeex), GFP_ATOMIC);
if (!confirm)
break;
memcpy(&confirm->address, mlmeex->address, ETH_ALEN);
confirm->id = ((struct obj_mlmeex *)mlme)->id;
confirm->state = 0;
confirm->code = 0;
wpa_ie_len = prism54_wpa_bss_ie_get(priv, mlmeex->address, wpa_ie);
if (!wpa_ie_len) {
printk(KERN_DEBUG "No WPA IE found from address:\t%pM\n",
mlmeex->address);
kfree(confirm);
break;
}
confirm->size = wpa_ie_len;
memcpy(&confirm->data, wpa_ie, wpa_ie_len);
mgt_set_varlen(priv, oid, confirm, wpa_ie_len);
kfree(confirm);
break;
case DOT11_OID_REASSOCIATEEX:
handle_request(priv, mlme, oid);
send_formatted_event(priv, "Reassociate request (ex)", mlme, 1);
if (priv->iw_mode != IW_MODE_MASTER
&& mlmeex->state != DOT11_STATE_ASSOCING)
break;
confirm = kmalloc(sizeof(struct obj_mlmeex), GFP_ATOMIC);
if (!confirm)
break;
memcpy(&confirm->address, mlmeex->address, ETH_ALEN);
confirm->id = mlmeex->id;
confirm->state = 0;
confirm->code = 0;
wpa_ie_len = prism54_wpa_bss_ie_get(priv, mlmeex->address, wpa_ie);
if (!wpa_ie_len) {
printk(KERN_DEBUG "No WPA IE found from address:\t%pM\n",
mlmeex->address);
kfree(confirm);
break;
}
confirm->size = wpa_ie_len;
memcpy(&confirm->data, wpa_ie, wpa_ie_len);
mgt_set_varlen(priv, oid, confirm, wpa_ie_len);
kfree(confirm);
break;
default:
return -EINVAL;
}
return 0;
}
void
prism54_process_trap(struct work_struct *work)
{
struct islpci_mgmtframe *frame =
container_of(work, struct islpci_mgmtframe, ws);
struct net_device *ndev = frame->ndev;
enum oid_num_t n = mgt_oidtonum(frame->header->oid);
if (n != OID_NUM_LAST)
prism54_process_trap_helper(netdev_priv(ndev), n, frame->data);
islpci_mgt_release(frame);
}
int
prism54_set_mac_address(struct net_device *ndev, void *addr)
{
islpci_private *priv = netdev_priv(ndev);
int ret;
if (ndev->addr_len != 6)
return -EINVAL;
ret = mgt_set_request(priv, GEN_OID_MACADDRESS, 0,
&((struct sockaddr *) addr)->sa_data);
if (!ret)
memcpy(priv->ndev->dev_addr,
&((struct sockaddr *) addr)->sa_data, 6);
return ret;
}
static int
prism2_ioctl_set_encryption(struct net_device *dev,
struct prism2_hostapd_param *param,
int param_len)
{
islpci_private *priv = netdev_priv(dev);
int rvalue = 0, force = 0;
int authen = DOT11_AUTH_OS, invoke = 0, exunencrypt = 0;
union oid_res_t r;
if (param->u.crypt.key_len > 0) {
int index = param->u.crypt.idx;
int current_index;
struct obj_key key = { DOT11_PRIV_TKIP, 0, "" };
rvalue = mgt_get_request(priv, DOT11_OID_DEFKEYID, 0, NULL, &r);
current_index = r.u;
if (!(param->u.crypt.flags & IW_ENCODE_NOKEY)) {
key.length = param->u.crypt.key_len > sizeof (param->u.crypt.key) ?
sizeof (param->u.crypt.key) : param->u.crypt.key_len;
memcpy(key.key, param->u.crypt.key, key.length);
if (key.length == 32)
key.type = DOT11_PRIV_TKIP;
if ((index < 0) || (index > 3))
index = current_index;
rvalue |=
mgt_set_request(priv, DOT11_OID_DEFKEYX, index,
&key);
}
if ((index == current_index) && (key.length > 0))
force = 1;
} else {
int index = (param->u.crypt.flags & IW_ENCODE_INDEX) - 1;
if ((index >= 0) && (index <= 3)) {
rvalue |=
mgt_set_request(priv, DOT11_OID_DEFKEYID, 0,
&index);
} else {
if (!(param->u.crypt.flags & IW_ENCODE_MODE)) {
return -EINVAL;
}
}
}
if (param->u.crypt.flags & IW_ENCODE_DISABLED) {
}
if (param->u.crypt.flags & IW_ENCODE_OPEN)
invoke = 1;
if ((param->u.crypt.flags & IW_ENCODE_RESTRICTED) || force) {
authen = DOT11_AUTH_BOTH;
invoke = 1;
exunencrypt = 1;
}
if ((param->u.crypt.flags & IW_ENCODE_MODE) || force) {
rvalue |=
mgt_set_request(priv, DOT11_OID_AUTHENABLE, 0, &authen);
rvalue |=
mgt_set_request(priv, DOT11_OID_PRIVACYINVOKED, 0, &invoke);
rvalue |=
mgt_set_request(priv, DOT11_OID_EXUNENCRYPTED, 0,
&exunencrypt);
}
return rvalue;
}
static int
prism2_ioctl_set_generic_element(struct net_device *ndev,
struct prism2_hostapd_param *param,
int param_len)
{
islpci_private *priv = netdev_priv(ndev);
int max_len, len, alen, ret=0;
struct obj_attachment *attach;
len = param->u.generic_elem.len;
max_len = param_len - PRISM2_HOSTAPD_GENERIC_ELEMENT_HDR_LEN;
if (max_len < 0 || max_len < len)
return -EINVAL;
alen = sizeof(*attach) + len;
attach = kzalloc(alen, GFP_KERNEL);
if (attach == NULL)
return -ENOMEM;
#define WLAN_FC_TYPE_MGMT 0
#define WLAN_FC_STYPE_ASSOC_REQ 0
#define WLAN_FC_STYPE_REASSOC_REQ 2
attach->type = (WLAN_FC_TYPE_MGMT << 2) |
(WLAN_FC_STYPE_ASSOC_REQ << 4);
attach->id = -1;
attach->size = len;
memcpy(attach->data, param->u.generic_elem.data, len);
ret = mgt_set_varlen(priv, DOT11_OID_ATTACHMENT, attach, len);
if (ret == 0) {
attach->type = (WLAN_FC_TYPE_MGMT << 2) |
(WLAN_FC_STYPE_REASSOC_REQ << 4);
ret = mgt_set_varlen(priv, DOT11_OID_ATTACHMENT, attach, len);
if (ret == 0)
printk(KERN_DEBUG "%s: WPA IE Attachment was set\n",
ndev->name);
}
kfree(attach);
return ret;
}
static int
prism2_ioctl_mlme(struct net_device *dev, struct prism2_hostapd_param *param)
{
return -EOPNOTSUPP;
}
static int
prism2_ioctl_scan_req(struct net_device *ndev,
struct prism2_hostapd_param *param)
{
islpci_private *priv = netdev_priv(ndev);
struct iw_request_info info;
int i, rvalue;
struct obj_bsslist *bsslist;
u32 noise = 0;
char *extra = "";
char *current_ev = "foo";
union oid_res_t r;
if (islpci_get_state(priv) < PRV_STATE_INIT) {
return 0;
}
rvalue = mgt_get_request(priv, DOT11_OID_NOISEFLOOR, 0, NULL, &r);
noise = r.u;
rvalue |= mgt_get_request(priv, DOT11_OID_BSSLIST, 0, NULL, &r);
bsslist = r.ptr;
info.cmd = PRISM54_HOSTAPD;
info.flags = 0;
for (i = 0; i < min(IW_MAX_AP, (int) bsslist->nr); i++)
current_ev = prism54_translate_bss(ndev, &info, current_ev,
extra + IW_SCAN_MAX_DATA,
&(bsslist->bsslist[i]),
noise);
kfree(bsslist);
return rvalue;
}
static int
prism54_hostapd(struct net_device *ndev, struct iw_point *p)
{
struct prism2_hostapd_param *param;
int ret = 0;
u32 uwrq;
printk(KERN_DEBUG "prism54_hostapd - len=%d\n", p->length);
if (p->length < sizeof(struct prism2_hostapd_param) ||
p->length > PRISM2_HOSTAPD_MAX_BUF_SIZE || !p->pointer)
return -EINVAL;
param = memdup_user(p->pointer, p->length);
if (IS_ERR(param))
return PTR_ERR(param);
switch (param->cmd) {
case PRISM2_SET_ENCRYPTION:
printk(KERN_DEBUG "%s: Caught WPA supplicant set encryption request\n",
ndev->name);
ret = prism2_ioctl_set_encryption(ndev, param, p->length);
break;
case PRISM2_HOSTAPD_SET_GENERIC_ELEMENT:
printk(KERN_DEBUG "%s: Caught WPA supplicant set WPA IE request\n",
ndev->name);
ret = prism2_ioctl_set_generic_element(ndev, param,
p->length);
break;
case PRISM2_HOSTAPD_MLME:
printk(KERN_DEBUG "%s: Caught WPA supplicant MLME request\n",
ndev->name);
ret = prism2_ioctl_mlme(ndev, param);
break;
case PRISM2_HOSTAPD_SCAN_REQ:
printk(KERN_DEBUG "%s: Caught WPA supplicant scan request\n",
ndev->name);
ret = prism2_ioctl_scan_req(ndev, param);
break;
case PRISM54_SET_WPA:
printk(KERN_DEBUG "%s: Caught WPA supplicant wpa init request\n",
ndev->name);
uwrq = 1;
ret = prism54_set_wpa(ndev, NULL, &uwrq, NULL);
break;
case PRISM54_DROP_UNENCRYPTED:
printk(KERN_DEBUG "%s: Caught WPA drop unencrypted request\n",
ndev->name);
#if 0
uwrq = 0x01;
mgt_set(priv, DOT11_OID_EXUNENCRYPTED, &uwrq);
down_write(&priv->mib_sem);
mgt_commit(priv);
up_write(&priv->mib_sem);
#endif
ret = 0;
break;
default:
printk(KERN_DEBUG "%s: Caught a WPA supplicant request that is not supported\n",
ndev->name);
ret = -EOPNOTSUPP;
break;
}
if (ret == 0 && copy_to_user(p->pointer, param, p->length))
ret = -EFAULT;
kfree(param);
return ret;
}
static int
prism54_set_wpa(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
u32 mlme, authen, dot1x, filter, wep;
if (islpci_get_state(priv) < PRV_STATE_INIT)
return 0;
wep = 1;
filter = 1;
dot1x = 0x01;
mlme = DOT11_MLME_EXTENDED;
authen = DOT11_AUTH_OS;
down_write(&priv->mib_sem);
priv->wpa = *uwrq;
switch (priv->wpa) {
default:
case 0:
wep = 0;
filter = 0;
dot1x = 0;
mlme = DOT11_MLME_AUTO;
printk("%s: Disabling WPA\n", ndev->name);
break;
case 2:
case 1:
printk("%s: Enabling WPA\n", ndev->name);
break;
}
up_write(&priv->mib_sem);
mgt_set_request(priv, DOT11_OID_AUTHENABLE, 0, &authen);
mgt_set_request(priv, DOT11_OID_PRIVACYINVOKED, 0, &wep);
mgt_set_request(priv, DOT11_OID_EXUNENCRYPTED, 0, &filter);
mgt_set_request(priv, DOT11_OID_DOT1XENABLE, 0, &dot1x);
mgt_set_request(priv, DOT11_OID_MLMEAUTOLEVEL, 0, &mlme);
return 0;
}
static int
prism54_get_wpa(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
*uwrq = priv->wpa;
return 0;
}
static int
prism54_set_prismhdr(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
priv->monitor_type =
(*uwrq ? ARPHRD_IEEE80211_PRISM : ARPHRD_IEEE80211);
if (priv->iw_mode == IW_MODE_MONITOR)
priv->ndev->type = priv->monitor_type;
return 0;
}
static int
prism54_get_prismhdr(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
*uwrq = (priv->monitor_type == ARPHRD_IEEE80211_PRISM);
return 0;
}
static int
prism54_debug_oid(struct net_device *ndev, struct iw_request_info *info,
__u32 * uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
priv->priv_oid = *uwrq;
printk("%s: oid 0x%08X\n", ndev->name, *uwrq);
return 0;
}
static int
prism54_debug_get_oid(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *data, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct islpci_mgmtframe *response;
int ret = -EIO;
printk("%s: get_oid 0x%08X\n", ndev->name, priv->priv_oid);
data->length = 0;
if (islpci_get_state(priv) >= PRV_STATE_INIT) {
ret =
islpci_mgt_transaction(priv->ndev, PIMFOR_OP_GET,
priv->priv_oid, extra, 256,
&response);
printk("%s: ret: %i\n", ndev->name, ret);
if (ret || !response
|| response->header->operation == PIMFOR_OP_ERROR) {
if (response) {
islpci_mgt_release(response);
}
printk("%s: EIO\n", ndev->name);
ret = -EIO;
}
if (!ret) {
data->length = response->header->length;
memcpy(extra, response->data, data->length);
islpci_mgt_release(response);
printk("%s: len: %i\n", ndev->name, data->length);
}
}
return ret;
}
static int
prism54_debug_set_oid(struct net_device *ndev, struct iw_request_info *info,
struct iw_point *data, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
struct islpci_mgmtframe *response;
int ret = 0, response_op = PIMFOR_OP_ERROR;
printk("%s: set_oid 0x%08X\tlen: %d\n", ndev->name, priv->priv_oid,
data->length);
if (islpci_get_state(priv) >= PRV_STATE_INIT) {
ret =
islpci_mgt_transaction(priv->ndev, PIMFOR_OP_SET,
priv->priv_oid, extra, data->length,
&response);
printk("%s: ret: %i\n", ndev->name, ret);
if (ret || !response
|| response->header->operation == PIMFOR_OP_ERROR) {
if (response) {
islpci_mgt_release(response);
}
printk("%s: EIO\n", ndev->name);
ret = -EIO;
}
if (!ret) {
response_op = response->header->operation;
printk("%s: response_op: %i\n", ndev->name,
response_op);
islpci_mgt_release(response);
}
}
return (ret ? ret : -EINPROGRESS);
}
static int
prism54_set_spy(struct net_device *ndev,
struct iw_request_info *info,
union iwreq_data *uwrq, char *extra)
{
islpci_private *priv = netdev_priv(ndev);
u32 u;
enum oid_num_t oid = OID_INL_CONFIG;
down_write(&priv->mib_sem);
mgt_get(priv, OID_INL_CONFIG, &u);
if ((uwrq->data.length == 0) && (priv->spy_data.spy_number > 0))
u &= ~INL_CONFIG_RXANNEX;
else if ((uwrq->data.length > 0) && (priv->spy_data.spy_number == 0))
u |= INL_CONFIG_RXANNEX;
mgt_set(priv, OID_INL_CONFIG, &u);
mgt_commit_list(priv, &oid, 1);
up_write(&priv->mib_sem);
return iw_handler_set_spy(ndev, info, uwrq, extra);
}
int
prism54_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
struct iwreq *wrq = (struct iwreq *) rq;
int ret = -1;
switch (cmd) {
case PRISM54_HOSTAPD:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
ret = prism54_hostapd(ndev, &wrq->u.data);
return ret;
}
return -EOPNOTSUPP;
}
