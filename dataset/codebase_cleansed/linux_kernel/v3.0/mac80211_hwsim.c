static inline void hwsim_check_magic(struct ieee80211_vif *vif)
{
struct hwsim_vif_priv *vp = (void *)vif->drv_priv;
WARN_ON(vp->magic != HWSIM_VIF_MAGIC);
}
static inline void hwsim_set_magic(struct ieee80211_vif *vif)
{
struct hwsim_vif_priv *vp = (void *)vif->drv_priv;
vp->magic = HWSIM_VIF_MAGIC;
}
static inline void hwsim_clear_magic(struct ieee80211_vif *vif)
{
struct hwsim_vif_priv *vp = (void *)vif->drv_priv;
vp->magic = 0;
}
static inline void hwsim_check_sta_magic(struct ieee80211_sta *sta)
{
struct hwsim_sta_priv *sp = (void *)sta->drv_priv;
WARN_ON(sp->magic != HWSIM_STA_MAGIC);
}
static inline void hwsim_set_sta_magic(struct ieee80211_sta *sta)
{
struct hwsim_sta_priv *sp = (void *)sta->drv_priv;
sp->magic = HWSIM_STA_MAGIC;
}
static inline void hwsim_clear_sta_magic(struct ieee80211_sta *sta)
{
struct hwsim_sta_priv *sp = (void *)sta->drv_priv;
sp->magic = 0;
}
static netdev_tx_t hwsim_mon_xmit(struct sk_buff *skb,
struct net_device *dev)
{
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void mac80211_hwsim_monitor_rx(struct ieee80211_hw *hw,
struct sk_buff *tx_skb)
{
struct mac80211_hwsim_data *data = hw->priv;
struct sk_buff *skb;
struct hwsim_radiotap_hdr *hdr;
u16 flags;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(tx_skb);
struct ieee80211_rate *txrate = ieee80211_get_tx_rate(hw, info);
if (!netif_running(hwsim_mon))
return;
skb = skb_copy_expand(tx_skb, sizeof(*hdr), 0, GFP_ATOMIC);
if (skb == NULL)
return;
hdr = (struct hwsim_radiotap_hdr *) skb_push(skb, sizeof(*hdr));
hdr->hdr.it_version = PKTHDR_RADIOTAP_VERSION;
hdr->hdr.it_pad = 0;
hdr->hdr.it_len = cpu_to_le16(sizeof(*hdr));
hdr->hdr.it_present = cpu_to_le32((1 << IEEE80211_RADIOTAP_FLAGS) |
(1 << IEEE80211_RADIOTAP_RATE) |
(1 << IEEE80211_RADIOTAP_CHANNEL));
hdr->rt_flags = 0;
hdr->rt_rate = txrate->bitrate / 5;
hdr->rt_channel = cpu_to_le16(data->channel->center_freq);
flags = IEEE80211_CHAN_2GHZ;
if (txrate->flags & IEEE80211_RATE_ERP_G)
flags |= IEEE80211_CHAN_OFDM;
else
flags |= IEEE80211_CHAN_CCK;
hdr->rt_chbitmask = cpu_to_le16(flags);
skb->dev = hwsim_mon;
skb_set_mac_header(skb, 0);
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = htons(ETH_P_802_2);
memset(skb->cb, 0, sizeof(skb->cb));
netif_rx(skb);
}
static void mac80211_hwsim_monitor_ack(struct ieee80211_hw *hw, const u8 *addr)
{
struct mac80211_hwsim_data *data = hw->priv;
struct sk_buff *skb;
struct hwsim_radiotap_hdr *hdr;
u16 flags;
struct ieee80211_hdr *hdr11;
if (!netif_running(hwsim_mon))
return;
skb = dev_alloc_skb(100);
if (skb == NULL)
return;
hdr = (struct hwsim_radiotap_hdr *) skb_put(skb, sizeof(*hdr));
hdr->hdr.it_version = PKTHDR_RADIOTAP_VERSION;
hdr->hdr.it_pad = 0;
hdr->hdr.it_len = cpu_to_le16(sizeof(*hdr));
hdr->hdr.it_present = cpu_to_le32((1 << IEEE80211_RADIOTAP_FLAGS) |
(1 << IEEE80211_RADIOTAP_CHANNEL));
hdr->rt_flags = 0;
hdr->rt_rate = 0;
hdr->rt_channel = cpu_to_le16(data->channel->center_freq);
flags = IEEE80211_CHAN_2GHZ;
hdr->rt_chbitmask = cpu_to_le16(flags);
hdr11 = (struct ieee80211_hdr *) skb_put(skb, 10);
hdr11->frame_control = cpu_to_le16(IEEE80211_FTYPE_CTL |
IEEE80211_STYPE_ACK);
hdr11->duration_id = cpu_to_le16(0);
memcpy(hdr11->addr1, addr, ETH_ALEN);
skb->dev = hwsim_mon;
skb_set_mac_header(skb, 0);
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = htons(ETH_P_802_2);
memset(skb->cb, 0, sizeof(skb->cb));
netif_rx(skb);
}
static bool hwsim_ps_rx_ok(struct mac80211_hwsim_data *data,
struct sk_buff *skb)
{
switch (data->ps) {
case PS_DISABLED:
return true;
case PS_ENABLED:
return false;
case PS_AUTO_POLL:
return true;
case PS_MANUAL_POLL:
if (data->ps_poll_pending &&
memcmp(data->hw->wiphy->perm_addr, skb->data + 4,
ETH_ALEN) == 0) {
data->ps_poll_pending = false;
return true;
}
return false;
}
return true;
}
static void mac80211_hwsim_addr_iter(void *data, u8 *mac,
struct ieee80211_vif *vif)
{
struct mac80211_hwsim_addr_match_data *md = data;
if (memcmp(mac, md->addr, ETH_ALEN) == 0)
md->ret = true;
}
static bool mac80211_hwsim_addr_match(struct mac80211_hwsim_data *data,
const u8 *addr)
{
struct mac80211_hwsim_addr_match_data md;
if (memcmp(addr, data->hw->wiphy->perm_addr, ETH_ALEN) == 0)
return true;
md.ret = false;
md.addr = addr;
ieee80211_iterate_active_interfaces_atomic(data->hw,
mac80211_hwsim_addr_iter,
&md);
return md.ret;
}
static bool mac80211_hwsim_tx_frame(struct ieee80211_hw *hw,
struct sk_buff *skb)
{
struct mac80211_hwsim_data *data = hw->priv, *data2;
bool ack = false;
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) skb->data;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_rx_status rx_status;
if (data->idle) {
wiphy_debug(hw->wiphy, "Trying to TX when idle - reject\n");
return false;
}
memset(&rx_status, 0, sizeof(rx_status));
rx_status.freq = data->channel->center_freq;
rx_status.band = data->channel->band;
rx_status.rate_idx = info->control.rates[0].idx;
rx_status.signal = data->power_level - 50;
if (data->ps != PS_DISABLED)
hdr->frame_control |= cpu_to_le16(IEEE80211_FCTL_PM);
skb_orphan(skb);
skb_dst_drop(skb);
skb->mark = 0;
secpath_reset(skb);
nf_reset(skb);
spin_lock(&hwsim_radio_lock);
list_for_each_entry(data2, &hwsim_radios, list) {
struct sk_buff *nskb;
if (data == data2)
continue;
if (data2->idle || !data2->started ||
!hwsim_ps_rx_ok(data2, skb) ||
!data->channel || !data2->channel ||
data->channel->center_freq != data2->channel->center_freq ||
!(data->group & data2->group))
continue;
nskb = skb_copy(skb, GFP_ATOMIC);
if (nskb == NULL)
continue;
if (mac80211_hwsim_addr_match(data2, hdr->addr1))
ack = true;
memcpy(IEEE80211_SKB_RXCB(nskb), &rx_status, sizeof(rx_status));
ieee80211_rx_irqsafe(data2->hw, nskb);
}
spin_unlock(&hwsim_radio_lock);
return ack;
}
static void mac80211_hwsim_tx(struct ieee80211_hw *hw, struct sk_buff *skb)
{
bool ack;
struct ieee80211_tx_info *txi;
mac80211_hwsim_monitor_rx(hw, skb);
if (skb->len < 10) {
dev_kfree_skb(skb);
return;
}
ack = mac80211_hwsim_tx_frame(hw, skb);
if (ack && skb->len >= 16) {
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *) skb->data;
mac80211_hwsim_monitor_ack(hw, hdr->addr2);
}
txi = IEEE80211_SKB_CB(skb);
if (txi->control.vif)
hwsim_check_magic(txi->control.vif);
if (txi->control.sta)
hwsim_check_sta_magic(txi->control.sta);
ieee80211_tx_info_clear_status(txi);
if (!(txi->flags & IEEE80211_TX_CTL_NO_ACK) && ack)
txi->flags |= IEEE80211_TX_STAT_ACK;
ieee80211_tx_status_irqsafe(hw, skb);
}
static int mac80211_hwsim_start(struct ieee80211_hw *hw)
{
struct mac80211_hwsim_data *data = hw->priv;
wiphy_debug(hw->wiphy, "%s\n", __func__);
data->started = 1;
return 0;
}
static void mac80211_hwsim_stop(struct ieee80211_hw *hw)
{
struct mac80211_hwsim_data *data = hw->priv;
data->started = 0;
del_timer(&data->beacon_timer);
wiphy_debug(hw->wiphy, "%s\n", __func__);
}
static int mac80211_hwsim_add_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
wiphy_debug(hw->wiphy, "%s (type=%d mac_addr=%pM)\n",
__func__, ieee80211_vif_type_p2p(vif),
vif->addr);
hwsim_set_magic(vif);
return 0;
}
static int mac80211_hwsim_change_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum nl80211_iftype newtype,
bool newp2p)
{
newtype = ieee80211_iftype_p2p(newtype, newp2p);
wiphy_debug(hw->wiphy,
"%s (old type=%d, new type=%d, mac_addr=%pM)\n",
__func__, ieee80211_vif_type_p2p(vif),
newtype, vif->addr);
hwsim_check_magic(vif);
return 0;
}
static void mac80211_hwsim_remove_interface(
struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
wiphy_debug(hw->wiphy, "%s (type=%d mac_addr=%pM)\n",
__func__, ieee80211_vif_type_p2p(vif),
vif->addr);
hwsim_check_magic(vif);
hwsim_clear_magic(vif);
}
static void mac80211_hwsim_beacon_tx(void *arg, u8 *mac,
struct ieee80211_vif *vif)
{
struct ieee80211_hw *hw = arg;
struct sk_buff *skb;
struct ieee80211_tx_info *info;
hwsim_check_magic(vif);
if (vif->type != NL80211_IFTYPE_AP &&
vif->type != NL80211_IFTYPE_MESH_POINT &&
vif->type != NL80211_IFTYPE_ADHOC)
return;
skb = ieee80211_beacon_get(hw, vif);
if (skb == NULL)
return;
info = IEEE80211_SKB_CB(skb);
mac80211_hwsim_monitor_rx(hw, skb);
mac80211_hwsim_tx_frame(hw, skb);
dev_kfree_skb(skb);
}
static void mac80211_hwsim_beacon(unsigned long arg)
{
struct ieee80211_hw *hw = (struct ieee80211_hw *) arg;
struct mac80211_hwsim_data *data = hw->priv;
if (!data->started)
return;
ieee80211_iterate_active_interfaces_atomic(
hw, mac80211_hwsim_beacon_tx, hw);
data->beacon_timer.expires = jiffies + data->beacon_int;
add_timer(&data->beacon_timer);
}
static int mac80211_hwsim_config(struct ieee80211_hw *hw, u32 changed)
{
struct mac80211_hwsim_data *data = hw->priv;
struct ieee80211_conf *conf = &hw->conf;
static const char *smps_modes[IEEE80211_SMPS_NUM_MODES] = {
[IEEE80211_SMPS_AUTOMATIC] = "auto",
[IEEE80211_SMPS_OFF] = "off",
[IEEE80211_SMPS_STATIC] = "static",
[IEEE80211_SMPS_DYNAMIC] = "dynamic",
};
wiphy_debug(hw->wiphy,
"%s (freq=%d/%s idle=%d ps=%d smps=%s)\n",
__func__,
conf->channel->center_freq,
hwsim_chantypes[conf->channel_type],
!!(conf->flags & IEEE80211_CONF_IDLE),
!!(conf->flags & IEEE80211_CONF_PS),
smps_modes[conf->smps_mode]);
data->idle = !!(conf->flags & IEEE80211_CONF_IDLE);
data->channel = conf->channel;
data->power_level = conf->power_level;
if (!data->started || !data->beacon_int)
del_timer(&data->beacon_timer);
else
mod_timer(&data->beacon_timer, jiffies + data->beacon_int);
return 0;
}
static void mac80211_hwsim_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags,u64 multicast)
{
struct mac80211_hwsim_data *data = hw->priv;
wiphy_debug(hw->wiphy, "%s\n", __func__);
data->rx_filter = 0;
if (*total_flags & FIF_PROMISC_IN_BSS)
data->rx_filter |= FIF_PROMISC_IN_BSS;
if (*total_flags & FIF_ALLMULTI)
data->rx_filter |= FIF_ALLMULTI;
*total_flags = data->rx_filter;
}
static void mac80211_hwsim_bss_info_changed(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *info,
u32 changed)
{
struct hwsim_vif_priv *vp = (void *)vif->drv_priv;
struct mac80211_hwsim_data *data = hw->priv;
hwsim_check_magic(vif);
wiphy_debug(hw->wiphy, "%s(changed=0x%x)\n", __func__, changed);
if (changed & BSS_CHANGED_BSSID) {
wiphy_debug(hw->wiphy, "%s: BSSID changed: %pM\n",
__func__, info->bssid);
memcpy(vp->bssid, info->bssid, ETH_ALEN);
}
if (changed & BSS_CHANGED_ASSOC) {
wiphy_debug(hw->wiphy, " ASSOC: assoc=%d aid=%d\n",
info->assoc, info->aid);
vp->assoc = info->assoc;
vp->aid = info->aid;
}
if (changed & BSS_CHANGED_BEACON_INT) {
wiphy_debug(hw->wiphy, " BCNINT: %d\n", info->beacon_int);
data->beacon_int = 1024 * info->beacon_int / 1000 * HZ / 1000;
if (WARN_ON(!data->beacon_int))
data->beacon_int = 1;
if (data->started)
mod_timer(&data->beacon_timer,
jiffies + data->beacon_int);
}
if (changed & BSS_CHANGED_ERP_CTS_PROT) {
wiphy_debug(hw->wiphy, " ERP_CTS_PROT: %d\n",
info->use_cts_prot);
}
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
wiphy_debug(hw->wiphy, " ERP_PREAMBLE: %d\n",
info->use_short_preamble);
}
if (changed & BSS_CHANGED_ERP_SLOT) {
wiphy_debug(hw->wiphy, " ERP_SLOT: %d\n", info->use_short_slot);
}
if (changed & BSS_CHANGED_HT) {
wiphy_debug(hw->wiphy, " HT: op_mode=0x%x, chantype=%s\n",
info->ht_operation_mode,
hwsim_chantypes[info->channel_type]);
}
if (changed & BSS_CHANGED_BASIC_RATES) {
wiphy_debug(hw->wiphy, " BASIC_RATES: 0x%llx\n",
(unsigned long long) info->basic_rates);
}
}
static int mac80211_hwsim_sta_add(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
hwsim_check_magic(vif);
hwsim_set_sta_magic(sta);
return 0;
}
static int mac80211_hwsim_sta_remove(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
hwsim_check_magic(vif);
hwsim_clear_sta_magic(sta);
return 0;
}
static void mac80211_hwsim_sta_notify(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum sta_notify_cmd cmd,
struct ieee80211_sta *sta)
{
hwsim_check_magic(vif);
switch (cmd) {
case STA_NOTIFY_SLEEP:
case STA_NOTIFY_AWAKE:
break;
default:
WARN(1, "Invalid sta notify: %d\n", cmd);
break;
}
}
static int mac80211_hwsim_set_tim(struct ieee80211_hw *hw,
struct ieee80211_sta *sta,
bool set)
{
hwsim_check_sta_magic(sta);
return 0;
}
static int mac80211_hwsim_conf_tx(
struct ieee80211_hw *hw, u16 queue,
const struct ieee80211_tx_queue_params *params)
{
wiphy_debug(hw->wiphy,
"%s (queue=%d txop=%d cw_min=%d cw_max=%d aifs=%d)\n",
__func__, queue,
params->txop, params->cw_min,
params->cw_max, params->aifs);
return 0;
}
static int mac80211_hwsim_get_survey(
struct ieee80211_hw *hw, int idx,
struct survey_info *survey)
{
struct ieee80211_conf *conf = &hw->conf;
wiphy_debug(hw->wiphy, "%s (idx=%d)\n", __func__, idx);
if (idx != 0)
return -ENOENT;
survey->channel = conf->channel;
survey->filled = SURVEY_INFO_NOISE_DBM;
survey->noise = -92;
return 0;
}
static int mac80211_hwsim_testmode_cmd(struct ieee80211_hw *hw,
void *data, int len)
{
struct mac80211_hwsim_data *hwsim = hw->priv;
struct nlattr *tb[HWSIM_TM_ATTR_MAX + 1];
struct sk_buff *skb;
int err, ps;
err = nla_parse(tb, HWSIM_TM_ATTR_MAX, data, len,
hwsim_testmode_policy);
if (err)
return err;
if (!tb[HWSIM_TM_ATTR_CMD])
return -EINVAL;
switch (nla_get_u32(tb[HWSIM_TM_ATTR_CMD])) {
case HWSIM_TM_CMD_SET_PS:
if (!tb[HWSIM_TM_ATTR_PS])
return -EINVAL;
ps = nla_get_u32(tb[HWSIM_TM_ATTR_PS]);
return hwsim_fops_ps_write(hwsim, ps);
case HWSIM_TM_CMD_GET_PS:
skb = cfg80211_testmode_alloc_reply_skb(hw->wiphy,
nla_total_size(sizeof(u32)));
if (!skb)
return -ENOMEM;
NLA_PUT_U32(skb, HWSIM_TM_ATTR_PS, hwsim->ps);
return cfg80211_testmode_reply(skb);
default:
return -EOPNOTSUPP;
}
nla_put_failure:
kfree_skb(skb);
return -ENOBUFS;
}
static int mac80211_hwsim_ampdu_action(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum ieee80211_ampdu_mlme_action action,
struct ieee80211_sta *sta, u16 tid, u16 *ssn,
u8 buf_size)
{
switch (action) {
case IEEE80211_AMPDU_TX_START:
ieee80211_start_tx_ba_cb_irqsafe(vif, sta->addr, tid);
break;
case IEEE80211_AMPDU_TX_STOP:
ieee80211_stop_tx_ba_cb_irqsafe(vif, sta->addr, tid);
break;
case IEEE80211_AMPDU_TX_OPERATIONAL:
break;
case IEEE80211_AMPDU_RX_START:
case IEEE80211_AMPDU_RX_STOP:
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static void mac80211_hwsim_flush(struct ieee80211_hw *hw, bool drop)
{
}
static void hw_scan_done(struct work_struct *work)
{
struct hw_scan_done *hsd =
container_of(work, struct hw_scan_done, w.work);
ieee80211_scan_completed(hsd->hw, false);
kfree(hsd);
}
static int mac80211_hwsim_hw_scan(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct cfg80211_scan_request *req)
{
struct hw_scan_done *hsd = kzalloc(sizeof(*hsd), GFP_KERNEL);
int i;
if (!hsd)
return -ENOMEM;
hsd->hw = hw;
INIT_DELAYED_WORK(&hsd->w, hw_scan_done);
printk(KERN_DEBUG "hwsim hw_scan request\n");
for (i = 0; i < req->n_channels; i++)
printk(KERN_DEBUG "hwsim hw_scan freq %d\n",
req->channels[i]->center_freq);
ieee80211_queue_delayed_work(hw, &hsd->w, 2 * HZ);
return 0;
}
static void mac80211_hwsim_sw_scan(struct ieee80211_hw *hw)
{
struct mac80211_hwsim_data *hwsim = hw->priv;
mutex_lock(&hwsim->mutex);
if (hwsim->scanning) {
printk(KERN_DEBUG "two hwsim sw_scans detected!\n");
goto out;
}
printk(KERN_DEBUG "hwsim sw_scan request, prepping stuff\n");
hwsim->scanning = true;
out:
mutex_unlock(&hwsim->mutex);
}
static void mac80211_hwsim_sw_scan_complete(struct ieee80211_hw *hw)
{
struct mac80211_hwsim_data *hwsim = hw->priv;
mutex_lock(&hwsim->mutex);
printk(KERN_DEBUG "hwsim sw_scan_complete\n");
hwsim->scanning = false;
mutex_unlock(&hwsim->mutex);
}
static void mac80211_hwsim_free(void)
{
struct list_head tmplist, *i, *tmp;
struct mac80211_hwsim_data *data, *tmpdata;
INIT_LIST_HEAD(&tmplist);
spin_lock_bh(&hwsim_radio_lock);
list_for_each_safe(i, tmp, &hwsim_radios)
list_move(i, &tmplist);
spin_unlock_bh(&hwsim_radio_lock);
list_for_each_entry_safe(data, tmpdata, &tmplist, list) {
debugfs_remove(data->debugfs_group);
debugfs_remove(data->debugfs_ps);
debugfs_remove(data->debugfs);
ieee80211_unregister_hw(data->hw);
device_unregister(data->dev);
ieee80211_free_hw(data->hw);
}
class_destroy(hwsim_class);
}
static void hwsim_mon_setup(struct net_device *dev)
{
dev->netdev_ops = &hwsim_netdev_ops;
dev->destructor = free_netdev;
ether_setup(dev);
dev->tx_queue_len = 0;
dev->type = ARPHRD_IEEE80211_RADIOTAP;
memset(dev->dev_addr, 0, ETH_ALEN);
dev->dev_addr[0] = 0x12;
}
static void hwsim_send_ps_poll(void *dat, u8 *mac, struct ieee80211_vif *vif)
{
struct mac80211_hwsim_data *data = dat;
struct hwsim_vif_priv *vp = (void *)vif->drv_priv;
struct sk_buff *skb;
struct ieee80211_pspoll *pspoll;
if (!vp->assoc)
return;
wiphy_debug(data->hw->wiphy,
"%s: send PS-Poll to %pM for aid %d\n",
__func__, vp->bssid, vp->aid);
skb = dev_alloc_skb(sizeof(*pspoll));
if (!skb)
return;
pspoll = (void *) skb_put(skb, sizeof(*pspoll));
pspoll->frame_control = cpu_to_le16(IEEE80211_FTYPE_CTL |
IEEE80211_STYPE_PSPOLL |
IEEE80211_FCTL_PM);
pspoll->aid = cpu_to_le16(0xc000 | vp->aid);
memcpy(pspoll->bssid, vp->bssid, ETH_ALEN);
memcpy(pspoll->ta, mac, ETH_ALEN);
if (!mac80211_hwsim_tx_frame(data->hw, skb))
printk(KERN_DEBUG "%s: PS-Poll frame not ack'ed\n", __func__);
dev_kfree_skb(skb);
}
static void hwsim_send_nullfunc(struct mac80211_hwsim_data *data, u8 *mac,
struct ieee80211_vif *vif, int ps)
{
struct hwsim_vif_priv *vp = (void *)vif->drv_priv;
struct sk_buff *skb;
struct ieee80211_hdr *hdr;
if (!vp->assoc)
return;
wiphy_debug(data->hw->wiphy,
"%s: send data::nullfunc to %pM ps=%d\n",
__func__, vp->bssid, ps);
skb = dev_alloc_skb(sizeof(*hdr));
if (!skb)
return;
hdr = (void *) skb_put(skb, sizeof(*hdr) - ETH_ALEN);
hdr->frame_control = cpu_to_le16(IEEE80211_FTYPE_DATA |
IEEE80211_STYPE_NULLFUNC |
(ps ? IEEE80211_FCTL_PM : 0));
hdr->duration_id = cpu_to_le16(0);
memcpy(hdr->addr1, vp->bssid, ETH_ALEN);
memcpy(hdr->addr2, mac, ETH_ALEN);
memcpy(hdr->addr3, vp->bssid, ETH_ALEN);
if (!mac80211_hwsim_tx_frame(data->hw, skb))
printk(KERN_DEBUG "%s: nullfunc frame not ack'ed\n", __func__);
dev_kfree_skb(skb);
}
static void hwsim_send_nullfunc_ps(void *dat, u8 *mac,
struct ieee80211_vif *vif)
{
struct mac80211_hwsim_data *data = dat;
hwsim_send_nullfunc(data, mac, vif, 1);
}
static void hwsim_send_nullfunc_no_ps(void *dat, u8 *mac,
struct ieee80211_vif *vif)
{
struct mac80211_hwsim_data *data = dat;
hwsim_send_nullfunc(data, mac, vif, 0);
}
static int hwsim_fops_ps_read(void *dat, u64 *val)
{
struct mac80211_hwsim_data *data = dat;
*val = data->ps;
return 0;
}
static int hwsim_fops_ps_write(void *dat, u64 val)
{
struct mac80211_hwsim_data *data = dat;
enum ps_mode old_ps;
if (val != PS_DISABLED && val != PS_ENABLED && val != PS_AUTO_POLL &&
val != PS_MANUAL_POLL)
return -EINVAL;
old_ps = data->ps;
data->ps = val;
if (val == PS_MANUAL_POLL) {
ieee80211_iterate_active_interfaces(data->hw,
hwsim_send_ps_poll, data);
data->ps_poll_pending = true;
} else if (old_ps == PS_DISABLED && val != PS_DISABLED) {
ieee80211_iterate_active_interfaces(data->hw,
hwsim_send_nullfunc_ps,
data);
} else if (old_ps != PS_DISABLED && val == PS_DISABLED) {
ieee80211_iterate_active_interfaces(data->hw,
hwsim_send_nullfunc_no_ps,
data);
}
return 0;
}
static int hwsim_fops_group_read(void *dat, u64 *val)
{
struct mac80211_hwsim_data *data = dat;
*val = data->group;
return 0;
}
static int hwsim_fops_group_write(void *dat, u64 val)
{
struct mac80211_hwsim_data *data = dat;
data->group = val;
return 0;
}
static int __init init_mac80211_hwsim(void)
{
int i, err = 0;
u8 addr[ETH_ALEN];
struct mac80211_hwsim_data *data;
struct ieee80211_hw *hw;
enum ieee80211_band band;
if (radios < 1 || radios > 100)
return -EINVAL;
if (fake_hw_scan) {
mac80211_hwsim_ops.hw_scan = mac80211_hwsim_hw_scan;
mac80211_hwsim_ops.sw_scan_start = NULL;
mac80211_hwsim_ops.sw_scan_complete = NULL;
}
spin_lock_init(&hwsim_radio_lock);
INIT_LIST_HEAD(&hwsim_radios);
hwsim_class = class_create(THIS_MODULE, "mac80211_hwsim");
if (IS_ERR(hwsim_class))
return PTR_ERR(hwsim_class);
memset(addr, 0, ETH_ALEN);
addr[0] = 0x02;
for (i = 0; i < radios; i++) {
printk(KERN_DEBUG "mac80211_hwsim: Initializing radio %d\n",
i);
hw = ieee80211_alloc_hw(sizeof(*data), &mac80211_hwsim_ops);
if (!hw) {
printk(KERN_DEBUG "mac80211_hwsim: ieee80211_alloc_hw "
"failed\n");
err = -ENOMEM;
goto failed;
}
data = hw->priv;
data->hw = hw;
data->dev = device_create(hwsim_class, NULL, 0, hw,
"hwsim%d", i);
if (IS_ERR(data->dev)) {
printk(KERN_DEBUG
"mac80211_hwsim: device_create "
"failed (%ld)\n", PTR_ERR(data->dev));
err = -ENOMEM;
goto failed_drvdata;
}
data->dev->driver = &mac80211_hwsim_driver;
SET_IEEE80211_DEV(hw, data->dev);
addr[3] = i >> 8;
addr[4] = i;
memcpy(data->addresses[0].addr, addr, ETH_ALEN);
memcpy(data->addresses[1].addr, addr, ETH_ALEN);
data->addresses[1].addr[0] |= 0x40;
hw->wiphy->n_addresses = 2;
hw->wiphy->addresses = data->addresses;
if (fake_hw_scan) {
hw->wiphy->max_scan_ssids = 255;
hw->wiphy->max_scan_ie_len = IEEE80211_MAX_DATA_LEN;
}
hw->channel_change_time = 1;
hw->queues = 4;
hw->wiphy->interface_modes =
BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_AP) |
BIT(NL80211_IFTYPE_P2P_CLIENT) |
BIT(NL80211_IFTYPE_P2P_GO) |
BIT(NL80211_IFTYPE_ADHOC) |
BIT(NL80211_IFTYPE_MESH_POINT);
hw->flags = IEEE80211_HW_MFP_CAPABLE |
IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_SUPPORTS_STATIC_SMPS |
IEEE80211_HW_SUPPORTS_DYNAMIC_SMPS |
IEEE80211_HW_AMPDU_AGGREGATION;
hw->vif_data_size = sizeof(struct hwsim_vif_priv);
hw->sta_data_size = sizeof(struct hwsim_sta_priv);
memcpy(data->channels_2ghz, hwsim_channels_2ghz,
sizeof(hwsim_channels_2ghz));
memcpy(data->channels_5ghz, hwsim_channels_5ghz,
sizeof(hwsim_channels_5ghz));
memcpy(data->rates, hwsim_rates, sizeof(hwsim_rates));
for (band = IEEE80211_BAND_2GHZ; band < IEEE80211_NUM_BANDS; band++) {
struct ieee80211_supported_band *sband = &data->bands[band];
switch (band) {
case IEEE80211_BAND_2GHZ:
sband->channels = data->channels_2ghz;
sband->n_channels =
ARRAY_SIZE(hwsim_channels_2ghz);
sband->bitrates = data->rates;
sband->n_bitrates = ARRAY_SIZE(hwsim_rates);
break;
case IEEE80211_BAND_5GHZ:
sband->channels = data->channels_5ghz;
sband->n_channels =
ARRAY_SIZE(hwsim_channels_5ghz);
sband->bitrates = data->rates + 4;
sband->n_bitrates = ARRAY_SIZE(hwsim_rates) - 4;
break;
default:
break;
}
sband->ht_cap.ht_supported = true;
sband->ht_cap.cap = IEEE80211_HT_CAP_SUP_WIDTH_20_40 |
IEEE80211_HT_CAP_GRN_FLD |
IEEE80211_HT_CAP_SGI_40 |
IEEE80211_HT_CAP_DSSSCCK40;
sband->ht_cap.ampdu_factor = 0x3;
sband->ht_cap.ampdu_density = 0x6;
memset(&sband->ht_cap.mcs, 0,
sizeof(sband->ht_cap.mcs));
sband->ht_cap.mcs.rx_mask[0] = 0xff;
sband->ht_cap.mcs.rx_mask[1] = 0xff;
sband->ht_cap.mcs.tx_params = IEEE80211_HT_MCS_TX_DEFINED;
hw->wiphy->bands[band] = sband;
}
data->group = 1;
mutex_init(&data->mutex);
switch (regtest) {
case HWSIM_REGTEST_DISABLED:
case HWSIM_REGTEST_DRIVER_REG_FOLLOW:
case HWSIM_REGTEST_DRIVER_REG_ALL:
case HWSIM_REGTEST_DIFF_COUNTRY:
break;
case HWSIM_REGTEST_WORLD_ROAM:
if (i == 0) {
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY;
wiphy_apply_custom_regulatory(hw->wiphy,
&hwsim_world_regdom_custom_01);
}
break;
case HWSIM_REGTEST_CUSTOM_WORLD:
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY;
wiphy_apply_custom_regulatory(hw->wiphy,
&hwsim_world_regdom_custom_01);
break;
case HWSIM_REGTEST_CUSTOM_WORLD_2:
if (i == 0) {
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY;
wiphy_apply_custom_regulatory(hw->wiphy,
&hwsim_world_regdom_custom_01);
} else if (i == 1) {
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY;
wiphy_apply_custom_regulatory(hw->wiphy,
&hwsim_world_regdom_custom_02);
}
break;
case HWSIM_REGTEST_STRICT_ALL:
hw->wiphy->flags |= WIPHY_FLAG_STRICT_REGULATORY;
break;
case HWSIM_REGTEST_STRICT_FOLLOW:
case HWSIM_REGTEST_STRICT_AND_DRIVER_REG:
if (i == 0)
hw->wiphy->flags |= WIPHY_FLAG_STRICT_REGULATORY;
break;
case HWSIM_REGTEST_ALL:
if (i == 0) {
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY;
wiphy_apply_custom_regulatory(hw->wiphy,
&hwsim_world_regdom_custom_01);
} else if (i == 1) {
hw->wiphy->flags |= WIPHY_FLAG_CUSTOM_REGULATORY;
wiphy_apply_custom_regulatory(hw->wiphy,
&hwsim_world_regdom_custom_02);
} else if (i == 4)
hw->wiphy->flags |= WIPHY_FLAG_STRICT_REGULATORY;
break;
default:
break;
}
if (regtest)
schedule_timeout_interruptible(1);
err = ieee80211_register_hw(hw);
if (err < 0) {
printk(KERN_DEBUG "mac80211_hwsim: "
"ieee80211_register_hw failed (%d)\n", err);
goto failed_hw;
}
switch (regtest) {
case HWSIM_REGTEST_WORLD_ROAM:
case HWSIM_REGTEST_DISABLED:
break;
case HWSIM_REGTEST_DRIVER_REG_FOLLOW:
if (!i)
regulatory_hint(hw->wiphy, hwsim_alpha2s[0]);
break;
case HWSIM_REGTEST_DRIVER_REG_ALL:
case HWSIM_REGTEST_STRICT_ALL:
regulatory_hint(hw->wiphy, hwsim_alpha2s[0]);
break;
case HWSIM_REGTEST_DIFF_COUNTRY:
if (i < ARRAY_SIZE(hwsim_alpha2s))
regulatory_hint(hw->wiphy, hwsim_alpha2s[i]);
break;
case HWSIM_REGTEST_CUSTOM_WORLD:
case HWSIM_REGTEST_CUSTOM_WORLD_2:
break;
case HWSIM_REGTEST_STRICT_FOLLOW:
if (i == 0)
regulatory_hint(hw->wiphy, hwsim_alpha2s[0]);
break;
case HWSIM_REGTEST_STRICT_AND_DRIVER_REG:
if (i == 0)
regulatory_hint(hw->wiphy, hwsim_alpha2s[0]);
else if (i == 1)
regulatory_hint(hw->wiphy, hwsim_alpha2s[1]);
break;
case HWSIM_REGTEST_ALL:
if (i == 2)
regulatory_hint(hw->wiphy, hwsim_alpha2s[0]);
else if (i == 3)
regulatory_hint(hw->wiphy, hwsim_alpha2s[1]);
else if (i == 4)
regulatory_hint(hw->wiphy, hwsim_alpha2s[2]);
break;
default:
break;
}
wiphy_debug(hw->wiphy, "hwaddr %pm registered\n",
hw->wiphy->perm_addr);
data->debugfs = debugfs_create_dir("hwsim",
hw->wiphy->debugfsdir);
data->debugfs_ps = debugfs_create_file("ps", 0666,
data->debugfs, data,
&hwsim_fops_ps);
data->debugfs_group = debugfs_create_file("group", 0666,
data->debugfs, data,
&hwsim_fops_group);
setup_timer(&data->beacon_timer, mac80211_hwsim_beacon,
(unsigned long) hw);
list_add_tail(&data->list, &hwsim_radios);
}
hwsim_mon = alloc_netdev(0, "hwsim%d", hwsim_mon_setup);
if (hwsim_mon == NULL)
goto failed;
err = register_netdev(hwsim_mon);
if (err < 0)
goto failed_mon;
return 0;
failed_mon:
rtnl_unlock();
free_netdev(hwsim_mon);
mac80211_hwsim_free();
return err;
failed_hw:
device_unregister(data->dev);
failed_drvdata:
ieee80211_free_hw(hw);
failed:
mac80211_hwsim_free();
return err;
}
static void __exit exit_mac80211_hwsim(void)
{
printk(KERN_DEBUG "mac80211_hwsim: unregister radios\n");
mac80211_hwsim_free();
unregister_netdev(hwsim_mon);
}
