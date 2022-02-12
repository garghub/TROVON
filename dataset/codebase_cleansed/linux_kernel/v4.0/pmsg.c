static ssize_t write_pmsg(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
size_t i, buffer_size;
char *buffer;
if (!count)
return 0;
if (!access_ok(VERIFY_READ, buf, count))
return -EFAULT;
buffer_size = count;
if (buffer_size > PMSG_MAX_BOUNCE_BUFFER_SIZE)
buffer_size = PMSG_MAX_BOUNCE_BUFFER_SIZE;
buffer = vmalloc(buffer_size);
mutex_lock(&pmsg_lock);
for (i = 0; i < count; ) {
size_t c = min(count - i, buffer_size);
u64 id;
long ret;
ret = __copy_from_user(buffer, buf + i, c);
if (unlikely(ret != 0)) {
mutex_unlock(&pmsg_lock);
vfree(buffer);
return -EFAULT;
}
psinfo->write_buf(PSTORE_TYPE_PMSG, 0, &id, 0, buffer, 0, c,
psinfo);
i += c;
}
mutex_unlock(&pmsg_lock);
vfree(buffer);
return count;
}
static char *pmsg_devnode(struct device *dev, umode_t *mode)
{
if (mode)
*mode = 0220;
return NULL;
}
void pstore_register_pmsg(void)
{
struct device *pmsg_device;
pmsg_major = register_chrdev(0, PMSG_NAME, &pmsg_fops);
if (pmsg_major < 0) {
pr_err("register_chrdev failed\n");
goto err;
}
pmsg_class = class_create(THIS_MODULE, PMSG_NAME);
if (IS_ERR(pmsg_class)) {
pr_err("device class file already in use\n");
goto err_class;
}
pmsg_class->devnode = pmsg_devnode;
pmsg_device = device_create(pmsg_class, NULL, MKDEV(pmsg_major, 0),
NULL, "%s%d", PMSG_NAME, 0);
if (IS_ERR(pmsg_device)) {
pr_err("failed to create device\n");
goto err_device;
}
return;
err_device:
class_destroy(pmsg_class);
err_class:
unregister_chrdev(pmsg_major, PMSG_NAME);
err:
return;
}
