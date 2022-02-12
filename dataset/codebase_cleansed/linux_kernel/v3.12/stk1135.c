static u8 reg_r(struct gspca_dev *gspca_dev, u16 index)
{
struct usb_device *dev = gspca_dev->dev;
int ret;
if (gspca_dev->usb_err < 0)
return 0;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
0x00,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x00,
index,
gspca_dev->usb_buf, 1,
500);
PDEBUG(D_USBI, "reg_r 0x%x=0x%02x", index, gspca_dev->usb_buf[0]);
if (ret < 0) {
pr_err("reg_r 0x%x err %d\n", index, ret);
gspca_dev->usb_err = ret;
return 0;
}
return gspca_dev->usb_buf[0];
}
static void reg_w(struct gspca_dev *gspca_dev, u16 index, u8 val)
{
int ret;
struct usb_device *dev = gspca_dev->dev;
if (gspca_dev->usb_err < 0)
return;
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0x01,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
val,
index,
NULL,
0,
500);
PDEBUG(D_USBO, "reg_w 0x%x:=0x%02x", index, val);
if (ret < 0) {
pr_err("reg_w 0x%x err %d\n", index, ret);
gspca_dev->usb_err = ret;
}
}
static void reg_w_mask(struct gspca_dev *gspca_dev, u16 index, u8 val, u8 mask)
{
val = (reg_r(gspca_dev, index) & ~mask) | (val & mask);
reg_w(gspca_dev, index, val);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
gspca_dev->cam.cam_mode = stk1135_modes;
gspca_dev->cam.nmodes = ARRAY_SIZE(stk1135_modes);
return 0;
}
static int stk1135_serial_wait_ready(struct gspca_dev *gspca_dev)
{
int i = 0;
u8 val;
do {
val = reg_r(gspca_dev, STK1135_REG_SICTL + 1);
if (i++ > 500) {
pr_err("serial bus timeout: status=0x%02x\n", val);
return -1;
}
} while ((val & 0x10) || !(val & 0x05));
return 0;
}
static u8 sensor_read_8(struct gspca_dev *gspca_dev, u8 addr)
{
reg_w(gspca_dev, STK1135_REG_SBUSR, addr);
reg_w(gspca_dev, STK1135_REG_SICTL, 0x20);
if (stk1135_serial_wait_ready(gspca_dev)) {
pr_err("Sensor read failed\n");
return 0;
}
return reg_r(gspca_dev, STK1135_REG_SBUSR + 1);
}
static u16 sensor_read_16(struct gspca_dev *gspca_dev, u8 addr)
{
return (sensor_read_8(gspca_dev, addr) << 8) |
sensor_read_8(gspca_dev, 0xf1);
}
static void sensor_write_8(struct gspca_dev *gspca_dev, u8 addr, u8 data)
{
reg_w(gspca_dev, STK1135_REG_SBUSW, addr);
reg_w(gspca_dev, STK1135_REG_SBUSW + 1, data);
reg_w(gspca_dev, STK1135_REG_SICTL, 0x01);
if (stk1135_serial_wait_ready(gspca_dev)) {
pr_err("Sensor write failed\n");
return;
}
}
static void sensor_write_16(struct gspca_dev *gspca_dev, u8 addr, u16 data)
{
sensor_write_8(gspca_dev, addr, data >> 8);
sensor_write_8(gspca_dev, 0xf1, data & 0xff);
}
static void sensor_set_page(struct gspca_dev *gspca_dev, u8 page)
{
struct sd *sd = (struct sd *) gspca_dev;
if (page != sd->sensor_page) {
sensor_write_16(gspca_dev, 0xf0, page);
sd->sensor_page = page;
}
}
static u16 sensor_read(struct gspca_dev *gspca_dev, u16 reg)
{
sensor_set_page(gspca_dev, reg >> 8);
return sensor_read_16(gspca_dev, reg & 0xff);
}
static void sensor_write(struct gspca_dev *gspca_dev, u16 reg, u16 val)
{
sensor_set_page(gspca_dev, reg >> 8);
sensor_write_16(gspca_dev, reg & 0xff, val);
}
static void sensor_write_mask(struct gspca_dev *gspca_dev,
u16 reg, u16 val, u16 mask)
{
val = (sensor_read(gspca_dev, reg) & ~mask) | (val & mask);
sensor_write(gspca_dev, reg, val);
}
static void stk1135_configure_mt9m112(struct gspca_dev *gspca_dev)
{
static const struct sensor_val cfg[] = {
{ 0x00d, 0x000b }, { 0x00d, 0x0008 }, { 0x035, 0x0022 },
{ 0x106, 0x700e },
{ 0x2dd, 0x18e0 },
{ 0x21f, 0x0180 },
{ 0x220, 0xc814 }, { 0x221, 0x8080 },
{ 0x222, 0xa078 }, { 0x223, 0xa078 },
{ 0x224, 0x5f20 }, { 0x228, 0xea02 },
{ 0x229, 0x867a },
{ 0x25e, 0x594c }, { 0x25f, 0x4d51 }, { 0x260, 0x0002 },
{ 0x2ef, 0x0008 }, { 0x2f2, 0x0000 },
{ 0x202, 0x00ee }, { 0x203, 0x3923 }, { 0x204, 0x0724 },
{ 0x209, 0x00cd }, { 0x20a, 0x0093 }, { 0x20b, 0x0004 },
{ 0x20c, 0x005c }, { 0x20d, 0x00d9 }, { 0x20e, 0x0053 },
{ 0x20f, 0x0008 }, { 0x210, 0x0091 }, { 0x211, 0x00cf },
{ 0x215, 0x0000 },
{ 0x216, 0x0000 }, { 0x217, 0x0000 }, { 0x218, 0x0000 },
{ 0x219, 0x0000 }, { 0x21a, 0x0000 }, { 0x21b, 0x0000 },
{ 0x21c, 0x0000 }, { 0x21d, 0x0000 }, { 0x21e, 0x0000 },
{ 0x106, 0xf00e }, { 0x106, 0x700e },
{ 0x180, 0x0007 },
{ 0x181, 0xde13 }, { 0x182, 0xebe2 }, { 0x183, 0x00f6 },
{ 0x184, 0xe114 }, { 0x185, 0xeadd }, { 0x186, 0xfdf6 },
{ 0x187, 0xe511 }, { 0x188, 0xede6 }, { 0x189, 0xfbf7 },
{ 0x18a, 0xd613 }, { 0x18b, 0xedec },
{ 0x18c, 0xf9f2 }, { 0x18d, 0x0000 },
{ 0x18e, 0xd815 }, { 0x18f, 0xe9ea },
{ 0x190, 0xf9f1 }, { 0x191, 0x0002 },
{ 0x192, 0xde10 }, { 0x193, 0xefef },
{ 0x194, 0xfbf4 }, { 0x195, 0x0002 },
{ 0x1b6, 0x0e06 }, { 0x1b7, 0x2713 },
{ 0x1b8, 0x1106 }, { 0x1b9, 0x2713 },
{ 0x1ba, 0x0c03 }, { 0x1bb, 0x2a0f },
{ 0x1bc, 0x1208 }, { 0x1bd, 0x1a16 }, { 0x1be, 0x0022 },
{ 0x1bf, 0x150a }, { 0x1c0, 0x1c1a }, { 0x1c1, 0x002d },
{ 0x1c2, 0x1109 }, { 0x1c3, 0x1414 }, { 0x1c4, 0x002a },
{ 0x106, 0x740e },
{ 0x153, 0x0b03 }, { 0x154, 0x4722 }, { 0x155, 0xac82 },
{ 0x156, 0xdac7 }, { 0x157, 0xf5e9 }, { 0x158, 0xff00 },
{ 0x1dc, 0x0b03 }, { 0x1dd, 0x4722 }, { 0x1de, 0xac82 },
{ 0x1df, 0xdac7 }, { 0x1e0, 0xf5e9 }, { 0x1e1, 0xff00 },
{ 0x13a, 0x4300 }, { 0x19b, 0x4300 },
{ 0x108, 0x0180 },
{ 0x22f, 0xd100 }, { 0x29c, 0xd100 },
{ 0x2d2, 0x0000 }, { 0x2cc, 0x0004 }, { 0x2cb, 0x0001 },
{ 0x22e, 0x0c3c }, { 0x267, 0x1010 },
{ 0x065, 0xa000 },
{ 0x066, 0x2003 }, { 0x067, 0x0501 },
{ 0x065, 0x2000 },
{ 0x005, 0x01b8 }, { 0x007, 0x00d8 },
{ 0x239, 0x06c0 }, { 0x23b, 0x040e },
{ 0x23a, 0x06c0 }, { 0x23c, 0x0564 },
{ 0x257, 0x0208 }, { 0x258, 0x0271 },
{ 0x259, 0x0209 }, { 0x25a, 0x0271 },
{ 0x25c, 0x120d }, { 0x25d, 0x1712 },
{ 0x264, 0x5e1c },
{ 0x25b, 0x0003 }, { 0x236, 0x7810 }, { 0x237, 0x8304 },
{ 0x008, 0x0021 },
};
int i;
u16 width, height;
for (i = 0; i < ARRAY_SIZE(cfg); i++)
sensor_write(gspca_dev, cfg[i].reg, cfg[i].val);
width = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].width;
height = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].height;
if (width <= 640) {
sensor_write(gspca_dev, 0x1a7, width);
sensor_write(gspca_dev, 0x1aa, height);
sensor_write(gspca_dev, 0x0c8, 0x0000);
sensor_write(gspca_dev, 0x2c8, 0x0000);
} else {
sensor_write(gspca_dev, 0x1a1, width);
sensor_write(gspca_dev, 0x1a4, height);
sensor_write(gspca_dev, 0x0c8, 0x0008);
sensor_write(gspca_dev, 0x2c8, 0x040b);
}
}
static void stk1135_configure_clock(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, STK1135_REG_TMGEN, 0x12);
reg_w(gspca_dev, STK1135_REG_TCP1 + 0, 0x41);
reg_w(gspca_dev, STK1135_REG_TCP1 + 1, 0x00);
reg_w(gspca_dev, STK1135_REG_TCP1 + 2, 0x00);
reg_w(gspca_dev, STK1135_REG_TCP1 + 3, 0x00);
reg_w(gspca_dev, STK1135_REG_SENSO + 0, 0x10);
reg_w(gspca_dev, STK1135_REG_SENSO + 1, 0x00);
reg_w(gspca_dev, STK1135_REG_SENSO + 3, 0x07);
reg_w(gspca_dev, STK1135_REG_PLLFD, 0x06);
reg_w(gspca_dev, STK1135_REG_TMGEN, 0x80);
reg_w(gspca_dev, STK1135_REG_SENSO + 2, 0x04);
reg_w(gspca_dev, STK1135_REG_SICTL + 2, 0x1f);
}
static void stk1135_camera_disable(struct gspca_dev *gspca_dev)
{
reg_w(gspca_dev, STK1135_REG_CIEPO + 2, 0x00);
reg_w(gspca_dev, STK1135_REG_CIEPO + 3, 0x00);
reg_w_mask(gspca_dev, STK1135_REG_SCTRL, 0x00, 0x80);
sensor_write_mask(gspca_dev, 0x00d, 0x0004, 0x000c);
reg_w_mask(gspca_dev, STK1135_REG_SENSO + 2, 0x00, 0x01);
reg_w(gspca_dev, STK1135_REG_TMGEN, 0x00);
reg_w(gspca_dev, STK1135_REG_SENSO + 1, 0x20);
reg_w(gspca_dev, STK1135_REG_SENSO, 0x00);
reg_w(gspca_dev, STK1135_REG_GCTRL, 0x49);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
u16 sensor_id;
char *sensor_name;
struct sd *sd = (struct sd *) gspca_dev;
reg_w(gspca_dev, STK1135_REG_GCTRL + 2, 0x78);
reg_w(gspca_dev, STK1135_REG_GCTRL, (1 << 5));
reg_w(gspca_dev, STK1135_REG_GCTRL + 3, 0x80);
reg_w(gspca_dev, STK1135_REG_ICTRL + 1, 0x00);
reg_w(gspca_dev, STK1135_REG_ICTRL + 3, 0x03);
reg_w(gspca_dev, STK1135_REG_RMCTL + 1, 0x00);
reg_w(gspca_dev, STK1135_REG_RMCTL + 3, 0x02);
reg_w(gspca_dev, STK1135_REG_SICTL, 0x80);
reg_w(gspca_dev, STK1135_REG_SICTL, 0x00);
reg_w(gspca_dev, STK1135_REG_SICTL + 3, 0xba);
reg_w(gspca_dev, STK1135_REG_ASIC + 3, 0x00);
stk1135_configure_clock(gspca_dev);
sd->sensor_page = 0xff;
sensor_id = sensor_read(gspca_dev, 0x000);
switch (sensor_id) {
case 0x148c:
sensor_name = "MT9M112";
break;
default:
sensor_name = "unknown";
}
pr_info("Detected sensor type %s (0x%x)\n", sensor_name, sensor_id);
stk1135_camera_disable(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u16 width, height;
reg_w(gspca_dev, STK1135_REG_GCTRL, (1 << 5));
stk1135_configure_clock(gspca_dev);
reg_w(gspca_dev, STK1135_REG_CISPO + 0, 0x00);
reg_w(gspca_dev, STK1135_REG_CISPO + 1, 0x00);
reg_w(gspca_dev, STK1135_REG_CISPO + 2, 0x00);
reg_w(gspca_dev, STK1135_REG_CISPO + 3, 0x00);
width = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].width;
height = gspca_dev->cam.cam_mode[gspca_dev->curr_mode].height;
reg_w(gspca_dev, STK1135_REG_CIEPO + 0, width & 0xff);
reg_w(gspca_dev, STK1135_REG_CIEPO + 1, width >> 8);
reg_w(gspca_dev, STK1135_REG_CIEPO + 2, height & 0xff);
reg_w(gspca_dev, STK1135_REG_CIEPO + 3, height >> 8);
reg_w(gspca_dev, STK1135_REG_SCTRL, 0x20);
stk1135_configure_mt9m112(gspca_dev);
reg_w_mask(gspca_dev, STK1135_REG_SCTRL, 0x80, 0x80);
if (gspca_dev->usb_err >= 0)
PDEBUG(D_STREAM, "camera started alt: 0x%02x",
gspca_dev->alt);
sd->pkt_seq = 0;
return gspca_dev->usb_err;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
struct usb_device *dev = gspca_dev->dev;
usb_set_interface(dev, gspca_dev->iface, 0);
stk1135_camera_disable(gspca_dev);
PDEBUG(D_STREAM, "camera stopped");
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int skip = sizeof(struct stk1135_pkt_header);
bool flip;
enum gspca_packet_type pkt_type = INTER_PACKET;
struct stk1135_pkt_header *hdr = (void *)data;
u8 seq;
if (len < 4) {
PDEBUG(D_PACK, "received short packet (less than 4 bytes)");
return;
}
flip = !(le16_to_cpu(hdr->gpio) & (1 << 8));
if (sd->flip_status != flip)
sd->flip_debounce++;
else
sd->flip_debounce = 0;
if (!(hdr->flags & STK1135_HDR_FRAME_START)) {
seq = hdr->seq & STK1135_HDR_SEQ_MASK;
if (seq != sd->pkt_seq) {
PDEBUG(D_PACK, "received out-of-sequence packet");
sd->pkt_seq = seq;
gspca_dev->last_packet_type = DISCARD_PACKET;
return;
}
}
sd->pkt_seq++;
if (sd->pkt_seq > STK1135_HDR_SEQ_MASK)
sd->pkt_seq = 0;
if (len == sizeof(struct stk1135_pkt_header))
return;
if (hdr->flags & STK1135_HDR_FRAME_START) {
skip = 8;
gspca_frame_add(gspca_dev, LAST_PACKET, data, 0);
pkt_type = FIRST_PACKET;
}
gspca_frame_add(gspca_dev, pkt_type, data + skip, len - skip);
}
static void sethflip(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->flip_status)
val = !val;
sensor_write_mask(gspca_dev, 0x020, val ? 0x0002 : 0x0000 , 0x0002);
}
static void setvflip(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->flip_status)
val = !val;
sensor_write_mask(gspca_dev, 0x020, val ? 0x0001 : 0x0000 , 0x0001);
}
static void stk1135_dq_callback(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (sd->flip_debounce > 100) {
sd->flip_status = !sd->flip_status;
sethflip(gspca_dev, v4l2_ctrl_g_ctrl(sd->hflip));
setvflip(gspca_dev, v4l2_ctrl_g_ctrl(sd->vflip));
}
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_HFLIP:
sethflip(gspca_dev, ctrl->val);
break;
case V4L2_CID_VFLIP:
setvflip(gspca_dev, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 2);
sd->hflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
sd->vflip = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return gspca_dev_probe(intf, id, &sd_desc, sizeof(struct sd),
THIS_MODULE);
}
