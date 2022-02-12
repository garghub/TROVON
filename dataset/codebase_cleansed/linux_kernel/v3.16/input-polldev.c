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
if (dev->poll_interval > 0) {
dev->poll(dev);
input_polldev_queue_work(dev);
}
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
unsigned int interval;
int err;
err = kstrtouint(buf, 0, &interval);
if (err)
return err;
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
static int devm_input_polldev_match(struct device *dev, void *res, void *data)
{
struct input_polled_devres *devres = res;
return devres->polldev == data;
}
static void devm_input_polldev_release(struct device *dev, void *res)
{
struct input_polled_devres *devres = res;
struct input_polled_dev *polldev = devres->polldev;
dev_dbg(dev, "%s: dropping reference/freeing %s\n",
__func__, dev_name(&polldev->input->dev));
input_put_device(polldev->input);
kfree(polldev);
}
static void devm_input_polldev_unregister(struct device *dev, void *res)
{
struct input_polled_devres *devres = res;
struct input_polled_dev *polldev = devres->polldev;
dev_dbg(dev, "%s: unregistering device %s\n",
__func__, dev_name(&polldev->input->dev));
input_unregister_device(polldev->input);
}
struct input_polled_dev *devm_input_allocate_polled_device(struct device *dev)
{
struct input_polled_dev *polldev;
struct input_polled_devres *devres;
devres = devres_alloc(devm_input_polldev_release, sizeof(*devres),
GFP_KERNEL);
if (!devres)
return NULL;
polldev = input_allocate_polled_device();
if (!polldev) {
devres_free(devres);
return NULL;
}
polldev->input->dev.parent = dev;
polldev->devres_managed = true;
devres->polldev = polldev;
devres_add(dev, devres);
return polldev;
}
void input_free_polled_device(struct input_polled_dev *dev)
{
if (dev) {
if (dev->devres_managed)
WARN_ON(devres_destroy(dev->input->dev.parent,
devm_input_polldev_release,
devm_input_polldev_match,
dev));
input_put_device(dev->input);
kfree(dev);
}
}
int input_register_polled_device(struct input_polled_dev *dev)
{
struct input_polled_devres *devres = NULL;
struct input_dev *input = dev->input;
int error;
if (dev->devres_managed) {
devres = devres_alloc(devm_input_polldev_unregister,
sizeof(*devres), GFP_KERNEL);
if (!devres)
return -ENOMEM;
devres->polldev = dev;
}
input_set_drvdata(input, dev);
INIT_DELAYED_WORK(&dev->work, input_polled_device_work);
if (!dev->poll_interval)
dev->poll_interval = 500;
if (!dev->poll_interval_max)
dev->poll_interval_max = dev->poll_interval;
input->open = input_open_polled_device;
input->close = input_close_polled_device;
input->dev.groups = input_polldev_attribute_groups;
error = input_register_device(input);
if (error) {
devres_free(devres);
return error;
}
input_get_device(input);
if (dev->devres_managed) {
dev_dbg(input->dev.parent, "%s: registering %s with devres.\n",
__func__, dev_name(&input->dev));
devres_add(input->dev.parent, devres);
}
return 0;
}
void input_unregister_polled_device(struct input_polled_dev *dev)
{
if (dev->devres_managed)
WARN_ON(devres_destroy(dev->input->dev.parent,
devm_input_polldev_unregister,
devm_input_polldev_match,
dev));
input_unregister_device(dev->input);
}
