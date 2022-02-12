void drm_flip_work_queue(struct drm_flip_work *work, void *val)
{
if (kfifo_put(&work->fifo, (const void **)&val)) {
atomic_inc(&work->pending);
} else {
DRM_ERROR("%s fifo full!\n", work->name);
work->func(work, val);
}
}
void drm_flip_work_commit(struct drm_flip_work *work,
struct workqueue_struct *wq)
{
uint32_t pending = atomic_read(&work->pending);
atomic_add(pending, &work->count);
atomic_sub(pending, &work->pending);
queue_work(wq, &work->worker);
}
static void flip_worker(struct work_struct *w)
{
struct drm_flip_work *work = container_of(w, struct drm_flip_work, worker);
uint32_t count = atomic_read(&work->count);
void *val = NULL;
atomic_sub(count, &work->count);
while(count--)
if (!WARN_ON(!kfifo_get(&work->fifo, &val)))
work->func(work, val);
}
int drm_flip_work_init(struct drm_flip_work *work, int size,
const char *name, drm_flip_func_t func)
{
int ret;
work->name = name;
atomic_set(&work->count, 0);
atomic_set(&work->pending, 0);
work->func = func;
ret = kfifo_alloc(&work->fifo, size, GFP_KERNEL);
if (ret) {
DRM_ERROR("could not allocate %s fifo\n", name);
return ret;
}
INIT_WORK(&work->worker, flip_worker);
return 0;
}
void drm_flip_work_cleanup(struct drm_flip_work *work)
{
WARN_ON(!kfifo_is_empty(&work->fifo));
kfifo_free(&work->fifo);
}
