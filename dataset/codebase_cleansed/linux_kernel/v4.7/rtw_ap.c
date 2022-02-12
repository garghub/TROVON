void init_mlme_ap_info23a(struct rtw_adapter *padapter)
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct sta_priv *pstapriv = &padapter->stapriv;
struct wlan_acl_pool *pacl_list = &pstapriv->acl_list;
spin_lock_init(&pmlmepriv->bcn_update_lock);
_rtw_init_queue23a(&pacl_list->acl_node_q);
start_ap_mode23a(padapter);
}
void free_mlme_ap_info23a(struct rtw_adapter *padapter)
{
struct sta_info *psta = NULL;
struct sta_priv *pstapriv = &padapter->stapriv;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
pmlmepriv->update_bcn = false;
pmlmeext->bstart_bss = false;
rtw_sta_flush23a(padapter);
pmlmeinfo->state = MSR_NOLINK;
rtw_free_all_stainfo23a(padapter);
psta = rtw_get_bcmc_stainfo23a(padapter);
spin_lock_bh(&pstapriv->sta_hash_lock);
rtw_free_stainfo23a(padapter, psta);
spin_unlock_bh(&pstapriv->sta_hash_lock);
}
static void update_BCNTIM(struct rtw_adapter *padapter)
{
struct sta_priv *pstapriv = &padapter->stapriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
struct wlan_bssid_ex *pnetwork_mlmeext = &pmlmeinfo->network;
unsigned char *pie = pnetwork_mlmeext->IEs;
u8 *p, *dst_ie, *premainder_ie = NULL, *pbackup_remainder_ie = NULL;
uint offset, tmp_len, tim_ielen, tim_ie_offset, remainder_ielen;
p = rtw_get_ie23a(pie, WLAN_EID_TIM, &tim_ielen,
pnetwork_mlmeext->IELength);
if (p != NULL && tim_ielen > 0) {
tim_ielen += 2;
premainder_ie = p+tim_ielen;
tim_ie_offset = (int)(p - pie);
remainder_ielen = pnetwork_mlmeext->IELength - tim_ie_offset - tim_ielen;
dst_ie = p;
} else {
tim_ielen = 0;
offset = 0;
p = rtw_get_ie23a(pie, WLAN_EID_SSID,
&tmp_len, pnetwork_mlmeext->IELength);
if (p != NULL)
offset += tmp_len+2;
p = rtw_get_ie23a(pie, WLAN_EID_SUPP_RATES,
&tmp_len, pnetwork_mlmeext->IELength);
if (p != NULL)
offset += tmp_len+2;
offset += 3;
premainder_ie = pie + offset;
remainder_ielen = pnetwork_mlmeext->IELength - offset - tim_ielen;
dst_ie = pie + offset;
}
if (remainder_ielen > 0) {
pbackup_remainder_ie = kmalloc(remainder_ielen, GFP_ATOMIC);
if (pbackup_remainder_ie && premainder_ie)
memcpy(pbackup_remainder_ie, premainder_ie, remainder_ielen);
}
*dst_ie++ = WLAN_EID_TIM;
if ((pstapriv->tim_bitmap&0xff00) && (pstapriv->tim_bitmap&0x00fc))
tim_ielen = 5;
else
tim_ielen = 4;
*dst_ie++ = tim_ielen;
*dst_ie++ = 0;
*dst_ie++ = 1;
if (pstapriv->tim_bitmap & BIT(0))
*dst_ie++ = BIT(0);
else
*dst_ie++ = 0;
if (tim_ielen == 4) {
*dst_ie++ = pstapriv->tim_bitmap & 0xff;
} else if (tim_ielen == 5) {
put_unaligned_le16(pstapriv->tim_bitmap, dst_ie);
dst_ie += 2;
}
if (pbackup_remainder_ie) {
memcpy(dst_ie, pbackup_remainder_ie, remainder_ielen);
kfree(pbackup_remainder_ie);
}
offset = (uint)(dst_ie - pie);
pnetwork_mlmeext->IELength = offset + remainder_ielen;
set_tx_beacon_cmd23a(padapter);
}
static u8 chk_sta_is_alive(struct sta_info *psta)
{
u8 ret = false;
if ((psta->sta_stats.last_rx_data_pkts +
psta->sta_stats.last_rx_ctrl_pkts) !=
(psta->sta_stats.rx_data_pkts + psta->sta_stats.rx_ctrl_pkts))
ret = true;
sta_update_last_rx_pkts(psta);
return ret;
}
void expire_timeout_chk23a(struct rtw_adapter *padapter)
{
struct list_head *phead;
u8 updated = 0;
struct sta_info *psta, *ptmp;
struct sta_priv *pstapriv = &padapter->stapriv;
u8 chk_alive_num = 0;
struct sta_info *chk_alive_list[NUM_STA];
int i;
spin_lock_bh(&pstapriv->auth_list_lock);
phead = &pstapriv->auth_list;
list_for_each_entry_safe(psta, ptmp, phead, auth_list) {
if (psta->expire_to > 0) {
psta->expire_to--;
if (psta->expire_to == 0) {
list_del_init(&psta->auth_list);
pstapriv->auth_list_cnt--;
DBG_8723A("auth expire %pM\n", psta->hwaddr);
spin_unlock_bh(&pstapriv->auth_list_lock);
spin_lock_bh(&pstapriv->sta_hash_lock);
rtw_free_stainfo23a(padapter, psta);
spin_unlock_bh(&pstapriv->sta_hash_lock);
spin_lock_bh(&pstapriv->auth_list_lock);
}
}
}
spin_unlock_bh(&pstapriv->auth_list_lock);
spin_lock_bh(&pstapriv->asoc_list_lock);
phead = &pstapriv->asoc_list;
list_for_each_entry_safe(psta, ptmp, phead, asoc_list) {
if (chk_sta_is_alive(psta) || !psta->expire_to) {
psta->expire_to = pstapriv->expire_to;
psta->keep_alive_trycnt = 0;
} else {
psta->expire_to--;
}
if (psta->expire_to <= 0) {
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
if (padapter->registrypriv.wifi_spec == 1) {
psta->expire_to = pstapriv->expire_to;
continue;
}
if (psta->state & WIFI_SLEEP_STATE) {
if (!(psta->state & WIFI_STA_ALIVE_CHK_STATE)) {
psta->expire_to = pstapriv->expire_to;
psta->state |= WIFI_STA_ALIVE_CHK_STATE;
pstapriv->tim_bitmap |= CHKBIT(psta->aid);
update_beacon23a(padapter, WLAN_EID_TIM, NULL, false);
if (!pmlmeext->active_keep_alive_check)
continue;
}
}
if (pmlmeext->active_keep_alive_check) {
chk_alive_list[chk_alive_num++] = psta;
continue;
}
list_del_init(&psta->asoc_list);
pstapriv->asoc_list_cnt--;
DBG_8723A("asoc expire %pM, state = 0x%x\n",
psta->hwaddr, psta->state);
updated = ap_free_sta23a(padapter, psta, false, WLAN_REASON_DEAUTH_LEAVING);
} else {
if (psta->sleepq_len > (NR_XMITFRAME/pstapriv->asoc_list_cnt)
&& padapter->xmitpriv.free_xmitframe_cnt < ((NR_XMITFRAME/pstapriv->asoc_list_cnt)/2)
) {
DBG_8723A("%s sta:%pM, sleepq_len:%u, free_xmitframe_cnt:%u, asoc_list_cnt:%u, clear sleep_q\n",
__func__,
psta->hwaddr,
psta->sleepq_len,
padapter->xmitpriv.free_xmitframe_cnt,
pstapriv->asoc_list_cnt);
wakeup_sta_to_xmit23a(padapter, psta);
}
}
}
spin_unlock_bh(&pstapriv->asoc_list_lock);
if (chk_alive_num) {
u8 backup_oper_channel = 0;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
if (rtw_get_oper_ch23a(padapter) != pmlmeext->cur_channel) {
backup_oper_channel = rtw_get_oper_ch23a(padapter);
SelectChannel23a(padapter, pmlmeext->cur_channel);
}
for (i = 0; i < chk_alive_num; i++) {
int ret = _FAIL;
psta = chk_alive_list[i];
if (!(psta->state & _FW_LINKED))
continue;
if (psta->state & WIFI_SLEEP_STATE)
ret = issue_nulldata23a(padapter, psta->hwaddr, 0, 1, 50);
else
ret = issue_nulldata23a(padapter, psta->hwaddr, 0, 3, 50);
psta->keep_alive_trycnt++;
if (ret == _SUCCESS) {
DBG_8723A("asoc check, sta(%pM) is alive\n",
psta->hwaddr);
psta->expire_to = pstapriv->expire_to;
psta->keep_alive_trycnt = 0;
continue;
} else if (psta->keep_alive_trycnt <= 3) {
DBG_8723A("ack check for asoc expire, keep_alive_trycnt =%d\n", psta->keep_alive_trycnt);
psta->expire_to = 1;
continue;
}
psta->keep_alive_trycnt = 0;
DBG_8723A("asoc expire %pM, state = 0x%x\n",
psta->hwaddr, psta->state);
spin_lock_bh(&pstapriv->asoc_list_lock);
if (!list_empty(&psta->asoc_list)) {
list_del_init(&psta->asoc_list);
pstapriv->asoc_list_cnt--;
updated = ap_free_sta23a(padapter, psta, false, WLAN_REASON_DEAUTH_LEAVING);
}
spin_unlock_bh(&pstapriv->asoc_list_lock);
}
if (backup_oper_channel > 0)
SelectChannel23a(padapter, backup_oper_channel);
}
associated_clients_update23a(padapter, updated);
}
void add_RATid23a(struct rtw_adapter *padapter, struct sta_info *psta, u8 rssi_level)
{
int i;
u8 rf_type;
u32 init_rate = 0;
unsigned char sta_band = 0, raid, shortGIrate = false;
unsigned char limit;
unsigned int tx_ra_bitmap = 0;
struct ht_priv *psta_ht = NULL;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct wlan_bssid_ex *pcur_network = &pmlmepriv->cur_network.network;
if (psta)
psta_ht = &psta->htpriv;
else
return;
if (!(psta->state & _FW_LINKED))
return;
for (i = 0; i < sizeof(psta->bssrateset); i++) {
if (psta->bssrateset[i])
tx_ra_bitmap |= rtw_get_bit_value_from_ieee_value23a(psta->bssrateset[i]&0x7f);
}
if (psta_ht->ht_option) {
rf_type = rtl8723a_get_rf_type(padapter);
if (rf_type == RF_2T2R)
limit = 16;
else
limit = 8;
for (i = 0; i < limit; i++) {
if (psta_ht->ht_cap.mcs.rx_mask[i / 8] & BIT(i % 8))
tx_ra_bitmap |= BIT(i + 12);
}
shortGIrate = psta_ht->sgi;
}
if (pcur_network->DSConfig > 14) {
if (tx_ra_bitmap & 0xffff000)
sta_band |= WIRELESS_11_5N | WIRELESS_11A;
else
sta_band |= WIRELESS_11A;
} else {
if (tx_ra_bitmap & 0xffff000)
sta_band |= WIRELESS_11_24N | WIRELESS_11G | WIRELESS_11B;
else if (tx_ra_bitmap & 0xff0)
sta_band |= WIRELESS_11G | WIRELESS_11B;
else
sta_band |= WIRELESS_11B;
}
psta->wireless_mode = sta_band;
raid = networktype_to_raid23a(sta_band);
init_rate = get_highest_rate_idx23a(tx_ra_bitmap&0x0fffffff)&0x3f;
if (psta->aid < NUM_STA) {
u8 arg;
arg = psta->mac_id&0x1f;
arg |= BIT(7);
if (shortGIrate == true)
arg |= BIT(5);
tx_ra_bitmap |= ((raid<<28)&0xf0000000);
DBG_8723A("%s => mac_id:%d , raid:%d , bitmap = 0x%x, arg = "
"0x%x\n",
__func__, psta->mac_id, raid, tx_ra_bitmap, arg);
rtl8723a_add_rateatid(padapter, tx_ra_bitmap, arg, rssi_level);
if (shortGIrate == true)
init_rate |= BIT(6);
psta->raid = raid;
psta->init_rate = init_rate;
} else
DBG_8723A("station aid %d exceed the max number\n", psta->aid);
}
static void update_bmc_sta(struct rtw_adapter *padapter)
{
u32 init_rate = 0;
unsigned char network_type, raid;
int i, supportRateNum = 0;
unsigned int tx_ra_bitmap = 0;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct wlan_bssid_ex *pcur_network = &pmlmepriv->cur_network.network;
struct sta_info *psta = rtw_get_bcmc_stainfo23a(padapter);
if (psta) {
psta->aid = 0;
psta->mac_id = psta->aid + 1;
psta->qos_option = 0;
psta->htpriv.ht_option = false;
psta->ieee8021x_blocked = 0;
memset((void *)&psta->sta_stats, 0,
sizeof(struct stainfo_stats));
supportRateNum = rtw_get_rateset_len23a((u8 *)&pcur_network->SupportedRates);
network_type = rtw_check_network_type23a((u8 *)&pcur_network->SupportedRates, supportRateNum, 1);
memcpy(psta->bssrateset, &pcur_network->SupportedRates, supportRateNum);
psta->bssratelen = supportRateNum;
for (i = 0; i < supportRateNum; i++) {
if (psta->bssrateset[i])
tx_ra_bitmap |= rtw_get_bit_value_from_ieee_value23a(psta->bssrateset[i]&0x7f);
}
if (pcur_network->DSConfig > 14) {
network_type = WIRELESS_11A;
tx_ra_bitmap = 0x150;
} else {
network_type = WIRELESS_11B;
tx_ra_bitmap = 0xf;
}
raid = networktype_to_raid23a(network_type);
init_rate = get_highest_rate_idx23a(tx_ra_bitmap&0x0fffffff)&0x3f;
rtl8723a_SetHalODMVar(padapter, HAL_ODM_STA_INFO, psta, true);
{
u8 arg;
arg = psta->mac_id&0x1f;
arg |= BIT(7);
tx_ra_bitmap |= ((raid<<28)&0xf0000000);
DBG_8723A("update_bmc_sta, mask = 0x%x, arg = 0x%x\n", tx_ra_bitmap, arg);
rtl8723a_add_rateatid(padapter, tx_ra_bitmap, arg, 0);
}
psta->raid = raid;
psta->init_rate = init_rate;
spin_lock_bh(&psta->lock);
psta->state = _FW_LINKED;
spin_unlock_bh(&psta->lock);
} else
DBG_8723A("add_RATid23a_bmc_sta error!\n");
}
void update_sta_info23a_apmode23a(struct rtw_adapter *padapter, struct sta_info *psta)
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct ht_priv *phtpriv_ap = &pmlmepriv->htpriv;
struct ht_priv *phtpriv_sta = &psta->htpriv;
psta->mac_id = psta->aid+1;
DBG_8723A("%s\n", __func__);
rtl8723a_SetHalODMVar(padapter, HAL_ODM_STA_INFO, psta, true);
if (psecuritypriv->dot11AuthAlgrthm == dot11AuthAlgrthm_8021X)
psta->ieee8021x_blocked = true;
else
psta->ieee8021x_blocked = false;
VCS_update23a(padapter, psta);
if (phtpriv_sta->ht_option) {
phtpriv_sta->ampdu_enable = phtpriv_ap->ampdu_enable;
if ((phtpriv_sta->ht_cap.cap_info & phtpriv_ap->ht_cap.cap_info) & cpu_to_le16(IEEE80211_HT_CAP_SGI_20|IEEE80211_HT_CAP_SGI_40))
phtpriv_sta->sgi = true;
if ((phtpriv_sta->ht_cap.cap_info & phtpriv_ap->ht_cap.cap_info) & cpu_to_le16(IEEE80211_HT_CAP_SUP_WIDTH_20_40)) {
phtpriv_sta->bwmode = pmlmeext->cur_bwmode;
phtpriv_sta->ch_offset = pmlmeext->cur_ch_offset;
}
psta->qos_option = true;
} else {
phtpriv_sta->ampdu_enable = false;
phtpriv_sta->sgi = false;
phtpriv_sta->bwmode = HT_CHANNEL_WIDTH_20;
phtpriv_sta->ch_offset = HAL_PRIME_CHNL_OFFSET_DONT_CARE;
}
send_delba23a(padapter, 0, psta->hwaddr);
send_delba23a(padapter, 1, psta->hwaddr);
phtpriv_sta->agg_enable_bitmap = 0x0;
phtpriv_sta->candidate_tid_bitmap = 0x0;
memset((void *)&psta->sta_stats, 0, sizeof(struct stainfo_stats));
spin_lock_bh(&psta->lock);
psta->state |= _FW_LINKED;
spin_unlock_bh(&psta->lock);
}
static void update_hw_ht_param(struct rtw_adapter *padapter)
{
unsigned char max_AMPDU_len;
unsigned char min_MPDU_spacing;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
DBG_8723A("%s\n", __func__);
max_AMPDU_len = pmlmeinfo->ht_cap.ampdu_params_info &
IEEE80211_HT_AMPDU_PARM_FACTOR;
min_MPDU_spacing = (pmlmeinfo->ht_cap.ampdu_params_info &
IEEE80211_HT_AMPDU_PARM_DENSITY) >> 2;
rtl8723a_set_ampdu_min_space(padapter, min_MPDU_spacing);
rtl8723a_set_ampdu_factor(padapter, max_AMPDU_len);
pmlmeinfo->SM_PS = (le16_to_cpu(pmlmeinfo->ht_cap.cap_info) &
IEEE80211_HT_CAP_SM_PS) >> 2;
if (pmlmeinfo->SM_PS == WLAN_HT_CAP_SM_PS_STATIC)
DBG_8723A("%s(): WLAN_HT_CAP_SM_PS_STATIC\n", __func__);
}
static void start_bss_network(struct rtw_adapter *padapter, u8 *pbuf)
{
const u8 *p;
u8 val8, cur_channel, cur_bwmode, cur_ch_offset;
u16 bcn_interval;
u32 acparm;
struct registry_priv *pregpriv = &padapter->registrypriv;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct wlan_bssid_ex *pnetwork = &pmlmepriv->cur_network.network;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
struct wlan_bssid_ex *pnetwork_mlmeext = &pmlmeinfo->network;
struct ieee80211_ht_operation *pht_info = NULL;
bcn_interval = (u16)pnetwork->beacon_interval;
cur_channel = pnetwork->DSConfig;
cur_bwmode = HT_CHANNEL_WIDTH_20;
cur_ch_offset = HAL_PRIME_CHNL_OFFSET_DONT_CARE;
if (!cfg80211_find_vendor_ie(WLAN_OUI_MICROSOFT,
WLAN_OUI_TYPE_MICROSOFT_WPS,
pnetwork->IEs,
pnetwork->IELength))
pmlmeext->bstart_bss = true;
if (pmlmepriv->qos_option)
pmlmeinfo->WMM_enable = true;
if (pmlmepriv->htpriv.ht_option) {
pmlmeinfo->WMM_enable = true;
pmlmeinfo->HT_enable = true;
update_hw_ht_param(padapter);
}
if (pmlmepriv->cur_network.join_res != true) {
if (psecuritypriv->dot11PrivacyAlgrthm !=
WLAN_CIPHER_SUITE_WEP40 &&
psecuritypriv->dot11PrivacyAlgrthm !=
WLAN_CIPHER_SUITE_WEP104)
flush_all_cam_entry23a(padapter);
}
rtl8723a_set_media_status(padapter, MSR_AP);
hw_var_set_bssid(padapter, pnetwork->MacAddress);
acparm = 0x002F3217;
rtl8723a_set_ac_param_vo(padapter, acparm);
acparm = 0x005E4317;
rtl8723a_set_ac_param_vi(padapter, acparm);
acparm = 0x005ea42b;
rtl8723a_set_ac_param_be(padapter, acparm);
acparm = 0x0000A444;
rtl8723a_set_ac_param_bk(padapter, acparm);
val8 = (psecuritypriv->dot11AuthAlgrthm == dot11AuthAlgrthm_8021X) ?
0xcc : 0xcf;
rtl8723a_set_sec_cfg(padapter, val8);
rtl8723a_set_beacon_interval(padapter, bcn_interval);
UpdateBrateTbl23a(padapter, pnetwork->SupportedRates);
HalSetBrateCfg23a(padapter, pnetwork->SupportedRates);
if (!pmlmepriv->cur_network.join_res) {
rtl8723a_odm_support_ability_set(padapter,
DYNAMIC_ALL_FUNC_ENABLE);
}
p = cfg80211_find_ie(WLAN_EID_HT_OPERATION, pnetwork->IEs,
pnetwork->IELength);
if (p && p[1]) {
pht_info = (struct ieee80211_ht_operation *)(p + 2);
if (pregpriv->cbw40_enable && pht_info->ht_param &
IEEE80211_HT_PARAM_CHAN_WIDTH_ANY) {
cur_bwmode = HT_CHANNEL_WIDTH_40;
switch (pht_info->ht_param &
IEEE80211_HT_PARAM_CHA_SEC_OFFSET) {
case IEEE80211_HT_PARAM_CHA_SEC_ABOVE:
cur_ch_offset = HAL_PRIME_CHNL_OFFSET_LOWER;
break;
case IEEE80211_HT_PARAM_CHA_SEC_BELOW:
cur_ch_offset = HAL_PRIME_CHNL_OFFSET_UPPER;
break;
default:
cur_ch_offset = HAL_PRIME_CHNL_OFFSET_DONT_CARE;
break;
}
}
}
set_channel_bwmode23a(padapter, cur_channel, cur_ch_offset, cur_bwmode);
DBG_8723A("CH =%d, BW =%d, offset =%d\n", cur_channel, cur_bwmode,
cur_ch_offset);
pmlmeext->cur_channel = cur_channel;
pmlmeext->cur_bwmode = cur_bwmode;
pmlmeext->cur_ch_offset = cur_ch_offset;
pmlmeext->cur_wireless_mode = pmlmepriv->cur_network.network_type;
update_wireless_mode23a(padapter);
update_capinfo23a(padapter, pnetwork->capability);
memcpy(pnetwork_mlmeext, pnetwork, pnetwork->Length);
if (pmlmeext->bstart_bss) {
update_beacon23a(padapter, WLAN_EID_TIM, NULL, false);
if (send_beacon23a(padapter) == _FAIL)
DBG_8723A("issue_beacon23a, fail!\n");
}
update_bmc_sta(padapter);
}
int rtw_check_beacon_data23a(struct rtw_adapter *padapter,
struct ieee80211_mgmt *mgmt, unsigned int len)
{
int ret = _SUCCESS;
u8 *p;
u8 *pHT_caps_ie = NULL;
u8 *pHT_info_ie = NULL;
struct sta_info *psta = NULL;
u16 ht_cap = false;
uint ie_len = 0;
int group_cipher, pairwise_cipher;
u8 channel, network_type, supportRate[NDIS_802_11_LENGTH_RATES_EX];
int supportRateNum = 0;
u8 WMM_PARA_IE[] = {0x00, 0x50, 0xf2, 0x02, 0x01, 0x01};
struct registry_priv *pregistrypriv = &padapter->registrypriv;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct wlan_bssid_ex *pbss_network = &pmlmepriv->cur_network.network;
u8 *ie = pbss_network->IEs;
u8 *pbuf = mgmt->u.beacon.variable;
len -= offsetof(struct ieee80211_mgmt, u.beacon.variable);
DBG_8723A("%s, len =%d\n", __func__, len);
if (!check_fwstate(pmlmepriv, WIFI_AP_STATE))
return _FAIL;
if (len > MAX_IE_SZ)
return _FAIL;
pbss_network->IELength = len;
memset(ie, 0, MAX_IE_SZ);
memcpy(ie, pbuf, pbss_network->IELength);
if (pbss_network->ifmode != NL80211_IFTYPE_AP &&
pbss_network->ifmode != NL80211_IFTYPE_P2P_GO)
return _FAIL;
pbss_network->Rssi = 0;
memcpy(pbss_network->MacAddress, myid(&padapter->eeprompriv), ETH_ALEN);
p = rtw_get_ie23a(ie, WLAN_EID_SSID, &ie_len, pbss_network->IELength);
if (p && ie_len > 0) {
memset(&pbss_network->Ssid, 0, sizeof(struct cfg80211_ssid));
memcpy(pbss_network->Ssid.ssid, (p + 2), ie_len);
pbss_network->Ssid.ssid_len = ie_len;
}
channel = 0;
p = rtw_get_ie23a(ie, WLAN_EID_DS_PARAMS, &ie_len,
pbss_network->IELength);
if (p && ie_len > 0)
channel = *(p + 2);
pbss_network->DSConfig = channel;
memset(supportRate, 0, NDIS_802_11_LENGTH_RATES_EX);
p = rtw_get_ie23a(ie, WLAN_EID_SUPP_RATES, &ie_len,
pbss_network->IELength);
if (p) {
memcpy(supportRate, p+2, ie_len);
supportRateNum = ie_len;
}
p = rtw_get_ie23a(ie, WLAN_EID_EXT_SUPP_RATES,
&ie_len, pbss_network->IELength);
if (p) {
memcpy(supportRate+supportRateNum, p+2, ie_len);
supportRateNum += ie_len;
}
network_type = rtw_check_network_type23a(supportRate,
supportRateNum, channel);
rtw_set_supported_rate23a(pbss_network->SupportedRates, network_type);
p = rtw_get_ie23a(ie, WLAN_EID_ERP_INFO, &ie_len,
pbss_network->IELength);
if (p && ie_len > 0)
ERP_IE_handler23a(padapter, p);
if (pbss_network->capability & BIT(4))
pbss_network->Privacy = 1;
else
pbss_network->Privacy = 0;
psecuritypriv->wpa_psk = 0;
group_cipher = 0; pairwise_cipher = 0;
psecuritypriv->wpa2_group_cipher = 0;
psecuritypriv->wpa2_pairwise_cipher = 0;
p = rtw_get_ie23a(ie, WLAN_EID_RSN, &ie_len,
pbss_network->IELength);
if (p && ie_len > 0) {
if (rtw_parse_wpa2_ie23a(p, ie_len+2, &group_cipher,
&pairwise_cipher, NULL) == _SUCCESS) {
psecuritypriv->dot11AuthAlgrthm = dot11AuthAlgrthm_8021X;
psecuritypriv->dot8021xalg = 1;
psecuritypriv->wpa_psk |= BIT(1);
psecuritypriv->wpa2_group_cipher = group_cipher;
psecuritypriv->wpa2_pairwise_cipher = pairwise_cipher;
}
}
ie_len = 0;
group_cipher = 0;
pairwise_cipher = 0;
psecuritypriv->wpa_group_cipher = 0;
psecuritypriv->wpa_pairwise_cipher = 0;
for (p = ie; ; p += (ie_len + 2)) {
p = rtw_get_ie23a(p, WLAN_EID_VENDOR_SPECIFIC, &ie_len,
pbss_network->IELength - (ie_len + 2));
if ((p) && (!memcmp(p+2, RTW_WPA_OUI23A_TYPE, 4))) {
if (rtw_parse_wpa_ie23a(p, ie_len+2, &group_cipher,
&pairwise_cipher, NULL) == _SUCCESS) {
psecuritypriv->dot11AuthAlgrthm = dot11AuthAlgrthm_8021X;
psecuritypriv->dot8021xalg = 1;
psecuritypriv->wpa_psk |= BIT(0);
psecuritypriv->wpa_group_cipher = group_cipher;
psecuritypriv->wpa_pairwise_cipher = pairwise_cipher;
}
break;
}
if (!p || !ie_len)
break;
}
ie_len = 0;
pmlmepriv->qos_option = 0;
if (pregistrypriv->wmm_enable) {
for (p = ie; ; p += (ie_len + 2)) {
p = rtw_get_ie23a(p, WLAN_EID_VENDOR_SPECIFIC, &ie_len,
(pbss_network->IELength -
(ie_len + 2)));
if ((p) && !memcmp(p+2, WMM_PARA_IE, 6)) {
pmlmepriv->qos_option = 1;
*(p + 8) |= BIT(7);
*(p + 10) &= ~BIT(4);
*(p + 14) &= ~BIT(4);
*(p + 18) &= ~BIT(4);
*(p + 22) &= ~BIT(4);
break;
}
if ((p == NULL) || (ie_len == 0))
break;
}
}
p = rtw_get_ie23a(ie, WLAN_EID_HT_CAPABILITY, &ie_len,
pbss_network->IELength);
if (p && ie_len > 0) {
u8 rf_type;
struct ieee80211_ht_cap *pht_cap = (struct ieee80211_ht_cap *)(p+2);
pHT_caps_ie = p;
ht_cap = true;
network_type |= WIRELESS_11_24N;
rf_type = rtl8723a_get_rf_type(padapter);
if ((psecuritypriv->wpa_pairwise_cipher & WPA_CIPHER_CCMP) ||
(psecuritypriv->wpa2_pairwise_cipher & WPA_CIPHER_CCMP))
pht_cap->ampdu_params_info |= (IEEE80211_HT_AMPDU_PARM_DENSITY & (0x07<<2));
else
pht_cap->ampdu_params_info |= (IEEE80211_HT_AMPDU_PARM_DENSITY&0x00);
pht_cap->ampdu_params_info |= (IEEE80211_HT_AMPDU_PARM_FACTOR & 0x03);
if (rf_type == RF_1T1R) {
pht_cap->mcs.rx_mask[0] = 0xff;
pht_cap->mcs.rx_mask[1] = 0x0;
}
memcpy(&pmlmepriv->htpriv.ht_cap, p+2, ie_len);
}
p = rtw_get_ie23a(ie, WLAN_EID_HT_OPERATION, &ie_len,
pbss_network->IELength);
if (p && ie_len > 0)
pHT_info_ie = p;
pmlmepriv->cur_network.network_type = network_type;
pmlmepriv->htpriv.ht_option = false;
if (pregistrypriv->ht_enable && ht_cap) {
pmlmepriv->htpriv.ht_option = true;
pmlmepriv->qos_option = 1;
if (pregistrypriv->ampdu_enable == 1)
pmlmepriv->htpriv.ampdu_enable = true;
HT_caps_handler23a(padapter, pHT_caps_ie);
HT_info_handler23a(padapter, pHT_info_ie);
}
pbss_network->Length = get_wlan_bssid_ex_sz(pbss_network);
start_bss_network(padapter, (u8 *)pbss_network);
psta = rtw_get_stainfo23a(&padapter->stapriv, pbss_network->MacAddress);
if (!psta) {
psta = rtw_alloc_stainfo23a(&padapter->stapriv,
pbss_network->MacAddress,
GFP_KERNEL);
if (!psta)
return _FAIL;
}
psta->state |= WIFI_AP_STATE;
rtw_indicate_connect23a(padapter);
pmlmepriv->cur_network.join_res = true;
return ret;
}
void rtw_set_macaddr_acl23a(struct rtw_adapter *padapter, int mode)
{
struct sta_priv *pstapriv = &padapter->stapriv;
struct wlan_acl_pool *pacl_list = &pstapriv->acl_list;
DBG_8723A("%s, mode =%d\n", __func__, mode);
pacl_list->mode = mode;
}
static void update_bcn_erpinfo_ie(struct rtw_adapter *padapter)
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
struct wlan_bssid_ex *pnetwork = &pmlmeinfo->network;
unsigned char *p, *ie = pnetwork->IEs;
u32 len = 0;
DBG_8723A("%s, ERP_enable =%d\n", __func__, pmlmeinfo->ERP_enable);
if (!pmlmeinfo->ERP_enable)
return;
p = rtw_get_ie23a(ie, WLAN_EID_ERP_INFO, &len, pnetwork->IELength);
if (p && len > 0) {
if (pmlmepriv->num_sta_non_erp == 1)
p[2] |= WLAN_ERP_NON_ERP_PRESENT |
WLAN_ERP_USE_PROTECTION;
else
p[2] &= ~(WLAN_ERP_NON_ERP_PRESENT |
WLAN_ERP_USE_PROTECTION);
if (pmlmepriv->num_sta_no_short_preamble > 0)
p[2] |= WLAN_ERP_BARKER_PREAMBLE;
else
p[2] &= ~(WLAN_ERP_BARKER_PREAMBLE);
ERP_IE_handler23a(padapter, p);
}
}
static void update_bcn_wpa_ie(struct rtw_adapter *padapter)
{
DBG_8723A("%s\n", __func__);
}
static void update_bcn_wmm_ie(struct rtw_adapter *padapter)
{
DBG_8723A("%s\n", __func__);
}
static void update_bcn_wps_ie(struct rtw_adapter *padapter)
{
DBG_8723A("%s\n", __func__);
}
static void update_bcn_p2p_ie(struct rtw_adapter *padapter)
{
}
static void update_bcn_vendor_spec_ie(struct rtw_adapter *padapter, u8 *oui)
{
DBG_8723A("%s\n", __func__);
if (!memcmp(RTW_WPA_OUI23A_TYPE, oui, 4))
update_bcn_wpa_ie(padapter);
else if (!memcmp(WMM_OUI23A, oui, 4))
update_bcn_wmm_ie(padapter);
else if (!memcmp(WPS_OUI23A, oui, 4))
update_bcn_wps_ie(padapter);
else if (!memcmp(P2P_OUI23A, oui, 4))
update_bcn_p2p_ie(padapter);
else
DBG_8723A("unknown OUI type!\n");
}
void update_beacon23a(struct rtw_adapter *padapter, u8 ie_id, u8 *oui, u8 tx)
{
struct mlme_priv *pmlmepriv;
struct mlme_ext_priv *pmlmeext;
if (!padapter)
return;
pmlmepriv = &padapter->mlmepriv;
pmlmeext = &padapter->mlmeextpriv;
if (false == pmlmeext->bstart_bss)
return;
spin_lock_bh(&pmlmepriv->bcn_update_lock);
switch (ie_id) {
case WLAN_EID_TIM:
update_BCNTIM(padapter);
break;
case WLAN_EID_ERP_INFO:
update_bcn_erpinfo_ie(padapter);
break;
case WLAN_EID_VENDOR_SPECIFIC:
update_bcn_vendor_spec_ie(padapter, oui);
break;
default:
break;
}
pmlmepriv->update_bcn = true;
spin_unlock_bh(&pmlmepriv->bcn_update_lock);
if (tx)
set_tx_beacon_cmd23a(padapter);
}
static int rtw_ht_operation_update(struct rtw_adapter *padapter)
{
u16 cur_op_mode, new_op_mode;
int op_mode_changes = 0;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct ht_priv *phtpriv_ap = &pmlmepriv->htpriv;
if (pmlmepriv->htpriv.ht_option)
return 0;
DBG_8723A("%s current operation mode = 0x%X\n",
__func__, pmlmepriv->ht_op_mode);
if (!(pmlmepriv->ht_op_mode & IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT)
&& pmlmepriv->num_sta_ht_no_gf) {
pmlmepriv->ht_op_mode |=
IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT;
op_mode_changes++;
} else if ((pmlmepriv->ht_op_mode &
IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT) &&
pmlmepriv->num_sta_ht_no_gf == 0) {
pmlmepriv->ht_op_mode &=
~IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT;
op_mode_changes++;
}
if (!(pmlmepriv->ht_op_mode & IEEE80211_HT_OP_MODE_NON_HT_STA_PRSNT) &&
(pmlmepriv->num_sta_no_ht || pmlmepriv->olbc_ht)) {
pmlmepriv->ht_op_mode |= IEEE80211_HT_OP_MODE_NON_HT_STA_PRSNT;
op_mode_changes++;
} else if ((pmlmepriv->ht_op_mode &
IEEE80211_HT_OP_MODE_NON_HT_STA_PRSNT) &&
(pmlmepriv->num_sta_no_ht == 0 && !pmlmepriv->olbc_ht)) {
pmlmepriv->ht_op_mode &=
~IEEE80211_HT_OP_MODE_NON_HT_STA_PRSNT;
op_mode_changes++;
}
if (pmlmepriv->num_sta_no_ht ||
(pmlmepriv->ht_op_mode & IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT))
new_op_mode = IEEE80211_HT_OP_MODE_PROTECTION_NONHT_MIXED;
else if ((le16_to_cpu(phtpriv_ap->ht_cap.cap_info) &
IEEE80211_HT_CAP_SUP_WIDTH_20_40) &&
pmlmepriv->num_sta_ht_20mhz)
new_op_mode = IEEE80211_HT_OP_MODE_PROTECTION_20MHZ;
else if (pmlmepriv->olbc_ht)
new_op_mode = IEEE80211_HT_OP_MODE_PROTECTION_NONMEMBER;
else
new_op_mode = IEEE80211_HT_OP_MODE_PROTECTION_NONE;
cur_op_mode = pmlmepriv->ht_op_mode & IEEE80211_HT_OP_MODE_PROTECTION;
if (cur_op_mode != new_op_mode) {
pmlmepriv->ht_op_mode &= ~IEEE80211_HT_OP_MODE_PROTECTION;
pmlmepriv->ht_op_mode |= new_op_mode;
op_mode_changes++;
}
DBG_8723A("%s new operation mode = 0x%X changes =%d\n",
__func__, pmlmepriv->ht_op_mode, op_mode_changes);
return op_mode_changes;
}
void associated_clients_update23a(struct rtw_adapter *padapter, u8 updated)
{
if (updated == true) {
struct list_head *phead;
struct sta_info *psta, *ptmp;
struct sta_priv *pstapriv = &padapter->stapriv;
spin_lock_bh(&pstapriv->asoc_list_lock);
phead = &pstapriv->asoc_list;
list_for_each_entry_safe(psta, ptmp, phead, asoc_list)
VCS_update23a(padapter, psta);
spin_unlock_bh(&pstapriv->asoc_list_lock);
}
}
void bss_cap_update_on_sta_join23a(struct rtw_adapter *padapter, struct sta_info *psta)
{
u8 beacon_updated = false;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
if (!(psta->flags & WLAN_STA_SHORT_PREAMBLE)) {
if (!psta->no_short_preamble_set) {
psta->no_short_preamble_set = 1;
pmlmepriv->num_sta_no_short_preamble++;
if ((pmlmeext->cur_wireless_mode > WIRELESS_11B) &&
(pmlmepriv->num_sta_no_short_preamble == 1)) {
beacon_updated = true;
update_beacon23a(padapter, 0xFF, NULL, true);
}
}
} else {
if (psta->no_short_preamble_set) {
psta->no_short_preamble_set = 0;
pmlmepriv->num_sta_no_short_preamble--;
if ((pmlmeext->cur_wireless_mode > WIRELESS_11B) &&
(pmlmepriv->num_sta_no_short_preamble == 0)) {
beacon_updated = true;
update_beacon23a(padapter, 0xFF, NULL, true);
}
}
}
if (psta->flags & WLAN_STA_NONERP) {
if (!psta->nonerp_set) {
psta->nonerp_set = 1;
pmlmepriv->num_sta_non_erp++;
if (pmlmepriv->num_sta_non_erp == 1) {
beacon_updated = true;
update_beacon23a(padapter, WLAN_EID_ERP_INFO, NULL, true);
}
}
} else {
if (psta->nonerp_set) {
psta->nonerp_set = 0;
pmlmepriv->num_sta_non_erp--;
if (pmlmepriv->num_sta_non_erp == 0) {
beacon_updated = true;
update_beacon23a(padapter, WLAN_EID_ERP_INFO, NULL, true);
}
}
}
if (!(psta->capability & WLAN_CAPABILITY_SHORT_SLOT_TIME)) {
if (!psta->no_short_slot_time_set) {
psta->no_short_slot_time_set = 1;
pmlmepriv->num_sta_no_short_slot_time++;
if ((pmlmeext->cur_wireless_mode > WIRELESS_11B) &&
(pmlmepriv->num_sta_no_short_slot_time == 1)) {
beacon_updated = true;
update_beacon23a(padapter, 0xFF, NULL, true);
}
}
} else {
if (psta->no_short_slot_time_set) {
psta->no_short_slot_time_set = 0;
pmlmepriv->num_sta_no_short_slot_time--;
if ((pmlmeext->cur_wireless_mode > WIRELESS_11B) &&
(pmlmepriv->num_sta_no_short_slot_time == 0)) {
beacon_updated = true;
update_beacon23a(padapter, 0xFF, NULL, true);
}
}
}
if (psta->flags & WLAN_STA_HT) {
u16 ht_capab = le16_to_cpu(psta->htpriv.ht_cap.cap_info);
DBG_8723A("HT: STA %pM HT Capabilities Info: 0x%04x\n",
psta->hwaddr, ht_capab);
if (psta->no_ht_set) {
psta->no_ht_set = 0;
pmlmepriv->num_sta_no_ht--;
}
if ((ht_capab & IEEE80211_HT_CAP_GRN_FLD) == 0) {
if (!psta->no_ht_gf_set) {
psta->no_ht_gf_set = 1;
pmlmepriv->num_sta_ht_no_gf++;
}
DBG_8723A("%s STA %pM - no greenfield, num of non-gf stations %d\n",
__func__, psta->hwaddr,
pmlmepriv->num_sta_ht_no_gf);
}
if ((ht_capab & IEEE80211_HT_CAP_SUP_WIDTH_20_40) == 0) {
if (!psta->ht_20mhz_set) {
psta->ht_20mhz_set = 1;
pmlmepriv->num_sta_ht_20mhz++;
}
DBG_8723A("%s STA %pM - 20 MHz HT, num of 20MHz HT STAs %d\n",
__func__, psta->hwaddr,
pmlmepriv->num_sta_ht_20mhz);
}
} else {
if (!psta->no_ht_set) {
psta->no_ht_set = 1;
pmlmepriv->num_sta_no_ht++;
}
if (pmlmepriv->htpriv.ht_option) {
DBG_8723A("%s STA %pM - no HT, num of non-HT stations %d\n",
__func__, psta->hwaddr,
pmlmepriv->num_sta_no_ht);
}
}
if (rtw_ht_operation_update(padapter) > 0) {
update_beacon23a(padapter, WLAN_EID_HT_CAPABILITY, NULL, false);
update_beacon23a(padapter, WLAN_EID_HT_OPERATION, NULL, true);
}
associated_clients_update23a(padapter, beacon_updated);
DBG_8723A("%s, updated =%d\n", __func__, beacon_updated);
}
u8 bss_cap_update_on_sta_leave23a(struct rtw_adapter *padapter, struct sta_info *psta)
{
u8 beacon_updated = false;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
if (!psta)
return beacon_updated;
if (psta->no_short_preamble_set) {
psta->no_short_preamble_set = 0;
pmlmepriv->num_sta_no_short_preamble--;
if (pmlmeext->cur_wireless_mode > WIRELESS_11B
&& pmlmepriv->num_sta_no_short_preamble == 0) {
beacon_updated = true;
update_beacon23a(padapter, 0xFF, NULL, true);
}
}
if (psta->nonerp_set) {
psta->nonerp_set = 0;
pmlmepriv->num_sta_non_erp--;
if (pmlmepriv->num_sta_non_erp == 0) {
beacon_updated = true;
update_beacon23a(padapter, WLAN_EID_ERP_INFO,
NULL, true);
}
}
if (psta->no_short_slot_time_set) {
psta->no_short_slot_time_set = 0;
pmlmepriv->num_sta_no_short_slot_time--;
if (pmlmeext->cur_wireless_mode > WIRELESS_11B
&& pmlmepriv->num_sta_no_short_slot_time == 0) {
beacon_updated = true;
update_beacon23a(padapter, 0xFF, NULL, true);
}
}
if (psta->no_ht_gf_set) {
psta->no_ht_gf_set = 0;
pmlmepriv->num_sta_ht_no_gf--;
}
if (psta->no_ht_set) {
psta->no_ht_set = 0;
pmlmepriv->num_sta_no_ht--;
}
if (psta->ht_20mhz_set) {
psta->ht_20mhz_set = 0;
pmlmepriv->num_sta_ht_20mhz--;
}
if (rtw_ht_operation_update(padapter) > 0) {
update_beacon23a(padapter, WLAN_EID_HT_CAPABILITY, NULL, false);
update_beacon23a(padapter, WLAN_EID_HT_OPERATION, NULL, true);
}
DBG_8723A("%s, updated =%d\n", __func__, beacon_updated);
return beacon_updated;
}
u8 ap_free_sta23a(struct rtw_adapter *padapter, struct sta_info *psta, bool active, u16 reason)
{
struct sta_priv *pstapriv = &padapter->stapriv;
u8 beacon_updated = false;
if (!psta)
return beacon_updated;
if (active) {
send_delba23a(padapter, 0, psta->hwaddr);
send_delba23a(padapter, 1, psta->hwaddr);
issue_deauth23a(padapter, psta->hwaddr, reason);
}
psta->htpriv.agg_enable_bitmap = 0x0;
psta->htpriv.candidate_tid_bitmap = 0x0;
rtw_clearstakey_cmd23a(padapter, (u8 *)psta, (u8)(psta->mac_id + 3),
true);
spin_lock_bh(&psta->lock);
psta->state &= ~_FW_LINKED;
spin_unlock_bh(&psta->lock);
rtw_cfg80211_indicate_sta_disassoc(padapter, psta->hwaddr, reason);
report_del_sta_event23a(padapter, psta->hwaddr, reason);
beacon_updated = bss_cap_update_on_sta_leave23a(padapter, psta);
spin_lock_bh(&pstapriv->sta_hash_lock);
rtw_free_stainfo23a(padapter, psta);
spin_unlock_bh(&pstapriv->sta_hash_lock);
return beacon_updated;
}
int rtw_sta_flush23a(struct rtw_adapter *padapter)
{
struct list_head *phead;
struct sta_info *psta, *ptmp;
struct sta_priv *pstapriv = &padapter->stapriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
u8 bc_addr[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
u8 chk_alive_num = 0;
struct sta_info *chk_alive_list[NUM_STA];
int i;
DBG_8723A("%s(%s)\n", __func__, padapter->pnetdev->name);
if ((pmlmeinfo->state&0x03) != MSR_AP)
return 0;
spin_lock_bh(&pstapriv->asoc_list_lock);
phead = &pstapriv->asoc_list;
list_for_each_entry_safe(psta, ptmp, phead, asoc_list) {
list_del_init(&psta->asoc_list);
pstapriv->asoc_list_cnt--;
chk_alive_list[chk_alive_num++] = psta;
}
spin_unlock_bh(&pstapriv->asoc_list_lock);
for (i = 0; i < chk_alive_num; i++)
ap_free_sta23a(padapter, chk_alive_list[i], true,
WLAN_REASON_DEAUTH_LEAVING);
issue_deauth23a(padapter, bc_addr, WLAN_REASON_DEAUTH_LEAVING);
associated_clients_update23a(padapter, true);
return 0;
}
void sta_info_update23a(struct rtw_adapter *padapter, struct sta_info *psta)
{
int flags = psta->flags;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
if (WLAN_STA_WME&flags)
psta->qos_option = 1;
else
psta->qos_option = 0;
if (pmlmepriv->qos_option == 0)
psta->qos_option = 0;
if (WLAN_STA_HT&flags) {
psta->htpriv.ht_option = true;
psta->qos_option = 1;
} else {
psta->htpriv.ht_option = false;
}
if (!pmlmepriv->htpriv.ht_option)
psta->htpriv.ht_option = false;
update_sta_info23a_apmode23a(padapter, psta);
}
void ap_sta_info_defer_update23a(struct rtw_adapter *padapter, struct sta_info *psta)
{
if (psta->state & _FW_LINKED) {
add_RATid23a(padapter, psta, 0);
}
}
void rtw_ap_restore_network(struct rtw_adapter *padapter)
{
struct mlme_priv *mlmepriv = &padapter->mlmepriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct sta_priv *pstapriv = &padapter->stapriv;
struct sta_info *psta, *ptmp;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct list_head *phead;
u8 chk_alive_num = 0;
struct sta_info *chk_alive_list[NUM_STA];
int i;
rtw_setopmode_cmd23a(padapter, NL80211_IFTYPE_AP);
set_channel_bwmode23a(padapter, pmlmeext->cur_channel, pmlmeext->cur_ch_offset, pmlmeext->cur_bwmode);
start_bss_network(padapter, (u8 *)&mlmepriv->cur_network.network);
if (padapter->securitypriv.dot11PrivacyAlgrthm ==
WLAN_CIPHER_SUITE_TKIP ||
padapter->securitypriv.dot11PrivacyAlgrthm ==
WLAN_CIPHER_SUITE_CCMP) {
rtw_set_key23a(padapter, psecuritypriv,
psecuritypriv->dot118021XGrpKeyid, 0);
}
if (padapter->securitypriv.dot11PrivacyAlgrthm !=
WLAN_CIPHER_SUITE_TKIP &&
padapter->securitypriv.dot11PrivacyAlgrthm !=
WLAN_CIPHER_SUITE_CCMP) {
return;
}
spin_lock_bh(&pstapriv->asoc_list_lock);
phead = &pstapriv->asoc_list;
list_for_each_entry_safe(psta, ptmp, phead, asoc_list)
chk_alive_list[chk_alive_num++] = psta;
spin_unlock_bh(&pstapriv->asoc_list_lock);
for (i = 0; i < chk_alive_num; i++) {
psta = chk_alive_list[i];
if (psta->state & _FW_LINKED) {
Update_RA_Entry23a(padapter, psta);
rtw_setstakey_cmd23a(padapter, (unsigned char *)psta, true);
}
}
}
void start_ap_mode23a(struct rtw_adapter *padapter)
{
int i;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct sta_priv *pstapriv = &padapter->stapriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct wlan_acl_pool *pacl_list = &pstapriv->acl_list;
pmlmepriv->update_bcn = false;
pmlmeext->bstart_bss = false;
pmlmepriv->num_sta_non_erp = 0;
pmlmepriv->num_sta_no_short_slot_time = 0;
pmlmepriv->num_sta_no_short_preamble = 0;
pmlmepriv->num_sta_ht_no_gf = 0;
pmlmepriv->num_sta_no_ht = 0;
pmlmepriv->num_sta_ht_20mhz = 0;
pmlmepriv->olbc = false;
pmlmepriv->olbc_ht = false;
pmlmepriv->ht_op_mode = 0;
for (i = 0; i < NUM_STA; i++)
pstapriv->sta_aid[i] = NULL;
INIT_LIST_HEAD(&pacl_list->acl_node_q.queue);
pacl_list->num = 0;
pacl_list->mode = 0;
for (i = 0; i < NUM_ACL; i++) {
INIT_LIST_HEAD(&pacl_list->aclnode[i].list);
pacl_list->aclnode[i].valid = false;
}
}
void stop_ap_mode23a(struct rtw_adapter *padapter)
{
struct list_head *phead;
struct rtw_wlan_acl_node *paclnode, *ptmp;
struct sta_info *psta = NULL;
struct sta_priv *pstapriv = &padapter->stapriv;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct wlan_acl_pool *pacl_list = &pstapriv->acl_list;
struct rtw_queue *pacl_node_q = &pacl_list->acl_node_q;
pmlmepriv->update_bcn = false;
pmlmeext->bstart_bss = false;
memset((unsigned char *)&padapter->securitypriv, 0, sizeof(struct security_priv));
padapter->securitypriv.ndisauthtype = Ndis802_11AuthModeOpen;
padapter->securitypriv.ndisencryptstatus = Ndis802_11WEPDisabled;
spin_lock_bh(&pacl_node_q->lock);
phead = get_list_head(pacl_node_q);
list_for_each_entry_safe(paclnode, ptmp, phead, list) {
if (paclnode->valid == true) {
paclnode->valid = false;
list_del_init(&paclnode->list);
pacl_list->num--;
}
}
spin_unlock_bh(&pacl_node_q->lock);
DBG_8723A("%s, free acl_node_queue, num =%d\n",
__func__, pacl_list->num);
rtw_sta_flush23a(padapter);
rtw_free_all_stainfo23a(padapter);
psta = rtw_get_bcmc_stainfo23a(padapter);
spin_lock_bh(&pstapriv->sta_hash_lock);
rtw_free_stainfo23a(padapter, psta);
spin_unlock_bh(&pstapriv->sta_hash_lock);
rtw_init_bcmc_stainfo23a(padapter);
rtw23a_free_mlme_priv_ie_data(pmlmepriv);
}
