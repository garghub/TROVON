static ssize_t resource_to_user(int minor, char __user *buf, size_t count,
loff_t *ppos)
{
ssize_t copied = 0;
if (count > image[minor].size_buf)
count = image[minor].size_buf;
copied = vme_master_read(image[minor].resource, image[minor].kern_buf,
count, *ppos);
if (copied < 0)
return (int)copied;
if (__copy_to_user(buf, image[minor].kern_buf, (unsigned long)copied))
return -EFAULT;
return copied;
}
static ssize_t resource_from_user(unsigned int minor, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count > image[minor].size_buf)
count = image[minor].size_buf;
if (__copy_from_user(image[minor].kern_buf, buf, (unsigned long)count))
return -EFAULT;
return vme_master_write(image[minor].resource, image[minor].kern_buf,
count, *ppos);
}
static ssize_t buffer_to_user(unsigned int minor, char __user *buf,
size_t count, loff_t *ppos)
{
void *image_ptr;
image_ptr = image[minor].kern_buf + *ppos;
if (__copy_to_user(buf, image_ptr, (unsigned long)count))
return -EFAULT;
return count;
}
static ssize_t buffer_from_user(unsigned int minor, const char __user *buf,
size_t count, loff_t *ppos)
{
void *image_ptr;
image_ptr = image[minor].kern_buf + *ppos;
if (__copy_from_user(image_ptr, buf, (unsigned long)count))
return -EFAULT;
return count;
}
static ssize_t vme_user_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
unsigned int minor = MINOR(file_inode(file)->i_rdev);
ssize_t retval;
size_t image_size;
if (minor == CONTROL_MINOR)
return 0;
mutex_lock(&image[minor].mutex);
image_size = vme_get_size(image[minor].resource);
if ((*ppos < 0) || (*ppos > (image_size - 1))) {
mutex_unlock(&image[minor].mutex);
return 0;
}
if (*ppos + count > image_size)
count = image_size - *ppos;
switch (type[minor]) {
case MASTER_MINOR:
retval = resource_to_user(minor, buf, count, ppos);
break;
case SLAVE_MINOR:
retval = buffer_to_user(minor, buf, count, ppos);
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
if (minor == CONTROL_MINOR)
return 0;
mutex_lock(&image[minor].mutex);
image_size = vme_get_size(image[minor].resource);
if ((*ppos < 0) || (*ppos > (image_size - 1))) {
mutex_unlock(&image[minor].mutex);
return 0;
}
if (*ppos + count > image_size)
count = image_size - *ppos;
switch (type[minor]) {
case MASTER_MINOR:
retval = resource_from_user(minor, buf, count, ppos);
break;
case SLAVE_MINOR:
retval = buffer_from_user(minor, buf, count, ppos);
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
unsigned int minor = MINOR(file_inode(file)->i_rdev);
size_t image_size;
loff_t res;
switch (type[minor]) {
case MASTER_MINOR:
case SLAVE_MINOR:
mutex_lock(&image[minor].mutex);
image_size = vme_get_size(image[minor].resource);
res = fixed_size_llseek(file, off, whence, image_size);
mutex_unlock(&image[minor].mutex);
return res;
}
return -EINVAL;
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
return vme_irq_generate(vme_user_bridge,
irq_req.level,
irq_req.statid);
}
break;
case MASTER_MINOR:
switch (cmd) {
case VME_GET_MASTER:
memset(&master, 0, sizeof(struct vme_master));
retval = vme_master_get(image[minor].resource,
&master.enable,
&master.vme_addr,
&master.size, &master.aspace,
&master.cycle, &master.dwidth);
copied = copy_to_user(argp, &master,
sizeof(struct vme_master));
if (copied != 0) {
pr_warn("Partial copy to userspace\n");
return -EFAULT;
}
return retval;
case VME_SET_MASTER:
if (image[minor].mmap_count != 0) {
pr_warn("Can't adjust mapped window\n");
return -EPERM;
}
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
&slave.size, &pci_addr,
&slave.aspace, &slave.cycle);
copied = copy_to_user(argp, &slave,
sizeof(struct vme_slave));
if (copied != 0) {
pr_warn("Partial copy to userspace\n");
return -EFAULT;
}
return retval;
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
struct inode *inode = file_inode(file);
unsigned int minor = MINOR(inode->i_rdev);
mutex_lock(&image[minor].mutex);
ret = vme_user_ioctl(inode, file, cmd, arg);
mutex_unlock(&image[minor].mutex);
return ret;
}
static void vme_user_vm_open(struct vm_area_struct *vma)
{
struct vme_user_vma_priv *vma_priv = vma->vm_private_data;
atomic_inc(&vma_priv->refcnt);
}
static void vme_user_vm_close(struct vm_area_struct *vma)
{
struct vme_user_vma_priv *vma_priv = vma->vm_private_data;
unsigned int minor = vma_priv->minor;
if (!atomic_dec_and_test(&vma_priv->refcnt))
return;
mutex_lock(&image[minor].mutex);
image[minor].mmap_count--;
mutex_unlock(&image[minor].mutex);
kfree(vma_priv);
}
static int vme_user_master_mmap(unsigned int minor, struct vm_area_struct *vma)
{
int err;
struct vme_user_vma_priv *vma_priv;
mutex_lock(&image[minor].mutex);
err = vme_master_mmap(image[minor].resource, vma);
if (err) {
mutex_unlock(&image[minor].mutex);
return err;
}
vma_priv = kmalloc(sizeof(*vma_priv), GFP_KERNEL);
if (!vma_priv) {
mutex_unlock(&image[minor].mutex);
return -ENOMEM;
}
vma_priv->minor = minor;
atomic_set(&vma_priv->refcnt, 1);
vma->vm_ops = &vme_user_vm_ops;
vma->vm_private_data = vma_priv;
image[minor].mmap_count++;
mutex_unlock(&image[minor].mutex);
return 0;
}
static int vme_user_mmap(struct file *file, struct vm_area_struct *vma)
{
unsigned int minor = MINOR(file_inode(file)->i_rdev);
if (type[minor] == MASTER_MINOR)
return vme_user_master_mmap(minor, vma);
return -ENODEV;
}
static int vme_user_match(struct vme_dev *vdev)
{
int i;
int cur_bus = vme_bus_num(vdev);
int cur_slot = vme_slot_num(vdev);
for (i = 0; i < bus_num; i++)
if ((cur_bus == bus[i]) && (cur_slot == vdev->num))
return 1;
return 0;
}
static int vme_user_probe(struct vme_dev *vdev)
{
int i, err;
char *name;
if (vme_user_bridge) {
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
}
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
if (err)
goto err_char;
for (i = SLAVE_MINOR; i < (SLAVE_MAX + 1); i++) {
image[i].resource = vme_slave_request(vme_user_bridge,
VME_A24, VME_SCT);
if (!image[i].resource) {
dev_warn(&vdev->dev,
"Unable to allocate slave resource\n");
err = -ENOMEM;
goto err_slave;
}
image[i].size_buf = PCI_BUF_SIZE;
image[i].kern_buf = vme_alloc_consistent(image[i].resource,
image[i].size_buf, &image[i].pci_buf);
if (!image[i].kern_buf) {
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
if (!image[i].resource) {
dev_warn(&vdev->dev,
"Unable to allocate master resource\n");
err = -ENOMEM;
goto err_master;
}
image[i].size_buf = PCI_BUF_SIZE;
image[i].kern_buf = kmalloc(image[i].size_buf, GFP_KERNEL);
if (!image[i].kern_buf) {
err = -ENOMEM;
vme_master_free(image[i].resource);
goto err_master;
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
name = "bus/vme/m%d";
break;
case CONTROL_MINOR:
name = "bus/vme/ctl";
break;
case SLAVE_MINOR:
name = "bus/vme/s%d";
break;
default:
err = -EINVAL;
goto err_sysfs;
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
err_sysfs:
while (i > 0) {
i--;
device_destroy(vme_user_sysfs_class, MKDEV(VME_MAJOR, i));
}
class_destroy(vme_user_sysfs_class);
i = MASTER_MAX + 1;
err_master:
while (i > MASTER_MINOR) {
i--;
kfree(image[i].kern_buf);
vme_master_free(image[i].resource);
}
i = SLAVE_MAX + 1;
err_slave:
while (i > SLAVE_MINOR) {
i--;
vme_free_consistent(image[i].resource, image[i].size_buf,
image[i].kern_buf, image[i].pci_buf);
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
vme_free_consistent(image[i].resource, image[i].size_buf,
image[i].kern_buf, image[i].pci_buf);
vme_slave_free(image[i].resource);
}
cdev_del(vme_user_cdev);
unregister_chrdev_region(MKDEV(VME_MAJOR, 0), VME_DEVS);
return 0;
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
static void __exit vme_user_exit(void)
{
vme_unregister_driver(&vme_user_driver);
}
