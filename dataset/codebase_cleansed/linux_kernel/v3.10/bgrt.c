static ssize_t show_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", bgrt_tab->version);
}
static ssize_t show_status(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", bgrt_tab->status);
}
static ssize_t show_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", bgrt_tab->image_type);
}
static ssize_t show_xoffset(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", bgrt_tab->image_offset_x);
}
static ssize_t show_yoffset(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", bgrt_tab->image_offset_y);
}
static ssize_t show_image(struct file *file, struct kobject *kobj,
struct bin_attribute *attr, char *buf, loff_t off, size_t count)
{
memcpy(buf, attr->private + off, count);
return count;
}
static int __init bgrt_init(void)
{
int ret;
if (!bgrt_image)
return -ENODEV;
sysfs_bin_attr_init(&image_attr);
image_attr.private = bgrt_image;
image_attr.size = bgrt_image_size;
bgrt_kobj = kobject_create_and_add("bgrt", acpi_kobj);
if (!bgrt_kobj)
return -EINVAL;
ret = sysfs_create_group(bgrt_kobj, &bgrt_attribute_group);
if (ret)
goto out_kobject;
ret = sysfs_create_bin_file(bgrt_kobj, &image_attr);
if (ret)
goto out_group;
return 0;
out_group:
sysfs_remove_group(bgrt_kobj, &bgrt_attribute_group);
out_kobject:
kobject_put(bgrt_kobj);
return ret;
}
