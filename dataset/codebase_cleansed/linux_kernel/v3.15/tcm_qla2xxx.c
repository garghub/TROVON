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
static u8 tcm_qla2xxx_get_fabric_proto_ident(struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
struct tcm_qla2xxx_lport *lport = tpg->lport;
u8 proto_id;
switch (lport->lport_proto_id) {
case SCSI_PROTOCOL_FCP:
default:
proto_id = fc_get_fabric_proto_ident(se_tpg);
break;
}
return proto_id;
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
static u32 tcm_qla2xxx_get_default_depth(struct se_portal_group *se_tpg)
{
return 1;
}
static u32 tcm_qla2xxx_get_pr_transport_id(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int *format_code,
unsigned char *buf)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
struct tcm_qla2xxx_lport *lport = tpg->lport;
int ret = 0;
switch (lport->lport_proto_id) {
case SCSI_PROTOCOL_FCP:
default:
ret = fc_get_pr_transport_id(se_tpg, se_nacl, pr_reg,
format_code, buf);
break;
}
return ret;
}
static u32 tcm_qla2xxx_get_pr_transport_id_len(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl,
struct t10_pr_registration *pr_reg,
int *format_code)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
struct tcm_qla2xxx_lport *lport = tpg->lport;
int ret = 0;
switch (lport->lport_proto_id) {
case SCSI_PROTOCOL_FCP:
default:
ret = fc_get_pr_transport_id_len(se_tpg, se_nacl, pr_reg,
format_code);
break;
}
return ret;
}
static char *tcm_qla2xxx_parse_pr_out_transport_id(
struct se_portal_group *se_tpg,
const char *buf,
u32 *out_tid_len,
char **port_nexus_ptr)
{
struct tcm_qla2xxx_tpg *tpg = container_of(se_tpg,
struct tcm_qla2xxx_tpg, se_tpg);
struct tcm_qla2xxx_lport *lport = tpg->lport;
char *tid = NULL;
switch (lport->lport_proto_id) {
case SCSI_PROTOCOL_FCP:
default:
tid = fc_parse_pr_out_transport_id(se_tpg, buf, out_tid_len,
port_nexus_ptr);
break;
}
return tid;
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
static struct se_node_acl *tcm_qla2xxx_alloc_fabric_acl(
struct se_portal_group *se_tpg)
{
struct tcm_qla2xxx_nacl *nacl;
nacl = kzalloc(sizeof(struct tcm_qla2xxx_nacl), GFP_KERNEL);
if (!nacl) {
pr_err("Unable to allocate struct tcm_qla2xxx_nacl\n");
return NULL;
}
return &nacl->se_node_acl;
}
static void tcm_qla2xxx_release_fabric_acl(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl)
{
struct tcm_qla2xxx_nacl *nacl = container_of(se_nacl,
struct tcm_qla2xxx_nacl, se_node_acl);
kfree(nacl);
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
transport_generic_free_cmd(&cmd->se_cmd, 0);
}
static void tcm_qla2xxx_free_cmd(struct qla_tgt_cmd *cmd)
{
INIT_WORK(&cmd->work, tcm_qla2xxx_complete_free);
queue_work(tcm_qla2xxx_free_wq, &cmd->work);
}
static int tcm_qla2xxx_check_stop_free(struct se_cmd *se_cmd)
{
return target_put_sess_cmd(se_cmd->se_sess, se_cmd);
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
static int tcm_qla2xxx_shutdown_session(struct se_session *se_sess)
{
struct qla_tgt_sess *sess = se_sess->fabric_sess_ptr;
struct scsi_qla_host *vha;
unsigned long flags;
BUG_ON(!sess);
vha = sess->vha;
spin_lock_irqsave(&vha->hw->hardware_lock, flags);
target_sess_cmd_list_set_waiting(se_sess);
spin_unlock_irqrestore(&vha->hw->hardware_lock, flags);
return 1;
}
static void tcm_qla2xxx_close_session(struct se_session *se_sess)
{
struct qla_tgt_sess *sess = se_sess->fabric_sess_ptr;
struct scsi_qla_host *vha;
unsigned long flags;
BUG_ON(!sess);
vha = sess->vha;
spin_lock_irqsave(&vha->hw->hardware_lock, flags);
qlt_unreg_sess(sess);
spin_unlock_irqrestore(&vha->hw->hardware_lock, flags);
}
static u32 tcm_qla2xxx_sess_get_index(struct se_session *se_sess)
{
return 0;
}
static int tcm_qla2xxx_write_pending(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
cmd->bufflen = se_cmd->data_length;
cmd->dma_data_direction = target_reverse_dma_direction(se_cmd);
cmd->sg_cnt = se_cmd->t_data_nents;
cmd->sg = se_cmd->t_data_sg;
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
3000);
return 0;
}
spin_unlock_irqrestore(&se_cmd->t_state_lock, flags);
return 0;
}
static void tcm_qla2xxx_set_default_node_attrs(struct se_node_acl *nacl)
{
return;
}
static u32 tcm_qla2xxx_get_task_tag(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
return cmd->tag;
}
static int tcm_qla2xxx_get_cmd_state(struct se_cmd *se_cmd)
{
return 0;
}
static int tcm_qla2xxx_handle_cmd(scsi_qla_host_t *vha, struct qla_tgt_cmd *cmd,
unsigned char *cdb, uint32_t data_length, int fcp_task_attr,
int data_dir, int bidi)
{
struct se_cmd *se_cmd = &cmd->se_cmd;
struct se_session *se_sess;
struct qla_tgt_sess *sess;
int flags = TARGET_SCF_ACK_KREF;
if (bidi)
flags |= TARGET_SCF_BIDI_OP;
sess = cmd->sess;
if (!sess) {
pr_err("Unable to locate struct qla_tgt_sess from qla_tgt_cmd\n");
return -EINVAL;
}
se_sess = sess->se_sess;
if (!se_sess) {
pr_err("Unable to locate active struct se_session\n");
return -EINVAL;
}
return target_submit_cmd(se_cmd, se_sess, cdb, &cmd->sense_buffer[0],
cmd->unpacked_lun, data_length, fcp_task_attr,
data_dir, flags);
}
static void tcm_qla2xxx_handle_data_work(struct work_struct *work)
{
struct qla_tgt_cmd *cmd = container_of(work, struct qla_tgt_cmd, work);
if (!cmd->write_data_transferred) {
if (cmd->se_cmd.transport_state & CMD_T_ABORTED) {
complete(&cmd->se_cmd.t_transport_stop_comp);
return;
}
transport_generic_request_failure(&cmd->se_cmd,
TCM_CHECK_CONDITION_ABORT_CMD);
return;
}
return target_execute_cmd(&cmd->se_cmd);
}
static void tcm_qla2xxx_handle_data(struct qla_tgt_cmd *cmd)
{
INIT_WORK(&cmd->work, tcm_qla2xxx_handle_data_work);
queue_work(tcm_qla2xxx_free_wq, &cmd->work);
}
static int tcm_qla2xxx_handle_tmr(struct qla_tgt_mgmt_cmd *mcmd, uint32_t lun,
uint8_t tmr_func, uint32_t tag)
{
struct qla_tgt_sess *sess = mcmd->sess;
struct se_cmd *se_cmd = &mcmd->se_cmd;
return target_submit_tmr(se_cmd, sess->se_sess, NULL, lun, mcmd,
tmr_func, GFP_ATOMIC, tag, TARGET_SCF_ACK_KREF);
}
static int tcm_qla2xxx_queue_data_in(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
cmd->bufflen = se_cmd->data_length;
cmd->dma_data_direction = target_reverse_dma_direction(se_cmd);
cmd->aborted = (se_cmd->transport_state & CMD_T_ABORTED);
cmd->sg_cnt = se_cmd->t_data_nents;
cmd->sg = se_cmd->t_data_sg;
cmd->offset = 0;
return qlt_xmit_response(cmd, QLA_TGT_XMIT_DATA|QLA_TGT_XMIT_STATUS,
se_cmd->scsi_status);
}
static int tcm_qla2xxx_queue_status(struct se_cmd *se_cmd)
{
struct qla_tgt_cmd *cmd = container_of(se_cmd,
struct qla_tgt_cmd, se_cmd);
int xmit_type = QLA_TGT_XMIT_STATUS;
cmd->bufflen = se_cmd->data_length;
cmd->sg = NULL;
cmd->sg_cnt = 0;
cmd->offset = 0;
cmd->dma_data_direction = target_reverse_dma_direction(se_cmd);
cmd->aborted = (se_cmd->transport_state & CMD_T_ABORTED);
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
struct scsi_qla_host *vha = cmd->vha;
struct qla_hw_data *ha = vha->hw;
if (!cmd->sg_mapped)
return;
pci_unmap_sg(ha->pdev, cmd->sg, cmd->sg_cnt, cmd->dma_data_direction);
cmd->sg_mapped = 0;
}
static void tcm_qla2xxx_clear_nacl_from_fcport_map(struct qla_tgt_sess *sess)
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
WARN_ON(node && (node != se_nacl));
pr_debug("Removed from fcport_map: %p for WWNN: 0x%016LX, port_id: 0x%06x\n",
se_nacl, nacl->nport_wwnn, nacl->nport_id);
tcm_qla2xxx_clear_sess_lookup(lport, nacl, sess);
}
static void tcm_qla2xxx_release_session(struct kref *kref)
{
struct se_session *se_sess = container_of(kref,
struct se_session, sess_kref);
qlt_unreg_sess(se_sess->fabric_sess_ptr);
}
static void tcm_qla2xxx_put_session(struct se_session *se_sess)
{
struct qla_tgt_sess *sess = se_sess->fabric_sess_ptr;
struct qla_hw_data *ha = sess->vha->hw;
unsigned long flags;
spin_lock_irqsave(&ha->hardware_lock, flags);
kref_put(&se_sess->sess_kref, tcm_qla2xxx_release_session);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
}
static void tcm_qla2xxx_put_sess(struct qla_tgt_sess *sess)
{
if (!sess)
return;
assert_spin_locked(&sess->vha->hw->hardware_lock);
kref_put(&sess->se_sess->sess_kref, tcm_qla2xxx_release_session);
}
static void tcm_qla2xxx_shutdown_sess(struct qla_tgt_sess *sess)
{
assert_spin_locked(&sess->vha->hw->hardware_lock);
target_sess_cmd_list_set_waiting(sess->se_sess);
}
static struct se_node_acl *tcm_qla2xxx_make_nodeacl(
struct se_portal_group *se_tpg,
struct config_group *group,
const char *name)
{
struct se_node_acl *se_nacl, *se_nacl_new;
struct tcm_qla2xxx_nacl *nacl;
u64 wwnn;
u32 qla2xxx_nexus_depth;
if (tcm_qla2xxx_parse_wwn(name, &wwnn, 1) < 0)
return ERR_PTR(-EINVAL);
se_nacl_new = tcm_qla2xxx_alloc_fabric_acl(se_tpg);
if (!se_nacl_new)
return ERR_PTR(-ENOMEM);
qla2xxx_nexus_depth = 1;
se_nacl = core_tpg_add_initiator_node_acl(se_tpg, se_nacl_new,
name, qla2xxx_nexus_depth);
if (IS_ERR(se_nacl)) {
tcm_qla2xxx_release_fabric_acl(se_tpg, se_nacl_new);
return se_nacl;
}
nacl = container_of(se_nacl, struct tcm_qla2xxx_nacl, se_node_acl);
nacl->nport_wwnn = wwnn;
tcm_qla2xxx_format_wwn(&nacl->nport_name[0], TCM_QLA2XXX_NAMELEN, wwnn);
return se_nacl;
}
static void tcm_qla2xxx_drop_nodeacl(struct se_node_acl *se_acl)
{
struct se_portal_group *se_tpg = se_acl->se_tpg;
struct tcm_qla2xxx_nacl *nacl = container_of(se_acl,
struct tcm_qla2xxx_nacl, se_node_acl);
core_tpg_del_initiator_node_acl(se_tpg, se_acl, 1);
kfree(nacl);
}
static ssize_t tcm_qla2xxx_tpg_show_enable(
struct se_portal_group *se_tpg,
char *page)
{
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
if (!configfs_depend_item(se_tpg->se_tpg_tfo->tf_subsys,
&se_tpg->tpg_group.cg_item)) {
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
configfs_undepend_item(se_tpg->se_tpg_tfo->tf_subsys,
&se_tpg->tpg_group.cg_item);
}
complete(&base_tpg->tpg_base_comp);
}
static ssize_t tcm_qla2xxx_tpg_store_enable(
struct se_portal_group *se_tpg,
const char *page,
size_t count)
{
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
ret = core_tpg_register(&tcm_qla2xxx_fabric_configfs->tf_ops, wwn,
&tpg->se_tpg, tpg, TRANSPORT_TPG_TYPE_NORMAL);
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
static ssize_t tcm_qla2xxx_npiv_tpg_show_enable(
struct se_portal_group *se_tpg,
char *page)
{
return tcm_qla2xxx_tpg_show_enable(se_tpg, page);
}
static ssize_t tcm_qla2xxx_npiv_tpg_store_enable(
struct se_portal_group *se_tpg,
const char *page,
size_t count)
{
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
ret = core_tpg_register(&tcm_qla2xxx_npiv_fabric_configfs->tf_ops, wwn,
&tpg->se_tpg, tpg, TRANSPORT_TPG_TYPE_NORMAL);
if (ret < 0) {
kfree(tpg);
return NULL;
}
lport->tpg_1 = tpg;
return &tpg->se_tpg;
}
static struct qla_tgt_sess *tcm_qla2xxx_find_sess_by_s_id(
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
key = (((unsigned long)s_id[0] << 16) |
((unsigned long)s_id[1] << 8) |
(unsigned long)s_id[2]);
pr_debug("find_sess_by_s_id: 0x%06x\n", key);
se_nacl = btree_lookup32(&lport->lport_fcport_map, key);
if (!se_nacl) {
pr_debug("Unable to locate s_id: 0x%06x\n", key);
return NULL;
}
pr_debug("find_sess_by_s_id: located se_nacl: %p, initiatorname: %s\n",
se_nacl, se_nacl->initiatorname);
nacl = container_of(se_nacl, struct tcm_qla2xxx_nacl, se_node_acl);
if (!nacl->qla_tgt_sess) {
pr_err("Unable to locate struct qla_tgt_sess\n");
return NULL;
}
return nacl->qla_tgt_sess;
}
static void tcm_qla2xxx_set_sess_by_s_id(
struct tcm_qla2xxx_lport *lport,
struct se_node_acl *new_se_nacl,
struct tcm_qla2xxx_nacl *nacl,
struct se_session *se_sess,
struct qla_tgt_sess *qla_tgt_sess,
uint8_t *s_id)
{
u32 key;
void *slot;
int rc;
key = (((unsigned long)s_id[0] << 16) |
((unsigned long)s_id[1] << 8) |
(unsigned long)s_id[2]);
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
qla_tgt_sess->se_sess = se_sess;
nacl->qla_tgt_sess = qla_tgt_sess;
return;
}
if (nacl->qla_tgt_sess) {
if (new_se_nacl == NULL) {
pr_debug("Clearing existing nacl->qla_tgt_sess and fc_port entry\n");
btree_remove32(&lport->lport_fcport_map, key);
nacl->qla_tgt_sess = NULL;
return;
}
pr_debug("Replacing existing nacl->qla_tgt_sess and fc_port entry\n");
btree_update32(&lport->lport_fcport_map, key, new_se_nacl);
qla_tgt_sess->se_sess = se_sess;
nacl->qla_tgt_sess = qla_tgt_sess;
return;
}
if (new_se_nacl == NULL) {
pr_debug("Clearing existing fc_port entry\n");
btree_remove32(&lport->lport_fcport_map, key);
return;
}
pr_debug("Replacing existing fc_port entry w/o active nacl->qla_tgt_sess\n");
btree_update32(&lport->lport_fcport_map, key, new_se_nacl);
qla_tgt_sess->se_sess = se_sess;
nacl->qla_tgt_sess = qla_tgt_sess;
pr_debug("Setup nacl->qla_tgt_sess %p by s_id for se_nacl: %p, initiatorname: %s\n",
nacl->qla_tgt_sess, new_se_nacl, new_se_nacl->initiatorname);
}
static struct qla_tgt_sess *tcm_qla2xxx_find_sess_by_loop_id(
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
if (!nacl->qla_tgt_sess) {
pr_err("Unable to locate struct qla_tgt_sess\n");
return NULL;
}
return nacl->qla_tgt_sess;
}
static void tcm_qla2xxx_set_sess_by_loop_id(
struct tcm_qla2xxx_lport *lport,
struct se_node_acl *new_se_nacl,
struct tcm_qla2xxx_nacl *nacl,
struct se_session *se_sess,
struct qla_tgt_sess *qla_tgt_sess,
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
if (qla_tgt_sess->se_sess != se_sess)
qla_tgt_sess->se_sess = se_sess;
if (nacl->qla_tgt_sess != qla_tgt_sess)
nacl->qla_tgt_sess = qla_tgt_sess;
return;
}
if (nacl->qla_tgt_sess) {
if (new_se_nacl == NULL) {
pr_debug("Clearing nacl->qla_tgt_sess and fc_loopid->se_nacl\n");
fc_loopid->se_nacl = NULL;
nacl->qla_tgt_sess = NULL;
return;
}
pr_debug("Replacing existing nacl->qla_tgt_sess and fc_loopid->se_nacl\n");
fc_loopid->se_nacl = new_se_nacl;
if (qla_tgt_sess->se_sess != se_sess)
qla_tgt_sess->se_sess = se_sess;
if (nacl->qla_tgt_sess != qla_tgt_sess)
nacl->qla_tgt_sess = qla_tgt_sess;
return;
}
if (new_se_nacl == NULL) {
pr_debug("Clearing fc_loopid->se_nacl\n");
fc_loopid->se_nacl = NULL;
return;
}
pr_debug("Replacing existing fc_loopid->se_nacl w/o active nacl->qla_tgt_sess\n");
fc_loopid->se_nacl = new_se_nacl;
if (qla_tgt_sess->se_sess != se_sess)
qla_tgt_sess->se_sess = se_sess;
if (nacl->qla_tgt_sess != qla_tgt_sess)
nacl->qla_tgt_sess = qla_tgt_sess;
pr_debug("Setup nacl->qla_tgt_sess %p by loop_id for se_nacl: %p, initiatorname: %s\n",
nacl->qla_tgt_sess, new_se_nacl, new_se_nacl->initiatorname);
}
static void tcm_qla2xxx_clear_sess_lookup(struct tcm_qla2xxx_lport *lport,
struct tcm_qla2xxx_nacl *nacl, struct qla_tgt_sess *sess)
{
struct se_session *se_sess = sess->se_sess;
unsigned char be_sid[3];
be_sid[0] = sess->s_id.b.domain;
be_sid[1] = sess->s_id.b.area;
be_sid[2] = sess->s_id.b.al_pa;
tcm_qla2xxx_set_sess_by_s_id(lport, NULL, nacl, se_sess,
sess, be_sid);
tcm_qla2xxx_set_sess_by_loop_id(lport, NULL, nacl, se_sess,
sess, sess->loop_id);
}
static void tcm_qla2xxx_free_session(struct qla_tgt_sess *sess)
{
struct qla_tgt *tgt = sess->tgt;
struct qla_hw_data *ha = tgt->ha;
scsi_qla_host_t *vha = pci_get_drvdata(ha->pdev);
struct se_session *se_sess;
struct se_node_acl *se_nacl;
struct tcm_qla2xxx_lport *lport;
struct tcm_qla2xxx_nacl *nacl;
BUG_ON(in_interrupt());
se_sess = sess->se_sess;
if (!se_sess) {
pr_err("struct qla_tgt_sess->se_sess is NULL\n");
dump_stack();
return;
}
se_nacl = se_sess->se_node_acl;
nacl = container_of(se_nacl, struct tcm_qla2xxx_nacl, se_node_acl);
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
static int tcm_qla2xxx_check_initiator_node_acl(
scsi_qla_host_t *vha,
unsigned char *fc_wwpn,
void *qla_tgt_sess,
uint8_t *s_id,
uint16_t loop_id)
{
struct qla_hw_data *ha = vha->hw;
struct tcm_qla2xxx_lport *lport;
struct tcm_qla2xxx_tpg *tpg;
struct tcm_qla2xxx_nacl *nacl;
struct se_portal_group *se_tpg;
struct se_node_acl *se_nacl;
struct se_session *se_sess;
struct qla_tgt_sess *sess = qla_tgt_sess;
unsigned char port_name[36];
unsigned long flags;
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
se_tpg = &tpg->se_tpg;
se_sess = transport_init_session(TARGET_PROT_NORMAL);
if (IS_ERR(se_sess)) {
pr_err("Unable to initialize struct se_session\n");
return PTR_ERR(se_sess);
}
memset(&port_name, 0, 36);
snprintf(port_name, 36, "%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x",
fc_wwpn[0], fc_wwpn[1], fc_wwpn[2], fc_wwpn[3], fc_wwpn[4],
fc_wwpn[5], fc_wwpn[6], fc_wwpn[7]);
se_sess->se_node_acl = core_tpg_check_initiator_node_acl(se_tpg,
port_name);
if (!se_sess->se_node_acl) {
transport_free_session(se_sess);
return -EINVAL;
}
se_nacl = se_sess->se_node_acl;
nacl = container_of(se_nacl, struct tcm_qla2xxx_nacl, se_node_acl);
spin_lock_irqsave(&ha->hardware_lock, flags);
tcm_qla2xxx_set_sess_by_s_id(lport, se_nacl, nacl, se_sess,
qla_tgt_sess, s_id);
tcm_qla2xxx_set_sess_by_loop_id(lport, se_nacl, nacl, se_sess,
qla_tgt_sess, loop_id);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
__transport_register_session(se_nacl->se_tpg, se_nacl, se_sess, sess);
return 0;
}
static void tcm_qla2xxx_update_sess(struct qla_tgt_sess *sess, port_id_t s_id,
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
if (sess->loop_id != loop_id || sess->s_id.b24 != s_id.b24)
pr_info("Updating session %p from port %8phC loop_id %d -> %d s_id %x:%x:%x -> %x:%x:%x\n",
sess, sess->port_name,
sess->loop_id, loop_id, sess->s_id.b.domain,
sess->s_id.b.area, sess->s_id.b.al_pa, s_id.b.domain,
s_id.b.area, s_id.b.al_pa);
if (sess->loop_id != loop_id) {
if (lport->lport_loopid_map[sess->loop_id].se_nacl == se_nacl)
lport->lport_loopid_map[sess->loop_id].se_nacl = NULL;
lport->lport_loopid_map[loop_id].se_nacl = se_nacl;
sess->loop_id = loop_id;
}
if (sess->s_id.b24 != s_id.b24) {
key = (((u32) sess->s_id.b.domain << 16) |
((u32) sess->s_id.b.area << 8) |
((u32) sess->s_id.b.al_pa));
if (btree_lookup32(&lport->lport_fcport_map, key))
WARN(btree_remove32(&lport->lport_fcport_map, key) != se_nacl,
"Found wrong se_nacl when updating s_id %x:%x:%x\n",
sess->s_id.b.domain, sess->s_id.b.area, sess->s_id.b.al_pa);
else
WARN(1, "No lport_fcport_map entry for s_id %x:%x:%x\n",
sess->s_id.b.domain, sess->s_id.b.area, sess->s_id.b.al_pa);
key = (((u32) s_id.b.domain << 16) |
((u32) s_id.b.area << 8) |
((u32) s_id.b.al_pa));
if (btree_lookup32(&lport->lport_fcport_map, key)) {
WARN(1, "Already have lport_fcport_map entry for s_id %x:%x:%x\n",
s_id.b.domain, s_id.b.area, s_id.b.al_pa);
btree_update32(&lport->lport_fcport_map, key, se_nacl);
} else {
btree_insert32(&lport->lport_fcport_map, key, se_nacl, GFP_ATOMIC);
}
sess->s_id = s_id;
nacl->nport_id = key;
}
sess->conf_compl_supported = conf_compl_supported;
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
struct tcm_qla2xxx_tpg *base_tpg;
struct fc_vport_identifiers vport_id;
if (!qla_tgt_mode_enabled(base_vha)) {
pr_err("qla2xxx base_vha not enabled for target mode\n");
return -EPERM;
}
if (!base_lport || !base_lport->tpg_1 ||
!atomic_read(&base_lport->tpg_1->lport_tpg_enabled)) {
pr_err("qla2xxx base_lport or tpg_1 not available\n");
return -EPERM;
}
base_tpg = base_lport->tpg_1;
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
pr_err("Unable to locate NPIV '@' seperator\n");
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
static ssize_t tcm_qla2xxx_wwn_show_attr_version(
struct target_fabric_configfs *tf,
char *page)
{
return sprintf(page,
"TCM QLOGIC QLA2XXX NPIV capable fabric module %s on %s/%s on "
UTS_RELEASE"\n", TCM_QLA2XXX_VERSION, utsname()->sysname,
utsname()->machine);
}
static int tcm_qla2xxx_register_configfs(void)
{
struct target_fabric_configfs *fabric, *npiv_fabric;
int ret;
pr_debug("TCM QLOGIC QLA2XXX fabric module %s on %s/%s on "
UTS_RELEASE"\n", TCM_QLA2XXX_VERSION, utsname()->sysname,
utsname()->machine);
fabric = target_fabric_configfs_init(THIS_MODULE, "qla2xxx");
if (IS_ERR(fabric)) {
pr_err("target_fabric_configfs_init() failed\n");
return PTR_ERR(fabric);
}
fabric->tf_ops = tcm_qla2xxx_ops;
fabric->tf_cit_tmpl.tfc_wwn_cit.ct_attrs = tcm_qla2xxx_wwn_attrs;
fabric->tf_cit_tmpl.tfc_tpg_base_cit.ct_attrs = tcm_qla2xxx_tpg_attrs;
fabric->tf_cit_tmpl.tfc_tpg_attrib_cit.ct_attrs =
tcm_qla2xxx_tpg_attrib_attrs;
fabric->tf_cit_tmpl.tfc_tpg_param_cit.ct_attrs = NULL;
fabric->tf_cit_tmpl.tfc_tpg_np_base_cit.ct_attrs = NULL;
fabric->tf_cit_tmpl.tfc_tpg_nacl_base_cit.ct_attrs = NULL;
fabric->tf_cit_tmpl.tfc_tpg_nacl_attrib_cit.ct_attrs = NULL;
fabric->tf_cit_tmpl.tfc_tpg_nacl_auth_cit.ct_attrs = NULL;
fabric->tf_cit_tmpl.tfc_tpg_nacl_param_cit.ct_attrs = NULL;
ret = target_fabric_configfs_register(fabric);
if (ret < 0) {
pr_err("target_fabric_configfs_register() failed for TCM_QLA2XXX\n");
return ret;
}
tcm_qla2xxx_fabric_configfs = fabric;
pr_debug("TCM_QLA2XXX[0] - Set fabric -> tcm_qla2xxx_fabric_configfs\n");
npiv_fabric = target_fabric_configfs_init(THIS_MODULE, "qla2xxx_npiv");
if (IS_ERR(npiv_fabric)) {
pr_err("target_fabric_configfs_init() failed\n");
ret = PTR_ERR(npiv_fabric);
goto out_fabric;
}
npiv_fabric->tf_ops = tcm_qla2xxx_npiv_ops;
npiv_fabric->tf_cit_tmpl.tfc_wwn_cit.ct_attrs = tcm_qla2xxx_wwn_attrs;
npiv_fabric->tf_cit_tmpl.tfc_tpg_base_cit.ct_attrs =
tcm_qla2xxx_npiv_tpg_attrs;
npiv_fabric->tf_cit_tmpl.tfc_tpg_attrib_cit.ct_attrs = NULL;
npiv_fabric->tf_cit_tmpl.tfc_tpg_param_cit.ct_attrs = NULL;
npiv_fabric->tf_cit_tmpl.tfc_tpg_np_base_cit.ct_attrs = NULL;
npiv_fabric->tf_cit_tmpl.tfc_tpg_nacl_base_cit.ct_attrs = NULL;
npiv_fabric->tf_cit_tmpl.tfc_tpg_nacl_attrib_cit.ct_attrs = NULL;
npiv_fabric->tf_cit_tmpl.tfc_tpg_nacl_auth_cit.ct_attrs = NULL;
npiv_fabric->tf_cit_tmpl.tfc_tpg_nacl_param_cit.ct_attrs = NULL;
ret = target_fabric_configfs_register(npiv_fabric);
if (ret < 0) {
pr_err("target_fabric_configfs_register() failed for TCM_QLA2XXX\n");
goto out_fabric;
}
tcm_qla2xxx_npiv_fabric_configfs = npiv_fabric;
pr_debug("TCM_QLA2XXX[0] - Set fabric -> tcm_qla2xxx_npiv_fabric_configfs\n");
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
target_fabric_configfs_deregister(tcm_qla2xxx_npiv_fabric_configfs);
out_fabric:
target_fabric_configfs_deregister(tcm_qla2xxx_fabric_configfs);
return ret;
}
static void tcm_qla2xxx_deregister_configfs(void)
{
destroy_workqueue(tcm_qla2xxx_cmd_wq);
destroy_workqueue(tcm_qla2xxx_free_wq);
target_fabric_configfs_deregister(tcm_qla2xxx_fabric_configfs);
tcm_qla2xxx_fabric_configfs = NULL;
pr_debug("TCM_QLA2XXX[0] - Cleared tcm_qla2xxx_fabric_configfs\n");
target_fabric_configfs_deregister(tcm_qla2xxx_npiv_fabric_configfs);
tcm_qla2xxx_npiv_fabric_configfs = NULL;
pr_debug("TCM_QLA2XXX[0] - Cleared tcm_qla2xxx_npiv_fabric_configfs\n");
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
