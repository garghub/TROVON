static enum led_brightness __intensity_to_led_brightness(
struct v4l2_ctrl *ctrl, s32 intensity)
{
intensity -= ctrl->minimum;
intensity /= (u32) ctrl->step;
if (ctrl->minimum)
++intensity;
return intensity;
}
static s32 __led_brightness_to_intensity(struct v4l2_ctrl *ctrl,
enum led_brightness brightness)
{
if (ctrl->id != V4L2_CID_FLASH_INDICATOR_INTENSITY)
--brightness;
return (brightness * ctrl->step) + ctrl->minimum;
}
static void v4l2_flash_set_led_brightness(struct v4l2_flash *v4l2_flash,
struct v4l2_ctrl *ctrl)
{
struct v4l2_ctrl **ctrls = v4l2_flash->ctrls;
enum led_brightness brightness;
if (has_flash_op(v4l2_flash, intensity_to_led_brightness))
brightness = call_flash_op(v4l2_flash,
intensity_to_led_brightness,
ctrl->val);
else
brightness = __intensity_to_led_brightness(ctrl, ctrl->val);
if (has_flash_op(v4l2_flash, led_brightness_to_intensity))
ctrl->val = call_flash_op(v4l2_flash,
led_brightness_to_intensity,
brightness);
if (ctrl == ctrls[TORCH_INTENSITY]) {
if (ctrls[LED_MODE]->val != V4L2_FLASH_LED_MODE_TORCH)
return;
led_set_brightness_sync(&v4l2_flash->fled_cdev->led_cdev,
brightness);
} else {
led_set_brightness_sync(&v4l2_flash->iled_cdev->led_cdev,
brightness);
}
}
static int v4l2_flash_update_led_brightness(struct v4l2_flash *v4l2_flash,
struct v4l2_ctrl *ctrl)
{
struct v4l2_ctrl **ctrls = v4l2_flash->ctrls;
struct led_classdev *led_cdev;
int ret;
if (ctrl == ctrls[TORCH_INTENSITY]) {
if (ctrls[LED_MODE]->val != V4L2_FLASH_LED_MODE_TORCH)
return 0;
led_cdev = &v4l2_flash->fled_cdev->led_cdev;
} else {
led_cdev = &v4l2_flash->iled_cdev->led_cdev;
}
ret = led_update_brightness(led_cdev);
if (ret < 0)
return ret;
if (has_flash_op(v4l2_flash, led_brightness_to_intensity))
ctrl->val = call_flash_op(v4l2_flash,
led_brightness_to_intensity,
led_cdev->brightness);
else
ctrl->val = __led_brightness_to_intensity(ctrl,
led_cdev->brightness);
return 0;
}
static int v4l2_flash_g_volatile_ctrl(struct v4l2_ctrl *c)
{
struct v4l2_flash *v4l2_flash = v4l2_ctrl_to_v4l2_flash(c);
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
bool is_strobing;
int ret;
switch (c->id) {
case V4L2_CID_FLASH_TORCH_INTENSITY:
case V4L2_CID_FLASH_INDICATOR_INTENSITY:
return v4l2_flash_update_led_brightness(v4l2_flash, c);
case V4L2_CID_FLASH_INTENSITY:
ret = led_update_flash_brightness(fled_cdev);
if (ret < 0)
return ret;
c->val = fled_cdev->brightness.val;
return 0;
case V4L2_CID_FLASH_STROBE_STATUS:
ret = led_get_flash_strobe(fled_cdev, &is_strobing);
if (ret < 0)
return ret;
c->val = is_strobing;
return 0;
case V4L2_CID_FLASH_FAULT:
return led_get_flash_fault(fled_cdev, &c->val);
default:
return -EINVAL;
}
}
static bool __software_strobe_mode_inactive(struct v4l2_ctrl **ctrls)
{
return ((ctrls[LED_MODE]->val != V4L2_FLASH_LED_MODE_FLASH) ||
(ctrls[STROBE_SOURCE] && (ctrls[STROBE_SOURCE]->val !=
V4L2_FLASH_STROBE_SOURCE_SOFTWARE)));
}
static int v4l2_flash_s_ctrl(struct v4l2_ctrl *c)
{
struct v4l2_flash *v4l2_flash = v4l2_ctrl_to_v4l2_flash(c);
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct v4l2_ctrl **ctrls = v4l2_flash->ctrls;
bool external_strobe;
int ret = 0;
switch (c->id) {
case V4L2_CID_FLASH_LED_MODE:
switch (c->val) {
case V4L2_FLASH_LED_MODE_NONE:
led_set_brightness_sync(led_cdev, LED_OFF);
return led_set_flash_strobe(fled_cdev, false);
case V4L2_FLASH_LED_MODE_FLASH:
led_set_brightness_sync(led_cdev, LED_OFF);
if (ctrls[STROBE_SOURCE]) {
external_strobe = (ctrls[STROBE_SOURCE]->val ==
V4L2_FLASH_STROBE_SOURCE_EXTERNAL);
ret = call_flash_op(v4l2_flash,
external_strobe_set,
external_strobe);
}
return ret;
case V4L2_FLASH_LED_MODE_TORCH:
if (ctrls[STROBE_SOURCE]) {
ret = call_flash_op(v4l2_flash,
external_strobe_set,
false);
if (ret < 0)
return ret;
}
ret = led_set_flash_strobe(fled_cdev, false);
if (ret < 0)
return ret;
v4l2_flash_set_led_brightness(v4l2_flash,
ctrls[TORCH_INTENSITY]);
return 0;
}
break;
case V4L2_CID_FLASH_STROBE_SOURCE:
external_strobe = (c->val == V4L2_FLASH_STROBE_SOURCE_EXTERNAL);
if (ctrls[LED_MODE]->val != V4L2_FLASH_LED_MODE_FLASH)
return 0;
return call_flash_op(v4l2_flash, external_strobe_set,
external_strobe);
case V4L2_CID_FLASH_STROBE:
if (__software_strobe_mode_inactive(ctrls))
return -EBUSY;
return led_set_flash_strobe(fled_cdev, true);
case V4L2_CID_FLASH_STROBE_STOP:
if (__software_strobe_mode_inactive(ctrls))
return -EBUSY;
return led_set_flash_strobe(fled_cdev, false);
case V4L2_CID_FLASH_TIMEOUT:
return led_set_flash_timeout(fled_cdev, c->val);
case V4L2_CID_FLASH_INTENSITY:
return led_set_flash_brightness(fled_cdev, c->val);
case V4L2_CID_FLASH_TORCH_INTENSITY:
case V4L2_CID_FLASH_INDICATOR_INTENSITY:
v4l2_flash_set_led_brightness(v4l2_flash, c);
return 0;
}
return -EINVAL;
}
static void __lfs_to_v4l2_ctrl_config(struct led_flash_setting *s,
struct v4l2_ctrl_config *c)
{
c->min = s->min;
c->max = s->max;
c->step = s->step;
c->def = s->val;
}
static void __fill_ctrl_init_data(struct v4l2_flash *v4l2_flash,
struct v4l2_flash_config *flash_cfg,
struct v4l2_flash_ctrl_data *ctrl_init_data)
{
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
const struct led_flash_ops *fled_cdev_ops = fled_cdev->ops;
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct v4l2_ctrl_config *ctrl_cfg;
u32 mask;
if (flash_cfg->flash_faults) {
ctrl_init_data[FLASH_FAULT].cid = V4L2_CID_FLASH_FAULT;
ctrl_cfg = &ctrl_init_data[FLASH_FAULT].config;
ctrl_cfg->id = V4L2_CID_FLASH_FAULT;
ctrl_cfg->max = flash_cfg->flash_faults;
ctrl_cfg->flags = V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_READ_ONLY;
}
mask = 1 << V4L2_FLASH_LED_MODE_NONE |
1 << V4L2_FLASH_LED_MODE_TORCH;
if (led_cdev->flags & LED_DEV_CAP_FLASH)
mask |= 1 << V4L2_FLASH_LED_MODE_FLASH;
ctrl_init_data[LED_MODE].cid = V4L2_CID_FLASH_LED_MODE;
ctrl_cfg = &ctrl_init_data[LED_MODE].config;
ctrl_cfg->id = V4L2_CID_FLASH_LED_MODE;
ctrl_cfg->max = V4L2_FLASH_LED_MODE_TORCH;
ctrl_cfg->menu_skip_mask = ~mask;
ctrl_cfg->def = V4L2_FLASH_LED_MODE_NONE;
ctrl_cfg->flags = 0;
ctrl_init_data[TORCH_INTENSITY].cid = V4L2_CID_FLASH_TORCH_INTENSITY;
ctrl_cfg = &ctrl_init_data[TORCH_INTENSITY].config;
__lfs_to_v4l2_ctrl_config(&flash_cfg->torch_intensity, ctrl_cfg);
ctrl_cfg->id = V4L2_CID_FLASH_TORCH_INTENSITY;
ctrl_cfg->flags = V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_EXECUTE_ON_WRITE;
if (v4l2_flash->iled_cdev) {
ctrl_init_data[INDICATOR_INTENSITY].cid =
V4L2_CID_FLASH_INDICATOR_INTENSITY;
ctrl_cfg = &ctrl_init_data[INDICATOR_INTENSITY].config;
__lfs_to_v4l2_ctrl_config(&flash_cfg->indicator_intensity,
ctrl_cfg);
ctrl_cfg->id = V4L2_CID_FLASH_INDICATOR_INTENSITY;
ctrl_cfg->min = 0;
ctrl_cfg->flags = V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_EXECUTE_ON_WRITE;
}
if (!(led_cdev->flags & LED_DEV_CAP_FLASH))
return;
ctrl_init_data[FLASH_STROBE].cid = V4L2_CID_FLASH_STROBE;
ctrl_cfg = &ctrl_init_data[FLASH_STROBE].config;
ctrl_cfg->id = V4L2_CID_FLASH_STROBE;
ctrl_init_data[STROBE_STOP].cid = V4L2_CID_FLASH_STROBE_STOP;
ctrl_cfg = &ctrl_init_data[STROBE_STOP].config;
ctrl_cfg->id = V4L2_CID_FLASH_STROBE_STOP;
if (flash_cfg->has_external_strobe) {
mask = (1 << V4L2_FLASH_STROBE_SOURCE_SOFTWARE) |
(1 << V4L2_FLASH_STROBE_SOURCE_EXTERNAL);
ctrl_init_data[STROBE_SOURCE].cid =
V4L2_CID_FLASH_STROBE_SOURCE;
ctrl_cfg = &ctrl_init_data[STROBE_SOURCE].config;
ctrl_cfg->id = V4L2_CID_FLASH_STROBE_SOURCE;
ctrl_cfg->max = V4L2_FLASH_STROBE_SOURCE_EXTERNAL;
ctrl_cfg->menu_skip_mask = ~mask;
ctrl_cfg->def = V4L2_FLASH_STROBE_SOURCE_SOFTWARE;
}
if (fled_cdev_ops->strobe_get) {
ctrl_init_data[STROBE_STATUS].cid =
V4L2_CID_FLASH_STROBE_STATUS;
ctrl_cfg = &ctrl_init_data[STROBE_STATUS].config;
ctrl_cfg->id = V4L2_CID_FLASH_STROBE_STATUS;
ctrl_cfg->flags = V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_READ_ONLY;
}
if (fled_cdev_ops->timeout_set) {
ctrl_init_data[FLASH_TIMEOUT].cid = V4L2_CID_FLASH_TIMEOUT;
ctrl_cfg = &ctrl_init_data[FLASH_TIMEOUT].config;
__lfs_to_v4l2_ctrl_config(&fled_cdev->timeout, ctrl_cfg);
ctrl_cfg->id = V4L2_CID_FLASH_TIMEOUT;
}
if (fled_cdev_ops->flash_brightness_set) {
ctrl_init_data[FLASH_INTENSITY].cid = V4L2_CID_FLASH_INTENSITY;
ctrl_cfg = &ctrl_init_data[FLASH_INTENSITY].config;
__lfs_to_v4l2_ctrl_config(&fled_cdev->brightness, ctrl_cfg);
ctrl_cfg->id = V4L2_CID_FLASH_INTENSITY;
ctrl_cfg->flags = V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_EXECUTE_ON_WRITE;
}
}
static int v4l2_flash_init_controls(struct v4l2_flash *v4l2_flash,
struct v4l2_flash_config *flash_cfg)
{
struct v4l2_flash_ctrl_data *ctrl_init_data;
struct v4l2_ctrl *ctrl;
struct v4l2_ctrl_config *ctrl_cfg;
int i, ret, num_ctrls = 0;
v4l2_flash->ctrls = devm_kzalloc(v4l2_flash->sd.dev,
sizeof(*v4l2_flash->ctrls) *
(STROBE_SOURCE + 1), GFP_KERNEL);
if (!v4l2_flash->ctrls)
return -ENOMEM;
ctrl_init_data = kcalloc(NUM_FLASH_CTRLS, sizeof(*ctrl_init_data),
GFP_KERNEL);
if (!ctrl_init_data)
return -ENOMEM;
__fill_ctrl_init_data(v4l2_flash, flash_cfg, ctrl_init_data);
for (i = 0; i < NUM_FLASH_CTRLS; ++i)
if (ctrl_init_data[i].cid)
++num_ctrls;
v4l2_ctrl_handler_init(&v4l2_flash->hdl, num_ctrls);
for (i = 0; i < NUM_FLASH_CTRLS; ++i) {
ctrl_cfg = &ctrl_init_data[i].config;
if (!ctrl_init_data[i].cid)
continue;
if (ctrl_cfg->id == V4L2_CID_FLASH_LED_MODE ||
ctrl_cfg->id == V4L2_CID_FLASH_STROBE_SOURCE)
ctrl = v4l2_ctrl_new_std_menu(&v4l2_flash->hdl,
&v4l2_flash_ctrl_ops,
ctrl_cfg->id,
ctrl_cfg->max,
ctrl_cfg->menu_skip_mask,
ctrl_cfg->def);
else
ctrl = v4l2_ctrl_new_std(&v4l2_flash->hdl,
&v4l2_flash_ctrl_ops,
ctrl_cfg->id,
ctrl_cfg->min,
ctrl_cfg->max,
ctrl_cfg->step,
ctrl_cfg->def);
if (ctrl)
ctrl->flags |= ctrl_cfg->flags;
if (i <= STROBE_SOURCE)
v4l2_flash->ctrls[i] = ctrl;
}
kfree(ctrl_init_data);
if (v4l2_flash->hdl.error) {
ret = v4l2_flash->hdl.error;
goto error_free_handler;
}
v4l2_ctrl_handler_setup(&v4l2_flash->hdl);
v4l2_flash->sd.ctrl_handler = &v4l2_flash->hdl;
return 0;
error_free_handler:
v4l2_ctrl_handler_free(&v4l2_flash->hdl);
return ret;
}
static int __sync_device_with_v4l2_controls(struct v4l2_flash *v4l2_flash)
{
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
struct v4l2_ctrl **ctrls = v4l2_flash->ctrls;
int ret = 0;
v4l2_flash_set_led_brightness(v4l2_flash, ctrls[TORCH_INTENSITY]);
if (ctrls[INDICATOR_INTENSITY])
v4l2_flash_set_led_brightness(v4l2_flash,
ctrls[INDICATOR_INTENSITY]);
if (ctrls[FLASH_TIMEOUT]) {
ret = led_set_flash_timeout(fled_cdev,
ctrls[FLASH_TIMEOUT]->val);
if (ret < 0)
return ret;
}
if (ctrls[FLASH_INTENSITY]) {
ret = led_set_flash_brightness(fled_cdev,
ctrls[FLASH_INTENSITY]->val);
if (ret < 0)
return ret;
}
if (ctrls[STROBE_SOURCE] &&
ctrls[LED_MODE]->val != V4L2_FLASH_LED_MODE_TORCH)
ret = call_flash_op(v4l2_flash, external_strobe_set,
ctrls[STROBE_SOURCE]->val);
return ret;
}
static int v4l2_flash_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_flash *v4l2_flash = v4l2_subdev_to_v4l2_flash(sd);
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct led_classdev_flash *iled_cdev = v4l2_flash->iled_cdev;
struct led_classdev *led_cdev_ind = NULL;
int ret = 0;
if (!v4l2_fh_is_singular(&fh->vfh))
return 0;
mutex_lock(&led_cdev->led_access);
led_sysfs_disable(led_cdev);
led_trigger_remove(led_cdev);
mutex_unlock(&led_cdev->led_access);
if (iled_cdev) {
led_cdev_ind = &iled_cdev->led_cdev;
mutex_lock(&led_cdev_ind->led_access);
led_sysfs_disable(led_cdev_ind);
led_trigger_remove(led_cdev_ind);
mutex_unlock(&led_cdev_ind->led_access);
}
ret = __sync_device_with_v4l2_controls(v4l2_flash);
if (ret < 0)
goto out_sync_device;
return 0;
out_sync_device:
mutex_lock(&led_cdev->led_access);
led_sysfs_enable(led_cdev);
mutex_unlock(&led_cdev->led_access);
if (led_cdev_ind) {
mutex_lock(&led_cdev_ind->led_access);
led_sysfs_enable(led_cdev_ind);
mutex_unlock(&led_cdev_ind->led_access);
}
return ret;
}
static int v4l2_flash_close(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_flash *v4l2_flash = v4l2_subdev_to_v4l2_flash(sd);
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct led_classdev_flash *iled_cdev = v4l2_flash->iled_cdev;
int ret = 0;
if (!v4l2_fh_is_singular(&fh->vfh))
return 0;
mutex_lock(&led_cdev->led_access);
if (v4l2_flash->ctrls[STROBE_SOURCE])
ret = v4l2_ctrl_s_ctrl(v4l2_flash->ctrls[STROBE_SOURCE],
V4L2_FLASH_STROBE_SOURCE_SOFTWARE);
led_sysfs_enable(led_cdev);
mutex_unlock(&led_cdev->led_access);
if (iled_cdev) {
struct led_classdev *led_cdev_ind = &iled_cdev->led_cdev;
mutex_lock(&led_cdev_ind->led_access);
led_sysfs_enable(led_cdev_ind);
mutex_unlock(&led_cdev_ind->led_access);
}
return ret;
}
struct v4l2_flash *v4l2_flash_init(
struct device *dev, struct fwnode_handle *fwn,
struct led_classdev_flash *fled_cdev,
struct led_classdev_flash *iled_cdev,
const struct v4l2_flash_ops *ops,
struct v4l2_flash_config *config)
{
struct v4l2_flash *v4l2_flash;
struct led_classdev *led_cdev;
struct v4l2_subdev *sd;
int ret;
if (!fled_cdev || !ops || !config)
return ERR_PTR(-EINVAL);
led_cdev = &fled_cdev->led_cdev;
v4l2_flash = devm_kzalloc(led_cdev->dev, sizeof(*v4l2_flash),
GFP_KERNEL);
if (!v4l2_flash)
return ERR_PTR(-ENOMEM);
sd = &v4l2_flash->sd;
v4l2_flash->fled_cdev = fled_cdev;
v4l2_flash->iled_cdev = iled_cdev;
v4l2_flash->ops = ops;
sd->dev = dev;
sd->fwnode = fwn ? fwn : dev_fwnode(led_cdev->dev);
v4l2_subdev_init(sd, &v4l2_flash_subdev_ops);
sd->internal_ops = &v4l2_flash_subdev_internal_ops;
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
strlcpy(sd->name, config->dev_name, sizeof(sd->name));
ret = media_entity_pads_init(&sd->entity, 0, NULL);
if (ret < 0)
return ERR_PTR(ret);
sd->entity.function = MEDIA_ENT_F_FLASH;
ret = v4l2_flash_init_controls(v4l2_flash, config);
if (ret < 0)
goto err_init_controls;
fwnode_handle_get(sd->fwnode);
ret = v4l2_async_register_subdev(sd);
if (ret < 0)
goto err_async_register_sd;
return v4l2_flash;
err_async_register_sd:
fwnode_handle_put(sd->fwnode);
v4l2_ctrl_handler_free(sd->ctrl_handler);
err_init_controls:
media_entity_cleanup(&sd->entity);
return ERR_PTR(ret);
}
void v4l2_flash_release(struct v4l2_flash *v4l2_flash)
{
struct v4l2_subdev *sd;
if (IS_ERR_OR_NULL(v4l2_flash))
return;
sd = &v4l2_flash->sd;
v4l2_async_unregister_subdev(sd);
fwnode_handle_put(sd->fwnode);
v4l2_ctrl_handler_free(sd->ctrl_handler);
media_entity_cleanup(&sd->entity);
}
