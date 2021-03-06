static void
mwifiex_wmm_ac_debug_print(const struct ieee_types_wmm_ac_parameters *ac_param)
{
const char *ac_str[] = { "BK", "BE", "VI", "VO" };
pr_debug("info: WMM AC_%s: ACI=%d, ACM=%d, Aifsn=%d, "
"EcwMin=%d, EcwMax=%d, TxopLimit=%d\n",
ac_str[wmm_aci_to_qidx_map[(ac_param->aci_aifsn_bitmap
& MWIFIEX_ACI) >> 5]],
(ac_param->aci_aifsn_bitmap & MWIFIEX_ACI) >> 5,
(ac_param->aci_aifsn_bitmap & MWIFIEX_ACM) >> 4,
ac_param->aci_aifsn_bitmap & MWIFIEX_AIFSN,
ac_param->ecw_bitmap & MWIFIEX_ECW_MIN,
(ac_param->ecw_bitmap & MWIFIEX_ECW_MAX) >> 4,
le16_to_cpu(ac_param->tx_op_limit));
}
static struct mwifiex_ra_list_tbl *
mwifiex_wmm_allocate_ralist_node(struct mwifiex_adapter *adapter, u8 *ra)
{
struct mwifiex_ra_list_tbl *ra_list;
ra_list = kzalloc(sizeof(struct mwifiex_ra_list_tbl), GFP_ATOMIC);
if (!ra_list) {
dev_err(adapter->dev, "%s: failed to alloc ra_list\n",
__func__);
return NULL;
}
INIT_LIST_HEAD(&ra_list->list);
skb_queue_head_init(&ra_list->skb_head);
memcpy(ra_list->ra, ra, ETH_ALEN);
ra_list->total_pkts_size = 0;
dev_dbg(adapter->dev, "info: allocated ra_list %p\n", ra_list);
return ra_list;
}
void
mwifiex_ralist_add(struct mwifiex_private *priv, u8 *ra)
{
int i;
struct mwifiex_ra_list_tbl *ra_list;
struct mwifiex_adapter *adapter = priv->adapter;
for (i = 0; i < MAX_NUM_TID; ++i) {
ra_list = mwifiex_wmm_allocate_ralist_node(adapter, ra);
dev_dbg(adapter->dev, "info: created ra_list %p\n", ra_list);
if (!ra_list)
break;
if (!mwifiex_queuing_ra_based(priv))
ra_list->is_11n_enabled = IS_11N_ENABLED(priv);
else
ra_list->is_11n_enabled = false;
dev_dbg(adapter->dev, "data: ralist %p: is_11n_enabled=%d\n",
ra_list, ra_list->is_11n_enabled);
list_add_tail(&ra_list->list,
&priv->wmm.tid_tbl_ptr[i].ra_list);
if (!priv->wmm.tid_tbl_ptr[i].ra_list_curr)
priv->wmm.tid_tbl_ptr[i].ra_list_curr = ra_list;
}
}
static void mwifiex_wmm_default_queue_priorities(struct mwifiex_private *priv)
{
priv->wmm.queue_priority[0] = WMM_AC_VO;
priv->wmm.queue_priority[1] = WMM_AC_VI;
priv->wmm.queue_priority[2] = WMM_AC_BE;
priv->wmm.queue_priority[3] = WMM_AC_BK;
}
static void
mwifiex_wmm_queue_priorities_tid(struct mwifiex_wmm_desc *wmm)
{
u8 *queue_priority = wmm->queue_priority;
int i;
for (i = 0; i < 4; ++i) {
tos_to_tid[7 - (i * 2)] = ac_to_tid[queue_priority[i]][1];
tos_to_tid[6 - (i * 2)] = ac_to_tid[queue_priority[i]][0];
}
for (i = 0; i < MAX_NUM_TID; ++i)
tos_to_tid_inv[tos_to_tid[i]] = (u8)i;
atomic_set(&wmm->highest_queued_prio, HIGH_PRIO_TID);
}
void
mwifiex_wmm_setup_queue_priorities(struct mwifiex_private *priv,
struct ieee_types_wmm_parameter *wmm_ie)
{
u16 cw_min, avg_back_off, tmp[4];
u32 i, j, num_ac;
u8 ac_idx;
if (!wmm_ie || !priv->wmm_enabled) {
mwifiex_wmm_default_queue_priorities(priv);
return;
}
dev_dbg(priv->adapter->dev, "info: WMM Parameter IE: version=%d, "
"qos_info Parameter Set Count=%d, Reserved=%#x\n",
wmm_ie->vend_hdr.version, wmm_ie->qos_info_bitmap &
IEEE80211_WMM_IE_AP_QOSINFO_PARAM_SET_CNT_MASK,
wmm_ie->reserved);
for (num_ac = 0; num_ac < ARRAY_SIZE(wmm_ie->ac_params); num_ac++) {
cw_min = (1 << (wmm_ie->ac_params[num_ac].ecw_bitmap &
MWIFIEX_ECW_MIN)) - 1;
avg_back_off = (cw_min >> 1) +
(wmm_ie->ac_params[num_ac].aci_aifsn_bitmap &
MWIFIEX_AIFSN);
ac_idx = wmm_aci_to_qidx_map[(wmm_ie->ac_params[num_ac].
aci_aifsn_bitmap &
MWIFIEX_ACI) >> 5];
priv->wmm.queue_priority[ac_idx] = ac_idx;
tmp[ac_idx] = avg_back_off;
dev_dbg(priv->adapter->dev, "info: WMM: CWmax=%d CWmin=%d Avg Back-off=%d\n",
(1 << ((wmm_ie->ac_params[num_ac].ecw_bitmap &
MWIFIEX_ECW_MAX) >> 4)) - 1,
cw_min, avg_back_off);
mwifiex_wmm_ac_debug_print(&wmm_ie->ac_params[num_ac]);
}
for (i = 0; i < num_ac; i++) {
for (j = 1; j < num_ac - i; j++) {
if (tmp[j - 1] > tmp[j]) {
swap(tmp[j - 1], tmp[j]);
swap(priv->wmm.queue_priority[j - 1],
priv->wmm.queue_priority[j]);
} else if (tmp[j - 1] == tmp[j]) {
if (priv->wmm.queue_priority[j - 1]
< priv->wmm.queue_priority[j])
swap(priv->wmm.queue_priority[j - 1],
priv->wmm.queue_priority[j]);
}
}
}
mwifiex_wmm_queue_priorities_tid(&priv->wmm);
}
static enum mwifiex_wmm_ac_e
mwifiex_wmm_eval_downgrade_ac(struct mwifiex_private *priv,
enum mwifiex_wmm_ac_e eval_ac)
{
int down_ac;
enum mwifiex_wmm_ac_e ret_ac;
struct mwifiex_wmm_ac_status *ac_status;
ac_status = &priv->wmm.ac_status[eval_ac];
if (!ac_status->disabled)
return eval_ac;
ret_ac = WMM_AC_BK;
for (down_ac = WMM_AC_BK; down_ac < eval_ac; down_ac++) {
ac_status = &priv->wmm.ac_status[down_ac];
if (!ac_status->disabled && !ac_status->flow_required)
ret_ac = (enum mwifiex_wmm_ac_e) down_ac;
}
return ret_ac;
}
void
mwifiex_wmm_setup_ac_downgrade(struct mwifiex_private *priv)
{
int ac_val;
dev_dbg(priv->adapter->dev, "info: WMM: AC Priorities:"
"BK(0), BE(1), VI(2), VO(3)\n");
if (!priv->wmm_enabled) {
for (ac_val = WMM_AC_BK; ac_val <= WMM_AC_VO; ac_val++)
priv->wmm.ac_down_graded_vals[ac_val] =
(enum mwifiex_wmm_ac_e) ac_val;
} else {
for (ac_val = WMM_AC_BK; ac_val <= WMM_AC_VO; ac_val++) {
priv->wmm.ac_down_graded_vals[ac_val]
= mwifiex_wmm_eval_downgrade_ac(priv,
(enum mwifiex_wmm_ac_e) ac_val);
dev_dbg(priv->adapter->dev, "info: WMM: AC PRIO %d maps to %d\n",
ac_val, priv->wmm.ac_down_graded_vals[ac_val]);
}
}
}
static enum mwifiex_wmm_ac_e
mwifiex_wmm_convert_tos_to_ac(struct mwifiex_adapter *adapter, u32 tos)
{
const enum mwifiex_wmm_ac_e tos_to_ac[] = { WMM_AC_BE,
WMM_AC_BK,
WMM_AC_BK,
WMM_AC_BE,
WMM_AC_VI,
WMM_AC_VI,
WMM_AC_VO,
WMM_AC_VO
};
if (tos >= ARRAY_SIZE(tos_to_ac))
return WMM_AC_BE;
return tos_to_ac[tos];
}
static u8
mwifiex_wmm_downgrade_tid(struct mwifiex_private *priv, u32 tid)
{
enum mwifiex_wmm_ac_e ac, ac_down;
u8 new_tid;
ac = mwifiex_wmm_convert_tos_to_ac(priv->adapter, tid);
ac_down = priv->wmm.ac_down_graded_vals[ac];
new_tid = ac_to_tid[ac_down][tid % 2];
return new_tid;
}
void
mwifiex_wmm_init(struct mwifiex_adapter *adapter)
{
int i, j;
struct mwifiex_private *priv;
for (j = 0; j < adapter->priv_num; ++j) {
priv = adapter->priv[j];
if (!priv)
continue;
for (i = 0; i < MAX_NUM_TID; ++i) {
priv->aggr_prio_tbl[i].amsdu = tos_to_tid_inv[i];
priv->aggr_prio_tbl[i].ampdu_ap = tos_to_tid_inv[i];
priv->aggr_prio_tbl[i].ampdu_user = tos_to_tid_inv[i];
priv->wmm.tid_tbl_ptr[i].ra_list_curr = NULL;
}
priv->aggr_prio_tbl[6].amsdu
= priv->aggr_prio_tbl[6].ampdu_ap
= priv->aggr_prio_tbl[6].ampdu_user
= BA_STREAM_NOT_ALLOWED;
priv->aggr_prio_tbl[7].amsdu = priv->aggr_prio_tbl[7].ampdu_ap
= priv->aggr_prio_tbl[7].ampdu_user
= BA_STREAM_NOT_ALLOWED;
priv->add_ba_param.timeout = MWIFIEX_DEFAULT_BLOCK_ACK_TIMEOUT;
priv->add_ba_param.tx_win_size = MWIFIEX_AMPDU_DEF_TXWINSIZE;
priv->add_ba_param.rx_win_size = MWIFIEX_AMPDU_DEF_RXWINSIZE;
atomic_set(&priv->wmm.tx_pkts_queued, 0);
atomic_set(&priv->wmm.highest_queued_prio, HIGH_PRIO_TID);
}
}
int
mwifiex_wmm_lists_empty(struct mwifiex_adapter *adapter)
{
int i;
struct mwifiex_private *priv;
for (i = 0; i < adapter->priv_num; ++i) {
priv = adapter->priv[i];
if (priv && atomic_read(&priv->wmm.tx_pkts_queued))
return false;
}
return true;
}
static void
mwifiex_wmm_del_pkts_in_ralist_node(struct mwifiex_private *priv,
struct mwifiex_ra_list_tbl *ra_list)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct sk_buff *skb, *tmp;
skb_queue_walk_safe(&ra_list->skb_head, skb, tmp)
mwifiex_write_data_complete(adapter, skb, -1);
}
static void
mwifiex_wmm_del_pkts_in_ralist(struct mwifiex_private *priv,
struct list_head *ra_list_head)
{
struct mwifiex_ra_list_tbl *ra_list;
list_for_each_entry(ra_list, ra_list_head, list)
mwifiex_wmm_del_pkts_in_ralist_node(priv, ra_list);
}
static void mwifiex_wmm_cleanup_queues(struct mwifiex_private *priv)
{
int i;
for (i = 0; i < MAX_NUM_TID; i++)
mwifiex_wmm_del_pkts_in_ralist(priv, &priv->wmm.tid_tbl_ptr[i].
ra_list);
atomic_set(&priv->wmm.tx_pkts_queued, 0);
atomic_set(&priv->wmm.highest_queued_prio, HIGH_PRIO_TID);
}
static void mwifiex_wmm_delete_all_ralist(struct mwifiex_private *priv)
{
struct mwifiex_ra_list_tbl *ra_list, *tmp_node;
int i;
for (i = 0; i < MAX_NUM_TID; ++i) {
dev_dbg(priv->adapter->dev,
"info: ra_list: freeing buf for tid %d\n", i);
list_for_each_entry_safe(ra_list, tmp_node,
&priv->wmm.tid_tbl_ptr[i].ra_list, list) {
list_del(&ra_list->list);
kfree(ra_list);
}
INIT_LIST_HEAD(&priv->wmm.tid_tbl_ptr[i].ra_list);
priv->wmm.tid_tbl_ptr[i].ra_list_curr = NULL;
}
}
void
mwifiex_clean_txrx(struct mwifiex_private *priv)
{
unsigned long flags;
mwifiex_11n_cleanup_reorder_tbl(priv);
spin_lock_irqsave(&priv->wmm.ra_list_spinlock, flags);
mwifiex_wmm_cleanup_queues(priv);
mwifiex_11n_delete_all_tx_ba_stream_tbl(priv);
if (priv->adapter->if_ops.cleanup_mpa_buf)
priv->adapter->if_ops.cleanup_mpa_buf(priv->adapter);
mwifiex_wmm_delete_all_ralist(priv);
memcpy(tos_to_tid, ac_to_tid, sizeof(tos_to_tid));
spin_unlock_irqrestore(&priv->wmm.ra_list_spinlock, flags);
}
static struct mwifiex_ra_list_tbl *
mwifiex_wmm_get_ralist_node(struct mwifiex_private *priv, u8 tid,
u8 *ra_addr)
{
struct mwifiex_ra_list_tbl *ra_list;
list_for_each_entry(ra_list, &priv->wmm.tid_tbl_ptr[tid].ra_list,
list) {
if (!memcmp(ra_list->ra, ra_addr, ETH_ALEN))
return ra_list;
}
return NULL;
}
static struct mwifiex_ra_list_tbl *
mwifiex_wmm_get_queue_raptr(struct mwifiex_private *priv, u8 tid, u8 *ra_addr)
{
struct mwifiex_ra_list_tbl *ra_list;
ra_list = mwifiex_wmm_get_ralist_node(priv, tid, ra_addr);
if (ra_list)
return ra_list;
mwifiex_ralist_add(priv, ra_addr);
return mwifiex_wmm_get_ralist_node(priv, tid, ra_addr);
}
int
mwifiex_is_ralist_valid(struct mwifiex_private *priv,
struct mwifiex_ra_list_tbl *ra_list, int ptr_index)
{
struct mwifiex_ra_list_tbl *rlist;
list_for_each_entry(rlist, &priv->wmm.tid_tbl_ptr[ptr_index].ra_list,
list) {
if (rlist == ra_list)
return true;
}
return false;
}
void
mwifiex_wmm_add_buf_txqueue(struct mwifiex_adapter *adapter,
struct sk_buff *skb)
{
struct mwifiex_txinfo *tx_info = MWIFIEX_SKB_TXCB(skb);
struct mwifiex_private *priv = adapter->priv[tx_info->bss_index];
u32 tid;
struct mwifiex_ra_list_tbl *ra_list;
u8 ra[ETH_ALEN], tid_down;
unsigned long flags;
if (!priv->media_connected) {
dev_dbg(adapter->dev, "data: drop packet in disconnect\n");
mwifiex_write_data_complete(adapter, skb, -1);
return;
}
tid = skb->priority;
spin_lock_irqsave(&priv->wmm.ra_list_spinlock, flags);
tid_down = mwifiex_wmm_downgrade_tid(priv, tid);
if (!mwifiex_queuing_ra_based(priv)) {
if (!list_empty(&priv->wmm.tid_tbl_ptr[tid_down].ra_list))
ra_list = list_first_entry(
&priv->wmm.tid_tbl_ptr[tid_down].ra_list,
struct mwifiex_ra_list_tbl, list);
else
ra_list = NULL;
} else {
memcpy(ra, skb->data, ETH_ALEN);
if (ra[0] & 0x01)
memset(ra, 0xff, ETH_ALEN);
ra_list = mwifiex_wmm_get_queue_raptr(priv, tid_down, ra);
}
if (!ra_list) {
spin_unlock_irqrestore(&priv->wmm.ra_list_spinlock, flags);
mwifiex_write_data_complete(adapter, skb, -1);
return;
}
skb_queue_tail(&ra_list->skb_head, skb);
ra_list->total_pkts_size += skb->len;
atomic_inc(&priv->wmm.tx_pkts_queued);
if (atomic_read(&priv->wmm.highest_queued_prio) <
tos_to_tid_inv[tid_down])
atomic_set(&priv->wmm.highest_queued_prio,
tos_to_tid_inv[tid_down]);
spin_unlock_irqrestore(&priv->wmm.ra_list_spinlock, flags);
}
int mwifiex_ret_wmm_get_status(struct mwifiex_private *priv,
const struct host_cmd_ds_command *resp)
{
u8 *curr = (u8 *) &resp->params.get_wmm_status;
uint16_t resp_len = le16_to_cpu(resp->size), tlv_len;
int valid = true;
struct mwifiex_ie_types_data *tlv_hdr;
struct mwifiex_ie_types_wmm_queue_status *tlv_wmm_qstatus;
struct ieee_types_wmm_parameter *wmm_param_ie = NULL;
struct mwifiex_wmm_ac_status *ac_status;
dev_dbg(priv->adapter->dev, "info: WMM: WMM_GET_STATUS cmdresp received: %d\n",
resp_len);
while ((resp_len >= sizeof(tlv_hdr->header)) && valid) {
tlv_hdr = (struct mwifiex_ie_types_data *) curr;
tlv_len = le16_to_cpu(tlv_hdr->header.len);
switch (le16_to_cpu(tlv_hdr->header.type)) {
case TLV_TYPE_WMMQSTATUS:
tlv_wmm_qstatus =
(struct mwifiex_ie_types_wmm_queue_status *)
tlv_hdr;
dev_dbg(priv->adapter->dev,
"info: CMD_RESP: WMM_GET_STATUS:"
" QSTATUS TLV: %d, %d, %d\n",
tlv_wmm_qstatus->queue_index,
tlv_wmm_qstatus->flow_required,
tlv_wmm_qstatus->disabled);
ac_status = &priv->wmm.ac_status[tlv_wmm_qstatus->
queue_index];
ac_status->disabled = tlv_wmm_qstatus->disabled;
ac_status->flow_required =
tlv_wmm_qstatus->flow_required;
ac_status->flow_created = tlv_wmm_qstatus->flow_created;
break;
case WLAN_EID_VENDOR_SPECIFIC:
wmm_param_ie =
(struct ieee_types_wmm_parameter *) (curr +
2);
wmm_param_ie->vend_hdr.len = (u8) tlv_len;
wmm_param_ie->vend_hdr.element_id =
WLAN_EID_VENDOR_SPECIFIC;
dev_dbg(priv->adapter->dev,
"info: CMD_RESP: WMM_GET_STATUS:"
" WMM Parameter Set Count: %d\n",
wmm_param_ie->qos_info_bitmap &
IEEE80211_WMM_IE_AP_QOSINFO_PARAM_SET_CNT_MASK);
memcpy((u8 *) &priv->curr_bss_params.bss_descriptor.
wmm_ie, wmm_param_ie,
wmm_param_ie->vend_hdr.len + 2);
break;
default:
valid = false;
break;
}
curr += (tlv_len + sizeof(tlv_hdr->header));
resp_len -= (tlv_len + sizeof(tlv_hdr->header));
}
mwifiex_wmm_setup_queue_priorities(priv, wmm_param_ie);
mwifiex_wmm_setup_ac_downgrade(priv);
return 0;
}
u32
mwifiex_wmm_process_association_req(struct mwifiex_private *priv,
u8 **assoc_buf,
struct ieee_types_wmm_parameter *wmm_ie,
struct ieee80211_ht_cap *ht_cap)
{
struct mwifiex_ie_types_wmm_param_set *wmm_tlv;
u32 ret_len = 0;
if (!assoc_buf)
return 0;
if (!(*assoc_buf))
return 0;
if (!wmm_ie)
return 0;
dev_dbg(priv->adapter->dev, "info: WMM: process assoc req:"
"bss->wmmIe=0x%x\n",
wmm_ie->vend_hdr.element_id);
if ((priv->wmm_required
|| (ht_cap && (priv->adapter->config_bands & BAND_GN
|| priv->adapter->config_bands & BAND_AN))
)
&& wmm_ie->vend_hdr.element_id == WLAN_EID_VENDOR_SPECIFIC) {
wmm_tlv = (struct mwifiex_ie_types_wmm_param_set *) *assoc_buf;
wmm_tlv->header.type = cpu_to_le16((u16) wmm_info_ie[0]);
wmm_tlv->header.len = cpu_to_le16((u16) wmm_info_ie[1]);
memcpy(wmm_tlv->wmm_ie, &wmm_info_ie[2],
le16_to_cpu(wmm_tlv->header.len));
if (wmm_ie->qos_info_bitmap & IEEE80211_WMM_IE_AP_QOSINFO_UAPSD)
memcpy((u8 *) (wmm_tlv->wmm_ie
+ le16_to_cpu(wmm_tlv->header.len)
- sizeof(priv->wmm_qosinfo)),
&priv->wmm_qosinfo,
sizeof(priv->wmm_qosinfo));
ret_len = sizeof(wmm_tlv->header)
+ le16_to_cpu(wmm_tlv->header.len);
*assoc_buf += ret_len;
}
return ret_len;
}
u8
mwifiex_wmm_compute_drv_pkt_delay(struct mwifiex_private *priv,
const struct sk_buff *skb)
{
u8 ret_val;
struct timeval out_tstamp, in_tstamp;
u32 queue_delay;
do_gettimeofday(&out_tstamp);
in_tstamp = ktime_to_timeval(skb->tstamp);
queue_delay = (out_tstamp.tv_sec - in_tstamp.tv_sec) * 1000;
queue_delay += (out_tstamp.tv_usec - in_tstamp.tv_usec) / 1000;
ret_val = (u8) (min(queue_delay, priv->wmm.drv_pkt_delay_max) >> 1);
dev_dbg(priv->adapter->dev, "data: WMM: Pkt Delay: %d ms,"
" %d ms sent to FW\n", queue_delay, ret_val);
return ret_val;
}
static struct mwifiex_ra_list_tbl *
mwifiex_wmm_get_highest_priolist_ptr(struct mwifiex_adapter *adapter,
struct mwifiex_private **priv, int *tid)
{
struct mwifiex_private *priv_tmp;
struct mwifiex_ra_list_tbl *ptr, *head;
struct mwifiex_bss_prio_node *bssprio_node, *bssprio_head;
struct mwifiex_tid_tbl *tid_ptr;
int is_list_empty;
unsigned long flags;
int i, j;
for (j = adapter->priv_num - 1; j >= 0; --j) {
spin_lock_irqsave(&adapter->bss_prio_tbl[j].bss_prio_lock,
flags);
is_list_empty = list_empty(&adapter->bss_prio_tbl[j]
.bss_prio_head);
spin_unlock_irqrestore(&adapter->bss_prio_tbl[j].bss_prio_lock,
flags);
if (is_list_empty)
continue;
if (adapter->bss_prio_tbl[j].bss_prio_cur ==
(struct mwifiex_bss_prio_node *)
&adapter->bss_prio_tbl[j].bss_prio_head) {
bssprio_node =
list_first_entry(&adapter->bss_prio_tbl[j]
.bss_prio_head,
struct mwifiex_bss_prio_node,
list);
bssprio_head = bssprio_node;
} else {
bssprio_node = adapter->bss_prio_tbl[j].bss_prio_cur;
bssprio_head = bssprio_node;
}
do {
atomic_t *hqp;
spinlock_t *lock;
priv_tmp = bssprio_node->priv;
hqp = &priv_tmp->wmm.highest_queued_prio;
lock = &priv_tmp->wmm.ra_list_spinlock;
for (i = atomic_read(hqp); i >= LOW_PRIO_TID; --i) {
tid_ptr = &(priv_tmp)->wmm.
tid_tbl_ptr[tos_to_tid[i]];
spin_lock_irqsave(&tid_ptr->tid_tbl_lock,
flags);
is_list_empty =
list_empty(&adapter->bss_prio_tbl[j]
.bss_prio_head);
spin_unlock_irqrestore(&tid_ptr->tid_tbl_lock,
flags);
if (is_list_empty)
continue;
ptr = list_first_entry(
&tid_ptr->ra_list_curr->list,
struct mwifiex_ra_list_tbl,
list);
head = ptr;
if (ptr == (struct mwifiex_ra_list_tbl *)
&tid_ptr->ra_list) {
ptr = list_first_entry(&ptr->list,
struct mwifiex_ra_list_tbl, list);
head = ptr;
}
do {
is_list_empty =
skb_queue_empty(&ptr->skb_head);
if (!is_list_empty) {
spin_lock_irqsave(lock, flags);
if (atomic_read(hqp) > i)
atomic_set(hqp, i);
spin_unlock_irqrestore(lock,
flags);
*priv = priv_tmp;
*tid = tos_to_tid[i];
return ptr;
}
ptr = list_first_entry(&ptr->list,
struct mwifiex_ra_list_tbl,
list);
if (ptr ==
(struct mwifiex_ra_list_tbl *)
&tid_ptr->ra_list)
ptr = list_first_entry(
&ptr->list,
struct mwifiex_ra_list_tbl,
list);
} while (ptr != head);
}
atomic_set(hqp, NO_PKT_PRIO_TID);
bssprio_node = list_first_entry(&bssprio_node->list,
struct mwifiex_bss_prio_node,
list);
if (bssprio_node ==
(struct mwifiex_bss_prio_node *)
&adapter->bss_prio_tbl[j].bss_prio_head)
bssprio_node = list_first_entry(
&bssprio_node->list,
struct mwifiex_bss_prio_node,
list);
} while (bssprio_node != bssprio_head);
}
return NULL;
}
static int
mwifiex_is_11n_aggragation_possible(struct mwifiex_private *priv,
struct mwifiex_ra_list_tbl *ptr,
int max_buf_size)
{
int count = 0, total_size = 0;
struct sk_buff *skb, *tmp;
skb_queue_walk_safe(&ptr->skb_head, skb, tmp) {
total_size += skb->len;
if (total_size >= max_buf_size)
break;
if (++count >= MIN_NUM_AMSDU)
return true;
}
return false;
}
static void
mwifiex_send_single_packet(struct mwifiex_private *priv,
struct mwifiex_ra_list_tbl *ptr, int ptr_index,
unsigned long ra_list_flags)
__releases(&priv->wmm.ra_list_spinlock
static int
mwifiex_is_ptr_processed(struct mwifiex_private *priv,
struct mwifiex_ra_list_tbl *ptr)
{
struct sk_buff *skb;
struct mwifiex_txinfo *tx_info;
if (skb_queue_empty(&ptr->skb_head))
return false;
skb = skb_peek(&ptr->skb_head);
tx_info = MWIFIEX_SKB_TXCB(skb);
if (tx_info->flags & MWIFIEX_BUF_FLAG_REQUEUED_PKT)
return true;
return false;
}
static void
mwifiex_send_processed_packet(struct mwifiex_private *priv,
struct mwifiex_ra_list_tbl *ptr, int ptr_index,
unsigned long ra_list_flags)
__releases(&priv->wmm.ra_list_spinlock
static int
mwifiex_dequeue_tx_packet(struct mwifiex_adapter *adapter)
{
struct mwifiex_ra_list_tbl *ptr;
struct mwifiex_private *priv = NULL;
int ptr_index = 0;
u8 ra[ETH_ALEN];
int tid_del = 0, tid = 0;
unsigned long flags;
ptr = mwifiex_wmm_get_highest_priolist_ptr(adapter, &priv, &ptr_index);
if (!ptr)
return -1;
tid = mwifiex_get_tid(ptr);
dev_dbg(adapter->dev, "data: tid=%d\n", tid);
spin_lock_irqsave(&priv->wmm.ra_list_spinlock, flags);
if (!mwifiex_is_ralist_valid(priv, ptr, ptr_index)) {
spin_unlock_irqrestore(&priv->wmm.ra_list_spinlock, flags);
return -1;
}
if (mwifiex_is_ptr_processed(priv, ptr)) {
mwifiex_send_processed_packet(priv, ptr, ptr_index, flags);
return 0;
}
if (!ptr->is_11n_enabled || mwifiex_is_ba_stream_setup(priv, ptr, tid)
|| ((priv->sec_info.wpa_enabled
|| priv->sec_info.wpa2_enabled) && !priv->wpa_is_gtk_set)
) {
mwifiex_send_single_packet(priv, ptr, ptr_index, flags);
} else {
if (mwifiex_is_ampdu_allowed(priv, tid)) {
if (mwifiex_space_avail_for_new_ba_stream(adapter)) {
mwifiex_11n_create_tx_ba_stream_tbl(priv,
ptr->ra, tid,
BA_STREAM_SETUP_INPROGRESS);
mwifiex_send_addba(priv, tid, ptr->ra);
} else if (mwifiex_find_stream_to_delete
(priv, tid, &tid_del, ra)) {
mwifiex_11n_create_tx_ba_stream_tbl(priv,
ptr->ra, tid,
BA_STREAM_SETUP_INPROGRESS);
mwifiex_send_delba(priv, tid_del, ra, 1);
}
}
if (mwifiex_is_amsdu_allowed(priv, tid) &&
mwifiex_is_11n_aggragation_possible(priv, ptr,
adapter->tx_buf_size))
mwifiex_11n_aggregate_pkt(priv, ptr, INTF_HEADER_LEN,
ptr_index, flags);
else
mwifiex_send_single_packet(priv, ptr, ptr_index, flags);
}
return 0;
}
void
mwifiex_wmm_process_tx(struct mwifiex_adapter *adapter)
{
do {
if (adapter->data_sent || adapter->tx_lock_flag)
break;
if (mwifiex_dequeue_tx_packet(adapter))
break;
} while (!mwifiex_wmm_lists_empty(adapter));
}
