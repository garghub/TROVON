struct se_tmr_req *core_tmr_alloc_req(
struct se_cmd *se_cmd,
void *fabric_tmr_ptr,
u8 function,
gfp_t gfp_flags)
{
struct se_tmr_req *tmr;
tmr = kmem_cache_zalloc(se_tmr_req_cache, gfp_flags);
if (!tmr) {
pr_err("Unable to allocate struct se_tmr_req\n");
return ERR_PTR(-ENOMEM);
}
tmr->task_cmd = se_cmd;
tmr->fabric_tmr_ptr = fabric_tmr_ptr;
tmr->function = function;
INIT_LIST_HEAD(&tmr->tmr_list);
return tmr;
}
void core_tmr_release_req(
struct se_tmr_req *tmr)
{
struct se_device *dev = tmr->tmr_dev;
unsigned long flags;
if (!dev) {
kmem_cache_free(se_tmr_req_cache, tmr);
return;
}
spin_lock_irqsave(&dev->se_tmr_lock, flags);
list_del(&tmr->tmr_list);
spin_unlock_irqrestore(&dev->se_tmr_lock, flags);
kmem_cache_free(se_tmr_req_cache, tmr);
}
static void core_tmr_handle_tas_abort(
struct se_node_acl *tmr_nacl,
struct se_cmd *cmd,
int tas,
int fe_count)
{
if (!fe_count) {
transport_cmd_finish_abort(cmd, 1);
return;
}
if ((tmr_nacl &&
(tmr_nacl == cmd->se_sess->se_node_acl)) || tas)
transport_send_task_abort(cmd);
transport_cmd_finish_abort(cmd, 0);
}
static void core_tmr_drain_tmr_list(
struct se_device *dev,
struct se_tmr_req *tmr,
struct list_head *preempt_and_abort_list)
{
LIST_HEAD(drain_tmr_list);
struct se_tmr_req *tmr_p, *tmr_pp;
struct se_cmd *cmd;
unsigned long flags;
spin_lock_irqsave(&dev->se_tmr_lock, flags);
list_for_each_entry_safe(tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if (tmr_p == tmr)
continue;
cmd = tmr_p->task_cmd;
if (!cmd) {
pr_err("Unable to locate struct se_cmd for TMR\n");
continue;
}
if (preempt_and_abort_list &&
(core_scsi3_check_cdb_abort_and_preempt(
preempt_and_abort_list, cmd) != 0))
continue;
spin_lock(&cmd->t_state_lock);
if (!atomic_read(&cmd->t_transport_active)) {
spin_unlock(&cmd->t_state_lock);
continue;
}
if (cmd->t_state == TRANSPORT_ISTATE_PROCESSING) {
spin_unlock(&cmd->t_state_lock);
continue;
}
spin_unlock(&cmd->t_state_lock);
list_move_tail(&tmr_p->tmr_list, &drain_tmr_list);
}
spin_unlock_irqrestore(&dev->se_tmr_lock, flags);
list_for_each_entry_safe(tmr_p, tmr_pp, &drain_tmr_list, tmr_list) {
list_del_init(&tmr_p->tmr_list);
cmd = tmr_p->task_cmd;
pr_debug("LUN_RESET: %s releasing TMR %p Function: 0x%02x,"
" Response: 0x%02x, t_state: %d\n",
(preempt_and_abort_list) ? "Preempt" : "", tmr_p,
tmr_p->function, tmr_p->response, cmd->t_state);
transport_cmd_finish_abort(cmd, 1);
}
}
static void core_tmr_drain_task_list(
struct se_device *dev,
struct se_cmd *prout_cmd,
struct se_node_acl *tmr_nacl,
int tas,
struct list_head *preempt_and_abort_list)
{
LIST_HEAD(drain_task_list);
struct se_cmd *cmd;
struct se_task *task, *task_tmp;
unsigned long flags;
int fe_count;
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_for_each_entry_safe(task, task_tmp, &dev->state_task_list,
t_state_list) {
if (!task->task_se_cmd) {
pr_err("task->task_se_cmd is NULL!\n");
continue;
}
cmd = task->task_se_cmd;
if (preempt_and_abort_list &&
(core_scsi3_check_cdb_abort_and_preempt(
preempt_and_abort_list, cmd) != 0))
continue;
if (prout_cmd == cmd)
continue;
list_move_tail(&task->t_state_list, &drain_task_list);
atomic_set(&task->task_state_active, 0);
if (!list_empty(&task->t_execute_list))
__transport_remove_task_from_execute_queue(task, dev);
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
while (!list_empty(&drain_task_list)) {
task = list_entry(drain_task_list.next, struct se_task, t_state_list);
list_del(&task->t_state_list);
cmd = task->task_se_cmd;
pr_debug("LUN_RESET: %s cmd: %p task: %p"
" ITT/CmdSN: 0x%08x/0x%08x, i_state: %d, t_state: %d"
"cdb: 0x%02x\n",
(preempt_and_abort_list) ? "Preempt" : "", cmd, task,
cmd->se_tfo->get_task_tag(cmd), 0,
cmd->se_tfo->get_cmd_state(cmd), cmd->t_state,
cmd->t_task_cdb[0]);
pr_debug("LUN_RESET: ITT[0x%08x] - pr_res_key: 0x%016Lx"
" t_task_cdbs: %d t_task_cdbs_left: %d"
" t_task_cdbs_sent: %d -- t_transport_active: %d"
" t_transport_stop: %d t_transport_sent: %d\n",
cmd->se_tfo->get_task_tag(cmd), cmd->pr_res_key,
cmd->t_task_list_num,
atomic_read(&cmd->t_task_cdbs_left),
atomic_read(&cmd->t_task_cdbs_sent),
atomic_read(&cmd->t_transport_active),
atomic_read(&cmd->t_transport_stop),
atomic_read(&cmd->t_transport_sent));
if (cmd->t_state == TRANSPORT_COMPLETE)
cancel_work_sync(&cmd->work);
spin_lock_irqsave(&cmd->t_state_lock, flags);
target_stop_task(task, &flags);
if (!atomic_dec_and_test(&cmd->t_task_cdbs_ex_left)) {
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
pr_debug("LUN_RESET: Skipping task: %p, dev: %p for"
" t_task_cdbs_ex_left: %d\n", task, dev,
atomic_read(&cmd->t_task_cdbs_ex_left));
continue;
}
fe_count = atomic_read(&cmd->t_fe_count);
if (atomic_read(&cmd->t_transport_active)) {
pr_debug("LUN_RESET: got t_transport_active = 1 for"
" task: %p, t_fe_count: %d dev: %p\n", task,
fe_count, dev);
atomic_set(&cmd->t_transport_aborted, 1);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas, fe_count);
continue;
}
pr_debug("LUN_RESET: Got t_transport_active = 0 for task: %p,"
" t_fe_count: %d dev: %p\n", task, fe_count, dev);
atomic_set(&cmd->t_transport_aborted, 1);
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas, fe_count);
}
}
static void core_tmr_drain_cmd_list(
struct se_device *dev,
struct se_cmd *prout_cmd,
struct se_node_acl *tmr_nacl,
int tas,
struct list_head *preempt_and_abort_list)
{
LIST_HEAD(drain_cmd_list);
struct se_queue_obj *qobj = &dev->dev_queue_obj;
struct se_cmd *cmd, *tcmd;
unsigned long flags;
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
list_for_each_entry_safe(cmd, tcmd, &qobj->qobj_list, se_queue_node) {
if (preempt_and_abort_list &&
(core_scsi3_check_cdb_abort_and_preempt(
preempt_and_abort_list, cmd) != 0))
continue;
if (prout_cmd == cmd)
continue;
atomic_set(&cmd->t_transport_queue_active, 0);
atomic_dec(&qobj->queue_cnt);
list_move_tail(&cmd->se_queue_node, &drain_cmd_list);
}
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
while (!list_empty(&drain_cmd_list)) {
cmd = list_entry(drain_cmd_list.next, struct se_cmd, se_queue_node);
list_del_init(&cmd->se_queue_node);
pr_debug("LUN_RESET: %s from Device Queue: cmd: %p t_state:"
" %d t_fe_count: %d\n", (preempt_and_abort_list) ?
"Preempt" : "", cmd, cmd->t_state,
atomic_read(&cmd->t_fe_count));
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas,
atomic_read(&cmd->t_fe_count));
}
}
int core_tmr_lun_reset(
struct se_device *dev,
struct se_tmr_req *tmr,
struct list_head *preempt_and_abort_list,
struct se_cmd *prout_cmd)
{
struct se_node_acl *tmr_nacl = NULL;
struct se_portal_group *tmr_tpg = NULL;
int tas;
tas = dev->se_sub_dev->se_dev_attrib.emulate_tas;
if (tmr && tmr->task_cmd && tmr->task_cmd->se_sess) {
tmr_nacl = tmr->task_cmd->se_sess->se_node_acl;
tmr_tpg = tmr->task_cmd->se_sess->se_tpg;
if (tmr_nacl && tmr_tpg) {
pr_debug("LUN_RESET: TMR caller fabric: %s"
" initiator port %s\n",
tmr_tpg->se_tpg_tfo->get_fabric_name(),
tmr_nacl->initiatorname);
}
}
pr_debug("LUN_RESET: %s starting for [%s], tas: %d\n",
(preempt_and_abort_list) ? "Preempt" : "TMR",
dev->transport->name, tas);
core_tmr_drain_tmr_list(dev, tmr, preempt_and_abort_list);
core_tmr_drain_task_list(dev, prout_cmd, tmr_nacl, tas,
preempt_and_abort_list);
core_tmr_drain_cmd_list(dev, prout_cmd, tmr_nacl, tas,
preempt_and_abort_list);
if (!preempt_and_abort_list &&
(dev->dev_flags & DF_SPC2_RESERVATIONS)) {
spin_lock(&dev->dev_reservation_lock);
dev->dev_reserved_node_acl = NULL;
dev->dev_flags &= ~DF_SPC2_RESERVATIONS;
spin_unlock(&dev->dev_reservation_lock);
pr_debug("LUN_RESET: SCSI-2 Released reservation\n");
}
spin_lock_irq(&dev->stats_lock);
dev->num_resets++;
spin_unlock_irq(&dev->stats_lock);
pr_debug("LUN_RESET: %s for [%s] Complete\n",
(preempt_and_abort_list) ? "Preempt" : "TMR",
dev->transport->name);
return 0;
}
