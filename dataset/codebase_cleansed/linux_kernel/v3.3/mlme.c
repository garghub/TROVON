void cfg80211_send_rx_auth(struct net_device *dev, const u8 *buf, size_t len)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)buf;
u8 *bssid = mgmt->bssid;
int i;
u16 status = le16_to_cpu(mgmt->u.auth.status_code);
bool done = false;
wdev_lock(wdev);
for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (wdev->authtry_bsses[i] &&
memcmp(wdev->authtry_bsses[i]->pub.bssid, bssid,
ETH_ALEN) == 0) {
if (status == WLAN_STATUS_SUCCESS) {
wdev->auth_bsses[i] = wdev->authtry_bsses[i];
} else {
cfg80211_unhold_bss(wdev->authtry_bsses[i]);
cfg80211_put_bss(&wdev->authtry_bsses[i]->pub);
}
wdev->authtry_bsses[i] = NULL;
done = true;
break;
}
}
if (done) {
nl80211_send_rx_auth(rdev, dev, buf, len, GFP_KERNEL);
cfg80211_sme_rx_auth(dev, buf, len);
}
wdev_unlock(wdev);
}
void cfg80211_send_rx_assoc(struct net_device *dev, const u8 *buf, size_t len)
{
u16 status_code;
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)buf;
u8 *ie = mgmt->u.assoc_resp.variable;
int i, ieoffs = offsetof(struct ieee80211_mgmt, u.assoc_resp.variable);
struct cfg80211_internal_bss *bss = NULL;
wdev_lock(wdev);
status_code = le16_to_cpu(mgmt->u.assoc_resp.status_code);
if (status_code != WLAN_STATUS_SUCCESS && wdev->conn &&
cfg80211_sme_failed_reassoc(wdev))
goto out;
nl80211_send_rx_assoc(rdev, dev, buf, len, GFP_KERNEL);
if (status_code == WLAN_STATUS_SUCCESS) {
for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (!wdev->auth_bsses[i])
continue;
if (memcmp(wdev->auth_bsses[i]->pub.bssid, mgmt->bssid,
ETH_ALEN) == 0) {
bss = wdev->auth_bsses[i];
wdev->auth_bsses[i] = NULL;
cfg80211_ref_bss(bss);
break;
}
}
if (!bss)
goto out;
} else if (wdev->conn) {
cfg80211_sme_failed_assoc(wdev);
goto out;
}
if (!wdev->conn && wdev->sme_state == CFG80211_SME_IDLE) {
wdev->sme_state = CFG80211_SME_CONNECTING;
}
__cfg80211_connect_result(dev, mgmt->bssid, NULL, 0, ie, len - ieoffs,
status_code,
status_code == WLAN_STATUS_SUCCESS,
bss ? &bss->pub : NULL);
if (bss) {
cfg80211_unhold_bss(bss);
cfg80211_put_bss(&bss->pub);
}
out:
wdev_unlock(wdev);
}
void __cfg80211_send_deauth(struct net_device *dev,
const u8 *buf, size_t len)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)buf;
const u8 *bssid = mgmt->bssid;
int i;
bool found = false, was_current = false;
ASSERT_WDEV_LOCK(wdev);
if (wdev->current_bss &&
memcmp(wdev->current_bss->pub.bssid, bssid, ETH_ALEN) == 0) {
cfg80211_unhold_bss(wdev->current_bss);
cfg80211_put_bss(&wdev->current_bss->pub);
wdev->current_bss = NULL;
found = true;
was_current = true;
} else for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (wdev->auth_bsses[i] &&
memcmp(wdev->auth_bsses[i]->pub.bssid, bssid, ETH_ALEN) == 0) {
cfg80211_unhold_bss(wdev->auth_bsses[i]);
cfg80211_put_bss(&wdev->auth_bsses[i]->pub);
wdev->auth_bsses[i] = NULL;
found = true;
break;
}
if (wdev->authtry_bsses[i] &&
memcmp(wdev->authtry_bsses[i]->pub.bssid, bssid,
ETH_ALEN) == 0 &&
memcmp(mgmt->sa, dev->dev_addr, ETH_ALEN) == 0) {
cfg80211_unhold_bss(wdev->authtry_bsses[i]);
cfg80211_put_bss(&wdev->authtry_bsses[i]->pub);
wdev->authtry_bsses[i] = NULL;
found = true;
break;
}
}
if (!found)
return;
nl80211_send_deauth(rdev, dev, buf, len, GFP_KERNEL);
if (wdev->sme_state == CFG80211_SME_CONNECTED && was_current) {
u16 reason_code;
bool from_ap;
reason_code = le16_to_cpu(mgmt->u.deauth.reason_code);
from_ap = memcmp(mgmt->sa, dev->dev_addr, ETH_ALEN) != 0;
__cfg80211_disconnected(dev, NULL, 0, reason_code, from_ap);
} else if (wdev->sme_state == CFG80211_SME_CONNECTING) {
__cfg80211_connect_result(dev, mgmt->bssid, NULL, 0, NULL, 0,
WLAN_STATUS_UNSPECIFIED_FAILURE,
false, NULL);
}
}
void cfg80211_send_deauth(struct net_device *dev, const u8 *buf, size_t len)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
wdev_lock(wdev);
__cfg80211_send_deauth(dev, buf, len);
wdev_unlock(wdev);
}
void __cfg80211_send_disassoc(struct net_device *dev,
const u8 *buf, size_t len)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)buf;
const u8 *bssid = mgmt->bssid;
int i;
u16 reason_code;
bool from_ap;
bool done = false;
ASSERT_WDEV_LOCK(wdev);
nl80211_send_disassoc(rdev, dev, buf, len, GFP_KERNEL);
if (wdev->sme_state != CFG80211_SME_CONNECTED)
return;
if (wdev->current_bss &&
memcmp(wdev->current_bss->pub.bssid, bssid, ETH_ALEN) == 0) {
for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (wdev->authtry_bsses[i] || wdev->auth_bsses[i])
continue;
wdev->auth_bsses[i] = wdev->current_bss;
wdev->current_bss = NULL;
done = true;
cfg80211_sme_disassoc(dev, i);
break;
}
WARN_ON(!done);
} else
WARN_ON(1);
reason_code = le16_to_cpu(mgmt->u.disassoc.reason_code);
from_ap = memcmp(mgmt->sa, dev->dev_addr, ETH_ALEN) != 0;
__cfg80211_disconnected(dev, NULL, 0, reason_code, from_ap);
}
void cfg80211_send_disassoc(struct net_device *dev, const u8 *buf, size_t len)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
wdev_lock(wdev);
__cfg80211_send_disassoc(dev, buf, len);
wdev_unlock(wdev);
}
void cfg80211_send_unprot_deauth(struct net_device *dev, const u8 *buf,
size_t len)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_unprot_deauth(rdev, dev, buf, len, GFP_ATOMIC);
}
void cfg80211_send_unprot_disassoc(struct net_device *dev, const u8 *buf,
size_t len)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_unprot_disassoc(rdev, dev, buf, len, GFP_ATOMIC);
}
static void __cfg80211_auth_remove(struct wireless_dev *wdev, const u8 *addr)
{
int i;
bool done = false;
ASSERT_WDEV_LOCK(wdev);
for (i = 0; addr && i < MAX_AUTH_BSSES; i++) {
if (wdev->authtry_bsses[i] &&
memcmp(wdev->authtry_bsses[i]->pub.bssid,
addr, ETH_ALEN) == 0) {
cfg80211_unhold_bss(wdev->authtry_bsses[i]);
cfg80211_put_bss(&wdev->authtry_bsses[i]->pub);
wdev->authtry_bsses[i] = NULL;
done = true;
break;
}
}
WARN_ON(!done);
}
void __cfg80211_auth_canceled(struct net_device *dev, const u8 *addr)
{
__cfg80211_auth_remove(dev->ieee80211_ptr, addr);
}
void cfg80211_send_auth_timeout(struct net_device *dev, const u8 *addr)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
wdev_lock(wdev);
nl80211_send_auth_timeout(rdev, dev, addr, GFP_KERNEL);
if (wdev->sme_state == CFG80211_SME_CONNECTING)
__cfg80211_connect_result(dev, addr, NULL, 0, NULL, 0,
WLAN_STATUS_UNSPECIFIED_FAILURE,
false, NULL);
__cfg80211_auth_remove(wdev, addr);
wdev_unlock(wdev);
}
void cfg80211_send_assoc_timeout(struct net_device *dev, const u8 *addr)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
int i;
bool done = false;
wdev_lock(wdev);
nl80211_send_assoc_timeout(rdev, dev, addr, GFP_KERNEL);
if (wdev->sme_state == CFG80211_SME_CONNECTING)
__cfg80211_connect_result(dev, addr, NULL, 0, NULL, 0,
WLAN_STATUS_UNSPECIFIED_FAILURE,
false, NULL);
for (i = 0; addr && i < MAX_AUTH_BSSES; i++) {
if (wdev->auth_bsses[i] &&
memcmp(wdev->auth_bsses[i]->pub.bssid,
addr, ETH_ALEN) == 0) {
cfg80211_unhold_bss(wdev->auth_bsses[i]);
cfg80211_put_bss(&wdev->auth_bsses[i]->pub);
wdev->auth_bsses[i] = NULL;
done = true;
break;
}
}
WARN_ON(!done);
wdev_unlock(wdev);
}
void cfg80211_michael_mic_failure(struct net_device *dev, const u8 *addr,
enum nl80211_key_type key_type, int key_id,
const u8 *tsc, gfp_t gfp)
{
struct wiphy *wiphy = dev->ieee80211_ptr->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
#ifdef CONFIG_CFG80211_WEXT
union iwreq_data wrqu;
char *buf = kmalloc(128, gfp);
if (buf) {
sprintf(buf, "MLME-MICHAELMICFAILURE.indication("
"keyid=%d %scast addr=%pM)", key_id,
key_type == NL80211_KEYTYPE_GROUP ? "broad" : "uni",
addr);
memset(&wrqu, 0, sizeof(wrqu));
wrqu.data.length = strlen(buf);
wireless_send_event(dev, IWEVCUSTOM, &wrqu, buf);
kfree(buf);
}
#endif
nl80211_michael_mic_failure(rdev, dev, addr, key_type, key_id, tsc, gfp);
}
int __cfg80211_mlme_auth(struct cfg80211_registered_device *rdev,
struct net_device *dev,
struct ieee80211_channel *chan,
enum nl80211_auth_type auth_type,
const u8 *bssid,
const u8 *ssid, int ssid_len,
const u8 *ie, int ie_len,
const u8 *key, int key_len, int key_idx,
bool local_state_change)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct cfg80211_auth_request req;
struct cfg80211_internal_bss *bss;
int i, err, slot = -1, nfree = 0;
ASSERT_WDEV_LOCK(wdev);
if (auth_type == NL80211_AUTHTYPE_SHARED_KEY)
if (!key || !key_len || key_idx < 0 || key_idx > 4)
return -EINVAL;
if (wdev->current_bss &&
memcmp(bssid, wdev->current_bss->pub.bssid, ETH_ALEN) == 0)
return -EALREADY;
for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (wdev->authtry_bsses[i] &&
memcmp(bssid, wdev->authtry_bsses[i]->pub.bssid,
ETH_ALEN) == 0)
return -EALREADY;
if (wdev->auth_bsses[i] &&
memcmp(bssid, wdev->auth_bsses[i]->pub.bssid,
ETH_ALEN) == 0)
return -EALREADY;
}
memset(&req, 0, sizeof(req));
req.local_state_change = local_state_change;
req.ie = ie;
req.ie_len = ie_len;
req.auth_type = auth_type;
req.bss = cfg80211_get_bss(&rdev->wiphy, chan, bssid, ssid, ssid_len,
WLAN_CAPABILITY_ESS, WLAN_CAPABILITY_ESS);
req.key = key;
req.key_len = key_len;
req.key_idx = key_idx;
if (!req.bss)
return -ENOENT;
bss = bss_from_pub(req.bss);
for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (!wdev->auth_bsses[i] && !wdev->authtry_bsses[i]) {
slot = i;
nfree++;
}
}
if (nfree < 2) {
err = -ENOSPC;
goto out;
}
if (local_state_change)
wdev->auth_bsses[slot] = bss;
else
wdev->authtry_bsses[slot] = bss;
cfg80211_hold_bss(bss);
err = rdev->ops->auth(&rdev->wiphy, dev, &req);
if (err) {
if (local_state_change)
wdev->auth_bsses[slot] = NULL;
else
wdev->authtry_bsses[slot] = NULL;
cfg80211_unhold_bss(bss);
}
out:
if (err)
cfg80211_put_bss(req.bss);
return err;
}
int cfg80211_mlme_auth(struct cfg80211_registered_device *rdev,
struct net_device *dev, struct ieee80211_channel *chan,
enum nl80211_auth_type auth_type, const u8 *bssid,
const u8 *ssid, int ssid_len,
const u8 *ie, int ie_len,
const u8 *key, int key_len, int key_idx,
bool local_state_change)
{
int err;
wdev_lock(dev->ieee80211_ptr);
err = __cfg80211_mlme_auth(rdev, dev, chan, auth_type, bssid,
ssid, ssid_len, ie, ie_len,
key, key_len, key_idx, local_state_change);
wdev_unlock(dev->ieee80211_ptr);
return err;
}
void cfg80211_oper_and_ht_capa(struct ieee80211_ht_cap *ht_capa,
const struct ieee80211_ht_cap *ht_capa_mask)
{
int i;
u8 *p1, *p2;
if (!ht_capa_mask) {
memset(ht_capa, 0, sizeof(*ht_capa));
return;
}
p1 = (u8*)(ht_capa);
p2 = (u8*)(ht_capa_mask);
for (i = 0; i<sizeof(*ht_capa); i++)
p1[i] &= p2[i];
}
int __cfg80211_mlme_assoc(struct cfg80211_registered_device *rdev,
struct net_device *dev,
struct ieee80211_channel *chan,
const u8 *bssid, const u8 *prev_bssid,
const u8 *ssid, int ssid_len,
const u8 *ie, int ie_len, bool use_mfp,
struct cfg80211_crypto_settings *crypt,
u32 assoc_flags, struct ieee80211_ht_cap *ht_capa,
struct ieee80211_ht_cap *ht_capa_mask)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct cfg80211_assoc_request req;
struct cfg80211_internal_bss *bss;
int i, err, slot = -1;
bool was_connected = false;
ASSERT_WDEV_LOCK(wdev);
memset(&req, 0, sizeof(req));
if (wdev->current_bss && prev_bssid &&
memcmp(wdev->current_bss->pub.bssid, prev_bssid, ETH_ALEN) == 0) {
if (wdev->sme_state == CFG80211_SME_CONNECTED) {
was_connected = true;
wdev->sme_state = CFG80211_SME_CONNECTING;
}
} else if (wdev->current_bss)
return -EALREADY;
req.ie = ie;
req.ie_len = ie_len;
memcpy(&req.crypto, crypt, sizeof(req.crypto));
req.use_mfp = use_mfp;
req.prev_bssid = prev_bssid;
req.flags = assoc_flags;
if (ht_capa)
memcpy(&req.ht_capa, ht_capa, sizeof(req.ht_capa));
if (ht_capa_mask)
memcpy(&req.ht_capa_mask, ht_capa_mask,
sizeof(req.ht_capa_mask));
cfg80211_oper_and_ht_capa(&req.ht_capa_mask,
rdev->wiphy.ht_capa_mod_mask);
req.bss = cfg80211_get_bss(&rdev->wiphy, chan, bssid, ssid, ssid_len,
WLAN_CAPABILITY_ESS, WLAN_CAPABILITY_ESS);
if (!req.bss) {
if (was_connected)
wdev->sme_state = CFG80211_SME_CONNECTED;
return -ENOENT;
}
bss = bss_from_pub(req.bss);
for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (bss == wdev->auth_bsses[i]) {
slot = i;
break;
}
}
if (slot < 0) {
err = -ENOTCONN;
goto out;
}
err = rdev->ops->assoc(&rdev->wiphy, dev, &req);
out:
if (err && was_connected)
wdev->sme_state = CFG80211_SME_CONNECTED;
cfg80211_put_bss(req.bss);
return err;
}
int cfg80211_mlme_assoc(struct cfg80211_registered_device *rdev,
struct net_device *dev,
struct ieee80211_channel *chan,
const u8 *bssid, const u8 *prev_bssid,
const u8 *ssid, int ssid_len,
const u8 *ie, int ie_len, bool use_mfp,
struct cfg80211_crypto_settings *crypt,
u32 assoc_flags, struct ieee80211_ht_cap *ht_capa,
struct ieee80211_ht_cap *ht_capa_mask)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
int err;
wdev_lock(wdev);
err = __cfg80211_mlme_assoc(rdev, dev, chan, bssid, prev_bssid,
ssid, ssid_len, ie, ie_len, use_mfp, crypt,
assoc_flags, ht_capa, ht_capa_mask);
wdev_unlock(wdev);
return err;
}
int __cfg80211_mlme_deauth(struct cfg80211_registered_device *rdev,
struct net_device *dev, const u8 *bssid,
const u8 *ie, int ie_len, u16 reason,
bool local_state_change)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct cfg80211_deauth_request req;
int i;
ASSERT_WDEV_LOCK(wdev);
memset(&req, 0, sizeof(req));
req.reason_code = reason;
req.local_state_change = local_state_change;
req.ie = ie;
req.ie_len = ie_len;
if (wdev->current_bss &&
memcmp(wdev->current_bss->pub.bssid, bssid, ETH_ALEN) == 0) {
req.bss = &wdev->current_bss->pub;
} else for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (wdev->auth_bsses[i] &&
memcmp(bssid, wdev->auth_bsses[i]->pub.bssid, ETH_ALEN) == 0) {
req.bss = &wdev->auth_bsses[i]->pub;
break;
}
if (wdev->authtry_bsses[i] &&
memcmp(bssid, wdev->authtry_bsses[i]->pub.bssid, ETH_ALEN) == 0) {
req.bss = &wdev->authtry_bsses[i]->pub;
break;
}
}
if (!req.bss)
return -ENOTCONN;
return rdev->ops->deauth(&rdev->wiphy, dev, &req, wdev);
}
int cfg80211_mlme_deauth(struct cfg80211_registered_device *rdev,
struct net_device *dev, const u8 *bssid,
const u8 *ie, int ie_len, u16 reason,
bool local_state_change)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
int err;
wdev_lock(wdev);
err = __cfg80211_mlme_deauth(rdev, dev, bssid, ie, ie_len, reason,
local_state_change);
wdev_unlock(wdev);
return err;
}
static int __cfg80211_mlme_disassoc(struct cfg80211_registered_device *rdev,
struct net_device *dev, const u8 *bssid,
const u8 *ie, int ie_len, u16 reason,
bool local_state_change)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct cfg80211_disassoc_request req;
ASSERT_WDEV_LOCK(wdev);
if (wdev->sme_state != CFG80211_SME_CONNECTED)
return -ENOTCONN;
if (WARN_ON(!wdev->current_bss))
return -ENOTCONN;
memset(&req, 0, sizeof(req));
req.reason_code = reason;
req.local_state_change = local_state_change;
req.ie = ie;
req.ie_len = ie_len;
if (memcmp(wdev->current_bss->pub.bssid, bssid, ETH_ALEN) == 0)
req.bss = &wdev->current_bss->pub;
else
return -ENOTCONN;
return rdev->ops->disassoc(&rdev->wiphy, dev, &req, wdev);
}
int cfg80211_mlme_disassoc(struct cfg80211_registered_device *rdev,
struct net_device *dev, const u8 *bssid,
const u8 *ie, int ie_len, u16 reason,
bool local_state_change)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
int err;
wdev_lock(wdev);
err = __cfg80211_mlme_disassoc(rdev, dev, bssid, ie, ie_len, reason,
local_state_change);
wdev_unlock(wdev);
return err;
}
void cfg80211_mlme_down(struct cfg80211_registered_device *rdev,
struct net_device *dev)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct cfg80211_deauth_request req;
int i;
ASSERT_WDEV_LOCK(wdev);
if (!rdev->ops->deauth)
return;
memset(&req, 0, sizeof(req));
req.reason_code = WLAN_REASON_DEAUTH_LEAVING;
req.ie = NULL;
req.ie_len = 0;
if (wdev->current_bss) {
req.bss = &wdev->current_bss->pub;
rdev->ops->deauth(&rdev->wiphy, dev, &req, wdev);
if (wdev->current_bss) {
cfg80211_unhold_bss(wdev->current_bss);
cfg80211_put_bss(&wdev->current_bss->pub);
wdev->current_bss = NULL;
}
}
for (i = 0; i < MAX_AUTH_BSSES; i++) {
if (wdev->auth_bsses[i]) {
req.bss = &wdev->auth_bsses[i]->pub;
rdev->ops->deauth(&rdev->wiphy, dev, &req, wdev);
if (wdev->auth_bsses[i]) {
cfg80211_unhold_bss(wdev->auth_bsses[i]);
cfg80211_put_bss(&wdev->auth_bsses[i]->pub);
wdev->auth_bsses[i] = NULL;
}
}
if (wdev->authtry_bsses[i]) {
req.bss = &wdev->authtry_bsses[i]->pub;
rdev->ops->deauth(&rdev->wiphy, dev, &req, wdev);
if (wdev->authtry_bsses[i]) {
cfg80211_unhold_bss(wdev->authtry_bsses[i]);
cfg80211_put_bss(&wdev->authtry_bsses[i]->pub);
wdev->authtry_bsses[i] = NULL;
}
}
}
}
void cfg80211_ready_on_channel(struct net_device *dev, u64 cookie,
struct ieee80211_channel *chan,
enum nl80211_channel_type channel_type,
unsigned int duration, gfp_t gfp)
{
struct wiphy *wiphy = dev->ieee80211_ptr->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_remain_on_channel(rdev, dev, cookie, chan, channel_type,
duration, gfp);
}
void cfg80211_remain_on_channel_expired(struct net_device *dev,
u64 cookie,
struct ieee80211_channel *chan,
enum nl80211_channel_type channel_type,
gfp_t gfp)
{
struct wiphy *wiphy = dev->ieee80211_ptr->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_remain_on_channel_cancel(rdev, dev, cookie, chan,
channel_type, gfp);
}
void cfg80211_new_sta(struct net_device *dev, const u8 *mac_addr,
struct station_info *sinfo, gfp_t gfp)
{
struct wiphy *wiphy = dev->ieee80211_ptr->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_sta_event(rdev, dev, mac_addr, sinfo, gfp);
}
void cfg80211_del_sta(struct net_device *dev, const u8 *mac_addr, gfp_t gfp)
{
struct wiphy *wiphy = dev->ieee80211_ptr->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_sta_del_event(rdev, dev, mac_addr, gfp);
}
int cfg80211_mlme_register_mgmt(struct wireless_dev *wdev, u32 snd_pid,
u16 frame_type, const u8 *match_data,
int match_len)
{
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
struct cfg80211_mgmt_registration *reg, *nreg;
int err = 0;
u16 mgmt_type;
if (!wdev->wiphy->mgmt_stypes)
return -EOPNOTSUPP;
if ((frame_type & IEEE80211_FCTL_FTYPE) != IEEE80211_FTYPE_MGMT)
return -EINVAL;
if (frame_type & ~(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE))
return -EINVAL;
mgmt_type = (frame_type & IEEE80211_FCTL_STYPE) >> 4;
if (!(wdev->wiphy->mgmt_stypes[wdev->iftype].rx & BIT(mgmt_type)))
return -EINVAL;
nreg = kzalloc(sizeof(*reg) + match_len, GFP_KERNEL);
if (!nreg)
return -ENOMEM;
spin_lock_bh(&wdev->mgmt_registrations_lock);
list_for_each_entry(reg, &wdev->mgmt_registrations, list) {
int mlen = min(match_len, reg->match_len);
if (frame_type != le16_to_cpu(reg->frame_type))
continue;
if (memcmp(reg->match, match_data, mlen) == 0) {
err = -EALREADY;
break;
}
}
if (err) {
kfree(nreg);
goto out;
}
memcpy(nreg->match, match_data, match_len);
nreg->match_len = match_len;
nreg->nlpid = snd_pid;
nreg->frame_type = cpu_to_le16(frame_type);
list_add(&nreg->list, &wdev->mgmt_registrations);
if (rdev->ops->mgmt_frame_register)
rdev->ops->mgmt_frame_register(wiphy, wdev->netdev,
frame_type, true);
out:
spin_unlock_bh(&wdev->mgmt_registrations_lock);
return err;
}
void cfg80211_mlme_unregister_socket(struct wireless_dev *wdev, u32 nlpid)
{
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
struct cfg80211_mgmt_registration *reg, *tmp;
spin_lock_bh(&wdev->mgmt_registrations_lock);
list_for_each_entry_safe(reg, tmp, &wdev->mgmt_registrations, list) {
if (reg->nlpid != nlpid)
continue;
if (rdev->ops->mgmt_frame_register) {
u16 frame_type = le16_to_cpu(reg->frame_type);
rdev->ops->mgmt_frame_register(wiphy, wdev->netdev,
frame_type, false);
}
list_del(&reg->list);
kfree(reg);
}
spin_unlock_bh(&wdev->mgmt_registrations_lock);
if (nlpid == wdev->ap_unexpected_nlpid)
wdev->ap_unexpected_nlpid = 0;
}
void cfg80211_mlme_purge_registrations(struct wireless_dev *wdev)
{
struct cfg80211_mgmt_registration *reg, *tmp;
spin_lock_bh(&wdev->mgmt_registrations_lock);
list_for_each_entry_safe(reg, tmp, &wdev->mgmt_registrations, list) {
list_del(&reg->list);
kfree(reg);
}
spin_unlock_bh(&wdev->mgmt_registrations_lock);
}
int cfg80211_mlme_mgmt_tx(struct cfg80211_registered_device *rdev,
struct net_device *dev,
struct ieee80211_channel *chan, bool offchan,
enum nl80211_channel_type channel_type,
bool channel_type_valid, unsigned int wait,
const u8 *buf, size_t len, bool no_cck,
bool dont_wait_for_ack, u64 *cookie)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
const struct ieee80211_mgmt *mgmt;
u16 stype;
if (!wdev->wiphy->mgmt_stypes)
return -EOPNOTSUPP;
if (!rdev->ops->mgmt_tx)
return -EOPNOTSUPP;
if (len < 24 + 1)
return -EINVAL;
mgmt = (const struct ieee80211_mgmt *) buf;
if (!ieee80211_is_mgmt(mgmt->frame_control))
return -EINVAL;
stype = le16_to_cpu(mgmt->frame_control) & IEEE80211_FCTL_STYPE;
if (!(wdev->wiphy->mgmt_stypes[wdev->iftype].tx & BIT(stype >> 4)))
return -EINVAL;
if (ieee80211_is_action(mgmt->frame_control) &&
mgmt->u.action.category != WLAN_CATEGORY_PUBLIC) {
int err = 0;
wdev_lock(wdev);
switch (wdev->iftype) {
case NL80211_IFTYPE_ADHOC:
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_P2P_CLIENT:
if (!wdev->current_bss) {
err = -ENOTCONN;
break;
}
if (memcmp(wdev->current_bss->pub.bssid,
mgmt->bssid, ETH_ALEN)) {
err = -ENOTCONN;
break;
}
if (wdev->iftype == NL80211_IFTYPE_ADHOC)
break;
if (memcmp(wdev->current_bss->pub.bssid,
mgmt->da, ETH_ALEN)) {
err = -ENOTCONN;
break;
}
break;
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_P2P_GO:
case NL80211_IFTYPE_AP_VLAN:
if (memcmp(mgmt->bssid, dev->dev_addr, ETH_ALEN))
err = -EINVAL;
break;
case NL80211_IFTYPE_MESH_POINT:
if (memcmp(mgmt->sa, mgmt->bssid, ETH_ALEN)) {
err = -EINVAL;
break;
}
break;
default:
err = -EOPNOTSUPP;
break;
}
wdev_unlock(wdev);
if (err)
return err;
}
if (memcmp(mgmt->sa, dev->dev_addr, ETH_ALEN) != 0)
return -EINVAL;
return rdev->ops->mgmt_tx(&rdev->wiphy, dev, chan, offchan,
channel_type, channel_type_valid,
wait, buf, len, no_cck, dont_wait_for_ack,
cookie);
}
bool cfg80211_rx_mgmt(struct net_device *dev, int freq, const u8 *buf,
size_t len, gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
struct cfg80211_mgmt_registration *reg;
const struct ieee80211_txrx_stypes *stypes =
&wiphy->mgmt_stypes[wdev->iftype];
struct ieee80211_mgmt *mgmt = (void *)buf;
const u8 *data;
int data_len;
bool result = false;
__le16 ftype = mgmt->frame_control &
cpu_to_le16(IEEE80211_FCTL_FTYPE | IEEE80211_FCTL_STYPE);
u16 stype;
stype = (le16_to_cpu(mgmt->frame_control) & IEEE80211_FCTL_STYPE) >> 4;
if (!(stypes->rx & BIT(stype)))
return false;
data = buf + ieee80211_hdrlen(mgmt->frame_control);
data_len = len - ieee80211_hdrlen(mgmt->frame_control);
spin_lock_bh(&wdev->mgmt_registrations_lock);
list_for_each_entry(reg, &wdev->mgmt_registrations, list) {
if (reg->frame_type != ftype)
continue;
if (reg->match_len > data_len)
continue;
if (memcmp(reg->match, data, reg->match_len))
continue;
if (nl80211_send_mgmt(rdev, dev, reg->nlpid, freq,
buf, len, gfp))
continue;
result = true;
break;
}
spin_unlock_bh(&wdev->mgmt_registrations_lock);
return result;
}
void cfg80211_mgmt_tx_status(struct net_device *dev, u64 cookie,
const u8 *buf, size_t len, bool ack, gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_mgmt_tx_status(rdev, dev, cookie, buf, len, ack, gfp);
}
void cfg80211_cqm_rssi_notify(struct net_device *dev,
enum nl80211_cqm_rssi_threshold_event rssi_event,
gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_cqm_rssi_notify(rdev, dev, rssi_event, gfp);
}
void cfg80211_cqm_pktloss_notify(struct net_device *dev,
const u8 *peer, u32 num_packets, gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_send_cqm_pktloss_notify(rdev, dev, peer, num_packets, gfp);
}
void cfg80211_gtk_rekey_notify(struct net_device *dev, const u8 *bssid,
const u8 *replay_ctr, gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_gtk_rekey_notify(rdev, dev, bssid, replay_ctr, gfp);
}
void cfg80211_pmksa_candidate_notify(struct net_device *dev, int index,
const u8 *bssid, bool preauth, gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
struct wiphy *wiphy = wdev->wiphy;
struct cfg80211_registered_device *rdev = wiphy_to_dev(wiphy);
nl80211_pmksa_candidate_notify(rdev, dev, index, bssid, preauth, gfp);
}
bool cfg80211_rx_spurious_frame(struct net_device *dev,
const u8 *addr, gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
if (WARN_ON(wdev->iftype != NL80211_IFTYPE_AP &&
wdev->iftype != NL80211_IFTYPE_P2P_GO))
return false;
return nl80211_unexpected_frame(dev, addr, gfp);
}
bool cfg80211_rx_unexpected_4addr_frame(struct net_device *dev,
const u8 *addr, gfp_t gfp)
{
struct wireless_dev *wdev = dev->ieee80211_ptr;
if (WARN_ON(wdev->iftype != NL80211_IFTYPE_AP &&
wdev->iftype != NL80211_IFTYPE_P2P_GO &&
wdev->iftype != NL80211_IFTYPE_AP_VLAN))
return false;
return nl80211_unexpected_4addr_frame(dev, addr, gfp);
}
