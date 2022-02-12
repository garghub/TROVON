static int as3645a_write(struct as3645a *flash, u8 addr, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(&flash->subdev);
int rval;
rval = i2c_smbus_write_byte_data(client, addr, val);
dev_dbg(&client->dev, "Write Addr:%02X Val:%02X %s\n", addr, val,
rval < 0 ? "fail" : "ok");
return rval;
}
static int as3645a_read(struct as3645a *flash, u8 addr)
{
struct i2c_client *client = v4l2_get_subdevdata(&flash->subdev);
int rval;
rval = i2c_smbus_read_byte_data(client, addr);
dev_dbg(&client->dev, "Read Addr:%02X Val:%02X %s\n", addr, rval,
rval < 0 ? "fail" : "ok");
return rval;
}
static int as3645a_set_config(struct as3645a *flash)
{
int ret;
u8 val;
val = (flash->flash_current << AS_CURRENT_FLASH_CURRENT_SHIFT)
| (flash->assist_current << AS_CURRENT_ASSIST_LIGHT_SHIFT)
| AS_CURRENT_LED_DET_ON;
ret = as3645a_write(flash, AS_CURRENT_SET_REG, val);
if (ret < 0)
return ret;
val = AS_TIMER_MS_TO_CODE(flash->timeout / 1000)
<< AS_INDICATOR_AND_TIMER_TIMEOUT_SHIFT;
val |= (flash->pdata->vref << AS_INDICATOR_AND_TIMER_VREF_SHIFT)
| ((flash->indicator_current ? flash->indicator_current - 1 : 0)
<< AS_INDICATOR_AND_TIMER_INDICATOR_SHIFT);
return as3645a_write(flash, AS_INDICATOR_AND_TIMER_REG, val);
}
static int
as3645a_set_control(struct as3645a *flash, enum as_mode mode, bool on)
{
u8 reg;
reg = (flash->pdata->peak << AS_CONTROL_COIL_PEAK_SHIFT)
| (on ? AS_CONTROL_OUT_ON : 0)
| mode;
if (flash->led_mode == V4L2_FLASH_LED_MODE_FLASH &&
flash->strobe_source == V4L2_FLASH_STROBE_SOURCE_EXTERNAL) {
reg |= AS_CONTROL_STROBE_TYPE_LEVEL
| AS_CONTROL_STROBE_ON;
}
return as3645a_write(flash, AS_CONTROL_REG, reg);
}
static int as3645a_set_output(struct as3645a *flash, bool strobe)
{
enum as_mode mode;
bool on;
switch (flash->led_mode) {
case V4L2_FLASH_LED_MODE_NONE:
on = flash->indicator_current != 0;
mode = AS_MODE_INDICATOR;
break;
case V4L2_FLASH_LED_MODE_TORCH:
on = true;
mode = AS_MODE_ASSIST;
break;
case V4L2_FLASH_LED_MODE_FLASH:
on = strobe;
mode = AS_MODE_FLASH;
break;
default:
BUG();
}
return as3645a_set_control(flash, mode, on);
}
static int as3645a_is_active(struct as3645a *flash)
{
int ret;
ret = as3645a_read(flash, AS_CONTROL_REG);
return ret < 0 ? ret : !!(ret & AS_CONTROL_OUT_ON);
}
static int as3645a_read_fault(struct as3645a *flash)
{
struct i2c_client *client = v4l2_get_subdevdata(&flash->subdev);
int rval;
rval = as3645a_read(flash, AS_FAULT_INFO_REG);
if (rval < 0)
return rval;
if (rval & AS_FAULT_INFO_INDUCTOR_PEAK_LIMIT)
dev_dbg(&client->dev, "Inductor Peak limit fault\n");
if (rval & AS_FAULT_INFO_INDICATOR_LED)
dev_dbg(&client->dev, "Indicator LED fault: "
"Short circuit or open loop\n");
dev_dbg(&client->dev, "%u connected LEDs\n",
rval & AS_FAULT_INFO_LED_AMOUNT ? 2 : 1);
if (rval & AS_FAULT_INFO_TIMEOUT)
dev_dbg(&client->dev, "Timeout fault\n");
if (rval & AS_FAULT_INFO_OVER_TEMPERATURE)
dev_dbg(&client->dev, "Over temperature fault\n");
if (rval & AS_FAULT_INFO_SHORT_CIRCUIT)
dev_dbg(&client->dev, "Short circuit fault\n");
if (rval & AS_FAULT_INFO_OVER_VOLTAGE)
dev_dbg(&client->dev, "Over voltage fault: "
"Indicates missing capacitor or open connection\n");
return rval;
}
static int as3645a_get_ctrl(struct v4l2_ctrl *ctrl)
{
struct as3645a *flash =
container_of(ctrl->handler, struct as3645a, ctrls);
struct i2c_client *client = v4l2_get_subdevdata(&flash->subdev);
int value;
switch (ctrl->id) {
case V4L2_CID_FLASH_FAULT:
value = as3645a_read_fault(flash);
if (value < 0)
return value;
ctrl->cur.val = 0;
if (value & AS_FAULT_INFO_SHORT_CIRCUIT)
ctrl->cur.val |= V4L2_FLASH_FAULT_SHORT_CIRCUIT;
if (value & AS_FAULT_INFO_OVER_TEMPERATURE)
ctrl->cur.val |= V4L2_FLASH_FAULT_OVER_TEMPERATURE;
if (value & AS_FAULT_INFO_TIMEOUT)
ctrl->cur.val |= V4L2_FLASH_FAULT_TIMEOUT;
if (value & AS_FAULT_INFO_OVER_VOLTAGE)
ctrl->cur.val |= V4L2_FLASH_FAULT_OVER_VOLTAGE;
if (value & AS_FAULT_INFO_INDUCTOR_PEAK_LIMIT)
ctrl->cur.val |= V4L2_FLASH_FAULT_OVER_CURRENT;
if (value & AS_FAULT_INFO_INDICATOR_LED)
ctrl->cur.val |= V4L2_FLASH_FAULT_INDICATOR;
break;
case V4L2_CID_FLASH_STROBE_STATUS:
if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH) {
ctrl->cur.val = 0;
break;
}
value = as3645a_is_active(flash);
if (value < 0)
return value;
ctrl->cur.val = value;
break;
}
dev_dbg(&client->dev, "G_CTRL %08x:%d\n", ctrl->id, ctrl->cur.val);
return 0;
}
static int as3645a_set_ctrl(struct v4l2_ctrl *ctrl)
{
struct as3645a *flash =
container_of(ctrl->handler, struct as3645a, ctrls);
struct i2c_client *client = v4l2_get_subdevdata(&flash->subdev);
int ret;
dev_dbg(&client->dev, "S_CTRL %08x:%d\n", ctrl->id, ctrl->val);
switch (ctrl->id) {
case V4L2_CID_FLASH_LED_MODE:
if (flash->indicator_current)
return -EBUSY;
ret = as3645a_set_config(flash);
if (ret < 0)
return ret;
flash->led_mode = ctrl->val;
return as3645a_set_output(flash, false);
case V4L2_CID_FLASH_STROBE_SOURCE:
flash->strobe_source = ctrl->val;
if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH)
break;
return as3645a_set_output(flash, false);
case V4L2_CID_FLASH_STROBE:
if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH)
return -EBUSY;
return as3645a_set_output(flash, true);
case V4L2_CID_FLASH_STROBE_STOP:
if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH)
return -EBUSY;
return as3645a_set_output(flash, false);
case V4L2_CID_FLASH_TIMEOUT:
flash->timeout = ctrl->val;
if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH)
break;
return as3645a_set_config(flash);
case V4L2_CID_FLASH_INTENSITY:
flash->flash_current = (ctrl->val - AS3645A_FLASH_INTENSITY_MIN)
/ AS3645A_FLASH_INTENSITY_STEP;
if (flash->led_mode != V4L2_FLASH_LED_MODE_FLASH)
break;
return as3645a_set_config(flash);
case V4L2_CID_FLASH_TORCH_INTENSITY:
flash->assist_current =
(ctrl->val - AS3645A_TORCH_INTENSITY_MIN)
/ AS3645A_TORCH_INTENSITY_STEP;
if (flash->led_mode != V4L2_FLASH_LED_MODE_TORCH)
break;
return as3645a_set_config(flash);
case V4L2_CID_FLASH_INDICATOR_INTENSITY:
if (flash->led_mode != V4L2_FLASH_LED_MODE_NONE)
return -EBUSY;
flash->indicator_current =
(ctrl->val - AS3645A_INDICATOR_INTENSITY_MIN)
/ AS3645A_INDICATOR_INTENSITY_STEP;
ret = as3645a_set_config(flash);
if (ret < 0)
return ret;
if ((ctrl->val == 0) == (ctrl->cur.val == 0))
break;
return as3645a_set_output(flash, false);
}
return 0;
}
static int as3645a_setup(struct as3645a *flash)
{
struct i2c_client *client = v4l2_get_subdevdata(&flash->subdev);
int ret;
ret = as3645a_read(flash, AS_FAULT_INFO_REG);
if (ret < 0)
return ret;
dev_dbg(&client->dev, "Fault info: %02x\n", ret);
ret = as3645a_set_config(flash);
if (ret < 0)
return ret;
ret = as3645a_set_output(flash, false);
if (ret < 0)
return ret;
ret = as3645a_read_fault(flash);
if (ret < 0)
return ret;
dev_dbg(&client->dev, "AS_INDICATOR_AND_TIMER_REG: %02x\n",
as3645a_read(flash, AS_INDICATOR_AND_TIMER_REG));
dev_dbg(&client->dev, "AS_CURRENT_SET_REG: %02x\n",
as3645a_read(flash, AS_CURRENT_SET_REG));
dev_dbg(&client->dev, "AS_CONTROL_REG: %02x\n",
as3645a_read(flash, AS_CONTROL_REG));
return ret & ~AS_FAULT_INFO_LED_AMOUNT ? -EIO : 0;
}
static int __as3645a_set_power(struct as3645a *flash, int on)
{
int ret;
if (!on)
as3645a_set_control(flash, AS_MODE_EXT_TORCH, false);
if (flash->pdata->set_power) {
ret = flash->pdata->set_power(&flash->subdev, on);
if (ret < 0)
return ret;
}
if (!on)
return 0;
ret = as3645a_setup(flash);
if (ret < 0) {
if (flash->pdata->set_power)
flash->pdata->set_power(&flash->subdev, 0);
}
return ret;
}
static int as3645a_set_power(struct v4l2_subdev *sd, int on)
{
struct as3645a *flash = to_as3645a(sd);
int ret = 0;
mutex_lock(&flash->power_lock);
if (flash->power_count == !on) {
ret = __as3645a_set_power(flash, !!on);
if (ret < 0)
goto done;
}
flash->power_count += on ? 1 : -1;
WARN_ON(flash->power_count < 0);
done:
mutex_unlock(&flash->power_lock);
return ret;
}
static int as3645a_registered(struct v4l2_subdev *sd)
{
struct as3645a *flash = to_as3645a(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int rval, man, model, rfu, version;
const char *vendor;
rval = as3645a_set_power(&flash->subdev, 1);
if (rval < 0)
return rval;
rval = as3645a_read(flash, AS_DESIGN_INFO_REG);
if (rval < 0)
goto power_off;
man = AS_DESIGN_INFO_FACTORY(rval);
model = AS_DESIGN_INFO_MODEL(rval);
rval = as3645a_read(flash, AS_VERSION_CONTROL_REG);
if (rval < 0)
goto power_off;
rfu = AS_VERSION_CONTROL_RFU(rval);
version = AS_VERSION_CONTROL_VERSION(rval);
if (model != 0x01 || rfu != 0x00) {
dev_err(&client->dev, "AS3645A not detected "
"(model %d rfu %d)\n", model, rfu);
rval = -ENODEV;
goto power_off;
}
switch (man) {
case 1:
vendor = "AMS, Austria Micro Systems";
break;
case 2:
vendor = "ADI, Analog Devices Inc.";
break;
case 3:
vendor = "NSC, National Semiconductor";
break;
case 4:
vendor = "NXP";
break;
case 5:
vendor = "TI, Texas Instrument";
break;
default:
vendor = "Unknown";
}
dev_info(&client->dev, "Chip vendor: %s (%d) Version: %d\n", vendor,
man, version);
rval = as3645a_write(flash, AS_PASSWORD_REG, AS_PASSWORD_UNLOCK_VALUE);
if (rval < 0)
goto power_off;
rval = as3645a_write(flash, AS_BOOST_REG, AS_BOOST_CURRENT_DISABLE);
if (rval < 0)
goto power_off;
rval = as3645a_setup(flash);
power_off:
as3645a_set_power(&flash->subdev, 0);
return rval;
}
static int as3645a_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
return as3645a_set_power(sd, 1);
}
static int as3645a_close(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
return as3645a_set_power(sd, 0);
}
static int as3645a_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct as3645a *flash = to_as3645a(subdev);
int rval;
if (flash->power_count == 0)
return 0;
rval = __as3645a_set_power(flash, 0);
dev_dbg(&client->dev, "Suspend %s\n", rval < 0 ? "failed" : "ok");
return rval;
}
static int as3645a_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct as3645a *flash = to_as3645a(subdev);
int rval;
if (flash->power_count == 0)
return 0;
rval = __as3645a_set_power(flash, 1);
dev_dbg(&client->dev, "Resume %s\n", rval < 0 ? "fail" : "ok");
return rval;
}
static int as3645a_init_controls(struct as3645a *flash)
{
const struct as3645a_platform_data *pdata = flash->pdata;
struct v4l2_ctrl *ctrl;
int maximum;
v4l2_ctrl_handler_init(&flash->ctrls, 10);
v4l2_ctrl_new_std_menu(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_LED_MODE, 2, ~7,
V4L2_FLASH_LED_MODE_NONE);
v4l2_ctrl_new_std_menu(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_STROBE_SOURCE,
pdata->ext_strobe ? 1 : 0,
pdata->ext_strobe ? ~3 : ~1,
V4L2_FLASH_STROBE_SOURCE_SOFTWARE);
flash->strobe_source = V4L2_FLASH_STROBE_SOURCE_SOFTWARE;
v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_STROBE, 0, 0, 0, 0);
v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_STROBE_STOP, 0, 0, 0, 0);
ctrl = v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_STROBE_STATUS, 0, 1, 1, 1);
if (ctrl != NULL)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;
maximum = pdata->timeout_max;
v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_TIMEOUT, AS3645A_FLASH_TIMEOUT_MIN,
maximum, AS3645A_FLASH_TIMEOUT_STEP, maximum);
flash->timeout = maximum;
maximum = pdata->flash_max_current;
v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_INTENSITY, AS3645A_FLASH_INTENSITY_MIN,
maximum, AS3645A_FLASH_INTENSITY_STEP, maximum);
flash->flash_current = (maximum - AS3645A_FLASH_INTENSITY_MIN)
/ AS3645A_FLASH_INTENSITY_STEP;
maximum = pdata->torch_max_current;
v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_TORCH_INTENSITY,
AS3645A_TORCH_INTENSITY_MIN, maximum,
AS3645A_TORCH_INTENSITY_STEP,
AS3645A_TORCH_INTENSITY_MIN);
flash->assist_current = 0;
v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_INDICATOR_INTENSITY,
AS3645A_INDICATOR_INTENSITY_MIN,
AS3645A_INDICATOR_INTENSITY_MAX,
AS3645A_INDICATOR_INTENSITY_STEP,
AS3645A_INDICATOR_INTENSITY_MIN);
flash->indicator_current = 0;
ctrl = v4l2_ctrl_new_std(&flash->ctrls, &as3645a_ctrl_ops,
V4L2_CID_FLASH_FAULT, 0,
V4L2_FLASH_FAULT_OVER_VOLTAGE |
V4L2_FLASH_FAULT_TIMEOUT |
V4L2_FLASH_FAULT_OVER_TEMPERATURE |
V4L2_FLASH_FAULT_SHORT_CIRCUIT, 0, 0);
if (ctrl != NULL)
ctrl->flags |= V4L2_CTRL_FLAG_VOLATILE;
flash->subdev.ctrl_handler = &flash->ctrls;
return flash->ctrls.error;
}
static int as3645a_probe(struct i2c_client *client,
const struct i2c_device_id *devid)
{
struct as3645a *flash;
int ret;
if (client->dev.platform_data == NULL)
return -ENODEV;
flash = kzalloc(sizeof(*flash), GFP_KERNEL);
if (flash == NULL)
return -ENOMEM;
flash->pdata = client->dev.platform_data;
v4l2_i2c_subdev_init(&flash->subdev, client, &as3645a_ops);
flash->subdev.internal_ops = &as3645a_internal_ops;
flash->subdev.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
ret = as3645a_init_controls(flash);
if (ret < 0)
goto done;
ret = media_entity_init(&flash->subdev.entity, 0, NULL, 0);
if (ret < 0)
goto done;
flash->subdev.entity.type = MEDIA_ENT_T_V4L2_SUBDEV_FLASH;
mutex_init(&flash->power_lock);
flash->led_mode = V4L2_FLASH_LED_MODE_NONE;
done:
if (ret < 0) {
v4l2_ctrl_handler_free(&flash->ctrls);
kfree(flash);
}
return ret;
}
static int __exit as3645a_remove(struct i2c_client *client)
{
struct v4l2_subdev *subdev = i2c_get_clientdata(client);
struct as3645a *flash = to_as3645a(subdev);
v4l2_device_unregister_subdev(subdev);
v4l2_ctrl_handler_free(&flash->ctrls);
media_entity_cleanup(&flash->subdev.entity);
mutex_destroy(&flash->power_lock);
kfree(flash);
return 0;
}
static int __init as3645a_init(void)
{
int rval;
rval = i2c_add_driver(&as3645a_i2c_driver);
if (rval)
pr_err("%s: Failed to register the driver\n", AS3645A_NAME);
return rval;
}
static void __exit as3645a_exit(void)
{
i2c_del_driver(&as3645a_i2c_driver);
}
