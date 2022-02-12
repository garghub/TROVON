static inline unsigned long idx_to_pfn(struct xenvif_queue *queue,
u16 idx)
{
return page_to_pfn(queue->mmap_pages[idx]);
}
static inline unsigned long idx_to_kaddr(struct xenvif_queue *queue,
u16 idx)
{
return (unsigned long)pfn_to_kaddr(idx_to_pfn(queue, idx));
}
static inline struct xenvif_queue *ubuf_to_queue(const struct ubuf_info *ubuf)
{
u16 pending_idx = ubuf->desc;
struct pending_tx_info *temp =
container_of(ubuf, struct pending_tx_info, callback_struct);
return container_of(temp - pending_idx,
struct xenvif_queue,
pending_tx_info[0]);
}
static u16 frag_get_pending_idx(skb_frag_t *frag)
{
return (u16)frag->page_offset;
}
static void frag_set_pending_idx(skb_frag_t *frag, u16 pending_idx)
{
frag->page_offset = pending_idx;
}
static inline pending_ring_idx_t pending_index(unsigned i)
{
return i & (MAX_PENDING_REQS-1);
}
bool xenvif_rx_ring_slots_available(struct xenvif_queue *queue, int needed)
{
RING_IDX prod, cons;
do {
prod = queue->rx.sring->req_prod;
cons = queue->rx.req_cons;
if (prod - cons >= needed)
return true;
queue->rx.sring->req_event = prod + 1;
mb();
} while (queue->rx.sring->req_prod != prod);
return false;
}
static bool start_new_rx_buffer(int offset, unsigned long size, int head,
bool full_coalesce)
{
if (offset == MAX_BUFFER_OFFSET)
return true;
BUG_ON(size > MAX_BUFFER_OFFSET);
if ((offset + size > MAX_BUFFER_OFFSET) && offset && !head &&
!full_coalesce)
return true;
return false;
}
static struct xenvif_rx_meta *get_next_rx_buffer(struct xenvif_queue *queue,
struct netrx_pending_operations *npo)
{
struct xenvif_rx_meta *meta;
struct xen_netif_rx_request *req;
req = RING_GET_REQUEST(&queue->rx, queue->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
meta->gso_type = XEN_NETIF_GSO_TYPE_NONE;
meta->gso_size = 0;
meta->size = 0;
meta->id = req->id;
npo->copy_off = 0;
npo->copy_gref = req->gref;
return meta;
}
static void xenvif_gop_frag_copy(struct xenvif_queue *queue, struct sk_buff *skb,
struct netrx_pending_operations *npo,
struct page *page, unsigned long size,
unsigned long offset, int *head,
struct xenvif_queue *foreign_queue,
grant_ref_t foreign_gref)
{
struct gnttab_copy *copy_gop;
struct xenvif_rx_meta *meta;
unsigned long bytes;
int gso_type = XEN_NETIF_GSO_TYPE_NONE;
BUG_ON(size + offset > PAGE_SIZE<<compound_order(page));
meta = npo->meta + npo->meta_prod - 1;
page += offset >> PAGE_SHIFT;
offset &= ~PAGE_MASK;
while (size > 0) {
BUG_ON(offset >= PAGE_SIZE);
BUG_ON(npo->copy_off > MAX_BUFFER_OFFSET);
bytes = PAGE_SIZE - offset;
if (bytes > size)
bytes = size;
if (start_new_rx_buffer(npo->copy_off,
bytes,
*head,
XENVIF_RX_CB(skb)->full_coalesce)) {
BUG_ON(*head);
meta = get_next_rx_buffer(queue, npo);
}
if (npo->copy_off + bytes > MAX_BUFFER_OFFSET)
bytes = MAX_BUFFER_OFFSET - npo->copy_off;
copy_gop = npo->copy + npo->copy_prod++;
copy_gop->flags = GNTCOPY_dest_gref;
copy_gop->len = bytes;
if (foreign_queue) {
copy_gop->source.domid = foreign_queue->vif->domid;
copy_gop->source.u.ref = foreign_gref;
copy_gop->flags |= GNTCOPY_source_gref;
} else {
copy_gop->source.domid = DOMID_SELF;
copy_gop->source.u.gmfn =
virt_to_mfn(page_address(page));
}
copy_gop->source.offset = offset;
copy_gop->dest.domid = queue->vif->domid;
copy_gop->dest.offset = npo->copy_off;
copy_gop->dest.u.ref = npo->copy_gref;
npo->copy_off += bytes;
meta->size += bytes;
offset += bytes;
size -= bytes;
if (offset == PAGE_SIZE && size) {
BUG_ON(!PageCompound(page));
page++;
offset = 0;
}
if (skb_is_gso(skb)) {
if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4)
gso_type = XEN_NETIF_GSO_TYPE_TCPV4;
else if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV6)
gso_type = XEN_NETIF_GSO_TYPE_TCPV6;
}
if (*head && ((1 << gso_type) & queue->vif->gso_mask))
queue->rx.req_cons++;
*head = 0;
}
}
static const struct ubuf_info *xenvif_find_gref(const struct sk_buff *const skb,
const int i,
const struct ubuf_info *ubuf)
{
struct xenvif_queue *foreign_queue = ubuf_to_queue(ubuf);
do {
u16 pending_idx = ubuf->desc;
if (skb_shinfo(skb)->frags[i].page.p ==
foreign_queue->mmap_pages[pending_idx])
break;
ubuf = (struct ubuf_info *) ubuf->ctx;
} while (ubuf);
return ubuf;
}
static int xenvif_gop_skb(struct sk_buff *skb,
struct netrx_pending_operations *npo,
struct xenvif_queue *queue)
{
struct xenvif *vif = netdev_priv(skb->dev);
int nr_frags = skb_shinfo(skb)->nr_frags;
int i;
struct xen_netif_rx_request *req;
struct xenvif_rx_meta *meta;
unsigned char *data;
int head = 1;
int old_meta_prod;
int gso_type;
const struct ubuf_info *ubuf = skb_shinfo(skb)->destructor_arg;
const struct ubuf_info *const head_ubuf = ubuf;
old_meta_prod = npo->meta_prod;
gso_type = XEN_NETIF_GSO_TYPE_NONE;
if (skb_is_gso(skb)) {
if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4)
gso_type = XEN_NETIF_GSO_TYPE_TCPV4;
else if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV6)
gso_type = XEN_NETIF_GSO_TYPE_TCPV6;
}
if ((1 << gso_type) & vif->gso_prefix_mask) {
req = RING_GET_REQUEST(&queue->rx, queue->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
meta->gso_type = gso_type;
meta->gso_size = skb_shinfo(skb)->gso_size;
meta->size = 0;
meta->id = req->id;
}
req = RING_GET_REQUEST(&queue->rx, queue->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
if ((1 << gso_type) & vif->gso_mask) {
meta->gso_type = gso_type;
meta->gso_size = skb_shinfo(skb)->gso_size;
} else {
meta->gso_type = XEN_NETIF_GSO_TYPE_NONE;
meta->gso_size = 0;
}
meta->size = 0;
meta->id = req->id;
npo->copy_off = 0;
npo->copy_gref = req->gref;
data = skb->data;
while (data < skb_tail_pointer(skb)) {
unsigned int offset = offset_in_page(data);
unsigned int len = PAGE_SIZE - offset;
if (data + len > skb_tail_pointer(skb))
len = skb_tail_pointer(skb) - data;
xenvif_gop_frag_copy(queue, skb, npo,
virt_to_page(data), len, offset, &head,
NULL,
0);
data += len;
}
for (i = 0; i < nr_frags; i++) {
struct xenvif_queue *foreign_queue = NULL;
grant_ref_t foreign_gref;
if ((skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY) &&
(ubuf->callback == &xenvif_zerocopy_callback)) {
const struct ubuf_info *const startpoint = ubuf;
ubuf = xenvif_find_gref(skb, i, ubuf);
if (unlikely(!ubuf) && startpoint != head_ubuf)
ubuf = xenvif_find_gref(skb, i, head_ubuf);
if (likely(ubuf)) {
u16 pending_idx = ubuf->desc;
foreign_queue = ubuf_to_queue(ubuf);
foreign_gref =
foreign_queue->pending_tx_info[pending_idx].req.gref;
ubuf = ubuf->ctx ?
(struct ubuf_info *) ubuf->ctx :
head_ubuf;
} else
ubuf = head_ubuf;
}
xenvif_gop_frag_copy(queue, skb, npo,
skb_frag_page(&skb_shinfo(skb)->frags[i]),
skb_frag_size(&skb_shinfo(skb)->frags[i]),
skb_shinfo(skb)->frags[i].page_offset,
&head,
foreign_queue,
foreign_queue ? foreign_gref : UINT_MAX);
}
return npo->meta_prod - old_meta_prod;
}
static int xenvif_check_gop(struct xenvif *vif, int nr_meta_slots,
struct netrx_pending_operations *npo)
{
struct gnttab_copy *copy_op;
int status = XEN_NETIF_RSP_OKAY;
int i;
for (i = 0; i < nr_meta_slots; i++) {
copy_op = npo->copy + npo->copy_cons++;
if (copy_op->status != GNTST_okay) {
netdev_dbg(vif->dev,
"Bad status %d from copy to DOM%d.\n",
copy_op->status, vif->domid);
status = XEN_NETIF_RSP_ERROR;
}
}
return status;
}
static void xenvif_add_frag_responses(struct xenvif_queue *queue, int status,
struct xenvif_rx_meta *meta,
int nr_meta_slots)
{
int i;
unsigned long offset;
if (nr_meta_slots <= 1)
return;
nr_meta_slots--;
for (i = 0; i < nr_meta_slots; i++) {
int flags;
if (i == nr_meta_slots - 1)
flags = 0;
else
flags = XEN_NETRXF_more_data;
offset = 0;
make_rx_response(queue, meta[i].id, status, offset,
meta[i].size, flags);
}
}
void xenvif_kick_thread(struct xenvif_queue *queue)
{
wake_up(&queue->wq);
}
static void xenvif_rx_action(struct xenvif_queue *queue)
{
s8 status;
u16 flags;
struct xen_netif_rx_response *resp;
struct sk_buff_head rxq;
struct sk_buff *skb;
LIST_HEAD(notify);
int ret;
unsigned long offset;
bool need_to_notify = false;
struct netrx_pending_operations npo = {
.copy = queue->grant_copy_op,
.meta = queue->meta,
};
skb_queue_head_init(&rxq);
while ((skb = skb_dequeue(&queue->rx_queue)) != NULL) {
RING_IDX max_slots_needed;
RING_IDX old_req_cons;
RING_IDX ring_slots_used;
int i;
max_slots_needed = DIV_ROUND_UP(offset_in_page(skb->data) +
skb_headlen(skb),
PAGE_SIZE);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
unsigned int size;
unsigned int offset;
size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
offset = skb_shinfo(skb)->frags[i].page_offset;
max_slots_needed += DIV_ROUND_UP(offset + size,
PAGE_SIZE);
}
if (max_slots_needed > MAX_SKB_FRAGS) {
max_slots_needed = MAX_SKB_FRAGS;
XENVIF_RX_CB(skb)->full_coalesce = true;
} else {
XENVIF_RX_CB(skb)->full_coalesce = false;
}
if (skb_is_gso(skb) &&
(skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4 ||
skb_shinfo(skb)->gso_type & SKB_GSO_TCPV6))
max_slots_needed++;
if (!xenvif_rx_ring_slots_available(queue, max_slots_needed)) {
skb_queue_head(&queue->rx_queue, skb);
need_to_notify = true;
queue->rx_last_skb_slots = max_slots_needed;
break;
} else
queue->rx_last_skb_slots = 0;
old_req_cons = queue->rx.req_cons;
XENVIF_RX_CB(skb)->meta_slots_used = xenvif_gop_skb(skb, &npo, queue);
ring_slots_used = queue->rx.req_cons - old_req_cons;
BUG_ON(ring_slots_used > max_slots_needed);
__skb_queue_tail(&rxq, skb);
}
BUG_ON(npo.meta_prod > ARRAY_SIZE(queue->meta));
if (!npo.copy_prod)
goto done;
BUG_ON(npo.copy_prod > MAX_GRANT_COPY_OPS);
gnttab_batch_copy(queue->grant_copy_op, npo.copy_prod);
while ((skb = __skb_dequeue(&rxq)) != NULL) {
if ((1 << queue->meta[npo.meta_cons].gso_type) &
queue->vif->gso_prefix_mask) {
resp = RING_GET_RESPONSE(&queue->rx,
queue->rx.rsp_prod_pvt++);
resp->flags = XEN_NETRXF_gso_prefix | XEN_NETRXF_more_data;
resp->offset = queue->meta[npo.meta_cons].gso_size;
resp->id = queue->meta[npo.meta_cons].id;
resp->status = XENVIF_RX_CB(skb)->meta_slots_used;
npo.meta_cons++;
XENVIF_RX_CB(skb)->meta_slots_used--;
}
queue->stats.tx_bytes += skb->len;
queue->stats.tx_packets++;
status = xenvif_check_gop(queue->vif,
XENVIF_RX_CB(skb)->meta_slots_used,
&npo);
if (XENVIF_RX_CB(skb)->meta_slots_used == 1)
flags = 0;
else
flags = XEN_NETRXF_more_data;
if (skb->ip_summed == CHECKSUM_PARTIAL)
flags |= XEN_NETRXF_csum_blank | XEN_NETRXF_data_validated;
else if (skb->ip_summed == CHECKSUM_UNNECESSARY)
flags |= XEN_NETRXF_data_validated;
offset = 0;
resp = make_rx_response(queue, queue->meta[npo.meta_cons].id,
status, offset,
queue->meta[npo.meta_cons].size,
flags);
if ((1 << queue->meta[npo.meta_cons].gso_type) &
queue->vif->gso_mask) {
struct xen_netif_extra_info *gso =
(struct xen_netif_extra_info *)
RING_GET_RESPONSE(&queue->rx,
queue->rx.rsp_prod_pvt++);
resp->flags |= XEN_NETRXF_extra_info;
gso->u.gso.type = queue->meta[npo.meta_cons].gso_type;
gso->u.gso.size = queue->meta[npo.meta_cons].gso_size;
gso->u.gso.pad = 0;
gso->u.gso.features = 0;
gso->type = XEN_NETIF_EXTRA_TYPE_GSO;
gso->flags = 0;
}
xenvif_add_frag_responses(queue, status,
queue->meta + npo.meta_cons + 1,
XENVIF_RX_CB(skb)->meta_slots_used);
RING_PUSH_RESPONSES_AND_CHECK_NOTIFY(&queue->rx, ret);
need_to_notify |= !!ret;
npo.meta_cons += XENVIF_RX_CB(skb)->meta_slots_used;
dev_kfree_skb(skb);
}
done:
if (need_to_notify)
notify_remote_via_irq(queue->rx_irq);
}
void xenvif_napi_schedule_or_enable_events(struct xenvif_queue *queue)
{
int more_to_do;
RING_FINAL_CHECK_FOR_REQUESTS(&queue->tx, more_to_do);
if (more_to_do)
napi_schedule(&queue->napi);
}
static void tx_add_credit(struct xenvif_queue *queue)
{
unsigned long max_burst, max_credit;
max_burst = RING_GET_REQUEST(&queue->tx, queue->tx.req_cons)->size;
max_burst = min(max_burst, 131072UL);
max_burst = max(max_burst, queue->credit_bytes);
max_credit = queue->remaining_credit + queue->credit_bytes;
if (max_credit < queue->remaining_credit)
max_credit = ULONG_MAX;
queue->remaining_credit = min(max_credit, max_burst);
}
static void tx_credit_callback(unsigned long data)
{
struct xenvif_queue *queue = (struct xenvif_queue *)data;
tx_add_credit(queue);
xenvif_napi_schedule_or_enable_events(queue);
}
static void xenvif_tx_err(struct xenvif_queue *queue,
struct xen_netif_tx_request *txp, RING_IDX end)
{
RING_IDX cons = queue->tx.req_cons;
unsigned long flags;
do {
spin_lock_irqsave(&queue->response_lock, flags);
make_tx_response(queue, txp, XEN_NETIF_RSP_ERROR);
spin_unlock_irqrestore(&queue->response_lock, flags);
if (cons == end)
break;
txp = RING_GET_REQUEST(&queue->tx, cons++);
} while (1);
queue->tx.req_cons = cons;
}
static void xenvif_fatal_tx_err(struct xenvif *vif)
{
netdev_err(vif->dev, "fatal error; disabling device\n");
vif->disabled = true;
if (vif->queues)
xenvif_kick_thread(&vif->queues[0]);
}
static int xenvif_count_requests(struct xenvif_queue *queue,
struct xen_netif_tx_request *first,
struct xen_netif_tx_request *txp,
int work_to_do)
{
RING_IDX cons = queue->tx.req_cons;
int slots = 0;
int drop_err = 0;
int more_data;
if (!(first->flags & XEN_NETTXF_more_data))
return 0;
do {
struct xen_netif_tx_request dropped_tx = { 0 };
if (slots >= work_to_do) {
netdev_err(queue->vif->dev,
"Asked for %d slots but exceeds this limit\n",
work_to_do);
xenvif_fatal_tx_err(queue->vif);
return -ENODATA;
}
if (unlikely(slots >= fatal_skb_slots)) {
netdev_err(queue->vif->dev,
"Malicious frontend using %d slots, threshold %u\n",
slots, fatal_skb_slots);
xenvif_fatal_tx_err(queue->vif);
return -E2BIG;
}
if (!drop_err && slots >= XEN_NETBK_LEGACY_SLOTS_MAX) {
if (net_ratelimit())
netdev_dbg(queue->vif->dev,
"Too many slots (%d) exceeding limit (%d), dropping packet\n",
slots, XEN_NETBK_LEGACY_SLOTS_MAX);
drop_err = -E2BIG;
}
if (drop_err)
txp = &dropped_tx;
memcpy(txp, RING_GET_REQUEST(&queue->tx, cons + slots),
sizeof(*txp));
if (!drop_err && txp->size > first->size) {
if (net_ratelimit())
netdev_dbg(queue->vif->dev,
"Invalid tx request, slot size %u > remaining size %u\n",
txp->size, first->size);
drop_err = -EIO;
}
first->size -= txp->size;
slots++;
if (unlikely((txp->offset + txp->size) > PAGE_SIZE)) {
netdev_err(queue->vif->dev, "Cross page boundary, txp->offset: %x, size: %u\n",
txp->offset, txp->size);
xenvif_fatal_tx_err(queue->vif);
return -EINVAL;
}
more_data = txp->flags & XEN_NETTXF_more_data;
if (!drop_err)
txp++;
} while (more_data);
if (drop_err) {
xenvif_tx_err(queue, first, cons + slots);
return drop_err;
}
return slots;
}
static inline void xenvif_tx_create_map_op(struct xenvif_queue *queue,
u16 pending_idx,
struct xen_netif_tx_request *txp,
struct gnttab_map_grant_ref *mop)
{
queue->pages_to_map[mop-queue->tx_map_ops] = queue->mmap_pages[pending_idx];
gnttab_set_map_op(mop, idx_to_kaddr(queue, pending_idx),
GNTMAP_host_map | GNTMAP_readonly,
txp->gref, queue->vif->domid);
memcpy(&queue->pending_tx_info[pending_idx].req, txp,
sizeof(*txp));
}
static inline struct sk_buff *xenvif_alloc_skb(unsigned int size)
{
struct sk_buff *skb =
alloc_skb(size + NET_SKB_PAD + NET_IP_ALIGN,
GFP_ATOMIC | __GFP_NOWARN);
if (unlikely(skb == NULL))
return NULL;
skb_reserve(skb, NET_SKB_PAD + NET_IP_ALIGN);
skb_shinfo(skb)->destructor_arg = NULL;
return skb;
}
static struct gnttab_map_grant_ref *xenvif_get_requests(struct xenvif_queue *queue,
struct sk_buff *skb,
struct xen_netif_tx_request *txp,
struct gnttab_map_grant_ref *gop)
{
struct skb_shared_info *shinfo = skb_shinfo(skb);
skb_frag_t *frags = shinfo->frags;
u16 pending_idx = XENVIF_TX_CB(skb)->pending_idx;
int start;
pending_ring_idx_t index;
unsigned int nr_slots, frag_overflow = 0;
if (shinfo->nr_frags > MAX_SKB_FRAGS) {
frag_overflow = shinfo->nr_frags - MAX_SKB_FRAGS;
BUG_ON(frag_overflow > MAX_SKB_FRAGS);
shinfo->nr_frags = MAX_SKB_FRAGS;
}
nr_slots = shinfo->nr_frags;
start = (frag_get_pending_idx(&shinfo->frags[0]) == pending_idx);
for (shinfo->nr_frags = start; shinfo->nr_frags < nr_slots;
shinfo->nr_frags++, txp++, gop++) {
index = pending_index(queue->pending_cons++);
pending_idx = queue->pending_ring[index];
xenvif_tx_create_map_op(queue, pending_idx, txp, gop);
frag_set_pending_idx(&frags[shinfo->nr_frags], pending_idx);
}
if (frag_overflow) {
struct sk_buff *nskb = xenvif_alloc_skb(0);
if (unlikely(nskb == NULL)) {
if (net_ratelimit())
netdev_err(queue->vif->dev,
"Can't allocate the frag_list skb.\n");
return NULL;
}
shinfo = skb_shinfo(nskb);
frags = shinfo->frags;
for (shinfo->nr_frags = 0; shinfo->nr_frags < frag_overflow;
shinfo->nr_frags++, txp++, gop++) {
index = pending_index(queue->pending_cons++);
pending_idx = queue->pending_ring[index];
xenvif_tx_create_map_op(queue, pending_idx, txp, gop);
frag_set_pending_idx(&frags[shinfo->nr_frags],
pending_idx);
}
skb_shinfo(skb)->frag_list = nskb;
}
return gop;
}
static inline void xenvif_grant_handle_set(struct xenvif_queue *queue,
u16 pending_idx,
grant_handle_t handle)
{
if (unlikely(queue->grant_tx_handle[pending_idx] !=
NETBACK_INVALID_HANDLE)) {
netdev_err(queue->vif->dev,
"Trying to overwrite active handle! pending_idx: %x\n",
pending_idx);
BUG();
}
queue->grant_tx_handle[pending_idx] = handle;
}
static inline void xenvif_grant_handle_reset(struct xenvif_queue *queue,
u16 pending_idx)
{
if (unlikely(queue->grant_tx_handle[pending_idx] ==
NETBACK_INVALID_HANDLE)) {
netdev_err(queue->vif->dev,
"Trying to unmap invalid handle! pending_idx: %x\n",
pending_idx);
BUG();
}
queue->grant_tx_handle[pending_idx] = NETBACK_INVALID_HANDLE;
}
static int xenvif_tx_check_gop(struct xenvif_queue *queue,
struct sk_buff *skb,
struct gnttab_map_grant_ref **gopp_map,
struct gnttab_copy **gopp_copy)
{
struct gnttab_map_grant_ref *gop_map = *gopp_map;
u16 pending_idx = XENVIF_TX_CB(skb)->pending_idx;
struct skb_shared_info *shinfo = skb_shinfo(skb);
struct skb_shared_info *first_shinfo = NULL;
int nr_frags = shinfo->nr_frags;
const bool sharedslot = nr_frags &&
frag_get_pending_idx(&shinfo->frags[0]) == pending_idx;
int i, err;
err = (*gopp_copy)->status;
if (unlikely(err)) {
if (net_ratelimit())
netdev_dbg(queue->vif->dev,
"Grant copy of header failed! status: %d pending_idx: %u ref: %u\n",
(*gopp_copy)->status,
pending_idx,
(*gopp_copy)->source.u.ref);
if (!sharedslot)
xenvif_idx_release(queue, pending_idx,
XEN_NETIF_RSP_ERROR);
}
(*gopp_copy)++;
check_frags:
for (i = 0; i < nr_frags; i++, gop_map++) {
int j, newerr;
pending_idx = frag_get_pending_idx(&shinfo->frags[i]);
newerr = gop_map->status;
if (likely(!newerr)) {
xenvif_grant_handle_set(queue,
pending_idx,
gop_map->handle);
if (unlikely(err)) {
xenvif_idx_unmap(queue, pending_idx);
if (i == 0 && sharedslot)
xenvif_idx_release(queue, pending_idx,
XEN_NETIF_RSP_ERROR);
else
xenvif_idx_release(queue, pending_idx,
XEN_NETIF_RSP_OKAY);
}
continue;
}
if (net_ratelimit())
netdev_dbg(queue->vif->dev,
"Grant map of %d. frag failed! status: %d pending_idx: %u ref: %u\n",
i,
gop_map->status,
pending_idx,
gop_map->ref);
xenvif_idx_release(queue, pending_idx, XEN_NETIF_RSP_ERROR);
if (err)
continue;
if (!sharedslot)
xenvif_idx_release(queue,
XENVIF_TX_CB(skb)->pending_idx,
XEN_NETIF_RSP_OKAY);
for (j = 0; j < i; j++) {
pending_idx = frag_get_pending_idx(&shinfo->frags[j]);
xenvif_idx_unmap(queue, pending_idx);
xenvif_idx_release(queue, pending_idx,
XEN_NETIF_RSP_OKAY);
}
if (first_shinfo) {
for (j = 0; j < first_shinfo->nr_frags; j++) {
pending_idx = frag_get_pending_idx(&first_shinfo->frags[j]);
xenvif_idx_unmap(queue, pending_idx);
xenvif_idx_release(queue, pending_idx,
XEN_NETIF_RSP_OKAY);
}
}
err = newerr;
}
if (skb_has_frag_list(skb) && !first_shinfo) {
first_shinfo = skb_shinfo(skb);
shinfo = skb_shinfo(skb_shinfo(skb)->frag_list);
nr_frags = shinfo->nr_frags;
goto check_frags;
}
*gopp_map = gop_map;
return err;
}
static void xenvif_fill_frags(struct xenvif_queue *queue, struct sk_buff *skb)
{
struct skb_shared_info *shinfo = skb_shinfo(skb);
int nr_frags = shinfo->nr_frags;
int i;
u16 prev_pending_idx = INVALID_PENDING_IDX;
for (i = 0; i < nr_frags; i++) {
skb_frag_t *frag = shinfo->frags + i;
struct xen_netif_tx_request *txp;
struct page *page;
u16 pending_idx;
pending_idx = frag_get_pending_idx(frag);
if (prev_pending_idx == INVALID_PENDING_IDX)
skb_shinfo(skb)->destructor_arg =
&callback_param(queue, pending_idx);
else
callback_param(queue, prev_pending_idx).ctx =
&callback_param(queue, pending_idx);
callback_param(queue, pending_idx).ctx = NULL;
prev_pending_idx = pending_idx;
txp = &queue->pending_tx_info[pending_idx].req;
page = virt_to_page(idx_to_kaddr(queue, pending_idx));
__skb_fill_page_desc(skb, i, page, txp->offset, txp->size);
skb->len += txp->size;
skb->data_len += txp->size;
skb->truesize += txp->size;
get_page(queue->mmap_pages[pending_idx]);
}
skb->pfmemalloc = false;
}
static int xenvif_get_extras(struct xenvif_queue *queue,
struct xen_netif_extra_info *extras,
int work_to_do)
{
struct xen_netif_extra_info extra;
RING_IDX cons = queue->tx.req_cons;
do {
if (unlikely(work_to_do-- <= 0)) {
netdev_err(queue->vif->dev, "Missing extra info\n");
xenvif_fatal_tx_err(queue->vif);
return -EBADR;
}
memcpy(&extra, RING_GET_REQUEST(&queue->tx, cons),
sizeof(extra));
if (unlikely(!extra.type ||
extra.type >= XEN_NETIF_EXTRA_TYPE_MAX)) {
queue->tx.req_cons = ++cons;
netdev_err(queue->vif->dev,
"Invalid extra type: %d\n", extra.type);
xenvif_fatal_tx_err(queue->vif);
return -EINVAL;
}
memcpy(&extras[extra.type - 1], &extra, sizeof(extra));
queue->tx.req_cons = ++cons;
} while (extra.flags & XEN_NETIF_EXTRA_FLAG_MORE);
return work_to_do;
}
static int xenvif_set_skb_gso(struct xenvif *vif,
struct sk_buff *skb,
struct xen_netif_extra_info *gso)
{
if (!gso->u.gso.size) {
netdev_err(vif->dev, "GSO size must not be zero.\n");
xenvif_fatal_tx_err(vif);
return -EINVAL;
}
switch (gso->u.gso.type) {
case XEN_NETIF_GSO_TYPE_TCPV4:
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV4;
break;
case XEN_NETIF_GSO_TYPE_TCPV6:
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV6;
break;
default:
netdev_err(vif->dev, "Bad GSO type %d.\n", gso->u.gso.type);
xenvif_fatal_tx_err(vif);
return -EINVAL;
}
skb_shinfo(skb)->gso_size = gso->u.gso.size;
return 0;
}
static int checksum_setup(struct xenvif_queue *queue, struct sk_buff *skb)
{
bool recalculate_partial_csum = false;
if (skb->ip_summed != CHECKSUM_PARTIAL && skb_is_gso(skb)) {
queue->stats.rx_gso_checksum_fixup++;
skb->ip_summed = CHECKSUM_PARTIAL;
recalculate_partial_csum = true;
}
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
return skb_checksum_setup(skb, recalculate_partial_csum);
}
static bool tx_credit_exceeded(struct xenvif_queue *queue, unsigned size)
{
u64 now = get_jiffies_64();
u64 next_credit = queue->credit_window_start +
msecs_to_jiffies(queue->credit_usec / 1000);
if (timer_pending(&queue->credit_timeout))
return true;
if (time_after_eq64(now, next_credit)) {
queue->credit_window_start = now;
tx_add_credit(queue);
}
if (size > queue->remaining_credit) {
queue->credit_timeout.data =
(unsigned long)queue;
queue->credit_timeout.function =
tx_credit_callback;
mod_timer(&queue->credit_timeout,
next_credit);
queue->credit_window_start = next_credit;
return true;
}
return false;
}
static void xenvif_tx_build_gops(struct xenvif_queue *queue,
int budget,
unsigned *copy_ops,
unsigned *map_ops)
{
struct gnttab_map_grant_ref *gop = queue->tx_map_ops, *request_gop;
struct sk_buff *skb;
int ret;
while (skb_queue_len(&queue->tx_queue) < budget) {
struct xen_netif_tx_request txreq;
struct xen_netif_tx_request txfrags[XEN_NETBK_LEGACY_SLOTS_MAX];
struct xen_netif_extra_info extras[XEN_NETIF_EXTRA_TYPE_MAX-1];
u16 pending_idx;
RING_IDX idx;
int work_to_do;
unsigned int data_len;
pending_ring_idx_t index;
if (queue->tx.sring->req_prod - queue->tx.req_cons >
XEN_NETIF_TX_RING_SIZE) {
netdev_err(queue->vif->dev,
"Impossible number of requests. "
"req_prod %d, req_cons %d, size %ld\n",
queue->tx.sring->req_prod, queue->tx.req_cons,
XEN_NETIF_TX_RING_SIZE);
xenvif_fatal_tx_err(queue->vif);
break;
}
work_to_do = RING_HAS_UNCONSUMED_REQUESTS(&queue->tx);
if (!work_to_do)
break;
idx = queue->tx.req_cons;
rmb();
memcpy(&txreq, RING_GET_REQUEST(&queue->tx, idx), sizeof(txreq));
if (txreq.size > queue->remaining_credit &&
tx_credit_exceeded(queue, txreq.size))
break;
queue->remaining_credit -= txreq.size;
work_to_do--;
queue->tx.req_cons = ++idx;
memset(extras, 0, sizeof(extras));
if (txreq.flags & XEN_NETTXF_extra_info) {
work_to_do = xenvif_get_extras(queue, extras,
work_to_do);
idx = queue->tx.req_cons;
if (unlikely(work_to_do < 0))
break;
}
ret = xenvif_count_requests(queue, &txreq, txfrags, work_to_do);
if (unlikely(ret < 0))
break;
idx += ret;
if (unlikely(txreq.size < ETH_HLEN)) {
netdev_dbg(queue->vif->dev,
"Bad packet size: %d\n", txreq.size);
xenvif_tx_err(queue, &txreq, idx);
break;
}
if (unlikely((txreq.offset + txreq.size) > PAGE_SIZE)) {
netdev_err(queue->vif->dev,
"txreq.offset: %x, size: %u, end: %lu\n",
txreq.offset, txreq.size,
(txreq.offset&~PAGE_MASK) + txreq.size);
xenvif_fatal_tx_err(queue->vif);
break;
}
index = pending_index(queue->pending_cons);
pending_idx = queue->pending_ring[index];
data_len = (txreq.size > PKT_PROT_LEN &&
ret < XEN_NETBK_LEGACY_SLOTS_MAX) ?
PKT_PROT_LEN : txreq.size;
skb = xenvif_alloc_skb(data_len);
if (unlikely(skb == NULL)) {
netdev_dbg(queue->vif->dev,
"Can't allocate a skb in start_xmit.\n");
xenvif_tx_err(queue, &txreq, idx);
break;
}
if (extras[XEN_NETIF_EXTRA_TYPE_GSO - 1].type) {
struct xen_netif_extra_info *gso;
gso = &extras[XEN_NETIF_EXTRA_TYPE_GSO - 1];
if (xenvif_set_skb_gso(queue->vif, skb, gso)) {
kfree_skb(skb);
break;
}
}
XENVIF_TX_CB(skb)->pending_idx = pending_idx;
__skb_put(skb, data_len);
queue->tx_copy_ops[*copy_ops].source.u.ref = txreq.gref;
queue->tx_copy_ops[*copy_ops].source.domid = queue->vif->domid;
queue->tx_copy_ops[*copy_ops].source.offset = txreq.offset;
queue->tx_copy_ops[*copy_ops].dest.u.gmfn =
virt_to_mfn(skb->data);
queue->tx_copy_ops[*copy_ops].dest.domid = DOMID_SELF;
queue->tx_copy_ops[*copy_ops].dest.offset =
offset_in_page(skb->data);
queue->tx_copy_ops[*copy_ops].len = data_len;
queue->tx_copy_ops[*copy_ops].flags = GNTCOPY_source_gref;
(*copy_ops)++;
skb_shinfo(skb)->nr_frags = ret;
if (data_len < txreq.size) {
skb_shinfo(skb)->nr_frags++;
frag_set_pending_idx(&skb_shinfo(skb)->frags[0],
pending_idx);
xenvif_tx_create_map_op(queue, pending_idx, &txreq, gop);
gop++;
} else {
frag_set_pending_idx(&skb_shinfo(skb)->frags[0],
INVALID_PENDING_IDX);
memcpy(&queue->pending_tx_info[pending_idx].req, &txreq,
sizeof(txreq));
}
queue->pending_cons++;
request_gop = xenvif_get_requests(queue, skb, txfrags, gop);
if (request_gop == NULL) {
kfree_skb(skb);
xenvif_tx_err(queue, &txreq, idx);
break;
}
gop = request_gop;
__skb_queue_tail(&queue->tx_queue, skb);
queue->tx.req_cons = idx;
if (((gop-queue->tx_map_ops) >= ARRAY_SIZE(queue->tx_map_ops)) ||
(*copy_ops >= ARRAY_SIZE(queue->tx_copy_ops)))
break;
}
(*map_ops) = gop - queue->tx_map_ops;
return;
}
static int xenvif_handle_frag_list(struct xenvif_queue *queue, struct sk_buff *skb)
{
unsigned int offset = skb_headlen(skb);
skb_frag_t frags[MAX_SKB_FRAGS];
int i;
struct ubuf_info *uarg;
struct sk_buff *nskb = skb_shinfo(skb)->frag_list;
queue->stats.tx_zerocopy_sent += 2;
queue->stats.tx_frag_overflow++;
xenvif_fill_frags(queue, nskb);
skb->truesize -= skb->data_len;
skb->len += nskb->len;
skb->data_len += nskb->len;
for (i = 0; offset < skb->len; i++) {
struct page *page;
unsigned int len;
BUG_ON(i >= MAX_SKB_FRAGS);
page = alloc_page(GFP_ATOMIC|__GFP_COLD);
if (!page) {
int j;
skb->truesize += skb->data_len;
for (j = 0; j < i; j++)
put_page(frags[j].page.p);
return -ENOMEM;
}
if (offset + PAGE_SIZE < skb->len)
len = PAGE_SIZE;
else
len = skb->len - offset;
if (skb_copy_bits(skb, offset, page_address(page), len))
BUG();
offset += len;
frags[i].page.p = page;
frags[i].page_offset = 0;
skb_frag_size_set(&frags[i], len);
}
memcpy(skb_shinfo(skb)->frags,
frags,
i * sizeof(skb_frag_t));
skb_shinfo(skb)->nr_frags = i;
skb->truesize += i * PAGE_SIZE;
skb_frag_list_init(skb);
uarg = skb_shinfo(skb)->destructor_arg;
atomic_inc(&queue->inflight_packets);
uarg->callback(uarg, true);
skb_shinfo(skb)->destructor_arg = NULL;
xenvif_skb_zerocopy_prepare(queue, nskb);
kfree_skb(nskb);
return 0;
}
static int xenvif_tx_submit(struct xenvif_queue *queue)
{
struct gnttab_map_grant_ref *gop_map = queue->tx_map_ops;
struct gnttab_copy *gop_copy = queue->tx_copy_ops;
struct sk_buff *skb;
int work_done = 0;
while ((skb = __skb_dequeue(&queue->tx_queue)) != NULL) {
struct xen_netif_tx_request *txp;
u16 pending_idx;
unsigned data_len;
pending_idx = XENVIF_TX_CB(skb)->pending_idx;
txp = &queue->pending_tx_info[pending_idx].req;
if (unlikely(xenvif_tx_check_gop(queue, skb, &gop_map, &gop_copy))) {
skb_shinfo(skb)->nr_frags = 0;
if (skb_has_frag_list(skb)) {
struct sk_buff *nskb =
skb_shinfo(skb)->frag_list;
skb_shinfo(nskb)->nr_frags = 0;
}
kfree_skb(skb);
continue;
}
data_len = skb->len;
callback_param(queue, pending_idx).ctx = NULL;
if (data_len < txp->size) {
txp->offset += data_len;
txp->size -= data_len;
} else {
xenvif_idx_release(queue, pending_idx,
XEN_NETIF_RSP_OKAY);
}
if (txp->flags & XEN_NETTXF_csum_blank)
skb->ip_summed = CHECKSUM_PARTIAL;
else if (txp->flags & XEN_NETTXF_data_validated)
skb->ip_summed = CHECKSUM_UNNECESSARY;
xenvif_fill_frags(queue, skb);
if (unlikely(skb_has_frag_list(skb))) {
if (xenvif_handle_frag_list(queue, skb)) {
if (net_ratelimit())
netdev_err(queue->vif->dev,
"Not enough memory to consolidate frag_list!\n");
xenvif_skb_zerocopy_prepare(queue, skb);
kfree_skb(skb);
continue;
}
}
if (skb_is_nonlinear(skb) && skb_headlen(skb) < PKT_PROT_LEN) {
int target = min_t(int, skb->len, PKT_PROT_LEN);
__pskb_pull_tail(skb, target - skb_headlen(skb));
}
skb->dev = queue->vif->dev;
skb->protocol = eth_type_trans(skb, skb->dev);
skb_reset_network_header(skb);
if (checksum_setup(queue, skb)) {
netdev_dbg(queue->vif->dev,
"Can't setup checksum in net_tx_action\n");
if (skb_shinfo(skb)->destructor_arg)
xenvif_skb_zerocopy_prepare(queue, skb);
kfree_skb(skb);
continue;
}
skb_probe_transport_header(skb, 0);
if (skb_is_gso(skb)) {
int mss = skb_shinfo(skb)->gso_size;
int hdrlen = skb_transport_header(skb) -
skb_mac_header(skb) +
tcp_hdrlen(skb);
skb_shinfo(skb)->gso_segs =
DIV_ROUND_UP(skb->len - hdrlen, mss);
}
queue->stats.rx_bytes += skb->len;
queue->stats.rx_packets++;
work_done++;
if (skb_shinfo(skb)->destructor_arg) {
xenvif_skb_zerocopy_prepare(queue, skb);
queue->stats.tx_zerocopy_sent++;
}
netif_receive_skb(skb);
}
return work_done;
}
void xenvif_zerocopy_callback(struct ubuf_info *ubuf, bool zerocopy_success)
{
unsigned long flags;
pending_ring_idx_t index;
struct xenvif_queue *queue = ubuf_to_queue(ubuf);
spin_lock_irqsave(&queue->callback_lock, flags);
do {
u16 pending_idx = ubuf->desc;
ubuf = (struct ubuf_info *) ubuf->ctx;
BUG_ON(queue->dealloc_prod - queue->dealloc_cons >=
MAX_PENDING_REQS);
index = pending_index(queue->dealloc_prod);
queue->dealloc_ring[index] = pending_idx;
smp_wmb();
queue->dealloc_prod++;
} while (ubuf);
wake_up(&queue->dealloc_wq);
spin_unlock_irqrestore(&queue->callback_lock, flags);
if (likely(zerocopy_success))
queue->stats.tx_zerocopy_success++;
else
queue->stats.tx_zerocopy_fail++;
xenvif_skb_zerocopy_complete(queue);
}
static inline void xenvif_tx_dealloc_action(struct xenvif_queue *queue)
{
struct gnttab_unmap_grant_ref *gop;
pending_ring_idx_t dc, dp;
u16 pending_idx, pending_idx_release[MAX_PENDING_REQS];
unsigned int i = 0;
dc = queue->dealloc_cons;
gop = queue->tx_unmap_ops;
do {
dp = queue->dealloc_prod;
smp_rmb();
while (dc != dp) {
BUG_ON(gop - queue->tx_unmap_ops > MAX_PENDING_REQS);
pending_idx =
queue->dealloc_ring[pending_index(dc++)];
pending_idx_release[gop-queue->tx_unmap_ops] =
pending_idx;
queue->pages_to_unmap[gop-queue->tx_unmap_ops] =
queue->mmap_pages[pending_idx];
gnttab_set_unmap_op(gop,
idx_to_kaddr(queue, pending_idx),
GNTMAP_host_map,
queue->grant_tx_handle[pending_idx]);
xenvif_grant_handle_reset(queue, pending_idx);
++gop;
}
} while (dp != queue->dealloc_prod);
queue->dealloc_cons = dc;
if (gop - queue->tx_unmap_ops > 0) {
int ret;
ret = gnttab_unmap_refs(queue->tx_unmap_ops,
NULL,
queue->pages_to_unmap,
gop - queue->tx_unmap_ops);
if (ret) {
netdev_err(queue->vif->dev, "Unmap fail: nr_ops %tx ret %d\n",
gop - queue->tx_unmap_ops, ret);
for (i = 0; i < gop - queue->tx_unmap_ops; ++i) {
if (gop[i].status != GNTST_okay)
netdev_err(queue->vif->dev,
" host_addr: %llx handle: %x status: %d\n",
gop[i].host_addr,
gop[i].handle,
gop[i].status);
}
BUG();
}
}
for (i = 0; i < gop - queue->tx_unmap_ops; ++i)
xenvif_idx_release(queue, pending_idx_release[i],
XEN_NETIF_RSP_OKAY);
}
int xenvif_tx_action(struct xenvif_queue *queue, int budget)
{
unsigned nr_mops, nr_cops = 0;
int work_done, ret;
if (unlikely(!tx_work_todo(queue)))
return 0;
xenvif_tx_build_gops(queue, budget, &nr_cops, &nr_mops);
if (nr_cops == 0)
return 0;
gnttab_batch_copy(queue->tx_copy_ops, nr_cops);
if (nr_mops != 0) {
ret = gnttab_map_refs(queue->tx_map_ops,
NULL,
queue->pages_to_map,
nr_mops);
BUG_ON(ret);
}
work_done = xenvif_tx_submit(queue);
return work_done;
}
static void xenvif_idx_release(struct xenvif_queue *queue, u16 pending_idx,
u8 status)
{
struct pending_tx_info *pending_tx_info;
pending_ring_idx_t index;
unsigned long flags;
pending_tx_info = &queue->pending_tx_info[pending_idx];
spin_lock_irqsave(&queue->response_lock, flags);
make_tx_response(queue, &pending_tx_info->req, status);
index = pending_index(queue->pending_prod);
queue->pending_ring[index] = pending_idx;
mb();
queue->pending_prod++;
spin_unlock_irqrestore(&queue->response_lock, flags);
}
static void make_tx_response(struct xenvif_queue *queue,
struct xen_netif_tx_request *txp,
s8 st)
{
RING_IDX i = queue->tx.rsp_prod_pvt;
struct xen_netif_tx_response *resp;
int notify;
resp = RING_GET_RESPONSE(&queue->tx, i);
resp->id = txp->id;
resp->status = st;
if (txp->flags & XEN_NETTXF_extra_info)
RING_GET_RESPONSE(&queue->tx, ++i)->status = XEN_NETIF_RSP_NULL;
queue->tx.rsp_prod_pvt = ++i;
RING_PUSH_RESPONSES_AND_CHECK_NOTIFY(&queue->tx, notify);
if (notify)
notify_remote_via_irq(queue->tx_irq);
}
static struct xen_netif_rx_response *make_rx_response(struct xenvif_queue *queue,
u16 id,
s8 st,
u16 offset,
u16 size,
u16 flags)
{
RING_IDX i = queue->rx.rsp_prod_pvt;
struct xen_netif_rx_response *resp;
resp = RING_GET_RESPONSE(&queue->rx, i);
resp->offset = offset;
resp->flags = flags;
resp->id = id;
resp->status = (s16)size;
if (st < 0)
resp->status = (s16)st;
queue->rx.rsp_prod_pvt = ++i;
return resp;
}
void xenvif_idx_unmap(struct xenvif_queue *queue, u16 pending_idx)
{
int ret;
struct gnttab_unmap_grant_ref tx_unmap_op;
gnttab_set_unmap_op(&tx_unmap_op,
idx_to_kaddr(queue, pending_idx),
GNTMAP_host_map,
queue->grant_tx_handle[pending_idx]);
xenvif_grant_handle_reset(queue, pending_idx);
ret = gnttab_unmap_refs(&tx_unmap_op, NULL,
&queue->mmap_pages[pending_idx], 1);
if (ret) {
netdev_err(queue->vif->dev,
"Unmap fail: ret: %d pending_idx: %d host_addr: %llx handle: %x status: %d\n",
ret,
pending_idx,
tx_unmap_op.host_addr,
tx_unmap_op.handle,
tx_unmap_op.status);
BUG();
}
}
static inline int rx_work_todo(struct xenvif_queue *queue)
{
return (!skb_queue_empty(&queue->rx_queue) &&
xenvif_rx_ring_slots_available(queue, queue->rx_last_skb_slots));
}
static inline int tx_work_todo(struct xenvif_queue *queue)
{
if (likely(RING_HAS_UNCONSUMED_REQUESTS(&queue->tx)))
return 1;
return 0;
}
static inline bool tx_dealloc_work_todo(struct xenvif_queue *queue)
{
return queue->dealloc_cons != queue->dealloc_prod;
}
void xenvif_unmap_frontend_rings(struct xenvif_queue *queue)
{
if (queue->tx.sring)
xenbus_unmap_ring_vfree(xenvif_to_xenbus_device(queue->vif),
queue->tx.sring);
if (queue->rx.sring)
xenbus_unmap_ring_vfree(xenvif_to_xenbus_device(queue->vif),
queue->rx.sring);
}
int xenvif_map_frontend_rings(struct xenvif_queue *queue,
grant_ref_t tx_ring_ref,
grant_ref_t rx_ring_ref)
{
void *addr;
struct xen_netif_tx_sring *txs;
struct xen_netif_rx_sring *rxs;
int err = -ENOMEM;
err = xenbus_map_ring_valloc(xenvif_to_xenbus_device(queue->vif),
tx_ring_ref, &addr);
if (err)
goto err;
txs = (struct xen_netif_tx_sring *)addr;
BACK_RING_INIT(&queue->tx, txs, PAGE_SIZE);
err = xenbus_map_ring_valloc(xenvif_to_xenbus_device(queue->vif),
rx_ring_ref, &addr);
if (err)
goto err;
rxs = (struct xen_netif_rx_sring *)addr;
BACK_RING_INIT(&queue->rx, rxs, PAGE_SIZE);
return 0;
err:
xenvif_unmap_frontend_rings(queue);
return err;
}
static void xenvif_start_queue(struct xenvif_queue *queue)
{
if (xenvif_schedulable(queue->vif))
xenvif_wake_queue(queue);
}
static void xenvif_rx_purge_event(struct xenvif_queue *queue)
{
int needed = queue->rx_last_skb_slots ?
queue->rx_last_skb_slots : 1;
set_bit(QUEUE_STATUS_RX_STALLED, &queue->status);
if (!xenvif_rx_ring_slots_available(queue, needed)) {
rtnl_lock();
if (netif_carrier_ok(queue->vif->dev)) {
netif_carrier_off(queue->vif->dev);
skb_queue_purge(&queue->rx_queue);
queue->rx_last_skb_slots = 0;
if (net_ratelimit())
netdev_err(queue->vif->dev, "Carrier off due to lack of guest response on queue %d\n", queue->id);
} else {
skb_queue_purge(&queue->rx_queue);
queue->rx_last_skb_slots = 0;
}
rtnl_unlock();
} else if (!netif_carrier_ok(queue->vif->dev)) {
unsigned int num_queues = queue->vif->num_queues;
unsigned int i;
clear_bit(QUEUE_STATUS_RX_STALLED,
&queue->status);
rtnl_lock();
netif_carrier_on(queue->vif->dev);
netif_tx_wake_all_queues(queue->vif->dev);
rtnl_unlock();
for (i = 0; i < num_queues; i++) {
struct xenvif_queue *temp = &queue->vif->queues[i];
xenvif_napi_schedule_or_enable_events(temp);
}
if (net_ratelimit())
netdev_err(queue->vif->dev, "Carrier on again\n");
} else {
clear_bit(QUEUE_STATUS_RX_STALLED,
&queue->status);
del_timer_sync(&queue->rx_stalled);
xenvif_start_queue(queue);
}
}
int xenvif_kthread_guest_rx(void *data)
{
struct xenvif_queue *queue = data;
struct sk_buff *skb;
while (!kthread_should_stop()) {
wait_event_interruptible(queue->wq,
rx_work_todo(queue) ||
queue->vif->disabled ||
test_bit(QUEUE_STATUS_RX_PURGE_EVENT, &queue->status) ||
kthread_should_stop());
if (kthread_should_stop())
break;
if (unlikely(queue->vif->disabled && queue->id == 0)) {
xenvif_carrier_off(queue->vif);
} else if (unlikely(queue->vif->disabled)) {
skb_queue_purge(&queue->rx_queue);
queue->rx_last_skb_slots = 0;
} else if (unlikely(test_and_clear_bit(QUEUE_STATUS_RX_PURGE_EVENT,
&queue->status))) {
xenvif_rx_purge_event(queue);
} else if (!netif_carrier_ok(queue->vif->dev)) {
skb_queue_purge(&queue->rx_queue);
queue->rx_last_skb_slots = 0;
}
if (!skb_queue_empty(&queue->rx_queue))
xenvif_rx_action(queue);
cond_resched();
}
while ((skb = skb_dequeue(&queue->rx_queue)) != NULL)
dev_kfree_skb(skb);
return 0;
}
static bool xenvif_dealloc_kthread_should_stop(struct xenvif_queue *queue)
{
return kthread_should_stop() &&
!atomic_read(&queue->inflight_packets);
}
int xenvif_dealloc_kthread(void *data)
{
struct xenvif_queue *queue = data;
for (;;) {
wait_event_interruptible(queue->dealloc_wq,
tx_dealloc_work_todo(queue) ||
xenvif_dealloc_kthread_should_stop(queue));
if (xenvif_dealloc_kthread_should_stop(queue))
break;
xenvif_tx_dealloc_action(queue);
cond_resched();
}
if (tx_dealloc_work_todo(queue))
xenvif_tx_dealloc_action(queue);
return 0;
}
static int __init netback_init(void)
{
int rc = 0;
if (!xen_domain())
return -ENODEV;
xenvif_max_queues = num_online_cpus();
if (fatal_skb_slots < XEN_NETBK_LEGACY_SLOTS_MAX) {
pr_info("fatal_skb_slots too small (%d), bump it to XEN_NETBK_LEGACY_SLOTS_MAX (%d)\n",
fatal_skb_slots, XEN_NETBK_LEGACY_SLOTS_MAX);
fatal_skb_slots = XEN_NETBK_LEGACY_SLOTS_MAX;
}
rc = xenvif_xenbus_init();
if (rc)
goto failed_init;
rx_drain_timeout_jiffies = msecs_to_jiffies(rx_drain_timeout_msecs);
#ifdef CONFIG_DEBUG_FS
xen_netback_dbg_root = debugfs_create_dir("xen-netback", NULL);
if (IS_ERR_OR_NULL(xen_netback_dbg_root))
pr_warn("Init of debugfs returned %ld!\n",
PTR_ERR(xen_netback_dbg_root));
#endif
return 0;
failed_init:
return rc;
}
static void __exit netback_fini(void)
{
#ifdef CONFIG_DEBUG_FS
if (!IS_ERR_OR_NULL(xen_netback_dbg_root))
debugfs_remove_recursive(xen_netback_dbg_root);
#endif
xenvif_xenbus_fini();
}
