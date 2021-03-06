int init_se_kmem_caches(void)
{
se_sess_cache = kmem_cache_create("se_sess_cache",
sizeof(struct se_session), __alignof__(struct se_session),
0, NULL);
if (!se_sess_cache) {
pr_err("kmem_cache_create() for struct se_session"
" failed\n");
goto out;
}
se_ua_cache = kmem_cache_create("se_ua_cache",
sizeof(struct se_ua), __alignof__(struct se_ua),
0, NULL);
if (!se_ua_cache) {
pr_err("kmem_cache_create() for struct se_ua failed\n");
goto out_free_sess_cache;
}
t10_pr_reg_cache = kmem_cache_create("t10_pr_reg_cache",
sizeof(struct t10_pr_registration),
__alignof__(struct t10_pr_registration), 0, NULL);
if (!t10_pr_reg_cache) {
pr_err("kmem_cache_create() for struct t10_pr_registration"
" failed\n");
goto out_free_ua_cache;
}
t10_alua_lu_gp_cache = kmem_cache_create("t10_alua_lu_gp_cache",
sizeof(struct t10_alua_lu_gp), __alignof__(struct t10_alua_lu_gp),
0, NULL);
if (!t10_alua_lu_gp_cache) {
pr_err("kmem_cache_create() for t10_alua_lu_gp_cache"
" failed\n");
goto out_free_pr_reg_cache;
}
t10_alua_lu_gp_mem_cache = kmem_cache_create("t10_alua_lu_gp_mem_cache",
sizeof(struct t10_alua_lu_gp_member),
__alignof__(struct t10_alua_lu_gp_member), 0, NULL);
if (!t10_alua_lu_gp_mem_cache) {
pr_err("kmem_cache_create() for t10_alua_lu_gp_mem_"
"cache failed\n");
goto out_free_lu_gp_cache;
}
t10_alua_tg_pt_gp_cache = kmem_cache_create("t10_alua_tg_pt_gp_cache",
sizeof(struct t10_alua_tg_pt_gp),
__alignof__(struct t10_alua_tg_pt_gp), 0, NULL);
if (!t10_alua_tg_pt_gp_cache) {
pr_err("kmem_cache_create() for t10_alua_tg_pt_gp_"
"cache failed\n");
goto out_free_lu_gp_mem_cache;
}
t10_alua_tg_pt_gp_mem_cache = kmem_cache_create(
"t10_alua_tg_pt_gp_mem_cache",
sizeof(struct t10_alua_tg_pt_gp_member),
__alignof__(struct t10_alua_tg_pt_gp_member),
0, NULL);
if (!t10_alua_tg_pt_gp_mem_cache) {
pr_err("kmem_cache_create() for t10_alua_tg_pt_gp_"
"mem_t failed\n");
goto out_free_tg_pt_gp_cache;
}
target_completion_wq = alloc_workqueue("target_completion",
WQ_MEM_RECLAIM, 0);
if (!target_completion_wq)
goto out_free_tg_pt_gp_mem_cache;
return 0;
out_free_tg_pt_gp_mem_cache:
kmem_cache_destroy(t10_alua_tg_pt_gp_mem_cache);
out_free_tg_pt_gp_cache:
kmem_cache_destroy(t10_alua_tg_pt_gp_cache);
out_free_lu_gp_mem_cache:
kmem_cache_destroy(t10_alua_lu_gp_mem_cache);
out_free_lu_gp_cache:
kmem_cache_destroy(t10_alua_lu_gp_cache);
out_free_pr_reg_cache:
kmem_cache_destroy(t10_pr_reg_cache);
out_free_ua_cache:
kmem_cache_destroy(se_ua_cache);
out_free_sess_cache:
kmem_cache_destroy(se_sess_cache);
out:
return -ENOMEM;
}
void release_se_kmem_caches(void)
{
destroy_workqueue(target_completion_wq);
kmem_cache_destroy(se_sess_cache);
kmem_cache_destroy(se_ua_cache);
kmem_cache_destroy(t10_pr_reg_cache);
kmem_cache_destroy(t10_alua_lu_gp_cache);
kmem_cache_destroy(t10_alua_lu_gp_mem_cache);
kmem_cache_destroy(t10_alua_tg_pt_gp_cache);
kmem_cache_destroy(t10_alua_tg_pt_gp_mem_cache);
}
u32 scsi_get_new_index(scsi_index_t type)
{
u32 new_index;
BUG_ON((type < 0) || (type >= SCSI_INDEX_TYPE_MAX));
spin_lock(&scsi_mib_index_lock);
new_index = ++scsi_mib_index[type];
spin_unlock(&scsi_mib_index_lock);
return new_index;
}
void transport_subsystem_check_init(void)
{
int ret;
static int sub_api_initialized;
if (sub_api_initialized)
return;
ret = request_module("target_core_iblock");
if (ret != 0)
pr_err("Unable to load target_core_iblock\n");
ret = request_module("target_core_file");
if (ret != 0)
pr_err("Unable to load target_core_file\n");
ret = request_module("target_core_pscsi");
if (ret != 0)
pr_err("Unable to load target_core_pscsi\n");
sub_api_initialized = 1;
}
struct se_session *transport_init_session(void)
{
struct se_session *se_sess;
se_sess = kmem_cache_zalloc(se_sess_cache, GFP_KERNEL);
if (!se_sess) {
pr_err("Unable to allocate struct se_session from"
" se_sess_cache\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&se_sess->sess_list);
INIT_LIST_HEAD(&se_sess->sess_acl_list);
INIT_LIST_HEAD(&se_sess->sess_cmd_list);
spin_lock_init(&se_sess->sess_cmd_lock);
kref_init(&se_sess->sess_kref);
return se_sess;
}
void __transport_register_session(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl,
struct se_session *se_sess,
void *fabric_sess_ptr)
{
unsigned char buf[PR_REG_ISID_LEN];
se_sess->se_tpg = se_tpg;
se_sess->fabric_sess_ptr = fabric_sess_ptr;
if (se_nacl) {
if (se_tpg->se_tpg_tfo->sess_get_initiator_sid != NULL) {
memset(&buf[0], 0, PR_REG_ISID_LEN);
se_tpg->se_tpg_tfo->sess_get_initiator_sid(se_sess,
&buf[0], PR_REG_ISID_LEN);
se_sess->sess_bin_isid = get_unaligned_be64(&buf[0]);
}
kref_get(&se_nacl->acl_kref);
spin_lock_irq(&se_nacl->nacl_sess_lock);
se_nacl->nacl_sess = se_sess;
list_add_tail(&se_sess->sess_acl_list,
&se_nacl->acl_sess_list);
spin_unlock_irq(&se_nacl->nacl_sess_lock);
}
list_add_tail(&se_sess->sess_list, &se_tpg->tpg_sess_list);
pr_debug("TARGET_CORE[%s]: Registered fabric_sess_ptr: %p\n",
se_tpg->se_tpg_tfo->get_fabric_name(), se_sess->fabric_sess_ptr);
}
void transport_register_session(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl,
struct se_session *se_sess,
void *fabric_sess_ptr)
{
unsigned long flags;
spin_lock_irqsave(&se_tpg->session_lock, flags);
__transport_register_session(se_tpg, se_nacl, se_sess, fabric_sess_ptr);
spin_unlock_irqrestore(&se_tpg->session_lock, flags);
}
void target_release_session(struct kref *kref)
{
struct se_session *se_sess = container_of(kref,
struct se_session, sess_kref);
struct se_portal_group *se_tpg = se_sess->se_tpg;
se_tpg->se_tpg_tfo->close_session(se_sess);
}
void target_get_session(struct se_session *se_sess)
{
kref_get(&se_sess->sess_kref);
}
void target_put_session(struct se_session *se_sess)
{
struct se_portal_group *tpg = se_sess->se_tpg;
if (tpg->se_tpg_tfo->put_session != NULL) {
tpg->se_tpg_tfo->put_session(se_sess);
return;
}
kref_put(&se_sess->sess_kref, target_release_session);
}
static void target_complete_nacl(struct kref *kref)
{
struct se_node_acl *nacl = container_of(kref,
struct se_node_acl, acl_kref);
complete(&nacl->acl_free_comp);
}
void target_put_nacl(struct se_node_acl *nacl)
{
kref_put(&nacl->acl_kref, target_complete_nacl);
}
void transport_deregister_session_configfs(struct se_session *se_sess)
{
struct se_node_acl *se_nacl;
unsigned long flags;
se_nacl = se_sess->se_node_acl;
if (se_nacl) {
spin_lock_irqsave(&se_nacl->nacl_sess_lock, flags);
if (se_nacl->acl_stop == 0)
list_del(&se_sess->sess_acl_list);
if (list_empty(&se_nacl->acl_sess_list))
se_nacl->nacl_sess = NULL;
else {
se_nacl->nacl_sess = container_of(
se_nacl->acl_sess_list.prev,
struct se_session, sess_acl_list);
}
spin_unlock_irqrestore(&se_nacl->nacl_sess_lock, flags);
}
}
void transport_free_session(struct se_session *se_sess)
{
kmem_cache_free(se_sess_cache, se_sess);
}
void transport_deregister_session(struct se_session *se_sess)
{
struct se_portal_group *se_tpg = se_sess->se_tpg;
struct target_core_fabric_ops *se_tfo;
struct se_node_acl *se_nacl;
unsigned long flags;
bool comp_nacl = true;
if (!se_tpg) {
transport_free_session(se_sess);
return;
}
se_tfo = se_tpg->se_tpg_tfo;
spin_lock_irqsave(&se_tpg->session_lock, flags);
list_del(&se_sess->sess_list);
se_sess->se_tpg = NULL;
se_sess->fabric_sess_ptr = NULL;
spin_unlock_irqrestore(&se_tpg->session_lock, flags);
se_nacl = se_sess->se_node_acl;
spin_lock_irqsave(&se_tpg->acl_node_lock, flags);
if (se_nacl && se_nacl->dynamic_node_acl) {
if (!se_tfo->tpg_check_demo_mode_cache(se_tpg)) {
list_del(&se_nacl->acl_list);
se_tpg->num_node_acls--;
spin_unlock_irqrestore(&se_tpg->acl_node_lock, flags);
core_tpg_wait_for_nacl_pr_ref(se_nacl);
core_free_device_list_for_node(se_nacl, se_tpg);
se_tfo->tpg_release_fabric_acl(se_tpg, se_nacl);
comp_nacl = false;
spin_lock_irqsave(&se_tpg->acl_node_lock, flags);
}
}
spin_unlock_irqrestore(&se_tpg->acl_node_lock, flags);
pr_debug("TARGET_CORE[%s]: Deregistered fabric_sess\n",
se_tpg->se_tpg_tfo->get_fabric_name());
if (se_nacl && comp_nacl == true)
target_put_nacl(se_nacl);
transport_free_session(se_sess);
}
static void target_remove_from_state_list(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned long flags;
if (!dev)
return;
if (cmd->transport_state & CMD_T_BUSY)
return;
spin_lock_irqsave(&dev->execute_task_lock, flags);
if (cmd->state_active) {
list_del(&cmd->state_list);
cmd->state_active = false;
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
}
static int transport_cmd_check_stop(struct se_cmd *cmd, bool remove_from_lists)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (cmd->transport_state & CMD_T_LUN_STOP) {
pr_debug("%s:%d CMD_T_LUN_STOP for ITT: 0x%08x\n",
__func__, __LINE__, cmd->se_tfo->get_task_tag(cmd));
cmd->transport_state &= ~CMD_T_ACTIVE;
if (remove_from_lists)
target_remove_from_state_list(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->transport_lun_stop_comp);
return 1;
}
if (remove_from_lists) {
target_remove_from_state_list(cmd);
cmd->se_lun = NULL;
}
if (cmd->transport_state & CMD_T_STOP) {
pr_debug("%s:%d CMD_T_STOP for ITT: 0x%08x\n",
__func__, __LINE__,
cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->t_transport_stop_comp);
return 1;
}
cmd->transport_state &= ~CMD_T_ACTIVE;
if (remove_from_lists) {
if (cmd->se_tfo->check_stop_free != NULL) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return cmd->se_tfo->check_stop_free(cmd);
}
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return 0;
}
static int transport_cmd_check_stop_to_fabric(struct se_cmd *cmd)
{
return transport_cmd_check_stop(cmd, true);
}
static void transport_lun_remove_cmd(struct se_cmd *cmd)
{
struct se_lun *lun = cmd->se_lun;
unsigned long flags;
if (!lun)
return;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (cmd->transport_state & CMD_T_DEV_ACTIVE) {
cmd->transport_state &= ~CMD_T_DEV_ACTIVE;
target_remove_from_state_list(cmd);
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
spin_lock_irqsave(&lun->lun_cmd_lock, flags);
if (!list_empty(&cmd->se_lun_node))
list_del_init(&cmd->se_lun_node);
spin_unlock_irqrestore(&lun->lun_cmd_lock, flags);
}
void transport_cmd_finish_abort(struct se_cmd *cmd, int remove)
{
if (!(cmd->se_cmd_flags & SCF_SCSI_TMR_CDB))
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop_to_fabric(cmd))
return;
if (remove)
transport_put_cmd(cmd);
}
static void target_complete_failure_work(struct work_struct *work)
{
struct se_cmd *cmd = container_of(work, struct se_cmd, work);
transport_generic_request_failure(cmd);
}
static unsigned char *transport_get_sense_buffer(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
WARN_ON(!cmd->se_lun);
if (!dev)
return NULL;
if (cmd->se_cmd_flags & SCF_SENT_CHECK_CONDITION)
return NULL;
cmd->scsi_sense_length = TRANSPORT_SENSE_BUFFER;
pr_debug("HBA_[%u]_PLUG[%s]: Requesting sense for SAM STATUS: 0x%02x\n",
dev->se_hba->hba_id, dev->transport->name, cmd->scsi_status);
return cmd->sense_buffer;
}
void target_complete_cmd(struct se_cmd *cmd, u8 scsi_status)
{
struct se_device *dev = cmd->se_dev;
int success = scsi_status == GOOD;
unsigned long flags;
cmd->scsi_status = scsi_status;
spin_lock_irqsave(&cmd->t_state_lock, flags);
cmd->transport_state &= ~CMD_T_BUSY;
if (dev && dev->transport->transport_complete) {
dev->transport->transport_complete(cmd,
cmd->t_data_sg,
transport_get_sense_buffer(cmd));
if (cmd->se_cmd_flags & SCF_TRANSPORT_TASK_SENSE)
success = 1;
}
if (cmd->transport_state & CMD_T_REQUEST_STOP) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->task_stop_comp);
return;
}
if (!success)
cmd->transport_state |= CMD_T_FAILED;
if (cmd->transport_state & CMD_T_ABORTED &&
cmd->transport_state & CMD_T_STOP) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->t_transport_stop_comp);
return;
} else if (cmd->transport_state & CMD_T_FAILED) {
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
INIT_WORK(&cmd->work, target_complete_failure_work);
} else {
INIT_WORK(&cmd->work, target_complete_ok_work);
}
cmd->t_state = TRANSPORT_COMPLETE;
cmd->transport_state |= (CMD_T_COMPLETE | CMD_T_ACTIVE);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
queue_work(target_completion_wq, &cmd->work);
}
static void target_add_to_state_list(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned long flags;
spin_lock_irqsave(&dev->execute_task_lock, flags);
if (!cmd->state_active) {
list_add_tail(&cmd->state_list, &dev->state_list);
cmd->state_active = true;
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
}
static void target_qf_do_work(struct work_struct *work)
{
struct se_device *dev = container_of(work, struct se_device,
qf_work_queue);
LIST_HEAD(qf_cmd_list);
struct se_cmd *cmd, *cmd_tmp;
spin_lock_irq(&dev->qf_cmd_lock);
list_splice_init(&dev->qf_cmd_list, &qf_cmd_list);
spin_unlock_irq(&dev->qf_cmd_lock);
list_for_each_entry_safe(cmd, cmd_tmp, &qf_cmd_list, se_qf_node) {
list_del(&cmd->se_qf_node);
atomic_dec(&dev->dev_qf_count);
smp_mb__after_atomic_dec();
pr_debug("Processing %s cmd: %p QUEUE_FULL in work queue"
" context: %s\n", cmd->se_tfo->get_fabric_name(), cmd,
(cmd->t_state == TRANSPORT_COMPLETE_QF_OK) ? "COMPLETE_OK" :
(cmd->t_state == TRANSPORT_COMPLETE_QF_WP) ? "WRITE_PENDING"
: "UNKNOWN");
if (cmd->t_state == TRANSPORT_COMPLETE_QF_WP)
transport_write_pending_qf(cmd);
else if (cmd->t_state == TRANSPORT_COMPLETE_QF_OK)
transport_complete_qf(cmd);
}
}
unsigned char *transport_dump_cmd_direction(struct se_cmd *cmd)
{
switch (cmd->data_direction) {
case DMA_NONE:
return "NONE";
case DMA_FROM_DEVICE:
return "READ";
case DMA_TO_DEVICE:
return "WRITE";
case DMA_BIDIRECTIONAL:
return "BIDI";
default:
break;
}
return "UNKNOWN";
}
void transport_dump_dev_state(
struct se_device *dev,
char *b,
int *bl)
{
*bl += sprintf(b + *bl, "Status: ");
switch (dev->dev_status) {
case TRANSPORT_DEVICE_ACTIVATED:
*bl += sprintf(b + *bl, "ACTIVATED");
break;
case TRANSPORT_DEVICE_DEACTIVATED:
*bl += sprintf(b + *bl, "DEACTIVATED");
break;
case TRANSPORT_DEVICE_SHUTDOWN:
*bl += sprintf(b + *bl, "SHUTDOWN");
break;
case TRANSPORT_DEVICE_OFFLINE_ACTIVATED:
case TRANSPORT_DEVICE_OFFLINE_DEACTIVATED:
*bl += sprintf(b + *bl, "OFFLINE");
break;
default:
*bl += sprintf(b + *bl, "UNKNOWN=%d", dev->dev_status);
break;
}
*bl += sprintf(b + *bl, " Max Queue Depth: %d", dev->queue_depth);
*bl += sprintf(b + *bl, " SectorSize: %u HwMaxSectors: %u\n",
dev->se_sub_dev->se_dev_attrib.block_size,
dev->se_sub_dev->se_dev_attrib.hw_max_sectors);
*bl += sprintf(b + *bl, " ");
}
void transport_dump_vpd_proto_id(
struct t10_vpd *vpd,
unsigned char *p_buf,
int p_buf_len)
{
unsigned char buf[VPD_TMP_BUF_SIZE];
int len;
memset(buf, 0, VPD_TMP_BUF_SIZE);
len = sprintf(buf, "T10 VPD Protocol Identifier: ");
switch (vpd->protocol_identifier) {
case 0x00:
sprintf(buf+len, "Fibre Channel\n");
break;
case 0x10:
sprintf(buf+len, "Parallel SCSI\n");
break;
case 0x20:
sprintf(buf+len, "SSA\n");
break;
case 0x30:
sprintf(buf+len, "IEEE 1394\n");
break;
case 0x40:
sprintf(buf+len, "SCSI Remote Direct Memory Access"
" Protocol\n");
break;
case 0x50:
sprintf(buf+len, "Internet SCSI (iSCSI)\n");
break;
case 0x60:
sprintf(buf+len, "SAS Serial SCSI Protocol\n");
break;
case 0x70:
sprintf(buf+len, "Automation/Drive Interface Transport"
" Protocol\n");
break;
case 0x80:
sprintf(buf+len, "AT Attachment Interface ATA/ATAPI\n");
break;
default:
sprintf(buf+len, "Unknown 0x%02x\n",
vpd->protocol_identifier);
break;
}
if (p_buf)
strncpy(p_buf, buf, p_buf_len);
else
pr_debug("%s", buf);
}
void
transport_set_vpd_proto_id(struct t10_vpd *vpd, unsigned char *page_83)
{
if (page_83[1] & 0x80) {
vpd->protocol_identifier = (page_83[0] & 0xf0);
vpd->protocol_identifier_set = 1;
transport_dump_vpd_proto_id(vpd, NULL, 0);
}
}
int transport_dump_vpd_assoc(
struct t10_vpd *vpd,
unsigned char *p_buf,
int p_buf_len)
{
unsigned char buf[VPD_TMP_BUF_SIZE];
int ret = 0;
int len;
memset(buf, 0, VPD_TMP_BUF_SIZE);
len = sprintf(buf, "T10 VPD Identifier Association: ");
switch (vpd->association) {
case 0x00:
sprintf(buf+len, "addressed logical unit\n");
break;
case 0x10:
sprintf(buf+len, "target port\n");
break;
case 0x20:
sprintf(buf+len, "SCSI target device\n");
break;
default:
sprintf(buf+len, "Unknown 0x%02x\n", vpd->association);
ret = -EINVAL;
break;
}
if (p_buf)
strncpy(p_buf, buf, p_buf_len);
else
pr_debug("%s", buf);
return ret;
}
int transport_set_vpd_assoc(struct t10_vpd *vpd, unsigned char *page_83)
{
vpd->association = (page_83[1] & 0x30);
return transport_dump_vpd_assoc(vpd, NULL, 0);
}
int transport_dump_vpd_ident_type(
struct t10_vpd *vpd,
unsigned char *p_buf,
int p_buf_len)
{
unsigned char buf[VPD_TMP_BUF_SIZE];
int ret = 0;
int len;
memset(buf, 0, VPD_TMP_BUF_SIZE);
len = sprintf(buf, "T10 VPD Identifier Type: ");
switch (vpd->device_identifier_type) {
case 0x00:
sprintf(buf+len, "Vendor specific\n");
break;
case 0x01:
sprintf(buf+len, "T10 Vendor ID based\n");
break;
case 0x02:
sprintf(buf+len, "EUI-64 based\n");
break;
case 0x03:
sprintf(buf+len, "NAA\n");
break;
case 0x04:
sprintf(buf+len, "Relative target port identifier\n");
break;
case 0x08:
sprintf(buf+len, "SCSI name string\n");
break;
default:
sprintf(buf+len, "Unsupported: 0x%02x\n",
vpd->device_identifier_type);
ret = -EINVAL;
break;
}
if (p_buf) {
if (p_buf_len < strlen(buf)+1)
return -EINVAL;
strncpy(p_buf, buf, p_buf_len);
} else {
pr_debug("%s", buf);
}
return ret;
}
int transport_set_vpd_ident_type(struct t10_vpd *vpd, unsigned char *page_83)
{
vpd->device_identifier_type = (page_83[1] & 0x0f);
return transport_dump_vpd_ident_type(vpd, NULL, 0);
}
int transport_dump_vpd_ident(
struct t10_vpd *vpd,
unsigned char *p_buf,
int p_buf_len)
{
unsigned char buf[VPD_TMP_BUF_SIZE];
int ret = 0;
memset(buf, 0, VPD_TMP_BUF_SIZE);
switch (vpd->device_identifier_code_set) {
case 0x01:
sprintf(buf, "T10 VPD Binary Device Identifier: %s\n",
&vpd->device_identifier[0]);
break;
case 0x02:
sprintf(buf, "T10 VPD ASCII Device Identifier: %s\n",
&vpd->device_identifier[0]);
break;
case 0x03:
sprintf(buf, "T10 VPD UTF-8 Device Identifier: %s\n",
&vpd->device_identifier[0]);
break;
default:
sprintf(buf, "T10 VPD Device Identifier encoding unsupported:"
" 0x%02x", vpd->device_identifier_code_set);
ret = -EINVAL;
break;
}
if (p_buf)
strncpy(p_buf, buf, p_buf_len);
else
pr_debug("%s", buf);
return ret;
}
int
transport_set_vpd_ident(struct t10_vpd *vpd, unsigned char *page_83)
{
static const char hex_str[] = "0123456789abcdef";
int j = 0, i = 4;
vpd->device_identifier_code_set = (page_83[0] & 0x0f);
switch (vpd->device_identifier_code_set) {
case 0x01:
vpd->device_identifier[j++] =
hex_str[vpd->device_identifier_type];
while (i < (4 + page_83[3])) {
vpd->device_identifier[j++] =
hex_str[(page_83[i] & 0xf0) >> 4];
vpd->device_identifier[j++] =
hex_str[page_83[i] & 0x0f];
i++;
}
break;
case 0x02:
case 0x03:
while (i < (4 + page_83[3]))
vpd->device_identifier[j++] = page_83[i++];
break;
default:
break;
}
return transport_dump_vpd_ident(vpd, NULL, 0);
}
static void core_setup_task_attr_emulation(struct se_device *dev)
{
if (dev->transport->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV) {
dev->dev_task_attr_type = SAM_TASK_ATTR_PASSTHROUGH;
return;
}
dev->dev_task_attr_type = SAM_TASK_ATTR_EMULATED;
pr_debug("%s: Using SAM_TASK_ATTR_EMULATED for SPC: 0x%02x"
" device\n", dev->transport->name,
dev->transport->get_device_rev(dev));
}
static void scsi_dump_inquiry(struct se_device *dev)
{
struct t10_wwn *wwn = &dev->se_sub_dev->t10_wwn;
char buf[17];
int i, device_type;
for (i = 0; i < 8; i++)
if (wwn->vendor[i] >= 0x20)
buf[i] = wwn->vendor[i];
else
buf[i] = ' ';
buf[i] = '\0';
pr_debug(" Vendor: %s\n", buf);
for (i = 0; i < 16; i++)
if (wwn->model[i] >= 0x20)
buf[i] = wwn->model[i];
else
buf[i] = ' ';
buf[i] = '\0';
pr_debug(" Model: %s\n", buf);
for (i = 0; i < 4; i++)
if (wwn->revision[i] >= 0x20)
buf[i] = wwn->revision[i];
else
buf[i] = ' ';
buf[i] = '\0';
pr_debug(" Revision: %s\n", buf);
device_type = dev->transport->get_device_type(dev);
pr_debug(" Type: %s ", scsi_device_type(device_type));
pr_debug(" ANSI SCSI revision: %02x\n",
dev->transport->get_device_rev(dev));
}
struct se_device *transport_add_device_to_core_hba(
struct se_hba *hba,
struct se_subsystem_api *transport,
struct se_subsystem_dev *se_dev,
u32 device_flags,
void *transport_dev,
struct se_dev_limits *dev_limits,
const char *inquiry_prod,
const char *inquiry_rev)
{
int force_pt;
struct se_device *dev;
dev = kzalloc(sizeof(struct se_device), GFP_KERNEL);
if (!dev) {
pr_err("Unable to allocate memory for se_dev_t\n");
return NULL;
}
dev->dev_flags = device_flags;
dev->dev_status |= TRANSPORT_DEVICE_DEACTIVATED;
dev->dev_ptr = transport_dev;
dev->se_hba = hba;
dev->se_sub_dev = se_dev;
dev->transport = transport;
INIT_LIST_HEAD(&dev->dev_list);
INIT_LIST_HEAD(&dev->dev_sep_list);
INIT_LIST_HEAD(&dev->dev_tmr_list);
INIT_LIST_HEAD(&dev->delayed_cmd_list);
INIT_LIST_HEAD(&dev->state_list);
INIT_LIST_HEAD(&dev->qf_cmd_list);
spin_lock_init(&dev->execute_task_lock);
spin_lock_init(&dev->delayed_cmd_lock);
spin_lock_init(&dev->dev_reservation_lock);
spin_lock_init(&dev->dev_status_lock);
spin_lock_init(&dev->se_port_lock);
spin_lock_init(&dev->se_tmr_lock);
spin_lock_init(&dev->qf_cmd_lock);
atomic_set(&dev->dev_ordered_id, 0);
se_dev_set_default_attribs(dev, dev_limits);
dev->dev_index = scsi_get_new_index(SCSI_DEVICE_INDEX);
dev->creation_time = get_jiffies_64();
spin_lock_init(&dev->stats_lock);
spin_lock(&hba->device_lock);
list_add_tail(&dev->dev_list, &hba->hba_dev_list);
hba->dev_count++;
spin_unlock(&hba->device_lock);
core_setup_task_attr_emulation(dev);
force_pt = (hba->hba_flags & HBA_FLAGS_INTERNAL_USE);
core_setup_reservations(dev, force_pt);
if (core_setup_alua(dev, force_pt) < 0)
goto err_dev_list;
dev->tmr_wq = alloc_workqueue("tmr-%s", WQ_MEM_RECLAIM | WQ_UNBOUND, 1,
dev->transport->name);
if (!dev->tmr_wq) {
pr_err("Unable to create tmr workqueue for %s\n",
dev->transport->name);
goto err_dev_list;
}
INIT_WORK(&dev->qf_work_queue, target_qf_do_work);
if (dev->transport->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV) {
if (!inquiry_prod || !inquiry_rev) {
pr_err("All non TCM/pSCSI plugins require"
" INQUIRY consts\n");
goto err_wq;
}
strncpy(&dev->se_sub_dev->t10_wwn.vendor[0], "LIO-ORG", 8);
strncpy(&dev->se_sub_dev->t10_wwn.model[0], inquiry_prod, 16);
strncpy(&dev->se_sub_dev->t10_wwn.revision[0], inquiry_rev, 4);
}
scsi_dump_inquiry(dev);
return dev;
err_wq:
destroy_workqueue(dev->tmr_wq);
err_dev_list:
spin_lock(&hba->device_lock);
list_del(&dev->dev_list);
hba->dev_count--;
spin_unlock(&hba->device_lock);
se_release_vpd_for_dev(dev);
kfree(dev);
return NULL;
}
int target_cmd_size_check(struct se_cmd *cmd, unsigned int size)
{
struct se_device *dev = cmd->se_dev;
if (cmd->unknown_data_length) {
cmd->data_length = size;
} else if (size != cmd->data_length) {
pr_warn("TARGET_CORE[%s]: Expected Transfer Length:"
" %u does not match SCSI CDB Length: %u for SAM Opcode:"
" 0x%02x\n", cmd->se_tfo->get_fabric_name(),
cmd->data_length, size, cmd->t_task_cdb[0]);
if (cmd->data_direction == DMA_TO_DEVICE) {
pr_err("Rejecting underflow/overflow"
" WRITE data\n");
goto out_invalid_cdb_field;
}
if (dev->se_sub_dev->se_dev_attrib.block_size != 512) {
pr_err("Failing OVERFLOW/UNDERFLOW for LBA op"
" CDB on non 512-byte sector setup subsystem"
" plugin: %s\n", dev->transport->name);
goto out_invalid_cdb_field;
}
if (size > cmd->data_length) {
cmd->se_cmd_flags |= SCF_OVERFLOW_BIT;
cmd->residual_count = (size - cmd->data_length);
} else {
cmd->se_cmd_flags |= SCF_UNDERFLOW_BIT;
cmd->residual_count = (cmd->data_length - size);
cmd->data_length = size;
}
}
return 0;
out_invalid_cdb_field:
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -EINVAL;
}
void transport_init_se_cmd(
struct se_cmd *cmd,
struct target_core_fabric_ops *tfo,
struct se_session *se_sess,
u32 data_length,
int data_direction,
int task_attr,
unsigned char *sense_buffer)
{
INIT_LIST_HEAD(&cmd->se_lun_node);
INIT_LIST_HEAD(&cmd->se_delayed_node);
INIT_LIST_HEAD(&cmd->se_qf_node);
INIT_LIST_HEAD(&cmd->se_cmd_list);
INIT_LIST_HEAD(&cmd->state_list);
init_completion(&cmd->transport_lun_fe_stop_comp);
init_completion(&cmd->transport_lun_stop_comp);
init_completion(&cmd->t_transport_stop_comp);
init_completion(&cmd->cmd_wait_comp);
init_completion(&cmd->task_stop_comp);
spin_lock_init(&cmd->t_state_lock);
cmd->transport_state = CMD_T_DEV_ACTIVE;
cmd->se_tfo = tfo;
cmd->se_sess = se_sess;
cmd->data_length = data_length;
cmd->data_direction = data_direction;
cmd->sam_task_attr = task_attr;
cmd->sense_buffer = sense_buffer;
cmd->state_active = false;
}
static int transport_check_alloc_task_attr(struct se_cmd *cmd)
{
if (cmd->se_dev->dev_task_attr_type != SAM_TASK_ATTR_EMULATED)
return 0;
if (cmd->sam_task_attr == MSG_ACA_TAG) {
pr_debug("SAM Task Attribute ACA"
" emulation is not supported\n");
return -EINVAL;
}
cmd->se_ordered_id = atomic_inc_return(&cmd->se_dev->dev_ordered_id);
smp_mb__after_atomic_inc();
pr_debug("Allocated se_ordered_id: %u for Task Attr: 0x%02x on %s\n",
cmd->se_ordered_id, cmd->sam_task_attr,
cmd->se_dev->transport->name);
return 0;
}
int target_setup_cmd_from_cdb(
struct se_cmd *cmd,
unsigned char *cdb)
{
struct se_subsystem_dev *su_dev = cmd->se_dev->se_sub_dev;
u32 pr_reg_type = 0;
u8 alua_ascq = 0;
unsigned long flags;
int ret;
if (scsi_command_size(cdb) > SCSI_MAX_VARLEN_CDB_SIZE) {
pr_err("Received SCSI CDB with command_size: %d that"
" exceeds SCSI_MAX_VARLEN_CDB_SIZE: %d\n",
scsi_command_size(cdb), SCSI_MAX_VARLEN_CDB_SIZE);
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -EINVAL;
}
if (scsi_command_size(cdb) > sizeof(cmd->__t_task_cdb)) {
cmd->t_task_cdb = kzalloc(scsi_command_size(cdb),
GFP_KERNEL);
if (!cmd->t_task_cdb) {
pr_err("Unable to allocate cmd->t_task_cdb"
" %u > sizeof(cmd->__t_task_cdb): %lu ops\n",
scsi_command_size(cdb),
(unsigned long)sizeof(cmd->__t_task_cdb));
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason =
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return -ENOMEM;
}
} else
cmd->t_task_cdb = &cmd->__t_task_cdb[0];
memcpy(cmd->t_task_cdb, cdb, scsi_command_size(cdb));
if (core_scsi3_ua_check(cmd, cdb) < 0) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_CHECK_CONDITION_UNIT_ATTENTION;
return -EINVAL;
}
ret = su_dev->t10_alua.alua_state_check(cmd, cdb, &alua_ascq);
if (ret != 0) {
if (ret > 0) {
pr_debug("[%s]: ALUA TG Port not available, "
"SenseKey: NOT_READY, ASC/ASCQ: "
"0x04/0x%02x\n",
cmd->se_tfo->get_fabric_name(), alua_ascq);
transport_set_sense_codes(cmd, 0x04, alua_ascq);
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_CHECK_CONDITION_NOT_READY;
return -EINVAL;
}
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -EINVAL;
}
if (su_dev->t10_pr.pr_ops.t10_reservation_check(cmd, &pr_reg_type)) {
if (su_dev->t10_pr.pr_ops.t10_seq_non_holder(
cmd, cdb, pr_reg_type) != 0) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->se_cmd_flags |= SCF_SCSI_RESERVATION_CONFLICT;
cmd->scsi_status = SAM_STAT_RESERVATION_CONFLICT;
cmd->scsi_sense_reason = TCM_RESERVATION_CONFLICT;
return -EBUSY;
}
}
ret = cmd->se_dev->transport->parse_cdb(cmd);
if (ret < 0)
return ret;
spin_lock_irqsave(&cmd->t_state_lock, flags);
cmd->se_cmd_flags |= SCF_SUPPORTED_SAM_OPCODE;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
if (transport_check_alloc_task_attr(cmd) < 0) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -EINVAL;
}
spin_lock(&cmd->se_lun->lun_sep_lock);
if (cmd->se_lun->lun_sep)
cmd->se_lun->lun_sep->sep_stats.cmd_pdus++;
spin_unlock(&cmd->se_lun->lun_sep_lock);
return 0;
}
int transport_handle_cdb_direct(
struct se_cmd *cmd)
{
int ret;
if (!cmd->se_lun) {
dump_stack();
pr_err("cmd->se_lun is NULL\n");
return -EINVAL;
}
if (in_interrupt()) {
dump_stack();
pr_err("transport_generic_handle_cdb cannot be called"
" from interrupt context\n");
return -EINVAL;
}
cmd->t_state = TRANSPORT_NEW_CMD;
cmd->transport_state |= CMD_T_ACTIVE;
ret = transport_generic_new_cmd(cmd);
if (ret < 0)
transport_generic_request_failure(cmd);
return 0;
}
int target_submit_cmd_map_sgls(struct se_cmd *se_cmd, struct se_session *se_sess,
unsigned char *cdb, unsigned char *sense, u32 unpacked_lun,
u32 data_length, int task_attr, int data_dir, int flags,
struct scatterlist *sgl, u32 sgl_count,
struct scatterlist *sgl_bidi, u32 sgl_bidi_count)
{
struct se_portal_group *se_tpg;
int rc;
se_tpg = se_sess->se_tpg;
BUG_ON(!se_tpg);
BUG_ON(se_cmd->se_tfo || se_cmd->se_sess);
BUG_ON(in_interrupt());
transport_init_se_cmd(se_cmd, se_tpg->se_tpg_tfo, se_sess,
data_length, data_dir, task_attr, sense);
if (flags & TARGET_SCF_UNKNOWN_SIZE)
se_cmd->unknown_data_length = 1;
rc = target_get_sess_cmd(se_sess, se_cmd, (flags & TARGET_SCF_ACK_KREF));
if (rc)
return rc;
if (flags & TARGET_SCF_BIDI_OP)
se_cmd->se_cmd_flags |= SCF_BIDI;
if (transport_lookup_cmd_lun(se_cmd, unpacked_lun) < 0) {
transport_send_check_condition_and_sense(se_cmd,
se_cmd->scsi_sense_reason, 0);
target_put_sess_cmd(se_sess, se_cmd);
return 0;
}
rc = target_setup_cmd_from_cdb(se_cmd, cdb);
if (rc != 0) {
transport_generic_request_failure(se_cmd);
return 0;
}
if (sgl_count != 0) {
BUG_ON(!sgl);
if (!(se_cmd->se_cmd_flags & SCF_SCSI_DATA_CDB) &&
se_cmd->data_direction == DMA_FROM_DEVICE) {
unsigned char *buf = NULL;
if (sgl)
buf = kmap(sg_page(sgl)) + sgl->offset;
if (buf) {
memset(buf, 0, sgl->length);
kunmap(sg_page(sgl));
}
}
rc = transport_generic_map_mem_to_cmd(se_cmd, sgl, sgl_count,
sgl_bidi, sgl_bidi_count);
if (rc != 0) {
transport_generic_request_failure(se_cmd);
return 0;
}
}
core_alua_check_nonop_delay(se_cmd);
transport_handle_cdb_direct(se_cmd);
return 0;
}
int target_submit_cmd(struct se_cmd *se_cmd, struct se_session *se_sess,
unsigned char *cdb, unsigned char *sense, u32 unpacked_lun,
u32 data_length, int task_attr, int data_dir, int flags)
{
return target_submit_cmd_map_sgls(se_cmd, se_sess, cdb, sense,
unpacked_lun, data_length, task_attr, data_dir,
flags, NULL, 0, NULL, 0);
}
static void target_complete_tmr_failure(struct work_struct *work)
{
struct se_cmd *se_cmd = container_of(work, struct se_cmd, work);
se_cmd->se_tmr_req->response = TMR_LUN_DOES_NOT_EXIST;
se_cmd->se_tfo->queue_tm_rsp(se_cmd);
}
int target_submit_tmr(struct se_cmd *se_cmd, struct se_session *se_sess,
unsigned char *sense, u32 unpacked_lun,
void *fabric_tmr_ptr, unsigned char tm_type,
gfp_t gfp, unsigned int tag, int flags)
{
struct se_portal_group *se_tpg;
int ret;
se_tpg = se_sess->se_tpg;
BUG_ON(!se_tpg);
transport_init_se_cmd(se_cmd, se_tpg->se_tpg_tfo, se_sess,
0, DMA_NONE, MSG_SIMPLE_TAG, sense);
ret = core_tmr_alloc_req(se_cmd, fabric_tmr_ptr, tm_type, gfp);
if (ret < 0)
return -ENOMEM;
if (tm_type == TMR_ABORT_TASK)
se_cmd->se_tmr_req->ref_task_tag = tag;
ret = target_get_sess_cmd(se_sess, se_cmd, (flags & TARGET_SCF_ACK_KREF));
if (ret) {
core_tmr_release_req(se_cmd->se_tmr_req);
return ret;
}
ret = transport_lookup_tmr_lun(se_cmd, unpacked_lun);
if (ret) {
INIT_WORK(&se_cmd->work, target_complete_tmr_failure);
schedule_work(&se_cmd->work);
return 0;
}
transport_generic_handle_tmr(se_cmd);
return 0;
}
bool target_stop_cmd(struct se_cmd *cmd, unsigned long *flags)
{
bool was_active = false;
if (cmd->transport_state & CMD_T_BUSY) {
cmd->transport_state |= CMD_T_REQUEST_STOP;
spin_unlock_irqrestore(&cmd->t_state_lock, *flags);
pr_debug("cmd %p waiting to complete\n", cmd);
wait_for_completion(&cmd->task_stop_comp);
pr_debug("cmd %p stopped successfully\n", cmd);
spin_lock_irqsave(&cmd->t_state_lock, *flags);
cmd->transport_state &= ~CMD_T_REQUEST_STOP;
cmd->transport_state &= ~CMD_T_BUSY;
was_active = true;
}
return was_active;
}
void transport_generic_request_failure(struct se_cmd *cmd)
{
int ret = 0;
pr_debug("-----[ Storage Engine Exception for cmd: %p ITT: 0x%08x"
" CDB: 0x%02x\n", cmd, cmd->se_tfo->get_task_tag(cmd),
cmd->t_task_cdb[0]);
pr_debug("-----[ i_state: %d t_state: %d scsi_sense_reason: %d\n",
cmd->se_tfo->get_cmd_state(cmd),
cmd->t_state, cmd->scsi_sense_reason);
pr_debug("-----[ CMD_T_ACTIVE: %d CMD_T_STOP: %d CMD_T_SENT: %d\n",
(cmd->transport_state & CMD_T_ACTIVE) != 0,
(cmd->transport_state & CMD_T_STOP) != 0,
(cmd->transport_state & CMD_T_SENT) != 0);
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
transport_complete_task_attr(cmd);
switch (cmd->scsi_sense_reason) {
case TCM_NON_EXISTENT_LUN:
case TCM_UNSUPPORTED_SCSI_OPCODE:
case TCM_INVALID_CDB_FIELD:
case TCM_INVALID_PARAMETER_LIST:
case TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE:
case TCM_UNKNOWN_MODE_PAGE:
case TCM_WRITE_PROTECTED:
case TCM_ADDRESS_OUT_OF_RANGE:
case TCM_CHECK_CONDITION_ABORT_CMD:
case TCM_CHECK_CONDITION_UNIT_ATTENTION:
case TCM_CHECK_CONDITION_NOT_READY:
break;
case TCM_RESERVATION_CONFLICT:
cmd->scsi_status = SAM_STAT_RESERVATION_CONFLICT;
if (cmd->se_sess &&
cmd->se_dev->se_sub_dev->se_dev_attrib.emulate_ua_intlck_ctrl == 2)
core_scsi3_ua_allocate(cmd->se_sess->se_node_acl,
cmd->orig_fe_lun, 0x2C,
ASCQ_2CH_PREVIOUS_RESERVATION_CONFLICT_STATUS);
ret = cmd->se_tfo->queue_status(cmd);
if (ret == -EAGAIN || ret == -ENOMEM)
goto queue_full;
goto check_stop;
default:
pr_err("Unknown transport error for CDB 0x%02x: %d\n",
cmd->t_task_cdb[0], cmd->scsi_sense_reason);
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
break;
}
ret = transport_send_check_condition_and_sense(cmd,
cmd->scsi_sense_reason, 0);
if (ret == -EAGAIN || ret == -ENOMEM)
goto queue_full;
check_stop:
transport_lun_remove_cmd(cmd);
if (!transport_cmd_check_stop_to_fabric(cmd))
;
return;
queue_full:
cmd->t_state = TRANSPORT_COMPLETE_QF_OK;
transport_handle_queue_full(cmd, cmd->se_dev);
}
static void __target_execute_cmd(struct se_cmd *cmd)
{
int error = 0;
spin_lock_irq(&cmd->t_state_lock);
cmd->transport_state |= (CMD_T_BUSY|CMD_T_SENT);
spin_unlock_irq(&cmd->t_state_lock);
if (cmd->execute_cmd)
error = cmd->execute_cmd(cmd);
if (error) {
spin_lock_irq(&cmd->t_state_lock);
cmd->transport_state &= ~(CMD_T_BUSY|CMD_T_SENT);
spin_unlock_irq(&cmd->t_state_lock);
transport_generic_request_failure(cmd);
}
}
void target_execute_cmd(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
if (transport_check_aborted_status(cmd, 1)) {
complete(&cmd->t_transport_stop_comp);
return;
}
spin_lock_irq(&cmd->t_state_lock);
if (cmd->transport_state & CMD_T_LUN_STOP) {
pr_debug("%s:%d CMD_T_LUN_STOP for ITT: 0x%08x\n",
__func__, __LINE__, cmd->se_tfo->get_task_tag(cmd));
cmd->transport_state &= ~CMD_T_ACTIVE;
spin_unlock_irq(&cmd->t_state_lock);
complete(&cmd->transport_lun_stop_comp);
return;
}
if (cmd->transport_state & CMD_T_STOP) {
pr_debug("%s:%d CMD_T_STOP for ITT: 0x%08x\n",
__func__, __LINE__,
cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irq(&cmd->t_state_lock);
complete(&cmd->t_transport_stop_comp);
return;
}
cmd->t_state = TRANSPORT_PROCESSING;
spin_unlock_irq(&cmd->t_state_lock);
if (dev->dev_task_attr_type != SAM_TASK_ATTR_EMULATED)
goto execute;
switch (cmd->sam_task_attr) {
case MSG_HEAD_TAG:
pr_debug("Added HEAD_OF_QUEUE for CDB: 0x%02x, "
"se_ordered_id: %u\n",
cmd->t_task_cdb[0], cmd->se_ordered_id);
goto execute;
case MSG_ORDERED_TAG:
atomic_inc(&dev->dev_ordered_sync);
smp_mb__after_atomic_inc();
pr_debug("Added ORDERED for CDB: 0x%02x to ordered list, "
" se_ordered_id: %u\n",
cmd->t_task_cdb[0], cmd->se_ordered_id);
if (!atomic_read(&dev->simple_cmds))
goto execute;
break;
default:
atomic_inc(&dev->simple_cmds);
smp_mb__after_atomic_inc();
break;
}
if (atomic_read(&dev->dev_ordered_sync) != 0) {
spin_lock(&dev->delayed_cmd_lock);
list_add_tail(&cmd->se_delayed_node, &dev->delayed_cmd_list);
spin_unlock(&dev->delayed_cmd_lock);
pr_debug("Added CDB: 0x%02x Task Attr: 0x%02x to"
" delayed CMD list, se_ordered_id: %u\n",
cmd->t_task_cdb[0], cmd->sam_task_attr,
cmd->se_ordered_id);
return;
}
execute:
__target_execute_cmd(cmd);
}
static void target_restart_delayed_cmds(struct se_device *dev)
{
for (;;) {
struct se_cmd *cmd;
spin_lock(&dev->delayed_cmd_lock);
if (list_empty(&dev->delayed_cmd_list)) {
spin_unlock(&dev->delayed_cmd_lock);
break;
}
cmd = list_entry(dev->delayed_cmd_list.next,
struct se_cmd, se_delayed_node);
list_del(&cmd->se_delayed_node);
spin_unlock(&dev->delayed_cmd_lock);
__target_execute_cmd(cmd);
if (cmd->sam_task_attr == MSG_ORDERED_TAG)
break;
}
}
static void transport_complete_task_attr(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
if (cmd->sam_task_attr == MSG_SIMPLE_TAG) {
atomic_dec(&dev->simple_cmds);
smp_mb__after_atomic_dec();
dev->dev_cur_ordered_id++;
pr_debug("Incremented dev->dev_cur_ordered_id: %u for"
" SIMPLE: %u\n", dev->dev_cur_ordered_id,
cmd->se_ordered_id);
} else if (cmd->sam_task_attr == MSG_HEAD_TAG) {
dev->dev_cur_ordered_id++;
pr_debug("Incremented dev_cur_ordered_id: %u for"
" HEAD_OF_QUEUE: %u\n", dev->dev_cur_ordered_id,
cmd->se_ordered_id);
} else if (cmd->sam_task_attr == MSG_ORDERED_TAG) {
atomic_dec(&dev->dev_ordered_sync);
smp_mb__after_atomic_dec();
dev->dev_cur_ordered_id++;
pr_debug("Incremented dev_cur_ordered_id: %u for ORDERED:"
" %u\n", dev->dev_cur_ordered_id, cmd->se_ordered_id);
}
target_restart_delayed_cmds(dev);
}
static void transport_complete_qf(struct se_cmd *cmd)
{
int ret = 0;
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
transport_complete_task_attr(cmd);
if (cmd->se_cmd_flags & SCF_TRANSPORT_TASK_SENSE) {
ret = cmd->se_tfo->queue_status(cmd);
if (ret)
goto out;
}
switch (cmd->data_direction) {
case DMA_FROM_DEVICE:
ret = cmd->se_tfo->queue_data_in(cmd);
break;
case DMA_TO_DEVICE:
if (cmd->t_bidi_data_sg) {
ret = cmd->se_tfo->queue_data_in(cmd);
if (ret < 0)
break;
}
case DMA_NONE:
ret = cmd->se_tfo->queue_status(cmd);
break;
default:
break;
}
out:
if (ret < 0) {
transport_handle_queue_full(cmd, cmd->se_dev);
return;
}
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop_to_fabric(cmd);
}
static void transport_handle_queue_full(
struct se_cmd *cmd,
struct se_device *dev)
{
spin_lock_irq(&dev->qf_cmd_lock);
list_add_tail(&cmd->se_qf_node, &cmd->se_dev->qf_cmd_list);
atomic_inc(&dev->dev_qf_count);
smp_mb__after_atomic_inc();
spin_unlock_irq(&cmd->se_dev->qf_cmd_lock);
schedule_work(&cmd->se_dev->qf_work_queue);
}
static void target_complete_ok_work(struct work_struct *work)
{
struct se_cmd *cmd = container_of(work, struct se_cmd, work);
int ret;
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
transport_complete_task_attr(cmd);
if (atomic_read(&cmd->se_dev->dev_qf_count) != 0)
schedule_work(&cmd->se_dev->qf_work_queue);
if (cmd->se_cmd_flags & SCF_TRANSPORT_TASK_SENSE) {
WARN_ON(!cmd->scsi_status);
ret = transport_send_check_condition_and_sense(
cmd, 0, 1);
if (ret == -EAGAIN || ret == -ENOMEM)
goto queue_full;
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop_to_fabric(cmd);
return;
}
if (cmd->transport_complete_callback)
cmd->transport_complete_callback(cmd);
switch (cmd->data_direction) {
case DMA_FROM_DEVICE:
spin_lock(&cmd->se_lun->lun_sep_lock);
if (cmd->se_lun->lun_sep) {
cmd->se_lun->lun_sep->sep_stats.tx_data_octets +=
cmd->data_length;
}
spin_unlock(&cmd->se_lun->lun_sep_lock);
ret = cmd->se_tfo->queue_data_in(cmd);
if (ret == -EAGAIN || ret == -ENOMEM)
goto queue_full;
break;
case DMA_TO_DEVICE:
spin_lock(&cmd->se_lun->lun_sep_lock);
if (cmd->se_lun->lun_sep) {
cmd->se_lun->lun_sep->sep_stats.rx_data_octets +=
cmd->data_length;
}
spin_unlock(&cmd->se_lun->lun_sep_lock);
if (cmd->t_bidi_data_sg) {
spin_lock(&cmd->se_lun->lun_sep_lock);
if (cmd->se_lun->lun_sep) {
cmd->se_lun->lun_sep->sep_stats.tx_data_octets +=
cmd->data_length;
}
spin_unlock(&cmd->se_lun->lun_sep_lock);
ret = cmd->se_tfo->queue_data_in(cmd);
if (ret == -EAGAIN || ret == -ENOMEM)
goto queue_full;
break;
}
case DMA_NONE:
ret = cmd->se_tfo->queue_status(cmd);
if (ret == -EAGAIN || ret == -ENOMEM)
goto queue_full;
break;
default:
break;
}
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop_to_fabric(cmd);
return;
queue_full:
pr_debug("Handling complete_ok QUEUE_FULL: se_cmd: %p,"
" data_direction: %d\n", cmd, cmd->data_direction);
cmd->t_state = TRANSPORT_COMPLETE_QF_OK;
transport_handle_queue_full(cmd, cmd->se_dev);
}
static inline void transport_free_sgl(struct scatterlist *sgl, int nents)
{
struct scatterlist *sg;
int count;
for_each_sg(sgl, sg, nents, count)
__free_page(sg_page(sg));
kfree(sgl);
}
static inline void transport_free_pages(struct se_cmd *cmd)
{
if (cmd->se_cmd_flags & SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC)
return;
transport_free_sgl(cmd->t_data_sg, cmd->t_data_nents);
cmd->t_data_sg = NULL;
cmd->t_data_nents = 0;
transport_free_sgl(cmd->t_bidi_data_sg, cmd->t_bidi_data_nents);
cmd->t_bidi_data_sg = NULL;
cmd->t_bidi_data_nents = 0;
}
static void transport_release_cmd(struct se_cmd *cmd)
{
BUG_ON(!cmd->se_tfo);
if (cmd->se_cmd_flags & SCF_SCSI_TMR_CDB)
core_tmr_release_req(cmd->se_tmr_req);
if (cmd->t_task_cdb != cmd->__t_task_cdb)
kfree(cmd->t_task_cdb);
if (cmd->check_release != 0) {
target_put_sess_cmd(cmd->se_sess, cmd);
return;
}
cmd->se_tfo->release_cmd(cmd);
}
static void transport_put_cmd(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (atomic_read(&cmd->t_fe_count)) {
if (!atomic_dec_and_test(&cmd->t_fe_count))
goto out_busy;
}
if (cmd->transport_state & CMD_T_DEV_ACTIVE) {
cmd->transport_state &= ~CMD_T_DEV_ACTIVE;
target_remove_from_state_list(cmd);
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_free_pages(cmd);
transport_release_cmd(cmd);
return;
out_busy:
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
}
int transport_generic_map_mem_to_cmd(
struct se_cmd *cmd,
struct scatterlist *sgl,
u32 sgl_count,
struct scatterlist *sgl_bidi,
u32 sgl_bidi_count)
{
if (!sgl || !sgl_count)
return 0;
if (cmd->se_cmd_flags & SCF_OVERFLOW_BIT) {
pr_warn("Rejecting SCSI DATA overflow for fabric using"
" SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC\n");
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -EINVAL;
}
cmd->t_data_sg = sgl;
cmd->t_data_nents = sgl_count;
if (sgl_bidi && sgl_bidi_count) {
cmd->t_bidi_data_sg = sgl_bidi;
cmd->t_bidi_data_nents = sgl_bidi_count;
}
cmd->se_cmd_flags |= SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC;
return 0;
}
void *transport_kmap_data_sg(struct se_cmd *cmd)
{
struct scatterlist *sg = cmd->t_data_sg;
struct page **pages;
int i;
if (!cmd->t_data_nents)
return NULL;
BUG_ON(!sg);
if (cmd->t_data_nents == 1)
return kmap(sg_page(sg)) + sg->offset;
pages = kmalloc(sizeof(*pages) * cmd->t_data_nents, GFP_KERNEL);
if (!pages) {
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return NULL;
}
for_each_sg(cmd->t_data_sg, sg, cmd->t_data_nents, i) {
pages[i] = sg_page(sg);
}
cmd->t_data_vmap = vmap(pages, cmd->t_data_nents, VM_MAP, PAGE_KERNEL);
kfree(pages);
if (!cmd->t_data_vmap) {
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return NULL;
}
return cmd->t_data_vmap + cmd->t_data_sg[0].offset;
}
void transport_kunmap_data_sg(struct se_cmd *cmd)
{
if (!cmd->t_data_nents) {
return;
} else if (cmd->t_data_nents == 1) {
kunmap(sg_page(cmd->t_data_sg));
return;
}
vunmap(cmd->t_data_vmap);
cmd->t_data_vmap = NULL;
}
static int
transport_generic_get_mem(struct se_cmd *cmd)
{
u32 length = cmd->data_length;
unsigned int nents;
struct page *page;
gfp_t zero_flag;
int i = 0;
nents = DIV_ROUND_UP(length, PAGE_SIZE);
cmd->t_data_sg = kmalloc(sizeof(struct scatterlist) * nents, GFP_KERNEL);
if (!cmd->t_data_sg)
return -ENOMEM;
cmd->t_data_nents = nents;
sg_init_table(cmd->t_data_sg, nents);
zero_flag = cmd->se_cmd_flags & SCF_SCSI_DATA_CDB ? 0 : __GFP_ZERO;
while (length) {
u32 page_len = min_t(u32, length, PAGE_SIZE);
page = alloc_page(GFP_KERNEL | zero_flag);
if (!page)
goto out;
sg_set_page(&cmd->t_data_sg[i], page, page_len, 0);
length -= page_len;
i++;
}
return 0;
out:
while (i > 0) {
i--;
__free_page(sg_page(&cmd->t_data_sg[i]));
}
kfree(cmd->t_data_sg);
cmd->t_data_sg = NULL;
return -ENOMEM;
}
int transport_generic_new_cmd(struct se_cmd *cmd)
{
int ret = 0;
if (!(cmd->se_cmd_flags & SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC) &&
cmd->data_length) {
ret = transport_generic_get_mem(cmd);
if (ret < 0)
goto out_fail;
}
atomic_inc(&cmd->t_fe_count);
target_add_to_state_list(cmd);
if (cmd->data_direction != DMA_TO_DEVICE) {
target_execute_cmd(cmd);
return 0;
}
spin_lock_irq(&cmd->t_state_lock);
cmd->t_state = TRANSPORT_WRITE_PENDING;
spin_unlock_irq(&cmd->t_state_lock);
transport_cmd_check_stop(cmd, false);
ret = cmd->se_tfo->write_pending(cmd);
if (ret == -EAGAIN || ret == -ENOMEM)
goto queue_full;
if (ret < 0)
return ret;
return 1;
out_fail:
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return -EINVAL;
queue_full:
pr_debug("Handling write_pending QUEUE__FULL: se_cmd: %p\n", cmd);
cmd->t_state = TRANSPORT_COMPLETE_QF_WP;
transport_handle_queue_full(cmd, cmd->se_dev);
return 0;
}
static void transport_write_pending_qf(struct se_cmd *cmd)
{
int ret;
ret = cmd->se_tfo->write_pending(cmd);
if (ret == -EAGAIN || ret == -ENOMEM) {
pr_debug("Handling write_pending QUEUE__FULL: se_cmd: %p\n",
cmd);
transport_handle_queue_full(cmd, cmd->se_dev);
}
}
void transport_generic_free_cmd(struct se_cmd *cmd, int wait_for_tasks)
{
if (!(cmd->se_cmd_flags & SCF_SE_LUN_CMD)) {
if (wait_for_tasks && (cmd->se_cmd_flags & SCF_SCSI_TMR_CDB))
transport_wait_for_tasks(cmd);
transport_release_cmd(cmd);
} else {
if (wait_for_tasks)
transport_wait_for_tasks(cmd);
core_dec_lacl_count(cmd->se_sess->se_node_acl, cmd);
if (cmd->se_lun)
transport_lun_remove_cmd(cmd);
transport_put_cmd(cmd);
}
}
static int target_get_sess_cmd(struct se_session *se_sess, struct se_cmd *se_cmd,
bool ack_kref)
{
unsigned long flags;
int ret = 0;
kref_init(&se_cmd->cmd_kref);
if (ack_kref == true) {
kref_get(&se_cmd->cmd_kref);
se_cmd->se_cmd_flags |= SCF_ACK_KREF;
}
spin_lock_irqsave(&se_sess->sess_cmd_lock, flags);
if (se_sess->sess_tearing_down) {
ret = -ESHUTDOWN;
goto out;
}
list_add_tail(&se_cmd->se_cmd_list, &se_sess->sess_cmd_list);
se_cmd->check_release = 1;
out:
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
return ret;
}
static void target_release_cmd_kref(struct kref *kref)
{
struct se_cmd *se_cmd = container_of(kref, struct se_cmd, cmd_kref);
struct se_session *se_sess = se_cmd->se_sess;
unsigned long flags;
spin_lock_irqsave(&se_sess->sess_cmd_lock, flags);
if (list_empty(&se_cmd->se_cmd_list)) {
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
se_cmd->se_tfo->release_cmd(se_cmd);
return;
}
if (se_sess->sess_tearing_down && se_cmd->cmd_wait_set) {
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
complete(&se_cmd->cmd_wait_comp);
return;
}
list_del(&se_cmd->se_cmd_list);
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
se_cmd->se_tfo->release_cmd(se_cmd);
}
int target_put_sess_cmd(struct se_session *se_sess, struct se_cmd *se_cmd)
{
return kref_put(&se_cmd->cmd_kref, target_release_cmd_kref);
}
void target_sess_cmd_list_set_waiting(struct se_session *se_sess)
{
struct se_cmd *se_cmd;
unsigned long flags;
spin_lock_irqsave(&se_sess->sess_cmd_lock, flags);
WARN_ON(se_sess->sess_tearing_down);
se_sess->sess_tearing_down = 1;
list_for_each_entry(se_cmd, &se_sess->sess_cmd_list, se_cmd_list)
se_cmd->cmd_wait_set = 1;
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
}
void target_wait_for_sess_cmds(
struct se_session *se_sess,
int wait_for_tasks)
{
struct se_cmd *se_cmd, *tmp_cmd;
bool rc = false;
list_for_each_entry_safe(se_cmd, tmp_cmd,
&se_sess->sess_cmd_list, se_cmd_list) {
list_del(&se_cmd->se_cmd_list);
pr_debug("Waiting for se_cmd: %p t_state: %d, fabric state:"
" %d\n", se_cmd, se_cmd->t_state,
se_cmd->se_tfo->get_cmd_state(se_cmd));
if (wait_for_tasks) {
pr_debug("Calling transport_wait_for_tasks se_cmd: %p t_state: %d,"
" fabric state: %d\n", se_cmd, se_cmd->t_state,
se_cmd->se_tfo->get_cmd_state(se_cmd));
rc = transport_wait_for_tasks(se_cmd);
pr_debug("After transport_wait_for_tasks se_cmd: %p t_state: %d,"
" fabric state: %d\n", se_cmd, se_cmd->t_state,
se_cmd->se_tfo->get_cmd_state(se_cmd));
}
if (!rc) {
wait_for_completion(&se_cmd->cmd_wait_comp);
pr_debug("After cmd_wait_comp: se_cmd: %p t_state: %d"
" fabric state: %d\n", se_cmd, se_cmd->t_state,
se_cmd->se_tfo->get_cmd_state(se_cmd));
}
se_cmd->se_tfo->release_cmd(se_cmd);
}
}
static int transport_lun_wait_for_tasks(struct se_cmd *cmd, struct se_lun *lun)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (cmd->transport_state & CMD_T_STOP) {
cmd->transport_state &= ~CMD_T_LUN_STOP;
pr_debug("ConfigFS ITT[0x%08x] - CMD_T_STOP, skipping\n",
cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_cmd_check_stop(cmd, false);
return -EPERM;
}
cmd->transport_state |= CMD_T_LUN_FE_STOP;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
spin_lock_irqsave(&cmd->t_state_lock, flags);
if ((cmd->transport_state & CMD_T_BUSY) &&
(cmd->transport_state & CMD_T_SENT)) {
if (!target_stop_cmd(cmd, &flags))
ret++;
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
pr_debug("ConfigFS: cmd: %p stop tasks ret:"
" %d\n", cmd, ret);
if (!ret) {
pr_debug("ConfigFS: ITT[0x%08x] - stopping cmd....\n",
cmd->se_tfo->get_task_tag(cmd));
wait_for_completion(&cmd->transport_lun_stop_comp);
pr_debug("ConfigFS: ITT[0x%08x] - stopped cmd....\n",
cmd->se_tfo->get_task_tag(cmd));
}
return 0;
}
static void __transport_clear_lun_from_sessions(struct se_lun *lun)
{
struct se_cmd *cmd = NULL;
unsigned long lun_flags, cmd_flags;
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
while (!list_empty(&lun->lun_cmd_list)) {
cmd = list_first_entry(&lun->lun_cmd_list,
struct se_cmd, se_lun_node);
list_del_init(&cmd->se_lun_node);
spin_lock(&cmd->t_state_lock);
pr_debug("SE_LUN[%d] - Setting cmd->transport"
"_lun_stop for ITT: 0x%08x\n",
cmd->se_lun->unpacked_lun,
cmd->se_tfo->get_task_tag(cmd));
cmd->transport_state |= CMD_T_LUN_STOP;
spin_unlock(&cmd->t_state_lock);
spin_unlock_irqrestore(&lun->lun_cmd_lock, lun_flags);
if (!cmd->se_lun) {
pr_err("ITT: 0x%08x, [i,t]_state: %u/%u\n",
cmd->se_tfo->get_task_tag(cmd),
cmd->se_tfo->get_cmd_state(cmd), cmd->t_state);
BUG();
}
pr_debug("SE_LUN[%d] - ITT: 0x%08x before transport"
"_lun_wait_for_tasks()\n", cmd->se_lun->unpacked_lun,
cmd->se_tfo->get_task_tag(cmd));
if (transport_lun_wait_for_tasks(cmd, cmd->se_lun) < 0) {
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
continue;
}
pr_debug("SE_LUN[%d] - ITT: 0x%08x after transport_lun"
"_wait_for_tasks(): SUCCESS\n",
cmd->se_lun->unpacked_lun,
cmd->se_tfo->get_task_tag(cmd));
spin_lock_irqsave(&cmd->t_state_lock, cmd_flags);
if (!(cmd->transport_state & CMD_T_DEV_ACTIVE)) {
spin_unlock_irqrestore(&cmd->t_state_lock, cmd_flags);
goto check_cond;
}
cmd->transport_state &= ~CMD_T_DEV_ACTIVE;
target_remove_from_state_list(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, cmd_flags);
check_cond:
transport_send_check_condition_and_sense(cmd,
TCM_NON_EXISTENT_LUN, 0);
spin_lock_irqsave(&cmd->t_state_lock, cmd_flags);
if (cmd->transport_state & CMD_T_LUN_FE_STOP) {
pr_debug("SE_LUN[%d] - Detected FE stop for"
" struct se_cmd: %p ITT: 0x%08x\n",
lun->unpacked_lun,
cmd, cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock,
cmd_flags);
transport_cmd_check_stop(cmd, false);
complete(&cmd->transport_lun_fe_stop_comp);
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
continue;
}
pr_debug("SE_LUN[%d] - ITT: 0x%08x finished processing\n",
lun->unpacked_lun, cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock, cmd_flags);
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
}
spin_unlock_irqrestore(&lun->lun_cmd_lock, lun_flags);
}
static int transport_clear_lun_thread(void *p)
{
struct se_lun *lun = p;
__transport_clear_lun_from_sessions(lun);
complete(&lun->lun_shutdown_comp);
return 0;
}
int transport_clear_lun_from_sessions(struct se_lun *lun)
{
struct task_struct *kt;
kt = kthread_run(transport_clear_lun_thread, lun,
"tcm_cl_%u", lun->unpacked_lun);
if (IS_ERR(kt)) {
pr_err("Unable to start clear_lun thread\n");
return PTR_ERR(kt);
}
wait_for_completion(&lun->lun_shutdown_comp);
return 0;
}
bool transport_wait_for_tasks(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (!(cmd->se_cmd_flags & SCF_SE_LUN_CMD) &&
!(cmd->se_cmd_flags & SCF_SCSI_TMR_CDB)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return false;
}
if (!(cmd->se_cmd_flags & SCF_SUPPORTED_SAM_OPCODE) &&
!(cmd->se_cmd_flags & SCF_SCSI_TMR_CDB)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return false;
}
if (cmd->transport_state & CMD_T_LUN_STOP) {
pr_debug("wait_for_tasks: Stopping"
" wait_for_completion(&cmd->t_tasktransport_lun_fe"
"_stop_comp); for ITT: 0x%08x\n",
cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->transport_lun_stop_comp);
wait_for_completion(&cmd->transport_lun_fe_stop_comp);
spin_lock_irqsave(&cmd->t_state_lock, flags);
target_remove_from_state_list(cmd);
pr_debug("wait_for_tasks: Stopped"
" wait_for_completion(&cmd->t_tasktransport_lun_fe_"
"stop_comp); for ITT: 0x%08x\n",
cmd->se_tfo->get_task_tag(cmd));
cmd->transport_state &= ~CMD_T_LUN_STOP;
}
if (!(cmd->transport_state & CMD_T_ACTIVE)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return false;
}
cmd->transport_state |= CMD_T_STOP;
pr_debug("wait_for_tasks: Stopping %p ITT: 0x%08x"
" i_state: %d, t_state: %d, CMD_T_STOP\n",
cmd, cmd->se_tfo->get_task_tag(cmd),
cmd->se_tfo->get_cmd_state(cmd), cmd->t_state);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
wait_for_completion(&cmd->t_transport_stop_comp);
spin_lock_irqsave(&cmd->t_state_lock, flags);
cmd->transport_state &= ~(CMD_T_ACTIVE | CMD_T_STOP);
pr_debug("wait_for_tasks: Stopped wait_for_completion("
"&cmd->t_transport_stop_comp) for ITT: 0x%08x\n",
cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return true;
}
static int transport_get_sense_codes(
struct se_cmd *cmd,
u8 *asc,
u8 *ascq)
{
*asc = cmd->scsi_asc;
*ascq = cmd->scsi_ascq;
return 0;
}
static int transport_set_sense_codes(
struct se_cmd *cmd,
u8 asc,
u8 ascq)
{
cmd->scsi_asc = asc;
cmd->scsi_ascq = ascq;
return 0;
}
int transport_send_check_condition_and_sense(
struct se_cmd *cmd,
u8 reason,
int from_transport)
{
unsigned char *buffer = cmd->sense_buffer;
unsigned long flags;
u8 asc = 0, ascq = 0;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (cmd->se_cmd_flags & SCF_SENT_CHECK_CONDITION) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return 0;
}
cmd->se_cmd_flags |= SCF_SENT_CHECK_CONDITION;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
if (!reason && from_transport)
goto after_reason;
if (!from_transport)
cmd->se_cmd_flags |= SCF_EMULATED_TASK_SENSE;
switch (reason) {
case TCM_NON_EXISTENT_LUN:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[SPC_ASC_KEY_OFFSET] = 0x25;
break;
case TCM_UNSUPPORTED_SCSI_OPCODE:
case TCM_SECTOR_COUNT_TOO_MANY:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[SPC_ASC_KEY_OFFSET] = 0x20;
break;
case TCM_UNKNOWN_MODE_PAGE:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[SPC_ASC_KEY_OFFSET] = 0x24;
break;
case TCM_CHECK_CONDITION_ABORT_CMD:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[SPC_ASC_KEY_OFFSET] = 0x29;
buffer[SPC_ASCQ_KEY_OFFSET] = 0x03;
break;
case TCM_INCORRECT_AMOUNT_OF_DATA:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[SPC_ASC_KEY_OFFSET] = 0x0c;
buffer[SPC_ASCQ_KEY_OFFSET] = 0x0d;
break;
case TCM_INVALID_CDB_FIELD:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[SPC_ASC_KEY_OFFSET] = 0x24;
break;
case TCM_INVALID_PARAMETER_LIST:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[SPC_ASC_KEY_OFFSET] = 0x26;
break;
case TCM_UNEXPECTED_UNSOLICITED_DATA:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[SPC_ASC_KEY_OFFSET] = 0x0c;
buffer[SPC_ASCQ_KEY_OFFSET] = 0x0c;
break;
case TCM_SERVICE_CRC_ERROR:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[SPC_ASC_KEY_OFFSET] = 0x47;
buffer[SPC_ASCQ_KEY_OFFSET] = 0x05;
break;
case TCM_SNACK_REJECTED:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[SPC_ASC_KEY_OFFSET] = 0x11;
buffer[SPC_ASCQ_KEY_OFFSET] = 0x13;
break;
case TCM_WRITE_PROTECTED:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = DATA_PROTECT;
buffer[SPC_ASC_KEY_OFFSET] = 0x27;
break;
case TCM_ADDRESS_OUT_OF_RANGE:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[SPC_ASC_KEY_OFFSET] = 0x21;
break;
case TCM_CHECK_CONDITION_UNIT_ATTENTION:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = UNIT_ATTENTION;
core_scsi3_ua_for_check_condition(cmd, &asc, &ascq);
buffer[SPC_ASC_KEY_OFFSET] = asc;
buffer[SPC_ASCQ_KEY_OFFSET] = ascq;
break;
case TCM_CHECK_CONDITION_NOT_READY:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = NOT_READY;
transport_get_sense_codes(cmd, &asc, &ascq);
buffer[SPC_ASC_KEY_OFFSET] = asc;
buffer[SPC_ASCQ_KEY_OFFSET] = ascq;
break;
case TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE:
default:
buffer[0] = 0x70;
buffer[SPC_ADD_SENSE_LEN_OFFSET] = 10;
buffer[SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[SPC_ASC_KEY_OFFSET] = 0x80;
break;
}
cmd->scsi_status = SAM_STAT_CHECK_CONDITION;
cmd->scsi_sense_length = TRANSPORT_SENSE_BUFFER;
after_reason:
return cmd->se_tfo->queue_status(cmd);
}
int transport_check_aborted_status(struct se_cmd *cmd, int send_status)
{
int ret = 0;
if (cmd->transport_state & CMD_T_ABORTED) {
if (!send_status ||
(cmd->se_cmd_flags & SCF_SENT_DELAYED_TAS))
return 1;
pr_debug("Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
cmd->se_cmd_flags |= SCF_SENT_DELAYED_TAS;
cmd->se_tfo->queue_status(cmd);
ret = 1;
}
return ret;
}
void transport_send_task_abort(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (cmd->se_cmd_flags & (SCF_SENT_CHECK_CONDITION | SCF_SENT_DELAYED_TAS)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return;
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
if (cmd->data_direction == DMA_TO_DEVICE) {
if (cmd->se_tfo->write_pending_status(cmd) != 0) {
cmd->transport_state |= CMD_T_ABORTED;
smp_mb__after_atomic_inc();
}
}
cmd->scsi_status = SAM_STAT_TASK_ABORTED;
pr_debug("Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
cmd->se_tfo->queue_status(cmd);
}
static void target_tmr_work(struct work_struct *work)
{
struct se_cmd *cmd = container_of(work, struct se_cmd, work);
struct se_device *dev = cmd->se_dev;
struct se_tmr_req *tmr = cmd->se_tmr_req;
int ret;
switch (tmr->function) {
case TMR_ABORT_TASK:
core_tmr_abort_task(dev, tmr, cmd->se_sess);
break;
case TMR_ABORT_TASK_SET:
case TMR_CLEAR_ACA:
case TMR_CLEAR_TASK_SET:
tmr->response = TMR_TASK_MGMT_FUNCTION_NOT_SUPPORTED;
break;
case TMR_LUN_RESET:
ret = core_tmr_lun_reset(dev, tmr, NULL, NULL);
tmr->response = (!ret) ? TMR_FUNCTION_COMPLETE :
TMR_FUNCTION_REJECTED;
break;
case TMR_TARGET_WARM_RESET:
tmr->response = TMR_FUNCTION_REJECTED;
break;
case TMR_TARGET_COLD_RESET:
tmr->response = TMR_FUNCTION_REJECTED;
break;
default:
pr_err("Uknown TMR function: 0x%02x.\n",
tmr->function);
tmr->response = TMR_FUNCTION_REJECTED;
break;
}
cmd->t_state = TRANSPORT_ISTATE_PROCESSING;
cmd->se_tfo->queue_tm_rsp(cmd);
transport_cmd_check_stop_to_fabric(cmd);
}
int transport_generic_handle_tmr(
struct se_cmd *cmd)
{
INIT_WORK(&cmd->work, target_tmr_work);
queue_work(cmd->se_dev->tmr_wq, &cmd->work);
return 0;
}
