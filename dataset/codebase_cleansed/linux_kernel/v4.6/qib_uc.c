int qib_make_uc_req(struct rvt_qp *qp)
{
struct qib_qp_priv *priv = qp->priv;
struct qib_other_headers *ohdr;
struct rvt_swqe *wqe;
u32 hwords;
u32 bth0;
u32 len;
u32 pmtu = qp->pmtu;
int ret = 0;
if (!(ib_rvt_state_ops[qp->state] & RVT_PROCESS_SEND_OK)) {
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
ohdr = &priv->s_hdr->u.oth;
if (qp->remote_ah_attr.ah_flags & IB_AH_GRH)
ohdr = &priv->s_hdr->u.l.oth;
hwords = 5;
bth0 = 0;
wqe = rvt_get_swqe_ptr(qp, qp->s_cur);
qp->s_wqe = NULL;
switch (qp->s_state) {
default:
if (!(ib_rvt_state_ops[qp->state] &
RVT_PROCESS_NEXT_SEND_OK))
goto bail;
smp_read_barrier_depends();
if (qp->s_cur == ACCESS_ONCE(qp->s_head))
goto bail;
qp->s_psn = wqe->psn;
qp->s_sge.sge = wqe->sg_list[0];
qp->s_sge.sg_list = wqe->sg_list + 1;
qp->s_sge.num_sge = wqe->wr.num_sge;
qp->s_sge.total_len = wqe->length;
len = wqe->length;
qp->s_len = len;
switch (wqe->wr.opcode) {
case IB_WR_SEND:
case IB_WR_SEND_WITH_IMM:
if (len > pmtu) {
qp->s_state = OP(SEND_FIRST);
len = pmtu;
break;
}
if (wqe->wr.opcode == IB_WR_SEND)
qp->s_state = OP(SEND_ONLY);
else {
qp->s_state =
OP(SEND_ONLY_WITH_IMMEDIATE);
ohdr->u.imm_data = wqe->wr.ex.imm_data;
hwords += 1;
}
if (wqe->wr.send_flags & IB_SEND_SOLICITED)
bth0 |= IB_BTH_SOLICITED;
qp->s_wqe = wqe;
if (++qp->s_cur >= qp->s_size)
qp->s_cur = 0;
break;
case IB_WR_RDMA_WRITE:
case IB_WR_RDMA_WRITE_WITH_IMM:
ohdr->u.rc.reth.vaddr =
cpu_to_be64(wqe->rdma_wr.remote_addr);
ohdr->u.rc.reth.rkey =
cpu_to_be32(wqe->rdma_wr.rkey);
ohdr->u.rc.reth.length = cpu_to_be32(len);
hwords += sizeof(struct ib_reth) / 4;
if (len > pmtu) {
qp->s_state = OP(RDMA_WRITE_FIRST);
len = pmtu;
break;
}
if (wqe->wr.opcode == IB_WR_RDMA_WRITE)
qp->s_state = OP(RDMA_WRITE_ONLY);
else {
qp->s_state =
OP(RDMA_WRITE_ONLY_WITH_IMMEDIATE);
ohdr->u.rc.imm_data = wqe->wr.ex.imm_data;
hwords += 1;
if (wqe->wr.send_flags & IB_SEND_SOLICITED)
bth0 |= IB_BTH_SOLICITED;
}
qp->s_wqe = wqe;
if (++qp->s_cur >= qp->s_size)
qp->s_cur = 0;
break;
default:
goto bail;
}
break;
case OP(SEND_FIRST):
qp->s_state = OP(SEND_MIDDLE);
case OP(SEND_MIDDLE):
len = qp->s_len;
if (len > pmtu) {
len = pmtu;
break;
}
if (wqe->wr.opcode == IB_WR_SEND)
qp->s_state = OP(SEND_LAST);
else {
qp->s_state = OP(SEND_LAST_WITH_IMMEDIATE);
ohdr->u.imm_data = wqe->wr.ex.imm_data;
hwords += 1;
}
if (wqe->wr.send_flags & IB_SEND_SOLICITED)
bth0 |= IB_BTH_SOLICITED;
qp->s_wqe = wqe;
if (++qp->s_cur >= qp->s_size)
qp->s_cur = 0;
break;
case OP(RDMA_WRITE_FIRST):
qp->s_state = OP(RDMA_WRITE_MIDDLE);
case OP(RDMA_WRITE_MIDDLE):
len = qp->s_len;
if (len > pmtu) {
len = pmtu;
break;
}
if (wqe->wr.opcode == IB_WR_RDMA_WRITE)
qp->s_state = OP(RDMA_WRITE_LAST);
else {
qp->s_state =
OP(RDMA_WRITE_LAST_WITH_IMMEDIATE);
ohdr->u.imm_data = wqe->wr.ex.imm_data;
hwords += 1;
if (wqe->wr.send_flags & IB_SEND_SOLICITED)
bth0 |= IB_BTH_SOLICITED;
}
qp->s_wqe = wqe;
if (++qp->s_cur >= qp->s_size)
qp->s_cur = 0;
break;
}
qp->s_len -= len;
qp->s_hdrwords = hwords;
qp->s_cur_sge = &qp->s_sge;
qp->s_cur_size = len;
qib_make_ruc_header(qp, ohdr, bth0 | (qp->s_state << 24),
qp->s_psn++ & QIB_PSN_MASK);
done:
return 1;
bail:
qp->s_flags &= ~RVT_S_BUSY;
return ret;
}
void qib_uc_rcv(struct qib_ibport *ibp, struct qib_ib_header *hdr,
int has_grh, void *data, u32 tlen, struct rvt_qp *qp)
{
struct qib_other_headers *ohdr;
u32 opcode;
u32 hdrsize;
u32 psn;
u32 pad;
struct ib_wc wc;
u32 pmtu = qp->pmtu;
struct ib_reth *reth;
int ret;
if (!has_grh) {
ohdr = &hdr->u.oth;
hdrsize = 8 + 12;
} else {
ohdr = &hdr->u.l.oth;
hdrsize = 8 + 40 + 12;
}
opcode = be32_to_cpu(ohdr->bth[0]);
if (qib_ruc_check_hdr(ibp, hdr, has_grh, qp, opcode))
return;
psn = be32_to_cpu(ohdr->bth[2]);
opcode >>= 24;
if (unlikely(qib_cmp24(psn, qp->r_psn) != 0)) {
qp->r_psn = psn;
inv:
if (qp->r_state == OP(SEND_FIRST) ||
qp->r_state == OP(SEND_MIDDLE)) {
set_bit(RVT_R_REWIND_SGE, &qp->r_aflags);
qp->r_sge.num_sge = 0;
} else
rvt_put_ss(&qp->r_sge);
qp->r_state = OP(SEND_LAST);
switch (opcode) {
case OP(SEND_FIRST):
case OP(SEND_ONLY):
case OP(SEND_ONLY_WITH_IMMEDIATE):
goto send_first;
case OP(RDMA_WRITE_FIRST):
case OP(RDMA_WRITE_ONLY):
case OP(RDMA_WRITE_ONLY_WITH_IMMEDIATE):
goto rdma_first;
default:
goto drop;
}
}
switch (qp->r_state) {
case OP(SEND_FIRST):
case OP(SEND_MIDDLE):
if (opcode == OP(SEND_MIDDLE) ||
opcode == OP(SEND_LAST) ||
opcode == OP(SEND_LAST_WITH_IMMEDIATE))
break;
goto inv;
case OP(RDMA_WRITE_FIRST):
case OP(RDMA_WRITE_MIDDLE):
if (opcode == OP(RDMA_WRITE_MIDDLE) ||
opcode == OP(RDMA_WRITE_LAST) ||
opcode == OP(RDMA_WRITE_LAST_WITH_IMMEDIATE))
break;
goto inv;
default:
if (opcode == OP(SEND_FIRST) ||
opcode == OP(SEND_ONLY) ||
opcode == OP(SEND_ONLY_WITH_IMMEDIATE) ||
opcode == OP(RDMA_WRITE_FIRST) ||
opcode == OP(RDMA_WRITE_ONLY) ||
opcode == OP(RDMA_WRITE_ONLY_WITH_IMMEDIATE))
break;
goto inv;
}
if (qp->state == IB_QPS_RTR && !(qp->r_flags & RVT_R_COMM_EST)) {
qp->r_flags |= RVT_R_COMM_EST;
if (qp->ibqp.event_handler) {
struct ib_event ev;
ev.device = qp->ibqp.device;
ev.element.qp = &qp->ibqp;
ev.event = IB_EVENT_COMM_EST;
qp->ibqp.event_handler(&ev, qp->ibqp.qp_context);
}
}
switch (opcode) {
case OP(SEND_FIRST):
case OP(SEND_ONLY):
case OP(SEND_ONLY_WITH_IMMEDIATE):
send_first:
if (test_and_clear_bit(RVT_R_REWIND_SGE, &qp->r_aflags))
qp->r_sge = qp->s_rdma_read_sge;
else {
ret = qib_get_rwqe(qp, 0);
if (ret < 0)
goto op_err;
if (!ret)
goto drop;
qp->s_rdma_read_sge = qp->r_sge;
}
qp->r_rcv_len = 0;
if (opcode == OP(SEND_ONLY))
goto no_immediate_data;
else if (opcode == OP(SEND_ONLY_WITH_IMMEDIATE))
goto send_last_imm;
case OP(SEND_MIDDLE):
if (unlikely(tlen != (hdrsize + pmtu + 4)))
goto rewind;
qp->r_rcv_len += pmtu;
if (unlikely(qp->r_rcv_len > qp->r_len))
goto rewind;
qib_copy_sge(&qp->r_sge, data, pmtu, 0);
break;
case OP(SEND_LAST_WITH_IMMEDIATE):
send_last_imm:
wc.ex.imm_data = ohdr->u.imm_data;
hdrsize += 4;
wc.wc_flags = IB_WC_WITH_IMM;
goto send_last;
case OP(SEND_LAST):
no_immediate_data:
wc.ex.imm_data = 0;
wc.wc_flags = 0;
send_last:
pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
if (unlikely(tlen < (hdrsize + pad + 4)))
goto rewind;
tlen -= (hdrsize + pad + 4);
wc.byte_len = tlen + qp->r_rcv_len;
if (unlikely(wc.byte_len > qp->r_len))
goto rewind;
wc.opcode = IB_WC_RECV;
qib_copy_sge(&qp->r_sge, data, tlen, 0);
rvt_put_ss(&qp->s_rdma_read_sge);
last_imm:
wc.wr_id = qp->r_wr_id;
wc.status = IB_WC_SUCCESS;
wc.qp = &qp->ibqp;
wc.src_qp = qp->remote_qpn;
wc.slid = qp->remote_ah_attr.dlid;
wc.sl = qp->remote_ah_attr.sl;
wc.vendor_err = 0;
wc.pkey_index = 0;
wc.dlid_path_bits = 0;
wc.port_num = 0;
rvt_cq_enter(ibcq_to_rvtcq(qp->ibqp.recv_cq), &wc,
(ohdr->bth[0] &
cpu_to_be32(IB_BTH_SOLICITED)) != 0);
break;
case OP(RDMA_WRITE_FIRST):
case OP(RDMA_WRITE_ONLY):
case OP(RDMA_WRITE_ONLY_WITH_IMMEDIATE):
rdma_first:
if (unlikely(!(qp->qp_access_flags &
IB_ACCESS_REMOTE_WRITE))) {
goto drop;
}
reth = &ohdr->u.rc.reth;
hdrsize += sizeof(*reth);
qp->r_len = be32_to_cpu(reth->length);
qp->r_rcv_len = 0;
qp->r_sge.sg_list = NULL;
if (qp->r_len != 0) {
u32 rkey = be32_to_cpu(reth->rkey);
u64 vaddr = be64_to_cpu(reth->vaddr);
int ok;
ok = rvt_rkey_ok(qp, &qp->r_sge.sge, qp->r_len,
vaddr, rkey, IB_ACCESS_REMOTE_WRITE);
if (unlikely(!ok))
goto drop;
qp->r_sge.num_sge = 1;
} else {
qp->r_sge.num_sge = 0;
qp->r_sge.sge.mr = NULL;
qp->r_sge.sge.vaddr = NULL;
qp->r_sge.sge.length = 0;
qp->r_sge.sge.sge_length = 0;
}
if (opcode == OP(RDMA_WRITE_ONLY))
goto rdma_last;
else if (opcode == OP(RDMA_WRITE_ONLY_WITH_IMMEDIATE)) {
wc.ex.imm_data = ohdr->u.rc.imm_data;
goto rdma_last_imm;
}
case OP(RDMA_WRITE_MIDDLE):
if (unlikely(tlen != (hdrsize + pmtu + 4)))
goto drop;
qp->r_rcv_len += pmtu;
if (unlikely(qp->r_rcv_len > qp->r_len))
goto drop;
qib_copy_sge(&qp->r_sge, data, pmtu, 1);
break;
case OP(RDMA_WRITE_LAST_WITH_IMMEDIATE):
wc.ex.imm_data = ohdr->u.imm_data;
rdma_last_imm:
hdrsize += 4;
wc.wc_flags = IB_WC_WITH_IMM;
pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
if (unlikely(tlen < (hdrsize + pad + 4)))
goto drop;
tlen -= (hdrsize + pad + 4);
if (unlikely(tlen + qp->r_rcv_len != qp->r_len))
goto drop;
if (test_and_clear_bit(RVT_R_REWIND_SGE, &qp->r_aflags))
rvt_put_ss(&qp->s_rdma_read_sge);
else {
ret = qib_get_rwqe(qp, 1);
if (ret < 0)
goto op_err;
if (!ret)
goto drop;
}
wc.byte_len = qp->r_len;
wc.opcode = IB_WC_RECV_RDMA_WITH_IMM;
qib_copy_sge(&qp->r_sge, data, tlen, 1);
rvt_put_ss(&qp->r_sge);
goto last_imm;
case OP(RDMA_WRITE_LAST):
rdma_last:
pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
if (unlikely(tlen < (hdrsize + pad + 4)))
goto drop;
tlen -= (hdrsize + pad + 4);
if (unlikely(tlen + qp->r_rcv_len != qp->r_len))
goto drop;
qib_copy_sge(&qp->r_sge, data, tlen, 1);
rvt_put_ss(&qp->r_sge);
break;
default:
goto drop;
}
qp->r_psn++;
qp->r_state = opcode;
return;
rewind:
set_bit(RVT_R_REWIND_SGE, &qp->r_aflags);
qp->r_sge.num_sge = 0;
drop:
ibp->rvp.n_pkt_drops++;
return;
op_err:
qib_rc_error(qp, IB_WC_LOC_QP_OP_ERR);
return;
}
