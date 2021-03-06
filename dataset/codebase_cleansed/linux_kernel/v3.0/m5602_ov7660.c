int ov7660_probe(struct sd *sd)
{
int err = 0, i;
u8 prod_id = 0, ver_id = 0;
s32 *sensor_settings;
if (force_sensor) {
if (force_sensor == OV7660_SENSOR) {
info("Forcing an %s sensor", ov7660.name);
goto sensor_found;
}
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(preinit_ov7660) && !err; i++) {
u8 data[2];
if (preinit_ov7660[i][0] == BRIDGE) {
err = m5602_write_bridge(sd,
preinit_ov7660[i][1],
preinit_ov7660[i][2]);
} else {
data[0] = preinit_ov7660[i][2];
err = m5602_write_sensor(sd,
preinit_ov7660[i][1], data, 1);
}
}
if (err < 0)
return err;
if (m5602_read_sensor(sd, OV7660_PID, &prod_id, 1))
return -ENODEV;
if (m5602_read_sensor(sd, OV7660_VER, &ver_id, 1))
return -ENODEV;
info("Sensor reported 0x%x%x", prod_id, ver_id);
if ((prod_id == 0x76) && (ver_id == 0x60)) {
info("Detected a ov7660 sensor");
goto sensor_found;
}
return -ENODEV;
sensor_found:
sensor_settings = kmalloc(
ARRAY_SIZE(ov7660_ctrls) * sizeof(s32), GFP_KERNEL);
if (!sensor_settings)
return -ENOMEM;
sd->gspca_dev.cam.cam_mode = ov7660_modes;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(ov7660_modes);
sd->desc->ctrls = ov7660_ctrls;
sd->desc->nctrls = ARRAY_SIZE(ov7660_ctrls);
for (i = 0; i < ARRAY_SIZE(ov7660_ctrls); i++)
sensor_settings[i] = ov7660_ctrls[i].qctrl.default_value;
sd->sensor_priv = sensor_settings;
return 0;
}
int ov7660_init(struct sd *sd)
{
int i, err = 0;
s32 *sensor_settings = sd->sensor_priv;
for (i = 0; i < ARRAY_SIZE(init_ov7660); i++) {
u8 data[2];
if (init_ov7660[i][0] == BRIDGE) {
err = m5602_write_bridge(sd,
init_ov7660[i][1],
init_ov7660[i][2]);
} else {
data[0] = init_ov7660[i][2];
err = m5602_write_sensor(sd,
init_ov7660[i][1], data, 1);
}
}
if (dump_sensor)
ov7660_dump_registers(sd);
err = ov7660_set_gain(&sd->gspca_dev, sensor_settings[GAIN_IDX]);
if (err < 0)
return err;
err = ov7660_set_auto_white_balance(&sd->gspca_dev,
sensor_settings[AUTO_WHITE_BALANCE_IDX]);
if (err < 0)
return err;
err = ov7660_set_auto_gain(&sd->gspca_dev,
sensor_settings[AUTO_GAIN_CTRL_IDX]);
if (err < 0)
return err;
err = ov7660_set_auto_exposure(&sd->gspca_dev,
sensor_settings[AUTO_EXPOSURE_IDX]);
if (err < 0)
return err;
err = ov7660_set_hflip(&sd->gspca_dev,
sensor_settings[HFLIP_IDX]);
if (err < 0)
return err;
err = ov7660_set_vflip(&sd->gspca_dev,
sensor_settings[VFLIP_IDX]);
return err;
}
int ov7660_start(struct sd *sd)
{
return 0;
}
int ov7660_stop(struct sd *sd)
{
return 0;
}
void ov7660_disconnect(struct sd *sd)
{
ov7660_stop(sd);
sd->sensor = NULL;
kfree(sd->sensor_priv);
}
static int ov7660_get_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[GAIN_IDX];
PDEBUG(D_V4L2, "Read gain %d", *val);
return 0;
}
static int ov7660_set_gain(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Setting gain to %d", val);
sensor_settings[GAIN_IDX] = val;
err = m5602_write_sensor(sd, OV7660_GAIN, &i2c_data, 1);
return err;
}
static int ov7660_get_auto_white_balance(struct gspca_dev *gspca_dev,
__s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[AUTO_WHITE_BALANCE_IDX];
return 0;
}
static int ov7660_set_auto_white_balance(struct gspca_dev *gspca_dev,
__s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set auto white balance to %d", val);
sensor_settings[AUTO_WHITE_BALANCE_IDX] = val;
err = m5602_read_sensor(sd, OV7660_COM8, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = ((i2c_data & 0xfd) | ((val & 0x01) << 1));
err = m5602_write_sensor(sd, OV7660_COM8, &i2c_data, 1);
return err;
}
static int ov7660_get_auto_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[AUTO_GAIN_CTRL_IDX];
PDEBUG(D_V4L2, "Read auto gain control %d", *val);
return 0;
}
static int ov7660_set_auto_gain(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set auto gain control to %d", val);
sensor_settings[AUTO_GAIN_CTRL_IDX] = val;
err = m5602_read_sensor(sd, OV7660_COM8, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = ((i2c_data & 0xfb) | ((val & 0x01) << 2));
return m5602_write_sensor(sd, OV7660_COM8, &i2c_data, 1);
}
static int ov7660_get_auto_exposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[AUTO_EXPOSURE_IDX];
PDEBUG(D_V4L2, "Read auto exposure control %d", *val);
return 0;
}
static int ov7660_set_auto_exposure(struct gspca_dev *gspca_dev,
__s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set auto exposure control to %d", val);
sensor_settings[AUTO_EXPOSURE_IDX] = val;
err = m5602_read_sensor(sd, OV7660_COM8, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = ((i2c_data & 0xfe) | ((val & 0x01) << 0));
return m5602_write_sensor(sd, OV7660_COM8, &i2c_data, 1);
}
static int ov7660_get_hflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[HFLIP_IDX];
PDEBUG(D_V4L2, "Read horizontal flip %d", *val);
return 0;
}
static int ov7660_set_hflip(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set horizontal flip to %d", val);
sensor_settings[HFLIP_IDX] = val;
i2c_data = ((val & 0x01) << 5) |
(sensor_settings[VFLIP_IDX] << 4);
err = m5602_write_sensor(sd, OV7660_MVFP, &i2c_data, 1);
return err;
}
static int ov7660_get_vflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[VFLIP_IDX];
PDEBUG(D_V4L2, "Read vertical flip %d", *val);
return 0;
}
static int ov7660_set_vflip(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set vertical flip to %d", val);
sensor_settings[VFLIP_IDX] = val;
i2c_data = ((val & 0x01) << 4) | (sensor_settings[VFLIP_IDX] << 5);
err = m5602_write_sensor(sd, OV7660_MVFP, &i2c_data, 1);
if (err < 0)
return err;
if (gspca_dev->streaming)
err = ov7660_start(sd);
return err;
}
static void ov7660_dump_registers(struct sd *sd)
{
int address;
info("Dumping the ov7660 register state");
for (address = 0; address < 0xa9; address++) {
u8 value;
m5602_read_sensor(sd, address, &value, 1);
info("register 0x%x contains 0x%x",
address, value);
}
info("ov7660 register state dump complete");
info("Probing for which registers that are read/write");
for (address = 0; address < 0xff; address++) {
u8 old_value, ctrl_value;
u8 test_value[2] = {0xff, 0xff};
m5602_read_sensor(sd, address, &old_value, 1);
m5602_write_sensor(sd, address, test_value, 1);
m5602_read_sensor(sd, address, &ctrl_value, 1);
if (ctrl_value == test_value[0])
info("register 0x%x is writeable", address);
else
info("register 0x%x is read only", address);
m5602_write_sensor(sd, address, &old_value, 1);
}
}
