static struct devcd_entry *dev_to_devcd(struct device *dev)
{
return container_of(dev, struct devcd_entry, devcd_dev);
}
static void devcd_dev_release(struct device *dev)
{
struct devcd_entry *devcd = dev_to_devcd(dev);
devcd->free(devcd->data);
module_put(devcd->owner);
if (devcd->failing_dev->kobj.sd)
sysfs_delete_link(&devcd->failing_dev->kobj, &dev->kobj,
"devcoredump");
put_device(devcd->failing_dev);
kfree(devcd);
}
static void devcd_del(struct work_struct *wk)
{
struct devcd_entry *devcd;
devcd = container_of(wk, struct devcd_entry, del_wk.work);
device_del(&devcd->devcd_dev);
put_device(&devcd->devcd_dev);
}
static ssize_t devcd_data_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t offset, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
struct devcd_entry *devcd = dev_to_devcd(dev);
return devcd->read(buffer, offset, count, devcd->data, devcd->datalen);
}
static ssize_t devcd_data_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t offset, size_t count)
{
struct device *dev = kobj_to_dev(kobj);
struct devcd_entry *devcd = dev_to_devcd(dev);
mod_delayed_work(system_wq, &devcd->del_wk, 0);
return count;
}
static int devcd_free(struct device *dev, void *data)
{
struct devcd_entry *devcd = dev_to_devcd(dev);
flush_delayed_work(&devcd->del_wk);
return 0;
}
static ssize_t disabled_show(struct class *class, struct class_attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", devcd_disabled);
}
static ssize_t disabled_store(struct class *class, struct class_attribute *attr,
const char *buf, size_t count)
{
long tmp = simple_strtol(buf, NULL, 10);
if (tmp != 1)
return -EINVAL;
devcd_disabled = true;
class_for_each_device(&devcd_class, NULL, NULL, devcd_free);
return count;
}
static ssize_t devcd_readv(char *buffer, loff_t offset, size_t count,
void *data, size_t datalen)
{
if (offset > datalen)
return -EINVAL;
if (offset + count > datalen)
count = datalen - offset;
if (count)
memcpy(buffer, ((u8 *)data) + offset, count);
return count;
}
static void devcd_freev(void *data)
{
vfree(data);
}
void dev_coredumpv(struct device *dev, void *data, size_t datalen,
gfp_t gfp)
{
dev_coredumpm(dev, NULL, data, datalen, gfp, devcd_readv, devcd_freev);
}
static int devcd_match_failing(struct device *dev, const void *failing)
{
struct devcd_entry *devcd = dev_to_devcd(dev);
return devcd->failing_dev == failing;
}
static void devcd_free_sgtable(void *data)
{
_devcd_free_sgtable(data);
}
static ssize_t devcd_read_from_sgtable(char *buffer, loff_t offset,
size_t buf_len, void *data,
size_t data_len)
{
struct scatterlist *table = data;
if (offset > data_len)
return -EINVAL;
if (offset + buf_len > data_len)
buf_len = data_len - offset;
return sg_pcopy_to_buffer(table, sg_nents(table), buffer, buf_len,
offset);
}
void dev_coredumpm(struct device *dev, struct module *owner,
void *data, size_t datalen, gfp_t gfp,
ssize_t (*read)(char *buffer, loff_t offset, size_t count,
void *data, size_t datalen),
void (*free)(void *data))
{
static atomic_t devcd_count = ATOMIC_INIT(0);
struct devcd_entry *devcd;
struct device *existing;
if (devcd_disabled)
goto free;
existing = class_find_device(&devcd_class, NULL, dev,
devcd_match_failing);
if (existing) {
put_device(existing);
goto free;
}
if (!try_module_get(owner))
goto free;
devcd = kzalloc(sizeof(*devcd), gfp);
if (!devcd)
goto put_module;
devcd->owner = owner;
devcd->data = data;
devcd->datalen = datalen;
devcd->read = read;
devcd->free = free;
devcd->failing_dev = get_device(dev);
device_initialize(&devcd->devcd_dev);
dev_set_name(&devcd->devcd_dev, "devcd%d",
atomic_inc_return(&devcd_count));
devcd->devcd_dev.class = &devcd_class;
if (device_add(&devcd->devcd_dev))
goto put_device;
if (sysfs_create_link(&devcd->devcd_dev.kobj, &dev->kobj,
"failing_device"))
;
if (sysfs_create_link(&dev->kobj, &devcd->devcd_dev.kobj,
"devcoredump"))
;
INIT_DELAYED_WORK(&devcd->del_wk, devcd_del);
schedule_delayed_work(&devcd->del_wk, DEVCD_TIMEOUT);
return;
put_device:
put_device(&devcd->devcd_dev);
put_module:
module_put(owner);
free:
free(data);
}
void dev_coredumpsg(struct device *dev, struct scatterlist *table,
size_t datalen, gfp_t gfp)
{
dev_coredumpm(dev, NULL, table, datalen, gfp, devcd_read_from_sgtable,
devcd_free_sgtable);
}
static int __init devcoredump_init(void)
{
return class_register(&devcd_class);
}
static void __exit devcoredump_exit(void)
{
class_for_each_device(&devcd_class, NULL, NULL, devcd_free);
class_unregister(&devcd_class);
}
