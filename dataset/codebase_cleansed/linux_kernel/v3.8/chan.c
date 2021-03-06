void cfg80211_chandef_create(struct cfg80211_chan_def *chandef,
struct ieee80211_channel *chan,
enum nl80211_channel_type chan_type)
{
if (WARN_ON(!chan))
return;
chandef->chan = chan;
chandef->center_freq2 = 0;
switch (chan_type) {
case NL80211_CHAN_NO_HT:
chandef->width = NL80211_CHAN_WIDTH_20_NOHT;
chandef->center_freq1 = chan->center_freq;
break;
case NL80211_CHAN_HT20:
chandef->width = NL80211_CHAN_WIDTH_20;
chandef->center_freq1 = chan->center_freq;
break;
case NL80211_CHAN_HT40PLUS:
chandef->width = NL80211_CHAN_WIDTH_40;
chandef->center_freq1 = chan->center_freq + 10;
break;
case NL80211_CHAN_HT40MINUS:
chandef->width = NL80211_CHAN_WIDTH_40;
chandef->center_freq1 = chan->center_freq - 10;
break;
default:
WARN_ON(1);
}
}
bool cfg80211_chandef_valid(const struct cfg80211_chan_def *chandef)
{
u32 control_freq;
if (!chandef->chan)
return false;
control_freq = chandef->chan->center_freq;
switch (chandef->width) {
case NL80211_CHAN_WIDTH_20:
case NL80211_CHAN_WIDTH_20_NOHT:
if (chandef->center_freq1 != control_freq)
return false;
if (chandef->center_freq2)
return false;
break;
case NL80211_CHAN_WIDTH_40:
if (chandef->center_freq1 != control_freq + 10 &&
chandef->center_freq1 != control_freq - 10)
return false;
if (chandef->center_freq2)
return false;
break;
case NL80211_CHAN_WIDTH_80P80:
if (chandef->center_freq1 != control_freq + 30 &&
chandef->center_freq1 != control_freq + 10 &&
chandef->center_freq1 != control_freq - 10 &&
chandef->center_freq1 != control_freq - 30)
return false;
if (!chandef->center_freq2)
return false;
break;
case NL80211_CHAN_WIDTH_80:
if (chandef->center_freq1 != control_freq + 30 &&
chandef->center_freq1 != control_freq + 10 &&
chandef->center_freq1 != control_freq - 10 &&
chandef->center_freq1 != control_freq - 30)
return false;
if (chandef->center_freq2)
return false;
break;
case NL80211_CHAN_WIDTH_160:
if (chandef->center_freq1 != control_freq + 70 &&
chandef->center_freq1 != control_freq + 50 &&
chandef->center_freq1 != control_freq + 30 &&
chandef->center_freq1 != control_freq + 10 &&
chandef->center_freq1 != control_freq - 10 &&
chandef->center_freq1 != control_freq - 30 &&
chandef->center_freq1 != control_freq - 50 &&
chandef->center_freq1 != control_freq - 70)
return false;
if (chandef->center_freq2)
return false;
break;
default:
return false;
}
return true;
}
static void chandef_primary_freqs(const struct cfg80211_chan_def *c,
int *pri40, int *pri80)
{
int tmp;
switch (c->width) {
case NL80211_CHAN_WIDTH_40:
*pri40 = c->center_freq1;
*pri80 = 0;
break;
case NL80211_CHAN_WIDTH_80:
case NL80211_CHAN_WIDTH_80P80:
*pri80 = c->center_freq1;
tmp = (30 + c->chan->center_freq - c->center_freq1)/20;
tmp /= 2;
*pri40 = c->center_freq1 - 20 + 40 * tmp;
break;
case NL80211_CHAN_WIDTH_160:
tmp = (70 + c->chan->center_freq - c->center_freq1)/20;
tmp /= 2;
*pri40 = c->center_freq1 - 60 + 40 * tmp;
tmp /= 2;
*pri80 = c->center_freq1 - 40 + 80 * tmp;
break;
default:
WARN_ON_ONCE(1);
}
}
const struct cfg80211_chan_def *
cfg80211_chandef_compatible(const struct cfg80211_chan_def *c1,
const struct cfg80211_chan_def *c2)
{
u32 c1_pri40, c1_pri80, c2_pri40, c2_pri80;
if (cfg80211_chandef_identical(c1, c2))
return c1;
if (c1->chan != c2->chan)
return NULL;
if (c1->width == c2->width)
return NULL;
if (c1->width == NL80211_CHAN_WIDTH_20_NOHT ||
c1->width == NL80211_CHAN_WIDTH_20)
return c2;
if (c2->width == NL80211_CHAN_WIDTH_20_NOHT ||
c2->width == NL80211_CHAN_WIDTH_20)
return c1;
chandef_primary_freqs(c1, &c1_pri40, &c1_pri80);
chandef_primary_freqs(c2, &c2_pri40, &c2_pri80);
if (c1_pri40 != c2_pri40)
return NULL;
WARN_ON(!c1_pri80 && !c2_pri80);
if (c1_pri80 && c2_pri80 && c1_pri80 != c2_pri80)
return NULL;
if (c1->width > c2->width)
return c1;
return c2;
}
static bool cfg80211_secondary_chans_ok(struct wiphy *wiphy,
u32 center_freq, u32 bandwidth,
u32 prohibited_flags)
{
struct ieee80211_channel *c;
u32 freq;
for (freq = center_freq - bandwidth/2 + 10;
freq <= center_freq + bandwidth/2 - 10;
freq += 20) {
c = ieee80211_get_channel(wiphy, freq);
if (!c || c->flags & prohibited_flags)
return false;
}
return true;
}
bool cfg80211_chandef_usable(struct wiphy *wiphy,
const struct cfg80211_chan_def *chandef,
u32 prohibited_flags)
{
struct ieee80211_sta_ht_cap *ht_cap;
struct ieee80211_sta_vht_cap *vht_cap;
u32 width, control_freq;
if (WARN_ON(!cfg80211_chandef_valid(chandef)))
return false;
ht_cap = &wiphy->bands[chandef->chan->band]->ht_cap;
vht_cap = &wiphy->bands[chandef->chan->band]->vht_cap;
control_freq = chandef->chan->center_freq;
switch (chandef->width) {
case NL80211_CHAN_WIDTH_20:
if (!ht_cap->ht_supported)
return false;
case NL80211_CHAN_WIDTH_20_NOHT:
width = 20;
break;
case NL80211_CHAN_WIDTH_40:
width = 40;
if (!ht_cap->ht_supported)
return false;
if (!(ht_cap->cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40) ||
ht_cap->cap & IEEE80211_HT_CAP_40MHZ_INTOLERANT)
return false;
if (chandef->center_freq1 < control_freq &&
chandef->chan->flags & IEEE80211_CHAN_NO_HT40MINUS)
return false;
if (chandef->center_freq1 > control_freq &&
chandef->chan->flags & IEEE80211_CHAN_NO_HT40PLUS)
return false;
break;
case NL80211_CHAN_WIDTH_80P80:
if (!(vht_cap->cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160_80PLUS80MHZ))
return false;
case NL80211_CHAN_WIDTH_80:
if (!vht_cap->vht_supported)
return false;
width = 80;
break;
case NL80211_CHAN_WIDTH_160:
if (!vht_cap->vht_supported)
return false;
if (!(vht_cap->cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ))
return false;
width = 160;
break;
default:
WARN_ON_ONCE(1);
return false;
}
if (width > 20)
prohibited_flags |= IEEE80211_CHAN_NO_OFDM;
if (!cfg80211_secondary_chans_ok(wiphy, chandef->center_freq1,
width, prohibited_flags))
return false;
if (!chandef->center_freq2)
return true;
return cfg80211_secondary_chans_ok(wiphy, chandef->center_freq2,
width, prohibited_flags);
}
bool cfg80211_reg_can_beacon(struct wiphy *wiphy,
struct cfg80211_chan_def *chandef)
{
bool res;
trace_cfg80211_reg_can_beacon(wiphy, chandef);
res = cfg80211_chandef_usable(wiphy, chandef,
IEEE80211_CHAN_DISABLED |
IEEE80211_CHAN_PASSIVE_SCAN |
IEEE80211_CHAN_NO_IBSS |
IEEE80211_CHAN_RADAR);
trace_cfg80211_return_bool(res);
return res;
}
int cfg80211_set_monitor_channel(struct cfg80211_registered_device *rdev,
struct cfg80211_chan_def *chandef)
{
if (!rdev->ops->set_monitor_channel)
return -EOPNOTSUPP;
if (!cfg80211_has_monitors_only(rdev))
return -EBUSY;
return rdev_set_monitor_channel(rdev, chandef);
}
void
cfg80211_get_chan_state(struct wireless_dev *wdev,
struct ieee80211_channel **chan,
enum cfg80211_chan_mode *chanmode)
{
*chan = NULL;
*chanmode = CHAN_MODE_UNDEFINED;
ASSERT_WDEV_LOCK(wdev);
if (wdev->netdev && !netif_running(wdev->netdev))
return;
switch (wdev->iftype) {
case NL80211_IFTYPE_ADHOC:
if (wdev->current_bss) {
*chan = wdev->current_bss->pub.channel;
*chanmode = wdev->ibss_fixed
? CHAN_MODE_SHARED
: CHAN_MODE_EXCLUSIVE;
return;
}
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_P2P_CLIENT:
if (wdev->current_bss) {
*chan = wdev->current_bss->pub.channel;
*chanmode = CHAN_MODE_SHARED;
return;
}
break;
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_P2P_GO:
if (wdev->beacon_interval) {
*chan = wdev->channel;
*chanmode = CHAN_MODE_SHARED;
}
return;
case NL80211_IFTYPE_MESH_POINT:
if (wdev->mesh_id_len) {
*chan = wdev->channel;
*chanmode = CHAN_MODE_SHARED;
}
return;
case NL80211_IFTYPE_MONITOR:
case NL80211_IFTYPE_AP_VLAN:
case NL80211_IFTYPE_WDS:
return;
case NL80211_IFTYPE_P2P_DEVICE:
if (wdev->wiphy->features &
NL80211_FEATURE_P2P_DEVICE_NEEDS_CHANNEL)
*chanmode = CHAN_MODE_EXCLUSIVE;
return;
case NL80211_IFTYPE_UNSPECIFIED:
case NUM_NL80211_IFTYPES:
WARN_ON(1);
}
return;
}
