struct ipath_user_sdma_queue *
ipath_user_sdma_queue_create(struct device *dev, int unit, int port, int sport)
{
struct ipath_user_sdma_queue *pq =
kmalloc(sizeof(struct ipath_user_sdma_queue), GFP_KERNEL);
if (!pq)
goto done;
pq->counter = 0;
pq->sent_counter = 0;
INIT_LIST_HEAD(&pq->sent);
mutex_init(&pq->lock);
snprintf(pq->pkt_slab_name, sizeof(pq->pkt_slab_name),
"ipath-user-sdma-pkts-%u-%02u.%02u", unit, port, sport);
pq->pkt_slab = kmem_cache_create(pq->pkt_slab_name,
sizeof(struct ipath_user_sdma_pkt),
0, 0, NULL);
if (!pq->pkt_slab)
goto err_kfree;
snprintf(pq->header_cache_name, sizeof(pq->header_cache_name),
"ipath-user-sdma-headers-%u-%02u.%02u", unit, port, sport);
pq->header_cache = dma_pool_create(pq->header_cache_name,
dev,
IPATH_USER_SDMA_EXP_HEADER_LENGTH,
4, 0);
if (!pq->header_cache)
goto err_slab;
pq->dma_pages_root = RB_ROOT;
goto done;
err_slab:
kmem_cache_destroy(pq->pkt_slab);
err_kfree:
kfree(pq);
pq = NULL;
done:
return pq;
}
static void ipath_user_sdma_init_frag(struct ipath_user_sdma_pkt *pkt,
int i, size_t offset, size_t len,
int put_page, int dma_mapped,
struct page *page,
void *kvaddr, dma_addr_t dma_addr)
{
pkt->addr[i].offset = offset;
pkt->addr[i].length = len;
pkt->addr[i].put_page = put_page;
pkt->addr[i].dma_mapped = dma_mapped;
pkt->addr[i].page = page;
pkt->addr[i].kvaddr = kvaddr;
pkt->addr[i].addr = dma_addr;
}
static void ipath_user_sdma_init_header(struct ipath_user_sdma_pkt *pkt,
u32 counter, size_t offset,
size_t len, int dma_mapped,
struct page *page,
void *kvaddr, dma_addr_t dma_addr)
{
pkt->naddr = 1;
pkt->counter = counter;
ipath_user_sdma_init_frag(pkt, 0, offset, len, 0, dma_mapped, page,
kvaddr, dma_addr);
}
static int ipath_user_sdma_coalesce(const struct ipath_devdata *dd,
struct ipath_user_sdma_pkt *pkt,
const struct iovec *iov,
unsigned long niov) {
int ret = 0;
struct page *page = alloc_page(GFP_KERNEL);
void *mpage_save;
char *mpage;
int i;
int len = 0;
dma_addr_t dma_addr;
if (!page) {
ret = -ENOMEM;
goto done;
}
mpage = kmap(page);
mpage_save = mpage;
for (i = 0; i < niov; i++) {
int cfur;
cfur = copy_from_user(mpage,
iov[i].iov_base, iov[i].iov_len);
if (cfur) {
ret = -EFAULT;
goto free_unmap;
}
mpage += iov[i].iov_len;
len += iov[i].iov_len;
}
dma_addr = dma_map_page(&dd->pcidev->dev, page, 0, len,
DMA_TO_DEVICE);
if (dma_mapping_error(&dd->pcidev->dev, dma_addr)) {
ret = -ENOMEM;
goto free_unmap;
}
ipath_user_sdma_init_frag(pkt, 1, 0, len, 0, 1, page, mpage_save,
dma_addr);
pkt->naddr = 2;
goto done;
free_unmap:
kunmap(page);
__free_page(page);
done:
return ret;
}
static int ipath_user_sdma_num_pages(const struct iovec *iov)
{
const unsigned long addr = (unsigned long) iov->iov_base;
const unsigned long len = iov->iov_len;
const unsigned long spage = addr & PAGE_MASK;
const unsigned long epage = (addr + len - 1) & PAGE_MASK;
return 1 + ((epage - spage) >> PAGE_SHIFT);
}
static int ipath_user_sdma_page_length(unsigned long addr, unsigned long len)
{
const unsigned long offset = addr & ~PAGE_MASK;
return ((offset + len) > PAGE_SIZE) ? (PAGE_SIZE - offset) : len;
}
static void ipath_user_sdma_free_pkt_frag(struct device *dev,
struct ipath_user_sdma_queue *pq,
struct ipath_user_sdma_pkt *pkt,
int frag)
{
const int i = frag;
if (pkt->addr[i].page) {
if (pkt->addr[i].dma_mapped)
dma_unmap_page(dev,
pkt->addr[i].addr,
pkt->addr[i].length,
DMA_TO_DEVICE);
if (pkt->addr[i].kvaddr)
kunmap(pkt->addr[i].page);
if (pkt->addr[i].put_page)
put_page(pkt->addr[i].page);
else
__free_page(pkt->addr[i].page);
} else if (pkt->addr[i].kvaddr)
dma_pool_free(pq->header_cache,
pkt->addr[i].kvaddr, pkt->addr[i].addr);
}
static int ipath_user_sdma_pin_pages(const struct ipath_devdata *dd,
struct ipath_user_sdma_pkt *pkt,
unsigned long addr, int tlen, int npages)
{
struct page *pages[2];
int j;
int ret;
ret = get_user_pages_fast(addr, npages, 0, pages);
if (ret != npages) {
int i;
for (i = 0; i < ret; i++)
put_page(pages[i]);
ret = -ENOMEM;
goto done;
}
for (j = 0; j < npages; j++) {
const int flen =
ipath_user_sdma_page_length(addr, tlen);
dma_addr_t dma_addr =
dma_map_page(&dd->pcidev->dev,
pages[j], 0, flen, DMA_TO_DEVICE);
unsigned long fofs = addr & ~PAGE_MASK;
if (dma_mapping_error(&dd->pcidev->dev, dma_addr)) {
ret = -ENOMEM;
goto done;
}
ipath_user_sdma_init_frag(pkt, pkt->naddr, fofs, flen, 1, 1,
pages[j], kmap(pages[j]),
dma_addr);
pkt->naddr++;
addr += flen;
tlen -= flen;
}
done:
return ret;
}
static int ipath_user_sdma_pin_pkt(const struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq,
struct ipath_user_sdma_pkt *pkt,
const struct iovec *iov,
unsigned long niov)
{
int ret = 0;
unsigned long idx;
for (idx = 0; idx < niov; idx++) {
const int npages = ipath_user_sdma_num_pages(iov + idx);
const unsigned long addr = (unsigned long) iov[idx].iov_base;
ret = ipath_user_sdma_pin_pages(dd, pkt,
addr, iov[idx].iov_len,
npages);
if (ret < 0)
goto free_pkt;
}
goto done;
free_pkt:
for (idx = 0; idx < pkt->naddr; idx++)
ipath_user_sdma_free_pkt_frag(&dd->pcidev->dev, pq, pkt, idx);
done:
return ret;
}
static int ipath_user_sdma_init_payload(const struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq,
struct ipath_user_sdma_pkt *pkt,
const struct iovec *iov,
unsigned long niov, int npages)
{
int ret = 0;
if (npages >= ARRAY_SIZE(pkt->addr))
ret = ipath_user_sdma_coalesce(dd, pkt, iov, niov);
else
ret = ipath_user_sdma_pin_pkt(dd, pq, pkt, iov, niov);
return ret;
}
static void ipath_user_sdma_free_pkt_list(struct device *dev,
struct ipath_user_sdma_queue *pq,
struct list_head *list)
{
struct ipath_user_sdma_pkt *pkt, *pkt_next;
list_for_each_entry_safe(pkt, pkt_next, list, list) {
int i;
for (i = 0; i < pkt->naddr; i++)
ipath_user_sdma_free_pkt_frag(dev, pq, pkt, i);
kmem_cache_free(pq->pkt_slab, pkt);
}
}
static int ipath_user_sdma_queue_pkts(const struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq,
struct list_head *list,
const struct iovec *iov,
unsigned long niov,
int maxpkts)
{
unsigned long idx = 0;
int ret = 0;
int npkts = 0;
struct page *page = NULL;
__le32 *pbc;
dma_addr_t dma_addr;
struct ipath_user_sdma_pkt *pkt = NULL;
size_t len;
size_t nw;
u32 counter = pq->counter;
int dma_mapped = 0;
while (idx < niov && npkts < maxpkts) {
const unsigned long addr = (unsigned long) iov[idx].iov_base;
const unsigned long idx_save = idx;
unsigned pktnw;
unsigned pktnwc;
int nfrags = 0;
int npages = 0;
int cfur;
dma_mapped = 0;
len = iov[idx].iov_len;
nw = len >> 2;
page = NULL;
pkt = kmem_cache_alloc(pq->pkt_slab, GFP_KERNEL);
if (!pkt) {
ret = -ENOMEM;
goto free_list;
}
if (len < IPATH_USER_SDMA_MIN_HEADER_LENGTH ||
len > PAGE_SIZE || len & 3 || addr & 3) {
ret = -EINVAL;
goto free_pkt;
}
if (len == IPATH_USER_SDMA_EXP_HEADER_LENGTH)
pbc = dma_pool_alloc(pq->header_cache, GFP_KERNEL,
&dma_addr);
else
pbc = NULL;
if (!pbc) {
page = alloc_page(GFP_KERNEL);
if (!page) {
ret = -ENOMEM;
goto free_pkt;
}
pbc = kmap(page);
}
cfur = copy_from_user(pbc, iov[idx].iov_base, len);
if (cfur) {
ret = -EFAULT;
goto free_pbc;
}
pktnwc = nw - 1;
pktnw = le32_to_cpu(*pbc) & IPATH_PBC_LENGTH_MASK;
if (pktnw < pktnwc || pktnw > pktnwc + (PAGE_SIZE >> 2)) {
ret = -EINVAL;
goto free_pbc;
}
idx++;
while (pktnwc < pktnw && idx < niov) {
const size_t slen = iov[idx].iov_len;
const unsigned long faddr =
(unsigned long) iov[idx].iov_base;
if (slen & 3 || faddr & 3 || !slen ||
slen > PAGE_SIZE) {
ret = -EINVAL;
goto free_pbc;
}
npages++;
if ((faddr & PAGE_MASK) !=
((faddr + slen - 1) & PAGE_MASK))
npages++;
pktnwc += slen >> 2;
idx++;
nfrags++;
}
if (pktnwc != pktnw) {
ret = -EINVAL;
goto free_pbc;
}
if (page) {
dma_addr = dma_map_page(&dd->pcidev->dev,
page, 0, len, DMA_TO_DEVICE);
if (dma_mapping_error(&dd->pcidev->dev, dma_addr)) {
ret = -ENOMEM;
goto free_pbc;
}
dma_mapped = 1;
}
ipath_user_sdma_init_header(pkt, counter, 0, len, dma_mapped,
page, pbc, dma_addr);
if (nfrags) {
ret = ipath_user_sdma_init_payload(dd, pq, pkt,
iov + idx_save + 1,
nfrags, npages);
if (ret < 0)
goto free_pbc_dma;
}
counter++;
npkts++;
list_add_tail(&pkt->list, list);
}
ret = idx;
goto done;
free_pbc_dma:
if (dma_mapped)
dma_unmap_page(&dd->pcidev->dev, dma_addr, len, DMA_TO_DEVICE);
free_pbc:
if (page) {
kunmap(page);
__free_page(page);
} else
dma_pool_free(pq->header_cache, pbc, dma_addr);
free_pkt:
kmem_cache_free(pq->pkt_slab, pkt);
free_list:
ipath_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, list);
done:
return ret;
}
static void ipath_user_sdma_set_complete_counter(struct ipath_user_sdma_queue *pq,
u32 c)
{
pq->sent_counter = c;
}
static int ipath_user_sdma_queue_clean(const struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq)
{
struct list_head free_list;
struct ipath_user_sdma_pkt *pkt;
struct ipath_user_sdma_pkt *pkt_prev;
int ret = 0;
INIT_LIST_HEAD(&free_list);
list_for_each_entry_safe(pkt, pkt_prev, &pq->sent, list) {
s64 descd = dd->ipath_sdma_descq_removed - pkt->added;
if (descd < 0)
break;
list_move_tail(&pkt->list, &free_list);
ret++;
}
if (!list_empty(&free_list)) {
u32 counter;
pkt = list_entry(free_list.prev,
struct ipath_user_sdma_pkt, list);
counter = pkt->counter;
ipath_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, &free_list);
ipath_user_sdma_set_complete_counter(pq, counter);
}
return ret;
}
void ipath_user_sdma_queue_destroy(struct ipath_user_sdma_queue *pq)
{
if (!pq)
return;
kmem_cache_destroy(pq->pkt_slab);
dma_pool_destroy(pq->header_cache);
kfree(pq);
}
static int ipath_user_sdma_hwqueue_clean(struct ipath_devdata *dd)
{
int ret;
unsigned long flags;
spin_lock_irqsave(&dd->ipath_sdma_lock, flags);
ret = ipath_sdma_make_progress(dd);
spin_unlock_irqrestore(&dd->ipath_sdma_lock, flags);
return ret;
}
void ipath_user_sdma_queue_drain(struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq)
{
int i;
if (!pq)
return;
for (i = 0; i < 100; i++) {
mutex_lock(&pq->lock);
if (list_empty(&pq->sent)) {
mutex_unlock(&pq->lock);
break;
}
ipath_user_sdma_hwqueue_clean(dd);
ipath_user_sdma_queue_clean(dd, pq);
mutex_unlock(&pq->lock);
msleep(10);
}
if (!list_empty(&pq->sent)) {
struct list_head free_list;
printk(KERN_INFO "drain: lists not empty: forcing!\n");
INIT_LIST_HEAD(&free_list);
mutex_lock(&pq->lock);
list_splice_init(&pq->sent, &free_list);
ipath_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, &free_list);
mutex_unlock(&pq->lock);
}
}
static inline __le64 ipath_sdma_make_desc0(struct ipath_devdata *dd,
u64 addr, u64 dwlen, u64 dwoffset)
{
return cpu_to_le64(
((addr & 0xfffffffcULL) << 32) |
((dd->ipath_sdma_generation & 3ULL) << 30) |
((dwlen & 0x7ffULL) << 16) |
(dwoffset & 0x7ffULL));
}
static inline __le64 ipath_sdma_make_first_desc0(__le64 descq)
{
return descq | cpu_to_le64(1ULL << 12);
}
static inline __le64 ipath_sdma_make_last_desc0(__le64 descq)
{
return descq | cpu_to_le64(1ULL << 11 | 1ULL << 13);
}
static inline __le64 ipath_sdma_make_desc1(u64 addr)
{
return cpu_to_le64(addr >> 32);
}
static void ipath_user_sdma_send_frag(struct ipath_devdata *dd,
struct ipath_user_sdma_pkt *pkt, int idx,
unsigned ofs, u16 tail)
{
const u64 addr = (u64) pkt->addr[idx].addr +
(u64) pkt->addr[idx].offset;
const u64 dwlen = (u64) pkt->addr[idx].length / 4;
__le64 *descqp;
__le64 descq0;
descqp = &dd->ipath_sdma_descq[tail].qw[0];
descq0 = ipath_sdma_make_desc0(dd, addr, dwlen, ofs);
if (idx == 0)
descq0 = ipath_sdma_make_first_desc0(descq0);
if (idx == pkt->naddr - 1)
descq0 = ipath_sdma_make_last_desc0(descq0);
descqp[0] = descq0;
descqp[1] = ipath_sdma_make_desc1(addr);
}
static int ipath_user_sdma_push_pkts(struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq,
struct list_head *pktlist)
{
int ret = 0;
unsigned long flags;
u16 tail;
if (list_empty(pktlist))
return 0;
if (unlikely(!(dd->ipath_flags & IPATH_LINKACTIVE)))
return -ECOMM;
spin_lock_irqsave(&dd->ipath_sdma_lock, flags);
if (unlikely(dd->ipath_sdma_status & IPATH_SDMA_ABORT_MASK)) {
ret = -ECOMM;
goto unlock;
}
tail = dd->ipath_sdma_descq_tail;
while (!list_empty(pktlist)) {
struct ipath_user_sdma_pkt *pkt =
list_entry(pktlist->next, struct ipath_user_sdma_pkt,
list);
int i;
unsigned ofs = 0;
u16 dtail = tail;
if (pkt->naddr > ipath_sdma_descq_freecnt(dd))
goto unlock_check_tail;
for (i = 0; i < pkt->naddr; i++) {
ipath_user_sdma_send_frag(dd, pkt, i, ofs, tail);
ofs += pkt->addr[i].length >> 2;
if (++tail == dd->ipath_sdma_descq_cnt) {
tail = 0;
++dd->ipath_sdma_generation;
}
}
if ((ofs<<2) > dd->ipath_ibmaxlen) {
ipath_dbg("packet size %X > ibmax %X, fail\n",
ofs<<2, dd->ipath_ibmaxlen);
ret = -EMSGSIZE;
goto unlock;
}
if (ofs >= IPATH_SMALLBUF_DWORDS) {
for (i = 0; i < pkt->naddr; i++) {
dd->ipath_sdma_descq[dtail].qw[0] |=
cpu_to_le64(1ULL << 14);
if (++dtail == dd->ipath_sdma_descq_cnt)
dtail = 0;
}
}
dd->ipath_sdma_descq_added += pkt->naddr;
pkt->added = dd->ipath_sdma_descq_added;
list_move_tail(&pkt->list, &pq->sent);
ret++;
}
unlock_check_tail:
if (dd->ipath_sdma_descq_tail != tail) {
wmb();
ipath_write_kreg(dd, dd->ipath_kregs->kr_senddmatail, tail);
dd->ipath_sdma_descq_tail = tail;
}
unlock:
spin_unlock_irqrestore(&dd->ipath_sdma_lock, flags);
return ret;
}
int ipath_user_sdma_writev(struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq,
const struct iovec *iov,
unsigned long dim)
{
int ret = 0;
struct list_head list;
int npkts = 0;
INIT_LIST_HEAD(&list);
mutex_lock(&pq->lock);
if (dd->ipath_sdma_descq_added != dd->ipath_sdma_descq_removed) {
ipath_user_sdma_hwqueue_clean(dd);
ipath_user_sdma_queue_clean(dd, pq);
}
while (dim) {
const int mxp = 8;
ret = ipath_user_sdma_queue_pkts(dd, pq, &list, iov, dim, mxp);
if (ret <= 0)
goto done_unlock;
else {
dim -= ret;
iov += ret;
}
if (!list_empty(&list)) {
if (ipath_sdma_descq_freecnt(dd) < ret * 4) {
ipath_user_sdma_hwqueue_clean(dd);
ipath_user_sdma_queue_clean(dd, pq);
}
ret = ipath_user_sdma_push_pkts(dd, pq, &list);
if (ret < 0)
goto done_unlock;
else {
npkts += ret;
pq->counter += ret;
if (!list_empty(&list))
goto done_unlock;
}
}
}
done_unlock:
if (!list_empty(&list))
ipath_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, &list);
mutex_unlock(&pq->lock);
return (ret < 0) ? ret : npkts;
}
int ipath_user_sdma_make_progress(struct ipath_devdata *dd,
struct ipath_user_sdma_queue *pq)
{
int ret = 0;
mutex_lock(&pq->lock);
ipath_user_sdma_hwqueue_clean(dd);
ret = ipath_user_sdma_queue_clean(dd, pq);
mutex_unlock(&pq->lock);
return ret;
}
u32 ipath_user_sdma_complete_counter(const struct ipath_user_sdma_queue *pq)
{
return pq->sent_counter;
}
u32 ipath_user_sdma_inflight_counter(struct ipath_user_sdma_queue *pq)
{
return pq->counter;
}
