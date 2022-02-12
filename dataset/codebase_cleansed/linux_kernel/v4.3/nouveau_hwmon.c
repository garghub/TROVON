static ssize_t
nouveau_hwmon_show_temp(struct device *d, struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
int temp = nvkm_therm_temp_get(therm);
if (temp < 0)
return temp;
return snprintf(buf, PAGE_SIZE, "%d\n", temp * 1000);
}
static ssize_t
nouveau_hwmon_show_temp1_auto_point1_pwm(struct device *d,
struct device_attribute *a, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", 100);
}
static ssize_t
nouveau_hwmon_temp1_auto_point1_temp(struct device *d,
struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_FAN_BOOST) * 1000);
}
static ssize_t
nouveau_hwmon_set_temp1_auto_point1_temp(struct device *d,
struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_FAN_BOOST,
value / 1000);
return count;
}
static ssize_t
nouveau_hwmon_temp1_auto_point1_temp_hyst(struct device *d,
struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_FAN_BOOST_HYST) * 1000);
}
static ssize_t
nouveau_hwmon_set_temp1_auto_point1_temp_hyst(struct device *d,
struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_FAN_BOOST_HYST,
value / 1000);
return count;
}
static ssize_t
nouveau_hwmon_max_temp(struct device *d, struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_DOWN_CLK) * 1000);
}
static ssize_t
nouveau_hwmon_set_max_temp(struct device *d, struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_DOWN_CLK, value / 1000);
return count;
}
static ssize_t
nouveau_hwmon_max_temp_hyst(struct device *d, struct device_attribute *a,
char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_DOWN_CLK_HYST) * 1000);
}
static ssize_t
nouveau_hwmon_set_max_temp_hyst(struct device *d, struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_DOWN_CLK_HYST,
value / 1000);
return count;
}
static ssize_t
nouveau_hwmon_critical_temp(struct device *d, struct device_attribute *a,
char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_CRITICAL) * 1000);
}
static ssize_t
nouveau_hwmon_set_critical_temp(struct device *d, struct device_attribute *a,
const char *buf,
size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_CRITICAL, value / 1000);
return count;
}
static ssize_t
nouveau_hwmon_critical_temp_hyst(struct device *d, struct device_attribute *a,
char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_CRITICAL_HYST) * 1000);
}
static ssize_t
nouveau_hwmon_set_critical_temp_hyst(struct device *d,
struct device_attribute *a,
const char *buf,
size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_CRITICAL_HYST,
value / 1000);
return count;
}
static ssize_t
nouveau_hwmon_emergency_temp(struct device *d, struct device_attribute *a,
char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_SHUTDOWN) * 1000);
}
static ssize_t
nouveau_hwmon_set_emergency_temp(struct device *d, struct device_attribute *a,
const char *buf,
size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_SHUTDOWN, value / 1000);
return count;
}
static ssize_t
nouveau_hwmon_emergency_temp_hyst(struct device *d, struct device_attribute *a,
char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n",
therm->attr_get(therm, NVKM_THERM_ATTR_THRS_SHUTDOWN_HYST) * 1000);
}
static ssize_t
nouveau_hwmon_set_emergency_temp_hyst(struct device *d,
struct device_attribute *a,
const char *buf,
size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return count;
therm->attr_set(therm, NVKM_THERM_ATTR_THRS_SHUTDOWN_HYST,
value / 1000);
return count;
}
static ssize_t nouveau_hwmon_show_name(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "nouveau\n");
}
static ssize_t nouveau_hwmon_show_update_rate(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "1000\n");
}
static ssize_t
nouveau_hwmon_show_fan1_input(struct device *d, struct device_attribute *attr,
char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
return snprintf(buf, PAGE_SIZE, "%d\n", nvkm_therm_fan_sense(therm));
}
static ssize_t
nouveau_hwmon_get_pwm1_enable(struct device *d,
struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
int ret;
ret = therm->attr_get(therm, NVKM_THERM_ATTR_FAN_MODE);
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", ret);
}
static ssize_t
nouveau_hwmon_set_pwm1_enable(struct device *d, struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
int ret;
ret = kstrtol(buf, 10, &value);
if (ret)
return ret;
ret = therm->attr_set(therm, NVKM_THERM_ATTR_FAN_MODE, value);
if (ret)
return ret;
else
return count;
}
static ssize_t
nouveau_hwmon_get_pwm1(struct device *d, struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
int ret;
ret = therm->fan_get(therm);
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", ret);
}
static ssize_t
nouveau_hwmon_set_pwm1(struct device *d, struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
int ret = -ENODEV;
long value;
if (kstrtol(buf, 10, &value) == -EINVAL)
return -EINVAL;
ret = therm->fan_set(therm, value);
if (ret)
return ret;
return count;
}
static ssize_t
nouveau_hwmon_get_pwm1_min(struct device *d,
struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
int ret;
ret = therm->attr_get(therm, NVKM_THERM_ATTR_FAN_MIN_DUTY);
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", ret);
}
static ssize_t
nouveau_hwmon_set_pwm1_min(struct device *d, struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
int ret;
if (kstrtol(buf, 10, &value) == -EINVAL)
return -EINVAL;
ret = therm->attr_set(therm, NVKM_THERM_ATTR_FAN_MIN_DUTY, value);
if (ret < 0)
return ret;
return count;
}
static ssize_t
nouveau_hwmon_get_pwm1_max(struct device *d,
struct device_attribute *a, char *buf)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
int ret;
ret = therm->attr_get(therm, NVKM_THERM_ATTR_FAN_MAX_DUTY);
if (ret < 0)
return ret;
return sprintf(buf, "%i\n", ret);
}
static ssize_t
nouveau_hwmon_set_pwm1_max(struct device *d, struct device_attribute *a,
const char *buf, size_t count)
{
struct drm_device *dev = dev_get_drvdata(d);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
long value;
int ret;
if (kstrtol(buf, 10, &value) == -EINVAL)
return -EINVAL;
ret = therm->attr_set(therm, NVKM_THERM_ATTR_FAN_MAX_DUTY, value);
if (ret < 0)
return ret;
return count;
}
int
nouveau_hwmon_init(struct drm_device *dev)
{
#if defined(CONFIG_HWMON) || (defined(MODULE) && defined(CONFIG_HWMON_MODULE))
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_therm *therm = nvxx_therm(&drm->device);
struct nouveau_hwmon *hwmon;
struct device *hwmon_dev;
int ret = 0;
hwmon = drm->hwmon = kzalloc(sizeof(*hwmon), GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
hwmon->dev = dev;
if (!therm || !therm->attr_get || !therm->attr_set)
return -ENODEV;
hwmon_dev = hwmon_device_register(&dev->pdev->dev);
if (IS_ERR(hwmon_dev)) {
ret = PTR_ERR(hwmon_dev);
NV_ERROR(drm, "Unable to register hwmon device: %d\n", ret);
return ret;
}
dev_set_drvdata(hwmon_dev, dev);
ret = sysfs_create_group(&hwmon_dev->kobj, &hwmon_default_attrgroup);
if (ret)
goto error;
if (nvkm_therm_temp_get(therm) >= 0) {
ret = sysfs_create_group(&hwmon_dev->kobj, &hwmon_temp_attrgroup);
if (ret)
goto error;
}
if (therm->fan_get && therm->fan_get(therm) >= 0) {
ret = sysfs_create_group(&hwmon_dev->kobj,
&hwmon_pwm_fan_attrgroup);
if (ret)
goto error;
}
if (nvkm_therm_fan_sense(therm) >= 0) {
ret = sysfs_create_group(&hwmon_dev->kobj,
&hwmon_fan_rpm_attrgroup);
if (ret)
goto error;
}
hwmon->hwmon = hwmon_dev;
return 0;
error:
NV_ERROR(drm, "Unable to create some hwmon sysfs files: %d\n", ret);
hwmon_device_unregister(hwmon_dev);
hwmon->hwmon = NULL;
return ret;
#else
return 0;
#endif
}
void
nouveau_hwmon_fini(struct drm_device *dev)
{
#if defined(CONFIG_HWMON) || (defined(MODULE) && defined(CONFIG_HWMON_MODULE))
struct nouveau_hwmon *hwmon = nouveau_hwmon(dev);
if (hwmon->hwmon) {
sysfs_remove_group(&hwmon->hwmon->kobj, &hwmon_default_attrgroup);
sysfs_remove_group(&hwmon->hwmon->kobj, &hwmon_temp_attrgroup);
sysfs_remove_group(&hwmon->hwmon->kobj, &hwmon_pwm_fan_attrgroup);
sysfs_remove_group(&hwmon->hwmon->kobj, &hwmon_fan_rpm_attrgroup);
hwmon_device_unregister(hwmon->hwmon);
}
nouveau_drm(dev)->hwmon = NULL;
kfree(hwmon);
#endif
}
