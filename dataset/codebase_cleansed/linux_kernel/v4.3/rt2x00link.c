static inline int rt2x00link_get_avg_rssi(struct ewma_rssi *ewma)
{
unsigned long avg;
avg = ewma_rssi_read(ewma);
if (avg)
return -avg;
return DEFAULT_RSSI;
}
static int rt2x00link_antenna_get_link_rssi(struct rt2x00_dev *rt2x00dev)
{
struct link_ant *ant = &rt2x00dev->link.ant;
if (rt2x00dev->link.qual.rx_success)
return rt2x00link_get_avg_rssi(&ant->rssi_ant);
return DEFAULT_RSSI;
}
static int rt2x00link_antenna_get_rssi_history(struct rt2x00_dev *rt2x00dev)
{
struct link_ant *ant = &rt2x00dev->link.ant;
if (ant->rssi_history)
return ant->rssi_history;
return DEFAULT_RSSI;
}
static void rt2x00link_antenna_update_rssi_history(struct rt2x00_dev *rt2x00dev,
int rssi)
{
struct link_ant *ant = &rt2x00dev->link.ant;
ant->rssi_history = rssi;
}
static void rt2x00link_antenna_reset(struct rt2x00_dev *rt2x00dev)
{
ewma_rssi_init(&rt2x00dev->link.ant.rssi_ant);
}
static void rt2x00lib_antenna_diversity_sample(struct rt2x00_dev *rt2x00dev)
{
struct link_ant *ant = &rt2x00dev->link.ant;
struct antenna_setup new_ant;
int other_antenna;
int sample_current = rt2x00link_antenna_get_link_rssi(rt2x00dev);
int sample_other = rt2x00link_antenna_get_rssi_history(rt2x00dev);
memcpy(&new_ant, &ant->active, sizeof(new_ant));
ant->flags &= ~ANTENNA_MODE_SAMPLE;
if (sample_current >= sample_other) {
rt2x00link_antenna_update_rssi_history(rt2x00dev,
sample_current);
return;
}
other_antenna = (ant->active.rx == ANTENNA_A) ? ANTENNA_B : ANTENNA_A;
if (ant->flags & ANTENNA_RX_DIVERSITY)
new_ant.rx = other_antenna;
if (ant->flags & ANTENNA_TX_DIVERSITY)
new_ant.tx = other_antenna;
rt2x00lib_config_antenna(rt2x00dev, new_ant);
}
static void rt2x00lib_antenna_diversity_eval(struct rt2x00_dev *rt2x00dev)
{
struct link_ant *ant = &rt2x00dev->link.ant;
struct antenna_setup new_ant;
int rssi_curr;
int rssi_old;
memcpy(&new_ant, &ant->active, sizeof(new_ant));
rssi_curr = rt2x00link_antenna_get_link_rssi(rt2x00dev);
rssi_old = rt2x00link_antenna_get_rssi_history(rt2x00dev);
rt2x00link_antenna_update_rssi_history(rt2x00dev, rssi_curr);
if (abs(rssi_curr - rssi_old) < 5)
return;
ant->flags |= ANTENNA_MODE_SAMPLE;
if (ant->flags & ANTENNA_RX_DIVERSITY)
new_ant.rx = (new_ant.rx == ANTENNA_A) ? ANTENNA_B : ANTENNA_A;
if (ant->flags & ANTENNA_TX_DIVERSITY)
new_ant.tx = (new_ant.tx == ANTENNA_A) ? ANTENNA_B : ANTENNA_A;
rt2x00lib_config_antenna(rt2x00dev, new_ant);
}
static bool rt2x00lib_antenna_diversity(struct rt2x00_dev *rt2x00dev)
{
struct link_ant *ant = &rt2x00dev->link.ant;
if (!(ant->flags & ANTENNA_RX_DIVERSITY) &&
!(ant->flags & ANTENNA_TX_DIVERSITY)) {
ant->flags = 0;
return true;
}
if (ant->flags & ANTENNA_MODE_SAMPLE) {
rt2x00lib_antenna_diversity_sample(rt2x00dev);
return true;
} else if (rt2x00dev->link.count & 1) {
rt2x00lib_antenna_diversity_eval(rt2x00dev);
return true;
}
return false;
}
void rt2x00link_update_stats(struct rt2x00_dev *rt2x00dev,
struct sk_buff *skb,
struct rxdone_entry_desc *rxdesc)
{
struct link *link = &rt2x00dev->link;
struct link_qual *qual = &rt2x00dev->link.qual;
struct link_ant *ant = &rt2x00dev->link.ant;
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
if (!rt2x00dev->intf_sta_count)
return;
qual->rx_success++;
if (!ieee80211_is_beacon(hdr->frame_control) ||
!(rxdesc->dev_flags & RXDONE_MY_BSS))
return;
ewma_rssi_add(&link->avg_rssi, -rxdesc->rssi);
ewma_rssi_add(&ant->rssi_ant, -rxdesc->rssi);
}
void rt2x00link_start_tuner(struct rt2x00_dev *rt2x00dev)
{
struct link *link = &rt2x00dev->link;
if (!rt2x00dev->intf_sta_count)
return;
if (test_bit(DEVICE_STATE_SCANNING, &rt2x00dev->flags))
return;
rt2x00link_reset_tuner(rt2x00dev, false);
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->work, LINK_TUNE_INTERVAL);
}
void rt2x00link_stop_tuner(struct rt2x00_dev *rt2x00dev)
{
cancel_delayed_work_sync(&rt2x00dev->link.work);
}
void rt2x00link_reset_tuner(struct rt2x00_dev *rt2x00dev, bool antenna)
{
struct link_qual *qual = &rt2x00dev->link.qual;
u8 vgc_level = qual->vgc_level_reg;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
rt2x00dev->link.count = 0;
memset(qual, 0, sizeof(*qual));
ewma_rssi_init(&rt2x00dev->link.avg_rssi);
qual->vgc_level_reg = vgc_level;
rt2x00dev->ops->lib->reset_tuner(rt2x00dev, qual);
if (antenna)
rt2x00link_antenna_reset(rt2x00dev);
}
static void rt2x00link_reset_qual(struct rt2x00_dev *rt2x00dev)
{
struct link_qual *qual = &rt2x00dev->link.qual;
qual->rx_success = 0;
qual->rx_failed = 0;
qual->tx_success = 0;
qual->tx_failed = 0;
}
static void rt2x00link_tuner(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, link.work.work);
struct link *link = &rt2x00dev->link;
struct link_qual *qual = &rt2x00dev->link.qual;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags) ||
test_bit(DEVICE_STATE_SCANNING, &rt2x00dev->flags))
return;
rt2x00dev->ops->lib->link_stats(rt2x00dev, qual);
rt2x00dev->low_level_stats.dot11FCSErrorCount += qual->rx_failed;
if (!qual->rx_success)
qual->rssi = DEFAULT_RSSI;
else
qual->rssi = rt2x00link_get_avg_rssi(&link->avg_rssi);
if (rt2x00_has_cap_link_tuning(rt2x00dev))
rt2x00dev->ops->lib->link_tuner(rt2x00dev, qual, link->count);
rt2x00leds_led_quality(rt2x00dev, qual->rssi);
if (rt2x00lib_antenna_diversity(rt2x00dev))
rt2x00link_reset_qual(rt2x00dev);
link->count++;
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->work, LINK_TUNE_INTERVAL);
}
void rt2x00link_start_watchdog(struct rt2x00_dev *rt2x00dev)
{
struct link *link = &rt2x00dev->link;
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags) &&
rt2x00dev->ops->lib->watchdog)
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->watchdog_work,
WATCHDOG_INTERVAL);
}
void rt2x00link_stop_watchdog(struct rt2x00_dev *rt2x00dev)
{
cancel_delayed_work_sync(&rt2x00dev->link.watchdog_work);
}
static void rt2x00link_watchdog(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, link.watchdog_work.work);
struct link *link = &rt2x00dev->link;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
rt2x00dev->ops->lib->watchdog(rt2x00dev);
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->watchdog_work,
WATCHDOG_INTERVAL);
}
void rt2x00link_start_agc(struct rt2x00_dev *rt2x00dev)
{
struct link *link = &rt2x00dev->link;
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags) &&
rt2x00dev->ops->lib->gain_calibration)
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->agc_work,
AGC_INTERVAL);
}
void rt2x00link_start_vcocal(struct rt2x00_dev *rt2x00dev)
{
struct link *link = &rt2x00dev->link;
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags) &&
rt2x00dev->ops->lib->vco_calibration)
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->vco_work,
VCO_INTERVAL);
}
void rt2x00link_stop_agc(struct rt2x00_dev *rt2x00dev)
{
cancel_delayed_work_sync(&rt2x00dev->link.agc_work);
}
void rt2x00link_stop_vcocal(struct rt2x00_dev *rt2x00dev)
{
cancel_delayed_work_sync(&rt2x00dev->link.vco_work);
}
static void rt2x00link_agc(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, link.agc_work.work);
struct link *link = &rt2x00dev->link;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
rt2x00dev->ops->lib->gain_calibration(rt2x00dev);
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->agc_work,
AGC_INTERVAL);
}
static void rt2x00link_vcocal(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, link.vco_work.work);
struct link *link = &rt2x00dev->link;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return;
rt2x00dev->ops->lib->vco_calibration(rt2x00dev);
if (test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
ieee80211_queue_delayed_work(rt2x00dev->hw,
&link->vco_work,
VCO_INTERVAL);
}
void rt2x00link_register(struct rt2x00_dev *rt2x00dev)
{
INIT_DELAYED_WORK(&rt2x00dev->link.agc_work, rt2x00link_agc);
if (rt2x00_has_cap_vco_recalibration(rt2x00dev))
INIT_DELAYED_WORK(&rt2x00dev->link.vco_work, rt2x00link_vcocal);
INIT_DELAYED_WORK(&rt2x00dev->link.watchdog_work, rt2x00link_watchdog);
INIT_DELAYED_WORK(&rt2x00dev->link.work, rt2x00link_tuner);
}
