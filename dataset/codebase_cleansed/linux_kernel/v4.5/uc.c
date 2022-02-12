int hfi1_make_uc_req(struct hfi1_qp *qp)
{
struct hfi1_other_headers *ohdr;
struct hfi1_swqe *wqe;
unsigned long flags;
u32 hwords = 5;
u32 bth0 = 0;
u32 len;
u32 pmtu = qp->pmtu;
int ret = 0;
int middle = 0;
spin_lock_irqsave(&qp->s_lock, flags);
if (!(ib_hfi1_state_ops[qp->state] & HFI1_PROCESS_SEND_OK)) {
if (!(ib_hfi1_state_ops[qp->state] & HFI1_FLUSH_SEND))
goto bail;
if (qp->s_last == qp->s_head)
goto bail;
if (atomic_read(&qp->s_iowait.sdma_busy)) {
qp->s_flags |= HFI1_S_WAIT_DMA;
goto bail;
}
clear_ahg(qp);
wqe = get_swqe_ptr(qp, qp->s_last);
hfi1_send_complete(qp, wqe, IB_WC_WR_FLUSH_ERR);
goto done;
}
ohdr = &qp->s_hdr->ibh.u.oth;
if (qp->remote_ah_attr.ah_flags & IB_AH_GRH)
ohdr = &qp->s_hdr->ibh.u.l.oth;
wqe = get_swqe_ptr(qp, qp->s_cur);
qp->s_wqe = NULL;
switch (qp->s_state) {
default:
if (!(ib_hfi1_state_ops[qp->state] &
HFI1_PROCESS_NEXT_SEND_OK))
goto bail;
if (qp->s_cur == qp->s_head) {
clear_ahg(qp);
goto bail;
}
wqe->psn = qp->s_next_psn;
qp->s_psn = qp->s_next_psn;
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
middle = HFI1_CAP_IS_KSET(SDMA_AHG);
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
middle = HFI1_CAP_IS_KSET(SDMA_AHG);
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
hfi1_make_ruc_header(qp, ohdr, bth0 | (qp->s_state << 24),
mask_psn(qp->s_next_psn++), middle);
done:
ret = 1;
goto unlock;
bail:
qp->s_flags &= ~HFI1_S_BUSY;
unlock:
spin_unlock_irqrestore(&qp->s_lock, flags);
return ret;
}
void hfi1_uc_rcv(struct hfi1_packet *packet)
{
struct hfi1_ibport *ibp = &packet->rcd->ppd->ibport_data;
struct hfi1_ib_header *hdr = packet->hdr;
u32 rcv_flags = packet->rcv_flags;
void *data = packet->ebuf;
u32 tlen = packet->tlen;
struct hfi1_qp *qp = packet->qp;
struct hfi1_other_headers *ohdr = packet->ohdr;
u32 bth0, opcode;
u32 hdrsize = packet->hlen;
u32 psn;
u32 pad;
struct ib_wc wc;
u32 pmtu = qp->pmtu;
struct ib_reth *reth;
int has_grh = rcv_flags & HFI1_HAS_GRH;
int ret;
u32 bth1;
bth0 = be32_to_cpu(ohdr->bth[0]);
if (hfi1_ruc_check_hdr(ibp, hdr, has_grh, qp, bth0))
return;
bth1 = be32_to_cpu(ohdr->bth[1]);
if (unlikely(bth1 & (HFI1_BECN_SMASK | HFI1_FECN_SMASK))) {
if (bth1 & HFI1_BECN_SMASK) {
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
u32 rqpn, lqpn;
u16 rlid = be16_to_cpu(hdr->lrh[3]);
u8 sl, sc5;
lqpn = bth1 & HFI1_QPN_MASK;
rqpn = qp->remote_qpn;
sc5 = ibp->sl_to_sc[qp->remote_ah_attr.sl];
sl = ibp->sc_to_sl[sc5];
process_becn(ppd, sl, rlid, lqpn, rqpn,
IB_CC_SVCTYPE_UC);
}
if (bth1 & HFI1_FECN_SMASK) {
struct ib_grh *grh = NULL;
u16 pkey = (u16)be32_to_cpu(ohdr->bth[0]);
u16 slid = be16_to_cpu(hdr->lrh[3]);
u16 dlid = be16_to_cpu(hdr->lrh[1]);
u32 src_qp = qp->remote_qpn;
u8 sc5;
sc5 = ibp->sl_to_sc[qp->remote_ah_attr.sl];
if (has_grh)
grh = &hdr->u.l.grh;
return_cnp(ibp, qp, src_qp, pkey, dlid, slid, sc5,
grh);
}
}
psn = be32_to_cpu(ohdr->bth[2]);
opcode = (bth0 >> 24) & 0xff;
if (unlikely(cmp_psn(psn, qp->r_psn) != 0)) {
qp->r_psn = psn;
inv:
if (qp->r_state == OP(SEND_FIRST) ||
qp->r_state == OP(SEND_MIDDLE)) {
set_bit(HFI1_R_REWIND_SGE, &qp->r_aflags);
qp->r_sge.num_sge = 0;
} else
hfi1_put_ss(&qp->r_sge);
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
if (qp->state == IB_QPS_RTR && !(qp->r_flags & HFI1_R_COMM_EST))
qp_comm_est(qp);
switch (opcode) {
case OP(SEND_FIRST):
case OP(SEND_ONLY):
case OP(SEND_ONLY_WITH_IMMEDIATE):
send_first:
if (test_and_clear_bit(HFI1_R_REWIND_SGE, &qp->r_aflags))
qp->r_sge = qp->s_rdma_read_sge;
else {
ret = hfi1_get_rwqe(qp, 0);
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
hfi1_copy_sge(&qp->r_sge, data, pmtu, 0);
break;
case OP(SEND_LAST_WITH_IMMEDIATE):
send_last_imm:
wc.ex.imm_data = ohdr->u.imm_data;
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
hfi1_copy_sge(&qp->r_sge, data, tlen, 0);
hfi1_put_ss(&qp->s_rdma_read_sge);
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
hfi1_cq_enter(to_icq(qp->ibqp.recv_cq), &wc,
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
qp->r_len = be32_to_cpu(reth->length);
qp->r_rcv_len = 0;
qp->r_sge.sg_list = NULL;
if (qp->r_len != 0) {
u32 rkey = be32_to_cpu(reth->rkey);
u64 vaddr = be64_to_cpu(reth->vaddr);
int ok;
ok = hfi1_rkey_ok(qp, &qp->r_sge.sge, qp->r_len,
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
hfi1_copy_sge(&qp->r_sge, data, pmtu, 1);
break;
case OP(RDMA_WRITE_LAST_WITH_IMMEDIATE):
wc.ex.imm_data = ohdr->u.imm_data;
rdma_last_imm:
wc.wc_flags = IB_WC_WITH_IMM;
pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
if (unlikely(tlen < (hdrsize + pad + 4)))
goto drop;
tlen -= (hdrsize + pad + 4);
if (unlikely(tlen + qp->r_rcv_len != qp->r_len))
goto drop;
if (test_and_clear_bit(HFI1_R_REWIND_SGE, &qp->r_aflags))
hfi1_put_ss(&qp->s_rdma_read_sge);
else {
ret = hfi1_get_rwqe(qp, 1);
if (ret < 0)
goto op_err;
if (!ret)
goto drop;
}
wc.byte_len = qp->r_len;
wc.opcode = IB_WC_RECV_RDMA_WITH_IMM;
hfi1_copy_sge(&qp->r_sge, data, tlen, 1);
hfi1_put_ss(&qp->r_sge);
goto last_imm;
case OP(RDMA_WRITE_LAST):
rdma_last:
pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
if (unlikely(tlen < (hdrsize + pad + 4)))
goto drop;
tlen -= (hdrsize + pad + 4);
if (unlikely(tlen + qp->r_rcv_len != qp->r_len))
goto drop;
hfi1_copy_sge(&qp->r_sge, data, tlen, 1);
hfi1_put_ss(&qp->r_sge);
break;
default:
goto drop;
}
qp->r_psn++;
qp->r_state = opcode;
return;
rewind:
set_bit(HFI1_R_REWIND_SGE, &qp->r_aflags);
qp->r_sge.num_sge = 0;
drop:
ibp->n_pkt_drops++;
return;
op_err:
hfi1_rc_error(qp, IB_WC_LOC_QP_OP_ERR);
return;
}
