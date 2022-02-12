static int kinect_write(struct usb_device *udev, uint8_t *data,
uint16_t wLength)
{
return usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
0x00,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, 0, data, wLength, CTRL_TIMEOUT);
}
static int kinect_read(struct usb_device *udev, uint8_t *data, uint16_t wLength)
{
return usb_control_msg(udev,
usb_rcvctrlpipe(udev, 0),
0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, 0, data, wLength, CTRL_TIMEOUT);
}
static int send_cmd(struct gspca_dev *gspca_dev, uint16_t cmd, void *cmdbuf,
unsigned int cmd_len, void *replybuf, unsigned int reply_len)
{
struct sd *sd = (struct sd *) gspca_dev;
struct usb_device *udev = gspca_dev->dev;
int res, actual_len;
uint8_t *obuf = sd->obuf;
uint8_t *ibuf = sd->ibuf;
struct cam_hdr *chdr = (void *)obuf;
struct cam_hdr *rhdr = (void *)ibuf;
if (cmd_len & 1 || cmd_len > (0x400 - sizeof(*chdr))) {
pr_err("send_cmd: Invalid command length (0x%x)\n", cmd_len);
return -1;
}
chdr->magic[0] = 0x47;
chdr->magic[1] = 0x4d;
chdr->cmd = cpu_to_le16(cmd);
chdr->tag = cpu_to_le16(sd->cam_tag);
chdr->len = cpu_to_le16(cmd_len / 2);
memcpy(obuf+sizeof(*chdr), cmdbuf, cmd_len);
res = kinect_write(udev, obuf, cmd_len + sizeof(*chdr));
PDEBUG(D_USBO, "Control cmd=%04x tag=%04x len=%04x: %d", cmd,
sd->cam_tag, cmd_len, res);
if (res < 0) {
pr_err("send_cmd: Output control transfer failed (%d)\n", res);
return res;
}
do {
actual_len = kinect_read(udev, ibuf, 0x200);
} while (actual_len == 0);
PDEBUG(D_USBO, "Control reply: %d", actual_len);
if (actual_len < sizeof(*rhdr)) {
pr_err("send_cmd: Input control transfer failed (%d)\n",
actual_len);
return actual_len < 0 ? actual_len : -EREMOTEIO;
}
actual_len -= sizeof(*rhdr);
if (rhdr->magic[0] != 0x52 || rhdr->magic[1] != 0x42) {
pr_err("send_cmd: Bad magic %02x %02x\n",
rhdr->magic[0], rhdr->magic[1]);
return -1;
}
if (rhdr->cmd != chdr->cmd) {
pr_err("send_cmd: Bad cmd %02x != %02x\n",
rhdr->cmd, chdr->cmd);
return -1;
}
if (rhdr->tag != chdr->tag) {
pr_err("send_cmd: Bad tag %04x != %04x\n",
rhdr->tag, chdr->tag);
return -1;
}
if (cpu_to_le16(rhdr->len) != (actual_len/2)) {
pr_err("send_cmd: Bad len %04x != %04x\n",
cpu_to_le16(rhdr->len), (int)(actual_len/2));
return -1;
}
if (actual_len > reply_len) {
pr_warn("send_cmd: Data buffer is %d bytes long, but got %d bytes\n",
reply_len, actual_len);
memcpy(replybuf, ibuf+sizeof(*rhdr), reply_len);
} else {
memcpy(replybuf, ibuf+sizeof(*rhdr), actual_len);
}
sd->cam_tag++;
return actual_len;
}
static int write_register(struct gspca_dev *gspca_dev, uint16_t reg,
uint16_t data)
{
uint16_t reply[2];
uint16_t cmd[2];
int res;
cmd[0] = cpu_to_le16(reg);
cmd[1] = cpu_to_le16(data);
PDEBUG(D_USBO, "Write Reg 0x%04x <= 0x%02x", reg, data);
res = send_cmd(gspca_dev, 0x03, cmd, 4, reply, 4);
if (res < 0)
return res;
if (res != 2) {
pr_warn("send_cmd returned %d [%04x %04x], 0000 expected\n",
res, reply[0], reply[1]);
}
return 0;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
sd->cam_tag = 0;
sd->stream_flag = 0x80;
cam = &gspca_dev->cam;
cam->cam_mode = video_camera_mode;
cam->nmodes = ARRAY_SIZE(video_camera_mode);
#if 0
cam->npkt = 15;
gspca_dev->pkt_size = 960 * 2;
#endif
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
PDEBUG(D_PROBE, "Kinect Camera device.");
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
int mode;
uint8_t fmt_reg, fmt_val;
uint8_t res_reg, res_val;
uint8_t fps_reg, fps_val;
uint8_t mode_val;
mode = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].priv;
if (mode & FORMAT_Y10B) {
fmt_reg = 0x19;
res_reg = 0x1a;
fps_reg = 0x1b;
mode_val = 0x03;
} else {
fmt_reg = 0x0c;
res_reg = 0x0d;
fps_reg = 0x0e;
mode_val = 0x01;
}
if (mode & FORMAT_UYVY)
fmt_val = 0x05;
else
fmt_val = 0x00;
if (mode & MODE_1280x1024)
res_val = 0x02;
else
res_val = 0x01;
if (mode & FPS_HIGH)
fps_val = 0x1e;
else
fps_val = 0x0f;
write_register(gspca_dev, 0x105, 0x00);
write_register(gspca_dev, 0x05, 0x00);
if (mode & (FORMAT_Y10B | MODE_1280x1024)) {
write_register(gspca_dev, 0x13, 0x01);
write_register(gspca_dev, 0x14, 0x1e);
write_register(gspca_dev, 0x06, 0x02);
write_register(gspca_dev, 0x06, 0x00);
}
write_register(gspca_dev, fmt_reg, fmt_val);
write_register(gspca_dev, res_reg, res_val);
write_register(gspca_dev, fps_reg, fps_val);
write_register(gspca_dev, 0x05, mode_val);
write_register(gspca_dev, 0x47, 0x00);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
write_register(gspca_dev, 0x05, 0x00);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev, u8 *__data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
struct pkt_hdr *hdr = (void *)__data;
uint8_t *data = __data + sizeof(*hdr);
int datalen = len - sizeof(*hdr);
uint8_t sof = sd->stream_flag | 1;
uint8_t mof = sd->stream_flag | 2;
uint8_t eof = sd->stream_flag | 5;
if (len < 12)
return;
if (hdr->magic[0] != 'R' || hdr->magic[1] != 'B') {
pr_warn("[Stream %02x] Invalid magic %02x%02x\n",
sd->stream_flag, hdr->magic[0], hdr->magic[1]);
return;
}
if (hdr->flag == sof)
gspca_frame_add(gspca_dev, FIRST_PACKET, data, datalen);
else if (hdr->flag == mof)
gspca_frame_add(gspca_dev, INTER_PACKET, data, datalen);
else if (hdr->flag == eof)
gspca_frame_add(gspca_dev, LAST_PACKET, data, datalen);
else
pr_warn("Packet type not recognized...\n");
}
static int sd_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
