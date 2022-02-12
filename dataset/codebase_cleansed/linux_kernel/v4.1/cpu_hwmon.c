int loongson3_cpu_temp(int cpu)
{
u32 reg;
reg = LOONGSON_CHIPTEMP(cpu);
if (loongson_sysconf.cputype == Loongson_3A)
reg = (reg >> 8) & 0xff;
else if (loongson_sysconf.cputype == Loongson_3B)
reg = ((reg >> 8) & 0xff) - 100;
return (int)reg * 1000;
}
static ssize_t get_hwmon_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "cpu-hwmon\n");
}
static ssize_t cpu0_temp_label(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "CPU 0 Temprature\n");
}
static ssize_t cpu1_temp_label(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "CPU 1 Temprature\n");
}
static ssize_t get_cpu0_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
int value = loongson3_cpu_temp(0);
return sprintf(buf, "%d\n", value);
}
static ssize_t get_cpu1_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
int value = loongson3_cpu_temp(1);
return sprintf(buf, "%d\n", value);
}
static int create_sysfs_cputemp_files(struct kobject *kobj)
{
int ret;
ret = sysfs_create_files(kobj, hwmon_cputemp1);
if (ret)
goto sysfs_create_temp1_fail;
if (loongson_sysconf.nr_cpus <= loongson_sysconf.cores_per_package)
return 0;
ret = sysfs_create_files(kobj, hwmon_cputemp2);
if (ret)
goto sysfs_create_temp2_fail;
return 0;
sysfs_create_temp2_fail:
sysfs_remove_files(kobj, hwmon_cputemp1);
sysfs_create_temp1_fail:
return -1;
}
static void remove_sysfs_cputemp_files(struct kobject *kobj)
{
sysfs_remove_files(&cpu_hwmon_dev->kobj, hwmon_cputemp1);
if (loongson_sysconf.nr_cpus > loongson_sysconf.cores_per_package)
sysfs_remove_files(&cpu_hwmon_dev->kobj, hwmon_cputemp2);
}
static void do_thermal_timer(struct work_struct *work)
{
int value = loongson3_cpu_temp(0);
if (value <= CPU_THERMAL_THRESHOLD)
schedule_delayed_work(&thermal_work, msecs_to_jiffies(5000));
else
orderly_poweroff(true);
}
static int __init loongson_hwmon_init(void)
{
int ret;
pr_info("Loongson Hwmon Enter...\n");
cpu_hwmon_dev = hwmon_device_register(NULL);
if (IS_ERR(cpu_hwmon_dev)) {
ret = -ENOMEM;
pr_err("hwmon_device_register fail!\n");
goto fail_hwmon_device_register;
}
ret = sysfs_create_group(&cpu_hwmon_dev->kobj,
&cpu_hwmon_attribute_group);
if (ret) {
pr_err("fail to create loongson hwmon!\n");
goto fail_sysfs_create_group_hwmon;
}
ret = create_sysfs_cputemp_files(&cpu_hwmon_dev->kobj);
if (ret) {
pr_err("fail to create cpu temprature interface!\n");
goto fail_create_sysfs_cputemp_files;
}
INIT_DEFERRABLE_WORK(&thermal_work, do_thermal_timer);
schedule_delayed_work(&thermal_work, msecs_to_jiffies(20000));
return ret;
fail_create_sysfs_cputemp_files:
sysfs_remove_group(&cpu_hwmon_dev->kobj,
&cpu_hwmon_attribute_group);
fail_sysfs_create_group_hwmon:
hwmon_device_unregister(cpu_hwmon_dev);
fail_hwmon_device_register:
return ret;
}
static void __exit loongson_hwmon_exit(void)
{
cancel_delayed_work_sync(&thermal_work);
remove_sysfs_cputemp_files(&cpu_hwmon_dev->kobj);
sysfs_remove_group(&cpu_hwmon_dev->kobj,
&cpu_hwmon_attribute_group);
hwmon_device_unregister(cpu_hwmon_dev);
}
