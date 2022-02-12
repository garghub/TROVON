static void brcms_set_basic_rate(struct brcm_rateset *rs, u16 rate, bool is_br)
{
u32 i;
for (i = 0; i < rs->count; i++) {
if (rate != (rs->rates[i] & 0x7f))
continue;
if (is_br)
rs->rates[i] |= BRCMS_RATE_FLAG;
else
rs->rates[i] &= BRCMS_RATE_MASK;
return;
}
}
static void brcms_ops_tx(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct brcms_info *wl = hw->priv;
spin_lock_bh(&wl->lock);
if (!wl->pub->up) {
wiphy_err(wl->wiphy, "ops->tx called while down\n");
kfree_skb(skb);
goto done;
}
brcms_c_sendpkt_mac80211(wl->wlc, skb, hw);
done:
spin_unlock_bh(&wl->lock);
}
static int brcms_ops_start(struct ieee80211_hw *hw)
{
struct brcms_info *wl = hw->priv;
bool blocked;
ieee80211_wake_queues(hw);
spin_lock_bh(&wl->lock);
blocked = brcms_rfkill_set_hw_state(wl);
spin_unlock_bh(&wl->lock);
if (!blocked)
wiphy_rfkill_stop_polling(wl->pub->ieee_hw->wiphy);
return 0;
}
static void brcms_ops_stop(struct ieee80211_hw *hw)
{
ieee80211_stop_queues(hw);
}
static int
brcms_ops_add_interface(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
struct brcms_info *wl;
int err;
if (vif->type != NL80211_IFTYPE_AP &&
vif->type != NL80211_IFTYPE_MESH_POINT &&
vif->type != NL80211_IFTYPE_STATION &&
vif->type != NL80211_IFTYPE_WDS &&
vif->type != NL80211_IFTYPE_ADHOC) {
wiphy_err(hw->wiphy, "%s: Attempt to add type %d, only"
" STA for now\n", __func__, vif->type);
return -EOPNOTSUPP;
}
wl = hw->priv;
spin_lock_bh(&wl->lock);
if (!wl->pub->up)
err = brcms_up(wl);
else
err = -ENODEV;
spin_unlock_bh(&wl->lock);
if (err != 0)
wiphy_err(hw->wiphy, "%s: brcms_up() returned %d\n", __func__,
err);
return err;
}
static void
brcms_ops_remove_interface(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
struct brcms_info *wl;
wl = hw->priv;
spin_lock_bh(&wl->lock);
brcms_down(wl);
spin_unlock_bh(&wl->lock);
}
static int brcms_ops_config(struct ieee80211_hw *hw, u32 changed)
{
struct ieee80211_conf *conf = &hw->conf;
struct brcms_info *wl = hw->priv;
int err = 0;
int new_int;
struct wiphy *wiphy = hw->wiphy;
spin_lock_bh(&wl->lock);
if (changed & IEEE80211_CONF_CHANGE_LISTEN_INTERVAL) {
brcms_c_set_beacon_listen_interval(wl->wlc,
conf->listen_interval);
}
if (changed & IEEE80211_CONF_CHANGE_MONITOR)
wiphy_err(wiphy, "%s: change monitor mode: %s (implement)\n",
__func__, conf->flags & IEEE80211_CONF_MONITOR ?
"true" : "false");
if (changed & IEEE80211_CONF_CHANGE_PS)
wiphy_err(wiphy, "%s: change power-save mode: %s (implement)\n",
__func__, conf->flags & IEEE80211_CONF_PS ?
"true" : "false");
if (changed & IEEE80211_CONF_CHANGE_POWER) {
err = brcms_c_set_tx_power(wl->wlc, conf->power_level);
if (err < 0) {
wiphy_err(wiphy, "%s: Error setting power_level\n",
__func__);
goto config_out;
}
new_int = brcms_c_get_tx_power(wl->wlc);
if (new_int != conf->power_level)
wiphy_err(wiphy, "%s: Power level req != actual, %d %d"
"\n", __func__, conf->power_level,
new_int);
}
if (changed & IEEE80211_CONF_CHANGE_CHANNEL) {
if (conf->channel_type == NL80211_CHAN_HT20 ||
conf->channel_type == NL80211_CHAN_NO_HT)
err = brcms_c_set_channel(wl->wlc,
conf->channel->hw_value);
else
err = -ENOTSUPP;
}
if (changed & IEEE80211_CONF_CHANGE_RETRY_LIMITS)
err = brcms_c_set_rate_limit(wl->wlc,
conf->short_frame_max_tx_count,
conf->long_frame_max_tx_count);
config_out:
spin_unlock_bh(&wl->lock);
return err;
}
static void
brcms_ops_bss_info_changed(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *info, u32 changed)
{
struct brcms_info *wl = hw->priv;
struct wiphy *wiphy = hw->wiphy;
if (changed & BSS_CHANGED_ASSOC) {
wiphy_err(wiphy, "%s: %s: %sassociated\n", KBUILD_MODNAME,
__func__, info->assoc ? "" : "dis");
spin_lock_bh(&wl->lock);
brcms_c_associate_upd(wl->wlc, info->assoc);
spin_unlock_bh(&wl->lock);
}
if (changed & BSS_CHANGED_ERP_SLOT) {
s8 val;
if (info->use_short_slot)
val = 1;
else
val = 0;
spin_lock_bh(&wl->lock);
brcms_c_set_shortslot_override(wl->wlc, val);
spin_unlock_bh(&wl->lock);
}
if (changed & BSS_CHANGED_HT) {
u16 mode = info->ht_operation_mode;
spin_lock_bh(&wl->lock);
brcms_c_protection_upd(wl->wlc, BRCMS_PROT_N_CFG,
mode & IEEE80211_HT_OP_MODE_PROTECTION);
brcms_c_protection_upd(wl->wlc, BRCMS_PROT_N_NONGF,
mode & IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT);
brcms_c_protection_upd(wl->wlc, BRCMS_PROT_N_OBSS,
mode & IEEE80211_HT_OP_MODE_NON_HT_STA_PRSNT);
spin_unlock_bh(&wl->lock);
}
if (changed & BSS_CHANGED_BASIC_RATES) {
struct ieee80211_supported_band *bi;
u32 br_mask, i;
u16 rate;
struct brcm_rateset rs;
int error;
spin_lock_bh(&wl->lock);
brcms_c_get_current_rateset(wl->wlc, &rs);
spin_unlock_bh(&wl->lock);
br_mask = info->basic_rates;
bi = hw->wiphy->bands[brcms_c_get_curband(wl->wlc)];
for (i = 0; i < bi->n_bitrates; i++) {
rate = (bi->bitrates[i].bitrate << 1) / 10;
brcms_set_basic_rate(&rs, rate, br_mask & 1);
br_mask >>= 1;
}
spin_lock_bh(&wl->lock);
error = brcms_c_set_rateset(wl->wlc, &rs);
spin_unlock_bh(&wl->lock);
if (error)
wiphy_err(wiphy, "changing basic rates failed: %d\n",
error);
}
if (changed & BSS_CHANGED_BEACON_INT) {
spin_lock_bh(&wl->lock);
brcms_c_set_beacon_period(wl->wlc, info->beacon_int);
spin_unlock_bh(&wl->lock);
}
if (changed & BSS_CHANGED_BSSID) {
spin_lock_bh(&wl->lock);
brcms_c_set_addrmatch(wl->wlc, RCM_BSSID_OFFSET, info->bssid);
spin_unlock_bh(&wl->lock);
}
if (changed & BSS_CHANGED_BEACON)
wiphy_err(wiphy, "%s: beacon changed\n", __func__);
if (changed & BSS_CHANGED_BEACON_ENABLED) {
wiphy_err(wiphy, "%s: Beacon enabled: %s\n", __func__,
info->enable_beacon ? "true" : "false");
}
if (changed & BSS_CHANGED_CQM) {
wiphy_err(wiphy, "%s: cqm change: threshold %d, hys %d "
" (implement)\n", __func__, info->cqm_rssi_thold,
info->cqm_rssi_hyst);
}
if (changed & BSS_CHANGED_IBSS) {
wiphy_err(wiphy, "%s: IBSS joined: %s (implement)\n", __func__,
info->ibss_joined ? "true" : "false");
}
if (changed & BSS_CHANGED_ARP_FILTER) {
wiphy_err(wiphy, "%s: arp filtering: enabled %s, count %d"
" (implement)\n", __func__, info->arp_filter_enabled ?
"true" : "false", info->arp_addr_cnt);
}
if (changed & BSS_CHANGED_QOS) {
wiphy_err(wiphy, "%s: qos enabled: %s (implement)\n", __func__,
info->qos ? "true" : "false");
}
return;
}
static void
brcms_ops_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags, u64 multicast)
{
struct brcms_info *wl = hw->priv;
struct wiphy *wiphy = hw->wiphy;
changed_flags &= MAC_FILTERS;
*total_flags &= MAC_FILTERS;
if (changed_flags & FIF_PROMISC_IN_BSS)
wiphy_err(wiphy, "FIF_PROMISC_IN_BSS\n");
if (changed_flags & FIF_ALLMULTI)
wiphy_err(wiphy, "FIF_ALLMULTI\n");
if (changed_flags & FIF_FCSFAIL)
wiphy_err(wiphy, "FIF_FCSFAIL\n");
if (changed_flags & FIF_PLCPFAIL)
wiphy_err(wiphy, "FIF_PLCPFAIL\n");
if (changed_flags & FIF_CONTROL)
wiphy_err(wiphy, "FIF_CONTROL\n");
if (changed_flags & FIF_OTHER_BSS)
wiphy_err(wiphy, "FIF_OTHER_BSS\n");
if (changed_flags & FIF_BCN_PRBRESP_PROMISC) {
spin_lock_bh(&wl->lock);
if (*total_flags & FIF_BCN_PRBRESP_PROMISC) {
wl->pub->mac80211_state |= MAC80211_PROMISC_BCNS;
brcms_c_mac_bcn_promisc_change(wl->wlc, 1);
} else {
brcms_c_mac_bcn_promisc_change(wl->wlc, 0);
wl->pub->mac80211_state &= ~MAC80211_PROMISC_BCNS;
}
spin_unlock_bh(&wl->lock);
}
return;
}
static void brcms_ops_sw_scan_start(struct ieee80211_hw *hw)
{
struct brcms_info *wl = hw->priv;
spin_lock_bh(&wl->lock);
brcms_c_scan_start(wl->wlc);
spin_unlock_bh(&wl->lock);
return;
}
static void brcms_ops_sw_scan_complete(struct ieee80211_hw *hw)
{
struct brcms_info *wl = hw->priv;
spin_lock_bh(&wl->lock);
brcms_c_scan_stop(wl->wlc);
spin_unlock_bh(&wl->lock);
return;
}
static int
brcms_ops_conf_tx(struct ieee80211_hw *hw, struct ieee80211_vif *vif, u16 queue,
const struct ieee80211_tx_queue_params *params)
{
struct brcms_info *wl = hw->priv;
spin_lock_bh(&wl->lock);
brcms_c_wme_setparams(wl->wlc, queue, params, true);
spin_unlock_bh(&wl->lock);
return 0;
}
static int
brcms_ops_sta_add(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct brcms_info *wl = hw->priv;
struct scb *scb = &wl->wlc->pri_scb;
brcms_c_init_scb(scb);
wl->pub->global_ampdu = &(scb->scb_ampdu);
wl->pub->global_ampdu->scb = scb;
wl->pub->global_ampdu->max_pdu = 16;
sta->ht_cap.ht_supported = true;
sta->ht_cap.ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K;
sta->ht_cap.ampdu_density = AMPDU_DEF_MPDU_DENSITY;
sta->ht_cap.cap = IEEE80211_HT_CAP_GRN_FLD |
IEEE80211_HT_CAP_SGI_20 |
IEEE80211_HT_CAP_SGI_40 | IEEE80211_HT_CAP_40MHZ_INTOLERANT;
return 0;
}
static int
brcms_ops_ampdu_action(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
enum ieee80211_ampdu_mlme_action action,
struct ieee80211_sta *sta, u16 tid, u16 *ssn,
u8 buf_size)
{
struct brcms_info *wl = hw->priv;
struct scb *scb = &wl->wlc->pri_scb;
int status;
if (WARN_ON(scb->magic != SCB_MAGIC))
return -EIDRM;
switch (action) {
case IEEE80211_AMPDU_RX_START:
break;
case IEEE80211_AMPDU_RX_STOP:
break;
case IEEE80211_AMPDU_TX_START:
spin_lock_bh(&wl->lock);
status = brcms_c_aggregatable(wl->wlc, tid);
spin_unlock_bh(&wl->lock);
if (!status) {
wiphy_err(wl->wiphy, "START: tid %d is not agg\'able\n",
tid);
return -EINVAL;
}
ieee80211_start_tx_ba_cb_irqsafe(vif, sta->addr, tid);
break;
case IEEE80211_AMPDU_TX_STOP:
spin_lock_bh(&wl->lock);
brcms_c_ampdu_flush(wl->wlc, sta, tid);
spin_unlock_bh(&wl->lock);
ieee80211_stop_tx_ba_cb_irqsafe(vif, sta->addr, tid);
break;
case IEEE80211_AMPDU_TX_OPERATIONAL:
spin_lock_bh(&wl->lock);
brcms_c_ampdu_tx_operational(wl->wlc, tid, buf_size,
(1 << (IEEE80211_HT_MAX_AMPDU_FACTOR +
sta->ht_cap.ampdu_factor)) - 1);
spin_unlock_bh(&wl->lock);
break;
default:
wiphy_err(wl->wiphy, "%s: Invalid command, ignoring\n",
__func__);
}
return 0;
}
static void brcms_ops_rfkill_poll(struct ieee80211_hw *hw)
{
struct brcms_info *wl = hw->priv;
bool blocked;
spin_lock_bh(&wl->lock);
blocked = brcms_c_check_radio_disabled(wl->wlc);
spin_unlock_bh(&wl->lock);
wiphy_rfkill_set_hw_state(wl->pub->ieee_hw->wiphy, blocked);
}
static void brcms_ops_flush(struct ieee80211_hw *hw, bool drop)
{
struct brcms_info *wl = hw->priv;
no_printk("%s: drop = %s\n", __func__, drop ? "true" : "false");
spin_lock_bh(&wl->lock);
brcms_c_wait_for_tx_completion(wl->wlc, drop);
spin_unlock_bh(&wl->lock);
}
static int brcms_set_hint(struct brcms_info *wl, char *abbrev)
{
return regulatory_hint(wl->pub->ieee_hw->wiphy, abbrev);
}
void brcms_dpc(unsigned long data)
{
struct brcms_info *wl;
wl = (struct brcms_info *) data;
spin_lock_bh(&wl->lock);
if (wl->pub->up) {
if (wl->resched) {
unsigned long flags;
spin_lock_irqsave(&wl->isr_lock, flags);
brcms_c_intrsupd(wl->wlc);
spin_unlock_irqrestore(&wl->isr_lock, flags);
}
wl->resched = brcms_c_dpc(wl->wlc, true);
}
if (!wl->pub->up)
goto done;
if (wl->resched)
tasklet_schedule(&wl->tasklet);
else
brcms_intrson(wl);
done:
spin_unlock_bh(&wl->lock);
}
static int brcms_request_fw(struct brcms_info *wl, struct pci_dev *pdev)
{
int status;
struct device *device = &pdev->dev;
char fw_name[100];
int i;
memset(&wl->fw, 0, sizeof(struct brcms_firmware));
for (i = 0; i < MAX_FW_IMAGES; i++) {
if (brcms_firmwares[i] == NULL)
break;
sprintf(fw_name, "%s-%d.fw", brcms_firmwares[i],
UCODE_LOADER_API_VER);
status = request_firmware(&wl->fw.fw_bin[i], fw_name, device);
if (status) {
wiphy_err(wl->wiphy, "%s: fail to load firmware %s\n",
KBUILD_MODNAME, fw_name);
return status;
}
sprintf(fw_name, "%s_hdr-%d.fw", brcms_firmwares[i],
UCODE_LOADER_API_VER);
status = request_firmware(&wl->fw.fw_hdr[i], fw_name, device);
if (status) {
wiphy_err(wl->wiphy, "%s: fail to load firmware %s\n",
KBUILD_MODNAME, fw_name);
return status;
}
wl->fw.hdr_num_entries[i] =
wl->fw.fw_hdr[i]->size / (sizeof(struct firmware_hdr));
}
wl->fw.fw_cnt = i;
return brcms_ucode_data_init(wl, &wl->ucode);
}
static void brcms_release_fw(struct brcms_info *wl)
{
int i;
for (i = 0; i < MAX_FW_IMAGES; i++) {
release_firmware(wl->fw.fw_bin[i]);
release_firmware(wl->fw.fw_hdr[i]);
}
}
static void brcms_free(struct brcms_info *wl)
{
struct brcms_timer *t, *next;
if (wl->fw.fw_cnt)
brcms_ucode_data_free(&wl->ucode);
if (wl->irq)
free_irq(wl->irq, wl);
tasklet_kill(&wl->tasklet);
if (wl->pub)
brcms_c_module_unregister(wl->pub, "linux", wl);
if (wl->wlc) {
brcms_c_detach(wl->wlc);
wl->wlc = NULL;
wl->pub = NULL;
}
while (atomic_read(&wl->callbacks) > 0)
schedule();
for (t = wl->timers; t; t = next) {
next = t->next;
#ifdef BCMDBG
kfree(t->name);
#endif
kfree(t);
}
if (wl->regsva)
iounmap(wl->regsva);
wl->regsva = NULL;
}
static void brcms_remove(struct pci_dev *pdev)
{
struct brcms_info *wl;
struct ieee80211_hw *hw;
int status;
hw = pci_get_drvdata(pdev);
wl = hw->priv;
if (!wl) {
pr_err("wl: brcms_remove: pci_get_drvdata failed\n");
return;
}
spin_lock_bh(&wl->lock);
status = brcms_c_chipmatch(pdev->vendor, pdev->device);
spin_unlock_bh(&wl->lock);
if (!status) {
wiphy_err(wl->wiphy, "wl: brcms_remove: chipmatch "
"failed\n");
return;
}
if (wl->wlc) {
wiphy_rfkill_set_hw_state(wl->pub->ieee_hw->wiphy, false);
wiphy_rfkill_stop_polling(wl->pub->ieee_hw->wiphy);
ieee80211_unregister_hw(hw);
spin_lock_bh(&wl->lock);
brcms_down(wl);
spin_unlock_bh(&wl->lock);
}
pci_disable_device(pdev);
brcms_free(wl);
pci_set_drvdata(pdev, NULL);
ieee80211_free_hw(hw);
}
static irqreturn_t brcms_isr(int irq, void *dev_id)
{
struct brcms_info *wl;
bool ours, wantdpc;
wl = (struct brcms_info *) dev_id;
spin_lock(&wl->isr_lock);
ours = brcms_c_isr(wl->wlc, &wantdpc);
if (ours) {
if (wantdpc) {
tasklet_schedule(&wl->tasklet);
}
}
spin_unlock(&wl->isr_lock);
return IRQ_RETVAL(ours);
}
static int ieee_hw_rate_init(struct ieee80211_hw *hw)
{
struct brcms_info *wl = hw->priv;
struct brcms_c_info *wlc = wl->wlc;
struct ieee80211_supported_band *band;
int has_5g = 0;
u16 phy_type;
hw->wiphy->bands[IEEE80211_BAND_2GHZ] = NULL;
hw->wiphy->bands[IEEE80211_BAND_5GHZ] = NULL;
phy_type = brcms_c_get_phy_type(wl->wlc, 0);
if (phy_type == PHY_TYPE_N || phy_type == PHY_TYPE_LCN) {
band = &wlc->bandstate[BAND_2G_INDEX]->band;
*band = brcms_band_2GHz_nphy_template;
if (phy_type == PHY_TYPE_LCN) {
band->ht_cap.mcs.rx_mask[1] = 0;
band->ht_cap.mcs.rx_highest = cpu_to_le16(72);
}
hw->wiphy->bands[IEEE80211_BAND_2GHZ] = band;
} else {
return -EPERM;
}
if (wl->pub->_nbands > 1) {
has_5g++;
if (phy_type == PHY_TYPE_N || phy_type == PHY_TYPE_LCN) {
band = &wlc->bandstate[BAND_5G_INDEX]->band;
*band = brcms_band_5GHz_nphy_template;
hw->wiphy->bands[IEEE80211_BAND_5GHZ] = band;
} else {
return -EPERM;
}
}
return 0;
}
static int ieee_hw_init(struct ieee80211_hw *hw)
{
hw->flags = IEEE80211_HW_SIGNAL_DBM
| IEEE80211_HW_REPORTS_TX_ACK_STATUS
| IEEE80211_HW_AMPDU_AGGREGATION;
hw->extra_tx_headroom = brcms_c_get_header_len();
hw->queues = N_TX_QUEUES;
hw->max_rates = 2;
hw->channel_change_time = 7 * 1000;
hw->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION);
hw->rate_control_algorithm = "minstrel_ht";
hw->sta_data_size = 0;
return ieee_hw_rate_init(hw);
}
static struct brcms_info *brcms_attach(u16 vendor, u16 device,
resource_size_t regs,
struct pci_dev *btparam, uint irq)
{
struct brcms_info *wl = NULL;
int unit, err;
struct ieee80211_hw *hw;
u8 perm[ETH_ALEN];
unit = n_adapters_found;
err = 0;
if (unit < 0)
return NULL;
hw = pci_get_drvdata(btparam);
if (hw != NULL)
wl = hw->priv;
if (WARN_ON(hw == NULL) || WARN_ON(wl == NULL))
return NULL;
wl->wiphy = hw->wiphy;
atomic_set(&wl->callbacks, 0);
tasklet_init(&wl->tasklet, brcms_dpc, (unsigned long) wl);
wl->regsva = ioremap_nocache(regs, PCI_BAR0_WINSZ);
if (wl->regsva == NULL) {
wiphy_err(wl->wiphy, "wl%d: ioremap() failed\n", unit);
goto fail;
}
spin_lock_init(&wl->lock);
spin_lock_init(&wl->isr_lock);
if (brcms_request_fw(wl, btparam) < 0) {
wiphy_err(wl->wiphy, "%s: Failed to find firmware usually in "
"%s\n", KBUILD_MODNAME, "/lib/firmware/brcm");
brcms_release_fw(wl);
brcms_remove(btparam);
return NULL;
}
wl->wlc = brcms_c_attach(wl, vendor, device, unit, false,
wl->regsva, btparam, &err);
brcms_release_fw(wl);
if (!wl->wlc) {
wiphy_err(wl->wiphy, "%s: attach() failed with code %d\n",
KBUILD_MODNAME, err);
goto fail;
}
wl->pub = brcms_c_pub(wl->wlc);
wl->pub->ieee_hw = hw;
brcms_c_set_radio_mpc(wl->wlc, false);
if (request_irq(irq, brcms_isr, IRQF_SHARED, KBUILD_MODNAME, wl)) {
wiphy_err(wl->wiphy, "wl%d: request_irq() failed\n", unit);
goto fail;
}
wl->irq = irq;
brcms_c_module_register(wl->pub, "linux", wl, NULL);
if (ieee_hw_init(hw)) {
wiphy_err(wl->wiphy, "wl%d: %s: ieee_hw_init failed!\n", unit,
__func__);
goto fail;
}
memcpy(perm, &wl->pub->cur_etheraddr, ETH_ALEN);
if (WARN_ON(!is_valid_ether_addr(perm)))
goto fail;
SET_IEEE80211_PERM_ADDR(hw, perm);
err = ieee80211_register_hw(hw);
if (err)
wiphy_err(wl->wiphy, "%s: ieee80211_register_hw failed, status"
"%d\n", __func__, err);
if (wl->pub->srom_ccode[0])
err = brcms_set_hint(wl, wl->pub->srom_ccode);
else
err = brcms_set_hint(wl, "US");
if (err)
wiphy_err(wl->wiphy, "%s: regulatory_hint failed, status %d\n",
__func__, err);
n_adapters_found++;
return wl;
fail:
brcms_free(wl);
return NULL;
}
static int __devinit
brcms_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
struct brcms_info *wl;
struct ieee80211_hw *hw;
u32 val;
dev_info(&pdev->dev, "bus %d slot %d func %d irq %d\n",
pdev->bus->number, PCI_SLOT(pdev->devfn),
PCI_FUNC(pdev->devfn), pdev->irq);
if ((pdev->vendor != PCI_VENDOR_ID_BROADCOM) ||
((pdev->device != 0x0576) &&
((pdev->device & 0xff00) != 0x4300) &&
((pdev->device & 0xff00) != 0x4700) &&
((pdev->device < 43000) || (pdev->device > 43999))))
return -ENODEV;
rc = pci_enable_device(pdev);
if (rc) {
pr_err("%s: Cannot enable device %d-%d_%d\n",
__func__, pdev->bus->number, PCI_SLOT(pdev->devfn),
PCI_FUNC(pdev->devfn));
return -ENODEV;
}
pci_set_master(pdev);
pci_read_config_dword(pdev, 0x40, &val);
if ((val & 0x0000ff00) != 0)
pci_write_config_dword(pdev, 0x40, val & 0xffff00ff);
hw = ieee80211_alloc_hw(sizeof(struct brcms_info), &brcms_ops);
if (!hw) {
pr_err("%s: ieee80211_alloc_hw failed\n", __func__);
return -ENOMEM;
}
SET_IEEE80211_DEV(hw, &pdev->dev);
pci_set_drvdata(pdev, hw);
memset(hw->priv, 0, sizeof(*wl));
wl = brcms_attach(pdev->vendor, pdev->device,
pci_resource_start(pdev, 0), pdev,
pdev->irq);
if (!wl) {
pr_err("%s: %s: brcms_attach failed!\n", KBUILD_MODNAME,
__func__);
return -ENODEV;
}
return 0;
}
static int brcms_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct brcms_info *wl;
struct ieee80211_hw *hw;
hw = pci_get_drvdata(pdev);
wl = hw->priv;
if (!wl) {
wiphy_err(wl->wiphy,
"brcms_suspend: pci_get_drvdata failed\n");
return -ENODEV;
}
spin_lock_bh(&wl->lock);
wl->pub->hw_up = false;
spin_unlock_bh(&wl->lock);
pci_save_state(pdev);
pci_disable_device(pdev);
return pci_set_power_state(pdev, PCI_D3hot);
}
static int brcms_resume(struct pci_dev *pdev)
{
struct brcms_info *wl;
struct ieee80211_hw *hw;
int err = 0;
u32 val;
hw = pci_get_drvdata(pdev);
wl = hw->priv;
if (!wl) {
wiphy_err(wl->wiphy,
"wl: brcms_resume: pci_get_drvdata failed\n");
return -ENODEV;
}
err = pci_set_power_state(pdev, PCI_D0);
if (err)
return err;
pci_restore_state(pdev);
err = pci_enable_device(pdev);
if (err)
return err;
pci_set_master(pdev);
pci_read_config_dword(pdev, 0x40, &val);
if ((val & 0x0000ff00) != 0)
pci_write_config_dword(pdev, 0x40, val & 0xffff00ff);
return err;
}
static int __init brcms_module_init(void)
{
int error = -ENODEV;
#ifdef BCMDBG
if (msglevel != 0xdeadbeef)
brcm_msg_level = msglevel;
#endif
error = pci_register_driver(&brcms_pci_driver);
if (!error)
return 0;
return error;
}
static void __exit brcms_module_exit(void)
{
pci_unregister_driver(&brcms_pci_driver);
}
void brcms_txflowcontrol(struct brcms_info *wl, struct brcms_if *wlif,
bool state, int prio)
{
wiphy_err(wl->wiphy, "Shouldn't be here %s\n", __func__);
}
void brcms_init(struct brcms_info *wl)
{
BCMMSG(wl->pub->ieee_hw->wiphy, "wl%d\n", wl->pub->unit);
brcms_reset(wl);
brcms_c_init(wl->wlc);
}
uint brcms_reset(struct brcms_info *wl)
{
BCMMSG(wl->pub->ieee_hw->wiphy, "wl%d\n", wl->pub->unit);
brcms_c_reset(wl->wlc);
wl->resched = 0;
return 0;
}
void brcms_intrson(struct brcms_info *wl)
{
unsigned long flags;
spin_lock_irqsave(&wl->isr_lock, flags);
brcms_c_intrson(wl->wlc);
spin_unlock_irqrestore(&wl->isr_lock, flags);
}
u32 brcms_intrsoff(struct brcms_info *wl)
{
unsigned long flags;
u32 status;
spin_lock_irqsave(&wl->isr_lock, flags);
status = brcms_c_intrsoff(wl->wlc);
spin_unlock_irqrestore(&wl->isr_lock, flags);
return status;
}
void brcms_intrsrestore(struct brcms_info *wl, u32 macintmask)
{
unsigned long flags;
spin_lock_irqsave(&wl->isr_lock, flags);
brcms_c_intrsrestore(wl->wlc, macintmask);
spin_unlock_irqrestore(&wl->isr_lock, flags);
}
int brcms_up(struct brcms_info *wl)
{
int error = 0;
if (wl->pub->up)
return 0;
error = brcms_c_up(wl->wlc);
return error;
}
void brcms_down(struct brcms_info *wl)
{
uint callbacks, ret_val = 0;
ret_val = brcms_c_down(wl->wlc);
callbacks = atomic_read(&wl->callbacks) - ret_val;
spin_unlock_bh(&wl->lock);
SPINWAIT((atomic_read(&wl->callbacks) > callbacks), 100 * 1000);
spin_lock_bh(&wl->lock);
}
static void _brcms_timer(struct work_struct *work)
{
struct brcms_timer *t = container_of(work, struct brcms_timer,
dly_wrk.work);
spin_lock_bh(&t->wl->lock);
if (t->set) {
if (t->periodic) {
atomic_inc(&t->wl->callbacks);
ieee80211_queue_delayed_work(t->wl->pub->ieee_hw,
&t->dly_wrk,
msecs_to_jiffies(t->ms));
} else {
t->set = false;
}
t->fn(t->arg);
}
atomic_dec(&t->wl->callbacks);
spin_unlock_bh(&t->wl->lock);
}
struct brcms_timer *brcms_init_timer(struct brcms_info *wl,
void (*fn) (void *arg),
void *arg, const char *name)
{
struct brcms_timer *t;
t = kzalloc(sizeof(struct brcms_timer), GFP_ATOMIC);
if (!t)
return NULL;
INIT_DELAYED_WORK(&t->dly_wrk, _brcms_timer);
t->wl = wl;
t->fn = fn;
t->arg = arg;
t->next = wl->timers;
wl->timers = t;
#ifdef BCMDBG
t->name = kmalloc(strlen(name) + 1, GFP_ATOMIC);
if (t->name)
strcpy(t->name, name);
#endif
return t;
}
void brcms_add_timer(struct brcms_timer *t, uint ms, int periodic)
{
struct ieee80211_hw *hw = t->wl->pub->ieee_hw;
#ifdef BCMDBG
if (t->set)
wiphy_err(hw->wiphy, "%s: Already set. Name: %s, per %d\n",
__func__, t->name, periodic);
#endif
t->ms = ms;
t->periodic = (bool) periodic;
t->set = true;
atomic_inc(&t->wl->callbacks);
ieee80211_queue_delayed_work(hw, &t->dly_wrk, msecs_to_jiffies(ms));
}
bool brcms_del_timer(struct brcms_timer *t)
{
if (t->set) {
t->set = false;
if (!cancel_delayed_work(&t->dly_wrk))
return false;
atomic_dec(&t->wl->callbacks);
}
return true;
}
void brcms_free_timer(struct brcms_timer *t)
{
struct brcms_info *wl = t->wl;
struct brcms_timer *tmp;
brcms_del_timer(t);
if (wl->timers == t) {
wl->timers = wl->timers->next;
#ifdef BCMDBG
kfree(t->name);
#endif
kfree(t);
return;
}
tmp = wl->timers;
while (tmp) {
if (tmp->next == t) {
tmp->next = t->next;
#ifdef BCMDBG
kfree(t->name);
#endif
kfree(t);
return;
}
tmp = tmp->next;
}
}
int brcms_ucode_init_buf(struct brcms_info *wl, void **pbuf, u32 idx)
{
int i, entry;
const u8 *pdata;
struct firmware_hdr *hdr;
for (i = 0; i < wl->fw.fw_cnt; i++) {
hdr = (struct firmware_hdr *)wl->fw.fw_hdr[i]->data;
for (entry = 0; entry < wl->fw.hdr_num_entries[i];
entry++, hdr++) {
u32 len = le32_to_cpu(hdr->len);
if (le32_to_cpu(hdr->idx) == idx) {
pdata = wl->fw.fw_bin[i]->data +
le32_to_cpu(hdr->offset);
*pbuf = kmalloc(len, GFP_ATOMIC);
if (*pbuf == NULL)
goto fail;
memcpy(*pbuf, pdata, len);
return 0;
}
}
}
wiphy_err(wl->wiphy, "ERROR: ucode buf tag:%d can not be found!\n",
idx);
*pbuf = NULL;
fail:
return -ENODATA;
}
int brcms_ucode_init_uint(struct brcms_info *wl, size_t *n_bytes, u32 idx)
{
int i, entry;
const u8 *pdata;
struct firmware_hdr *hdr;
for (i = 0; i < wl->fw.fw_cnt; i++) {
hdr = (struct firmware_hdr *)wl->fw.fw_hdr[i]->data;
for (entry = 0; entry < wl->fw.hdr_num_entries[i];
entry++, hdr++) {
if (le32_to_cpu(hdr->idx) == idx) {
pdata = wl->fw.fw_bin[i]->data +
le32_to_cpu(hdr->offset);
if (le32_to_cpu(hdr->len) != 4) {
wiphy_err(wl->wiphy,
"ERROR: fw hdr len\n");
return -ENOMSG;
}
*n_bytes = le32_to_cpu(*((__le32 *) pdata));
return 0;
}
}
}
wiphy_err(wl->wiphy, "ERROR: ucode tag:%d can not be found!\n", idx);
return -ENOMSG;
}
void brcms_ucode_free_buf(void *p)
{
kfree(p);
}
int brcms_check_firmwares(struct brcms_info *wl)
{
int i;
int entry;
int rc = 0;
const struct firmware *fw;
const struct firmware *fw_hdr;
struct firmware_hdr *ucode_hdr;
for (i = 0; i < MAX_FW_IMAGES && rc == 0; i++) {
fw = wl->fw.fw_bin[i];
fw_hdr = wl->fw.fw_hdr[i];
if (fw == NULL && fw_hdr == NULL) {
break;
} else if (fw == NULL || fw_hdr == NULL) {
wiphy_err(wl->wiphy, "%s: invalid bin/hdr fw\n",
__func__);
rc = -EBADF;
} else if (fw_hdr->size % sizeof(struct firmware_hdr)) {
wiphy_err(wl->wiphy, "%s: non integral fw hdr file "
"size %zu/%zu\n", __func__, fw_hdr->size,
sizeof(struct firmware_hdr));
rc = -EBADF;
} else if (fw->size < MIN_FW_SIZE || fw->size > MAX_FW_SIZE) {
wiphy_err(wl->wiphy, "%s: out of bounds fw file size "
"%zu\n", __func__, fw->size);
rc = -EBADF;
} else {
ucode_hdr = (struct firmware_hdr *)fw_hdr->data;
for (entry = 0; entry < wl->fw.hdr_num_entries[i] &&
!rc; entry++, ucode_hdr++) {
if (le32_to_cpu(ucode_hdr->offset) +
le32_to_cpu(ucode_hdr->len) >
fw->size) {
wiphy_err(wl->wiphy,
"%s: conflicting bin/hdr\n",
__func__);
rc = -EBADF;
}
}
}
}
if (rc == 0 && wl->fw.fw_cnt != i) {
wiphy_err(wl->wiphy, "%s: invalid fw_cnt=%d\n", __func__,
wl->fw.fw_cnt);
rc = -EBADF;
}
return rc;
}
bool brcms_rfkill_set_hw_state(struct brcms_info *wl)
{
bool blocked = brcms_c_check_radio_disabled(wl->wlc);
spin_unlock_bh(&wl->lock);
wiphy_rfkill_set_hw_state(wl->pub->ieee_hw->wiphy, blocked);
if (blocked)
wiphy_rfkill_start_polling(wl->pub->ieee_hw->wiphy);
spin_lock_bh(&wl->lock);
return blocked;
}
void brcms_msleep(struct brcms_info *wl, uint ms)
{
spin_unlock_bh(&wl->lock);
msleep(ms);
spin_lock_bh(&wl->lock);
}
