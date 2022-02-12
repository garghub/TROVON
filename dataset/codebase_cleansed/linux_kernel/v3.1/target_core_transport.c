int init_se_kmem_caches(void)
{
se_cmd_cache = kmem_cache_create("se_cmd_cache",
sizeof(struct se_cmd), __alignof__(struct se_cmd), 0, NULL);
if (!se_cmd_cache) {
pr_err("kmem_cache_create for struct se_cmd failed\n");
goto out;
}
se_tmr_req_cache = kmem_cache_create("se_tmr_cache",
sizeof(struct se_tmr_req), __alignof__(struct se_tmr_req),
0, NULL);
if (!se_tmr_req_cache) {
pr_err("kmem_cache_create() for struct se_tmr_req"
" failed\n");
goto out;
}
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
goto out;
}
t10_pr_reg_cache = kmem_cache_create("t10_pr_reg_cache",
sizeof(struct t10_pr_registration),
__alignof__(struct t10_pr_registration), 0, NULL);
if (!t10_pr_reg_cache) {
pr_err("kmem_cache_create() for struct t10_pr_registration"
" failed\n");
goto out;
}
t10_alua_lu_gp_cache = kmem_cache_create("t10_alua_lu_gp_cache",
sizeof(struct t10_alua_lu_gp), __alignof__(struct t10_alua_lu_gp),
0, NULL);
if (!t10_alua_lu_gp_cache) {
pr_err("kmem_cache_create() for t10_alua_lu_gp_cache"
" failed\n");
goto out;
}
t10_alua_lu_gp_mem_cache = kmem_cache_create("t10_alua_lu_gp_mem_cache",
sizeof(struct t10_alua_lu_gp_member),
__alignof__(struct t10_alua_lu_gp_member), 0, NULL);
if (!t10_alua_lu_gp_mem_cache) {
pr_err("kmem_cache_create() for t10_alua_lu_gp_mem_"
"cache failed\n");
goto out;
}
t10_alua_tg_pt_gp_cache = kmem_cache_create("t10_alua_tg_pt_gp_cache",
sizeof(struct t10_alua_tg_pt_gp),
__alignof__(struct t10_alua_tg_pt_gp), 0, NULL);
if (!t10_alua_tg_pt_gp_cache) {
pr_err("kmem_cache_create() for t10_alua_tg_pt_gp_"
"cache failed\n");
goto out;
}
t10_alua_tg_pt_gp_mem_cache = kmem_cache_create(
"t10_alua_tg_pt_gp_mem_cache",
sizeof(struct t10_alua_tg_pt_gp_member),
__alignof__(struct t10_alua_tg_pt_gp_member),
0, NULL);
if (!t10_alua_tg_pt_gp_mem_cache) {
pr_err("kmem_cache_create() for t10_alua_tg_pt_gp_"
"mem_t failed\n");
goto out;
}
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
return -ENOMEM;
}
void release_se_kmem_caches(void)
{
kmem_cache_destroy(se_cmd_cache);
kmem_cache_destroy(se_tmr_req_cache);
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
pr_err("Unable to load target_core_iblock\n");
ret = request_module("target_core_file");
if (ret != 0)
pr_err("Unable to load target_core_file\n");
ret = request_module("target_core_pscsi");
if (ret != 0)
pr_err("Unable to load target_core_pscsi\n");
ret = request_module("target_core_stgt");
if (ret != 0)
pr_err("Unable to load target_core_stgt\n");
return 0;
}
int transport_subsystem_check_init(void)
{
int ret;
if (sub_api_initialized)
return 0;
ret = transport_subsystem_reqmods();
if (ret < 0)
return ret;
sub_api_initialized = 1;
return 0;
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
spin_lock_bh(&se_tpg->session_lock);
__transport_register_session(se_tpg, se_nacl, se_sess, fabric_sess_ptr);
spin_unlock_bh(&se_tpg->session_lock);
}
void transport_deregister_session_configfs(struct se_session *se_sess)
{
struct se_node_acl *se_nacl;
unsigned long flags;
se_nacl = se_sess->se_node_acl;
if (se_nacl) {
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
unsigned long flags;
if (!se_tpg) {
transport_free_session(se_sess);
return;
}
spin_lock_irqsave(&se_tpg->session_lock, flags);
list_del(&se_sess->sess_list);
se_sess->se_tpg = NULL;
se_sess->fabric_sess_ptr = NULL;
spin_unlock_irqrestore(&se_tpg->session_lock, flags);
se_nacl = se_sess->se_node_acl;
if (se_nacl) {
spin_lock_irqsave(&se_tpg->acl_node_lock, flags);
if (se_nacl->dynamic_node_acl) {
if (!se_tpg->se_tpg_tfo->tpg_check_demo_mode_cache(
se_tpg)) {
list_del(&se_nacl->acl_list);
se_tpg->num_node_acls--;
spin_unlock_irqrestore(&se_tpg->acl_node_lock, flags);
core_tpg_wait_for_nacl_pr_ref(se_nacl);
core_free_device_list_for_node(se_nacl, se_tpg);
se_tpg->se_tpg_tfo->tpg_release_fabric_acl(se_tpg,
se_nacl);
spin_lock_irqsave(&se_tpg->acl_node_lock, flags);
}
}
spin_unlock_irqrestore(&se_tpg->acl_node_lock, flags);
}
transport_free_session(se_sess);
pr_debug("TARGET_CORE[%s]: Deregistered fabric_sess\n",
se_tpg->se_tpg_tfo->get_fabric_name());
}
static void transport_all_task_dev_remove_state(struct se_cmd *cmd)
{
struct se_device *dev;
struct se_task *task;
unsigned long flags;
list_for_each_entry(task, &cmd->t_task_list, t_list) {
dev = task->se_dev;
if (!dev)
continue;
if (atomic_read(&task->task_active))
continue;
if (!atomic_read(&task->task_state_active))
continue;
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_del(&task->t_state_list);
pr_debug("Removed ITT: 0x%08x dev: %p task[%p]\n",
cmd->se_tfo->get_task_tag(cmd), dev, task);
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
atomic_set(&task->task_state_active, 0);
atomic_dec(&cmd->t_task_cdbs_ex_left);
}
}
static int transport_cmd_check_stop(
struct se_cmd *cmd,
int transport_off,
u8 t_state)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (atomic_read(&cmd->transport_lun_stop)) {
pr_debug("%s:%d atomic_read(&cmd->transport_lun_stop)"
" == TRUE for ITT: 0x%08x\n", __func__, __LINE__,
cmd->se_tfo->get_task_tag(cmd));
cmd->deferred_t_state = cmd->t_state;
cmd->t_state = TRANSPORT_DEFERRED_CMD;
atomic_set(&cmd->t_transport_active, 0);
if (transport_off == 2)
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->transport_lun_stop_comp);
return 1;
}
if (atomic_read(&cmd->t_transport_stop)) {
pr_debug("%s:%d atomic_read(&cmd->t_transport_stop) =="
" TRUE for ITT: 0x%08x\n", __func__, __LINE__,
cmd->se_tfo->get_task_tag(cmd));
cmd->deferred_t_state = cmd->t_state;
cmd->t_state = TRANSPORT_DEFERRED_CMD;
if (transport_off == 2)
transport_all_task_dev_remove_state(cmd);
if (transport_off == 2)
cmd->se_lun = NULL;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->t_transport_stop_comp);
return 1;
}
if (transport_off) {
atomic_set(&cmd->t_transport_active, 0);
if (transport_off == 2) {
transport_all_task_dev_remove_state(cmd);
cmd->se_lun = NULL;
if (cmd->se_tfo->check_stop_free != NULL) {
spin_unlock_irqrestore(
&cmd->t_state_lock, flags);
cmd->se_tfo->check_stop_free(cmd);
return 1;
}
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return 0;
} else if (t_state)
cmd->t_state = t_state;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return 0;
}
static int transport_cmd_check_stop_to_fabric(struct se_cmd *cmd)
{
return transport_cmd_check_stop(cmd, 2, 0);
}
static void transport_lun_remove_cmd(struct se_cmd *cmd)
{
struct se_lun *lun = cmd->se_lun;
unsigned long flags;
if (!lun)
return;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (!atomic_read(&cmd->transport_dev_active)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
goto check_lun;
}
atomic_set(&cmd->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
check_lun:
spin_lock_irqsave(&lun->lun_cmd_lock, flags);
if (atomic_read(&cmd->transport_lun_active)) {
list_del(&cmd->se_lun_node);
atomic_set(&cmd->transport_lun_active, 0);
#if 0
pr_debug("Removed ITT: 0x%08x from LUN LIST[%d]\n"
cmd->se_tfo->get_task_tag(cmd), lun->unpacked_lun);
#endif
}
spin_unlock_irqrestore(&lun->lun_cmd_lock, flags);
}
void transport_cmd_finish_abort(struct se_cmd *cmd, int remove)
{
transport_remove_cmd_from_queue(cmd, &cmd->se_dev->dev_queue_obj);
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop_to_fabric(cmd))
return;
if (remove)
transport_generic_remove(cmd, 0);
}
void transport_cmd_finish_abort_tmr(struct se_cmd *cmd)
{
transport_remove_cmd_from_queue(cmd, &cmd->se_dev->dev_queue_obj);
if (transport_cmd_check_stop_to_fabric(cmd))
return;
transport_generic_remove(cmd, 0);
}
static void transport_add_cmd_to_queue(
struct se_cmd *cmd,
int t_state)
{
struct se_device *dev = cmd->se_dev;
struct se_queue_obj *qobj = &dev->dev_queue_obj;
unsigned long flags;
INIT_LIST_HEAD(&cmd->se_queue_node);
if (t_state) {
spin_lock_irqsave(&cmd->t_state_lock, flags);
cmd->t_state = t_state;
atomic_set(&cmd->t_transport_active, 1);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
}
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
if (cmd->se_cmd_flags & SCF_EMULATE_QUEUE_FULL) {
cmd->se_cmd_flags &= ~SCF_EMULATE_QUEUE_FULL;
list_add(&cmd->se_queue_node, &qobj->qobj_list);
} else
list_add_tail(&cmd->se_queue_node, &qobj->qobj_list);
atomic_inc(&cmd->t_transport_queue_active);
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
atomic_inc(&qobj->queue_cnt);
wake_up_interruptible(&qobj->thread_wq);
}
static struct se_cmd *
transport_get_cmd_from_queue(struct se_queue_obj *qobj)
{
struct se_cmd *cmd;
unsigned long flags;
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
if (list_empty(&qobj->qobj_list)) {
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
return NULL;
}
cmd = list_first_entry(&qobj->qobj_list, struct se_cmd, se_queue_node);
atomic_dec(&cmd->t_transport_queue_active);
list_del(&cmd->se_queue_node);
atomic_dec(&qobj->queue_cnt);
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
return cmd;
}
static void transport_remove_cmd_from_queue(struct se_cmd *cmd,
struct se_queue_obj *qobj)
{
struct se_cmd *t;
unsigned long flags;
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
if (!atomic_read(&cmd->t_transport_queue_active)) {
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
return;
}
list_for_each_entry(t, &qobj->qobj_list, se_queue_node)
if (t == cmd) {
atomic_dec(&cmd->t_transport_queue_active);
atomic_dec(&qobj->queue_cnt);
list_del(&cmd->se_queue_node);
break;
}
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
if (atomic_read(&cmd->t_transport_queue_active)) {
pr_err("ITT: 0x%08x t_transport_queue_active: %d\n",
cmd->se_tfo->get_task_tag(cmd),
atomic_read(&cmd->t_transport_queue_active));
}
}
void transport_complete_sync_cache(struct se_cmd *cmd, int good)
{
struct se_task *task = list_entry(cmd->t_task_list.next,
struct se_task, t_list);
if (good) {
cmd->scsi_status = SAM_STAT_GOOD;
task->task_scsi_status = GOOD;
} else {
task->task_scsi_status = SAM_STAT_CHECK_CONDITION;
task->task_error_status = PYX_TRANSPORT_ILLEGAL_REQUEST;
task->task_se_cmd->transport_error_status =
PYX_TRANSPORT_ILLEGAL_REQUEST;
}
transport_complete_task(task, good);
}
void transport_complete_task(struct se_task *task, int success)
{
struct se_cmd *cmd = task->task_se_cmd;
struct se_device *dev = task->se_dev;
int t_state;
unsigned long flags;
#if 0
pr_debug("task: %p CDB: 0x%02x obj_ptr: %p\n", task,
cmd->t_task_cdb[0], dev);
#endif
if (dev)
atomic_inc(&dev->depth_left);
spin_lock_irqsave(&cmd->t_state_lock, flags);
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
atomic_dec(&cmd->t_se_count);
atomic_set(&task->task_timeout, 0);
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&task->task_stop_comp);
return;
}
if (atomic_read(&task->task_timeout)) {
if (!atomic_dec_and_test(
&cmd->t_task_cdbs_timeout_left)) {
spin_unlock_irqrestore(&cmd->t_state_lock,
flags);
return;
}
t_state = TRANSPORT_COMPLETE_TIMEOUT;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_add_cmd_to_queue(cmd, t_state);
return;
}
atomic_dec(&cmd->t_task_cdbs_timeout_left);
if (!atomic_dec_and_test(&cmd->t_task_cdbs_left)) {
if (!success)
cmd->t_tasks_failed = 1;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return;
}
if (!success || cmd->t_tasks_failed) {
t_state = TRANSPORT_COMPLETE_FAILURE;
if (!task->task_error_status) {
task->task_error_status =
PYX_TRANSPORT_UNKNOWN_SAM_OPCODE;
cmd->transport_error_status =
PYX_TRANSPORT_UNKNOWN_SAM_OPCODE;
}
} else {
atomic_set(&cmd->t_transport_complete, 1);
t_state = TRANSPORT_COMPLETE_OK;
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
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
pr_debug("Set HEAD_OF_QUEUE for task CDB: 0x%02x"
" in execution queue\n",
task->task_se_cmd->t_task_cdb[0]);
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
pr_debug("Added ITT: 0x%08x task[%p] to dev: %p\n",
task->task_se_cmd->se_tfo->get_task_tag(task->task_se_cmd),
task, dev);
}
static void transport_add_tasks_to_state_queue(struct se_cmd *cmd)
{
struct se_device *dev;
struct se_task *task;
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
list_for_each_entry(task, &cmd->t_task_list, t_list) {
dev = task->se_dev;
if (atomic_read(&task->task_state_active))
continue;
spin_lock(&dev->execute_task_lock);
list_add_tail(&task->t_state_list, &dev->state_task_list);
atomic_set(&task->task_state_active, 1);
pr_debug("Added ITT: 0x%08x task[%p] to dev: %p\n",
task->task_se_cmd->se_tfo->get_task_tag(
task->task_se_cmd), task, dev);
spin_unlock(&dev->execute_task_lock);
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
}
static void transport_add_tasks_from_cmd(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_task *task, *task_prev = NULL;
unsigned long flags;
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_for_each_entry(task, &cmd->t_task_list, t_list) {
if (atomic_read(&task->task_execute_queue))
continue;
__transport_add_task_to_execute_queue(task, task_prev, dev);
atomic_set(&task->task_execute_queue, 1);
task_prev = task;
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
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
(cmd->t_state == TRANSPORT_COMPLETE_OK) ? "COMPLETE_OK" :
(cmd->t_state == TRANSPORT_COMPLETE_QF_WP) ? "WRITE_PENDING"
: "UNKNOWN");
transport_add_cmd_to_queue(cmd, cmd->t_state);
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
*bl += sprintf(b + *bl, " Execute/Left/Max Queue Depth: %d/%d/%d",
atomic_read(&dev->execute_tasks), atomic_read(&dev->depth_left),
dev->queue_depth);
*bl += sprintf(b + *bl, " SectorSize: %u MaxSectors: %u\n",
dev->se_sub_dev->se_dev_attrib.block_size, dev->se_sub_dev->se_dev_attrib.max_sectors);
*bl += sprintf(b + *bl, " ");
}
static void transport_release_all_cmds(struct se_device *dev)
{
struct se_cmd *cmd, *tcmd;
int bug_out = 0, t_state;
unsigned long flags;
spin_lock_irqsave(&dev->dev_queue_obj.cmd_queue_lock, flags);
list_for_each_entry_safe(cmd, tcmd, &dev->dev_queue_obj.qobj_list,
se_queue_node) {
t_state = cmd->t_state;
list_del(&cmd->se_queue_node);
spin_unlock_irqrestore(&dev->dev_queue_obj.cmd_queue_lock,
flags);
pr_err("Releasing ITT: 0x%08x, i_state: %u,"
" t_state: %u directly\n",
cmd->se_tfo->get_task_tag(cmd),
cmd->se_tfo->get_cmd_state(cmd), t_state);
transport_release_fe_cmd(cmd);
bug_out = 1;
spin_lock_irqsave(&dev->dev_queue_obj.cmd_queue_lock, flags);
}
spin_unlock_irqrestore(&dev->dev_queue_obj.cmd_queue_lock, flags);
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
int i, device_type;
pr_debug(" Vendor: ");
for (i = 0; i < 8; i++)
if (wwn->vendor[i] >= 0x20)
pr_debug("%c", wwn->vendor[i]);
else
pr_debug(" ");
pr_debug(" Model: ");
for (i = 0; i < 16; i++)
if (wwn->model[i] >= 0x20)
pr_debug("%c", wwn->model[i]);
else
pr_debug(" ");
pr_debug(" Revision: ");
for (i = 0; i < 4; i++)
if (wwn->revision[i] >= 0x20)
pr_debug("%c", wwn->revision[i]);
else
pr_debug(" ");
pr_debug("\n");
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
transport_init_queue_obj(&dev->dev_queue_obj);
dev->dev_flags = device_flags;
dev->dev_status |= TRANSPORT_DEVICE_DEACTIVATED;
dev->dev_ptr = transport_dev;
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
INIT_LIST_HEAD(&dev->qf_cmd_list);
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
spin_lock_init(&dev->qf_cmd_lock);
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
"LIO_%s", dev->transport->name);
if (IS_ERR(dev->process_thread)) {
pr_err("Unable to create kthread: LIO_%s\n",
dev->transport->name);
goto out;
}
INIT_WORK(&dev->qf_work_queue, target_qf_do_work);
if (dev->transport->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV) {
if (!inquiry_prod || !inquiry_rev) {
pr_err("All non TCM/pSCSI plugins require"
" INQUIRY consts\n");
goto out;
}
strncpy(&dev->se_sub_dev->t10_wwn.vendor[0], "LIO-ORG", 8);
strncpy(&dev->se_sub_dev->t10_wwn.model[0], inquiry_prod, 16);
strncpy(&dev->se_sub_dev->t10_wwn.revision[0], inquiry_rev, 4);
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
struct se_device *dev = cmd->se_dev;
task = dev->transport->alloc_task(cmd->t_task_cdb);
if (!task) {
pr_err("Unable to allocate struct se_task\n");
return NULL;
}
INIT_LIST_HEAD(&task->t_list);
INIT_LIST_HEAD(&task->t_execute_list);
INIT_LIST_HEAD(&task->t_state_list);
init_completion(&task->task_stop_comp);
task->task_se_cmd = cmd;
task->se_dev = dev;
task->task_data_direction = data_direction;
return task;
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
INIT_LIST_HEAD(&cmd->se_ordered_node);
INIT_LIST_HEAD(&cmd->se_qf_node);
INIT_LIST_HEAD(&cmd->t_task_list);
init_completion(&cmd->transport_lun_fe_stop_comp);
init_completion(&cmd->transport_lun_stop_comp);
init_completion(&cmd->t_transport_stop_comp);
spin_lock_init(&cmd->t_state_lock);
atomic_set(&cmd->transport_dev_active, 1);
cmd->se_tfo = tfo;
cmd->se_sess = se_sess;
cmd->data_length = data_length;
cmd->data_direction = data_direction;
cmd->sam_task_attr = task_attr;
cmd->sense_buffer = sense_buffer;
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
void transport_free_se_cmd(
struct se_cmd *se_cmd)
{
if (se_cmd->se_tmr_req)
core_tmr_release_req(se_cmd->se_tmr_req);
if (se_cmd->t_task_cdb != se_cmd->__t_task_cdb)
kfree(se_cmd->t_task_cdb);
}
int transport_generic_allocate_tasks(
struct se_cmd *cmd,
unsigned char *cdb)
{
int ret;
transport_generic_prepare_cdb(cdb);
cmd->transport_wait_for_tasks = &transport_generic_wait_for_tasks;
if (scsi_command_size(cdb) > SCSI_MAX_VARLEN_CDB_SIZE) {
pr_err("Received SCSI CDB with command_size: %d that"
" exceeds SCSI_MAX_VARLEN_CDB_SIZE: %d\n",
scsi_command_size(cdb), SCSI_MAX_VARLEN_CDB_SIZE);
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
return -ENOMEM;
}
} else
cmd->t_task_cdb = &cmd->__t_task_cdb[0];
memcpy(cmd->t_task_cdb, cdb, scsi_command_size(cdb));
ret = transport_generic_cmd_sequencer(cmd, cdb);
if (ret < 0)
return ret;
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
int transport_generic_handle_cdb(
struct se_cmd *cmd)
{
if (!cmd->se_lun) {
dump_stack();
pr_err("cmd->se_lun is NULL\n");
return -EINVAL;
}
transport_add_cmd_to_queue(cmd, TRANSPORT_NEW_CMD);
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
atomic_set(&cmd->t_transport_active, 1);
ret = transport_generic_new_cmd(cmd);
if (ret == -EAGAIN)
return 0;
else if (ret < 0) {
cmd->transport_error_status = ret;
transport_generic_request_failure(cmd, NULL, 0,
(cmd->data_direction != DMA_TO_DEVICE));
}
return 0;
}
int transport_generic_handle_cdb_map(
struct se_cmd *cmd)
{
if (!cmd->se_lun) {
dump_stack();
pr_err("cmd->se_lun is NULL\n");
return -EINVAL;
}
transport_add_cmd_to_queue(cmd, TRANSPORT_NEW_CMD_MAP);
return 0;
}
int transport_generic_handle_data(
struct se_cmd *cmd)
{
if (!in_interrupt() && signal_pending(current))
return -EPERM;
if (transport_check_aborted_status(cmd, 1) != 0)
return 0;
transport_add_cmd_to_queue(cmd, TRANSPORT_PROCESS_WRITE);
return 0;
}
int transport_generic_handle_tmr(
struct se_cmd *cmd)
{
cmd->transport_wait_for_tasks = &transport_generic_wait_for_tasks;
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
pr_debug("ITT[0x%08x] - Stopping tasks\n",
cmd->se_tfo->get_task_tag(cmd));
spin_lock_irqsave(&cmd->t_state_lock, flags);
list_for_each_entry_safe(task, task_tmp,
&cmd->t_task_list, t_list) {
pr_debug("task_no[%d] - Processing task %p\n",
task->task_no, task);
if (!atomic_read(&task->task_sent) &&
!atomic_read(&task->task_active)) {
spin_unlock_irqrestore(&cmd->t_state_lock,
flags);
transport_remove_task_from_execute_queue(task,
task->se_dev);
pr_debug("task_no[%d] - Removed from execute queue\n",
task->task_no);
spin_lock_irqsave(&cmd->t_state_lock, flags);
continue;
}
if (atomic_read(&task->task_active)) {
atomic_set(&task->task_stop, 1);
spin_unlock_irqrestore(&cmd->t_state_lock,
flags);
pr_debug("task_no[%d] - Waiting to complete\n",
task->task_no);
wait_for_completion(&task->task_stop_comp);
pr_debug("task_no[%d] - Stopped successfully\n",
task->task_no);
spin_lock_irqsave(&cmd->t_state_lock, flags);
atomic_dec(&cmd->t_task_cdbs_left);
atomic_set(&task->task_active, 0);
atomic_set(&task->task_stop, 0);
} else {
pr_debug("task_no[%d] - Did nothing\n", task->task_no);
ret++;
}
__transport_stop_task_timer(task, &flags);
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return ret;
}
static void transport_generic_request_failure(
struct se_cmd *cmd,
struct se_device *dev,
int complete,
int sc)
{
int ret = 0;
pr_debug("-----[ Storage Engine Exception for cmd: %p ITT: 0x%08x"
" CDB: 0x%02x\n", cmd, cmd->se_tfo->get_task_tag(cmd),
cmd->t_task_cdb[0]);
pr_debug("-----[ i_state: %d t_state/def_t_state:"
" %d/%d transport_error_status: %d\n",
cmd->se_tfo->get_cmd_state(cmd),
cmd->t_state, cmd->deferred_t_state,
cmd->transport_error_status);
pr_debug("-----[ t_tasks: %d t_task_cdbs_left: %d"
" t_task_cdbs_sent: %d t_task_cdbs_ex_left: %d --"
" t_transport_active: %d t_transport_stop: %d"
" t_transport_sent: %d\n", cmd->t_task_list_num,
atomic_read(&cmd->t_task_cdbs_left),
atomic_read(&cmd->t_task_cdbs_sent),
atomic_read(&cmd->t_task_cdbs_ex_left),
atomic_read(&cmd->t_transport_active),
atomic_read(&cmd->t_transport_stop),
atomic_read(&cmd->t_transport_sent));
transport_stop_all_task_timers(cmd);
if (dev)
atomic_inc(&dev->depth_left);
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
cmd->se_tfo->fall_back_to_erl0(cmd->se_sess);
cmd->se_tfo->stop_session(cmd->se_sess, 0, 0);
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
if (cmd->se_sess &&
cmd->se_dev->se_sub_dev->se_dev_attrib.emulate_ua_intlck_ctrl == 2)
core_scsi3_ua_allocate(cmd->se_sess->se_node_acl,
cmd->orig_fe_lun, 0x2C,
ASCQ_2CH_PREVIOUS_RESERVATION_CONFLICT_STATUS);
ret = cmd->se_tfo->queue_status(cmd);
if (ret == -EAGAIN)
goto queue_full;
goto check_stop;
case PYX_TRANSPORT_USE_SENSE_REASON:
break;
default:
pr_err("Unknown transport error for CDB 0x%02x: %d\n",
cmd->t_task_cdb[0],
cmd->transport_error_status);
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
break;
}
if (!sc && !cmd->se_tfo->new_cmd_map)
transport_new_cmd_failure(cmd);
else {
ret = transport_send_check_condition_and_sense(cmd,
cmd->scsi_sense_reason, 0);
if (ret == -EAGAIN)
goto queue_full;
}
check_stop:
transport_lun_remove_cmd(cmd);
if (!transport_cmd_check_stop_to_fabric(cmd))
;
return;
queue_full:
cmd->t_state = TRANSPORT_COMPLETE_OK;
transport_handle_queue_full(cmd, cmd->se_dev, transport_complete_qf);
}
static void transport_direct_request_timeout(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (!atomic_read(&cmd->t_transport_timeout)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return;
}
if (atomic_read(&cmd->t_task_cdbs_timeout_left)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return;
}
atomic_sub(atomic_read(&cmd->t_transport_timeout),
&cmd->t_se_count);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
}
static void transport_generic_request_timeout(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (atomic_read(&cmd->t_transport_timeout) > 1) {
int tmp = (atomic_read(&cmd->t_transport_timeout) - 1);
atomic_sub(tmp, &cmd->t_se_count);
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_generic_remove(cmd, 0);
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
spin_lock_irqsave(&se_cmd->t_state_lock, flags);
se_cmd->se_cmd_flags |= SCF_SUPPORTED_SAM_OPCODE;
spin_unlock_irqrestore(&se_cmd->t_state_lock, flags);
}
static void transport_task_timeout_handler(unsigned long data)
{
struct se_task *task = (struct se_task *)data;
struct se_cmd *cmd = task->task_se_cmd;
unsigned long flags;
pr_debug("transport task timeout fired! task: %p cmd: %p\n", task, cmd);
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (task->task_flags & TF_STOP) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return;
}
task->task_flags &= ~TF_RUNNING;
if (!atomic_read(&task->task_active)) {
pr_debug("transport task: %p cmd: %p timeout task_active"
" == 0\n", task, cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return;
}
atomic_inc(&cmd->t_se_count);
atomic_inc(&cmd->t_transport_timeout);
cmd->t_tasks_failed = 1;
atomic_set(&task->task_timeout, 1);
task->task_error_status = PYX_TRANSPORT_TASK_TIMEOUT;
task->task_scsi_status = 1;
if (atomic_read(&task->task_stop)) {
pr_debug("transport task: %p cmd: %p timeout task_stop"
" == 1\n", task, cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&task->task_stop_comp);
return;
}
if (!atomic_dec_and_test(&cmd->t_task_cdbs_left)) {
pr_debug("transport task: %p cmd: %p timeout non zero"
" t_task_cdbs_left\n", task, cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return;
}
pr_debug("transport task: %p cmd: %p timeout ZERO t_task_cdbs_left\n",
task, cmd);
cmd->t_state = TRANSPORT_COMPLETE_FAILURE;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_add_cmd_to_queue(cmd, TRANSPORT_COMPLETE_FAILURE);
}
static void transport_start_task_timer(struct se_task *task)
{
struct se_device *dev = task->se_dev;
int timeout;
if (task->task_flags & TF_RUNNING)
return;
timeout = dev->se_sub_dev->se_dev_attrib.task_timeout;
if (!timeout)
return;
init_timer(&task->task_timer);
task->task_timer.expires = (get_jiffies_64() + timeout * HZ);
task->task_timer.data = (unsigned long) task;
task->task_timer.function = transport_task_timeout_handler;
task->task_flags |= TF_RUNNING;
add_timer(&task->task_timer);
#if 0
pr_debug("Starting task timer for cmd: %p task: %p seconds:"
" %d\n", task->task_se_cmd, task, timeout);
#endif
}
void __transport_stop_task_timer(struct se_task *task, unsigned long *flags)
{
struct se_cmd *cmd = task->task_se_cmd;
if (!task->task_flags & TF_RUNNING)
return;
task->task_flags |= TF_STOP;
spin_unlock_irqrestore(&cmd->t_state_lock, *flags);
del_timer_sync(&task->task_timer);
spin_lock_irqsave(&cmd->t_state_lock, *flags);
task->task_flags &= ~TF_RUNNING;
task->task_flags &= ~TF_STOP;
}
static void transport_stop_all_task_timers(struct se_cmd *cmd)
{
struct se_task *task = NULL, *task_tmp;
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
list_for_each_entry_safe(task, task_tmp,
&cmd->t_task_list, t_list)
__transport_stop_task_timer(task, &flags);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
}
static inline int transport_tcq_window_closed(struct se_device *dev)
{
if (dev->dev_tcq_window_closed++ <
PYX_TRANSPORT_WINDOW_CLOSED_THRESHOLD) {
msleep(PYX_TRANSPORT_WINDOW_CLOSED_WAIT_SHORT);
} else
msleep(PYX_TRANSPORT_WINDOW_CLOSED_WAIT_LONG);
wake_up_interruptible(&dev->dev_queue_obj.thread_wq);
return 0;
}
static inline int transport_execute_task_attr(struct se_cmd *cmd)
{
if (cmd->se_dev->dev_task_attr_type != SAM_TASK_ATTR_EMULATED)
return 1;
if (cmd->sam_task_attr == MSG_HEAD_TAG) {
atomic_inc(&cmd->se_dev->dev_hoq_count);
smp_mb__after_atomic_inc();
pr_debug("Added HEAD_OF_QUEUE for CDB:"
" 0x%02x, se_ordered_id: %u\n",
cmd->t_task_cdb[0],
cmd->se_ordered_id);
return 1;
} else if (cmd->sam_task_attr == MSG_ORDERED_TAG) {
spin_lock(&cmd->se_dev->ordered_cmd_lock);
list_add_tail(&cmd->se_ordered_node,
&cmd->se_dev->ordered_cmd_list);
spin_unlock(&cmd->se_dev->ordered_cmd_lock);
atomic_inc(&cmd->se_dev->dev_ordered_sync);
smp_mb__after_atomic_inc();
pr_debug("Added ORDERED for CDB: 0x%02x to ordered"
" list, se_ordered_id: %u\n",
cmd->t_task_cdb[0],
cmd->se_ordered_id);
if (!atomic_read(&cmd->se_dev->simple_cmds))
return 1;
} else {
atomic_inc(&cmd->se_dev->simple_cmds);
smp_mb__after_atomic_inc();
}
if (atomic_read(&cmd->se_dev->dev_ordered_sync) != 0) {
spin_lock(&cmd->se_dev->delayed_cmd_lock);
cmd->se_cmd_flags |= SCF_DELAYED_CMD_FROM_SAM_ATTR;
list_add_tail(&cmd->se_delayed_node,
&cmd->se_dev->delayed_cmd_list);
spin_unlock(&cmd->se_dev->delayed_cmd_lock);
pr_debug("Added CDB: 0x%02x Task Attr: 0x%02x to"
" delayed CMD list, se_ordered_id: %u\n",
cmd->t_task_cdb[0], cmd->sam_task_attr,
cmd->se_ordered_id);
return 0;
}
return 1;
}
static int transport_execute_tasks(struct se_cmd *cmd)
{
int add_tasks;
if (se_dev_check_online(cmd->se_orig_obj_ptr) != 0) {
cmd->transport_error_status = PYX_TRANSPORT_LU_COMM_FAILURE;
transport_generic_request_failure(cmd, NULL, 0, 1);
return 0;
}
if (!transport_cmd_check_stop(cmd, 0, TRANSPORT_PROCESSING)) {
add_tasks = transport_execute_task_attr(cmd);
if (!add_tasks)
goto execute_tasks;
transport_add_tasks_from_cmd(cmd);
}
execute_tasks:
__transport_execute_tasks(cmd->se_dev);
return 0;
}
static int __transport_execute_tasks(struct se_device *dev)
{
int error;
struct se_cmd *cmd = NULL;
struct se_task *task = NULL;
unsigned long flags;
check_depth:
if (!atomic_read(&dev->depth_left))
return transport_tcq_window_closed(dev);
dev->dev_tcq_window_closed = 0;
spin_lock_irq(&dev->execute_task_lock);
if (list_empty(&dev->execute_task_list)) {
spin_unlock_irq(&dev->execute_task_lock);
return 0;
}
task = list_first_entry(&dev->execute_task_list,
struct se_task, t_execute_list);
list_del(&task->t_execute_list);
atomic_set(&task->task_execute_queue, 0);
atomic_dec(&dev->execute_tasks);
spin_unlock_irq(&dev->execute_task_lock);
atomic_dec(&dev->depth_left);
cmd = task->task_se_cmd;
spin_lock_irqsave(&cmd->t_state_lock, flags);
atomic_set(&task->task_active, 1);
atomic_set(&task->task_sent, 1);
atomic_inc(&cmd->t_task_cdbs_sent);
if (atomic_read(&cmd->t_task_cdbs_sent) ==
cmd->t_task_list_num)
atomic_set(&cmd->transport_sent, 1);
transport_start_task_timer(task);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
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
if ((dev->transport->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV) &&
(!(task->task_se_cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB)))
error = transport_emulate_control_cdb(task);
else
error = dev->transport->do_task(task);
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
spin_lock_irqsave(&se_cmd->t_state_lock, flags);
se_cmd->se_cmd_flags |= SCF_SE_CMD_FAILED;
se_cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
spin_unlock_irqrestore(&se_cmd->t_state_lock, flags);
}
static inline u32 transport_get_sectors_6(
unsigned char *cdb,
struct se_cmd *cmd,
int *ret)
{
struct se_device *dev = cmd->se_dev;
if (!dev)
goto type_disk;
if (dev->transport->get_device_type(dev) == TYPE_TAPE)
return (u32)(cdb[2] << 16) + (cdb[3] << 8) + cdb[4];
type_disk:
return (u32)cdb[4];
}
static inline u32 transport_get_sectors_10(
unsigned char *cdb,
struct se_cmd *cmd,
int *ret)
{
struct se_device *dev = cmd->se_dev;
if (!dev)
goto type_disk;
if (dev->transport->get_device_type(dev) == TYPE_TAPE) {
*ret = -EINVAL;
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
struct se_device *dev = cmd->se_dev;
if (!dev)
goto type_disk;
if (dev->transport->get_device_type(dev) == TYPE_TAPE) {
*ret = -EINVAL;
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
struct se_device *dev = cmd->se_dev;
if (!dev)
goto type_disk;
if (dev->transport->get_device_type(dev) == TYPE_TAPE)
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
struct se_device *dev = cmd->se_dev;
if (dev->transport->get_device_type(dev) == TYPE_TAPE) {
if (cdb[1] & 1) {
return dev->se_sub_dev->se_dev_attrib.block_size * sectors;
} else
return sectors;
}
#if 0
pr_debug("Returning block_size: %u, sectors: %u == %u for"
" %s object\n", dev->se_sub_dev->se_dev_attrib.block_size, sectors,
dev->se_sub_dev->se_dev_attrib.block_size * sectors,
dev->transport->name);
#endif
return dev->se_sub_dev->se_dev_attrib.block_size * sectors;
}
static void transport_xor_callback(struct se_cmd *cmd)
{
unsigned char *buf, *addr;
struct scatterlist *sg;
unsigned int offset;
int i;
int count;
buf = kmalloc(cmd->data_length, GFP_KERNEL);
if (!buf) {
pr_err("Unable to allocate xor_callback buf\n");
return;
}
sg_copy_to_buffer(cmd->t_data_sg,
cmd->t_data_nents,
buf,
cmd->data_length);
offset = 0;
for_each_sg(cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
addr = kmap_atomic(sg_page(sg), KM_USER0);
if (!addr)
goto out;
for (i = 0; i < sg->length; i++)
*(addr + sg->offset + i) ^= *(buf + offset + i);
offset += sg->length;
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
WARN_ON(!cmd->se_lun);
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (cmd->se_cmd_flags & SCF_SENT_CHECK_CONDITION) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return 0;
}
list_for_each_entry_safe(task, task_tmp,
&cmd->t_task_list, t_list) {
if (!task->task_sense)
continue;
dev = task->se_dev;
if (!dev)
continue;
if (!dev->transport->get_sense_buffer) {
pr_err("dev->transport->get_sense_buffer"
" is NULL\n");
continue;
}
sense_buffer = dev->transport->get_sense_buffer(task);
if (!sense_buffer) {
pr_err("ITT[0x%08x]_TASK[%d]: Unable to locate"
" sense buffer for task with sense\n",
cmd->se_tfo->get_task_tag(cmd), task->task_no);
continue;
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
offset = cmd->se_tfo->set_fabric_sense_len(cmd,
TRANSPORT_SENSE_BUFFER);
memcpy(&buffer[offset], sense_buffer,
TRANSPORT_SENSE_BUFFER);
cmd->scsi_status = task->task_scsi_status;
cmd->scsi_sense_length =
(TRANSPORT_SENSE_BUFFER + offset);
pr_debug("HBA_[%u]_PLUG[%s]: Set SAM STATUS: 0x%02x"
" and sense\n",
dev->se_hba->hba_id, dev->transport->name,
cmd->scsi_status);
return 0;
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return -1;
}
static int
transport_handle_reservation_conflict(struct se_cmd *cmd)
{
cmd->transport_wait_for_tasks = &transport_nop_wait_for_tasks;
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->se_cmd_flags |= SCF_SCSI_RESERVATION_CONFLICT;
cmd->scsi_status = SAM_STAT_RESERVATION_CONFLICT;
if (cmd->se_sess &&
cmd->se_dev->se_sub_dev->se_dev_attrib.emulate_ua_intlck_ctrl == 2)
core_scsi3_ua_allocate(cmd->se_sess->se_node_acl,
cmd->orig_fe_lun, 0x2C,
ASCQ_2CH_PREVIOUS_RESERVATION_CONFLICT_STATUS);
return -EINVAL;
}
static inline long long transport_dev_end_lba(struct se_device *dev)
{
return dev->transport->get_blocks(dev) + 1;
}
static int transport_cmd_get_valid_sectors(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
u32 sectors;
if (dev->transport->get_device_type(dev) != TYPE_DISK)
return 0;
sectors = (cmd->data_length / dev->se_sub_dev->se_dev_attrib.block_size);
if ((cmd->t_task_lba + sectors) > transport_dev_end_lba(dev)) {
pr_err("LBA: %llu Sectors: %u exceeds"
" transport_dev_end_lba(): %llu\n",
cmd->t_task_lba, sectors,
transport_dev_end_lba(dev));
return -EINVAL;
}
return 0;
}
static int target_check_write_same_discard(unsigned char *flags, struct se_device *dev)
{
int passthrough = (dev->transport->transport_type ==
TRANSPORT_PLUGIN_PHBA_PDEV);
if (!passthrough) {
if ((flags[0] & 0x04) || (flags[0] & 0x02)) {
pr_err("WRITE_SAME PBDATA and LBDATA"
" bits not supported for Block Discard"
" Emulation\n");
return -ENOSYS;
}
if (!(flags[0] & 0x08)) {
pr_err("WRITE_SAME w/o UNMAP bit not"
" supported for Block Discard Emulation\n");
return -ENOSYS;
}
}
return 0;
}
static int transport_generic_cmd_sequencer(
struct se_cmd *cmd,
unsigned char *cdb)
{
struct se_device *dev = cmd->se_dev;
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
return -EINVAL;
}
ret = su_dev->t10_alua.alua_state_check(cmd, cdb, &alua_ascq);
if (ret != 0) {
cmd->transport_wait_for_tasks = &transport_nop_wait_for_tasks;
if (ret > 0) {
#if 0
pr_debug("[%s]: ALUA TG Port not available,"
" SenseKey: NOT_READY, ASC/ASCQ: 0x04/0x%02x\n",
cmd->se_tfo->get_fabric_name(), alua_ascq);
#endif
transport_set_sense_codes(cmd, 0x04, alua_ascq);
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_CHECK_CONDITION_NOT_READY;
return -EINVAL;
}
goto out_invalid_cdb_field;
}
if (su_dev->t10_pr.pr_ops.t10_reservation_check(cmd, &pr_reg_type) != 0) {
if (su_dev->t10_pr.pr_ops.t10_seq_non_holder(
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
cmd->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case READ_10:
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_10;
cmd->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case READ_12:
sectors = transport_get_sectors_12(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_12;
cmd->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case READ_16:
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_16;
cmd->t_task_lba = transport_lba_64(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_6:
sectors = transport_get_sectors_6(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_6;
cmd->t_task_lba = transport_lba_21(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_10:
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_10;
cmd->t_task_lba = transport_lba_32(cdb);
cmd->t_tasks_fua = (cdb[1] & 0x8);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_12:
sectors = transport_get_sectors_12(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_12;
cmd->t_task_lba = transport_lba_32(cdb);
cmd->t_tasks_fua = (cdb[1] & 0x8);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case WRITE_16:
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_16;
cmd->t_task_lba = transport_lba_64(cdb);
cmd->t_tasks_fua = (cdb[1] & 0x8);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
break;
case XDWRITEREAD_10:
if ((cmd->data_direction != DMA_TO_DEVICE) ||
!(cmd->t_tasks_bidi))
goto out_invalid_cdb_field;
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_10;
cmd->t_task_lba = transport_lba_32(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
passthrough = (dev->transport->transport_type ==
TRANSPORT_PLUGIN_PHBA_PDEV);
if (passthrough)
break;
cmd->transport_complete_callback = &transport_xor_callback;
cmd->t_tasks_fua = (cdb[1] & 0x8);
break;
case VARIABLE_LENGTH_CMD:
service_action = get_unaligned_be16(&cdb[8]);
passthrough = (dev->transport->transport_type ==
TRANSPORT_PLUGIN_PHBA_PDEV);
switch (service_action) {
case XDWRITEREAD_32:
sectors = transport_get_sectors_32(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->transport_split_cdb = &split_cdb_XX_32;
cmd->t_task_lba = transport_lba_64_ext(cdb);
cmd->se_cmd_flags |= SCF_SCSI_DATA_SG_IO_CDB;
if (passthrough)
break;
cmd->transport_complete_callback = &transport_xor_callback;
cmd->t_tasks_fua = (cdb[10] & 0x8);
break;
case WRITE_SAME_32:
sectors = transport_get_sectors_32(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
if (sectors)
size = transport_get_size(1, cdb, cmd);
else {
pr_err("WSNZ=1, WRITE_SAME w/sectors=0 not"
" supported\n");
goto out_invalid_cdb_field;
}
cmd->t_task_lba = get_unaligned_be64(&cdb[12]);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
if (target_check_write_same_discard(&cdb[10], dev) < 0)
goto out_invalid_cdb_field;
break;
default:
pr_err("VARIABLE_LENGTH_CMD service action"
" 0x%04x not supported\n", service_action);
goto out_unsupported_cdb;
}
break;
case MAINTENANCE_IN:
if (dev->transport->get_device_type(dev) != TYPE_ROM) {
if (cdb[1] == MI_REPORT_TARGET_PGS) {
cmd->transport_emulate_cdb =
(su_dev->t10_alua.alua_type ==
SPC3_ALUA_EMULATED) ?
core_emulate_report_target_port_groups :
NULL;
}
size = (cdb[6] << 24) | (cdb[7] << 16) |
(cdb[8] << 8) | cdb[9];
} else {
size = (cdb[8] << 8) + cdb[9];
}
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
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
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case MODE_SENSE_10:
case GPCMD_READ_BUFFER_CAPACITY:
case GPCMD_SEND_OPC:
case LOG_SELECT:
case LOG_SENSE:
size = (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case READ_BLOCK_LIMITS:
size = READ_BLOCK_LEN;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
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
(su_dev->t10_pr.res_type ==
SPC3_PERSISTENT_RESERVATIONS) ?
core_scsi3_emulate_pr : NULL;
size = (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case GPCMD_MECHANISM_STATUS:
case GPCMD_READ_DVD_STRUCTURE:
size = (cdb[8] << 8) + cdb[9];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case READ_POSITION:
size = READ_POSITION_LEN;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case MAINTENANCE_OUT:
if (dev->transport->get_device_type(dev) != TYPE_ROM) {
if (cdb[1] == MO_SET_TARGET_PGS) {
cmd->transport_emulate_cdb =
(su_dev->t10_alua.alua_type ==
SPC3_ALUA_EMULATED) ?
core_emulate_set_target_port_groups :
NULL;
}
size = (cdb[6] << 24) | (cdb[7] << 16) |
(cdb[8] << 8) | cdb[9];
} else {
size = (cdb[8] << 8) + cdb[9];
}
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case INQUIRY:
size = (cdb[3] << 8) + cdb[4];
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
cmd->sam_task_attr = MSG_HEAD_TAG;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case READ_BUFFER:
size = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case READ_CAPACITY:
size = READ_CAP_LEN;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case READ_MEDIA_SERIAL_NUMBER:
case SECURITY_PROTOCOL_IN:
case SECURITY_PROTOCOL_OUT:
size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
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
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case RECEIVE_DIAGNOSTIC:
case SEND_DIAGNOSTIC:
size = (cdb[3] << 8) | cdb[4];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
#if 0
case GPCMD_READ_CD:
sectors = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
size = (2336 * sectors);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
#endif
case READ_TOC:
size = cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case REQUEST_SENSE:
size = cdb[4];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case READ_ELEMENT_STATUS:
size = 65536 * cdb[7] + 256 * cdb[8] + cdb[9];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case WRITE_BUFFER:
size = (cdb[6] << 16) + (cdb[7] << 8) + cdb[8];
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case RESERVE:
case RESERVE_10:
if (cdb[0] == RESERVE_10)
size = (cdb[7] << 8) | cdb[8];
else
size = cmd->data_length;
cmd->transport_emulate_cdb =
(su_dev->t10_pr.res_type !=
SPC_PASSTHROUGH) ?
core_scsi2_emulate_crh : NULL;
cmd->se_cmd_flags |= SCF_SCSI_NON_DATA_CDB;
break;
case RELEASE:
case RELEASE_10:
if (cdb[0] == RELEASE_10)
size = (cdb[7] << 8) | cdb[8];
else
size = cmd->data_length;
cmd->transport_emulate_cdb =
(su_dev->t10_pr.res_type !=
SPC_PASSTHROUGH) ?
core_scsi2_emulate_crh : NULL;
cmd->se_cmd_flags |= SCF_SCSI_NON_DATA_CDB;
break;
case SYNCHRONIZE_CACHE:
case 0x91:
if (cdb[0] == SYNCHRONIZE_CACHE) {
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
cmd->t_task_lba = transport_lba_32(cdb);
} else {
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
cmd->t_task_lba = transport_lba_64(cdb);
}
if (sector_ret)
goto out_unsupported_cdb;
size = transport_get_size(sectors, cdb, cmd);
cmd->se_cmd_flags |= SCF_SCSI_NON_DATA_CDB;
if (dev->transport->transport_type == TRANSPORT_PLUGIN_PHBA_PDEV)
break;
cmd->se_cmd_flags |= SCF_EMULATE_CDB_ASYNC;
if ((cmd->t_task_lba != 0) || (sectors != 0)) {
if (transport_cmd_get_valid_sectors(cmd) < 0)
goto out_invalid_cdb_field;
}
break;
case UNMAP:
size = get_unaligned_be16(&cdb[7]);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
case WRITE_SAME_16:
sectors = transport_get_sectors_16(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
if (sectors)
size = transport_get_size(1, cdb, cmd);
else {
pr_err("WSNZ=1, WRITE_SAME w/sectors=0 not supported\n");
goto out_invalid_cdb_field;
}
cmd->t_task_lba = get_unaligned_be64(&cdb[2]);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
if (target_check_write_same_discard(&cdb[1], dev) < 0)
goto out_invalid_cdb_field;
break;
case WRITE_SAME:
sectors = transport_get_sectors_10(cdb, cmd, &sector_ret);
if (sector_ret)
goto out_unsupported_cdb;
if (sectors)
size = transport_get_size(1, cdb, cmd);
else {
pr_err("WSNZ=1, WRITE_SAME w/sectors=0 not supported\n");
goto out_invalid_cdb_field;
}
cmd->t_task_lba = get_unaligned_be32(&cdb[2]);
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
if (target_check_write_same_discard(&cdb[1], dev) < 0)
goto out_invalid_cdb_field;
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
transport_core_report_lun_response;
size = (cdb[6] << 24) | (cdb[7] << 16) | (cdb[8] << 8) | cdb[9];
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
cmd->sam_task_attr = MSG_HEAD_TAG;
cmd->se_cmd_flags |= SCF_SCSI_CONTROL_SG_IO_CDB;
break;
default:
pr_warn("TARGET_CORE[%s]: Unsupported SCSI Opcode"
" 0x%02x, sending CHECK_CONDITION.\n",
cmd->se_tfo->get_fabric_name(), cdb[0]);
cmd->transport_wait_for_tasks = &transport_nop_wait_for_tasks;
goto out_unsupported_cdb;
}
if (size != cmd->data_length) {
pr_warn("TARGET_CORE[%s]: Expected Transfer Length:"
" %u does not match SCSI CDB Length: %u for SAM Opcode:"
" 0x%02x\n", cmd->se_tfo->get_fabric_name(),
cmd->data_length, size, cdb[0]);
cmd->cmd_spdtl = size;
if (cmd->data_direction == DMA_TO_DEVICE) {
pr_err("Rejecting underflow/overflow"
" WRITE data\n");
goto out_invalid_cdb_field;
}
if (!ret && (dev->se_sub_dev->se_dev_attrib.block_size != 512)) {
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
}
cmd->data_length = size;
}
if ((cmd->se_cmd_flags & SCF_SCSI_CONTROL_SG_IO_CDB) &&
size > PAGE_SIZE)
goto out_invalid_cdb_field;
transport_set_supported_SAM_opcode(cmd);
return ret;
out_unsupported_cdb:
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_UNSUPPORTED_SCSI_OPCODE;
return -EINVAL;
out_invalid_cdb_field:
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason = TCM_INVALID_CDB_FIELD;
return -EINVAL;
}
static void transport_complete_task_attr(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_cmd *cmd_p, *cmd_tmp;
int new_active_tasks = 0;
if (cmd->sam_task_attr == MSG_SIMPLE_TAG) {
atomic_dec(&dev->simple_cmds);
smp_mb__after_atomic_dec();
dev->dev_cur_ordered_id++;
pr_debug("Incremented dev->dev_cur_ordered_id: %u for"
" SIMPLE: %u\n", dev->dev_cur_ordered_id,
cmd->se_ordered_id);
} else if (cmd->sam_task_attr == MSG_HEAD_TAG) {
atomic_dec(&dev->dev_hoq_count);
smp_mb__after_atomic_dec();
dev->dev_cur_ordered_id++;
pr_debug("Incremented dev_cur_ordered_id: %u for"
" HEAD_OF_QUEUE: %u\n", dev->dev_cur_ordered_id,
cmd->se_ordered_id);
} else if (cmd->sam_task_attr == MSG_ORDERED_TAG) {
spin_lock(&dev->ordered_cmd_lock);
list_del(&cmd->se_ordered_node);
atomic_dec(&dev->dev_ordered_sync);
smp_mb__after_atomic_dec();
spin_unlock(&dev->ordered_cmd_lock);
dev->dev_cur_ordered_id++;
pr_debug("Incremented dev_cur_ordered_id: %u for ORDERED:"
" %u\n", dev->dev_cur_ordered_id, cmd->se_ordered_id);
}
spin_lock(&dev->delayed_cmd_lock);
list_for_each_entry_safe(cmd_p, cmd_tmp,
&dev->delayed_cmd_list, se_delayed_node) {
list_del(&cmd_p->se_delayed_node);
spin_unlock(&dev->delayed_cmd_lock);
pr_debug("Calling add_tasks() for"
" cmd_p: 0x%02x Task Attr: 0x%02x"
" Dormant -> Active, se_ordered_id: %u\n",
cmd_p->t_task_cdb[0],
cmd_p->sam_task_attr, cmd_p->se_ordered_id);
transport_add_tasks_from_cmd(cmd_p);
new_active_tasks++;
spin_lock(&dev->delayed_cmd_lock);
if (cmd_p->sam_task_attr == MSG_ORDERED_TAG)
break;
}
spin_unlock(&dev->delayed_cmd_lock);
if (new_active_tasks != 0)
wake_up_interruptible(&dev->dev_queue_obj.thread_wq);
}
static int transport_complete_qf(struct se_cmd *cmd)
{
int ret = 0;
if (cmd->se_cmd_flags & SCF_TRANSPORT_TASK_SENSE)
return cmd->se_tfo->queue_status(cmd);
switch (cmd->data_direction) {
case DMA_FROM_DEVICE:
ret = cmd->se_tfo->queue_data_in(cmd);
break;
case DMA_TO_DEVICE:
if (cmd->t_bidi_data_sg) {
ret = cmd->se_tfo->queue_data_in(cmd);
if (ret < 0)
return ret;
}
case DMA_NONE:
ret = cmd->se_tfo->queue_status(cmd);
break;
default:
break;
}
return ret;
}
static void transport_handle_queue_full(
struct se_cmd *cmd,
struct se_device *dev,
int (*qf_callback)(struct se_cmd *))
{
spin_lock_irq(&dev->qf_cmd_lock);
cmd->se_cmd_flags |= SCF_EMULATE_QUEUE_FULL;
cmd->transport_qf_callback = qf_callback;
list_add_tail(&cmd->se_qf_node, &cmd->se_dev->qf_cmd_list);
atomic_inc(&dev->dev_qf_count);
smp_mb__after_atomic_inc();
spin_unlock_irq(&cmd->se_dev->qf_cmd_lock);
schedule_work(&cmd->se_dev->qf_work_queue);
}
static void transport_generic_complete_ok(struct se_cmd *cmd)
{
int reason = 0, ret;
if (cmd->se_dev->dev_task_attr_type == SAM_TASK_ATTR_EMULATED)
transport_complete_task_attr(cmd);
if (atomic_read(&cmd->se_dev->dev_qf_count) != 0)
schedule_work(&cmd->se_dev->qf_work_queue);
if (cmd->transport_qf_callback) {
ret = cmd->transport_qf_callback(cmd);
if (ret < 0)
goto queue_full;
cmd->transport_qf_callback = NULL;
goto done;
}
if (cmd->se_cmd_flags & SCF_TRANSPORT_TASK_SENSE) {
if (transport_get_sense_data(cmd) < 0)
reason = TCM_NON_EXISTENT_LUN;
if (cmd->scsi_status) {
ret = transport_send_check_condition_and_sense(
cmd, reason, 1);
if (ret == -EAGAIN)
goto queue_full;
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
if (cmd->se_lun->lun_sep) {
cmd->se_lun->lun_sep->sep_stats.tx_data_octets +=
cmd->data_length;
}
spin_unlock(&cmd->se_lun->lun_sep_lock);
ret = cmd->se_tfo->queue_data_in(cmd);
if (ret == -EAGAIN)
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
if (ret == -EAGAIN)
goto queue_full;
break;
}
case DMA_NONE:
ret = cmd->se_tfo->queue_status(cmd);
if (ret == -EAGAIN)
goto queue_full;
break;
default:
break;
}
done:
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop_to_fabric(cmd);
return;
queue_full:
pr_debug("Handling complete_ok QUEUE_FULL: se_cmd: %p,"
" data_direction: %d\n", cmd, cmd->data_direction);
transport_handle_queue_full(cmd, cmd->se_dev, transport_complete_qf);
}
static void transport_free_dev_tasks(struct se_cmd *cmd)
{
struct se_task *task, *task_tmp;
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
list_for_each_entry_safe(task, task_tmp,
&cmd->t_task_list, t_list) {
if (atomic_read(&task->task_active))
continue;
kfree(task->task_sg_bidi);
kfree(task->task_sg);
list_del(&task->t_list);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
if (task->se_dev)
task->se_dev->transport->free_task(task);
else
pr_err("task[%u] - task->se_dev is NULL\n",
task->task_no);
spin_lock_irqsave(&cmd->t_state_lock, flags);
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
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
static inline void transport_release_tasks(struct se_cmd *cmd)
{
transport_free_dev_tasks(cmd);
}
static inline int transport_dec_and_check(struct se_cmd *cmd)
{
unsigned long flags;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (atomic_read(&cmd->t_fe_count)) {
if (!atomic_dec_and_test(&cmd->t_fe_count)) {
spin_unlock_irqrestore(&cmd->t_state_lock,
flags);
return 1;
}
}
if (atomic_read(&cmd->t_se_count)) {
if (!atomic_dec_and_test(&cmd->t_se_count)) {
spin_unlock_irqrestore(&cmd->t_state_lock,
flags);
return 1;
}
}
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
return 0;
}
static void transport_release_fe_cmd(struct se_cmd *cmd)
{
unsigned long flags;
if (transport_dec_and_check(cmd))
return;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (!atomic_read(&cmd->transport_dev_active)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
goto free_pages;
}
atomic_set(&cmd->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_release_tasks(cmd);
free_pages:
transport_free_pages(cmd);
transport_free_se_cmd(cmd);
cmd->se_tfo->release_cmd(cmd);
}
static int
transport_generic_remove(struct se_cmd *cmd, int session_reinstatement)
{
unsigned long flags;
if (transport_dec_and_check(cmd)) {
if (session_reinstatement) {
spin_lock_irqsave(&cmd->t_state_lock, flags);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock,
flags);
}
return 1;
}
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (!atomic_read(&cmd->transport_dev_active)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
goto free_pages;
}
atomic_set(&cmd->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_release_tasks(cmd);
free_pages:
transport_free_pages(cmd);
transport_release_cmd(cmd);
return 0;
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
if ((cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB) ||
(cmd->se_cmd_flags & SCF_SCSI_CONTROL_SG_IO_CDB)) {
cmd->t_data_sg = sgl;
cmd->t_data_nents = sgl_count;
if (sgl_bidi && sgl_bidi_count) {
cmd->t_bidi_data_sg = sgl_bidi;
cmd->t_bidi_data_nents = sgl_bidi_count;
}
cmd->se_cmd_flags |= SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC;
}
return 0;
}
static int transport_new_cmd_obj(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
int set_counts = 1, rc, task_cdbs;
if (cmd->t_bidi_data_sg &&
(dev->transport->transport_type != TRANSPORT_PLUGIN_PHBA_PDEV)) {
rc = transport_allocate_tasks(cmd,
cmd->t_task_lba,
DMA_FROM_DEVICE,
cmd->t_bidi_data_sg,
cmd->t_bidi_data_nents);
if (rc <= 0) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason =
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return -EINVAL;
}
atomic_inc(&cmd->t_fe_count);
atomic_inc(&cmd->t_se_count);
set_counts = 0;
}
task_cdbs = transport_allocate_tasks(cmd,
cmd->t_task_lba,
cmd->data_direction,
cmd->t_data_sg,
cmd->t_data_nents);
if (task_cdbs <= 0) {
cmd->se_cmd_flags |= SCF_SCSI_CDB_EXCEPTION;
cmd->scsi_sense_reason =
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE;
return -EINVAL;
}
if (set_counts) {
atomic_inc(&cmd->t_fe_count);
atomic_inc(&cmd->t_se_count);
}
cmd->t_task_list_num = task_cdbs;
atomic_set(&cmd->t_task_cdbs_left, task_cdbs);
atomic_set(&cmd->t_task_cdbs_ex_left, task_cdbs);
atomic_set(&cmd->t_task_cdbs_timeout_left, task_cdbs);
return 0;
}
void *transport_kmap_first_data_page(struct se_cmd *cmd)
{
struct scatterlist *sg = cmd->t_data_sg;
BUG_ON(!sg);
return kmap(sg_page(sg)) + sg->offset;
}
void transport_kunmap_first_data_page(struct se_cmd *cmd)
{
kunmap(sg_page(cmd->t_data_sg));
}
static int
transport_generic_get_mem(struct se_cmd *cmd)
{
u32 length = cmd->data_length;
unsigned int nents;
struct page *page;
int i = 0;
nents = DIV_ROUND_UP(length, PAGE_SIZE);
cmd->t_data_sg = kmalloc(sizeof(struct scatterlist) * nents, GFP_KERNEL);
if (!cmd->t_data_sg)
return -ENOMEM;
cmd->t_data_nents = nents;
sg_init_table(cmd->t_data_sg, nents);
while (length) {
u32 page_len = min_t(u32, length, PAGE_SIZE);
page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!page)
goto out;
sg_set_page(&cmd->t_data_sg[i], page, page_len, 0);
length -= page_len;
i++;
}
return 0;
out:
while (i >= 0) {
__free_page(sg_page(&cmd->t_data_sg[i]));
i--;
}
kfree(cmd->t_data_sg);
cmd->t_data_sg = NULL;
return -ENOMEM;
}
static inline sector_t transport_limit_task_sectors(
struct se_device *dev,
unsigned long long lba,
sector_t sectors)
{
sectors = min_t(sector_t, sectors, dev->se_sub_dev->se_dev_attrib.max_sectors);
if (dev->transport->get_device_type(dev) == TYPE_DISK)
if ((lba + sectors) > transport_dev_end_lba(dev))
sectors = ((transport_dev_end_lba(dev) - lba) + 1);
return sectors;
}
void transport_do_task_sg_chain(struct se_cmd *cmd)
{
struct scatterlist *sg_first = NULL;
struct scatterlist *sg_prev = NULL;
int sg_prev_nents = 0;
struct scatterlist *sg;
struct se_task *task;
u32 chained_nents = 0;
int i;
BUG_ON(!cmd->se_tfo->task_sg_chaining);
list_for_each_entry(task, &cmd->t_task_list, t_list) {
if (!task->task_sg)
continue;
if (!sg_first) {
sg_first = task->task_sg;
chained_nents = task->task_sg_nents;
} else {
sg_chain(sg_prev, sg_prev_nents, task->task_sg);
chained_nents += task->task_sg_nents;
}
if (task->task_padded_sg)
sg_prev_nents = (task->task_sg_nents + 1);
else
sg_prev_nents = task->task_sg_nents;
sg_prev = task->task_sg;
}
cmd->t_tasks_sg_chained = sg_first;
cmd->t_tasks_sg_chained_no = chained_nents;
pr_debug("Setup cmd: %p cmd->t_tasks_sg_chained: %p and"
" t_tasks_sg_chained_no: %u\n", cmd, cmd->t_tasks_sg_chained,
cmd->t_tasks_sg_chained_no);
for_each_sg(cmd->t_tasks_sg_chained, sg,
cmd->t_tasks_sg_chained_no, i) {
pr_debug("SG[%d]: %p page: %p length: %d offset: %d\n",
i, sg, sg_page(sg), sg->length, sg->offset);
if (sg_is_chain(sg))
pr_debug("SG: %p sg_is_chain=1\n", sg);
if (sg_is_last(sg))
pr_debug("SG: %p sg_is_last=1\n", sg);
}
}
static int transport_allocate_data_tasks(
struct se_cmd *cmd,
unsigned long long lba,
enum dma_data_direction data_direction,
struct scatterlist *sgl,
unsigned int sgl_nents)
{
unsigned char *cdb = NULL;
struct se_task *task;
struct se_device *dev = cmd->se_dev;
unsigned long flags;
int task_count, i, ret;
sector_t sectors, dev_max_sectors = dev->se_sub_dev->se_dev_attrib.max_sectors;
u32 sector_size = dev->se_sub_dev->se_dev_attrib.block_size;
struct scatterlist *sg;
struct scatterlist *cmd_sg;
WARN_ON(cmd->data_length % sector_size);
sectors = DIV_ROUND_UP(cmd->data_length, sector_size);
task_count = DIV_ROUND_UP_SECTOR_T(sectors, dev_max_sectors);
cmd_sg = sgl;
for (i = 0; i < task_count; i++) {
unsigned int task_size, task_sg_nents_padded;
int count;
task = transport_generic_get_task(cmd, data_direction);
if (!task)
return -ENOMEM;
task->task_lba = lba;
task->task_sectors = min(sectors, dev_max_sectors);
task->task_size = task->task_sectors * sector_size;
cdb = dev->transport->get_cdb(task);
BUG_ON(!cdb);
memcpy(cdb, cmd->t_task_cdb,
scsi_command_size(cmd->t_task_cdb));
cmd->transport_split_cdb(task->task_lba, task->task_sectors, cdb);
task->task_sg_nents = DIV_ROUND_UP(task->task_size, PAGE_SIZE);
if (cmd->se_tfo->task_sg_chaining && (i < (task_count - 1))) {
task_sg_nents_padded = (task->task_sg_nents + 1);
task->task_padded_sg = 1;
} else
task_sg_nents_padded = task->task_sg_nents;
task->task_sg = kmalloc(sizeof(struct scatterlist) *
task_sg_nents_padded, GFP_KERNEL);
if (!task->task_sg) {
cmd->se_dev->transport->free_task(task);
return -ENOMEM;
}
sg_init_table(task->task_sg, task_sg_nents_padded);
task_size = task->task_size;
for_each_sg(task->task_sg, sg, task->task_sg_nents, count) {
if (cmd_sg->length > task_size)
break;
*sg = *cmd_sg;
task_size -= cmd_sg->length;
cmd_sg = sg_next(cmd_sg);
}
lba += task->task_sectors;
sectors -= task->task_sectors;
spin_lock_irqsave(&cmd->t_state_lock, flags);
list_add_tail(&task->t_list, &cmd->t_task_list);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
}
list_for_each_entry(task, &cmd->t_task_list, t_list) {
if (atomic_read(&task->task_sent))
continue;
if (!dev->transport->map_data_SG)
continue;
ret = dev->transport->map_data_SG(task);
if (ret < 0)
return 0;
}
return task_count;
}
static int
transport_allocate_control_task(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
unsigned char *cdb;
struct se_task *task;
unsigned long flags;
int ret = 0;
task = transport_generic_get_task(cmd, cmd->data_direction);
if (!task)
return -ENOMEM;
cdb = dev->transport->get_cdb(task);
BUG_ON(!cdb);
memcpy(cdb, cmd->t_task_cdb,
scsi_command_size(cmd->t_task_cdb));
task->task_sg = kmalloc(sizeof(struct scatterlist) * cmd->t_data_nents,
GFP_KERNEL);
if (!task->task_sg) {
cmd->se_dev->transport->free_task(task);
return -ENOMEM;
}
memcpy(task->task_sg, cmd->t_data_sg,
sizeof(struct scatterlist) * cmd->t_data_nents);
task->task_size = cmd->data_length;
task->task_sg_nents = cmd->t_data_nents;
spin_lock_irqsave(&cmd->t_state_lock, flags);
list_add_tail(&task->t_list, &cmd->t_task_list);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
if (cmd->se_cmd_flags & SCF_SCSI_CONTROL_SG_IO_CDB) {
if (dev->transport->map_control_SG)
ret = dev->transport->map_control_SG(task);
} else if (cmd->se_cmd_flags & SCF_SCSI_NON_DATA_CDB) {
if (dev->transport->cdb_none)
ret = dev->transport->cdb_none(task);
} else {
pr_err("target: Unknown control cmd type!\n");
BUG();
}
if (ret == 0)
return 1;
return ret;
}
static u32 transport_allocate_tasks(
struct se_cmd *cmd,
unsigned long long lba,
enum dma_data_direction data_direction,
struct scatterlist *sgl,
unsigned int sgl_nents)
{
if (cmd->se_cmd_flags & SCF_SCSI_DATA_SG_IO_CDB) {
if (transport_cmd_get_valid_sectors(cmd) < 0)
return -EINVAL;
return transport_allocate_data_tasks(cmd, lba, data_direction,
sgl, sgl_nents);
} else
return transport_allocate_control_task(cmd);
}
int transport_generic_new_cmd(struct se_cmd *cmd)
{
int ret = 0;
if (!(cmd->se_cmd_flags & SCF_PASSTHROUGH_SG_TO_MEM_NOALLOC) &&
cmd->data_length) {
ret = transport_generic_get_mem(cmd);
if (ret < 0)
return ret;
}
ret = transport_new_cmd_obj(cmd);
if (ret < 0)
return ret;
if (cmd->data_direction == DMA_TO_DEVICE) {
transport_add_tasks_to_state_queue(cmd);
return transport_generic_write_pending(cmd);
}
transport_execute_tasks(cmd);
return 0;
}
void transport_generic_process_write(struct se_cmd *cmd)
{
transport_execute_tasks(cmd);
}
static int transport_write_pending_qf(struct se_cmd *cmd)
{
return cmd->se_tfo->write_pending(cmd);
}
static int transport_generic_write_pending(struct se_cmd *cmd)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&cmd->t_state_lock, flags);
cmd->t_state = TRANSPORT_WRITE_PENDING;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
if (cmd->transport_qf_callback) {
ret = cmd->transport_qf_callback(cmd);
if (ret == -EAGAIN)
goto queue_full;
else if (ret < 0)
return ret;
cmd->transport_qf_callback = NULL;
return 0;
}
transport_cmd_check_stop(cmd, 1, 0);
ret = cmd->se_tfo->write_pending(cmd);
if (ret == -EAGAIN)
goto queue_full;
else if (ret < 0)
return ret;
return PYX_TRANSPORT_WRITE_PENDING;
queue_full:
pr_debug("Handling write_pending QUEUE__FULL: se_cmd: %p\n", cmd);
cmd->t_state = TRANSPORT_COMPLETE_QF_WP;
transport_handle_queue_full(cmd, cmd->se_dev,
transport_write_pending_qf);
return ret;
}
void transport_release_cmd(struct se_cmd *cmd)
{
BUG_ON(!cmd->se_tfo);
transport_free_se_cmd(cmd);
cmd->se_tfo->release_cmd(cmd);
}
void transport_generic_free_cmd(
struct se_cmd *cmd,
int wait_for_tasks,
int session_reinstatement)
{
if (!(cmd->se_cmd_flags & SCF_SE_LUN_CMD))
transport_release_cmd(cmd);
else {
core_dec_lacl_count(cmd->se_sess->se_node_acl, cmd);
if (cmd->se_lun) {
#if 0
pr_debug("cmd: %p ITT: 0x%08x contains"
" cmd->se_lun\n", cmd,
cmd->se_tfo->get_task_tag(cmd));
#endif
transport_lun_remove_cmd(cmd);
}
if (wait_for_tasks && cmd->transport_wait_for_tasks)
cmd->transport_wait_for_tasks(cmd, 0, 0);
transport_free_dev_tasks(cmd);
transport_generic_remove(cmd, session_reinstatement);
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
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (atomic_read(&cmd->t_transport_stop)) {
atomic_set(&cmd->transport_lun_stop, 0);
pr_debug("ConfigFS ITT[0x%08x] - t_transport_stop =="
" TRUE, skipping\n", cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
transport_cmd_check_stop(cmd, 1, 0);
return -EPERM;
}
atomic_set(&cmd->transport_lun_fe_stop, 1);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
wake_up_interruptible(&cmd->se_dev->dev_queue_obj.thread_wq);
ret = transport_stop_tasks_for_cmd(cmd);
pr_debug("ConfigFS: cmd: %p t_tasks: %d stop tasks ret:"
" %d\n", cmd, cmd->t_task_list_num, ret);
if (!ret) {
pr_debug("ConfigFS: ITT[0x%08x] - stopping cmd....\n",
cmd->se_tfo->get_task_tag(cmd));
wait_for_completion(&cmd->transport_lun_stop_comp);
pr_debug("ConfigFS: ITT[0x%08x] - stopped cmd....\n",
cmd->se_tfo->get_task_tag(cmd));
}
transport_remove_cmd_from_queue(cmd, &cmd->se_dev->dev_queue_obj);
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
list_del(&cmd->se_lun_node);
atomic_set(&cmd->transport_lun_active, 0);
spin_lock(&cmd->t_state_lock);
pr_debug("SE_LUN[%d] - Setting cmd->transport"
"_lun_stop for ITT: 0x%08x\n",
cmd->se_lun->unpacked_lun,
cmd->se_tfo->get_task_tag(cmd));
atomic_set(&cmd->transport_lun_stop, 1);
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
if (!atomic_read(&cmd->transport_dev_active)) {
spin_unlock_irqrestore(&cmd->t_state_lock, cmd_flags);
goto check_cond;
}
atomic_set(&cmd->transport_dev_active, 0);
transport_all_task_dev_remove_state(cmd);
spin_unlock_irqrestore(&cmd->t_state_lock, cmd_flags);
transport_free_dev_tasks(cmd);
check_cond:
transport_send_check_condition_and_sense(cmd,
TCM_NON_EXISTENT_LUN, 0);
spin_lock_irqsave(&cmd->t_state_lock, cmd_flags);
if (atomic_read(&cmd->transport_lun_fe_stop)) {
pr_debug("SE_LUN[%d] - Detected FE stop for"
" struct se_cmd: %p ITT: 0x%08x\n",
lun->unpacked_lun,
cmd, cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock,
cmd_flags);
transport_cmd_check_stop(cmd, 1, 0);
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
struct se_lun *lun = (struct se_lun *)p;
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
static void transport_generic_wait_for_tasks(
struct se_cmd *cmd,
int remove_cmd,
int session_reinstatement)
{
unsigned long flags;
if (!(cmd->se_cmd_flags & SCF_SE_LUN_CMD) && !(cmd->se_tmr_req))
return;
spin_lock_irqsave(&cmd->t_state_lock, flags);
if (atomic_read(&cmd->transport_lun_stop)) {
pr_debug("wait_for_tasks: Stopping"
" wait_for_completion(&cmd->t_tasktransport_lun_fe"
"_stop_comp); for ITT: 0x%08x\n",
cmd->se_tfo->get_task_tag(cmd));
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
complete(&cmd->transport_lun_stop_comp);
wait_for_completion(&cmd->transport_lun_fe_stop_comp);
spin_lock_irqsave(&cmd->t_state_lock, flags);
transport_all_task_dev_remove_state(cmd);
pr_debug("wait_for_tasks: Stopped"
" wait_for_completion(&cmd->t_tasktransport_lun_fe_"
"stop_comp); for ITT: 0x%08x\n",
cmd->se_tfo->get_task_tag(cmd));
atomic_set(&cmd->transport_lun_stop, 0);
}
if (!atomic_read(&cmd->t_transport_active) ||
atomic_read(&cmd->t_transport_aborted))
goto remove;
atomic_set(&cmd->t_transport_stop, 1);
pr_debug("wait_for_tasks: Stopping %p ITT: 0x%08x"
" i_state: %d, t_state/def_t_state: %d/%d, t_transport_stop"
" = TRUE\n", cmd, cmd->se_tfo->get_task_tag(cmd),
cmd->se_tfo->get_cmd_state(cmd), cmd->t_state,
cmd->deferred_t_state);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
wake_up_interruptible(&cmd->se_dev->dev_queue_obj.thread_wq);
wait_for_completion(&cmd->t_transport_stop_comp);
spin_lock_irqsave(&cmd->t_state_lock, flags);
atomic_set(&cmd->t_transport_active, 0);
atomic_set(&cmd->t_transport_stop, 0);
pr_debug("wait_for_tasks: Stopped wait_for_compltion("
"&cmd->t_transport_stop_comp) for ITT: 0x%08x\n",
cmd->se_tfo->get_task_tag(cmd));
remove:
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
if (!remove_cmd)
return;
transport_generic_free_cmd(cmd, 0, session_reinstatement);
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
offset = cmd->se_tfo->set_fabric_sense_len(cmd,
TRANSPORT_SENSE_BUFFER);
switch (reason) {
case TCM_NON_EXISTENT_LUN:
buffer[offset] = 0x70;
buffer[offset+SPC_SENSE_KEY_OFFSET] = ILLEGAL_REQUEST;
buffer[offset+SPC_ASC_KEY_OFFSET] = 0x25;
break;
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
return cmd->se_tfo->queue_status(cmd);
}
int transport_check_aborted_status(struct se_cmd *cmd, int send_status)
{
int ret = 0;
if (atomic_read(&cmd->t_transport_aborted) != 0) {
if (!send_status ||
(cmd->se_cmd_flags & SCF_SENT_DELAYED_TAS))
return 1;
#if 0
pr_debug("Sending delayed SAM_STAT_TASK_ABORTED"
" status for CDB: 0x%02x ITT: 0x%08x\n",
cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
cmd->se_cmd_flags |= SCF_SENT_DELAYED_TAS;
cmd->se_tfo->queue_status(cmd);
ret = 1;
}
return ret;
}
void transport_send_task_abort(struct se_cmd *cmd)
{
if (cmd->data_direction == DMA_TO_DEVICE) {
if (cmd->se_tfo->write_pending_status(cmd) != 0) {
atomic_inc(&cmd->t_transport_aborted);
smp_mb__after_atomic_inc();
cmd->scsi_status = SAM_STAT_TASK_ABORTED;
transport_new_cmd_failure(cmd);
return;
}
}
cmd->scsi_status = SAM_STAT_TASK_ABORTED;
#if 0
pr_debug("Setting SAM_STAT_TASK_ABORTED status for CDB: 0x%02x,"
" ITT: 0x%08x\n", cmd->t_task_cdb[0],
cmd->se_tfo->get_task_tag(cmd));
#endif
cmd->se_tfo->queue_status(cmd);
}
int transport_generic_do_tmr(struct se_cmd *cmd)
{
struct se_device *dev = cmd->se_dev;
struct se_tmr_req *tmr = cmd->se_tmr_req;
int ret;
switch (tmr->function) {
case TMR_ABORT_TASK:
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
pr_err("Uknown TMR function: 0x%02x.\n",
tmr->function);
tmr->response = TMR_FUNCTION_REJECTED;
break;
}
cmd->t_state = TRANSPORT_ISTATE_PROCESSING;
cmd->se_tfo->queue_tm_rsp(cmd);
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
struct se_task *task;
unsigned long flags;
spin_lock_irqsave(&dev->execute_task_lock, flags);
while ((task = transport_get_task_from_state_list(dev))) {
if (!task->task_se_cmd) {
pr_err("task->task_se_cmd is NULL!\n");
continue;
}
cmd = task->task_se_cmd;
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
spin_lock_irqsave(&cmd->t_state_lock, flags);
pr_debug("PT: cmd: %p task: %p ITT: 0x%08x,"
" i_state: %d, t_state/def_t_state:"
" %d/%d cdb: 0x%02x\n", cmd, task,
cmd->se_tfo->get_task_tag(cmd),
cmd->se_tfo->get_cmd_state(cmd),
cmd->t_state, cmd->deferred_t_state,
cmd->t_task_cdb[0]);
pr_debug("PT: ITT[0x%08x] - t_tasks: %d t_task_cdbs_left:"
" %d t_task_cdbs_sent: %d -- t_transport_active: %d"
" t_transport_stop: %d t_transport_sent: %d\n",
cmd->se_tfo->get_task_tag(cmd),
cmd->t_task_list_num,
atomic_read(&cmd->t_task_cdbs_left),
atomic_read(&cmd->t_task_cdbs_sent),
atomic_read(&cmd->t_transport_active),
atomic_read(&cmd->t_transport_stop),
atomic_read(&cmd->t_transport_sent));
if (atomic_read(&task->task_active)) {
atomic_set(&task->task_stop, 1);
spin_unlock_irqrestore(
&cmd->t_state_lock, flags);
pr_debug("Waiting for task: %p to shutdown for dev:"
" %p\n", task, dev);
wait_for_completion(&task->task_stop_comp);
pr_debug("Completed task: %p shutdown for dev: %p\n",
task, dev);
spin_lock_irqsave(&cmd->t_state_lock, flags);
atomic_dec(&cmd->t_task_cdbs_left);
atomic_set(&task->task_active, 0);
atomic_set(&task->task_stop, 0);
} else {
if (atomic_read(&task->task_execute_queue) != 0)
transport_remove_task_from_execute_queue(task, dev);
}
__transport_stop_task_timer(task, &flags);
if (!atomic_dec_and_test(&cmd->t_task_cdbs_ex_left)) {
spin_unlock_irqrestore(
&cmd->t_state_lock, flags);
pr_debug("Skipping task: %p, dev: %p for"
" t_task_cdbs_ex_left: %d\n", task, dev,
atomic_read(&cmd->t_task_cdbs_ex_left));
spin_lock_irqsave(&dev->execute_task_lock, flags);
continue;
}
if (atomic_read(&cmd->t_transport_active)) {
pr_debug("got t_transport_active = 1 for task: %p, dev:"
" %p\n", task, dev);
if (atomic_read(&cmd->t_fe_count)) {
spin_unlock_irqrestore(
&cmd->t_state_lock, flags);
transport_send_check_condition_and_sense(
cmd, TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE,
0);
transport_remove_cmd_from_queue(cmd,
&cmd->se_dev->dev_queue_obj);
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop(cmd, 1, 0);
} else {
spin_unlock_irqrestore(
&cmd->t_state_lock, flags);
transport_remove_cmd_from_queue(cmd,
&cmd->se_dev->dev_queue_obj);
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop(cmd, 1, 0))
transport_generic_remove(cmd, 0);
}
spin_lock_irqsave(&dev->execute_task_lock, flags);
continue;
}
pr_debug("Got t_transport_active = 0 for task: %p, dev: %p\n",
task, dev);
if (atomic_read(&cmd->t_fe_count)) {
spin_unlock_irqrestore(
&cmd->t_state_lock, flags);
transport_send_check_condition_and_sense(cmd,
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE, 0);
transport_remove_cmd_from_queue(cmd,
&cmd->se_dev->dev_queue_obj);
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop(cmd, 1, 0);
} else {
spin_unlock_irqrestore(
&cmd->t_state_lock, flags);
transport_remove_cmd_from_queue(cmd,
&cmd->se_dev->dev_queue_obj);
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop(cmd, 1, 0))
transport_generic_remove(cmd, 0);
}
spin_lock_irqsave(&dev->execute_task_lock, flags);
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
while ((cmd = transport_get_cmd_from_queue(&dev->dev_queue_obj))) {
pr_debug("From Device Queue: cmd: %p t_state: %d\n",
cmd, cmd->t_state);
if (atomic_read(&cmd->t_fe_count)) {
transport_send_check_condition_and_sense(cmd,
TCM_LOGICAL_UNIT_COMMUNICATION_FAILURE, 0);
transport_lun_remove_cmd(cmd);
transport_cmd_check_stop(cmd, 1, 0);
} else {
transport_lun_remove_cmd(cmd);
if (transport_cmd_check_stop(cmd, 1, 0))
transport_generic_remove(cmd, 0);
}
}
}
static int transport_processing_thread(void *param)
{
int ret;
struct se_cmd *cmd;
struct se_device *dev = (struct se_device *) param;
set_user_nice(current, -20);
while (!kthread_should_stop()) {
ret = wait_event_interruptible(dev->dev_queue_obj.thread_wq,
atomic_read(&dev->dev_queue_obj.queue_cnt) ||
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
cmd = transport_get_cmd_from_queue(&dev->dev_queue_obj);
if (!cmd)
continue;
switch (cmd->t_state) {
case TRANSPORT_NEW_CMD_MAP:
if (!cmd->se_tfo->new_cmd_map) {
pr_err("cmd->se_tfo->new_cmd_map is"
" NULL for TRANSPORT_NEW_CMD_MAP\n");
BUG();
}
ret = cmd->se_tfo->new_cmd_map(cmd);
if (ret < 0) {
cmd->transport_error_status = ret;
transport_generic_request_failure(cmd, NULL,
0, (cmd->data_direction !=
DMA_TO_DEVICE));
break;
}
case TRANSPORT_NEW_CMD:
ret = transport_generic_new_cmd(cmd);
if (ret == -EAGAIN)
break;
else if (ret < 0) {
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
transport_generic_remove(cmd, 0);
break;
case TRANSPORT_FREE_CMD_INTR:
transport_generic_free_cmd(cmd, 0, 0);
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
case TRANSPORT_COMPLETE_QF_WP:
transport_generic_write_pending(cmd);
break;
default:
pr_err("Unknown t_state: %d deferred_t_state:"
" %d for ITT: 0x%08x i_state: %d on SE LUN:"
" %u\n", cmd->t_state, cmd->deferred_t_state,
cmd->se_tfo->get_task_tag(cmd),
cmd->se_tfo->get_cmd_state(cmd),
cmd->se_lun->unpacked_lun);
BUG();
}
goto get_cmd;
}
out:
transport_release_all_cmds(dev);
dev->process_thread = NULL;
return 0;
}
