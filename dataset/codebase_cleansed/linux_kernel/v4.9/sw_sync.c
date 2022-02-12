static inline struct sync_pt *fence_to_sync_pt(struct fence *fence)
{
if (fence->ops != &timeline_fence_ops)
return NULL;
return container_of(fence, struct sync_pt, base);
}
struct sync_timeline *sync_timeline_create(const char *name)
{
struct sync_timeline *obj;
obj = kzalloc(sizeof(*obj), GFP_KERNEL);
if (!obj)
return NULL;
kref_init(&obj->kref);
obj->context = fence_context_alloc(1);
strlcpy(obj->name, name, sizeof(obj->name));
INIT_LIST_HEAD(&obj->child_list_head);
INIT_LIST_HEAD(&obj->active_list_head);
spin_lock_init(&obj->child_list_lock);
sync_timeline_debug_add(obj);
return obj;
}
static void sync_timeline_free(struct kref *kref)
{
struct sync_timeline *obj =
container_of(kref, struct sync_timeline, kref);
sync_timeline_debug_remove(obj);
kfree(obj);
}
static void sync_timeline_get(struct sync_timeline *obj)
{
kref_get(&obj->kref);
}
static void sync_timeline_put(struct sync_timeline *obj)
{
kref_put(&obj->kref, sync_timeline_free);
}
static void sync_timeline_signal(struct sync_timeline *obj, unsigned int inc)
{
unsigned long flags;
struct sync_pt *pt, *next;
trace_sync_timeline(obj);
spin_lock_irqsave(&obj->child_list_lock, flags);
obj->value += inc;
list_for_each_entry_safe(pt, next, &obj->active_list_head,
active_list) {
if (fence_is_signaled_locked(&pt->base))
list_del_init(&pt->active_list);
}
spin_unlock_irqrestore(&obj->child_list_lock, flags);
}
static struct sync_pt *sync_pt_create(struct sync_timeline *obj, int size,
unsigned int value)
{
unsigned long flags;
struct sync_pt *pt;
if (size < sizeof(*pt))
return NULL;
pt = kzalloc(size, GFP_KERNEL);
if (!pt)
return NULL;
spin_lock_irqsave(&obj->child_list_lock, flags);
sync_timeline_get(obj);
fence_init(&pt->base, &timeline_fence_ops, &obj->child_list_lock,
obj->context, value);
list_add_tail(&pt->child_list, &obj->child_list_head);
INIT_LIST_HEAD(&pt->active_list);
spin_unlock_irqrestore(&obj->child_list_lock, flags);
return pt;
}
static const char *timeline_fence_get_driver_name(struct fence *fence)
{
return "sw_sync";
}
static const char *timeline_fence_get_timeline_name(struct fence *fence)
{
struct sync_timeline *parent = fence_parent(fence);
return parent->name;
}
static void timeline_fence_release(struct fence *fence)
{
struct sync_pt *pt = fence_to_sync_pt(fence);
struct sync_timeline *parent = fence_parent(fence);
unsigned long flags;
spin_lock_irqsave(fence->lock, flags);
list_del(&pt->child_list);
if (!list_empty(&pt->active_list))
list_del(&pt->active_list);
spin_unlock_irqrestore(fence->lock, flags);
sync_timeline_put(parent);
fence_free(fence);
}
static bool timeline_fence_signaled(struct fence *fence)
{
struct sync_timeline *parent = fence_parent(fence);
return (fence->seqno > parent->value) ? false : true;
}
static bool timeline_fence_enable_signaling(struct fence *fence)
{
struct sync_pt *pt = fence_to_sync_pt(fence);
struct sync_timeline *parent = fence_parent(fence);
if (timeline_fence_signaled(fence))
return false;
list_add_tail(&pt->active_list, &parent->active_list_head);
return true;
}
static void timeline_fence_value_str(struct fence *fence,
char *str, int size)
{
snprintf(str, size, "%d", fence->seqno);
}
static void timeline_fence_timeline_value_str(struct fence *fence,
char *str, int size)
{
struct sync_timeline *parent = fence_parent(fence);
snprintf(str, size, "%d", parent->value);
}
static int sw_sync_debugfs_open(struct inode *inode, struct file *file)
{
struct sync_timeline *obj;
char task_comm[TASK_COMM_LEN];
get_task_comm(task_comm, current);
obj = sync_timeline_create(task_comm);
if (!obj)
return -ENOMEM;
file->private_data = obj;
return 0;
}
static int sw_sync_debugfs_release(struct inode *inode, struct file *file)
{
struct sync_timeline *obj = file->private_data;
smp_wmb();
sync_timeline_put(obj);
return 0;
}
static long sw_sync_ioctl_create_fence(struct sync_timeline *obj,
unsigned long arg)
{
int fd = get_unused_fd_flags(O_CLOEXEC);
int err;
struct sync_pt *pt;
struct sync_file *sync_file;
struct sw_sync_create_fence_data data;
if (fd < 0)
return fd;
if (copy_from_user(&data, (void __user *)arg, sizeof(data))) {
err = -EFAULT;
goto err;
}
pt = sync_pt_create(obj, sizeof(*pt), data.value);
if (!pt) {
err = -ENOMEM;
goto err;
}
sync_file = sync_file_create(&pt->base);
if (!sync_file) {
fence_put(&pt->base);
err = -ENOMEM;
goto err;
}
data.fence = fd;
if (copy_to_user((void __user *)arg, &data, sizeof(data))) {
fput(sync_file->file);
err = -EFAULT;
goto err;
}
fd_install(fd, sync_file->file);
return 0;
err:
put_unused_fd(fd);
return err;
}
static long sw_sync_ioctl_inc(struct sync_timeline *obj, unsigned long arg)
{
u32 value;
if (copy_from_user(&value, (void __user *)arg, sizeof(value)))
return -EFAULT;
sync_timeline_signal(obj, value);
return 0;
}
static long sw_sync_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct sync_timeline *obj = file->private_data;
switch (cmd) {
case SW_SYNC_IOC_CREATE_FENCE:
return sw_sync_ioctl_create_fence(obj, arg);
case SW_SYNC_IOC_INC:
return sw_sync_ioctl_inc(obj, arg);
default:
return -ENOTTY;
}
}
