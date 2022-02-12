static ssize_t get_hv_confstr(char *page, int query)
{
ssize_t n = hv_confstr(query, (unsigned long)page, PAGE_SIZE - 1);
n = n < 0 ? 0 : min(n, (ssize_t)PAGE_SIZE - 1) - 1;
if (n)
page[n++] = '\n';
page[n] = '\0';
return n;
}
static ssize_t chip_width_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
return sprintf(page, "%u\n", smp_width);
}
static ssize_t chip_height_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
return sprintf(page, "%u\n", smp_height);
}
static ssize_t chip_serial_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
return get_hv_confstr(page, HV_CONFSTR_CHIP_SERIAL_NUM);
}
static ssize_t chip_revision_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
return get_hv_confstr(page, HV_CONFSTR_CHIP_REV);
}
static ssize_t type_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
return sprintf(page, "tilera\n");
}
static ssize_t
hvconfig_bin_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
static size_t size;
if (size == 0)
size = hv_confstr(HV_CONFSTR_HV_CONFIG, 0, 0) - 1;
if (off > size)
return -EINVAL;
if (count > size - off)
count = size - off;
if (count) {
char *hvc;
size = off + count;
hvc = kmalloc(size, GFP_KERNEL);
if (hvc == NULL)
return -ENOMEM;
hv_confstr(HV_CONFSTR_HV_CONFIG, (unsigned long)hvc, size);
memcpy(buf, hvc + off, count);
kfree(hvc);
}
return count;
}
static ssize_t hv_stats_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
int cpu = dev->id;
long lotar = HV_XY_TO_LOTAR(cpu_x(cpu), cpu_y(cpu));
ssize_t n = hv_confstr(HV_CONFSTR_HV_STATS,
(unsigned long)page, PAGE_SIZE - 1,
lotar, 0);
n = n < 0 ? 0 : min(n, (ssize_t)PAGE_SIZE - 1);
page[n] = '\0';
return n;
}
static ssize_t hv_stats_store(struct device *dev,
struct device_attribute *attr,
const char *page,
size_t count)
{
int cpu = dev->id;
long lotar = HV_XY_TO_LOTAR(cpu_x(cpu), cpu_y(cpu));
ssize_t n = hv_confstr(HV_CONFSTR_HV_STATS, 0, 0, lotar, 1);
return n < 0 ? n : count;
}
static int hv_stats_device_add(struct device *dev, struct subsys_interface *sif)
{
int err, cpu = dev->id;
if (!cpu_online(cpu))
return 0;
err = sysfs_create_file(&dev->kobj, &dev_attr_hv_stats.attr);
return err;
}
static void hv_stats_device_remove(struct device *dev,
struct subsys_interface *sif)
{
int cpu = dev->id;
if (cpu_online(cpu))
sysfs_remove_file(&dev->kobj, &dev_attr_hv_stats.attr);
}
static int __init create_sysfs_entries(void)
{
int err = 0;
#define create_cpu_attr(name) \
if (!err) \
err = device_create_file(cpu_subsys.dev_root, &dev_attr_##name);
create_cpu_attr(chip_width);
create_cpu_attr(chip_height);
create_cpu_attr(chip_serial);
create_cpu_attr(chip_revision);
#define create_hv_attr(name) \
if (!err) \
err = sysfs_create_file(hypervisor_kobj, &dev_attr_##name.attr);
create_hv_attr(type);
create_hv_attr(version);
create_hv_attr(config_version);
if (!err)
err = sysfs_create_group(hypervisor_kobj, &board_attr_group);
if (!err) {
sysfs_bin_attr_init(&hvconfig_bin);
hvconfig_bin.attr.name = "hvconfig";
hvconfig_bin.attr.mode = S_IRUGO;
hvconfig_bin.read = hvconfig_bin_read;
hvconfig_bin.size = PAGE_SIZE;
err = sysfs_create_bin_file(hypervisor_kobj, &hvconfig_bin);
}
if (!err) {
int cpu = raw_smp_processor_id();
long lotar = HV_XY_TO_LOTAR(cpu_x(cpu), cpu_y(cpu));
char dummy;
ssize_t n = hv_confstr(HV_CONFSTR_HV_STATS,
(unsigned long) &dummy, 1,
lotar, 0);
if (n >= 0)
err = subsys_interface_register(&hv_stats_interface);
}
return err;
}
