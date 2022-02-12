static void drm_legacy_dev_reinit(struct drm_device *dev)
{
int i;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return;
atomic_set(&dev->ioctl_count, 0);
atomic_set(&dev->vma_count, 0);
for (i = 0; i < ARRAY_SIZE(dev->counts); i++)
atomic_set(&dev->counts[i], 0);
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
static int __init drm_core_init(void)
{
int ret = -ENOMEM;
drm_global_init();
drm_connector_ida_init();
idr_init(&drm_minors_idr);
if (register_chrdev(DRM_MAJOR, "drm", &drm_stub_fops))
goto err_p1;
drm_class = drm_sysfs_create(THIS_MODULE, "drm");
if (IS_ERR(drm_class)) {
printk(KERN_ERR "DRM: Error creating drm class.\n");
ret = PTR_ERR(drm_class);
goto err_p2;
}
drm_debugfs_root = debugfs_create_dir("dri", NULL);
if (!drm_debugfs_root) {
DRM_ERROR("Cannot create /sys/kernel/debug/dri\n");
ret = -1;
goto err_p3;
}
DRM_INFO("Initialized %s %d.%d.%d %s\n",
CORE_NAME, CORE_MAJOR, CORE_MINOR, CORE_PATCHLEVEL, CORE_DATE);
return 0;
err_p3:
drm_sysfs_destroy();
err_p2:
unregister_chrdev(DRM_MAJOR, "drm");
idr_destroy(&drm_minors_idr);
err_p1:
return ret;
}
static void __exit drm_core_exit(void)
{
debugfs_remove(drm_debugfs_root);
drm_sysfs_destroy();
unregister_chrdev(DRM_MAJOR, "drm");
drm_connector_ida_destroy();
idr_destroy(&drm_minors_idr);
}
static int drm_copy_field(char *buf, size_t *buf_len, const char *value)
{
int len;
len = strlen(value);
if (len > *buf_len)
len = *buf_len;
*buf_len = strlen(value);
if (len && buf)
if (copy_to_user(buf, value, len))
return -EFAULT;
return 0;
}
static int drm_version(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_version *version = data;
int err;
version->version_major = dev->driver->major;
version->version_minor = dev->driver->minor;
version->version_patchlevel = dev->driver->patchlevel;
err = drm_copy_field(version->name, &version->name_len,
dev->driver->name);
if (!err)
err = drm_copy_field(version->date, &version->date_len,
dev->driver->date);
if (!err)
err = drm_copy_field(version->desc, &version->desc_len,
dev->driver->desc);
return err;
}
long drm_ioctl(struct file *filp,
unsigned int cmd, unsigned long arg)
{
struct drm_file *file_priv = filp->private_data;
struct drm_device *dev;
const struct drm_ioctl_desc *ioctl = NULL;
drm_ioctl_t *func;
unsigned int nr = DRM_IOCTL_NR(cmd);
int retcode = -EINVAL;
char stack_kdata[128];
char *kdata = NULL;
unsigned int usize, asize;
dev = file_priv->minor->dev;
if (drm_device_is_unplugged(dev))
return -ENODEV;
atomic_inc(&dev->ioctl_count);
atomic_inc(&dev->counts[_DRM_STAT_IOCTLS]);
++file_priv->ioctl_count;
if ((nr >= DRM_CORE_IOCTL_COUNT) &&
((nr < DRM_COMMAND_BASE) || (nr >= DRM_COMMAND_END)))
goto err_i1;
if ((nr >= DRM_COMMAND_BASE) && (nr < DRM_COMMAND_END) &&
(nr < DRM_COMMAND_BASE + dev->driver->num_ioctls)) {
u32 drv_size;
ioctl = &dev->driver->ioctls[nr - DRM_COMMAND_BASE];
drv_size = _IOC_SIZE(ioctl->cmd_drv);
usize = asize = _IOC_SIZE(cmd);
if (drv_size > asize)
asize = drv_size;
cmd = ioctl->cmd_drv;
}
else if ((nr >= DRM_COMMAND_END) || (nr < DRM_COMMAND_BASE)) {
u32 drv_size;
ioctl = &drm_ioctls[nr];
drv_size = _IOC_SIZE(ioctl->cmd);
usize = asize = _IOC_SIZE(cmd);
if (drv_size > asize)
asize = drv_size;
cmd = ioctl->cmd;
} else
goto err_i1;
DRM_DEBUG("pid=%d, dev=0x%lx, auth=%d, %s\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->device),
file_priv->authenticated, ioctl->name);
func = ioctl->func;
if (!func) {
DRM_DEBUG("no function\n");
retcode = -EINVAL;
} else if (((ioctl->flags & DRM_ROOT_ONLY) && !capable(CAP_SYS_ADMIN)) ||
((ioctl->flags & DRM_AUTH) && !drm_is_render_client(file_priv) && !file_priv->authenticated) ||
((ioctl->flags & DRM_MASTER) && !file_priv->is_master) ||
(!(ioctl->flags & DRM_CONTROL_ALLOW) && (file_priv->minor->type == DRM_MINOR_CONTROL)) ||
(!(ioctl->flags & DRM_RENDER_ALLOW) && drm_is_render_client(file_priv))) {
retcode = -EACCES;
} else {
if (cmd & (IOC_IN | IOC_OUT)) {
if (asize <= sizeof(stack_kdata)) {
kdata = stack_kdata;
} else {
kdata = kmalloc(asize, GFP_KERNEL);
if (!kdata) {
retcode = -ENOMEM;
goto err_i1;
}
}
if (asize > usize)
memset(kdata + usize, 0, asize - usize);
}
if (cmd & IOC_IN) {
if (copy_from_user(kdata, (void __user *)arg,
usize) != 0) {
retcode = -EFAULT;
goto err_i1;
}
} else
memset(kdata, 0, usize);
if (ioctl->flags & DRM_UNLOCKED)
retcode = func(dev, kdata, file_priv);
else {
mutex_lock(&drm_global_mutex);
retcode = func(dev, kdata, file_priv);
mutex_unlock(&drm_global_mutex);
}
if (cmd & IOC_OUT) {
if (copy_to_user((void __user *)arg, kdata,
usize) != 0)
retcode = -EFAULT;
}
}
err_i1:
if (!ioctl)
DRM_DEBUG("invalid iotcl: pid=%d, dev=0x%lx, auth=%d, cmd=0x%02x, nr=0x%02x\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->device),
file_priv->authenticated, cmd, nr);
if (kdata != stack_kdata)
kfree(kdata);
atomic_dec(&dev->ioctl_count);
if (retcode)
DRM_DEBUG("ret = %d\n", retcode);
return retcode;
}
