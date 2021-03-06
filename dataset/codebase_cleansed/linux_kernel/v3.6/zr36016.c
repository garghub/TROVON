static u8
zr36016_read (struct zr36016 *ptr,
u16 reg)
{
u8 value = 0;
if (ptr->codec->master_data->readreg)
value =
(ptr->codec->master_data->
readreg(ptr->codec, reg)) & 0xFF;
else
dprintk(1,
KERN_ERR "%s: invalid I/O setup, nothing read!\n",
ptr->name);
dprintk(4, "%s: reading from 0x%04x: %02x\n", ptr->name, reg,
value);
return value;
}
static void
zr36016_write (struct zr36016 *ptr,
u16 reg,
u8 value)
{
dprintk(4, "%s: writing 0x%02x to 0x%04x\n", ptr->name, value,
reg);
if (ptr->codec->master_data->writereg) {
ptr->codec->master_data->writereg(ptr->codec, reg, value);
} else
dprintk(1,
KERN_ERR
"%s: invalid I/O setup, nothing written!\n",
ptr->name);
}
static u8
zr36016_readi (struct zr36016 *ptr,
u16 reg)
{
u8 value = 0;
if ((ptr->codec->master_data->writereg) &&
(ptr->codec->master_data->readreg)) {
ptr->codec->master_data->writereg(ptr->codec, ZR016_IADDR, reg & 0x0F);
value = (ptr->codec->master_data->readreg(ptr->codec, ZR016_IDATA)) & 0xFF;
} else
dprintk(1,
KERN_ERR
"%s: invalid I/O setup, nothing read (i)!\n",
ptr->name);
dprintk(4, "%s: reading indirect from 0x%04x: %02x\n", ptr->name,
reg, value);
return value;
}
static void
zr36016_writei (struct zr36016 *ptr,
u16 reg,
u8 value)
{
dprintk(4, "%s: writing indirect 0x%02x to 0x%04x\n", ptr->name,
value, reg);
if (ptr->codec->master_data->writereg) {
ptr->codec->master_data->writereg(ptr->codec, ZR016_IADDR, reg & 0x0F);
ptr->codec->master_data->writereg(ptr->codec, ZR016_IDATA, value & 0x0FF);
} else
dprintk(1,
KERN_ERR
"%s: invalid I/O setup, nothing written (i)!\n",
ptr->name);
}
static u8
zr36016_read_version (struct zr36016 *ptr)
{
ptr->version = zr36016_read(ptr, 0) >> 4;
return ptr->version;
}
static int
zr36016_basic_test (struct zr36016 *ptr)
{
if (debug) {
int i;
zr36016_writei(ptr, ZR016I_PAX_LO, 0x55);
dprintk(1, KERN_INFO "%s: registers: ", ptr->name);
for (i = 0; i <= 0x0b; i++)
dprintk(1, "%02x ", zr36016_readi(ptr, i));
dprintk(1, "\n");
}
zr36016_writei(ptr, ZR016I_PAX_LO, 0x00);
if (zr36016_readi(ptr, ZR016I_PAX_LO) != 0x0) {
dprintk(1,
KERN_ERR
"%s: attach failed, can't connect to vfe processor!\n",
ptr->name);
return -ENXIO;
}
zr36016_writei(ptr, ZR016I_PAX_LO, 0x0d0);
if (zr36016_readi(ptr, ZR016I_PAX_LO) != 0x0d0) {
dprintk(1,
KERN_ERR
"%s: attach failed, can't connect to vfe processor!\n",
ptr->name);
return -ENXIO;
}
zr36016_read_version(ptr);
if (ptr->version & 0x0c) {
dprintk(1,
KERN_ERR
"%s: attach failed, suspicious version %d found...\n",
ptr->name, ptr->version);
return -ENXIO;
}
return 0;
}
static void
zr36016_init (struct zr36016 *ptr)
{
zr36016_write(ptr, ZR016_GOSTOP, 0);
zr36016_write(ptr, ZR016_MODE,
ZR016_YUV422 | ZR016_YUV422_YUV422 |
(ptr->mode == CODEC_DO_COMPRESSION ?
ZR016_COMPRESSION : ZR016_EXPANSION));
zr36016_writei(ptr, ZR016I_SETUP1,
(ptr->xdec ? (ZR016_HRFL | ZR016_HORZ) : 0) |
(ptr->ydec ? ZR016_VERT : 0) | ZR016_CNTI);
zr36016_writei(ptr, ZR016I_SETUP2, ZR016_CCIR);
zr36016_writei(ptr, ZR016I_PAX_HI, ptr->width >> 8);
zr36016_writei(ptr, ZR016I_PAX_LO, ptr->width & 0xFF);
zr36016_writei(ptr, ZR016I_PAY_HI, ptr->height >> 8);
zr36016_writei(ptr, ZR016I_PAY_LO, ptr->height & 0xFF);
zr36016_writei(ptr, ZR016I_NAX_HI, ptr->xoff >> 8);
zr36016_writei(ptr, ZR016I_NAX_LO, ptr->xoff & 0xFF);
zr36016_writei(ptr, ZR016I_NAY_HI, ptr->yoff >> 8);
zr36016_writei(ptr, ZR016I_NAY_LO, ptr->yoff & 0xFF);
zr36016_write(ptr, ZR016_GOSTOP, 1);
}
static int
zr36016_set_mode (struct videocodec *codec,
int mode)
{
struct zr36016 *ptr = (struct zr36016 *) codec->data;
dprintk(2, "%s: set_mode %d call\n", ptr->name, mode);
if ((mode != CODEC_DO_EXPANSION) && (mode != CODEC_DO_COMPRESSION))
return -EINVAL;
ptr->mode = mode;
zr36016_init(ptr);
return 0;
}
static int
zr36016_set_video (struct videocodec *codec,
struct tvnorm *norm,
struct vfe_settings *cap,
struct vfe_polarity *pol)
{
struct zr36016 *ptr = (struct zr36016 *) codec->data;
dprintk(2, "%s: set_video %d.%d, %d/%d-%dx%d (0x%x) call\n",
ptr->name, norm->HStart, norm->VStart,
cap->x, cap->y, cap->width, cap->height,
cap->decimation);
ptr->width = cap->width;
ptr->height = cap->height;
ptr->xoff = (norm->HStart ? norm->HStart : 1) + cap->x;
ptr->yoff = norm->VStart + cap->y;
ptr->xdec = ((cap->decimation & 0xff) == 1) ? 0 : 1;
ptr->ydec = (((cap->decimation >> 8) & 0xff) == 1) ? 0 : 1;
return 0;
}
static int
zr36016_control (struct videocodec *codec,
int type,
int size,
void *data)
{
struct zr36016 *ptr = (struct zr36016 *) codec->data;
int *ival = (int *) data;
dprintk(2, "%s: control %d call with %d byte\n", ptr->name, type,
size);
switch (type) {
case CODEC_G_STATUS:
if (size != sizeof(int))
return -EFAULT;
*ival = 0;
break;
case CODEC_G_CODEC_MODE:
if (size != sizeof(int))
return -EFAULT;
*ival = 0;
break;
case CODEC_S_CODEC_MODE:
if (size != sizeof(int))
return -EFAULT;
if (*ival != 0)
return -EINVAL;
return 0;
case CODEC_G_VFE:
case CODEC_S_VFE:
return 0;
case CODEC_S_MMAP:
return -ENXIO;
default:
return -EINVAL;
}
return size;
}
static int
zr36016_unset (struct videocodec *codec)
{
struct zr36016 *ptr = codec->data;
if (ptr) {
dprintk(1, "%s: finished codec #%d\n", ptr->name,
ptr->num);
kfree(ptr);
codec->data = NULL;
zr36016_codecs--;
return 0;
}
return -EFAULT;
}
static int
zr36016_setup (struct videocodec *codec)
{
struct zr36016 *ptr;
int res;
dprintk(2, "zr36016: initializing VFE subsystem #%d.\n",
zr36016_codecs);
if (zr36016_codecs == MAX_CODECS) {
dprintk(1,
KERN_ERR "zr36016: Can't attach more codecs!\n");
return -ENOSPC;
}
codec->data = ptr = kzalloc(sizeof(struct zr36016), GFP_KERNEL);
if (NULL == ptr) {
dprintk(1, KERN_ERR "zr36016: Can't get enough memory!\n");
return -ENOMEM;
}
snprintf(ptr->name, sizeof(ptr->name), "zr36016[%d]",
zr36016_codecs);
ptr->num = zr36016_codecs++;
ptr->codec = codec;
res = zr36016_basic_test(ptr);
if (res < 0) {
zr36016_unset(codec);
return res;
}
ptr->mode = CODEC_DO_COMPRESSION;
ptr->width = 768;
ptr->height = 288;
ptr->xdec = 1;
ptr->ydec = 0;
zr36016_init(ptr);
dprintk(1, KERN_INFO "%s: codec v%d attached and running\n",
ptr->name, ptr->version);
return 0;
}
static int __init
zr36016_init_module (void)
{
zr36016_codecs = 0;
return videocodec_register(&zr36016_codec);
}
static void __exit
zr36016_cleanup_module (void)
{
if (zr36016_codecs) {
dprintk(1,
"zr36016: something's wrong - %d codecs left somehow.\n",
zr36016_codecs);
}
videocodec_unregister(&zr36016_codec);
}
