static int rpmsg_eptdev_destroy(struct device *dev, void *data)
{
struct rpmsg_eptdev *eptdev = dev_to_eptdev(dev);
mutex_lock(&eptdev->ept_lock);
if (eptdev->ept) {
rpmsg_destroy_ept(eptdev->ept);
eptdev->ept = NULL;
}
mutex_unlock(&eptdev->ept_lock);
wake_up_interruptible(&eptdev->readq);
device_del(&eptdev->dev);
put_device(&eptdev->dev);
return 0;
}
static int rpmsg_ept_cb(struct rpmsg_device *rpdev, void *buf, int len,
void *priv, u32 addr)
{
struct rpmsg_eptdev *eptdev = priv;
struct sk_buff *skb;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb)
return -ENOMEM;
memcpy(skb_put(skb, len), buf, len);
spin_lock(&eptdev->queue_lock);
skb_queue_tail(&eptdev->queue, skb);
spin_unlock(&eptdev->queue_lock);
wake_up_interruptible(&eptdev->readq);
return 0;
}
static int rpmsg_eptdev_open(struct inode *inode, struct file *filp)
{
struct rpmsg_eptdev *eptdev = cdev_to_eptdev(inode->i_cdev);
struct rpmsg_endpoint *ept;
struct rpmsg_device *rpdev = eptdev->rpdev;
struct device *dev = &eptdev->dev;
get_device(dev);
ept = rpmsg_create_ept(rpdev, rpmsg_ept_cb, eptdev, eptdev->chinfo);
if (!ept) {
dev_err(dev, "failed to open %s\n", eptdev->chinfo.name);
put_device(dev);
return -EINVAL;
}
eptdev->ept = ept;
filp->private_data = eptdev;
return 0;
}
static int rpmsg_eptdev_release(struct inode *inode, struct file *filp)
{
struct rpmsg_eptdev *eptdev = cdev_to_eptdev(inode->i_cdev);
struct device *dev = &eptdev->dev;
struct sk_buff *skb;
mutex_lock(&eptdev->ept_lock);
if (eptdev->ept) {
rpmsg_destroy_ept(eptdev->ept);
eptdev->ept = NULL;
}
mutex_unlock(&eptdev->ept_lock);
while (!skb_queue_empty(&eptdev->queue)) {
skb = skb_dequeue(&eptdev->queue);
kfree_skb(skb);
}
put_device(dev);
return 0;
}
static ssize_t rpmsg_eptdev_read(struct file *filp, char __user *buf,
size_t len, loff_t *f_pos)
{
struct rpmsg_eptdev *eptdev = filp->private_data;
unsigned long flags;
struct sk_buff *skb;
int use;
if (!eptdev->ept)
return -EPIPE;
spin_lock_irqsave(&eptdev->queue_lock, flags);
if (skb_queue_empty(&eptdev->queue)) {
spin_unlock_irqrestore(&eptdev->queue_lock, flags);
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
if (wait_event_interruptible(eptdev->readq,
!skb_queue_empty(&eptdev->queue) ||
!eptdev->ept))
return -ERESTARTSYS;
if (!eptdev->ept)
return -EPIPE;
spin_lock_irqsave(&eptdev->queue_lock, flags);
}
skb = skb_dequeue(&eptdev->queue);
spin_unlock_irqrestore(&eptdev->queue_lock, flags);
if (!skb)
return -EFAULT;
use = min_t(size_t, len, skb->len);
if (copy_to_user(buf, skb->data, use))
use = -EFAULT;
kfree_skb(skb);
return use;
}
static ssize_t rpmsg_eptdev_write(struct file *filp, const char __user *buf,
size_t len, loff_t *f_pos)
{
struct rpmsg_eptdev *eptdev = filp->private_data;
void *kbuf;
int ret;
kbuf = memdup_user(buf, len);
if (IS_ERR(kbuf))
return PTR_ERR(kbuf);
if (mutex_lock_interruptible(&eptdev->ept_lock)) {
ret = -ERESTARTSYS;
goto free_kbuf;
}
if (!eptdev->ept) {
ret = -EPIPE;
goto unlock_eptdev;
}
if (filp->f_flags & O_NONBLOCK)
ret = rpmsg_trysend(eptdev->ept, kbuf, len);
else
ret = rpmsg_send(eptdev->ept, kbuf, len);
unlock_eptdev:
mutex_unlock(&eptdev->ept_lock);
free_kbuf:
kfree(kbuf);
return ret < 0 ? ret : len;
}
static unsigned int rpmsg_eptdev_poll(struct file *filp, poll_table *wait)
{
struct rpmsg_eptdev *eptdev = filp->private_data;
unsigned int mask = 0;
if (!eptdev->ept)
return POLLERR;
poll_wait(filp, &eptdev->readq, wait);
if (!skb_queue_empty(&eptdev->queue))
mask |= POLLIN | POLLRDNORM;
mask |= rpmsg_poll(eptdev->ept, filp, wait);
return mask;
}
static long rpmsg_eptdev_ioctl(struct file *fp, unsigned int cmd,
unsigned long arg)
{
struct rpmsg_eptdev *eptdev = fp->private_data;
if (cmd != RPMSG_DESTROY_EPT_IOCTL)
return -EINVAL;
return rpmsg_eptdev_destroy(&eptdev->dev, NULL);
}
static ssize_t name_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct rpmsg_eptdev *eptdev = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", eptdev->chinfo.name);
}
static ssize_t src_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct rpmsg_eptdev *eptdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", eptdev->chinfo.src);
}
static ssize_t dst_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct rpmsg_eptdev *eptdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", eptdev->chinfo.dst);
}
static void rpmsg_eptdev_release_device(struct device *dev)
{
struct rpmsg_eptdev *eptdev = dev_to_eptdev(dev);
ida_simple_remove(&rpmsg_ept_ida, dev->id);
ida_simple_remove(&rpmsg_minor_ida, MINOR(eptdev->dev.devt));
cdev_del(&eptdev->cdev);
kfree(eptdev);
}
static int rpmsg_eptdev_create(struct rpmsg_ctrldev *ctrldev,
struct rpmsg_channel_info chinfo)
{
struct rpmsg_device *rpdev = ctrldev->rpdev;
struct rpmsg_eptdev *eptdev;
struct device *dev;
int ret;
eptdev = kzalloc(sizeof(*eptdev), GFP_KERNEL);
if (!eptdev)
return -ENOMEM;
dev = &eptdev->dev;
eptdev->rpdev = rpdev;
eptdev->chinfo = chinfo;
mutex_init(&eptdev->ept_lock);
spin_lock_init(&eptdev->queue_lock);
skb_queue_head_init(&eptdev->queue);
init_waitqueue_head(&eptdev->readq);
device_initialize(dev);
dev->class = rpmsg_class;
dev->parent = &ctrldev->dev;
dev->groups = rpmsg_eptdev_groups;
dev_set_drvdata(dev, eptdev);
cdev_init(&eptdev->cdev, &rpmsg_eptdev_fops);
eptdev->cdev.owner = THIS_MODULE;
ret = ida_simple_get(&rpmsg_minor_ida, 0, RPMSG_DEV_MAX, GFP_KERNEL);
if (ret < 0)
goto free_eptdev;
dev->devt = MKDEV(MAJOR(rpmsg_major), ret);
ret = ida_simple_get(&rpmsg_ept_ida, 0, 0, GFP_KERNEL);
if (ret < 0)
goto free_minor_ida;
dev->id = ret;
dev_set_name(dev, "rpmsg%d", ret);
ret = cdev_add(&eptdev->cdev, dev->devt, 1);
if (ret)
goto free_ept_ida;
dev->release = rpmsg_eptdev_release_device;
ret = device_add(dev);
if (ret) {
dev_err(dev, "device_register failed: %d\n", ret);
put_device(dev);
}
return ret;
free_ept_ida:
ida_simple_remove(&rpmsg_ept_ida, dev->id);
free_minor_ida:
ida_simple_remove(&rpmsg_minor_ida, MINOR(dev->devt));
free_eptdev:
put_device(dev);
kfree(eptdev);
return ret;
}
static int rpmsg_ctrldev_open(struct inode *inode, struct file *filp)
{
struct rpmsg_ctrldev *ctrldev = cdev_to_ctrldev(inode->i_cdev);
get_device(&ctrldev->dev);
filp->private_data = ctrldev;
return 0;
}
static int rpmsg_ctrldev_release(struct inode *inode, struct file *filp)
{
struct rpmsg_ctrldev *ctrldev = cdev_to_ctrldev(inode->i_cdev);
put_device(&ctrldev->dev);
return 0;
}
static long rpmsg_ctrldev_ioctl(struct file *fp, unsigned int cmd,
unsigned long arg)
{
struct rpmsg_ctrldev *ctrldev = fp->private_data;
void __user *argp = (void __user *)arg;
struct rpmsg_endpoint_info eptinfo;
struct rpmsg_channel_info chinfo;
if (cmd != RPMSG_CREATE_EPT_IOCTL)
return -EINVAL;
if (copy_from_user(&eptinfo, argp, sizeof(eptinfo)))
return -EFAULT;
memcpy(chinfo.name, eptinfo.name, RPMSG_NAME_SIZE);
chinfo.name[RPMSG_NAME_SIZE-1] = '\0';
chinfo.src = eptinfo.src;
chinfo.dst = eptinfo.dst;
return rpmsg_eptdev_create(ctrldev, chinfo);
}
static void rpmsg_ctrldev_release_device(struct device *dev)
{
struct rpmsg_ctrldev *ctrldev = dev_to_ctrldev(dev);
ida_simple_remove(&rpmsg_ctrl_ida, dev->id);
ida_simple_remove(&rpmsg_minor_ida, MINOR(dev->devt));
cdev_del(&ctrldev->cdev);
kfree(ctrldev);
}
static int rpmsg_chrdev_probe(struct rpmsg_device *rpdev)
{
struct rpmsg_ctrldev *ctrldev;
struct device *dev;
int ret;
ctrldev = kzalloc(sizeof(*ctrldev), GFP_KERNEL);
if (!ctrldev)
return -ENOMEM;
ctrldev->rpdev = rpdev;
dev = &ctrldev->dev;
device_initialize(dev);
dev->parent = &rpdev->dev;
dev->class = rpmsg_class;
cdev_init(&ctrldev->cdev, &rpmsg_ctrldev_fops);
ctrldev->cdev.owner = THIS_MODULE;
ret = ida_simple_get(&rpmsg_minor_ida, 0, RPMSG_DEV_MAX, GFP_KERNEL);
if (ret < 0)
goto free_ctrldev;
dev->devt = MKDEV(MAJOR(rpmsg_major), ret);
ret = ida_simple_get(&rpmsg_ctrl_ida, 0, 0, GFP_KERNEL);
if (ret < 0)
goto free_minor_ida;
dev->id = ret;
dev_set_name(&ctrldev->dev, "rpmsg_ctrl%d", ret);
ret = cdev_add(&ctrldev->cdev, dev->devt, 1);
if (ret)
goto free_ctrl_ida;
dev->release = rpmsg_ctrldev_release_device;
ret = device_add(dev);
if (ret) {
dev_err(&rpdev->dev, "device_register failed: %d\n", ret);
put_device(dev);
}
dev_set_drvdata(&rpdev->dev, ctrldev);
return ret;
free_ctrl_ida:
ida_simple_remove(&rpmsg_ctrl_ida, dev->id);
free_minor_ida:
ida_simple_remove(&rpmsg_minor_ida, MINOR(dev->devt));
free_ctrldev:
put_device(dev);
kfree(ctrldev);
return ret;
}
static void rpmsg_chrdev_remove(struct rpmsg_device *rpdev)
{
struct rpmsg_ctrldev *ctrldev = dev_get_drvdata(&rpdev->dev);
int ret;
ret = device_for_each_child(&ctrldev->dev, NULL, rpmsg_eptdev_destroy);
if (ret)
dev_warn(&rpdev->dev, "failed to nuke endpoints: %d\n", ret);
device_del(&ctrldev->dev);
put_device(&ctrldev->dev);
}
static int rpmsg_char_init(void)
{
int ret;
ret = alloc_chrdev_region(&rpmsg_major, 0, RPMSG_DEV_MAX, "rpmsg");
if (ret < 0) {
pr_err("rpmsg: failed to allocate char dev region\n");
return ret;
}
rpmsg_class = class_create(THIS_MODULE, "rpmsg");
if (IS_ERR(rpmsg_class)) {
pr_err("failed to create rpmsg class\n");
unregister_chrdev_region(rpmsg_major, RPMSG_DEV_MAX);
return PTR_ERR(rpmsg_class);
}
ret = register_rpmsg_driver(&rpmsg_chrdev_driver);
if (ret < 0) {
pr_err("rpmsgchr: failed to register rpmsg driver\n");
class_destroy(rpmsg_class);
unregister_chrdev_region(rpmsg_major, RPMSG_DEV_MAX);
}
return ret;
}
static void rpmsg_chrdev_exit(void)
{
unregister_rpmsg_driver(&rpmsg_chrdev_driver);
class_destroy(rpmsg_class);
unregister_chrdev_region(rpmsg_major, RPMSG_DEV_MAX);
}
