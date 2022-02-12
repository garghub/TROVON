inline int mdp_ppp_get_ret_code(void)
{
return mdp_ppp_ret_code;
}
inline void mdp_ppp_outdw(uint32_t addr, uint32_t data)
{
if (curr_djob) {
struct mdp_ppp_roi_cmd_set *node =
list_entry(curr_djob->roi_cmd_list.prev,
struct mdp_ppp_roi_cmd_set, node);
if (node->ncmds == MDP_PPP_ROI_NODE_SIZE) {
node = kmalloc(sizeof(struct mdp_ppp_roi_cmd_set),
GFP_KERNEL);
if (!node) {
printk(KERN_ERR
"MDP_PPP: not enough memory.\n");
mdp_ppp_ret_code = -EINVAL;
return;
}
node->ncmds = 0;
list_add_tail(&node->node, &curr_djob->roi_cmd_list);
}
node->cmd[node->ncmds].reg = addr;
node->cmd[node->ncmds].val = data;
node->ncmds++;
} else
outpdw((addr), (data));
}
inline void mdp_ppp_dq_init(void)
{
mdp_ppp_djob_clnr = create_singlethread_workqueue("MDPDJobClnrThrd");
}
static void mdp_ppp_del_djob(struct mdp_ppp_djob *job)
{
struct mdp_ppp_roi_cmd_set *node, *tmp;
mdp_ppp_put_img(job->p_src_file, job->p_dst_file);
list_for_each_entry_safe(node, tmp, &job->roi_cmd_list, node) {
list_del(&node->node);
kfree(node);
}
kfree(job);
}
static void mdp_ppp_djob_cleaner(struct work_struct *work)
{
struct mdp_ppp_djob *job;
MDP_PPP_DEBUG_MSG("mdp ppp display job cleaner started \n");
job = container_of(work, struct mdp_ppp_djob, cleaner.work);
if (likely(work && job))
mdp_ppp_del_djob(job);
}
inline struct mdp_ppp_djob *mdp_ppp_new_djob(void)
{
struct mdp_ppp_djob *job;
struct mdp_ppp_roi_cmd_set *node;
job = kmalloc(sizeof(struct mdp_ppp_djob), GFP_KERNEL);
if (!job)
return NULL;
node = kmalloc(sizeof(struct mdp_ppp_roi_cmd_set), GFP_KERNEL);
if (!node) {
kfree(job);
return NULL;
}
BUG_ON(curr_djob);
curr_djob = job;
INIT_LIST_HEAD(&curr_djob->roi_cmd_list);
node->ncmds = 0;
INIT_LIST_HEAD(&node->node);
list_add_tail(&node->node, &curr_djob->roi_cmd_list);
INIT_DELAYED_WORK(&curr_djob->cleaner, mdp_ppp_djob_cleaner);
INIT_LIST_HEAD(&curr_djob->entry);
curr_djob->p_src_file = 0;
curr_djob->p_dst_file = 0;
return job;
}
inline void mdp_ppp_clear_curr_djob(void)
{
if (likely(curr_djob)) {
mdp_ppp_del_djob(curr_djob);
curr_djob = NULL;
}
}
static void mdp_ppp_flush_dirty_djobs(void *cond)
{
unsigned long flags;
struct mdp_ppp_djob *job;
while (cond && test_bit(0, (unsigned long *)cond)) {
spin_lock_irqsave(&mdp_ppp_djob_clnrq_lock, flags);
if (list_empty(&mdp_ppp_djob_clnrq)) {
spin_unlock_irqrestore(&mdp_ppp_djob_clnrq_lock, flags);
break;
}
MDP_PPP_DEBUG_MSG("flushing djobs ... loop \n");
job = list_entry(mdp_ppp_djob_clnrq.next,
struct mdp_ppp_djob, entry);
list_del_init(&job->entry);
spin_unlock_irqrestore(&mdp_ppp_djob_clnrq_lock, flags);
msm_fb_ensure_mem_coherency_after_dma(job->info, &job->req, 1);
queue_delayed_work(mdp_ppp_djob_clnr, &job->cleaner,
mdp_timer_duration);
}
}
void mdp_ppp_wait(void)
{
unsigned long flags;
int cond = 1;
mdp_ppp_flush_dirty_djobs(&mdp_ppp_busy_flag);
spin_lock_irqsave(&mdp_ppp_dq_lock, flags);
if (test_bit(0, (unsigned long *)&mdp_ppp_busy_flag)) {
test_and_set_bit(0, (unsigned long *)&mdp_ppp_waiting);
INIT_COMPLETION(mdp_ppp_comp);
spin_unlock_irqrestore(&mdp_ppp_dq_lock, flags);
MDP_PPP_DEBUG_MSG("waiting for mdp... \n");
wait_for_completion_killable(&mdp_ppp_comp);
spin_lock_irqsave(&mdp_ppp_dq_lock, flags);
if (!test_bit(0, (unsigned long *)&mdp_ppp_busy_flag) &&
test_and_clear_bit(0, (unsigned long *)&mdp_ppp_intr_flag))
mdp_disable_irq(MDP_PPP_TERM);
}
spin_unlock_irqrestore(&mdp_ppp_dq_lock, flags);
mdp_ppp_flush_dirty_djobs(&cond);
}
static void mdp_ppp_process_roi(struct list_head *roi_cmd_list)
{
struct mdp_ppp_roi_cmd_set *node;
list_for_each_entry(node, roi_cmd_list, node) {
int i = 0;
for (; i < node->ncmds; i++) {
MDP_PPP_DEBUG_MSG("%d: reg: 0x%x val: 0x%x \n",
i, node->cmd[i].reg, node->cmd[i].val);
outpdw(node->cmd[i].reg, node->cmd[i].val);
}
}
MDP_PPP_DEBUG_MSG("kicking off mdp \n");
outpdw(MDP_BASE + 0x30, 0x1000);
}
static void mdp_ppp_dispatch_djob(struct mdp_ppp_djob *job)
{
if (!test_and_set_bit(0, (unsigned long *)&mdp_ppp_intr_flag))
mdp_enable_irq(MDP_PPP_TERM);
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
mdp_pipe_ctrl(MDP_PPP_BLOCK, MDP_BLOCK_POWER_ON, FALSE);
mdp_ppp_process_roi(&job->roi_cmd_list);
}
static inline void mdp_ppp_enqueue_djob(struct mdp_ppp_djob *job)
{
unsigned long flags;
spin_lock_irqsave(&mdp_ppp_dq_lock, flags);
list_add_tail(&job->entry, &mdp_ppp_dq);
spin_unlock_irqrestore(&mdp_ppp_dq_lock, flags);
}
void mdp_ppp_process_curr_djob(void)
{
mdp_ppp_enqueue_djob(curr_djob);
if (!test_and_set_bit(0, (unsigned long *)&mdp_ppp_busy_flag))
mdp_ppp_dispatch_djob(curr_djob);
curr_djob = NULL;
}
void mdp_ppp_djob_done(void)
{
struct mdp_ppp_djob *curr, *next;
unsigned long flags;
spin_lock_irqsave(&mdp_ppp_dq_lock, flags);
curr = list_entry(mdp_ppp_dq.next, struct mdp_ppp_djob, entry);
list_del_init(&curr->entry);
spin_unlock_irqrestore(&mdp_ppp_dq_lock, flags);
spin_lock_irqsave(&mdp_ppp_djob_clnrq_lock, flags);
list_add_tail(&curr->entry, &mdp_ppp_djob_clnrq);
spin_unlock_irqrestore(&mdp_ppp_djob_clnrq_lock, flags);
spin_lock_irqsave(&mdp_ppp_dq_lock, flags);
if (!list_empty(&mdp_ppp_dq)) {
next = list_entry(mdp_ppp_dq.next, struct mdp_ppp_djob,
entry);
spin_unlock_irqrestore(&mdp_ppp_dq_lock, flags);
mdp_ppp_process_roi(&next->roi_cmd_list);
} else {
spin_unlock_irqrestore(&mdp_ppp_dq_lock, flags);
mdp_pipe_ctrl(MDP_PPP_BLOCK, MDP_BLOCK_POWER_OFF, TRUE);
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, TRUE);
if (test_and_clear_bit(0, (unsigned long *)&mdp_ppp_waiting))
complete(&mdp_ppp_comp);
test_and_clear_bit(0, (unsigned long *)&mdp_ppp_busy_flag);
}
}
