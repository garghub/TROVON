static int vv6410_probe(struct sd *sd)
{
u16 data;
int err, i;
s32 *sensor_settings;
err = stv06xx_read_sensor(sd, VV6410_DEVICEH, &data);
if (err < 0)
return -ENODEV;
if (data == 0x19) {
info("vv6410 sensor detected");
sensor_settings = kmalloc(ARRAY_SIZE(vv6410_ctrl) * sizeof(s32),
GFP_KERNEL);
if (!sensor_settings)
return -ENOMEM;
sd->gspca_dev.cam.cam_mode = vv6410_mode;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(vv6410_mode);
sd->desc.ctrls = vv6410_ctrl;
sd->desc.nctrls = ARRAY_SIZE(vv6410_ctrl);
for (i = 0; i < sd->desc.nctrls; i++)
sensor_settings[i] = vv6410_ctrl[i].qctrl.default_value;
sd->sensor_priv = sensor_settings;
return 0;
}
return -ENODEV;
}
static int vv6410_init(struct sd *sd)
{
int err = 0, i;
s32 *sensor_settings = sd->sensor_priv;
for (i = 0; i < ARRAY_SIZE(stv_bridge_init); i++) {
if (stv_bridge_init[i].data == NULL) {
err = stv06xx_write_bridge(sd,
stv_bridge_init[i].start,
stv_bridge_init[i].len);
} else {
int j;
for (j = 0; j < stv_bridge_init[i].len; j++)
err = stv06xx_write_bridge(sd,
stv_bridge_init[i].start + j,
stv_bridge_init[i].data[j]);
}
}
if (err < 0)
return err;
err = stv06xx_write_sensor_bytes(sd, (u8 *) vv6410_sensor_init,
ARRAY_SIZE(vv6410_sensor_init));
if (err < 0)
return err;
err = vv6410_set_exposure(&sd->gspca_dev,
sensor_settings[EXPOSURE_IDX]);
if (err < 0)
return err;
err = vv6410_set_analog_gain(&sd->gspca_dev,
sensor_settings[GAIN_IDX]);
return (err < 0) ? err : 0;
}
static void vv6410_disconnect(struct sd *sd)
{
sd->sensor = NULL;
kfree(sd->sensor_priv);
}
static int vv6410_start(struct sd *sd)
{
int err;
struct cam *cam = &sd->gspca_dev.cam;
u32 priv = cam->cam_mode[sd->gspca_dev.curr_mode].priv;
if (priv & VV6410_CROP_TO_QVGA) {
PDEBUG(D_CONF, "Cropping to QVGA");
stv06xx_write_sensor(sd, VV6410_XENDH, 320 - 1);
stv06xx_write_sensor(sd, VV6410_YENDH, 240 - 1);
} else {
stv06xx_write_sensor(sd, VV6410_XENDH, 360 - 1);
stv06xx_write_sensor(sd, VV6410_YENDH, 294 - 1);
}
if (priv & VV6410_SUBSAMPLE) {
PDEBUG(D_CONF, "Enabling subsampling");
stv06xx_write_bridge(sd, STV_Y_CTRL, 0x02);
stv06xx_write_bridge(sd, STV_X_CTRL, 0x06);
stv06xx_write_bridge(sd, STV_SCAN_RATE, 0x10);
} else {
stv06xx_write_bridge(sd, STV_Y_CTRL, 0x01);
stv06xx_write_bridge(sd, STV_X_CTRL, 0x0a);
stv06xx_write_bridge(sd, STV_SCAN_RATE, 0x20);
}
err = stv06xx_write_bridge(sd, STV_LED_CTRL, LED_ON);
if (err < 0)
return err;
err = stv06xx_write_sensor(sd, VV6410_SETUP0, 0);
if (err < 0)
return err;
PDEBUG(D_STREAM, "Starting stream");
return 0;
}
static int vv6410_stop(struct sd *sd)
{
int err;
err = stv06xx_write_bridge(sd, STV_LED_CTRL, LED_OFF);
if (err < 0)
return err;
err = stv06xx_write_sensor(sd, VV6410_SETUP0, VV6410_LOW_POWER_MODE);
if (err < 0)
return err;
PDEBUG(D_STREAM, "Halting stream");
return (err < 0) ? err : 0;
}
static int vv6410_dump(struct sd *sd)
{
u8 i;
int err = 0;
info("Dumping all vv6410 sensor registers");
for (i = 0; i < 0xff && !err; i++) {
u16 data;
err = stv06xx_read_sensor(sd, i, &data);
info("Register 0x%x contained 0x%x", i, data);
}
return (err < 0) ? err : 0;
}
static int vv6410_get_hflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[HFLIP_IDX];
PDEBUG(D_V4L2, "Read horizontal flip %d", *val);
return 0;
}
static int vv6410_set_hflip(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u16 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
sensor_settings[HFLIP_IDX] = val;
err = stv06xx_read_sensor(sd, VV6410_DATAFORMAT, &i2c_data);
if (err < 0)
return err;
if (val)
i2c_data |= VV6410_HFLIP;
else
i2c_data &= ~VV6410_HFLIP;
PDEBUG(D_V4L2, "Set horizontal flip to %d", val);
err = stv06xx_write_sensor(sd, VV6410_DATAFORMAT, i2c_data);
return (err < 0) ? err : 0;
}
static int vv6410_get_vflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[VFLIP_IDX];
PDEBUG(D_V4L2, "Read vertical flip %d", *val);
return 0;
}
static int vv6410_set_vflip(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u16 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
sensor_settings[VFLIP_IDX] = val;
err = stv06xx_read_sensor(sd, VV6410_DATAFORMAT, &i2c_data);
if (err < 0)
return err;
if (val)
i2c_data |= VV6410_VFLIP;
else
i2c_data &= ~VV6410_VFLIP;
PDEBUG(D_V4L2, "Set vertical flip to %d", val);
err = stv06xx_write_sensor(sd, VV6410_DATAFORMAT, i2c_data);
return (err < 0) ? err : 0;
}
static int vv6410_get_analog_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[GAIN_IDX];
PDEBUG(D_V4L2, "Read analog gain %d", *val);
return 0;
}
static int vv6410_set_analog_gain(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
sensor_settings[GAIN_IDX] = val;
PDEBUG(D_V4L2, "Set analog gain to %d", val);
err = stv06xx_write_sensor(sd, VV6410_ANALOGGAIN, 0xf0 | (val & 0xf));
return (err < 0) ? err : 0;
}
static int vv6410_get_exposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[EXPOSURE_IDX];
PDEBUG(D_V4L2, "Read exposure %d", *val);
return 0;
}
static int vv6410_set_exposure(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
unsigned int fine, coarse;
sensor_settings[EXPOSURE_IDX] = val;
val = (val * val >> 14) + val / 4;
fine = val % VV6410_CIF_LINELENGTH;
coarse = min(512, val / VV6410_CIF_LINELENGTH);
PDEBUG(D_V4L2, "Set coarse exposure to %d, fine expsure to %d",
coarse, fine);
err = stv06xx_write_sensor(sd, VV6410_FINEH, fine >> 8);
if (err < 0)
goto out;
err = stv06xx_write_sensor(sd, VV6410_FINEL, fine & 0xff);
if (err < 0)
goto out;
err = stv06xx_write_sensor(sd, VV6410_COARSEH, coarse >> 8);
if (err < 0)
goto out;
err = stv06xx_write_sensor(sd, VV6410_COARSEL, coarse & 0xff);
out:
return err;
}
