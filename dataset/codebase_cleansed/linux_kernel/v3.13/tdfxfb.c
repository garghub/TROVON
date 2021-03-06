static inline int mtrr_add(unsigned long base, unsigned long size,
unsigned int type, char increment)
{
return -ENODEV;
}
static inline int mtrr_del(int reg, unsigned long base,
unsigned long size)
{
return -ENODEV;
}
static inline u8 vga_inb(struct tdfx_par *par, u32 reg)
{
return inb(par->iobase + reg - 0x300);
}
static inline void vga_outb(struct tdfx_par *par, u32 reg, u8 val)
{
outb(val, par->iobase + reg - 0x300);
}
static inline void gra_outb(struct tdfx_par *par, u32 idx, u8 val)
{
vga_outb(par, GRA_I, idx);
wmb();
vga_outb(par, GRA_D, val);
wmb();
}
static inline void seq_outb(struct tdfx_par *par, u32 idx, u8 val)
{
vga_outb(par, SEQ_I, idx);
wmb();
vga_outb(par, SEQ_D, val);
wmb();
}
static inline u8 seq_inb(struct tdfx_par *par, u32 idx)
{
vga_outb(par, SEQ_I, idx);
mb();
return vga_inb(par, SEQ_D);
}
static inline void crt_outb(struct tdfx_par *par, u32 idx, u8 val)
{
vga_outb(par, CRT_I, idx);
wmb();
vga_outb(par, CRT_D, val);
wmb();
}
static inline u8 crt_inb(struct tdfx_par *par, u32 idx)
{
vga_outb(par, CRT_I, idx);
mb();
return vga_inb(par, CRT_D);
}
static inline void att_outb(struct tdfx_par *par, u32 idx, u8 val)
{
unsigned char tmp;
tmp = vga_inb(par, IS1_R);
vga_outb(par, ATT_IW, idx);
vga_outb(par, ATT_IW, val);
}
static inline void vga_disable_video(struct tdfx_par *par)
{
unsigned char s;
s = seq_inb(par, 0x01) | 0x20;
seq_outb(par, 0x00, 0x01);
seq_outb(par, 0x01, s);
seq_outb(par, 0x00, 0x03);
}
static inline void vga_enable_video(struct tdfx_par *par)
{
unsigned char s;
s = seq_inb(par, 0x01) & 0xdf;
seq_outb(par, 0x00, 0x01);
seq_outb(par, 0x01, s);
seq_outb(par, 0x00, 0x03);
}
static inline void vga_enable_palette(struct tdfx_par *par)
{
vga_inb(par, IS1_R);
mb();
vga_outb(par, ATT_IW, 0x20);
}
static inline u32 tdfx_inl(struct tdfx_par *par, unsigned int reg)
{
return readl(par->regbase_virt + reg);
}
static inline void tdfx_outl(struct tdfx_par *par, unsigned int reg, u32 val)
{
writel(val, par->regbase_virt + reg);
}
static inline void banshee_make_room(struct tdfx_par *par, int size)
{
while ((tdfx_inl(par, STATUS) & 0x1f) < size - 1)
cpu_relax();
}
static int banshee_wait_idle(struct fb_info *info)
{
struct tdfx_par *par = info->par;
int i = 0;
banshee_make_room(par, 1);
tdfx_outl(par, COMMAND_3D, COMMAND_3D_NOP);
do {
if ((tdfx_inl(par, STATUS) & STATUS_BUSY) == 0)
i++;
} while (i < 3);
return 0;
}
static inline void do_setpalentry(struct tdfx_par *par, unsigned regno, u32 c)
{
banshee_make_room(par, 2);
tdfx_outl(par, DACADDR, regno);
tdfx_inl(par, DACADDR);
tdfx_outl(par, DACDATA, c);
}
static u32 do_calc_pll(int freq, int *freq_out)
{
int m, n, k, best_m, best_n, best_k, best_error;
int fref = 14318;
best_error = freq;
best_n = best_m = best_k = 0;
for (k = 3; k >= 0; k--) {
for (m = 63; m >= 0; m--) {
int n_estimated = ((freq * (m + 2) << k) / fref) - 2;
for (n = max(0, n_estimated);
n <= min(255, n_estimated + 1);
n++) {
int f = (fref * (n + 2) / (m + 2)) >> k;
int error = abs(f - freq);
if (error < best_error) {
best_error = error;
best_n = n;
best_m = m;
best_k = k;
}
}
}
}
n = best_n;
m = best_m;
k = best_k;
*freq_out = (fref * (n + 2) / (m + 2)) >> k;
return (n << 8) | (m << 2) | k;
}
static void do_write_regs(struct fb_info *info, struct banshee_reg *reg)
{
struct tdfx_par *par = info->par;
int i;
banshee_wait_idle(info);
tdfx_outl(par, MISCINIT1, tdfx_inl(par, MISCINIT1) | 0x01);
crt_outb(par, 0x11, crt_inb(par, 0x11) & 0x7f);
banshee_make_room(par, 3);
tdfx_outl(par, VGAINIT1, reg->vgainit1 & 0x001FFFFF);
tdfx_outl(par, VIDPROCCFG, reg->vidcfg & ~0x00000001);
#if 0
tdfx_outl(par, PLLCTRL1, reg->mempll);
tdfx_outl(par, PLLCTRL2, reg->gfxpll);
#endif
tdfx_outl(par, PLLCTRL0, reg->vidpll);
vga_outb(par, MISC_W, reg->misc[0x00] | 0x01);
for (i = 0; i < 5; i++)
seq_outb(par, i, reg->seq[i]);
for (i = 0; i < 25; i++)
crt_outb(par, i, reg->crt[i]);
for (i = 0; i < 9; i++)
gra_outb(par, i, reg->gra[i]);
for (i = 0; i < 21; i++)
att_outb(par, i, reg->att[i]);
crt_outb(par, 0x1a, reg->ext[0]);
crt_outb(par, 0x1b, reg->ext[1]);
vga_enable_palette(par);
vga_enable_video(par);
banshee_make_room(par, 9);
tdfx_outl(par, VGAINIT0, reg->vgainit0);
tdfx_outl(par, DACMODE, reg->dacmode);
tdfx_outl(par, VIDDESKSTRIDE, reg->stride);
tdfx_outl(par, HWCURPATADDR, reg->curspataddr);
tdfx_outl(par, VIDSCREENSIZE, reg->screensize);
tdfx_outl(par, VIDDESKSTART, reg->startaddr);
tdfx_outl(par, VIDPROCCFG, reg->vidcfg);
tdfx_outl(par, VGAINIT1, reg->vgainit1);
tdfx_outl(par, MISCINIT0, reg->miscinit0);
banshee_make_room(par, 8);
tdfx_outl(par, SRCBASE, reg->startaddr);
tdfx_outl(par, DSTBASE, reg->startaddr);
tdfx_outl(par, COMMANDEXTRA_2D, 0);
tdfx_outl(par, CLIP0MIN, 0);
tdfx_outl(par, CLIP0MAX, 0x0fff0fff);
tdfx_outl(par, CLIP1MIN, 0);
tdfx_outl(par, CLIP1MAX, 0x0fff0fff);
tdfx_outl(par, SRCXY, 0);
banshee_wait_idle(info);
}
static unsigned long do_lfb_size(struct tdfx_par *par, unsigned short dev_id)
{
u32 draminit0 = tdfx_inl(par, DRAMINIT0);
u32 draminit1 = tdfx_inl(par, DRAMINIT1);
u32 miscinit1;
int num_chips = (draminit0 & DRAMINIT0_SGRAM_NUM) ? 8 : 4;
int chip_size;
int has_sgram = draminit1 & DRAMINIT1_MEM_SDRAM;
if (dev_id < PCI_DEVICE_ID_3DFX_VOODOO5) {
chip_size = 2;
if (has_sgram && !(draminit0 & DRAMINIT0_SGRAM_TYPE))
chip_size = 1;
} else {
has_sgram = 0;
chip_size = draminit0 & DRAMINIT0_SGRAM_TYPE_MASK;
chip_size = 1 << (chip_size >> DRAMINIT0_SGRAM_TYPE_SHIFT);
}
miscinit1 = tdfx_inl(par, MISCINIT1);
miscinit1 |= has_sgram ? 0 : MISCINIT1_2DBLOCK_DIS;
miscinit1 |= MISCINIT1_CLUT_INV;
banshee_make_room(par, 1);
tdfx_outl(par, MISCINIT1, miscinit1);
return num_chips * chip_size * 1024l * 1024;
}
static int tdfxfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct tdfx_par *par = info->par;
u32 lpitch;
if (var->bits_per_pixel != 8 && var->bits_per_pixel != 16 &&
var->bits_per_pixel != 24 && var->bits_per_pixel != 32) {
DPRINTK("depth not supported: %u\n", var->bits_per_pixel);
return -EINVAL;
}
if (var->xres != var->xres_virtual)
var->xres_virtual = var->xres;
if (var->yres > var->yres_virtual)
var->yres_virtual = var->yres;
if (var->xoffset) {
DPRINTK("xoffset not supported\n");
return -EINVAL;
}
var->yoffset = 0;
if (((var->vmode & FB_VMODE_MASK) == FB_VMODE_INTERLACED) &&
(par->max_pixclock < VOODOO3_MAX_PIXCLOCK)) {
DPRINTK("interlace not supported\n");
return -EINVAL;
}
if (info->monspecs.hfmax && info->monspecs.vfmax &&
info->monspecs.dclkmax && fb_validate_mode(var, info) < 0) {
DPRINTK("mode outside monitor's specs\n");
return -EINVAL;
}
var->xres = (var->xres + 15) & ~15;
lpitch = var->xres * ((var->bits_per_pixel + 7) >> 3);
if (var->xres < 320 || var->xres > 2048) {
DPRINTK("width not supported: %u\n", var->xres);
return -EINVAL;
}
if (var->yres < 200 || var->yres > 2048) {
DPRINTK("height not supported: %u\n", var->yres);
return -EINVAL;
}
if (lpitch * var->yres_virtual > info->fix.smem_len) {
var->yres_virtual = info->fix.smem_len / lpitch;
if (var->yres_virtual < var->yres) {
DPRINTK("no memory for screen (%ux%ux%u)\n",
var->xres, var->yres_virtual,
var->bits_per_pixel);
return -EINVAL;
}
}
if (PICOS2KHZ(var->pixclock) > par->max_pixclock) {
DPRINTK("pixclock too high (%ldKHz)\n",
PICOS2KHZ(var->pixclock));
return -EINVAL;
}
var->transp.offset = 0;
var->transp.length = 0;
switch (var->bits_per_pixel) {
case 8:
var->red.length = 8;
var->red.offset = 0;
var->green = var->red;
var->blue = var->red;
break;
case 16:
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
break;
case 32:
var->transp.offset = 24;
var->transp.length = 8;
case 24:
var->red.offset = 16;
var->green.offset = 8;
var->blue.offset = 0;
var->red.length = var->green.length = var->blue.length = 8;
break;
}
var->width = -1;
var->height = -1;
var->accel_flags = FB_ACCELF_TEXT;
DPRINTK("Checking graphics mode at %dx%d depth %d\n",
var->xres, var->yres, var->bits_per_pixel);
return 0;
}
static int tdfxfb_set_par(struct fb_info *info)
{
struct tdfx_par *par = info->par;
u32 hdispend = info->var.xres;
u32 hsyncsta = hdispend + info->var.right_margin;
u32 hsyncend = hsyncsta + info->var.hsync_len;
u32 htotal = hsyncend + info->var.left_margin;
u32 hd, hs, he, ht, hbs, hbe;
u32 vd, vs, ve, vt, vbs, vbe;
struct banshee_reg reg;
int fout, freq;
u32 wd;
u32 cpp = (info->var.bits_per_pixel + 7) >> 3;
memset(&reg, 0, sizeof(reg));
reg.vidcfg = VIDCFG_VIDPROC_ENABLE | VIDCFG_DESK_ENABLE |
VIDCFG_CURS_X11 |
((cpp - 1) << VIDCFG_PIXFMT_SHIFT) |
(cpp != 1 ? VIDCFG_CLUT_BYPASS : 0);
freq = PICOS2KHZ(info->var.pixclock);
reg.vidcfg &= ~VIDCFG_2X;
if (freq > par->max_pixclock / 2) {
freq = freq > par->max_pixclock ? par->max_pixclock : freq;
reg.dacmode |= DACMODE_2X;
reg.vidcfg |= VIDCFG_2X;
hdispend >>= 1;
hsyncsta >>= 1;
hsyncend >>= 1;
htotal >>= 1;
}
wd = (hdispend >> 3) - 1;
hd = wd;
hs = (hsyncsta >> 3) - 1;
he = (hsyncend >> 3) - 1;
ht = (htotal >> 3) - 1;
hbs = hd;
hbe = ht;
if ((info->var.vmode & FB_VMODE_MASK) == FB_VMODE_DOUBLE) {
vd = (info->var.yres << 1) - 1;
vs = vd + (info->var.lower_margin << 1);
ve = vs + (info->var.vsync_len << 1);
vt = ve + (info->var.upper_margin << 1) - 1;
reg.screensize = info->var.xres | (info->var.yres << 13);
reg.vidcfg |= VIDCFG_HALF_MODE;
reg.crt[0x09] = 0x80;
} else {
vd = info->var.yres - 1;
vs = vd + info->var.lower_margin;
ve = vs + info->var.vsync_len;
vt = ve + info->var.upper_margin - 1;
reg.screensize = info->var.xres | (info->var.yres << 12);
reg.vidcfg &= ~VIDCFG_HALF_MODE;
}
vbs = vd;
vbe = vt;
reg.misc[0x00] = 0x0f |
(info->var.xres < 400 ? 0xa0 :
info->var.xres < 480 ? 0x60 :
info->var.xres < 768 ? 0xe0 : 0x20);
reg.gra[0x05] = 0x40;
reg.gra[0x06] = 0x05;
reg.gra[0x07] = 0x0f;
reg.gra[0x08] = 0xff;
reg.att[0x00] = 0x00;
reg.att[0x01] = 0x01;
reg.att[0x02] = 0x02;
reg.att[0x03] = 0x03;
reg.att[0x04] = 0x04;
reg.att[0x05] = 0x05;
reg.att[0x06] = 0x06;
reg.att[0x07] = 0x07;
reg.att[0x08] = 0x08;
reg.att[0x09] = 0x09;
reg.att[0x0a] = 0x0a;
reg.att[0x0b] = 0x0b;
reg.att[0x0c] = 0x0c;
reg.att[0x0d] = 0x0d;
reg.att[0x0e] = 0x0e;
reg.att[0x0f] = 0x0f;
reg.att[0x10] = 0x41;
reg.att[0x12] = 0x0f;
reg.seq[0x00] = 0x03;
reg.seq[0x01] = 0x01;
reg.seq[0x02] = 0x0f;
reg.seq[0x03] = 0x00;
reg.seq[0x04] = 0x0e;
reg.crt[0x00] = ht - 4;
reg.crt[0x01] = hd;
reg.crt[0x02] = hbs;
reg.crt[0x03] = 0x80 | (hbe & 0x1f);
reg.crt[0x04] = hs;
reg.crt[0x05] = ((hbe & 0x20) << 2) | (he & 0x1f);
reg.crt[0x06] = vt;
reg.crt[0x07] = ((vs & 0x200) >> 2) |
((vd & 0x200) >> 3) |
((vt & 0x200) >> 4) | 0x10 |
((vbs & 0x100) >> 5) |
((vs & 0x100) >> 6) |
((vd & 0x100) >> 7) |
((vt & 0x100) >> 8);
reg.crt[0x09] |= 0x40 | ((vbs & 0x200) >> 4);
reg.crt[0x10] = vs;
reg.crt[0x11] = (ve & 0x0f) | 0x20;
reg.crt[0x12] = vd;
reg.crt[0x13] = wd;
reg.crt[0x15] = vbs;
reg.crt[0x16] = vbe + 1;
reg.crt[0x17] = 0xc3;
reg.crt[0x18] = 0xff;
reg.ext[0x00] = (((ht & 0x100) >> 8) |
((hd & 0x100) >> 6) |
((hbs & 0x100) >> 4) |
((hbe & 0x40) >> 1) |
((hs & 0x100) >> 2) |
((he & 0x20) << 2));
reg.ext[0x01] = (((vt & 0x400) >> 10) |
((vd & 0x400) >> 8) |
((vbs & 0x400) >> 6) |
((vbe & 0x400) >> 4));
reg.vgainit0 = VGAINIT0_8BIT_DAC |
VGAINIT0_EXT_ENABLE |
VGAINIT0_WAKEUP_3C3 |
VGAINIT0_ALT_READBACK |
VGAINIT0_EXTSHIFTOUT;
reg.vgainit1 = tdfx_inl(par, VGAINIT1) & 0x1fffff;
if (hwcursor)
reg.curspataddr = info->fix.smem_len;
reg.cursloc = 0;
reg.cursc0 = 0;
reg.cursc1 = 0xffffff;
reg.stride = info->var.xres * cpp;
reg.startaddr = info->var.yoffset * reg.stride
+ info->var.xoffset * cpp;
reg.vidpll = do_calc_pll(freq, &fout);
#if 0
reg.mempll = do_calc_pll(..., &fout);
reg.gfxpll = do_calc_pll(..., &fout);
#endif
if ((info->var.vmode & FB_VMODE_MASK) == FB_VMODE_INTERLACED)
reg.vidcfg |= VIDCFG_INTERLACE;
reg.miscinit0 = tdfx_inl(par, MISCINIT0);
#if defined(__BIG_ENDIAN)
switch (info->var.bits_per_pixel) {
case 8:
case 24:
reg.miscinit0 &= ~(1 << 30);
reg.miscinit0 &= ~(1 << 31);
break;
case 16:
reg.miscinit0 |= (1 << 30);
reg.miscinit0 |= (1 << 31);
break;
case 32:
reg.miscinit0 |= (1 << 30);
reg.miscinit0 &= ~(1 << 31);
break;
}
#endif
do_write_regs(info, &reg);
info->fix.line_length = reg.stride;
info->fix.visual = (info->var.bits_per_pixel == 8)
? FB_VISUAL_PSEUDOCOLOR
: FB_VISUAL_TRUECOLOR;
DPRINTK("Graphics mode is now set at %dx%d depth %d\n",
info->var.xres, info->var.yres, info->var.bits_per_pixel);
return 0;
}
static int tdfxfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct tdfx_par *par = info->par;
u32 rgbcol;
if (regno >= info->cmap.len || regno > 255)
return 1;
if (info->var.grayscale) {
blue = (red * 77 + green * 151 + blue * 28) >> 8;
green = blue;
red = blue;
}
switch (info->fix.visual) {
case FB_VISUAL_PSEUDOCOLOR:
rgbcol = (((u32)red & 0xff00) << 8) |
(((u32)green & 0xff00) << 0) |
(((u32)blue & 0xff00) >> 8);
do_setpalentry(par, regno, rgbcol);
break;
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
rgbcol = (CNVT_TOHW(red, info->var.red.length) <<
info->var.red.offset) |
(CNVT_TOHW(green, info->var.green.length) <<
info->var.green.offset) |
(CNVT_TOHW(blue, info->var.blue.length) <<
info->var.blue.offset) |
(CNVT_TOHW(transp, info->var.transp.length) <<
info->var.transp.offset);
par->palette[regno] = rgbcol;
}
break;
default:
DPRINTK("bad depth %u\n", info->var.bits_per_pixel);
break;
}
return 0;
}
static int tdfxfb_blank(int blank, struct fb_info *info)
{
struct tdfx_par *par = info->par;
int vgablank = 1;
u32 dacmode = tdfx_inl(par, DACMODE);
dacmode &= ~(BIT(1) | BIT(3));
switch (blank) {
case FB_BLANK_UNBLANK:
vgablank = 0;
break;
case FB_BLANK_NORMAL:
break;
case FB_BLANK_VSYNC_SUSPEND:
dacmode |= BIT(3);
break;
case FB_BLANK_HSYNC_SUSPEND:
dacmode |= BIT(1);
break;
case FB_BLANK_POWERDOWN:
dacmode |= BIT(1) | BIT(3);
break;
}
banshee_make_room(par, 1);
tdfx_outl(par, DACMODE, dacmode);
if (vgablank)
vga_disable_video(par);
else
vga_enable_video(par);
return 0;
}
static int tdfxfb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct tdfx_par *par = info->par;
u32 addr = var->yoffset * info->fix.line_length;
if (nopan || var->xoffset)
return -EINVAL;
banshee_make_room(par, 1);
tdfx_outl(par, VIDDESKSTART, addr);
return 0;
}
static void tdfxfb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
struct tdfx_par *par = info->par;
u32 bpp = info->var.bits_per_pixel;
u32 stride = info->fix.line_length;
u32 fmt = stride | ((bpp + ((bpp == 8) ? 0 : 8)) << 13);
int tdfx_rop;
u32 dx = rect->dx;
u32 dy = rect->dy;
u32 dstbase = 0;
if (rect->rop == ROP_COPY)
tdfx_rop = TDFX_ROP_COPY;
else
tdfx_rop = TDFX_ROP_XOR;
if (dy + rect->height > 4095) {
dstbase = stride * dy;
dy = 0;
}
if (dx + rect->width > 4095) {
dstbase += dx * bpp >> 3;
dx = 0;
}
banshee_make_room(par, 6);
tdfx_outl(par, DSTFORMAT, fmt);
if (info->fix.visual == FB_VISUAL_PSEUDOCOLOR) {
tdfx_outl(par, COLORFORE, rect->color);
} else {
tdfx_outl(par, COLORFORE, par->palette[rect->color]);
}
tdfx_outl(par, COMMAND_2D, COMMAND_2D_FILLRECT | (tdfx_rop << 24));
tdfx_outl(par, DSTBASE, dstbase);
tdfx_outl(par, DSTSIZE, rect->width | (rect->height << 16));
tdfx_outl(par, LAUNCH_2D, dx | (dy << 16));
}
static void tdfxfb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
struct tdfx_par *par = info->par;
u32 sx = area->sx, sy = area->sy, dx = area->dx, dy = area->dy;
u32 bpp = info->var.bits_per_pixel;
u32 stride = info->fix.line_length;
u32 blitcmd = COMMAND_2D_S2S_BITBLT | (TDFX_ROP_COPY << 24);
u32 fmt = stride | ((bpp + ((bpp == 8) ? 0 : 8)) << 13);
u32 dstbase = 0;
u32 srcbase = 0;
if (sy + area->height > 4095) {
srcbase = stride * sy;
sy = 0;
}
if (sx + area->width > 4095) {
srcbase += sx * bpp >> 3;
sx = 0;
}
if (dy + area->height > 4095) {
dstbase = stride * dy;
dy = 0;
}
if (dx + area->width > 4095) {
dstbase += dx * bpp >> 3;
dx = 0;
}
if (area->sx <= area->dx) {
blitcmd |= BIT(14);
sx += area->width - 1;
dx += area->width - 1;
}
if (area->sy <= area->dy) {
blitcmd |= BIT(15);
sy += area->height - 1;
dy += area->height - 1;
}
banshee_make_room(par, 8);
tdfx_outl(par, SRCFORMAT, fmt);
tdfx_outl(par, DSTFORMAT, fmt);
tdfx_outl(par, COMMAND_2D, blitcmd);
tdfx_outl(par, DSTSIZE, area->width | (area->height << 16));
tdfx_outl(par, DSTXY, dx | (dy << 16));
tdfx_outl(par, SRCBASE, srcbase);
tdfx_outl(par, DSTBASE, dstbase);
tdfx_outl(par, LAUNCH_2D, sx | (sy << 16));
}
static void tdfxfb_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct tdfx_par *par = info->par;
int size = image->height * ((image->width * image->depth + 7) >> 3);
int fifo_free;
int i, stride = info->fix.line_length;
u32 bpp = info->var.bits_per_pixel;
u32 dstfmt = stride | ((bpp + ((bpp == 8) ? 0 : 8)) << 13);
u8 *chardata = (u8 *) image->data;
u32 srcfmt;
u32 dx = image->dx;
u32 dy = image->dy;
u32 dstbase = 0;
if (image->depth != 1) {
#ifdef BROKEN_CODE
banshee_make_room(par, 6 + ((size + 3) >> 2));
srcfmt = stride | ((bpp + ((bpp == 8) ? 0 : 8)) << 13) |
0x400000;
#else
cfb_imageblit(info, image);
#endif
return;
}
banshee_make_room(par, 9);
switch (info->fix.visual) {
case FB_VISUAL_PSEUDOCOLOR:
tdfx_outl(par, COLORFORE, image->fg_color);
tdfx_outl(par, COLORBACK, image->bg_color);
break;
case FB_VISUAL_TRUECOLOR:
default:
tdfx_outl(par, COLORFORE,
par->palette[image->fg_color]);
tdfx_outl(par, COLORBACK,
par->palette[image->bg_color]);
}
#ifdef __BIG_ENDIAN
srcfmt = 0x400000 | BIT(20);
#else
srcfmt = 0x400000;
#endif
if (dy + image->height > 4095) {
dstbase = stride * dy;
dy = 0;
}
if (dx + image->width > 4095) {
dstbase += dx * bpp >> 3;
dx = 0;
}
tdfx_outl(par, DSTBASE, dstbase);
tdfx_outl(par, SRCXY, 0);
tdfx_outl(par, DSTXY, dx | (dy << 16));
tdfx_outl(par, COMMAND_2D,
COMMAND_2D_H2S_BITBLT | (TDFX_ROP_COPY << 24));
tdfx_outl(par, SRCFORMAT, srcfmt);
tdfx_outl(par, DSTFORMAT, dstfmt);
tdfx_outl(par, DSTSIZE, image->width | (image->height << 16));
fifo_free = 0;
for (i = (size >> 2); i > 0; i--) {
if (--fifo_free < 0) {
fifo_free = 31;
banshee_make_room(par, fifo_free);
}
tdfx_outl(par, LAUNCH_2D, *(u32 *)chardata);
chardata += 4;
}
banshee_make_room(par, 3);
switch (size % 4) {
case 0:
break;
case 1:
tdfx_outl(par, LAUNCH_2D, *chardata);
break;
case 2:
tdfx_outl(par, LAUNCH_2D, *(u16 *)chardata);
break;
case 3:
tdfx_outl(par, LAUNCH_2D,
*(u16 *)chardata | (chardata[3] << 24));
break;
}
}
static int tdfxfb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
struct tdfx_par *par = info->par;
u32 vidcfg;
if (!hwcursor)
return -EINVAL;
if (cursor->image.width > 64 ||
cursor->image.height > 64 ||
cursor->image.depth > 1)
return -EINVAL;
vidcfg = tdfx_inl(par, VIDPROCCFG);
if (cursor->enable)
tdfx_outl(par, VIDPROCCFG, vidcfg | VIDCFG_HWCURSOR_ENABLE);
else
tdfx_outl(par, VIDPROCCFG, vidcfg & ~VIDCFG_HWCURSOR_ENABLE);
if (!cursor->set)
return 0;
if (cursor->set & FB_CUR_SETCMAP) {
struct fb_cmap cmap = info->cmap;
u32 bg_idx = cursor->image.bg_color;
u32 fg_idx = cursor->image.fg_color;
unsigned long bg_color, fg_color;
fg_color = (((u32)cmap.red[fg_idx] & 0xff00) << 8) |
(((u32)cmap.green[fg_idx] & 0xff00) << 0) |
(((u32)cmap.blue[fg_idx] & 0xff00) >> 8);
bg_color = (((u32)cmap.red[bg_idx] & 0xff00) << 8) |
(((u32)cmap.green[bg_idx] & 0xff00) << 0) |
(((u32)cmap.blue[bg_idx] & 0xff00) >> 8);
banshee_make_room(par, 2);
tdfx_outl(par, HWCURC0, bg_color);
tdfx_outl(par, HWCURC1, fg_color);
}
if (cursor->set & FB_CUR_SETPOS) {
int x = cursor->image.dx;
int y = cursor->image.dy - info->var.yoffset;
x += 63;
y += 63;
banshee_make_room(par, 1);
tdfx_outl(par, HWCURLOC, (y << 16) + x);
}
if (cursor->set & (FB_CUR_SETIMAGE | FB_CUR_SETSHAPE)) {
u8 __iomem *cursorbase = info->screen_base + info->fix.smem_len;
u8 *bitmap = (u8 *)cursor->image.data;
u8 *mask = (u8 *)cursor->mask;
int i;
fb_memset(cursorbase, 0, 1024);
for (i = 0; i < cursor->image.height; i++) {
int h = 0;
int j = (cursor->image.width + 7) >> 3;
for (; j > 0; j--) {
u8 data = *mask ^ *bitmap;
if (cursor->rop == ROP_COPY)
data = *mask & *bitmap;
fb_writeb(*mask, cursorbase + h);
mask++;
fb_writeb(data, cursorbase + h + 8);
bitmap++;
h++;
}
cursorbase += 16;
}
}
return 0;
}
static void tdfxfb_i2c_setscl(void *data, int val)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
unsigned int r;
r = tdfx_inl(par, VIDSERPARPORT);
if (val)
r |= I2C_SCL_OUT;
else
r &= ~I2C_SCL_OUT;
tdfx_outl(par, VIDSERPARPORT, r);
tdfx_inl(par, VIDSERPARPORT);
}
static void tdfxfb_i2c_setsda(void *data, int val)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
unsigned int r;
r = tdfx_inl(par, VIDSERPARPORT);
if (val)
r |= I2C_SDA_OUT;
else
r &= ~I2C_SDA_OUT;
tdfx_outl(par, VIDSERPARPORT, r);
tdfx_inl(par, VIDSERPARPORT);
}
static int tdfxfb_i2c_getscl(void *data)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
return (0 != (tdfx_inl(par, VIDSERPARPORT) & I2C_SCL_IN));
}
static int tdfxfb_i2c_getsda(void *data)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
return (0 != (tdfx_inl(par, VIDSERPARPORT) & I2C_SDA_IN));
}
static void tdfxfb_ddc_setscl(void *data, int val)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
unsigned int r;
r = tdfx_inl(par, VIDSERPARPORT);
if (val)
r |= DDC_SCL_OUT;
else
r &= ~DDC_SCL_OUT;
tdfx_outl(par, VIDSERPARPORT, r);
tdfx_inl(par, VIDSERPARPORT);
}
static void tdfxfb_ddc_setsda(void *data, int val)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
unsigned int r;
r = tdfx_inl(par, VIDSERPARPORT);
if (val)
r |= DDC_SDA_OUT;
else
r &= ~DDC_SDA_OUT;
tdfx_outl(par, VIDSERPARPORT, r);
tdfx_inl(par, VIDSERPARPORT);
}
static int tdfxfb_ddc_getscl(void *data)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
return (0 != (tdfx_inl(par, VIDSERPARPORT) & DDC_SCL_IN));
}
static int tdfxfb_ddc_getsda(void *data)
{
struct tdfxfb_i2c_chan *chan = data;
struct tdfx_par *par = chan->par;
return (0 != (tdfx_inl(par, VIDSERPARPORT) & DDC_SDA_IN));
}
static int tdfxfb_setup_ddc_bus(struct tdfxfb_i2c_chan *chan, const char *name,
struct device *dev)
{
int rc;
strlcpy(chan->adapter.name, name, sizeof(chan->adapter.name));
chan->adapter.owner = THIS_MODULE;
chan->adapter.class = I2C_CLASS_DDC;
chan->adapter.algo_data = &chan->algo;
chan->adapter.dev.parent = dev;
chan->algo.setsda = tdfxfb_ddc_setsda;
chan->algo.setscl = tdfxfb_ddc_setscl;
chan->algo.getsda = tdfxfb_ddc_getsda;
chan->algo.getscl = tdfxfb_ddc_getscl;
chan->algo.udelay = 10;
chan->algo.timeout = msecs_to_jiffies(500);
chan->algo.data = chan;
i2c_set_adapdata(&chan->adapter, chan);
rc = i2c_bit_add_bus(&chan->adapter);
if (rc == 0)
DPRINTK("I2C bus %s registered.\n", name);
else
chan->par = NULL;
return rc;
}
static int tdfxfb_setup_i2c_bus(struct tdfxfb_i2c_chan *chan, const char *name,
struct device *dev)
{
int rc;
strlcpy(chan->adapter.name, name, sizeof(chan->adapter.name));
chan->adapter.owner = THIS_MODULE;
chan->adapter.algo_data = &chan->algo;
chan->adapter.dev.parent = dev;
chan->algo.setsda = tdfxfb_i2c_setsda;
chan->algo.setscl = tdfxfb_i2c_setscl;
chan->algo.getsda = tdfxfb_i2c_getsda;
chan->algo.getscl = tdfxfb_i2c_getscl;
chan->algo.udelay = 10;
chan->algo.timeout = msecs_to_jiffies(500);
chan->algo.data = chan;
i2c_set_adapdata(&chan->adapter, chan);
rc = i2c_bit_add_bus(&chan->adapter);
if (rc == 0)
DPRINTK("I2C bus %s registered.\n", name);
else
chan->par = NULL;
return rc;
}
static void tdfxfb_create_i2c_busses(struct fb_info *info)
{
struct tdfx_par *par = info->par;
tdfx_outl(par, VIDINFORMAT, 0x8160);
tdfx_outl(par, VIDSERPARPORT, 0xcffc0020);
par->chan[0].par = par;
par->chan[1].par = par;
tdfxfb_setup_ddc_bus(&par->chan[0], "Voodoo3-DDC", info->dev);
tdfxfb_setup_i2c_bus(&par->chan[1], "Voodoo3-I2C", info->dev);
}
static void tdfxfb_delete_i2c_busses(struct tdfx_par *par)
{
if (par->chan[0].par)
i2c_del_adapter(&par->chan[0].adapter);
par->chan[0].par = NULL;
if (par->chan[1].par)
i2c_del_adapter(&par->chan[1].adapter);
par->chan[1].par = NULL;
}
static int tdfxfb_probe_i2c_connector(struct tdfx_par *par,
struct fb_monspecs *specs)
{
u8 *edid = NULL;
DPRINTK("Probe DDC Bus\n");
if (par->chan[0].par)
edid = fb_ddc_read(&par->chan[0].adapter);
if (edid) {
fb_edid_to_monspecs(edid, specs);
kfree(edid);
return 0;
}
return 1;
}
static int tdfxfb_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct tdfx_par *default_par;
struct fb_info *info;
int err, lpitch;
struct fb_monspecs *specs;
bool found;
err = pci_enable_device(pdev);
if (err) {
printk(KERN_ERR "tdfxfb: Can't enable pdev: %d\n", err);
return err;
}
info = framebuffer_alloc(sizeof(struct tdfx_par), &pdev->dev);
if (!info)
return -ENOMEM;
default_par = info->par;
info->fix = tdfx_fix;
switch (pdev->device) {
case PCI_DEVICE_ID_3DFX_BANSHEE:
strcpy(info->fix.id, "3Dfx Banshee");
default_par->max_pixclock = BANSHEE_MAX_PIXCLOCK;
break;
case PCI_DEVICE_ID_3DFX_VOODOO3:
strcpy(info->fix.id, "3Dfx Voodoo3");
default_par->max_pixclock = VOODOO3_MAX_PIXCLOCK;
break;
case PCI_DEVICE_ID_3DFX_VOODOO5:
strcpy(info->fix.id, "3Dfx Voodoo5");
default_par->max_pixclock = VOODOO5_MAX_PIXCLOCK;
break;
}
info->fix.mmio_start = pci_resource_start(pdev, 0);
info->fix.mmio_len = pci_resource_len(pdev, 0);
if (!request_mem_region(info->fix.mmio_start, info->fix.mmio_len,
"tdfx regbase")) {
printk(KERN_ERR "tdfxfb: Can't reserve regbase\n");
goto out_err;
}
default_par->regbase_virt =
ioremap_nocache(info->fix.mmio_start, info->fix.mmio_len);
if (!default_par->regbase_virt) {
printk(KERN_ERR "fb: Can't remap %s register area.\n",
info->fix.id);
goto out_err_regbase;
}
info->fix.smem_start = pci_resource_start(pdev, 1);
info->fix.smem_len = do_lfb_size(default_par, pdev->device);
if (!info->fix.smem_len) {
printk(KERN_ERR "fb: Can't count %s memory.\n", info->fix.id);
goto out_err_regbase;
}
if (!request_mem_region(info->fix.smem_start,
pci_resource_len(pdev, 1), "tdfx smem")) {
printk(KERN_ERR "tdfxfb: Can't reserve smem\n");
goto out_err_regbase;
}
info->screen_base = ioremap_nocache(info->fix.smem_start,
info->fix.smem_len);
if (!info->screen_base) {
printk(KERN_ERR "fb: Can't remap %s framebuffer.\n",
info->fix.id);
goto out_err_screenbase;
}
default_par->iobase = pci_resource_start(pdev, 2);
if (!request_region(pci_resource_start(pdev, 2),
pci_resource_len(pdev, 2), "tdfx iobase")) {
printk(KERN_ERR "tdfxfb: Can't reserve iobase\n");
goto out_err_screenbase;
}
printk(KERN_INFO "fb: %s memory = %dK\n", info->fix.id,
info->fix.smem_len >> 10);
default_par->mtrr_handle = -1;
if (!nomtrr)
default_par->mtrr_handle =
mtrr_add(info->fix.smem_start, info->fix.smem_len,
MTRR_TYPE_WRCOMB, 1);
info->fix.ypanstep = nopan ? 0 : 1;
info->fix.ywrapstep = nowrap ? 0 : 1;
info->fbops = &tdfxfb_ops;
info->pseudo_palette = default_par->palette;
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
#ifdef CONFIG_FB_3DFX_ACCEL
info->flags |= FBINFO_HWACCEL_FILLRECT |
FBINFO_HWACCEL_COPYAREA |
FBINFO_HWACCEL_IMAGEBLIT |
FBINFO_READS_FAST;
#endif
if (hwcursor)
info->fix.smem_len = (info->fix.smem_len - 1024) &
(PAGE_MASK << 1);
specs = &info->monspecs;
found = false;
info->var.bits_per_pixel = 8;
#ifdef CONFIG_FB_3DFX_I2C
tdfxfb_create_i2c_busses(info);
err = tdfxfb_probe_i2c_connector(default_par, specs);
if (!err) {
if (specs->modedb == NULL)
DPRINTK("Unable to get Mode Database\n");
else {
const struct fb_videomode *m;
fb_videomode_to_modelist(specs->modedb,
specs->modedb_len,
&info->modelist);
m = fb_find_best_display(specs, &info->modelist);
if (m) {
fb_videomode_to_var(&info->var, m);
if (tdfxfb_check_var(&info->var, info) < 0)
info->var = tdfx_var;
else
found = true;
}
}
}
#endif
if (!mode_option && !found)
mode_option = "640x480@60";
if (mode_option) {
err = fb_find_mode(&info->var, info, mode_option,
specs->modedb, specs->modedb_len,
NULL, info->var.bits_per_pixel);
if (!err || err == 4)
info->var = tdfx_var;
}
if (found) {
fb_destroy_modedb(specs->modedb);
specs->modedb = NULL;
}
lpitch = info->var.xres_virtual * ((info->var.bits_per_pixel + 7) >> 3);
info->var.yres_virtual = info->fix.smem_len / lpitch;
if (info->var.yres_virtual < info->var.yres)
goto out_err_iobase;
if (fb_alloc_cmap(&info->cmap, 256, 0) < 0) {
printk(KERN_ERR "tdfxfb: Can't allocate color map\n");
goto out_err_iobase;
}
if (register_framebuffer(info) < 0) {
printk(KERN_ERR "tdfxfb: can't register framebuffer\n");
fb_dealloc_cmap(&info->cmap);
goto out_err_iobase;
}
pci_set_drvdata(pdev, info);
return 0;
out_err_iobase:
#ifdef CONFIG_FB_3DFX_I2C
tdfxfb_delete_i2c_busses(default_par);
#endif
if (default_par->mtrr_handle >= 0)
mtrr_del(default_par->mtrr_handle, info->fix.smem_start,
info->fix.smem_len);
release_region(pci_resource_start(pdev, 2),
pci_resource_len(pdev, 2));
out_err_screenbase:
if (info->screen_base)
iounmap(info->screen_base);
release_mem_region(info->fix.smem_start, pci_resource_len(pdev, 1));
out_err_regbase:
if (default_par->regbase_virt)
iounmap(default_par->regbase_virt);
release_mem_region(info->fix.mmio_start, info->fix.mmio_len);
out_err:
framebuffer_release(info);
return -ENXIO;
}
static void __init tdfxfb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!*this_opt)
continue;
if (!strcmp(this_opt, "nopan")) {
nopan = 1;
} else if (!strcmp(this_opt, "nowrap")) {
nowrap = 1;
} else if (!strncmp(this_opt, "hwcursor=", 9)) {
hwcursor = simple_strtoul(this_opt + 9, NULL, 0);
#ifdef CONFIG_MTRR
} else if (!strncmp(this_opt, "nomtrr", 6)) {
nomtrr = 1;
#endif
} else {
mode_option = this_opt;
}
}
}
static void tdfxfb_remove(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct tdfx_par *par = info->par;
unregister_framebuffer(info);
#ifdef CONFIG_FB_3DFX_I2C
tdfxfb_delete_i2c_busses(par);
#endif
if (par->mtrr_handle >= 0)
mtrr_del(par->mtrr_handle, info->fix.smem_start,
info->fix.smem_len);
iounmap(par->regbase_virt);
iounmap(info->screen_base);
release_region(pci_resource_start(pdev, 2),
pci_resource_len(pdev, 2));
release_mem_region(pci_resource_start(pdev, 1),
pci_resource_len(pdev, 1));
release_mem_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
static int __init tdfxfb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("tdfxfb", &option))
return -ENODEV;
tdfxfb_setup(option);
#endif
return pci_register_driver(&tdfxfb_driver);
}
static void __exit tdfxfb_exit(void)
{
pci_unregister_driver(&tdfxfb_driver);
}
