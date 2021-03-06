static inline void
cyber2000_crtcw(unsigned int reg, unsigned int val, struct cfb_info *cfb)
{
cyber2000fb_writew((reg & 255) | val << 8, 0x3d4, cfb);
}
static inline void
cyber2000_grphw(unsigned int reg, unsigned int val, struct cfb_info *cfb)
{
cyber2000fb_writew((reg & 255) | val << 8, 0x3ce, cfb);
}
static inline unsigned int
cyber2000_grphr(unsigned int reg, struct cfb_info *cfb)
{
cyber2000fb_writeb(reg, 0x3ce, cfb);
return cyber2000fb_readb(0x3cf, cfb);
}
static inline void
cyber2000_attrw(unsigned int reg, unsigned int val, struct cfb_info *cfb)
{
cyber2000fb_readb(0x3da, cfb);
cyber2000fb_writeb(reg, 0x3c0, cfb);
cyber2000fb_readb(0x3c1, cfb);
cyber2000fb_writeb(val, 0x3c0, cfb);
}
static inline void
cyber2000_seqw(unsigned int reg, unsigned int val, struct cfb_info *cfb)
{
cyber2000fb_writew((reg & 255) | val << 8, 0x3c4, cfb);
}
static void
cyber2000fb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
unsigned long dst, col;
if (!(cfb->fb.var.accel_flags & FB_ACCELF_TEXT)) {
cfb_fillrect(info, rect);
return;
}
cyber2000fb_writeb(0, CO_REG_CONTROL, cfb);
cyber2000fb_writew(rect->width - 1, CO_REG_PIXWIDTH, cfb);
cyber2000fb_writew(rect->height - 1, CO_REG_PIXHEIGHT, cfb);
col = rect->color;
if (cfb->fb.var.bits_per_pixel > 8)
col = ((u32 *)cfb->fb.pseudo_palette)[col];
cyber2000fb_writel(col, CO_REG_FGCOLOUR, cfb);
dst = rect->dx + rect->dy * cfb->fb.var.xres_virtual;
if (cfb->fb.var.bits_per_pixel == 24) {
cyber2000fb_writeb(dst, CO_REG_X_PHASE, cfb);
dst *= 3;
}
cyber2000fb_writel(dst, CO_REG_DEST_PTR, cfb);
cyber2000fb_writeb(CO_FG_MIX_SRC, CO_REG_FGMIX, cfb);
cyber2000fb_writew(CO_CMD_L_PATTERN_FGCOL, CO_REG_CMD_L, cfb);
cyber2000fb_writew(CO_CMD_H_BLITTER, CO_REG_CMD_H, cfb);
}
static void
cyber2000fb_copyarea(struct fb_info *info, const struct fb_copyarea *region)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
unsigned int cmd = CO_CMD_L_PATTERN_FGCOL;
unsigned long src, dst;
if (!(cfb->fb.var.accel_flags & FB_ACCELF_TEXT)) {
cfb_copyarea(info, region);
return;
}
cyber2000fb_writeb(0, CO_REG_CONTROL, cfb);
cyber2000fb_writew(region->width - 1, CO_REG_PIXWIDTH, cfb);
cyber2000fb_writew(region->height - 1, CO_REG_PIXHEIGHT, cfb);
src = region->sx + region->sy * cfb->fb.var.xres_virtual;
dst = region->dx + region->dy * cfb->fb.var.xres_virtual;
if (region->sx < region->dx) {
src += region->width - 1;
dst += region->width - 1;
cmd |= CO_CMD_L_INC_LEFT;
}
if (region->sy < region->dy) {
src += (region->height - 1) * cfb->fb.var.xres_virtual;
dst += (region->height - 1) * cfb->fb.var.xres_virtual;
cmd |= CO_CMD_L_INC_UP;
}
if (cfb->fb.var.bits_per_pixel == 24) {
cyber2000fb_writeb(dst, CO_REG_X_PHASE, cfb);
src *= 3;
dst *= 3;
}
cyber2000fb_writel(src, CO_REG_SRC1_PTR, cfb);
cyber2000fb_writel(dst, CO_REG_DEST_PTR, cfb);
cyber2000fb_writew(CO_FG_MIX_SRC, CO_REG_FGMIX, cfb);
cyber2000fb_writew(cmd, CO_REG_CMD_L, cfb);
cyber2000fb_writew(CO_CMD_H_FGSRCMAP | CO_CMD_H_BLITTER,
CO_REG_CMD_H, cfb);
}
static void
cyber2000fb_imageblit(struct fb_info *info, const struct fb_image *image)
{
cfb_imageblit(info, image);
return;
}
static int cyber2000fb_sync(struct fb_info *info)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
int count = 100000;
if (!(cfb->fb.var.accel_flags & FB_ACCELF_TEXT))
return 0;
while (cyber2000fb_readb(CO_REG_CONTROL, cfb) & CO_CTRL_BUSY) {
if (!count--) {
debug_printf("accel_wait timed out\n");
cyber2000fb_writeb(0, CO_REG_CONTROL, cfb);
break;
}
udelay(1);
}
return 0;
}
static inline u32 convert_bitfield(u_int val, struct fb_bitfield *bf)
{
u_int mask = (1 << bf->length) - 1;
return (val >> (16 - bf->length) & mask) << bf->offset;
}
static int
cyber2000fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
struct fb_var_screeninfo *var = &cfb->fb.var;
u32 pseudo_val;
int ret = 1;
switch (cfb->fb.fix.visual) {
default:
return 1;
case FB_VISUAL_PSEUDOCOLOR:
if (regno >= NR_PALETTE)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
cfb->palette[regno].red = red;
cfb->palette[regno].green = green;
cfb->palette[regno].blue = blue;
cyber2000fb_writeb(regno, 0x3c8, cfb);
cyber2000fb_writeb(red, 0x3c9, cfb);
cyber2000fb_writeb(green, 0x3c9, cfb);
cyber2000fb_writeb(blue, 0x3c9, cfb);
return 0;
case FB_VISUAL_DIRECTCOLOR:
red >>= 8;
green >>= 8;
blue >>= 8;
if (var->green.length == 6 && regno < 64) {
cfb->palette[regno << 2].green = green;
cyber2000fb_writeb(regno << 2, 0x3c8, cfb);
cyber2000fb_writeb(cfb->palette[regno >> 1].red,
0x3c9, cfb);
cyber2000fb_writeb(green, 0x3c9, cfb);
cyber2000fb_writeb(cfb->palette[regno >> 1].blue,
0x3c9, cfb);
green = cfb->palette[regno << 3].green;
ret = 0;
}
if (var->green.length >= 5 && regno < 32) {
cfb->palette[regno << 3].red = red;
cfb->palette[regno << 3].green = green;
cfb->palette[regno << 3].blue = blue;
cyber2000fb_writeb(regno << 3, 0x3c8, cfb);
cyber2000fb_writeb(red, 0x3c9, cfb);
cyber2000fb_writeb(green, 0x3c9, cfb);
cyber2000fb_writeb(blue, 0x3c9, cfb);
ret = 0;
}
if (var->green.length == 4 && regno < 16) {
cfb->palette[regno << 4].red = red;
cfb->palette[regno << 4].green = green;
cfb->palette[regno << 4].blue = blue;
cyber2000fb_writeb(regno << 4, 0x3c8, cfb);
cyber2000fb_writeb(red, 0x3c9, cfb);
cyber2000fb_writeb(green, 0x3c9, cfb);
cyber2000fb_writeb(blue, 0x3c9, cfb);
ret = 0;
}
pseudo_val = regno << var->red.offset |
regno << var->green.offset |
regno << var->blue.offset;
break;
case FB_VISUAL_TRUECOLOR:
pseudo_val = convert_bitfield(transp ^ 0xffff, &var->transp);
pseudo_val |= convert_bitfield(red, &var->red);
pseudo_val |= convert_bitfield(green, &var->green);
pseudo_val |= convert_bitfield(blue, &var->blue);
ret = 0;
break;
}
if (regno < 16)
((u32 *)cfb->fb.pseudo_palette)[regno] = pseudo_val;
return ret;
}
static void cyber2000fb_write_ramdac_ctrl(struct cfb_info *cfb)
{
unsigned int i;
unsigned int val = cfb->ramdac_ctrl | cfb->ramdac_powerdown;
cyber2000fb_writeb(0x56, 0x3ce, cfb);
i = cyber2000fb_readb(0x3cf, cfb);
cyber2000fb_writeb(i | 4, 0x3cf, cfb);
cyber2000fb_writeb(val, 0x3c6, cfb);
cyber2000fb_writeb(i, 0x3cf, cfb);
cyber2000fb_readb(0x3cf, cfb);
}
static void cyber2000fb_set_timing(struct cfb_info *cfb, struct par_info *hw)
{
u_int i;
for (i = 0; i < NR_PALETTE; i++) {
cyber2000fb_writeb(i, 0x3c8, cfb);
cyber2000fb_writeb(0, 0x3c9, cfb);
cyber2000fb_writeb(0, 0x3c9, cfb);
cyber2000fb_writeb(0, 0x3c9, cfb);
}
cyber2000fb_writeb(0xef, 0x3c2, cfb);
cyber2000_crtcw(0x11, 0x0b, cfb);
cyber2000_attrw(0x11, 0x00, cfb);
cyber2000_seqw(0x00, 0x01, cfb);
cyber2000_seqw(0x01, 0x01, cfb);
cyber2000_seqw(0x02, 0x0f, cfb);
cyber2000_seqw(0x03, 0x00, cfb);
cyber2000_seqw(0x04, 0x0e, cfb);
cyber2000_seqw(0x00, 0x03, cfb);
for (i = 0; i < sizeof(crtc_idx); i++)
cyber2000_crtcw(crtc_idx[i], hw->crtc[i], cfb);
for (i = 0x0a; i < 0x10; i++)
cyber2000_crtcw(i, 0, cfb);
cyber2000_grphw(EXT_CRT_VRTOFL, hw->crtc_ofl, cfb);
cyber2000_grphw(0x00, 0x00, cfb);
cyber2000_grphw(0x01, 0x00, cfb);
cyber2000_grphw(0x02, 0x00, cfb);
cyber2000_grphw(0x03, 0x00, cfb);
cyber2000_grphw(0x04, 0x00, cfb);
cyber2000_grphw(0x05, 0x60, cfb);
cyber2000_grphw(0x06, 0x05, cfb);
cyber2000_grphw(0x07, 0x0f, cfb);
cyber2000_grphw(0x08, 0xff, cfb);
for (i = 0; i < 16; i++)
cyber2000_attrw(i, i, cfb);
cyber2000_attrw(0x10, 0x01, cfb);
cyber2000_attrw(0x11, 0x00, cfb);
cyber2000_attrw(0x12, 0x0f, cfb);
cyber2000_attrw(0x13, 0x00, cfb);
cyber2000_attrw(0x14, 0x00, cfb);
spin_lock(&cfb->reg_b0_lock);
cyber2000_grphw(EXT_DCLK_MULT, hw->clock_mult, cfb);
cyber2000_grphw(EXT_DCLK_DIV, hw->clock_div, cfb);
cyber2000_grphw(EXT_MCLK_MULT, cfb->mclk_mult, cfb);
cyber2000_grphw(EXT_MCLK_DIV, cfb->mclk_div, cfb);
cyber2000_grphw(0x90, 0x01, cfb);
cyber2000_grphw(0xb9, 0x80, cfb);
cyber2000_grphw(0xb9, 0x00, cfb);
spin_unlock(&cfb->reg_b0_lock);
cfb->ramdac_ctrl = hw->ramdac;
cyber2000fb_write_ramdac_ctrl(cfb);
cyber2000fb_writeb(0x20, 0x3c0, cfb);
cyber2000fb_writeb(0xff, 0x3c6, cfb);
cyber2000_grphw(0x14, hw->fetch, cfb);
cyber2000_grphw(0x15, ((hw->fetch >> 8) & 0x03) |
((hw->pitch >> 4) & 0x30), cfb);
cyber2000_grphw(EXT_SEQ_MISC, hw->extseqmisc, cfb);
cyber2000fb_writew(hw->width, CO_REG_SRC_WIDTH, cfb);
cyber2000fb_writew(hw->width, CO_REG_DEST_WIDTH, cfb);
cyber2000fb_writeb(hw->co_pixfmt, CO_REG_PIXFMT, cfb);
}
static inline int
cyber2000fb_update_start(struct cfb_info *cfb, struct fb_var_screeninfo *var)
{
u_int base = var->yoffset * var->xres_virtual + var->xoffset;
base *= var->bits_per_pixel;
base >>= 5;
if (base >= 1 << 20)
return -EINVAL;
cyber2000_grphw(0x10, base >> 16 | 0x10, cfb);
cyber2000_crtcw(0x0c, base >> 8, cfb);
cyber2000_crtcw(0x0d, base, cfb);
return 0;
}
static int
cyber2000fb_decode_crtc(struct par_info *hw, struct cfb_info *cfb,
struct fb_var_screeninfo *var)
{
u_int Htotal, Hblankend, Hsyncend;
u_int Vtotal, Vdispend, Vblankstart, Vblankend, Vsyncstart, Vsyncend;
#define ENCODE_BIT(v, b1, m, b2) ((((v) >> (b1)) & (m)) << (b2))
hw->crtc[13] = hw->pitch;
hw->crtc[17] = 0xe3;
hw->crtc[14] = 0;
hw->crtc[8] = 0;
Htotal = var->xres + var->right_margin +
var->hsync_len + var->left_margin;
if (Htotal > 2080)
return -EINVAL;
hw->crtc[0] = (Htotal >> 3) - 5;
hw->crtc[1] = (var->xres >> 3) - 1;
hw->crtc[2] = var->xres >> 3;
hw->crtc[4] = (var->xres + var->right_margin) >> 3;
Hblankend = (Htotal - 4 * 8) >> 3;
hw->crtc[3] = ENCODE_BIT(Hblankend, 0, 0x1f, 0) |
ENCODE_BIT(1, 0, 0x01, 7);
Hsyncend = (var->xres + var->right_margin + var->hsync_len) >> 3;
hw->crtc[5] = ENCODE_BIT(Hsyncend, 0, 0x1f, 0) |
ENCODE_BIT(Hblankend, 5, 0x01, 7);
Vdispend = var->yres - 1;
Vsyncstart = var->yres + var->lower_margin;
Vsyncend = var->yres + var->lower_margin + var->vsync_len;
Vtotal = var->yres + var->lower_margin + var->vsync_len +
var->upper_margin - 2;
if (Vtotal > 2047)
return -EINVAL;
Vblankstart = var->yres + 6;
Vblankend = Vtotal - 10;
hw->crtc[6] = Vtotal;
hw->crtc[7] = ENCODE_BIT(Vtotal, 8, 0x01, 0) |
ENCODE_BIT(Vdispend, 8, 0x01, 1) |
ENCODE_BIT(Vsyncstart, 8, 0x01, 2) |
ENCODE_BIT(Vblankstart, 8, 0x01, 3) |
ENCODE_BIT(1, 0, 0x01, 4) |
ENCODE_BIT(Vtotal, 9, 0x01, 5) |
ENCODE_BIT(Vdispend, 9, 0x01, 6) |
ENCODE_BIT(Vsyncstart, 9, 0x01, 7);
hw->crtc[9] = ENCODE_BIT(0, 0, 0x1f, 0) |
ENCODE_BIT(Vblankstart, 9, 0x01, 5) |
ENCODE_BIT(1, 0, 0x01, 6);
hw->crtc[10] = Vsyncstart;
hw->crtc[11] = ENCODE_BIT(Vsyncend, 0, 0x0f, 0) |
ENCODE_BIT(1, 0, 0x01, 7);
hw->crtc[12] = Vdispend;
hw->crtc[15] = Vblankstart;
hw->crtc[16] = Vblankend;
hw->crtc[18] = 0xff;
hw->crtc_ofl =
ENCODE_BIT(Vtotal, 10, 0x01, 0) |
ENCODE_BIT(Vdispend, 10, 0x01, 1) |
ENCODE_BIT(Vsyncstart, 10, 0x01, 2) |
ENCODE_BIT(Vblankstart, 10, 0x01, 3) |
EXT_CRT_VRTOFL_LINECOMP10;
if ((var->vmode & FB_VMODE_MASK) == FB_VMODE_INTERLACED)
hw->crtc_ofl |= EXT_CRT_VRTOFL_INTERLACE;
return 0;
}
static int
cyber2000fb_decode_clock(struct par_info *hw, struct cfb_info *cfb,
struct fb_var_screeninfo *var)
{
u_long pll_ps = var->pixclock;
const u_long ref_ps = cfb->ref_ps;
u_int div2, t_div1, best_div1, best_mult;
int best_diff;
int vco;
for (div2 = 0; div2 < 4; div2++) {
u_long new_pll;
new_pll = pll_ps / cfb->divisors[div2];
if (8696 > new_pll && new_pll > 3846) {
pll_ps = new_pll;
break;
}
}
if (div2 == 4)
return -EINVAL;
best_diff = 0x7fffffff;
best_mult = 2;
best_div1 = 32;
for (t_div1 = 2; t_div1 < 32; t_div1 += 1) {
u_int rr, t_mult, t_pll_ps;
int diff;
rr = ref_ps * t_div1;
t_mult = (rr + pll_ps / 2) / pll_ps;
if (t_mult > 256 || t_mult < 2)
continue;
t_pll_ps = (rr + t_mult / 2) / t_mult;
diff = pll_ps - t_pll_ps;
if (diff < 0)
diff = -diff;
if (diff < best_diff) {
best_diff = diff;
best_mult = t_mult;
best_div1 = t_div1;
}
if (diff == 0)
break;
}
hw->clock_mult = best_mult - 1;
hw->clock_div = div2 << 6 | (best_div1 - 1);
vco = ref_ps * best_div1 / best_mult;
if ((ref_ps == 40690) && (vco < 5556))
hw->clock_div |= EXT_DCLK_DIV_VFSEL;
return 0;
}
static int
cyber2000fb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
struct par_info hw;
unsigned int mem;
int err;
var->transp.msb_right = 0;
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
var->transp.offset = 0;
var->transp.length = 0;
switch (var->bits_per_pixel) {
case 8:
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
break;
case 16:
switch (var->green.length) {
case 6:
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
break;
default:
case 5:
var->red.offset = 10;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 5;
var->blue.offset = 0;
var->blue.length = 5;
break;
case 4:
var->transp.offset = 12;
var->transp.length = 4;
var->red.offset = 8;
var->red.length = 4;
var->green.offset = 4;
var->green.length = 4;
var->blue.offset = 0;
var->blue.length = 4;
break;
}
break;
case 24:
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
break;
case 32:
var->transp.offset = 24;
var->transp.length = 8;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
break;
default:
return -EINVAL;
}
mem = var->xres_virtual * var->yres_virtual * (var->bits_per_pixel / 8);
if (mem > cfb->fb.fix.smem_len)
var->yres_virtual = cfb->fb.fix.smem_len * 8 /
(var->bits_per_pixel * var->xres_virtual);
if (var->yres > var->yres_virtual)
var->yres = var->yres_virtual;
if (var->xres > var->xres_virtual)
var->xres = var->xres_virtual;
err = cyber2000fb_decode_clock(&hw, cfb, var);
if (err)
return err;
err = cyber2000fb_decode_crtc(&hw, cfb, var);
if (err)
return err;
return 0;
}
static int cyber2000fb_set_par(struct fb_info *info)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
struct fb_var_screeninfo *var = &cfb->fb.var;
struct par_info hw;
unsigned int mem;
hw.width = var->xres_virtual;
hw.ramdac = RAMDAC_VREFEN | RAMDAC_DAC8BIT;
switch (var->bits_per_pixel) {
case 8:
hw.co_pixfmt = CO_PIXFMT_8BPP;
hw.pitch = hw.width >> 3;
hw.extseqmisc = EXT_SEQ_MISC_8;
break;
case 16:
hw.co_pixfmt = CO_PIXFMT_16BPP;
hw.pitch = hw.width >> 2;
switch (var->green.length) {
case 6:
hw.extseqmisc = EXT_SEQ_MISC_16_RGB565;
break;
case 5:
hw.extseqmisc = EXT_SEQ_MISC_16_RGB555;
break;
case 4:
hw.extseqmisc = EXT_SEQ_MISC_16_RGB444;
break;
default:
BUG();
}
break;
case 24:
hw.co_pixfmt = CO_PIXFMT_24BPP;
hw.width *= 3;
hw.pitch = hw.width >> 3;
hw.ramdac |= (RAMDAC_BYPASS | RAMDAC_RAMPWRDN);
hw.extseqmisc = EXT_SEQ_MISC_24_RGB888;
break;
case 32:
hw.co_pixfmt = CO_PIXFMT_32BPP;
hw.pitch = hw.width >> 1;
hw.ramdac |= (RAMDAC_BYPASS | RAMDAC_RAMPWRDN);
hw.extseqmisc = EXT_SEQ_MISC_32;
break;
default:
BUG();
}
BUG_ON(cyber2000fb_decode_clock(&hw, cfb, var) != 0);
BUG_ON(cyber2000fb_decode_crtc(&hw, cfb, var) != 0);
hw.width -= 1;
hw.fetch = hw.pitch;
if (!(cfb->mem_ctl2 & MEM_CTL2_64BIT))
hw.fetch <<= 1;
hw.fetch += 1;
cfb->fb.fix.line_length = var->xres_virtual * var->bits_per_pixel / 8;
mem = cfb->fb.fix.line_length * var->yres_virtual;
BUG_ON(mem > cfb->fb.fix.smem_len);
if (var->bits_per_pixel == 8)
cfb->fb.fix.visual = FB_VISUAL_PSEUDOCOLOR;
else if (hw.ramdac & RAMDAC_BYPASS)
cfb->fb.fix.visual = FB_VISUAL_TRUECOLOR;
else
cfb->fb.fix.visual = FB_VISUAL_DIRECTCOLOR;
cyber2000fb_set_timing(cfb, &hw);
cyber2000fb_update_start(cfb, var);
return 0;
}
static int
cyber2000fb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
if (cyber2000fb_update_start(cfb, var))
return -EINVAL;
cfb->fb.var.xoffset = var->xoffset;
cfb->fb.var.yoffset = var->yoffset;
if (var->vmode & FB_VMODE_YWRAP) {
cfb->fb.var.vmode |= FB_VMODE_YWRAP;
} else {
cfb->fb.var.vmode &= ~FB_VMODE_YWRAP;
}
return 0;
}
static int cyber2000fb_blank(int blank, struct fb_info *info)
{
struct cfb_info *cfb = container_of(info, struct cfb_info, fb);
unsigned int sync = 0;
int i;
switch (blank) {
case FB_BLANK_POWERDOWN:
sync = EXT_SYNC_CTL_VS_0 | EXT_SYNC_CTL_HS_0;
break;
case FB_BLANK_HSYNC_SUSPEND:
sync = EXT_SYNC_CTL_VS_NORMAL | EXT_SYNC_CTL_HS_0;
break;
case FB_BLANK_VSYNC_SUSPEND:
sync = EXT_SYNC_CTL_VS_0 | EXT_SYNC_CTL_HS_NORMAL;
break;
case FB_BLANK_NORMAL:
default:
break;
}
cyber2000_grphw(EXT_SYNC_CTL, sync, cfb);
if (blank <= 1) {
cfb->ramdac_powerdown &= ~(RAMDAC_DACPWRDN | RAMDAC_BYPASS |
RAMDAC_RAMPWRDN);
cyber2000fb_write_ramdac_ctrl(cfb);
}
if (blank) {
for (i = 0; i < NR_PALETTE; i++) {
cyber2000fb_writeb(i, 0x3c8, cfb);
cyber2000fb_writeb(0, 0x3c9, cfb);
cyber2000fb_writeb(0, 0x3c9, cfb);
cyber2000fb_writeb(0, 0x3c9, cfb);
}
} else {
for (i = 0; i < NR_PALETTE; i++) {
cyber2000fb_writeb(i, 0x3c8, cfb);
cyber2000fb_writeb(cfb->palette[i].red, 0x3c9, cfb);
cyber2000fb_writeb(cfb->palette[i].green, 0x3c9, cfb);
cyber2000fb_writeb(cfb->palette[i].blue, 0x3c9, cfb);
}
}
if (blank >= 2) {
cfb->ramdac_powerdown |= RAMDAC_DACPWRDN | RAMDAC_BYPASS |
RAMDAC_RAMPWRDN;
cyber2000fb_write_ramdac_ctrl(cfb);
}
return 0;
}
void cyber2000fb_enable_extregs(struct cfb_info *cfb)
{
cfb->func_use_count += 1;
if (cfb->func_use_count == 1) {
int old;
old = cyber2000_grphr(EXT_FUNC_CTL, cfb);
old |= EXT_FUNC_CTL_EXTREGENBL;
cyber2000_grphw(EXT_FUNC_CTL, old, cfb);
}
}
void cyber2000fb_disable_extregs(struct cfb_info *cfb)
{
if (cfb->func_use_count == 1) {
int old;
old = cyber2000_grphr(EXT_FUNC_CTL, cfb);
old &= ~EXT_FUNC_CTL_EXTREGENBL;
cyber2000_grphw(EXT_FUNC_CTL, old, cfb);
}
if (cfb->func_use_count == 0)
printk(KERN_ERR "disable_extregs: count = 0\n");
else
cfb->func_use_count -= 1;
}
int cyber2000fb_attach(struct cyberpro_info *info, int idx)
{
if (int_cfb_info != NULL) {
info->dev = int_cfb_info->fb.device;
#ifdef CONFIG_FB_CYBER2000_I2C
info->i2c = &int_cfb_info->i2c_adapter;
#else
info->i2c = NULL;
#endif
info->regs = int_cfb_info->regs;
info->irq = int_cfb_info->irq;
info->fb = int_cfb_info->fb.screen_base;
info->fb_size = int_cfb_info->fb.fix.smem_len;
info->info = int_cfb_info;
strlcpy(info->dev_name, int_cfb_info->fb.fix.id,
sizeof(info->dev_name));
}
return int_cfb_info != NULL;
}
void cyber2000fb_detach(int idx)
{
}
static void cyber2000fb_enable_ddc(struct cfb_info *cfb)
{
spin_lock(&cfb->reg_b0_lock);
cyber2000fb_writew(0x1bf, 0x3ce, cfb);
}
static void cyber2000fb_disable_ddc(struct cfb_info *cfb)
{
cyber2000fb_writew(0x0bf, 0x3ce, cfb);
spin_unlock(&cfb->reg_b0_lock);
}
static void cyber2000fb_ddc_setscl(void *data, int val)
{
struct cfb_info *cfb = data;
unsigned char reg;
cyber2000fb_enable_ddc(cfb);
reg = cyber2000_grphr(DDC_REG, cfb);
if (!val)
reg |= DDC_SCL_OUT;
else
reg &= ~DDC_SCL_OUT;
cyber2000_grphw(DDC_REG, reg, cfb);
cyber2000fb_disable_ddc(cfb);
}
static void cyber2000fb_ddc_setsda(void *data, int val)
{
struct cfb_info *cfb = data;
unsigned char reg;
cyber2000fb_enable_ddc(cfb);
reg = cyber2000_grphr(DDC_REG, cfb);
if (!val)
reg |= DDC_SDA_OUT;
else
reg &= ~DDC_SDA_OUT;
cyber2000_grphw(DDC_REG, reg, cfb);
cyber2000fb_disable_ddc(cfb);
}
static int cyber2000fb_ddc_getscl(void *data)
{
struct cfb_info *cfb = data;
int retval;
cyber2000fb_enable_ddc(cfb);
retval = !!(cyber2000_grphr(DDC_REG, cfb) & DDC_SCL_IN);
cyber2000fb_disable_ddc(cfb);
return retval;
}
static int cyber2000fb_ddc_getsda(void *data)
{
struct cfb_info *cfb = data;
int retval;
cyber2000fb_enable_ddc(cfb);
retval = !!(cyber2000_grphr(DDC_REG, cfb) & DDC_SDA_IN);
cyber2000fb_disable_ddc(cfb);
return retval;
}
static int cyber2000fb_setup_ddc_bus(struct cfb_info *cfb)
{
strlcpy(cfb->ddc_adapter.name, cfb->fb.fix.id,
sizeof(cfb->ddc_adapter.name));
cfb->ddc_adapter.owner = THIS_MODULE;
cfb->ddc_adapter.class = I2C_CLASS_DDC;
cfb->ddc_adapter.algo_data = &cfb->ddc_algo;
cfb->ddc_adapter.dev.parent = cfb->fb.device;
cfb->ddc_algo.setsda = cyber2000fb_ddc_setsda;
cfb->ddc_algo.setscl = cyber2000fb_ddc_setscl;
cfb->ddc_algo.getsda = cyber2000fb_ddc_getsda;
cfb->ddc_algo.getscl = cyber2000fb_ddc_getscl;
cfb->ddc_algo.udelay = 10;
cfb->ddc_algo.timeout = 20;
cfb->ddc_algo.data = cfb;
i2c_set_adapdata(&cfb->ddc_adapter, cfb);
return i2c_bit_add_bus(&cfb->ddc_adapter);
}
static void cyber2000fb_i2c_setsda(void *data, int state)
{
struct cfb_info *cfb = data;
unsigned int latch2;
spin_lock(&cfb->reg_b0_lock);
latch2 = cyber2000_grphr(EXT_LATCH2, cfb);
latch2 &= EXT_LATCH2_I2C_CLKEN;
if (state)
latch2 |= EXT_LATCH2_I2C_DATEN;
cyber2000_grphw(EXT_LATCH2, latch2, cfb);
spin_unlock(&cfb->reg_b0_lock);
}
static void cyber2000fb_i2c_setscl(void *data, int state)
{
struct cfb_info *cfb = data;
unsigned int latch2;
spin_lock(&cfb->reg_b0_lock);
latch2 = cyber2000_grphr(EXT_LATCH2, cfb);
latch2 &= EXT_LATCH2_I2C_DATEN;
if (state)
latch2 |= EXT_LATCH2_I2C_CLKEN;
cyber2000_grphw(EXT_LATCH2, latch2, cfb);
spin_unlock(&cfb->reg_b0_lock);
}
static int cyber2000fb_i2c_getsda(void *data)
{
struct cfb_info *cfb = data;
int ret;
spin_lock(&cfb->reg_b0_lock);
ret = !!(cyber2000_grphr(EXT_LATCH2, cfb) & EXT_LATCH2_I2C_DAT);
spin_unlock(&cfb->reg_b0_lock);
return ret;
}
static int cyber2000fb_i2c_getscl(void *data)
{
struct cfb_info *cfb = data;
int ret;
spin_lock(&cfb->reg_b0_lock);
ret = !!(cyber2000_grphr(EXT_LATCH2, cfb) & EXT_LATCH2_I2C_CLK);
spin_unlock(&cfb->reg_b0_lock);
return ret;
}
static int cyber2000fb_i2c_register(struct cfb_info *cfb)
{
strlcpy(cfb->i2c_adapter.name, cfb->fb.fix.id,
sizeof(cfb->i2c_adapter.name));
cfb->i2c_adapter.owner = THIS_MODULE;
cfb->i2c_adapter.algo_data = &cfb->i2c_algo;
cfb->i2c_adapter.dev.parent = cfb->fb.device;
cfb->i2c_algo.setsda = cyber2000fb_i2c_setsda;
cfb->i2c_algo.setscl = cyber2000fb_i2c_setscl;
cfb->i2c_algo.getsda = cyber2000fb_i2c_getsda;
cfb->i2c_algo.getscl = cyber2000fb_i2c_getscl;
cfb->i2c_algo.udelay = 5;
cfb->i2c_algo.timeout = msecs_to_jiffies(100);
cfb->i2c_algo.data = cfb;
return i2c_bit_add_bus(&cfb->i2c_adapter);
}
static void cyber2000fb_i2c_unregister(struct cfb_info *cfb)
{
i2c_del_adapter(&cfb->i2c_adapter);
}
static void cyberpro_init_hw(struct cfb_info *cfb)
{
int i;
for (i = 0; i < sizeof(igs_regs); i += 2)
cyber2000_grphw(igs_regs[i], igs_regs[i + 1], cfb);
if (cfb->id == ID_CYBERPRO_5000) {
unsigned char val;
cyber2000fb_writeb(0xba, 0x3ce, cfb);
val = cyber2000fb_readb(0x3cf, cfb) & 0x80;
cyber2000fb_writeb(val, 0x3cf, cfb);
}
}
static struct cfb_info *cyberpro_alloc_fb_info(unsigned int id, char *name)
{
struct cfb_info *cfb;
cfb = kzalloc(sizeof(struct cfb_info), GFP_KERNEL);
if (!cfb)
return NULL;
cfb->id = id;
if (id == ID_CYBERPRO_5000)
cfb->ref_ps = 40690;
else
cfb->ref_ps = 69842;
cfb->divisors[0] = 1;
cfb->divisors[1] = 2;
cfb->divisors[2] = 4;
if (id == ID_CYBERPRO_2000)
cfb->divisors[3] = 8;
else
cfb->divisors[3] = 6;
strcpy(cfb->fb.fix.id, name);
cfb->fb.fix.type = FB_TYPE_PACKED_PIXELS;
cfb->fb.fix.type_aux = 0;
cfb->fb.fix.xpanstep = 0;
cfb->fb.fix.ypanstep = 1;
cfb->fb.fix.ywrapstep = 0;
switch (id) {
case ID_IGA_1682:
cfb->fb.fix.accel = 0;
break;
case ID_CYBERPRO_2000:
cfb->fb.fix.accel = FB_ACCEL_IGS_CYBER2000;
break;
case ID_CYBERPRO_2010:
cfb->fb.fix.accel = FB_ACCEL_IGS_CYBER2010;
break;
case ID_CYBERPRO_5000:
cfb->fb.fix.accel = FB_ACCEL_IGS_CYBER5000;
break;
}
cfb->fb.var.nonstd = 0;
cfb->fb.var.activate = FB_ACTIVATE_NOW;
cfb->fb.var.height = -1;
cfb->fb.var.width = -1;
cfb->fb.var.accel_flags = FB_ACCELF_TEXT;
cfb->fb.fbops = &cyber2000fb_ops;
cfb->fb.flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
cfb->fb.pseudo_palette = cfb->pseudo_palette;
spin_lock_init(&cfb->reg_b0_lock);
fb_alloc_cmap(&cfb->fb.cmap, NR_PALETTE, 0);
return cfb;
}
static void cyberpro_free_fb_info(struct cfb_info *cfb)
{
if (cfb) {
fb_alloc_cmap(&cfb->fb.cmap, 0, 0);
kfree(cfb);
}
}
static int cyber2000fb_setup(char *options)
{
char *opt;
if (!options || !*options)
return 0;
while ((opt = strsep(&options, ",")) != NULL) {
if (!*opt)
continue;
if (strncmp(opt, "font:", 5) == 0) {
static char default_font_storage[40];
strlcpy(default_font_storage, opt + 5,
sizeof(default_font_storage));
default_font = default_font_storage;
continue;
}
printk(KERN_ERR "CyberPro20x0: unknown parameter: %s\n", opt);
}
return 0;
}
static int cyberpro_common_probe(struct cfb_info *cfb)
{
u_long smem_size;
u_int h_sync, v_sync;
int err;
cyberpro_init_hw(cfb);
cfb->mem_ctl1 = cyber2000_grphr(EXT_MEM_CTL1, cfb);
cfb->mem_ctl2 = cyber2000_grphr(EXT_MEM_CTL2, cfb);
switch (cfb->mem_ctl2 & MEM_CTL2_SIZE_MASK) {
case MEM_CTL2_SIZE_4MB:
smem_size = 0x00400000;
break;
case MEM_CTL2_SIZE_2MB:
smem_size = 0x00200000;
break;
case MEM_CTL2_SIZE_1MB:
smem_size = 0x00100000;
break;
default:
smem_size = 0x00100000;
break;
}
cfb->fb.fix.smem_len = smem_size;
cfb->fb.fix.mmio_len = MMIO_SIZE;
cfb->fb.screen_base = cfb->region;
#ifdef CONFIG_FB_CYBER2000_DDC
if (cyber2000fb_setup_ddc_bus(cfb) == 0)
cfb->ddc_registered = true;
#endif
err = -EINVAL;
if (!fb_find_mode(&cfb->fb.var, &cfb->fb, NULL, NULL, 0,
&cyber2000fb_default_mode, 8)) {
printk(KERN_ERR "%s: no valid mode found\n", cfb->fb.fix.id);
goto failed;
}
cfb->fb.var.yres_virtual = cfb->fb.fix.smem_len * 8 /
(cfb->fb.var.bits_per_pixel * cfb->fb.var.xres_virtual);
if (cfb->fb.var.yres_virtual < cfb->fb.var.yres)
cfb->fb.var.yres_virtual = cfb->fb.var.yres;
h_sync = 1953125000 / cfb->fb.var.pixclock;
h_sync = h_sync * 512 / (cfb->fb.var.xres + cfb->fb.var.left_margin +
cfb->fb.var.right_margin + cfb->fb.var.hsync_len);
v_sync = h_sync / (cfb->fb.var.yres + cfb->fb.var.upper_margin +
cfb->fb.var.lower_margin + cfb->fb.var.vsync_len);
printk(KERN_INFO "%s: %dKiB VRAM, using %dx%d, %d.%03dkHz, %dHz\n",
cfb->fb.fix.id, cfb->fb.fix.smem_len >> 10,
cfb->fb.var.xres, cfb->fb.var.yres,
h_sync / 1000, h_sync % 1000, v_sync);
err = cyber2000fb_i2c_register(cfb);
if (err)
goto failed;
err = register_framebuffer(&cfb->fb);
if (err)
cyber2000fb_i2c_unregister(cfb);
failed:
#ifdef CONFIG_FB_CYBER2000_DDC
if (err && cfb->ddc_registered)
i2c_del_adapter(&cfb->ddc_adapter);
#endif
return err;
}
static void cyberpro_common_remove(struct cfb_info *cfb)
{
unregister_framebuffer(&cfb->fb);
#ifdef CONFIG_FB_CYBER2000_DDC
if (cfb->ddc_registered)
i2c_del_adapter(&cfb->ddc_adapter);
#endif
cyber2000fb_i2c_unregister(cfb);
}
static void cyberpro_common_resume(struct cfb_info *cfb)
{
cyberpro_init_hw(cfb);
cyber2000_grphw(EXT_MEM_CTL1, cfb->mem_ctl1, cfb);
cyber2000_grphw(EXT_MEM_CTL2, cfb->mem_ctl2, cfb);
cyber2000fb_set_par(&cfb->fb);
}
static int cyberpro_pci_enable_mmio(struct cfb_info *cfb)
{
unsigned char val;
#if defined(__sparc_v9__)
#error "You lose, consult DaveM."
#elif defined(__sparc__)
unsigned char __iomem *iop;
iop = ioremap(0x3000000, 0x5000);
if (iop == NULL) {
printk(KERN_ERR "iga5000: cannot map I/O\n");
return -ENOMEM;
}
writeb(0x18, iop + 0x46e8);
writeb(0x01, iop + 0x102);
writeb(0x08, iop + 0x46e8);
writeb(EXT_BIU_MISC, iop + 0x3ce);
writeb(EXT_BIU_MISC_LIN_ENABLE, iop + 0x3cf);
iounmap(iop);
#else
outb(0x18, 0x46e8);
outb(0x01, 0x102);
outb(0x08, 0x46e8);
outb(EXT_BIU_MISC, 0x3ce);
outb(EXT_BIU_MISC_LIN_ENABLE, 0x3cf);
#endif
if (cfb->id == ID_CYBERPRO_2010) {
printk(KERN_INFO "%s: NOT enabling PCI bursts\n",
cfb->fb.fix.id);
} else {
val = cyber2000_grphr(EXT_BUS_CTL, cfb);
if (!(val & EXT_BUS_CTL_PCIBURST_WRITE)) {
printk(KERN_INFO "%s: enabling PCI bursts\n",
cfb->fb.fix.id);
val |= EXT_BUS_CTL_PCIBURST_WRITE;
if (cfb->id == ID_CYBERPRO_5000)
val |= EXT_BUS_CTL_PCIBURST_READ;
cyber2000_grphw(EXT_BUS_CTL, val, cfb);
}
}
return 0;
}
static int cyberpro_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct cfb_info *cfb;
char name[16];
int err;
sprintf(name, "CyberPro%4X", id->device);
err = pci_enable_device(dev);
if (err)
return err;
err = -ENOMEM;
cfb = cyberpro_alloc_fb_info(id->driver_data, name);
if (!cfb)
goto failed_release;
err = pci_request_regions(dev, cfb->fb.fix.id);
if (err)
goto failed_regions;
cfb->irq = dev->irq;
cfb->region = pci_ioremap_bar(dev, 0);
if (!cfb->region) {
err = -ENOMEM;
goto failed_ioremap;
}
cfb->regs = cfb->region + MMIO_OFFSET;
cfb->fb.device = &dev->dev;
cfb->fb.fix.mmio_start = pci_resource_start(dev, 0) + MMIO_OFFSET;
cfb->fb.fix.smem_start = pci_resource_start(dev, 0);
err = cyberpro_pci_enable_mmio(cfb);
if (err)
goto failed;
cfb->mclk_mult = cyber2000_grphr(EXT_MCLK_MULT, cfb);
cfb->mclk_div = cyber2000_grphr(EXT_MCLK_DIV, cfb);
#ifdef __arm__
if (machine_is_netwinder()) {
cfb->mclk_mult = 0xdb;
cfb->mclk_div = 0x54;
}
#endif
err = cyberpro_common_probe(cfb);
if (err)
goto failed;
pci_set_drvdata(dev, cfb);
if (int_cfb_info == NULL)
int_cfb_info = cfb;
return 0;
failed:
iounmap(cfb->region);
failed_ioremap:
pci_release_regions(dev);
failed_regions:
cyberpro_free_fb_info(cfb);
failed_release:
return err;
}
static void cyberpro_pci_remove(struct pci_dev *dev)
{
struct cfb_info *cfb = pci_get_drvdata(dev);
if (cfb) {
cyberpro_common_remove(cfb);
iounmap(cfb->region);
cyberpro_free_fb_info(cfb);
if (cfb == int_cfb_info)
int_cfb_info = NULL;
pci_release_regions(dev);
}
}
static int cyberpro_pci_suspend(struct pci_dev *dev, pm_message_t state)
{
return 0;
}
static int cyberpro_pci_resume(struct pci_dev *dev)
{
struct cfb_info *cfb = pci_get_drvdata(dev);
if (cfb) {
cyberpro_pci_enable_mmio(cfb);
cyberpro_common_resume(cfb);
}
return 0;
}
static int __init cyber2000fb_init(void)
{
int ret = -1, err;
#ifndef MODULE
char *option = NULL;
if (fb_get_options("cyber2000fb", &option))
return -ENODEV;
cyber2000fb_setup(option);
#endif
err = pci_register_driver(&cyberpro_driver);
if (!err)
ret = 0;
return ret ? err : 0;
}
static void __exit cyberpro_exit(void)
{
pci_unregister_driver(&cyberpro_driver);
}
