int m5602_read_bridge(struct sd *sd, const u8 address, u8 *i2c_data)
{
int err;
struct gspca_dev *gspca_dev = (struct gspca_dev *) sd;
struct usb_device *udev = sd->gspca_dev.dev;
__u8 *buf = sd->gspca_dev.usb_buf;
err = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
0x04, 0xc0, 0x14,
0x8100 + address, buf,
1, M5602_URB_MSG_TIMEOUT);
*i2c_data = buf[0];
PDEBUG(D_CONF, "Reading bridge register 0x%x containing 0x%x",
address, *i2c_data);
return (err < 0) ? err : 0;
}
int m5602_write_bridge(struct sd *sd, const u8 address, const u8 i2c_data)
{
int err;
struct gspca_dev *gspca_dev = (struct gspca_dev *) sd;
struct usb_device *udev = sd->gspca_dev.dev;
__u8 *buf = sd->gspca_dev.usb_buf;
PDEBUG(D_CONF, "Writing bridge register 0x%x with 0x%x",
address, i2c_data);
memcpy(buf, bridge_urb_skeleton,
sizeof(bridge_urb_skeleton));
buf[1] = address;
buf[3] = i2c_data;
err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x04, 0x40, 0x19,
0x0000, buf,
4, M5602_URB_MSG_TIMEOUT);
return (err < 0) ? err : 0;
}
static int m5602_wait_for_i2c(struct sd *sd)
{
int err;
u8 data;
do {
err = m5602_read_bridge(sd, M5602_XB_I2C_STATUS, &data);
} while ((data & I2C_BUSY) && !err);
return err;
}
int m5602_read_sensor(struct sd *sd, const u8 address,
u8 *i2c_data, const u8 len)
{
int err, i;
struct gspca_dev *gspca_dev = (struct gspca_dev *) sd;
if (!len || len > sd->sensor->i2c_regW)
return -EINVAL;
err = m5602_wait_for_i2c(sd);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_I2C_DEV_ADDR,
sd->sensor->i2c_slave_id);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_I2C_REG_ADDR, address);
if (err < 0)
return err;
if (sd->sensor->i2c_regW == 1) {
err = m5602_write_bridge(sd, M5602_XB_I2C_CTRL, 1);
if (err < 0)
return err;
err = m5602_write_bridge(sd, M5602_XB_I2C_CTRL, 0x08);
} else {
err = m5602_write_bridge(sd, M5602_XB_I2C_CTRL, 0x18 + len);
}
for (i = 0; (i < len) && !err; i++) {
err = m5602_wait_for_i2c(sd);
if (err < 0)
return err;
err = m5602_read_bridge(sd, M5602_XB_I2C_DATA, &(i2c_data[i]));
PDEBUG(D_CONF, "Reading sensor register 0x%x containing 0x%x ",
address, *i2c_data);
}
return err;
}
int m5602_write_sensor(struct sd *sd, const u8 address,
u8 *i2c_data, const u8 len)
{
int err, i;
u8 *p;
struct gspca_dev *gspca_dev = (struct gspca_dev *) sd;
struct usb_device *udev = sd->gspca_dev.dev;
__u8 *buf = sd->gspca_dev.usb_buf;
if (len > sd->sensor->i2c_regW || !len)
return -EINVAL;
memcpy(buf, sensor_urb_skeleton,
sizeof(sensor_urb_skeleton));
buf[11] = sd->sensor->i2c_slave_id;
buf[15] = address;
p = buf + 16;
for (i = 0; i < len; i++) {
memcpy(p, sensor_urb_skeleton + 16, 4);
p[3] = i2c_data[i];
p += 4;
PDEBUG(D_CONF, "Writing sensor register 0x%x with 0x%x",
address, i2c_data[i]);
}
memcpy(p, sensor_urb_skeleton + 20, 4);
p[3] = 0x10 + len;
err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x04, 0x40, 0x19,
0x0000, buf,
20 + len * 4, M5602_URB_MSG_TIMEOUT);
return (err < 0) ? err : 0;
}
static void m5602_dump_bridge(struct sd *sd)
{
int i;
for (i = 0; i < 0x80; i++) {
unsigned char val = 0;
m5602_read_bridge(sd, i, &val);
pr_info("ALi m5602 address 0x%x contains 0x%x\n", i, val);
}
pr_info("Warning: The ALi m5602 webcam probably won't work until it's power cycled\n");
}
static int m5602_probe_sensor(struct sd *sd)
{
sd->sensor = &po1030;
if (!sd->sensor->probe(sd))
return 0;
sd->sensor = &mt9m111;
if (!sd->sensor->probe(sd))
return 0;
sd->sensor = &s5k4aa;
if (!sd->sensor->probe(sd))
return 0;
sd->sensor = &ov9650;
if (!sd->sensor->probe(sd))
return 0;
sd->sensor = &ov7660;
if (!sd->sensor->probe(sd))
return 0;
sd->sensor = &s5k83a;
if (!sd->sensor->probe(sd))
return 0;
pr_info("Failed to find a sensor\n");
sd->sensor = NULL;
return -ENODEV;
}
static int m5602_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int err;
PDEBUG(D_CONF, "Initializing ALi m5602 webcam");
err = sd->sensor->init(sd);
return err;
}
static int m5602_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (!sd->sensor->init_controls)
return 0;
return sd->sensor->init_controls(sd);
}
static int m5602_start_transfer(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
__u8 *buf = sd->gspca_dev.usb_buf;
int err;
const u8 buffer[4] = {0x13, 0xf9, 0x0f, 0x01};
if (sd->sensor->start)
sd->sensor->start(sd);
memcpy(buf, buffer, sizeof(buffer));
err = usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x04, 0x40, 0x19, 0x0000, buf,
sizeof(buffer), M5602_URB_MSG_TIMEOUT);
PDEBUG(D_STREAM, "Transfer started");
return (err < 0) ? err : 0;
}
static void m5602_urb_complete(struct gspca_dev *gspca_dev,
u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (len < 6) {
PDEBUG(D_PACK, "Packet is less than 6 bytes");
return;
}
if (data[0] == 0xff && data[4] == 0xff && data[5] == 0xff &&
data[2] != sd->frame_id) {
PDEBUG(D_FRAM, "Frame delimiter detected");
sd->frame_id = data[2];
data += 6;
len -= 6;
gspca_frame_add(gspca_dev, LAST_PACKET,
NULL, 0);
sd->frame_count++;
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
PDEBUG(D_FRAM, "Starting new frame %d",
sd->frame_count);
} else {
int cur_frame_len;
cur_frame_len = gspca_dev->image_len;
data += 4;
len -= 4;
if (cur_frame_len + len <= gspca_dev->frsz) {
PDEBUG(D_FRAM, "Continuing frame %d copying %d bytes",
sd->frame_count, len);
gspca_frame_add(gspca_dev, INTER_PACKET,
data, len);
} else {
gspca_frame_add(gspca_dev, INTER_PACKET, data,
gspca_dev->frsz - cur_frame_len);
}
}
}
static void m5602_stop_transfer(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor->stop)
sd->sensor->stop(sd);
}
static int m5602_configure(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
int err;
cam = &gspca_dev->cam;
if (dump_bridge)
m5602_dump_bridge(sd);
err = m5602_probe_sensor(sd);
if (err)
goto fail;
return 0;
fail:
PERR("ALi m5602 webcam failed");
cam->cam_mode = NULL;
cam->nmodes = 0;
return err;
}
static int m5602_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
static void m5602_disconnect(struct usb_interface *intf)
{
struct gspca_dev *gspca_dev = usb_get_intfdata(intf);
struct sd *sd = (struct sd *) gspca_dev;
if (sd->sensor->disconnect)
sd->sensor->disconnect(sd);
gspca_disconnect(intf);
}
