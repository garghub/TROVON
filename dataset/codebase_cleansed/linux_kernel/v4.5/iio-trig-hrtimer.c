static
ssize_t iio_hrtimer_show_sampling_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_trigger *trig = to_iio_trigger(dev);
struct iio_hrtimer_info *info = iio_trigger_get_drvdata(trig);
return snprintf(buf, PAGE_SIZE, "%lu\n", info->sampling_frequency);
}
static
ssize_t iio_hrtimer_store_sampling_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_trigger *trig = to_iio_trigger(dev);
struct iio_hrtimer_info *info = iio_trigger_get_drvdata(trig);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (!val || val > NSEC_PER_SEC)
return -EINVAL;
info->sampling_frequency = val;
info->period = ktime_set(0, NSEC_PER_SEC / val);
return len;
}
static enum hrtimer_restart iio_hrtimer_trig_handler(struct hrtimer *timer)
{
struct iio_hrtimer_info *info;
info = container_of(timer, struct iio_hrtimer_info, timer);
hrtimer_forward_now(timer, info->period);
iio_trigger_poll(info->swt.trigger);
return HRTIMER_RESTART;
}
static int iio_trig_hrtimer_set_state(struct iio_trigger *trig, bool state)
{
struct iio_hrtimer_info *trig_info;
trig_info = iio_trigger_get_drvdata(trig);
if (state)
hrtimer_start(&trig_info->timer, trig_info->period,
HRTIMER_MODE_REL);
else
hrtimer_cancel(&trig_info->timer);
return 0;
}
static struct iio_sw_trigger *iio_trig_hrtimer_probe(const char *name)
{
struct iio_hrtimer_info *trig_info;
int ret;
trig_info = kzalloc(sizeof(*trig_info), GFP_KERNEL);
if (!trig_info)
return ERR_PTR(-ENOMEM);
trig_info->swt.trigger = iio_trigger_alloc("%s", name);
if (!trig_info->swt.trigger) {
ret = -ENOMEM;
goto err_free_trig_info;
}
iio_trigger_set_drvdata(trig_info->swt.trigger, trig_info);
trig_info->swt.trigger->ops = &iio_hrtimer_trigger_ops;
trig_info->swt.trigger->dev.groups = iio_hrtimer_attr_groups;
hrtimer_init(&trig_info->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
trig_info->timer.function = iio_hrtimer_trig_handler;
trig_info->sampling_frequency = HRTIMER_DEFAULT_SAMPLING_FREQUENCY;
trig_info->period = ktime_set(0, NSEC_PER_SEC /
trig_info->sampling_frequency);
ret = iio_trigger_register(trig_info->swt.trigger);
if (ret)
goto err_free_trigger;
iio_swt_group_init_type_name(&trig_info->swt, name, &iio_hrtimer_type);
return &trig_info->swt;
err_free_trigger:
iio_trigger_free(trig_info->swt.trigger);
err_free_trig_info:
kfree(trig_info);
return ERR_PTR(ret);
}
static int iio_trig_hrtimer_remove(struct iio_sw_trigger *swt)
{
struct iio_hrtimer_info *trig_info;
trig_info = iio_trigger_get_drvdata(swt->trigger);
iio_trigger_unregister(swt->trigger);
hrtimer_cancel(&trig_info->timer);
iio_trigger_free(swt->trigger);
kfree(trig_info);
return 0;
}
