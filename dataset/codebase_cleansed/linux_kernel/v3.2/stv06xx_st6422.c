static int st6422_probe(struct sd *sd)
{
struct st6422_settings *sensor_settings;
if (sd->bridge != BRIDGE_ST6422)
return -ENODEV;
pr_info("st6422 sensor detected\n");
sensor_settings = kmalloc(sizeof *sensor_settings, GFP_KERNEL);
if (!sensor_settings)
return -ENOMEM;
sd->gspca_dev.cam.cam_mode = st6422_mode;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(st6422_mode);
sd->gspca_dev.cam.ctrls = sensor_settings->ctrls;
sd->desc.ctrls = st6422_ctrl;
sd->desc.nctrls = ARRAY_SIZE(st6422_ctrl);
sd->sensor_priv = sensor_settings;
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
static void st6422_disconnect(struct sd *sd)
{
sd->sensor = NULL;
kfree(sd->sensor_priv);
}
static int setbrightness(struct sd *sd)
{
struct st6422_settings *sensor_settings = sd->sensor_priv;
return stv06xx_write_bridge(sd, 0x1432,
sensor_settings->ctrls[BRIGHTNESS].val);
}
static int setcontrast(struct sd *sd)
{
struct st6422_settings *sensor_settings = sd->sensor_priv;
return stv06xx_write_bridge(sd, 0x143a,
sensor_settings->ctrls[CONTRAST].val | 0xf0);
}
static int setgain(struct sd *sd)
{
struct st6422_settings *sensor_settings = sd->sensor_priv;
u8 gain;
int err;
gain = sensor_settings->ctrls[GAIN].val;
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
static int setexposure(struct sd *sd)
{
struct st6422_settings *sensor_settings = sd->sensor_priv;
u16 expo;
int err;
expo = sensor_settings->ctrls[EXPOSURE].val;
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
err = setbrightness(sd);
if (err < 0)
return err;
err = setcontrast(sd);
if (err < 0)
return err;
err = setexposure(sd);
if (err < 0)
return err;
err = setgain(sd);
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
static void st6422_set_brightness(struct gspca_dev *gspca_dev)
{
int err;
struct sd *sd = (struct sd *) gspca_dev;
err = setbrightness(sd);
if (err >= 0)
err = stv06xx_write_bridge(sd, 0x143f, 0x01);
gspca_dev->usb_err = err;
}
static void st6422_set_contrast(struct gspca_dev *gspca_dev)
{
int err;
struct sd *sd = (struct sd *) gspca_dev;
err = setcontrast(sd);
if (err >= 0)
err = stv06xx_write_bridge(sd, 0x143f, 0x01);
gspca_dev->usb_err = err;
}
static void st6422_set_gain(struct gspca_dev *gspca_dev)
{
int err;
struct sd *sd = (struct sd *) gspca_dev;
err = setgain(sd);
if (err >= 0)
err = stv06xx_write_bridge(sd, 0x143f, 0x01);
gspca_dev->usb_err = err;
}
static void st6422_set_exposure(struct gspca_dev *gspca_dev)
{
int err;
struct sd *sd = (struct sd *) gspca_dev;
err = setexposure(sd);
if (err >= 0)
err = stv06xx_write_bridge(sd, 0x143f, 0x01);
gspca_dev->usb_err = err;
}
