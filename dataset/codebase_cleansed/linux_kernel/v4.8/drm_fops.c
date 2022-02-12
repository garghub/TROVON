static int drm_setup(struct drm_device * dev)
{
int ret;
if (dev->driver->firstopen &&
!drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = dev->driver->firstopen(dev);
if (ret != 0)
return ret;
}
ret = drm_legacy_dma_setup(dev);
if (ret < 0)
return ret;
DRM_DEBUG("\n");
return 0;
}
int drm_open(struct inode *inode, struct file *filp)
{
struct drm_device *dev;
struct drm_minor *minor;
int retcode;
int need_setup = 0;
minor = drm_minor_acquire(iminor(inode));
if (IS_ERR(minor))
return PTR_ERR(minor);
dev = minor->dev;
if (!dev->open_count++)
need_setup = 1;
filp->f_mapping = dev->anon_inode->i_mapping;
retcode = drm_open_helper(filp, minor);
if (retcode)
goto err_undo;
if (need_setup) {
retcode = drm_setup(dev);
if (retcode)
goto err_undo;
}
return 0;
err_undo:
dev->open_count--;
drm_minor_release(minor);
return retcode;
}
static int drm_cpu_valid(void)
{
#if defined(__sparc__) && !defined(__sparc_v9__)
return 0;
#endif
return 1;
}
static int drm_open_helper(struct file *filp, struct drm_minor *minor)
{
struct drm_device *dev = minor->dev;
struct drm_file *priv;
int ret;
if (filp->f_flags & O_EXCL)
return -EBUSY;
if (!drm_cpu_valid())
return -EINVAL;
if (dev->switch_power_state != DRM_SWITCH_POWER_ON && dev->switch_power_state != DRM_SWITCH_POWER_DYNAMIC_OFF)
return -EINVAL;
DRM_DEBUG("pid = %d, minor = %d\n", task_pid_nr(current), minor->index);
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
filp->private_data = priv;
priv->filp = filp;
priv->uid = current_euid();
priv->pid = get_pid(task_pid(current));
priv->minor = minor;
priv->authenticated = capable(CAP_SYS_ADMIN);
priv->lock_count = 0;
INIT_LIST_HEAD(&priv->lhead);
INIT_LIST_HEAD(&priv->fbs);
mutex_init(&priv->fbs_lock);
INIT_LIST_HEAD(&priv->blobs);
INIT_LIST_HEAD(&priv->pending_event_list);
INIT_LIST_HEAD(&priv->event_list);
init_waitqueue_head(&priv->event_wait);
priv->event_space = 4096;
mutex_init(&priv->event_read_lock);
if (drm_core_check_feature(dev, DRIVER_GEM))
drm_gem_open(dev, priv);
if (drm_core_check_feature(dev, DRIVER_PRIME))
drm_prime_init_file_private(&priv->prime);
if (dev->driver->open) {
ret = dev->driver->open(dev, priv);
if (ret < 0)
goto out_prime_destroy;
}
if (drm_is_primary_client(priv)) {
ret = drm_master_open(priv);
if (ret)
goto out_close;
}
mutex_lock(&dev->filelist_mutex);
list_add(&priv->lhead, &dev->filelist);
mutex_unlock(&dev->filelist_mutex);
#ifdef __alpha__
if (!dev->hose) {
struct pci_dev *pci_dev;
pci_dev = pci_get_class(PCI_CLASS_DISPLAY_VGA << 8, NULL);
if (pci_dev) {
dev->hose = pci_dev->sysdata;
pci_dev_put(pci_dev);
}
if (!dev->hose) {
struct pci_bus *b = list_entry(pci_root_buses.next,
struct pci_bus, node);
if (b)
dev->hose = b->sysdata;
}
}
#endif
return 0;
out_close:
if (dev->driver->postclose)
dev->driver->postclose(dev, priv);
out_prime_destroy:
if (drm_core_check_feature(dev, DRIVER_PRIME))
drm_prime_destroy_file_private(&priv->prime);
if (drm_core_check_feature(dev, DRIVER_GEM))
drm_gem_release(dev, priv);
put_pid(priv->pid);
kfree(priv);
filp->private_data = NULL;
return ret;
}
static void drm_events_release(struct drm_file *file_priv)
{
struct drm_device *dev = file_priv->minor->dev;
struct drm_pending_event *e, *et;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
list_for_each_entry_safe(e, et, &file_priv->pending_event_list,
pending_link) {
list_del(&e->pending_link);
e->file_priv = NULL;
}
list_for_each_entry_safe(e, et, &file_priv->event_list, link) {
list_del(&e->link);
kfree(e);
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static void drm_legacy_dev_reinit(struct drm_device *dev)
{
if (dev->irq_enabled)
drm_irq_uninstall(dev);
mutex_lock(&dev->struct_mutex);
drm_legacy_agp_clear(dev);
drm_legacy_sg_cleanup(dev);
drm_legacy_vma_flush(dev);
drm_legacy_dma_takedown(dev);
mutex_unlock(&dev->struct_mutex);
dev->sigdata.lock = NULL;
dev->context_flag = 0;
dev->last_context = 0;
dev->if_version = 0;
DRM_DEBUG("lastclose completed\n");
}
void drm_lastclose(struct drm_device * dev)
{
DRM_DEBUG("\n");
if (dev->driver->lastclose)
dev->driver->lastclose(dev);
DRM_DEBUG("driver lastclose completed\n");
if (!drm_core_check_feature(dev, DRIVER_MODESET))
drm_legacy_dev_reinit(dev);
}
int drm_release(struct inode *inode, struct file *filp)
{
struct drm_file *file_priv = filp->private_data;
struct drm_minor *minor = file_priv->minor;
struct drm_device *dev = minor->dev;
mutex_lock(&drm_global_mutex);
DRM_DEBUG("open_count = %d\n", dev->open_count);
mutex_lock(&dev->filelist_mutex);
list_del(&file_priv->lhead);
mutex_unlock(&dev->filelist_mutex);
if (dev->driver->preclose)
dev->driver->preclose(dev, file_priv);
DRM_DEBUG("pid = %d, device = 0x%lx, open_count = %d\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->kdev->devt),
dev->open_count);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
drm_legacy_lock_release(dev, filp);
if (drm_core_check_feature(dev, DRIVER_HAVE_DMA))
drm_legacy_reclaim_buffers(dev, file_priv);
drm_events_release(file_priv);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
drm_fb_release(file_priv);
drm_property_destroy_user_blobs(dev, file_priv);
}
if (drm_core_check_feature(dev, DRIVER_GEM))
drm_gem_release(dev, file_priv);
drm_legacy_ctxbitmap_flush(dev, file_priv);
if (drm_is_primary_client(file_priv))
drm_master_release(file_priv);
if (dev->driver->postclose)
dev->driver->postclose(dev, file_priv);
if (drm_core_check_feature(dev, DRIVER_PRIME))
drm_prime_destroy_file_private(&file_priv->prime);
WARN_ON(!list_empty(&file_priv->event_list));
put_pid(file_priv->pid);
kfree(file_priv);
if (!--dev->open_count) {
drm_lastclose(dev);
if (drm_device_is_unplugged(dev))
drm_put_dev(dev);
}
mutex_unlock(&drm_global_mutex);
drm_minor_release(minor);
return 0;
}
ssize_t drm_read(struct file *filp, char __user *buffer,
size_t count, loff_t *offset)
{
struct drm_file *file_priv = filp->private_data;
struct drm_device *dev = file_priv->minor->dev;
ssize_t ret;
if (!access_ok(VERIFY_WRITE, buffer, count))
return -EFAULT;
ret = mutex_lock_interruptible(&file_priv->event_read_lock);
if (ret)
return ret;
for (;;) {
struct drm_pending_event *e = NULL;
spin_lock_irq(&dev->event_lock);
if (!list_empty(&file_priv->event_list)) {
e = list_first_entry(&file_priv->event_list,
struct drm_pending_event, link);
file_priv->event_space += e->event->length;
list_del(&e->link);
}
spin_unlock_irq(&dev->event_lock);
if (e == NULL) {
if (ret)
break;
if (filp->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
break;
}
mutex_unlock(&file_priv->event_read_lock);
ret = wait_event_interruptible(file_priv->event_wait,
!list_empty(&file_priv->event_list));
if (ret >= 0)
ret = mutex_lock_interruptible(&file_priv->event_read_lock);
if (ret)
return ret;
} else {
unsigned length = e->event->length;
if (length > count - ret) {
put_back_event:
spin_lock_irq(&dev->event_lock);
file_priv->event_space -= length;
list_add(&e->link, &file_priv->event_list);
spin_unlock_irq(&dev->event_lock);
break;
}
if (copy_to_user(buffer + ret, e->event, length)) {
if (ret == 0)
ret = -EFAULT;
goto put_back_event;
}
ret += length;
kfree(e);
}
}
mutex_unlock(&file_priv->event_read_lock);
return ret;
}
unsigned int drm_poll(struct file *filp, struct poll_table_struct *wait)
{
struct drm_file *file_priv = filp->private_data;
unsigned int mask = 0;
poll_wait(filp, &file_priv->event_wait, wait);
if (!list_empty(&file_priv->event_list))
mask |= POLLIN | POLLRDNORM;
return mask;
}
int drm_event_reserve_init_locked(struct drm_device *dev,
struct drm_file *file_priv,
struct drm_pending_event *p,
struct drm_event *e)
{
if (file_priv->event_space < e->length)
return -ENOMEM;
file_priv->event_space -= e->length;
p->event = e;
list_add(&p->pending_link, &file_priv->pending_event_list);
p->file_priv = file_priv;
return 0;
}
int drm_event_reserve_init(struct drm_device *dev,
struct drm_file *file_priv,
struct drm_pending_event *p,
struct drm_event *e)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&dev->event_lock, flags);
ret = drm_event_reserve_init_locked(dev, file_priv, p, e);
spin_unlock_irqrestore(&dev->event_lock, flags);
return ret;
}
void drm_event_cancel_free(struct drm_device *dev,
struct drm_pending_event *p)
{
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (p->file_priv) {
p->file_priv->event_space += p->event->length;
list_del(&p->pending_link);
}
spin_unlock_irqrestore(&dev->event_lock, flags);
kfree(p);
}
void drm_send_event_locked(struct drm_device *dev, struct drm_pending_event *e)
{
assert_spin_locked(&dev->event_lock);
if (e->completion) {
complete_all(e->completion);
e->completion = NULL;
}
if (e->fence) {
fence_signal(e->fence);
fence_put(e->fence);
}
if (!e->file_priv) {
kfree(e);
return;
}
list_del(&e->pending_link);
list_add_tail(&e->link,
&e->file_priv->event_list);
wake_up_interruptible(&e->file_priv->event_wait);
}
void drm_send_event(struct drm_device *dev, struct drm_pending_event *e)
{
unsigned long irqflags;
spin_lock_irqsave(&dev->event_lock, irqflags);
drm_send_event_locked(dev, e);
spin_unlock_irqrestore(&dev->event_lock, irqflags);
}
