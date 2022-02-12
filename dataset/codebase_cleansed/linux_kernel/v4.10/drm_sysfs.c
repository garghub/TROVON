static char *drm_devnode(struct device *dev, umode_t *mode)
{
return kasprintf(GFP_KERNEL, "dri/%s", dev_name(dev));
}
int drm_sysfs_init(void)
{
int err;
drm_class = class_create(THIS_MODULE, "drm");
if (IS_ERR(drm_class))
return PTR_ERR(drm_class);
err = class_create_file(drm_class, &class_attr_version.attr);
if (err) {
class_destroy(drm_class);
drm_class = NULL;
return err;
}
drm_class->devnode = drm_devnode;
return 0;
}
void drm_sysfs_destroy(void)
{
if (IS_ERR_OR_NULL(drm_class))
return;
class_remove_file(drm_class, &class_attr_version.attr);
class_destroy(drm_class);
drm_class = NULL;
}
static ssize_t status_store(struct device *device,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct drm_connector *connector = to_drm_connector(device);
struct drm_device *dev = connector->dev;
enum drm_connector_force old_force;
int ret;
ret = mutex_lock_interruptible(&dev->mode_config.mutex);
if (ret)
return ret;
old_force = connector->force;
if (sysfs_streq(buf, "detect"))
connector->force = 0;
else if (sysfs_streq(buf, "on"))
connector->force = DRM_FORCE_ON;
else if (sysfs_streq(buf, "on-digital"))
connector->force = DRM_FORCE_ON_DIGITAL;
else if (sysfs_streq(buf, "off"))
connector->force = DRM_FORCE_OFF;
else
ret = -EINVAL;
if (old_force != connector->force || !connector->force) {
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] force updated from %d to %d or reprobing\n",
connector->base.id,
connector->name,
old_force, connector->force);
connector->funcs->fill_modes(connector,
dev->mode_config.max_width,
dev->mode_config.max_height);
}
mutex_unlock(&dev->mode_config.mutex);
return ret ? ret : count;
}
static ssize_t status_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
enum drm_connector_status status;
status = READ_ONCE(connector->status);
return snprintf(buf, PAGE_SIZE, "%s\n",
drm_get_connector_status_name(status));
}
static ssize_t dpms_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
int dpms;
dpms = READ_ONCE(connector->dpms);
return snprintf(buf, PAGE_SIZE, "%s\n",
drm_get_dpms_name(dpms));
}
static ssize_t enabled_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
bool enabled;
enabled = READ_ONCE(connector->encoder);
return snprintf(buf, PAGE_SIZE, enabled ? "enabled\n" : "disabled\n");
}
static ssize_t edid_show(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf, loff_t off,
size_t count)
{
struct device *connector_dev = kobj_to_dev(kobj);
struct drm_connector *connector = to_drm_connector(connector_dev);
unsigned char *edid;
size_t size;
ssize_t ret = 0;
mutex_lock(&connector->dev->mode_config.mutex);
if (!connector->edid_blob_ptr)
goto unlock;
edid = connector->edid_blob_ptr->data;
size = connector->edid_blob_ptr->length;
if (!edid)
goto unlock;
if (off >= size)
goto unlock;
if (off + count > size)
count = size - off;
memcpy(buf, edid + off, count);
ret = count;
unlock:
mutex_unlock(&connector->dev->mode_config.mutex);
return ret;
}
static ssize_t modes_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
struct drm_display_mode *mode;
int written = 0;
mutex_lock(&connector->dev->mode_config.mutex);
list_for_each_entry(mode, &connector->modes, head) {
written += snprintf(buf + written, PAGE_SIZE - written, "%s\n",
mode->name);
}
mutex_unlock(&connector->dev->mode_config.mutex);
return written;
}
int drm_sysfs_connector_add(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
if (connector->kdev)
return 0;
connector->kdev =
device_create_with_groups(drm_class, dev->primary->kdev, 0,
connector, connector_dev_groups,
"card%d-%s", dev->primary->index,
connector->name);
DRM_DEBUG("adding \"%s\" to sysfs\n",
connector->name);
if (IS_ERR(connector->kdev)) {
DRM_ERROR("failed to register connector device: %ld\n", PTR_ERR(connector->kdev));
return PTR_ERR(connector->kdev);
}
drm_sysfs_hotplug_event(dev);
return 0;
}
void drm_sysfs_connector_remove(struct drm_connector *connector)
{
if (!connector->kdev)
return;
DRM_DEBUG("removing \"%s\" from sysfs\n",
connector->name);
device_unregister(connector->kdev);
connector->kdev = NULL;
}
void drm_sysfs_hotplug_event(struct drm_device *dev)
{
char *event_string = "HOTPLUG=1";
char *envp[] = { event_string, NULL };
DRM_DEBUG("generating hotplug event\n");
kobject_uevent_env(&dev->primary->kdev->kobj, KOBJ_CHANGE, envp);
}
static void drm_sysfs_release(struct device *dev)
{
kfree(dev);
}
struct device *drm_sysfs_minor_alloc(struct drm_minor *minor)
{
const char *minor_str;
struct device *kdev;
int r;
if (minor->type == DRM_MINOR_CONTROL)
minor_str = "controlD%d";
else if (minor->type == DRM_MINOR_RENDER)
minor_str = "renderD%d";
else
minor_str = "card%d";
kdev = kzalloc(sizeof(*kdev), GFP_KERNEL);
if (!kdev)
return ERR_PTR(-ENOMEM);
device_initialize(kdev);
kdev->devt = MKDEV(DRM_MAJOR, minor->index);
kdev->class = drm_class;
kdev->type = &drm_sysfs_device_minor;
kdev->parent = minor->dev->dev;
kdev->release = drm_sysfs_release;
dev_set_drvdata(kdev, minor);
r = dev_set_name(kdev, minor_str, minor->index);
if (r < 0)
goto err_free;
return kdev;
err_free:
put_device(kdev);
return ERR_PTR(r);
}
int drm_class_device_register(struct device *dev)
{
if (!drm_class || IS_ERR(drm_class))
return -ENOENT;
dev->class = drm_class;
return device_register(dev);
}
void drm_class_device_unregister(struct device *dev)
{
return device_unregister(dev);
}
