static bool match_i2c(struct device *dev, struct v4l2_async_subdev *asd)
{
#if IS_ENABLED(CONFIG_I2C)
struct i2c_client *client = i2c_verify_client(dev);
return client &&
asd->bus_type == V4L2_ASYNC_BUS_I2C &&
asd->match.i2c.adapter_id == client->adapter->nr &&
asd->match.i2c.address == client->addr;
#else
return false;
#endif
}
static bool match_platform(struct device *dev, struct v4l2_async_subdev *asd)
{
return asd->bus_type == V4L2_ASYNC_BUS_PLATFORM &&
!strcmp(asd->match.platform.name, dev_name(dev));
}
static struct v4l2_async_subdev *v4l2_async_belongs(struct v4l2_async_notifier *notifier,
struct v4l2_async_subdev_list *asdl)
{
struct v4l2_subdev *sd = v4l2_async_to_subdev(asdl);
struct v4l2_async_subdev *asd;
bool (*match)(struct device *,
struct v4l2_async_subdev *);
list_for_each_entry(asd, &notifier->waiting, list) {
switch (asd->bus_type) {
case V4L2_ASYNC_BUS_CUSTOM:
match = asd->match.custom.match;
if (!match)
return asd;
break;
case V4L2_ASYNC_BUS_PLATFORM:
match = match_platform;
break;
case V4L2_ASYNC_BUS_I2C:
match = match_i2c;
break;
default:
WARN_ON(true);
return NULL;
}
if (match(sd->dev, asd))
return asd;
}
return NULL;
}
static int v4l2_async_test_notify(struct v4l2_async_notifier *notifier,
struct v4l2_async_subdev_list *asdl,
struct v4l2_async_subdev *asd)
{
struct v4l2_subdev *sd = v4l2_async_to_subdev(asdl);
int ret;
list_del(&asd->list);
asdl->asd = asd;
asdl->notifier = notifier;
if (notifier->bound) {
ret = notifier->bound(notifier, sd, asd);
if (ret < 0)
return ret;
}
list_move(&asdl->list, &notifier->done);
ret = v4l2_device_register_subdev(notifier->v4l2_dev, sd);
if (ret < 0) {
if (notifier->unbind)
notifier->unbind(notifier, sd, asd);
return ret;
}
if (list_empty(&notifier->waiting) && notifier->complete)
return notifier->complete(notifier);
return 0;
}
static void v4l2_async_cleanup(struct v4l2_async_subdev_list *asdl)
{
struct v4l2_subdev *sd = v4l2_async_to_subdev(asdl);
v4l2_device_unregister_subdev(sd);
list_del_init(&asdl->list);
asdl->asd = NULL;
sd->dev = NULL;
}
int v4l2_async_notifier_register(struct v4l2_device *v4l2_dev,
struct v4l2_async_notifier *notifier)
{
struct v4l2_async_subdev_list *asdl, *tmp;
struct v4l2_async_subdev *asd;
int i;
if (!notifier->num_subdevs || notifier->num_subdevs > V4L2_MAX_SUBDEVS)
return -EINVAL;
notifier->v4l2_dev = v4l2_dev;
INIT_LIST_HEAD(&notifier->waiting);
INIT_LIST_HEAD(&notifier->done);
for (i = 0; i < notifier->num_subdevs; i++) {
asd = notifier->subdev[i];
switch (asd->bus_type) {
case V4L2_ASYNC_BUS_CUSTOM:
case V4L2_ASYNC_BUS_PLATFORM:
case V4L2_ASYNC_BUS_I2C:
break;
default:
dev_err(notifier->v4l2_dev ? notifier->v4l2_dev->dev : NULL,
"Invalid bus-type %u on %p\n",
asd->bus_type, asd);
return -EINVAL;
}
list_add_tail(&asd->list, &notifier->waiting);
}
mutex_lock(&list_lock);
list_add(&notifier->list, &notifier_list);
list_for_each_entry_safe(asdl, tmp, &subdev_list, list) {
int ret;
asd = v4l2_async_belongs(notifier, asdl);
if (!asd)
continue;
ret = v4l2_async_test_notify(notifier, asdl, asd);
if (ret < 0) {
mutex_unlock(&list_lock);
return ret;
}
}
mutex_unlock(&list_lock);
return 0;
}
void v4l2_async_notifier_unregister(struct v4l2_async_notifier *notifier)
{
struct v4l2_async_subdev_list *asdl, *tmp;
unsigned int notif_n_subdev = notifier->num_subdevs;
unsigned int n_subdev = min(notif_n_subdev, V4L2_MAX_SUBDEVS);
struct device *dev[n_subdev];
int i = 0;
mutex_lock(&list_lock);
list_del(&notifier->list);
list_for_each_entry_safe(asdl, tmp, &notifier->done, list) {
struct v4l2_subdev *sd = v4l2_async_to_subdev(asdl);
dev[i] = get_device(sd->dev);
v4l2_async_cleanup(asdl);
device_release_driver(dev[i++]);
if (notifier->unbind)
notifier->unbind(notifier, sd, sd->asdl.asd);
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
}
int v4l2_async_register_subdev(struct v4l2_subdev *sd)
{
struct v4l2_async_subdev_list *asdl = &sd->asdl;
struct v4l2_async_notifier *notifier;
mutex_lock(&list_lock);
INIT_LIST_HEAD(&asdl->list);
list_for_each_entry(notifier, &notifier_list, list) {
struct v4l2_async_subdev *asd = v4l2_async_belongs(notifier, asdl);
if (asd) {
int ret = v4l2_async_test_notify(notifier, asdl, asd);
mutex_unlock(&list_lock);
return ret;
}
}
list_add(&asdl->list, &subdev_list);
mutex_unlock(&list_lock);
return 0;
}
void v4l2_async_unregister_subdev(struct v4l2_subdev *sd)
{
struct v4l2_async_subdev_list *asdl = &sd->asdl;
struct v4l2_async_notifier *notifier = asdl->notifier;
if (!asdl->asd) {
if (!list_empty(&asdl->list))
v4l2_async_cleanup(asdl);
return;
}
mutex_lock(&list_lock);
list_add(&asdl->asd->list, &notifier->waiting);
v4l2_async_cleanup(asdl);
if (notifier->unbind)
notifier->unbind(notifier, sd, sd->asdl.asd);
mutex_unlock(&list_lock);
}
