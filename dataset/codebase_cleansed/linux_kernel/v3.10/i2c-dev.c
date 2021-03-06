static struct i2c_dev *i2c_dev_get_by_minor(unsigned index)
{
struct i2c_dev *i2c_dev;
spin_lock(&i2c_dev_list_lock);
list_for_each_entry(i2c_dev, &i2c_dev_list, list) {
if (i2c_dev->adap->nr == index)
goto found;
}
i2c_dev = NULL;
found:
spin_unlock(&i2c_dev_list_lock);
return i2c_dev;
}
static struct i2c_dev *get_free_i2c_dev(struct i2c_adapter *adap)
{
struct i2c_dev *i2c_dev;
if (adap->nr >= I2C_MINORS) {
printk(KERN_ERR "i2c-dev: Out of device minors (%d)\n",
adap->nr);
return ERR_PTR(-ENODEV);
}
i2c_dev = kzalloc(sizeof(*i2c_dev), GFP_KERNEL);
if (!i2c_dev)
return ERR_PTR(-ENOMEM);
i2c_dev->adap = adap;
spin_lock(&i2c_dev_list_lock);
list_add_tail(&i2c_dev->list, &i2c_dev_list);
spin_unlock(&i2c_dev_list_lock);
return i2c_dev;
}
static void return_i2c_dev(struct i2c_dev *i2c_dev)
{
spin_lock(&i2c_dev_list_lock);
list_del(&i2c_dev->list);
spin_unlock(&i2c_dev_list_lock);
kfree(i2c_dev);
}
static ssize_t show_adapter_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_dev *i2c_dev = i2c_dev_get_by_minor(MINOR(dev->devt));
if (!i2c_dev)
return -ENODEV;
return sprintf(buf, "%s\n", i2c_dev->adap->name);
}
static ssize_t i2cdev_read(struct file *file, char __user *buf, size_t count,
loff_t *offset)
{
char *tmp;
int ret;
struct i2c_client *client = file->private_data;
if (count > 8192)
count = 8192;
tmp = kmalloc(count, GFP_KERNEL);
if (tmp == NULL)
return -ENOMEM;
pr_debug("i2c-dev: i2c-%d reading %zu bytes.\n",
iminor(file_inode(file)), count);
ret = i2c_master_recv(client, tmp, count);
if (ret >= 0)
ret = copy_to_user(buf, tmp, count) ? -EFAULT : ret;
kfree(tmp);
return ret;
}
static ssize_t i2cdev_write(struct file *file, const char __user *buf,
size_t count, loff_t *offset)
{
int ret;
char *tmp;
struct i2c_client *client = file->private_data;
if (count > 8192)
count = 8192;
tmp = memdup_user(buf, count);
if (IS_ERR(tmp))
return PTR_ERR(tmp);
pr_debug("i2c-dev: i2c-%d writing %zu bytes.\n",
iminor(file_inode(file)), count);
ret = i2c_master_send(client, tmp, count);
kfree(tmp);
return ret;
}
static int i2cdev_check(struct device *dev, void *addrp)
{
struct i2c_client *client = i2c_verify_client(dev);
if (!client || client->addr != *(unsigned int *)addrp)
return 0;
return dev->driver ? -EBUSY : 0;
}
static int i2cdev_check_mux_parents(struct i2c_adapter *adapter, int addr)
{
struct i2c_adapter *parent = i2c_parent_is_i2c_adapter(adapter);
int result;
result = device_for_each_child(&adapter->dev, &addr, i2cdev_check);
if (!result && parent)
result = i2cdev_check_mux_parents(parent, addr);
return result;
}
static int i2cdev_check_mux_children(struct device *dev, void *addrp)
{
int result;
if (dev->type == &i2c_adapter_type)
result = device_for_each_child(dev, addrp,
i2cdev_check_mux_children);
else
result = i2cdev_check(dev, addrp);
return result;
}
static int i2cdev_check_addr(struct i2c_adapter *adapter, unsigned int addr)
{
struct i2c_adapter *parent = i2c_parent_is_i2c_adapter(adapter);
int result = 0;
if (parent)
result = i2cdev_check_mux_parents(parent, addr);
if (!result)
result = device_for_each_child(&adapter->dev, &addr,
i2cdev_check_mux_children);
return result;
}
static noinline int i2cdev_ioctl_rdrw(struct i2c_client *client,
unsigned long arg)
{
struct i2c_rdwr_ioctl_data rdwr_arg;
struct i2c_msg *rdwr_pa;
u8 __user **data_ptrs;
int i, res;
if (copy_from_user(&rdwr_arg,
(struct i2c_rdwr_ioctl_data __user *)arg,
sizeof(rdwr_arg)))
return -EFAULT;
if (rdwr_arg.nmsgs > I2C_RDRW_IOCTL_MAX_MSGS)
return -EINVAL;
rdwr_pa = memdup_user(rdwr_arg.msgs,
rdwr_arg.nmsgs * sizeof(struct i2c_msg));
if (IS_ERR(rdwr_pa))
return PTR_ERR(rdwr_pa);
data_ptrs = kmalloc(rdwr_arg.nmsgs * sizeof(u8 __user *), GFP_KERNEL);
if (data_ptrs == NULL) {
kfree(rdwr_pa);
return -ENOMEM;
}
res = 0;
for (i = 0; i < rdwr_arg.nmsgs; i++) {
if (rdwr_pa[i].len > 8192) {
res = -EINVAL;
break;
}
data_ptrs[i] = (u8 __user *)rdwr_pa[i].buf;
rdwr_pa[i].buf = memdup_user(data_ptrs[i], rdwr_pa[i].len);
if (IS_ERR(rdwr_pa[i].buf)) {
res = PTR_ERR(rdwr_pa[i].buf);
break;
}
if (rdwr_pa[i].flags & I2C_M_RECV_LEN) {
if (!(rdwr_pa[i].flags & I2C_M_RD) ||
rdwr_pa[i].buf[0] < 1 ||
rdwr_pa[i].len < rdwr_pa[i].buf[0] +
I2C_SMBUS_BLOCK_MAX) {
res = -EINVAL;
break;
}
rdwr_pa[i].len = rdwr_pa[i].buf[0];
}
}
if (res < 0) {
int j;
for (j = 0; j < i; ++j)
kfree(rdwr_pa[j].buf);
kfree(data_ptrs);
kfree(rdwr_pa);
return res;
}
res = i2c_transfer(client->adapter, rdwr_pa, rdwr_arg.nmsgs);
while (i-- > 0) {
if (res >= 0 && (rdwr_pa[i].flags & I2C_M_RD)) {
if (copy_to_user(data_ptrs[i], rdwr_pa[i].buf,
rdwr_pa[i].len))
res = -EFAULT;
}
kfree(rdwr_pa[i].buf);
}
kfree(data_ptrs);
kfree(rdwr_pa);
return res;
}
static noinline int i2cdev_ioctl_smbus(struct i2c_client *client,
unsigned long arg)
{
struct i2c_smbus_ioctl_data data_arg;
union i2c_smbus_data temp;
int datasize, res;
if (copy_from_user(&data_arg,
(struct i2c_smbus_ioctl_data __user *) arg,
sizeof(struct i2c_smbus_ioctl_data)))
return -EFAULT;
if ((data_arg.size != I2C_SMBUS_BYTE) &&
(data_arg.size != I2C_SMBUS_QUICK) &&
(data_arg.size != I2C_SMBUS_BYTE_DATA) &&
(data_arg.size != I2C_SMBUS_WORD_DATA) &&
(data_arg.size != I2C_SMBUS_PROC_CALL) &&
(data_arg.size != I2C_SMBUS_BLOCK_DATA) &&
(data_arg.size != I2C_SMBUS_I2C_BLOCK_BROKEN) &&
(data_arg.size != I2C_SMBUS_I2C_BLOCK_DATA) &&
(data_arg.size != I2C_SMBUS_BLOCK_PROC_CALL)) {
dev_dbg(&client->adapter->dev,
"size out of range (%x) in ioctl I2C_SMBUS.\n",
data_arg.size);
return -EINVAL;
}
if ((data_arg.read_write != I2C_SMBUS_READ) &&
(data_arg.read_write != I2C_SMBUS_WRITE)) {
dev_dbg(&client->adapter->dev,
"read_write out of range (%x) in ioctl I2C_SMBUS.\n",
data_arg.read_write);
return -EINVAL;
}
if ((data_arg.size == I2C_SMBUS_QUICK) ||
((data_arg.size == I2C_SMBUS_BYTE) &&
(data_arg.read_write == I2C_SMBUS_WRITE)))
return i2c_smbus_xfer(client->adapter, client->addr,
client->flags, data_arg.read_write,
data_arg.command, data_arg.size, NULL);
if (data_arg.data == NULL) {
dev_dbg(&client->adapter->dev,
"data is NULL pointer in ioctl I2C_SMBUS.\n");
return -EINVAL;
}
if ((data_arg.size == I2C_SMBUS_BYTE_DATA) ||
(data_arg.size == I2C_SMBUS_BYTE))
datasize = sizeof(data_arg.data->byte);
else if ((data_arg.size == I2C_SMBUS_WORD_DATA) ||
(data_arg.size == I2C_SMBUS_PROC_CALL))
datasize = sizeof(data_arg.data->word);
else
datasize = sizeof(data_arg.data->block);
if ((data_arg.size == I2C_SMBUS_PROC_CALL) ||
(data_arg.size == I2C_SMBUS_BLOCK_PROC_CALL) ||
(data_arg.size == I2C_SMBUS_I2C_BLOCK_DATA) ||
(data_arg.read_write == I2C_SMBUS_WRITE)) {
if (copy_from_user(&temp, data_arg.data, datasize))
return -EFAULT;
}
if (data_arg.size == I2C_SMBUS_I2C_BLOCK_BROKEN) {
data_arg.size = I2C_SMBUS_I2C_BLOCK_DATA;
if (data_arg.read_write == I2C_SMBUS_READ)
temp.block[0] = I2C_SMBUS_BLOCK_MAX;
}
res = i2c_smbus_xfer(client->adapter, client->addr, client->flags,
data_arg.read_write, data_arg.command, data_arg.size, &temp);
if (!res && ((data_arg.size == I2C_SMBUS_PROC_CALL) ||
(data_arg.size == I2C_SMBUS_BLOCK_PROC_CALL) ||
(data_arg.read_write == I2C_SMBUS_READ))) {
if (copy_to_user(data_arg.data, &temp, datasize))
return -EFAULT;
}
return res;
}
static long i2cdev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct i2c_client *client = file->private_data;
unsigned long funcs;
dev_dbg(&client->adapter->dev, "ioctl, cmd=0x%02x, arg=0x%02lx\n",
cmd, arg);
switch (cmd) {
case I2C_SLAVE:
case I2C_SLAVE_FORCE:
if ((arg > 0x3ff) ||
(((client->flags & I2C_M_TEN) == 0) && arg > 0x7f))
return -EINVAL;
if (cmd == I2C_SLAVE && i2cdev_check_addr(client->adapter, arg))
return -EBUSY;
client->addr = arg;
return 0;
case I2C_TENBIT:
if (arg)
client->flags |= I2C_M_TEN;
else
client->flags &= ~I2C_M_TEN;
return 0;
case I2C_PEC:
if (arg)
client->flags |= I2C_CLIENT_PEC;
else
client->flags &= ~I2C_CLIENT_PEC;
return 0;
case I2C_FUNCS:
funcs = i2c_get_functionality(client->adapter);
return put_user(funcs, (unsigned long __user *)arg);
case I2C_RDWR:
return i2cdev_ioctl_rdrw(client, arg);
case I2C_SMBUS:
return i2cdev_ioctl_smbus(client, arg);
case I2C_RETRIES:
client->adapter->retries = arg;
break;
case I2C_TIMEOUT:
client->adapter->timeout = msecs_to_jiffies(arg * 10);
break;
default:
return -ENOTTY;
}
return 0;
}
static int i2cdev_open(struct inode *inode, struct file *file)
{
unsigned int minor = iminor(inode);
struct i2c_client *client;
struct i2c_adapter *adap;
struct i2c_dev *i2c_dev;
i2c_dev = i2c_dev_get_by_minor(minor);
if (!i2c_dev)
return -ENODEV;
adap = i2c_get_adapter(i2c_dev->adap->nr);
if (!adap)
return -ENODEV;
client = kzalloc(sizeof(*client), GFP_KERNEL);
if (!client) {
i2c_put_adapter(adap);
return -ENOMEM;
}
snprintf(client->name, I2C_NAME_SIZE, "i2c-dev %d", adap->nr);
client->adapter = adap;
file->private_data = client;
return 0;
}
static int i2cdev_release(struct inode *inode, struct file *file)
{
struct i2c_client *client = file->private_data;
i2c_put_adapter(client->adapter);
kfree(client);
file->private_data = NULL;
return 0;
}
static int i2cdev_attach_adapter(struct device *dev, void *dummy)
{
struct i2c_adapter *adap;
struct i2c_dev *i2c_dev;
int res;
if (dev->type != &i2c_adapter_type)
return 0;
adap = to_i2c_adapter(dev);
i2c_dev = get_free_i2c_dev(adap);
if (IS_ERR(i2c_dev))
return PTR_ERR(i2c_dev);
i2c_dev->dev = device_create(i2c_dev_class, &adap->dev,
MKDEV(I2C_MAJOR, adap->nr), NULL,
"i2c-%d", adap->nr);
if (IS_ERR(i2c_dev->dev)) {
res = PTR_ERR(i2c_dev->dev);
goto error;
}
res = device_create_file(i2c_dev->dev, &dev_attr_name);
if (res)
goto error_destroy;
pr_debug("i2c-dev: adapter [%s] registered as minor %d\n",
adap->name, adap->nr);
return 0;
error_destroy:
device_destroy(i2c_dev_class, MKDEV(I2C_MAJOR, adap->nr));
error:
return_i2c_dev(i2c_dev);
return res;
}
static int i2cdev_detach_adapter(struct device *dev, void *dummy)
{
struct i2c_adapter *adap;
struct i2c_dev *i2c_dev;
if (dev->type != &i2c_adapter_type)
return 0;
adap = to_i2c_adapter(dev);
i2c_dev = i2c_dev_get_by_minor(adap->nr);
if (!i2c_dev)
return 0;
device_remove_file(i2c_dev->dev, &dev_attr_name);
return_i2c_dev(i2c_dev);
device_destroy(i2c_dev_class, MKDEV(I2C_MAJOR, adap->nr));
pr_debug("i2c-dev: adapter [%s] unregistered\n", adap->name);
return 0;
}
static int i2cdev_notifier_call(struct notifier_block *nb, unsigned long action,
void *data)
{
struct device *dev = data;
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
return i2cdev_attach_adapter(dev, NULL);
case BUS_NOTIFY_DEL_DEVICE:
return i2cdev_detach_adapter(dev, NULL);
}
return 0;
}
static int __init i2c_dev_init(void)
{
int res;
printk(KERN_INFO "i2c /dev entries driver\n");
res = register_chrdev(I2C_MAJOR, "i2c", &i2cdev_fops);
if (res)
goto out;
i2c_dev_class = class_create(THIS_MODULE, "i2c-dev");
if (IS_ERR(i2c_dev_class)) {
res = PTR_ERR(i2c_dev_class);
goto out_unreg_chrdev;
}
res = bus_register_notifier(&i2c_bus_type, &i2cdev_notifier);
if (res)
goto out_unreg_class;
i2c_for_each_dev(NULL, i2cdev_attach_adapter);
return 0;
out_unreg_class:
class_destroy(i2c_dev_class);
out_unreg_chrdev:
unregister_chrdev(I2C_MAJOR, "i2c");
out:
printk(KERN_ERR "%s: Driver Initialisation failed\n", __FILE__);
return res;
}
static void __exit i2c_dev_exit(void)
{
bus_unregister_notifier(&i2c_bus_type, &i2cdev_notifier);
i2c_for_each_dev(NULL, i2cdev_detach_adapter);
class_destroy(i2c_dev_class);
unregister_chrdev(I2C_MAJOR, "i2c");
}
