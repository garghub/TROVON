static ssize_t partition_id_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%ld\n", sn_partition_id);
}
static ssize_t coherence_id_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%ld\n", partition_coherence_id());
}
static int __init sgi_uv_sysfs_init(void)
{
unsigned long ret;
if (!is_uv_system())
return -ENODEV;
if (!sgi_uv_kobj)
sgi_uv_kobj = kobject_create_and_add("sgi_uv", firmware_kobj);
if (!sgi_uv_kobj) {
printk(KERN_WARNING "kobject_create_and_add sgi_uv failed\n");
return -EINVAL;
}
ret = sysfs_create_file(sgi_uv_kobj, &partition_id_attr.attr);
if (ret) {
printk(KERN_WARNING "sysfs_create_file partition_id failed\n");
return ret;
}
ret = sysfs_create_file(sgi_uv_kobj, &coherence_id_attr.attr);
if (ret) {
printk(KERN_WARNING "sysfs_create_file coherence_id failed\n");
return ret;
}
return 0;
}
