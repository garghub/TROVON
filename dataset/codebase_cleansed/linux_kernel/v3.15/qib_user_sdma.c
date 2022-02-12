static struct qib_user_sdma_rb_node *
qib_user_sdma_rb_search(struct rb_root *root, pid_t pid)
{
struct qib_user_sdma_rb_node *sdma_rb_node;
struct rb_node *node = root->rb_node;
while (node) {
sdma_rb_node = container_of(node,
struct qib_user_sdma_rb_node, node);
if (pid < sdma_rb_node->pid)
node = node->rb_left;
else if (pid > sdma_rb_node->pid)
node = node->rb_right;
else
return sdma_rb_node;
}
return NULL;
}
static int
qib_user_sdma_rb_insert(struct rb_root *root, struct qib_user_sdma_rb_node *new)
{
struct rb_node **node = &(root->rb_node);
struct rb_node *parent = NULL;
struct qib_user_sdma_rb_node *got;
while (*node) {
got = container_of(*node, struct qib_user_sdma_rb_node, node);
parent = *node;
if (new->pid < got->pid)
node = &((*node)->rb_left);
else if (new->pid > got->pid)
node = &((*node)->rb_right);
else
return 0;
}
rb_link_node(&new->node, parent, node);
rb_insert_color(&new->node, root);
return 1;
}
struct qib_user_sdma_queue *
qib_user_sdma_queue_create(struct device *dev, int unit, int ctxt, int sctxt)
{
struct qib_user_sdma_queue *pq =
kmalloc(sizeof(struct qib_user_sdma_queue), GFP_KERNEL);
struct qib_user_sdma_rb_node *sdma_rb_node;
if (!pq)
goto done;
pq->counter = 0;
pq->sent_counter = 0;
pq->num_pending = 0;
pq->num_sending = 0;
pq->added = 0;
pq->sdma_rb_node = NULL;
INIT_LIST_HEAD(&pq->sent);
spin_lock_init(&pq->sent_lock);
mutex_init(&pq->lock);
snprintf(pq->pkt_slab_name, sizeof(pq->pkt_slab_name),
"qib-user-sdma-pkts-%u-%02u.%02u", unit, ctxt, sctxt);
pq->pkt_slab = kmem_cache_create(pq->pkt_slab_name,
sizeof(struct qib_user_sdma_pkt),
0, 0, NULL);
if (!pq->pkt_slab)
goto err_kfree;
snprintf(pq->header_cache_name, sizeof(pq->header_cache_name),
"qib-user-sdma-headers-%u-%02u.%02u", unit, ctxt, sctxt);
pq->header_cache = dma_pool_create(pq->header_cache_name,
dev,
QIB_USER_SDMA_EXP_HEADER_LENGTH,
4, 0);
if (!pq->header_cache)
goto err_slab;
pq->dma_pages_root = RB_ROOT;
sdma_rb_node = qib_user_sdma_rb_search(&qib_user_sdma_rb_root,
current->pid);
if (sdma_rb_node) {
sdma_rb_node->refcount++;
} else {
int ret;
sdma_rb_node = kmalloc(sizeof(
struct qib_user_sdma_rb_node), GFP_KERNEL);
if (!sdma_rb_node)
goto err_rb;
sdma_rb_node->refcount = 1;
sdma_rb_node->pid = current->pid;
ret = qib_user_sdma_rb_insert(&qib_user_sdma_rb_root,
sdma_rb_node);
BUG_ON(ret == 0);
}
pq->sdma_rb_node = sdma_rb_node;
goto done;
err_rb:
dma_pool_destroy(pq->header_cache);
err_slab:
kmem_cache_destroy(pq->pkt_slab);
err_kfree:
kfree(pq);
pq = NULL;
done:
return pq;
}
static void qib_user_sdma_init_frag(struct qib_user_sdma_pkt *pkt,
int i, u16 offset, u16 len,
u16 first_desc, u16 last_desc,
u16 put_page, u16 dma_mapped,
struct page *page, void *kvaddr,
dma_addr_t dma_addr, u16 dma_length)
{
pkt->addr[i].offset = offset;
pkt->addr[i].length = len;
pkt->addr[i].first_desc = first_desc;
pkt->addr[i].last_desc = last_desc;
pkt->addr[i].put_page = put_page;
pkt->addr[i].dma_mapped = dma_mapped;
pkt->addr[i].page = page;
pkt->addr[i].kvaddr = kvaddr;
pkt->addr[i].addr = dma_addr;
pkt->addr[i].dma_length = dma_length;
}
static void *qib_user_sdma_alloc_header(struct qib_user_sdma_queue *pq,
size_t len, dma_addr_t *dma_addr)
{
void *hdr;
if (len == QIB_USER_SDMA_EXP_HEADER_LENGTH)
hdr = dma_pool_alloc(pq->header_cache, GFP_KERNEL,
dma_addr);
else
hdr = NULL;
if (!hdr) {
hdr = kmalloc(len, GFP_KERNEL);
if (!hdr)
return NULL;
*dma_addr = 0;
}
return hdr;
}
static int qib_user_sdma_page_to_frags(const struct qib_devdata *dd,
struct qib_user_sdma_queue *pq,
struct qib_user_sdma_pkt *pkt,
struct page *page, u16 put,
u16 offset, u16 len, void *kvaddr)
{
__le16 *pbc16;
void *pbcvaddr;
struct qib_message_header *hdr;
u16 newlen, pbclen, lastdesc, dma_mapped;
u32 vcto;
union qib_seqnum seqnum;
dma_addr_t pbcdaddr;
dma_addr_t dma_addr =
dma_map_page(&dd->pcidev->dev,
page, offset, len, DMA_TO_DEVICE);
int ret = 0;
if (dma_mapping_error(&dd->pcidev->dev, dma_addr)) {
if (put) {
put_page(page);
} else {
kunmap(page);
__free_page(page);
}
ret = -ENOMEM;
goto done;
}
offset = 0;
dma_mapped = 1;
next_fragment:
if (pkt->tiddma && len > pkt->tidsm[pkt->tidsmidx].length)
newlen = pkt->tidsm[pkt->tidsmidx].length;
else
newlen = len;
lastdesc = 0;
if ((pkt->payload_size + newlen) >= pkt->frag_size) {
newlen = pkt->frag_size - pkt->payload_size;
lastdesc = 1;
} else if (pkt->tiddma) {
if (newlen == pkt->tidsm[pkt->tidsmidx].length)
lastdesc = 1;
} else {
if (newlen == pkt->bytes_togo)
lastdesc = 1;
}
qib_user_sdma_init_frag(pkt, pkt->naddr,
offset, newlen,
0, lastdesc,
put, dma_mapped,
page, kvaddr,
dma_addr, len);
pkt->bytes_togo -= newlen;
pkt->payload_size += newlen;
pkt->naddr++;
if (pkt->naddr == pkt->addrlimit) {
ret = -EFAULT;
goto done;
}
if (pkt->bytes_togo == 0) {
if (!pkt->addr[pkt->index].addr) {
pkt->addr[pkt->index].addr =
dma_map_single(&dd->pcidev->dev,
pkt->addr[pkt->index].kvaddr,
pkt->addr[pkt->index].dma_length,
DMA_TO_DEVICE);
if (dma_mapping_error(&dd->pcidev->dev,
pkt->addr[pkt->index].addr)) {
ret = -ENOMEM;
goto done;
}
pkt->addr[pkt->index].dma_mapped = 1;
}
goto done;
}
if (pkt->tiddma) {
pkt->tidsm[pkt->tidsmidx].length -= newlen;
if (pkt->tidsm[pkt->tidsmidx].length) {
pkt->tidsm[pkt->tidsmidx].offset += newlen;
} else {
pkt->tidsmidx++;
if (pkt->tidsmidx == pkt->tidsmcount) {
ret = -EFAULT;
goto done;
}
}
}
if (lastdesc == 0)
goto done;
pbclen = pkt->addr[pkt->index].length;
pbcvaddr = qib_user_sdma_alloc_header(pq, pbclen, &pbcdaddr);
if (!pbcvaddr) {
ret = -ENOMEM;
goto done;
}
pbc16 = (__le16 *)pkt->addr[pkt->index].kvaddr;
memcpy(pbcvaddr, pbc16, pbclen);
hdr = (struct qib_message_header *)&pbc16[4];
pbc16[0] = cpu_to_le16(le16_to_cpu(pbc16[0])-(pkt->bytes_togo>>2));
hdr->lrh[2] = cpu_to_be16(le16_to_cpu(pbc16[0]));
if (pkt->tiddma) {
hdr->iph.pkt_flags =
cpu_to_le16(le16_to_cpu(hdr->iph.pkt_flags)|0x2);
hdr->flags &= ~(0x04|0x20);
} else {
hdr->bth[0] = cpu_to_be32(be32_to_cpu(hdr->bth[0])&0xFFCFFFFF);
hdr->flags &= ~(0x04);
}
vcto = le32_to_cpu(hdr->iph.ver_ctxt_tid_offset);
hdr->iph.chksum = cpu_to_le16(QIB_LRH_BTH +
be16_to_cpu(hdr->lrh[2]) -
((vcto>>16)&0xFFFF) - (vcto&0xFFFF) -
le16_to_cpu(hdr->iph.pkt_flags));
if (!pkt->addr[pkt->index].addr) {
pkt->addr[pkt->index].addr =
dma_map_single(&dd->pcidev->dev,
pkt->addr[pkt->index].kvaddr,
pkt->addr[pkt->index].dma_length,
DMA_TO_DEVICE);
if (dma_mapping_error(&dd->pcidev->dev,
pkt->addr[pkt->index].addr)) {
ret = -ENOMEM;
goto done;
}
pkt->addr[pkt->index].dma_mapped = 1;
}
pbc16 = (__le16 *)pbcvaddr;
hdr = (struct qib_message_header *)&pbc16[4];
pbc16[0] = cpu_to_le16(le16_to_cpu(pbc16[0])-(pkt->payload_size>>2));
hdr->lrh[2] = cpu_to_be16(le16_to_cpu(pbc16[0]));
if (pkt->tiddma) {
hdr->iph.ver_ctxt_tid_offset = cpu_to_le32(
(le32_to_cpu(hdr->iph.ver_ctxt_tid_offset)&0xFF000000) +
(pkt->tidsm[pkt->tidsmidx].tid<<QLOGIC_IB_I_TID_SHIFT) +
(pkt->tidsm[pkt->tidsmidx].offset>>2));
} else {
hdr->uwords[2] += pkt->payload_size;
}
vcto = le32_to_cpu(hdr->iph.ver_ctxt_tid_offset);
hdr->iph.chksum = cpu_to_le16(QIB_LRH_BTH +
be16_to_cpu(hdr->lrh[2]) -
((vcto>>16)&0xFFFF) - (vcto&0xFFFF) -
le16_to_cpu(hdr->iph.pkt_flags));
seqnum.val = be32_to_cpu(hdr->bth[2]);
if (pkt->tiddma)
seqnum.seq++;
else
seqnum.pkt++;
hdr->bth[2] = cpu_to_be32(seqnum.val);
qib_user_sdma_init_frag(pkt, pkt->naddr,
0, pbclen,
1, 0,
0, 0,
NULL, pbcvaddr,
pbcdaddr, pbclen);
pkt->index = pkt->naddr;
pkt->payload_size = 0;
pkt->naddr++;
if (pkt->naddr == pkt->addrlimit) {
ret = -EFAULT;
goto done;
}
if (newlen != len) {
if (dma_mapped) {
put = 0;
dma_mapped = 0;
page = NULL;
kvaddr = NULL;
}
len -= newlen;
offset += newlen;
goto next_fragment;
}
done:
return ret;
}
static int qib_user_sdma_coalesce(const struct qib_devdata *dd,
struct qib_user_sdma_queue *pq,
struct qib_user_sdma_pkt *pkt,
const struct iovec *iov,
unsigned long niov)
{
int ret = 0;
struct page *page = alloc_page(GFP_KERNEL);
void *mpage_save;
char *mpage;
int i;
int len = 0;
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
ret = qib_user_sdma_page_to_frags(dd, pq, pkt,
page, 0, 0, len, mpage_save);
goto done;
free_unmap:
kunmap(page);
__free_page(page);
done:
return ret;
}
static int qib_user_sdma_num_pages(const struct iovec *iov)
{
const unsigned long addr = (unsigned long) iov->iov_base;
const unsigned long len = iov->iov_len;
const unsigned long spage = addr & PAGE_MASK;
const unsigned long epage = (addr + len - 1) & PAGE_MASK;
return 1 + ((epage - spage) >> PAGE_SHIFT);
}
static void qib_user_sdma_free_pkt_frag(struct device *dev,
struct qib_user_sdma_queue *pq,
struct qib_user_sdma_pkt *pkt,
int frag)
{
const int i = frag;
if (pkt->addr[i].page) {
if (pkt->addr[i].dma_mapped)
dma_unmap_page(dev,
pkt->addr[i].addr,
pkt->addr[i].dma_length,
DMA_TO_DEVICE);
if (pkt->addr[i].kvaddr)
kunmap(pkt->addr[i].page);
if (pkt->addr[i].put_page)
put_page(pkt->addr[i].page);
else
__free_page(pkt->addr[i].page);
} else if (pkt->addr[i].kvaddr) {
if (pkt->addr[i].dma_mapped) {
dma_unmap_single(dev,
pkt->addr[i].addr,
pkt->addr[i].dma_length,
DMA_TO_DEVICE);
kfree(pkt->addr[i].kvaddr);
} else if (pkt->addr[i].addr) {
dma_pool_free(pq->header_cache,
pkt->addr[i].kvaddr, pkt->addr[i].addr);
} else {
kfree(pkt->addr[i].kvaddr);
}
}
}
static int qib_user_sdma_pin_pages(const struct qib_devdata *dd,
struct qib_user_sdma_queue *pq,
struct qib_user_sdma_pkt *pkt,
unsigned long addr, int tlen, int npages)
{
struct page *pages[8];
int i, j;
int ret = 0;
while (npages) {
if (npages > 8)
j = 8;
else
j = npages;
ret = get_user_pages_fast(addr, j, 0, pages);
if (ret != j) {
i = 0;
j = ret;
ret = -ENOMEM;
goto free_pages;
}
for (i = 0; i < j; i++) {
unsigned long fofs = addr & ~PAGE_MASK;
int flen = ((fofs + tlen) > PAGE_SIZE) ?
(PAGE_SIZE - fofs) : tlen;
ret = qib_user_sdma_page_to_frags(dd, pq, pkt,
pages[i], 1, fofs, flen, NULL);
if (ret < 0) {
i++;
goto free_pages;
}
addr += flen;
tlen -= flen;
}
npages -= j;
}
goto done;
free_pages:
while (i < j)
put_page(pages[i++]);
done:
return ret;
}
static int qib_user_sdma_pin_pkt(const struct qib_devdata *dd,
struct qib_user_sdma_queue *pq,
struct qib_user_sdma_pkt *pkt,
const struct iovec *iov,
unsigned long niov)
{
int ret = 0;
unsigned long idx;
for (idx = 0; idx < niov; idx++) {
const int npages = qib_user_sdma_num_pages(iov + idx);
const unsigned long addr = (unsigned long) iov[idx].iov_base;
ret = qib_user_sdma_pin_pages(dd, pq, pkt, addr,
iov[idx].iov_len, npages);
if (ret < 0)
goto free_pkt;
}
goto done;
free_pkt:
for (idx = 1; idx < pkt->naddr; idx++)
qib_user_sdma_free_pkt_frag(&dd->pcidev->dev, pq, pkt, idx);
if (pkt->addr[0].dma_mapped) {
dma_unmap_single(&dd->pcidev->dev,
pkt->addr[0].addr,
pkt->addr[0].dma_length,
DMA_TO_DEVICE);
pkt->addr[0].addr = 0;
pkt->addr[0].dma_mapped = 0;
}
done:
return ret;
}
static int qib_user_sdma_init_payload(const struct qib_devdata *dd,
struct qib_user_sdma_queue *pq,
struct qib_user_sdma_pkt *pkt,
const struct iovec *iov,
unsigned long niov, int npages)
{
int ret = 0;
if (pkt->frag_size == pkt->bytes_togo &&
npages >= ARRAY_SIZE(pkt->addr))
ret = qib_user_sdma_coalesce(dd, pq, pkt, iov, niov);
else
ret = qib_user_sdma_pin_pkt(dd, pq, pkt, iov, niov);
return ret;
}
static void qib_user_sdma_free_pkt_list(struct device *dev,
struct qib_user_sdma_queue *pq,
struct list_head *list)
{
struct qib_user_sdma_pkt *pkt, *pkt_next;
list_for_each_entry_safe(pkt, pkt_next, list, list) {
int i;
for (i = 0; i < pkt->naddr; i++)
qib_user_sdma_free_pkt_frag(dev, pq, pkt, i);
if (pkt->largepkt)
kfree(pkt);
else
kmem_cache_free(pq->pkt_slab, pkt);
}
INIT_LIST_HEAD(list);
}
static int qib_user_sdma_queue_pkts(const struct qib_devdata *dd,
struct qib_pportdata *ppd,
struct qib_user_sdma_queue *pq,
const struct iovec *iov,
unsigned long niov,
struct list_head *list,
int *maxpkts, int *ndesc)
{
unsigned long idx = 0;
int ret = 0;
int npkts = 0;
__le32 *pbc;
dma_addr_t dma_addr;
struct qib_user_sdma_pkt *pkt = NULL;
size_t len;
size_t nw;
u32 counter = pq->counter;
u16 frag_size;
while (idx < niov && npkts < *maxpkts) {
const unsigned long addr = (unsigned long) iov[idx].iov_base;
const unsigned long idx_save = idx;
unsigned pktnw;
unsigned pktnwc;
int nfrags = 0;
int npages = 0;
int bytes_togo = 0;
int tiddma = 0;
int cfur;
len = iov[idx].iov_len;
nw = len >> 2;
if (len < QIB_USER_SDMA_MIN_HEADER_LENGTH ||
len > PAGE_SIZE || len & 3 || addr & 3) {
ret = -EINVAL;
goto free_list;
}
pbc = qib_user_sdma_alloc_header(pq, len, &dma_addr);
if (!pbc) {
ret = -ENOMEM;
goto free_list;
}
cfur = copy_from_user(pbc, iov[idx].iov_base, len);
if (cfur) {
ret = -EFAULT;
goto free_pbc;
}
pktnwc = nw - 1;
pktnw = le32_to_cpu(*pbc) & 0xFFFF;
if (pktnw < pktnwc) {
ret = -EINVAL;
goto free_pbc;
}
idx++;
while (pktnwc < pktnw && idx < niov) {
const size_t slen = iov[idx].iov_len;
const unsigned long faddr =
(unsigned long) iov[idx].iov_base;
if (slen & 3 || faddr & 3 || !slen) {
ret = -EINVAL;
goto free_pbc;
}
npages += qib_user_sdma_num_pages(&iov[idx]);
bytes_togo += slen;
pktnwc += slen >> 2;
idx++;
nfrags++;
}
if (pktnwc != pktnw) {
ret = -EINVAL;
goto free_pbc;
}
frag_size = ((le32_to_cpu(*pbc))>>16) & 0xFFFF;
if (((frag_size ? frag_size : bytes_togo) + len) >
ppd->ibmaxlen) {
ret = -EINVAL;
goto free_pbc;
}
if (frag_size) {
int pktsize, tidsmsize, n;
n = npages*((2*PAGE_SIZE/frag_size)+1);
pktsize = sizeof(*pkt) + sizeof(pkt->addr[0])*n;
tiddma = (((le32_to_cpu(pbc[7])>>
QLOGIC_IB_I_TID_SHIFT)&
QLOGIC_IB_I_TID_MASK) !=
QLOGIC_IB_I_TID_MASK);
if (tiddma)
tidsmsize = iov[idx].iov_len;
else
tidsmsize = 0;
pkt = kmalloc(pktsize+tidsmsize, GFP_KERNEL);
if (!pkt) {
ret = -ENOMEM;
goto free_pbc;
}
pkt->largepkt = 1;
pkt->frag_size = frag_size;
pkt->addrlimit = n + ARRAY_SIZE(pkt->addr);
if (tiddma) {
char *tidsm = (char *)pkt + pktsize;
cfur = copy_from_user(tidsm,
iov[idx].iov_base, tidsmsize);
if (cfur) {
ret = -EFAULT;
goto free_pkt;
}
pkt->tidsm =
(struct qib_tid_session_member *)tidsm;
pkt->tidsmcount = tidsmsize/
sizeof(struct qib_tid_session_member);
pkt->tidsmidx = 0;
idx++;
}
*pbc = cpu_to_le32(le32_to_cpu(*pbc) & 0x0000FFFF);
} else {
pkt = kmem_cache_alloc(pq->pkt_slab, GFP_KERNEL);
if (!pkt) {
ret = -ENOMEM;
goto free_pbc;
}
pkt->largepkt = 0;
pkt->frag_size = bytes_togo;
pkt->addrlimit = ARRAY_SIZE(pkt->addr);
}
pkt->bytes_togo = bytes_togo;
pkt->payload_size = 0;
pkt->counter = counter;
pkt->tiddma = tiddma;
qib_user_sdma_init_frag(pkt, 0,
0, len,
1, 0,
0, 0,
NULL, pbc,
dma_addr, len);
pkt->index = 0;
pkt->naddr = 1;
if (nfrags) {
ret = qib_user_sdma_init_payload(dd, pq, pkt,
iov + idx_save + 1,
nfrags, npages);
if (ret < 0)
goto free_pkt;
} else {
pkt->addr[0].last_desc = 1;
if (dma_addr == 0) {
dma_addr = dma_map_single(&dd->pcidev->dev,
pbc, len, DMA_TO_DEVICE);
if (dma_mapping_error(&dd->pcidev->dev,
dma_addr)) {
ret = -ENOMEM;
goto free_pkt;
}
pkt->addr[0].addr = dma_addr;
pkt->addr[0].dma_mapped = 1;
}
}
counter++;
npkts++;
pkt->pq = pq;
pkt->index = 0;
*ndesc += pkt->naddr;
list_add_tail(&pkt->list, list);
}
*maxpkts = npkts;
ret = idx;
goto done;
free_pkt:
if (pkt->largepkt)
kfree(pkt);
else
kmem_cache_free(pq->pkt_slab, pkt);
free_pbc:
if (dma_addr)
dma_pool_free(pq->header_cache, pbc, dma_addr);
else
kfree(pbc);
free_list:
qib_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, list);
done:
return ret;
}
static void qib_user_sdma_set_complete_counter(struct qib_user_sdma_queue *pq,
u32 c)
{
pq->sent_counter = c;
}
static int qib_user_sdma_queue_clean(struct qib_pportdata *ppd,
struct qib_user_sdma_queue *pq)
{
struct qib_devdata *dd = ppd->dd;
struct list_head free_list;
struct qib_user_sdma_pkt *pkt;
struct qib_user_sdma_pkt *pkt_prev;
unsigned long flags;
int ret = 0;
if (!pq->num_sending)
return 0;
INIT_LIST_HEAD(&free_list);
spin_lock_irqsave(&pq->sent_lock, flags);
list_for_each_entry_safe(pkt, pkt_prev, &pq->sent, list) {
s64 descd = ppd->sdma_descq_removed - pkt->added;
if (descd < 0)
break;
list_move_tail(&pkt->list, &free_list);
ret++;
pq->num_sending--;
}
spin_unlock_irqrestore(&pq->sent_lock, flags);
if (!list_empty(&free_list)) {
u32 counter;
pkt = list_entry(free_list.prev,
struct qib_user_sdma_pkt, list);
counter = pkt->counter;
qib_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, &free_list);
qib_user_sdma_set_complete_counter(pq, counter);
}
return ret;
}
void qib_user_sdma_queue_destroy(struct qib_user_sdma_queue *pq)
{
if (!pq)
return;
pq->sdma_rb_node->refcount--;
if (pq->sdma_rb_node->refcount == 0) {
rb_erase(&pq->sdma_rb_node->node, &qib_user_sdma_rb_root);
kfree(pq->sdma_rb_node);
}
dma_pool_destroy(pq->header_cache);
kmem_cache_destroy(pq->pkt_slab);
kfree(pq);
}
static int qib_user_sdma_hwqueue_clean(struct qib_pportdata *ppd)
{
int ret;
unsigned long flags;
spin_lock_irqsave(&ppd->sdma_lock, flags);
ret = qib_sdma_make_progress(ppd);
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
return ret;
}
void qib_user_sdma_queue_drain(struct qib_pportdata *ppd,
struct qib_user_sdma_queue *pq)
{
struct qib_devdata *dd = ppd->dd;
unsigned long flags;
int i;
if (!pq)
return;
for (i = 0; i < QIB_USER_SDMA_DRAIN_TIMEOUT; i++) {
mutex_lock(&pq->lock);
if (!pq->num_pending && !pq->num_sending) {
mutex_unlock(&pq->lock);
break;
}
qib_user_sdma_hwqueue_clean(ppd);
qib_user_sdma_queue_clean(ppd, pq);
mutex_unlock(&pq->lock);
msleep(10);
}
if (pq->num_pending || pq->num_sending) {
struct qib_user_sdma_pkt *pkt;
struct qib_user_sdma_pkt *pkt_prev;
struct list_head free_list;
mutex_lock(&pq->lock);
spin_lock_irqsave(&ppd->sdma_lock, flags);
if (pq->num_pending) {
list_for_each_entry_safe(pkt, pkt_prev,
&ppd->sdma_userpending, list) {
if (pkt->pq == pq) {
list_move_tail(&pkt->list, &pq->sent);
pq->num_pending--;
pq->num_sending++;
}
}
}
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
qib_dev_err(dd, "user sdma lists not empty: forcing!\n");
INIT_LIST_HEAD(&free_list);
list_splice_init(&pq->sent, &free_list);
pq->num_sending = 0;
qib_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, &free_list);
mutex_unlock(&pq->lock);
}
}
static inline __le64 qib_sdma_make_desc0(u8 gen,
u64 addr, u64 dwlen, u64 dwoffset)
{
return cpu_to_le64(
((addr & 0xfffffffcULL) << 32) |
((gen & 3ULL) << 30) |
((dwlen & 0x7ffULL) << 16) |
(dwoffset & 0x7ffULL));
}
static inline __le64 qib_sdma_make_first_desc0(__le64 descq)
{
return descq | cpu_to_le64(1ULL << 12);
}
static inline __le64 qib_sdma_make_last_desc0(__le64 descq)
{
return descq | cpu_to_le64(1ULL << 11 | 1ULL << 13);
}
static inline __le64 qib_sdma_make_desc1(u64 addr)
{
return cpu_to_le64(addr >> 32);
}
static void qib_user_sdma_send_frag(struct qib_pportdata *ppd,
struct qib_user_sdma_pkt *pkt, int idx,
unsigned ofs, u16 tail, u8 gen)
{
const u64 addr = (u64) pkt->addr[idx].addr +
(u64) pkt->addr[idx].offset;
const u64 dwlen = (u64) pkt->addr[idx].length / 4;
__le64 *descqp;
__le64 descq0;
descqp = &ppd->sdma_descq[tail].qw[0];
descq0 = qib_sdma_make_desc0(gen, addr, dwlen, ofs);
if (pkt->addr[idx].first_desc)
descq0 = qib_sdma_make_first_desc0(descq0);
if (pkt->addr[idx].last_desc) {
descq0 = qib_sdma_make_last_desc0(descq0);
if (ppd->sdma_intrequest) {
descq0 |= cpu_to_le64(1ULL << 15);
ppd->sdma_intrequest = 0;
}
}
descqp[0] = descq0;
descqp[1] = qib_sdma_make_desc1(addr);
}
void qib_user_sdma_send_desc(struct qib_pportdata *ppd,
struct list_head *pktlist)
{
struct qib_devdata *dd = ppd->dd;
u16 nfree, nsent;
u16 tail, tail_c;
u8 gen, gen_c;
nfree = qib_sdma_descq_freecnt(ppd);
if (!nfree)
return;
retry:
nsent = 0;
tail_c = tail = ppd->sdma_descq_tail;
gen_c = gen = ppd->sdma_generation;
while (!list_empty(pktlist)) {
struct qib_user_sdma_pkt *pkt =
list_entry(pktlist->next, struct qib_user_sdma_pkt,
list);
int i, j, c = 0;
unsigned ofs = 0;
u16 dtail = tail;
for (i = pkt->index; i < pkt->naddr && nfree; i++) {
qib_user_sdma_send_frag(ppd, pkt, i, ofs, tail, gen);
ofs += pkt->addr[i].length >> 2;
if (++tail == ppd->sdma_descq_cnt) {
tail = 0;
++gen;
ppd->sdma_intrequest = 1;
} else if (tail == (ppd->sdma_descq_cnt>>1)) {
ppd->sdma_intrequest = 1;
}
nfree--;
if (pkt->addr[i].last_desc == 0)
continue;
if (ofs > dd->piosize2kmax_dwords) {
for (j = pkt->index; j <= i; j++) {
ppd->sdma_descq[dtail].qw[0] |=
cpu_to_le64(1ULL << 14);
if (++dtail == ppd->sdma_descq_cnt)
dtail = 0;
}
}
c += i + 1 - pkt->index;
pkt->index = i + 1;
tail_c = dtail = tail;
gen_c = gen;
ofs = 0;
}
ppd->sdma_descq_added += c;
nsent += c;
if (pkt->index == pkt->naddr) {
pkt->added = ppd->sdma_descq_added;
pkt->pq->added = pkt->added;
pkt->pq->num_pending--;
spin_lock(&pkt->pq->sent_lock);
pkt->pq->num_sending++;
list_move_tail(&pkt->list, &pkt->pq->sent);
spin_unlock(&pkt->pq->sent_lock);
}
if (!nfree || (nsent<<2) > ppd->sdma_descq_cnt)
break;
}
if (ppd->sdma_descq_tail != tail_c) {
ppd->sdma_generation = gen_c;
dd->f_sdma_update_tail(ppd, tail_c);
}
if (nfree && !list_empty(pktlist))
goto retry;
return;
}
static int qib_user_sdma_push_pkts(struct qib_pportdata *ppd,
struct qib_user_sdma_queue *pq,
struct list_head *pktlist, int count)
{
unsigned long flags;
if (unlikely(!(ppd->lflags & QIBL_LINKACTIVE)))
return -ECOMM;
if (pq->sdma_rb_node->refcount > 1) {
spin_lock_irqsave(&ppd->sdma_lock, flags);
if (unlikely(!__qib_sdma_running(ppd))) {
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
return -ECOMM;
}
pq->num_pending += count;
list_splice_tail_init(pktlist, &ppd->sdma_userpending);
qib_user_sdma_send_desc(ppd, &ppd->sdma_userpending);
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
return 0;
}
pq->num_pending += count;
do {
spin_lock_irqsave(&ppd->sdma_lock, flags);
if (unlikely(!__qib_sdma_running(ppd))) {
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
return -ECOMM;
}
qib_user_sdma_send_desc(ppd, pktlist);
if (!list_empty(pktlist))
qib_sdma_make_progress(ppd);
spin_unlock_irqrestore(&ppd->sdma_lock, flags);
} while (!list_empty(pktlist));
return 0;
}
int qib_user_sdma_writev(struct qib_ctxtdata *rcd,
struct qib_user_sdma_queue *pq,
const struct iovec *iov,
unsigned long dim)
{
struct qib_devdata *dd = rcd->dd;
struct qib_pportdata *ppd = rcd->ppd;
int ret = 0;
struct list_head list;
int npkts = 0;
INIT_LIST_HEAD(&list);
mutex_lock(&pq->lock);
if (!qib_sdma_running(ppd))
goto done_unlock;
if (pq->added > ppd->sdma_descq_removed)
qib_user_sdma_hwqueue_clean(ppd);
if (pq->num_sending)
qib_user_sdma_queue_clean(ppd, pq);
while (dim) {
int mxp = 1;
int ndesc = 0;
ret = qib_user_sdma_queue_pkts(dd, ppd, pq,
iov, dim, &list, &mxp, &ndesc);
if (ret < 0)
goto done_unlock;
else {
dim -= ret;
iov += ret;
}
if (!list_empty(&list)) {
if (qib_sdma_descq_freecnt(ppd) < ndesc) {
qib_user_sdma_hwqueue_clean(ppd);
if (pq->num_sending)
qib_user_sdma_queue_clean(ppd, pq);
}
ret = qib_user_sdma_push_pkts(ppd, pq, &list, mxp);
if (ret < 0)
goto done_unlock;
else {
npkts += mxp;
pq->counter += mxp;
}
}
}
done_unlock:
if (!list_empty(&list))
qib_user_sdma_free_pkt_list(&dd->pcidev->dev, pq, &list);
mutex_unlock(&pq->lock);
return (ret < 0) ? ret : npkts;
}
int qib_user_sdma_make_progress(struct qib_pportdata *ppd,
struct qib_user_sdma_queue *pq)
{
int ret = 0;
mutex_lock(&pq->lock);
qib_user_sdma_hwqueue_clean(ppd);
ret = qib_user_sdma_queue_clean(ppd, pq);
mutex_unlock(&pq->lock);
return ret;
}
u32 qib_user_sdma_complete_counter(const struct qib_user_sdma_queue *pq)
{
return pq ? pq->sent_counter : 0;
}
u32 qib_user_sdma_inflight_counter(struct qib_user_sdma_queue *pq)
{
return pq ? pq->counter : 0;
}
