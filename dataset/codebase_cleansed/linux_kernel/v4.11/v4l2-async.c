static bool match_i2c(struct v4l2_subdev *sd, struct v4l2_async_subdev *asd)
{
#if IS_ENABLED(CONFIG_I2C)
struct i2c_client *client = i2c_verify_client(sd->dev);
return client &&
asd->match.i2c.adapter_id == client->adapter->nr &&
asd->match.i2c.address == client->addr;
#else
return false;
#endif
}
static bool match_devname(struct v4l2_subdev *sd,
struct v4l2_async_subdev *asd)
{
return !strcmp(asd->match.device_name.name, dev_name(sd->dev));
}
static bool match_of(struct v4l2_subdev *sd, struct v4l2_async_subdev *asd)
{
return !of_node_cmp(of_node_full_name(sd->of_node),
of_node_full_name(asd->match.of.node));
}
static bool match_custom(struct v4l2_subdev *sd, struct v4l2_async_subdev *asd)
{
if (!asd->match.custom.match)
return true;
return asd->match.custom.match(sd->dev, asd);
}
static struct v4l2_async_subdev *v4l2_async_belongs(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *sd)
{
bool (*match)(struct v4l2_subdev *, struct v4l2_async_subdev *);
struct v4l2_async_subdev *asd;
list_for_each_entry(asd, &notifier->waiting, list) {
switch (asd->match_type) {
case V4L2_ASYNC_MATCH_CUSTOM:
match = match_custom;
break;
case V4L2_ASYNC_MATCH_DEVNAME:
match = match_devname;
break;
case V4L2_ASYNC_MATCH_I2C:
match = match_i2c;
break;
case V4L2_ASYNC_MATCH_OF:
match = match_of;
break;
default:
WARN_ON(true);
return NULL;
}
if (match(sd, asd))
return asd;
}
return NULL;
}
static int v4l2_async_test_notify(struct v4l2_async_notifier *notifier,
struct v4l2_subdev *sd,
struct v4l2_async_subdev *asd)
{
int ret;
if (notifier->bound) {
ret = notifier->bound(notifier, sd, asd);
if (ret < 0)
return ret;
}
ret = v4l2_device_register_subdev(notifier->v4l2_dev, sd);
if (ret < 0) {
if (notifier->unbind)
notifier->unbind(notifier, sd, asd);
return ret;
}
list_del(&asd->list);
sd->asd = asd;
sd->notifier = notifier;
list_move(&sd->async_list, &notifier->done);
if (list_empty(&notifier->waiting) && notifier->complete)
return notifier->complete(notifier);
return 0;
}
static void v4l2_async_cleanup(struct v4l2_subdev *sd)
{
v4l2_device_unregister_subdev(sd);
list_del_init(&sd->async_list);
sd->asd = NULL;
sd->dev = NULL;
}
int v4l2_async_notifier_register(struct v4l2_device *v4l2_dev,
struct v4l2_async_notifier *notifier)
{
struct v4l2_subdev *sd, *tmp;
struct v4l2_async_subdev *asd;
int i;
if (!notifier->num_subdevs || notifier->num_subdevs > V4L2_MAX_SUBDEVS)
return -EINVAL;
notifier->v4l2_dev = v4l2_dev;
INIT_LIST_HEAD(&notifier->waiting);
INIT_LIST_HEAD(&notifier->done);
for (i = 0; i < notifier->num_subdevs; i++) {
asd = notifier->subdevs[i];
switch (asd->match_type) {
case V4L2_ASYNC_MATCH_CUSTOM:
case V4L2_ASYNC_MATCH_DEVNAME:
case V4L2_ASYNC_MATCH_I2C:
case V4L2_ASYNC_MATCH_OF:
break;
default:
dev_err(notifier->v4l2_dev ? notifier->v4l2_dev->dev : NULL,
"Invalid match type %u on %p\n",
asd->match_type, asd);
return -EINVAL;
}
list_add_tail(&asd->list, &notifier->waiting);
}
mutex_lock(&list_lock);
list_for_each_entry_safe(sd, tmp, &subdev_list, async_list) {
int ret;
asd = v4l2_async_belongs(notifier, sd);
if (!asd)
continue;
ret = v4l2_async_test_notify(notifier, sd, asd);
if (ret < 0) {
mutex_unlock(&list_lock);
return ret;
}
}
list_add(&notifier->list, &notifier_list);
mutex_unlock(&list_lock);
return 0;
}
void v4l2_async_notifier_unregister(struct v4l2_async_notifier *notifier)
{
struct v4l2_subdev *sd, *tmp;
unsigned int notif_n_subdev = notifier->num_subdevs;
unsigned int n_subdev = min(notif_n_subdev, V4L2_MAX_SUBDEVS);
struct device **dev;
int i = 0;
if (!notifier->v4l2_dev)
return;
dev = kmalloc_array(n_subdev, sizeof(*dev), GFP_KERNEL);
if (!dev) {
dev_err(notifier->v4l2_dev->dev,
"Failed to allocate device cache!\n");
}
mutex_lock(&list_lock);
list_del(&notifier->list);
list_for_each_entry_safe(sd, tmp, &notifier->done, async_list) {
struct device *d;
d = get_device(sd->dev);
v4l2_async_cleanup(sd);
device_release_driver(d);
if (notifier->unbind)
notifier->unbind(notifier, sd, sd->asd);
if (dev)
dev[i++] = d;
else
put_device(d);
}
mutex_unlock(&list_lock);
while (i--) {
struct device *d = dev[i];
if (d && device_attach(d) < 0) {
const char *name = "(none)";
int lock = device_trylock(d);
if (lock && d->driver)
name = d->driver->name;
dev_err(d, "Failed to re-probe to %s\n", name);
if (lock)
device_unlock(d);
}
put_device(d);
}
kfree(dev);
notifier->v4l2_dev = NULL;
}
int v4l2_async_register_subdev(struct v4l2_subdev *sd)
{
struct v4l2_async_notifier *notifier;
if (!sd->of_node && sd->dev)
sd->of_node = sd->dev->of_node;
mutex_lock(&list_lock);
INIT_LIST_HEAD(&sd->async_list);
list_for_each_entry(notifier, &notifier_list, list) {
struct v4l2_async_subdev *asd = v4l2_async_belongs(notifier, sd);
if (asd) {
int ret = v4l2_async_test_notify(notifier, sd, asd);
mutex_unlock(&list_lock);
return ret;
}
}
list_add(&sd->async_list, &subdev_list);
mutex_unlock(&list_lock);
return 0;
}
void v4l2_async_unregister_subdev(struct v4l2_subdev *sd)
{
struct v4l2_async_notifier *notifier = sd->notifier;
if (!sd->asd) {
if (!list_empty(&sd->async_list))
v4l2_async_cleanup(sd);
return;
}
mutex_lock(&list_lock);
list_add(&sd->asd->list, &notifier->waiting);
v4l2_async_cleanup(sd);
if (notifier->unbind)
notifier->unbind(notifier, sd, sd->asd);
mutex_unlock(&list_lock);
}
