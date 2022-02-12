static void
csio_get_flbuf_size(struct csio_hw *hw, struct csio_sge *sge, uint32_t reg)
{
sge->sge_fl_buf_size[reg] = csio_rd_reg32(hw, SGE_FL_BUFFER_SIZE0 +
reg * sizeof(uint32_t));
}
static inline uint32_t
csio_wr_fl_bufsz(struct csio_sge *sge, struct csio_dma_buf *buf)
{
return sge->sge_fl_buf_size[buf->paddr & 0xF];
}
static inline uint32_t
csio_wr_qstat_pgsz(struct csio_hw *hw)
{
return (hw->wrm.sge.sge_control & EGRSTATUSPAGESIZE(1)) ? 128 : 64;
}
static inline void
csio_wr_ring_fldb(struct csio_hw *hw, struct csio_q *flq)
{
if (flq->inc_idx >= 8) {
csio_wr_reg32(hw, DBPRIO(1) | QID(flq->un.fl.flid) |
PIDX(flq->inc_idx / 8),
MYPF_REG(SGE_PF_KDOORBELL));
flq->inc_idx &= 7;
}
}
static void
csio_wr_sge_intr_enable(struct csio_hw *hw, uint16_t iqid)
{
csio_wr_reg32(hw, CIDXINC(0) |
INGRESSQID(iqid) |
TIMERREG(X_TIMERREG_RESTART_COUNTER),
MYPF_REG(SGE_PF_GTS));
}
static int
csio_wr_fill_fl(struct csio_hw *hw, struct csio_q *flq)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_sge *sge = &wrm->sge;
__be64 *d = (__be64 *)(flq->vstart);
struct csio_dma_buf *buf = &flq->un.fl.bufs[0];
uint64_t paddr;
int sreg = flq->un.fl.sreg;
int n = flq->credits;
while (n--) {
buf->len = sge->sge_fl_buf_size[sreg];
buf->vaddr = pci_alloc_consistent(hw->pdev, buf->len,
&buf->paddr);
if (!buf->vaddr) {
csio_err(hw, "Could only fill %d buffers!\n", n + 1);
return -ENOMEM;
}
paddr = buf->paddr | (sreg & 0xF);
*d++ = cpu_to_be64(paddr);
buf++;
}
return 0;
}
static inline void
csio_wr_update_fl(struct csio_hw *hw, struct csio_q *flq, uint16_t n)
{
flq->inc_idx += n;
flq->pidx += n;
if (unlikely(flq->pidx >= flq->credits))
flq->pidx -= (uint16_t)flq->credits;
CSIO_INC_STATS(flq, n_flq_refill);
}
int
csio_wr_alloc_q(struct csio_hw *hw, uint32_t qsize, uint32_t wrsize,
uint16_t type, void *owner, uint32_t nflb, int sreg,
iq_handler_t iq_intx_handler)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_q *q, *flq;
int free_idx = wrm->free_qidx;
int ret_idx = free_idx;
uint32_t qsz;
int flq_idx;
if (free_idx >= wrm->num_q) {
csio_err(hw, "No more free queues.\n");
return -1;
}
switch (type) {
case CSIO_EGRESS:
qsz = ALIGN(qsize, CSIO_QCREDIT_SZ) + csio_wr_qstat_pgsz(hw);
break;
case CSIO_INGRESS:
switch (wrsize) {
case 16:
case 32:
case 64:
case 128:
break;
default:
csio_err(hw, "Invalid Ingress queue WR size:%d\n",
wrsize);
return -1;
}
qsz = ALIGN(qsize/wrsize, 16) * wrsize;
break;
case CSIO_FREELIST:
qsz = ALIGN(qsize/wrsize, 8) * wrsize + csio_wr_qstat_pgsz(hw);
break;
default:
csio_err(hw, "Invalid queue type: 0x%x\n", type);
return -1;
}
q = wrm->q_arr[free_idx];
q->vstart = pci_alloc_consistent(hw->pdev, qsz, &q->pstart);
if (!q->vstart) {
csio_err(hw,
"Failed to allocate DMA memory for "
"queue at id: %d size: %d\n", free_idx, qsize);
return -1;
}
memset(q->vstart, 0, qsz);
q->type = type;
q->owner = owner;
q->pidx = q->cidx = q->inc_idx = 0;
q->size = qsz;
q->wr_sz = wrsize;
wrm->free_qidx++;
if (type == CSIO_INGRESS) {
q->un.iq.genbit = 1;
q->credits = (qsz - q->wr_sz) / q->wr_sz;
q->vwrap = (void *)((uintptr_t)(q->vstart) + qsz
- q->wr_sz);
if (nflb > 0) {
flq_idx = csio_wr_alloc_q(hw, nflb * sizeof(__be64),
sizeof(__be64), CSIO_FREELIST,
owner, 0, sreg, NULL);
if (flq_idx == -1) {
csio_err(hw,
"Failed to allocate FL queue"
" for IQ idx:%d\n", free_idx);
return -1;
}
q->un.iq.flq_idx = flq_idx;
flq = wrm->q_arr[q->un.iq.flq_idx];
flq->un.fl.bufs = kzalloc(flq->credits *
sizeof(struct csio_dma_buf),
GFP_KERNEL);
if (!flq->un.fl.bufs) {
csio_err(hw,
"Failed to allocate FL queue bufs"
" for IQ idx:%d\n", free_idx);
return -1;
}
flq->un.fl.packen = 0;
flq->un.fl.offset = 0;
flq->un.fl.sreg = sreg;
if (csio_wr_fill_fl(hw, flq))
return -1;
flq->pidx = flq->inc_idx = flq->credits - 8;
} else {
q->un.iq.flq_idx = -1;
}
q->un.iq.iq_intx_handler = iq_intx_handler;
csio_q_iqid(hw, ret_idx) = CSIO_MAX_QID;
} else if (type == CSIO_EGRESS) {
q->credits = (qsz - csio_wr_qstat_pgsz(hw)) / CSIO_QCREDIT_SZ;
q->vwrap = (void *)((uintptr_t)(q->vstart) + qsz
- csio_wr_qstat_pgsz(hw));
csio_q_eqid(hw, ret_idx) = CSIO_MAX_QID;
} else {
q->credits = (qsz - csio_wr_qstat_pgsz(hw)) / sizeof(__be64);
q->vwrap = (void *)((uintptr_t)(q->vstart) + qsz
- csio_wr_qstat_pgsz(hw));
csio_q_flid(hw, ret_idx) = CSIO_MAX_QID;
}
return ret_idx;
}
static int
csio_wr_iq_create_rsp(struct csio_hw *hw, struct csio_mb *mbp, int iq_idx)
{
struct csio_iq_params iqp;
enum fw_retval retval;
uint32_t iq_id;
int flq_idx;
memset(&iqp, 0, sizeof(struct csio_iq_params));
csio_mb_iq_alloc_write_rsp(hw, mbp, &retval, &iqp);
if (retval != FW_SUCCESS) {
csio_err(hw, "IQ cmd returned 0x%x!\n", retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
csio_q_iqid(hw, iq_idx) = iqp.iqid;
csio_q_physiqid(hw, iq_idx) = iqp.physiqid;
csio_q_pidx(hw, iq_idx) = csio_q_cidx(hw, iq_idx) = 0;
csio_q_inc_idx(hw, iq_idx) = 0;
iq_id = iqp.iqid - hw->wrm.fw_iq_start;
if (iq_id >= CSIO_MAX_IQ) {
csio_err(hw,
"Exceeding MAX_IQ(%d) supported!"
" iqid:%d rel_iqid:%d FW iq_start:%d\n",
CSIO_MAX_IQ, iq_id, iqp.iqid, hw->wrm.fw_iq_start);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
csio_q_set_intr_map(hw, iq_idx, iq_id);
csio_wr_sge_intr_enable(hw, iqp.physiqid);
flq_idx = csio_q_iq_flq_idx(hw, iq_idx);
if (flq_idx != -1) {
struct csio_q *flq = hw->wrm.q_arr[flq_idx];
csio_q_flid(hw, flq_idx) = iqp.fl0id;
csio_q_cidx(hw, flq_idx) = 0;
csio_q_pidx(hw, flq_idx) = csio_q_credits(hw, flq_idx) - 8;
csio_q_inc_idx(hw, flq_idx) = csio_q_credits(hw, flq_idx) - 8;
csio_wr_ring_fldb(hw, flq);
}
mempool_free(mbp, hw->mb_mempool);
return 0;
}
int
csio_wr_iq_create(struct csio_hw *hw, void *priv, int iq_idx,
uint32_t vec, uint8_t portid, bool async,
void (*cbfn) (struct csio_hw *, struct csio_mb *))
{
struct csio_mb *mbp;
struct csio_iq_params iqp;
int flq_idx;
memset(&iqp, 0, sizeof(struct csio_iq_params));
csio_q_portid(hw, iq_idx) = portid;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
csio_err(hw, "IQ command out of memory!\n");
return -ENOMEM;
}
switch (hw->intr_mode) {
case CSIO_IM_INTX:
case CSIO_IM_MSI:
if (hw->intr_iq_idx == iq_idx)
iqp.iqandst = X_INTERRUPTDESTINATION_PCIE;
else
iqp.iqandst = X_INTERRUPTDESTINATION_IQ;
iqp.iqandstindex =
csio_q_physiqid(hw, hw->intr_iq_idx);
break;
case CSIO_IM_MSIX:
iqp.iqandst = X_INTERRUPTDESTINATION_PCIE;
iqp.iqandstindex = (uint16_t)vec;
break;
case CSIO_IM_NONE:
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
iqp.pfn = hw->pfn;
iqp.vfn = 0;
iqp.iq_start = 1;
iqp.viid = 0;
iqp.type = FW_IQ_TYPE_FL_INT_CAP;
iqp.iqasynch = async;
if (csio_intr_coalesce_cnt)
iqp.iqanus = X_UPDATESCHEDULING_COUNTER_OPTTIMER;
else
iqp.iqanus = X_UPDATESCHEDULING_TIMER;
iqp.iqanud = X_UPDATEDELIVERY_INTERRUPT;
iqp.iqpciech = portid;
iqp.iqintcntthresh = (uint8_t)csio_sge_thresh_reg;
switch (csio_q_wr_sz(hw, iq_idx)) {
case 16:
iqp.iqesize = 0; break;
case 32:
iqp.iqesize = 1; break;
case 64:
iqp.iqesize = 2; break;
case 128:
iqp.iqesize = 3; break;
}
iqp.iqsize = csio_q_size(hw, iq_idx) /
csio_q_wr_sz(hw, iq_idx);
iqp.iqaddr = csio_q_pstart(hw, iq_idx);
flq_idx = csio_q_iq_flq_idx(hw, iq_idx);
if (flq_idx != -1) {
struct csio_q *flq = hw->wrm.q_arr[flq_idx];
iqp.fl0paden = 1;
iqp.fl0packen = flq->un.fl.packen ? 1 : 0;
iqp.fl0fbmin = X_FETCHBURSTMIN_64B;
iqp.fl0fbmax = X_FETCHBURSTMAX_512B;
iqp.fl0size = csio_q_size(hw, flq_idx) / CSIO_QCREDIT_SZ;
iqp.fl0addr = csio_q_pstart(hw, flq_idx);
}
csio_mb_iq_alloc_write(hw, mbp, priv, CSIO_MB_DEFAULT_TMO, &iqp, cbfn);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of IQ cmd failed!\n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
if (cbfn != NULL)
return 0;
return csio_wr_iq_create_rsp(hw, mbp, iq_idx);
}
static int
csio_wr_eq_cfg_rsp(struct csio_hw *hw, struct csio_mb *mbp, int eq_idx)
{
struct csio_eq_params eqp;
enum fw_retval retval;
memset(&eqp, 0, sizeof(struct csio_eq_params));
csio_mb_eq_ofld_alloc_write_rsp(hw, mbp, &retval, &eqp);
if (retval != FW_SUCCESS) {
csio_err(hw, "EQ OFLD cmd returned 0x%x!\n", retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
csio_q_eqid(hw, eq_idx) = (uint16_t)eqp.eqid;
csio_q_physeqid(hw, eq_idx) = (uint16_t)eqp.physeqid;
csio_q_pidx(hw, eq_idx) = csio_q_cidx(hw, eq_idx) = 0;
csio_q_inc_idx(hw, eq_idx) = 0;
mempool_free(mbp, hw->mb_mempool);
return 0;
}
int
csio_wr_eq_create(struct csio_hw *hw, void *priv, int eq_idx,
int iq_idx, uint8_t portid,
void (*cbfn) (struct csio_hw *, struct csio_mb *))
{
struct csio_mb *mbp;
struct csio_eq_params eqp;
memset(&eqp, 0, sizeof(struct csio_eq_params));
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
csio_err(hw, "EQ command out of memory!\n");
return -ENOMEM;
}
eqp.pfn = hw->pfn;
eqp.vfn = 0;
eqp.eqstart = 1;
eqp.hostfcmode = X_HOSTFCMODE_STATUS_PAGE;
eqp.iqid = csio_q_iqid(hw, iq_idx);
eqp.fbmin = X_FETCHBURSTMIN_64B;
eqp.fbmax = X_FETCHBURSTMAX_512B;
eqp.cidxfthresh = 0;
eqp.pciechn = portid;
eqp.eqsize = csio_q_size(hw, eq_idx) / CSIO_QCREDIT_SZ;
eqp.eqaddr = csio_q_pstart(hw, eq_idx);
csio_mb_eq_ofld_alloc_write(hw, mbp, priv, CSIO_MB_DEFAULT_TMO,
&eqp, cbfn);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of EQ OFLD cmd failed!\n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
if (cbfn != NULL)
return 0;
return csio_wr_eq_cfg_rsp(hw, mbp, eq_idx);
}
static int
csio_wr_iq_destroy_rsp(struct csio_hw *hw, struct csio_mb *mbp, int iq_idx)
{
enum fw_retval retval = csio_mb_fw_retval(mbp);
int rv = 0;
if (retval != FW_SUCCESS)
rv = -EINVAL;
mempool_free(mbp, hw->mb_mempool);
return rv;
}
static int
csio_wr_iq_destroy(struct csio_hw *hw, void *priv, int iq_idx,
void (*cbfn)(struct csio_hw *, struct csio_mb *))
{
int rv = 0;
struct csio_mb *mbp;
struct csio_iq_params iqp;
int flq_idx;
memset(&iqp, 0, sizeof(struct csio_iq_params));
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp)
return -ENOMEM;
iqp.pfn = hw->pfn;
iqp.vfn = 0;
iqp.iqid = csio_q_iqid(hw, iq_idx);
iqp.type = FW_IQ_TYPE_FL_INT_CAP;
flq_idx = csio_q_iq_flq_idx(hw, iq_idx);
if (flq_idx != -1)
iqp.fl0id = csio_q_flid(hw, flq_idx);
else
iqp.fl0id = 0xFFFF;
iqp.fl1id = 0xFFFF;
csio_mb_iq_free(hw, mbp, priv, CSIO_MB_DEFAULT_TMO, &iqp, cbfn);
rv = csio_mb_issue(hw, mbp);
if (rv != 0) {
mempool_free(mbp, hw->mb_mempool);
return rv;
}
if (cbfn != NULL)
return 0;
return csio_wr_iq_destroy_rsp(hw, mbp, iq_idx);
}
static int
csio_wr_eq_destroy_rsp(struct csio_hw *hw, struct csio_mb *mbp, int eq_idx)
{
enum fw_retval retval = csio_mb_fw_retval(mbp);
int rv = 0;
if (retval != FW_SUCCESS)
rv = -EINVAL;
mempool_free(mbp, hw->mb_mempool);
return rv;
}
static int
csio_wr_eq_destroy(struct csio_hw *hw, void *priv, int eq_idx,
void (*cbfn) (struct csio_hw *, struct csio_mb *))
{
int rv = 0;
struct csio_mb *mbp;
struct csio_eq_params eqp;
memset(&eqp, 0, sizeof(struct csio_eq_params));
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp)
return -ENOMEM;
eqp.pfn = hw->pfn;
eqp.vfn = 0;
eqp.eqid = csio_q_eqid(hw, eq_idx);
csio_mb_eq_ofld_free(hw, mbp, priv, CSIO_MB_DEFAULT_TMO, &eqp, cbfn);
rv = csio_mb_issue(hw, mbp);
if (rv != 0) {
mempool_free(mbp, hw->mb_mempool);
return rv;
}
if (cbfn != NULL)
return 0;
return csio_wr_eq_destroy_rsp(hw, mbp, eq_idx);
}
static void
csio_wr_cleanup_eq_stpg(struct csio_hw *hw, int qidx)
{
struct csio_q *q = csio_hw_to_wrm(hw)->q_arr[qidx];
struct csio_qstatus_page *stp = (struct csio_qstatus_page *)q->vwrap;
memset(stp, 0, sizeof(*stp));
}
static void
csio_wr_cleanup_iq_ftr(struct csio_hw *hw, int qidx)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_q *q = wrm->q_arr[qidx];
void *wr;
struct csio_iqwr_footer *ftr;
uint32_t i = 0;
q->un.iq.genbit = 1;
for (i = 0; i < q->credits; i++) {
wr = (void *)((uintptr_t)q->vstart +
(i * q->wr_sz));
ftr = (struct csio_iqwr_footer *)((uintptr_t)wr +
(q->wr_sz - sizeof(*ftr)));
memset(ftr, 0, sizeof(*ftr));
}
}
int
csio_wr_destroy_queues(struct csio_hw *hw, bool cmd)
{
int i, flq_idx;
struct csio_q *q;
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
int rv;
for (i = 0; i < wrm->free_qidx; i++) {
q = wrm->q_arr[i];
switch (q->type) {
case CSIO_EGRESS:
if (csio_q_eqid(hw, i) != CSIO_MAX_QID) {
csio_wr_cleanup_eq_stpg(hw, i);
if (!cmd) {
csio_q_eqid(hw, i) = CSIO_MAX_QID;
continue;
}
rv = csio_wr_eq_destroy(hw, NULL, i, NULL);
if ((rv == -EBUSY) || (rv == -ETIMEDOUT))
cmd = false;
csio_q_eqid(hw, i) = CSIO_MAX_QID;
}
case CSIO_INGRESS:
if (csio_q_iqid(hw, i) != CSIO_MAX_QID) {
csio_wr_cleanup_iq_ftr(hw, i);
if (!cmd) {
csio_q_iqid(hw, i) = CSIO_MAX_QID;
flq_idx = csio_q_iq_flq_idx(hw, i);
if (flq_idx != -1)
csio_q_flid(hw, flq_idx) =
CSIO_MAX_QID;
continue;
}
rv = csio_wr_iq_destroy(hw, NULL, i, NULL);
if ((rv == -EBUSY) || (rv == -ETIMEDOUT))
cmd = false;
csio_q_iqid(hw, i) = CSIO_MAX_QID;
flq_idx = csio_q_iq_flq_idx(hw, i);
if (flq_idx != -1)
csio_q_flid(hw, flq_idx) = CSIO_MAX_QID;
}
default:
break;
}
}
hw->flags &= ~CSIO_HWF_Q_FW_ALLOCED;
return 0;
}
int
csio_wr_get(struct csio_hw *hw, int qidx, uint32_t size,
struct csio_wr_pair *wrp)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_q *q = wrm->q_arr[qidx];
void *cwr = (void *)((uintptr_t)(q->vstart) +
(q->pidx * CSIO_QCREDIT_SZ));
struct csio_qstatus_page *stp = (struct csio_qstatus_page *)q->vwrap;
uint16_t cidx = q->cidx = ntohs(stp->cidx);
uint16_t pidx = q->pidx;
uint32_t req_sz = ALIGN(size, CSIO_QCREDIT_SZ);
int req_credits = req_sz / CSIO_QCREDIT_SZ;
int credits;
CSIO_DB_ASSERT(q->owner != NULL);
CSIO_DB_ASSERT((qidx >= 0) && (qidx < wrm->free_qidx));
CSIO_DB_ASSERT(cidx <= q->credits);
if (pidx > cidx) {
credits = q->credits - (pidx - cidx) - 1;
} else if (cidx > pidx) {
credits = cidx - pidx - 1;
} else {
credits = q->credits;
CSIO_INC_STATS(q, n_qempty);
}
if (!credits || (req_credits > credits)) {
CSIO_INC_STATS(q, n_qfull);
return -EBUSY;
}
if (unlikely(((uintptr_t)cwr + req_sz) > (uintptr_t)(q->vwrap))) {
wrp->addr1 = cwr;
wrp->size1 = (uint32_t)((uintptr_t)q->vwrap - (uintptr_t)cwr);
wrp->addr2 = q->vstart;
wrp->size2 = req_sz - wrp->size1;
q->pidx = (uint16_t)(ALIGN(wrp->size2, CSIO_QCREDIT_SZ) /
CSIO_QCREDIT_SZ);
CSIO_INC_STATS(q, n_qwrap);
CSIO_INC_STATS(q, n_eq_wr_split);
} else {
wrp->addr1 = cwr;
wrp->size1 = req_sz;
wrp->addr2 = NULL;
wrp->size2 = 0;
q->pidx += (uint16_t)req_credits;
if (unlikely(q->pidx == q->credits)) {
q->pidx = 0;
CSIO_INC_STATS(q, n_qwrap);
}
}
q->inc_idx = (uint16_t)req_credits;
CSIO_INC_STATS(q, n_tot_reqs);
return 0;
}
void
csio_wr_copy_to_wrp(void *data_buf, struct csio_wr_pair *wrp,
uint32_t wr_off, uint32_t data_len)
{
uint32_t nbytes;
nbytes = ((wrp->size1 - wr_off) >= data_len) ?
data_len : (wrp->size1 - wr_off);
memcpy((uint8_t *) wrp->addr1 + wr_off, data_buf, nbytes);
data_len -= nbytes;
if (data_len) {
CSIO_DB_ASSERT(data_len <= wrp->size2);
CSIO_DB_ASSERT(wrp->addr2 != NULL);
memcpy(wrp->addr2, (uint8_t *) data_buf + nbytes, data_len);
}
}
int
csio_wr_issue(struct csio_hw *hw, int qidx, bool prio)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_q *q = wrm->q_arr[qidx];
CSIO_DB_ASSERT((qidx >= 0) && (qidx < wrm->free_qidx));
wmb();
csio_wr_reg32(hw, DBPRIO(prio) | QID(q->un.eq.physeqid) |
PIDX(q->inc_idx), MYPF_REG(SGE_PF_KDOORBELL));
q->inc_idx = 0;
return 0;
}
static inline uint32_t
csio_wr_avail_qcredits(struct csio_q *q)
{
if (q->pidx > q->cidx)
return q->pidx - q->cidx;
else if (q->cidx > q->pidx)
return q->credits - (q->cidx - q->pidx);
else
return 0;
}
static inline void
csio_wr_inval_flq_buf(struct csio_hw *hw, struct csio_q *flq)
{
flq->cidx++;
if (flq->cidx == flq->credits) {
flq->cidx = 0;
CSIO_INC_STATS(flq, n_qwrap);
}
}
static inline void
csio_wr_process_fl(struct csio_hw *hw, struct csio_q *q,
void *wr, uint32_t len_to_qid,
void (*iq_handler)(struct csio_hw *, void *,
uint32_t, struct csio_fl_dma_buf *,
void *),
void *priv)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_sge *sge = &wrm->sge;
struct csio_fl_dma_buf flb;
struct csio_dma_buf *buf, *fbuf;
uint32_t bufsz, len, lastlen = 0;
int n;
struct csio_q *flq = hw->wrm.q_arr[q->un.iq.flq_idx];
CSIO_DB_ASSERT(flq != NULL);
len = len_to_qid;
if (len & IQWRF_NEWBUF) {
if (flq->un.fl.offset > 0) {
csio_wr_inval_flq_buf(hw, flq);
flq->un.fl.offset = 0;
}
len = IQWRF_LEN_GET(len);
}
CSIO_DB_ASSERT(len != 0);
flb.totlen = len;
for (n = 0, fbuf = flb.flbufs; ; n++, fbuf++) {
buf = &flq->un.fl.bufs[flq->cidx];
bufsz = csio_wr_fl_bufsz(sge, buf);
fbuf->paddr = buf->paddr;
fbuf->vaddr = buf->vaddr;
flb.offset = flq->un.fl.offset;
lastlen = min(bufsz, len);
fbuf->len = lastlen;
len -= lastlen;
if (!len)
break;
csio_wr_inval_flq_buf(hw, flq);
}
flb.defer_free = flq->un.fl.packen ? 0 : 1;
iq_handler(hw, wr, q->wr_sz - sizeof(struct csio_iqwr_footer),
&flb, priv);
if (flq->un.fl.packen)
flq->un.fl.offset += ALIGN(lastlen, sge->csio_fl_align);
else
csio_wr_inval_flq_buf(hw, flq);
}
static inline bool
csio_is_new_iqwr(struct csio_q *q, struct csio_iqwr_footer *ftr)
{
return (q->un.iq.genbit == (ftr->u.type_gen >> IQWRF_GEN_SHIFT));
}
int
csio_wr_process_iq(struct csio_hw *hw, struct csio_q *q,
void (*iq_handler)(struct csio_hw *, void *,
uint32_t, struct csio_fl_dma_buf *,
void *),
void *priv)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
void *wr = (void *)((uintptr_t)q->vstart + (q->cidx * q->wr_sz));
struct csio_iqwr_footer *ftr;
uint32_t wr_type, fw_qid, qid;
struct csio_q *q_completed;
struct csio_q *flq = csio_iq_has_fl(q) ?
wrm->q_arr[q->un.iq.flq_idx] : NULL;
int rv = 0;
ftr = (struct csio_iqwr_footer *)((uintptr_t)wr +
(q->wr_sz - sizeof(*ftr)));
while (csio_is_new_iqwr(q, ftr)) {
CSIO_DB_ASSERT(((uintptr_t)wr + q->wr_sz) <=
(uintptr_t)q->vwrap);
rmb();
wr_type = IQWRF_TYPE_GET(ftr->u.type_gen);
switch (wr_type) {
case X_RSPD_TYPE_CPL:
iq_handler(hw, wr, q->wr_sz - sizeof(*ftr), NULL, priv);
break;
case X_RSPD_TYPE_FLBUF:
csio_wr_process_fl(hw, q, wr,
ntohl(ftr->pldbuflen_qid),
iq_handler, priv);
break;
case X_RSPD_TYPE_INTR:
fw_qid = ntohl(ftr->pldbuflen_qid);
qid = fw_qid - wrm->fw_iq_start;
q_completed = hw->wrm.intr_map[qid];
if (unlikely(qid ==
csio_q_physiqid(hw, hw->intr_iq_idx))) {
} else {
CSIO_DB_ASSERT(q_completed);
CSIO_DB_ASSERT(
q_completed->un.iq.iq_intx_handler);
q_completed->un.iq.iq_intx_handler(hw, NULL,
0, NULL, (void *)q_completed);
}
break;
default:
csio_warn(hw, "Unknown resp type 0x%x received\n",
wr_type);
CSIO_INC_STATS(q, n_rsp_unknown);
break;
}
if (((uintptr_t)wr + q->wr_sz) == (uintptr_t)q->vwrap) {
q->cidx = 0;
wr = q->vstart;
q->un.iq.genbit ^= 0x1;
CSIO_INC_STATS(q, n_qwrap);
} else {
q->cidx++;
wr = (void *)((uintptr_t)(q->vstart) +
(q->cidx * q->wr_sz));
}
ftr = (struct csio_iqwr_footer *)((uintptr_t)wr +
(q->wr_sz - sizeof(*ftr)));
q->inc_idx++;
}
if (unlikely(!q->inc_idx)) {
CSIO_INC_STATS(q, n_stray_comp);
rv = -EINVAL;
goto restart;
}
if (flq) {
uint32_t avail = csio_wr_avail_qcredits(flq);
if (avail <= 16) {
csio_wr_update_fl(hw, flq, (flq->credits - 8) - avail);
csio_wr_ring_fldb(hw, flq);
}
}
restart:
csio_wr_reg32(hw, CIDXINC(q->inc_idx) |
INGRESSQID(q->un.iq.physiqid) |
TIMERREG(csio_sge_timer_reg),
MYPF_REG(SGE_PF_GTS));
q->stats.n_tot_rsps += q->inc_idx;
q->inc_idx = 0;
return rv;
}
int
csio_wr_process_iq_idx(struct csio_hw *hw, int qidx,
void (*iq_handler)(struct csio_hw *, void *,
uint32_t, struct csio_fl_dma_buf *,
void *),
void *priv)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_q *iq = wrm->q_arr[qidx];
return csio_wr_process_iq(hw, iq, iq_handler, priv);
}
static int
csio_closest_timer(struct csio_sge *s, int time)
{
int i, delta, match = 0, min_delta = INT_MAX;
for (i = 0; i < ARRAY_SIZE(s->timer_val); i++) {
delta = time - s->timer_val[i];
if (delta < 0)
delta = -delta;
if (delta < min_delta) {
min_delta = delta;
match = i;
}
}
return match;
}
static int
csio_closest_thresh(struct csio_sge *s, int cnt)
{
int i, delta, match = 0, min_delta = INT_MAX;
for (i = 0; i < ARRAY_SIZE(s->counter_val); i++) {
delta = cnt - s->counter_val[i];
if (delta < 0)
delta = -delta;
if (delta < min_delta) {
min_delta = delta;
match = i;
}
}
return match;
}
static void
csio_wr_fixup_host_params(struct csio_hw *hw)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_sge *sge = &wrm->sge;
uint32_t clsz = L1_CACHE_BYTES;
uint32_t s_hps = PAGE_SHIFT - 10;
uint32_t ingpad = 0;
uint32_t stat_len = clsz > 64 ? 128 : 64;
csio_wr_reg32(hw, HOSTPAGESIZEPF0(s_hps) | HOSTPAGESIZEPF1(s_hps) |
HOSTPAGESIZEPF2(s_hps) | HOSTPAGESIZEPF3(s_hps) |
HOSTPAGESIZEPF4(s_hps) | HOSTPAGESIZEPF5(s_hps) |
HOSTPAGESIZEPF6(s_hps) | HOSTPAGESIZEPF7(s_hps),
SGE_HOST_PAGE_SIZE);
sge->csio_fl_align = clsz < 32 ? 32 : clsz;
ingpad = ilog2(sge->csio_fl_align) - 5;
csio_set_reg_field(hw, SGE_CONTROL, INGPADBOUNDARY_MASK |
EGRSTATUSPAGESIZE(1),
INGPADBOUNDARY(ingpad) |
EGRSTATUSPAGESIZE(stat_len != 64));
csio_wr_reg32(hw, PAGE_SIZE, SGE_FL_BUFFER_SIZE0);
csio_wr_reg32(hw,
(csio_rd_reg32(hw, SGE_FL_BUFFER_SIZE2) +
sge->csio_fl_align - 1) & ~(sge->csio_fl_align - 1),
SGE_FL_BUFFER_SIZE2);
csio_wr_reg32(hw,
(csio_rd_reg32(hw, SGE_FL_BUFFER_SIZE3) +
sge->csio_fl_align - 1) & ~(sge->csio_fl_align - 1),
SGE_FL_BUFFER_SIZE3);
csio_wr_reg32(hw, HPZ0(PAGE_SHIFT - 12), ULP_RX_TDDP_PSZ);
csio_set_reg_field(hw, SGE_CONTROL, PKTSHIFT_MASK,
PKTSHIFT(CSIO_SGE_RX_DMA_OFFSET));
}
static void
csio_init_intr_coalesce_parms(struct csio_hw *hw)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_sge *sge = &wrm->sge;
csio_sge_thresh_reg = csio_closest_thresh(sge, csio_intr_coalesce_cnt);
if (csio_intr_coalesce_cnt) {
csio_sge_thresh_reg = 0;
csio_sge_timer_reg = X_TIMERREG_RESTART_COUNTER;
return;
}
csio_sge_timer_reg = csio_closest_timer(sge, csio_intr_coalesce_time);
}
static void
csio_wr_get_sge(struct csio_hw *hw)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_sge *sge = &wrm->sge;
uint32_t ingpad;
int i;
u32 timer_value_0_and_1, timer_value_2_and_3, timer_value_4_and_5;
u32 ingress_rx_threshold;
sge->sge_control = csio_rd_reg32(hw, SGE_CONTROL);
ingpad = INGPADBOUNDARY_GET(sge->sge_control);
switch (ingpad) {
case X_INGPCIEBOUNDARY_32B:
sge->csio_fl_align = 32; break;
case X_INGPCIEBOUNDARY_64B:
sge->csio_fl_align = 64; break;
case X_INGPCIEBOUNDARY_128B:
sge->csio_fl_align = 128; break;
case X_INGPCIEBOUNDARY_256B:
sge->csio_fl_align = 256; break;
case X_INGPCIEBOUNDARY_512B:
sge->csio_fl_align = 512; break;
case X_INGPCIEBOUNDARY_1024B:
sge->csio_fl_align = 1024; break;
case X_INGPCIEBOUNDARY_2048B:
sge->csio_fl_align = 2048; break;
case X_INGPCIEBOUNDARY_4096B:
sge->csio_fl_align = 4096; break;
}
for (i = 0; i < CSIO_SGE_FL_SIZE_REGS; i++)
csio_get_flbuf_size(hw, sge, i);
timer_value_0_and_1 = csio_rd_reg32(hw, SGE_TIMER_VALUE_0_AND_1);
timer_value_2_and_3 = csio_rd_reg32(hw, SGE_TIMER_VALUE_2_AND_3);
timer_value_4_and_5 = csio_rd_reg32(hw, SGE_TIMER_VALUE_4_AND_5);
sge->timer_val[0] = (uint16_t)csio_core_ticks_to_us(hw,
TIMERVALUE0_GET(timer_value_0_and_1));
sge->timer_val[1] = (uint16_t)csio_core_ticks_to_us(hw,
TIMERVALUE1_GET(timer_value_0_and_1));
sge->timer_val[2] = (uint16_t)csio_core_ticks_to_us(hw,
TIMERVALUE2_GET(timer_value_2_and_3));
sge->timer_val[3] = (uint16_t)csio_core_ticks_to_us(hw,
TIMERVALUE3_GET(timer_value_2_and_3));
sge->timer_val[4] = (uint16_t)csio_core_ticks_to_us(hw,
TIMERVALUE4_GET(timer_value_4_and_5));
sge->timer_val[5] = (uint16_t)csio_core_ticks_to_us(hw,
TIMERVALUE5_GET(timer_value_4_and_5));
ingress_rx_threshold = csio_rd_reg32(hw, SGE_INGRESS_RX_THRESHOLD);
sge->counter_val[0] = THRESHOLD_0_GET(ingress_rx_threshold);
sge->counter_val[1] = THRESHOLD_1_GET(ingress_rx_threshold);
sge->counter_val[2] = THRESHOLD_2_GET(ingress_rx_threshold);
sge->counter_val[3] = THRESHOLD_3_GET(ingress_rx_threshold);
csio_init_intr_coalesce_parms(hw);
}
static void
csio_wr_set_sge(struct csio_hw *hw)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_sge *sge = &wrm->sge;
int i;
csio_set_reg_field(hw, SGE_CONTROL, RXPKTCPLMODE(1), RXPKTCPLMODE(1));
sge->sge_control = csio_rd_reg32(hw, SGE_CONTROL);
csio_set_reg_field(hw, SGE_DBFIFO_STATUS,
HP_INT_THRESH(HP_INT_THRESH_MASK) |
LP_INT_THRESH(LP_INT_THRESH_MASK),
HP_INT_THRESH(CSIO_SGE_DBFIFO_INT_THRESH) |
LP_INT_THRESH(CSIO_SGE_DBFIFO_INT_THRESH));
csio_set_reg_field(hw, SGE_DOORBELL_CONTROL, ENABLE_DROP,
ENABLE_DROP);
CSIO_SET_FLBUF_SIZE(hw, 1, CSIO_SGE_FLBUF_SIZE1);
CSIO_SET_FLBUF_SIZE(hw, 2, CSIO_SGE_FLBUF_SIZE2);
CSIO_SET_FLBUF_SIZE(hw, 3, CSIO_SGE_FLBUF_SIZE3);
CSIO_SET_FLBUF_SIZE(hw, 4, CSIO_SGE_FLBUF_SIZE4);
CSIO_SET_FLBUF_SIZE(hw, 5, CSIO_SGE_FLBUF_SIZE5);
CSIO_SET_FLBUF_SIZE(hw, 6, CSIO_SGE_FLBUF_SIZE6);
CSIO_SET_FLBUF_SIZE(hw, 7, CSIO_SGE_FLBUF_SIZE7);
CSIO_SET_FLBUF_SIZE(hw, 8, CSIO_SGE_FLBUF_SIZE8);
for (i = 0; i < CSIO_SGE_FL_SIZE_REGS; i++)
csio_get_flbuf_size(hw, sge, i);
sge->timer_val[0] = CSIO_SGE_TIMER_VAL_0;
sge->timer_val[1] = CSIO_SGE_TIMER_VAL_1;
sge->timer_val[2] = CSIO_SGE_TIMER_VAL_2;
sge->timer_val[3] = CSIO_SGE_TIMER_VAL_3;
sge->timer_val[4] = CSIO_SGE_TIMER_VAL_4;
sge->timer_val[5] = CSIO_SGE_TIMER_VAL_5;
sge->counter_val[0] = CSIO_SGE_INT_CNT_VAL_0;
sge->counter_val[1] = CSIO_SGE_INT_CNT_VAL_1;
sge->counter_val[2] = CSIO_SGE_INT_CNT_VAL_2;
sge->counter_val[3] = CSIO_SGE_INT_CNT_VAL_3;
csio_wr_reg32(hw, THRESHOLD_0(sge->counter_val[0]) |
THRESHOLD_1(sge->counter_val[1]) |
THRESHOLD_2(sge->counter_val[2]) |
THRESHOLD_3(sge->counter_val[3]),
SGE_INGRESS_RX_THRESHOLD);
csio_wr_reg32(hw,
TIMERVALUE0(csio_us_to_core_ticks(hw, sge->timer_val[0])) |
TIMERVALUE1(csio_us_to_core_ticks(hw, sge->timer_val[1])),
SGE_TIMER_VALUE_0_AND_1);
csio_wr_reg32(hw,
TIMERVALUE2(csio_us_to_core_ticks(hw, sge->timer_val[2])) |
TIMERVALUE3(csio_us_to_core_ticks(hw, sge->timer_val[3])),
SGE_TIMER_VALUE_2_AND_3);
csio_wr_reg32(hw,
TIMERVALUE4(csio_us_to_core_ticks(hw, sge->timer_val[4])) |
TIMERVALUE5(csio_us_to_core_ticks(hw, sge->timer_val[5])),
SGE_TIMER_VALUE_4_AND_5);
csio_init_intr_coalesce_parms(hw);
}
void
csio_wr_sge_init(struct csio_hw *hw)
{
if (csio_is_hw_master(hw)) {
csio_wr_fixup_host_params(hw);
if (hw->flags & CSIO_HWF_USING_SOFT_PARAMS)
csio_wr_get_sge(hw);
else
csio_wr_set_sge(hw);
} else
csio_wr_get_sge(hw);
}
int
csio_wrm_init(struct csio_wrm *wrm, struct csio_hw *hw)
{
int i;
if (!wrm->num_q) {
csio_err(hw, "Num queues is not set\n");
return -EINVAL;
}
wrm->q_arr = kzalloc(sizeof(struct csio_q *) * wrm->num_q, GFP_KERNEL);
if (!wrm->q_arr)
goto err;
for (i = 0; i < wrm->num_q; i++) {
wrm->q_arr[i] = kzalloc(sizeof(struct csio_q), GFP_KERNEL);
if (!wrm->q_arr[i]) {
while (--i >= 0)
kfree(wrm->q_arr[i]);
goto err_free_arr;
}
}
wrm->free_qidx = 0;
return 0;
err_free_arr:
kfree(wrm->q_arr);
err:
return -ENOMEM;
}
void
csio_wrm_exit(struct csio_wrm *wrm, struct csio_hw *hw)
{
int i;
uint32_t j;
struct csio_q *q;
struct csio_dma_buf *buf;
for (i = 0; i < wrm->num_q; i++) {
q = wrm->q_arr[i];
if (wrm->free_qidx && (i < wrm->free_qidx)) {
if (q->type == CSIO_FREELIST) {
if (!q->un.fl.bufs)
continue;
for (j = 0; j < q->credits; j++) {
buf = &q->un.fl.bufs[j];
if (!buf->vaddr)
continue;
pci_free_consistent(hw->pdev, buf->len,
buf->vaddr,
buf->paddr);
}
kfree(q->un.fl.bufs);
}
pci_free_consistent(hw->pdev, q->size,
q->vstart, q->pstart);
}
kfree(q);
}
hw->flags &= ~CSIO_HWF_Q_MEM_ALLOCED;
kfree(wrm->q_arr);
}
