static int devfreq_userspace_func(struct devfreq *df, unsigned long *freq)
{
struct userspace_data *data = df->data;
if (data->valid) {
unsigned long adjusted_freq = data->user_frequency;
if (df->max_freq && adjusted_freq > df->max_freq)
adjusted_freq = df->max_freq;
if (df->min_freq && adjusted_freq < df->min_freq)
adjusted_freq = df->min_freq;
*freq = adjusted_freq;
} else {
*freq = df->previous_freq;
}
return 0;
}
static ssize_t store_freq(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct devfreq *devfreq = to_devfreq(dev);
struct userspace_data *data;
unsigned long wanted;
int err = 0;
mutex_lock(&devfreq->lock);
data = devfreq->data;
sscanf(buf, "%lu", &wanted);
data->user_frequency = wanted;
data->valid = true;
err = update_devfreq(devfreq);
if (err == 0)
err = count;
mutex_unlock(&devfreq->lock);
return err;
}
static ssize_t show_freq(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct devfreq *devfreq = to_devfreq(dev);
struct userspace_data *data;
int err = 0;
mutex_lock(&devfreq->lock);
data = devfreq->data;
if (data->valid)
err = sprintf(buf, "%lu\n", data->user_frequency);
else
err = sprintf(buf, "undefined\n");
mutex_unlock(&devfreq->lock);
return err;
}
static int userspace_init(struct devfreq *devfreq)
{
int err = 0;
struct userspace_data *data = kzalloc(sizeof(struct userspace_data),
GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto out;
}
data->valid = false;
devfreq->data = data;
err = sysfs_create_group(&devfreq->dev.kobj, &dev_attr_group);
out:
return err;
}
static void userspace_exit(struct devfreq *devfreq)
{
sysfs_remove_group(&devfreq->dev.kobj, &dev_attr_group);
kfree(devfreq->data);
devfreq->data = NULL;
}
