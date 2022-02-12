static int __drm_class_suspend(struct device *dev, pm_message_t state)
{
if (dev->type == &drm_sysfs_device_minor) {
struct drm_minor *drm_minor = to_drm_minor(dev);
struct drm_device *drm_dev = drm_minor->dev;
if (drm_minor->type == DRM_MINOR_LEGACY &&
!drm_core_check_feature(drm_dev, DRIVER_MODESET) &&
drm_dev->driver->suspend)
return drm_dev->driver->suspend(drm_dev, state);
}
return 0;
}
static int drm_class_suspend(struct device *dev)
{
return __drm_class_suspend(dev, PMSG_SUSPEND);
}
static int drm_class_freeze(struct device *dev)
{
return __drm_class_suspend(dev, PMSG_FREEZE);
}
static int drm_class_resume(struct device *dev)
{
if (dev->type == &drm_sysfs_device_minor) {
struct drm_minor *drm_minor = to_drm_minor(dev);
struct drm_device *drm_dev = drm_minor->dev;
if (drm_minor->type == DRM_MINOR_LEGACY &&
!drm_core_check_feature(drm_dev, DRIVER_MODESET) &&
drm_dev->driver->resume)
return drm_dev->driver->resume(drm_dev);
}
return 0;
}
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
drm_class->pm = &drm_class_dev_pm_ops;
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
enum drm_connector_status old_status;
int ret;
ret = mutex_lock_interruptible(&dev->mode_config.mutex);
if (ret)
return ret;
old_status = connector->status;
if (sysfs_streq(buf, "detect")) {
connector->force = 0;
connector->status = connector->funcs->detect(connector, true);
} else if (sysfs_streq(buf, "on")) {
connector->force = DRM_FORCE_ON;
} else if (sysfs_streq(buf, "on-digital")) {
connector->force = DRM_FORCE_ON_DIGITAL;
} else if (sysfs_streq(buf, "off")) {
connector->force = DRM_FORCE_OFF;
} else
ret = -EINVAL;
if (ret == 0 && connector->force) {
if (connector->force == DRM_FORCE_ON ||
connector->force == DRM_FORCE_ON_DIGITAL)
connector->status = connector_status_connected;
else
connector->status = connector_status_disconnected;
if (connector->funcs->force)
connector->funcs->force(connector);
}
if (old_status != connector->status) {
DRM_DEBUG_KMS("[CONNECTOR:%d:%s] status updated from %d to %d\n",
connector->base.id,
connector->name,
old_status, connector->status);
dev->mode_config.delayed_event = true;
if (dev->mode_config.poll_enabled)
schedule_delayed_work(&dev->mode_config.output_poll_work,
0);
}
mutex_unlock(&dev->mode_config.mutex);
return ret ? ret : count;
}
static ssize_t status_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
return snprintf(buf, PAGE_SIZE, "%s\n",
drm_get_connector_status_name(connector->status));
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
return snprintf(buf, PAGE_SIZE, "%s\n", connector->encoder ? "enabled" :
"disabled");
}
static ssize_t edid_show(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf, loff_t off,
size_t count)
{
struct device *connector_dev = container_of(kobj, struct device, kobj);
struct drm_connector *connector = to_drm_connector(connector_dev);
unsigned char *edid;
size_t size;
if (!connector->edid_blob_ptr)
return 0;
edid = connector->edid_blob_ptr->data;
size = connector->edid_blob_ptr->length;
if (!edid)
return 0;
if (off >= size)
return 0;
if (off + count > size)
count = size - off;
memcpy(buf, edid + off, count);
return count;
}
static ssize_t modes_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
struct drm_display_mode *mode;
int written = 0;
list_for_each_entry(mode, &connector->modes, head) {
written += snprintf(buf + written, PAGE_SIZE - written, "%s\n",
mode->name);
}
return written;
}
static ssize_t tv_subconnector_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
struct drm_device *dev = connector->dev;
struct drm_property *prop;
uint64_t subconnector;
int ret;
prop = dev->mode_config.tv_subconnector_property;
if (!prop) {
DRM_ERROR("Unable to find subconnector property\n");
return 0;
}
ret = drm_object_property_get_value(&connector->base, prop, &subconnector);
if (ret)
return 0;
return snprintf(buf, PAGE_SIZE, "%s",
drm_get_tv_subconnector_name((int)subconnector));
}
static ssize_t tv_select_subconnector_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
struct drm_device *dev = connector->dev;
struct drm_property *prop;
uint64_t subconnector;
int ret;
prop = dev->mode_config.tv_select_subconnector_property;
if (!prop) {
DRM_ERROR("Unable to find select subconnector property\n");
return 0;
}
ret = drm_object_property_get_value(&connector->base, prop, &subconnector);
if (ret)
return 0;
return snprintf(buf, PAGE_SIZE, "%s",
drm_get_tv_select_name((int)subconnector));
}
static ssize_t dvii_subconnector_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
struct drm_device *dev = connector->dev;
struct drm_property *prop;
uint64_t subconnector;
int ret;
prop = dev->mode_config.dvi_i_subconnector_property;
if (!prop) {
DRM_ERROR("Unable to find subconnector property\n");
return 0;
}
ret = drm_object_property_get_value(&connector->base, prop, &subconnector);
if (ret)
return 0;
return snprintf(buf, PAGE_SIZE, "%s",
drm_get_dvi_i_subconnector_name((int)subconnector));
}
static ssize_t dvii_select_subconnector_show(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct drm_connector *connector = to_drm_connector(device);
struct drm_device *dev = connector->dev;
struct drm_property *prop;
uint64_t subconnector;
int ret;
prop = dev->mode_config.dvi_i_select_subconnector_property;
if (!prop) {
DRM_ERROR("Unable to find select subconnector property\n");
return 0;
}
ret = drm_object_property_get_value(&connector->base, prop, &subconnector);
if (ret)
return 0;
return snprintf(buf, PAGE_SIZE, "%s",
drm_get_dvi_i_select_name((int)subconnector));
}
static int kobj_connector_type(struct kobject *kobj)
{
struct device *dev = kobj_to_dev(kobj);
struct drm_connector *connector = to_drm_connector(dev);
return connector->connector_type;
}
static umode_t connector_is_dvii(struct kobject *kobj,
struct attribute *attr, int idx)
{
return kobj_connector_type(kobj) == DRM_MODE_CONNECTOR_DVII ?
attr->mode : 0;
}
static umode_t connector_is_tv(struct kobject *kobj,
struct attribute *attr, int idx)
{
switch (kobj_connector_type(kobj)) {
case DRM_MODE_CONNECTOR_Composite:
case DRM_MODE_CONNECTOR_SVIDEO:
case DRM_MODE_CONNECTOR_Component:
case DRM_MODE_CONNECTOR_TV:
return attr->mode;
}
return 0;
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
