void qed_iwarp_init_devinfo(struct qed_hwfn *p_hwfn)
{
struct qed_rdma_device *dev = p_hwfn->p_rdma_info->dev;
dev->max_inline = IWARP_REQ_MAX_INLINE_DATA_SIZE;
dev->max_qp = min_t(u32,
IWARP_MAX_QPS,
p_hwfn->p_rdma_info->num_qps) -
QED_IWARP_PREALLOC_CNT;
dev->max_cq = dev->max_qp;
dev->max_qp_resp_rd_atomic_resc = QED_IWARP_IRD_DEFAULT;
dev->max_qp_req_rd_atomic_resc = QED_IWARP_ORD_DEFAULT;
}
void qed_iwarp_init_hw(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt)
{
p_hwfn->rdma_prs_search_reg = PRS_REG_SEARCH_TCP;
qed_wr(p_hwfn, p_ptt, p_hwfn->rdma_prs_search_reg, 1);
p_hwfn->b_rdma_enabled_in_prs = true;
}
static void qed_iwarp_cid_cleaned(struct qed_hwfn *p_hwfn, u32 cid)
{
cid -= qed_cxt_get_proto_cid_start(p_hwfn, p_hwfn->p_rdma_info->proto);
spin_lock_bh(&p_hwfn->p_rdma_info->lock);
if (cid < QED_IWARP_PREALLOC_CNT)
qed_bmap_release_id(p_hwfn, &p_hwfn->p_rdma_info->tcp_cid_map,
cid);
else
qed_bmap_release_id(p_hwfn, &p_hwfn->p_rdma_info->cid_map, cid);
spin_unlock_bh(&p_hwfn->p_rdma_info->lock);
}
static int qed_iwarp_alloc_cid(struct qed_hwfn *p_hwfn, u32 *cid)
{
int rc;
spin_lock_bh(&p_hwfn->p_rdma_info->lock);
rc = qed_rdma_bmap_alloc_id(p_hwfn, &p_hwfn->p_rdma_info->cid_map, cid);
spin_unlock_bh(&p_hwfn->p_rdma_info->lock);
if (rc) {
DP_NOTICE(p_hwfn, "Failed in allocating iwarp cid\n");
return rc;
}
*cid += qed_cxt_get_proto_cid_start(p_hwfn, p_hwfn->p_rdma_info->proto);
rc = qed_cxt_dynamic_ilt_alloc(p_hwfn, QED_ELEM_CXT, *cid);
if (rc)
qed_iwarp_cid_cleaned(p_hwfn, *cid);
return rc;
}
static void qed_iwarp_set_tcp_cid(struct qed_hwfn *p_hwfn, u32 cid)
{
cid -= qed_cxt_get_proto_cid_start(p_hwfn, p_hwfn->p_rdma_info->proto);
spin_lock_bh(&p_hwfn->p_rdma_info->lock);
qed_bmap_set_id(p_hwfn, &p_hwfn->p_rdma_info->tcp_cid_map, cid);
spin_unlock_bh(&p_hwfn->p_rdma_info->lock);
}
static int qed_iwarp_alloc_tcp_cid(struct qed_hwfn *p_hwfn, u32 *cid)
{
int rc;
spin_lock_bh(&p_hwfn->p_rdma_info->lock);
rc = qed_rdma_bmap_alloc_id(p_hwfn,
&p_hwfn->p_rdma_info->tcp_cid_map, cid);
spin_unlock_bh(&p_hwfn->p_rdma_info->lock);
if (rc) {
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"can't allocate iwarp tcp cid max-count=%d\n",
p_hwfn->p_rdma_info->tcp_cid_map.max_count);
*cid = QED_IWARP_INVALID_TCP_CID;
return rc;
}
*cid += qed_cxt_get_proto_cid_start(p_hwfn,
p_hwfn->p_rdma_info->proto);
return 0;
}
int qed_iwarp_create_qp(struct qed_hwfn *p_hwfn,
struct qed_rdma_qp *qp,
struct qed_rdma_create_qp_out_params *out_params)
{
struct iwarp_create_qp_ramrod_data *p_ramrod;
struct qed_sp_init_data init_data;
struct qed_spq_entry *p_ent;
u16 physical_queue;
u32 cid;
int rc;
qp->shared_queue = dma_alloc_coherent(&p_hwfn->cdev->pdev->dev,
IWARP_SHARED_QUEUE_PAGE_SIZE,
&qp->shared_queue_phys_addr,
GFP_KERNEL);
if (!qp->shared_queue)
return -ENOMEM;
out_params->sq_pbl_virt = (u8 *)qp->shared_queue +
IWARP_SHARED_QUEUE_PAGE_SQ_PBL_OFFSET;
out_params->sq_pbl_phys = qp->shared_queue_phys_addr +
IWARP_SHARED_QUEUE_PAGE_SQ_PBL_OFFSET;
out_params->rq_pbl_virt = (u8 *)qp->shared_queue +
IWARP_SHARED_QUEUE_PAGE_RQ_PBL_OFFSET;
out_params->rq_pbl_phys = qp->shared_queue_phys_addr +
IWARP_SHARED_QUEUE_PAGE_RQ_PBL_OFFSET;
rc = qed_iwarp_alloc_cid(p_hwfn, &cid);
if (rc)
goto err1;
qp->icid = (u16)cid;
memset(&init_data, 0, sizeof(init_data));
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.cid = qp->icid;
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
IWARP_RAMROD_CMD_ID_CREATE_QP,
PROTOCOLID_IWARP, &init_data);
if (rc)
goto err2;
p_ramrod = &p_ent->ramrod.iwarp_create_qp;
SET_FIELD(p_ramrod->flags,
IWARP_CREATE_QP_RAMROD_DATA_FMR_AND_RESERVED_EN,
qp->fmr_and_reserved_lkey);
SET_FIELD(p_ramrod->flags,
IWARP_CREATE_QP_RAMROD_DATA_SIGNALED_COMP, qp->signal_all);
SET_FIELD(p_ramrod->flags,
IWARP_CREATE_QP_RAMROD_DATA_RDMA_RD_EN,
qp->incoming_rdma_read_en);
SET_FIELD(p_ramrod->flags,
IWARP_CREATE_QP_RAMROD_DATA_RDMA_WR_EN,
qp->incoming_rdma_write_en);
SET_FIELD(p_ramrod->flags,
IWARP_CREATE_QP_RAMROD_DATA_ATOMIC_EN,
qp->incoming_atomic_en);
SET_FIELD(p_ramrod->flags,
IWARP_CREATE_QP_RAMROD_DATA_SRQ_FLG, qp->use_srq);
p_ramrod->pd = qp->pd;
p_ramrod->sq_num_pages = qp->sq_num_pages;
p_ramrod->rq_num_pages = qp->rq_num_pages;
p_ramrod->qp_handle_for_cqe.hi = cpu_to_le32(qp->qp_handle.hi);
p_ramrod->qp_handle_for_cqe.lo = cpu_to_le32(qp->qp_handle.lo);
p_ramrod->cq_cid_for_sq =
cpu_to_le32((p_hwfn->hw_info.opaque_fid << 16) | qp->sq_cq_id);
p_ramrod->cq_cid_for_rq =
cpu_to_le32((p_hwfn->hw_info.opaque_fid << 16) | qp->rq_cq_id);
p_ramrod->dpi = cpu_to_le16(qp->dpi);
physical_queue = qed_get_cm_pq_idx(p_hwfn, PQ_FLAGS_OFLD);
p_ramrod->physical_q0 = cpu_to_le16(physical_queue);
physical_queue = qed_get_cm_pq_idx(p_hwfn, PQ_FLAGS_ACK);
p_ramrod->physical_q1 = cpu_to_le16(physical_queue);
rc = qed_spq_post(p_hwfn, p_ent, NULL);
if (rc)
goto err2;
return rc;
err2:
qed_iwarp_cid_cleaned(p_hwfn, cid);
err1:
dma_free_coherent(&p_hwfn->cdev->pdev->dev,
IWARP_SHARED_QUEUE_PAGE_SIZE,
qp->shared_queue, qp->shared_queue_phys_addr);
return rc;
}
static int qed_iwarp_modify_fw(struct qed_hwfn *p_hwfn, struct qed_rdma_qp *qp)
{
struct iwarp_modify_qp_ramrod_data *p_ramrod;
struct qed_sp_init_data init_data;
struct qed_spq_entry *p_ent;
int rc;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = qp->icid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
IWARP_RAMROD_CMD_ID_MODIFY_QP,
p_hwfn->p_rdma_info->proto, &init_data);
if (rc)
return rc;
p_ramrod = &p_ent->ramrod.iwarp_modify_qp;
SET_FIELD(p_ramrod->flags, IWARP_MODIFY_QP_RAMROD_DATA_STATE_TRANS_EN,
0x1);
if (qp->iwarp_state == QED_IWARP_QP_STATE_CLOSING)
p_ramrod->transition_to_state = IWARP_MODIFY_QP_STATE_CLOSING;
else
p_ramrod->transition_to_state = IWARP_MODIFY_QP_STATE_ERROR;
rc = qed_spq_post(p_hwfn, p_ent, NULL);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "QP(0x%x)rc=%d\n", qp->icid, rc);
return rc;
}
enum qed_iwarp_qp_state qed_roce2iwarp_state(enum qed_roce_qp_state state)
{
switch (state) {
case QED_ROCE_QP_STATE_RESET:
case QED_ROCE_QP_STATE_INIT:
case QED_ROCE_QP_STATE_RTR:
return QED_IWARP_QP_STATE_IDLE;
case QED_ROCE_QP_STATE_RTS:
return QED_IWARP_QP_STATE_RTS;
case QED_ROCE_QP_STATE_SQD:
return QED_IWARP_QP_STATE_CLOSING;
case QED_ROCE_QP_STATE_ERR:
return QED_IWARP_QP_STATE_ERROR;
case QED_ROCE_QP_STATE_SQE:
return QED_IWARP_QP_STATE_TERMINATE;
default:
return QED_IWARP_QP_STATE_ERROR;
}
}
static enum qed_roce_qp_state
qed_iwarp2roce_state(enum qed_iwarp_qp_state state)
{
switch (state) {
case QED_IWARP_QP_STATE_IDLE:
return QED_ROCE_QP_STATE_INIT;
case QED_IWARP_QP_STATE_RTS:
return QED_ROCE_QP_STATE_RTS;
case QED_IWARP_QP_STATE_TERMINATE:
return QED_ROCE_QP_STATE_SQE;
case QED_IWARP_QP_STATE_CLOSING:
return QED_ROCE_QP_STATE_SQD;
case QED_IWARP_QP_STATE_ERROR:
return QED_ROCE_QP_STATE_ERR;
default:
return QED_ROCE_QP_STATE_ERR;
}
}
int
qed_iwarp_modify_qp(struct qed_hwfn *p_hwfn,
struct qed_rdma_qp *qp,
enum qed_iwarp_qp_state new_state, bool internal)
{
enum qed_iwarp_qp_state prev_iw_state;
bool modify_fw = false;
int rc = 0;
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.qp_lock);
prev_iw_state = qp->iwarp_state;
if (prev_iw_state == new_state) {
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.qp_lock);
return 0;
}
switch (prev_iw_state) {
case QED_IWARP_QP_STATE_IDLE:
switch (new_state) {
case QED_IWARP_QP_STATE_RTS:
qp->iwarp_state = QED_IWARP_QP_STATE_RTS;
break;
case QED_IWARP_QP_STATE_ERROR:
qp->iwarp_state = QED_IWARP_QP_STATE_ERROR;
if (!internal)
modify_fw = true;
break;
default:
break;
}
break;
case QED_IWARP_QP_STATE_RTS:
switch (new_state) {
case QED_IWARP_QP_STATE_CLOSING:
if (!internal)
modify_fw = true;
qp->iwarp_state = QED_IWARP_QP_STATE_CLOSING;
break;
case QED_IWARP_QP_STATE_ERROR:
if (!internal)
modify_fw = true;
qp->iwarp_state = QED_IWARP_QP_STATE_ERROR;
break;
default:
break;
}
break;
case QED_IWARP_QP_STATE_ERROR:
switch (new_state) {
case QED_IWARP_QP_STATE_IDLE:
qp->iwarp_state = new_state;
break;
case QED_IWARP_QP_STATE_CLOSING:
break;
default:
rc = -EINVAL;
}
break;
case QED_IWARP_QP_STATE_TERMINATE:
case QED_IWARP_QP_STATE_CLOSING:
qp->iwarp_state = new_state;
break;
default:
break;
}
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "QP(0x%x) %s --> %s%s\n",
qp->icid,
iwarp_state_names[prev_iw_state],
iwarp_state_names[qp->iwarp_state],
internal ? "internal" : "");
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.qp_lock);
if (modify_fw)
rc = qed_iwarp_modify_fw(p_hwfn, qp);
return rc;
}
int qed_iwarp_fw_destroy(struct qed_hwfn *p_hwfn, struct qed_rdma_qp *qp)
{
struct qed_sp_init_data init_data;
struct qed_spq_entry *p_ent;
int rc;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = qp->icid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
IWARP_RAMROD_CMD_ID_DESTROY_QP,
p_hwfn->p_rdma_info->proto, &init_data);
if (rc)
return rc;
rc = qed_spq_post(p_hwfn, p_ent, NULL);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "QP(0x%x) rc = %d\n", qp->icid, rc);
return rc;
}
static void qed_iwarp_destroy_ep(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ep *ep,
bool remove_from_active_list)
{
dma_free_coherent(&p_hwfn->cdev->pdev->dev,
sizeof(*ep->ep_buffer_virt),
ep->ep_buffer_virt, ep->ep_buffer_phys);
if (remove_from_active_list) {
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_del(&ep->list_entry);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
}
if (ep->qp)
ep->qp->ep = NULL;
kfree(ep);
}
int qed_iwarp_destroy_qp(struct qed_hwfn *p_hwfn, struct qed_rdma_qp *qp)
{
struct qed_iwarp_ep *ep = qp->ep;
int wait_count = 0;
int rc = 0;
if (qp->iwarp_state != QED_IWARP_QP_STATE_ERROR) {
rc = qed_iwarp_modify_qp(p_hwfn, qp,
QED_IWARP_QP_STATE_ERROR, false);
if (rc)
return rc;
}
if (ep) {
while (ep->state != QED_IWARP_EP_CLOSED && wait_count++ < 200)
msleep(100);
if (ep->state != QED_IWARP_EP_CLOSED)
DP_NOTICE(p_hwfn, "ep state close timeout state=%x\n",
ep->state);
qed_iwarp_destroy_ep(p_hwfn, ep, false);
}
rc = qed_iwarp_fw_destroy(p_hwfn, qp);
if (qp->shared_queue)
dma_free_coherent(&p_hwfn->cdev->pdev->dev,
IWARP_SHARED_QUEUE_PAGE_SIZE,
qp->shared_queue, qp->shared_queue_phys_addr);
return rc;
}
static int
qed_iwarp_create_ep(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep **ep_out)
{
struct qed_iwarp_ep *ep;
int rc;
ep = kzalloc(sizeof(*ep), GFP_KERNEL);
if (!ep)
return -ENOMEM;
ep->state = QED_IWARP_EP_INIT;
ep->ep_buffer_virt = dma_alloc_coherent(&p_hwfn->cdev->pdev->dev,
sizeof(*ep->ep_buffer_virt),
&ep->ep_buffer_phys,
GFP_KERNEL);
if (!ep->ep_buffer_virt) {
rc = -ENOMEM;
goto err;
}
ep->sig = QED_EP_SIG;
*ep_out = ep;
return 0;
err:
kfree(ep);
return rc;
}
static void
qed_iwarp_print_tcp_ramrod(struct qed_hwfn *p_hwfn,
struct iwarp_tcp_offload_ramrod_data *p_tcp_ramrod)
{
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "local_mac=%x %x %x, remote_mac=%x %x %x\n",
p_tcp_ramrod->tcp.local_mac_addr_lo,
p_tcp_ramrod->tcp.local_mac_addr_mid,
p_tcp_ramrod->tcp.local_mac_addr_hi,
p_tcp_ramrod->tcp.remote_mac_addr_lo,
p_tcp_ramrod->tcp.remote_mac_addr_mid,
p_tcp_ramrod->tcp.remote_mac_addr_hi);
if (p_tcp_ramrod->tcp.ip_version == TCP_IPV4) {
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"local_ip=%pI4h:%x, remote_ip=%pI4h:%x, vlan=%x\n",
p_tcp_ramrod->tcp.local_ip,
p_tcp_ramrod->tcp.local_port,
p_tcp_ramrod->tcp.remote_ip,
p_tcp_ramrod->tcp.remote_port,
p_tcp_ramrod->tcp.vlan_id);
} else {
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"local_ip=%pI6:%x, remote_ip=%pI6:%x, vlan=%x\n",
p_tcp_ramrod->tcp.local_ip,
p_tcp_ramrod->tcp.local_port,
p_tcp_ramrod->tcp.remote_ip,
p_tcp_ramrod->tcp.remote_port,
p_tcp_ramrod->tcp.vlan_id);
}
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"flow_label=%x, ttl=%x, tos_or_tc=%x, mss=%x, rcv_wnd_scale=%x, connect_mode=%x, flags=%x\n",
p_tcp_ramrod->tcp.flow_label,
p_tcp_ramrod->tcp.ttl,
p_tcp_ramrod->tcp.tos_or_tc,
p_tcp_ramrod->tcp.mss,
p_tcp_ramrod->tcp.rcv_wnd_scale,
p_tcp_ramrod->tcp.connect_mode,
p_tcp_ramrod->tcp.flags);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "syn_ip_payload_length=%x, lo=%x, hi=%x\n",
p_tcp_ramrod->tcp.syn_ip_payload_length,
p_tcp_ramrod->tcp.syn_phy_addr_lo,
p_tcp_ramrod->tcp.syn_phy_addr_hi);
}
static int
qed_iwarp_tcp_offload(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep *ep)
{
struct qed_iwarp_info *iwarp_info = &p_hwfn->p_rdma_info->iwarp;
struct iwarp_tcp_offload_ramrod_data *p_tcp_ramrod;
struct tcp_offload_params_opt2 *tcp;
struct qed_sp_init_data init_data;
struct qed_spq_entry *p_ent;
dma_addr_t async_output_phys;
dma_addr_t in_pdata_phys;
u16 physical_q;
u8 tcp_flags;
int rc;
int i;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = ep->tcp_cid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
if (ep->connect_mode == TCP_CONNECT_PASSIVE)
init_data.comp_mode = QED_SPQ_MODE_CB;
else
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
IWARP_RAMROD_CMD_ID_TCP_OFFLOAD,
PROTOCOLID_IWARP, &init_data);
if (rc)
return rc;
p_tcp_ramrod = &p_ent->ramrod.iwarp_tcp_offload;
in_pdata_phys = ep->ep_buffer_phys +
offsetof(struct qed_iwarp_ep_memory, in_pdata);
DMA_REGPAIR_LE(p_tcp_ramrod->iwarp.incoming_ulp_buffer.addr,
in_pdata_phys);
p_tcp_ramrod->iwarp.incoming_ulp_buffer.len =
cpu_to_le16(sizeof(ep->ep_buffer_virt->in_pdata));
async_output_phys = ep->ep_buffer_phys +
offsetof(struct qed_iwarp_ep_memory, async_output);
DMA_REGPAIR_LE(p_tcp_ramrod->iwarp.async_eqe_output_buf,
async_output_phys);
p_tcp_ramrod->iwarp.handle_for_async.hi = cpu_to_le32(PTR_HI(ep));
p_tcp_ramrod->iwarp.handle_for_async.lo = cpu_to_le32(PTR_LO(ep));
physical_q = qed_get_cm_pq_idx(p_hwfn, PQ_FLAGS_OFLD);
p_tcp_ramrod->iwarp.physical_q0 = cpu_to_le16(physical_q);
physical_q = qed_get_cm_pq_idx(p_hwfn, PQ_FLAGS_ACK);
p_tcp_ramrod->iwarp.physical_q1 = cpu_to_le16(physical_q);
p_tcp_ramrod->iwarp.mpa_mode = iwarp_info->mpa_rev;
tcp = &p_tcp_ramrod->tcp;
qed_set_fw_mac_addr(&tcp->remote_mac_addr_hi,
&tcp->remote_mac_addr_mid,
&tcp->remote_mac_addr_lo, ep->remote_mac_addr);
qed_set_fw_mac_addr(&tcp->local_mac_addr_hi, &tcp->local_mac_addr_mid,
&tcp->local_mac_addr_lo, ep->local_mac_addr);
tcp->vlan_id = cpu_to_le16(ep->cm_info.vlan);
tcp_flags = p_hwfn->p_rdma_info->iwarp.tcp_flags;
tcp->flags = 0;
SET_FIELD(tcp->flags, TCP_OFFLOAD_PARAMS_OPT2_TS_EN,
!!(tcp_flags & QED_IWARP_TS_EN));
SET_FIELD(tcp->flags, TCP_OFFLOAD_PARAMS_OPT2_DA_EN,
!!(tcp_flags & QED_IWARP_DA_EN));
tcp->ip_version = ep->cm_info.ip_version;
for (i = 0; i < 4; i++) {
tcp->remote_ip[i] = cpu_to_le32(ep->cm_info.remote_ip[i]);
tcp->local_ip[i] = cpu_to_le32(ep->cm_info.local_ip[i]);
}
tcp->remote_port = cpu_to_le16(ep->cm_info.remote_port);
tcp->local_port = cpu_to_le16(ep->cm_info.local_port);
tcp->mss = cpu_to_le16(ep->mss);
tcp->flow_label = 0;
tcp->ttl = 0x40;
tcp->tos_or_tc = 0;
tcp->rcv_wnd_scale = (u8)p_hwfn->p_rdma_info->iwarp.rcv_wnd_scale;
tcp->connect_mode = ep->connect_mode;
if (ep->connect_mode == TCP_CONNECT_PASSIVE) {
tcp->syn_ip_payload_length =
cpu_to_le16(ep->syn_ip_payload_length);
tcp->syn_phy_addr_hi = DMA_HI_LE(ep->syn_phy_addr);
tcp->syn_phy_addr_lo = DMA_LO_LE(ep->syn_phy_addr);
}
qed_iwarp_print_tcp_ramrod(p_hwfn, p_tcp_ramrod);
rc = qed_spq_post(p_hwfn, p_ent, NULL);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"EP(0x%x) Offload completed rc=%d\n", ep->tcp_cid, rc);
return rc;
}
static void
qed_iwarp_mpa_received(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep *ep)
{
struct qed_iwarp_info *iwarp_info = &p_hwfn->p_rdma_info->iwarp;
struct qed_iwarp_cm_event_params params;
struct mpa_v2_hdr *mpa_v2;
union async_output *async_data;
u16 mpa_ord, mpa_ird;
u8 mpa_hdr_size = 0;
u8 mpa_rev;
async_data = &ep->ep_buffer_virt->async_output;
mpa_rev = async_data->mpa_request.mpa_handshake_mode;
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"private_data_len=%x handshake_mode=%x private_data=(%x)\n",
async_data->mpa_request.ulp_data_len,
mpa_rev, *((u32 *)(ep->ep_buffer_virt->in_pdata)));
if (mpa_rev == MPA_NEGOTIATION_TYPE_ENHANCED) {
mpa_v2 = (struct mpa_v2_hdr *)ep->ep_buffer_virt->in_pdata;
mpa_hdr_size = sizeof(*mpa_v2);
mpa_ord = ntohs(mpa_v2->ord);
mpa_ird = ntohs(mpa_v2->ird);
ep->cm_info.ord = (u8)min_t(u16,
(mpa_ord & MPA_V2_IRD_ORD_MASK),
QED_IWARP_ORD_DEFAULT);
ep->cm_info.ird = (u8)min_t(u16,
(mpa_ird & MPA_V2_IRD_ORD_MASK),
QED_IWARP_IRD_DEFAULT);
ep->rtr_type = MPA_RTR_TYPE_NONE;
if (mpa_ird & MPA_V2_PEER2PEER_MODEL) {
if (mpa_ord & MPA_V2_WRITE_RTR)
ep->rtr_type |= MPA_RTR_TYPE_ZERO_WRITE;
if (mpa_ord & MPA_V2_READ_RTR)
ep->rtr_type |= MPA_RTR_TYPE_ZERO_READ;
if (mpa_ird & MPA_V2_SEND_RTR)
ep->rtr_type |= MPA_RTR_TYPE_ZERO_SEND;
ep->rtr_type &= iwarp_info->rtr_type;
if (ep->rtr_type == MPA_RTR_TYPE_NONE)
ep->rtr_type = iwarp_info->rtr_type;
}
ep->mpa_rev = MPA_NEGOTIATION_TYPE_ENHANCED;
} else {
ep->cm_info.ord = QED_IWARP_ORD_DEFAULT;
ep->cm_info.ird = QED_IWARP_IRD_DEFAULT;
ep->mpa_rev = MPA_NEGOTIATION_TYPE_BASIC;
}
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"MPA_NEGOTIATE (v%d): ORD: 0x%x IRD: 0x%x rtr:0x%x ulp_data_len = %x mpa_hdr_size = %x\n",
mpa_rev, ep->cm_info.ord, ep->cm_info.ird, ep->rtr_type,
async_data->mpa_request.ulp_data_len, mpa_hdr_size);
ep->cm_info.private_data = ep->ep_buffer_virt->in_pdata + mpa_hdr_size;
ep->cm_info.private_data_len = async_data->mpa_request.ulp_data_len -
mpa_hdr_size;
params.event = QED_IWARP_EVENT_MPA_REQUEST;
params.cm_info = &ep->cm_info;
params.ep_context = ep;
params.status = 0;
ep->state = QED_IWARP_EP_MPA_REQ_RCVD;
ep->event_cb(ep->cb_context, &params);
}
static int
qed_iwarp_mpa_offload(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep *ep)
{
struct iwarp_mpa_offload_ramrod_data *p_mpa_ramrod;
struct qed_sp_init_data init_data;
dma_addr_t async_output_phys;
struct qed_spq_entry *p_ent;
dma_addr_t out_pdata_phys;
dma_addr_t in_pdata_phys;
struct qed_rdma_qp *qp;
bool reject;
int rc;
if (!ep)
return -EINVAL;
qp = ep->qp;
reject = !qp;
memset(&init_data, 0, sizeof(init_data));
init_data.cid = reject ? ep->tcp_cid : qp->icid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
if (ep->connect_mode == TCP_CONNECT_ACTIVE)
init_data.comp_mode = QED_SPQ_MODE_CB;
else
init_data.comp_mode = QED_SPQ_MODE_EBLOCK;
rc = qed_sp_init_request(p_hwfn, &p_ent,
IWARP_RAMROD_CMD_ID_MPA_OFFLOAD,
PROTOCOLID_IWARP, &init_data);
if (rc)
return rc;
p_mpa_ramrod = &p_ent->ramrod.iwarp_mpa_offload;
out_pdata_phys = ep->ep_buffer_phys +
offsetof(struct qed_iwarp_ep_memory, out_pdata);
DMA_REGPAIR_LE(p_mpa_ramrod->common.outgoing_ulp_buffer.addr,
out_pdata_phys);
p_mpa_ramrod->common.outgoing_ulp_buffer.len =
ep->cm_info.private_data_len;
p_mpa_ramrod->common.crc_needed = p_hwfn->p_rdma_info->iwarp.crc_needed;
p_mpa_ramrod->common.out_rq.ord = ep->cm_info.ord;
p_mpa_ramrod->common.out_rq.ird = ep->cm_info.ird;
p_mpa_ramrod->tcp_cid = p_hwfn->hw_info.opaque_fid << 16 | ep->tcp_cid;
in_pdata_phys = ep->ep_buffer_phys +
offsetof(struct qed_iwarp_ep_memory, in_pdata);
p_mpa_ramrod->tcp_connect_side = ep->connect_mode;
DMA_REGPAIR_LE(p_mpa_ramrod->incoming_ulp_buffer.addr,
in_pdata_phys);
p_mpa_ramrod->incoming_ulp_buffer.len =
cpu_to_le16(sizeof(ep->ep_buffer_virt->in_pdata));
async_output_phys = ep->ep_buffer_phys +
offsetof(struct qed_iwarp_ep_memory, async_output);
DMA_REGPAIR_LE(p_mpa_ramrod->async_eqe_output_buf,
async_output_phys);
p_mpa_ramrod->handle_for_async.hi = cpu_to_le32(PTR_HI(ep));
p_mpa_ramrod->handle_for_async.lo = cpu_to_le32(PTR_LO(ep));
if (!reject) {
DMA_REGPAIR_LE(p_mpa_ramrod->shared_queue_addr,
qp->shared_queue_phys_addr);
p_mpa_ramrod->stats_counter_id =
RESC_START(p_hwfn, QED_RDMA_STATS_QUEUE) + qp->stats_queue;
} else {
p_mpa_ramrod->common.reject = 1;
}
p_mpa_ramrod->mode = ep->mpa_rev;
SET_FIELD(p_mpa_ramrod->rtr_pref,
IWARP_MPA_OFFLOAD_RAMROD_DATA_RTR_SUPPORTED, ep->rtr_type);
ep->state = QED_IWARP_EP_MPA_OFFLOADED;
rc = qed_spq_post(p_hwfn, p_ent, NULL);
if (!reject)
ep->cid = qp->icid;
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"QP(0x%x) EP(0x%x) MPA Offload rc = %d IRD=0x%x ORD=0x%x rtr_type=%d mpa_rev=%d reject=%d\n",
reject ? 0xffff : qp->icid,
ep->tcp_cid,
rc,
ep->cm_info.ird,
ep->cm_info.ord, ep->rtr_type, ep->mpa_rev, reject);
return rc;
}
static void
qed_iwarp_return_ep(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep *ep)
{
ep->state = QED_IWARP_EP_INIT;
if (ep->qp)
ep->qp->ep = NULL;
ep->qp = NULL;
memset(&ep->cm_info, 0, sizeof(ep->cm_info));
if (ep->tcp_cid == QED_IWARP_INVALID_TCP_CID) {
qed_iwarp_alloc_tcp_cid(p_hwfn, &ep->tcp_cid);
}
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_del(&ep->list_entry);
list_add_tail(&ep->list_entry,
&p_hwfn->p_rdma_info->iwarp.ep_free_list);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
}
void
qed_iwarp_parse_private_data(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep *ep)
{
struct mpa_v2_hdr *mpa_v2_params;
union async_output *async_data;
u16 mpa_ird, mpa_ord;
u8 mpa_data_size = 0;
if (MPA_REV2(p_hwfn->p_rdma_info->iwarp.mpa_rev)) {
mpa_v2_params =
(struct mpa_v2_hdr *)(ep->ep_buffer_virt->in_pdata);
mpa_data_size = sizeof(*mpa_v2_params);
mpa_ird = ntohs(mpa_v2_params->ird);
mpa_ord = ntohs(mpa_v2_params->ord);
ep->cm_info.ird = (u8)(mpa_ord & MPA_V2_IRD_ORD_MASK);
ep->cm_info.ord = (u8)(mpa_ird & MPA_V2_IRD_ORD_MASK);
}
async_data = &ep->ep_buffer_virt->async_output;
ep->cm_info.private_data = ep->ep_buffer_virt->in_pdata + mpa_data_size;
ep->cm_info.private_data_len = async_data->mpa_response.ulp_data_len -
mpa_data_size;
}
void
qed_iwarp_mpa_reply_arrived(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep *ep)
{
struct qed_iwarp_cm_event_params params;
if (ep->connect_mode == TCP_CONNECT_PASSIVE) {
DP_NOTICE(p_hwfn,
"MPA reply event not expected on passive side!\n");
return;
}
params.event = QED_IWARP_EVENT_ACTIVE_MPA_REPLY;
qed_iwarp_parse_private_data(p_hwfn, ep);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"MPA_NEGOTIATE (v%d): ORD: 0x%x IRD: 0x%x\n",
ep->mpa_rev, ep->cm_info.ord, ep->cm_info.ird);
params.cm_info = &ep->cm_info;
params.ep_context = ep;
params.status = 0;
ep->mpa_reply_processed = true;
ep->event_cb(ep->cb_context, &params);
}
static void
qed_iwarp_mpa_complete(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ep *ep, u8 fw_return_code)
{
struct qed_iwarp_cm_event_params params;
if (ep->connect_mode == TCP_CONNECT_ACTIVE)
params.event = QED_IWARP_EVENT_ACTIVE_COMPLETE;
else
params.event = QED_IWARP_EVENT_PASSIVE_COMPLETE;
if (ep->connect_mode == TCP_CONNECT_ACTIVE && !ep->mpa_reply_processed)
qed_iwarp_parse_private_data(p_hwfn, ep);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"MPA_NEGOTIATE (v%d): ORD: 0x%x IRD: 0x%x\n",
ep->mpa_rev, ep->cm_info.ord, ep->cm_info.ird);
params.cm_info = &ep->cm_info;
params.ep_context = ep;
ep->state = QED_IWARP_EP_CLOSED;
switch (fw_return_code) {
case RDMA_RETURN_OK:
ep->qp->max_rd_atomic_req = ep->cm_info.ord;
ep->qp->max_rd_atomic_resp = ep->cm_info.ird;
qed_iwarp_modify_qp(p_hwfn, ep->qp, QED_IWARP_QP_STATE_RTS, 1);
ep->state = QED_IWARP_EP_ESTABLISHED;
params.status = 0;
break;
case IWARP_CONN_ERROR_MPA_TIMEOUT:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA timeout\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -EBUSY;
break;
case IWARP_CONN_ERROR_MPA_ERROR_REJECT:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA Reject\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -ECONNREFUSED;
break;
case IWARP_CONN_ERROR_MPA_RST:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA reset(tcp cid: 0x%x)\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid,
ep->tcp_cid);
params.status = -ECONNRESET;
break;
case IWARP_CONN_ERROR_MPA_FIN:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA received FIN\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -ECONNREFUSED;
break;
case IWARP_CONN_ERROR_MPA_INSUF_IRD:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA insufficient ird\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -ECONNREFUSED;
break;
case IWARP_CONN_ERROR_MPA_RTR_MISMATCH:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA RTR MISMATCH\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -ECONNREFUSED;
break;
case IWARP_CONN_ERROR_MPA_INVALID_PACKET:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA Invalid Packet\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -ECONNREFUSED;
break;
case IWARP_CONN_ERROR_MPA_LOCAL_ERROR:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA Local Error\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -ECONNREFUSED;
break;
case IWARP_CONN_ERROR_MPA_TERMINATE:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA TERMINATE\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->cid);
params.status = -ECONNREFUSED;
break;
default:
params.status = -ECONNRESET;
break;
}
ep->event_cb(ep->cb_context, &params);
if (fw_return_code != RDMA_RETURN_OK) {
ep->tcp_cid = QED_IWARP_INVALID_TCP_CID;
if ((ep->connect_mode == TCP_CONNECT_PASSIVE) &&
(!ep->qp)) {
qed_iwarp_return_ep(p_hwfn, ep);
} else {
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_del(&ep->list_entry);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
}
}
}
static void
qed_iwarp_mpa_v2_set_private(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ep *ep, u8 *mpa_data_size)
{
struct mpa_v2_hdr *mpa_v2_params;
u16 mpa_ird, mpa_ord;
*mpa_data_size = 0;
if (MPA_REV2(ep->mpa_rev)) {
mpa_v2_params =
(struct mpa_v2_hdr *)ep->ep_buffer_virt->out_pdata;
*mpa_data_size = sizeof(*mpa_v2_params);
mpa_ird = (u16)ep->cm_info.ird;
mpa_ord = (u16)ep->cm_info.ord;
if (ep->rtr_type != MPA_RTR_TYPE_NONE) {
mpa_ird |= MPA_V2_PEER2PEER_MODEL;
if (ep->rtr_type & MPA_RTR_TYPE_ZERO_SEND)
mpa_ird |= MPA_V2_SEND_RTR;
if (ep->rtr_type & MPA_RTR_TYPE_ZERO_WRITE)
mpa_ord |= MPA_V2_WRITE_RTR;
if (ep->rtr_type & MPA_RTR_TYPE_ZERO_READ)
mpa_ord |= MPA_V2_READ_RTR;
}
mpa_v2_params->ird = htons(mpa_ird);
mpa_v2_params->ord = htons(mpa_ord);
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"MPA_NEGOTIATE Header: [%x ord:%x ird] %x ord:%x ird:%x peer2peer:%x rtr_send:%x rtr_write:%x rtr_read:%x\n",
mpa_v2_params->ird,
mpa_v2_params->ord,
*((u32 *)mpa_v2_params),
mpa_ord & MPA_V2_IRD_ORD_MASK,
mpa_ird & MPA_V2_IRD_ORD_MASK,
!!(mpa_ird & MPA_V2_PEER2PEER_MODEL),
!!(mpa_ird & MPA_V2_SEND_RTR),
!!(mpa_ord & MPA_V2_WRITE_RTR),
!!(mpa_ord & MPA_V2_READ_RTR));
}
}
int qed_iwarp_connect(void *rdma_cxt,
struct qed_iwarp_connect_in *iparams,
struct qed_iwarp_connect_out *oparams)
{
struct qed_hwfn *p_hwfn = rdma_cxt;
struct qed_iwarp_info *iwarp_info;
struct qed_iwarp_ep *ep;
u8 mpa_data_size = 0;
u8 ts_hdr_size = 0;
u32 cid;
int rc;
if ((iparams->cm_info.ord > QED_IWARP_ORD_DEFAULT) ||
(iparams->cm_info.ird > QED_IWARP_IRD_DEFAULT)) {
DP_NOTICE(p_hwfn,
"QP(0x%x) ERROR: Invalid ord(0x%x)/ird(0x%x)\n",
iparams->qp->icid, iparams->cm_info.ord,
iparams->cm_info.ird);
return -EINVAL;
}
iwarp_info = &p_hwfn->p_rdma_info->iwarp;
rc = qed_iwarp_alloc_cid(p_hwfn, &cid);
if (rc)
return rc;
rc = qed_iwarp_create_ep(p_hwfn, &ep);
if (rc)
goto err;
ep->tcp_cid = cid;
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_add_tail(&ep->list_entry, &p_hwfn->p_rdma_info->iwarp.ep_list);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
ep->qp = iparams->qp;
ep->qp->ep = ep;
ether_addr_copy(ep->remote_mac_addr, iparams->remote_mac_addr);
ether_addr_copy(ep->local_mac_addr, iparams->local_mac_addr);
memcpy(&ep->cm_info, &iparams->cm_info, sizeof(ep->cm_info));
ep->cm_info.ord = iparams->cm_info.ord;
ep->cm_info.ird = iparams->cm_info.ird;
ep->rtr_type = iwarp_info->rtr_type;
if (!iwarp_info->peer2peer)
ep->rtr_type = MPA_RTR_TYPE_NONE;
if ((ep->rtr_type & MPA_RTR_TYPE_ZERO_READ) && (ep->cm_info.ord == 0))
ep->cm_info.ord = 1;
ep->mpa_rev = iwarp_info->mpa_rev;
qed_iwarp_mpa_v2_set_private(p_hwfn, ep, &mpa_data_size);
ep->cm_info.private_data = ep->ep_buffer_virt->out_pdata;
ep->cm_info.private_data_len = iparams->cm_info.private_data_len +
mpa_data_size;
memcpy((u8 *)ep->ep_buffer_virt->out_pdata + mpa_data_size,
iparams->cm_info.private_data,
iparams->cm_info.private_data_len);
if (p_hwfn->p_rdma_info->iwarp.tcp_flags & QED_IWARP_TS_EN)
ts_hdr_size = TIMESTAMP_HEADER_SIZE;
ep->mss = iparams->mss - ts_hdr_size;
ep->mss = min_t(u16, QED_IWARP_MAX_FW_MSS, ep->mss);
ep->event_cb = iparams->event_cb;
ep->cb_context = iparams->cb_context;
ep->connect_mode = TCP_CONNECT_ACTIVE;
oparams->ep_context = ep;
rc = qed_iwarp_tcp_offload(p_hwfn, ep);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "QP(0x%x) EP(0x%x) rc = %d\n",
iparams->qp->icid, ep->tcp_cid, rc);
if (rc) {
qed_iwarp_destroy_ep(p_hwfn, ep, true);
goto err;
}
return rc;
err:
qed_iwarp_cid_cleaned(p_hwfn, cid);
return rc;
}
static struct qed_iwarp_ep *qed_iwarp_get_free_ep(struct qed_hwfn *p_hwfn)
{
struct qed_iwarp_ep *ep = NULL;
int rc;
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
if (list_empty(&p_hwfn->p_rdma_info->iwarp.ep_free_list)) {
DP_ERR(p_hwfn, "Ep list is empty\n");
goto out;
}
ep = list_first_entry(&p_hwfn->p_rdma_info->iwarp.ep_free_list,
struct qed_iwarp_ep, list_entry);
if (ep->tcp_cid == QED_IWARP_INVALID_TCP_CID) {
rc = qed_iwarp_alloc_tcp_cid(p_hwfn, &ep->tcp_cid);
if (rc) {
ep->tcp_cid = QED_IWARP_INVALID_TCP_CID;
ep = NULL;
goto out;
}
}
list_del(&ep->list_entry);
out:
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
return ep;
}
static int
qed_iwarp_wait_cid_map_cleared(struct qed_hwfn *p_hwfn, struct qed_bmap *bmap)
{
int prev_weight = 0;
int wait_count = 0;
int weight = 0;
weight = bitmap_weight(bmap->bitmap, bmap->max_count);
prev_weight = weight;
while (weight) {
msleep(QED_IWARP_MAX_CID_CLEAN_TIME);
weight = bitmap_weight(bmap->bitmap, bmap->max_count);
if (prev_weight == weight) {
wait_count++;
} else {
prev_weight = weight;
wait_count = 0;
}
if (wait_count > QED_IWARP_MAX_NO_PROGRESS_CNT) {
DP_NOTICE(p_hwfn,
"%s bitmap wait timed out (%d cids pending)\n",
bmap->name, weight);
return -EBUSY;
}
}
return 0;
}
static int qed_iwarp_wait_for_all_cids(struct qed_hwfn *p_hwfn)
{
int rc;
int i;
rc = qed_iwarp_wait_cid_map_cleared(p_hwfn,
&p_hwfn->p_rdma_info->tcp_cid_map);
if (rc)
return rc;
for (i = 0; i < QED_IWARP_PREALLOC_CNT; i++)
qed_bmap_release_id(p_hwfn, &p_hwfn->p_rdma_info->cid_map, i);
return qed_iwarp_wait_cid_map_cleared(p_hwfn,
&p_hwfn->p_rdma_info->cid_map);
}
static void qed_iwarp_free_prealloc_ep(struct qed_hwfn *p_hwfn)
{
struct qed_iwarp_ep *ep;
while (!list_empty(&p_hwfn->p_rdma_info->iwarp.ep_free_list)) {
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
ep = list_first_entry(&p_hwfn->p_rdma_info->iwarp.ep_free_list,
struct qed_iwarp_ep, list_entry);
if (!ep) {
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
break;
}
list_del(&ep->list_entry);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
if (ep->tcp_cid != QED_IWARP_INVALID_TCP_CID)
qed_iwarp_cid_cleaned(p_hwfn, ep->tcp_cid);
qed_iwarp_destroy_ep(p_hwfn, ep, false);
}
}
static int qed_iwarp_prealloc_ep(struct qed_hwfn *p_hwfn, bool init)
{
struct qed_iwarp_ep *ep;
int rc = 0;
int count;
u32 cid;
int i;
count = init ? QED_IWARP_PREALLOC_CNT : 1;
for (i = 0; i < count; i++) {
rc = qed_iwarp_create_ep(p_hwfn, &ep);
if (rc)
return rc;
if (init) {
rc = qed_iwarp_alloc_cid(p_hwfn, &cid);
if (rc)
goto err;
qed_iwarp_set_tcp_cid(p_hwfn, cid);
} else {
qed_iwarp_alloc_tcp_cid(p_hwfn, &cid);
}
ep->tcp_cid = cid;
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_add_tail(&ep->list_entry,
&p_hwfn->p_rdma_info->iwarp.ep_free_list);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
}
return rc;
err:
qed_iwarp_destroy_ep(p_hwfn, ep, false);
return rc;
}
int qed_iwarp_alloc(struct qed_hwfn *p_hwfn)
{
int rc;
rc = qed_rdma_bmap_alloc(p_hwfn, &p_hwfn->p_rdma_info->tcp_cid_map,
QED_IWARP_PREALLOC_CNT, "TCP_CID");
if (rc) {
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"Failed to allocate tcp cid, rc = %d\n", rc);
return rc;
}
INIT_LIST_HEAD(&p_hwfn->p_rdma_info->iwarp.ep_free_list);
spin_lock_init(&p_hwfn->p_rdma_info->iwarp.iw_lock);
return qed_iwarp_prealloc_ep(p_hwfn, true);
}
void qed_iwarp_resc_free(struct qed_hwfn *p_hwfn)
{
qed_rdma_bmap_free(p_hwfn, &p_hwfn->p_rdma_info->tcp_cid_map, 1);
}
int qed_iwarp_accept(void *rdma_cxt, struct qed_iwarp_accept_in *iparams)
{
struct qed_hwfn *p_hwfn = rdma_cxt;
struct qed_iwarp_ep *ep;
u8 mpa_data_size = 0;
int rc;
ep = iparams->ep_context;
if (!ep) {
DP_ERR(p_hwfn, "Ep Context receive in accept is NULL\n");
return -EINVAL;
}
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "QP(0x%x) EP(0x%x)\n",
iparams->qp->icid, ep->tcp_cid);
if ((iparams->ord > QED_IWARP_ORD_DEFAULT) ||
(iparams->ird > QED_IWARP_IRD_DEFAULT)) {
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"QP(0x%x) EP(0x%x) ERROR: Invalid ord(0x%x)/ird(0x%x)\n",
iparams->qp->icid,
ep->tcp_cid, iparams->ord, iparams->ord);
return -EINVAL;
}
qed_iwarp_prealloc_ep(p_hwfn, false);
ep->cb_context = iparams->cb_context;
ep->qp = iparams->qp;
ep->qp->ep = ep;
if (ep->mpa_rev == MPA_NEGOTIATION_TYPE_ENHANCED) {
if (iparams->ord > ep->cm_info.ird)
iparams->ord = ep->cm_info.ird;
if ((ep->rtr_type & MPA_RTR_TYPE_ZERO_READ) &&
(iparams->ird == 0))
iparams->ird = 1;
}
ep->cm_info.ord = iparams->ord;
ep->cm_info.ird = iparams->ird;
qed_iwarp_mpa_v2_set_private(p_hwfn, ep, &mpa_data_size);
ep->cm_info.private_data = ep->ep_buffer_virt->out_pdata;
ep->cm_info.private_data_len = iparams->private_data_len +
mpa_data_size;
memcpy((u8 *)ep->ep_buffer_virt->out_pdata + mpa_data_size,
iparams->private_data, iparams->private_data_len);
rc = qed_iwarp_mpa_offload(p_hwfn, ep);
if (rc)
qed_iwarp_modify_qp(p_hwfn,
iparams->qp, QED_IWARP_QP_STATE_ERROR, 1);
return rc;
}
int qed_iwarp_reject(void *rdma_cxt, struct qed_iwarp_reject_in *iparams)
{
struct qed_hwfn *p_hwfn = rdma_cxt;
struct qed_iwarp_ep *ep;
u8 mpa_data_size = 0;
ep = iparams->ep_context;
if (!ep) {
DP_ERR(p_hwfn, "Ep Context receive in reject is NULL\n");
return -EINVAL;
}
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "EP(0x%x)\n", ep->tcp_cid);
ep->cb_context = iparams->cb_context;
ep->qp = NULL;
qed_iwarp_mpa_v2_set_private(p_hwfn, ep, &mpa_data_size);
ep->cm_info.private_data = ep->ep_buffer_virt->out_pdata;
ep->cm_info.private_data_len = iparams->private_data_len +
mpa_data_size;
memcpy((u8 *)ep->ep_buffer_virt->out_pdata + mpa_data_size,
iparams->private_data, iparams->private_data_len);
return qed_iwarp_mpa_offload(p_hwfn, ep);
}
static void
qed_iwarp_print_cm_info(struct qed_hwfn *p_hwfn,
struct qed_iwarp_cm_info *cm_info)
{
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "ip_version = %d\n",
cm_info->ip_version);
if (cm_info->ip_version == QED_TCP_IPV4)
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"remote_ip %pI4h:%x, local_ip %pI4h:%x vlan=%x\n",
cm_info->remote_ip, cm_info->remote_port,
cm_info->local_ip, cm_info->local_port,
cm_info->vlan);
else
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"remote_ip %pI6:%x, local_ip %pI6:%x vlan=%x\n",
cm_info->remote_ip, cm_info->remote_port,
cm_info->local_ip, cm_info->local_port,
cm_info->vlan);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"private_data_len = %x ord = %d, ird = %d\n",
cm_info->private_data_len, cm_info->ord, cm_info->ird);
}
static int
qed_iwarp_ll2_post_rx(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ll2_buff *buf, u8 handle)
{
int rc;
rc = qed_ll2_post_rx_buffer(p_hwfn, handle, buf->data_phys_addr,
(u16)buf->buff_size, buf, 1);
if (rc) {
DP_NOTICE(p_hwfn,
"Failed to repost rx buffer to ll2 rc = %d, handle=%d\n",
rc, handle);
dma_free_coherent(&p_hwfn->cdev->pdev->dev, buf->buff_size,
buf->data, buf->data_phys_addr);
kfree(buf);
}
return rc;
}
static bool
qed_iwarp_ep_exists(struct qed_hwfn *p_hwfn, struct qed_iwarp_cm_info *cm_info)
{
struct qed_iwarp_ep *ep = NULL;
bool found = false;
list_for_each_entry(ep,
&p_hwfn->p_rdma_info->iwarp.ep_list,
list_entry) {
if ((ep->cm_info.local_port == cm_info->local_port) &&
(ep->cm_info.remote_port == cm_info->remote_port) &&
(ep->cm_info.vlan == cm_info->vlan) &&
!memcmp(&ep->cm_info.local_ip, cm_info->local_ip,
sizeof(cm_info->local_ip)) &&
!memcmp(&ep->cm_info.remote_ip, cm_info->remote_ip,
sizeof(cm_info->remote_ip))) {
found = true;
break;
}
}
if (found) {
DP_NOTICE(p_hwfn,
"SYN received on active connection - dropping\n");
qed_iwarp_print_cm_info(p_hwfn, cm_info);
return true;
}
return false;
}
static struct qed_iwarp_listener *
qed_iwarp_get_listener(struct qed_hwfn *p_hwfn,
struct qed_iwarp_cm_info *cm_info)
{
struct qed_iwarp_listener *listener = NULL;
static const u32 ip_zero[4] = { 0, 0, 0, 0 };
bool found = false;
qed_iwarp_print_cm_info(p_hwfn, cm_info);
list_for_each_entry(listener,
&p_hwfn->p_rdma_info->iwarp.listen_list,
list_entry) {
if (listener->port == cm_info->local_port) {
if (!memcmp(listener->ip_addr,
ip_zero, sizeof(ip_zero))) {
found = true;
break;
}
if (!memcmp(listener->ip_addr,
cm_info->local_ip,
sizeof(cm_info->local_ip)) &&
(listener->vlan == cm_info->vlan)) {
found = true;
break;
}
}
}
if (found) {
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "listener found = %p\n",
listener);
return listener;
}
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "listener not found\n");
return NULL;
}
static int
qed_iwarp_parse_rx_pkt(struct qed_hwfn *p_hwfn,
struct qed_iwarp_cm_info *cm_info,
void *buf,
u8 *remote_mac_addr,
u8 *local_mac_addr,
int *payload_len, int *tcp_start_offset)
{
struct vlan_ethhdr *vethh;
bool vlan_valid = false;
struct ipv6hdr *ip6h;
struct ethhdr *ethh;
struct tcphdr *tcph;
struct iphdr *iph;
int eth_hlen;
int ip_hlen;
int eth_type;
int i;
ethh = buf;
eth_type = ntohs(ethh->h_proto);
if (eth_type == ETH_P_8021Q) {
vlan_valid = true;
vethh = (struct vlan_ethhdr *)ethh;
cm_info->vlan = ntohs(vethh->h_vlan_TCI) & VLAN_VID_MASK;
eth_type = ntohs(vethh->h_vlan_encapsulated_proto);
}
eth_hlen = ETH_HLEN + (vlan_valid ? sizeof(u32) : 0);
ether_addr_copy(remote_mac_addr, ethh->h_source);
ether_addr_copy(local_mac_addr, ethh->h_dest);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "eth_type =%d source mac: %pM\n",
eth_type, ethh->h_source);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "eth_hlen=%d destination mac: %pM\n",
eth_hlen, ethh->h_dest);
iph = (struct iphdr *)((u8 *)(ethh) + eth_hlen);
if (eth_type == ETH_P_IP) {
cm_info->local_ip[0] = ntohl(iph->daddr);
cm_info->remote_ip[0] = ntohl(iph->saddr);
cm_info->ip_version = TCP_IPV4;
ip_hlen = (iph->ihl) * sizeof(u32);
*payload_len = ntohs(iph->tot_len) - ip_hlen;
} else if (eth_type == ETH_P_IPV6) {
ip6h = (struct ipv6hdr *)iph;
for (i = 0; i < 4; i++) {
cm_info->local_ip[i] =
ntohl(ip6h->daddr.in6_u.u6_addr32[i]);
cm_info->remote_ip[i] =
ntohl(ip6h->saddr.in6_u.u6_addr32[i]);
}
cm_info->ip_version = TCP_IPV6;
ip_hlen = sizeof(*ip6h);
*payload_len = ntohs(ip6h->payload_len);
} else {
DP_NOTICE(p_hwfn, "Unexpected ethertype on ll2 %x\n", eth_type);
return -EINVAL;
}
tcph = (struct tcphdr *)((u8 *)iph + ip_hlen);
if (!tcph->syn) {
DP_NOTICE(p_hwfn,
"Only SYN type packet expected on this ll2 conn, iph->ihl=%d source=%d dest=%d\n",
iph->ihl, tcph->source, tcph->dest);
return -EINVAL;
}
cm_info->local_port = ntohs(tcph->dest);
cm_info->remote_port = ntohs(tcph->source);
qed_iwarp_print_cm_info(p_hwfn, cm_info);
*tcp_start_offset = eth_hlen + ip_hlen;
return 0;
}
static void
qed_iwarp_ll2_comp_syn_pkt(void *cxt, struct qed_ll2_comp_rx_data *data)
{
struct qed_iwarp_ll2_buff *buf = data->cookie;
struct qed_iwarp_listener *listener;
struct qed_ll2_tx_pkt_info tx_pkt;
struct qed_iwarp_cm_info cm_info;
struct qed_hwfn *p_hwfn = cxt;
u8 remote_mac_addr[ETH_ALEN];
u8 local_mac_addr[ETH_ALEN];
struct qed_iwarp_ep *ep;
int tcp_start_offset;
u8 ts_hdr_size = 0;
u8 ll2_syn_handle;
int payload_len;
u32 hdr_size;
int rc;
memset(&cm_info, 0, sizeof(cm_info));
ll2_syn_handle = p_hwfn->p_rdma_info->iwarp.ll2_syn_handle;
if (GET_FIELD(data->parse_flags,
PARSING_AND_ERR_FLAGS_L4CHKSMWASCALCULATED) &&
GET_FIELD(data->parse_flags, PARSING_AND_ERR_FLAGS_L4CHKSMERROR)) {
DP_NOTICE(p_hwfn, "Syn packet received with checksum error\n");
goto err;
}
rc = qed_iwarp_parse_rx_pkt(p_hwfn, &cm_info, (u8 *)(buf->data) +
data->u.placement_offset, remote_mac_addr,
local_mac_addr, &payload_len,
&tcp_start_offset);
if (rc)
goto err;
listener = qed_iwarp_get_listener(p_hwfn, &cm_info);
if (!listener) {
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"SYN received on tuple not listened on parse_flags=%d packet len=%d\n",
data->parse_flags, data->length.packet_length);
memset(&tx_pkt, 0, sizeof(tx_pkt));
tx_pkt.num_of_bds = 1;
tx_pkt.vlan = data->vlan;
if (GET_FIELD(data->parse_flags,
PARSING_AND_ERR_FLAGS_TAG8021QEXIST))
SET_FIELD(tx_pkt.bd_flags,
CORE_TX_BD_DATA_VLAN_INSERTION, 1);
tx_pkt.l4_hdr_offset_w = (data->length.packet_length) >> 2;
tx_pkt.tx_dest = QED_LL2_TX_DEST_LB;
tx_pkt.first_frag = buf->data_phys_addr +
data->u.placement_offset;
tx_pkt.first_frag_len = data->length.packet_length;
tx_pkt.cookie = buf;
rc = qed_ll2_prepare_tx_packet(p_hwfn, ll2_syn_handle,
&tx_pkt, true);
if (rc) {
DP_NOTICE(p_hwfn,
"Can't post SYN back to chip rc=%d\n", rc);
goto err;
}
return;
}
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "Received syn on listening port\n");
if (qed_iwarp_ep_exists(p_hwfn, &cm_info))
goto err;
ep = qed_iwarp_get_free_ep(p_hwfn);
if (!ep)
goto err;
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_add_tail(&ep->list_entry, &p_hwfn->p_rdma_info->iwarp.ep_list);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
ether_addr_copy(ep->remote_mac_addr, remote_mac_addr);
ether_addr_copy(ep->local_mac_addr, local_mac_addr);
memcpy(&ep->cm_info, &cm_info, sizeof(ep->cm_info));
if (p_hwfn->p_rdma_info->iwarp.tcp_flags & QED_IWARP_TS_EN)
ts_hdr_size = TIMESTAMP_HEADER_SIZE;
hdr_size = ((cm_info.ip_version == QED_TCP_IPV4) ? 40 : 60) +
ts_hdr_size;
ep->mss = p_hwfn->p_rdma_info->iwarp.max_mtu - hdr_size;
ep->mss = min_t(u16, QED_IWARP_MAX_FW_MSS, ep->mss);
ep->event_cb = listener->event_cb;
ep->cb_context = listener->cb_context;
ep->connect_mode = TCP_CONNECT_PASSIVE;
ep->syn = buf;
ep->syn_ip_payload_length = (u16)payload_len;
ep->syn_phy_addr = buf->data_phys_addr + data->u.placement_offset +
tcp_start_offset;
rc = qed_iwarp_tcp_offload(p_hwfn, ep);
if (rc) {
qed_iwarp_return_ep(p_hwfn, ep);
goto err;
}
return;
err:
qed_iwarp_ll2_post_rx(p_hwfn, buf, ll2_syn_handle);
}
static void qed_iwarp_ll2_rel_rx_pkt(void *cxt, u8 connection_handle,
void *cookie, dma_addr_t rx_buf_addr,
bool b_last_packet)
{
struct qed_iwarp_ll2_buff *buffer = cookie;
struct qed_hwfn *p_hwfn = cxt;
dma_free_coherent(&p_hwfn->cdev->pdev->dev, buffer->buff_size,
buffer->data, buffer->data_phys_addr);
kfree(buffer);
}
static void qed_iwarp_ll2_comp_tx_pkt(void *cxt, u8 connection_handle,
void *cookie, dma_addr_t first_frag_addr,
bool b_last_fragment, bool b_last_packet)
{
struct qed_iwarp_ll2_buff *buffer = cookie;
struct qed_hwfn *p_hwfn = cxt;
qed_iwarp_ll2_post_rx(p_hwfn, buffer, connection_handle);
}
static void qed_iwarp_ll2_rel_tx_pkt(void *cxt, u8 connection_handle,
void *cookie, dma_addr_t first_frag_addr,
bool b_last_fragment, bool b_last_packet)
{
struct qed_iwarp_ll2_buff *buffer = cookie;
struct qed_hwfn *p_hwfn = cxt;
if (!buffer)
return;
dma_free_coherent(&p_hwfn->cdev->pdev->dev, buffer->buff_size,
buffer->data, buffer->data_phys_addr);
kfree(buffer);
}
static int qed_iwarp_ll2_stop(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt)
{
struct qed_iwarp_info *iwarp_info = &p_hwfn->p_rdma_info->iwarp;
int rc = 0;
if (iwarp_info->ll2_syn_handle != QED_IWARP_HANDLE_INVAL) {
rc = qed_ll2_terminate_connection(p_hwfn,
iwarp_info->ll2_syn_handle);
if (rc)
DP_INFO(p_hwfn, "Failed to terminate syn connection\n");
qed_ll2_release_connection(p_hwfn, iwarp_info->ll2_syn_handle);
iwarp_info->ll2_syn_handle = QED_IWARP_HANDLE_INVAL;
}
qed_llh_remove_mac_filter(p_hwfn,
p_ptt, p_hwfn->p_rdma_info->iwarp.mac_addr);
return rc;
}
static int
qed_iwarp_ll2_alloc_buffers(struct qed_hwfn *p_hwfn,
int num_rx_bufs, int buff_size, u8 ll2_handle)
{
struct qed_iwarp_ll2_buff *buffer;
int rc = 0;
int i;
for (i = 0; i < num_rx_bufs; i++) {
buffer = kzalloc(sizeof(*buffer), GFP_KERNEL);
if (!buffer) {
rc = -ENOMEM;
break;
}
buffer->data = dma_alloc_coherent(&p_hwfn->cdev->pdev->dev,
buff_size,
&buffer->data_phys_addr,
GFP_KERNEL);
if (!buffer->data) {
kfree(buffer);
rc = -ENOMEM;
break;
}
buffer->buff_size = buff_size;
rc = qed_iwarp_ll2_post_rx(p_hwfn, buffer, ll2_handle);
if (rc)
break;
}
return rc;
}
static int
qed_iwarp_ll2_start(struct qed_hwfn *p_hwfn,
struct qed_rdma_start_in_params *params,
struct qed_ptt *p_ptt)
{
struct qed_iwarp_info *iwarp_info;
struct qed_ll2_acquire_data data;
struct qed_ll2_cbs cbs;
int rc = 0;
iwarp_info = &p_hwfn->p_rdma_info->iwarp;
iwarp_info->ll2_syn_handle = QED_IWARP_HANDLE_INVAL;
iwarp_info->max_mtu = params->max_mtu;
ether_addr_copy(p_hwfn->p_rdma_info->iwarp.mac_addr, params->mac_addr);
rc = qed_llh_add_mac_filter(p_hwfn, p_ptt, params->mac_addr);
if (rc)
return rc;
cbs.rx_comp_cb = qed_iwarp_ll2_comp_syn_pkt;
cbs.rx_release_cb = qed_iwarp_ll2_rel_rx_pkt;
cbs.tx_comp_cb = qed_iwarp_ll2_comp_tx_pkt;
cbs.tx_release_cb = qed_iwarp_ll2_rel_tx_pkt;
cbs.cookie = p_hwfn;
memset(&data, 0, sizeof(data));
data.input.conn_type = QED_LL2_TYPE_IWARP;
data.input.mtu = QED_IWARP_MAX_SYN_PKT_SIZE;
data.input.rx_num_desc = QED_IWARP_LL2_SYN_RX_SIZE;
data.input.tx_num_desc = QED_IWARP_LL2_SYN_TX_SIZE;
data.input.tx_max_bds_per_packet = 1;
data.input.tx_tc = PKT_LB_TC;
data.input.tx_dest = QED_LL2_TX_DEST_LB;
data.p_connection_handle = &iwarp_info->ll2_syn_handle;
data.cbs = &cbs;
rc = qed_ll2_acquire_connection(p_hwfn, &data);
if (rc) {
DP_NOTICE(p_hwfn, "Failed to acquire LL2 connection\n");
qed_llh_remove_mac_filter(p_hwfn, p_ptt, params->mac_addr);
return rc;
}
rc = qed_ll2_establish_connection(p_hwfn, iwarp_info->ll2_syn_handle);
if (rc) {
DP_NOTICE(p_hwfn, "Failed to establish LL2 connection\n");
goto err;
}
rc = qed_iwarp_ll2_alloc_buffers(p_hwfn,
QED_IWARP_LL2_SYN_RX_SIZE,
QED_IWARP_MAX_SYN_PKT_SIZE,
iwarp_info->ll2_syn_handle);
if (rc)
goto err;
return rc;
err:
qed_iwarp_ll2_stop(p_hwfn, p_ptt);
return rc;
}
int qed_iwarp_setup(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt,
struct qed_rdma_start_in_params *params)
{
struct qed_iwarp_info *iwarp_info;
u32 rcv_wnd_size;
iwarp_info = &p_hwfn->p_rdma_info->iwarp;
iwarp_info->tcp_flags = QED_IWARP_TS_EN;
rcv_wnd_size = QED_IWARP_RCV_WND_SIZE_DEF;
iwarp_info->rcv_wnd_scale = ilog2(rcv_wnd_size) -
ilog2(QED_IWARP_RCV_WND_SIZE_MIN);
iwarp_info->crc_needed = QED_IWARP_PARAM_CRC_NEEDED;
iwarp_info->mpa_rev = MPA_NEGOTIATION_TYPE_ENHANCED;
iwarp_info->peer2peer = QED_IWARP_PARAM_P2P;
iwarp_info->rtr_type = MPA_RTR_TYPE_ZERO_SEND |
MPA_RTR_TYPE_ZERO_WRITE |
MPA_RTR_TYPE_ZERO_READ;
spin_lock_init(&p_hwfn->p_rdma_info->iwarp.qp_lock);
INIT_LIST_HEAD(&p_hwfn->p_rdma_info->iwarp.ep_list);
INIT_LIST_HEAD(&p_hwfn->p_rdma_info->iwarp.listen_list);
qed_spq_register_async_cb(p_hwfn, PROTOCOLID_IWARP,
qed_iwarp_async_event);
return qed_iwarp_ll2_start(p_hwfn, params, p_ptt);
}
int qed_iwarp_stop(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt)
{
int rc;
qed_iwarp_free_prealloc_ep(p_hwfn);
rc = qed_iwarp_wait_for_all_cids(p_hwfn);
if (rc)
return rc;
qed_spq_unregister_async_cb(p_hwfn, PROTOCOLID_IWARP);
return qed_iwarp_ll2_stop(p_hwfn, p_ptt);
}
void qed_iwarp_qp_in_error(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ep *ep, u8 fw_return_code)
{
struct qed_iwarp_cm_event_params params;
qed_iwarp_modify_qp(p_hwfn, ep->qp, QED_IWARP_QP_STATE_ERROR, true);
params.event = QED_IWARP_EVENT_CLOSE;
params.ep_context = ep;
params.cm_info = &ep->cm_info;
params.status = (fw_return_code == IWARP_QP_IN_ERROR_GOOD_CLOSE) ?
0 : -ECONNRESET;
ep->state = QED_IWARP_EP_CLOSED;
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_del(&ep->list_entry);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
ep->event_cb(ep->cb_context, &params);
}
void qed_iwarp_exception_received(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ep *ep, int fw_ret_code)
{
struct qed_iwarp_cm_event_params params;
bool event_cb = false;
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "EP(0x%x) fw_ret_code=%d\n",
ep->cid, fw_ret_code);
switch (fw_ret_code) {
case IWARP_EXCEPTION_DETECTED_LLP_CLOSED:
params.status = 0;
params.event = QED_IWARP_EVENT_DISCONNECT;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_LLP_RESET:
params.status = -ECONNRESET;
params.event = QED_IWARP_EVENT_DISCONNECT;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_RQ_EMPTY:
params.event = QED_IWARP_EVENT_RQ_EMPTY;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_IRQ_FULL:
params.event = QED_IWARP_EVENT_IRQ_FULL;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_LLP_TIMEOUT:
params.event = QED_IWARP_EVENT_LLP_TIMEOUT;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_REMOTE_PROTECTION_ERROR:
params.event = QED_IWARP_EVENT_REMOTE_PROTECTION_ERROR;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_CQ_OVERFLOW:
params.event = QED_IWARP_EVENT_CQ_OVERFLOW;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_LOCAL_CATASTROPHIC:
params.event = QED_IWARP_EVENT_QP_CATASTROPHIC;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_LOCAL_ACCESS_ERROR:
params.event = QED_IWARP_EVENT_LOCAL_ACCESS_ERROR;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_REMOTE_OPERATION_ERROR:
params.event = QED_IWARP_EVENT_REMOTE_OPERATION_ERROR;
event_cb = true;
break;
case IWARP_EXCEPTION_DETECTED_TERMINATE_RECEIVED:
params.event = QED_IWARP_EVENT_TERMINATE_RECEIVED;
event_cb = true;
break;
default:
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"Unhandled exception received...fw_ret_code=%d\n",
fw_ret_code);
break;
}
if (event_cb) {
params.ep_context = ep;
params.cm_info = &ep->cm_info;
ep->event_cb(ep->cb_context, &params);
}
}
static void
qed_iwarp_tcp_connect_unsuccessful(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ep *ep, u8 fw_return_code)
{
struct qed_iwarp_cm_event_params params;
memset(&params, 0, sizeof(params));
params.event = QED_IWARP_EVENT_ACTIVE_COMPLETE;
params.ep_context = ep;
params.cm_info = &ep->cm_info;
ep->state = QED_IWARP_EP_CLOSED;
switch (fw_return_code) {
case IWARP_CONN_ERROR_TCP_CONNECT_INVALID_PACKET:
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"%s(0x%x) TCP connect got invalid packet\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->tcp_cid);
params.status = -ECONNRESET;
break;
case IWARP_CONN_ERROR_TCP_CONNECTION_RST:
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"%s(0x%x) TCP Connection Reset\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->tcp_cid);
params.status = -ECONNRESET;
break;
case IWARP_CONN_ERROR_TCP_CONNECT_TIMEOUT:
DP_NOTICE(p_hwfn, "%s(0x%x) TCP timeout\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->tcp_cid);
params.status = -EBUSY;
break;
case IWARP_CONN_ERROR_MPA_NOT_SUPPORTED_VER:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA not supported VER\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->tcp_cid);
params.status = -ECONNREFUSED;
break;
case IWARP_CONN_ERROR_MPA_INVALID_PACKET:
DP_NOTICE(p_hwfn, "%s(0x%x) MPA Invalid Packet\n",
QED_IWARP_CONNECT_MODE_STRING(ep), ep->tcp_cid);
params.status = -ECONNRESET;
break;
default:
DP_ERR(p_hwfn,
"%s(0x%x) Unexpected return code tcp connect: %d\n",
QED_IWARP_CONNECT_MODE_STRING(ep),
ep->tcp_cid, fw_return_code);
params.status = -ECONNRESET;
break;
}
if (ep->connect_mode == TCP_CONNECT_PASSIVE) {
ep->tcp_cid = QED_IWARP_INVALID_TCP_CID;
qed_iwarp_return_ep(p_hwfn, ep);
} else {
ep->event_cb(ep->cb_context, &params);
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_del(&ep->list_entry);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
}
}
void
qed_iwarp_connect_complete(struct qed_hwfn *p_hwfn,
struct qed_iwarp_ep *ep, u8 fw_return_code)
{
u8 ll2_syn_handle = p_hwfn->p_rdma_info->iwarp.ll2_syn_handle;
if (ep->connect_mode == TCP_CONNECT_PASSIVE) {
qed_iwarp_ll2_post_rx(p_hwfn, ep->syn, ll2_syn_handle);
ep->syn = NULL;
if (fw_return_code == RDMA_RETURN_OK)
qed_iwarp_mpa_received(p_hwfn, ep);
else
qed_iwarp_tcp_connect_unsuccessful(p_hwfn, ep,
fw_return_code);
} else {
if (fw_return_code == RDMA_RETURN_OK)
qed_iwarp_mpa_offload(p_hwfn, ep);
else
qed_iwarp_tcp_connect_unsuccessful(p_hwfn, ep,
fw_return_code);
}
}
static inline bool
qed_iwarp_check_ep_ok(struct qed_hwfn *p_hwfn, struct qed_iwarp_ep *ep)
{
if (!ep || (ep->sig != QED_EP_SIG)) {
DP_ERR(p_hwfn, "ERROR ON ASYNC ep=%p\n", ep);
return false;
}
return true;
}
static int qed_iwarp_async_event(struct qed_hwfn *p_hwfn,
u8 fw_event_code, u16 echo,
union event_ring_data *data,
u8 fw_return_code)
{
struct regpair *fw_handle = &data->rdma_data.async_handle;
struct qed_iwarp_ep *ep = NULL;
u16 cid;
ep = (struct qed_iwarp_ep *)(uintptr_t)HILO_64(fw_handle->hi,
fw_handle->lo);
switch (fw_event_code) {
case IWARP_EVENT_TYPE_ASYNC_CONNECT_COMPLETE:
if (!qed_iwarp_check_ep_ok(p_hwfn, ep))
return -EINVAL;
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"EP(0x%x) IWARP_EVENT_TYPE_ASYNC_CONNECT_COMPLETE fw_ret_code=%d\n",
ep->tcp_cid, fw_return_code);
qed_iwarp_connect_complete(p_hwfn, ep, fw_return_code);
break;
case IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED:
if (!qed_iwarp_check_ep_ok(p_hwfn, ep))
return -EINVAL;
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"QP(0x%x) IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED fw_ret_code=%d\n",
ep->cid, fw_return_code);
qed_iwarp_exception_received(p_hwfn, ep, fw_return_code);
break;
case IWARP_EVENT_TYPE_ASYNC_QP_IN_ERROR_STATE:
if (!qed_iwarp_check_ep_ok(p_hwfn, ep))
return -EINVAL;
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"QP(0x%x) IWARP_EVENT_TYPE_ASYNC_QP_IN_ERROR_STATE fw_ret_code=%d\n",
ep->cid, fw_return_code);
qed_iwarp_qp_in_error(p_hwfn, ep, fw_return_code);
break;
case IWARP_EVENT_TYPE_ASYNC_ENHANCED_MPA_REPLY_ARRIVED:
if (!qed_iwarp_check_ep_ok(p_hwfn, ep))
return -EINVAL;
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"QP(0x%x) IWARP_EVENT_TYPE_ASYNC_MPA_HANDSHAKE_MPA_REPLY_ARRIVED fw_ret_code=%d\n",
ep->cid, fw_return_code);
qed_iwarp_mpa_reply_arrived(p_hwfn, ep);
break;
case IWARP_EVENT_TYPE_ASYNC_MPA_HANDSHAKE_COMPLETE:
if (!qed_iwarp_check_ep_ok(p_hwfn, ep))
return -EINVAL;
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"QP(0x%x) IWARP_EVENT_TYPE_ASYNC_MPA_HANDSHAKE_COMPLETE fw_ret_code=%d\n",
ep->cid, fw_return_code);
qed_iwarp_mpa_complete(p_hwfn, ep, fw_return_code);
break;
case IWARP_EVENT_TYPE_ASYNC_CID_CLEANED:
cid = (u16)le32_to_cpu(fw_handle->lo);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA,
"(0x%x)IWARP_EVENT_TYPE_ASYNC_CID_CLEANED\n", cid);
qed_iwarp_cid_cleaned(p_hwfn, cid);
break;
case IWARP_EVENT_TYPE_ASYNC_CQ_OVERFLOW:
DP_NOTICE(p_hwfn, "IWARP_EVENT_TYPE_ASYNC_CQ_OVERFLOW\n");
p_hwfn->p_rdma_info->events.affiliated_event(
p_hwfn->p_rdma_info->events.context,
QED_IWARP_EVENT_CQ_OVERFLOW,
(void *)fw_handle);
break;
default:
DP_ERR(p_hwfn, "Received unexpected async iwarp event %d\n",
fw_event_code);
return -EINVAL;
}
return 0;
}
int
qed_iwarp_create_listen(void *rdma_cxt,
struct qed_iwarp_listen_in *iparams,
struct qed_iwarp_listen_out *oparams)
{
struct qed_hwfn *p_hwfn = rdma_cxt;
struct qed_iwarp_listener *listener;
listener = kzalloc(sizeof(*listener), GFP_KERNEL);
if (!listener)
return -ENOMEM;
listener->ip_version = iparams->ip_version;
memcpy(listener->ip_addr, iparams->ip_addr, sizeof(listener->ip_addr));
listener->port = iparams->port;
listener->vlan = iparams->vlan;
listener->event_cb = iparams->event_cb;
listener->cb_context = iparams->cb_context;
listener->max_backlog = iparams->max_backlog;
oparams->handle = listener;
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_add_tail(&listener->list_entry,
&p_hwfn->p_rdma_info->iwarp.listen_list);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
DP_VERBOSE(p_hwfn,
QED_MSG_RDMA,
"callback=%p handle=%p ip=%x:%x:%x:%x port=0x%x vlan=0x%x\n",
listener->event_cb,
listener,
listener->ip_addr[0],
listener->ip_addr[1],
listener->ip_addr[2],
listener->ip_addr[3], listener->port, listener->vlan);
return 0;
}
int qed_iwarp_destroy_listen(void *rdma_cxt, void *handle)
{
struct qed_iwarp_listener *listener = handle;
struct qed_hwfn *p_hwfn = rdma_cxt;
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "handle=%p\n", handle);
spin_lock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
list_del(&listener->list_entry);
spin_unlock_bh(&p_hwfn->p_rdma_info->iwarp.iw_lock);
kfree(listener);
return 0;
}
int qed_iwarp_send_rtr(void *rdma_cxt, struct qed_iwarp_send_rtr_in *iparams)
{
struct qed_hwfn *p_hwfn = rdma_cxt;
struct qed_sp_init_data init_data;
struct qed_spq_entry *p_ent;
struct qed_iwarp_ep *ep;
struct qed_rdma_qp *qp;
int rc;
ep = iparams->ep_context;
if (!ep) {
DP_ERR(p_hwfn, "Ep Context receive in send_rtr is NULL\n");
return -EINVAL;
}
qp = ep->qp;
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "QP(0x%x) EP(0x%x)\n",
qp->icid, ep->tcp_cid);
memset(&init_data, 0, sizeof(init_data));
init_data.cid = qp->icid;
init_data.opaque_fid = p_hwfn->hw_info.opaque_fid;
init_data.comp_mode = QED_SPQ_MODE_CB;
rc = qed_sp_init_request(p_hwfn, &p_ent,
IWARP_RAMROD_CMD_ID_MPA_OFFLOAD_SEND_RTR,
PROTOCOLID_IWARP, &init_data);
if (rc)
return rc;
rc = qed_spq_post(p_hwfn, p_ent, NULL);
DP_VERBOSE(p_hwfn, QED_MSG_RDMA, "rc = 0x%x\n", rc);
return rc;
}
void
qed_iwarp_query_qp(struct qed_rdma_qp *qp,
struct qed_rdma_query_qp_out_params *out_params)
{
out_params->state = qed_iwarp2roce_state(qp->iwarp_state);
}
