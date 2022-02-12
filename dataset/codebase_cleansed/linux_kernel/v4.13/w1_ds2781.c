static int w1_ds2781_do_io(struct device *dev, char *buf, int addr,
size_t count, int io)
{
struct w1_slave *sl = container_of(dev, struct w1_slave, dev);
if (addr > DS2781_DATA_SIZE || addr < 0)
return 0;
count = min_t(int, count, DS2781_DATA_SIZE - addr);
if (w1_reset_select_slave(sl) == 0) {
if (io) {
w1_write_8(sl->master, W1_DS2781_WRITE_DATA);
w1_write_8(sl->master, addr);
w1_write_block(sl->master, buf, count);
} else {
w1_write_8(sl->master, W1_DS2781_READ_DATA);
w1_write_8(sl->master, addr);
count = w1_read_block(sl->master, buf, count);
}
}
return count;
}
int w1_ds2781_io(struct device *dev, char *buf, int addr, size_t count,
int io)
{
struct w1_slave *sl = container_of(dev, struct w1_slave, dev);
int ret;
if (!dev)
return -ENODEV;
mutex_lock(&sl->master->bus_mutex);
ret = w1_ds2781_do_io(dev, buf, addr, count, io);
mutex_unlock(&sl->master->bus_mutex);
return ret;
}
int w1_ds2781_eeprom_cmd(struct device *dev, int addr, int cmd)
{
struct w1_slave *sl = container_of(dev, struct w1_slave, dev);
if (!dev)
return -EINVAL;
mutex_lock(&sl->master->bus_mutex);
if (w1_reset_select_slave(sl) == 0) {
w1_write_8(sl->master, cmd);
w1_write_8(sl->master, addr);
}
mutex_unlock(&sl->master->bus_mutex);
return 0;
}
static ssize_t w1_slave_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
return w1_ds2781_io(dev, buf, off, count, 0);
}
static int w1_ds2781_add_slave(struct w1_slave *sl)
{
int ret;
struct platform_device *pdev;
pdev = platform_device_alloc("ds2781-battery", PLATFORM_DEVID_AUTO);
if (!pdev)
return -ENOMEM;
pdev->dev.parent = &sl->dev;
ret = platform_device_add(pdev);
if (ret)
goto pdev_add_failed;
dev_set_drvdata(&sl->dev, pdev);
return 0;
pdev_add_failed:
platform_device_put(pdev);
return ret;
}
static void w1_ds2781_remove_slave(struct w1_slave *sl)
{
struct platform_device *pdev = dev_get_drvdata(&sl->dev);
platform_device_unregister(pdev);
}
