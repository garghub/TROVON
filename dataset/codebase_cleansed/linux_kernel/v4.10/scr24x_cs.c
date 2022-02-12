static void scr24x_delete(struct kref *kref)
{
struct scr24x_dev *dev = container_of(kref, struct scr24x_dev,
refcnt);
kfree(dev);
}
static int scr24x_wait_ready(struct scr24x_dev *dev)
{
u_char status;
int timeout = 100;
do {
status = ioread8(dev->regs + SCR24X_CMD_STATUS);
if (!(status & STATUS_BUSY))
return 0;
msleep(20);
} while (--timeout);
return -EIO;
}
static int scr24x_open(struct inode *inode, struct file *filp)
{
struct scr24x_dev *dev = container_of(inode->i_cdev,
struct scr24x_dev, c_dev);
kref_get(&dev->refcnt);
filp->private_data = dev;
return nonseekable_open(inode, filp);
}
static int scr24x_release(struct inode *inode, struct file *filp)
{
struct scr24x_dev *dev = filp->private_data;
kref_put(&dev->refcnt, scr24x_delete);
return 0;
}
static int read_chunk(struct scr24x_dev *dev, size_t offset, size_t limit)
{
size_t i, y;
int ret;
for (i = offset; i < limit; i += 5) {
iowrite8(CMD_READ_BYTE, dev->regs + SCR24X_CMD_STATUS);
ret = scr24x_wait_ready(dev);
if (ret < 0)
return ret;
for (y = 0; y < 5 && i + y < limit; y++)
dev->buf[i + y] = ioread8(dev->regs + SCR24X_DATA(y));
}
return 0;
}
static ssize_t scr24x_read(struct file *filp, char __user *buf, size_t count,
loff_t *ppos)
{
struct scr24x_dev *dev = filp->private_data;
int ret;
int len;
if (count < CCID_HEADER_SIZE)
return -EINVAL;
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
if (!dev->dev) {
ret = -ENODEV;
goto out;
}
ret = scr24x_wait_ready(dev);
if (ret < 0)
goto out;
len = CCID_HEADER_SIZE;
ret = read_chunk(dev, 0, len);
if (ret < 0)
goto out;
len += le32_to_cpu(*(__le32 *)(&dev->buf[CCID_LENGTH_OFFSET]));
if (len > sizeof(dev->buf)) {
ret = -EIO;
goto out;
}
ret = read_chunk(dev, CCID_HEADER_SIZE, len);
if (ret < 0)
goto out;
if (len < count)
count = len;
if (copy_to_user(buf, dev->buf, count)) {
ret = -EFAULT;
goto out;
}
ret = count;
out:
mutex_unlock(&dev->lock);
return ret;
}
static ssize_t scr24x_write(struct file *filp, const char __user *buf,
size_t count, loff_t *ppos)
{
struct scr24x_dev *dev = filp->private_data;
size_t i, y;
int ret;
if (mutex_lock_interruptible(&dev->lock))
return -ERESTARTSYS;
if (!dev->dev) {
ret = -ENODEV;
goto out;
}
if (count > sizeof(dev->buf)) {
ret = -EINVAL;
goto out;
}
if (copy_from_user(dev->buf, buf, count)) {
ret = -EFAULT;
goto out;
}
ret = scr24x_wait_ready(dev);
if (ret < 0)
goto out;
iowrite8(CMD_START, dev->regs + SCR24X_CMD_STATUS);
ret = scr24x_wait_ready(dev);
if (ret < 0)
goto out;
for (i = 0; i < count; i += 5) {
for (y = 0; y < 5 && i + y < count; y++)
iowrite8(dev->buf[i + y], dev->regs + SCR24X_DATA(y));
iowrite8(CMD_WRITE_BYTE, dev->regs + SCR24X_CMD_STATUS);
ret = scr24x_wait_ready(dev);
if (ret < 0)
goto out;
}
ret = count;
out:
mutex_unlock(&dev->lock);
return ret;
}
static int scr24x_config_check(struct pcmcia_device *link, void *priv_data)
{
if (resource_size(link->resource[PCMCIA_IOPORT_0]) != 0x11)
return -ENODEV;
return pcmcia_request_io(link);
}
static int scr24x_probe(struct pcmcia_device *link)
{
struct scr24x_dev *dev;
int ret;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->devno = find_first_zero_bit(scr24x_minors, SCR24X_DEVS);
if (dev->devno >= SCR24X_DEVS) {
ret = -EBUSY;
goto err;
}
mutex_init(&dev->lock);
kref_init(&dev->refcnt);
link->priv = dev;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, scr24x_config_check, NULL);
if (ret < 0)
goto err;
dev->dev = &link->dev;
dev->regs = devm_ioport_map(&link->dev,
link->resource[PCMCIA_IOPORT_0]->start,
resource_size(link->resource[PCMCIA_IOPORT_0]));
if (!dev->regs) {
ret = -EIO;
goto err;
}
cdev_init(&dev->c_dev, &scr24x_fops);
dev->c_dev.owner = THIS_MODULE;
dev->c_dev.ops = &scr24x_fops;
ret = cdev_add(&dev->c_dev, MKDEV(MAJOR(scr24x_devt), dev->devno), 1);
if (ret < 0)
goto err;
ret = pcmcia_enable_device(link);
if (ret < 0) {
pcmcia_disable_device(link);
goto err;
}
device_create(scr24x_class, NULL, MKDEV(MAJOR(scr24x_devt), dev->devno),
NULL, "scr24x%d", dev->devno);
dev_info(&link->dev, "SCR24x Chip Card Interface\n");
return 0;
err:
if (dev->devno < SCR24X_DEVS)
clear_bit(dev->devno, scr24x_minors);
kfree (dev);
return ret;
}
static void scr24x_remove(struct pcmcia_device *link)
{
struct scr24x_dev *dev = (struct scr24x_dev *)link->priv;
device_destroy(scr24x_class, MKDEV(MAJOR(scr24x_devt), dev->devno));
mutex_lock(&dev->lock);
pcmcia_disable_device(link);
cdev_del(&dev->c_dev);
clear_bit(dev->devno, scr24x_minors);
dev->dev = NULL;
mutex_unlock(&dev->lock);
kref_put(&dev->refcnt, scr24x_delete);
}
static int __init scr24x_init(void)
{
int ret;
scr24x_class = class_create(THIS_MODULE, "scr24x");
if (IS_ERR(scr24x_class))
return PTR_ERR(scr24x_class);
ret = alloc_chrdev_region(&scr24x_devt, 0, SCR24X_DEVS, "scr24x");
if (ret < 0) {
class_destroy(scr24x_class);
return ret;
}
ret = pcmcia_register_driver(&scr24x_driver);
if (ret < 0) {
unregister_chrdev_region(scr24x_devt, SCR24X_DEVS);
class_destroy(scr24x_class);
}
return ret;
}
static void __exit scr24x_exit(void)
{
pcmcia_unregister_driver(&scr24x_driver);
unregister_chrdev_region(scr24x_devt, SCR24X_DEVS);
class_destroy(scr24x_class);
}
