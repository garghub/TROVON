static int cit_write_reg(struct gspca_dev *gspca_dev, u16 value, u16 index)
{
struct usb_device *udev = gspca_dev->dev;
int err;
err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x00,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_ENDPOINT,
value, index, NULL, 0, 1000);
if (err < 0)
pr_err("Failed to write a register (index 0x%04X, value 0x%02X, error %d)\n",
index, value, err);
return 0;
}
static int cit_read_reg(struct gspca_dev *gspca_dev, u16 index, int verbose)
{
struct usb_device *udev = gspca_dev->dev;
__u8 *buf = gspca_dev->usb_buf;
int res;
res = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0), 0x01,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_ENDPOINT,
0x00, index, buf, 8, 1000);
if (res < 0) {
pr_err("Failed to read a register (index 0x%04X, error %d)\n",
index, res);
return res;
}
if (verbose)
PDEBUG(D_PROBE, "Register %04x value: %02x", index, buf[0]);
return 0;
}
static void cit_send_FF_04_02(struct gspca_dev *gspca_dev)
{
cit_write_reg(gspca_dev, 0x00FF, 0x0127);
cit_write_reg(gspca_dev, 0x0004, 0x0124);
cit_write_reg(gspca_dev, 0x0002, 0x0124);
}
static void cit_send_00_04_06(struct gspca_dev *gspca_dev)
{
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0x0004, 0x0124);
cit_write_reg(gspca_dev, 0x0006, 0x0124);
}
static void cit_send_x_00(struct gspca_dev *gspca_dev, unsigned short x)
{
cit_write_reg(gspca_dev, x, 0x0127);
cit_write_reg(gspca_dev, 0x0000, 0x0124);
}
static void cit_send_x_00_05(struct gspca_dev *gspca_dev, unsigned short x)
{
cit_send_x_00(gspca_dev, x);
cit_write_reg(gspca_dev, 0x0005, 0x0124);
}
static void cit_send_x_00_05_02(struct gspca_dev *gspca_dev, unsigned short x)
{
cit_write_reg(gspca_dev, x, 0x0127);
cit_write_reg(gspca_dev, 0x0000, 0x0124);
cit_write_reg(gspca_dev, 0x0005, 0x0124);
cit_write_reg(gspca_dev, 0x0002, 0x0124);
}
static void cit_send_x_01_00_05(struct gspca_dev *gspca_dev, u16 x)
{
cit_write_reg(gspca_dev, x, 0x0127);
cit_write_reg(gspca_dev, 0x0001, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0124);
cit_write_reg(gspca_dev, 0x0005, 0x0124);
}
static void cit_send_x_00_05_02_01(struct gspca_dev *gspca_dev, u16 x)
{
cit_write_reg(gspca_dev, x, 0x0127);
cit_write_reg(gspca_dev, 0x0000, 0x0124);
cit_write_reg(gspca_dev, 0x0005, 0x0124);
cit_write_reg(gspca_dev, 0x0002, 0x0124);
cit_write_reg(gspca_dev, 0x0001, 0x0124);
}
static void cit_send_x_00_05_02_08_01(struct gspca_dev *gspca_dev, u16 x)
{
cit_write_reg(gspca_dev, x, 0x0127);
cit_write_reg(gspca_dev, 0x0000, 0x0124);
cit_write_reg(gspca_dev, 0x0005, 0x0124);
cit_write_reg(gspca_dev, 0x0002, 0x0124);
cit_write_reg(gspca_dev, 0x0008, 0x0124);
cit_write_reg(gspca_dev, 0x0001, 0x0124);
}
static void cit_Packet_Format1(struct gspca_dev *gspca_dev, u16 fkey, u16 val)
{
cit_send_x_01_00_05(gspca_dev, 0x0088);
cit_send_x_00_05(gspca_dev, fkey);
cit_send_x_00_05_02_08_01(gspca_dev, val);
cit_send_x_00_05(gspca_dev, 0x0088);
cit_send_x_00_05_02_01(gspca_dev, fkey);
cit_send_x_00_05(gspca_dev, 0x0089);
cit_send_x_00(gspca_dev, fkey);
cit_send_00_04_06(gspca_dev);
cit_read_reg(gspca_dev, 0x0126, 0);
cit_send_FF_04_02(gspca_dev);
}
static void cit_PacketFormat2(struct gspca_dev *gspca_dev, u16 fkey, u16 val)
{
cit_send_x_01_00_05(gspca_dev, 0x0088);
cit_send_x_00_05(gspca_dev, fkey);
cit_send_x_00_05_02(gspca_dev, val);
}
static void cit_model2_Packet2(struct gspca_dev *gspca_dev)
{
cit_write_reg(gspca_dev, 0x00ff, 0x012d);
cit_write_reg(gspca_dev, 0xfea3, 0x0124);
}
static void cit_model2_Packet1(struct gspca_dev *gspca_dev, u16 v1, u16 v2)
{
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x00ff, 0x012e);
cit_write_reg(gspca_dev, v1, 0x012f);
cit_write_reg(gspca_dev, 0x00ff, 0x0130);
cit_write_reg(gspca_dev, 0xc719, 0x0124);
cit_write_reg(gspca_dev, v2, 0x0127);
cit_model2_Packet2(gspca_dev);
}
static void cit_model3_Packet1(struct gspca_dev *gspca_dev, u16 v1, u16 v2)
{
cit_write_reg(gspca_dev, 0x0078, 0x012d);
cit_write_reg(gspca_dev, v1, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, v2, 0x0127);
cit_write_reg(gspca_dev, 0xfea8, 0x0124);
}
static void cit_model4_Packet1(struct gspca_dev *gspca_dev, u16 v1, u16 v2)
{
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, v1, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, v2, 0x0127);
cit_write_reg(gspca_dev, 0xfea8, 0x0124);
}
static void cit_model4_BrightnessPacket(struct gspca_dev *gspca_dev, u16 val)
{
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0026, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, val, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0038, 0x012d);
cit_write_reg(gspca_dev, 0x0004, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
}
static int sd_config(struct gspca_dev *gspca_dev,
const struct usb_device_id *id)
{
struct sd *sd = (struct sd *) gspca_dev;
struct cam *cam;
sd->model = id->driver_info;
if (sd->model == CIT_MODEL3 && ibm_netcam_pro)
sd->model = CIT_IBM_NETCAM_PRO;
cam = &gspca_dev->cam;
switch (sd->model) {
case CIT_MODEL0:
cam->cam_mode = model0_mode;
cam->nmodes = ARRAY_SIZE(model0_mode);
sd->sof_len = 4;
break;
case CIT_MODEL1:
cam->cam_mode = cif_yuv_mode;
cam->nmodes = ARRAY_SIZE(cif_yuv_mode);
sd->sof_len = 4;
break;
case CIT_MODEL2:
cam->cam_mode = model2_mode + 1;
cam->nmodes = 3;
break;
case CIT_MODEL3:
cam->cam_mode = vga_yuv_mode;
cam->nmodes = ARRAY_SIZE(vga_yuv_mode);
sd->stop_on_control_change = 1;
sd->sof_len = 4;
break;
case CIT_MODEL4:
cam->cam_mode = model2_mode;
cam->nmodes = ARRAY_SIZE(model2_mode);
break;
case CIT_IBM_NETCAM_PRO:
cam->cam_mode = vga_yuv_mode;
cam->nmodes = 2;
cam->input_flags = V4L2_IN_ST_VFLIP;
sd->stop_on_control_change = 1;
sd->sof_len = 4;
break;
}
return 0;
}
static int cit_init_model0(struct gspca_dev *gspca_dev)
{
cit_write_reg(gspca_dev, 0x0000, 0x0100);
cit_write_reg(gspca_dev, 0x0001, 0x0112);
cit_write_reg(gspca_dev, 0x0000, 0x0400);
cit_write_reg(gspca_dev, 0x0001, 0x0400);
cit_write_reg(gspca_dev, 0x0000, 0x0420);
cit_write_reg(gspca_dev, 0x0001, 0x0420);
cit_write_reg(gspca_dev, 0x000d, 0x0409);
cit_write_reg(gspca_dev, 0x0002, 0x040a);
cit_write_reg(gspca_dev, 0x0018, 0x0405);
cit_write_reg(gspca_dev, 0x0008, 0x0435);
cit_write_reg(gspca_dev, 0x0026, 0x040b);
cit_write_reg(gspca_dev, 0x0007, 0x0437);
cit_write_reg(gspca_dev, 0x0015, 0x042f);
cit_write_reg(gspca_dev, 0x002b, 0x0439);
cit_write_reg(gspca_dev, 0x0026, 0x043a);
cit_write_reg(gspca_dev, 0x0008, 0x0438);
cit_write_reg(gspca_dev, 0x001e, 0x042b);
cit_write_reg(gspca_dev, 0x0041, 0x042c);
return 0;
}
static int cit_init_ibm_netcam_pro(struct gspca_dev *gspca_dev)
{
cit_read_reg(gspca_dev, 0x128, 1);
cit_write_reg(gspca_dev, 0x0003, 0x0133);
cit_write_reg(gspca_dev, 0x0000, 0x0117);
cit_write_reg(gspca_dev, 0x0008, 0x0123);
cit_write_reg(gspca_dev, 0x0000, 0x0100);
cit_read_reg(gspca_dev, 0x0116, 0);
cit_write_reg(gspca_dev, 0x0060, 0x0116);
cit_write_reg(gspca_dev, 0x0002, 0x0112);
cit_write_reg(gspca_dev, 0x0000, 0x0133);
cit_write_reg(gspca_dev, 0x0000, 0x0123);
cit_write_reg(gspca_dev, 0x0001, 0x0117);
cit_write_reg(gspca_dev, 0x0040, 0x0108);
cit_write_reg(gspca_dev, 0x0019, 0x012c);
cit_write_reg(gspca_dev, 0x0060, 0x0116);
cit_write_reg(gspca_dev, 0x0002, 0x0115);
cit_write_reg(gspca_dev, 0x000b, 0x0115);
cit_write_reg(gspca_dev, 0x0078, 0x012d);
cit_write_reg(gspca_dev, 0x0001, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0079, 0x012d);
cit_write_reg(gspca_dev, 0x00ff, 0x0130);
cit_write_reg(gspca_dev, 0xcd41, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_read_reg(gspca_dev, 0x0126, 1);
cit_model3_Packet1(gspca_dev, 0x0000, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0000, 0x0001);
cit_model3_Packet1(gspca_dev, 0x000b, 0x0000);
cit_model3_Packet1(gspca_dev, 0x000c, 0x0008);
cit_model3_Packet1(gspca_dev, 0x000d, 0x003a);
cit_model3_Packet1(gspca_dev, 0x000e, 0x0060);
cit_model3_Packet1(gspca_dev, 0x000f, 0x0060);
cit_model3_Packet1(gspca_dev, 0x0010, 0x0008);
cit_model3_Packet1(gspca_dev, 0x0011, 0x0004);
cit_model3_Packet1(gspca_dev, 0x0012, 0x0028);
cit_model3_Packet1(gspca_dev, 0x0013, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0014, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0015, 0x00fb);
cit_model3_Packet1(gspca_dev, 0x0016, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0017, 0x0037);
cit_model3_Packet1(gspca_dev, 0x0018, 0x0036);
cit_model3_Packet1(gspca_dev, 0x001e, 0x0000);
cit_model3_Packet1(gspca_dev, 0x001f, 0x0008);
cit_model3_Packet1(gspca_dev, 0x0020, 0x00c1);
cit_model3_Packet1(gspca_dev, 0x0021, 0x0034);
cit_model3_Packet1(gspca_dev, 0x0022, 0x0034);
cit_model3_Packet1(gspca_dev, 0x0025, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0028, 0x0022);
cit_model3_Packet1(gspca_dev, 0x0029, 0x000a);
cit_model3_Packet1(gspca_dev, 0x002b, 0x0000);
cit_model3_Packet1(gspca_dev, 0x002c, 0x0000);
cit_model3_Packet1(gspca_dev, 0x002d, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x002e, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x002f, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x0030, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x0031, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x0032, 0x0007);
cit_model3_Packet1(gspca_dev, 0x0033, 0x0005);
cit_model3_Packet1(gspca_dev, 0x0037, 0x0040);
cit_model3_Packet1(gspca_dev, 0x0039, 0x0000);
cit_model3_Packet1(gspca_dev, 0x003a, 0x0000);
cit_model3_Packet1(gspca_dev, 0x003b, 0x0001);
cit_model3_Packet1(gspca_dev, 0x003c, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0040, 0x000c);
cit_model3_Packet1(gspca_dev, 0x0041, 0x00fb);
cit_model3_Packet1(gspca_dev, 0x0042, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0043, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0045, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0046, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0047, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0048, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0049, 0x0000);
cit_model3_Packet1(gspca_dev, 0x004a, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x004b, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x004c, 0x00ff);
cit_model3_Packet1(gspca_dev, 0x004f, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0050, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0051, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0055, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0056, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0057, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0058, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0059, 0x0000);
cit_model3_Packet1(gspca_dev, 0x005c, 0x0016);
cit_model3_Packet1(gspca_dev, 0x005d, 0x0022);
cit_model3_Packet1(gspca_dev, 0x005e, 0x003c);
cit_model3_Packet1(gspca_dev, 0x005f, 0x0050);
cit_model3_Packet1(gspca_dev, 0x0060, 0x0044);
cit_model3_Packet1(gspca_dev, 0x0061, 0x0005);
cit_model3_Packet1(gspca_dev, 0x006a, 0x007e);
cit_model3_Packet1(gspca_dev, 0x006f, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0072, 0x001b);
cit_model3_Packet1(gspca_dev, 0x0073, 0x0005);
cit_model3_Packet1(gspca_dev, 0x0074, 0x000a);
cit_model3_Packet1(gspca_dev, 0x0075, 0x001b);
cit_model3_Packet1(gspca_dev, 0x0076, 0x002a);
cit_model3_Packet1(gspca_dev, 0x0077, 0x003c);
cit_model3_Packet1(gspca_dev, 0x0078, 0x0050);
cit_model3_Packet1(gspca_dev, 0x007b, 0x0000);
cit_model3_Packet1(gspca_dev, 0x007c, 0x0011);
cit_model3_Packet1(gspca_dev, 0x007d, 0x0024);
cit_model3_Packet1(gspca_dev, 0x007e, 0x0043);
cit_model3_Packet1(gspca_dev, 0x007f, 0x005a);
cit_model3_Packet1(gspca_dev, 0x0084, 0x0020);
cit_model3_Packet1(gspca_dev, 0x0085, 0x0033);
cit_model3_Packet1(gspca_dev, 0x0086, 0x000a);
cit_model3_Packet1(gspca_dev, 0x0087, 0x0030);
cit_model3_Packet1(gspca_dev, 0x0088, 0x0070);
cit_model3_Packet1(gspca_dev, 0x008b, 0x0008);
cit_model3_Packet1(gspca_dev, 0x008f, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0090, 0x0006);
cit_model3_Packet1(gspca_dev, 0x0091, 0x0028);
cit_model3_Packet1(gspca_dev, 0x0092, 0x005a);
cit_model3_Packet1(gspca_dev, 0x0093, 0x0082);
cit_model3_Packet1(gspca_dev, 0x0096, 0x0014);
cit_model3_Packet1(gspca_dev, 0x0097, 0x0020);
cit_model3_Packet1(gspca_dev, 0x0098, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00b0, 0x0046);
cit_model3_Packet1(gspca_dev, 0x00b1, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00b2, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00b3, 0x0004);
cit_model3_Packet1(gspca_dev, 0x00b4, 0x0007);
cit_model3_Packet1(gspca_dev, 0x00b6, 0x0002);
cit_model3_Packet1(gspca_dev, 0x00b7, 0x0004);
cit_model3_Packet1(gspca_dev, 0x00bb, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00bc, 0x0001);
cit_model3_Packet1(gspca_dev, 0x00bd, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00bf, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00c0, 0x00c8);
cit_model3_Packet1(gspca_dev, 0x00c1, 0x0014);
cit_model3_Packet1(gspca_dev, 0x00c2, 0x0001);
cit_model3_Packet1(gspca_dev, 0x00c3, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00c4, 0x0004);
cit_model3_Packet1(gspca_dev, 0x00cb, 0x00bf);
cit_model3_Packet1(gspca_dev, 0x00cc, 0x00bf);
cit_model3_Packet1(gspca_dev, 0x00cd, 0x00bf);
cit_model3_Packet1(gspca_dev, 0x00ce, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00cf, 0x0020);
cit_model3_Packet1(gspca_dev, 0x00d0, 0x0040);
cit_model3_Packet1(gspca_dev, 0x00d1, 0x00bf);
cit_model3_Packet1(gspca_dev, 0x00d1, 0x00bf);
cit_model3_Packet1(gspca_dev, 0x00d2, 0x00bf);
cit_model3_Packet1(gspca_dev, 0x00d3, 0x00bf);
cit_model3_Packet1(gspca_dev, 0x00ea, 0x0008);
cit_model3_Packet1(gspca_dev, 0x00eb, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00ec, 0x00e8);
cit_model3_Packet1(gspca_dev, 0x00ed, 0x0001);
cit_model3_Packet1(gspca_dev, 0x00ef, 0x0022);
cit_model3_Packet1(gspca_dev, 0x00f0, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00f2, 0x0028);
cit_model3_Packet1(gspca_dev, 0x00f4, 0x0002);
cit_model3_Packet1(gspca_dev, 0x00f5, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00fa, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00fb, 0x0001);
cit_model3_Packet1(gspca_dev, 0x00fc, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00fd, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00fe, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00ff, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00be, 0x0003);
cit_model3_Packet1(gspca_dev, 0x00c8, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00c9, 0x0020);
cit_model3_Packet1(gspca_dev, 0x00ca, 0x0040);
cit_model3_Packet1(gspca_dev, 0x0053, 0x0001);
cit_model3_Packet1(gspca_dev, 0x0082, 0x000e);
cit_model3_Packet1(gspca_dev, 0x0083, 0x0020);
cit_model3_Packet1(gspca_dev, 0x0034, 0x003c);
cit_model3_Packet1(gspca_dev, 0x006e, 0x0055);
cit_model3_Packet1(gspca_dev, 0x0062, 0x0005);
cit_model3_Packet1(gspca_dev, 0x0063, 0x0008);
cit_model3_Packet1(gspca_dev, 0x0066, 0x000a);
cit_model3_Packet1(gspca_dev, 0x0067, 0x0006);
cit_model3_Packet1(gspca_dev, 0x006b, 0x0010);
cit_model3_Packet1(gspca_dev, 0x005a, 0x0001);
cit_model3_Packet1(gspca_dev, 0x005b, 0x000a);
cit_model3_Packet1(gspca_dev, 0x0023, 0x0006);
cit_model3_Packet1(gspca_dev, 0x0026, 0x0004);
cit_model3_Packet1(gspca_dev, 0x0036, 0x0069);
cit_model3_Packet1(gspca_dev, 0x0038, 0x0064);
cit_model3_Packet1(gspca_dev, 0x003d, 0x0003);
cit_model3_Packet1(gspca_dev, 0x003e, 0x0001);
cit_model3_Packet1(gspca_dev, 0x00b8, 0x0014);
cit_model3_Packet1(gspca_dev, 0x00b9, 0x0014);
cit_model3_Packet1(gspca_dev, 0x00e6, 0x0004);
cit_model3_Packet1(gspca_dev, 0x00e8, 0x0001);
return 0;
}
static int sd_init(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->model) {
case CIT_MODEL0:
cit_init_model0(gspca_dev);
sd_stop0(gspca_dev);
break;
case CIT_MODEL1:
case CIT_MODEL2:
case CIT_MODEL3:
case CIT_MODEL4:
break;
case CIT_IBM_NETCAM_PRO:
cit_init_ibm_netcam_pro(gspca_dev);
sd_stop0(gspca_dev);
break;
}
return 0;
}
static int cit_set_brightness(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
int i;
switch (sd->model) {
case CIT_MODEL0:
case CIT_IBM_NETCAM_PRO:
break;
case CIT_MODEL1:
cit_Packet_Format1(gspca_dev, 0x0031, val);
cit_Packet_Format1(gspca_dev, 0x0032, val);
cit_Packet_Format1(gspca_dev, 0x0033, val);
break;
case CIT_MODEL2:
i = 0x60 + val * 2254 / 1000;
cit_model2_Packet1(gspca_dev, 0x001a, i);
break;
case CIT_MODEL3:
i = val;
if (i < 0x0c)
i = 0x0c;
cit_model3_Packet1(gspca_dev, 0x0036, i);
break;
case CIT_MODEL4:
i = 0x04 + val * 2794 / 1000;
cit_model4_BrightnessPacket(gspca_dev, i);
break;
}
return 0;
}
static int cit_set_contrast(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->model) {
case CIT_MODEL0: {
int i;
i = val * 1000 / 1333;
cit_write_reg(gspca_dev, i, 0x0422);
i = val * 2000 / 1333;
cit_write_reg(gspca_dev, i, 0x0423);
i = val * 4000 / 1333;
cit_write_reg(gspca_dev, i, 0x0424);
i = val * 8000 / 1333;
cit_write_reg(gspca_dev, i, 0x0425);
break;
}
case CIT_MODEL2:
case CIT_MODEL4:
break;
case CIT_MODEL1:
{
int i, new_contrast = (20 - val) * 1000 / 1333;
for (i = 0; i < cit_model1_ntries; i++) {
cit_Packet_Format1(gspca_dev, 0x0014, new_contrast);
cit_send_FF_04_02(gspca_dev);
}
break;
}
case CIT_MODEL3:
{
static const struct {
unsigned short cv1;
unsigned short cv2;
unsigned short cv3;
} cv[7] = {
{ 0x05, 0x05, 0x0f },
{ 0x04, 0x04, 0x16 },
{ 0x02, 0x03, 0x16 },
{ 0x02, 0x08, 0x16 },
{ 0x01, 0x0c, 0x16 },
{ 0x01, 0x0e, 0x16 },
{ 0x01, 0x10, 0x16 }
};
int i = val / 3;
cit_model3_Packet1(gspca_dev, 0x0067, cv[i].cv1);
cit_model3_Packet1(gspca_dev, 0x005b, cv[i].cv2);
cit_model3_Packet1(gspca_dev, 0x005c, cv[i].cv3);
break;
}
case CIT_IBM_NETCAM_PRO:
cit_model3_Packet1(gspca_dev, 0x005b, val + 1);
break;
}
return 0;
}
static int cit_set_hue(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->model) {
case CIT_MODEL0:
case CIT_MODEL1:
case CIT_IBM_NETCAM_PRO:
break;
case CIT_MODEL2:
cit_model2_Packet1(gspca_dev, 0x0024, val);
break;
case CIT_MODEL3: {
if (0) {
int i = 0x05 + val * 1000 / 2540;
cit_model3_Packet1(gspca_dev, 0x007e, i);
}
break;
}
case CIT_MODEL4:
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x001e, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 160, 0x0127);
cit_write_reg(gspca_dev, 160, 0x012e);
cit_write_reg(gspca_dev, 160, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, val, 0x012d);
cit_write_reg(gspca_dev, 0xf545, 0x0124);
break;
}
return 0;
}
static int cit_set_sharpness(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->model) {
case CIT_MODEL0:
case CIT_MODEL2:
case CIT_MODEL4:
case CIT_IBM_NETCAM_PRO:
break;
case CIT_MODEL1: {
int i;
const unsigned short sa[] = {
0x11, 0x13, 0x16, 0x18, 0x1a, 0x8, 0x0a };
for (i = 0; i < cit_model1_ntries; i++)
cit_PacketFormat2(gspca_dev, 0x0013, sa[val]);
break;
}
case CIT_MODEL3:
{
static const struct {
unsigned short sv1;
unsigned short sv2;
unsigned short sv3;
unsigned short sv4;
} sv[7] = {
{ 0x00, 0x00, 0x05, 0x14 },
{ 0x01, 0x04, 0x05, 0x14 },
{ 0x02, 0x04, 0x05, 0x14 },
{ 0x03, 0x04, 0x05, 0x14 },
{ 0x03, 0x05, 0x05, 0x14 },
{ 0x03, 0x06, 0x05, 0x14 },
{ 0x03, 0x07, 0x05, 0x14 }
};
cit_model3_Packet1(gspca_dev, 0x0060, sv[val].sv1);
cit_model3_Packet1(gspca_dev, 0x0061, sv[val].sv2);
cit_model3_Packet1(gspca_dev, 0x0062, sv[val].sv3);
cit_model3_Packet1(gspca_dev, 0x0063, sv[val].sv4);
break;
}
}
return 0;
}
static void cit_set_lighting(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->model) {
case CIT_MODEL0:
case CIT_MODEL2:
case CIT_MODEL3:
case CIT_MODEL4:
case CIT_IBM_NETCAM_PRO:
break;
case CIT_MODEL1: {
int i;
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x0027, val);
break;
}
}
}
static void cit_set_hflip(struct gspca_dev *gspca_dev, s32 val)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->model) {
case CIT_MODEL0:
if (val)
cit_write_reg(gspca_dev, 0x0020, 0x0115);
else
cit_write_reg(gspca_dev, 0x0040, 0x0115);
break;
case CIT_MODEL1:
case CIT_MODEL2:
case CIT_MODEL3:
case CIT_MODEL4:
case CIT_IBM_NETCAM_PRO:
break;
}
}
static int cit_restart_stream(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
switch (sd->model) {
case CIT_MODEL0:
case CIT_MODEL1:
cit_write_reg(gspca_dev, 0x0001, 0x0114);
case CIT_MODEL2:
case CIT_MODEL4:
cit_write_reg(gspca_dev, 0x00c0, 0x010c);
usb_clear_halt(gspca_dev->dev, gspca_dev->urb[0]->pipe);
break;
case CIT_MODEL3:
case CIT_IBM_NETCAM_PRO:
cit_write_reg(gspca_dev, 0x0001, 0x0114);
cit_write_reg(gspca_dev, 0x00c0, 0x010c);
usb_clear_halt(gspca_dev->dev, gspca_dev->urb[0]->pipe);
cit_write_reg(gspca_dev, 0x0001, 0x0113);
break;
}
sd->sof_read = 0;
return 0;
}
static int cit_get_packet_size(struct gspca_dev *gspca_dev)
{
struct usb_host_interface *alt;
struct usb_interface *intf;
intf = usb_ifnum_to_if(gspca_dev->dev, gspca_dev->iface);
alt = usb_altnum_to_altsetting(intf, gspca_dev->alt);
if (!alt) {
pr_err("Couldn't get altsetting\n");
return -EIO;
}
return le16_to_cpu(alt->endpoint[0].desc.wMaxPacketSize);
}
static int cit_get_clock_div(struct gspca_dev *gspca_dev)
{
int clock_div = 7;
int fps[8] = { 30, 25, 20, 15, 12, 8, 6, 3 };
int packet_size;
packet_size = cit_get_packet_size(gspca_dev);
if (packet_size < 0)
return packet_size;
while (clock_div > 3 &&
1000 * packet_size >
gspca_dev->width * gspca_dev->height *
fps[clock_div - 1] * 3 / 2)
clock_div--;
PDEBUG(D_PROBE,
"PacketSize: %d, res: %dx%d -> using clockdiv: %d (%d fps)",
packet_size, gspca_dev->width, gspca_dev->height, clock_div,
fps[clock_div]);
return clock_div;
}
static int cit_start_model0(struct gspca_dev *gspca_dev)
{
const unsigned short compression = 0;
int clock_div;
clock_div = cit_get_clock_div(gspca_dev);
if (clock_div < 0)
return clock_div;
cit_write_reg(gspca_dev, 0x0000, 0x0100);
cit_write_reg(gspca_dev, 0x0003, 0x0438);
cit_write_reg(gspca_dev, 0x001e, 0x042b);
cit_write_reg(gspca_dev, 0x0041, 0x042c);
cit_write_reg(gspca_dev, 0x0008, 0x0436);
cit_write_reg(gspca_dev, 0x0024, 0x0403);
cit_write_reg(gspca_dev, 0x002c, 0x0404);
cit_write_reg(gspca_dev, 0x0002, 0x0426);
cit_write_reg(gspca_dev, 0x0014, 0x0427);
switch (gspca_dev->width) {
case 160:
cit_write_reg(gspca_dev, 0x0004, 0x010b);
cit_write_reg(gspca_dev, 0x0001, 0x010a);
cit_write_reg(gspca_dev, 0x0010, 0x0102);
cit_write_reg(gspca_dev, 0x00a0, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x0078, 0x0105);
break;
case 176:
cit_write_reg(gspca_dev, 0x0006, 0x010b);
cit_write_reg(gspca_dev, 0x0000, 0x010a);
cit_write_reg(gspca_dev, 0x0005, 0x0102);
cit_write_reg(gspca_dev, 0x00b0, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x0090, 0x0105);
break;
case 320:
cit_write_reg(gspca_dev, 0x0008, 0x010b);
cit_write_reg(gspca_dev, 0x0004, 0x010a);
cit_write_reg(gspca_dev, 0x0005, 0x0102);
cit_write_reg(gspca_dev, 0x00a0, 0x0103);
cit_write_reg(gspca_dev, 0x0010, 0x0104);
cit_write_reg(gspca_dev, 0x0078, 0x0105);
break;
}
cit_write_reg(gspca_dev, compression, 0x0109);
cit_write_reg(gspca_dev, clock_div, 0x0111);
return 0;
}
static int cit_start_model1(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int i, clock_div;
clock_div = cit_get_clock_div(gspca_dev);
if (clock_div < 0)
return clock_div;
cit_read_reg(gspca_dev, 0x0128, 1);
cit_read_reg(gspca_dev, 0x0100, 0);
cit_write_reg(gspca_dev, 0x01, 0x0100);
cit_read_reg(gspca_dev, 0x0100, 0);
cit_write_reg(gspca_dev, 0x81, 0x0100);
cit_read_reg(gspca_dev, 0x0100, 0);
cit_write_reg(gspca_dev, 0x01, 0x0100);
cit_write_reg(gspca_dev, 0x01, 0x0108);
cit_write_reg(gspca_dev, 0x03, 0x0112);
cit_read_reg(gspca_dev, 0x0115, 0);
cit_write_reg(gspca_dev, 0x06, 0x0115);
cit_read_reg(gspca_dev, 0x0116, 0);
cit_write_reg(gspca_dev, 0x44, 0x0116);
cit_read_reg(gspca_dev, 0x0116, 0);
cit_write_reg(gspca_dev, 0x40, 0x0116);
cit_read_reg(gspca_dev, 0x0115, 0);
cit_write_reg(gspca_dev, 0x0e, 0x0115);
cit_write_reg(gspca_dev, 0x19, 0x012c);
cit_Packet_Format1(gspca_dev, 0x00, 0x1e);
cit_Packet_Format1(gspca_dev, 0x39, 0x0d);
cit_Packet_Format1(gspca_dev, 0x39, 0x09);
cit_Packet_Format1(gspca_dev, 0x3b, 0x00);
cit_Packet_Format1(gspca_dev, 0x28, 0x22);
cit_Packet_Format1(gspca_dev, 0x27, 0x00);
cit_Packet_Format1(gspca_dev, 0x2b, 0x1f);
cit_Packet_Format1(gspca_dev, 0x39, 0x08);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x2c, 0x00);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x30, 0x14);
cit_PacketFormat2(gspca_dev, 0x39, 0x02);
cit_PacketFormat2(gspca_dev, 0x01, 0xe1);
cit_PacketFormat2(gspca_dev, 0x02, 0xcd);
cit_PacketFormat2(gspca_dev, 0x03, 0xcd);
cit_PacketFormat2(gspca_dev, 0x04, 0xfa);
cit_PacketFormat2(gspca_dev, 0x3f, 0xff);
cit_PacketFormat2(gspca_dev, 0x39, 0x00);
cit_PacketFormat2(gspca_dev, 0x39, 0x02);
cit_PacketFormat2(gspca_dev, 0x0a, 0x37);
cit_PacketFormat2(gspca_dev, 0x0b, 0xb8);
cit_PacketFormat2(gspca_dev, 0x0c, 0xf3);
cit_PacketFormat2(gspca_dev, 0x0d, 0xe3);
cit_PacketFormat2(gspca_dev, 0x0e, 0x0d);
cit_PacketFormat2(gspca_dev, 0x0f, 0xf2);
cit_PacketFormat2(gspca_dev, 0x10, 0xd5);
cit_PacketFormat2(gspca_dev, 0x11, 0xba);
cit_PacketFormat2(gspca_dev, 0x12, 0x53);
cit_PacketFormat2(gspca_dev, 0x3f, 0xff);
cit_PacketFormat2(gspca_dev, 0x39, 0x00);
cit_PacketFormat2(gspca_dev, 0x39, 0x02);
cit_PacketFormat2(gspca_dev, 0x16, 0x00);
cit_PacketFormat2(gspca_dev, 0x17, 0x28);
cit_PacketFormat2(gspca_dev, 0x18, 0x7d);
cit_PacketFormat2(gspca_dev, 0x19, 0xbe);
cit_PacketFormat2(gspca_dev, 0x3f, 0xff);
cit_PacketFormat2(gspca_dev, 0x39, 0x00);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x00, 0x18);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x13, 0x18);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x14, 0x06);
if (0) {
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x31, 0x37);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x32, 0x46);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x33, 0x55);
}
cit_Packet_Format1(gspca_dev, 0x2e, 0x04);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x2d, 0x04);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x29, 0x80);
cit_Packet_Format1(gspca_dev, 0x2c, 0x01);
cit_Packet_Format1(gspca_dev, 0x30, 0x17);
cit_Packet_Format1(gspca_dev, 0x39, 0x08);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x34, 0x00);
cit_write_reg(gspca_dev, 0x00, 0x0101);
cit_write_reg(gspca_dev, 0x00, 0x010a);
switch (gspca_dev->width) {
case 128:
cit_write_reg(gspca_dev, 0x80, 0x0103);
cit_write_reg(gspca_dev, 0x60, 0x0105);
cit_write_reg(gspca_dev, 0x0c, 0x010b);
cit_write_reg(gspca_dev, 0x04, 0x011b);
cit_write_reg(gspca_dev, 0x0b, 0x011d);
cit_write_reg(gspca_dev, 0x00, 0x011e);
cit_write_reg(gspca_dev, 0x00, 0x0129);
break;
case 176:
cit_write_reg(gspca_dev, 0xb0, 0x0103);
cit_write_reg(gspca_dev, 0x8f, 0x0105);
cit_write_reg(gspca_dev, 0x06, 0x010b);
cit_write_reg(gspca_dev, 0x04, 0x011b);
cit_write_reg(gspca_dev, 0x0d, 0x011d);
cit_write_reg(gspca_dev, 0x00, 0x011e);
cit_write_reg(gspca_dev, 0x03, 0x0129);
break;
case 352:
cit_write_reg(gspca_dev, 0xb0, 0x0103);
cit_write_reg(gspca_dev, 0x90, 0x0105);
cit_write_reg(gspca_dev, 0x02, 0x010b);
cit_write_reg(gspca_dev, 0x04, 0x011b);
cit_write_reg(gspca_dev, 0x05, 0x011d);
cit_write_reg(gspca_dev, 0x00, 0x011e);
cit_write_reg(gspca_dev, 0x00, 0x0129);
break;
}
cit_write_reg(gspca_dev, 0xff, 0x012b);
if (0) {
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x31, 0xc3);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x32, 0xd2);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x33, 0xe1);
for (i = 0; i < cit_model1_ntries; i++)
cit_Packet_Format1(gspca_dev, 0x14, 0x0a);
for (i = 0; i < cit_model1_ntries2; i++)
cit_PacketFormat2(gspca_dev, 0x13, 0x1a);
cit_Packet_Format1(gspca_dev, 0x0027,
v4l2_ctrl_g_ctrl(sd->lighting));
}
switch (gspca_dev->width) {
case 128:
cit_Packet_Format1(gspca_dev, 0x2b, 0x1e);
cit_write_reg(gspca_dev, 0xc9, 0x0119);
cit_write_reg(gspca_dev, 0x80, 0x0109);
cit_write_reg(gspca_dev, 0x36, 0x0102);
cit_write_reg(gspca_dev, 0x1a, 0x0104);
cit_write_reg(gspca_dev, 0x04, 0x011a);
cit_write_reg(gspca_dev, 0x2b, 0x011c);
cit_write_reg(gspca_dev, 0x23, 0x012a);
break;
case 176:
cit_Packet_Format1(gspca_dev, 0x2b, 0x1e);
cit_write_reg(gspca_dev, 0xc9, 0x0119);
cit_write_reg(gspca_dev, 0x80, 0x0109);
cit_write_reg(gspca_dev, 0x04, 0x0102);
cit_write_reg(gspca_dev, 0x02, 0x0104);
cit_write_reg(gspca_dev, 0x04, 0x011a);
cit_write_reg(gspca_dev, 0x2b, 0x011c);
cit_write_reg(gspca_dev, 0x23, 0x012a);
break;
case 352:
cit_Packet_Format1(gspca_dev, 0x2b, 0x1f);
cit_write_reg(gspca_dev, 0xc9, 0x0119);
cit_write_reg(gspca_dev, 0x80, 0x0109);
cit_write_reg(gspca_dev, 0x08, 0x0102);
cit_write_reg(gspca_dev, 0x01, 0x0104);
cit_write_reg(gspca_dev, 0x04, 0x011a);
cit_write_reg(gspca_dev, 0x2f, 0x011c);
cit_write_reg(gspca_dev, 0x23, 0x012a);
break;
}
cit_write_reg(gspca_dev, 0x01, 0x0100);
cit_write_reg(gspca_dev, clock_div, 0x0111);
return 0;
}
static int cit_start_model2(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int clock_div = 0;
cit_write_reg(gspca_dev, 0x0000, 0x0100);
cit_read_reg(gspca_dev, 0x0116, 0);
cit_write_reg(gspca_dev, 0x0060, 0x0116);
cit_write_reg(gspca_dev, 0x0002, 0x0112);
cit_write_reg(gspca_dev, 0x00bc, 0x012c);
cit_write_reg(gspca_dev, 0x0008, 0x012b);
cit_write_reg(gspca_dev, 0x0000, 0x0108);
cit_write_reg(gspca_dev, 0x0001, 0x0133);
cit_write_reg(gspca_dev, 0x0001, 0x0102);
switch (gspca_dev->width) {
case 176:
cit_write_reg(gspca_dev, 0x002c, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x0024, 0x0105);
cit_write_reg(gspca_dev, 0x00b9, 0x010a);
cit_write_reg(gspca_dev, 0x0038, 0x0119);
sd->sof_len = 10;
break;
case 320:
cit_write_reg(gspca_dev, 0x0028, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x001e, 0x0105);
cit_write_reg(gspca_dev, 0x0039, 0x010a);
cit_write_reg(gspca_dev, 0x0070, 0x0119);
sd->sof_len = 2;
break;
cit_write_reg(gspca_dev, 0x002c, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x001e, 0x0105);
cit_write_reg(gspca_dev, 0x0039, 0x010a);
cit_write_reg(gspca_dev, 0x0070, 0x0119);
sd->sof_len = 2;
break;
case 352:
cit_write_reg(gspca_dev, 0x002c, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x0024, 0x0105);
cit_write_reg(gspca_dev, 0x0039, 0x010a);
cit_write_reg(gspca_dev, 0x0070, 0x0119);
sd->sof_len = 2;
break;
}
cit_write_reg(gspca_dev, 0x0000, 0x0100);
switch (gspca_dev->width) {
case 176:
cit_write_reg(gspca_dev, 0x0050, 0x0111);
cit_write_reg(gspca_dev, 0x00d0, 0x0111);
break;
case 320:
case 352:
cit_write_reg(gspca_dev, 0x0040, 0x0111);
cit_write_reg(gspca_dev, 0x00c0, 0x0111);
break;
}
cit_write_reg(gspca_dev, 0x009b, 0x010f);
cit_write_reg(gspca_dev, 0x00bb, 0x010f);
cit_model2_Packet1(gspca_dev, 0x000a, 0x005c);
cit_model2_Packet1(gspca_dev, 0x0004, 0x0000);
cit_model2_Packet1(gspca_dev, 0x0006, 0x00fb);
cit_model2_Packet1(gspca_dev, 0x0008, 0x0000);
cit_model2_Packet1(gspca_dev, 0x000c, 0x0009);
cit_model2_Packet1(gspca_dev, 0x0012, 0x000a);
cit_model2_Packet1(gspca_dev, 0x002a, 0x0000);
cit_model2_Packet1(gspca_dev, 0x002c, 0x0000);
cit_model2_Packet1(gspca_dev, 0x002e, 0x0008);
cit_model2_Packet1(gspca_dev, 0x0030, 0x0000);
switch (gspca_dev->width) {
case 176:
cit_model2_Packet1(gspca_dev, 0x0014, 0x0002);
cit_model2_Packet1(gspca_dev, 0x0016, 0x0002);
cit_model2_Packet1(gspca_dev, 0x0018, 0x004a);
clock_div = 6;
break;
case 320:
cit_model2_Packet1(gspca_dev, 0x0014, 0x0009);
cit_model2_Packet1(gspca_dev, 0x0016, 0x0005);
cit_model2_Packet1(gspca_dev, 0x0018, 0x0044);
clock_div = 8;
break;
cit_model2_Packet1(gspca_dev, 0x0014, 0x0009);
cit_model2_Packet1(gspca_dev, 0x0016, 0x0003);
cit_model2_Packet1(gspca_dev, 0x0018, 0x0044);
clock_div = 10;
break;
case 352:
cit_model2_Packet1(gspca_dev, 0x0014, 0x0003);
cit_model2_Packet1(gspca_dev, 0x0016, 0x0002);
cit_model2_Packet1(gspca_dev, 0x0018, 0x004a);
clock_div = 16;
break;
}
if (0)
cit_model2_Packet1(gspca_dev, 0x001a, 0x005a);
cit_model2_Packet1(gspca_dev, 0x001c, clock_div);
switch (gspca_dev->width) {
case 176:
cit_model2_Packet1(gspca_dev, 0x0026, 0x00c2);
break;
case 320:
cit_model2_Packet1(gspca_dev, 0x0026, 0x0044);
break;
cit_model2_Packet1(gspca_dev, 0x0026, 0x0046);
break;
case 352:
cit_model2_Packet1(gspca_dev, 0x0026, 0x0048);
break;
}
cit_model2_Packet1(gspca_dev, 0x0028, v4l2_ctrl_g_ctrl(sd->lighting));
v4l2_ctrl_grab(sd->lighting, true);
cit_model2_Packet1(gspca_dev, 0x001e, 0x002f);
cit_model2_Packet1(gspca_dev, 0x0020, 0x0034);
cit_model2_Packet1(gspca_dev, 0x0022, 0x00a0);
cit_model2_Packet1(gspca_dev, 0x0030, 0x0004);
return 0;
}
static int cit_start_model3(struct gspca_dev *gspca_dev)
{
const unsigned short compression = 0;
int i, clock_div = 0;
cit_read_reg(gspca_dev, 0x128, 1);
cit_write_reg(gspca_dev, 0x0000, 0x0100);
cit_read_reg(gspca_dev, 0x0116, 0);
cit_write_reg(gspca_dev, 0x0060, 0x0116);
cit_write_reg(gspca_dev, 0x0002, 0x0112);
cit_write_reg(gspca_dev, 0x0000, 0x0123);
cit_write_reg(gspca_dev, 0x0001, 0x0117);
cit_write_reg(gspca_dev, 0x0040, 0x0108);
cit_write_reg(gspca_dev, 0x0019, 0x012c);
cit_write_reg(gspca_dev, 0x0060, 0x0116);
cit_write_reg(gspca_dev, 0x0002, 0x0115);
cit_write_reg(gspca_dev, 0x0003, 0x0115);
cit_read_reg(gspca_dev, 0x0115, 0);
cit_write_reg(gspca_dev, 0x000b, 0x0115);
if (0) {
cit_write_reg(gspca_dev, 0x0078, 0x012d);
cit_write_reg(gspca_dev, 0x0001, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0079, 0x012d);
cit_write_reg(gspca_dev, 0x00ff, 0x0130);
cit_write_reg(gspca_dev, 0xcd41, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_read_reg(gspca_dev, 0x0126, 1);
}
cit_model3_Packet1(gspca_dev, 0x000a, 0x0040);
cit_model3_Packet1(gspca_dev, 0x000b, 0x00f6);
cit_model3_Packet1(gspca_dev, 0x000c, 0x0002);
cit_model3_Packet1(gspca_dev, 0x000d, 0x0020);
cit_model3_Packet1(gspca_dev, 0x000e, 0x0033);
cit_model3_Packet1(gspca_dev, 0x000f, 0x0007);
cit_model3_Packet1(gspca_dev, 0x0010, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0011, 0x0070);
cit_model3_Packet1(gspca_dev, 0x0012, 0x0030);
cit_model3_Packet1(gspca_dev, 0x0013, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0014, 0x0001);
cit_model3_Packet1(gspca_dev, 0x0015, 0x0001);
cit_model3_Packet1(gspca_dev, 0x0016, 0x0001);
cit_model3_Packet1(gspca_dev, 0x0017, 0x0001);
cit_model3_Packet1(gspca_dev, 0x0018, 0x0000);
cit_model3_Packet1(gspca_dev, 0x001e, 0x00c3);
cit_model3_Packet1(gspca_dev, 0x0020, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0028, 0x0010);
cit_model3_Packet1(gspca_dev, 0x0029, 0x0054);
cit_model3_Packet1(gspca_dev, 0x002a, 0x0013);
cit_model3_Packet1(gspca_dev, 0x002b, 0x0007);
cit_model3_Packet1(gspca_dev, 0x002d, 0x0028);
cit_model3_Packet1(gspca_dev, 0x002e, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0031, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0032, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0033, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0034, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0035, 0x0038);
cit_model3_Packet1(gspca_dev, 0x003a, 0x0001);
cit_model3_Packet1(gspca_dev, 0x003c, 0x001e);
cit_model3_Packet1(gspca_dev, 0x003f, 0x000a);
cit_model3_Packet1(gspca_dev, 0x0041, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0046, 0x003f);
cit_model3_Packet1(gspca_dev, 0x0047, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0050, 0x0005);
cit_model3_Packet1(gspca_dev, 0x0052, 0x001a);
cit_model3_Packet1(gspca_dev, 0x0053, 0x0003);
cit_model3_Packet1(gspca_dev, 0x005a, 0x006b);
cit_model3_Packet1(gspca_dev, 0x005d, 0x001e);
cit_model3_Packet1(gspca_dev, 0x005e, 0x0030);
cit_model3_Packet1(gspca_dev, 0x005f, 0x0041);
cit_model3_Packet1(gspca_dev, 0x0064, 0x0008);
cit_model3_Packet1(gspca_dev, 0x0065, 0x0015);
cit_model3_Packet1(gspca_dev, 0x0068, 0x000f);
cit_model3_Packet1(gspca_dev, 0x0079, 0x0000);
cit_model3_Packet1(gspca_dev, 0x007a, 0x0000);
cit_model3_Packet1(gspca_dev, 0x007c, 0x003f);
cit_model3_Packet1(gspca_dev, 0x0082, 0x000f);
cit_model3_Packet1(gspca_dev, 0x0085, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0099, 0x0000);
cit_model3_Packet1(gspca_dev, 0x009b, 0x0023);
cit_model3_Packet1(gspca_dev, 0x009c, 0x0022);
cit_model3_Packet1(gspca_dev, 0x009d, 0x0096);
cit_model3_Packet1(gspca_dev, 0x009e, 0x0096);
cit_model3_Packet1(gspca_dev, 0x009f, 0x000a);
switch (gspca_dev->width) {
case 160:
cit_write_reg(gspca_dev, 0x0000, 0x0101);
cit_write_reg(gspca_dev, 0x00a0, 0x0103);
cit_write_reg(gspca_dev, 0x0078, 0x0105);
cit_write_reg(gspca_dev, 0x0000, 0x010a);
cit_write_reg(gspca_dev, 0x0024, 0x010b);
cit_write_reg(gspca_dev, 0x00a9, 0x0119);
cit_write_reg(gspca_dev, 0x0016, 0x011b);
cit_write_reg(gspca_dev, 0x0002, 0x011d);
cit_write_reg(gspca_dev, 0x0003, 0x011e);
cit_write_reg(gspca_dev, 0x0000, 0x0129);
cit_write_reg(gspca_dev, 0x00fc, 0x012b);
cit_write_reg(gspca_dev, 0x0018, 0x0102);
cit_write_reg(gspca_dev, 0x0004, 0x0104);
cit_write_reg(gspca_dev, 0x0004, 0x011a);
cit_write_reg(gspca_dev, 0x0028, 0x011c);
cit_write_reg(gspca_dev, 0x0022, 0x012a);
cit_write_reg(gspca_dev, 0x0000, 0x0118);
cit_write_reg(gspca_dev, 0x0000, 0x0132);
cit_model3_Packet1(gspca_dev, 0x0021, 0x0001);
cit_write_reg(gspca_dev, compression, 0x0109);
clock_div = 3;
break;
case 320:
cit_write_reg(gspca_dev, 0x0000, 0x0101);
cit_write_reg(gspca_dev, 0x00a0, 0x0103);
cit_write_reg(gspca_dev, 0x0078, 0x0105);
cit_write_reg(gspca_dev, 0x0000, 0x010a);
cit_write_reg(gspca_dev, 0x0028, 0x010b);
cit_write_reg(gspca_dev, 0x0002, 0x011d);
cit_write_reg(gspca_dev, 0x0000, 0x011e);
cit_write_reg(gspca_dev, 0x0000, 0x0129);
cit_write_reg(gspca_dev, 0x00fc, 0x012b);
cit_write_reg(gspca_dev, 0x0022, 0x012a);
cit_model3_Packet1(gspca_dev, 0x0021, 0x0001);
cit_write_reg(gspca_dev, compression, 0x0109);
cit_write_reg(gspca_dev, 0x00d9, 0x0119);
cit_write_reg(gspca_dev, 0x0006, 0x011b);
cit_write_reg(gspca_dev, 0x0021, 0x0102);
cit_write_reg(gspca_dev, 0x0010, 0x0104);
cit_write_reg(gspca_dev, 0x0004, 0x011a);
cit_write_reg(gspca_dev, 0x003f, 0x011c);
cit_write_reg(gspca_dev, 0x001c, 0x0118);
cit_write_reg(gspca_dev, 0x0000, 0x0132);
clock_div = 5;
break;
case 640:
cit_write_reg(gspca_dev, 0x00f0, 0x0105);
cit_write_reg(gspca_dev, 0x0000, 0x010a);
cit_write_reg(gspca_dev, 0x0038, 0x010b);
cit_write_reg(gspca_dev, 0x00d9, 0x0119);
cit_write_reg(gspca_dev, 0x0006, 0x011b);
cit_write_reg(gspca_dev, 0x0004, 0x011d);
cit_write_reg(gspca_dev, 0x0003, 0x011e);
cit_write_reg(gspca_dev, 0x0000, 0x0129);
cit_write_reg(gspca_dev, 0x00fc, 0x012b);
cit_write_reg(gspca_dev, 0x0021, 0x0102);
cit_write_reg(gspca_dev, 0x0016, 0x0104);
cit_write_reg(gspca_dev, 0x0004, 0x011a);
cit_write_reg(gspca_dev, 0x003f, 0x011c);
cit_write_reg(gspca_dev, 0x0022, 0x012a);
cit_write_reg(gspca_dev, 0x001c, 0x0118);
cit_model3_Packet1(gspca_dev, 0x0021, 0x0001);
cit_write_reg(gspca_dev, compression, 0x0109);
cit_write_reg(gspca_dev, 0x0040, 0x0101);
cit_write_reg(gspca_dev, 0x0040, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0132);
clock_div = 7;
break;
}
cit_model3_Packet1(gspca_dev, 0x007e, 0x000e);
cit_model3_Packet1(gspca_dev, 0x0036, 0x0011);
cit_model3_Packet1(gspca_dev, 0x0060, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0061, 0x0004);
cit_model3_Packet1(gspca_dev, 0x0062, 0x0005);
cit_model3_Packet1(gspca_dev, 0x0063, 0x0014);
cit_model3_Packet1(gspca_dev, 0x0096, 0x00a0);
cit_model3_Packet1(gspca_dev, 0x0097, 0x0096);
cit_model3_Packet1(gspca_dev, 0x0067, 0x0001);
cit_model3_Packet1(gspca_dev, 0x005b, 0x000c);
cit_model3_Packet1(gspca_dev, 0x005c, 0x0016);
cit_model3_Packet1(gspca_dev, 0x0098, 0x000b);
cit_model3_Packet1(gspca_dev, 0x002c, 0x0003);
cit_model3_Packet1(gspca_dev, 0x002f, 0x002a);
cit_model3_Packet1(gspca_dev, 0x0030, 0x0029);
cit_model3_Packet1(gspca_dev, 0x0037, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0038, 0x0059);
cit_model3_Packet1(gspca_dev, 0x003d, 0x002e);
cit_model3_Packet1(gspca_dev, 0x003e, 0x0028);
cit_model3_Packet1(gspca_dev, 0x0078, 0x0005);
cit_model3_Packet1(gspca_dev, 0x007b, 0x0011);
cit_model3_Packet1(gspca_dev, 0x007d, 0x004b);
cit_model3_Packet1(gspca_dev, 0x007f, 0x0022);
cit_model3_Packet1(gspca_dev, 0x0080, 0x000c);
cit_model3_Packet1(gspca_dev, 0x0081, 0x000b);
cit_model3_Packet1(gspca_dev, 0x0083, 0x00fd);
cit_model3_Packet1(gspca_dev, 0x0086, 0x000b);
cit_model3_Packet1(gspca_dev, 0x0087, 0x000b);
cit_model3_Packet1(gspca_dev, 0x007e, 0x000e);
cit_model3_Packet1(gspca_dev, 0x0096, 0x00a0);
cit_model3_Packet1(gspca_dev, 0x0097, 0x0096);
cit_model3_Packet1(gspca_dev, 0x0098, 0x000b);
cit_write_reg(gspca_dev, clock_div, 0x0111);
switch (gspca_dev->width) {
case 160:
cit_model3_Packet1(gspca_dev, 0x001f, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0039, 0x001f);
cit_model3_Packet1(gspca_dev, 0x003b, 0x003c);
cit_model3_Packet1(gspca_dev, 0x0040, 0x000a);
cit_model3_Packet1(gspca_dev, 0x0051, 0x000a);
break;
case 320:
cit_model3_Packet1(gspca_dev, 0x001f, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0039, 0x001f);
cit_model3_Packet1(gspca_dev, 0x003b, 0x003c);
cit_model3_Packet1(gspca_dev, 0x0040, 0x0008);
cit_model3_Packet1(gspca_dev, 0x0051, 0x000b);
break;
case 640:
cit_model3_Packet1(gspca_dev, 0x001f, 0x0002);
cit_model3_Packet1(gspca_dev, 0x0039, 0x003e);
cit_model3_Packet1(gspca_dev, 0x0040, 0x0008);
cit_model3_Packet1(gspca_dev, 0x0051, 0x000a);
break;
}
if (rca_input) {
for (i = 0; i < ARRAY_SIZE(rca_initdata); i++) {
if (rca_initdata[i][0])
cit_read_reg(gspca_dev, rca_initdata[i][2], 0);
else
cit_write_reg(gspca_dev, rca_initdata[i][1],
rca_initdata[i][2]);
}
}
return 0;
}
static int cit_start_model4(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
cit_write_reg(gspca_dev, 0x0000, 0x0100);
cit_write_reg(gspca_dev, 0x00c0, 0x0111);
cit_write_reg(gspca_dev, 0x00bc, 0x012c);
cit_write_reg(gspca_dev, 0x0080, 0x012b);
cit_write_reg(gspca_dev, 0x0000, 0x0108);
cit_write_reg(gspca_dev, 0x0001, 0x0133);
cit_write_reg(gspca_dev, 0x009b, 0x010f);
cit_write_reg(gspca_dev, 0x00bb, 0x010f);
cit_model4_Packet1(gspca_dev, 0x0038, 0x0000);
cit_model4_Packet1(gspca_dev, 0x000a, 0x005c);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0004, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0x00fb, 0x012e);
cit_write_reg(gspca_dev, 0x0000, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012f);
cit_write_reg(gspca_dev, 0xd055, 0x0124);
cit_write_reg(gspca_dev, 0x000c, 0x0127);
cit_write_reg(gspca_dev, 0x0009, 0x012e);
cit_write_reg(gspca_dev, 0xaa28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0012, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0008, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x002a, 0x012d);
cit_write_reg(gspca_dev, 0x0000, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_model4_Packet1(gspca_dev, 0x0034, 0x0000);
switch (gspca_dev->width) {
case 128:
cit_write_reg(gspca_dev, 0x0070, 0x0119);
cit_write_reg(gspca_dev, 0x00d0, 0x0111);
cit_write_reg(gspca_dev, 0x0039, 0x010a);
cit_write_reg(gspca_dev, 0x0001, 0x0102);
cit_write_reg(gspca_dev, 0x0028, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x001e, 0x0105);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0016, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x000a, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0014, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012e);
cit_write_reg(gspca_dev, 0x001a, 0x0130);
cit_write_reg(gspca_dev, 0x8a0a, 0x0124);
cit_write_reg(gspca_dev, 0x005a, 0x012d);
cit_write_reg(gspca_dev, 0x9545, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x0127);
cit_write_reg(gspca_dev, 0x0018, 0x012e);
cit_write_reg(gspca_dev, 0x0043, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012f);
cit_write_reg(gspca_dev, 0xd055, 0x0124);
cit_write_reg(gspca_dev, 0x001c, 0x0127);
cit_write_reg(gspca_dev, 0x00eb, 0x012e);
cit_write_reg(gspca_dev, 0xaa28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0032, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0036, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x001e, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0017, 0x0127);
cit_write_reg(gspca_dev, 0x0013, 0x012e);
cit_write_reg(gspca_dev, 0x0031, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x0017, 0x012d);
cit_write_reg(gspca_dev, 0x0078, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0xfea8, 0x0124);
sd->sof_len = 2;
break;
case 160:
cit_write_reg(gspca_dev, 0x0038, 0x0119);
cit_write_reg(gspca_dev, 0x00d0, 0x0111);
cit_write_reg(gspca_dev, 0x00b9, 0x010a);
cit_write_reg(gspca_dev, 0x0001, 0x0102);
cit_write_reg(gspca_dev, 0x0028, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x001e, 0x0105);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0016, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x000b, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0014, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012e);
cit_write_reg(gspca_dev, 0x001a, 0x0130);
cit_write_reg(gspca_dev, 0x8a0a, 0x0124);
cit_write_reg(gspca_dev, 0x005a, 0x012d);
cit_write_reg(gspca_dev, 0x9545, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x0127);
cit_write_reg(gspca_dev, 0x0018, 0x012e);
cit_write_reg(gspca_dev, 0x0043, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012f);
cit_write_reg(gspca_dev, 0xd055, 0x0124);
cit_write_reg(gspca_dev, 0x001c, 0x0127);
cit_write_reg(gspca_dev, 0x00c7, 0x012e);
cit_write_reg(gspca_dev, 0xaa28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0032, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0025, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0036, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x001e, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0048, 0x0127);
cit_write_reg(gspca_dev, 0x0035, 0x012e);
cit_write_reg(gspca_dev, 0x00d0, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x0048, 0x012d);
cit_write_reg(gspca_dev, 0x0090, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x0001, 0x0127);
cit_write_reg(gspca_dev, 0xfea8, 0x0124);
sd->sof_len = 2;
break;
case 176:
cit_write_reg(gspca_dev, 0x0038, 0x0119);
cit_write_reg(gspca_dev, 0x00d0, 0x0111);
cit_write_reg(gspca_dev, 0x00b9, 0x010a);
cit_write_reg(gspca_dev, 0x0001, 0x0102);
cit_write_reg(gspca_dev, 0x002c, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x0024, 0x0105);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0016, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0007, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0014, 0x012d);
cit_write_reg(gspca_dev, 0x0001, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012e);
cit_write_reg(gspca_dev, 0x001a, 0x0130);
cit_write_reg(gspca_dev, 0x8a0a, 0x0124);
cit_write_reg(gspca_dev, 0x005e, 0x012d);
cit_write_reg(gspca_dev, 0x9545, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x0127);
cit_write_reg(gspca_dev, 0x0018, 0x012e);
cit_write_reg(gspca_dev, 0x0049, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012f);
cit_write_reg(gspca_dev, 0xd055, 0x0124);
cit_write_reg(gspca_dev, 0x001c, 0x0127);
cit_write_reg(gspca_dev, 0x00c7, 0x012e);
cit_write_reg(gspca_dev, 0xaa28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0032, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0028, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0036, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x001e, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0010, 0x0127);
cit_write_reg(gspca_dev, 0x0013, 0x012e);
cit_write_reg(gspca_dev, 0x002a, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x0010, 0x012d);
cit_write_reg(gspca_dev, 0x006d, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x0001, 0x0127);
cit_write_reg(gspca_dev, 0xfea8, 0x0124);
sd->sof_len = 10;
break;
case 320:
cit_write_reg(gspca_dev, 0x0070, 0x0119);
cit_write_reg(gspca_dev, 0x00d0, 0x0111);
cit_write_reg(gspca_dev, 0x0039, 0x010a);
cit_write_reg(gspca_dev, 0x0001, 0x0102);
cit_write_reg(gspca_dev, 0x0028, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x001e, 0x0105);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0016, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x000a, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0014, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012e);
cit_write_reg(gspca_dev, 0x001a, 0x0130);
cit_write_reg(gspca_dev, 0x8a0a, 0x0124);
cit_write_reg(gspca_dev, 0x005a, 0x012d);
cit_write_reg(gspca_dev, 0x9545, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x0127);
cit_write_reg(gspca_dev, 0x0018, 0x012e);
cit_write_reg(gspca_dev, 0x0043, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012f);
cit_write_reg(gspca_dev, 0xd055, 0x0124);
cit_write_reg(gspca_dev, 0x001c, 0x0127);
cit_write_reg(gspca_dev, 0x00eb, 0x012e);
cit_write_reg(gspca_dev, 0xaa28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0032, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0036, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x001e, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0017, 0x0127);
cit_write_reg(gspca_dev, 0x0013, 0x012e);
cit_write_reg(gspca_dev, 0x0031, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x0017, 0x012d);
cit_write_reg(gspca_dev, 0x0078, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0xfea8, 0x0124);
sd->sof_len = 2;
break;
case 352:
cit_write_reg(gspca_dev, 0x0070, 0x0119);
cit_write_reg(gspca_dev, 0x00c0, 0x0111);
cit_write_reg(gspca_dev, 0x0039, 0x010a);
cit_write_reg(gspca_dev, 0x0001, 0x0102);
cit_write_reg(gspca_dev, 0x002c, 0x0103);
cit_write_reg(gspca_dev, 0x0000, 0x0104);
cit_write_reg(gspca_dev, 0x0024, 0x0105);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0016, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0006, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0014, 0x012d);
cit_write_reg(gspca_dev, 0x0002, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012e);
cit_write_reg(gspca_dev, 0x001a, 0x0130);
cit_write_reg(gspca_dev, 0x8a0a, 0x0124);
cit_write_reg(gspca_dev, 0x005e, 0x012d);
cit_write_reg(gspca_dev, 0x9545, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x0127);
cit_write_reg(gspca_dev, 0x0018, 0x012e);
cit_write_reg(gspca_dev, 0x0049, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012f);
cit_write_reg(gspca_dev, 0xd055, 0x0124);
cit_write_reg(gspca_dev, 0x001c, 0x0127);
cit_write_reg(gspca_dev, 0x00cf, 0x012e);
cit_write_reg(gspca_dev, 0xaa28, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x0032, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0x00aa, 0x0130);
cit_write_reg(gspca_dev, 0x82a8, 0x0124);
cit_write_reg(gspca_dev, 0x0036, 0x012d);
cit_write_reg(gspca_dev, 0x0008, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0xfffa, 0x0124);
cit_write_reg(gspca_dev, 0x00aa, 0x012d);
cit_write_reg(gspca_dev, 0x001e, 0x012f);
cit_write_reg(gspca_dev, 0xd141, 0x0124);
cit_write_reg(gspca_dev, 0x0010, 0x0127);
cit_write_reg(gspca_dev, 0x0013, 0x012e);
cit_write_reg(gspca_dev, 0x0025, 0x0130);
cit_write_reg(gspca_dev, 0x8a28, 0x0124);
cit_write_reg(gspca_dev, 0x0010, 0x012d);
cit_write_reg(gspca_dev, 0x0048, 0x012f);
cit_write_reg(gspca_dev, 0xd145, 0x0124);
cit_write_reg(gspca_dev, 0x0000, 0x0127);
cit_write_reg(gspca_dev, 0xfea8, 0x0124);
sd->sof_len = 2;
break;
}
cit_model4_Packet1(gspca_dev, 0x0038, 0x0004);
return 0;
}
static int cit_start_ibm_netcam_pro(struct gspca_dev *gspca_dev)
{
const unsigned short compression = 0;
int i, clock_div;
clock_div = cit_get_clock_div(gspca_dev);
if (clock_div < 0)
return clock_div;
cit_write_reg(gspca_dev, 0x0003, 0x0133);
cit_write_reg(gspca_dev, 0x0000, 0x0117);
cit_write_reg(gspca_dev, 0x0008, 0x0123);
cit_write_reg(gspca_dev, 0x0000, 0x0100);
cit_write_reg(gspca_dev, 0x0060, 0x0116);
cit_write_reg(gspca_dev, 0x0000, 0x0133);
cit_write_reg(gspca_dev, 0x0000, 0x0123);
cit_write_reg(gspca_dev, 0x0001, 0x0117);
cit_write_reg(gspca_dev, 0x0040, 0x0108);
cit_write_reg(gspca_dev, 0x0019, 0x012c);
cit_write_reg(gspca_dev, 0x0060, 0x0116);
cit_model3_Packet1(gspca_dev, 0x0049, 0x0000);
cit_write_reg(gspca_dev, 0x0000, 0x0101);
cit_write_reg(gspca_dev, 0x003a, 0x0102);
cit_write_reg(gspca_dev, 0x00a0, 0x0103);
cit_write_reg(gspca_dev, 0x0078, 0x0105);
cit_write_reg(gspca_dev, 0x0000, 0x010a);
cit_write_reg(gspca_dev, 0x0002, 0x011d);
cit_write_reg(gspca_dev, 0x0000, 0x0129);
cit_write_reg(gspca_dev, 0x00fc, 0x012b);
cit_write_reg(gspca_dev, 0x0022, 0x012a);
switch (gspca_dev->width) {
case 160:
cit_write_reg(gspca_dev, 0x0024, 0x010b);
cit_write_reg(gspca_dev, 0x0089, 0x0119);
cit_write_reg(gspca_dev, 0x000a, 0x011b);
cit_write_reg(gspca_dev, 0x0003, 0x011e);
cit_write_reg(gspca_dev, 0x0007, 0x0104);
cit_write_reg(gspca_dev, 0x0009, 0x011a);
cit_write_reg(gspca_dev, 0x008b, 0x011c);
cit_write_reg(gspca_dev, 0x0008, 0x0118);
cit_write_reg(gspca_dev, 0x0000, 0x0132);
break;
case 320:
cit_write_reg(gspca_dev, 0x0028, 0x010b);
cit_write_reg(gspca_dev, 0x00d9, 0x0119);
cit_write_reg(gspca_dev, 0x0006, 0x011b);
cit_write_reg(gspca_dev, 0x0000, 0x011e);
cit_write_reg(gspca_dev, 0x000e, 0x0104);
cit_write_reg(gspca_dev, 0x0004, 0x011a);
cit_write_reg(gspca_dev, 0x003f, 0x011c);
cit_write_reg(gspca_dev, 0x000c, 0x0118);
cit_write_reg(gspca_dev, 0x0000, 0x0132);
break;
}
cit_model3_Packet1(gspca_dev, 0x0019, 0x0031);
cit_model3_Packet1(gspca_dev, 0x001a, 0x0003);
cit_model3_Packet1(gspca_dev, 0x001b, 0x0038);
cit_model3_Packet1(gspca_dev, 0x001c, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0024, 0x0001);
cit_model3_Packet1(gspca_dev, 0x0027, 0x0001);
cit_model3_Packet1(gspca_dev, 0x002a, 0x0004);
cit_model3_Packet1(gspca_dev, 0x0035, 0x000b);
cit_model3_Packet1(gspca_dev, 0x003f, 0x0001);
cit_model3_Packet1(gspca_dev, 0x0044, 0x0000);
cit_model3_Packet1(gspca_dev, 0x0054, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00c4, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00e7, 0x0001);
cit_model3_Packet1(gspca_dev, 0x00e9, 0x0001);
cit_model3_Packet1(gspca_dev, 0x00ee, 0x0000);
cit_model3_Packet1(gspca_dev, 0x00f3, 0x00c0);
cit_write_reg(gspca_dev, compression, 0x0109);
cit_write_reg(gspca_dev, clock_div, 0x0111);
if (rca_input) {
for (i = 0; i < ARRAY_SIZE(rca_initdata); i++) {
if (rca_initdata[i][0])
cit_read_reg(gspca_dev, rca_initdata[i][2], 0);
else
cit_write_reg(gspca_dev, rca_initdata[i][1],
rca_initdata[i][2]);
}
}
return 0;
}
static int sd_start(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
int packet_size;
packet_size = cit_get_packet_size(gspca_dev);
if (packet_size < 0)
return packet_size;
switch (sd->model) {
case CIT_MODEL0:
cit_start_model0(gspca_dev);
break;
case CIT_MODEL1:
cit_start_model1(gspca_dev);
break;
case CIT_MODEL2:
cit_start_model2(gspca_dev);
break;
case CIT_MODEL3:
cit_start_model3(gspca_dev);
break;
case CIT_MODEL4:
cit_start_model4(gspca_dev);
break;
case CIT_IBM_NETCAM_PRO:
cit_start_ibm_netcam_pro(gspca_dev);
break;
}
cit_write_reg(gspca_dev, packet_size >> 8, 0x0106);
cit_write_reg(gspca_dev, packet_size & 0xff, 0x0107);
cit_restart_stream(gspca_dev);
return 0;
}
static int sd_isoc_init(struct gspca_dev *gspca_dev)
{
struct usb_host_interface *alt;
int max_packet_size;
switch (gspca_dev->width) {
case 160:
max_packet_size = 450;
break;
case 176:
max_packet_size = 600;
break;
default:
max_packet_size = 1022;
break;
}
alt = &gspca_dev->dev->actconfig->intf_cache[0]->altsetting[1];
alt->endpoint[0].desc.wMaxPacketSize = cpu_to_le16(max_packet_size);
return 0;
}
static int sd_isoc_nego(struct gspca_dev *gspca_dev)
{
int ret, packet_size, min_packet_size;
struct usb_host_interface *alt;
switch (gspca_dev->width) {
case 160:
min_packet_size = 200;
break;
case 176:
min_packet_size = 266;
break;
default:
min_packet_size = 400;
break;
}
alt = &gspca_dev->dev->actconfig->intf_cache[0]->altsetting[1];
packet_size = le16_to_cpu(alt->endpoint[0].desc.wMaxPacketSize);
if (packet_size <= min_packet_size)
return -EIO;
packet_size -= 100;
if (packet_size < min_packet_size)
packet_size = min_packet_size;
alt->endpoint[0].desc.wMaxPacketSize = cpu_to_le16(packet_size);
ret = usb_set_interface(gspca_dev->dev, gspca_dev->iface, 1);
if (ret < 0)
pr_err("set alt 1 err %d\n", ret);
return ret;
}
static void sd_stopN(struct gspca_dev *gspca_dev)
{
cit_write_reg(gspca_dev, 0x0000, 0x010c);
}
static void sd_stop0(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
if (!gspca_dev->present)
return;
switch (sd->model) {
case CIT_MODEL0:
cit_write_reg(gspca_dev, 0x00c0, 0x0100);
break;
case CIT_MODEL1:
cit_send_FF_04_02(gspca_dev);
cit_read_reg(gspca_dev, 0x0100, 0);
cit_write_reg(gspca_dev, 0x81, 0x0100);
break;
case CIT_MODEL2:
v4l2_ctrl_grab(sd->lighting, false);
case CIT_MODEL4:
cit_model2_Packet1(gspca_dev, 0x0030, 0x0004);
cit_write_reg(gspca_dev, 0x0080, 0x0100);
cit_write_reg(gspca_dev, 0x0020, 0x0111);
cit_write_reg(gspca_dev, 0x00a0, 0x0111);
cit_model2_Packet1(gspca_dev, 0x0030, 0x0002);
cit_write_reg(gspca_dev, 0x0020, 0x0111);
cit_write_reg(gspca_dev, 0x0000, 0x0112);
break;
case CIT_MODEL3:
cit_write_reg(gspca_dev, 0x0006, 0x012c);
cit_model3_Packet1(gspca_dev, 0x0046, 0x0000);
cit_read_reg(gspca_dev, 0x0116, 0);
cit_write_reg(gspca_dev, 0x0064, 0x0116);
cit_read_reg(gspca_dev, 0x0115, 0);
cit_write_reg(gspca_dev, 0x0003, 0x0115);
cit_write_reg(gspca_dev, 0x0008, 0x0123);
cit_write_reg(gspca_dev, 0x0000, 0x0117);
cit_write_reg(gspca_dev, 0x0000, 0x0112);
cit_write_reg(gspca_dev, 0x0080, 0x0100);
break;
case CIT_IBM_NETCAM_PRO:
cit_model3_Packet1(gspca_dev, 0x0049, 0x00ff);
cit_write_reg(gspca_dev, 0x0006, 0x012c);
cit_write_reg(gspca_dev, 0x0000, 0x0116);
cit_write_reg(gspca_dev, 0x0008, 0x0123);
cit_write_reg(gspca_dev, 0x0000, 0x0117);
cit_write_reg(gspca_dev, 0x0003, 0x0133);
cit_write_reg(gspca_dev, 0x0000, 0x0111);
cit_write_reg(gspca_dev, 0x00c0, 0x0100);
break;
}
#if IS_ENABLED(CONFIG_INPUT)
if (sd->button_state) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA, 0);
input_sync(gspca_dev->input_dev);
sd->button_state = 0;
}
#endif
}
static u8 *cit_find_sof(struct gspca_dev *gspca_dev, u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 byte3 = 0, byte4 = 0;
int i;
switch (sd->model) {
case CIT_MODEL0:
case CIT_MODEL1:
case CIT_MODEL3:
case CIT_IBM_NETCAM_PRO:
switch (gspca_dev->width) {
case 160:
byte3 = 0x02;
byte4 = 0x0a;
break;
case 176:
byte3 = 0x02;
byte4 = 0x0e;
break;
case 320:
byte3 = 0x02;
byte4 = 0x08;
break;
case 352:
byte3 = 0x02;
byte4 = 0x00;
break;
case 640:
byte3 = 0x03;
byte4 = 0x08;
break;
}
if (sd->model <= CIT_MODEL1)
byte3 = 0x00;
for (i = 0; i < len; i++) {
if (sd->model == CIT_MODEL0 && sd->sof_read != i)
break;
switch (sd->sof_read) {
case 0:
if (data[i] == 0x00)
sd->sof_read++;
break;
case 1:
if (data[i] == 0xff)
sd->sof_read++;
else if (data[i] == 0x00)
sd->sof_read = 1;
else
sd->sof_read = 0;
break;
case 2:
if (data[i] == byte3)
sd->sof_read++;
else if (data[i] == 0x00)
sd->sof_read = 1;
else
sd->sof_read = 0;
break;
case 3:
if (data[i] == byte4) {
sd->sof_read = 0;
return data + i + (sd->sof_len - 3);
}
if (byte3 == 0x00 && data[i] == 0xff)
sd->sof_read = 2;
else if (data[i] == 0x00)
sd->sof_read = 1;
else
sd->sof_read = 0;
break;
}
}
break;
case CIT_MODEL2:
case CIT_MODEL4:
for (i = 0; i < len; i++) {
switch (sd->sof_read) {
case 0:
if (data[i] == 0x00)
sd->sof_read++;
break;
case 1:
sd->sof_read = 0;
if (data[i] == 0xff) {
if (i >= 4)
PDEBUG(D_FRAM,
"header found at offset: %d: %02x %02x 00 %02x %02x %02x\n",
i - 1,
data[i - 4],
data[i - 3],
data[i],
data[i + 1],
data[i + 2]);
else
PDEBUG(D_FRAM,
"header found at offset: %d: 00 %02x %02x %02x\n",
i - 1,
data[i],
data[i + 1],
data[i + 2]);
return data + i + (sd->sof_len - 1);
}
break;
}
}
break;
}
return NULL;
}
static void sd_pkt_scan(struct gspca_dev *gspca_dev,
u8 *data, int len)
{
struct sd *sd = (struct sd *) gspca_dev;
unsigned char *sof;
sof = cit_find_sof(gspca_dev, data, len);
if (sof) {
int n;
n = sof - data;
if (n > sd->sof_len)
n -= sd->sof_len;
else
n = 0;
gspca_frame_add(gspca_dev, LAST_PACKET,
data, n);
gspca_frame_add(gspca_dev, FIRST_PACKET, NULL, 0);
len -= sof - data;
data = sof;
}
gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
}
static void cit_check_button(struct gspca_dev *gspca_dev)
{
int new_button_state;
struct sd *sd = (struct sd *)gspca_dev;
switch (sd->model) {
case CIT_MODEL3:
case CIT_IBM_NETCAM_PRO:
break;
default:
return;
}
cit_read_reg(gspca_dev, 0x0113, 0);
new_button_state = !gspca_dev->usb_buf[0];
if (new_button_state)
cit_write_reg(gspca_dev, 0x01, 0x0113);
if (sd->button_state != new_button_state) {
input_report_key(gspca_dev->input_dev, KEY_CAMERA,
new_button_state);
input_sync(gspca_dev->input_dev);
sd->button_state = new_button_state;
}
}
static int sd_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct gspca_dev *gspca_dev =
container_of(ctrl->handler, struct gspca_dev, ctrl_handler);
struct sd *sd = (struct sd *)gspca_dev;
gspca_dev->usb_err = 0;
if (!gspca_dev->streaming)
return 0;
if (sd->stop_on_control_change)
sd_stopN(gspca_dev);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
cit_set_brightness(gspca_dev, ctrl->val);
break;
case V4L2_CID_CONTRAST:
cit_set_contrast(gspca_dev, ctrl->val);
break;
case V4L2_CID_HUE:
cit_set_hue(gspca_dev, ctrl->val);
break;
case V4L2_CID_HFLIP:
cit_set_hflip(gspca_dev, ctrl->val);
break;
case V4L2_CID_SHARPNESS:
cit_set_sharpness(gspca_dev, ctrl->val);
break;
case V4L2_CID_BACKLIGHT_COMPENSATION:
cit_set_lighting(gspca_dev, ctrl->val);
break;
}
if (sd->stop_on_control_change)
cit_restart_stream(gspca_dev);
return gspca_dev->usb_err;
}
static int sd_init_controls(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *)gspca_dev;
struct v4l2_ctrl_handler *hdl = &gspca_dev->ctrl_handler;
bool has_brightness;
bool has_contrast;
bool has_hue;
bool has_sharpness;
bool has_lighting;
bool has_hflip;
has_brightness = has_contrast = has_hue =
has_sharpness = has_hflip = has_lighting = false;
switch (sd->model) {
case CIT_MODEL0:
has_contrast = has_hflip = true;
break;
case CIT_MODEL1:
has_brightness = has_contrast =
has_sharpness = has_lighting = true;
break;
case CIT_MODEL2:
has_brightness = has_hue = has_lighting = true;
break;
case CIT_MODEL3:
has_brightness = has_contrast = has_sharpness = true;
break;
case CIT_MODEL4:
has_brightness = has_hue = true;
break;
case CIT_IBM_NETCAM_PRO:
has_brightness = has_hue =
has_sharpness = has_hflip = has_lighting = true;
break;
}
gspca_dev->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_init(hdl, 5);
if (has_brightness)
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 63, 1, 32);
if (has_contrast)
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_CONTRAST, 0, 20, 1, 10);
if (has_hue)
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HUE, 0, 127, 1, 63);
if (has_sharpness)
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_SHARPNESS, 0, 6, 1, 3);
if (has_lighting)
sd->lighting = v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_BACKLIGHT_COMPENSATION, 0, 2, 1, 1);
if (has_hflip)
v4l2_ctrl_new_std(hdl, &sd_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
if (hdl->error) {
pr_err("Could not initialize controls\n");
return hdl->error;
}
return 0;
}
static int sd_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
const struct sd_desc *desc = &sd_desc;
switch (id->driver_info) {
case CIT_MODEL0:
case CIT_MODEL1:
if (intf->cur_altsetting->desc.bInterfaceNumber != 2)
return -ENODEV;
break;
case CIT_MODEL2:
case CIT_MODEL4:
if (intf->cur_altsetting->desc.bInterfaceNumber != 0)
return -ENODEV;
break;
case CIT_MODEL3:
if (intf->cur_altsetting->desc.bInterfaceNumber != 0)
return -ENODEV;
if (ibm_netcam_pro)
desc = &sd_desc_isoc_nego;
break;
}
return gspca_dev_probe2(intf, id, desc, sizeof(struct sd), THIS_MODULE);
}
