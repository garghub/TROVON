u8 rtl92e_tid_to_ac(struct ieee80211_hw *hw, u8 tid)
{
return tid_to_ac[tid];
}
static void _rtl_init_hw_ht_capab(struct ieee80211_hw *hw,
struct ieee80211_sta_ht_cap *ht_cap)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_phy *rtlphy = &(rtlpriv->phy);
ht_cap->ht_supported = true;
ht_cap->cap = IEEE80211_HT_CAP_SUP_WIDTH_20_40 |
IEEE80211_HT_CAP_SGI_40 |
IEEE80211_HT_CAP_SGI_20 |
IEEE80211_HT_CAP_DSSSCCK40 | IEEE80211_HT_CAP_MAX_AMSDU;
if (rtlpriv->rtlhal.disable_amsdu_8k)
ht_cap->cap &= ~IEEE80211_HT_CAP_MAX_AMSDU;
ht_cap->ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K;
ht_cap->ampdu_density = IEEE80211_HT_MPDU_DENSITY_16;
ht_cap->mcs.tx_params = IEEE80211_HT_MCS_TX_DEFINED;
if (rtlpriv->dm.supp_phymode_switch) {
RT_TRACE(COMP_INIT, DBG_EMERG, ("Support phy mode switch\n"));
ht_cap->mcs.rx_mask[0] = 0xFF;
ht_cap->mcs.rx_mask[1] = 0xFF;
ht_cap->mcs.rx_mask[4] = 0x01;
ht_cap->mcs.rx_highest = cpu_to_le16(MAX_BIT_RATE_40MHZ_MCS15);
} else {
if (get_rf_type(rtlphy) == RF_1T2R ||
get_rf_type(rtlphy) == RF_2T2R) {
RT_TRACE(COMP_INIT, DBG_DMESG, ("1T2R or 2T2R\n"));
ht_cap->mcs.rx_mask[0] = 0xFF;
ht_cap->mcs.rx_mask[1] = 0xFF;
ht_cap->mcs.rx_mask[4] = 0x01;
ht_cap->mcs.rx_highest = cpu_to_le16(MAX_BIT_RATE_40MHZ_MCS15);
} else if (get_rf_type(rtlphy) == RF_1T1R) {
RT_TRACE(COMP_INIT, DBG_DMESG, ("1T1R\n"));
ht_cap->mcs.rx_mask[0] = 0xFF;
ht_cap->mcs.rx_mask[1] = 0x00;
ht_cap->mcs.rx_mask[4] = 0x01;
ht_cap->mcs.rx_highest = cpu_to_le16(MAX_BIT_RATE_40MHZ_MCS7);
}
}
}
static void _rtl_init_hw_vht_capab(struct ieee80211_hw *hw,
struct ieee80211_sta_vht_cap *vht_cap)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_hal *rtlhal = rtl_hal(rtlpriv);
if (rtlhal->hw_type == HARDWARE_TYPE_RTL8812AE) {
u16 mcs_map;
vht_cap->vht_supported = true;
vht_cap->cap =
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895 |
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991 |
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454 |
IEEE80211_VHT_CAP_SHORT_GI_80 |
IEEE80211_VHT_CAP_TXSTBC |
IEEE80211_VHT_CAP_RXSTBC_1 |
IEEE80211_VHT_CAP_SU_BEAMFORMER_CAPABLE |
IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE |
IEEE80211_VHT_CAP_HTC_VHT |
IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK |
IEEE80211_VHT_CAP_RX_ANTENNA_PATTERN |
IEEE80211_VHT_CAP_TX_ANTENNA_PATTERN |
0;
mcs_map = IEEE80211_VHT_MCS_SUPPORT_0_9 << 0 |
IEEE80211_VHT_MCS_SUPPORT_0_9 << 2 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 4 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 6 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 8 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 10 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 12 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 14;
vht_cap->vht_mcs.rx_mcs_map = cpu_to_le16(mcs_map);
vht_cap->vht_mcs.rx_highest =
cpu_to_le16(MAX_BIT_RATE_SHORT_GI_2NSS_80MHZ_MCS9);
vht_cap->vht_mcs.tx_mcs_map = cpu_to_le16(mcs_map);
vht_cap->vht_mcs.tx_highest =
cpu_to_le16(MAX_BIT_RATE_SHORT_GI_2NSS_80MHZ_MCS9);
} else if (rtlhal->hw_type == HARDWARE_TYPE_RTL8821AE) {
u16 mcs_map;
vht_cap->vht_supported = true;
vht_cap->cap =
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895 |
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991 |
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454 |
IEEE80211_VHT_CAP_SHORT_GI_80 |
IEEE80211_VHT_CAP_TXSTBC |
IEEE80211_VHT_CAP_RXSTBC_1 |
IEEE80211_VHT_CAP_SU_BEAMFORMER_CAPABLE |
IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE |
IEEE80211_VHT_CAP_HTC_VHT |
IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK |
IEEE80211_VHT_CAP_RX_ANTENNA_PATTERN |
IEEE80211_VHT_CAP_TX_ANTENNA_PATTERN |
0;
mcs_map = IEEE80211_VHT_MCS_SUPPORT_0_9 << 0 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 2 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 4 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 6 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 8 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 10 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 12 |
IEEE80211_VHT_MCS_NOT_SUPPORTED << 14;
vht_cap->vht_mcs.rx_mcs_map = cpu_to_le16(mcs_map);
vht_cap->vht_mcs.rx_highest =
cpu_to_le16(MAX_BIT_RATE_SHORT_GI_1NSS_80MHZ_MCS9);
vht_cap->vht_mcs.tx_mcs_map = cpu_to_le16(mcs_map);
vht_cap->vht_mcs.tx_highest =
cpu_to_le16(MAX_BIT_RATE_SHORT_GI_1NSS_80MHZ_MCS9);
}
}
static void _rtl_init_mac80211(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_hal *rtlhal = rtl_hal(rtlpriv);
struct rtl_mac *rtlmac = rtl_mac(rtl_priv(hw));
struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
struct ieee80211_supported_band *sband;
if (rtlhal->macphymode == SINGLEMAC_SINGLEPHY &&
rtlhal->bandset == BAND_ON_BOTH) {
sband = &(rtlmac->bands[IEEE80211_BAND_2GHZ]);
memcpy(&(rtlmac->bands[IEEE80211_BAND_2GHZ]), &rtl_band_2ghz,
sizeof(struct ieee80211_supported_band));
_rtl_init_hw_ht_capab(hw, &sband->ht_cap);
hw->wiphy->bands[IEEE80211_BAND_2GHZ] = sband;
sband = &(rtlmac->bands[IEEE80211_BAND_5GHZ]);
memcpy(&(rtlmac->bands[IEEE80211_BAND_5GHZ]), &rtl_band_5ghz,
sizeof(struct ieee80211_supported_band));
_rtl_init_hw_ht_capab(hw, &sband->ht_cap);
_rtl_init_hw_vht_capab(hw, &sband->vht_cap);
hw->wiphy->bands[IEEE80211_BAND_5GHZ] = sband;
} else {
if (rtlhal->current_bandtype == BAND_ON_2_4G) {
sband = &(rtlmac->bands[IEEE80211_BAND_2GHZ]);
memcpy(&(rtlmac->bands[IEEE80211_BAND_2GHZ]),
&rtl_band_2ghz,
sizeof(struct ieee80211_supported_band));
_rtl_init_hw_ht_capab(hw, &sband->ht_cap);
hw->wiphy->bands[IEEE80211_BAND_2GHZ] = sband;
} else if (rtlhal->current_bandtype == BAND_ON_5G) {
sband = &(rtlmac->bands[IEEE80211_BAND_5GHZ]);
memcpy(&(rtlmac->bands[IEEE80211_BAND_5GHZ]),
&rtl_band_5ghz,
sizeof(struct ieee80211_supported_band));
_rtl_init_hw_ht_capab(hw, &sband->ht_cap);
_rtl_init_hw_vht_capab(hw, &sband->vht_cap);
hw->wiphy->bands[IEEE80211_BAND_5GHZ] = sband;
} else {
RT_TRACE(COMP_INIT, DBG_EMERG,
("Err BAND %d\n", rtlhal->current_bandtype));
}
}
hw->flags = IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_RX_INCLUDES_FCS |
IEEE80211_HW_AMPDU_AGGREGATION |
IEEE80211_HW_REPORTS_TX_ACK_STATUS |
IEEE80211_HW_CONNECTION_MONITOR |
IEEE80211_HW_MFP_CAPABLE | 0;
if (rtlpriv->psc.b_swctrl_lps)
hw->flags |= IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_PS_NULLFUNC_STACK |
0;
hw->wiphy->interface_modes =
BIT(NL80211_IFTYPE_AP) |
BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_ADHOC) |
BIT(NL80211_IFTYPE_MESH_POINT) |
BIT(NL80211_IFTYPE_P2P_CLIENT) |
BIT(NL80211_IFTYPE_P2P_GO);
hw->wiphy->flags |= WIPHY_FLAG_IBSS_RSN;
hw->wiphy->flags |= WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL;
hw->wiphy->rts_threshold = 2347;
hw->queues = AC_MAX;
hw->extra_tx_headroom = RTL_TX_HEADER_SIZE;
hw->max_listen_interval = 10;
hw->max_rate_tries = 4;
hw->sta_data_size = sizeof(struct rtl_sta_info);
#ifdef CONFIG_PM
if (rtlpriv->psc.wo_wlan_mode) {
if (rtlpriv->psc.wo_wlan_mode & WAKE_ON_MAGIC_PACKET)
rtlpriv->wowlan.flags = WIPHY_WOWLAN_MAGIC_PKT;
if (rtlpriv->psc.wo_wlan_mode & WAKE_ON_PATTERN_MATCH) {
rtlpriv->wowlan.n_patterns =
MAX_SUPPORT_WOL_PATTERN_NUM;
rtlpriv->wowlan.pattern_min_len = MIN_WOL_PATTERN_SIZE;
rtlpriv->wowlan.pattern_max_len = MAX_WOL_PATTERN_SIZE;
}
hw->wiphy->wowlan = &(rtlpriv->wowlan);
}
#endif
if (is_valid_ether_addr(rtlefuse->dev_addr)) {
SET_IEEE80211_PERM_ADDR(hw, rtlefuse->dev_addr);
} else {
u8 rtlmac[] = { 0x00, 0xe0, 0x4c, 0x81, 0x92, 0x00 };
get_random_bytes((rtlmac + (ETH_ALEN - 1)), 1);
SET_IEEE80211_PERM_ADDR(hw, rtlmac);
}
}
static void _rtl_init_deferred_work(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
init_timer(&rtlpriv->works.watchdog_timer);
setup_timer(&rtlpriv->works.watchdog_timer,
rtl92e_watch_dog_timer_callback, (unsigned long)hw);
init_timer(&rtlpriv->works.dualmac_easyconcurrent_retrytimer);
setup_timer(&rtlpriv->works.dualmac_easyconcurrent_retrytimer,
rtl92e_easy_concurrent_retrytimer_callback, (unsigned long)hw);
rtlpriv->works.hw = hw;
rtlpriv->works.rtl_wq = alloc_workqueue(rtlpriv->cfg->name, 0, 0);
INIT_DELAYED_WORK(&rtlpriv->works.watchdog_wq,
(void *)rtl92e_watchdog_wq_callback);
INIT_DELAYED_WORK(&rtlpriv->works.ips_nic_off_wq,
(void *)rtl92e_ips_nic_off_wq_callback);
INIT_DELAYED_WORK(&rtlpriv->works.ps_work,
(void *)rtl92e_swlps_wq_callback);
INIT_DELAYED_WORK(&rtlpriv->works.ps_rfon_wq,
(void *)rtl92e_swlps_rfon_wq_callback);
INIT_DELAYED_WORK(&rtlpriv->works.fwevt_wq,
(void *)rtl92e_fwevt_wq_callback);
}
void rtl92e_deinit_deferred_work(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
del_timer_sync(&rtlpriv->works.watchdog_timer);
cancel_delayed_work(&rtlpriv->works.watchdog_wq);
cancel_delayed_work(&rtlpriv->works.ips_nic_off_wq);
cancel_delayed_work(&rtlpriv->works.ps_work);
cancel_delayed_work(&rtlpriv->works.ps_rfon_wq);
cancel_delayed_work(&rtlpriv->works.fwevt_wq);
}
void rtl92e_init_rfkill(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
bool radio_state;
bool blocked;
u8 valid = 0;
rtlpriv->rfkill.rfkill_state = 1;
wiphy_rfkill_set_hw_state(hw->wiphy, 0);
radio_state = rtlpriv->cfg->ops->radio_onoff_checking(hw, &valid);
if (valid) {
pr_info("rtlwifi: wireless switch is %s\n",
rtlpriv->rfkill.rfkill_state ? "on" : "off");
rtlpriv->rfkill.rfkill_state = radio_state;
blocked = (rtlpriv->rfkill.rfkill_state == 1) ? 0 : 1;
wiphy_rfkill_set_hw_state(hw->wiphy, blocked);
}
wiphy_rfkill_start_polling(hw->wiphy);
}
void rtl92e_deinit_rfkill(struct ieee80211_hw *hw)
{
wiphy_rfkill_stop_polling(hw->wiphy);
}
static void rtl_init_vif(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
INIT_LIST_HEAD(&rtlpriv->vif_priv.vif_list);
rtlpriv->vif_priv.vifs = 0;
}
int rtl92e_init_core(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *rtlmac = rtl_mac(rtl_priv(hw));
_rtl_init_mac80211(hw);
rtlmac->hw = hw;
rtlmac->link_state = MAC80211_NOLINK;
hw->rate_control_algorithm = "rtl_rc";
if (rtl92e_regd_init(hw, rtl92e_reg_notifier)) {
RT_TRACE(COMP_ERR, DBG_EMERG, ("REGD init failed\n"));
return 1;
}
mutex_init(&rtlpriv->locks.conf_mutex);
spin_lock_init(&rtlpriv->locks.ips_lock);
spin_lock_init(&rtlpriv->locks.irq_th_lock);
spin_lock_init(&rtlpriv->locks.h2c_lock);
spin_lock_init(&rtlpriv->locks.rf_ps_lock);
spin_lock_init(&rtlpriv->locks.rf_lock);
spin_lock_init(&rtlpriv->locks.lps_lock);
spin_lock_init(&rtlpriv->locks.waitq_lock);
spin_lock_init(&rtlpriv->locks.entry_list_lock);
spin_lock_init(&rtlpriv->locks.cck_and_rw_pagea_lock);
spin_lock_init(&rtlpriv->locks.check_sendpkt_lock);
spin_lock_init(&rtlpriv->locks.fw_ps_lock);
spin_lock_init(&rtlpriv->locks.iqk_lock);
INIT_LIST_HEAD(&rtlpriv->entry_list);
_rtl_init_deferred_work(hw);
#ifdef VIF_TODO
rtl_init_vif(hw);
#endif
return 0;
}
void rtl92e_deinit_core(struct ieee80211_hw *hw)
{
}
void rtl92e_init_rx_config(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
rtlpriv->cfg->ops->get_hw_reg(hw, HW_VAR_RCR, (u8 *)(&mac->rx_conf));
}
static void _rtl_qurey_shortpreamble_mode(struct ieee80211_hw *hw,
struct rtl_tcb_desc *tcb_desc,
struct ieee80211_tx_info *info)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
u8 rate_flag = info->control.rates[0].flags;
tcb_desc->use_shortpreamble = false;
if (tcb_desc->hw_rate == rtlpriv->cfg->maps[RTL_RC_CCK_RATE1M])
return;
else if (rate_flag & IEEE80211_TX_RC_USE_SHORT_PREAMBLE)
tcb_desc->use_shortpreamble = true;
return;
}
static void _rtl_query_shortgi(struct ieee80211_hw *hw,
struct ieee80211_sta *sta,
struct rtl_tcb_desc *tcb_desc,
struct ieee80211_tx_info *info)
{
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
u8 rate_flag = info->control.rates[0].flags;
u8 sgi_40 = 0, sgi_20 = 0, bw_40 = 0;
u8 sgi_80 = 0, bw_80 = 0;
tcb_desc->use_shortgi = false;
if (sta == NULL)
return;
sgi_40 = sta->ht_cap.cap & IEEE80211_HT_CAP_SGI_40;
sgi_20 = sta->ht_cap.cap & IEEE80211_HT_CAP_SGI_20;
sgi_80 = sta->vht_cap.cap & IEEE80211_VHT_CAP_SHORT_GI_80;
if (!(sta->ht_cap.ht_supported) && !(sta->vht_cap.vht_supported))
return;
if (!sgi_40 && !sgi_20)
return;
if (mac->opmode == NL80211_IFTYPE_STATION) {
bw_40 = mac->bw_40;
bw_80 = mac->bw_80;
} else if (mac->opmode == NL80211_IFTYPE_AP ||
mac->opmode == NL80211_IFTYPE_ADHOC ||
mac->opmode == NL80211_IFTYPE_MESH_POINT) {
bw_40 = sta->ht_cap.cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40;
bw_80 = sta->vht_cap.vht_supported;
}
if (bw_80) {
if (sgi_80)
tcb_desc->use_shortgi = true;
else
tcb_desc->use_shortgi = false;
} else {
if (bw_40 && sgi_40)
tcb_desc->use_shortgi = true;
else if (!bw_40 && sgi_20)
tcb_desc->use_shortgi = true;
}
if (!(rate_flag & IEEE80211_TX_RC_SHORT_GI))
tcb_desc->use_shortgi = false;
}
static void _rtl_query_protection_mode(struct ieee80211_hw *hw,
struct rtl_tcb_desc *tcb_desc,
struct ieee80211_tx_info *info)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
u8 rate_flag = info->control.rates[0].flags;
tcb_desc->b_rts_stbc = false;
tcb_desc->b_cts_enable = false;
tcb_desc->rts_sc = 0;
tcb_desc->b_rts_bw = false;
tcb_desc->b_rts_use_shortpreamble = false;
tcb_desc->b_rts_use_shortgi = false;
if (rate_flag & IEEE80211_TX_RC_USE_CTS_PROTECT) {
tcb_desc->b_rts_enable = true;
tcb_desc->b_cts_enable = true;
tcb_desc->rts_rate = rtlpriv->cfg->maps[RTL_RC_OFDM_RATE24M];
} else if (rate_flag & IEEE80211_TX_RC_USE_RTS_CTS) {
tcb_desc->b_rts_enable = true;
tcb_desc->rts_rate = rtlpriv->cfg->maps[RTL_RC_OFDM_RATE24M];
}
}
static void _rtl_txrate_selectmode(struct ieee80211_hw *hw,
struct ieee80211_sta *sta,
struct rtl_tcb_desc *tcb_desc)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
struct rtl_sta_info *sta_entry = NULL;
u8 ratr_index = 7;
if (sta) {
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
ratr_index = sta_entry->ratr_index;
}
if (!tcb_desc->disable_ratefallback || !tcb_desc->use_driver_rate) {
if (mac->opmode == NL80211_IFTYPE_STATION) {
tcb_desc->ratr_index = 0;
} else if (mac->opmode == NL80211_IFTYPE_ADHOC ||
mac->opmode == NL80211_IFTYPE_MESH_POINT) {
if (tcb_desc->b_multicast || tcb_desc->b_broadcast) {
tcb_desc->hw_rate =
rtlpriv->cfg->maps[RTL_RC_CCK_RATE2M];
tcb_desc->use_driver_rate = 1;
tcb_desc->ratr_index = RATR_INX_WIRELESS_MC;
} else {
tcb_desc->ratr_index = ratr_index;
}
} else if (mac->opmode == NL80211_IFTYPE_AP) {
tcb_desc->ratr_index = ratr_index;
}
}
if (rtlpriv->dm.b_useramask) {
tcb_desc->ratr_index = ratr_index;
if (mac->opmode == NL80211_IFTYPE_STATION ||
mac->opmode == NL80211_IFTYPE_MESH_POINT) {
tcb_desc->mac_id = 0;
if (mac->mode == WIRELESS_MODE_AC_5G)
tcb_desc->ratr_index =
RATR_INX_WIRELESS_AC_5N;
else if (mac->mode == WIRELESS_MODE_AC_24G)
tcb_desc->ratr_index =
RATR_INX_WIRELESS_AC_24N;
else if (mac->mode == WIRELESS_MODE_N_24G)
tcb_desc->ratr_index = RATR_INX_WIRELESS_NGB;
else if (mac->mode == WIRELESS_MODE_N_5G)
tcb_desc->ratr_index = RATR_INX_WIRELESS_NG;
else if (mac->mode & WIRELESS_MODE_G)
tcb_desc->ratr_index = RATR_INX_WIRELESS_GB;
else if (mac->mode & WIRELESS_MODE_B)
tcb_desc->ratr_index = RATR_INX_WIRELESS_B;
else if (mac->mode & WIRELESS_MODE_A)
tcb_desc->ratr_index = RATR_INX_WIRELESS_G;
} else if (mac->opmode == NL80211_IFTYPE_AP ||
mac->opmode == NL80211_IFTYPE_ADHOC) {
if (sta) {
if (sta->aid > 0)
tcb_desc->mac_id = sta->aid + 1;
else
tcb_desc->mac_id = 1;
} else {
tcb_desc->mac_id = 0;
}
}
}
}
static void _rtl_query_bandwidth_mode(struct ieee80211_hw *hw,
struct ieee80211_sta *sta,
struct rtl_tcb_desc *tcb_desc)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
tcb_desc->packet_bw = 0;
if (!sta)
return;
if (mac->opmode == NL80211_IFTYPE_AP ||
mac->opmode == NL80211_IFTYPE_ADHOC ||
mac->opmode == NL80211_IFTYPE_MESH_POINT) {
if (!(sta->ht_cap.ht_supported) ||
!(sta->ht_cap.cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40))
return;
} else if (mac->opmode == NL80211_IFTYPE_STATION) {
if (!mac->bw_40 || !(sta->ht_cap.ht_supported))
return;
}
if (tcb_desc->b_multicast || tcb_desc->b_broadcast)
return;
if (tcb_desc->hw_rate <= rtlpriv->cfg->maps[RTL_RC_OFDM_RATE54M])
return;
tcb_desc->packet_bw = HT_CHANNEL_WIDTH_20_40;
if (rtlpriv->rtlhal.hw_type == HARDWARE_TYPE_RTL8812AE ||
rtlpriv->rtlhal.hw_type == HARDWARE_TYPE_RTL8821AE) {
if (mac->opmode == NL80211_IFTYPE_AP ||
mac->opmode == NL80211_IFTYPE_ADHOC ||
mac->opmode == NL80211_IFTYPE_MESH_POINT) {
if (!(sta->vht_cap.vht_supported)) {
return;
} else if (mac->opmode == NL80211_IFTYPE_STATION) {
if (!mac->bw_80 ||
!(sta->vht_cap.vht_supported))
return;
}
}
if (tcb_desc->hw_rate <=
rtlpriv->cfg->maps[RTL_RC_HT_RATEMCS15])
return;
tcb_desc->packet_bw = HT_CHANNEL_WIDTH_80;
}
}
static u8 _rtl_get_vht_highest_n_rate(struct ieee80211_hw *hw,
struct ieee80211_sta *sta)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_phy *rtlphy = &(rtlpriv->phy);
u8 hw_rate;
u16 map = le16_to_cpu(sta->vht_cap.vht_mcs.tx_mcs_map);
if ((get_rf_type(rtlphy) == RF_2T2R) &&
(map & 0x000c) != 0x000c0) {
if ((map & 0x000c) >> 2 == IEEE80211_VHT_MCS_SUPPORT_0_7)
hw_rate =
rtlpriv->cfg->maps[RTL_RC_VHT_RATE_2SS_MCS7];
else if ((map & 0x000c) >> 2 == IEEE80211_VHT_MCS_SUPPORT_0_8)
hw_rate = rtlpriv->cfg->maps[RTL_RC_VHT_RATE_2SS_MCS9];
else
hw_rate = rtlpriv->cfg->maps[RTL_RC_VHT_RATE_2SS_MCS9];
} else {
if ((map & 0x0003) == IEEE80211_VHT_MCS_SUPPORT_0_7)
hw_rate = rtlpriv->cfg->maps[RTL_RC_VHT_RATE_1SS_MCS7];
else if ((map & 0x0003) == IEEE80211_VHT_MCS_SUPPORT_0_8)
hw_rate = rtlpriv->cfg->maps[RTL_RC_VHT_RATE_1SS_MCS9];
else
hw_rate = rtlpriv->cfg->maps[RTL_RC_VHT_RATE_1SS_MCS9];
}
return hw_rate;
}
static u8 _rtl_get_highest_n_rate(struct ieee80211_hw *hw,
struct ieee80211_sta *sta)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_phy *rtlphy = &(rtlpriv->phy);
u8 hw_rate;
if ((get_rf_type(rtlphy) == RF_2T2R) &&
(sta->ht_cap.mcs.rx_mask[1] != 0))
hw_rate = rtlpriv->cfg->maps[RTL_RC_HT_RATEMCS15];
else
hw_rate = rtlpriv->cfg->maps[RTL_RC_HT_RATEMCS7];
return hw_rate;
}
void stg_rtl_get_tcb_desc(struct ieee80211_hw *hw,
struct ieee80211_tx_info *info,
struct ieee80211_sta *sta,
struct sk_buff *skb, struct rtl_tcb_desc *tcb_desc)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *rtlmac = rtl_mac(rtl_priv(hw));
struct ieee80211_hdr *hdr = rtl_get_hdr(skb);
struct ieee80211_rate *txrate;
__le16 fc = rtl_get_fc(skb);
txrate = ieee80211_get_tx_rate(hw, info);
if (txrate != NULL)
tcb_desc->hw_rate = txrate->hw_value;
if (ieee80211_is_data(fc)) {
if (info->control.rates[0].idx == 0 ||
ieee80211_is_nullfunc(fc)) {
tcb_desc->use_driver_rate = true;
tcb_desc->ratr_index = RATR_INX_WIRELESS_MC;
tcb_desc->disable_ratefallback = 1;
} else {
if (sta && sta->vht_cap.vht_supported) {
tcb_desc->hw_rate =
_rtl_get_vht_highest_n_rate(hw, sta);
} else if (sta && (sta->ht_cap.ht_supported)) {
tcb_desc->hw_rate =
_rtl_get_highest_n_rate(hw, sta);
} else {
if (rtlmac->mode == WIRELESS_MODE_B) {
tcb_desc->hw_rate =
rtlpriv->cfg->maps[RTL_RC_CCK_RATE11M];
} else {
tcb_desc->hw_rate =
rtlpriv->cfg->maps[RTL_RC_OFDM_RATE54M];
}
}
}
if (is_multicast_ether_addr(ieee80211_get_DA(hdr)))
tcb_desc->b_multicast = 1;
else if (is_broadcast_ether_addr(ieee80211_get_DA(hdr)))
tcb_desc->b_broadcast = 1;
_rtl_txrate_selectmode(hw, sta, tcb_desc);
_rtl_query_bandwidth_mode(hw, sta, tcb_desc);
_rtl_qurey_shortpreamble_mode(hw, tcb_desc, info);
_rtl_query_shortgi(hw, sta, tcb_desc, info);
_rtl_query_protection_mode(hw, tcb_desc, info);
} else {
tcb_desc->use_driver_rate = true;
tcb_desc->ratr_index = RATR_INX_WIRELESS_MC;
tcb_desc->disable_ratefallback = 1;
tcb_desc->mac_id = 0;
tcb_desc->packet_bw = 0;
}
}
bool rtl92e_tx_mgmt_proc(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
struct rtl_priv *rtlpriv = rtl_priv(hw);
__le16 fc = rtl_get_fc(skb);
if (rtlpriv->dm.supp_phymode_switch &&
mac->link_state < MAC80211_LINKED &&
(ieee80211_is_auth(fc) || ieee80211_is_probe_req(fc))) {
if (rtlpriv->cfg->ops->check_switch_to_dmdp)
rtlpriv->cfg->ops->check_switch_to_dmdp(hw);
}
if (ieee80211_is_auth(fc)) {
RT_TRACE(COMP_SEND, DBG_DMESG, ("MAC80211_LINKING\n"));
rtl92e_ips_nic_on(hw);
mac->link_state = MAC80211_LINKING;
rtlpriv->phy.b_need_iqk = true;
}
return true;
}
bool rtl92e_action_proc(struct ieee80211_hw *hw, struct sk_buff *skb, u8 is_tx)
{
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
struct ieee80211_hdr *hdr = rtl_get_hdr(skb);
struct rtl_priv *rtlpriv = rtl_priv(hw);
__le16 fc = rtl_get_fc(skb);
u8 *act = (u8 *)(((u8 *)skb->data + MAC80211_3ADDR_LEN));
u8 category;
if (!ieee80211_is_action(fc))
return true;
category = *act;
act++;
switch (category) {
case ACT_CAT_BA:
switch (*act) {
case ACT_ADDBAREQ:
if (mac->act_scanning)
return false;
RT_TRACE((COMP_SEND | COMP_RECV), DBG_DMESG,
("%s ACT_ADDBAREQ From:%pM\n",
is_tx ? "Tx" : "Rx", hdr->addr2));
RT_PRINT_DATA(rtlpriv, COMP_INIT, DBG_DMESG, "req\n",
skb->data, skb->len);
if (!is_tx) {
struct ieee80211_sta *sta = NULL;
struct rtl_sta_info *sta_entry = NULL;
struct ieee80211_mgmt *mgmt = (void *)skb->data;
u16 capab = 0, tid = 0;
struct rtl_tid_data *tid_data;
struct sk_buff *skb_delba = NULL;
struct ieee80211_rx_status rx_status = { 0 };
rcu_read_lock();
sta = rtl_find_sta(hw, hdr->addr3);
if (sta == NULL) {
RT_TRACE((COMP_SEND | COMP_RECV),
DBG_TRACE, ("sta is NULL\n"));
rcu_read_unlock();
return true;
}
sta_entry =
(struct rtl_sta_info *)sta->drv_priv;
if (!sta_entry) {
rcu_read_unlock();
return true;
}
capab = le16_to_cpu(mgmt->u.action.u.addba_req.capab);
tid = (capab &
IEEE80211_ADDBA_PARAM_TID_MASK) >> 2;
tid_data = &sta_entry->tids[tid];
if (tid_data->agg.rx_agg_state ==
RTL_RX_AGG_START) {
skb_delba = rtl92e_make_del_ba(hw,
hdr->addr2,
hdr->addr3,
tid);
if (skb_delba) {
rx_status.freq =
hw->conf.chandef.chan->center_freq;
rx_status.band =
hw->conf.chandef.chan->band;
rx_status.flag |= RX_FLAG_DECRYPTED;
rx_status.flag |= RX_FLAG_MACTIME_MPDU;
rx_status.rate_idx = 0;
rx_status.signal = 50 + 10;
memcpy(IEEE80211_SKB_RXCB(skb_delba),
&rx_status, sizeof(rx_status));
RT_PRINT_DATA(rtlpriv, COMP_INIT, DBG_DMESG,
"fake del\n",
skb_delba->data, skb_delba->len);
ieee80211_rx_irqsafe(hw, skb_delba);
}
}
rcu_read_unlock();
}
break;
case ACT_ADDBARSP:
RT_TRACE((COMP_SEND | COMP_RECV), DBG_DMESG,
("%s ACT_ADDBARSP From :%pM\n",
is_tx ? "Tx" : "Rx", hdr->addr2));
break;
case ACT_DELBA:
RT_TRACE((COMP_SEND | COMP_RECV), DBG_DMESG,
("ACT_ADDBADEL From :%pM\n", hdr->addr2));
break;
}
break;
default:
break;
}
return true;
}
u8 rtl92e_is_special_data(struct ieee80211_hw *hw, struct sk_buff *skb,
u8 is_tx)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_ps_ctl *ppsc = rtl_psc(rtl_priv(hw));
__le16 fc = rtl_get_fc(skb);
u16 ether_type;
u8 mac_hdr_len = ieee80211_get_hdrlen_from_skb(skb);
const struct iphdr *ip;
if (!ieee80211_is_data(fc))
goto end;
ip = (struct iphdr *)((u8 *)skb->data + mac_hdr_len +
SNAP_SIZE + PROTOC_TYPE_SIZE);
ether_type = be16_to_cpup((__be16 *)
(skb->data + mac_hdr_len + SNAP_SIZE));
if (ETH_P_IP == ether_type) {
if (IPPROTO_UDP == ip->protocol) {
struct udphdr *udp = (struct udphdr *)((u8 *)ip +
(ip->ihl << 2));
if (((((u8 *)udp)[1] == 68) &&
(((u8 *)udp)[3] == 67)) ||
((((u8 *)udp)[1] == 67) &&
(((u8 *)udp)[3] == 68))) {
RT_TRACE((COMP_SEND | COMP_RECV),
DBG_DMESG, ("dhcp %s !!\n",
(is_tx) ? "Tx" : "Rx"));
if (is_tx) {
rtlpriv->ra.is_special_data = true;
if (rtlpriv->cfg->ops->get_btc_status())
rtlpriv->btcoexist.btc_ops->btc_special_packet_notify(
rtlpriv, 1);
rtl92e_lps_leave(hw);
ppsc->last_delaylps_stamp_jiffies =
jiffies;
}
return true;
}
}
} else if (ETH_P_ARP == ether_type) {
if (is_tx) {
rtlpriv->ra.is_special_data = true;
if (rtlpriv->cfg->ops->get_btc_status())
rtlpriv->btcoexist.btc_ops->btc_special_packet_notify(
rtlpriv, 1);
rtl92e_lps_leave(hw);
ppsc->last_delaylps_stamp_jiffies = jiffies;
}
return true;
} else if (ETH_P_PAE == ether_type) {
RT_TRACE((COMP_SEND | COMP_RECV), DBG_DMESG,
("802.1X %s EAPOL pkt!!\n", (is_tx) ? "Tx" : "Rx"));
if (is_tx) {
rtlpriv->ra.is_special_data = true;
rtl92e_lps_leave(hw);
ppsc->last_delaylps_stamp_jiffies = jiffies;
}
return true;
} else if (0x86DD == ether_type) {
return true;
}
end:
rtlpriv->ra.is_special_data = false;
return false;
}
int rtl92e_tx_agg_start(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid, u16 *ssn)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_tid_data *tid_data;
struct rtl_sta_info *sta_entry = NULL;
if (sta == NULL)
return -EINVAL;
if (unlikely(tid >= MAX_TID_COUNT))
return -EINVAL;
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
if (!sta_entry)
return -ENXIO;
tid_data = &sta_entry->tids[tid];
RT_TRACE(COMP_SEND, DBG_DMESG,
("on ra = %pM tid = %d seq:%d\n", sta->addr, tid,
tid_data->seq_number));
*ssn = tid_data->seq_number;
tid_data->agg.agg_state = RTL_AGG_START;
ieee80211_start_tx_ba_cb_irqsafe(vif, sta->addr, tid);
return 0;
}
int rtl92e_tx_agg_stop(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_sta *sta, u16 tid)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_tid_data *tid_data;
struct rtl_sta_info *sta_entry = NULL;
if (sta == NULL)
return -EINVAL;
RT_TRACE(COMP_SEND, DBG_DMESG,
("on ra = %pM tid = %d\n", sta->addr, tid));
if (unlikely(tid >= MAX_TID_COUNT))
return -EINVAL;
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
tid_data = &sta_entry->tids[tid];
sta_entry->tids[tid].agg.agg_state = RTL_AGG_STOP;
ieee80211_stop_tx_ba_cb_irqsafe(vif, sta->addr, tid);
return 0;
}
int rtl92e_rx_agg_start(struct ieee80211_hw *hw,
struct ieee80211_sta *sta, u16 tid)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_tid_data *tid_data;
struct rtl_sta_info *sta_entry = NULL;
if (sta == NULL)
return -EINVAL;
if (unlikely(tid >= MAX_TID_COUNT))
return -EINVAL;
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
if (!sta_entry)
return -ENXIO;
tid_data = &sta_entry->tids[tid];
RT_TRACE(COMP_RECV, DBG_DMESG,
("on ra = %pM tid = %d seq:%d\n", sta->addr, tid,
tid_data->seq_number));
tid_data->agg.rx_agg_state = RTL_RX_AGG_START;
return 0;
}
int rtl92e_rx_agg_stop(struct ieee80211_hw *hw,
struct ieee80211_sta *sta, u16 tid)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_tid_data *tid_data;
struct rtl_sta_info *sta_entry = NULL;
if (sta == NULL)
return -EINVAL;
RT_TRACE(COMP_SEND, DBG_DMESG,
("on ra = %pM tid = %d\n", sta->addr, tid));
if (unlikely(tid >= MAX_TID_COUNT))
return -EINVAL;
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
tid_data = &sta_entry->tids[tid];
sta_entry->tids[tid].agg.rx_agg_state = RTL_RX_AGG_STOP;
return 0;
}
int rtl92e_tx_agg_oper(struct ieee80211_hw *hw,
struct ieee80211_sta *sta, u16 tid)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_tid_data *tid_data;
struct rtl_sta_info *sta_entry = NULL;
if (sta == NULL)
return -EINVAL;
RT_TRACE(COMP_SEND, DBG_DMESG,
("on ra = %pM tid = %d\n", sta->addr, tid));
if (unlikely(tid >= MAX_TID_COUNT))
return -EINVAL;
sta_entry = (struct rtl_sta_info *)sta->drv_priv;
tid_data = &sta_entry->tids[tid];
sta_entry->tids[tid].agg.agg_state = RTL_AGG_OPERATIONAL;
return 0;
}
void rtl92e_beacon_statistic(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
if (rtlpriv->mac80211.opmode != NL80211_IFTYPE_STATION)
return;
if (rtlpriv->mac80211.link_state < MAC80211_LINKED)
return;
if (!ieee80211_is_beacon(hdr->frame_control) &&
!ieee80211_is_probe_resp(hdr->frame_control))
return;
if (skb->len <= 40 + FCS_LEN)
return;
if (!ether_addr_equal(hdr->addr3, rtlpriv->mac80211.bssid))
return;
rtlpriv->link_info.bcn_rx_inperiod++;
}
void rtl92e_watchdog_wq_callback(void *data)
{
struct rtl_works *rtlworks = container_of_dwork_rtl(data,
struct rtl_works,
watchdog_wq);
struct ieee80211_hw *hw = rtlworks->hw;
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
bool b_busytraffic = false;
bool b_tx_busy_traffic = false;
bool b_rx_busy_traffic = false;
bool b_higher_busytraffic = false;
bool b_higher_busyrxtraffic = false;
u8 idx, tid;
u32 rx_cnt_inp4eriod = 0;
u32 tx_cnt_inp4eriod = 0;
u32 aver_rx_cnt_inperiod = 0;
u32 aver_tx_cnt_inperiod = 0;
u32 aver_tidtx_inperiod[MAX_TID_COUNT] = {0};
u32 tidtx_inp4eriod[MAX_TID_COUNT] = {0};
bool benter_ps = false;
if (is_hal_stop(rtlhal))
return;
if (mac->link_state > MAC80211_NOLINK) {
if (mac->cnt_after_linked < 20)
mac->cnt_after_linked++;
} else {
mac->cnt_after_linked = 0;
}
if (mac->link_state >= MAC80211_LINKED) {
for (idx = 0; idx <= 2; idx++) {
rtlpriv->link_info.num_rx_in4period[idx] =
rtlpriv->link_info.num_rx_in4period[idx + 1];
rtlpriv->link_info.num_tx_in4period[idx] =
rtlpriv->link_info.num_tx_in4period[idx + 1];
}
rtlpriv->link_info.num_rx_in4period[3] =
rtlpriv->link_info.num_rx_inperiod;
rtlpriv->link_info.num_tx_in4period[3] =
rtlpriv->link_info.num_tx_inperiod;
for (idx = 0; idx <= 3; idx++) {
rx_cnt_inp4eriod +=
rtlpriv->link_info.num_rx_in4period[idx];
tx_cnt_inp4eriod +=
rtlpriv->link_info.num_tx_in4period[idx];
}
aver_rx_cnt_inperiod = rx_cnt_inp4eriod / 4;
aver_tx_cnt_inperiod = tx_cnt_inp4eriod / 4;
if (aver_rx_cnt_inperiod > 100 || aver_tx_cnt_inperiod > 100) {
b_busytraffic = true;
if (aver_rx_cnt_inperiod > aver_tx_cnt_inperiod)
b_rx_busy_traffic = true;
else
b_tx_busy_traffic = false;
}
if (aver_rx_cnt_inperiod > 4000 ||
aver_tx_cnt_inperiod > 4000) {
b_higher_busytraffic = true;
if (aver_rx_cnt_inperiod > 5000)
b_higher_busyrxtraffic = true;
}
for (tid = 0; tid <= 7; tid++) {
for (idx = 0; idx <= 2; idx++)
rtlpriv->link_info.tidtx_in4period[tid][idx] =
rtlpriv->link_info.tidtx_in4period[tid]
[idx + 1];
rtlpriv->link_info.tidtx_in4period[tid][3] =
rtlpriv->link_info.tidtx_inperiod[tid];
for (idx = 0; idx <= 3; idx++)
tidtx_inp4eriod[tid] +=
rtlpriv->link_info.tidtx_in4period[tid][idx];
aver_tidtx_inperiod[tid] = tidtx_inp4eriod[tid] / 4;
if (aver_tidtx_inperiod[tid] > 5000)
rtlpriv->link_info.higher_busytxtraffic[tid] =
true;
else
rtlpriv->link_info.higher_busytxtraffic[tid] =
false;
}
if (((rtlpriv->link_info.num_rx_inperiod +
rtlpriv->link_info.num_tx_inperiod) > 8) ||
(rtlpriv->link_info.num_rx_inperiod > 2))
benter_ps = false;
else
benter_ps = true;
if (benter_ps)
rtl92e_lps_enter(hw);
else
rtl92e_lps_leave(hw);
}
rtlpriv->link_info.num_rx_inperiod = 0;
rtlpriv->link_info.num_tx_inperiod = 0;
for (tid = 0; tid <= 7; tid++)
rtlpriv->link_info.tidtx_inperiod[tid] = 0;
rtlpriv->link_info.b_busytraffic = b_busytraffic;
rtlpriv->link_info.b_rx_busy_traffic = b_rx_busy_traffic;
rtlpriv->link_info.b_tx_busy_traffic = b_tx_busy_traffic;
rtlpriv->link_info.b_higher_busytraffic = b_higher_busytraffic;
rtlpriv->link_info.b_higher_busyrxtraffic = b_higher_busyrxtraffic;
rtlpriv->cfg->ops->dm_watchdog(hw);
if (mac->link_state == MAC80211_LINKED &&
mac->opmode == NL80211_IFTYPE_STATION) {
if ((rtlpriv->link_info.bcn_rx_inperiod +
rtlpriv->link_info.num_rx_inperiod) == 0) {
rtlpriv->link_info.roam_times++;
RT_TRACE(COMP_ERR, DBG_DMESG,
("AP off for %d s\n",
(rtlpriv->link_info.roam_times * 2)));
if (rtlpriv->link_info.roam_times >= 5) {
RT_TRACE(COMP_ERR, DBG_EMERG,
("AP off, try to reconnect now\n"));
rtlpriv->link_info.roam_times = 0;
ieee80211_connection_loss(
rtlpriv->mac80211.vif);
}
} else {
rtlpriv->link_info.roam_times = 0;
}
}
if (rtlpriv->cfg->ops->get_btc_status())
rtlpriv->btcoexist.btc_ops->btc_periodical(rtlpriv);
rtlpriv->link_info.bcn_rx_inperiod = 0;
}
void rtl92e_watch_dog_timer_callback(unsigned long data)
{
struct ieee80211_hw *hw = (struct ieee80211_hw *)data;
struct rtl_priv *rtlpriv = rtl_priv(hw);
queue_delayed_work(rtlpriv->works.rtl_wq,
&rtlpriv->works.watchdog_wq, 0);
mod_timer(&rtlpriv->works.watchdog_timer,
jiffies + MSECS(RTL_WATCH_DOG_TIME));
}
void rtl92e_fwevt_wq_callback(void *data)
{
struct rtl_works *rtlworks =
container_of_dwork_rtl(data, struct rtl_works, fwevt_wq);
struct ieee80211_hw *hw = rtlworks->hw;
struct rtl_priv *rtlpriv = rtl_priv(hw);
rtlpriv->cfg->ops->c2h_command_handle(hw);
}
void rtl92e_easy_concurrent_retrytimer_callback(unsigned long data)
{
struct ieee80211_hw *hw = (struct ieee80211_hw *)data;
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_priv *buddy_priv = rtlpriv->buddy_priv;
if (buddy_priv == NULL)
return;
rtlpriv->cfg->ops->dualmac_easy_concurrent(hw);
}
u8 *rtl92e_find_ie(u8 *data, unsigned int len, u8 ie)
{
struct ieee80211_mgmt *mgmt = (void *)data;
u8 *pos, *end;
pos = (u8 *)mgmt->u.beacon.variable;
end = data + len;
while (pos < end) {
if (pos + 2 + pos[1] > end)
return NULL;
if (pos[0] == ie)
return pos;
pos += 2 + pos[1];
}
return NULL;
}
static struct sk_buff *rtl_make_smps_action(struct ieee80211_hw *hw,
enum ieee80211_smps_mode smps,
u8 *da, u8 *bssid)
{
struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
struct sk_buff *skb;
struct ieee80211_mgmt_compat *action_frame;
skb = dev_alloc_skb(27 + hw->extra_tx_headroom);
if (!skb)
return NULL;
skb_reserve(skb, hw->extra_tx_headroom);
action_frame = (void *)skb_put(skb, 27);
memset(action_frame, 0, 27);
ether_addr_copy(action_frame->da, da);
ether_addr_copy(action_frame->sa, rtlefuse->dev_addr);
ether_addr_copy(action_frame->bssid, bssid);
action_frame->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
IEEE80211_STYPE_ACTION);
action_frame->u.action.category = WLAN_CATEGORY_HT;
action_frame->u.action.u.ht_smps.action = WLAN_HT_ACTION_SMPS;
switch (smps) {
case IEEE80211_SMPS_AUTOMATIC:
case IEEE80211_SMPS_NUM_MODES:
WARN_ON(1);
case IEEE80211_SMPS_OFF:
action_frame->u.action.u.ht_smps.smps_control =
WLAN_HT_SMPS_CONTROL_DISABLED;
break;
case IEEE80211_SMPS_STATIC:
action_frame->u.action.u.ht_smps.smps_control =
WLAN_HT_SMPS_CONTROL_STATIC;
break;
case IEEE80211_SMPS_DYNAMIC:
action_frame->u.action.u.ht_smps.smps_control =
WLAN_HT_SMPS_CONTROL_DYNAMIC;
break;
}
return skb;
}
int stg_rtl_send_smps_action(struct ieee80211_hw *hw,
struct ieee80211_sta *sta,
enum ieee80211_smps_mode smps)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
struct rtl_ps_ctl *ppsc = rtl_psc(rtl_priv(hw));
struct sk_buff *skb = NULL;
struct rtl_tcb_desc tcb_desc;
u8 bssid[ETH_ALEN] = {0};
memset(&tcb_desc, 0, sizeof(struct rtl_tcb_desc));
if (rtlpriv->mac80211.act_scanning)
goto err_free;
if (!sta)
goto err_free;
if (unlikely(is_hal_stop(rtlhal) || ppsc->rfpwr_state != ERFON))
goto err_free;
if (!test_bit(RTL_STATUS_INTERFACE_START, &rtlpriv->status))
goto err_free;
if (rtlpriv->mac80211.opmode == NL80211_IFTYPE_AP)
ether_addr_copy(bssid, rtlpriv->efuse.dev_addr);
else
ether_addr_copy(bssid, rtlpriv->mac80211.bssid);
skb = rtl_make_smps_action(hw, smps, sta->addr, bssid);
if (skb) {
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct rtl_sta_info *sta_entry =
(struct rtl_sta_info *)sta->drv_priv;
sta_entry->mimo_ps = smps;
info->control.rates[0].idx = 0;
info->band = hw->conf.chandef.chan->band;
rtlpriv->intf_ops->adapter_tx(hw, sta, skb, &tcb_desc);
}
return 1;
err_free:
return 0;
}
struct sk_buff *rtl92e_make_del_ba(struct ieee80211_hw *hw,
u8 *sa, u8 *bssid, u16 tid)
{
struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
struct sk_buff *skb;
struct ieee80211_mgmt *action_frame;
u16 params;
skb = dev_alloc_skb(34 + hw->extra_tx_headroom);
if (!skb)
return NULL;
skb_reserve(skb, hw->extra_tx_headroom);
action_frame = (void *)skb_put(skb, 34);
memset(action_frame, 0, 34);
ether_addr_copy(action_frame->sa, sa);
ether_addr_copy(action_frame->da, rtlefuse->dev_addr);
ether_addr_copy(action_frame->bssid, bssid);
action_frame->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT |
IEEE80211_STYPE_ACTION);
action_frame->u.action.category = WLAN_CATEGORY_BACK;
action_frame->u.action.u.delba.action_code = WLAN_ACTION_DELBA;
params = (u16)(1 << 11);
params |= (u16)(tid << 12);
action_frame->u.action.u.delba.params = cpu_to_le16(params);
action_frame->u.action.u.delba.reason_code =
cpu_to_le16(WLAN_REASON_QSTA_TIMEOUT);
return skb;
}
static bool rtl_chk_vendor_ouisub(struct ieee80211_hw *hw,
struct octet_string vendor_ie)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
bool matched = false;
static u8 athcap_1[] = { 0x00, 0x03, 0x7F };
static u8 athcap_2[] = { 0x00, 0x13, 0x74 };
static u8 broadcap_1[] = { 0x00, 0x10, 0x18 };
static u8 broadcap_2[] = { 0x00, 0x0a, 0xf7 };
static u8 broadcap_3[] = { 0x00, 0x05, 0xb5 };
static u8 racap[] = { 0x00, 0x0c, 0x43 };
static u8 ciscocap[] = { 0x00, 0x40, 0x96 };
static u8 marvcap[] = { 0x00, 0x50, 0x43 };
if (memcmp(vendor_ie.octet, athcap_1, 3) == 0 ||
memcmp(vendor_ie.octet, athcap_2, 3) == 0) {
rtlpriv->mac80211.vendor = PEER_ATH;
matched = true;
} else if (memcmp(vendor_ie.octet, broadcap_1, 3) == 0 ||
memcmp(vendor_ie.octet, broadcap_2, 3) == 0 ||
memcmp(vendor_ie.octet, broadcap_3, 3) == 0) {
rtlpriv->mac80211.vendor = PEER_BROAD;
matched = true;
} else if (memcmp(vendor_ie.octet, racap, 3) == 0) {
rtlpriv->mac80211.vendor = PEER_RAL;
matched = true;
} else if (memcmp(vendor_ie.octet, ciscocap, 3) == 0) {
rtlpriv->mac80211.vendor = PEER_CISCO;
matched = true;
} else if (memcmp(vendor_ie.octet, marvcap, 3) == 0) {
rtlpriv->mac80211.vendor = PEER_MARV;
matched = true;
}
return matched;
}
static bool rtl_find_221_ie(struct ieee80211_hw *hw, u8 *data, unsigned int len)
{
struct ieee80211_mgmt *mgmt = (void *)data;
struct octet_string vendor_ie;
u8 *pos, *end;
pos = (u8 *)mgmt->u.beacon.variable;
end = data + len;
while (pos < end) {
if (pos[0] == 221) {
vendor_ie.length = pos[1];
vendor_ie.octet = &pos[2];
if (rtl_chk_vendor_ouisub(hw, vendor_ie))
return true;
}
if (pos + 2 + pos[1] > end)
return false;
pos += 2 + pos[1];
}
return false;
}
void rtl92e_recognize_peer(struct ieee80211_hw *hw, u8 *data, unsigned int len)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
struct ieee80211_hdr *hdr = (void *)data;
u32 vendor = PEER_UNKNOWN;
static u8 ap3_1[3] = { 0x00, 0x14, 0xbf };
static u8 ap3_2[3] = { 0x00, 0x1a, 0x70 };
static u8 ap3_3[3] = { 0x00, 0x1d, 0x7e };
static u8 ap4_1[3] = { 0x00, 0x90, 0xcc };
static u8 ap4_2[3] = { 0x00, 0x0e, 0x2e };
static u8 ap4_3[3] = { 0x00, 0x18, 0x02 };
static u8 ap4_4[3] = { 0x00, 0x17, 0x3f };
static u8 ap4_5[3] = { 0x00, 0x1c, 0xdf };
static u8 ap5_1[3] = { 0x00, 0x1c, 0xf0 };
static u8 ap5_2[3] = { 0x00, 0x21, 0x91 };
static u8 ap5_3[3] = { 0x00, 0x24, 0x01 };
static u8 ap5_4[3] = { 0x00, 0x15, 0xe9 };
static u8 ap5_5[3] = { 0x00, 0x17, 0x9A };
static u8 ap5_6[3] = { 0x00, 0x18, 0xE7 };
static u8 ap6_1[3] = { 0x00, 0x17, 0x94 };
static u8 ap7_1[3] = { 0x00, 0x14, 0xa4 };
if (mac->opmode != NL80211_IFTYPE_STATION)
return;
if (mac->link_state == MAC80211_NOLINK) {
mac->vendor = PEER_UNKNOWN;
return;
}
if (mac->cnt_after_linked > 2)
return;
if (!ieee80211_is_beacon(hdr->frame_control))
return;
if (len <= 40 + FCS_LEN)
return;
if (!ether_addr_equal(hdr->addr3, rtlpriv->mac80211.bssid))
return;
if (rtl_find_221_ie(hw, data, len))
vendor = mac->vendor;
if ((memcmp(mac->bssid, ap5_1, 3) == 0) ||
(memcmp(mac->bssid, ap5_2, 3) == 0) ||
(memcmp(mac->bssid, ap5_3, 3) == 0) ||
(memcmp(mac->bssid, ap5_4, 3) == 0) ||
(memcmp(mac->bssid, ap5_5, 3) == 0) ||
(memcmp(mac->bssid, ap5_6, 3) == 0) ||
vendor == PEER_ATH) {
vendor = PEER_ATH;
RT_TRACE(COMP_MAC80211, DBG_LOUD, ("=>ath find\n"));
} else if ((memcmp(mac->bssid, ap4_4, 3) == 0) ||
(memcmp(mac->bssid, ap4_5, 3) == 0) ||
(memcmp(mac->bssid, ap4_1, 3) == 0) ||
(memcmp(mac->bssid, ap4_2, 3) == 0) ||
(memcmp(mac->bssid, ap4_3, 3) == 0) ||
vendor == PEER_RAL) {
RT_TRACE(COMP_MAC80211, DBG_LOUD, ("=>ral findn\n"));
vendor = PEER_RAL;
} else if (memcmp(mac->bssid, ap6_1, 3) == 0 ||
vendor == PEER_CISCO) {
vendor = PEER_CISCO;
RT_TRACE(COMP_MAC80211, DBG_LOUD, ("=>cisco find\n"));
} else if ((memcmp(mac->bssid, ap3_1, 3) == 0) ||
(memcmp(mac->bssid, ap3_2, 3) == 0) ||
(memcmp(mac->bssid, ap3_3, 3) == 0) ||
vendor == PEER_BROAD) {
RT_TRACE(COMP_MAC80211, DBG_LOUD, ("=>broad find\n"));
vendor = PEER_BROAD;
} else if (memcmp(mac->bssid, ap7_1, 3) == 0 ||
vendor == PEER_MARV) {
vendor = PEER_MARV;
RT_TRACE(COMP_MAC80211, DBG_LOUD, ("=>marv find\n"));
}
mac->vendor = vendor;
}
int rtl_core_module_init(void)
{
static int here_once;
if (here_once++)
return 0;
if (rtl92e_rate_control_register())
pr_debug("rtl: Unable to register rtl_rc, use default RC !!\n");
INIT_LIST_HEAD(&global_var.glb_priv_list);
spin_lock_init(&global_var.glb_list_lock);
return 0;
}
void rtl_core_module_exit(void)
{
rtl92e_rate_control_unregister();
}
