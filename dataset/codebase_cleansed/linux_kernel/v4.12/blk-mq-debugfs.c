static int blk_flags_show(struct seq_file *m, const unsigned long flags,
const char *const *flag_name, int flag_name_count)
{
bool sep = false;
int i;
for (i = 0; i < sizeof(flags) * BITS_PER_BYTE; i++) {
if (!(flags & BIT(i)))
continue;
if (sep)
seq_puts(m, "|");
sep = true;
if (i < flag_name_count && flag_name[i])
seq_puts(m, flag_name[i]);
else
seq_printf(m, "%d", i);
}
return 0;
}
static int queue_state_show(void *data, struct seq_file *m)
{
struct request_queue *q = data;
blk_flags_show(m, q->queue_flags, blk_queue_flag_name,
ARRAY_SIZE(blk_queue_flag_name));
seq_puts(m, "\n");
return 0;
}
static ssize_t queue_state_write(void *data, const char __user *buf,
size_t count, loff_t *ppos)
{
struct request_queue *q = data;
char opbuf[16] = { }, *op;
if (blk_queue_dead(q))
return -ENOENT;
if (count >= sizeof(opbuf)) {
pr_err("%s: operation too long\n", __func__);
goto inval;
}
if (copy_from_user(opbuf, buf, count))
return -EFAULT;
op = strstrip(opbuf);
if (strcmp(op, "run") == 0) {
blk_mq_run_hw_queues(q, true);
} else if (strcmp(op, "start") == 0) {
blk_mq_start_stopped_hw_queues(q, true);
} else {
pr_err("%s: unsupported operation '%s'\n", __func__, op);
inval:
pr_err("%s: use either 'run' or 'start'\n", __func__);
return -EINVAL;
}
return count;
}
static void print_stat(struct seq_file *m, struct blk_rq_stat *stat)
{
if (stat->nr_samples) {
seq_printf(m, "samples=%d, mean=%lld, min=%llu, max=%llu",
stat->nr_samples, stat->mean, stat->min, stat->max);
} else {
seq_puts(m, "samples=0");
}
}
static int queue_poll_stat_show(void *data, struct seq_file *m)
{
struct request_queue *q = data;
int bucket;
for (bucket = 0; bucket < BLK_MQ_POLL_STATS_BKTS/2; bucket++) {
seq_printf(m, "read (%d Bytes): ", 1 << (9+bucket));
print_stat(m, &q->poll_stat[2*bucket]);
seq_puts(m, "\n");
seq_printf(m, "write (%d Bytes): ", 1 << (9+bucket));
print_stat(m, &q->poll_stat[2*bucket+1]);
seq_puts(m, "\n");
}
return 0;
}
static int hctx_state_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
blk_flags_show(m, hctx->state, hctx_state_name,
ARRAY_SIZE(hctx_state_name));
seq_puts(m, "\n");
return 0;
}
static int hctx_flags_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
const int alloc_policy = BLK_MQ_FLAG_TO_ALLOC_POLICY(hctx->flags);
seq_puts(m, "alloc_policy=");
if (alloc_policy < ARRAY_SIZE(alloc_policy_name) &&
alloc_policy_name[alloc_policy])
seq_puts(m, alloc_policy_name[alloc_policy]);
else
seq_printf(m, "%d", alloc_policy);
seq_puts(m, " ");
blk_flags_show(m,
hctx->flags ^ BLK_ALLOC_POLICY_TO_MQ_FLAG(alloc_policy),
hctx_flag_name, ARRAY_SIZE(hctx_flag_name));
seq_puts(m, "\n");
return 0;
}
int __blk_mq_debugfs_rq_show(struct seq_file *m, struct request *rq)
{
const struct blk_mq_ops *const mq_ops = rq->q->mq_ops;
const unsigned int op = rq->cmd_flags & REQ_OP_MASK;
seq_printf(m, "%p {.op=", rq);
if (op < ARRAY_SIZE(op_name) && op_name[op])
seq_printf(m, "%s", op_name[op]);
else
seq_printf(m, "%d", op);
seq_puts(m, ", .cmd_flags=");
blk_flags_show(m, rq->cmd_flags & ~REQ_OP_MASK, cmd_flag_name,
ARRAY_SIZE(cmd_flag_name));
seq_puts(m, ", .rq_flags=");
blk_flags_show(m, (__force unsigned int)rq->rq_flags, rqf_name,
ARRAY_SIZE(rqf_name));
seq_printf(m, ", .tag=%d, .internal_tag=%d", rq->tag,
rq->internal_tag);
if (mq_ops->show_rq)
mq_ops->show_rq(m, rq);
seq_puts(m, "}\n");
return 0;
}
int blk_mq_debugfs_rq_show(struct seq_file *m, void *v)
{
return __blk_mq_debugfs_rq_show(m, list_entry_rq(v));
}
static void *hctx_dispatch_start(struct seq_file *m, loff_t *pos)
__acquires(&hctx->lock
static void *hctx_dispatch_next(struct seq_file *m, void *v, loff_t *pos)
{
struct blk_mq_hw_ctx *hctx = m->private;
return seq_list_next(v, &hctx->dispatch, pos);
}
static void hctx_dispatch_stop(struct seq_file *m, void *v)
__releases(&hctx->lock
static int hctx_ctx_map_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
sbitmap_bitmap_show(&hctx->ctx_map, m);
return 0;
}
static void blk_mq_debugfs_tags_show(struct seq_file *m,
struct blk_mq_tags *tags)
{
seq_printf(m, "nr_tags=%u\n", tags->nr_tags);
seq_printf(m, "nr_reserved_tags=%u\n", tags->nr_reserved_tags);
seq_printf(m, "active_queues=%d\n",
atomic_read(&tags->active_queues));
seq_puts(m, "\nbitmap_tags:\n");
sbitmap_queue_show(&tags->bitmap_tags, m);
if (tags->nr_reserved_tags) {
seq_puts(m, "\nbreserved_tags:\n");
sbitmap_queue_show(&tags->breserved_tags, m);
}
}
static int hctx_tags_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
struct request_queue *q = hctx->queue;
int res;
res = mutex_lock_interruptible(&q->sysfs_lock);
if (res)
goto out;
if (hctx->tags)
blk_mq_debugfs_tags_show(m, hctx->tags);
mutex_unlock(&q->sysfs_lock);
out:
return res;
}
static int hctx_tags_bitmap_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
struct request_queue *q = hctx->queue;
int res;
res = mutex_lock_interruptible(&q->sysfs_lock);
if (res)
goto out;
if (hctx->tags)
sbitmap_bitmap_show(&hctx->tags->bitmap_tags.sb, m);
mutex_unlock(&q->sysfs_lock);
out:
return res;
}
static int hctx_sched_tags_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
struct request_queue *q = hctx->queue;
int res;
res = mutex_lock_interruptible(&q->sysfs_lock);
if (res)
goto out;
if (hctx->sched_tags)
blk_mq_debugfs_tags_show(m, hctx->sched_tags);
mutex_unlock(&q->sysfs_lock);
out:
return res;
}
static int hctx_sched_tags_bitmap_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
struct request_queue *q = hctx->queue;
int res;
res = mutex_lock_interruptible(&q->sysfs_lock);
if (res)
goto out;
if (hctx->sched_tags)
sbitmap_bitmap_show(&hctx->sched_tags->bitmap_tags.sb, m);
mutex_unlock(&q->sysfs_lock);
out:
return res;
}
static int hctx_io_poll_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
seq_printf(m, "considered=%lu\n", hctx->poll_considered);
seq_printf(m, "invoked=%lu\n", hctx->poll_invoked);
seq_printf(m, "success=%lu\n", hctx->poll_success);
return 0;
}
static ssize_t hctx_io_poll_write(void *data, const char __user *buf,
size_t count, loff_t *ppos)
{
struct blk_mq_hw_ctx *hctx = data;
hctx->poll_considered = hctx->poll_invoked = hctx->poll_success = 0;
return count;
}
static int hctx_dispatched_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
int i;
seq_printf(m, "%8u\t%lu\n", 0U, hctx->dispatched[0]);
for (i = 1; i < BLK_MQ_MAX_DISPATCH_ORDER - 1; i++) {
unsigned int d = 1U << (i - 1);
seq_printf(m, "%8u\t%lu\n", d, hctx->dispatched[i]);
}
seq_printf(m, "%8u+\t%lu\n", 1U << (i - 1), hctx->dispatched[i]);
return 0;
}
static ssize_t hctx_dispatched_write(void *data, const char __user *buf,
size_t count, loff_t *ppos)
{
struct blk_mq_hw_ctx *hctx = data;
int i;
for (i = 0; i < BLK_MQ_MAX_DISPATCH_ORDER; i++)
hctx->dispatched[i] = 0;
return count;
}
static int hctx_queued_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
seq_printf(m, "%lu\n", hctx->queued);
return 0;
}
static ssize_t hctx_queued_write(void *data, const char __user *buf,
size_t count, loff_t *ppos)
{
struct blk_mq_hw_ctx *hctx = data;
hctx->queued = 0;
return count;
}
static int hctx_run_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
seq_printf(m, "%lu\n", hctx->run);
return 0;
}
static ssize_t hctx_run_write(void *data, const char __user *buf, size_t count,
loff_t *ppos)
{
struct blk_mq_hw_ctx *hctx = data;
hctx->run = 0;
return count;
}
static int hctx_active_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
seq_printf(m, "%d\n", atomic_read(&hctx->nr_active));
return 0;
}
static void *ctx_rq_list_start(struct seq_file *m, loff_t *pos)
__acquires(&ctx->lock
static void *ctx_rq_list_next(struct seq_file *m, void *v, loff_t *pos)
{
struct blk_mq_ctx *ctx = m->private;
return seq_list_next(v, &ctx->rq_list, pos);
}
static void ctx_rq_list_stop(struct seq_file *m, void *v)
__releases(&ctx->lock
static int ctx_dispatched_show(void *data, struct seq_file *m)
{
struct blk_mq_ctx *ctx = data;
seq_printf(m, "%lu %lu\n", ctx->rq_dispatched[1], ctx->rq_dispatched[0]);
return 0;
}
static ssize_t ctx_dispatched_write(void *data, const char __user *buf,
size_t count, loff_t *ppos)
{
struct blk_mq_ctx *ctx = data;
ctx->rq_dispatched[0] = ctx->rq_dispatched[1] = 0;
return count;
}
static int ctx_merged_show(void *data, struct seq_file *m)
{
struct blk_mq_ctx *ctx = data;
seq_printf(m, "%lu\n", ctx->rq_merged);
return 0;
}
static ssize_t ctx_merged_write(void *data, const char __user *buf,
size_t count, loff_t *ppos)
{
struct blk_mq_ctx *ctx = data;
ctx->rq_merged = 0;
return count;
}
static int ctx_completed_show(void *data, struct seq_file *m)
{
struct blk_mq_ctx *ctx = data;
seq_printf(m, "%lu %lu\n", ctx->rq_completed[1], ctx->rq_completed[0]);
return 0;
}
static ssize_t ctx_completed_write(void *data, const char __user *buf,
size_t count, loff_t *ppos)
{
struct blk_mq_ctx *ctx = data;
ctx->rq_completed[0] = ctx->rq_completed[1] = 0;
return count;
}
static int blk_mq_debugfs_show(struct seq_file *m, void *v)
{
const struct blk_mq_debugfs_attr *attr = m->private;
void *data = d_inode(m->file->f_path.dentry->d_parent)->i_private;
return attr->show(data, m);
}
static ssize_t blk_mq_debugfs_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct seq_file *m = file->private_data;
const struct blk_mq_debugfs_attr *attr = m->private;
void *data = d_inode(file->f_path.dentry->d_parent)->i_private;
if (!attr->write)
return -EPERM;
return attr->write(data, buf, count, ppos);
}
static int blk_mq_debugfs_open(struct inode *inode, struct file *file)
{
const struct blk_mq_debugfs_attr *attr = inode->i_private;
void *data = d_inode(file->f_path.dentry->d_parent)->i_private;
struct seq_file *m;
int ret;
if (attr->seq_ops) {
ret = seq_open(file, attr->seq_ops);
if (!ret) {
m = file->private_data;
m->private = data;
}
return ret;
}
if (WARN_ON_ONCE(!attr->show))
return -EPERM;
return single_open(file, blk_mq_debugfs_show, inode->i_private);
}
static int blk_mq_debugfs_release(struct inode *inode, struct file *file)
{
const struct blk_mq_debugfs_attr *attr = inode->i_private;
if (attr->show)
return single_release(inode, file);
else
return seq_release(inode, file);
}
static bool debugfs_create_files(struct dentry *parent, void *data,
const struct blk_mq_debugfs_attr *attr)
{
d_inode(parent)->i_private = data;
for (; attr->name; attr++) {
if (!debugfs_create_file(attr->name, attr->mode, parent,
(void *)attr, &blk_mq_debugfs_fops))
return false;
}
return true;
}
int blk_mq_debugfs_register(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
int i;
if (!blk_debugfs_root)
return -ENOENT;
q->debugfs_dir = debugfs_create_dir(kobject_name(q->kobj.parent),
blk_debugfs_root);
if (!q->debugfs_dir)
return -ENOMEM;
if (!debugfs_create_files(q->debugfs_dir, q,
blk_mq_debugfs_queue_attrs))
goto err;
queue_for_each_hw_ctx(q, hctx, i) {
if (!hctx->debugfs_dir && blk_mq_debugfs_register_hctx(q, hctx))
goto err;
if (q->elevator && !hctx->sched_debugfs_dir &&
blk_mq_debugfs_register_sched_hctx(q, hctx))
goto err;
}
return 0;
err:
blk_mq_debugfs_unregister(q);
return -ENOMEM;
}
void blk_mq_debugfs_unregister(struct request_queue *q)
{
debugfs_remove_recursive(q->debugfs_dir);
q->sched_debugfs_dir = NULL;
q->debugfs_dir = NULL;
}
static int blk_mq_debugfs_register_ctx(struct blk_mq_hw_ctx *hctx,
struct blk_mq_ctx *ctx)
{
struct dentry *ctx_dir;
char name[20];
snprintf(name, sizeof(name), "cpu%u", ctx->cpu);
ctx_dir = debugfs_create_dir(name, hctx->debugfs_dir);
if (!ctx_dir)
return -ENOMEM;
if (!debugfs_create_files(ctx_dir, ctx, blk_mq_debugfs_ctx_attrs))
return -ENOMEM;
return 0;
}
int blk_mq_debugfs_register_hctx(struct request_queue *q,
struct blk_mq_hw_ctx *hctx)
{
struct blk_mq_ctx *ctx;
char name[20];
int i;
if (!q->debugfs_dir)
return -ENOENT;
snprintf(name, sizeof(name), "hctx%u", hctx->queue_num);
hctx->debugfs_dir = debugfs_create_dir(name, q->debugfs_dir);
if (!hctx->debugfs_dir)
return -ENOMEM;
if (!debugfs_create_files(hctx->debugfs_dir, hctx,
blk_mq_debugfs_hctx_attrs))
goto err;
hctx_for_each_ctx(hctx, ctx, i) {
if (blk_mq_debugfs_register_ctx(hctx, ctx))
goto err;
}
return 0;
err:
blk_mq_debugfs_unregister_hctx(hctx);
return -ENOMEM;
}
void blk_mq_debugfs_unregister_hctx(struct blk_mq_hw_ctx *hctx)
{
debugfs_remove_recursive(hctx->debugfs_dir);
hctx->sched_debugfs_dir = NULL;
hctx->debugfs_dir = NULL;
}
int blk_mq_debugfs_register_hctxs(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i) {
if (blk_mq_debugfs_register_hctx(q, hctx))
return -ENOMEM;
}
return 0;
}
void blk_mq_debugfs_unregister_hctxs(struct request_queue *q)
{
struct blk_mq_hw_ctx *hctx;
int i;
queue_for_each_hw_ctx(q, hctx, i)
blk_mq_debugfs_unregister_hctx(hctx);
}
int blk_mq_debugfs_register_sched(struct request_queue *q)
{
struct elevator_type *e = q->elevator->type;
if (!q->debugfs_dir)
return -ENOENT;
if (!e->queue_debugfs_attrs)
return 0;
q->sched_debugfs_dir = debugfs_create_dir("sched", q->debugfs_dir);
if (!q->sched_debugfs_dir)
return -ENOMEM;
if (!debugfs_create_files(q->sched_debugfs_dir, q,
e->queue_debugfs_attrs))
goto err;
return 0;
err:
blk_mq_debugfs_unregister_sched(q);
return -ENOMEM;
}
void blk_mq_debugfs_unregister_sched(struct request_queue *q)
{
debugfs_remove_recursive(q->sched_debugfs_dir);
q->sched_debugfs_dir = NULL;
}
int blk_mq_debugfs_register_sched_hctx(struct request_queue *q,
struct blk_mq_hw_ctx *hctx)
{
struct elevator_type *e = q->elevator->type;
if (!hctx->debugfs_dir)
return -ENOENT;
if (!e->hctx_debugfs_attrs)
return 0;
hctx->sched_debugfs_dir = debugfs_create_dir("sched",
hctx->debugfs_dir);
if (!hctx->sched_debugfs_dir)
return -ENOMEM;
if (!debugfs_create_files(hctx->sched_debugfs_dir, hctx,
e->hctx_debugfs_attrs))
return -ENOMEM;
return 0;
}
void blk_mq_debugfs_unregister_sched_hctx(struct blk_mq_hw_ctx *hctx)
{
debugfs_remove_recursive(hctx->sched_debugfs_dir);
hctx->sched_debugfs_dir = NULL;
}
