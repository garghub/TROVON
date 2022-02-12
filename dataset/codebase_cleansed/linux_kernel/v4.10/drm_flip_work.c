struct drm_flip_task *drm_flip_work_allocate_task(void *data, gfp_t flags)
{
struct drm_flip_task *task;
task = kzalloc(sizeof(*task), flags);
if (task)
task->data = data;
return task;
}
void drm_flip_work_queue_task(struct drm_flip_work *work,
struct drm_flip_task *task)
{
unsigned long flags;
spin_lock_irqsave(&work->lock, flags);
list_add_tail(&task->node, &work->queued);
spin_unlock_irqrestore(&work->lock, flags);
}
void drm_flip_work_queue(struct drm_flip_work *work, void *val)
{
struct drm_flip_task *task;
task = drm_flip_work_allocate_task(val,
drm_can_sleep() ? GFP_KERNEL : GFP_ATOMIC);
if (task) {
drm_flip_work_queue_task(work, task);
} else {
DRM_ERROR("%s could not allocate task!\n", work->name);
work->func(work, val);
}
}
void drm_flip_work_commit(struct drm_flip_work *work,
struct workqueue_struct *wq)
{
unsigned long flags;
spin_lock_irqsave(&work->lock, flags);
list_splice_tail(&work->queued, &work->commited);
INIT_LIST_HEAD(&work->queued);
spin_unlock_irqrestore(&work->lock, flags);
queue_work(wq, &work->worker);
}
static void flip_worker(struct work_struct *w)
{
struct drm_flip_work *work = container_of(w, struct drm_flip_work, worker);
struct list_head tasks;
unsigned long flags;
while (1) {
struct drm_flip_task *task, *tmp;
INIT_LIST_HEAD(&tasks);
spin_lock_irqsave(&work->lock, flags);
list_splice_tail(&work->commited, &tasks);
INIT_LIST_HEAD(&work->commited);
spin_unlock_irqrestore(&work->lock, flags);
if (list_empty(&tasks))
break;
list_for_each_entry_safe(task, tmp, &tasks, node) {
work->func(work, task->data);
kfree(task);
}
}
}
void drm_flip_work_init(struct drm_flip_work *work,
const char *name, drm_flip_func_t func)
{
work->name = name;
INIT_LIST_HEAD(&work->queued);
INIT_LIST_HEAD(&work->commited);
spin_lock_init(&work->lock);
work->func = func;
INIT_WORK(&work->worker, flip_worker);
}
void drm_flip_work_cleanup(struct drm_flip_work *work)
{
WARN_ON(!list_empty(&work->queued) || !list_empty(&work->commited));
}
