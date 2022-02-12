static void input_polldev_queue_work(struct input_polled_dev *dev)
{
unsigned long delay;
delay = msecs_to_jiffies(dev->poll_interval);
if (delay >= HZ)
delay = round_jiffies_relative(delay);
queue_delayed_work(system_freezable_wq, &dev->work, delay);
}
static void input_polled_device_work(struct work_struct *work)
{
struct input_polled_dev *dev =
container_of(work, struct input_polled_dev, work.work);
dev->poll(dev);
input_polldev_queue_work(dev);
}
static int input_open_polled_device(struct input_dev *input)
{
struct input_polled_dev *dev = input_get_drvdata(input);
if (dev->open)
dev->open(dev);
if (dev->poll_interval > 0)
queue_delayed_work(system_freezable_wq, &dev->work, 0);
return 0;
}
static void input_close_polled_device(struct input_dev *input)
{
struct input_polled_dev *dev = input_get_drvdata(input);
cancel_delayed_work_sync(&dev->work);
if (dev->close)
dev->close(dev);
}
static ssize_t input_polldev_get_poll(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct input_polled_dev *polldev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", polldev->poll_interval);
}
static ssize_t input_polldev_set_poll(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct input_polled_dev *polldev = dev_get_drvdata(dev);
struct input_dev *input = polldev->input;
unsigned long interval;
if (strict_strtoul(buf, 0, &interval))
return -EINVAL;
if (interval < polldev->poll_interval_min)
return -EINVAL;
if (interval > polldev->poll_interval_max)
return -EINVAL;
mutex_lock(&input->mutex);
polldev->poll_interval = interval;
if (input->users) {
cancel_delayed_work_sync(&polldev->work);
if (polldev->poll_interval > 0)
input_polldev_queue_work(polldev);
}
mutex_unlock(&input->mutex);
return count;
}
static ssize_t input_polldev_get_max(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct input_polled_dev *polldev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", polldev->poll_interval_max);
}
static ssize_t input_polldev_get_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct input_polled_dev *polldev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", polldev->poll_interval_min);
}
struct input_polled_dev *input_allocate_polled_device(void)
{
struct input_polled_dev *dev;
dev = kzalloc(sizeof(struct input_polled_dev), GFP_KERNEL);
if (!dev)
return NULL;
dev->input = input_allocate_device();
if (!dev->input) {
kfree(dev);
return NULL;
}
return dev;
}
void input_free_polled_device(struct input_polled_dev *dev)
{
if (dev) {
input_free_device(dev->input);
kfree(dev);
}
}
int input_register_polled_device(struct input_polled_dev *dev)
{
struct input_dev *input = dev->input;
int error;
input_set_drvdata(input, dev);
INIT_DELAYED_WORK(&dev->work, input_polled_device_work);
if (!dev->poll_interval)
dev->poll_interval = 500;
if (!dev->poll_interval_max)
dev->poll_interval_max = dev->poll_interval;
input->open = input_open_polled_device;
input->close = input_close_polled_device;
error = input_register_device(input);
if (error)
return error;
error = sysfs_create_group(&input->dev.kobj,
&input_polldev_attribute_group);
if (error) {
input_unregister_device(input);
return error;
}
input_get_device(input);
return 0;
}
void input_unregister_polled_device(struct input_polled_dev *dev)
{
sysfs_remove_group(&dev->input->dev.kobj,
&input_polldev_attribute_group);
input_unregister_device(dev->input);
}
