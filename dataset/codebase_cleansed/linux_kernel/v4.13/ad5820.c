static int ad5820_write(struct ad5820_device *coil, u16 data)
{
struct i2c_client *client = v4l2_get_subdevdata(&coil->subdev);
struct i2c_msg msg;
__be16 be_data;
int r;
if (!client->adapter)
return -ENODEV;
be_data = cpu_to_be16(data);
msg.addr = client->addr;
msg.flags = 0;
msg.len = 2;
msg.buf = (u8 *)&be_data;
r = i2c_transfer(client->adapter, &msg, 1);
if (r < 0) {
dev_err(&client->dev, "write failed, error %d\n", r);
return r;
}
return 0;
}
static int ad5820_update_hw(struct ad5820_device *coil)
{
u16 status;
status = RAMP_US_TO_CODE(coil->focus_ramp_time);
status |= coil->focus_ramp_mode
? AD5820_RAMP_MODE_64_16 : AD5820_RAMP_MODE_LINEAR;
status |= coil->focus_absolute << AD5820_DAC_SHIFT;
if (coil->standby)
status |= AD5820_POWER_DOWN;
return ad5820_write(coil, status);
}
static int ad5820_power_off(struct ad5820_device *coil, bool standby)
{
int ret = 0, ret2;
if (standby) {
coil->standby = true;
ret = ad5820_update_hw(coil);
}
ret2 = regulator_disable(coil->vana);
if (ret)
return ret;
return ret2;
}
static int ad5820_power_on(struct ad5820_device *coil, bool restore)
{
int ret;
ret = regulator_enable(coil->vana);
if (ret < 0)
return ret;
if (restore) {
coil->standby = false;
ret = ad5820_update_hw(coil);
if (ret)
goto fail;
}
return 0;
fail:
coil->standby = true;
regulator_disable(coil->vana);
return ret;
}
static int ad5820_set_ctrl(struct v4l2_ctrl *ctrl)
{
struct ad5820_device *coil =
container_of(ctrl->handler, struct ad5820_device, ctrls);
switch (ctrl->id) {
case V4L2_CID_FOCUS_ABSOLUTE:
coil->focus_absolute = ctrl->val;
return ad5820_update_hw(coil);
}
return 0;
}
static int ad5820_init_controls(struct ad5820_device *coil)
{
v4l2_ctrl_handler_init(&coil->ctrls, 1);
v4l2_ctrl_new_std(&coil->ctrls, &ad5820_ctrl_ops,
V4L2_CID_FOCUS_ABSOLUTE, 0, 1023, 1, 0);
if (coil->ctrls.error)
return coil->ctrls.error;
coil->focus_absolute = 0;
coil->focus_ramp_time = 0;
coil->focus_ramp_mode = 0;
coil->subdev.ctrl_handler = &coil->ctrls;
return 0;
}
static int ad5820_registered(struct v4l2_subdev *subdev)
{
struct ad5820_device *coil = to_ad5820_device(subdev);
return ad5820_init_controls(coil);
}
static int
ad5820_set_power(struct v4l2_subdev *subdev, int on)
{
struct ad5820_device *coil = to_ad5820_device(subdev);
int ret = 0;
mutex_lock(&coil->power_lock);
if (coil->power_count == !on) {
ret = on ? ad5820_power_on(coil, true) :
ad5820_power_off(coil, true);
if (ret < 0)
goto done;
}
coil->power_count += on ? 1 : -1;
WARN_ON(coil->power_count < 0);
done:
mutex_unlock(&coil->power_lock);
return ret;
}
static int ad5820_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
return ad5820_set_power(sd, 1);
}
static int ad5820_close(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
return ad5820_set_power(sd, 0);
}
static int __maybe_unused ad5820_suspend(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct ad5820_device *coil = to_ad5820_device(subdev);
if (!coil->power_count)
return 0;
return ad5820_power_off(coil, false);
}
static int __maybe_unused ad5820_resume(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct ad5820_device *coil = to_ad5820_device(subdev);
if (!coil->power_count)
return 0;
return ad5820_power_on(coil, true);
}
static int ad5820_probe(struct i2c_client *client,
const struct i2c_device_id *devid)
{
struct ad5820_device *coil;
int ret;
coil = devm_kzalloc(&client->dev, sizeof(*coil), GFP_KERNEL);
if (!coil)
return -ENOMEM;
coil->vana = devm_regulator_get(&client->dev, "VANA");
if (IS_ERR(coil->vana)) {
ret = PTR_ERR(coil->vana);
if (ret != -EPROBE_DEFER)
dev_err(&client->dev, "could not get regulator for vana\n");
return ret;
}
mutex_init(&coil->power_lock);
v4l2_i2c_subdev_init(&coil->subdev, client, &ad5820_ops);
coil->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
coil->subdev.internal_ops = &ad5820_internal_ops;
strcpy(coil->subdev.name, "ad5820 focus");
ret = media_entity_pads_init(&coil->subdev.entity, 0, NULL);
if (ret < 0)
goto cleanup2;
ret = v4l2_async_register_subdev(&coil->subdev);
if (ret < 0)
goto cleanup;
return ret;
cleanup2:
mutex_destroy(&coil->power_lock);
cleanup:
media_entity_cleanup(&coil->subdev.entity);
return ret;
}
static int ad5820_remove(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct ad5820_device *coil = to_ad5820_device(subdev);
v4l2_async_unregister_subdev(&coil->subdev);
v4l2_ctrl_handler_free(&coil->ctrls);
media_entity_cleanup(&coil->subdev.entity);
mutex_destroy(&coil->power_lock);
return 0;
}
