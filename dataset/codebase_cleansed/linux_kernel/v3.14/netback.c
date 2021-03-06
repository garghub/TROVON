static inline int pending_tx_is_head(struct xenvif *vif, RING_IDX idx)
{
return vif->pending_tx_info[idx].head != INVALID_PENDING_RING_IDX;
}
static inline unsigned long idx_to_pfn(struct xenvif *vif,
u16 idx)
{
return page_to_pfn(vif->mmap_pages[idx]);
}
static inline unsigned long idx_to_kaddr(struct xenvif *vif,
u16 idx)
{
return (unsigned long)pfn_to_kaddr(idx_to_pfn(vif, idx));
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
static inline pending_ring_idx_t nr_pending_reqs(struct xenvif *vif)
{
return MAX_PENDING_REQS -
vif->pending_prod + vif->pending_cons;
}
bool xenvif_rx_ring_slots_available(struct xenvif *vif, int needed)
{
RING_IDX prod, cons;
do {
prod = vif->rx.sring->req_prod;
cons = vif->rx.req_cons;
if (prod - cons >= needed)
return true;
vif->rx.sring->req_event = prod + 1;
mb();
} while (vif->rx.sring->req_prod != prod);
return false;
}
static bool start_new_rx_buffer(int offset, unsigned long size, int head)
{
if (offset == MAX_BUFFER_OFFSET)
return true;
if ((offset + size > MAX_BUFFER_OFFSET) &&
(size <= MAX_BUFFER_OFFSET) && offset && !head)
return true;
return false;
}
static struct xenvif_rx_meta *get_next_rx_buffer(struct xenvif *vif,
struct netrx_pending_operations *npo)
{
struct xenvif_rx_meta *meta;
struct xen_netif_rx_request *req;
req = RING_GET_REQUEST(&vif->rx, vif->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
meta->gso_type = XEN_NETIF_GSO_TYPE_NONE;
meta->gso_size = 0;
meta->size = 0;
meta->id = req->id;
npo->copy_off = 0;
npo->copy_gref = req->gref;
return meta;
}
static void xenvif_gop_frag_copy(struct xenvif *vif, struct sk_buff *skb,
struct netrx_pending_operations *npo,
struct page *page, unsigned long size,
unsigned long offset, int *head)
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
if (start_new_rx_buffer(npo->copy_off, bytes, *head)) {
BUG_ON(*head);
meta = get_next_rx_buffer(vif, npo);
}
if (npo->copy_off + bytes > MAX_BUFFER_OFFSET)
bytes = MAX_BUFFER_OFFSET - npo->copy_off;
copy_gop = npo->copy + npo->copy_prod++;
copy_gop->flags = GNTCOPY_dest_gref;
copy_gop->len = bytes;
copy_gop->source.domid = DOMID_SELF;
copy_gop->source.u.gmfn = virt_to_mfn(page_address(page));
copy_gop->source.offset = offset;
copy_gop->dest.domid = vif->domid;
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
if (*head && ((1 << gso_type) & vif->gso_mask))
vif->rx.req_cons++;
*head = 0;
}
}
static int xenvif_gop_skb(struct sk_buff *skb,
struct netrx_pending_operations *npo)
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
old_meta_prod = npo->meta_prod;
gso_type = XEN_NETIF_GSO_TYPE_NONE;
if (skb_is_gso(skb)) {
if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4)
gso_type = XEN_NETIF_GSO_TYPE_TCPV4;
else if (skb_shinfo(skb)->gso_type & SKB_GSO_TCPV6)
gso_type = XEN_NETIF_GSO_TYPE_TCPV6;
}
if ((1 << gso_type) & vif->gso_prefix_mask) {
req = RING_GET_REQUEST(&vif->rx, vif->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
meta->gso_type = gso_type;
meta->gso_size = skb_shinfo(skb)->gso_size;
meta->size = 0;
meta->id = req->id;
}
req = RING_GET_REQUEST(&vif->rx, vif->rx.req_cons++);
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
xenvif_gop_frag_copy(vif, skb, npo,
virt_to_page(data), len, offset, &head);
data += len;
}
for (i = 0; i < nr_frags; i++) {
xenvif_gop_frag_copy(vif, skb, npo,
skb_frag_page(&skb_shinfo(skb)->frags[i]),
skb_frag_size(&skb_shinfo(skb)->frags[i]),
skb_shinfo(skb)->frags[i].page_offset,
&head);
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
static void xenvif_add_frag_responses(struct xenvif *vif, int status,
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
make_rx_response(vif, meta[i].id, status, offset,
meta[i].size, flags);
}
}
void xenvif_kick_thread(struct xenvif *vif)
{
wake_up(&vif->wq);
}
static void xenvif_rx_action(struct xenvif *vif)
{
s8 status;
u16 flags;
struct xen_netif_rx_response *resp;
struct sk_buff_head rxq;
struct sk_buff *skb;
LIST_HEAD(notify);
int ret;
unsigned long offset;
struct skb_cb_overlay *sco;
bool need_to_notify = false;
struct netrx_pending_operations npo = {
.copy = vif->grant_copy_op,
.meta = vif->meta,
};
skb_queue_head_init(&rxq);
while ((skb = skb_dequeue(&vif->rx_queue)) != NULL) {
RING_IDX max_slots_needed;
int i;
max_slots_needed = DIV_ROUND_UP(offset_in_page(skb->data) +
skb_headlen(skb),
PAGE_SIZE);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
unsigned int size;
size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
max_slots_needed += DIV_ROUND_UP(size, PAGE_SIZE);
}
if (skb_is_gso(skb) &&
(skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4 ||
skb_shinfo(skb)->gso_type & SKB_GSO_TCPV6))
max_slots_needed++;
if (!xenvif_rx_ring_slots_available(vif, max_slots_needed)) {
skb_queue_head(&vif->rx_queue, skb);
need_to_notify = true;
vif->rx_last_skb_slots = max_slots_needed;
break;
} else
vif->rx_last_skb_slots = 0;
sco = (struct skb_cb_overlay *)skb->cb;
sco->meta_slots_used = xenvif_gop_skb(skb, &npo);
BUG_ON(sco->meta_slots_used > max_slots_needed);
__skb_queue_tail(&rxq, skb);
}
BUG_ON(npo.meta_prod > ARRAY_SIZE(vif->meta));
if (!npo.copy_prod)
goto done;
BUG_ON(npo.copy_prod > MAX_GRANT_COPY_OPS);
gnttab_batch_copy(vif->grant_copy_op, npo.copy_prod);
while ((skb = __skb_dequeue(&rxq)) != NULL) {
sco = (struct skb_cb_overlay *)skb->cb;
if ((1 << vif->meta[npo.meta_cons].gso_type) &
vif->gso_prefix_mask) {
resp = RING_GET_RESPONSE(&vif->rx,
vif->rx.rsp_prod_pvt++);
resp->flags = XEN_NETRXF_gso_prefix | XEN_NETRXF_more_data;
resp->offset = vif->meta[npo.meta_cons].gso_size;
resp->id = vif->meta[npo.meta_cons].id;
resp->status = sco->meta_slots_used;
npo.meta_cons++;
sco->meta_slots_used--;
}
vif->dev->stats.tx_bytes += skb->len;
vif->dev->stats.tx_packets++;
status = xenvif_check_gop(vif, sco->meta_slots_used, &npo);
if (sco->meta_slots_used == 1)
flags = 0;
else
flags = XEN_NETRXF_more_data;
if (skb->ip_summed == CHECKSUM_PARTIAL)
flags |= XEN_NETRXF_csum_blank | XEN_NETRXF_data_validated;
else if (skb->ip_summed == CHECKSUM_UNNECESSARY)
flags |= XEN_NETRXF_data_validated;
offset = 0;
resp = make_rx_response(vif, vif->meta[npo.meta_cons].id,
status, offset,
vif->meta[npo.meta_cons].size,
flags);
if ((1 << vif->meta[npo.meta_cons].gso_type) &
vif->gso_mask) {
struct xen_netif_extra_info *gso =
(struct xen_netif_extra_info *)
RING_GET_RESPONSE(&vif->rx,
vif->rx.rsp_prod_pvt++);
resp->flags |= XEN_NETRXF_extra_info;
gso->u.gso.type = vif->meta[npo.meta_cons].gso_type;
gso->u.gso.size = vif->meta[npo.meta_cons].gso_size;
gso->u.gso.pad = 0;
gso->u.gso.features = 0;
gso->type = XEN_NETIF_EXTRA_TYPE_GSO;
gso->flags = 0;
}
xenvif_add_frag_responses(vif, status,
vif->meta + npo.meta_cons + 1,
sco->meta_slots_used);
RING_PUSH_RESPONSES_AND_CHECK_NOTIFY(&vif->rx, ret);
need_to_notify |= !!ret;
npo.meta_cons += sco->meta_slots_used;
dev_kfree_skb(skb);
}
done:
if (need_to_notify)
notify_remote_via_irq(vif->rx_irq);
}
void xenvif_check_rx_xenvif(struct xenvif *vif)
{
int more_to_do;
RING_FINAL_CHECK_FOR_REQUESTS(&vif->tx, more_to_do);
if (more_to_do)
napi_schedule(&vif->napi);
}
static void tx_add_credit(struct xenvif *vif)
{
unsigned long max_burst, max_credit;
max_burst = RING_GET_REQUEST(&vif->tx, vif->tx.req_cons)->size;
max_burst = min(max_burst, 131072UL);
max_burst = max(max_burst, vif->credit_bytes);
max_credit = vif->remaining_credit + vif->credit_bytes;
if (max_credit < vif->remaining_credit)
max_credit = ULONG_MAX;
vif->remaining_credit = min(max_credit, max_burst);
}
static void tx_credit_callback(unsigned long data)
{
struct xenvif *vif = (struct xenvif *)data;
tx_add_credit(vif);
xenvif_check_rx_xenvif(vif);
}
static void xenvif_tx_err(struct xenvif *vif,
struct xen_netif_tx_request *txp, RING_IDX end)
{
RING_IDX cons = vif->tx.req_cons;
do {
make_tx_response(vif, txp, XEN_NETIF_RSP_ERROR);
if (cons == end)
break;
txp = RING_GET_REQUEST(&vif->tx, cons++);
} while (1);
vif->tx.req_cons = cons;
}
static void xenvif_fatal_tx_err(struct xenvif *vif)
{
netdev_err(vif->dev, "fatal error; disabling device\n");
xenvif_carrier_off(vif);
}
static int xenvif_count_requests(struct xenvif *vif,
struct xen_netif_tx_request *first,
struct xen_netif_tx_request *txp,
int work_to_do)
{
RING_IDX cons = vif->tx.req_cons;
int slots = 0;
int drop_err = 0;
int more_data;
if (!(first->flags & XEN_NETTXF_more_data))
return 0;
do {
struct xen_netif_tx_request dropped_tx = { 0 };
if (slots >= work_to_do) {
netdev_err(vif->dev,
"Asked for %d slots but exceeds this limit\n",
work_to_do);
xenvif_fatal_tx_err(vif);
return -ENODATA;
}
if (unlikely(slots >= fatal_skb_slots)) {
netdev_err(vif->dev,
"Malicious frontend using %d slots, threshold %u\n",
slots, fatal_skb_slots);
xenvif_fatal_tx_err(vif);
return -E2BIG;
}
if (!drop_err && slots >= XEN_NETBK_LEGACY_SLOTS_MAX) {
if (net_ratelimit())
netdev_dbg(vif->dev,
"Too many slots (%d) exceeding limit (%d), dropping packet\n",
slots, XEN_NETBK_LEGACY_SLOTS_MAX);
drop_err = -E2BIG;
}
if (drop_err)
txp = &dropped_tx;
memcpy(txp, RING_GET_REQUEST(&vif->tx, cons + slots),
sizeof(*txp));
if (!drop_err && txp->size > first->size) {
if (net_ratelimit())
netdev_dbg(vif->dev,
"Invalid tx request, slot size %u > remaining size %u\n",
txp->size, first->size);
drop_err = -EIO;
}
first->size -= txp->size;
slots++;
if (unlikely((txp->offset + txp->size) > PAGE_SIZE)) {
netdev_err(vif->dev, "Cross page boundary, txp->offset: %x, size: %u\n",
txp->offset, txp->size);
xenvif_fatal_tx_err(vif);
return -EINVAL;
}
more_data = txp->flags & XEN_NETTXF_more_data;
if (!drop_err)
txp++;
} while (more_data);
if (drop_err) {
xenvif_tx_err(vif, first, cons + slots);
return drop_err;
}
return slots;
}
static struct page *xenvif_alloc_page(struct xenvif *vif,
u16 pending_idx)
{
struct page *page;
page = alloc_page(GFP_ATOMIC|__GFP_COLD);
if (!page)
return NULL;
vif->mmap_pages[pending_idx] = page;
return page;
}
static struct gnttab_copy *xenvif_get_requests(struct xenvif *vif,
struct sk_buff *skb,
struct xen_netif_tx_request *txp,
struct gnttab_copy *gop)
{
struct skb_shared_info *shinfo = skb_shinfo(skb);
skb_frag_t *frags = shinfo->frags;
u16 pending_idx = *((u16 *)skb->data);
u16 head_idx = 0;
int slot, start;
struct page *page;
pending_ring_idx_t index, start_idx = 0;
uint16_t dst_offset;
unsigned int nr_slots;
struct pending_tx_info *first = NULL;
nr_slots = shinfo->nr_frags;
start = (frag_get_pending_idx(&shinfo->frags[0]) == pending_idx);
for (shinfo->nr_frags = slot = start; slot < nr_slots;
shinfo->nr_frags++) {
struct pending_tx_info *pending_tx_info =
vif->pending_tx_info;
page = alloc_page(GFP_ATOMIC|__GFP_COLD);
if (!page)
goto err;
dst_offset = 0;
first = NULL;
while (dst_offset < PAGE_SIZE && slot < nr_slots) {
gop->flags = GNTCOPY_source_gref;
gop->source.u.ref = txp->gref;
gop->source.domid = vif->domid;
gop->source.offset = txp->offset;
gop->dest.domid = DOMID_SELF;
gop->dest.offset = dst_offset;
gop->dest.u.gmfn = virt_to_mfn(page_address(page));
if (dst_offset + txp->size > PAGE_SIZE) {
gop->len = PAGE_SIZE - dst_offset;
txp->offset += gop->len;
txp->size -= gop->len;
dst_offset += gop->len;
} else {
gop->len = txp->size;
dst_offset += gop->len;
index = pending_index(vif->pending_cons++);
pending_idx = vif->pending_ring[index];
memcpy(&pending_tx_info[pending_idx].req, txp,
sizeof(*txp));
vif->mmap_pages[pending_idx] = (void *)(~0UL);
pending_tx_info[pending_idx].head =
INVALID_PENDING_RING_IDX;
if (!first) {
first = &pending_tx_info[pending_idx];
start_idx = index;
head_idx = pending_idx;
}
txp++;
slot++;
}
gop++;
}
first->req.offset = 0;
first->req.size = dst_offset;
first->head = start_idx;
vif->mmap_pages[head_idx] = page;
frag_set_pending_idx(&frags[shinfo->nr_frags], head_idx);
}
BUG_ON(shinfo->nr_frags > MAX_SKB_FRAGS);
return gop;
err:
while (shinfo->nr_frags-- > start) {
xenvif_idx_release(vif,
frag_get_pending_idx(&frags[shinfo->nr_frags]),
XEN_NETIF_RSP_ERROR);
}
if (start)
xenvif_idx_release(vif, pending_idx, XEN_NETIF_RSP_ERROR);
return NULL;
}
static int xenvif_tx_check_gop(struct xenvif *vif,
struct sk_buff *skb,
struct gnttab_copy **gopp)
{
struct gnttab_copy *gop = *gopp;
u16 pending_idx = *((u16 *)skb->data);
struct skb_shared_info *shinfo = skb_shinfo(skb);
struct pending_tx_info *tx_info;
int nr_frags = shinfo->nr_frags;
int i, err, start;
u16 peek;
err = gop->status;
if (unlikely(err))
xenvif_idx_release(vif, pending_idx, XEN_NETIF_RSP_ERROR);
start = (frag_get_pending_idx(&shinfo->frags[0]) == pending_idx);
for (i = start; i < nr_frags; i++) {
int j, newerr;
pending_ring_idx_t head;
pending_idx = frag_get_pending_idx(&shinfo->frags[i]);
tx_info = &vif->pending_tx_info[pending_idx];
head = tx_info->head;
do {
newerr = (++gop)->status;
if (newerr)
break;
peek = vif->pending_ring[pending_index(++head)];
} while (!pending_tx_is_head(vif, peek));
if (likely(!newerr)) {
if (unlikely(err))
xenvif_idx_release(vif, pending_idx,
XEN_NETIF_RSP_OKAY);
continue;
}
xenvif_idx_release(vif, pending_idx, XEN_NETIF_RSP_ERROR);
if (err)
continue;
pending_idx = *((u16 *)skb->data);
xenvif_idx_release(vif, pending_idx, XEN_NETIF_RSP_OKAY);
for (j = start; j < i; j++) {
pending_idx = frag_get_pending_idx(&shinfo->frags[j]);
xenvif_idx_release(vif, pending_idx,
XEN_NETIF_RSP_OKAY);
}
err = newerr;
}
*gopp = gop + 1;
return err;
}
static void xenvif_fill_frags(struct xenvif *vif, struct sk_buff *skb)
{
struct skb_shared_info *shinfo = skb_shinfo(skb);
int nr_frags = shinfo->nr_frags;
int i;
for (i = 0; i < nr_frags; i++) {
skb_frag_t *frag = shinfo->frags + i;
struct xen_netif_tx_request *txp;
struct page *page;
u16 pending_idx;
pending_idx = frag_get_pending_idx(frag);
txp = &vif->pending_tx_info[pending_idx].req;
page = virt_to_page(idx_to_kaddr(vif, pending_idx));
__skb_fill_page_desc(skb, i, page, txp->offset, txp->size);
skb->len += txp->size;
skb->data_len += txp->size;
skb->truesize += txp->size;
get_page(vif->mmap_pages[pending_idx]);
xenvif_idx_release(vif, pending_idx, XEN_NETIF_RSP_OKAY);
}
}
static int xenvif_get_extras(struct xenvif *vif,
struct xen_netif_extra_info *extras,
int work_to_do)
{
struct xen_netif_extra_info extra;
RING_IDX cons = vif->tx.req_cons;
do {
if (unlikely(work_to_do-- <= 0)) {
netdev_err(vif->dev, "Missing extra info\n");
xenvif_fatal_tx_err(vif);
return -EBADR;
}
memcpy(&extra, RING_GET_REQUEST(&vif->tx, cons),
sizeof(extra));
if (unlikely(!extra.type ||
extra.type >= XEN_NETIF_EXTRA_TYPE_MAX)) {
vif->tx.req_cons = ++cons;
netdev_err(vif->dev,
"Invalid extra type: %d\n", extra.type);
xenvif_fatal_tx_err(vif);
return -EINVAL;
}
memcpy(&extras[extra.type - 1], &extra, sizeof(extra));
vif->tx.req_cons = ++cons;
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
static int checksum_setup(struct xenvif *vif, struct sk_buff *skb)
{
bool recalculate_partial_csum = false;
if (skb->ip_summed != CHECKSUM_PARTIAL && skb_is_gso(skb)) {
vif->rx_gso_checksum_fixup++;
skb->ip_summed = CHECKSUM_PARTIAL;
recalculate_partial_csum = true;
}
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
return skb_checksum_setup(skb, recalculate_partial_csum);
}
static bool tx_credit_exceeded(struct xenvif *vif, unsigned size)
{
u64 now = get_jiffies_64();
u64 next_credit = vif->credit_window_start +
msecs_to_jiffies(vif->credit_usec / 1000);
if (timer_pending(&vif->credit_timeout))
return true;
if (time_after_eq64(now, next_credit)) {
vif->credit_window_start = now;
tx_add_credit(vif);
}
if (size > vif->remaining_credit) {
vif->credit_timeout.data =
(unsigned long)vif;
vif->credit_timeout.function =
tx_credit_callback;
mod_timer(&vif->credit_timeout,
next_credit);
vif->credit_window_start = next_credit;
return true;
}
return false;
}
static unsigned xenvif_tx_build_gops(struct xenvif *vif, int budget)
{
struct gnttab_copy *gop = vif->tx_copy_ops, *request_gop;
struct sk_buff *skb;
int ret;
while ((nr_pending_reqs(vif) + XEN_NETBK_LEGACY_SLOTS_MAX
< MAX_PENDING_REQS) &&
(skb_queue_len(&vif->tx_queue) < budget)) {
struct xen_netif_tx_request txreq;
struct xen_netif_tx_request txfrags[XEN_NETBK_LEGACY_SLOTS_MAX];
struct page *page;
struct xen_netif_extra_info extras[XEN_NETIF_EXTRA_TYPE_MAX-1];
u16 pending_idx;
RING_IDX idx;
int work_to_do;
unsigned int data_len;
pending_ring_idx_t index;
if (vif->tx.sring->req_prod - vif->tx.req_cons >
XEN_NETIF_TX_RING_SIZE) {
netdev_err(vif->dev,
"Impossible number of requests. "
"req_prod %d, req_cons %d, size %ld\n",
vif->tx.sring->req_prod, vif->tx.req_cons,
XEN_NETIF_TX_RING_SIZE);
xenvif_fatal_tx_err(vif);
continue;
}
work_to_do = RING_HAS_UNCONSUMED_REQUESTS(&vif->tx);
if (!work_to_do)
break;
idx = vif->tx.req_cons;
rmb();
memcpy(&txreq, RING_GET_REQUEST(&vif->tx, idx), sizeof(txreq));
if (txreq.size > vif->remaining_credit &&
tx_credit_exceeded(vif, txreq.size))
break;
vif->remaining_credit -= txreq.size;
work_to_do--;
vif->tx.req_cons = ++idx;
memset(extras, 0, sizeof(extras));
if (txreq.flags & XEN_NETTXF_extra_info) {
work_to_do = xenvif_get_extras(vif, extras,
work_to_do);
idx = vif->tx.req_cons;
if (unlikely(work_to_do < 0))
break;
}
ret = xenvif_count_requests(vif, &txreq, txfrags, work_to_do);
if (unlikely(ret < 0))
break;
idx += ret;
if (unlikely(txreq.size < ETH_HLEN)) {
netdev_dbg(vif->dev,
"Bad packet size: %d\n", txreq.size);
xenvif_tx_err(vif, &txreq, idx);
break;
}
if (unlikely((txreq.offset + txreq.size) > PAGE_SIZE)) {
netdev_err(vif->dev,
"txreq.offset: %x, size: %u, end: %lu\n",
txreq.offset, txreq.size,
(txreq.offset&~PAGE_MASK) + txreq.size);
xenvif_fatal_tx_err(vif);
break;
}
index = pending_index(vif->pending_cons);
pending_idx = vif->pending_ring[index];
data_len = (txreq.size > PKT_PROT_LEN &&
ret < XEN_NETBK_LEGACY_SLOTS_MAX) ?
PKT_PROT_LEN : txreq.size;
skb = alloc_skb(data_len + NET_SKB_PAD + NET_IP_ALIGN,
GFP_ATOMIC | __GFP_NOWARN);
if (unlikely(skb == NULL)) {
netdev_dbg(vif->dev,
"Can't allocate a skb in start_xmit.\n");
xenvif_tx_err(vif, &txreq, idx);
break;
}
skb_reserve(skb, NET_SKB_PAD + NET_IP_ALIGN);
if (extras[XEN_NETIF_EXTRA_TYPE_GSO - 1].type) {
struct xen_netif_extra_info *gso;
gso = &extras[XEN_NETIF_EXTRA_TYPE_GSO - 1];
if (xenvif_set_skb_gso(vif, skb, gso)) {
kfree_skb(skb);
break;
}
}
page = xenvif_alloc_page(vif, pending_idx);
if (!page) {
kfree_skb(skb);
xenvif_tx_err(vif, &txreq, idx);
break;
}
gop->source.u.ref = txreq.gref;
gop->source.domid = vif->domid;
gop->source.offset = txreq.offset;
gop->dest.u.gmfn = virt_to_mfn(page_address(page));
gop->dest.domid = DOMID_SELF;
gop->dest.offset = txreq.offset;
gop->len = txreq.size;
gop->flags = GNTCOPY_source_gref;
gop++;
memcpy(&vif->pending_tx_info[pending_idx].req,
&txreq, sizeof(txreq));
vif->pending_tx_info[pending_idx].head = index;
*((u16 *)skb->data) = pending_idx;
__skb_put(skb, data_len);
skb_shinfo(skb)->nr_frags = ret;
if (data_len < txreq.size) {
skb_shinfo(skb)->nr_frags++;
frag_set_pending_idx(&skb_shinfo(skb)->frags[0],
pending_idx);
} else {
frag_set_pending_idx(&skb_shinfo(skb)->frags[0],
INVALID_PENDING_IDX);
}
vif->pending_cons++;
request_gop = xenvif_get_requests(vif, skb, txfrags, gop);
if (request_gop == NULL) {
kfree_skb(skb);
xenvif_tx_err(vif, &txreq, idx);
break;
}
gop = request_gop;
__skb_queue_tail(&vif->tx_queue, skb);
vif->tx.req_cons = idx;
if ((gop-vif->tx_copy_ops) >= ARRAY_SIZE(vif->tx_copy_ops))
break;
}
return gop - vif->tx_copy_ops;
}
static int xenvif_tx_submit(struct xenvif *vif)
{
struct gnttab_copy *gop = vif->tx_copy_ops;
struct sk_buff *skb;
int work_done = 0;
while ((skb = __skb_dequeue(&vif->tx_queue)) != NULL) {
struct xen_netif_tx_request *txp;
u16 pending_idx;
unsigned data_len;
pending_idx = *((u16 *)skb->data);
txp = &vif->pending_tx_info[pending_idx].req;
if (unlikely(xenvif_tx_check_gop(vif, skb, &gop))) {
netdev_dbg(vif->dev, "netback grant failed.\n");
skb_shinfo(skb)->nr_frags = 0;
kfree_skb(skb);
continue;
}
data_len = skb->len;
memcpy(skb->data,
(void *)(idx_to_kaddr(vif, pending_idx)|txp->offset),
data_len);
if (data_len < txp->size) {
txp->offset += data_len;
txp->size -= data_len;
} else {
xenvif_idx_release(vif, pending_idx,
XEN_NETIF_RSP_OKAY);
}
if (txp->flags & XEN_NETTXF_csum_blank)
skb->ip_summed = CHECKSUM_PARTIAL;
else if (txp->flags & XEN_NETTXF_data_validated)
skb->ip_summed = CHECKSUM_UNNECESSARY;
xenvif_fill_frags(vif, skb);
if (skb_is_nonlinear(skb) && skb_headlen(skb) < PKT_PROT_LEN) {
int target = min_t(int, skb->len, PKT_PROT_LEN);
__pskb_pull_tail(skb, target - skb_headlen(skb));
}
skb->dev = vif->dev;
skb->protocol = eth_type_trans(skb, skb->dev);
skb_reset_network_header(skb);
if (checksum_setup(vif, skb)) {
netdev_dbg(vif->dev,
"Can't setup checksum in net_tx_action\n");
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
vif->dev->stats.rx_bytes += skb->len;
vif->dev->stats.rx_packets++;
work_done++;
netif_receive_skb(skb);
}
return work_done;
}
int xenvif_tx_action(struct xenvif *vif, int budget)
{
unsigned nr_gops;
int work_done;
if (unlikely(!tx_work_todo(vif)))
return 0;
nr_gops = xenvif_tx_build_gops(vif, budget);
if (nr_gops == 0)
return 0;
gnttab_batch_copy(vif->tx_copy_ops, nr_gops);
work_done = xenvif_tx_submit(vif);
return work_done;
}
static void xenvif_idx_release(struct xenvif *vif, u16 pending_idx,
u8 status)
{
struct pending_tx_info *pending_tx_info;
pending_ring_idx_t head;
u16 peek;
BUG_ON(vif->mmap_pages[pending_idx] == (void *)(~0UL));
if (vif->mmap_pages[pending_idx] == NULL)
return;
pending_tx_info = &vif->pending_tx_info[pending_idx];
head = pending_tx_info->head;
BUG_ON(!pending_tx_is_head(vif, head));
BUG_ON(vif->pending_ring[pending_index(head)] != pending_idx);
do {
pending_ring_idx_t index;
pending_ring_idx_t idx = pending_index(head);
u16 info_idx = vif->pending_ring[idx];
pending_tx_info = &vif->pending_tx_info[info_idx];
make_tx_response(vif, &pending_tx_info->req, status);
pending_tx_info->head = 0;
index = pending_index(vif->pending_prod++);
vif->pending_ring[index] = vif->pending_ring[info_idx];
peek = vif->pending_ring[pending_index(++head)];
} while (!pending_tx_is_head(vif, peek));
put_page(vif->mmap_pages[pending_idx]);
vif->mmap_pages[pending_idx] = NULL;
}
static void make_tx_response(struct xenvif *vif,
struct xen_netif_tx_request *txp,
s8 st)
{
RING_IDX i = vif->tx.rsp_prod_pvt;
struct xen_netif_tx_response *resp;
int notify;
resp = RING_GET_RESPONSE(&vif->tx, i);
resp->id = txp->id;
resp->status = st;
if (txp->flags & XEN_NETTXF_extra_info)
RING_GET_RESPONSE(&vif->tx, ++i)->status = XEN_NETIF_RSP_NULL;
vif->tx.rsp_prod_pvt = ++i;
RING_PUSH_RESPONSES_AND_CHECK_NOTIFY(&vif->tx, notify);
if (notify)
notify_remote_via_irq(vif->tx_irq);
}
static struct xen_netif_rx_response *make_rx_response(struct xenvif *vif,
u16 id,
s8 st,
u16 offset,
u16 size,
u16 flags)
{
RING_IDX i = vif->rx.rsp_prod_pvt;
struct xen_netif_rx_response *resp;
resp = RING_GET_RESPONSE(&vif->rx, i);
resp->offset = offset;
resp->flags = flags;
resp->id = id;
resp->status = (s16)size;
if (st < 0)
resp->status = (s16)st;
vif->rx.rsp_prod_pvt = ++i;
return resp;
}
static inline int rx_work_todo(struct xenvif *vif)
{
return !skb_queue_empty(&vif->rx_queue) &&
xenvif_rx_ring_slots_available(vif, vif->rx_last_skb_slots);
}
static inline int tx_work_todo(struct xenvif *vif)
{
if (likely(RING_HAS_UNCONSUMED_REQUESTS(&vif->tx)) &&
(nr_pending_reqs(vif) + XEN_NETBK_LEGACY_SLOTS_MAX
< MAX_PENDING_REQS))
return 1;
return 0;
}
void xenvif_unmap_frontend_rings(struct xenvif *vif)
{
if (vif->tx.sring)
xenbus_unmap_ring_vfree(xenvif_to_xenbus_device(vif),
vif->tx.sring);
if (vif->rx.sring)
xenbus_unmap_ring_vfree(xenvif_to_xenbus_device(vif),
vif->rx.sring);
}
int xenvif_map_frontend_rings(struct xenvif *vif,
grant_ref_t tx_ring_ref,
grant_ref_t rx_ring_ref)
{
void *addr;
struct xen_netif_tx_sring *txs;
struct xen_netif_rx_sring *rxs;
int err = -ENOMEM;
err = xenbus_map_ring_valloc(xenvif_to_xenbus_device(vif),
tx_ring_ref, &addr);
if (err)
goto err;
txs = (struct xen_netif_tx_sring *)addr;
BACK_RING_INIT(&vif->tx, txs, PAGE_SIZE);
err = xenbus_map_ring_valloc(xenvif_to_xenbus_device(vif),
rx_ring_ref, &addr);
if (err)
goto err;
rxs = (struct xen_netif_rx_sring *)addr;
BACK_RING_INIT(&vif->rx, rxs, PAGE_SIZE);
return 0;
err:
xenvif_unmap_frontend_rings(vif);
return err;
}
void xenvif_stop_queue(struct xenvif *vif)
{
if (!vif->can_queue)
return;
netif_stop_queue(vif->dev);
}
static void xenvif_start_queue(struct xenvif *vif)
{
if (xenvif_schedulable(vif))
netif_wake_queue(vif->dev);
}
int xenvif_kthread(void *data)
{
struct xenvif *vif = data;
struct sk_buff *skb;
while (!kthread_should_stop()) {
wait_event_interruptible(vif->wq,
rx_work_todo(vif) ||
kthread_should_stop());
if (kthread_should_stop())
break;
if (!skb_queue_empty(&vif->rx_queue))
xenvif_rx_action(vif);
if (skb_queue_empty(&vif->rx_queue) &&
netif_queue_stopped(vif->dev))
xenvif_start_queue(vif);
cond_resched();
}
while ((skb = skb_dequeue(&vif->rx_queue)) != NULL)
dev_kfree_skb(skb);
return 0;
}
static int __init netback_init(void)
{
int rc = 0;
if (!xen_domain())
return -ENODEV;
if (fatal_skb_slots < XEN_NETBK_LEGACY_SLOTS_MAX) {
pr_info("fatal_skb_slots too small (%d), bump it to XEN_NETBK_LEGACY_SLOTS_MAX (%d)\n",
fatal_skb_slots, XEN_NETBK_LEGACY_SLOTS_MAX);
fatal_skb_slots = XEN_NETBK_LEGACY_SLOTS_MAX;
}
rc = xenvif_xenbus_init();
if (rc)
goto failed_init;
return 0;
failed_init:
return rc;
}
static void __exit netback_fini(void)
{
xenvif_xenbus_fini();
}
