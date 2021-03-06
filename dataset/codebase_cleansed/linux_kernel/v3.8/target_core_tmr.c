int core_tmr_alloc_req(
struct se_cmd *se_cmd,
void *fabric_tmr_ptr,
u8 function,
gfp_t gfp_flags)
{
struct se_tmr_req *tmr;
tmr = kzalloc(sizeof(struct se_tmr_req), gfp_flags);
if (!tmr) {
pr_err("Unable to allocate struct se_tmr_req\n");
return -ENOMEM;
}
se_cmd->se_cmd_flags |= SCF_SCSI_TMR_CDB;
se_cmd->se_tmr_req = tmr;
tmr->task_cmd = se_cmd;
tmr->fabric_tmr_ptr = fabric_tmr_ptr;
tmr->function = function;
INIT_LIST_HEAD(&tmr->tmr_list);
return 0;
}
void core_tmr_release_req(
struct se_tmr_req *tmr)
{
struct se_device *dev = tmr->tmr_dev;
unsigned long flags;
if (!dev) {
kfree(tmr);
return;
}
spin_lock_irqsave(&dev->se_tmr_lock, flags);
list_del(&tmr->tmr_list);
spin_unlock_irqrestore(&dev->se_tmr_lock, flags);
kfree(tmr);
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
static int target_check_cdb_and_preempt(struct list_head *list,
struct se_cmd *cmd)
{
struct t10_pr_registration *reg;
if (!list)
return 0;
list_for_each_entry(reg, list, pr_reg_abort_list) {
if (reg->pr_res_key == cmd->pr_res_key)
return 0;
}
return 1;
}
void core_tmr_abort_task(
struct se_device *dev,
struct se_tmr_req *tmr,
struct se_session *se_sess)
{
struct se_cmd *se_cmd, *tmp_cmd;
unsigned long flags;
int ref_tag;
spin_lock_irqsave(&se_sess->sess_cmd_lock, flags);
list_for_each_entry_safe(se_cmd, tmp_cmd,
&se_sess->sess_cmd_list, se_cmd_list) {
if (dev != se_cmd->se_dev)
continue;
ref_tag = se_cmd->se_tfo->get_task_tag(se_cmd);
if (tmr->ref_task_tag != ref_tag)
continue;
printk("ABORT_TASK: Found referenced %s task_tag: %u\n",
se_cmd->se_tfo->get_fabric_name(), ref_tag);
spin_lock(&se_cmd->t_state_lock);
if (se_cmd->transport_state & CMD_T_COMPLETE) {
printk("ABORT_TASK: ref_tag: %u already complete, skipping\n", ref_tag);
spin_unlock(&se_cmd->t_state_lock);
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
goto out;
}
se_cmd->transport_state |= CMD_T_ABORTED;
spin_unlock(&se_cmd->t_state_lock);
list_del_init(&se_cmd->se_cmd_list);
kref_get(&se_cmd->cmd_kref);
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
cancel_work_sync(&se_cmd->work);
transport_wait_for_tasks(se_cmd);
transport_send_task_abort(se_cmd);
if (se_cmd->se_cmd_flags & SCF_ACK_KREF)
target_put_sess_cmd(se_sess, se_cmd);
target_put_sess_cmd(se_sess, se_cmd);
printk("ABORT_TASK: Sending TMR_FUNCTION_COMPLETE for"
" ref_tag: %d\n", ref_tag);
tmr->response = TMR_FUNCTION_COMPLETE;
return;
}
spin_unlock_irqrestore(&se_sess->sess_cmd_lock, flags);
out:
printk("ABORT_TASK: Sending TMR_TASK_DOES_NOT_EXIST for ref_tag: %d\n",
tmr->ref_task_tag);
tmr->response = TMR_TASK_DOES_NOT_EXIST;
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
if (target_check_cdb_and_preempt(preempt_and_abort_list, cmd))
continue;
spin_lock(&cmd->t_state_lock);
if (!(cmd->transport_state & CMD_T_ACTIVE)) {
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
static void core_tmr_drain_state_list(
struct se_device *dev,
struct se_cmd *prout_cmd,
struct se_node_acl *tmr_nacl,
int tas,
struct list_head *preempt_and_abort_list)
{
LIST_HEAD(drain_task_list);
struct se_cmd *cmd, *next;
unsigned long flags;
int fe_count;
spin_lock_irqsave(&dev->execute_task_lock, flags);
list_for_each_entry_safe(cmd, next, &dev->state_list, state_list) {
if (target_check_cdb_and_preempt(preempt_and_abort_list, cmd))
continue;
if (prout_cmd == cmd)
continue;
list_move_tail(&cmd->state_list, &drain_task_list);
cmd->state_active = false;
}
spin_unlock_irqrestore(&dev->execute_task_lock, flags);
while (!list_empty(&drain_task_list)) {
cmd = list_entry(drain_task_list.next, struct se_cmd, state_list);
list_del(&cmd->state_list);
pr_debug("LUN_RESET: %s cmd: %p"
" ITT/CmdSN: 0x%08x/0x%08x, i_state: %d, t_state: %d"
"cdb: 0x%02x\n",
(preempt_and_abort_list) ? "Preempt" : "", cmd,
cmd->se_tfo->get_task_tag(cmd), 0,
cmd->se_tfo->get_cmd_state(cmd), cmd->t_state,
cmd->t_task_cdb[0]);
pr_debug("LUN_RESET: ITT[0x%08x] - pr_res_key: 0x%016Lx"
" -- CMD_T_ACTIVE: %d"
" CMD_T_STOP: %d CMD_T_SENT: %d\n",
cmd->se_tfo->get_task_tag(cmd), cmd->pr_res_key,
(cmd->transport_state & CMD_T_ACTIVE) != 0,
(cmd->transport_state & CMD_T_STOP) != 0,
(cmd->transport_state & CMD_T_SENT) != 0);
if (cmd->t_state == TRANSPORT_COMPLETE)
cancel_work_sync(&cmd->work);
spin_lock_irqsave(&cmd->t_state_lock, flags);
target_stop_cmd(cmd, &flags);
fe_count = atomic_read(&cmd->t_fe_count);
if (!(cmd->transport_state & CMD_T_ACTIVE)) {
pr_debug("LUN_RESET: got CMD_T_ACTIVE for"
" cdb: %p, t_fe_count: %d dev: %p\n", cmd,
fe_count, dev);
cmd->transport_state |= CMD_T_ABORTED;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas, fe_count);
continue;
}
pr_debug("LUN_RESET: Got !CMD_T_ACTIVE for cdb: %p,"
" t_fe_count: %d dev: %p\n", cmd, fe_count, dev);
cmd->transport_state |= CMD_T_ABORTED;
spin_unlock_irqrestore(&cmd->t_state_lock, flags);
core_tmr_handle_tas_abort(tmr_nacl, cmd, tas, fe_count);
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
tas = dev->dev_attrib.emulate_tas;
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
core_tmr_drain_state_list(dev, prout_cmd, tmr_nacl, tas,
preempt_and_abort_list);
if (!preempt_and_abort_list &&
(dev->dev_reservation_flags & DRF_SPC2_RESERVATIONS)) {
spin_lock(&dev->dev_reservation_lock);
dev->dev_reserved_node_acl = NULL;
dev->dev_reservation_flags &= ~DRF_SPC2_RESERVATIONS;
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
