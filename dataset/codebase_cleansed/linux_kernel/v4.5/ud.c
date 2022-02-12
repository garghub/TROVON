static void ud_loopback(struct hfi1_qp *sqp, struct hfi1_swqe *swqe)
{
struct hfi1_ibport *ibp = to_iport(sqp->ibqp.device, sqp->port_num);
struct hfi1_pportdata *ppd;
struct hfi1_qp *qp;
struct ib_ah_attr *ah_attr;
unsigned long flags;
struct hfi1_sge_state ssge;
struct hfi1_sge *sge;
struct ib_wc wc;
u32 length;
enum ib_qp_type sqptype, dqptype;
rcu_read_lock();
qp = hfi1_lookup_qpn(ibp, swqe->ud_wr.remote_qpn);
if (!qp) {
ibp->n_pkt_drops++;
rcu_read_unlock();
return;
}
sqptype = sqp->ibqp.qp_type == IB_QPT_GSI ?
IB_QPT_UD : sqp->ibqp.qp_type;
dqptype = qp->ibqp.qp_type == IB_QPT_GSI ?
IB_QPT_UD : qp->ibqp.qp_type;
if (dqptype != sqptype ||
!(ib_hfi1_state_ops[qp->state] & HFI1_PROCESS_RECV_OK)) {
ibp->n_pkt_drops++;
goto drop;
}
ah_attr = &to_iah(swqe->ud_wr.ah)->attr;
ppd = ppd_from_ibp(ibp);
if (qp->ibqp.qp_num > 1) {
u16 pkey;
u16 slid;
u8 sc5 = ibp->sl_to_sc[ah_attr->sl];
pkey = hfi1_get_pkey(ibp, sqp->s_pkey_index);
slid = ppd->lid | (ah_attr->src_path_bits &
((1 << ppd->lmc) - 1));
if (unlikely(ingress_pkey_check(ppd, pkey, sc5,
qp->s_pkey_index, slid))) {
hfi1_bad_pqkey(ibp, OPA_TRAP_BAD_P_KEY, pkey,
ah_attr->sl,
sqp->ibqp.qp_num, qp->ibqp.qp_num,
slid, ah_attr->dlid);
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
hfi1_bad_pqkey(ibp, OPA_TRAP_BAD_Q_KEY, qkey,
ah_attr->sl,
sqp->ibqp.qp_num, qp->ibqp.qp_num,
lid,
ah_attr->dlid);
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
if (qp->r_flags & HFI1_R_REUSE_SGE)
qp->r_flags &= ~HFI1_R_REUSE_SGE;
else {
int ret;
ret = hfi1_get_rwqe(qp, 0);
if (ret < 0) {
hfi1_rc_error(qp, IB_WC_LOC_QP_OP_ERR);
goto bail_unlock;
}
if (!ret) {
if (qp->ibqp.qp_num == 0)
ibp->n_vl15_dropped++;
goto bail_unlock;
}
}
if (unlikely(wc.byte_len > qp->r_len)) {
qp->r_flags |= HFI1_R_REUSE_SGE;
ibp->n_pkt_drops++;
goto bail_unlock;
}
if (ah_attr->ah_flags & IB_AH_GRH) {
hfi1_copy_sge(&qp->r_sge, &ah_attr->grh,
sizeof(struct ib_grh), 1);
wc.wc_flags |= IB_WC_GRH;
} else
hfi1_skip_sge(&qp->r_sge, sizeof(struct ib_grh), 1);
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
WARN_ON_ONCE(len == 0);
hfi1_copy_sge(&qp->r_sge, sge->vaddr, len, 1);
sge->vaddr += len;
sge->length -= len;
sge->sge_length -= len;
if (sge->sge_length == 0) {
if (--ssge.num_sge)
*sge = *ssge.sg_list++;
} else if (sge->length == 0 && sge->mr->lkey) {
if (++sge->n >= HFI1_SEGSZ) {
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
hfi1_put_ss(&qp->r_sge);
if (!test_and_clear_bit(HFI1_R_WRID_VALID, &qp->r_aflags))
goto bail_unlock;
wc.wr_id = qp->r_wr_id;
wc.status = IB_WC_SUCCESS;
wc.opcode = IB_WC_RECV;
wc.qp = &qp->ibqp;
wc.src_qp = sqp->ibqp.qp_num;
if (qp->ibqp.qp_type == IB_QPT_GSI || qp->ibqp.qp_type == IB_QPT_SMI) {
if (sqp->ibqp.qp_type == IB_QPT_GSI ||
sqp->ibqp.qp_type == IB_QPT_SMI)
wc.pkey_index = swqe->ud_wr.pkey_index;
else
wc.pkey_index = sqp->s_pkey_index;
} else {
wc.pkey_index = 0;
}
wc.slid = ppd->lid | (ah_attr->src_path_bits & ((1 << ppd->lmc) - 1));
if (wc.slid == 0 && sqp->ibqp.qp_type == IB_QPT_GSI)
wc.slid = HFI1_PERMISSIVE_LID;
wc.sl = ah_attr->sl;
wc.dlid_path_bits = ah_attr->dlid & ((1 << ppd->lmc) - 1);
wc.port_num = qp->port_num;
hfi1_cq_enter(to_icq(qp->ibqp.recv_cq), &wc,
swqe->wr.send_flags & IB_SEND_SOLICITED);
ibp->n_loop_pkts++;
bail_unlock:
spin_unlock_irqrestore(&qp->r_lock, flags);
drop:
rcu_read_unlock();
}
int hfi1_make_ud_req(struct hfi1_qp *qp)
{
struct hfi1_other_headers *ohdr;
struct ib_ah_attr *ah_attr;
struct hfi1_pportdata *ppd;
struct hfi1_ibport *ibp;
struct hfi1_swqe *wqe;
unsigned long flags;
u32 nwords;
u32 extra_bytes;
u32 bth0;
u16 lrh0;
u16 lid;
int ret = 0;
int next_cur;
u8 sc5;
spin_lock_irqsave(&qp->s_lock, flags);
if (!(ib_hfi1_state_ops[qp->state] & HFI1_PROCESS_NEXT_SEND_OK)) {
if (!(ib_hfi1_state_ops[qp->state] & HFI1_FLUSH_SEND))
goto bail;
if (qp->s_last == qp->s_head)
goto bail;
if (atomic_read(&qp->s_iowait.sdma_busy)) {
qp->s_flags |= HFI1_S_WAIT_DMA;
goto bail;
}
wqe = get_swqe_ptr(qp, qp->s_last);
hfi1_send_complete(qp, wqe, IB_WC_WR_FLUSH_ERR);
goto done;
}
if (qp->s_cur == qp->s_head)
goto bail;
wqe = get_swqe_ptr(qp, qp->s_cur);
next_cur = qp->s_cur + 1;
if (next_cur >= qp->s_size)
next_cur = 0;
ibp = to_iport(qp->ibqp.device, qp->port_num);
ppd = ppd_from_ibp(ibp);
ah_attr = &to_iah(wqe->ud_wr.ah)->attr;
if (ah_attr->dlid < HFI1_MULTICAST_LID_BASE ||
ah_attr->dlid == HFI1_PERMISSIVE_LID) {
lid = ah_attr->dlid & ~((1 << ppd->lmc) - 1);
if (unlikely(!loopback && (lid == ppd->lid ||
(lid == HFI1_PERMISSIVE_LID &&
qp->ibqp.qp_type == IB_QPT_GSI)))) {
if (atomic_read(&qp->s_iowait.sdma_busy)) {
qp->s_flags |= HFI1_S_WAIT_DMA;
goto bail;
}
qp->s_cur = next_cur;
spin_unlock_irqrestore(&qp->s_lock, flags);
ud_loopback(qp, wqe);
spin_lock_irqsave(&qp->s_lock, flags);
hfi1_send_complete(qp, wqe, IB_WC_SUCCESS);
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
qp->srate_mbps = ib_rate_to_mbps(qp->s_srate);
qp->s_wqe = wqe;
qp->s_sge.sge = wqe->sg_list[0];
qp->s_sge.sg_list = wqe->sg_list + 1;
qp->s_sge.num_sge = wqe->wr.num_sge;
qp->s_sge.total_len = wqe->length;
if (ah_attr->ah_flags & IB_AH_GRH) {
qp->s_hdrwords += hfi1_make_grh(ibp, &qp->s_hdr->ibh.u.l.grh,
&ah_attr->grh,
qp->s_hdrwords, nwords);
lrh0 = HFI1_LRH_GRH;
ohdr = &qp->s_hdr->ibh.u.l.oth;
} else {
lrh0 = HFI1_LRH_BTH;
ohdr = &qp->s_hdr->ibh.u.oth;
}
if (wqe->wr.opcode == IB_WR_SEND_WITH_IMM) {
qp->s_hdrwords++;
ohdr->u.ud.imm_data = wqe->wr.ex.imm_data;
bth0 = IB_OPCODE_UD_SEND_ONLY_WITH_IMMEDIATE << 24;
} else
bth0 = IB_OPCODE_UD_SEND_ONLY << 24;
sc5 = ibp->sl_to_sc[ah_attr->sl];
lrh0 |= (ah_attr->sl & 0xf) << 4;
if (qp->ibqp.qp_type == IB_QPT_SMI) {
lrh0 |= 0xF000;
qp->s_sc = 0xf;
} else {
lrh0 |= (sc5 & 0xf) << 12;
qp->s_sc = sc5;
}
qp->s_sde = qp_to_sdma_engine(qp, qp->s_sc);
qp->s_hdr->ibh.lrh[0] = cpu_to_be16(lrh0);
qp->s_hdr->ibh.lrh[1] = cpu_to_be16(ah_attr->dlid);
qp->s_hdr->ibh.lrh[2] =
cpu_to_be16(qp->s_hdrwords + nwords + SIZE_OF_CRC);
if (ah_attr->dlid == be16_to_cpu(IB_LID_PERMISSIVE))
qp->s_hdr->ibh.lrh[3] = IB_LID_PERMISSIVE;
else {
lid = ppd->lid;
if (lid) {
lid |= ah_attr->src_path_bits & ((1 << ppd->lmc) - 1);
qp->s_hdr->ibh.lrh[3] = cpu_to_be16(lid);
} else
qp->s_hdr->ibh.lrh[3] = IB_LID_PERMISSIVE;
}
if (wqe->wr.send_flags & IB_SEND_SOLICITED)
bth0 |= IB_BTH_SOLICITED;
bth0 |= extra_bytes << 20;
if (qp->ibqp.qp_type == IB_QPT_GSI || qp->ibqp.qp_type == IB_QPT_SMI)
bth0 |= hfi1_get_pkey(ibp, wqe->ud_wr.pkey_index);
else
bth0 |= hfi1_get_pkey(ibp, qp->s_pkey_index);
ohdr->bth[0] = cpu_to_be32(bth0);
ohdr->bth[1] = cpu_to_be32(wqe->ud_wr.remote_qpn);
ohdr->bth[2] = cpu_to_be32(mask_psn(qp->s_next_psn++));
ohdr->u.ud.deth[0] = cpu_to_be32((int)wqe->ud_wr.remote_qkey < 0 ?
qp->qkey : wqe->ud_wr.remote_qkey);
ohdr->u.ud.deth[1] = cpu_to_be32(qp->ibqp.qp_num);
qp->s_hdr->ahgcount = 0;
qp->s_hdr->ahgidx = 0;
qp->s_hdr->tx_flags = 0;
qp->s_hdr->sde = NULL;
done:
ret = 1;
goto unlock;
bail:
qp->s_flags &= ~HFI1_S_BUSY;
unlock:
spin_unlock_irqrestore(&qp->s_lock, flags);
return ret;
}
int hfi1_lookup_pkey_idx(struct hfi1_ibport *ibp, u16 pkey)
{
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
unsigned i;
if (pkey == FULL_MGMT_P_KEY || pkey == LIM_MGMT_P_KEY) {
unsigned lim_idx = -1;
for (i = 0; i < ARRAY_SIZE(ppd->pkeys); ++i) {
if (ppd->pkeys[i] == pkey)
return i;
if (ppd->pkeys[i] == LIM_MGMT_P_KEY)
lim_idx = i;
}
if (pkey == FULL_MGMT_P_KEY)
return lim_idx;
return -1;
}
pkey &= 0x7fff;
for (i = 0; i < ARRAY_SIZE(ppd->pkeys); ++i)
if ((ppd->pkeys[i] & 0x7fff) == pkey)
return i;
return -1;
}
void return_cnp(struct hfi1_ibport *ibp, struct hfi1_qp *qp, u32 remote_qpn,
u32 pkey, u32 slid, u32 dlid, u8 sc5,
const struct ib_grh *old_grh)
{
u64 pbc, pbc_flags = 0;
u32 bth0, plen, vl, hwords = 5;
u16 lrh0;
u8 sl = ibp->sc_to_sl[sc5];
struct hfi1_ib_header hdr;
struct hfi1_other_headers *ohdr;
struct pio_buf *pbuf;
struct send_context *ctxt = qp_to_send_context(qp, sc5);
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
if (old_grh) {
struct ib_grh *grh = &hdr.u.l.grh;
grh->version_tclass_flow = old_grh->version_tclass_flow;
grh->paylen = cpu_to_be16((hwords - 2 + SIZE_OF_CRC) << 2);
grh->hop_limit = 0xff;
grh->sgid = old_grh->dgid;
grh->dgid = old_grh->sgid;
ohdr = &hdr.u.l.oth;
lrh0 = HFI1_LRH_GRH;
hwords += sizeof(struct ib_grh) / sizeof(u32);
} else {
ohdr = &hdr.u.oth;
lrh0 = HFI1_LRH_BTH;
}
lrh0 |= (sc5 & 0xf) << 12 | sl << 4;
bth0 = pkey | (IB_OPCODE_CNP << 24);
ohdr->bth[0] = cpu_to_be32(bth0);
ohdr->bth[1] = cpu_to_be32(remote_qpn | (1 << HFI1_BECN_SHIFT));
ohdr->bth[2] = 0;
hdr.lrh[0] = cpu_to_be16(lrh0);
hdr.lrh[1] = cpu_to_be16(dlid);
hdr.lrh[2] = cpu_to_be16(hwords + SIZE_OF_CRC);
hdr.lrh[3] = cpu_to_be16(slid);
plen = 2 + hwords;
pbc_flags |= (!!(sc5 & 0x10)) << PBC_DC_INFO_SHIFT;
vl = sc_to_vlt(ppd->dd, sc5);
pbc = create_pbc(ppd, pbc_flags, qp->srate_mbps, vl, plen);
if (ctxt) {
pbuf = sc_buffer_alloc(ctxt, plen, NULL, NULL);
if (pbuf)
ppd->dd->pio_inline_send(ppd->dd, pbuf, pbc,
&hdr, hwords);
}
}
static int opa_smp_check(struct hfi1_ibport *ibp, u16 pkey, u8 sc5,
struct hfi1_qp *qp, u16 slid, struct opa_smp *smp)
{
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
if (sc5 != 0xf)
return 1;
if (rcv_pkey_check(ppd, pkey, sc5, slid))
return 1;
if (smp->mgmt_class != IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE &&
smp->mgmt_class != IB_MGMT_CLASS_SUBN_LID_ROUTED) {
ingress_pkey_table_fail(ppd, pkey, slid);
return 1;
}
switch (smp->method) {
case IB_MGMT_METHOD_GET:
case IB_MGMT_METHOD_SET:
case IB_MGMT_METHOD_REPORT:
case IB_MGMT_METHOD_TRAP_REPRESS:
if (pkey != FULL_MGMT_P_KEY) {
ingress_pkey_table_fail(ppd, pkey, slid);
return 1;
}
break;
case IB_MGMT_METHOD_SEND:
case IB_MGMT_METHOD_TRAP:
case IB_MGMT_METHOD_GET_RESP:
case IB_MGMT_METHOD_REPORT_RESP:
if (ibp->port_cap_flags & IB_PORT_SM)
return 0;
if (pkey == FULL_MGMT_P_KEY) {
smp->status |= IB_SMP_UNSUP_METHOD;
return 0;
}
if (pkey != LIM_MGMT_P_KEY) {
ingress_pkey_table_fail(ppd, pkey, slid);
return 1;
}
break;
default:
break;
}
return 0;
}
void hfi1_ud_rcv(struct hfi1_packet *packet)
{
struct hfi1_other_headers *ohdr = packet->ohdr;
int opcode;
u32 hdrsize = packet->hlen;
u32 pad;
struct ib_wc wc;
u32 qkey;
u32 src_qp;
u16 dlid, pkey;
int mgmt_pkey_idx = -1;
struct hfi1_ibport *ibp = &packet->rcd->ppd->ibport_data;
struct hfi1_ib_header *hdr = packet->hdr;
u32 rcv_flags = packet->rcv_flags;
void *data = packet->ebuf;
u32 tlen = packet->tlen;
struct hfi1_qp *qp = packet->qp;
bool has_grh = rcv_flags & HFI1_HAS_GRH;
bool sc4_bit = has_sc4_bit(packet);
u8 sc;
u32 bth1;
int is_mcast;
struct ib_grh *grh = NULL;
qkey = be32_to_cpu(ohdr->u.ud.deth[0]);
src_qp = be32_to_cpu(ohdr->u.ud.deth[1]) & HFI1_QPN_MASK;
dlid = be16_to_cpu(hdr->lrh[1]);
is_mcast = (dlid > HFI1_MULTICAST_LID_BASE) &&
(dlid != HFI1_PERMISSIVE_LID);
bth1 = be32_to_cpu(ohdr->bth[1]);
if (unlikely(bth1 & HFI1_BECN_SMASK)) {
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
u32 lqpn = be32_to_cpu(ohdr->bth[1]) & HFI1_QPN_MASK;
u8 sl, sc5;
sc5 = (be16_to_cpu(hdr->lrh[0]) >> 12) & 0xf;
sc5 |= sc4_bit;
sl = ibp->sc_to_sl[sc5];
process_becn(ppd, sl, 0, lqpn, 0, IB_CC_SVCTYPE_UD);
}
opcode = be32_to_cpu(ohdr->bth[0]) >> 24;
opcode &= 0xff;
pkey = (u16)be32_to_cpu(ohdr->bth[0]);
if (!is_mcast && (opcode != IB_OPCODE_CNP) && bth1 & HFI1_FECN_SMASK) {
u16 slid = be16_to_cpu(hdr->lrh[3]);
u8 sc5;
sc5 = (be16_to_cpu(hdr->lrh[0]) >> 12) & 0xf;
sc5 |= sc4_bit;
return_cnp(ibp, qp, src_qp, pkey, dlid, slid, sc5, grh);
}
pad = (be32_to_cpu(ohdr->bth[0]) >> 20) & 3;
if (unlikely(tlen < (hdrsize + pad + 4)))
goto drop;
tlen -= hdrsize + pad + 4;
if (qp->ibqp.qp_num) {
if (unlikely(hdr->lrh[1] == IB_LID_PERMISSIVE ||
hdr->lrh[3] == IB_LID_PERMISSIVE))
goto drop;
if (qp->ibqp.qp_num > 1) {
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
u16 slid;
u8 sc5;
sc5 = (be16_to_cpu(hdr->lrh[0]) >> 12) & 0xf;
sc5 |= sc4_bit;
slid = be16_to_cpu(hdr->lrh[3]);
if (unlikely(rcv_pkey_check(ppd, pkey, sc5, slid))) {
hfi1_bad_pqkey(ibp, OPA_TRAP_BAD_P_KEY,
pkey,
(be16_to_cpu(hdr->lrh[0]) >> 4) &
0xF,
src_qp, qp->ibqp.qp_num,
be16_to_cpu(hdr->lrh[3]),
be16_to_cpu(hdr->lrh[1]));
return;
}
} else {
mgmt_pkey_idx = hfi1_lookup_pkey_idx(ibp, pkey);
if (mgmt_pkey_idx < 0)
goto drop;
}
if (unlikely(qkey != qp->qkey)) {
hfi1_bad_pqkey(ibp, OPA_TRAP_BAD_Q_KEY, qkey,
(be16_to_cpu(hdr->lrh[0]) >> 4) & 0xF,
src_qp, qp->ibqp.qp_num,
be16_to_cpu(hdr->lrh[3]),
be16_to_cpu(hdr->lrh[1]));
return;
}
if (unlikely(qp->ibqp.qp_num == 1 &&
(tlen > 2048 ||
(be16_to_cpu(hdr->lrh[0]) >> 12) == 15)))
goto drop;
} else {
struct opa_smp *smp = (struct opa_smp *)data;
u16 slid = be16_to_cpu(hdr->lrh[3]);
u8 sc5;
sc5 = (be16_to_cpu(hdr->lrh[0]) >> 12) & 0xf;
sc5 |= sc4_bit;
if (opa_smp_check(ibp, pkey, sc5, qp, slid, smp))
goto drop;
if (tlen > 2048)
goto drop;
if ((hdr->lrh[1] == IB_LID_PERMISSIVE ||
hdr->lrh[3] == IB_LID_PERMISSIVE) &&
smp->mgmt_class != IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE)
goto drop;
mgmt_pkey_idx = hfi1_lookup_pkey_idx(ibp, pkey);
if (mgmt_pkey_idx < 0)
goto drop;
}
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
if (qp->r_flags & HFI1_R_REUSE_SGE)
qp->r_flags &= ~HFI1_R_REUSE_SGE;
else {
int ret;
ret = hfi1_get_rwqe(qp, 0);
if (ret < 0) {
hfi1_rc_error(qp, IB_WC_LOC_QP_OP_ERR);
return;
}
if (!ret) {
if (qp->ibqp.qp_num == 0)
ibp->n_vl15_dropped++;
return;
}
}
if (unlikely(wc.byte_len > qp->r_len)) {
qp->r_flags |= HFI1_R_REUSE_SGE;
goto drop;
}
if (has_grh) {
hfi1_copy_sge(&qp->r_sge, &hdr->u.l.grh,
sizeof(struct ib_grh), 1);
wc.wc_flags |= IB_WC_GRH;
} else
hfi1_skip_sge(&qp->r_sge, sizeof(struct ib_grh), 1);
hfi1_copy_sge(&qp->r_sge, data, wc.byte_len - sizeof(struct ib_grh), 1);
hfi1_put_ss(&qp->r_sge);
if (!test_and_clear_bit(HFI1_R_WRID_VALID, &qp->r_aflags))
return;
wc.wr_id = qp->r_wr_id;
wc.status = IB_WC_SUCCESS;
wc.opcode = IB_WC_RECV;
wc.vendor_err = 0;
wc.qp = &qp->ibqp;
wc.src_qp = src_qp;
if (qp->ibqp.qp_type == IB_QPT_GSI ||
qp->ibqp.qp_type == IB_QPT_SMI) {
if (mgmt_pkey_idx < 0) {
if (net_ratelimit()) {
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
struct hfi1_devdata *dd = ppd->dd;
dd_dev_err(dd, "QP type %d mgmt_pkey_idx < 0 and packet not dropped???\n",
qp->ibqp.qp_type);
mgmt_pkey_idx = 0;
}
}
wc.pkey_index = (unsigned)mgmt_pkey_idx;
} else
wc.pkey_index = 0;
wc.slid = be16_to_cpu(hdr->lrh[3]);
sc = (be16_to_cpu(hdr->lrh[0]) >> 12) & 0xf;
sc |= sc4_bit;
wc.sl = ibp->sc_to_sl[sc];
wc.dlid_path_bits = dlid >= HFI1_MULTICAST_LID_BASE ? 0 :
dlid & ((1 << ppd_from_ibp(ibp)->lmc) - 1);
wc.port_num = qp->port_num;
hfi1_cq_enter(to_icq(qp->ibqp.recv_cq), &wc,
(ohdr->bth[0] &
cpu_to_be32(IB_BTH_SOLICITED)) != 0);
return;
drop:
ibp->n_pkt_drops++;
}
