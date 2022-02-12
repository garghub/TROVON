static int val_reply(struct gspca_dev *gspca_dev, const char *reply, int rc)
{
if (rc < 0) {
PERR("reply has error %d", rc);
return -EIO;
}
if (rc != 1) {
PERR("Bad reply size %d", rc);
return -EIO;
}
if (reply[0] != 0x08) {
PERR("Bad reply 0x%02X", reply[0]);
return -EIO;
}
return 0;
}
static void reg_w(struct gspca_dev *gspca_dev, u16 value, u16 index)
{
char buff[1];
int rc;
PDEBUG(D_USBO,
"reg_w bReq=0x0B, bReqT=0xC0, wVal=0x%04X, wInd=0x%04X\n",
value, index);
rc = usb_control_msg(gspca_dev->dev, usb_rcvctrlpipe(gspca_dev->dev, 0),
0x0B, 0xC0, value, index, buff, 1, 500);
PDEBUG(D_USBO, "rc=%d, ret={0x%02X}", rc, buff[0]);
if (rc < 0) {
PERR("Failed reg_w(0x0B, 0xC0, 0x%04X, 0x%04X) w/ rc %d\n",
value, index, rc);
gspca_dev->usb_err = rc;
return;
}
if (val_reply(gspca_dev, buff, rc)) {
PERR("Bad reply to reg_w(0x0B, 0xC0, 0x%04X, 0x%04X\n",
value, index);
gspca_dev->usb_err = -EIO;
}
}
static void reg_w_buf(struct gspca_dev *gspca_dev,
const struct cmd *p, int l)
{
do {
reg_w(gspca_dev, p->value, p->index);
p++;
} while (--l > 0);
}
static void setexposure(struct gspca_dev *gspca_dev, s32 val)
{
u16 value;
unsigned int w = gspca_dev->pixfmt.width;
if (w == 800)
value = val * 5;
else if (w == 1600)
value = val * 3;
else if (w == 3264)
value = val * 3 / 2;
else {
PERR("Invalid width %u\n", w);
gspca_dev->usb_err = -EINVAL;
return;
}
PDEBUG(D_STREAM, "exposure: 0x%04X ms\n", value);
reg_w(gspca_dev, value, REG_COARSE_INTEGRATION_TIME_);
reg_w(gspca_dev, value, REG_COARSE_INTEGRATION_TIME_);
}
static int gainify(int in)
{
if (in <= 0x7F)
return 0x1000 | in;
else if (in <= 0xFF)
return 0x1080 | in / 2;
else
return 0x1180 | in / 4;
}
static void setggain(struct gspca_dev *gspca_dev, u16 global_gain)
{
u16 normalized;
normalized = gainify(global_gain);
PDEBUG(D_STREAM, "gain G1/G2 (0x%04X): 0x%04X (src 0x%04X)\n",
REG_GREEN1_GAIN,
normalized, global_gain);
reg_w(gspca_dev, normalized, REG_GREEN1_GAIN);
reg_w(gspca_dev, normalized, REG_GREEN2_GAIN);
}
static void setbgain(struct gspca_dev *gspca_dev,
u16 gain, u16 global_gain)
{
u16 normalized;
normalized = global_gain +
((u32)global_gain) * gain / GAIN_MAX;
if (normalized > GAIN_MAX) {
PDEBUG(D_STREAM, "Truncating blue 0x%04X w/ value 0x%04X\n",
GAIN_MAX, normalized);
normalized = GAIN_MAX;
}
normalized = gainify(normalized);
PDEBUG(D_STREAM, "gain B (0x%04X): 0x%04X w/ source 0x%04X\n",
REG_BLUE_GAIN, normalized, gain);
reg_w(gspca_dev, normalized, REG_BLUE_GAIN);
}
static void setrgain(struct gspca_dev *gspca_dev,
u16 gain, u16 global_gain)
{
u16 normalized;
normalized = global_gain +
((u32)global_gain) * gain / GAIN_MAX;
if (normalized > GAIN_MAX) {
PDEBUG(D_STREAM, "Truncating gain 0x%04X w/ value 0x%04X\n",
GAIN_MAX, normalized);
normalized = GAIN_MAX;
}
normalized = gainify(normalized);
PDEBUG(D_STREAM, "gain R (0x%04X): 0x%04X w / source 0x%04X\n",
REG_RED_GAIN, normalized, gain);
reg_w(gspca_dev, normalized, REG_RED_GAIN);
}
static void configure_wh(struct gspca_dev *gspca_dev)
{
unsigned int w = gspca_dev->pixfmt.width;
PDEBUG(D_STREAM, "configure_wh\n");
if (w == 800) {
static const struct cmd reg_init_res[] = {
{0x0060, REG_X_ADDR_START},
{0x0CD9, REG_X_ADDR_END},
{0x0036, REG_Y_ADDR_START},
{0x098F, REG_Y_ADDR_END},
{0x07C7, REG_READ_MODE},
};
reg_w_buf(gspca_dev,
reg_init_res, ARRAY_SIZE(reg_init_res));
} else if (w == 1600) {
static const struct cmd reg_init_res[] = {
{0x009C, REG_X_ADDR_START},
{0x0D19, REG_X_ADDR_END},
{0x0068, REG_Y_ADDR_START},
{0x09C5, REG_Y_ADDR_END},
{0x06C3, REG_READ_MODE},
};
reg_w_buf(gspca_dev,
reg_init_res, ARRAY_SIZE(reg_init_res));
} else if (w == 3264) {
static const struct cmd reg_init_res[] = {
{0x00E8, REG_X_ADDR_START},
{0x0DA7, REG_X_ADDR_END},
{0x009E, REG_Y_ADDR_START},
{0x0A2D, REG_Y_ADDR_END},
{0x0241, REG_READ_MODE},
};
reg_w_buf(gspca_dev,
reg_init_res, ARRAY_SIZE(reg_init_res));
} else {
PERR("bad width %u\n", w);
gspca_dev->usb_err = -EINVAL;
return;
}
reg_w(gspca_dev, 0x0000, REG_SCALING_MODE);
reg_w(gspca_dev, 0x0010, REG_SCALE_M);
reg_w(gspca_dev, w, REG_X_OUTPUT_SIZE);
reg_w(gspca_dev, gspca_dev->pixfmt.height, REG_Y_OUTPUT_SIZE);
if (w == 800) {
reg_w(gspca_dev, 0x0384, REG_FRAME_LENGTH_LINES_);
reg_w(gspca_dev, 0x0960, REG_LINE_LENGTH_PCK_);
} else if (w == 1600) {
reg_w(gspca_dev, 0x0640, REG_FRAME_LENGTH_LINES_);
reg_w(gspca_dev, 0x0FA0, REG_LINE_LENGTH_PCK_);
} else if (w == 3264) {
reg_w(gspca_dev, 0x0B4B, REG_FRAME_LENGTH_LINES_);
reg_w(gspca_dev, 0x1F40, REG_LINE_LENGTH_PCK_);
} else {
PERR("bad width %u\n", w);
gspca_dev->usb_err = -EINVAL;
return;
}
}
static void configure_encrypted(struct gspca_dev *gspca_dev)
{
static const struct cmd reg_init_begin[] = {
{0x0100, REG_SOFTWARE_RESET},
{0x0000, REG_MODE_SELECT},
{0x0100, REG_GROUPED_PARAMETER_HOLD},
{0x0004, REG_VT_PIX_CLK_DIV},
{0x0001, REG_VT_SYS_CLK_DIV},
{0x0008, REG_OP_PIX_CLK_DIV},
{0x0001, REG_OP_SYS_CLK_DIV},
{0x0004, REG_PRE_PLL_CLK_DIV},
{0x0040, REG_PLL_MULTIPLIER},
{0x0000, REG_GROUPED_PARAMETER_HOLD},
{0x0100, REG_GROUPED_PARAMETER_HOLD},
};
static const struct cmd reg_init_end[] = {
{0x0000, REG_GROUPED_PARAMETER_HOLD},
{0x0301, 0x31AE},
{0x0805, 0x3064},
{0x0071, 0x3170},
{0x10DE, REG_RESET_REGISTER},
{0x0000, REG_MODE_SELECT},
{0x0010, REG_PLL_MULTIPLIER},
{0x0100, REG_MODE_SELECT},
};
PDEBUG(D_STREAM, "Encrypted begin, w = %u\n", gspca_dev->pixfmt.width);
reg_w_buf(gspca_dev, reg_init_begin, ARRAY_SIZE(reg_init_begin));
configure_wh(gspca_dev);
reg_w_buf(gspca_dev, reg_init_end, ARRAY_SIZE(reg_init_end));
reg_w(gspca_dev, 0x0100, REG_GROUPED_PARAMETER_HOLD);
reg_w(gspca_dev, 0x0000, REG_GROUPED_PARAMETER_HOLD);
PDEBUG(D_STREAM, "Encrypted end\n");
}
static int configure(struct gspca_dev *gspca_dev)
{
int rc;
uint8_t buff[4];
PDEBUG(D_STREAM, "configure()\n");
rc = usb_control_msg(gspca_dev->dev, usb_rcvctrlpipe(gspca_dev->dev, 0),
0x16, 0xC0, 0x0000, 0x0000, buff, 2, 500);
if (val_reply(gspca_dev, buff, rc)) {
PERR("failed key req");
return -EIO;
}
rc = usb_control_msg(gspca_dev->dev, usb_sndctrlpipe(gspca_dev->dev, 0),
0x01, 0x40, 0x0001, 0x000F, NULL, 0, 500);
if (rc < 0) {
PERR("failed to replay packet 176 w/ rc %d\n", rc);
return rc;
}
rc = usb_control_msg(gspca_dev->dev, usb_sndctrlpipe(gspca_dev->dev, 0),
0x01, 0x40, 0x0000, 0x000F, NULL, 0, 500);
if (rc < 0) {
PERR("failed to replay packet 178 w/ rc %d\n", rc);
return rc;
}
rc = usb_control_msg(gspca_dev->dev, usb_sndctrlpipe(gspca_dev->dev, 0),
0x01, 0x40, 0x0001, 0x000F, NULL, 0, 500);
if (rc < 0) {
PERR("failed to replay packet 180 w/ rc %d\n", rc);
return rc;
}
gspca_dev->usb_err = 0;
configure_encrypted(gspca_dev);
if (gspca_dev->usb_err)
return gspca_dev->usb_err;
rc = usb_control_msg(gspca_dev->dev, usb_sndctrlpipe(gspca_dev->dev, 0),
0x01, 0x40, 0x0003, 0x000F, NULL, 0, 500);
if (rc < 0) {
PERR("failed to replay final packet w/ rc %d\n", rc);
return rc;
}
PDEBUG(D_STREAM, "Configure complete\n");
return 0;
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
gspca_dev->cam.cam_mode = vga_mode;
gspca_dev->cam.nmodes = ARRAY_SIZE(vga_mode);
gspca_dev->cam.no_urb_create = 0;
gspca_dev->cam.bulk_nurbs = 4;
gspca_dev->cam.bulk_size = BULK_SIZE;
gspca_dev->cam.bulk = 1;
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int rc;
sd->this_f = 0;
rc = configure(gspca_dev);
if (rc < 0) {
PERR("Failed configure");
return rc;
}
return 0;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
struct sd *sd = (struct sd *) gspca_dev;
if (len != BULK_SIZE) {
if (sd->this_f + len == gspca_dev->pixfmt.sizeimage) {
gspca_frame_add(gspca_dev, LAST_PACKET, data, len);
PDEBUG(D_FRAM, "finish frame sz %u/%u w/ len %u\n",
sd->this_f, gspca_dev->pixfmt.sizeimage, len);
} else {
gspca_frame_add(gspca_dev, DISCARD_PACKET, NULL, 0);
PDEBUG(D_FRAM, "abort frame sz %u/%u w/ len %u\n",
sd->this_f, gspca_dev->pixfmt.sizeimage, len);
}
sd->this_f = 0;
} else {
if (sd->this_f == 0)
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
else
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
sd->this_f += len;
}
}
static int sd_init(struct gspca_dev *gspca_dev)
{
return 0;
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *) gspca_dev;
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming)
return 0;
switch (ctrl->id) {
case V4L2_CID_EXPOSURE:
setexposure(gspca_dev, ctrl->val);
break;
case V4L2_CID_GAIN:
setggain(gspca_dev, gspca_dev->gain->val);
break;
case V4L2_CID_BLUE_BALANCE:
sd->blue->val = ctrl->val;
setbgain(gspca_dev, sd->blue->val, gspca_dev->gain->val);
break;
case V4L2_CID_RED_BALANCE:
sd->red->val = ctrl->val;
setrgain(gspca_dev, sd->red->val, gspca_dev->gain->val);
break;
}
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 4);
gspca_dev->exposure = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_EXPOSURE, 0, 800, 1, 350);
gspca_dev->gain = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_GAIN, 0, 511, 1, 128);
sd->blue = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BLUE_BALANCE, 0, 1023, 1, 80);
sd->red = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_RED_BALANCE, 0, 1023, 1, 295);
if (hdl->error) {
PERR("Could not initialize controls\n");
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
static int __init sd_mod_init(void)
{
int ret;
ret = usb_register(&sd_driver);
if (ret < 0)
return ret;
return 0;
}
static void __exit sd_mod_exit(void)
{
usb_deregister(&sd_driver);
}
