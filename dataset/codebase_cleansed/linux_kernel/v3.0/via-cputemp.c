static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
int ret;
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct via_cputemp_data *data = dev_get_drvdata(dev);
if (attr->index == SHOW_NAME)
ret = sprintf(buf, "%s\n", data->name);
else
ret = sprintf(buf, "Core %d\n", data->id);
return ret;
}
static ssize_t show_temp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct via_cputemp_data *data = dev_get_drvdata(dev);
u32 eax, edx;
int err;
err = rdmsr_safe_on_cpu(data->id, data->msr, &eax, &edx);
if (err)
return -EAGAIN;
return sprintf(buf, "%lu\n", ((unsigned long)eax & 0xffffff) * 1000);
}
static int __devinit via_cputemp_probe(struct platform_device *pdev)
{
struct via_cputemp_data *data;
struct cpuinfo_x86 *c = &cpu_data(pdev->id);
int err;
u32 eax, edx;
data = kzalloc(sizeof(struct via_cputemp_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
dev_err(&pdev->dev, "Out of memory\n");
goto exit;
}
data->id = pdev->id;
data->name = "via_cputemp";
switch (c->x86_model) {
case 0xA:
case 0xD:
data->msr = 0x1169;
break;
case 0xF:
data->msr = 0x1423;
break;
default:
err = -ENODEV;
goto exit_free;
}
err = rdmsr_safe_on_cpu(data->id, data->msr, &eax, &edx);
if (err) {
dev_err(&pdev->dev,
"Unable to access TEMPERATURE MSR, giving up\n");
goto exit_free;
}
platform_set_drvdata(pdev, data);
err = sysfs_create_group(&pdev->dev.kobj, &via_cputemp_group);
if (err)
goto exit_free;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
dev_err(&pdev->dev, "Class registration failed (%d)\n",
err);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&pdev->dev.kobj, &via_cputemp_group);
exit_free:
platform_set_drvdata(pdev, NULL);
kfree(data);
exit:
return err;
}
static int __devexit via_cputemp_remove(struct platform_device *pdev)
{
struct via_cputemp_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &via_cputemp_group);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static int __cpuinit via_cputemp_device_add(unsigned int cpu)
{
int err;
struct platform_device *pdev;
struct pdev_entry *pdev_entry;
pdev = platform_device_alloc(DRVNAME, cpu);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
pdev_entry = kzalloc(sizeof(struct pdev_entry), GFP_KERNEL);
if (!pdev_entry) {
err = -ENOMEM;
goto exit_device_put;
}
err = platform_device_add(pdev);
if (err) {
pr_err("Device addition failed (%d)\n", err);
goto exit_device_free;
}
pdev_entry->pdev = pdev;
pdev_entry->cpu = cpu;
mutex_lock(&pdev_list_mutex);
list_add_tail(&pdev_entry->list, &pdev_list);
mutex_unlock(&pdev_list_mutex);
return 0;
exit_device_free:
kfree(pdev_entry);
exit_device_put:
platform_device_put(pdev);
exit:
return err;
}
static void __cpuinit via_cputemp_device_remove(unsigned int cpu)
{
struct pdev_entry *p;
mutex_lock(&pdev_list_mutex);
list_for_each_entry(p, &pdev_list, list) {
if (p->cpu == cpu) {
platform_device_unregister(p->pdev);
list_del(&p->list);
mutex_unlock(&pdev_list_mutex);
kfree(p);
return;
}
}
mutex_unlock(&pdev_list_mutex);
}
static int __cpuinit via_cputemp_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long) hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_DOWN_FAILED:
via_cputemp_device_add(cpu);
break;
case CPU_DOWN_PREPARE:
via_cputemp_device_remove(cpu);
break;
}
return NOTIFY_OK;
}
static int __init via_cputemp_init(void)
{
int i, err;
if (cpu_data(0).x86_vendor != X86_VENDOR_CENTAUR) {
printk(KERN_DEBUG DRVNAME ": Not a VIA CPU\n");
err = -ENODEV;
goto exit;
}
err = platform_driver_register(&via_cputemp_driver);
if (err)
goto exit;
for_each_online_cpu(i) {
struct cpuinfo_x86 *c = &cpu_data(i);
if (c->x86 != 6)
continue;
if (c->x86_model < 0x0a)
continue;
if (c->x86_model > 0x0f) {
pr_warn("Unknown CPU model 0x%x\n", c->x86_model);
continue;
}
via_cputemp_device_add(i);
}
#ifndef CONFIG_HOTPLUG_CPU
if (list_empty(&pdev_list)) {
err = -ENODEV;
goto exit_driver_unreg;
}
#endif
register_hotcpu_notifier(&via_cputemp_cpu_notifier);
return 0;
#ifndef CONFIG_HOTPLUG_CPU
exit_driver_unreg:
platform_driver_unregister(&via_cputemp_driver);
#endif
exit:
return err;
}
static void __exit via_cputemp_exit(void)
{
struct pdev_entry *p, *n;
unregister_hotcpu_notifier(&via_cputemp_cpu_notifier);
mutex_lock(&pdev_list_mutex);
list_for_each_entry_safe(p, n, &pdev_list, list) {
platform_device_unregister(p->pdev);
list_del(&p->list);
kfree(p);
}
mutex_unlock(&pdev_list_mutex);
platform_driver_unregister(&via_cputemp_driver);
}
