void round_off_xres(u32 *xres) { }
void round_off_yres(u32 *xres, u32 *yres) { }
void i810fb_encode_registers(const struct fb_var_screeninfo *var,
struct i810fb_par *par, u32 xres, u32 yres)
{
int n, blank_s, blank_e;
u8 __iomem *mmio = par->mmio_start_virtual;
u8 msr = 0;
n = ((xres + var->right_margin + var->hsync_len +
var->left_margin) >> 3) - 5;
par->regs.cr00 = (u8) n;
par->regs.cr35 = (u8) ((n >> 8) & 1);
par->regs.cr01 = (u8) ((xres >> 3) - 1);
blank_e = (xres + var->right_margin + var->hsync_len +
var->left_margin) >> 3;
blank_e--;
blank_s = blank_e - 127;
if (blank_s < (xres >> 3))
blank_s = xres >> 3;
par->regs.cr02 = (u8) blank_s;
par->regs.cr03 = (u8) (blank_e & 0x1F);
par->regs.cr05 = (u8) ((blank_e & (1 << 5)) << 2);
par->regs.cr39 = (u8) ((blank_e >> 6) & 1);
par->regs.cr04 = (u8) ((xres + var->right_margin) >> 3);
par->regs.cr05 |= (u8) (((xres + var->right_margin +
var->hsync_len) >> 3) & 0x1F);
n = yres + var->lower_margin + var->vsync_len + var->upper_margin - 2;
par->regs.cr06 = (u8) (n & 0xFF);
par->regs.cr30 = (u8) ((n >> 8) & 0x0F);
n = yres + var->lower_margin;
par->regs.cr10 = (u8) (n & 0xFF);
par->regs.cr32 = (u8) ((n >> 8) & 0x0F);
par->regs.cr11 = i810_readb(CR11, mmio) & ~0x0F;
par->regs.cr11 |= (u8) ((yres + var->lower_margin +
var->vsync_len) & 0x0F);
n = yres - 1;
par->regs.cr12 = (u8) (n & 0xFF);
par->regs.cr31 = (u8) ((n >> 8) & 0x0F);
blank_e = yres + var->lower_margin + var->vsync_len +
var->upper_margin;
blank_e--;
blank_s = blank_e - 127;
if (blank_s < yres)
blank_s = yres;
par->regs.cr15 = (u8) (blank_s & 0xFF);
par->regs.cr33 = (u8) ((blank_s >> 8) & 0x0F);
par->regs.cr16 = (u8) (blank_e & 0xFF);
par->regs.cr09 = 0;
if (!(var->sync & FB_SYNC_HOR_HIGH_ACT))
msr |= 1 << 6;
if (!(var->sync & FB_SYNC_VERT_HIGH_ACT))
msr |= 1 << 7;
par->regs.msr = msr;
if (var->vmode & FB_VMODE_INTERLACED)
par->interlace = (1 << 7) | ((u8) (var->yres >> 4));
else
par->interlace = 0;
if (var->vmode & FB_VMODE_DOUBLE)
par->regs.cr09 |= 1 << 7;
par->ovract = ((var->xres + var->right_margin + var->hsync_len +
var->left_margin - 32) | ((var->xres - 32) << 16));
}
void i810fb_fill_var_timings(struct fb_var_screeninfo *var) { }
u32 i810_get_watermark(const struct fb_var_screeninfo *var,
struct i810fb_par *par)
{
struct wm_info *wmark = NULL;
u32 i, size = 0, pixclock, wm_best = 0, min, diff;
if (par->mem_freq == 100) {
switch (var->bits_per_pixel) {
case 8:
wmark = i810_wm_8_100;
size = ARRAY_SIZE(i810_wm_8_100);
break;
case 16:
wmark = i810_wm_16_100;
size = ARRAY_SIZE(i810_wm_16_100);
break;
case 24:
case 32:
wmark = i810_wm_24_100;
size = ARRAY_SIZE(i810_wm_24_100);
}
} else {
switch(var->bits_per_pixel) {
case 8:
wmark = i810_wm_8_133;
size = ARRAY_SIZE(i810_wm_8_133);
break;
case 16:
wmark = i810_wm_16_133;
size = ARRAY_SIZE(i810_wm_16_133);
break;
case 24:
case 32:
wmark = i810_wm_24_133;
size = ARRAY_SIZE(i810_wm_24_133);
}
}
pixclock = 1000000/var->pixclock;
min = ~0;
for (i = 0; i < size; i++) {
if (pixclock <= wmark[i].freq)
diff = wmark[i].freq - pixclock;
else
diff = pixclock - wmark[i].freq;
if (diff < min) {
wm_best = wmark[i].wm;
min = diff;
}
}
return wm_best;
}
