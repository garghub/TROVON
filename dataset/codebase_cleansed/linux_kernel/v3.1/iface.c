static int ieee80211_change_mtu(struct net_device *dev, int new_mtu)
{
int meshhdrlen;
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
meshhdrlen = (sdata->vif.type == NL80211_IFTYPE_MESH_POINT) ? 5 : 0;
if (new_mtu < 256 ||
new_mtu > IEEE80211_MAX_DATA_LEN - 24 - 6 - meshhdrlen) {
return -EINVAL;
}
#ifdef CONFIG_MAC80211_VERBOSE_DEBUG
printk(KERN_DEBUG "%s: setting MTU %d\n", dev->name, new_mtu);
#endif
dev->mtu = new_mtu;
return 0;
}
static int ieee80211_change_mac(struct net_device *dev, void *addr)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
struct sockaddr *sa = addr;
int ret;
if (ieee80211_sdata_running(sdata))
return -EBUSY;
ret = eth_mac_addr(dev, sa);
if (ret == 0)
memcpy(sdata->vif.addr, sa->sa_data, ETH_ALEN);
return ret;
}
static inline int identical_mac_addr_allowed(int type1, int type2)
{
return type1 == NL80211_IFTYPE_MONITOR ||
type2 == NL80211_IFTYPE_MONITOR ||
(type1 == NL80211_IFTYPE_AP && type2 == NL80211_IFTYPE_WDS) ||
(type1 == NL80211_IFTYPE_WDS &&
(type2 == NL80211_IFTYPE_WDS ||
type2 == NL80211_IFTYPE_AP)) ||
(type1 == NL80211_IFTYPE_AP && type2 == NL80211_IFTYPE_AP_VLAN) ||
(type1 == NL80211_IFTYPE_AP_VLAN &&
(type2 == NL80211_IFTYPE_AP ||
type2 == NL80211_IFTYPE_AP_VLAN));
}
static int ieee80211_check_concurrent_iface(struct ieee80211_sub_if_data *sdata,
enum nl80211_iftype iftype)
{
struct ieee80211_local *local = sdata->local;
struct ieee80211_sub_if_data *nsdata;
struct net_device *dev = sdata->dev;
ASSERT_RTNL();
list_for_each_entry(nsdata, &local->interfaces, list) {
struct net_device *ndev = nsdata->dev;
if (ndev != dev && ieee80211_sdata_running(nsdata)) {
if (iftype == NL80211_IFTYPE_ADHOC &&
nsdata->vif.type == NL80211_IFTYPE_ADHOC)
return -EBUSY;
if (compare_ether_addr(dev->dev_addr, ndev->dev_addr))
continue;
if (!identical_mac_addr_allowed(iftype,
nsdata->vif.type))
return -ENOTUNIQ;
if (iftype == NL80211_IFTYPE_AP_VLAN &&
nsdata->vif.type == NL80211_IFTYPE_AP)
sdata->bss = &nsdata->u.ap;
}
}
return 0;
}
void ieee80211_adjust_monitor_flags(struct ieee80211_sub_if_data *sdata,
const int offset)
{
struct ieee80211_local *local = sdata->local;
u32 flags = sdata->u.mntr_flags;
#define ADJUST(_f, _s) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
ADJUST(FCSFAIL, fcsfail);
ADJUST(PLCPFAIL, plcpfail);
ADJUST(CONTROL, control);
ADJUST(CONTROL, pspoll);
ADJUST(OTHER_BSS, other_bss);
#undef ADJUST
}
static int ieee80211_do_open(struct net_device *dev, bool coming_up)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
struct ieee80211_local *local = sdata->local;
struct sta_info *sta;
u32 changed = 0;
int res;
u32 hw_reconf_flags = 0;
switch (sdata->vif.type) {
case NL80211_IFTYPE_WDS:
if (!is_valid_ether_addr(sdata->u.wds.remote_addr))
return -ENOLINK;
break;
case NL80211_IFTYPE_AP_VLAN:
if (!sdata->bss)
return -ENOLINK;
list_add(&sdata->u.vlan.list, &sdata->bss->vlans);
break;
case NL80211_IFTYPE_AP:
sdata->bss = &sdata->u.ap;
break;
case NL80211_IFTYPE_MESH_POINT:
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_MONITOR:
case NL80211_IFTYPE_ADHOC:
break;
case NL80211_IFTYPE_UNSPECIFIED:
case NUM_NL80211_IFTYPES:
case NL80211_IFTYPE_P2P_CLIENT:
case NL80211_IFTYPE_P2P_GO:
WARN_ON(1);
break;
}
if (local->open_count == 0) {
res = drv_start(local);
if (res)
goto err_del_bss;
if (local->ops->napi_poll)
napi_enable(&local->napi);
hw_reconf_flags = ~0;
ieee80211_led_radio(local, true);
ieee80211_mod_tpt_led_trig(local,
IEEE80211_TPT_LEDTRIG_FL_RADIO, 0);
}
if (is_zero_ether_addr(dev->dev_addr)) {
memcpy(dev->dev_addr,
local->hw.wiphy->perm_addr,
ETH_ALEN);
memcpy(dev->perm_addr, dev->dev_addr, ETH_ALEN);
if (!is_valid_ether_addr(dev->dev_addr)) {
if (!local->open_count)
drv_stop(local);
return -EADDRNOTAVAIL;
}
}
switch (sdata->vif.type) {
case NL80211_IFTYPE_AP_VLAN:
break;
case NL80211_IFTYPE_MONITOR:
if (sdata->u.mntr_flags & MONITOR_FLAG_COOK_FRAMES) {
local->cooked_mntrs++;
break;
}
local->monitors++;
if (local->monitors == 1) {
local->hw.conf.flags |= IEEE80211_CONF_MONITOR;
hw_reconf_flags |= IEEE80211_CONF_CHANGE_MONITOR;
}
ieee80211_adjust_monitor_flags(sdata, 1);
ieee80211_configure_filter(local);
netif_carrier_on(dev);
break;
default:
if (coming_up) {
res = drv_add_interface(local, &sdata->vif);
if (res)
goto err_stop;
}
if (sdata->vif.type == NL80211_IFTYPE_AP) {
local->fif_pspoll++;
local->fif_probe_req++;
ieee80211_configure_filter(local);
} else if (sdata->vif.type == NL80211_IFTYPE_ADHOC) {
local->fif_probe_req++;
}
changed |= ieee80211_reset_erp_info(sdata);
ieee80211_bss_info_change_notify(sdata, changed);
if (sdata->vif.type == NL80211_IFTYPE_STATION)
netif_carrier_off(dev);
else
netif_carrier_on(dev);
}
set_bit(SDATA_STATE_RUNNING, &sdata->state);
if (sdata->vif.type == NL80211_IFTYPE_WDS) {
sta = sta_info_alloc(sdata, sdata->u.wds.remote_addr,
GFP_KERNEL);
if (!sta) {
res = -ENOMEM;
goto err_del_interface;
}
sta->flags |= WLAN_STA_AUTHORIZED;
res = sta_info_insert(sta);
if (res) {
goto err_del_interface;
}
rate_control_rate_init(sta);
}
if (sdata->flags & IEEE80211_SDATA_ALLMULTI)
atomic_inc(&local->iff_allmultis);
if (sdata->flags & IEEE80211_SDATA_PROMISC)
atomic_inc(&local->iff_promiscs);
mutex_lock(&local->mtx);
hw_reconf_flags |= __ieee80211_recalc_idle(local);
mutex_unlock(&local->mtx);
if (coming_up)
local->open_count++;
if (hw_reconf_flags) {
ieee80211_hw_config(local, hw_reconf_flags);
ieee80211_set_wmm_default(sdata);
}
ieee80211_recalc_ps(local, -1);
netif_tx_start_all_queues(dev);
return 0;
err_del_interface:
drv_remove_interface(local, &sdata->vif);
err_stop:
if (!local->open_count)
drv_stop(local);
err_del_bss:
sdata->bss = NULL;
if (sdata->vif.type == NL80211_IFTYPE_AP_VLAN)
list_del(&sdata->u.vlan.list);
clear_bit(SDATA_STATE_RUNNING, &sdata->state);
return res;
}
static int ieee80211_open(struct net_device *dev)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
int err;
if (!is_valid_ether_addr(dev->dev_addr))
return -EADDRNOTAVAIL;
err = ieee80211_check_concurrent_iface(sdata, sdata->vif.type);
if (err)
return err;
return ieee80211_do_open(dev, true);
}
static void ieee80211_do_stop(struct ieee80211_sub_if_data *sdata,
bool going_down)
{
struct ieee80211_local *local = sdata->local;
unsigned long flags;
struct sk_buff *skb, *tmp;
u32 hw_reconf_flags = 0;
int i;
enum nl80211_channel_type orig_ct;
clear_bit(SDATA_STATE_RUNNING, &sdata->state);
if (local->scan_sdata == sdata)
ieee80211_scan_cancel(local);
netif_tx_stop_all_queues(sdata->dev);
ieee80211_work_purge(sdata);
sta_info_flush(local, sdata);
if (sdata->flags & IEEE80211_SDATA_ALLMULTI)
atomic_dec(&local->iff_allmultis);
if (sdata->flags & IEEE80211_SDATA_PROMISC)
atomic_dec(&local->iff_promiscs);
if (sdata->vif.type == NL80211_IFTYPE_AP) {
local->fif_pspoll--;
local->fif_probe_req--;
} else if (sdata->vif.type == NL80211_IFTYPE_ADHOC) {
local->fif_probe_req--;
}
netif_addr_lock_bh(sdata->dev);
spin_lock_bh(&local->filter_lock);
__hw_addr_unsync(&local->mc_list, &sdata->dev->mc,
sdata->dev->addr_len);
spin_unlock_bh(&local->filter_lock);
netif_addr_unlock_bh(sdata->dev);
ieee80211_configure_filter(local);
del_timer_sync(&local->dynamic_ps_timer);
cancel_work_sync(&local->dynamic_ps_enable_work);
if (sdata->vif.type == NL80211_IFTYPE_AP) {
struct ieee80211_sub_if_data *vlan, *tmpsdata;
struct beacon_data *old_beacon =
rtnl_dereference(sdata->u.ap.beacon);
ieee80211_bss_info_change_notify(sdata,
BSS_CHANGED_BEACON_ENABLED);
rcu_assign_pointer(sdata->u.ap.beacon, NULL);
synchronize_rcu();
kfree(old_beacon);
while ((skb = skb_dequeue(&sdata->u.ap.ps_bc_buf))) {
local->total_ps_buffered--;
dev_kfree_skb(skb);
}
list_for_each_entry_safe(vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
dev_close(vlan->dev);
WARN_ON(!list_empty(&sdata->u.ap.vlans));
}
if (going_down)
local->open_count--;
switch (sdata->vif.type) {
case NL80211_IFTYPE_AP_VLAN:
list_del(&sdata->u.vlan.list);
break;
case NL80211_IFTYPE_MONITOR:
if (sdata->u.mntr_flags & MONITOR_FLAG_COOK_FRAMES) {
local->cooked_mntrs--;
break;
}
local->monitors--;
if (local->monitors == 0) {
local->hw.conf.flags &= ~IEEE80211_CONF_MONITOR;
hw_reconf_flags |= IEEE80211_CONF_CHANGE_MONITOR;
}
ieee80211_adjust_monitor_flags(sdata, -1);
ieee80211_configure_filter(local);
break;
default:
flush_work(&sdata->work);
synchronize_rcu();
skb_queue_purge(&sdata->skb_queue);
if (sdata->vif.type == NL80211_IFTYPE_MESH_POINT)
ieee80211_bss_info_change_notify(sdata,
BSS_CHANGED_BEACON_ENABLED);
ieee80211_free_keys(sdata);
if (going_down)
drv_remove_interface(local, &sdata->vif);
}
sdata->bss = NULL;
mutex_lock(&local->mtx);
hw_reconf_flags |= __ieee80211_recalc_idle(local);
mutex_unlock(&local->mtx);
ieee80211_recalc_ps(local, -1);
if (local->open_count == 0) {
if (local->ops->napi_poll)
napi_disable(&local->napi);
ieee80211_clear_tx_pending(local);
ieee80211_stop_device(local);
hw_reconf_flags = 0;
}
orig_ct = local->_oper_channel_type;
ieee80211_set_channel_type(local, NULL, NL80211_CHAN_NO_HT);
if (hw_reconf_flags || (orig_ct != local->_oper_channel_type))
ieee80211_hw_config(local, hw_reconf_flags);
spin_lock_irqsave(&local->queue_stop_reason_lock, flags);
for (i = 0; i < IEEE80211_MAX_QUEUES; i++) {
skb_queue_walk_safe(&local->pending[i], skb, tmp) {
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
if (info->control.vif == &sdata->vif) {
__skb_unlink(skb, &local->pending[i]);
dev_kfree_skb_irq(skb);
}
}
}
spin_unlock_irqrestore(&local->queue_stop_reason_lock, flags);
}
static int ieee80211_stop(struct net_device *dev)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
ieee80211_do_stop(sdata, true);
return 0;
}
static void ieee80211_set_multicast_list(struct net_device *dev)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
struct ieee80211_local *local = sdata->local;
int allmulti, promisc, sdata_allmulti, sdata_promisc;
allmulti = !!(dev->flags & IFF_ALLMULTI);
promisc = !!(dev->flags & IFF_PROMISC);
sdata_allmulti = !!(sdata->flags & IEEE80211_SDATA_ALLMULTI);
sdata_promisc = !!(sdata->flags & IEEE80211_SDATA_PROMISC);
if (allmulti != sdata_allmulti) {
if (dev->flags & IFF_ALLMULTI)
atomic_inc(&local->iff_allmultis);
else
atomic_dec(&local->iff_allmultis);
sdata->flags ^= IEEE80211_SDATA_ALLMULTI;
}
if (promisc != sdata_promisc) {
if (dev->flags & IFF_PROMISC)
atomic_inc(&local->iff_promiscs);
else
atomic_dec(&local->iff_promiscs);
sdata->flags ^= IEEE80211_SDATA_PROMISC;
}
spin_lock_bh(&local->filter_lock);
__hw_addr_sync(&local->mc_list, &dev->mc, dev->addr_len);
spin_unlock_bh(&local->filter_lock);
ieee80211_queue_work(&local->hw, &local->reconfig_filter);
}
static void ieee80211_teardown_sdata(struct net_device *dev)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
struct ieee80211_local *local = sdata->local;
int flushed;
int i;
ieee80211_free_keys(sdata);
ieee80211_debugfs_remove_netdev(sdata);
for (i = 0; i < IEEE80211_FRAGMENT_MAX; i++)
__skb_queue_purge(&sdata->fragments[i].skb_list);
sdata->fragment_next = 0;
if (ieee80211_vif_is_mesh(&sdata->vif))
mesh_rmc_free(sdata);
flushed = sta_info_flush(local, sdata);
WARN_ON(flushed);
}
static u16 ieee80211_netdev_select_queue(struct net_device *dev,
struct sk_buff *skb)
{
return ieee80211_select_queue(IEEE80211_DEV_TO_SUB_IF(dev), skb);
}
static u16 ieee80211_monitor_select_queue(struct net_device *dev,
struct sk_buff *skb)
{
struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);
struct ieee80211_local *local = sdata->local;
struct ieee80211_hdr *hdr;
struct ieee80211_radiotap_header *rtap = (void *)skb->data;
u8 *p;
if (local->hw.queues < 4)
return 0;
if (skb->len < 4 ||
skb->len < le16_to_cpu(rtap->it_len) + 2 )
return 0;
hdr = (void *)((u8 *)skb->data + le16_to_cpu(rtap->it_len));
if (!ieee80211_is_data(hdr->frame_control)) {
skb->priority = 7;
return ieee802_1d_to_ac[skb->priority];
}
if (!ieee80211_is_data_qos(hdr->frame_control)) {
skb->priority = 0;
return ieee802_1d_to_ac[skb->priority];
}
p = ieee80211_get_qos_ctl(hdr);
skb->priority = *p & IEEE80211_QOS_CTL_TAG1D_MASK;
return ieee80211_downgrade_queue(local, skb);
}
static void ieee80211_if_setup(struct net_device *dev)
{
ether_setup(dev);
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
dev->netdev_ops = &ieee80211_dataif_ops;
dev->destructor = free_netdev;
}
static void ieee80211_iface_work(struct work_struct *work)
{
struct ieee80211_sub_if_data *sdata =
container_of(work, struct ieee80211_sub_if_data, work);
struct ieee80211_local *local = sdata->local;
struct sk_buff *skb;
struct sta_info *sta;
struct ieee80211_ra_tid *ra_tid;
if (!ieee80211_sdata_running(sdata))
return;
if (local->scanning)
return;
if (WARN(local->suspended,
"interface work scheduled while going to suspend\n"))
return;
while ((skb = skb_dequeue(&sdata->skb_queue))) {
struct ieee80211_mgmt *mgmt = (void *)skb->data;
if (skb->pkt_type == IEEE80211_SDATA_QUEUE_AGG_START) {
ra_tid = (void *)&skb->cb;
ieee80211_start_tx_ba_cb(&sdata->vif, ra_tid->ra,
ra_tid->tid);
} else if (skb->pkt_type == IEEE80211_SDATA_QUEUE_AGG_STOP) {
ra_tid = (void *)&skb->cb;
ieee80211_stop_tx_ba_cb(&sdata->vif, ra_tid->ra,
ra_tid->tid);
} else if (ieee80211_is_action(mgmt->frame_control) &&
mgmt->u.action.category == WLAN_CATEGORY_BACK) {
int len = skb->len;
mutex_lock(&local->sta_mtx);
sta = sta_info_get_bss(sdata, mgmt->sa);
if (sta) {
switch (mgmt->u.action.u.addba_req.action_code) {
case WLAN_ACTION_ADDBA_REQ:
ieee80211_process_addba_request(
local, sta, mgmt, len);
break;
case WLAN_ACTION_ADDBA_RESP:
ieee80211_process_addba_resp(local, sta,
mgmt, len);
break;
case WLAN_ACTION_DELBA:
ieee80211_process_delba(sdata, sta,
mgmt, len);
break;
default:
WARN_ON(1);
break;
}
}
mutex_unlock(&local->sta_mtx);
} else if (ieee80211_is_data_qos(mgmt->frame_control)) {
struct ieee80211_hdr *hdr = (void *)mgmt;
WARN_ON(hdr->frame_control &
cpu_to_le16(IEEE80211_STYPE_NULLFUNC));
WARN_ON(!(hdr->seq_ctrl &
cpu_to_le16(IEEE80211_SCTL_FRAG)));
mutex_lock(&local->sta_mtx);
sta = sta_info_get_bss(sdata, mgmt->sa);
if (sta) {
u16 tid = *ieee80211_get_qos_ctl(hdr) &
IEEE80211_QOS_CTL_TID_MASK;
__ieee80211_stop_rx_ba_session(
sta, tid, WLAN_BACK_RECIPIENT,
WLAN_REASON_QSTA_REQUIRE_SETUP,
true);
}
mutex_unlock(&local->sta_mtx);
} else switch (sdata->vif.type) {
case NL80211_IFTYPE_STATION:
ieee80211_sta_rx_queued_mgmt(sdata, skb);
break;
case NL80211_IFTYPE_ADHOC:
ieee80211_ibss_rx_queued_mgmt(sdata, skb);
break;
case NL80211_IFTYPE_MESH_POINT:
if (!ieee80211_vif_is_mesh(&sdata->vif))
break;
ieee80211_mesh_rx_queued_mgmt(sdata, skb);
break;
default:
WARN(1, "frame for unexpected interface type");
break;
}
kfree_skb(skb);
}
switch (sdata->vif.type) {
case NL80211_IFTYPE_STATION:
ieee80211_sta_work(sdata);
break;
case NL80211_IFTYPE_ADHOC:
ieee80211_ibss_work(sdata);
break;
case NL80211_IFTYPE_MESH_POINT:
if (!ieee80211_vif_is_mesh(&sdata->vif))
break;
ieee80211_mesh_work(sdata);
break;
default:
break;
}
}
static void ieee80211_setup_sdata(struct ieee80211_sub_if_data *sdata,
enum nl80211_iftype type)
{
memset(&sdata->u, 0, sizeof(sdata->u));
sdata->vif.type = type;
sdata->vif.p2p = false;
sdata->dev->netdev_ops = &ieee80211_dataif_ops;
sdata->wdev.iftype = type;
sdata->control_port_protocol = cpu_to_be16(ETH_P_PAE);
sdata->control_port_no_encrypt = false;
sdata->dev->type = ARPHRD_ETHER;
skb_queue_head_init(&sdata->skb_queue);
INIT_WORK(&sdata->work, ieee80211_iface_work);
switch (type) {
case NL80211_IFTYPE_P2P_GO:
type = NL80211_IFTYPE_AP;
sdata->vif.type = type;
sdata->vif.p2p = true;
case NL80211_IFTYPE_AP:
skb_queue_head_init(&sdata->u.ap.ps_bc_buf);
INIT_LIST_HEAD(&sdata->u.ap.vlans);
break;
case NL80211_IFTYPE_P2P_CLIENT:
type = NL80211_IFTYPE_STATION;
sdata->vif.type = type;
sdata->vif.p2p = true;
case NL80211_IFTYPE_STATION:
ieee80211_sta_setup_sdata(sdata);
break;
case NL80211_IFTYPE_ADHOC:
ieee80211_ibss_setup_sdata(sdata);
break;
case NL80211_IFTYPE_MESH_POINT:
if (ieee80211_vif_is_mesh(&sdata->vif))
ieee80211_mesh_init_sdata(sdata);
break;
case NL80211_IFTYPE_MONITOR:
sdata->dev->type = ARPHRD_IEEE80211_RADIOTAP;
sdata->dev->netdev_ops = &ieee80211_monitorif_ops;
sdata->u.mntr_flags = MONITOR_FLAG_CONTROL |
MONITOR_FLAG_OTHER_BSS;
break;
case NL80211_IFTYPE_WDS:
case NL80211_IFTYPE_AP_VLAN:
break;
case NL80211_IFTYPE_UNSPECIFIED:
case NUM_NL80211_IFTYPES:
BUG();
break;
}
ieee80211_debugfs_add_netdev(sdata);
}
static int ieee80211_runtime_change_iftype(struct ieee80211_sub_if_data *sdata,
enum nl80211_iftype type)
{
struct ieee80211_local *local = sdata->local;
int ret, err;
enum nl80211_iftype internal_type = type;
bool p2p = false;
ASSERT_RTNL();
if (!local->ops->change_interface)
return -EBUSY;
switch (sdata->vif.type) {
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_ADHOC:
break;
default:
return -EBUSY;
}
switch (type) {
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_ADHOC:
break;
case NL80211_IFTYPE_P2P_CLIENT:
p2p = true;
internal_type = NL80211_IFTYPE_STATION;
break;
case NL80211_IFTYPE_P2P_GO:
p2p = true;
internal_type = NL80211_IFTYPE_AP;
break;
default:
return -EBUSY;
}
ret = ieee80211_check_concurrent_iface(sdata, internal_type);
if (ret)
return ret;
ieee80211_do_stop(sdata, false);
ieee80211_teardown_sdata(sdata->dev);
ret = drv_change_interface(local, sdata, internal_type, p2p);
if (ret)
type = sdata->vif.type;
ieee80211_setup_sdata(sdata, type);
err = ieee80211_do_open(sdata->dev, false);
WARN(err, "type change: do_open returned %d", err);
return ret;
}
int ieee80211_if_change_type(struct ieee80211_sub_if_data *sdata,
enum nl80211_iftype type)
{
int ret;
ASSERT_RTNL();
if (type == ieee80211_vif_type_p2p(&sdata->vif))
return 0;
if (sdata->local->oper_channel->flags & IEEE80211_CHAN_NO_IBSS &&
type == NL80211_IFTYPE_ADHOC)
return -EOPNOTSUPP;
if (ieee80211_sdata_running(sdata)) {
ret = ieee80211_runtime_change_iftype(sdata, type);
if (ret)
return ret;
} else {
ieee80211_teardown_sdata(sdata->dev);
ieee80211_setup_sdata(sdata, type);
}
sdata->vif.bss_conf.basic_rates =
ieee80211_mandatory_rates(sdata->local,
sdata->local->hw.conf.channel->band);
sdata->drop_unencrypted = 0;
if (type == NL80211_IFTYPE_STATION)
sdata->u.mgd.use_4addr = false;
return 0;
}
static void ieee80211_assign_perm_addr(struct ieee80211_local *local,
struct net_device *dev,
enum nl80211_iftype type)
{
struct ieee80211_sub_if_data *sdata;
u64 mask, start, addr, val, inc;
u8 *m;
u8 tmp_addr[ETH_ALEN];
int i;
memcpy(dev->perm_addr, local->hw.wiphy->perm_addr, ETH_ALEN);
if (is_zero_ether_addr(local->hw.wiphy->addr_mask) &&
local->hw.wiphy->n_addresses <= 1)
return;
mutex_lock(&local->iflist_mtx);
switch (type) {
case NL80211_IFTYPE_MONITOR:
break;
case NL80211_IFTYPE_WDS:
case NL80211_IFTYPE_AP_VLAN:
list_for_each_entry(sdata, &local->interfaces, list) {
if (sdata->vif.type != NL80211_IFTYPE_AP)
continue;
memcpy(dev->perm_addr, sdata->vif.addr, ETH_ALEN);
break;
}
break;
default:
for (i = 0; i < local->hw.wiphy->n_addresses; i++) {
bool used = false;
list_for_each_entry(sdata, &local->interfaces, list) {
if (memcmp(local->hw.wiphy->addresses[i].addr,
sdata->vif.addr, ETH_ALEN) == 0) {
used = true;
break;
}
}
if (!used) {
memcpy(dev->perm_addr,
local->hw.wiphy->addresses[i].addr,
ETH_ALEN);
break;
}
}
if (is_zero_ether_addr(local->hw.wiphy->addr_mask))
break;
m = local->hw.wiphy->addr_mask;
mask = ((u64)m[0] << 5*8) | ((u64)m[1] << 4*8) |
((u64)m[2] << 3*8) | ((u64)m[3] << 2*8) |
((u64)m[4] << 1*8) | ((u64)m[5] << 0*8);
if (__ffs64(mask) + hweight64(mask) != fls64(mask)) {
printk(KERN_DEBUG "not contiguous\n");
break;
}
m = local->hw.wiphy->perm_addr;
start = ((u64)m[0] << 5*8) | ((u64)m[1] << 4*8) |
((u64)m[2] << 3*8) | ((u64)m[3] << 2*8) |
((u64)m[4] << 1*8) | ((u64)m[5] << 0*8);
inc = 1ULL<<__ffs64(mask);
val = (start & mask);
addr = (start & ~mask) | (val & mask);
do {
bool used = false;
tmp_addr[5] = addr >> 0*8;
tmp_addr[4] = addr >> 1*8;
tmp_addr[3] = addr >> 2*8;
tmp_addr[2] = addr >> 3*8;
tmp_addr[1] = addr >> 4*8;
tmp_addr[0] = addr >> 5*8;
val += inc;
list_for_each_entry(sdata, &local->interfaces, list) {
if (memcmp(tmp_addr, sdata->vif.addr,
ETH_ALEN) == 0) {
used = true;
break;
}
}
if (!used) {
memcpy(dev->perm_addr, tmp_addr, ETH_ALEN);
break;
}
addr = (start & ~mask) | (val & mask);
} while (addr != start);
break;
}
mutex_unlock(&local->iflist_mtx);
}
int ieee80211_if_add(struct ieee80211_local *local, const char *name,
struct net_device **new_dev, enum nl80211_iftype type,
struct vif_params *params)
{
struct net_device *ndev;
struct ieee80211_sub_if_data *sdata = NULL;
int ret, i;
ASSERT_RTNL();
ndev = alloc_netdev_mqs(sizeof(*sdata) + local->hw.vif_data_size,
name, ieee80211_if_setup, local->hw.queues, 1);
if (!ndev)
return -ENOMEM;
dev_net_set(ndev, wiphy_net(local->hw.wiphy));
ndev->needed_headroom = local->tx_headroom +
4*6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- ETH_HLEN
+ IEEE80211_ENCRYPT_HEADROOM;
ndev->needed_tailroom = IEEE80211_ENCRYPT_TAILROOM;
ret = dev_alloc_name(ndev, ndev->name);
if (ret < 0)
goto fail;
ieee80211_assign_perm_addr(local, ndev, type);
memcpy(ndev->dev_addr, ndev->perm_addr, ETH_ALEN);
SET_NETDEV_DEV(ndev, wiphy_dev(local->hw.wiphy));
sdata = netdev_priv(ndev);
ndev->ieee80211_ptr = &sdata->wdev;
memcpy(sdata->vif.addr, ndev->dev_addr, ETH_ALEN);
memcpy(sdata->name, ndev->name, IFNAMSIZ);
sdata->wdev.wiphy = local->hw.wiphy;
sdata->local = local;
sdata->dev = ndev;
#ifdef CONFIG_INET
sdata->arp_filter_state = true;
#endif
for (i = 0; i < IEEE80211_FRAGMENT_MAX; i++)
skb_queue_head_init(&sdata->fragments[i].skb_list);
INIT_LIST_HEAD(&sdata->key_list);
for (i = 0; i < IEEE80211_NUM_BANDS; i++) {
struct ieee80211_supported_band *sband;
sband = local->hw.wiphy->bands[i];
sdata->rc_rateidx_mask[i] =
sband ? (1 << sband->n_bitrates) - 1 : 0;
}
ieee80211_setup_sdata(sdata, type);
if (params) {
ndev->ieee80211_ptr->use_4addr = params->use_4addr;
if (type == NL80211_IFTYPE_STATION)
sdata->u.mgd.use_4addr = params->use_4addr;
}
ret = register_netdevice(ndev);
if (ret)
goto fail;
mutex_lock(&local->iflist_mtx);
list_add_tail_rcu(&sdata->list, &local->interfaces);
mutex_unlock(&local->iflist_mtx);
if (new_dev)
*new_dev = ndev;
return 0;
fail:
free_netdev(ndev);
return ret;
}
void ieee80211_if_remove(struct ieee80211_sub_if_data *sdata)
{
ASSERT_RTNL();
mutex_lock(&sdata->local->iflist_mtx);
list_del_rcu(&sdata->list);
mutex_unlock(&sdata->local->iflist_mtx);
synchronize_rcu();
unregister_netdevice(sdata->dev);
}
void ieee80211_remove_interfaces(struct ieee80211_local *local)
{
struct ieee80211_sub_if_data *sdata, *tmp;
LIST_HEAD(unreg_list);
ASSERT_RTNL();
mutex_lock(&local->iflist_mtx);
list_for_each_entry_safe(sdata, tmp, &local->interfaces, list) {
list_del(&sdata->list);
unregister_netdevice_queue(sdata->dev, &unreg_list);
}
mutex_unlock(&local->iflist_mtx);
unregister_netdevice_many(&unreg_list);
list_del(&unreg_list);
}
static u32 ieee80211_idle_off(struct ieee80211_local *local,
const char *reason)
{
if (!(local->hw.conf.flags & IEEE80211_CONF_IDLE))
return 0;
#ifdef CONFIG_MAC80211_VERBOSE_DEBUG
wiphy_debug(local->hw.wiphy, "device no longer idle - %s\n", reason);
#endif
local->hw.conf.flags &= ~IEEE80211_CONF_IDLE;
return IEEE80211_CONF_CHANGE_IDLE;
}
static u32 ieee80211_idle_on(struct ieee80211_local *local)
{
if (local->hw.conf.flags & IEEE80211_CONF_IDLE)
return 0;
#ifdef CONFIG_MAC80211_VERBOSE_DEBUG
wiphy_debug(local->hw.wiphy, "device now idle\n");
#endif
drv_flush(local, false);
local->hw.conf.flags |= IEEE80211_CONF_IDLE;
return IEEE80211_CONF_CHANGE_IDLE;
}
u32 __ieee80211_recalc_idle(struct ieee80211_local *local)
{
struct ieee80211_sub_if_data *sdata;
int count = 0;
bool working = false, scanning = false, hw_roc = false;
struct ieee80211_work *wk;
unsigned int led_trig_start = 0, led_trig_stop = 0;
#ifdef CONFIG_PROVE_LOCKING
WARN_ON(debug_locks && !lockdep_rtnl_is_held() &&
!lockdep_is_held(&local->iflist_mtx));
#endif
lockdep_assert_held(&local->mtx);
list_for_each_entry(sdata, &local->interfaces, list) {
if (!ieee80211_sdata_running(sdata)) {
sdata->vif.bss_conf.idle = true;
continue;
}
sdata->old_idle = sdata->vif.bss_conf.idle;
if (sdata->vif.type == NL80211_IFTYPE_STATION &&
!sdata->u.mgd.associated) {
sdata->vif.bss_conf.idle = true;
continue;
}
if (sdata->vif.type == NL80211_IFTYPE_ADHOC &&
!sdata->u.ibss.ssid_len) {
sdata->vif.bss_conf.idle = true;
continue;
}
count++;
}
list_for_each_entry(wk, &local->work_list, list) {
working = true;
wk->sdata->vif.bss_conf.idle = false;
}
if (local->scan_sdata) {
scanning = true;
local->scan_sdata->vif.bss_conf.idle = false;
}
if (local->hw_roc_channel)
hw_roc = true;
list_for_each_entry(sdata, &local->interfaces, list) {
if (sdata->old_idle == sdata->vif.bss_conf.idle)
continue;
if (!ieee80211_sdata_running(sdata))
continue;
ieee80211_bss_info_change_notify(sdata, BSS_CHANGED_IDLE);
}
if (working || scanning || hw_roc)
led_trig_start |= IEEE80211_TPT_LEDTRIG_FL_WORK;
else
led_trig_stop |= IEEE80211_TPT_LEDTRIG_FL_WORK;
if (count)
led_trig_start |= IEEE80211_TPT_LEDTRIG_FL_CONNECTED;
else
led_trig_stop |= IEEE80211_TPT_LEDTRIG_FL_CONNECTED;
ieee80211_mod_tpt_led_trig(local, led_trig_start, led_trig_stop);
if (hw_roc)
return ieee80211_idle_off(local, "hw remain-on-channel");
if (working)
return ieee80211_idle_off(local, "working");
if (scanning)
return ieee80211_idle_off(local, "scanning");
if (!count)
return ieee80211_idle_on(local);
else
return ieee80211_idle_off(local, "in use");
return 0;
}
void ieee80211_recalc_idle(struct ieee80211_local *local)
{
u32 chg;
mutex_lock(&local->iflist_mtx);
chg = __ieee80211_recalc_idle(local);
mutex_unlock(&local->iflist_mtx);
if (chg)
ieee80211_hw_config(local, chg);
}
static int netdev_notify(struct notifier_block *nb,
unsigned long state,
void *ndev)
{
struct net_device *dev = ndev;
struct ieee80211_sub_if_data *sdata;
if (state != NETDEV_CHANGENAME)
return 0;
if (!dev->ieee80211_ptr || !dev->ieee80211_ptr->wiphy)
return 0;
if (dev->ieee80211_ptr->wiphy->privid != mac80211_wiphy_privid)
return 0;
sdata = IEEE80211_DEV_TO_SUB_IF(dev);
memcpy(sdata->name, dev->name, IFNAMSIZ);
ieee80211_debugfs_rename_netdev(sdata);
return 0;
}
int ieee80211_iface_init(void)
{
return register_netdevice_notifier(&mac80211_netdev_notifier);
}
void ieee80211_iface_exit(void)
{
unregister_netdevice_notifier(&mac80211_netdev_notifier);
}
