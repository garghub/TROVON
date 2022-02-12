static int tas5130d1b_init(struct sn9c102_device* cam)
{
int err;
err = sn9c102_write_const_regs(cam, {0x01, 0x01}, {0x20, 0x17},
{0x04, 0x01}, {0x01, 0x10},
{0x00, 0x11}, {0x00, 0x14},
{0x60, 0x17}, {0x07, 0x18});
return err;
}
static int tas5130d1b_set_ctrl(struct sn9c102_device* cam,
const struct v4l2_control* ctrl)
{
int err = 0;
switch (ctrl->id) {
case V4L2_CID_GAIN:
err += sn9c102_i2c_write(cam, 0x20, 0xf6 - ctrl->value);
break;
case V4L2_CID_EXPOSURE:
err += sn9c102_i2c_write(cam, 0x40, 0x47 - ctrl->value);
break;
default:
return -EINVAL;
}
return err ? -EIO : 0;
}
static int tas5130d1b_set_crop(struct sn9c102_device* cam,
const struct v4l2_rect* rect)
{
struct sn9c102_sensor* s = sn9c102_get_sensor(cam);
u8 h_start = (u8)(rect->left - s->cropcap.bounds.left) + 104,
v_start = (u8)(rect->top - s->cropcap.bounds.top) + 12;
int err = 0;
err += sn9c102_write_reg(cam, h_start, 0x12);
err += sn9c102_write_reg(cam, v_start, 0x13);
err += sn9c102_write_reg(cam, 0x1f, 0x1a);
err += sn9c102_write_reg(cam, 0x1a, 0x1b);
err += sn9c102_write_reg(cam, sn9c102_pread_reg(cam, 0x19), 0x19);
return err;
}
static int tas5130d1b_set_pix_format(struct sn9c102_device* cam,
const struct v4l2_pix_format* pix)
{
int err = 0;
if (pix->pixelformat == V4L2_PIX_FMT_SN9C10X)
err += sn9c102_write_reg(cam, 0x63, 0x19);
else
err += sn9c102_write_reg(cam, 0xf3, 0x19);
return err;
}
int sn9c102_probe_tas5130d1b(struct sn9c102_device* cam)
{
const struct usb_device_id tas5130d1b_id_table[] = {
{ USB_DEVICE(0x0c45, 0x6024), },
{ USB_DEVICE(0x0c45, 0x6025), },
{ USB_DEVICE(0x0c45, 0x60aa), },
{ }
};
if (!sn9c102_match_id(cam, tas5130d1b_id_table))
return -ENODEV;
sn9c102_attach_sensor(cam, &tas5130d1b);
return 0;
}
