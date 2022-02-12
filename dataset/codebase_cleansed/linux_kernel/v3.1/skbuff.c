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
static void skb_over_panic(struct sk_buff *skb, int sz, void *here)
{
printk(KERN_EMERG "skb_over_panic: text:%p len:%d put:%d head:%p "
"data:%p tail:%#lx end:%#lx dev:%s\n",
here, skb->len, sz, skb->head, skb->data,
(unsigned long)skb->tail, (unsigned long)skb->end,
skb->dev ? skb->dev->name : "<NULL>");
BUG();
}
static void skb_under_panic(struct sk_buff *skb, int sz, void *here)
{
printk(KERN_EMERG "skb_under_panic: text:%p len:%d put:%d head:%p "
"data:%p tail:%#lx end:%#lx dev:%s\n",
here, skb->len, sz, skb->head, skb->data,
(unsigned long)skb->tail, (unsigned long)skb->end,
skb->dev ? skb->dev->name : "<NULL>");
BUG();
}
struct sk_buff *__alloc_skb(unsigned int size, gfp_t gfp_mask,
int fclone, int node)
{
struct kmem_cache *cache;
struct skb_shared_info *shinfo;
struct sk_buff *skb;
u8 *data;
cache = fclone ? skbuff_fclone_cache : skbuff_head_cache;
skb = kmem_cache_alloc_node(cache, gfp_mask & ~__GFP_DMA, node);
if (!skb)
goto out;
prefetchw(skb);
size = SKB_DATA_ALIGN(size);
data = kmalloc_node_track_caller(size + sizeof(struct skb_shared_info),
gfp_mask, node);
if (!data)
goto nodata;
prefetchw(data + size);
memset(skb, 0, offsetof(struct sk_buff, tail));
skb->truesize = size + sizeof(struct sk_buff);
atomic_set(&skb->users, 1);
skb->head = data;
skb->data = data;
skb_reset_tail_pointer(skb);
skb->end = skb->tail + size;
#ifdef NET_SKBUFF_DATA_USES_OFFSET
skb->mac_header = ~0U;
#endif
shinfo = skb_shinfo(skb);
memset(shinfo, 0, offsetof(struct skb_shared_info, dataref));
atomic_set(&shinfo->dataref, 1);
kmemcheck_annotate_variable(shinfo->destructor_arg);
if (fclone) {
struct sk_buff *child = skb + 1;
atomic_t *fclone_ref = (atomic_t *) (child + 1);
kmemcheck_annotate_bitfield(child, flags1);
kmemcheck_annotate_bitfield(child, flags2);
skb->fclone = SKB_FCLONE_ORIG;
atomic_set(fclone_ref, 1);
child->fclone = SKB_FCLONE_UNAVAILABLE;
}
out:
return skb;
nodata:
kmem_cache_free(cache, skb);
skb = NULL;
goto out;
}
struct sk_buff *__netdev_alloc_skb(struct net_device *dev,
unsigned int length, gfp_t gfp_mask)
{
struct sk_buff *skb;
skb = __alloc_skb(length + NET_SKB_PAD, gfp_mask, 0, NUMA_NO_NODE);
if (likely(skb)) {
skb_reserve(skb, NET_SKB_PAD);
skb->dev = dev;
}
return skb;
}
void skb_add_rx_frag(struct sk_buff *skb, int i, struct page *page, int off,
int size)
{
skb_fill_page_desc(skb, i, page, off, size);
skb->len += size;
skb->data_len += size;
skb->truesize += size;
}
struct sk_buff *dev_alloc_skb(unsigned int length)
{
return __dev_alloc_skb(length, GFP_ATOMIC);
}
static void skb_drop_list(struct sk_buff **listp)
{
struct sk_buff *list = *listp;
*listp = NULL;
do {
struct sk_buff *this = list;
list = list->next;
kfree_skb(this);
} while (list);
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
static void skb_release_data(struct sk_buff *skb)
{
if (!skb->cloned ||
!atomic_sub_return(skb->nohdr ? (1 << SKB_DATAREF_SHIFT) + 1 : 1,
&skb_shinfo(skb)->dataref)) {
if (skb_shinfo(skb)->nr_frags) {
int i;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++)
put_page(skb_shinfo(skb)->frags[i].page);
}
if (skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY) {
struct ubuf_info *uarg;
uarg = skb_shinfo(skb)->destructor_arg;
if (uarg->callback)
uarg->callback(uarg);
}
if (skb_has_frag_list(skb))
skb_drop_fraglist(skb);
kfree(skb->head);
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
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
nf_conntrack_put(skb->nfct);
#endif
#ifdef NET_SKBUFF_NF_DEFRAG_NEEDED
nf_conntrack_put_reasm(skb->nfct_reasm);
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
bool skb_recycle_check(struct sk_buff *skb, int skb_size)
{
struct skb_shared_info *shinfo;
if (irqs_disabled())
return false;
if (skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY)
return false;
if (skb_is_nonlinear(skb) || skb->fclone != SKB_FCLONE_UNAVAILABLE)
return false;
skb_size = SKB_DATA_ALIGN(skb_size + NET_SKB_PAD);
if (skb_end_pointer(skb) - skb->head < skb_size)
return false;
if (skb_shared(skb) || skb_cloned(skb))
return false;
skb_release_head_state(skb);
shinfo = skb_shinfo(skb);
memset(shinfo, 0, offsetof(struct skb_shared_info, dataref));
atomic_set(&shinfo->dataref, 1);
memset(skb, 0, offsetof(struct sk_buff, tail));
skb->data = skb->head + NET_SKB_PAD;
skb_reset_tail_pointer(skb);
return true;
}
static void __copy_skb_header(struct sk_buff *new, const struct sk_buff *old)
{
new->tstamp = old->tstamp;
new->dev = old->dev;
new->transport_header = old->transport_header;
new->network_header = old->network_header;
new->mac_header = old->mac_header;
skb_dst_copy(new, old);
new->rxhash = old->rxhash;
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
#if defined(CONFIG_IP_VS) || defined(CONFIG_IP_VS_MODULE)
new->ipvs_property = old->ipvs_property;
#endif
new->protocol = old->protocol;
new->mark = old->mark;
new->skb_iif = old->skb_iif;
__nf_copy(new, old);
#if defined(CONFIG_NETFILTER_XT_TARGET_TRACE) || \
defined(CONFIG_NETFILTER_XT_TARGET_TRACE_MODULE)
new->nf_trace = old->nf_trace;
#endif
#ifdef CONFIG_NET_SCHED
new->tc_index = old->tc_index;
#ifdef CONFIG_NET_CLS_ACT
new->tc_verd = old->tc_verd;
#endif
#endif
new->vlan_tci = old->vlan_tci;
skb_copy_secmark(new, old);
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
page = alloc_page(GFP_ATOMIC);
if (!page) {
while (head) {
struct page *next = (struct page *)head->private;
put_page(head);
head = next;
}
return -ENOMEM;
}
vaddr = kmap_skb_frag(&skb_shinfo(skb)->frags[i]);
memcpy(page_address(page),
vaddr + f->page_offset, f->size);
kunmap_skb_frag(vaddr);
page->private = (unsigned long)head;
head = page;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++)
put_page(skb_shinfo(skb)->frags[i].page);
uarg->callback(uarg);
for (i = skb_shinfo(skb)->nr_frags; i > 0; i--) {
skb_shinfo(skb)->frags[i - 1].page_offset = 0;
skb_shinfo(skb)->frags[i - 1].page = head;
head = (struct page *)head->private;
}
skb_shinfo(skb)->tx_flags &= ~SKBTX_DEV_ZEROCOPY;
return 0;
}
struct sk_buff *skb_clone(struct sk_buff *skb, gfp_t gfp_mask)
{
struct sk_buff *n;
if (skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY) {
if (skb_copy_ubufs(skb, gfp_mask))
return NULL;
}
n = skb + 1;
if (skb->fclone == SKB_FCLONE_ORIG &&
n->fclone == SKB_FCLONE_UNAVAILABLE) {
atomic_t *fclone_ref = (atomic_t *) (n + 1);
n->fclone = SKB_FCLONE_CLONE;
atomic_inc(fclone_ref);
} else {
n = kmem_cache_alloc(skbuff_head_cache, gfp_mask);
if (!n)
return NULL;
kmemcheck_annotate_bitfield(n, flags1);
kmemcheck_annotate_bitfield(n, flags2);
n->fclone = SKB_FCLONE_UNAVAILABLE;
}
return __skb_clone(n, skb);
}
static void copy_skb_header(struct sk_buff *new, const struct sk_buff *old)
{
#ifndef NET_SKBUFF_DATA_USES_OFFSET
unsigned long offset = new->data - old->data;
#endif
__copy_skb_header(new, old);
#ifndef NET_SKBUFF_DATA_USES_OFFSET
new->transport_header += offset;
new->network_header += offset;
if (skb_mac_header_was_set(new))
new->mac_header += offset;
#endif
skb_shinfo(new)->gso_size = skb_shinfo(old)->gso_size;
skb_shinfo(new)->gso_segs = skb_shinfo(old)->gso_segs;
skb_shinfo(new)->gso_type = skb_shinfo(old)->gso_type;
}
struct sk_buff *skb_copy(const struct sk_buff *skb, gfp_t gfp_mask)
{
int headerlen = skb_headroom(skb);
unsigned int size = (skb_end_pointer(skb) - skb->head) + skb->data_len;
struct sk_buff *n = alloc_skb(size, gfp_mask);
if (!n)
return NULL;
skb_reserve(n, headerlen);
skb_put(n, skb->len);
if (skb_copy_bits(skb, -headerlen, n->head, headerlen + skb->len))
BUG();
copy_skb_header(n, skb);
return n;
}
struct sk_buff *pskb_copy(struct sk_buff *skb, gfp_t gfp_mask)
{
unsigned int size = skb_end_pointer(skb) - skb->head;
struct sk_buff *n = alloc_skb(size, gfp_mask);
if (!n)
goto out;
skb_reserve(n, skb_headroom(skb));
skb_put(n, skb_headlen(skb));
skb_copy_from_linear_data(skb, n->data, n->len);
n->truesize += skb->data_len;
n->data_len = skb->data_len;
n->len = skb->len;
if (skb_shinfo(skb)->nr_frags) {
int i;
if (skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY) {
if (skb_copy_ubufs(skb, gfp_mask)) {
kfree_skb(n);
n = NULL;
goto out;
}
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_shinfo(n)->frags[i] = skb_shinfo(skb)->frags[i];
get_page(skb_shinfo(n)->frags[i].page);
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
int size = nhead + (skb_end_pointer(skb) - skb->head) + ntail;
long off;
bool fastpath;
BUG_ON(nhead < 0);
if (skb_shared(skb))
BUG();
size = SKB_DATA_ALIGN(size);
if (!skb->cloned)
fastpath = true;
else {
int delta = skb->nohdr ? (1 << SKB_DATAREF_SHIFT) + 1 : 1;
fastpath = atomic_read(&skb_shinfo(skb)->dataref) == delta;
}
if (fastpath &&
size + sizeof(struct skb_shared_info) <= ksize(skb->head)) {
memmove(skb->head + size, skb_shinfo(skb),
offsetof(struct skb_shared_info,
frags[skb_shinfo(skb)->nr_frags]));
memmove(skb->head + nhead, skb->head,
skb_tail_pointer(skb) - skb->head);
off = nhead;
goto adjust_others;
}
data = kmalloc(size + sizeof(struct skb_shared_info), gfp_mask);
if (!data)
goto nodata;
memcpy(data + nhead, skb->head, skb_tail_pointer(skb) - skb->head);
memcpy((struct skb_shared_info *)(data + size),
skb_shinfo(skb),
offsetof(struct skb_shared_info, frags[skb_shinfo(skb)->nr_frags]));
if (fastpath) {
kfree(skb->head);
} else {
if (skb_shinfo(skb)->tx_flags & SKBTX_DEV_ZEROCOPY) {
if (skb_copy_ubufs(skb, gfp_mask))
goto nofrags;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++)
get_page(skb_shinfo(skb)->frags[i].page);
if (skb_has_frag_list(skb))
skb_clone_fraglist(skb);
skb_release_data(skb);
}
off = (data + nhead) - skb->head;
skb->head = data;
adjust_others:
skb->data += off;
#ifdef NET_SKBUFF_DATA_USES_OFFSET
skb->end = size;
off = nhead;
#else
skb->end = skb->head + size;
#endif
skb->tail += off;
skb->transport_header += off;
skb->network_header += off;
if (skb_mac_header_was_set(skb))
skb->mac_header += off;
if (skb->ip_summed == CHECKSUM_PARTIAL)
skb->csum_start += nhead;
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
struct sk_buff *n = alloc_skb(newheadroom + skb->len + newtailroom,
gfp_mask);
int oldheadroom = skb_headroom(skb);
int head_copy_len, head_copy_off;
int off;
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
off = newheadroom - oldheadroom;
if (n->ip_summed == CHECKSUM_PARTIAL)
n->csum_start += off;
#ifdef NET_SKBUFF_DATA_USES_OFFSET
n->transport_header += off;
n->network_header += off;
if (skb_mac_header_was_set(skb))
n->mac_header += off;
#endif
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
int end = offset + skb_shinfo(skb)->frags[i].size;
if (end < len) {
offset = end;
continue;
}
skb_shinfo(skb)->frags[i++].size = len - offset;
drop_pages:
skb_shinfo(skb)->nr_frags = i;
for (; i < nfrags; i++)
put_page(skb_shinfo(skb)->frags[i].page);
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
kfree_skb(frag);
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
if (skb_shinfo(skb)->frags[i].size >= eat)
goto pull_pages;
eat -= skb_shinfo(skb)->frags[i].size;
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
if (skb_shinfo(skb)->frags[i].size <= eat) {
put_page(skb_shinfo(skb)->frags[i].page);
eat -= skb_shinfo(skb)->frags[i].size;
} else {
skb_shinfo(skb)->frags[k] = skb_shinfo(skb)->frags[i];
if (eat) {
skb_shinfo(skb)->frags[k].page_offset += eat;
skb_shinfo(skb)->frags[k].size -= eat;
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
WARN_ON(start > offset + len);
end = start + skb_shinfo(skb)->frags[i].size;
if ((copy = end - offset) > 0) {
u8 *vaddr;
if (copy > len)
copy = len;
vaddr = kmap_skb_frag(&skb_shinfo(skb)->frags[i]);
memcpy(to,
vaddr + skb_shinfo(skb)->frags[i].page_offset+
offset - start, copy);
kunmap_skb_frag(vaddr);
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
static inline struct page *linear_to_page(struct page *page, unsigned int *len,
unsigned int *offset,
struct sk_buff *skb, struct sock *sk)
{
struct page *p = sk->sk_sndmsg_page;
unsigned int off;
if (!p) {
new_page:
p = sk->sk_sndmsg_page = alloc_pages(sk->sk_allocation, 0);
if (!p)
return NULL;
off = sk->sk_sndmsg_off = 0;
} else {
unsigned int mlen;
off = sk->sk_sndmsg_off;
mlen = PAGE_SIZE - off;
if (mlen < 64 && mlen < *len) {
put_page(p);
goto new_page;
}
*len = min_t(unsigned int, *len, mlen);
}
memcpy(page_address(p) + off, page_address(page) + *offset, *len);
sk->sk_sndmsg_off += *len;
*offset = off;
get_page(p);
return p;
}
static inline int spd_fill_page(struct splice_pipe_desc *spd,
struct pipe_inode_info *pipe, struct page *page,
unsigned int *len, unsigned int offset,
struct sk_buff *skb, int linear,
struct sock *sk)
{
if (unlikely(spd->nr_pages == pipe->buffers))
return 1;
if (linear) {
page = linear_to_page(page, len, &offset, skb, sk);
if (!page)
return 1;
} else
get_page(page);
spd->pages[spd->nr_pages] = page;
spd->partial[spd->nr_pages].len = *len;
spd->partial[spd->nr_pages].offset = offset;
spd->nr_pages++;
return 0;
}
static inline void __segment_seek(struct page **page, unsigned int *poff,
unsigned int *plen, unsigned int off)
{
unsigned long n;
*poff += off;
n = *poff / PAGE_SIZE;
if (n)
*page = nth_page(*page, n);
*poff = *poff % PAGE_SIZE;
*plen -= off;
}
static inline int __splice_segment(struct page *page, unsigned int poff,
unsigned int plen, unsigned int *off,
unsigned int *len, struct sk_buff *skb,
struct splice_pipe_desc *spd, int linear,
struct sock *sk,
struct pipe_inode_info *pipe)
{
if (!*len)
return 1;
if (*off >= plen) {
*off -= plen;
return 0;
}
if (*off) {
__segment_seek(&page, &poff, &plen, *off);
*off = 0;
}
do {
unsigned int flen = min(*len, plen);
flen = min_t(unsigned int, flen, PAGE_SIZE - poff);
if (spd_fill_page(spd, pipe, page, &flen, poff, skb, linear, sk))
return 1;
__segment_seek(&page, &poff, &plen, flen);
*len -= flen;
} while (*len && plen);
return 0;
}
static int __skb_splice_bits(struct sk_buff *skb, struct pipe_inode_info *pipe,
unsigned int *offset, unsigned int *len,
struct splice_pipe_desc *spd, struct sock *sk)
{
int seg;
if (__splice_segment(virt_to_page(skb->data),
(unsigned long) skb->data & (PAGE_SIZE - 1),
skb_headlen(skb),
offset, len, skb, spd, 1, sk, pipe))
return 1;
for (seg = 0; seg < skb_shinfo(skb)->nr_frags; seg++) {
const skb_frag_t *f = &skb_shinfo(skb)->frags[seg];
if (__splice_segment(f->page, f->page_offset, f->size,
offset, len, skb, spd, 0, sk, pipe))
return 1;
}
return 0;
}
int skb_splice_bits(struct sk_buff *skb, unsigned int offset,
struct pipe_inode_info *pipe, unsigned int tlen,
unsigned int flags)
{
struct partial_page partial[PIPE_DEF_BUFFERS];
struct page *pages[PIPE_DEF_BUFFERS];
struct splice_pipe_desc spd = {
.pages = pages,
.partial = partial,
.flags = flags,
.ops = &sock_pipe_buf_ops,
.spd_release = sock_spd_release,
};
struct sk_buff *frag_iter;
struct sock *sk = skb->sk;
int ret = 0;
if (splice_grow_spd(pipe, &spd))
return -ENOMEM;
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
splice_shrink_spd(pipe, &spd);
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
end = start + frag->size;
if ((copy = end - offset) > 0) {
u8 *vaddr;
if (copy > len)
copy = len;
vaddr = kmap_skb_frag(frag);
memcpy(vaddr + frag->page_offset + offset - start,
from, copy);
kunmap_skb_frag(vaddr);
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
__wsum skb_checksum(const struct sk_buff *skb, int offset,
int len, __wsum csum)
{
int start = skb_headlen(skb);
int i, copy = start - offset;
struct sk_buff *frag_iter;
int pos = 0;
if (copy > 0) {
if (copy > len)
copy = len;
csum = csum_partial(skb->data + offset, copy, csum);
if ((len -= copy) == 0)
return csum;
offset += copy;
pos = copy;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int end;
WARN_ON(start > offset + len);
end = start + skb_shinfo(skb)->frags[i].size;
if ((copy = end - offset) > 0) {
__wsum csum2;
u8 *vaddr;
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
if (copy > len)
copy = len;
vaddr = kmap_skb_frag(frag);
csum2 = csum_partial(vaddr + frag->page_offset +
offset - start, copy, 0);
kunmap_skb_frag(vaddr);
csum = csum_block_add(csum, csum2, pos);
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
csum2 = skb_checksum(frag_iter, offset - start,
copy, 0);
csum = csum_block_add(csum, csum2, pos);
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
end = start + skb_shinfo(skb)->frags[i].size;
if ((copy = end - offset) > 0) {
__wsum csum2;
u8 *vaddr;
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
if (copy > len)
copy = len;
vaddr = kmap_skb_frag(frag);
csum2 = csum_partial_copy_nocheck(vaddr +
frag->page_offset +
offset - start, to,
copy, 0);
kunmap_skb_frag(vaddr);
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
int size = skb_shinfo(skb)->frags[i].size;
if (pos + size > len) {
skb_shinfo(skb1)->frags[k] = skb_shinfo(skb)->frags[i];
if (pos < len) {
get_page(skb_shinfo(skb)->frags[i].page);
skb_shinfo(skb1)->frags[0].page_offset += len - pos;
skb_shinfo(skb1)->frags[0].size -= len - pos;
skb_shinfo(skb)->frags[i].size = len - pos;
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
!skb_can_coalesce(tgt, to, fragfrom->page, fragfrom->page_offset)) {
merge = -1;
} else {
merge = to - 1;
todo -= fragfrom->size;
if (todo < 0) {
if (skb_prepare_for_shift(skb) ||
skb_prepare_for_shift(tgt))
return 0;
fragfrom = &skb_shinfo(skb)->frags[from];
fragto = &skb_shinfo(tgt)->frags[merge];
fragto->size += shiftlen;
fragfrom->size -= shiftlen;
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
if (todo >= fragfrom->size) {
*fragto = *fragfrom;
todo -= fragfrom->size;
from++;
to++;
} else {
get_page(fragfrom->page);
fragto->page = fragfrom->page;
fragto->page_offset = fragfrom->page_offset;
fragto->size = todo;
fragfrom->page_offset += todo;
fragfrom->size -= todo;
todo = 0;
to++;
break;
}
}
skb_shinfo(tgt)->nr_frags = to;
if (merge >= 0) {
fragfrom = &skb_shinfo(skb)->frags[0];
fragto = &skb_shinfo(tgt)->frags[merge];
fragto->size += fragfrom->size;
put_page(fragfrom->page);
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
if (unlikely(abs_offset >= st->upper_offset))
return 0;
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
block_limit = frag->size + st->stepped_offset;
if (abs_offset < block_limit) {
if (!st->frag_data)
st->frag_data = kmap_skb_frag(frag);
*data = (u8 *) st->frag_data + frag->page_offset +
(abs_offset - st->stepped_offset);
return block_limit - abs_offset;
}
if (st->frag_data) {
kunmap_skb_frag(st->frag_data);
st->frag_data = NULL;
}
st->frag_idx++;
st->stepped_offset += frag->size;
}
if (st->frag_data) {
kunmap_skb_frag(st->frag_data);
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
kunmap_skb_frag(st->frag_data);
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
int frg_cnt = 0;
skb_frag_t *frag = NULL;
struct page *page = NULL;
int copy, left;
int offset = 0;
int ret;
do {
frg_cnt = skb_shinfo(skb)->nr_frags;
if (frg_cnt >= MAX_SKB_FRAGS)
return -EFAULT;
page = alloc_pages(sk->sk_allocation, 0);
if (page == NULL)
return -ENOMEM;
skb_fill_page_desc(skb, frg_cnt, page, 0, 0);
skb->truesize += PAGE_SIZE;
atomic_add(PAGE_SIZE, &sk->sk_wmem_alloc);
frg_cnt = skb_shinfo(skb)->nr_frags;
frag = &skb_shinfo(skb)->frags[frg_cnt - 1];
left = PAGE_SIZE - frag->page_offset;
copy = (length > left)? left : length;
ret = getfrag(from, (page_address(frag->page) +
frag->page_offset + frag->size),
offset, copy, 0, skb);
if (ret < 0)
return -EFAULT;
frag->size += copy;
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
struct sk_buff *skb_segment(struct sk_buff *skb, u32 features)
{
struct sk_buff *segs = NULL;
struct sk_buff *tail = NULL;
struct sk_buff *fskb = skb_shinfo(skb)->frag_list;
unsigned int mss = skb_shinfo(skb)->gso_size;
unsigned int doffset = skb->data - skb_mac_header(skb);
unsigned int offset = doffset;
unsigned int headroom;
unsigned int len;
int sg = !!(features & NETIF_F_SG);
int nfrags = skb_shinfo(skb)->nr_frags;
int err = -ENOMEM;
int i = 0;
int pos;
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
if (!hsize && i >= nfrags) {
BUG_ON(fskb->len != len);
pos += len;
nskb = skb_clone(fskb, GFP_ATOMIC);
fskb = fskb->next;
if (unlikely(!nskb))
goto err;
hsize = skb_end_pointer(nskb) - nskb->head;
if (skb_cow_head(nskb, doffset + headroom)) {
kfree_skb(nskb);
goto err;
}
nskb->truesize += skb_end_pointer(nskb) - nskb->head -
hsize;
skb_release_head_state(nskb);
__skb_push(nskb, doffset);
} else {
nskb = alloc_skb(hsize + doffset + headroom,
GFP_ATOMIC);
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
if (nskb->ip_summed == CHECKSUM_PARTIAL)
nskb->csum_start += skb_headroom(nskb) - headroom;
skb_reset_mac_header(nskb);
skb_set_network_header(nskb, skb->mac_len);
nskb->transport_header = (nskb->network_header +
skb_network_header_len(skb));
skb_copy_from_linear_data(skb, nskb->data, doffset);
if (fskb != skb_shinfo(skb)->frag_list)
continue;
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
while (pos < offset + len && i < nfrags) {
*frag = skb_shinfo(skb)->frags[i];
get_page(frag->page);
size = frag->size;
if (pos < offset) {
frag->page_offset += offset - pos;
frag->size -= offset - pos;
}
skb_shinfo(nskb)->nr_frags++;
if (pos + size <= offset + len) {
i++;
pos += size;
} else {
frag->size -= pos + size - (offset + len);
goto skip_fraglist;
}
frag++;
}
if (pos < offset + len) {
struct sk_buff *fskb2 = fskb;
BUG_ON(pos + fskb->len != offset + len);
pos += fskb->len;
fskb = fskb->next;
if (fskb2->next) {
fskb2 = skb_clone(fskb2, GFP_ATOMIC);
if (!fskb2)
goto err;
} else
skb_get(fskb2);
SKB_FRAG_ASSERT(nskb);
skb_shinfo(nskb)->frag_list = fskb2;
}
skip_fraglist:
nskb->data_len = len - hsize;
nskb->len += nskb->data_len;
nskb->truesize += nskb->data_len;
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
struct sk_buff *p = *head;
struct sk_buff *nskb;
struct skb_shared_info *skbinfo = skb_shinfo(skb);
struct skb_shared_info *pinfo = skb_shinfo(p);
unsigned int headroom;
unsigned int len = skb_gro_len(skb);
unsigned int offset = skb_gro_offset(skb);
unsigned int headlen = skb_headlen(skb);
if (p->len + len >= 65536)
return -E2BIG;
if (pinfo->frag_list)
goto merge;
else if (headlen <= offset) {
skb_frag_t *frag;
skb_frag_t *frag2;
int i = skbinfo->nr_frags;
int nr_frags = pinfo->nr_frags + i;
offset -= headlen;
if (nr_frags > MAX_SKB_FRAGS)
return -E2BIG;
pinfo->nr_frags = nr_frags;
skbinfo->nr_frags = 0;
frag = pinfo->frags + nr_frags;
frag2 = skbinfo->frags + i;
do {
*--frag = *--frag2;
} while (--i);
frag->page_offset += offset;
frag->size -= offset;
skb->truesize -= skb->data_len;
skb->len -= skb->data_len;
skb->data_len = 0;
NAPI_GRO_CB(skb)->free = 1;
goto done;
} else if (skb_gro_len(p) != pinfo->gso_size)
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
*NAPI_GRO_CB(nskb) = *NAPI_GRO_CB(p);
skb_shinfo(nskb)->frag_list = p;
skb_shinfo(nskb)->gso_size = pinfo->gso_size;
pinfo->gso_size = 0;
skb_header_release(p);
nskb->prev = p;
nskb->data_len += p->len;
nskb->truesize += p->len;
nskb->len += p->len;
*head = nskb;
nskb->next = p->next;
p->next = NULL;
p = nskb;
merge:
if (offset > headlen) {
unsigned int eat = offset - headlen;
skbinfo->frags[0].page_offset += eat;
skbinfo->frags[0].size -= eat;
skb->data_len -= eat;
skb->len -= eat;
offset = headlen;
}
__skb_pull(skb, offset);
p->prev->next = skb;
p->prev = skb;
skb_header_release(skb);
done:
NAPI_GRO_CB(p)->count++;
p->data_len += len;
p->truesize += len;
p->len += len;
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
end = start + skb_shinfo(skb)->frags[i].size;
if ((copy = end - offset) > 0) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
if (copy > len)
copy = len;
sg_set_page(&sg[elt], frag->page, copy,
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
if (atomic_read(&sk->sk_rmem_alloc) + skb->truesize >=
(unsigned)sk->sk_rcvbuf)
return -ENOMEM;
skb_orphan(skb);
skb->sk = sk;
skb->destructor = sock_rmem_free;
atomic_add(skb->truesize, &sk->sk_rmem_alloc);
skb_dst_force(skb);
skb_queue_tail(&sk->sk_error_queue, skb);
if (!sock_flag(sk, SOCK_DEAD))
sk->sk_data_ready(sk, skb->len);
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
skb = skb_clone(orig_skb, GFP_ATOMIC);
if (!skb)
return;
if (hwtstamps) {
*skb_hwtstamps(skb) =
*hwtstamps;
} else {
skb->tstamp = ktime_get_real();
}
serr = SKB_EXT_ERR(skb);
memset(serr, 0, sizeof(*serr));
serr->ee.ee_errno = ENOMSG;
serr->ee.ee_origin = SO_EE_ORIGIN_TIMESTAMPING;
err = sock_queue_err_skb(sk, skb);
if (err)
kfree_skb(skb);
}
bool skb_partial_csum_set(struct sk_buff *skb, u16 start, u16 off)
{
if (unlikely(start > skb_headlen(skb)) ||
unlikely((int)start + off > skb_headlen(skb) - 2)) {
if (net_ratelimit())
printk(KERN_WARNING
"bad partial csum: csum=%u/%u len=%u\n",
start, off, skb_headlen(skb));
return false;
}
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum_start = skb_headroom(skb) + start;
skb->csum_offset = off;
return true;
}
void __skb_warn_lro_forwarding(const struct sk_buff *skb)
{
if (net_ratelimit())
pr_warning("%s: received packets cannot be forwarded"
" while LRO is enabled\n", skb->dev->name);
}
