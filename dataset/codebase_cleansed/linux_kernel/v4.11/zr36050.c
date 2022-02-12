static u8
zr36050_read (struct zr36050 *ptr,
u16 reg)
{
u8 value = 0;
if (ptr->codec->master_data->readreg)
value = (ptr->codec->master_data->readreg(ptr->codec,
reg)) & 0xFF;
else
dprintk(1,
KERN_ERR "%s: invalid I/O setup, nothing read!\n",
ptr->name);
dprintk(4, "%s: reading from 0x%04x: %02x\n", ptr->name, reg,
value);
return value;
}
static void
zr36050_write (struct zr36050 *ptr,
u16 reg,
u8 value)
{
dprintk(4, "%s: writing 0x%02x to 0x%04x\n", ptr->name, value,
reg);
if (ptr->codec->master_data->writereg)
ptr->codec->master_data->writereg(ptr->codec, reg, value);
else
dprintk(1,
KERN_ERR
"%s: invalid I/O setup, nothing written!\n",
ptr->name);
}
static u8
zr36050_read_status1 (struct zr36050 *ptr)
{
ptr->status1 = zr36050_read(ptr, ZR050_STATUS_1);
zr36050_read(ptr, 0);
return ptr->status1;
}
static u16
zr36050_read_scalefactor (struct zr36050 *ptr)
{
ptr->scalefact = (zr36050_read(ptr, ZR050_SF_HI) << 8) |
(zr36050_read(ptr, ZR050_SF_LO) & 0xFF);
zr36050_read(ptr, 0);
return ptr->scalefact;
}
static void
zr36050_wait_end (struct zr36050 *ptr)
{
int i = 0;
while (!(zr36050_read_status1(ptr) & 0x4)) {
udelay(1);
if (i++ > 200000) {
dprintk(1,
"%s: timeout at wait_end (last status: 0x%02x)\n",
ptr->name, ptr->status1);
break;
}
}
}
static int
zr36050_basic_test (struct zr36050 *ptr)
{
zr36050_write(ptr, ZR050_SOF_IDX, 0x00);
zr36050_write(ptr, ZR050_SOF_IDX + 1, 0x00);
if ((zr36050_read(ptr, ZR050_SOF_IDX) |
zr36050_read(ptr, ZR050_SOF_IDX + 1)) != 0x0000) {
dprintk(1,
KERN_ERR
"%s: attach failed, can't connect to jpeg processor!\n",
ptr->name);
return -ENXIO;
}
zr36050_write(ptr, ZR050_SOF_IDX, 0xff);
zr36050_write(ptr, ZR050_SOF_IDX + 1, 0xc0);
if (((zr36050_read(ptr, ZR050_SOF_IDX) << 8) |
zr36050_read(ptr, ZR050_SOF_IDX + 1)) != 0xffc0) {
dprintk(1,
KERN_ERR
"%s: attach failed, can't connect to jpeg processor!\n",
ptr->name);
return -ENXIO;
}
zr36050_wait_end(ptr);
if ((ptr->status1 & 0x4) == 0) {
dprintk(1,
KERN_ERR
"%s: attach failed, jpeg processor failed (end flag)!\n",
ptr->name);
return -EBUSY;
}
return 0;
}
static int
zr36050_pushit (struct zr36050 *ptr,
u16 startreg,
u16 len,
const char *data)
{
int i = 0;
dprintk(4, "%s: write data block to 0x%04x (len=%d)\n", ptr->name,
startreg, len);
while (i < len) {
zr36050_write(ptr, startreg++, data[i++]);
}
return i;
}
static int
zr36050_set_sof (struct zr36050 *ptr)
{
char sof_data[34];
int i;
dprintk(3, "%s: write SOF (%dx%d, %d components)\n", ptr->name,
ptr->width, ptr->height, NO_OF_COMPONENTS);
sof_data[0] = 0xff;
sof_data[1] = 0xc0;
sof_data[2] = 0x00;
sof_data[3] = (3 * NO_OF_COMPONENTS) + 8;
sof_data[4] = BASELINE_PRECISION;
sof_data[5] = (ptr->height) >> 8;
sof_data[6] = (ptr->height) & 0xff;
sof_data[7] = (ptr->width) >> 8;
sof_data[8] = (ptr->width) & 0xff;
sof_data[9] = NO_OF_COMPONENTS;
for (i = 0; i < NO_OF_COMPONENTS; i++) {
sof_data[10 + (i * 3)] = i;
sof_data[11 + (i * 3)] = (ptr->h_samp_ratio[i] << 4) | (ptr->v_samp_ratio[i]);
sof_data[12 + (i * 3)] = zr36050_tq[i];
}
return zr36050_pushit(ptr, ZR050_SOF_IDX,
(3 * NO_OF_COMPONENTS) + 10, sof_data);
}
static int
zr36050_set_sos (struct zr36050 *ptr)
{
char sos_data[16];
int i;
dprintk(3, "%s: write SOS\n", ptr->name);
sos_data[0] = 0xff;
sos_data[1] = 0xda;
sos_data[2] = 0x00;
sos_data[3] = 2 + 1 + (2 * NO_OF_COMPONENTS) + 3;
sos_data[4] = NO_OF_COMPONENTS;
for (i = 0; i < NO_OF_COMPONENTS; i++) {
sos_data[5 + (i * 2)] = i;
sos_data[6 + (i * 2)] = (zr36050_td[i] << 4) | zr36050_ta[i];
}
sos_data[2 + 1 + (2 * NO_OF_COMPONENTS) + 2] = 00;
sos_data[2 + 1 + (2 * NO_OF_COMPONENTS) + 3] = 0x3F;
sos_data[2 + 1 + (2 * NO_OF_COMPONENTS) + 4] = 00;
return zr36050_pushit(ptr, ZR050_SOS1_IDX,
4 + 1 + (2 * NO_OF_COMPONENTS) + 3,
sos_data);
}
static int
zr36050_set_dri (struct zr36050 *ptr)
{
char dri_data[6];
dprintk(3, "%s: write DRI\n", ptr->name);
dri_data[0] = 0xff;
dri_data[1] = 0xdd;
dri_data[2] = 0x00;
dri_data[3] = 0x04;
dri_data[4] = ptr->dri >> 8;
dri_data[5] = ptr->dri & 0xff;
return zr36050_pushit(ptr, ZR050_DRI_IDX, 6, dri_data);
}
static void
zr36050_init (struct zr36050 *ptr)
{
int sum = 0;
long bitcnt, tmp;
if (ptr->mode == CODEC_DO_COMPRESSION) {
dprintk(2, "%s: COMPRESSION SETUP\n", ptr->name);
zr36050_write(ptr, ZR050_HARDWARE, ZR050_HW_MSTR);
zr36050_write(ptr, ZR050_MODE,
ZR050_MO_COMP | ZR050_MO_TLM);
zr36050_write(ptr, ZR050_OPTIONS, 0);
zr36050_write(ptr, ZR050_INT_REQ_0, 0);
zr36050_write(ptr, ZR050_INT_REQ_1, 3);
zr36050_write(ptr, ZR050_SF_HI, ptr->scalefact >> 8);
zr36050_write(ptr, ZR050_SF_LO, ptr->scalefact & 0xff);
zr36050_write(ptr, ZR050_AF_HI, 0xff);
zr36050_write(ptr, ZR050_AF_M, 0xff);
zr36050_write(ptr, ZR050_AF_LO, 0xff);
sum += zr36050_set_sof(ptr);
sum += zr36050_set_sos(ptr);
sum += zr36050_set_dri(ptr);
dprintk(3, "%s: write DQT, DHT, APP\n", ptr->name);
sum += zr36050_pushit(ptr, ZR050_DQT_IDX,
sizeof(zr36050_dqt), zr36050_dqt);
sum += zr36050_pushit(ptr, ZR050_DHT_IDX,
sizeof(zr36050_dht), zr36050_dht);
zr36050_write(ptr, ZR050_APP_IDX, 0xff);
zr36050_write(ptr, ZR050_APP_IDX + 1, 0xe0 + ptr->app.appn);
zr36050_write(ptr, ZR050_APP_IDX + 2, 0x00);
zr36050_write(ptr, ZR050_APP_IDX + 3, ptr->app.len + 2);
sum += zr36050_pushit(ptr, ZR050_APP_IDX + 4, 60,
ptr->app.data) + 4;
zr36050_write(ptr, ZR050_COM_IDX, 0xff);
zr36050_write(ptr, ZR050_COM_IDX + 1, 0xfe);
zr36050_write(ptr, ZR050_COM_IDX + 2, 0x00);
zr36050_write(ptr, ZR050_COM_IDX + 3, ptr->com.len + 2);
sum += zr36050_pushit(ptr, ZR050_COM_IDX + 4, 60,
ptr->com.data) + 4;
zr36050_write(ptr, ZR050_MARKERS_EN, ZR050_ME_DHTI);
zr36050_write(ptr, ZR050_GO, 1);
zr36050_wait_end(ptr);
dprintk(2, "%s: Status after table preload: 0x%02x\n",
ptr->name, ptr->status1);
if ((ptr->status1 & 0x4) == 0) {
dprintk(1, KERN_ERR "%s: init aborted!\n",
ptr->name);
return;
}
sum = ptr->real_code_vol - sum;
bitcnt = sum << 3;
tmp = bitcnt >> 16;
dprintk(3,
"%s: code: csize=%d, tot=%d, bit=%ld, highbits=%ld\n",
ptr->name, sum, ptr->real_code_vol, bitcnt, tmp);
zr36050_write(ptr, ZR050_TCV_NET_HI, tmp >> 8);
zr36050_write(ptr, ZR050_TCV_NET_MH, tmp & 0xff);
tmp = bitcnt & 0xffff;
zr36050_write(ptr, ZR050_TCV_NET_ML, tmp >> 8);
zr36050_write(ptr, ZR050_TCV_NET_LO, tmp & 0xff);
bitcnt -= bitcnt >> 7;
bitcnt -= ((bitcnt * 5) >> 6);
tmp = bitcnt >> 16;
dprintk(3, "%s: code: nettobit=%ld, highnettobits=%ld\n",
ptr->name, bitcnt, tmp);
zr36050_write(ptr, ZR050_TCV_DATA_HI, tmp >> 8);
zr36050_write(ptr, ZR050_TCV_DATA_MH, tmp & 0xff);
tmp = bitcnt & 0xffff;
zr36050_write(ptr, ZR050_TCV_DATA_ML, tmp >> 8);
zr36050_write(ptr, ZR050_TCV_DATA_LO, tmp & 0xff);
zr36050_write(ptr, ZR050_MODE,
ZR050_MO_COMP | ZR050_MO_PASS2 |
(ptr->bitrate_ctrl ? ZR050_MO_BRC : 0));
zr36050_write(ptr, ZR050_MARKERS_EN,
ZR050_ME_DQT | ZR050_ME_DHT |
((ptr->app.len > 0) ? ZR050_ME_APP : 0) |
((ptr->com.len > 0) ? ZR050_ME_COM : 0));
} else {
dprintk(2, "%s: EXPANSION SETUP\n", ptr->name);
zr36050_write(ptr, ZR050_HARDWARE,
ZR050_HW_MSTR | ZR050_HW_CFIS_2_CLK);
zr36050_write(ptr, ZR050_MODE, ZR050_MO_TLM);
zr36050_write(ptr, ZR050_INT_REQ_0, 0);
zr36050_write(ptr, ZR050_INT_REQ_1, 3);
dprintk(3, "%s: write DHT\n", ptr->name);
zr36050_pushit(ptr, ZR050_DHT_IDX, sizeof(zr36050_dht),
zr36050_dht);
zr36050_write(ptr, ZR050_MARKERS_EN, ZR050_ME_DHTI);
zr36050_write(ptr, ZR050_GO, 1);
zr36050_wait_end(ptr);
dprintk(2, "%s: Status after table preload: 0x%02x\n",
ptr->name, ptr->status1);
if ((ptr->status1 & 0x4) == 0) {
dprintk(1, KERN_ERR "%s: init aborted!\n",
ptr->name);
return;
}
zr36050_write(ptr, ZR050_MODE, 0);
zr36050_write(ptr, ZR050_MARKERS_EN, 0);
}
zr36050_read(ptr, 0);
}
static int
zr36050_set_mode (struct videocodec *codec,
int mode)
{
struct zr36050 *ptr = (struct zr36050 *) codec->data;
dprintk(2, "%s: set_mode %d call\n", ptr->name, mode);
if ((mode != CODEC_DO_EXPANSION) && (mode != CODEC_DO_COMPRESSION))
return -EINVAL;
ptr->mode = mode;
zr36050_init(ptr);
return 0;
}
static int
zr36050_set_video (struct videocodec *codec,
struct tvnorm *norm,
struct vfe_settings *cap,
struct vfe_polarity *pol)
{
struct zr36050 *ptr = (struct zr36050 *) codec->data;
int size;
dprintk(2, "%s: set_video %d.%d, %d/%d-%dx%d (0x%x) q%d call\n",
ptr->name, norm->HStart, norm->VStart,
cap->x, cap->y, cap->width, cap->height,
cap->decimation, cap->quality);
ptr->width = cap->width / (cap->decimation & 0xff);
ptr->height = cap->height / ((cap->decimation >> 8) & 0xff);
size = ptr->width * ptr->height;
size *= 16;
size = size * cap->quality / 200;
if (size < 8192)
size = 8192;
if (size > ptr->total_code_vol * 7)
size = ptr->total_code_vol * 7;
ptr->real_code_vol = size >> 3;
zr36050_write(ptr, ZR050_MBCV, ptr->max_block_vol);
return 0;
}
static int
zr36050_control (struct videocodec *codec,
int type,
int size,
void *data)
{
struct zr36050 *ptr = (struct zr36050 *) codec->data;
int *ival = (int *) data;
dprintk(2, "%s: control %d call with %d byte\n", ptr->name, type,
size);
switch (type) {
case CODEC_G_STATUS:
if (size != sizeof(int))
return -EFAULT;
zr36050_read_status1(ptr);
*ival = ptr->status1;
break;
case CODEC_G_CODEC_MODE:
if (size != sizeof(int))
return -EFAULT;
*ival = CODEC_MODE_BJPG;
break;
case CODEC_S_CODEC_MODE:
if (size != sizeof(int))
return -EFAULT;
if (*ival != CODEC_MODE_BJPG)
return -EINVAL;
return 0;
case CODEC_G_VFE:
case CODEC_S_VFE:
return 0;
case CODEC_S_MMAP:
return -ENXIO;
case CODEC_G_JPEG_TDS_BYTE:
if (size != sizeof(int))
return -EFAULT;
*ival = ptr->total_code_vol;
break;
case CODEC_S_JPEG_TDS_BYTE:
if (size != sizeof(int))
return -EFAULT;
ptr->total_code_vol = *ival;
ptr->real_code_vol = (ptr->total_code_vol * 6) >> 3;
break;
case CODEC_G_JPEG_SCALE:
if (size != sizeof(int))
return -EFAULT;
*ival = zr36050_read_scalefactor(ptr);
break;
case CODEC_S_JPEG_SCALE:
if (size != sizeof(int))
return -EFAULT;
ptr->scalefact = *ival;
break;
case CODEC_G_JPEG_APP_DATA: {
struct jpeg_app_marker *app = data;
if (size != sizeof(struct jpeg_app_marker))
return -EFAULT;
*app = ptr->app;
break;
}
case CODEC_S_JPEG_APP_DATA: {
struct jpeg_app_marker *app = data;
if (size != sizeof(struct jpeg_app_marker))
return -EFAULT;
ptr->app = *app;
break;
}
case CODEC_G_JPEG_COM_DATA: {
struct jpeg_com_marker *com = data;
if (size != sizeof(struct jpeg_com_marker))
return -EFAULT;
*com = ptr->com;
break;
}
case CODEC_S_JPEG_COM_DATA: {
struct jpeg_com_marker *com = data;
if (size != sizeof(struct jpeg_com_marker))
return -EFAULT;
ptr->com = *com;
break;
}
default:
return -EINVAL;
}
return size;
}
static int
zr36050_unset (struct videocodec *codec)
{
struct zr36050 *ptr = codec->data;
if (ptr) {
dprintk(1, "%s: finished codec #%d\n", ptr->name,
ptr->num);
kfree(ptr);
codec->data = NULL;
zr36050_codecs--;
return 0;
}
return -EFAULT;
}
static int
zr36050_setup (struct videocodec *codec)
{
struct zr36050 *ptr;
int res;
dprintk(2, "zr36050: initializing MJPEG subsystem #%d.\n",
zr36050_codecs);
if (zr36050_codecs == MAX_CODECS) {
dprintk(1,
KERN_ERR "zr36050: Can't attach more codecs!\n");
return -ENOSPC;
}
codec->data = ptr = kzalloc(sizeof(struct zr36050), GFP_KERNEL);
if (NULL == ptr) {
dprintk(1, KERN_ERR "zr36050: Can't get enough memory!\n");
return -ENOMEM;
}
snprintf(ptr->name, sizeof(ptr->name), "zr36050[%d]",
zr36050_codecs);
ptr->num = zr36050_codecs++;
ptr->codec = codec;
res = zr36050_basic_test(ptr);
if (res < 0) {
zr36050_unset(codec);
return res;
}
memcpy(ptr->h_samp_ratio, zr36050_decimation_h, 8);
memcpy(ptr->v_samp_ratio, zr36050_decimation_v, 8);
ptr->bitrate_ctrl = 0;
ptr->mode = CODEC_DO_COMPRESSION;
ptr->width = 384;
ptr->height = 288;
ptr->total_code_vol = 16000;
ptr->max_block_vol = 240;
ptr->scalefact = 0x100;
ptr->dri = 1;
ptr->app.appn = 0;
ptr->app.len = 0;
ptr->com.len = 0;
zr36050_init(ptr);
dprintk(1, KERN_INFO "%s: codec attached and running\n",
ptr->name);
return 0;
}
static int __init
zr36050_init_module (void)
{
zr36050_codecs = 0;
return videocodec_register(&zr36050_codec);
}
static void __exit
zr36050_cleanup_module (void)
{
if (zr36050_codecs) {
dprintk(1,
"zr36050: something's wrong - %d codecs left somehow.\n",
zr36050_codecs);
}
videocodec_unregister(&zr36050_codec);
}
