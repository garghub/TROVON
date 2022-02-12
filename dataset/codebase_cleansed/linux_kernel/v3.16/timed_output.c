static ssize_t enable_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct timed_output_dev *tdev = dev_get_drvdata(dev);
int remaining = tdev->get_time(tdev);
return sprintf(buf, "%d\n", remaining);
}
static ssize_t enable_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
struct timed_output_dev *tdev = dev_get_drvdata(dev);
int value;
if (sscanf(buf, "%d", &value) != 1)
return -EINVAL;
tdev->enable(tdev, value);
return size;
}
static int create_timed_output_class(void)
{
if (!timed_output_class) {
timed_output_class = class_create(THIS_MODULE, "timed_output");
if (IS_ERR(timed_output_class))
return PTR_ERR(timed_output_class);
atomic_set(&device_count, 0);
timed_output_class->dev_groups = timed_output_groups;
}
return 0;
}
int timed_output_dev_register(struct timed_output_dev *tdev)
{
int ret;
if (!tdev || !tdev->name || !tdev->enable || !tdev->get_time)
return -EINVAL;
ret = create_timed_output_class();
if (ret < 0)
return ret;
tdev->index = atomic_inc_return(&device_count);
tdev->dev = device_create(timed_output_class, NULL,
MKDEV(0, tdev->index), NULL, "%s", tdev->name);
if (IS_ERR(tdev->dev))
return PTR_ERR(tdev->dev);
dev_set_drvdata(tdev->dev, tdev);
tdev->state = 0;
return 0;
}
void timed_output_dev_unregister(struct timed_output_dev *tdev)
{
tdev->enable(tdev, 0);
device_destroy(timed_output_class, MKDEV(0, tdev->index));
}
static int __init timed_output_init(void)
{
return create_timed_output_class();
}
static void __exit timed_output_exit(void)
{
class_destroy(timed_output_class);
}
