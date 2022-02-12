static int dvb_device_open(struct inode *inode, struct file *file)
{
struct dvb_device *dvbdev;
mutex_lock(&dvbdev_mutex);
down_read(&minor_rwsem);
dvbdev = dvb_minors[iminor(inode)];
if (dvbdev && dvbdev->fops) {
int err = 0;
const struct file_operations *old_fops;
file->private_data = dvbdev;
old_fops = file->f_op;
file->f_op = fops_get(dvbdev->fops);
if (file->f_op == NULL) {
file->f_op = old_fops;
goto fail;
}
if(file->f_op->open)
err = file->f_op->open(inode,file);
if (err) {
fops_put(file->f_op);
file->f_op = fops_get(old_fops);
}
fops_put(old_fops);
up_read(&minor_rwsem);
mutex_unlock(&dvbdev_mutex);
return err;
}
fail:
up_read(&minor_rwsem);
mutex_unlock(&dvbdev_mutex);
return -ENODEV;
}
int dvb_generic_open(struct inode *inode, struct file *file)
{
struct dvb_device *dvbdev = file->private_data;
if (!dvbdev)
return -ENODEV;
if (!dvbdev->users)
return -EBUSY;
if ((file->f_flags & O_ACCMODE) == O_RDONLY) {
if (!dvbdev->readers)
return -EBUSY;
dvbdev->readers--;
} else {
if (!dvbdev->writers)
return -EBUSY;
dvbdev->writers--;
}
dvbdev->users--;
return 0;
}
int dvb_generic_release(struct inode *inode, struct file *file)
{
struct dvb_device *dvbdev = file->private_data;
if (!dvbdev)
return -ENODEV;
if ((file->f_flags & O_ACCMODE) == O_RDONLY) {
dvbdev->readers++;
} else {
dvbdev->writers++;
}
dvbdev->users++;
return 0;
}
long dvb_generic_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
struct dvb_device *dvbdev = file->private_data;
if (!dvbdev)
return -ENODEV;
if (!dvbdev->kernel_ioctl)
return -EINVAL;
return dvb_usercopy(file, cmd, arg, dvbdev->kernel_ioctl);
}
static int dvbdev_get_free_id (struct dvb_adapter *adap, int type)
{
u32 id = 0;
while (id < DVB_MAX_IDS) {
struct dvb_device *dev;
list_for_each_entry(dev, &adap->device_list, list_head)
if (dev->type == type && dev->id == id)
goto skip;
return id;
skip:
id++;
}
return -ENFILE;
}
int dvb_register_device(struct dvb_adapter *adap, struct dvb_device **pdvbdev,
const struct dvb_device *template, void *priv, int type)
{
struct dvb_device *dvbdev;
struct file_operations *dvbdevfops;
struct device *clsdev;
int minor;
int id;
mutex_lock(&dvbdev_register_lock);
if ((id = dvbdev_get_free_id (adap, type)) < 0){
mutex_unlock(&dvbdev_register_lock);
*pdvbdev = NULL;
printk(KERN_ERR "%s: couldn't find free device id\n", __func__);
return -ENFILE;
}
*pdvbdev = dvbdev = kmalloc(sizeof(struct dvb_device), GFP_KERNEL);
if (!dvbdev){
mutex_unlock(&dvbdev_register_lock);
return -ENOMEM;
}
dvbdevfops = kzalloc(sizeof(struct file_operations), GFP_KERNEL);
if (!dvbdevfops){
kfree (dvbdev);
mutex_unlock(&dvbdev_register_lock);
return -ENOMEM;
}
memcpy(dvbdev, template, sizeof(struct dvb_device));
dvbdev->type = type;
dvbdev->id = id;
dvbdev->adapter = adap;
dvbdev->priv = priv;
dvbdev->fops = dvbdevfops;
init_waitqueue_head (&dvbdev->wait_queue);
memcpy(dvbdevfops, template->fops, sizeof(struct file_operations));
dvbdevfops->owner = adap->module;
list_add_tail (&dvbdev->list_head, &adap->device_list);
down_write(&minor_rwsem);
#ifdef CONFIG_DVB_DYNAMIC_MINORS
for (minor = 0; minor < MAX_DVB_MINORS; minor++)
if (dvb_minors[minor] == NULL)
break;
if (minor == MAX_DVB_MINORS) {
kfree(dvbdevfops);
kfree(dvbdev);
up_write(&minor_rwsem);
mutex_unlock(&dvbdev_register_lock);
return -EINVAL;
}
#else
minor = nums2minor(adap->num, type, id);
#endif
dvbdev->minor = minor;
dvb_minors[minor] = dvbdev;
up_write(&minor_rwsem);
mutex_unlock(&dvbdev_register_lock);
clsdev = device_create(dvb_class, adap->device,
MKDEV(DVB_MAJOR, minor),
dvbdev, "dvb%d.%s%d", adap->num, dnames[type], id);
if (IS_ERR(clsdev)) {
printk(KERN_ERR "%s: failed to create device dvb%d.%s%d (%ld)\n",
__func__, adap->num, dnames[type], id, PTR_ERR(clsdev));
return PTR_ERR(clsdev);
}
dprintk(KERN_DEBUG "DVB: register adapter%d/%s%d @ minor: %i (0x%02x)\n",
adap->num, dnames[type], id, minor, minor);
return 0;
}
void dvb_unregister_device(struct dvb_device *dvbdev)
{
if (!dvbdev)
return;
down_write(&minor_rwsem);
dvb_minors[dvbdev->minor] = NULL;
up_write(&minor_rwsem);
device_destroy(dvb_class, MKDEV(DVB_MAJOR, dvbdev->minor));
list_del (&dvbdev->list_head);
kfree (dvbdev->fops);
kfree (dvbdev);
}
static int dvbdev_check_free_adapter_num(int num)
{
struct list_head *entry;
list_for_each(entry, &dvb_adapter_list) {
struct dvb_adapter *adap;
adap = list_entry(entry, struct dvb_adapter, list_head);
if (adap->num == num)
return 0;
}
return 1;
}
static int dvbdev_get_free_adapter_num (void)
{
int num = 0;
while (num < DVB_MAX_ADAPTERS) {
if (dvbdev_check_free_adapter_num(num))
return num;
num++;
}
return -ENFILE;
}
int dvb_register_adapter(struct dvb_adapter *adap, const char *name,
struct module *module, struct device *device,
short *adapter_nums)
{
int i, num;
mutex_lock(&dvbdev_register_lock);
for (i = 0; i < DVB_MAX_ADAPTERS; ++i) {
num = adapter_nums[i];
if (num >= 0 && num < DVB_MAX_ADAPTERS) {
if (dvbdev_check_free_adapter_num(num))
break;
} else {
num = dvbdev_get_free_adapter_num();
break;
}
num = -1;
}
if (num < 0) {
mutex_unlock(&dvbdev_register_lock);
return -ENFILE;
}
memset (adap, 0, sizeof(struct dvb_adapter));
INIT_LIST_HEAD (&adap->device_list);
printk(KERN_INFO "DVB: registering new adapter (%s)\n", name);
adap->num = num;
adap->name = name;
adap->module = module;
adap->device = device;
adap->mfe_shared = 0;
adap->mfe_dvbdev = NULL;
mutex_init (&adap->mfe_lock);
list_add_tail (&adap->list_head, &dvb_adapter_list);
mutex_unlock(&dvbdev_register_lock);
return num;
}
int dvb_unregister_adapter(struct dvb_adapter *adap)
{
mutex_lock(&dvbdev_register_lock);
list_del (&adap->list_head);
mutex_unlock(&dvbdev_register_lock);
return 0;
}
int dvb_usercopy(struct file *file,
unsigned int cmd, unsigned long arg,
int (*func)(struct file *file,
unsigned int cmd, void *arg))
{
char sbuf[128];
void *mbuf = NULL;
void *parg = NULL;
int err = -EINVAL;
switch (_IOC_DIR(cmd)) {
case _IOC_NONE:
parg = (void *) arg;
break;
case _IOC_READ:
case _IOC_WRITE:
case (_IOC_WRITE | _IOC_READ):
if (_IOC_SIZE(cmd) <= sizeof(sbuf)) {
parg = sbuf;
} else {
mbuf = kmalloc(_IOC_SIZE(cmd),GFP_KERNEL);
if (NULL == mbuf)
return -ENOMEM;
parg = mbuf;
}
err = -EFAULT;
if (copy_from_user(parg, (void __user *)arg, _IOC_SIZE(cmd)))
goto out;
break;
}
mutex_lock(&dvbdev_mutex);
if ((err = func(file, cmd, parg)) == -ENOIOCTLCMD)
err = -ENOTTY;
mutex_unlock(&dvbdev_mutex);
if (err < 0)
goto out;
switch (_IOC_DIR(cmd))
{
case _IOC_READ:
case (_IOC_WRITE | _IOC_READ):
if (copy_to_user((void __user *)arg, parg, _IOC_SIZE(cmd)))
err = -EFAULT;
break;
}
out:
kfree(mbuf);
return err;
}
static int dvb_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct dvb_device *dvbdev = dev_get_drvdata(dev);
add_uevent_var(env, "DVB_ADAPTER_NUM=%d", dvbdev->adapter->num);
add_uevent_var(env, "DVB_DEVICE_TYPE=%s", dnames[dvbdev->type]);
add_uevent_var(env, "DVB_DEVICE_NUM=%d", dvbdev->id);
return 0;
}
static char *dvb_devnode(struct device *dev, umode_t *mode)
{
struct dvb_device *dvbdev = dev_get_drvdata(dev);
return kasprintf(GFP_KERNEL, "dvb/adapter%d/%s%d",
dvbdev->adapter->num, dnames[dvbdev->type], dvbdev->id);
}
static int __init init_dvbdev(void)
{
int retval;
dev_t dev = MKDEV(DVB_MAJOR, 0);
if ((retval = register_chrdev_region(dev, MAX_DVB_MINORS, "DVB")) != 0) {
printk(KERN_ERR "dvb-core: unable to get major %d\n", DVB_MAJOR);
return retval;
}
cdev_init(&dvb_device_cdev, &dvb_device_fops);
if ((retval = cdev_add(&dvb_device_cdev, dev, MAX_DVB_MINORS)) != 0) {
printk(KERN_ERR "dvb-core: unable register character device\n");
goto error;
}
dvb_class = class_create(THIS_MODULE, "dvb");
if (IS_ERR(dvb_class)) {
retval = PTR_ERR(dvb_class);
goto error;
}
dvb_class->dev_uevent = dvb_uevent;
dvb_class->devnode = dvb_devnode;
return 0;
error:
cdev_del(&dvb_device_cdev);
unregister_chrdev_region(dev, MAX_DVB_MINORS);
return retval;
}
static void __exit exit_dvbdev(void)
{
class_destroy(dvb_class);
cdev_del(&dvb_device_cdev);
unregister_chrdev_region(MKDEV(DVB_MAJOR, 0), MAX_DVB_MINORS);
}
