static inline int seq_less(u16 sq1, u16 sq2)
{
return ((sq1 - sq2) & SEQ_MASK) > (SEQ_MODULO >> 1);
}
static inline u16 seq_inc(u16 sq)
{
return (sq + 1) & SEQ_MASK;
}
static inline u16 seq_sub(u16 sq1, u16 sq2)
{
return (sq1 - sq2) & SEQ_MASK;
}
static inline int reorder_index(struct wil_tid_ampdu_rx *r, u16 seq)
{
return seq_sub(seq, r->ssn) % r->buf_size;
}
static void wil_release_reorder_frame(struct wil6210_priv *wil,
struct wil_tid_ampdu_rx *r,
int index)
{
struct net_device *ndev = wil_to_ndev(wil);
struct sk_buff *skb = r->reorder_buf[index];
if (!skb)
goto no_frame;
r->stored_mpdu_num--;
r->reorder_buf[index] = NULL;
wil_netif_rx_any(skb, ndev);
no_frame:
r->head_seq_num = seq_inc(r->head_seq_num);
}
static void wil_release_reorder_frames(struct wil6210_priv *wil,
struct wil_tid_ampdu_rx *r,
u16 hseq)
{
int index;
while (seq_less(r->head_seq_num, hseq) && r->stored_mpdu_num) {
index = reorder_index(r, r->head_seq_num);
wil_release_reorder_frame(wil, r, index);
}
r->head_seq_num = hseq;
}
static void wil_reorder_release(struct wil6210_priv *wil,
struct wil_tid_ampdu_rx *r)
{
int index = reorder_index(r, r->head_seq_num);
while (r->reorder_buf[index]) {
wil_release_reorder_frame(wil, r, index);
index = reorder_index(r, r->head_seq_num);
}
}
void wil_rx_reorder(struct wil6210_priv *wil, struct sk_buff *skb)
__acquires(&sta->tid_rx_lock
void wil_rx_bar(struct wil6210_priv *wil, u8 cid, u8 tid, u16 seq)
{
struct wil_sta_info *sta = &wil->sta[cid];
struct wil_tid_ampdu_rx *r;
spin_lock(&sta->tid_rx_lock);
r = sta->tid_rx[tid];
if (!r) {
wil_err(wil, "BAR for non-existing CID %d TID %d\n", cid, tid);
goto out;
}
if (seq_less(seq, r->head_seq_num)) {
wil_err(wil, "BAR Seq 0x%03x preceding head 0x%03x\n",
seq, r->head_seq_num);
goto out;
}
wil_dbg_txrx(wil, "BAR: CID %d TID %d Seq 0x%03x head 0x%03x\n",
cid, tid, seq, r->head_seq_num);
wil_release_reorder_frames(wil, r, seq);
out:
spin_unlock(&sta->tid_rx_lock);
}
struct wil_tid_ampdu_rx *wil_tid_ampdu_rx_alloc(struct wil6210_priv *wil,
int size, u16 ssn)
{
struct wil_tid_ampdu_rx *r = kzalloc(sizeof(*r), GFP_KERNEL);
if (!r)
return NULL;
r->reorder_buf =
kcalloc(size, sizeof(struct sk_buff *), GFP_KERNEL);
r->reorder_time =
kcalloc(size, sizeof(unsigned long), GFP_KERNEL);
if (!r->reorder_buf || !r->reorder_time) {
kfree(r->reorder_buf);
kfree(r->reorder_time);
kfree(r);
return NULL;
}
r->ssn = ssn;
r->head_seq_num = ssn;
r->buf_size = size;
r->stored_mpdu_num = 0;
r->first_time = true;
return r;
}
void wil_tid_ampdu_rx_free(struct wil6210_priv *wil,
struct wil_tid_ampdu_rx *r)
{
int i;
if (!r)
return;
for (i = 0; i < r->buf_size; i++)
kfree_skb(r->reorder_buf[i]);
kfree(r->reorder_buf);
kfree(r->reorder_time);
kfree(r);
}
static u16 wil_agg_size(struct wil6210_priv *wil, u16 req_agg_wsize)
{
u16 max_agg_size = min_t(u16, WIL_MAX_AGG_WSIZE, WIL_MAX_AMPDU_SIZE /
(mtu_max + WIL_MAX_MPDU_OVERHEAD));
if (!req_agg_wsize)
return max_agg_size;
return min(max_agg_size, req_agg_wsize);
}
int wil_addba_rx_request(struct wil6210_priv *wil, u8 cidxtid,
u8 dialog_token, __le16 ba_param_set,
__le16 ba_timeout, __le16 ba_seq_ctrl)
__acquires(&sta->tid_rx_lock
int wil_addba_tx_request(struct wil6210_priv *wil, u8 ringid, u16 wsize)
{
u8 agg_wsize = wil_agg_size(wil, wsize);
u16 agg_timeout = 0;
struct vring_tx_data *txdata = &wil->vring_tx_data[ringid];
int rc = 0;
if (txdata->addba_in_progress) {
wil_dbg_misc(wil, "ADDBA for vring[%d] already in progress\n",
ringid);
goto out;
}
if (txdata->agg_wsize) {
wil_dbg_misc(wil,
"ADDBA for vring[%d] already done for wsize %d\n",
ringid, txdata->agg_wsize);
goto out;
}
txdata->addba_in_progress = true;
rc = wmi_addba(wil, ringid, agg_wsize, agg_timeout);
if (rc) {
wil_err(wil, "%s: wmi_addba failed, rc (%d)", __func__, rc);
txdata->addba_in_progress = false;
}
out:
return rc;
}
