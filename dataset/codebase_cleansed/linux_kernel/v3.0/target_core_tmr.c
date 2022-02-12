struct se_tmr_req *core_tmr_alloc_req(
struct se_cmd *se_cmd,
void *fabric_tmr_ptr,
u8 function)
{
struct se_tmr_req *tmr;
tmr = kmem_cache_zalloc(se_tmr_req_cache, (in_interrupt()) ?
GFP_ATOMIC : GFP_KERNEL);
if (!(tmr)) {
printk(KERN_ERR "Unable to allocate struct se_tmr_req\n");
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
if (!dev) {
kmem_cache_free(se_tmr_req_cache, tmr);
return;
}
spin_lock(&dev->se_tmr_lock);
list_del(&tmr->tmr_list);
spin_unlock(&dev->se_tmr_lock);
kmem_cache_free(se_tmr_req_cache, tmr);
}
static void core_tmr_handle_tas_abort(
struct se_node_acl *tmr_nacl,
struct se_cmd *cmd,
int tas,
int fe_count)
{
if (!(fe_count)) {
transport_cmd_finish_abort(cmd, 1);
return;
}
if (((tmr_nacl != NULL) &&
(tmr_nacl == cmd->se_sess->se_node_acl)) || tas)
transport_send_task_abort(cmd);
transport_cmd_finish_abort(cmd, 0);
}
int core_tmr_lun_reset(
struct se_device *dev,
struct se_tmr_req *tmr,
struct list_head *preempt_and_abort_list,
struct se_cmd *prout_cmd)
{
struct se_cmd *cmd;
struct se_queue_req *qr, *qr_tmp;
struct se_node_acl *tmr_nacl = NULL;
struct se_portal_group *tmr_tpg = NULL;
struct se_queue_obj *qobj = dev->dev_queue_obj;
struct se_tmr_req *tmr_p, *tmr_pp;
struct se_task *task, *task_tmp;
unsigned long flags;
int fe_count, state, tas;
tas = DEV_ATTRIB(dev)->emulate_tas;
if (tmr && tmr->task_cmd && tmr->task_cmd->se_sess) {
tmr_nacl = tmr->task_cmd->se_sess->se_node_acl;
tmr_tpg = tmr->task_cmd->se_sess->se_tpg;
if (tmr_nacl && tmr_tpg) {
DEBUG_LR("LUN_RESET: TMR caller fabric: %s"
" initiator port %s\n",
TPG_TFO(tmr_tpg)->get_fabric_name(),
tmr_nacl->initiatorname);
}
}
DEBUG_LR("LUN_RESET: %s starting for [%s], tas: %d\n",
(preempt_and_abort_list) ? "Preempt" : "TMR",
TRANSPORT(dev)->name, tas);
spin_lock(&dev->se_tmr_lock);
list_for_each_entry_safe(tmr_p, tmr_pp, &dev->dev_tmr_list, tmr_list) {
if (tmr && (tmr_p == tmr))
continue;
cmd = tmr_p->task_cmd;
if (!(cmd)) {
printk(KERN_ERR "Unable to locate struct se_cmd for TMR\n");
continue;
}
if ((preempt_and_abort_list != NULL) &&
(core_scsi3_check_cdb_abort_and_preempt(
preempt_and_abort_list, cmd) != 0))
continue;
spin_unlock(&dev->se_tmr_lock);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
if (!(atomic_read(&T_TASK(cmd)->t_transport_active))) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
spin_lock(&dev->se_tmr_lock);
continue;
}
if (cmd->t_state == TRANSPORT_ISTATE_PROCESSING) {
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
spin_lock(&dev->se_tmr_lock);
continue;
}
DEBUG_LR("LUN_RESET: %s releasing TMR %p Function: 0x%02x,"
" Response: 0x%02x, t_state: %d\n",
(preempt_and_abort_list) ? "Preempt" : "", tmr_p,
tmr_p->function, tmr_p->response, cmd->t_state);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
transport_cmd_finish_abort_tmr(cmd);
spin_lock(&dev->se_tmr_lock);
}
spin_unlock(&dev->se_tmr_lock);
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_for_each_entry_safe(task, task_tmp, &dev->state_task_list,
t_state_list) {
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
if ((preempt_and_abort_list != NULL) &&
(core_scsi3_check_cdb_abort_and_preempt(
preempt_and_abort_list, cmd) != 0))
continue;
if (prout_cmd == cmd)
continue;
list_del(&task->t_state_list);
atomic_set(&task->task_state_active, 0);
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
spin_lock_irqsave(&T_TASK(cmd)->t_state_lock, flags);
DEBUG_LR("LUN_RESET: %s cmd: %p task: %p"
" ITT/CmdSN: 0x%08x/0x%08x, i_state: %d, t_state/"
"def_t_state: %d/%d cdb: 0x%02x\n",
(preempt_and_abort_list) ? "Preempt" : "", cmd, task,
CMD_TFO(cmd)->get_task_tag(cmd), 0,
CMD_TFO(cmd)->get_cmd_state(cmd), cmd->t_state,
cmd->deferred_t_state, T_TASK(cmd)->t_task_cdb[0]);
DEBUG_LR("LUN_RESET: ITT[0x%08x] - pr_res_key: 0x%016Lx"
" t_task_cdbs: %d t_task_cdbs_left: %d"
" t_task_cdbs_sent: %d -- t_transport_active: %d"
" t_transport_stop: %d t_transport_sent: %d\n",
CMD_TFO(cmd)->get_task_tag(cmd), cmd->pr_res_key,
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
DEBUG_LR("LUN_RESET: Waiting for task: %p to shutdown"
" for dev: %p\n", task, dev);
wait_for_completion(&task->task_stop_comp);
DEBUG_LR("LUN_RESET Completed task: %p shutdown for"
" dev: %p\n", task, dev);
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
DEBUG_LR("LUN_RESET: Skipping task: %p, dev: %p for"
" t_task_cdbs_ex_left: %d\n", task, dev,
atomic_read(&T_TASK(cmd)->t_task_cdbs_ex_left));
spin_lock_irqsave(&dev->execute_task_lock, flags);
continue;
}
fe_count = atomic_read(&T_TASK(cmd)->t_fe_count);
if (atomic_read(&T_TASK(cmd)->t_transport_active)) {
DEBUG_LR("LUN_RESET: got t_transport_active = 1 for"
" task: %p, t_fe_count: %d dev: %p\n", task,
fe_count, dev);
atomic_set(&T_TASK(cmd)->t_transport_aborted, 1);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock,
flags);
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas, fe_count);
spin_lock_irqsave(&dev->execute_task_lock, flags);
continue;
}
DEBUG_LR("LUN_RESET: Got t_transport_active = 0 for task: %p,"
" t_fe_count: %d dev: %p\n", task, fe_count, dev);
atomic_set(&T_TASK(cmd)->t_transport_aborted, 1);
spin_unlock_irqrestore(&T_TASK(cmd)->t_state_lock, flags);
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas, fe_count);
spin_lock_irqsave(&dev->execute_task_lock, flags);
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
list_for_each_entry_safe(qr, qr_tmp, &qobj->qobj_list, qr_list) {
cmd = (struct se_cmd *)qr->cmd;
if (!(cmd)) {
if (preempt_and_abort_list != NULL)
continue;
atomic_dec(&qobj->queue_cnt);
list_del(&qr->qr_list);
kfree(qr);
continue;
}
if ((preempt_and_abort_list != NULL) &&
(core_scsi3_check_cdb_abort_and_preempt(
preempt_and_abort_list, cmd) != 0))
continue;
if (prout_cmd == cmd)
continue;
atomic_dec(&T_TASK(cmd)->t_transport_queue_active);
atomic_dec(&qobj->queue_cnt);
list_del(&qr->qr_list);
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
state = qr->state;
kfree(qr);
DEBUG_LR("LUN_RESET: %s from Device Queue: cmd: %p t_state:"
" %d t_fe_count: %d\n", (preempt_and_abort_list) ?
"Preempt" : "", cmd, state,
atomic_read(&T_TASK(cmd)->t_fe_count));
transport_new_cmd_failure(cmd);
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas,
atomic_read(&T_TASK(cmd)->t_fe_count));
spin_lock_irqsave(&qobj->cmd_queue_lock, flags);
}
spin_unlock_irqrestore(&qobj->cmd_queue_lock, flags);
if (!(preempt_and_abort_list) &&
(dev->dev_flags & DF_SPC2_RESERVATIONS)) {
spin_lock(&dev->dev_reservation_lock);
dev->dev_reserved_node_acl = NULL;
dev->dev_flags &= ~DF_SPC2_RESERVATIONS;
spin_unlock(&dev->dev_reservation_lock);
printk(KERN_INFO "LUN_RESET: SCSI-2 Released reservation\n");
}
spin_lock_irq(&dev->stats_lock);
dev->num_resets++;
spin_unlock_irq(&dev->stats_lock);
DEBUG_LR("LUN_RESET: %s for [%s] Complete\n",
(preempt_and_abort_list) ? "Preempt" : "TMR",
TRANSPORT(dev)->name);
return 0;
}
