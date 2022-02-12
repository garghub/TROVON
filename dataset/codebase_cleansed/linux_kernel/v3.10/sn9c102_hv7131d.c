static int hv7131d_init(struct sn9c102_device* cam)
{
int err;
err = sn9c102_write_const_regs(cam, {0x00, 0x10}, {0x00, 0x11},
{0x00, 0x14}, {0x60, 0x17},
{0x0e, 0x18}, {0xf2, 0x19});
err += sn9c102_i2c_write(cam, 0x01, 0x04);
err += sn9c102_i2c_write(cam, 0x02, 0x00);
err += sn9c102_i2c_write(cam, 0x28, 0x00);
return err;
}
static int hv7131d_get_ctrl(struct sn9c102_device* cam,
struct v4l2_control* ctrl)
{
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
{
int r1 = sn9c102_i2c_read(cam, 0x26),
r2 = sn9c102_i2c_read(cam, 0x27);
if (r1 < 0 || r2 < 0)
return -EIO;
ctrl->value = (r1 << 8) | (r2 & 0xff);
}
return 0;
case V4L2_CID_RED_BALANCE:
if ((ctrl->value = sn9c102_i2c_read(cam, 0x31)) < 0)
return -EIO;
ctrl->value = 0x3f - (ctrl->value & 0x3f);
return 0;
case V4L2_CID_BLUE_BALANCE:
if ((ctrl->value = sn9c102_i2c_read(cam, 0x33)) < 0)
return -EIO;
ctrl->value = 0x3f - (ctrl->value & 0x3f);
return 0;
case SN9C102_V4L2_CID_GREEN_BALANCE:
if ((ctrl->value = sn9c102_i2c_read(cam, 0x32)) < 0)
return -EIO;
ctrl->value = 0x3f - (ctrl->value & 0x3f);
return 0;
case SN9C102_V4L2_CID_RESET_LEVEL:
if ((ctrl->value = sn9c102_i2c_read(cam, 0x30)) < 0)
return -EIO;
ctrl->value &= 0x3f;
return 0;
case SN9C102_V4L2_CID_PIXEL_BIAS_VOLTAGE:
if ((ctrl->value = sn9c102_i2c_read(cam, 0x34)) < 0)
return -EIO;
ctrl->value &= 0x07;
return 0;
default:
return -EINVAL;
}
}
static int hv7131d_set_ctrl(struct sn9c102_device* cam,
const struct v4l2_control* ctrl)
{
int err = 0;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
err += sn9c102_i2c_write(cam, 0x26, ctrl->value >> 8);
err += sn9c102_i2c_write(cam, 0x27, ctrl->value & 0xff);
break;
case V4L2_CID_RED_BALANCE:
err += sn9c102_i2c_write(cam, 0x31, 0x3f - ctrl->value);
break;
case V4L2_CID_BLUE_BALANCE:
err += sn9c102_i2c_write(cam, 0x33, 0x3f - ctrl->value);
break;
case SN9C102_V4L2_CID_GREEN_BALANCE:
err += sn9c102_i2c_write(cam, 0x32, 0x3f - ctrl->value);
break;
case SN9C102_V4L2_CID_RESET_LEVEL:
err += sn9c102_i2c_write(cam, 0x30, ctrl->value);
break;
case SN9C102_V4L2_CID_PIXEL_BIAS_VOLTAGE:
err += sn9c102_i2c_write(cam, 0x34, ctrl->value);
break;
default:
return -EINVAL;
}
return err ? -EIO : 0;
}
static int hv7131d_set_crop(struct sn9c102_device* cam,
const struct v4l2_rect* rect)
{
struct sn9c102_sensor* s = sn9c102_get_sensor(cam);
int err = 0;
u8 h_start = (u8)(rect->left - s->cropcap.bounds.left) + 2,
v_start = (u8)(rect->top - s->cropcap.bounds.top) + 2;
err += sn9c102_write_reg(cam, h_start, 0x12);
err += sn9c102_write_reg(cam, v_start, 0x13);
return err;
}
static int hv7131d_set_pix_format(struct sn9c102_device* cam,
const struct v4l2_pix_format* pix)
{
int err = 0;
if (pix->pixelformat == V4L2_PIX_FMT_SN9C10X)
err += sn9c102_write_reg(cam, 0x42, 0x19);
else
err += sn9c102_write_reg(cam, 0xf2, 0x19);
return err;
}
int sn9c102_probe_hv7131d(struct sn9c102_device* cam)
{
int r0 = 0, r1 = 0, err;
err = sn9c102_write_const_regs(cam, {0x01, 0x01}, {0x00, 0x01},
{0x28, 0x17});
r0 = sn9c102_i2c_try_read(cam, &hv7131d, 0x00);
r1 = sn9c102_i2c_try_read(cam, &hv7131d, 0x01);
if (err || r0 < 0 || r1 < 0)
return -EIO;
if ((r0 != 0x00 && r0 != 0x01) || r1 != 0x04)
return -ENODEV;
sn9c102_attach_sensor(cam, &hv7131d);
return 0;
}
