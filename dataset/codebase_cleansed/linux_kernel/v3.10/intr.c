static void waiter_release(struct kref *kref)
{
kfree(container_of(kref, struct host1x_waitlist, refcount));
}
static bool add_waiter_to_queue(struct host1x_waitlist *waiter,
struct list_head *queue)
{
struct host1x_waitlist *pos;
u32 thresh = waiter->thresh;
list_for_each_entry_reverse(pos, queue, list)
if ((s32)(pos->thresh - thresh) <= 0) {
list_add(&waiter->list, &pos->list);
return false;
}
list_add(&waiter->list, queue);
return true;
}
static void remove_completed_waiters(struct list_head *head, u32 sync,
struct list_head completed[HOST1X_INTR_ACTION_COUNT])
{
struct list_head *dest;
struct host1x_waitlist *waiter, *next, *prev;
list_for_each_entry_safe(waiter, next, head, list) {
if ((s32)(waiter->thresh - sync) > 0)
break;
dest = completed + waiter->action;
if (waiter->action == HOST1X_INTR_ACTION_SUBMIT_COMPLETE &&
!list_empty(dest)) {
prev = list_entry(dest->prev,
struct host1x_waitlist, list);
if (prev->data == waiter->data) {
prev->count++;
dest = NULL;
}
}
if (atomic_inc_return(&waiter->state) == WLS_HANDLED || !dest) {
list_del(&waiter->list);
kref_put(&waiter->refcount, waiter_release);
} else
list_move_tail(&waiter->list, dest);
}
}
static void reset_threshold_interrupt(struct host1x *host,
struct list_head *head,
unsigned int id)
{
u32 thresh =
list_first_entry(head, struct host1x_waitlist, list)->thresh;
host1x_hw_intr_set_syncpt_threshold(host, id, thresh);
host1x_hw_intr_enable_syncpt_intr(host, id);
}
static void action_submit_complete(struct host1x_waitlist *waiter)
{
struct host1x_channel *channel = waiter->data;
host1x_cdma_update(&channel->cdma);
trace_host1x_channel_submit_complete(dev_name(channel->dev),
waiter->count, waiter->thresh);
}
static void action_wakeup(struct host1x_waitlist *waiter)
{
wait_queue_head_t *wq = waiter->data;
wake_up(wq);
}
static void action_wakeup_interruptible(struct host1x_waitlist *waiter)
{
wait_queue_head_t *wq = waiter->data;
wake_up_interruptible(wq);
}
static void run_handlers(struct list_head completed[HOST1X_INTR_ACTION_COUNT])
{
struct list_head *head = completed;
int i;
for (i = 0; i < HOST1X_INTR_ACTION_COUNT; ++i, ++head) {
action_handler handler = action_handlers[i];
struct host1x_waitlist *waiter, *next;
list_for_each_entry_safe(waiter, next, head, list) {
list_del(&waiter->list);
handler(waiter);
WARN_ON(atomic_xchg(&waiter->state, WLS_HANDLED) !=
WLS_REMOVED);
kref_put(&waiter->refcount, waiter_release);
}
}
}
static int process_wait_list(struct host1x *host,
struct host1x_syncpt *syncpt,
u32 threshold)
{
struct list_head completed[HOST1X_INTR_ACTION_COUNT];
unsigned int i;
int empty;
for (i = 0; i < HOST1X_INTR_ACTION_COUNT; ++i)
INIT_LIST_HEAD(completed + i);
spin_lock(&syncpt->intr.lock);
remove_completed_waiters(&syncpt->intr.wait_head, threshold,
completed);
empty = list_empty(&syncpt->intr.wait_head);
if (empty)
host1x_hw_intr_disable_syncpt_intr(host, syncpt->id);
else
reset_threshold_interrupt(host, &syncpt->intr.wait_head,
syncpt->id);
spin_unlock(&syncpt->intr.lock);
run_handlers(completed);
return empty;
}
static void syncpt_thresh_work(struct work_struct *work)
{
struct host1x_syncpt_intr *syncpt_intr =
container_of(work, struct host1x_syncpt_intr, work);
struct host1x_syncpt *syncpt =
container_of(syncpt_intr, struct host1x_syncpt, intr);
unsigned int id = syncpt->id;
struct host1x *host = syncpt->host;
(void)process_wait_list(host, syncpt,
host1x_syncpt_load(host->syncpt + id));
}
int host1x_intr_add_action(struct host1x *host, u32 id, u32 thresh,
enum host1x_intr_action action, void *data,
struct host1x_waitlist *waiter, void **ref)
{
struct host1x_syncpt *syncpt;
int queue_was_empty;
if (waiter == NULL) {
pr_warn("%s: NULL waiter\n", __func__);
return -EINVAL;
}
INIT_LIST_HEAD(&waiter->list);
kref_init(&waiter->refcount);
if (ref)
kref_get(&waiter->refcount);
waiter->thresh = thresh;
waiter->action = action;
atomic_set(&waiter->state, WLS_PENDING);
waiter->data = data;
waiter->count = 1;
syncpt = host->syncpt + id;
spin_lock(&syncpt->intr.lock);
queue_was_empty = list_empty(&syncpt->intr.wait_head);
if (add_waiter_to_queue(waiter, &syncpt->intr.wait_head)) {
host1x_hw_intr_set_syncpt_threshold(host, id, thresh);
if (queue_was_empty)
host1x_hw_intr_enable_syncpt_intr(host, id);
}
spin_unlock(&syncpt->intr.lock);
if (ref)
*ref = waiter;
return 0;
}
void host1x_intr_put_ref(struct host1x *host, u32 id, void *ref)
{
struct host1x_waitlist *waiter = ref;
struct host1x_syncpt *syncpt;
while (atomic_cmpxchg(&waiter->state, WLS_PENDING, WLS_CANCELLED) ==
WLS_REMOVED)
schedule();
syncpt = host->syncpt + id;
(void)process_wait_list(host, syncpt,
host1x_syncpt_load(host->syncpt + id));
kref_put(&waiter->refcount, waiter_release);
}
int host1x_intr_init(struct host1x *host, unsigned int irq_sync)
{
unsigned int id;
u32 nb_pts = host1x_syncpt_nb_pts(host);
mutex_init(&host->intr_mutex);
host->intr_syncpt_irq = irq_sync;
host->intr_wq = create_workqueue("host_syncpt");
if (!host->intr_wq)
return -ENOMEM;
for (id = 0; id < nb_pts; ++id) {
struct host1x_syncpt *syncpt = host->syncpt + id;
spin_lock_init(&syncpt->intr.lock);
INIT_LIST_HEAD(&syncpt->intr.wait_head);
snprintf(syncpt->intr.thresh_irq_name,
sizeof(syncpt->intr.thresh_irq_name),
"host1x_sp_%02d", id);
}
host1x_intr_start(host);
return 0;
}
void host1x_intr_deinit(struct host1x *host)
{
host1x_intr_stop(host);
destroy_workqueue(host->intr_wq);
}
void host1x_intr_start(struct host1x *host)
{
u32 hz = clk_get_rate(host->clk);
int err;
mutex_lock(&host->intr_mutex);
err = host1x_hw_intr_init_host_sync(host, DIV_ROUND_UP(hz, 1000000),
syncpt_thresh_work);
if (err) {
mutex_unlock(&host->intr_mutex);
return;
}
mutex_unlock(&host->intr_mutex);
}
void host1x_intr_stop(struct host1x *host)
{
unsigned int id;
struct host1x_syncpt *syncpt = host->syncpt;
u32 nb_pts = host1x_syncpt_nb_pts(host);
mutex_lock(&host->intr_mutex);
host1x_hw_intr_disable_all_syncpt_intrs(host);
for (id = 0; id < nb_pts; ++id) {
struct host1x_waitlist *waiter, *next;
list_for_each_entry_safe(waiter, next,
&syncpt[id].intr.wait_head, list) {
if (atomic_cmpxchg(&waiter->state,
WLS_CANCELLED, WLS_HANDLED) == WLS_CANCELLED) {
list_del(&waiter->list);
kref_put(&waiter->refcount, waiter_release);
}
}
if (!list_empty(&syncpt[id].intr.wait_head)) {
mutex_unlock(&host->intr_mutex);
pr_warn("%s cannot stop syncpt intr id=%d\n",
__func__, id);
return;
}
}
host1x_hw_intr_free_syncpt_irq(host);
mutex_unlock(&host->intr_mutex);
}
