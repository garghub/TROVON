static void qib_ud_loopback(struct rvt_qp *sqp, struct rvt_swqe *swqe)
{
struct qib_ibport *ibp = to_iport(sqp->ibqp.device, sqp->port_num);
struct qib_pportdata *ppd = ppd_from_ibp(ibp);
struct qib_devdata *dd = ppd->dd;
struct rvt_dev_info *rdi = &dd->verbs_dev.rdi;
struct rvt_qp *qp;
struct ib_ah_attr *ah_attr;
unsigned long flags;
struct rvt_sge_state ssge;
struct rvt_sge *sge;
struct ib_wc wc;
u32 length;
enum ib_qp_type sqptype, dqptype;
rcu_read_lock();
qp = rvt_lookup_qpn(rdi, &ibp->rvp, swqe->ud_wr.remote_qpn);
if (!qp) {
ibp->rvp.n_pkt_drops++;
rcu_read_unlock();
return;
}
sqptype = sqp->ibqp.qp_type == IB_QPT_GSI ?
IB_QPT_UD : sqp->ibqp.qp_type;
dqptype = qp->ibqp.qp_type == IB_QPT_GSI ?
IB_QPT_UD : qp->ibqp.qp_type;
if (dqptype != sqptype ||
!(ib_rvt_state_ops[qp->state] & RVT_PROCESS_RECV_OK)) {
ibp->rvp.n_pkt_drops++;
goto drop;
}
ah_attr = &ibah_to_rvtah(swqe->ud_wr.ah)->attr;
ppd = ppd_from_ibp(ibp);
if (qp->ibqp.qp_num > 1) {
u16 pkey1;
u16 pkey2;
u16 lid;
pkey1 = qib_get_pkey(ibp, sqp->s_pkey_index);
pkey2 = qib_get_pkey(ibp, qp->s_pkey_index);
if (unlikely(!qib_pkey_ok(pkey1, pkey2))) {
lid = ppd->lid | (ah_attr->src_path_bits &
((1 << ppd->lmc) - 1));
qib_bad_pqkey(ibp, IB_NOTICE_TRAP_BAD_PKEY, pkey1,
ah_attr->sl,
sqp->ibqp.qp_num, qp->ibqp.qp_num,
cpu_to_be16(lid),
cpu_to_be16(ah_attr->dlid));
goto drop;
}
}
if (qp->ibqp.qp_num) {
u32 qkey;
qkey = (int)swqe->ud_wr.remote_qkey < 0 ?
sqp->qkey : swqe->ud_wr.remote_qkey;
if (unlikely(qkey != qp->qkey)) {
u16 lid;
lid = ppd->lid | (ah_attr->src_path_bits &
((1 << ppd->lmc) - 1));
qib_bad_pqkey(ibp, IB_NOTICE_TRAP_BAD_QKEY, qkey,
ah_attr->sl,
sqp->ibqp.qp_num, qp->ibqp.qp_num,
cpu_to_be16(lid),
cpu_to_be16(ah_attr->dlid));
goto drop;
}
}
length = swqe->length;
memset(&wc, 0, sizeof(wc));
wc.byte_len = length + sizeof(struct ib_grh);
if (swqe->wr.opcode == IB_WR_SEND_WITH_IMM) {
wc.wc_flags = IB_WC_WITH_IMM;
wc.ex.imm_data = swqe->wr.ex.imm_data;
}
spin_lock_irqsave(&qp->r_lock, flags);
if (qp->r_flags & RVT_R_REUSE_SGE)
qp->r_flags &= ~RVT_R_REUSE_SGE;
else {
int ret;
ret = qib_get_rwqe(qp, 0);
if (ret < 0) {
qib_rc_error(qp, IB_WC_LOC_QP_OP_ERR);
goto bail_unlock;
}
if (!ret) {
if (qp->ibqp.qp_num == 0)
ibp->rvp.n_vl15_dropped++;
goto bail_unlock;
}
}
if (unlikely(wc.byte_len > qp->r_len)) {
qp->r_flags |= RVT_R_REUSE_SGE;
ibp->rvp.n_pkt_drops++;
goto bail_unlock;
}
if (ah_attr->ah_flags & IB_AH_GRH) {
qib_copy_sge(&qp->r_sge, &ah_attr->grh,
sizeof(struct ib_grh), 1);
wc.wc_flags |= IB_WC_GRH;
} else
qib_skip_sge(&qp->r_sge, sizeof(struct ib_grh), 1);
ssge.sg_list = swqe->sg_list + 1;
ssge.sge = *swqe->sg_list;
ssge.num_sge = swqe->wr.num_sge;
sge = &ssge.sge;
while (length) {
u32 len = sge->length;
if (len > length)
len = length;
if (len > sge->sge_length)
len = sge->sge_length;
BUG_ON(len == 0);
qib_copy_sge(&qp->r_sge, sge->vaddr, len, 1);
sge->vaddr += len;
sge->length -= len;
sge->sge_length -= len;
if (sge->sge_length == 0) {
if (--ssge.num_sge)
*sge = *ssge.sg_list++;
} else if (sge->length == 0 && sge->mr->lkey) {
if (++sge->n >= RVT_SEGSZ) {
if (++sge->m >= sge->mr->mapsz)
break;
sge->n = 0;
}
sge->vaddr =
sge->mr->map[sge->m]->segs[sge->n].vaddr;
sge->length =
sge->mr->map[sge->m]->segs[sge->n].length;
}
length -= len;
}
rvt_put_ss(&qp->r_sge);
if (!test_and_clear_bit(RVT_R_WRID_VALID, &qp->r_aflags))
goto bail_unlock;
wc.wr_id = qp->r_wr_id;
wc.status = IB_WC_SUCCESS;
wc.opcode = IB_WC_RECV;
wc.qp = &qp->ibqp;
wc.src_qp = sqp->ibqp.qp_num;
wc.pkey_index = qp->ibqp.qp_type == IB_QPT_GSI ?
swqe->ud_wr.pkey_index : 0;
wc.slid = ppd->lid | (ah_attr->src_path_bits & ((1 << ppd->lmc) - 1));
wc.sl = ah_attr->sl;
wc.dlid_path_bits = ah_attr->dlid & ((1 << ppd->lmc) - 1);
wc.port_num = qp->port_num;
rvt_cq_enter(ibcq_to_rvtcq(qp->ibqp.recv_cq), &wc,
swqe->wr.send_flags & IB_SEND_SOLICITED);
ibp->rvp.n_loop_pkts++;
bail_unlock:
spin_unlock_irqrestore(&qp->r_lock, flags);
drop:
rcu_read_unlock();
}
int qib_make_ud_req(struct rvt_qp *qp)
{
struct qib_qp_priv *priv = qp->priv;
struct qib_other_headers *ohdr;
struct ib_ah_attr *ah_attr;
struct qib_pportdata *ppd;
struct qib_ibport *ibp;
struct rvt_swqe *wqe;
u32 nwords;
u32 extra_bytes;
u32 bth0;
u16 lrh0;
u16 lid;
int ret = 0;
int next_cur;
if (!(ib_rvt_state_ops[qp->state] & RVT_PROCESS_NEXT_SEND_OK)) {
if (!(ib_rvt_state_ops[qp->state] & RVT_FLUSH_SEND))
goto bail;
smp_read_barrier_depends();
if (qp->s_last == ACCESS_ONCE(qp->s_head))
goto bail;
if (atomic_read(&priv->s_dma_busy)) {
qp->s_flags |= RVT_S_WAIT_DMA;
goto bail;
}
wqe = rvt_get_swqe_ptr(qp, qp->s_last);
qib_send_complete(qp, wqe, IB_WC_WR_FLUSH_ERR);
goto done;
}
smp_read_barrier_depends();
if (qp->s_cur == ACCESS_ONCE(qp->s_head))
goto bail;
wqe = rvt_get_swqe_ptr(qp, qp->s_cur);
next_cur = qp->s_cur + 1;
if (next_cur >= qp->s_size)
next_cur = 0;
ibp = to_iport(qp->ibqp.device, qp->port_num);
ppd = ppd_from_ibp(ibp);
ah_attr = &ibah_to_rvtah(wqe->ud_wr.ah)->attr;
if (ah_attr->dlid >= be16_to_cpu(IB_MULTICAST_LID_BASE)) {
if (ah_attr->dlid != be16_to_cpu(IB_LID_PERMISSIVE))
this_cpu_inc(ibp->pmastats->n_multicast_xmit);
else
this_cpu_inc(ibp->pmastats->n_unicast_xmit);
} else {
this_cpu_inc(ibp->pmastats->n_unicast_xmit);
lid = ah_attr->dlid & ~((1 << ppd->lmc) - 1);
if (unlikely(lid == ppd->lid)) {
unsigned long flags;
if (atomic_read(&priv->s_dma_busy)) {
qp->s_flags |= RVT_S_WAIT_DMA;
goto bail;
}
qp->s_cur = next_cur;
local_irq_save(flags);
spin_unlock_irqrestore(&qp->s_lock, flags);
qib_ud_loopback(qp, wqe);
spin_lock_irqsave(&qp->s_lock, flags);
qib_send_complete(qp, wqe, IB_WC_SUCCESS);
goto done;
}
}
qp->s_cur = next_cur;
extra_bytes = -wqe->length & 3;
nwords = (wqe->length + extra_bytes) >> 2;
qp->s_hdrwords = 7;
qp->s_cur_size = wqe->length;
qp->s_cur_sge = &qp->s_sge;
qp->s_srate = ah_attr->static_rate;
qp->s_wqe = wqe;
qp->s_sge.sge = wqe->sg_list[0];
qp->s_sge.sg_list = wqe->sg_list + 1;
qp->s_sge.num_sge = wqe->wr.num_sge;
qp->s_sge.total_len = wqe->length;
if (ah_attr->ah_flags & IB_AH_GRH) {
qp->s_hdrwords += qib_make_grh(ibp, &priv->s_hdr->u.l.grh,
&ah_attr->grh,
qp->s_hdrwords, nwords);
lrh0 = QIB_LRH_GRH;
ohdr = &priv->s_hdr->u.l.oth;
} else {
lrh0 = QIB_LRH_BTH;
ohdr = &priv->s_hdr->u.oth;
}
if (wqe->wr.opcode == IB_WR_SEND_WITH_IMM) {
qp->s_hdrwords++;
ohdr->u.ud.imm_data = wqe->wr.ex.imm_data;
bth0 = IB_OPCODE_UD_SEND_ONLY_WITH_IMMEDIATE << 24;
} else
bth0 = IB_OPCODE_UD_SEND_ONLY << 24;
lrh0 |= ah_attr->sl << 4;
if (qp->ibqp.qp_type == IB_QPT_SMI)
lrh0 |= 0xF000;
else
lrh0 |= ibp->sl_to_vl[ah_attr->sl] << 12;
priv->s_hdr->lrh[0] = cpu_to_be16(lrh0);
priv->s_hdr->lrh[1] = cpu_to_be16(ah_attr->dlid);
priv->s_hdr->lrh[2] =
cpu_to_be16(qp->s_hdrwords + nwords + SIZE_OF_CRC);
lid = ppd->lid;
if (lid) {
lid |= ah_attr->src_path_bits & ((1 << ppd->lmc) - 1);
priv->s_hdr->lrh[3] = cpu_to_be16(lid);
} else
priv->s_hdr->lrh[3] = IB_LID_PERMISSIVE;
if (wqe->wr.send_flags & IB_SEND_SOLICITED)
bth0 |= IB_BTH_SOLICITED;
bth0 |= extra_bytes << 20;
bth0 |= qp->ibqp.qp_type == IB_QPT_SMI ? QIB_DEFAULT_P_KEY :
qib_get_pkey(ibp, qp->ibqp.qp_type == IB_QPT_GSI ?
wqe->ud_wr.pkey_index : qp->s_pkey_index);
ohdr->bth[0] = cpu_to_be32(bth0);
ohdr->bth[1] = ah_attr->dlid >= be16_to_cpu(IB_MULTICAST_LID_BASE) &&
ah_attr->dlid != be16_to_cpu(IB_LID_PERMISSIVE) ?
cpu_to_be32(QIB_MULTICAST_QPN) :
cpu_to_be32(wqe->ud_wr.remote_qpn);
ohdr->bth[2] = cpu_to_be32(wqe->psn & QIB_PSN_MASK);
ohdr->u.ud.deth[0] = cpu_to_be32((int)wqe->ud_wr.remote_qkey < 0 ?
qp->qkey : wqe->ud_wr.remote_qkey);
ohdr->u.ud.deth[1] = cpu_to_be32(qp->ibqp.qp_num);
done:
return 1;
bail:
qp->s_flags &= ~RVT_S_BUSY;
return ret;
}
static unsigned qib_lookup_pkey(struct qib_ibport *ibp, u16 pkey)
{
struct qib_pportdata *ppd = ppd_from_ibp(ibp);
struct qib_devdata *dd = ppd->dd;
unsigned ctxt = ppd->hw_pidx;
unsigned i;
pkey &= 0x7fff;
for (i = 0; i < ARRAY_SIZE(dd->rcd[ctxt]->pkeys); ++i)
if ((dd->rcd[ctxt]->pkeys[i] & 0x7fff) == pkey)
return i;
return 0;
}
void qib_ud_rcv(struct qib_ibport *ibp, struct qib_ib_header *hdr,
int has_grh, void *data, u32 tlen, struct rvt_qp *qp)
{
struct qib_other_headers *ohdr;
int opcode;
u32 hdrsize;
u32 pad;
struct ib_wc wc;
u32 qkey;
u32 src_qp;
u16 dlid;
if (!has_grh) {
ohdr = &hdr->u.oth;
hdrsize = 8 + 12 + 8;
} else {
ohdr = &hdr->u.l.oth;
hdrsize = 8 + 40 + 12 + 8;
}
qkey = be32_to_cpu(ohdr->u.ud.deth[0]);
src_qp = be32_to_cpu(ohdr->u.ud.deth[1]) & RVT_QPN_MASK;
pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
if (unlikely(tlen < (hdrsize + pad + 4)))
goto drop;
tlen -= hdrsize + pad + 4;
if (qp->ibqp.qp_num) {
if (unlikely(hdr->lrh[1] == IB_LID_PERMISSIVE ||
hdr->lrh[3] == IB_LID_PERMISSIVE))
goto drop;
if (qp->ibqp.qp_num > 1) {
u16 pkey1, pkey2;
pkey1 = be32_to_cpu(ohdr->bth[0]);
pkey2 = qib_get_pkey(ibp, qp->s_pkey_index);
if (unlikely(!qib_pkey_ok(pkey1, pkey2))) {
qib_bad_pqkey(ibp, IB_NOTICE_TRAP_BAD_PKEY,
pkey1,
(be16_to_cpu(hdr->lrh[0]) >> 4) &
0xF,
src_qp, qp->ibqp.qp_num,
hdr->lrh[3], hdr->lrh[1]);
return;
}
}
if (unlikely(qkey != qp->qkey)) {
qib_bad_pqkey(ibp, IB_NOTICE_TRAP_BAD_QKEY, qkey,
(be16_to_cpu(hdr->lrh[0]) >> 4) & 0xF,
src_qp, qp->ibqp.qp_num,
hdr->lrh[3], hdr->lrh[1]);
return;
}
if (unlikely(qp->ibqp.qp_num == 1 &&
(tlen != 256 ||
(be16_to_cpu(hdr->lrh[0]) >> 12) == 15)))
goto drop;
} else {
struct ib_smp *smp;
if (tlen != 256 || (be16_to_cpu(hdr->lrh[0]) >> 12) != 15)
goto drop;
smp = (struct ib_smp *) data;
if ((hdr->lrh[1] == IB_LID_PERMISSIVE ||
hdr->lrh[3] == IB_LID_PERMISSIVE) &&
smp->mgmt_class != IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE)
goto drop;
}
opcode = be32_to_cpu(ohdr->bth[0]) >> 24;
if (qp->ibqp.qp_num > 1 &&
opcode == IB_OPCODE_UD_SEND_ONLY_WITH_IMMEDIATE) {
wc.ex.imm_data = ohdr->u.ud.imm_data;
wc.wc_flags = IB_WC_WITH_IMM;
tlen -= sizeof(u32);
} else if (opcode == IB_OPCODE_UD_SEND_ONLY) {
wc.ex.imm_data = 0;
wc.wc_flags = 0;
} else
goto drop;
wc.byte_len = tlen + sizeof(struct ib_grh);
if (qp->r_flags & RVT_R_REUSE_SGE)
qp->r_flags &= ~RVT_R_REUSE_SGE;
else {
int ret;
ret = qib_get_rwqe(qp, 0);
if (ret < 0) {
qib_rc_error(qp, IB_WC_LOC_QP_OP_ERR);
return;
}
if (!ret) {
if (qp->ibqp.qp_num == 0)
ibp->rvp.n_vl15_dropped++;
return;
}
}
if (unlikely(wc.byte_len > qp->r_len)) {
qp->r_flags |= RVT_R_REUSE_SGE;
goto drop;
}
if (has_grh) {
qib_copy_sge(&qp->r_sge, &hdr->u.l.grh,
sizeof(struct ib_grh), 1);
wc.wc_flags |= IB_WC_GRH;
} else
qib_skip_sge(&qp->r_sge, sizeof(struct ib_grh), 1);
qib_copy_sge(&qp->r_sge, data, wc.byte_len - sizeof(struct ib_grh), 1);
rvt_put_ss(&qp->r_sge);
if (!test_and_clear_bit(RVT_R_WRID_VALID, &qp->r_aflags))
return;
wc.wr_id = qp->r_wr_id;
wc.status = IB_WC_SUCCESS;
wc.opcode = IB_WC_RECV;
wc.vendor_err = 0;
wc.qp = &qp->ibqp;
wc.src_qp = src_qp;
wc.pkey_index = qp->ibqp.qp_type == IB_QPT_GSI ?
qib_lookup_pkey(ibp, be32_to_cpu(ohdr->bth[0])) : 0;
wc.slid = be16_to_cpu(hdr->lrh[3]);
wc.sl = (be16_to_cpu(hdr->lrh[0]) >> 4) & 0xF;
dlid = be16_to_cpu(hdr->lrh[1]);
wc.dlid_path_bits = dlid >= be16_to_cpu(IB_MULTICAST_LID_BASE) ? 0 :
dlid & ((1 << ppd_from_ibp(ibp)->lmc) - 1);
wc.port_num = qp->port_num;
rvt_cq_enter(ibcq_to_rvtcq(qp->ibqp.recv_cq), &wc,
(ohdr->bth[0] &
cpu_to_be32(IB_BTH_SOLICITED)) != 0);
return;
drop:
ibp->rvp.n_pkt_drops++;
}
