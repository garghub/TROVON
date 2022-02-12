static void reset_counters(void)
{
statistics.reads = 0;
statistics.writes = 0;
statistics.ioctls = 0;
statistics.irqs = 0;
statistics.berrs = 0;
statistics.dmaerrors = 0;
statistics.timeouts = 0;
}
static int vme_user_open(struct inode *inode, struct file *file)
{
int err;
unsigned int minor = MINOR(inode->i_rdev);
mutex_lock(&image[minor].mutex);
if (minor < CONTROL_MINOR && image[minor].resource == NULL) {
pr_err("No resources allocated for device\n");
err = -EINVAL;
goto err_res;
}
image[minor].users++;
mutex_unlock(&image[minor].mutex);
return 0;
err_res:
mutex_unlock(&image[minor].mutex);
return err;
}
static int vme_user_release(struct inode *inode, struct file *file)
{
unsigned int minor = MINOR(inode->i_rdev);
mutex_lock(&image[minor].mutex);
image[minor].users--;
mutex_unlock(&image[minor].mutex);
return 0;
}
static ssize_t resource_to_user(int minor, char __user *buf, size_t count,
loff_t *ppos)
{
ssize_t retval;
ssize_t copied = 0;
if (count <= image[minor].size_buf) {
copied = vme_master_read(image[minor].resource,
image[minor].kern_buf, count, *ppos);
if (copied < 0)
return (int)copied;
retval = __copy_to_user(buf, image[minor].kern_buf,
(unsigned long)copied);
if (retval != 0) {
copied = (copied - retval);
pr_info("User copy failed\n");
return -EINVAL;
}
} else {
pr_info("Currently don't support large transfers\n");
return -EINVAL;
}
return copied;
}
static ssize_t resource_from_user(unsigned int minor, const char __user *buf,
size_t count, loff_t *ppos)
{
ssize_t retval;
ssize_t copied = 0;
if (count <= image[minor].size_buf) {
retval = __copy_from_user(image[minor].kern_buf, buf,
(unsigned long)count);
if (retval != 0)
copied = (copied - retval);
else
copied = count;
copied = vme_master_write(image[minor].resource,
image[minor].kern_buf, copied, *ppos);
} else {
pr_info("Currently don't support large transfers\n");
return -EINVAL;
}
return copied;
}
static ssize_t buffer_to_user(unsigned int minor, char __user *buf,
size_t count, loff_t *ppos)
{
void *image_ptr;
ssize_t retval;
image_ptr = image[minor].kern_buf + *ppos;
retval = __copy_to_user(buf, image_ptr, (unsigned long)count);
if (retval != 0) {
retval = (count - retval);
pr_warn("Partial copy to userspace\n");
} else
retval = count;
return retval;
}
static ssize_t buffer_from_user(unsigned int minor, const char __user *buf,
size_t count, loff_t *ppos)
{
void *image_ptr;
size_t retval;
image_ptr = image[minor].kern_buf + *ppos;
retval = __copy_from_user(image_ptr, buf, (unsigned long)count);
if (retval != 0) {
retval = (count - retval);
pr_warn("Partial copy to userspace\n");
} else
retval = count;
return retval;
}
static ssize_t vme_user_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
unsigned int minor = MINOR(file_inode(file)->i_rdev);
ssize_t retval;
size_t image_size;
size_t okcount;
if (minor == CONTROL_MINOR)
return 0;
mutex_lock(&image[minor].mutex);
image_size = vme_get_size(image[minor].resource);
if ((*ppos < 0) || (*ppos > (image_size - 1))) {
mutex_unlock(&image[minor].mutex);
return 0;
}
if (*ppos + count > image_size)
okcount = image_size - *ppos;
else
okcount = count;
switch (type[minor]) {
case MASTER_MINOR:
retval = resource_to_user(minor, buf, okcount, ppos);
break;
case SLAVE_MINOR:
retval = buffer_to_user(minor, buf, okcount, ppos);
break;
default:
retval = -EINVAL;
}
mutex_unlock(&image[minor].mutex);
if (retval > 0)
*ppos += retval;
return retval;
}
static ssize_t vme_user_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
unsigned int minor = MINOR(file_inode(file)->i_rdev);
ssize_t retval;
size_t image_size;
size_t okcount;
if (minor == CONTROL_MINOR)
return 0;
mutex_lock(&image[minor].mutex);
image_size = vme_get_size(image[minor].resource);
if ((*ppos < 0) || (*ppos > (image_size - 1))) {
mutex_unlock(&image[minor].mutex);
return 0;
}
if (*ppos + count > image_size)
okcount = image_size - *ppos;
else
okcount = count;
switch (type[minor]) {
case MASTER_MINOR:
retval = resource_from_user(minor, buf, okcount, ppos);
break;
case SLAVE_MINOR:
retval = buffer_from_user(minor, buf, okcount, ppos);
break;
default:
retval = -EINVAL;
}
mutex_unlock(&image[minor].mutex);
if (retval > 0)
*ppos += retval;
return retval;
}
static loff_t vme_user_llseek(struct file *file, loff_t off, int whence)
{
loff_t absolute = -1;
unsigned int minor = MINOR(file_inode(file)->i_rdev);
size_t image_size;
if (minor == CONTROL_MINOR)
return -EINVAL;
mutex_lock(&image[minor].mutex);
image_size = vme_get_size(image[minor].resource);
switch (whence) {
case SEEK_SET:
absolute = off;
break;
case SEEK_CUR:
absolute = file->f_pos + off;
break;
case SEEK_END:
absolute = image_size + off;
break;
default:
mutex_unlock(&image[minor].mutex);
return -EINVAL;
break;
}
if ((absolute < 0) || (absolute >= image_size)) {
mutex_unlock(&image[minor].mutex);
return -EINVAL;
}
file->f_pos = absolute;
mutex_unlock(&image[minor].mutex);
return absolute;
}
static int vme_user_ioctl(struct inode *inode, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct vme_master master;
struct vme_slave slave;
struct vme_irq_id irq_req;
unsigned long copied;
unsigned int minor = MINOR(inode->i_rdev);
int retval;
dma_addr_t pci_addr;
void __user *argp = (void __user *)arg;
statistics.ioctls++;
switch (type[minor]) {
case CONTROL_MINOR:
switch (cmd) {
case VME_IRQ_GEN:
copied = copy_from_user(&irq_req, argp,
sizeof(struct vme_irq_id));
if (copied != 0) {
pr_warn("Partial copy from userspace\n");
return -EFAULT;
}
retval = vme_irq_generate(vme_user_bridge,
irq_req.level,
irq_req.statid);
return retval;
}
break;
case MASTER_MINOR:
switch (cmd) {
case VME_GET_MASTER:
memset(&master, 0, sizeof(struct vme_master));
retval = vme_master_get(image[minor].resource,
&master.enable, &master.vme_addr,
&master.size, &master.aspace,
&master.cycle, &master.dwidth);
copied = copy_to_user(argp, &master,
sizeof(struct vme_master));
if (copied != 0) {
pr_warn("Partial copy to userspace\n");
return -EFAULT;
}
return retval;
break;
case VME_SET_MASTER:
copied = copy_from_user(&master, argp, sizeof(master));
if (copied != 0) {
pr_warn("Partial copy from userspace\n");
return -EFAULT;
}
return vme_master_set(image[minor].resource,
master.enable, master.vme_addr, master.size,
master.aspace, master.cycle, master.dwidth);
break;
}
break;
case SLAVE_MINOR:
switch (cmd) {
case VME_GET_SLAVE:
memset(&slave, 0, sizeof(struct vme_slave));
retval = vme_slave_get(image[minor].resource,
&slave.enable, &slave.vme_addr,
&slave.size, &pci_addr, &slave.aspace,
&slave.cycle);
copied = copy_to_user(argp, &slave,
sizeof(struct vme_slave));
if (copied != 0) {
pr_warn("Partial copy to userspace\n");
return -EFAULT;
}
return retval;
break;
case VME_SET_SLAVE:
copied = copy_from_user(&slave, argp, sizeof(slave));
if (copied != 0) {
pr_warn("Partial copy from userspace\n");
return -EFAULT;
}
return vme_slave_set(image[minor].resource,
slave.enable, slave.vme_addr, slave.size,
image[minor].pci_buf, slave.aspace,
slave.cycle);
break;
}
break;
}
return -EINVAL;
}
static long
vme_user_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int ret;
mutex_lock(&vme_user_mutex);
ret = vme_user_ioctl(file_inode(file), file, cmd, arg);
mutex_unlock(&vme_user_mutex);
return ret;
}
static void buf_unalloc(int num)
{
if (image[num].kern_buf) {
#ifdef VME_DEBUG
pr_debug("UniverseII:Releasing buffer at %p\n",
image[num].pci_buf);
#endif
vme_free_consistent(image[num].resource, image[num].size_buf,
image[num].kern_buf, image[num].pci_buf);
image[num].kern_buf = NULL;
image[num].pci_buf = 0;
image[num].size_buf = 0;
#ifdef VME_DEBUG
} else {
pr_debug("UniverseII: Buffer not allocated\n");
#endif
}
}
static int __init vme_user_init(void)
{
int retval = 0;
pr_info("VME User Space Access Driver\n");
if (bus_num == 0) {
pr_err("No cards, skipping registration\n");
retval = -ENODEV;
goto err_nocard;
}
if (bus_num > VME_USER_BUS_MAX) {
pr_err("Driver only able to handle %d buses\n",
VME_USER_BUS_MAX);
bus_num = VME_USER_BUS_MAX;
}
retval = vme_register_driver(&vme_user_driver, VME_MAX_SLOTS);
if (retval != 0)
goto err_reg;
return retval;
err_reg:
err_nocard:
return retval;
}
static int vme_user_match(struct vme_dev *vdev)
{
if (vdev->num >= VME_USER_BUS_MAX)
return 0;
return 1;
}
static int vme_user_probe(struct vme_dev *vdev)
{
int i, err;
char name[12];
if (vme_user_bridge != NULL) {
dev_err(&vdev->dev, "Driver can only be loaded for 1 device\n");
err = -EINVAL;
goto err_dev;
}
vme_user_bridge = vdev;
for (i = 0; i < VME_DEVS; i++) {
image[i].kern_buf = NULL;
image[i].pci_buf = 0;
mutex_init(&image[i].mutex);
image[i].device = NULL;
image[i].resource = NULL;
image[i].users = 0;
}
reset_counters();
err = register_chrdev_region(MKDEV(VME_MAJOR, 0), VME_DEVS,
driver_name);
if (err) {
dev_warn(&vdev->dev, "Error getting Major Number %d for driver.\n",
VME_MAJOR);
goto err_region;
}
vme_user_cdev = cdev_alloc();
if (!vme_user_cdev) {
err = -ENOMEM;
goto err_char;
}
vme_user_cdev->ops = &vme_user_fops;
vme_user_cdev->owner = THIS_MODULE;
err = cdev_add(vme_user_cdev, MKDEV(VME_MAJOR, 0), VME_DEVS);
if (err) {
dev_warn(&vdev->dev, "cdev_all failed\n");
goto err_char;
}
for (i = SLAVE_MINOR; i < (SLAVE_MAX + 1); i++) {
image[i].resource = vme_slave_request(vme_user_bridge,
VME_A24, VME_SCT);
if (image[i].resource == NULL) {
dev_warn(&vdev->dev,
"Unable to allocate slave resource\n");
err = -ENOMEM;
goto err_slave;
}
image[i].size_buf = PCI_BUF_SIZE;
image[i].kern_buf = vme_alloc_consistent(image[i].resource,
image[i].size_buf, &image[i].pci_buf);
if (image[i].kern_buf == NULL) {
dev_warn(&vdev->dev,
"Unable to allocate memory for buffer\n");
image[i].pci_buf = 0;
vme_slave_free(image[i].resource);
err = -ENOMEM;
goto err_slave;
}
}
for (i = MASTER_MINOR; i < (MASTER_MAX + 1); i++) {
image[i].resource = vme_master_request(vme_user_bridge,
VME_A32, VME_SCT, VME_D32);
if (image[i].resource == NULL) {
dev_warn(&vdev->dev,
"Unable to allocate master resource\n");
err = -ENOMEM;
goto err_master;
}
image[i].size_buf = PCI_BUF_SIZE;
image[i].kern_buf = kmalloc(image[i].size_buf, GFP_KERNEL);
if (image[i].kern_buf == NULL) {
err = -ENOMEM;
goto err_master_buf;
}
}
vme_user_sysfs_class = class_create(THIS_MODULE, driver_name);
if (IS_ERR(vme_user_sysfs_class)) {
dev_err(&vdev->dev, "Error creating vme_user class.\n");
err = PTR_ERR(vme_user_sysfs_class);
goto err_class;
}
for (i = 0; i < VME_DEVS; i++) {
int num;
switch (type[i]) {
case MASTER_MINOR:
sprintf(name, "bus/vme/m%%d");
break;
case CONTROL_MINOR:
sprintf(name, "bus/vme/ctl");
break;
case SLAVE_MINOR:
sprintf(name, "bus/vme/s%%d");
break;
default:
err = -EINVAL;
goto err_sysfs;
break;
}
num = (type[i] == SLAVE_MINOR) ? i - (MASTER_MAX + 1) : i;
image[i].device = device_create(vme_user_sysfs_class, NULL,
MKDEV(VME_MAJOR, i), NULL, name, num);
if (IS_ERR(image[i].device)) {
dev_info(&vdev->dev, "Error creating sysfs device\n");
err = PTR_ERR(image[i].device);
goto err_sysfs;
}
}
return 0;
i = VME_DEVS;
err_sysfs:
while (i > 0) {
i--;
device_destroy(vme_user_sysfs_class, MKDEV(VME_MAJOR, i));
}
class_destroy(vme_user_sysfs_class);
i = MASTER_MAX + 1;
err_master_buf:
for (i = MASTER_MINOR; i < (MASTER_MAX + 1); i++)
kfree(image[i].kern_buf);
err_master:
while (i > MASTER_MINOR) {
i--;
vme_master_free(image[i].resource);
}
i = SLAVE_MAX + 1;
err_slave:
while (i > SLAVE_MINOR) {
i--;
buf_unalloc(i);
vme_slave_free(image[i].resource);
}
err_class:
cdev_del(vme_user_cdev);
err_char:
unregister_chrdev_region(MKDEV(VME_MAJOR, 0), VME_DEVS);
err_region:
err_dev:
return err;
}
static int vme_user_remove(struct vme_dev *dev)
{
int i;
for (i = 0; i < VME_DEVS; i++) {
mutex_destroy(&image[i].mutex);
device_destroy(vme_user_sysfs_class, MKDEV(VME_MAJOR, i));
}
class_destroy(vme_user_sysfs_class);
for (i = MASTER_MINOR; i < (MASTER_MAX + 1); i++) {
kfree(image[i].kern_buf);
vme_master_free(image[i].resource);
}
for (i = SLAVE_MINOR; i < (SLAVE_MAX + 1); i++) {
vme_slave_set(image[i].resource, 0, 0, 0, 0, VME_A32, 0);
buf_unalloc(i);
vme_slave_free(image[i].resource);
}
cdev_del(vme_user_cdev);
unregister_chrdev_region(MKDEV(VME_MAJOR, 0), VME_DEVS);
return 0;
}
static void __exit vme_user_exit(void)
{
vme_unregister_driver(&vme_user_driver);
}
