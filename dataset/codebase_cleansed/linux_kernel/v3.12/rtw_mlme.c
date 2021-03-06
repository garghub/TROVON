int _rtw_init_mlme_priv (struct adapter *padapter)
{
int i;
u8 *pbuf;
struct wlan_network *pnetwork;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
int res = _SUCCESS;
_func_enter_;
pmlmepriv->nic_hdl = (u8 *)padapter;
pmlmepriv->pscanned = NULL;
pmlmepriv->fw_state = 0;
pmlmepriv->cur_network.network.InfrastructureMode = Ndis802_11AutoUnknown;
pmlmepriv->scan_mode = SCAN_ACTIVE;
_rtw_spinlock_init(&(pmlmepriv->lock));
_rtw_init_queue(&(pmlmepriv->free_bss_pool));
_rtw_init_queue(&(pmlmepriv->scanned_queue));
set_scanned_network_val(pmlmepriv, 0);
_rtw_memset(&pmlmepriv->assoc_ssid, 0, sizeof(struct ndis_802_11_ssid));
pbuf = rtw_zvmalloc(MAX_BSS_CNT * (sizeof(struct wlan_network)));
if (pbuf == NULL) {
res = _FAIL;
goto exit;
}
pmlmepriv->free_bss_buf = pbuf;
pnetwork = (struct wlan_network *)pbuf;
for (i = 0; i < MAX_BSS_CNT; i++) {
_rtw_init_listhead(&(pnetwork->list));
rtw_list_insert_tail(&(pnetwork->list), &(pmlmepriv->free_bss_pool.queue));
pnetwork++;
}
rtw_clear_scan_deny(padapter);
rtw_init_mlme_timer(padapter);
exit:
_func_exit_;
return res;
}
static void rtw_mfree_mlme_priv_lock (struct mlme_priv *pmlmepriv)
{
_rtw_spinlock_free(&pmlmepriv->lock);
_rtw_spinlock_free(&(pmlmepriv->free_bss_pool.lock));
_rtw_spinlock_free(&(pmlmepriv->scanned_queue.lock));
}
static void rtw_free_mlme_ie_data(u8 **ppie, u32 *plen)
{
kfree(*ppie);
*plen = 0;
*ppie = NULL;
}
void rtw_free_mlme_priv_ie_data(struct mlme_priv *pmlmepriv)
{
rtw_buf_free(&pmlmepriv->assoc_req, &pmlmepriv->assoc_req_len);
rtw_buf_free(&pmlmepriv->assoc_rsp, &pmlmepriv->assoc_rsp_len);
rtw_free_mlme_ie_data(&pmlmepriv->wps_beacon_ie, &pmlmepriv->wps_beacon_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->wps_probe_req_ie, &pmlmepriv->wps_probe_req_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->wps_probe_resp_ie, &pmlmepriv->wps_probe_resp_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->wps_assoc_resp_ie, &pmlmepriv->wps_assoc_resp_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->p2p_beacon_ie, &pmlmepriv->p2p_beacon_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->p2p_probe_req_ie, &pmlmepriv->p2p_probe_req_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->p2p_probe_resp_ie, &pmlmepriv->p2p_probe_resp_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->p2p_go_probe_resp_ie, &pmlmepriv->p2p_go_probe_resp_ie_len);
rtw_free_mlme_ie_data(&pmlmepriv->p2p_assoc_req_ie, &pmlmepriv->p2p_assoc_req_ie_len);
}
void rtw_free_mlme_priv_ie_data(struct mlme_priv *pmlmepriv)
{
}
void _rtw_free_mlme_priv (struct mlme_priv *pmlmepriv)
{
_func_enter_;
rtw_free_mlme_priv_ie_data(pmlmepriv);
if (pmlmepriv) {
rtw_mfree_mlme_priv_lock (pmlmepriv);
if (pmlmepriv->free_bss_buf) {
rtw_vmfree(pmlmepriv->free_bss_buf, MAX_BSS_CNT * sizeof(struct wlan_network));
}
}
_func_exit_;
}
int _rtw_enqueue_network(struct __queue *queue, struct wlan_network *pnetwork)
{
unsigned long irql;
_func_enter_;
if (pnetwork == NULL)
goto exit;
_enter_critical_bh(&queue->lock, &irql);
rtw_list_insert_tail(&pnetwork->list, &queue->queue);
_exit_critical_bh(&queue->lock, &irql);
exit:
_func_exit_;
return _SUCCESS;
}
struct wlan_network *_rtw_dequeue_network(struct __queue *queue)
{
unsigned long irql;
struct wlan_network *pnetwork;
_func_enter_;
_enter_critical_bh(&queue->lock, &irql);
if (_rtw_queue_empty(queue)) {
pnetwork = NULL;
} else {
pnetwork = LIST_CONTAINOR(get_next(&queue->queue), struct wlan_network, list);
rtw_list_delete(&(pnetwork->list));
}
_exit_critical_bh(&queue->lock, &irql);
_func_exit_;
return pnetwork;
}
struct wlan_network *_rtw_alloc_network(struct mlme_priv *pmlmepriv)
{
unsigned long irql;
struct wlan_network *pnetwork;
struct __queue *free_queue = &pmlmepriv->free_bss_pool;
struct list_head *plist = NULL;
_func_enter_;
_enter_critical_bh(&free_queue->lock, &irql);
if (_rtw_queue_empty(free_queue) == true) {
pnetwork = NULL;
goto exit;
}
plist = get_next(&(free_queue->queue));
pnetwork = LIST_CONTAINOR(plist , struct wlan_network, list);
rtw_list_delete(&pnetwork->list);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_, ("_rtw_alloc_network: ptr=%p\n", plist));
pnetwork->network_type = 0;
pnetwork->fixed = false;
pnetwork->last_scanned = rtw_get_current_time();
pnetwork->aid = 0;
pnetwork->join_res = 0;
pmlmepriv->num_of_scanned++;
exit:
_exit_critical_bh(&free_queue->lock, &irql);
_func_exit_;
return pnetwork;
}
void _rtw_free_network(struct mlme_priv *pmlmepriv , struct wlan_network *pnetwork, u8 isfreeall)
{
u32 curr_time, delta_time;
u32 lifetime = SCANQUEUE_LIFETIME;
unsigned long irql;
struct __queue *free_queue = &(pmlmepriv->free_bss_pool);
_func_enter_;
if (pnetwork == NULL)
goto exit;
if (pnetwork->fixed)
goto exit;
curr_time = rtw_get_current_time();
if ((check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE)) ||
(check_fwstate(pmlmepriv, WIFI_ADHOC_STATE)))
lifetime = 1;
if (!isfreeall) {
delta_time = (curr_time - pnetwork->last_scanned)/HZ;
if (delta_time < lifetime)
goto exit;
}
_enter_critical_bh(&free_queue->lock, &irql);
rtw_list_delete(&(pnetwork->list));
rtw_list_insert_tail(&(pnetwork->list), &(free_queue->queue));
pmlmepriv->num_of_scanned--;
_exit_critical_bh(&free_queue->lock, &irql);
exit:
_func_exit_;
}
void _rtw_free_network_nolock(struct mlme_priv *pmlmepriv, struct wlan_network *pnetwork)
{
struct __queue *free_queue = &(pmlmepriv->free_bss_pool);
_func_enter_;
if (pnetwork == NULL)
goto exit;
if (pnetwork->fixed)
goto exit;
rtw_list_delete(&(pnetwork->list));
rtw_list_insert_tail(&(pnetwork->list), get_list_head(free_queue));
pmlmepriv->num_of_scanned--;
exit:
_func_exit_;
}
struct wlan_network *_rtw_find_network(struct __queue *scanned_queue, u8 *addr)
{
struct list_head *phead, *plist;
struct wlan_network *pnetwork = NULL;
u8 zero_addr[ETH_ALEN] = {0, 0, 0, 0, 0, 0};
_func_enter_;
if (_rtw_memcmp(zero_addr, addr, ETH_ALEN)) {
pnetwork = NULL;
goto exit;
}
phead = get_list_head(scanned_queue);
plist = get_next(phead);
while (plist != phead) {
pnetwork = LIST_CONTAINOR(plist, struct wlan_network , list);
if (_rtw_memcmp(addr, pnetwork->network.MacAddress, ETH_ALEN) == true)
break;
plist = get_next(plist);
}
if (plist == phead)
pnetwork = NULL;
exit:
_func_exit_;
return pnetwork;
}
void _rtw_free_network_queue(struct adapter *padapter, u8 isfreeall)
{
unsigned long irql;
struct list_head *phead, *plist;
struct wlan_network *pnetwork;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct __queue *scanned_queue = &pmlmepriv->scanned_queue;
_func_enter_;
_enter_critical_bh(&scanned_queue->lock, &irql);
phead = get_list_head(scanned_queue);
plist = get_next(phead);
while (rtw_end_of_queue_search(phead, plist) == false) {
pnetwork = LIST_CONTAINOR(plist, struct wlan_network, list);
plist = get_next(plist);
_rtw_free_network(pmlmepriv, pnetwork, isfreeall);
}
_exit_critical_bh(&scanned_queue->lock, &irql);
_func_exit_;
}
int rtw_if_up(struct adapter *padapter)
{
int res;
_func_enter_;
if (padapter->bDriverStopped || padapter->bSurpriseRemoved ||
(check_fwstate(&padapter->mlmepriv, _FW_LINKED) == false)) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_,
("rtw_if_up:bDriverStopped(%d) OR bSurpriseRemoved(%d)",
padapter->bDriverStopped, padapter->bSurpriseRemoved));
res = false;
} else {
res = true;
}
_func_exit_;
return res;
}
void rtw_generate_random_ibss(u8 *pibss)
{
u32 curtime = rtw_get_current_time();
_func_enter_;
pibss[0] = 0x02;
pibss[1] = 0x11;
pibss[2] = 0x87;
pibss[3] = (u8)(curtime & 0xff);
pibss[4] = (u8)((curtime>>8) & 0xff);
pibss[5] = (u8)((curtime>>16) & 0xff);
_func_exit_;
return;
}
u8 *rtw_get_capability_from_ie(u8 *ie)
{
return ie + 8 + 2;
}
u16 rtw_get_capability(struct wlan_bssid_ex *bss)
{
__le16 val;
_func_enter_;
memcpy((u8 *)&val, rtw_get_capability_from_ie(bss->IEs), 2);
_func_exit_;
return le16_to_cpu(val);
}
u8 *rtw_get_timestampe_from_ie(u8 *ie)
{
return ie + 0;
}
u8 *rtw_get_beacon_interval_from_ie(u8 *ie)
{
return ie + 8;
}
int rtw_init_mlme_priv (struct adapter *padapter)
{
int res;
_func_enter_;
res = _rtw_init_mlme_priv(padapter);
_func_exit_;
return res;
}
void rtw_free_mlme_priv (struct mlme_priv *pmlmepriv)
{
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("rtw_free_mlme_priv\n"));
_rtw_free_mlme_priv (pmlmepriv);
_func_exit_;
}
static struct wlan_network *rtw_alloc_network(struct mlme_priv *pmlmepriv)
{
struct wlan_network *pnetwork;
_func_enter_;
pnetwork = _rtw_alloc_network(pmlmepriv);
_func_exit_;
return pnetwork;
}
static void rtw_free_network_nolock(struct mlme_priv *pmlmepriv,
struct wlan_network *pnetwork)
{
_func_enter_;
_rtw_free_network_nolock(pmlmepriv, pnetwork);
_func_exit_;
}
void rtw_free_network_queue(struct adapter *dev, u8 isfreeall)
{
_func_enter_;
_rtw_free_network_queue(dev, isfreeall);
_func_exit_;
}
struct wlan_network *rtw_find_network(struct __queue *scanned_queue, u8 *addr)
{
struct wlan_network *pnetwork = _rtw_find_network(scanned_queue, addr);
return pnetwork;
}
int rtw_is_same_ibss(struct adapter *adapter, struct wlan_network *pnetwork)
{
int ret = true;
struct security_priv *psecuritypriv = &adapter->securitypriv;
if ((psecuritypriv->dot11PrivacyAlgrthm != _NO_PRIVACY_) &&
(pnetwork->network.Privacy == 0))
ret = false;
else if ((psecuritypriv->dot11PrivacyAlgrthm == _NO_PRIVACY_) &&
(pnetwork->network.Privacy == 1))
ret = false;
else
ret = true;
return ret;
}
static int is_same_ess(struct wlan_bssid_ex *a, struct wlan_bssid_ex *b)
{
return (a->Ssid.SsidLength == b->Ssid.SsidLength) &&
_rtw_memcmp(a->Ssid.Ssid, b->Ssid.Ssid, a->Ssid.SsidLength);
}
int is_same_network(struct wlan_bssid_ex *src, struct wlan_bssid_ex *dst)
{
u16 s_cap, d_cap;
__le16 le_scap, le_dcap;
_func_enter_;
memcpy((u8 *)&le_scap, rtw_get_capability_from_ie(src->IEs), 2);
memcpy((u8 *)&le_dcap, rtw_get_capability_from_ie(dst->IEs), 2);
s_cap = le16_to_cpu(le_scap);
d_cap = le16_to_cpu(le_dcap);
_func_exit_;
return ((src->Ssid.SsidLength == dst->Ssid.SsidLength) &&
((_rtw_memcmp(src->MacAddress, dst->MacAddress, ETH_ALEN)) == true) &&
((_rtw_memcmp(src->Ssid.Ssid, dst->Ssid.Ssid, src->Ssid.SsidLength)) == true) &&
((s_cap & WLAN_CAPABILITY_IBSS) ==
(d_cap & WLAN_CAPABILITY_IBSS)) &&
((s_cap & WLAN_CAPABILITY_BSS) ==
(d_cap & WLAN_CAPABILITY_BSS)));
}
struct wlan_network *rtw_get_oldest_wlan_network(struct __queue *scanned_queue)
{
struct list_head *plist, *phead;
struct wlan_network *pwlan = NULL;
struct wlan_network *oldest = NULL;
_func_enter_;
phead = get_list_head(scanned_queue);
plist = get_next(phead);
while (1) {
if (rtw_end_of_queue_search(phead, plist) == true)
break;
pwlan = LIST_CONTAINOR(plist, struct wlan_network, list);
if (!pwlan->fixed) {
if (oldest == NULL || time_after(oldest->last_scanned, pwlan->last_scanned))
oldest = pwlan;
}
plist = get_next(plist);
}
_func_exit_;
return oldest;
}
void update_network(struct wlan_bssid_ex *dst, struct wlan_bssid_ex *src,
struct adapter *padapter, bool update_ie)
{
long rssi_ori = dst->Rssi;
u8 sq_smp = src->PhyInfo.SignalQuality;
u8 ss_final;
u8 sq_final;
long rssi_final;
_func_enter_;
rtw_hal_antdiv_rssi_compared(padapter, dst, src);
if (check_fwstate(&padapter->mlmepriv, _FW_LINKED) && is_same_network(&(padapter->mlmepriv.cur_network.network), src)) {
ss_final = padapter->recvpriv.signal_strength;
sq_final = padapter->recvpriv.signal_qual;
if (sq_smp != 101)
rssi_final = (src->Rssi+dst->Rssi*4)/5;
else
rssi_final = rssi_ori;
} else {
if (sq_smp != 101) {
ss_final = ((u32)(src->PhyInfo.SignalStrength)+(u32)(dst->PhyInfo.SignalStrength)*4)/5;
sq_final = ((u32)(src->PhyInfo.SignalQuality)+(u32)(dst->PhyInfo.SignalQuality)*4)/5;
rssi_final = (src->Rssi+dst->Rssi*4)/5;
} else {
ss_final = dst->PhyInfo.SignalStrength;
sq_final = dst->PhyInfo.SignalQuality;
rssi_final = dst->Rssi;
}
}
if (update_ie)
memcpy((u8 *)dst, (u8 *)src, get_wlan_bssid_ex_sz(src));
dst->PhyInfo.SignalStrength = ss_final;
dst->PhyInfo.SignalQuality = sq_final;
dst->Rssi = rssi_final;
_func_exit_;
}
static void update_current_network(struct adapter *adapter, struct wlan_bssid_ex *pnetwork)
{
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
_func_enter_;
if ((check_fwstate(pmlmepriv, _FW_LINKED) == true) &&
(is_same_network(&(pmlmepriv->cur_network.network), pnetwork))) {
update_network(&(pmlmepriv->cur_network.network), pnetwork, adapter, true);
rtw_update_protection(adapter, (pmlmepriv->cur_network.network.IEs) + sizeof(struct ndis_802_11_fixed_ie),
pmlmepriv->cur_network.network.IELength);
}
_func_exit_;
}
void rtw_update_scanned_network(struct adapter *adapter, struct wlan_bssid_ex *target)
{
unsigned long irql;
struct list_head *plist, *phead;
u32 bssid_ex_sz;
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
struct __queue *queue = &(pmlmepriv->scanned_queue);
struct wlan_network *pnetwork = NULL;
struct wlan_network *oldest = NULL;
_func_enter_;
_enter_critical_bh(&queue->lock, &irql);
phead = get_list_head(queue);
plist = get_next(phead);
while (1) {
if (rtw_end_of_queue_search(phead, plist) == true)
break;
pnetwork = LIST_CONTAINOR(plist, struct wlan_network, list);
if (is_same_network(&(pnetwork->network), target))
break;
if ((oldest == ((struct wlan_network *)0)) ||
time_after(oldest->last_scanned, pnetwork->last_scanned))
oldest = pnetwork;
plist = get_next(plist);
}
if (rtw_end_of_queue_search(phead, plist) == true) {
if (_rtw_queue_empty(&(pmlmepriv->free_bss_pool)) == true) {
pnetwork = oldest;
rtw_hal_get_def_var(adapter, HAL_DEF_CURRENT_ANTENNA, &(target->PhyInfo.Optimum_antenna));
memcpy(&(pnetwork->network), target, get_wlan_bssid_ex_sz(target));
pnetwork->fixed = false;
pnetwork->last_scanned = rtw_get_current_time();
pnetwork->network_type = 0;
pnetwork->aid = 0;
pnetwork->join_res = 0;
if (pnetwork->network.PhyInfo.SignalQuality == 101)
pnetwork->network.PhyInfo.SignalQuality = 0;
} else {
pnetwork = rtw_alloc_network(pmlmepriv);
if (pnetwork == NULL) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("\n\n\nsomething wrong here\n\n\n"));
goto exit;
}
bssid_ex_sz = get_wlan_bssid_ex_sz(target);
target->Length = bssid_ex_sz;
rtw_hal_get_def_var(adapter, HAL_DEF_CURRENT_ANTENNA, &(target->PhyInfo.Optimum_antenna));
memcpy(&(pnetwork->network), target, bssid_ex_sz);
pnetwork->last_scanned = rtw_get_current_time();
if (pnetwork->network.PhyInfo.SignalQuality == 101)
pnetwork->network.PhyInfo.SignalQuality = 0;
rtw_list_insert_tail(&(pnetwork->list), &(queue->queue));
}
} else {
bool update_ie = true;
pnetwork->last_scanned = rtw_get_current_time();
if ((pnetwork->network.IELength > target->IELength) && (target->Reserved[0] == 1))
update_ie = false;
update_network(&(pnetwork->network), target, adapter, update_ie);
}
exit:
_exit_critical_bh(&queue->lock, &irql);
_func_exit_;
}
static void rtw_add_network(struct adapter *adapter,
struct wlan_bssid_ex *pnetwork)
{
_func_enter_;
#if defined(CONFIG_88EU_P2P)
rtw_wlan_bssid_ex_remove_p2p_attr(pnetwork, P2P_ATTR_GROUP_INFO);
#endif
update_current_network(adapter, pnetwork);
rtw_update_scanned_network(adapter, pnetwork);
_func_exit_;
}
static int rtw_is_desired_network(struct adapter *adapter, struct wlan_network *pnetwork)
{
struct security_priv *psecuritypriv = &adapter->securitypriv;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
u32 desired_encmode;
u32 privacy;
uint wps_ielen;
int bselected = true;
desired_encmode = psecuritypriv->ndisencryptstatus;
privacy = pnetwork->network.Privacy;
if (check_fwstate(pmlmepriv, WIFI_UNDER_WPS)) {
if (rtw_get_wps_ie(pnetwork->network.IEs+_FIXED_IE_LENGTH_, pnetwork->network.IELength-_FIXED_IE_LENGTH_, NULL, &wps_ielen) != NULL)
return true;
else
return false;
}
if (adapter->registrypriv.wifi_spec == 1) {
if ((desired_encmode == Ndis802_11EncryptionDisabled) && (privacy != 0))
bselected = false;
}
if ((desired_encmode != Ndis802_11EncryptionDisabled) && (privacy == 0)) {
DBG_88E("desired_encmode: %d, privacy: %d\n", desired_encmode, privacy);
bselected = false;
}
if (check_fwstate(pmlmepriv, WIFI_ADHOC_STATE) == true) {
if (pnetwork->network.InfrastructureMode != pmlmepriv->cur_network.network.InfrastructureMode)
bselected = false;
}
return bselected;
}
void rtw_atimdone_event_callback(struct adapter *adapter , u8 *pbuf)
{
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("receive atimdone_evet\n"));
_func_exit_;
return;
}
void rtw_survey_event_callback(struct adapter *adapter, u8 *pbuf)
{
unsigned long irql;
u32 len;
struct wlan_bssid_ex *pnetwork;
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
_func_enter_;
pnetwork = (struct wlan_bssid_ex *)pbuf;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_, ("rtw_survey_event_callback, ssid=%s\n", pnetwork->Ssid.Ssid));
len = get_wlan_bssid_ex_sz(pnetwork);
if (len > (sizeof(struct wlan_bssid_ex))) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("\n****rtw_survey_event_callback: return a wrong bss ***\n"));
return;
}
_enter_critical_bh(&pmlmepriv->lock, &irql);
if ((check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE)) == true) {
if (_rtw_memcmp(&(pmlmepriv->cur_network.network.MacAddress), pnetwork->MacAddress, ETH_ALEN)) {
struct wlan_network *ibss_wlan = NULL;
unsigned long irql;
memcpy(pmlmepriv->cur_network.network.IEs, pnetwork->IEs, 8);
_enter_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
ibss_wlan = rtw_find_network(&pmlmepriv->scanned_queue, pnetwork->MacAddress);
if (ibss_wlan) {
memcpy(ibss_wlan->network.IEs , pnetwork->IEs, 8);
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
goto exit;
}
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
}
}
if ((check_fwstate(pmlmepriv, _FW_UNDER_LINKING)) == false) {
if (pnetwork->Ssid.Ssid[0] == 0)
pnetwork->Ssid.SsidLength = 0;
rtw_add_network(adapter, pnetwork);
}
exit:
_exit_critical_bh(&pmlmepriv->lock, &irql);
_func_exit_;
return;
}
void rtw_surveydone_event_callback(struct adapter *adapter, u8 *pbuf)
{
unsigned long irql;
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
struct mlme_ext_priv *pmlmeext;
_func_enter_;
_enter_critical_bh(&pmlmepriv->lock, &irql);
if (pmlmepriv->wps_probe_req_ie) {
pmlmepriv->wps_probe_req_ie_len = 0;
kfree(pmlmepriv->wps_probe_req_ie);
pmlmepriv->wps_probe_req_ie = NULL;
}
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_, ("rtw_surveydone_event_callback: fw_state:%x\n\n", get_fwstate(pmlmepriv)));
if (check_fwstate(pmlmepriv, _FW_UNDER_SURVEY)) {
u8 timer_cancelled;
_cancel_timer(&pmlmepriv->scan_to_timer, &timer_cancelled);
_clr_fwstate_(pmlmepriv, _FW_UNDER_SURVEY);
} else {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("nic status=%x, survey done event comes too late!\n", get_fwstate(pmlmepriv)));
}
rtw_set_signal_stat_timer(&adapter->recvpriv);
if (pmlmepriv->to_join) {
if ((check_fwstate(pmlmepriv, WIFI_ADHOC_STATE) == true)) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == false) {
set_fwstate(pmlmepriv, _FW_UNDER_LINKING);
if (rtw_select_and_join_from_scanned_queue(pmlmepriv) == _SUCCESS) {
_set_timer(&pmlmepriv->assoc_timer, MAX_JOIN_TIMEOUT);
} else {
struct wlan_bssid_ex *pdev_network = &(adapter->registrypriv.dev_network);
u8 *pibss = adapter->registrypriv.dev_network.MacAddress;
_clr_fwstate_(pmlmepriv, _FW_UNDER_SURVEY);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("switching to adhoc master\n"));
_rtw_memset(&pdev_network->Ssid, 0, sizeof(struct ndis_802_11_ssid));
memcpy(&pdev_network->Ssid, &pmlmepriv->assoc_ssid, sizeof(struct ndis_802_11_ssid));
rtw_update_registrypriv_dev_network(adapter);
rtw_generate_random_ibss(pibss);
pmlmepriv->fw_state = WIFI_ADHOC_MASTER_STATE;
if (rtw_createbss_cmd(adapter) != _SUCCESS)
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("Error=>rtw_createbss_cmd status FAIL\n"));
pmlmepriv->to_join = false;
}
}
} else {
int s_ret;
set_fwstate(pmlmepriv, _FW_UNDER_LINKING);
pmlmepriv->to_join = false;
s_ret = rtw_select_and_join_from_scanned_queue(pmlmepriv);
if (_SUCCESS == s_ret) {
_set_timer(&pmlmepriv->assoc_timer, MAX_JOIN_TIMEOUT);
} else if (s_ret == 2) {
_clr_fwstate_(pmlmepriv, _FW_UNDER_LINKING);
rtw_indicate_connect(adapter);
} else {
DBG_88E("try_to_join, but select scanning queue fail, to_roaming:%d\n", pmlmepriv->to_roaming);
if (pmlmepriv->to_roaming != 0) {
if (--pmlmepriv->to_roaming == 0 ||
_SUCCESS != rtw_sitesurvey_cmd(adapter, &pmlmepriv->assoc_ssid, 1, NULL, 0)) {
pmlmepriv->to_roaming = 0;
rtw_free_assoc_resources(adapter, 1);
rtw_indicate_disconnect(adapter);
} else {
pmlmepriv->to_join = true;
}
}
_clr_fwstate_(pmlmepriv, _FW_UNDER_LINKING);
}
}
}
indicate_wx_scan_complete_event(adapter);
_exit_critical_bh(&pmlmepriv->lock, &irql);
if (check_fwstate(pmlmepriv, _FW_LINKED) == true)
p2p_ps_wk_cmd(adapter, P2P_PS_SCAN_DONE, 0);
rtw_os_xmit_schedule(adapter);
pmlmeext = &adapter->mlmeextpriv;
if (pmlmeext->sitesurvey_res.bss_cnt == 0)
rtw_hal_sreset_reset(adapter);
_func_exit_;
}
void rtw_dummy_event_callback(struct adapter *adapter , u8 *pbuf)
{
}
void rtw_fwdbg_event_callback(struct adapter *adapter , u8 *pbuf)
{
}
static void free_scanqueue(struct mlme_priv *pmlmepriv)
{
unsigned long irql, irql0;
struct __queue *free_queue = &pmlmepriv->free_bss_pool;
struct __queue *scan_queue = &pmlmepriv->scanned_queue;
struct list_head *plist, *phead, *ptemp;
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_notice_, ("+free_scanqueue\n"));
_enter_critical_bh(&scan_queue->lock, &irql0);
_enter_critical_bh(&free_queue->lock, &irql);
phead = get_list_head(scan_queue);
plist = get_next(phead);
while (plist != phead) {
ptemp = get_next(plist);
rtw_list_delete(plist);
rtw_list_insert_tail(plist, &free_queue->queue);
plist = ptemp;
pmlmepriv->num_of_scanned--;
}
_exit_critical_bh(&free_queue->lock, &irql);
_exit_critical_bh(&scan_queue->lock, &irql0);
_func_exit_;
}
void rtw_free_assoc_resources(struct adapter *adapter, int lock_scanned_queue)
{
unsigned long irql;
struct wlan_network *pwlan = NULL;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
struct sta_priv *pstapriv = &adapter->stapriv;
struct wlan_network *tgt_network = &pmlmepriv->cur_network;
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_notice_, ("+rtw_free_assoc_resources\n"));
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_,
("tgt_network->network.MacAddress=%pM ssid=%s\n",
tgt_network->network.MacAddress, tgt_network->network.Ssid.Ssid));
if (check_fwstate(pmlmepriv, WIFI_STATION_STATE | WIFI_AP_STATE)) {
struct sta_info *psta;
psta = rtw_get_stainfo(&adapter->stapriv, tgt_network->network.MacAddress);
_enter_critical_bh(&(pstapriv->sta_hash_lock), &irql);
rtw_free_stainfo(adapter, psta);
_exit_critical_bh(&(pstapriv->sta_hash_lock), &irql);
}
if (check_fwstate(pmlmepriv, WIFI_ADHOC_STATE | WIFI_ADHOC_MASTER_STATE | WIFI_AP_STATE)) {
struct sta_info *psta;
rtw_free_all_stainfo(adapter);
psta = rtw_get_bcmc_stainfo(adapter);
_enter_critical_bh(&(pstapriv->sta_hash_lock), &irql);
rtw_free_stainfo(adapter, psta);
_exit_critical_bh(&(pstapriv->sta_hash_lock), &irql);
rtw_init_bcmc_stainfo(adapter);
}
if (lock_scanned_queue)
_enter_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
pwlan = rtw_find_network(&pmlmepriv->scanned_queue, tgt_network->network.MacAddress);
if (pwlan)
pwlan->fixed = false;
else
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("rtw_free_assoc_resources:pwlan==NULL\n\n"));
if ((check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE) && (adapter->stapriv.asoc_sta_count == 1)))
rtw_free_network_nolock(pmlmepriv, pwlan);
if (lock_scanned_queue)
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
pmlmepriv->key_mask = 0;
_func_exit_;
}
void rtw_indicate_connect(struct adapter *padapter)
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("+rtw_indicate_connect\n"));
pmlmepriv->to_join = false;
if (!check_fwstate(&padapter->mlmepriv, _FW_LINKED)) {
set_fwstate(pmlmepriv, _FW_LINKED);
rtw_led_control(padapter, LED_CTL_LINK);
rtw_os_indicate_connect(padapter);
}
pmlmepriv->to_roaming = 0;
rtw_set_scan_deny(padapter, 3000);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("-rtw_indicate_connect: fw_state=0x%08x\n", get_fwstate(pmlmepriv)));
_func_exit_;
}
void rtw_indicate_disconnect(struct adapter *padapter)
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("+rtw_indicate_disconnect\n"));
_clr_fwstate_(pmlmepriv, _FW_UNDER_LINKING | WIFI_UNDER_WPS);
if (pmlmepriv->to_roaming > 0)
_clr_fwstate_(pmlmepriv, _FW_LINKED);
if (check_fwstate(&padapter->mlmepriv, _FW_LINKED) ||
(pmlmepriv->to_roaming <= 0)) {
rtw_os_indicate_disconnect(padapter);
_clr_fwstate_(pmlmepriv, _FW_LINKED);
rtw_led_control(padapter, LED_CTL_NO_LINK);
rtw_clear_scan_deny(padapter);
}
p2p_ps_wk_cmd(padapter, P2P_PS_DISABLE, 1);
rtw_lps_ctrl_wk_cmd(padapter, LPS_CTRL_DISCONNECT, 1);
_func_exit_;
}
inline void rtw_indicate_scan_done(struct adapter *padapter, bool aborted)
{
rtw_os_indicate_scan_done(padapter, aborted);
}
void rtw_scan_abort(struct adapter *adapter)
{
u32 start;
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
struct mlme_ext_priv *pmlmeext = &(adapter->mlmeextpriv);
start = rtw_get_current_time();
pmlmeext->scan_abort = true;
while (check_fwstate(pmlmepriv, _FW_UNDER_SURVEY) &&
rtw_get_passing_time_ms(start) <= 200) {
if (adapter->bDriverStopped || adapter->bSurpriseRemoved)
break;
DBG_88E(FUNC_NDEV_FMT"fw_state=_FW_UNDER_SURVEY!\n", FUNC_NDEV_ARG(adapter->pnetdev));
rtw_msleep_os(20);
}
if (check_fwstate(pmlmepriv, _FW_UNDER_SURVEY)) {
if (!adapter->bDriverStopped && !adapter->bSurpriseRemoved)
DBG_88E(FUNC_NDEV_FMT"waiting for scan_abort time out!\n", FUNC_NDEV_ARG(adapter->pnetdev));
rtw_indicate_scan_done(adapter, true);
}
pmlmeext->scan_abort = false;
}
static struct sta_info *rtw_joinbss_update_stainfo(struct adapter *padapter, struct wlan_network *pnetwork)
{
int i;
struct sta_info *bmc_sta, *psta = NULL;
struct recv_reorder_ctrl *preorder_ctrl;
struct sta_priv *pstapriv = &padapter->stapriv;
psta = rtw_get_stainfo(pstapriv, pnetwork->network.MacAddress);
if (psta == NULL)
psta = rtw_alloc_stainfo(pstapriv, pnetwork->network.MacAddress);
if (psta) {
DBG_88E("%s\n", __func__);
psta->aid = pnetwork->join_res;
psta->mac_id = 0;
rtw_hal_set_odm_var(padapter, HAL_ODM_STA_INFO, psta, true);
if (padapter->securitypriv.dot11AuthAlgrthm == dot11AuthAlgrthm_8021X) {
padapter->securitypriv.binstallGrpkey = false;
padapter->securitypriv.busetkipkey = false;
padapter->securitypriv.bgrpkey_handshake = false;
psta->ieee8021x_blocked = true;
psta->dot118021XPrivacy = padapter->securitypriv.dot11PrivacyAlgrthm;
_rtw_memset((u8 *)&psta->dot118021x_UncstKey, 0, sizeof(union Keytype));
_rtw_memset((u8 *)&psta->dot11tkiprxmickey, 0, sizeof(union Keytype));
_rtw_memset((u8 *)&psta->dot11tkiptxmickey, 0, sizeof(union Keytype));
_rtw_memset((u8 *)&psta->dot11txpn, 0, sizeof(union pn48));
_rtw_memset((u8 *)&psta->dot11rxpn, 0, sizeof(union pn48));
}
if (padapter->securitypriv.wps_ie_len != 0) {
psta->ieee8021x_blocked = true;
padapter->securitypriv.wps_ie_len = 0;
}
for (i = 0; i < 16; i++) {
preorder_ctrl = &psta->recvreorder_ctrl[i];
preorder_ctrl->enable = false;
preorder_ctrl->indicate_seq = 0xffff;
preorder_ctrl->wend_b = 0xffff;
preorder_ctrl->wsize_b = 64;
}
bmc_sta = rtw_get_bcmc_stainfo(padapter);
if (bmc_sta) {
for (i = 0; i < 16; i++) {
preorder_ctrl = &bmc_sta->recvreorder_ctrl[i];
preorder_ctrl->enable = false;
preorder_ctrl->indicate_seq = 0xffff;
preorder_ctrl->wend_b = 0xffff;
preorder_ctrl->wsize_b = 64;
}
}
update_sta_info(padapter, psta);
}
return psta;
}
static void rtw_joinbss_update_network(struct adapter *padapter, struct wlan_network *ptarget_wlan, struct wlan_network *pnetwork)
{
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
struct wlan_network *cur_network = &(pmlmepriv->cur_network);
DBG_88E("%s\n", __func__);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_,
("\nfw_state:%x, BSSID:%pM\n",
get_fwstate(pmlmepriv), pnetwork->network.MacAddress));
memcpy(&cur_network->network, &pnetwork->network, pnetwork->network.Length);
cur_network->network.IELength = ptarget_wlan->network.IELength;
memcpy(&cur_network->network.IEs[0], &ptarget_wlan->network.IEs[0], MAX_IE_SZ);
cur_network->aid = pnetwork->join_res;
rtw_set_signal_stat_timer(&padapter->recvpriv);
padapter->recvpriv.signal_strength = ptarget_wlan->network.PhyInfo.SignalStrength;
padapter->recvpriv.signal_qual = ptarget_wlan->network.PhyInfo.SignalQuality;
padapter->recvpriv.rssi = translate_percentage_to_dbm(ptarget_wlan->network.PhyInfo.SignalStrength);
rtw_set_signal_stat_timer(&padapter->recvpriv);
switch (pnetwork->network.InfrastructureMode) {
case Ndis802_11Infrastructure:
if (pmlmepriv->fw_state&WIFI_UNDER_WPS)
pmlmepriv->fw_state = WIFI_STATION_STATE|WIFI_UNDER_WPS;
else
pmlmepriv->fw_state = WIFI_STATION_STATE;
break;
case Ndis802_11IBSS:
pmlmepriv->fw_state = WIFI_ADHOC_STATE;
break;
default:
pmlmepriv->fw_state = WIFI_NULL_STATE;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("Invalid network_mode\n"));
break;
}
rtw_update_protection(padapter, (cur_network->network.IEs) +
sizeof(struct ndis_802_11_fixed_ie),
(cur_network->network.IELength));
rtw_update_ht_cap(padapter, cur_network->network.IEs, cur_network->network.IELength);
}
void rtw_joinbss_event_prehandle(struct adapter *adapter, u8 *pbuf)
{
unsigned long irql, irql2;
u8 timer_cancelled;
struct sta_info *ptarget_sta = NULL, *pcur_sta = NULL;
struct sta_priv *pstapriv = &adapter->stapriv;
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
struct wlan_network *pnetwork = (struct wlan_network *)pbuf;
struct wlan_network *cur_network = &(pmlmepriv->cur_network);
struct wlan_network *pcur_wlan = NULL, *ptarget_wlan = NULL;
unsigned int the_same_macaddr = false;
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_, ("joinbss event call back received with res=%d\n", pnetwork->join_res));
rtw_get_encrypt_decrypt_from_registrypriv(adapter);
if (pmlmepriv->assoc_ssid.SsidLength == 0)
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("@@@@@ joinbss event call back for Any SSid\n"));
else
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("@@@@@ rtw_joinbss_event_callback for SSid:%s\n", pmlmepriv->assoc_ssid.Ssid));
the_same_macaddr = _rtw_memcmp(pnetwork->network.MacAddress, cur_network->network.MacAddress, ETH_ALEN);
pnetwork->network.Length = get_wlan_bssid_ex_sz(&pnetwork->network);
if (pnetwork->network.Length > sizeof(struct wlan_bssid_ex)) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("\n\n ***joinbss_evt_callback return a wrong bss ***\n\n"));
goto ignore_nolock;
}
_enter_critical_bh(&pmlmepriv->lock, &irql);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_, ("\nrtw_joinbss_event_callback!! _enter_critical\n"));
if (pnetwork->join_res > 0) {
_enter_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
if (check_fwstate(pmlmepriv, _FW_UNDER_LINKING)) {
if (check_fwstate(pmlmepriv, _FW_LINKED)) {
if (the_same_macaddr) {
ptarget_wlan = rtw_find_network(&pmlmepriv->scanned_queue, cur_network->network.MacAddress);
} else {
pcur_wlan = rtw_find_network(&pmlmepriv->scanned_queue, cur_network->network.MacAddress);
if (pcur_wlan)
pcur_wlan->fixed = false;
pcur_sta = rtw_get_stainfo(pstapriv, cur_network->network.MacAddress);
if (pcur_sta) {
_enter_critical_bh(&(pstapriv->sta_hash_lock), &irql2);
rtw_free_stainfo(adapter, pcur_sta);
_exit_critical_bh(&(pstapriv->sta_hash_lock), &irql2);
}
ptarget_wlan = rtw_find_network(&pmlmepriv->scanned_queue, pnetwork->network.MacAddress);
if (check_fwstate(pmlmepriv, WIFI_STATION_STATE) == true) {
if (ptarget_wlan)
ptarget_wlan->fixed = true;
}
}
} else {
ptarget_wlan = rtw_find_network(&pmlmepriv->scanned_queue, pnetwork->network.MacAddress);
if (check_fwstate(pmlmepriv, WIFI_STATION_STATE) == true) {
if (ptarget_wlan)
ptarget_wlan->fixed = true;
}
}
if (ptarget_wlan) {
rtw_joinbss_update_network(adapter, ptarget_wlan, pnetwork);
} else {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("Can't find ptarget_wlan when joinbss_event callback\n"));
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
goto ignore_joinbss_callback;
}
if (check_fwstate(pmlmepriv, WIFI_STATION_STATE) == true) {
ptarget_sta = rtw_joinbss_update_stainfo(adapter, pnetwork);
if (ptarget_sta == NULL) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("Can't update stainfo when joinbss_event callback\n"));
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
goto ignore_joinbss_callback;
}
}
if (check_fwstate(pmlmepriv, WIFI_STATION_STATE) == true) {
rtw_indicate_connect(adapter);
} else {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_, ("adhoc mode, fw_state:%x", get_fwstate(pmlmepriv)));
}
_cancel_timer(&pmlmepriv->assoc_timer, &timer_cancelled);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_, ("Cancle assoc_timer\n"));
} else {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("rtw_joinbss_event_callback err: fw_state:%x", get_fwstate(pmlmepriv)));
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
goto ignore_joinbss_callback;
}
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
} else if (pnetwork->join_res == -4) {
rtw_reset_securitypriv(adapter);
_set_timer(&pmlmepriv->assoc_timer, 1);
if ((check_fwstate(pmlmepriv, _FW_UNDER_LINKING)) == true) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("fail! clear _FW_UNDER_LINKING ^^^fw_state=%x\n", get_fwstate(pmlmepriv)));
_clr_fwstate_(pmlmepriv, _FW_UNDER_LINKING);
}
} else {
_set_timer(&pmlmepriv->assoc_timer, 1);
_clr_fwstate_(pmlmepriv, _FW_UNDER_LINKING);
}
ignore_joinbss_callback:
_exit_critical_bh(&pmlmepriv->lock, &irql);
ignore_nolock:
_func_exit_;
}
void rtw_joinbss_event_callback(struct adapter *adapter, u8 *pbuf)
{
struct wlan_network *pnetwork = (struct wlan_network *)pbuf;
_func_enter_;
mlmeext_joinbss_event_callback(adapter, pnetwork->join_res);
rtw_os_xmit_schedule(adapter);
_func_exit_;
}
static u8 search_max_mac_id(struct adapter *padapter)
{
u8 mac_id;
#if defined (CONFIG_88EU_AP_MODE)
u8 aid;
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
struct sta_priv *pstapriv = &padapter->stapriv;
#endif
struct mlme_ext_priv *pmlmeext = &(padapter->mlmeextpriv);
struct mlme_ext_info *pmlmeinfo = &(pmlmeext->mlmext_info);
#if defined (CONFIG_88EU_AP_MODE)
if (check_fwstate(pmlmepriv, WIFI_AP_STATE)) {
for (aid = (pstapriv->max_num_sta); aid > 0; aid--) {
if (pstapriv->sta_aid[aid-1] != NULL)
break;
}
mac_id = aid + 1;
} else
#endif
{
for (mac_id = (NUM_STA-1); mac_id >= IBSS_START_MAC_ID; mac_id--) {
if (pmlmeinfo->FW_sta_info[mac_id].status == 1)
break;
}
}
return mac_id;
}
void rtw_stassoc_hw_rpt(struct adapter *adapter, struct sta_info *psta)
{
u16 media_status;
u8 macid;
if (psta == NULL)
return;
macid = search_max_mac_id(adapter);
rtw_hal_set_hwreg(adapter, HW_VAR_TX_RPT_MAX_MACID, (u8 *)&macid);
media_status = (psta->mac_id<<8)|1;
rtw_hal_set_hwreg(adapter, HW_VAR_H2C_MEDIA_STATUS_RPT, (u8 *)&media_status);
}
void rtw_stassoc_event_callback(struct adapter *adapter, u8 *pbuf)
{
unsigned long irql;
struct sta_info *psta;
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
struct stassoc_event *pstassoc = (struct stassoc_event *)pbuf;
struct wlan_network *cur_network = &(pmlmepriv->cur_network);
struct wlan_network *ptarget_wlan = NULL;
_func_enter_;
if (rtw_access_ctrl(adapter, pstassoc->macaddr) == false)
return;
#if defined (CONFIG_88EU_AP_MODE)
if (check_fwstate(pmlmepriv, WIFI_AP_STATE)) {
psta = rtw_get_stainfo(&adapter->stapriv, pstassoc->macaddr);
if (psta) {
ap_sta_info_defer_update(adapter, psta);
rtw_stassoc_hw_rpt(adapter, psta);
}
goto exit;
}
#endif
psta = rtw_get_stainfo(&adapter->stapriv, pstassoc->macaddr);
if (psta != NULL) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("Error: rtw_stassoc_event_callback: sta has been in sta_hash_queue\n"));
goto exit;
}
psta = rtw_alloc_stainfo(&adapter->stapriv, pstassoc->macaddr);
if (psta == NULL) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("Can't alloc sta_info when rtw_stassoc_event_callback\n"));
goto exit;
}
psta->qos_option = 0;
psta->mac_id = (uint)pstassoc->cam_id;
DBG_88E("%s\n", __func__);
rtw_hal_set_odm_var(adapter, HAL_ODM_STA_INFO, psta, true);
rtw_stassoc_hw_rpt(adapter, psta);
if (adapter->securitypriv.dot11AuthAlgrthm == dot11AuthAlgrthm_8021X)
psta->dot118021XPrivacy = adapter->securitypriv.dot11PrivacyAlgrthm;
psta->ieee8021x_blocked = false;
_enter_critical_bh(&pmlmepriv->lock, &irql);
if ((check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE)) ||
(check_fwstate(pmlmepriv, WIFI_ADHOC_STATE))) {
if (adapter->stapriv.asoc_sta_count == 2) {
_enter_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
ptarget_wlan = rtw_find_network(&pmlmepriv->scanned_queue, cur_network->network.MacAddress);
if (ptarget_wlan)
ptarget_wlan->fixed = true;
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
rtw_indicate_connect(adapter);
}
}
_exit_critical_bh(&pmlmepriv->lock, &irql);
mlmeext_sta_add_event_callback(adapter, psta);
exit:
_func_exit_;
}
void rtw_stadel_event_callback(struct adapter *adapter, u8 *pbuf)
{
unsigned long irql, irql2;
int mac_id = -1;
struct sta_info *psta;
struct wlan_network *pwlan = NULL;
struct wlan_bssid_ex *pdev_network = NULL;
u8 *pibss = NULL;
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
struct stadel_event *pstadel = (struct stadel_event *)pbuf;
struct sta_priv *pstapriv = &adapter->stapriv;
struct wlan_network *tgt_network = &(pmlmepriv->cur_network);
_func_enter_;
psta = rtw_get_stainfo(&adapter->stapriv, pstadel->macaddr);
if (psta)
mac_id = psta->mac_id;
else
mac_id = pstadel->mac_id;
DBG_88E("%s(mac_id=%d)=%pM\n", __func__, mac_id, pstadel->macaddr);
if (mac_id >= 0) {
u16 media_status;
media_status = (mac_id<<8)|0;
rtw_hal_set_hwreg(adapter, HW_VAR_H2C_MEDIA_STATUS_RPT, (u8 *)&media_status);
}
if (check_fwstate(pmlmepriv, WIFI_AP_STATE))
return;
mlmeext_sta_del_event_callback(adapter);
_enter_critical_bh(&pmlmepriv->lock, &irql2);
if (check_fwstate(pmlmepriv, WIFI_STATION_STATE)) {
if (pmlmepriv->to_roaming > 0)
pmlmepriv->to_roaming--;
else if (pmlmepriv->to_roaming == 0)
pmlmepriv->to_roaming = adapter->registrypriv.max_roaming_times;
if (*((unsigned short *)(pstadel->rsvd)) != WLAN_REASON_EXPIRATION_CHK)
pmlmepriv->to_roaming = 0;
rtw_free_uc_swdec_pending_queue(adapter);
rtw_free_assoc_resources(adapter, 1);
rtw_indicate_disconnect(adapter);
_enter_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
pwlan = rtw_find_network(&pmlmepriv->scanned_queue, tgt_network->network.MacAddress);
if (pwlan) {
pwlan->fixed = false;
rtw_free_network_nolock(pmlmepriv, pwlan);
}
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
_rtw_roaming(adapter, tgt_network);
}
if (check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE) ||
check_fwstate(pmlmepriv, WIFI_ADHOC_STATE)) {
_enter_critical_bh(&(pstapriv->sta_hash_lock), &irql);
rtw_free_stainfo(adapter, psta);
_exit_critical_bh(&(pstapriv->sta_hash_lock), &irql);
if (adapter->stapriv.asoc_sta_count == 1) {
_enter_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
pwlan = rtw_find_network(&pmlmepriv->scanned_queue, tgt_network->network.MacAddress);
if (pwlan) {
pwlan->fixed = false;
rtw_free_network_nolock(pmlmepriv, pwlan);
}
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
pdev_network = &(adapter->registrypriv.dev_network);
pibss = adapter->registrypriv.dev_network.MacAddress;
memcpy(pdev_network, &tgt_network->network, get_wlan_bssid_ex_sz(&tgt_network->network));
_rtw_memset(&pdev_network->Ssid, 0, sizeof(struct ndis_802_11_ssid));
memcpy(&pdev_network->Ssid, &pmlmepriv->assoc_ssid, sizeof(struct ndis_802_11_ssid));
rtw_update_registrypriv_dev_network(adapter);
rtw_generate_random_ibss(pibss);
if (check_fwstate(pmlmepriv, WIFI_ADHOC_STATE)) {
set_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE);
_clr_fwstate_(pmlmepriv, WIFI_ADHOC_STATE);
}
if (rtw_createbss_cmd(adapter) != _SUCCESS)
RT_TRACE(_module_rtl871x_ioctl_set_c_, _drv_err_, ("***Error=>stadel_event_callback: rtw_createbss_cmd status FAIL***\n "));
}
}
_exit_critical_bh(&pmlmepriv->lock, &irql2);
_func_exit_;
}
void rtw_cpwm_event_callback(struct adapter *padapter, u8 *pbuf)
{
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("+rtw_cpwm_event_callback !!!\n"));
_func_exit_;
}
void _rtw_join_timeout_handler (struct adapter *adapter)
{
unsigned long irql;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
int do_join_r;
_func_enter_;
DBG_88E("%s, fw_state=%x\n", __func__, get_fwstate(pmlmepriv));
if (adapter->bDriverStopped || adapter->bSurpriseRemoved)
return;
_enter_critical_bh(&pmlmepriv->lock, &irql);
if (pmlmepriv->to_roaming > 0) {
while (1) {
pmlmepriv->to_roaming--;
if (pmlmepriv->to_roaming != 0) {
DBG_88E("%s try another roaming\n", __func__);
do_join_r = rtw_do_join(adapter);
if (_SUCCESS != do_join_r) {
DBG_88E("%s roaming do_join return %d\n", __func__ , do_join_r);
continue;
}
break;
} else {
DBG_88E("%s We've try roaming but fail\n", __func__);
rtw_indicate_disconnect(adapter);
break;
}
}
} else {
rtw_indicate_disconnect(adapter);
free_scanqueue(pmlmepriv);
}
_exit_critical_bh(&pmlmepriv->lock, &irql);
_func_exit_;
}
void rtw_scan_timeout_handler (struct adapter *adapter)
{
unsigned long irql;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
DBG_88E(FUNC_ADPT_FMT" fw_state=%x\n", FUNC_ADPT_ARG(adapter), get_fwstate(pmlmepriv));
_enter_critical_bh(&pmlmepriv->lock, &irql);
_clr_fwstate_(pmlmepriv, _FW_UNDER_SURVEY);
_exit_critical_bh(&pmlmepriv->lock, &irql);
rtw_indicate_scan_done(adapter, true);
}
static void rtw_auto_scan_handler(struct adapter *padapter)
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
if (pmlmepriv->scan_interval > 0) {
pmlmepriv->scan_interval--;
if (pmlmepriv->scan_interval == 0) {
DBG_88E("%s\n", __func__);
rtw_set_802_11_bssid_list_scan(padapter, NULL, 0);
pmlmepriv->scan_interval = SCAN_INTERVAL;
}
}
}
void rtw_dynamic_check_timer_handlder(struct adapter *adapter)
{
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
struct registry_priv *pregistrypriv = &adapter->registrypriv;
if (!adapter)
return;
if (!adapter->hw_init_completed)
return;
if ((adapter->bDriverStopped) || (adapter->bSurpriseRemoved))
return;
if (adapter->net_closed)
return;
rtw_dynamic_chk_wk_cmd(adapter);
if (pregistrypriv->wifi_spec == 1) {
#ifdef CONFIG_88EU_P2P
struct wifidirect_info *pwdinfo = &adapter->wdinfo;
if (rtw_p2p_chk_state(pwdinfo, P2P_STATE_NONE))
#endif
{
rtw_auto_scan_handler(adapter);
}
}
rcu_read_lock();
if (rcu_dereference(adapter->pnetdev->rx_handler_data) &&
(check_fwstate(pmlmepriv, WIFI_STATION_STATE|WIFI_ADHOC_STATE) == true)) {
nat25_db_expire(adapter);
if (adapter->pppoe_connection_in_progress > 0) {
adapter->pppoe_connection_in_progress--;
}
if (adapter->pppoe_connection_in_progress > 0) {
adapter->pppoe_connection_in_progress--;
}
}
rcu_read_unlock();
}
static int rtw_check_join_candidate(struct mlme_priv *pmlmepriv
, struct wlan_network **candidate, struct wlan_network *competitor)
{
int updated = false;
struct adapter *adapter = container_of(pmlmepriv, struct adapter, mlmepriv);
if (pmlmepriv->assoc_by_bssid) {
if (!_rtw_memcmp(competitor->network.MacAddress, pmlmepriv->assoc_bssid, ETH_ALEN))
goto exit;
}
if (pmlmepriv->assoc_ssid.Ssid && pmlmepriv->assoc_ssid.SsidLength) {
if (competitor->network.Ssid.SsidLength != pmlmepriv->assoc_ssid.SsidLength ||
_rtw_memcmp(competitor->network.Ssid.Ssid, pmlmepriv->assoc_ssid.Ssid, pmlmepriv->assoc_ssid.SsidLength) == false)
goto exit;
}
if (rtw_is_desired_network(adapter, competitor) == false)
goto exit;
if (pmlmepriv->to_roaming) {
if (rtw_get_passing_time_ms((u32)competitor->last_scanned) >= RTW_SCAN_RESULT_EXPIRE ||
is_same_ess(&competitor->network, &pmlmepriv->cur_network.network) == false)
goto exit;
}
if (*candidate == NULL || (*candidate)->network.Rssi < competitor->network.Rssi) {
*candidate = competitor;
updated = true;
}
if (updated) {
DBG_88E("[by_bssid:%u][assoc_ssid:%s]new candidate: %s(%pM rssi:%d\n",
pmlmepriv->assoc_by_bssid,
pmlmepriv->assoc_ssid.Ssid,
(*candidate)->network.Ssid.Ssid,
(*candidate)->network.MacAddress,
(int)(*candidate)->network.Rssi);
DBG_88E("[to_roaming:%u]\n", pmlmepriv->to_roaming);
}
exit:
return updated;
}
int rtw_select_and_join_from_scanned_queue(struct mlme_priv *pmlmepriv)
{
unsigned long irql;
int ret;
struct list_head *phead;
struct adapter *adapter;
struct __queue *queue = &(pmlmepriv->scanned_queue);
struct wlan_network *pnetwork = NULL;
struct wlan_network *candidate = NULL;
u8 supp_ant_div = false;
_func_enter_;
_enter_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
phead = get_list_head(queue);
adapter = (struct adapter *)pmlmepriv->nic_hdl;
pmlmepriv->pscanned = get_next(phead);
while (!rtw_end_of_queue_search(phead, pmlmepriv->pscanned)) {
pnetwork = LIST_CONTAINOR(pmlmepriv->pscanned, struct wlan_network, list);
if (pnetwork == NULL) {
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_, ("%s return _FAIL:(pnetwork==NULL)\n", __func__));
ret = _FAIL;
goto exit;
}
pmlmepriv->pscanned = get_next(pmlmepriv->pscanned);
rtw_check_join_candidate(pmlmepriv, &candidate, pnetwork);
}
if (candidate == NULL) {
DBG_88E("%s: return _FAIL(candidate==NULL)\n", __func__);
ret = _FAIL;
goto exit;
} else {
DBG_88E("%s: candidate: %s(%pM ch:%u)\n", __func__,
candidate->network.Ssid.Ssid, candidate->network.MacAddress,
candidate->network.Configuration.DSConfig);
}
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
DBG_88E("%s: _FW_LINKED while ask_for_joinbss!!!\n", __func__);
rtw_disassoc_cmd(adapter, 0, true);
rtw_indicate_disconnect(adapter);
rtw_free_assoc_resources(adapter, 0);
}
rtw_hal_get_def_var(adapter, HAL_DEF_IS_SUPPORT_ANT_DIV, &(supp_ant_div));
if (supp_ant_div) {
u8 cur_ant;
rtw_hal_get_def_var(adapter, HAL_DEF_CURRENT_ANTENNA, &(cur_ant));
DBG_88E("#### Opt_Ant_(%s), cur_Ant(%s)\n",
(2 == candidate->network.PhyInfo.Optimum_antenna) ? "A" : "B",
(2 == cur_ant) ? "A" : "B"
);
}
ret = rtw_joinbss_cmd(adapter, candidate);
exit:
_exit_critical_bh(&(pmlmepriv->scanned_queue.lock), &irql);
_func_exit_;
return ret;
}
int rtw_set_auth(struct adapter *adapter, struct security_priv *psecuritypriv)
{
struct cmd_obj *pcmd;
struct setauth_parm *psetauthparm;
struct cmd_priv *pcmdpriv = &(adapter->cmdpriv);
int res = _SUCCESS;
_func_enter_;
pcmd = (struct cmd_obj *)rtw_zmalloc(sizeof(struct cmd_obj));
if (pcmd == NULL) {
res = _FAIL;
goto exit;
}
psetauthparm = (struct setauth_parm *)rtw_zmalloc(sizeof(struct setauth_parm));
if (psetauthparm == NULL) {
kfree(pcmd);
res = _FAIL;
goto exit;
}
_rtw_memset(psetauthparm, 0, sizeof(struct setauth_parm));
psetauthparm->mode = (unsigned char)psecuritypriv->dot11AuthAlgrthm;
pcmd->cmdcode = _SetAuth_CMD_;
pcmd->parmbuf = (unsigned char *)psetauthparm;
pcmd->cmdsz = (sizeof(struct setauth_parm));
pcmd->rsp = NULL;
pcmd->rspsz = 0;
_rtw_init_listhead(&pcmd->list);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_,
("after enqueue set_auth_cmd, auth_mode=%x\n",
psecuritypriv->dot11AuthAlgrthm));
res = rtw_enqueue_cmd(pcmdpriv, pcmd);
exit:
_func_exit_;
return res;
}
int rtw_set_key(struct adapter *adapter, struct security_priv *psecuritypriv, int keyid, u8 set_tx)
{
u8 keylen;
struct cmd_obj *pcmd;
struct setkey_parm *psetkeyparm;
struct cmd_priv *pcmdpriv = &(adapter->cmdpriv);
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
int res = _SUCCESS;
_func_enter_;
pcmd = (struct cmd_obj *)rtw_zmalloc(sizeof(struct cmd_obj));
if (pcmd == NULL) {
res = _FAIL;
goto exit;
}
psetkeyparm = (struct setkey_parm *)rtw_zmalloc(sizeof(struct setkey_parm));
if (psetkeyparm == NULL) {
kfree(pcmd);
res = _FAIL;
goto exit;
}
_rtw_memset(psetkeyparm, 0, sizeof(struct setkey_parm));
if (psecuritypriv->dot11AuthAlgrthm == dot11AuthAlgrthm_8021X) {
psetkeyparm->algorithm = (unsigned char)psecuritypriv->dot118021XGrpPrivacy;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_,
("\n rtw_set_key: psetkeyparm->algorithm=(unsigned char)psecuritypriv->dot118021XGrpPrivacy=%d\n",
psetkeyparm->algorithm));
} else {
psetkeyparm->algorithm = (u8)psecuritypriv->dot11PrivacyAlgrthm;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_,
("\n rtw_set_key: psetkeyparm->algorithm=(u8)psecuritypriv->dot11PrivacyAlgrthm=%d\n",
psetkeyparm->algorithm));
}
psetkeyparm->keyid = (u8)keyid;
psetkeyparm->set_tx = set_tx;
pmlmepriv->key_mask |= BIT(psetkeyparm->keyid);
DBG_88E("==> rtw_set_key algorithm(%x), keyid(%x), key_mask(%x)\n",
psetkeyparm->algorithm, psetkeyparm->keyid, pmlmepriv->key_mask);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_,
("\n rtw_set_key: psetkeyparm->algorithm=%d psetkeyparm->keyid=(u8)keyid=%d\n",
psetkeyparm->algorithm, keyid));
switch (psetkeyparm->algorithm) {
case _WEP40_:
keylen = 5;
memcpy(&(psetkeyparm->key[0]), &(psecuritypriv->dot11DefKey[keyid].skey[0]), keylen);
break;
case _WEP104_:
keylen = 13;
memcpy(&(psetkeyparm->key[0]), &(psecuritypriv->dot11DefKey[keyid].skey[0]), keylen);
break;
case _TKIP_:
keylen = 16;
memcpy(&psetkeyparm->key, &psecuritypriv->dot118021XGrpKey[keyid], keylen);
psetkeyparm->grpkey = 1;
break;
case _AES_:
keylen = 16;
memcpy(&psetkeyparm->key, &psecuritypriv->dot118021XGrpKey[keyid], keylen);
psetkeyparm->grpkey = 1;
break;
default:
RT_TRACE(_module_rtl871x_mlme_c_, _drv_err_,
("\n rtw_set_key:psecuritypriv->dot11PrivacyAlgrthm=%x (must be 1 or 2 or 4 or 5)\n",
psecuritypriv->dot11PrivacyAlgrthm));
res = _FAIL;
goto exit;
}
pcmd->cmdcode = _SetKey_CMD_;
pcmd->parmbuf = (u8 *)psetkeyparm;
pcmd->cmdsz = (sizeof(struct setkey_parm));
pcmd->rsp = NULL;
pcmd->rspsz = 0;
_rtw_init_listhead(&pcmd->list);
res = rtw_enqueue_cmd(pcmdpriv, pcmd);
exit:
_func_exit_;
return res;
}
int rtw_restruct_wmm_ie(struct adapter *adapter, u8 *in_ie, u8 *out_ie, uint in_len, uint initial_out_len)
{
unsigned int ielength = 0;
unsigned int i, j;
i = 12;
while (i < in_len) {
ielength = initial_out_len;
if (in_ie[i] == 0xDD && in_ie[i+2] == 0x00 && in_ie[i+3] == 0x50 && in_ie[i+4] == 0xF2 && in_ie[i+5] == 0x02 && i+5 < in_len) {
for (j = i; j < i + 9; j++) {
out_ie[ielength] = in_ie[j];
ielength++;
}
out_ie[initial_out_len + 1] = 0x07;
out_ie[initial_out_len + 6] = 0x00;
out_ie[initial_out_len + 8] = 0x00;
break;
}
i += (in_ie[i+1]+2);
}
return ielength;
}
static int SecIsInPMKIDList(struct adapter *Adapter, u8 *bssid)
{
struct security_priv *psecuritypriv = &Adapter->securitypriv;
int i = 0;
do {
if ((psecuritypriv->PMKIDList[i].bUsed) &&
(_rtw_memcmp(psecuritypriv->PMKIDList[i].Bssid, bssid, ETH_ALEN) == true)) {
break;
} else {
i++;
}
} while (i < NUM_PMKID_CACHE);
if (i == NUM_PMKID_CACHE) {
i = -1;
} else {
}
return i;
}
static int rtw_append_pmkid(struct adapter *Adapter, int iEntry, u8 *ie, uint ie_len)
{
struct security_priv *psecuritypriv = &Adapter->securitypriv;
if (ie[13] <= 20) {
ie[ie_len] = 1;
ie_len++;
ie[ie_len] = 0;
ie_len++;
memcpy(&ie[ie_len], &psecuritypriv->PMKIDList[iEntry].PMKID, 16);
ie_len += 16;
ie[13] += 18;
}
return ie_len;
}
int rtw_restruct_sec_ie(struct adapter *adapter, u8 *in_ie, u8 *out_ie, uint in_len)
{
u8 authmode;
uint ielength;
int iEntry;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
struct security_priv *psecuritypriv = &adapter->securitypriv;
uint ndisauthmode = psecuritypriv->ndisauthtype;
uint ndissecuritytype = psecuritypriv->ndisencryptstatus;
_func_enter_;
RT_TRACE(_module_rtl871x_mlme_c_, _drv_notice_,
("+rtw_restruct_sec_ie: ndisauthmode=%d ndissecuritytype=%d\n",
ndisauthmode, ndissecuritytype));
memcpy(out_ie, in_ie, 12);
ielength = 12;
if ((ndisauthmode == Ndis802_11AuthModeWPA) ||
(ndisauthmode == Ndis802_11AuthModeWPAPSK))
authmode = _WPA_IE_ID_;
if ((ndisauthmode == Ndis802_11AuthModeWPA2) ||
(ndisauthmode == Ndis802_11AuthModeWPA2PSK))
authmode = _WPA2_IE_ID_;
if (check_fwstate(pmlmepriv, WIFI_UNDER_WPS)) {
memcpy(out_ie+ielength, psecuritypriv->wps_ie, psecuritypriv->wps_ie_len);
ielength += psecuritypriv->wps_ie_len;
} else if ((authmode == _WPA_IE_ID_) || (authmode == _WPA2_IE_ID_)) {
memcpy(&out_ie[ielength], &psecuritypriv->supplicant_ie[0], psecuritypriv->supplicant_ie[1]+2);
ielength += psecuritypriv->supplicant_ie[1]+2;
rtw_report_sec_ie(adapter, authmode, psecuritypriv->supplicant_ie);
}
iEntry = SecIsInPMKIDList(adapter, pmlmepriv->assoc_bssid);
if (iEntry < 0) {
return ielength;
} else {
if (authmode == _WPA2_IE_ID_)
ielength = rtw_append_pmkid(adapter, iEntry, out_ie, ielength);
}
_func_exit_;
return ielength;
}
void rtw_init_registrypriv_dev_network(struct adapter *adapter)
{
struct registry_priv *pregistrypriv = &adapter->registrypriv;
struct eeprom_priv *peepriv = &adapter->eeprompriv;
struct wlan_bssid_ex *pdev_network = &pregistrypriv->dev_network;
u8 *myhwaddr = myid(peepriv);
_func_enter_;
memcpy(pdev_network->MacAddress, myhwaddr, ETH_ALEN);
memcpy(&pdev_network->Ssid, &pregistrypriv->ssid, sizeof(struct ndis_802_11_ssid));
pdev_network->Configuration.Length = sizeof(struct ndis_802_11_config);
pdev_network->Configuration.BeaconPeriod = 100;
pdev_network->Configuration.FHConfig.Length = 0;
pdev_network->Configuration.FHConfig.HopPattern = 0;
pdev_network->Configuration.FHConfig.HopSet = 0;
pdev_network->Configuration.FHConfig.DwellTime = 0;
_func_exit_;
}
void rtw_update_registrypriv_dev_network(struct adapter *adapter)
{
int sz = 0;
struct registry_priv *pregistrypriv = &adapter->registrypriv;
struct wlan_bssid_ex *pdev_network = &pregistrypriv->dev_network;
struct security_priv *psecuritypriv = &adapter->securitypriv;
struct wlan_network *cur_network = &adapter->mlmepriv.cur_network;
_func_enter_;
pdev_network->Privacy = (psecuritypriv->dot11PrivacyAlgrthm > 0 ? 1 : 0);
pdev_network->Rssi = 0;
switch (pregistrypriv->wireless_mode) {
case WIRELESS_11B:
pdev_network->NetworkTypeInUse = (Ndis802_11DS);
break;
case WIRELESS_11G:
case WIRELESS_11BG:
case WIRELESS_11_24N:
case WIRELESS_11G_24N:
case WIRELESS_11BG_24N:
pdev_network->NetworkTypeInUse = (Ndis802_11OFDM24);
break;
case WIRELESS_11A:
case WIRELESS_11A_5N:
pdev_network->NetworkTypeInUse = (Ndis802_11OFDM5);
break;
case WIRELESS_11ABGN:
if (pregistrypriv->channel > 14)
pdev_network->NetworkTypeInUse = (Ndis802_11OFDM5);
else
pdev_network->NetworkTypeInUse = (Ndis802_11OFDM24);
break;
default:
break;
}
pdev_network->Configuration.DSConfig = (pregistrypriv->channel);
RT_TRACE(_module_rtl871x_mlme_c_, _drv_info_,
("pregistrypriv->channel=%d, pdev_network->Configuration.DSConfig=0x%x\n",
pregistrypriv->channel, pdev_network->Configuration.DSConfig));
if (cur_network->network.InfrastructureMode == Ndis802_11IBSS)
pdev_network->Configuration.ATIMWindow = (0);
pdev_network->InfrastructureMode = (cur_network->network.InfrastructureMode);
sz = rtw_generate_ie(pregistrypriv);
pdev_network->IELength = sz;
pdev_network->Length = get_wlan_bssid_ex_sz((struct wlan_bssid_ex *)pdev_network);
_func_exit_;
}
void rtw_get_encrypt_decrypt_from_registrypriv(struct adapter *adapter)
{
_func_enter_;
_func_exit_;
}
void rtw_joinbss_reset(struct adapter *padapter)
{
u8 threshold;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct ht_priv *phtpriv = &pmlmepriv->htpriv;
pmlmepriv->num_FortyMHzIntolerant = 0;
pmlmepriv->num_sta_no_ht = 0;
phtpriv->ampdu_enable = false;
if (phtpriv->ht_option) {
if (padapter->registrypriv.wifi_spec == 1)
threshold = 1;
else
threshold = 0;
rtw_hal_set_hwreg(padapter, HW_VAR_RXDMA_AGG_PG_TH, (u8 *)(&threshold));
} else {
threshold = 1;
rtw_hal_set_hwreg(padapter, HW_VAR_RXDMA_AGG_PG_TH, (u8 *)(&threshold));
}
}
unsigned int rtw_restructure_ht_ie(struct adapter *padapter, u8 *in_ie, u8 *out_ie, uint in_len, uint *pout_len)
{
u32 ielen, out_len;
enum ht_cap_ampdu_factor max_rx_ampdu_factor;
unsigned char *p;
struct rtw_ieee80211_ht_cap ht_capie;
unsigned char WMM_IE[] = {0x00, 0x50, 0xf2, 0x02, 0x00, 0x01, 0x00};
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct qos_priv *pqospriv = &pmlmepriv->qospriv;
struct ht_priv *phtpriv = &pmlmepriv->htpriv;
u32 rx_packet_offset, max_recvbuf_sz;
phtpriv->ht_option = false;
p = rtw_get_ie(in_ie+12, _HT_CAPABILITY_IE_, &ielen, in_len-12);
if (p && ielen > 0) {
if (pqospriv->qos_option == 0) {
out_len = *pout_len;
rtw_set_ie(out_ie+out_len, _VENDOR_SPECIFIC_IE_,
_WMM_IE_Length_, WMM_IE, pout_len);
pqospriv->qos_option = 1;
}
out_len = *pout_len;
_rtw_memset(&ht_capie, 0, sizeof(struct rtw_ieee80211_ht_cap));
ht_capie.cap_info = IEEE80211_HT_CAP_SUP_WIDTH |
IEEE80211_HT_CAP_SGI_20 |
IEEE80211_HT_CAP_SGI_40 |
IEEE80211_HT_CAP_TX_STBC |
IEEE80211_HT_CAP_DSSSCCK40;
rtw_hal_get_def_var(padapter, HAL_DEF_RX_PACKET_OFFSET, &rx_packet_offset);
rtw_hal_get_def_var(padapter, HAL_DEF_MAX_RECVBUF_SZ, &max_recvbuf_sz);
rtw_hal_get_def_var(padapter, HW_VAR_MAX_RX_AMPDU_FACTOR, &max_rx_ampdu_factor);
ht_capie.ampdu_params_info = (max_rx_ampdu_factor&0x03);
if (padapter->securitypriv.dot11PrivacyAlgrthm == _AES_)
ht_capie.ampdu_params_info |= (IEEE80211_HT_CAP_AMPDU_DENSITY&(0x07<<2));
else
ht_capie.ampdu_params_info |= (IEEE80211_HT_CAP_AMPDU_DENSITY&0x00);
rtw_set_ie(out_ie+out_len, _HT_CAPABILITY_IE_,
sizeof(struct rtw_ieee80211_ht_cap), (unsigned char *)&ht_capie, pout_len);
phtpriv->ht_option = true;
p = rtw_get_ie(in_ie+12, _HT_ADD_INFO_IE_, &ielen, in_len-12);
if (p && (ielen == sizeof(struct ieee80211_ht_addt_info))) {
out_len = *pout_len;
rtw_set_ie(out_ie+out_len, _HT_ADD_INFO_IE_, ielen, p+2 , pout_len);
}
}
return phtpriv->ht_option;
}
void rtw_update_ht_cap(struct adapter *padapter, u8 *pie, uint ie_len)
{
u8 *p, max_ampdu_sz;
int len;
struct rtw_ieee80211_ht_cap *pht_capie;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct ht_priv *phtpriv = &pmlmepriv->htpriv;
struct registry_priv *pregistrypriv = &padapter->registrypriv;
struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &(pmlmeext->mlmext_info);
if (!phtpriv->ht_option)
return;
if ((!pmlmeinfo->HT_info_enable) || (!pmlmeinfo->HT_caps_enable))
return;
DBG_88E("+rtw_update_ht_cap()\n");
if ((!phtpriv->ampdu_enable) && (pregistrypriv->ampdu_enable == 1)) {
if (pregistrypriv->wifi_spec == 1)
phtpriv->ampdu_enable = false;
else
phtpriv->ampdu_enable = true;
} else if (pregistrypriv->ampdu_enable == 2) {
phtpriv->ampdu_enable = true;
}
len = 0;
p = rtw_get_ie(pie+sizeof(struct ndis_802_11_fixed_ie), _HT_CAPABILITY_IE_, &len, ie_len-sizeof(struct ndis_802_11_fixed_ie));
if (p && len > 0) {
pht_capie = (struct rtw_ieee80211_ht_cap *)(p+2);
max_ampdu_sz = (pht_capie->ampdu_params_info & IEEE80211_HT_CAP_AMPDU_FACTOR);
max_ampdu_sz = 1 << (max_ampdu_sz+3);
phtpriv->rx_ampdu_maxlen = max_ampdu_sz;
}
len = 0;
p = rtw_get_ie(pie+sizeof(struct ndis_802_11_fixed_ie), _HT_ADD_INFO_IE_, &len, ie_len-sizeof(struct ndis_802_11_fixed_ie));
if ((pregistrypriv->cbw40_enable) &&
(le16_to_cpu(pmlmeinfo->HT_caps.u.HT_cap_element.HT_caps_info) & BIT(1)) &&
(pmlmeinfo->HT_info.infos[0] & BIT(2))) {
int i;
u8 rf_type;
padapter->HalFunc.GetHwRegHandler(padapter, HW_VAR_RF_TYPE, (u8 *)(&rf_type));
for (i = 0; i < 16; i++) {
if ((rf_type == RF_1T1R) || (rf_type == RF_1T2R))
pmlmeinfo->HT_caps.u.HT_cap_element.MCS_rate[i] &= MCS_rate_1R[i];
else
pmlmeinfo->HT_caps.u.HT_cap_element.MCS_rate[i] &= MCS_rate_2R[i];
}
pmlmeext->cur_bwmode = HT_CHANNEL_WIDTH_40;
switch ((pmlmeinfo->HT_info.infos[0] & 0x3)) {
case HT_EXTCHNL_OFFSET_UPPER:
pmlmeext->cur_ch_offset = HAL_PRIME_CHNL_OFFSET_LOWER;
break;
case HT_EXTCHNL_OFFSET_LOWER:
pmlmeext->cur_ch_offset = HAL_PRIME_CHNL_OFFSET_UPPER;
break;
default:
pmlmeext->cur_ch_offset = HAL_PRIME_CHNL_OFFSET_DONT_CARE;
break;
}
}
pmlmeinfo->SM_PS = (le16_to_cpu(pmlmeinfo->HT_caps.u.HT_cap_element.HT_caps_info) & 0x0C) >> 2;
if (pmlmeinfo->SM_PS == WLAN_HT_CAP_SM_PS_STATIC)
DBG_88E("%s(): WLAN_HT_CAP_SM_PS_STATIC\n", __func__);
pmlmeinfo->HT_protection = pmlmeinfo->HT_info.infos[1] & 0x3;
}
void rtw_issue_addbareq_cmd(struct adapter *padapter, struct xmit_frame *pxmitframe)
{
u8 issued;
int priority;
struct sta_info *psta = NULL;
struct ht_priv *phtpriv;
struct pkt_attrib *pattrib = &pxmitframe->attrib;
s32 bmcst = IS_MCAST(pattrib->ra);
if (bmcst || (padapter->mlmepriv.LinkDetectInfo.NumTxOkInPeriod < 100))
return;
priority = pattrib->priority;
if (pattrib->psta)
psta = pattrib->psta;
else
psta = rtw_get_stainfo(&padapter->stapriv, pattrib->ra);
if (psta == NULL)
return;
phtpriv = &psta->htpriv;
if ((phtpriv->ht_option) && (phtpriv->ampdu_enable)) {
issued = (phtpriv->agg_enable_bitmap>>priority)&0x1;
issued |= (phtpriv->candidate_tid_bitmap>>priority)&0x1;
if (0 == issued) {
DBG_88E("rtw_issue_addbareq_cmd, p=%d\n", priority);
psta->htpriv.candidate_tid_bitmap |= BIT((u8)priority);
rtw_addbareq_cmd(padapter, (u8) priority, pattrib->ra);
}
}
}
void rtw_roaming(struct adapter *padapter, struct wlan_network *tgt_network)
{
unsigned long irql;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
_enter_critical_bh(&pmlmepriv->lock, &irql);
_rtw_roaming(padapter, tgt_network);
_exit_critical_bh(&pmlmepriv->lock, &irql);
}
void _rtw_roaming(struct adapter *padapter, struct wlan_network *tgt_network)
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
int do_join_r;
struct wlan_network *pnetwork;
if (tgt_network != NULL)
pnetwork = tgt_network;
else
pnetwork = &pmlmepriv->cur_network;
if (0 < pmlmepriv->to_roaming) {
DBG_88E("roaming from %s(%pM length:%d\n",
pnetwork->network.Ssid.Ssid, pnetwork->network.MacAddress,
pnetwork->network.Ssid.SsidLength);
memcpy(&pmlmepriv->assoc_ssid, &pnetwork->network.Ssid, sizeof(struct ndis_802_11_ssid));
pmlmepriv->assoc_by_bssid = false;
while (1) {
do_join_r = rtw_do_join(padapter);
if (_SUCCESS == do_join_r) {
break;
} else {
DBG_88E("roaming do_join return %d\n", do_join_r);
pmlmepriv->to_roaming--;
if (0 < pmlmepriv->to_roaming) {
continue;
} else {
DBG_88E("%s(%d) -to roaming fail, indicate_disconnect\n", __func__, __LINE__);
rtw_indicate_disconnect(padapter);
break;
}
}
}
}
}
