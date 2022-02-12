static inline int iovec_may_free(struct user_sdma_iovec *iovec,
void (*free)(struct user_sdma_iovec *))
{
if (ACCESS_ONCE(iovec->offset) == iovec->iov.iov_len) {
free(iovec);
return 1;
}
return 0;
}
static inline void iovec_set_complete(struct user_sdma_iovec *iovec)
{
iovec->offset = iovec->iov.iov_len;
}
static int defer_packet_queue(
struct sdma_engine *sde,
struct iowait *wait,
struct sdma_txreq *txreq,
unsigned seq)
{
struct hfi1_user_sdma_pkt_q *pq =
container_of(wait, struct hfi1_user_sdma_pkt_q, busy);
struct hfi1_ibdev *dev = &pq->dd->verbs_dev;
struct user_sdma_txreq *tx =
container_of(txreq, struct user_sdma_txreq, txreq);
if (sdma_progress(sde, seq, txreq)) {
if (tx->busycount++ < MAX_DEFER_RETRY_COUNT)
goto eagain;
}
xchg(&pq->state, SDMA_PKT_Q_DEFERRED);
write_seqlock(&dev->iowait_lock);
if (list_empty(&pq->busy.list))
list_add_tail(&pq->busy.list, &sde->dmawait);
write_sequnlock(&dev->iowait_lock);
return -EBUSY;
eagain:
return -EAGAIN;
}
static void activate_packet_queue(struct iowait *wait, int reason)
{
struct hfi1_user_sdma_pkt_q *pq =
container_of(wait, struct hfi1_user_sdma_pkt_q, busy);
xchg(&pq->state, SDMA_PKT_Q_ACTIVE);
wake_up(&wait->wait_dma);
}
static void sdma_kmem_cache_ctor(void *obj)
{
struct user_sdma_txreq *tx = (struct user_sdma_txreq *)obj;
memset(tx, 0, sizeof(*tx));
}
int hfi1_user_sdma_alloc_queues(struct hfi1_ctxtdata *uctxt, struct file *fp)
{
int ret = 0;
unsigned memsize;
char buf[64];
struct hfi1_devdata *dd;
struct hfi1_user_sdma_comp_q *cq;
struct hfi1_user_sdma_pkt_q *pq;
unsigned long flags;
if (!uctxt || !fp) {
ret = -EBADF;
goto done;
}
if (!hfi1_sdma_comp_ring_size) {
ret = -EINVAL;
goto done;
}
dd = uctxt->dd;
pq = kzalloc(sizeof(*pq), GFP_KERNEL);
if (!pq) {
dd_dev_err(dd,
"[%u:%u] Failed to allocate SDMA request struct\n",
uctxt->ctxt, subctxt_fp(fp));
goto pq_nomem;
}
memsize = sizeof(*pq->reqs) * hfi1_sdma_comp_ring_size;
pq->reqs = kmalloc(memsize, GFP_KERNEL);
if (!pq->reqs) {
dd_dev_err(dd,
"[%u:%u] Failed to allocate SDMA request queue (%u)\n",
uctxt->ctxt, subctxt_fp(fp), memsize);
goto pq_reqs_nomem;
}
INIT_LIST_HEAD(&pq->list);
pq->dd = dd;
pq->ctxt = uctxt->ctxt;
pq->subctxt = subctxt_fp(fp);
pq->n_max_reqs = hfi1_sdma_comp_ring_size;
pq->state = SDMA_PKT_Q_INACTIVE;
atomic_set(&pq->n_reqs, 0);
iowait_init(&pq->busy, 0, NULL, defer_packet_queue,
activate_packet_queue);
pq->reqidx = 0;
snprintf(buf, 64, "txreq-kmem-cache-%u-%u-%u", dd->unit, uctxt->ctxt,
subctxt_fp(fp));
pq->txreq_cache = kmem_cache_create(buf,
sizeof(struct user_sdma_txreq),
L1_CACHE_BYTES,
SLAB_HWCACHE_ALIGN,
sdma_kmem_cache_ctor);
if (!pq->txreq_cache) {
dd_dev_err(dd, "[%u] Failed to allocate TxReq cache\n",
uctxt->ctxt);
goto pq_txreq_nomem;
}
user_sdma_pkt_fp(fp) = pq;
cq = kzalloc(sizeof(*cq), GFP_KERNEL);
if (!cq) {
dd_dev_err(dd,
"[%u:%u] Failed to allocate SDMA completion queue\n",
uctxt->ctxt, subctxt_fp(fp));
goto cq_nomem;
}
memsize = ALIGN(sizeof(*cq->comps) * hfi1_sdma_comp_ring_size,
PAGE_SIZE);
cq->comps = vmalloc_user(memsize);
if (!cq->comps) {
dd_dev_err(dd,
"[%u:%u] Failed to allocate SDMA completion queue entries\n",
uctxt->ctxt, subctxt_fp(fp));
goto cq_comps_nomem;
}
cq->nentries = hfi1_sdma_comp_ring_size;
user_sdma_comp_fp(fp) = cq;
spin_lock_irqsave(&uctxt->sdma_qlock, flags);
list_add(&pq->list, &uctxt->sdma_queues);
spin_unlock_irqrestore(&uctxt->sdma_qlock, flags);
goto done;
cq_comps_nomem:
kfree(cq);
cq_nomem:
kmem_cache_destroy(pq->txreq_cache);
pq_txreq_nomem:
kfree(pq->reqs);
pq_reqs_nomem:
kfree(pq);
user_sdma_pkt_fp(fp) = NULL;
pq_nomem:
ret = -ENOMEM;
done:
return ret;
}
int hfi1_user_sdma_free_queues(struct hfi1_filedata *fd)
{
struct hfi1_ctxtdata *uctxt = fd->uctxt;
struct hfi1_user_sdma_pkt_q *pq;
unsigned long flags;
hfi1_cdbg(SDMA, "[%u:%u:%u] Freeing user SDMA queues", uctxt->dd->unit,
uctxt->ctxt, fd->subctxt);
pq = fd->pq;
if (pq) {
u16 i, j;
spin_lock_irqsave(&uctxt->sdma_qlock, flags);
if (!list_empty(&pq->list))
list_del_init(&pq->list);
spin_unlock_irqrestore(&uctxt->sdma_qlock, flags);
iowait_sdma_drain(&pq->busy);
if (pq->reqs) {
for (i = 0, j = 0; i < atomic_read(&pq->n_reqs) &&
j < pq->n_max_reqs; j++) {
struct user_sdma_request *req = &pq->reqs[j];
if (test_bit(SDMA_REQ_IN_USE, &req->flags)) {
set_comp_state(req, ERROR, -ECOMM);
user_sdma_free_request(req);
i++;
}
}
kfree(pq->reqs);
}
if (pq->txreq_cache)
kmem_cache_destroy(pq->txreq_cache);
kfree(pq);
fd->pq = NULL;
}
if (fd->cq) {
if (fd->cq->comps)
vfree(fd->cq->comps);
kfree(fd->cq);
fd->cq = NULL;
}
return 0;
}
int hfi1_user_sdma_process_request(struct file *fp, struct iovec *iovec,
unsigned long dim, unsigned long *count)
{
int ret = 0, i = 0, sent;
struct hfi1_ctxtdata *uctxt = ctxt_fp(fp);
struct hfi1_user_sdma_pkt_q *pq = user_sdma_pkt_fp(fp);
struct hfi1_user_sdma_comp_q *cq = user_sdma_comp_fp(fp);
struct hfi1_devdata *dd = pq->dd;
unsigned long idx = 0;
u8 pcount = initial_pkt_count;
struct sdma_req_info info;
struct user_sdma_request *req;
u8 opcode, sc, vl;
if (iovec[idx].iov_len < sizeof(info) + sizeof(req->hdr)) {
hfi1_cdbg(
SDMA,
"[%u:%u:%u] First vector not big enough for header %lu/%lu",
dd->unit, uctxt->ctxt, subctxt_fp(fp),
iovec[idx].iov_len, sizeof(info) + sizeof(req->hdr));
ret = -EINVAL;
goto done;
}
ret = copy_from_user(&info, iovec[idx].iov_base, sizeof(info));
if (ret) {
hfi1_cdbg(SDMA, "[%u:%u:%u] Failed to copy info QW (%d)",
dd->unit, uctxt->ctxt, subctxt_fp(fp), ret);
ret = -EFAULT;
goto done;
}
trace_hfi1_sdma_user_reqinfo(dd, uctxt->ctxt, subctxt_fp(fp),
(u16 *)&info);
if (cq->comps[info.comp_idx].status == QUEUED) {
hfi1_cdbg(SDMA, "[%u:%u:%u] Entry %u is in QUEUED state",
dd->unit, uctxt->ctxt, subctxt_fp(fp),
info.comp_idx);
ret = -EBADSLT;
goto done;
}
if (!info.fragsize) {
hfi1_cdbg(SDMA,
"[%u:%u:%u:%u] Request does not specify fragsize",
dd->unit, uctxt->ctxt, subctxt_fp(fp), info.comp_idx);
ret = -EINVAL;
goto done;
}
hfi1_cdbg(SDMA, "[%u:%u:%u] Using req/comp entry %u\n", dd->unit,
uctxt->ctxt, subctxt_fp(fp), info.comp_idx);
req = pq->reqs + info.comp_idx;
memset(req, 0, sizeof(*req));
set_bit(SDMA_REQ_IN_USE, &req->flags);
req->data_iovs = req_iovcnt(info.ctrl) - 1;
req->pq = pq;
req->cq = cq;
INIT_LIST_HEAD(&req->txps);
spin_lock_init(&req->list_lock);
memcpy(&req->info, &info, sizeof(info));
if (req_opcode(info.ctrl) == EXPECTED)
req->data_iovs--;
if (!info.npkts || req->data_iovs > MAX_VECTORS_PER_REQ) {
SDMA_DBG(req, "Too many vectors (%u/%u)", req->data_iovs,
MAX_VECTORS_PER_REQ);
ret = -EINVAL;
goto done;
}
ret = copy_from_user(&req->hdr, iovec[idx].iov_base + sizeof(info),
sizeof(req->hdr));
if (ret) {
SDMA_DBG(req, "Failed to copy header template (%d)", ret);
ret = -EFAULT;
goto free_req;
}
if (!HFI1_CAP_IS_USET(STATIC_RATE_CTRL))
req->hdr.pbc[2] = 0;
opcode = (be32_to_cpu(req->hdr.bth[0]) >> 24) & 0xff;
if ((opcode & USER_OPCODE_CHECK_MASK) !=
USER_OPCODE_CHECK_VAL) {
SDMA_DBG(req, "Invalid opcode (%d)", opcode);
ret = -EINVAL;
goto free_req;
}
vl = (le16_to_cpu(req->hdr.pbc[0]) >> 12) & 0xF;
sc = (((be16_to_cpu(req->hdr.lrh[0]) >> 12) & 0xF) |
(((le16_to_cpu(req->hdr.pbc[1]) >> 14) & 0x1) << 4));
if (vl >= dd->pport->vls_operational ||
vl != sc_to_vlt(dd, sc)) {
SDMA_DBG(req, "Invalid SC(%u)/VL(%u)", sc, vl);
ret = -EINVAL;
goto free_req;
}
if ((be16_to_cpu(req->hdr.lrh[0]) & 0x3) == HFI1_LRH_GRH) {
SDMA_DBG(req, "User tried to pass in a GRH");
ret = -EINVAL;
goto free_req;
}
req->koffset = le32_to_cpu(req->hdr.kdeth.swdata[6]);
req->tidoffset = KDETH_GET(req->hdr.kdeth.ver_tid_offset, OFFSET) *
(KDETH_GET(req->hdr.kdeth.ver_tid_offset, OM) ?
KDETH_OM_LARGE : KDETH_OM_SMALL);
SDMA_DBG(req, "Initial TID offset %u", req->tidoffset);
idx++;
while (i < req->data_iovs) {
memcpy(&req->iovs[i].iov, iovec + idx++, sizeof(struct iovec));
req->iovs[i].offset = 0;
req->data_len += req->iovs[i++].iov.iov_len;
}
SDMA_DBG(req, "total data length %u", req->data_len);
if (pcount > req->info.npkts)
pcount = req->info.npkts;
if (req_opcode(req->info.ctrl) == EXPECTED) {
u16 ntids = iovec[idx].iov_len / sizeof(*req->tids);
if (!ntids || ntids > MAX_TID_PAIR_ENTRIES) {
ret = -EINVAL;
goto free_req;
}
req->tids = kcalloc(ntids, sizeof(*req->tids), GFP_KERNEL);
if (!req->tids) {
ret = -ENOMEM;
goto free_req;
}
ret = copy_from_user(req->tids, iovec[idx].iov_base,
ntids * sizeof(*req->tids));
if (ret) {
SDMA_DBG(req, "Failed to copy %d TIDs (%d)",
ntids, ret);
ret = -EFAULT;
goto free_req;
}
req->n_tids = ntids;
idx++;
}
req->sde = sdma_select_engine_vl(dd,
(u32)(uctxt->ctxt + subctxt_fp(fp)),
vl);
if (!req->sde || !sdma_running(req->sde)) {
ret = -ECOMM;
goto free_req;
}
if (req->info.npkts > 1 && HFI1_CAP_IS_USET(SDMA_AHG)) {
int ahg = sdma_ahg_alloc(req->sde);
if (likely(ahg >= 0)) {
req->ahg_idx = (u8)ahg;
set_bit(SDMA_REQ_HAVE_AHG, &req->flags);
}
}
set_comp_state(req, QUEUED, 0);
sent = user_sdma_send_pkts(req, pcount);
if (unlikely(sent < 0)) {
if (sent != -EBUSY) {
ret = sent;
goto send_err;
} else
sent = 0;
}
atomic_inc(&pq->n_reqs);
if (sent < req->info.npkts) {
get_task_struct(current);
req->user_proc = current;
while (!test_bit(SDMA_REQ_SEND_DONE, &req->flags)) {
ret = user_sdma_send_pkts(req, pcount);
if (ret < 0) {
if (ret != -EBUSY)
goto send_err;
wait_event_interruptible_timeout(
pq->busy.wait_dma,
(pq->state == SDMA_PKT_Q_ACTIVE),
msecs_to_jiffies(
SDMA_IOWAIT_TIMEOUT));
}
}
}
ret = 0;
*count += idx;
goto done;
send_err:
set_comp_state(req, ERROR, ret);
free_req:
user_sdma_free_request(req);
done:
return ret;
}
static inline u32 compute_data_length(struct user_sdma_request *req,
struct user_sdma_txreq *tx)
{
u32 len;
if (!req->seqnum) {
len = ((be16_to_cpu(req->hdr.lrh[2]) << 2) -
(sizeof(tx->hdr) - 4));
} else if (req_opcode(req->info.ctrl) == EXPECTED) {
u32 tidlen = EXP_TID_GET(req->tids[req->tididx], LEN) *
PAGE_SIZE;
len = min(tidlen - req->tidoffset, (u32)req->info.fragsize);
if (unlikely(!len) && ++req->tididx < req->n_tids &&
req->tids[req->tididx]) {
tidlen = EXP_TID_GET(req->tids[req->tididx],
LEN) * PAGE_SIZE;
req->tidoffset = 0;
len = min_t(u32, tidlen, req->info.fragsize);
}
len = min(len, req->data_len - req->sent);
} else
len = min(req->data_len - req->sent, (u32)req->info.fragsize);
SDMA_DBG(req, "Data Length = %u", len);
return len;
}
static inline u32 get_lrh_len(struct hfi1_pkt_header hdr, u32 len)
{
return ((sizeof(hdr) - sizeof(hdr.pbc)) + 4 + len);
}
static int user_sdma_send_pkts(struct user_sdma_request *req, unsigned maxpkts)
{
int ret = 0;
unsigned npkts = 0;
struct user_sdma_txreq *tx = NULL;
struct hfi1_user_sdma_pkt_q *pq = NULL;
struct user_sdma_iovec *iovec = NULL;
if (!req->pq) {
ret = -EINVAL;
goto done;
}
pq = req->pq;
if (unlikely(req->seqnum == req->info.npkts)) {
if (!list_empty(&req->txps))
goto dosend;
goto done;
}
if (!maxpkts || maxpkts > req->info.npkts - req->seqnum)
maxpkts = req->info.npkts - req->seqnum;
while (npkts < maxpkts) {
u32 datalen = 0, queued = 0, data_sent = 0;
u64 iov_offset = 0;
if (test_bit(SDMA_REQ_HAS_ERROR, &req->flags)) {
set_bit(SDMA_REQ_DONE_ERROR, &req->flags);
ret = -EFAULT;
goto done;
}
tx = kmem_cache_alloc(pq->txreq_cache, GFP_KERNEL);
if (!tx) {
ret = -ENOMEM;
goto done;
}
tx->flags = 0;
tx->req = req;
tx->busycount = 0;
tx->iovec1 = NULL;
tx->iovec2 = NULL;
if (req->seqnum == req->info.npkts - 1)
tx->flags |= USER_SDMA_TXREQ_FLAGS_LAST_PKT;
if (req->data_len) {
iovec = &req->iovs[req->iov_idx];
if (ACCESS_ONCE(iovec->offset) == iovec->iov.iov_len) {
if (++req->iov_idx == req->data_iovs) {
ret = -EFAULT;
goto free_txreq;
}
iovec = &req->iovs[req->iov_idx];
WARN_ON(iovec->offset);
}
if (unlikely(!iovec->pages && iovec->iov.iov_len)) {
ret = pin_vector_pages(req, iovec);
if (ret)
goto free_tx;
}
tx->iovec1 = iovec;
datalen = compute_data_length(req, tx);
if (!datalen) {
SDMA_DBG(req,
"Request has data but pkt len is 0");
ret = -EFAULT;
goto free_tx;
}
}
if (test_bit(SDMA_REQ_HAVE_AHG, &req->flags)) {
if (!req->seqnum) {
u16 pbclen = le16_to_cpu(req->hdr.pbc[0]);
u32 lrhlen = get_lrh_len(req->hdr, datalen);
memcpy(&tx->hdr, &req->hdr, sizeof(tx->hdr));
if (PBC2LRH(pbclen) != lrhlen) {
pbclen = (pbclen & 0xf000) |
LRH2PBC(lrhlen);
tx->hdr.pbc[0] = cpu_to_le16(pbclen);
}
ret = sdma_txinit_ahg(&tx->txreq,
SDMA_TXREQ_F_AHG_COPY,
sizeof(tx->hdr) + datalen,
req->ahg_idx, 0, NULL, 0,
user_sdma_txreq_cb);
if (ret)
goto free_tx;
ret = sdma_txadd_kvaddr(pq->dd, &tx->txreq,
&tx->hdr,
sizeof(tx->hdr));
if (ret)
goto free_txreq;
} else {
int changes;
changes = set_txreq_header_ahg(req, tx,
datalen);
if (changes < 0)
goto free_tx;
sdma_txinit_ahg(&tx->txreq,
SDMA_TXREQ_F_USE_AHG,
datalen, req->ahg_idx, changes,
req->ahg, sizeof(req->hdr),
user_sdma_txreq_cb);
}
} else {
ret = sdma_txinit(&tx->txreq, 0, sizeof(req->hdr) +
datalen, user_sdma_txreq_cb);
if (ret)
goto free_tx;
ret = set_txreq_header(req, tx, datalen);
if (ret)
goto free_txreq;
}
while (queued < datalen &&
(req->sent + data_sent) < req->data_len) {
unsigned long base, offset;
unsigned pageidx, len;
base = (unsigned long)iovec->iov.iov_base;
offset = ((base + iovec->offset + iov_offset) &
~PAGE_MASK);
pageidx = (((iovec->offset + iov_offset +
base) - (base & PAGE_MASK)) >> PAGE_SHIFT);
len = offset + req->info.fragsize > PAGE_SIZE ?
PAGE_SIZE - offset : req->info.fragsize;
len = min((datalen - queued), len);
ret = sdma_txadd_page(pq->dd, &tx->txreq,
iovec->pages[pageidx],
offset, len);
if (ret) {
dd_dev_err(pq->dd,
"SDMA txreq add page failed %d\n",
ret);
iovec_set_complete(iovec);
goto free_txreq;
}
iov_offset += len;
queued += len;
data_sent += len;
if (unlikely(queued < datalen &&
pageidx == iovec->npages &&
req->iov_idx < req->data_iovs - 1)) {
iovec->offset += iov_offset;
iovec = &req->iovs[++req->iov_idx];
if (!iovec->pages) {
ret = pin_vector_pages(req, iovec);
if (ret)
goto free_txreq;
}
iov_offset = 0;
tx->iovec2 = iovec;
}
}
req->koffset += datalen;
if (req_opcode(req->info.ctrl) == EXPECTED)
req->tidoffset += datalen;
req->sent += data_sent;
if (req->data_len) {
if (tx->iovec1 && !tx->iovec2)
tx->iovec1->offset += iov_offset;
else if (tx->iovec2)
tx->iovec2->offset += iov_offset;
}
tx->seqnum = req->seqnum++;
list_add_tail(&tx->txreq.list, &req->txps);
npkts++;
}
dosend:
ret = sdma_send_txlist(req->sde, &pq->busy, &req->txps);
if (list_empty(&req->txps))
if (req->seqnum == req->info.npkts) {
set_bit(SDMA_REQ_SEND_DONE, &req->flags);
if (test_bit(SDMA_REQ_HAVE_AHG, &req->flags))
sdma_ahg_free(req->sde, req->ahg_idx);
}
goto done;
free_txreq:
sdma_txclean(pq->dd, &tx->txreq);
free_tx:
kmem_cache_free(pq->txreq_cache, tx);
done:
return ret;
}
static inline int num_user_pages(const struct iovec *iov)
{
const unsigned long addr = (unsigned long) iov->iov_base;
const unsigned long len = iov->iov_len;
const unsigned long spage = addr & PAGE_MASK;
const unsigned long epage = (addr + len - 1) & PAGE_MASK;
return 1 + ((epage - spage) >> PAGE_SHIFT);
}
static int pin_vector_pages(struct user_sdma_request *req,
struct user_sdma_iovec *iovec) {
int ret = 0;
unsigned pinned;
iovec->npages = num_user_pages(&iovec->iov);
iovec->pages = kzalloc(sizeof(*iovec->pages) *
iovec->npages, GFP_KERNEL);
if (!iovec->pages) {
SDMA_DBG(req, "Failed page array alloc");
ret = -ENOMEM;
goto done;
}
if (current->flags & PF_KTHREAD)
use_mm(req->user_proc->mm);
pinned = get_user_pages_fast(
(unsigned long)iovec->iov.iov_base,
iovec->npages, 0, iovec->pages);
if (current->flags & PF_KTHREAD)
unuse_mm(req->user_proc->mm);
if (pinned != iovec->npages) {
SDMA_DBG(req, "Failed to pin pages (%u/%u)", pinned,
iovec->npages);
ret = -EFAULT;
goto pfree;
}
goto done;
pfree:
unpin_vector_pages(iovec);
done:
return ret;
}
static void unpin_vector_pages(struct user_sdma_iovec *iovec)
{
unsigned i;
if (ACCESS_ONCE(iovec->offset) != iovec->iov.iov_len) {
hfi1_cdbg(SDMA,
"the complete vector has not been sent yet %llu %zu",
iovec->offset, iovec->iov.iov_len);
return;
}
for (i = 0; i < iovec->npages; i++)
if (iovec->pages[i])
put_page(iovec->pages[i]);
kfree(iovec->pages);
iovec->pages = NULL;
iovec->npages = 0;
iovec->offset = 0;
}
static int check_header_template(struct user_sdma_request *req,
struct hfi1_pkt_header *hdr, u32 lrhlen,
u32 datalen)
{
if (req->info.fragsize % PIO_BLOCK_SIZE ||
lrhlen & 0x3 || req->data_len & 0x3 ||
lrhlen > get_lrh_len(*hdr, req->info.fragsize))
return -EINVAL;
if (req_opcode(req->info.ctrl) == EXPECTED) {
u32 tidval = req->tids[req->tididx],
tidlen = EXP_TID_GET(tidval, LEN) * PAGE_SIZE,
tididx = EXP_TID_GET(tidval, IDX),
tidctrl = EXP_TID_GET(tidval, CTRL),
tidoff;
__le32 kval = hdr->kdeth.ver_tid_offset;
tidoff = KDETH_GET(kval, OFFSET) *
(KDETH_GET(req->hdr.kdeth.ver_tid_offset, OM) ?
KDETH_OM_LARGE : KDETH_OM_SMALL);
if ((tidoff + datalen > tidlen) ||
KDETH_GET(kval, TIDCTRL) != tidctrl ||
KDETH_GET(kval, TID) != tididx)
return -EINVAL;
}
return 0;
}
static inline u32 set_pkt_bth_psn(__be32 bthpsn, u8 expct, u32 frags)
{
u32 val = be32_to_cpu(bthpsn),
mask = (HFI1_CAP_IS_KSET(EXTENDED_PSN) ? 0x7fffffffull :
0xffffffull),
psn = val & mask;
if (expct)
psn = (psn & ~BTH_SEQ_MASK) | ((psn + frags) & BTH_SEQ_MASK);
else
psn = psn + frags;
return psn & mask;
}
static int set_txreq_header(struct user_sdma_request *req,
struct user_sdma_txreq *tx, u32 datalen)
{
struct hfi1_user_sdma_pkt_q *pq = req->pq;
struct hfi1_pkt_header *hdr = &tx->hdr;
u16 pbclen;
int ret;
u32 tidval = 0, lrhlen = get_lrh_len(*hdr, datalen);
memcpy(hdr, &req->hdr, sizeof(*hdr));
pbclen = le16_to_cpu(hdr->pbc[0]);
if (PBC2LRH(pbclen) != lrhlen) {
pbclen = (pbclen & 0xf000) | LRH2PBC(lrhlen);
hdr->pbc[0] = cpu_to_le16(pbclen);
hdr->lrh[2] = cpu_to_be16(lrhlen >> 2);
if (unlikely(req->seqnum == 2)) {
req->hdr.pbc[0] = hdr->pbc[0];
req->hdr.lrh[2] = hdr->lrh[2];
}
}
if (unlikely(!req->seqnum)) {
ret = check_header_template(req, hdr, lrhlen, datalen);
if (ret)
return ret;
goto done;
}
hdr->bth[2] = cpu_to_be32(
set_pkt_bth_psn(hdr->bth[2],
(req_opcode(req->info.ctrl) == EXPECTED),
req->seqnum));
if (unlikely(tx->flags & USER_SDMA_TXREQ_FLAGS_LAST_PKT))
hdr->bth[2] |= cpu_to_be32(1UL<<31);
hdr->kdeth.swdata[6] = cpu_to_le32(req->koffset);
if (req_opcode(req->info.ctrl) == EXPECTED) {
tidval = req->tids[req->tididx];
if ((req->tidoffset) == (EXP_TID_GET(tidval, LEN) *
PAGE_SIZE)) {
req->tidoffset = 0;
if (++req->tididx > req->n_tids - 1 ||
!req->tids[req->tididx]) {
return -EINVAL;
}
tidval = req->tids[req->tididx];
}
req->omfactor = EXP_TID_GET(tidval, LEN) * PAGE_SIZE >=
KDETH_OM_MAX_SIZE ? KDETH_OM_LARGE : KDETH_OM_SMALL;
KDETH_SET(hdr->kdeth.ver_tid_offset, TIDCTRL,
EXP_TID_GET(tidval, CTRL));
KDETH_SET(hdr->kdeth.ver_tid_offset, TID,
EXP_TID_GET(tidval, IDX));
if (unlikely(tx->flags & USER_SDMA_TXREQ_FLAGS_LAST_PKT))
KDETH_SET(hdr->kdeth.ver_tid_offset, SH, 0);
SDMA_DBG(req, "TID offset %ubytes %uunits om%u",
req->tidoffset, req->tidoffset / req->omfactor,
!!(req->omfactor - KDETH_OM_SMALL));
KDETH_SET(hdr->kdeth.ver_tid_offset, OFFSET,
req->tidoffset / req->omfactor);
KDETH_SET(hdr->kdeth.ver_tid_offset, OM,
!!(req->omfactor - KDETH_OM_SMALL));
}
done:
trace_hfi1_sdma_user_header(pq->dd, pq->ctxt, pq->subctxt,
req->info.comp_idx, hdr, tidval);
return sdma_txadd_kvaddr(pq->dd, &tx->txreq, hdr, sizeof(*hdr));
}
static int set_txreq_header_ahg(struct user_sdma_request *req,
struct user_sdma_txreq *tx, u32 len)
{
int diff = 0;
struct hfi1_user_sdma_pkt_q *pq = req->pq;
struct hfi1_pkt_header *hdr = &req->hdr;
u16 pbclen = le16_to_cpu(hdr->pbc[0]);
u32 val32, tidval = 0, lrhlen = get_lrh_len(*hdr, len);
if (PBC2LRH(pbclen) != lrhlen) {
AHG_HEADER_SET(req->ahg, diff, 0, 0, 12,
cpu_to_le16(LRH2PBC(lrhlen)));
AHG_HEADER_SET(req->ahg, diff, 3, 0, 16,
cpu_to_be16(lrhlen >> 2));
}
val32 = (be32_to_cpu(hdr->bth[2]) + req->seqnum) &
(HFI1_CAP_IS_KSET(EXTENDED_PSN) ? 0x7fffffff : 0xffffff);
if (unlikely(tx->flags & USER_SDMA_TXREQ_FLAGS_LAST_PKT))
val32 |= 1UL << 31;
AHG_HEADER_SET(req->ahg, diff, 6, 0, 16, cpu_to_be16(val32 >> 16));
AHG_HEADER_SET(req->ahg, diff, 6, 16, 16, cpu_to_be16(val32 & 0xffff));
AHG_HEADER_SET(req->ahg, diff, 15, 0, 16,
cpu_to_le16(req->koffset & 0xffff));
AHG_HEADER_SET(req->ahg, diff, 15, 16, 16,
cpu_to_le16(req->koffset >> 16));
if (req_opcode(req->info.ctrl) == EXPECTED) {
__le16 val;
tidval = req->tids[req->tididx];
if ((req->tidoffset) == (EXP_TID_GET(tidval, LEN) *
PAGE_SIZE)) {
req->tidoffset = 0;
if (++req->tididx > req->n_tids - 1 ||
!req->tids[req->tididx]) {
return -EINVAL;
}
tidval = req->tids[req->tididx];
}
req->omfactor = ((EXP_TID_GET(tidval, LEN) *
PAGE_SIZE) >=
KDETH_OM_MAX_SIZE) ? KDETH_OM_LARGE :
KDETH_OM_SMALL;
AHG_HEADER_SET(req->ahg, diff, 7, 0, 16,
((!!(req->omfactor - KDETH_OM_SMALL)) << 15 |
((req->tidoffset / req->omfactor) & 0x7fff)));
val = cpu_to_le16(((EXP_TID_GET(tidval, CTRL) & 0x3) << 10) |
(EXP_TID_GET(tidval, IDX) & 0x3ff));
if (unlikely(tx->flags & USER_SDMA_TXREQ_FLAGS_LAST_PKT)) {
val |= cpu_to_le16(KDETH_GET(hdr->kdeth.ver_tid_offset,
INTR) >> 16);
val &= cpu_to_le16(~(1U << 13));
AHG_HEADER_SET(req->ahg, diff, 7, 16, 14, val);
} else
AHG_HEADER_SET(req->ahg, diff, 7, 16, 12, val);
}
trace_hfi1_sdma_user_header_ahg(pq->dd, pq->ctxt, pq->subctxt,
req->info.comp_idx, req->sde->this_idx,
req->ahg_idx, req->ahg, diff, tidval);
return diff;
}
static void user_sdma_txreq_cb(struct sdma_txreq *txreq, int status,
int drain)
{
struct user_sdma_txreq *tx =
container_of(txreq, struct user_sdma_txreq, txreq);
struct user_sdma_request *req = tx->req;
struct hfi1_user_sdma_pkt_q *pq = req ? req->pq : NULL;
u64 tx_seqnum;
if (unlikely(!req || !pq))
return;
if (tx->iovec1)
iovec_may_free(tx->iovec1, unpin_vector_pages);
if (tx->iovec2)
iovec_may_free(tx->iovec2, unpin_vector_pages);
tx_seqnum = tx->seqnum;
kmem_cache_free(pq->txreq_cache, tx);
if (status != SDMA_TXREQ_S_OK) {
dd_dev_err(pq->dd, "SDMA completion with error %d", status);
set_comp_state(req, ERROR, status);
set_bit(SDMA_REQ_HAS_ERROR, &req->flags);
if (tx_seqnum == ACCESS_ONCE(req->seqnum) &&
test_bit(SDMA_REQ_DONE_ERROR, &req->flags)) {
atomic_dec(&pq->n_reqs);
user_sdma_free_request(req);
}
} else {
if (tx_seqnum == req->info.npkts - 1) {
atomic_dec(&pq->n_reqs);
set_comp_state(req, COMPLETE, 0);
user_sdma_free_request(req);
}
}
if (!atomic_read(&pq->n_reqs))
xchg(&pq->state, SDMA_PKT_Q_INACTIVE);
}
static void user_sdma_free_request(struct user_sdma_request *req)
{
if (!list_empty(&req->txps)) {
struct sdma_txreq *t, *p;
list_for_each_entry_safe(t, p, &req->txps, list) {
struct user_sdma_txreq *tx =
container_of(t, struct user_sdma_txreq, txreq);
list_del_init(&t->list);
sdma_txclean(req->pq->dd, t);
kmem_cache_free(req->pq->txreq_cache, tx);
}
}
if (req->data_iovs) {
int i;
for (i = 0; i < req->data_iovs; i++)
if (req->iovs[i].npages && req->iovs[i].pages)
unpin_vector_pages(&req->iovs[i]);
}
if (req->user_proc)
put_task_struct(req->user_proc);
kfree(req->tids);
clear_bit(SDMA_REQ_IN_USE, &req->flags);
}
static inline void set_comp_state(struct user_sdma_request *req,
enum hfi1_sdma_comp_state state,
int ret)
{
SDMA_DBG(req, "Setting completion status %u %d", state, ret);
req->cq->comps[req->info.comp_idx].status = state;
if (state == ERROR)
req->cq->comps[req->info.comp_idx].errcode = -ret;
trace_hfi1_sdma_user_completion(req->pq->dd, req->pq->ctxt,
req->pq->subctxt, req->info.comp_idx,
state, ret);
}
