static int mi0343_init(struct sn9c102_device* cam)
{
struct sn9c102_sensor* s = sn9c102_get_sensor(cam);
int err = 0;
err = sn9c102_write_const_regs(cam, {0x00, 0x10}, {0x00, 0x11},
{0x0a, 0x14}, {0x40, 0x01},
{0x20, 0x17}, {0x07, 0x18},
{0xa0, 0x19});
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id, 0x0d,
0x00, 0x01, 0, 0);
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id, 0x0d,
0x00, 0x00, 0, 0);
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id, 0x03,
0x01, 0xe1, 0, 0);
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id, 0x04,
0x02, 0x81, 0, 0);
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id, 0x05,
0x00, 0x17, 0, 0);
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id, 0x06,
0x00, 0x11, 0, 0);
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id, 0x62,
0x04, 0x9a, 0, 0);
return err;
}
static int mi0343_get_ctrl(struct sn9c102_device* cam,
struct v4l2_control* ctrl)
{
struct sn9c102_sensor* s = sn9c102_get_sensor(cam);
u8 data[2];
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
if (sn9c102_i2c_try_raw_read(cam, s, s->i2c_slave_id, 0x09, 2,
data) < 0)
return -EIO;
ctrl->value = data[0];
return 0;
case V4L2_CID_GAIN:
if (sn9c102_i2c_try_raw_read(cam, s, s->i2c_slave_id, 0x35, 2,
data) < 0)
return -EIO;
break;
case V4L2_CID_HFLIP:
if (sn9c102_i2c_try_raw_read(cam, s, s->i2c_slave_id, 0x20, 2,
data) < 0)
return -EIO;
ctrl->value = data[1] & 0x20 ? 1 : 0;
return 0;
case V4L2_CID_VFLIP:
if (sn9c102_i2c_try_raw_read(cam, s, s->i2c_slave_id, 0x20, 2,
data) < 0)
return -EIO;
ctrl->value = data[1] & 0x80 ? 1 : 0;
return 0;
case V4L2_CID_RED_BALANCE:
if (sn9c102_i2c_try_raw_read(cam, s, s->i2c_slave_id, 0x2d, 2,
data) < 0)
return -EIO;
break;
case V4L2_CID_BLUE_BALANCE:
if (sn9c102_i2c_try_raw_read(cam, s, s->i2c_slave_id, 0x2c, 2,
data) < 0)
return -EIO;
break;
case SN9C102_V4L2_CID_GREEN_BALANCE:
if (sn9c102_i2c_try_raw_read(cam, s, s->i2c_slave_id, 0x2e, 2,
data) < 0)
return -EIO;
break;
default:
return -EINVAL;
}
switch (ctrl->id) {
case V4L2_CID_GAIN:
case V4L2_CID_RED_BALANCE:
case V4L2_CID_BLUE_BALANCE:
case SN9C102_V4L2_CID_GREEN_BALANCE:
ctrl->value = data[1] | (data[0] << 8);
if (ctrl->value >= 0x10 && ctrl->value <= 0x3f)
ctrl->value -= 0x10;
else if (ctrl->value >= 0x60 && ctrl->value <= 0x7f)
ctrl->value -= 0x60;
else if (ctrl->value >= 0xe0 && ctrl->value <= 0xff)
ctrl->value -= 0xe0;
}
return 0;
}
static int mi0343_set_ctrl(struct sn9c102_device* cam,
const struct v4l2_control* ctrl)
{
struct sn9c102_sensor* s = sn9c102_get_sensor(cam);
u16 reg = 0;
int err = 0;
switch (ctrl->id) {
case V4L2_CID_GAIN:
case V4L2_CID_RED_BALANCE:
case V4L2_CID_BLUE_BALANCE:
case SN9C102_V4L2_CID_GREEN_BALANCE:
if (ctrl->value <= (0x3f-0x10))
reg = 0x10 + ctrl->value;
else if (ctrl->value <= ((0x3f-0x10) + (0x7f-0x60)))
reg = 0x60 + (ctrl->value - (0x3f-0x10));
else
reg = 0xe0 + (ctrl->value - (0x3f-0x10) - (0x7f-0x60));
break;
}
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x09, ctrl->value, 0x00,
0, 0);
break;
case V4L2_CID_GAIN:
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x35, reg >> 8, reg & 0xff,
0, 0);
break;
case V4L2_CID_HFLIP:
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x20, ctrl->value ? 0x40:0x00,
ctrl->value ? 0x20:0x00,
0, 0);
break;
case V4L2_CID_VFLIP:
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x20, ctrl->value ? 0x80:0x00,
ctrl->value ? 0x80:0x00,
0, 0);
break;
case V4L2_CID_RED_BALANCE:
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x2d, reg >> 8, reg & 0xff,
0, 0);
break;
case V4L2_CID_BLUE_BALANCE:
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x2c, reg >> 8, reg & 0xff,
0, 0);
break;
case SN9C102_V4L2_CID_GREEN_BALANCE:
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x2b, reg >> 8, reg & 0xff,
0, 0);
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x2e, reg >> 8, reg & 0xff,
0, 0);
break;
default:
return -EINVAL;
}
return err ? -EIO : 0;
}
static int mi0343_set_crop(struct sn9c102_device* cam,
const struct v4l2_rect* rect)
{
struct sn9c102_sensor* s = sn9c102_get_sensor(cam);
int err = 0;
u8 h_start = (u8)(rect->left - s->cropcap.bounds.left) + 0,
v_start = (u8)(rect->top - s->cropcap.bounds.top) + 2;
err += sn9c102_write_reg(cam, h_start, 0x12);
err += sn9c102_write_reg(cam, v_start, 0x13);
return err;
}
static int mi0343_set_pix_format(struct sn9c102_device* cam,
const struct v4l2_pix_format* pix)
{
struct sn9c102_sensor* s = sn9c102_get_sensor(cam);
int err = 0;
if (pix->pixelformat == V4L2_PIX_FMT_SN9C10X) {
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x0a, 0x00, 0x03, 0, 0);
err += sn9c102_write_reg(cam, 0x20, 0x19);
} else {
err += sn9c102_i2c_try_raw_write(cam, s, 4, s->i2c_slave_id,
0x0a, 0x00, 0x05, 0, 0);
err += sn9c102_write_reg(cam, 0xa0, 0x19);
}
return err;
}
int sn9c102_probe_mi0343(struct sn9c102_device* cam)
{
u8 data[2];
if (sn9c102_write_const_regs(cam, {0x01, 0x01}, {0x00, 0x01},
{0x28, 0x17}))
return -EIO;
if (sn9c102_i2c_try_raw_read(cam, &mi0343, mi0343.i2c_slave_id, 0x00,
2, data) < 0)
return -EIO;
if (data[1] != 0x42 || data[0] != 0xe3)
return -ENODEV;
sn9c102_attach_sensor(cam, &mi0343);
return 0;
}
