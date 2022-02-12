static ssize_t tcm_qla2xxx_parse_wwn(const char *name, u64 *wwn, int strict)
{
const char *cp;
char c;
u32 nibble;
u32 byte = 0;
u32 pos = 0;
u32 err;
*wwn = 0;
for (cp = name; cp < &name[TCM_QLA2XXX_NAMELEN - 1]; cp++) {
c = *cp;
if (c == '\n' && cp[1] == '\0')
continue;
if (strict && pos++ == 2 && byte++ < 7) {
pos = 0;
if (c == ':')
continue;
err = 1;
goto fail;
}
if (c == '\0') {
err = 2;
if (strict && byte != 8)
goto fail;
return cp - name;
}
err = 3;
if (isdigit(c))
nibble = c - '0';
else if (isxdigit(c) && (islower(c) || !strict))
nibble = tolower(c) - 'a' + 10;
else
goto fail;
*wwn = (*wwn << 4) | nibble;
}
err = 4;
fail:
pr_debug("err %u len %zu pos %u byte %u\n",
err, cp - name, pos, byte);
return -1;
}
static ssize_t tcm_qla2xxx_format_wwn(char *buf, size_t len, u64 wwn)
{
u8 b[8];
put_unaligned_be64(wwn, b);
return snprintf(buf, len,
"%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x",
b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]);
}
static char *tcm_qla2xxx_get_fabric_name(void)
{
return "qla2xxx";
}
static int tcm_qla2xxx_npiv_extract_wwn(const char *ns, u64 *nm)
{
unsigned int i, j;
u8 wwn[8];
memset(wwn, 0, sizeof(wwn));
for (i = 0, j = 0; i < 16; i++) {
int value;
value = hex_to_bin(*ns++);
if (value >= 0)
j = (j << 4) | value;
else
return -EINVAL;
if (i % 2) {
wwn[i/2] = j & 0xff;
j = 0;
}
}
*nm = wwn_to_u64(wwn);
return 0;
}
static int tcm_qla2xxx_npiv_parse_wwn(
const char *name,
size_t count,
u64 *wwpn,
u64 *wwnn)
{
unsigned int cnt = count;
int rc;
*wwpn = 0;
*wwnn = 0;
if (name[cnt-1] == '\n' || name[cnt-1] == 0)
cnt--;
if ((cnt != (16+1+16)) || (name[16] != ':'))
return -EINVAL;
rc = tcm_qla2xxx_npiv_extract_wwn(&name[0], wwpn);
if (rc != 0)
return rc;
rc = tcm_qla2xxx_npiv_extract_wwn(&name[17], wwnn);
if (rc != 0)
return rc;
return 0;
}
static char *tcm_qla2xxx_npiv_get_fabric_name(void)
{
return "qla2xxx_npiv";
}
static char *tcm_qla2xxx_get_fabric_wwn(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
struct tcm_qla2xxx_lport *lport = tpg->lport;
return lport->lport_naa_name;
}
static u16 tcm_qla2xxx_get_tag(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->lport_tpgt;
}
static int tcm_qla2xxx_check_demo_mode(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->tpg_attrib.generate_node_acls;
}
static int tcm_qla2xxx_check_demo_mode_cache(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->tpg_attrib.cache_dynamic_acls;
}
static int tcm_qla2xxx_check_demo_write_protect(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->tpg_attrib.demo_mode_write_protect;
}
static int tcm_qla2xxx_check_prod_write_protect(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->tpg_attrib.prod_mode_write_protect;
}
static int tcm_qla2xxx_check_demo_mode_login_only(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->tpg_attrib.demo_mode_login_only;
}
static int tcm_qla2xxx_check_prot_fabric_only(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->tpg_attrib.fabric_prot_type;
}
static u32 tcm_qla2xxx_tpg_get_inst_index(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return tpg->lport_tpgt;
}
static void tcm_qla2xxx_complete_mcmd(struct work_struct *work)
{
struct qla_tgt_mgmt_cmd *mcmd = container_of(work,
struct qla_tgt_mgmt_cmd, free_work);
transport_generic_free_cmd(&mcmd->se_cmd, 0);
}
static void tcm_qla2xxx_free_mcmd(struct qla_tgt_mgmt_cmd *mcmd)
{
INIT_WORK(&mcmd->free_work, tcm_qla2xxx_complete_mcmd);
queue_work(tcm_qla2xxx_free_wq, &mcmd->free_work);
}
static void tcm_qla2xxx_complete_free(struct work_struct *work)
{
struct qla_tgt_cmd *cmd = container_of(work, struct qla_tgt_cmd, work);
cmd->cmd_in_wq = 0;
WARN_ON(cmd->trc_flags & TRC_CMD_FREE);
cmd->qpair->tgt_counters.qla_core_ret_sta_ctio++;
cmd->trc_flags |= TRC_CMD_FREE;
transport_generic_free_cmd(&cmd->se_cmd, 0);
}
static void tcm_qla2xxx_free_cmd(struct qla_tgt_cmd *cmd)
{
cmd->qpair->tgt_counters.core_qla_free_cmd++;
cmd->cmd_in_wq = 1;
WARN_ON(cmd->trc_flags & TRC_CMD_DONE);
cmd->trc_flags |= TRC_CMD_DONE;
INIT_WORK(&cmd->work, tcm_qla2xxx_complete_free);
queue_work_on(smp_processor_id(), tcm_qla2xxx_free_wq, &cmd->work);
}
static int tcm_qla2xxx_check_stop_free(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd;
if ((se_cmd->se_cmd_flags & SCF_SCSI_TMR_CDB) == 0) {
cmd = container_of(se_cmd, struct qla_tgt_cmd, se_cmd);
cmd->trc_flags |= TRC_CMD_CHK_STOP;
}
return target_put_sess_cmd(se_cmd);
}
static void tcm_qla2xxx_release_cmd(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd;
if (se_cmd->se_cmd_flags & SCF_SCSI_TMR_CDB) {
struct qla_tgt_mgmt_cmd *mcmd = container_of(se_cmd,
struct qla_tgt_mgmt_cmd, se_cmd);
qlt_free_mcmd(mcmd);
return;
}
cmd = container_of(se_cmd, struct qla_tgt_cmd, se_cmd);
qlt_free_cmd(cmd);
}
static void tcm_qla2xxx_release_session(struct kref *kref)
{
struct fc_port *sess = container_of(kref,
struct fc_port, sess_kref);
qlt_unreg_sess(sess);
}
static void tcm_qla2xxx_put_sess(struct fc_port *sess)
{
if (!sess)
return;
assert_spin_locked(&sess->vha->hw->tgt.sess_lock);
kref_put(&sess->sess_kref, tcm_qla2xxx_release_session);
}
static void tcm_qla2xxx_close_session(struct se_session *se_sess)
{
struct fc_port *sess = se_sess->fabric_sess_ptr;
struct scsi_qla_host *vha;
unsigned long flags;
BUG_ON(!sess);
vha = sess->vha;
spin_lock_irqsave(&vha->hw->tgt.sess_lock, flags);
target_sess_cmd_list_set_waiting(se_sess);
tcm_qla2xxx_put_sess(sess);
spin_unlock_irqrestore(&vha->hw->tgt.sess_lock, flags);
}
static u32 tcm_qla2xxx_sess_get_index(struct se_session *se_sess)
{
return 0;
}
static int tcm_qla2xxx_write_pending(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
if (cmd->aborted) {
pr_debug("write_pending aborted cmd[%p] refcount %d "
"transport_state %x, t_state %x, se_cmd_flags %x\n",
cmd, kref_read(&cmd->se_cmd.cmd_kref),
cmd->se_cmd.transport_state,
cmd->se_cmd.t_state,
cmd->se_cmd.se_cmd_flags);
return 0;
}
cmd->trc_flags |= TRC_XFR_RDY;
cmd->bufflen = se_cmd->data_length;
cmd->dma_data_direction = target_reverse_dma_direction(se_cmd);
cmd->sg_cnt = se_cmd->t_data_nents;
cmd->sg = se_cmd->t_data_sg;
cmd->prot_sg_cnt = se_cmd->t_prot_nents;
cmd->prot_sg = se_cmd->t_prot_sg;
cmd->blk_sz = se_cmd->se_dev->dev_attrib.block_size;
se_cmd->pi_err = 0;
return qlt_rdy_to_xfer(cmd);
}
static int tcm_qla2xxx_write_pending_status(struct se_cmd *se_cmd)
{
unsigned long flags;
spin_lock_irqsave(&se_cmd->t_state_lock, flags);
if (se_cmd->t_state == TRANSPORT_WRITE_PENDING ||
se_cmd->t_state == TRANSPORT_COMPLETE_QF_WP) {
spin_unlock_irqrestore(&se_cmd->t_state_lock, flags);
wait_for_completion_timeout(&se_cmd->t_transport_stop_comp,
50);
return 0;
}
spin_unlock_irqrestore(&se_cmd->t_state_lock, flags);
return 0;
}
static void tcm_qla2xxx_set_default_node_attrs(struct se_node_acl *nacl)
{
return;
}
static int tcm_qla2xxx_get_cmd_state(struct se_cmd *se_cmd)
{
if (!(se_cmd->se_cmd_flags & SCF_SCSI_TMR_CDB)) {
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
return cmd->state;
}
return 0;
}
static int tcm_qla2xxx_handle_cmd(scsi_qla_host_t *vha, struct qla_tgt_cmd *cmd,
unsigned char *cdb, uint32_t data_length, int fcp_task_attr,
int data_dir, int bidi)
{
struct se_cmd *se_cmd = &cmd->se_cmd;
struct se_session *se_sess;
struct fc_port *sess;
#ifdef CONFIG_TCM_QLA2XXX_DEBUG
struct se_portal_group *se_tpg;
struct tcm_qla2xxx_tpg *tpg;
#endif
int flags = TARGET_SCF_ACK_KREF;
if (bidi)
flags |= TARGET_SCF_BIDI_OP;
if (se_cmd->cpuid != WORK_CPU_UNBOUND)
flags |= TARGET_SCF_USE_CPUID;
sess = cmd->sess;
if (!sess) {
pr_err("Unable to locate struct fc_port from qla_tgt_cmd\n");
return -EINVAL;
}
se_sess = sess->se_sess;
if (!se_sess) {
pr_err("Unable to locate active struct se_session\n");
return -EINVAL;
}
#ifdef CONFIG_TCM_QLA2XXX_DEBUG
se_tpg = se_sess->se_tpg;
tpg = container_of(se_tpg, struct tcm_qla2xxx_tpg, se_tpg);
if (unlikely(tpg->tpg_attrib.jam_host)) {
return 0;
}
#endif
cmd->qpair->tgt_counters.qla_core_sbt_cmd++;
return target_submit_cmd(se_cmd, se_sess, cdb, &cmd->sense_buffer[0],
cmd->unpacked_lun, data_length, fcp_task_attr,
data_dir, flags);
}
static void tcm_qla2xxx_handle_data_work(struct work_struct *work)
{
struct qla_tgt_cmd *cmd = container_of(work, struct qla_tgt_cmd, work);
cmd->cmd_in_wq = 0;
cmd->qpair->tgt_counters.qla_core_ret_ctio++;
if (!cmd->write_data_transferred) {
if (cmd->se_cmd.transport_state & CMD_T_ABORTED) {
complete(&cmd->se_cmd.t_transport_stop_comp);
return;
}
switch (cmd->dif_err_code) {
case DIF_ERR_GRD:
cmd->se_cmd.pi_err =
TCM_LOGICAL_BLOCK_GUARD_CHECK_FAILED;
break;
case DIF_ERR_REF:
cmd->se_cmd.pi_err =
TCM_LOGICAL_BLOCK_REF_TAG_CHECK_FAILED;
break;
case DIF_ERR_APP:
cmd->se_cmd.pi_err =
TCM_LOGICAL_BLOCK_APP_TAG_CHECK_FAILED;
break;
case DIF_ERR_NONE:
default:
break;
}
if (cmd->se_cmd.pi_err)
transport_generic_request_failure(&cmd->se_cmd,
cmd->se_cmd.pi_err);
else
transport_generic_request_failure(&cmd->se_cmd,
TCM_CHECK_CONDITION_ABORT_CMD);
return;
}
return target_execute_cmd(&cmd->se_cmd);
}
static void tcm_qla2xxx_handle_data(struct qla_tgt_cmd *cmd)
{
cmd->trc_flags |= TRC_DATA_IN;
cmd->cmd_in_wq = 1;
INIT_WORK(&cmd->work, tcm_qla2xxx_handle_data_work);
queue_work_on(smp_processor_id(), tcm_qla2xxx_free_wq, &cmd->work);
}
static int tcm_qla2xxx_chk_dif_tags(uint32_t tag)
{
return 0;
}
static int tcm_qla2xxx_dif_tags(struct qla_tgt_cmd *cmd,
uint16_t *pfw_prot_opts)
{
struct se_cmd *se_cmd = &cmd->se_cmd;
if (!(se_cmd->prot_checks & TARGET_DIF_CHECK_GUARD))
*pfw_prot_opts |= PO_DISABLE_GUARD_CHECK;
if (!(se_cmd->prot_checks & TARGET_DIF_CHECK_APPTAG))
*pfw_prot_opts |= PO_DIS_APP_TAG_VALD;
return 0;
}
static int tcm_qla2xxx_handle_tmr(struct qla_tgt_mgmt_cmd *mcmd, u64 lun,
uint16_t tmr_func, uint32_t tag)
{
struct fc_port *sess = mcmd->sess;
struct se_cmd *se_cmd = &mcmd->se_cmd;
int transl_tmr_func = 0;
int flags = TARGET_SCF_ACK_KREF;
switch (tmr_func) {
case QLA_TGT_ABTS:
pr_debug("%ld: ABTS received\n", sess->vha->host_no);
transl_tmr_func = TMR_ABORT_TASK;
flags |= TARGET_SCF_LOOKUP_LUN_FROM_TAG;
break;
case QLA_TGT_2G_ABORT_TASK:
pr_debug("%ld: 2G Abort Task received\n", sess->vha->host_no);
transl_tmr_func = TMR_ABORT_TASK;
break;
case QLA_TGT_CLEAR_ACA:
pr_debug("%ld: CLEAR_ACA received\n", sess->vha->host_no);
transl_tmr_func = TMR_CLEAR_ACA;
break;
case QLA_TGT_TARGET_RESET:
pr_debug("%ld: TARGET_RESET received\n", sess->vha->host_no);
transl_tmr_func = TMR_TARGET_WARM_RESET;
break;
case QLA_TGT_LUN_RESET:
pr_debug("%ld: LUN_RESET received\n", sess->vha->host_no);
transl_tmr_func = TMR_LUN_RESET;
break;
case QLA_TGT_CLEAR_TS:
pr_debug("%ld: CLEAR_TS received\n", sess->vha->host_no);
transl_tmr_func = TMR_CLEAR_TASK_SET;
break;
case QLA_TGT_ABORT_TS:
pr_debug("%ld: ABORT_TS received\n", sess->vha->host_no);
transl_tmr_func = TMR_ABORT_TASK_SET;
break;
default:
pr_debug("%ld: Unknown task mgmt fn 0x%x\n",
sess->vha->host_no, tmr_func);
return -ENOSYS;
}
return target_submit_tmr(se_cmd, sess->se_sess, NULL, lun, mcmd,
transl_tmr_func, GFP_ATOMIC, tag, flags);
}
static int tcm_qla2xxx_queue_data_in(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
if (cmd->aborted) {
pr_debug("queue_data_in aborted cmd[%p] refcount %d "
"transport_state %x, t_state %x, se_cmd_flags %x\n",
cmd, kref_read(&cmd->se_cmd.cmd_kref),
cmd->se_cmd.transport_state,
cmd->se_cmd.t_state,
cmd->se_cmd.se_cmd_flags);
return 0;
}
cmd->trc_flags |= TRC_XMIT_DATA;
cmd->bufflen = se_cmd->data_length;
cmd->dma_data_direction = target_reverse_dma_direction(se_cmd);
cmd->sg_cnt = se_cmd->t_data_nents;
cmd->sg = se_cmd->t_data_sg;
cmd->offset = 0;
cmd->prot_sg_cnt = se_cmd->t_prot_nents;
cmd->prot_sg = se_cmd->t_prot_sg;
cmd->blk_sz = se_cmd->se_dev->dev_attrib.block_size;
se_cmd->pi_err = 0;
return qlt_xmit_response(cmd, QLA_TGT_XMIT_DATA|QLA_TGT_XMIT_STATUS,
se_cmd->scsi_status);
}
static int tcm_qla2xxx_queue_status(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
int xmit_type = QLA_TGT_XMIT_STATUS;
if (cmd->aborted) {
pr_debug(
"queue_data_in aborted cmd[%p] refcount %d transport_state %x, t_state %x, se_cmd_flags %x\n",
cmd, kref_read(&cmd->se_cmd.cmd_kref),
cmd->se_cmd.transport_state, cmd->se_cmd.t_state,
cmd->se_cmd.se_cmd_flags);
return 0;
}
cmd->bufflen = se_cmd->data_length;
cmd->sg = NULL;
cmd->sg_cnt = 0;
cmd->offset = 0;
cmd->dma_data_direction = target_reverse_dma_direction(se_cmd);
if (cmd->trc_flags & TRC_XMIT_STATUS) {
pr_crit("Multiple calls for status = %p.\n", cmd);
dump_stack();
}
cmd->trc_flags |= TRC_XMIT_STATUS;
if (se_cmd->data_direction == DMA_FROM_DEVICE) {
if (se_cmd->se_cmd_flags & SCF_OVERFLOW_BIT) {
se_cmd->se_cmd_flags &= ~SCF_OVERFLOW_BIT;
se_cmd->residual_count = 0;
}
se_cmd->se_cmd_flags |= SCF_UNDERFLOW_BIT;
se_cmd->residual_count += se_cmd->data_length;
cmd->bufflen = 0;
}
return qlt_xmit_response(cmd, xmit_type, se_cmd->scsi_status);
}
static void tcm_qla2xxx_queue_tm_rsp(struct se_cmd *se_cmd)
{
struct se_tmr_req *se_tmr = se_cmd->se_tmr_req;
struct qla_tgt_mgmt_cmd *mcmd = container_of(se_cmd,
struct qla_tgt_mgmt_cmd, se_cmd);
pr_debug("queue_tm_rsp: mcmd: %p func: 0x%02x response: 0x%02x\n",
mcmd, se_tmr->function, se_tmr->response);
switch (se_tmr->response) {
case TMR_FUNCTION_COMPLETE:
mcmd->fc_tm_rsp = FC_TM_SUCCESS;
break;
case TMR_TASK_DOES_NOT_EXIST:
mcmd->fc_tm_rsp = FC_TM_BAD_CMD;
break;
case TMR_FUNCTION_REJECTED:
mcmd->fc_tm_rsp = FC_TM_REJECT;
break;
case TMR_LUN_DOES_NOT_EXIST:
default:
mcmd->fc_tm_rsp = FC_TM_FAILED;
break;
}
qlt_xmit_tm_rsp(mcmd);
}
static void tcm_qla2xxx_aborted_task(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
if (qlt_abort_cmd(cmd))
return;
}
static void tcm_qla2xxx_clear_nacl_from_fcport_map(struct fc_port *sess)
{
struct se_node_acl *se_nacl = sess->se_sess->se_node_acl;
struct se_portal_group *se_tpg = se_nacl->se_tpg;
struct se_wwn *se_wwn = se_tpg->se_tpg_wwn;
struct tcm_qla2xxx_lport *lport = container_of(se_wwn,
struct tcm_qla2xxx_lport, lport_wwn);
struct tcm_qla2xxx_nacl *nacl = container_of(se_nacl,
struct tcm_qla2xxx_nacl, se_node_acl);
void *node;
pr_debug("fc_rport domain: port_id 0x%06x\n", nacl->nport_id);
node = btree_remove32(&lport->lport_fcport_map, nacl->nport_id);
if (WARN_ON(node && (node != se_nacl))) {
btree_insert32(&lport->lport_fcport_map, nacl->nport_id,
node, GFP_ATOMIC);
}
pr_debug("Removed from fcport_map: %p for WWNN: 0x%016LX, port_id: 0x%06x\n",
se_nacl, nacl->nport_wwnn, nacl->nport_id);
tcm_qla2xxx_clear_sess_lookup(lport, nacl, sess);
}
static void tcm_qla2xxx_shutdown_sess(struct fc_port *sess)
{
assert_spin_locked(&sess->vha->hw->tgt.sess_lock);
target_sess_cmd_list_set_waiting(sess->se_sess);
}
static int tcm_qla2xxx_init_nodeacl(struct se_node_acl *se_nacl,
const char *name)
{
struct tcm_qla2xxx_nacl *nacl =
container_of(se_nacl, struct tcm_qla2xxx_nacl, se_node_acl);
u64 wwnn;
if (tcm_qla2xxx_parse_wwn(name, &wwnn, 1) < 0)
return -EINVAL;
nacl->nport_wwnn = wwnn;
tcm_qla2xxx_format_wwn(&nacl->nport_name[0], TCM_QLA2XXX_NAMELEN, wwnn);
return 0;
}
static ssize_t tcm_qla2xxx_tpg_enable_show(struct config_item *item,
char *page)
{
struct se_portal_group *se_tpg = to_tpg(item);
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return snprintf(page, PAGE_SIZE, "%d\n",
atomic_read(&tpg->lport_tpg_enabled));
}
static void tcm_qla2xxx_depend_tpg(struct work_struct *work)
{
struct tcm_qla2xxx_tpg *base_tpg = container_of(work,
struct tcm_qla2xxx_tpg, tpg_base_work);
struct se_portal_group *se_tpg = &base_tpg->se_tpg;
struct scsi_qla_host *base_vha = base_tpg->lport->qla_vha;
if (!target_depend_item(&se_tpg->tpg_group.cg_item)) {
atomic_set(&base_tpg->lport_tpg_enabled, 1);
qlt_enable_vha(base_vha);
}
complete(&base_tpg->tpg_base_comp);
}
static void tcm_qla2xxx_undepend_tpg(struct work_struct *work)
{
struct tcm_qla2xxx_tpg *base_tpg = container_of(work,
struct tcm_qla2xxx_tpg, tpg_base_work);
struct se_portal_group *se_tpg = &base_tpg->se_tpg;
struct scsi_qla_host *base_vha = base_tpg->lport->qla_vha;
if (!qlt_stop_phase1(base_vha->vha_tgt.qla_tgt)) {
atomic_set(&base_tpg->lport_tpg_enabled, 0);
target_undepend_item(&se_tpg->tpg_group.cg_item);
}
complete(&base_tpg->tpg_base_comp);
}
static ssize_t tcm_qla2xxx_tpg_enable_store(struct config_item *item,
const char *page, size_t count)
{
struct se_portal_group *se_tpg = to_tpg(item);
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
unsigned long op;
int rc;
rc = kstrtoul(page, 0, &op);
if (rc < 0) {
pr_err("kstrtoul() returned %d\n", rc);
return -EINVAL;
}
if ((op != 1) && (op != 0)) {
pr_err("Illegal value for tpg_enable: %lu\n", op);
return -EINVAL;
}
if (op) {
if (atomic_read(&tpg->lport_tpg_enabled))
return -EEXIST;
INIT_WORK(&tpg->tpg_base_work, tcm_qla2xxx_depend_tpg);
} else {
if (!atomic_read(&tpg->lport_tpg_enabled))
return count;
INIT_WORK(&tpg->tpg_base_work, tcm_qla2xxx_undepend_tpg);
}
init_completion(&tpg->tpg_base_comp);
schedule_work(&tpg->tpg_base_work);
wait_for_completion(&tpg->tpg_base_comp);
if (op) {
if (!atomic_read(&tpg->lport_tpg_enabled))
return -ENODEV;
} else {
if (atomic_read(&tpg->lport_tpg_enabled))
return -EPERM;
}
return count;
}
static ssize_t tcm_qla2xxx_tpg_dynamic_sessions_show(struct config_item *item,
char *page)
{
return target_show_dynamic_sessions(to_tpg(item), page);
}
static ssize_t tcm_qla2xxx_tpg_fabric_prot_type_store(struct config_item *item,
const char *page, size_t count)
{
struct se_portal_group *se_tpg = to_tpg(item);
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
unsigned long val;
int ret = kstrtoul(page, 0, &val);
if (ret) {
pr_err("kstrtoul() returned %d for fabric_prot_type\n", ret);
return ret;
}
if (val != 0 && val != 1 && val != 3) {
pr_err("Invalid qla2xxx fabric_prot_type: %lu\n", val);
return -EINVAL;
}
tpg->tpg_attrib.fabric_prot_type = val;
return count;
}
static ssize_t tcm_qla2xxx_tpg_fabric_prot_type_show(struct config_item *item,
char *page)
{
struct se_portal_group *se_tpg = to_tpg(item);
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
return sprintf(page, "%d\n", tpg->tpg_attrib.fabric_prot_type);
}
static struct se_portal_group *tcm_qla2xxx_make_tpg(
struct se_wwn *wwn,
struct config_group *group,
const char *name)
{
struct tcm_qla2xxx_lport *lport = container_of(wwn,
struct tcm_qla2xxx_lport, lport_wwn);
struct tcm_qla2xxx_tpg *tpg;
unsigned long tpgt;
int ret;
if (strstr(name, "tpgt_") != name)
return ERR_PTR(-EINVAL);
if (kstrtoul(name + 5, 10, &tpgt) || tpgt > USHRT_MAX)
return ERR_PTR(-EINVAL);
if ((tpgt != 1)) {
pr_err("In non NPIV mode, a single TPG=1 is used for HW port mappings\n");
return ERR_PTR(-ENOSYS);
}
tpg = kzalloc(sizeof(struct tcm_qla2xxx_tpg), GFP_KERNEL);
if (!tpg) {
pr_err("Unable to allocate struct tcm_qla2xxx_tpg\n");
return ERR_PTR(-ENOMEM);
}
tpg->lport = lport;
tpg->lport_tpgt = tpgt;
tpg->tpg_attrib.generate_node_acls = 1;
tpg->tpg_attrib.demo_mode_write_protect = 1;
tpg->tpg_attrib.cache_dynamic_acls = 1;
tpg->tpg_attrib.demo_mode_login_only = 1;
tpg->tpg_attrib.jam_host = 0;
ret = core_tpg_register(wwn, &tpg->se_tpg, SCSI_PROTOCOL_FCP);
if (ret < 0) {
kfree(tpg);
return NULL;
}
lport->tpg_1 = tpg;
return &tpg->se_tpg;
}
static void tcm_qla2xxx_drop_tpg(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
struct tcm_qla2xxx_lport *lport = tpg->lport;
struct scsi_qla_host *vha = lport->qla_vha;
if (vha->vha_tgt.qla_tgt && !vha->vha_tgt.qla_tgt->tgt_stop)
qlt_stop_phase1(vha->vha_tgt.qla_tgt);
core_tpg_deregister(se_tpg);
lport->tpg_1 = NULL;
kfree(tpg);
}
static ssize_t tcm_qla2xxx_npiv_tpg_enable_show(struct config_item *item,
char *page)
{
return tcm_qla2xxx_tpg_enable_show(item, page);
}
static ssize_t tcm_qla2xxx_npiv_tpg_enable_store(struct config_item *item,
const char *page, size_t count)
{
struct se_portal_group *se_tpg = to_tpg(item);
struct se_wwn *se_wwn = se_tpg->se_tpg_wwn;
struct tcm_qla2xxx_lport *lport = container_of(se_wwn,
struct tcm_qla2xxx_lport, lport_wwn);
struct scsi_qla_host *vha = lport->qla_vha;
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
unsigned long op;
int rc;
rc = kstrtoul(page, 0, &op);
if (rc < 0) {
pr_err("kstrtoul() returned %d\n", rc);
return -EINVAL;
}
if ((op != 1) && (op != 0)) {
pr_err("Illegal value for tpg_enable: %lu\n", op);
return -EINVAL;
}
if (op) {
if (atomic_read(&tpg->lport_tpg_enabled))
return -EEXIST;
atomic_set(&tpg->lport_tpg_enabled, 1);
qlt_enable_vha(vha);
} else {
if (!atomic_read(&tpg->lport_tpg_enabled))
return count;
atomic_set(&tpg->lport_tpg_enabled, 0);
qlt_stop_phase1(vha->vha_tgt.qla_tgt);
}
return count;
}
static struct se_portal_group *tcm_qla2xxx_npiv_make_tpg(
struct se_wwn *wwn,
struct config_group *group,
const char *name)
{
struct tcm_qla2xxx_lport *lport = container_of(wwn,
struct tcm_qla2xxx_lport, lport_wwn);
struct tcm_qla2xxx_tpg *tpg;
unsigned long tpgt;
int ret;
if (strstr(name, "tpgt_") != name)
return ERR_PTR(-EINVAL);
if (kstrtoul(name + 5, 10, &tpgt) || tpgt > USHRT_MAX)
return ERR_PTR(-EINVAL);
tpg = kzalloc(sizeof(struct tcm_qla2xxx_tpg), GFP_KERNEL);
if (!tpg) {
pr_err("Unable to allocate struct tcm_qla2xxx_tpg\n");
return ERR_PTR(-ENOMEM);
}
tpg->lport = lport;
tpg->lport_tpgt = tpgt;
tpg->tpg_attrib.generate_node_acls = 1;
tpg->tpg_attrib.demo_mode_write_protect = 1;
tpg->tpg_attrib.cache_dynamic_acls = 1;
tpg->tpg_attrib.demo_mode_login_only = 1;
ret = core_tpg_register(wwn, &tpg->se_tpg, SCSI_PROTOCOL_FCP);
if (ret < 0) {
kfree(tpg);
return NULL;
}
lport->tpg_1 = tpg;
return &tpg->se_tpg;
}
static struct fc_port *tcm_qla2xxx_find_sess_by_s_id(
scsi_qla_host_t *vha,
const uint8_t *s_id)
{
struct tcm_qla2xxx_lport *lport;
struct se_node_acl *se_nacl;
struct tcm_qla2xxx_nacl *nacl;
u32 key;
lport = vha->vha_tgt.target_lport_ptr;
if (!lport) {
pr_err("Unable to locate struct tcm_qla2xxx_lport\n");
dump_stack();
return NULL;
}
key = sid_to_key(s_id);
pr_debug("find_sess_by_s_id: 0x%06x\n", key);
se_nacl = btree_lookup32(&lport->lport_fcport_map, key);
if (!se_nacl) {
pr_debug("Unable to locate s_id: 0x%06x\n", key);
return NULL;
}
pr_debug("find_sess_by_s_id: located se_nacl: %p, initiatorname: %s\n",
se_nacl, se_nacl->initiatorname);
nacl = container_of(se_nacl, struct tcm_qla2xxx_nacl, se_node_acl);
if (!nacl->fc_port) {
pr_err("Unable to locate struct fc_port\n");
return NULL;
}
return nacl->fc_port;
}
static void tcm_qla2xxx_set_sess_by_s_id(
struct tcm_qla2xxx_lport *lport,
struct se_node_acl *new_se_nacl,
struct tcm_qla2xxx_nacl *nacl,
struct se_session *se_sess,
struct fc_port *fc_port,
uint8_t *s_id)
{
u32 key;
void *slot;
int rc;
key = sid_to_key(s_id);
pr_debug("set_sess_by_s_id: %06x\n", key);
slot = btree_lookup32(&lport->lport_fcport_map, key);
if (!slot) {
if (new_se_nacl) {
pr_debug("Setting up new fc_port entry to new_se_nacl\n");
nacl->nport_id = key;
rc = btree_insert32(&lport->lport_fcport_map, key,
new_se_nacl, GFP_ATOMIC);
if (rc)
printk(KERN_ERR "Unable to insert s_id into fcport_map: %06x\n",
(int)key);
} else {
pr_debug("Wiping nonexisting fc_port entry\n");
}
fc_port->se_sess = se_sess;
nacl->fc_port = fc_port;
return;
}
if (nacl->fc_port) {
if (new_se_nacl == NULL) {
pr_debug("Clearing existing nacl->fc_port and fc_port entry\n");
btree_remove32(&lport->lport_fcport_map, key);
nacl->fc_port = NULL;
return;
}
pr_debug("Replacing existing nacl->fc_port and fc_port entry\n");
btree_update32(&lport->lport_fcport_map, key, new_se_nacl);
fc_port->se_sess = se_sess;
nacl->fc_port = fc_port;
return;
}
if (new_se_nacl == NULL) {
pr_debug("Clearing existing fc_port entry\n");
btree_remove32(&lport->lport_fcport_map, key);
return;
}
pr_debug("Replacing existing fc_port entry w/o active nacl->fc_port\n");
btree_update32(&lport->lport_fcport_map, key, new_se_nacl);
fc_port->se_sess = se_sess;
nacl->fc_port = fc_port;
pr_debug("Setup nacl->fc_port %p by s_id for se_nacl: %p, initiatorname: %s\n",
nacl->fc_port, new_se_nacl, new_se_nacl->initiatorname);
}
static struct fc_port *tcm_qla2xxx_find_sess_by_loop_id(
scsi_qla_host_t *vha,
const uint16_t loop_id)
{
struct tcm_qla2xxx_lport *lport;
struct se_node_acl *se_nacl;
struct tcm_qla2xxx_nacl *nacl;
struct tcm_qla2xxx_fc_loopid *fc_loopid;
lport = vha->vha_tgt.target_lport_ptr;
if (!lport) {
pr_err("Unable to locate struct tcm_qla2xxx_lport\n");
dump_stack();
return NULL;
}
pr_debug("find_sess_by_loop_id: Using loop_id: 0x%04x\n", loop_id);
fc_loopid = lport->lport_loopid_map + loop_id;
se_nacl = fc_loopid->se_nacl;
if (!se_nacl) {
pr_debug("Unable to locate se_nacl by loop_id: 0x%04x\n",
loop_id);
return NULL;
}
nacl = container_of(se_nacl, struct tcm_qla2xxx_nacl, se_node_acl);
if (!nacl->fc_port) {
pr_err("Unable to locate struct fc_port\n");
return NULL;
}
return nacl->fc_port;
}
static void tcm_qla2xxx_set_sess_by_loop_id(
struct tcm_qla2xxx_lport *lport,
struct se_node_acl *new_se_nacl,
struct tcm_qla2xxx_nacl *nacl,
struct se_session *se_sess,
struct fc_port *fc_port,
uint16_t loop_id)
{
struct se_node_acl *saved_nacl;
struct tcm_qla2xxx_fc_loopid *fc_loopid;
pr_debug("set_sess_by_loop_id: Using loop_id: 0x%04x\n", loop_id);
fc_loopid = &((struct tcm_qla2xxx_fc_loopid *)
lport->lport_loopid_map)[loop_id];
saved_nacl = fc_loopid->se_nacl;
if (!saved_nacl) {
pr_debug("Setting up new fc_loopid->se_nacl to new_se_nacl\n");
fc_loopid->se_nacl = new_se_nacl;
if (fc_port->se_sess != se_sess)
fc_port->se_sess = se_sess;
if (nacl->fc_port != fc_port)
nacl->fc_port = fc_port;
return;
}
if (nacl->fc_port) {
if (new_se_nacl == NULL) {
pr_debug("Clearing nacl->fc_port and fc_loopid->se_nacl\n");
fc_loopid->se_nacl = NULL;
nacl->fc_port = NULL;
return;
}
pr_debug("Replacing existing nacl->fc_port and fc_loopid->se_nacl\n");
fc_loopid->se_nacl = new_se_nacl;
if (fc_port->se_sess != se_sess)
fc_port->se_sess = se_sess;
if (nacl->fc_port != fc_port)
nacl->fc_port = fc_port;
return;
}
if (new_se_nacl == NULL) {
pr_debug("Clearing fc_loopid->se_nacl\n");
fc_loopid->se_nacl = NULL;
return;
}
pr_debug("Replacing existing fc_loopid->se_nacl w/o active nacl->fc_port\n");
fc_loopid->se_nacl = new_se_nacl;
if (fc_port->se_sess != se_sess)
fc_port->se_sess = se_sess;
if (nacl->fc_port != fc_port)
nacl->fc_port = fc_port;
pr_debug("Setup nacl->fc_port %p by loop_id for se_nacl: %p, initiatorname: %s\n",
nacl->fc_port, new_se_nacl, new_se_nacl->initiatorname);
}
static void tcm_qla2xxx_clear_sess_lookup(struct tcm_qla2xxx_lport *lport,
struct tcm_qla2xxx_nacl *nacl, struct fc_port *sess)
{
struct se_session *se_sess = sess->se_sess;
unsigned char be_sid[3];
be_sid[0] = sess->d_id.b.domain;
be_sid[1] = sess->d_id.b.area;
be_sid[2] = sess->d_id.b.al_pa;
tcm_qla2xxx_set_sess_by_s_id(lport, NULL, nacl, se_sess,
sess, be_sid);
tcm_qla2xxx_set_sess_by_loop_id(lport, NULL, nacl, se_sess,
sess, sess->loop_id);
}
static void tcm_qla2xxx_free_session(struct fc_port *sess)
{
struct qla_tgt *tgt = sess->tgt;
struct qla_hw_data *ha = tgt->ha;
scsi_qla_host_t *vha = pci_get_drvdata(ha->pdev);
struct se_session *se_sess;
struct tcm_qla2xxx_lport *lport;
BUG_ON(in_interrupt());
se_sess = sess->se_sess;
if (!se_sess) {
pr_err("struct fc_port->se_sess is NULL\n");
dump_stack();
return;
}
lport = vha->vha_tgt.target_lport_ptr;
if (!lport) {
pr_err("Unable to locate struct tcm_qla2xxx_lport\n");
dump_stack();
return;
}
target_wait_for_sess_cmds(se_sess);
transport_deregister_session_configfs(sess->se_sess);
transport_deregister_session(sess->se_sess);
}
static int tcm_qla2xxx_session_cb(struct se_portal_group *se_tpg,
struct se_session *se_sess, void *p)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
struct tcm_qla2xxx_lport *lport = tpg->lport;
struct qla_hw_data *ha = lport->qla_vha->hw;
struct se_node_acl *se_nacl = se_sess->se_node_acl;
struct tcm_qla2xxx_nacl *nacl = container_of(se_nacl,
struct tcm_qla2xxx_nacl, se_node_acl);
struct fc_port *qlat_sess = p;
uint16_t loop_id = qlat_sess->loop_id;
unsigned long flags;
unsigned char be_sid[3];
be_sid[0] = qlat_sess->d_id.b.domain;
be_sid[1] = qlat_sess->d_id.b.area;
be_sid[2] = qlat_sess->d_id.b.al_pa;
spin_lock_irqsave(&ha->tgt.sess_lock, flags);
tcm_qla2xxx_set_sess_by_s_id(lport, se_nacl, nacl,
se_sess, qlat_sess, be_sid);
tcm_qla2xxx_set_sess_by_loop_id(lport, se_nacl, nacl,
se_sess, qlat_sess, loop_id);
spin_unlock_irqrestore(&ha->tgt.sess_lock, flags);
return 0;
}
static int tcm_qla2xxx_check_initiator_node_acl(
scsi_qla_host_t *vha,
unsigned char *fc_wwpn,
struct fc_port *qlat_sess)
{
struct qla_hw_data *ha = vha->hw;
struct tcm_qla2xxx_lport *lport;
struct tcm_qla2xxx_tpg *tpg;
struct se_session *se_sess;
unsigned char port_name[36];
int num_tags = (ha->cur_fw_xcb_count) ? ha->cur_fw_xcb_count :
TCM_QLA2XXX_DEFAULT_TAGS;
lport = vha->vha_tgt.target_lport_ptr;
if (!lport) {
pr_err("Unable to locate struct tcm_qla2xxx_lport\n");
dump_stack();
return -EINVAL;
}
tpg = lport->tpg_1;
if (!tpg) {
pr_err("Unable to lcoate struct tcm_qla2xxx_lport->tpg_1\n");
return -EINVAL;
}
memset(&port_name, 0, 36);
snprintf(port_name, sizeof(port_name), "%8phC", fc_wwpn);
se_sess = target_alloc_session(&tpg->se_tpg, num_tags,
sizeof(struct qla_tgt_cmd),
TARGET_PROT_ALL, port_name,
qlat_sess, tcm_qla2xxx_session_cb);
if (IS_ERR(se_sess))
return PTR_ERR(se_sess);
return 0;
}
static void tcm_qla2xxx_update_sess(struct fc_port *sess, port_id_t s_id,
uint16_t loop_id, bool conf_compl_supported)
{
struct qla_tgt *tgt = sess->tgt;
struct qla_hw_data *ha = tgt->ha;
scsi_qla_host_t *vha = pci_get_drvdata(ha->pdev);
struct tcm_qla2xxx_lport *lport = vha->vha_tgt.target_lport_ptr;
struct se_node_acl *se_nacl = sess->se_sess->se_node_acl;
struct tcm_qla2xxx_nacl *nacl = container_of(se_nacl,
struct tcm_qla2xxx_nacl, se_node_acl);
u32 key;
if (sess->loop_id != loop_id || sess->d_id.b24 != s_id.b24)
pr_info("Updating session %p from port %8phC loop_id %d -> %d s_id %x:%x:%x -> %x:%x:%x\n",
sess, sess->port_name,
sess->loop_id, loop_id, sess->d_id.b.domain,
sess->d_id.b.area, sess->d_id.b.al_pa, s_id.b.domain,
s_id.b.area, s_id.b.al_pa);
if (sess->loop_id != loop_id) {
if (lport->lport_loopid_map[sess->loop_id].se_nacl == se_nacl)
lport->lport_loopid_map[sess->loop_id].se_nacl = NULL;
lport->lport_loopid_map[loop_id].se_nacl = se_nacl;
sess->loop_id = loop_id;
}
if (sess->d_id.b24 != s_id.b24) {
key = (((u32) sess->d_id.b.domain << 16) |
((u32) sess->d_id.b.area << 8) |
((u32) sess->d_id.b.al_pa));
if (btree_lookup32(&lport->lport_fcport_map, key))
WARN(btree_remove32(&lport->lport_fcport_map, key) !=
se_nacl, "Found wrong se_nacl when updating s_id %x:%x:%x\n",
sess->d_id.b.domain, sess->d_id.b.area,
sess->d_id.b.al_pa);
else
WARN(1, "No lport_fcport_map entry for s_id %x:%x:%x\n",
sess->d_id.b.domain, sess->d_id.b.area,
sess->d_id.b.al_pa);
key = (((u32) s_id.b.domain << 16) |
((u32) s_id.b.area << 8) |
((u32) s_id.b.al_pa));
if (btree_lookup32(&lport->lport_fcport_map, key)) {
WARN(1, "Already have lport_fcport_map entry for s_id %x:%x:%x\n",
s_id.b.domain, s_id.b.area, s_id.b.al_pa);
btree_update32(&lport->lport_fcport_map, key, se_nacl);
} else {
btree_insert32(&lport->lport_fcport_map, key, se_nacl,
GFP_ATOMIC);
}
sess->d_id = s_id;
nacl->nport_id = key;
}
sess->conf_compl_supported = conf_compl_supported;
sess->logout_on_delete = 1;
sess->keep_nport_handle = 0;
}
static int tcm_qla2xxx_init_lport(struct tcm_qla2xxx_lport *lport)
{
int rc;
rc = btree_init32(&lport->lport_fcport_map);
if (rc) {
pr_err("Unable to initialize lport->lport_fcport_map btree\n");
return rc;
}
lport->lport_loopid_map = vmalloc(sizeof(struct tcm_qla2xxx_fc_loopid) *
65536);
if (!lport->lport_loopid_map) {
pr_err("Unable to allocate lport->lport_loopid_map of %zu bytes\n",
sizeof(struct tcm_qla2xxx_fc_loopid) * 65536);
btree_destroy32(&lport->lport_fcport_map);
return -ENOMEM;
}
memset(lport->lport_loopid_map, 0, sizeof(struct tcm_qla2xxx_fc_loopid)
* 65536);
pr_debug("qla2xxx: Allocated lport_loopid_map of %zu bytes\n",
sizeof(struct tcm_qla2xxx_fc_loopid) * 65536);
return 0;
}
static int tcm_qla2xxx_lport_register_cb(struct scsi_qla_host *vha,
void *target_lport_ptr,
u64 npiv_wwpn, u64 npiv_wwnn)
{
struct qla_hw_data *ha = vha->hw;
struct tcm_qla2xxx_lport *lport =
(struct tcm_qla2xxx_lport *)target_lport_ptr;
ha->tgt.tgt_ops = &tcm_qla2xxx_template;
vha->vha_tgt.target_lport_ptr = target_lport_ptr;
lport->qla_vha = vha;
return 0;
}
static struct se_wwn *tcm_qla2xxx_make_lport(
struct target_fabric_configfs *tf,
struct config_group *group,
const char *name)
{
struct tcm_qla2xxx_lport *lport;
u64 wwpn;
int ret = -ENODEV;
if (tcm_qla2xxx_parse_wwn(name, &wwpn, 1) < 0)
return ERR_PTR(-EINVAL);
lport = kzalloc(sizeof(struct tcm_qla2xxx_lport), GFP_KERNEL);
if (!lport) {
pr_err("Unable to allocate struct tcm_qla2xxx_lport\n");
return ERR_PTR(-ENOMEM);
}
lport->lport_wwpn = wwpn;
tcm_qla2xxx_format_wwn(&lport->lport_name[0], TCM_QLA2XXX_NAMELEN,
wwpn);
sprintf(lport->lport_naa_name, "naa.%016llx", (unsigned long long) wwpn);
ret = tcm_qla2xxx_init_lport(lport);
if (ret != 0)
goto out;
ret = qlt_lport_register(lport, wwpn, 0, 0,
tcm_qla2xxx_lport_register_cb);
if (ret != 0)
goto out_lport;
return &lport->lport_wwn;
out_lport:
vfree(lport->lport_loopid_map);
btree_destroy32(&lport->lport_fcport_map);
out:
kfree(lport);
return ERR_PTR(ret);
}
static void tcm_qla2xxx_drop_lport(struct se_wwn *wwn)
{
struct tcm_qla2xxx_lport *lport = container_of(wwn,
struct tcm_qla2xxx_lport, lport_wwn);
struct scsi_qla_host *vha = lport->qla_vha;
struct se_node_acl *node;
u32 key = 0;
if (vha->vha_tgt.qla_tgt && !vha->vha_tgt.qla_tgt->tgt_stopped)
qlt_stop_phase2(vha->vha_tgt.qla_tgt);
qlt_lport_deregister(vha);
vfree(lport->lport_loopid_map);
btree_for_each_safe32(&lport->lport_fcport_map, key, node)
btree_remove32(&lport->lport_fcport_map, key);
btree_destroy32(&lport->lport_fcport_map);
kfree(lport);
}
static int tcm_qla2xxx_lport_register_npiv_cb(struct scsi_qla_host *base_vha,
void *target_lport_ptr,
u64 npiv_wwpn, u64 npiv_wwnn)
{
struct fc_vport *vport;
struct Scsi_Host *sh = base_vha->host;
struct scsi_qla_host *npiv_vha;
struct tcm_qla2xxx_lport *lport =
(struct tcm_qla2xxx_lport *)target_lport_ptr;
struct tcm_qla2xxx_lport *base_lport =
(struct tcm_qla2xxx_lport *)base_vha->vha_tgt.target_lport_ptr;
struct fc_vport_identifiers vport_id;
if (qla_ini_mode_enabled(base_vha)) {
pr_err("qla2xxx base_vha not enabled for target mode\n");
return -EPERM;
}
if (!base_lport || !base_lport->tpg_1 ||
!atomic_read(&base_lport->tpg_1->lport_tpg_enabled)) {
pr_err("qla2xxx base_lport or tpg_1 not available\n");
return -EPERM;
}
memset(&vport_id, 0, sizeof(vport_id));
vport_id.port_name = npiv_wwpn;
vport_id.node_name = npiv_wwnn;
vport_id.roles = FC_PORT_ROLE_FCP_INITIATOR;
vport_id.vport_type = FC_PORTTYPE_NPIV;
vport_id.disable = false;
vport = fc_vport_create(sh, 0, &vport_id);
if (!vport) {
pr_err("fc_vport_create failed for qla2xxx_npiv\n");
return -ENODEV;
}
npiv_vha = (struct scsi_qla_host *)vport->dd_data;
npiv_vha->vha_tgt.target_lport_ptr = target_lport_ptr;
lport->qla_vha = npiv_vha;
scsi_host_get(npiv_vha->host);
return 0;
}
static struct se_wwn *tcm_qla2xxx_npiv_make_lport(
struct target_fabric_configfs *tf,
struct config_group *group,
const char *name)
{
struct tcm_qla2xxx_lport *lport;
u64 phys_wwpn, npiv_wwpn, npiv_wwnn;
char *p, tmp[128];
int ret;
snprintf(tmp, 128, "%s", name);
p = strchr(tmp, '@');
if (!p) {
pr_err("Unable to locate NPIV '@' separator\n");
return ERR_PTR(-EINVAL);
}
*p++ = '\0';
if (tcm_qla2xxx_parse_wwn(tmp, &phys_wwpn, 1) < 0)
return ERR_PTR(-EINVAL);
if (tcm_qla2xxx_npiv_parse_wwn(p, strlen(p)+1,
&npiv_wwpn, &npiv_wwnn) < 0)
return ERR_PTR(-EINVAL);
lport = kzalloc(sizeof(struct tcm_qla2xxx_lport), GFP_KERNEL);
if (!lport) {
pr_err("Unable to allocate struct tcm_qla2xxx_lport for NPIV\n");
return ERR_PTR(-ENOMEM);
}
lport->lport_npiv_wwpn = npiv_wwpn;
lport->lport_npiv_wwnn = npiv_wwnn;
sprintf(lport->lport_naa_name, "naa.%016llx", (unsigned long long) npiv_wwpn);
ret = tcm_qla2xxx_init_lport(lport);
if (ret != 0)
goto out;
ret = qlt_lport_register(lport, phys_wwpn, npiv_wwpn, npiv_wwnn,
tcm_qla2xxx_lport_register_npiv_cb);
if (ret != 0)
goto out_lport;
return &lport->lport_wwn;
out_lport:
vfree(lport->lport_loopid_map);
btree_destroy32(&lport->lport_fcport_map);
out:
kfree(lport);
return ERR_PTR(ret);
}
static void tcm_qla2xxx_npiv_drop_lport(struct se_wwn *wwn)
{
struct tcm_qla2xxx_lport *lport = container_of(wwn,
struct tcm_qla2xxx_lport, lport_wwn);
struct scsi_qla_host *npiv_vha = lport->qla_vha;
struct qla_hw_data *ha = npiv_vha->hw;
scsi_qla_host_t *base_vha = pci_get_drvdata(ha->pdev);
scsi_host_put(npiv_vha->host);
fc_vport_terminate(npiv_vha->fc_vport);
scsi_host_put(base_vha->host);
kfree(lport);
}
static ssize_t tcm_qla2xxx_wwn_version_show(struct config_item *item,
char *page)
{
return sprintf(page,
"TCM QLOGIC QLA2XXX NPIV capable fabric module %s on %s/%s on %s\n",
QLA2XXX_VERSION, utsname()->sysname,
utsname()->machine, utsname()->release);
}
static int tcm_qla2xxx_register_configfs(void)
{
int ret;
pr_debug("TCM QLOGIC QLA2XXX fabric module %s on %s/%s on %s\n",
QLA2XXX_VERSION, utsname()->sysname,
utsname()->machine, utsname()->release);
ret = target_register_template(&tcm_qla2xxx_ops);
if (ret)
return ret;
ret = target_register_template(&tcm_qla2xxx_npiv_ops);
if (ret)
goto out_fabric;
tcm_qla2xxx_free_wq = alloc_workqueue("tcm_qla2xxx_free",
WQ_MEM_RECLAIM, 0);
if (!tcm_qla2xxx_free_wq) {
ret = -ENOMEM;
goto out_fabric_npiv;
}
tcm_qla2xxx_cmd_wq = alloc_workqueue("tcm_qla2xxx_cmd", 0, 0);
if (!tcm_qla2xxx_cmd_wq) {
ret = -ENOMEM;
goto out_free_wq;
}
return 0;
out_free_wq:
destroy_workqueue(tcm_qla2xxx_free_wq);
out_fabric_npiv:
target_unregister_template(&tcm_qla2xxx_npiv_ops);
out_fabric:
target_unregister_template(&tcm_qla2xxx_ops);
return ret;
}
static void tcm_qla2xxx_deregister_configfs(void)
{
destroy_workqueue(tcm_qla2xxx_cmd_wq);
destroy_workqueue(tcm_qla2xxx_free_wq);
target_unregister_template(&tcm_qla2xxx_ops);
target_unregister_template(&tcm_qla2xxx_npiv_ops);
}
static int __init tcm_qla2xxx_init(void)
{
int ret;
ret = tcm_qla2xxx_register_configfs();
if (ret < 0)
return ret;
return 0;
}
static void __exit tcm_qla2xxx_exit(void)
{
tcm_qla2xxx_deregister_configfs();
}
