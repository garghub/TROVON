static int reg_write(struct usb_device *dev,
__u16 req, __u16 index, __u16 value)
{
int ret;
ret = usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
req,
USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, NULL, 0, 500);
PDEBUG(D_USBO, "reg write: 0x%02x 0x%02x 0x%02x",
req, index, value);
if (ret < 0)
pr_err("reg write: error %d\n", ret);
return ret;
}
static int write_vector(struct gspca_dev *gspca_dev,
const __u16 data[][3])
{
struct usb_device *dev = gspca_dev->dev;
int ret, i = 0;
while (data[i][0] != 0 || data[i][1] != 0 || data[i][2] != 0) {
ret = reg_write(dev, data[i][0], data[i][2], data[i][1]);
if (ret < 0) {
PDEBUG(D_ERR,
"Reg write failed for 0x%02x,0x%02x,0x%02x",
data[i][0], data[i][1], data[i][2]);
return ret;
}
i++;
}
return 0;
}
static void setbrightness(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x12, sd->brightness);
}
static void setcontrast(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_write(gspca_dev->dev, 0x00, 0x00,
(sd->contrast >> 8) & 0xff);
reg_write(gspca_dev->dev, 0x00, 0x01,
sd->contrast & 0xff);
}
static void setcolors(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x0c, sd->colors);
}
static void setblue_balance(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x11, sd->blue_balance);
}
static void setred_balance(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
reg_write(gspca_dev->dev, SPCA501_REG_CCDSP, 0x13, sd->red_balance);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
cam = &gspca_dev->cam;
cam->cam_mode = vga_mode;
cam->nmodes = ARRAY_SIZE(vga_mode);
sd->subtype = id->driver_info;
sd->brightness = sd_ctrls[MY_BRIGHTNESS].qctrl.default_value;
sd->contrast = sd_ctrls[MY_CONTRAST].qctrl.default_value;
sd->colors = sd_ctrls[MY_COLOR].qctrl.default_value;
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->subtype) {
case Arowana300KCMOSCamera:
case SmileIntlCamera:
if (write_vector(gspca_dev, spca501c_arowana_init_data))
goto error;
break;
case MystFromOriUnknownCamera:
if (write_vector(gspca_dev, spca501c_mysterious_open_data))
goto error;
break;
default:
if (write_vector(gspca_dev, spca501_init_data))
goto error;
break;
}
PDEBUG(D_STREAM, "Initializing SPCA501 finished");
return 0;
error:
return -EINVAL;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
struct usb_device *dev = gspca_dev->dev;
int mode;
switch (sd->subtype) {
case ThreeComHomeConnectLite:
write_vector(gspca_dev, spca501_3com_open_data);
break;
case Arowana300KCMOSCamera:
case SmileIntlCamera:
write_vector(gspca_dev, spca501c_arowana_open_data);
break;
case MystFromOriUnknownCamera:
write_vector(gspca_dev, spca501c_mysterious_init_data);
break;
default:
write_vector(gspca_dev, spca501_open_data);
}
mode = gspca_dev->cam.cam_mode[(int) gspca_dev->curr_mode].priv;
reg_write(dev, SPCA50X_REG_USB, 0x6, 0x94);
switch (mode) {
case 0:
reg_write(dev, SPCA50X_REG_USB, 0x07, 0x004a);
break;
case 1:
reg_write(dev, SPCA50X_REG_USB, 0x07, 0x104a);
break;
default:
reg_write(dev, SPCA50X_REG_USB, 0x07, 0x204a);
break;
}
reg_write(dev, SPCA501_REG_CTLRL, 0x01, 0x02);
setbrightness(gspca_dev);
setcontrast(gspca_dev);
setcolors(gspca_dev);
return 0;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
reg_write(gspca_dev->dev, SPCA501_REG_CTLRL, 0x01, 0x00);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
if (!gspca_dev->present)
return;
reg_write(gspca_dev->dev, SPCA501_REG_CTLRL, 0x05, 0x00);
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data,
int len)
{
switch (data[0]) {
case 0:
gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
data += SPCA501_OFFSET_DATA;
len -= SPCA501_OFFSET_DATA;
gspca_frame_add(gspca_dev, FIRST_PACKET, data, len);
return;
case 0xff:
return;
}
data++;
len--;
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
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
static int sd_setcolors(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->colors = val;
if (gspca_dev->streaming)
setcolors(gspca_dev);
return 0;
}
static int sd_getcolors(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->colors;
return 0;
}
static int sd_setblue_balance(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->blue_balance = val;
if (gspca_dev->streaming)
setblue_balance(gspca_dev);
return 0;
}
static int sd_getblue_balance(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->blue_balance;
return 0;
}
static int sd_setred_balance(struct gspca_dev *gspca_dev, __s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->red_balance = val;
if (gspca_dev->streaming)
setred_balance(gspca_dev);
return 0;
}
static int sd_getred_balance(struct gspca_dev *gspca_dev, __s32 *val)
{
struct sd *sd = (struct sd *) gspca_dev;
*val = sd->red_balance;
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
return usb_register(&sd_driver);
}
static void __exit sd_mod_exit(void)
{
usb_deregister(&sd_driver);
}
