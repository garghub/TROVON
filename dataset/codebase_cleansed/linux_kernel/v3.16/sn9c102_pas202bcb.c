static int pas202bcb_init(struct sn9c102_device *cam)
{
int err = 0;
switch (sn9c102_get_bridge(cam)) {
case BRIDGE_SN9C101:
case BRIDGE_SN9C102:
err = sn9c102_write_const_regs(cam, {0x00, 0x10}, {0x00, 0x11},
{0x00, 0x14}, {0x20, 0x17},
{0x30, 0x19}, {0x09, 0x18});
break;
case BRIDGE_SN9C103:
err = sn9c102_write_const_regs(cam, {0x00, 0x02}, {0x00, 0x03},
{0x1a, 0x04}, {0x20, 0x05},
{0x20, 0x06}, {0x20, 0x07},
{0x00, 0x10}, {0x00, 0x11},
{0x00, 0x14}, {0x20, 0x17},
{0x30, 0x19}, {0x09, 0x18},
{0x02, 0x1c}, {0x03, 0x1d},
{0x0f, 0x1e}, {0x0c, 0x1f},
{0x00, 0x20}, {0x10, 0x21},
{0x20, 0x22}, {0x30, 0x23},
{0x40, 0x24}, {0x50, 0x25},
{0x60, 0x26}, {0x70, 0x27},
{0x80, 0x28}, {0x90, 0x29},
{0xa0, 0x2a}, {0xb0, 0x2b},
{0xc0, 0x2c}, {0xd0, 0x2d},
{0xe0, 0x2e}, {0xf0, 0x2f},
{0xff, 0x30});
break;
default:
break;
}
err += sn9c102_i2c_write(cam, 0x02, 0x14);
err += sn9c102_i2c_write(cam, 0x03, 0x40);
err += sn9c102_i2c_write(cam, 0x0d, 0x2c);
err += sn9c102_i2c_write(cam, 0x0e, 0x01);
err += sn9c102_i2c_write(cam, 0x0f, 0xa9);
err += sn9c102_i2c_write(cam, 0x10, 0x08);
err += sn9c102_i2c_write(cam, 0x13, 0x63);
err += sn9c102_i2c_write(cam, 0x15, 0x70);
err += sn9c102_i2c_write(cam, 0x11, 0x01);
msleep(400);
return err;
}
static int pas202bcb_get_ctrl(struct sn9c102_device *cam,
struct v4l2_control *ctrl)
{
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
{
int r1 = sn9c102_i2c_read(cam, 0x04),
r2 = sn9c102_i2c_read(cam, 0x05);
if (r1 < 0 || r2 < 0)
return -EIO;
ctrl->value = (r1 << 6) | (r2 & 0x3f);
}
return 0;
case V4L2_CID_RED_BALANCE:
ctrl->value = sn9c102_i2c_read(cam, 0x09);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x0f;
return 0;
case V4L2_CID_BLUE_BALANCE:
ctrl->value = sn9c102_i2c_read(cam, 0x07);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x0f;
return 0;
case V4L2_CID_GAIN:
ctrl->value = sn9c102_i2c_read(cam, 0x10);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x1f;
return 0;
case SN9C102_V4L2_CID_GREEN_BALANCE:
ctrl->value = sn9c102_i2c_read(cam, 0x08);
if (ctrl->value < 0)
return -EIO;
ctrl->value &= 0x0f;
return 0;
case SN9C102_V4L2_CID_DAC_MAGNITUDE:
ctrl->value = sn9c102_i2c_read(cam, 0x0c);
if (ctrl->value < 0)
return -EIO;
return 0;
default:
return -EINVAL;
}
}
static int pas202bcb_set_pix_format(struct sn9c102_device *cam,
const struct v4l2_pix_format *pix)
{
int err = 0;
if (pix->pixelformat == V4L2_PIX_FMT_SN9C10X)
err += sn9c102_write_reg(cam, 0x28, 0x17);
else
err += sn9c102_write_reg(cam, 0x20, 0x17);
return err;
}
static int pas202bcb_set_ctrl(struct sn9c102_device *cam,
const struct v4l2_control *ctrl)
{
int err = 0;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
err += sn9c102_i2c_write(cam, 0x04, ctrl->value >> 6);
err += sn9c102_i2c_write(cam, 0x05, ctrl->value & 0x3f);
break;
case V4L2_CID_RED_BALANCE:
err += sn9c102_i2c_write(cam, 0x09, ctrl->value);
break;
case V4L2_CID_BLUE_BALANCE:
err += sn9c102_i2c_write(cam, 0x07, ctrl->value);
break;
case V4L2_CID_GAIN:
err += sn9c102_i2c_write(cam, 0x10, ctrl->value);
break;
case SN9C102_V4L2_CID_GREEN_BALANCE:
err += sn9c102_i2c_write(cam, 0x08, ctrl->value);
break;
case SN9C102_V4L2_CID_DAC_MAGNITUDE:
err += sn9c102_i2c_write(cam, 0x0c, ctrl->value);
break;
default:
return -EINVAL;
}
err += sn9c102_i2c_write(cam, 0x11, 0x01);
return err ? -EIO : 0;
}
static int pas202bcb_set_crop(struct sn9c102_device *cam,
const struct v4l2_rect *rect)
{
struct sn9c102_sensor *s = sn9c102_get_sensor(cam);
int err = 0;
u8 h_start = 0,
v_start = (u8)(rect->top - s->cropcap.bounds.top) + 3;
switch (sn9c102_get_bridge(cam)) {
case BRIDGE_SN9C101:
case BRIDGE_SN9C102:
h_start = (u8)(rect->left - s->cropcap.bounds.left) + 4;
break;
case BRIDGE_SN9C103:
h_start = (u8)(rect->left - s->cropcap.bounds.left) + 3;
break;
default:
break;
}
err += sn9c102_write_reg(cam, h_start, 0x12);
err += sn9c102_write_reg(cam, v_start, 0x13);
return err;
}
int sn9c102_probe_pas202bcb(struct sn9c102_device *cam)
{
int r0 = 0, r1 = 0, err = 0;
unsigned int pid = 0;
switch (sn9c102_get_bridge(cam)) {
case BRIDGE_SN9C101:
case BRIDGE_SN9C102:
err = sn9c102_write_const_regs(cam,
{0x01, 0x01},
{0x40, 0x01},
{0x28, 0x17});
break;
case BRIDGE_SN9C103:
err = sn9c102_write_const_regs(cam, {0x09, 0x01}, {0x44, 0x01},
{0x44, 0x02}, {0x29, 0x17});
break;
default:
break;
}
r0 = sn9c102_i2c_try_read(cam, &pas202bcb, 0x00);
r1 = sn9c102_i2c_try_read(cam, &pas202bcb, 0x01);
if (err || r0 < 0 || r1 < 0)
return -EIO;
pid = (r0 << 4) | ((r1 & 0xf0) >> 4);
if (pid != 0x017)
return -ENODEV;
sn9c102_attach_sensor(cam, &pas202bcb);
return 0;
}
