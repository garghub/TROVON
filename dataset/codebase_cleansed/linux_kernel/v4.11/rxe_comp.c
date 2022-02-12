static inline unsigned long rnrnak_jiffies(u8 timeout)
{
return max_t(unsigned long,
usecs_to_jiffies(rnrnak_usec[timeout]), 1);
}
static enum ib_wc_opcode wr_to_wc_opcode(enum ib_wr_opcode opcode)
{
switch (opcode) {
case IB_WR_RDMA_WRITE: return IB_WC_RDMA_WRITE;
case IB_WR_RDMA_WRITE_WITH_IMM: return IB_WC_RDMA_WRITE;
case IB_WR_SEND: return IB_WC_SEND;
case IB_WR_SEND_WITH_IMM: return IB_WC_SEND;
case IB_WR_RDMA_READ: return IB_WC_RDMA_READ;
case IB_WR_ATOMIC_CMP_AND_SWP: return IB_WC_COMP_SWAP;
case IB_WR_ATOMIC_FETCH_AND_ADD: return IB_WC_FETCH_ADD;
case IB_WR_LSO: return IB_WC_LSO;
case IB_WR_SEND_WITH_INV: return IB_WC_SEND;
case IB_WR_RDMA_READ_WITH_INV: return IB_WC_RDMA_READ;
case IB_WR_LOCAL_INV: return IB_WC_LOCAL_INV;
case IB_WR_REG_MR: return IB_WC_REG_MR;
default:
return 0xff;
}
}
void retransmit_timer(unsigned long data)
{
struct rxe_qp *qp = (struct rxe_qp *)data;
if (qp->valid) {
qp->comp.timeout = 1;
rxe_run_task(&qp->comp.task, 1);
}
}
void rxe_comp_queue_pkt(struct rxe_dev *rxe, struct rxe_qp *qp,
struct sk_buff *skb)
{
int must_sched;
skb_queue_tail(&qp->resp_pkts, skb);
must_sched = skb_queue_len(&qp->resp_pkts) > 1;
rxe_run_task(&qp->comp.task, must_sched);
}
static inline enum comp_state get_wqe(struct rxe_qp *qp,
struct rxe_pkt_info *pkt,
struct rxe_send_wqe **wqe_p)
{
struct rxe_send_wqe *wqe;
wqe = queue_head(qp->sq.queue);
*wqe_p = wqe;
if (!wqe || wqe->state == wqe_state_posted)
return pkt ? COMPST_DONE : COMPST_EXIT;
if (wqe->state == wqe_state_done)
return COMPST_COMP_WQE;
if (wqe->state == wqe_state_error)
return COMPST_ERROR;
return pkt ? COMPST_CHECK_PSN : COMPST_EXIT;
}
static inline void reset_retry_counters(struct rxe_qp *qp)
{
qp->comp.retry_cnt = qp->attr.retry_cnt;
qp->comp.rnr_retry = qp->attr.rnr_retry;
}
static inline enum comp_state check_psn(struct rxe_qp *qp,
struct rxe_pkt_info *pkt,
struct rxe_send_wqe *wqe)
{
s32 diff;
diff = psn_compare(pkt->psn, wqe->last_psn);
if (diff > 0) {
if (wqe->state == wqe_state_pending) {
if (wqe->mask & WR_ATOMIC_OR_READ_MASK)
return COMPST_ERROR_RETRY;
reset_retry_counters(qp);
return COMPST_COMP_WQE;
} else {
return COMPST_DONE;
}
}
diff = psn_compare(pkt->psn, qp->comp.psn);
if (diff < 0) {
if (pkt->psn == wqe->last_psn)
return COMPST_COMP_ACK;
else
return COMPST_DONE;
} else if ((diff > 0) && (wqe->mask & WR_ATOMIC_OR_READ_MASK)) {
return COMPST_DONE;
} else {
return COMPST_CHECK_ACK;
}
}
static inline enum comp_state check_ack(struct rxe_qp *qp,
struct rxe_pkt_info *pkt,
struct rxe_send_wqe *wqe)
{
unsigned int mask = pkt->mask;
u8 syn;
switch (qp->comp.opcode) {
case -1:
if (!(mask & RXE_START_MASK))
return COMPST_ERROR;
break;
case IB_OPCODE_RC_RDMA_READ_RESPONSE_FIRST:
case IB_OPCODE_RC_RDMA_READ_RESPONSE_MIDDLE:
if (pkt->opcode != IB_OPCODE_RC_RDMA_READ_RESPONSE_MIDDLE &&
pkt->opcode != IB_OPCODE_RC_RDMA_READ_RESPONSE_LAST) {
return COMPST_ERROR;
}
break;
default:
WARN_ON_ONCE(1);
}
switch (pkt->opcode) {
case IB_OPCODE_RC_RDMA_READ_RESPONSE_FIRST:
case IB_OPCODE_RC_RDMA_READ_RESPONSE_LAST:
case IB_OPCODE_RC_RDMA_READ_RESPONSE_ONLY:
syn = aeth_syn(pkt);
if ((syn & AETH_TYPE_MASK) != AETH_ACK)
return COMPST_ERROR;
case IB_OPCODE_RC_RDMA_READ_RESPONSE_MIDDLE:
if (wqe->wr.opcode != IB_WR_RDMA_READ &&
wqe->wr.opcode != IB_WR_RDMA_READ_WITH_INV) {
return COMPST_ERROR;
}
reset_retry_counters(qp);
return COMPST_READ;
case IB_OPCODE_RC_ATOMIC_ACKNOWLEDGE:
syn = aeth_syn(pkt);
if ((syn & AETH_TYPE_MASK) != AETH_ACK)
return COMPST_ERROR;
if (wqe->wr.opcode != IB_WR_ATOMIC_CMP_AND_SWP &&
wqe->wr.opcode != IB_WR_ATOMIC_FETCH_AND_ADD)
return COMPST_ERROR;
reset_retry_counters(qp);
return COMPST_ATOMIC;
case IB_OPCODE_RC_ACKNOWLEDGE:
syn = aeth_syn(pkt);
switch (syn & AETH_TYPE_MASK) {
case AETH_ACK:
reset_retry_counters(qp);
return COMPST_WRITE_SEND;
case AETH_RNR_NAK:
return COMPST_RNR_RETRY;
case AETH_NAK:
switch (syn) {
case AETH_NAK_PSN_SEQ_ERROR:
if (psn_compare(pkt->psn, qp->comp.psn) > 0) {
qp->comp.psn = pkt->psn;
if (qp->req.wait_psn) {
qp->req.wait_psn = 0;
rxe_run_task(&qp->req.task, 1);
}
}
return COMPST_ERROR_RETRY;
case AETH_NAK_INVALID_REQ:
wqe->status = IB_WC_REM_INV_REQ_ERR;
return COMPST_ERROR;
case AETH_NAK_REM_ACC_ERR:
wqe->status = IB_WC_REM_ACCESS_ERR;
return COMPST_ERROR;
case AETH_NAK_REM_OP_ERR:
wqe->status = IB_WC_REM_OP_ERR;
return COMPST_ERROR;
default:
pr_warn("unexpected nak %x\n", syn);
wqe->status = IB_WC_REM_OP_ERR;
return COMPST_ERROR;
}
default:
return COMPST_ERROR;
}
break;
default:
pr_warn("unexpected opcode\n");
}
return COMPST_ERROR;
}
static inline enum comp_state do_read(struct rxe_qp *qp,
struct rxe_pkt_info *pkt,
struct rxe_send_wqe *wqe)
{
struct rxe_dev *rxe = to_rdev(qp->ibqp.device);
int ret;
ret = copy_data(rxe, qp->pd, IB_ACCESS_LOCAL_WRITE,
&wqe->dma, payload_addr(pkt),
payload_size(pkt), to_mem_obj, NULL);
if (ret)
return COMPST_ERROR;
if (wqe->dma.resid == 0 && (pkt->mask & RXE_END_MASK))
return COMPST_COMP_ACK;
else
return COMPST_UPDATE_COMP;
}
static inline enum comp_state do_atomic(struct rxe_qp *qp,
struct rxe_pkt_info *pkt,
struct rxe_send_wqe *wqe)
{
struct rxe_dev *rxe = to_rdev(qp->ibqp.device);
int ret;
u64 atomic_orig = atmack_orig(pkt);
ret = copy_data(rxe, qp->pd, IB_ACCESS_LOCAL_WRITE,
&wqe->dma, &atomic_orig,
sizeof(u64), to_mem_obj, NULL);
if (ret)
return COMPST_ERROR;
else
return COMPST_COMP_ACK;
}
static void make_send_cqe(struct rxe_qp *qp, struct rxe_send_wqe *wqe,
struct rxe_cqe *cqe)
{
memset(cqe, 0, sizeof(*cqe));
if (!qp->is_user) {
struct ib_wc *wc = &cqe->ibwc;
wc->wr_id = wqe->wr.wr_id;
wc->status = wqe->status;
wc->opcode = wr_to_wc_opcode(wqe->wr.opcode);
if (wqe->wr.opcode == IB_WR_RDMA_WRITE_WITH_IMM ||
wqe->wr.opcode == IB_WR_SEND_WITH_IMM)
wc->wc_flags = IB_WC_WITH_IMM;
wc->byte_len = wqe->dma.length;
wc->qp = &qp->ibqp;
} else {
struct ib_uverbs_wc *uwc = &cqe->uibwc;
uwc->wr_id = wqe->wr.wr_id;
uwc->status = wqe->status;
uwc->opcode = wr_to_wc_opcode(wqe->wr.opcode);
if (wqe->wr.opcode == IB_WR_RDMA_WRITE_WITH_IMM ||
wqe->wr.opcode == IB_WR_SEND_WITH_IMM)
uwc->wc_flags = IB_WC_WITH_IMM;
uwc->byte_len = wqe->dma.length;
uwc->qp_num = qp->ibqp.qp_num;
}
}
static void do_complete(struct rxe_qp *qp, struct rxe_send_wqe *wqe)
{
struct rxe_cqe cqe;
if ((qp->sq_sig_type == IB_SIGNAL_ALL_WR) ||
(wqe->wr.send_flags & IB_SEND_SIGNALED) ||
wqe->status != IB_WC_SUCCESS) {
make_send_cqe(qp, wqe, &cqe);
advance_consumer(qp->sq.queue);
rxe_cq_post(qp->scq, &cqe, 0);
} else {
advance_consumer(qp->sq.queue);
}
if (qp->req.wait_fence) {
qp->req.wait_fence = 0;
rxe_run_task(&qp->req.task, 1);
}
}
static inline enum comp_state complete_ack(struct rxe_qp *qp,
struct rxe_pkt_info *pkt,
struct rxe_send_wqe *wqe)
{
unsigned long flags;
if (wqe->has_rd_atomic) {
wqe->has_rd_atomic = 0;
atomic_inc(&qp->req.rd_atomic);
if (qp->req.need_rd_atomic) {
qp->comp.timeout_retry = 0;
qp->req.need_rd_atomic = 0;
rxe_run_task(&qp->req.task, 1);
}
}
if (unlikely(qp->req.state == QP_STATE_DRAIN)) {
spin_lock_irqsave(&qp->state_lock, flags);
if ((qp->req.state == QP_STATE_DRAIN) &&
(qp->comp.psn == qp->req.psn)) {
qp->req.state = QP_STATE_DRAINED;
spin_unlock_irqrestore(&qp->state_lock, flags);
if (qp->ibqp.event_handler) {
struct ib_event ev;
ev.device = qp->ibqp.device;
ev.element.qp = &qp->ibqp;
ev.event = IB_EVENT_SQ_DRAINED;
qp->ibqp.event_handler(&ev,
qp->ibqp.qp_context);
}
} else {
spin_unlock_irqrestore(&qp->state_lock, flags);
}
}
do_complete(qp, wqe);
if (psn_compare(pkt->psn, qp->comp.psn) >= 0)
return COMPST_UPDATE_COMP;
else
return COMPST_DONE;
}
static inline enum comp_state complete_wqe(struct rxe_qp *qp,
struct rxe_pkt_info *pkt,
struct rxe_send_wqe *wqe)
{
qp->comp.opcode = -1;
if (pkt) {
if (psn_compare(pkt->psn, qp->comp.psn) >= 0)
qp->comp.psn = (pkt->psn + 1) & BTH_PSN_MASK;
if (qp->req.wait_psn) {
qp->req.wait_psn = 0;
rxe_run_task(&qp->req.task, 1);
}
}
do_complete(qp, wqe);
return COMPST_GET_WQE;
}
static void rxe_drain_resp_pkts(struct rxe_qp *qp, bool notify)
{
struct sk_buff *skb;
struct rxe_send_wqe *wqe;
while ((skb = skb_dequeue(&qp->resp_pkts))) {
rxe_drop_ref(qp);
kfree_skb(skb);
}
while ((wqe = queue_head(qp->sq.queue))) {
if (notify) {
wqe->status = IB_WC_WR_FLUSH_ERR;
do_complete(qp, wqe);
} else {
advance_consumer(qp->sq.queue);
}
}
}
int rxe_completer(void *arg)
{
struct rxe_qp *qp = (struct rxe_qp *)arg;
struct rxe_send_wqe *wqe = wqe;
struct sk_buff *skb = NULL;
struct rxe_pkt_info *pkt = NULL;
enum comp_state state;
rxe_add_ref(qp);
if (!qp->valid || qp->req.state == QP_STATE_ERROR ||
qp->req.state == QP_STATE_RESET) {
rxe_drain_resp_pkts(qp, qp->valid &&
qp->req.state == QP_STATE_ERROR);
goto exit;
}
if (qp->comp.timeout) {
qp->comp.timeout_retry = 1;
qp->comp.timeout = 0;
} else {
qp->comp.timeout_retry = 0;
}
if (qp->req.need_retry)
goto exit;
state = COMPST_GET_ACK;
while (1) {
pr_debug("qp#%d state = %s\n", qp_num(qp),
comp_state_name[state]);
switch (state) {
case COMPST_GET_ACK:
skb = skb_dequeue(&qp->resp_pkts);
if (skb) {
pkt = SKB_TO_PKT(skb);
qp->comp.timeout_retry = 0;
}
state = COMPST_GET_WQE;
break;
case COMPST_GET_WQE:
state = get_wqe(qp, pkt, &wqe);
break;
case COMPST_CHECK_PSN:
state = check_psn(qp, pkt, wqe);
break;
case COMPST_CHECK_ACK:
state = check_ack(qp, pkt, wqe);
break;
case COMPST_READ:
state = do_read(qp, pkt, wqe);
break;
case COMPST_ATOMIC:
state = do_atomic(qp, pkt, wqe);
break;
case COMPST_WRITE_SEND:
if (wqe->state == wqe_state_pending &&
wqe->last_psn == pkt->psn)
state = COMPST_COMP_ACK;
else
state = COMPST_UPDATE_COMP;
break;
case COMPST_COMP_ACK:
state = complete_ack(qp, pkt, wqe);
break;
case COMPST_COMP_WQE:
state = complete_wqe(qp, pkt, wqe);
break;
case COMPST_UPDATE_COMP:
if (pkt->mask & RXE_END_MASK)
qp->comp.opcode = -1;
else
qp->comp.opcode = pkt->opcode;
if (psn_compare(pkt->psn, qp->comp.psn) >= 0)
qp->comp.psn = (pkt->psn + 1) & BTH_PSN_MASK;
if (qp->req.wait_psn) {
qp->req.wait_psn = 0;
rxe_run_task(&qp->req.task, 1);
}
state = COMPST_DONE;
break;
case COMPST_DONE:
if (pkt) {
rxe_drop_ref(pkt->qp);
kfree_skb(skb);
skb = NULL;
}
goto done;
case COMPST_EXIT:
if (qp->comp.timeout_retry && wqe) {
state = COMPST_ERROR_RETRY;
break;
}
if ((qp_type(qp) == IB_QPT_RC) &&
(qp->req.state == QP_STATE_READY) &&
(psn_compare(qp->req.psn, qp->comp.psn) > 0) &&
qp->qp_timeout_jiffies)
mod_timer(&qp->retrans_timer,
jiffies + qp->qp_timeout_jiffies);
WARN_ON_ONCE(skb);
goto exit;
case COMPST_ERROR_RETRY:
if (!wqe || (wqe->state == wqe_state_posted)) {
WARN_ON_ONCE(skb);
goto exit;
}
if (qp->comp.retry_cnt > 0) {
if (qp->comp.retry_cnt != 7)
qp->comp.retry_cnt--;
if (psn_compare(qp->req.psn,
qp->comp.psn) > 0) {
qp->req.need_retry = 1;
rxe_run_task(&qp->req.task, 1);
}
if (pkt) {
rxe_drop_ref(pkt->qp);
kfree_skb(skb);
skb = NULL;
}
WARN_ON_ONCE(skb);
goto exit;
} else {
wqe->status = IB_WC_RETRY_EXC_ERR;
state = COMPST_ERROR;
}
break;
case COMPST_RNR_RETRY:
if (qp->comp.rnr_retry > 0) {
if (qp->comp.rnr_retry != 7)
qp->comp.rnr_retry--;
qp->req.need_retry = 1;
pr_debug("qp#%d set rnr nak timer\n",
qp_num(qp));
mod_timer(&qp->rnr_nak_timer,
jiffies + rnrnak_jiffies(aeth_syn(pkt)
& ~AETH_TYPE_MASK));
rxe_drop_ref(pkt->qp);
kfree_skb(skb);
skb = NULL;
goto exit;
} else {
wqe->status = IB_WC_RNR_RETRY_EXC_ERR;
state = COMPST_ERROR;
}
break;
case COMPST_ERROR:
WARN_ON_ONCE(wqe->status == IB_WC_SUCCESS);
do_complete(qp, wqe);
rxe_qp_error(qp);
if (pkt) {
rxe_drop_ref(pkt->qp);
kfree_skb(skb);
skb = NULL;
}
WARN_ON_ONCE(skb);
goto exit;
}
}
exit:
WARN_ON_ONCE(skb);
rxe_drop_ref(qp);
return -EAGAIN;
done:
WARN_ON_ONCE(skb);
rxe_drop_ref(qp);
return 0;
}
