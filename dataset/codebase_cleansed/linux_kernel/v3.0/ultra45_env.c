static u8 env_read(struct env *p, u8 ireg)
{
u8 ret;
spin_lock(&p->lock);
writeb(ireg, p->regs + REG_ADDR);
ret = readb(p->regs + REG_DATA);
spin_unlock(&p->lock);
return ret;
}
static void env_write(struct env *p, u8 ireg, u8 val)
{
spin_lock(&p->lock);
writeb(ireg, p->regs + REG_ADDR);
writeb(val, p->regs + REG_DATA);
spin_unlock(&p->lock);
}
static ssize_t show_fan_speed(struct device *dev, struct device_attribute *attr, char *buf)
{
int fan_nr = to_sensor_dev_attr(attr)->index;
struct env *p = dev_get_drvdata(dev);
int rpm, period;
u8 val;
val = env_read(p, IREG_FAN0 + fan_nr);
period = (int) val << 8;
if (FAN_DATA_VALID(period))
rpm = FAN_PERIOD_TO_RPM(period);
else
rpm = 0;
return sprintf(buf, "%d\n", rpm);
}
static ssize_t set_fan_speed(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int fan_nr = to_sensor_dev_attr(attr)->index;
int rpm = simple_strtol(buf, NULL, 10);
struct env *p = dev_get_drvdata(dev);
int period;
u8 val;
if (!rpm)
return -EINVAL;
period = FAN_RPM_TO_PERIOD(rpm);
val = period >> 8;
env_write(p, IREG_FAN0 + fan_nr, val);
return count;
}
static ssize_t show_fan_fault(struct device *dev, struct device_attribute *attr, char *buf)
{
int fan_nr = to_sensor_dev_attr(attr)->index;
struct env *p = dev_get_drvdata(dev);
u8 val = env_read(p, IREG_FAN_STAT);
return sprintf(buf, "%d\n", (val & (1 << fan_nr)) ? 1 : 0);
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
int temp_nr = to_sensor_dev_attr(attr)->index;
struct env *p = dev_get_drvdata(dev);
s8 val;
val = env_read(p, IREG_LCL_TEMP + temp_nr);
return sprintf(buf, "%d\n", ((int) val) - 64);
}
static ssize_t show_stat_bit(struct device *dev, struct device_attribute *attr, char *buf)
{
int index = to_sensor_dev_attr(attr)->index;
struct env *p = dev_get_drvdata(dev);
u8 val;
val = readb(p->regs + REG_STAT);
return sprintf(buf, "%d\n", (val & (1 << index)) ? 1 : 0);
}
static ssize_t show_fwver(struct device *dev, struct device_attribute *attr, char *buf)
{
struct env *p = dev_get_drvdata(dev);
u8 val;
val = readb(p->regs + REG_STAT);
return sprintf(buf, "%d\n", val >> 4);
}
static ssize_t show_name(struct device *dev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "ultra45\n");
}
static int __devinit env_probe(struct platform_device *op)
{
struct env *p = kzalloc(sizeof(*p), GFP_KERNEL);
int err = -ENOMEM;
if (!p)
goto out;
spin_lock_init(&p->lock);
p->regs = of_ioremap(&op->resource[0], 0, REG_SIZE, "pic16f747");
if (!p->regs)
goto out_free;
err = sysfs_create_group(&op->dev.kobj, &env_group);
if (err)
goto out_iounmap;
p->hwmon_dev = hwmon_device_register(&op->dev);
if (IS_ERR(p->hwmon_dev)) {
err = PTR_ERR(p->hwmon_dev);
goto out_sysfs_remove_group;
}
platform_set_drvdata(op, p);
err = 0;
out:
return err;
out_sysfs_remove_group:
sysfs_remove_group(&op->dev.kobj, &env_group);
out_iounmap:
of_iounmap(&op->resource[0], p->regs, REG_SIZE);
out_free:
kfree(p);
goto out;
}
static int __devexit env_remove(struct platform_device *op)
{
struct env *p = platform_get_drvdata(op);
if (p) {
sysfs_remove_group(&op->dev.kobj, &env_group);
hwmon_device_unregister(p->hwmon_dev);
of_iounmap(&op->resource[0], p->regs, REG_SIZE);
kfree(p);
}
return 0;
}
static int __init env_init(void)
{
return platform_driver_register(&env_driver);
}
static void __exit env_exit(void)
{
platform_driver_unregister(&env_driver);
}
