static int hfi1_caps_set(const char *val, const struct kernel_param *kp)
{
int ret = 0;
unsigned long *cap_mask_ptr = (unsigned long *)kp->arg,
cap_mask = *cap_mask_ptr, value, diff,
write_mask = ((HFI1_CAP_WRITABLE_MASK << HFI1_CAP_USER_SHIFT) |
HFI1_CAP_WRITABLE_MASK);
ret = kstrtoul(val, 0, &value);
if (ret) {
pr_warn("Invalid module parameter value for 'cap_mask'\n");
goto done;
}
diff = value ^ (cap_mask & ~HFI1_CAP_LOCKED_SMASK);
if (HFI1_CAP_LOCKED() && (diff & ~write_mask)) {
pr_warn("Ignoring non-writable capability bits %#lx\n",
diff & ~write_mask);
diff &= write_mask;
}
diff &= ~HFI1_CAP_RESERVED_MASK;
cap_mask &= ~diff;
cap_mask |= (value & diff);
diff = (cap_mask & (HFI1_CAP_MUST_HAVE_KERN << HFI1_CAP_USER_SHIFT)) ^
((cap_mask & HFI1_CAP_MUST_HAVE_KERN) << HFI1_CAP_USER_SHIFT);
cap_mask &= ~diff;
*cap_mask_ptr = cap_mask;
done:
return ret;
}
static int hfi1_caps_get(char *buffer, const struct kernel_param *kp)
{
unsigned long cap_mask = *(unsigned long *)kp->arg;
cap_mask &= ~HFI1_CAP_LOCKED_SMASK;
cap_mask |= ((cap_mask & HFI1_CAP_K2U) << HFI1_CAP_USER_SHIFT);
return scnprintf(buffer, PAGE_SIZE, "0x%lx", cap_mask);
}
const char *get_unit_name(int unit)
{
static char iname[16];
snprintf(iname, sizeof(iname), DRIVER_NAME "_%u", unit);
return iname;
}
const char *get_card_name(struct rvt_dev_info *rdi)
{
struct hfi1_ibdev *ibdev = container_of(rdi, struct hfi1_ibdev, rdi);
struct hfi1_devdata *dd = container_of(ibdev,
struct hfi1_devdata, verbs_dev);
return get_unit_name(dd->unit);
}
struct pci_dev *get_pci_dev(struct rvt_dev_info *rdi)
{
struct hfi1_ibdev *ibdev = container_of(rdi, struct hfi1_ibdev, rdi);
struct hfi1_devdata *dd = container_of(ibdev,
struct hfi1_devdata, verbs_dev);
return dd->pcidev;
}
int hfi1_count_active_units(void)
{
struct hfi1_devdata *dd;
struct hfi1_pportdata *ppd;
unsigned long flags;
int pidx, nunits_active = 0;
spin_lock_irqsave(&hfi1_devs_lock, flags);
list_for_each_entry(dd, &hfi1_dev_list, list) {
if (!(dd->flags & HFI1_PRESENT) || !dd->kregbase)
continue;
for (pidx = 0; pidx < dd->num_pports; ++pidx) {
ppd = dd->pport + pidx;
if (ppd->lid && ppd->linkup) {
nunits_active++;
break;
}
}
}
spin_unlock_irqrestore(&hfi1_devs_lock, flags);
return nunits_active;
}
int hfi1_count_units(int *npresentp, int *nupp)
{
int nunits = 0, npresent = 0, nup = 0;
struct hfi1_devdata *dd;
unsigned long flags;
int pidx;
struct hfi1_pportdata *ppd;
spin_lock_irqsave(&hfi1_devs_lock, flags);
list_for_each_entry(dd, &hfi1_dev_list, list) {
nunits++;
if ((dd->flags & HFI1_PRESENT) && dd->kregbase)
npresent++;
for (pidx = 0; pidx < dd->num_pports; ++pidx) {
ppd = dd->pport + pidx;
if (ppd->lid && ppd->linkup)
nup++;
}
}
spin_unlock_irqrestore(&hfi1_devs_lock, flags);
if (npresentp)
*npresentp = npresent;
if (nupp)
*nupp = nup;
return nunits;
}
static inline void *get_egrbuf(const struct hfi1_ctxtdata *rcd, u64 rhf,
u8 *update)
{
u32 idx = rhf_egr_index(rhf), offset = rhf_egr_buf_offset(rhf);
*update |= !(idx & (rcd->egrbufs.threshold - 1)) && !offset;
return (void *)(((u64)(rcd->egrbufs.rcvtids[idx].addr)) +
(offset * RCV_BUF_BLOCK_SIZE));
}
inline int hfi1_rcvbuf_validate(u32 size, u8 type, u16 *encoded)
{
if (unlikely(!PAGE_ALIGNED(size)))
return 0;
if (unlikely(size < MIN_EAGER_BUFFER))
return 0;
if (size >
(type == PT_EAGER ? MAX_EAGER_BUFFER : MAX_EXPECTED_BUFFER))
return 0;
if (encoded)
*encoded = ilog2(size / PAGE_SIZE) + 1;
return 1;
}
static void rcv_hdrerr(struct hfi1_ctxtdata *rcd, struct hfi1_pportdata *ppd,
struct hfi1_packet *packet)
{
struct hfi1_message_header *rhdr = packet->hdr;
u32 rte = rhf_rcv_type_err(packet->rhf);
int lnh = be16_to_cpu(rhdr->lrh[0]) & 3;
struct hfi1_ibport *ibp = &ppd->ibport_data;
struct hfi1_devdata *dd = ppd->dd;
struct rvt_dev_info *rdi = &dd->verbs_dev.rdi;
if (packet->rhf & (RHF_VCRC_ERR | RHF_ICRC_ERR))
return;
if (packet->rhf & RHF_TID_ERR) {
struct hfi1_ib_header *hdr = (struct hfi1_ib_header *)rhdr;
struct hfi1_other_headers *ohdr = NULL;
u32 tlen = rhf_pkt_len(packet->rhf);
u16 lid = be16_to_cpu(hdr->lrh[1]);
u32 qp_num;
u32 rcv_flags = 0;
if (tlen < 24)
goto drop;
if (lnh == HFI1_LRH_BTH) {
ohdr = &hdr->u.oth;
} else if (lnh == HFI1_LRH_GRH) {
u32 vtf;
ohdr = &hdr->u.l.oth;
if (hdr->u.l.grh.next_hdr != IB_GRH_NEXT_HDR)
goto drop;
vtf = be32_to_cpu(hdr->u.l.grh.version_tclass_flow);
if ((vtf >> IB_GRH_VERSION_SHIFT) != IB_GRH_VERSION)
goto drop;
rcv_flags |= HFI1_HAS_GRH;
} else {
goto drop;
}
qp_num = be32_to_cpu(ohdr->bth[1]) & RVT_QPN_MASK;
if (lid < be16_to_cpu(IB_MULTICAST_LID_BASE)) {
struct rvt_qp *qp;
unsigned long flags;
rcu_read_lock();
qp = rvt_lookup_qpn(rdi, &ibp->rvp, qp_num);
if (!qp) {
rcu_read_unlock();
goto drop;
}
spin_lock_irqsave(&qp->r_lock, flags);
if (!(ib_rvt_state_ops[qp->state] &
RVT_PROCESS_RECV_OK)) {
ibp->rvp.n_pkt_drops++;
}
switch (qp->ibqp.qp_type) {
case IB_QPT_RC:
hfi1_rc_hdrerr(
rcd,
hdr,
rcv_flags,
qp);
break;
default:
break;
}
spin_unlock_irqrestore(&qp->r_lock, flags);
rcu_read_unlock();
}
}
switch (rte) {
case RHF_RTE_ERROR_OP_CODE_ERR:
{
u32 opcode;
void *ebuf = NULL;
__be32 *bth = NULL;
if (rhf_use_egr_bfr(packet->rhf))
ebuf = packet->ebuf;
if (!ebuf)
goto drop;
if (lnh == HFI1_LRH_BTH)
bth = (__be32 *)ebuf;
else if (lnh == HFI1_LRH_GRH)
bth = (__be32 *)((char *)ebuf + sizeof(struct ib_grh));
else
goto drop;
opcode = be32_to_cpu(bth[0]) >> 24;
opcode &= 0xff;
if (opcode == IB_OPCODE_CNP) {
struct rvt_qp *qp = NULL;
u32 lqpn, rqpn;
u16 rlid;
u8 svc_type, sl, sc5;
sc5 = (be16_to_cpu(rhdr->lrh[0]) >> 12) & 0xf;
if (rhf_dc_info(packet->rhf))
sc5 |= 0x10;
sl = ibp->sc_to_sl[sc5];
lqpn = be32_to_cpu(bth[1]) & RVT_QPN_MASK;
rcu_read_lock();
qp = rvt_lookup_qpn(rdi, &ibp->rvp, lqpn);
if (!qp) {
rcu_read_unlock();
goto drop;
}
switch (qp->ibqp.qp_type) {
case IB_QPT_UD:
rlid = 0;
rqpn = 0;
svc_type = IB_CC_SVCTYPE_UD;
break;
case IB_QPT_UC:
rlid = be16_to_cpu(rhdr->lrh[3]);
rqpn = qp->remote_qpn;
svc_type = IB_CC_SVCTYPE_UC;
break;
default:
goto drop;
}
process_becn(ppd, sl, rlid, lqpn, rqpn, svc_type);
rcu_read_unlock();
}
packet->rhf &= ~RHF_RCV_TYPE_ERR_SMASK;
break;
}
default:
break;
}
drop:
return;
}
static inline void init_packet(struct hfi1_ctxtdata *rcd,
struct hfi1_packet *packet)
{
packet->rsize = rcd->rcvhdrqentsize;
packet->maxcnt = rcd->rcvhdrq_cnt * packet->rsize;
packet->rcd = rcd;
packet->updegr = 0;
packet->etail = -1;
packet->rhf_addr = get_rhf_addr(rcd);
packet->rhf = rhf_to_cpu(packet->rhf_addr);
packet->rhqoff = rcd->head;
packet->numpkt = 0;
packet->rcv_flags = 0;
}
static void process_ecn(struct rvt_qp *qp, struct hfi1_ib_header *hdr,
struct hfi1_other_headers *ohdr,
u64 rhf, u32 bth1, struct ib_grh *grh)
{
struct hfi1_ibport *ibp = to_iport(qp->ibqp.device, qp->port_num);
u32 rqpn = 0;
u16 rlid;
u8 sc5, svc_type;
switch (qp->ibqp.qp_type) {
case IB_QPT_SMI:
case IB_QPT_GSI:
case IB_QPT_UD:
rlid = be16_to_cpu(hdr->lrh[3]);
rqpn = be32_to_cpu(ohdr->u.ud.deth[1]) & RVT_QPN_MASK;
svc_type = IB_CC_SVCTYPE_UD;
break;
case IB_QPT_UC:
rlid = qp->remote_ah_attr.dlid;
rqpn = qp->remote_qpn;
svc_type = IB_CC_SVCTYPE_UC;
break;
case IB_QPT_RC:
rlid = qp->remote_ah_attr.dlid;
rqpn = qp->remote_qpn;
svc_type = IB_CC_SVCTYPE_RC;
break;
default:
return;
}
sc5 = (be16_to_cpu(hdr->lrh[0]) >> 12) & 0xf;
if (rhf_dc_info(rhf))
sc5 |= 0x10;
if (bth1 & HFI1_FECN_SMASK) {
u16 pkey = (u16)be32_to_cpu(ohdr->bth[0]);
u16 dlid = be16_to_cpu(hdr->lrh[1]);
return_cnp(ibp, qp, rqpn, pkey, dlid, rlid, sc5, grh);
}
if (bth1 & HFI1_BECN_SMASK) {
struct hfi1_pportdata *ppd = ppd_from_ibp(ibp);
u32 lqpn = bth1 & RVT_QPN_MASK;
u8 sl = ibp->sc_to_sl[sc5];
process_becn(ppd, sl, rlid, lqpn, rqpn, svc_type);
}
}
static inline void init_ps_mdata(struct ps_mdata *mdata,
struct hfi1_packet *packet)
{
struct hfi1_ctxtdata *rcd = packet->rcd;
mdata->rcd = rcd;
mdata->rsize = packet->rsize;
mdata->maxcnt = packet->maxcnt;
mdata->ps_head = packet->rhqoff;
if (HFI1_CAP_KGET_MASK(rcd->flags, DMA_RTAIL)) {
mdata->ps_tail = get_rcvhdrtail(rcd);
if (rcd->ctxt == HFI1_CTRL_CTXT)
mdata->ps_seq = rcd->seq_cnt;
else
mdata->ps_seq = 0;
} else {
mdata->ps_tail = 0;
mdata->ps_seq = rcd->seq_cnt;
}
}
static inline int ps_done(struct ps_mdata *mdata, u64 rhf,
struct hfi1_ctxtdata *rcd)
{
if (HFI1_CAP_KGET_MASK(rcd->flags, DMA_RTAIL))
return mdata->ps_head == mdata->ps_tail;
return mdata->ps_seq != rhf_rcv_seq(rhf);
}
static inline int ps_skip(struct ps_mdata *mdata, u64 rhf,
struct hfi1_ctxtdata *rcd)
{
if ((rcd->ctxt == HFI1_CTRL_CTXT) && (mdata->ps_head != mdata->ps_tail))
return mdata->ps_seq != rhf_rcv_seq(rhf);
return 0;
}
static inline void update_ps_mdata(struct ps_mdata *mdata,
struct hfi1_ctxtdata *rcd)
{
mdata->ps_head += mdata->rsize;
if (mdata->ps_head >= mdata->maxcnt)
mdata->ps_head = 0;
if (!HFI1_CAP_KGET_MASK(rcd->flags, DMA_RTAIL) ||
(rcd->ctxt == HFI1_CTRL_CTXT)) {
if (++mdata->ps_seq > 13)
mdata->ps_seq = 1;
}
}
static void __prescan_rxq(struct hfi1_packet *packet)
{
struct hfi1_ctxtdata *rcd = packet->rcd;
struct ps_mdata mdata;
init_ps_mdata(&mdata, packet);
while (1) {
struct hfi1_devdata *dd = rcd->dd;
struct hfi1_ibport *ibp = &rcd->ppd->ibport_data;
__le32 *rhf_addr = (__le32 *)rcd->rcvhdrq + mdata.ps_head +
dd->rhf_offset;
struct rvt_qp *qp;
struct hfi1_ib_header *hdr;
struct hfi1_other_headers *ohdr;
struct ib_grh *grh = NULL;
struct rvt_dev_info *rdi = &dd->verbs_dev.rdi;
u64 rhf = rhf_to_cpu(rhf_addr);
u32 etype = rhf_rcv_type(rhf), qpn, bth1;
int is_ecn = 0;
u8 lnh;
if (ps_done(&mdata, rhf, rcd))
break;
if (ps_skip(&mdata, rhf, rcd))
goto next;
if (etype != RHF_RCV_TYPE_IB)
goto next;
hdr = (struct hfi1_ib_header *)
hfi1_get_msgheader(dd, rhf_addr);
lnh = be16_to_cpu(hdr->lrh[0]) & 3;
if (lnh == HFI1_LRH_BTH) {
ohdr = &hdr->u.oth;
} else if (lnh == HFI1_LRH_GRH) {
ohdr = &hdr->u.l.oth;
grh = &hdr->u.l.grh;
} else {
goto next;
}
bth1 = be32_to_cpu(ohdr->bth[1]);
is_ecn = !!(bth1 & (HFI1_FECN_SMASK | HFI1_BECN_SMASK));
if (!is_ecn)
goto next;
qpn = bth1 & RVT_QPN_MASK;
rcu_read_lock();
qp = rvt_lookup_qpn(rdi, &ibp->rvp, qpn);
if (!qp) {
rcu_read_unlock();
goto next;
}
process_ecn(qp, hdr, ohdr, rhf, bth1, grh);
rcu_read_unlock();
bth1 &= ~(HFI1_FECN_SMASK | HFI1_BECN_SMASK);
ohdr->bth[1] = cpu_to_be32(bth1);
next:
update_ps_mdata(&mdata, rcd);
}
}
static inline int skip_rcv_packet(struct hfi1_packet *packet, int thread)
{
int ret = RCV_PKT_OK;
packet->rhqoff += packet->rsize;
if (packet->rhqoff >= packet->maxcnt)
packet->rhqoff = 0;
packet->numpkt++;
if (unlikely((packet->numpkt & (MAX_PKT_RECV - 1)) == 0)) {
if (thread) {
cond_resched();
} else {
ret = RCV_PKT_LIMIT;
this_cpu_inc(*packet->rcd->dd->rcv_limit);
}
}
packet->rhf_addr = (__le32 *)packet->rcd->rcvhdrq + packet->rhqoff +
packet->rcd->dd->rhf_offset;
packet->rhf = rhf_to_cpu(packet->rhf_addr);
return ret;
}
static inline int process_rcv_packet(struct hfi1_packet *packet, int thread)
{
int ret = RCV_PKT_OK;
packet->hdr = hfi1_get_msgheader(packet->rcd->dd,
packet->rhf_addr);
packet->hlen = (u8 *)packet->rhf_addr - (u8 *)packet->hdr;
packet->etype = rhf_rcv_type(packet->rhf);
packet->tlen = rhf_pkt_len(packet->rhf);
packet->ebuf = NULL;
if (rhf_use_egr_bfr(packet->rhf)) {
packet->etail = rhf_egr_index(packet->rhf);
packet->ebuf = get_egrbuf(packet->rcd, packet->rhf,
&packet->updegr);
prefetch_range(packet->ebuf,
packet->tlen - ((packet->rcd->rcvhdrqentsize -
(rhf_hdrq_offset(packet->rhf)
+ 2)) * 4));
}
packet->rcd->dd->rhf_rcv_function_map[packet->etype](packet);
packet->numpkt++;
packet->rhqoff += packet->rsize;
if (packet->rhqoff >= packet->maxcnt)
packet->rhqoff = 0;
if (unlikely((packet->numpkt & (MAX_PKT_RECV - 1)) == 0)) {
if (thread) {
cond_resched();
} else {
ret = RCV_PKT_LIMIT;
this_cpu_inc(*packet->rcd->dd->rcv_limit);
}
}
packet->rhf_addr = (__le32 *)packet->rcd->rcvhdrq + packet->rhqoff +
packet->rcd->dd->rhf_offset;
packet->rhf = rhf_to_cpu(packet->rhf_addr);
return ret;
}
static inline void process_rcv_update(int last, struct hfi1_packet *packet)
{
if (!last && !(packet->numpkt & 0xf)) {
update_usrhead(packet->rcd, packet->rhqoff, packet->updegr,
packet->etail, 0, 0);
packet->updegr = 0;
}
packet->rcv_flags = 0;
}
static inline void finish_packet(struct hfi1_packet *packet)
{
update_usrhead(packet->rcd, packet->rcd->head, packet->updegr,
packet->etail, rcv_intr_dynamic, packet->numpkt);
}
static inline void process_rcv_qp_work(struct hfi1_packet *packet)
{
struct hfi1_ctxtdata *rcd;
struct rvt_qp *qp, *nqp;
rcd = packet->rcd;
rcd->head = packet->rhqoff;
list_for_each_entry_safe(qp, nqp, &rcd->qp_wait_list, rspwait) {
list_del_init(&qp->rspwait);
if (qp->r_flags & RVT_R_RSP_NAK) {
qp->r_flags &= ~RVT_R_RSP_NAK;
hfi1_send_rc_ack(rcd, qp, 0);
}
if (qp->r_flags & RVT_R_RSP_SEND) {
unsigned long flags;
qp->r_flags &= ~RVT_R_RSP_SEND;
spin_lock_irqsave(&qp->s_lock, flags);
if (ib_rvt_state_ops[qp->state] &
RVT_PROCESS_OR_FLUSH_SEND)
hfi1_schedule_send(qp);
spin_unlock_irqrestore(&qp->s_lock, flags);
}
if (atomic_dec_and_test(&qp->refcount))
wake_up(&qp->wait);
}
}
int handle_receive_interrupt_nodma_rtail(struct hfi1_ctxtdata *rcd, int thread)
{
u32 seq;
int last = RCV_PKT_OK;
struct hfi1_packet packet;
init_packet(rcd, &packet);
seq = rhf_rcv_seq(packet.rhf);
if (seq != rcd->seq_cnt) {
last = RCV_PKT_DONE;
goto bail;
}
prescan_rxq(rcd, &packet);
while (last == RCV_PKT_OK) {
last = process_rcv_packet(&packet, thread);
seq = rhf_rcv_seq(packet.rhf);
if (++rcd->seq_cnt > 13)
rcd->seq_cnt = 1;
if (seq != rcd->seq_cnt)
last = RCV_PKT_DONE;
process_rcv_update(last, &packet);
}
process_rcv_qp_work(&packet);
bail:
finish_packet(&packet);
return last;
}
int handle_receive_interrupt_dma_rtail(struct hfi1_ctxtdata *rcd, int thread)
{
u32 hdrqtail;
int last = RCV_PKT_OK;
struct hfi1_packet packet;
init_packet(rcd, &packet);
hdrqtail = get_rcvhdrtail(rcd);
if (packet.rhqoff == hdrqtail) {
last = RCV_PKT_DONE;
goto bail;
}
smp_rmb();
prescan_rxq(rcd, &packet);
while (last == RCV_PKT_OK) {
last = process_rcv_packet(&packet, thread);
if (packet.rhqoff == hdrqtail)
last = RCV_PKT_DONE;
process_rcv_update(last, &packet);
}
process_rcv_qp_work(&packet);
bail:
finish_packet(&packet);
return last;
}
static inline void set_all_nodma_rtail(struct hfi1_devdata *dd)
{
int i;
for (i = HFI1_CTRL_CTXT + 1; i < dd->first_user_ctxt; i++)
dd->rcd[i]->do_interrupt =
&handle_receive_interrupt_nodma_rtail;
}
static inline void set_all_dma_rtail(struct hfi1_devdata *dd)
{
int i;
for (i = HFI1_CTRL_CTXT + 1; i < dd->first_user_ctxt; i++)
dd->rcd[i]->do_interrupt =
&handle_receive_interrupt_dma_rtail;
}
void set_all_slowpath(struct hfi1_devdata *dd)
{
int i;
for (i = HFI1_CTRL_CTXT + 1; i < dd->first_user_ctxt; i++)
dd->rcd[i]->do_interrupt = &handle_receive_interrupt;
}
static inline int set_armed_to_active(struct hfi1_ctxtdata *rcd,
struct hfi1_packet packet,
struct hfi1_devdata *dd)
{
struct work_struct *lsaw = &rcd->ppd->linkstate_active_work;
struct hfi1_message_header *hdr = hfi1_get_msgheader(packet.rcd->dd,
packet.rhf_addr);
if (hdr2sc(hdr, packet.rhf) != 0xf) {
int hwstate = read_logical_state(dd);
if (hwstate != LSTATE_ACTIVE) {
dd_dev_info(dd, "Unexpected link state %d\n", hwstate);
return 0;
}
queue_work(rcd->ppd->hfi1_wq, lsaw);
return 1;
}
return 0;
}
int handle_receive_interrupt(struct hfi1_ctxtdata *rcd, int thread)
{
struct hfi1_devdata *dd = rcd->dd;
u32 hdrqtail;
int needset, last = RCV_PKT_OK;
struct hfi1_packet packet;
int skip_pkt = 0;
needset = (rcd->ctxt == HFI1_CTRL_CTXT) ? 0 : 1;
init_packet(rcd, &packet);
if (!HFI1_CAP_KGET_MASK(rcd->flags, DMA_RTAIL)) {
u32 seq = rhf_rcv_seq(packet.rhf);
if (seq != rcd->seq_cnt) {
last = RCV_PKT_DONE;
goto bail;
}
hdrqtail = 0;
} else {
hdrqtail = get_rcvhdrtail(rcd);
if (packet.rhqoff == hdrqtail) {
last = RCV_PKT_DONE;
goto bail;
}
smp_rmb();
if (rcd->ctxt == HFI1_CTRL_CTXT) {
u32 seq = rhf_rcv_seq(packet.rhf);
if (seq != rcd->seq_cnt)
skip_pkt = 1;
}
}
prescan_rxq(rcd, &packet);
while (last == RCV_PKT_OK) {
if (unlikely(dd->do_drop &&
atomic_xchg(&dd->drop_packet, DROP_PACKET_OFF) ==
DROP_PACKET_ON)) {
dd->do_drop = 0;
packet.rhqoff += packet.rsize;
packet.rhf_addr = (__le32 *)rcd->rcvhdrq +
packet.rhqoff +
dd->rhf_offset;
packet.rhf = rhf_to_cpu(packet.rhf_addr);
} else if (skip_pkt) {
last = skip_rcv_packet(&packet, thread);
skip_pkt = 0;
} else {
if (unlikely(rcd->ppd->host_link_state ==
HLS_UP_ARMED) &&
set_armed_to_active(rcd, packet, dd))
goto bail;
last = process_rcv_packet(&packet, thread);
}
if (!HFI1_CAP_KGET_MASK(rcd->flags, DMA_RTAIL)) {
u32 seq = rhf_rcv_seq(packet.rhf);
if (++rcd->seq_cnt > 13)
rcd->seq_cnt = 1;
if (seq != rcd->seq_cnt)
last = RCV_PKT_DONE;
if (needset) {
dd_dev_info(dd, "Switching to NO_DMA_RTAIL\n");
set_all_nodma_rtail(dd);
needset = 0;
}
} else {
if (packet.rhqoff == hdrqtail)
last = RCV_PKT_DONE;
if (rcd->ctxt == HFI1_CTRL_CTXT) {
u32 seq = rhf_rcv_seq(packet.rhf);
if (++rcd->seq_cnt > 13)
rcd->seq_cnt = 1;
if (!last && (seq != rcd->seq_cnt))
skip_pkt = 1;
}
if (needset) {
dd_dev_info(dd,
"Switching to DMA_RTAIL\n");
set_all_dma_rtail(dd);
needset = 0;
}
}
process_rcv_update(last, &packet);
}
process_rcv_qp_work(&packet);
bail:
finish_packet(&packet);
return last;
}
void receive_interrupt_work(struct work_struct *work)
{
struct hfi1_pportdata *ppd = container_of(work, struct hfi1_pportdata,
linkstate_active_work);
struct hfi1_devdata *dd = ppd->dd;
int i;
ppd->neighbor_normal = 1;
set_link_state(ppd, HLS_UP_ACTIVE);
for (i = HFI1_CTRL_CTXT; i < dd->first_user_ctxt; i++)
force_recv_intr(dd->rcd[i]);
}
int mtu_to_enum(u32 mtu, int default_if_bad)
{
switch (mtu) {
case 0: return OPA_MTU_0;
case 256: return OPA_MTU_256;
case 512: return OPA_MTU_512;
case 1024: return OPA_MTU_1024;
case 2048: return OPA_MTU_2048;
case 4096: return OPA_MTU_4096;
case 8192: return OPA_MTU_8192;
case 10240: return OPA_MTU_10240;
}
return default_if_bad;
}
u16 enum_to_mtu(int mtu)
{
switch (mtu) {
case OPA_MTU_0: return 0;
case OPA_MTU_256: return 256;
case OPA_MTU_512: return 512;
case OPA_MTU_1024: return 1024;
case OPA_MTU_2048: return 2048;
case OPA_MTU_4096: return 4096;
case OPA_MTU_8192: return 8192;
case OPA_MTU_10240: return 10240;
default: return 0xffff;
}
}
int set_mtu(struct hfi1_pportdata *ppd)
{
struct hfi1_devdata *dd = ppd->dd;
int i, drain, ret = 0, is_up = 0;
ppd->ibmtu = 0;
for (i = 0; i < ppd->vls_supported; i++)
if (ppd->ibmtu < dd->vld[i].mtu)
ppd->ibmtu = dd->vld[i].mtu;
ppd->ibmaxlen = ppd->ibmtu + lrh_max_header_bytes(ppd->dd);
mutex_lock(&ppd->hls_lock);
if (ppd->host_link_state == HLS_UP_INIT ||
ppd->host_link_state == HLS_UP_ARMED ||
ppd->host_link_state == HLS_UP_ACTIVE)
is_up = 1;
drain = !is_ax(dd) && is_up;
if (drain)
ret = stop_drain_data_vls(dd);
if (ret) {
dd_dev_err(dd, "%s: cannot stop/drain VLs - refusing to change per-VL MTUs\n",
__func__);
goto err;
}
hfi1_set_ib_cfg(ppd, HFI1_IB_CFG_MTU, 0);
if (drain)
open_fill_data_vls(dd);
err:
mutex_unlock(&ppd->hls_lock);
return ret;
}
int hfi1_set_lid(struct hfi1_pportdata *ppd, u32 lid, u8 lmc)
{
struct hfi1_devdata *dd = ppd->dd;
ppd->lid = lid;
ppd->lmc = lmc;
hfi1_set_ib_cfg(ppd, HFI1_IB_CFG_LIDLMC, 0);
dd_dev_info(dd, "port %u: got a lid: 0x%x\n", ppd->port, lid);
return 0;
}
void shutdown_led_override(struct hfi1_pportdata *ppd)
{
struct hfi1_devdata *dd = ppd->dd;
smp_rmb();
if (atomic_read(&ppd->led_override_timer_active)) {
del_timer_sync(&ppd->led_override_timer);
atomic_set(&ppd->led_override_timer_active, 0);
smp_wmb();
}
write_csr(dd, DCC_CFG_LED_CNTRL, 0);
}
static void run_led_override(unsigned long opaque)
{
struct hfi1_pportdata *ppd = (struct hfi1_pportdata *)opaque;
struct hfi1_devdata *dd = ppd->dd;
unsigned long timeout;
int phase_idx;
if (!(dd->flags & HFI1_INITTED))
return;
phase_idx = ppd->led_override_phase & 1;
setextled(dd, phase_idx);
timeout = ppd->led_override_vals[phase_idx];
ppd->led_override_phase = !ppd->led_override_phase;
mod_timer(&ppd->led_override_timer, jiffies + timeout);
}
void hfi1_start_led_override(struct hfi1_pportdata *ppd, unsigned int timeon,
unsigned int timeoff)
{
if (!(ppd->dd->flags & HFI1_INITTED))
return;
ppd->led_override_vals[0] = msecs_to_jiffies(timeoff);
ppd->led_override_vals[1] = msecs_to_jiffies(timeon);
ppd->led_override_phase = 1;
if (!timer_pending(&ppd->led_override_timer)) {
setup_timer(&ppd->led_override_timer, run_led_override,
(unsigned long)ppd);
ppd->led_override_timer.expires = jiffies + 1;
add_timer(&ppd->led_override_timer);
atomic_set(&ppd->led_override_timer_active, 1);
smp_wmb();
}
}
int hfi1_reset_device(int unit)
{
int ret, i;
struct hfi1_devdata *dd = hfi1_lookup(unit);
struct hfi1_pportdata *ppd;
unsigned long flags;
int pidx;
if (!dd) {
ret = -ENODEV;
goto bail;
}
dd_dev_info(dd, "Reset on unit %u requested\n", unit);
if (!dd->kregbase || !(dd->flags & HFI1_PRESENT)) {
dd_dev_info(dd,
"Invalid unit number %u or not initialized or not present\n",
unit);
ret = -ENXIO;
goto bail;
}
spin_lock_irqsave(&dd->uctxt_lock, flags);
if (dd->rcd)
for (i = dd->first_user_ctxt; i < dd->num_rcv_contexts; i++) {
if (!dd->rcd[i] || !dd->rcd[i]->cnt)
continue;
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
ret = -EBUSY;
goto bail;
}
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
for (pidx = 0; pidx < dd->num_pports; ++pidx) {
ppd = dd->pport + pidx;
shutdown_led_override(ppd);
}
if (dd->flags & HFI1_HAS_SEND_DMA)
sdma_exit(dd);
hfi1_reset_cpu_counters(dd);
ret = hfi1_init(dd, 1);
if (ret)
dd_dev_err(dd,
"Reinitialize unit %u after reset failed with %d\n",
unit, ret);
else
dd_dev_info(dd, "Reinitialized unit %u after resetting\n",
unit);
bail:
return ret;
}
void handle_eflags(struct hfi1_packet *packet)
{
struct hfi1_ctxtdata *rcd = packet->rcd;
u32 rte = rhf_rcv_type_err(packet->rhf);
rcv_hdrerr(rcd, rcd->ppd, packet);
if (rhf_err_flags(packet->rhf))
dd_dev_err(rcd->dd,
"receive context %d: rhf 0x%016llx, errs [ %s%s%s%s%s%s%s%s] rte 0x%x\n",
rcd->ctxt, packet->rhf,
packet->rhf & RHF_K_HDR_LEN_ERR ? "k_hdr_len " : "",
packet->rhf & RHF_DC_UNC_ERR ? "dc_unc " : "",
packet->rhf & RHF_DC_ERR ? "dc " : "",
packet->rhf & RHF_TID_ERR ? "tid " : "",
packet->rhf & RHF_LEN_ERR ? "len " : "",
packet->rhf & RHF_ECC_ERR ? "ecc " : "",
packet->rhf & RHF_VCRC_ERR ? "vcrc " : "",
packet->rhf & RHF_ICRC_ERR ? "icrc " : "",
rte);
}
int process_receive_ib(struct hfi1_packet *packet)
{
trace_hfi1_rcvhdr(packet->rcd->ppd->dd,
packet->rcd->ctxt,
rhf_err_flags(packet->rhf),
RHF_RCV_TYPE_IB,
packet->hlen,
packet->tlen,
packet->updegr,
rhf_egr_index(packet->rhf));
if (unlikely(rhf_err_flags(packet->rhf))) {
handle_eflags(packet);
return RHF_RCV_CONTINUE;
}
hfi1_ib_rcv(packet);
return RHF_RCV_CONTINUE;
}
int process_receive_bypass(struct hfi1_packet *packet)
{
if (unlikely(rhf_err_flags(packet->rhf)))
handle_eflags(packet);
dd_dev_err(packet->rcd->dd,
"Bypass packets are not supported in normal operation. Dropping\n");
return RHF_RCV_CONTINUE;
}
int process_receive_error(struct hfi1_packet *packet)
{
handle_eflags(packet);
if (unlikely(rhf_err_flags(packet->rhf)))
dd_dev_err(packet->rcd->dd,
"Unhandled error packet received. Dropping.\n");
return RHF_RCV_CONTINUE;
}
int kdeth_process_expected(struct hfi1_packet *packet)
{
if (unlikely(rhf_err_flags(packet->rhf)))
handle_eflags(packet);
dd_dev_err(packet->rcd->dd,
"Unhandled expected packet received. Dropping.\n");
return RHF_RCV_CONTINUE;
}
int kdeth_process_eager(struct hfi1_packet *packet)
{
if (unlikely(rhf_err_flags(packet->rhf)))
handle_eflags(packet);
dd_dev_err(packet->rcd->dd,
"Unhandled eager packet received. Dropping.\n");
return RHF_RCV_CONTINUE;
}
int process_receive_invalid(struct hfi1_packet *packet)
{
dd_dev_err(packet->rcd->dd, "Invalid packet type %d. Dropping\n",
rhf_rcv_type(packet->rhf));
return RHF_RCV_CONTINUE;
}
