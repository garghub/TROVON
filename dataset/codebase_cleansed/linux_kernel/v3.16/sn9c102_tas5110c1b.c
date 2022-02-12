static int tas5110c1b_init(struct sn9c102_device *cam)
{
int err = 0;
err = sn9c102_write_const_regs(cam, {0x01, 0x01}, {0x44, 0x01},
{0x00, 0x10}, {0x00, 0x11},
{0x0a, 0x14}, {0x60, 0x17},
{0x06, 0x18}, {0xfb, 0x19});
err += sn9c102_i2c_write(cam, 0xc0, 0x80);
return err;
}
static int tas5110c1b_set_ctrl(struct sn9c102_device *cam,
const struct v4l2_control *ctrl)
{
int err = 0;
switch (ctrl->id) {
case V4L2_CID_GAIN:
err += sn9c102_i2c_write(cam, 0x20, 0xf6 - ctrl->value);
break;
default:
return -EINVAL;
}
return err ? -EIO : 0;
}
static int tas5110c1b_set_crop(struct sn9c102_device *cam,
const struct v4l2_rect *rect)
{
struct sn9c102_sensor *s = sn9c102_get_sensor(cam);
int err = 0;
u8 h_start = (u8)(rect->left - s->cropcap.bounds.left) + 69,
v_start = (u8)(rect->top - s->cropcap.bounds.top) + 9;
err += sn9c102_write_reg(cam, h_start, 0x12);
err += sn9c102_write_reg(cam, v_start, 0x13);
err += sn9c102_write_reg(cam, 0x14, 0x1a);
err += sn9c102_write_reg(cam, 0x0a, 0x1b);
err += sn9c102_write_reg(cam, sn9c102_pread_reg(cam, 0x19), 0x19);
return err;
}
static int tas5110c1b_set_pix_format(struct sn9c102_device *cam,
const struct v4l2_pix_format *pix)
{
int err = 0;
if (pix->pixelformat == V4L2_PIX_FMT_SN9C10X)
err += sn9c102_write_reg(cam, 0x2b, 0x19);
else
err += sn9c102_write_reg(cam, 0xfb, 0x19);
return err;
}
int sn9c102_probe_tas5110c1b(struct sn9c102_device *cam)
{
const struct usb_device_id tas5110c1b_id_table[] = {
{ USB_DEVICE(0x0c45, 0x6001), },
{ USB_DEVICE(0x0c45, 0x6005), },
{ USB_DEVICE(0x0c45, 0x60ab), },
{ }
};
if (!sn9c102_match_id(cam, tas5110c1b_id_table))
return -ENODEV;
sn9c102_attach_sensor(cam, &tas5110c1b);
return 0;
}
