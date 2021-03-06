int s5k4aa_probe(struct sd *sd)
{
u8 prod_id[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const u8 expected_prod_id[6] = {0x00, 0x10, 0x00, 0x4b, 0x33, 0x75};
int i, err = 0;
s32 *sensor_settings;
if (force_sensor) {
if (force_sensor == S5K4AA_SENSOR) {
pr_info("Forcing a %s sensor\n", s5k4aa.name);
goto sensor_found;
}
return -ENODEV;
}
PDEBUG(D_PROBE, "Probing for a s5k4aa sensor");
for (i = 0; i < ARRAY_SIZE(preinit_s5k4aa) && !err; i++) {
u8 data[2] = {0x00, 0x00};
switch (preinit_s5k4aa[i][0]) {
case BRIDGE:
err = m5602_write_bridge(sd,
preinit_s5k4aa[i][1],
preinit_s5k4aa[i][2]);
break;
case SENSOR:
data[0] = preinit_s5k4aa[i][2];
err = m5602_write_sensor(sd,
preinit_s5k4aa[i][1],
data, 1);
break;
case SENSOR_LONG:
data[0] = preinit_s5k4aa[i][2];
data[1] = preinit_s5k4aa[i][3];
err = m5602_write_sensor(sd,
preinit_s5k4aa[i][1],
data, 2);
break;
default:
pr_info("Invalid stream command, exiting init\n");
return -EINVAL;
}
}
if (m5602_read_sensor(sd, 0x00, prod_id, 2))
return -ENODEV;
if (m5602_read_sensor(sd, 0x02, prod_id+2, 2))
return -ENODEV;
if (m5602_read_sensor(sd, 0x04, prod_id+4, 2))
return -ENODEV;
if (memcmp(prod_id, expected_prod_id, sizeof(prod_id)))
return -ENODEV;
else
pr_info("Detected a s5k4aa sensor\n");
sensor_found:
sensor_settings = kmalloc(
ARRAY_SIZE(s5k4aa_ctrls) * sizeof(s32), GFP_KERNEL);
if (!sensor_settings)
return -ENOMEM;
sd->gspca_dev.cam.cam_mode = s5k4aa_modes;
sd->gspca_dev.cam.nmodes = ARRAY_SIZE(s5k4aa_modes);
sd->desc->ctrls = s5k4aa_ctrls;
sd->desc->nctrls = ARRAY_SIZE(s5k4aa_ctrls);
for (i = 0; i < ARRAY_SIZE(s5k4aa_ctrls); i++)
sensor_settings[i] = s5k4aa_ctrls[i].qctrl.default_value;
sd->sensor_priv = sensor_settings;
return 0;
}
int s5k4aa_start(struct sd *sd)
{
int i, err = 0;
u8 data[2];
struct cam *cam = &sd->gspca_dev.cam;
s32 *sensor_settings = sd->sensor_priv;
switch (cam->cam_mode[sd->gspca_dev.curr_mode].width) {
case 1280:
PDEBUG(D_V4L2, "Configuring camera for SXGA mode");
for (i = 0; i < ARRAY_SIZE(SXGA_s5k4aa); i++) {
switch (SXGA_s5k4aa[i][0]) {
case BRIDGE:
err = m5602_write_bridge(sd,
SXGA_s5k4aa[i][1],
SXGA_s5k4aa[i][2]);
break;
case SENSOR:
data[0] = SXGA_s5k4aa[i][2];
err = m5602_write_sensor(sd,
SXGA_s5k4aa[i][1],
data, 1);
break;
case SENSOR_LONG:
data[0] = SXGA_s5k4aa[i][2];
data[1] = SXGA_s5k4aa[i][3];
err = m5602_write_sensor(sd,
SXGA_s5k4aa[i][1],
data, 2);
break;
default:
pr_err("Invalid stream command, exiting init\n");
return -EINVAL;
}
}
err = s5k4aa_set_noise(&sd->gspca_dev, 0);
if (err < 0)
return err;
break;
case 640:
PDEBUG(D_V4L2, "Configuring camera for VGA mode");
for (i = 0; i < ARRAY_SIZE(VGA_s5k4aa); i++) {
switch (VGA_s5k4aa[i][0]) {
case BRIDGE:
err = m5602_write_bridge(sd,
VGA_s5k4aa[i][1],
VGA_s5k4aa[i][2]);
break;
case SENSOR:
data[0] = VGA_s5k4aa[i][2];
err = m5602_write_sensor(sd,
VGA_s5k4aa[i][1],
data, 1);
break;
case SENSOR_LONG:
data[0] = VGA_s5k4aa[i][2];
data[1] = VGA_s5k4aa[i][3];
err = m5602_write_sensor(sd,
VGA_s5k4aa[i][1],
data, 2);
break;
default:
pr_err("Invalid stream command, exiting init\n");
return -EINVAL;
}
}
err = s5k4aa_set_noise(&sd->gspca_dev, 1);
if (err < 0)
return err;
break;
}
if (err < 0)
return err;
err = s5k4aa_set_exposure(&sd->gspca_dev,
sensor_settings[EXPOSURE_IDX]);
if (err < 0)
return err;
err = s5k4aa_set_gain(&sd->gspca_dev, sensor_settings[GAIN_IDX]);
if (err < 0)
return err;
err = s5k4aa_set_brightness(&sd->gspca_dev,
sensor_settings[BRIGHTNESS_IDX]);
if (err < 0)
return err;
err = s5k4aa_set_noise(&sd->gspca_dev, sensor_settings[NOISE_SUPP_IDX]);
if (err < 0)
return err;
err = s5k4aa_set_vflip(&sd->gspca_dev, sensor_settings[VFLIP_IDX]);
if (err < 0)
return err;
return s5k4aa_set_hflip(&sd->gspca_dev, sensor_settings[HFLIP_IDX]);
}
int s5k4aa_init(struct sd *sd)
{
int i, err = 0;
for (i = 0; i < ARRAY_SIZE(init_s5k4aa) && !err; i++) {
u8 data[2] = {0x00, 0x00};
switch (init_s5k4aa[i][0]) {
case BRIDGE:
err = m5602_write_bridge(sd,
init_s5k4aa[i][1],
init_s5k4aa[i][2]);
break;
case SENSOR:
data[0] = init_s5k4aa[i][2];
err = m5602_write_sensor(sd,
init_s5k4aa[i][1], data, 1);
break;
case SENSOR_LONG:
data[0] = init_s5k4aa[i][2];
data[1] = init_s5k4aa[i][3];
err = m5602_write_sensor(sd,
init_s5k4aa[i][1], data, 2);
break;
default:
pr_info("Invalid stream command, exiting init\n");
return -EINVAL;
}
}
if (dump_sensor)
s5k4aa_dump_registers(sd);
return err;
}
static int s5k4aa_get_exposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[EXPOSURE_IDX];
PDEBUG(D_V4L2, "Read exposure %d", *val);
return 0;
}
static int s5k4aa_set_exposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
u8 data = S5K4AA_PAGE_MAP_2;
int err;
sensor_settings[EXPOSURE_IDX] = val;
PDEBUG(D_V4L2, "Set exposure to %d", val);
err = m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &data, 1);
if (err < 0)
return err;
data = (val >> 8) & 0xff;
err = m5602_write_sensor(sd, S5K4AA_EXPOSURE_HI, &data, 1);
if (err < 0)
return err;
data = val & 0xff;
err = m5602_write_sensor(sd, S5K4AA_EXPOSURE_LO, &data, 1);
return err;
}
static int s5k4aa_get_vflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[VFLIP_IDX];
PDEBUG(D_V4L2, "Read vertical flip %d", *val);
return 0;
}
static int s5k4aa_set_vflip(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
u8 data = S5K4AA_PAGE_MAP_2;
int err;
sensor_settings[VFLIP_IDX] = val;
PDEBUG(D_V4L2, "Set vertical flip to %d", val);
err = m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &data, 1);
if (err < 0)
return err;
err = m5602_read_sensor(sd, S5K4AA_READ_MODE, &data, 1);
if (err < 0)
return err;
if (dmi_check_system(s5k4aa_vflip_dmi_table))
val = !val;
data = ((data & ~S5K4AA_RM_V_FLIP) | ((val & 0x01) << 7));
err = m5602_write_sensor(sd, S5K4AA_READ_MODE, &data, 1);
if (err < 0)
return err;
err = m5602_read_sensor(sd, S5K4AA_ROWSTART_LO, &data, 1);
if (err < 0)
return err;
if (val)
data &= 0xfe;
else
data |= 0x01;
err = m5602_write_sensor(sd, S5K4AA_ROWSTART_LO, &data, 1);
return err;
}
static int s5k4aa_get_hflip(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[HFLIP_IDX];
PDEBUG(D_V4L2, "Read horizontal flip %d", *val);
return 0;
}
static int s5k4aa_set_hflip(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
u8 data = S5K4AA_PAGE_MAP_2;
int err;
sensor_settings[HFLIP_IDX] = val;
PDEBUG(D_V4L2, "Set horizontal flip to %d", val);
err = m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &data, 1);
if (err < 0)
return err;
err = m5602_read_sensor(sd, S5K4AA_READ_MODE, &data, 1);
if (err < 0)
return err;
if (dmi_check_system(s5k4aa_vflip_dmi_table))
val = !val;
data = ((data & ~S5K4AA_RM_H_FLIP) | ((val & 0x01) << 6));
err = m5602_write_sensor(sd, S5K4AA_READ_MODE, &data, 1);
if (err < 0)
return err;
err = m5602_read_sensor(sd, S5K4AA_COLSTART_LO, &data, 1);
if (err < 0)
return err;
if (val)
data &= 0xfe;
else
data |= 0x01;
err = m5602_write_sensor(sd, S5K4AA_COLSTART_LO, &data, 1);
return err;
}
static int s5k4aa_get_gain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[GAIN_IDX];
PDEBUG(D_V4L2, "Read gain %d", *val);
return 0;
}
static int s5k4aa_set_gain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
u8 data = S5K4AA_PAGE_MAP_2;
int err;
sensor_settings[GAIN_IDX] = val;
PDEBUG(D_V4L2, "Set gain to %d", val);
err = m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &data, 1);
if (err < 0)
return err;
data = val & 0xff;
err = m5602_write_sensor(sd, S5K4AA_GAIN, &data, 1);
return err;
}
static int s5k4aa_get_brightness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[BRIGHTNESS_IDX];
PDEBUG(D_V4L2, "Read brightness %d", *val);
return 0;
}
static int s5k4aa_set_brightness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
u8 data = S5K4AA_PAGE_MAP_2;
int err;
sensor_settings[BRIGHTNESS_IDX] = val;
PDEBUG(D_V4L2, "Set brightness to %d", val);
err = m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &data, 1);
if (err < 0)
return err;
data = val & 0xff;
return m5602_write_sensor(sd, S5K4AA_BRIGHTNESS, &data, 1);
}
static int s5k4aa_get_noise(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
*val = sensor_settings[NOISE_SUPP_IDX];
PDEBUG(D_V4L2, "Read noise %d", *val);
return 0;
}
static int s5k4aa_set_noise(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 *sensor_settings = sd->sensor_priv;
u8 data = S5K4AA_PAGE_MAP_2;
int err;
sensor_settings[NOISE_SUPP_IDX] = val;
PDEBUG(D_V4L2, "Set noise to %d", val);
err = m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &data, 1);
if (err < 0)
return err;
data = val & 0x01;
return m5602_write_sensor(sd, S5K4AA_NOISE_SUPP, &data, 1);
}
void s5k4aa_disconnect(struct sd *sd)
{
sd->sensor = NULL;
kfree(sd->sensor_priv);
}
static void s5k4aa_dump_registers(struct sd *sd)
{
int address;
u8 page, old_page;
m5602_read_sensor(sd, S5K4AA_PAGE_MAP, &old_page, 1);
for (page = 0; page < 16; page++) {
m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &page, 1);
pr_info("Dumping the s5k4aa register state for page 0x%x\n",
page);
for (address = 0; address <= 0xff; address++) {
u8 value = 0;
m5602_read_sensor(sd, address, &value, 1);
pr_info("register 0x%x contains 0x%x\n",
address, value);
}
}
pr_info("s5k4aa register state dump complete\n");
for (page = 0; page < 16; page++) {
m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &page, 1);
pr_info("Probing for which registers that are read/write for page 0x%x\n",
page);
for (address = 0; address <= 0xff; address++) {
u8 old_value, ctrl_value, test_value = 0xff;
m5602_read_sensor(sd, address, &old_value, 1);
m5602_write_sensor(sd, address, &test_value, 1);
m5602_read_sensor(sd, address, &ctrl_value, 1);
if (ctrl_value == test_value)
pr_info("register 0x%x is writeable\n",
address);
else
pr_info("register 0x%x is read only\n",
address);
m5602_write_sensor(sd, address, &old_value, 1);
}
}
pr_info("Read/write register probing complete\n");
m5602_write_sensor(sd, S5K4AA_PAGE_MAP, &old_page, 1);
}
