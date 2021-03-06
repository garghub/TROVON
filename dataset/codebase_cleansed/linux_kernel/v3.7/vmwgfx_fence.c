static void vmw_fence_obj_destroy_locked(struct kref *kref)
{
struct vmw_fence_obj *fence =
container_of(kref, struct vmw_fence_obj, kref);
struct vmw_fence_manager *fman = fence->fman;
unsigned int num_fences;
list_del_init(&fence->head);
num_fences = --fman->num_fence_objects;
spin_unlock_irq(&fman->lock);
if (fence->destroy)
fence->destroy(fence);
else
kfree(fence);
spin_lock_irq(&fman->lock);
}
static void vmw_fence_work_func(struct work_struct *work)
{
struct vmw_fence_manager *fman =
container_of(work, struct vmw_fence_manager, work);
struct list_head list;
struct vmw_fence_action *action, *next_action;
bool seqno_valid;
do {
INIT_LIST_HEAD(&list);
mutex_lock(&fman->goal_irq_mutex);
spin_lock_irq(&fman->lock);
list_splice_init(&fman->cleanup_list, &list);
seqno_valid = fman->seqno_valid;
spin_unlock_irq(&fman->lock);
if (!seqno_valid && fman->goal_irq_on) {
fman->goal_irq_on = false;
vmw_goal_waiter_remove(fman->dev_priv);
}
mutex_unlock(&fman->goal_irq_mutex);
if (list_empty(&list))
return;
list_for_each_entry_safe(action, next_action, &list, head) {
list_del_init(&action->head);
if (action->cleanup)
action->cleanup(action);
}
} while (1);
}
struct vmw_fence_manager *vmw_fence_manager_init(struct vmw_private *dev_priv)
{
struct vmw_fence_manager *fman = kzalloc(sizeof(*fman), GFP_KERNEL);
if (unlikely(fman == NULL))
return NULL;
fman->dev_priv = dev_priv;
spin_lock_init(&fman->lock);
INIT_LIST_HEAD(&fman->fence_list);
INIT_LIST_HEAD(&fman->cleanup_list);
INIT_WORK(&fman->work, &vmw_fence_work_func);
fman->fifo_down = true;
fman->user_fence_size = ttm_round_pot(sizeof(struct vmw_user_fence));
fman->fence_size = ttm_round_pot(sizeof(struct vmw_fence_obj));
fman->event_fence_action_size =
ttm_round_pot(sizeof(struct vmw_event_fence_action));
mutex_init(&fman->goal_irq_mutex);
return fman;
}
void vmw_fence_manager_takedown(struct vmw_fence_manager *fman)
{
unsigned long irq_flags;
bool lists_empty;
(void) cancel_work_sync(&fman->work);
spin_lock_irqsave(&fman->lock, irq_flags);
lists_empty = list_empty(&fman->fence_list) &&
list_empty(&fman->cleanup_list);
spin_unlock_irqrestore(&fman->lock, irq_flags);
BUG_ON(!lists_empty);
kfree(fman);
}
static int vmw_fence_obj_init(struct vmw_fence_manager *fman,
struct vmw_fence_obj *fence,
u32 seqno,
uint32_t mask,
void (*destroy) (struct vmw_fence_obj *fence))
{
unsigned long irq_flags;
unsigned int num_fences;
int ret = 0;
fence->seqno = seqno;
INIT_LIST_HEAD(&fence->seq_passed_actions);
fence->fman = fman;
fence->signaled = 0;
fence->signal_mask = mask;
kref_init(&fence->kref);
fence->destroy = destroy;
init_waitqueue_head(&fence->queue);
spin_lock_irqsave(&fman->lock, irq_flags);
if (unlikely(fman->fifo_down)) {
ret = -EBUSY;
goto out_unlock;
}
list_add_tail(&fence->head, &fman->fence_list);
num_fences = ++fman->num_fence_objects;
out_unlock:
spin_unlock_irqrestore(&fman->lock, irq_flags);
return ret;
}
struct vmw_fence_obj *vmw_fence_obj_reference(struct vmw_fence_obj *fence)
{
if (unlikely(fence == NULL))
return NULL;
kref_get(&fence->kref);
return fence;
}
void vmw_fence_obj_unreference(struct vmw_fence_obj **fence_p)
{
struct vmw_fence_obj *fence = *fence_p;
struct vmw_fence_manager *fman;
if (unlikely(fence == NULL))
return;
fman = fence->fman;
*fence_p = NULL;
spin_lock_irq(&fman->lock);
BUG_ON(atomic_read(&fence->kref.refcount) == 0);
kref_put(&fence->kref, vmw_fence_obj_destroy_locked);
spin_unlock_irq(&fman->lock);
}
void vmw_fences_perform_actions(struct vmw_fence_manager *fman,
struct list_head *list)
{
struct vmw_fence_action *action, *next_action;
list_for_each_entry_safe(action, next_action, list, head) {
list_del_init(&action->head);
fman->pending_actions[action->type]--;
if (action->seq_passed != NULL)
action->seq_passed(action);
list_add_tail(&action->head, &fman->cleanup_list);
}
}
static bool vmw_fence_goal_new_locked(struct vmw_fence_manager *fman,
u32 passed_seqno)
{
u32 goal_seqno;
__le32 __iomem *fifo_mem;
struct vmw_fence_obj *fence;
if (likely(!fman->seqno_valid))
return false;
fifo_mem = fman->dev_priv->mmio_virt;
goal_seqno = ioread32(fifo_mem + SVGA_FIFO_FENCE_GOAL);
if (likely(passed_seqno - goal_seqno >= VMW_FENCE_WRAP))
return false;
fman->seqno_valid = false;
list_for_each_entry(fence, &fman->fence_list, head) {
if (!list_empty(&fence->seq_passed_actions)) {
fman->seqno_valid = true;
iowrite32(fence->seqno,
fifo_mem + SVGA_FIFO_FENCE_GOAL);
break;
}
}
return true;
}
static bool vmw_fence_goal_check_locked(struct vmw_fence_obj *fence)
{
u32 goal_seqno;
__le32 __iomem *fifo_mem;
if (fence->signaled & DRM_VMW_FENCE_FLAG_EXEC)
return false;
fifo_mem = fence->fman->dev_priv->mmio_virt;
goal_seqno = ioread32(fifo_mem + SVGA_FIFO_FENCE_GOAL);
if (likely(fence->fman->seqno_valid &&
goal_seqno - fence->seqno < VMW_FENCE_WRAP))
return false;
iowrite32(fence->seqno, fifo_mem + SVGA_FIFO_FENCE_GOAL);
fence->fman->seqno_valid = true;
return true;
}
void vmw_fences_update(struct vmw_fence_manager *fman)
{
unsigned long flags;
struct vmw_fence_obj *fence, *next_fence;
struct list_head action_list;
bool needs_rerun;
uint32_t seqno, new_seqno;
__le32 __iomem *fifo_mem = fman->dev_priv->mmio_virt;
seqno = ioread32(fifo_mem + SVGA_FIFO_FENCE);
rerun:
spin_lock_irqsave(&fman->lock, flags);
list_for_each_entry_safe(fence, next_fence, &fman->fence_list, head) {
if (seqno - fence->seqno < VMW_FENCE_WRAP) {
list_del_init(&fence->head);
fence->signaled |= DRM_VMW_FENCE_FLAG_EXEC;
INIT_LIST_HEAD(&action_list);
list_splice_init(&fence->seq_passed_actions,
&action_list);
vmw_fences_perform_actions(fman, &action_list);
wake_up_all(&fence->queue);
} else
break;
}
needs_rerun = vmw_fence_goal_new_locked(fman, seqno);
if (!list_empty(&fman->cleanup_list))
(void) schedule_work(&fman->work);
spin_unlock_irqrestore(&fman->lock, flags);
if (unlikely(needs_rerun)) {
new_seqno = ioread32(fifo_mem + SVGA_FIFO_FENCE);
if (new_seqno != seqno) {
seqno = new_seqno;
goto rerun;
}
}
}
bool vmw_fence_obj_signaled(struct vmw_fence_obj *fence,
uint32_t flags)
{
struct vmw_fence_manager *fman = fence->fman;
unsigned long irq_flags;
uint32_t signaled;
spin_lock_irqsave(&fman->lock, irq_flags);
signaled = fence->signaled;
spin_unlock_irqrestore(&fman->lock, irq_flags);
flags &= fence->signal_mask;
if ((signaled & flags) == flags)
return 1;
if ((signaled & DRM_VMW_FENCE_FLAG_EXEC) == 0)
vmw_fences_update(fman);
spin_lock_irqsave(&fman->lock, irq_flags);
signaled = fence->signaled;
spin_unlock_irqrestore(&fman->lock, irq_flags);
return ((signaled & flags) == flags);
}
int vmw_fence_obj_wait(struct vmw_fence_obj *fence,
uint32_t flags, bool lazy,
bool interruptible, unsigned long timeout)
{
struct vmw_private *dev_priv = fence->fman->dev_priv;
long ret;
if (likely(vmw_fence_obj_signaled(fence, flags)))
return 0;
vmw_fifo_ping_host(dev_priv, SVGA_SYNC_GENERIC);
vmw_seqno_waiter_add(dev_priv);
if (interruptible)
ret = wait_event_interruptible_timeout
(fence->queue,
vmw_fence_obj_signaled(fence, flags),
timeout);
else
ret = wait_event_timeout
(fence->queue,
vmw_fence_obj_signaled(fence, flags),
timeout);
vmw_seqno_waiter_remove(dev_priv);
if (unlikely(ret == 0))
ret = -EBUSY;
else if (likely(ret > 0))
ret = 0;
return ret;
}
void vmw_fence_obj_flush(struct vmw_fence_obj *fence)
{
struct vmw_private *dev_priv = fence->fman->dev_priv;
vmw_fifo_ping_host(dev_priv, SVGA_SYNC_GENERIC);
}
static void vmw_fence_destroy(struct vmw_fence_obj *fence)
{
struct vmw_fence_manager *fman = fence->fman;
kfree(fence);
ttm_mem_global_free(vmw_mem_glob(fman->dev_priv),
fman->fence_size);
}
int vmw_fence_create(struct vmw_fence_manager *fman,
uint32_t seqno,
uint32_t mask,
struct vmw_fence_obj **p_fence)
{
struct ttm_mem_global *mem_glob = vmw_mem_glob(fman->dev_priv);
struct vmw_fence_obj *fence;
int ret;
ret = ttm_mem_global_alloc(mem_glob, fman->fence_size,
false, false);
if (unlikely(ret != 0))
return ret;
fence = kzalloc(sizeof(*fence), GFP_KERNEL);
if (unlikely(fence == NULL)) {
ret = -ENOMEM;
goto out_no_object;
}
ret = vmw_fence_obj_init(fman, fence, seqno, mask,
vmw_fence_destroy);
if (unlikely(ret != 0))
goto out_err_init;
*p_fence = fence;
return 0;
out_err_init:
kfree(fence);
out_no_object:
ttm_mem_global_free(mem_glob, fman->fence_size);
return ret;
}
static void vmw_user_fence_destroy(struct vmw_fence_obj *fence)
{
struct vmw_user_fence *ufence =
container_of(fence, struct vmw_user_fence, fence);
struct vmw_fence_manager *fman = fence->fman;
kfree(ufence);
ttm_mem_global_free(vmw_mem_glob(fman->dev_priv),
fman->user_fence_size);
}
static void vmw_user_fence_base_release(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
struct vmw_user_fence *ufence =
container_of(base, struct vmw_user_fence, base);
struct vmw_fence_obj *fence = &ufence->fence;
*p_base = NULL;
vmw_fence_obj_unreference(&fence);
}
int vmw_user_fence_create(struct drm_file *file_priv,
struct vmw_fence_manager *fman,
uint32_t seqno,
uint32_t mask,
struct vmw_fence_obj **p_fence,
uint32_t *p_handle)
{
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_user_fence *ufence;
struct vmw_fence_obj *tmp;
struct ttm_mem_global *mem_glob = vmw_mem_glob(fman->dev_priv);
int ret;
ret = ttm_mem_global_alloc(mem_glob, fman->user_fence_size,
false, false);
if (unlikely(ret != 0))
return ret;
ufence = kzalloc(sizeof(*ufence), GFP_KERNEL);
if (unlikely(ufence == NULL)) {
ret = -ENOMEM;
goto out_no_object;
}
ret = vmw_fence_obj_init(fman, &ufence->fence, seqno,
mask, vmw_user_fence_destroy);
if (unlikely(ret != 0)) {
kfree(ufence);
goto out_no_object;
}
tmp = vmw_fence_obj_reference(&ufence->fence);
ret = ttm_base_object_init(tfile, &ufence->base, false,
VMW_RES_FENCE,
&vmw_user_fence_base_release, NULL);
if (unlikely(ret != 0)) {
vmw_fence_obj_unreference(&tmp);
goto out_err;
}
*p_fence = &ufence->fence;
*p_handle = ufence->base.hash.key;
return 0;
out_err:
tmp = &ufence->fence;
vmw_fence_obj_unreference(&tmp);
out_no_object:
ttm_mem_global_free(mem_glob, fman->user_fence_size);
return ret;
}
void vmw_fence_fifo_down(struct vmw_fence_manager *fman)
{
unsigned long irq_flags;
struct list_head action_list;
int ret;
spin_lock_irqsave(&fman->lock, irq_flags);
fman->fifo_down = true;
while (!list_empty(&fman->fence_list)) {
struct vmw_fence_obj *fence =
list_entry(fman->fence_list.prev, struct vmw_fence_obj,
head);
kref_get(&fence->kref);
spin_unlock_irq(&fman->lock);
ret = vmw_fence_obj_wait(fence, fence->signal_mask,
false, false,
VMW_FENCE_WAIT_TIMEOUT);
if (unlikely(ret != 0)) {
list_del_init(&fence->head);
fence->signaled |= DRM_VMW_FENCE_FLAG_EXEC;
INIT_LIST_HEAD(&action_list);
list_splice_init(&fence->seq_passed_actions,
&action_list);
vmw_fences_perform_actions(fman, &action_list);
wake_up_all(&fence->queue);
}
spin_lock_irq(&fman->lock);
BUG_ON(!list_empty(&fence->head));
kref_put(&fence->kref, vmw_fence_obj_destroy_locked);
}
spin_unlock_irqrestore(&fman->lock, irq_flags);
}
void vmw_fence_fifo_up(struct vmw_fence_manager *fman)
{
unsigned long irq_flags;
spin_lock_irqsave(&fman->lock, irq_flags);
fman->fifo_down = false;
spin_unlock_irqrestore(&fman->lock, irq_flags);
}
int vmw_fence_obj_wait_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_fence_wait_arg *arg =
(struct drm_vmw_fence_wait_arg *)data;
unsigned long timeout;
struct ttm_base_object *base;
struct vmw_fence_obj *fence;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
int ret;
uint64_t wait_timeout = ((uint64_t)arg->timeout_us * HZ);
wait_timeout = (wait_timeout >> 20) + (wait_timeout >> 24) -
(wait_timeout >> 26);
if (!arg->cookie_valid) {
arg->cookie_valid = 1;
arg->kernel_cookie = jiffies + wait_timeout;
}
base = ttm_base_object_lookup(tfile, arg->handle);
if (unlikely(base == NULL)) {
printk(KERN_ERR "Wait invalid fence object handle "
"0x%08lx.\n",
(unsigned long)arg->handle);
return -EINVAL;
}
fence = &(container_of(base, struct vmw_user_fence, base)->fence);
timeout = jiffies;
if (time_after_eq(timeout, (unsigned long)arg->kernel_cookie)) {
ret = ((vmw_fence_obj_signaled(fence, arg->flags)) ?
0 : -EBUSY);
goto out;
}
timeout = (unsigned long)arg->kernel_cookie - timeout;
ret = vmw_fence_obj_wait(fence, arg->flags, arg->lazy, true, timeout);
out:
ttm_base_object_unref(&base);
if (ret == 0 && (arg->wait_options & DRM_VMW_WAIT_OPTION_UNREF))
return ttm_ref_object_base_unref(tfile, arg->handle,
TTM_REF_USAGE);
return ret;
}
int vmw_fence_obj_signaled_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_fence_signaled_arg *arg =
(struct drm_vmw_fence_signaled_arg *) data;
struct ttm_base_object *base;
struct vmw_fence_obj *fence;
struct vmw_fence_manager *fman;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_private *dev_priv = vmw_priv(dev);
base = ttm_base_object_lookup(tfile, arg->handle);
if (unlikely(base == NULL)) {
printk(KERN_ERR "Fence signaled invalid fence object handle "
"0x%08lx.\n",
(unsigned long)arg->handle);
return -EINVAL;
}
fence = &(container_of(base, struct vmw_user_fence, base)->fence);
fman = fence->fman;
arg->signaled = vmw_fence_obj_signaled(fence, arg->flags);
spin_lock_irq(&fman->lock);
arg->signaled_flags = fence->signaled;
arg->passed_seqno = dev_priv->last_read_seqno;
spin_unlock_irq(&fman->lock);
ttm_base_object_unref(&base);
return 0;
}
int vmw_fence_obj_unref_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_fence_arg *arg =
(struct drm_vmw_fence_arg *) data;
return ttm_ref_object_base_unref(vmw_fpriv(file_priv)->tfile,
arg->handle,
TTM_REF_USAGE);
}
void vmw_event_fence_fpriv_gone(struct vmw_fence_manager *fman,
struct list_head *event_list)
{
struct vmw_event_fence_action *eaction;
struct drm_pending_event *event;
unsigned long irq_flags;
while (1) {
spin_lock_irqsave(&fman->lock, irq_flags);
if (list_empty(event_list))
goto out_unlock;
eaction = list_first_entry(event_list,
struct vmw_event_fence_action,
fpriv_head);
list_del_init(&eaction->fpriv_head);
event = eaction->event;
eaction->event = NULL;
spin_unlock_irqrestore(&fman->lock, irq_flags);
event->destroy(event);
}
out_unlock:
spin_unlock_irqrestore(&fman->lock, irq_flags);
}
static void vmw_event_fence_action_seq_passed(struct vmw_fence_action *action)
{
struct vmw_event_fence_action *eaction =
container_of(action, struct vmw_event_fence_action, action);
struct drm_device *dev = eaction->dev;
struct drm_pending_event *event = eaction->event;
struct drm_file *file_priv;
unsigned long irq_flags;
if (unlikely(event == NULL))
return;
file_priv = event->file_priv;
spin_lock_irqsave(&dev->event_lock, irq_flags);
if (likely(eaction->tv_sec != NULL)) {
struct timeval tv;
do_gettimeofday(&tv);
*eaction->tv_sec = tv.tv_sec;
*eaction->tv_usec = tv.tv_usec;
}
list_del_init(&eaction->fpriv_head);
list_add_tail(&eaction->event->link, &file_priv->event_list);
eaction->event = NULL;
wake_up_all(&file_priv->event_wait);
spin_unlock_irqrestore(&dev->event_lock, irq_flags);
}
static void vmw_event_fence_action_cleanup(struct vmw_fence_action *action)
{
struct vmw_event_fence_action *eaction =
container_of(action, struct vmw_event_fence_action, action);
struct vmw_fence_manager *fman = eaction->fence->fman;
unsigned long irq_flags;
spin_lock_irqsave(&fman->lock, irq_flags);
list_del(&eaction->fpriv_head);
spin_unlock_irqrestore(&fman->lock, irq_flags);
vmw_fence_obj_unreference(&eaction->fence);
kfree(eaction);
}
void vmw_fence_obj_add_action(struct vmw_fence_obj *fence,
struct vmw_fence_action *action)
{
struct vmw_fence_manager *fman = fence->fman;
unsigned long irq_flags;
bool run_update = false;
mutex_lock(&fman->goal_irq_mutex);
spin_lock_irqsave(&fman->lock, irq_flags);
fman->pending_actions[action->type]++;
if (fence->signaled & DRM_VMW_FENCE_FLAG_EXEC) {
struct list_head action_list;
INIT_LIST_HEAD(&action_list);
list_add_tail(&action->head, &action_list);
vmw_fences_perform_actions(fman, &action_list);
} else {
list_add_tail(&action->head, &fence->seq_passed_actions);
run_update = vmw_fence_goal_check_locked(fence);
}
spin_unlock_irqrestore(&fman->lock, irq_flags);
if (run_update) {
if (!fman->goal_irq_on) {
fman->goal_irq_on = true;
vmw_goal_waiter_add(fman->dev_priv);
}
vmw_fences_update(fman);
}
mutex_unlock(&fman->goal_irq_mutex);
}
int vmw_event_fence_action_queue(struct drm_file *file_priv,
struct vmw_fence_obj *fence,
struct drm_pending_event *event,
uint32_t *tv_sec,
uint32_t *tv_usec,
bool interruptible)
{
struct vmw_event_fence_action *eaction;
struct vmw_fence_manager *fman = fence->fman;
struct vmw_fpriv *vmw_fp = vmw_fpriv(file_priv);
unsigned long irq_flags;
eaction = kzalloc(sizeof(*eaction), GFP_KERNEL);
if (unlikely(eaction == NULL))
return -ENOMEM;
eaction->event = event;
eaction->action.seq_passed = vmw_event_fence_action_seq_passed;
eaction->action.cleanup = vmw_event_fence_action_cleanup;
eaction->action.type = VMW_ACTION_EVENT;
eaction->fence = vmw_fence_obj_reference(fence);
eaction->dev = fman->dev_priv->dev;
eaction->tv_sec = tv_sec;
eaction->tv_usec = tv_usec;
spin_lock_irqsave(&fman->lock, irq_flags);
list_add_tail(&eaction->fpriv_head, &vmw_fp->fence_events);
spin_unlock_irqrestore(&fman->lock, irq_flags);
vmw_fence_obj_add_action(fence, &eaction->action);
return 0;
}
int vmw_event_fence_action_create(struct drm_file *file_priv,
struct vmw_fence_obj *fence,
uint32_t flags,
uint64_t user_data,
bool interruptible)
{
struct vmw_event_fence_pending *event;
struct drm_device *dev = fence->fman->dev_priv->dev;
unsigned long irq_flags;
int ret;
spin_lock_irqsave(&dev->event_lock, irq_flags);
ret = (file_priv->event_space < sizeof(event->event)) ? -EBUSY : 0;
if (likely(ret == 0))
file_priv->event_space -= sizeof(event->event);
spin_unlock_irqrestore(&dev->event_lock, irq_flags);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to allocate event space for this file.\n");
goto out_no_space;
}
event = kzalloc(sizeof(*event), GFP_KERNEL);
if (unlikely(event == NULL)) {
DRM_ERROR("Failed to allocate an event.\n");
ret = -ENOMEM;
goto out_no_event;
}
event->event.base.type = DRM_VMW_EVENT_FENCE_SIGNALED;
event->event.base.length = sizeof(*event);
event->event.user_data = user_data;
event->base.event = &event->event.base;
event->base.file_priv = file_priv;
event->base.destroy = (void (*) (struct drm_pending_event *)) kfree;
if (flags & DRM_VMW_FE_FLAG_REQ_TIME)
ret = vmw_event_fence_action_queue(file_priv, fence,
&event->base,
&event->event.tv_sec,
&event->event.tv_usec,
interruptible);
else
ret = vmw_event_fence_action_queue(file_priv, fence,
&event->base,
NULL,
NULL,
interruptible);
if (ret != 0)
goto out_no_queue;
out_no_queue:
event->base.destroy(&event->base);
out_no_event:
spin_lock_irqsave(&dev->event_lock, irq_flags);
file_priv->event_space += sizeof(*event);
spin_unlock_irqrestore(&dev->event_lock, irq_flags);
out_no_space:
return ret;
}
int vmw_fence_event_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_fence_event_arg *arg =
(struct drm_vmw_fence_event_arg *) data;
struct vmw_fence_obj *fence = NULL;
struct vmw_fpriv *vmw_fp = vmw_fpriv(file_priv);
struct drm_vmw_fence_rep __user *user_fence_rep =
(struct drm_vmw_fence_rep __user *)(unsigned long)
arg->fence_rep;
uint32_t handle;
int ret;
if (arg->handle) {
struct ttm_base_object *base =
ttm_base_object_lookup(vmw_fp->tfile, arg->handle);
if (unlikely(base == NULL)) {
DRM_ERROR("Fence event invalid fence object handle "
"0x%08lx.\n",
(unsigned long)arg->handle);
return -EINVAL;
}
fence = &(container_of(base, struct vmw_user_fence,
base)->fence);
(void) vmw_fence_obj_reference(fence);
if (user_fence_rep != NULL) {
bool existed;
ret = ttm_ref_object_add(vmw_fp->tfile, base,
TTM_REF_USAGE, &existed);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to reference a fence "
"object.\n");
goto out_no_ref_obj;
}
handle = base->hash.key;
}
ttm_base_object_unref(&base);
}
if (!fence) {
ret = vmw_execbuf_fence_commands(file_priv, dev_priv,
&fence,
(user_fence_rep) ?
&handle : NULL);
if (unlikely(ret != 0)) {
DRM_ERROR("Fence event failed to create fence.\n");
return ret;
}
}
BUG_ON(fence == NULL);
if (arg->flags & DRM_VMW_FE_FLAG_REQ_TIME)
ret = vmw_event_fence_action_create(file_priv, fence,
arg->flags,
arg->user_data,
true);
else
ret = vmw_event_fence_action_create(file_priv, fence,
arg->flags,
arg->user_data,
true);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Failed to attach event to fence.\n");
goto out_no_create;
}
vmw_execbuf_copy_fence_user(dev_priv, vmw_fp, 0, user_fence_rep, fence,
handle);
vmw_fence_obj_unreference(&fence);
return 0;
out_no_create:
if (user_fence_rep != NULL)
ttm_ref_object_base_unref(vmw_fpriv(file_priv)->tfile,
handle, TTM_REF_USAGE);
out_no_ref_obj:
vmw_fence_obj_unreference(&fence);
return ret;
}
