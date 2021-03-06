void fscache_enqueue_operation(struct fscache_operation *op)
{
_enter("{OBJ%x OP%x,%u}",
op->object->debug_id, op->debug_id, atomic_read(&op->usage));
ASSERT(list_empty(&op->pend_link));
ASSERT(op->processor != NULL);
ASSERTCMP(op->object->state, >=, FSCACHE_OBJECT_AVAILABLE);
ASSERTCMP(atomic_read(&op->usage), >, 0);
fscache_stat(&fscache_n_op_enqueue);
switch (op->flags & FSCACHE_OP_TYPE) {
case FSCACHE_OP_ASYNC:
_debug("queue async");
atomic_inc(&op->usage);
if (!queue_work(fscache_op_wq, &op->work))
fscache_put_operation(op);
break;
case FSCACHE_OP_MYTHREAD:
_debug("queue for caller's attention");
break;
default:
printk(KERN_ERR "FS-Cache: Unexpected op type %lx",
op->flags);
BUG();
break;
}
}
static void fscache_run_op(struct fscache_object *object,
struct fscache_operation *op)
{
object->n_in_progress++;
if (test_and_clear_bit(FSCACHE_OP_WAITING, &op->flags))
wake_up_bit(&op->flags, FSCACHE_OP_WAITING);
if (op->processor)
fscache_enqueue_operation(op);
fscache_stat(&fscache_n_op_run);
}
int fscache_submit_exclusive_op(struct fscache_object *object,
struct fscache_operation *op)
{
int ret;
_enter("{OBJ%x OP%x},", object->debug_id, op->debug_id);
spin_lock(&object->lock);
ASSERTCMP(object->n_ops, >=, object->n_in_progress);
ASSERTCMP(object->n_ops, >=, object->n_exclusive);
ASSERT(list_empty(&op->pend_link));
ret = -ENOBUFS;
if (fscache_object_is_active(object)) {
op->object = object;
object->n_ops++;
object->n_exclusive++;
if (object->n_ops > 1) {
atomic_inc(&op->usage);
list_add_tail(&op->pend_link, &object->pending_ops);
fscache_stat(&fscache_n_op_pend);
} else if (!list_empty(&object->pending_ops)) {
atomic_inc(&op->usage);
list_add_tail(&op->pend_link, &object->pending_ops);
fscache_stat(&fscache_n_op_pend);
fscache_start_operations(object);
} else {
ASSERTCMP(object->n_in_progress, ==, 0);
fscache_run_op(object, op);
}
clear_bit(FSCACHE_OBJECT_PENDING_WRITE, &object->flags);
ret = 0;
} else if (object->state == FSCACHE_OBJECT_CREATING) {
op->object = object;
object->n_ops++;
object->n_exclusive++;
atomic_inc(&op->usage);
list_add_tail(&op->pend_link, &object->pending_ops);
fscache_stat(&fscache_n_op_pend);
ret = 0;
} else {
BUG();
}
spin_unlock(&object->lock);
return ret;
}
static void fscache_report_unexpected_submission(struct fscache_object *object,
struct fscache_operation *op,
unsigned long ostate)
{
static bool once_only;
struct fscache_operation *p;
unsigned n;
if (once_only)
return;
once_only = true;
kdebug("unexpected submission OP%x [OBJ%x %s]",
op->debug_id, object->debug_id,
fscache_object_states[object->state]);
kdebug("objstate=%s [%s]",
fscache_object_states[object->state],
fscache_object_states[ostate]);
kdebug("objflags=%lx", object->flags);
kdebug("objevent=%lx [%lx]", object->events, object->event_mask);
kdebug("ops=%u inp=%u exc=%u",
object->n_ops, object->n_in_progress, object->n_exclusive);
if (!list_empty(&object->pending_ops)) {
n = 0;
list_for_each_entry(p, &object->pending_ops, pend_link) {
ASSERTCMP(p->object, ==, object);
kdebug("%p %p", op->processor, op->release);
n++;
}
kdebug("n=%u", n);
}
dump_stack();
}
int fscache_submit_op(struct fscache_object *object,
struct fscache_operation *op)
{
unsigned long ostate;
int ret;
_enter("{OBJ%x OP%x},{%u}",
object->debug_id, op->debug_id, atomic_read(&op->usage));
ASSERTCMP(atomic_read(&op->usage), >, 0);
spin_lock(&object->lock);
ASSERTCMP(object->n_ops, >=, object->n_in_progress);
ASSERTCMP(object->n_ops, >=, object->n_exclusive);
ASSERT(list_empty(&op->pend_link));
ostate = object->state;
smp_rmb();
if (fscache_object_is_active(object)) {
op->object = object;
object->n_ops++;
if (object->n_exclusive > 0) {
atomic_inc(&op->usage);
list_add_tail(&op->pend_link, &object->pending_ops);
fscache_stat(&fscache_n_op_pend);
} else if (!list_empty(&object->pending_ops)) {
atomic_inc(&op->usage);
list_add_tail(&op->pend_link, &object->pending_ops);
fscache_stat(&fscache_n_op_pend);
fscache_start_operations(object);
} else {
ASSERTCMP(object->n_exclusive, ==, 0);
fscache_run_op(object, op);
}
ret = 0;
} else if (object->state == FSCACHE_OBJECT_CREATING) {
op->object = object;
object->n_ops++;
atomic_inc(&op->usage);
list_add_tail(&op->pend_link, &object->pending_ops);
fscache_stat(&fscache_n_op_pend);
ret = 0;
} else if (object->state == FSCACHE_OBJECT_DYING ||
object->state == FSCACHE_OBJECT_LC_DYING ||
object->state == FSCACHE_OBJECT_WITHDRAWING) {
fscache_stat(&fscache_n_op_rejected);
ret = -ENOBUFS;
} else if (!test_bit(FSCACHE_IOERROR, &object->cache->flags)) {
fscache_report_unexpected_submission(object, op, ostate);
ASSERT(!fscache_object_is_active(object));
ret = -ENOBUFS;
} else {
ret = -ENOBUFS;
}
spin_unlock(&object->lock);
return ret;
}
void fscache_abort_object(struct fscache_object *object)
{
_enter("{OBJ%x}", object->debug_id);
fscache_raise_event(object, FSCACHE_OBJECT_EV_ERROR);
}
void fscache_start_operations(struct fscache_object *object)
{
struct fscache_operation *op;
bool stop = false;
while (!list_empty(&object->pending_ops) && !stop) {
op = list_entry(object->pending_ops.next,
struct fscache_operation, pend_link);
if (test_bit(FSCACHE_OP_EXCLUSIVE, &op->flags)) {
if (object->n_in_progress > 0)
break;
stop = true;
}
list_del_init(&op->pend_link);
fscache_run_op(object, op);
fscache_put_operation(op);
}
ASSERTCMP(object->n_in_progress, <=, object->n_ops);
_debug("woke %d ops on OBJ%x",
object->n_in_progress, object->debug_id);
}
int fscache_cancel_op(struct fscache_operation *op)
{
struct fscache_object *object = op->object;
int ret;
_enter("OBJ%x OP%x}", op->object->debug_id, op->debug_id);
spin_lock(&object->lock);
ret = -EBUSY;
if (!list_empty(&op->pend_link)) {
fscache_stat(&fscache_n_op_cancelled);
list_del_init(&op->pend_link);
object->n_ops--;
if (test_bit(FSCACHE_OP_EXCLUSIVE, &op->flags))
object->n_exclusive--;
if (test_and_clear_bit(FSCACHE_OP_WAITING, &op->flags))
wake_up_bit(&op->flags, FSCACHE_OP_WAITING);
fscache_put_operation(op);
ret = 0;
}
spin_unlock(&object->lock);
_leave(" = %d", ret);
return ret;
}
void fscache_put_operation(struct fscache_operation *op)
{
struct fscache_object *object;
struct fscache_cache *cache;
_enter("{OBJ%x OP%x,%d}",
op->object->debug_id, op->debug_id, atomic_read(&op->usage));
ASSERTCMP(atomic_read(&op->usage), >, 0);
if (!atomic_dec_and_test(&op->usage))
return;
_debug("PUT OP");
if (test_and_set_bit(FSCACHE_OP_DEAD, &op->flags))
BUG();
fscache_stat(&fscache_n_op_release);
if (op->release) {
op->release(op);
op->release = NULL;
}
object = op->object;
if (test_bit(FSCACHE_OP_DEC_READ_CNT, &op->flags))
atomic_dec(&object->n_reads);
if (!spin_trylock(&object->lock)) {
_debug("defer put");
fscache_stat(&fscache_n_op_deferred_release);
cache = object->cache;
spin_lock(&cache->op_gc_list_lock);
list_add_tail(&op->pend_link, &cache->op_gc_list);
spin_unlock(&cache->op_gc_list_lock);
schedule_work(&cache->op_gc);
_leave(" [defer]");
return;
}
if (test_bit(FSCACHE_OP_EXCLUSIVE, &op->flags)) {
ASSERTCMP(object->n_exclusive, >, 0);
object->n_exclusive--;
}
ASSERTCMP(object->n_in_progress, >, 0);
object->n_in_progress--;
if (object->n_in_progress == 0)
fscache_start_operations(object);
ASSERTCMP(object->n_ops, >, 0);
object->n_ops--;
if (object->n_ops == 0)
fscache_raise_event(object, FSCACHE_OBJECT_EV_CLEARED);
spin_unlock(&object->lock);
kfree(op);
_leave(" [done]");
}
void fscache_operation_gc(struct work_struct *work)
{
struct fscache_operation *op;
struct fscache_object *object;
struct fscache_cache *cache =
container_of(work, struct fscache_cache, op_gc);
int count = 0;
_enter("");
do {
spin_lock(&cache->op_gc_list_lock);
if (list_empty(&cache->op_gc_list)) {
spin_unlock(&cache->op_gc_list_lock);
break;
}
op = list_entry(cache->op_gc_list.next,
struct fscache_operation, pend_link);
list_del(&op->pend_link);
spin_unlock(&cache->op_gc_list_lock);
object = op->object;
_debug("GC DEFERRED REL OBJ%x OP%x",
object->debug_id, op->debug_id);
fscache_stat(&fscache_n_op_gc);
ASSERTCMP(atomic_read(&op->usage), ==, 0);
spin_lock(&object->lock);
if (test_bit(FSCACHE_OP_EXCLUSIVE, &op->flags)) {
ASSERTCMP(object->n_exclusive, >, 0);
object->n_exclusive--;
}
ASSERTCMP(object->n_in_progress, >, 0);
object->n_in_progress--;
if (object->n_in_progress == 0)
fscache_start_operations(object);
ASSERTCMP(object->n_ops, >, 0);
object->n_ops--;
if (object->n_ops == 0)
fscache_raise_event(object, FSCACHE_OBJECT_EV_CLEARED);
spin_unlock(&object->lock);
} while (count++ < 20);
if (!list_empty(&cache->op_gc_list))
schedule_work(&cache->op_gc);
_leave("");
}
void fscache_op_work_func(struct work_struct *work)
{
struct fscache_operation *op =
container_of(work, struct fscache_operation, work);
unsigned long start;
_enter("{OBJ%x OP%x,%d}",
op->object->debug_id, op->debug_id, atomic_read(&op->usage));
ASSERT(op->processor != NULL);
start = jiffies;
op->processor(op);
fscache_hist(fscache_ops_histogram, start);
fscache_put_operation(op);
_leave("");
}
