static void jlj_write2(struct gspca_dev *gspca_dev, unsigned char *command)
{
int retval;
if (gspca_dev->usb_err < 0)
return;
memcpy(gspca_dev->usb_buf, command, 2);
retval = usb_bulk_msg(gspca_dev->dev,
usb_sndbulkpipe(gspca_dev->dev, 3),
gspca_dev->usb_buf, 2, NULL, 500);
if (retval < 0) {
pr_err("command write [%02x] error %d\n",
gspca_dev->usb_buf[0], retval);
gspca_dev->usb_err = retval;
}
}
static void jlj_read1(struct gspca_dev *gspca_dev, unsigned char response)
{
int retval;
if (gspca_dev->usb_err < 0)
return;
retval = usb_bulk_msg(gspca_dev->dev,
usb_rcvbulkpipe(gspca_dev->dev, 0x84),
gspca_dev->usb_buf, 1, NULL, 500);
response = gspca_dev->usb_buf[0];
if (retval < 0) {
pr_err("read command [%02x] error %d\n",
gspca_dev->usb_buf[0], retval);
gspca_dev->usb_err = retval;
}
}
static void setfreq(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 freq_commands[][2] = {
{0x71, 0x80},
{0x70, 0x07}
};
freq_commands[0][1] |= (sd->ctrls[LIGHTFREQ].val >> 1);
jlj_write2(gspca_dev, freq_commands[0]);
jlj_write2(gspca_dev, freq_commands[1]);
}
static void setcamquality(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 quality_commands[][2] = {
{0x71, 0x1E},
{0x70, 0x06}
};
u8 camquality;
camquality = ((QUALITY_MAX - sd->quality) * CAMQUALITY_MAX)
/ (QUALITY_MAX - QUALITY_MIN);
quality_commands[0][1] += camquality;
jlj_write2(gspca_dev, quality_commands[0]);
jlj_write2(gspca_dev, quality_commands[1]);
}
static void setautogain(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 autogain_commands[][2] = {
{0x94, 0x02},
{0xcf, 0x00}
};
autogain_commands[1][1] = (sd->ctrls[AUTOGAIN].val << 4);
jlj_write2(gspca_dev, autogain_commands[0]);
jlj_write2(gspca_dev, autogain_commands[1]);
}
static void setred(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 setred_commands[][2] = {
{0x94, 0x02},
{0xe6, 0x00}
};
setred_commands[1][1] = sd->ctrls[RED].val;
jlj_write2(gspca_dev, setred_commands[0]);
jlj_write2(gspca_dev, setred_commands[1]);
}
static void setgreen(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 setgreen_commands[][2] = {
{0x94, 0x02},
{0xe7, 0x00}
};
setgreen_commands[1][1] = sd->ctrls[GREEN].val;
jlj_write2(gspca_dev, setgreen_commands[0]);
jlj_write2(gspca_dev, setgreen_commands[1]);
}
static void setblue(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 setblue_commands[][2] = {
{0x94, 0x02},
{0xe9, 0x00}
};
setblue_commands[1][1] = sd->ctrls[BLUE].val;
jlj_write2(gspca_dev, setblue_commands[0]);
jlj_write2(gspca_dev, setblue_commands[1]);
}
static int jlj_start(struct gspca_dev *gspca_dev)
{
int i;
int start_commands_size;
u8 response = 0xff;
struct sd *sd = (struct sd *) gspca_dev;
struct jlj_command start_commands[] = {
{{0x71, 0x81}, 0, 0},
{{0x70, 0x05}, 0, JEILINJ_CMD_DELAY},
{{0x95, 0x70}, 1, 0},
{{0x71, 0x81 - gspca_dev->curr_mode}, 0, 0},
{{0x70, 0x04}, 0, JEILINJ_CMD_DELAY},
{{0x95, 0x70}, 1, 0},
{{0x71, 0x00}, 0, 0},
{{0x70, 0x08}, 0, JEILINJ_CMD_DELAY},
{{0x95, 0x70}, 1, 0},
#define SPORTSCAM_DV15_CMD_SIZE 9
{{0x94, 0x02}, 0, 0},
{{0xde, 0x24}, 0, 0},
{{0x94, 0x02}, 0, 0},
{{0xdd, 0xf0}, 0, 0},
{{0x94, 0x02}, 0, 0},
{{0xe3, 0x2c}, 0, 0},
{{0x94, 0x02}, 0, 0},
{{0xe4, 0x00}, 0, 0},
{{0x94, 0x02}, 0, 0},
{{0xe5, 0x00}, 0, 0},
{{0x94, 0x02}, 0, 0},
{{0xe6, 0x2c}, 0, 0},
{{0x94, 0x03}, 0, 0},
{{0xaa, 0x00}, 0, 0}
};
sd->blocks_left = 0;
if (sd->type == SPORTSCAM_DV15)
start_commands_size = SPORTSCAM_DV15_CMD_SIZE;
else
start_commands_size = ARRAY_SIZE(start_commands);
for (i = 0; i < start_commands_size; i++) {
jlj_write2(gspca_dev, start_commands[i].instruction);
if (start_commands[i].delay)
msleep(start_commands[i].delay);
if (start_commands[i].ack_wanted)
jlj_read1(gspca_dev, response);
}
setcamquality(gspca_dev);
msleep(2);
setfreq(gspca_dev);
if (gspca_dev->usb_err < 0)
PDEBUG(D_ERR, "Start streaming command failed");
return gspca_dev->usb_err;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int packet_type;
u32 header_marker;
PDEBUG(D_STREAM, "Got %d bytes out of %d for Block 0",
len, JEILINJ_MAX_TRANSFER);
if (len != JEILINJ_MAX_TRANSFER) {
PDEBUG(D_PACK, "bad length");
goto discard;
}
header_marker = ((u32 *)data)[0];
if (header_marker == FRAME_START) {
sd->blocks_left = data[0x0a] - 1;
PDEBUG(D_STREAM, "blocks_left = 0x%x", sd->blocks_left);
gspca_frame_add(gspca_dev, FIRST_PACKET,
sd->jpeg_hdr, JPEG_HDR_SZ);
gspca_frame_add(gspca_dev, INTER_PACKET,
data + FRAME_HEADER_LEN,
JEILINJ_MAX_TRANSFER - FRAME_HEADER_LEN);
} else if (sd->blocks_left > 0) {
PDEBUG(D_STREAM, "%d blocks remaining for frame",
sd->blocks_left);
sd->blocks_left -= 1;
if (sd->blocks_left == 0)
packet_type = LAST_PACKET;
else
packet_type = INTER_PACKET;
gspca_frame_add(gspca_dev, packet_type,
data, JEILINJ_MAX_TRANSFER);
} else
goto discard;
return;
discard:
gspca_dev->last_packet_type = DISCARD_PACKET;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam = &gspca_dev->cam;
struct sd *dev = (struct sd *) gspca_dev;
dev->type = id->driver_info;
gspca_dev->cam.ctrls = dev->ctrls;
dev->quality = QUALITY_DEF;
cam->cam_mode = jlj_mode;
cam->nmodes = ARRAY_SIZE(jlj_mode);
cam->bulk = 1;
cam->bulk_nurbs = 1;
cam->bulk_size = JEILINJ_MAX_TRANSFER;
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
int i;
u8 *buf;
static u8 stop_commands[][2] = {
{0x71, 0x00},
{0x70, 0x09},
{0x71, 0x80},
{0x70, 0x05}
};
for (;;) {
usb_bulk_msg(gspca_dev->dev,
gspca_dev->urb[0]->pipe,
gspca_dev->urb[0]->transfer_buffer,
JEILINJ_MAX_TRANSFER, NULL,
JEILINJ_DATA_TIMEOUT);
i = 0;
buf = gspca_dev->urb[0]->transfer_buffer;
while ((i < (JEILINJ_MAX_TRANSFER - 1)) &&
((buf[i] != 0xff) || (buf[i+1] != 0xd9)))
i++;
if (i != (JEILINJ_MAX_TRANSFER - 1))
break;
}
for (i = 0; i < ARRAY_SIZE(stop_commands); i++)
jlj_write2(gspca_dev, stop_commands[i]);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *dev = (struct sd *) gspca_dev;
jpeg_define(dev->jpeg_hdr, gspca_dev->height, gspca_dev->width,
0x21);
jpeg_set_qual(dev->jpeg_hdr, dev->quality);
PDEBUG(D_STREAM, "Start streaming at %dx%d",
gspca_dev->height, gspca_dev->width);
jlj_start(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_querymenu(struct gspca_dev *gspca_dev,
struct v4l2_querymenu *menu)
{
switch (menu->id) {
case V4L2_CID_POWER_LINE_FREQUENCY:
switch (menu->index) {
case 0:
strcpy((char *) menu->name, "disable");
return 0;
case 1:
strcpy((char *) menu->name, "50 Hz");
return 0;
case 2:
strcpy((char *) menu->name, "60 Hz");
return 0;
}
break;
}
return -EINVAL;
}
static int sd_set_jcomp(struct gspca_dev *gspca_dev,
struct v4l2_jpegcompression *jcomp)
{
struct sd *sd = (struct sd *) gspca_dev;
if (jcomp->quality < QUALITY_MIN)
sd->quality = QUALITY_MIN;
else if (jcomp->quality > QUALITY_MAX)
sd->quality = QUALITY_MAX;
else
sd->quality = jcomp->quality;
if (gspca_dev->streaming) {
jpeg_set_qual(sd->jpeg_hdr, sd->quality);
setcamquality(gspca_dev);
}
return 0;
}
static int sd_get_jcomp(struct gspca_dev *gspca_dev,
struct v4l2_jpegcompression *jcomp)
{
struct sd *sd = (struct sd *) gspca_dev;
memset(jcomp, 0, sizeof *jcomp);
jcomp->quality = sd->quality;
jcomp->jpeg_markers = V4L2_JPEG_MARKER_DHT
| V4L2_JPEG_MARKER_DQT;
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id,
sd_desc[id->driver_info],
sizeof(struct sd),
THIS_MODULE);
}
