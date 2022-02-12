__be32 rvt_compute_aeth(struct rvt_qp *qp)
{
u32 aeth = qp->r_msn & IB_MSN_MASK;
if (qp->ibqp.srq) {
aeth |= IB_AETH_CREDIT_INVAL << IB_AETH_CREDIT_SHIFT;
} else {
u32 min, max, x;
u32 credits;
struct rvt_rwq *wq = qp->r_rq.wq;
u32 head;
u32 tail;
head = wq->head;
if (head >= qp->r_rq.size)
head = 0;
tail = wq->tail;
if (tail >= qp->r_rq.size)
tail = 0;
credits = head - tail;
if ((int)credits < 0)
credits += qp->r_rq.size;
min = 0;
max = 31;
for (;;) {
x = (min + max) / 2;
if (credit_table[x] == credits)
break;
if (credit_table[x] > credits) {
max = x;
} else {
if (min == x)
break;
min = x;
}
}
aeth |= x << IB_AETH_CREDIT_SHIFT;
}
return cpu_to_be32(aeth);
}
void rvt_get_credit(struct rvt_qp *qp, u32 aeth)
{
struct rvt_dev_info *rdi = ib_to_rvt(qp->ibqp.device);
u32 credit = (aeth >> IB_AETH_CREDIT_SHIFT) & IB_AETH_CREDIT_MASK;
lockdep_assert_held(&qp->s_lock);
if (credit == IB_AETH_CREDIT_INVAL) {
if (!(qp->s_flags & RVT_S_UNLIMITED_CREDIT)) {
qp->s_flags |= RVT_S_UNLIMITED_CREDIT;
if (qp->s_flags & RVT_S_WAIT_SSN_CREDIT) {
qp->s_flags &= ~RVT_S_WAIT_SSN_CREDIT;
rdi->driver_f.schedule_send(qp);
}
}
} else if (!(qp->s_flags & RVT_S_UNLIMITED_CREDIT)) {
credit = (aeth + credit_table[credit]) & IB_MSN_MASK;
if (rvt_cmp_msn(credit, qp->s_lsn) > 0) {
qp->s_lsn = credit;
if (qp->s_flags & RVT_S_WAIT_SSN_CREDIT) {
qp->s_flags &= ~RVT_S_WAIT_SSN_CREDIT;
rdi->driver_f.schedule_send(qp);
}
}
}
}
