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
struct drm_device *dev = NULL;
int minor_id = iminor(inode);
struct drm_minor *minor;
int retcode = 0;
int need_setup = 0;
struct address_space *old_mapping;
struct address_space *old_imapping;
minor = idr_find(&drm_minors_idr, minor_id);
if (!minor)
return -ENODEV;
if (!(dev = minor->dev))
return -ENODEV;
if (drm_device_is_unplugged(dev))
return -ENODEV;
if (!dev->open_count++)
need_setup = 1;
mutex_lock(&dev->struct_mutex);
old_imapping = inode->i_mapping;
old_mapping = dev->dev_mapping;
if (old_mapping == NULL)
dev->dev_mapping = &inode->i_data;
ihold(container_of(dev->dev_mapping, struct inode, i_data));
inode->i_mapping = dev->dev_mapping;
filp->f_mapping = dev->dev_mapping;
mutex_unlock(&dev->struct_mutex);
retcode = drm_open_helper(inode, filp, dev);
if (retcode)
goto err_undo;
if (need_setup) {
retcode = drm_setup(dev);
if (retcode)
goto err_undo;
}
return 0;
err_undo:
mutex_lock(&dev->struct_mutex);
filp->f_mapping = old_imapping;
inode->i_mapping = old_imapping;
iput(container_of(dev->dev_mapping, struct inode, i_data));
dev->dev_mapping = old_mapping;
mutex_unlock(&dev->struct_mutex);
dev->open_count--;
return retcode;
}
int drm_stub_open(struct inode *inode, struct file *filp)
{
struct drm_device *dev = NULL;
struct drm_minor *minor;
int minor_id = iminor(inode);
int err = -ENODEV;
const struct file_operations *new_fops;
DRM_DEBUG("\n");
mutex_lock(&drm_global_mutex);
minor = idr_find(&drm_minors_idr, minor_id);
if (!minor)
goto out;
if (!(dev = minor->dev))
goto out;
if (drm_device_is_unplugged(dev))
goto out;
new_fops = fops_get(dev->driver->fops);
if (!new_fops)
goto out;
replace_fops(filp, new_fops);
if (filp->f_op->open)
err = filp->f_op->open(inode, filp);
out:
mutex_unlock(&drm_global_mutex);
return err;
}
static int drm_cpu_valid(void)
{
#if defined(__i386__)
if (boot_cpu_data.x86 == 3)
return 0;
#endif
#if defined(__sparc__) && !defined(__sparc_v9__)
return 0;
#endif
return 1;
}
static int drm_open_helper(struct inode *inode, struct file *filp,
struct drm_device * dev)
{
int minor_id = iminor(inode);
struct drm_file *priv;
int ret;
if (filp->f_flags & O_EXCL)
return -EBUSY;
if (!drm_cpu_valid())
return -EINVAL;
if (dev->switch_power_state != DRM_SWITCH_POWER_ON && dev->switch_power_state != DRM_SWITCH_POWER_DYNAMIC_OFF)
return -EINVAL;
DRM_DEBUG("pid = %d, minor = %d\n", task_pid_nr(current), minor_id);
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
filp->private_data = priv;
priv->filp = filp;
priv->uid = current_euid();
priv->pid = get_pid(task_pid(current));
priv->minor = idr_find(&drm_minors_idr, minor_id);
if (!priv->minor) {
ret = -ENODEV;
goto out_put_pid;
}
priv->ioctl_count = 0;
priv->always_authenticated = capable(CAP_SYS_ADMIN);
priv->authenticated = priv->always_authenticated;
priv->lock_count = 0;
INIT_LIST_HEAD(&priv->lhead);
INIT_LIST_HEAD(&priv->fbs);
mutex_init(&priv->fbs_lock);
INIT_LIST_HEAD(&priv->event_list);
init_waitqueue_head(&priv->event_wait);
priv->event_space = 4096;
if (dev->driver->driver_features & DRIVER_GEM)
drm_gem_open(dev, priv);
if (drm_core_check_feature(dev, DRIVER_PRIME))
drm_prime_init_file_private(&priv->prime);
if (dev->driver->open) {
ret = dev->driver->open(dev, priv);
if (ret < 0)
goto out_prime_destroy;
}
mutex_lock(&dev->struct_mutex);
if (!priv->minor->master && !drm_is_render_client(priv)) {
priv->minor->master = drm_master_create(priv->minor);
if (!priv->minor->master) {
mutex_unlock(&dev->struct_mutex);
ret = -ENOMEM;
goto out_close;
}
priv->is_master = 1;
priv->master = drm_master_get(priv->minor->master);
priv->authenticated = 1;
mutex_unlock(&dev->struct_mutex);
if (dev->driver->master_create) {
ret = dev->driver->master_create(dev, priv->master);
if (ret) {
mutex_lock(&dev->struct_mutex);
drm_master_put(&priv->minor->master);
drm_master_put(&priv->master);
mutex_unlock(&dev->struct_mutex);
goto out_close;
}
}
mutex_lock(&dev->struct_mutex);
if (dev->driver->master_set) {
ret = dev->driver->master_set(dev, priv, true);
if (ret) {
drm_master_put(&priv->minor->master);
drm_master_put(&priv->master);
mutex_unlock(&dev->struct_mutex);
goto out_close;
}
}
} else if (!drm_is_render_client(priv)) {
priv->master = drm_master_get(priv->minor->master);
}
mutex_unlock(&dev->struct_mutex);
mutex_lock(&dev->struct_mutex);
list_add(&priv->lhead, &dev->filelist);
mutex_unlock(&dev->struct_mutex);
#ifdef __alpha__
if (!dev->hose) {
struct pci_dev *pci_dev;
pci_dev = pci_get_class(PCI_CLASS_DISPLAY_VGA << 8, NULL);
if (pci_dev) {
dev->hose = pci_dev->sysdata;
pci_dev_put(pci_dev);
}
if (!dev->hose) {
struct pci_bus *b = pci_bus_b(pci_root_buses.next);
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
if (dev->driver->driver_features & DRIVER_GEM)
drm_gem_release(dev, priv);
out_put_pid:
put_pid(priv->pid);
kfree(priv);
filp->private_data = NULL;
return ret;
}
static void drm_master_release(struct drm_device *dev, struct file *filp)
{
struct drm_file *file_priv = filp->private_data;
if (drm_i_have_hw_lock(dev, file_priv)) {
DRM_DEBUG("File %p released, freeing lock for context %d\n",
filp, _DRM_LOCKING_CONTEXT(file_priv->master->lock.hw_lock->lock));
drm_lock_free(&file_priv->master->lock,
_DRM_LOCKING_CONTEXT(file_priv->master->lock.hw_lock->lock));
}
}
static void drm_events_release(struct drm_file *file_priv)
{
struct drm_device *dev = file_priv->minor->dev;
struct drm_pending_event *e, *et;
struct drm_pending_vblank_event *v, *vt;
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
list_for_each_entry_safe(v, vt, &dev->vblank_event_list, base.link)
if (v->base.file_priv == file_priv) {
list_del(&v->base.link);
drm_vblank_put(dev, v->pipe);
v->base.destroy(&v->base);
}
list_for_each_entry_safe(e, et, &file_priv->event_list, link) {
list_del(&e->link);
e->destroy(e);
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static void drm_legacy_dev_reinit(struct drm_device *dev)
{
if (drm_core_check_feature(dev, DRIVER_MODESET))
return;
atomic_set(&dev->ioctl_count, 0);
atomic_set(&dev->vma_count, 0);
dev->sigdata.lock = NULL;
dev->context_flag = 0;
dev->last_context = 0;
dev->if_version = 0;
}
int drm_lastclose(struct drm_device * dev)
{
struct drm_vma_entry *vma, *vma_temp;
DRM_DEBUG("\n");
if (dev->driver->lastclose)
dev->driver->lastclose(dev);
DRM_DEBUG("driver lastclose completed\n");
if (dev->irq_enabled && !drm_core_check_feature(dev, DRIVER_MODESET))
drm_irq_uninstall(dev);
mutex_lock(&dev->struct_mutex);
drm_agp_clear(dev);
drm_legacy_sg_cleanup(dev);
list_for_each_entry_safe(vma, vma_temp, &dev->vmalist, head) {
list_del(&vma->head);
kfree(vma);
}
drm_legacy_dma_takedown(dev);
dev->dev_mapping = NULL;
mutex_unlock(&dev->struct_mutex);
drm_legacy_dev_reinit(dev);
DRM_DEBUG("lastclose completed\n");
return 0;
}
int drm_release(struct inode *inode, struct file *filp)
{
struct drm_file *file_priv = filp->private_data;
struct drm_device *dev = file_priv->minor->dev;
int retcode = 0;
mutex_lock(&drm_global_mutex);
DRM_DEBUG("open_count = %d\n", dev->open_count);
if (dev->driver->preclose)
dev->driver->preclose(dev, file_priv);
DRM_DEBUG("pid = %d, device = 0x%lx, open_count = %d\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->device),
dev->open_count);
if (file_priv->magic)
(void) drm_remove_magic(file_priv->master, file_priv->magic);
if (file_priv->minor->master)
drm_master_release(dev, filp);
if (drm_core_check_feature(dev, DRIVER_HAVE_DMA))
drm_core_reclaim_buffers(dev, file_priv);
drm_events_release(file_priv);
if (dev->driver->driver_features & DRIVER_MODESET)
drm_fb_release(file_priv);
if (dev->driver->driver_features & DRIVER_GEM)
drm_gem_release(dev, file_priv);
mutex_lock(&dev->ctxlist_mutex);
if (!list_empty(&dev->ctxlist)) {
struct drm_ctx_list *pos, *n;
list_for_each_entry_safe(pos, n, &dev->ctxlist, head) {
if (pos->tag == file_priv &&
pos->handle != DRM_KERNEL_CONTEXT) {
if (dev->driver->context_dtor)
dev->driver->context_dtor(dev,
pos->handle);
drm_ctxbitmap_free(dev, pos->handle);
list_del(&pos->head);
kfree(pos);
}
}
}
mutex_unlock(&dev->ctxlist_mutex);
mutex_lock(&dev->struct_mutex);
if (file_priv->is_master) {
struct drm_master *master = file_priv->master;
struct drm_file *temp;
list_for_each_entry(temp, &dev->filelist, lhead) {
if ((temp->master == file_priv->master) &&
(temp != file_priv))
temp->authenticated = temp->always_authenticated;
}
if (master->lock.hw_lock) {
if (dev->sigdata.lock == master->lock.hw_lock)
dev->sigdata.lock = NULL;
master->lock.hw_lock = NULL;
master->lock.file_priv = NULL;
wake_up_interruptible_all(&master->lock.lock_queue);
}
if (file_priv->minor->master == file_priv->master) {
if (dev->driver->master_drop)
dev->driver->master_drop(dev, file_priv, true);
drm_master_put(&file_priv->minor->master);
}
}
BUG_ON(dev->dev_mapping == NULL);
iput(container_of(dev->dev_mapping, struct inode, i_data));
if (file_priv->master)
drm_master_put(&file_priv->master);
file_priv->is_master = 0;
list_del(&file_priv->lhead);
mutex_unlock(&dev->struct_mutex);
if (dev->driver->postclose)
dev->driver->postclose(dev, file_priv);
if (drm_core_check_feature(dev, DRIVER_PRIME))
drm_prime_destroy_file_private(&file_priv->prime);
put_pid(file_priv->pid);
kfree(file_priv);
if (!--dev->open_count) {
if (atomic_read(&dev->ioctl_count)) {
DRM_ERROR("Device busy: %d\n",
atomic_read(&dev->ioctl_count));
retcode = -EBUSY;
} else
retcode = drm_lastclose(dev);
if (drm_device_is_unplugged(dev))
drm_put_dev(dev);
}
mutex_unlock(&drm_global_mutex);
return retcode;
}
static bool
drm_dequeue_event(struct drm_file *file_priv,
size_t total, size_t max, struct drm_pending_event **out)
{
struct drm_device *dev = file_priv->minor->dev;
struct drm_pending_event *e;
unsigned long flags;
bool ret = false;
spin_lock_irqsave(&dev->event_lock, flags);
*out = NULL;
if (list_empty(&file_priv->event_list))
goto out;
e = list_first_entry(&file_priv->event_list,
struct drm_pending_event, link);
if (e->event->length + total > max)
goto out;
file_priv->event_space += e->event->length;
list_del(&e->link);
*out = e;
ret = true;
out:
spin_unlock_irqrestore(&dev->event_lock, flags);
return ret;
}
ssize_t drm_read(struct file *filp, char __user *buffer,
size_t count, loff_t *offset)
{
struct drm_file *file_priv = filp->private_data;
struct drm_pending_event *e;
size_t total;
ssize_t ret;
ret = wait_event_interruptible(file_priv->event_wait,
!list_empty(&file_priv->event_list));
if (ret < 0)
return ret;
total = 0;
while (drm_dequeue_event(file_priv, total, count, &e)) {
if (copy_to_user(buffer + total,
e->event, e->event->length)) {
total = -EFAULT;
break;
}
total += e->event->length;
e->destroy(e);
}
return total;
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
