static ssize_t iio_sysfs_trig_add(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
int ret;
unsigned long input;
ret = strict_strtoul(buf, 10, &input);
if (ret)
return ret;
ret = iio_sysfs_trigger_probe(input);
if (ret)
return ret;
return len;
}
static ssize_t iio_sysfs_trig_remove(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
int ret;
unsigned long input;
ret = strict_strtoul(buf, 10, &input);
if (ret)
return ret;
ret = iio_sysfs_trigger_remove(input);
if (ret)
return ret;
return len;
}
static ssize_t iio_sysfs_trigger_poll(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_trigger *trig = dev_get_drvdata(dev);
iio_trigger_poll_chained(trig, 0);
return count;
}
static int iio_sysfs_trigger_probe(int id)
{
struct iio_sysfs_trig *t;
int ret;
bool foundit = false;
mutex_lock(&iio_syfs_trig_list_mut);
list_for_each_entry(t, &iio_sysfs_trig_list, l)
if (id == t->id) {
foundit = true;
break;
}
if (foundit) {
ret = -EINVAL;
goto out1;
}
t = kmalloc(sizeof(*t), GFP_KERNEL);
if (t == NULL) {
ret = -ENOMEM;
goto out1;
}
t->id = id;
t->trig = iio_allocate_trigger("sysfstrig%d", id);
if (!t->trig) {
ret = -ENOMEM;
goto free_t;
}
t->trig->dev.groups = iio_sysfs_trigger_attr_groups;
t->trig->owner = THIS_MODULE;
t->trig->dev.parent = &iio_sysfs_trig_dev;
ret = iio_trigger_register(t->trig);
if (ret)
goto out2;
list_add(&t->l, &iio_sysfs_trig_list);
__module_get(THIS_MODULE);
mutex_unlock(&iio_syfs_trig_list_mut);
return 0;
out2:
iio_put_trigger(t->trig);
free_t:
kfree(t);
out1:
mutex_unlock(&iio_syfs_trig_list_mut);
return ret;
}
static int iio_sysfs_trigger_remove(int id)
{
bool foundit = false;
struct iio_sysfs_trig *t;
mutex_lock(&iio_syfs_trig_list_mut);
list_for_each_entry(t, &iio_sysfs_trig_list, l)
if (id == t->id) {
foundit = true;
break;
}
if (!foundit) {
mutex_unlock(&iio_syfs_trig_list_mut);
return -EINVAL;
}
iio_trigger_unregister(t->trig);
iio_free_trigger(t->trig);
list_del(&t->l);
kfree(t);
module_put(THIS_MODULE);
mutex_unlock(&iio_syfs_trig_list_mut);
return 0;
}
static int __init iio_sysfs_trig_init(void)
{
device_initialize(&iio_sysfs_trig_dev);
dev_set_name(&iio_sysfs_trig_dev, "iio_sysfs_trigger");
return device_add(&iio_sysfs_trig_dev);
}
static void __exit iio_sysfs_trig_exit(void)
{
device_unregister(&iio_sysfs_trig_dev);
}
