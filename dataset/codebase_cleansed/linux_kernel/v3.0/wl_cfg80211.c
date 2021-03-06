static void swap_key_from_BE(struct wl_wsec_key *key)
{
key->index = cpu_to_le32(key->index);
key->len = cpu_to_le32(key->len);
key->algo = cpu_to_le32(key->algo);
key->flags = cpu_to_le32(key->flags);
key->rxiv.hi = cpu_to_le32(key->rxiv.hi);
key->rxiv.lo = cpu_to_le16(key->rxiv.lo);
key->iv_initialized = cpu_to_le32(key->iv_initialized);
}
static void swap_key_to_BE(struct wl_wsec_key *key)
{
key->index = le32_to_cpu(key->index);
key->len = le32_to_cpu(key->len);
key->algo = le32_to_cpu(key->algo);
key->flags = le32_to_cpu(key->flags);
key->rxiv.hi = le32_to_cpu(key->rxiv.hi);
key->rxiv.lo = le16_to_cpu(key->rxiv.lo);
key->iv_initialized = le32_to_cpu(key->iv_initialized);
}
static s32
wl_dev_ioctl(struct net_device *dev, u32 cmd, void *arg, u32 len)
{
struct ifreq ifr;
struct wl_ioctl ioc;
mm_segment_t fs;
s32 err = 0;
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = cmd;
ioc.buf = arg;
ioc.len = len;
strcpy(ifr.ifr_name, dev->name);
ifr.ifr_data = (caddr_t)&ioc;
fs = get_fs();
set_fs(get_ds());
err = dev->netdev_ops->ndo_do_ioctl(dev, &ifr, SIOCDEVPRIVATE);
set_fs(fs);
return err;
}
static s32
wl_cfg80211_change_iface(struct wiphy *wiphy, struct net_device *ndev,
enum nl80211_iftype type, u32 *flags,
struct vif_params *params)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct wireless_dev *wdev;
s32 infra = 0;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
switch (type) {
case NL80211_IFTYPE_MONITOR:
case NL80211_IFTYPE_WDS:
WL_ERR("type (%d) : currently we do not support this type\n",
type);
return -EOPNOTSUPP;
case NL80211_IFTYPE_ADHOC:
wl->conf->mode = WL_MODE_IBSS;
infra = 0;
break;
case NL80211_IFTYPE_STATION:
wl->conf->mode = WL_MODE_BSS;
infra = 1;
break;
default:
err = -EINVAL;
goto done;
}
infra = cpu_to_le32(infra);
err = wl_dev_ioctl(ndev, WLC_SET_INFRA, &infra, sizeof(infra));
if (unlikely(err)) {
WL_ERR("WLC_SET_INFRA error (%d)\n", err);
err = -EAGAIN;
} else {
wdev = ndev->ieee80211_ptr;
wdev->iftype = type;
}
WL_INFO("IF Type = %s\n",
(wl->conf->mode == WL_MODE_IBSS) ? "Adhoc" : "Infra");
done:
WL_TRACE("Exit\n");
return err;
}
static void wl_iscan_prep(struct wl_scan_params *params, struct wlc_ssid *ssid)
{
memcpy(params->bssid, ether_bcast, ETH_ALEN);
params->bss_type = DOT11_BSSTYPE_ANY;
params->scan_type = 0;
params->nprobes = -1;
params->active_time = -1;
params->passive_time = -1;
params->home_time = -1;
params->channel_num = 0;
params->nprobes = cpu_to_le32(params->nprobes);
params->active_time = cpu_to_le32(params->active_time);
params->passive_time = cpu_to_le32(params->passive_time);
params->home_time = cpu_to_le32(params->home_time);
if (ssid && ssid->SSID_len)
memcpy(&params->ssid, ssid, sizeof(wlc_ssid_t));
}
static s32
wl_dev_iovar_setbuf(struct net_device *dev, s8 * iovar, void *param,
s32 paramlen, void *bufptr, s32 buflen)
{
s32 iolen;
iolen = bcm_mkiovar(iovar, param, paramlen, bufptr, buflen);
BUG_ON(!iolen);
return wl_dev_ioctl(dev, WLC_SET_VAR, bufptr, iolen);
}
static s32
wl_dev_iovar_getbuf(struct net_device *dev, s8 * iovar, void *param,
s32 paramlen, void *bufptr, s32 buflen)
{
s32 iolen;
iolen = bcm_mkiovar(iovar, param, paramlen, bufptr, buflen);
BUG_ON(!iolen);
return wl_dev_ioctl(dev, WLC_GET_VAR, bufptr, buflen);
}
static s32
wl_run_iscan(struct wl_iscan_ctrl *iscan, struct wlc_ssid *ssid, u16 action)
{
s32 params_size =
(WL_SCAN_PARAMS_FIXED_SIZE + offsetof(wl_iscan_params_t, params));
struct wl_iscan_params *params;
s32 err = 0;
if (ssid && ssid->SSID_len)
params_size += sizeof(struct wlc_ssid);
params = kzalloc(params_size, GFP_KERNEL);
if (unlikely(!params))
return -ENOMEM;
BUG_ON(params_size >= WLC_IOCTL_SMLEN);
wl_iscan_prep(&params->params, ssid);
params->version = cpu_to_le32(ISCAN_REQ_VERSION);
params->action = cpu_to_le16(action);
params->scan_duration = cpu_to_le16(0);
err = wl_dev_iovar_setbuf(iscan->dev, "iscan", params, params_size,
iscan->ioctl_buf, WLC_IOCTL_SMLEN);
if (unlikely(err)) {
if (err == -EBUSY) {
WL_INFO("system busy : iscan canceled\n");
} else {
WL_ERR("error (%d)\n", err);
}
}
kfree(params);
return err;
}
static s32 wl_do_iscan(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl_to_iscan(wl);
struct net_device *ndev = wl_to_ndev(wl);
struct wlc_ssid ssid;
s32 passive_scan;
s32 err = 0;
memset(&ssid, 0, sizeof(ssid));
iscan->state = WL_ISCAN_STATE_SCANING;
passive_scan = wl->active_scan ? 0 : 1;
err = wl_dev_ioctl(wl_to_ndev(wl), WLC_SET_PASSIVE_SCAN,
&passive_scan, sizeof(passive_scan));
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
wl_set_mpc(ndev, 0);
wl->iscan_kickstart = true;
wl_run_iscan(iscan, &ssid, WL_SCAN_ACTION_START);
mod_timer(&iscan->timer, jiffies + iscan->timer_ms * HZ / 1000);
iscan->timer_on = 1;
return err;
}
static s32
__wl_cfg80211_scan(struct wiphy *wiphy, struct net_device *ndev,
struct cfg80211_scan_request *request,
struct cfg80211_ssid *this_ssid)
{
struct wl_priv *wl = ndev_to_wl(ndev);
struct cfg80211_ssid *ssids;
struct wl_scan_req *sr = wl_to_sr(wl);
s32 passive_scan;
bool iscan_req;
bool spec_scan;
s32 err = 0;
if (unlikely(test_bit(WL_STATUS_SCANNING, &wl->status))) {
WL_ERR("Scanning already : status (%d)\n", (int)wl->status);
return -EAGAIN;
}
if (unlikely(test_bit(WL_STATUS_SCAN_ABORTING, &wl->status))) {
WL_ERR("Scanning being aborted : status (%d)\n",
(int)wl->status);
return -EAGAIN;
}
if (test_bit(WL_STATUS_CONNECTING, &wl->status)) {
WL_ERR("Connecting : status (%d)\n",
(int)wl->status);
return -EAGAIN;
}
iscan_req = false;
spec_scan = false;
if (request) {
ssids = request->ssids;
if (wl->iscan_on && (!ssids || !ssids->ssid_len))
iscan_req = true;
} else {
ssids = this_ssid;
}
wl->scan_request = request;
set_bit(WL_STATUS_SCANNING, &wl->status);
if (iscan_req) {
err = wl_do_iscan(wl);
if (likely(!err))
return err;
else
goto scan_out;
} else {
WL_SCAN("ssid \"%s\", ssid_len (%d)\n",
ssids->ssid, ssids->ssid_len);
memset(&sr->ssid, 0, sizeof(sr->ssid));
sr->ssid.SSID_len =
min_t(u8, sizeof(sr->ssid.SSID), ssids->ssid_len);
if (sr->ssid.SSID_len) {
memcpy(sr->ssid.SSID, ssids->ssid, sr->ssid.SSID_len);
sr->ssid.SSID_len = cpu_to_le32(sr->ssid.SSID_len);
spec_scan = true;
} else {
WL_SCAN("Broadcast scan\n");
}
passive_scan = wl->active_scan ? 0 : 1;
err = wl_dev_ioctl(ndev, WLC_SET_PASSIVE_SCAN,
&passive_scan, sizeof(passive_scan));
if (unlikely(err)) {
WL_ERR("WLC_SET_PASSIVE_SCAN error (%d)\n", err);
goto scan_out;
}
wl_set_mpc(ndev, 0);
err = wl_dev_ioctl(ndev, WLC_SCAN, &sr->ssid,
sizeof(sr->ssid));
if (err) {
if (err == -EBUSY) {
WL_INFO("system busy : scan for \"%s\" canceled\n",
sr->ssid.SSID);
} else {
WL_ERR("WLC_SCAN error (%d)\n", err);
}
wl_set_mpc(ndev, 1);
goto scan_out;
}
}
return 0;
scan_out:
clear_bit(WL_STATUS_SCANNING, &wl->status);
wl->scan_request = NULL;
return err;
}
static s32
wl_cfg80211_scan(struct wiphy *wiphy, struct net_device *ndev,
struct cfg80211_scan_request *request)
{
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
err = __wl_cfg80211_scan(wiphy, ndev, request, NULL);
if (unlikely(err))
WL_ERR("scan error (%d)\n", err);
WL_TRACE("Exit\n");
return err;
}
static s32 wl_dev_intvar_set(struct net_device *dev, s8 *name, s32 val)
{
s8 buf[WLC_IOCTL_SMLEN];
u32 len;
s32 err = 0;
val = cpu_to_le32(val);
len = bcm_mkiovar(name, (char *)(&val), sizeof(val), buf, sizeof(buf));
BUG_ON(!len);
err = wl_dev_ioctl(dev, WLC_SET_VAR, buf, len);
if (unlikely(err))
WL_ERR("error (%d)\n", err);
return err;
}
static s32
wl_dev_intvar_get(struct net_device *dev, s8 *name, s32 *retval)
{
union {
s8 buf[WLC_IOCTL_SMLEN];
s32 val;
} var;
u32 len;
u32 data_null;
s32 err = 0;
len =
bcm_mkiovar(name, (char *)(&data_null), 0, (char *)(&var),
sizeof(var.buf));
BUG_ON(!len);
err = wl_dev_ioctl(dev, WLC_GET_VAR, &var, len);
if (unlikely(err))
WL_ERR("error (%d)\n", err);
*retval = le32_to_cpu(var.val);
return err;
}
static s32 wl_set_rts(struct net_device *dev, u32 rts_threshold)
{
s32 err = 0;
err = wl_dev_intvar_set(dev, "rtsthresh", rts_threshold);
if (unlikely(err))
WL_ERR("Error (%d)\n", err);
return err;
}
static s32 wl_set_frag(struct net_device *dev, u32 frag_threshold)
{
s32 err = 0;
err = wl_dev_intvar_set(dev, "fragthresh", frag_threshold);
if (unlikely(err))
WL_ERR("Error (%d)\n", err);
return err;
}
static s32 wl_set_retry(struct net_device *dev, u32 retry, bool l)
{
s32 err = 0;
u32 cmd = (l ? WLC_SET_LRL : WLC_SET_SRL);
retry = cpu_to_le32(retry);
err = wl_dev_ioctl(dev, cmd, &retry, sizeof(retry));
if (unlikely(err)) {
WL_ERR("cmd (%d) , error (%d)\n", cmd, err);
return err;
}
return err;
}
static s32 wl_cfg80211_set_wiphy_params(struct wiphy *wiphy, u32 changed)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct net_device *ndev = wl_to_ndev(wl);
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
if (changed & WIPHY_PARAM_RTS_THRESHOLD &&
(wl->conf->rts_threshold != wiphy->rts_threshold)) {
wl->conf->rts_threshold = wiphy->rts_threshold;
err = wl_set_rts(ndev, wl->conf->rts_threshold);
if (!err)
goto done;
}
if (changed & WIPHY_PARAM_FRAG_THRESHOLD &&
(wl->conf->frag_threshold != wiphy->frag_threshold)) {
wl->conf->frag_threshold = wiphy->frag_threshold;
err = wl_set_frag(ndev, wl->conf->frag_threshold);
if (!err)
goto done;
}
if (changed & WIPHY_PARAM_RETRY_LONG
&& (wl->conf->retry_long != wiphy->retry_long)) {
wl->conf->retry_long = wiphy->retry_long;
err = wl_set_retry(ndev, wl->conf->retry_long, true);
if (!err)
goto done;
}
if (changed & WIPHY_PARAM_RETRY_SHORT
&& (wl->conf->retry_short != wiphy->retry_short)) {
wl->conf->retry_short = wiphy->retry_short;
err = wl_set_retry(ndev, wl->conf->retry_short, false);
if (!err)
goto done;
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_join_ibss(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_ibss_params *params)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct wl_join_params join_params;
size_t join_params_size = 0;
s32 err = 0;
s32 wsec = 0;
s32 bcnprd;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
if (params->ssid)
WL_CONN("SSID: %s\n", params->ssid);
else {
WL_CONN("SSID: NULL, Not supported\n");
return -EOPNOTSUPP;
}
if (params->bssid)
WL_CONN("BSSID: %02X %02X %02X %02X %02X %02X\n",
params->bssid[0], params->bssid[1], params->bssid[2],
params->bssid[3], params->bssid[4], params->bssid[5]);
else
WL_CONN("No BSSID specified\n");
if (params->channel)
WL_CONN("channel: %d\n", params->channel->center_freq);
else
WL_CONN("no channel specified\n");
if (params->channel_fixed)
WL_CONN("fixed channel required\n");
else
WL_CONN("no fixed channel required\n");
if (params->ie && params->ie_len)
WL_CONN("ie len: %d\n", params->ie_len);
else
WL_CONN("no ie specified\n");
if (params->beacon_interval)
WL_CONN("beacon interval: %d\n", params->beacon_interval);
else
WL_CONN("no beacon interval specified\n");
if (params->basic_rates)
WL_CONN("basic rates: %08X\n", params->basic_rates);
else
WL_CONN("no basic rates specified\n");
if (params->privacy)
WL_CONN("privacy required\n");
else
WL_CONN("no privacy required\n");
if (params->privacy)
wsec |= WEP_ENABLED;
err = wl_dev_intvar_set(dev, "wsec", wsec);
if (unlikely(err)) {
WL_ERR("wsec failed (%d)\n", err);
goto done;
}
if (params->beacon_interval)
bcnprd = cpu_to_le32(params->beacon_interval);
else
bcnprd = cpu_to_le32(100);
err = wl_dev_ioctl(dev, WLC_SET_BCNPRD, &bcnprd, sizeof(bcnprd));
if (unlikely(err)) {
WL_ERR("WLC_SET_BCNPRD failed (%d)\n", err);
goto done;
}
memset(&join_params, 0, sizeof(wl_join_params_t));
join_params.ssid.SSID_len =
(params->ssid_len > 32) ? 32 : params->ssid_len;
memcpy(join_params.ssid.SSID, params->ssid, join_params.ssid.SSID_len);
join_params.ssid.SSID_len = cpu_to_le32(join_params.ssid.SSID_len);
join_params_size = sizeof(join_params.ssid);
wl_update_prof(wl, NULL, &join_params.ssid, WL_PROF_SSID);
if (params->bssid) {
memcpy(join_params.params.bssid, params->bssid, ETH_ALEN);
join_params_size =
sizeof(join_params.ssid) + WL_ASSOC_PARAMS_FIXED_SIZE;
} else {
memcpy(join_params.params.bssid, ether_bcast, ETH_ALEN);
}
wl_update_prof(wl, NULL, &join_params.params.bssid, WL_PROF_BSSID);
if (params->channel) {
u32 target_channel;
wl->channel =
ieee80211_frequency_to_channel(
params->channel->center_freq);
if (params->channel_fixed) {
wl_ch_to_chanspec(wl->channel,
&join_params, &join_params_size);
}
target_channel = cpu_to_le32(wl->channel);
err = wl_dev_ioctl(dev, WLC_SET_CHANNEL,
&target_channel, sizeof(target_channel));
if (unlikely(err)) {
WL_ERR("WLC_SET_CHANNEL failed (%d)\n", err);
goto done;
}
} else
wl->channel = 0;
wl->ibss_starter = false;
err = wl_dev_ioctl(dev, WLC_SET_SSID, &join_params, join_params_size);
if (unlikely(err)) {
WL_ERR("WLC_SET_SSID failed (%d)\n", err);
goto done;
}
set_bit(WL_STATUS_CONNECTING, &wl->status);
done:
WL_TRACE("Exit\n");
return err;
}
static s32 wl_cfg80211_leave_ibss(struct wiphy *wiphy, struct net_device *dev)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
wl_link_down(wl);
WL_TRACE("Exit\n");
return err;
}
static s32
wl_set_wpa_version(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct wl_priv *wl = ndev_to_wl(dev);
struct wl_security *sec;
s32 val = 0;
s32 err = 0;
if (sme->crypto.wpa_versions & NL80211_WPA_VERSION_1)
val = WPA_AUTH_PSK | WPA_AUTH_UNSPECIFIED;
else if (sme->crypto.wpa_versions & NL80211_WPA_VERSION_2)
val = WPA2_AUTH_PSK | WPA2_AUTH_UNSPECIFIED;
else
val = WPA_AUTH_DISABLED;
WL_CONN("setting wpa_auth to 0x%0x\n", val);
err = wl_dev_intvar_set(dev, "wpa_auth", val);
if (unlikely(err)) {
WL_ERR("set wpa_auth failed (%d)\n", err);
return err;
}
sec = wl_read_prof(wl, WL_PROF_SEC);
sec->wpa_versions = sme->crypto.wpa_versions;
return err;
}
static s32
wl_set_auth_type(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct wl_priv *wl = ndev_to_wl(dev);
struct wl_security *sec;
s32 val = 0;
s32 err = 0;
switch (sme->auth_type) {
case NL80211_AUTHTYPE_OPEN_SYSTEM:
val = 0;
WL_CONN("open system\n");
break;
case NL80211_AUTHTYPE_SHARED_KEY:
val = 1;
WL_CONN("shared key\n");
break;
case NL80211_AUTHTYPE_AUTOMATIC:
val = 2;
WL_CONN("automatic\n");
break;
case NL80211_AUTHTYPE_NETWORK_EAP:
WL_CONN("network eap\n");
default:
val = 2;
WL_ERR("invalid auth type (%d)\n", sme->auth_type);
break;
}
err = wl_dev_intvar_set(dev, "auth", val);
if (unlikely(err)) {
WL_ERR("set auth failed (%d)\n", err);
return err;
}
sec = wl_read_prof(wl, WL_PROF_SEC);
sec->auth_type = sme->auth_type;
return err;
}
static s32
wl_set_set_cipher(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct wl_priv *wl = ndev_to_wl(dev);
struct wl_security *sec;
s32 pval = 0;
s32 gval = 0;
s32 err = 0;
if (sme->crypto.n_ciphers_pairwise) {
switch (sme->crypto.ciphers_pairwise[0]) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
pval = WEP_ENABLED;
break;
case WLAN_CIPHER_SUITE_TKIP:
pval = TKIP_ENABLED;
break;
case WLAN_CIPHER_SUITE_CCMP:
pval = AES_ENABLED;
break;
case WLAN_CIPHER_SUITE_AES_CMAC:
pval = AES_ENABLED;
break;
default:
WL_ERR("invalid cipher pairwise (%d)\n",
sme->crypto.ciphers_pairwise[0]);
return -EINVAL;
}
}
if (sme->crypto.cipher_group) {
switch (sme->crypto.cipher_group) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
gval = WEP_ENABLED;
break;
case WLAN_CIPHER_SUITE_TKIP:
gval = TKIP_ENABLED;
break;
case WLAN_CIPHER_SUITE_CCMP:
gval = AES_ENABLED;
break;
case WLAN_CIPHER_SUITE_AES_CMAC:
gval = AES_ENABLED;
break;
default:
WL_ERR("invalid cipher group (%d)\n",
sme->crypto.cipher_group);
return -EINVAL;
}
}
WL_CONN("pval (%d) gval (%d)\n", pval, gval);
err = wl_dev_intvar_set(dev, "wsec", pval | gval);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
sec = wl_read_prof(wl, WL_PROF_SEC);
sec->cipher_pairwise = sme->crypto.ciphers_pairwise[0];
sec->cipher_group = sme->crypto.cipher_group;
return err;
}
static s32
wl_set_key_mgmt(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct wl_priv *wl = ndev_to_wl(dev);
struct wl_security *sec;
s32 val = 0;
s32 err = 0;
if (sme->crypto.n_akm_suites) {
err = wl_dev_intvar_get(dev, "wpa_auth", &val);
if (unlikely(err)) {
WL_ERR("could not get wpa_auth (%d)\n", err);
return err;
}
if (val & (WPA_AUTH_PSK | WPA_AUTH_UNSPECIFIED)) {
switch (sme->crypto.akm_suites[0]) {
case WLAN_AKM_SUITE_8021X:
val = WPA_AUTH_UNSPECIFIED;
break;
case WLAN_AKM_SUITE_PSK:
val = WPA_AUTH_PSK;
break;
default:
WL_ERR("invalid cipher group (%d)\n",
sme->crypto.cipher_group);
return -EINVAL;
}
} else if (val & (WPA2_AUTH_PSK | WPA2_AUTH_UNSPECIFIED)) {
switch (sme->crypto.akm_suites[0]) {
case WLAN_AKM_SUITE_8021X:
val = WPA2_AUTH_UNSPECIFIED;
break;
case WLAN_AKM_SUITE_PSK:
val = WPA2_AUTH_PSK;
break;
default:
WL_ERR("invalid cipher group (%d)\n",
sme->crypto.cipher_group);
return -EINVAL;
}
}
WL_CONN("setting wpa_auth to %d\n", val);
err = wl_dev_intvar_set(dev, "wpa_auth", val);
if (unlikely(err)) {
WL_ERR("could not set wpa_auth (%d)\n", err);
return err;
}
}
sec = wl_read_prof(wl, WL_PROF_SEC);
sec->wpa_auth = sme->crypto.akm_suites[0];
return err;
}
static s32
wl_set_set_sharedkey(struct net_device *dev,
struct cfg80211_connect_params *sme)
{
struct wl_priv *wl = ndev_to_wl(dev);
struct wl_security *sec;
struct wl_wsec_key key;
s32 val;
s32 err = 0;
WL_CONN("key len (%d)\n", sme->key_len);
if (sme->key_len) {
sec = wl_read_prof(wl, WL_PROF_SEC);
WL_CONN("wpa_versions 0x%x cipher_pairwise 0x%x\n",
sec->wpa_versions, sec->cipher_pairwise);
if (!
(sec->wpa_versions & (NL80211_WPA_VERSION_1 |
NL80211_WPA_VERSION_2))
&& (sec->cipher_pairwise & (WLAN_CIPHER_SUITE_WEP40 |
WLAN_CIPHER_SUITE_WEP104))) {
memset(&key, 0, sizeof(key));
key.len = (u32) sme->key_len;
key.index = (u32) sme->key_idx;
if (unlikely(key.len > sizeof(key.data))) {
WL_ERR("Too long key length (%u)\n", key.len);
return -EINVAL;
}
memcpy(key.data, sme->key, key.len);
key.flags = WL_PRIMARY_KEY;
switch (sec->cipher_pairwise) {
case WLAN_CIPHER_SUITE_WEP40:
key.algo = CRYPTO_ALGO_WEP1;
break;
case WLAN_CIPHER_SUITE_WEP104:
key.algo = CRYPTO_ALGO_WEP128;
break;
default:
WL_ERR("Invalid algorithm (%d)\n",
sme->crypto.ciphers_pairwise[0]);
return -EINVAL;
}
WL_CONN("key length (%d) key index (%d) algo (%d)\n",
key.len, key.index, key.algo);
WL_CONN("key \"%s\"\n", key.data);
swap_key_from_BE(&key);
err = wl_dev_ioctl(dev, WLC_SET_KEY, &key,
sizeof(key));
if (unlikely(err)) {
WL_ERR("WLC_SET_KEY error (%d)\n", err);
return err;
}
if (sec->auth_type == NL80211_AUTHTYPE_OPEN_SYSTEM) {
WL_CONN("set auth_type to shared key\n");
val = 1;
err = wl_dev_intvar_set(dev, "auth", val);
if (unlikely(err)) {
WL_ERR("set auth failed (%d)\n", err);
return err;
}
}
}
}
return err;
}
static s32
wl_cfg80211_connect(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_connect_params *sme)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct ieee80211_channel *chan = sme->channel;
struct wl_join_params join_params;
size_t join_params_size;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
if (unlikely(!sme->ssid)) {
WL_ERR("Invalid ssid\n");
return -EOPNOTSUPP;
}
if (chan) {
wl->channel =
ieee80211_frequency_to_channel(chan->center_freq);
WL_CONN("channel (%d), center_req (%d)\n",
wl->channel, chan->center_freq);
} else
wl->channel = 0;
WL_INFO("ie (%p), ie_len (%zd)\n", sme->ie, sme->ie_len);
err = wl_set_wpa_version(dev, sme);
if (unlikely(err))
return err;
err = wl_set_auth_type(dev, sme);
if (unlikely(err))
return err;
err = wl_set_set_cipher(dev, sme);
if (unlikely(err))
return err;
err = wl_set_key_mgmt(dev, sme);
if (unlikely(err))
return err;
err = wl_set_set_sharedkey(dev, sme);
if (unlikely(err))
return err;
wl_update_prof(wl, NULL, sme->bssid, WL_PROF_BSSID);
memset(&join_params, 0, sizeof(join_params));
join_params_size = sizeof(join_params.ssid);
join_params.ssid.SSID_len = min(sizeof(join_params.ssid.SSID), sme->ssid_len);
memcpy(&join_params.ssid.SSID, sme->ssid, join_params.ssid.SSID_len);
join_params.ssid.SSID_len = cpu_to_le32(join_params.ssid.SSID_len);
wl_update_prof(wl, NULL, &join_params.ssid, WL_PROF_SSID);
if (sme->bssid)
memcpy(join_params.params.bssid, sme->bssid, ETH_ALEN);
else
memcpy(join_params.params.bssid, ether_bcast, ETH_ALEN);
if (join_params.ssid.SSID_len < IEEE80211_MAX_SSID_LEN) {
WL_CONN("ssid \"%s\", len (%d)\n",
join_params.ssid.SSID, join_params.ssid.SSID_len);
}
wl_ch_to_chanspec(wl->channel, &join_params, &join_params_size);
err = wl_dev_ioctl(dev, WLC_SET_SSID, &join_params, join_params_size);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
set_bit(WL_STATUS_CONNECTING, &wl->status);
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_disconnect(struct wiphy *wiphy, struct net_device *dev,
u16 reason_code)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
scb_val_t scbval;
s32 err = 0;
WL_TRACE("Enter. Reason code = %d\n", reason_code);
CHECK_SYS_UP();
clear_bit(WL_STATUS_CONNECTED, &wl->status);
scbval.val = reason_code;
memcpy(&scbval.ea, wl_read_prof(wl, WL_PROF_BSSID), ETH_ALEN);
scbval.val = cpu_to_le32(scbval.val);
err = wl_dev_ioctl(dev, WLC_DISASSOC, &scbval,
sizeof(scb_val_t));
if (unlikely(err))
WL_ERR("error (%d)\n", err);
wl->link_up = false;
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_set_tx_power(struct wiphy *wiphy,
enum nl80211_tx_power_setting type, s32 dbm)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct net_device *ndev = wl_to_ndev(wl);
u16 txpwrmw;
s32 err = 0;
s32 disable = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
switch (type) {
case NL80211_TX_POWER_AUTOMATIC:
break;
case NL80211_TX_POWER_LIMITED:
if (dbm < 0) {
WL_ERR("TX_POWER_LIMITED - dbm is negative\n");
err = -EINVAL;
goto done;
}
break;
case NL80211_TX_POWER_FIXED:
if (dbm < 0) {
WL_ERR("TX_POWER_FIXED - dbm is negative\n");
err = -EINVAL;
goto done;
}
break;
}
disable = WL_RADIO_SW_DISABLE << 16;
disable = cpu_to_le32(disable);
err = wl_dev_ioctl(ndev, WLC_SET_RADIO, &disable, sizeof(disable));
if (unlikely(err))
WL_ERR("WLC_SET_RADIO error (%d)\n", err);
if (dbm > 0xffff)
txpwrmw = 0xffff;
else
txpwrmw = (u16) dbm;
err = wl_dev_intvar_set(ndev, "qtxpower",
(s32) (bcm_mw_to_qdbm(txpwrmw)));
if (unlikely(err))
WL_ERR("qtxpower error (%d)\n", err);
wl->conf->tx_power = dbm;
done:
WL_TRACE("Exit\n");
return err;
}
static s32 wl_cfg80211_get_tx_power(struct wiphy *wiphy, s32 *dbm)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct net_device *ndev = wl_to_ndev(wl);
s32 txpwrdbm;
u8 result;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
err = wl_dev_intvar_get(ndev, "qtxpower", &txpwrdbm);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
goto done;
}
result = (u8) (txpwrdbm & ~WL_TXPWR_OVERRIDE);
*dbm = (s32) bcm_qdbm_to_mw(result);
done:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_config_default_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool unicast, bool multicast)
{
u32 index;
s32 wsec;
s32 err = 0;
WL_TRACE("Enter\n");
WL_CONN("key index (%d)\n", key_idx);
CHECK_SYS_UP();
err = wl_dev_ioctl(dev, WLC_GET_WSEC, &wsec, sizeof(wsec));
if (unlikely(err)) {
WL_ERR("WLC_GET_WSEC error (%d)\n", err);
goto done;
}
wsec = le32_to_cpu(wsec);
if (wsec & WEP_ENABLED) {
index = (u32) key_idx;
index = cpu_to_le32(index);
err = wl_dev_ioctl(dev, WLC_SET_KEY_PRIMARY, &index,
sizeof(index));
if (unlikely(err))
WL_ERR("error (%d)\n", err);
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_add_keyext(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, const u8 *mac_addr, struct key_params *params)
{
struct wl_wsec_key key;
s32 err = 0;
memset(&key, 0, sizeof(key));
key.index = (u32) key_idx;
if (!is_multicast_ether_addr(mac_addr))
memcpy((char *)&key.ea, (void *)mac_addr, ETH_ALEN);
key.len = (u32) params->key_len;
if (key.len == 0) {
swap_key_from_BE(&key);
err = wl_dev_ioctl(dev, WLC_SET_KEY, &key, sizeof(key));
if (unlikely(err)) {
WL_ERR("key delete error (%d)\n", err);
return err;
}
} else {
if (key.len > sizeof(key.data)) {
WL_ERR("Invalid key length (%d)\n", key.len);
return -EINVAL;
}
WL_CONN("Setting the key index %d\n", key.index);
memcpy(key.data, params->key, key.len);
if (params->cipher == WLAN_CIPHER_SUITE_TKIP) {
u8 keybuf[8];
memcpy(keybuf, &key.data[24], sizeof(keybuf));
memcpy(&key.data[24], &key.data[16], sizeof(keybuf));
memcpy(&key.data[16], keybuf, sizeof(keybuf));
}
if (params->seq && params->seq_len == 6) {
u8 *ivptr;
ivptr = (u8 *) params->seq;
key.rxiv.hi = (ivptr[5] << 24) | (ivptr[4] << 16) |
(ivptr[3] << 8) | ivptr[2];
key.rxiv.lo = (ivptr[1] << 8) | ivptr[0];
key.iv_initialized = true;
}
switch (params->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
key.algo = CRYPTO_ALGO_WEP1;
WL_CONN("WLAN_CIPHER_SUITE_WEP40\n");
break;
case WLAN_CIPHER_SUITE_WEP104:
key.algo = CRYPTO_ALGO_WEP128;
WL_CONN("WLAN_CIPHER_SUITE_WEP104\n");
break;
case WLAN_CIPHER_SUITE_TKIP:
key.algo = CRYPTO_ALGO_TKIP;
WL_CONN("WLAN_CIPHER_SUITE_TKIP\n");
break;
case WLAN_CIPHER_SUITE_AES_CMAC:
key.algo = CRYPTO_ALGO_AES_CCM;
WL_CONN("WLAN_CIPHER_SUITE_AES_CMAC\n");
break;
case WLAN_CIPHER_SUITE_CCMP:
key.algo = CRYPTO_ALGO_AES_CCM;
WL_CONN("WLAN_CIPHER_SUITE_CCMP\n");
break;
default:
WL_ERR("Invalid cipher (0x%x)\n", params->cipher);
return -EINVAL;
}
swap_key_from_BE(&key);
dhd_wait_pend8021x(dev);
err = wl_dev_ioctl(dev, WLC_SET_KEY, &key, sizeof(key));
if (unlikely(err)) {
WL_ERR("WLC_SET_KEY error (%d)\n", err);
return err;
}
}
return err;
}
static s32
wl_cfg80211_add_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool pairwise, const u8 *mac_addr,
struct key_params *params)
{
struct wl_wsec_key key;
s32 val;
s32 wsec;
s32 err = 0;
u8 keybuf[8];
WL_TRACE("Enter\n");
WL_CONN("key index (%d)\n", key_idx);
CHECK_SYS_UP();
if (mac_addr) {
WL_TRACE("Exit");
return wl_add_keyext(wiphy, dev, key_idx, mac_addr, params);
}
memset(&key, 0, sizeof(key));
key.len = (u32) params->key_len;
key.index = (u32) key_idx;
if (unlikely(key.len > sizeof(key.data))) {
WL_ERR("Too long key length (%u)\n", key.len);
err = -EINVAL;
goto done;
}
memcpy(key.data, params->key, key.len);
key.flags = WL_PRIMARY_KEY;
switch (params->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
key.algo = CRYPTO_ALGO_WEP1;
WL_CONN("WLAN_CIPHER_SUITE_WEP40\n");
break;
case WLAN_CIPHER_SUITE_WEP104:
key.algo = CRYPTO_ALGO_WEP128;
WL_CONN("WLAN_CIPHER_SUITE_WEP104\n");
break;
case WLAN_CIPHER_SUITE_TKIP:
memcpy(keybuf, &key.data[24], sizeof(keybuf));
memcpy(&key.data[24], &key.data[16], sizeof(keybuf));
memcpy(&key.data[16], keybuf, sizeof(keybuf));
key.algo = CRYPTO_ALGO_TKIP;
WL_CONN("WLAN_CIPHER_SUITE_TKIP\n");
break;
case WLAN_CIPHER_SUITE_AES_CMAC:
key.algo = CRYPTO_ALGO_AES_CCM;
WL_CONN("WLAN_CIPHER_SUITE_AES_CMAC\n");
break;
case WLAN_CIPHER_SUITE_CCMP:
key.algo = CRYPTO_ALGO_AES_CCM;
WL_CONN("WLAN_CIPHER_SUITE_CCMP\n");
break;
default:
WL_ERR("Invalid cipher (0x%x)\n", params->cipher);
err = -EINVAL;
goto done;
}
swap_key_from_BE(&key);
err = wl_dev_ioctl(dev, WLC_SET_KEY, &key, sizeof(key));
if (unlikely(err)) {
WL_ERR("WLC_SET_KEY error (%d)\n", err);
goto done;
}
val = WEP_ENABLED;
err = wl_dev_intvar_get(dev, "wsec", &wsec);
if (unlikely(err)) {
WL_ERR("get wsec error (%d)\n", err);
goto done;
}
wsec &= ~(WEP_ENABLED);
wsec |= val;
err = wl_dev_intvar_set(dev, "wsec", wsec);
if (unlikely(err)) {
WL_ERR("set wsec error (%d)\n", err);
goto done;
}
val = 1;
val = cpu_to_le32(val);
err = wl_dev_ioctl(dev, WLC_SET_AUTH, &val, sizeof(val));
if (unlikely(err))
WL_ERR("WLC_SET_AUTH error (%d)\n", err);
done:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_del_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool pairwise, const u8 *mac_addr)
{
struct wl_wsec_key key;
s32 err = 0;
s32 val;
s32 wsec;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
memset(&key, 0, sizeof(key));
key.index = (u32) key_idx;
key.flags = WL_PRIMARY_KEY;
key.algo = CRYPTO_ALGO_OFF;
WL_CONN("key index (%d)\n", key_idx);
swap_key_from_BE(&key);
err = wl_dev_ioctl(dev, WLC_SET_KEY, &key, sizeof(key));
if (unlikely(err)) {
if (err == -EINVAL) {
if (key.index >= DOT11_MAX_DEFAULT_KEYS)
WL_ERR("invalid key index (%d)\n", key_idx);
} else
WL_ERR("WLC_SET_KEY error (%d)\n", err);
err = -EAGAIN;
goto done;
}
val = 0;
err = wl_dev_intvar_get(dev, "wsec", &wsec);
if (unlikely(err)) {
WL_ERR("get wsec error (%d)\n", err);
err = -EAGAIN;
goto done;
}
wsec &= ~(WEP_ENABLED);
wsec |= val;
err = wl_dev_intvar_set(dev, "wsec", wsec);
if (unlikely(err)) {
WL_ERR("set wsec error (%d)\n", err);
err = -EAGAIN;
goto done;
}
val = 0;
val = cpu_to_le32(val);
err = wl_dev_ioctl(dev, WLC_SET_AUTH, &val, sizeof(val));
if (unlikely(err)) {
WL_ERR("WLC_SET_AUTH error (%d)\n", err);
err = -EAGAIN;
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_get_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool pairwise, const u8 *mac_addr, void *cookie,
void (*callback) (void *cookie, struct key_params * params))
{
struct key_params params;
struct wl_wsec_key key;
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct wl_security *sec;
s32 wsec;
s32 err = 0;
WL_TRACE("Enter\n");
WL_CONN("key index (%d)\n", key_idx);
CHECK_SYS_UP();
memset(&key, 0, sizeof(key));
key.index = key_idx;
swap_key_to_BE(&key);
memset(&params, 0, sizeof(params));
params.key_len = (u8) min_t(u8, WLAN_MAX_KEY_LEN, key.len);
memcpy(params.key, key.data, params.key_len);
err = wl_dev_ioctl(dev, WLC_GET_WSEC, &wsec, sizeof(wsec));
if (unlikely(err)) {
WL_ERR("WLC_GET_WSEC error (%d)\n", err);
err = -EAGAIN;
goto done;
}
wsec = le32_to_cpu(wsec);
switch (wsec) {
case WEP_ENABLED:
sec = wl_read_prof(wl, WL_PROF_SEC);
if (sec->cipher_pairwise & WLAN_CIPHER_SUITE_WEP40) {
params.cipher = WLAN_CIPHER_SUITE_WEP40;
WL_CONN("WLAN_CIPHER_SUITE_WEP40\n");
} else if (sec->cipher_pairwise & WLAN_CIPHER_SUITE_WEP104) {
params.cipher = WLAN_CIPHER_SUITE_WEP104;
WL_CONN("WLAN_CIPHER_SUITE_WEP104\n");
}
break;
case TKIP_ENABLED:
params.cipher = WLAN_CIPHER_SUITE_TKIP;
WL_CONN("WLAN_CIPHER_SUITE_TKIP\n");
break;
case AES_ENABLED:
params.cipher = WLAN_CIPHER_SUITE_AES_CMAC;
WL_CONN("WLAN_CIPHER_SUITE_AES_CMAC\n");
break;
default:
WL_ERR("Invalid algo (0x%x)\n", wsec);
err = -EINVAL;
goto done;
}
callback(cookie, &params);
done:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_config_default_mgmt_key(struct wiphy *wiphy,
struct net_device *dev, u8 key_idx)
{
WL_INFO("Not supported\n");
CHECK_SYS_UP();
return -EOPNOTSUPP;
}
static s32
wl_cfg80211_get_station(struct wiphy *wiphy, struct net_device *dev,
u8 *mac, struct station_info *sinfo)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
scb_val_t scb_val;
int rssi;
s32 rate;
s32 err = 0;
u8 *bssid = wl_read_prof(wl, WL_PROF_BSSID);
WL_TRACE("Enter\n");
CHECK_SYS_UP();
if (unlikely
(memcmp(mac, bssid, ETH_ALEN))) {
WL_ERR("Wrong Mac address cfg_mac-%X:%X:%X:%X:%X:%X"
"wl_bssid-%X:%X:%X:%X:%X:%X\n",
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5],
bssid[0], bssid[1], bssid[2], bssid[3],
bssid[4], bssid[5]);
err = -ENOENT;
goto done;
}
err = wl_dev_ioctl(dev, WLC_GET_RATE, &rate, sizeof(rate));
if (err) {
WL_ERR("Could not get rate (%d)\n", err);
} else {
rate = le32_to_cpu(rate);
sinfo->filled |= STATION_INFO_TX_BITRATE;
sinfo->txrate.legacy = rate * 5;
WL_CONN("Rate %d Mbps\n", rate / 2);
}
if (test_bit(WL_STATUS_CONNECTED, &wl->status)) {
scb_val.val = 0;
err = wl_dev_ioctl(dev, WLC_GET_RSSI, &scb_val,
sizeof(scb_val_t));
if (unlikely(err)) {
WL_ERR("Could not get rssi (%d)\n", err);
}
rssi = le32_to_cpu(scb_val.val);
sinfo->filled |= STATION_INFO_SIGNAL;
sinfo->signal = rssi;
WL_CONN("RSSI %d dBm\n", rssi);
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_set_power_mgmt(struct wiphy *wiphy, struct net_device *dev,
bool enabled, s32 timeout)
{
s32 pm;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
pm = enabled ? PM_FAST : PM_OFF;
pm = cpu_to_le32(pm);
WL_INFO("power save %s\n", (pm ? "enabled" : "disabled"));
err = wl_dev_ioctl(dev, WLC_SET_PM, &pm, sizeof(pm));
if (unlikely(err)) {
if (err == -ENODEV)
WL_ERR("net_device is not ready yet\n");
else
WL_ERR("error (%d)\n", err);
}
WL_TRACE("Exit\n");
return err;
}
static __used u32 wl_find_msb(u16 bit16)
{
u32 ret = 0;
if (bit16 & 0xff00) {
ret += 8;
bit16 >>= 8;
}
if (bit16 & 0xf0) {
ret += 4;
bit16 >>= 4;
}
if (bit16 & 0xc) {
ret += 2;
bit16 >>= 2;
}
if (bit16 & 2)
ret += bit16 & 2;
else if (bit16)
ret += bit16;
return ret;
}
static s32
wl_cfg80211_set_bitrate_mask(struct wiphy *wiphy, struct net_device *dev,
const u8 *addr,
const struct cfg80211_bitrate_mask *mask)
{
struct wl_rateset rateset;
s32 rate;
s32 val;
s32 err_bg;
s32 err_a;
u32 legacy;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
err = wl_dev_ioctl(dev, WLC_GET_CURR_RATESET, &rateset,
sizeof(rateset));
if (unlikely(err)) {
WL_ERR("could not get current rateset (%d)\n", err);
goto done;
}
rateset.count = le32_to_cpu(rateset.count);
legacy = wl_find_msb(mask->control[IEEE80211_BAND_2GHZ].legacy);
if (!legacy)
legacy = wl_find_msb(mask->control[IEEE80211_BAND_5GHZ].legacy);
val = wl_g_rates[legacy - 1].bitrate * 100000;
if (val < rateset.count)
rate = rateset.rates[val] & 0x7f;
else
rate = val / 500000;
WL_CONN("rate %d mbps\n", rate / 2);
err_bg = wl_dev_intvar_set(dev, "bg_rate", rate);
err_a = wl_dev_intvar_set(dev, "a_rate", rate);
if (unlikely(err_bg && err_a)) {
WL_ERR("could not set fixed rate (%d) (%d)\n", err_bg, err_a);
err = err_bg | err_a;
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32 wl_cfg80211_resume(struct wiphy *wiphy)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct net_device *ndev = wl_to_ndev(wl);
WL_TRACE("Enter\n");
#if defined(CONFIG_PM_SLEEP)
atomic_set(&dhd_mmc_suspend, false);
#endif
if (test_bit(WL_STATUS_READY, &wl->status)) {
wl_os_wd_timer(ndev, dhd_watchdog_ms);
wl_invoke_iscan(wiphy_to_wl(wiphy));
}
WL_TRACE("Exit\n");
return 0;
}
static s32 wl_cfg80211_suspend(struct wiphy *wiphy)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct net_device *ndev = wl_to_ndev(wl);
WL_TRACE("Enter\n");
if (test_bit(WL_STATUS_CONNECTED, &wl->status) &&
test_bit(WL_STATUS_READY, &wl->status)) {
WL_INFO("Disassociating from AP"
" while entering suspend state\n");
wl_link_down(wl);
rtnl_unlock();
wl_delay(500);
rtnl_lock();
}
set_bit(WL_STATUS_SCAN_ABORTING, &wl->status);
if (test_bit(WL_STATUS_READY, &wl->status))
wl_term_iscan(wl);
if (wl->scan_request) {
WL_INFO("Terminating scan in progress\n");
cfg80211_scan_done(wl->scan_request, true);
wl->scan_request = NULL;
}
clear_bit(WL_STATUS_SCANNING, &wl->status);
clear_bit(WL_STATUS_SCAN_ABORTING, &wl->status);
clear_bit(WL_STATUS_CONNECTING, &wl->status);
clear_bit(WL_STATUS_CONNECTED, &wl->status);
sdioh_sdio_set_host_pm_flags(MMC_PM_KEEP_POWER);
if (test_bit(WL_STATUS_READY, &wl->status)) {
WL_INFO("Terminate watchdog timer and enable MPC\n");
wl_set_mpc(ndev, 1);
wl_os_wd_timer(ndev, 0);
}
#if defined(CONFIG_PM_SLEEP)
atomic_set(&dhd_mmc_suspend, true);
#endif
WL_TRACE("Exit\n");
return 0;
}
static __used s32
wl_update_pmklist(struct net_device *dev, struct wl_pmk_list *pmk_list,
s32 err)
{
int i, j;
WL_CONN("No of elements %d\n", pmk_list->pmkids.npmkid);
for (i = 0; i < pmk_list->pmkids.npmkid; i++) {
WL_CONN("PMKID[%d]: %pM =\n", i,
&pmk_list->pmkids.pmkid[i].BSSID);
for (j = 0; j < WLAN_PMKID_LEN; j++)
WL_CONN("%02x\n", pmk_list->pmkids.pmkid[i].PMKID[j]);
}
if (likely(!err))
wl_dev_bufvar_set(dev, "pmkid_info", (char *)pmk_list,
sizeof(*pmk_list));
return err;
}
static s32
wl_cfg80211_set_pmksa(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_pmksa *pmksa)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
s32 err = 0;
int i;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
for (i = 0; i < wl->pmk_list->pmkids.npmkid; i++)
if (!memcmp(pmksa->bssid, &wl->pmk_list->pmkids.pmkid[i].BSSID,
ETH_ALEN))
break;
if (i < WL_NUM_PMKIDS_MAX) {
memcpy(&wl->pmk_list->pmkids.pmkid[i].BSSID, pmksa->bssid,
ETH_ALEN);
memcpy(&wl->pmk_list->pmkids.pmkid[i].PMKID, pmksa->pmkid,
WLAN_PMKID_LEN);
if (i == wl->pmk_list->pmkids.npmkid)
wl->pmk_list->pmkids.npmkid++;
} else
err = -EINVAL;
WL_CONN("set_pmksa,IW_PMKSA_ADD - PMKID: %pM =\n",
&wl->pmk_list->pmkids.pmkid[wl->pmk_list->pmkids.npmkid].BSSID);
for (i = 0; i < WLAN_PMKID_LEN; i++)
WL_CONN("%02x\n",
wl->pmk_list->pmkids.pmkid[wl->pmk_list->pmkids.npmkid].
PMKID[i]);
err = wl_update_pmklist(dev, wl->pmk_list, err);
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_del_pmksa(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_pmksa *pmksa)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
struct _pmkid_list pmkid;
s32 err = 0;
int i;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
memcpy(&pmkid.pmkid[0].BSSID, pmksa->bssid, ETH_ALEN);
memcpy(&pmkid.pmkid[0].PMKID, pmksa->pmkid, WLAN_PMKID_LEN);
WL_CONN("del_pmksa,IW_PMKSA_REMOVE - PMKID: %pM =\n",
&pmkid.pmkid[0].BSSID);
for (i = 0; i < WLAN_PMKID_LEN; i++)
WL_CONN("%02x\n", pmkid.pmkid[0].PMKID[i]);
for (i = 0; i < wl->pmk_list->pmkids.npmkid; i++)
if (!memcmp
(pmksa->bssid, &wl->pmk_list->pmkids.pmkid[i].BSSID,
ETH_ALEN))
break;
if ((wl->pmk_list->pmkids.npmkid > 0)
&& (i < wl->pmk_list->pmkids.npmkid)) {
memset(&wl->pmk_list->pmkids.pmkid[i], 0, sizeof(pmkid_t));
for (; i < (wl->pmk_list->pmkids.npmkid - 1); i++) {
memcpy(&wl->pmk_list->pmkids.pmkid[i].BSSID,
&wl->pmk_list->pmkids.pmkid[i + 1].BSSID,
ETH_ALEN);
memcpy(&wl->pmk_list->pmkids.pmkid[i].PMKID,
&wl->pmk_list->pmkids.pmkid[i + 1].PMKID,
WLAN_PMKID_LEN);
}
wl->pmk_list->pmkids.npmkid--;
} else
err = -EINVAL;
err = wl_update_pmklist(dev, wl->pmk_list, err);
WL_TRACE("Exit\n");
return err;
}
static s32
wl_cfg80211_flush_pmksa(struct wiphy *wiphy, struct net_device *dev)
{
struct wl_priv *wl = wiphy_to_wl(wiphy);
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
memset(wl->pmk_list, 0, sizeof(*wl->pmk_list));
err = wl_update_pmklist(dev, wl->pmk_list, err);
WL_TRACE("Exit\n");
return err;
}
static s32 wl_mode_to_nl80211_iftype(s32 mode)
{
s32 err = 0;
switch (mode) {
case WL_MODE_BSS:
return NL80211_IFTYPE_STATION;
case WL_MODE_IBSS:
return NL80211_IFTYPE_ADHOC;
default:
return NL80211_IFTYPE_UNSPECIFIED;
}
return err;
}
static struct wireless_dev *wl_alloc_wdev(s32 sizeof_iface,
struct device *dev)
{
struct wireless_dev *wdev;
s32 err = 0;
wdev = kzalloc(sizeof(*wdev), GFP_KERNEL);
if (unlikely(!wdev)) {
WL_ERR("Could not allocate wireless device\n");
return ERR_PTR(-ENOMEM);
}
wdev->wiphy =
wiphy_new(&wl_cfg80211_ops, sizeof(struct wl_priv) + sizeof_iface);
if (unlikely(!wdev->wiphy)) {
WL_ERR("Couldn not allocate wiphy device\n");
err = -ENOMEM;
goto wiphy_new_out;
}
set_wiphy_dev(wdev->wiphy, dev);
wdev->wiphy->max_scan_ssids = WL_NUM_SCAN_MAX;
wdev->wiphy->max_num_pmkids = WL_NUM_PMKIDS_MAX;
wdev->wiphy->interface_modes =
BIT(NL80211_IFTYPE_STATION) | BIT(NL80211_IFTYPE_ADHOC);
wdev->wiphy->bands[IEEE80211_BAND_2GHZ] = &__wl_band_2ghz;
wdev->wiphy->bands[IEEE80211_BAND_5GHZ] = &__wl_band_5ghz_a;
wdev->wiphy->signal_type = CFG80211_SIGNAL_TYPE_MBM;
wdev->wiphy->cipher_suites = __wl_cipher_suites;
wdev->wiphy->n_cipher_suites = ARRAY_SIZE(__wl_cipher_suites);
#ifndef WL_POWERSAVE_DISABLED
wdev->wiphy->flags |= WIPHY_FLAG_PS_ON_BY_DEFAULT;
#else
wdev->wiphy->flags &= ~WIPHY_FLAG_PS_ON_BY_DEFAULT;
#endif
err = wiphy_register(wdev->wiphy);
if (unlikely(err < 0)) {
WL_ERR("Couldn not register wiphy device (%d)\n", err);
goto wiphy_register_out;
}
return wdev;
wiphy_register_out:
wiphy_free(wdev->wiphy);
wiphy_new_out:
kfree(wdev);
return ERR_PTR(err);
}
static void wl_free_wdev(struct wl_priv *wl)
{
struct wireless_dev *wdev = wl_to_wdev(wl);
if (unlikely(!wdev)) {
WL_ERR("wdev is invalid\n");
return;
}
wiphy_unregister(wdev->wiphy);
wiphy_free(wdev->wiphy);
kfree(wdev);
wl_to_wdev(wl) = NULL;
}
static s32 wl_inform_bss(struct wl_priv *wl)
{
struct wl_scan_results *bss_list;
struct wl_bss_info *bi = NULL;
s32 err = 0;
int i;
bss_list = wl->bss_list;
if (unlikely(bss_list->version != WL_BSS_INFO_VERSION)) {
WL_ERR("Version %d != WL_BSS_INFO_VERSION\n",
bss_list->version);
return -EOPNOTSUPP;
}
WL_SCAN("scanned AP count (%d)\n", bss_list->count);
bi = next_bss(bss_list, bi);
for_each_bss(bss_list, bi, i) {
err = wl_inform_single_bss(wl, bi);
if (unlikely(err))
break;
}
return err;
}
static s32 wl_inform_single_bss(struct wl_priv *wl, struct wl_bss_info *bi)
{
struct wiphy *wiphy = wl_to_wiphy(wl);
struct ieee80211_channel *notify_channel;
struct cfg80211_bss *bss;
struct ieee80211_supported_band *band;
s32 err = 0;
u16 channel;
u32 freq;
u64 notify_timestamp;
u16 notify_capability;
u16 notify_interval;
u8 *notify_ie;
size_t notify_ielen;
s32 notify_signal;
if (unlikely(le32_to_cpu(bi->length) > WL_BSS_INFO_MAX)) {
WL_ERR("Bss info is larger than buffer. Discarding\n");
return 0;
}
channel = bi->ctl_ch ? bi->ctl_ch :
CHSPEC_CHANNEL(le16_to_cpu(bi->chanspec));
if (channel <= CH_MAX_2G_CHANNEL)
band = wiphy->bands[IEEE80211_BAND_2GHZ];
else
band = wiphy->bands[IEEE80211_BAND_5GHZ];
freq = ieee80211_channel_to_frequency(channel, band->band);
notify_channel = ieee80211_get_channel(wiphy, freq);
notify_timestamp = jiffies_to_msecs(jiffies)*1000;
notify_capability = le16_to_cpu(bi->capability);
notify_interval = le16_to_cpu(bi->beacon_period);
notify_ie = (u8 *)bi + le16_to_cpu(bi->ie_offset);
notify_ielen = le16_to_cpu(bi->ie_length);
notify_signal = (s16)le16_to_cpu(bi->RSSI) * 100;
WL_CONN("bssid: %2.2X:%2.2X:%2.2X:%2.2X:%2.2X:%2.2X\n",
bi->BSSID[0], bi->BSSID[1], bi->BSSID[2],
bi->BSSID[3], bi->BSSID[4], bi->BSSID[5]);
WL_CONN("Channel: %d(%d)\n", channel, freq);
WL_CONN("Capability: %X\n", notify_capability);
WL_CONN("Beacon interval: %d\n", notify_interval);
WL_CONN("Signal: %d\n", notify_signal);
WL_CONN("notify_timestamp: %#018llx\n", notify_timestamp);
bss = cfg80211_inform_bss(wiphy, notify_channel, (const u8 *)bi->BSSID,
notify_timestamp, notify_capability, notify_interval, notify_ie,
notify_ielen, notify_signal, GFP_KERNEL);
if (unlikely(!bss)) {
WL_ERR("cfg80211_inform_bss_frame error\n");
return -EINVAL;
}
return err;
}
static s32
wl_inform_ibss(struct wl_priv *wl, struct net_device *dev, const u8 *bssid)
{
struct wiphy *wiphy = wl_to_wiphy(wl);
struct ieee80211_channel *notify_channel;
struct wl_bss_info *bi = NULL;
struct ieee80211_supported_band *band;
u8 *buf = NULL;
s32 err = 0;
u16 channel;
u32 freq;
u64 notify_timestamp;
u16 notify_capability;
u16 notify_interval;
u8 *notify_ie;
size_t notify_ielen;
s32 notify_signal;
WL_TRACE("Enter\n");
buf = kzalloc(WL_BSS_INFO_MAX, GFP_KERNEL);
if (buf == NULL) {
WL_ERR("kzalloc() failed\n");
err = -ENOMEM;
goto CleanUp;
}
*(u32 *)buf = cpu_to_le32(WL_BSS_INFO_MAX);
err = wl_dev_ioctl(dev, WLC_GET_BSS_INFO, buf, WL_BSS_INFO_MAX);
if (unlikely(err)) {
WL_ERR("WLC_GET_BSS_INFO failed: %d\n", err);
goto CleanUp;
}
bi = (wl_bss_info_t *)(buf + 4);
channel = bi->ctl_ch ? bi->ctl_ch :
CHSPEC_CHANNEL(le16_to_cpu(bi->chanspec));
if (channel <= CH_MAX_2G_CHANNEL)
band = wiphy->bands[IEEE80211_BAND_2GHZ];
else
band = wiphy->bands[IEEE80211_BAND_5GHZ];
freq = ieee80211_channel_to_frequency(channel, band->band);
notify_channel = ieee80211_get_channel(wiphy, freq);
notify_timestamp = jiffies_to_msecs(jiffies)*1000;
notify_capability = le16_to_cpu(bi->capability);
notify_interval = le16_to_cpu(bi->beacon_period);
notify_ie = (u8 *)bi + le16_to_cpu(bi->ie_offset);
notify_ielen = le16_to_cpu(bi->ie_length);
notify_signal = (s16)le16_to_cpu(bi->RSSI) * 100;
WL_CONN("channel: %d(%d)\n", channel, freq);
WL_CONN("capability: %X\n", notify_capability);
WL_CONN("beacon interval: %d\n", notify_interval);
WL_CONN("signal: %d\n", notify_signal);
WL_CONN("notify_timestamp: %#018llx\n", notify_timestamp);
cfg80211_inform_bss(wiphy, notify_channel, bssid,
notify_timestamp, notify_capability, notify_interval,
notify_ie, notify_ielen, notify_signal, GFP_KERNEL);
CleanUp:
kfree(buf);
WL_TRACE("Exit\n");
return err;
}
static bool wl_is_linkup(struct wl_priv *wl, const wl_event_msg_t *e)
{
u32 event = be32_to_cpu(e->event_type);
u32 status = be32_to_cpu(e->status);
if (event == WLC_E_SET_SSID && status == WLC_E_STATUS_SUCCESS) {
WL_CONN("Processing set ssid\n");
wl->link_up = true;
return true;
}
return false;
}
static bool wl_is_linkdown(struct wl_priv *wl, const wl_event_msg_t *e)
{
u32 event = be32_to_cpu(e->event_type);
u16 flags = be16_to_cpu(e->flags);
if (event == WLC_E_LINK && (!(flags & WLC_EVENT_MSG_LINK))) {
WL_CONN("Processing link down\n");
return true;
}
return false;
}
static bool wl_is_nonetwork(struct wl_priv *wl, const wl_event_msg_t *e)
{
u32 event = be32_to_cpu(e->event_type);
u32 status = be32_to_cpu(e->status);
u16 flags = be16_to_cpu(e->flags);
if (event == WLC_E_LINK && status == WLC_E_STATUS_NO_NETWORKS) {
WL_CONN("Processing Link %s & no network found\n",
flags & WLC_EVENT_MSG_LINK ? "up" : "down");
return true;
}
if (event == WLC_E_SET_SSID && status != WLC_E_STATUS_SUCCESS) {
WL_CONN("Processing connecting & no network found\n");
return true;
}
return false;
}
static s32
wl_notify_connect_status(struct wl_priv *wl, struct net_device *ndev,
const wl_event_msg_t *e, void *data)
{
s32 err = 0;
if (wl_is_linkup(wl, e)) {
WL_CONN("Linkup\n");
if (wl_is_ibssmode(wl)) {
wl_update_prof(wl, NULL, (void *)e->addr,
WL_PROF_BSSID);
wl_inform_ibss(wl, ndev, e->addr);
cfg80211_ibss_joined(ndev, e->addr, GFP_KERNEL);
clear_bit(WL_STATUS_CONNECTING, &wl->status);
set_bit(WL_STATUS_CONNECTED, &wl->status);
} else
wl_bss_connect_done(wl, ndev, e, data, true);
} else if (wl_is_linkdown(wl, e)) {
WL_CONN("Linkdown\n");
if (wl_is_ibssmode(wl)) {
if (test_and_clear_bit(WL_STATUS_CONNECTED,
&wl->status))
wl_link_down(wl);
} else {
if (test_and_clear_bit(WL_STATUS_CONNECTED,
&wl->status)) {
cfg80211_disconnected(ndev, 0, NULL, 0,
GFP_KERNEL);
wl_link_down(wl);
}
}
wl_init_prof(wl->profile);
} else if (wl_is_nonetwork(wl, e)) {
if (wl_is_ibssmode(wl))
clear_bit(WL_STATUS_CONNECTING, &wl->status);
else
wl_bss_connect_done(wl, ndev, e, data, false);
}
return err;
}
static s32
wl_notify_roaming_status(struct wl_priv *wl, struct net_device *ndev,
const wl_event_msg_t *e, void *data)
{
s32 err = 0;
u32 event = be32_to_cpu(e->event_type);
u32 status = be32_to_cpu(e->status);
if (event == WLC_E_ROAM && status == WLC_E_STATUS_SUCCESS) {
if (test_bit(WL_STATUS_CONNECTED, &wl->status))
wl_bss_roaming_done(wl, ndev, e, data);
else
wl_bss_connect_done(wl, ndev, e, data, true);
}
return err;
}
static __used s32
wl_dev_bufvar_set(struct net_device *dev, s8 *name, s8 *buf, s32 len)
{
struct wl_priv *wl = ndev_to_wl(dev);
u32 buflen;
buflen = bcm_mkiovar(name, buf, len, wl->ioctl_buf, WL_IOCTL_LEN_MAX);
BUG_ON(!buflen);
return wl_dev_ioctl(dev, WLC_SET_VAR, wl->ioctl_buf, buflen);
}
static s32
wl_dev_bufvar_get(struct net_device *dev, s8 *name, s8 *buf,
s32 buf_len)
{
struct wl_priv *wl = ndev_to_wl(dev);
u32 len;
s32 err = 0;
len = bcm_mkiovar(name, NULL, 0, wl->ioctl_buf, WL_IOCTL_LEN_MAX);
BUG_ON(!len);
err = wl_dev_ioctl(dev, WLC_GET_VAR, (void *)wl->ioctl_buf,
WL_IOCTL_LEN_MAX);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
memcpy(buf, wl->ioctl_buf, buf_len);
return err;
}
static s32 wl_get_assoc_ies(struct wl_priv *wl)
{
struct net_device *ndev = wl_to_ndev(wl);
struct wl_assoc_ielen *assoc_info;
struct wl_connect_info *conn_info = wl_to_conn(wl);
u32 req_len;
u32 resp_len;
s32 err = 0;
wl_clear_assoc_ies(wl);
err = wl_dev_bufvar_get(ndev, "assoc_info", wl->extra_buf,
WL_ASSOC_INFO_MAX);
if (unlikely(err)) {
WL_ERR("could not get assoc info (%d)\n", err);
return err;
}
assoc_info = (struct wl_assoc_ielen *)wl->extra_buf;
req_len = assoc_info->req_len;
resp_len = assoc_info->resp_len;
if (req_len) {
err = wl_dev_bufvar_get(ndev, "assoc_req_ies", wl->extra_buf,
WL_ASSOC_INFO_MAX);
if (unlikely(err)) {
WL_ERR("could not get assoc req (%d)\n", err);
return err;
}
conn_info->req_ie_len = req_len;
conn_info->req_ie =
kmemdup(wl->extra_buf, conn_info->req_ie_len, GFP_KERNEL);
} else {
conn_info->req_ie_len = 0;
conn_info->req_ie = NULL;
}
if (resp_len) {
err = wl_dev_bufvar_get(ndev, "assoc_resp_ies", wl->extra_buf,
WL_ASSOC_INFO_MAX);
if (unlikely(err)) {
WL_ERR("could not get assoc resp (%d)\n", err);
return err;
}
conn_info->resp_ie_len = resp_len;
conn_info->resp_ie =
kmemdup(wl->extra_buf, conn_info->resp_ie_len, GFP_KERNEL);
} else {
conn_info->resp_ie_len = 0;
conn_info->resp_ie = NULL;
}
WL_CONN("req len (%d) resp len (%d)\n",
conn_info->req_ie_len, conn_info->resp_ie_len);
return err;
}
static void wl_clear_assoc_ies(struct wl_priv *wl)
{
struct wl_connect_info *conn_info = wl_to_conn(wl);
kfree(conn_info->req_ie);
conn_info->req_ie = NULL;
conn_info->req_ie_len = 0;
kfree(conn_info->resp_ie);
conn_info->resp_ie = NULL;
conn_info->resp_ie_len = 0;
}
static void wl_ch_to_chanspec(int ch, struct wl_join_params *join_params,
size_t *join_params_size)
{
chanspec_t chanspec = 0;
if (ch != 0) {
join_params->params.chanspec_num = 1;
join_params->params.chanspec_list[0] = ch;
if (join_params->params.chanspec_list[0] <= CH_MAX_2G_CHANNEL)
chanspec |= WL_CHANSPEC_BAND_2G;
else
chanspec |= WL_CHANSPEC_BAND_5G;
chanspec |= WL_CHANSPEC_BW_20;
chanspec |= WL_CHANSPEC_CTL_SB_NONE;
*join_params_size += WL_ASSOC_PARAMS_FIXED_SIZE +
join_params->params.chanspec_num * sizeof(chanspec_t);
join_params->params.chanspec_list[0] &= WL_CHANSPEC_CHAN_MASK;
join_params->params.chanspec_list[0] |= chanspec;
join_params->params.chanspec_list[0] =
cpu_to_le16(join_params->params.chanspec_list[0]);
join_params->params.chanspec_num =
cpu_to_le32(join_params->params.chanspec_num);
WL_CONN("join_params->params.chanspec_list[0]= %#X,"
"channel %d, chanspec %#X\n",
join_params->params.chanspec_list[0], ch, chanspec);
}
}
static s32 wl_update_bss_info(struct wl_priv *wl)
{
struct wl_bss_info *bi;
struct wlc_ssid *ssid;
struct bcm_tlv *tim;
u16 beacon_interval;
u8 dtim_period;
size_t ie_len;
u8 *ie;
s32 err = 0;
WL_TRACE("Enter\n");
if (wl_is_ibssmode(wl))
return err;
ssid = (struct wlc_ssid *)wl_read_prof(wl, WL_PROF_SSID);
*(u32 *)wl->extra_buf = cpu_to_le32(WL_EXTRA_BUF_MAX);
err = wl_dev_ioctl(wl_to_ndev(wl), WLC_GET_BSS_INFO,
wl->extra_buf, WL_EXTRA_BUF_MAX);
if (unlikely(err)) {
WL_ERR("Could not get bss info %d\n", err);
goto update_bss_info_out;
}
bi = (struct wl_bss_info *)(wl->extra_buf + 4);
err = wl_inform_single_bss(wl, bi);
if (unlikely(err))
goto update_bss_info_out;
ie = ((u8 *)bi) + bi->ie_offset;
ie_len = bi->ie_length;
beacon_interval = cpu_to_le16(bi->beacon_period);
tim = bcm_parse_tlvs(ie, ie_len, WLAN_EID_TIM);
if (tim)
dtim_period = tim->data[1];
else {
u32 var;
err = wl_dev_intvar_get(wl_to_ndev(wl), "dtim_assoc", &var);
if (unlikely(err)) {
WL_ERR("wl dtim_assoc failed (%d)\n", err);
goto update_bss_info_out;
}
dtim_period = (u8)var;
}
wl_update_prof(wl, NULL, &beacon_interval, WL_PROF_BEACONINT);
wl_update_prof(wl, NULL, &dtim_period, WL_PROF_DTIMPERIOD);
update_bss_info_out:
WL_TRACE("Exit");
return err;
}
static s32
wl_bss_roaming_done(struct wl_priv *wl, struct net_device *ndev,
const wl_event_msg_t *e, void *data)
{
struct wl_connect_info *conn_info = wl_to_conn(wl);
s32 err = 0;
WL_TRACE("Enter\n");
wl_get_assoc_ies(wl);
wl_update_prof(wl, NULL, &e->addr, WL_PROF_BSSID);
wl_update_bss_info(wl);
cfg80211_roamed(ndev, NULL,
(u8 *)wl_read_prof(wl, WL_PROF_BSSID),
conn_info->req_ie, conn_info->req_ie_len,
conn_info->resp_ie, conn_info->resp_ie_len, GFP_KERNEL);
WL_CONN("Report roaming result\n");
set_bit(WL_STATUS_CONNECTED, &wl->status);
WL_TRACE("Exit\n");
return err;
}
static s32
wl_bss_connect_done(struct wl_priv *wl, struct net_device *ndev,
const wl_event_msg_t *e, void *data, bool completed)
{
struct wl_connect_info *conn_info = wl_to_conn(wl);
s32 err = 0;
WL_TRACE("Enter\n");
if (test_and_clear_bit(WL_STATUS_CONNECTING, &wl->status)) {
if (completed) {
wl_get_assoc_ies(wl);
wl_update_prof(wl, NULL, &e->addr, WL_PROF_BSSID);
wl_update_bss_info(wl);
}
cfg80211_connect_result(ndev,
(u8 *)wl_read_prof(wl, WL_PROF_BSSID),
conn_info->req_ie,
conn_info->req_ie_len,
conn_info->resp_ie,
conn_info->resp_ie_len,
completed ? WLAN_STATUS_SUCCESS : WLAN_STATUS_AUTH_TIMEOUT,
GFP_KERNEL);
if (completed)
set_bit(WL_STATUS_CONNECTED, &wl->status);
WL_CONN("Report connect result - connection %s\n",
completed ? "succeeded" : "failed");
}
WL_TRACE("Exit\n");
return err;
}
static s32
wl_notify_mic_status(struct wl_priv *wl, struct net_device *ndev,
const wl_event_msg_t *e, void *data)
{
u16 flags = be16_to_cpu(e->flags);
enum nl80211_key_type key_type;
rtnl_lock();
if (flags & WLC_EVENT_MSG_GROUP)
key_type = NL80211_KEYTYPE_GROUP;
else
key_type = NL80211_KEYTYPE_PAIRWISE;
cfg80211_michael_mic_failure(ndev, (u8 *)&e->addr, key_type, -1,
NULL, GFP_KERNEL);
rtnl_unlock();
return 0;
}
static s32
wl_notify_scan_status(struct wl_priv *wl, struct net_device *ndev,
const wl_event_msg_t *e, void *data)
{
struct channel_info channel_inform;
struct wl_scan_results *bss_list;
u32 len = WL_SCAN_BUF_MAX;
s32 err = 0;
bool scan_abort = false;
WL_TRACE("Enter\n");
if (wl->iscan_on && wl->iscan_kickstart) {
WL_TRACE("Exit\n");
return wl_wakeup_iscan(wl_to_iscan(wl));
}
if (unlikely(!test_and_clear_bit(WL_STATUS_SCANNING, &wl->status))) {
WL_ERR("Scan complete while device not scanning\n");
scan_abort = true;
err = -EINVAL;
goto scan_done_out;
}
err = wl_dev_ioctl(ndev, WLC_GET_CHANNEL, &channel_inform,
sizeof(channel_inform));
if (unlikely(err)) {
WL_ERR("scan busy (%d)\n", err);
scan_abort = true;
goto scan_done_out;
}
channel_inform.scan_channel = le32_to_cpu(channel_inform.scan_channel);
if (unlikely(channel_inform.scan_channel)) {
WL_CONN("channel_inform.scan_channel (%d)\n",
channel_inform.scan_channel);
}
wl->bss_list = wl->scan_results;
bss_list = wl->bss_list;
memset(bss_list, 0, len);
bss_list->buflen = cpu_to_le32(len);
err = wl_dev_ioctl(ndev, WLC_SCAN_RESULTS, bss_list, len);
if (unlikely(err)) {
WL_ERR("%s Scan_results error (%d)\n", ndev->name, err);
err = -EINVAL;
scan_abort = true;
goto scan_done_out;
}
bss_list->buflen = le32_to_cpu(bss_list->buflen);
bss_list->version = le32_to_cpu(bss_list->version);
bss_list->count = le32_to_cpu(bss_list->count);
err = wl_inform_bss(wl);
if (err) {
scan_abort = true;
goto scan_done_out;
}
scan_done_out:
if (wl->scan_request) {
WL_SCAN("calling cfg80211_scan_done\n");
cfg80211_scan_done(wl->scan_request, scan_abort);
wl_set_mpc(ndev, 1);
wl->scan_request = NULL;
}
WL_TRACE("Exit\n");
return err;
}
static void wl_init_conf(struct wl_conf *conf)
{
conf->mode = (u32)-1;
conf->frag_threshold = (u32)-1;
conf->rts_threshold = (u32)-1;
conf->retry_short = (u32)-1;
conf->retry_long = (u32)-1;
conf->tx_power = -1;
}
static void wl_init_prof(struct wl_profile *prof)
{
memset(prof, 0, sizeof(*prof));
}
static void wl_init_eloop_handler(struct wl_event_loop *el)
{
memset(el, 0, sizeof(*el));
el->handler[WLC_E_SCAN_COMPLETE] = wl_notify_scan_status;
el->handler[WLC_E_LINK] = wl_notify_connect_status;
el->handler[WLC_E_ROAM] = wl_notify_roaming_status;
el->handler[WLC_E_MIC_ERROR] = wl_notify_mic_status;
el->handler[WLC_E_SET_SSID] = wl_notify_connect_status;
}
static s32 wl_init_priv_mem(struct wl_priv *wl)
{
wl->scan_results = kzalloc(WL_SCAN_BUF_MAX, GFP_KERNEL);
if (unlikely(!wl->scan_results)) {
WL_ERR("Scan results alloc failed\n");
goto init_priv_mem_out;
}
wl->conf = kzalloc(sizeof(*wl->conf), GFP_KERNEL);
if (unlikely(!wl->conf)) {
WL_ERR("wl_conf alloc failed\n");
goto init_priv_mem_out;
}
wl->profile = kzalloc(sizeof(*wl->profile), GFP_KERNEL);
if (unlikely(!wl->profile)) {
WL_ERR("wl_profile alloc failed\n");
goto init_priv_mem_out;
}
wl->bss_info = kzalloc(WL_BSS_INFO_MAX, GFP_KERNEL);
if (unlikely(!wl->bss_info)) {
WL_ERR("Bss information alloc failed\n");
goto init_priv_mem_out;
}
wl->scan_req_int = kzalloc(sizeof(*wl->scan_req_int), GFP_KERNEL);
if (unlikely(!wl->scan_req_int)) {
WL_ERR("Scan req alloc failed\n");
goto init_priv_mem_out;
}
wl->ioctl_buf = kzalloc(WL_IOCTL_LEN_MAX, GFP_KERNEL);
if (unlikely(!wl->ioctl_buf)) {
WL_ERR("Ioctl buf alloc failed\n");
goto init_priv_mem_out;
}
wl->extra_buf = kzalloc(WL_EXTRA_BUF_MAX, GFP_KERNEL);
if (unlikely(!wl->extra_buf)) {
WL_ERR("Extra buf alloc failed\n");
goto init_priv_mem_out;
}
wl->iscan = kzalloc(sizeof(*wl->iscan), GFP_KERNEL);
if (unlikely(!wl->iscan)) {
WL_ERR("Iscan buf alloc failed\n");
goto init_priv_mem_out;
}
wl->fw = kzalloc(sizeof(*wl->fw), GFP_KERNEL);
if (unlikely(!wl->fw)) {
WL_ERR("fw object alloc failed\n");
goto init_priv_mem_out;
}
wl->pmk_list = kzalloc(sizeof(*wl->pmk_list), GFP_KERNEL);
if (unlikely(!wl->pmk_list)) {
WL_ERR("pmk list alloc failed\n");
goto init_priv_mem_out;
}
return 0;
init_priv_mem_out:
wl_deinit_priv_mem(wl);
return -ENOMEM;
}
static void wl_deinit_priv_mem(struct wl_priv *wl)
{
kfree(wl->scan_results);
wl->scan_results = NULL;
kfree(wl->bss_info);
wl->bss_info = NULL;
kfree(wl->conf);
wl->conf = NULL;
kfree(wl->profile);
wl->profile = NULL;
kfree(wl->scan_req_int);
wl->scan_req_int = NULL;
kfree(wl->ioctl_buf);
wl->ioctl_buf = NULL;
kfree(wl->extra_buf);
wl->extra_buf = NULL;
kfree(wl->iscan);
wl->iscan = NULL;
kfree(wl->fw);
wl->fw = NULL;
kfree(wl->pmk_list);
wl->pmk_list = NULL;
}
static s32 wl_create_event_handler(struct wl_priv *wl)
{
sema_init(&wl->event_sync, 0);
wl->event_tsk = kthread_run(wl_event_handler, wl, "wl_event_handler");
if (IS_ERR(wl->event_tsk)) {
wl->event_tsk = NULL;
WL_ERR("failed to create event thread\n");
return -ENOMEM;
}
return 0;
}
static void wl_destroy_event_handler(struct wl_priv *wl)
{
if (wl->event_tsk) {
send_sig(SIGTERM, wl->event_tsk, 1);
kthread_stop(wl->event_tsk);
wl->event_tsk = NULL;
}
}
static void wl_term_iscan(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl_to_iscan(wl);
if (wl->iscan_on && iscan->tsk) {
iscan->state = WL_ISCAN_STATE_IDLE;
send_sig(SIGTERM, iscan->tsk, 1);
kthread_stop(iscan->tsk);
iscan->tsk = NULL;
}
}
static void wl_notify_iscan_complete(struct wl_iscan_ctrl *iscan, bool aborted)
{
struct wl_priv *wl = iscan_to_wl(iscan);
struct net_device *ndev = wl_to_ndev(wl);
if (unlikely(!test_and_clear_bit(WL_STATUS_SCANNING, &wl->status))) {
WL_ERR("Scan complete while device not scanning\n");
return;
}
if (likely(wl->scan_request)) {
WL_SCAN("ISCAN Completed scan: %s\n",
aborted ? "Aborted" : "Done");
cfg80211_scan_done(wl->scan_request, aborted);
wl_set_mpc(ndev, 1);
wl->scan_request = NULL;
}
wl->iscan_kickstart = false;
}
static s32 wl_wakeup_iscan(struct wl_iscan_ctrl *iscan)
{
if (likely(iscan->state != WL_ISCAN_STATE_IDLE)) {
WL_SCAN("wake up iscan\n");
up(&iscan->sync);
return 0;
}
return -EIO;
}
static s32
wl_get_iscan_results(struct wl_iscan_ctrl *iscan, u32 *status,
struct wl_scan_results **bss_list)
{
struct wl_iscan_results list;
struct wl_scan_results *results;
struct wl_iscan_results *list_buf;
s32 err = 0;
memset(iscan->scan_buf, 0, WL_ISCAN_BUF_MAX);
list_buf = (struct wl_iscan_results *)iscan->scan_buf;
results = &list_buf->results;
results->buflen = WL_ISCAN_RESULTS_FIXED_SIZE;
results->version = 0;
results->count = 0;
memset(&list, 0, sizeof(list));
list.results.buflen = cpu_to_le32(WL_ISCAN_BUF_MAX);
err = wl_dev_iovar_getbuf(iscan->dev, "iscanresults", &list,
WL_ISCAN_RESULTS_FIXED_SIZE, iscan->scan_buf,
WL_ISCAN_BUF_MAX);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
results->buflen = le32_to_cpu(results->buflen);
results->version = le32_to_cpu(results->version);
results->count = le32_to_cpu(results->count);
WL_SCAN("results->count = %d\n", results->count);
WL_SCAN("results->buflen = %d\n", results->buflen);
*status = le32_to_cpu(list_buf->status);
*bss_list = results;
return err;
}
static s32 wl_iscan_done(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl->iscan;
s32 err = 0;
iscan->state = WL_ISCAN_STATE_IDLE;
rtnl_lock();
wl_inform_bss(wl);
wl_notify_iscan_complete(iscan, false);
rtnl_unlock();
return err;
}
static s32 wl_iscan_pending(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl->iscan;
s32 err = 0;
mod_timer(&iscan->timer, jiffies + iscan->timer_ms * HZ / 1000);
iscan->timer_on = 1;
return err;
}
static s32 wl_iscan_inprogress(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl->iscan;
s32 err = 0;
rtnl_lock();
wl_inform_bss(wl);
wl_run_iscan(iscan, NULL, WL_SCAN_ACTION_CONTINUE);
rtnl_unlock();
mod_timer(&iscan->timer, jiffies + iscan->timer_ms * HZ / 1000);
iscan->timer_on = 1;
return err;
}
static s32 wl_iscan_aborted(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl->iscan;
s32 err = 0;
iscan->state = WL_ISCAN_STATE_IDLE;
rtnl_lock();
wl_notify_iscan_complete(iscan, true);
rtnl_unlock();
return err;
}
static s32 wl_iscan_thread(void *data)
{
struct sched_param param = {.sched_priority = MAX_RT_PRIO - 1 };
struct wl_iscan_ctrl *iscan = (struct wl_iscan_ctrl *)data;
struct wl_priv *wl = iscan_to_wl(iscan);
struct wl_iscan_eloop *el = &iscan->el;
u32 status;
int err = 0;
sched_setscheduler(current, SCHED_FIFO, &param);
allow_signal(SIGTERM);
status = WL_SCAN_RESULTS_PARTIAL;
while (likely(!down_interruptible(&iscan->sync))) {
if (kthread_should_stop())
break;
if (iscan->timer_on) {
del_timer_sync(&iscan->timer);
iscan->timer_on = 0;
}
rtnl_lock();
err = wl_get_iscan_results(iscan, &status, &wl->bss_list);
if (unlikely(err)) {
status = WL_SCAN_RESULTS_ABORTED;
WL_ERR("Abort iscan\n");
}
rtnl_unlock();
el->handler[status] (wl);
}
if (iscan->timer_on) {
del_timer_sync(&iscan->timer);
iscan->timer_on = 0;
}
WL_SCAN("ISCAN thread terminated\n");
return 0;
}
static void wl_iscan_timer(unsigned long data)
{
struct wl_iscan_ctrl *iscan = (struct wl_iscan_ctrl *)data;
if (iscan) {
iscan->timer_on = 0;
WL_SCAN("timer expired\n");
wl_wakeup_iscan(iscan);
}
}
static s32 wl_invoke_iscan(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl_to_iscan(wl);
int err = 0;
if (wl->iscan_on && !iscan->tsk) {
iscan->state = WL_ISCAN_STATE_IDLE;
sema_init(&iscan->sync, 0);
iscan->tsk = kthread_run(wl_iscan_thread, iscan, "wl_iscan");
if (IS_ERR(iscan->tsk)) {
WL_ERR("Could not create iscan thread\n");
iscan->tsk = NULL;
return -ENOMEM;
}
}
return err;
}
static void wl_init_iscan_eloop(struct wl_iscan_eloop *el)
{
memset(el, 0, sizeof(*el));
el->handler[WL_SCAN_RESULTS_SUCCESS] = wl_iscan_done;
el->handler[WL_SCAN_RESULTS_PARTIAL] = wl_iscan_inprogress;
el->handler[WL_SCAN_RESULTS_PENDING] = wl_iscan_pending;
el->handler[WL_SCAN_RESULTS_ABORTED] = wl_iscan_aborted;
el->handler[WL_SCAN_RESULTS_NO_MEM] = wl_iscan_aborted;
}
static s32 wl_init_iscan(struct wl_priv *wl)
{
struct wl_iscan_ctrl *iscan = wl_to_iscan(wl);
int err = 0;
if (wl->iscan_on) {
iscan->dev = wl_to_ndev(wl);
iscan->state = WL_ISCAN_STATE_IDLE;
wl_init_iscan_eloop(&iscan->el);
iscan->timer_ms = WL_ISCAN_TIMER_INTERVAL_MS;
init_timer(&iscan->timer);
iscan->timer.data = (unsigned long) iscan;
iscan->timer.function = wl_iscan_timer;
sema_init(&iscan->sync, 0);
iscan->tsk = kthread_run(wl_iscan_thread, iscan, "wl_iscan");
if (IS_ERR(iscan->tsk)) {
WL_ERR("Could not create iscan thread\n");
iscan->tsk = NULL;
return -ENOMEM;
}
iscan->data = wl;
}
return err;
}
static void wl_init_fw(struct wl_fw_ctrl *fw)
{
fw->status = 0;
}
static s32 wl_init_priv(struct wl_priv *wl)
{
struct wiphy *wiphy = wl_to_wiphy(wl);
s32 err = 0;
wl->scan_request = NULL;
wl->pwr_save = !!(wiphy->flags & WIPHY_FLAG_PS_ON_BY_DEFAULT);
wl->iscan_on = true;
wl->roam_on = false;
wl->iscan_kickstart = false;
wl->active_scan = true;
wl->dongle_up = false;
wl_init_eq(wl);
err = wl_init_priv_mem(wl);
if (unlikely(err))
return err;
if (unlikely(wl_create_event_handler(wl)))
return -ENOMEM;
wl_init_eloop_handler(&wl->el);
mutex_init(&wl->usr_sync);
err = wl_init_iscan(wl);
if (unlikely(err))
return err;
wl_init_fw(wl->fw);
wl_init_conf(wl->conf);
wl_init_prof(wl->profile);
wl_link_down(wl);
return err;
}
static void wl_deinit_priv(struct wl_priv *wl)
{
wl_destroy_event_handler(wl);
wl->dongle_up = false;
wl_flush_eq(wl);
wl_link_down(wl);
wl_term_iscan(wl);
wl_deinit_priv_mem(wl);
}
s32 wl_cfg80211_attach(struct net_device *ndev, void *data)
{
struct wireless_dev *wdev;
struct wl_priv *wl;
struct wl_iface *ci;
s32 err = 0;
if (unlikely(!ndev)) {
WL_ERR("ndev is invalid\n");
return -ENODEV;
}
wl_cfg80211_dev = kzalloc(sizeof(struct wl_dev), GFP_KERNEL);
if (unlikely(!wl_cfg80211_dev)) {
WL_ERR("wl_cfg80211_dev is invalid\n");
return -ENOMEM;
}
WL_INFO("func %p\n", wl_cfg80211_get_sdio_func());
wdev = wl_alloc_wdev(sizeof(struct wl_iface), &wl_cfg80211_get_sdio_func()->dev);
if (IS_ERR(wdev))
return -ENOMEM;
wdev->iftype = wl_mode_to_nl80211_iftype(WL_MODE_BSS);
wl = wdev_to_wl(wdev);
wl->wdev = wdev;
wl->pub = data;
ci = (struct wl_iface *)wl_to_ci(wl);
ci->wl = wl;
ndev->ieee80211_ptr = wdev;
SET_NETDEV_DEV(ndev, wiphy_dev(wdev->wiphy));
wdev->netdev = ndev;
err = wl_init_priv(wl);
if (unlikely(err)) {
WL_ERR("Failed to init iwm_priv (%d)\n", err);
goto cfg80211_attach_out;
}
wl_set_drvdata(wl_cfg80211_dev, ci);
return err;
cfg80211_attach_out:
wl_free_wdev(wl);
return err;
}
void wl_cfg80211_detach(void)
{
struct wl_priv *wl;
wl = WL_PRIV_GET();
wl_deinit_priv(wl);
wl_free_wdev(wl);
wl_set_drvdata(wl_cfg80211_dev, NULL);
kfree(wl_cfg80211_dev);
wl_cfg80211_dev = NULL;
wl_clear_sdio_func();
}
static void wl_wakeup_event(struct wl_priv *wl)
{
up(&wl->event_sync);
}
static s32 wl_event_handler(void *data)
{
struct wl_priv *wl = (struct wl_priv *)data;
struct sched_param param = {.sched_priority = MAX_RT_PRIO - 1 };
struct wl_event_q *e;
sched_setscheduler(current, SCHED_FIFO, &param);
allow_signal(SIGTERM);
while (likely(!down_interruptible(&wl->event_sync))) {
if (kthread_should_stop())
break;
e = wl_deq_event(wl);
if (unlikely(!e)) {
WL_ERR("event queue empty...\n");
BUG();
}
WL_INFO("event type (%d)\n", e->etype);
if (wl->el.handler[e->etype]) {
wl->el.handler[e->etype] (wl, wl_to_ndev(wl), &e->emsg,
e->edata);
} else {
WL_INFO("Unknown Event (%d): ignoring\n", e->etype);
}
wl_put_event(e);
}
WL_INFO("was terminated\n");
return 0;
}
void
wl_cfg80211_event(struct net_device *ndev, const wl_event_msg_t * e, void *data)
{
u32 event_type = be32_to_cpu(e->event_type);
struct wl_priv *wl = ndev_to_wl(ndev);
if (likely(!wl_enq_event(wl, event_type, e, data)))
wl_wakeup_event(wl);
}
static void wl_init_eq(struct wl_priv *wl)
{
wl_init_eq_lock(wl);
INIT_LIST_HEAD(&wl->eq_list);
}
static void wl_flush_eq(struct wl_priv *wl)
{
struct wl_event_q *e;
wl_lock_eq(wl);
while (!list_empty(&wl->eq_list)) {
e = list_first_entry(&wl->eq_list, struct wl_event_q, eq_list);
list_del(&e->eq_list);
kfree(e);
}
wl_unlock_eq(wl);
}
static struct wl_event_q *wl_deq_event(struct wl_priv *wl)
{
struct wl_event_q *e = NULL;
wl_lock_eq(wl);
if (likely(!list_empty(&wl->eq_list))) {
e = list_first_entry(&wl->eq_list, struct wl_event_q, eq_list);
list_del(&e->eq_list);
}
wl_unlock_eq(wl);
return e;
}
static s32
wl_enq_event(struct wl_priv *wl, u32 event, const wl_event_msg_t *msg,
void *data)
{
struct wl_event_q *e;
s32 err = 0;
e = kzalloc(sizeof(struct wl_event_q), GFP_KERNEL);
if (unlikely(!e)) {
WL_ERR("event alloc failed\n");
return -ENOMEM;
}
e->etype = event;
memcpy(&e->emsg, msg, sizeof(wl_event_msg_t));
if (data) {
}
wl_lock_eq(wl);
list_add_tail(&e->eq_list, &wl->eq_list);
wl_unlock_eq(wl);
return err;
}
static void wl_put_event(struct wl_event_q *e)
{
kfree(e);
}
void wl_cfg80211_sdio_func(void *func)
{
cfg80211_sdio_func = (struct sdio_func *)func;
}
static void wl_clear_sdio_func(void)
{
cfg80211_sdio_func = NULL;
}
struct sdio_func *wl_cfg80211_get_sdio_func(void)
{
return cfg80211_sdio_func;
}
static s32 wl_dongle_mode(struct net_device *ndev, s32 iftype)
{
s32 infra = 0;
s32 err = 0;
switch (iftype) {
case NL80211_IFTYPE_MONITOR:
case NL80211_IFTYPE_WDS:
WL_ERR("type (%d) : currently we do not support this mode\n",
iftype);
err = -EINVAL;
return err;
case NL80211_IFTYPE_ADHOC:
infra = 0;
break;
case NL80211_IFTYPE_STATION:
infra = 1;
break;
default:
err = -EINVAL;
WL_ERR("invalid type (%d)\n", iftype);
return err;
}
infra = cpu_to_le32(infra);
err = wl_dev_ioctl(ndev, WLC_SET_INFRA, &infra, sizeof(infra));
if (unlikely(err)) {
WL_ERR("WLC_SET_INFRA error (%d)\n", err);
return err;
}
return 0;
}
static s32 wl_dongle_country(struct net_device *ndev, u8 ccode)
{
s32 err = 0;
return err;
}
static s32 wl_dongle_up(struct net_device *ndev, u32 up)
{
s32 err = 0;
err = wl_dev_ioctl(ndev, WLC_UP, &up, sizeof(up));
if (unlikely(err)) {
WL_ERR("WLC_UP error (%d)\n", err);
}
return err;
}
static s32 wl_dongle_power(struct net_device *ndev, u32 power_mode)
{
s32 err = 0;
err = wl_dev_ioctl(ndev, WLC_SET_PM, &power_mode, sizeof(power_mode));
if (unlikely(err)) {
WL_ERR("WLC_SET_PM error (%d)\n", err);
}
return err;
}
static s32
wl_dongle_glom(struct net_device *ndev, u32 glom, u32 dongle_align)
{
s8 iovbuf[WL_EVENTING_MASK_LEN + 12];
s32 err = 0;
bcm_mkiovar("bus:txglomalign", (char *)&dongle_align, 4, iovbuf,
sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("txglomalign error (%d)\n", err);
goto dongle_glom_out;
}
bcm_mkiovar("bus:txglom", (char *)&glom, 4, iovbuf, sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("txglom error (%d)\n", err);
goto dongle_glom_out;
}
dongle_glom_out:
return err;
}
static s32
wl_dongle_offload(struct net_device *ndev, s32 arpoe, s32 arp_ol)
{
s8 iovbuf[WL_EVENTING_MASK_LEN + 12];
s32 err = 0;
bcm_mkiovar("arpoe", (char *)&arpoe, 4, iovbuf, sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (err) {
if (err == -EOPNOTSUPP)
WL_INFO("arpoe is not supported\n");
else
WL_ERR("arpoe error (%d)\n", err);
goto dongle_offload_out;
}
bcm_mkiovar("arp_ol", (char *)&arp_ol, 4, iovbuf, sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (err) {
if (err == -EOPNOTSUPP)
WL_INFO("arp_ol is not supported\n");
else
WL_ERR("arp_ol error (%d)\n", err);
goto dongle_offload_out;
}
dongle_offload_out:
return err;
}
static s32 wl_pattern_atoh(s8 *src, s8 *dst)
{
int i;
if (strncmp(src, "0x", 2) != 0 && strncmp(src, "0X", 2) != 0) {
WL_ERR("Mask invalid format. Needs to start with 0x\n");
return -1;
}
src = src + 2;
if (strlen(src) % 2 != 0) {
WL_ERR("Mask invalid format. Needs to be of even length\n");
return -1;
}
for (i = 0; *src != '\0'; i++) {
char num[3];
strncpy(num, src, 2);
num[2] = '\0';
dst[i] = (u8) simple_strtoul(num, NULL, 16);
src += 2;
}
return i;
}
static s32 wl_dongle_filter(struct net_device *ndev, u32 filter_mode)
{
s8 iovbuf[WL_EVENTING_MASK_LEN + 12];
const s8 *str;
struct wl_pkt_filter pkt_filter;
struct wl_pkt_filter *pkt_filterp;
s32 buf_len;
s32 str_len;
u32 mask_size;
u32 pattern_size;
s8 buf[256];
s32 err = 0;
str = "pkt_filter_add";
str_len = strlen(str);
strncpy(buf, str, str_len);
buf[str_len] = '\0';
buf_len = str_len + 1;
pkt_filterp = (struct wl_pkt_filter *)(buf + str_len + 1);
pkt_filter.id = cpu_to_le32(100);
pkt_filter.negate_match = cpu_to_le32(0);
pkt_filter.type = cpu_to_le32(0);
pkt_filter.u.pattern.offset = cpu_to_le32(0);
mask_size = cpu_to_le32(wl_pattern_atoh("0xff",
(char *)pkt_filterp->u.pattern.
mask_and_pattern));
pattern_size = cpu_to_le32(wl_pattern_atoh("0x00",
(char *)&pkt_filterp->u.
pattern.
mask_and_pattern
[mask_size]));
if (mask_size != pattern_size) {
WL_ERR("Mask and pattern not the same size\n");
err = -EINVAL;
goto dongle_filter_out;
}
pkt_filter.u.pattern.size_bytes = mask_size;
buf_len += WL_PKT_FILTER_FIXED_LEN;
buf_len += (WL_PKT_FILTER_PATTERN_FIXED_LEN + 2 * mask_size);
memcpy((char *)pkt_filterp, &pkt_filter,
WL_PKT_FILTER_FIXED_LEN + WL_PKT_FILTER_PATTERN_FIXED_LEN);
err = wl_dev_ioctl(ndev, WLC_SET_VAR, buf, buf_len);
if (err) {
if (err == -EOPNOTSUPP) {
WL_INFO("filter not supported\n");
} else {
WL_ERR("filter (%d)\n", err);
}
goto dongle_filter_out;
}
bcm_mkiovar("pkt_filter_mode", (char *)&filter_mode, 4, iovbuf,
sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (err) {
if (err == -EOPNOTSUPP) {
WL_INFO("filter_mode not supported\n");
} else {
WL_ERR("filter_mode (%d)\n", err);
}
goto dongle_filter_out;
}
dongle_filter_out:
return err;
}
static s32 wl_dongle_eventmsg(struct net_device *ndev)
{
s8 iovbuf[WL_EVENTING_MASK_LEN + 12];
s8 eventmask[WL_EVENTING_MASK_LEN];
s32 err = 0;
WL_TRACE("Enter\n");
bcm_mkiovar("event_msgs", eventmask, WL_EVENTING_MASK_LEN, iovbuf,
sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_GET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("Get event_msgs error (%d)\n", err);
goto dongle_eventmsg_out;
}
memcpy(eventmask, iovbuf, WL_EVENTING_MASK_LEN);
setbit(eventmask, WLC_E_SET_SSID);
setbit(eventmask, WLC_E_ROAM);
setbit(eventmask, WLC_E_PRUNE);
setbit(eventmask, WLC_E_AUTH);
setbit(eventmask, WLC_E_REASSOC);
setbit(eventmask, WLC_E_REASSOC_IND);
setbit(eventmask, WLC_E_DEAUTH_IND);
setbit(eventmask, WLC_E_DISASSOC_IND);
setbit(eventmask, WLC_E_DISASSOC);
setbit(eventmask, WLC_E_JOIN);
setbit(eventmask, WLC_E_ASSOC_IND);
setbit(eventmask, WLC_E_PSK_SUP);
setbit(eventmask, WLC_E_LINK);
setbit(eventmask, WLC_E_NDIS_LINK);
setbit(eventmask, WLC_E_MIC_ERROR);
setbit(eventmask, WLC_E_PMKID_CACHE);
setbit(eventmask, WLC_E_TXFAIL);
setbit(eventmask, WLC_E_JOIN_START);
setbit(eventmask, WLC_E_SCAN_COMPLETE);
bcm_mkiovar("event_msgs", eventmask, WL_EVENTING_MASK_LEN, iovbuf,
sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("Set event_msgs error (%d)\n", err);
goto dongle_eventmsg_out;
}
dongle_eventmsg_out:
WL_TRACE("Exit\n");
return err;
}
static s32
wl_dongle_roam(struct net_device *ndev, u32 roamvar, u32 bcn_timeout)
{
s8 iovbuf[32];
s32 roamtrigger[2];
s32 roam_delta[2];
s32 err = 0;
if (roamvar) {
bcm_mkiovar("bcn_timeout", (char *)&bcn_timeout,
sizeof(bcn_timeout), iovbuf, sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("bcn_timeout error (%d)\n", err);
goto dongle_rom_out;
}
}
WL_INFO("Internal Roaming = %s\n", roamvar ? "Off" : "On");
bcm_mkiovar("roam_off", (char *)&roamvar,
sizeof(roamvar), iovbuf, sizeof(iovbuf));
err = wl_dev_ioctl(ndev, WLC_SET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("roam_off error (%d)\n", err);
goto dongle_rom_out;
}
roamtrigger[0] = WL_ROAM_TRIGGER_LEVEL;
roamtrigger[1] = WLC_BAND_ALL;
err = wl_dev_ioctl(ndev, WLC_SET_ROAM_TRIGGER,
(void *)roamtrigger, sizeof(roamtrigger));
if (unlikely(err)) {
WL_ERR("WLC_SET_ROAM_TRIGGER error (%d)\n", err);
goto dongle_rom_out;
}
roam_delta[0] = WL_ROAM_DELTA;
roam_delta[1] = WLC_BAND_ALL;
err = wl_dev_ioctl(ndev, WLC_SET_ROAM_DELTA,
(void *)roam_delta, sizeof(roam_delta));
if (unlikely(err)) {
WL_ERR("WLC_SET_ROAM_DELTA error (%d)\n", err);
goto dongle_rom_out;
}
dongle_rom_out:
return err;
}
static s32
wl_dongle_scantime(struct net_device *ndev, s32 scan_assoc_time,
s32 scan_unassoc_time, s32 scan_passive_time)
{
s32 err = 0;
err = wl_dev_ioctl(ndev, WLC_SET_SCAN_CHANNEL_TIME, &scan_assoc_time,
sizeof(scan_assoc_time));
if (err) {
if (err == -EOPNOTSUPP)
WL_INFO("Scan assoc time is not supported\n");
else
WL_ERR("Scan assoc time error (%d)\n", err);
goto dongle_scantime_out;
}
err = wl_dev_ioctl(ndev, WLC_SET_SCAN_UNASSOC_TIME, &scan_unassoc_time,
sizeof(scan_unassoc_time));
if (err) {
if (err == -EOPNOTSUPP)
WL_INFO("Scan unassoc time is not supported\n");
else
WL_ERR("Scan unassoc time error (%d)\n", err);
goto dongle_scantime_out;
}
err = wl_dev_ioctl(ndev, WLC_SET_SCAN_PASSIVE_TIME, &scan_passive_time,
sizeof(scan_passive_time));
if (err) {
if (err == -EOPNOTSUPP)
WL_INFO("Scan passive time is not supported\n");
else
WL_ERR("Scan passive time error (%d)\n", err);
goto dongle_scantime_out;
}
dongle_scantime_out:
return err;
}
s32 wl_config_dongle(struct wl_priv *wl, bool need_lock)
{
#ifndef DHD_SDALIGN
#define DHD_SDALIGN 32
#endif
struct net_device *ndev;
struct wireless_dev *wdev;
s32 err = 0;
if (wl->dongle_up)
return err;
ndev = wl_to_ndev(wl);
wdev = ndev->ieee80211_ptr;
if (need_lock)
rtnl_lock();
#ifndef EMBEDDED_PLATFORM
err = wl_dongle_up(ndev, 0);
if (unlikely(err))
goto default_conf_out;
err = wl_dongle_country(ndev, 0);
if (unlikely(err))
goto default_conf_out;
err = wl_dongle_power(ndev, PM_FAST);
if (unlikely(err))
goto default_conf_out;
err = wl_dongle_glom(ndev, 0, DHD_SDALIGN);
if (unlikely(err))
goto default_conf_out;
wl_dongle_offload(ndev, 1, 0xf);
wl_dongle_filter(ndev, 1);
#endif
wl_dongle_scantime(ndev, WL_SCAN_CHANNEL_TIME,
WL_SCAN_UNASSOC_TIME, WL_SCAN_PASSIVE_TIME);
err = wl_dongle_eventmsg(ndev);
if (unlikely(err))
goto default_conf_out;
err = wl_dongle_roam(ndev, (wl->roam_on ? 0 : 1), WL_BEACON_TIMEOUT);
if (unlikely(err))
goto default_conf_out;
err = wl_dongle_mode(ndev, wdev->iftype);
if (unlikely(err && err != -EINPROGRESS))
goto default_conf_out;
err = wl_dongle_probecap(wl);
if (unlikely(err))
goto default_conf_out;
default_conf_out:
if (need_lock)
rtnl_unlock();
wl->dongle_up = true;
return err;
}
static s32 wl_update_wiphybands(struct wl_priv *wl)
{
struct wiphy *wiphy;
s32 phy_list;
s8 phy;
s32 err = 0;
err = wl_dev_ioctl(wl_to_ndev(wl), WLC_GET_PHYLIST, &phy_list,
sizeof(phy_list));
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
phy = ((char *)&phy_list)[1];
WL_INFO("%c phy\n", phy);
if (phy == 'n' || phy == 'a') {
wiphy = wl_to_wiphy(wl);
wiphy->bands[IEEE80211_BAND_5GHZ] = &__wl_band_5ghz_n;
}
return err;
}
static s32 __wl_cfg80211_up(struct wl_priv *wl)
{
s32 err = 0;
set_bit(WL_STATUS_READY, &wl->status);
wl_debugfs_add_netdev_params(wl);
err = wl_config_dongle(wl, false);
if (unlikely(err))
return err;
wl_invoke_iscan(wl);
return err;
}
static s32 __wl_cfg80211_down(struct wl_priv *wl)
{
set_bit(WL_STATUS_SCAN_ABORTING, &wl->status);
wl_term_iscan(wl);
if (wl->scan_request) {
cfg80211_scan_done(wl->scan_request, true);
wl->scan_request = NULL;
}
clear_bit(WL_STATUS_READY, &wl->status);
clear_bit(WL_STATUS_SCANNING, &wl->status);
clear_bit(WL_STATUS_SCAN_ABORTING, &wl->status);
clear_bit(WL_STATUS_CONNECTING, &wl->status);
clear_bit(WL_STATUS_CONNECTED, &wl->status);
wl_debugfs_remove_netdev(wl);
return 0;
}
s32 wl_cfg80211_up(void)
{
struct wl_priv *wl;
s32 err = 0;
wl = WL_PRIV_GET();
mutex_lock(&wl->usr_sync);
err = __wl_cfg80211_up(wl);
mutex_unlock(&wl->usr_sync);
return err;
}
s32 wl_cfg80211_down(void)
{
struct wl_priv *wl;
s32 err = 0;
wl = WL_PRIV_GET();
mutex_lock(&wl->usr_sync);
err = __wl_cfg80211_down(wl);
mutex_unlock(&wl->usr_sync);
return err;
}
static s32 wl_dongle_probecap(struct wl_priv *wl)
{
s32 err = 0;
err = wl_update_wiphybands(wl);
if (unlikely(err))
return err;
return err;
}
static void *wl_read_prof(struct wl_priv *wl, s32 item)
{
switch (item) {
case WL_PROF_SEC:
return &wl->profile->sec;
case WL_PROF_BSSID:
return &wl->profile->bssid;
case WL_PROF_SSID:
return &wl->profile->ssid;
}
WL_ERR("invalid item (%d)\n", item);
return NULL;
}
static s32
wl_update_prof(struct wl_priv *wl, const wl_event_msg_t *e, void *data,
s32 item)
{
s32 err = 0;
struct wlc_ssid *ssid;
switch (item) {
case WL_PROF_SSID:
ssid = (wlc_ssid_t *) data;
memset(wl->profile->ssid.SSID, 0,
sizeof(wl->profile->ssid.SSID));
memcpy(wl->profile->ssid.SSID, ssid->SSID, ssid->SSID_len);
wl->profile->ssid.SSID_len = ssid->SSID_len;
break;
case WL_PROF_BSSID:
if (data)
memcpy(wl->profile->bssid, data, ETH_ALEN);
else
memset(wl->profile->bssid, 0, ETH_ALEN);
break;
case WL_PROF_SEC:
memcpy(&wl->profile->sec, data, sizeof(wl->profile->sec));
break;
case WL_PROF_BEACONINT:
wl->profile->beacon_interval = *(u16 *)data;
break;
case WL_PROF_DTIMPERIOD:
wl->profile->dtim_period = *(u8 *)data;
break;
default:
WL_ERR("unsupported item (%d)\n", item);
err = -EOPNOTSUPP;
break;
}
return err;
}
static bool wl_is_ibssmode(struct wl_priv *wl)
{
return wl->conf->mode == WL_MODE_IBSS;
}
static __used s32 wl_add_ie(struct wl_priv *wl, u8 t, u8 l, u8 *v)
{
struct wl_ie *ie = wl_to_ie(wl);
s32 err = 0;
if (unlikely(ie->offset + l + 2 > WL_TLV_INFO_MAX)) {
WL_ERR("ei crosses buffer boundary\n");
return -ENOSPC;
}
ie->buf[ie->offset] = t;
ie->buf[ie->offset + 1] = l;
memcpy(&ie->buf[ie->offset + 2], v, l);
ie->offset += l + 2;
return err;
}
static void wl_link_down(struct wl_priv *wl)
{
struct net_device *dev = NULL;
s32 err = 0;
WL_TRACE("Enter\n");
clear_bit(WL_STATUS_CONNECTED, &wl->status);
if (wl->link_up) {
dev = wl_to_ndev(wl);
WL_INFO("Call WLC_DISASSOC to stop excess roaming\n ");
err = wl_dev_ioctl(dev, WLC_DISASSOC, NULL, 0);
if (unlikely(err))
WL_ERR("WLC_DISASSOC failed (%d)\n", err);
wl->link_up = false;
}
WL_TRACE("Exit\n");
}
static void wl_lock_eq(struct wl_priv *wl)
{
spin_lock_irq(&wl->eq_lock);
}
static void wl_unlock_eq(struct wl_priv *wl)
{
spin_unlock_irq(&wl->eq_lock);
}
static void wl_init_eq_lock(struct wl_priv *wl)
{
spin_lock_init(&wl->eq_lock);
}
static void wl_delay(u32 ms)
{
if (ms < 1000 / HZ) {
cond_resched();
mdelay(ms);
} else {
msleep(ms);
}
}
static void wl_set_drvdata(struct wl_dev *dev, void *data)
{
dev->driver_data = data;
}
static void *wl_get_drvdata(struct wl_dev *dev)
{
return dev->driver_data;
}
s32 wl_cfg80211_read_fw(s8 *buf, u32 size)
{
const struct firmware *fw_entry;
struct wl_priv *wl;
wl = WL_PRIV_GET();
fw_entry = wl->fw->fw_entry;
if (fw_entry->size < wl->fw->ptr + size)
size = fw_entry->size - wl->fw->ptr;
memcpy(buf, &fw_entry->data[wl->fw->ptr], size);
wl->fw->ptr += size;
return size;
}
void wl_cfg80211_release_fw(void)
{
struct wl_priv *wl;
wl = WL_PRIV_GET();
release_firmware(wl->fw->fw_entry);
wl->fw->ptr = 0;
}
void *wl_cfg80211_request_fw(s8 *file_name)
{
struct wl_priv *wl;
const struct firmware *fw_entry = NULL;
s32 err = 0;
WL_INFO("file name : \"%s\"\n", file_name);
wl = WL_PRIV_GET();
if (!test_bit(WL_FW_LOADING_DONE, &wl->fw->status)) {
err = request_firmware(&wl->fw->fw_entry, file_name,
&wl_cfg80211_get_sdio_func()->dev);
if (unlikely(err)) {
WL_ERR("Could not download fw (%d)\n", err);
goto req_fw_out;
}
set_bit(WL_FW_LOADING_DONE, &wl->fw->status);
fw_entry = wl->fw->fw_entry;
if (fw_entry) {
WL_INFO("fw size (%zd), data (%p)\n",
fw_entry->size, fw_entry->data);
}
} else if (!test_bit(WL_NVRAM_LOADING_DONE, &wl->fw->status)) {
err = request_firmware(&wl->fw->fw_entry, file_name,
&wl_cfg80211_get_sdio_func()->dev);
if (unlikely(err)) {
WL_ERR("Could not download nvram (%d)\n", err);
goto req_fw_out;
}
set_bit(WL_NVRAM_LOADING_DONE, &wl->fw->status);
fw_entry = wl->fw->fw_entry;
if (fw_entry) {
WL_INFO("nvram size (%zd), data (%p)\n",
fw_entry->size, fw_entry->data);
}
} else {
WL_INFO("Downloading already done. Nothing to do more\n");
err = -EPERM;
}
req_fw_out:
if (unlikely(err)) {
return NULL;
}
wl->fw->ptr = 0;
return (void *)fw_entry->data;
}
s8 *wl_cfg80211_get_fwname(void)
{
struct wl_priv *wl;
wl = WL_PRIV_GET();
strcpy(wl->fw->fw_name, WL_4329_FW_FILE);
return wl->fw->fw_name;
}
s8 *wl_cfg80211_get_nvramname(void)
{
struct wl_priv *wl;
wl = WL_PRIV_GET();
strcpy(wl->fw->nvram_name, WL_4329_NVRAM_FILE);
return wl->fw->nvram_name;
}
static void wl_set_mpc(struct net_device *ndev, int mpc)
{
s32 err = 0;
struct wl_priv *wl = ndev_to_wl(ndev);
if (test_bit(WL_STATUS_READY, &wl->status)) {
err = wl_dev_intvar_set(ndev, "mpc", mpc);
if (unlikely(err)) {
WL_ERR("fail to set mpc\n");
return;
}
WL_INFO("MPC : %d\n", mpc);
}
}
static int wl_debugfs_add_netdev_params(struct wl_priv *wl)
{
char buf[10+IFNAMSIZ];
struct dentry *fd;
s32 err = 0;
sprintf(buf, "netdev:%s", wl_to_ndev(wl)->name);
wl->debugfsdir = debugfs_create_dir(buf, wl_to_wiphy(wl)->debugfsdir);
fd = debugfs_create_u16("beacon_int", S_IRUGO, wl->debugfsdir,
(u16 *)&wl->profile->beacon_interval);
if (!fd) {
err = -ENOMEM;
goto err_out;
}
fd = debugfs_create_u8("dtim_period", S_IRUGO, wl->debugfsdir,
(u8 *)&wl->profile->dtim_period);
if (!fd) {
err = -ENOMEM;
goto err_out;
}
err_out:
return err;
}
static void wl_debugfs_remove_netdev(struct wl_priv *wl)
{
debugfs_remove_recursive(wl->debugfsdir);
wl->debugfsdir = NULL;
}
