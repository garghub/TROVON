unsigned int ccp_increment_unit_ordinal(void)
{
return atomic_inc_return(&ccp_unit_ordinal);
}
void ccp_add_device(struct ccp_device *ccp)
{
unsigned long flags;
write_lock_irqsave(&ccp_unit_lock, flags);
list_add_tail(&ccp->entry, &ccp_units);
if (!ccp_rr)
ccp_rr = ccp;
write_unlock_irqrestore(&ccp_unit_lock, flags);
}
void ccp_del_device(struct ccp_device *ccp)
{
unsigned long flags;
write_lock_irqsave(&ccp_unit_lock, flags);
if (ccp_rr == ccp) {
if (list_is_last(&ccp_rr->entry, &ccp_units))
ccp_rr = list_first_entry(&ccp_units, struct ccp_device,
entry);
else
ccp_rr = list_next_entry(ccp_rr, entry);
}
list_del(&ccp->entry);
if (list_empty(&ccp_units))
ccp_rr = NULL;
write_unlock_irqrestore(&ccp_unit_lock, flags);
}
static struct ccp_device *ccp_get_device(void)
{
unsigned long flags;
struct ccp_device *dp = NULL;
read_lock_irqsave(&ccp_unit_lock, flags);
if (!list_empty(&ccp_units)) {
spin_lock(&ccp_rr_lock);
dp = ccp_rr;
if (list_is_last(&ccp_rr->entry, &ccp_units))
ccp_rr = list_first_entry(&ccp_units, struct ccp_device,
entry);
else
ccp_rr = list_next_entry(ccp_rr, entry);
spin_unlock(&ccp_rr_lock);
}
read_unlock_irqrestore(&ccp_unit_lock, flags);
return dp;
}
int ccp_present(void)
{
unsigned long flags;
int ret;
read_lock_irqsave(&ccp_unit_lock, flags);
ret = list_empty(&ccp_units);
read_unlock_irqrestore(&ccp_unit_lock, flags);
return ret ? -ENODEV : 0;
}
unsigned int ccp_version(void)
{
struct ccp_device *dp;
unsigned long flags;
int ret = 0;
read_lock_irqsave(&ccp_unit_lock, flags);
if (!list_empty(&ccp_units)) {
dp = list_first_entry(&ccp_units, struct ccp_device, entry);
ret = dp->vdata->version;
}
read_unlock_irqrestore(&ccp_unit_lock, flags);
return ret;
}
int ccp_enqueue_cmd(struct ccp_cmd *cmd)
{
struct ccp_device *ccp = ccp_get_device();
unsigned long flags;
unsigned int i;
int ret;
if (!ccp)
return -ENODEV;
if (!cmd->callback)
return -EINVAL;
cmd->ccp = ccp;
spin_lock_irqsave(&ccp->cmd_lock, flags);
i = ccp->cmd_q_count;
if (ccp->cmd_count >= MAX_CMD_QLEN) {
ret = -EBUSY;
if (cmd->flags & CCP_CMD_MAY_BACKLOG)
list_add_tail(&cmd->entry, &ccp->backlog);
} else {
ret = -EINPROGRESS;
ccp->cmd_count++;
list_add_tail(&cmd->entry, &ccp->cmd);
if (!ccp->suspending) {
for (i = 0; i < ccp->cmd_q_count; i++) {
if (ccp->cmd_q[i].active)
continue;
break;
}
}
}
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
if (i < ccp->cmd_q_count)
wake_up_process(ccp->cmd_q[i].kthread);
return ret;
}
static void ccp_do_cmd_backlog(struct work_struct *work)
{
struct ccp_cmd *cmd = container_of(work, struct ccp_cmd, work);
struct ccp_device *ccp = cmd->ccp;
unsigned long flags;
unsigned int i;
cmd->callback(cmd->data, -EINPROGRESS);
spin_lock_irqsave(&ccp->cmd_lock, flags);
ccp->cmd_count++;
list_add_tail(&cmd->entry, &ccp->cmd);
for (i = 0; i < ccp->cmd_q_count; i++) {
if (ccp->cmd_q[i].active)
continue;
break;
}
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
if (i < ccp->cmd_q_count)
wake_up_process(ccp->cmd_q[i].kthread);
}
static struct ccp_cmd *ccp_dequeue_cmd(struct ccp_cmd_queue *cmd_q)
{
struct ccp_device *ccp = cmd_q->ccp;
struct ccp_cmd *cmd = NULL;
struct ccp_cmd *backlog = NULL;
unsigned long flags;
spin_lock_irqsave(&ccp->cmd_lock, flags);
cmd_q->active = 0;
if (ccp->suspending) {
cmd_q->suspended = 1;
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
wake_up_interruptible(&ccp->suspend_queue);
return NULL;
}
if (ccp->cmd_count) {
cmd_q->active = 1;
cmd = list_first_entry(&ccp->cmd, struct ccp_cmd, entry);
list_del(&cmd->entry);
ccp->cmd_count--;
}
if (!list_empty(&ccp->backlog)) {
backlog = list_first_entry(&ccp->backlog, struct ccp_cmd,
entry);
list_del(&backlog->entry);
}
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
if (backlog) {
INIT_WORK(&backlog->work, ccp_do_cmd_backlog);
schedule_work(&backlog->work);
}
return cmd;
}
static void ccp_do_cmd_complete(unsigned long data)
{
struct ccp_tasklet_data *tdata = (struct ccp_tasklet_data *)data;
struct ccp_cmd *cmd = tdata->cmd;
cmd->callback(cmd->data, cmd->ret);
complete(&tdata->completion);
}
int ccp_cmd_queue_thread(void *data)
{
struct ccp_cmd_queue *cmd_q = (struct ccp_cmd_queue *)data;
struct ccp_cmd *cmd;
struct ccp_tasklet_data tdata;
struct tasklet_struct tasklet;
tasklet_init(&tasklet, ccp_do_cmd_complete, (unsigned long)&tdata);
set_current_state(TASK_INTERRUPTIBLE);
while (!kthread_should_stop()) {
schedule();
set_current_state(TASK_INTERRUPTIBLE);
cmd = ccp_dequeue_cmd(cmd_q);
if (!cmd)
continue;
__set_current_state(TASK_RUNNING);
cmd->ret = ccp_run_cmd(cmd_q, cmd);
tdata.cmd = cmd;
init_completion(&tdata.completion);
tasklet_schedule(&tasklet);
wait_for_completion(&tdata.completion);
}
__set_current_state(TASK_RUNNING);
return 0;
}
struct ccp_device *ccp_alloc_struct(struct device *dev)
{
struct ccp_device *ccp;
ccp = devm_kzalloc(dev, sizeof(*ccp), GFP_KERNEL);
if (!ccp)
return NULL;
ccp->dev = dev;
INIT_LIST_HEAD(&ccp->cmd);
INIT_LIST_HEAD(&ccp->backlog);
spin_lock_init(&ccp->cmd_lock);
mutex_init(&ccp->req_mutex);
mutex_init(&ccp->ksb_mutex);
ccp->ksb_count = KSB_COUNT;
ccp->ksb_start = 0;
ccp->ord = ccp_increment_unit_ordinal();
snprintf(ccp->name, MAX_CCP_NAME_LEN, "ccp-%u", ccp->ord);
snprintf(ccp->rngname, MAX_CCP_NAME_LEN, "ccp-%u-rng", ccp->ord);
return ccp;
}
bool ccp_queues_suspended(struct ccp_device *ccp)
{
unsigned int suspended = 0;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&ccp->cmd_lock, flags);
for (i = 0; i < ccp->cmd_q_count; i++)
if (ccp->cmd_q[i].suspended)
suspended++;
spin_unlock_irqrestore(&ccp->cmd_lock, flags);
return ccp->cmd_q_count == suspended;
}
static int __init ccp_mod_init(void)
{
#ifdef CONFIG_X86
int ret;
ret = ccp_pci_init();
if (ret)
return ret;
if (ccp_present() != 0) {
ccp_pci_exit();
return -ENODEV;
}
return 0;
#endif
#ifdef CONFIG_ARM64
int ret;
ret = ccp_platform_init();
if (ret)
return ret;
if (ccp_present() != 0) {
ccp_platform_exit();
return -ENODEV;
}
return 0;
#endif
return -ENODEV;
}
static void __exit ccp_mod_exit(void)
{
#ifdef CONFIG_X86
ccp_pci_exit();
#endif
#ifdef CONFIG_ARM64
ccp_platform_exit();
#endif
}
