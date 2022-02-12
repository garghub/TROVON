static void reg_w1(struct gspca_dev *gspca_dev,
__u16 index, __u8 value)
{
gspca_dev->usb_buf[0] = value;
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x02,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, 1, 500);
}
static void reg_w2(struct gspca_dev *gspca_dev,
u16 index, u16 value)
{
gspca_dev->usb_buf[0] = value;
gspca_dev->usb_buf[1] = value >> 8;
usb_control_msg(gspca_dev->dev,
usb_sndctrlpipe(gspca_dev->dev, 0),
0x02,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0,
index, gspca_dev->usb_buf, 2, 500);
}
static void tv_8532WriteEEprom(struct gspca_dev *gspca_dev)
{
int i;
reg_w1(gspca_dev, R01_TIMING_CONTROL_LOW, CMD_EEprom_Open);
for (i = 0; i < ARRAY_SIZE(eeprom_data); i++) {
reg_w1(gspca_dev, R03_TABLE_ADDR, i);
reg_w1(gspca_dev, R04_WTRAM_DATA_L, eeprom_data[i][2]);
reg_w1(gspca_dev, R05_WTRAM_DATA_M, eeprom_data[i][1]);
reg_w1(gspca_dev, R06_WTRAM_DATA_H, eeprom_data[i][0]);
reg_w1(gspca_dev, R08_RAM_WRITE_ACTION, 0);
}
reg_w1(gspca_dev, R07_TABLE_LEN, i);
reg_w1(gspca_dev, R01_TIMING_CONTROL_LOW, CMD_EEprom_Close);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = sif_mode;
cam->nmodes = ARRAY_SIZE(sif_mode);
return 0;
}
static void tv_8532_setReg(struct gspca_dev *gspca_dev)
{
reg_w1(gspca_dev, R3B_Test3, 0x0a);
reg_w1(gspca_dev, R0E_AD_HEIGHTL, 0x90);
reg_w1(gspca_dev, R0F_AD_HEIGHTH, 0x01);
reg_w2(gspca_dev, R1C_AD_EXPOSE_TIMEL, 0x018f);
reg_w1(gspca_dev, R10_AD_COL_BEGINL, 0x44);
reg_w1(gspca_dev, R11_AD_COL_BEGINH, 0x00);
reg_w1(gspca_dev, R14_AD_ROW_BEGINL, 0x0a);
reg_w1(gspca_dev, R94_AD_BITCONTROL, 0x02);
reg_w1(gspca_dev, R91_AD_SLOPEREG, 0x00);
reg_w1(gspca_dev, R00_PART_CONTROL, LATENT_CHANGE | EXPO_CHANGE);
}
static int sd_init(struct gspca_dev *gspca_dev)
{
tv_8532WriteEEprom(gspca_dev);
return 0;
}
static void setexposure(struct gspca_dev *gspca_dev, s32 val)
{
reg_w2(gspca_dev, R1C_AD_EXPOSE_TIMEL, val);
reg_w1(gspca_dev, R00_PART_CONTROL, LATENT_CHANGE | EXPO_CHANGE);
}
static void setgain(struct gspca_dev *gspca_dev, s32 val)
{
reg_w2(gspca_dev, R20_GAIN_G1L, val);
reg_w2(gspca_dev, R22_GAIN_RL, val);
reg_w2(gspca_dev, R24_GAIN_BL, val);
reg_w2(gspca_dev, R26_GAIN_G2L, val);
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_w1(gspca_dev, R0C_AD_WIDTHL, 0xe8);
reg_w1(gspca_dev, R0D_AD_WIDTHH, 0x03);
reg_w1(gspca_dev, R28_QUANT, 0x90);
if (gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv) {
reg_w1(gspca_dev, R29_LINE, 0x41);
} else {
reg_w1(gspca_dev, R29_LINE, 0x81);
}
reg_w1(gspca_dev, R2C_POLARITY, 0x10);
reg_w1(gspca_dev, R2D_POINT, 0x14);
reg_w1(gspca_dev, R2E_POINTH, 0x01);
reg_w1(gspca_dev, R2F_POINTB, 0x12);
reg_w1(gspca_dev, R30_POINTBH, 0x01);
tv_8532_setReg(gspca_dev);
reg_w1(gspca_dev, R31_UPD, 0x01);
msleep(200);
reg_w1(gspca_dev, R31_UPD, 0x00);
gspca_dev->empty_packet = 0;
sd->packet = 0;
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_w1(gspca_dev, R3B_Test3, 0x0b);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
int packet_type0, packet_type1;
packet_type0 = packet_type1 = INTER_PACKET;
if (gspca_dev->empty_packet) {
gspca_dev->empty_packet = 0;
sd->packet = gspca_dev->pixfmt.height / 2;
packet_type0 = FIRST_PACKET;
} else if (sd->packet == 0)
return;
sd->packet--;
if (sd->packet == 0)
packet_type1 = LAST_PACKET;
gspca_frame_add(gspca_dev, packet_type0,
data + 2, gspca_dev->pixfmt.width);
gspca_frame_add(gspca_dev, packet_type1,
data + gspca_dev->pixfmt.width + 5,
gspca_dev->pixfmt.width);
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
setexposure(gspca_dev, ctrl->val);
break;
case V4L2_CID_GAIN:
setgain(gspca_dev, ctrl->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 2);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 0x18f, 1, 0x18f);
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 0x7ff, 1, 0x100);
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
