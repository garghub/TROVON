static ssize_t
store_call_start(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned int cpu=dev->id;
unsigned long call_start = simple_strtoull(buf, NULL, 16);
#ifdef ERR_INJ_DEBUG
printk(KERN_DEBUG "pal_mc_err_inject for cpu%d:\n", cpu);
printk(KERN_DEBUG "err_type_info=%lx,\n", err_type_info[cpu]);
printk(KERN_DEBUG "err_struct_info=%lx,\n", err_struct_info[cpu]);
printk(KERN_DEBUG "err_data_buffer=%lx, %lx, %lx.\n",
err_data_buffer[cpu].data1,
err_data_buffer[cpu].data2,
err_data_buffer[cpu].data3);
#endif
switch (call_start) {
case 0:
break;
case 1:
status[cpu]=ia64_pal_mc_error_inject_phys(err_type_info[cpu],
err_struct_info[cpu],
ia64_tpa(&err_data_buffer[cpu]),
&capabilities[cpu],
&resources[cpu]);
break;
case 2:
status[cpu]=ia64_pal_mc_error_inject_virt(err_type_info[cpu],
err_struct_info[cpu],
ia64_tpa(&err_data_buffer[cpu]),
&capabilities[cpu],
&resources[cpu]);
break;
default:
status[cpu] = -EINVAL;
break;
}
#ifdef ERR_INJ_DEBUG
printk(KERN_DEBUG "Returns: status=%d,\n", (int)status[cpu]);
printk(KERN_DEBUG "capapbilities=%lx,\n", capabilities[cpu]);
printk(KERN_DEBUG "resources=%lx\n", resources[cpu]);
#endif
return size;
}
static ssize_t
show_virtual_to_phys(struct device *dev, struct device_attribute *attr,
char *buf)
{
unsigned int cpu=dev->id;
return sprintf(buf, "%lx\n", phys_addr[cpu]);
}
static ssize_t
store_virtual_to_phys(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned int cpu=dev->id;
u64 virt_addr=simple_strtoull(buf, NULL, 16);
int ret;
ret = get_user_pages(current, current->mm, virt_addr,
1, VM_READ, 0, NULL, NULL);
if (ret<=0) {
#ifdef ERR_INJ_DEBUG
printk("Virtual address %lx is not existing.\n",virt_addr);
#endif
return -EINVAL;
}
phys_addr[cpu] = ia64_tpa(virt_addr);
return size;
}
static ssize_t
show_err_data_buffer(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned int cpu=dev->id;
return sprintf(buf, "%lx, %lx, %lx\n",
err_data_buffer[cpu].data1,
err_data_buffer[cpu].data2,
err_data_buffer[cpu].data3);
}
static ssize_t
store_err_data_buffer(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned int cpu=dev->id;
int ret;
#ifdef ERR_INJ_DEBUG
printk("write err_data_buffer=[%lx,%lx,%lx] on cpu%d\n",
err_data_buffer[cpu].data1,
err_data_buffer[cpu].data2,
err_data_buffer[cpu].data3,
cpu);
#endif
ret=sscanf(buf, "%lx, %lx, %lx",
&err_data_buffer[cpu].data1,
&err_data_buffer[cpu].data2,
&err_data_buffer[cpu].data3);
if (ret!=ERR_DATA_BUFFER_SIZE)
return -EINVAL;
return size;
}
static int err_inject_add_dev(struct device *sys_dev)
{
return sysfs_create_group(&sys_dev->kobj, &err_inject_attr_group);
}
static int err_inject_remove_dev(struct device *sys_dev)
{
sysfs_remove_group(&sys_dev->kobj, &err_inject_attr_group);
return 0;
}
static int err_inject_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct device *sys_dev;
sys_dev = get_cpu_device(cpu);
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
err_inject_add_dev(sys_dev);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
err_inject_remove_dev(sys_dev);
break;
}
return NOTIFY_OK;
}
static int __init
err_inject_init(void)
{
int i;
#ifdef ERR_INJ_DEBUG
printk(KERN_INFO "Enter error injection driver.\n");
#endif
for_each_online_cpu(i) {
err_inject_cpu_callback(&err_inject_cpu_notifier, CPU_ONLINE,
(void *)(long)i);
}
register_hotcpu_notifier(&err_inject_cpu_notifier);
return 0;
}
static void __exit
err_inject_exit(void)
{
int i;
struct device *sys_dev;
#ifdef ERR_INJ_DEBUG
printk(KERN_INFO "Exit error injection driver.\n");
#endif
for_each_online_cpu(i) {
sys_dev = get_cpu_device(i);
sysfs_remove_group(&sys_dev->kobj, &err_inject_attr_group);
}
unregister_hotcpu_notifier(&err_inject_cpu_notifier);
}
