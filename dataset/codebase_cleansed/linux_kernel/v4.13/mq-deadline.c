static inline struct rb_root *
deadline_rb_root(struct deadline_data *dd, struct request *rq)
{
return &dd->sort_list[rq_data_dir(rq)];
}
static inline struct request *
deadline_latter_request(struct request *rq)
{
struct rb_node *node = rb_next(&rq->rb_node);
if (node)
return rb_entry_rq(node);
return NULL;
}
static void
deadline_add_rq_rb(struct deadline_data *dd, struct request *rq)
{
struct rb_root *root = deadline_rb_root(dd, rq);
elv_rb_add(root, rq);
}
static inline void
deadline_del_rq_rb(struct deadline_data *dd, struct request *rq)
{
const int data_dir = rq_data_dir(rq);
if (dd->next_rq[data_dir] == rq)
dd->next_rq[data_dir] = deadline_latter_request(rq);
elv_rb_del(deadline_rb_root(dd, rq), rq);
}
static void deadline_remove_request(struct request_queue *q, struct request *rq)
{
struct deadline_data *dd = q->elevator->elevator_data;
list_del_init(&rq->queuelist);
if (!RB_EMPTY_NODE(&rq->rb_node))
deadline_del_rq_rb(dd, rq);
elv_rqhash_del(q, rq);
if (q->last_merge == rq)
q->last_merge = NULL;
}
static void dd_request_merged(struct request_queue *q, struct request *req,
enum elv_merge type)
{
struct deadline_data *dd = q->elevator->elevator_data;
if (type == ELEVATOR_FRONT_MERGE) {
elv_rb_del(deadline_rb_root(dd, req), req);
deadline_add_rq_rb(dd, req);
}
}
static void dd_merged_requests(struct request_queue *q, struct request *req,
struct request *next)
{
if (!list_empty(&req->queuelist) && !list_empty(&next->queuelist)) {
if (time_before((unsigned long)next->fifo_time,
(unsigned long)req->fifo_time)) {
list_move(&req->queuelist, &next->queuelist);
req->fifo_time = next->fifo_time;
}
}
deadline_remove_request(q, next);
}
static void
deadline_move_request(struct deadline_data *dd, struct request *rq)
{
const int data_dir = rq_data_dir(rq);
dd->next_rq[READ] = NULL;
dd->next_rq[WRITE] = NULL;
dd->next_rq[data_dir] = deadline_latter_request(rq);
deadline_remove_request(rq->q, rq);
}
static inline int deadline_check_fifo(struct deadline_data *dd, int ddir)
{
struct request *rq = rq_entry_fifo(dd->fifo_list[ddir].next);
if (time_after_eq(jiffies, (unsigned long)rq->fifo_time))
return 1;
return 0;
}
static struct request *__dd_dispatch_request(struct blk_mq_hw_ctx *hctx)
{
struct deadline_data *dd = hctx->queue->elevator->elevator_data;
struct request *rq;
bool reads, writes;
int data_dir;
if (!list_empty(&dd->dispatch)) {
rq = list_first_entry(&dd->dispatch, struct request, queuelist);
list_del_init(&rq->queuelist);
goto done;
}
reads = !list_empty(&dd->fifo_list[READ]);
writes = !list_empty(&dd->fifo_list[WRITE]);
if (dd->next_rq[WRITE])
rq = dd->next_rq[WRITE];
else
rq = dd->next_rq[READ];
if (rq && dd->batching < dd->fifo_batch)
goto dispatch_request;
if (reads) {
BUG_ON(RB_EMPTY_ROOT(&dd->sort_list[READ]));
if (writes && (dd->starved++ >= dd->writes_starved))
goto dispatch_writes;
data_dir = READ;
goto dispatch_find_request;
}
if (writes) {
dispatch_writes:
BUG_ON(RB_EMPTY_ROOT(&dd->sort_list[WRITE]));
dd->starved = 0;
data_dir = WRITE;
goto dispatch_find_request;
}
return NULL;
dispatch_find_request:
if (deadline_check_fifo(dd, data_dir) || !dd->next_rq[data_dir]) {
rq = rq_entry_fifo(dd->fifo_list[data_dir].next);
} else {
rq = dd->next_rq[data_dir];
}
dd->batching = 0;
dispatch_request:
dd->batching++;
deadline_move_request(dd, rq);
done:
rq->rq_flags |= RQF_STARTED;
return rq;
}
static struct request *dd_dispatch_request(struct blk_mq_hw_ctx *hctx)
{
struct deadline_data *dd = hctx->queue->elevator->elevator_data;
struct request *rq;
spin_lock(&dd->lock);
rq = __dd_dispatch_request(hctx);
spin_unlock(&dd->lock);
return rq;
}
static void dd_exit_queue(struct elevator_queue *e)
{
struct deadline_data *dd = e->elevator_data;
BUG_ON(!list_empty(&dd->fifo_list[READ]));
BUG_ON(!list_empty(&dd->fifo_list[WRITE]));
kfree(dd);
}
static int dd_init_queue(struct request_queue *q, struct elevator_type *e)
{
struct deadline_data *dd;
struct elevator_queue *eq;
eq = elevator_alloc(q, e);
if (!eq)
return -ENOMEM;
dd = kzalloc_node(sizeof(*dd), GFP_KERNEL, q->node);
if (!dd) {
kobject_put(&eq->kobj);
return -ENOMEM;
}
eq->elevator_data = dd;
INIT_LIST_HEAD(&dd->fifo_list[READ]);
INIT_LIST_HEAD(&dd->fifo_list[WRITE]);
dd->sort_list[READ] = RB_ROOT;
dd->sort_list[WRITE] = RB_ROOT;
dd->fifo_expire[READ] = read_expire;
dd->fifo_expire[WRITE] = write_expire;
dd->writes_starved = writes_starved;
dd->front_merges = 1;
dd->fifo_batch = fifo_batch;
spin_lock_init(&dd->lock);
INIT_LIST_HEAD(&dd->dispatch);
q->elevator = eq;
return 0;
}
static int dd_request_merge(struct request_queue *q, struct request **rq,
struct bio *bio)
{
struct deadline_data *dd = q->elevator->elevator_data;
sector_t sector = bio_end_sector(bio);
struct request *__rq;
if (!dd->front_merges)
return ELEVATOR_NO_MERGE;
__rq = elv_rb_find(&dd->sort_list[bio_data_dir(bio)], sector);
if (__rq) {
BUG_ON(sector != blk_rq_pos(__rq));
if (elv_bio_merge_ok(__rq, bio)) {
*rq = __rq;
return ELEVATOR_FRONT_MERGE;
}
}
return ELEVATOR_NO_MERGE;
}
static bool dd_bio_merge(struct blk_mq_hw_ctx *hctx, struct bio *bio)
{
struct request_queue *q = hctx->queue;
struct deadline_data *dd = q->elevator->elevator_data;
struct request *free = NULL;
bool ret;
spin_lock(&dd->lock);
ret = blk_mq_sched_try_merge(q, bio, &free);
spin_unlock(&dd->lock);
if (free)
blk_mq_free_request(free);
return ret;
}
static void dd_insert_request(struct blk_mq_hw_ctx *hctx, struct request *rq,
bool at_head)
{
struct request_queue *q = hctx->queue;
struct deadline_data *dd = q->elevator->elevator_data;
const int data_dir = rq_data_dir(rq);
if (blk_mq_sched_try_insert_merge(q, rq))
return;
blk_mq_sched_request_inserted(rq);
if (at_head || blk_rq_is_passthrough(rq)) {
if (at_head)
list_add(&rq->queuelist, &dd->dispatch);
else
list_add_tail(&rq->queuelist, &dd->dispatch);
} else {
deadline_add_rq_rb(dd, rq);
if (rq_mergeable(rq)) {
elv_rqhash_add(q, rq);
if (!q->last_merge)
q->last_merge = rq;
}
rq->fifo_time = jiffies + dd->fifo_expire[data_dir];
list_add_tail(&rq->queuelist, &dd->fifo_list[data_dir]);
}
}
static void dd_insert_requests(struct blk_mq_hw_ctx *hctx,
struct list_head *list, bool at_head)
{
struct request_queue *q = hctx->queue;
struct deadline_data *dd = q->elevator->elevator_data;
spin_lock(&dd->lock);
while (!list_empty(list)) {
struct request *rq;
rq = list_first_entry(list, struct request, queuelist);
list_del_init(&rq->queuelist);
dd_insert_request(hctx, rq, at_head);
}
spin_unlock(&dd->lock);
}
static bool dd_has_work(struct blk_mq_hw_ctx *hctx)
{
struct deadline_data *dd = hctx->queue->elevator->elevator_data;
return !list_empty_careful(&dd->dispatch) ||
!list_empty_careful(&dd->fifo_list[0]) ||
!list_empty_careful(&dd->fifo_list[1]);
}
static ssize_t
deadline_var_show(int var, char *page)
{
return sprintf(page, "%d\n", var);
}
static ssize_t
deadline_var_store(int *var, const char *page, size_t count)
{
char *p = (char *) page;
*var = simple_strtol(p, &p, 10);
return count;
}
static int deadline_batching_show(void *data, struct seq_file *m)
{
struct request_queue *q = data;
struct deadline_data *dd = q->elevator->elevator_data;
seq_printf(m, "%u\n", dd->batching);
return 0;
}
static int deadline_starved_show(void *data, struct seq_file *m)
{
struct request_queue *q = data;
struct deadline_data *dd = q->elevator->elevator_data;
seq_printf(m, "%u\n", dd->starved);
return 0;
}
static void *deadline_dispatch_start(struct seq_file *m, loff_t *pos)
__acquires(&dd->lock
static void *deadline_dispatch_next(struct seq_file *m, void *v, loff_t *pos)
{
struct request_queue *q = m->private;
struct deadline_data *dd = q->elevator->elevator_data;
return seq_list_next(v, &dd->dispatch, pos);
}
static void deadline_dispatch_stop(struct seq_file *m, void *v)
__releases(&dd->lock
static int __init deadline_init(void)
{
return elv_register(&mq_deadline);
}
static void __exit deadline_exit(void)
{
elv_unregister(&mq_deadline);
}
