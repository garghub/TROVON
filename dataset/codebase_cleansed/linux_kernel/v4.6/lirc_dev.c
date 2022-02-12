static void lirc_irctl_init(struct irctl *ir)
{
mutex_init(&ir->irctl_lock);
ir->d.minor = NOPLUG;
}
static void lirc_irctl_cleanup(struct irctl *ir)
{
dev_dbg(ir->d.dev, LOGHEAD "cleaning up\n", ir->d.name, ir->d.minor);
device_destroy(lirc_class, MKDEV(MAJOR(lirc_base_dev), ir->d.minor));
if (ir->buf != ir->d.rbuf) {
lirc_buffer_free(ir->buf);
kfree(ir->buf);
}
ir->buf = NULL;
}
static int lirc_add_to_buf(struct irctl *ir)
{
if (ir->d.add_to_buf) {
int res = -ENODATA;
int got_data = 0;
get_data:
res = ir->d.add_to_buf(ir->d.data, ir->buf);
if (res == 0) {
got_data++;
goto get_data;
}
if (res == -ENODEV)
kthread_stop(ir->task);
return got_data ? 0 : res;
}
return 0;
}
static int lirc_thread(void *irctl)
{
struct irctl *ir = irctl;
dev_dbg(ir->d.dev, LOGHEAD "poll thread started\n",
ir->d.name, ir->d.minor);
do {
if (ir->open) {
if (ir->jiffies_to_wait) {
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(ir->jiffies_to_wait);
}
if (kthread_should_stop())
break;
if (!lirc_add_to_buf(ir))
wake_up_interruptible(&ir->buf->wait_poll);
} else {
set_current_state(TASK_INTERRUPTIBLE);
schedule();
}
} while (!kthread_should_stop());
dev_dbg(ir->d.dev, LOGHEAD "poll thread ended\n",
ir->d.name, ir->d.minor);
return 0;
}
static int lirc_cdev_add(struct irctl *ir)
{
int retval = -ENOMEM;
struct lirc_driver *d = &ir->d;
struct cdev *cdev;
cdev = kzalloc(sizeof(*cdev), GFP_KERNEL);
if (!cdev)
goto err_out;
if (d->fops) {
cdev_init(cdev, d->fops);
cdev->owner = d->owner;
} else {
cdev_init(cdev, &lirc_dev_fops);
cdev->owner = THIS_MODULE;
}
retval = kobject_set_name(&cdev->kobj, "lirc%d", d->minor);
if (retval)
goto err_out;
retval = cdev_add(cdev, MKDEV(MAJOR(lirc_base_dev), d->minor), 1);
if (retval) {
kobject_put(&cdev->kobj);
goto err_out;
}
ir->cdev = cdev;
return 0;
err_out:
kfree(cdev);
return retval;
}
int lirc_register_driver(struct lirc_driver *d)
{
struct irctl *ir;
int minor;
int bytes_in_key;
unsigned int chunk_size;
unsigned int buffer_size;
int err;
if (!d) {
printk(KERN_ERR "lirc_dev: lirc_register_driver: "
"driver pointer must be not NULL!\n");
err = -EBADRQC;
goto out;
}
if (!d->dev) {
printk(KERN_ERR "%s: dev pointer not filled in!\n", __func__);
err = -EINVAL;
goto out;
}
if (MAX_IRCTL_DEVICES <= d->minor) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"\"minor\" must be between 0 and %d (%d)!\n",
MAX_IRCTL_DEVICES - 1, d->minor);
err = -EBADRQC;
goto out;
}
if (1 > d->code_length || (BUFLEN * 8) < d->code_length) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"code length in bits for minor (%d) "
"must be less than %d!\n",
d->minor, BUFLEN * 8);
err = -EBADRQC;
goto out;
}
dev_dbg(d->dev, "lirc_dev: lirc_register_driver: sample_rate: %d\n",
d->sample_rate);
if (d->sample_rate) {
if (2 > d->sample_rate || HZ < d->sample_rate) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"sample_rate must be between 2 and %d!\n", HZ);
err = -EBADRQC;
goto out;
}
if (!d->add_to_buf) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"add_to_buf cannot be NULL when "
"sample_rate is set\n");
err = -EBADRQC;
goto out;
}
} else if (!(d->fops && d->fops->read) && !d->rbuf) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"fops->read and rbuf cannot all be NULL!\n");
err = -EBADRQC;
goto out;
} else if (!d->rbuf) {
if (!(d->fops && d->fops->read && d->fops->poll &&
d->fops->unlocked_ioctl)) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"neither read, poll nor unlocked_ioctl can be NULL!\n");
err = -EBADRQC;
goto out;
}
}
mutex_lock(&lirc_dev_lock);
minor = d->minor;
if (minor < 0) {
for (minor = 0; minor < MAX_IRCTL_DEVICES; minor++)
if (!irctls[minor])
break;
if (MAX_IRCTL_DEVICES == minor) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"no free slots for drivers!\n");
err = -ENOMEM;
goto out_lock;
}
} else if (irctls[minor]) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"minor (%d) just registered!\n", minor);
err = -EBUSY;
goto out_lock;
}
ir = kzalloc(sizeof(struct irctl), GFP_KERNEL);
if (!ir) {
err = -ENOMEM;
goto out_lock;
}
lirc_irctl_init(ir);
irctls[minor] = ir;
d->minor = minor;
if (d->sample_rate) {
ir->jiffies_to_wait = HZ / d->sample_rate;
} else {
ir->jiffies_to_wait = 0;
}
d->name[sizeof(d->name)-1] = '\0';
bytes_in_key = BITS_TO_LONGS(d->code_length) +
(d->code_length % 8 ? 1 : 0);
buffer_size = d->buffer_size ? d->buffer_size : BUFLEN / bytes_in_key;
chunk_size = d->chunk_size ? d->chunk_size : bytes_in_key;
if (d->rbuf) {
ir->buf = d->rbuf;
} else {
ir->buf = kmalloc(sizeof(struct lirc_buffer), GFP_KERNEL);
if (!ir->buf) {
err = -ENOMEM;
goto out_lock;
}
err = lirc_buffer_init(ir->buf, chunk_size, buffer_size);
if (err) {
kfree(ir->buf);
goto out_lock;
}
}
ir->chunk_size = ir->buf->chunk_size;
if (d->features == 0)
d->features = LIRC_CAN_REC_LIRCCODE;
ir->d = *d;
device_create(lirc_class, ir->d.dev,
MKDEV(MAJOR(lirc_base_dev), ir->d.minor), NULL,
"lirc%u", ir->d.minor);
if (d->sample_rate) {
ir->task = kthread_run(lirc_thread, (void *)ir, "lirc_dev");
if (IS_ERR(ir->task)) {
dev_err(d->dev, "lirc_dev: lirc_register_driver: "
"cannot run poll thread for minor = %d\n",
d->minor);
err = -ECHILD;
goto out_sysfs;
}
}
err = lirc_cdev_add(ir);
if (err)
goto out_sysfs;
ir->attached = 1;
mutex_unlock(&lirc_dev_lock);
dev_info(ir->d.dev, "lirc_dev: driver %s registered at minor = %d\n",
ir->d.name, ir->d.minor);
return minor;
out_sysfs:
device_destroy(lirc_class, MKDEV(MAJOR(lirc_base_dev), ir->d.minor));
out_lock:
mutex_unlock(&lirc_dev_lock);
out:
return err;
}
int lirc_unregister_driver(int minor)
{
struct irctl *ir;
struct cdev *cdev;
if (minor < 0 || minor >= MAX_IRCTL_DEVICES) {
printk(KERN_ERR "lirc_dev: %s: minor (%d) must be between "
"0 and %d!\n", __func__, minor, MAX_IRCTL_DEVICES - 1);
return -EBADRQC;
}
ir = irctls[minor];
if (!ir) {
printk(KERN_ERR "lirc_dev: %s: failed to get irctl struct "
"for minor %d!\n", __func__, minor);
return -ENOENT;
}
cdev = ir->cdev;
mutex_lock(&lirc_dev_lock);
if (ir->d.minor != minor) {
printk(KERN_ERR "lirc_dev: %s: minor (%d) device not "
"registered!\n", __func__, minor);
mutex_unlock(&lirc_dev_lock);
return -ENOENT;
}
if (ir->task)
kthread_stop(ir->task);
dev_dbg(ir->d.dev, "lirc_dev: driver %s unregistered from minor = %d\n",
ir->d.name, ir->d.minor);
ir->attached = 0;
if (ir->open) {
dev_dbg(ir->d.dev, LOGHEAD "releasing opened driver\n",
ir->d.name, ir->d.minor);
wake_up_interruptible(&ir->buf->wait_poll);
mutex_lock(&ir->irctl_lock);
ir->d.set_use_dec(ir->d.data);
module_put(cdev->owner);
mutex_unlock(&ir->irctl_lock);
} else {
lirc_irctl_cleanup(ir);
cdev_del(cdev);
kfree(cdev);
kfree(ir);
irctls[minor] = NULL;
}
mutex_unlock(&lirc_dev_lock);
return 0;
}
int lirc_dev_fop_open(struct inode *inode, struct file *file)
{
struct irctl *ir;
struct cdev *cdev;
int retval = 0;
if (iminor(inode) >= MAX_IRCTL_DEVICES) {
printk(KERN_WARNING "lirc_dev [%d]: open result = -ENODEV\n",
iminor(inode));
return -ENODEV;
}
if (mutex_lock_interruptible(&lirc_dev_lock))
return -ERESTARTSYS;
ir = irctls[iminor(inode)];
if (!ir) {
retval = -ENODEV;
goto error;
}
dev_dbg(ir->d.dev, LOGHEAD "open called\n", ir->d.name, ir->d.minor);
if (ir->d.minor == NOPLUG) {
retval = -ENODEV;
goto error;
}
if (ir->open) {
retval = -EBUSY;
goto error;
}
if (ir->d.rdev) {
retval = rc_open(ir->d.rdev);
if (retval)
goto error;
}
cdev = ir->cdev;
if (try_module_get(cdev->owner)) {
ir->open++;
retval = ir->d.set_use_inc(ir->d.data);
if (retval) {
module_put(cdev->owner);
ir->open--;
} else {
lirc_buffer_clear(ir->buf);
}
if (ir->task)
wake_up_process(ir->task);
}
error:
if (ir)
dev_dbg(ir->d.dev, LOGHEAD "open result = %d\n",
ir->d.name, ir->d.minor, retval);
mutex_unlock(&lirc_dev_lock);
nonseekable_open(inode, file);
return retval;
}
int lirc_dev_fop_close(struct inode *inode, struct file *file)
{
struct irctl *ir = irctls[iminor(inode)];
struct cdev *cdev;
int ret;
if (!ir) {
printk(KERN_ERR "%s: called with invalid irctl\n", __func__);
return -EINVAL;
}
cdev = ir->cdev;
dev_dbg(ir->d.dev, LOGHEAD "close called\n", ir->d.name, ir->d.minor);
ret = mutex_lock_killable(&lirc_dev_lock);
WARN_ON(ret);
rc_close(ir->d.rdev);
ir->open--;
if (ir->attached) {
ir->d.set_use_dec(ir->d.data);
module_put(cdev->owner);
} else {
lirc_irctl_cleanup(ir);
cdev_del(cdev);
irctls[ir->d.minor] = NULL;
kfree(cdev);
kfree(ir);
}
if (!ret)
mutex_unlock(&lirc_dev_lock);
return 0;
}
unsigned int lirc_dev_fop_poll(struct file *file, poll_table *wait)
{
struct irctl *ir = irctls[iminor(file_inode(file))];
unsigned int ret;
if (!ir) {
printk(KERN_ERR "%s: called with invalid irctl\n", __func__);
return POLLERR;
}
dev_dbg(ir->d.dev, LOGHEAD "poll called\n", ir->d.name, ir->d.minor);
if (!ir->attached)
return POLLERR;
if (ir->buf) {
poll_wait(file, &ir->buf->wait_poll, wait);
if (lirc_buffer_empty(ir->buf))
ret = 0;
else
ret = POLLIN | POLLRDNORM;
} else
ret = POLLERR;
dev_dbg(ir->d.dev, LOGHEAD "poll result = %d\n",
ir->d.name, ir->d.minor, ret);
return ret;
}
long lirc_dev_fop_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
__u32 mode;
int result = 0;
struct irctl *ir = irctls[iminor(file_inode(file))];
if (!ir) {
printk(KERN_ERR "lirc_dev: %s: no irctl found!\n", __func__);
return -ENODEV;
}
dev_dbg(ir->d.dev, LOGHEAD "ioctl called (0x%x)\n",
ir->d.name, ir->d.minor, cmd);
if (ir->d.minor == NOPLUG || !ir->attached) {
dev_dbg(ir->d.dev, LOGHEAD "ioctl result = -ENODEV\n",
ir->d.name, ir->d.minor);
return -ENODEV;
}
mutex_lock(&ir->irctl_lock);
switch (cmd) {
case LIRC_GET_FEATURES:
result = put_user(ir->d.features, (__u32 __user *)arg);
break;
case LIRC_GET_REC_MODE:
if (!(ir->d.features & LIRC_CAN_REC_MASK)) {
result = -ENOSYS;
break;
}
result = put_user(LIRC_REC2MODE
(ir->d.features & LIRC_CAN_REC_MASK),
(__u32 __user *)arg);
break;
case LIRC_SET_REC_MODE:
if (!(ir->d.features & LIRC_CAN_REC_MASK)) {
result = -ENOSYS;
break;
}
result = get_user(mode, (__u32 __user *)arg);
if (!result && !(LIRC_MODE2REC(mode) & ir->d.features))
result = -EINVAL;
break;
case LIRC_GET_LENGTH:
result = put_user(ir->d.code_length, (__u32 __user *)arg);
break;
case LIRC_GET_MIN_TIMEOUT:
if (!(ir->d.features & LIRC_CAN_SET_REC_TIMEOUT) ||
ir->d.min_timeout == 0) {
result = -ENOSYS;
break;
}
result = put_user(ir->d.min_timeout, (__u32 __user *)arg);
break;
case LIRC_GET_MAX_TIMEOUT:
if (!(ir->d.features & LIRC_CAN_SET_REC_TIMEOUT) ||
ir->d.max_timeout == 0) {
result = -ENOSYS;
break;
}
result = put_user(ir->d.max_timeout, (__u32 __user *)arg);
break;
default:
result = -EINVAL;
}
dev_dbg(ir->d.dev, LOGHEAD "ioctl result = %d\n",
ir->d.name, ir->d.minor, result);
mutex_unlock(&ir->irctl_lock);
return result;
}
ssize_t lirc_dev_fop_read(struct file *file,
char __user *buffer,
size_t length,
loff_t *ppos)
{
struct irctl *ir = irctls[iminor(file_inode(file))];
unsigned char *buf;
int ret = 0, written = 0;
DECLARE_WAITQUEUE(wait, current);
if (!ir) {
printk(KERN_ERR "%s: called with invalid irctl\n", __func__);
return -ENODEV;
}
dev_dbg(ir->d.dev, LOGHEAD "read called\n", ir->d.name, ir->d.minor);
buf = kzalloc(ir->chunk_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (mutex_lock_interruptible(&ir->irctl_lock)) {
ret = -ERESTARTSYS;
goto out_unlocked;
}
if (!ir->attached) {
ret = -ENODEV;
goto out_locked;
}
if (length % ir->chunk_size) {
ret = -EINVAL;
goto out_locked;
}
add_wait_queue(&ir->buf->wait_poll, &wait);
set_current_state(TASK_INTERRUPTIBLE);
while (written < length && ret == 0) {
if (lirc_buffer_empty(ir->buf)) {
if (written)
break;
if (file->f_flags & O_NONBLOCK) {
ret = -EWOULDBLOCK;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
mutex_unlock(&ir->irctl_lock);
schedule();
set_current_state(TASK_INTERRUPTIBLE);
if (mutex_lock_interruptible(&ir->irctl_lock)) {
ret = -ERESTARTSYS;
remove_wait_queue(&ir->buf->wait_poll, &wait);
set_current_state(TASK_RUNNING);
goto out_unlocked;
}
if (!ir->attached) {
ret = -ENODEV;
break;
}
} else {
lirc_buffer_read(ir->buf, buf);
ret = copy_to_user((void __user *)buffer+written, buf,
ir->buf->chunk_size);
if (!ret)
written += ir->buf->chunk_size;
else
ret = -EFAULT;
}
}
remove_wait_queue(&ir->buf->wait_poll, &wait);
set_current_state(TASK_RUNNING);
out_locked:
mutex_unlock(&ir->irctl_lock);
out_unlocked:
kfree(buf);
dev_dbg(ir->d.dev, LOGHEAD "read result = %s (%d)\n",
ir->d.name, ir->d.minor, ret ? "<fail>" : "<ok>", ret);
return ret ? ret : written;
}
void *lirc_get_pdata(struct file *file)
{
return irctls[iminor(file_inode(file))]->d.data;
}
ssize_t lirc_dev_fop_write(struct file *file, const char __user *buffer,
size_t length, loff_t *ppos)
{
struct irctl *ir = irctls[iminor(file_inode(file))];
if (!ir) {
printk(KERN_ERR "%s: called with invalid irctl\n", __func__);
return -ENODEV;
}
dev_dbg(ir->d.dev, LOGHEAD "write called\n", ir->d.name, ir->d.minor);
if (!ir->attached)
return -ENODEV;
return -EINVAL;
}
static int __init lirc_dev_init(void)
{
int retval;
lirc_class = class_create(THIS_MODULE, "lirc");
if (IS_ERR(lirc_class)) {
retval = PTR_ERR(lirc_class);
printk(KERN_ERR "lirc_dev: class_create failed\n");
goto error;
}
retval = alloc_chrdev_region(&lirc_base_dev, 0, MAX_IRCTL_DEVICES,
IRCTL_DEV_NAME);
if (retval) {
class_destroy(lirc_class);
printk(KERN_ERR "lirc_dev: alloc_chrdev_region failed\n");
goto error;
}
printk(KERN_INFO "lirc_dev: IR Remote Control driver registered, "
"major %d \n", MAJOR(lirc_base_dev));
error:
return retval;
}
static void __exit lirc_dev_exit(void)
{
class_destroy(lirc_class);
unregister_chrdev_region(lirc_base_dev, MAX_IRCTL_DEVICES);
printk(KERN_INFO "lirc_dev: module unloaded\n");
}
