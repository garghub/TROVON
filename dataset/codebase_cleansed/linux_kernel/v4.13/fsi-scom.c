static int put_scom(struct scom_device *scom_dev, uint64_t value,
uint32_t addr)
{
int rc;
uint32_t data;
data = cpu_to_be32(SCOM_RESET_CMD);
rc = fsi_device_write(scom_dev->fsi_dev, SCOM_RESET_REG, &data,
sizeof(uint32_t));
if (rc)
return rc;
data = cpu_to_be32((value >> 32) & 0xffffffff);
rc = fsi_device_write(scom_dev->fsi_dev, SCOM_DATA0_REG, &data,
sizeof(uint32_t));
if (rc)
return rc;
data = cpu_to_be32(value & 0xffffffff);
rc = fsi_device_write(scom_dev->fsi_dev, SCOM_DATA1_REG, &data,
sizeof(uint32_t));
if (rc)
return rc;
data = cpu_to_be32(SCOM_WRITE_CMD | addr);
return fsi_device_write(scom_dev->fsi_dev, SCOM_CMD_REG, &data,
sizeof(uint32_t));
}
static int get_scom(struct scom_device *scom_dev, uint64_t *value,
uint32_t addr)
{
uint32_t result, data;
int rc;
*value = 0ULL;
data = cpu_to_be32(addr);
rc = fsi_device_write(scom_dev->fsi_dev, SCOM_CMD_REG, &data,
sizeof(uint32_t));
if (rc)
return rc;
rc = fsi_device_read(scom_dev->fsi_dev, SCOM_DATA0_REG, &result,
sizeof(uint32_t));
if (rc)
return rc;
*value |= (uint64_t)cpu_to_be32(result) << 32;
rc = fsi_device_read(scom_dev->fsi_dev, SCOM_DATA1_REG, &result,
sizeof(uint32_t));
if (rc)
return rc;
*value |= cpu_to_be32(result);
return 0;
}
static ssize_t scom_read(struct file *filep, char __user *buf, size_t len,
loff_t *offset)
{
int rc;
struct miscdevice *mdev =
(struct miscdevice *)filep->private_data;
struct scom_device *scom = to_scom_dev(mdev);
struct device *dev = &scom->fsi_dev->dev;
uint64_t val;
if (len != sizeof(uint64_t))
return -EINVAL;
rc = get_scom(scom, &val, *offset);
if (rc) {
dev_dbg(dev, "get_scom fail:%d\n", rc);
return rc;
}
rc = copy_to_user(buf, &val, len);
if (rc)
dev_dbg(dev, "copy to user failed:%d\n", rc);
return rc ? rc : len;
}
static ssize_t scom_write(struct file *filep, const char __user *buf,
size_t len, loff_t *offset)
{
int rc;
struct miscdevice *mdev = filep->private_data;
struct scom_device *scom = to_scom_dev(mdev);
struct device *dev = &scom->fsi_dev->dev;
uint64_t val;
if (len != sizeof(uint64_t))
return -EINVAL;
rc = copy_from_user(&val, buf, len);
if (rc) {
dev_dbg(dev, "copy from user failed:%d\n", rc);
return -EINVAL;
}
rc = put_scom(scom, val, *offset);
if (rc) {
dev_dbg(dev, "put_scom failed with:%d\n", rc);
return rc;
}
return len;
}
static loff_t scom_llseek(struct file *file, loff_t offset, int whence)
{
switch (whence) {
case SEEK_CUR:
break;
case SEEK_SET:
file->f_pos = offset;
break;
default:
return -EINVAL;
}
return offset;
}
static int scom_probe(struct device *dev)
{
struct fsi_device *fsi_dev = to_fsi_dev(dev);
struct scom_device *scom;
scom = devm_kzalloc(dev, sizeof(*scom), GFP_KERNEL);
if (!scom)
return -ENOMEM;
scom->idx = ida_simple_get(&scom_ida, 1, INT_MAX, GFP_KERNEL);
snprintf(scom->name, sizeof(scom->name), "scom%d", scom->idx);
scom->fsi_dev = fsi_dev;
scom->mdev.minor = MISC_DYNAMIC_MINOR;
scom->mdev.fops = &scom_fops;
scom->mdev.name = scom->name;
scom->mdev.parent = dev;
list_add(&scom->link, &scom_devices);
return misc_register(&scom->mdev);
}
static int scom_remove(struct device *dev)
{
struct scom_device *scom, *scom_tmp;
struct fsi_device *fsi_dev = to_fsi_dev(dev);
list_for_each_entry_safe(scom, scom_tmp, &scom_devices, link) {
if (scom->fsi_dev == fsi_dev) {
list_del(&scom->link);
ida_simple_remove(&scom_ida, scom->idx);
misc_deregister(&scom->mdev);
}
}
return 0;
}
static int scom_init(void)
{
INIT_LIST_HEAD(&scom_devices);
return fsi_driver_register(&scom_drv);
}
static void scom_exit(void)
{
struct list_head *pos;
struct scom_device *scom;
list_for_each(pos, &scom_devices) {
scom = list_entry(pos, struct scom_device, link);
misc_deregister(&scom->mdev);
devm_kfree(&scom->fsi_dev->dev, scom);
}
fsi_driver_unregister(&scom_drv);
}
