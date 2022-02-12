int w1_ds2780_io(struct device *dev, char *buf, int addr, size_t count,
int io)
{
struct w1_slave *sl = container_of(dev, struct w1_slave, dev);
if (!dev)
return -ENODEV;
mutex_lock(&sl->master->mutex);
if (addr > DS2780_DATA_SIZE || addr < 0) {
count = 0;
goto out;
}
count = min_t(int, count, DS2780_DATA_SIZE - addr);
if (w1_reset_select_slave(sl) == 0) {
if (io) {
w1_write_8(sl->master, W1_DS2780_WRITE_DATA);
w1_write_8(sl->master, addr);
w1_write_block(sl->master, buf, count);
} else {
w1_write_8(sl->master, W1_DS2780_READ_DATA);
w1_write_8(sl->master, addr);
count = w1_read_block(sl->master, buf, count);
}
}
out:
mutex_unlock(&sl->master->mutex);
return count;
}
int w1_ds2780_eeprom_cmd(struct device *dev, int addr, int cmd)
{
struct w1_slave *sl = container_of(dev, struct w1_slave, dev);
if (!dev)
return -EINVAL;
mutex_lock(&sl->master->mutex);
if (w1_reset_select_slave(sl) == 0) {
w1_write_8(sl->master, cmd);
w1_write_8(sl->master, addr);
}
mutex_unlock(&sl->master->mutex);
return 0;
}
static ssize_t w1_ds2780_read_bin(struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
return w1_ds2780_io(dev, buf, off, count, 0);
}
static int new_bat_id(void)
{
int ret;
while (1) {
int id;
ret = idr_pre_get(&bat_idr, GFP_KERNEL);
if (ret == 0)
return -ENOMEM;
mutex_lock(&bat_idr_lock);
ret = idr_get_new(&bat_idr, NULL, &id);
mutex_unlock(&bat_idr_lock);
if (ret == 0) {
ret = id & MAX_ID_MASK;
break;
} else if (ret == -EAGAIN) {
continue;
} else {
break;
}
}
return ret;
}
static void release_bat_id(int id)
{
mutex_lock(&bat_idr_lock);
idr_remove(&bat_idr, id);
mutex_unlock(&bat_idr_lock);
}
static int w1_ds2780_add_slave(struct w1_slave *sl)
{
int ret;
int id;
struct platform_device *pdev;
id = new_bat_id();
if (id < 0) {
ret = id;
goto noid;
}
pdev = platform_device_alloc("ds2780-battery", id);
if (!pdev) {
ret = -ENOMEM;
goto pdev_alloc_failed;
}
pdev->dev.parent = &sl->dev;
ret = platform_device_add(pdev);
if (ret)
goto pdev_add_failed;
ret = sysfs_create_bin_file(&sl->dev.kobj, &w1_ds2780_bin_attr);
if (ret)
goto bin_attr_failed;
dev_set_drvdata(&sl->dev, pdev);
return 0;
bin_attr_failed:
pdev_add_failed:
platform_device_unregister(pdev);
pdev_alloc_failed:
release_bat_id(id);
noid:
return ret;
}
static void w1_ds2780_remove_slave(struct w1_slave *sl)
{
struct platform_device *pdev = dev_get_drvdata(&sl->dev);
int id = pdev->id;
platform_device_unregister(pdev);
release_bat_id(id);
sysfs_remove_bin_file(&sl->dev.kobj, &w1_ds2780_bin_attr);
}
static int __init w1_ds2780_init(void)
{
idr_init(&bat_idr);
return w1_register_family(&w1_ds2780_family);
}
static void __exit w1_ds2780_exit(void)
{
w1_unregister_family(&w1_ds2780_family);
idr_destroy(&bat_idr);
}
