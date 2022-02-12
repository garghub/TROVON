static ssize_t memconsole_read(struct file *filp, struct kobject *kobp,
struct bin_attribute *bin_attr, char *buf,
loff_t pos, size_t count)
{
return memory_read_from_buffer(buf, count, &pos, memconsole_baseaddr,
memconsole_length);
}
void memconsole_setup(void *baseaddr, size_t length)
{
memconsole_baseaddr = baseaddr;
memconsole_length = length;
}
int memconsole_sysfs_init(void)
{
memconsole_bin_attr.size = memconsole_length;
return sysfs_create_bin_file(firmware_kobj, &memconsole_bin_attr);
}
void memconsole_exit(void)
{
sysfs_remove_bin_file(firmware_kobj, &memconsole_bin_attr);
}
