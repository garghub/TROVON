static u8
zr36060_read (struct zr36060 *ptr,
u16 reg)
{
u8 value = 0;
if (ptr->codec->master_data->readreg)
value = (ptr->codec->master_data->readreg(ptr->codec,
reg)) & 0xff;
else
dprintk(1,
KERN_ERR "%s: invalid I/O setup, nothing read!\n",
ptr->name);
return value;
}
static void
zr36060_write(struct zr36060 *ptr,
u16 reg,
u8 value)
{
dprintk(4, "0x%02x @0x%04x\n", value, reg);
if (ptr->codec->master_data->writereg)
ptr->codec->master_data->writereg(ptr->codec, reg, value);
else
dprintk(1,
KERN_ERR
"%s: invalid I/O setup, nothing written!\n",
ptr->name);
}
static u8
zr36060_read_status (struct zr36060 *ptr)
{
ptr->status = zr36060_read(ptr, ZR060_CFSR);
zr36060_read(ptr, 0);
return ptr->status;
}
static u16
zr36060_read_scalefactor (struct zr36060 *ptr)
{
ptr->scalefact = (zr36060_read(ptr, ZR060_SF_HI) << 8) |
(zr36060_read(ptr, ZR060_SF_LO) & 0xFF);
zr36060_read(ptr, 0);
return ptr->scalefact;
}
static void
zr36060_wait_end (struct zr36060 *ptr)
{
int i = 0;
while (zr36060_read_status(ptr) & ZR060_CFSR_Busy) {
udelay(1);
if (i++ > 200000) {
dprintk(1,
"%s: timeout at wait_end (last status: 0x%02x)\n",
ptr->name, ptr->status);
break;
}
}
}
static int
zr36060_basic_test (struct zr36060 *ptr)
{
if ((zr36060_read(ptr, ZR060_IDR_DEV) != 0x33) &&
(zr36060_read(ptr, ZR060_IDR_REV) != 0x01)) {
dprintk(1,
KERN_ERR
"%s: attach failed, can't connect to jpeg processor!\n",
ptr->name);
return -ENXIO;
}
zr36060_wait_end(ptr);
if (ptr->status & ZR060_CFSR_Busy) {
dprintk(1,
KERN_ERR
"%s: attach failed, jpeg processor failed (end flag)!\n",
ptr->name);
return -EBUSY;
}
return 0;
}
static int
zr36060_pushit (struct zr36060 *ptr,
u16 startreg,
u16 len,
const char *data)
{
int i = 0;
dprintk(4, "%s: write data block to 0x%04x (len=%d)\n", ptr->name,
startreg, len);
while (i < len) {
zr36060_write(ptr, startreg++, data[i++]);
}
return i;
}
static int
zr36060_set_sof (struct zr36060 *ptr)
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
sof_data[11 + (i * 3)] = (ptr->h_samp_ratio[i] << 4) |
(ptr->v_samp_ratio[i]);
sof_data[12 + (i * 3)] = zr36060_tq[i];
}
return zr36060_pushit(ptr, ZR060_SOF_IDX,
(3 * NO_OF_COMPONENTS) + 10, sof_data);
}
static int
zr36060_set_sos (struct zr36060 *ptr)
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
sos_data[6 + (i * 2)] = (zr36060_td[i] << 4) |
zr36060_ta[i];
}
sos_data[2 + 1 + (2 * NO_OF_COMPONENTS) + 2] = 00;
sos_data[2 + 1 + (2 * NO_OF_COMPONENTS) + 3] = 0x3f;
sos_data[2 + 1 + (2 * NO_OF_COMPONENTS) + 4] = 00;
return zr36060_pushit(ptr, ZR060_SOS_IDX,
4 + 1 + (2 * NO_OF_COMPONENTS) + 3,
sos_data);
}
static int
zr36060_set_dri (struct zr36060 *ptr)
{
char dri_data[6];
dprintk(3, "%s: write DRI\n", ptr->name);
dri_data[0] = 0xff;
dri_data[1] = 0xdd;
dri_data[2] = 0x00;
dri_data[3] = 0x04;
dri_data[4] = (ptr->dri) >> 8;
dri_data[5] = (ptr->dri) & 0xff;
return zr36060_pushit(ptr, ZR060_DRI_IDX, 6, dri_data);
}
static void
zr36060_init (struct zr36060 *ptr)
{
int sum = 0;
long bitcnt, tmp;
if (ptr->mode == CODEC_DO_COMPRESSION) {
dprintk(2, "%s: COMPRESSION SETUP\n", ptr->name);
zr36060_write(ptr, ZR060_LOAD, ZR060_LOAD_SyncRst);
zr36060_write(ptr, ZR060_CIR, ZR060_CIR_CodeMstr);
zr36060_write(ptr, ZR060_CMR,
ZR060_CMR_Comp | ZR060_CMR_Pass2 |
ZR060_CMR_BRB);
zr36060_write(ptr, ZR060_MBZ, 0x00);
zr36060_write(ptr, ZR060_TCR_HI, 0x00);
zr36060_write(ptr, ZR060_TCR_LO, 0x00);
zr36060_write(ptr, ZR060_IMR, 0);
zr36060_write(ptr, ZR060_SF_HI, ptr->scalefact >> 8);
zr36060_write(ptr, ZR060_SF_LO, ptr->scalefact & 0xff);
zr36060_write(ptr, ZR060_AF_HI, 0xff);
zr36060_write(ptr, ZR060_AF_M, 0xff);
zr36060_write(ptr, ZR060_AF_LO, 0xff);
sum += zr36060_set_sof(ptr);
sum += zr36060_set_sos(ptr);
sum += zr36060_set_dri(ptr);
sum +=
zr36060_pushit(ptr, ZR060_DQT_IDX, sizeof(zr36060_dqt),
zr36060_dqt);
sum +=
zr36060_pushit(ptr, ZR060_DHT_IDX, sizeof(zr36060_dht),
zr36060_dht);
zr36060_write(ptr, ZR060_APP_IDX, 0xff);
zr36060_write(ptr, ZR060_APP_IDX + 1, 0xe0 + ptr->app.appn);
zr36060_write(ptr, ZR060_APP_IDX + 2, 0x00);
zr36060_write(ptr, ZR060_APP_IDX + 3, ptr->app.len + 2);
sum += zr36060_pushit(ptr, ZR060_APP_IDX + 4, 60,
ptr->app.data) + 4;
zr36060_write(ptr, ZR060_COM_IDX, 0xff);
zr36060_write(ptr, ZR060_COM_IDX + 1, 0xfe);
zr36060_write(ptr, ZR060_COM_IDX + 2, 0x00);
zr36060_write(ptr, ZR060_COM_IDX + 3, ptr->com.len + 2);
sum += zr36060_pushit(ptr, ZR060_COM_IDX + 4, 60,
ptr->com.data) + 4;
sum = ptr->real_code_vol - sum;
bitcnt = sum << 3;
tmp = bitcnt >> 16;
dprintk(3,
"%s: code: csize=%d, tot=%d, bit=%ld, highbits=%ld\n",
ptr->name, sum, ptr->real_code_vol, bitcnt, tmp);
zr36060_write(ptr, ZR060_TCV_NET_HI, tmp >> 8);
zr36060_write(ptr, ZR060_TCV_NET_MH, tmp & 0xff);
tmp = bitcnt & 0xffff;
zr36060_write(ptr, ZR060_TCV_NET_ML, tmp >> 8);
zr36060_write(ptr, ZR060_TCV_NET_LO, tmp & 0xff);
bitcnt -= bitcnt >> 7;
bitcnt -= ((bitcnt * 5) >> 6);
tmp = bitcnt >> 16;
dprintk(3, "%s: code: nettobit=%ld, highnettobits=%ld\n",
ptr->name, bitcnt, tmp);
zr36060_write(ptr, ZR060_TCV_DATA_HI, tmp >> 8);
zr36060_write(ptr, ZR060_TCV_DATA_MH, tmp & 0xff);
tmp = bitcnt & 0xffff;
zr36060_write(ptr, ZR060_TCV_DATA_ML, tmp >> 8);
zr36060_write(ptr, ZR060_TCV_DATA_LO, tmp & 0xff);
zr36060_write(ptr, ZR060_MER,
ZR060_MER_DQT | ZR060_MER_DHT |
((ptr->com.len > 0) ? ZR060_MER_Com : 0) |
((ptr->app.len > 0) ? ZR060_MER_App : 0));
zr36060_write(ptr, ZR060_VCR, ZR060_VCR_Range);
} else {
dprintk(2, "%s: EXPANSION SETUP\n", ptr->name);
zr36060_write(ptr, ZR060_LOAD, ZR060_LOAD_SyncRst);
zr36060_write(ptr, ZR060_CIR, ZR060_CIR_CodeMstr);
zr36060_write(ptr, ZR060_CMR, 0);
zr36060_write(ptr, ZR060_MBZ, 0x00);
zr36060_write(ptr, ZR060_TCR_HI, 0x00);
zr36060_write(ptr, ZR060_TCR_LO, 0x00);
zr36060_write(ptr, ZR060_IMR, 0);
zr36060_write(ptr, ZR060_MER, 0);
zr36060_pushit(ptr, ZR060_DHT_IDX, sizeof(zr36060_dht),
zr36060_dht);
zr36060_write(ptr, ZR060_VCR, ZR060_VCR_Range);
}
zr36060_write(ptr, ZR060_LOAD,
ZR060_LOAD_SyncRst | ZR060_LOAD_Load);
zr36060_wait_end(ptr);
dprintk(2, "%s: Status after table preload: 0x%02x\n", ptr->name,
ptr->status);
if (ptr->status & ZR060_CFSR_Busy) {
dprintk(1, KERN_ERR "%s: init aborted!\n", ptr->name);
return;
}
}
static int
zr36060_set_mode (struct videocodec *codec,
int mode)
{
struct zr36060 *ptr = (struct zr36060 *) codec->data;
dprintk(2, "%s: set_mode %d call\n", ptr->name, mode);
if ((mode != CODEC_DO_EXPANSION) && (mode != CODEC_DO_COMPRESSION))
return -EINVAL;
ptr->mode = mode;
zr36060_init(ptr);
return 0;
}
static int
zr36060_set_video (struct videocodec *codec,
struct tvnorm *norm,
struct vfe_settings *cap,
struct vfe_polarity *pol)
{
struct zr36060 *ptr = (struct zr36060 *) codec->data;
u32 reg;
int size;
dprintk(2, "%s: set_video %d/%d-%dx%d (%%%d) call\n", ptr->name,
cap->x, cap->y, cap->width, cap->height, cap->decimation);
ptr->width = cap->width / (cap->decimation & 0xff);
ptr->height = cap->height / (cap->decimation >> 8);
zr36060_write(ptr, ZR060_LOAD, ZR060_LOAD_SyncRst);
reg = (!pol->vsync_pol ? ZR060_VPR_VSPol : 0)
| (!pol->hsync_pol ? ZR060_VPR_HSPol : 0)
| (pol->field_pol ? ZR060_VPR_FIPol : 0)
| (pol->blank_pol ? ZR060_VPR_BLPol : 0)
| (pol->subimg_pol ? ZR060_VPR_SImgPol : 0)
| (pol->poe_pol ? ZR060_VPR_PoePol : 0)
| (pol->pvalid_pol ? ZR060_VPR_PValPol : 0)
| (pol->vclk_pol ? ZR060_VPR_VCLKPol : 0);
zr36060_write(ptr, ZR060_VPR, reg);
reg = 0;
switch (cap->decimation & 0xff) {
default:
case 1:
break;
case 2:
reg |= ZR060_SR_HScale2;
break;
case 4:
reg |= ZR060_SR_HScale4;
break;
}
switch (cap->decimation >> 8) {
default:
case 1:
break;
case 2:
reg |= ZR060_SR_VScale;
break;
}
zr36060_write(ptr, ZR060_SR, reg);
zr36060_write(ptr, ZR060_BCR_Y, 0x00);
zr36060_write(ptr, ZR060_BCR_U, 0x80);
zr36060_write(ptr, ZR060_BCR_V, 0x80);
reg = norm->Ht - 1;
zr36060_write(ptr, ZR060_SGR_VTOTAL_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SGR_VTOTAL_LO, (reg >> 0) & 0xff);
reg = norm->Wt - 1;
zr36060_write(ptr, ZR060_SGR_HTOTAL_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SGR_HTOTAL_LO, (reg >> 0) & 0xff);
reg = 6 - 1;
zr36060_write(ptr, ZR060_SGR_VSYNC, reg);
reg = 68;
zr36060_write(ptr, ZR060_SGR_HSYNC, reg);
reg = norm->VStart - 1;
zr36060_write(ptr, ZR060_SGR_BVSTART, reg);
reg += norm->Ha / 2;
zr36060_write(ptr, ZR060_SGR_BVEND_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SGR_BVEND_LO, (reg >> 0) & 0xff);
reg = norm->HStart - 1;
zr36060_write(ptr, ZR060_SGR_BHSTART, reg);
reg += norm->Wa;
zr36060_write(ptr, ZR060_SGR_BHEND_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SGR_BHEND_LO, (reg >> 0) & 0xff);
reg = cap->y + norm->VStart;
zr36060_write(ptr, ZR060_AAR_VSTART_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_AAR_VSTART_LO, (reg >> 0) & 0xff);
reg += cap->height;
zr36060_write(ptr, ZR060_AAR_VEND_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_AAR_VEND_LO, (reg >> 0) & 0xff);
reg = cap->x + norm->HStart;
zr36060_write(ptr, ZR060_AAR_HSTART_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_AAR_HSTART_LO, (reg >> 0) & 0xff);
reg += cap->width;
zr36060_write(ptr, ZR060_AAR_HEND_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_AAR_HEND_LO, (reg >> 0) & 0xff);
reg = norm->VStart - 4;
zr36060_write(ptr, ZR060_SWR_VSTART_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SWR_VSTART_LO, (reg >> 0) & 0xff);
reg += norm->Ha / 2 + 8;
zr36060_write(ptr, ZR060_SWR_VEND_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SWR_VEND_LO, (reg >> 0) & 0xff);
reg = norm->HStart - 4;
zr36060_write(ptr, ZR060_SWR_HSTART_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SWR_HSTART_LO, (reg >> 0) & 0xff);
reg += norm->Wa + 8;
zr36060_write(ptr, ZR060_SWR_HEND_HI, (reg >> 8) & 0xff);
zr36060_write(ptr, ZR060_SWR_HEND_LO, (reg >> 0) & 0xff);
size = ptr->width * ptr->height;
size = size * 16;
size = size * cap->quality / (low_bitrate ? 400 : 200);
if (size < 8192)
size = 8192;
if (size > ptr->total_code_vol * 7)
size = ptr->total_code_vol * 7;
ptr->real_code_vol = size >> 3;
reg = ptr->max_block_vol;
zr36060_write(ptr, ZR060_MBCVR, reg);
return 0;
}
static int
zr36060_control (struct videocodec *codec,
int type,
int size,
void *data)
{
struct zr36060 *ptr = (struct zr36060 *) codec->data;
int *ival = (int *) data;
dprintk(2, "%s: control %d call with %d byte\n", ptr->name, type,
size);
switch (type) {
case CODEC_G_STATUS:
if (size != sizeof(int))
return -EFAULT;
zr36060_read_status(ptr);
*ival = ptr->status;
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
*ival = zr36060_read_scalefactor(ptr);
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
zr36060_unset (struct videocodec *codec)
{
struct zr36060 *ptr = codec->data;
if (ptr) {
dprintk(1, "%s: finished codec #%d\n", ptr->name,
ptr->num);
kfree(ptr);
codec->data = NULL;
zr36060_codecs--;
return 0;
}
return -EFAULT;
}
static int
zr36060_setup (struct videocodec *codec)
{
struct zr36060 *ptr;
int res;
dprintk(2, "zr36060: initializing MJPEG subsystem #%d.\n",
zr36060_codecs);
if (zr36060_codecs == MAX_CODECS) {
dprintk(1,
KERN_ERR "zr36060: Can't attach more codecs!\n");
return -ENOSPC;
}
codec->data = ptr = kzalloc(sizeof(struct zr36060), GFP_KERNEL);
if (NULL == ptr) {
dprintk(1, KERN_ERR "zr36060: Can't get enough memory!\n");
return -ENOMEM;
}
snprintf(ptr->name, sizeof(ptr->name), "zr36060[%d]",
zr36060_codecs);
ptr->num = zr36060_codecs++;
ptr->codec = codec;
res = zr36060_basic_test(ptr);
if (res < 0) {
zr36060_unset(codec);
return res;
}
memcpy(ptr->h_samp_ratio, zr36060_decimation_h, 8);
memcpy(ptr->v_samp_ratio, zr36060_decimation_v, 8);
ptr->bitrate_ctrl = 0;
ptr->mode = CODEC_DO_COMPRESSION;
ptr->width = 384;
ptr->height = 288;
ptr->total_code_vol = 16000;
ptr->real_code_vol = (ptr->total_code_vol * 6) >> 3;
ptr->max_block_vol = 240;
ptr->scalefact = 0x100;
ptr->dri = 1;
ptr->com.len = 0;
ptr->app.appn = 0;
ptr->app.len = 0;
zr36060_init(ptr);
dprintk(1, KERN_INFO "%s: codec attached and running\n",
ptr->name);
return 0;
}
static int __init
zr36060_init_module (void)
{
zr36060_codecs = 0;
return videocodec_register(&zr36060_codec);
}
static void __exit
zr36060_cleanup_module (void)
{
if (zr36060_codecs) {
dprintk(1,
"zr36060: something's wrong - %d codecs left somehow.\n",
zr36060_codecs);
}
videocodec_unregister(&zr36060_codec);
}
