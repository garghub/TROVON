void ams_sensors(s8 *x, s8 *y, s8 *z)
{
u32 orient = ams_info.vflag? ams_info.orient1 : ams_info.orient2;
if (orient & 0x80)
ams_info.get_xyz(y, x, z);
else
ams_info.get_xyz(x, y, z);
if (orient & 0x04)
*z = ~(*z);
if (orient & 0x02)
*y = ~(*y);
if (orient & 0x01)
*x = ~(*x);
}
static ssize_t ams_show_current(struct device *dev,
struct device_attribute *attr, char *buf)
{
s8 x, y, z;
mutex_lock(&ams_info.lock);
ams_sensors(&x, &y, &z);
mutex_unlock(&ams_info.lock);
return snprintf(buf, PAGE_SIZE, "%d %d %d\n", x, y, z);
}
static void ams_handle_irq(void *data)
{
enum ams_irq irq = *((enum ams_irq *)data);
spin_lock(&ams_info.irq_lock);
ams_info.worker_irqs |= irq;
schedule_work(&ams_info.worker);
spin_unlock(&ams_info.irq_lock);
}
static void ams_worker(struct work_struct *work)
{
unsigned long flags;
u8 irqs_to_clear;
mutex_lock(&ams_info.lock);
spin_lock_irqsave(&ams_info.irq_lock, flags);
irqs_to_clear = ams_info.worker_irqs;
if (ams_info.worker_irqs & AMS_IRQ_FREEFALL) {
if (verbose)
printk(KERN_INFO "ams: freefall detected!\n");
ams_info.worker_irqs &= ~AMS_IRQ_FREEFALL;
}
if (ams_info.worker_irqs & AMS_IRQ_SHOCK) {
if (verbose)
printk(KERN_INFO "ams: shock detected!\n");
ams_info.worker_irqs &= ~AMS_IRQ_SHOCK;
}
spin_unlock_irqrestore(&ams_info.irq_lock, flags);
ams_info.clear_irq(irqs_to_clear);
mutex_unlock(&ams_info.lock);
}
int ams_sensor_attach(void)
{
int result;
const u32 *prop;
prop = of_get_property(ams_info.of_node, "orientation", NULL);
if (!prop)
return -ENODEV;
ams_info.orient1 = *prop;
ams_info.orient2 = *(prop + 1);
result = pmf_register_irq_client(ams_info.of_node,
"accel-int-1",
&ams_freefall_client);
if (result < 0)
return -ENODEV;
ams_info.worker_irqs = 0;
result = pmf_register_irq_client(ams_info.of_node,
"accel-int-2",
&ams_shock_client);
if (result < 0)
goto release_freefall;
ams_info.of_dev = of_platform_device_create(ams_info.of_node, "ams", NULL);
if (!ams_info.of_dev) {
result = -ENODEV;
goto release_shock;
}
result = device_create_file(&ams_info.of_dev->dev, &dev_attr_current);
if (result)
goto release_of;
ams_info.vflag = !!(ams_info.get_vendor() & 0x10);
result = ams_input_init();
if (result)
goto release_device_file;
return result;
release_device_file:
device_remove_file(&ams_info.of_dev->dev, &dev_attr_current);
release_of:
of_device_unregister(ams_info.of_dev);
release_shock:
pmf_unregister_irq_client(&ams_shock_client);
release_freefall:
pmf_unregister_irq_client(&ams_freefall_client);
return result;
}
int __init ams_init(void)
{
struct device_node *np;
spin_lock_init(&ams_info.irq_lock);
mutex_init(&ams_info.lock);
INIT_WORK(&ams_info.worker, ams_worker);
#ifdef CONFIG_SENSORS_AMS_I2C
np = of_find_node_by_name(NULL, "accelerometer");
if (np && of_device_is_compatible(np, "AAPL,accelerometer_1"))
return ams_i2c_init(np);
#endif
#ifdef CONFIG_SENSORS_AMS_PMU
np = of_find_node_by_name(NULL, "sms");
if (np && of_device_is_compatible(np, "sms"))
return ams_pmu_init(np);
#endif
return -ENODEV;
}
void ams_sensor_detach(void)
{
ams_input_exit();
device_remove_file(&ams_info.of_dev->dev, &dev_attr_current);
flush_work(&ams_info.worker);
of_device_unregister(ams_info.of_dev);
pmf_unregister_irq_client(&ams_shock_client);
pmf_unregister_irq_client(&ams_freefall_client);
}
static void __exit ams_exit(void)
{
ams_info.exit();
}
