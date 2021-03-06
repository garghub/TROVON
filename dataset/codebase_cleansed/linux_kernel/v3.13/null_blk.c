static void put_tag(struct nullb_queue *nq, unsigned int tag)
{
clear_bit_unlock(tag, nq->tag_map);
if (waitqueue_active(&nq->wait))
wake_up(&nq->wait);
}
static unsigned int get_tag(struct nullb_queue *nq)
{
unsigned int tag;
do {
tag = find_first_zero_bit(nq->tag_map, nq->queue_depth);
if (tag >= nq->queue_depth)
return -1U;
} while (test_and_set_bit_lock(tag, nq->tag_map));
return tag;
}
static void free_cmd(struct nullb_cmd *cmd)
{
put_tag(cmd->nq, cmd->tag);
}
static struct nullb_cmd *__alloc_cmd(struct nullb_queue *nq)
{
struct nullb_cmd *cmd;
unsigned int tag;
tag = get_tag(nq);
if (tag != -1U) {
cmd = &nq->cmds[tag];
cmd->tag = tag;
cmd->nq = nq;
return cmd;
}
return NULL;
}
static struct nullb_cmd *alloc_cmd(struct nullb_queue *nq, int can_wait)
{
struct nullb_cmd *cmd;
DEFINE_WAIT(wait);
cmd = __alloc_cmd(nq);
if (cmd || !can_wait)
return cmd;
do {
prepare_to_wait(&nq->wait, &wait, TASK_UNINTERRUPTIBLE);
cmd = __alloc_cmd(nq);
if (cmd)
break;
io_schedule();
} while (1);
finish_wait(&nq->wait, &wait);
return cmd;
}
static void end_cmd(struct nullb_cmd *cmd)
{
if (cmd->rq) {
if (queue_mode == NULL_Q_MQ)
blk_mq_end_io(cmd->rq, 0);
else {
INIT_LIST_HEAD(&cmd->rq->queuelist);
blk_end_request_all(cmd->rq, 0);
}
} else if (cmd->bio)
bio_endio(cmd->bio, 0);
if (queue_mode != NULL_Q_MQ)
free_cmd(cmd);
}
static enum hrtimer_restart null_cmd_timer_expired(struct hrtimer *timer)
{
struct completion_queue *cq;
struct llist_node *entry;
struct nullb_cmd *cmd;
cq = &per_cpu(completion_queues, smp_processor_id());
while ((entry = llist_del_all(&cq->list)) != NULL) {
do {
cmd = container_of(entry, struct nullb_cmd, ll_list);
end_cmd(cmd);
entry = entry->next;
} while (entry);
}
return HRTIMER_NORESTART;
}
static void null_cmd_end_timer(struct nullb_cmd *cmd)
{
struct completion_queue *cq = &per_cpu(completion_queues, get_cpu());
cmd->ll_list.next = NULL;
if (llist_add(&cmd->ll_list, &cq->list)) {
ktime_t kt = ktime_set(0, completion_nsec);
hrtimer_start(&cq->timer, kt, HRTIMER_MODE_REL);
}
put_cpu();
}
static void null_softirq_done_fn(struct request *rq)
{
blk_end_request_all(rq, 0);
}
static void null_ipi_cmd_end_io(void *data)
{
struct completion_queue *cq;
struct llist_node *entry, *next;
struct nullb_cmd *cmd;
cq = &per_cpu(completion_queues, smp_processor_id());
entry = llist_del_all(&cq->list);
while (entry) {
next = entry->next;
cmd = llist_entry(entry, struct nullb_cmd, ll_list);
end_cmd(cmd);
entry = next;
}
}
static void null_cmd_end_ipi(struct nullb_cmd *cmd)
{
struct call_single_data *data = &cmd->csd;
int cpu = get_cpu();
struct completion_queue *cq = &per_cpu(completion_queues, cpu);
cmd->ll_list.next = NULL;
if (llist_add(&cmd->ll_list, &cq->list)) {
data->func = null_ipi_cmd_end_io;
data->flags = 0;
__smp_call_function_single(cpu, data, 0);
}
put_cpu();
}
static inline void null_handle_cmd(struct nullb_cmd *cmd)
{
switch (irqmode) {
case NULL_IRQ_NONE:
end_cmd(cmd);
break;
case NULL_IRQ_SOFTIRQ:
#ifdef CONFIG_SMP
null_cmd_end_ipi(cmd);
#else
end_cmd(cmd);
#endif
break;
case NULL_IRQ_TIMER:
null_cmd_end_timer(cmd);
break;
}
}
static struct nullb_queue *nullb_to_queue(struct nullb *nullb)
{
int index = 0;
if (nullb->nr_queues != 1)
index = raw_smp_processor_id() / ((nr_cpu_ids + nullb->nr_queues - 1) / nullb->nr_queues);
return &nullb->queues[index];
}
static void null_queue_bio(struct request_queue *q, struct bio *bio)
{
struct nullb *nullb = q->queuedata;
struct nullb_queue *nq = nullb_to_queue(nullb);
struct nullb_cmd *cmd;
cmd = alloc_cmd(nq, 1);
cmd->bio = bio;
null_handle_cmd(cmd);
}
static int null_rq_prep_fn(struct request_queue *q, struct request *req)
{
struct nullb *nullb = q->queuedata;
struct nullb_queue *nq = nullb_to_queue(nullb);
struct nullb_cmd *cmd;
cmd = alloc_cmd(nq, 0);
if (cmd) {
cmd->rq = req;
req->special = cmd;
return BLKPREP_OK;
}
return BLKPREP_DEFER;
}
static void null_request_fn(struct request_queue *q)
{
struct request *rq;
while ((rq = blk_fetch_request(q)) != NULL) {
struct nullb_cmd *cmd = rq->special;
spin_unlock_irq(q->queue_lock);
null_handle_cmd(cmd);
spin_lock_irq(q->queue_lock);
}
}
static int null_queue_rq(struct blk_mq_hw_ctx *hctx, struct request *rq)
{
struct nullb_cmd *cmd = rq->special;
cmd->rq = rq;
cmd->nq = hctx->driver_data;
null_handle_cmd(cmd);
return BLK_MQ_RQ_QUEUE_OK;
}
static struct blk_mq_hw_ctx *null_alloc_hctx(struct blk_mq_reg *reg, unsigned int hctx_index)
{
int b_size = DIV_ROUND_UP(reg->nr_hw_queues, nr_online_nodes);
int tip = (reg->nr_hw_queues % nr_online_nodes);
int node = 0, i, n;
for (i = 0, n = 1; i < hctx_index; i++, n++) {
if (n % b_size == 0) {
n = 0;
node++;
tip--;
if (!tip)
b_size = reg->nr_hw_queues / nr_online_nodes;
}
}
for_each_online_node(n) {
if (!node)
break;
node--;
}
return kzalloc_node(sizeof(struct blk_mq_hw_ctx), GFP_KERNEL, n);
}
static void null_free_hctx(struct blk_mq_hw_ctx *hctx, unsigned int hctx_index)
{
kfree(hctx);
}
static void null_init_queue(struct nullb *nullb, struct nullb_queue *nq)
{
BUG_ON(!nullb);
BUG_ON(!nq);
init_waitqueue_head(&nq->wait);
nq->queue_depth = nullb->queue_depth;
}
static int null_init_hctx(struct blk_mq_hw_ctx *hctx, void *data,
unsigned int index)
{
struct nullb *nullb = data;
struct nullb_queue *nq = &nullb->queues[index];
hctx->driver_data = nq;
null_init_queue(nullb, nq);
nullb->nr_queues++;
return 0;
}
static void null_del_dev(struct nullb *nullb)
{
list_del_init(&nullb->list);
del_gendisk(nullb->disk);
blk_cleanup_queue(nullb->q);
put_disk(nullb->disk);
kfree(nullb);
}
static int null_open(struct block_device *bdev, fmode_t mode)
{
return 0;
}
static void null_release(struct gendisk *disk, fmode_t mode)
{
}
static int setup_commands(struct nullb_queue *nq)
{
struct nullb_cmd *cmd;
int i, tag_size;
nq->cmds = kzalloc(nq->queue_depth * sizeof(*cmd), GFP_KERNEL);
if (!nq->cmds)
return -ENOMEM;
tag_size = ALIGN(nq->queue_depth, BITS_PER_LONG) / BITS_PER_LONG;
nq->tag_map = kzalloc(tag_size * sizeof(unsigned long), GFP_KERNEL);
if (!nq->tag_map) {
kfree(nq->cmds);
return -ENOMEM;
}
for (i = 0; i < nq->queue_depth; i++) {
cmd = &nq->cmds[i];
INIT_LIST_HEAD(&cmd->list);
cmd->ll_list.next = NULL;
cmd->tag = -1U;
}
return 0;
}
static void cleanup_queue(struct nullb_queue *nq)
{
kfree(nq->tag_map);
kfree(nq->cmds);
}
static void cleanup_queues(struct nullb *nullb)
{
int i;
for (i = 0; i < nullb->nr_queues; i++)
cleanup_queue(&nullb->queues[i]);
kfree(nullb->queues);
}
static int setup_queues(struct nullb *nullb)
{
nullb->queues = kzalloc(submit_queues * sizeof(struct nullb_queue),
GFP_KERNEL);
if (!nullb->queues)
return -ENOMEM;
nullb->nr_queues = 0;
nullb->queue_depth = hw_queue_depth;
return 0;
}
static int init_driver_queues(struct nullb *nullb)
{
struct nullb_queue *nq;
int i, ret = 0;
for (i = 0; i < submit_queues; i++) {
nq = &nullb->queues[i];
null_init_queue(nullb, nq);
ret = setup_commands(nq);
if (ret)
goto err_queue;
nullb->nr_queues++;
}
return 0;
err_queue:
cleanup_queues(nullb);
return ret;
}
static int null_add_dev(void)
{
struct gendisk *disk;
struct nullb *nullb;
sector_t size;
nullb = kzalloc_node(sizeof(*nullb), GFP_KERNEL, home_node);
if (!nullb)
return -ENOMEM;
spin_lock_init(&nullb->lock);
if (queue_mode == NULL_Q_MQ && use_per_node_hctx)
submit_queues = nr_online_nodes;
if (setup_queues(nullb))
goto err;
if (queue_mode == NULL_Q_MQ) {
null_mq_reg.numa_node = home_node;
null_mq_reg.queue_depth = hw_queue_depth;
null_mq_reg.nr_hw_queues = submit_queues;
if (use_per_node_hctx) {
null_mq_reg.ops->alloc_hctx = null_alloc_hctx;
null_mq_reg.ops->free_hctx = null_free_hctx;
} else {
null_mq_reg.ops->alloc_hctx = blk_mq_alloc_single_hw_queue;
null_mq_reg.ops->free_hctx = blk_mq_free_single_hw_queue;
}
nullb->q = blk_mq_init_queue(&null_mq_reg, nullb);
} else if (queue_mode == NULL_Q_BIO) {
nullb->q = blk_alloc_queue_node(GFP_KERNEL, home_node);
blk_queue_make_request(nullb->q, null_queue_bio);
init_driver_queues(nullb);
} else {
nullb->q = blk_init_queue_node(null_request_fn, &nullb->lock, home_node);
blk_queue_prep_rq(nullb->q, null_rq_prep_fn);
if (nullb->q)
blk_queue_softirq_done(nullb->q, null_softirq_done_fn);
init_driver_queues(nullb);
}
if (!nullb->q)
goto queue_fail;
nullb->q->queuedata = nullb;
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, nullb->q);
disk = nullb->disk = alloc_disk_node(1, home_node);
if (!disk) {
queue_fail:
blk_cleanup_queue(nullb->q);
cleanup_queues(nullb);
err:
kfree(nullb);
return -ENOMEM;
}
mutex_lock(&lock);
list_add_tail(&nullb->list, &nullb_list);
nullb->index = nullb_indexes++;
mutex_unlock(&lock);
blk_queue_logical_block_size(nullb->q, bs);
blk_queue_physical_block_size(nullb->q, bs);
size = gb * 1024 * 1024 * 1024ULL;
sector_div(size, bs);
set_capacity(disk, size);
disk->flags |= GENHD_FL_EXT_DEVT;
disk->major = null_major;
disk->first_minor = nullb->index;
disk->fops = &null_fops;
disk->private_data = nullb;
disk->queue = nullb->q;
sprintf(disk->disk_name, "nullb%d", nullb->index);
add_disk(disk);
return 0;
}
static int __init null_init(void)
{
unsigned int i;
#if !defined(CONFIG_SMP)
if (irqmode == NULL_IRQ_SOFTIRQ) {
pr_warn("null_blk: softirq completions not available.\n");
pr_warn("null_blk: using direct completions.\n");
irqmode = NULL_IRQ_NONE;
}
#endif
if (queue_mode == NULL_Q_MQ && use_per_node_hctx) {
if (submit_queues < nr_online_nodes) {
pr_warn("null_blk: submit_queues param is set to %u.",
nr_online_nodes);
submit_queues = nr_online_nodes;
}
} else if (submit_queues > nr_cpu_ids)
submit_queues = nr_cpu_ids;
else if (!submit_queues)
submit_queues = 1;
mutex_init(&lock);
for_each_possible_cpu(i) {
struct completion_queue *cq = &per_cpu(completion_queues, i);
init_llist_head(&cq->list);
if (irqmode != NULL_IRQ_TIMER)
continue;
hrtimer_init(&cq->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
cq->timer.function = null_cmd_timer_expired;
}
null_major = register_blkdev(0, "nullb");
if (null_major < 0)
return null_major;
for (i = 0; i < nr_devices; i++) {
if (null_add_dev()) {
unregister_blkdev(null_major, "nullb");
return -EINVAL;
}
}
pr_info("null: module loaded\n");
return 0;
}
static void __exit null_exit(void)
{
struct nullb *nullb;
unregister_blkdev(null_major, "nullb");
mutex_lock(&lock);
while (!list_empty(&nullb_list)) {
nullb = list_entry(nullb_list.next, struct nullb, list);
null_del_dev(nullb);
}
mutex_unlock(&lock);
}
