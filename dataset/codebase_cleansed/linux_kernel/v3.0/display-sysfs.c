static ssize_t display_show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct display_device *dsp = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%s\n", dsp->name);
}
static ssize_t display_show_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct display_device *dsp = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%s\n", dsp->type);
}
static ssize_t display_show_contrast(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct display_device *dsp = dev_get_drvdata(dev);
ssize_t rc = -ENXIO;
mutex_lock(&dsp->lock);
if (likely(dsp->driver) && dsp->driver->get_contrast)
rc = sprintf(buf, "%d\n", dsp->driver->get_contrast(dsp));
mutex_unlock(&dsp->lock);
return rc;
}
static ssize_t display_store_contrast(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct display_device *dsp = dev_get_drvdata(dev);
ssize_t ret = -EINVAL, size;
int contrast;
char *endp;
contrast = simple_strtoul(buf, &endp, 0);
size = endp - buf;
if (isspace(*endp))
size++;
if (size != count)
return ret;
mutex_lock(&dsp->lock);
if (likely(dsp->driver && dsp->driver->set_contrast)) {
pr_debug("display: set contrast to %d\n", contrast);
dsp->driver->set_contrast(dsp, contrast);
ret = count;
}
mutex_unlock(&dsp->lock);
return ret;
}
static ssize_t display_show_max_contrast(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct display_device *dsp = dev_get_drvdata(dev);
ssize_t rc = -ENXIO;
mutex_lock(&dsp->lock);
if (likely(dsp->driver))
rc = sprintf(buf, "%d\n", dsp->driver->max_contrast);
mutex_unlock(&dsp->lock);
return rc;
}
static int display_suspend(struct device *dev, pm_message_t state)
{
struct display_device *dsp = dev_get_drvdata(dev);
mutex_lock(&dsp->lock);
if (likely(dsp->driver->suspend))
dsp->driver->suspend(dsp, state);
mutex_unlock(&dsp->lock);
return 0;
}
static int display_resume(struct device *dev)
{
struct display_device *dsp = dev_get_drvdata(dev);
mutex_lock(&dsp->lock);
if (likely(dsp->driver->resume))
dsp->driver->resume(dsp);
mutex_unlock(&dsp->lock);
return 0;
}
struct display_device *display_device_register(struct display_driver *driver,
struct device *parent, void *devdata)
{
struct display_device *new_dev = NULL;
int ret = -EINVAL;
if (unlikely(!driver))
return ERR_PTR(ret);
mutex_lock(&allocated_dsp_lock);
ret = idr_pre_get(&allocated_dsp, GFP_KERNEL);
mutex_unlock(&allocated_dsp_lock);
if (!ret)
return ERR_PTR(ret);
new_dev = kzalloc(sizeof(struct display_device), GFP_KERNEL);
if (likely(new_dev) && unlikely(driver->probe(new_dev, devdata))) {
mutex_lock(&allocated_dsp_lock);
ret = idr_get_new(&allocated_dsp, new_dev, &new_dev->idx);
mutex_unlock(&allocated_dsp_lock);
if (!ret) {
new_dev->dev = device_create(display_class, parent,
MKDEV(0, 0), new_dev,
"display%d", new_dev->idx);
if (!IS_ERR(new_dev->dev)) {
new_dev->parent = parent;
new_dev->driver = driver;
mutex_init(&new_dev->lock);
return new_dev;
}
mutex_lock(&allocated_dsp_lock);
idr_remove(&allocated_dsp, new_dev->idx);
mutex_unlock(&allocated_dsp_lock);
ret = -EINVAL;
}
}
kfree(new_dev);
return ERR_PTR(ret);
}
void display_device_unregister(struct display_device *ddev)
{
if (!ddev)
return;
mutex_lock(&ddev->lock);
device_unregister(ddev->dev);
mutex_unlock(&ddev->lock);
mutex_lock(&allocated_dsp_lock);
idr_remove(&allocated_dsp, ddev->idx);
mutex_unlock(&allocated_dsp_lock);
kfree(ddev);
}
static int __init display_class_init(void)
{
display_class = class_create(THIS_MODULE, "display");
if (IS_ERR(display_class)) {
printk(KERN_ERR "Failed to create display class\n");
display_class = NULL;
return -EINVAL;
}
display_class->dev_attrs = display_attrs;
display_class->suspend = display_suspend;
display_class->resume = display_resume;
mutex_init(&allocated_dsp_lock);
return 0;
}
static void __exit display_class_exit(void)
{
class_destroy(display_class);
}
