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
case NL80211_CHAN_WIDTH_5:
case NL80211_CHAN_WIDTH_10:
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
if (chandef->center_freq1 - chandef->center_freq2 == 80 ||
chandef->center_freq2 - chandef->center_freq1 == 80)
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
static int cfg80211_chandef_get_width(const struct cfg80211_chan_def *c)
{
int width;
switch (c->width) {
case NL80211_CHAN_WIDTH_5:
width = 5;
break;
case NL80211_CHAN_WIDTH_10:
width = 10;
break;
case NL80211_CHAN_WIDTH_20:
case NL80211_CHAN_WIDTH_20_NOHT:
width = 20;
break;
case NL80211_CHAN_WIDTH_40:
width = 40;
break;
case NL80211_CHAN_WIDTH_80P80:
case NL80211_CHAN_WIDTH_80:
width = 80;
break;
case NL80211_CHAN_WIDTH_160:
width = 160;
break;
default:
WARN_ON_ONCE(1);
return -1;
}
return width;
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
if (c1->width == NL80211_CHAN_WIDTH_5 ||
c1->width == NL80211_CHAN_WIDTH_10 ||
c2->width == NL80211_CHAN_WIDTH_5 ||
c2->width == NL80211_CHAN_WIDTH_10)
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
static void cfg80211_set_chans_dfs_state(struct wiphy *wiphy, u32 center_freq,
u32 bandwidth,
enum nl80211_dfs_state dfs_state)
{
struct ieee80211_channel *c;
u32 freq;
for (freq = center_freq - bandwidth/2 + 10;
freq <= center_freq + bandwidth/2 - 10;
freq += 20) {
c = ieee80211_get_channel(wiphy, freq);
if (!c || !(c->flags & IEEE80211_CHAN_RADAR))
continue;
c->dfs_state = dfs_state;
c->dfs_state_entered = jiffies;
}
}
void cfg80211_set_dfs_state(struct wiphy *wiphy,
const struct cfg80211_chan_def *chandef,
enum nl80211_dfs_state dfs_state)
{
int width;
if (WARN_ON(!cfg80211_chandef_valid(chandef)))
return;
width = cfg80211_chandef_get_width(chandef);
if (width < 0)
return;
cfg80211_set_chans_dfs_state(wiphy, chandef->center_freq1,
width, dfs_state);
if (!chandef->center_freq2)
return;
cfg80211_set_chans_dfs_state(wiphy, chandef->center_freq2,
width, dfs_state);
}
static u32 cfg80211_get_start_freq(u32 center_freq,
u32 bandwidth)
{
u32 start_freq;
if (bandwidth <= 20)
start_freq = center_freq;
else
start_freq = center_freq - bandwidth/2 + 10;
return start_freq;
}
static u32 cfg80211_get_end_freq(u32 center_freq,
u32 bandwidth)
{
u32 end_freq;
if (bandwidth <= 20)
end_freq = center_freq;
else
end_freq = center_freq + bandwidth/2 - 10;
return end_freq;
}
static int cfg80211_get_chans_dfs_required(struct wiphy *wiphy,
u32 center_freq,
u32 bandwidth)
{
struct ieee80211_channel *c;
u32 freq, start_freq, end_freq;
start_freq = cfg80211_get_start_freq(center_freq, bandwidth);
end_freq = cfg80211_get_end_freq(center_freq, bandwidth);
for (freq = start_freq; freq <= end_freq; freq += 20) {
c = ieee80211_get_channel(wiphy, freq);
if (!c)
return -EINVAL;
if (c->flags & IEEE80211_CHAN_RADAR)
return 1;
}
return 0;
}
int cfg80211_chandef_dfs_required(struct wiphy *wiphy,
const struct cfg80211_chan_def *chandef)
{
int width;
int r;
if (WARN_ON(!cfg80211_chandef_valid(chandef)))
return -EINVAL;
width = cfg80211_chandef_get_width(chandef);
if (width < 0)
return -EINVAL;
r = cfg80211_get_chans_dfs_required(wiphy, chandef->center_freq1,
width);
if (r)
return r;
if (!chandef->center_freq2)
return 0;
return cfg80211_get_chans_dfs_required(wiphy, chandef->center_freq2,
width);
}
static int cfg80211_get_chans_dfs_usable(struct wiphy *wiphy,
u32 center_freq,
u32 bandwidth)
{
struct ieee80211_channel *c;
u32 freq, start_freq, end_freq;
int count = 0;
start_freq = cfg80211_get_start_freq(center_freq, bandwidth);
end_freq = cfg80211_get_end_freq(center_freq, bandwidth);
for (freq = start_freq; freq <= end_freq; freq += 20) {
c = ieee80211_get_channel(wiphy, freq);
if (!c)
return -EINVAL;
if (c->flags & IEEE80211_CHAN_DISABLED)
return -EINVAL;
if (c->flags & IEEE80211_CHAN_RADAR) {
if (c->dfs_state == NL80211_DFS_UNAVAILABLE)
return -EINVAL;
if (c->dfs_state == NL80211_DFS_USABLE)
count++;
}
}
return count;
}
bool cfg80211_chandef_dfs_usable(struct wiphy *wiphy,
const struct cfg80211_chan_def *chandef)
{
int width;
int r1, r2 = 0;
if (WARN_ON(!cfg80211_chandef_valid(chandef)))
return false;
width = cfg80211_chandef_get_width(chandef);
if (width < 0)
return false;
r1 = cfg80211_get_chans_dfs_usable(wiphy, chandef->center_freq1,
width);
if (r1 < 0)
return false;
switch (chandef->width) {
case NL80211_CHAN_WIDTH_80P80:
WARN_ON(!chandef->center_freq2);
r2 = cfg80211_get_chans_dfs_usable(wiphy,
chandef->center_freq2,
width);
if (r2 < 0)
return false;
break;
default:
WARN_ON(chandef->center_freq2);
break;
}
return (r1 + r2 > 0);
}
static bool cfg80211_get_chans_dfs_available(struct wiphy *wiphy,
u32 center_freq,
u32 bandwidth)
{
struct ieee80211_channel *c;
u32 freq, start_freq, end_freq;
start_freq = cfg80211_get_start_freq(center_freq, bandwidth);
end_freq = cfg80211_get_end_freq(center_freq, bandwidth);
for (freq = start_freq; freq <= end_freq; freq += 20) {
c = ieee80211_get_channel(wiphy, freq);
if (!c)
return false;
if (c->flags & IEEE80211_CHAN_DISABLED)
return false;
if ((c->flags & IEEE80211_CHAN_RADAR) &&
(c->dfs_state != NL80211_DFS_AVAILABLE))
return false;
}
return true;
}
static bool cfg80211_chandef_dfs_available(struct wiphy *wiphy,
const struct cfg80211_chan_def *chandef)
{
int width;
int r;
if (WARN_ON(!cfg80211_chandef_valid(chandef)))
return false;
width = cfg80211_chandef_get_width(chandef);
if (width < 0)
return false;
r = cfg80211_get_chans_dfs_available(wiphy, chandef->center_freq1,
width);
if (!r)
return r;
switch (chandef->width) {
case NL80211_CHAN_WIDTH_80P80:
WARN_ON(!chandef->center_freq2);
r = cfg80211_get_chans_dfs_available(wiphy,
chandef->center_freq2,
width);
default:
WARN_ON(chandef->center_freq2);
break;
}
return r;
}
static unsigned int cfg80211_get_chans_dfs_cac_time(struct wiphy *wiphy,
u32 center_freq,
u32 bandwidth)
{
struct ieee80211_channel *c;
u32 start_freq, end_freq, freq;
unsigned int dfs_cac_ms = 0;
start_freq = cfg80211_get_start_freq(center_freq, bandwidth);
end_freq = cfg80211_get_end_freq(center_freq, bandwidth);
for (freq = start_freq; freq <= end_freq; freq += 20) {
c = ieee80211_get_channel(wiphy, freq);
if (!c)
return 0;
if (c->flags & IEEE80211_CHAN_DISABLED)
return 0;
if (!(c->flags & IEEE80211_CHAN_RADAR))
continue;
if (c->dfs_cac_ms > dfs_cac_ms)
dfs_cac_ms = c->dfs_cac_ms;
}
return dfs_cac_ms;
}
unsigned int
cfg80211_chandef_dfs_cac_time(struct wiphy *wiphy,
const struct cfg80211_chan_def *chandef)
{
int width;
unsigned int t1 = 0, t2 = 0;
if (WARN_ON(!cfg80211_chandef_valid(chandef)))
return 0;
width = cfg80211_chandef_get_width(chandef);
if (width < 0)
return 0;
t1 = cfg80211_get_chans_dfs_cac_time(wiphy,
chandef->center_freq1,
width);
if (!chandef->center_freq2)
return t1;
t2 = cfg80211_get_chans_dfs_cac_time(wiphy,
chandef->center_freq2,
width);
return max(t1, t2);
}
static bool cfg80211_secondary_chans_ok(struct wiphy *wiphy,
u32 center_freq, u32 bandwidth,
u32 prohibited_flags)
{
struct ieee80211_channel *c;
u32 freq, start_freq, end_freq;
start_freq = cfg80211_get_start_freq(center_freq, bandwidth);
end_freq = cfg80211_get_end_freq(center_freq, bandwidth);
for (freq = start_freq; freq <= end_freq; freq += 20) {
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
case NL80211_CHAN_WIDTH_5:
width = 5;
break;
case NL80211_CHAN_WIDTH_10:
width = 10;
break;
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
prohibited_flags |= IEEE80211_CHAN_NO_80MHZ;
width = 80;
break;
case NL80211_CHAN_WIDTH_160:
if (!vht_cap->vht_supported)
return false;
if (!(vht_cap->cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ))
return false;
prohibited_flags |= IEEE80211_CHAN_NO_160MHZ;
width = 160;
break;
default:
WARN_ON_ONCE(1);
return false;
}
if (width > 20)
prohibited_flags |= IEEE80211_CHAN_NO_OFDM;
if (width < 20)
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
u32 prohibited_flags = IEEE80211_CHAN_DISABLED |
IEEE80211_CHAN_NO_IR |
IEEE80211_CHAN_RADAR;
trace_cfg80211_reg_can_beacon(wiphy, chandef);
if (cfg80211_chandef_dfs_required(wiphy, chandef) > 0 &&
cfg80211_chandef_dfs_available(wiphy, chandef)) {
prohibited_flags = IEEE80211_CHAN_DISABLED;
}
res = cfg80211_chandef_usable(wiphy, chandef, prohibited_flags);
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
enum cfg80211_chan_mode *chanmode,
u8 *radar_detect)
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
*chanmode = (wdev->ibss_fixed &&
!wdev->ibss_dfs_possible)
? CHAN_MODE_SHARED
: CHAN_MODE_EXCLUSIVE;
if (wdev->ibss_dfs_possible)
*radar_detect |= BIT(wdev->chandef.width);
return;
}
break;
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
if (wdev->cac_started) {
*chan = wdev->chandef.chan;
*chanmode = CHAN_MODE_SHARED;
*radar_detect |= BIT(wdev->chandef.width);
} else if (wdev->beacon_interval) {
*chan = wdev->chandef.chan;
*chanmode = CHAN_MODE_SHARED;
if (cfg80211_chandef_dfs_required(wdev->wiphy,
&wdev->chandef))
*radar_detect |= BIT(wdev->chandef.width);
}
return;
case NL80211_IFTYPE_MESH_POINT:
if (wdev->mesh_id_len) {
*chan = wdev->chandef.chan;
*chanmode = CHAN_MODE_SHARED;
if (cfg80211_chandef_dfs_required(wdev->wiphy,
&wdev->chandef))
*radar_detect |= BIT(wdev->chandef.width);
}
return;
case NL80211_IFTYPE_MONITOR:
case NL80211_IFTYPE_AP_VLAN:
case NL80211_IFTYPE_WDS:
case NL80211_IFTYPE_P2P_DEVICE:
return;
case NL80211_IFTYPE_UNSPECIFIED:
case NUM_NL80211_IFTYPES:
WARN_ON(1);
}
}
