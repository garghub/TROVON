static inline struct indycam *to_indycam(struct v4l2_subdev *sd)
{
return container_of(sd, struct indycam, sd);
}
static int indycam_read_reg(struct v4l2_subdev *sd, u8 reg, u8 *value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int ret;
if (reg == INDYCAM_REG_RESET) {
dprintk("indycam_read_reg(): "
"skipping write-only register %d\n", reg);
*value = 0;
return 0;
}
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0) {
printk(KERN_ERR "IndyCam: indycam_read_reg(): read failed, "
"register = 0x%02x\n", reg);
return ret;
}
*value = (u8)ret;
return 0;
}
static int indycam_write_reg(struct v4l2_subdev *sd, u8 reg, u8 value)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int err;
if (reg == INDYCAM_REG_BRIGHTNESS || reg == INDYCAM_REG_VERSION) {
dprintk("indycam_write_reg(): "
"skipping read-only register %d\n", reg);
return 0;
}
dprintk("Writing Reg %d = 0x%02x\n", reg, value);
err = i2c_smbus_write_byte_data(client, reg, value);
if (err) {
printk(KERN_ERR "IndyCam: indycam_write_reg(): write failed, "
"register = 0x%02x, value = 0x%02x\n", reg, value);
}
return err;
}
static int indycam_write_block(struct v4l2_subdev *sd, u8 reg,
u8 length, u8 *data)
{
int i, err;
for (i = 0; i < length; i++) {
err = indycam_write_reg(sd, reg + i, data[i]);
if (err)
return err;
}
return 0;
}
static void indycam_regdump_debug(struct v4l2_subdev *sd)
{
int i;
u8 val;
for (i = 0; i < 9; i++) {
indycam_read_reg(sd, i, &val);
dprintk("Reg %d = 0x%02x\n", i, val);
}
}
static int indycam_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct indycam *camera = to_indycam(sd);
u8 reg;
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = indycam_read_reg(sd, INDYCAM_REG_CONTROL, &reg);
if (ret)
return -EIO;
if (ctrl->id == V4L2_CID_AUTOGAIN)
ctrl->value = (reg & INDYCAM_CONTROL_AGCENA)
? 1 : 0;
else
ctrl->value = (reg & INDYCAM_CONTROL_AWBCTL)
? 1 : 0;
break;
case V4L2_CID_EXPOSURE:
ret = indycam_read_reg(sd, INDYCAM_REG_SHUTTER, &reg);
if (ret)
return -EIO;
ctrl->value = ((s32)reg == 0x00) ? 0xff : ((s32)reg - 1);
break;
case V4L2_CID_GAIN:
ret = indycam_read_reg(sd, INDYCAM_REG_GAIN, &reg);
if (ret)
return -EIO;
ctrl->value = (s32)reg;
break;
case V4L2_CID_RED_BALANCE:
ret = indycam_read_reg(sd, INDYCAM_REG_RED_BALANCE, &reg);
if (ret)
return -EIO;
ctrl->value = (s32)reg;
break;
case V4L2_CID_BLUE_BALANCE:
ret = indycam_read_reg(sd, INDYCAM_REG_BLUE_BALANCE, &reg);
if (ret)
return -EIO;
ctrl->value = (s32)reg;
break;
case INDYCAM_CONTROL_RED_SATURATION:
ret = indycam_read_reg(sd,
INDYCAM_REG_RED_SATURATION, &reg);
if (ret)
return -EIO;
ctrl->value = (s32)reg;
break;
case INDYCAM_CONTROL_BLUE_SATURATION:
ret = indycam_read_reg(sd,
INDYCAM_REG_BLUE_SATURATION, &reg);
if (ret)
return -EIO;
ctrl->value = (s32)reg;
break;
case V4L2_CID_GAMMA:
if (camera->version == CAMERA_VERSION_MOOSE) {
ret = indycam_read_reg(sd,
INDYCAM_REG_GAMMA, &reg);
if (ret)
return -EIO;
ctrl->value = (s32)reg;
} else {
ctrl->value = INDYCAM_GAMMA_DEFAULT;
}
break;
default:
ret = -EINVAL;
}
return ret;
}
static int indycam_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct indycam *camera = to_indycam(sd);
u8 reg;
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = indycam_read_reg(sd, INDYCAM_REG_CONTROL, &reg);
if (ret)
break;
if (ctrl->id == V4L2_CID_AUTOGAIN) {
if (ctrl->value)
reg |= INDYCAM_CONTROL_AGCENA;
else
reg &= ~INDYCAM_CONTROL_AGCENA;
} else {
if (ctrl->value)
reg |= INDYCAM_CONTROL_AWBCTL;
else
reg &= ~INDYCAM_CONTROL_AWBCTL;
}
ret = indycam_write_reg(sd, INDYCAM_REG_CONTROL, reg);
break;
case V4L2_CID_EXPOSURE:
reg = (ctrl->value == 0xff) ? 0x00 : (ctrl->value + 1);
ret = indycam_write_reg(sd, INDYCAM_REG_SHUTTER, reg);
break;
case V4L2_CID_GAIN:
ret = indycam_write_reg(sd, INDYCAM_REG_GAIN, ctrl->value);
break;
case V4L2_CID_RED_BALANCE:
ret = indycam_write_reg(sd, INDYCAM_REG_RED_BALANCE,
ctrl->value);
break;
case V4L2_CID_BLUE_BALANCE:
ret = indycam_write_reg(sd, INDYCAM_REG_BLUE_BALANCE,
ctrl->value);
break;
case INDYCAM_CONTROL_RED_SATURATION:
ret = indycam_write_reg(sd, INDYCAM_REG_RED_SATURATION,
ctrl->value);
break;
case INDYCAM_CONTROL_BLUE_SATURATION:
ret = indycam_write_reg(sd, INDYCAM_REG_BLUE_SATURATION,
ctrl->value);
break;
case V4L2_CID_GAMMA:
if (camera->version == CAMERA_VERSION_MOOSE) {
ret = indycam_write_reg(sd, INDYCAM_REG_GAMMA,
ctrl->value);
}
break;
default:
ret = -EINVAL;
}
return ret;
}
static int indycam_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct indycam *camera = to_indycam(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_INDYCAM,
camera->version);
}
static int indycam_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err = 0;
struct indycam *camera;
struct v4l2_subdev *sd;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
camera = kzalloc(sizeof(struct indycam), GFP_KERNEL);
if (!camera)
return -ENOMEM;
sd = &camera->sd;
v4l2_i2c_subdev_init(sd, client, &indycam_ops);
camera->version = i2c_smbus_read_byte_data(client,
INDYCAM_REG_VERSION);
if (camera->version != CAMERA_VERSION_INDY &&
camera->version != CAMERA_VERSION_MOOSE) {
kfree(camera);
return -ENODEV;
}
printk(KERN_INFO "IndyCam v%d.%d detected\n",
INDYCAM_VERSION_MAJOR(camera->version),
INDYCAM_VERSION_MINOR(camera->version));
indycam_regdump(sd);
err = indycam_write_block(sd, 0, sizeof(initseq), (u8 *)&initseq);
if (err) {
printk(KERN_ERR "IndyCam initialization failed\n");
kfree(camera);
return -EIO;
}
indycam_regdump(sd);
err = indycam_write_reg(sd, INDYCAM_REG_CONTROL,
INDYCAM_CONTROL_AGCENA | INDYCAM_CONTROL_AWBCTL);
if (err) {
printk(KERN_ERR "IndyCam: White balancing camera failed\n");
kfree(camera);
return -EIO;
}
indycam_regdump(sd);
printk(KERN_INFO "IndyCam initialized\n");
return 0;
}
static int indycam_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(to_indycam(sd));
return 0;
}
