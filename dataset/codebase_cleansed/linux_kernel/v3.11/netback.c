static inline int pending_tx_is_head(struct xen_netbk *netbk, RING_IDX idx)
{
return netbk->pending_tx_info[idx].head != INVALID_PENDING_RING_IDX;
}
void xen_netbk_add_xenvif(struct xenvif *vif)
{
int i;
int min_netfront_count;
int min_group = 0;
struct xen_netbk *netbk;
min_netfront_count = atomic_read(&xen_netbk[0].netfront_count);
for (i = 0; i < xen_netbk_group_nr; i++) {
int netfront_count = atomic_read(&xen_netbk[i].netfront_count);
if (netfront_count < min_netfront_count) {
min_group = i;
min_netfront_count = netfront_count;
}
}
netbk = &xen_netbk[min_group];
vif->netbk = netbk;
atomic_inc(&netbk->netfront_count);
}
void xen_netbk_remove_xenvif(struct xenvif *vif)
{
struct xen_netbk *netbk = vif->netbk;
vif->netbk = NULL;
atomic_dec(&netbk->netfront_count);
}
static inline unsigned long idx_to_pfn(struct xen_netbk *netbk,
u16 idx)
{
return page_to_pfn(netbk->mmap_pages[idx]);
}
static inline unsigned long idx_to_kaddr(struct xen_netbk *netbk,
u16 idx)
{
return (unsigned long)pfn_to_kaddr(idx_to_pfn(netbk, idx));
}
static inline void set_page_ext(struct page *pg, struct xen_netbk *netbk,
unsigned int idx)
{
unsigned int group = netbk - xen_netbk;
union page_ext ext = { .e = { .group = group + 1, .idx = idx } };
BUILD_BUG_ON(sizeof(ext) > sizeof(ext.mapping));
pg->mapping = ext.mapping;
}
static int get_page_ext(struct page *pg,
unsigned int *pgroup, unsigned int *pidx)
{
union page_ext ext = { .mapping = pg->mapping };
struct xen_netbk *netbk;
unsigned int group, idx;
group = ext.e.group - 1;
if (group < 0 || group >= xen_netbk_group_nr)
return 0;
netbk = &xen_netbk[group];
idx = ext.e.idx;
if ((idx < 0) || (idx >= MAX_PENDING_REQS))
return 0;
if (netbk->mmap_pages[idx] != pg)
return 0;
*pgroup = group;
*pidx = idx;
return 1;
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
static inline pending_ring_idx_t nr_pending_reqs(struct xen_netbk *netbk)
{
return MAX_PENDING_REQS -
netbk->pending_prod + netbk->pending_cons;
}
static void xen_netbk_kick_thread(struct xen_netbk *netbk)
{
wake_up(&netbk->wq);
}
static int max_required_rx_slots(struct xenvif *vif)
{
int max = DIV_ROUND_UP(vif->dev->mtu, PAGE_SIZE);
if (vif->can_sg || vif->gso || vif->gso_prefix)
max += MAX_SKB_FRAGS + 1;
return max;
}
int xen_netbk_rx_ring_full(struct xenvif *vif)
{
RING_IDX peek = vif->rx_req_cons_peek;
RING_IDX needed = max_required_rx_slots(vif);
return ((vif->rx.sring->req_prod - peek) < needed) ||
((vif->rx.rsp_prod_pvt + XEN_NETIF_RX_RING_SIZE - peek) < needed);
}
int xen_netbk_must_stop_queue(struct xenvif *vif)
{
if (!xen_netbk_rx_ring_full(vif))
return 0;
vif->rx.sring->req_event = vif->rx_req_cons_peek +
max_required_rx_slots(vif);
mb();
return xen_netbk_rx_ring_full(vif);
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
unsigned int xen_netbk_count_skb_slots(struct xenvif *vif, struct sk_buff *skb)
{
unsigned int count;
int i, copy_off;
count = DIV_ROUND_UP(skb_headlen(skb), PAGE_SIZE);
copy_off = skb_headlen(skb) % PAGE_SIZE;
if (skb_shinfo(skb)->gso_size)
count++;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
unsigned long size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
unsigned long offset = skb_shinfo(skb)->frags[i].page_offset;
unsigned long bytes;
offset &= ~PAGE_MASK;
while (size > 0) {
BUG_ON(offset >= PAGE_SIZE);
BUG_ON(copy_off > MAX_BUFFER_OFFSET);
bytes = PAGE_SIZE - offset;
if (bytes > size)
bytes = size;
if (start_new_rx_buffer(copy_off, bytes, 0)) {
count++;
copy_off = 0;
}
if (copy_off + bytes > MAX_BUFFER_OFFSET)
bytes = MAX_BUFFER_OFFSET - copy_off;
copy_off += bytes;
offset += bytes;
size -= bytes;
if (offset == PAGE_SIZE)
offset = 0;
}
}
return count;
}
static struct netbk_rx_meta *get_next_rx_buffer(struct xenvif *vif,
struct netrx_pending_operations *npo)
{
struct netbk_rx_meta *meta;
struct xen_netif_rx_request *req;
req = RING_GET_REQUEST(&vif->rx, vif->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
meta->gso_size = 0;
meta->size = 0;
meta->id = req->id;
npo->copy_off = 0;
npo->copy_gref = req->gref;
return meta;
}
static void netbk_gop_frag_copy(struct xenvif *vif, struct sk_buff *skb,
struct netrx_pending_operations *npo,
struct page *page, unsigned long size,
unsigned long offset, int *head)
{
struct gnttab_copy *copy_gop;
struct netbk_rx_meta *meta;
unsigned int uninitialized_var(group), uninitialized_var(idx);
int foreign = get_page_ext(page, &group, &idx);
unsigned long bytes;
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
if (foreign) {
struct xen_netbk *netbk = &xen_netbk[group];
struct pending_tx_info *src_pend;
src_pend = &netbk->pending_tx_info[idx];
copy_gop->source.domid = src_pend->vif->domid;
copy_gop->source.u.ref = src_pend->req.gref;
copy_gop->flags |= GNTCOPY_source_gref;
} else {
void *vaddr = page_address(page);
copy_gop->source.domid = DOMID_SELF;
copy_gop->source.u.gmfn = virt_to_mfn(vaddr);
}
copy_gop->source.offset = offset;
copy_gop->dest.domid = vif->domid;
copy_gop->dest.offset = npo->copy_off;
copy_gop->dest.u.ref = npo->copy_gref;
copy_gop->len = bytes;
npo->copy_off += bytes;
meta->size += bytes;
offset += bytes;
size -= bytes;
if (offset == PAGE_SIZE && size) {
BUG_ON(!PageCompound(page));
page++;
offset = 0;
}
if (*head && skb_shinfo(skb)->gso_size && !vif->gso_prefix)
vif->rx.req_cons++;
*head = 0;
}
}
static int netbk_gop_skb(struct sk_buff *skb,
struct netrx_pending_operations *npo)
{
struct xenvif *vif = netdev_priv(skb->dev);
int nr_frags = skb_shinfo(skb)->nr_frags;
int i;
struct xen_netif_rx_request *req;
struct netbk_rx_meta *meta;
unsigned char *data;
int head = 1;
int old_meta_prod;
old_meta_prod = npo->meta_prod;
if (skb_shinfo(skb)->gso_size && vif->gso_prefix) {
req = RING_GET_REQUEST(&vif->rx, vif->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
meta->gso_size = skb_shinfo(skb)->gso_size;
meta->size = 0;
meta->id = req->id;
}
req = RING_GET_REQUEST(&vif->rx, vif->rx.req_cons++);
meta = npo->meta + npo->meta_prod++;
if (!vif->gso_prefix)
meta->gso_size = skb_shinfo(skb)->gso_size;
else
meta->gso_size = 0;
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
netbk_gop_frag_copy(vif, skb, npo,
virt_to_page(data), len, offset, &head);
data += len;
}
for (i = 0; i < nr_frags; i++) {
netbk_gop_frag_copy(vif, skb, npo,
skb_frag_page(&skb_shinfo(skb)->frags[i]),
skb_frag_size(&skb_shinfo(skb)->frags[i]),
skb_shinfo(skb)->frags[i].page_offset,
&head);
}
return npo->meta_prod - old_meta_prod;
}
static int netbk_check_gop(struct xenvif *vif, int nr_meta_slots,
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
static void netbk_add_frag_responses(struct xenvif *vif, int status,
struct netbk_rx_meta *meta,
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
static void xen_netbk_rx_action(struct xen_netbk *netbk)
{
struct xenvif *vif = NULL, *tmp;
s8 status;
u16 flags;
struct xen_netif_rx_response *resp;
struct sk_buff_head rxq;
struct sk_buff *skb;
LIST_HEAD(notify);
int ret;
int nr_frags;
int count;
unsigned long offset;
struct skb_cb_overlay *sco;
struct netrx_pending_operations npo = {
.copy = netbk->grant_copy_op,
.meta = netbk->meta,
};
skb_queue_head_init(&rxq);
count = 0;
while ((skb = skb_dequeue(&netbk->rx_queue)) != NULL) {
vif = netdev_priv(skb->dev);
nr_frags = skb_shinfo(skb)->nr_frags;
sco = (struct skb_cb_overlay *)skb->cb;
sco->meta_slots_used = netbk_gop_skb(skb, &npo);
count += nr_frags + 1;
__skb_queue_tail(&rxq, skb);
if (count + MAX_SKB_FRAGS >= XEN_NETIF_RX_RING_SIZE)
break;
}
BUG_ON(npo.meta_prod > ARRAY_SIZE(netbk->meta));
if (!npo.copy_prod)
return;
BUG_ON(npo.copy_prod > ARRAY_SIZE(netbk->grant_copy_op));
gnttab_batch_copy(netbk->grant_copy_op, npo.copy_prod);
while ((skb = __skb_dequeue(&rxq)) != NULL) {
sco = (struct skb_cb_overlay *)skb->cb;
vif = netdev_priv(skb->dev);
if (netbk->meta[npo.meta_cons].gso_size && vif->gso_prefix) {
resp = RING_GET_RESPONSE(&vif->rx,
vif->rx.rsp_prod_pvt++);
resp->flags = XEN_NETRXF_gso_prefix | XEN_NETRXF_more_data;
resp->offset = netbk->meta[npo.meta_cons].gso_size;
resp->id = netbk->meta[npo.meta_cons].id;
resp->status = sco->meta_slots_used;
npo.meta_cons++;
sco->meta_slots_used--;
}
vif->dev->stats.tx_bytes += skb->len;
vif->dev->stats.tx_packets++;
status = netbk_check_gop(vif, sco->meta_slots_used, &npo);
if (sco->meta_slots_used == 1)
flags = 0;
else
flags = XEN_NETRXF_more_data;
if (skb->ip_summed == CHECKSUM_PARTIAL)
flags |= XEN_NETRXF_csum_blank | XEN_NETRXF_data_validated;
else if (skb->ip_summed == CHECKSUM_UNNECESSARY)
flags |= XEN_NETRXF_data_validated;
offset = 0;
resp = make_rx_response(vif, netbk->meta[npo.meta_cons].id,
status, offset,
netbk->meta[npo.meta_cons].size,
flags);
if (netbk->meta[npo.meta_cons].gso_size && !vif->gso_prefix) {
struct xen_netif_extra_info *gso =
(struct xen_netif_extra_info *)
RING_GET_RESPONSE(&vif->rx,
vif->rx.rsp_prod_pvt++);
resp->flags |= XEN_NETRXF_extra_info;
gso->u.gso.size = netbk->meta[npo.meta_cons].gso_size;
gso->u.gso.type = XEN_NETIF_GSO_TYPE_TCPV4;
gso->u.gso.pad = 0;
gso->u.gso.features = 0;
gso->type = XEN_NETIF_EXTRA_TYPE_GSO;
gso->flags = 0;
}
netbk_add_frag_responses(vif, status,
netbk->meta + npo.meta_cons + 1,
sco->meta_slots_used);
RING_PUSH_RESPONSES_AND_CHECK_NOTIFY(&vif->rx, ret);
xenvif_notify_tx_completion(vif);
if (ret && list_empty(&vif->notify_list))
list_add_tail(&vif->notify_list, &notify);
else
xenvif_put(vif);
npo.meta_cons += sco->meta_slots_used;
dev_kfree_skb(skb);
}
list_for_each_entry_safe(vif, tmp, &notify, notify_list) {
notify_remote_via_irq(vif->rx_irq);
list_del_init(&vif->notify_list);
xenvif_put(vif);
}
if (!skb_queue_empty(&netbk->rx_queue) &&
!timer_pending(&netbk->net_timer))
xen_netbk_kick_thread(netbk);
}
void xen_netbk_queue_tx_skb(struct xenvif *vif, struct sk_buff *skb)
{
struct xen_netbk *netbk = vif->netbk;
skb_queue_tail(&netbk->rx_queue, skb);
xen_netbk_kick_thread(netbk);
}
static void xen_netbk_alarm(unsigned long data)
{
struct xen_netbk *netbk = (struct xen_netbk *)data;
xen_netbk_kick_thread(netbk);
}
static int __on_net_schedule_list(struct xenvif *vif)
{
return !list_empty(&vif->schedule_list);
}
static void remove_from_net_schedule_list(struct xenvif *vif)
{
if (likely(__on_net_schedule_list(vif))) {
list_del_init(&vif->schedule_list);
xenvif_put(vif);
}
}
static struct xenvif *poll_net_schedule_list(struct xen_netbk *netbk)
{
struct xenvif *vif = NULL;
spin_lock_irq(&netbk->net_schedule_list_lock);
if (list_empty(&netbk->net_schedule_list))
goto out;
vif = list_first_entry(&netbk->net_schedule_list,
struct xenvif, schedule_list);
if (!vif)
goto out;
xenvif_get(vif);
remove_from_net_schedule_list(vif);
out:
spin_unlock_irq(&netbk->net_schedule_list_lock);
return vif;
}
void xen_netbk_schedule_xenvif(struct xenvif *vif)
{
unsigned long flags;
struct xen_netbk *netbk = vif->netbk;
if (__on_net_schedule_list(vif))
goto kick;
spin_lock_irqsave(&netbk->net_schedule_list_lock, flags);
if (!__on_net_schedule_list(vif) &&
likely(xenvif_schedulable(vif))) {
list_add_tail(&vif->schedule_list, &netbk->net_schedule_list);
xenvif_get(vif);
}
spin_unlock_irqrestore(&netbk->net_schedule_list_lock, flags);
kick:
smp_mb();
if ((nr_pending_reqs(netbk) < (MAX_PENDING_REQS/2)) &&
!list_empty(&netbk->net_schedule_list))
xen_netbk_kick_thread(netbk);
}
void xen_netbk_deschedule_xenvif(struct xenvif *vif)
{
struct xen_netbk *netbk = vif->netbk;
spin_lock_irq(&netbk->net_schedule_list_lock);
remove_from_net_schedule_list(vif);
spin_unlock_irq(&netbk->net_schedule_list_lock);
}
void xen_netbk_check_rx_xenvif(struct xenvif *vif)
{
int more_to_do;
RING_FINAL_CHECK_FOR_REQUESTS(&vif->tx, more_to_do);
if (more_to_do)
xen_netbk_schedule_xenvif(vif);
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
xen_netbk_check_rx_xenvif(vif);
}
static void netbk_tx_err(struct xenvif *vif,
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
xen_netbk_check_rx_xenvif(vif);
xenvif_put(vif);
}
static void netbk_fatal_tx_err(struct xenvif *vif)
{
netdev_err(vif->dev, "fatal error; disabling device\n");
xenvif_carrier_off(vif);
xenvif_put(vif);
}
static int netbk_count_requests(struct xenvif *vif,
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
netbk_fatal_tx_err(vif);
return -ENODATA;
}
if (unlikely(slots >= fatal_skb_slots)) {
netdev_err(vif->dev,
"Malicious frontend using %d slots, threshold %u\n",
slots, fatal_skb_slots);
netbk_fatal_tx_err(vif);
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
netbk_fatal_tx_err(vif);
return -EINVAL;
}
more_data = txp->flags & XEN_NETTXF_more_data;
if (!drop_err)
txp++;
} while (more_data);
if (drop_err) {
netbk_tx_err(vif, first, cons + slots);
return drop_err;
}
return slots;
}
static struct page *xen_netbk_alloc_page(struct xen_netbk *netbk,
u16 pending_idx)
{
struct page *page;
page = alloc_page(GFP_KERNEL|__GFP_COLD);
if (!page)
return NULL;
set_page_ext(page, netbk, pending_idx);
netbk->mmap_pages[pending_idx] = page;
return page;
}
static struct gnttab_copy *xen_netbk_get_requests(struct xen_netbk *netbk,
struct xenvif *vif,
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
netbk->pending_tx_info;
page = alloc_page(GFP_KERNEL|__GFP_COLD);
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
index = pending_index(netbk->pending_cons++);
pending_idx = netbk->pending_ring[index];
memcpy(&pending_tx_info[pending_idx].req, txp,
sizeof(*txp));
xenvif_get(vif);
pending_tx_info[pending_idx].vif = vif;
netbk->mmap_pages[pending_idx] = (void *)(~0UL);
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
set_page_ext(page, netbk, head_idx);
netbk->mmap_pages[head_idx] = page;
frag_set_pending_idx(&frags[shinfo->nr_frags], head_idx);
}
BUG_ON(shinfo->nr_frags > MAX_SKB_FRAGS);
return gop;
err:
while (shinfo->nr_frags-- > start) {
xen_netbk_idx_release(netbk,
frag_get_pending_idx(&frags[shinfo->nr_frags]),
XEN_NETIF_RSP_ERROR);
}
if (start)
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_ERROR);
return NULL;
}
static int xen_netbk_tx_check_gop(struct xen_netbk *netbk,
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
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_ERROR);
start = (frag_get_pending_idx(&shinfo->frags[0]) == pending_idx);
for (i = start; i < nr_frags; i++) {
int j, newerr;
pending_ring_idx_t head;
pending_idx = frag_get_pending_idx(&shinfo->frags[i]);
tx_info = &netbk->pending_tx_info[pending_idx];
head = tx_info->head;
do {
newerr = (++gop)->status;
if (newerr)
break;
peek = netbk->pending_ring[pending_index(++head)];
} while (!pending_tx_is_head(netbk, peek));
if (likely(!newerr)) {
if (unlikely(err))
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_OKAY);
continue;
}
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_ERROR);
if (err)
continue;
pending_idx = *((u16 *)skb->data);
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_OKAY);
for (j = start; j < i; j++) {
pending_idx = frag_get_pending_idx(&shinfo->frags[j]);
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_OKAY);
}
err = newerr;
}
*gopp = gop + 1;
return err;
}
static void xen_netbk_fill_frags(struct xen_netbk *netbk, struct sk_buff *skb)
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
txp = &netbk->pending_tx_info[pending_idx].req;
page = virt_to_page(idx_to_kaddr(netbk, pending_idx));
__skb_fill_page_desc(skb, i, page, txp->offset, txp->size);
skb->len += txp->size;
skb->data_len += txp->size;
skb->truesize += txp->size;
get_page(netbk->mmap_pages[pending_idx]);
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_OKAY);
}
}
static int xen_netbk_get_extras(struct xenvif *vif,
struct xen_netif_extra_info *extras,
int work_to_do)
{
struct xen_netif_extra_info extra;
RING_IDX cons = vif->tx.req_cons;
do {
if (unlikely(work_to_do-- <= 0)) {
netdev_err(vif->dev, "Missing extra info\n");
netbk_fatal_tx_err(vif);
return -EBADR;
}
memcpy(&extra, RING_GET_REQUEST(&vif->tx, cons),
sizeof(extra));
if (unlikely(!extra.type ||
extra.type >= XEN_NETIF_EXTRA_TYPE_MAX)) {
vif->tx.req_cons = ++cons;
netdev_err(vif->dev,
"Invalid extra type: %d\n", extra.type);
netbk_fatal_tx_err(vif);
return -EINVAL;
}
memcpy(&extras[extra.type - 1], &extra, sizeof(extra));
vif->tx.req_cons = ++cons;
} while (extra.flags & XEN_NETIF_EXTRA_FLAG_MORE);
return work_to_do;
}
static int netbk_set_skb_gso(struct xenvif *vif,
struct sk_buff *skb,
struct xen_netif_extra_info *gso)
{
if (!gso->u.gso.size) {
netdev_err(vif->dev, "GSO size must not be zero.\n");
netbk_fatal_tx_err(vif);
return -EINVAL;
}
if (gso->u.gso.type != XEN_NETIF_GSO_TYPE_TCPV4) {
netdev_err(vif->dev, "Bad GSO type %d.\n", gso->u.gso.type);
netbk_fatal_tx_err(vif);
return -EINVAL;
}
skb_shinfo(skb)->gso_size = gso->u.gso.size;
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV4;
skb_shinfo(skb)->gso_type |= SKB_GSO_DODGY;
skb_shinfo(skb)->gso_segs = 0;
return 0;
}
static int checksum_setup(struct xenvif *vif, struct sk_buff *skb)
{
struct iphdr *iph;
int err = -EPROTO;
int recalculate_partial_csum = 0;
if (skb->ip_summed != CHECKSUM_PARTIAL && skb_is_gso(skb)) {
vif->rx_gso_checksum_fixup++;
skb->ip_summed = CHECKSUM_PARTIAL;
recalculate_partial_csum = 1;
}
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (skb->protocol != htons(ETH_P_IP))
goto out;
iph = (void *)skb->data;
switch (iph->protocol) {
case IPPROTO_TCP:
if (!skb_partial_csum_set(skb, 4 * iph->ihl,
offsetof(struct tcphdr, check)))
goto out;
if (recalculate_partial_csum) {
struct tcphdr *tcph = tcp_hdr(skb);
tcph->check = ~csum_tcpudp_magic(iph->saddr, iph->daddr,
skb->len - iph->ihl*4,
IPPROTO_TCP, 0);
}
break;
case IPPROTO_UDP:
if (!skb_partial_csum_set(skb, 4 * iph->ihl,
offsetof(struct udphdr, check)))
goto out;
if (recalculate_partial_csum) {
struct udphdr *udph = udp_hdr(skb);
udph->check = ~csum_tcpudp_magic(iph->saddr, iph->daddr,
skb->len - iph->ihl*4,
IPPROTO_UDP, 0);
}
break;
default:
if (net_ratelimit())
netdev_err(vif->dev,
"Attempting to checksum a non-TCP/UDP packet, dropping a protocol %d packet\n",
iph->protocol);
goto out;
}
err = 0;
out:
return err;
}
static bool tx_credit_exceeded(struct xenvif *vif, unsigned size)
{
unsigned long now = jiffies;
unsigned long next_credit =
vif->credit_timeout.expires +
msecs_to_jiffies(vif->credit_usec / 1000);
if (timer_pending(&vif->credit_timeout))
return true;
if (time_after_eq(now, next_credit)) {
vif->credit_timeout.expires = now;
tx_add_credit(vif);
}
if (size > vif->remaining_credit) {
vif->credit_timeout.data =
(unsigned long)vif;
vif->credit_timeout.function =
tx_credit_callback;
mod_timer(&vif->credit_timeout,
next_credit);
return true;
}
return false;
}
static unsigned xen_netbk_tx_build_gops(struct xen_netbk *netbk)
{
struct gnttab_copy *gop = netbk->tx_copy_ops, *request_gop;
struct sk_buff *skb;
int ret;
while ((nr_pending_reqs(netbk) + XEN_NETBK_LEGACY_SLOTS_MAX
< MAX_PENDING_REQS) &&
!list_empty(&netbk->net_schedule_list)) {
struct xenvif *vif;
struct xen_netif_tx_request txreq;
struct xen_netif_tx_request txfrags[XEN_NETBK_LEGACY_SLOTS_MAX];
struct page *page;
struct xen_netif_extra_info extras[XEN_NETIF_EXTRA_TYPE_MAX-1];
u16 pending_idx;
RING_IDX idx;
int work_to_do;
unsigned int data_len;
pending_ring_idx_t index;
vif = poll_net_schedule_list(netbk);
if (!vif)
continue;
if (vif->tx.sring->req_prod - vif->tx.req_cons >
XEN_NETIF_TX_RING_SIZE) {
netdev_err(vif->dev,
"Impossible number of requests. "
"req_prod %d, req_cons %d, size %ld\n",
vif->tx.sring->req_prod, vif->tx.req_cons,
XEN_NETIF_TX_RING_SIZE);
netbk_fatal_tx_err(vif);
continue;
}
RING_FINAL_CHECK_FOR_REQUESTS(&vif->tx, work_to_do);
if (!work_to_do) {
xenvif_put(vif);
continue;
}
idx = vif->tx.req_cons;
rmb();
memcpy(&txreq, RING_GET_REQUEST(&vif->tx, idx), sizeof(txreq));
if (txreq.size > vif->remaining_credit &&
tx_credit_exceeded(vif, txreq.size)) {
xenvif_put(vif);
continue;
}
vif->remaining_credit -= txreq.size;
work_to_do--;
vif->tx.req_cons = ++idx;
memset(extras, 0, sizeof(extras));
if (txreq.flags & XEN_NETTXF_extra_info) {
work_to_do = xen_netbk_get_extras(vif, extras,
work_to_do);
idx = vif->tx.req_cons;
if (unlikely(work_to_do < 0))
continue;
}
ret = netbk_count_requests(vif, &txreq, txfrags, work_to_do);
if (unlikely(ret < 0))
continue;
idx += ret;
if (unlikely(txreq.size < ETH_HLEN)) {
netdev_dbg(vif->dev,
"Bad packet size: %d\n", txreq.size);
netbk_tx_err(vif, &txreq, idx);
continue;
}
if (unlikely((txreq.offset + txreq.size) > PAGE_SIZE)) {
netdev_err(vif->dev,
"txreq.offset: %x, size: %u, end: %lu\n",
txreq.offset, txreq.size,
(txreq.offset&~PAGE_MASK) + txreq.size);
netbk_fatal_tx_err(vif);
continue;
}
index = pending_index(netbk->pending_cons);
pending_idx = netbk->pending_ring[index];
data_len = (txreq.size > PKT_PROT_LEN &&
ret < XEN_NETBK_LEGACY_SLOTS_MAX) ?
PKT_PROT_LEN : txreq.size;
skb = alloc_skb(data_len + NET_SKB_PAD + NET_IP_ALIGN,
GFP_ATOMIC | __GFP_NOWARN);
if (unlikely(skb == NULL)) {
netdev_dbg(vif->dev,
"Can't allocate a skb in start_xmit.\n");
netbk_tx_err(vif, &txreq, idx);
break;
}
skb_reserve(skb, NET_SKB_PAD + NET_IP_ALIGN);
if (extras[XEN_NETIF_EXTRA_TYPE_GSO - 1].type) {
struct xen_netif_extra_info *gso;
gso = &extras[XEN_NETIF_EXTRA_TYPE_GSO - 1];
if (netbk_set_skb_gso(vif, skb, gso)) {
kfree_skb(skb);
continue;
}
}
page = xen_netbk_alloc_page(netbk, pending_idx);
if (!page) {
kfree_skb(skb);
netbk_tx_err(vif, &txreq, idx);
continue;
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
memcpy(&netbk->pending_tx_info[pending_idx].req,
&txreq, sizeof(txreq));
netbk->pending_tx_info[pending_idx].vif = vif;
netbk->pending_tx_info[pending_idx].head = index;
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
netbk->pending_cons++;
request_gop = xen_netbk_get_requests(netbk, vif,
skb, txfrags, gop);
if (request_gop == NULL) {
kfree_skb(skb);
netbk_tx_err(vif, &txreq, idx);
continue;
}
gop = request_gop;
__skb_queue_tail(&netbk->tx_queue, skb);
vif->tx.req_cons = idx;
xen_netbk_check_rx_xenvif(vif);
if ((gop-netbk->tx_copy_ops) >= ARRAY_SIZE(netbk->tx_copy_ops))
break;
}
return gop - netbk->tx_copy_ops;
}
static void xen_netbk_tx_submit(struct xen_netbk *netbk)
{
struct gnttab_copy *gop = netbk->tx_copy_ops;
struct sk_buff *skb;
while ((skb = __skb_dequeue(&netbk->tx_queue)) != NULL) {
struct xen_netif_tx_request *txp;
struct xenvif *vif;
u16 pending_idx;
unsigned data_len;
pending_idx = *((u16 *)skb->data);
vif = netbk->pending_tx_info[pending_idx].vif;
txp = &netbk->pending_tx_info[pending_idx].req;
if (unlikely(xen_netbk_tx_check_gop(netbk, skb, &gop))) {
netdev_dbg(vif->dev, "netback grant failed.\n");
skb_shinfo(skb)->nr_frags = 0;
kfree_skb(skb);
continue;
}
data_len = skb->len;
memcpy(skb->data,
(void *)(idx_to_kaddr(netbk, pending_idx)|txp->offset),
data_len);
if (data_len < txp->size) {
txp->offset += data_len;
txp->size -= data_len;
} else {
xen_netbk_idx_release(netbk, pending_idx, XEN_NETIF_RSP_OKAY);
}
if (txp->flags & XEN_NETTXF_csum_blank)
skb->ip_summed = CHECKSUM_PARTIAL;
else if (txp->flags & XEN_NETTXF_data_validated)
skb->ip_summed = CHECKSUM_UNNECESSARY;
xen_netbk_fill_frags(netbk, skb);
if (skb_headlen(skb) < PKT_PROT_LEN && skb_is_nonlinear(skb)) {
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
vif->dev->stats.rx_bytes += skb->len;
vif->dev->stats.rx_packets++;
xenvif_receive_skb(vif, skb);
}
}
static void xen_netbk_tx_action(struct xen_netbk *netbk)
{
unsigned nr_gops;
nr_gops = xen_netbk_tx_build_gops(netbk);
if (nr_gops == 0)
return;
gnttab_batch_copy(netbk->tx_copy_ops, nr_gops);
xen_netbk_tx_submit(netbk);
}
static void xen_netbk_idx_release(struct xen_netbk *netbk, u16 pending_idx,
u8 status)
{
struct xenvif *vif;
struct pending_tx_info *pending_tx_info;
pending_ring_idx_t head;
u16 peek;
BUG_ON(netbk->mmap_pages[pending_idx] == (void *)(~0UL));
if (netbk->mmap_pages[pending_idx] == NULL)
return;
pending_tx_info = &netbk->pending_tx_info[pending_idx];
vif = pending_tx_info->vif;
head = pending_tx_info->head;
BUG_ON(!pending_tx_is_head(netbk, head));
BUG_ON(netbk->pending_ring[pending_index(head)] != pending_idx);
do {
pending_ring_idx_t index;
pending_ring_idx_t idx = pending_index(head);
u16 info_idx = netbk->pending_ring[idx];
pending_tx_info = &netbk->pending_tx_info[info_idx];
make_tx_response(vif, &pending_tx_info->req, status);
pending_tx_info->head = 0;
index = pending_index(netbk->pending_prod++);
netbk->pending_ring[index] = netbk->pending_ring[info_idx];
xenvif_put(vif);
peek = netbk->pending_ring[pending_index(++head)];
} while (!pending_tx_is_head(netbk, peek));
netbk->mmap_pages[pending_idx]->mapping = 0;
put_page(netbk->mmap_pages[pending_idx]);
netbk->mmap_pages[pending_idx] = NULL;
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
static inline int rx_work_todo(struct xen_netbk *netbk)
{
return !skb_queue_empty(&netbk->rx_queue);
}
static inline int tx_work_todo(struct xen_netbk *netbk)
{
if ((nr_pending_reqs(netbk) + XEN_NETBK_LEGACY_SLOTS_MAX
< MAX_PENDING_REQS) &&
!list_empty(&netbk->net_schedule_list))
return 1;
return 0;
}
static int xen_netbk_kthread(void *data)
{
struct xen_netbk *netbk = data;
while (!kthread_should_stop()) {
wait_event_interruptible(netbk->wq,
rx_work_todo(netbk) ||
tx_work_todo(netbk) ||
kthread_should_stop());
cond_resched();
if (kthread_should_stop())
break;
if (rx_work_todo(netbk))
xen_netbk_rx_action(netbk);
if (tx_work_todo(netbk))
xen_netbk_tx_action(netbk);
}
return 0;
}
void xen_netbk_unmap_frontend_rings(struct xenvif *vif)
{
if (vif->tx.sring)
xenbus_unmap_ring_vfree(xenvif_to_xenbus_device(vif),
vif->tx.sring);
if (vif->rx.sring)
xenbus_unmap_ring_vfree(xenvif_to_xenbus_device(vif),
vif->rx.sring);
}
int xen_netbk_map_frontend_rings(struct xenvif *vif,
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
vif->rx_req_cons_peek = 0;
return 0;
err:
xen_netbk_unmap_frontend_rings(vif);
return err;
}
static int __init netback_init(void)
{
int i;
int rc = 0;
int group;
if (!xen_domain())
return -ENODEV;
if (fatal_skb_slots < XEN_NETBK_LEGACY_SLOTS_MAX) {
pr_info("fatal_skb_slots too small (%d), bump it to XEN_NETBK_LEGACY_SLOTS_MAX (%d)\n",
fatal_skb_slots, XEN_NETBK_LEGACY_SLOTS_MAX);
fatal_skb_slots = XEN_NETBK_LEGACY_SLOTS_MAX;
}
xen_netbk_group_nr = num_online_cpus();
xen_netbk = vzalloc(sizeof(struct xen_netbk) * xen_netbk_group_nr);
if (!xen_netbk)
return -ENOMEM;
for (group = 0; group < xen_netbk_group_nr; group++) {
struct xen_netbk *netbk = &xen_netbk[group];
skb_queue_head_init(&netbk->rx_queue);
skb_queue_head_init(&netbk->tx_queue);
init_timer(&netbk->net_timer);
netbk->net_timer.data = (unsigned long)netbk;
netbk->net_timer.function = xen_netbk_alarm;
netbk->pending_cons = 0;
netbk->pending_prod = MAX_PENDING_REQS;
for (i = 0; i < MAX_PENDING_REQS; i++)
netbk->pending_ring[i] = i;
init_waitqueue_head(&netbk->wq);
netbk->task = kthread_create(xen_netbk_kthread,
(void *)netbk,
"netback/%u", group);
if (IS_ERR(netbk->task)) {
pr_alert("kthread_create() fails at netback\n");
del_timer(&netbk->net_timer);
rc = PTR_ERR(netbk->task);
goto failed_init;
}
kthread_bind(netbk->task, group);
INIT_LIST_HEAD(&netbk->net_schedule_list);
spin_lock_init(&netbk->net_schedule_list_lock);
atomic_set(&netbk->netfront_count, 0);
wake_up_process(netbk->task);
}
rc = xenvif_xenbus_init();
if (rc)
goto failed_init;
return 0;
failed_init:
while (--group >= 0) {
struct xen_netbk *netbk = &xen_netbk[group];
del_timer(&netbk->net_timer);
kthread_stop(netbk->task);
}
vfree(xen_netbk);
return rc;
}
static void __exit netback_fini(void)
{
int i, j;
xenvif_xenbus_fini();
for (i = 0; i < xen_netbk_group_nr; i++) {
struct xen_netbk *netbk = &xen_netbk[i];
del_timer_sync(&netbk->net_timer);
kthread_stop(netbk->task);
for (j = 0; j < MAX_PENDING_REQS; j++) {
if (netbk->mmap_pages[j])
__free_page(netbk->mmap_pages[j]);
}
}
vfree(xen_netbk);
}
