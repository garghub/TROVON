int devfreq_event_enable_edev(struct devfreq_event_dev *edev)
{
int ret = 0;
if (!edev || !edev->desc)
return -EINVAL;
mutex_lock(&edev->lock);
if (edev->desc->ops && edev->desc->ops->enable
&& edev->enable_count == 0) {
ret = edev->desc->ops->enable(edev);
if (ret < 0)
goto err;
}
edev->enable_count++;
err:
mutex_unlock(&edev->lock);
return ret;
}
int devfreq_event_disable_edev(struct devfreq_event_dev *edev)
{
int ret = 0;
if (!edev || !edev->desc)
return -EINVAL;
mutex_lock(&edev->lock);
if (edev->enable_count <= 0) {
dev_warn(&edev->dev, "unbalanced enable_count\n");
ret = -EIO;
goto err;
}
if (edev->desc->ops && edev->desc->ops->disable
&& edev->enable_count == 1) {
ret = edev->desc->ops->disable(edev);
if (ret < 0)
goto err;
}
edev->enable_count--;
err:
mutex_unlock(&edev->lock);
return ret;
}
bool devfreq_event_is_enabled(struct devfreq_event_dev *edev)
{
bool enabled = false;
if (!edev || !edev->desc)
return enabled;
mutex_lock(&edev->lock);
if (edev->enable_count > 0)
enabled = true;
mutex_unlock(&edev->lock);
return enabled;
}
int devfreq_event_set_event(struct devfreq_event_dev *edev)
{
int ret;
if (!edev || !edev->desc)
return -EINVAL;
if (!edev->desc->ops || !edev->desc->ops->set_event)
return -EINVAL;
if (!devfreq_event_is_enabled(edev))
return -EPERM;
mutex_lock(&edev->lock);
ret = edev->desc->ops->set_event(edev);
mutex_unlock(&edev->lock);
return ret;
}
int devfreq_event_get_event(struct devfreq_event_dev *edev,
struct devfreq_event_data *edata)
{
int ret;
if (!edev || !edev->desc)
return -EINVAL;
if (!edev->desc->ops || !edev->desc->ops->get_event)
return -EINVAL;
if (!devfreq_event_is_enabled(edev))
return -EINVAL;
edata->total_count = edata->load_count = 0;
mutex_lock(&edev->lock);
ret = edev->desc->ops->get_event(edev, edata);
if (ret < 0)
edata->total_count = edata->load_count = 0;
mutex_unlock(&edev->lock);
return ret;
}
int devfreq_event_reset_event(struct devfreq_event_dev *edev)
{
int ret = 0;
if (!edev || !edev->desc)
return -EINVAL;
if (!devfreq_event_is_enabled(edev))
return -EPERM;
mutex_lock(&edev->lock);
if (edev->desc->ops && edev->desc->ops->reset)
ret = edev->desc->ops->reset(edev);
mutex_unlock(&edev->lock);
return ret;
}
struct devfreq_event_dev *devfreq_event_get_edev_by_phandle(struct device *dev,
int index)
{
struct device_node *node;
struct devfreq_event_dev *edev;
if (!dev->of_node)
return ERR_PTR(-EINVAL);
node = of_parse_phandle(dev->of_node, "devfreq-events", index);
if (!node)
return ERR_PTR(-ENODEV);
mutex_lock(&devfreq_event_list_lock);
list_for_each_entry(edev, &devfreq_event_list, node) {
if (edev->dev.parent && edev->dev.parent->of_node == node)
goto out;
}
list_for_each_entry(edev, &devfreq_event_list, node) {
if (!strcmp(edev->desc->name, node->name))
goto out;
}
edev = NULL;
out:
mutex_unlock(&devfreq_event_list_lock);
if (!edev) {
of_node_put(node);
return ERR_PTR(-ENODEV);
}
of_node_put(node);
return edev;
}
int devfreq_event_get_edev_count(struct device *dev)
{
int count;
if (!dev->of_node) {
dev_err(dev, "device does not have a device node entry\n");
return -EINVAL;
}
count = of_property_count_elems_of_size(dev->of_node, "devfreq-events",
sizeof(u32));
if (count < 0) {
dev_err(dev,
"failed to get the count of devfreq-event in %s node\n",
dev->of_node->full_name);
return count;
}
return count;
}
static void devfreq_event_release_edev(struct device *dev)
{
struct devfreq_event_dev *edev = to_devfreq_event(dev);
kfree(edev);
}
struct devfreq_event_dev *devfreq_event_add_edev(struct device *dev,
struct devfreq_event_desc *desc)
{
struct devfreq_event_dev *edev;
static atomic_t event_no = ATOMIC_INIT(0);
int ret;
if (!dev || !desc)
return ERR_PTR(-EINVAL);
if (!desc->name || !desc->ops)
return ERR_PTR(-EINVAL);
if (!desc->ops->set_event || !desc->ops->get_event)
return ERR_PTR(-EINVAL);
edev = kzalloc(sizeof(struct devfreq_event_dev), GFP_KERNEL);
if (!edev)
return ERR_PTR(-ENOMEM);
mutex_init(&edev->lock);
edev->desc = desc;
edev->enable_count = 0;
edev->dev.parent = dev;
edev->dev.class = devfreq_event_class;
edev->dev.release = devfreq_event_release_edev;
dev_set_name(&edev->dev, "event.%d", atomic_inc_return(&event_no) - 1);
ret = device_register(&edev->dev);
if (ret < 0) {
put_device(&edev->dev);
return ERR_PTR(ret);
}
dev_set_drvdata(&edev->dev, edev);
INIT_LIST_HEAD(&edev->node);
mutex_lock(&devfreq_event_list_lock);
list_add(&edev->node, &devfreq_event_list);
mutex_unlock(&devfreq_event_list_lock);
return edev;
}
int devfreq_event_remove_edev(struct devfreq_event_dev *edev)
{
if (!edev)
return -EINVAL;
WARN_ON(edev->enable_count);
mutex_lock(&devfreq_event_list_lock);
list_del(&edev->node);
mutex_unlock(&devfreq_event_list_lock);
device_unregister(&edev->dev);
return 0;
}
static int devm_devfreq_event_match(struct device *dev, void *res, void *data)
{
struct devfreq_event_dev **r = res;
if (WARN_ON(!r || !*r))
return 0;
return *r == data;
}
static void devm_devfreq_event_release(struct device *dev, void *res)
{
devfreq_event_remove_edev(*(struct devfreq_event_dev **)res);
}
struct devfreq_event_dev *devm_devfreq_event_add_edev(struct device *dev,
struct devfreq_event_desc *desc)
{
struct devfreq_event_dev **ptr, *edev;
ptr = devres_alloc(devm_devfreq_event_release, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
edev = devfreq_event_add_edev(dev, desc);
if (IS_ERR(edev)) {
devres_free(ptr);
return ERR_PTR(-ENOMEM);
}
*ptr = edev;
devres_add(dev, ptr);
return edev;
}
void devm_devfreq_event_remove_edev(struct device *dev,
struct devfreq_event_dev *edev)
{
WARN_ON(devres_release(dev, devm_devfreq_event_release,
devm_devfreq_event_match, edev));
}
static ssize_t name_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct devfreq_event_dev *edev = to_devfreq_event(dev);
if (!edev || !edev->desc)
return -EINVAL;
return sprintf(buf, "%s\n", edev->desc->name);
}
static ssize_t enable_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct devfreq_event_dev *edev = to_devfreq_event(dev);
if (!edev || !edev->desc)
return -EINVAL;
return sprintf(buf, "%d\n", edev->enable_count);
}
static int __init devfreq_event_init(void)
{
devfreq_event_class = class_create(THIS_MODULE, "devfreq-event");
if (IS_ERR(devfreq_event_class)) {
pr_err("%s: couldn't create class\n", __FILE__);
return PTR_ERR(devfreq_event_class);
}
devfreq_event_class->dev_groups = devfreq_event_groups;
return 0;
}
static void __exit devfreq_event_exit(void)
{
class_destroy(devfreq_event_class);
}
