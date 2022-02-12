static void storm_memset_vf_to_pf(struct bnx2x *bp, u16 abs_fid,
u16 pf_id)
{
REG_WR8(bp, BAR_XSTRORM_INTMEM + XSTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
REG_WR8(bp, BAR_CSTRORM_INTMEM + CSTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
REG_WR8(bp, BAR_TSTRORM_INTMEM + TSTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
REG_WR8(bp, BAR_USTRORM_INTMEM + USTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
}
static void storm_memset_func_en(struct bnx2x *bp, u16 abs_fid,
u8 enable)
{
REG_WR8(bp, BAR_XSTRORM_INTMEM + XSTORM_FUNC_EN_OFFSET(abs_fid),
enable);
REG_WR8(bp, BAR_CSTRORM_INTMEM + CSTORM_FUNC_EN_OFFSET(abs_fid),
enable);
REG_WR8(bp, BAR_TSTRORM_INTMEM + TSTORM_FUNC_EN_OFFSET(abs_fid),
enable);
REG_WR8(bp, BAR_USTRORM_INTMEM + USTORM_FUNC_EN_OFFSET(abs_fid),
enable);
}
int bnx2x_vf_idx_by_abs_fid(struct bnx2x *bp, u16 abs_vfid)
{
int idx;
for_each_vf(bp, idx)
if (bnx2x_vf(bp, idx, abs_vfid) == abs_vfid)
break;
return idx;
}
static
struct bnx2x_virtf *bnx2x_vf_by_abs_fid(struct bnx2x *bp, u16 abs_vfid)
{
u16 idx = (u16)bnx2x_vf_idx_by_abs_fid(bp, abs_vfid);
return (idx < BNX2X_NR_VIRTFN(bp)) ? BP_VF(bp, idx) : NULL;
}
static void bnx2x_vf_igu_ack_sb(struct bnx2x *bp, struct bnx2x_virtf *vf,
u8 igu_sb_id, u8 segment, u16 index, u8 op,
u8 update)
{
u32 ctl;
u32 igu_addr_data = IGU_REG_COMMAND_REG_32LSB_DATA;
u32 igu_addr_ctl = IGU_REG_COMMAND_REG_CTRL;
u32 func_encode = vf->abs_vfid;
u32 addr_encode = IGU_CMD_E2_PROD_UPD_BASE + igu_sb_id;
struct igu_regular cmd_data = {0};
cmd_data.sb_id_and_flags =
((index << IGU_REGULAR_SB_INDEX_SHIFT) |
(segment << IGU_REGULAR_SEGMENT_ACCESS_SHIFT) |
(update << IGU_REGULAR_BUPDATE_SHIFT) |
(op << IGU_REGULAR_ENABLE_INT_SHIFT));
ctl = addr_encode << IGU_CTRL_REG_ADDRESS_SHIFT |
func_encode << IGU_CTRL_REG_FID_SHIFT |
IGU_CTRL_CMD_TYPE_WR << IGU_CTRL_REG_TYPE_SHIFT;
DP(NETIF_MSG_HW, "write 0x%08x to IGU(via GRC) addr 0x%x\n",
cmd_data.sb_id_and_flags, igu_addr_data);
REG_WR(bp, igu_addr_data, cmd_data.sb_id_and_flags);
mmiowb();
barrier();
DP(NETIF_MSG_HW, "write 0x%08x to IGU(via GRC) addr 0x%x\n",
ctl, igu_addr_ctl);
REG_WR(bp, igu_addr_ctl, ctl);
mmiowb();
barrier();
}
void bnx2x_vfop_qctor_dump_tx(struct bnx2x *bp, struct bnx2x_virtf *vf,
struct bnx2x_queue_init_params *init_params,
struct bnx2x_queue_setup_params *setup_params,
u16 q_idx, u16 sb_idx)
{
DP(BNX2X_MSG_IOV,
"VF[%d] Q_SETUP: txq[%d]-- vfsb=%d, sb-index=%d, hc-rate=%d, flags=0x%lx, traffic-type=%d",
vf->abs_vfid,
q_idx,
sb_idx,
init_params->tx.sb_cq_index,
init_params->tx.hc_rate,
setup_params->flags,
setup_params->txq_params.traffic_type);
}
void bnx2x_vfop_qctor_dump_rx(struct bnx2x *bp, struct bnx2x_virtf *vf,
struct bnx2x_queue_init_params *init_params,
struct bnx2x_queue_setup_params *setup_params,
u16 q_idx, u16 sb_idx)
{
struct bnx2x_rxq_setup_params *rxq_params = &setup_params->rxq_params;
DP(BNX2X_MSG_IOV, "VF[%d] Q_SETUP: rxq[%d]-- vfsb=%d, sb-index=%d, hc-rate=%d, mtu=%d, buf-size=%d\n"
"sge-size=%d, max_sge_pkt=%d, tpa-agg-size=%d, flags=0x%lx, drop-flags=0x%x, cache-log=%d\n",
vf->abs_vfid,
q_idx,
sb_idx,
init_params->rx.sb_cq_index,
init_params->rx.hc_rate,
setup_params->gen_params.mtu,
rxq_params->buf_sz,
rxq_params->sge_buf_sz,
rxq_params->max_sges_pkt,
rxq_params->tpa_agg_sz,
setup_params->flags,
rxq_params->drop_flags,
rxq_params->cache_line_log);
}
void bnx2x_vfop_qctor_prep(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vf_queue *q,
struct bnx2x_vfop_qctor_params *p,
unsigned long q_type)
{
struct bnx2x_queue_init_params *init_p = &p->qstate.params.init;
struct bnx2x_queue_setup_params *setup_p = &p->prep_qsetup;
if (test_bit(BNX2X_Q_FLG_HC, &init_p->rx.flags))
__set_bit(BNX2X_Q_FLG_HC_EN, &init_p->rx.flags);
if (test_bit(BNX2X_Q_FLG_HC, &init_p->tx.flags))
__set_bit(BNX2X_Q_FLG_HC_EN, &init_p->tx.flags);
init_p->rx.fw_sb_id = vf_igu_sb(vf, q->sb_idx);
init_p->tx.fw_sb_id = vf_igu_sb(vf, q->sb_idx);
init_p->cxts[0] = q->cxt;
setup_p->gen_params.spcl_id = vf->sp_cl_id;
setup_p->gen_params.stat_id = vfq_stat_id(vf, q);
if (vf->cfg_flags & VF_CFG_FW_FC)
BNX2X_ERR("No support for pause to VFs (abs_vfid: %d)\n",
vf->abs_vfid);
if (test_bit(BNX2X_Q_FLG_STATS, &setup_p->flags))
__set_bit(BNX2X_Q_FLG_ZERO_STATS, &setup_p->flags);
__set_bit(BNX2X_Q_FLG_TX_SWITCH, &setup_p->flags);
__set_bit(BNX2X_Q_FLG_TX_SEC, &setup_p->flags);
__set_bit(BNX2X_Q_FLG_ANTI_SPOOF, &setup_p->flags);
if (vfq_is_leading(q)) {
__set_bit(BNX2X_Q_FLG_LEADING_RSS, &setup_p->flags);
__set_bit(BNX2X_Q_FLG_MCAST, &setup_p->flags);
}
if (test_bit(BNX2X_Q_TYPE_HAS_RX, &q_type)) {
struct bnx2x_rxq_setup_params *rxq_p = &setup_p->rxq_params;
rxq_p->cl_qzone_id = vfq_qzone_id(vf, q);
rxq_p->fw_sb_id = vf_igu_sb(vf, q->sb_idx);
rxq_p->rss_engine_id = FW_VF_HANDLE(vf->abs_vfid);
if (test_bit(BNX2X_Q_FLG_TPA, &setup_p->flags))
rxq_p->max_tpa_queues = BNX2X_VF_MAX_TPA_AGG_QUEUES;
}
if (test_bit(BNX2X_Q_TYPE_HAS_TX, &q_type)) {
setup_p->txq_params.tss_leading_cl_id = vf->leading_rss;
setup_p->txq_params.fw_sb_id = vf_igu_sb(vf, q->sb_idx);
}
}
static void bnx2x_vfop_qctor(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_vfop_args_qctor *args = &vfop->args.qctor;
struct bnx2x_queue_state_params *q_params = &vfop->op_p->qctor.qstate;
enum bnx2x_vfop_qctor_state state = vfop->state;
bnx2x_vfop_reset_wq(vf);
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
switch (state) {
case BNX2X_VFOP_QCTOR_INIT:
if (bnx2x_get_q_logical_state(bp, q_params->q_obj) ==
BNX2X_Q_LOGICAL_STATE_ACTIVE) {
DP(BNX2X_MSG_IOV,
"Entered qctor but queue was already up. Aborting gracefully\n");
goto op_done;
}
vfop->state = BNX2X_VFOP_QCTOR_SETUP;
q_params->cmd = BNX2X_Q_CMD_INIT;
vfop->rc = bnx2x_queue_state_change(bp, q_params);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_CONT);
case BNX2X_VFOP_QCTOR_SETUP:
vfop->state = BNX2X_VFOP_QCTOR_INT_EN;
vfop->op_p->qctor.qstate.params.setup =
vfop->op_p->qctor.prep_qsetup;
q_params->cmd = BNX2X_Q_CMD_SETUP;
vfop->rc = bnx2x_queue_state_change(bp, q_params);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_CONT);
case BNX2X_VFOP_QCTOR_INT_EN:
bnx2x_vf_igu_ack_sb(bp, vf, vf_igu_sb(vf, args->sb_idx),
USTORM_ID, 0, IGU_INT_ENABLE, 0);
goto op_done;
default:
bnx2x_vfop_default(state);
}
op_err:
BNX2X_ERR("QCTOR[%d:%d] error: cmd %d, rc %d\n",
vf->abs_vfid, args->qid, q_params->cmd, vfop->rc);
op_done:
bnx2x_vfop_end(bp, vf, vfop);
op_pending:
return;
}
static int bnx2x_vfop_qctor_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
vf->op_params.qctor.qstate.q_obj = &bnx2x_vfq(vf, qid, sp_obj);
vfop->args.qctor.qid = qid;
vfop->args.qctor.sb_idx = bnx2x_vfq(vf, qid, sb_idx);
bnx2x_vfop_opset(BNX2X_VFOP_QCTOR_INIT,
bnx2x_vfop_qctor, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_qctor,
cmd->block);
}
return -ENOMEM;
}
static void bnx2x_vfop_qdtor(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_vfop_args_qdtor *qdtor = &vfop->args.qdtor;
struct bnx2x_queue_state_params *q_params = &vfop->op_p->qctor.qstate;
enum bnx2x_vfop_qdtor_state state = vfop->state;
bnx2x_vfop_reset_wq(vf);
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
switch (state) {
case BNX2X_VFOP_QDTOR_HALT:
if (bnx2x_get_q_logical_state(bp, q_params->q_obj) ==
BNX2X_Q_LOGICAL_STATE_STOPPED) {
DP(BNX2X_MSG_IOV,
"Entered qdtor but queue was already stopped. Aborting gracefully\n");
goto op_done;
}
vfop->state = BNX2X_VFOP_QDTOR_TERMINATE;
q_params->cmd = BNX2X_Q_CMD_HALT;
vfop->rc = bnx2x_queue_state_change(bp, q_params);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_CONT);
case BNX2X_VFOP_QDTOR_TERMINATE:
vfop->state = BNX2X_VFOP_QDTOR_CFCDEL;
q_params->cmd = BNX2X_Q_CMD_TERMINATE;
vfop->rc = bnx2x_queue_state_change(bp, q_params);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_CONT);
case BNX2X_VFOP_QDTOR_CFCDEL:
vfop->state = BNX2X_VFOP_QDTOR_DONE;
q_params->cmd = BNX2X_Q_CMD_CFC_DEL;
vfop->rc = bnx2x_queue_state_change(bp, q_params);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
op_err:
BNX2X_ERR("QDTOR[%d:%d] error: cmd %d, rc %d\n",
vf->abs_vfid, qdtor->qid, q_params->cmd, vfop->rc);
op_done:
case BNX2X_VFOP_QDTOR_DONE:
qdtor->cxt->ustorm_ag_context.cdu_usage = 0;
qdtor->cxt->xstorm_ag_context.cdu_reserved = 0;
bnx2x_vfop_end(bp, vf, vfop);
return;
default:
bnx2x_vfop_default(state);
}
op_pending:
return;
}
static int bnx2x_vfop_qdtor_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
struct bnx2x_queue_state_params *qstate =
&vf->op_params.qctor.qstate;
memset(qstate, 0, sizeof(*qstate));
qstate->q_obj = &bnx2x_vfq(vf, qid, sp_obj);
vfop->args.qdtor.qid = qid;
vfop->args.qdtor.cxt = bnx2x_vfq(vf, qid, cxt);
bnx2x_vfop_opset(BNX2X_VFOP_QDTOR_HALT,
bnx2x_vfop_qdtor, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_qdtor,
cmd->block);
}
DP(BNX2X_MSG_IOV, "VF[%d] failed to add a vfop.\n", vf->abs_vfid);
return -ENOMEM;
}
static void
bnx2x_vf_set_igu_info(struct bnx2x *bp, u8 igu_sb_id, u8 abs_vfid)
{
struct bnx2x_virtf *vf = bnx2x_vf_by_abs_fid(bp, abs_vfid);
if (vf) {
if (!vf_sb_count(vf))
vf->igu_base_id = igu_sb_id;
++vf_sb_count(vf);
}
}
static inline void bnx2x_vfop_credit(struct bnx2x *bp,
struct bnx2x_vfop *vfop,
struct bnx2x_vlan_mac_obj *obj)
{
struct bnx2x_vfop_args_filters *args = &vfop->args.filters;
if (!vfop->rc && args->credit) {
int cnt = 0;
struct list_head *pos;
list_for_each(pos, &obj->head)
cnt++;
atomic_set(args->credit, cnt);
}
}
static int bnx2x_vfop_set_user_req(struct bnx2x *bp,
struct bnx2x_vfop_filter *pos,
struct bnx2x_vlan_mac_data *user_req)
{
user_req->cmd = pos->add ? BNX2X_VLAN_MAC_ADD :
BNX2X_VLAN_MAC_DEL;
switch (pos->type) {
case BNX2X_VFOP_FILTER_MAC:
memcpy(user_req->u.mac.mac, pos->mac, ETH_ALEN);
break;
case BNX2X_VFOP_FILTER_VLAN:
user_req->u.vlan.vlan = pos->vid;
break;
default:
BNX2X_ERR("Invalid filter type, skipping\n");
return 1;
}
return 0;
}
static int bnx2x_vfop_config_list(struct bnx2x *bp,
struct bnx2x_vfop_filters *filters,
struct bnx2x_vlan_mac_ramrod_params *vlan_mac)
{
struct bnx2x_vfop_filter *pos, *tmp;
struct list_head rollback_list, *filters_list = &filters->head;
struct bnx2x_vlan_mac_data *user_req = &vlan_mac->user_req;
int rc = 0, cnt = 0;
INIT_LIST_HEAD(&rollback_list);
list_for_each_entry_safe(pos, tmp, filters_list, link) {
if (bnx2x_vfop_set_user_req(bp, pos, user_req))
continue;
rc = bnx2x_config_vlan_mac(bp, vlan_mac);
if (rc >= 0) {
cnt += pos->add ? 1 : -1;
list_move(&pos->link, &rollback_list);
rc = 0;
} else if (rc == -EEXIST) {
rc = 0;
} else {
BNX2X_ERR("Failed to add a new vlan_mac command\n");
break;
}
}
if (rc || cnt > filters->add_cnt) {
BNX2X_ERR("error or too many rules added. Performing rollback\n");
list_for_each_entry_safe(pos, tmp, &rollback_list, link) {
pos->add = !pos->add;
bnx2x_vfop_set_user_req(bp, pos, user_req);
bnx2x_config_vlan_mac(bp, vlan_mac);
list_del(&pos->link);
}
cnt = 0;
if (!rc)
rc = -EINVAL;
}
filters->add_cnt = cnt;
return rc;
}
static void bnx2x_vfop_vlan_mac(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_vlan_mac_ramrod_params *vlan_mac = &vfop->op_p->vlan_mac;
struct bnx2x_vlan_mac_obj *obj = vlan_mac->vlan_mac_obj;
struct bnx2x_vfop_filters *filters = vfop->args.filters.multi_filter;
enum bnx2x_vfop_vlan_mac_state state = vfop->state;
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
bnx2x_vfop_reset_wq(vf);
switch (state) {
case BNX2X_VFOP_VLAN_MAC_CLEAR:
vfop->state = BNX2X_VFOP_VLAN_MAC_CHK_DONE;
vfop->rc = obj->delete_all(bp, obj,
&vlan_mac->user_req.vlan_mac_flags,
&vlan_mac->ramrod_flags);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
case BNX2X_VFOP_VLAN_MAC_CONFIG_SINGLE:
vfop->state = BNX2X_VFOP_VLAN_MAC_CHK_DONE;
vfop->rc = bnx2x_config_vlan_mac(bp, vlan_mac);
if (vfop->rc == -EEXIST)
vfop->rc = 0;
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
case BNX2X_VFOP_VLAN_MAC_CHK_DONE:
vfop->rc = !!obj->raw.check_pending(&obj->raw);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
case BNX2X_VFOP_MAC_CONFIG_LIST:
vfop->state = BNX2X_VFOP_VLAN_MAC_CHK_DONE;
vfop->rc = bnx2x_vfop_config_list(bp, filters, vlan_mac);
if (vfop->rc)
goto op_err;
set_bit(RAMROD_CONT, &vlan_mac->ramrod_flags);
vfop->rc = bnx2x_config_vlan_mac(bp, vlan_mac);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
case BNX2X_VFOP_VLAN_CONFIG_LIST:
vfop->state = BNX2X_VFOP_VLAN_MAC_CHK_DONE;
vfop->rc = bnx2x_vfop_config_list(bp, filters, vlan_mac);
if (!vfop->rc) {
set_bit(RAMROD_CONT, &vlan_mac->ramrod_flags);
vfop->rc = bnx2x_config_vlan_mac(bp, vlan_mac);
}
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
default:
bnx2x_vfop_default(state);
}
op_err:
BNX2X_ERR("VLAN-MAC error: rc %d\n", vfop->rc);
op_done:
kfree(filters);
bnx2x_vfop_credit(bp, vfop, obj);
bnx2x_vfop_end(bp, vf, vfop);
op_pending:
return;
}
static void
bnx2x_vfop_vlan_mac_prep_ramrod(struct bnx2x_vlan_mac_ramrod_params *ramrod,
struct bnx2x_vfop_vlan_mac_flags *flags)
{
struct bnx2x_vlan_mac_data *ureq = &ramrod->user_req;
memset(ramrod, 0, sizeof(*ramrod));
if (flags->drv_only)
set_bit(RAMROD_DRV_CLR_ONLY, &ramrod->ramrod_flags);
if (flags->single_cmd)
set_bit(RAMROD_EXEC, &ramrod->ramrod_flags);
if (flags->dont_consume)
set_bit(BNX2X_DONT_CONSUME_CAM_CREDIT, &ureq->vlan_mac_flags);
ureq->cmd = flags->add ? BNX2X_VLAN_MAC_ADD : BNX2X_VLAN_MAC_DEL;
}
static inline void
bnx2x_vfop_mac_prep_ramrod(struct bnx2x_vlan_mac_ramrod_params *ramrod,
struct bnx2x_vfop_vlan_mac_flags *flags)
{
bnx2x_vfop_vlan_mac_prep_ramrod(ramrod, flags);
set_bit(BNX2X_ETH_MAC, &ramrod->user_req.vlan_mac_flags);
}
static int bnx2x_vfop_mac_delall_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid, bool drv_only)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
struct bnx2x_vfop_args_filters filters = {
.multi_filter = NULL,
.credit = NULL,
};
struct bnx2x_vfop_vlan_mac_flags flags = {
.drv_only = drv_only,
.dont_consume = (filters.credit != NULL),
.single_cmd = true,
.add = false ,
};
struct bnx2x_vlan_mac_ramrod_params *ramrod =
&vf->op_params.vlan_mac;
bnx2x_vfop_mac_prep_ramrod(ramrod, &flags);
ramrod->vlan_mac_obj = &bnx2x_vfq(vf, qid, mac_obj);
vfop->args.filters = filters;
bnx2x_vfop_opset(BNX2X_VFOP_VLAN_MAC_CLEAR,
bnx2x_vfop_vlan_mac, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_vlan_mac,
cmd->block);
}
return -ENOMEM;
}
int bnx2x_vfop_mac_list_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
struct bnx2x_vfop_filters *macs,
int qid, bool drv_only)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
struct bnx2x_vfop_args_filters filters = {
.multi_filter = macs,
.credit = NULL,
};
struct bnx2x_vfop_vlan_mac_flags flags = {
.drv_only = drv_only,
.dont_consume = (filters.credit != NULL),
.single_cmd = false,
.add = false,
};
struct bnx2x_vlan_mac_ramrod_params *ramrod =
&vf->op_params.vlan_mac;
bnx2x_vfop_mac_prep_ramrod(ramrod, &flags);
ramrod->vlan_mac_obj = &bnx2x_vfq(vf, qid, mac_obj);
filters.multi_filter->add_cnt = BNX2X_VFOP_FILTER_ADD_CNT_MAX;
vfop->args.filters = filters;
bnx2x_vfop_opset(BNX2X_VFOP_MAC_CONFIG_LIST,
bnx2x_vfop_vlan_mac, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_vlan_mac,
cmd->block);
}
return -ENOMEM;
}
int bnx2x_vfop_vlan_set_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid, u16 vid, bool add)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
struct bnx2x_vfop_args_filters filters = {
.multi_filter = NULL,
.credit = &bnx2x_vfq(vf, qid, vlan_count),
};
struct bnx2x_vfop_vlan_mac_flags flags = {
.drv_only = false,
.dont_consume = (filters.credit != NULL),
.single_cmd = true,
.add = add,
};
struct bnx2x_vlan_mac_ramrod_params *ramrod =
&vf->op_params.vlan_mac;
bnx2x_vfop_vlan_mac_prep_ramrod(ramrod, &flags);
ramrod->user_req.u.vlan.vlan = vid;
ramrod->vlan_mac_obj = &bnx2x_vfq(vf, qid, vlan_obj);
vfop->args.filters = filters;
bnx2x_vfop_opset(BNX2X_VFOP_VLAN_MAC_CONFIG_SINGLE,
bnx2x_vfop_vlan_mac, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_vlan_mac,
cmd->block);
}
return -ENOMEM;
}
static int bnx2x_vfop_vlan_delall_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid, bool drv_only)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
struct bnx2x_vfop_args_filters filters = {
.multi_filter = NULL,
.credit = &bnx2x_vfq(vf, qid, vlan_count),
};
struct bnx2x_vfop_vlan_mac_flags flags = {
.drv_only = drv_only,
.dont_consume = (filters.credit != NULL),
.single_cmd = true,
.add = false,
};
struct bnx2x_vlan_mac_ramrod_params *ramrod =
&vf->op_params.vlan_mac;
bnx2x_vfop_vlan_mac_prep_ramrod(ramrod, &flags);
ramrod->vlan_mac_obj = &bnx2x_vfq(vf, qid, vlan_obj);
vfop->args.filters = filters;
bnx2x_vfop_opset(BNX2X_VFOP_VLAN_MAC_CLEAR,
bnx2x_vfop_vlan_mac, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_vlan_mac,
cmd->block);
}
return -ENOMEM;
}
int bnx2x_vfop_vlan_list_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
struct bnx2x_vfop_filters *vlans,
int qid, bool drv_only)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
struct bnx2x_vfop_args_filters filters = {
.multi_filter = vlans,
.credit = &bnx2x_vfq(vf, qid, vlan_count),
};
struct bnx2x_vfop_vlan_mac_flags flags = {
.drv_only = drv_only,
.dont_consume = (filters.credit != NULL),
.single_cmd = false,
.add = false,
};
struct bnx2x_vlan_mac_ramrod_params *ramrod =
&vf->op_params.vlan_mac;
bnx2x_vfop_vlan_mac_prep_ramrod(ramrod, &flags);
ramrod->vlan_mac_obj = &bnx2x_vfq(vf, qid, vlan_obj);
filters.multi_filter->add_cnt = vf_vlan_rules_cnt(vf) -
atomic_read(filters.credit);
vfop->args.filters = filters;
bnx2x_vfop_opset(BNX2X_VFOP_VLAN_CONFIG_LIST,
bnx2x_vfop_vlan_mac, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_vlan_mac,
cmd->block);
}
return -ENOMEM;
}
static void bnx2x_vfop_qsetup(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
int qid = vfop->args.qctor.qid;
enum bnx2x_vfop_qsetup_state state = vfop->state;
struct bnx2x_vfop_cmd cmd = {
.done = bnx2x_vfop_qsetup,
.block = false,
};
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
switch (state) {
case BNX2X_VFOP_QSETUP_CTOR:
vfop->state = BNX2X_VFOP_QSETUP_VLAN0;
vfop->rc = bnx2x_vfop_qctor_cmd(bp, vf, &cmd, qid);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_QSETUP_VLAN0:
if (qid)
goto op_done;
vfop->state = BNX2X_VFOP_QSETUP_DONE;
vfop->rc = bnx2x_vfop_vlan_set_cmd(bp, vf, &cmd, qid, 0, true);
if (vfop->rc)
goto op_err;
return;
op_err:
BNX2X_ERR("QSETUP[%d:%d] error: rc %d\n", vf->abs_vfid, qid, vfop->rc);
op_done:
case BNX2X_VFOP_QSETUP_DONE:
vf->cfg_flags |= VF_CFG_VLAN;
smp_mb__before_clear_bit();
set_bit(BNX2X_SP_RTNL_HYPERVISOR_VLAN,
&bp->sp_rtnl_state);
smp_mb__after_clear_bit();
schedule_delayed_work(&bp->sp_rtnl_task, 0);
bnx2x_vfop_end(bp, vf, vfop);
return;
default:
bnx2x_vfop_default(state);
}
}
int bnx2x_vfop_qsetup_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
vfop->args.qctor.qid = qid;
bnx2x_vfop_opset(BNX2X_VFOP_QSETUP_CTOR,
bnx2x_vfop_qsetup, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_qsetup,
cmd->block);
}
return -ENOMEM;
}
static void bnx2x_vfop_qflr(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
int qid = vfop->args.qx.qid;
enum bnx2x_vfop_qflr_state state = vfop->state;
struct bnx2x_queue_state_params *qstate;
struct bnx2x_vfop_cmd cmd;
bnx2x_vfop_reset_wq(vf);
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "VF[%d] STATE: %d\n", vf->abs_vfid, state);
cmd.done = bnx2x_vfop_qflr;
cmd.block = false;
switch (state) {
case BNX2X_VFOP_QFLR_CLR_VLAN:
vfop->state = BNX2X_VFOP_QFLR_CLR_MAC;
vfop->rc = bnx2x_vfop_vlan_delall_cmd(bp, vf, &cmd, qid, true);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_QFLR_CLR_MAC:
vfop->state = BNX2X_VFOP_QFLR_TERMINATE;
vfop->rc = bnx2x_vfop_mac_delall_cmd(bp, vf, &cmd, qid, true);
DP(BNX2X_MSG_IOV,
"VF[%d] vfop->rc after bnx2x_vfop_mac_delall_cmd was %d",
vf->abs_vfid, vfop->rc);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_QFLR_TERMINATE:
qstate = &vfop->op_p->qctor.qstate;
memset(qstate , 0, sizeof(*qstate));
qstate->q_obj = &bnx2x_vfq(vf, qid, sp_obj);
vfop->state = BNX2X_VFOP_QFLR_DONE;
DP(BNX2X_MSG_IOV, "VF[%d] qstate during flr was %d\n",
vf->abs_vfid, qstate->q_obj->state);
if (qstate->q_obj->state != BNX2X_Q_STATE_RESET) {
qstate->q_obj->state = BNX2X_Q_STATE_STOPPED;
qstate->cmd = BNX2X_Q_CMD_TERMINATE;
vfop->rc = bnx2x_queue_state_change(bp, qstate);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_VERIFY_PEND);
} else {
goto op_done;
}
op_err:
BNX2X_ERR("QFLR[%d:%d] error: rc %d\n",
vf->abs_vfid, qid, vfop->rc);
op_done:
case BNX2X_VFOP_QFLR_DONE:
bnx2x_vfop_end(bp, vf, vfop);
return;
default:
bnx2x_vfop_default(state);
}
op_pending:
return;
}
static int bnx2x_vfop_qflr_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
vfop->args.qx.qid = qid;
bnx2x_vfop_opset(BNX2X_VFOP_QFLR_CLR_VLAN,
bnx2x_vfop_qflr, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_qflr,
cmd->block);
}
return -ENOMEM;
}
static void bnx2x_vfop_mcast(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_mcast_ramrod_params *mcast = &vfop->op_p->mcast;
struct bnx2x_raw_obj *raw = &mcast->mcast_obj->raw;
struct bnx2x_vfop_args_mcast *args = &vfop->args.mc_list;
enum bnx2x_vfop_mcast_state state = vfop->state;
int i;
bnx2x_vfop_reset_wq(vf);
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
switch (state) {
case BNX2X_VFOP_MCAST_DEL:
vfop->state = BNX2X_VFOP_MCAST_ADD;
vfop->rc = bnx2x_config_mcast(bp, mcast, BNX2X_MCAST_CMD_DEL);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_CONT);
case BNX2X_VFOP_MCAST_ADD:
if (raw->check_pending(raw))
goto op_pending;
if (args->mc_num) {
INIT_LIST_HEAD(&mcast->mcast_list);
for (i = 0; i < args->mc_num; i++)
list_add_tail(&(args->mc[i].link),
&mcast->mcast_list);
vfop->state = BNX2X_VFOP_MCAST_CHK_DONE;
vfop->rc = bnx2x_config_mcast(bp, mcast,
BNX2X_MCAST_CMD_ADD);
}
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
case BNX2X_VFOP_MCAST_CHK_DONE:
vfop->rc = raw->check_pending(raw) ? 1 : 0;
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
default:
bnx2x_vfop_default(state);
}
op_err:
BNX2X_ERR("MCAST CONFIG error: rc %d\n", vfop->rc);
op_done:
kfree(args->mc);
bnx2x_vfop_end(bp, vf, vfop);
op_pending:
return;
}
int bnx2x_vfop_mcast_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
bnx2x_mac_addr_t *mcasts,
int mcast_num, bool drv_only)
{
struct bnx2x_vfop *vfop = NULL;
size_t mc_sz = mcast_num * sizeof(struct bnx2x_mcast_list_elem);
struct bnx2x_mcast_list_elem *mc = mc_sz ? kzalloc(mc_sz, GFP_KERNEL) :
NULL;
if (!mc_sz || mc) {
vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
int i;
struct bnx2x_mcast_ramrod_params *ramrod =
&vf->op_params.mcast;
memset(ramrod, 0, sizeof(*ramrod));
ramrod->mcast_obj = &vf->mcast_obj;
if (drv_only)
set_bit(RAMROD_DRV_CLR_ONLY,
&ramrod->ramrod_flags);
vfop->args.mc_list.mc_num = mcast_num;
vfop->args.mc_list.mc = mc;
for (i = 0; i < mcast_num; i++)
mc[i].mac = mcasts[i];
bnx2x_vfop_opset(BNX2X_VFOP_MCAST_DEL,
bnx2x_vfop_mcast, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_mcast,
cmd->block);
} else {
kfree(mc);
}
}
return -ENOMEM;
}
static void bnx2x_vfop_rxmode(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_rx_mode_ramrod_params *ramrod = &vfop->op_p->rx_mode;
enum bnx2x_vfop_rxmode_state state = vfop->state;
bnx2x_vfop_reset_wq(vf);
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
switch (state) {
case BNX2X_VFOP_RXMODE_CONFIG:
vfop->state = BNX2X_VFOP_RXMODE_DONE;
vfop->rc = bnx2x_config_rx_mode(bp, ramrod);
bnx2x_vfop_finalize(vf, vfop->rc, VFOP_DONE);
op_err:
BNX2X_ERR("RXMODE error: rc %d\n", vfop->rc);
op_done:
case BNX2X_VFOP_RXMODE_DONE:
bnx2x_vfop_end(bp, vf, vfop);
return;
default:
bnx2x_vfop_default(state);
}
op_pending:
return;
}
int bnx2x_vfop_rxmode_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid, unsigned long accept_flags)
{
struct bnx2x_vf_queue *vfq = vfq_get(vf, qid);
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
struct bnx2x_rx_mode_ramrod_params *ramrod =
&vf->op_params.rx_mode;
memset(ramrod, 0, sizeof(*ramrod));
ramrod->cid = vfq->cid;
ramrod->cl_id = vfq_cl_id(vf, vfq);
ramrod->rx_mode_obj = &bp->rx_mode_obj;
ramrod->func_id = FW_VF_HANDLE(vf->abs_vfid);
ramrod->rx_accept_flags = accept_flags;
ramrod->tx_accept_flags = accept_flags;
ramrod->pstate = &vf->filter_state;
ramrod->state = BNX2X_FILTER_RX_MODE_PENDING;
set_bit(BNX2X_FILTER_RX_MODE_PENDING, &vf->filter_state);
set_bit(RAMROD_RX, &ramrod->ramrod_flags);
set_bit(RAMROD_TX, &ramrod->ramrod_flags);
ramrod->rdata =
bnx2x_vf_sp(bp, vf, rx_mode_rdata.e2);
ramrod->rdata_mapping =
bnx2x_vf_sp_map(bp, vf, rx_mode_rdata.e2);
bnx2x_vfop_opset(BNX2X_VFOP_RXMODE_CONFIG,
bnx2x_vfop_rxmode, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_rxmode,
cmd->block);
}
return -ENOMEM;
}
static void bnx2x_vfop_qdown(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
int qid = vfop->args.qx.qid;
enum bnx2x_vfop_qteardown_state state = vfop->state;
struct bnx2x_vfop_cmd cmd;
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
cmd.done = bnx2x_vfop_qdown;
cmd.block = false;
switch (state) {
case BNX2X_VFOP_QTEARDOWN_RXMODE:
vfop->state = BNX2X_VFOP_QTEARDOWN_CLR_VLAN;
vfop->rc = bnx2x_vfop_rxmode_cmd(bp, vf, &cmd, qid, 0);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_QTEARDOWN_CLR_VLAN:
vfop->state = BNX2X_VFOP_QTEARDOWN_CLR_MAC;
vfop->rc = bnx2x_vfop_vlan_delall_cmd(bp, vf, &cmd, qid, false);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_QTEARDOWN_CLR_MAC:
vfop->state = BNX2X_VFOP_QTEARDOWN_QDTOR;
vfop->rc = bnx2x_vfop_mac_delall_cmd(bp, vf, &cmd, qid, false);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_QTEARDOWN_QDTOR:
DP(BNX2X_MSG_IOV, "case: BNX2X_VFOP_QTEARDOWN_QDTOR\n");
vfop->state = BNX2X_VFOP_QTEARDOWN_DONE;
DP(BNX2X_MSG_IOV, "new state: BNX2X_VFOP_QTEARDOWN_DONE\n");
vfop->rc = bnx2x_vfop_qdtor_cmd(bp, vf, &cmd, qid);
DP(BNX2X_MSG_IOV, "returned from cmd\n");
if (vfop->rc)
goto op_err;
return;
op_err:
BNX2X_ERR("QTEARDOWN[%d:%d] error: rc %d\n",
vf->abs_vfid, qid, vfop->rc);
case BNX2X_VFOP_QTEARDOWN_DONE:
bnx2x_vfop_end(bp, vf, vfop);
return;
default:
bnx2x_vfop_default(state);
}
}
int bnx2x_vfop_qdown_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd,
int qid)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
vfop->args.qx.qid = qid;
bnx2x_vfop_opset(BNX2X_VFOP_QTEARDOWN_RXMODE,
bnx2x_vfop_qdown, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_qdown,
cmd->block);
}
return -ENOMEM;
}
static void bnx2x_vf_enable_internal(struct bnx2x *bp, u8 enable)
{
REG_WR(bp, PGLUE_B_REG_INTERNAL_VFID_ENABLE, enable ? 1 : 0);
}
static void bnx2x_vf_semi_clear_err(struct bnx2x *bp, u8 abs_vfid)
{
REG_WR(bp, TSEM_REG_VFPF_ERR_NUM, abs_vfid);
REG_WR(bp, USEM_REG_VFPF_ERR_NUM, abs_vfid);
REG_WR(bp, CSEM_REG_VFPF_ERR_NUM, abs_vfid);
REG_WR(bp, XSEM_REG_VFPF_ERR_NUM, abs_vfid);
}
static void bnx2x_vf_pglue_clear_err(struct bnx2x *bp, u8 abs_vfid)
{
u32 was_err_group = (2 * BP_PATH(bp) + abs_vfid) >> 5;
u32 was_err_reg = 0;
switch (was_err_group) {
case 0:
was_err_reg = PGLUE_B_REG_WAS_ERROR_VF_31_0_CLR;
break;
case 1:
was_err_reg = PGLUE_B_REG_WAS_ERROR_VF_63_32_CLR;
break;
case 2:
was_err_reg = PGLUE_B_REG_WAS_ERROR_VF_95_64_CLR;
break;
case 3:
was_err_reg = PGLUE_B_REG_WAS_ERROR_VF_127_96_CLR;
break;
}
REG_WR(bp, was_err_reg, 1 << (abs_vfid & 0x1f));
}
static void bnx2x_vf_igu_reset(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
int i;
u32 val;
bnx2x_pretend_func(bp, HW_VF_HANDLE(bp, vf->abs_vfid));
REG_WR(bp, IGU_REG_SB_INT_BEFORE_MASK_LSB, 0);
REG_WR(bp, IGU_REG_SB_INT_BEFORE_MASK_MSB, 0);
REG_WR(bp, IGU_REG_SB_MASK_LSB, 0);
REG_WR(bp, IGU_REG_SB_MASK_MSB, 0);
REG_WR(bp, IGU_REG_PBA_STATUS_LSB, 0);
REG_WR(bp, IGU_REG_PBA_STATUS_MSB, 0);
val = REG_RD(bp, IGU_REG_VF_CONFIGURATION);
val |= (IGU_VF_CONF_FUNC_EN | IGU_VF_CONF_MSI_MSIX_EN);
if (vf->cfg_flags & VF_CFG_INT_SIMD)
val |= IGU_VF_CONF_SINGLE_ISR_EN;
val &= ~IGU_VF_CONF_PARENT_MASK;
val |= BP_FUNC(bp) << IGU_VF_CONF_PARENT_SHIFT;
REG_WR(bp, IGU_REG_VF_CONFIGURATION, val);
DP(BNX2X_MSG_IOV,
"value in IGU_REG_VF_CONFIGURATION of vf %d after write %x\n",
vf->abs_vfid, REG_RD(bp, IGU_REG_VF_CONFIGURATION));
bnx2x_pretend_func(bp, BP_ABS_FUNC(bp));
for (i = 0; i < vf_sb_count(vf); i++) {
u8 igu_sb_id = vf_igu_sb(vf, i);
REG_WR(bp, IGU_REG_PROD_CONS_MEMORY + igu_sb_id * 4, 0);
bnx2x_igu_clear_sb_gen(bp, vf->abs_vfid, igu_sb_id,
false );
bnx2x_vf_igu_ack_sb(bp, vf, igu_sb_id, USTORM_ID, 0,
IGU_INT_DISABLE, 1);
}
}
void bnx2x_vf_enable_access(struct bnx2x *bp, u8 abs_vfid)
{
storm_memset_vf_to_pf(bp, FW_VF_HANDLE(abs_vfid), BP_FUNC(bp));
storm_memset_func_en(bp, FW_VF_HANDLE(abs_vfid), 1);
bnx2x_vf_semi_clear_err(bp, abs_vfid);
bnx2x_vf_pglue_clear_err(bp, abs_vfid);
bnx2x_pretend_func(bp, HW_VF_HANDLE(bp, abs_vfid));
DP(BNX2X_MSG_IOV, "enabling internal access for vf %x\n", abs_vfid);
bnx2x_vf_enable_internal(bp, true);
bnx2x_pretend_func(bp, BP_ABS_FUNC(bp));
}
static void bnx2x_vf_enable_traffic(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
bnx2x_vf_igu_reset(bp, vf);
bnx2x_pretend_func(bp, HW_VF_HANDLE(bp, vf->abs_vfid));
REG_WR(bp, PBF_REG_DISABLE_VF, 0);
bnx2x_pretend_func(bp, BP_ABS_FUNC(bp));
}
static u8 bnx2x_vf_is_pcie_pending(struct bnx2x *bp, u8 abs_vfid)
{
struct pci_dev *dev;
struct bnx2x_virtf *vf = bnx2x_vf_by_abs_fid(bp, abs_vfid);
if (!vf)
return false;
dev = pci_get_bus_and_slot(vf->bus, vf->devfn);
if (dev)
return bnx2x_is_pcie_pending(dev);
return false;
}
int bnx2x_vf_flr_clnup_epilog(struct bnx2x *bp, u8 abs_vfid)
{
if (bnx2x_vf_is_pcie_pending(bp, abs_vfid))
BNX2X_ERR("PCIE Transactions still pending\n");
return 0;
}
static void
bnx2x_iov_static_resc(struct bnx2x *bp, struct vf_pf_resc_request *resc)
{
u16 vlan_count = 0;
resc->num_rxqs = 0;
resc->num_txqs = 0;
resc->num_mac_filters = 1;
vlan_count = bp->vlans_pool.check(&bp->vlans_pool);
vlan_count = 1 << ilog2(vlan_count);
resc->num_vlan_filters = vlan_count / BNX2X_NR_VIRTFN(bp);
resc->num_mc_filters = 0;
}
static void bnx2x_vf_free_resc(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
bnx2x_iov_static_resc(bp, &vf->alloc_resc);
vf->state = VF_FREE;
}
static void bnx2x_vf_flr_clnup_hw(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
u32 poll_cnt = bnx2x_flr_clnup_poll_count(bp);
bnx2x_pretend_func(bp, HW_VF_HANDLE(bp, vf->abs_vfid));
bnx2x_flr_clnup_poll_hw_counter(bp, DORQ_REG_VF_USAGE_CNT,
"DQ VF usage counter timed out",
poll_cnt);
bnx2x_pretend_func(bp, BP_ABS_FUNC(bp));
if (bnx2x_send_final_clnup(bp, (u8)FW_VF_HANDLE(vf->abs_vfid),
poll_cnt))
BNX2X_ERR("VF[%d] Final cleanup timed-out\n", vf->abs_vfid);
bnx2x_tx_hw_flushed(bp, poll_cnt);
}
static void bnx2x_vfop_flr(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_vfop_args_qx *qx = &vfop->args.qx;
enum bnx2x_vfop_flr_state state = vfop->state;
struct bnx2x_vfop_cmd cmd = {
.done = bnx2x_vfop_flr,
.block = false,
};
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
switch (state) {
case BNX2X_VFOP_FLR_QUEUES:
if (++(qx->qid) < vf_rxq_count(vf)) {
vfop->rc = bnx2x_vfop_qflr_cmd(bp, vf, &cmd,
qx->qid);
if (vfop->rc)
goto op_err;
return;
}
vfop->state = BNX2X_VFOP_FLR_HW;
vfop->rc = bnx2x_vfop_mcast_cmd(bp, vf, &cmd, NULL,
0, true);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_FLR_HW:
bnx2x_vf_flr_clnup_hw(bp, vf);
bnx2x_vf_free_resc(bp, vf);
bnx2x_vf_enable_mbx(bp, vf->abs_vfid);
goto op_done;
default:
bnx2x_vfop_default(state);
}
op_err:
BNX2X_ERR("VF[%d] FLR error: rc %d\n", vf->abs_vfid, vfop->rc);
op_done:
vf->flr_clnup_stage = VF_FLR_ACK;
bnx2x_vfop_end(bp, vf, vfop);
bnx2x_unlock_vf_pf_channel(bp, vf, CHANNEL_TLV_FLR);
}
static int bnx2x_vfop_flr_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
vfop_handler_t done)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
vfop->args.qx.qid = -1;
bnx2x_vfop_opset(BNX2X_VFOP_FLR_QUEUES,
bnx2x_vfop_flr, done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_flr, false);
}
return -ENOMEM;
}
static void bnx2x_vf_flr_clnup(struct bnx2x *bp, struct bnx2x_virtf *prev_vf)
{
int i = prev_vf ? prev_vf->index + 1 : 0;
struct bnx2x_virtf *vf;
next_vf_to_clean:
for (;
i < BNX2X_NR_VIRTFN(bp) &&
(bnx2x_vf(bp, i, state) != VF_RESET ||
bnx2x_vf(bp, i, flr_clnup_stage) != VF_FLR_CLN);
i++)
;
DP(BNX2X_MSG_IOV, "next vf to cleanup: %d. Num of vfs: %d\n", i,
BNX2X_NR_VIRTFN(bp));
if (i < BNX2X_NR_VIRTFN(bp)) {
vf = BP_VF(bp, i);
bnx2x_lock_vf_pf_channel(bp, vf, CHANNEL_TLV_FLR);
if (bnx2x_vfop_flr_cmd(bp, vf, bnx2x_vf_flr_clnup)) {
BNX2X_ERR("VF[%d]: FLR cleanup failed -ENOMEM\n",
vf->abs_vfid);
vf->flr_clnup_stage = VF_FLR_ACK;
goto next_vf_to_clean;
}
return;
}
for_each_vf(bp, i) {
vf = BP_VF(bp, i);
if (vf->flr_clnup_stage != VF_FLR_ACK)
continue;
vf->flr_clnup_stage = VF_FLR_EPILOG;
}
DP(BNX2X_MSG_MCP, "DRV_STATUS_VF_DISABLED ACK for vfs 0x%x 0x%x\n",
bp->vfdb->flrd_vfs[0], bp->vfdb->flrd_vfs[1]);
for (i = 0; i < FLRD_VFS_DWORDS; i++)
SHMEM2_WR(bp, drv_ack_vf_disabled[BP_FW_MB_IDX(bp)][i],
bp->vfdb->flrd_vfs[i]);
bnx2x_fw_command(bp, DRV_MSG_CODE_VF_DISABLED_DONE, 0);
for (i = 0; i < FLRD_VFS_DWORDS; i++)
SHMEM2_WR(bp, drv_ack_vf_disabled[BP_FW_MB_IDX(bp)][i], 0);
}
void bnx2x_vf_handle_flr_event(struct bnx2x *bp)
{
int i;
for (i = 0; i < FLRD_VFS_DWORDS; i++)
bp->vfdb->flrd_vfs[i] = SHMEM2_RD(bp, mcp_vf_disabled[i]);
DP(BNX2X_MSG_MCP,
"DRV_STATUS_VF_DISABLED received for vfs 0x%x 0x%x\n",
bp->vfdb->flrd_vfs[0], bp->vfdb->flrd_vfs[1]);
for_each_vf(bp, i) {
struct bnx2x_virtf *vf = BP_VF(bp, i);
u32 reset = 0;
if (vf->abs_vfid < 32)
reset = bp->vfdb->flrd_vfs[0] & (1 << vf->abs_vfid);
else
reset = bp->vfdb->flrd_vfs[1] &
(1 << (vf->abs_vfid - 32));
if (reset) {
vf->state = VF_RESET;
vf->flr_clnup_stage = VF_FLR_CLN;
DP(BNX2X_MSG_IOV,
"Initiating Final cleanup for VF %d\n",
vf->abs_vfid);
}
}
bnx2x_vf_flr_clnup(bp, NULL);
}
void bnx2x_iov_init_dq(struct bnx2x *bp)
{
if (!IS_SRIOV(bp))
return;
REG_WR(bp, DORQ_REG_VF_NORM_VF_BASE, 0);
REG_WR(bp, DORQ_REG_MAX_RVFID_SIZE, ilog2(BNX2X_MAX_NUM_OF_VFS));
REG_WR(bp, DORQ_REG_VF_NORM_CID_BASE, BNX2X_FIRST_VF_CID);
REG_WR(bp, DORQ_REG_VF_NORM_CID_WND_SIZE, BNX2X_VF_CID_WND);
REG_WR(bp, DORQ_REG_VF_NORM_CID_OFST,
BNX2X_DB_SHIFT - BNX2X_DB_MIN_SHIFT);
REG_WR(bp, DORQ_REG_VF_TYPE_MASK_0, 1);
REG_WR(bp, DORQ_REG_VF_TYPE_VALUE_0, 0);
REG_WR(bp, DORQ_REG_VF_TYPE_MIN_MCID_0, 0);
REG_WR(bp, DORQ_REG_VF_TYPE_MAX_MCID_0, 0x1ffff);
REG_WR(bp, DORQ_REG_VF_NORM_MAX_CID_COUNT, 0x20000);
REG_WR(bp, DORQ_REG_VF_USAGE_CT_LIMIT, 4);
}
void bnx2x_iov_init_dmae(struct bnx2x *bp)
{
if (pci_find_ext_capability(bp->pdev, PCI_EXT_CAP_ID_SRIOV))
REG_WR(bp, DMAE_REG_BACKWARD_COMP_EN, 0);
}
static int bnx2x_vf_bus(struct bnx2x *bp, int vfid)
{
struct pci_dev *dev = bp->pdev;
struct bnx2x_sriov *iov = &bp->vfdb->sriov;
return dev->bus->number + ((dev->devfn + iov->offset +
iov->stride * vfid) >> 8);
}
static int bnx2x_vf_devfn(struct bnx2x *bp, int vfid)
{
struct pci_dev *dev = bp->pdev;
struct bnx2x_sriov *iov = &bp->vfdb->sriov;
return (dev->devfn + iov->offset + iov->stride * vfid) & 0xff;
}
static void bnx2x_vf_set_bars(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
int i, n;
struct pci_dev *dev = bp->pdev;
struct bnx2x_sriov *iov = &bp->vfdb->sriov;
for (i = 0, n = 0; i < PCI_SRIOV_NUM_BARS; i += 2, n++) {
u64 start = pci_resource_start(dev, PCI_IOV_RESOURCES + i);
u32 size = pci_resource_len(dev, PCI_IOV_RESOURCES + i);
size /= iov->total;
vf->bars[n].bar = start + size * vf->abs_vfid;
vf->bars[n].size = size;
}
}
static int bnx2x_ari_enabled(struct pci_dev *dev)
{
return dev->bus->self && dev->bus->self->ari_enabled;
}
static void
bnx2x_get_vf_igu_cam_info(struct bnx2x *bp)
{
int sb_id;
u32 val;
u8 fid;
for (sb_id = 0; sb_id < IGU_REG_MAPPING_MEMORY_SIZE; sb_id++) {
val = REG_RD(bp, IGU_REG_MAPPING_MEMORY + sb_id * 4);
if (!(val & IGU_REG_MAPPING_MEMORY_VALID))
continue;
fid = GET_FIELD((val), IGU_REG_MAPPING_MEMORY_FID);
if (!(fid & IGU_FID_ENCODE_IS_PF))
bnx2x_vf_set_igu_info(bp, sb_id,
(fid & IGU_FID_VF_NUM_MASK));
DP(BNX2X_MSG_IOV, "%s[%d], igu_sb_id=%d, msix=%d\n",
((fid & IGU_FID_ENCODE_IS_PF) ? "PF" : "VF"),
((fid & IGU_FID_ENCODE_IS_PF) ? (fid & IGU_FID_PF_NUM_MASK) :
(fid & IGU_FID_VF_NUM_MASK)), sb_id,
GET_FIELD((val), IGU_REG_MAPPING_MEMORY_VECTOR));
}
}
static void __bnx2x_iov_free_vfdb(struct bnx2x *bp)
{
if (bp->vfdb) {
kfree(bp->vfdb->vfqs);
kfree(bp->vfdb->vfs);
kfree(bp->vfdb);
}
bp->vfdb = NULL;
}
static int bnx2x_sriov_pci_cfg_info(struct bnx2x *bp, struct bnx2x_sriov *iov)
{
int pos;
struct pci_dev *dev = bp->pdev;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_SRIOV);
if (!pos) {
BNX2X_ERR("failed to find SRIOV capability in device\n");
return -ENODEV;
}
iov->pos = pos;
DP(BNX2X_MSG_IOV, "sriov ext pos %d\n", pos);
pci_read_config_word(dev, pos + PCI_SRIOV_CTRL, &iov->ctrl);
pci_read_config_word(dev, pos + PCI_SRIOV_TOTAL_VF, &iov->total);
pci_read_config_word(dev, pos + PCI_SRIOV_INITIAL_VF, &iov->initial);
pci_read_config_word(dev, pos + PCI_SRIOV_VF_OFFSET, &iov->offset);
pci_read_config_word(dev, pos + PCI_SRIOV_VF_STRIDE, &iov->stride);
pci_read_config_dword(dev, pos + PCI_SRIOV_SUP_PGSIZE, &iov->pgsz);
pci_read_config_dword(dev, pos + PCI_SRIOV_CAP, &iov->cap);
pci_read_config_byte(dev, pos + PCI_SRIOV_FUNC_LINK, &iov->link);
return 0;
}
static int bnx2x_sriov_info(struct bnx2x *bp, struct bnx2x_sriov *iov)
{
u32 val;
if (bnx2x_sriov_pci_cfg_info(bp, iov))
return -ENODEV;
iov->nres = 0;
val = REG_RD(bp, PCICFG_OFFSET + GRC_CONFIG_REG_PF_INIT_VF);
iov->first_vf_in_pf = ((val & GRC_CR_PF_INIT_VF_PF_FIRST_VF_NUM_MASK)
* 8) - (BNX2X_MAX_NUM_OF_VFS * BP_PATH(bp));
DP(BNX2X_MSG_IOV,
"IOV info[%d]: first vf %d, nres %d, cap 0x%x, ctrl 0x%x, total %d, initial %d, num vfs %d, offset %d, stride %d, page size 0x%x\n",
BP_FUNC(bp),
iov->first_vf_in_pf, iov->nres, iov->cap, iov->ctrl, iov->total,
iov->initial, iov->nr_virtfn, iov->offset, iov->stride, iov->pgsz);
return 0;
}
static u8 bnx2x_iov_get_max_queue_count(struct bnx2x *bp)
{
int i;
u8 queue_count = 0;
if (IS_SRIOV(bp))
for_each_vf(bp, i)
queue_count += bnx2x_vf(bp, i, alloc_resc.num_sbs);
return queue_count;
}
int bnx2x_iov_init_one(struct bnx2x *bp, int int_mode_param,
int num_vfs_param)
{
int err, i, qcount;
struct bnx2x_sriov *iov;
struct pci_dev *dev = bp->pdev;
bp->vfdb = NULL;
if (IS_VF(bp))
return 0;
if (!pci_find_ext_capability(dev, PCI_EXT_CAP_ID_SRIOV))
return 0;
if (CHIP_IS_E1x(bp))
return 0;
if (!num_vfs_param)
return 0;
if (BNX2X_L2_MAX_CID(bp) >= BNX2X_FIRST_VF_CID) {
BNX2X_ERR("PF cids %d are overspilling into vf space (starts at %d). Abort SRIOV\n",
BNX2X_L2_MAX_CID(bp), BNX2X_FIRST_VF_CID);
return 0;
}
if (int_mode_param == BNX2X_INT_MODE_MSI ||
int_mode_param == BNX2X_INT_MODE_INTX) {
BNX2X_ERR("Forced MSI/INTx mode is incompatible with SRIOV\n");
return 0;
}
err = -EIO;
if (!bnx2x_ari_enabled(bp->pdev)) {
BNX2X_ERR("ARI not supported (check pci bridge ARI forwarding), SRIOV can not be enabled\n");
return 0;
}
if (CHIP_INT_MODE_IS_BC(bp)) {
BNX2X_ERR("IGU not normal mode, SRIOV can not be enabled\n");
return 0;
}
bp->vfdb = kzalloc(sizeof(*(bp->vfdb)), GFP_KERNEL);
if (!bp->vfdb) {
BNX2X_ERR("failed to allocate vf database\n");
err = -ENOMEM;
goto failed;
}
iov = &(bp->vfdb->sriov);
err = bnx2x_sriov_info(bp, iov);
if (err)
goto failed;
if (iov->total == 0)
goto failed;
iov->nr_virtfn = min_t(u16, iov->total, num_vfs_param);
DP(BNX2X_MSG_IOV, "num_vfs_param was %d, nr_virtfn was %d\n",
num_vfs_param, iov->nr_virtfn);
bp->vfdb->vfs = kzalloc(sizeof(struct bnx2x_virtf) *
BNX2X_NR_VIRTFN(bp), GFP_KERNEL);
if (!bp->vfdb->vfs) {
BNX2X_ERR("failed to allocate vf array\n");
err = -ENOMEM;
goto failed;
}
for_each_vf(bp, i) {
bnx2x_vf(bp, i, index) = i;
bnx2x_vf(bp, i, abs_vfid) = iov->first_vf_in_pf + i;
bnx2x_vf(bp, i, state) = VF_FREE;
INIT_LIST_HEAD(&bnx2x_vf(bp, i, op_list_head));
mutex_init(&bnx2x_vf(bp, i, op_mutex));
bnx2x_vf(bp, i, op_current) = CHANNEL_TLV_NONE;
}
bnx2x_get_vf_igu_cam_info(bp);
qcount = bnx2x_iov_get_max_queue_count(bp);
bp->vfdb->vfqs = kzalloc(qcount * sizeof(struct bnx2x_vf_queue),
GFP_KERNEL);
if (!bp->vfdb->vfqs) {
BNX2X_ERR("failed to allocate vf queue array\n");
err = -ENOMEM;
goto failed;
}
return 0;
failed:
DP(BNX2X_MSG_IOV, "Failed err=%d\n", err);
__bnx2x_iov_free_vfdb(bp);
return err;
}
void bnx2x_iov_remove_one(struct bnx2x *bp)
{
if (!IS_SRIOV(bp))
return;
DP(BNX2X_MSG_IOV, "about to call disable sriov\n");
pci_disable_sriov(bp->pdev);
DP(BNX2X_MSG_IOV, "sriov disabled\n");
__bnx2x_iov_free_vfdb(bp);
}
void bnx2x_iov_free_mem(struct bnx2x *bp)
{
int i;
if (!IS_SRIOV(bp))
return;
for (i = 0; i < BNX2X_VF_CIDS/ILT_PAGE_CIDS; i++) {
struct hw_dma *cxt = &bp->vfdb->context[i];
BNX2X_PCI_FREE(cxt->addr, cxt->mapping, cxt->size);
}
BNX2X_PCI_FREE(BP_VFDB(bp)->sp_dma.addr,
BP_VFDB(bp)->sp_dma.mapping,
BP_VFDB(bp)->sp_dma.size);
BNX2X_PCI_FREE(BP_VF_MBX_DMA(bp)->addr,
BP_VF_MBX_DMA(bp)->mapping,
BP_VF_MBX_DMA(bp)->size);
BNX2X_PCI_FREE(BP_VF_BULLETIN_DMA(bp)->addr,
BP_VF_BULLETIN_DMA(bp)->mapping,
BP_VF_BULLETIN_DMA(bp)->size);
}
int bnx2x_iov_alloc_mem(struct bnx2x *bp)
{
size_t tot_size;
int i, rc = 0;
if (!IS_SRIOV(bp))
return rc;
tot_size = (BP_VFDB(bp)->sriov.first_vf_in_pf + BNX2X_NR_VIRTFN(bp)) *
BNX2X_CIDS_PER_VF * sizeof(union cdu_context);
for (i = 0; i < BNX2X_VF_CIDS/ILT_PAGE_CIDS; i++) {
struct hw_dma *cxt = BP_VF_CXT_PAGE(bp, i);
cxt->size = min_t(size_t, tot_size, CDU_ILT_PAGE_SZ);
if (cxt->size) {
BNX2X_PCI_ALLOC(cxt->addr, &cxt->mapping, cxt->size);
} else {
cxt->addr = NULL;
cxt->mapping = 0;
}
tot_size -= cxt->size;
}
tot_size = BNX2X_NR_VIRTFN(bp) * sizeof(struct bnx2x_vf_sp);
BNX2X_PCI_ALLOC(BP_VFDB(bp)->sp_dma.addr, &BP_VFDB(bp)->sp_dma.mapping,
tot_size);
BP_VFDB(bp)->sp_dma.size = tot_size;
tot_size = BNX2X_NR_VIRTFN(bp) * MBX_MSG_ALIGNED_SIZE;
BNX2X_PCI_ALLOC(BP_VF_MBX_DMA(bp)->addr, &BP_VF_MBX_DMA(bp)->mapping,
tot_size);
BP_VF_MBX_DMA(bp)->size = tot_size;
tot_size = BNX2X_NR_VIRTFN(bp) * BULLETIN_CONTENT_SIZE;
BNX2X_PCI_ALLOC(BP_VF_BULLETIN_DMA(bp)->addr,
&BP_VF_BULLETIN_DMA(bp)->mapping, tot_size);
BP_VF_BULLETIN_DMA(bp)->size = tot_size;
return 0;
alloc_mem_err:
return -ENOMEM;
}
static void bnx2x_vfq_init(struct bnx2x *bp, struct bnx2x_virtf *vf,
struct bnx2x_vf_queue *q)
{
u8 cl_id = vfq_cl_id(vf, q);
u8 func_id = FW_VF_HANDLE(vf->abs_vfid);
unsigned long q_type = 0;
set_bit(BNX2X_Q_TYPE_HAS_TX, &q_type);
set_bit(BNX2X_Q_TYPE_HAS_RX, &q_type);
bnx2x_init_queue_obj(bp, &q->sp_obj,
cl_id, &q->cid, 1, func_id,
bnx2x_vf_sp(bp, vf, q_data),
bnx2x_vf_sp_map(bp, vf, q_data),
q_type);
DP(BNX2X_MSG_IOV,
"initialized vf %d's queue object. func id set to %d\n",
vf->abs_vfid, q->sp_obj.func_id);
if (vfq_is_leading(q)) {
bnx2x_init_mac_obj(bp, &q->mac_obj,
cl_id, q->cid, func_id,
bnx2x_vf_sp(bp, vf, mac_rdata),
bnx2x_vf_sp_map(bp, vf, mac_rdata),
BNX2X_FILTER_MAC_PENDING,
&vf->filter_state,
BNX2X_OBJ_TYPE_RX_TX,
&bp->macs_pool);
bnx2x_init_vlan_obj(bp, &q->vlan_obj,
cl_id, q->cid, func_id,
bnx2x_vf_sp(bp, vf, vlan_rdata),
bnx2x_vf_sp_map(bp, vf, vlan_rdata),
BNX2X_FILTER_VLAN_PENDING,
&vf->filter_state,
BNX2X_OBJ_TYPE_RX_TX,
&bp->vlans_pool);
bnx2x_init_mcast_obj(bp, &vf->mcast_obj, cl_id,
q->cid, func_id, func_id,
bnx2x_vf_sp(bp, vf, mcast_rdata),
bnx2x_vf_sp_map(bp, vf, mcast_rdata),
BNX2X_FILTER_MCAST_PENDING,
&vf->filter_state,
BNX2X_OBJ_TYPE_RX_TX);
vf->leading_rss = cl_id;
}
}
int bnx2x_iov_nic_init(struct bnx2x *bp)
{
int vfid, qcount, i;
if (!IS_SRIOV(bp)) {
DP(BNX2X_MSG_IOV, "vfdb was not allocated\n");
return 0;
}
DP(BNX2X_MSG_IOV, "num of vfs: %d\n", (bp)->vfdb->sriov.nr_virtfn);
msleep(100);
for_each_vf(bp, vfid) {
struct bnx2x_virtf *vf = BP_VF(bp, vfid);
int base_vf_cid = (BP_VFDB(bp)->sriov.first_vf_in_pf + vfid) *
BNX2X_CIDS_PER_VF;
union cdu_context *base_cxt = (union cdu_context *)
BP_VF_CXT_PAGE(bp, base_vf_cid/ILT_PAGE_CIDS)->addr +
(base_vf_cid & (ILT_PAGE_CIDS-1));
DP(BNX2X_MSG_IOV,
"VF[%d] Max IGU SBs: %d, base vf cid 0x%x, base cid 0x%x, base cxt %p\n",
vf->abs_vfid, vf_sb_count(vf), base_vf_cid,
BNX2X_FIRST_VF_CID + base_vf_cid, base_cxt);
bnx2x_iov_static_resc(bp, &vf->alloc_resc);
bp->vlans_pool.get(&bp->vlans_pool, vf_vlan_rules_cnt(vf));
vf->filter_state = 0;
vf->sp_cl_id = bnx2x_fp(bp, 0, cl_id);
bnx2x_init_mcast_obj(bp, &vf->mcast_obj, 0xFF,
0xFF, 0xFF, 0xFF,
bnx2x_vf_sp(bp, vf, mcast_rdata),
bnx2x_vf_sp_map(bp, vf, mcast_rdata),
BNX2X_FILTER_MCAST_PENDING,
&vf->filter_state,
BNX2X_OBJ_TYPE_RX_TX);
BP_VF_MBX(bp, vfid)->msg = (struct bnx2x_vf_mbx_msg *)
(((u8 *)BP_VF_MBX_DMA(bp)->addr) + vfid *
MBX_MSG_ALIGNED_SIZE);
BP_VF_MBX(bp, vfid)->msg_mapping = BP_VF_MBX_DMA(bp)->mapping +
vfid * MBX_MSG_ALIGNED_SIZE;
bnx2x_vf_enable_mbx(bp, vf->abs_vfid);
}
qcount = 0;
for_each_vf(bp, i) {
struct bnx2x_virtf *vf = BP_VF(bp, i);
vf->bus = bnx2x_vf_bus(bp, i);
vf->devfn = bnx2x_vf_devfn(bp, i);
bnx2x_vf_set_bars(bp, vf);
DP(BNX2X_MSG_IOV,
"VF info[%d]: bus 0x%x, devfn 0x%x, bar0 [0x%x, %d], bar1 [0x%x, %d], bar2 [0x%x, %d]\n",
vf->abs_vfid, vf->bus, vf->devfn,
(unsigned)vf->bars[0].bar, vf->bars[0].size,
(unsigned)vf->bars[1].bar, vf->bars[1].size,
(unsigned)vf->bars[2].bar, vf->bars[2].size);
vf->vfqs = &bp->vfdb->vfqs[qcount];
qcount += bnx2x_vf(bp, i, alloc_resc.num_sbs);
}
return 0;
}
int bnx2x_iov_chip_cleanup(struct bnx2x *bp)
{
int i;
if (!IS_SRIOV(bp))
return 0;
for_each_vf(bp, i)
bnx2x_vf_release(bp, BP_VF(bp, i), true);
return 0;
}
int bnx2x_iov_init_ilt(struct bnx2x *bp, u16 line)
{
int i;
struct bnx2x_ilt *ilt = BP_ILT(bp);
if (!IS_SRIOV(bp))
return line;
for (i = 0; i < BNX2X_VF_CIDS/ILT_PAGE_CIDS; i++) {
struct hw_dma *hw_cxt = BP_VF_CXT_PAGE(bp, i);
ilt->lines[line+i].page = hw_cxt->addr;
ilt->lines[line+i].page_mapping = hw_cxt->mapping;
ilt->lines[line+i].size = hw_cxt->size;
}
return line + i;
}
static u8 bnx2x_iov_is_vf_cid(struct bnx2x *bp, u16 cid)
{
return ((cid >= BNX2X_FIRST_VF_CID) &&
((cid - BNX2X_FIRST_VF_CID) < BNX2X_VF_CIDS));
}
static
void bnx2x_vf_handle_classification_eqe(struct bnx2x *bp,
struct bnx2x_vf_queue *vfq,
union event_ring_elem *elem)
{
unsigned long ramrod_flags = 0;
int rc = 0;
set_bit(RAMROD_CONT, &ramrod_flags);
switch (elem->message.data.eth_event.echo >> BNX2X_SWCID_SHIFT) {
case BNX2X_FILTER_MAC_PENDING:
rc = vfq->mac_obj.complete(bp, &vfq->mac_obj, elem,
&ramrod_flags);
break;
case BNX2X_FILTER_VLAN_PENDING:
rc = vfq->vlan_obj.complete(bp, &vfq->vlan_obj, elem,
&ramrod_flags);
break;
default:
BNX2X_ERR("Unsupported classification command: %d\n",
elem->message.data.eth_event.echo);
return;
}
if (rc < 0)
BNX2X_ERR("Failed to schedule new commands: %d\n", rc);
else if (rc > 0)
DP(BNX2X_MSG_IOV, "Scheduled next pending commands...\n");
}
static
void bnx2x_vf_handle_mcast_eqe(struct bnx2x *bp,
struct bnx2x_virtf *vf)
{
struct bnx2x_mcast_ramrod_params rparam = {NULL};
int rc;
rparam.mcast_obj = &vf->mcast_obj;
vf->mcast_obj.raw.clear_pending(&vf->mcast_obj.raw);
if (vf->mcast_obj.check_pending(&vf->mcast_obj)) {
rc = bnx2x_config_mcast(bp, &rparam, BNX2X_MCAST_CMD_CONT);
if (rc < 0)
BNX2X_ERR("Failed to send pending mcast commands: %d\n",
rc);
}
}
static
void bnx2x_vf_handle_filters_eqe(struct bnx2x *bp,
struct bnx2x_virtf *vf)
{
smp_mb__before_clear_bit();
clear_bit(BNX2X_FILTER_RX_MODE_PENDING, &vf->filter_state);
smp_mb__after_clear_bit();
}
int bnx2x_iov_eq_sp_event(struct bnx2x *bp, union event_ring_elem *elem)
{
struct bnx2x_virtf *vf;
int qidx = 0, abs_vfid;
u8 opcode;
u16 cid = 0xffff;
if (!IS_SRIOV(bp))
return 1;
opcode = elem->message.opcode;
switch (opcode) {
case EVENT_RING_OPCODE_CFC_DEL:
cid = SW_CID((__force __le32)
elem->message.data.cfc_del_event.cid);
DP(BNX2X_MSG_IOV, "checking cfc-del comp cid=%d\n", cid);
break;
case EVENT_RING_OPCODE_CLASSIFICATION_RULES:
case EVENT_RING_OPCODE_MULTICAST_RULES:
case EVENT_RING_OPCODE_FILTERS_RULES:
cid = (elem->message.data.eth_event.echo &
BNX2X_SWCID_MASK);
DP(BNX2X_MSG_IOV, "checking filtering comp cid=%d\n", cid);
break;
case EVENT_RING_OPCODE_VF_FLR:
abs_vfid = elem->message.data.vf_flr_event.vf_id;
DP(BNX2X_MSG_IOV, "Got VF FLR notification abs_vfid=%d\n",
abs_vfid);
goto get_vf;
case EVENT_RING_OPCODE_MALICIOUS_VF:
abs_vfid = elem->message.data.malicious_vf_event.vf_id;
DP(BNX2X_MSG_IOV, "Got VF MALICIOUS notification abs_vfid=%d err_id=0x%x\n",
abs_vfid, elem->message.data.malicious_vf_event.err_id);
goto get_vf;
default:
return 1;
}
if (!bnx2x_iov_is_vf_cid(bp, cid)) {
DP(BNX2X_MSG_IOV, "cid is outside vf range: %d\n", cid);
return 1;
}
qidx = cid & ((1 << BNX2X_VF_CID_WND)-1);
abs_vfid = (cid >> BNX2X_VF_CID_WND) & (BNX2X_MAX_NUM_OF_VFS-1);
get_vf:
vf = bnx2x_vf_by_abs_fid(bp, abs_vfid);
if (!vf) {
BNX2X_ERR("EQ completion for unknown VF, cid %d, abs_vfid %d\n",
cid, abs_vfid);
return 0;
}
switch (opcode) {
case EVENT_RING_OPCODE_CFC_DEL:
DP(BNX2X_MSG_IOV, "got VF [%d:%d] cfc delete ramrod\n",
vf->abs_vfid, qidx);
vfq_get(vf, qidx)->sp_obj.complete_cmd(bp,
&vfq_get(vf,
qidx)->sp_obj,
BNX2X_Q_CMD_CFC_DEL);
break;
case EVENT_RING_OPCODE_CLASSIFICATION_RULES:
DP(BNX2X_MSG_IOV, "got VF [%d:%d] set mac/vlan ramrod\n",
vf->abs_vfid, qidx);
bnx2x_vf_handle_classification_eqe(bp, vfq_get(vf, qidx), elem);
break;
case EVENT_RING_OPCODE_MULTICAST_RULES:
DP(BNX2X_MSG_IOV, "got VF [%d:%d] set mcast ramrod\n",
vf->abs_vfid, qidx);
bnx2x_vf_handle_mcast_eqe(bp, vf);
break;
case EVENT_RING_OPCODE_FILTERS_RULES:
DP(BNX2X_MSG_IOV, "got VF [%d:%d] set rx-mode ramrod\n",
vf->abs_vfid, qidx);
bnx2x_vf_handle_filters_eqe(bp, vf);
break;
case EVENT_RING_OPCODE_VF_FLR:
DP(BNX2X_MSG_IOV, "got VF [%d] FLR notification\n",
vf->abs_vfid);
break;
case EVENT_RING_OPCODE_MALICIOUS_VF:
DP(BNX2X_MSG_IOV, "Got VF MALICIOUS notification abs_vfid=%d error id %x\n",
abs_vfid, elem->message.data.malicious_vf_event.err_id);
break;
}
bnx2x_iov_sp_event(bp, cid, false);
return 0;
}
static struct bnx2x_virtf *bnx2x_vf_by_cid(struct bnx2x *bp, int vf_cid)
{
int abs_vfid = (vf_cid >> BNX2X_VF_CID_WND) & (BNX2X_MAX_NUM_OF_VFS-1);
return bnx2x_vf_by_abs_fid(bp, abs_vfid);
}
void bnx2x_iov_set_queue_sp_obj(struct bnx2x *bp, int vf_cid,
struct bnx2x_queue_sp_obj **q_obj)
{
struct bnx2x_virtf *vf;
if (!IS_SRIOV(bp))
return;
vf = bnx2x_vf_by_cid(bp, vf_cid);
if (vf) {
int q_index = vf_cid & ((1 << BNX2X_VF_CID_WND)-1);
*q_obj = &bnx2x_vfq(vf, q_index, sp_obj);
} else {
BNX2X_ERR("No vf matching cid %d\n", vf_cid);
}
}
void bnx2x_iov_sp_event(struct bnx2x *bp, int vf_cid, bool queue_work)
{
struct bnx2x_virtf *vf;
if (!IS_SRIOV(bp) || !bnx2x_iov_is_vf_cid(bp, vf_cid))
return;
vf = bnx2x_vf_by_cid(bp, vf_cid);
if (vf) {
atomic_set(&vf->op_in_progress, 1);
if (queue_work)
queue_delayed_work(bnx2x_wq, &bp->sp_task, 0);
}
}
void bnx2x_iov_adjust_stats_req(struct bnx2x *bp)
{
int i;
int first_queue_query_index, num_queues_req;
dma_addr_t cur_data_offset;
struct stats_query_entry *cur_query_entry;
u8 stats_count = 0;
bool is_fcoe = false;
if (!IS_SRIOV(bp))
return;
if (!NO_FCOE(bp))
is_fcoe = true;
num_queues_req = BNX2X_NUM_ETH_QUEUES(bp) + is_fcoe;
first_queue_query_index = BNX2X_FIRST_QUEUE_QUERY_IDX -
(is_fcoe ? 0 : 1);
DP(BNX2X_MSG_IOV,
"BNX2X_NUM_ETH_QUEUES %d, is_fcoe %d, first_queue_query_index %d => determined the last non virtual statistics query index is %d. Will add queries on top of that\n",
BNX2X_NUM_ETH_QUEUES(bp), is_fcoe, first_queue_query_index,
first_queue_query_index + num_queues_req);
cur_data_offset = bp->fw_stats_data_mapping +
offsetof(struct bnx2x_fw_stats_data, queue_stats) +
num_queues_req * sizeof(struct per_queue_stats);
cur_query_entry = &bp->fw_stats_req->
query[first_queue_query_index + num_queues_req];
for_each_vf(bp, i) {
int j;
struct bnx2x_virtf *vf = BP_VF(bp, i);
if (vf->state != VF_ENABLED) {
DP(BNX2X_MSG_IOV,
"vf %d not enabled so no stats for it\n",
vf->abs_vfid);
continue;
}
DP(BNX2X_MSG_IOV, "add addresses for vf %d\n", vf->abs_vfid);
for_each_vfq(vf, j) {
struct bnx2x_vf_queue *rxq = vfq_get(vf, j);
if (bnx2x_get_q_logical_state(bp, &rxq->sp_obj) ==
BNX2X_Q_LOGICAL_STATE_STOPPED)
continue;
cur_query_entry->kind = STATS_TYPE_QUEUE;
cur_query_entry->index = vfq_cl_id(vf, rxq);
cur_query_entry->funcID =
cpu_to_le16(FW_VF_HANDLE(vf->abs_vfid));
cur_query_entry->address.hi =
cpu_to_le32(U64_HI(vf->fw_stat_map));
cur_query_entry->address.lo =
cpu_to_le32(U64_LO(vf->fw_stat_map));
DP(BNX2X_MSG_IOV,
"added address %x %x for vf %d queue %d client %d\n",
cur_query_entry->address.hi,
cur_query_entry->address.lo, cur_query_entry->funcID,
j, cur_query_entry->index);
cur_query_entry++;
cur_data_offset += sizeof(struct per_queue_stats);
stats_count++;
}
}
bp->fw_stats_req->hdr.cmd_num = bp->fw_stats_num + stats_count;
}
void bnx2x_iov_sp_task(struct bnx2x *bp)
{
int i;
if (!IS_SRIOV(bp))
return;
DP(BNX2X_MSG_IOV, "searching for pending vf operations\n");
for_each_vf(bp, i) {
struct bnx2x_virtf *vf = BP_VF(bp, i);
if (!list_empty(&vf->op_list_head) &&
atomic_read(&vf->op_in_progress)) {
DP(BNX2X_MSG_IOV, "running pending op for vf %d\n", i);
bnx2x_vfop_cur(bp, vf)->transition(bp, vf);
}
}
}
static inline
struct bnx2x_virtf *__vf_from_stat_id(struct bnx2x *bp, u8 stat_id)
{
int i;
struct bnx2x_virtf *vf = NULL;
for_each_vf(bp, i) {
vf = BP_VF(bp, i);
if (stat_id >= vf->igu_base_id &&
stat_id < vf->igu_base_id + vf_sb_count(vf))
break;
}
return vf;
}
static void bnx2x_vf_qtbl_set_q(struct bnx2x *bp, u8 abs_vfid, u8 qid,
u8 enable)
{
u32 reg = PXP_REG_HST_ZONE_PERMISSION_TABLE + qid * 4;
u32 val = enable ? (abs_vfid | (1 << 6)) : 0;
REG_WR(bp, reg, val);
}
static void bnx2x_vf_clr_qtbl(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
int i;
for_each_vfq(vf, i)
bnx2x_vf_qtbl_set_q(bp, vf->abs_vfid,
vfq_qzone_id(vf, vfq_get(vf, i)), false);
}
static void bnx2x_vf_igu_disable(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
u32 val;
bnx2x_pretend_func(bp, HW_VF_HANDLE(bp, vf->abs_vfid));
val = REG_RD(bp, IGU_REG_VF_CONFIGURATION);
val &= ~(IGU_VF_CONF_MSI_MSIX_EN | IGU_VF_CONF_SINGLE_ISR_EN |
IGU_VF_CONF_FUNC_EN | IGU_VF_CONF_PARENT_MASK);
REG_WR(bp, IGU_REG_VF_CONFIGURATION, val);
bnx2x_pretend_func(bp, BP_ABS_FUNC(bp));
}
u8 bnx2x_vf_max_queue_cnt(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
return min_t(u8, min_t(u8, vf_sb_count(vf), BNX2X_CIDS_PER_VF),
BNX2X_VF_MAX_QUEUES);
}
static
int bnx2x_vf_chk_avail_resc(struct bnx2x *bp, struct bnx2x_virtf *vf,
struct vf_pf_resc_request *req_resc)
{
u8 rxq_cnt = vf_rxq_count(vf) ? : bnx2x_vf_max_queue_cnt(bp, vf);
u8 txq_cnt = vf_txq_count(vf) ? : bnx2x_vf_max_queue_cnt(bp, vf);
return ((req_resc->num_rxqs <= rxq_cnt) &&
(req_resc->num_txqs <= txq_cnt) &&
(req_resc->num_sbs <= vf_sb_count(vf)) &&
(req_resc->num_mac_filters <= vf_mac_rules_cnt(vf)) &&
(req_resc->num_vlan_filters <= vf_vlan_rules_cnt(vf)));
}
int bnx2x_vf_acquire(struct bnx2x *bp, struct bnx2x_virtf *vf,
struct vf_pf_resc_request *resc)
{
int base_vf_cid = (BP_VFDB(bp)->sriov.first_vf_in_pf + vf->index) *
BNX2X_CIDS_PER_VF;
union cdu_context *base_cxt = (union cdu_context *)
BP_VF_CXT_PAGE(bp, base_vf_cid/ILT_PAGE_CIDS)->addr +
(base_vf_cid & (ILT_PAGE_CIDS-1));
int i;
if (vf->state == VF_ACQUIRED) {
DP(BNX2X_MSG_IOV, "VF[%d] Trying to re-acquire resources (VF was not released or FLR'd)\n",
vf->abs_vfid);
if (!bnx2x_vf_chk_avail_resc(bp, vf, resc)) {
BNX2X_ERR("VF[%d] When re-acquiring resources, requested numbers must be <= then previously acquired numbers\n",
vf->abs_vfid);
return -EINVAL;
}
return 0;
}
if (vf->state != VF_FREE && vf->state != VF_RESET) {
BNX2X_ERR("VF[%d] Can not acquire a VF with state %d\n",
vf->abs_vfid, vf->state);
return -EINVAL;
}
if (!bnx2x_vf_chk_avail_resc(bp, vf, resc)) {
DP(BNX2X_MSG_IOV,
"cannot fulfill vf resource request. Placing maximal available values in response\n");
return -ENOMEM;
}
vf_sb_count(vf) = resc->num_sbs;
vf_rxq_count(vf) = resc->num_rxqs ? : bnx2x_vf_max_queue_cnt(bp, vf);
vf_txq_count(vf) = resc->num_txqs ? : bnx2x_vf_max_queue_cnt(bp, vf);
if (resc->num_mac_filters)
vf_mac_rules_cnt(vf) = resc->num_mac_filters;
if (resc->num_vlan_filters)
vf_vlan_rules_cnt(vf) = resc->num_vlan_filters;
DP(BNX2X_MSG_IOV,
"Fulfilling vf request: sb count %d, tx_count %d, rx_count %d, mac_rules_count %d, vlan_rules_count %d\n",
vf_sb_count(vf), vf_rxq_count(vf),
vf_txq_count(vf), vf_mac_rules_cnt(vf),
vf_vlan_rules_cnt(vf));
if (!vf->vfqs) {
DP(BNX2X_MSG_IOV, "vf->vfqs was not allocated\n");
return -EINVAL;
}
for_each_vfq(vf, i) {
struct bnx2x_vf_queue *q = vfq_get(vf, i);
if (!q) {
DP(BNX2X_MSG_IOV, "q number %d was not allocated\n", i);
return -EINVAL;
}
q->index = i;
q->cxt = &((base_cxt + i)->eth);
q->cid = BNX2X_FIRST_VF_CID + base_vf_cid + i;
DP(BNX2X_MSG_IOV, "VFQ[%d:%d]: index %d, cid 0x%x, cxt %p\n",
vf->abs_vfid, i, q->index, q->cid, q->cxt);
bnx2x_vfq_init(bp, vf, q);
}
vf->state = VF_ACQUIRED;
return 0;
}
int bnx2x_vf_init(struct bnx2x *bp, struct bnx2x_virtf *vf, dma_addr_t *sb_map)
{
struct bnx2x_func_init_params func_init = {0};
u16 flags = 0;
int i;
for_each_vf_sb(vf, i)
bnx2x_init_sb(bp, (dma_addr_t)sb_map[i], vf->abs_vfid, true,
vf_igu_sb(vf, i), vf_igu_sb(vf, i));
if (vf->state != VF_ACQUIRED) {
DP(BNX2X_MSG_IOV, "VF[%d] is not in VF_ACQUIRED, but %d\n",
vf->abs_vfid, vf->state);
return -EINVAL;
}
msleep(100);
if (bnx2x_vf_flr_clnup_epilog(bp, vf->abs_vfid))
return -EBUSY;
REG_WR(bp, IGU_REG_STATISTIC_NUM_MESSAGE_SENT + vf->abs_vfid * 4 , 0);
if (vf->cfg_flags & VF_CFG_STATS)
flags |= (FUNC_FLG_STATS | FUNC_FLG_SPQ);
if (vf->cfg_flags & VF_CFG_TPA)
flags |= FUNC_FLG_TPA;
if (is_vf_multi(vf))
flags |= FUNC_FLG_RSS;
func_init.func_flgs = flags;
func_init.pf_id = BP_FUNC(bp);
func_init.func_id = FW_VF_HANDLE(vf->abs_vfid);
func_init.fw_stat_map = vf->fw_stat_map;
func_init.spq_map = vf->spq_map;
func_init.spq_prod = 0;
bnx2x_func_init(bp, &func_init);
bnx2x_vf_enable_access(bp, vf->abs_vfid);
bnx2x_vf_enable_traffic(bp, vf);
for_each_vfq(vf, i)
bnx2x_vf_qtbl_set_q(bp, vf->abs_vfid,
vfq_qzone_id(vf, vfq_get(vf, i)), true);
vf->state = VF_ENABLED;
bnx2x_post_vf_bulletin(bp, vf->index);
return 0;
}
void bnx2x_set_vf_state(void *cookie)
{
struct set_vf_state_cookie *p = (struct set_vf_state_cookie *)cookie;
p->vf->state = p->state;
}
static void bnx2x_vfop_close(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_vfop_args_qx *qx = &vfop->args.qx;
enum bnx2x_vfop_close_state state = vfop->state;
struct bnx2x_vfop_cmd cmd = {
.done = bnx2x_vfop_close,
.block = false,
};
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "vf[%d] STATE: %d\n", vf->abs_vfid, state);
switch (state) {
case BNX2X_VFOP_CLOSE_QUEUES:
if (++(qx->qid) < vf_rxq_count(vf)) {
vfop->rc = bnx2x_vfop_qdown_cmd(bp, vf, &cmd, qx->qid);
if (vfop->rc)
goto op_err;
return;
}
vfop->state = BNX2X_VFOP_CLOSE_HW;
vfop->rc = bnx2x_vfop_mcast_cmd(bp, vf, &cmd, NULL, 0, false);
if (vfop->rc)
goto op_err;
return;
case BNX2X_VFOP_CLOSE_HW:
DP(BNX2X_MSG_IOV, "disabling igu\n");
bnx2x_vf_igu_disable(bp, vf);
DP(BNX2X_MSG_IOV, "clearing qtbl\n");
bnx2x_vf_clr_qtbl(bp, vf);
goto op_done;
default:
bnx2x_vfop_default(state);
}
op_err:
BNX2X_ERR("VF[%d] CLOSE error: rc %d\n", vf->abs_vfid, vfop->rc);
op_done:
{
struct set_vf_state_cookie cookie;
cookie.vf = vf;
cookie.state = VF_ACQUIRED;
bnx2x_stats_safe_exec(bp, bnx2x_set_vf_state, &cookie);
}
DP(BNX2X_MSG_IOV, "set state to acquired\n");
bnx2x_vfop_end(bp, vf, vfop);
}
int bnx2x_vfop_close_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
vfop->args.qx.qid = -1;
bnx2x_vfop_opset(BNX2X_VFOP_CLOSE_QUEUES,
bnx2x_vfop_close, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_close,
cmd->block);
}
return -ENOMEM;
}
static void bnx2x_vfop_release(struct bnx2x *bp, struct bnx2x_virtf *vf)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_cur(bp, vf);
struct bnx2x_vfop_cmd cmd = {
.done = bnx2x_vfop_release,
.block = false,
};
DP(BNX2X_MSG_IOV, "vfop->rc %d\n", vfop->rc);
if (vfop->rc < 0)
goto op_err;
DP(BNX2X_MSG_IOV, "VF[%d] STATE: %s\n", vf->abs_vfid,
vf->state == VF_FREE ? "Free" :
vf->state == VF_ACQUIRED ? "Acquired" :
vf->state == VF_ENABLED ? "Enabled" :
vf->state == VF_RESET ? "Reset" :
"Unknown");
switch (vf->state) {
case VF_ENABLED:
vfop->rc = bnx2x_vfop_close_cmd(bp, vf, &cmd);
if (vfop->rc)
goto op_err;
return;
case VF_ACQUIRED:
DP(BNX2X_MSG_IOV, "about to free resources\n");
bnx2x_vf_free_resc(bp, vf);
DP(BNX2X_MSG_IOV, "vfop->rc %d\n", vfop->rc);
goto op_done;
case VF_FREE:
case VF_RESET:
goto op_done;
default:
bnx2x_vfop_default(vf->state);
}
op_err:
BNX2X_ERR("VF[%d] RELEASE error: rc %d\n", vf->abs_vfid, vfop->rc);
op_done:
bnx2x_vfop_end(bp, vf, vfop);
}
int bnx2x_vfop_release_cmd(struct bnx2x *bp,
struct bnx2x_virtf *vf,
struct bnx2x_vfop_cmd *cmd)
{
struct bnx2x_vfop *vfop = bnx2x_vfop_add(bp, vf);
if (vfop) {
bnx2x_vfop_opset(-1,
bnx2x_vfop_release, cmd->done);
return bnx2x_vfop_transition(bp, vf, bnx2x_vfop_release,
cmd->block);
}
return -ENOMEM;
}
void bnx2x_vf_release(struct bnx2x *bp, struct bnx2x_virtf *vf, bool block)
{
struct bnx2x_vfop_cmd cmd = {
.done = NULL,
.block = block,
};
int rc;
bnx2x_lock_vf_pf_channel(bp, vf, CHANNEL_TLV_PF_RELEASE_VF);
rc = bnx2x_vfop_release_cmd(bp, vf, &cmd);
if (rc)
WARN(rc,
"VF[%d] Failed to allocate resources for release op- rc=%d\n",
vf->abs_vfid, rc);
}
static inline void bnx2x_vf_get_sbdf(struct bnx2x *bp,
struct bnx2x_virtf *vf, u32 *sbdf)
{
*sbdf = vf->devfn | (vf->bus << 8);
}
static inline void bnx2x_vf_get_bars(struct bnx2x *bp, struct bnx2x_virtf *vf,
struct bnx2x_vf_bar_info *bar_info)
{
int n;
bar_info->nr_bars = bp->vfdb->sriov.nres;
for (n = 0; n < bar_info->nr_bars; n++)
bar_info->bars[n] = vf->bars[n];
}
void bnx2x_lock_vf_pf_channel(struct bnx2x *bp, struct bnx2x_virtf *vf,
enum channel_tlvs tlv)
{
mutex_lock(&vf->op_mutex);
vf->op_current = tlv;
DP(BNX2X_MSG_IOV, "VF[%d]: vf pf channel locked by %d\n",
vf->abs_vfid, tlv);
}
void bnx2x_unlock_vf_pf_channel(struct bnx2x *bp, struct bnx2x_virtf *vf,
enum channel_tlvs expected_tlv)
{
WARN(expected_tlv != vf->op_current,
"lock mismatch: expected %d found %d", expected_tlv,
vf->op_current);
mutex_unlock(&vf->op_mutex);
DP(BNX2X_MSG_IOV, "VF[%d]: vf pf channel unlocked by %d\n",
vf->abs_vfid, vf->op_current);
vf->op_current = CHANNEL_TLV_NONE;
}
int bnx2x_sriov_configure(struct pci_dev *dev, int num_vfs_param)
{
struct bnx2x *bp = netdev_priv(pci_get_drvdata(dev));
DP(BNX2X_MSG_IOV, "bnx2x_sriov_configure called with %d, BNX2X_NR_VIRTFN(bp) was %d\n",
num_vfs_param, BNX2X_NR_VIRTFN(bp));
if (bp->state != BNX2X_STATE_OPEN) {
BNX2X_ERR("VF num configuration via sysfs not supported while PF is down\n");
return -EINVAL;
}
if (num_vfs_param > BNX2X_NR_VIRTFN(bp)) {
BNX2X_ERR("truncating requested number of VFs (%d) down to maximum allowed (%d)\n",
num_vfs_param, BNX2X_NR_VIRTFN(bp));
num_vfs_param = BNX2X_NR_VIRTFN(bp);
}
bp->requested_nr_virtfn = num_vfs_param;
if (num_vfs_param == 0) {
pci_disable_sriov(dev);
return 0;
} else {
return bnx2x_enable_sriov(bp);
}
}
int bnx2x_enable_sriov(struct bnx2x *bp)
{
int rc = 0, req_vfs = bp->requested_nr_virtfn;
rc = pci_enable_sriov(bp->pdev, req_vfs);
if (rc) {
BNX2X_ERR("pci_enable_sriov failed with %d\n", rc);
return rc;
}
DP(BNX2X_MSG_IOV, "sriov enabled (%d vfs)\n", req_vfs);
return req_vfs;
}
void bnx2x_pf_set_vfs_vlan(struct bnx2x *bp)
{
int vfidx;
struct pf_vf_bulletin_content *bulletin;
DP(BNX2X_MSG_IOV, "configuring vlan for VFs from sp-task\n");
for_each_vf(bp, vfidx) {
bulletin = BP_VF_BULLETIN(bp, vfidx);
if (BP_VF(bp, vfidx)->cfg_flags & VF_CFG_VLAN)
bnx2x_set_vf_vlan(bp->dev, vfidx, bulletin->vlan, 0);
}
}
void bnx2x_disable_sriov(struct bnx2x *bp)
{
pci_disable_sriov(bp->pdev);
}
static int bnx2x_vf_ndo_prep(struct bnx2x *bp, int vfidx,
struct bnx2x_virtf **vf,
struct pf_vf_bulletin_content **bulletin)
{
if (bp->state != BNX2X_STATE_OPEN) {
BNX2X_ERR("vf ndo called though PF is down\n");
return -EINVAL;
}
if (!IS_SRIOV(bp)) {
BNX2X_ERR("vf ndo called though sriov is disabled\n");
return -EINVAL;
}
if (vfidx >= BNX2X_NR_VIRTFN(bp)) {
BNX2X_ERR("vf ndo called for uninitialized VF. vfidx was %d BNX2X_NR_VIRTFN was %d\n",
vfidx, BNX2X_NR_VIRTFN(bp));
return -EINVAL;
}
*vf = BP_VF(bp, vfidx);
*bulletin = BP_VF_BULLETIN(bp, vfidx);
if (!*vf) {
BNX2X_ERR("vf ndo called but vf was null. vfidx was %d\n",
vfidx);
return -EINVAL;
}
if (!*bulletin) {
BNX2X_ERR("vf ndo called but Bulletin Board struct is null. vfidx was %d\n",
vfidx);
return -EINVAL;
}
return 0;
}
int bnx2x_get_vf_config(struct net_device *dev, int vfidx,
struct ifla_vf_info *ivi)
{
struct bnx2x *bp = netdev_priv(dev);
struct bnx2x_virtf *vf = NULL;
struct pf_vf_bulletin_content *bulletin = NULL;
struct bnx2x_vlan_mac_obj *mac_obj;
struct bnx2x_vlan_mac_obj *vlan_obj;
int rc;
rc = bnx2x_vf_ndo_prep(bp, vfidx, &vf, &bulletin);
if (rc)
return rc;
mac_obj = &bnx2x_vfq(vf, 0, mac_obj);
vlan_obj = &bnx2x_vfq(vf, 0, vlan_obj);
if (!mac_obj || !vlan_obj) {
BNX2X_ERR("VF partially initialized\n");
return -EINVAL;
}
ivi->vf = vfidx;
ivi->qos = 0;
ivi->tx_rate = 10000;
ivi->spoofchk = 1;
if (vf->state == VF_ENABLED) {
mac_obj->get_n_elements(bp, mac_obj, 1, (u8 *)&ivi->mac,
0, ETH_ALEN);
vlan_obj->get_n_elements(bp, vlan_obj, 1, (u8 *)&ivi->vlan,
0, VLAN_HLEN);
} else {
if (bulletin->valid_bitmap & (1 << MAC_ADDR_VALID))
memcpy(&ivi->mac, bulletin->mac, ETH_ALEN);
else
memset(&ivi->mac, 0, ETH_ALEN);
if (bulletin->valid_bitmap & (1 << VLAN_VALID))
memcpy(&ivi->vlan, &bulletin->vlan, VLAN_HLEN);
else
memset(&ivi->vlan, 0, VLAN_HLEN);
}
return 0;
}
int bnx2x_set_vf_mac(struct net_device *dev, int vfidx, u8 *mac)
{
struct bnx2x *bp = netdev_priv(dev);
int rc, q_logical_state;
struct bnx2x_virtf *vf = NULL;
struct pf_vf_bulletin_content *bulletin = NULL;
rc = bnx2x_vf_ndo_prep(bp, vfidx, &vf, &bulletin);
if (rc)
return rc;
if (!is_valid_ether_addr(mac)) {
BNX2X_ERR("mac address invalid\n");
return -EINVAL;
}
bulletin->valid_bitmap |= 1 << MAC_ADDR_VALID;
memcpy(bulletin->mac, mac, ETH_ALEN);
rc = bnx2x_post_vf_bulletin(bp, vfidx);
if (rc) {
BNX2X_ERR("failed to update VF[%d] bulletin\n", vfidx);
return rc;
}
q_logical_state =
bnx2x_get_q_logical_state(bp, &bnx2x_vfq(vf, 0, sp_obj));
if (vf->state == VF_ENABLED &&
q_logical_state == BNX2X_Q_LOGICAL_STATE_ACTIVE) {
unsigned long ramrod_flags = 0;
struct bnx2x_vlan_mac_obj *mac_obj = &bnx2x_vfq(vf, 0, mac_obj);
bnx2x_lock_vf_pf_channel(bp, vf, CHANNEL_TLV_PF_SET_MAC);
rc = bnx2x_del_all_macs(bp, mac_obj, BNX2X_ETH_MAC, true);
if (rc) {
BNX2X_ERR("failed to delete eth macs\n");
return -EINVAL;
}
rc = bnx2x_del_all_macs(bp, mac_obj, BNX2X_UC_LIST_MAC, true);
if (rc) {
BNX2X_ERR("failed to delete uc_list macs\n");
return -EINVAL;
}
__set_bit(RAMROD_COMP_WAIT, &ramrod_flags);
bnx2x_set_mac_one(bp, (u8 *)&bulletin->mac, mac_obj, true,
BNX2X_ETH_MAC, &ramrod_flags);
bnx2x_unlock_vf_pf_channel(bp, vf, CHANNEL_TLV_PF_SET_MAC);
}
return 0;
}
int bnx2x_set_vf_vlan(struct net_device *dev, int vfidx, u16 vlan, u8 qos)
{
struct bnx2x *bp = netdev_priv(dev);
int rc, q_logical_state;
struct bnx2x_virtf *vf = NULL;
struct pf_vf_bulletin_content *bulletin = NULL;
rc = bnx2x_vf_ndo_prep(bp, vfidx, &vf, &bulletin);
if (rc)
return rc;
if (vlan > 4095) {
BNX2X_ERR("illegal vlan value %d\n", vlan);
return -EINVAL;
}
DP(BNX2X_MSG_IOV, "configuring VF %d with VLAN %d qos %d\n",
vfidx, vlan, 0);
bulletin->valid_bitmap |= 1 << VLAN_VALID;
bulletin->vlan = vlan;
q_logical_state =
bnx2x_get_q_logical_state(bp, &bnx2x_vfq(vf, 0, sp_obj));
if (vf->state == VF_ENABLED &&
q_logical_state == BNX2X_Q_LOGICAL_STATE_ACTIVE) {
unsigned long ramrod_flags = 0;
unsigned long vlan_mac_flags = 0;
struct bnx2x_vlan_mac_obj *vlan_obj =
&bnx2x_vfq(vf, 0, vlan_obj);
struct bnx2x_vlan_mac_ramrod_params ramrod_param;
struct bnx2x_queue_state_params q_params = {NULL};
struct bnx2x_queue_update_params *update_params;
memset(&ramrod_param, 0, sizeof(ramrod_param));
bnx2x_lock_vf_pf_channel(bp, vf, CHANNEL_TLV_PF_SET_VLAN);
__set_bit(RAMROD_COMP_WAIT, &ramrod_flags);
rc = vlan_obj->delete_all(bp, vlan_obj, &vlan_mac_flags,
&ramrod_flags);
if (rc) {
BNX2X_ERR("failed to delete vlans\n");
return -EINVAL;
}
__set_bit(RAMROD_COMP_WAIT, &q_params.ramrod_flags);
q_params.cmd = BNX2X_Q_CMD_UPDATE;
q_params.q_obj = &bnx2x_vfq(vf, 0, sp_obj);
update_params = &q_params.params.update;
__set_bit(BNX2X_Q_UPDATE_DEF_VLAN_EN_CHNG,
&update_params->update_flags);
__set_bit(BNX2X_Q_UPDATE_SILENT_VLAN_REM_CHNG,
&update_params->update_flags);
if (vlan == 0) {
__clear_bit(BNX2X_Q_UPDATE_DEF_VLAN_EN,
&update_params->update_flags);
__clear_bit(BNX2X_Q_UPDATE_SILENT_VLAN_REM,
&update_params->update_flags);
} else {
__set_bit(RAMROD_COMP_WAIT, &ramrod_flags);
ramrod_param.vlan_mac_obj = vlan_obj;
ramrod_param.ramrod_flags = ramrod_flags;
ramrod_param.user_req.u.vlan.vlan = vlan;
ramrod_param.user_req.cmd = BNX2X_VLAN_MAC_ADD;
rc = bnx2x_config_vlan_mac(bp, &ramrod_param);
if (rc) {
BNX2X_ERR("failed to configure vlan\n");
return -EINVAL;
}
update_params = &q_params.params.update;
__set_bit(BNX2X_Q_UPDATE_DEF_VLAN_EN,
&update_params->update_flags);
__set_bit(BNX2X_Q_UPDATE_SILENT_VLAN_REM,
&update_params->update_flags);
update_params->def_vlan = vlan;
}
rc = bnx2x_queue_state_change(bp, &q_params);
if (rc) {
BNX2X_ERR("Failed to configure default VLAN\n");
return rc;
}
vf->cfg_flags &= ~VF_CFG_VLAN;
bnx2x_unlock_vf_pf_channel(bp, vf, CHANNEL_TLV_PF_SET_VLAN);
}
return 0;
}
u32 bnx2x_crc_vf_bulletin(struct bnx2x *bp,
struct pf_vf_bulletin_content *bulletin)
{
return crc32(BULLETIN_CRC_SEED,
((u8 *)bulletin) + sizeof(bulletin->crc),
bulletin->length - sizeof(bulletin->crc));
}
enum sample_bulletin_result bnx2x_sample_bulletin(struct bnx2x *bp)
{
struct pf_vf_bulletin_content bulletin = bp->pf2vf_bulletin->content;
int attempts;
if (bp->old_bulletin.version == bulletin.version)
return PFVF_BULLETIN_UNCHANGED;
if (bp->old_bulletin.version != bp->pf2vf_bulletin->content.version) {
for (attempts = 0; attempts < BULLETIN_ATTEMPTS; attempts++) {
bulletin = bp->pf2vf_bulletin->content;
if (bulletin.crc == bnx2x_crc_vf_bulletin(bp,
&bulletin))
break;
BNX2X_ERR("bad crc on bulletin board. Contained %x computed %x\n",
bulletin.crc,
bnx2x_crc_vf_bulletin(bp, &bulletin));
}
if (attempts >= BULLETIN_ATTEMPTS) {
BNX2X_ERR("pf to vf bulletin board crc was wrong %d consecutive times. Aborting\n",
attempts);
return PFVF_BULLETIN_CRC_ERR;
}
}
if (bulletin.valid_bitmap & 1 << MAC_ADDR_VALID &&
memcmp(bulletin.mac, bp->old_bulletin.mac, ETH_ALEN)) {
memcpy(bp->dev->dev_addr, bulletin.mac, ETH_ALEN);
}
if (bulletin.valid_bitmap & 1 << VLAN_VALID)
memcpy(&bulletin.vlan, &bp->old_bulletin.vlan, VLAN_HLEN);
bp->old_bulletin = bulletin;
return PFVF_BULLETIN_UPDATED;
}
void bnx2x_timer_sriov(struct bnx2x *bp)
{
bnx2x_sample_bulletin(bp);
if (bp->old_bulletin.valid_bitmap & 1 << CHANNEL_DOWN) {
smp_mb__before_clear_bit();
set_bit(BNX2X_SP_RTNL_VFPF_CHANNEL_DOWN,
&bp->sp_rtnl_state);
smp_mb__after_clear_bit();
schedule_delayed_work(&bp->sp_rtnl_task, 0);
}
}
void __iomem *bnx2x_vf_doorbells(struct bnx2x *bp)
{
return bp->regview + PXP_VF_ADDR_DB_START;
}
int bnx2x_vf_pci_alloc(struct bnx2x *bp)
{
mutex_init(&bp->vf2pf_mutex);
BNX2X_PCI_ALLOC(bp->vf2pf_mbox, &bp->vf2pf_mbox_mapping,
sizeof(struct bnx2x_vf_mbx_msg));
BNX2X_PCI_ALLOC(bp->pf2vf_bulletin, &bp->pf2vf_bulletin_mapping,
sizeof(union pf_vf_bulletin));
return 0;
alloc_mem_err:
BNX2X_PCI_FREE(bp->vf2pf_mbox, bp->vf2pf_mbox_mapping,
sizeof(struct bnx2x_vf_mbx_msg));
BNX2X_PCI_FREE(bp->vf2pf_mbox, bp->pf2vf_bulletin_mapping,
sizeof(union pf_vf_bulletin));
return -ENOMEM;
}
int bnx2x_open_epilog(struct bnx2x *bp)
{
if (IS_SRIOV(bp) && BNX2X_NR_VIRTFN(bp)) {
smp_mb__before_clear_bit();
set_bit(BNX2X_SP_RTNL_ENABLE_SRIOV, &bp->sp_rtnl_state);
smp_mb__after_clear_bit();
schedule_delayed_work(&bp->sp_rtnl_task, 0);
}
return 0;
}
void bnx2x_iov_channel_down(struct bnx2x *bp)
{
int vf_idx;
struct pf_vf_bulletin_content *bulletin;
if (!IS_SRIOV(bp))
return;
for_each_vf(bp, vf_idx) {
bulletin = BP_VF_BULLETIN(bp, vf_idx);
bulletin->valid_bitmap |= 1 << CHANNEL_DOWN;
bnx2x_post_vf_bulletin(bp, vf_idx);
}
}
