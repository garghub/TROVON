static unsigned int pps_cdev_poll(struct file *file, poll_table *wait)
{
struct pps_device *pps = file->private_data;
poll_wait(file, &pps->queue, wait);
return POLLIN | POLLRDNORM;
}
static int pps_cdev_fasync(int fd, struct file *file, int on)
{
struct pps_device *pps = file->private_data;
return fasync_helper(fd, file, on, &pps->async_queue);
}
static long pps_cdev_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
struct pps_device *pps = file->private_data;
struct pps_kparams params;
void __user *uarg = (void __user *) arg;
int __user *iuarg = (int __user *) arg;
int err;
switch (cmd) {
case PPS_GETPARAMS:
dev_dbg(pps->dev, "PPS_GETPARAMS\n");
spin_lock_irq(&pps->lock);
params = pps->params;
spin_unlock_irq(&pps->lock);
err = copy_to_user(uarg, &params, sizeof(struct pps_kparams));
if (err)
return -EFAULT;
break;
case PPS_SETPARAMS:
dev_dbg(pps->dev, "PPS_SETPARAMS\n");
if (!capable(CAP_SYS_TIME))
return -EPERM;
err = copy_from_user(&params, uarg, sizeof(struct pps_kparams));
if (err)
return -EFAULT;
if (!(params.mode & (PPS_CAPTUREASSERT | PPS_CAPTURECLEAR))) {
dev_dbg(pps->dev, "capture mode unspecified (%x)\n",
params.mode);
return -EINVAL;
}
if ((params.mode & ~pps->info.mode) != 0) {
dev_dbg(pps->dev, "unsupported capabilities (%x)\n",
params.mode);
return -EINVAL;
}
spin_lock_irq(&pps->lock);
pps->params = params;
if ((params.mode & (PPS_TSFMT_TSPEC | PPS_TSFMT_NTPFP)) == 0) {
dev_dbg(pps->dev, "time format unspecified (%x)\n",
params.mode);
pps->params.mode |= PPS_TSFMT_TSPEC;
}
if (pps->info.mode & PPS_CANWAIT)
pps->params.mode |= PPS_CANWAIT;
pps->params.api_version = PPS_API_VERS;
spin_unlock_irq(&pps->lock);
break;
case PPS_GETCAP:
dev_dbg(pps->dev, "PPS_GETCAP\n");
err = put_user(pps->info.mode, iuarg);
if (err)
return -EFAULT;
break;
case PPS_FETCH: {
struct pps_fdata fdata;
unsigned int ev;
dev_dbg(pps->dev, "PPS_FETCH\n");
err = copy_from_user(&fdata, uarg, sizeof(struct pps_fdata));
if (err)
return -EFAULT;
ev = pps->last_ev;
if (fdata.timeout.flags & PPS_TIME_INVALID)
err = wait_event_interruptible(pps->queue,
ev != pps->last_ev);
else {
unsigned long ticks;
dev_dbg(pps->dev, "timeout %lld.%09d\n",
(long long) fdata.timeout.sec,
fdata.timeout.nsec);
ticks = fdata.timeout.sec * HZ;
ticks += fdata.timeout.nsec / (NSEC_PER_SEC / HZ);
if (ticks != 0) {
err = wait_event_interruptible_timeout(
pps->queue,
ev != pps->last_ev,
ticks);
if (err == 0)
return -ETIMEDOUT;
}
}
if (err == -ERESTARTSYS) {
dev_dbg(pps->dev, "pending signal caught\n");
return -EINTR;
}
spin_lock_irq(&pps->lock);
fdata.info.assert_sequence = pps->assert_sequence;
fdata.info.clear_sequence = pps->clear_sequence;
fdata.info.assert_tu = pps->assert_tu;
fdata.info.clear_tu = pps->clear_tu;
fdata.info.current_mode = pps->current_mode;
spin_unlock_irq(&pps->lock);
err = copy_to_user(uarg, &fdata, sizeof(struct pps_fdata));
if (err)
return -EFAULT;
break;
}
case PPS_KC_BIND: {
struct pps_bind_args bind_args;
dev_dbg(pps->dev, "PPS_KC_BIND\n");
if (!capable(CAP_SYS_TIME))
return -EPERM;
if (copy_from_user(&bind_args, uarg,
sizeof(struct pps_bind_args)))
return -EFAULT;
if ((bind_args.edge & ~pps->info.mode) != 0) {
dev_err(pps->dev, "unsupported capabilities (%x)\n",
bind_args.edge);
return -EINVAL;
}
if (bind_args.tsformat != PPS_TSFMT_TSPEC ||
(bind_args.edge & ~PPS_CAPTUREBOTH) != 0 ||
bind_args.consumer != PPS_KC_HARDPPS) {
dev_err(pps->dev, "invalid kernel consumer bind"
" parameters (%x)\n", bind_args.edge);
return -EINVAL;
}
err = pps_kc_bind(pps, &bind_args);
if (err < 0)
return err;
break;
}
default:
return -ENOTTY;
}
return 0;
}
static int pps_cdev_open(struct inode *inode, struct file *file)
{
struct pps_device *pps = container_of(inode->i_cdev,
struct pps_device, cdev);
file->private_data = pps;
kobject_get(&pps->dev->kobj);
return 0;
}
static int pps_cdev_release(struct inode *inode, struct file *file)
{
struct pps_device *pps = container_of(inode->i_cdev,
struct pps_device, cdev);
kobject_put(&pps->dev->kobj);
return 0;
}
static void pps_device_destruct(struct device *dev)
{
struct pps_device *pps = dev_get_drvdata(dev);
cdev_del(&pps->cdev);
pr_debug("deallocating pps%d\n", pps->id);
mutex_lock(&pps_idr_lock);
idr_remove(&pps_idr, pps->id);
mutex_unlock(&pps_idr_lock);
kfree(dev);
kfree(pps);
}
int pps_register_cdev(struct pps_device *pps)
{
int err;
dev_t devt;
mutex_lock(&pps_idr_lock);
err = idr_alloc(&pps_idr, pps, 0, PPS_MAX_SOURCES, GFP_KERNEL);
if (err < 0) {
if (err == -ENOSPC) {
pr_err("%s: too many PPS sources in the system\n",
pps->info.name);
err = -EBUSY;
}
goto out_unlock;
}
pps->id = err;
mutex_unlock(&pps_idr_lock);
devt = MKDEV(MAJOR(pps_devt), pps->id);
cdev_init(&pps->cdev, &pps_cdev_fops);
pps->cdev.owner = pps->info.owner;
err = cdev_add(&pps->cdev, devt, 1);
if (err) {
pr_err("%s: failed to add char device %d:%d\n",
pps->info.name, MAJOR(pps_devt), pps->id);
goto free_idr;
}
pps->dev = device_create(pps_class, pps->info.dev, devt, pps,
"pps%d", pps->id);
if (IS_ERR(pps->dev)) {
err = PTR_ERR(pps->dev);
goto del_cdev;
}
pps->dev->release = pps_device_destruct;
pr_debug("source %s got cdev (%d:%d)\n", pps->info.name,
MAJOR(pps_devt), pps->id);
return 0;
del_cdev:
cdev_del(&pps->cdev);
free_idr:
mutex_lock(&pps_idr_lock);
idr_remove(&pps_idr, pps->id);
out_unlock:
mutex_unlock(&pps_idr_lock);
return err;
}
void pps_unregister_cdev(struct pps_device *pps)
{
pr_debug("unregistering pps%d\n", pps->id);
pps->lookup_cookie = NULL;
device_destroy(pps_class, pps->dev->devt);
}
struct pps_device *pps_lookup_dev(void const *cookie)
{
struct pps_device *pps;
unsigned id;
rcu_read_lock();
idr_for_each_entry(&pps_idr, pps, id)
if (cookie == pps->lookup_cookie)
break;
rcu_read_unlock();
return pps;
}
static void __exit pps_exit(void)
{
class_destroy(pps_class);
unregister_chrdev_region(pps_devt, PPS_MAX_SOURCES);
}
static int __init pps_init(void)
{
int err;
pps_class = class_create(THIS_MODULE, "pps");
if (IS_ERR(pps_class)) {
pr_err("failed to allocate class\n");
return PTR_ERR(pps_class);
}
pps_class->dev_groups = pps_groups;
err = alloc_chrdev_region(&pps_devt, 0, PPS_MAX_SOURCES, "pps");
if (err < 0) {
pr_err("failed to allocate char device region\n");
goto remove_class;
}
pr_info("LinuxPPS API ver. %d registered\n", PPS_API_VERS);
pr_info("Software ver. %s - Copyright 2005-2007 Rodolfo Giometti "
"<giometti@linux.it>\n", PPS_VERSION);
return 0;
remove_class:
class_destroy(pps_class);
return err;
}
