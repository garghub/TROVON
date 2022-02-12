struct drm_syncobj *drm_syncobj_find(struct drm_file *file_private,
u32 handle)
{
struct drm_syncobj *syncobj;
spin_lock(&file_private->syncobj_table_lock);
syncobj = idr_find(&file_private->syncobj_idr, handle);
if (syncobj)
drm_syncobj_get(syncobj);
spin_unlock(&file_private->syncobj_table_lock);
return syncobj;
}
static void drm_syncobj_add_callback_locked(struct drm_syncobj *syncobj,
struct drm_syncobj_cb *cb,
drm_syncobj_func_t func)
{
cb->func = func;
list_add_tail(&cb->node, &syncobj->cb_list);
}
static int drm_syncobj_fence_get_or_add_callback(struct drm_syncobj *syncobj,
struct dma_fence **fence,
struct drm_syncobj_cb *cb,
drm_syncobj_func_t func)
{
int ret;
*fence = drm_syncobj_fence_get(syncobj);
if (*fence)
return 1;
spin_lock(&syncobj->lock);
if (syncobj->fence) {
*fence = dma_fence_get(syncobj->fence);
ret = 1;
} else {
*fence = NULL;
drm_syncobj_add_callback_locked(syncobj, cb, func);
ret = 0;
}
spin_unlock(&syncobj->lock);
return ret;
}
void drm_syncobj_add_callback(struct drm_syncobj *syncobj,
struct drm_syncobj_cb *cb,
drm_syncobj_func_t func)
{
spin_lock(&syncobj->lock);
drm_syncobj_add_callback_locked(syncobj, cb, func);
spin_unlock(&syncobj->lock);
}
void drm_syncobj_remove_callback(struct drm_syncobj *syncobj,
struct drm_syncobj_cb *cb)
{
spin_lock(&syncobj->lock);
list_del_init(&cb->node);
spin_unlock(&syncobj->lock);
}
void drm_syncobj_replace_fence(struct drm_syncobj *syncobj,
struct dma_fence *fence)
{
struct dma_fence *old_fence;
struct drm_syncobj_cb *cur, *tmp;
if (fence)
dma_fence_get(fence);
spin_lock(&syncobj->lock);
old_fence = syncobj->fence;
syncobj->fence = fence;
if (fence != old_fence) {
list_for_each_entry_safe(cur, tmp, &syncobj->cb_list, node) {
list_del_init(&cur->node);
cur->func(syncobj, cur);
}
}
spin_unlock(&syncobj->lock);
dma_fence_put(old_fence);
}
static const char *drm_syncobj_null_fence_get_name(struct dma_fence *fence)
{
return "syncobjnull";
}
static bool drm_syncobj_null_fence_enable_signaling(struct dma_fence *fence)
{
dma_fence_enable_sw_signaling(fence);
return !dma_fence_is_signaled(fence);
}
static int drm_syncobj_assign_null_handle(struct drm_syncobj *syncobj)
{
struct drm_syncobj_null_fence *fence;
fence = kzalloc(sizeof(*fence), GFP_KERNEL);
if (fence == NULL)
return -ENOMEM;
spin_lock_init(&fence->lock);
dma_fence_init(&fence->base, &drm_syncobj_null_fence_ops,
&fence->lock, 0, 0);
dma_fence_signal(&fence->base);
drm_syncobj_replace_fence(syncobj, &fence->base);
dma_fence_put(&fence->base);
return 0;
}
int drm_syncobj_find_fence(struct drm_file *file_private,
u32 handle,
struct dma_fence **fence)
{
struct drm_syncobj *syncobj = drm_syncobj_find(file_private, handle);
int ret = 0;
if (!syncobj)
return -ENOENT;
*fence = drm_syncobj_fence_get(syncobj);
if (!*fence) {
ret = -EINVAL;
}
drm_syncobj_put(syncobj);
return ret;
}
void drm_syncobj_free(struct kref *kref)
{
struct drm_syncobj *syncobj = container_of(kref,
struct drm_syncobj,
refcount);
drm_syncobj_replace_fence(syncobj, NULL);
kfree(syncobj);
}
static int drm_syncobj_create(struct drm_file *file_private,
u32 *handle, uint32_t flags)
{
int ret;
struct drm_syncobj *syncobj;
syncobj = kzalloc(sizeof(struct drm_syncobj), GFP_KERNEL);
if (!syncobj)
return -ENOMEM;
kref_init(&syncobj->refcount);
INIT_LIST_HEAD(&syncobj->cb_list);
spin_lock_init(&syncobj->lock);
if (flags & DRM_SYNCOBJ_CREATE_SIGNALED) {
ret = drm_syncobj_assign_null_handle(syncobj);
if (ret < 0) {
drm_syncobj_put(syncobj);
return ret;
}
}
idr_preload(GFP_KERNEL);
spin_lock(&file_private->syncobj_table_lock);
ret = idr_alloc(&file_private->syncobj_idr, syncobj, 1, 0, GFP_NOWAIT);
spin_unlock(&file_private->syncobj_table_lock);
idr_preload_end();
if (ret < 0) {
drm_syncobj_put(syncobj);
return ret;
}
*handle = ret;
return 0;
}
static int drm_syncobj_destroy(struct drm_file *file_private,
u32 handle)
{
struct drm_syncobj *syncobj;
spin_lock(&file_private->syncobj_table_lock);
syncobj = idr_remove(&file_private->syncobj_idr, handle);
spin_unlock(&file_private->syncobj_table_lock);
if (!syncobj)
return -EINVAL;
drm_syncobj_put(syncobj);
return 0;
}
static int drm_syncobj_file_release(struct inode *inode, struct file *file)
{
struct drm_syncobj *syncobj = file->private_data;
drm_syncobj_put(syncobj);
return 0;
}
static int drm_syncobj_alloc_file(struct drm_syncobj *syncobj)
{
struct file *file = anon_inode_getfile("syncobj_file",
&drm_syncobj_file_fops,
syncobj, 0);
if (IS_ERR(file))
return PTR_ERR(file);
drm_syncobj_get(syncobj);
if (cmpxchg(&syncobj->file, NULL, file)) {
fput(file);
}
return 0;
}
static int drm_syncobj_handle_to_fd(struct drm_file *file_private,
u32 handle, int *p_fd)
{
struct drm_syncobj *syncobj = drm_syncobj_find(file_private, handle);
int ret;
int fd;
if (!syncobj)
return -EINVAL;
fd = get_unused_fd_flags(O_CLOEXEC);
if (fd < 0) {
drm_syncobj_put(syncobj);
return fd;
}
if (!syncobj->file) {
ret = drm_syncobj_alloc_file(syncobj);
if (ret)
goto out_put_fd;
}
fd_install(fd, syncobj->file);
drm_syncobj_put(syncobj);
*p_fd = fd;
return 0;
out_put_fd:
put_unused_fd(fd);
drm_syncobj_put(syncobj);
return ret;
}
static struct drm_syncobj *drm_syncobj_fdget(int fd)
{
struct file *file = fget(fd);
if (!file)
return NULL;
if (file->f_op != &drm_syncobj_file_fops)
goto err;
return file->private_data;
err:
fput(file);
return NULL;
}
static int drm_syncobj_fd_to_handle(struct drm_file *file_private,
int fd, u32 *handle)
{
struct drm_syncobj *syncobj = drm_syncobj_fdget(fd);
int ret;
if (!syncobj)
return -EINVAL;
drm_syncobj_get(syncobj);
idr_preload(GFP_KERNEL);
spin_lock(&file_private->syncobj_table_lock);
ret = idr_alloc(&file_private->syncobj_idr, syncobj, 1, 0, GFP_NOWAIT);
spin_unlock(&file_private->syncobj_table_lock);
idr_preload_end();
if (ret < 0) {
fput(syncobj->file);
return ret;
}
*handle = ret;
return 0;
}
int drm_syncobj_import_sync_file_fence(struct drm_file *file_private,
int fd, int handle)
{
struct dma_fence *fence = sync_file_get_fence(fd);
struct drm_syncobj *syncobj;
if (!fence)
return -EINVAL;
syncobj = drm_syncobj_find(file_private, handle);
if (!syncobj) {
dma_fence_put(fence);
return -ENOENT;
}
drm_syncobj_replace_fence(syncobj, fence);
dma_fence_put(fence);
drm_syncobj_put(syncobj);
return 0;
}
int drm_syncobj_export_sync_file(struct drm_file *file_private,
int handle, int *p_fd)
{
int ret;
struct dma_fence *fence;
struct sync_file *sync_file;
int fd = get_unused_fd_flags(O_CLOEXEC);
if (fd < 0)
return fd;
ret = drm_syncobj_find_fence(file_private, handle, &fence);
if (ret)
goto err_put_fd;
sync_file = sync_file_create(fence);
dma_fence_put(fence);
if (!sync_file) {
ret = -EINVAL;
goto err_put_fd;
}
fd_install(fd, sync_file->file);
*p_fd = fd;
return 0;
err_put_fd:
put_unused_fd(fd);
return ret;
}
void
drm_syncobj_open(struct drm_file *file_private)
{
idr_init(&file_private->syncobj_idr);
spin_lock_init(&file_private->syncobj_table_lock);
}
static int
drm_syncobj_release_handle(int id, void *ptr, void *data)
{
struct drm_syncobj *syncobj = ptr;
drm_syncobj_put(syncobj);
return 0;
}
void
drm_syncobj_release(struct drm_file *file_private)
{
idr_for_each(&file_private->syncobj_idr,
&drm_syncobj_release_handle, file_private);
idr_destroy(&file_private->syncobj_idr);
}
int
drm_syncobj_create_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_private)
{
struct drm_syncobj_create *args = data;
if (!drm_core_check_feature(dev, DRIVER_SYNCOBJ))
return -ENODEV;
if (args->flags & ~DRM_SYNCOBJ_CREATE_SIGNALED)
return -EINVAL;
return drm_syncobj_create(file_private,
&args->handle, args->flags);
}
int
drm_syncobj_destroy_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_private)
{
struct drm_syncobj_destroy *args = data;
if (!drm_core_check_feature(dev, DRIVER_SYNCOBJ))
return -ENODEV;
if (args->pad)
return -EINVAL;
return drm_syncobj_destroy(file_private, args->handle);
}
int
drm_syncobj_handle_to_fd_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_private)
{
struct drm_syncobj_handle *args = data;
if (!drm_core_check_feature(dev, DRIVER_SYNCOBJ))
return -ENODEV;
if (args->pad)
return -EINVAL;
if (args->flags != 0 &&
args->flags != DRM_SYNCOBJ_HANDLE_TO_FD_FLAGS_EXPORT_SYNC_FILE)
return -EINVAL;
if (args->flags & DRM_SYNCOBJ_HANDLE_TO_FD_FLAGS_EXPORT_SYNC_FILE)
return drm_syncobj_export_sync_file(file_private, args->handle,
&args->fd);
return drm_syncobj_handle_to_fd(file_private, args->handle,
&args->fd);
}
int
drm_syncobj_fd_to_handle_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_private)
{
struct drm_syncobj_handle *args = data;
if (!drm_core_check_feature(dev, DRIVER_SYNCOBJ))
return -ENODEV;
if (args->pad)
return -EINVAL;
if (args->flags != 0 &&
args->flags != DRM_SYNCOBJ_FD_TO_HANDLE_FLAGS_IMPORT_SYNC_FILE)
return -EINVAL;
if (args->flags & DRM_SYNCOBJ_FD_TO_HANDLE_FLAGS_IMPORT_SYNC_FILE)
return drm_syncobj_import_sync_file_fence(file_private,
args->fd,
args->handle);
return drm_syncobj_fd_to_handle(file_private, args->fd,
&args->handle);
}
static void syncobj_wait_fence_func(struct dma_fence *fence,
struct dma_fence_cb *cb)
{
struct syncobj_wait_entry *wait =
container_of(cb, struct syncobj_wait_entry, fence_cb);
wake_up_process(wait->task);
}
static void syncobj_wait_syncobj_func(struct drm_syncobj *syncobj,
struct drm_syncobj_cb *cb)
{
struct syncobj_wait_entry *wait =
container_of(cb, struct syncobj_wait_entry, syncobj_cb);
wait->fence = dma_fence_get(syncobj->fence);
wake_up_process(wait->task);
}
static signed long drm_syncobj_array_wait_timeout(struct drm_syncobj **syncobjs,
uint32_t count,
uint32_t flags,
signed long timeout,
uint32_t *idx)
{
struct syncobj_wait_entry *entries;
struct dma_fence *fence;
signed long ret;
uint32_t signaled_count, i;
entries = kcalloc(count, sizeof(*entries), GFP_KERNEL);
if (!entries)
return -ENOMEM;
signaled_count = 0;
for (i = 0; i < count; ++i) {
entries[i].task = current;
entries[i].fence = drm_syncobj_fence_get(syncobjs[i]);
if (!entries[i].fence) {
if (flags & DRM_SYNCOBJ_WAIT_FLAGS_WAIT_FOR_SUBMIT) {
continue;
} else {
ret = -EINVAL;
goto cleanup_entries;
}
}
if (dma_fence_is_signaled(entries[i].fence)) {
if (signaled_count == 0 && idx)
*idx = i;
signaled_count++;
}
}
ret = max_t(signed long, timeout, 1);
if (signaled_count == count ||
(signaled_count > 0 &&
!(flags & DRM_SYNCOBJ_WAIT_FLAGS_WAIT_ALL)))
goto cleanup_entries;
if (flags & DRM_SYNCOBJ_WAIT_FLAGS_WAIT_FOR_SUBMIT) {
for (i = 0; i < count; ++i) {
drm_syncobj_fence_get_or_add_callback(syncobjs[i],
&entries[i].fence,
&entries[i].syncobj_cb,
syncobj_wait_syncobj_func);
}
}
do {
set_current_state(TASK_INTERRUPTIBLE);
signaled_count = 0;
for (i = 0; i < count; ++i) {
fence = entries[i].fence;
if (!fence)
continue;
if (dma_fence_is_signaled(fence) ||
(!entries[i].fence_cb.func &&
dma_fence_add_callback(fence,
&entries[i].fence_cb,
syncobj_wait_fence_func))) {
if (flags & DRM_SYNCOBJ_WAIT_FLAGS_WAIT_ALL) {
signaled_count++;
} else {
if (idx)
*idx = i;
goto done_waiting;
}
}
}
if (signaled_count == count)
goto done_waiting;
if (timeout == 0) {
ret = 0;
goto done_waiting;
}
ret = schedule_timeout(ret);
if (ret > 0 && signal_pending(current))
ret = -ERESTARTSYS;
} while (ret > 0);
done_waiting:
__set_current_state(TASK_RUNNING);
cleanup_entries:
for (i = 0; i < count; ++i) {
if (entries[i].syncobj_cb.func)
drm_syncobj_remove_callback(syncobjs[i],
&entries[i].syncobj_cb);
if (entries[i].fence_cb.func)
dma_fence_remove_callback(entries[i].fence,
&entries[i].fence_cb);
dma_fence_put(entries[i].fence);
}
kfree(entries);
return ret;
}
static signed long drm_timeout_abs_to_jiffies(int64_t timeout_nsec)
{
ktime_t abs_timeout, now;
u64 timeout_ns, timeout_jiffies64;
if (timeout_nsec == 0)
return 0;
abs_timeout = ns_to_ktime(timeout_nsec);
now = ktime_get();
if (!ktime_after(abs_timeout, now))
return 0;
timeout_ns = ktime_to_ns(ktime_sub(abs_timeout, now));
timeout_jiffies64 = nsecs_to_jiffies64(timeout_ns);
if (timeout_jiffies64 >= MAX_SCHEDULE_TIMEOUT - 1)
return MAX_SCHEDULE_TIMEOUT - 1;
return timeout_jiffies64 + 1;
}
static int drm_syncobj_array_wait(struct drm_device *dev,
struct drm_file *file_private,
struct drm_syncobj_wait *wait,
struct drm_syncobj **syncobjs)
{
signed long timeout = drm_timeout_abs_to_jiffies(wait->timeout_nsec);
signed long ret = 0;
uint32_t first = ~0;
ret = drm_syncobj_array_wait_timeout(syncobjs,
wait->count_handles,
wait->flags,
timeout, &first);
if (ret < 0)
return ret;
wait->first_signaled = first;
if (ret == 0)
return -ETIME;
return 0;
}
static int drm_syncobj_array_find(struct drm_file *file_private,
void *user_handles, uint32_t count_handles,
struct drm_syncobj ***syncobjs_out)
{
uint32_t i, *handles;
struct drm_syncobj **syncobjs;
int ret;
handles = kmalloc_array(count_handles, sizeof(*handles), GFP_KERNEL);
if (handles == NULL)
return -ENOMEM;
if (copy_from_user(handles, user_handles,
sizeof(uint32_t) * count_handles)) {
ret = -EFAULT;
goto err_free_handles;
}
syncobjs = kmalloc_array(count_handles, sizeof(*syncobjs), GFP_KERNEL);
if (syncobjs == NULL) {
ret = -ENOMEM;
goto err_free_handles;
}
for (i = 0; i < count_handles; i++) {
syncobjs[i] = drm_syncobj_find(file_private, handles[i]);
if (!syncobjs[i]) {
ret = -ENOENT;
goto err_put_syncobjs;
}
}
kfree(handles);
*syncobjs_out = syncobjs;
return 0;
err_put_syncobjs:
while (i-- > 0)
drm_syncobj_put(syncobjs[i]);
kfree(syncobjs);
err_free_handles:
kfree(handles);
return ret;
}
static void drm_syncobj_array_free(struct drm_syncobj **syncobjs,
uint32_t count)
{
uint32_t i;
for (i = 0; i < count; i++)
drm_syncobj_put(syncobjs[i]);
kfree(syncobjs);
}
int
drm_syncobj_wait_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_private)
{
struct drm_syncobj_wait *args = data;
struct drm_syncobj **syncobjs;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_SYNCOBJ))
return -ENODEV;
if (args->flags & ~(DRM_SYNCOBJ_WAIT_FLAGS_WAIT_ALL |
DRM_SYNCOBJ_WAIT_FLAGS_WAIT_FOR_SUBMIT))
return -EINVAL;
if (args->count_handles == 0)
return -EINVAL;
ret = drm_syncobj_array_find(file_private,
u64_to_user_ptr(args->handles),
args->count_handles,
&syncobjs);
if (ret < 0)
return ret;
ret = drm_syncobj_array_wait(dev, file_private,
args, syncobjs);
drm_syncobj_array_free(syncobjs, args->count_handles);
return ret;
}
int
drm_syncobj_reset_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_private)
{
struct drm_syncobj_array *args = data;
struct drm_syncobj **syncobjs;
uint32_t i;
int ret;
if (!drm_core_check_feature(dev, DRIVER_SYNCOBJ))
return -ENODEV;
if (args->pad != 0)
return -EINVAL;
if (args->count_handles == 0)
return -EINVAL;
ret = drm_syncobj_array_find(file_private,
u64_to_user_ptr(args->handles),
args->count_handles,
&syncobjs);
if (ret < 0)
return ret;
for (i = 0; i < args->count_handles; i++)
drm_syncobj_replace_fence(syncobjs[i], NULL);
drm_syncobj_array_free(syncobjs, args->count_handles);
return 0;
}
int
drm_syncobj_signal_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_private)
{
struct drm_syncobj_array *args = data;
struct drm_syncobj **syncobjs;
uint32_t i;
int ret;
if (!drm_core_check_feature(dev, DRIVER_SYNCOBJ))
return -ENODEV;
if (args->pad != 0)
return -EINVAL;
if (args->count_handles == 0)
return -EINVAL;
ret = drm_syncobj_array_find(file_private,
u64_to_user_ptr(args->handles),
args->count_handles,
&syncobjs);
if (ret < 0)
return ret;
for (i = 0; i < args->count_handles; i++) {
ret = drm_syncobj_assign_null_handle(syncobjs[i]);
if (ret < 0)
break;
}
drm_syncobj_array_free(syncobjs, args->count_handles);
return ret;
}
