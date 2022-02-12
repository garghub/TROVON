static ssize_t dio_show_id(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dio_dev *d;
d = to_dio_dev(dev);
return sprintf(buf, "0x%02x\n", (d->id & 0xff));
}
static ssize_t dio_show_ipl(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dio_dev *d;
d = to_dio_dev(dev);
return sprintf(buf, "0x%02x\n", d->ipl);
}
static ssize_t dio_show_secid(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dio_dev *d;
d = to_dio_dev(dev);
return sprintf(buf, "0x%02x\n", ((d->id >> 8)& 0xff));
}
static ssize_t dio_show_name(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dio_dev *d;
d = to_dio_dev(dev);
return sprintf(buf, "%s\n", d->name);
}
static ssize_t dio_show_resource(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dio_dev *d = to_dio_dev(dev);
return sprintf(buf, "0x%08lx 0x%08lx 0x%08lx\n",
(unsigned long)dio_resource_start(d),
(unsigned long)dio_resource_end(d),
dio_resource_flags(d));
}
int dio_create_sysfs_dev_files(struct dio_dev *d)
{
struct device *dev = &d->dev;
int error;
if ((error = device_create_file(dev, &dev_attr_id)) ||
(error = device_create_file(dev, &dev_attr_ipl)) ||
(error = device_create_file(dev, &dev_attr_secid)) ||
(error = device_create_file(dev, &dev_attr_name)) ||
(error = device_create_file(dev, &dev_attr_resource)))
return error;
return 0;
}
