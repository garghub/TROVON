static void
SETUP_HW(struct stifb_info *fb)
{
char stat;
do {
stat = READ_BYTE(fb, REG_15b0);
if (!stat)
stat = READ_BYTE(fb, REG_15b0);
} while (stat);
}
static void
SETUP_FB(struct stifb_info *fb)
{
unsigned int reg10_value = 0;
SETUP_HW(fb);
switch (fb->id)
{
case CRT_ID_VISUALIZE_EG:
case S9000_ID_ARTIST:
case S9000_ID_A1659A:
reg10_value = 0x13601000;
break;
case S9000_ID_A1439A:
if (fb->info.var.bits_per_pixel == 32)
reg10_value = 0xBBA0A000;
else
reg10_value = 0x13601000;
break;
case S9000_ID_HCRX:
if (fb->info.var.bits_per_pixel == 32)
reg10_value = 0xBBA0A000;
else
reg10_value = 0x13602000;
break;
case S9000_ID_TIMBER:
case CRX24_OVERLAY_PLANES:
reg10_value = 0x13602000;
break;
}
if (reg10_value)
WRITE_WORD(reg10_value, fb, REG_10);
WRITE_WORD(0x83000300, fb, REG_14);
SETUP_HW(fb);
WRITE_BYTE(1, fb, REG_16b1);
}
static void
START_IMAGE_COLORMAP_ACCESS(struct stifb_info *fb)
{
SETUP_HW(fb);
WRITE_WORD(0xBBE0F000, fb, REG_10);
WRITE_WORD(0x03000300, fb, REG_14);
WRITE_WORD(~0, fb, REG_13);
}
static void
WRITE_IMAGE_COLOR(struct stifb_info *fb, int index, int color)
{
SETUP_HW(fb);
WRITE_WORD(((0x100+index)<<2), fb, REG_3);
WRITE_WORD(color, fb, REG_4);
}
static void
FINISH_IMAGE_COLORMAP_ACCESS(struct stifb_info *fb)
{
WRITE_WORD(0x400, fb, REG_2);
if (fb->info.var.bits_per_pixel == 32) {
WRITE_WORD(0x83000100, fb, REG_1);
} else {
if (fb->id == S9000_ID_ARTIST || fb->id == CRT_ID_VISUALIZE_EG)
WRITE_WORD(0x80000100, fb, REG_26);
else
WRITE_WORD(0x80000100, fb, REG_1);
}
SETUP_FB(fb);
}
static void
SETUP_RAMDAC(struct stifb_info *fb)
{
SETUP_HW(fb);
WRITE_WORD(0x04000000, fb, 0x1020);
WRITE_WORD(0xff000000, fb, 0x1028);
}
static void
CRX24_SETUP_RAMDAC(struct stifb_info *fb)
{
SETUP_HW(fb);
WRITE_WORD(0x04000000, fb, 0x1000);
WRITE_WORD(0x02000000, fb, 0x1004);
WRITE_WORD(0xff000000, fb, 0x1008);
WRITE_WORD(0x05000000, fb, 0x1000);
WRITE_WORD(0x02000000, fb, 0x1004);
WRITE_WORD(0x03000000, fb, 0x1008);
}
static void
CRX24_SET_OVLY_MASK(struct stifb_info *fb)
{
SETUP_HW(fb);
WRITE_WORD(0x13a02000, fb, REG_11);
WRITE_WORD(0x03000300, fb, REG_14);
WRITE_WORD(0x000017f0, fb, REG_3);
WRITE_WORD(0xffffffff, fb, REG_13);
WRITE_WORD(0xffffffff, fb, REG_22);
WRITE_WORD(0x00000000, fb, REG_23);
}
static void
ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable)
{
unsigned int value = enable ? 0x43000000 : 0x03000000;
SETUP_HW(fb);
WRITE_WORD(0x06000000, fb, 0x1030);
WRITE_WORD(value, fb, 0x1038);
}
static void
CRX24_ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable)
{
unsigned int value = enable ? 0x10000000 : 0x30000000;
SETUP_HW(fb);
WRITE_WORD(0x01000000, fb, 0x1000);
WRITE_WORD(0x02000000, fb, 0x1004);
WRITE_WORD(value, fb, 0x1008);
}
static void
ARTIST_ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable)
{
u32 DregsMiscVideo = REG_21;
u32 DregsMiscCtl = REG_27;
SETUP_HW(fb);
if (enable) {
WRITE_WORD(READ_WORD(fb, DregsMiscVideo) | 0x0A000000, fb, DregsMiscVideo);
WRITE_WORD(READ_WORD(fb, DregsMiscCtl) | 0x00800000, fb, DregsMiscCtl);
} else {
WRITE_WORD(READ_WORD(fb, DregsMiscVideo) & ~0x0A000000, fb, DregsMiscVideo);
WRITE_WORD(READ_WORD(fb, DregsMiscCtl) & ~0x00800000, fb, DregsMiscCtl);
}
}
static void
HYPER_ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable)
{
u32 DregsHypMiscVideo = REG_33;
unsigned int value;
SETUP_HW(fb);
value = READ_WORD(fb, DregsHypMiscVideo);
if (enable)
value |= 0x0A000000;
else
value &= ~0x0A000000;
WRITE_WORD(value, fb, DregsHypMiscVideo);
}
static void
SETUP_ATTR_ACCESS(struct stifb_info *fb, unsigned BufferNumber)
{
SETUP_HW(fb);
WRITE_WORD(0x2EA0D000, fb, REG_11);
WRITE_WORD(0x23000302, fb, REG_14);
WRITE_WORD(BufferNumber, fb, REG_12);
WRITE_WORD(0xffffffff, fb, REG_8);
}
static void
SET_ATTR_SIZE(struct stifb_info *fb, int width, int height)
{
WRITE_WORD(0x00000000, fb, REG_6);
WRITE_WORD((width<<16) | height, fb, REG_9);
WRITE_WORD(0x05000000, fb, REG_6);
WRITE_WORD(0x00040001, fb, REG_9);
}
static void
FINISH_ATTR_ACCESS(struct stifb_info *fb)
{
SETUP_HW(fb);
WRITE_WORD(0x00000000, fb, REG_12);
}
static void
elkSetupPlanes(struct stifb_info *fb)
{
SETUP_RAMDAC(fb);
SETUP_FB(fb);
}
static void
ngleSetupAttrPlanes(struct stifb_info *fb, int BufferNumber)
{
SETUP_ATTR_ACCESS(fb, BufferNumber);
SET_ATTR_SIZE(fb, fb->info.var.xres, fb->info.var.yres);
FINISH_ATTR_ACCESS(fb);
SETUP_FB(fb);
}
static void
rattlerSetupPlanes(struct stifb_info *fb)
{
int saved_id, y;
CRX24_SETUP_RAMDAC(fb);
saved_id = fb->id;
fb->id = CRX24_OVERLAY_PLANES;
SETUP_FB(fb);
fb->id = saved_id;
for (y = 0; y < fb->info.var.yres; ++y)
memset(fb->info.screen_base + y * fb->info.fix.line_length,
0xff, fb->info.var.xres * fb->info.var.bits_per_pixel/8);
CRX24_SET_OVLY_MASK(fb);
SETUP_FB(fb);
}
static NgleLutBltCtl
setHyperLutBltCtl(struct stifb_info *fb, int offsetWithinLut, int length)
{
NgleLutBltCtl lutBltCtl;
lutBltCtl.all = 0x80000000;
lutBltCtl.fields.length = length;
lutBltCtl.fields.lutType = HYPER_CMAP_TYPE;
if (fb->info.var.bits_per_pixel == 8)
lutBltCtl.fields.lutOffset = 2 * 256;
else
lutBltCtl.fields.lutOffset = 0 * 256;
lutBltCtl.fields.lutOffset += offsetWithinLut;
return lutBltCtl;
}
static void hyperUndoITE(struct stifb_info *fb)
{
int nFreeFifoSlots = 0;
u32 fbAddr;
NGLE_LOCK(fb);
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 1);
WRITE_WORD(0xffffffff, fb, REG_32);
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 7);
NGLE_QUICK_SET_DST_BM_ACCESS(fb,
BA(IndexedDcd, Otc04, Ots08, AddrLong,
BAJustPoint(0), BINovly, BAIndexBase(0)));
NGLE_QUICK_SET_IMAGE_BITMAP_OP(fb,
IBOvals(RopSrc, MaskAddrOffset(0),
BitmapExtent08, StaticReg(0),
DataDynamic, MaskOtc, BGx(0), FGx(0)));
fbAddr = NGLE_LONG_FB_ADDRESS(0, 1532, 0);
NGLE_BINC_SET_DSTADDR(fb, fbAddr);
NGLE_REALLY_SET_IMAGE_PLANEMASK(fb, 0xffffff);
NGLE_BINC_SET_DSTMASK(fb, 0xffffffff);
NGLE_BINC_WRITE32(fb, 0);
NGLE_UNLOCK(fb);
}
static void
ngleDepth8_ClearImagePlanes(struct stifb_info *fb)
{
}
static void
ngleDepth24_ClearImagePlanes(struct stifb_info *fb)
{
}
static void
ngleResetAttrPlanes(struct stifb_info *fb, unsigned int ctlPlaneReg)
{
int nFreeFifoSlots = 0;
u32 packed_dst;
u32 packed_len;
NGLE_LOCK(fb);
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 4);
NGLE_QUICK_SET_DST_BM_ACCESS(fb,
BA(IndexedDcd, Otc32, OtsIndirect,
AddrLong, BAJustPoint(0),
BINattr, BAIndexBase(0)));
NGLE_QUICK_SET_CTL_PLN_REG(fb, ctlPlaneReg);
NGLE_SET_TRANSFERDATA(fb, 0xffffffff);
NGLE_QUICK_SET_IMAGE_BITMAP_OP(fb,
IBOvals(RopSrc, MaskAddrOffset(0),
BitmapExtent08, StaticReg(1),
DataDynamic, MaskOtc,
BGx(0), FGx(0)));
packed_dst = 0;
packed_len = (fb->info.var.xres << 16) | fb->info.var.yres;
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 2);
NGLE_SET_DSTXY(fb, packed_dst);
SET_LENXY_START_RECFILL(fb, packed_len);
if (fb->id == S9000_ID_A1659A) {
packed_dst = (1280 << 16);
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 2);
NGLE_SET_DSTXY(fb, packed_dst);
packed_len = (4 << 16) | 1;
SET_LENXY_START_RECFILL(fb, packed_len);
}
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 1);
NGLE_QUICK_SET_CTL_PLN_REG(fb, 0);
NGLE_UNLOCK(fb);
}
static void
ngleClearOverlayPlanes(struct stifb_info *fb, int mask, int data)
{
int nFreeFifoSlots = 0;
u32 packed_dst;
u32 packed_len;
NGLE_LOCK(fb);
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 8);
NGLE_QUICK_SET_DST_BM_ACCESS(fb,
BA(IndexedDcd, Otc04, Ots08, AddrLong,
BAJustPoint(0), BINovly, BAIndexBase(0)));
NGLE_SET_TRANSFERDATA(fb, 0xffffffff);
NGLE_REALLY_SET_IMAGE_FG_COLOR(fb, data);
NGLE_REALLY_SET_IMAGE_PLANEMASK(fb, mask);
packed_dst = 0;
packed_len = (fb->info.var.xres << 16) | fb->info.var.yres;
NGLE_SET_DSTXY(fb, packed_dst);
NGLE_QUICK_SET_IMAGE_BITMAP_OP(fb,
IBOvals(RopSrc, MaskAddrOffset(0),
BitmapExtent08, StaticReg(0),
DataDynamic, MaskOtc, BGx(0), FGx(0)));
SET_LENXY_START_RECFILL(fb, packed_len);
NGLE_UNLOCK(fb);
}
static void
hyperResetPlanes(struct stifb_info *fb, int enable)
{
unsigned int controlPlaneReg;
NGLE_LOCK(fb);
if (IS_24_DEVICE(fb))
if (fb->info.var.bits_per_pixel == 32)
controlPlaneReg = 0x04000F00;
else
controlPlaneReg = 0x00000F00;
else
controlPlaneReg = 0x00000F00;
switch (enable) {
case ENABLE:
if (IS_24_DEVICE(fb))
ngleDepth24_ClearImagePlanes(fb);
else
ngleDepth8_ClearImagePlanes(fb);
ngleResetAttrPlanes(fb, controlPlaneReg);
ngleClearOverlayPlanes(fb, 0xff, 255);
hyperUndoITE(fb);
break;
case DISABLE:
if (IS_24_DEVICE(fb))
ngleDepth24_ClearImagePlanes(fb);
else
ngleDepth8_ClearImagePlanes(fb);
ngleResetAttrPlanes(fb, controlPlaneReg);
ngleClearOverlayPlanes(fb, 0xff, 0);
break;
case -1:
hyperUndoITE(fb);
ngleResetAttrPlanes(fb, controlPlaneReg);
break;
}
NGLE_UNLOCK(fb);
}
static void
ngleGetDeviceRomData(struct stifb_info *fb)
{
#if 0
XXX: FIXME: !!!
int *pBytePerLongDevDepData;
int *pRomTable;
NgleDevRomData *pPackedDevRomData;
int sizePackedDevRomData = sizeof(*pPackedDevRomData);
char *pCard8;
int i;
char *mapOrigin = NULL;
int romTableIdx;
pPackedDevRomData = fb->ngle_rom;
SETUP_HW(fb);
if (fb->id == S9000_ID_ARTIST) {
pPackedDevRomData->cursor_pipeline_delay = 4;
pPackedDevRomData->video_interleaves = 4;
} else {
pBytePerLongDevDepData = fb->sti->regions[NGLEDEVDEPROM_CRT_REGION];
if (fb->id == S9000_ID_TOMCAT)
{
GET_ROMTABLE_INDEX(romTableIdx);
while (romTableIdx > 0)
{
pCard8 = (Card8 *) pPackedDevRomData;
pRomTable = pBytePerLongDevDepData;
for (i = 0; i < sizePackedDevRomData; i++)
{
*pCard8++ = (Card8) (*pRomTable++);
}
pBytePerLongDevDepData = (Card32 *)
((Card8 *) pBytePerLongDevDepData +
pPackedDevRomData->sizeof_ngle_data);
romTableIdx--;
}
}
pCard8 = (Card8 *) pPackedDevRomData;
for (i = 0; i < sizePackedDevRomData; i++)
{
*pCard8++ = (Card8) (*pBytePerLongDevDepData++);
}
}
SETUP_FB(fb);
#endif
}
static void __init
SETUP_HCRX(struct stifb_info *fb)
{
int hyperbowl;
int nFreeFifoSlots = 0;
if (fb->id != S9000_ID_HCRX)
return;
GET_FIFO_SLOTS(fb, nFreeFifoSlots, 7);
if (IS_24_DEVICE(fb)) {
hyperbowl = (fb->info.var.bits_per_pixel == 32) ?
HYPERBOWL_MODE01_8_24_LUT0_TRANSPARENT_LUT1_OPAQUE :
HYPERBOWL_MODE01_8_24_LUT0_OPAQUE_LUT1_OPAQUE;
WRITE_WORD(hyperbowl, fb, REG_40);
WRITE_WORD(hyperbowl, fb, REG_40);
WRITE_WORD(HYPERBOWL_MODE2_8_24, fb, REG_39);
WRITE_WORD(0x014c0148, fb, REG_42);
WRITE_WORD(0x404c4048, fb, REG_43);
WRITE_WORD(0x034c0348, fb, REG_44);
WRITE_WORD(0x444c4448, fb, REG_45);
} else {
hyperbowl = HYPERBOWL_MODE_FOR_8_OVER_88_LUT0_NO_TRANSPARENCIES;
WRITE_WORD(hyperbowl, fb, REG_40);
WRITE_WORD(hyperbowl, fb, REG_40);
WRITE_WORD(0x00000000, fb, REG_42);
WRITE_WORD(0x00000000, fb, REG_43);
WRITE_WORD(0x00000000, fb, REG_44);
WRITE_WORD(0x444c4048, fb, REG_45);
}
}
static int
stifb_setcolreg(u_int regno, u_int red, u_int green,
u_int blue, u_int transp, struct fb_info *info)
{
struct stifb_info *fb = container_of(info, struct stifb_info, info);
u32 color;
if (regno >= NR_PALETTE)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
DEBUG_OFF();
START_IMAGE_COLORMAP_ACCESS(fb);
if (unlikely(fb->info.var.grayscale)) {
color = ((red * 77) +
(green * 151) +
(blue * 28)) >> 8;
} else {
color = ((red << 16) |
(green << 8) |
(blue));
}
if (fb->info.fix.visual == FB_VISUAL_DIRECTCOLOR) {
struct fb_var_screeninfo *var = &fb->info.var;
if (regno < 16)
((u32 *)fb->info.pseudo_palette)[regno] =
regno << var->red.offset |
regno << var->green.offset |
regno << var->blue.offset;
}
WRITE_IMAGE_COLOR(fb, regno, color);
if (fb->id == S9000_ID_HCRX) {
NgleLutBltCtl lutBltCtl;
lutBltCtl = setHyperLutBltCtl(fb,
0,
256);
NGLE_BINC_SET_SRCADDR(fb,
NGLE_LONG_FB_ADDRESS(0, 0x100, 0));
START_COLORMAPLOAD(fb, lutBltCtl.all);
SETUP_FB(fb);
} else {
FINISH_IMAGE_COLORMAP_ACCESS(fb);
}
DEBUG_ON();
return 0;
}
static int
stifb_blank(int blank_mode, struct fb_info *info)
{
struct stifb_info *fb = container_of(info, struct stifb_info, info);
int enable = (blank_mode == 0) ? ENABLE : DISABLE;
switch (fb->id) {
case S9000_ID_A1439A:
CRX24_ENABLE_DISABLE_DISPLAY(fb, enable);
break;
case CRT_ID_VISUALIZE_EG:
case S9000_ID_ARTIST:
ARTIST_ENABLE_DISABLE_DISPLAY(fb, enable);
break;
case S9000_ID_HCRX:
HYPER_ENABLE_DISABLE_DISPLAY(fb, enable);
break;
case S9000_ID_A1659A:
case S9000_ID_TIMBER:
case CRX24_OVERLAY_PLANES:
default:
ENABLE_DISABLE_DISPLAY(fb, enable);
break;
}
SETUP_FB(fb);
return 0;
}
static void
stifb_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct stifb_info *fb = container_of(info, struct stifb_info, info);
SETUP_COPYAREA(fb);
SETUP_HW(fb);
if (fb->info.var.bits_per_pixel == 32) {
WRITE_WORD(0xBBA0A000, fb, REG_10);
NGLE_REALLY_SET_IMAGE_PLANEMASK(fb, 0xffffffff);
} else {
WRITE_WORD(fb->id == S9000_ID_HCRX ? 0x13a02000 : 0x13a01000, fb, REG_10);
NGLE_REALLY_SET_IMAGE_PLANEMASK(fb, 0xff);
}
NGLE_QUICK_SET_IMAGE_BITMAP_OP(fb,
IBOvals(RopSrc, MaskAddrOffset(0),
BitmapExtent08, StaticReg(1),
DataDynamic, MaskOtc, BGx(0), FGx(0)));
WRITE_WORD(((area->sx << 16) | area->sy), fb, REG_24);
WRITE_WORD(((area->width << 16) | area->height), fb, REG_7);
WRITE_WORD(((area->dx << 16) | area->dy), fb, REG_25);
SETUP_FB(fb);
}
static void __init
stifb_init_display(struct stifb_info *fb)
{
int id = fb->id;
SETUP_FB(fb);
SETUP_HCRX(fb);
switch (id) {
case S9000_ID_HCRX:
hyperResetPlanes(fb, ENABLE);
break;
case S9000_ID_A1439A:
rattlerSetupPlanes(fb);
break;
case S9000_ID_A1659A:
case S9000_ID_ARTIST:
case CRT_ID_VISUALIZE_EG:
elkSetupPlanes(fb);
break;
}
switch (id) {
case S9000_ID_A1659A:
case S9000_ID_A1439A:
if (fb->info.var.bits_per_pixel == 32)
ngleSetupAttrPlanes(fb, BUFF1_CMAP3);
else {
ngleSetupAttrPlanes(fb, BUFF1_CMAP0);
}
if (id == S9000_ID_A1439A)
ngleClearOverlayPlanes(fb, 0xff, 0);
break;
case S9000_ID_ARTIST:
case CRT_ID_VISUALIZE_EG:
if (fb->info.var.bits_per_pixel == 32)
ngleSetupAttrPlanes(fb, BUFF1_CMAP3);
else {
ngleSetupAttrPlanes(fb, ARTIST_CMAP0);
}
break;
}
stifb_blank(0, (struct fb_info *)fb);
SETUP_FB(fb);
}
static int __init stifb_init_fb(struct sti_struct *sti, int bpp_pref)
{
struct fb_fix_screeninfo *fix;
struct fb_var_screeninfo *var;
struct stifb_info *fb;
struct fb_info *info;
unsigned long sti_rom_address;
char *dev_name;
int bpp, xres, yres;
fb = kzalloc(sizeof(*fb), GFP_ATOMIC);
if (!fb) {
printk(KERN_ERR "stifb: Could not allocate stifb structure\n");
return -ENODEV;
}
info = &fb->info;
fix = &info->fix;
var = &info->var;
fb->sti = sti;
dev_name = sti->sti_data->inq_outptr.dev_name;
fb->id = fb->sti->graphics_id[0];
switch (fb->id) {
case CRT_ID_VISUALIZE_EG:
if (strstr(dev_name, "DX")) {
printk(KERN_WARNING
"WARNING: stifb framebuffer driver does not support '%s' in double-buffer mode.\n"
"WARNING: Please disable the double-buffer mode in IPL menu (the PARISC-BIOS).\n",
dev_name);
goto out_err0;
}
case S9000_ID_ARTIST:
case S9000_ID_HCRX:
case S9000_ID_TIMBER:
case S9000_ID_A1659A:
case S9000_ID_A1439A:
break;
default:
printk(KERN_WARNING "stifb: '%s' (id: 0x%08x) not supported.\n",
dev_name, fb->id);
goto out_err0;
}
bpp = 8;
xres = sti_onscreen_x(fb->sti);
yres = sti_onscreen_y(fb->sti);
ngleGetDeviceRomData(fb);
fix->mmio_start = REGION_BASE(fb,2);
fix->mmio_len = 0x400000;
switch (fb->id) {
case S9000_ID_A1659A:
break;
case S9000_ID_ELM:
var->grayscale = 1;
fb->id = S9000_ID_A1659A;
break;
case S9000_ID_TIMBER:
if (strstr(dev_name, "GRAYSCALE") ||
strstr(dev_name, "Grayscale") ||
strstr(dev_name, "grayscale"))
var->grayscale = 1;
break;
case S9000_ID_TOMCAT:
xres = fb->ngle_rom.x_size_visible;
yres = fb->ngle_rom.y_size_visible;
fb->id = S9000_ID_A1659A;
break;
case S9000_ID_A1439A:
bpp = 32;
break;
case S9000_ID_HCRX:
memset(&fb->ngle_rom, 0, sizeof(fb->ngle_rom));
if ((fb->sti->regions_phys[0] & 0xfc000000) ==
(fb->sti->regions_phys[2] & 0xfc000000))
sti_rom_address = F_EXTEND(fb->sti->regions_phys[0]);
else
sti_rom_address = F_EXTEND(fb->sti->regions_phys[1]);
fb->deviceSpecificConfig = gsc_readl(sti_rom_address);
if (IS_24_DEVICE(fb)) {
if (bpp_pref == 8 || bpp_pref == 32)
bpp = bpp_pref;
else
bpp = 32;
} else
bpp = 8;
READ_WORD(fb, REG_15);
SETUP_HW(fb);
break;
case CRT_ID_VISUALIZE_EG:
case S9000_ID_ARTIST:
break;
default:
#ifdef FALLBACK_TO_1BPP
printk(KERN_WARNING
"stifb: Unsupported graphics card (id=0x%08x) "
"- now trying 1bpp mode instead\n",
fb->id);
bpp = 1;
break;
#else
printk(KERN_WARNING
"stifb: Unsupported graphics card (id=0x%08x) "
"- skipping.\n",
fb->id);
goto out_err0;
#endif
}
fix->smem_start = F_EXTEND(fb->sti->regions_phys[1]);
fix->smem_len = fb->sti->regions[1].region_desc.length * 4096;
fix->line_length = (fb->sti->glob_cfg->total_x * bpp) / 8;
if (!fix->line_length)
fix->line_length = 2048;
if (fix->smem_len > yres*fix->line_length)
fix->smem_len = yres*fix->line_length;
fix->accel = FB_ACCEL_NONE;
switch (bpp) {
case 1:
fix->type = FB_TYPE_PLANES;
fix->visual = FB_VISUAL_MONO10;
var->red.length = var->green.length = var->blue.length = 1;
break;
case 8:
fix->type = FB_TYPE_PACKED_PIXELS;
fix->visual = FB_VISUAL_PSEUDOCOLOR;
var->red.length = var->green.length = var->blue.length = 8;
break;
case 32:
fix->type = FB_TYPE_PACKED_PIXELS;
fix->visual = FB_VISUAL_DIRECTCOLOR;
var->red.length = var->green.length = var->blue.length = var->transp.length = 8;
var->blue.offset = 0;
var->green.offset = 8;
var->red.offset = 16;
var->transp.offset = 24;
break;
default:
break;
}
var->xres = var->xres_virtual = xres;
var->yres = var->yres_virtual = yres;
var->bits_per_pixel = bpp;
strcpy(fix->id, "stifb");
info->fbops = &stifb_ops;
info->screen_base = ioremap_nocache(REGION_BASE(fb,1), fix->smem_len);
if (!info->screen_base) {
printk(KERN_ERR "stifb: failed to map memory\n");
goto out_err0;
}
info->screen_size = fix->smem_len;
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_COPYAREA;
info->pseudo_palette = &fb->pseudo_palette;
if (fb_alloc_cmap(&info->cmap, NR_PALETTE, 0))
goto out_err1;
stifb_init_display(fb);
if (!request_mem_region(fix->smem_start, fix->smem_len, "stifb fb")) {
printk(KERN_ERR "stifb: cannot reserve fb region 0x%04lx-0x%04lx\n",
fix->smem_start, fix->smem_start+fix->smem_len);
goto out_err2;
}
if (!request_mem_region(fix->mmio_start, fix->mmio_len, "stifb mmio")) {
printk(KERN_ERR "stifb: cannot reserve sti mmio region 0x%04lx-0x%04lx\n",
fix->mmio_start, fix->mmio_start+fix->mmio_len);
goto out_err3;
}
if (register_framebuffer(&fb->info) < 0)
goto out_err4;
sti->info = info;
fb_info(&fb->info, "%s %dx%d-%d frame buffer device, %s, id: %04x, mmio: 0x%04lx\n",
fix->id,
var->xres,
var->yres,
var->bits_per_pixel,
dev_name,
fb->id,
fix->mmio_start);
return 0;
out_err4:
release_mem_region(fix->mmio_start, fix->mmio_len);
out_err3:
release_mem_region(fix->smem_start, fix->smem_len);
out_err2:
fb_dealloc_cmap(&info->cmap);
out_err1:
iounmap(info->screen_base);
out_err0:
kfree(fb);
return -ENXIO;
}
static int __init stifb_init(void)
{
struct sti_struct *sti;
struct sti_struct *def_sti;
int i;
#ifndef MODULE
char *option = NULL;
if (fb_get_options("stifb", &option))
return -ENODEV;
stifb_setup(option);
#endif
if (stifb_disabled) {
printk(KERN_INFO "stifb: disabled by \"stifb=off\" kernel parameter\n");
return -ENXIO;
}
def_sti = sti_get_rom(0);
if (def_sti) {
for (i = 1; i <= MAX_STI_ROMS; i++) {
sti = sti_get_rom(i);
if (!sti)
break;
if (sti == def_sti) {
stifb_init_fb(sti, stifb_bpp_pref[i - 1]);
break;
}
}
}
for (i = 1; i <= MAX_STI_ROMS; i++) {
sti = sti_get_rom(i);
if (!sti)
break;
if (sti == def_sti)
continue;
stifb_init_fb(sti, stifb_bpp_pref[i - 1]);
}
return 0;
}
static void __exit
stifb_cleanup(void)
{
struct sti_struct *sti;
int i;
for (i = 1; i <= MAX_STI_ROMS; i++) {
sti = sti_get_rom(i);
if (!sti)
break;
if (sti->info) {
struct fb_info *info = sti->info;
unregister_framebuffer(sti->info);
release_mem_region(info->fix.mmio_start, info->fix.mmio_len);
release_mem_region(info->fix.smem_start, info->fix.smem_len);
if (info->screen_base)
iounmap(info->screen_base);
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
sti->info = NULL;
}
}
int __init
stifb_setup(char *options)
{
int i;
if (!options || !*options)
return 1;
if (strncmp(options, "off", 3) == 0) {
stifb_disabled = 1;
options += 3;
}
if (strncmp(options, "bpp", 3) == 0) {
options += 3;
for (i = 0; i < MAX_STI_ROMS; i++) {
if (*options++ != ':')
break;
stifb_bpp_pref[i] = simple_strtoul(options, &options, 10);
}
}
return 1;
}
