static inline u32 read_reg_le32(volatile u32 __iomem *base, int regindex)
{
#ifdef __powerpc__
return in_le32(base + regindex);
#else
return readl(base + regindex);
#endif
}
static inline void write_reg_le32(volatile u32 __iomem *base, int regindex, u32 val)
{
#ifdef __powerpc__
out_le32(base + regindex, val);
#else
writel(val, base + regindex);
#endif
}
static __u32
getclkMHz(struct imstt_par *par)
{
__u32 clk_m, clk_n, clk_p;
clk_m = par->init.pclk_m;
clk_n = par->init.pclk_n;
clk_p = par->init.pclk_p;
return 20 * (clk_m + 1) / ((clk_n + 1) * (clk_p ? 2 * clk_p : 1));
}
static void
setclkMHz(struct imstt_par *par, __u32 MHz)
{
__u32 clk_m, clk_n, x, stage, spilled;
clk_m = clk_n = 0;
stage = spilled = 0;
for (;;) {
switch (stage) {
case 0:
clk_m++;
break;
case 1:
clk_n++;
break;
}
x = 20 * (clk_m + 1) / (clk_n + 1);
if (x == MHz)
break;
if (x > MHz) {
spilled = 1;
stage = 1;
} else if (spilled && x < MHz) {
stage = 0;
}
}
par->init.pclk_m = clk_m;
par->init.pclk_n = clk_n;
par->init.pclk_p = 0;
}
static struct imstt_regvals *
compute_imstt_regvals_ibm(struct imstt_par *par, int xres, int yres)
{
struct imstt_regvals *init = &par->init;
__u32 MHz, hes, heb, veb, htp, vtp;
switch (xres) {
case 640:
hes = 0x0008; heb = 0x0012; veb = 0x002a; htp = 10; vtp = 2;
MHz = 30 ;
break;
case 832:
hes = 0x0005; heb = 0x0020; veb = 0x0028; htp = 8; vtp = 3;
MHz = 57 ;
break;
case 1024:
hes = 0x000a; heb = 0x001c; veb = 0x0020; htp = 8; vtp = 3;
MHz = 80;
break;
case 1152:
hes = 0x0012; heb = 0x0022; veb = 0x0031; htp = 4; vtp = 3;
MHz = 101 ;
break;
case 1280:
hes = 0x0012; heb = 0x002f; veb = 0x0029; htp = 4; vtp = 1;
MHz = yres == 960 ? 126 : 135;
break;
case 1600:
hes = 0x0018; heb = 0x0040; veb = 0x002a; htp = 4; vtp = 3;
MHz = 200;
break;
default:
return NULL;
}
setclkMHz(par, MHz);
init->hes = hes;
init->heb = heb;
init->hsb = init->heb + (xres >> 3);
init->ht = init->hsb + htp;
init->ves = 0x0003;
init->veb = veb;
init->vsb = init->veb + yres;
init->vt = init->vsb + vtp;
init->vil = init->vsb;
init->pitch = xres;
return init;
}
static struct imstt_regvals *
compute_imstt_regvals_tvp(struct imstt_par *par, int xres, int yres)
{
struct imstt_regvals *init;
switch (xres) {
case 512:
init = &tvp_reg_init_2;
break;
case 640:
init = &tvp_reg_init_6;
break;
case 800:
init = &tvp_reg_init_12;
break;
case 832:
init = &tvp_reg_init_13;
break;
case 1024:
init = &tvp_reg_init_17;
break;
case 1152:
init = &tvp_reg_init_18;
break;
case 1280:
init = yres == 960 ? &tvp_reg_init_19 : &tvp_reg_init_20;
break;
default:
return NULL;
}
par->init = *init;
return init;
}
static struct imstt_regvals *
compute_imstt_regvals (struct imstt_par *par, u_int xres, u_int yres)
{
if (par->ramdac == IBM)
return compute_imstt_regvals_ibm(par, xres, yres);
else
return compute_imstt_regvals_tvp(par, xres, yres);
}
static void
set_imstt_regvals_ibm (struct imstt_par *par, u_int bpp)
{
struct imstt_regvals *init = &par->init;
__u8 pformat = (bpp >> 3) + 2;
par->cmap_regs[PIDXHI] = 0; eieio();
par->cmap_regs[PIDXLO] = PIXM0; eieio();
par->cmap_regs[PIDXDATA] = init->pclk_m;eieio();
par->cmap_regs[PIDXLO] = PIXN0; eieio();
par->cmap_regs[PIDXDATA] = init->pclk_n;eieio();
par->cmap_regs[PIDXLO] = PIXP0; eieio();
par->cmap_regs[PIDXDATA] = init->pclk_p;eieio();
par->cmap_regs[PIDXLO] = PIXC0; eieio();
par->cmap_regs[PIDXDATA] = 0x02; eieio();
par->cmap_regs[PIDXLO] = PIXFMT; eieio();
par->cmap_regs[PIDXDATA] = pformat; eieio();
}
static void
set_imstt_regvals_tvp (struct imstt_par *par, u_int bpp)
{
struct imstt_regvals *init = &par->init;
__u8 tcc, mxc, lckl_n, mic;
__u8 mlc, lckl_p;
switch (bpp) {
default:
case 8:
tcc = 0x80;
mxc = 0x4d;
lckl_n = 0xc1;
mlc = init->mlc[0];
lckl_p = init->lckl_p[0];
break;
case 16:
tcc = 0x44;
mxc = 0x55;
lckl_n = 0xe1;
mlc = init->mlc[1];
lckl_p = init->lckl_p[1];
break;
case 24:
tcc = 0x5e;
mxc = 0x5d;
lckl_n = 0xf1;
mlc = init->mlc[2];
lckl_p = init->lckl_p[2];
break;
case 32:
tcc = 0x46;
mxc = 0x5d;
lckl_n = 0xf1;
mlc = init->mlc[2];
lckl_p = init->lckl_p[2];
break;
}
mic = 0x08;
par->cmap_regs[TVPADDRW] = TVPIRPLA; eieio();
par->cmap_regs[TVPIDATA] = 0x00; eieio();
par->cmap_regs[TVPADDRW] = TVPIRPPD; eieio();
par->cmap_regs[TVPIDATA] = init->pclk_m; eieio();
par->cmap_regs[TVPADDRW] = TVPIRPPD; eieio();
par->cmap_regs[TVPIDATA] = init->pclk_n; eieio();
par->cmap_regs[TVPADDRW] = TVPIRPPD; eieio();
par->cmap_regs[TVPIDATA] = init->pclk_p; eieio();
par->cmap_regs[TVPADDRW] = TVPIRTCC; eieio();
par->cmap_regs[TVPIDATA] = tcc; eieio();
par->cmap_regs[TVPADDRW] = TVPIRMXC; eieio();
par->cmap_regs[TVPIDATA] = mxc; eieio();
par->cmap_regs[TVPADDRW] = TVPIRMIC; eieio();
par->cmap_regs[TVPIDATA] = mic; eieio();
par->cmap_regs[TVPADDRW] = TVPIRPLA; eieio();
par->cmap_regs[TVPIDATA] = 0x00; eieio();
par->cmap_regs[TVPADDRW] = TVPIRLPD; eieio();
par->cmap_regs[TVPIDATA] = lckl_n; eieio();
par->cmap_regs[TVPADDRW] = TVPIRPLA; eieio();
par->cmap_regs[TVPIDATA] = 0x15; eieio();
par->cmap_regs[TVPADDRW] = TVPIRMLC; eieio();
par->cmap_regs[TVPIDATA] = mlc; eieio();
par->cmap_regs[TVPADDRW] = TVPIRPLA; eieio();
par->cmap_regs[TVPIDATA] = 0x2a; eieio();
par->cmap_regs[TVPADDRW] = TVPIRLPD; eieio();
par->cmap_regs[TVPIDATA] = lckl_p; eieio();
}
static void
set_imstt_regvals (struct fb_info *info, u_int bpp)
{
struct imstt_par *par = info->par;
struct imstt_regvals *init = &par->init;
__u32 ctl, pitch, byteswap, scr;
if (par->ramdac == IBM)
set_imstt_regvals_ibm(par, bpp);
else
set_imstt_regvals_tvp(par, bpp);
switch (bpp) {
default:
case 8:
ctl = 0x17b1;
pitch = init->pitch >> 2;
byteswap = 0x000;
break;
case 16:
ctl = 0x17b3;
pitch = init->pitch >> 1;
byteswap = 0x100;
break;
case 24:
ctl = 0x17b9;
pitch = init->pitch - (init->pitch >> 2);
byteswap = 0x200;
break;
case 32:
ctl = 0x17b5;
pitch = init->pitch;
byteswap = 0x300;
break;
}
if (par->ramdac == TVP)
ctl -= 0x30;
write_reg_le32(par->dc_regs, HES, init->hes);
write_reg_le32(par->dc_regs, HEB, init->heb);
write_reg_le32(par->dc_regs, HSB, init->hsb);
write_reg_le32(par->dc_regs, HT, init->ht);
write_reg_le32(par->dc_regs, VES, init->ves);
write_reg_le32(par->dc_regs, VEB, init->veb);
write_reg_le32(par->dc_regs, VSB, init->vsb);
write_reg_le32(par->dc_regs, VT, init->vt);
write_reg_le32(par->dc_regs, VIL, init->vil);
write_reg_le32(par->dc_regs, HCIV, 1);
write_reg_le32(par->dc_regs, VCIV, 1);
write_reg_le32(par->dc_regs, TCDR, 4);
write_reg_le32(par->dc_regs, RRCIV, 1);
write_reg_le32(par->dc_regs, RRSC, 0x980);
write_reg_le32(par->dc_regs, RRCR, 0x11);
if (par->ramdac == IBM) {
write_reg_le32(par->dc_regs, HRIR, 0x0100);
write_reg_le32(par->dc_regs, CMR, 0x00ff);
write_reg_le32(par->dc_regs, SRGCTL, 0x0073);
} else {
write_reg_le32(par->dc_regs, HRIR, 0x0200);
write_reg_le32(par->dc_regs, CMR, 0x01ff);
write_reg_le32(par->dc_regs, SRGCTL, 0x0003);
}
switch (info->fix.smem_len) {
case 0x200000:
scr = 0x059d | byteswap;
break;
default:
pitch >>= 1;
scr = 0x150dd | byteswap;
break;
}
write_reg_le32(par->dc_regs, SCR, scr);
write_reg_le32(par->dc_regs, SPR, pitch);
write_reg_le32(par->dc_regs, STGCTL, ctl);
}
static inline void
set_offset (struct fb_var_screeninfo *var, struct fb_info *info)
{
struct imstt_par *par = info->par;
__u32 off = var->yoffset * (info->fix.line_length >> 3)
+ ((var->xoffset * (info->var.bits_per_pixel >> 3)) >> 3);
write_reg_le32(par->dc_regs, SSR, off);
}
static inline void
set_555 (struct imstt_par *par)
{
if (par->ramdac == IBM) {
par->cmap_regs[PIDXHI] = 0; eieio();
par->cmap_regs[PIDXLO] = BPP16; eieio();
par->cmap_regs[PIDXDATA] = 0x01; eieio();
} else {
par->cmap_regs[TVPADDRW] = TVPIRTCC; eieio();
par->cmap_regs[TVPIDATA] = 0x44; eieio();
}
}
static inline void
set_565 (struct imstt_par *par)
{
if (par->ramdac == IBM) {
par->cmap_regs[PIDXHI] = 0; eieio();
par->cmap_regs[PIDXLO] = BPP16; eieio();
par->cmap_regs[PIDXDATA] = 0x03; eieio();
} else {
par->cmap_regs[TVPADDRW] = TVPIRTCC; eieio();
par->cmap_regs[TVPIDATA] = 0x45; eieio();
}
}
static int
imsttfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
if ((var->bits_per_pixel != 8 && var->bits_per_pixel != 16
&& var->bits_per_pixel != 24 && var->bits_per_pixel != 32)
|| var->xres_virtual < var->xres || var->yres_virtual < var->yres
|| var->nonstd
|| (var->vmode & FB_VMODE_MASK) != FB_VMODE_NONINTERLACED)
return -EINVAL;
if ((var->xres * var->yres) * (var->bits_per_pixel >> 3) > info->fix.smem_len
|| (var->xres_virtual * var->yres_virtual) * (var->bits_per_pixel >> 3) > info->fix.smem_len)
return -EINVAL;
switch (var->bits_per_pixel) {
case 8:
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
break;
case 16:
if (var->green.length != 6)
var->red.offset = 10;
var->red.length = 5;
var->green.offset = 5;
if (var->green.length != 6)
var->green.length = 5;
var->blue.offset = 0;
var->blue.length = 5;
var->transp.offset = 0;
var->transp.length = 0;
break;
case 24:
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
break;
case 32:
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 24;
var->transp.length = 8;
break;
}
if (var->yres == var->yres_virtual) {
__u32 vram = (info->fix.smem_len - (PAGE_SIZE << 2));
var->yres_virtual = ((vram << 3) / var->bits_per_pixel) / var->xres_virtual;
if (var->yres_virtual < var->yres)
var->yres_virtual = var->yres;
}
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
var->transp.msb_right = 0;
var->height = -1;
var->width = -1;
var->vmode = FB_VMODE_NONINTERLACED;
var->left_margin = var->right_margin = 16;
var->upper_margin = var->lower_margin = 16;
var->hsync_len = var->vsync_len = 8;
return 0;
}
static int
imsttfb_set_par(struct fb_info *info)
{
struct imstt_par *par = info->par;
if (!compute_imstt_regvals(par, info->var.xres, info->var.yres))
return -EINVAL;
if (info->var.green.length == 6)
set_565(par);
else
set_555(par);
set_imstt_regvals(info, info->var.bits_per_pixel);
info->var.pixclock = 1000000 / getclkMHz(par);
return 0;
}
static int
imsttfb_setcolreg (u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct imstt_par *par = info->par;
u_int bpp = info->var.bits_per_pixel;
if (regno > 255)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
if (0 && bpp == 16)
par->cmap_regs[PADDRW] = regno << 3;
else
par->cmap_regs[PADDRW] = regno;
eieio();
par->cmap_regs[PDATA] = red; eieio();
par->cmap_regs[PDATA] = green; eieio();
par->cmap_regs[PDATA] = blue; eieio();
if (regno < 16)
switch (bpp) {
case 16:
par->palette[regno] =
(regno << (info->var.green.length ==
5 ? 10 : 11)) | (regno << 5) | regno;
break;
case 24:
par->palette[regno] =
(regno << 16) | (regno << 8) | regno;
break;
case 32: {
int i = (regno << 8) | regno;
par->palette[regno] = (i << 16) |i;
break;
}
}
return 0;
}
static int
imsttfb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
if (var->xoffset + info->var.xres > info->var.xres_virtual
|| var->yoffset + info->var.yres > info->var.yres_virtual)
return -EINVAL;
info->var.xoffset = var->xoffset;
info->var.yoffset = var->yoffset;
set_offset(var, info);
return 0;
}
static int
imsttfb_blank(int blank, struct fb_info *info)
{
struct imstt_par *par = info->par;
__u32 ctrl;
ctrl = read_reg_le32(par->dc_regs, STGCTL);
if (blank > 0) {
switch (blank) {
case FB_BLANK_NORMAL:
case FB_BLANK_POWERDOWN:
ctrl &= ~0x00000380;
if (par->ramdac == IBM) {
par->cmap_regs[PIDXHI] = 0; eieio();
par->cmap_regs[PIDXLO] = MISCTL2; eieio();
par->cmap_regs[PIDXDATA] = 0x55; eieio();
par->cmap_regs[PIDXLO] = MISCTL1; eieio();
par->cmap_regs[PIDXDATA] = 0x11; eieio();
par->cmap_regs[PIDXLO] = SYNCCTL; eieio();
par->cmap_regs[PIDXDATA] = 0x0f; eieio();
par->cmap_regs[PIDXLO] = PWRMNGMT; eieio();
par->cmap_regs[PIDXDATA] = 0x1f; eieio();
par->cmap_regs[PIDXLO] = CLKCTL; eieio();
par->cmap_regs[PIDXDATA] = 0xc0;
}
break;
case FB_BLANK_VSYNC_SUSPEND:
ctrl &= ~0x00000020;
break;
case FB_BLANK_HSYNC_SUSPEND:
ctrl &= ~0x00000010;
break;
}
} else {
if (par->ramdac == IBM) {
ctrl |= 0x000017b0;
par->cmap_regs[PIDXHI] = 0; eieio();
par->cmap_regs[PIDXLO] = CLKCTL; eieio();
par->cmap_regs[PIDXDATA] = 0x01; eieio();
par->cmap_regs[PIDXLO] = PWRMNGMT; eieio();
par->cmap_regs[PIDXDATA] = 0x00; eieio();
par->cmap_regs[PIDXLO] = SYNCCTL; eieio();
par->cmap_regs[PIDXDATA] = 0x00; eieio();
par->cmap_regs[PIDXLO] = MISCTL1; eieio();
par->cmap_regs[PIDXDATA] = 0x01; eieio();
par->cmap_regs[PIDXLO] = MISCTL2; eieio();
par->cmap_regs[PIDXDATA] = 0x45; eieio();
} else
ctrl |= 0x00001780;
}
write_reg_le32(par->dc_regs, STGCTL, ctrl);
return 0;
}
static void
imsttfb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct imstt_par *par = info->par;
__u32 Bpp, line_pitch, bgc, dx, dy, width, height;
bgc = rect->color;
bgc |= (bgc << 8);
bgc |= (bgc << 16);
Bpp = info->var.bits_per_pixel >> 3,
line_pitch = info->fix.line_length;
dy = rect->dy * line_pitch;
dx = rect->dx * Bpp;
height = rect->height;
height--;
width = rect->width * Bpp;
width--;
if (rect->rop == ROP_COPY) {
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x80);
write_reg_le32(par->dc_regs, DSA, dy + dx);
write_reg_le32(par->dc_regs, CNT, (height << 16) | width);
write_reg_le32(par->dc_regs, DP_OCTL, line_pitch);
write_reg_le32(par->dc_regs, BI, 0xffffffff);
write_reg_le32(par->dc_regs, MBC, 0xffffffff);
write_reg_le32(par->dc_regs, CLR, bgc);
write_reg_le32(par->dc_regs, BLTCTL, 0x840);
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x80);
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x40);
} else {
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x80);
write_reg_le32(par->dc_regs, DSA, dy + dx);
write_reg_le32(par->dc_regs, S1SA, dy + dx);
write_reg_le32(par->dc_regs, CNT, (height << 16) | width);
write_reg_le32(par->dc_regs, DP_OCTL, line_pitch);
write_reg_le32(par->dc_regs, SP, line_pitch);
write_reg_le32(par->dc_regs, BLTCTL, 0x40005);
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x80);
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x40);
}
}
static void
imsttfb_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct imstt_par *par = info->par;
__u32 Bpp, line_pitch, fb_offset_old, fb_offset_new, sp, dp_octl;
__u32 cnt, bltctl, sx, sy, dx, dy, height, width;
Bpp = info->var.bits_per_pixel >> 3,
sx = area->sx * Bpp;
sy = area->sy;
dx = area->dx * Bpp;
dy = area->dy;
height = area->height;
height--;
width = area->width * Bpp;
width--;
line_pitch = info->fix.line_length;
bltctl = 0x05;
sp = line_pitch << 16;
cnt = height << 16;
if (sy < dy) {
sy += height;
dy += height;
sp |= -(line_pitch) & 0xffff;
dp_octl = -(line_pitch) & 0xffff;
} else {
sp |= line_pitch;
dp_octl = line_pitch;
}
if (sx < dx) {
sx += width;
dx += width;
bltctl |= 0x80;
cnt |= -(width) & 0xffff;
} else {
cnt |= width;
}
fb_offset_old = sy * line_pitch + sx;
fb_offset_new = dy * line_pitch + dx;
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x80);
write_reg_le32(par->dc_regs, S1SA, fb_offset_old);
write_reg_le32(par->dc_regs, SP, sp);
write_reg_le32(par->dc_regs, DSA, fb_offset_new);
write_reg_le32(par->dc_regs, CNT, cnt);
write_reg_le32(par->dc_regs, DP_OCTL, dp_octl);
write_reg_le32(par->dc_regs, BLTCTL, bltctl);
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x80);
while(read_reg_le32(par->dc_regs, SSTATUS) & 0x40);
}
static int
imsttfb_ioctl(struct fb_info *info, u_int cmd, u_long arg)
{
struct imstt_par *par = info->par;
void __user *argp = (void __user *)arg;
__u32 reg[2];
__u8 idx[2];
switch (cmd) {
case FBIMSTT_SETREG:
if (copy_from_user(reg, argp, 8) || reg[0] > (0x1000 - sizeof(reg[0])) / sizeof(reg[0]))
return -EFAULT;
write_reg_le32(par->dc_regs, reg[0], reg[1]);
return 0;
case FBIMSTT_GETREG:
if (copy_from_user(reg, argp, 4) || reg[0] > (0x1000 - sizeof(reg[0])) / sizeof(reg[0]))
return -EFAULT;
reg[1] = read_reg_le32(par->dc_regs, reg[0]);
if (copy_to_user((void __user *)(arg + 4), &reg[1], 4))
return -EFAULT;
return 0;
case FBIMSTT_SETCMAPREG:
if (copy_from_user(reg, argp, 8) || reg[0] > (0x1000 - sizeof(reg[0])) / sizeof(reg[0]))
return -EFAULT;
write_reg_le32(((u_int __iomem *)par->cmap_regs), reg[0], reg[1]);
return 0;
case FBIMSTT_GETCMAPREG:
if (copy_from_user(reg, argp, 4) || reg[0] > (0x1000 - sizeof(reg[0])) / sizeof(reg[0]))
return -EFAULT;
reg[1] = read_reg_le32(((u_int __iomem *)par->cmap_regs), reg[0]);
if (copy_to_user((void __user *)(arg + 4), &reg[1], 4))
return -EFAULT;
return 0;
case FBIMSTT_SETIDXREG:
if (copy_from_user(idx, argp, 2))
return -EFAULT;
par->cmap_regs[PIDXHI] = 0; eieio();
par->cmap_regs[PIDXLO] = idx[0]; eieio();
par->cmap_regs[PIDXDATA] = idx[1]; eieio();
return 0;
case FBIMSTT_GETIDXREG:
if (copy_from_user(idx, argp, 1))
return -EFAULT;
par->cmap_regs[PIDXHI] = 0; eieio();
par->cmap_regs[PIDXLO] = idx[0]; eieio();
idx[1] = par->cmap_regs[PIDXDATA];
if (copy_to_user((void __user *)(arg + 1), &idx[1], 1))
return -EFAULT;
return 0;
default:
return -ENOIOCTLCMD;
}
}
static void __devinit
init_imstt(struct fb_info *info)
{
struct imstt_par *par = info->par;
__u32 i, tmp, *ip, *end;
tmp = read_reg_le32(par->dc_regs, PRC);
if (par->ramdac == IBM)
info->fix.smem_len = (tmp & 0x0004) ? 0x400000 : 0x200000;
else
info->fix.smem_len = 0x800000;
ip = (__u32 *)info->screen_base;
end = (__u32 *)(info->screen_base + info->fix.smem_len);
while (ip < end)
*ip++ = 0;
tmp = read_reg_le32(par->dc_regs, STGCTL);
write_reg_le32(par->dc_regs, STGCTL, tmp & ~0x1);
write_reg_le32(par->dc_regs, SSR, 0);
if (par->ramdac == IBM) {
par->cmap_regs[PPMASK] = 0xff;
eieio();
par->cmap_regs[PIDXHI] = 0;
eieio();
for (i = 0; i < ARRAY_SIZE(ibm_initregs); i++) {
par->cmap_regs[PIDXLO] = ibm_initregs[i].addr;
eieio();
par->cmap_regs[PIDXDATA] = ibm_initregs[i].value;
eieio();
}
} else {
for (i = 0; i < ARRAY_SIZE(tvp_initregs); i++) {
par->cmap_regs[TVPADDRW] = tvp_initregs[i].addr;
eieio();
par->cmap_regs[TVPIDATA] = tvp_initregs[i].value;
eieio();
}
}
#if USE_NV_MODES && defined(CONFIG_PPC32)
{
int vmode = init_vmode, cmode = init_cmode;
if (vmode == -1) {
vmode = nvram_read_byte(NV_VMODE);
if (vmode <= 0 || vmode > VMODE_MAX)
vmode = VMODE_640_480_67;
}
if (cmode == -1) {
cmode = nvram_read_byte(NV_CMODE);
if (cmode < CMODE_8 || cmode > CMODE_32)
cmode = CMODE_8;
}
if (mac_vmode_to_var(vmode, cmode, &info->var)) {
info->var.xres = info->var.xres_virtual = INIT_XRES;
info->var.yres = info->var.yres_virtual = INIT_YRES;
info->var.bits_per_pixel = INIT_BPP;
}
}
#else
info->var.xres = info->var.xres_virtual = INIT_XRES;
info->var.yres = info->var.yres_virtual = INIT_YRES;
info->var.bits_per_pixel = INIT_BPP;
#endif
if ((info->var.xres * info->var.yres) * (info->var.bits_per_pixel >> 3) > info->fix.smem_len
|| !(compute_imstt_regvals(par, info->var.xres, info->var.yres))) {
printk("imsttfb: %ux%ux%u not supported\n", info->var.xres, info->var.yres, info->var.bits_per_pixel);
framebuffer_release(info);
return;
}
sprintf(info->fix.id, "IMS TT (%s)", par->ramdac == IBM ? "IBM" : "TVP");
info->fix.mmio_len = 0x1000;
info->fix.accel = FB_ACCEL_IMS_TWINTURBO;
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = info->var.bits_per_pixel == 8 ? FB_VISUAL_PSEUDOCOLOR
: FB_VISUAL_DIRECTCOLOR;
info->fix.line_length = info->var.xres * (info->var.bits_per_pixel >> 3);
info->fix.xpanstep = 8;
info->fix.ypanstep = 1;
info->fix.ywrapstep = 0;
info->var.accel_flags = FB_ACCELF_TEXT;
if (info->var.green.length == 6)
set_565(par);
else
set_555(par);
set_imstt_regvals(info, info->var.bits_per_pixel);
info->var.pixclock = 1000000 / getclkMHz(par);
info->fbops = &imsttfb_ops;
info->flags = FBINFO_DEFAULT |
FBINFO_HWACCEL_COPYAREA |
FBINFO_HWACCEL_FILLRECT |
FBINFO_HWACCEL_YPAN;
fb_alloc_cmap(&info->cmap, 0, 0);
if (register_framebuffer(info) < 0) {
framebuffer_release(info);
return;
}
tmp = (read_reg_le32(par->dc_regs, SSTATUS) & 0x0f00) >> 8;
printk("fb%u: %s frame buffer; %uMB vram; chip version %u\n",
info->node, info->fix.id, info->fix.smem_len >> 20, tmp);
}
static int __devinit
imsttfb_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
unsigned long addr, size;
struct imstt_par *par;
struct fb_info *info;
#ifdef CONFIG_PPC_OF
struct device_node *dp;
dp = pci_device_to_OF_node(pdev);
if(dp)
printk(KERN_INFO "%s: OF name %s\n",__func__, dp->name);
else
printk(KERN_ERR "imsttfb: no OF node for pci device\n");
#endif
info = framebuffer_alloc(sizeof(struct imstt_par), &pdev->dev);
if (!info) {
printk(KERN_ERR "imsttfb: Can't allocate memory\n");
return -ENOMEM;
}
par = info->par;
addr = pci_resource_start (pdev, 0);
size = pci_resource_len (pdev, 0);
if (!request_mem_region(addr, size, "imsttfb")) {
printk(KERN_ERR "imsttfb: Can't reserve memory region\n");
framebuffer_release(info);
return -ENODEV;
}
switch (pdev->device) {
case PCI_DEVICE_ID_IMS_TT128:
par->ramdac = IBM;
#ifdef CONFIG_PPC_OF
if (dp && ((strcmp(dp->name, "IMS,tt128mb8") == 0) ||
(strcmp(dp->name, "IMS,tt128mb8A") == 0)))
par->ramdac = TVP;
#endif
break;
case PCI_DEVICE_ID_IMS_TT3D:
par->ramdac = TVP;
break;
default:
printk(KERN_INFO "imsttfb: Device 0x%x unknown, "
"contact maintainer.\n", pdev->device);
release_mem_region(addr, size);
framebuffer_release(info);
return -ENODEV;
}
info->fix.smem_start = addr;
info->screen_base = (__u8 *)ioremap(addr, par->ramdac == IBM ?
0x400000 : 0x800000);
info->fix.mmio_start = addr + 0x800000;
par->dc_regs = ioremap(addr + 0x800000, 0x1000);
par->cmap_regs_phys = addr + 0x840000;
par->cmap_regs = (__u8 *)ioremap(addr + 0x840000, 0x1000);
info->pseudo_palette = par->palette;
init_imstt(info);
pci_set_drvdata(pdev, info);
return 0;
}
static void __devexit
imsttfb_remove(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct imstt_par *par = info->par;
int size = pci_resource_len(pdev, 0);
unregister_framebuffer(info);
iounmap(par->cmap_regs);
iounmap(par->dc_regs);
iounmap(info->screen_base);
release_mem_region(info->fix.smem_start, size);
framebuffer_release(info);
}
static int __init
imsttfb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "font:", 5)) {
char *p;
int i;
p = this_opt + 5;
for (i = 0; i < sizeof(fontname) - 1; i++)
if (!*p || *p == ' ' || *p == ',')
break;
memcpy(fontname, this_opt + 5, i);
fontname[i] = 0;
} else if (!strncmp(this_opt, "inverse", 7)) {
inverse = 1;
fb_invert_cmaps();
}
#if defined(CONFIG_PPC)
else if (!strncmp(this_opt, "vmode:", 6)) {
int vmode = simple_strtoul(this_opt+6, NULL, 0);
if (vmode > 0 && vmode <= VMODE_MAX)
init_vmode = vmode;
} else if (!strncmp(this_opt, "cmode:", 6)) {
int cmode = simple_strtoul(this_opt+6, NULL, 0);
switch (cmode) {
case CMODE_8:
case 8:
init_cmode = CMODE_8;
break;
case CMODE_16:
case 15:
case 16:
init_cmode = CMODE_16;
break;
case CMODE_32:
case 24:
case 32:
init_cmode = CMODE_32;
break;
}
}
#endif
}
return 0;
}
static int __init imsttfb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("imsttfb", &option))
return -ENODEV;
imsttfb_setup(option);
#endif
return pci_register_driver(&imsttfb_pci_driver);
}
static void __exit imsttfb_exit(void)
{
pci_unregister_driver(&imsttfb_pci_driver);
}
