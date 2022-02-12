static void post_qp_event(struct c4iw_dev *dev, struct c4iw_cq *chp,
struct c4iw_qp *qhp,
struct t4_cqe *err_cqe,
enum ib_event_type ib_event)
{
struct ib_event event;
struct c4iw_qp_attributes attrs;
unsigned long flag;
printk(KERN_ERR MOD "AE qpid 0x%x opcode %d status 0x%x "
"type %d wrid.hi 0x%x wrid.lo 0x%x\n",
CQE_QPID(err_cqe), CQE_OPCODE(err_cqe),
CQE_STATUS(err_cqe), CQE_TYPE(err_cqe),
CQE_WRID_HI(err_cqe), CQE_WRID_LOW(err_cqe));
if (qhp->attr.state == C4IW_QP_STATE_RTS) {
attrs.next_state = C4IW_QP_STATE_TERMINATE;
c4iw_modify_qp(qhp->rhp, qhp, C4IW_QP_ATTR_NEXT_STATE,
&attrs, 0);
}
event.event = ib_event;
event.device = chp->ibcq.device;
if (ib_event == IB_EVENT_CQ_ERR)
event.element.cq = &chp->ibcq;
else
event.element.qp = &qhp->ibqp;
if (qhp->ibqp.event_handler)
(*qhp->ibqp.event_handler)(&event, qhp->ibqp.qp_context);
spin_lock_irqsave(&chp->comp_handler_lock, flag);
(*chp->ibcq.comp_handler)(&chp->ibcq, chp->ibcq.cq_context);
spin_unlock_irqrestore(&chp->comp_handler_lock, flag);
}
void c4iw_ev_dispatch(struct c4iw_dev *dev, struct t4_cqe *err_cqe)
{
struct c4iw_cq *chp;
struct c4iw_qp *qhp;
u32 cqid;
spin_lock_irq(&dev->lock);
qhp = get_qhp(dev, CQE_QPID(err_cqe));
if (!qhp) {
printk(KERN_ERR MOD "BAD AE qpid 0x%x opcode %d "
"status 0x%x type %d wrid.hi 0x%x wrid.lo 0x%x\n",
CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe));
spin_unlock_irq(&dev->lock);
goto out;
}
if (SQ_TYPE(err_cqe))
cqid = qhp->attr.scq;
else
cqid = qhp->attr.rcq;
chp = get_chp(dev, cqid);
if (!chp) {
printk(KERN_ERR MOD "BAD AE cqid 0x%x qpid 0x%x opcode %d "
"status 0x%x type %d wrid.hi 0x%x wrid.lo 0x%x\n",
cqid, CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe));
spin_unlock_irq(&dev->lock);
goto out;
}
c4iw_qp_add_ref(&qhp->ibqp);
atomic_inc(&chp->refcnt);
spin_unlock_irq(&dev->lock);
if (RQ_TYPE(err_cqe) &&
(CQE_OPCODE(err_cqe) == FW_RI_RDMA_WRITE)) {
post_qp_event(dev, chp, qhp, err_cqe, IB_EVENT_QP_REQ_ERR);
goto done;
}
switch (CQE_STATUS(err_cqe)) {
case T4_ERR_SUCCESS:
printk(KERN_ERR MOD "AE with status 0!\n");
break;
case T4_ERR_STAG:
case T4_ERR_PDID:
case T4_ERR_QPID:
case T4_ERR_ACCESS:
case T4_ERR_WRAP:
case T4_ERR_BOUND:
case T4_ERR_INVALIDATE_SHARED_MR:
case T4_ERR_INVALIDATE_MR_WITH_MW_BOUND:
post_qp_event(dev, chp, qhp, err_cqe, IB_EVENT_QP_ACCESS_ERR);
break;
case T4_ERR_ECC:
case T4_ERR_ECC_PSTAG:
case T4_ERR_INTERNAL_ERR:
post_qp_event(dev, chp, qhp, err_cqe, IB_EVENT_DEVICE_FATAL);
break;
case T4_ERR_OUT_OF_RQE:
case T4_ERR_PBL_ADDR_BOUND:
case T4_ERR_CRC:
case T4_ERR_MARKER:
case T4_ERR_PDU_LEN_ERR:
case T4_ERR_DDP_VERSION:
case T4_ERR_RDMA_VERSION:
case T4_ERR_OPCODE:
case T4_ERR_DDP_QUEUE_NUM:
case T4_ERR_MSN:
case T4_ERR_TBIT:
case T4_ERR_MO:
case T4_ERR_MSN_GAP:
case T4_ERR_MSN_RANGE:
case T4_ERR_RQE_ADDR_BOUND:
case T4_ERR_IRD_OVERFLOW:
post_qp_event(dev, chp, qhp, err_cqe, IB_EVENT_QP_FATAL);
break;
default:
printk(KERN_ERR MOD "Unknown T4 status 0x%x QPID 0x%x\n",
CQE_STATUS(err_cqe), qhp->wq.sq.qid);
post_qp_event(dev, chp, qhp, err_cqe, IB_EVENT_QP_FATAL);
break;
}
done:
if (atomic_dec_and_test(&chp->refcnt))
wake_up(&chp->wait);
c4iw_qp_rem_ref(&qhp->ibqp);
out:
return;
}
int c4iw_ev_handler(struct c4iw_dev *dev, u32 qid)
{
struct c4iw_cq *chp;
unsigned long flag;
chp = get_chp(dev, qid);
if (chp) {
spin_lock_irqsave(&chp->comp_handler_lock, flag);
(*chp->ibcq.comp_handler)(&chp->ibcq, chp->ibcq.cq_context);
spin_unlock_irqrestore(&chp->comp_handler_lock, flag);
} else
PDBG("%s unknown cqid 0x%x\n", __func__, qid);
return 0;
}
