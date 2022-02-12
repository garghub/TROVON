static int
ath10k_wmi_tlv_iter(struct ath10k *ar, const void *ptr, size_t len,
int (*iter)(struct ath10k *ar, u16 tag, u16 len,
const void *ptr, void *data),
void *data)
{
const void *begin = ptr;
const struct wmi_tlv *tlv;
u16 tlv_tag, tlv_len;
int ret;
while (len > 0) {
if (len < sizeof(*tlv)) {
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv parse failure at byte %zd (%zu bytes left, %zu expected)\n",
ptr - begin, len, sizeof(*tlv));
return -EINVAL;
}
tlv = ptr;
tlv_tag = __le16_to_cpu(tlv->tag);
tlv_len = __le16_to_cpu(tlv->len);
ptr += sizeof(*tlv);
len -= sizeof(*tlv);
if (tlv_len > len) {
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv parse failure of tag %hhu at byte %zd (%zu bytes left, %hhu expected)\n",
tlv_tag, ptr - begin, len, tlv_len);
return -EINVAL;
}
if (tlv_tag < ARRAY_SIZE(wmi_tlv_policies) &&
wmi_tlv_policies[tlv_tag].min_len &&
wmi_tlv_policies[tlv_tag].min_len > tlv_len) {
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv parse failure of tag %hhu at byte %zd (%hhu bytes is less than min length %zu)\n",
tlv_tag, ptr - begin, tlv_len,
wmi_tlv_policies[tlv_tag].min_len);
return -EINVAL;
}
ret = iter(ar, tlv_tag, tlv_len, ptr, data);
if (ret)
return ret;
ptr += tlv_len;
len -= tlv_len;
}
return 0;
}
static int ath10k_wmi_tlv_iter_parse(struct ath10k *ar, u16 tag, u16 len,
const void *ptr, void *data)
{
const void **tb = data;
if (tag < WMI_TLV_TAG_MAX)
tb[tag] = ptr;
return 0;
}
static int ath10k_wmi_tlv_parse(struct ath10k *ar, const void **tb,
const void *ptr, size_t len)
{
return ath10k_wmi_tlv_iter(ar, ptr, len, ath10k_wmi_tlv_iter_parse,
(void *)tb);
}
static const void **
ath10k_wmi_tlv_parse_alloc(struct ath10k *ar, const void *ptr,
size_t len, gfp_t gfp)
{
const void **tb;
int ret;
tb = kzalloc(sizeof(*tb) * WMI_TLV_TAG_MAX, gfp);
if (!tb)
return ERR_PTR(-ENOMEM);
ret = ath10k_wmi_tlv_parse(ar, tb, ptr, len);
if (ret) {
kfree(tb);
return ERR_PTR(ret);
}
return tb;
}
static u16 ath10k_wmi_tlv_len(const void *ptr)
{
return __le16_to_cpu((((const struct wmi_tlv *)ptr) - 1)->len);
}
static int ath10k_wmi_tlv_event_bcn_tx_status(struct ath10k *ar,
struct sk_buff *skb)
{
const void **tb;
const struct wmi_tlv_bcn_tx_status_ev *ev;
struct ath10k_vif *arvif;
u32 vdev_id, tx_status;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_OFFLOAD_BCN_TX_STATUS_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
tx_status = __le32_to_cpu(ev->tx_status);
vdev_id = __le32_to_cpu(ev->vdev_id);
switch (tx_status) {
case WMI_TLV_BCN_TX_STATUS_OK:
break;
case WMI_TLV_BCN_TX_STATUS_XRETRY:
case WMI_TLV_BCN_TX_STATUS_DROP:
case WMI_TLV_BCN_TX_STATUS_FILTERED:
ath10k_warn(ar, "received bcn tmpl tx status on vdev %i: %d",
vdev_id, tx_status);
break;
}
arvif = ath10k_get_arvif(ar, vdev_id);
if (arvif && arvif->is_up && arvif->vif->csa_active)
ieee80211_queue_work(ar->hw, &arvif->ap_csa_work);
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_event_diag_data(struct ath10k *ar,
struct sk_buff *skb)
{
const void **tb;
const struct wmi_tlv_diag_data_ev *ev;
const struct wmi_tlv_diag_item *item;
const void *data;
int ret, num_items, len;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_DIAG_DATA_CONTAINER_EVENT];
data = tb[WMI_TLV_TAG_ARRAY_BYTE];
if (!ev || !data) {
kfree(tb);
return -EPROTO;
}
num_items = __le32_to_cpu(ev->num_items);
len = ath10k_wmi_tlv_len(data);
while (num_items--) {
if (len == 0)
break;
if (len < sizeof(*item)) {
ath10k_warn(ar, "failed to parse diag data: can't fit item header\n");
break;
}
item = data;
if (len < sizeof(*item) + __le16_to_cpu(item->len)) {
ath10k_warn(ar, "failed to parse diag data: item is too long\n");
break;
}
trace_ath10k_wmi_diag_container(ar,
item->type,
__le32_to_cpu(item->timestamp),
__le32_to_cpu(item->code),
__le16_to_cpu(item->len),
item->payload);
len -= sizeof(*item);
len -= roundup(__le16_to_cpu(item->len), 4);
data += sizeof(*item);
data += roundup(__le16_to_cpu(item->len), 4);
}
if (num_items != -1 || len != 0)
ath10k_warn(ar, "failed to parse diag data event: num_items %d len %d\n",
num_items, len);
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_event_diag(struct ath10k *ar,
struct sk_buff *skb)
{
const void **tb;
const void *data;
int ret, len;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
data = tb[WMI_TLV_TAG_ARRAY_BYTE];
if (!data) {
kfree(tb);
return -EPROTO;
}
len = ath10k_wmi_tlv_len(data);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv diag event len %d\n", len);
trace_ath10k_wmi_diag(ar, data, len);
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_event_p2p_noa(struct ath10k *ar,
struct sk_buff *skb)
{
const void **tb;
const struct wmi_tlv_p2p_noa_ev *ev;
const struct wmi_p2p_noa_info *noa;
int ret, vdev_id;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_P2P_NOA_EVENT];
noa = tb[WMI_TLV_TAG_STRUCT_P2P_NOA_INFO];
if (!ev || !noa) {
kfree(tb);
return -EPROTO;
}
vdev_id = __le32_to_cpu(ev->vdev_id);
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv p2p noa vdev_id %i descriptors %hhu\n",
vdev_id, noa->num_descriptors);
ath10k_p2p_noa_update_by_vdev_id(ar, vdev_id, noa);
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_event_tx_pause(struct ath10k *ar,
struct sk_buff *skb)
{
const void **tb;
const struct wmi_tlv_tx_pause_ev *ev;
int ret, vdev_id;
u32 pause_id, action, vdev_map, peer_id, tid_map;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_TX_PAUSE_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
pause_id = __le32_to_cpu(ev->pause_id);
action = __le32_to_cpu(ev->action);
vdev_map = __le32_to_cpu(ev->vdev_map);
peer_id = __le32_to_cpu(ev->peer_id);
tid_map = __le32_to_cpu(ev->tid_map);
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv tx pause pause_id %u action %u vdev_map 0x%08x peer_id %u tid_map 0x%08x\n",
pause_id, action, vdev_map, peer_id, tid_map);
switch (pause_id) {
case WMI_TLV_TX_PAUSE_ID_MCC:
case WMI_TLV_TX_PAUSE_ID_P2P_CLI_NOA:
case WMI_TLV_TX_PAUSE_ID_P2P_GO_PS:
case WMI_TLV_TX_PAUSE_ID_AP_PS:
case WMI_TLV_TX_PAUSE_ID_IBSS_PS:
for (vdev_id = 0; vdev_map; vdev_id++) {
if (!(vdev_map & BIT(vdev_id)))
continue;
vdev_map &= ~BIT(vdev_id);
ath10k_mac_handle_tx_pause_vdev(ar, vdev_id, pause_id,
action);
}
break;
case WMI_TLV_TX_PAUSE_ID_AP_PEER_PS:
case WMI_TLV_TX_PAUSE_ID_AP_PEER_UAPSD:
case WMI_TLV_TX_PAUSE_ID_STA_ADD_BA:
case WMI_TLV_TX_PAUSE_ID_HOST:
ath10k_dbg(ar, ATH10K_DBG_MAC,
"mac ignoring unsupported tx pause id %d\n",
pause_id);
break;
default:
ath10k_dbg(ar, ATH10K_DBG_MAC,
"mac ignoring unknown tx pause vdev %d\n",
pause_id);
break;
}
kfree(tb);
return 0;
}
static void ath10k_wmi_tlv_op_rx(struct ath10k *ar, struct sk_buff *skb)
{
struct wmi_cmd_hdr *cmd_hdr;
enum wmi_tlv_event_id id;
bool consumed;
cmd_hdr = (struct wmi_cmd_hdr *)skb->data;
id = MS(__le32_to_cpu(cmd_hdr->cmd_id), WMI_CMD_HDR_CMD_ID);
if (skb_pull(skb, sizeof(struct wmi_cmd_hdr)) == NULL)
goto out;
trace_ath10k_wmi_event(ar, id, skb->data, skb->len);
consumed = ath10k_tm_event_wmi(ar, id, skb);
if (consumed && id != WMI_TLV_READY_EVENTID) {
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv testmode consumed 0x%x\n", id);
goto out;
}
switch (id) {
case WMI_TLV_MGMT_RX_EVENTID:
ath10k_wmi_event_mgmt_rx(ar, skb);
return;
case WMI_TLV_SCAN_EVENTID:
ath10k_wmi_event_scan(ar, skb);
break;
case WMI_TLV_CHAN_INFO_EVENTID:
ath10k_wmi_event_chan_info(ar, skb);
break;
case WMI_TLV_ECHO_EVENTID:
ath10k_wmi_event_echo(ar, skb);
break;
case WMI_TLV_DEBUG_MESG_EVENTID:
ath10k_wmi_event_debug_mesg(ar, skb);
break;
case WMI_TLV_UPDATE_STATS_EVENTID:
ath10k_wmi_event_update_stats(ar, skb);
break;
case WMI_TLV_VDEV_START_RESP_EVENTID:
ath10k_wmi_event_vdev_start_resp(ar, skb);
break;
case WMI_TLV_VDEV_STOPPED_EVENTID:
ath10k_wmi_event_vdev_stopped(ar, skb);
break;
case WMI_TLV_PEER_STA_KICKOUT_EVENTID:
ath10k_wmi_event_peer_sta_kickout(ar, skb);
break;
case WMI_TLV_HOST_SWBA_EVENTID:
ath10k_wmi_event_host_swba(ar, skb);
break;
case WMI_TLV_TBTTOFFSET_UPDATE_EVENTID:
ath10k_wmi_event_tbttoffset_update(ar, skb);
break;
case WMI_TLV_PHYERR_EVENTID:
ath10k_wmi_event_phyerr(ar, skb);
break;
case WMI_TLV_ROAM_EVENTID:
ath10k_wmi_event_roam(ar, skb);
break;
case WMI_TLV_PROFILE_MATCH:
ath10k_wmi_event_profile_match(ar, skb);
break;
case WMI_TLV_DEBUG_PRINT_EVENTID:
ath10k_wmi_event_debug_print(ar, skb);
break;
case WMI_TLV_PDEV_QVIT_EVENTID:
ath10k_wmi_event_pdev_qvit(ar, skb);
break;
case WMI_TLV_WLAN_PROFILE_DATA_EVENTID:
ath10k_wmi_event_wlan_profile_data(ar, skb);
break;
case WMI_TLV_RTT_MEASUREMENT_REPORT_EVENTID:
ath10k_wmi_event_rtt_measurement_report(ar, skb);
break;
case WMI_TLV_TSF_MEASUREMENT_REPORT_EVENTID:
ath10k_wmi_event_tsf_measurement_report(ar, skb);
break;
case WMI_TLV_RTT_ERROR_REPORT_EVENTID:
ath10k_wmi_event_rtt_error_report(ar, skb);
break;
case WMI_TLV_WOW_WAKEUP_HOST_EVENTID:
ath10k_wmi_event_wow_wakeup_host(ar, skb);
break;
case WMI_TLV_DCS_INTERFERENCE_EVENTID:
ath10k_wmi_event_dcs_interference(ar, skb);
break;
case WMI_TLV_PDEV_TPC_CONFIG_EVENTID:
ath10k_wmi_event_pdev_tpc_config(ar, skb);
break;
case WMI_TLV_PDEV_FTM_INTG_EVENTID:
ath10k_wmi_event_pdev_ftm_intg(ar, skb);
break;
case WMI_TLV_GTK_OFFLOAD_STATUS_EVENTID:
ath10k_wmi_event_gtk_offload_status(ar, skb);
break;
case WMI_TLV_GTK_REKEY_FAIL_EVENTID:
ath10k_wmi_event_gtk_rekey_fail(ar, skb);
break;
case WMI_TLV_TX_DELBA_COMPLETE_EVENTID:
ath10k_wmi_event_delba_complete(ar, skb);
break;
case WMI_TLV_TX_ADDBA_COMPLETE_EVENTID:
ath10k_wmi_event_addba_complete(ar, skb);
break;
case WMI_TLV_VDEV_INSTALL_KEY_COMPLETE_EVENTID:
ath10k_wmi_event_vdev_install_key_complete(ar, skb);
break;
case WMI_TLV_SERVICE_READY_EVENTID:
ath10k_wmi_event_service_ready(ar, skb);
return;
case WMI_TLV_READY_EVENTID:
ath10k_wmi_event_ready(ar, skb);
break;
case WMI_TLV_OFFLOAD_BCN_TX_STATUS_EVENTID:
ath10k_wmi_tlv_event_bcn_tx_status(ar, skb);
break;
case WMI_TLV_DIAG_DATA_CONTAINER_EVENTID:
ath10k_wmi_tlv_event_diag_data(ar, skb);
break;
case WMI_TLV_DIAG_EVENTID:
ath10k_wmi_tlv_event_diag(ar, skb);
break;
case WMI_TLV_P2P_NOA_EVENTID:
ath10k_wmi_tlv_event_p2p_noa(ar, skb);
break;
case WMI_TLV_TX_PAUSE_EVENTID:
ath10k_wmi_tlv_event_tx_pause(ar, skb);
break;
default:
ath10k_warn(ar, "Unknown eventid: %d\n", id);
break;
}
out:
dev_kfree_skb(skb);
}
static int ath10k_wmi_tlv_op_pull_scan_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_scan_ev_arg *arg)
{
const void **tb;
const struct wmi_scan_event *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_SCAN_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
arg->event_type = ev->event_type;
arg->reason = ev->reason;
arg->channel_freq = ev->channel_freq;
arg->scan_req_id = ev->scan_req_id;
arg->scan_id = ev->scan_id;
arg->vdev_id = ev->vdev_id;
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_op_pull_mgmt_rx_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_mgmt_rx_ev_arg *arg)
{
const void **tb;
const struct wmi_tlv_mgmt_rx_ev *ev;
const u8 *frame;
u32 msdu_len;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_MGMT_RX_HDR];
frame = tb[WMI_TLV_TAG_ARRAY_BYTE];
if (!ev || !frame) {
kfree(tb);
return -EPROTO;
}
arg->channel = ev->channel;
arg->buf_len = ev->buf_len;
arg->status = ev->status;
arg->snr = ev->snr;
arg->phy_mode = ev->phy_mode;
arg->rate = ev->rate;
msdu_len = __le32_to_cpu(arg->buf_len);
if (skb->len < (frame - skb->data) + msdu_len) {
kfree(tb);
return -EPROTO;
}
skb_trim(skb, 0);
skb_put(skb, frame - skb->data);
skb_pull(skb, frame - skb->data);
skb_put(skb, msdu_len);
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_op_pull_ch_info_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_ch_info_ev_arg *arg)
{
const void **tb;
const struct wmi_chan_info_event *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_CHAN_INFO_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
arg->err_code = ev->err_code;
arg->freq = ev->freq;
arg->cmd_flags = ev->cmd_flags;
arg->noise_floor = ev->noise_floor;
arg->rx_clear_count = ev->rx_clear_count;
arg->cycle_count = ev->cycle_count;
kfree(tb);
return 0;
}
static int
ath10k_wmi_tlv_op_pull_vdev_start_ev(struct ath10k *ar, struct sk_buff *skb,
struct wmi_vdev_start_ev_arg *arg)
{
const void **tb;
const struct wmi_vdev_start_response_event *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_VDEV_START_RESPONSE_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
skb_pull(skb, sizeof(*ev));
arg->vdev_id = ev->vdev_id;
arg->req_id = ev->req_id;
arg->resp_type = ev->resp_type;
arg->status = ev->status;
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_op_pull_peer_kick_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_peer_kick_ev_arg *arg)
{
const void **tb;
const struct wmi_peer_sta_kickout_event *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_PEER_STA_KICKOUT_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
arg->mac_addr = ev->peer_macaddr.addr;
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_swba_tim_parse(struct ath10k *ar, u16 tag, u16 len,
const void *ptr, void *data)
{
struct wmi_tlv_swba_parse *swba = data;
struct wmi_tim_info_arg *tim_info_arg;
const struct wmi_tim_info *tim_info_ev = ptr;
if (tag != WMI_TLV_TAG_STRUCT_TIM_INFO)
return -EPROTO;
if (swba->n_tim >= ARRAY_SIZE(swba->arg->tim_info))
return -ENOBUFS;
if (__le32_to_cpu(tim_info_ev->tim_len) >
sizeof(tim_info_ev->tim_bitmap)) {
ath10k_warn(ar, "refusing to parse invalid swba structure\n");
return -EPROTO;
}
tim_info_arg = &swba->arg->tim_info[swba->n_tim];
tim_info_arg->tim_len = tim_info_ev->tim_len;
tim_info_arg->tim_mcast = tim_info_ev->tim_mcast;
tim_info_arg->tim_bitmap = tim_info_ev->tim_bitmap;
tim_info_arg->tim_changed = tim_info_ev->tim_changed;
tim_info_arg->tim_num_ps_pending = tim_info_ev->tim_num_ps_pending;
swba->n_tim++;
return 0;
}
static int ath10k_wmi_tlv_swba_noa_parse(struct ath10k *ar, u16 tag, u16 len,
const void *ptr, void *data)
{
struct wmi_tlv_swba_parse *swba = data;
if (tag != WMI_TLV_TAG_STRUCT_P2P_NOA_INFO)
return -EPROTO;
if (swba->n_noa >= ARRAY_SIZE(swba->arg->noa_info))
return -ENOBUFS;
swba->arg->noa_info[swba->n_noa++] = ptr;
return 0;
}
static int ath10k_wmi_tlv_swba_parse(struct ath10k *ar, u16 tag, u16 len,
const void *ptr, void *data)
{
struct wmi_tlv_swba_parse *swba = data;
int ret;
switch (tag) {
case WMI_TLV_TAG_STRUCT_HOST_SWBA_EVENT:
swba->ev = ptr;
break;
case WMI_TLV_TAG_ARRAY_STRUCT:
if (!swba->tim_done) {
swba->tim_done = true;
ret = ath10k_wmi_tlv_iter(ar, ptr, len,
ath10k_wmi_tlv_swba_tim_parse,
swba);
if (ret)
return ret;
} else if (!swba->noa_done) {
swba->noa_done = true;
ret = ath10k_wmi_tlv_iter(ar, ptr, len,
ath10k_wmi_tlv_swba_noa_parse,
swba);
if (ret)
return ret;
}
break;
default:
break;
}
return 0;
}
static int ath10k_wmi_tlv_op_pull_swba_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_swba_ev_arg *arg)
{
struct wmi_tlv_swba_parse swba = { .arg = arg };
u32 map;
size_t n_vdevs;
int ret;
ret = ath10k_wmi_tlv_iter(ar, skb->data, skb->len,
ath10k_wmi_tlv_swba_parse, &swba);
if (ret) {
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
if (!swba.ev)
return -EPROTO;
arg->vdev_map = swba.ev->vdev_map;
for (map = __le32_to_cpu(arg->vdev_map), n_vdevs = 0; map; map >>= 1)
if (map & BIT(0))
n_vdevs++;
if (n_vdevs != swba.n_tim ||
n_vdevs != swba.n_noa)
return -EPROTO;
return 0;
}
static int ath10k_wmi_tlv_op_pull_phyerr_ev_hdr(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_phyerr_hdr_arg *arg)
{
const void **tb;
const struct wmi_tlv_phyerr_ev *ev;
const void *phyerrs;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_COMB_PHYERR_RX_HDR];
phyerrs = tb[WMI_TLV_TAG_ARRAY_BYTE];
if (!ev || !phyerrs) {
kfree(tb);
return -EPROTO;
}
arg->num_phyerrs = __le32_to_cpu(ev->num_phyerrs);
arg->tsf_l32 = __le32_to_cpu(ev->tsf_l32);
arg->tsf_u32 = __le32_to_cpu(ev->tsf_u32);
arg->buf_len = __le32_to_cpu(ev->buf_len);
arg->phyerrs = phyerrs;
kfree(tb);
return 0;
}
static int
ath10k_wmi_tlv_parse_mem_reqs(struct ath10k *ar, u16 tag, u16 len,
const void *ptr, void *data)
{
struct wmi_svc_rdy_ev_arg *arg = data;
int i;
if (tag != WMI_TLV_TAG_STRUCT_WLAN_HOST_MEM_REQ)
return -EPROTO;
for (i = 0; i < ARRAY_SIZE(arg->mem_reqs); i++) {
if (!arg->mem_reqs[i]) {
arg->mem_reqs[i] = ptr;
return 0;
}
}
return -ENOMEM;
}
static int ath10k_wmi_tlv_op_pull_svc_rdy_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_svc_rdy_ev_arg *arg)
{
const void **tb;
const struct hal_reg_capabilities *reg;
const struct wmi_tlv_svc_rdy_ev *ev;
const __le32 *svc_bmap;
const struct wlan_host_mem_req *mem_reqs;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_SERVICE_READY_EVENT];
reg = tb[WMI_TLV_TAG_STRUCT_HAL_REG_CAPABILITIES];
svc_bmap = tb[WMI_TLV_TAG_ARRAY_UINT32];
mem_reqs = tb[WMI_TLV_TAG_ARRAY_STRUCT];
if (!ev || !reg || !svc_bmap || !mem_reqs) {
kfree(tb);
return -EPROTO;
}
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv abi 0x%08x ?= 0x%08x, 0x%08x ?= 0x%08x, 0x%08x ?= 0x%08x, 0x%08x ?= 0x%08x, 0x%08x ?= 0x%08x\n",
__le32_to_cpu(ev->abi.abi_ver0), WMI_TLV_ABI_VER0,
__le32_to_cpu(ev->abi.abi_ver_ns0), WMI_TLV_ABI_VER_NS0,
__le32_to_cpu(ev->abi.abi_ver_ns1), WMI_TLV_ABI_VER_NS1,
__le32_to_cpu(ev->abi.abi_ver_ns2), WMI_TLV_ABI_VER_NS2,
__le32_to_cpu(ev->abi.abi_ver_ns3), WMI_TLV_ABI_VER_NS3);
if (__le32_to_cpu(ev->abi.abi_ver0) != WMI_TLV_ABI_VER0 ||
__le32_to_cpu(ev->abi.abi_ver_ns0) != WMI_TLV_ABI_VER_NS0 ||
__le32_to_cpu(ev->abi.abi_ver_ns1) != WMI_TLV_ABI_VER_NS1 ||
__le32_to_cpu(ev->abi.abi_ver_ns2) != WMI_TLV_ABI_VER_NS2 ||
__le32_to_cpu(ev->abi.abi_ver_ns3) != WMI_TLV_ABI_VER_NS3) {
kfree(tb);
return -ENOTSUPP;
}
arg->min_tx_power = ev->hw_min_tx_power;
arg->max_tx_power = ev->hw_max_tx_power;
arg->ht_cap = ev->ht_cap_info;
arg->vht_cap = ev->vht_cap_info;
arg->sw_ver0 = ev->abi.abi_ver0;
arg->sw_ver1 = ev->abi.abi_ver1;
arg->fw_build = ev->fw_build_vers;
arg->phy_capab = ev->phy_capability;
arg->num_rf_chains = ev->num_rf_chains;
arg->eeprom_rd = reg->eeprom_rd;
arg->num_mem_reqs = ev->num_mem_reqs;
arg->service_map = svc_bmap;
arg->service_map_len = ath10k_wmi_tlv_len(svc_bmap);
ret = ath10k_wmi_tlv_iter(ar, mem_reqs, ath10k_wmi_tlv_len(mem_reqs),
ath10k_wmi_tlv_parse_mem_reqs, arg);
if (ret) {
kfree(tb);
ath10k_warn(ar, "failed to parse mem_reqs tlv: %d\n", ret);
return ret;
}
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_op_pull_rdy_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_rdy_ev_arg *arg)
{
const void **tb;
const struct wmi_tlv_rdy_ev *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_READY_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
arg->sw_version = ev->abi.abi_ver0;
arg->abi_version = ev->abi.abi_ver1;
arg->status = ev->status;
arg->mac_addr = ev->mac_addr.addr;
kfree(tb);
return 0;
}
static void ath10k_wmi_tlv_pull_vdev_stats(const struct wmi_tlv_vdev_stats *src,
struct ath10k_fw_stats_vdev *dst)
{
int i;
dst->vdev_id = __le32_to_cpu(src->vdev_id);
dst->beacon_snr = __le32_to_cpu(src->beacon_snr);
dst->data_snr = __le32_to_cpu(src->data_snr);
dst->num_rx_frames = __le32_to_cpu(src->num_rx_frames);
dst->num_rts_fail = __le32_to_cpu(src->num_rts_fail);
dst->num_rts_success = __le32_to_cpu(src->num_rts_success);
dst->num_rx_err = __le32_to_cpu(src->num_rx_err);
dst->num_rx_discard = __le32_to_cpu(src->num_rx_discard);
dst->num_tx_not_acked = __le32_to_cpu(src->num_tx_not_acked);
for (i = 0; i < ARRAY_SIZE(src->num_tx_frames); i++)
dst->num_tx_frames[i] =
__le32_to_cpu(src->num_tx_frames[i]);
for (i = 0; i < ARRAY_SIZE(src->num_tx_frames_retries); i++)
dst->num_tx_frames_retries[i] =
__le32_to_cpu(src->num_tx_frames_retries[i]);
for (i = 0; i < ARRAY_SIZE(src->num_tx_frames_failures); i++)
dst->num_tx_frames_failures[i] =
__le32_to_cpu(src->num_tx_frames_failures[i]);
for (i = 0; i < ARRAY_SIZE(src->tx_rate_history); i++)
dst->tx_rate_history[i] =
__le32_to_cpu(src->tx_rate_history[i]);
for (i = 0; i < ARRAY_SIZE(src->beacon_rssi_history); i++)
dst->beacon_rssi_history[i] =
__le32_to_cpu(src->beacon_rssi_history[i]);
}
static int ath10k_wmi_tlv_op_pull_fw_stats(struct ath10k *ar,
struct sk_buff *skb,
struct ath10k_fw_stats *stats)
{
const void **tb;
const struct wmi_tlv_stats_ev *ev;
const void *data;
u32 num_pdev_stats;
u32 num_vdev_stats;
u32 num_peer_stats;
u32 num_bcnflt_stats;
u32 num_chan_stats;
size_t data_len;
int ret;
int i;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_STATS_EVENT];
data = tb[WMI_TLV_TAG_ARRAY_BYTE];
if (!ev || !data) {
kfree(tb);
return -EPROTO;
}
data_len = ath10k_wmi_tlv_len(data);
num_pdev_stats = __le32_to_cpu(ev->num_pdev_stats);
num_vdev_stats = __le32_to_cpu(ev->num_vdev_stats);
num_peer_stats = __le32_to_cpu(ev->num_peer_stats);
num_bcnflt_stats = __le32_to_cpu(ev->num_bcnflt_stats);
num_chan_stats = __le32_to_cpu(ev->num_chan_stats);
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv stats update pdev %i vdev %i peer %i bcnflt %i chan %i\n",
num_pdev_stats, num_vdev_stats, num_peer_stats,
num_bcnflt_stats, num_chan_stats);
for (i = 0; i < num_pdev_stats; i++) {
const struct wmi_pdev_stats *src;
struct ath10k_fw_stats_pdev *dst;
src = data;
if (data_len < sizeof(*src))
return -EPROTO;
data += sizeof(*src);
data_len -= sizeof(*src);
dst = kzalloc(sizeof(*dst), GFP_ATOMIC);
if (!dst)
continue;
ath10k_wmi_pull_pdev_stats_base(&src->base, dst);
ath10k_wmi_pull_pdev_stats_tx(&src->tx, dst);
ath10k_wmi_pull_pdev_stats_rx(&src->rx, dst);
list_add_tail(&dst->list, &stats->pdevs);
}
for (i = 0; i < num_vdev_stats; i++) {
const struct wmi_tlv_vdev_stats *src;
struct ath10k_fw_stats_vdev *dst;
src = data;
if (data_len < sizeof(*src))
return -EPROTO;
data += sizeof(*src);
data_len -= sizeof(*src);
dst = kzalloc(sizeof(*dst), GFP_ATOMIC);
if (!dst)
continue;
ath10k_wmi_tlv_pull_vdev_stats(src, dst);
list_add_tail(&dst->list, &stats->vdevs);
}
for (i = 0; i < num_peer_stats; i++) {
const struct wmi_10x_peer_stats *src;
struct ath10k_fw_stats_peer *dst;
src = data;
if (data_len < sizeof(*src))
return -EPROTO;
data += sizeof(*src);
data_len -= sizeof(*src);
dst = kzalloc(sizeof(*dst), GFP_ATOMIC);
if (!dst)
continue;
ath10k_wmi_pull_peer_stats(&src->old, dst);
dst->peer_rx_rate = __le32_to_cpu(src->peer_rx_rate);
list_add_tail(&dst->list, &stats->peers);
}
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_op_pull_roam_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_roam_ev_arg *arg)
{
const void **tb;
const struct wmi_tlv_roam_ev *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_ROAM_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
arg->vdev_id = ev->vdev_id;
arg->reason = ev->reason;
arg->rssi = ev->rssi;
kfree(tb);
return 0;
}
static int
ath10k_wmi_tlv_op_pull_wow_ev(struct ath10k *ar, struct sk_buff *skb,
struct wmi_wow_ev_arg *arg)
{
const void **tb;
const struct wmi_tlv_wow_event_info *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_WOW_EVENT_INFO];
if (!ev) {
kfree(tb);
return -EPROTO;
}
arg->vdev_id = __le32_to_cpu(ev->vdev_id);
arg->flag = __le32_to_cpu(ev->flag);
arg->wake_reason = __le32_to_cpu(ev->wake_reason);
arg->data_len = __le32_to_cpu(ev->data_len);
kfree(tb);
return 0;
}
static int ath10k_wmi_tlv_op_pull_echo_ev(struct ath10k *ar,
struct sk_buff *skb,
struct wmi_echo_ev_arg *arg)
{
const void **tb;
const struct wmi_echo_event *ev;
int ret;
tb = ath10k_wmi_tlv_parse_alloc(ar, skb->data, skb->len, GFP_ATOMIC);
if (IS_ERR(tb)) {
ret = PTR_ERR(tb);
ath10k_warn(ar, "failed to parse tlv: %d\n", ret);
return ret;
}
ev = tb[WMI_TLV_TAG_STRUCT_ECHO_EVENT];
if (!ev) {
kfree(tb);
return -EPROTO;
}
arg->value = ev->value;
kfree(tb);
return 0;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_pdev_suspend(struct ath10k *ar, u32 opt)
{
struct wmi_tlv_pdev_suspend *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PDEV_SUSPEND_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->opt = __cpu_to_le32(opt);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv pdev suspend\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_pdev_resume(struct ath10k *ar)
{
struct wmi_tlv_resume_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PDEV_RESUME_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->reserved = __cpu_to_le32(0);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv pdev resume\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_pdev_set_rd(struct ath10k *ar,
u16 rd, u16 rd2g, u16 rd5g,
u16 ctl2g, u16 ctl5g,
enum wmi_dfs_region dfs_reg)
{
struct wmi_tlv_pdev_set_rd_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PDEV_SET_REGDOMAIN_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->regd = __cpu_to_le32(rd);
cmd->regd_2ghz = __cpu_to_le32(rd2g);
cmd->regd_5ghz = __cpu_to_le32(rd5g);
cmd->conform_limit_2ghz = __cpu_to_le32(rd2g);
cmd->conform_limit_5ghz = __cpu_to_le32(rd5g);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv pdev set rd\n");
return skb;
}
static enum wmi_txbf_conf ath10k_wmi_tlv_txbf_conf_scheme(struct ath10k *ar)
{
return WMI_TXBF_CONF_AFTER_ASSOC;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_pdev_set_param(struct ath10k *ar, u32 param_id,
u32 param_value)
{
struct wmi_tlv_pdev_set_param_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PDEV_SET_PARAM_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->param_id = __cpu_to_le32(param_id);
cmd->param_value = __cpu_to_le32(param_value);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv pdev set param\n");
return skb;
}
static struct sk_buff *ath10k_wmi_tlv_op_gen_init(struct ath10k *ar)
{
struct sk_buff *skb;
struct wmi_tlv *tlv;
struct wmi_tlv_init_cmd *cmd;
struct wmi_tlv_resource_config *cfg;
struct wmi_host_mem_chunks *chunks;
size_t len, chunks_len;
void *ptr;
chunks_len = ar->wmi.num_mem_chunks * sizeof(struct host_memory_chunk);
len = (sizeof(*tlv) + sizeof(*cmd)) +
(sizeof(*tlv) + sizeof(*cfg)) +
(sizeof(*tlv) + chunks_len);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_INIT_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_RESOURCE_CONFIG);
tlv->len = __cpu_to_le16(sizeof(*cfg));
cfg = (void *)tlv->value;
ptr += sizeof(*tlv);
ptr += sizeof(*cfg);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(chunks_len);
chunks = (void *)tlv->value;
ptr += sizeof(*tlv);
ptr += chunks_len;
cmd->abi.abi_ver0 = __cpu_to_le32(WMI_TLV_ABI_VER0);
cmd->abi.abi_ver1 = __cpu_to_le32(WMI_TLV_ABI_VER1);
cmd->abi.abi_ver_ns0 = __cpu_to_le32(WMI_TLV_ABI_VER_NS0);
cmd->abi.abi_ver_ns1 = __cpu_to_le32(WMI_TLV_ABI_VER_NS1);
cmd->abi.abi_ver_ns2 = __cpu_to_le32(WMI_TLV_ABI_VER_NS2);
cmd->abi.abi_ver_ns3 = __cpu_to_le32(WMI_TLV_ABI_VER_NS3);
cmd->num_host_mem_chunks = __cpu_to_le32(ar->wmi.num_mem_chunks);
cfg->num_vdevs = __cpu_to_le32(TARGET_TLV_NUM_VDEVS);
cfg->num_peers = __cpu_to_le32(TARGET_TLV_NUM_PEERS);
if (test_bit(WMI_SERVICE_RX_FULL_REORDER, ar->wmi.svc_map)) {
cfg->num_offload_peers = __cpu_to_le32(TARGET_TLV_NUM_VDEVS);
cfg->num_offload_reorder_bufs = __cpu_to_le32(TARGET_TLV_NUM_VDEVS);
} else {
cfg->num_offload_peers = __cpu_to_le32(0);
cfg->num_offload_reorder_bufs = __cpu_to_le32(0);
}
cfg->num_peer_keys = __cpu_to_le32(2);
cfg->num_tids = __cpu_to_le32(TARGET_TLV_NUM_TIDS);
cfg->ast_skid_limit = __cpu_to_le32(0x10);
cfg->tx_chain_mask = __cpu_to_le32(0x7);
cfg->rx_chain_mask = __cpu_to_le32(0x7);
cfg->rx_timeout_pri[0] = __cpu_to_le32(0x64);
cfg->rx_timeout_pri[1] = __cpu_to_le32(0x64);
cfg->rx_timeout_pri[2] = __cpu_to_le32(0x64);
cfg->rx_timeout_pri[3] = __cpu_to_le32(0x28);
cfg->rx_decap_mode = __cpu_to_le32(ar->wmi.rx_decap_mode);
cfg->scan_max_pending_reqs = __cpu_to_le32(4);
cfg->bmiss_offload_max_vdev = __cpu_to_le32(TARGET_TLV_NUM_VDEVS);
cfg->roam_offload_max_vdev = __cpu_to_le32(TARGET_TLV_NUM_VDEVS);
cfg->roam_offload_max_ap_profiles = __cpu_to_le32(8);
cfg->num_mcast_groups = __cpu_to_le32(0);
cfg->num_mcast_table_elems = __cpu_to_le32(0);
cfg->mcast2ucast_mode = __cpu_to_le32(0);
cfg->tx_dbg_log_size = __cpu_to_le32(0x400);
cfg->num_wds_entries = __cpu_to_le32(0x20);
cfg->dma_burst_size = __cpu_to_le32(0);
cfg->mac_aggr_delim = __cpu_to_le32(0);
cfg->rx_skip_defrag_timeout_dup_detection_check = __cpu_to_le32(0);
cfg->vow_config = __cpu_to_le32(0);
cfg->gtk_offload_max_vdev = __cpu_to_le32(2);
cfg->num_msdu_desc = __cpu_to_le32(TARGET_TLV_NUM_MSDU_DESC);
cfg->max_frag_entries = __cpu_to_le32(2);
cfg->num_tdls_vdevs = __cpu_to_le32(TARGET_TLV_NUM_TDLS_VDEVS);
cfg->num_tdls_conn_table_entries = __cpu_to_le32(0x20);
cfg->beacon_tx_offload_max_vdev = __cpu_to_le32(2);
cfg->num_multicast_filter_entries = __cpu_to_le32(5);
cfg->num_wow_filters = __cpu_to_le32(ar->wow.max_num_patterns);
cfg->num_keep_alive_pattern = __cpu_to_le32(6);
cfg->keep_alive_pattern_size = __cpu_to_le32(0);
cfg->max_tdls_concurrent_sleep_sta = __cpu_to_le32(1);
cfg->max_tdls_concurrent_buffer_sta = __cpu_to_le32(1);
ath10k_wmi_put_host_mem_chunks(ar, chunks);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv init\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_start_scan(struct ath10k *ar,
const struct wmi_start_scan_arg *arg)
{
struct wmi_tlv_start_scan_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len, chan_len, ssid_len, bssid_len, ie_len;
__le32 *chans;
struct wmi_ssid *ssids;
struct wmi_mac_addr *addrs;
void *ptr;
int i, ret;
ret = ath10k_wmi_start_scan_verify(arg);
if (ret)
return ERR_PTR(ret);
chan_len = arg->n_channels * sizeof(__le32);
ssid_len = arg->n_ssids * sizeof(struct wmi_ssid);
bssid_len = arg->n_bssids * sizeof(struct wmi_mac_addr);
ie_len = roundup(arg->ie_len, 4);
len = (sizeof(*tlv) + sizeof(*cmd)) +
(arg->n_channels ? sizeof(*tlv) + chan_len : 0) +
(arg->n_ssids ? sizeof(*tlv) + ssid_len : 0) +
(arg->n_bssids ? sizeof(*tlv) + bssid_len : 0) +
(arg->ie_len ? sizeof(*tlv) + ie_len : 0);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_START_SCAN_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
ath10k_wmi_put_start_scan_common(&cmd->common, arg);
cmd->burst_duration_ms = __cpu_to_le32(arg->burst_duration_ms);
cmd->num_channels = __cpu_to_le32(arg->n_channels);
cmd->num_ssids = __cpu_to_le32(arg->n_ssids);
cmd->num_bssids = __cpu_to_le32(arg->n_bssids);
cmd->ie_len = __cpu_to_le32(arg->ie_len);
cmd->num_probes = __cpu_to_le32(3);
cmd->common.scan_ctrl_flags ^= __cpu_to_le32(WMI_SCAN_FILTER_PROBE_REQ);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_UINT32);
tlv->len = __cpu_to_le16(chan_len);
chans = (void *)tlv->value;
for (i = 0; i < arg->n_channels; i++)
chans[i] = __cpu_to_le32(arg->channels[i]);
ptr += sizeof(*tlv);
ptr += chan_len;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_FIXED_STRUCT);
tlv->len = __cpu_to_le16(ssid_len);
ssids = (void *)tlv->value;
for (i = 0; i < arg->n_ssids; i++) {
ssids[i].ssid_len = __cpu_to_le32(arg->ssids[i].len);
memcpy(ssids[i].ssid, arg->ssids[i].ssid, arg->ssids[i].len);
}
ptr += sizeof(*tlv);
ptr += ssid_len;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_FIXED_STRUCT);
tlv->len = __cpu_to_le16(bssid_len);
addrs = (void *)tlv->value;
for (i = 0; i < arg->n_bssids; i++)
ether_addr_copy(addrs[i].addr, arg->bssids[i].bssid);
ptr += sizeof(*tlv);
ptr += bssid_len;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_BYTE);
tlv->len = __cpu_to_le16(ie_len);
memcpy(tlv->value, arg->ie, arg->ie_len);
ptr += sizeof(*tlv);
ptr += ie_len;
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv start scan\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_stop_scan(struct ath10k *ar,
const struct wmi_stop_scan_arg *arg)
{
struct wmi_stop_scan_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
u32 scan_id;
u32 req_id;
if (arg->req_id > 0xFFF)
return ERR_PTR(-EINVAL);
if (arg->req_type == WMI_SCAN_STOP_ONE && arg->u.scan_id > 0xFFF)
return ERR_PTR(-EINVAL);
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
scan_id = arg->u.scan_id;
scan_id |= WMI_HOST_SCAN_REQ_ID_PREFIX;
req_id = arg->req_id;
req_id |= WMI_HOST_SCAN_REQUESTOR_ID_PREFIX;
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_STOP_SCAN_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->req_type = __cpu_to_le32(arg->req_type);
cmd->vdev_id = __cpu_to_le32(arg->u.vdev_id);
cmd->scan_id = __cpu_to_le32(scan_id);
cmd->scan_req_id = __cpu_to_le32(req_id);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv stop scan\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_create(struct ath10k *ar,
u32 vdev_id,
enum wmi_vdev_type vdev_type,
enum wmi_vdev_subtype vdev_subtype,
const u8 mac_addr[ETH_ALEN])
{
struct wmi_vdev_create_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_CREATE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->vdev_type = __cpu_to_le32(vdev_type);
cmd->vdev_subtype = __cpu_to_le32(vdev_subtype);
ether_addr_copy(cmd->vdev_macaddr.addr, mac_addr);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev create\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_delete(struct ath10k *ar, u32 vdev_id)
{
struct wmi_vdev_delete_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_DELETE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev delete\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_start(struct ath10k *ar,
const struct wmi_vdev_start_request_arg *arg,
bool restart)
{
struct wmi_tlv_vdev_start_cmd *cmd;
struct wmi_channel *ch;
struct wmi_p2p_noa_descriptor *noa;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
void *ptr;
u32 flags = 0;
if (WARN_ON(arg->hidden_ssid && !arg->ssid))
return ERR_PTR(-EINVAL);
if (WARN_ON(arg->ssid_len > sizeof(cmd->ssid.ssid)))
return ERR_PTR(-EINVAL);
len = (sizeof(*tlv) + sizeof(*cmd)) +
(sizeof(*tlv) + sizeof(*ch)) +
(sizeof(*tlv) + 0);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
if (arg->hidden_ssid)
flags |= WMI_VDEV_START_HIDDEN_SSID;
if (arg->pmf_enabled)
flags |= WMI_VDEV_START_PMF_ENABLED;
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_START_REQUEST_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(arg->vdev_id);
cmd->bcn_intval = __cpu_to_le32(arg->bcn_intval);
cmd->dtim_period = __cpu_to_le32(arg->dtim_period);
cmd->flags = __cpu_to_le32(flags);
cmd->bcn_tx_rate = __cpu_to_le32(arg->bcn_tx_rate);
cmd->bcn_tx_power = __cpu_to_le32(arg->bcn_tx_power);
cmd->disable_hw_ack = __cpu_to_le32(arg->disable_hw_ack);
if (arg->ssid) {
cmd->ssid.ssid_len = __cpu_to_le32(arg->ssid_len);
memcpy(cmd->ssid.ssid, arg->ssid, arg->ssid_len);
}
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_CHANNEL);
tlv->len = __cpu_to_le16(sizeof(*ch));
ch = (void *)tlv->value;
ath10k_wmi_put_wmi_channel(ch, &arg->channel);
ptr += sizeof(*tlv);
ptr += sizeof(*ch);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = 0;
noa = (void *)tlv->value;
ptr += sizeof(*tlv);
ptr += 0;
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev start\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_stop(struct ath10k *ar, u32 vdev_id)
{
struct wmi_vdev_stop_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_STOP_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev stop\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_up(struct ath10k *ar, u32 vdev_id, u32 aid,
const u8 *bssid)
{
struct wmi_vdev_up_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_UP_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->vdev_assoc_id = __cpu_to_le32(aid);
ether_addr_copy(cmd->vdev_bssid.addr, bssid);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev up\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_down(struct ath10k *ar, u32 vdev_id)
{
struct wmi_vdev_down_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_DOWN_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev down\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_set_param(struct ath10k *ar, u32 vdev_id,
u32 param_id, u32 param_value)
{
struct wmi_vdev_set_param_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_SET_PARAM_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->param_id = __cpu_to_le32(param_id);
cmd->param_value = __cpu_to_le32(param_value);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev set param\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_install_key(struct ath10k *ar,
const struct wmi_vdev_install_key_arg *arg)
{
struct wmi_vdev_install_key_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
void *ptr;
if (arg->key_cipher == WMI_CIPHER_NONE && arg->key_data != NULL)
return ERR_PTR(-EINVAL);
if (arg->key_cipher != WMI_CIPHER_NONE && arg->key_data == NULL)
return ERR_PTR(-EINVAL);
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) + roundup(arg->key_len, sizeof(__le32));
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_INSTALL_KEY_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(arg->vdev_id);
cmd->key_idx = __cpu_to_le32(arg->key_idx);
cmd->key_flags = __cpu_to_le32(arg->key_flags);
cmd->key_cipher = __cpu_to_le32(arg->key_cipher);
cmd->key_len = __cpu_to_le32(arg->key_len);
cmd->key_txmic_len = __cpu_to_le32(arg->key_txmic_len);
cmd->key_rxmic_len = __cpu_to_le32(arg->key_rxmic_len);
if (arg->macaddr)
ether_addr_copy(cmd->peer_macaddr.addr, arg->macaddr);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_BYTE);
tlv->len = __cpu_to_le16(roundup(arg->key_len, sizeof(__le32)));
if (arg->key_data)
memcpy(tlv->value, arg->key_data, arg->key_len);
ptr += sizeof(*tlv);
ptr += roundup(arg->key_len, sizeof(__le32));
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev install key\n");
return skb;
}
static void *ath10k_wmi_tlv_put_uapsd_ac(struct ath10k *ar, void *ptr,
const struct wmi_sta_uapsd_auto_trig_arg *arg)
{
struct wmi_sta_uapsd_auto_trig_param *ac;
struct wmi_tlv *tlv;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_STA_UAPSD_AUTO_TRIG_PARAM);
tlv->len = __cpu_to_le16(sizeof(*ac));
ac = (void *)tlv->value;
ac->wmm_ac = __cpu_to_le32(arg->wmm_ac);
ac->user_priority = __cpu_to_le32(arg->user_priority);
ac->service_interval = __cpu_to_le32(arg->service_interval);
ac->suspend_interval = __cpu_to_le32(arg->suspend_interval);
ac->delay_interval = __cpu_to_le32(arg->delay_interval);
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv vdev sta uapsd auto trigger ac %d prio %d svc int %d susp int %d delay int %d\n",
ac->wmm_ac, ac->user_priority, ac->service_interval,
ac->suspend_interval, ac->delay_interval);
return ptr + sizeof(*tlv) + sizeof(*ac);
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_sta_uapsd(struct ath10k *ar, u32 vdev_id,
const u8 peer_addr[ETH_ALEN],
const struct wmi_sta_uapsd_auto_trig_arg *args,
u32 num_ac)
{
struct wmi_sta_uapsd_auto_trig_cmd_fixed_param *cmd;
struct wmi_sta_uapsd_auto_trig_param *ac;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
size_t ac_tlv_len;
void *ptr;
int i;
ac_tlv_len = num_ac * (sizeof(*tlv) + sizeof(*ac));
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) + ac_tlv_len;
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_STA_UAPSD_AUTO_TRIG_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->num_ac = __cpu_to_le32(num_ac);
ether_addr_copy(cmd->peer_macaddr.addr, peer_addr);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(ac_tlv_len);
ac = (void *)tlv->value;
ptr += sizeof(*tlv);
for (i = 0; i < num_ac; i++)
ptr = ath10k_wmi_tlv_put_uapsd_ac(ar, ptr, &args[i]);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev sta uapsd auto trigger\n");
return skb;
}
static void *ath10k_wmi_tlv_put_wmm(void *ptr,
const struct wmi_wmm_params_arg *arg)
{
struct wmi_wmm_params *wmm;
struct wmi_tlv *tlv;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_WMM_PARAMS);
tlv->len = __cpu_to_le16(sizeof(*wmm));
wmm = (void *)tlv->value;
ath10k_wmi_set_wmm_param(wmm, arg);
return ptr + sizeof(*tlv) + sizeof(*wmm);
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_vdev_wmm_conf(struct ath10k *ar, u32 vdev_id,
const struct wmi_wmm_params_all_arg *arg)
{
struct wmi_tlv_vdev_set_wmm_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
void *ptr;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VDEV_SET_WMM_PARAMS_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
ath10k_wmi_set_wmm_param(&cmd->vdev_wmm_params[0].params, &arg->ac_be);
ath10k_wmi_set_wmm_param(&cmd->vdev_wmm_params[1].params, &arg->ac_bk);
ath10k_wmi_set_wmm_param(&cmd->vdev_wmm_params[2].params, &arg->ac_vi);
ath10k_wmi_set_wmm_param(&cmd->vdev_wmm_params[3].params, &arg->ac_vo);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv vdev wmm conf\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_sta_keepalive(struct ath10k *ar,
const struct wmi_sta_keepalive_arg *arg)
{
struct wmi_tlv_sta_keepalive_cmd *cmd;
struct wmi_sta_keepalive_arp_resp *arp;
struct sk_buff *skb;
struct wmi_tlv *tlv;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) + sizeof(*arp);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_STA_KEEPALIVE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(arg->vdev_id);
cmd->enabled = __cpu_to_le32(arg->enabled);
cmd->method = __cpu_to_le32(arg->method);
cmd->interval = __cpu_to_le32(arg->interval);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_STA_KEEPALVE_ARP_RESPONSE);
tlv->len = __cpu_to_le16(sizeof(*arp));
arp = (void *)tlv->value;
arp->src_ip4_addr = arg->src_ip4_addr;
arp->dest_ip4_addr = arg->dest_ip4_addr;
ether_addr_copy(arp->dest_mac_addr.addr, arg->dest_mac_addr);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv sta keepalive vdev %d enabled %d method %d inverval %d\n",
arg->vdev_id, arg->enabled, arg->method, arg->interval);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_peer_create(struct ath10k *ar, u32 vdev_id,
const u8 peer_addr[ETH_ALEN],
enum wmi_peer_type peer_type)
{
struct wmi_tlv_peer_create_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PEER_CREATE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->peer_type = __cpu_to_le32(peer_type);
ether_addr_copy(cmd->peer_addr.addr, peer_addr);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv peer create\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_peer_delete(struct ath10k *ar, u32 vdev_id,
const u8 peer_addr[ETH_ALEN])
{
struct wmi_peer_delete_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PEER_DELETE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
ether_addr_copy(cmd->peer_macaddr.addr, peer_addr);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv peer delete\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_peer_flush(struct ath10k *ar, u32 vdev_id,
const u8 peer_addr[ETH_ALEN], u32 tid_bitmap)
{
struct wmi_peer_flush_tids_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PEER_FLUSH_TIDS_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->peer_tid_bitmap = __cpu_to_le32(tid_bitmap);
ether_addr_copy(cmd->peer_macaddr.addr, peer_addr);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv peer flush\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_peer_set_param(struct ath10k *ar, u32 vdev_id,
const u8 *peer_addr,
enum wmi_peer_param param_id,
u32 param_value)
{
struct wmi_peer_set_param_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PEER_SET_PARAM_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->param_id = __cpu_to_le32(param_id);
cmd->param_value = __cpu_to_le32(param_value);
ether_addr_copy(cmd->peer_macaddr.addr, peer_addr);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv peer set param\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_peer_assoc(struct ath10k *ar,
const struct wmi_peer_assoc_complete_arg *arg)
{
struct wmi_tlv_peer_assoc_cmd *cmd;
struct wmi_vht_rate_set *vht_rate;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len, legacy_rate_len, ht_rate_len;
void *ptr;
if (arg->peer_mpdu_density > 16)
return ERR_PTR(-EINVAL);
if (arg->peer_legacy_rates.num_rates > MAX_SUPPORTED_RATES)
return ERR_PTR(-EINVAL);
if (arg->peer_ht_rates.num_rates > MAX_SUPPORTED_RATES)
return ERR_PTR(-EINVAL);
legacy_rate_len = roundup(arg->peer_legacy_rates.num_rates,
sizeof(__le32));
ht_rate_len = roundup(arg->peer_ht_rates.num_rates, sizeof(__le32));
len = (sizeof(*tlv) + sizeof(*cmd)) +
(sizeof(*tlv) + legacy_rate_len) +
(sizeof(*tlv) + ht_rate_len) +
(sizeof(*tlv) + sizeof(*vht_rate));
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PEER_ASSOC_COMPLETE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(arg->vdev_id);
cmd->new_assoc = __cpu_to_le32(arg->peer_reassoc ? 0 : 1);
cmd->assoc_id = __cpu_to_le32(arg->peer_aid);
cmd->flags = __cpu_to_le32(arg->peer_flags);
cmd->caps = __cpu_to_le32(arg->peer_caps);
cmd->listen_intval = __cpu_to_le32(arg->peer_listen_intval);
cmd->ht_caps = __cpu_to_le32(arg->peer_ht_caps);
cmd->max_mpdu = __cpu_to_le32(arg->peer_max_mpdu);
cmd->mpdu_density = __cpu_to_le32(arg->peer_mpdu_density);
cmd->rate_caps = __cpu_to_le32(arg->peer_rate_caps);
cmd->nss = __cpu_to_le32(arg->peer_num_spatial_streams);
cmd->vht_caps = __cpu_to_le32(arg->peer_vht_caps);
cmd->phy_mode = __cpu_to_le32(arg->peer_phymode);
cmd->num_legacy_rates = __cpu_to_le32(arg->peer_legacy_rates.num_rates);
cmd->num_ht_rates = __cpu_to_le32(arg->peer_ht_rates.num_rates);
ether_addr_copy(cmd->mac_addr.addr, arg->addr);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_BYTE);
tlv->len = __cpu_to_le16(legacy_rate_len);
memcpy(tlv->value, arg->peer_legacy_rates.rates,
arg->peer_legacy_rates.num_rates);
ptr += sizeof(*tlv);
ptr += legacy_rate_len;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_BYTE);
tlv->len = __cpu_to_le16(ht_rate_len);
memcpy(tlv->value, arg->peer_ht_rates.rates,
arg->peer_ht_rates.num_rates);
ptr += sizeof(*tlv);
ptr += ht_rate_len;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_VHT_RATE_SET);
tlv->len = __cpu_to_le16(sizeof(*vht_rate));
vht_rate = (void *)tlv->value;
vht_rate->rx_max_rate = __cpu_to_le32(arg->peer_vht_rates.rx_max_rate);
vht_rate->rx_mcs_set = __cpu_to_le32(arg->peer_vht_rates.rx_mcs_set);
vht_rate->tx_max_rate = __cpu_to_le32(arg->peer_vht_rates.tx_max_rate);
vht_rate->tx_mcs_set = __cpu_to_le32(arg->peer_vht_rates.tx_mcs_set);
ptr += sizeof(*tlv);
ptr += sizeof(*vht_rate);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv peer assoc\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_set_psmode(struct ath10k *ar, u32 vdev_id,
enum wmi_sta_ps_mode psmode)
{
struct wmi_sta_powersave_mode_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_STA_POWERSAVE_MODE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->sta_ps_mode = __cpu_to_le32(psmode);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv set psmode\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_set_sta_ps(struct ath10k *ar, u32 vdev_id,
enum wmi_sta_powersave_param param_id,
u32 param_value)
{
struct wmi_sta_powersave_param_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_STA_POWERSAVE_PARAM_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->param_id = __cpu_to_le32(param_id);
cmd->param_value = __cpu_to_le32(param_value);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv set sta ps\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_set_ap_ps(struct ath10k *ar, u32 vdev_id, const u8 *mac,
enum wmi_ap_ps_peer_param param_id, u32 value)
{
struct wmi_ap_ps_peer_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
if (!mac)
return ERR_PTR(-EINVAL);
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_AP_PS_PEER_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->param_id = __cpu_to_le32(param_id);
cmd->param_value = __cpu_to_le32(value);
ether_addr_copy(cmd->peer_macaddr.addr, mac);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv ap ps param\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_scan_chan_list(struct ath10k *ar,
const struct wmi_scan_chan_list_arg *arg)
{
struct wmi_tlv_scan_chan_list_cmd *cmd;
struct wmi_channel *ci;
struct wmi_channel_arg *ch;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t chans_len, len;
int i;
void *ptr, *chans;
chans_len = arg->n_channels * (sizeof(*tlv) + sizeof(*ci));
len = (sizeof(*tlv) + sizeof(*cmd)) +
(sizeof(*tlv) + chans_len);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_SCAN_CHAN_LIST_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->num_scan_chans = __cpu_to_le32(arg->n_channels);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(chans_len);
chans = (void *)tlv->value;
for (i = 0; i < arg->n_channels; i++) {
ch = &arg->channels[i];
tlv = chans;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_CHANNEL);
tlv->len = __cpu_to_le16(sizeof(*ci));
ci = (void *)tlv->value;
ath10k_wmi_put_wmi_channel(ci, ch);
chans += sizeof(*tlv);
chans += sizeof(*ci);
}
ptr += sizeof(*tlv);
ptr += chans_len;
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv scan chan list\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_beacon_dma(struct ath10k *ar, u32 vdev_id,
const void *bcn, size_t bcn_len,
u32 bcn_paddr, bool dtim_zero,
bool deliver_cab)
{
struct wmi_bcn_tx_ref_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
struct ieee80211_hdr *hdr;
u16 fc;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
hdr = (struct ieee80211_hdr *)bcn;
fc = le16_to_cpu(hdr->frame_control);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_BCN_SEND_FROM_HOST_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->data_len = __cpu_to_le32(bcn_len);
cmd->data_ptr = __cpu_to_le32(bcn_paddr);
cmd->msdu_id = 0;
cmd->frame_control = __cpu_to_le32(fc);
cmd->flags = 0;
if (dtim_zero)
cmd->flags |= __cpu_to_le32(WMI_BCN_TX_REF_FLAG_DTIM_ZERO);
if (deliver_cab)
cmd->flags |= __cpu_to_le32(WMI_BCN_TX_REF_FLAG_DELIVER_CAB);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv beacon dma\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_pdev_set_wmm(struct ath10k *ar,
const struct wmi_wmm_params_all_arg *arg)
{
struct wmi_tlv_pdev_set_wmm_cmd *cmd;
struct wmi_wmm_params *wmm;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
void *ptr;
len = (sizeof(*tlv) + sizeof(*cmd)) +
(4 * (sizeof(*tlv) + sizeof(*wmm)));
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PDEV_SET_WMM_PARAMS_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
ptr = ath10k_wmi_tlv_put_wmm(ptr, &arg->ac_be);
ptr = ath10k_wmi_tlv_put_wmm(ptr, &arg->ac_bk);
ptr = ath10k_wmi_tlv_put_wmm(ptr, &arg->ac_vi);
ptr = ath10k_wmi_tlv_put_wmm(ptr, &arg->ac_vo);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv pdev set wmm\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_request_stats(struct ath10k *ar, u32 stats_mask)
{
struct wmi_request_stats_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_REQUEST_STATS_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->stats_id = __cpu_to_le32(stats_mask);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv request stats\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_force_fw_hang(struct ath10k *ar,
enum wmi_force_fw_hang_type type,
u32 delay_ms)
{
struct wmi_force_fw_hang_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
skb = ath10k_wmi_alloc_skb(ar, sizeof(*tlv) + sizeof(*cmd));
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (void *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_FORCE_FW_HANG_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->type = __cpu_to_le32(type);
cmd->delay_ms = __cpu_to_le32(delay_ms);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv force fw hang\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_dbglog_cfg(struct ath10k *ar, u64 module_enable,
u32 log_level) {
struct wmi_tlv_dbglog_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len, bmap_len;
u32 value;
void *ptr;
if (module_enable) {
value = WMI_TLV_DBGLOG_LOG_LEVEL_VALUE(
module_enable,
WMI_TLV_DBGLOG_LOG_LEVEL_VERBOSE);
} else {
value = WMI_TLV_DBGLOG_LOG_LEVEL_VALUE(
WMI_TLV_DBGLOG_ALL_MODULES,
WMI_TLV_DBGLOG_LOG_LEVEL_WARN);
}
bmap_len = 0;
len = sizeof(*tlv) + sizeof(*cmd) + sizeof(*tlv) + bmap_len;
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_DEBUG_LOG_CONFIG_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->param = __cpu_to_le32(WMI_TLV_DBGLOG_PARAM_LOG_LEVEL);
cmd->value = __cpu_to_le32(value);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_UINT32);
tlv->len = __cpu_to_le16(bmap_len);
ptr += sizeof(*tlv);
ptr += sizeof(bmap_len);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv dbglog value 0x%08x\n", value);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_pktlog_enable(struct ath10k *ar, u32 filter)
{
struct wmi_tlv_pktlog_enable *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PDEV_PKTLOG_ENABLE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->filter = __cpu_to_le32(filter);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv pktlog enable filter 0x%08x\n",
filter);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_pktlog_disable(struct ath10k *ar)
{
struct wmi_tlv_pktlog_disable *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PDEV_PKTLOG_DISABLE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv pktlog disable\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_bcn_tmpl(struct ath10k *ar, u32 vdev_id,
u32 tim_ie_offset, struct sk_buff *bcn,
u32 prb_caps, u32 prb_erp, void *prb_ies,
size_t prb_ies_len)
{
struct wmi_tlv_bcn_tmpl_cmd *cmd;
struct wmi_tlv_bcn_prb_info *info;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
if (WARN_ON(prb_ies_len > 0 && !prb_ies))
return ERR_PTR(-EINVAL);
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) + sizeof(*info) + prb_ies_len +
sizeof(*tlv) + roundup(bcn->len, 4);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_BCN_TMPL_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->tim_ie_offset = __cpu_to_le32(tim_ie_offset);
cmd->buf_len = __cpu_to_le32(bcn->len);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_BCN_PRB_INFO);
tlv->len = __cpu_to_le16(sizeof(*info) + prb_ies_len);
info = (void *)tlv->value;
info->caps = __cpu_to_le32(prb_caps);
info->erp = __cpu_to_le32(prb_erp);
memcpy(info->ies, prb_ies, prb_ies_len);
ptr += sizeof(*tlv);
ptr += sizeof(*info);
ptr += prb_ies_len;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_BYTE);
tlv->len = __cpu_to_le16(roundup(bcn->len, 4));
memcpy(tlv->value, bcn->data, bcn->len);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv bcn tmpl vdev_id %i\n",
vdev_id);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_prb_tmpl(struct ath10k *ar, u32 vdev_id,
struct sk_buff *prb)
{
struct wmi_tlv_prb_tmpl_cmd *cmd;
struct wmi_tlv_bcn_prb_info *info;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) + sizeof(*info) +
sizeof(*tlv) + roundup(prb->len, 4);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_PRB_TMPL_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->buf_len = __cpu_to_le32(prb->len);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_BCN_PRB_INFO);
tlv->len = __cpu_to_le16(sizeof(*info));
info = (void *)tlv->value;
info->caps = 0;
info->erp = 0;
ptr += sizeof(*tlv);
ptr += sizeof(*info);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_BYTE);
tlv->len = __cpu_to_le16(roundup(prb->len, 4));
memcpy(tlv->value, prb->data, prb->len);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv prb tmpl vdev_id %i\n",
vdev_id);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_p2p_go_bcn_ie(struct ath10k *ar, u32 vdev_id,
const u8 *p2p_ie)
{
struct wmi_tlv_p2p_go_bcn_ie *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) + roundup(p2p_ie[1] + 2, 4);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_P2P_GO_SET_BEACON_IE);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->ie_len = __cpu_to_le32(p2p_ie[1] + 2);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_BYTE);
tlv->len = __cpu_to_le16(roundup(p2p_ie[1] + 2, 4));
memcpy(tlv->value, p2p_ie, p2p_ie[1] + 2);
ptr += sizeof(*tlv);
ptr += roundup(p2p_ie[1] + 2, 4);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv p2p go bcn ie for vdev %i\n",
vdev_id);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_update_fw_tdls_state(struct ath10k *ar, u32 vdev_id,
enum wmi_tdls_state state)
{
struct wmi_tdls_set_state_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
u32 options = 0;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_TDLS_SET_STATE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->state = __cpu_to_le32(state);
cmd->notification_interval_ms = __cpu_to_le32(5000);
cmd->tx_discovery_threshold = __cpu_to_le32(100);
cmd->tx_teardown_threshold = __cpu_to_le32(5);
cmd->rssi_teardown_threshold = __cpu_to_le32(-75);
cmd->rssi_delta = __cpu_to_le32(-20);
cmd->tdls_options = __cpu_to_le32(options);
cmd->tdls_peer_traffic_ind_window = __cpu_to_le32(2);
cmd->tdls_peer_traffic_response_timeout_ms = __cpu_to_le32(5000);
cmd->tdls_puapsd_mask = __cpu_to_le32(0xf);
cmd->tdls_puapsd_inactivity_time_ms = __cpu_to_le32(0);
cmd->tdls_puapsd_rx_frame_threshold = __cpu_to_le32(10);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv update fw tdls state %d for vdev %i\n",
state, vdev_id);
return skb;
}
static u32 ath10k_wmi_tlv_prepare_peer_qos(u8 uapsd_queues, u8 sp)
{
u32 peer_qos = 0;
if (uapsd_queues & IEEE80211_WMM_IE_STA_QOSINFO_AC_VO)
peer_qos |= WMI_TLV_TDLS_PEER_QOS_AC_VO;
if (uapsd_queues & IEEE80211_WMM_IE_STA_QOSINFO_AC_VI)
peer_qos |= WMI_TLV_TDLS_PEER_QOS_AC_VI;
if (uapsd_queues & IEEE80211_WMM_IE_STA_QOSINFO_AC_BK)
peer_qos |= WMI_TLV_TDLS_PEER_QOS_AC_BK;
if (uapsd_queues & IEEE80211_WMM_IE_STA_QOSINFO_AC_BE)
peer_qos |= WMI_TLV_TDLS_PEER_QOS_AC_BE;
peer_qos |= SM(sp, WMI_TLV_TDLS_PEER_SP);
return peer_qos;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_tdls_peer_update(struct ath10k *ar,
const struct wmi_tdls_peer_update_cmd_arg *arg,
const struct wmi_tdls_peer_capab_arg *cap,
const struct wmi_channel_arg *chan_arg)
{
struct wmi_tdls_peer_update_cmd *cmd;
struct wmi_tdls_peer_capab *peer_cap;
struct wmi_channel *chan;
struct wmi_tlv *tlv;
struct sk_buff *skb;
u32 peer_qos;
void *ptr;
int len;
int i;
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) + sizeof(*peer_cap) +
sizeof(*tlv) + cap->peer_chan_len * sizeof(*chan);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_TDLS_PEER_UPDATE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(arg->vdev_id);
ether_addr_copy(cmd->peer_macaddr.addr, arg->addr);
cmd->peer_state = __cpu_to_le32(arg->peer_state);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_TDLS_PEER_CAPABILITIES);
tlv->len = __cpu_to_le16(sizeof(*peer_cap));
peer_cap = (void *)tlv->value;
peer_qos = ath10k_wmi_tlv_prepare_peer_qos(cap->peer_uapsd_queues,
cap->peer_max_sp);
peer_cap->peer_qos = __cpu_to_le32(peer_qos);
peer_cap->buff_sta_support = __cpu_to_le32(cap->buff_sta_support);
peer_cap->off_chan_support = __cpu_to_le32(cap->off_chan_support);
peer_cap->peer_curr_operclass = __cpu_to_le32(cap->peer_curr_operclass);
peer_cap->self_curr_operclass = __cpu_to_le32(cap->self_curr_operclass);
peer_cap->peer_chan_len = __cpu_to_le32(cap->peer_chan_len);
peer_cap->peer_operclass_len = __cpu_to_le32(cap->peer_operclass_len);
for (i = 0; i < WMI_TDLS_MAX_SUPP_OPER_CLASSES; i++)
peer_cap->peer_operclass[i] = cap->peer_operclass[i];
peer_cap->is_peer_responder = __cpu_to_le32(cap->is_peer_responder);
peer_cap->pref_offchan_num = __cpu_to_le32(cap->pref_offchan_num);
peer_cap->pref_offchan_bw = __cpu_to_le32(cap->pref_offchan_bw);
ptr += sizeof(*tlv);
ptr += sizeof(*peer_cap);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(cap->peer_chan_len * sizeof(*chan));
ptr += sizeof(*tlv);
for (i = 0; i < cap->peer_chan_len; i++) {
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_CHANNEL);
tlv->len = __cpu_to_le16(sizeof(*chan));
chan = (void *)tlv->value;
ath10k_wmi_put_wmi_channel(chan, &chan_arg[i]);
ptr += sizeof(*tlv);
ptr += sizeof(*chan);
}
ath10k_dbg(ar, ATH10K_DBG_WMI,
"wmi tlv tdls peer update vdev %i state %d n_chans %u\n",
arg->vdev_id, arg->peer_state, cap->peer_chan_len);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_wow_enable(struct ath10k *ar)
{
struct wmi_tlv_wow_enable_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (struct wmi_tlv *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_WOW_ENABLE_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->enable = __cpu_to_le32(1);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv wow enable\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_wow_add_wakeup_event(struct ath10k *ar,
u32 vdev_id,
enum wmi_wow_wakeup_event event,
u32 enable)
{
struct wmi_tlv_wow_add_del_event_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (struct wmi_tlv *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_WOW_ADD_DEL_EVT_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->is_add = __cpu_to_le32(enable);
cmd->event_bitmap = __cpu_to_le32(1 << event);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv wow add wakeup event %s enable %d vdev_id %d\n",
wow_wakeup_event(event), enable, vdev_id);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_gen_wow_host_wakeup_ind(struct ath10k *ar)
{
struct wmi_tlv_wow_host_wakeup_ind *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (struct wmi_tlv *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_WOW_HOSTWAKEUP_FROM_SLEEP_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv wow host wakeup ind\n");
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_wow_add_pattern(struct ath10k *ar, u32 vdev_id,
u32 pattern_id, const u8 *pattern,
const u8 *bitmask, int pattern_len,
int pattern_offset)
{
struct wmi_tlv_wow_add_pattern_cmd *cmd;
struct wmi_tlv_wow_bitmap_pattern *bitmap;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd) +
sizeof(*tlv) +
sizeof(*tlv) + sizeof(*bitmap) +
sizeof(*tlv) +
sizeof(*tlv) +
sizeof(*tlv) +
sizeof(*tlv) +
sizeof(*tlv) + sizeof(u32);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_WOW_ADD_PATTERN_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->pattern_id = __cpu_to_le32(pattern_id);
cmd->pattern_type = __cpu_to_le32(WOW_BITMAP_PATTERN);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(sizeof(*tlv) + sizeof(*bitmap));
ptr += sizeof(*tlv);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_WOW_BITMAP_PATTERN_T);
tlv->len = __cpu_to_le16(sizeof(*bitmap));
bitmap = (void *)tlv->value;
memcpy(bitmap->patternbuf, pattern, pattern_len);
memcpy(bitmap->bitmaskbuf, bitmask, pattern_len);
bitmap->pattern_offset = __cpu_to_le32(pattern_offset);
bitmap->pattern_len = __cpu_to_le32(pattern_len);
bitmap->bitmask_len = __cpu_to_le32(pattern_len);
bitmap->pattern_id = __cpu_to_le32(pattern_id);
ptr += sizeof(*tlv);
ptr += sizeof(*bitmap);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(0);
ptr += sizeof(*tlv);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(0);
ptr += sizeof(*tlv);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_STRUCT);
tlv->len = __cpu_to_le16(0);
ptr += sizeof(*tlv);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_UINT32);
tlv->len = __cpu_to_le16(0);
ptr += sizeof(*tlv);
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_ARRAY_UINT32);
tlv->len = __cpu_to_le16(sizeof(u32));
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv wow add pattern vdev_id %d pattern_id %d, pattern_offset %d\n",
vdev_id, pattern_id, pattern_offset);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_wow_del_pattern(struct ath10k *ar, u32 vdev_id,
u32 pattern_id)
{
struct wmi_tlv_wow_del_pattern_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
tlv = (struct wmi_tlv *)skb->data;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_WOW_DEL_PATTERN_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->vdev_id = __cpu_to_le32(vdev_id);
cmd->pattern_id = __cpu_to_le32(pattern_id);
cmd->pattern_type = __cpu_to_le32(WOW_BITMAP_PATTERN);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv wow del pattern vdev_id %d pattern_id %d\n",
vdev_id, pattern_id);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_adaptive_qcs(struct ath10k *ar, bool enable)
{
struct wmi_tlv_adaptive_qcs *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_RESMGR_ADAPTIVE_OCS_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->enable = __cpu_to_le32(enable ? 1 : 0);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv adaptive qcs %d\n", enable);
return skb;
}
static struct sk_buff *
ath10k_wmi_tlv_op_gen_echo(struct ath10k *ar, u32 value)
{
struct wmi_echo_cmd *cmd;
struct wmi_tlv *tlv;
struct sk_buff *skb;
void *ptr;
size_t len;
len = sizeof(*tlv) + sizeof(*cmd);
skb = ath10k_wmi_alloc_skb(ar, len);
if (!skb)
return ERR_PTR(-ENOMEM);
ptr = (void *)skb->data;
tlv = ptr;
tlv->tag = __cpu_to_le16(WMI_TLV_TAG_STRUCT_ECHO_CMD);
tlv->len = __cpu_to_le16(sizeof(*cmd));
cmd = (void *)tlv->value;
cmd->value = cpu_to_le32(value);
ptr += sizeof(*tlv);
ptr += sizeof(*cmd);
ath10k_dbg(ar, ATH10K_DBG_WMI, "wmi tlv echo value 0x%08x\n", value);
return skb;
}
void ath10k_wmi_tlv_attach(struct ath10k *ar)
{
ar->wmi.cmd = &wmi_tlv_cmd_map;
ar->wmi.vdev_param = &wmi_tlv_vdev_param_map;
ar->wmi.pdev_param = &wmi_tlv_pdev_param_map;
ar->wmi.ops = &wmi_tlv_ops;
ar->wmi.peer_flags = &wmi_tlv_peer_flags_map;
}
