static int tas5130d1b_init(struct et61x251_device* cam)
{
int err = 0;
err += et61x251_write_reg(cam, 0x14, 0x01);
err += et61x251_write_reg(cam, 0x1b, 0x02);
err += et61x251_write_reg(cam, 0x02, 0x12);
err += et61x251_write_reg(cam, 0x0e, 0x60);
err += et61x251_write_reg(cam, 0x80, 0x61);
err += et61x251_write_reg(cam, 0xf0, 0x62);
err += et61x251_write_reg(cam, 0x03, 0x63);
err += et61x251_write_reg(cam, 0x14, 0x64);
err += et61x251_write_reg(cam, 0xf4, 0x65);
err += et61x251_write_reg(cam, 0x01, 0x66);
err += et61x251_write_reg(cam, 0x05, 0x67);
err += et61x251_write_reg(cam, 0x8f, 0x68);
err += et61x251_write_reg(cam, 0x0f, 0x8d);
err += et61x251_write_reg(cam, 0x08, 0x8e);
return err;
}
static int tas5130d1b_set_ctrl(struct et61x251_device* cam,
const struct v4l2_control* ctrl)
{
int err = 0;
switch (ctrl->id) {
case V4L2_CID_GAIN:
err += et61x251_i2c_raw_write(cam, 2, 0x20,
0xf6-ctrl->value, 0, 0, 0,
0, 0, 0, 0);
break;
case V4L2_CID_EXPOSURE:
err += et61x251_i2c_raw_write(cam, 2, 0x40,
0x47-ctrl->value, 0, 0, 0,
0, 0, 0, 0);
break;
default:
return -EINVAL;
}
return err ? -EIO : 0;
}
int et61x251_probe_tas5130d1b(struct et61x251_device* cam)
{
const struct usb_device_id tas5130d1b_id_table[] = {
{ USB_DEVICE(0x102c, 0x6251), },
{ }
};
if (!et61x251_match_id(cam, tas5130d1b_id_table))
return -ENODEV;
et61x251_attach_sensor(cam, &tas5130d1b);
return 0;
}
