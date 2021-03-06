static int mr_write(struct gspca_dev *gspca_dev, int len)
{
int rc;
rc = usb_bulk_msg(gspca_dev->dev,
usb_sndbulkpipe(gspca_dev->dev, 4),
gspca_dev->usb_buf, len, NULL, 500);
if (rc < 0)
err("reg write [%02x] error %d",
gspca_dev->usb_buf[0], rc);
return rc;
}
static int mr_read(struct gspca_dev *gspca_dev, int len)
{
int rc;
rc = usb_bulk_msg(gspca_dev->dev,
usb_rcvbulkpipe(gspca_dev->dev, 3),
gspca_dev->usb_buf, len, NULL, 500);
if (rc < 0)
err("reg read [%02x] error %d",
gspca_dev->usb_buf[0], rc);
return rc;
}
static int sensor_write_reg(struct gspca_dev *gspca_dev, u8 reg, u8 flags,
const u8 *data, int len)
{
gspca_dev->usb_buf[0] = 0x1f;
gspca_dev->usb_buf[1] = flags;
gspca_dev->usb_buf[2] = reg;
memcpy(gspca_dev->usb_buf + 3, data, len);
return mr_write(gspca_dev, len + 3);
}
static int sensor_write_regs(struct gspca_dev *gspca_dev,
const struct sensor_w_data *data, int len)
{
int i, rc;
for (i = 0; i < len; i++) {
rc = sensor_write_reg(gspca_dev, data[i].reg, data[i].flags,
data[i].data, data[i].len);
if (rc < 0)
return rc;
}
return 0;
}
static int sensor_write1(struct gspca_dev *gspca_dev, u8 reg, u8 data)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 buf, confirm_reg;
int rc;
buf = data;
if (sd->cam_type == CAM_TYPE_CIF) {
rc = sensor_write_reg(gspca_dev, reg, 0x01, &buf, 1);
confirm_reg = sd->sensor_type ? 0x13 : 0x11;
} else {
rc = sensor_write_reg(gspca_dev, reg, 0x00, &buf, 1);
confirm_reg = 0x11;
}
if (rc < 0)
return rc;
buf = 0x01;
rc = sensor_write_reg(gspca_dev, confirm_reg, 0x00, &buf, 1);
if (rc < 0)
return rc;
return 0;
}
static int cam_get_response16(struct gspca_dev *gspca_dev, u8 reg, int verbose)
{
int err_code;
gspca_dev->usb_buf[0] = reg;
err_code = mr_write(gspca_dev, 1);
if (err_code < 0)
return err_code;
err_code = mr_read(gspca_dev, 16);
if (err_code < 0)
return err_code;
if (verbose)
PDEBUG(D_PROBE, "Register: %02x reads %02x%02x%02x", reg,
gspca_dev->usb_buf[0],
gspca_dev->usb_buf[1],
gspca_dev->usb_buf[2]);
return 0;
}
static int zero_the_pointer(struct gspca_dev *gspca_dev)
{
__u8 *data = gspca_dev->usb_buf;
int err_code;
u8 status = 0;
int tries = 0;
err_code = cam_get_response16(gspca_dev, 0x21, 0);
if (err_code < 0)
return err_code;
data[0] = 0x19;
data[1] = 0x51;
err_code = mr_write(gspca_dev, 2);
if (err_code < 0)
return err_code;
err_code = cam_get_response16(gspca_dev, 0x21, 0);
if (err_code < 0)
return err_code;
data[0] = 0x19;
data[1] = 0xba;
err_code = mr_write(gspca_dev, 2);
if (err_code < 0)
return err_code;
err_code = cam_get_response16(gspca_dev, 0x21, 0);
if (err_code < 0)
return err_code;
data[0] = 0x19;
data[1] = 0x00;
err_code = mr_write(gspca_dev, 2);
if (err_code < 0)
return err_code;
err_code = cam_get_response16(gspca_dev, 0x21, 0);
if (err_code < 0)
return err_code;
data[0] = 0x19;
data[1] = 0x00;
err_code = mr_write(gspca_dev, 2);
if (err_code < 0)
return err_code;
while (status != 0x0a && tries < 256) {
err_code = cam_get_response16(gspca_dev, 0x21, 0);
status = data[0];
tries++;
if (err_code < 0)
return err_code;
}
if (status != 0x0a)
PDEBUG(D_ERR, "status is %02x", status);
tries = 0;
while (tries < 4) {
data[0] = 0x19;
data[1] = 0x00;
err_code = mr_write(gspca_dev, 2);
if (err_code < 0)
return err_code;
err_code = cam_get_response16(gspca_dev, 0x21, 0);
status = data[0];
tries++;
if (err_code < 0)
return err_code;
}
data[0] = 0x19;
err_code = mr_write(gspca_dev, 1);
if (err_code < 0)
return err_code;
err_code = mr_read(gspca_dev, 16);
if (err_code < 0)
return err_code;
return 0;
}
static int stream_start(struct gspca_dev *gspca_dev)
{
gspca_dev->usb_buf[0] = 0x01;
gspca_dev->usb_buf[1] = 0x01;
return mr_write(gspca_dev, 2);
}
static void stream_stop(struct gspca_dev *gspca_dev)
{
gspca_dev->usb_buf[0] = 0x01;
gspca_dev->usb_buf[1] = 0x00;
if (mr_write(gspca_dev, 2) < 0)
PDEBUG(D_ERR, "Stream Stop failed");
}
static void lcd_stop(struct gspca_dev *gspca_dev)
{
gspca_dev->usb_buf[0] = 0x19;
gspca_dev->usb_buf[1] = 0x54;
if (mr_write(gspca_dev, 2) < 0)
PDEBUG(D_ERR, "LCD Stop failed");
}
static int isoc_enable(struct gspca_dev *gspca_dev)
{
gspca_dev->usb_buf[0] = 0x00;
gspca_dev->usb_buf[1] = 0x4d;
return mr_write(gspca_dev, 2);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
int gain_default = MR97310A_GAIN_DEFAULT;
int err_code;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
sd->do_lcd_stop = 0;
err_code = zero_the_pointer(gspca_dev);
if (err_code < 0)
return err_code;
err_code = stream_start(gspca_dev);
if (err_code < 0)
return err_code;
err_code = cam_get_response16(gspca_dev, 0x07, 1);
if (err_code < 0)
return err_code;
if (id->idProduct == 0x0110 || id->idProduct == 0x010e) {
sd->cam_type = CAM_TYPE_CIF;
cam->nmodes--;
switch (gspca_dev->usb_buf[0]) {
case 2:
sd->sensor_type = 0;
break;
case 3:
sd->sensor_type = 1;
break;
default:
err("Unknown CIF Sensor id : %02x",
gspca_dev->usb_buf[1]);
return -ENODEV;
}
PDEBUG(D_PROBE, "MR97310A CIF camera detected, sensor: %d",
sd->sensor_type);
} else {
sd->cam_type = CAM_TYPE_VGA;
sd->sensor_type = 1;
sd->do_lcd_stop = 0;
sd->adj_colors = 0;
if (gspca_dev->usb_buf[0] == 0x01) {
sd->sensor_type = 2;
} else if ((gspca_dev->usb_buf[0] != 0x03) &&
(gspca_dev->usb_buf[0] != 0x04)) {
err("Unknown VGA Sensor id Byte 0: %02x",
gspca_dev->usb_buf[0]);
err("Defaults assumed, may not work");
err("Please report this");
}
if ((gspca_dev->usb_buf[0] == 0x03) &&
(gspca_dev->usb_buf[1] == 0x50))
sd->adj_colors = 1;
if (gspca_dev->usb_buf[0] == 0x04) {
sd->do_lcd_stop = 1;
switch (gspca_dev->usb_buf[1]) {
case 0x50:
sd->sensor_type = 0;
PDEBUG(D_PROBE, "sensor_type corrected to 0");
break;
case 0x20:
break;
default:
err("Unknown VGA Sensor id Byte 1: %02x",
gspca_dev->usb_buf[1]);
err("Defaults assumed, may not work");
err("Please report this");
}
}
PDEBUG(D_PROBE, "MR97310A VGA camera detected, sensor: %d",
sd->sensor_type);
}
sd_stopN(gspca_dev);
if (force_sensor_type != -1) {
sd->sensor_type = !!force_sensor_type;
PDEBUG(D_PROBE, "Forcing sensor type to: %d",
sd->sensor_type);
}
if (sd->cam_type == CAM_TYPE_CIF) {
if (sd->sensor_type == 0)
gspca_dev->ctrl_dis = (1 << NORM_BRIGHTNESS_IDX) |
(1 << ARGUS_QC_BRIGHTNESS_IDX) |
(1 << CONTRAST_IDX) |
(1 << SAKAR_CS_GAIN_IDX);
else
gspca_dev->ctrl_dis = (1 << ARGUS_QC_BRIGHTNESS_IDX) |
(1 << CONTRAST_IDX) |
(1 << SAKAR_CS_GAIN_IDX) |
(1 << MIN_CLOCKDIV_IDX);
} else {
if (sd->sensor_type == 0)
gspca_dev->ctrl_dis = (1 << NORM_BRIGHTNESS_IDX) |
(1 << ARGUS_QC_BRIGHTNESS_IDX) |
(1 << EXPOSURE_IDX) |
(1 << GAIN_IDX) |
(1 << CONTRAST_IDX) |
(1 << SAKAR_CS_GAIN_IDX) |
(1 << MIN_CLOCKDIV_IDX);
else if (sd->sensor_type == 2) {
gspca_dev->ctrl_dis = (1 << NORM_BRIGHTNESS_IDX) |
(1 << ARGUS_QC_BRIGHTNESS_IDX) |
(1 << GAIN_IDX) |
(1 << MIN_CLOCKDIV_IDX);
gain_default = MR97310A_CS_GAIN_DEFAULT;
} else if (sd->do_lcd_stop)
gspca_dev->ctrl_dis = (1 << NORM_BRIGHTNESS_IDX) |
(1 << CONTRAST_IDX) |
(1 << SAKAR_CS_GAIN_IDX);
else
gspca_dev->ctrl_dis = (1 << ARGUS_QC_BRIGHTNESS_IDX) |
(1 << CONTRAST_IDX) |
(1 << SAKAR_CS_GAIN_IDX);
}
sd->brightness = MR97310A_BRIGHTNESS_DEFAULT;
sd->exposure = MR97310A_EXPOSURE_DEFAULT;
sd->gain = gain_default;
sd->contrast = MR97310A_CONTRAST_DEFAULT;
sd->min_clockdiv = MR97310A_MIN_CLOCKDIV_DEFAULT;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
return 0;
}
static int start_cif_cam(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 *data = gspca_dev->usb_buf;
int err_code;
static const __u8 startup_string[] = {
0x00,
0x0d,
0x01,
0x00,
0x00,
0x13,
0x00,
0x00,
0x00,
0x50,
0xc0
};
memcpy(data, startup_string, 11);
if (sd->sensor_type)
data[5] = 0xbb;
switch (gspca_dev->width) {
case 160:
data[9] |= 0x04;
case 320:
default:
data[3] = 0x28;
data[4] = 0x3c;
data[6] = 0x14;
data[8] = 0x1a + sd->sensor_type;
break;
case 176:
data[9] |= 0x04;
case 352:
data[3] = 0x2c;
data[4] = 0x48;
data[6] = 0x06;
data[8] = 0x06 - sd->sensor_type;
break;
}
err_code = mr_write(gspca_dev, 11);
if (err_code < 0)
return err_code;
if (!sd->sensor_type) {
static const struct sensor_w_data cif_sensor0_init_data[] = {
{0x02, 0x00, {0x03, 0x5a, 0xb5, 0x01,
0x0f, 0x14, 0x0f, 0x10}, 8},
{0x0c, 0x00, {0x04, 0x01, 0x01, 0x00, 0x1f}, 5},
{0x12, 0x00, {0x07}, 1},
{0x1f, 0x00, {0x06}, 1},
{0x27, 0x00, {0x04}, 1},
{0x29, 0x00, {0x0c}, 1},
{0x40, 0x00, {0x40, 0x00, 0x04}, 3},
{0x50, 0x00, {0x60}, 1},
{0x60, 0x00, {0x06}, 1},
{0x6b, 0x00, {0x85, 0x85, 0xc8, 0xc8, 0xc8, 0xc8}, 6},
{0x72, 0x00, {0x1e, 0x56}, 2},
{0x75, 0x00, {0x58, 0x40, 0xa2, 0x02, 0x31, 0x02,
0x31, 0x80, 0x00}, 9},
{0x11, 0x00, {0x01}, 1},
{0, 0, {0}, 0}
};
err_code = sensor_write_regs(gspca_dev, cif_sensor0_init_data,
ARRAY_SIZE(cif_sensor0_init_data));
} else {
static const struct sensor_w_data cif_sensor1_init_data[] = {
{0x02, 0x00, {0x10}, 1},
{0x05, 0x01, {0x22}, 1},
{0x06, 0x01, {0x00}, 1},
{0x09, 0x02, {0x0e}, 1},
{0x0a, 0x02, {0x05}, 1},
{0x0b, 0x02, {0x05}, 1},
{0x0c, 0x02, {0x0f}, 1},
{0x0d, 0x02, {0x07}, 1},
{0x0e, 0x02, {0x0c}, 1},
{0x0f, 0x00, {0x00}, 1},
{0x10, 0x00, {0x06}, 1},
{0x11, 0x00, {0x07}, 1},
{0x12, 0x00, {0x00}, 1},
{0x13, 0x00, {0x01}, 1},
{0, 0, {0}, 0}
};
gspca_dev->usb_buf[0] = 0x0a;
gspca_dev->usb_buf[1] = 0x00;
err_code = mr_write(gspca_dev, 2);
if (err_code < 0)
return err_code;
err_code = sensor_write_regs(gspca_dev, cif_sensor1_init_data,
ARRAY_SIZE(cif_sensor1_init_data));
}
return err_code;
}
static int start_vga_cam(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 *data = gspca_dev->usb_buf;
int err_code;
static const __u8 startup_string[] =
{0x00, 0x0d, 0x01, 0x00, 0x00, 0x2b, 0x00, 0x00,
0x00, 0x50, 0xc0};
memcpy(data, startup_string, 11);
if (!sd->sensor_type) {
data[5] = 0x00;
data[10] = 0x91;
}
if (sd->sensor_type == 2) {
data[5] = 0x00;
data[10] = 0x18;
}
switch (gspca_dev->width) {
case 160:
data[9] |= 0x0c;
case 320:
data[9] |= 0x04;
case 640:
default:
data[3] = 0x50;
data[4] = 0x78;
data[6] = 0x04;
data[8] = 0x03;
if (sd->sensor_type == 2) {
data[6] = 2;
data[8] = 1;
}
if (sd->do_lcd_stop)
data[8] = 0x04;
break;
case 176:
data[9] |= 0x04;
case 352:
data[3] = 0x2c;
data[4] = 0x48;
data[6] = 0x94;
data[8] = 0x63;
if (sd->do_lcd_stop)
data[8] = 0x64;
break;
}
err_code = mr_write(gspca_dev, 11);
if (err_code < 0)
return err_code;
if (!sd->sensor_type) {
static const struct sensor_w_data vga_sensor0_init_data[] = {
{0x01, 0x00, {0x0c, 0x00, 0x04}, 3},
{0x14, 0x00, {0x01, 0xe4, 0x02, 0x84}, 4},
{0x20, 0x00, {0x00, 0x80, 0x00, 0x08}, 4},
{0x25, 0x00, {0x03, 0xa9, 0x80}, 3},
{0x30, 0x00, {0x30, 0x18, 0x10, 0x18}, 4},
{0, 0, {0}, 0}
};
err_code = sensor_write_regs(gspca_dev, vga_sensor0_init_data,
ARRAY_SIZE(vga_sensor0_init_data));
} else if (sd->sensor_type == 1) {
static const struct sensor_w_data color_adj[] = {
{0x02, 0x00, {0x06, 0x59, 0x0c, 0x16, 0x00,
0x05, 0x01, 0x04}, 8}
};
static const struct sensor_w_data color_no_adj[] = {
{0x02, 0x00, {0x06, 0x59, 0x0c, 0x16, 0x00,
0x07, 0x00, 0x01}, 8}
};
static const struct sensor_w_data vga_sensor1_init_data[] = {
{0x11, 0x04, {0x01}, 1},
{0x0a, 0x00, {0x00, 0x01, 0x00, 0x00, 0x01,
0x00, 0x0a}, 7},
{0x11, 0x04, {0x01}, 1},
{0x12, 0x00, {0x00, 0x63, 0x00, 0x70, 0x00, 0x00}, 6},
{0x11, 0x04, {0x01}, 1},
{0, 0, {0}, 0}
};
if (sd->adj_colors)
err_code = sensor_write_regs(gspca_dev, color_adj,
ARRAY_SIZE(color_adj));
else
err_code = sensor_write_regs(gspca_dev, color_no_adj,
ARRAY_SIZE(color_no_adj));
if (err_code < 0)
return err_code;
err_code = sensor_write_regs(gspca_dev, vga_sensor1_init_data,
ARRAY_SIZE(vga_sensor1_init_data));
} else {
static const struct sensor_w_data vga_sensor2_init_data[] = {
{0x01, 0x00, {0x48}, 1},
{0x02, 0x00, {0x22}, 1},
{0x05, 0x00, {0x10}, 1},
{0x06, 0x00, {0x00}, 1},
{0x07, 0x00, {0x00}, 1},
{0x08, 0x00, {0x00}, 1},
{0x09, 0x00, {0x00}, 1},
{0x12, 0x00, {0x00}, 1},
{0x13, 0x00, {0x04}, 1},
{0x14, 0x00, {0x00}, 1},
{0x15, 0x00, {0x06}, 1},
{0x16, 0x00, {0x01}, 1},
{0x17, 0x00, {0xe2}, 1},
{0x18, 0x00, {0x02}, 1},
{0x19, 0x00, {0x82}, 1},
{0x1a, 0x00, {0x00}, 1},
{0x1b, 0x00, {0x20}, 1},
{0x1d, 0x00, {0x80}, 1},
{0x1e, 0x00, {0x08}, 1},
{0x1f, 0x00, {0x0c}, 1},
{0x20, 0x00, {0x00}, 1},
{0, 0, {0}, 0}
};
err_code = sensor_write_regs(gspca_dev, vga_sensor2_init_data,
ARRAY_SIZE(vga_sensor2_init_data));
}
return err_code;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int err_code;
sd->sof_read = 0;
err_code = zero_the_pointer(gspca_dev);
if (err_code < 0)
return err_code;
err_code = stream_start(gspca_dev);
if (err_code < 0)
return err_code;
if (sd->cam_type == CAM_TYPE_CIF) {
err_code = start_cif_cam(gspca_dev);
} else {
err_code = start_vga_cam(gspca_dev);
}
if (err_code < 0)
return err_code;
setbrightness(gspca_dev);
setcontrast(gspca_dev);
setexposure(gspca_dev);
setgain(gspca_dev);
return isoc_enable(gspca_dev);
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
stream_stop(gspca_dev);
zero_the_pointer(gspca_dev);
if (sd->do_lcd_stop)
lcd_stop(gspca_dev);
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 val;
u8 sign_reg = 7;
u8 value_reg = 8;
static const u8 quick_clix_table[] =
{ 0, 4, 8, 12, 1, 2, 3, 5, 6, 9, 7, 10, 13, 11, 14, 15};
if ((gspca_dev->ctrl_dis & (1 << NORM_BRIGHTNESS_IDX)) &&
(gspca_dev->ctrl_dis & (1 << ARGUS_QC_BRIGHTNESS_IDX)))
return;
if (sd->cam_type == CAM_TYPE_VGA) {
sign_reg += 4;
value_reg += 4;
}
if (sd->brightness > 0) {
sensor_write1(gspca_dev, sign_reg, 0x00);
val = sd->brightness;
} else {
sensor_write1(gspca_dev, sign_reg, 0x01);
val = (257 - sd->brightness);
}
if (sd->do_lcd_stop)
val = quick_clix_table[val];
sensor_write1(gspca_dev, value_reg, val);
}
static void setexposure(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int exposure = MR97310A_EXPOSURE_DEFAULT;
u8 buf[2];
if (gspca_dev->ctrl_dis & (1 << EXPOSURE_IDX))
return;
if (sd->cam_type == CAM_TYPE_CIF && sd->sensor_type == 1) {
exposure = (sd->exposure * 9267) / 10000 + 300;
sensor_write1(gspca_dev, 3, exposure >> 4);
sensor_write1(gspca_dev, 4, exposure & 0x0f);
} else if (sd->sensor_type == 2) {
exposure = sd->exposure;
exposure >>= 3;
sensor_write1(gspca_dev, 3, exposure >> 8);
sensor_write1(gspca_dev, 4, exposure & 0xff);
} else {
u8 clockdiv = (60 * sd->exposure + 7999) / 8000;
if (clockdiv < sd->min_clockdiv && gspca_dev->width >= 320)
clockdiv = sd->min_clockdiv;
else if (clockdiv < 2)
clockdiv = 2;
if (sd->cam_type == CAM_TYPE_VGA && clockdiv < 4)
clockdiv = 4;
exposure = (60 * 511 * sd->exposure) / (8000 * clockdiv);
if (exposure > 511)
exposure = 511;
exposure = 511 - exposure;
buf[0] = exposure & 0xff;
buf[1] = exposure >> 8;
sensor_write_reg(gspca_dev, 0x0e, 0, buf, 2);
sensor_write1(gspca_dev, 0x02, clockdiv);
}
}
static void setgain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 gainreg;
if ((gspca_dev->ctrl_dis & (1 << GAIN_IDX)) &&
(gspca_dev->ctrl_dis & (1 << SAKAR_CS_GAIN_IDX)))
return;
if (sd->cam_type == CAM_TYPE_CIF && sd->sensor_type == 1)
sensor_write1(gspca_dev, 0x0e, sd->gain);
else if (sd->cam_type == CAM_TYPE_VGA && sd->sensor_type == 2)
for (gainreg = 0x0a; gainreg < 0x11; gainreg += 2) {
sensor_write1(gspca_dev, gainreg, sd->gain >> 8);
sensor_write1(gspca_dev, gainreg + 1, sd->gain & 0xff);
}
else
sensor_write1(gspca_dev, 0x10, sd->gain);
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (gspca_dev->ctrl_dis & (1 << CONTRAST_IDX))
return;
sensor_write1(gspca_dev, 0x1c, sd->contrast);
}
static int sd_setbrightness(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->brightness = val;
if (gspca_dev->streaming)
setbrightness(gspca_dev);
return 0;
}
static int sd_getbrightness(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->brightness;
return 0;
}
static int sd_setexposure(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->exposure = val;
if (gspca_dev->streaming)
setexposure(gspca_dev);
return 0;
}
static int sd_getexposure(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->exposure;
return 0;
}
static int sd_setgain(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->gain = val;
if (gspca_dev->streaming)
setgain(gspca_dev);
return 0;
}
static int sd_getgain(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->gain;
return 0;
}
static int sd_setcontrast(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->contrast = val;
if (gspca_dev->streaming)
setcontrast(gspca_dev);
return 0;
}
static int sd_getcontrast(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->contrast;
return 0;
}
static int sd_setmin_clockdiv(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->min_clockdiv = val;
if (gspca_dev->streaming)
setexposure(gspca_dev);
return 0;
}
static int sd_getmin_clockdiv(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->min_clockdiv;
return 0;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
unsigned char *sof;
sof = pac_find_sof(&sd->sof_read, data, len);
if (sof) {
int n;
n = sof - data;
if (n > sizeof pac_sof_marker)
n -= sizeof pac_sof_marker;
else
n = 0;
gspca_frame_add(gspca_dev, LAST_PACKET,
data, n);
gspca_frame_add(gspca_dev, FIRST_PACKET,
pac_sof_marker, sizeof pac_sof_marker);
len -= sof - data;
data = sof;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
static int __init sd_mod_init(void)
{
return usb_register(&sd_driver);
}
static void __exit sd_mod_exit(void)
{
usb_deregister(&sd_driver);
}
