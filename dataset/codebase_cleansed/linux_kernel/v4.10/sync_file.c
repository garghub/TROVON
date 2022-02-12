static struct sync_file *sync_file_alloc(void)
{
struct sync_file *sync_file;
sync_file = kzalloc(sizeof(*sync_file), GFP_KERNEL);
if (!sync_file)
return NULL;
sync_file->file = anon_inode_getfile("sync_file", &sync_file_fops,
sync_file, 0);
if (IS_ERR(sync_file->file))
goto err;
kref_init(&sync_file->kref);
init_waitqueue_head(&sync_file->wq);
INIT_LIST_HEAD(&sync_file->cb.node);
return sync_file;
err:
kfree(sync_file);
return NULL;
}
static void fence_check_cb_func(struct dma_fence *f, struct dma_fence_cb *cb)
{
struct sync_file *sync_file;
sync_file = container_of(cb, struct sync_file, cb);
wake_up_all(&sync_file->wq);
}
struct sync_file *sync_file_create(struct dma_fence *fence)
{
struct sync_file *sync_file;
sync_file = sync_file_alloc();
if (!sync_file)
return NULL;
sync_file->fence = dma_fence_get(fence);
snprintf(sync_file->name, sizeof(sync_file->name), "%s-%s%llu-%d",
fence->ops->get_driver_name(fence),
fence->ops->get_timeline_name(fence), fence->context,
fence->seqno);
return sync_file;
}
static struct sync_file *sync_file_fdget(int fd)
{
struct file *file = fget(fd);
if (!file)
return NULL;
if (file->f_op != &sync_file_fops)
goto err;
return file->private_data;
err:
fput(file);
return NULL;
}
struct dma_fence *sync_file_get_fence(int fd)
{
struct sync_file *sync_file;
struct dma_fence *fence;
sync_file = sync_file_fdget(fd);
if (!sync_file)
return NULL;
fence = dma_fence_get(sync_file->fence);
fput(sync_file->file);
return fence;
}
static int sync_file_set_fence(struct sync_file *sync_file,
struct dma_fence **fences, int num_fences)
{
struct dma_fence_array *array;
if (num_fences == 1) {
sync_file->fence = fences[0];
kfree(fences);
} else {
array = dma_fence_array_create(num_fences, fences,
dma_fence_context_alloc(1),
1, false);
if (!array)
return -ENOMEM;
sync_file->fence = &array->base;
}
return 0;
}
static struct dma_fence **get_fences(struct sync_file *sync_file,
int *num_fences)
{
if (dma_fence_is_array(sync_file->fence)) {
struct dma_fence_array *array = to_dma_fence_array(sync_file->fence);
*num_fences = array->num_fences;
return array->fences;
}
*num_fences = 1;
return &sync_file->fence;
}
static void add_fence(struct dma_fence **fences,
int *i, struct dma_fence *fence)
{
fences[*i] = fence;
if (!dma_fence_is_signaled(fence)) {
dma_fence_get(fence);
(*i)++;
}
}
static struct sync_file *sync_file_merge(const char *name, struct sync_file *a,
struct sync_file *b)
{
struct sync_file *sync_file;
struct dma_fence **fences, **nfences, **a_fences, **b_fences;
int i, i_a, i_b, num_fences, a_num_fences, b_num_fences;
sync_file = sync_file_alloc();
if (!sync_file)
return NULL;
a_fences = get_fences(a, &a_num_fences);
b_fences = get_fences(b, &b_num_fences);
if (a_num_fences > INT_MAX - b_num_fences)
return NULL;
num_fences = a_num_fences + b_num_fences;
fences = kcalloc(num_fences, sizeof(*fences), GFP_KERNEL);
if (!fences)
goto err;
for (i = i_a = i_b = 0; i_a < a_num_fences && i_b < b_num_fences; ) {
struct dma_fence *pt_a = a_fences[i_a];
struct dma_fence *pt_b = b_fences[i_b];
if (pt_a->context < pt_b->context) {
add_fence(fences, &i, pt_a);
i_a++;
} else if (pt_a->context > pt_b->context) {
add_fence(fences, &i, pt_b);
i_b++;
} else {
if (pt_a->seqno - pt_b->seqno <= INT_MAX)
add_fence(fences, &i, pt_a);
else
add_fence(fences, &i, pt_b);
i_a++;
i_b++;
}
}
for (; i_a < a_num_fences; i_a++)
add_fence(fences, &i, a_fences[i_a]);
for (; i_b < b_num_fences; i_b++)
add_fence(fences, &i, b_fences[i_b]);
if (i == 0)
fences[i++] = dma_fence_get(a_fences[0]);
if (num_fences > i) {
nfences = krealloc(fences, i * sizeof(*fences),
GFP_KERNEL);
if (!nfences)
goto err;
fences = nfences;
}
if (sync_file_set_fence(sync_file, fences, i) < 0) {
kfree(fences);
goto err;
}
strlcpy(sync_file->name, name, sizeof(sync_file->name));
return sync_file;
err:
fput(sync_file->file);
return NULL;
}
static void sync_file_free(struct kref *kref)
{
struct sync_file *sync_file = container_of(kref, struct sync_file,
kref);
if (test_bit(POLL_ENABLED, &sync_file->fence->flags))
dma_fence_remove_callback(sync_file->fence, &sync_file->cb);
dma_fence_put(sync_file->fence);
kfree(sync_file);
}
static int sync_file_release(struct inode *inode, struct file *file)
{
struct sync_file *sync_file = file->private_data;
kref_put(&sync_file->kref, sync_file_free);
return 0;
}
static unsigned int sync_file_poll(struct file *file, poll_table *wait)
{
struct sync_file *sync_file = file->private_data;
poll_wait(file, &sync_file->wq, wait);
if (!test_and_set_bit(POLL_ENABLED, &sync_file->fence->flags)) {
if (dma_fence_add_callback(sync_file->fence, &sync_file->cb,
fence_check_cb_func) < 0)
wake_up_all(&sync_file->wq);
}
return dma_fence_is_signaled(sync_file->fence) ? POLLIN : 0;
}
static long sync_file_ioctl_merge(struct sync_file *sync_file,
unsigned long arg)
{
int fd = get_unused_fd_flags(O_CLOEXEC);
int err;
struct sync_file *fence2, *fence3;
struct sync_merge_data data;
if (fd < 0)
return fd;
if (copy_from_user(&data, (void __user *)arg, sizeof(data))) {
err = -EFAULT;
goto err_put_fd;
}
if (data.flags || data.pad) {
err = -EINVAL;
goto err_put_fd;
}
fence2 = sync_file_fdget(data.fd2);
if (!fence2) {
err = -ENOENT;
goto err_put_fd;
}
data.name[sizeof(data.name) - 1] = '\0';
fence3 = sync_file_merge(data.name, sync_file, fence2);
if (!fence3) {
err = -ENOMEM;
goto err_put_fence2;
}
data.fence = fd;
if (copy_to_user((void __user *)arg, &data, sizeof(data))) {
err = -EFAULT;
goto err_put_fence3;
}
fd_install(fd, fence3->file);
fput(fence2->file);
return 0;
err_put_fence3:
fput(fence3->file);
err_put_fence2:
fput(fence2->file);
err_put_fd:
put_unused_fd(fd);
return err;
}
static void sync_fill_fence_info(struct dma_fence *fence,
struct sync_fence_info *info)
{
strlcpy(info->obj_name, fence->ops->get_timeline_name(fence),
sizeof(info->obj_name));
strlcpy(info->driver_name, fence->ops->get_driver_name(fence),
sizeof(info->driver_name));
if (dma_fence_is_signaled(fence))
info->status = fence->status >= 0 ? 1 : fence->status;
else
info->status = 0;
info->timestamp_ns = ktime_to_ns(fence->timestamp);
}
static long sync_file_ioctl_fence_info(struct sync_file *sync_file,
unsigned long arg)
{
struct sync_file_info info;
struct sync_fence_info *fence_info = NULL;
struct dma_fence **fences;
__u32 size;
int num_fences, ret, i;
if (copy_from_user(&info, (void __user *)arg, sizeof(info)))
return -EFAULT;
if (info.flags || info.pad)
return -EINVAL;
fences = get_fences(sync_file, &num_fences);
if (!info.num_fences)
goto no_fences;
if (info.num_fences < num_fences)
return -EINVAL;
size = num_fences * sizeof(*fence_info);
fence_info = kzalloc(size, GFP_KERNEL);
if (!fence_info)
return -ENOMEM;
for (i = 0; i < num_fences; i++)
sync_fill_fence_info(fences[i], &fence_info[i]);
if (copy_to_user(u64_to_user_ptr(info.sync_fence_info), fence_info,
size)) {
ret = -EFAULT;
goto out;
}
no_fences:
strlcpy(info.name, sync_file->name, sizeof(info.name));
info.status = dma_fence_is_signaled(sync_file->fence);
info.num_fences = num_fences;
if (copy_to_user((void __user *)arg, &info, sizeof(info)))
ret = -EFAULT;
else
ret = 0;
out:
kfree(fence_info);
return ret;
}
static long sync_file_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct sync_file *sync_file = file->private_data;
switch (cmd) {
case SYNC_IOC_MERGE:
return sync_file_ioctl_merge(sync_file, arg);
case SYNC_IOC_FILE_INFO:
return sync_file_ioctl_fence_info(sync_file, arg);
default:
return -ENOTTY;
}
}
