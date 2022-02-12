static ssize_t dm_attr_show(struct kobject *kobj, struct attribute *attr,
char *page)
{
struct dm_sysfs_attr *dm_attr;
struct mapped_device *md;
ssize_t ret;
dm_attr = container_of(attr, struct dm_sysfs_attr, attr);
if (!dm_attr->show)
return -EIO;
md = dm_get_from_kobject(kobj);
if (!md)
return -EINVAL;
ret = dm_attr->show(md, page);
dm_put(md);
return ret;
}
static ssize_t dm_attr_name_show(struct mapped_device *md, char *buf)
{
if (dm_copy_name_and_uuid(md, buf, NULL))
return -EIO;
strcat(buf, "\n");
return strlen(buf);
}
static ssize_t dm_attr_uuid_show(struct mapped_device *md, char *buf)
{
if (dm_copy_name_and_uuid(md, NULL, buf))
return -EIO;
strcat(buf, "\n");
return strlen(buf);
}
static ssize_t dm_attr_suspended_show(struct mapped_device *md, char *buf)
{
sprintf(buf, "%d\n", dm_suspended_md(md));
return strlen(buf);
}
int dm_sysfs_init(struct mapped_device *md)
{
return kobject_init_and_add(dm_kobject(md), &dm_ktype,
&disk_to_dev(dm_disk(md))->kobj,
"%s", "dm");
}
void dm_sysfs_exit(struct mapped_device *md)
{
struct kobject *kobj = dm_kobject(md);
kobject_put(kobj);
wait_for_completion(dm_get_completion_from_kobject(kobj));
}
