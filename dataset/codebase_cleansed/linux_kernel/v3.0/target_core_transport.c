int init_se_global(void)
{
struct se_global *global;
global = kzalloc(sizeof(struct se_global), GFP_KERNEL);
if (!(global)) {
printk(KERN_ERR "Unable to allocate memory for struct se_global\n");
return -1;
}
INIT_LIST_HEAD(&global->g_lu_gps_list);
INIT_LIST_HEAD(&global->g_se_tpg_list);
INIT_LIST_HEAD(&global->g_hba_list);
INIT_LIST_HEAD(&global->g_se_dev_list);
spin_lock_init(&global->g_device_lock);
spin_lock_init(&global->hba_lock);
spin_lock_init(&global->se_tpg_lock);
spin_lock_init(&global->lu_gps_lock);
spin_lock_init(&global->plugin_class_lock);
se_cmd_cache = kmem_cache_create("se_cmd_cache",
sizeof(struct se_cmd), __alignof__(struct se_cmd), 0, NULL);
if (!(se_cmd_cache)) {
printk(KERN_ERR "kmem_cache_create for struct se_cmd failed\n");
goto out;
}
se_tmr_req_cache = kmem_cache_create("se_tmr_cache",
sizeof(struct se_tmr_req), __alignof__(struct se_tmr_req),
0, NULL);
if (!(se_tmr_req_cache)) {
printk(KERN_ERR "kmem_cache_create() for struct se_tmr_req"
" failed\n");
goto out;
}
se_sess_cache = kmem_cache_create("se_sess_cache",
sizeof(struct se_session), __alignof__(struct se_session),
0, NULL);
if (!(se_sess_cache)) {
printk(KERN_ERR "kmem_cache_create() for struct se_session"
" failed\n");
goto out;
}
se_ua_cache = kmem_cache_create("se_ua_cache",
sizeof(struct se_ua), __alignof__(struct se_ua),
0, NULL);
if (!(se_ua_cache)) {
printk(KERN_ERR "kmem_cache_create() for struct se_ua failed\n");
goto out;
}
se_mem_cache = kmem_cache_create("se_mem_cache",
sizeof(struct se_mem), __alignof__(struct se_mem), 0, NULL);
if (!(se_mem_cache)) {
printk(KERN_ERR "kmem_cache_create() for struct se_mem failed\n");
goto out;
}
t10_pr_reg_cache = kmem_cache_create("t10_pr_reg_cache",
sizeof(struct t10_pr_registration),
__alignof__(struct t10_pr_registration), 0, NULL);
if (!(t10_pr_reg_cache)) {
printk(KERN_ERR "kmem_cache_create() for struct t10_pr_registration"
" failed\n");
goto out;
}
t10_alua_lu_gp_cache = kmem_cache_create("t10_alua_lu_gp_cache",
sizeof(struct t10_alua_lu_gp), __alignof__(struct t10_alua_lu_gp),
0, NULL);
if (!(t10_alua_lu_gp_cache)) {
printk(KERN_ERR "kmem_cache_create() for t10_alua_lu_gp_cache"
" failed\n");
goto out;
}
t10_alua_lu_gp_mem_cache = kmem_cache_create("t10_alua_lu_gp_mem_cache",
sizeof(struct t10_alua_lu_gp_member),
__alignof__(struct t10_alua_lu_gp_member), 0, NULL);
if (!(t10_alua_lu_gp_mem_cache)) {
printk(KERN_ERR "kmem_cache_create() for t10_alua_lu_gp_mem_"
"cache failed\n");
goto out;
}
t10_alua_tg_pt_gp_cache = kmem_cache_create("t10_alua_tg_pt_gp_cache",
sizeof(struct t10_alua_tg_pt_gp),
__alignof__(struct t10_alua_tg_pt_gp), 0, NULL);
if (!(t10_alua_tg_pt_gp_cache)) {
printk(KERN_ERR "kmem_cache_create() for t10_alua_tg_pt_gp_"
"cache failed\n");
goto out;
}
t10_alua_tg_pt_gp_mem_cache = kmem_cache_create(
"t10_alua_tg_pt_gp_mem_cache",
sizeof(struct t10_alua_tg_pt_gp_member),
__alignof__(struct t10_alua_tg_pt_gp_member),
0, NULL);
if (!(t10_alua_tg_pt_gp_mem_cache)) {
printk(KERN_ERR "kmem_cache_create() for t10_alua_tg_pt_gp_"
"mem_t failed\n");
goto out;
}
se_global = global;
return 0;
out:
if (se_cmd_cache)
kmem_cache_destroy(se_cmd_cache);
if (se_tmr_req_cache)
kmem_cache_destroy(se_tmr_req_cache);
if (se_sess_cache)
kmem_cache_destroy(se_sess_cache);
if (se_ua_cache)
kmem_cache_destroy(se_ua_cache);
if (se_mem_cache)
kmem_cache_destroy(se_mem_cache);
if (t10_pr_reg_cache)
kmem_cache_destroy(t10_pr_reg_cache);
if (t10_alua_lu_gp_cache)
kmem_cache_destroy(t10_alua_lu_gp_cache);
if (t10_alua_lu_gp_mem_cache)
kmem_cache_destroy(t10_alua_lu_gp_mem_cache);
if (t10_alua_tg_pt_gp_cache)
kmem_cache_destroy(t10_alua_tg_pt_gp_cache);
if (t10_alua_tg_pt_gp_mem_cache)
kmem_cache_destroy(t10_alua_tg_pt_gp_mem_cache);
kfree(global);
return -1;
}
void release_se_global(void)
{
struct se_global *global;
global = se_global;
if (!(global))
return;
kmem_cache_destroy(se_cmd_cache);
kmem_cache_destroy(se_tmr_req_cache);
kmem_cache_destroy(se_sess_cache);
kmem_cache_destroy(se_ua_cache);
kmem_cache_destroy(se_mem_cache);
kmem_cache_destroy(t10_pr_reg_cache);
kmem_cache_destroy(t10_alua_lu_gp_cache);
kmem_cache_destroy(t10_alua_lu_gp_mem_cache);
kmem_cache_destroy(t10_alua_tg_pt_gp_cache);
kmem_cache_destroy(t10_alua_tg_pt_gp_mem_cache);
kfree(global);
se_global = NULL;
}
void init_scsi_index_table(void)
{
memset(&scsi_index_table, 0, sizeof(struct scsi_index_table));
spin_lock_init(&scsi_index_table.lock);
}
u32 scsi_get_new_index(scsi_index_t type)
{
u32 new_index;
if ((type < 0) || (type >= SCSI_INDEX_TYPE_MAX)) {
printk(KERN_ERR "Invalid index type %d\n", type);
return -EINVAL;
}
spin_lock(&scsi_index_table.lock);
new_index = ++scsi_index_table.scsi_mib_index[type];
if (new_index == 0)
new_index = ++scsi_index_table.scsi_mib_index[type];
spin_unlock(&scsi_index_table.lock);
return new_index;
}
void transport_init_queue_obj(struct se_queue_obj *qobj)
{
atomic_set(&qobj->queue_cnt, 0);
INIT_LIST_HEAD(&qobj->qobj_list);
init_waitqueue_head(&qobj->thread_wq);
spin_lock_init(&qobj->cmd_queue_lock);
}
static int transport_subsystem_reqmods(void)
{
int ret;
ret = request_module("target_core_iblock");
if (ret != 0)
printk(KERN_ERR "Unable to load target_core_iblock\n");
ret = request_module("target_core_file");
if (ret != 0)
printk(KERN_ERR "Unable to load target_core_file\n");
ret = request_module("target_core_pscsi");
if (ret != 0)
printk(KERN_ERR "Unable to load target_core_pscsi\n");
ret = request_module("target_core_stgt");
if (ret != 0)
printk(KERN_ERR "Unable to load target_core_stgt\n");
return 0;
}
int transport_subsystem_check_init(void)
{
if (se_global->g_sub_api_initialized)
return 0;
if (transport_subsystem_reqmods() < 0)
return -1;
se_global->g_sub_api_initialized = 1;
return 0;
}
struct se_session *transport_init_session(void)
{
struct se_session *se_sess;
se_sess = kmem_cache_zalloc(se_sess_cache, GFP_KERNEL);
if (!(se_sess)) {
printk(KERN_ERR "Unable to allocate struct se_session from"
" se_sess_cache\n");
return ERR_PTR(-ENOMEM);
}
INIT_LIST_HEAD(&se_sess->sess_list);
INIT_LIST_HEAD(&se_sess->sess_acl_list);
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
if (TPG_TFO(se_tpg)->sess_get_initiator_sid != NULL) {
memset(&buf[0], 0, PR_REG_ISID_LEN);
TPG_TFO(se_tpg)->sess_get_initiator_sid(se_sess,
&buf[0], PR_REG_ISID_LEN);
se_sess->sess_bin_isid = get_unaligned_be64(&buf[0]);
}
spin_lock_irq(&se_nacl->nacl_sess_lock);
se_nacl->nacl_sess = se_sess;
list_add_tail(&se_sess->sess_acl_list,
&se_nacl->acl_sess_list);
spin_unlock_irq(&se_nacl->nacl_sess_lock);
}
list_add_tail(&se_sess->sess_list, &se_tpg->tpg_sess_list);
printk(KERN_INFO "TARGET_CORE[%s]: Registered fabric_sess_ptr: %p\n",
TPG_TFO(se_tpg)->get_fabric_name(), se_sess->fabric_sess_ptr);
}
void transport_register_session(
struct se_portal_group *se_tpg,
struct se_node_acl *se_nacl,
struct se_session *se_sess,
void *fabric_sess_ptr)
{
spin_lock_bh(&se_tpg->session_lock);
__transport_register_session(se_tpg, se_nacl, se_sess, fabric_sess_ptr);
spin_unlock_bh(&se_tpg->session_lock);
}
void transport_deregister_session_configfs(struct se_session *se_sess)
{
struct se_node_acl *se_nacl;
unsigned long flags;
se_nacl = se_sess->se_node_acl;
if ((se_nacl)) {
spin_lock_irqsave(&se_nacl->nacl_sess_lock, flags);
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
struct se_node_acl *se_nacl;
if (!(se_tpg)) {
transport_free_session(se_sess);
return;
}
spin_lock_bh(&se_tpg->session_lock);
list_del(&se_sess->sess_list);
se_sess->se_tpg = NULL;
se_sess->fabric_sess_ptr = NULL;
spin_unlock_bh(&se_tpg->session_lock);
se_nacl = se_sess->se_node_acl;
if ((se_nacl)) {
spin_lock_bh(&se_tpg->acl_node_lock);
if (se_nacl->dynamic_node_acl) {
if (!(TPG_TFO(se_tpg)->tpg_check_demo_mode_cache(
se_tpg))) {
list_del(&se_nacl->acl_list);
se_tpg->num_node_acls--;
spin_unlock_bh(&se_tpg->acl_node_lock);
core_tpg_wait_for_nacl_pr_ref(se_nacl);
core_free_device_list_for_node(se_nacl, se_tpg);
TPG_TFO(se_tpg)->tpg_release_fabric_acl(se_tpg,
se_nacl);
spin_lock_bh(&se_tpg->acl_node_lock);
}
}
spin_unlock_bh(&se_tpg->acl_node_lock);
}
transport_free_session(se_sess);
printk(KERN_INFO "TARGET_CORE[%s]: Deregistered fabric_sess\n",
TPG_TFO(se_tpg)->get_fabric_name());
}
static void transport_all_task_dev_remove_state(struct se_cmd *cmd)
{
struct se_device *dev;
struct se_task *task;
unsigned long flags;
if (!T_TASK(cmd))
return;
list_for_each_entry(task, &T_TASK(cmd)->t_task_list, t_list) {
dev = task->se_dev;
if (!(dev))
continue;
if (atomic_read(&task->task_active))
continue;
if (!(atomic_read(&task->task_state_active)))
continue;
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_del(&task->t_state_list);
DEBUG_TSTATE("Removed ITT: 0x%08x dev: %p task[%p]\n",
CMD_TFO(cmd)->tfo_get_task_tag(cmd), dev, task);
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
atomic_set(&task->task_state_active, 0);
atomic_dec(&T_TASK(cmd)->t_task_cdbs_ex_left);
}
}
static int transport_cmd_check_stop(
struct se_cmd *cmd,
int transport_off,
u8 t_state)
{
unsigned long flags;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (atomic_read(&T_TASK(cmd)->transport_lun_stop)) {
DEBUG_CS("%s:%d atomic_read(&T_TASK(cmd)->transport_lun_stop)"
" == TRUE for ITT: 0x%08x\n", __func__, __LINE__,
CMD_TFO(cmd)->get_task_tag(cmd));
cmd->deferred_t_state = cmd->t_state;
cmd->t_state = TRANSPORT_DEFERRED_CMD;
atomic_set(&T_TASK(cmd)->t_transport_active, 0);
if (transport_off == 2)
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
complete(&T_TASK(cmd)->transport_lun_stop_comp);
return 1;
}
if (atomic_read(&T_TASK(cmd)->t_transport_stop)) {
DEBUG_CS("%s:%d atomic_read(&T_TASK(cmd)->t_transport_stop) =="
" TRUE for ITT: 0x%08x\n", __func__, __LINE__,
CMD_TFO(cmd)->get_task_tag(cmd));
cmd->deferred_t_state = cmd->t_state;
cmd->t_state = TRANSPORT_DEFERRED_CMD;
if (transport_off == 2)
transport_all_task_dev_remove_state(cmd);
if (transport_off == 2)
cmd->se_lun = NULL;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
complete(&T_TASK(cmd)->t_transport_stop_comp);
return 1;
}
if (transport_off) {
atomic_set(&T_TASK(cmd)->t_transport_active, 0);
if (transport_off == 2) {
transport_all_task_dev_remove_state(cmd);
cmd->se_lun = NULL;
if (CMD_TFO(cmd)->check_stop_free != NULL) {
spin_unlock_irqrestore(
&T_TASK(cmd)->t_state_lock, flags);
CMD_TFO(cmd)->check_stop_free(cmd);
return 1;
}
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return 0;
} else if (t_state)
cmd->t_state = t_state;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return 0;
}
static int transport_cmd_check_stop_to_fabric(struct se_cmd *cmd)
{
return transport_cmd_check_stop(cmd, 2, 0);
}
static void transport_lun_remove_cmd(struct se_cmd *cmd)
{
struct se_lun *lun = SE_LUN(cmd);
unsigned long flags;
if (!lun)
return;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (!(atomic_read(&T_TASK(cmd)->transport_dev_active))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
goto check_lun;
}
atomic_set(&T_TASK(cmd)->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
check_lun:
spin_lock_irqsave(&lun->lun_cmd_lock, flags);
if (atomic_read(&T_TASK(cmd)->transport_lun_active)) {
list_del(&cmd->se_lun_list);
atomic_set(&T_TASK(cmd)->transport_lun_active, 0);
#if 0
printk(KERN_INFO "Removed ITT: 0x%08x from LUN LIST[%d]\n"
CMD_TFO(cmd)->get_task_tag(cmd), lun->unpacked_lun);
#endif
}
spin_unlock_irqrestore(&lun->lun_cmd_lock, flags);
}
void transport_cmd_finish_abort(struct se_cmd *cmd, int remove)
{
transport_remove_cmd_from_queue(cmd, SE_DEV(cmd)->dev_queue_obj);
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop_to_fabric(cmd))
return;
if (remove)
transport_generic_remove(cmd, 0, 0);
}
void transport_cmd_finish_abort_tmr(struct se_cmd *cmd)
{
transport_remove_cmd_from_queue(cmd, SE_DEV(cmd)->dev_queue_obj);
if (transport_cmd_check_stop_to_fabric(cmd))
return;
transport_generic_remove(cmd, 0, 0);
}
static int transport_add_cmd_to_queue(
struct se_cmd *cmd,
int t_state)
{
struct se_device *dev = cmd->se_dev;
struct se_queue_obj *qobj = dev->dev_queue_obj;
struct se_queue_req *qr;
unsigned long flags;
qr = kzalloc(sizeof(struct se_queue_req), GFP_ATOMIC);
if (!(qr)) {
printk(KERN_ERR "Unable to allocate memory for"
" struct se_queue_req\n");
return -1;
}
INIT_LIST_HEAD(&qr->qr_list);
qr->cmd = (void *)cmd;
qr->state = t_state;
if (t_state) {
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
cmd->t_state = t_state;
atomic_set(&T_TASK(cmd)->t_transport_active, 1);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
}
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
list_add_tail(&qr->qr_list, &qobj->qobj_list);
atomic_inc(&T_TASK(cmd)->t_transport_queue_active);
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
atomic_inc(&qobj->queue_cnt);
wake_up_interruptible(&qobj->thread_wq);
return 0;
}
static struct se_queue_req *
__transport_get_qr_from_queue(struct se_queue_obj *qobj)
{
struct se_cmd *cmd;
struct se_queue_req *qr = NULL;
if (list_empty(&qobj->qobj_list))
return NULL;
list_for_each_entry(qr, &qobj->qobj_list, qr_list)
break;
if (qr->cmd) {
cmd = (struct se_cmd *)qr->cmd;
atomic_dec(&T_TASK(cmd)->t_transport_queue_active);
}
list_del(&qr->qr_list);
atomic_dec(&qobj->queue_cnt);
return qr;
}
static struct se_queue_req *
transport_get_qr_from_queue(struct se_queue_obj *qobj)
{
struct se_cmd *cmd;
struct se_queue_req *qr;
unsigned long flags;
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
if (list_empty(&qobj->qobj_list)) {
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
return NULL;
}
list_for_each_entry(qr, &qobj->qobj_list, qr_list)
break;
if (qr->cmd) {
cmd = (struct se_cmd *)qr->cmd;
atomic_dec(&T_TASK(cmd)->t_transport_queue_active);
}
list_del(&qr->qr_list);
atomic_dec(&qobj->queue_cnt);
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
return qr;
}
static void transport_remove_cmd_from_queue(struct se_cmd *cmd,
struct se_queue_obj *qobj)
{
struct se_cmd *q_cmd;
struct se_queue_req *qr = NULL, *qr_p = NULL;
unsigned long flags;
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
if (!(atomic_read(&T_TASK(cmd)->t_transport_queue_active))) {
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
return;
}
list_for_each_entry_safe(qr, qr_p, &qobj->qobj_list, qr_list) {
q_cmd = (struct se_cmd *)qr->cmd;
if (q_cmd != cmd)
continue;
atomic_dec(&T_TASK(q_cmd)->t_transport_queue_active);
atomic_dec(&qobj->queue_cnt);
list_del(&qr->qr_list);
kfree(qr);
}
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
if (atomic_read(&T_TASK(cmd)->t_transport_queue_active)) {
printk(KERN_ERR "ITT: 0x%08x t_transport_queue_active: %d\n",
CMD_TFO(cmd)->get_task_tag(cmd),
atomic_read(&T_TASK(cmd)->t_transport_queue_active));
}
}
void transport_complete_sync_cache(struct se_cmd *cmd, int good)
{
struct se_task *task = list_entry(T_TASK(cmd)->t_task_list.next,
struct se_task, t_list);
if (good) {
cmd->scsi_status = SAM_STAT_GOOD;
task->task_scsi_status = GOOD;
} else {
task->task_scsi_status = SAM_STAT_CHECK_CONDITION;
task->task_error_status = PYX_TRANSPORT_ILLEGAL_REQUEST;
TASK_CMD(task)->transport_error_status =
PYX_TRANSPORT_ILLEGAL_REQUEST;
}
transport_complete_task(task, good);
}
void transport_complete_task(struct se_task *task, int success)
{
struct se_cmd *cmd = TASK_CMD(task);
struct se_device *dev = task->se_dev;
int t_state;
unsigned long flags;
#if 0
printk(KERN_INFO "task: %p CDB: 0x%02x obj_ptr: %p\n", task,
T_TASK(cmd)->t_task_cdb[0], dev);
#endif
if (dev) {
spin_lock_irqsave(&SE_HBA(dev)->hba_queue_lock, flags);
atomic_inc(&dev->depth_left);
atomic_inc(&SE_HBA(dev)->left_queue_depth);
spin_unlock_irqrestore(&SE_HBA(dev)->hba_queue_lock, flags);
}
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
atomic_set(&task->task_active, 0);
if (dev && dev->transport->transport_complete) {
if (dev->transport->transport_complete(task) != 0) {
cmd->se_cmd_flags |= SCF_TRANSPORT_TASK_SENSE;
task->task_sense = 1;
success = 1;
}
}
if (atomic_read(&task->task_stop)) {
if (atomic_read(&task->task_timeout)) {
atomic_dec(&T_TASK(cmd)->t_se_count);
atomic_set(&task->task_timeout, 0);
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
complete(&task->task_stop_comp);
return;
}
if (atomic_read(&task->task_timeout)) {
if (!(atomic_dec_and_test(
&T_TASK(cmd)->t_task_cdbs_timeout_left))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
flags);
return;
}
t_state = TRANSPORT_COMPLETE_TIMEOUT;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_add_cmd_to_queue(cmd, t_state);
return;
}
atomic_dec(&T_TASK(cmd)->t_task_cdbs_timeout_left);
if (!(atomic_dec_and_test(&T_TASK(cmd)->t_task_cdbs_left))) {
if (!success)
T_TASK(cmd)->t_tasks_failed = 1;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return;
}
if (!success || T_TASK(cmd)->t_tasks_failed) {
t_state = TRANSPORT_COMPLETE_FAILURE;
if (!task->task_error_status) {
task->task_error_status =
PYX_TRANSPORT_UNKNOWN_SAM_OPCODE;
cmd->transport_error_status =
PYX_TRANSPORT_UNKNOWN_SAM_OPCODE;
}
} else {
atomic_set(&T_TASK(cmd)->t_transport_complete, 1);
t_state = TRANSPORT_COMPLETE_OK;
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_add_cmd_to_queue(cmd, t_state);
}
static inline int transport_add_task_check_sam_attr(
struct se_task *task,
struct se_task *task_prev,
struct se_device *dev)
{
if (dev->dev_task_attr_type != SAM_TASK_ATTR_EMULATED) {
list_add_tail(&task->t_execute_list, &dev->execute_task_list);
return 0;
}
if (task->task_se_cmd->sam_task_attr == MSG_HEAD_TAG) {
list_add(&task->t_execute_list,
(task_prev != NULL) ?
&task_prev->t_execute_list :
&dev->execute_task_list);
DEBUG_STA("Set HEAD_OF_QUEUE for task CDB: 0x%02x"
" in execution queue\n",
T_TASK(task->task_se_cmd)->t_task_cdb[0]);
return 1;
}
list_add_tail(&task->t_execute_list, &dev->execute_task_list);
return 0;
}
static void __transport_add_task_to_execute_queue(
struct se_task *task,
struct se_task *task_prev,
struct se_device *dev)
{
int head_of_queue;
head_of_queue = transport_add_task_check_sam_attr(task, task_prev, dev);
atomic_inc(&dev->execute_tasks);
if (atomic_read(&task->task_state_active))
return;
if (head_of_queue)
list_add(&task->t_state_list, (task_prev) ?
&task_prev->t_state_list :
&dev->state_task_list);
else
list_add_tail(&task->t_state_list, &dev->state_task_list);
atomic_set(&task->task_state_active, 1);
DEBUG_TSTATE("Added ITT: 0x%08x task[%p] to dev: %p\n",
CMD_TFO(task->task_se_cmd)->get_task_tag(task->task_se_cmd),
task, dev);
}
static void transport_add_tasks_to_state_queue(struct se_cmd *cmd)
{
struct se_device *dev;
struct se_task *task;
unsigned long flags;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
list_for_each_entry(task, &T_TASK(cmd)->t_task_list, t_list) {
dev = task->se_dev;
if (atomic_read(&task->task_state_active))
continue;
spin_lock(&dev->execute_task_lock);
list_add_tail(&task->t_state_list, &dev->state_task_list);
atomic_set(&task->task_state_active, 1);
DEBUG_TSTATE("Added ITT: 0x%08x task[%p] to dev: %p\n",
CMD_TFO(task->task_se_cmd)->get_task_tag(
task->task_se_cmd), task, dev);
spin_unlock(&dev->execute_task_lock);
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
}
static void transport_add_tasks_from_cmd(struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
struct se_task *task, *task_prev = NULL;
unsigned long flags;
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_for_each_entry(task, &T_TASK(cmd)->t_task_list, t_list) {
if (atomic_read(&task->task_execute_queue))
continue;
__transport_add_task_to_execute_queue(task, task_prev, dev);
atomic_set(&task->task_execute_queue, 1);
task_prev = task;
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
return;
}
static struct se_task *
transport_get_task_from_execute_queue(struct se_device *dev)
{
struct se_task *task;
if (list_empty(&dev->execute_task_list))
return NULL;
list_for_each_entry(task, &dev->execute_task_list, t_execute_list)
break;
list_del(&task->t_execute_list);
atomic_set(&task->task_execute_queue, 0);
atomic_dec(&dev->execute_tasks);
return task;
}
void transport_remove_task_from_execute_queue(
struct se_task *task,
struct se_device *dev)
{
unsigned long flags;
if (atomic_read(&task->task_execute_queue) == 0) {
dump_stack();
return;
}
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_del(&task->t_execute_list);
atomic_set(&task->task_execute_queue, 0);
atomic_dec(&dev->execute_tasks);
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
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
*bl += sprintf(b + *bl, " Execute/Left/Max Queue Depth: %d/%d/%d",
atomic_read(&dev->execute_tasks), atomic_read(&dev->depth_left),
dev->queue_depth);
*bl += sprintf(b + *bl, " SectorSize: %u MaxSectors: %u\n",
DEV_ATTRIB(dev)->block_size, DEV_ATTRIB(dev)->max_sectors);
*bl += sprintf(b + *bl, " ");
}
static void transport_release_all_cmds(struct se_device *dev)
{
struct se_cmd *cmd = NULL;
struct se_queue_req *qr = NULL, *qr_p = NULL;
int bug_out = 0, t_state;
unsigned long flags;
spin_lock_irqsave(&dev->dev_queue_obj->cmd_queue_lock, flags);
list_for_each_entry_safe(qr, qr_p, &dev->dev_queue_obj->qobj_list,
qr_list) {
cmd = (struct se_cmd *)qr->cmd;
t_state = qr->state;
list_del(&qr->qr_list);
kfree(qr);
spin_unlock_irqrestore(&dev->dev_queue_obj->cmd_queue_lock,
flags);
printk(KERN_ERR "Releasing ITT: 0x%08x, i_state: %u,"
" t_state: %u directly\n",
CMD_TFO(cmd)->get_task_tag(cmd),
CMD_TFO(cmd)->get_cmd_state(cmd), t_state);
transport_release_fe_cmd(cmd);
bug_out = 1;
spin_lock_irqsave(&dev->dev_queue_obj->cmd_queue_lock, flags);
}
spin_unlock_irqrestore(&dev->dev_queue_obj->cmd_queue_lock, flags);
#if 0
if (bug_out)
BUG();
#endif
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
printk(KERN_INFO "%s", buf);
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
int ret = 0, len;
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
ret = -1;
break;
}
if (p_buf)
strncpy(p_buf, buf, p_buf_len);
else
printk("%s", buf);
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
int ret = 0, len;
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
ret = -1;
break;
}
if (p_buf)
strncpy(p_buf, buf, p_buf_len);
else
printk("%s", buf);
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
ret = -1;
break;
}
if (p_buf)
strncpy(p_buf, buf, p_buf_len);
else
printk("%s", buf);
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
if (TRANSPORT(dev)->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV) {
dev->dev_task_attr_type = SAM_TASK_ATTR_PASSTHROUGH;
return;
}
dev->dev_task_attr_type = SAM_TASK_ATTR_EMULATED;
DEBUG_STA("%s: Using SAM_TASK_ATTR_EMULATED for SPC: 0x%02x"
" device\n", TRANSPORT(dev)->name,
TRANSPORT(dev)->get_device_rev(dev));
}
static void scsi_dump_inquiry(struct se_device *dev)
{
struct t10_wwn *wwn = DEV_T10_WWN(dev);
int i, device_type;
printk(" Vendor: ");
for (i = 0; i < 8; i++)
if (wwn->vendor[i] >= 0x20)
printk("%c", wwn->vendor[i]);
else
printk(" ");
printk(" Model: ");
for (i = 0; i < 16; i++)
if (wwn->model[i] >= 0x20)
printk("%c", wwn->model[i]);
else
printk(" ");
printk(" Revision: ");
for (i = 0; i < 4; i++)
if (wwn->revision[i] >= 0x20)
printk("%c", wwn->revision[i]);
else
printk(" ");
printk("\n");
device_type = TRANSPORT(dev)->get_device_type(dev);
printk(" Type: %s ", scsi_device_type(device_type));
printk(" ANSI SCSI revision: %02x\n",
TRANSPORT(dev)->get_device_rev(dev));
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
if (!(dev)) {
printk(KERN_ERR "Unable to allocate memory for se_dev_t\n");
return NULL;
}
dev->dev_queue_obj = kzalloc(sizeof(struct se_queue_obj), GFP_KERNEL);
if (!(dev->dev_queue_obj)) {
printk(KERN_ERR "Unable to allocate memory for"
" dev->dev_queue_obj\n");
kfree(dev);
return NULL;
}
transport_init_queue_obj(dev->dev_queue_obj);
dev->dev_status_queue_obj = kzalloc(sizeof(struct se_queue_obj),
GFP_KERNEL);
if (!(dev->dev_status_queue_obj)) {
printk(KERN_ERR "Unable to allocate memory for"
" dev->dev_status_queue_obj\n");
kfree(dev->dev_queue_obj);
kfree(dev);
return NULL;
}
transport_init_queue_obj(dev->dev_status_queue_obj);
dev->dev_flags = device_flags;
dev->dev_status |= TRANSPORT_DEVICE_DEACTIVATED;
dev->dev_ptr = (void *) transport_dev;
dev->se_hba = hba;
dev->se_sub_dev = se_dev;
dev->transport = transport;
atomic_set(&dev->active_cmds, 0);
INIT_LIST_HEAD(&dev->dev_list);
INIT_LIST_HEAD(&dev->dev_sep_list);
INIT_LIST_HEAD(&dev->dev_tmr_list);
INIT_LIST_HEAD(&dev->execute_task_list);
INIT_LIST_HEAD(&dev->delayed_cmd_list);
INIT_LIST_HEAD(&dev->ordered_cmd_list);
INIT_LIST_HEAD(&dev->state_task_list);
spin_lock_init(&dev->execute_task_lock);
spin_lock_init(&dev->delayed_cmd_lock);
spin_lock_init(&dev->ordered_cmd_lock);
spin_lock_init(&dev->state_task_lock);
spin_lock_init(&dev->dev_alua_lock);
spin_lock_init(&dev->dev_reservation_lock);
spin_lock_init(&dev->dev_status_lock);
spin_lock_init(&dev->dev_status_thr_lock);
spin_lock_init(&dev->se_port_lock);
spin_lock_init(&dev->se_tmr_lock);
dev->queue_depth = dev_limits->queue_depth;
atomic_set(&dev->depth_left, dev->queue_depth);
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
goto out;
dev->process_thread = kthread_run(transport_processing_thread, dev,
"LIO_%s", TRANSPORT(dev)->name);
if (IS_ERR(dev->process_thread)) {
printk(KERN_ERR "Unable to create kthread: LIO_%s\n",
TRANSPORT(dev)->name);
goto out;
}
if (TRANSPORT(dev)->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV) {
if (!(inquiry_prod) || !(inquiry_prod)) {
printk(KERN_ERR "All non TCM/pSCSI plugins require"
" INQUIRY consts\n");
goto out;
}
strncpy(&DEV_T10_WWN(dev)->vendor[0], "LIO-ORG", 8);
strncpy(&DEV_T10_WWN(dev)->model[0], inquiry_prod, 16);
strncpy(&DEV_T10_WWN(dev)->revision[0], inquiry_rev, 4);
}
scsi_dump_inquiry(dev);
return dev;
out:
kthread_stop(dev->process_thread);
spin_lock(&hba->device_lock);
list_del(&dev->dev_list);
hba->dev_count--;
spin_unlock(&hba->device_lock);
se_release_vpd_for_dev(dev);
kfree(dev->dev_status_queue_obj);
kfree(dev->dev_queue_obj);
kfree(dev);
return NULL;
}
static inline void transport_generic_prepare_cdb(
unsigned char *cdb)
{
switch (cdb[0]) {
case READ_10:
case READ_12:
case READ_16:
case SEND_DIAGNOSTIC:
case VERIFY:
case VERIFY_16:
case WRITE_VERIFY:
case WRITE_VERIFY_12:
break;
default:
cdb[1] &= 0x1f;
break;
}
}
static struct se_task *
transport_generic_get_task(struct se_cmd *cmd,
enum dma_data_direction data_direction)
{
struct se_task *task;
struct se_device *dev = SE_DEV(cmd);
unsigned long flags;
task = dev->transport->alloc_task(cmd);
if (!task) {
printk(KERN_ERR "Unable to allocate struct se_task\n");
return NULL;
}
INIT_LIST_HEAD(&task->t_list);
INIT_LIST_HEAD(&task->t_execute_list);
INIT_LIST_HEAD(&task->t_state_list);
init_completion(&task->task_stop_comp);
task->task_no = T_TASK(cmd)->t_tasks_no++;
task->task_se_cmd = cmd;
task->se_dev = dev;
task->task_data_direction = data_direction;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
list_add_tail(&task->t_list, &T_TASK(cmd)->t_task_list);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return task;
}
void transport_device_setup_cmd(struct se_cmd *cmd)
{
cmd->se_dev = SE_LUN(cmd)->lun_se_dev;
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
INIT_LIST_HEAD(&cmd->se_lun_list);
INIT_LIST_HEAD(&cmd->se_delayed_list);
INIT_LIST_HEAD(&cmd->se_ordered_list);
cmd->t_task = &cmd->t_task_backstore;
INIT_LIST_HEAD(&T_TASK(cmd)->t_task_list);
init_completion(&T_TASK(cmd)->transport_lun_fe_stop_comp);
init_completion(&T_TASK(cmd)->transport_lun_stop_comp);
init_completion(&T_TASK(cmd)->t_transport_stop_comp);
spin_lock_init(&T_TASK(cmd)->t_state_lock);
atomic_set(&T_TASK(cmd)->transport_dev_active, 1);
cmd->se_tfo = tfo;
cmd->se_sess = se_sess;
cmd->data_length = data_length;
cmd->data_direction = data_direction;
cmd->sam_task_attr = task_attr;
cmd->sense_buffer = sense_buffer;
}
static int transport_check_alloc_task_attr(struct se_cmd *cmd)
{
if (SE_DEV(cmd)->dev_task_attr_type != SAM_TASK_ATTR_EMULATED)
return 0;
if (cmd->sam_task_attr == MSG_ACA_TAG) {
DEBUG_STA("SAM Task Attribute ACA"
" emulation is not supported\n");
return -1;
}
cmd->se_ordered_id = atomic_inc_return(&SE_DEV(cmd)->dev_ordered_id);
smp_mb__after_atomic_inc();
DEBUG_STA("Allocated se_ordered_id: %u for Task Attr: 0x%02x on %s\n",
cmd->se_ordered_id, cmd->sam_task_attr,
TRANSPORT(cmd->se_dev)->name);
return 0;
}
void transport_free_se_cmd(
struct se_cmd *se_cmd)
{
if (se_cmd->se_tmr_req)
core_tmr_release_req(se_cmd->se_tmr_req);
if (T_TASK(se_cmd)->t_task_cdb != T_TASK(se_cmd)->__t_task_cdb)
kfree(T_TASK(se_cmd)->t_task_cdb);
}
int transport_generic_allocate_tasks(
struct se_cmd *cmd,
unsigned char *cdb)
{
int ret;
transport_generic_prepare_cdb(cdb);
cmd->transport_wait_for_tasks = &transport_generic_wait_for_tasks;
transport_device_setup_cmd(cmd);
if (scsi_command_size(cdb) > SCSI_MAX_VARLEN_CDB_SIZE) {
printk(KERN_ERR "Received SCSI CDB with command_size: %d that"
" exceeds SCSI_MAX_VARLEN_CDB_SIZE: %d\n",
scsi_command_size(cdb), SCSI_MAX_VARLEN_CDB_SIZE);
return -1;
}
if (scsi_command_size(cdb) > sizeof(T_TASK(cmd)->__t_task_cdb)) {
T_TASK(cmd)->t_task_cdb = kzalloc(scsi_command_size(cdb),
GFP_KERNEL);
if (!(T_TASK(cmd)->t_task_cdb)) {
printk(KERN_ERR "Unable to allocate T_TASK(cmd)->t_task_cdb"
" %u > sizeof(T_TASK(cmd)->__t_task_cdb): %lu ops\n",
scsi_command_size(cdb),
(unsigned long)sizeof(T_TASK(cmd)->__t_task_cdb));
return -1;
}
} else
T_TASK(cmd)->t_task_cdb = &T_TASK(cmd)->__t_task_cdb[0];
memcpy(T_TASK(cmd)->t_task_cdb, cdb, scsi_command_size(cdb));
ret = transport_generic_cmd_sequencer(cmd, cdb);
if (ret < 0)
return ret;
if (transport_check_alloc_task_attr(cmd) < 0) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -2;
}
spin_lock(&cmd->se_lun->lun_sep_lock);
if (cmd->se_lun->lun_sep)
cmd->se_lun->lun_sep->sep_stats.cmd_pdus++;
spin_unlock(&cmd->se_lun->lun_sep_lock);
return 0;
}
int transport_generic_handle_cdb(
struct se_cmd *cmd)
{
if (!SE_LUN(cmd)) {
dump_stack();
printk(KERN_ERR "SE_LUN(cmd) is NULL\n");
return -1;
}
transport_add_cmd_to_queue(cmd, TRANSPORT_NEW_CMD);
return 0;
}
int transport_generic_handle_cdb_map(
struct se_cmd *cmd)
{
if (!SE_LUN(cmd)) {
dump_stack();
printk(KERN_ERR "SE_LUN(cmd) is NULL\n");
return -1;
}
transport_add_cmd_to_queue(cmd, TRANSPORT_NEW_CMD_MAP);
return 0;
}
int transport_generic_handle_data(
struct se_cmd *cmd)
{
if (!in_interrupt() && signal_pending(current))
return -1;
if (transport_check_aborted_status(cmd, 1) != 0)
return 0;
transport_add_cmd_to_queue(cmd, TRANSPORT_PROCESS_WRITE);
return 0;
}
int transport_generic_handle_tmr(
struct se_cmd *cmd)
{
cmd->transport_wait_for_tasks = &transport_generic_wait_for_tasks;
transport_device_setup_cmd(cmd);
transport_add_cmd_to_queue(cmd, TRANSPORT_PROCESS_TMR);
return 0;
}
void transport_generic_free_cmd_intr(
struct se_cmd *cmd)
{
transport_add_cmd_to_queue(cmd, TRANSPORT_FREE_CMD_INTR);
}
static int transport_stop_tasks_for_cmd(struct se_cmd *cmd)
{
struct se_task *task, *task_tmp;
unsigned long flags;
int ret = 0;
DEBUG_TS("ITT[0x%08x] - Stopping tasks\n",
CMD_TFO(cmd)->get_task_tag(cmd));
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
list_for_each_entry_safe(task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list) {
DEBUG_TS("task_no[%d] - Processing task %p\n",
task->task_no, task);
if (!atomic_read(&task->task_sent) &&
!atomic_read(&task->task_active)) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
flags);
transport_remove_task_from_execute_queue(task,
task->se_dev);
DEBUG_TS("task_no[%d] - Removed from execute queue\n",
task->task_no);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
continue;
}
if (atomic_read(&task->task_active)) {
atomic_set(&task->task_stop, 1);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
flags);
DEBUG_TS("task_no[%d] - Waiting to complete\n",
task->task_no);
wait_for_completion(&task->task_stop_comp);
DEBUG_TS("task_no[%d] - Stopped successfully\n",
task->task_no);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
atomic_dec(&T_TASK(cmd)->t_task_cdbs_left);
atomic_set(&task->task_active, 0);
atomic_set(&task->task_stop, 0);
} else {
DEBUG_TS("task_no[%d] - Did nothing\n", task->task_no);
ret++;
}
__transport_stop_task_timer(task, &flags);
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return ret;
}
static void transport_failure_reset_queue_depth(struct se_device *dev)
{
unsigned long flags;
spin_lock_irqsave(&SE_HBA(dev)->hba_queue_lock, flags);
atomic_inc(&dev->depth_left);
atomic_inc(&SE_HBA(dev)->left_queue_depth);
spin_unlock_irqrestore(&SE_HBA(dev)->hba_queue_lock, flags);
}
static void transport_generic_request_failure(
struct se_cmd *cmd,
struct se_device *dev,
int complete,
int sc)
{
DEBUG_GRF("-----[ Storage Engine Exception for cmd: %p ITT: 0x%08x"
" CDB: 0x%02x\n", cmd, CMD_TFO(cmd)->get_task_tag(cmd),
T_TASK(cmd)->t_task_cdb[0]);
DEBUG_GRF("-----[ i_state: %d t_state/def_t_state:"
" %d/%d transport_error_status: %d\n",
CMD_TFO(cmd)->get_cmd_state(cmd),
cmd->t_state, cmd->deferred_t_state,
cmd->transport_error_status);
DEBUG_GRF("-----[ t_task_cdbs: %d t_task_cdbs_left: %d"
" t_task_cdbs_sent: %d t_task_cdbs_ex_left: %d --"
" t_transport_active: %d t_transport_stop: %d"
" t_transport_sent: %d\n", T_TASK(cmd)->t_task_cdbs,
atomic_read(&T_TASK(cmd)->t_task_cdbs_left),
atomic_read(&T_TASK(cmd)->t_task_cdbs_sent),
atomic_read(&T_TASK(cmd)->t_task_cdbs_ex_left),
atomic_read(&T_TASK(cmd)->t_transport_active),
atomic_read(&T_TASK(cmd)->t_transport_stop),
atomic_read(&T_TASK(cmd)->t_transport_sent));
transport_stop_all_task_timers(cmd);
if (dev)
transport_failure_reset_queue_depth(dev);
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
transport_complete_task_attr(cmd);
if (complete) {
transport_direct_request_timeout(cmd);
cmd->transport_error_status = PYX_TRANSPORT_LU_COMM_FAILURE;
}
switch (cmd->transport_error_status) {
case PYX_TRANSPORT_UNKNOWN_SAM_OPCODE:
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
break;
case PYX_TRANSPORT_REQ_TOO_MANY_SECTORS:
cmd->scsi_sense_reason = TCM_SECTOR_COUNT_TOO_MANY;
break;
case PYX_TRANSPORT_INVALID_CDB_FIELD:
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
break;
case PYX_TRANSPORT_INVALID_PARAMETER_LIST:
cmd->scsi_sense_reason = TCM_INVALID_PARAMETER_LIST;
break;
case PYX_TRANSPORT_OUT_OF_MEMORY_RESOURCES:
if (!sc)
transport_new_cmd_failure(cmd);
CMD_TFO(cmd)->fall_back_to_erl0(cmd->se_sess);
CMD_TFO(cmd)->stop_session(cmd->se_sess, 0, 0);
goto check_stop;
case PYX_TRANSPORT_LU_COMM_FAILURE:
case PYX_TRANSPORT_ILLEGAL_REQUEST:
cmd->scsi_sense_reason = TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
break;
case PYX_TRANSPORT_UNKNOWN_MODE_PAGE:
cmd->scsi_sense_reason = TCM_UNKNOWN_MODE_PAGE;
break;
case PYX_TRANSPORT_WRITE_PROTECTED:
cmd->scsi_sense_reason = TCM_WRITE_PROTECTED;
break;
case PYX_TRANSPORT_RESERVATION_CONFLICT:
cmd->scsi_status = SAM_STAT_RESERVATION_CONFLICT;
if (SE_SESS(cmd) &&
DEV_ATTRIB(cmd->se_dev)->emulate_ua_intlck_ctrl == 2)
core_scsi3_ua_allocate(SE_SESS(cmd)->se_node_acl,
cmd->orig_fe_lun, 0x2C,
ASCQ_2CH_PREVIOUS_RESERVATION_CONFLICT_STATUS);
CMD_TFO(cmd)->queue_status(cmd);
goto check_stop;
case PYX_TRANSPORT_USE_SENSE_REASON:
break;
default:
printk(KERN_ERR "Unknown transport error for CDB 0x%02x: %d\n",
T_TASK(cmd)->t_task_cdb[0],
cmd->transport_error_status);
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
break;
}
if (!sc)
transport_new_cmd_failure(cmd);
else
transport_send_check_condition_and_sense(cmd,
cmd->scsi_sense_reason, 0);
check_stop:
transport_lun_remove_cmd(cmd);
if (!(transport_cmd_check_stop_to_fabric(cmd)))
;
}
static void transport_direct_request_timeout(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (!(atomic_read(&T_TASK(cmd)->t_transport_timeout))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return;
}
if (atomic_read(&T_TASK(cmd)->t_task_cdbs_timeout_left)) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return;
}
atomic_sub(atomic_read(&T_TASK(cmd)->t_transport_timeout),
&T_TASK(cmd)->t_se_count);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
}
static void transport_generic_request_timeout(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (atomic_read(&T_TASK(cmd)->t_transport_timeout) > 1) {
int tmp = (atomic_read(&T_TASK(cmd)->t_transport_timeout) - 1);
atomic_sub(tmp, &T_TASK(cmd)->t_se_count);
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_generic_remove(cmd, 0, 0);
}
static int
transport_generic_allocate_buf(struct se_cmd *cmd, u32 data_length)
{
unsigned char *buf;
buf = kzalloc(data_length, GFP_KERNEL);
if (!(buf)) {
printk(KERN_ERR "Unable to allocate memory for buffer\n");
return -1;
}
T_TASK(cmd)->t_tasks_se_num = 0;
T_TASK(cmd)->t_task_buf = buf;
return 0;
}
static inline u32 transport_lba_21(unsigned char *cdb)
{
return ((cdb[1] & 0x1f) << 16) | (cdb[2] << 8) | cdb[3];
}
static inline u32 transport_lba_32(unsigned char *cdb)
{
return (cdb[2] << 24) | (cdb[3] << 16) | (cdb[4] << 8) | cdb[5];
}
static inline unsigned long long transport_lba_64(unsigned char *cdb)
{
unsigned int __v1, __v2;
__v1 = (cdb[2] << 24) | (cdb[3] << 16) | (cdb[4] << 8) | cdb[5];
__v2 = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
return ((unsigned long long)__v2) | (unsigned long long)__v1 << 32;
}
static inline unsigned long long transport_lba_64_ext(unsigned char *cdb)
{
unsigned int __v1, __v2;
__v1 = (cdb[12] << 24) | (cdb[13] << 16) | (cdb[14] << 8) | cdb[15];
__v2 = (cdb[16] << 24) | (cdb[17] << 16) | (cdb[18] << 8) | cdb[19];
return ((unsigned long long)__v2) | (unsigned long long)__v1 << 32;
}
static void transport_set_supported_SAM_opcode(struct se_cmd *se_cmd)
{
unsigned long flags;
spin_lock_irqsave(&T_TASK(se_cmd)->t_state_lock, flags);
se_cmd->se_cmd_flags |= SCF_SUPPORTED_SAM_OPCODE;
spin_unlock_irqrestore(&T_TASK(se_cmd)->t_state_lock, flags);
}
static void transport_task_timeout_handler(unsigned long data)
{
struct se_task *task = (struct se_task *)data;
struct se_cmd *cmd = TASK_CMD(task);
unsigned long flags;
DEBUG_TT("transport task timeout fired! task: %p cmd: %p\n", task, cmd);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (task->task_flags & TF_STOP) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return;
}
task->task_flags &= ~TF_RUNNING;
if (!(atomic_read(&task->task_active))) {
DEBUG_TT("transport task: %p cmd: %p timeout task_active"
" == 0\n", task, cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return;
}
atomic_inc(&T_TASK(cmd)->t_se_count);
atomic_inc(&T_TASK(cmd)->t_transport_timeout);
T_TASK(cmd)->t_tasks_failed = 1;
atomic_set(&task->task_timeout, 1);
task->task_error_status = PYX_TRANSPORT_TASK_TIMEOUT;
task->task_scsi_status = 1;
if (atomic_read(&task->task_stop)) {
DEBUG_TT("transport task: %p cmd: %p timeout task_stop"
" == 1\n", task, cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
complete(&task->task_stop_comp);
return;
}
if (!(atomic_dec_and_test(&T_TASK(cmd)->t_task_cdbs_left))) {
DEBUG_TT("transport task: %p cmd: %p timeout non zero"
" t_task_cdbs_left\n", task, cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return;
}
DEBUG_TT("transport task: %p cmd: %p timeout ZERO t_task_cdbs_left\n",
task, cmd);
cmd->t_state = TRANSPORT_COMPLETE_FAILURE;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_add_cmd_to_queue(cmd, TRANSPORT_COMPLETE_FAILURE);
}
static void transport_start_task_timer(struct se_task *task)
{
struct se_device *dev = task->se_dev;
int timeout;
if (task->task_flags & TF_RUNNING)
return;
timeout = DEV_ATTRIB(dev)->task_timeout;
if (!(timeout))
return;
init_timer(&task->task_timer);
task->task_timer.expires = (get_jiffies_64() + timeout * HZ);
task->task_timer.data = (unsigned long) task;
task->task_timer.function = transport_task_timeout_handler;
task->task_flags |= TF_RUNNING;
add_timer(&task->task_timer);
#if 0
printk(KERN_INFO "Starting task timer for cmd: %p task: %p seconds:"
" %d\n", task->task_se_cmd, task, timeout);
#endif
}
void __transport_stop_task_timer(struct se_task *task, unsigned long *flags)
{
struct se_cmd *cmd = TASK_CMD(task);
if (!(task->task_flags & TF_RUNNING))
return;
task->task_flags |= TF_STOP;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, *flags);
del_timer_sync(&task->task_timer);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, *flags);
task->task_flags &= ~TF_RUNNING;
task->task_flags &= ~TF_STOP;
}
static void transport_stop_all_task_timers(struct se_cmd *cmd)
{
struct se_task *task = NULL, *task_tmp;
unsigned long flags;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
list_for_each_entry_safe(task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list)
__transport_stop_task_timer(task, &flags);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
}
static inline int transport_tcq_window_closed(struct se_device *dev)
{
if (dev->dev_tcq_window_closed++ <
PYX_TRANSPORT_WINDOW_CLOSED_THRESHOLD) {
msleep(PYX_TRANSPORT_WINDOW_CLOSED_WAIT_SHORT);
} else
msleep(PYX_TRANSPORT_WINDOW_CLOSED_WAIT_LONG);
wake_up_interruptible(&dev->dev_queue_obj->thread_wq);
return 0;
}
static inline int transport_execute_task_attr(struct se_cmd *cmd)
{
if (SE_DEV(cmd)->dev_task_attr_type != SAM_TASK_ATTR_EMULATED)
return 1;
if (cmd->sam_task_attr == MSG_HEAD_TAG) {
atomic_inc(&SE_DEV(cmd)->dev_hoq_count);
smp_mb__after_atomic_inc();
DEBUG_STA("Added HEAD_OF_QUEUE for CDB:"
" 0x%02x, se_ordered_id: %u\n",
T_TASK(cmd)->t_task_cdb[0],
cmd->se_ordered_id);
return 1;
} else if (cmd->sam_task_attr == MSG_ORDERED_TAG) {
spin_lock(&SE_DEV(cmd)->ordered_cmd_lock);
list_add_tail(&cmd->se_ordered_list,
&SE_DEV(cmd)->ordered_cmd_list);
spin_unlock(&SE_DEV(cmd)->ordered_cmd_lock);
atomic_inc(&SE_DEV(cmd)->dev_ordered_sync);
smp_mb__after_atomic_inc();
DEBUG_STA("Added ORDERED for CDB: 0x%02x to ordered"
" list, se_ordered_id: %u\n",
T_TASK(cmd)->t_task_cdb[0],
cmd->se_ordered_id);
if (!(atomic_read(&SE_DEV(cmd)->simple_cmds)))
return 1;
} else {
atomic_inc(&SE_DEV(cmd)->simple_cmds);
smp_mb__after_atomic_inc();
}
if (atomic_read(&SE_DEV(cmd)->dev_ordered_sync) != 0) {
spin_lock(&SE_DEV(cmd)->delayed_cmd_lock);
cmd->se_cmd_flags |= SCF_DELAYED_CMD_FROM_SAM_ATTR;
list_add_tail(&cmd->se_delayed_list,
&SE_DEV(cmd)->delayed_cmd_list);
spin_unlock(&SE_DEV(cmd)->delayed_cmd_lock);
DEBUG_STA("Added CDB: 0x%02x Task Attr: 0x%02x to"
" delayed CMD list, se_ordered_id: %u\n",
T_TASK(cmd)->t_task_cdb[0], cmd->sam_task_attr,
cmd->se_ordered_id);
return 0;
}
return 1;
}
static int transport_execute_tasks(struct se_cmd *cmd)
{
int add_tasks;
if (!(cmd->se_cmd_flags & SCF_SE_DISABLE_ONLINE_CHECK)) {
if (se_dev_check_online(cmd->se_orig_obj_ptr) != 0) {
cmd->transport_error_status =
PYX_TRANSPORT_LU_COMM_FAILURE;
transport_generic_request_failure(cmd, NULL, 0, 1);
return 0;
}
}
if (!(transport_cmd_check_stop(cmd, 0, TRANSPORT_PROCESSING))) {
add_tasks = transport_execute_task_attr(cmd);
if (add_tasks == 0)
goto execute_tasks;
transport_add_tasks_from_cmd(cmd);
}
execute_tasks:
__transport_execute_tasks(SE_DEV(cmd));
return 0;
}
static int __transport_execute_tasks(struct se_device *dev)
{
int error;
struct se_cmd *cmd = NULL;
struct se_task *task;
unsigned long flags;
check_depth:
spin_lock_irqsave(&SE_HBA(dev)->hba_queue_lock, flags);
if (!(atomic_read(&dev->depth_left)) ||
!(atomic_read(&SE_HBA(dev)->left_queue_depth))) {
spin_unlock_irqrestore(&SE_HBA(dev)->hba_queue_lock, flags);
return transport_tcq_window_closed(dev);
}
dev->dev_tcq_window_closed = 0;
spin_lock(&dev->execute_task_lock);
task = transport_get_task_from_execute_queue(dev);
spin_unlock(&dev->execute_task_lock);
if (!task) {
spin_unlock_irqrestore(&SE_HBA(dev)->hba_queue_lock, flags);
return 0;
}
atomic_dec(&dev->depth_left);
atomic_dec(&SE_HBA(dev)->left_queue_depth);
spin_unlock_irqrestore(&SE_HBA(dev)->hba_queue_lock, flags);
cmd = TASK_CMD(task);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
atomic_set(&task->task_active, 1);
atomic_set(&task->task_sent, 1);
atomic_inc(&T_TASK(cmd)->t_task_cdbs_sent);
if (atomic_read(&T_TASK(cmd)->t_task_cdbs_sent) ==
T_TASK(cmd)->t_task_cdbs)
atomic_set(&cmd->transport_sent, 1);
transport_start_task_timer(task);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
if (cmd->transport_emulate_cdb) {
error = cmd->transport_emulate_cdb(cmd);
if (error != 0) {
cmd->transport_error_status = error;
atomic_set(&task->task_active, 0);
atomic_set(&cmd->transport_sent, 0);
transport_stop_tasks_for_cmd(cmd);
transport_generic_request_failure(cmd, dev, 0, 1);
goto check_depth;
}
if (!(cmd->se_cmd_flags & SCF_EMULATE_CDB_ASYNC)) {
cmd->scsi_status = SAM_STAT_GOOD;
task->task_scsi_status = GOOD;
transport_complete_task(task, 1);
}
} else {
if ((TRANSPORT(dev)->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV) &&
(!(TASK_CMD(task)->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB)))
error = transport_emulate_control_cdb(task);
else
error = TRANSPORT(dev)->do_task(task);
if (error != 0) {
cmd->transport_error_status = error;
atomic_set(&task->task_active, 0);
atomic_set(&cmd->transport_sent, 0);
transport_stop_tasks_for_cmd(cmd);
transport_generic_request_failure(cmd, dev, 0, 1);
}
}
goto check_depth;
return 0;
}
void transport_new_cmd_failure(struct se_cmd *se_cmd)
{
unsigned long flags;
spin_lock_irqsave(&T_TASK(se_cmd)->t_state_lock, flags);
se_cmd->se_cmd_flags |= SCF_SE_CMD_FAILED;
se_cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
spin_unlock_irqrestore(&T_TASK(se_cmd)->t_state_lock, flags);
CMD_TFO(se_cmd)->new_cmd_failure(se_cmd);
}
static inline u32 transport_get_sectors_6(
unsigned char *cdb,
struct se_cmd *cmd,
int *ret)
{
struct se_device *dev = SE_LUN(cmd)->lun_se_dev;
if (!dev)
goto type_disk;
if (TRANSPORT(dev)->get_device_type(dev) == TYPE_TAPE)
return (u32)(cdb[2] << 16) + (cdb[3] << 8) + cdb[4];
type_disk:
return (u32)cdb[4];
}
static inline u32 transport_get_sectors_10(
unsigned char *cdb,
struct se_cmd *cmd,
int *ret)
{
struct se_device *dev = SE_LUN(cmd)->lun_se_dev;
if (!dev)
goto type_disk;
if (TRANSPORT(dev)->get_device_type(dev) == TYPE_TAPE) {
*ret = -1;
return 0;
}
type_disk:
return (u32)(cdb[7] << 8) + cdb[8];
}
static inline u32 transport_get_sectors_12(
unsigned char *cdb,
struct se_cmd *cmd,
int *ret)
{
struct se_device *dev = SE_LUN(cmd)->lun_se_dev;
if (!dev)
goto type_disk;
if (TRANSPORT(dev)->get_device_type(dev) == TYPE_TAPE) {
*ret = -1;
return 0;
}
type_disk:
return (u32)(cdb[6] << 24) + (cdb[7] << 16) + (cdb[8] << 8) + cdb[9];
}
static inline u32 transport_get_sectors_16(
unsigned char *cdb,
struct se_cmd *cmd,
int *ret)
{
struct se_device *dev = SE_LUN(cmd)->lun_se_dev;
if (!dev)
goto type_disk;
if (TRANSPORT(dev)->get_device_type(dev) == TYPE_TAPE)
return (u32)(cdb[12] << 16) + (cdb[13] << 8) + cdb[14];
type_disk:
return (u32)(cdb[10] << 24) + (cdb[11] << 16) +
(cdb[12] << 8) + cdb[13];
}
static inline u32 transport_get_sectors_32(
unsigned char *cdb,
struct se_cmd *cmd,
int *ret)
{
return (u32)(cdb[28] << 24) + (cdb[29] << 16) +
(cdb[30] << 8) + cdb[31];
}
static inline u32 transport_get_size(
u32 sectors,
unsigned char *cdb,
struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
if (TRANSPORT(dev)->get_device_type(dev) == TYPE_TAPE) {
if (cdb[1] & 1) {
return DEV_ATTRIB(dev)->block_size * sectors;
} else
return sectors;
}
#if 0
printk(KERN_INFO "Returning block_size: %u, sectors: %u == %u for"
" %s object\n", DEV_ATTRIB(dev)->block_size, sectors,
DEV_ATTRIB(dev)->block_size * sectors,
TRANSPORT(dev)->name);
#endif
return DEV_ATTRIB(dev)->block_size * sectors;
}
unsigned char transport_asciihex_to_binaryhex(unsigned char val[2])
{
unsigned char result = 0;
if ((val[0] >= 'a') && (val[0] <= 'f'))
result = ((val[0] - 'a' + 10) & 0xf) << 4;
else
if ((val[0] >= 'A') && (val[0] <= 'F'))
result = ((val[0] - 'A' + 10) & 0xf) << 4;
else
result = ((val[0] - '0') & 0xf) << 4;
if ((val[1] >= 'a') && (val[1] <= 'f'))
result |= ((val[1] - 'a' + 10) & 0xf);
else
if ((val[1] >= 'A') && (val[1] <= 'F'))
result |= ((val[1] - 'A' + 10) & 0xf);
else
result |= ((val[1] - '0') & 0xf);
return result;
}
static void transport_xor_callback(struct se_cmd *cmd)
{
unsigned char *buf, *addr;
struct se_mem *se_mem;
unsigned int offset;
int i;
buf = kmalloc(cmd->data_length, GFP_KERNEL);
if (!(buf)) {
printk(KERN_ERR "Unable to allocate xor_callback buf\n");
return;
}
transport_memcpy_se_mem_read_contig(cmd, buf, T_TASK(cmd)->t_mem_list);
offset = 0;
list_for_each_entry(se_mem, T_TASK(cmd)->t_mem_bidi_list, se_list) {
addr = (unsigned char *)kmap_atomic(se_mem->se_page, KM_USER0);
if (!(addr))
goto out;
for (i = 0; i < se_mem->se_len; i++)
*(addr + se_mem->se_off + i) ^= *(buf + offset + i);
offset += se_mem->se_len;
kunmap_atomic(addr, KM_USER0);
}
out:
kfree(buf);
}
static int transport_get_sense_data(struct se_cmd *cmd)
{
unsigned char *buffer = cmd->sense_buffer, *sense_buffer = NULL;
struct se_device *dev;
struct se_task *task = NULL, *task_tmp;
unsigned long flags;
u32 offset = 0;
if (!SE_LUN(cmd)) {
printk(KERN_ERR "SE_LUN(cmd) is NULL\n");
return -1;
}
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (cmd->se_cmd_flags & SCF_SENT_CHECK_CONDITION) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return 0;
}
list_for_each_entry_safe(task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list) {
if (!task->task_sense)
continue;
dev = task->se_dev;
if (!(dev))
continue;
if (!TRANSPORT(dev)->get_sense_buffer) {
printk(KERN_ERR "TRANSPORT(dev)->get_sense_buffer"
" is NULL\n");
continue;
}
sense_buffer = TRANSPORT(dev)->get_sense_buffer(task);
if (!(sense_buffer)) {
printk(KERN_ERR "ITT[0x%08x]_TASK[%d]: Unable to locate"
" sense buffer for task with sense\n",
CMD_TFO(cmd)->get_task_tag(cmd), task->task_no);
continue;
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
offset = CMD_TFO(cmd)->set_fabric_sense_len(cmd,
TRANSPORT_SENSE_BUFFER);
memcpy((void *)&buffer[offset], (void *)sense_buffer,
TRANSPORT_SENSE_BUFFER);
cmd->scsi_status = task->task_scsi_status;
cmd->scsi_sense_length =
(TRANSPORT_SENSE_BUFFER + offset);
printk(KERN_INFO "HBA_[%u]_PLUG[%s]: Set SAM STATUS: 0x%02x"
" and sense\n",
dev->se_hba->hba_id, TRANSPORT(dev)->name,
cmd->scsi_status);
return 0;
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return -1;
}
static int transport_allocate_resources(struct se_cmd *cmd)
{
u32 length = cmd->data_length;
if ((cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB) ||
(cmd->se_cmd_flags & SCF_SCSI_CONTROL_SG_IO_CDB))
return transport_generic_get_mem(cmd, length, PAGE_SIZE);
else if (cmd->se_cmd_flags & SCF_SCSI_CONTROL_NONSG_IO_CDB)
return transport_generic_allocate_buf(cmd, length);
else
return 0;
}
static int
transport_handle_reservation_conflict(struct se_cmd *cmd)
{
cmd->transport_wait_for_tasks = &transport_nop_wait_for_tasks;
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->se_cmd_flags |= SCF_SCSI_RESERVATION_CONFLICT;
cmd->scsi_status = SAM_STAT_RESERVATION_CONFLICT;
if (SE_SESS(cmd) &&
DEV_ATTRIB(cmd->se_dev)->emulate_ua_intlck_ctrl == 2)
core_scsi3_ua_allocate(SE_SESS(cmd)->se_node_acl,
cmd->orig_fe_lun, 0x2C,
ASCQ_2CH_PREVIOUS_RESERVATION_CONFLICT_STATUS);
return -2;
}
static int transport_generic_cmd_sequencer(
struct se_cmd *cmd,
unsigned char *cdb)
{
struct se_device *dev = SE_DEV(cmd);
struct se_subsystem_dev *su_dev = dev->se_sub_dev;
int ret = 0, sector_ret = 0, passthrough;
u32 sectors = 0, size = 0, pr_reg_type = 0;
u16 service_action;
u8 alua_ascq = 0;
if (core_scsi3_ua_check(cmd, cdb) < 0) {
cmd->transport_wait_for_tasks =
&transport_nop_wait_for_tasks;
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_CHECK_CONDITION_UNIT_ATTENTION;
return -2;
}
ret = T10_ALUA(su_dev)->alua_state_check(cmd, cdb, &alua_ascq);
if (ret != 0) {
cmd->transport_wait_for_tasks = &transport_nop_wait_for_tasks;
if (ret > 0) {
#if 0
printk(KERN_INFO "[%s]: ALUA TG Port not available,"
" SenseKey: NOT_READY, ASC/ASCQ: 0x04/0x%02x\n",
CMD_TFO(cmd)->get_fabric_name(), alua_ascq);
#endif
transport_set_sense_codes(cmd, 0x04, alua_ascq);
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_CHECK_CONDITION_NOT_READY;
return -2;
}
goto out_invalid_cdb_field;
}
if (T10_PR_OPS(su_dev)->t10_reservation_check(cmd, &pr_reg_type) != 0) {
if (T10_PR_OPS(su_dev)->t10_seq_non_holder(
cmd, cdb, pr_reg_type) != 0)
return transport_handle_reservation_conflict(cmd);
}
switch (cdb[0]) {
case READ_6:
sectors = transport_get_sectors_6(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_6;
T_TASK(cmd)->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case READ_10:
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_10;
T_TASK(cmd)->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case READ_12:
sectors = transport_get_sectors_12(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_12;
T_TASK(cmd)->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case READ_16:
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_16;
T_TASK(cmd)->t_task_lba = transport_lba_64(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_6:
sectors = transport_get_sectors_6(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_6;
T_TASK(cmd)->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_10:
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_10;
T_TASK(cmd)->t_task_lba = transport_lba_32(cdb);
T_TASK(cmd)->t_tasks_fua = (cdb[1] & 0x8);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_12:
sectors = transport_get_sectors_12(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_12;
T_TASK(cmd)->t_task_lba = transport_lba_32(cdb);
T_TASK(cmd)->t_tasks_fua = (cdb[1] & 0x8);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_16:
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_16;
T_TASK(cmd)->t_task_lba = transport_lba_64(cdb);
T_TASK(cmd)->t_tasks_fua = (cdb[1] & 0x8);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case XDWRITEREAD_10:
if ((cmd->data_direction != DMA_TO_DEVICE) ||
!(T_TASK(cmd)->t_tasks_bidi))
goto out_invalid_cdb_field;
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_10;
T_TASK(cmd)->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
passthrough = (TRANSPORT(dev)->transport_type ==
TRANSPORT_PLUGIN_PHBA_PDEV);
if (passthrough)
break;
cmd->transport_complete_callback = &transport_xor_callback;
T_TASK(cmd)->t_tasks_fua = (cdb[1] & 0x8);
break;
case VARIABLE_LENGTH_CMD:
service_action = get_unaligned_be16(&cdb[8]);
passthrough = (TRANSPORT(dev)->transport_type ==
TRANSPORT_PLUGIN_PHBA_PDEV);
switch (service_action) {
case XDWRITEREAD_32:
sectors = transport_get_sectors_32(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_32;
T_TASK(cmd)->t_task_lba = transport_lba_64_ext(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
if (passthrough)
break;
cmd->transport_complete_callback = &transport_xor_callback;
T_TASK(cmd)->t_tasks_fua = (cdb[10] & 0x8);
break;
case WRITE_SAME_32:
sectors = transport_get_sectors_32(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
T_TASK(cmd)->t_task_lba = get_unaligned_be64(&cdb[12]);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
if (passthrough)
break;
if ((cdb[10] & 0x04) || (cdb[10] & 0x02)) {
printk(KERN_ERR "WRITE_SAME PBDATA and LBDATA"
" bits not supported for Block Discard"
" Emulation\n");
goto out_invalid_cdb_field;
}
if (!(cdb[10] & 0x08)) {
printk(KERN_ERR "WRITE_SAME w/o UNMAP bit not"
" supported for Block Discard Emulation\n");
goto out_invalid_cdb_field;
}
break;
default:
printk(KERN_ERR "VARIABLE_LENGTH_CMD service action"
" 0x%04x not supported\n", service_action);
goto out_unsupported_cdb;
}
break;
case 0xa3:
if (TRANSPORT(dev)->get_device_type(dev) != TYPE_ROM) {
if (cdb[1] == MI_REPORT_TARGET_PGS) {
cmd->transport_emulate_cdb =
(T10_ALUA(su_dev)->alua_type ==
SPC3_ALUA_EMULATED) ?
&core_emulate_report_target_port_groups :
NULL;
}
size = (cdb[6] << 24) | (cdb[7] << 16) |
(cdb[8] << 8) | cdb[9];
} else {
size = (cdb[8] << 8) + cdb[9];
}
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case MODE_SELECT:
size = cdb[4];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case MODE_SELECT_10:
size = (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case MODE_SENSE:
size = cdb[4];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case MODE_SENSE_10:
case GPCMD_READ_BUFFER_CAPACITY:
case GPCMD_SEND_OPC:
case LOG_SELECT:
case LOG_SENSE:
size = (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case READ_BLOCK_LIMITS:
size = READ_BLOCK_LEN;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case GPCMD_GET_CONFIGURATION:
case GPCMD_READ_FORMAT_CAPACITIES:
case GPCMD_READ_DISC_INFO:
case GPCMD_READ_TRACK_RZONE_INFO:
size = (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case PERSISTENT_RESERVE_IN:
case PERSISTENT_RESERVE_OUT:
cmd->transport_emulate_cdb =
(T10_RES(su_dev)->res_type ==
SPC3_PERSISTENT_RESERVATIONS) ?
&core_scsi3_emulate_pr : NULL;
size = (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case GPCMD_MECHANISM_STATUS:
case GPCMD_READ_DVD_STRUCTURE:
size = (cdb[8] << 8) + cdb[9];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case READ_POSITION:
size = READ_POSITION_LEN;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case 0xa4:
if (TRANSPORT(dev)->get_device_type(dev) != TYPE_ROM) {
if (cdb[1] == MO_SET_TARGET_PGS) {
cmd->transport_emulate_cdb =
(T10_ALUA(su_dev)->alua_type ==
SPC3_ALUA_EMULATED) ?
&core_emulate_set_target_port_groups :
NULL;
}
size = (cdb[6] << 24) | (cdb[7] << 16) |
(cdb[8] << 8) | cdb[9];
} else {
size = (cdb[8] << 8) + cdb[9];
}
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case INQUIRY:
size = (cdb[3] << 8) + cdb[4];
if (SE_DEV(cmd)->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
cmd->sam_task_attr = MSG_HEAD_TAG;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case READ_BUFFER:
size = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case READ_CAPACITY:
size = READ_CAP_LEN;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case READ_MEDIA_SERIAL_NUMBER:
case SECURITY_PROTOCOL_IN:
case SECURITY_PROTOCOL_OUT:
size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case SERVICE_ACTION_IN:
case ACCESS_CONTROL_IN:
case ACCESS_CONTROL_OUT:
case EXTENDED_COPY:
case READ_ATTRIBUTE:
case RECEIVE_COPY_RESULTS:
case WRITE_ATTRIBUTE:
size = (cdb[10] << 24) | (cdb[11] << 16) |
(cdb[12] << 8) | cdb[13];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case RECEIVE_DIAGNOSTIC:
case SEND_DIAGNOSTIC:
size = (cdb[3] << 8) | cdb[4];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
#endif
case READ_TOC:
size = cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case REQUEST_SENSE:
size = cdb[4];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case READ_ELEMENT_STATUS:
size = 65536 * cdb[7] + 256 * cdb[8] + cdb[9];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case WRITE_BUFFER:
size = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case RESERVE:
case RESERVE_10:
if (cdb[0] == RESERVE_10)
size = (cdb[7] << 8) | cdb[8];
else
size = cmd->data_length;
cmd->transport_emulate_cdb =
(T10_RES(su_dev)->res_type !=
SPC_PASSTHROUGH) ?
&core_scsi2_emulate_crh : NULL;
cmd->se_cmd_flags |= SCF_SCSI_NON_DATA_CDB;
break;
case RELEASE:
case RELEASE_10:
if (cdb[0] == RELEASE_10)
size = (cdb[7] << 8) | cdb[8];
else
size = cmd->data_length;
cmd->transport_emulate_cdb =
(T10_RES(su_dev)->res_type !=
SPC_PASSTHROUGH) ?
&core_scsi2_emulate_crh : NULL;
cmd->se_cmd_flags |= SCF_SCSI_NON_DATA_CDB;
break;
case SYNCHRONIZE_CACHE:
case 0x91:
if (cdb[0] == SYNCHRONIZE_CACHE) {
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
T_TASK(cmd)->t_task_lba = transport_lba_32(cdb);
} else {
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
T_TASK(cmd)->t_task_lba = transport_lba_64(cdb);
}
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->se_cmd_flags |= SCF_SCSI_NON_DATA_CDB;
if (TRANSPORT(dev)->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV)
break;
cmd->se_cmd_flags |= SCF_EMULATE_CDB_ASYNC;
if (transport_get_sectors(cmd) < 0)
goto out_invalid_cdb_field;
break;
case UNMAP:
size = get_unaligned_be16(&cdb[7]);
passthrough = (TRANSPORT(dev)->transport_type ==
TRANSPORT_PLUGIN_PHBA_PDEV);
if (!(passthrough))
cmd->se_cmd_flags |= SCF_EMULATE_SYNC_UNMAP;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
case WRITE_SAME_16:
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
T_TASK(cmd)->t_task_lba = get_unaligned_be16(&cdb[2]);
passthrough = (TRANSPORT(dev)->transport_type ==
TRANSPORT_PLUGIN_PHBA_PDEV);
if (!(passthrough)) {
if ((cdb[1] & 0x04) || (cdb[1] & 0x02)) {
printk(KERN_ERR "WRITE_SAME PBDATA and LBDATA"
" bits not supported for Block Discard"
" Emulation\n");
goto out_invalid_cdb_field;
}
if (!(cdb[1] & 0x08)) {
printk(KERN_ERR "WRITE_SAME w/o UNMAP bit not "
" supported for Block Discard Emulation\n");
goto out_invalid_cdb_field;
}
}
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case ALLOW_MEDIUM_REMOVAL:
case GPCMD_CLOSE_TRACK:
case ERASE:
case INITIALIZE_ELEMENT_STATUS:
case GPCMD_LOAD_UNLOAD:
case REZERO_UNIT:
case SEEK_10:
case GPCMD_SET_SPEED:
case SPACE:
case START_STOP:
case TEST_UNIT_READY:
case VERIFY:
case WRITE_FILEMARKS:
case MOVE_MEDIUM:
cmd->se_cmd_flags |= SCF_SCSI_NON_DATA_CDB;
break;
case REPORT_LUNS:
cmd->transport_emulate_cdb =
&transport_core_report_lun_response;
size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
if (SE_DEV(cmd)->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
cmd->sam_task_attr = MSG_HEAD_TAG;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_NONSG_IO_CDB;
break;
default:
printk(KERN_WARNING "TARGET_CORE[%s]: Unsupported SCSI Opcode"
" 0x%02x, sending CHECK_CONDITION.\n",
CMD_TFO(cmd)->get_fabric_name(), cdb[0]);
cmd->transport_wait_for_tasks = &transport_nop_wait_for_tasks;
goto out_unsupported_cdb;
}
if (size != cmd->data_length) {
printk(KERN_WARNING "TARGET_CORE[%s]: Expected Transfer Length:"
" %u does not match SCSI CDB Length: %u for SAM Opcode:"
" 0x%02x\n", CMD_TFO(cmd)->get_fabric_name(),
cmd->data_length, size, cdb[0]);
cmd->cmd_spdtl = size;
if (cmd->data_direction == DMA_TO_DEVICE) {
printk(KERN_ERR "Rejecting underflow/overflow"
" WRITE data\n");
goto out_invalid_cdb_field;
}
if (!(ret) && (DEV_ATTRIB(dev)->block_size != 512)) {
printk(KERN_ERR "Failing OVERFLOW/UNDERFLOW for LBA op"
" CDB on non 512-byte sector setup subsystem"
" plugin: %s\n", TRANSPORT(dev)->name);
goto out_invalid_cdb_field;
}
if (size > cmd->data_length) {
cmd->se_cmd_flags |= SCF_OVERFLOW_BIT;
cmd->residual_count = (size - cmd->data_length);
} else {
cmd->se_cmd_flags |= SCF_UNDERFLOW_BIT;
cmd->residual_count = (cmd->data_length - size);
}
cmd->data_length = size;
}
transport_set_supported_SAM_opcode(cmd);
return ret;
out_unsupported_cdb:
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
return -2;
out_invalid_cdb_field:
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -2;
}
static void transport_memcpy_write_contig(
struct se_cmd *cmd,
struct scatterlist *sg_d,
unsigned char *src)
{
u32 i = 0, length = 0, total_length = cmd->data_length;
void *dst;
while (total_length) {
length = sg_d[i].length;
if (length > total_length)
length = total_length;
dst = sg_virt(&sg_d[i]);
memcpy(dst, src, length);
if (!(total_length -= length))
return;
src += length;
i++;
}
}
static void transport_memcpy_read_contig(
struct se_cmd *cmd,
unsigned char *dst,
struct scatterlist *sg_s)
{
u32 i = 0, length = 0, total_length = cmd->data_length;
void *src;
while (total_length) {
length = sg_s[i].length;
if (length > total_length)
length = total_length;
src = sg_virt(&sg_s[i]);
memcpy(dst, src, length);
if (!(total_length -= length))
return;
dst += length;
i++;
}
}
static void transport_memcpy_se_mem_read_contig(
struct se_cmd *cmd,
unsigned char *dst,
struct list_head *se_mem_list)
{
struct se_mem *se_mem;
void *src;
u32 length = 0, total_length = cmd->data_length;
list_for_each_entry(se_mem, se_mem_list, se_list) {
length = se_mem->se_len;
if (length > total_length)
length = total_length;
src = page_address(se_mem->se_page) + se_mem->se_off;
memcpy(dst, src, length);
if (!(total_length -= length))
return;
dst += length;
}
}
static void transport_complete_task_attr(struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
struct se_cmd *cmd_p, *cmd_tmp;
int new_active_tasks = 0;
if (cmd->sam_task_attr == MSG_SIMPLE_TAG) {
atomic_dec(&dev->simple_cmds);
smp_mb__after_atomic_dec();
dev->dev_cur_ordered_id++;
DEBUG_STA("Incremented dev->dev_cur_ordered_id: %u for"
" SIMPLE: %u\n", dev->dev_cur_ordered_id,
cmd->se_ordered_id);
} else if (cmd->sam_task_attr == MSG_HEAD_TAG) {
atomic_dec(&dev->dev_hoq_count);
smp_mb__after_atomic_dec();
dev->dev_cur_ordered_id++;
DEBUG_STA("Incremented dev_cur_ordered_id: %u for"
" HEAD_OF_QUEUE: %u\n", dev->dev_cur_ordered_id,
cmd->se_ordered_id);
} else if (cmd->sam_task_attr == MSG_ORDERED_TAG) {
spin_lock(&dev->ordered_cmd_lock);
list_del(&cmd->se_ordered_list);
atomic_dec(&dev->dev_ordered_sync);
smp_mb__after_atomic_dec();
spin_unlock(&dev->ordered_cmd_lock);
dev->dev_cur_ordered_id++;
DEBUG_STA("Incremented dev_cur_ordered_id: %u for ORDERED:"
" %u\n", dev->dev_cur_ordered_id, cmd->se_ordered_id);
}
spin_lock(&dev->delayed_cmd_lock);
list_for_each_entry_safe(cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_list) {
list_del(&cmd_p->se_delayed_list);
spin_unlock(&dev->delayed_cmd_lock);
DEBUG_STA("Calling add_tasks() for"
" cmd_p: 0x%02x Task Attr: 0x%02x"
" Dormant -> Active, se_ordered_id: %u\n",
T_TASK(cmd_p)->t_task_cdb[0],
cmd_p->sam_task_attr, cmd_p->se_ordered_id);
transport_add_tasks_from_cmd(cmd_p);
new_active_tasks++;
spin_lock(&dev->delayed_cmd_lock);
if (cmd_p->sam_task_attr == MSG_ORDERED_TAG)
break;
}
spin_unlock(&dev->delayed_cmd_lock);
if (new_active_tasks != 0)
wake_up_interruptible(&dev->dev_queue_obj->thread_wq);
}
static void transport_generic_complete_ok(struct se_cmd *cmd)
{
int reason = 0;
if (SE_DEV(cmd)->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
transport_complete_task_attr(cmd);
if (cmd->se_cmd_flags & SCF_TRANSPORT_TASK_SENSE) {
if (transport_get_sense_data(cmd) < 0)
reason = TCM_NON_EXISTENT_LUN;
if (cmd->scsi_status) {
transport_send_check_condition_and_sense(
cmd, reason, 1);
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop_to_fabric(cmd);
return;
}
}
if (cmd->transport_complete_callback)
cmd->transport_complete_callback(cmd);
switch (cmd->data_direction) {
case DMA_FROM_DEVICE:
spin_lock(&cmd->se_lun->lun_sep_lock);
if (SE_LUN(cmd)->lun_sep) {
SE_LUN(cmd)->lun_sep->sep_stats.tx_data_octets +=
cmd->data_length;
}
spin_unlock(&cmd->se_lun->lun_sep_lock);
if (cmd->se_cmd_flags & SCF_PASSTHROUGH_CONTIG_TO_SG)
transport_memcpy_write_contig(cmd,
T_TASK(cmd)->t_task_pt_sgl,
T_TASK(cmd)->t_task_buf);
CMD_TFO(cmd)->queue_data_in(cmd);
break;
case DMA_TO_DEVICE:
spin_lock(&cmd->se_lun->lun_sep_lock);
if (SE_LUN(cmd)->lun_sep) {
SE_LUN(cmd)->lun_sep->sep_stats.rx_data_octets +=
cmd->data_length;
}
spin_unlock(&cmd->se_lun->lun_sep_lock);
if (T_TASK(cmd)->t_mem_bidi_list != NULL) {
spin_lock(&cmd->se_lun->lun_sep_lock);
if (SE_LUN(cmd)->lun_sep) {
SE_LUN(cmd)->lun_sep->sep_stats.tx_data_octets +=
cmd->data_length;
}
spin_unlock(&cmd->se_lun->lun_sep_lock);
CMD_TFO(cmd)->queue_data_in(cmd);
break;
}
case DMA_NONE:
CMD_TFO(cmd)->queue_status(cmd);
break;
default:
break;
}
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop_to_fabric(cmd);
}
static void transport_free_dev_tasks(struct se_cmd *cmd)
{
struct se_task *task, *task_tmp;
unsigned long flags;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
list_for_each_entry_safe(task, task_tmp,
&T_TASK(cmd)->t_task_list, t_list) {
if (atomic_read(&task->task_active))
continue;
kfree(task->task_sg_bidi);
kfree(task->task_sg);
list_del(&task->t_list);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
if (task->se_dev)
TRANSPORT(task->se_dev)->free_task(task);
else
printk(KERN_ERR "task[%u] - task->se_dev is NULL\n",
task->task_no);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
}
static inline void transport_free_pages(struct se_cmd *cmd)
{
struct se_mem *se_mem, *se_mem_tmp;
int free_page = 1;
if (cmd->se_cmd_flags & SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC)
free_page = 0;
if (cmd->se_dev->transport->do_se_mem_map)
free_page = 0;
if (T_TASK(cmd)->t_task_buf) {
kfree(T_TASK(cmd)->t_task_buf);
T_TASK(cmd)->t_task_buf = NULL;
return;
}
if (cmd->se_cmd_flags & SCF_CMD_PASSTHROUGH_NOALLOC)
return;
if (!(T_TASK(cmd)->t_tasks_se_num))
return;
list_for_each_entry_safe(se_mem, se_mem_tmp,
T_TASK(cmd)->t_mem_list, se_list) {
if (free_page)
__free_page(se_mem->se_page);
list_del(&se_mem->se_list);
kmem_cache_free(se_mem_cache, se_mem);
}
if (T_TASK(cmd)->t_mem_bidi_list && T_TASK(cmd)->t_tasks_se_bidi_num) {
list_for_each_entry_safe(se_mem, se_mem_tmp,
T_TASK(cmd)->t_mem_bidi_list, se_list) {
if (free_page)
__free_page(se_mem->se_page);
list_del(&se_mem->se_list);
kmem_cache_free(se_mem_cache, se_mem);
}
}
kfree(T_TASK(cmd)->t_mem_bidi_list);
T_TASK(cmd)->t_mem_bidi_list = NULL;
kfree(T_TASK(cmd)->t_mem_list);
T_TASK(cmd)->t_mem_list = NULL;
T_TASK(cmd)->t_tasks_se_num = 0;
}
static inline void transport_release_tasks(struct se_cmd *cmd)
{
transport_free_dev_tasks(cmd);
}
static inline int transport_dec_and_check(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (atomic_read(&T_TASK(cmd)->t_fe_count)) {
if (!(atomic_dec_and_test(&T_TASK(cmd)->t_fe_count))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
flags);
return 1;
}
}
if (atomic_read(&T_TASK(cmd)->t_se_count)) {
if (!(atomic_dec_and_test(&T_TASK(cmd)->t_se_count))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
flags);
return 1;
}
}
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return 0;
}
static void transport_release_fe_cmd(struct se_cmd *cmd)
{
unsigned long flags;
if (transport_dec_and_check(cmd))
return;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (!(atomic_read(&T_TASK(cmd)->transport_dev_active))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
goto free_pages;
}
atomic_set(&T_TASK(cmd)->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_release_tasks(cmd);
free_pages:
transport_free_pages(cmd);
transport_free_se_cmd(cmd);
CMD_TFO(cmd)->release_cmd_direct(cmd);
}
static int transport_generic_remove(
struct se_cmd *cmd,
int release_to_pool,
int session_reinstatement)
{
unsigned long flags;
if (!(T_TASK(cmd)))
goto release_cmd;
if (transport_dec_and_check(cmd)) {
if (session_reinstatement) {
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
flags);
}
return 1;
}
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (!(atomic_read(&T_TASK(cmd)->transport_dev_active))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
goto free_pages;
}
atomic_set(&T_TASK(cmd)->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_release_tasks(cmd);
free_pages:
transport_free_pages(cmd);
release_cmd:
if (release_to_pool) {
transport_release_cmd_to_pool(cmd);
} else {
transport_free_se_cmd(cmd);
CMD_TFO(cmd)->release_cmd_direct(cmd);
}
return 0;
}
int transport_generic_map_mem_to_cmd(
struct se_cmd *cmd,
struct scatterlist *mem,
u32 sg_mem_num,
struct scatterlist *mem_bidi_in,
u32 sg_mem_bidi_num)
{
u32 se_mem_cnt_out = 0;
int ret;
if (!(mem) || !(sg_mem_num))
return 0;
if (!(cmd->se_cmd_flags & SCF_PASSTHROUGH_SG_TO_MEM)) {
if ((mem_bidi_in) || (sg_mem_bidi_num)) {
printk(KERN_ERR "SCF_CMD_PASSTHROUGH_NOALLOC not supported"
" with BIDI-COMMAND\n");
return -ENOSYS;
}
T_TASK(cmd)->t_mem_list = (struct list_head *)mem;
T_TASK(cmd)->t_tasks_se_num = sg_mem_num;
cmd->se_cmd_flags |= SCF_CMD_PASSTHROUGH_NOALLOC;
return 0;
}
if ((cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB) ||
(cmd->se_cmd_flags & SCF_SCSI_CONTROL_SG_IO_CDB)) {
T_TASK(cmd)->t_mem_list = transport_init_se_mem_list();
if (!(T_TASK(cmd)->t_mem_list))
return -ENOMEM;
ret = transport_map_sg_to_mem(cmd,
T_TASK(cmd)->t_mem_list, mem, &se_mem_cnt_out);
if (ret < 0)
return -ENOMEM;
T_TASK(cmd)->t_tasks_se_num = se_mem_cnt_out;
if ((mem_bidi_in) && (sg_mem_bidi_num)) {
T_TASK(cmd)->t_mem_bidi_list = transport_init_se_mem_list();
if (!(T_TASK(cmd)->t_mem_bidi_list)) {
kfree(T_TASK(cmd)->t_mem_list);
return -ENOMEM;
}
se_mem_cnt_out = 0;
ret = transport_map_sg_to_mem(cmd,
T_TASK(cmd)->t_mem_bidi_list, mem_bidi_in,
&se_mem_cnt_out);
if (ret < 0) {
kfree(T_TASK(cmd)->t_mem_list);
return -ENOMEM;
}
T_TASK(cmd)->t_tasks_se_bidi_num = se_mem_cnt_out;
}
cmd->se_cmd_flags |= SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC;
} else if (cmd->se_cmd_flags & SCF_SCSI_CONTROL_NONSG_IO_CDB) {
if (mem_bidi_in || sg_mem_bidi_num) {
printk(KERN_ERR "BIDI-Commands not supported using "
"SCF_SCSI_CONTROL_NONSG_IO_CDB\n");
return -ENOSYS;
}
cmd->se_cmd_flags |= SCF_PASSTHROUGH_CONTIG_TO_SG;
T_TASK(cmd)->t_task_pt_sgl = mem;
}
return 0;
}
static inline long long transport_dev_end_lba(struct se_device *dev)
{
return dev->transport->get_blocks(dev) + 1;
}
static int transport_get_sectors(struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
T_TASK(cmd)->t_tasks_sectors =
(cmd->data_length / DEV_ATTRIB(dev)->block_size);
if (!(T_TASK(cmd)->t_tasks_sectors))
T_TASK(cmd)->t_tasks_sectors = 1;
if (TRANSPORT(dev)->get_device_type(dev) != TYPE_DISK)
return 0;
if ((T_TASK(cmd)->t_task_lba + T_TASK(cmd)->t_tasks_sectors) >
transport_dev_end_lba(dev)) {
printk(KERN_ERR "LBA: %llu Sectors: %u exceeds"
" transport_dev_end_lba(): %llu\n",
T_TASK(cmd)->t_task_lba, T_TASK(cmd)->t_tasks_sectors,
transport_dev_end_lba(dev));
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_SECTOR_COUNT_TOO_MANY;
return PYX_TRANSPORT_REQ_TOO_MANY_SECTORS;
}
return 0;
}
static int transport_new_cmd_obj(struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
u32 task_cdbs = 0, rc;
if (!(cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB)) {
task_cdbs++;
T_TASK(cmd)->t_task_cdbs++;
} else {
int set_counts = 1;
if ((T_TASK(cmd)->t_mem_bidi_list != NULL) &&
(TRANSPORT(dev)->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV)) {
rc = transport_generic_get_cdb_count(cmd,
T_TASK(cmd)->t_task_lba,
T_TASK(cmd)->t_tasks_sectors,
DMA_FROM_DEVICE, T_TASK(cmd)->t_mem_bidi_list,
set_counts);
if (!(rc)) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason =
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
set_counts = 0;
}
task_cdbs = transport_generic_get_cdb_count(cmd,
T_TASK(cmd)->t_task_lba,
T_TASK(cmd)->t_tasks_sectors,
cmd->data_direction, T_TASK(cmd)->t_mem_list,
set_counts);
if (!(task_cdbs)) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason =
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return PYX_TRANSPORT_LU_COMM_FAILURE;
}
T_TASK(cmd)->t_task_cdbs += task_cdbs;
#if 0
printk(KERN_INFO "data_length: %u, LBA: %llu t_tasks_sectors:"
" %u, t_task_cdbs: %u\n", obj_ptr, cmd->data_length,
T_TASK(cmd)->t_task_lba, T_TASK(cmd)->t_tasks_sectors,
T_TASK(cmd)->t_task_cdbs);
#endif
}
atomic_set(&T_TASK(cmd)->t_task_cdbs_left, task_cdbs);
atomic_set(&T_TASK(cmd)->t_task_cdbs_ex_left, task_cdbs);
atomic_set(&T_TASK(cmd)->t_task_cdbs_timeout_left, task_cdbs);
return 0;
}
static struct list_head *transport_init_se_mem_list(void)
{
struct list_head *se_mem_list;
se_mem_list = kzalloc(sizeof(struct list_head), GFP_KERNEL);
if (!(se_mem_list)) {
printk(KERN_ERR "Unable to allocate memory for se_mem_list\n");
return NULL;
}
INIT_LIST_HEAD(se_mem_list);
return se_mem_list;
}
static int
transport_generic_get_mem(struct se_cmd *cmd, u32 length, u32 dma_size)
{
unsigned char *buf;
struct se_mem *se_mem;
T_TASK(cmd)->t_mem_list = transport_init_se_mem_list();
if (!(T_TASK(cmd)->t_mem_list))
return -ENOMEM;
if (cmd->se_dev->transport->do_se_mem_map)
return 0;
if (T_TASK(cmd)->t_tasks_bidi) {
T_TASK(cmd)->t_mem_bidi_list = transport_init_se_mem_list();
if (!(T_TASK(cmd)->t_mem_bidi_list)) {
kfree(T_TASK(cmd)->t_mem_list);
return -ENOMEM;
}
}
while (length) {
se_mem = kmem_cache_zalloc(se_mem_cache, GFP_KERNEL);
if (!(se_mem)) {
printk(KERN_ERR "Unable to allocate struct se_mem\n");
goto out;
}
se_mem->se_page = alloc_pages(GFP_KERNEL, 0);
if (!(se_mem->se_page)) {
printk(KERN_ERR "alloc_pages() failed\n");
goto out;
}
buf = kmap_atomic(se_mem->se_page, KM_IRQ0);
if (!(buf)) {
printk(KERN_ERR "kmap_atomic() failed\n");
goto out;
}
INIT_LIST_HEAD(&se_mem->se_list);
se_mem->se_len = (length > dma_size) ? dma_size : length;
memset(buf, 0, se_mem->se_len);
kunmap_atomic(buf, KM_IRQ0);
list_add_tail(&se_mem->se_list, T_TASK(cmd)->t_mem_list);
T_TASK(cmd)->t_tasks_se_num++;
DEBUG_MEM("Allocated struct se_mem page(%p) Length(%u)"
" Offset(%u)\n", se_mem->se_page, se_mem->se_len,
se_mem->se_off);
length -= se_mem->se_len;
}
DEBUG_MEM("Allocated total struct se_mem elements(%u)\n",
T_TASK(cmd)->t_tasks_se_num);
return 0;
out:
if (se_mem)
__free_pages(se_mem->se_page, 0);
kmem_cache_free(se_mem_cache, se_mem);
return -1;
}
u32 transport_calc_sg_num(
struct se_task *task,
struct se_mem *in_se_mem,
u32 task_offset)
{
struct se_cmd *se_cmd = task->task_se_cmd;
struct se_device *se_dev = SE_DEV(se_cmd);
struct se_mem *se_mem = in_se_mem;
struct target_core_fabric_ops *tfo = CMD_TFO(se_cmd);
u32 sg_length, task_size = task->task_size, task_sg_num_padded;
while (task_size != 0) {
DEBUG_SC("se_mem->se_page(%p) se_mem->se_len(%u)"
" se_mem->se_off(%u) task_offset(%u)\n",
se_mem->se_page, se_mem->se_len,
se_mem->se_off, task_offset);
if (task_offset == 0) {
if (task_size >= se_mem->se_len) {
sg_length = se_mem->se_len;
if (!(list_is_last(&se_mem->se_list,
T_TASK(se_cmd)->t_mem_list)))
se_mem = list_entry(se_mem->se_list.next,
struct se_mem, se_list);
} else {
sg_length = task_size;
task_size -= sg_length;
goto next;
}
DEBUG_SC("sg_length(%u) task_size(%u)\n",
sg_length, task_size);
} else {
if ((se_mem->se_len - task_offset) > task_size) {
sg_length = task_size;
task_size -= sg_length;
goto next;
} else {
sg_length = (se_mem->se_len - task_offset);
if (!(list_is_last(&se_mem->se_list,
T_TASK(se_cmd)->t_mem_list)))
se_mem = list_entry(se_mem->se_list.next,
struct se_mem, se_list);
}
DEBUG_SC("sg_length(%u) task_size(%u)\n",
sg_length, task_size);
task_offset = 0;
}
task_size -= sg_length;
next:
DEBUG_SC("task[%u] - Reducing task_size to(%u)\n",
task->task_no, task_size);
task->task_sg_num++;
}
if (tfo->task_sg_chaining) {
task_sg_num_padded = (task->task_sg_num + 1);
task->task_padded_sg = 1;
} else
task_sg_num_padded = task->task_sg_num;
task->task_sg = kzalloc(task_sg_num_padded *
sizeof(struct scatterlist), GFP_KERNEL);
if (!(task->task_sg)) {
printk(KERN_ERR "Unable to allocate memory for"
" task->task_sg\n");
return 0;
}
sg_init_table(&task->task_sg[0], task_sg_num_padded);
if ((T_TASK(se_cmd)->t_mem_bidi_list != NULL) &&
(TRANSPORT(se_dev)->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV)) {
task->task_sg_bidi = kzalloc(task_sg_num_padded *
sizeof(struct scatterlist), GFP_KERNEL);
if (!(task->task_sg_bidi)) {
printk(KERN_ERR "Unable to allocate memory for"
" task->task_sg_bidi\n");
return 0;
}
sg_init_table(&task->task_sg_bidi[0], task_sg_num_padded);
}
if (task->task_padded_sg) {
sg_mark_end(&task->task_sg[task->task_sg_num - 1]);
if (task->task_sg_bidi)
sg_mark_end(&task->task_sg_bidi[task->task_sg_num - 1]);
}
DEBUG_SC("Successfully allocated task->task_sg_num(%u),"
" task_sg_num_padded(%u)\n", task->task_sg_num,
task_sg_num_padded);
return task->task_sg_num;
}
static inline int transport_set_tasks_sectors_disk(
struct se_task *task,
struct se_device *dev,
unsigned long long lba,
u32 sectors,
int *max_sectors_set)
{
if ((lba + sectors) > transport_dev_end_lba(dev)) {
task->task_sectors = ((transport_dev_end_lba(dev) - lba) + 1);
if (task->task_sectors > DEV_ATTRIB(dev)->max_sectors) {
task->task_sectors = DEV_ATTRIB(dev)->max_sectors;
*max_sectors_set = 1;
}
} else {
if (sectors > DEV_ATTRIB(dev)->max_sectors) {
task->task_sectors = DEV_ATTRIB(dev)->max_sectors;
*max_sectors_set = 1;
} else
task->task_sectors = sectors;
}
return 0;
}
static inline int transport_set_tasks_sectors_non_disk(
struct se_task *task,
struct se_device *dev,
unsigned long long lba,
u32 sectors,
int *max_sectors_set)
{
if (sectors > DEV_ATTRIB(dev)->max_sectors) {
task->task_sectors = DEV_ATTRIB(dev)->max_sectors;
*max_sectors_set = 1;
} else
task->task_sectors = sectors;
return 0;
}
static inline int transport_set_tasks_sectors(
struct se_task *task,
struct se_device *dev,
unsigned long long lba,
u32 sectors,
int *max_sectors_set)
{
return (TRANSPORT(dev)->get_device_type(dev) == TYPE_DISK) ?
transport_set_tasks_sectors_disk(task, dev, lba, sectors,
max_sectors_set) :
transport_set_tasks_sectors_non_disk(task, dev, lba, sectors,
max_sectors_set);
}
static int transport_map_sg_to_mem(
struct se_cmd *cmd,
struct list_head *se_mem_list,
void *in_mem,
u32 *se_mem_cnt)
{
struct se_mem *se_mem;
struct scatterlist *sg;
u32 sg_count = 1, cmd_size = cmd->data_length;
if (!in_mem) {
printk(KERN_ERR "No source scatterlist\n");
return -1;
}
sg = (struct scatterlist *)in_mem;
while (cmd_size) {
se_mem = kmem_cache_zalloc(se_mem_cache, GFP_KERNEL);
if (!(se_mem)) {
printk(KERN_ERR "Unable to allocate struct se_mem\n");
return -1;
}
INIT_LIST_HEAD(&se_mem->se_list);
DEBUG_MEM("sg_to_mem: Starting loop with cmd_size: %u"
" sg_page: %p offset: %d length: %d\n", cmd_size,
sg_page(sg), sg->offset, sg->length);
se_mem->se_page = sg_page(sg);
se_mem->se_off = sg->offset;
if (cmd_size > sg->length) {
se_mem->se_len = sg->length;
sg = sg_next(sg);
sg_count++;
} else
se_mem->se_len = cmd_size;
cmd_size -= se_mem->se_len;
DEBUG_MEM("sg_to_mem: *se_mem_cnt: %u cmd_size: %u\n",
*se_mem_cnt, cmd_size);
DEBUG_MEM("sg_to_mem: Final se_page: %p se_off: %d se_len: %d\n",
se_mem->se_page, se_mem->se_off, se_mem->se_len);
list_add_tail(&se_mem->se_list, se_mem_list);
(*se_mem_cnt)++;
}
DEBUG_MEM("task[0] - Mapped(%u) struct scatterlist segments to(%u)"
" struct se_mem\n", sg_count, *se_mem_cnt);
if (sg_count != *se_mem_cnt)
BUG();
return 0;
}
int transport_map_mem_to_sg(
struct se_task *task,
struct list_head *se_mem_list,
void *in_mem,
struct se_mem *in_se_mem,
struct se_mem **out_se_mem,
u32 *se_mem_cnt,
u32 *task_offset)
{
struct se_cmd *se_cmd = task->task_se_cmd;
struct se_mem *se_mem = in_se_mem;
struct scatterlist *sg = (struct scatterlist *)in_mem;
u32 task_size = task->task_size, sg_no = 0;
if (!sg) {
printk(KERN_ERR "Unable to locate valid struct"
" scatterlist pointer\n");
return -1;
}
while (task_size != 0) {
sg_assign_page(sg, se_mem->se_page);
if (*task_offset == 0) {
sg->offset = se_mem->se_off;
if (task_size >= se_mem->se_len) {
sg->length = se_mem->se_len;
if (!(list_is_last(&se_mem->se_list,
T_TASK(se_cmd)->t_mem_list))) {
se_mem = list_entry(se_mem->se_list.next,
struct se_mem, se_list);
(*se_mem_cnt)++;
}
} else {
sg->length = task_size;
task_size -= sg->length;
if (!(task_size))
*task_offset = sg->length;
goto next;
}
} else {
sg->offset = (*task_offset + se_mem->se_off);
if ((se_mem->se_len - *task_offset) > task_size) {
sg->length = task_size;
task_size -= sg->length;
if (!(task_size))
*task_offset += sg->length;
goto next;
} else {
sg->length = (se_mem->se_len - *task_offset);
if (!(list_is_last(&se_mem->se_list,
T_TASK(se_cmd)->t_mem_list))) {
se_mem = list_entry(se_mem->se_list.next,
struct se_mem, se_list);
(*se_mem_cnt)++;
}
}
*task_offset = 0;
}
task_size -= sg->length;
next:
DEBUG_MEM("task[%u] mem_to_sg - sg[%u](%p)(%u)(%u) - Reducing"
" task_size to(%u), task_offset: %u\n", task->task_no, sg_no,
sg_page(sg), sg->length, sg->offset, task_size, *task_offset);
sg_no++;
if (!(task_size))
break;
sg = sg_next(sg);
if (task_size > se_cmd->data_length)
BUG();
}
*out_se_mem = se_mem;
DEBUG_MEM("task[%u] - Mapped(%u) struct se_mem segments to total(%u)"
" SGs\n", task->task_no, *se_mem_cnt, sg_no);
return 0;
}
void transport_do_task_sg_chain(struct se_cmd *cmd)
{
struct scatterlist *sg_head = NULL, *sg_link = NULL, *sg_first = NULL;
struct scatterlist *sg_head_cur = NULL, *sg_link_cur = NULL;
struct scatterlist *sg, *sg_end = NULL, *sg_end_cur = NULL;
struct se_task *task;
struct target_core_fabric_ops *tfo = CMD_TFO(cmd);
u32 task_sg_num = 0, sg_count = 0;
int i;
if (tfo->task_sg_chaining == 0) {
printk(KERN_ERR "task_sg_chaining is diabled for fabric module:"
" %s\n", tfo->get_fabric_name());
dump_stack();
return;
}
list_for_each_entry(task, &T_TASK(cmd)->t_task_list, t_list) {
if (!(task->task_sg) || !(task->task_padded_sg))
continue;
if (sg_head && sg_link) {
sg_head_cur = &task->task_sg[0];
sg_link_cur = &task->task_sg[task->task_sg_num];
if (!(list_is_last(&task->t_list,
&T_TASK(cmd)->t_task_list))) {
sg_end_cur = &task->task_sg[task->task_sg_num - 1];
sg_end_cur->page_link &= ~0x02;
sg_chain(sg_head, task_sg_num, sg_head_cur);
sg_count += task->task_sg_num;
task_sg_num = (task->task_sg_num + 1);
} else {
sg_chain(sg_head, task_sg_num, sg_head_cur);
sg_count += task->task_sg_num;
task_sg_num = task->task_sg_num;
}
sg_head = sg_head_cur;
sg_link = sg_link_cur;
continue;
}
sg_head = sg_first = &task->task_sg[0];
sg_link = &task->task_sg[task->task_sg_num];
if (!(list_is_last(&task->t_list, &T_TASK(cmd)->t_task_list))) {
sg_end = &task->task_sg[task->task_sg_num - 1];
sg_end->page_link &= ~0x02;
sg_count += task->task_sg_num;
task_sg_num = (task->task_sg_num + 1);
} else {
sg_count += task->task_sg_num;
task_sg_num = task->task_sg_num;
}
}
T_TASK(cmd)->t_tasks_sg_chained = sg_first;
T_TASK(cmd)->t_tasks_sg_chained_no = sg_count;
DEBUG_CMD_M("Setup cmd: %p T_TASK(cmd)->t_tasks_sg_chained: %p and"
" t_tasks_sg_chained_no: %u\n", cmd, T_TASK(cmd)->t_tasks_sg_chained,
T_TASK(cmd)->t_tasks_sg_chained_no);
for_each_sg(T_TASK(cmd)->t_tasks_sg_chained, sg,
T_TASK(cmd)->t_tasks_sg_chained_no, i) {
DEBUG_CMD_M("SG[%d]: %p page: %p length: %d offset: %d, magic: 0x%08x\n",
i, sg, sg_page(sg), sg->length, sg->offset, sg->sg_magic);
if (sg_is_chain(sg))
DEBUG_CMD_M("SG: %p sg_is_chain=1\n", sg);
if (sg_is_last(sg))
DEBUG_CMD_M("SG: %p sg_is_last=1\n", sg);
}
}
static int transport_do_se_mem_map(
struct se_device *dev,
struct se_task *task,
struct list_head *se_mem_list,
void *in_mem,
struct se_mem *in_se_mem,
struct se_mem **out_se_mem,
u32 *se_mem_cnt,
u32 *task_offset_in)
{
u32 task_offset = *task_offset_in;
int ret = 0;
if (TRANSPORT(dev)->do_se_mem_map) {
ret = TRANSPORT(dev)->do_se_mem_map(task, se_mem_list,
in_mem, in_se_mem, out_se_mem, se_mem_cnt,
task_offset_in);
if (ret == 0)
T_TASK(task->task_se_cmd)->t_tasks_se_num += *se_mem_cnt;
return ret;
}
BUG_ON(list_empty(se_mem_list));
if (!(task->task_sg_bidi)) {
if (!(transport_calc_sg_num(task, in_se_mem, task_offset)))
return -1;
return transport_map_mem_to_sg(task, se_mem_list, task->task_sg,
in_se_mem, out_se_mem, se_mem_cnt,
task_offset_in);
}
return transport_map_mem_to_sg(task, se_mem_list, task->task_sg_bidi,
in_se_mem, out_se_mem, se_mem_cnt,
task_offset_in);
}
static u32 transport_generic_get_cdb_count(
struct se_cmd *cmd,
unsigned long long lba,
u32 sectors,
enum dma_data_direction data_direction,
struct list_head *mem_list,
int set_counts)
{
unsigned char *cdb = NULL;
struct se_task *task;
struct se_mem *se_mem = NULL, *se_mem_lout = NULL;
struct se_mem *se_mem_bidi = NULL, *se_mem_bidi_lout = NULL;
struct se_device *dev = SE_DEV(cmd);
int max_sectors_set = 0, ret;
u32 task_offset_in = 0, se_mem_cnt = 0, se_mem_bidi_cnt = 0, task_cdbs = 0;
if (!mem_list) {
printk(KERN_ERR "mem_list is NULL in transport_generic_get"
"_cdb_count()\n");
return 0;
}
if (!(list_empty(mem_list)))
se_mem = list_entry(mem_list->next, struct se_mem, se_list);
if ((T_TASK(cmd)->t_mem_bidi_list != NULL) &&
!(list_empty(T_TASK(cmd)->t_mem_bidi_list)) &&
(TRANSPORT(dev)->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV))
se_mem_bidi = list_entry(T_TASK(cmd)->t_mem_bidi_list->next,
struct se_mem, se_list);
while (sectors) {
DEBUG_VOL("ITT[0x%08x] LBA(%llu) SectorsLeft(%u) EOBJ(%llu)\n",
CMD_TFO(cmd)->get_task_tag(cmd), lba, sectors,
transport_dev_end_lba(dev));
task = transport_generic_get_task(cmd, data_direction);
if (!(task))
goto out;
transport_set_tasks_sectors(task, dev, lba, sectors,
&max_sectors_set);
task->task_lba = lba;
lba += task->task_sectors;
sectors -= task->task_sectors;
task->task_size = (task->task_sectors *
DEV_ATTRIB(dev)->block_size);
cdb = TRANSPORT(dev)->get_cdb(task);
if ((cdb)) {
memcpy(cdb, T_TASK(cmd)->t_task_cdb,
scsi_command_size(T_TASK(cmd)->t_task_cdb));
cmd->transport_split_cdb(task->task_lba,
&task->task_sectors, cdb);
}
ret = transport_do_se_mem_map(dev, task, mem_list,
NULL, se_mem, &se_mem_lout, &se_mem_cnt,
&task_offset_in);
if (ret < 0)
goto out;
se_mem = se_mem_lout;
if (task->task_sg_bidi != NULL) {
ret = transport_do_se_mem_map(dev, task,
T_TASK(cmd)->t_mem_bidi_list, NULL,
se_mem_bidi, &se_mem_bidi_lout, &se_mem_bidi_cnt,
&task_offset_in);
if (ret < 0)
goto out;
se_mem_bidi = se_mem_bidi_lout;
}
task_cdbs++;
DEBUG_VOL("Incremented task_cdbs(%u) task->task_sg_num(%u)\n",
task_cdbs, task->task_sg_num);
if (max_sectors_set) {
max_sectors_set = 0;
continue;
}
if (!sectors)
break;
}
if (set_counts) {
atomic_inc(&T_TASK(cmd)->t_fe_count);
atomic_inc(&T_TASK(cmd)->t_se_count);
}
DEBUG_VOL("ITT[0x%08x] total %s cdbs(%u)\n",
CMD_TFO(cmd)->get_task_tag(cmd), (data_direction == DMA_TO_DEVICE)
? "DMA_TO_DEVICE" : "DMA_FROM_DEVICE", task_cdbs);
return task_cdbs;
out:
return 0;
}
static int
transport_map_control_cmd_to_task(struct se_cmd *cmd)
{
struct se_device *dev = SE_DEV(cmd);
unsigned char *cdb;
struct se_task *task;
int ret;
task = transport_generic_get_task(cmd, cmd->data_direction);
if (!task)
return PYX_TRANSPORT_OUT_OF_MEMORY_RESOURCES;
cdb = TRANSPORT(dev)->get_cdb(task);
if (cdb)
memcpy(cdb, cmd->t_task->t_task_cdb,
scsi_command_size(cmd->t_task->t_task_cdb));
task->task_size = cmd->data_length;
task->task_sg_num =
(cmd->se_cmd_flags & SCF_SCSI_CONTROL_SG_IO_CDB) ? 1 : 0;
atomic_inc(&cmd->t_task->t_fe_count);
atomic_inc(&cmd->t_task->t_se_count);
if (cmd->se_cmd_flags & SCF_SCSI_CONTROL_SG_IO_CDB) {
struct se_mem *se_mem = NULL, *se_mem_lout = NULL;
u32 se_mem_cnt = 0, task_offset = 0;
if (!list_empty(T_TASK(cmd)->t_mem_list))
se_mem = list_entry(T_TASK(cmd)->t_mem_list->next,
struct se_mem, se_list);
ret = transport_do_se_mem_map(dev, task,
cmd->t_task->t_mem_list, NULL, se_mem,
&se_mem_lout, &se_mem_cnt, &task_offset);
if (ret < 0)
return PYX_TRANSPORT_OUT_OF_MEMORY_RESOURCES;
if (dev->transport->map_task_SG)
return dev->transport->map_task_SG(task);
return 0;
} else if (cmd->se_cmd_flags & SCF_SCSI_CONTROL_NONSG_IO_CDB) {
if (dev->transport->map_task_non_SG)
return dev->transport->map_task_non_SG(task);
return 0;
} else if (cmd->se_cmd_flags & SCF_SCSI_NON_DATA_CDB) {
if (dev->transport->cdb_none)
return dev->transport->cdb_none(task);
return 0;
} else {
BUG();
return PYX_TRANSPORT_OUT_OF_MEMORY_RESOURCES;
}
}
static int transport_generic_new_cmd(struct se_cmd *cmd)
{
struct se_portal_group *se_tpg;
struct se_task *task;
struct se_device *dev = SE_DEV(cmd);
int ret = 0;
if (!(cmd->se_cmd_flags & SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC)) {
ret = transport_allocate_resources(cmd);
if (ret < 0)
return ret;
}
ret = transport_get_sectors(cmd);
if (ret < 0)
return ret;
ret = transport_new_cmd_obj(cmd);
if (ret < 0)
return ret;
se_tpg = SE_LUN(cmd)->lun_sep->sep_tpg;
if (TPG_TFO(se_tpg)->alloc_cmd_iovecs != NULL) {
ret = TPG_TFO(se_tpg)->alloc_cmd_iovecs(cmd);
if (ret < 0)
return PYX_TRANSPORT_OUT_OF_MEMORY_RESOURCES;
}
if (cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB) {
list_for_each_entry(task, &T_TASK(cmd)->t_task_list, t_list) {
if (atomic_read(&task->task_sent))
continue;
if (!dev->transport->map_task_SG)
continue;
ret = dev->transport->map_task_SG(task);
if (ret < 0)
return ret;
}
} else {
ret = transport_map_control_cmd_to_task(cmd);
if (ret < 0)
return ret;
}
if (cmd->data_direction == DMA_TO_DEVICE) {
transport_add_tasks_to_state_queue(cmd);
return transport_generic_write_pending(cmd);
}
transport_execute_tasks(cmd);
return 0;
}
void transport_generic_process_write(struct se_cmd *cmd)
{
#if 0
if (cmd->se_cmd_flags & SCF_UNDERFLOW_BIT) {
if (!T_TASK(cmd)->t_tasks_se_num) {
unsigned char *dst, *buf =
(unsigned char *)T_TASK(cmd)->t_task_buf;
dst = kzalloc(cmd->cmd_spdtl), GFP_KERNEL);
if (!(dst)) {
printk(KERN_ERR "Unable to allocate memory for"
" WRITE underflow\n");
transport_generic_request_failure(cmd, NULL,
PYX_TRANSPORT_REQ_TOO_MANY_SECTORS, 1);
return;
}
memcpy(dst, buf, cmd->cmd_spdtl);
kfree(T_TASK(cmd)->t_task_buf);
T_TASK(cmd)->t_task_buf = dst;
} else {
struct scatterlist *sg =
(struct scatterlist *sg)T_TASK(cmd)->t_task_buf;
struct scatterlist *orig_sg;
orig_sg = kzalloc(sizeof(struct scatterlist) *
T_TASK(cmd)->t_tasks_se_num,
GFP_KERNEL))) {
if (!(orig_sg)) {
printk(KERN_ERR "Unable to allocate memory"
" for WRITE underflow\n");
transport_generic_request_failure(cmd, NULL,
PYX_TRANSPORT_REQ_TOO_MANY_SECTORS, 1);
return;
}
memcpy(orig_sg, T_TASK(cmd)->t_task_buf,
sizeof(struct scatterlist) *
T_TASK(cmd)->t_tasks_se_num);
cmd->data_length = cmd->cmd_spdtl;
if (transport_generic_new_cmd(cmd) < 0) {
transport_generic_request_failure(cmd, NULL,
PYX_TRANSPORT_REQ_TOO_MANY_SECTORS, 1);
kfree(orig_sg);
return;
}
transport_memcpy_write_sg(cmd, orig_sg);
}
}
#endif
transport_execute_tasks(cmd);
}
static int transport_generic_write_pending(struct se_cmd *cmd)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
cmd->t_state = TRANSPORT_WRITE_PENDING;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
if (cmd->se_cmd_flags & SCF_PASSTHROUGH_CONTIG_TO_SG)
transport_memcpy_read_contig(cmd,
T_TASK(cmd)->t_task_buf,
T_TASK(cmd)->t_task_pt_sgl);
transport_cmd_check_stop(cmd, 1, 0);
ret = CMD_TFO(cmd)->write_pending(cmd);
if (ret < 0)
return ret;
return PYX_TRANSPORT_WRITE_PENDING;
}
void transport_release_cmd_to_pool(struct se_cmd *cmd)
{
BUG_ON(!T_TASK(cmd));
BUG_ON(!CMD_TFO(cmd));
transport_free_se_cmd(cmd);
CMD_TFO(cmd)->release_cmd_to_pool(cmd);
}
void transport_generic_free_cmd(
struct se_cmd *cmd,
int wait_for_tasks,
int release_to_pool,
int session_reinstatement)
{
if (!(cmd->se_cmd_flags & SCF_SE_LUN_CMD) || !T_TASK(cmd))
transport_release_cmd_to_pool(cmd);
else {
core_dec_lacl_count(cmd->se_sess->se_node_acl, cmd);
if (SE_LUN(cmd)) {
#if 0
printk(KERN_INFO "cmd: %p ITT: 0x%08x contains"
" SE_LUN(cmd)\n", cmd,
CMD_TFO(cmd)->get_task_tag(cmd));
#endif
transport_lun_remove_cmd(cmd);
}
if (wait_for_tasks && cmd->transport_wait_for_tasks)
cmd->transport_wait_for_tasks(cmd, 0, 0);
transport_free_dev_tasks(cmd);
transport_generic_remove(cmd, release_to_pool,
session_reinstatement);
}
}
static void transport_nop_wait_for_tasks(
struct se_cmd *cmd,
int remove_cmd,
int session_reinstatement)
{
return;
}
static int transport_lun_wait_for_tasks(struct se_cmd *cmd, struct se_lun *lun)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (atomic_read(&T_TASK(cmd)->t_transport_stop)) {
atomic_set(&T_TASK(cmd)->transport_lun_stop, 0);
DEBUG_TRANSPORT_S("ConfigFS ITT[0x%08x] - t_transport_stop =="
" TRUE, skipping\n", CMD_TFO(cmd)->get_task_tag(cmd));
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_cmd_check_stop(cmd, 1, 0);
return -1;
}
atomic_set(&T_TASK(cmd)->transport_lun_fe_stop, 1);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
wake_up_interruptible(&SE_DEV(cmd)->dev_queue_obj->thread_wq);
ret = transport_stop_tasks_for_cmd(cmd);
DEBUG_TRANSPORT_S("ConfigFS: cmd: %p t_task_cdbs: %d stop tasks ret:"
" %d\n", cmd, T_TASK(cmd)->t_task_cdbs, ret);
if (!ret) {
DEBUG_TRANSPORT_S("ConfigFS: ITT[0x%08x] - stopping cmd....\n",
CMD_TFO(cmd)->get_task_tag(cmd));
wait_for_completion(&T_TASK(cmd)->transport_lun_stop_comp);
DEBUG_TRANSPORT_S("ConfigFS: ITT[0x%08x] - stopped cmd....\n",
CMD_TFO(cmd)->get_task_tag(cmd));
}
transport_remove_cmd_from_queue(cmd, SE_DEV(cmd)->dev_queue_obj);
return 0;
}
static void __transport_clear_lun_from_sessions(struct se_lun *lun)
{
struct se_cmd *cmd = NULL;
unsigned long lun_flags, cmd_flags;
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
while (!list_empty_careful(&lun->lun_cmd_list)) {
cmd = list_entry(lun->lun_cmd_list.next,
struct se_cmd, se_lun_list);
list_del(&cmd->se_lun_list);
if (!(T_TASK(cmd))) {
printk(KERN_ERR "ITT: 0x%08x, T_TASK(cmd) = NULL"
"[i,t]_state: %u/%u\n",
CMD_TFO(cmd)->get_task_tag(cmd),
CMD_TFO(cmd)->get_cmd_state(cmd), cmd->t_state);
BUG();
}
atomic_set(&T_TASK(cmd)->transport_lun_active, 0);
spin_lock(&T_TASK(cmd)->t_state_lock);
DEBUG_CLEAR_L("SE_LUN[%d] - Setting T_TASK(cmd)->transport"
"_lun_stop for ITT: 0x%08x\n",
SE_LUN(cmd)->unpacked_lun,
CMD_TFO(cmd)->get_task_tag(cmd));
atomic_set(&T_TASK(cmd)->transport_lun_stop, 1);
spin_unlock(&T_TASK(cmd)->t_state_lock);
spin_unlock_irqrestore(&lun->lun_cmd_lock, lun_flags);
if (!(SE_LUN(cmd))) {
printk(KERN_ERR "ITT: 0x%08x, [i,t]_state: %u/%u\n",
CMD_TFO(cmd)->get_task_tag(cmd),
CMD_TFO(cmd)->get_cmd_state(cmd), cmd->t_state);
BUG();
}
DEBUG_CLEAR_L("SE_LUN[%d] - ITT: 0x%08x before transport"
"_lun_wait_for_tasks()\n", SE_LUN(cmd)->unpacked_lun,
CMD_TFO(cmd)->get_task_tag(cmd));
if (transport_lun_wait_for_tasks(cmd, SE_LUN(cmd)) < 0) {
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
continue;
}
DEBUG_CLEAR_L("SE_LUN[%d] - ITT: 0x%08x after transport_lun"
"_wait_for_tasks(): SUCCESS\n",
SE_LUN(cmd)->unpacked_lun,
CMD_TFO(cmd)->get_task_tag(cmd));
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, cmd_flags);
if (!(atomic_read(&T_TASK(cmd)->transport_dev_active))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, cmd_flags);
goto check_cond;
}
atomic_set(&T_TASK(cmd)->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, cmd_flags);
transport_free_dev_tasks(cmd);
check_cond:
transport_send_check_condition_and_sense(cmd,
TCM_NON_EXISTENT_LUN, 0);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, cmd_flags);
if (atomic_read(&T_TASK(cmd)->transport_lun_fe_stop)) {
DEBUG_CLEAR_L("SE_LUN[%d] - Detected FE stop for"
" struct se_cmd: %p ITT: 0x%08x\n",
lun->unpacked_lun,
cmd, CMD_TFO(cmd)->get_task_tag(cmd));
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
cmd_flags);
transport_cmd_check_stop(cmd, 1, 0);
complete(&T_TASK(cmd)->transport_lun_fe_stop_comp);
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
continue;
}
DEBUG_CLEAR_L("SE_LUN[%d] - ITT: 0x%08x finished processing\n",
lun->unpacked_lun, CMD_TFO(cmd)->get_task_tag(cmd));
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, cmd_flags);
spin_lock_irqsave(&lun->lun_cmd_lock, lun_flags);
}
spin_unlock_irqrestore(&lun->lun_cmd_lock, lun_flags);
}
static int transport_clear_lun_thread(void *p)
{
struct se_lun *lun = (struct se_lun *)p;
__transport_clear_lun_from_sessions(lun);
complete(&lun->lun_shutdown_comp);
return 0;
}
int transport_clear_lun_from_sessions(struct se_lun *lun)
{
struct task_struct *kt;
kt = kthread_run(transport_clear_lun_thread, (void *)lun,
"tcm_cl_%u", lun->unpacked_lun);
if (IS_ERR(kt)) {
printk(KERN_ERR "Unable to start clear_lun thread\n");
return -1;
}
wait_for_completion(&lun->lun_shutdown_comp);
return 0;
}
static void transport_generic_wait_for_tasks(
struct se_cmd *cmd,
int remove_cmd,
int session_reinstatement)
{
unsigned long flags;
if (!(cmd->se_cmd_flags & SCF_SE_LUN_CMD) && !(cmd->se_tmr_req))
return;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (atomic_read(&T_TASK(cmd)->transport_lun_stop)) {
DEBUG_TRANSPORT_S("wait_for_tasks: Stopping"
" wait_for_completion(&T_TASK(cmd)transport_lun_fe"
"_stop_comp); for ITT: 0x%08x\n",
CMD_TFO(cmd)->get_task_tag(cmd));
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
complete(&T_TASK(cmd)->transport_lun_stop_comp);
wait_for_completion(&T_TASK(cmd)->transport_lun_fe_stop_comp);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
transport_all_task_dev_remove_state(cmd);
DEBUG_TRANSPORT_S("wait_for_tasks: Stopped"
" wait_for_completion(&T_TASK(cmd)transport_lun_fe_"
"stop_comp); for ITT: 0x%08x\n",
CMD_TFO(cmd)->get_task_tag(cmd));
atomic_set(&T_TASK(cmd)->transport_lun_stop, 0);
}
if (!atomic_read(&T_TASK(cmd)->t_transport_active) ||
atomic_read(&T_TASK(cmd)->t_transport_aborted))
goto remove;
atomic_set(&T_TASK(cmd)->t_transport_stop, 1);
DEBUG_TRANSPORT_S("wait_for_tasks: Stopping %p ITT: 0x%08x"
" i_state: %d, t_state/def_t_state: %d/%d, t_transport_stop"
" = TRUE\n", cmd, CMD_TFO(cmd)->get_task_tag(cmd),
CMD_TFO(cmd)->get_cmd_state(cmd), cmd->t_state,
cmd->deferred_t_state);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
wake_up_interruptible(&SE_DEV(cmd)->dev_queue_obj->thread_wq);
wait_for_completion(&T_TASK(cmd)->t_transport_stop_comp);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
atomic_set(&T_TASK(cmd)->t_transport_active, 0);
atomic_set(&T_TASK(cmd)->t_transport_stop, 0);
DEBUG_TRANSPORT_S("wait_for_tasks: Stopped wait_for_compltion("
"&T_TASK(cmd)->t_transport_stop_comp) for ITT: 0x%08x\n",
CMD_TFO(cmd)->get_task_tag(cmd));
remove:
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
if (!remove_cmd)
return;
transport_generic_free_cmd(cmd, 0, 0, session_reinstatement);
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
int offset;
u8 asc = 0, ascq = 0;
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (cmd->se_cmd_flags & SCF_SENT_CHECK_CONDITION) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
return 0;
}
cmd->se_cmd_flags |= SCF_SENT_CHECK_CONDITION;
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
if (!reason && from_transport)
goto after_reason;
if (!from_transport)
cmd->se_cmd_flags |= SCF_EMULATED_TASK_SENSE;
offset = CMD_TFO(cmd)->set_fabric_sense_len(cmd,
TRANSPORT_SENSE_BUFFER);
switch (reason) {
case TCM_NON_EXISTENT_LUN:
case TCM_UNSUPPORTED_SCSI_OPCODE:
case TCM_SECTOR_COUNT_TOO_MANY:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x20;
break;
case TCM_UNKNOWN_MODE_PAGE:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x24;
break;
case TCM_CHECK_CONDITION_ABORT_CMD:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x29;
buffer[offset+SPC_ASCQ_KEY_OFFSET] = 0x03;
break;
case TCM_INCORRECT_AMOUNT_OF_DATA:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x0c;
buffer[offset+SPC_ASCQ_KEY_OFFSET] = 0x0d;
break;
case TCM_INVALID_CDB_FIELD:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x24;
break;
case TCM_INVALID_PARAMETER_LIST:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x26;
break;
case TCM_UNEXPECTED_UNSOLICITED_DATA:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x0c;
buffer[offset+SPC_ASCQ_KEY_OFFSET] = 0x0c;
break;
case TCM_SERVICE_CRC_ERROR:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x47;
buffer[offset+SPC_ASCQ_KEY_OFFSET] = 0x05;
break;
case TCM_SNACK_REJECTED:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ABORTED_COMMAND;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x11;
buffer[offset+SPC_ASCQ_KEY_OFFSET] = 0x13;
break;
case TCM_WRITE_PROTECTED:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = DATA_PROTECT;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x27;
break;
case TCM_CHECK_CONDITION_UNIT_ATTENTION:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = UNIT_ATTENTION;
core_scsi3_ua_for_check_condition(cmd, &asc, &ascq);
buffer[offset+SPC_ASC_KEY_OFFSET] = asc;
buffer[offset+SPC_ASCQ_KEY_OFFSET] = ascq;
break;
case TCM_CHECK_CONDITION_NOT_READY:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = NOT_READY;
transport_get_sense_codes(cmd, &asc, &ascq);
buffer[offset+SPC_ASC_KEY_OFFSET] = asc;
buffer[offset+SPC_ASCQ_KEY_OFFSET] = ascq;
break;
case TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE:
default:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x80;
break;
}
cmd->scsi_status = SAM_STAT_CHECK_CONDITION;
cmd->scsi_sense_length = TRANSPORT_SENSE_BUFFER + offset;
after_reason:
CMD_TFO(cmd)->queue_status(cmd);
return 0;
}
int transport_check_aborted_status(struct se_cmd *cmd, int send_status)
{
int ret = 0;
if (atomic_read(&T_TASK(cmd)->t_transport_aborted) != 0) {
if (!(send_status) ||
(cmd->se_cmd_flags & SCF_SENT_DELAYED_TAS))
return 1;
#if 0
printk(KERN_INFO "Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
T_TASK(cmd)->t_task_cdb[0],
CMD_TFO(cmd)->get_task_tag(cmd));
#endif
cmd->se_cmd_flags |= SCF_SENT_DELAYED_TAS;
CMD_TFO(cmd)->queue_status(cmd);
ret = 1;
}
return ret;
}
void transport_send_task_abort(struct se_cmd *cmd)
{
if (cmd->data_direction == DMA_TO_DEVICE) {
if (CMD_TFO(cmd)->write_pending_status(cmd) != 0) {
atomic_inc(&T_TASK(cmd)->t_transport_aborted);
smp_mb__after_atomic_inc();
cmd->scsi_status = SAM_STAT_TASK_ABORTED;
transport_new_cmd_failure(cmd);
return;
}
}
cmd->scsi_status = SAM_STAT_TASK_ABORTED;
#if 0
printk(KERN_INFO "Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", T_TASK(cmd)->t_task_cdb[0],
CMD_TFO(cmd)->get_task_tag(cmd));
#endif
CMD_TFO(cmd)->queue_status(cmd);
}
int transport_generic_do_tmr(struct se_cmd *cmd)
{
struct se_cmd *ref_cmd;
struct se_device *dev = SE_DEV(cmd);
struct se_tmr_req *tmr = cmd->se_tmr_req;
int ret;
switch (tmr->function) {
case TMR_ABORT_TASK:
ref_cmd = tmr->ref_cmd;
tmr->response = TMR_FUNCTION_REJECTED;
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
printk(KERN_ERR "Uknown TMR function: 0x%02x.\n",
tmr->function);
tmr->response = TMR_FUNCTION_REJECTED;
break;
}
cmd->t_state = TRANSPORT_ISTATE_PROCESSING;
CMD_TFO(cmd)->queue_tm_rsp(cmd);
transport_cmd_check_stop(cmd, 2, 0);
return 0;
}
static struct se_task *
transport_get_task_from_state_list(struct se_device *dev)
{
struct se_task *task;
if (list_empty(&dev->state_task_list))
return NULL;
list_for_each_entry(task, &dev->state_task_list, t_state_list)
break;
list_del(&task->t_state_list);
atomic_set(&task->task_state_active, 0);
return task;
}
static void transport_processing_shutdown(struct se_device *dev)
{
struct se_cmd *cmd;
struct se_queue_req *qr;
struct se_task *task;
u8 state;
unsigned long flags;
spin_lock_irqsave(&dev->execute_task_lock, flags);
while ((task = transport_get_task_from_state_list(dev))) {
if (!(TASK_CMD(task))) {
printk(KERN_ERR "TASK_CMD(task) is NULL!\n");
continue;
}
cmd = TASK_CMD(task);
if (!T_TASK(cmd)) {
printk(KERN_ERR "T_TASK(cmd) is NULL for task: %p cmd:"
" %p ITT: 0x%08x\n", task, cmd,
CMD_TFO(cmd)->get_task_tag(cmd));
continue;
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
DEBUG_DO("PT: cmd: %p task: %p ITT/CmdSN: 0x%08x/0x%08x,"
" i_state/def_i_state: %d/%d, t_state/def_t_state:"
" %d/%d cdb: 0x%02x\n", cmd, task,
CMD_TFO(cmd)->get_task_tag(cmd), cmd->cmd_sn,
CMD_TFO(cmd)->get_cmd_state(cmd), cmd->deferred_i_state,
cmd->t_state, cmd->deferred_t_state,
T_TASK(cmd)->t_task_cdb[0]);
DEBUG_DO("PT: ITT[0x%08x] - t_task_cdbs: %d t_task_cdbs_left:"
" %d t_task_cdbs_sent: %d -- t_transport_active: %d"
" t_transport_stop: %d t_transport_sent: %d\n",
CMD_TFO(cmd)->get_task_tag(cmd),
T_TASK(cmd)->t_task_cdbs,
atomic_read(&T_TASK(cmd)->t_task_cdbs_left),
atomic_read(&T_TASK(cmd)->t_task_cdbs_sent),
atomic_read(&T_TASK(cmd)->t_transport_active),
atomic_read(&T_TASK(cmd)->t_transport_stop),
atomic_read(&T_TASK(cmd)->t_transport_sent));
if (atomic_read(&task->task_active)) {
atomic_set(&task->task_stop, 1);
spin_unlock_irqrestore(
&T_TASK(cmd)->t_state_lock, flags);
DEBUG_DO("Waiting for task: %p to shutdown for dev:"
" %p\n", task, dev);
wait_for_completion(&task->task_stop_comp);
DEBUG_DO("Completed task: %p shutdown for dev: %p\n",
task, dev);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
atomic_dec(&T_TASK(cmd)->t_task_cdbs_left);
atomic_set(&task->task_active, 0);
atomic_set(&task->task_stop, 0);
} else {
if (atomic_read(&task->task_execute_queue) != 0)
transport_remove_task_from_execute_queue(task, dev);
}
__transport_stop_task_timer(task, &flags);
if (!(atomic_dec_and_test(&T_TASK(cmd)->t_task_cdbs_ex_left))) {
spin_unlock_irqrestore(
&T_TASK(cmd)->t_state_lock, flags);
DEBUG_DO("Skipping task: %p, dev: %p for"
" t_task_cdbs_ex_left: %d\n", task, dev,
atomic_read(&T_TASK(cmd)->t_task_cdbs_ex_left));
spin_lock_irqsave(&dev->execute_task_lock, flags);
continue;
}
if (atomic_read(&T_TASK(cmd)->t_transport_active)) {
DEBUG_DO("got t_transport_active = 1 for task: %p, dev:"
" %p\n", task, dev);
if (atomic_read(&T_TASK(cmd)->t_fe_count)) {
spin_unlock_irqrestore(
&T_TASK(cmd)->t_state_lock, flags);
transport_send_check_condition_and_sense(
cmd, TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE,
0);
transport_remove_cmd_from_queue(cmd,
SE_DEV(cmd)->dev_queue_obj);
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop(cmd, 1, 0);
} else {
spin_unlock_irqrestore(
&T_TASK(cmd)->t_state_lock, flags);
transport_remove_cmd_from_queue(cmd,
SE_DEV(cmd)->dev_queue_obj);
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop(cmd, 1, 0))
transport_generic_remove(cmd, 0, 0);
}
spin_lock_irqsave(&dev->execute_task_lock, flags);
continue;
}
DEBUG_DO("Got t_transport_active = 0 for task: %p, dev: %p\n",
task, dev);
if (atomic_read(&T_TASK(cmd)->t_fe_count)) {
spin_unlock_irqrestore(
&T_TASK(cmd)->t_state_lock, flags);
transport_send_check_condition_and_sense(cmd,
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE, 0);
transport_remove_cmd_from_queue(cmd,
SE_DEV(cmd)->dev_queue_obj);
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop(cmd, 1, 0);
} else {
spin_unlock_irqrestore(
&T_TASK(cmd)->t_state_lock, flags);
transport_remove_cmd_from_queue(cmd,
SE_DEV(cmd)->dev_queue_obj);
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop(cmd, 1, 0))
transport_generic_remove(cmd, 0, 0);
}
spin_lock_irqsave(&dev->execute_task_lock, flags);
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
spin_lock_irqsave(&dev->dev_queue_obj->cmd_queue_lock, flags);
while ((qr = __transport_get_qr_from_queue(dev->dev_queue_obj))) {
spin_unlock_irqrestore(
&dev->dev_queue_obj->cmd_queue_lock, flags);
cmd = (struct se_cmd *)qr->cmd;
state = qr->state;
kfree(qr);
DEBUG_DO("From Device Queue: cmd: %p t_state: %d\n",
cmd, state);
if (atomic_read(&T_TASK(cmd)->t_fe_count)) {
transport_send_check_condition_and_sense(cmd,
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE, 0);
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop(cmd, 1, 0);
} else {
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop(cmd, 1, 0))
transport_generic_remove(cmd, 0, 0);
}
spin_lock_irqsave(&dev->dev_queue_obj->cmd_queue_lock, flags);
}
spin_unlock_irqrestore(&dev->dev_queue_obj->cmd_queue_lock, flags);
}
static int transport_processing_thread(void *param)
{
int ret, t_state;
struct se_cmd *cmd;
struct se_device *dev = (struct se_device *) param;
struct se_queue_req *qr;
set_user_nice(current, -20);
while (!kthread_should_stop()) {
ret = wait_event_interruptible(dev->dev_queue_obj->thread_wq,
atomic_read(&dev->dev_queue_obj->queue_cnt) ||
kthread_should_stop());
if (ret < 0)
goto out;
spin_lock_irq(&dev->dev_status_lock);
if (dev->dev_status & TRANSPORT_DEVICE_SHUTDOWN) {
spin_unlock_irq(&dev->dev_status_lock);
transport_processing_shutdown(dev);
continue;
}
spin_unlock_irq(&dev->dev_status_lock);
get_cmd:
__transport_execute_tasks(dev);
qr = transport_get_qr_from_queue(dev->dev_queue_obj);
if (!(qr))
continue;
cmd = (struct se_cmd *)qr->cmd;
t_state = qr->state;
kfree(qr);
switch (t_state) {
case TRANSPORT_NEW_CMD_MAP:
if (!(CMD_TFO(cmd)->new_cmd_map)) {
printk(KERN_ERR "CMD_TFO(cmd)->new_cmd_map is"
" NULL for TRANSPORT_NEW_CMD_MAP\n");
BUG();
}
ret = CMD_TFO(cmd)->new_cmd_map(cmd);
if (ret < 0) {
cmd->transport_error_status = ret;
transport_generic_request_failure(cmd, NULL,
0, (cmd->data_direction !=
DMA_TO_DEVICE));
break;
}
case TRANSPORT_NEW_CMD:
ret = transport_generic_new_cmd(cmd);
if (ret < 0) {
cmd->transport_error_status = ret;
transport_generic_request_failure(cmd, NULL,
0, (cmd->data_direction !=
DMA_TO_DEVICE));
}
break;
case TRANSPORT_PROCESS_WRITE:
transport_generic_process_write(cmd);
break;
case TRANSPORT_COMPLETE_OK:
transport_stop_all_task_timers(cmd);
transport_generic_complete_ok(cmd);
break;
case TRANSPORT_REMOVE:
transport_generic_remove(cmd, 1, 0);
break;
case TRANSPORT_FREE_CMD_INTR:
transport_generic_free_cmd(cmd, 0, 1, 0);
break;
case TRANSPORT_PROCESS_TMR:
transport_generic_do_tmr(cmd);
break;
case TRANSPORT_COMPLETE_FAILURE:
transport_generic_request_failure(cmd, NULL, 1, 1);
break;
case TRANSPORT_COMPLETE_TIMEOUT:
transport_stop_all_task_timers(cmd);
transport_generic_request_timeout(cmd);
break;
default:
printk(KERN_ERR "Unknown t_state: %d deferred_t_state:"
" %d for ITT: 0x%08x i_state: %d on SE LUN:"
" %u\n", t_state, cmd->deferred_t_state,
CMD_TFO(cmd)->get_task_tag(cmd),
CMD_TFO(cmd)->get_cmd_state(cmd),
SE_LUN(cmd)->unpacked_lun);
BUG();
}
goto get_cmd;
}
out:
transport_release_all_cmds(dev);
dev->process_thread = NULL;
return 0;
}
