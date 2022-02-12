static int st6422_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
int err = -EINVAL;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
err = setbrightness(sd, ctrl->val);
break;
case V4L2_CID_CONTRAST:
err = setcontrast(sd, ctrl->val);
break;
case V4L2_CID_GAIN:
err = setgain(sd, ctrl->val);
break;
case V4L2_CID_EXPOSURE:
err = setexposure(sd, ctrl->val);
break;
}
if (err >= 0)
err = stv06xx_write_bridge(sd, 0x143f, 0x01);
sd->gspca_dev.usb_err = err;
return err;
}
static int st6422_init_controls(struct sd *sd)
{
struct v4l2_ctrl_handler *hdl = &sd->gspca_dev.ctrl_handler;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &st6422_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 31, 1, 3);
v4l2_ctrl_new_std(hdl, &st6422_ctrl_ops,
V4L2_CID_CONTRAST, 0, 15, 1, 11);
v4l2_ctrl_new_std(hdl, &st6422_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 1023, 1, 256);
v4l2_ctrl_new_std(hdl, &st6422_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 64);
return hdl->error;
}
static int st6422_probe(struct sd *sd)
{
if (sd->bridge != BRIDGE_ST6422)
return -ENODEV;
pr_info("st6422 sensor detected\n");
sd->gspca_dev.cam.cam_mode = st6422_mode;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(st6422_mode);
return 0;
}
static int st6422_init(struct sd *sd)
{
int err = 0, i;
const u16 st6422_bridge_init[][2] = {
{ STV_ISO_ENABLE, 0x00 },
{ 0x1436, 0x00 },
{ 0x1432, 0x03 },
{ 0x143a, 0xf9 },
{ 0x0509, 0x38 },
{ 0x050a, 0x38 },
{ 0x050b, 0x38 },
{ 0x050c, 0x2a },
{ 0x050d, 0x01 },
{ 0x1431, 0x00 },
{ 0x1433, 0x34 },
{ 0x1438, 0x18 },
{ 0x1439, 0x00 },
{ 0x143b, 0x05 },
{ 0x143c, 0x00 },
{ 0x143e, 0x01 },
{ 0x143d, 0x00 },
{ 0x1442, 0xe2 },
{ 0x1500, 0xd0 },
{ 0x1500, 0xd0 },
{ 0x1500, 0x50 },
{ 0x1501, 0xaf },
{ 0x1502, 0xc2 },
{ 0x1503, 0x45 },
{ 0x1505, 0x02 },
{ 0x150e, 0x8e },
{ 0x150f, 0x37 },
{ 0x15c0, 0x00 },
{ 0x15c3, 0x08 },
{ 0x143f, 0x01 },
};
for (i = 0; i < ARRAY_SIZE(st6422_bridge_init) && !err; i++) {
err = stv06xx_write_bridge(sd, st6422_bridge_init[i][0],
st6422_bridge_init[i][1]);
}
return err;
}
static int setbrightness(struct sd *sd, s32 val)
{
return stv06xx_write_bridge(sd, 0x1432, val);
}
static int setcontrast(struct sd *sd, s32 val)
{
return stv06xx_write_bridge(sd, 0x143a, val | 0xf0);
}
static int setgain(struct sd *sd, u8 gain)
{
int err;
err = stv06xx_write_bridge(sd, 0x0509, gain);
if (err < 0)
return err;
err = stv06xx_write_bridge(sd, 0x050a, gain);
if (err < 0)
return err;
err = stv06xx_write_bridge(sd, 0x050b, gain);
if (err < 0)
return err;
err = stv06xx_write_bridge(sd, 0x050c, 0x2a);
if (err < 0)
return err;
return stv06xx_write_bridge(sd, 0x050d, 0x01);
}
static int setexposure(struct sd *sd, s16 expo)
{
int err;
err = stv06xx_write_bridge(sd, 0x143d, expo & 0xff);
if (err < 0)
return err;
return stv06xx_write_bridge(sd, 0x143e, expo >> 8);
}
static int st6422_start(struct sd *sd)
{
int err;
struct cam *cam = &sd->gspca_dev.cam;
if (cam->cam_mode[sd->gspca_dev.curr_mode].priv)
err = stv06xx_write_bridge(sd, 0x1505, 0x0f);
else
err = stv06xx_write_bridge(sd, 0x1505, 0x02);
if (err < 0)
return err;
err = stv06xx_write_bridge(sd, 0x143f, 0x01);
return (err < 0) ? err : 0;
}
static int st6422_stop(struct sd *sd)
{
PDEBUG(D_STREAM, "Halting stream");
return 0;
}
