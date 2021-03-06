static int set_freq(struct i2c_client *client, int freq)
{
struct wis_sony_tuner *t = i2c_get_clientdata(client);
char *band_name;
int n;
int band_select;
struct sony_tunertype *tun;
u8 buffer[4];
tun = &sony_tuners[t->type - 200];
if (freq < tun->thresh1) {
band_name = "VHF_L";
band_select = tun->VHF_L;
} else if (freq < tun->thresh2) {
band_name = "VHF_H";
band_select = tun->VHF_H;
} else {
band_name = "UHF";
band_select = tun->UHF;
}
printk(KERN_DEBUG "wis-sony-tuner: tuning to frequency %d.%04d (%s)\n",
freq / 16, (freq % 16) * 625, band_name);
n = freq + tun->IFPCoff;
buffer[0] = n >> 8;
buffer[1] = n & 0xff;
buffer[2] = tun->config;
buffer[3] = band_select;
i2c_master_send(client, buffer, 4);
return 0;
}
static int mpx_write(struct i2c_client *client, int dev, int addr, int val)
{
u8 buffer[5];
struct i2c_msg msg;
buffer[0] = dev;
buffer[1] = addr >> 8;
buffer[2] = addr & 0xff;
buffer[3] = val >> 8;
buffer[4] = val & 0xff;
msg.addr = MPX_I2C_ADDR;
msg.flags = 0;
msg.len = 5;
msg.buf = buffer;
i2c_transfer(client->adapter, &msg, 1);
return 0;
}
static int mpx_setup(struct i2c_client *client)
{
struct wis_sony_tuner *t = i2c_get_clientdata(client);
u16 source = 0;
u8 buffer[3];
struct i2c_msg msg;
buffer[0] = 0x00;
buffer[1] = 0x80;
buffer[2] = 0x00;
msg.addr = MPX_I2C_ADDR;
msg.flags = 0;
msg.len = 3;
msg.buf = buffer;
i2c_transfer(client->adapter, &msg, 1);
buffer[1] = 0x00;
i2c_transfer(client->adapter, &msg, 1);
if (mpx_audio_modes[t->mpxmode].audio_mode != AUD_MONO) {
switch (t->audmode) {
case V4L2_TUNER_MODE_MONO:
switch (mpx_audio_modes[t->mpxmode].audio_mode) {
case AUD_A2:
source = mpx_audio_modes[t->mpxmode].source;
break;
case AUD_NICAM:
source = 0x0000;
break;
case AUD_NICAM_L:
source = 0x0200;
break;
default:
break;
}
break;
case V4L2_TUNER_MODE_STEREO:
source = mpx_audio_modes[t->mpxmode].source;
break;
case V4L2_TUNER_MODE_LANG1:
source = 0x0300;
break;
case V4L2_TUNER_MODE_LANG2:
source = 0x0400;
break;
}
source |= mpx_audio_modes[t->mpxmode].source & 0x00ff;
} else
source = mpx_audio_modes[t->mpxmode].source;
mpx_write(client, 0x10, 0x0030, mpx_audio_modes[t->mpxmode].modus);
mpx_write(client, 0x12, 0x0008, source);
mpx_write(client, 0x12, 0x0013, mpx_audio_modes[t->mpxmode].acb);
mpx_write(client, 0x12, 0x000e,
mpx_audio_modes[t->mpxmode].fm_prescale);
mpx_write(client, 0x12, 0x0010,
mpx_audio_modes[t->mpxmode].nicam_prescale);
mpx_write(client, 0x12, 0x000d,
mpx_audio_modes[t->mpxmode].scart_prescale);
mpx_write(client, 0x10, 0x0020, mpx_audio_modes[t->mpxmode].system);
mpx_write(client, 0x12, 0x0000, mpx_audio_modes[t->mpxmode].volume);
if (mpx_audio_modes[t->mpxmode].audio_mode == AUD_A2)
mpx_write(client, 0x10, 0x0022,
t->audmode == V4L2_TUNER_MODE_MONO ? 0x07f0 : 0x0190);
#ifdef MPX_DEBUG
{
u8 buf1[3], buf2[2];
struct i2c_msg msgs[2];
printk(KERN_DEBUG "wis-sony-tuner: MPX registers: %04x %04x "
"%04x %04x %04x %04x %04x %04x\n",
mpx_audio_modes[t->mpxmode].modus,
source,
mpx_audio_modes[t->mpxmode].acb,
mpx_audio_modes[t->mpxmode].fm_prescale,
mpx_audio_modes[t->mpxmode].nicam_prescale,
mpx_audio_modes[t->mpxmode].scart_prescale,
mpx_audio_modes[t->mpxmode].system,
mpx_audio_modes[t->mpxmode].volume);
buf1[0] = 0x11;
buf1[1] = 0x00;
buf1[2] = 0x7e;
msgs[0].addr = MPX_I2C_ADDR;
msgs[0].flags = 0;
msgs[0].len = 3;
msgs[0].buf = buf1;
msgs[1].addr = MPX_I2C_ADDR;
msgs[1].flags = I2C_M_RD;
msgs[1].len = 2;
msgs[1].buf = buf2;
i2c_transfer(client->adapter, msgs, 2);
printk(KERN_DEBUG "wis-sony-tuner: MPX system: %02x%02x\n",
buf2[0], buf2[1]);
buf1[0] = 0x11;
buf1[1] = 0x02;
buf1[2] = 0x00;
i2c_transfer(client->adapter, msgs, 2);
printk(KERN_DEBUG "wis-sony-tuner: MPX status: %02x%02x\n",
buf2[0], buf2[1]);
}
#endif
return 0;
}
static int set_if(struct i2c_client *client)
{
struct wis_sony_tuner *t = i2c_get_clientdata(client);
u8 buffer[4];
struct i2c_msg msg;
int default_mpx_mode = 0;
buffer[0] = 0;
if (t->std & V4L2_STD_PAL_BG) {
buffer[1] = 0x94;
buffer[2] = 0x70;
buffer[3] = 0x49;
default_mpx_mode = 1;
} else if (t->std & V4L2_STD_PAL_I) {
buffer[1] = 0x14;
buffer[2] = 0x70;
buffer[3] = 0x4a;
default_mpx_mode = 4;
} else if (t->std & V4L2_STD_PAL_DK) {
buffer[1] = 0x14;
buffer[2] = 0x70;
buffer[3] = 0x4b;
default_mpx_mode = 6;
} else if (t->std & V4L2_STD_SECAM_L) {
buffer[1] = 0x04;
buffer[2] = 0x70;
buffer[3] = 0x4b;
default_mpx_mode = 11;
}
msg.addr = IF_I2C_ADDR;
msg.flags = 0;
msg.len = 4;
msg.buf = buffer;
i2c_transfer(client->adapter, &msg, 1);
if (force_mpx_mode >= 0 && force_mpx_mode < MPX_NUM_MODES)
t->mpxmode = force_mpx_mode;
else
t->mpxmode = default_mpx_mode;
printk(KERN_DEBUG "wis-sony-tuner: setting MPX to mode %d\n",
t->mpxmode);
mpx_setup(client);
return 0;
}
static int tuner_command(struct i2c_client *client, unsigned int cmd, void *arg)
{
struct wis_sony_tuner *t = i2c_get_clientdata(client);
switch (cmd) {
#if 0
#ifdef TUNER_SET_TYPE_ADDR
case TUNER_SET_TYPE_ADDR:
{
struct tuner_setup *tun_setup = arg;
int *type = &tun_setup->type;
#else
case TUNER_SET_TYPE:
{
int *type = arg;
#endif
if (t->type >= 0) {
if (t->type != *type)
printk(KERN_ERR "wis-sony-tuner: type already "
"set to %d, ignoring request for %d\n",
t->type, *type);
break;
}
t->type = *type;
switch (t->type) {
case TUNER_SONY_BTF_PG472Z:
switch (force_band_str[0]) {
case 'b':
case 'B':
case 'g':
case 'G':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to PAL-B/G bands\n");
force_band = V4L2_STD_PAL_BG;
break;
case 'i':
case 'I':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to PAL-I band\n");
force_band = V4L2_STD_PAL_I;
break;
case 'd':
case 'D':
case 'k':
case 'K':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to PAL-D/K bands\n");
force_band = V4L2_STD_PAL_I;
break;
case 'l':
case 'L':
printk(KERN_INFO "wis-sony-tuner: forcing "
"tuner to SECAM-L band\n");
force_band = V4L2_STD_SECAM_L;
break;
default:
force_band = 0;
break;
}
if (force_band)
t->std = force_band;
else
t->std = V4L2_STD_PAL_BG;
set_if(client);
break;
case TUNER_SONY_BTF_PK467Z:
t->std = V4L2_STD_NTSC_M_JP;
break;
case TUNER_SONY_BTF_PB463Z:
t->std = V4L2_STD_NTSC_M;
break;
default:
printk(KERN_ERR "wis-sony-tuner: tuner type %d is not "
"supported by this module\n", *type);
break;
}
if (type >= 0)
printk(KERN_INFO
"wis-sony-tuner: type set to %d (%s)\n",
t->type, sony_tuners[t->type - 200].name);
break;
}
#endif
case VIDIOC_G_FREQUENCY:
{
struct v4l2_frequency *f = arg;
f->frequency = t->freq;
break;
}
case VIDIOC_S_FREQUENCY:
{
struct v4l2_frequency *f = arg;
t->freq = f->frequency;
set_freq(client, t->freq);
break;
}
case VIDIOC_ENUMSTD:
{
struct v4l2_standard *std = arg;
switch (t->type) {
case TUNER_SONY_BTF_PG472Z:
switch (std->index) {
case 0:
v4l2_video_std_construct(std,
V4L2_STD_PAL_BG, "PAL-B/G");
break;
case 1:
v4l2_video_std_construct(std,
V4L2_STD_PAL_I, "PAL-I");
break;
case 2:
v4l2_video_std_construct(std,
V4L2_STD_PAL_DK, "PAL-D/K");
break;
case 3:
v4l2_video_std_construct(std,
V4L2_STD_SECAM_L, "SECAM-L");
break;
default:
std->id = 0;
break;
}
break;
case TUNER_SONY_BTF_PK467Z:
if (std->index != 0) {
std->id = 0;
break;
}
v4l2_video_std_construct(std,
V4L2_STD_NTSC_M_JP, "NTSC-J");
break;
case TUNER_SONY_BTF_PB463Z:
if (std->index != 0) {
std->id = 0;
break;
}
v4l2_video_std_construct(std, V4L2_STD_NTSC_M, "NTSC");
break;
}
break;
}
case VIDIOC_G_STD:
{
v4l2_std_id *std = arg;
*std = t->std;
break;
}
case VIDIOC_S_STD:
{
v4l2_std_id *std = arg;
v4l2_std_id old = t->std;
switch (t->type) {
case TUNER_SONY_BTF_PG472Z:
if (force_band && (*std & force_band) != *std &&
*std != V4L2_STD_PAL &&
*std != V4L2_STD_SECAM) {
printk(KERN_DEBUG "wis-sony-tuner: ignoring "
"requested TV standard in "
"favor of force_band value\n");
t->std = force_band;
} else if (*std & V4L2_STD_PAL_BG) {
t->std = V4L2_STD_PAL_BG;
} else if (*std & V4L2_STD_PAL_I) {
t->std = V4L2_STD_PAL_I;
} else if (*std & V4L2_STD_PAL_DK) {
t->std = V4L2_STD_PAL_DK;
} else if (*std & V4L2_STD_SECAM_L) {
t->std = V4L2_STD_SECAM_L;
} else {
printk(KERN_ERR "wis-sony-tuner: TV standard "
"not supported\n");
*std = 0;
break;
}
if (old != t->std)
set_if(client);
break;
case TUNER_SONY_BTF_PK467Z:
if (!(*std & V4L2_STD_NTSC_M_JP)) {
printk(KERN_ERR "wis-sony-tuner: TV standard "
"not supported\n");
*std = 0;
}
break;
case TUNER_SONY_BTF_PB463Z:
if (!(*std & V4L2_STD_NTSC_M)) {
printk(KERN_ERR "wis-sony-tuner: TV standard "
"not supported\n");
*std = 0;
}
break;
}
break;
}
case VIDIOC_QUERYSTD:
{
v4l2_std_id *std = arg;
switch (t->type) {
case TUNER_SONY_BTF_PG472Z:
if (force_band)
*std = force_band;
else
*std = V4L2_STD_PAL_BG | V4L2_STD_PAL_I |
V4L2_STD_PAL_DK | V4L2_STD_SECAM_L;
break;
case TUNER_SONY_BTF_PK467Z:
*std = V4L2_STD_NTSC_M_JP;
break;
case TUNER_SONY_BTF_PB463Z:
*std = V4L2_STD_NTSC_M;
break;
}
break;
}
case VIDIOC_G_TUNER:
{
struct v4l2_tuner *tun = arg;
memset(tun, 0, sizeof(*tun));
strcpy(tun->name, "Television");
tun->type = V4L2_TUNER_ANALOG_TV;
tun->rangelow = 0UL;
tun->rangehigh = 0xffffffffUL;
switch (t->type) {
case TUNER_SONY_BTF_PG472Z:
tun->capability = V4L2_TUNER_CAP_NORM |
V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LANG1 |
V4L2_TUNER_CAP_LANG2;
tun->rxsubchans = V4L2_TUNER_SUB_MONO |
V4L2_TUNER_SUB_STEREO | V4L2_TUNER_SUB_LANG1 |
V4L2_TUNER_SUB_LANG2;
break;
case TUNER_SONY_BTF_PK467Z:
case TUNER_SONY_BTF_PB463Z:
tun->capability = V4L2_TUNER_CAP_STEREO;
tun->rxsubchans = V4L2_TUNER_SUB_MONO |
V4L2_TUNER_SUB_STEREO;
break;
}
tun->audmode = t->audmode;
return 0;
}
case VIDIOC_S_TUNER:
{
struct v4l2_tuner *tun = arg;
switch (t->type) {
case TUNER_SONY_BTF_PG472Z:
if (tun->audmode != t->audmode) {
t->audmode = tun->audmode;
mpx_setup(client);
}
break;
case TUNER_SONY_BTF_PK467Z:
case TUNER_SONY_BTF_PB463Z:
break;
}
return 0;
}
default:
break;
}
return 0;
}
static int wis_sony_tuner_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct wis_sony_tuner *t;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_I2C_BLOCK))
return -ENODEV;
t = kmalloc(sizeof(struct wis_sony_tuner), GFP_KERNEL);
if (t == NULL)
return -ENOMEM;
t->type = -1;
t->freq = 0;
t->mpxmode = 0;
t->audmode = V4L2_TUNER_MODE_STEREO;
i2c_set_clientdata(client, t);
printk(KERN_DEBUG
"wis-sony-tuner: initializing tuner at address %d on %s\n",
client->addr, adapter->name);
return 0;
}
static int wis_sony_tuner_remove(struct i2c_client *client)
{
struct wis_sony_tuner *t = i2c_get_clientdata(client);
kfree(t);
return 0;
}
static int __init wis_sony_tuner_init(void)
{
return i2c_add_driver(&wis_sony_tuner_driver);
}
static void __exit wis_sony_tuner_cleanup(void)
{
i2c_del_driver(&wis_sony_tuner_driver);
}
