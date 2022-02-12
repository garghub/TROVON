int v4l2_device_register(struct device *dev, struct v4l2_device *v4l2_dev)
{
if (v4l2_dev == NULL)
return -EINVAL;
INIT_LIST_HEAD(&v4l2_dev->subdevs);
spin_lock_init(&v4l2_dev->lock);
v4l2_prio_init(&v4l2_dev->prio);
kref_init(&v4l2_dev->ref);
get_device(dev);
v4l2_dev->dev = dev;
if (dev == NULL) {
if (WARN_ON(!v4l2_dev->name[0]))
return -EINVAL;
return 0;
}
if (!v4l2_dev->name[0])
snprintf(v4l2_dev->name, sizeof(v4l2_dev->name), "%s %s",
dev->driver->name, dev_name(dev));
if (!dev_get_drvdata(dev))
dev_set_drvdata(dev, v4l2_dev);
return 0;
}
static void v4l2_device_release(struct kref *ref)
{
struct v4l2_device *v4l2_dev =
container_of(ref, struct v4l2_device, ref);
if (v4l2_dev->release)
v4l2_dev->release(v4l2_dev);
}
int v4l2_device_put(struct v4l2_device *v4l2_dev)
{
return kref_put(&v4l2_dev->ref, v4l2_device_release);
}
int v4l2_device_set_name(struct v4l2_device *v4l2_dev, const char *basename,
atomic_t *instance)
{
int num = atomic_inc_return(instance) - 1;
int len = strlen(basename);
if (basename[len - 1] >= '0' && basename[len - 1] <= '9')
snprintf(v4l2_dev->name, sizeof(v4l2_dev->name),
"%s-%d", basename, num);
else
snprintf(v4l2_dev->name, sizeof(v4l2_dev->name),
"%s%d", basename, num);
return num;
}
void v4l2_device_disconnect(struct v4l2_device *v4l2_dev)
{
if (v4l2_dev->dev == NULL)
return;
if (dev_get_drvdata(v4l2_dev->dev) == v4l2_dev)
dev_set_drvdata(v4l2_dev->dev, NULL);
put_device(v4l2_dev->dev);
v4l2_dev->dev = NULL;
}
void v4l2_device_unregister(struct v4l2_device *v4l2_dev)
{
struct v4l2_subdev *sd, *next;
if (v4l2_dev == NULL || !v4l2_dev->name[0])
return;
v4l2_device_disconnect(v4l2_dev);
list_for_each_entry_safe(sd, next, &v4l2_dev->subdevs, list) {
v4l2_device_unregister_subdev(sd);
#if IS_ENABLED(CONFIG_I2C)
if (sd->flags & V4L2_SUBDEV_FL_IS_I2C) {
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (client)
i2c_unregister_device(client);
continue;
}
#endif
#if defined(CONFIG_SPI)
if (sd->flags & V4L2_SUBDEV_FL_IS_SPI) {
struct spi_device *spi = v4l2_get_subdevdata(sd);
if (spi)
spi_unregister_device(spi);
continue;
}
#endif
}
v4l2_dev->name[0] = '\0';
}
int v4l2_device_register_subdev(struct v4l2_device *v4l2_dev,
struct v4l2_subdev *sd)
{
#if defined(CONFIG_MEDIA_CONTROLLER)
struct media_entity *entity = &sd->entity;
#endif
int err;
if (v4l2_dev == NULL || sd == NULL || !sd->name[0])
return -EINVAL;
WARN_ON(sd->v4l2_dev != NULL);
sd->owner_v4l2_dev = v4l2_dev->dev && v4l2_dev->dev->driver &&
sd->owner == v4l2_dev->dev->driver->owner;
if (!sd->owner_v4l2_dev && !try_module_get(sd->owner))
return -ENODEV;
sd->v4l2_dev = v4l2_dev;
if (sd->internal_ops && sd->internal_ops->registered) {
err = sd->internal_ops->registered(sd);
if (err)
goto error_module;
}
err = v4l2_ctrl_add_handler(v4l2_dev->ctrl_handler, sd->ctrl_handler, NULL);
if (err)
goto error_unregister;
#if defined(CONFIG_MEDIA_CONTROLLER)
if (v4l2_dev->mdev) {
err = media_device_register_entity(v4l2_dev->mdev, entity);
if (err < 0)
goto error_unregister;
}
#endif
spin_lock(&v4l2_dev->lock);
list_add_tail(&sd->list, &v4l2_dev->subdevs);
spin_unlock(&v4l2_dev->lock);
return 0;
error_unregister:
if (sd->internal_ops && sd->internal_ops->unregistered)
sd->internal_ops->unregistered(sd);
error_module:
if (!sd->owner_v4l2_dev)
module_put(sd->owner);
sd->v4l2_dev = NULL;
return err;
}
static void v4l2_device_release_subdev_node(struct video_device *vdev)
{
struct v4l2_subdev *sd = video_get_drvdata(vdev);
sd->devnode = NULL;
kfree(vdev);
}
int v4l2_device_register_subdev_nodes(struct v4l2_device *v4l2_dev)
{
struct video_device *vdev;
struct v4l2_subdev *sd;
int err;
list_for_each_entry(sd, &v4l2_dev->subdevs, list) {
if (!(sd->flags & V4L2_SUBDEV_FL_HAS_DEVNODE))
continue;
vdev = kzalloc(sizeof(*vdev), GFP_KERNEL);
if (!vdev) {
err = -ENOMEM;
goto clean_up;
}
video_set_drvdata(vdev, sd);
strlcpy(vdev->name, sd->name, sizeof(vdev->name));
vdev->v4l2_dev = v4l2_dev;
vdev->fops = &v4l2_subdev_fops;
vdev->release = v4l2_device_release_subdev_node;
vdev->ctrl_handler = sd->ctrl_handler;
err = __video_register_device(vdev, VFL_TYPE_SUBDEV, -1, 1,
sd->owner);
if (err < 0) {
kfree(vdev);
goto clean_up;
}
#if defined(CONFIG_MEDIA_CONTROLLER)
sd->entity.info.dev.major = VIDEO_MAJOR;
sd->entity.info.dev.minor = vdev->minor;
#endif
sd->devnode = vdev;
}
return 0;
clean_up:
list_for_each_entry(sd, &v4l2_dev->subdevs, list) {
if (!sd->devnode)
break;
video_unregister_device(sd->devnode);
}
return err;
}
void v4l2_device_unregister_subdev(struct v4l2_subdev *sd)
{
struct v4l2_device *v4l2_dev;
if (sd == NULL || sd->v4l2_dev == NULL)
return;
v4l2_dev = sd->v4l2_dev;
spin_lock(&v4l2_dev->lock);
list_del(&sd->list);
spin_unlock(&v4l2_dev->lock);
if (sd->internal_ops && sd->internal_ops->unregistered)
sd->internal_ops->unregistered(sd);
sd->v4l2_dev = NULL;
#if defined(CONFIG_MEDIA_CONTROLLER)
if (v4l2_dev->mdev) {
media_entity_remove_links(&sd->entity);
media_device_unregister_entity(&sd->entity);
}
#endif
video_unregister_device(sd->devnode);
if (!sd->owner_v4l2_dev)
module_put(sd->owner);
}
