static int pas106b_init(struct sn9c102_device *cam)
{
int err = 0;
err = sn9c102_write_const_regs(cam, {0x00, 0x10}, {0x00, 0x11},
{0x00, 0x14}, {0x20, 0x17},
{0x20, 0x19}, {0x09, 0x18});
err += sn9c102_i2c_write(cam, 0x02, 0x0c);
err += sn9c102_i2c_write(cam, 0x05, 0x5a);
err += sn9c102_i2c_write(cam, 0x06, 0x88);
err += sn9c102_i2c_write(cam, 0x07, 0x80);
err += sn9c102_i2c_write(cam, 0x10, 0x06);
err += sn9c102_i2c_write(cam, 0x11, 0x06);
err += sn9c102_i2c_write(cam, 0x12, 0x00);
err += sn9c102_i2c_write(cam, 0x14, 0x02);
err += sn9c102_i2c_write(cam, 0x13, 0x01);
msleep(400);
return err;
}
static int pas106b_get_ctrl(struct sn9c102_device *cam,
struct v4l2_control *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
{
int r1 = sn9c102_i2c_read(cam, 0x03),
r2 = sn9c102_i2c_read(cam, 0x04);
if (r1 < 0 || r2 < 0)
return -EIO;
ctrl->value = (r1 << 4) | (r2 & 0x0f);
}
return 0;
case V4L2_CID_RED_BALANCE:
ctrl->value = sn9c102_i2c_read(cam, 0x0c);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x1f;
return 0;
case V4L2_CID_BLUE_BALANCE:
ctrl->value = sn9c102_i2c_read(cam, 0x09);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x1f;
return 0;
case V4L2_CID_GAIN:
ctrl->value = sn9c102_i2c_read(cam, 0x0e);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x1f;
return 0;
case V4L2_CID_CONTRAST:
ctrl->value = sn9c102_i2c_read(cam, 0x0f);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x07;
return 0;
case SN9C102_V4L2_CID_GREEN_BALANCE:
ctrl->value = sn9c102_i2c_read(cam, 0x0a);
if (ctrl->value < 0)
return -EIO;
ctrl->value = (ctrl->value & 0x1f) << 1;
return 0;
case SN9C102_V4L2_CID_DAC_MAGNITUDE:
ctrl->value = sn9c102_i2c_read(cam, 0x08);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0xf8;
return 0;
default:
return -EINVAL;
}
}
static int pas106b_set_ctrl(struct sn9c102_device *cam,
const struct v4l2_control *ctrl)
{
int err = 0;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
err += sn9c102_i2c_write(cam, 0x03, ctrl->value >> 4);
err += sn9c102_i2c_write(cam, 0x04, ctrl->value & 0x0f);
break;
case V4L2_CID_RED_BALANCE:
err += sn9c102_i2c_write(cam, 0x0c, ctrl->value);
break;
case V4L2_CID_BLUE_BALANCE:
err += sn9c102_i2c_write(cam, 0x09, ctrl->value);
break;
case V4L2_CID_GAIN:
err += sn9c102_i2c_write(cam, 0x0e, ctrl->value);
break;
case V4L2_CID_CONTRAST:
err += sn9c102_i2c_write(cam, 0x0f, ctrl->value);
break;
case SN9C102_V4L2_CID_GREEN_BALANCE:
err += sn9c102_i2c_write(cam, 0x0a, ctrl->value >> 1);
err += sn9c102_i2c_write(cam, 0x0b, ctrl->value >> 1);
break;
case SN9C102_V4L2_CID_DAC_MAGNITUDE:
err += sn9c102_i2c_write(cam, 0x08, ctrl->value << 3);
break;
default:
return -EINVAL;
}
err += sn9c102_i2c_write(cam, 0x13, 0x01);
return err ? -EIO : 0;
}
static int pas106b_set_crop(struct sn9c102_device *cam,
const struct v4l2_rect *rect)
{
struct sn9c102_sensor *s = sn9c102_get_sensor(cam);
int err = 0;
u8 h_start = (u8)(rect->left - s->cropcap.bounds.left) + 4,
v_start = (u8)(rect->top - s->cropcap.bounds.top) + 3;
err += sn9c102_write_reg(cam, h_start, 0x12);
err += sn9c102_write_reg(cam, v_start, 0x13);
return err;
}
static int pas106b_set_pix_format(struct sn9c102_device *cam,
const struct v4l2_pix_format *pix)
{
int err = 0;
if (pix->pixelformat == V4L2_PIX_FMT_SN9C10X)
err += sn9c102_write_reg(cam, 0x2c, 0x17);
else
err += sn9c102_write_reg(cam, 0x20, 0x17);
return err;
}
int sn9c102_probe_pas106b(struct sn9c102_device *cam)
{
int r0 = 0, r1 = 0;
unsigned int pid = 0;
if (sn9c102_write_const_regs(cam,
{0x01, 0x01},
{0x00, 0x01},
{0x28, 0x17}))
return -EIO;
r0 = sn9c102_i2c_try_read(cam, &pas106b, 0x00);
r1 = sn9c102_i2c_try_read(cam, &pas106b, 0x01);
if (r0 < 0 || r1 < 0)
return -EIO;
pid = (r0 << 11) | ((r1 & 0xf0) >> 4);
if (pid != 0x007)
return -ENODEV;
sn9c102_attach_sensor(cam, &pas106b);
return 0;
}
