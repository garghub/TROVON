int ov9650_probe(struct sd *sd)
{
int err = 0;
u8 prod_id = 0, ver_id = 0, i;
s32 *sensor_settings;
if (force_sensor) {
if (force_sensor == OV9650_SENSOR) {
info("Forcing an %s sensor", ov9650.name);
goto sensor_found;
}
return -ENODEV;
}
PDEBUG(D_PROBE, "Probing for an ov9650 sensor");
for (i = 0; i < ARRAY_SIZE(preinit_ov9650) && !err; i++) {
u8 data = preinit_ov9650[i][2];
if (preinit_ov9650[i][0] == SENSOR)
err = m5602_write_sensor(sd,
preinit_ov9650[i][1], &data, 1);
else
err = m5602_write_bridge(sd,
preinit_ov9650[i][1], data);
}
if (err < 0)
return err;
if (m5602_read_sensor(sd, OV9650_PID, &prod_id, 1))
return -ENODEV;
if (m5602_read_sensor(sd, OV9650_VER, &ver_id, 1))
return -ENODEV;
if ((prod_id == 0x96) && (ver_id == 0x52)) {
info("Detected an ov9650 sensor");
goto sensor_found;
}
return -ENODEV;
sensor_found:
sensor_settings = kmalloc(
ARRAY_SIZE(ov9650_ctrls) * sizeof(s32), GFP_KERNEL);
if (!sensor_settings)
return -ENOMEM;
sd->gspca_dev.cam.cam_mode = ov9650_modes;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(ov9650_modes);
sd->desc->ctrls = ov9650_ctrls;
sd->desc->nctrls = ARRAY_SIZE(ov9650_ctrls);
for (i = 0; i < ARRAY_SIZE(ov9650_ctrls); i++)
sensor_settings[i] = ov9650_ctrls[i].qctrl.default_value;
sd->sensor_priv = sensor_settings;
return 0;
}
int ov9650_init(struct sd *sd)
{
int i, err = 0;
u8 data;
s32 *sensor_settings = sd->sensor_priv;
if (dump_sensor)
ov9650_dump_registers(sd);
for (i = 0; i < ARRAY_SIZE(init_ov9650) && !err; i++) {
data = init_ov9650[i][2];
if (init_ov9650[i][0] == SENSOR)
err = m5602_write_sensor(sd, init_ov9650[i][1],
&data, 1);
else
err = m5602_write_bridge(sd, init_ov9650[i][1], data);
}
err = ov9650_set_exposure(&sd->gspca_dev,
sensor_settings[EXPOSURE_IDX]);
if (err < 0)
return err;
err = ov9650_set_gain(&sd->gspca_dev, sensor_settings[GAIN_IDX]);
if (err < 0)
return err;
err = ov9650_set_red_balance(&sd->gspca_dev,
sensor_settings[RED_BALANCE_IDX]);
if (err < 0)
return err;
err = ov9650_set_blue_balance(&sd->gspca_dev,
sensor_settings[BLUE_BALANCE_IDX]);
if (err < 0)
return err;
err = ov9650_set_hflip(&sd->gspca_dev, sensor_settings[HFLIP_IDX]);
if (err < 0)
return err;
err = ov9650_set_vflip(&sd->gspca_dev, sensor_settings[VFLIP_IDX]);
if (err < 0)
return err;
err = ov9650_set_auto_exposure(&sd->gspca_dev,
sensor_settings[AUTO_EXPOSURE_IDX]);
if (err < 0)
return err;
err = ov9650_set_auto_white_balance(&sd->gspca_dev,
sensor_settings[AUTO_WHITE_BALANCE_IDX]);
if (err < 0)
return err;
err = ov9650_set_auto_gain(&sd->gspca_dev,
sensor_settings[AUTO_GAIN_CTRL_IDX]);
return err;
}
int ov9650_start(struct sd *sd)
{
u8 data;
int i, err = 0;
struct cam *cam = &sd->gspca_dev.cam;
s32 *sensor_settings = sd->sensor_priv;
int width = cam->cam_mode[sd->gspca_dev.curr_mode].width;
int height = cam->cam_mode[sd->gspca_dev.curr_mode].height;
int ver_offs = cam->cam_mode[sd->gspca_dev.curr_mode].priv;
int hor_offs = OV9650_LEFT_OFFSET;
if ((!dmi_check_system(ov9650_flip_dmi_table) &&
sensor_settings[VFLIP_IDX]) ||
(dmi_check_system(ov9650_flip_dmi_table) &&
!sensor_settings[VFLIP_IDX]))
ver_offs--;
if (width <= 320)
hor_offs /= 2;
for (i = 0; i < ARRAY_SIZE(res_init_ov9650) && !err; i++) {
if (res_init_ov9650[i][0] == BRIDGE)
err = m5602_write_bridge(sd, res_init_ov9650[i][1],
res_init_ov9650[i][2]);
else if (res_init_ov9650[i][0] == SENSOR) {
data = res_init_ov9650[i][2];
err = m5602_write_sensor(sd,
res_init_ov9650[i][1], &data, 1);
}
}
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_VSYNC_PARA,
((ver_offs >> 8) & 0xff));
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_VSYNC_PARA, (ver_offs & 0xff));
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_VSYNC_PARA, 0);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_VSYNC_PARA, (height >> 8) & 0xff);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_VSYNC_PARA, (height & 0xff));
if (err < 0)
return err;
for (i = 0; i < 2 && !err; i++)
err = m5602_write_bridge(sd, M5602_XB_VSYNC_PARA, 0);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_SIG_INI, 0);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_SIG_INI, 2);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_HSYNC_PARA,
(hor_offs >> 8) & 0xff);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_HSYNC_PARA, hor_offs & 0xff);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_HSYNC_PARA,
((width + hor_offs) >> 8) & 0xff);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_HSYNC_PARA,
((width + hor_offs) & 0xff));
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_SIG_INI, 0);
if (err < 0)
return err;
switch (width) {
case 640:
PDEBUG(D_V4L2, "Configuring camera for VGA mode");
data = OV9650_VGA_SELECT | OV9650_RGB_SELECT |
OV9650_RAW_RGB_SELECT;
err = m5602_write_sensor(sd, OV9650_COM7, &data, 1);
break;
case 352:
PDEBUG(D_V4L2, "Configuring camera for CIF mode");
data = OV9650_CIF_SELECT | OV9650_RGB_SELECT |
OV9650_RAW_RGB_SELECT;
err = m5602_write_sensor(sd, OV9650_COM7, &data, 1);
break;
case 320:
PDEBUG(D_V4L2, "Configuring camera for QVGA mode");
data = OV9650_QVGA_SELECT | OV9650_RGB_SELECT |
OV9650_RAW_RGB_SELECT;
err = m5602_write_sensor(sd, OV9650_COM7, &data, 1);
break;
case 176:
PDEBUG(D_V4L2, "Configuring camera for QCIF mode");
data = OV9650_QCIF_SELECT | OV9650_RGB_SELECT |
OV9650_RAW_RGB_SELECT;
err = m5602_write_sensor(sd, OV9650_COM7, &data, 1);
break;
}
return err;
}
int ov9650_stop(struct sd *sd)
{
u8 data = OV9650_SOFT_SLEEP | OV9650_OUTPUT_DRIVE_2X;
return m5602_write_sensor(sd, OV9650_COM2, &data, 1);
}
void ov9650_disconnect(struct sd *sd)
{
ov9650_stop(sd);
sd->sensor = NULL;
kfree(sd->sensor_priv);
}
static int ov9650_get_exposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[EXPOSURE_IDX];
PDEBUG(D_V4L2, "Read exposure %d", *val);
return 0;
}
static int ov9650_set_exposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
u8 i2c_data;
int err;
PDEBUG(D_V4L2, "Set exposure to %d", val);
sensor_settings[EXPOSURE_IDX] = val;
i2c_data = (val >> 10) & 0x3f;
err = m5602_write_sensor(sd, OV9650_AECHM,
&i2c_data, 1);
if (err < 0)
return err;
i2c_data = (val >> 2) & 0xff;
err = m5602_write_sensor(sd, OV9650_AECH,
&i2c_data, 1);
if (err < 0)
return err;
i2c_data = val & 0x03;
err = m5602_write_sensor(sd, OV9650_COM1, &i2c_data, 1);
return err;
}
static int ov9650_get_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[GAIN_IDX];
PDEBUG(D_V4L2, "Read gain %d", *val);
return 0;
}
static int ov9650_set_gain(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Setting gain to %d", val);
sensor_settings[GAIN_IDX] = val;
err = m5602_read_sensor(sd, OV9650_VREF, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = ((val & 0x0300) >> 2) |
(i2c_data & 0x3f);
err = m5602_write_sensor(sd, OV9650_VREF, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = val & 0xff;
err = m5602_write_sensor(sd, OV9650_GAIN, &i2c_data, 1);
return err;
}
static int ov9650_get_red_balance(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[RED_BALANCE_IDX];
PDEBUG(D_V4L2, "Read red gain %d", *val);
return 0;
}
static int ov9650_set_red_balance(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set red gain to %d", val);
sensor_settings[RED_BALANCE_IDX] = val;
i2c_data = val & 0xff;
err = m5602_write_sensor(sd, OV9650_RED, &i2c_data, 1);
return err;
}
static int ov9650_get_blue_balance(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[BLUE_BALANCE_IDX];
PDEBUG(D_V4L2, "Read blue gain %d", *val);
return 0;
}
static int ov9650_set_blue_balance(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set blue gain to %d", val);
sensor_settings[BLUE_BALANCE_IDX] = val;
i2c_data = val & 0xff;
err = m5602_write_sensor(sd, OV9650_BLUE, &i2c_data, 1);
return err;
}
static int ov9650_get_hflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[HFLIP_IDX];
PDEBUG(D_V4L2, "Read horizontal flip %d", *val);
return 0;
}
static int ov9650_set_hflip(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set horizontal flip to %d", val);
sensor_settings[HFLIP_IDX] = val;
if (!dmi_check_system(ov9650_flip_dmi_table))
i2c_data = ((val & 0x01) << 5) |
(sensor_settings[VFLIP_IDX] << 4);
else
i2c_data = ((val & 0x01) << 5) |
(!sensor_settings[VFLIP_IDX] << 4);
err = m5602_write_sensor(sd, OV9650_MVFP, &i2c_data, 1);
return err;
}
static int ov9650_get_vflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[VFLIP_IDX];
PDEBUG(D_V4L2, "Read vertical flip %d", *val);
return 0;
}
static int ov9650_set_vflip(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set vertical flip to %d", val);
sensor_settings[VFLIP_IDX] = val;
if (dmi_check_system(ov9650_flip_dmi_table))
val = !val;
i2c_data = ((val & 0x01) << 4) | (sensor_settings[VFLIP_IDX] << 5);
err = m5602_write_sensor(sd, OV9650_MVFP, &i2c_data, 1);
if (err < 0)
return err;
if (gspca_dev->streaming)
err = ov9650_start(sd);
return err;
}
static int ov9650_get_auto_exposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[AUTO_EXPOSURE_IDX];
PDEBUG(D_V4L2, "Read auto exposure control %d", *val);
return 0;
}
static int ov9650_set_auto_exposure(struct gspca_dev *gspca_dev,
__s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set auto exposure control to %d", val);
sensor_settings[AUTO_EXPOSURE_IDX] = val;
err = m5602_read_sensor(sd, OV9650_COM8, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = ((i2c_data & 0xfe) | ((val & 0x01) << 0));
return m5602_write_sensor(sd, OV9650_COM8, &i2c_data, 1);
}
static int ov9650_get_auto_white_balance(struct gspca_dev *gspca_dev,
__s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[AUTO_WHITE_BALANCE_IDX];
return 0;
}
static int ov9650_set_auto_white_balance(struct gspca_dev *gspca_dev,
__s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set auto white balance to %d", val);
sensor_settings[AUTO_WHITE_BALANCE_IDX] = val;
err = m5602_read_sensor(sd, OV9650_COM8, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = ((i2c_data & 0xfd) | ((val & 0x01) << 1));
err = m5602_write_sensor(sd, OV9650_COM8, &i2c_data, 1);
return err;
}
static int ov9650_get_auto_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[AUTO_GAIN_CTRL_IDX];
PDEBUG(D_V4L2, "Read auto gain control %d", *val);
return 0;
}
static int ov9650_set_auto_gain(struct gspca_dev *gspca_dev, __s32 val)
{
int err;
u8 i2c_data;
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
PDEBUG(D_V4L2, "Set auto gain control to %d", val);
sensor_settings[AUTO_GAIN_CTRL_IDX] = val;
err = m5602_read_sensor(sd, OV9650_COM8, &i2c_data, 1);
if (err < 0)
return err;
i2c_data = ((i2c_data & 0xfb) | ((val & 0x01) << 2));
return m5602_write_sensor(sd, OV9650_COM8, &i2c_data, 1);
}
static void ov9650_dump_registers(struct sd *sd)
{
int address;
info("Dumping the ov9650 register state");
for (address = 0; address < 0xa9; address++) {
u8 value;
m5602_read_sensor(sd, address, &value, 1);
info("register 0x%x contains 0x%x",
address, value);
}
info("ov9650 register state dump complete");
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
