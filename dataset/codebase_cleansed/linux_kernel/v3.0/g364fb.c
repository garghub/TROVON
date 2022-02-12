int g364fb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
switch (cursor->enable) {
case CM_ERASE:
*(unsigned int *) CTLA_REG |= CURS_TOGGLE;
break;
case CM_MOVE:
case CM_DRAW:
*(unsigned int *) CTLA_REG &= ~CURS_TOGGLE;
*(unsigned int *) CURS_POS_REG =
((x * fontwidth(p)) << 12) | ((y * fontheight(p)) -
info->var.yoffset);
break;
}
return 0;
}
static int g364fb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
if (var->xoffset || var->yoffset + var->yres > var->yres_virtual)
return -EINVAL;
*(unsigned int *) TOP_REG = var->yoffset * var->xres;
return 0;
}
static int g364fb_blank(int blank, struct fb_info *info)
{
if (blank)
*(unsigned int *) CTLA_REG |= FORCE_BLANK;
else
*(unsigned int *) CTLA_REG &= ~FORCE_BLANK;
return 0;
}
static int g364fb_setcolreg(u_int regno, u_int red, u_int green,
u_int blue, u_int transp, struct fb_info *info)
{
volatile unsigned int *ptr = (volatile unsigned int *) CLR_PAL_REG;
if (regno > 255)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
ptr[regno << 1] = (red << 16) | (green << 8) | blue;
return 0;
}
int __init g364fb_init(void)
{
volatile unsigned int *pal_ptr =
(volatile unsigned int *) CLR_PAL_REG;
volatile unsigned int *curs_pal_ptr =
(volatile unsigned int *) CURS_PAL_REG;
int mem, i, j;
if (fb_get_options("g364fb", NULL))
return -ENODEV;
*(volatile unsigned int *) CTLA_REG &= ~ENABLE_VTG;
fb_var.xres =
(*((volatile unsigned int *) DISPLAY_REG) & 0x00ffffff) * 4;
fb_var.yres =
(*((volatile unsigned int *) VDISPLAY_REG) & 0x00ffffff) / 2;
*(volatile unsigned int *) CTLA_REG |= ENABLE_VTG;
curs_pal_ptr[0] |= 0x00ffffff;
curs_pal_ptr[2] |= 0x00ffffff;
curs_pal_ptr[4] |= 0x00ffffff;
for (i = 0; i < 512; i++)
*(unsigned short *) (CURS_PAT_REG + i * 8) = 0;
*(unsigned short *) (CURS_PAT_REG + 14 * 64) = 0xffff;
*(unsigned short *) (CURS_PAT_REG + 15 * 64) = 0xffff;
fb_var.xres_virtual = fbvar.xres;
fb_fix.line_length = (xres / 8) * fb_var.bits_per_pixel;
fb_fix.smem_start = 0x40000000;
mem = (r4030_read_reg32(JAZZ_R4030_CONFIG) >> 8) & 3;
fb_fix.smem_len = (1 << (mem * 2)) * 512 * 1024;
fb_var.yres_virtual = fb_fix.smem_len / fb_var.xres;
fb_info.fbops = &g364fb_ops;
fb_info.screen_base = (char *) G364_MEM_BASE;
fb_info.var = fb_var;
fb_info.fix = fb_fix;
fb_info.flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
fb_alloc_cmap(&fb_info.cmap, 255, 0);
if (register_framebuffer(&fb_info) < 0)
return -EINVAL;
return 0;
}
