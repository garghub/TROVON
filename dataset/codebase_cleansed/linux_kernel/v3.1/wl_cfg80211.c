static void swap_key_from_BE(struct brcmf_wsec_key *key)
{
key->index = cpu_to_le32(key->index);
key->len = cpu_to_le32(key->len);
key->algo = cpu_to_le32(key->algo);
key->flags = cpu_to_le32(key->flags);
key->rxiv.hi = cpu_to_le32(key->rxiv.hi);
key->rxiv.lo = cpu_to_le16(key->rxiv.lo);
key->iv_initialized = cpu_to_le32(key->iv_initialized);
}
static void swap_key_to_BE(struct brcmf_wsec_key *key)
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
brcmf_dev_ioctl(struct net_device *dev, u32 cmd, void *arg, u32 len)
{
struct ifreq ifr;
struct brcmf_ioctl ioc;
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
brcmf_cfg80211_change_iface(struct wiphy *wiphy, struct net_device *ndev,
enum nl80211_iftype type, u32 *flags,
struct vif_params *params)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
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
cfg_priv->conf->mode = WL_MODE_IBSS;
infra = 0;
break;
case NL80211_IFTYPE_STATION:
cfg_priv->conf->mode = WL_MODE_BSS;
infra = 1;
break;
default:
err = -EINVAL;
goto done;
}
infra = cpu_to_le32(infra);
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_INFRA, &infra, sizeof(infra));
if (unlikely(err)) {
WL_ERR("WLC_SET_INFRA error (%d)\n", err);
err = -EAGAIN;
} else {
wdev = ndev->ieee80211_ptr;
wdev->iftype = type;
}
WL_INFO("IF Type = %s\n",
(cfg_priv->conf->mode == WL_MODE_IBSS) ? "Adhoc" : "Infra");
done:
WL_TRACE("Exit\n");
return err;
}
static void wl_iscan_prep(struct brcmf_scan_params *params,
struct brcmf_ssid *ssid)
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
memcpy(&params->ssid, ssid, sizeof(struct brcmf_ssid));
}
static s32
brcmf_dev_iovar_setbuf(struct net_device *dev, s8 * iovar, void *param,
s32 paramlen, void *bufptr, s32 buflen)
{
s32 iolen;
iolen = brcmu_mkiovar(iovar, param, paramlen, bufptr, buflen);
BUG_ON(!iolen);
return brcmf_dev_ioctl(dev, BRCMF_C_SET_VAR, bufptr, iolen);
}
static s32
brcmf_dev_iovar_getbuf(struct net_device *dev, s8 * iovar, void *param,
s32 paramlen, void *bufptr, s32 buflen)
{
s32 iolen;
iolen = brcmu_mkiovar(iovar, param, paramlen, bufptr, buflen);
BUG_ON(!iolen);
return brcmf_dev_ioctl(dev, BRCMF_C_GET_VAR, bufptr, buflen);
}
static s32
brcmf_run_iscan(struct brcmf_cfg80211_iscan_ctrl *iscan,
struct brcmf_ssid *ssid, u16 action)
{
s32 params_size = (BRCMF_SCAN_PARAMS_FIXED_SIZE +
offsetof(struct brcmf_iscan_params, params));
struct brcmf_iscan_params *params;
s32 err = 0;
if (ssid && ssid->SSID_len)
params_size += sizeof(struct brcmf_ssid);
params = kzalloc(params_size, GFP_KERNEL);
if (unlikely(!params))
return -ENOMEM;
BUG_ON(params_size >= BRCMF_C_IOCTL_SMLEN);
wl_iscan_prep(&params->params, ssid);
params->version = cpu_to_le32(BRCMF_ISCAN_REQ_VERSION);
params->action = cpu_to_le16(action);
params->scan_duration = cpu_to_le16(0);
err = brcmf_dev_iovar_setbuf(iscan->dev, "iscan", params, params_size,
iscan->ioctl_buf, BRCMF_C_IOCTL_SMLEN);
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
static s32 brcmf_do_iscan(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_to_iscan(cfg_priv);
struct net_device *ndev = cfg_to_ndev(cfg_priv);
struct brcmf_ssid ssid;
s32 passive_scan;
s32 err = 0;
memset(&ssid, 0, sizeof(ssid));
iscan->state = WL_ISCAN_STATE_SCANING;
passive_scan = cfg_priv->active_scan ? 0 : 1;
err = brcmf_dev_ioctl(cfg_to_ndev(cfg_priv), BRCMF_C_SET_PASSIVE_SCAN,
&passive_scan, sizeof(passive_scan));
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
brcmf_set_mpc(ndev, 0);
cfg_priv->iscan_kickstart = true;
brcmf_run_iscan(iscan, &ssid, BRCMF_SCAN_ACTION_START);
mod_timer(&iscan->timer, jiffies + iscan->timer_ms * HZ / 1000);
iscan->timer_on = 1;
return err;
}
static s32
__brcmf_cfg80211_scan(struct wiphy *wiphy, struct net_device *ndev,
struct cfg80211_scan_request *request,
struct cfg80211_ssid *this_ssid)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(ndev);
struct cfg80211_ssid *ssids;
struct brcmf_cfg80211_scan_req *sr = cfg_priv->scan_req_int;
s32 passive_scan;
bool iscan_req;
bool spec_scan;
s32 err = 0;
if (unlikely(test_bit(WL_STATUS_SCANNING, &cfg_priv->status))) {
WL_ERR("Scanning already : status (%lu)\n", cfg_priv->status);
return -EAGAIN;
}
if (unlikely(test_bit(WL_STATUS_SCAN_ABORTING, &cfg_priv->status))) {
WL_ERR("Scanning being aborted : status (%lu)\n",
cfg_priv->status);
return -EAGAIN;
}
if (test_bit(WL_STATUS_CONNECTING, &cfg_priv->status)) {
WL_ERR("Connecting : status (%lu)\n",
cfg_priv->status);
return -EAGAIN;
}
iscan_req = false;
spec_scan = false;
if (request) {
ssids = request->ssids;
if (cfg_priv->iscan_on && (!ssids || !ssids->ssid_len))
iscan_req = true;
} else {
ssids = this_ssid;
}
cfg_priv->scan_request = request;
set_bit(WL_STATUS_SCANNING, &cfg_priv->status);
if (iscan_req) {
err = brcmf_do_iscan(cfg_priv);
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
passive_scan = cfg_priv->active_scan ? 0 : 1;
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_PASSIVE_SCAN,
&passive_scan, sizeof(passive_scan));
if (unlikely(err)) {
WL_ERR("WLC_SET_PASSIVE_SCAN error (%d)\n", err);
goto scan_out;
}
brcmf_set_mpc(ndev, 0);
err = brcmf_dev_ioctl(ndev, BRCMF_C_SCAN, &sr->ssid,
sizeof(sr->ssid));
if (err) {
if (err == -EBUSY) {
WL_INFO("system busy : scan for \"%s\" canceled\n",
sr->ssid.SSID);
} else {
WL_ERR("WLC_SCAN error (%d)\n", err);
}
brcmf_set_mpc(ndev, 1);
goto scan_out;
}
}
return 0;
scan_out:
clear_bit(WL_STATUS_SCANNING, &cfg_priv->status);
cfg_priv->scan_request = NULL;
return err;
}
static s32
brcmf_cfg80211_scan(struct wiphy *wiphy, struct net_device *ndev,
struct cfg80211_scan_request *request)
{
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
err = __brcmf_cfg80211_scan(wiphy, ndev, request, NULL);
if (unlikely(err))
WL_ERR("scan error (%d)\n", err);
WL_TRACE("Exit\n");
return err;
}
static s32 brcmf_dev_intvar_set(struct net_device *dev, s8 *name, s32 val)
{
s8 buf[BRCMF_C_IOCTL_SMLEN];
u32 len;
s32 err = 0;
val = cpu_to_le32(val);
len = brcmu_mkiovar(name, (char *)(&val), sizeof(val), buf,
sizeof(buf));
BUG_ON(!len);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_VAR, buf, len);
if (unlikely(err))
WL_ERR("error (%d)\n", err);
return err;
}
static s32
brcmf_dev_intvar_get(struct net_device *dev, s8 *name, s32 *retval)
{
union {
s8 buf[BRCMF_C_IOCTL_SMLEN];
s32 val;
} var;
u32 len;
u32 data_null;
s32 err = 0;
len =
brcmu_mkiovar(name, (char *)(&data_null), 0, (char *)(&var),
sizeof(var.buf));
BUG_ON(!len);
err = brcmf_dev_ioctl(dev, BRCMF_C_GET_VAR, &var, len);
if (unlikely(err))
WL_ERR("error (%d)\n", err);
*retval = le32_to_cpu(var.val);
return err;
}
static s32 brcmf_set_rts(struct net_device *dev, u32 rts_threshold)
{
s32 err = 0;
err = brcmf_dev_intvar_set(dev, "rtsthresh", rts_threshold);
if (unlikely(err))
WL_ERR("Error (%d)\n", err);
return err;
}
static s32 brcmf_set_frag(struct net_device *dev, u32 frag_threshold)
{
s32 err = 0;
err = brcmf_dev_intvar_set(dev, "fragthresh", frag_threshold);
if (unlikely(err))
WL_ERR("Error (%d)\n", err);
return err;
}
static s32 brcmf_set_retry(struct net_device *dev, u32 retry, bool l)
{
s32 err = 0;
u32 cmd = (l ? BRCM_SET_LRL : BRCM_SET_SRL);
retry = cpu_to_le32(retry);
err = brcmf_dev_ioctl(dev, cmd, &retry, sizeof(retry));
if (unlikely(err)) {
WL_ERR("cmd (%d) , error (%d)\n", cmd, err);
return err;
}
return err;
}
static s32 brcmf_cfg80211_set_wiphy_params(struct wiphy *wiphy, u32 changed)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct net_device *ndev = cfg_to_ndev(cfg_priv);
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
if (changed & WIPHY_PARAM_RTS_THRESHOLD &&
(cfg_priv->conf->rts_threshold != wiphy->rts_threshold)) {
cfg_priv->conf->rts_threshold = wiphy->rts_threshold;
err = brcmf_set_rts(ndev, cfg_priv->conf->rts_threshold);
if (!err)
goto done;
}
if (changed & WIPHY_PARAM_FRAG_THRESHOLD &&
(cfg_priv->conf->frag_threshold != wiphy->frag_threshold)) {
cfg_priv->conf->frag_threshold = wiphy->frag_threshold;
err = brcmf_set_frag(ndev, cfg_priv->conf->frag_threshold);
if (!err)
goto done;
}
if (changed & WIPHY_PARAM_RETRY_LONG
&& (cfg_priv->conf->retry_long != wiphy->retry_long)) {
cfg_priv->conf->retry_long = wiphy->retry_long;
err = brcmf_set_retry(ndev, cfg_priv->conf->retry_long, true);
if (!err)
goto done;
}
if (changed & WIPHY_PARAM_RETRY_SHORT
&& (cfg_priv->conf->retry_short != wiphy->retry_short)) {
cfg_priv->conf->retry_short = wiphy->retry_short;
err = brcmf_set_retry(ndev, cfg_priv->conf->retry_short, false);
if (!err)
goto done;
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_join_ibss(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_ibss_params *params)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct brcmf_join_params join_params;
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
set_bit(WL_STATUS_CONNECTING, &cfg_priv->status);
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
err = brcmf_dev_intvar_set(dev, "wsec", wsec);
if (unlikely(err)) {
WL_ERR("wsec failed (%d)\n", err);
goto done;
}
if (params->beacon_interval)
bcnprd = cpu_to_le32(params->beacon_interval);
else
bcnprd = cpu_to_le32(100);
err = brcmf_dev_ioctl(dev, BRCM_SET_BCNPRD, &bcnprd, sizeof(bcnprd));
if (unlikely(err)) {
WL_ERR("WLC_SET_BCNPRD failed (%d)\n", err);
goto done;
}
memset(&join_params, 0, sizeof(struct brcmf_join_params));
join_params.ssid.SSID_len =
(params->ssid_len > 32) ? 32 : params->ssid_len;
memcpy(join_params.ssid.SSID, params->ssid, join_params.ssid.SSID_len);
join_params.ssid.SSID_len = cpu_to_le32(join_params.ssid.SSID_len);
join_params_size = sizeof(join_params.ssid);
brcmf_update_prof(cfg_priv, NULL, &join_params.ssid, WL_PROF_SSID);
if (params->bssid) {
memcpy(join_params.params.bssid, params->bssid, ETH_ALEN);
join_params_size = sizeof(join_params.ssid) +
BRCMF_ASSOC_PARAMS_FIXED_SIZE;
} else {
memcpy(join_params.params.bssid, ether_bcast, ETH_ALEN);
}
brcmf_update_prof(cfg_priv, NULL,
&join_params.params.bssid, WL_PROF_BSSID);
if (params->channel) {
u32 target_channel;
cfg_priv->channel =
ieee80211_frequency_to_channel(
params->channel->center_freq);
if (params->channel_fixed) {
brcmf_ch_to_chanspec(cfg_priv->channel,
&join_params, &join_params_size);
}
target_channel = cpu_to_le32(cfg_priv->channel);
err = brcmf_dev_ioctl(dev, BRCM_SET_CHANNEL,
&target_channel, sizeof(target_channel));
if (unlikely(err)) {
WL_ERR("WLC_SET_CHANNEL failed (%d)\n", err);
goto done;
}
} else
cfg_priv->channel = 0;
cfg_priv->ibss_starter = false;
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_SSID,
&join_params, join_params_size);
if (unlikely(err)) {
WL_ERR("WLC_SET_SSID failed (%d)\n", err);
goto done;
}
done:
if (err)
clear_bit(WL_STATUS_CONNECTING, &cfg_priv->status);
WL_TRACE("Exit\n");
return err;
}
static s32 brcmf_cfg80211_leave_ibss(struct wiphy *wiphy, struct net_device *dev)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
brcmf_link_down(cfg_priv);
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_set_wpa_version(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(dev);
struct brcmf_cfg80211_security *sec;
s32 val = 0;
s32 err = 0;
if (sme->crypto.wpa_versions & NL80211_WPA_VERSION_1)
val = WPA_AUTH_PSK | WPA_AUTH_UNSPECIFIED;
else if (sme->crypto.wpa_versions & NL80211_WPA_VERSION_2)
val = WPA2_AUTH_PSK | WPA2_AUTH_UNSPECIFIED;
else
val = WPA_AUTH_DISABLED;
WL_CONN("setting wpa_auth to 0x%0x\n", val);
err = brcmf_dev_intvar_set(dev, "wpa_auth", val);
if (unlikely(err)) {
WL_ERR("set wpa_auth failed (%d)\n", err);
return err;
}
sec = brcmf_read_prof(cfg_priv, WL_PROF_SEC);
sec->wpa_versions = sme->crypto.wpa_versions;
return err;
}
static s32
brcmf_set_auth_type(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(dev);
struct brcmf_cfg80211_security *sec;
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
err = brcmf_dev_intvar_set(dev, "auth", val);
if (unlikely(err)) {
WL_ERR("set auth failed (%d)\n", err);
return err;
}
sec = brcmf_read_prof(cfg_priv, WL_PROF_SEC);
sec->auth_type = sme->auth_type;
return err;
}
static s32
brcmf_set_set_cipher(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(dev);
struct brcmf_cfg80211_security *sec;
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
err = brcmf_dev_intvar_set(dev, "wsec", pval | gval);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
sec = brcmf_read_prof(cfg_priv, WL_PROF_SEC);
sec->cipher_pairwise = sme->crypto.ciphers_pairwise[0];
sec->cipher_group = sme->crypto.cipher_group;
return err;
}
static s32
brcmf_set_key_mgmt(struct net_device *dev, struct cfg80211_connect_params *sme)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(dev);
struct brcmf_cfg80211_security *sec;
s32 val = 0;
s32 err = 0;
if (sme->crypto.n_akm_suites) {
err = brcmf_dev_intvar_get(dev, "wpa_auth", &val);
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
err = brcmf_dev_intvar_set(dev, "wpa_auth", val);
if (unlikely(err)) {
WL_ERR("could not set wpa_auth (%d)\n", err);
return err;
}
}
sec = brcmf_read_prof(cfg_priv, WL_PROF_SEC);
sec->wpa_auth = sme->crypto.akm_suites[0];
return err;
}
static s32
brcmf_set_set_sharedkey(struct net_device *dev,
struct cfg80211_connect_params *sme)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(dev);
struct brcmf_cfg80211_security *sec;
struct brcmf_wsec_key key;
s32 val;
s32 err = 0;
WL_CONN("key len (%d)\n", sme->key_len);
if (sme->key_len) {
sec = brcmf_read_prof(cfg_priv, WL_PROF_SEC);
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
key.flags = BRCMF_PRIMARY_KEY;
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
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_KEY, &key,
sizeof(key));
if (unlikely(err)) {
WL_ERR("WLC_SET_KEY error (%d)\n", err);
return err;
}
if (sec->auth_type == NL80211_AUTHTYPE_OPEN_SYSTEM) {
WL_CONN("set auth_type to shared key\n");
val = 1;
err = brcmf_dev_intvar_set(dev, "auth", val);
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
brcmf_cfg80211_connect(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_connect_params *sme)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct ieee80211_channel *chan = sme->channel;
struct brcmf_join_params join_params;
size_t join_params_size;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
if (unlikely(!sme->ssid)) {
WL_ERR("Invalid ssid\n");
return -EOPNOTSUPP;
}
set_bit(WL_STATUS_CONNECTING, &cfg_priv->status);
if (chan) {
cfg_priv->channel =
ieee80211_frequency_to_channel(chan->center_freq);
WL_CONN("channel (%d), center_req (%d)\n",
cfg_priv->channel, chan->center_freq);
} else
cfg_priv->channel = 0;
WL_INFO("ie (%p), ie_len (%zd)\n", sme->ie, sme->ie_len);
err = brcmf_set_wpa_version(dev, sme);
if (err) {
WL_ERR("wl_set_wpa_version failed (%d)\n", err);
goto done;
}
err = brcmf_set_auth_type(dev, sme);
if (err) {
WL_ERR("wl_set_auth_type failed (%d)\n", err);
goto done;
}
err = brcmf_set_set_cipher(dev, sme);
if (err) {
WL_ERR("wl_set_set_cipher failed (%d)\n", err);
goto done;
}
err = brcmf_set_key_mgmt(dev, sme);
if (err) {
WL_ERR("wl_set_key_mgmt failed (%d)\n", err);
goto done;
}
err = brcmf_set_set_sharedkey(dev, sme);
if (err) {
WL_ERR("wl_set_set_sharedkey failed (%d)\n", err);
goto done;
}
brcmf_update_prof(cfg_priv, NULL, sme->bssid, WL_PROF_BSSID);
memset(&join_params, 0, sizeof(join_params));
join_params_size = sizeof(join_params.ssid);
join_params.ssid.SSID_len = min(sizeof(join_params.ssid.SSID), sme->ssid_len);
memcpy(&join_params.ssid.SSID, sme->ssid, join_params.ssid.SSID_len);
join_params.ssid.SSID_len = cpu_to_le32(join_params.ssid.SSID_len);
brcmf_update_prof(cfg_priv, NULL, &join_params.ssid, WL_PROF_SSID);
if (sme->bssid)
memcpy(join_params.params.bssid, sme->bssid, ETH_ALEN);
else
memcpy(join_params.params.bssid, ether_bcast, ETH_ALEN);
if (join_params.ssid.SSID_len < IEEE80211_MAX_SSID_LEN) {
WL_CONN("ssid \"%s\", len (%d)\n",
join_params.ssid.SSID, join_params.ssid.SSID_len);
}
brcmf_ch_to_chanspec(cfg_priv->channel,
&join_params, &join_params_size);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_SSID,
&join_params, join_params_size);
if (err)
WL_ERR("WLC_SET_SSID failed (%d)\n", err);
done:
if (err)
clear_bit(WL_STATUS_CONNECTING, &cfg_priv->status);
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_disconnect(struct wiphy *wiphy, struct net_device *dev,
u16 reason_code)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct brcmf_scb_val scbval;
s32 err = 0;
WL_TRACE("Enter. Reason code = %d\n", reason_code);
CHECK_SYS_UP();
clear_bit(WL_STATUS_CONNECTED, &cfg_priv->status);
scbval.val = reason_code;
memcpy(&scbval.ea, brcmf_read_prof(cfg_priv, WL_PROF_BSSID), ETH_ALEN);
scbval.val = cpu_to_le32(scbval.val);
err = brcmf_dev_ioctl(dev, BRCMF_C_DISASSOC, &scbval,
sizeof(struct brcmf_scb_val));
if (unlikely(err))
WL_ERR("error (%d)\n", err);
cfg_priv->link_up = false;
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_set_tx_power(struct wiphy *wiphy,
enum nl80211_tx_power_setting type, s32 dbm)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct net_device *ndev = cfg_to_ndev(cfg_priv);
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
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_RADIO, &disable, sizeof(disable));
if (unlikely(err))
WL_ERR("WLC_SET_RADIO error (%d)\n", err);
if (dbm > 0xffff)
txpwrmw = 0xffff;
else
txpwrmw = (u16) dbm;
err = brcmf_dev_intvar_set(ndev, "qtxpower",
(s32) (brcmu_mw_to_qdbm(txpwrmw)));
if (unlikely(err))
WL_ERR("qtxpower error (%d)\n", err);
cfg_priv->conf->tx_power = dbm;
done:
WL_TRACE("Exit\n");
return err;
}
static s32 brcmf_cfg80211_get_tx_power(struct wiphy *wiphy, s32 *dbm)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct net_device *ndev = cfg_to_ndev(cfg_priv);
s32 txpwrdbm;
u8 result;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
err = brcmf_dev_intvar_get(ndev, "qtxpower", &txpwrdbm);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
goto done;
}
result = (u8) (txpwrdbm & ~WL_TXPWR_OVERRIDE);
*dbm = (s32) brcmu_qdbm_to_mw(result);
done:
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_config_default_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool unicast, bool multicast)
{
u32 index;
s32 wsec;
s32 err = 0;
WL_TRACE("Enter\n");
WL_CONN("key index (%d)\n", key_idx);
CHECK_SYS_UP();
err = brcmf_dev_ioctl(dev, BRCMF_C_GET_WSEC, &wsec, sizeof(wsec));
if (unlikely(err)) {
WL_ERR("WLC_GET_WSEC error (%d)\n", err);
goto done;
}
wsec = le32_to_cpu(wsec);
if (wsec & WEP_ENABLED) {
index = (u32) key_idx;
index = cpu_to_le32(index);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_KEY_PRIMARY, &index,
sizeof(index));
if (unlikely(err))
WL_ERR("error (%d)\n", err);
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_add_keyext(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, const u8 *mac_addr, struct key_params *params)
{
struct brcmf_wsec_key key;
s32 err = 0;
memset(&key, 0, sizeof(key));
key.index = (u32) key_idx;
if (!is_multicast_ether_addr(mac_addr))
memcpy((char *)&key.ea, (void *)mac_addr, ETH_ALEN);
key.len = (u32) params->key_len;
if (key.len == 0) {
swap_key_from_BE(&key);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_KEY, &key, sizeof(key));
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
brcmf_netdev_wait_pend8021x(dev);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_KEY, &key, sizeof(key));
if (unlikely(err)) {
WL_ERR("WLC_SET_KEY error (%d)\n", err);
return err;
}
}
return err;
}
static s32
brcmf_cfg80211_add_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool pairwise, const u8 *mac_addr,
struct key_params *params)
{
struct brcmf_wsec_key key;
s32 val;
s32 wsec;
s32 err = 0;
u8 keybuf[8];
WL_TRACE("Enter\n");
WL_CONN("key index (%d)\n", key_idx);
CHECK_SYS_UP();
if (mac_addr) {
WL_TRACE("Exit");
return brcmf_add_keyext(wiphy, dev, key_idx, mac_addr, params);
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
key.flags = BRCMF_PRIMARY_KEY;
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
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_KEY, &key, sizeof(key));
if (unlikely(err)) {
WL_ERR("WLC_SET_KEY error (%d)\n", err);
goto done;
}
val = WEP_ENABLED;
err = brcmf_dev_intvar_get(dev, "wsec", &wsec);
if (unlikely(err)) {
WL_ERR("get wsec error (%d)\n", err);
goto done;
}
wsec &= ~(WEP_ENABLED);
wsec |= val;
err = brcmf_dev_intvar_set(dev, "wsec", wsec);
if (unlikely(err)) {
WL_ERR("set wsec error (%d)\n", err);
goto done;
}
val = 1;
val = cpu_to_le32(val);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_AUTH, &val, sizeof(val));
if (unlikely(err))
WL_ERR("WLC_SET_AUTH error (%d)\n", err);
done:
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_del_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool pairwise, const u8 *mac_addr)
{
struct brcmf_wsec_key key;
s32 err = 0;
s32 val;
s32 wsec;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
memset(&key, 0, sizeof(key));
key.index = (u32) key_idx;
key.flags = BRCMF_PRIMARY_KEY;
key.algo = CRYPTO_ALGO_OFF;
WL_CONN("key index (%d)\n", key_idx);
swap_key_from_BE(&key);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_KEY, &key, sizeof(key));
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
err = brcmf_dev_intvar_get(dev, "wsec", &wsec);
if (unlikely(err)) {
WL_ERR("get wsec error (%d)\n", err);
err = -EAGAIN;
goto done;
}
wsec &= ~(WEP_ENABLED);
wsec |= val;
err = brcmf_dev_intvar_set(dev, "wsec", wsec);
if (unlikely(err)) {
WL_ERR("set wsec error (%d)\n", err);
err = -EAGAIN;
goto done;
}
val = 0;
val = cpu_to_le32(val);
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_AUTH, &val, sizeof(val));
if (unlikely(err)) {
WL_ERR("WLC_SET_AUTH error (%d)\n", err);
err = -EAGAIN;
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_get_key(struct wiphy *wiphy, struct net_device *dev,
u8 key_idx, bool pairwise, const u8 *mac_addr, void *cookie,
void (*callback) (void *cookie, struct key_params * params))
{
struct key_params params;
struct brcmf_wsec_key key;
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct brcmf_cfg80211_security *sec;
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
err = brcmf_dev_ioctl(dev, BRCMF_C_GET_WSEC, &wsec, sizeof(wsec));
if (unlikely(err)) {
WL_ERR("WLC_GET_WSEC error (%d)\n", err);
err = -EAGAIN;
goto done;
}
wsec = le32_to_cpu(wsec);
switch (wsec) {
case WEP_ENABLED:
sec = brcmf_read_prof(cfg_priv, WL_PROF_SEC);
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
brcmf_cfg80211_config_default_mgmt_key(struct wiphy *wiphy,
struct net_device *dev, u8 key_idx)
{
WL_INFO("Not supported\n");
CHECK_SYS_UP();
return -EOPNOTSUPP;
}
static s32
brcmf_cfg80211_get_station(struct wiphy *wiphy, struct net_device *dev,
u8 *mac, struct station_info *sinfo)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct brcmf_scb_val scb_val;
int rssi;
s32 rate;
s32 err = 0;
u8 *bssid = brcmf_read_prof(cfg_priv, WL_PROF_BSSID);
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
err = brcmf_dev_ioctl(dev, BRCMF_C_GET_RATE, &rate, sizeof(rate));
if (err) {
WL_ERR("Could not get rate (%d)\n", err);
} else {
rate = le32_to_cpu(rate);
sinfo->filled |= STATION_INFO_TX_BITRATE;
sinfo->txrate.legacy = rate * 5;
WL_CONN("Rate %d Mbps\n", rate / 2);
}
if (test_bit(WL_STATUS_CONNECTED, &cfg_priv->status)) {
scb_val.val = 0;
err = brcmf_dev_ioctl(dev, BRCMF_C_GET_RSSI, &scb_val,
sizeof(struct brcmf_scb_val));
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
brcmf_cfg80211_set_power_mgmt(struct wiphy *wiphy, struct net_device *dev,
bool enabled, s32 timeout)
{
s32 pm;
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
pm = enabled ? PM_FAST : PM_OFF;
pm = cpu_to_le32(pm);
WL_INFO("power save %s\n", (pm ? "enabled" : "disabled"));
err = brcmf_dev_ioctl(dev, BRCMF_C_SET_PM, &pm, sizeof(pm));
if (unlikely(err)) {
if (err == -ENODEV)
WL_ERR("net_device is not ready yet\n");
else
WL_ERR("error (%d)\n", err);
}
WL_TRACE("Exit\n");
return err;
}
static __used u32 brcmf_find_msb(u16 bit16)
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
brcmf_cfg80211_set_bitrate_mask(struct wiphy *wiphy, struct net_device *dev,
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
err = brcmf_dev_ioctl(dev, BRCM_GET_CURR_RATESET, &rateset,
sizeof(rateset));
if (unlikely(err)) {
WL_ERR("could not get current rateset (%d)\n", err);
goto done;
}
rateset.count = le32_to_cpu(rateset.count);
legacy = brcmf_find_msb(mask->control[IEEE80211_BAND_2GHZ].legacy);
if (!legacy)
legacy = brcmf_find_msb(mask->control[IEEE80211_BAND_5GHZ].legacy);
val = wl_g_rates[legacy - 1].bitrate * 100000;
if (val < rateset.count)
rate = rateset.rates[val] & 0x7f;
else
rate = val / 500000;
WL_CONN("rate %d mbps\n", rate / 2);
err_bg = brcmf_dev_intvar_set(dev, "bg_rate", rate);
err_a = brcmf_dev_intvar_set(dev, "a_rate", rate);
if (unlikely(err_bg && err_a)) {
WL_ERR("could not set fixed rate (%d) (%d)\n", err_bg, err_a);
err = err_bg | err_a;
}
done:
WL_TRACE("Exit\n");
return err;
}
static s32 brcmf_cfg80211_resume(struct wiphy *wiphy)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
WL_TRACE("Enter\n");
#if defined(CONFIG_PM_SLEEP)
atomic_set(&brcmf_mmc_suspend, false);
#endif
if (test_bit(WL_STATUS_READY, &cfg_priv->status))
brcmf_invoke_iscan(wiphy_to_cfg(wiphy));
WL_TRACE("Exit\n");
return 0;
}
static s32 brcmf_cfg80211_suspend(struct wiphy *wiphy,
struct cfg80211_wowlan *wow)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct net_device *ndev = cfg_to_ndev(cfg_priv);
WL_TRACE("Enter\n");
if ((test_bit(WL_STATUS_CONNECTED, &cfg_priv->status) ||
test_bit(WL_STATUS_CONNECTING, &cfg_priv->status)) &&
test_bit(WL_STATUS_READY, &cfg_priv->status)) {
WL_INFO("Disassociating from AP"
" while entering suspend state\n");
brcmf_link_down(cfg_priv);
rtnl_unlock();
brcmf_delay(500);
rtnl_lock();
}
set_bit(WL_STATUS_SCAN_ABORTING, &cfg_priv->status);
if (test_bit(WL_STATUS_READY, &cfg_priv->status))
brcmf_term_iscan(cfg_priv);
if (cfg_priv->scan_request) {
WL_INFO("Terminating scan in progress\n");
cfg80211_scan_done(cfg_priv->scan_request, true);
cfg_priv->scan_request = NULL;
}
clear_bit(WL_STATUS_SCANNING, &cfg_priv->status);
clear_bit(WL_STATUS_SCAN_ABORTING, &cfg_priv->status);
if (test_bit(WL_STATUS_READY, &cfg_priv->status)) {
WL_INFO("Enable MPC\n");
brcmf_set_mpc(ndev, 1);
}
#if defined(CONFIG_PM_SLEEP)
atomic_set(&brcmf_mmc_suspend, true);
#endif
WL_TRACE("Exit\n");
return 0;
}
static __used s32
brcmf_update_pmklist(struct net_device *dev,
struct brcmf_cfg80211_pmk_list *pmk_list, s32 err)
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
brcmf_dev_bufvar_set(dev, "pmkid_info", (char *)pmk_list,
sizeof(*pmk_list));
return err;
}
static s32
brcmf_cfg80211_set_pmksa(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_pmksa *pmksa)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
struct _pmkid_list *pmkids = &cfg_priv->pmk_list->pmkids;
s32 err = 0;
int i;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
for (i = 0; i < pmkids->npmkid; i++)
if (!memcmp(pmksa->bssid, pmkids->pmkid[i].BSSID, ETH_ALEN))
break;
if (i < WL_NUM_PMKIDS_MAX) {
memcpy(pmkids->pmkid[i].BSSID, pmksa->bssid, ETH_ALEN);
memcpy(pmkids->pmkid[i].PMKID, pmksa->pmkid, WLAN_PMKID_LEN);
if (i == pmkids->npmkid)
pmkids->npmkid++;
} else
err = -EINVAL;
WL_CONN("set_pmksa,IW_PMKSA_ADD - PMKID: %pM =\n",
pmkids->pmkid[pmkids->npmkid].BSSID);
for (i = 0; i < WLAN_PMKID_LEN; i++)
WL_CONN("%02x\n", pmkids->pmkid[pmkids->npmkid].PMKID[i]);
err = brcmf_update_pmklist(dev, cfg_priv->pmk_list, err);
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_del_pmksa(struct wiphy *wiphy, struct net_device *dev,
struct cfg80211_pmksa *pmksa)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
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
for (i = 0; i < cfg_priv->pmk_list->pmkids.npmkid; i++)
if (!memcmp
(pmksa->bssid, &cfg_priv->pmk_list->pmkids.pmkid[i].BSSID,
ETH_ALEN))
break;
if ((cfg_priv->pmk_list->pmkids.npmkid > 0)
&& (i < cfg_priv->pmk_list->pmkids.npmkid)) {
memset(&cfg_priv->pmk_list->pmkids.pmkid[i], 0,
sizeof(pmkid_t));
for (; i < (cfg_priv->pmk_list->pmkids.npmkid - 1); i++) {
memcpy(&cfg_priv->pmk_list->pmkids.pmkid[i].BSSID,
&cfg_priv->pmk_list->pmkids.pmkid[i + 1].BSSID,
ETH_ALEN);
memcpy(&cfg_priv->pmk_list->pmkids.pmkid[i].PMKID,
&cfg_priv->pmk_list->pmkids.pmkid[i + 1].PMKID,
WLAN_PMKID_LEN);
}
cfg_priv->pmk_list->pmkids.npmkid--;
} else
err = -EINVAL;
err = brcmf_update_pmklist(dev, cfg_priv->pmk_list, err);
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_cfg80211_flush_pmksa(struct wiphy *wiphy, struct net_device *dev)
{
struct brcmf_cfg80211_priv *cfg_priv = wiphy_to_cfg(wiphy);
s32 err = 0;
WL_TRACE("Enter\n");
CHECK_SYS_UP();
memset(cfg_priv->pmk_list, 0, sizeof(*cfg_priv->pmk_list));
err = brcmf_update_pmklist(dev, cfg_priv->pmk_list, err);
WL_TRACE("Exit\n");
return err;
}
static s32 brcmf_mode_to_nl80211_iftype(s32 mode)
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
static struct wireless_dev *brcmf_alloc_wdev(s32 sizeof_iface,
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
wiphy_new(&wl_cfg80211_ops,
sizeof(struct brcmf_cfg80211_priv) + sizeof_iface);
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
static void brcmf_free_wdev(struct brcmf_cfg80211_priv *cfg_priv)
{
struct wireless_dev *wdev = cfg_to_wdev(cfg_priv);
if (unlikely(!wdev)) {
WL_ERR("wdev is invalid\n");
return;
}
wiphy_unregister(wdev->wiphy);
wiphy_free(wdev->wiphy);
kfree(wdev);
cfg_to_wdev(cfg_priv) = NULL;
}
static s32 brcmf_inform_bss(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_scan_results *bss_list;
struct brcmf_bss_info *bi = NULL;
s32 err = 0;
int i;
bss_list = cfg_priv->bss_list;
if (unlikely(bss_list->version != BRCMF_BSS_INFO_VERSION)) {
WL_ERR("Version %d != WL_BSS_INFO_VERSION\n",
bss_list->version);
return -EOPNOTSUPP;
}
WL_SCAN("scanned AP count (%d)\n", bss_list->count);
bi = next_bss(bss_list, bi);
for_each_bss(bss_list, bi, i) {
err = brcmf_inform_single_bss(cfg_priv, bi);
if (unlikely(err))
break;
}
return err;
}
static s32 brcmf_inform_single_bss(struct brcmf_cfg80211_priv *cfg_priv,
struct brcmf_bss_info *bi)
{
struct wiphy *wiphy = cfg_to_wiphy(cfg_priv);
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
static s32 wl_inform_ibss(struct brcmf_cfg80211_priv *cfg_priv,
struct net_device *dev, const u8 *bssid)
{
struct wiphy *wiphy = cfg_to_wiphy(cfg_priv);
struct ieee80211_channel *notify_channel;
struct brcmf_bss_info *bi = NULL;
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
err = brcmf_dev_ioctl(dev, BRCMF_C_GET_BSS_INFO, buf, WL_BSS_INFO_MAX);
if (unlikely(err)) {
WL_ERR("WLC_GET_BSS_INFO failed: %d\n", err);
goto CleanUp;
}
bi = (struct brcmf_bss_info *)(buf + 4);
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
static bool brcmf_is_linkup(struct brcmf_cfg80211_priv *cfg_priv,
const struct brcmf_event_msg *e)
{
u32 event = be32_to_cpu(e->event_type);
u32 status = be32_to_cpu(e->status);
if (event == BRCMF_E_SET_SSID && status == BRCMF_E_STATUS_SUCCESS) {
WL_CONN("Processing set ssid\n");
cfg_priv->link_up = true;
return true;
}
return false;
}
static bool brcmf_is_linkdown(struct brcmf_cfg80211_priv *cfg_priv,
const struct brcmf_event_msg *e)
{
u32 event = be32_to_cpu(e->event_type);
u16 flags = be16_to_cpu(e->flags);
if (event == BRCMF_E_LINK && (!(flags & BRCMF_EVENT_MSG_LINK))) {
WL_CONN("Processing link down\n");
return true;
}
return false;
}
static bool brcmf_is_nonetwork(struct brcmf_cfg80211_priv *cfg_priv,
const struct brcmf_event_msg *e)
{
u32 event = be32_to_cpu(e->event_type);
u32 status = be32_to_cpu(e->status);
if (event == BRCMF_E_LINK && status == BRCMF_E_STATUS_NO_NETWORKS) {
WL_CONN("Processing Link %s & no network found\n",
be16_to_cpu(e->flags) & BRCMF_EVENT_MSG_LINK ?
"up" : "down");
return true;
}
if (event == BRCMF_E_SET_SSID && status != BRCMF_E_STATUS_SUCCESS) {
WL_CONN("Processing connecting & no network found\n");
return true;
}
return false;
}
static s32
brcmf_notify_connect_status(struct brcmf_cfg80211_priv *cfg_priv,
struct net_device *ndev,
const struct brcmf_event_msg *e, void *data)
{
s32 err = 0;
if (brcmf_is_linkup(cfg_priv, e)) {
WL_CONN("Linkup\n");
if (brcmf_is_ibssmode(cfg_priv)) {
brcmf_update_prof(cfg_priv, NULL, (void *)e->addr,
WL_PROF_BSSID);
wl_inform_ibss(cfg_priv, ndev, e->addr);
cfg80211_ibss_joined(ndev, e->addr, GFP_KERNEL);
clear_bit(WL_STATUS_CONNECTING, &cfg_priv->status);
set_bit(WL_STATUS_CONNECTED, &cfg_priv->status);
} else
brcmf_bss_connect_done(cfg_priv, ndev, e, data, true);
} else if (brcmf_is_linkdown(cfg_priv, e)) {
WL_CONN("Linkdown\n");
if (brcmf_is_ibssmode(cfg_priv)) {
clear_bit(WL_STATUS_CONNECTING, &cfg_priv->status);
if (test_and_clear_bit(WL_STATUS_CONNECTED,
&cfg_priv->status))
brcmf_link_down(cfg_priv);
} else {
brcmf_bss_connect_done(cfg_priv, ndev, e, data, false);
if (test_and_clear_bit(WL_STATUS_CONNECTED,
&cfg_priv->status)) {
cfg80211_disconnected(ndev, 0, NULL, 0,
GFP_KERNEL);
brcmf_link_down(cfg_priv);
}
}
brcmf_init_prof(cfg_priv->profile);
} else if (brcmf_is_nonetwork(cfg_priv, e)) {
if (brcmf_is_ibssmode(cfg_priv))
clear_bit(WL_STATUS_CONNECTING, &cfg_priv->status);
else
brcmf_bss_connect_done(cfg_priv, ndev, e, data, false);
}
return err;
}
static s32
brcmf_notify_roaming_status(struct brcmf_cfg80211_priv *cfg_priv,
struct net_device *ndev,
const struct brcmf_event_msg *e, void *data)
{
s32 err = 0;
u32 event = be32_to_cpu(e->event_type);
u32 status = be32_to_cpu(e->status);
if (event == BRCMF_E_ROAM && status == BRCMF_E_STATUS_SUCCESS) {
if (test_bit(WL_STATUS_CONNECTED, &cfg_priv->status))
brcmf_bss_roaming_done(cfg_priv, ndev, e, data);
else
brcmf_bss_connect_done(cfg_priv, ndev, e, data, true);
}
return err;
}
static __used s32
brcmf_dev_bufvar_set(struct net_device *dev, s8 *name, s8 *buf, s32 len)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(dev);
u32 buflen;
buflen = brcmu_mkiovar(name, buf, len, cfg_priv->ioctl_buf,
WL_IOCTL_LEN_MAX);
BUG_ON(!buflen);
return brcmf_dev_ioctl(dev, BRCMF_C_SET_VAR, cfg_priv->ioctl_buf,
buflen);
}
static s32
brcmf_dev_bufvar_get(struct net_device *dev, s8 *name, s8 *buf,
s32 buf_len)
{
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(dev);
u32 len;
s32 err = 0;
len = brcmu_mkiovar(name, NULL, 0, cfg_priv->ioctl_buf,
WL_IOCTL_LEN_MAX);
BUG_ON(!len);
err = brcmf_dev_ioctl(dev, BRCMF_C_GET_VAR, (void *)cfg_priv->ioctl_buf,
WL_IOCTL_LEN_MAX);
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
memcpy(buf, cfg_priv->ioctl_buf, buf_len);
return err;
}
static s32 brcmf_get_assoc_ies(struct brcmf_cfg80211_priv *cfg_priv)
{
struct net_device *ndev = cfg_to_ndev(cfg_priv);
struct brcmf_cfg80211_assoc_ielen *assoc_info;
struct brcmf_cfg80211_connect_info *conn_info = cfg_to_conn(cfg_priv);
u32 req_len;
u32 resp_len;
s32 err = 0;
brcmf_clear_assoc_ies(cfg_priv);
err = brcmf_dev_bufvar_get(ndev, "assoc_info", cfg_priv->extra_buf,
WL_ASSOC_INFO_MAX);
if (unlikely(err)) {
WL_ERR("could not get assoc info (%d)\n", err);
return err;
}
assoc_info = (struct brcmf_cfg80211_assoc_ielen *)cfg_priv->extra_buf;
req_len = assoc_info->req_len;
resp_len = assoc_info->resp_len;
if (req_len) {
err = brcmf_dev_bufvar_get(ndev, "assoc_req_ies",
cfg_priv->extra_buf,
WL_ASSOC_INFO_MAX);
if (unlikely(err)) {
WL_ERR("could not get assoc req (%d)\n", err);
return err;
}
conn_info->req_ie_len = req_len;
conn_info->req_ie =
kmemdup(cfg_priv->extra_buf, conn_info->req_ie_len,
GFP_KERNEL);
} else {
conn_info->req_ie_len = 0;
conn_info->req_ie = NULL;
}
if (resp_len) {
err = brcmf_dev_bufvar_get(ndev, "assoc_resp_ies",
cfg_priv->extra_buf,
WL_ASSOC_INFO_MAX);
if (unlikely(err)) {
WL_ERR("could not get assoc resp (%d)\n", err);
return err;
}
conn_info->resp_ie_len = resp_len;
conn_info->resp_ie =
kmemdup(cfg_priv->extra_buf, conn_info->resp_ie_len,
GFP_KERNEL);
} else {
conn_info->resp_ie_len = 0;
conn_info->resp_ie = NULL;
}
WL_CONN("req len (%d) resp len (%d)\n",
conn_info->req_ie_len, conn_info->resp_ie_len);
return err;
}
static void brcmf_clear_assoc_ies(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_connect_info *conn_info = cfg_to_conn(cfg_priv);
kfree(conn_info->req_ie);
conn_info->req_ie = NULL;
conn_info->req_ie_len = 0;
kfree(conn_info->resp_ie);
conn_info->resp_ie = NULL;
conn_info->resp_ie_len = 0;
}
static void brcmf_ch_to_chanspec(int ch, struct brcmf_join_params *join_params,
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
*join_params_size += BRCMF_ASSOC_PARAMS_FIXED_SIZE +
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
static s32 brcmf_update_bss_info(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_bss_info *bi;
struct brcmf_ssid *ssid;
struct brcmu_tlv *tim;
u16 beacon_interval;
u8 dtim_period;
size_t ie_len;
u8 *ie;
s32 err = 0;
WL_TRACE("Enter\n");
if (brcmf_is_ibssmode(cfg_priv))
return err;
ssid = (struct brcmf_ssid *)brcmf_read_prof(cfg_priv, WL_PROF_SSID);
*(u32 *)cfg_priv->extra_buf = cpu_to_le32(WL_EXTRA_BUF_MAX);
err = brcmf_dev_ioctl(cfg_to_ndev(cfg_priv), BRCMF_C_GET_BSS_INFO,
cfg_priv->extra_buf, WL_EXTRA_BUF_MAX);
if (unlikely(err)) {
WL_ERR("Could not get bss info %d\n", err);
goto update_bss_info_out;
}
bi = (struct brcmf_bss_info *)(cfg_priv->extra_buf + 4);
err = brcmf_inform_single_bss(cfg_priv, bi);
if (unlikely(err))
goto update_bss_info_out;
ie = ((u8 *)bi) + bi->ie_offset;
ie_len = bi->ie_length;
beacon_interval = cpu_to_le16(bi->beacon_period);
tim = brcmu_parse_tlvs(ie, ie_len, WLAN_EID_TIM);
if (tim)
dtim_period = tim->data[1];
else {
u32 var;
err = brcmf_dev_intvar_get(cfg_to_ndev(cfg_priv),
"dtim_assoc", &var);
if (unlikely(err)) {
WL_ERR("wl dtim_assoc failed (%d)\n", err);
goto update_bss_info_out;
}
dtim_period = (u8)var;
}
brcmf_update_prof(cfg_priv, NULL, &beacon_interval, WL_PROF_BEACONINT);
brcmf_update_prof(cfg_priv, NULL, &dtim_period, WL_PROF_DTIMPERIOD);
update_bss_info_out:
WL_TRACE("Exit");
return err;
}
static s32
brcmf_bss_roaming_done(struct brcmf_cfg80211_priv *cfg_priv,
struct net_device *ndev,
const struct brcmf_event_msg *e, void *data)
{
struct brcmf_cfg80211_connect_info *conn_info = cfg_to_conn(cfg_priv);
s32 err = 0;
WL_TRACE("Enter\n");
brcmf_get_assoc_ies(cfg_priv);
brcmf_update_prof(cfg_priv, NULL, &e->addr, WL_PROF_BSSID);
brcmf_update_bss_info(cfg_priv);
cfg80211_roamed(ndev, NULL,
(u8 *)brcmf_read_prof(cfg_priv, WL_PROF_BSSID),
conn_info->req_ie, conn_info->req_ie_len,
conn_info->resp_ie, conn_info->resp_ie_len, GFP_KERNEL);
WL_CONN("Report roaming result\n");
set_bit(WL_STATUS_CONNECTED, &cfg_priv->status);
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_bss_connect_done(struct brcmf_cfg80211_priv *cfg_priv,
struct net_device *ndev, const struct brcmf_event_msg *e,
void *data, bool completed)
{
struct brcmf_cfg80211_connect_info *conn_info = cfg_to_conn(cfg_priv);
s32 err = 0;
WL_TRACE("Enter\n");
if (test_and_clear_bit(WL_STATUS_CONNECTING, &cfg_priv->status)) {
if (completed) {
brcmf_get_assoc_ies(cfg_priv);
brcmf_update_prof(cfg_priv, NULL, &e->addr,
WL_PROF_BSSID);
brcmf_update_bss_info(cfg_priv);
}
cfg80211_connect_result(ndev,
(u8 *)brcmf_read_prof(cfg_priv,
WL_PROF_BSSID),
conn_info->req_ie,
conn_info->req_ie_len,
conn_info->resp_ie,
conn_info->resp_ie_len,
completed ? WLAN_STATUS_SUCCESS :
WLAN_STATUS_AUTH_TIMEOUT,
GFP_KERNEL);
if (completed)
set_bit(WL_STATUS_CONNECTED, &cfg_priv->status);
WL_CONN("Report connect result - connection %s\n",
completed ? "succeeded" : "failed");
}
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_notify_mic_status(struct brcmf_cfg80211_priv *cfg_priv,
struct net_device *ndev,
const struct brcmf_event_msg *e, void *data)
{
u16 flags = be16_to_cpu(e->flags);
enum nl80211_key_type key_type;
rtnl_lock();
if (flags & BRCMF_EVENT_MSG_GROUP)
key_type = NL80211_KEYTYPE_GROUP;
else
key_type = NL80211_KEYTYPE_PAIRWISE;
cfg80211_michael_mic_failure(ndev, (u8 *)&e->addr, key_type, -1,
NULL, GFP_KERNEL);
rtnl_unlock();
return 0;
}
static s32
brcmf_notify_scan_status(struct brcmf_cfg80211_priv *cfg_priv,
struct net_device *ndev,
const struct brcmf_event_msg *e, void *data)
{
struct brcmf_channel_info channel_inform;
struct brcmf_scan_results *bss_list;
u32 len = WL_SCAN_BUF_MAX;
s32 err = 0;
bool scan_abort = false;
WL_TRACE("Enter\n");
if (cfg_priv->iscan_on && cfg_priv->iscan_kickstart) {
WL_TRACE("Exit\n");
return brcmf_wakeup_iscan(cfg_to_iscan(cfg_priv));
}
if (unlikely(!test_and_clear_bit(WL_STATUS_SCANNING,
&cfg_priv->status))) {
WL_ERR("Scan complete while device not scanning\n");
scan_abort = true;
err = -EINVAL;
goto scan_done_out;
}
err = brcmf_dev_ioctl(ndev, BRCMF_C_GET_CHANNEL, &channel_inform,
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
cfg_priv->bss_list = cfg_priv->scan_results;
bss_list = cfg_priv->bss_list;
memset(bss_list, 0, len);
bss_list->buflen = cpu_to_le32(len);
err = brcmf_dev_ioctl(ndev, BRCMF_C_SCAN_RESULTS, bss_list, len);
if (unlikely(err)) {
WL_ERR("%s Scan_results error (%d)\n", ndev->name, err);
err = -EINVAL;
scan_abort = true;
goto scan_done_out;
}
bss_list->buflen = le32_to_cpu(bss_list->buflen);
bss_list->version = le32_to_cpu(bss_list->version);
bss_list->count = le32_to_cpu(bss_list->count);
err = brcmf_inform_bss(cfg_priv);
if (err) {
scan_abort = true;
goto scan_done_out;
}
scan_done_out:
if (cfg_priv->scan_request) {
WL_SCAN("calling cfg80211_scan_done\n");
cfg80211_scan_done(cfg_priv->scan_request, scan_abort);
brcmf_set_mpc(ndev, 1);
cfg_priv->scan_request = NULL;
}
WL_TRACE("Exit\n");
return err;
}
static void brcmf_init_conf(struct brcmf_cfg80211_conf *conf)
{
conf->mode = (u32)-1;
conf->frag_threshold = (u32)-1;
conf->rts_threshold = (u32)-1;
conf->retry_short = (u32)-1;
conf->retry_long = (u32)-1;
conf->tx_power = -1;
}
static void brcmf_init_prof(struct brcmf_cfg80211_profile *prof)
{
memset(prof, 0, sizeof(*prof));
}
static void brcmf_init_eloop_handler(struct brcmf_cfg80211_event_loop *el)
{
memset(el, 0, sizeof(*el));
el->handler[BRCMF_E_SCAN_COMPLETE] = brcmf_notify_scan_status;
el->handler[BRCMF_E_LINK] = brcmf_notify_connect_status;
el->handler[BRCMF_E_ROAM] = brcmf_notify_roaming_status;
el->handler[BRCMF_E_MIC_ERROR] = brcmf_notify_mic_status;
el->handler[BRCMF_E_SET_SSID] = brcmf_notify_connect_status;
}
static s32 brcmf_init_priv_mem(struct brcmf_cfg80211_priv *cfg_priv)
{
cfg_priv->scan_results = kzalloc(WL_SCAN_BUF_MAX, GFP_KERNEL);
if (unlikely(!cfg_priv->scan_results)) {
WL_ERR("Scan results alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->conf = kzalloc(sizeof(*cfg_priv->conf), GFP_KERNEL);
if (unlikely(!cfg_priv->conf)) {
WL_ERR("wl_conf alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->profile = kzalloc(sizeof(*cfg_priv->profile), GFP_KERNEL);
if (unlikely(!cfg_priv->profile)) {
WL_ERR("wl_profile alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->bss_info = kzalloc(WL_BSS_INFO_MAX, GFP_KERNEL);
if (unlikely(!cfg_priv->bss_info)) {
WL_ERR("Bss information alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->scan_req_int = kzalloc(sizeof(*cfg_priv->scan_req_int),
GFP_KERNEL);
if (unlikely(!cfg_priv->scan_req_int)) {
WL_ERR("Scan req alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->ioctl_buf = kzalloc(WL_IOCTL_LEN_MAX, GFP_KERNEL);
if (unlikely(!cfg_priv->ioctl_buf)) {
WL_ERR("Ioctl buf alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->extra_buf = kzalloc(WL_EXTRA_BUF_MAX, GFP_KERNEL);
if (unlikely(!cfg_priv->extra_buf)) {
WL_ERR("Extra buf alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->iscan = kzalloc(sizeof(*cfg_priv->iscan), GFP_KERNEL);
if (unlikely(!cfg_priv->iscan)) {
WL_ERR("Iscan buf alloc failed\n");
goto init_priv_mem_out;
}
cfg_priv->pmk_list = kzalloc(sizeof(*cfg_priv->pmk_list), GFP_KERNEL);
if (unlikely(!cfg_priv->pmk_list)) {
WL_ERR("pmk list alloc failed\n");
goto init_priv_mem_out;
}
return 0;
init_priv_mem_out:
brcmf_deinit_priv_mem(cfg_priv);
return -ENOMEM;
}
static void brcmf_deinit_priv_mem(struct brcmf_cfg80211_priv *cfg_priv)
{
kfree(cfg_priv->scan_results);
cfg_priv->scan_results = NULL;
kfree(cfg_priv->bss_info);
cfg_priv->bss_info = NULL;
kfree(cfg_priv->conf);
cfg_priv->conf = NULL;
kfree(cfg_priv->profile);
cfg_priv->profile = NULL;
kfree(cfg_priv->scan_req_int);
cfg_priv->scan_req_int = NULL;
kfree(cfg_priv->ioctl_buf);
cfg_priv->ioctl_buf = NULL;
kfree(cfg_priv->extra_buf);
cfg_priv->extra_buf = NULL;
kfree(cfg_priv->iscan);
cfg_priv->iscan = NULL;
kfree(cfg_priv->pmk_list);
cfg_priv->pmk_list = NULL;
}
static s32 brcmf_create_event_handler(struct brcmf_cfg80211_priv *cfg_priv)
{
sema_init(&cfg_priv->event_sync, 0);
cfg_priv->event_tsk = kthread_run(brcmf_event_handler, cfg_priv,
"wl_event_handler");
if (IS_ERR(cfg_priv->event_tsk)) {
cfg_priv->event_tsk = NULL;
WL_ERR("failed to create event thread\n");
return -ENOMEM;
}
return 0;
}
static void brcmf_destroy_event_handler(struct brcmf_cfg80211_priv *cfg_priv)
{
if (cfg_priv->event_tsk) {
send_sig(SIGTERM, cfg_priv->event_tsk, 1);
kthread_stop(cfg_priv->event_tsk);
cfg_priv->event_tsk = NULL;
}
}
static void brcmf_term_iscan(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_to_iscan(cfg_priv);
if (cfg_priv->iscan_on && iscan->tsk) {
iscan->state = WL_ISCAN_STATE_IDLE;
send_sig(SIGTERM, iscan->tsk, 1);
kthread_stop(iscan->tsk);
iscan->tsk = NULL;
}
}
static void brcmf_notify_iscan_complete(struct brcmf_cfg80211_iscan_ctrl *iscan,
bool aborted)
{
struct brcmf_cfg80211_priv *cfg_priv = iscan_to_cfg(iscan);
struct net_device *ndev = cfg_to_ndev(cfg_priv);
if (unlikely(!test_and_clear_bit(WL_STATUS_SCANNING,
&cfg_priv->status))) {
WL_ERR("Scan complete while device not scanning\n");
return;
}
if (likely(cfg_priv->scan_request)) {
WL_SCAN("ISCAN Completed scan: %s\n",
aborted ? "Aborted" : "Done");
cfg80211_scan_done(cfg_priv->scan_request, aborted);
brcmf_set_mpc(ndev, 1);
cfg_priv->scan_request = NULL;
}
cfg_priv->iscan_kickstart = false;
}
static s32 brcmf_wakeup_iscan(struct brcmf_cfg80211_iscan_ctrl *iscan)
{
if (likely(iscan->state != WL_ISCAN_STATE_IDLE)) {
WL_SCAN("wake up iscan\n");
up(&iscan->sync);
return 0;
}
return -EIO;
}
static s32
brcmf_get_iscan_results(struct brcmf_cfg80211_iscan_ctrl *iscan, u32 *status,
struct brcmf_scan_results **bss_list)
{
struct brcmf_iscan_results list;
struct brcmf_scan_results *results;
struct brcmf_iscan_results *list_buf;
s32 err = 0;
memset(iscan->scan_buf, 0, WL_ISCAN_BUF_MAX);
list_buf = (struct brcmf_iscan_results *)iscan->scan_buf;
results = &list_buf->results;
results->buflen = BRCMF_ISCAN_RESULTS_FIXED_SIZE;
results->version = 0;
results->count = 0;
memset(&list, 0, sizeof(list));
list.results.buflen = cpu_to_le32(WL_ISCAN_BUF_MAX);
err = brcmf_dev_iovar_getbuf(iscan->dev, "iscanresults", &list,
BRCMF_ISCAN_RESULTS_FIXED_SIZE, iscan->scan_buf,
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
static s32 brcmf_iscan_done(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_priv->iscan;
s32 err = 0;
iscan->state = WL_ISCAN_STATE_IDLE;
rtnl_lock();
brcmf_inform_bss(cfg_priv);
brcmf_notify_iscan_complete(iscan, false);
rtnl_unlock();
return err;
}
static s32 brcmf_iscan_pending(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_priv->iscan;
s32 err = 0;
mod_timer(&iscan->timer, jiffies + iscan->timer_ms * HZ / 1000);
iscan->timer_on = 1;
return err;
}
static s32 brcmf_iscan_inprogress(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_priv->iscan;
s32 err = 0;
rtnl_lock();
brcmf_inform_bss(cfg_priv);
brcmf_run_iscan(iscan, NULL, BRCMF_SCAN_ACTION_CONTINUE);
rtnl_unlock();
mod_timer(&iscan->timer, jiffies + iscan->timer_ms * HZ / 1000);
iscan->timer_on = 1;
return err;
}
static s32 brcmf_iscan_aborted(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_priv->iscan;
s32 err = 0;
iscan->state = WL_ISCAN_STATE_IDLE;
rtnl_lock();
brcmf_notify_iscan_complete(iscan, true);
rtnl_unlock();
return err;
}
static s32 brcmf_iscan_thread(void *data)
{
struct sched_param param = {.sched_priority = MAX_RT_PRIO - 1 };
struct brcmf_cfg80211_iscan_ctrl *iscan =
(struct brcmf_cfg80211_iscan_ctrl *)data;
struct brcmf_cfg80211_priv *cfg_priv = iscan_to_cfg(iscan);
struct brcmf_cfg80211_iscan_eloop *el = &iscan->el;
u32 status;
int err = 0;
sched_setscheduler(current, SCHED_FIFO, &param);
allow_signal(SIGTERM);
status = BRCMF_SCAN_RESULTS_PARTIAL;
while (likely(!down_interruptible(&iscan->sync))) {
if (kthread_should_stop())
break;
if (iscan->timer_on) {
del_timer_sync(&iscan->timer);
iscan->timer_on = 0;
}
rtnl_lock();
err = brcmf_get_iscan_results(iscan, &status,
&cfg_priv->bss_list);
if (unlikely(err)) {
status = BRCMF_SCAN_RESULTS_ABORTED;
WL_ERR("Abort iscan\n");
}
rtnl_unlock();
el->handler[status](cfg_priv);
}
if (iscan->timer_on) {
del_timer_sync(&iscan->timer);
iscan->timer_on = 0;
}
WL_SCAN("ISCAN thread terminated\n");
return 0;
}
static void brcmf_iscan_timer(unsigned long data)
{
struct brcmf_cfg80211_iscan_ctrl *iscan =
(struct brcmf_cfg80211_iscan_ctrl *)data;
if (iscan) {
iscan->timer_on = 0;
WL_SCAN("timer expired\n");
brcmf_wakeup_iscan(iscan);
}
}
static s32 brcmf_invoke_iscan(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_to_iscan(cfg_priv);
int err = 0;
if (cfg_priv->iscan_on && !iscan->tsk) {
iscan->state = WL_ISCAN_STATE_IDLE;
sema_init(&iscan->sync, 0);
iscan->tsk = kthread_run(brcmf_iscan_thread, iscan, "wl_iscan");
if (IS_ERR(iscan->tsk)) {
WL_ERR("Could not create iscan thread\n");
iscan->tsk = NULL;
return -ENOMEM;
}
}
return err;
}
static void brcmf_init_iscan_eloop(struct brcmf_cfg80211_iscan_eloop *el)
{
memset(el, 0, sizeof(*el));
el->handler[BRCMF_SCAN_RESULTS_SUCCESS] = brcmf_iscan_done;
el->handler[BRCMF_SCAN_RESULTS_PARTIAL] = brcmf_iscan_inprogress;
el->handler[BRCMF_SCAN_RESULTS_PENDING] = brcmf_iscan_pending;
el->handler[BRCMF_SCAN_RESULTS_ABORTED] = brcmf_iscan_aborted;
el->handler[BRCMF_SCAN_RESULTS_NO_MEM] = brcmf_iscan_aborted;
}
static s32 brcmf_init_iscan(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_iscan_ctrl *iscan = cfg_to_iscan(cfg_priv);
int err = 0;
if (cfg_priv->iscan_on) {
iscan->dev = cfg_to_ndev(cfg_priv);
iscan->state = WL_ISCAN_STATE_IDLE;
brcmf_init_iscan_eloop(&iscan->el);
iscan->timer_ms = WL_ISCAN_TIMER_INTERVAL_MS;
init_timer(&iscan->timer);
iscan->timer.data = (unsigned long) iscan;
iscan->timer.function = brcmf_iscan_timer;
sema_init(&iscan->sync, 0);
iscan->tsk = kthread_run(brcmf_iscan_thread, iscan, "wl_iscan");
if (IS_ERR(iscan->tsk)) {
WL_ERR("Could not create iscan thread\n");
iscan->tsk = NULL;
return -ENOMEM;
}
iscan->data = cfg_priv;
}
return err;
}
static s32 wl_init_priv(struct brcmf_cfg80211_priv *cfg_priv)
{
struct wiphy *wiphy = cfg_to_wiphy(cfg_priv);
s32 err = 0;
cfg_priv->scan_request = NULL;
cfg_priv->pwr_save = !!(wiphy->flags & WIPHY_FLAG_PS_ON_BY_DEFAULT);
cfg_priv->iscan_on = true;
cfg_priv->roam_on = false;
cfg_priv->iscan_kickstart = false;
cfg_priv->active_scan = true;
cfg_priv->dongle_up = false;
brcmf_init_eq(cfg_priv);
err = brcmf_init_priv_mem(cfg_priv);
if (unlikely(err))
return err;
if (unlikely(brcmf_create_event_handler(cfg_priv)))
return -ENOMEM;
brcmf_init_eloop_handler(&cfg_priv->el);
mutex_init(&cfg_priv->usr_sync);
err = brcmf_init_iscan(cfg_priv);
if (unlikely(err))
return err;
brcmf_init_conf(cfg_priv->conf);
brcmf_init_prof(cfg_priv->profile);
brcmf_link_down(cfg_priv);
return err;
}
static void wl_deinit_priv(struct brcmf_cfg80211_priv *cfg_priv)
{
brcmf_destroy_event_handler(cfg_priv);
cfg_priv->dongle_up = false;
brcmf_flush_eq(cfg_priv);
brcmf_link_down(cfg_priv);
brcmf_term_iscan(cfg_priv);
brcmf_deinit_priv_mem(cfg_priv);
}
s32 brcmf_cfg80211_attach(struct net_device *ndev, void *data)
{
struct wireless_dev *wdev;
struct brcmf_cfg80211_priv *cfg_priv;
struct brcmf_cfg80211_iface *ci;
s32 err = 0;
if (unlikely(!ndev)) {
WL_ERR("ndev is invalid\n");
return -ENODEV;
}
cfg80211_dev = kzalloc(sizeof(struct brcmf_cfg80211_dev), GFP_KERNEL);
if (unlikely(!cfg80211_dev)) {
WL_ERR("wl_cfg80211_dev is invalid\n");
return -ENOMEM;
}
WL_INFO("func %p\n", brcmf_cfg80211_get_sdio_func());
wdev = brcmf_alloc_wdev(sizeof(struct brcmf_cfg80211_iface),
&brcmf_cfg80211_get_sdio_func()->dev);
if (IS_ERR(wdev))
return -ENOMEM;
wdev->iftype = brcmf_mode_to_nl80211_iftype(WL_MODE_BSS);
cfg_priv = wdev_to_cfg(wdev);
cfg_priv->wdev = wdev;
cfg_priv->pub = data;
ci = (struct brcmf_cfg80211_iface *)&cfg_priv->ci;
ci->cfg_priv = cfg_priv;
ndev->ieee80211_ptr = wdev;
SET_NETDEV_DEV(ndev, wiphy_dev(wdev->wiphy));
wdev->netdev = ndev;
err = wl_init_priv(cfg_priv);
if (unlikely(err)) {
WL_ERR("Failed to init iwm_priv (%d)\n", err);
goto cfg80211_attach_out;
}
brcmf_set_drvdata(cfg80211_dev, ci);
return err;
cfg80211_attach_out:
brcmf_free_wdev(cfg_priv);
return err;
}
void brcmf_cfg80211_detach(void)
{
struct brcmf_cfg80211_priv *cfg_priv;
cfg_priv = WL_PRIV_GET();
wl_deinit_priv(cfg_priv);
brcmf_free_wdev(cfg_priv);
brcmf_set_drvdata(cfg80211_dev, NULL);
kfree(cfg80211_dev);
cfg80211_dev = NULL;
brcmf_clear_sdio_func();
}
static void brcmf_wakeup_event(struct brcmf_cfg80211_priv *cfg_priv)
{
up(&cfg_priv->event_sync);
}
static s32 brcmf_event_handler(void *data)
{
struct brcmf_cfg80211_priv *cfg_priv =
(struct brcmf_cfg80211_priv *)data;
struct sched_param param = {.sched_priority = MAX_RT_PRIO - 1 };
struct brcmf_cfg80211_event_q *e;
sched_setscheduler(current, SCHED_FIFO, &param);
allow_signal(SIGTERM);
while (likely(!down_interruptible(&cfg_priv->event_sync))) {
if (kthread_should_stop())
break;
e = brcmf_deq_event(cfg_priv);
if (unlikely(!e)) {
WL_ERR("event queue empty...\n");
BUG();
}
WL_INFO("event type (%d)\n", e->etype);
if (cfg_priv->el.handler[e->etype]) {
cfg_priv->el.handler[e->etype](cfg_priv,
cfg_to_ndev(cfg_priv),
&e->emsg, e->edata);
} else {
WL_INFO("Unknown Event (%d): ignoring\n", e->etype);
}
brcmf_put_event(e);
}
WL_INFO("was terminated\n");
return 0;
}
void
brcmf_cfg80211_event(struct net_device *ndev,
const struct brcmf_event_msg *e, void *data)
{
u32 event_type = be32_to_cpu(e->event_type);
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(ndev);
if (likely(!brcmf_enq_event(cfg_priv, event_type, e, data)))
brcmf_wakeup_event(cfg_priv);
}
static void brcmf_init_eq(struct brcmf_cfg80211_priv *cfg_priv)
{
brcmf_init_eq_lock(cfg_priv);
INIT_LIST_HEAD(&cfg_priv->eq_list);
}
static void brcmf_flush_eq(struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_event_q *e;
brcmf_lock_eq(cfg_priv);
while (!list_empty(&cfg_priv->eq_list)) {
e = list_first_entry(&cfg_priv->eq_list,
struct brcmf_cfg80211_event_q, eq_list);
list_del(&e->eq_list);
kfree(e);
}
brcmf_unlock_eq(cfg_priv);
}
static struct brcmf_cfg80211_event_q *brcmf_deq_event(
struct brcmf_cfg80211_priv *cfg_priv)
{
struct brcmf_cfg80211_event_q *e = NULL;
brcmf_lock_eq(cfg_priv);
if (likely(!list_empty(&cfg_priv->eq_list))) {
e = list_first_entry(&cfg_priv->eq_list,
struct brcmf_cfg80211_event_q, eq_list);
list_del(&e->eq_list);
}
brcmf_unlock_eq(cfg_priv);
return e;
}
static s32
brcmf_enq_event(struct brcmf_cfg80211_priv *cfg_priv, u32 event,
const struct brcmf_event_msg *msg, void *data)
{
struct brcmf_cfg80211_event_q *e;
s32 err = 0;
e = kzalloc(sizeof(struct brcmf_cfg80211_event_q), GFP_KERNEL);
if (unlikely(!e)) {
WL_ERR("event alloc failed\n");
return -ENOMEM;
}
e->etype = event;
memcpy(&e->emsg, msg, sizeof(struct brcmf_event_msg));
brcmf_lock_eq(cfg_priv);
list_add_tail(&e->eq_list, &cfg_priv->eq_list);
brcmf_unlock_eq(cfg_priv);
return err;
}
static void brcmf_put_event(struct brcmf_cfg80211_event_q *e)
{
kfree(e);
}
void brcmf_cfg80211_sdio_func(void *func)
{
cfg80211_sdio_func = (struct sdio_func *)func;
}
static void brcmf_clear_sdio_func(void)
{
cfg80211_sdio_func = NULL;
}
struct sdio_func *brcmf_cfg80211_get_sdio_func(void)
{
return cfg80211_sdio_func;
}
static s32 brcmf_dongle_mode(struct net_device *ndev, s32 iftype)
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
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_INFRA, &infra, sizeof(infra));
if (unlikely(err)) {
WL_ERR("WLC_SET_INFRA error (%d)\n", err);
return err;
}
return 0;
}
static s32 brcmf_dongle_eventmsg(struct net_device *ndev)
{
s8 iovbuf[BRCMF_EVENTING_MASK_LEN + 12];
s8 eventmask[BRCMF_EVENTING_MASK_LEN];
s32 err = 0;
WL_TRACE("Enter\n");
brcmu_mkiovar("event_msgs", eventmask, BRCMF_EVENTING_MASK_LEN, iovbuf,
sizeof(iovbuf));
err = brcmf_dev_ioctl(ndev, BRCMF_C_GET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("Get event_msgs error (%d)\n", err);
goto dongle_eventmsg_out;
}
memcpy(eventmask, iovbuf, BRCMF_EVENTING_MASK_LEN);
setbit(eventmask, BRCMF_E_SET_SSID);
setbit(eventmask, BRCMF_E_ROAM);
setbit(eventmask, BRCMF_E_PRUNE);
setbit(eventmask, BRCMF_E_AUTH);
setbit(eventmask, BRCMF_E_REASSOC);
setbit(eventmask, BRCMF_E_REASSOC_IND);
setbit(eventmask, BRCMF_E_DEAUTH_IND);
setbit(eventmask, BRCMF_E_DISASSOC_IND);
setbit(eventmask, BRCMF_E_DISASSOC);
setbit(eventmask, BRCMF_E_JOIN);
setbit(eventmask, BRCMF_E_ASSOC_IND);
setbit(eventmask, BRCMF_E_PSK_SUP);
setbit(eventmask, BRCMF_E_LINK);
setbit(eventmask, BRCMF_E_NDIS_LINK);
setbit(eventmask, BRCMF_E_MIC_ERROR);
setbit(eventmask, BRCMF_E_PMKID_CACHE);
setbit(eventmask, BRCMF_E_TXFAIL);
setbit(eventmask, BRCMF_E_JOIN_START);
setbit(eventmask, BRCMF_E_SCAN_COMPLETE);
brcmu_mkiovar("event_msgs", eventmask, BRCMF_EVENTING_MASK_LEN, iovbuf,
sizeof(iovbuf));
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("Set event_msgs error (%d)\n", err);
goto dongle_eventmsg_out;
}
dongle_eventmsg_out:
WL_TRACE("Exit\n");
return err;
}
static s32
brcmf_dongle_roam(struct net_device *ndev, u32 roamvar, u32 bcn_timeout)
{
s8 iovbuf[32];
s32 roamtrigger[2];
s32 roam_delta[2];
s32 err = 0;
if (roamvar) {
brcmu_mkiovar("bcn_timeout", (char *)&bcn_timeout,
sizeof(bcn_timeout), iovbuf, sizeof(iovbuf));
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_VAR,
iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("bcn_timeout error (%d)\n", err);
goto dongle_rom_out;
}
}
WL_INFO("Internal Roaming = %s\n", roamvar ? "Off" : "On");
brcmu_mkiovar("roam_off", (char *)&roamvar,
sizeof(roamvar), iovbuf, sizeof(iovbuf));
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_VAR, iovbuf, sizeof(iovbuf));
if (unlikely(err)) {
WL_ERR("roam_off error (%d)\n", err);
goto dongle_rom_out;
}
roamtrigger[0] = WL_ROAM_TRIGGER_LEVEL;
roamtrigger[1] = BRCM_BAND_ALL;
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_ROAM_TRIGGER,
(void *)roamtrigger, sizeof(roamtrigger));
if (unlikely(err)) {
WL_ERR("WLC_SET_ROAM_TRIGGER error (%d)\n", err);
goto dongle_rom_out;
}
roam_delta[0] = WL_ROAM_DELTA;
roam_delta[1] = BRCM_BAND_ALL;
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_ROAM_DELTA,
(void *)roam_delta, sizeof(roam_delta));
if (unlikely(err)) {
WL_ERR("WLC_SET_ROAM_DELTA error (%d)\n", err);
goto dongle_rom_out;
}
dongle_rom_out:
return err;
}
static s32
brcmf_dongle_scantime(struct net_device *ndev, s32 scan_assoc_time,
s32 scan_unassoc_time, s32 scan_passive_time)
{
s32 err = 0;
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_SCAN_CHANNEL_TIME,
&scan_assoc_time, sizeof(scan_assoc_time));
if (err) {
if (err == -EOPNOTSUPP)
WL_INFO("Scan assoc time is not supported\n");
else
WL_ERR("Scan assoc time error (%d)\n", err);
goto dongle_scantime_out;
}
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_SCAN_UNASSOC_TIME,
&scan_unassoc_time, sizeof(scan_unassoc_time));
if (err) {
if (err == -EOPNOTSUPP)
WL_INFO("Scan unassoc time is not supported\n");
else
WL_ERR("Scan unassoc time error (%d)\n", err);
goto dongle_scantime_out;
}
err = brcmf_dev_ioctl(ndev, BRCMF_C_SET_SCAN_PASSIVE_TIME,
&scan_passive_time, sizeof(scan_passive_time));
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
s32 brcmf_config_dongle(struct brcmf_cfg80211_priv *cfg_priv, bool need_lock)
{
struct net_device *ndev;
struct wireless_dev *wdev;
s32 err = 0;
if (cfg_priv->dongle_up)
return err;
ndev = cfg_to_ndev(cfg_priv);
wdev = ndev->ieee80211_ptr;
if (need_lock)
rtnl_lock();
brcmf_dongle_scantime(ndev, WL_SCAN_CHANNEL_TIME,
WL_SCAN_UNASSOC_TIME, WL_SCAN_PASSIVE_TIME);
err = brcmf_dongle_eventmsg(ndev);
if (unlikely(err))
goto default_conf_out;
err = brcmf_dongle_roam(ndev, (cfg_priv->roam_on ? 0 : 1),
WL_BEACON_TIMEOUT);
if (unlikely(err))
goto default_conf_out;
err = brcmf_dongle_mode(ndev, wdev->iftype);
if (unlikely(err && err != -EINPROGRESS))
goto default_conf_out;
err = brcmf_dongle_probecap(cfg_priv);
if (unlikely(err))
goto default_conf_out;
default_conf_out:
if (need_lock)
rtnl_unlock();
cfg_priv->dongle_up = true;
return err;
}
static s32 wl_update_wiphybands(struct brcmf_cfg80211_priv *cfg_priv)
{
struct wiphy *wiphy;
s32 phy_list;
s8 phy;
s32 err = 0;
err = brcmf_dev_ioctl(cfg_to_ndev(cfg_priv), BRCM_GET_PHYLIST,
&phy_list, sizeof(phy_list));
if (unlikely(err)) {
WL_ERR("error (%d)\n", err);
return err;
}
phy = ((char *)&phy_list)[1];
WL_INFO("%c phy\n", phy);
if (phy == 'n' || phy == 'a') {
wiphy = cfg_to_wiphy(cfg_priv);
wiphy->bands[IEEE80211_BAND_5GHZ] = &__wl_band_5ghz_n;
}
return err;
}
static s32 __brcmf_cfg80211_up(struct brcmf_cfg80211_priv *cfg_priv)
{
s32 err = 0;
set_bit(WL_STATUS_READY, &cfg_priv->status);
brcmf_debugfs_add_netdev_params(cfg_priv);
err = brcmf_config_dongle(cfg_priv, false);
if (unlikely(err))
return err;
brcmf_invoke_iscan(cfg_priv);
return err;
}
static s32 __brcmf_cfg80211_down(struct brcmf_cfg80211_priv *cfg_priv)
{
if ((test_bit(WL_STATUS_CONNECTED, &cfg_priv->status) ||
test_bit(WL_STATUS_CONNECTING, &cfg_priv->status)) &&
test_bit(WL_STATUS_READY, &cfg_priv->status)) {
WL_INFO("Disassociating from AP");
brcmf_link_down(cfg_priv);
rtnl_unlock();
brcmf_delay(500);
rtnl_lock();
}
set_bit(WL_STATUS_SCAN_ABORTING, &cfg_priv->status);
brcmf_term_iscan(cfg_priv);
if (cfg_priv->scan_request) {
cfg80211_scan_done(cfg_priv->scan_request, true);
cfg_priv->scan_request = NULL;
}
clear_bit(WL_STATUS_READY, &cfg_priv->status);
clear_bit(WL_STATUS_SCANNING, &cfg_priv->status);
clear_bit(WL_STATUS_SCAN_ABORTING, &cfg_priv->status);
brcmf_debugfs_remove_netdev(cfg_priv);
return 0;
}
s32 brcmf_cfg80211_up(void)
{
struct brcmf_cfg80211_priv *cfg_priv;
s32 err = 0;
cfg_priv = WL_PRIV_GET();
mutex_lock(&cfg_priv->usr_sync);
err = __brcmf_cfg80211_up(cfg_priv);
mutex_unlock(&cfg_priv->usr_sync);
return err;
}
s32 brcmf_cfg80211_down(void)
{
struct brcmf_cfg80211_priv *cfg_priv;
s32 err = 0;
cfg_priv = WL_PRIV_GET();
mutex_lock(&cfg_priv->usr_sync);
err = __brcmf_cfg80211_down(cfg_priv);
mutex_unlock(&cfg_priv->usr_sync);
return err;
}
static s32 brcmf_dongle_probecap(struct brcmf_cfg80211_priv *cfg_priv)
{
return wl_update_wiphybands(cfg_priv);
}
static void *brcmf_read_prof(struct brcmf_cfg80211_priv *cfg_priv, s32 item)
{
switch (item) {
case WL_PROF_SEC:
return &cfg_priv->profile->sec;
case WL_PROF_BSSID:
return &cfg_priv->profile->bssid;
case WL_PROF_SSID:
return &cfg_priv->profile->ssid;
}
WL_ERR("invalid item (%d)\n", item);
return NULL;
}
static s32
brcmf_update_prof(struct brcmf_cfg80211_priv *cfg_priv,
const struct brcmf_event_msg *e, void *data, s32 item)
{
s32 err = 0;
struct brcmf_ssid *ssid;
switch (item) {
case WL_PROF_SSID:
ssid = (struct brcmf_ssid *) data;
memset(cfg_priv->profile->ssid.SSID, 0,
sizeof(cfg_priv->profile->ssid.SSID));
memcpy(cfg_priv->profile->ssid.SSID,
ssid->SSID, ssid->SSID_len);
cfg_priv->profile->ssid.SSID_len = ssid->SSID_len;
break;
case WL_PROF_BSSID:
if (data)
memcpy(cfg_priv->profile->bssid, data, ETH_ALEN);
else
memset(cfg_priv->profile->bssid, 0, ETH_ALEN);
break;
case WL_PROF_SEC:
memcpy(&cfg_priv->profile->sec, data,
sizeof(cfg_priv->profile->sec));
break;
case WL_PROF_BEACONINT:
cfg_priv->profile->beacon_interval = *(u16 *)data;
break;
case WL_PROF_DTIMPERIOD:
cfg_priv->profile->dtim_period = *(u8 *)data;
break;
default:
WL_ERR("unsupported item (%d)\n", item);
err = -EOPNOTSUPP;
break;
}
return err;
}
static bool brcmf_is_ibssmode(struct brcmf_cfg80211_priv *cfg_priv)
{
return cfg_priv->conf->mode == WL_MODE_IBSS;
}
static __used s32 brcmf_add_ie(struct brcmf_cfg80211_priv *cfg_priv,
u8 t, u8 l, u8 *v)
{
struct brcmf_cfg80211_ie *ie = &cfg_priv->ie;
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
static void brcmf_link_down(struct brcmf_cfg80211_priv *cfg_priv)
{
struct net_device *dev = NULL;
s32 err = 0;
WL_TRACE("Enter\n");
if (cfg_priv->link_up) {
dev = cfg_to_ndev(cfg_priv);
WL_INFO("Call WLC_DISASSOC to stop excess roaming\n ");
err = brcmf_dev_ioctl(dev, BRCMF_C_DISASSOC, NULL, 0);
if (unlikely(err))
WL_ERR("WLC_DISASSOC failed (%d)\n", err);
cfg_priv->link_up = false;
}
WL_TRACE("Exit\n");
}
static void brcmf_lock_eq(struct brcmf_cfg80211_priv *cfg_priv)
{
spin_lock_irq(&cfg_priv->eq_lock);
}
static void brcmf_unlock_eq(struct brcmf_cfg80211_priv *cfg_priv)
{
spin_unlock_irq(&cfg_priv->eq_lock);
}
static void brcmf_init_eq_lock(struct brcmf_cfg80211_priv *cfg_priv)
{
spin_lock_init(&cfg_priv->eq_lock);
}
static void brcmf_delay(u32 ms)
{
if (ms < 1000 / HZ) {
cond_resched();
mdelay(ms);
} else {
msleep(ms);
}
}
static void brcmf_set_drvdata(struct brcmf_cfg80211_dev *dev, void *data)
{
dev->driver_data = data;
}
static void *brcmf_get_drvdata(struct brcmf_cfg80211_dev *dev)
{
void *data = NULL;
if (dev)
data = dev->driver_data;
return data;
}
static void brcmf_set_mpc(struct net_device *ndev, int mpc)
{
s32 err = 0;
struct brcmf_cfg80211_priv *cfg_priv = ndev_to_cfg(ndev);
if (test_bit(WL_STATUS_READY, &cfg_priv->status)) {
err = brcmf_dev_intvar_set(ndev, "mpc", mpc);
if (unlikely(err)) {
WL_ERR("fail to set mpc\n");
return;
}
WL_INFO("MPC : %d\n", mpc);
}
}
static int brcmf_debugfs_add_netdev_params(struct brcmf_cfg80211_priv *cfg_priv)
{
char buf[10+IFNAMSIZ];
struct dentry *fd;
s32 err = 0;
sprintf(buf, "netdev:%s", cfg_to_ndev(cfg_priv)->name);
cfg_priv->debugfsdir = debugfs_create_dir(buf,
cfg_to_wiphy(cfg_priv)->debugfsdir);
fd = debugfs_create_u16("beacon_int", S_IRUGO, cfg_priv->debugfsdir,
(u16 *)&cfg_priv->profile->beacon_interval);
if (!fd) {
err = -ENOMEM;
goto err_out;
}
fd = debugfs_create_u8("dtim_period", S_IRUGO, cfg_priv->debugfsdir,
(u8 *)&cfg_priv->profile->dtim_period);
if (!fd) {
err = -ENOMEM;
goto err_out;
}
err_out:
return err;
}
static void brcmf_debugfs_remove_netdev(struct brcmf_cfg80211_priv *cfg_priv)
{
debugfs_remove_recursive(cfg_priv->debugfsdir);
cfg_priv->debugfsdir = NULL;
}
