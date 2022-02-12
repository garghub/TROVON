int loongson3_cpu_temp(int cpu)
{
u32 reg, prid_rev;
reg = LOONGSON_CHIPTEMP(cpu);
prid_rev = read_c0_prid() & PRID_REV_MASK;
switch (prid_rev) {
case PRID_REV_LOONGSON3A_R1:
reg = (reg >> 8) & 0xff;
break;
case PRID_REV_LOONGSON3A_R2:
case PRID_REV_LOONGSON3B_R1:
case PRID_REV_LOONGSON3B_R2:
reg = ((reg >> 8) & 0xff) - 100;
break;
case PRID_REV_LOONGSON3A_R3:
reg = (reg & 0xffff)*731/0x4000 - 273;
break;
}
return (int)reg * 1000;
}
static ssize_t get_hwmon_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "cpu-hwmon\n");
}
static ssize_t cpu_temp_label(struct device *dev,
struct device_attribute *attr, char *buf)
{
int id = (to_sensor_dev_attr(attr))->index - 1;
return sprintf(buf, "CPU %d Temperature\n", id);
}
static ssize_t get_cpu_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
int id = (to_sensor_dev_attr(attr))->index - 1;
int value = loongson3_cpu_temp(id);
return sprintf(buf, "%d\n", value);
}
static int create_sysfs_cputemp_files(struct kobject *kobj)
{
int i, ret = 0;
for (i=0; i<nr_packages; i++)
ret = sysfs_create_files(kobj, hwmon_cputemp[i]);
return ret;
}
static void remove_sysfs_cputemp_files(struct kobject *kobj)
{
int i;
for (i=0; i<nr_packages; i++)
sysfs_remove_files(kobj, hwmon_cputemp[i]);
}
static void do_thermal_timer(struct work_struct *work)
{
int i, value, temp_max = 0;
for (i=0; i<nr_packages; i++) {
value = loongson3_cpu_temp(i);
if (value > temp_max)
temp_max = value;
}
if (temp_max <= CPU_THERMAL_THRESHOLD)
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
nr_packages = loongson_sysconf.nr_cpus /
loongson_sysconf.cores_per_package;
ret = sysfs_create_group(&cpu_hwmon_dev->kobj,
&cpu_hwmon_attribute_group);
if (ret) {
pr_err("fail to create loongson hwmon!\n");
goto fail_sysfs_create_group_hwmon;
}
ret = create_sysfs_cputemp_files(&cpu_hwmon_dev->kobj);
if (ret) {
pr_err("fail to create cpu temperature interface!\n");
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
