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
err = rdmsr_safe_on_cpu(data->id, data->msr_temp, &eax, &edx);
if (err)
return -EAGAIN;
return sprintf(buf, "%lu\n", ((unsigned long)eax & 0xffffff) * 1000);
}
static ssize_t show_cpu_vid(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct via_cputemp_data *data = dev_get_drvdata(dev);
u32 eax, edx;
int err;
err = rdmsr_safe_on_cpu(data->id, data->msr_vid, &eax, &edx);
if (err)
return -EAGAIN;
return sprintf(buf, "%d\n", vid_from_reg(~edx & 0x7f, data->vrm));
}
static int via_cputemp_probe(struct platform_device *pdev)
{
struct via_cputemp_data *data;
struct cpuinfo_x86 *c = &cpu_data(pdev->id);
int err;
u32 eax, edx;
data = devm_kzalloc(&pdev->dev, sizeof(struct via_cputemp_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->id = pdev->id;
data->name = "via_cputemp";
switch (c->x86_model) {
case 0xA:
case 0xD:
data->msr_temp = 0x1169;
data->msr_vid = 0x198;
break;
case 0xF:
data->msr_temp = 0x1423;
break;
default:
return -ENODEV;
}
err = rdmsr_safe_on_cpu(data->id, data->msr_temp, &eax, &edx);
if (err) {
dev_err(&pdev->dev,
"Unable to access TEMPERATURE MSR, giving up\n");
return err;
}
platform_set_drvdata(pdev, data);
err = sysfs_create_group(&pdev->dev.kobj, &via_cputemp_group);
if (err)
return err;
if (data->msr_vid)
data->vrm = vid_which_vrm();
if (data->vrm) {
err = device_create_file(&pdev->dev, &dev_attr_cpu0_vid);
if (err)
goto exit_remove;
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
dev_err(&pdev->dev, "Class registration failed (%d)\n",
err);
goto exit_remove;
}
return 0;
exit_remove:
if (data->vrm)
device_remove_file(&pdev->dev, &dev_attr_cpu0_vid);
sysfs_remove_group(&pdev->dev.kobj, &via_cputemp_group);
return err;
}
static int via_cputemp_remove(struct platform_device *pdev)
{
struct via_cputemp_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
if (data->vrm)
device_remove_file(&pdev->dev, &dev_attr_cpu0_vid);
sysfs_remove_group(&pdev->dev.kobj, &via_cputemp_group);
return 0;
}
static int via_cputemp_online(unsigned int cpu)
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
static int via_cputemp_down_prep(unsigned int cpu)
{
struct pdev_entry *p;
mutex_lock(&pdev_list_mutex);
list_for_each_entry(p, &pdev_list, list) {
if (p->cpu == cpu) {
platform_device_unregister(p->pdev);
list_del(&p->list);
mutex_unlock(&pdev_list_mutex);
kfree(p);
return 0;
}
}
mutex_unlock(&pdev_list_mutex);
return 0;
}
static int __init via_cputemp_init(void)
{
int err;
if (!x86_match_cpu(cputemp_ids))
return -ENODEV;
err = platform_driver_register(&via_cputemp_driver);
if (err)
goto exit;
err = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "hwmon/via:online",
via_cputemp_online, via_cputemp_down_prep);
if (err < 0)
goto exit_driver_unreg;
via_temp_online = err;
#ifndef CONFIG_HOTPLUG_CPU
if (list_empty(&pdev_list)) {
err = -ENODEV;
goto exit_hp_unreg;
}
#endif
return 0;
#ifndef CONFIG_HOTPLUG_CPU
exit_hp_unreg:
cpuhp_remove_state_nocalls(via_temp_online);
#endif
exit_driver_unreg:
platform_driver_unregister(&via_cputemp_driver);
exit:
return err;
}
static void __exit via_cputemp_exit(void)
{
cpuhp_remove_state(via_temp_online);
platform_driver_unregister(&via_cputemp_driver);
}
