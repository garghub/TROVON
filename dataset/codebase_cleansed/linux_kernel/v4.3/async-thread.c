static struct __btrfs_workqueue *
__btrfs_alloc_workqueue(const char *name, unsigned int flags, int limit_active,
int thresh)
{
struct __btrfs_workqueue *ret = kzalloc(sizeof(*ret), GFP_NOFS);
if (!ret)
return NULL;
ret->limit_active = limit_active;
atomic_set(&ret->pending, 0);
if (thresh == 0)
thresh = DFT_THRESHOLD;
if (thresh < DFT_THRESHOLD) {
ret->current_active = limit_active;
ret->thresh = NO_THRESHOLD;
} else {
ret->current_active = 1;
ret->thresh = thresh;
}
if (flags & WQ_HIGHPRI)
ret->normal_wq = alloc_workqueue("%s-%s-high", flags,
ret->current_active, "btrfs",
name);
else
ret->normal_wq = alloc_workqueue("%s-%s", flags,
ret->current_active, "btrfs",
name);
if (!ret->normal_wq) {
kfree(ret);
return NULL;
}
INIT_LIST_HEAD(&ret->ordered_list);
spin_lock_init(&ret->list_lock);
spin_lock_init(&ret->thres_lock);
trace_btrfs_workqueue_alloc(ret, name, flags & WQ_HIGHPRI);
return ret;
}
struct btrfs_workqueue *btrfs_alloc_workqueue(const char *name,
unsigned int flags,
int limit_active,
int thresh)
{
struct btrfs_workqueue *ret = kzalloc(sizeof(*ret), GFP_NOFS);
if (!ret)
return NULL;
ret->normal = __btrfs_alloc_workqueue(name, flags & ~WQ_HIGHPRI,
limit_active, thresh);
if (!ret->normal) {
kfree(ret);
return NULL;
}
if (flags & WQ_HIGHPRI) {
ret->high = __btrfs_alloc_workqueue(name, flags, limit_active,
thresh);
if (!ret->high) {
__btrfs_destroy_workqueue(ret->normal);
kfree(ret);
return NULL;
}
}
return ret;
}
static inline void thresh_queue_hook(struct __btrfs_workqueue *wq)
{
if (wq->thresh == NO_THRESHOLD)
return;
atomic_inc(&wq->pending);
}
static inline void thresh_exec_hook(struct __btrfs_workqueue *wq)
{
int new_current_active;
long pending;
int need_change = 0;
if (wq->thresh == NO_THRESHOLD)
return;
atomic_dec(&wq->pending);
spin_lock(&wq->thres_lock);
wq->count++;
wq->count %= (wq->thresh / 4);
if (!wq->count)
goto out;
new_current_active = wq->current_active;
pending = atomic_read(&wq->pending);
if (pending > wq->thresh)
new_current_active++;
if (pending < wq->thresh / 2)
new_current_active--;
new_current_active = clamp_val(new_current_active, 1, wq->limit_active);
if (new_current_active != wq->current_active) {
need_change = 1;
wq->current_active = new_current_active;
}
out:
spin_unlock(&wq->thres_lock);
if (need_change) {
workqueue_set_max_active(wq->normal_wq, wq->current_active);
}
}
static void run_ordered_work(struct __btrfs_workqueue *wq)
{
struct list_head *list = &wq->ordered_list;
struct btrfs_work *work;
spinlock_t *lock = &wq->list_lock;
unsigned long flags;
while (1) {
spin_lock_irqsave(lock, flags);
if (list_empty(list))
break;
work = list_entry(list->next, struct btrfs_work,
ordered_list);
if (!test_bit(WORK_DONE_BIT, &work->flags))
break;
if (test_and_set_bit(WORK_ORDER_DONE_BIT, &work->flags))
break;
trace_btrfs_ordered_sched(work);
spin_unlock_irqrestore(lock, flags);
work->ordered_func(work);
spin_lock_irqsave(lock, flags);
list_del(&work->ordered_list);
spin_unlock_irqrestore(lock, flags);
work->ordered_free(work);
trace_btrfs_all_work_done(work);
}
spin_unlock_irqrestore(lock, flags);
}
static void normal_work_helper(struct btrfs_work *work)
{
struct __btrfs_workqueue *wq;
int need_order = 0;
if (work->ordered_func)
need_order = 1;
wq = work->wq;
trace_btrfs_work_sched(work);
thresh_exec_hook(wq);
work->func(work);
if (need_order) {
set_bit(WORK_DONE_BIT, &work->flags);
run_ordered_work(wq);
}
if (!need_order)
trace_btrfs_all_work_done(work);
}
void btrfs_init_work(struct btrfs_work *work, btrfs_work_func_t uniq_func,
btrfs_func_t func,
btrfs_func_t ordered_func,
btrfs_func_t ordered_free)
{
work->func = func;
work->ordered_func = ordered_func;
work->ordered_free = ordered_free;
INIT_WORK(&work->normal_work, uniq_func);
INIT_LIST_HEAD(&work->ordered_list);
work->flags = 0;
}
static inline void __btrfs_queue_work(struct __btrfs_workqueue *wq,
struct btrfs_work *work)
{
unsigned long flags;
work->wq = wq;
thresh_queue_hook(wq);
if (work->ordered_func) {
spin_lock_irqsave(&wq->list_lock, flags);
list_add_tail(&work->ordered_list, &wq->ordered_list);
spin_unlock_irqrestore(&wq->list_lock, flags);
}
queue_work(wq->normal_wq, &work->normal_work);
trace_btrfs_work_queued(work);
}
void btrfs_queue_work(struct btrfs_workqueue *wq,
struct btrfs_work *work)
{
struct __btrfs_workqueue *dest_wq;
if (test_bit(WORK_HIGH_PRIO_BIT, &work->flags) && wq->high)
dest_wq = wq->high;
else
dest_wq = wq->normal;
__btrfs_queue_work(dest_wq, work);
}
static inline void
__btrfs_destroy_workqueue(struct __btrfs_workqueue *wq)
{
destroy_workqueue(wq->normal_wq);
trace_btrfs_workqueue_destroy(wq);
kfree(wq);
}
void btrfs_destroy_workqueue(struct btrfs_workqueue *wq)
{
if (!wq)
return;
if (wq->high)
__btrfs_destroy_workqueue(wq->high);
__btrfs_destroy_workqueue(wq->normal);
kfree(wq);
}
void btrfs_workqueue_set_max(struct btrfs_workqueue *wq, int limit_active)
{
if (!wq)
return;
wq->normal->limit_active = limit_active;
if (wq->high)
wq->high->limit_active = limit_active;
}
void btrfs_set_work_high_priority(struct btrfs_work *work)
{
set_bit(WORK_HIGH_PRIO_BIT, &work->flags);
}
