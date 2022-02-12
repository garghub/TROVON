static int rq_sched_domain(const struct request *rq)
{
unsigned int op = rq->cmd_flags;
if ((op & REQ_OP_MASK) == REQ_OP_READ)
return KYBER_READ;
else if ((op & REQ_OP_MASK) == REQ_OP_WRITE && op_is_sync(op))
return KYBER_SYNC_WRITE;
else
return KYBER_OTHER;
}
static int kyber_lat_status(struct blk_stat_callback *cb,
unsigned int sched_domain, u64 target)
{
u64 latency;
if (!cb->stat[sched_domain].nr_samples)
return NONE;
latency = cb->stat[sched_domain].mean;
if (latency >= 2 * target)
return AWFUL;
else if (latency > target)
return BAD;
else if (latency <= target / 2)
return GREAT;
else
return GOOD;
}
static void kyber_adjust_rw_depth(struct kyber_queue_data *kqd,
unsigned int sched_domain, int this_status,
int other_status)
{
unsigned int orig_depth, depth;
if (this_status == NONE ||
(IS_GOOD(this_status) && IS_GOOD(other_status)) ||
(IS_BAD(this_status) && IS_BAD(other_status)))
return;
orig_depth = depth = kqd->domain_tokens[sched_domain].sb.depth;
if (other_status == NONE) {
depth++;
} else {
switch (this_status) {
case GOOD:
if (other_status == AWFUL)
depth -= max(depth / 4, 1U);
else
depth -= max(depth / 8, 1U);
break;
case GREAT:
if (other_status == AWFUL)
depth /= 2;
else
depth -= max(depth / 4, 1U);
break;
case BAD:
depth++;
break;
case AWFUL:
if (other_status == GREAT)
depth += 2;
else
depth++;
break;
}
}
depth = clamp(depth, 1U, kyber_depth[sched_domain]);
if (depth != orig_depth)
sbitmap_queue_resize(&kqd->domain_tokens[sched_domain], depth);
}
static void kyber_adjust_other_depth(struct kyber_queue_data *kqd,
int read_status, int write_status,
bool have_samples)
{
unsigned int orig_depth, depth;
int status;
orig_depth = depth = kqd->domain_tokens[KYBER_OTHER].sb.depth;
if (read_status == NONE && write_status == NONE) {
depth += 2;
} else if (have_samples) {
if (read_status == NONE)
status = write_status;
else if (write_status == NONE)
status = read_status;
else
status = max(read_status, write_status);
switch (status) {
case GREAT:
depth += 2;
break;
case GOOD:
depth++;
break;
case BAD:
depth -= max(depth / 4, 1U);
break;
case AWFUL:
depth /= 2;
break;
}
}
depth = clamp(depth, 1U, kyber_depth[KYBER_OTHER]);
if (depth != orig_depth)
sbitmap_queue_resize(&kqd->domain_tokens[KYBER_OTHER], depth);
}
static void kyber_stat_timer_fn(struct blk_stat_callback *cb)
{
struct kyber_queue_data *kqd = cb->data;
int read_status, write_status;
read_status = kyber_lat_status(cb, KYBER_READ, kqd->read_lat_nsec);
write_status = kyber_lat_status(cb, KYBER_SYNC_WRITE, kqd->write_lat_nsec);
kyber_adjust_rw_depth(kqd, KYBER_READ, read_status, write_status);
kyber_adjust_rw_depth(kqd, KYBER_SYNC_WRITE, write_status, read_status);
kyber_adjust_other_depth(kqd, read_status, write_status,
cb->stat[KYBER_OTHER].nr_samples != 0);
if (!blk_stat_is_active(kqd->cb) &&
((IS_BAD(read_status) || IS_BAD(write_status) ||
kqd->domain_tokens[KYBER_OTHER].sb.depth < kyber_depth[KYBER_OTHER])))
blk_stat_activate_msecs(kqd->cb, 100);
}
static unsigned int kyber_sched_tags_shift(struct kyber_queue_data *kqd)
{
return kqd->q->queue_hw_ctx[0]->sched_tags->bitmap_tags.sb.shift;
}
static struct kyber_queue_data *kyber_queue_data_alloc(struct request_queue *q)
{
struct kyber_queue_data *kqd;
unsigned int max_tokens;
unsigned int shift;
int ret = -ENOMEM;
int i;
kqd = kmalloc_node(sizeof(*kqd), GFP_KERNEL, q->node);
if (!kqd)
goto err;
kqd->q = q;
kqd->cb = blk_stat_alloc_callback(kyber_stat_timer_fn, rq_sched_domain,
KYBER_NUM_DOMAINS, kqd);
if (!kqd->cb)
goto err_kqd;
max_tokens = max_t(unsigned int, q->tag_set->queue_depth,
KYBER_MIN_DEPTH);
for (i = 0; i < KYBER_NUM_DOMAINS; i++) {
WARN_ON(!kyber_depth[i]);
WARN_ON(!kyber_batch_size[i]);
ret = sbitmap_queue_init_node(&kqd->domain_tokens[i],
max_tokens, -1, false, GFP_KERNEL,
q->node);
if (ret) {
while (--i >= 0)
sbitmap_queue_free(&kqd->domain_tokens[i]);
goto err_cb;
}
sbitmap_queue_resize(&kqd->domain_tokens[i], kyber_depth[i]);
}
shift = kyber_sched_tags_shift(kqd);
kqd->async_depth = (1U << shift) * KYBER_ASYNC_PERCENT / 100U;
kqd->read_lat_nsec = 2000000ULL;
kqd->write_lat_nsec = 10000000ULL;
return kqd;
err_cb:
blk_stat_free_callback(kqd->cb);
err_kqd:
kfree(kqd);
err:
return ERR_PTR(ret);
}
static int kyber_init_sched(struct request_queue *q, struct elevator_type *e)
{
struct kyber_queue_data *kqd;
struct elevator_queue *eq;
eq = elevator_alloc(q, e);
if (!eq)
return -ENOMEM;
kqd = kyber_queue_data_alloc(q);
if (IS_ERR(kqd)) {
kobject_put(&eq->kobj);
return PTR_ERR(kqd);
}
eq->elevator_data = kqd;
q->elevator = eq;
blk_stat_add_callback(q, kqd->cb);
return 0;
}
static void kyber_exit_sched(struct elevator_queue *e)
{
struct kyber_queue_data *kqd = e->elevator_data;
struct request_queue *q = kqd->q;
int i;
blk_stat_remove_callback(q, kqd->cb);
for (i = 0; i < KYBER_NUM_DOMAINS; i++)
sbitmap_queue_free(&kqd->domain_tokens[i]);
blk_stat_free_callback(kqd->cb);
kfree(kqd);
}
static int kyber_init_hctx(struct blk_mq_hw_ctx *hctx, unsigned int hctx_idx)
{
struct kyber_hctx_data *khd;
int i;
khd = kmalloc_node(sizeof(*khd), GFP_KERNEL, hctx->numa_node);
if (!khd)
return -ENOMEM;
spin_lock_init(&khd->lock);
for (i = 0; i < KYBER_NUM_DOMAINS; i++) {
INIT_LIST_HEAD(&khd->rqs[i]);
INIT_LIST_HEAD(&khd->domain_wait[i].task_list);
atomic_set(&khd->wait_index[i], 0);
}
khd->cur_domain = 0;
khd->batching = 0;
hctx->sched_data = khd;
return 0;
}
static void kyber_exit_hctx(struct blk_mq_hw_ctx *hctx, unsigned int hctx_idx)
{
kfree(hctx->sched_data);
}
static int rq_get_domain_token(struct request *rq)
{
return (long)rq->elv.priv[0];
}
static void rq_set_domain_token(struct request *rq, int token)
{
rq->elv.priv[0] = (void *)(long)token;
}
static void rq_clear_domain_token(struct kyber_queue_data *kqd,
struct request *rq)
{
unsigned int sched_domain;
int nr;
nr = rq_get_domain_token(rq);
if (nr != -1) {
sched_domain = rq_sched_domain(rq);
sbitmap_queue_clear(&kqd->domain_tokens[sched_domain], nr,
rq->mq_ctx->cpu);
}
}
static struct request *kyber_get_request(struct request_queue *q,
unsigned int op,
struct blk_mq_alloc_data *data)
{
struct kyber_queue_data *kqd = q->elevator->elevator_data;
struct request *rq;
if (!op_is_sync(op))
data->shallow_depth = kqd->async_depth;
rq = __blk_mq_alloc_request(data, op);
if (rq)
rq_set_domain_token(rq, -1);
return rq;
}
static void kyber_put_request(struct request *rq)
{
struct request_queue *q = rq->q;
struct kyber_queue_data *kqd = q->elevator->elevator_data;
rq_clear_domain_token(kqd, rq);
blk_mq_finish_request(rq);
}
static void kyber_completed_request(struct request *rq)
{
struct request_queue *q = rq->q;
struct kyber_queue_data *kqd = q->elevator->elevator_data;
unsigned int sched_domain;
u64 now, latency, target;
sched_domain = rq_sched_domain(rq);
switch (sched_domain) {
case KYBER_READ:
target = kqd->read_lat_nsec;
break;
case KYBER_SYNC_WRITE:
target = kqd->write_lat_nsec;
break;
default:
return;
}
if (blk_stat_is_active(kqd->cb))
return;
now = __blk_stat_time(ktime_to_ns(ktime_get()));
if (now < blk_stat_time(&rq->issue_stat))
return;
latency = now - blk_stat_time(&rq->issue_stat);
if (latency > target)
blk_stat_activate_msecs(kqd->cb, 10);
}
static void kyber_flush_busy_ctxs(struct kyber_hctx_data *khd,
struct blk_mq_hw_ctx *hctx)
{
LIST_HEAD(rq_list);
struct request *rq, *next;
blk_mq_flush_busy_ctxs(hctx, &rq_list);
list_for_each_entry_safe(rq, next, &rq_list, queuelist) {
unsigned int sched_domain;
sched_domain = rq_sched_domain(rq);
list_move_tail(&rq->queuelist, &khd->rqs[sched_domain]);
}
}
static int kyber_domain_wake(wait_queue_t *wait, unsigned mode, int flags,
void *key)
{
struct blk_mq_hw_ctx *hctx = READ_ONCE(wait->private);
list_del_init(&wait->task_list);
blk_mq_run_hw_queue(hctx, true);
return 1;
}
static int kyber_get_domain_token(struct kyber_queue_data *kqd,
struct kyber_hctx_data *khd,
struct blk_mq_hw_ctx *hctx)
{
unsigned int sched_domain = khd->cur_domain;
struct sbitmap_queue *domain_tokens = &kqd->domain_tokens[sched_domain];
wait_queue_t *wait = &khd->domain_wait[sched_domain];
struct sbq_wait_state *ws;
int nr;
nr = __sbitmap_queue_get(domain_tokens);
if (nr >= 0)
return nr;
if (list_empty_careful(&wait->task_list)) {
init_waitqueue_func_entry(wait, kyber_domain_wake);
wait->private = hctx;
ws = sbq_wait_ptr(domain_tokens,
&khd->wait_index[sched_domain]);
add_wait_queue(&ws->wait, wait);
nr = __sbitmap_queue_get(domain_tokens);
}
return nr;
}
static struct request *
kyber_dispatch_cur_domain(struct kyber_queue_data *kqd,
struct kyber_hctx_data *khd,
struct blk_mq_hw_ctx *hctx,
bool *flushed)
{
struct list_head *rqs;
struct request *rq;
int nr;
rqs = &khd->rqs[khd->cur_domain];
rq = list_first_entry_or_null(rqs, struct request, queuelist);
if (!rq && !*flushed) {
kyber_flush_busy_ctxs(khd, hctx);
*flushed = true;
rq = list_first_entry_or_null(rqs, struct request, queuelist);
}
if (rq) {
nr = kyber_get_domain_token(kqd, khd, hctx);
if (nr >= 0) {
khd->batching++;
rq_set_domain_token(rq, nr);
list_del_init(&rq->queuelist);
return rq;
}
}
return NULL;
}
static struct request *kyber_dispatch_request(struct blk_mq_hw_ctx *hctx)
{
struct kyber_queue_data *kqd = hctx->queue->elevator->elevator_data;
struct kyber_hctx_data *khd = hctx->sched_data;
bool flushed = false;
struct request *rq;
int i;
spin_lock(&khd->lock);
if (khd->batching < kyber_batch_size[khd->cur_domain]) {
rq = kyber_dispatch_cur_domain(kqd, khd, hctx, &flushed);
if (rq)
goto out;
}
khd->batching = 0;
for (i = 0; i < KYBER_NUM_DOMAINS; i++) {
if (khd->cur_domain == KYBER_NUM_DOMAINS - 1)
khd->cur_domain = 0;
else
khd->cur_domain++;
rq = kyber_dispatch_cur_domain(kqd, khd, hctx, &flushed);
if (rq)
goto out;
}
rq = NULL;
out:
spin_unlock(&khd->lock);
return rq;
}
static bool kyber_has_work(struct blk_mq_hw_ctx *hctx)
{
struct kyber_hctx_data *khd = hctx->sched_data;
int i;
for (i = 0; i < KYBER_NUM_DOMAINS; i++) {
if (!list_empty_careful(&khd->rqs[i]))
return true;
}
return false;
}
static int kyber_async_depth_show(void *data, struct seq_file *m)
{
struct request_queue *q = data;
struct kyber_queue_data *kqd = q->elevator->elevator_data;
seq_printf(m, "%u\n", kqd->async_depth);
return 0;
}
static int kyber_cur_domain_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
struct kyber_hctx_data *khd = hctx->sched_data;
switch (khd->cur_domain) {
case KYBER_READ:
seq_puts(m, "READ\n");
break;
case KYBER_SYNC_WRITE:
seq_puts(m, "SYNC_WRITE\n");
break;
case KYBER_OTHER:
seq_puts(m, "OTHER\n");
break;
default:
seq_printf(m, "%u\n", khd->cur_domain);
break;
}
return 0;
}
static int kyber_batching_show(void *data, struct seq_file *m)
{
struct blk_mq_hw_ctx *hctx = data;
struct kyber_hctx_data *khd = hctx->sched_data;
seq_printf(m, "%u\n", khd->batching);
return 0;
}
static int __init kyber_init(void)
{
return elv_register(&kyber_sched);
}
static void __exit kyber_exit(void)
{
elv_unregister(&kyber_sched);
}
