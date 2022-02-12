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
if (!r)
return;
wil_release_reorder_frames(wil, r, r->head_seq_num + r->buf_size);
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
{
struct wil_back_rx *req = kzalloc(sizeof(*req), GFP_KERNEL);
if (!req)
return -ENOMEM;
req->cidxtid = cidxtid;
req->dialog_token = dialog_token;
req->ba_param_set = le16_to_cpu(ba_param_set);
req->ba_timeout = le16_to_cpu(ba_timeout);
req->ba_seq_ctrl = le16_to_cpu(ba_seq_ctrl);
mutex_lock(&wil->back_rx_mutex);
list_add_tail(&req->list, &wil->back_rx_pending);
mutex_unlock(&wil->back_rx_mutex);
queue_work(wil->wq_service, &wil->back_rx_worker);
return 0;
}
static void wil_back_rx_handle(struct wil6210_priv *wil,
struct wil_back_rx *req)
__acquires(&sta->tid_rx_lock
void wil_back_rx_flush(struct wil6210_priv *wil)
{
struct wil_back_rx *evt, *t;
wil_dbg_misc(wil, "%s()\n", __func__);
mutex_lock(&wil->back_rx_mutex);
list_for_each_entry_safe(evt, t, &wil->back_rx_pending, list) {
list_del(&evt->list);
kfree(evt);
}
mutex_unlock(&wil->back_rx_mutex);
}
static struct list_head *next_back_rx(struct wil6210_priv *wil)
{
struct list_head *ret = NULL;
mutex_lock(&wil->back_rx_mutex);
if (!list_empty(&wil->back_rx_pending)) {
ret = wil->back_rx_pending.next;
list_del(ret);
}
mutex_unlock(&wil->back_rx_mutex);
return ret;
}
void wil_back_rx_worker(struct work_struct *work)
{
struct wil6210_priv *wil = container_of(work, struct wil6210_priv,
back_rx_worker);
struct wil_back_rx *evt;
struct list_head *lh;
while ((lh = next_back_rx(wil)) != NULL) {
evt = list_entry(lh, struct wil_back_rx, list);
wil_back_rx_handle(wil, evt);
kfree(evt);
}
}
static void wil_back_tx_handle(struct wil6210_priv *wil,
struct wil_back_tx *req)
{
struct vring_tx_data *txdata = &wil->vring_tx_data[req->ringid];
int rc;
if (txdata->addba_in_progress) {
wil_dbg_misc(wil, "ADDBA for vring[%d] already in progress\n",
req->ringid);
return;
}
if (txdata->agg_wsize) {
wil_dbg_misc(wil,
"ADDBA for vring[%d] already established wsize %d\n",
req->ringid, txdata->agg_wsize);
return;
}
txdata->addba_in_progress = true;
rc = wmi_addba(wil, req->ringid, req->agg_wsize, req->agg_timeout);
if (rc)
txdata->addba_in_progress = false;
}
static struct list_head *next_back_tx(struct wil6210_priv *wil)
{
struct list_head *ret = NULL;
mutex_lock(&wil->back_tx_mutex);
if (!list_empty(&wil->back_tx_pending)) {
ret = wil->back_tx_pending.next;
list_del(ret);
}
mutex_unlock(&wil->back_tx_mutex);
return ret;
}
void wil_back_tx_worker(struct work_struct *work)
{
struct wil6210_priv *wil = container_of(work, struct wil6210_priv,
back_tx_worker);
struct wil_back_tx *evt;
struct list_head *lh;
while ((lh = next_back_tx(wil)) != NULL) {
evt = list_entry(lh, struct wil_back_tx, list);
wil_back_tx_handle(wil, evt);
kfree(evt);
}
}
void wil_back_tx_flush(struct wil6210_priv *wil)
{
struct wil_back_tx *evt, *t;
wil_dbg_misc(wil, "%s()\n", __func__);
mutex_lock(&wil->back_tx_mutex);
list_for_each_entry_safe(evt, t, &wil->back_tx_pending, list) {
list_del(&evt->list);
kfree(evt);
}
mutex_unlock(&wil->back_tx_mutex);
}
int wil_addba_tx_request(struct wil6210_priv *wil, u8 ringid, u16 wsize)
{
struct wil_back_tx *req = kzalloc(sizeof(*req), GFP_KERNEL);
if (!req)
return -ENOMEM;
req->ringid = ringid;
req->agg_wsize = wil_agg_size(wil, wsize);
req->agg_timeout = 0;
mutex_lock(&wil->back_tx_mutex);
list_add_tail(&req->list, &wil->back_tx_pending);
mutex_unlock(&wil->back_tx_mutex);
queue_work(wil->wq_service, &wil->back_tx_worker);
return 0;
}
