static int regget(struct usb_device *pusb_device,
u16 index, void *reg, int reg_size)
{
int rc;
if (!pusb_device)
return -ENODEV;
rc = usb_control_msg(pusb_device, usb_rcvctrlpipe(pusb_device, 0),
0x00,
(USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE),
0x00,
index, reg, reg_size, 50000);
return rc;
}
static int regset(struct usb_device *pusb_device, u16 index, u16 value)
{
int rc;
if (!pusb_device)
return -ENODEV;
rc = usb_control_msg(pusb_device, usb_sndctrlpipe(pusb_device, 0),
0x01,
(USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE),
value, index, NULL, 0, 500);
if (rc < 0)
return rc;
if (easycap_readback) {
u16 igot = 0;
rc = regget(pusb_device, index, &igot, sizeof(igot));
igot = 0xFF & igot;
switch (index) {
case 0x000:
case 0x500:
case 0x502:
case 0x503:
case 0x504:
case 0x506:
case 0x507:
break;
case 0x204:
case 0x205:
case 0x350:
case 0x351:
if (igot)
JOT(8, "unexpected 0x%02X "
"for STK register 0x%03X\n",
igot, index);
break;
default:
if ((0xFF & value) != igot)
JOT(8, "unexpected 0x%02X != 0x%02X "
"for STK register 0x%03X\n",
igot, value, index);
break;
}
}
return rc;
}
static int wait_i2c(struct usb_device *p)
{
u16 get0;
u8 igot;
const int max = 2;
int k;
if (!p)
return -ENODEV;
for (k = 0; k < max; k++) {
GET(p, 0x0201, &igot); get0 = igot;
switch (get0) {
case 0x04:
case 0x01:
return 0;
case 0x00:
msleep(20);
continue;
default:
return get0 - 1;
}
}
return -1;
}
int write_saa(struct usb_device *p, u16 reg0, u16 set0)
{
if (!p)
return -ENODEV;
SET(p, 0x200, 0x00);
SET(p, 0x204, reg0);
SET(p, 0x205, set0);
SET(p, 0x200, 0x01);
return wait_i2c(p);
}
static int write_vt(struct usb_device *p, u16 reg0, u16 set0)
{
u8 igot;
u16 got502, got503;
u16 set502, set503;
if (!p)
return -ENODEV;
SET(p, 0x0504, reg0);
SET(p, 0x0500, 0x008B);
GET(p, 0x0502, &igot); got502 = (0xFF & igot);
GET(p, 0x0503, &igot); got503 = (0xFF & igot);
JOT(16, "write_vt(., 0x%04X, 0x%04X): was 0x%04X\n",
reg0, set0, ((got503 << 8) | got502));
set502 = (0x00FF & set0);
set503 = ((0xFF00 & set0) >> 8);
SET(p, 0x0504, reg0);
SET(p, 0x0502, set502);
SET(p, 0x0503, set503);
SET(p, 0x0500, 0x008C);
return 0;
}
static int read_vt(struct usb_device *p, u16 reg0)
{
u8 igot;
u16 got502, got503;
if (!p)
return -ENODEV;
SET(p, 0x0504, reg0);
SET(p, 0x0500, 0x008B);
GET(p, 0x0502, &igot); got502 = (0xFF & igot);
GET(p, 0x0503, &igot); got503 = (0xFF & igot);
JOT(16, "read_vt(., 0x%04X): has 0x%04X\n",
reg0, ((got503 << 8) | got502));
return (got503 << 8) | got502;
}
static int write_300(struct usb_device *p)
{
if (!p)
return -ENODEV;
SET(p, 0x300, 0x0012);
SET(p, 0x350, 0x002D);
SET(p, 0x351, 0x0001);
SET(p, 0x352, 0x0000);
SET(p, 0x353, 0x0000);
SET(p, 0x300, 0x0080);
return 0;
}
int setup_stk(struct usb_device *p, bool ntsc)
{
int i;
const struct stk1160config *cfg;
if (!p)
return -ENODEV;
cfg = (ntsc) ? stk1160configNTSC : stk1160configPAL;
for (i = 0; cfg[i].reg != 0xFFF; i++)
SET(p, cfg[i].reg, cfg[i].set);
write_300(p);
return 0;
}
int setup_saa(struct usb_device *p, bool ntsc)
{
int i, rc;
const struct saa7113config *cfg;
if (!p)
return -ENODEV;
cfg = (ntsc) ? saa7113configNTSC : saa7113configPAL;
for (i = 0; cfg[i].reg != 0xFF; i++) {
rc = write_saa(p, cfg[i].reg, cfg[i].set);
if (rc)
dev_err(&p->dev,
"Failed to set SAA register %d", cfg[i].reg);
}
return 0;
}
int merit_saa(struct usb_device *p)
{
int rc;
if (!p)
return -ENODEV;
rc = read_saa(p, 0x1F);
return ((0 > rc) || (0x02 & rc)) ? 1 : 0;
}
int ready_saa(struct usb_device *p)
{
int j, rc, rate;
const int max = 5, marktime = PATIENCE/5;
if (!p)
return -ENODEV;
j = 0;
while (max > j) {
rc = read_saa(p, 0x1F);
if (0 <= rc) {
if (0 == (0x40 & rc))
break;
if (1 == (0x01 & rc))
break;
}
msleep(marktime);
j++;
}
if (max == j)
return -1;
if (0x20 & rc) {
rate = 2;
JOT(8, "hardware detects 60 Hz\n");
} else {
rate = 0;
JOT(8, "hardware detects 50 Hz\n");
}
if (0x80 & rc)
JOT(8, "hardware detects interlacing\n");
else {
rate++;
JOT(8, "hardware detects no interlacing\n");
}
return 0;
}
int read_saa(struct usb_device *p, u16 reg0)
{
u8 igot;
if (!p)
return -ENODEV;
SET(p, 0x208, reg0);
SET(p, 0x200, 0x20);
if (0 != wait_i2c(p))
return -1;
igot = 0;
GET(p, 0x0209, &igot);
return igot;
}
static int read_stk(struct usb_device *p, u32 reg0)
{
u8 igot;
if (!p)
return -ENODEV;
igot = 0;
GET(p, reg0, &igot);
return igot;
}
int select_input(struct usb_device *p, int input, int mode)
{
int ir;
if (!p)
return -ENODEV;
stop_100(p);
switch (input) {
case 0:
case 1: {
if (0 != write_saa(p, 0x02, 0x80))
SAY("ERROR: failed to set SAA register 0x02 "
"for input %i\n", input);
SET(p, 0x0000, 0x0098);
SET(p, 0x0002, 0x0078);
break;
}
case 2: {
if (0 != write_saa(p, 0x02, 0x80))
SAY("ERROR: failed to set SAA register 0x02 "
"for input %i\n", input);
SET(p, 0x0000, 0x0090);
SET(p, 0x0002, 0x0078);
break;
}
case 3: {
if (0 != write_saa(p, 0x02, 0x80))
SAY("ERROR: failed to set SAA register 0x02 "
" for input %i\n", input);
SET(p, 0x0000, 0x0088);
SET(p, 0x0002, 0x0078);
break;
}
case 4: {
if (0 != write_saa(p, 0x02, 0x80)) {
SAY("ERROR: failed to set SAA register 0x02 "
"for input %i\n", input);
}
SET(p, 0x0000, 0x0080);
SET(p, 0x0002, 0x0078);
break;
}
case 5: {
if (9 != mode)
mode = 7;
switch (mode) {
case 7: {
if (0 != write_saa(p, 0x02, 0x87))
SAY("ERROR: failed to set SAA register 0x02 "
"for input %i\n", input);
if (0 != write_saa(p, 0x05, 0xFF))
SAY("ERROR: failed to set SAA register 0x05 "
"for input %i\n", input);
break;
}
case 9: {
if (0 != write_saa(p, 0x02, 0x89))
SAY("ERROR: failed to set SAA register 0x02 "
"for input %i\n", input);
if (0 != write_saa(p, 0x05, 0x00))
SAY("ERROR: failed to set SAA register 0x05 "
"for input %i\n", input);
break;
}
default:
SAY("MISTAKE: bad mode: %i\n", mode);
return -1;
}
if (0 != write_saa(p, 0x04, 0x00))
SAY("ERROR: failed to set SAA register 0x04 "
"for input %i\n", input);
if (0 != write_saa(p, 0x09, 0x80))
SAY("ERROR: failed to set SAA register 0x09 "
"for input %i\n", input);
SET(p, 0x0002, 0x0093);
break;
}
default:
SAY("ERROR: bad input: %i\n", input);
return -1;
}
ir = read_stk(p, 0x00);
JOT(8, "STK register 0x00 has 0x%02X\n", ir);
ir = read_saa(p, 0x02);
JOT(8, "SAA register 0x02 has 0x%02X\n", ir);
start_100(p);
return 0;
}
int set_resolution(struct usb_device *p,
u16 set0, u16 set1, u16 set2, u16 set3)
{
u16 u0x0111, u0x0113, u0x0115, u0x0117;
if (!p)
return -ENODEV;
u0x0111 = ((0xFF00 & set0) >> 8);
u0x0113 = ((0xFF00 & set1) >> 8);
u0x0115 = ((0xFF00 & set2) >> 8);
u0x0117 = ((0xFF00 & set3) >> 8);
SET(p, 0x0110, (0x00FF & set0));
SET(p, 0x0111, u0x0111);
SET(p, 0x0112, (0x00FF & set1));
SET(p, 0x0113, u0x0113);
SET(p, 0x0114, (0x00FF & set2));
SET(p, 0x0115, u0x0115);
SET(p, 0x0116, (0x00FF & set3));
SET(p, 0x0117, u0x0117);
return 0;
}
int start_100(struct usb_device *p)
{
u16 get116, get117, get0;
u8 igot116, igot117, igot;
if (!p)
return -ENODEV;
GET(p, 0x0116, &igot116);
get116 = igot116;
GET(p, 0x0117, &igot117);
get117 = igot117;
SET(p, 0x0116, 0x0000);
SET(p, 0x0117, 0x0000);
GET(p, 0x0100, &igot);
get0 = igot;
SET(p, 0x0100, (0x80 | get0));
SET(p, 0x0116, get116);
SET(p, 0x0117, get117);
return 0;
}
int stop_100(struct usb_device *p)
{
u16 get0;
u8 igot;
if (!p)
return -ENODEV;
GET(p, 0x0100, &igot);
get0 = igot;
SET(p, 0x0100, (0x7F & get0));
return 0;
}
int easycap_wakeup_device(struct usb_device *pusb_device)
{
if (!pusb_device)
return -ENODEV;
return usb_control_msg(pusb_device, usb_sndctrlpipe(pusb_device, 0),
USB_REQ_SET_FEATURE,
USB_DIR_OUT | USB_TYPE_STANDARD | USB_RECIP_DEVICE,
USB_DEVICE_REMOTE_WAKEUP,
0, NULL, 0, 50000);
}
int easycap_audio_setup(struct easycap *peasycap)
{
struct usb_device *pusb_device;
u8 buffer[1];
int rc, id1, id2;
const u8 request = 0x01;
const u8 requesttype = USB_DIR_OUT |
USB_TYPE_CLASS |
USB_RECIP_INTERFACE;
const u16 value_unmute = 0x0200;
const u16 index = 0x0301;
const u16 length = 1;
if (!peasycap)
return -EFAULT;
pusb_device = peasycap->pusb_device;
if (!pusb_device)
return -ENODEV;
JOM(8, "%02X %02X %02X %02X %02X %02X %02X %02X\n",
requesttype, request,
(0x00FF & value_unmute),
(0xFF00 & value_unmute) >> 8,
(0x00FF & index),
(0xFF00 & index) >> 8,
(0x00FF & length),
(0xFF00 & length) >> 8);
buffer[0] = 0x01;
rc = usb_control_msg(pusb_device, usb_sndctrlpipe(pusb_device, 0),
request, requesttype, value_unmute,
index, &buffer[0], length, 50000);
JOT(8, "0x%02X=buffer\n", buffer[0]);
if (rc != (int)length) {
switch (rc) {
case -EPIPE:
SAY("usb_control_msg returned -EPIPE\n");
break;
default:
SAY("ERROR: usb_control_msg returned %i\n", rc);
break;
}
}
SET(pusb_device, 0x0500, 0x0094);
SET(pusb_device, 0x0500, 0x008C);
SET(pusb_device, 0x0506, 0x0001);
SET(pusb_device, 0x0507, 0x0000);
id1 = read_vt(pusb_device, 0x007C);
id2 = read_vt(pusb_device, 0x007E);
SAM("0x%04X:0x%04X is audio vendor id\n", id1, id2);
if (easycap_audio_gainset(pusb_device, peasycap->gain))
SAY("ERROR: audio_gainset() failed\n");
check_vt(pusb_device);
return 0;
}
int check_vt(struct usb_device *pusb_device)
{
int igot;
if (!pusb_device)
return -ENODEV;
igot = read_vt(pusb_device, 0x0002);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x02\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x02);
igot = read_vt(pusb_device, 0x000E);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x0E\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x0E);
igot = read_vt(pusb_device, 0x0010);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x10\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x10);
igot = read_vt(pusb_device, 0x0012);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x12\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x12);
igot = read_vt(pusb_device, 0x0014);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x14\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x14);
igot = read_vt(pusb_device, 0x0016);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x16\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x16);
igot = read_vt(pusb_device, 0x0018);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x18\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x18);
igot = read_vt(pusb_device, 0x001C);
if (0 > igot)
SAY("ERROR: failed to read VT1612A register 0x1C\n");
if (0x8000 & igot)
SAY("register 0x%02X muted\n", 0x1C);
return 0;
}
int easycap_audio_gainset(struct usb_device *pusb_device, s8 loud)
{
int igot;
u8 tmp;
u16 mute;
if (!pusb_device)
return -ENODEV;
if (0 > loud)
loud = 0;
if (31 < loud)
loud = 31;
write_vt(pusb_device, 0x0002, 0x8000);
igot = read_vt(pusb_device, 0x000E);
if (0 > igot) {
SAY("ERROR: failed to read VT1612A register 0x0E\n");
mute = 0x0000;
} else
mute = 0x8000 & ((unsigned int)igot);
mute = 0;
if (16 > loud)
tmp = 0x01 | (0x001F & (((u8)(15 - loud)) << 1));
else
tmp = 0;
JOT(8, "0x%04X=(mute|tmp) for VT1612A register 0x0E\n", mute | tmp);
write_vt(pusb_device, 0x000E, (mute | tmp));
igot = read_vt(pusb_device, 0x0010);
if (0 > igot) {
SAY("ERROR: failed to read VT1612A register 0x10\n");
mute = 0x0000;
} else
mute = 0x8000 & ((unsigned int)igot);
mute = 0;
JOT(8, "0x%04X=(mute|tmp|(tmp<<8)) for VT1612A register 0x10,...0x18\n",
mute | tmp | (tmp << 8));
write_vt(pusb_device, 0x0010, (mute | tmp | (tmp << 8)));
write_vt(pusb_device, 0x0012, (mute | tmp | (tmp << 8)));
write_vt(pusb_device, 0x0014, (mute | tmp | (tmp << 8)));
write_vt(pusb_device, 0x0016, (mute | tmp | (tmp << 8)));
write_vt(pusb_device, 0x0018, (mute | tmp | (tmp << 8)));
igot = read_vt(pusb_device, 0x001C);
if (0 > igot) {
SAY("ERROR: failed to read VT1612A register 0x1C\n");
mute = 0x0000;
} else
mute = 0x8000 & ((unsigned int)igot);
mute = 0;
if (16 <= loud)
tmp = 0x000F & (u8)(loud - 16);
else
tmp = 0;
JOT(8, "0x%04X=(mute|tmp|(tmp<<8)) for VT1612A register 0x1C\n",
mute | tmp | (tmp << 8));
write_vt(pusb_device, 0x001C, (mute | tmp | (tmp << 8)));
write_vt(pusb_device, 0x001A, 0x0404);
write_vt(pusb_device, 0x0002, 0x0000);
return 0;
}
