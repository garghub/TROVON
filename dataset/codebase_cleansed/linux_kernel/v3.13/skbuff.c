static void sock_pipe_buf_release(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
put_page(buf->page);
}
static void sock_pipe_buf_get(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
get_page(buf->page);
}
static int sock_pipe_buf_steal(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
return 1;
}
static void skb_panic(struct sk_buff *skb, unsigned int sz, void *addr,
const char msg[])
{
pr_emerg("%s: text:%p len:%d put:%d head:%p data:%p tail:%#lx end:%#lx dev:%s\n",
msg, addr, skb->len, sz, skb->head, skb->data,
(unsigned long)skb->tail, (unsigned long)skb->end,
skb->dev ? skb->dev->name : "<NULL>");
BUG();
}
static void skb_over_panic(struct sk_buff *skb, unsigned int sz, void *addr)
{
skb_panic(skb, sz, addr, __func__);
}
static void skb_under_panic(struct sk_buff *skb, unsigned int sz, void *addr)
{
skb_panic(skb, sz, addr, __func__);
}
static void *__kmalloc_reserve(size_t size, gfp_t flags, int node,
unsigned long ip, bool *pfmemalloc)
{
void *obj;
bool ret_pfmemalloc = false;
obj = kmalloc_node_track_caller(size,
flags | __GFP_NOMEMALLOC | __GFP_NOWARN,
node);
if (obj || !(gfp_pfmemalloc_allowed(flags)))
goto out;
ret_pfmemalloc = true;
obj = kmalloc_node_track_caller(size, flags, node);
out:
if (pfmemalloc)
*pfmemalloc = ret_pfmemalloc;
return obj;
}
struct sk_buff *__alloc_skb_head(gfp_t gfp_mask, int node)
{
struct sk_buff *skb;
skb = kmem_cache_alloc_node(skbuff_head_cache,
gfp_mask & ~__GFP_DMA, node);
if (!skb)
goto out;
memset(skb, 0, offsetof(struct sk_buff, tail));
skb->head = NULL;
skb->truesize = sizeof(struct sk_buff);
atomic_set(&skb->users, 1);
skb->mac_header = (typeof(skb->mac_header))~0U;
out:
return skb;
}
struct sk_buff *__alloc_skb(unsigned int size, gfp_t gfp_mask,
int flags, int node)
{
struct kmem_cache *cache;
struct skb_shared_info *shinfo;
struct sk_buff *skb;
u8 *data;
bool pfmemalloc;
cache = (flags & SKB_ALLOC_FCLONE)
? skbuff_fclone_cache : skbuff_head_cache;
if (sk_memalloc_socks() && (flags & SKB_ALLOC_RX))
gfp_mask |= __GFP_MEMALLOC;
skb = kmem_cache_alloc_node(cache, gfp_mask & ~__GFP_DMA, node);
if (!skb)
goto out;
prefetchw(skb);
size = SKB_DATA_ALIGN(size);
size += SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
data = kmalloc_reserve(size, gfp_mask, node, &pfmemalloc);
if (!data)
goto nodata;
size = SKB_WITH_OVERHEAD(ksize(data));
prefetchw(data + size);
memset(skb, 0, offsetof(struct sk_buff, tail));
skb->truesize = SKB_TRUESIZE(size);
skb->pfmemalloc = pfmemalloc;
atomic_set(&skb->users, 1);
skb->head = data;
skb->data = data;
skb_reset_tail_pointer(skb);
skb->end = skb->tail + size;
skb->mac_header = (typeof(skb->mac_header))~0U;
skb->transport_header = (typeof(skb->transport_header))~0U;
shinfo = skb_shinfo(skb);
memset(shinfo, 0, offsetof(struct skb_shared_info, dataref));
atomic_set(&shinfo->dataref, 1);
kmemcheck_annotate_variable(shinfo->destructor_arg);
if (flags & SKB_ALLOC_FCLONE) {
struct sk_buff *child = skb + 1;
atomic_t *fclone_ref = (atomic_t *) (child + 1);
kmemcheck_annotate_bitfield(child, flags1);
kmemcheck_annotate_bitfield(child, flags2);
skb->fclone = SKB_FCLONE_ORIG;
atomic_set(fclone_ref, 1);
child->fclone = SKB_FCLONE_UNAVAILABLE;
child->pfmemalloc = pfmemalloc;
}
out:
return skb;
nodata:
kmem_cache_free(cache, skb);
skb = NULL;
goto out;
}
struct sk_buff *build_skb(void *data, unsigned int frag_size)
{
struct skb_shared_info *shinfo;
struct sk_buff *skb;
unsigned int size = frag_size ? : ksize(data);
skb = kmem_cache_alloc(skbuff_head_cache, GFP_ATOMIC);
if (!skb)
return NULL;
size -= SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
memset(skb, 0, offsetof(struct sk_buff, tail));
skb->truesize = SKB_TRUESIZE(size);
skb->head_frag = frag_size != 0;
atomic_set(&skb->users, 1);
skb->head = data;
skb->data = data;
skb_reset_tail_pointer(skb);
skb->end = skb->tail + size;
skb->mac_header = (typeof(skb->mac_header))~0U;
skb->transport_header = (typeof(skb->transport_header))~0U;
shinfo = skb_shinfo(skb);
memset(shinfo, 0, offsetof(struct skb_shared_info, dataref));
atomic_set(&shinfo->dataref, 1);
kmemcheck_annotate_variable(shinfo->destructor_arg);
return skb;
}
static void *__netdev_alloc_frag(unsigned int fragsz, gfp_t gfp_mask)
{
struct netdev_alloc_cache *nc;
void *data = NULL;
int order;
unsigned long flags;
local_irq_save(flags);
nc = &__get_cpu_var(netdev_alloc_cache);
if (unlikely(!nc->frag.page)) {
refill:
for (order = NETDEV_FRAG_PAGE_MAX_ORDER; ;) {
gfp_t gfp = gfp_mask;
if (order)
gfp |= __GFP_COMP | __GFP_NOWARN;
nc->frag.page = alloc_pages(gfp, order);
if (likely(nc->frag.page))
break;
if (--order < 0)
goto end;
}
nc->frag.size = PAGE_SIZE << order;
recycle:
atomic_set(&nc->frag.page->_count, NETDEV_PAGECNT_MAX_BIAS);
nc->pagecnt_bias = NETDEV_PAGECNT_MAX_BIAS;
nc->frag.offset = 0;
}
if (nc->frag.offset + fragsz > nc->frag.size) {
if ((atomic_read(&nc->frag.page->_count) == nc->pagecnt_bias) ||
atomic_sub_and_test(nc->pagecnt_bias, &nc->frag.page->_count))
goto recycle;
goto refill;
}
data = page_address(nc->frag.page) + nc->frag.offset;
nc->frag.offset += fragsz;
nc->pagecnt_bias--;
end:
local_irq_restore(flags);
return data;
}
void *netdev_alloc_frag(unsigned int fragsz)
{
return __netdev_alloc_frag(fragsz, GFP_ATOMIC | __GFP_COLD);
}
struct sk_buff *__netdev_alloc_skb(struct net_device *dev,
unsigned int length, gfp_t gfp_mask)
{
struct sk_buff *skb = NULL;
unsigned int fragsz = SKB_DATA_ALIGN(length + NET_SKB_PAD) +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
if (fragsz <= PAGE_SIZE && !(gfp_mask & (__GFP_WAIT | GFP_DMA))) {
void *data;
if (sk_memalloc_socks())
gfp_mask |= __GFP_MEMALLOC;
data = __netdev_alloc_frag(fragsz, gfp_mask);
if (likely(data)) {
skb = build_skb(data, fragsz);
if (unlikely(!skb))
put_page(virt_to_head_page(data));
}
} else {
skb = __alloc_skb(length + NET_SKB_PAD, gfp_mask,
SKB_ALLOC_RX, NUMA_NO_NODE);
}
if (likely(skb)) {
skb_reserve(skb, NET_SKB_PAD);
skb->dev = dev;
}
return skb;
}
void skb_add_rx_frag(struct sk_buff *skb, int i, struct page *page, int off,
int size, unsigned int truesize)
{
skb_fill_page_desc(skb, i, page, off, size);
skb->len += size;
skb->data_len += size;
skb->truesize += truesize;
}
void skb_coalesce_rx_frag(struct sk_buff *skb, int i, int size,
unsigned int truesize)
{
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
skb_frag_size_add(frag, size);
skb->len += size;
skb->data_len += size;
skb->truesize += truesize;
}
static void skb_drop_list(struct sk_buff **listp)
{
kfree_skb_list(*listp);
*listp = NULL;
}
static inline void skb_drop_fraglist(struct sk_buff *skb)
{
skb_drop_list(&skb_shinfo(skb)->frag_list);
}
static void skb_clone_fraglist(struct sk_buff *skb)
{
struct sk_buff *list;
skb_walk_frags(skb, list)
skb_get(list);
}
static void skb_free_head(struct sk_buff *skb)
{
if (skb->head_frag)
put_page(virt_to_head_page(skb->head));
else
kfree(skb->head);
}
static void skb_release_data(struct sk_buff *skb)
{
if (!skb->cloned ||
!atomic_sub_return(skb->nohdr ? (1 << SKB_DATAREF_SHIFT) + 1 : 1,
&skb_shinfo(skb)->dataref)) {
if (skb_shinfo(skb)->nr_frags) {
int i;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++)
skb_frag_unref(skb, i);
}
if (skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY) {
struct ubuf_info *uarg;
uarg = skb_shinfo(skb)->destructor_arg;
if (uarg->callback)
uarg->callback(uarg, true);
}
if (skb_has_frag_list(skb))
skb_drop_fraglist(skb);
skb_free_head(skb);
}
}
static void kfree_skbmem(struct sk_buff *skb)
{
struct sk_buff *other;
atomic_t *fclone_ref;
switch (skb->fclone) {
case SKB_FCLONE_UNAVAILABLE:
kmem_cache_free(skbuff_head_cache, skb);
break;
case SKB_FCLONE_ORIG:
fclone_ref = (atomic_t *) (skb + 2);
if (atomic_dec_and_test(fclone_ref))
kmem_cache_free(skbuff_fclone_cache, skb);
break;
case SKB_FCLONE_CLONE:
fclone_ref = (atomic_t *) (skb + 1);
other = skb - 1;
skb->fclone = SKB_FCLONE_UNAVAILABLE;
if (atomic_dec_and_test(fclone_ref))
kmem_cache_free(skbuff_fclone_cache, other);
break;
}
}
static void skb_release_head_state(struct sk_buff *skb)
{
skb_dst_drop(skb);
#ifdef CONFIG_XFRM
secpath_put(skb->sp);
#endif
if (skb->destructor) {
WARN_ON(in_irq());
skb->destructor(skb);
}
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
nf_conntrack_put(skb->nfct);
#endif
#ifdef CONFIG_BRIDGE_NETFILTER
nf_bridge_put(skb->nf_bridge);
#endif
#ifdef CONFIG_NET_SCHED
skb->tc_index = 0;
#ifdef CONFIG_NET_CLS_ACT
skb->tc_verd = 0;
#endif
#endif
}
static void skb_release_all(struct sk_buff *skb)
{
skb_release_head_state(skb);
if (likely(skb->head))
skb_release_data(skb);
}
void __kfree_skb(struct sk_buff *skb)
{
skb_release_all(skb);
kfree_skbmem(skb);
}
void kfree_skb(struct sk_buff *skb)
{
if (unlikely(!skb))
return;
if (likely(atomic_read(&skb->users) == 1))
smp_rmb();
else if (likely(!atomic_dec_and_test(&skb->users)))
return;
trace_kfree_skb(skb, __builtin_return_address(0));
__kfree_skb(skb);
}
void kfree_skb_list(struct sk_buff *segs)
{
while (segs) {
struct sk_buff *next = segs->next;
kfree_skb(segs);
segs = next;
}
}
void skb_tx_error(struct sk_buff *skb)
{
if (skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY) {
struct ubuf_info *uarg;
uarg = skb_shinfo(skb)->destructor_arg;
if (uarg->callback)
uarg->callback(uarg, false);
skb_shinfo(skb)->tx_flags &= ~SKBTX_DEV_ZEROCOPY;
}
}
void consume_skb(struct sk_buff *skb)
{
if (unlikely(!skb))
return;
if (likely(atomic_read(&skb->users) == 1))
smp_rmb();
else if (likely(!atomic_dec_and_test(&skb->users)))
return;
trace_consume_skb(skb);
__kfree_skb(skb);
}
static void __copy_skb_header(struct sk_buff *new, const struct sk_buff *old)
{
new->tstamp = old->tstamp;
new->dev = old->dev;
new->transport_header = old->transport_header;
new->network_header = old->network_header;
new->mac_header = old->mac_header;
new->inner_protocol = old->inner_protocol;
new->inner_transport_header = old->inner_transport_header;
new->inner_network_header = old->inner_network_header;
new->inner_mac_header = old->inner_mac_header;
skb_dst_copy(new, old);
new->rxhash = old->rxhash;
new->ooo_okay = old->ooo_okay;
new->l4_rxhash = old->l4_rxhash;
new->no_fcs = old->no_fcs;
new->encapsulation = old->encapsulation;
#ifdef CONFIG_XFRM
new->sp = secpath_get(old->sp);
#endif
memcpy(new->cb, old->cb, sizeof(old->cb));
new->csum = old->csum;
new->local_df = old->local_df;
new->pkt_type = old->pkt_type;
new->ip_summed = old->ip_summed;
skb_copy_queue_mapping(new, old);
new->priority = old->priority;
#if IS_ENABLED(CONFIG_IP_VS)
new->ipvs_property = old->ipvs_property;
#endif
new->pfmemalloc = old->pfmemalloc;
new->protocol = old->protocol;
new->mark = old->mark;
new->skb_iif = old->skb_iif;
__nf_copy(new, old);
#if IS_ENABLED(CONFIG_NETFILTER_XT_TARGET_TRACE)
new->nf_trace = old->nf_trace;
#endif
#ifdef CONFIG_NET_SCHED
new->tc_index = old->tc_index;
#ifdef CONFIG_NET_CLS_ACT
new->tc_verd = old->tc_verd;
#endif
#endif
new->vlan_proto = old->vlan_proto;
new->vlan_tci = old->vlan_tci;
skb_copy_secmark(new, old);
#ifdef CONFIG_NET_RX_BUSY_POLL
new->napi_id = old->napi_id;
#endif
}
static struct sk_buff *__skb_clone(struct sk_buff *n, struct sk_buff *skb)
{
#define C(x) n->x = skb->x
n->next = n->prev = NULL;
n->sk = NULL;
__copy_skb_header(n, skb);
C(len);
C(data_len);
C(mac_len);
n->hdr_len = skb->nohdr ? skb_headroom(skb) : skb->hdr_len;
n->cloned = 1;
n->nohdr = 0;
n->destructor = NULL;
C(tail);
C(end);
C(head);
C(head_frag);
C(data);
C(truesize);
atomic_set(&n->users, 1);
atomic_inc(&(skb_shinfo(skb)->dataref));
skb->cloned = 1;
return n;
#undef C
}
struct sk_buff *skb_morph(struct sk_buff *dst, struct sk_buff *src)
{
skb_release_all(dst);
return __skb_clone(dst, src);
}
int skb_copy_ubufs(struct sk_buff *skb, gfp_t gfp_mask)
{
int i;
int num_frags = skb_shinfo(skb)->nr_frags;
struct page *page, *head = NULL;
struct ubuf_info *uarg = skb_shinfo(skb)->destructor_arg;
for (i = 0; i < num_frags; i++) {
u8 *vaddr;
skb_frag_t *f = &skb_shinfo(skb)->frags[i];
page = alloc_page(gfp_mask);
if (!page) {
while (head) {
struct page *next = (struct page *)page_private(head);
put_page(head);
head = next;
}
return -ENOMEM;
}
vaddr = kmap_atomic(skb_frag_page(f));
memcpy(page_address(page),
vaddr + f->page_offset, skb_frag_size(f));
kunmap_atomic(vaddr);
set_page_private(page, (unsigned long)head);
head = page;
}
for (i = 0; i < num_frags; i++)
skb_frag_unref(skb, i);
uarg->callback(uarg, false);
for (i = num_frags - 1; i >= 0; i--) {
__skb_fill_page_desc(skb, i, head, 0,
skb_shinfo(skb)->frags[i].size);
head = (struct page *)page_private(head);
}
skb_shinfo(skb)->tx_flags &= ~SKBTX_DEV_ZEROCOPY;
return 0;
}
struct sk_buff *skb_clone(struct sk_buff *skb, gfp_t gfp_mask)
{
struct sk_buff *n;
if (skb_orphan_frags(skb, gfp_mask))
return NULL;
n = skb + 1;
if (skb->fclone == SKB_FCLONE_ORIG &&
n->fclone == SKB_FCLONE_UNAVAILABLE) {
atomic_t *fclone_ref = (atomic_t *) (n + 1);
n->fclone = SKB_FCLONE_CLONE;
atomic_inc(fclone_ref);
} else {
if (skb_pfmemalloc(skb))
gfp_mask |= __GFP_MEMALLOC;
n = kmem_cache_alloc(skbuff_head_cache, gfp_mask);
if (!n)
return NULL;
kmemcheck_annotate_bitfield(n, flags1);
kmemcheck_annotate_bitfield(n, flags2);
n->fclone = SKB_FCLONE_UNAVAILABLE;
}
return __skb_clone(n, skb);
}
static void skb_headers_offset_update(struct sk_buff *skb, int off)
{
if (skb->ip_summed == CHECKSUM_PARTIAL)
skb->csum_start += off;
skb->transport_header += off;
skb->network_header += off;
if (skb_mac_header_was_set(skb))
skb->mac_header += off;
skb->inner_transport_header += off;
skb->inner_network_header += off;
skb->inner_mac_header += off;
}
static void copy_skb_header(struct sk_buff *new, const struct sk_buff *old)
{
__copy_skb_header(new, old);
skb_shinfo(new)->gso_size = skb_shinfo(old)->gso_size;
skb_shinfo(new)->gso_segs = skb_shinfo(old)->gso_segs;
skb_shinfo(new)->gso_type = skb_shinfo(old)->gso_type;
}
static inline int skb_alloc_rx_flag(const struct sk_buff *skb)
{
if (skb_pfmemalloc(skb))
return SKB_ALLOC_RX;
return 0;
}
struct sk_buff *skb_copy(const struct sk_buff *skb, gfp_t gfp_mask)
{
int headerlen = skb_headroom(skb);
unsigned int size = skb_end_offset(skb) + skb->data_len;
struct sk_buff *n = __alloc_skb(size, gfp_mask,
skb_alloc_rx_flag(skb), NUMA_NO_NODE);
if (!n)
return NULL;
skb_reserve(n, headerlen);
skb_put(n, skb->len);
if (skb_copy_bits(skb, -headerlen, n->head, headerlen + skb->len))
BUG();
copy_skb_header(n, skb);
return n;
}
struct sk_buff *__pskb_copy(struct sk_buff *skb, int headroom, gfp_t gfp_mask)
{
unsigned int size = skb_headlen(skb) + headroom;
struct sk_buff *n = __alloc_skb(size, gfp_mask,
skb_alloc_rx_flag(skb), NUMA_NO_NODE);
if (!n)
goto out;
skb_reserve(n, headroom);
skb_put(n, skb_headlen(skb));
skb_copy_from_linear_data(skb, n->data, n->len);
n->truesize += skb->data_len;
n->data_len = skb->data_len;
n->len = skb->len;
if (skb_shinfo(skb)->nr_frags) {
int i;
if (skb_orphan_frags(skb, gfp_mask)) {
kfree_skb(n);
n = NULL;
goto out;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_shinfo(n)->frags[i] = skb_shinfo(skb)->frags[i];
skb_frag_ref(skb, i);
}
skb_shinfo(n)->nr_frags = i;
}
if (skb_has_frag_list(skb)) {
skb_shinfo(n)->frag_list = skb_shinfo(skb)->frag_list;
skb_clone_fraglist(n);
}
copy_skb_header(n, skb);
out:
return n;
}
int pskb_expand_head(struct sk_buff *skb, int nhead, int ntail,
gfp_t gfp_mask)
{
int i;
u8 *data;
int size = nhead + skb_end_offset(skb) + ntail;
long off;
BUG_ON(nhead < 0);
if (skb_shared(skb))
BUG();
size = SKB_DATA_ALIGN(size);
if (skb_pfmemalloc(skb))
gfp_mask |= __GFP_MEMALLOC;
data = kmalloc_reserve(size + SKB_DATA_ALIGN(sizeof(struct skb_shared_info)),
gfp_mask, NUMA_NO_NODE, NULL);
if (!data)
goto nodata;
size = SKB_WITH_OVERHEAD(ksize(data));
memcpy(data + nhead, skb->head, skb_tail_pointer(skb) - skb->head);
memcpy((struct skb_shared_info *)(data + size),
skb_shinfo(skb),
offsetof(struct skb_shared_info, frags[skb_shinfo(skb)->nr_frags]));
if (skb_cloned(skb)) {
if (skb_orphan_frags(skb, gfp_mask))
goto nofrags;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++)
skb_frag_ref(skb, i);
if (skb_has_frag_list(skb))
skb_clone_fraglist(skb);
skb_release_data(skb);
} else {
skb_free_head(skb);
}
off = (data + nhead) - skb->head;
skb->head = data;
skb->head_frag = 0;
skb->data += off;
#ifdef NET_SKBUFF_DATA_USES_OFFSET
skb->end = size;
off = nhead;
#else
skb->end = skb->head + size;
#endif
skb->tail += off;
skb_headers_offset_update(skb, nhead);
skb->cloned = 0;
skb->hdr_len = 0;
skb->nohdr = 0;
atomic_set(&skb_shinfo(skb)->dataref, 1);
return 0;
nofrags:
kfree(data);
nodata:
return -ENOMEM;
}
struct sk_buff *skb_realloc_headroom(struct sk_buff *skb, unsigned int headroom)
{
struct sk_buff *skb2;
int delta = headroom - skb_headroom(skb);
if (delta <= 0)
skb2 = pskb_copy(skb, GFP_ATOMIC);
else {
skb2 = skb_clone(skb, GFP_ATOMIC);
if (skb2 && pskb_expand_head(skb2, SKB_DATA_ALIGN(delta), 0,
GFP_ATOMIC)) {
kfree_skb(skb2);
skb2 = NULL;
}
}
return skb2;
}
struct sk_buff *skb_copy_expand(const struct sk_buff *skb,
int newheadroom, int newtailroom,
gfp_t gfp_mask)
{
struct sk_buff *n = __alloc_skb(newheadroom + skb->len + newtailroom,
gfp_mask, skb_alloc_rx_flag(skb),
NUMA_NO_NODE);
int oldheadroom = skb_headroom(skb);
int head_copy_len, head_copy_off;
if (!n)
return NULL;
skb_reserve(n, newheadroom);
skb_put(n, skb->len);
head_copy_len = oldheadroom;
head_copy_off = 0;
if (newheadroom <= head_copy_len)
head_copy_len = newheadroom;
else
head_copy_off = newheadroom - head_copy_len;
if (skb_copy_bits(skb, -head_copy_len, n->head + head_copy_off,
skb->len + head_copy_len))
BUG();
copy_skb_header(n, skb);
skb_headers_offset_update(n, newheadroom - oldheadroom);
return n;
}
int skb_pad(struct sk_buff *skb, int pad)
{
int err;
int ntail;
if (!skb_cloned(skb) && skb_tailroom(skb) >= pad) {
memset(skb->data+skb->len, 0, pad);
return 0;
}
ntail = skb->data_len + pad - (skb->end - skb->tail);
if (likely(skb_cloned(skb) || ntail > 0)) {
err = pskb_expand_head(skb, 0, ntail, GFP_ATOMIC);
if (unlikely(err))
goto free_skb;
}
err = skb_linearize(skb);
if (unlikely(err))
goto free_skb;
memset(skb->data + skb->len, 0, pad);
return 0;
free_skb:
kfree_skb(skb);
return err;
}
unsigned char *pskb_put(struct sk_buff *skb, struct sk_buff *tail, int len)
{
if (tail != skb) {
skb->data_len += len;
skb->len += len;
}
return skb_put(tail, len);
}
unsigned char *skb_put(struct sk_buff *skb, unsigned int len)
{
unsigned char *tmp = skb_tail_pointer(skb);
SKB_LINEAR_ASSERT(skb);
skb->tail += len;
skb->len += len;
if (unlikely(skb->tail > skb->end))
skb_over_panic(skb, len, __builtin_return_address(0));
return tmp;
}
unsigned char *skb_push(struct sk_buff *skb, unsigned int len)
{
skb->data -= len;
skb->len += len;
if (unlikely(skb->data<skb->head))
skb_under_panic(skb, len, __builtin_return_address(0));
return skb->data;
}
unsigned char *skb_pull(struct sk_buff *skb, unsigned int len)
{
return skb_pull_inline(skb, len);
}
void skb_trim(struct sk_buff *skb, unsigned int len)
{
if (skb->len > len)
__skb_trim(skb, len);
}
int ___pskb_trim(struct sk_buff *skb, unsigned int len)
{
struct sk_buff **fragp;
struct sk_buff *frag;
int offset = skb_headlen(skb);
int nfrags = skb_shinfo(skb)->nr_frags;
int i;
int err;
if (skb_cloned(skb) &&
unlikely((err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC))))
return err;
i = 0;
if (offset >= len)
goto drop_pages;
for (; i < nfrags; i++) {
int end = offset + skb_frag_size(&skb_shinfo(skb)->frags[i]);
if (end < len) {
offset = end;
continue;
}
skb_frag_size_set(&skb_shinfo(skb)->frags[i++], len - offset);
drop_pages:
skb_shinfo(skb)->nr_frags = i;
for (; i < nfrags; i++)
skb_frag_unref(skb, i);
if (skb_has_frag_list(skb))
skb_drop_fraglist(skb);
goto done;
}
for (fragp = &skb_shinfo(skb)->frag_list; (frag = *fragp);
fragp = &frag->next) {
int end = offset + frag->len;
if (skb_shared(frag)) {
struct sk_buff *nfrag;
nfrag = skb_clone(frag, GFP_ATOMIC);
if (unlikely(!nfrag))
return -ENOMEM;
nfrag->next = frag->next;
consume_skb(frag);
frag = nfrag;
*fragp = frag;
}
if (end < len) {
offset = end;
continue;
}
if (end > len &&
unlikely((err = pskb_trim(frag, len - offset))))
return err;
if (frag->next)
skb_drop_list(&frag->next);
break;
}
done:
if (len > skb_headlen(skb)) {
skb->data_len -= skb->len - len;
skb->len = len;
} else {
skb->len = len;
skb->data_len = 0;
skb_set_tail_pointer(skb, len);
}
return 0;
}
unsigned char *__pskb_pull_tail(struct sk_buff *skb, int delta)
{
int i, k, eat = (skb->tail + delta) - skb->end;
if (eat > 0 || skb_cloned(skb)) {
if (pskb_expand_head(skb, 0, eat > 0 ? eat + 128 : 0,
GFP_ATOMIC))
return NULL;
}
if (skb_copy_bits(skb, skb_headlen(skb), skb_tail_pointer(skb), delta))
BUG();
if (!skb_has_frag_list(skb))
goto pull_pages;
eat = delta;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
if (size >= eat)
goto pull_pages;
eat -= size;
}
if (eat) {
struct sk_buff *list = skb_shinfo(skb)->frag_list;
struct sk_buff *clone = NULL;
struct sk_buff *insp = NULL;
do {
BUG_ON(!list);
if (list->len <= eat) {
eat -= list->len;
list = list->next;
insp = list;
} else {
if (skb_shared(list)) {
clone = skb_clone(list, GFP_ATOMIC);
if (!clone)
return NULL;
insp = list->next;
list = clone;
} else {
insp = list;
}
if (!pskb_pull(list, eat)) {
kfree_skb(clone);
return NULL;
}
break;
}
} while (eat);
while ((list = skb_shinfo(skb)->frag_list) != insp) {
skb_shinfo(skb)->frag_list = list->next;
kfree_skb(list);
}
if (clone) {
clone->next = list;
skb_shinfo(skb)->frag_list = clone;
}
}
pull_pages:
eat = delta;
k = 0;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
if (size <= eat) {
skb_frag_unref(skb, i);
eat -= size;
} else {
skb_shinfo(skb)->frags[k] = skb_shinfo(skb)->frags[i];
if (eat) {
skb_shinfo(skb)->frags[k].page_offset += eat;
skb_frag_size_sub(&skb_shinfo(skb)->frags[k], eat);
eat = 0;
}
k++;
}
}
skb_shinfo(skb)->nr_frags = k;
skb->tail += delta;
skb->data_len -= delta;
return skb_tail_pointer(skb);
}
int skb_copy_bits(const struct sk_buff *skb, int offset, void *to, int len)
{
int start = skb_headlen(skb);
struct sk_buff *frag_iter;
int i, copy;
if (offset > (int)skb->len - len)
goto fault;
if ((copy = start - offset) > 0) {
if (copy > len)
copy = len;
skb_copy_from_linear_data_offset(skb, offset, to, copy);
if ((len -= copy) == 0)
return 0;
offset += copy;
to += copy;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int end;
skb_frag_t *f = &skb_shinfo(skb)->frags[i];
WARN_ON(start > offset + len);
end = start + skb_frag_size(f);
if ((copy = end - offset) > 0) {
u8 *vaddr;
if (copy > len)
copy = len;
vaddr = kmap_atomic(skb_frag_page(f));
memcpy(to,
vaddr + f->page_offset + offset - start,
copy);
kunmap_atomic(vaddr);
if ((len -= copy) == 0)
return 0;
offset += copy;
to += copy;
}
start = end;
}
skb_walk_frags(skb, frag_iter) {
int end;
WARN_ON(start > offset + len);
end = start + frag_iter->len;
if ((copy = end - offset) > 0) {
if (copy > len)
copy = len;
if (skb_copy_bits(frag_iter, offset - start, to, copy))
goto fault;
if ((len -= copy) == 0)
return 0;
offset += copy;
to += copy;
}
start = end;
}
if (!len)
return 0;
fault:
return -EFAULT;
}
static void sock_spd_release(struct splice_pipe_desc *spd, unsigned int i)
{
put_page(spd->pages[i]);
}
static struct page *linear_to_page(struct page *page, unsigned int *len,
unsigned int *offset,
struct sock *sk)
{
struct page_frag *pfrag = sk_page_frag(sk);
if (!sk_page_frag_refill(sk, pfrag))
return NULL;
*len = min_t(unsigned int, *len, pfrag->size - pfrag->offset);
memcpy(page_address(pfrag->page) + pfrag->offset,
page_address(page) + *offset, *len);
*offset = pfrag->offset;
pfrag->offset += *len;
return pfrag->page;
}
static bool spd_can_coalesce(const struct splice_pipe_desc *spd,
struct page *page,
unsigned int offset)
{
return spd->nr_pages &&
spd->pages[spd->nr_pages - 1] == page &&
(spd->partial[spd->nr_pages - 1].offset +
spd->partial[spd->nr_pages - 1].len == offset);
}
static bool spd_fill_page(struct splice_pipe_desc *spd,
struct pipe_inode_info *pipe, struct page *page,
unsigned int *len, unsigned int offset,
bool linear,
struct sock *sk)
{
if (unlikely(spd->nr_pages == MAX_SKB_FRAGS))
return true;
if (linear) {
page = linear_to_page(page, len, &offset, sk);
if (!page)
return true;
}
if (spd_can_coalesce(spd, page, offset)) {
spd->partial[spd->nr_pages - 1].len += *len;
return false;
}
get_page(page);
spd->pages[spd->nr_pages] = page;
spd->partial[spd->nr_pages].len = *len;
spd->partial[spd->nr_pages].offset = offset;
spd->nr_pages++;
return false;
}
static bool __splice_segment(struct page *page, unsigned int poff,
unsigned int plen, unsigned int *off,
unsigned int *len,
struct splice_pipe_desc *spd, bool linear,
struct sock *sk,
struct pipe_inode_info *pipe)
{
if (!*len)
return true;
if (*off >= plen) {
*off -= plen;
return false;
}
poff += *off;
plen -= *off;
*off = 0;
do {
unsigned int flen = min(*len, plen);
if (spd_fill_page(spd, pipe, page, &flen, poff,
linear, sk))
return true;
poff += flen;
plen -= flen;
*len -= flen;
} while (*len && plen);
return false;
}
static bool __skb_splice_bits(struct sk_buff *skb, struct pipe_inode_info *pipe,
unsigned int *offset, unsigned int *len,
struct splice_pipe_desc *spd, struct sock *sk)
{
int seg;
if (__splice_segment(virt_to_page(skb->data),
(unsigned long) skb->data & (PAGE_SIZE - 1),
skb_headlen(skb),
offset, len, spd,
skb_head_is_locked(skb),
sk, pipe))
return true;
for (seg = 0; seg < skb_shinfo(skb)->nr_frags; seg++) {
const skb_frag_t *f = &skb_shinfo(skb)->frags[seg];
if (__splice_segment(skb_frag_page(f),
f->page_offset, skb_frag_size(f),
offset, len, spd, false, sk, pipe))
return true;
}
return false;
}
int skb_splice_bits(struct sk_buff *skb, unsigned int offset,
struct pipe_inode_info *pipe, unsigned int tlen,
unsigned int flags)
{
struct partial_page partial[MAX_SKB_FRAGS];
struct page *pages[MAX_SKB_FRAGS];
struct splice_pipe_desc spd = {
.pages = pages,
.partial = partial,
.nr_pages_max = MAX_SKB_FRAGS,
.flags = flags,
.ops = &sock_pipe_buf_ops,
.spd_release = sock_spd_release,
};
struct sk_buff *frag_iter;
struct sock *sk = skb->sk;
int ret = 0;
if (__skb_splice_bits(skb, pipe, &offset, &tlen, &spd, sk))
goto done;
else if (!tlen)
goto done;
skb_walk_frags(skb, frag_iter) {
if (!tlen)
break;
if (__skb_splice_bits(frag_iter, pipe, &offset, &tlen, &spd, sk))
break;
}
done:
if (spd.nr_pages) {
release_sock(sk);
ret = splice_to_pipe(pipe, &spd);
lock_sock(sk);
}
return ret;
}
int skb_store_bits(struct sk_buff *skb, int offset, const void *from, int len)
{
int start = skb_headlen(skb);
struct sk_buff *frag_iter;
int i, copy;
if (offset > (int)skb->len - len)
goto fault;
if ((copy = start - offset) > 0) {
if (copy > len)
copy = len;
skb_copy_to_linear_data_offset(skb, offset, from, copy);
if ((len -= copy) == 0)
return 0;
offset += copy;
from += copy;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
int end;
WARN_ON(start > offset + len);
end = start + skb_frag_size(frag);
if ((copy = end - offset) > 0) {
u8 *vaddr;
if (copy > len)
copy = len;
vaddr = kmap_atomic(skb_frag_page(frag));
memcpy(vaddr + frag->page_offset + offset - start,
from, copy);
kunmap_atomic(vaddr);
if ((len -= copy) == 0)
return 0;
offset += copy;
from += copy;
}
start = end;
}
skb_walk_frags(skb, frag_iter) {
int end;
WARN_ON(start > offset + len);
end = start + frag_iter->len;
if ((copy = end - offset) > 0) {
if (copy > len)
copy = len;
if (skb_store_bits(frag_iter, offset - start,
from, copy))
goto fault;
if ((len -= copy) == 0)
return 0;
offset += copy;
from += copy;
}
start = end;
}
if (!len)
return 0;
fault:
return -EFAULT;
}
__wsum __skb_checksum(const struct sk_buff *skb, int offset, int len,
__wsum csum, const struct skb_checksum_ops *ops)
{
int start = skb_headlen(skb);
int i, copy = start - offset;
struct sk_buff *frag_iter;
int pos = 0;
if (copy > 0) {
if (copy > len)
copy = len;
csum = ops->update(skb->data + offset, copy, csum);
if ((len -= copy) == 0)
return csum;
offset += copy;
pos = copy;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int end;
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
WARN_ON(start > offset + len);
end = start + skb_frag_size(frag);
if ((copy = end - offset) > 0) {
__wsum csum2;
u8 *vaddr;
if (copy > len)
copy = len;
vaddr = kmap_atomic(skb_frag_page(frag));
csum2 = ops->update(vaddr + frag->page_offset +
offset - start, copy, 0);
kunmap_atomic(vaddr);
csum = ops->combine(csum, csum2, pos, copy);
if (!(len -= copy))
return csum;
offset += copy;
pos += copy;
}
start = end;
}
skb_walk_frags(skb, frag_iter) {
int end;
WARN_ON(start > offset + len);
end = start + frag_iter->len;
if ((copy = end - offset) > 0) {
__wsum csum2;
if (copy > len)
copy = len;
csum2 = __skb_checksum(frag_iter, offset - start,
copy, 0, ops);
csum = ops->combine(csum, csum2, pos, copy);
if ((len -= copy) == 0)
return csum;
offset += copy;
pos += copy;
}
start = end;
}
BUG_ON(len);
return csum;
}
__wsum skb_checksum(const struct sk_buff *skb, int offset,
int len, __wsum csum)
{
const struct skb_checksum_ops ops = {
.update = csum_partial_ext,
.combine = csum_block_add_ext,
};
return __skb_checksum(skb, offset, len, csum, &ops);
}
__wsum skb_copy_and_csum_bits(const struct sk_buff *skb, int offset,
u8 *to, int len, __wsum csum)
{
int start = skb_headlen(skb);
int i, copy = start - offset;
struct sk_buff *frag_iter;
int pos = 0;
if (copy > 0) {
if (copy > len)
copy = len;
csum = csum_partial_copy_nocheck(skb->data + offset, to,
copy, csum);
if ((len -= copy) == 0)
return csum;
offset += copy;
to += copy;
pos = copy;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int end;
WARN_ON(start > offset + len);
end = start + skb_frag_size(&skb_shinfo(skb)->frags[i]);
if ((copy = end - offset) > 0) {
__wsum csum2;
u8 *vaddr;
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
if (copy > len)
copy = len;
vaddr = kmap_atomic(skb_frag_page(frag));
csum2 = csum_partial_copy_nocheck(vaddr +
frag->page_offset +
offset - start, to,
copy, 0);
kunmap_atomic(vaddr);
csum = csum_block_add(csum, csum2, pos);
if (!(len -= copy))
return csum;
offset += copy;
to += copy;
pos += copy;
}
start = end;
}
skb_walk_frags(skb, frag_iter) {
__wsum csum2;
int end;
WARN_ON(start > offset + len);
end = start + frag_iter->len;
if ((copy = end - offset) > 0) {
if (copy > len)
copy = len;
csum2 = skb_copy_and_csum_bits(frag_iter,
offset - start,
to, copy, 0);
csum = csum_block_add(csum, csum2, pos);
if ((len -= copy) == 0)
return csum;
offset += copy;
to += copy;
pos += copy;
}
start = end;
}
BUG_ON(len);
return csum;
}
void skb_copy_and_csum_dev(const struct sk_buff *skb, u8 *to)
{
__wsum csum;
long csstart;
if (skb->ip_summed == CHECKSUM_PARTIAL)
csstart = skb_checksum_start_offset(skb);
else
csstart = skb_headlen(skb);
BUG_ON(csstart > skb_headlen(skb));
skb_copy_from_linear_data(skb, to, csstart);
csum = 0;
if (csstart != skb->len)
csum = skb_copy_and_csum_bits(skb, csstart, to + csstart,
skb->len - csstart, 0);
if (skb->ip_summed == CHECKSUM_PARTIAL) {
long csstuff = csstart + skb->csum_offset;
*((__sum16 *)(to + csstuff)) = csum_fold(csum);
}
}
struct sk_buff *skb_dequeue(struct sk_buff_head *list)
{
unsigned long flags;
struct sk_buff *result;
spin_lock_irqsave(&list->lock, flags);
result = __skb_dequeue(list);
spin_unlock_irqrestore(&list->lock, flags);
return result;
}
struct sk_buff *skb_dequeue_tail(struct sk_buff_head *list)
{
unsigned long flags;
struct sk_buff *result;
spin_lock_irqsave(&list->lock, flags);
result = __skb_dequeue_tail(list);
spin_unlock_irqrestore(&list->lock, flags);
return result;
}
void skb_queue_purge(struct sk_buff_head *list)
{
struct sk_buff *skb;
while ((skb = skb_dequeue(list)) != NULL)
kfree_skb(skb);
}
void skb_queue_head(struct sk_buff_head *list, struct sk_buff *newsk)
{
unsigned long flags;
spin_lock_irqsave(&list->lock, flags);
__skb_queue_head(list, newsk);
spin_unlock_irqrestore(&list->lock, flags);
}
void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk)
{
unsigned long flags;
spin_lock_irqsave(&list->lock, flags);
__skb_queue_tail(list, newsk);
spin_unlock_irqrestore(&list->lock, flags);
}
void skb_unlink(struct sk_buff *skb, struct sk_buff_head *list)
{
unsigned long flags;
spin_lock_irqsave(&list->lock, flags);
__skb_unlink(skb, list);
spin_unlock_irqrestore(&list->lock, flags);
}
void skb_append(struct sk_buff *old, struct sk_buff *newsk, struct sk_buff_head *list)
{
unsigned long flags;
spin_lock_irqsave(&list->lock, flags);
__skb_queue_after(list, old, newsk);
spin_unlock_irqrestore(&list->lock, flags);
}
void skb_insert(struct sk_buff *old, struct sk_buff *newsk, struct sk_buff_head *list)
{
unsigned long flags;
spin_lock_irqsave(&list->lock, flags);
__skb_insert(newsk, old->prev, old, list);
spin_unlock_irqrestore(&list->lock, flags);
}
static inline void skb_split_inside_header(struct sk_buff *skb,
struct sk_buff* skb1,
const u32 len, const int pos)
{
int i;
skb_copy_from_linear_data_offset(skb, len, skb_put(skb1, pos - len),
pos - len);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++)
skb_shinfo(skb1)->frags[i] = skb_shinfo(skb)->frags[i];
skb_shinfo(skb1)->nr_frags = skb_shinfo(skb)->nr_frags;
skb_shinfo(skb)->nr_frags = 0;
skb1->data_len = skb->data_len;
skb1->len += skb1->data_len;
skb->data_len = 0;
skb->len = len;
skb_set_tail_pointer(skb, len);
}
static inline void skb_split_no_header(struct sk_buff *skb,
struct sk_buff* skb1,
const u32 len, int pos)
{
int i, k = 0;
const int nfrags = skb_shinfo(skb)->nr_frags;
skb_shinfo(skb)->nr_frags = 0;
skb1->len = skb1->data_len = skb->len - len;
skb->len = len;
skb->data_len = len - pos;
for (i = 0; i < nfrags; i++) {
int size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
if (pos + size > len) {
skb_shinfo(skb1)->frags[k] = skb_shinfo(skb)->frags[i];
if (pos < len) {
skb_frag_ref(skb, i);
skb_shinfo(skb1)->frags[0].page_offset += len - pos;
skb_frag_size_sub(&skb_shinfo(skb1)->frags[0], len - pos);
skb_frag_size_set(&skb_shinfo(skb)->frags[i], len - pos);
skb_shinfo(skb)->nr_frags++;
}
k++;
} else
skb_shinfo(skb)->nr_frags++;
pos += size;
}
skb_shinfo(skb1)->nr_frags = k;
}
void skb_split(struct sk_buff *skb, struct sk_buff *skb1, const u32 len)
{
int pos = skb_headlen(skb);
skb_shinfo(skb1)->tx_flags = skb_shinfo(skb)->tx_flags & SKBTX_SHARED_FRAG;
if (len < pos)
skb_split_inside_header(skb, skb1, len, pos);
else
skb_split_no_header(skb, skb1, len, pos);
}
static int skb_prepare_for_shift(struct sk_buff *skb)
{
return skb_cloned(skb) && pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
}
int skb_shift(struct sk_buff *tgt, struct sk_buff *skb, int shiftlen)
{
int from, to, merge, todo;
struct skb_frag_struct *fragfrom, *fragto;
BUG_ON(shiftlen > skb->len);
BUG_ON(skb_headlen(skb));
todo = shiftlen;
from = 0;
to = skb_shinfo(tgt)->nr_frags;
fragfrom = &skb_shinfo(skb)->frags[from];
if (!to ||
!skb_can_coalesce(tgt, to, skb_frag_page(fragfrom),
fragfrom->page_offset)) {
merge = -1;
} else {
merge = to - 1;
todo -= skb_frag_size(fragfrom);
if (todo < 0) {
if (skb_prepare_for_shift(skb) ||
skb_prepare_for_shift(tgt))
return 0;
fragfrom = &skb_shinfo(skb)->frags[from];
fragto = &skb_shinfo(tgt)->frags[merge];
skb_frag_size_add(fragto, shiftlen);
skb_frag_size_sub(fragfrom, shiftlen);
fragfrom->page_offset += shiftlen;
goto onlymerged;
}
from++;
}
if ((shiftlen == skb->len) &&
(skb_shinfo(skb)->nr_frags - from) > (MAX_SKB_FRAGS - to))
return 0;
if (skb_prepare_for_shift(skb) || skb_prepare_for_shift(tgt))
return 0;
while ((todo > 0) && (from < skb_shinfo(skb)->nr_frags)) {
if (to == MAX_SKB_FRAGS)
return 0;
fragfrom = &skb_shinfo(skb)->frags[from];
fragto = &skb_shinfo(tgt)->frags[to];
if (todo >= skb_frag_size(fragfrom)) {
*fragto = *fragfrom;
todo -= skb_frag_size(fragfrom);
from++;
to++;
} else {
__skb_frag_ref(fragfrom);
fragto->page = fragfrom->page;
fragto->page_offset = fragfrom->page_offset;
skb_frag_size_set(fragto, todo);
fragfrom->page_offset += todo;
skb_frag_size_sub(fragfrom, todo);
todo = 0;
to++;
break;
}
}
skb_shinfo(tgt)->nr_frags = to;
if (merge >= 0) {
fragfrom = &skb_shinfo(skb)->frags[0];
fragto = &skb_shinfo(tgt)->frags[merge];
skb_frag_size_add(fragto, skb_frag_size(fragfrom));
__skb_frag_unref(fragfrom);
}
to = 0;
while (from < skb_shinfo(skb)->nr_frags)
skb_shinfo(skb)->frags[to++] = skb_shinfo(skb)->frags[from++];
skb_shinfo(skb)->nr_frags = to;
BUG_ON(todo > 0 && !skb_shinfo(skb)->nr_frags);
onlymerged:
tgt->ip_summed = CHECKSUM_PARTIAL;
skb->ip_summed = CHECKSUM_PARTIAL;
skb->len -= shiftlen;
skb->data_len -= shiftlen;
skb->truesize -= shiftlen;
tgt->len += shiftlen;
tgt->data_len += shiftlen;
tgt->truesize += shiftlen;
return shiftlen;
}
void skb_prepare_seq_read(struct sk_buff *skb, unsigned int from,
unsigned int to, struct skb_seq_state *st)
{
st->lower_offset = from;
st->upper_offset = to;
st->root_skb = st->cur_skb = skb;
st->frag_idx = st->stepped_offset = 0;
st->frag_data = NULL;
}
unsigned int skb_seq_read(unsigned int consumed, const u8 **data,
struct skb_seq_state *st)
{
unsigned int block_limit, abs_offset = consumed + st->lower_offset;
skb_frag_t *frag;
if (unlikely(abs_offset >= st->upper_offset)) {
if (st->frag_data) {
kunmap_atomic(st->frag_data);
st->frag_data = NULL;
}
return 0;
}
next_skb:
block_limit = skb_headlen(st->cur_skb) + st->stepped_offset;
if (abs_offset < block_limit && !st->frag_data) {
*data = st->cur_skb->data + (abs_offset - st->stepped_offset);
return block_limit - abs_offset;
}
if (st->frag_idx == 0 && !st->frag_data)
st->stepped_offset += skb_headlen(st->cur_skb);
while (st->frag_idx < skb_shinfo(st->cur_skb)->nr_frags) {
frag = &skb_shinfo(st->cur_skb)->frags[st->frag_idx];
block_limit = skb_frag_size(frag) + st->stepped_offset;
if (abs_offset < block_limit) {
if (!st->frag_data)
st->frag_data = kmap_atomic(skb_frag_page(frag));
*data = (u8 *) st->frag_data + frag->page_offset +
(abs_offset - st->stepped_offset);
return block_limit - abs_offset;
}
if (st->frag_data) {
kunmap_atomic(st->frag_data);
st->frag_data = NULL;
}
st->frag_idx++;
st->stepped_offset += skb_frag_size(frag);
}
if (st->frag_data) {
kunmap_atomic(st->frag_data);
st->frag_data = NULL;
}
if (st->root_skb == st->cur_skb && skb_has_frag_list(st->root_skb)) {
st->cur_skb = skb_shinfo(st->root_skb)->frag_list;
st->frag_idx = 0;
goto next_skb;
} else if (st->cur_skb->next) {
st->cur_skb = st->cur_skb->next;
st->frag_idx = 0;
goto next_skb;
}
return 0;
}
void skb_abort_seq_read(struct skb_seq_state *st)
{
if (st->frag_data)
kunmap_atomic(st->frag_data);
}
static unsigned int skb_ts_get_next_block(unsigned int offset, const u8 **text,
struct ts_config *conf,
struct ts_state *state)
{
return skb_seq_read(offset, text, TS_SKB_CB(state));
}
static void skb_ts_finish(struct ts_config *conf, struct ts_state *state)
{
skb_abort_seq_read(TS_SKB_CB(state));
}
unsigned int skb_find_text(struct sk_buff *skb, unsigned int from,
unsigned int to, struct ts_config *config,
struct ts_state *state)
{
unsigned int ret;
config->get_next_block = skb_ts_get_next_block;
config->finish = skb_ts_finish;
skb_prepare_seq_read(skb, from, to, TS_SKB_CB(state));
ret = textsearch_find(config, state);
return (ret <= to - from ? ret : UINT_MAX);
}
int skb_append_datato_frags(struct sock *sk, struct sk_buff *skb,
int (*getfrag)(void *from, char *to, int offset,
int len, int odd, struct sk_buff *skb),
void *from, int length)
{
int frg_cnt = skb_shinfo(skb)->nr_frags;
int copy;
int offset = 0;
int ret;
struct page_frag *pfrag = &current->task_frag;
do {
if (frg_cnt >= MAX_SKB_FRAGS)
return -EMSGSIZE;
if (!sk_page_frag_refill(sk, pfrag))
return -ENOMEM;
copy = min_t(int, length, pfrag->size - pfrag->offset);
ret = getfrag(from, page_address(pfrag->page) + pfrag->offset,
offset, copy, 0, skb);
if (ret < 0)
return -EFAULT;
skb_fill_page_desc(skb, frg_cnt, pfrag->page, pfrag->offset,
copy);
frg_cnt++;
pfrag->offset += copy;
get_page(pfrag->page);
skb->truesize += copy;
atomic_add(copy, &sk->sk_wmem_alloc);
skb->len += copy;
skb->data_len += copy;
offset += copy;
length -= copy;
} while (length > 0);
return 0;
}
unsigned char *skb_pull_rcsum(struct sk_buff *skb, unsigned int len)
{
BUG_ON(len > skb->len);
skb->len -= len;
BUG_ON(skb->len < skb->data_len);
skb_postpull_rcsum(skb, skb->data, len);
return skb->data += len;
}
struct sk_buff *skb_segment(struct sk_buff *skb, netdev_features_t features)
{
struct sk_buff *segs = NULL;
struct sk_buff *tail = NULL;
struct sk_buff *fskb = skb_shinfo(skb)->frag_list;
skb_frag_t *skb_frag = skb_shinfo(skb)->frags;
unsigned int mss = skb_shinfo(skb)->gso_size;
unsigned int doffset = skb->data - skb_mac_header(skb);
unsigned int offset = doffset;
unsigned int tnl_hlen = skb_tnl_header_len(skb);
unsigned int headroom;
unsigned int len;
__be16 proto;
bool csum;
int sg = !!(features & NETIF_F_SG);
int nfrags = skb_shinfo(skb)->nr_frags;
int err = -ENOMEM;
int i = 0;
int pos;
proto = skb_network_protocol(skb);
if (unlikely(!proto))
return ERR_PTR(-EINVAL);
csum = !!can_checksum_protocol(features, proto);
__skb_push(skb, doffset);
headroom = skb_headroom(skb);
pos = skb_headlen(skb);
do {
struct sk_buff *nskb;
skb_frag_t *frag;
int hsize;
int size;
len = skb->len - offset;
if (len > mss)
len = mss;
hsize = skb_headlen(skb) - offset;
if (hsize < 0)
hsize = 0;
if (hsize > len || !sg)
hsize = len;
if (!hsize && i >= nfrags && skb_headlen(fskb) &&
(skb_headlen(fskb) == len || sg)) {
BUG_ON(skb_headlen(fskb) > len);
i = 0;
nfrags = skb_shinfo(fskb)->nr_frags;
skb_frag = skb_shinfo(fskb)->frags;
pos += skb_headlen(fskb);
while (pos < offset + len) {
BUG_ON(i >= nfrags);
size = skb_frag_size(skb_frag);
if (pos + size > offset + len)
break;
i++;
pos += size;
skb_frag++;
}
nskb = skb_clone(fskb, GFP_ATOMIC);
fskb = fskb->next;
if (unlikely(!nskb))
goto err;
if (unlikely(pskb_trim(nskb, len))) {
kfree_skb(nskb);
goto err;
}
hsize = skb_end_offset(nskb);
if (skb_cow_head(nskb, doffset + headroom)) {
kfree_skb(nskb);
goto err;
}
nskb->truesize += skb_end_offset(nskb) - hsize;
skb_release_head_state(nskb);
__skb_push(nskb, doffset);
} else {
nskb = __alloc_skb(hsize + doffset + headroom,
GFP_ATOMIC, skb_alloc_rx_flag(skb),
NUMA_NO_NODE);
if (unlikely(!nskb))
goto err;
skb_reserve(nskb, headroom);
__skb_put(nskb, doffset);
}
if (segs)
tail->next = nskb;
else
segs = nskb;
tail = nskb;
__copy_skb_header(nskb, skb);
nskb->mac_len = skb->mac_len;
skb_headers_offset_update(nskb, skb_headroom(nskb) - headroom);
skb_copy_from_linear_data_offset(skb, -tnl_hlen,
nskb->data - tnl_hlen,
doffset + tnl_hlen);
if (nskb->len == len + doffset)
goto perform_csum_check;
if (!sg) {
nskb->ip_summed = CHECKSUM_NONE;
nskb->csum = skb_copy_and_csum_bits(skb, offset,
skb_put(nskb, len),
len, 0);
continue;
}
frag = skb_shinfo(nskb)->frags;
skb_copy_from_linear_data_offset(skb, offset,
skb_put(nskb, hsize), hsize);
skb_shinfo(nskb)->tx_flags = skb_shinfo(skb)->tx_flags & SKBTX_SHARED_FRAG;
while (pos < offset + len) {
if (i >= nfrags) {
BUG_ON(skb_headlen(fskb));
i = 0;
nfrags = skb_shinfo(fskb)->nr_frags;
skb_frag = skb_shinfo(fskb)->frags;
BUG_ON(!nfrags);
fskb = fskb->next;
}
if (unlikely(skb_shinfo(nskb)->nr_frags >=
MAX_SKB_FRAGS)) {
net_warn_ratelimited(
"skb_segment: too many frags: %u %u\n",
pos, mss);
goto err;
}
*frag = *skb_frag;
__skb_frag_ref(frag);
size = skb_frag_size(frag);
if (pos < offset) {
frag->page_offset += offset - pos;
skb_frag_size_sub(frag, offset - pos);
}
skb_shinfo(nskb)->nr_frags++;
if (pos + size <= offset + len) {
i++;
skb_frag++;
pos += size;
} else {
skb_frag_size_sub(frag, pos + size - (offset + len));
goto skip_fraglist;
}
frag++;
}
skip_fraglist:
nskb->data_len = len - hsize;
nskb->len += nskb->data_len;
nskb->truesize += nskb->data_len;
perform_csum_check:
if (!csum) {
nskb->csum = skb_checksum(nskb, doffset,
nskb->len - doffset, 0);
nskb->ip_summed = CHECKSUM_NONE;
}
} while ((offset += len) < skb->len);
return segs;
err:
while ((skb = segs)) {
segs = skb->next;
kfree_skb(skb);
}
return ERR_PTR(err);
}
int skb_gro_receive(struct sk_buff **head, struct sk_buff *skb)
{
struct skb_shared_info *pinfo, *skbinfo = skb_shinfo(skb);
unsigned int offset = skb_gro_offset(skb);
unsigned int headlen = skb_headlen(skb);
struct sk_buff *nskb, *lp, *p = *head;
unsigned int len = skb_gro_len(skb);
unsigned int delta_truesize;
unsigned int headroom;
if (unlikely(p->len + len >= 65536))
return -E2BIG;
lp = NAPI_GRO_CB(p)->last ?: p;
pinfo = skb_shinfo(lp);
if (headlen <= offset) {
skb_frag_t *frag;
skb_frag_t *frag2;
int i = skbinfo->nr_frags;
int nr_frags = pinfo->nr_frags + i;
if (nr_frags > MAX_SKB_FRAGS)
goto merge;
offset -= headlen;
pinfo->nr_frags = nr_frags;
skbinfo->nr_frags = 0;
frag = pinfo->frags + nr_frags;
frag2 = skbinfo->frags + i;
do {
*--frag = *--frag2;
} while (--i);
frag->page_offset += offset;
skb_frag_size_sub(frag, offset);
delta_truesize = skb->truesize -
SKB_TRUESIZE(skb_end_offset(skb));
skb->truesize -= skb->data_len;
skb->len -= skb->data_len;
skb->data_len = 0;
NAPI_GRO_CB(skb)->free = NAPI_GRO_FREE;
goto done;
} else if (skb->head_frag) {
int nr_frags = pinfo->nr_frags;
skb_frag_t *frag = pinfo->frags + nr_frags;
struct page *page = virt_to_head_page(skb->head);
unsigned int first_size = headlen - offset;
unsigned int first_offset;
if (nr_frags + 1 + skbinfo->nr_frags > MAX_SKB_FRAGS)
goto merge;
first_offset = skb->data -
(unsigned char *)page_address(page) +
offset;
pinfo->nr_frags = nr_frags + 1 + skbinfo->nr_frags;
frag->page.p = page;
frag->page_offset = first_offset;
skb_frag_size_set(frag, first_size);
memcpy(frag + 1, skbinfo->frags, sizeof(*frag) * skbinfo->nr_frags);
delta_truesize = skb->truesize - SKB_DATA_ALIGN(sizeof(struct sk_buff));
NAPI_GRO_CB(skb)->free = NAPI_GRO_FREE_STOLEN_HEAD;
goto done;
}
if (pinfo->frag_list)
goto merge;
if (skb_gro_len(p) != pinfo->gso_size)
return -E2BIG;
headroom = skb_headroom(p);
nskb = alloc_skb(headroom + skb_gro_offset(p), GFP_ATOMIC);
if (unlikely(!nskb))
return -ENOMEM;
__copy_skb_header(nskb, p);
nskb->mac_len = p->mac_len;
skb_reserve(nskb, headroom);
__skb_put(nskb, skb_gro_offset(p));
skb_set_mac_header(nskb, skb_mac_header(p) - p->data);
skb_set_network_header(nskb, skb_network_offset(p));
skb_set_transport_header(nskb, skb_transport_offset(p));
__skb_pull(p, skb_gro_offset(p));
memcpy(skb_mac_header(nskb), skb_mac_header(p),
p->data - skb_mac_header(p));
skb_shinfo(nskb)->frag_list = p;
skb_shinfo(nskb)->gso_size = pinfo->gso_size;
pinfo->gso_size = 0;
skb_header_release(p);
NAPI_GRO_CB(nskb)->last = p;
nskb->data_len += p->len;
nskb->truesize += p->truesize;
nskb->len += p->len;
*head = nskb;
nskb->next = p->next;
p->next = NULL;
p = nskb;
merge:
delta_truesize = skb->truesize;
if (offset > headlen) {
unsigned int eat = offset - headlen;
skbinfo->frags[0].page_offset += eat;
skb_frag_size_sub(&skbinfo->frags[0], eat);
skb->data_len -= eat;
skb->len -= eat;
offset = headlen;
}
__skb_pull(skb, offset);
if (!NAPI_GRO_CB(p)->last)
skb_shinfo(p)->frag_list = skb;
else
NAPI_GRO_CB(p)->last->next = skb;
NAPI_GRO_CB(p)->last = skb;
skb_header_release(skb);
lp = p;
done:
NAPI_GRO_CB(p)->count++;
p->data_len += len;
p->truesize += delta_truesize;
p->len += len;
if (lp != p) {
lp->data_len += len;
lp->truesize += delta_truesize;
lp->len += len;
}
NAPI_GRO_CB(skb)->same_flow = 1;
return 0;
}
void __init skb_init(void)
{
skbuff_head_cache = kmem_cache_create("skbuff_head_cache",
sizeof(struct sk_buff),
0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC,
NULL);
skbuff_fclone_cache = kmem_cache_create("skbuff_fclone_cache",
(2*sizeof(struct sk_buff)) +
sizeof(atomic_t),
0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC,
NULL);
}
static int
__skb_to_sgvec(struct sk_buff *skb, struct scatterlist *sg, int offset, int len)
{
int start = skb_headlen(skb);
int i, copy = start - offset;
struct sk_buff *frag_iter;
int elt = 0;
if (copy > 0) {
if (copy > len)
copy = len;
sg_set_buf(sg, skb->data + offset, copy);
elt++;
if ((len -= copy) == 0)
return elt;
offset += copy;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int end;
WARN_ON(start > offset + len);
end = start + skb_frag_size(&skb_shinfo(skb)->frags[i]);
if ((copy = end - offset) > 0) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
if (copy > len)
copy = len;
sg_set_page(&sg[elt], skb_frag_page(frag), copy,
frag->page_offset+offset-start);
elt++;
if (!(len -= copy))
return elt;
offset += copy;
}
start = end;
}
skb_walk_frags(skb, frag_iter) {
int end;
WARN_ON(start > offset + len);
end = start + frag_iter->len;
if ((copy = end - offset) > 0) {
if (copy > len)
copy = len;
elt += __skb_to_sgvec(frag_iter, sg+elt, offset - start,
copy);
if ((len -= copy) == 0)
return elt;
offset += copy;
}
start = end;
}
BUG_ON(len);
return elt;
}
int skb_to_sgvec(struct sk_buff *skb, struct scatterlist *sg, int offset, int len)
{
int nsg = __skb_to_sgvec(skb, sg, offset, len);
sg_mark_end(&sg[nsg - 1]);
return nsg;
}
int skb_cow_data(struct sk_buff *skb, int tailbits, struct sk_buff **trailer)
{
int copyflag;
int elt;
struct sk_buff *skb1, **skb_p;
if ((skb_cloned(skb) || skb_shinfo(skb)->nr_frags) &&
__pskb_pull_tail(skb, skb_pagelen(skb)-skb_headlen(skb)) == NULL)
return -ENOMEM;
if (!skb_has_frag_list(skb)) {
if (skb_tailroom(skb) < tailbits &&
pskb_expand_head(skb, 0, tailbits-skb_tailroom(skb)+128, GFP_ATOMIC))
return -ENOMEM;
*trailer = skb;
return 1;
}
elt = 1;
skb_p = &skb_shinfo(skb)->frag_list;
copyflag = 0;
while ((skb1 = *skb_p) != NULL) {
int ntail = 0;
if (skb_shared(skb1))
copyflag = 1;
if (skb1->next == NULL && tailbits) {
if (skb_shinfo(skb1)->nr_frags ||
skb_has_frag_list(skb1) ||
skb_tailroom(skb1) < tailbits)
ntail = tailbits + 128;
}
if (copyflag ||
skb_cloned(skb1) ||
ntail ||
skb_shinfo(skb1)->nr_frags ||
skb_has_frag_list(skb1)) {
struct sk_buff *skb2;
if (ntail == 0)
skb2 = skb_copy(skb1, GFP_ATOMIC);
else
skb2 = skb_copy_expand(skb1,
skb_headroom(skb1),
ntail,
GFP_ATOMIC);
if (unlikely(skb2 == NULL))
return -ENOMEM;
if (skb1->sk)
skb_set_owner_w(skb2, skb1->sk);
skb2->next = skb1->next;
*skb_p = skb2;
kfree_skb(skb1);
skb1 = skb2;
}
elt++;
*trailer = skb1;
skb_p = &skb1->next;
}
return elt;
}
static void sock_rmem_free(struct sk_buff *skb)
{
struct sock *sk = skb->sk;
atomic_sub(skb->truesize, &sk->sk_rmem_alloc);
}
int sock_queue_err_skb(struct sock *sk, struct sk_buff *skb)
{
int len = skb->len;
if (atomic_read(&sk->sk_rmem_alloc) + skb->truesize >=
(unsigned int)sk->sk_rcvbuf)
return -ENOMEM;
skb_orphan(skb);
skb->sk = sk;
skb->destructor = sock_rmem_free;
atomic_add(skb->truesize, &sk->sk_rmem_alloc);
skb_dst_force(skb);
skb_queue_tail(&sk->sk_error_queue, skb);
if (!sock_flag(sk, SOCK_DEAD))
sk->sk_data_ready(sk, len);
return 0;
}
void skb_tstamp_tx(struct sk_buff *orig_skb,
struct skb_shared_hwtstamps *hwtstamps)
{
struct sock *sk = orig_skb->sk;
struct sock_exterr_skb *serr;
struct sk_buff *skb;
int err;
if (!sk)
return;
if (hwtstamps) {
*skb_hwtstamps(orig_skb) =
*hwtstamps;
} else {
orig_skb->tstamp = ktime_get_real();
}
skb = skb_clone(orig_skb, GFP_ATOMIC);
if (!skb)
return;
serr = SKB_EXT_ERR(skb);
memset(serr, 0, sizeof(*serr));
serr->ee.ee_errno = ENOMSG;
serr->ee.ee_origin = SO_EE_ORIGIN_TIMESTAMPING;
err = sock_queue_err_skb(sk, skb);
if (err)
kfree_skb(skb);
}
void skb_complete_wifi_ack(struct sk_buff *skb, bool acked)
{
struct sock *sk = skb->sk;
struct sock_exterr_skb *serr;
int err;
skb->wifi_acked_valid = 1;
skb->wifi_acked = acked;
serr = SKB_EXT_ERR(skb);
memset(serr, 0, sizeof(*serr));
serr->ee.ee_errno = ENOMSG;
serr->ee.ee_origin = SO_EE_ORIGIN_TXSTATUS;
err = sock_queue_err_skb(sk, skb);
if (err)
kfree_skb(skb);
}
bool skb_partial_csum_set(struct sk_buff *skb, u16 start, u16 off)
{
if (unlikely(start > skb_headlen(skb)) ||
unlikely((int)start + off > skb_headlen(skb) - 2)) {
net_warn_ratelimited("bad partial csum: csum=%u/%u len=%u\n",
start, off, skb_headlen(skb));
return false;
}
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum_start = skb_headroom(skb) + start;
skb->csum_offset = off;
skb_set_transport_header(skb, start);
return true;
}
void __skb_warn_lro_forwarding(const struct sk_buff *skb)
{
net_warn_ratelimited("%s: received packets cannot be forwarded while LRO is enabled\n",
skb->dev->name);
}
void kfree_skb_partial(struct sk_buff *skb, bool head_stolen)
{
if (head_stolen) {
skb_release_head_state(skb);
kmem_cache_free(skbuff_head_cache, skb);
} else {
__kfree_skb(skb);
}
}
bool skb_try_coalesce(struct sk_buff *to, struct sk_buff *from,
bool *fragstolen, int *delta_truesize)
{
int i, delta, len = from->len;
*fragstolen = false;
if (skb_cloned(to))
return false;
if (len <= skb_tailroom(to)) {
BUG_ON(skb_copy_bits(from, 0, skb_put(to, len), len));
*delta_truesize = 0;
return true;
}
if (skb_has_frag_list(to) || skb_has_frag_list(from))
return false;
if (skb_headlen(from) != 0) {
struct page *page;
unsigned int offset;
if (skb_shinfo(to)->nr_frags +
skb_shinfo(from)->nr_frags >= MAX_SKB_FRAGS)
return false;
if (skb_head_is_locked(from))
return false;
delta = from->truesize - SKB_DATA_ALIGN(sizeof(struct sk_buff));
page = virt_to_head_page(from->head);
offset = from->data - (unsigned char *)page_address(page);
skb_fill_page_desc(to, skb_shinfo(to)->nr_frags,
page, offset, skb_headlen(from));
*fragstolen = true;
} else {
if (skb_shinfo(to)->nr_frags +
skb_shinfo(from)->nr_frags > MAX_SKB_FRAGS)
return false;
delta = from->truesize - SKB_TRUESIZE(skb_end_offset(from));
}
WARN_ON_ONCE(delta < len);
memcpy(skb_shinfo(to)->frags + skb_shinfo(to)->nr_frags,
skb_shinfo(from)->frags,
skb_shinfo(from)->nr_frags * sizeof(skb_frag_t));
skb_shinfo(to)->nr_frags += skb_shinfo(from)->nr_frags;
if (!skb_cloned(from))
skb_shinfo(from)->nr_frags = 0;
for (i = 0; i < skb_shinfo(from)->nr_frags; i++)
skb_frag_ref(from, i);
to->truesize += delta;
to->len += len;
to->data_len += len;
*delta_truesize = delta;
return true;
}
void skb_scrub_packet(struct sk_buff *skb, bool xnet)
{
if (xnet)
skb_orphan(skb);
skb->tstamp.tv64 = 0;
skb->pkt_type = PACKET_HOST;
skb->skb_iif = 0;
skb->local_df = 0;
skb_dst_drop(skb);
skb->mark = 0;
secpath_reset(skb);
nf_reset(skb);
nf_reset_trace(skb);
}
