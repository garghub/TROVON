static ssize_t memconsole_read(struct file *filp, struct kobject *kobp,
struct bin_attribute *bin_attr, char *buf,
loff_t pos, size_t count)
{
if (WARN_ON_ONCE(!memconsole_read_func))
return -EIO;
return memconsole_read_func(buf, pos, count);
}
void memconsole_setup(ssize_t (*read_func)(char *, loff_t, size_t))
{
memconsole_read_func = read_func;
}
int memconsole_sysfs_init(void)
{
return sysfs_create_bin_file(firmware_kobj, &memconsole_bin_attr);
}
void memconsole_exit(void)
{
sysfs_remove_bin_file(firmware_kobj, &memconsole_bin_attr);
}
