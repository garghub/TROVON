void amdgpu_pm_acpi_event_handler(struct amdgpu_device *adev)
{
if (adev->pm.dpm_enabled) {
mutex_lock(&adev->pm.mutex);
if (power_supply_is_system_supplied() > 0)
adev->pm.dpm.ac_power = true;
else
adev->pm.dpm.ac_power = false;
if (adev->pm.funcs->enable_bapm)
amdgpu_dpm_enable_bapm(adev, adev->pm.dpm.ac_power);
mutex_unlock(&adev->pm.mutex);
}
}
static ssize_t amdgpu_get_dpm_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct drm_device *ddev = dev_get_drvdata(dev);
struct amdgpu_device *adev = ddev->dev_private;
enum amdgpu_pm_state_type pm = adev->pm.dpm.user_state;
return snprintf(buf, PAGE_SIZE, "%s\n",
(pm == POWER_STATE_TYPE_BATTERY) ? "battery" :
(pm == POWER_STATE_TYPE_BALANCED) ? "balanced" : "performance");
}
static ssize_t amdgpu_set_dpm_state(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct drm_device *ddev = dev_get_drvdata(dev);
struct amdgpu_device *adev = ddev->dev_private;
mutex_lock(&adev->pm.mutex);
if (strncmp("battery", buf, strlen("battery")) == 0)
adev->pm.dpm.user_state = POWER_STATE_TYPE_BATTERY;
else if (strncmp("balanced", buf, strlen("balanced")) == 0)
adev->pm.dpm.user_state = POWER_STATE_TYPE_BALANCED;
else if (strncmp("performance", buf, strlen("performance")) == 0)
adev->pm.dpm.user_state = POWER_STATE_TYPE_PERFORMANCE;
else {
mutex_unlock(&adev->pm.mutex);
count = -EINVAL;
goto fail;
}
mutex_unlock(&adev->pm.mutex);
if (!(adev->flags & AMD_IS_PX) ||
(ddev->switch_power_state == DRM_SWITCH_POWER_ON))
amdgpu_pm_compute_clocks(adev);
fail:
return count;
}
static ssize_t amdgpu_get_dpm_forced_performance_level(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct drm_device *ddev = dev_get_drvdata(dev);
struct amdgpu_device *adev = ddev->dev_private;
enum amdgpu_dpm_forced_level level = adev->pm.dpm.forced_level;
return snprintf(buf, PAGE_SIZE, "%s\n",
(level == AMDGPU_DPM_FORCED_LEVEL_AUTO) ? "auto" :
(level == AMDGPU_DPM_FORCED_LEVEL_LOW) ? "low" : "high");
}
static ssize_t amdgpu_set_dpm_forced_performance_level(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct drm_device *ddev = dev_get_drvdata(dev);
struct amdgpu_device *adev = ddev->dev_private;
enum amdgpu_dpm_forced_level level;
int ret = 0;
mutex_lock(&adev->pm.mutex);
if (strncmp("low", buf, strlen("low")) == 0) {
level = AMDGPU_DPM_FORCED_LEVEL_LOW;
} else if (strncmp("high", buf, strlen("high")) == 0) {
level = AMDGPU_DPM_FORCED_LEVEL_HIGH;
} else if (strncmp("auto", buf, strlen("auto")) == 0) {
level = AMDGPU_DPM_FORCED_LEVEL_AUTO;
} else {
count = -EINVAL;
goto fail;
}
if (adev->pm.funcs->force_performance_level) {
if (adev->pm.dpm.thermal_active) {
count = -EINVAL;
goto fail;
}
ret = amdgpu_dpm_force_performance_level(adev, level);
if (ret)
count = -EINVAL;
}
fail:
mutex_unlock(&adev->pm.mutex);
return count;
}
static ssize_t amdgpu_hwmon_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct amdgpu_device *adev = dev_get_drvdata(dev);
int temp;
if (adev->pm.funcs->get_temperature)
temp = amdgpu_dpm_get_temperature(adev);
else
temp = 0;
return snprintf(buf, PAGE_SIZE, "%d\n", temp);
}
static ssize_t amdgpu_hwmon_show_temp_thresh(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct amdgpu_device *adev = dev_get_drvdata(dev);
int hyst = to_sensor_dev_attr(attr)->index;
int temp;
if (hyst)
temp = adev->pm.dpm.thermal.min_temp;
else
temp = adev->pm.dpm.thermal.max_temp;
return snprintf(buf, PAGE_SIZE, "%d\n", temp);
}
static ssize_t amdgpu_hwmon_get_pwm1_enable(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct amdgpu_device *adev = dev_get_drvdata(dev);
u32 pwm_mode = 0;
if (adev->pm.funcs->get_fan_control_mode)
pwm_mode = amdgpu_dpm_get_fan_control_mode(adev);
return sprintf(buf, "%i\n", pwm_mode == FDO_PWM_MODE_STATIC ? 1 : 2);
}
static ssize_t amdgpu_hwmon_set_pwm1_enable(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct amdgpu_device *adev = dev_get_drvdata(dev);
int err;
int value;
if(!adev->pm.funcs->set_fan_control_mode)
return -EINVAL;
err = kstrtoint(buf, 10, &value);
if (err)
return err;
switch (value) {
case 1:
amdgpu_dpm_set_fan_control_mode(adev, FDO_PWM_MODE_STATIC);
break;
default:
amdgpu_dpm_set_fan_control_mode(adev, 0);
break;
}
return count;
}
static ssize_t amdgpu_hwmon_get_pwm1_min(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%i\n", 0);
}
static ssize_t amdgpu_hwmon_get_pwm1_max(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%i\n", 255);
}
static ssize_t amdgpu_hwmon_set_pwm1(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct amdgpu_device *adev = dev_get_drvdata(dev);
int err;
u32 value;
err = kstrtou32(buf, 10, &value);
if (err)
return err;
value = (value * 100) / 255;
err = amdgpu_dpm_set_fan_speed_percent(adev, value);
if (err)
return err;
return count;
}
static ssize_t amdgpu_hwmon_get_pwm1(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct amdgpu_device *adev = dev_get_drvdata(dev);
int err;
u32 speed;
err = amdgpu_dpm_get_fan_speed_percent(adev, &speed);
if (err)
return err;
speed = (speed * 255) / 100;
return sprintf(buf, "%i\n", speed);
}
static umode_t hwmon_attributes_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct amdgpu_device *adev = dev_get_drvdata(dev);
umode_t effective_mode = attr->mode;
if (!adev->pm.dpm_enabled &&
(attr == &sensor_dev_attr_temp1_crit.dev_attr.attr ||
attr == &sensor_dev_attr_temp1_crit_hyst.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1_enable.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1_max.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1_min.dev_attr.attr))
return 0;
if (adev->pm.no_fan &&
(attr == &sensor_dev_attr_pwm1.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1_enable.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1_max.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1_min.dev_attr.attr))
return 0;
if ((!adev->pm.funcs->get_fan_speed_percent &&
attr == &sensor_dev_attr_pwm1.dev_attr.attr) ||
(!adev->pm.funcs->get_fan_control_mode &&
attr == &sensor_dev_attr_pwm1_enable.dev_attr.attr))
effective_mode &= ~S_IRUGO;
if ((!adev->pm.funcs->set_fan_speed_percent &&
attr == &sensor_dev_attr_pwm1.dev_attr.attr) ||
(!adev->pm.funcs->set_fan_control_mode &&
attr == &sensor_dev_attr_pwm1_enable.dev_attr.attr))
effective_mode &= ~S_IWUSR;
if ((!adev->pm.funcs->set_fan_speed_percent &&
!adev->pm.funcs->get_fan_speed_percent) &&
(attr == &sensor_dev_attr_pwm1_max.dev_attr.attr ||
attr == &sensor_dev_attr_pwm1_min.dev_attr.attr))
return 0;
return effective_mode;
}
void amdgpu_dpm_thermal_work_handler(struct work_struct *work)
{
struct amdgpu_device *adev =
container_of(work, struct amdgpu_device,
pm.dpm.thermal.work);
enum amdgpu_pm_state_type dpm_state = POWER_STATE_TYPE_INTERNAL_THERMAL;
if (!adev->pm.dpm_enabled)
return;
if (adev->pm.funcs->get_temperature) {
int temp = amdgpu_dpm_get_temperature(adev);
if (temp < adev->pm.dpm.thermal.min_temp)
dpm_state = adev->pm.dpm.user_state;
} else {
if (adev->pm.dpm.thermal.high_to_low)
dpm_state = adev->pm.dpm.user_state;
}
mutex_lock(&adev->pm.mutex);
if (dpm_state == POWER_STATE_TYPE_INTERNAL_THERMAL)
adev->pm.dpm.thermal_active = true;
else
adev->pm.dpm.thermal_active = false;
adev->pm.dpm.state = dpm_state;
mutex_unlock(&adev->pm.mutex);
amdgpu_pm_compute_clocks(adev);
}
static struct amdgpu_ps *amdgpu_dpm_pick_power_state(struct amdgpu_device *adev,
enum amdgpu_pm_state_type dpm_state)
{
int i;
struct amdgpu_ps *ps;
u32 ui_class;
bool single_display = (adev->pm.dpm.new_active_crtc_count < 2) ?
true : false;
if (single_display && adev->pm.funcs->vblank_too_short) {
if (amdgpu_dpm_vblank_too_short(adev))
single_display = false;
}
if (dpm_state == POWER_STATE_TYPE_PERFORMANCE)
dpm_state = POWER_STATE_TYPE_INTERNAL_3DPERF;
if (dpm_state == POWER_STATE_TYPE_BALANCED)
dpm_state = POWER_STATE_TYPE_PERFORMANCE;
restart_search:
for (i = 0; i < adev->pm.dpm.num_ps; i++) {
ps = &adev->pm.dpm.ps[i];
ui_class = ps->class & ATOM_PPLIB_CLASSIFICATION_UI_MASK;
switch (dpm_state) {
case POWER_STATE_TYPE_BATTERY:
if (ui_class == ATOM_PPLIB_CLASSIFICATION_UI_BATTERY) {
if (ps->caps & ATOM_PPLIB_SINGLE_DISPLAY_ONLY) {
if (single_display)
return ps;
} else
return ps;
}
break;
case POWER_STATE_TYPE_BALANCED:
if (ui_class == ATOM_PPLIB_CLASSIFICATION_UI_BALANCED) {
if (ps->caps & ATOM_PPLIB_SINGLE_DISPLAY_ONLY) {
if (single_display)
return ps;
} else
return ps;
}
break;
case POWER_STATE_TYPE_PERFORMANCE:
if (ui_class == ATOM_PPLIB_CLASSIFICATION_UI_PERFORMANCE) {
if (ps->caps & ATOM_PPLIB_SINGLE_DISPLAY_ONLY) {
if (single_display)
return ps;
} else
return ps;
}
break;
case POWER_STATE_TYPE_INTERNAL_UVD:
if (adev->pm.dpm.uvd_ps)
return adev->pm.dpm.uvd_ps;
else
break;
case POWER_STATE_TYPE_INTERNAL_UVD_SD:
if (ps->class & ATOM_PPLIB_CLASSIFICATION_SDSTATE)
return ps;
break;
case POWER_STATE_TYPE_INTERNAL_UVD_HD:
if (ps->class & ATOM_PPLIB_CLASSIFICATION_HDSTATE)
return ps;
break;
case POWER_STATE_TYPE_INTERNAL_UVD_HD2:
if (ps->class & ATOM_PPLIB_CLASSIFICATION_HD2STATE)
return ps;
break;
case POWER_STATE_TYPE_INTERNAL_UVD_MVC:
if (ps->class2 & ATOM_PPLIB_CLASSIFICATION2_MVC)
return ps;
break;
case POWER_STATE_TYPE_INTERNAL_BOOT:
return adev->pm.dpm.boot_ps;
case POWER_STATE_TYPE_INTERNAL_THERMAL:
if (ps->class & ATOM_PPLIB_CLASSIFICATION_THERMAL)
return ps;
break;
case POWER_STATE_TYPE_INTERNAL_ACPI:
if (ps->class & ATOM_PPLIB_CLASSIFICATION_ACPI)
return ps;
break;
case POWER_STATE_TYPE_INTERNAL_ULV:
if (ps->class2 & ATOM_PPLIB_CLASSIFICATION2_ULV)
return ps;
break;
case POWER_STATE_TYPE_INTERNAL_3DPERF:
if (ps->class & ATOM_PPLIB_CLASSIFICATION_3DPERFORMANCE)
return ps;
break;
default:
break;
}
}
switch (dpm_state) {
case POWER_STATE_TYPE_INTERNAL_UVD_SD:
dpm_state = POWER_STATE_TYPE_INTERNAL_UVD_HD;
goto restart_search;
case POWER_STATE_TYPE_INTERNAL_UVD_HD:
case POWER_STATE_TYPE_INTERNAL_UVD_HD2:
case POWER_STATE_TYPE_INTERNAL_UVD_MVC:
if (adev->pm.dpm.uvd_ps) {
return adev->pm.dpm.uvd_ps;
} else {
dpm_state = POWER_STATE_TYPE_PERFORMANCE;
goto restart_search;
}
case POWER_STATE_TYPE_INTERNAL_THERMAL:
dpm_state = POWER_STATE_TYPE_INTERNAL_ACPI;
goto restart_search;
case POWER_STATE_TYPE_INTERNAL_ACPI:
dpm_state = POWER_STATE_TYPE_BATTERY;
goto restart_search;
case POWER_STATE_TYPE_BATTERY:
case POWER_STATE_TYPE_BALANCED:
case POWER_STATE_TYPE_INTERNAL_3DPERF:
dpm_state = POWER_STATE_TYPE_PERFORMANCE;
goto restart_search;
default:
break;
}
return NULL;
}
static void amdgpu_dpm_change_power_state_locked(struct amdgpu_device *adev)
{
int i;
struct amdgpu_ps *ps;
enum amdgpu_pm_state_type dpm_state;
int ret;
if (!adev->pm.dpm_enabled)
return;
if (adev->pm.dpm.user_state != adev->pm.dpm.state) {
if ((!adev->pm.dpm.thermal_active) &&
(!adev->pm.dpm.uvd_active))
adev->pm.dpm.state = adev->pm.dpm.user_state;
}
dpm_state = adev->pm.dpm.state;
ps = amdgpu_dpm_pick_power_state(adev, dpm_state);
if (ps)
adev->pm.dpm.requested_ps = ps;
else
return;
if (adev->pm.dpm.current_ps == adev->pm.dpm.requested_ps) {
if (ps->vce_active != adev->pm.dpm.vce_active)
goto force;
if (adev->flags & AMD_IS_APU) {
if (adev->pm.dpm.new_active_crtcs != adev->pm.dpm.current_active_crtcs) {
amdgpu_display_bandwidth_update(adev);
amdgpu_dpm_display_configuration_changed(adev);
adev->pm.dpm.current_active_crtcs = adev->pm.dpm.new_active_crtcs;
adev->pm.dpm.current_active_crtc_count = adev->pm.dpm.new_active_crtc_count;
}
return;
} else {
if (adev->pm.dpm.new_active_crtcs ==
adev->pm.dpm.current_active_crtcs) {
return;
} else if ((adev->pm.dpm.current_active_crtc_count > 1) &&
(adev->pm.dpm.new_active_crtc_count > 1)) {
amdgpu_display_bandwidth_update(adev);
amdgpu_dpm_display_configuration_changed(adev);
adev->pm.dpm.current_active_crtcs = adev->pm.dpm.new_active_crtcs;
adev->pm.dpm.current_active_crtc_count = adev->pm.dpm.new_active_crtc_count;
return;
}
}
}
force:
if (amdgpu_dpm == 1) {
printk("switching from power state:\n");
amdgpu_dpm_print_power_state(adev, adev->pm.dpm.current_ps);
printk("switching to power state:\n");
amdgpu_dpm_print_power_state(adev, adev->pm.dpm.requested_ps);
}
mutex_lock(&adev->ring_lock);
ps->vce_active = adev->pm.dpm.vce_active;
ret = amdgpu_dpm_pre_set_power_state(adev);
if (ret)
goto done;
amdgpu_display_bandwidth_update(adev);
amdgpu_dpm_display_configuration_changed(adev);
adev->pm.dpm.current_active_crtcs = adev->pm.dpm.new_active_crtcs;
adev->pm.dpm.current_active_crtc_count = adev->pm.dpm.new_active_crtc_count;
for (i = 0; i < AMDGPU_MAX_RINGS; i++) {
struct amdgpu_ring *ring = adev->rings[i];
if (ring && ring->ready)
amdgpu_fence_wait_empty(ring);
}
amdgpu_dpm_set_power_state(adev);
adev->pm.dpm.current_ps = adev->pm.dpm.requested_ps;
amdgpu_dpm_post_set_power_state(adev);
if (adev->pm.funcs->force_performance_level) {
if (adev->pm.dpm.thermal_active) {
enum amdgpu_dpm_forced_level level = adev->pm.dpm.forced_level;
amdgpu_dpm_force_performance_level(adev, AMDGPU_DPM_FORCED_LEVEL_LOW);
adev->pm.dpm.forced_level = level;
} else {
amdgpu_dpm_force_performance_level(adev, adev->pm.dpm.forced_level);
}
}
done:
mutex_unlock(&adev->ring_lock);
}
void amdgpu_dpm_enable_uvd(struct amdgpu_device *adev, bool enable)
{
if (adev->pm.funcs->powergate_uvd) {
mutex_lock(&adev->pm.mutex);
amdgpu_dpm_powergate_uvd(adev, !enable);
mutex_unlock(&adev->pm.mutex);
} else {
if (enable) {
mutex_lock(&adev->pm.mutex);
adev->pm.dpm.uvd_active = true;
adev->pm.dpm.state = POWER_STATE_TYPE_INTERNAL_UVD;
mutex_unlock(&adev->pm.mutex);
} else {
mutex_lock(&adev->pm.mutex);
adev->pm.dpm.uvd_active = false;
mutex_unlock(&adev->pm.mutex);
}
amdgpu_pm_compute_clocks(adev);
}
}
void amdgpu_dpm_enable_vce(struct amdgpu_device *adev, bool enable)
{
if (adev->pm.funcs->powergate_vce) {
mutex_lock(&adev->pm.mutex);
amdgpu_dpm_powergate_vce(adev, !enable);
mutex_unlock(&adev->pm.mutex);
} else {
if (enable) {
mutex_lock(&adev->pm.mutex);
adev->pm.dpm.vce_active = true;
adev->pm.dpm.vce_level = AMDGPU_VCE_LEVEL_AC_ALL;
mutex_unlock(&adev->pm.mutex);
} else {
mutex_lock(&adev->pm.mutex);
adev->pm.dpm.vce_active = false;
mutex_unlock(&adev->pm.mutex);
}
amdgpu_pm_compute_clocks(adev);
}
}
void amdgpu_pm_print_power_states(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < adev->pm.dpm.num_ps; i++) {
printk("== power state %d ==\n", i);
amdgpu_dpm_print_power_state(adev, &adev->pm.dpm.ps[i]);
}
}
int amdgpu_pm_sysfs_init(struct amdgpu_device *adev)
{
int ret;
if (adev->pm.sysfs_initialized)
return 0;
if (adev->pm.funcs->get_temperature == NULL)
return 0;
adev->pm.int_hwmon_dev = hwmon_device_register_with_groups(adev->dev,
DRIVER_NAME, adev,
hwmon_groups);
if (IS_ERR(adev->pm.int_hwmon_dev)) {
ret = PTR_ERR(adev->pm.int_hwmon_dev);
dev_err(adev->dev,
"Unable to register hwmon device: %d\n", ret);
return ret;
}
ret = device_create_file(adev->dev, &dev_attr_power_dpm_state);
if (ret) {
DRM_ERROR("failed to create device file for dpm state\n");
return ret;
}
ret = device_create_file(adev->dev, &dev_attr_power_dpm_force_performance_level);
if (ret) {
DRM_ERROR("failed to create device file for dpm state\n");
return ret;
}
ret = amdgpu_debugfs_pm_init(adev);
if (ret) {
DRM_ERROR("Failed to register debugfs file for dpm!\n");
return ret;
}
adev->pm.sysfs_initialized = true;
return 0;
}
void amdgpu_pm_sysfs_fini(struct amdgpu_device *adev)
{
if (adev->pm.int_hwmon_dev)
hwmon_device_unregister(adev->pm.int_hwmon_dev);
device_remove_file(adev->dev, &dev_attr_power_dpm_state);
device_remove_file(adev->dev, &dev_attr_power_dpm_force_performance_level);
}
void amdgpu_pm_compute_clocks(struct amdgpu_device *adev)
{
struct drm_device *ddev = adev->ddev;
struct drm_crtc *crtc;
struct amdgpu_crtc *amdgpu_crtc;
if (!adev->pm.dpm_enabled)
return;
mutex_lock(&adev->pm.mutex);
adev->pm.dpm.new_active_crtcs = 0;
adev->pm.dpm.new_active_crtc_count = 0;
if (adev->mode_info.num_crtc && adev->mode_info.mode_config_initialized) {
list_for_each_entry(crtc,
&ddev->mode_config.crtc_list, head) {
amdgpu_crtc = to_amdgpu_crtc(crtc);
if (crtc->enabled) {
adev->pm.dpm.new_active_crtcs |= (1 << amdgpu_crtc->crtc_id);
adev->pm.dpm.new_active_crtc_count++;
}
}
}
if (power_supply_is_system_supplied() > 0)
adev->pm.dpm.ac_power = true;
else
adev->pm.dpm.ac_power = false;
amdgpu_dpm_change_power_state_locked(adev);
mutex_unlock(&adev->pm.mutex);
}
static int amdgpu_debugfs_pm_info(struct seq_file *m, void *data)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct amdgpu_device *adev = dev->dev_private;
if (adev->pm.dpm_enabled) {
mutex_lock(&adev->pm.mutex);
if (adev->pm.funcs->debugfs_print_current_performance_level)
amdgpu_dpm_debugfs_print_current_performance_level(adev, m);
else
seq_printf(m, "Debugfs support not implemented for this asic\n");
mutex_unlock(&adev->pm.mutex);
}
return 0;
}
static int amdgpu_debugfs_pm_init(struct amdgpu_device *adev)
{
#if defined(CONFIG_DEBUG_FS)
return amdgpu_debugfs_add_files(adev, amdgpu_pm_info_list, ARRAY_SIZE(amdgpu_pm_info_list));
#else
return 0;
#endif
}
