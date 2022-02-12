static int iio_trig_periodic_rtc_set_state(struct iio_trigger *trig, bool state)
{
struct iio_prtc_trigger_info *trig_info = trig->private_data;
if (trig_info->frequency == 0)
return -EINVAL;
printk(KERN_INFO "trigger frequency is %d\n", trig_info->frequency);
return rtc_irq_set_state(trig_info->rtc, &trig_info->task, state);
}
static ssize_t iio_trig_periodic_read_freq(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_trigger *trig = dev_get_drvdata(dev);
struct iio_prtc_trigger_info *trig_info = trig->private_data;
return sprintf(buf, "%u\n", trig_info->frequency);
}
static ssize_t iio_trig_periodic_write_freq(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_trigger *trig = dev_get_drvdata(dev);
struct iio_prtc_trigger_info *trig_info = trig->private_data;
unsigned long val;
int ret;
ret = strict_strtoul(buf, 10, &val);
if (ret)
goto error_ret;
ret = rtc_irq_set_freq(trig_info->rtc, &trig_info->task, val);
if (ret)
goto error_ret;
trig_info->frequency = val;
return len;
error_ret:
return ret;
}
static void iio_prtc_trigger_poll(void *private_data)
{
iio_trigger_poll(private_data, 0);
}
static int iio_trig_periodic_rtc_probe(struct platform_device *dev)
{
char **pdata = dev->dev.platform_data;
struct iio_prtc_trigger_info *trig_info;
struct iio_trigger *trig, *trig2;
int i, ret;
for (i = 0;; i++) {
if (pdata[i] == NULL)
break;
trig = iio_allocate_trigger("periodic%s", pdata[i]);
if (!trig) {
ret = -ENOMEM;
goto error_free_completed_registrations;
}
list_add(&trig->alloc_list, &iio_prtc_trigger_list);
trig_info = kzalloc(sizeof(*trig_info), GFP_KERNEL);
if (!trig_info) {
ret = -ENOMEM;
goto error_put_trigger_and_remove_from_list;
}
trig->private_data = trig_info;
trig->owner = THIS_MODULE;
trig->set_trigger_state = &iio_trig_periodic_rtc_set_state;
trig_info->rtc
= rtc_class_open(pdata[i]);
if (trig_info->rtc == NULL) {
ret = -EINVAL;
goto error_free_trig_info;
}
trig_info->task.func = iio_prtc_trigger_poll;
trig_info->task.private_data = trig;
ret = rtc_irq_register(trig_info->rtc, &trig_info->task);
if (ret)
goto error_close_rtc;
trig->dev.groups = iio_trig_prtc_attr_groups;
ret = iio_trigger_register(trig);
if (ret)
goto error_unregister_rtc_irq;
}
return 0;
error_unregister_rtc_irq:
rtc_irq_unregister(trig_info->rtc, &trig_info->task);
error_close_rtc:
rtc_class_close(trig_info->rtc);
error_free_trig_info:
kfree(trig_info);
error_put_trigger_and_remove_from_list:
list_del(&trig->alloc_list);
iio_put_trigger(trig);
error_free_completed_registrations:
list_for_each_entry_safe(trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
trig_info = trig->private_data;
rtc_irq_unregister(trig_info->rtc, &trig_info->task);
rtc_class_close(trig_info->rtc);
kfree(trig_info);
iio_trigger_unregister(trig);
}
return ret;
}
static int iio_trig_periodic_rtc_remove(struct platform_device *dev)
{
struct iio_trigger *trig, *trig2;
struct iio_prtc_trigger_info *trig_info;
mutex_lock(&iio_prtc_trigger_list_lock);
list_for_each_entry_safe(trig,
trig2,
&iio_prtc_trigger_list,
alloc_list) {
trig_info = trig->private_data;
rtc_irq_unregister(trig_info->rtc, &trig_info->task);
rtc_class_close(trig_info->rtc);
kfree(trig_info);
iio_trigger_unregister(trig);
}
mutex_unlock(&iio_prtc_trigger_list_lock);
return 0;
}
static int __init iio_trig_periodic_rtc_init(void)
{
return platform_driver_register(&iio_trig_periodic_rtc_driver);
}
static void __exit iio_trig_periodic_rtc_exit(void)
{
return platform_driver_unregister(&iio_trig_periodic_rtc_driver);
}
