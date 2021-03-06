void rt2x00lib_config_intf(struct rt2x00_dev *rt2x00dev,
struct rt2x00_intf *intf,
enum nl80211_iftype type,
const u8 *mac, const u8 *bssid)
{
struct rt2x00intf_conf conf;
unsigned int flags = 0;
conf.type = type;
switch (type) {
case NL80211_IFTYPE_ADHOC:
conf.sync = TSF_SYNC_ADHOC;
break;
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_MESH_POINT:
case NL80211_IFTYPE_WDS:
conf.sync = TSF_SYNC_AP_NONE;
break;
case NL80211_IFTYPE_STATION:
conf.sync = TSF_SYNC_INFRA;
break;
default:
conf.sync = TSF_SYNC_NONE;
break;
}
memset(conf.mac, 0, sizeof(conf.mac));
if (mac)
memcpy(conf.mac, mac, ETH_ALEN);
memset(conf.bssid, 0, sizeof(conf.bssid));
if (bssid)
memcpy(conf.bssid, bssid, ETH_ALEN);
flags |= CONFIG_UPDATE_TYPE;
if (mac || (!rt2x00dev->intf_ap_count && !rt2x00dev->intf_sta_count))
flags |= CONFIG_UPDATE_MAC;
if (bssid || (!rt2x00dev->intf_ap_count && !rt2x00dev->intf_sta_count))
flags |= CONFIG_UPDATE_BSSID;
rt2x00dev->ops->lib->config_intf(rt2x00dev, intf, &conf, flags);
}
void rt2x00lib_config_erp(struct rt2x00_dev *rt2x00dev,
struct rt2x00_intf *intf,
struct ieee80211_bss_conf *bss_conf,
u32 changed)
{
struct rt2x00lib_erp erp;
memset(&erp, 0, sizeof(erp));
erp.short_preamble = bss_conf->use_short_preamble;
erp.cts_protection = bss_conf->use_cts_prot;
erp.slot_time = bss_conf->use_short_slot ? SHORT_SLOT_TIME : SLOT_TIME;
erp.sifs = SIFS;
erp.pifs = bss_conf->use_short_slot ? SHORT_PIFS : PIFS;
erp.difs = bss_conf->use_short_slot ? SHORT_DIFS : DIFS;
erp.eifs = bss_conf->use_short_slot ? SHORT_EIFS : EIFS;
erp.basic_rates = bss_conf->basic_rates;
erp.beacon_int = bss_conf->beacon_int;
rt2x00dev->aid = bss_conf->assoc ? bss_conf->aid : 0;
rt2x00dev->last_beacon = bss_conf->timestamp;
rt2x00dev->beacon_int = bss_conf->beacon_int;
if (changed & BSS_CHANGED_HT)
erp.ht_opmode = bss_conf->ht_operation_mode;
rt2x00dev->ops->lib->config_erp(rt2x00dev, &erp, changed);
}
void rt2x00lib_config_antenna(struct rt2x00_dev *rt2x00dev,
struct antenna_setup config)
{
struct link_ant *ant = &rt2x00dev->link.ant;
struct antenna_setup *def = &rt2x00dev->default_ant;
struct antenna_setup *active = &rt2x00dev->link.ant.active;
if (!(ant->flags & ANTENNA_RX_DIVERSITY)) {
if (config.rx == ANTENNA_SW_DIVERSITY) {
ant->flags |= ANTENNA_RX_DIVERSITY;
if (def->rx == ANTENNA_SW_DIVERSITY)
config.rx = ANTENNA_B;
else
config.rx = def->rx;
}
} else if (config.rx == ANTENNA_SW_DIVERSITY)
config.rx = active->rx;
if (!(ant->flags & ANTENNA_TX_DIVERSITY)) {
if (config.tx == ANTENNA_SW_DIVERSITY) {
ant->flags |= ANTENNA_TX_DIVERSITY;
if (def->tx == ANTENNA_SW_DIVERSITY)
config.tx = ANTENNA_B;
else
config.tx = def->tx;
}
} else if (config.tx == ANTENNA_SW_DIVERSITY)
config.tx = active->tx;
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2x00queue_stop_queue(rt2x00dev->rx);
rt2x00dev->ops->lib->config_ant(rt2x00dev, &config);
rt2x00link_reset_tuner(rt2x00dev, true);
memcpy(active, &config, sizeof(config));
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2x00queue_start_queue(rt2x00dev->rx);
}
static u16 rt2x00ht_center_channel(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf)
{
struct hw_mode_spec *spec = &rt2x00dev->spec;
int center_channel;
u16 i;
center_channel = spec->channels[conf->channel->hw_value].channel;
if (conf_is_ht40_plus(conf))
center_channel += 2;
else if (conf_is_ht40_minus(conf))
center_channel -= (center_channel == 14) ? 1 : 2;
for (i = 0; i < spec->num_channels; i++)
if (spec->channels[i].channel == center_channel)
return i;
WARN_ON(1);
return conf->channel->hw_value;
}
void rt2x00lib_config(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf,
unsigned int ieee80211_flags)
{
struct rt2x00lib_conf libconf;
u16 hw_value;
u16 autowake_timeout;
u16 beacon_int;
u16 beacon_diff;
memset(&libconf, 0, sizeof(libconf));
libconf.conf = conf;
if (ieee80211_flags & IEEE80211_CONF_CHANGE_CHANNEL) {
if (conf_is_ht40(conf)) {
set_bit(CONFIG_CHANNEL_HT40, &rt2x00dev->flags);
hw_value = rt2x00ht_center_channel(rt2x00dev, conf);
} else {
clear_bit(CONFIG_CHANNEL_HT40, &rt2x00dev->flags);
hw_value = conf->channel->hw_value;
}
memcpy(&libconf.rf,
&rt2x00dev->spec.channels[hw_value],
sizeof(libconf.rf));
memcpy(&libconf.channel,
&rt2x00dev->spec.channels_info[hw_value],
sizeof(libconf.channel));
}
if (test_bit(REQUIRE_PS_AUTOWAKE, &rt2x00dev->cap_flags) &&
(ieee80211_flags & IEEE80211_CONF_CHANGE_PS))
cancel_delayed_work_sync(&rt2x00dev->autowakeup_work);
rt2x00dev->ops->lib->config(rt2x00dev, &libconf, ieee80211_flags);
if (ieee80211_flags & IEEE80211_CONF_CHANGE_CHANNEL)
rt2x00link_reset_tuner(rt2x00dev, false);
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags) &&
test_bit(REQUIRE_PS_AUTOWAKE, &rt2x00dev->cap_flags) &&
(ieee80211_flags & IEEE80211_CONF_CHANGE_PS) &&
(conf->flags & IEEE80211_CONF_PS)) {
beacon_diff = (long)jiffies - (long)rt2x00dev->last_beacon;
beacon_int = msecs_to_jiffies(rt2x00dev->beacon_int);
if (beacon_diff > beacon_int)
beacon_diff = 0;
autowake_timeout = (conf->max_sleep_period * beacon_int) - beacon_diff;
queue_delayed_work(rt2x00dev->workqueue,
&rt2x00dev->autowakeup_work,
autowake_timeout - 15);
}
if (conf->flags & IEEE80211_CONF_PS)
set_bit(CONFIG_POWERSAVING, &rt2x00dev->flags);
else
clear_bit(CONFIG_POWERSAVING, &rt2x00dev->flags);
rt2x00dev->curr_band = conf->channel->band;
rt2x00dev->curr_freq = conf->channel->center_freq;
rt2x00dev->tx_power = conf->power_level;
rt2x00dev->short_retry = conf->short_frame_max_tx_count;
rt2x00dev->long_retry = conf->long_frame_max_tx_count;
}
