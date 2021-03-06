static void trace_note(struct blk_trace *bt, pid_t pid, int action,
const void *data, size_t len)
{
struct blk_io_trace *t;
struct ring_buffer_event *event = NULL;
struct ring_buffer *buffer = NULL;
int pc = 0;
int cpu = smp_processor_id();
bool blk_tracer = blk_tracer_enabled;
if (blk_tracer) {
buffer = blk_tr->trace_buffer.buffer;
pc = preempt_count();
event = trace_buffer_lock_reserve(buffer, TRACE_BLK,
sizeof(*t) + len,
0, pc);
if (!event)
return;
t = ring_buffer_event_data(event);
goto record_it;
}
if (!bt->rchan)
return;
t = relay_reserve(bt->rchan, sizeof(*t) + len);
if (t) {
t->magic = BLK_IO_TRACE_MAGIC | BLK_IO_TRACE_VERSION;
t->time = ktime_to_ns(ktime_get());
record_it:
t->device = bt->dev;
t->action = action;
t->pid = pid;
t->cpu = cpu;
t->pdu_len = len;
memcpy((void *) t + sizeof(*t), data, len);
if (blk_tracer)
trace_buffer_unlock_commit(blk_tr, buffer, event, 0, pc);
}
}
static void trace_note_tsk(struct task_struct *tsk)
{
unsigned long flags;
struct blk_trace *bt;
tsk->btrace_seq = blktrace_seq;
spin_lock_irqsave(&running_trace_lock, flags);
list_for_each_entry(bt, &running_trace_list, running_list) {
trace_note(bt, tsk->pid, BLK_TN_PROCESS, tsk->comm,
sizeof(tsk->comm));
}
spin_unlock_irqrestore(&running_trace_lock, flags);
}
static void trace_note_time(struct blk_trace *bt)
{
struct timespec64 now;
unsigned long flags;
u32 words[2];
ktime_get_real_ts64(&now);
words[0] = (u32)now.tv_sec;
words[1] = now.tv_nsec;
local_irq_save(flags);
trace_note(bt, 0, BLK_TN_TIMESTAMP, words, sizeof(words));
local_irq_restore(flags);
}
void __trace_note_message(struct blk_trace *bt, const char *fmt, ...)
{
int n;
va_list args;
unsigned long flags;
char *buf;
if (unlikely(bt->trace_state != Blktrace_running &&
!blk_tracer_enabled))
return;
if (!(bt->act_mask & BLK_TC_NOTIFY))
return;
local_irq_save(flags);
buf = this_cpu_ptr(bt->msg_data);
va_start(args, fmt);
n = vscnprintf(buf, BLK_TN_MAX_MSG, fmt, args);
va_end(args);
trace_note(bt, 0, BLK_TN_MESSAGE, buf, n);
local_irq_restore(flags);
}
static int act_log_check(struct blk_trace *bt, u32 what, sector_t sector,
pid_t pid)
{
if (((bt->act_mask << BLK_TC_SHIFT) & what) == 0)
return 1;
if (sector && (sector < bt->start_lba || sector > bt->end_lba))
return 1;
if (bt->pid && pid != bt->pid)
return 1;
return 0;
}
static void __blk_add_trace(struct blk_trace *bt, sector_t sector, int bytes,
int op, int op_flags, u32 what, int error, int pdu_len,
void *pdu_data)
{
struct task_struct *tsk = current;
struct ring_buffer_event *event = NULL;
struct ring_buffer *buffer = NULL;
struct blk_io_trace *t;
unsigned long flags = 0;
unsigned long *sequence;
pid_t pid;
int cpu, pc = 0;
bool blk_tracer = blk_tracer_enabled;
if (unlikely(bt->trace_state != Blktrace_running && !blk_tracer))
return;
what |= ddir_act[op_is_write(op) ? WRITE : READ];
what |= MASK_TC_BIT(op_flags, SYNC);
what |= MASK_TC_BIT(op_flags, RAHEAD);
what |= MASK_TC_BIT(op_flags, META);
what |= MASK_TC_BIT(op_flags, PREFLUSH);
what |= MASK_TC_BIT(op_flags, FUA);
if (op == REQ_OP_DISCARD || op == REQ_OP_SECURE_ERASE)
what |= BLK_TC_ACT(BLK_TC_DISCARD);
if (op == REQ_OP_FLUSH)
what |= BLK_TC_ACT(BLK_TC_FLUSH);
pid = tsk->pid;
if (act_log_check(bt, what, sector, pid))
return;
cpu = raw_smp_processor_id();
if (blk_tracer) {
tracing_record_cmdline(current);
buffer = blk_tr->trace_buffer.buffer;
pc = preempt_count();
event = trace_buffer_lock_reserve(buffer, TRACE_BLK,
sizeof(*t) + pdu_len,
0, pc);
if (!event)
return;
t = ring_buffer_event_data(event);
goto record_it;
}
if (unlikely(tsk->btrace_seq != blktrace_seq))
trace_note_tsk(tsk);
local_irq_save(flags);
t = relay_reserve(bt->rchan, sizeof(*t) + pdu_len);
if (t) {
sequence = per_cpu_ptr(bt->sequence, cpu);
t->magic = BLK_IO_TRACE_MAGIC | BLK_IO_TRACE_VERSION;
t->sequence = ++(*sequence);
t->time = ktime_to_ns(ktime_get());
record_it:
t->cpu = cpu;
t->pid = pid;
t->sector = sector;
t->bytes = bytes;
t->action = what;
t->device = bt->dev;
t->error = error;
t->pdu_len = pdu_len;
if (pdu_len)
memcpy((void *) t + sizeof(*t), pdu_data, pdu_len);
if (blk_tracer) {
trace_buffer_unlock_commit(blk_tr, buffer, event, 0, pc);
return;
}
}
local_irq_restore(flags);
}
static void blk_trace_free(struct blk_trace *bt)
{
debugfs_remove(bt->msg_file);
debugfs_remove(bt->dropped_file);
relay_close(bt->rchan);
debugfs_remove(bt->dir);
free_percpu(bt->sequence);
free_percpu(bt->msg_data);
kfree(bt);
}
static void blk_trace_cleanup(struct blk_trace *bt)
{
blk_trace_free(bt);
if (atomic_dec_and_test(&blk_probes_ref))
blk_unregister_tracepoints();
}
int blk_trace_remove(struct request_queue *q)
{
struct blk_trace *bt;
bt = xchg(&q->blk_trace, NULL);
if (!bt)
return -EINVAL;
if (bt->trace_state != Blktrace_running)
blk_trace_cleanup(bt);
return 0;
}
static ssize_t blk_dropped_read(struct file *filp, char __user *buffer,
size_t count, loff_t *ppos)
{
struct blk_trace *bt = filp->private_data;
char buf[16];
snprintf(buf, sizeof(buf), "%u\n", atomic_read(&bt->dropped));
return simple_read_from_buffer(buffer, count, ppos, buf, strlen(buf));
}
static ssize_t blk_msg_write(struct file *filp, const char __user *buffer,
size_t count, loff_t *ppos)
{
char *msg;
struct blk_trace *bt;
if (count >= BLK_TN_MAX_MSG)
return -EINVAL;
msg = memdup_user_nul(buffer, count);
if (IS_ERR(msg))
return PTR_ERR(msg);
bt = filp->private_data;
__trace_note_message(bt, "%s", msg);
kfree(msg);
return count;
}
static int blk_subbuf_start_callback(struct rchan_buf *buf, void *subbuf,
void *prev_subbuf, size_t prev_padding)
{
struct blk_trace *bt;
if (!relay_buf_full(buf))
return 1;
bt = buf->chan->private_data;
atomic_inc(&bt->dropped);
return 0;
}
static int blk_remove_buf_file_callback(struct dentry *dentry)
{
debugfs_remove(dentry);
return 0;
}
static struct dentry *blk_create_buf_file_callback(const char *filename,
struct dentry *parent,
umode_t mode,
struct rchan_buf *buf,
int *is_global)
{
return debugfs_create_file(filename, mode, parent, buf,
&relay_file_operations);
}
static void blk_trace_setup_lba(struct blk_trace *bt,
struct block_device *bdev)
{
struct hd_struct *part = NULL;
if (bdev)
part = bdev->bd_part;
if (part) {
bt->start_lba = part->start_sect;
bt->end_lba = part->start_sect + part->nr_sects;
} else {
bt->start_lba = 0;
bt->end_lba = -1ULL;
}
}
static int do_blk_trace_setup(struct request_queue *q, char *name, dev_t dev,
struct block_device *bdev,
struct blk_user_trace_setup *buts)
{
struct blk_trace *bt = NULL;
struct dentry *dir = NULL;
int ret;
if (!buts->buf_size || !buts->buf_nr)
return -EINVAL;
strncpy(buts->name, name, BLKTRACE_BDEV_SIZE);
buts->name[BLKTRACE_BDEV_SIZE - 1] = '\0';
strreplace(buts->name, '/', '_');
bt = kzalloc(sizeof(*bt), GFP_KERNEL);
if (!bt)
return -ENOMEM;
ret = -ENOMEM;
bt->sequence = alloc_percpu(unsigned long);
if (!bt->sequence)
goto err;
bt->msg_data = __alloc_percpu(BLK_TN_MAX_MSG, __alignof__(char));
if (!bt->msg_data)
goto err;
ret = -ENOENT;
if (!blk_debugfs_root)
goto err;
dir = debugfs_lookup(buts->name, blk_debugfs_root);
if (!dir)
bt->dir = dir = debugfs_create_dir(buts->name, blk_debugfs_root);
if (!dir)
goto err;
bt->dev = dev;
atomic_set(&bt->dropped, 0);
INIT_LIST_HEAD(&bt->running_list);
ret = -EIO;
bt->dropped_file = debugfs_create_file("dropped", 0444, dir, bt,
&blk_dropped_fops);
if (!bt->dropped_file)
goto err;
bt->msg_file = debugfs_create_file("msg", 0222, dir, bt, &blk_msg_fops);
if (!bt->msg_file)
goto err;
bt->rchan = relay_open("trace", dir, buts->buf_size,
buts->buf_nr, &blk_relay_callbacks, bt);
if (!bt->rchan)
goto err;
bt->act_mask = buts->act_mask;
if (!bt->act_mask)
bt->act_mask = (u16) -1;
blk_trace_setup_lba(bt, bdev);
if (buts->start_lba)
bt->start_lba = buts->start_lba;
if (buts->end_lba)
bt->end_lba = buts->end_lba;
bt->pid = buts->pid;
bt->trace_state = Blktrace_setup;
ret = -EBUSY;
if (cmpxchg(&q->blk_trace, NULL, bt))
goto err;
if (atomic_inc_return(&blk_probes_ref) == 1)
blk_register_tracepoints();
ret = 0;
err:
if (dir && !bt->dir)
dput(dir);
if (ret)
blk_trace_free(bt);
return ret;
}
int blk_trace_setup(struct request_queue *q, char *name, dev_t dev,
struct block_device *bdev,
char __user *arg)
{
struct blk_user_trace_setup buts;
int ret;
ret = copy_from_user(&buts, arg, sizeof(buts));
if (ret)
return -EFAULT;
ret = do_blk_trace_setup(q, name, dev, bdev, &buts);
if (ret)
return ret;
if (copy_to_user(arg, &buts, sizeof(buts))) {
blk_trace_remove(q);
return -EFAULT;
}
return 0;
}
static int compat_blk_trace_setup(struct request_queue *q, char *name,
dev_t dev, struct block_device *bdev,
char __user *arg)
{
struct blk_user_trace_setup buts;
struct compat_blk_user_trace_setup cbuts;
int ret;
if (copy_from_user(&cbuts, arg, sizeof(cbuts)))
return -EFAULT;
buts = (struct blk_user_trace_setup) {
.act_mask = cbuts.act_mask,
.buf_size = cbuts.buf_size,
.buf_nr = cbuts.buf_nr,
.start_lba = cbuts.start_lba,
.end_lba = cbuts.end_lba,
.pid = cbuts.pid,
};
ret = do_blk_trace_setup(q, name, dev, bdev, &buts);
if (ret)
return ret;
if (copy_to_user(arg, &buts.name, ARRAY_SIZE(buts.name))) {
blk_trace_remove(q);
return -EFAULT;
}
return 0;
}
int blk_trace_startstop(struct request_queue *q, int start)
{
int ret;
struct blk_trace *bt = q->blk_trace;
if (bt == NULL)
return -EINVAL;
ret = -EINVAL;
if (start) {
if (bt->trace_state == Blktrace_setup ||
bt->trace_state == Blktrace_stopped) {
blktrace_seq++;
smp_mb();
bt->trace_state = Blktrace_running;
spin_lock_irq(&running_trace_lock);
list_add(&bt->running_list, &running_trace_list);
spin_unlock_irq(&running_trace_lock);
trace_note_time(bt);
ret = 0;
}
} else {
if (bt->trace_state == Blktrace_running) {
bt->trace_state = Blktrace_stopped;
spin_lock_irq(&running_trace_lock);
list_del_init(&bt->running_list);
spin_unlock_irq(&running_trace_lock);
relay_flush(bt->rchan);
ret = 0;
}
}
return ret;
}
int blk_trace_ioctl(struct block_device *bdev, unsigned cmd, char __user *arg)
{
struct request_queue *q;
int ret, start = 0;
char b[BDEVNAME_SIZE];
q = bdev_get_queue(bdev);
if (!q)
return -ENXIO;
mutex_lock(&bdev->bd_mutex);
switch (cmd) {
case BLKTRACESETUP:
bdevname(bdev, b);
ret = blk_trace_setup(q, b, bdev->bd_dev, bdev, arg);
break;
#if defined(CONFIG_COMPAT) && defined(CONFIG_X86_64)
case BLKTRACESETUP32:
bdevname(bdev, b);
ret = compat_blk_trace_setup(q, b, bdev->bd_dev, bdev, arg);
break;
#endif
case BLKTRACESTART:
start = 1;
case BLKTRACESTOP:
ret = blk_trace_startstop(q, start);
break;
case BLKTRACETEARDOWN:
ret = blk_trace_remove(q);
break;
default:
ret = -ENOTTY;
break;
}
mutex_unlock(&bdev->bd_mutex);
return ret;
}
void blk_trace_shutdown(struct request_queue *q)
{
if (q->blk_trace) {
blk_trace_startstop(q, 0);
blk_trace_remove(q);
}
}
static void blk_add_trace_rq(struct request_queue *q, struct request *rq,
unsigned int nr_bytes, u32 what)
{
struct blk_trace *bt = q->blk_trace;
if (likely(!bt))
return;
if (blk_rq_is_passthrough(rq))
what |= BLK_TC_ACT(BLK_TC_PC);
else
what |= BLK_TC_ACT(BLK_TC_FS);
__blk_add_trace(bt, blk_rq_trace_sector(rq), nr_bytes, req_op(rq),
rq->cmd_flags, what, rq->errors, 0, NULL);
}
static void blk_add_trace_rq_abort(void *ignore,
struct request_queue *q, struct request *rq)
{
blk_add_trace_rq(q, rq, blk_rq_bytes(rq), BLK_TA_ABORT);
}
static void blk_add_trace_rq_insert(void *ignore,
struct request_queue *q, struct request *rq)
{
blk_add_trace_rq(q, rq, blk_rq_bytes(rq), BLK_TA_INSERT);
}
static void blk_add_trace_rq_issue(void *ignore,
struct request_queue *q, struct request *rq)
{
blk_add_trace_rq(q, rq, blk_rq_bytes(rq), BLK_TA_ISSUE);
}
static void blk_add_trace_rq_requeue(void *ignore,
struct request_queue *q,
struct request *rq)
{
blk_add_trace_rq(q, rq, blk_rq_bytes(rq), BLK_TA_REQUEUE);
}
static void blk_add_trace_rq_complete(void *ignore,
struct request_queue *q,
struct request *rq,
unsigned int nr_bytes)
{
blk_add_trace_rq(q, rq, nr_bytes, BLK_TA_COMPLETE);
}
static void blk_add_trace_bio(struct request_queue *q, struct bio *bio,
u32 what, int error)
{
struct blk_trace *bt = q->blk_trace;
if (likely(!bt))
return;
__blk_add_trace(bt, bio->bi_iter.bi_sector, bio->bi_iter.bi_size,
bio_op(bio), bio->bi_opf, what, error, 0, NULL);
}
static void blk_add_trace_bio_bounce(void *ignore,
struct request_queue *q, struct bio *bio)
{
blk_add_trace_bio(q, bio, BLK_TA_BOUNCE, 0);
}
static void blk_add_trace_bio_complete(void *ignore,
struct request_queue *q, struct bio *bio,
int error)
{
blk_add_trace_bio(q, bio, BLK_TA_COMPLETE, error);
}
static void blk_add_trace_bio_backmerge(void *ignore,
struct request_queue *q,
struct request *rq,
struct bio *bio)
{
blk_add_trace_bio(q, bio, BLK_TA_BACKMERGE, 0);
}
static void blk_add_trace_bio_frontmerge(void *ignore,
struct request_queue *q,
struct request *rq,
struct bio *bio)
{
blk_add_trace_bio(q, bio, BLK_TA_FRONTMERGE, 0);
}
static void blk_add_trace_bio_queue(void *ignore,
struct request_queue *q, struct bio *bio)
{
blk_add_trace_bio(q, bio, BLK_TA_QUEUE, 0);
}
static void blk_add_trace_getrq(void *ignore,
struct request_queue *q,
struct bio *bio, int rw)
{
if (bio)
blk_add_trace_bio(q, bio, BLK_TA_GETRQ, 0);
else {
struct blk_trace *bt = q->blk_trace;
if (bt)
__blk_add_trace(bt, 0, 0, rw, 0, BLK_TA_GETRQ, 0, 0,
NULL);
}
}
static void blk_add_trace_sleeprq(void *ignore,
struct request_queue *q,
struct bio *bio, int rw)
{
if (bio)
blk_add_trace_bio(q, bio, BLK_TA_SLEEPRQ, 0);
else {
struct blk_trace *bt = q->blk_trace;
if (bt)
__blk_add_trace(bt, 0, 0, rw, 0, BLK_TA_SLEEPRQ,
0, 0, NULL);
}
}
static void blk_add_trace_plug(void *ignore, struct request_queue *q)
{
struct blk_trace *bt = q->blk_trace;
if (bt)
__blk_add_trace(bt, 0, 0, 0, 0, BLK_TA_PLUG, 0, 0, NULL);
}
static void blk_add_trace_unplug(void *ignore, struct request_queue *q,
unsigned int depth, bool explicit)
{
struct blk_trace *bt = q->blk_trace;
if (bt) {
__be64 rpdu = cpu_to_be64(depth);
u32 what;
if (explicit)
what = BLK_TA_UNPLUG_IO;
else
what = BLK_TA_UNPLUG_TIMER;
__blk_add_trace(bt, 0, 0, 0, 0, what, 0, sizeof(rpdu), &rpdu);
}
}
static void blk_add_trace_split(void *ignore,
struct request_queue *q, struct bio *bio,
unsigned int pdu)
{
struct blk_trace *bt = q->blk_trace;
if (bt) {
__be64 rpdu = cpu_to_be64(pdu);
__blk_add_trace(bt, bio->bi_iter.bi_sector,
bio->bi_iter.bi_size, bio_op(bio), bio->bi_opf,
BLK_TA_SPLIT, bio->bi_error, sizeof(rpdu),
&rpdu);
}
}
static void blk_add_trace_bio_remap(void *ignore,
struct request_queue *q, struct bio *bio,
dev_t dev, sector_t from)
{
struct blk_trace *bt = q->blk_trace;
struct blk_io_trace_remap r;
if (likely(!bt))
return;
r.device_from = cpu_to_be32(dev);
r.device_to = cpu_to_be32(bio->bi_bdev->bd_dev);
r.sector_from = cpu_to_be64(from);
__blk_add_trace(bt, bio->bi_iter.bi_sector, bio->bi_iter.bi_size,
bio_op(bio), bio->bi_opf, BLK_TA_REMAP, bio->bi_error,
sizeof(r), &r);
}
static void blk_add_trace_rq_remap(void *ignore,
struct request_queue *q,
struct request *rq, dev_t dev,
sector_t from)
{
struct blk_trace *bt = q->blk_trace;
struct blk_io_trace_remap r;
if (likely(!bt))
return;
r.device_from = cpu_to_be32(dev);
r.device_to = cpu_to_be32(disk_devt(rq->rq_disk));
r.sector_from = cpu_to_be64(from);
__blk_add_trace(bt, blk_rq_pos(rq), blk_rq_bytes(rq),
rq_data_dir(rq), 0, BLK_TA_REMAP, !!rq->errors,
sizeof(r), &r);
}
void blk_add_driver_data(struct request_queue *q,
struct request *rq,
void *data, size_t len)
{
struct blk_trace *bt = q->blk_trace;
if (likely(!bt))
return;
__blk_add_trace(bt, blk_rq_trace_sector(rq), blk_rq_bytes(rq), 0, 0,
BLK_TA_DRV_DATA, rq->errors, len, data);
}
static void blk_register_tracepoints(void)
{
int ret;
ret = register_trace_block_rq_abort(blk_add_trace_rq_abort, NULL);
WARN_ON(ret);
ret = register_trace_block_rq_insert(blk_add_trace_rq_insert, NULL);
WARN_ON(ret);
ret = register_trace_block_rq_issue(blk_add_trace_rq_issue, NULL);
WARN_ON(ret);
ret = register_trace_block_rq_requeue(blk_add_trace_rq_requeue, NULL);
WARN_ON(ret);
ret = register_trace_block_rq_complete(blk_add_trace_rq_complete, NULL);
WARN_ON(ret);
ret = register_trace_block_bio_bounce(blk_add_trace_bio_bounce, NULL);
WARN_ON(ret);
ret = register_trace_block_bio_complete(blk_add_trace_bio_complete, NULL);
WARN_ON(ret);
ret = register_trace_block_bio_backmerge(blk_add_trace_bio_backmerge, NULL);
WARN_ON(ret);
ret = register_trace_block_bio_frontmerge(blk_add_trace_bio_frontmerge, NULL);
WARN_ON(ret);
ret = register_trace_block_bio_queue(blk_add_trace_bio_queue, NULL);
WARN_ON(ret);
ret = register_trace_block_getrq(blk_add_trace_getrq, NULL);
WARN_ON(ret);
ret = register_trace_block_sleeprq(blk_add_trace_sleeprq, NULL);
WARN_ON(ret);
ret = register_trace_block_plug(blk_add_trace_plug, NULL);
WARN_ON(ret);
ret = register_trace_block_unplug(blk_add_trace_unplug, NULL);
WARN_ON(ret);
ret = register_trace_block_split(blk_add_trace_split, NULL);
WARN_ON(ret);
ret = register_trace_block_bio_remap(blk_add_trace_bio_remap, NULL);
WARN_ON(ret);
ret = register_trace_block_rq_remap(blk_add_trace_rq_remap, NULL);
WARN_ON(ret);
}
static void blk_unregister_tracepoints(void)
{
unregister_trace_block_rq_remap(blk_add_trace_rq_remap, NULL);
unregister_trace_block_bio_remap(blk_add_trace_bio_remap, NULL);
unregister_trace_block_split(blk_add_trace_split, NULL);
unregister_trace_block_unplug(blk_add_trace_unplug, NULL);
unregister_trace_block_plug(blk_add_trace_plug, NULL);
unregister_trace_block_sleeprq(blk_add_trace_sleeprq, NULL);
unregister_trace_block_getrq(blk_add_trace_getrq, NULL);
unregister_trace_block_bio_queue(blk_add_trace_bio_queue, NULL);
unregister_trace_block_bio_frontmerge(blk_add_trace_bio_frontmerge, NULL);
unregister_trace_block_bio_backmerge(blk_add_trace_bio_backmerge, NULL);
unregister_trace_block_bio_complete(blk_add_trace_bio_complete, NULL);
unregister_trace_block_bio_bounce(blk_add_trace_bio_bounce, NULL);
unregister_trace_block_rq_complete(blk_add_trace_rq_complete, NULL);
unregister_trace_block_rq_requeue(blk_add_trace_rq_requeue, NULL);
unregister_trace_block_rq_issue(blk_add_trace_rq_issue, NULL);
unregister_trace_block_rq_insert(blk_add_trace_rq_insert, NULL);
unregister_trace_block_rq_abort(blk_add_trace_rq_abort, NULL);
tracepoint_synchronize_unregister();
}
static void fill_rwbs(char *rwbs, const struct blk_io_trace *t)
{
int i = 0;
int tc = t->action >> BLK_TC_SHIFT;
if (t->action == BLK_TN_MESSAGE) {
rwbs[i++] = 'N';
goto out;
}
if (tc & BLK_TC_FLUSH)
rwbs[i++] = 'F';
if (tc & BLK_TC_DISCARD)
rwbs[i++] = 'D';
else if (tc & BLK_TC_WRITE)
rwbs[i++] = 'W';
else if (t->bytes)
rwbs[i++] = 'R';
else
rwbs[i++] = 'N';
if (tc & BLK_TC_FUA)
rwbs[i++] = 'F';
if (tc & BLK_TC_AHEAD)
rwbs[i++] = 'A';
if (tc & BLK_TC_SYNC)
rwbs[i++] = 'S';
if (tc & BLK_TC_META)
rwbs[i++] = 'M';
out:
rwbs[i] = '\0';
}
static inline
const struct blk_io_trace *te_blk_io_trace(const struct trace_entry *ent)
{
return (const struct blk_io_trace *)ent;
}
static inline const void *pdu_start(const struct trace_entry *ent)
{
return te_blk_io_trace(ent) + 1;
}
static inline u32 t_action(const struct trace_entry *ent)
{
return te_blk_io_trace(ent)->action;
}
static inline u32 t_bytes(const struct trace_entry *ent)
{
return te_blk_io_trace(ent)->bytes;
}
static inline u32 t_sec(const struct trace_entry *ent)
{
return te_blk_io_trace(ent)->bytes >> 9;
}
static inline unsigned long long t_sector(const struct trace_entry *ent)
{
return te_blk_io_trace(ent)->sector;
}
static inline __u16 t_error(const struct trace_entry *ent)
{
return te_blk_io_trace(ent)->error;
}
static __u64 get_pdu_int(const struct trace_entry *ent)
{
const __u64 *val = pdu_start(ent);
return be64_to_cpu(*val);
}
static void get_pdu_remap(const struct trace_entry *ent,
struct blk_io_trace_remap *r)
{
const struct blk_io_trace_remap *__r = pdu_start(ent);
__u64 sector_from = __r->sector_from;
r->device_from = be32_to_cpu(__r->device_from);
r->device_to = be32_to_cpu(__r->device_to);
r->sector_from = be64_to_cpu(sector_from);
}
static void blk_log_action_classic(struct trace_iterator *iter, const char *act)
{
char rwbs[RWBS_LEN];
unsigned long long ts = iter->ts;
unsigned long nsec_rem = do_div(ts, NSEC_PER_SEC);
unsigned secs = (unsigned long)ts;
const struct blk_io_trace *t = te_blk_io_trace(iter->ent);
fill_rwbs(rwbs, t);
trace_seq_printf(&iter->seq,
"%3d,%-3d %2d %5d.%09lu %5u %2s %3s ",
MAJOR(t->device), MINOR(t->device), iter->cpu,
secs, nsec_rem, iter->ent->pid, act, rwbs);
}
static void blk_log_action(struct trace_iterator *iter, const char *act)
{
char rwbs[RWBS_LEN];
const struct blk_io_trace *t = te_blk_io_trace(iter->ent);
fill_rwbs(rwbs, t);
trace_seq_printf(&iter->seq, "%3d,%-3d %2s %3s ",
MAJOR(t->device), MINOR(t->device), act, rwbs);
}
static void blk_log_dump_pdu(struct trace_seq *s, const struct trace_entry *ent)
{
const unsigned char *pdu_buf;
int pdu_len;
int i, end;
pdu_buf = pdu_start(ent);
pdu_len = te_blk_io_trace(ent)->pdu_len;
if (!pdu_len)
return;
for (end = pdu_len - 1; end >= 0; end--)
if (pdu_buf[end])
break;
end++;
trace_seq_putc(s, '(');
for (i = 0; i < pdu_len; i++) {
trace_seq_printf(s, "%s%02x",
i == 0 ? "" : " ", pdu_buf[i]);
if (i == end && end != pdu_len - 1) {
trace_seq_puts(s, " ..) ");
return;
}
}
trace_seq_puts(s, ") ");
}
static void blk_log_generic(struct trace_seq *s, const struct trace_entry *ent)
{
char cmd[TASK_COMM_LEN];
trace_find_cmdline(ent->pid, cmd);
if (t_action(ent) & BLK_TC_ACT(BLK_TC_PC)) {
trace_seq_printf(s, "%u ", t_bytes(ent));
blk_log_dump_pdu(s, ent);
trace_seq_printf(s, "[%s]\n", cmd);
} else {
if (t_sec(ent))
trace_seq_printf(s, "%llu + %u [%s]\n",
t_sector(ent), t_sec(ent), cmd);
else
trace_seq_printf(s, "[%s]\n", cmd);
}
}
static void blk_log_with_error(struct trace_seq *s,
const struct trace_entry *ent)
{
if (t_action(ent) & BLK_TC_ACT(BLK_TC_PC)) {
blk_log_dump_pdu(s, ent);
trace_seq_printf(s, "[%d]\n", t_error(ent));
} else {
if (t_sec(ent))
trace_seq_printf(s, "%llu + %u [%d]\n",
t_sector(ent),
t_sec(ent), t_error(ent));
else
trace_seq_printf(s, "%llu [%d]\n",
t_sector(ent), t_error(ent));
}
}
static void blk_log_remap(struct trace_seq *s, const struct trace_entry *ent)
{
struct blk_io_trace_remap r = { .device_from = 0, };
get_pdu_remap(ent, &r);
trace_seq_printf(s, "%llu + %u <- (%d,%d) %llu\n",
t_sector(ent), t_sec(ent),
MAJOR(r.device_from), MINOR(r.device_from),
(unsigned long long)r.sector_from);
}
static void blk_log_plug(struct trace_seq *s, const struct trace_entry *ent)
{
char cmd[TASK_COMM_LEN];
trace_find_cmdline(ent->pid, cmd);
trace_seq_printf(s, "[%s]\n", cmd);
}
static void blk_log_unplug(struct trace_seq *s, const struct trace_entry *ent)
{
char cmd[TASK_COMM_LEN];
trace_find_cmdline(ent->pid, cmd);
trace_seq_printf(s, "[%s] %llu\n", cmd, get_pdu_int(ent));
}
static void blk_log_split(struct trace_seq *s, const struct trace_entry *ent)
{
char cmd[TASK_COMM_LEN];
trace_find_cmdline(ent->pid, cmd);
trace_seq_printf(s, "%llu / %llu [%s]\n", t_sector(ent),
get_pdu_int(ent), cmd);
}
static void blk_log_msg(struct trace_seq *s, const struct trace_entry *ent)
{
const struct blk_io_trace *t = te_blk_io_trace(ent);
trace_seq_putmem(s, t + 1, t->pdu_len);
trace_seq_putc(s, '\n');
}
static void blk_tracer_print_header(struct seq_file *m)
{
if (!(blk_tracer_flags.val & TRACE_BLK_OPT_CLASSIC))
return;
seq_puts(m, "# DEV CPU TIMESTAMP PID ACT FLG\n"
"# | | | | | |\n");
}
static void blk_tracer_start(struct trace_array *tr)
{
blk_tracer_enabled = true;
}
static int blk_tracer_init(struct trace_array *tr)
{
blk_tr = tr;
blk_tracer_start(tr);
return 0;
}
static void blk_tracer_stop(struct trace_array *tr)
{
blk_tracer_enabled = false;
}
static void blk_tracer_reset(struct trace_array *tr)
{
blk_tracer_stop(tr);
}
static enum print_line_t print_one_line(struct trace_iterator *iter,
bool classic)
{
struct trace_array *tr = iter->tr;
struct trace_seq *s = &iter->seq;
const struct blk_io_trace *t;
u16 what;
bool long_act;
blk_log_action_t *log_action;
t = te_blk_io_trace(iter->ent);
what = t->action & ((1 << BLK_TC_SHIFT) - 1);
long_act = !!(tr->trace_flags & TRACE_ITER_VERBOSE);
log_action = classic ? &blk_log_action_classic : &blk_log_action;
if (t->action == BLK_TN_MESSAGE) {
log_action(iter, long_act ? "message" : "m");
blk_log_msg(s, iter->ent);
return trace_handle_return(s);
}
if (unlikely(what == 0 || what >= ARRAY_SIZE(what2act)))
trace_seq_printf(s, "Unknown action %x\n", what);
else {
log_action(iter, what2act[what].act[long_act]);
what2act[what].print(s, iter->ent);
}
return trace_handle_return(s);
}
static enum print_line_t blk_trace_event_print(struct trace_iterator *iter,
int flags, struct trace_event *event)
{
return print_one_line(iter, false);
}
static void blk_trace_synthesize_old_trace(struct trace_iterator *iter)
{
struct trace_seq *s = &iter->seq;
struct blk_io_trace *t = (struct blk_io_trace *)iter->ent;
const int offset = offsetof(struct blk_io_trace, sector);
struct blk_io_trace old = {
.magic = BLK_IO_TRACE_MAGIC | BLK_IO_TRACE_VERSION,
.time = iter->ts,
};
trace_seq_putmem(s, &old, offset);
trace_seq_putmem(s, &t->sector,
sizeof(old) - offset + t->pdu_len);
}
static enum print_line_t
blk_trace_event_print_binary(struct trace_iterator *iter, int flags,
struct trace_event *event)
{
blk_trace_synthesize_old_trace(iter);
return trace_handle_return(&iter->seq);
}
static enum print_line_t blk_tracer_print_line(struct trace_iterator *iter)
{
if (!(blk_tracer_flags.val & TRACE_BLK_OPT_CLASSIC))
return TRACE_TYPE_UNHANDLED;
return print_one_line(iter, true);
}
static int
blk_tracer_set_flag(struct trace_array *tr, u32 old_flags, u32 bit, int set)
{
if (bit == TRACE_BLK_OPT_CLASSIC) {
if (set)
tr->trace_flags &= ~TRACE_ITER_CONTEXT_INFO;
else
tr->trace_flags |= TRACE_ITER_CONTEXT_INFO;
}
return 0;
}
static int __init init_blk_tracer(void)
{
if (!register_trace_event(&trace_blk_event)) {
pr_warn("Warning: could not register block events\n");
return 1;
}
if (register_tracer(&blk_tracer) != 0) {
pr_warn("Warning: could not register the block tracer\n");
unregister_trace_event(&trace_blk_event);
return 1;
}
return 0;
}
static int blk_trace_remove_queue(struct request_queue *q)
{
struct blk_trace *bt;
bt = xchg(&q->blk_trace, NULL);
if (bt == NULL)
return -EINVAL;
if (atomic_dec_and_test(&blk_probes_ref))
blk_unregister_tracepoints();
blk_trace_free(bt);
return 0;
}
static int blk_trace_setup_queue(struct request_queue *q,
struct block_device *bdev)
{
struct blk_trace *bt = NULL;
int ret = -ENOMEM;
bt = kzalloc(sizeof(*bt), GFP_KERNEL);
if (!bt)
return -ENOMEM;
bt->msg_data = __alloc_percpu(BLK_TN_MAX_MSG, __alignof__(char));
if (!bt->msg_data)
goto free_bt;
bt->dev = bdev->bd_dev;
bt->act_mask = (u16)-1;
blk_trace_setup_lba(bt, bdev);
ret = -EBUSY;
if (cmpxchg(&q->blk_trace, NULL, bt))
goto free_bt;
if (atomic_inc_return(&blk_probes_ref) == 1)
blk_register_tracepoints();
return 0;
free_bt:
blk_trace_free(bt);
return ret;
}
static int blk_trace_str2mask(const char *str)
{
int i;
int mask = 0;
char *buf, *s, *token;
buf = kstrdup(str, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
s = strstrip(buf);
while (1) {
token = strsep(&s, ",");
if (token == NULL)
break;
if (*token == '\0')
continue;
for (i = 0; i < ARRAY_SIZE(mask_maps); i++) {
if (strcasecmp(token, mask_maps[i].str) == 0) {
mask |= mask_maps[i].mask;
break;
}
}
if (i == ARRAY_SIZE(mask_maps)) {
mask = -EINVAL;
break;
}
}
kfree(buf);
return mask;
}
static ssize_t blk_trace_mask2str(char *buf, int mask)
{
int i;
char *p = buf;
for (i = 0; i < ARRAY_SIZE(mask_maps); i++) {
if (mask & mask_maps[i].mask) {
p += sprintf(p, "%s%s",
(p == buf) ? "" : ",", mask_maps[i].str);
}
}
*p++ = '\n';
return p - buf;
}
static struct request_queue *blk_trace_get_queue(struct block_device *bdev)
{
if (bdev->bd_disk == NULL)
return NULL;
return bdev_get_queue(bdev);
}
static ssize_t sysfs_blk_trace_attr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hd_struct *p = dev_to_part(dev);
struct request_queue *q;
struct block_device *bdev;
ssize_t ret = -ENXIO;
bdev = bdget(part_devt(p));
if (bdev == NULL)
goto out;
q = blk_trace_get_queue(bdev);
if (q == NULL)
goto out_bdput;
mutex_lock(&bdev->bd_mutex);
if (attr == &dev_attr_enable) {
ret = sprintf(buf, "%u\n", !!q->blk_trace);
goto out_unlock_bdev;
}
if (q->blk_trace == NULL)
ret = sprintf(buf, "disabled\n");
else if (attr == &dev_attr_act_mask)
ret = blk_trace_mask2str(buf, q->blk_trace->act_mask);
else if (attr == &dev_attr_pid)
ret = sprintf(buf, "%u\n", q->blk_trace->pid);
else if (attr == &dev_attr_start_lba)
ret = sprintf(buf, "%llu\n", q->blk_trace->start_lba);
else if (attr == &dev_attr_end_lba)
ret = sprintf(buf, "%llu\n", q->blk_trace->end_lba);
out_unlock_bdev:
mutex_unlock(&bdev->bd_mutex);
out_bdput:
bdput(bdev);
out:
return ret;
}
static ssize_t sysfs_blk_trace_attr_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct block_device *bdev;
struct request_queue *q;
struct hd_struct *p;
u64 value;
ssize_t ret = -EINVAL;
if (count == 0)
goto out;
if (attr == &dev_attr_act_mask) {
if (sscanf(buf, "%llx", &value) != 1) {
ret = blk_trace_str2mask(buf);
if (ret < 0)
goto out;
value = ret;
}
} else if (sscanf(buf, "%llu", &value) != 1)
goto out;
ret = -ENXIO;
p = dev_to_part(dev);
bdev = bdget(part_devt(p));
if (bdev == NULL)
goto out;
q = blk_trace_get_queue(bdev);
if (q == NULL)
goto out_bdput;
mutex_lock(&bdev->bd_mutex);
if (attr == &dev_attr_enable) {
if (value)
ret = blk_trace_setup_queue(q, bdev);
else
ret = blk_trace_remove_queue(q);
goto out_unlock_bdev;
}
ret = 0;
if (q->blk_trace == NULL)
ret = blk_trace_setup_queue(q, bdev);
if (ret == 0) {
if (attr == &dev_attr_act_mask)
q->blk_trace->act_mask = value;
else if (attr == &dev_attr_pid)
q->blk_trace->pid = value;
else if (attr == &dev_attr_start_lba)
q->blk_trace->start_lba = value;
else if (attr == &dev_attr_end_lba)
q->blk_trace->end_lba = value;
}
out_unlock_bdev:
mutex_unlock(&bdev->bd_mutex);
out_bdput:
bdput(bdev);
out:
return ret ? ret : count;
}
int blk_trace_init_sysfs(struct device *dev)
{
return sysfs_create_group(&dev->kobj, &blk_trace_attr_group);
}
void blk_trace_remove_sysfs(struct device *dev)
{
sysfs_remove_group(&dev->kobj, &blk_trace_attr_group);
}
void blk_fill_rwbs(char *rwbs, unsigned int op, int bytes)
{
int i = 0;
if (op & REQ_PREFLUSH)
rwbs[i++] = 'F';
switch (op & REQ_OP_MASK) {
case REQ_OP_WRITE:
case REQ_OP_WRITE_SAME:
rwbs[i++] = 'W';
break;
case REQ_OP_DISCARD:
rwbs[i++] = 'D';
break;
case REQ_OP_SECURE_ERASE:
rwbs[i++] = 'D';
rwbs[i++] = 'E';
break;
case REQ_OP_FLUSH:
rwbs[i++] = 'F';
break;
case REQ_OP_READ:
rwbs[i++] = 'R';
break;
default:
rwbs[i++] = 'N';
}
if (op & REQ_FUA)
rwbs[i++] = 'F';
if (op & REQ_RAHEAD)
rwbs[i++] = 'A';
if (op & REQ_SYNC)
rwbs[i++] = 'S';
if (op & REQ_META)
rwbs[i++] = 'M';
rwbs[i] = '\0';
}
