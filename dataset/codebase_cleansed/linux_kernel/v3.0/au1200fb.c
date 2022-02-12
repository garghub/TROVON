static int set_brightness(unsigned int brightness)
{
unsigned int hi1, divider;
if (brightness < 30) {
brightness = 30;
}
divider = (lcd->pwmdiv & 0x3FFFF) + 1;
hi1 = (lcd->pwmhi >> 16) + 1;
hi1 = (((brightness & 0xFF) + 1) * divider >> 8);
lcd->pwmhi &= 0xFFFF;
lcd->pwmhi |= (hi1 << 16);
return brightness;
}
static int winbpp (unsigned int winctrl1)
{
int bits = 0;
switch (winctrl1 & LCD_WINCTRL1_FRM) {
case LCD_WINCTRL1_FRM_1BPP:
bits = 1;
break;
case LCD_WINCTRL1_FRM_2BPP:
bits = 2;
break;
case LCD_WINCTRL1_FRM_4BPP:
bits = 4;
break;
case LCD_WINCTRL1_FRM_8BPP:
bits = 8;
break;
case LCD_WINCTRL1_FRM_12BPP:
case LCD_WINCTRL1_FRM_16BPP655:
case LCD_WINCTRL1_FRM_16BPP565:
case LCD_WINCTRL1_FRM_16BPP556:
case LCD_WINCTRL1_FRM_16BPPI1555:
case LCD_WINCTRL1_FRM_16BPPI5551:
case LCD_WINCTRL1_FRM_16BPPA1555:
case LCD_WINCTRL1_FRM_16BPPA5551:
bits = 16;
break;
case LCD_WINCTRL1_FRM_24BPP:
case LCD_WINCTRL1_FRM_32BPP:
bits = 32;
break;
}
return bits;
}
static int fbinfo2index (struct fb_info *fb_info)
{
int i;
for (i = 0; i < CONFIG_FB_AU1200_DEVS; ++i) {
if (fb_info == (struct fb_info *)(&_au1200fb_devices[i].fb_info))
return i;
}
printk("au1200fb: ERROR: fbinfo2index failed!\n");
return -1;
}
static int au1200_setlocation (struct au1200fb_device *fbdev, int plane,
int xpos, int ypos)
{
uint32 winctrl0, winctrl1, winenable, fb_offset = 0;
int xsz, ysz;
winctrl0 = lcd->window[plane].winctrl0;
winctrl1 = lcd->window[plane].winctrl1;
winctrl0 &= (LCD_WINCTRL0_A | LCD_WINCTRL0_AEN);
winctrl1 &= ~(LCD_WINCTRL1_SZX | LCD_WINCTRL1_SZY);
xsz = win->w[plane].xres;
ysz = win->w[plane].yres;
if ((xpos + win->w[plane].xres) > panel->Xres) {
xsz = panel->Xres - xpos;
}
if ((ypos + win->w[plane].yres) > panel->Yres) {
ysz = panel->Yres - ypos;
}
if (xpos < 0) {
xsz = win->w[plane].xres + xpos;
fb_offset += (((0 - xpos) * winbpp(lcd->window[plane].winctrl1))/8);
xpos = 0;
}
if (ypos < 0) {
ysz = win->w[plane].yres + ypos;
ypos = 0;
}
win->w[plane].xpos = xpos;
win->w[plane].ypos = ypos;
xsz -= 1;
ysz -= 1;
winctrl0 |= (xpos << 21);
winctrl0 |= (ypos << 10);
winctrl1 |= (xsz << 11);
winctrl1 |= (ysz << 0);
winenable = lcd->winenable & (1 << plane);
au_sync();
lcd->winenable &= ~(1 << plane);
lcd->window[plane].winctrl0 = winctrl0;
lcd->window[plane].winctrl1 = winctrl1;
lcd->window[plane].winbuf0 =
lcd->window[plane].winbuf1 = fbdev->fb_phys;
lcd->window[plane].winbufctrl = 0;
lcd->winenable |= winenable;
au_sync();
return 0;
}
static void au1200_setpanel (struct panel_settings *newpanel)
{
uint32 winenable;
winenable = lcd->winenable;
lcd->winenable = 0;
au_sync();
if (lcd->screen & LCD_SCREEN_SEN) {
lcd->intstatus = LCD_INT_SS;
while ((lcd->intstatus & LCD_INT_SS) == 0) {
au_sync();
}
lcd->screen &= ~LCD_SCREEN_SEN;
do {
lcd->intstatus = lcd->intstatus;
au_sync();
} while ((lcd->intstatus & LCD_INT_SD) == 0);
if (panel->device_shutdown != NULL)
panel->device_shutdown();
}
if (newpanel == NULL)
return;
panel = newpanel;
printk("Panel(%s), %dx%d\n", panel->name, panel->Xres, panel->Yres);
if (!(panel->mode_clkcontrol & LCD_CLKCONTROL_EXT))
{
uint32 sys_clksrc;
au_writel(panel->mode_auxpll, SYS_AUXPLL);
sys_clksrc = au_readl(SYS_CLKSRC) & ~0x0000001f;
sys_clksrc |= panel->mode_toyclksrc;
au_writel(sys_clksrc, SYS_CLKSRC);
}
lcd->screen = panel->mode_screen;
lcd->horztiming = panel->mode_horztiming;
lcd->verttiming = panel->mode_verttiming;
lcd->clkcontrol = panel->mode_clkcontrol;
lcd->pwmdiv = panel->mode_pwmdiv;
lcd->pwmhi = panel->mode_pwmhi;
lcd->outmask = panel->mode_outmask;
lcd->fifoctrl = panel->mode_fifoctrl;
au_sync();
#if 0
au1200_setlocation(fbdev, 0, win->w[0].xpos, win->w[0].ypos);
au1200_setlocation(fbdev, 1, win->w[1].xpos, win->w[1].ypos);
au1200_setlocation(fbdev, 2, win->w[2].xpos, win->w[2].ypos);
au1200_setlocation(fbdev, 3, win->w[3].xpos, win->w[3].ypos);
#endif
lcd->winenable = winenable;
lcd->screen |= LCD_SCREEN_SEN;
au_sync();
if (panel->device_init != NULL) panel->device_init();
lcd->intenable = 0;
lcd->intstatus = ~0;
lcd->backcolor = win->mode_backcolor;
lcd->colorkey = win->mode_colorkey;
lcd->colorkeymsk = win->mode_colorkeymsk;
lcd->hwc.cursorctrl = 0;
lcd->hwc.cursorpos = 0;
lcd->hwc.cursorcolor0 = 0;
lcd->hwc.cursorcolor1 = 0;
lcd->hwc.cursorcolor2 = 0;
lcd->hwc.cursorcolor3 = 0;
#if 0
#define D(X) printk("%25s: %08X\n", #X, X)
D(lcd->screen);
D(lcd->horztiming);
D(lcd->verttiming);
D(lcd->clkcontrol);
D(lcd->pwmdiv);
D(lcd->pwmhi);
D(lcd->outmask);
D(lcd->fifoctrl);
D(lcd->window[0].winctrl0);
D(lcd->window[0].winctrl1);
D(lcd->window[0].winctrl2);
D(lcd->window[0].winbuf0);
D(lcd->window[0].winbuf1);
D(lcd->window[0].winbufctrl);
D(lcd->window[1].winctrl0);
D(lcd->window[1].winctrl1);
D(lcd->window[1].winctrl2);
D(lcd->window[1].winbuf0);
D(lcd->window[1].winbuf1);
D(lcd->window[1].winbufctrl);
D(lcd->window[2].winctrl0);
D(lcd->window[2].winctrl1);
D(lcd->window[2].winctrl2);
D(lcd->window[2].winbuf0);
D(lcd->window[2].winbuf1);
D(lcd->window[2].winbufctrl);
D(lcd->window[3].winctrl0);
D(lcd->window[3].winctrl1);
D(lcd->window[3].winctrl2);
D(lcd->window[3].winbuf0);
D(lcd->window[3].winbuf1);
D(lcd->window[3].winbufctrl);
D(lcd->winenable);
D(lcd->intenable);
D(lcd->intstatus);
D(lcd->backcolor);
D(lcd->winenable);
D(lcd->colorkey);
D(lcd->colorkeymsk);
D(lcd->hwc.cursorctrl);
D(lcd->hwc.cursorpos);
D(lcd->hwc.cursorcolor0);
D(lcd->hwc.cursorcolor1);
D(lcd->hwc.cursorcolor2);
D(lcd->hwc.cursorcolor3);
#endif
}
static void au1200_setmode(struct au1200fb_device *fbdev)
{
int plane = fbdev->plane;
lcd->window[plane].winctrl1 = ( 0
| LCD_WINCTRL1_PRI_N(plane)
| win->w[plane].mode_winctrl1
) ;
au1200_setlocation(fbdev, plane, win->w[plane].xpos, win->w[plane].ypos);
lcd->window[plane].winctrl2 = ( 0
| LCD_WINCTRL2_CKMODE_00
| LCD_WINCTRL2_DBM
| LCD_WINCTRL2_BX_N( fbdev->fb_info.fix.line_length)
| LCD_WINCTRL2_SCX_1
| LCD_WINCTRL2_SCY_1
) ;
lcd->winenable |= win->w[plane].mode_winenable;
au_sync();
}
static void au1200fb_update_fbinfo(struct fb_info *fbi)
{
if (panel_is_color(panel)) {
if (fbi->var.bits_per_pixel <= 8) {
fbi->fix.visual = FB_VISUAL_PSEUDOCOLOR;
fbi->fix.line_length = fbi->var.xres_virtual /
(8/fbi->var.bits_per_pixel);
} else {
fbi->fix.visual = FB_VISUAL_TRUECOLOR;
fbi->fix.line_length = fbi->var.xres_virtual * (fbi->var.bits_per_pixel / 8);
}
} else {
fbi->fix.visual = FB_VISUAL_MONO10;
fbi->fix.line_length = fbi->var.xres_virtual / 8;
}
fbi->screen_size = fbi->fix.line_length * fbi->var.yres_virtual;
print_dbg("line length: %d\n", fbi->fix.line_length);
print_dbg("bits_per_pixel: %d\n", fbi->var.bits_per_pixel);
}
static int au1200fb_fb_check_var(struct fb_var_screeninfo *var,
struct fb_info *fbi)
{
struct au1200fb_device *fbdev = (struct au1200fb_device *)fbi;
u32 pixclock;
int screen_size, plane;
plane = fbdev->plane;
var->xres = win->w[plane].xres;
var->yres = win->w[plane].yres;
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
var->bits_per_pixel = winbpp(win->w[plane].mode_winctrl1);
screen_size = var->xres_virtual * var->yres_virtual;
if (var->bits_per_pixel > 8) screen_size *= (var->bits_per_pixel / 8);
else screen_size /= (8/var->bits_per_pixel);
if (fbdev->fb_len < screen_size)
return -EINVAL;
pixclock = max((u32)(PICOS2KHZ(var->pixclock) * 1000), fbi->monspecs.dclkmin);
pixclock = min3(pixclock, fbi->monspecs.dclkmax, (u32)AU1200_LCD_MAX_CLK/2);
if (AU1200_LCD_MAX_CLK % pixclock) {
int diff = AU1200_LCD_MAX_CLK % pixclock;
pixclock -= diff;
}
var->pixclock = KHZ2PICOS(pixclock/1000);
#if 0
if (!panel_is_active(panel)) {
int pcd = AU1200_LCD_MAX_CLK / (pixclock * 2) - 1;
if (!panel_is_color(panel)
&& (panel->control_base & LCD_CONTROL_MPI) && (pcd < 3)) {
var->pixclock = KHZ2PICOS(6000);
} else if (!pcd) {
var->pixclock = KHZ2PICOS(12000);
}
}
#endif
switch (var->bits_per_pixel) {
case 16:
{
int idx;
idx = (win->w[0].mode_winctrl1 & LCD_WINCTRL1_FRM) >> 25;
var->red = rgb_bitfields[idx][0];
var->green = rgb_bitfields[idx][1];
var->blue = rgb_bitfields[idx][2];
var->transp = rgb_bitfields[idx][3];
break;
}
case 32:
{
int idx;
idx = (win->w[0].mode_winctrl1 & LCD_WINCTRL1_FRM) >> 25;
var->red = rgb_bitfields[idx][0];
var->green = rgb_bitfields[idx][1];
var->blue = rgb_bitfields[idx][2];
var->transp = rgb_bitfields[idx][3];
break;
}
default:
print_dbg("Unsupported depth %dbpp", var->bits_per_pixel);
return -EINVAL;
}
return 0;
}
static int au1200fb_fb_set_par(struct fb_info *fbi)
{
struct au1200fb_device *fbdev = (struct au1200fb_device *)fbi;
au1200fb_update_fbinfo(fbi);
au1200_setmode(fbdev);
return 0;
}
static int au1200fb_fb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp, struct fb_info *fbi)
{
volatile u32 *palette = lcd->palette;
u32 value;
if (regno > (AU1200_LCD_NBR_PALETTE_ENTRIES - 1))
return -EINVAL;
if (fbi->var.grayscale) {
red = green = blue =
(19595 * red + 38470 * green + 7471 * blue) >> 16;
}
if (fbi->fix.visual == FB_VISUAL_TRUECOLOR) {
if (regno > 16)
return -EINVAL;
palette = (u32*) fbi->pseudo_palette;
red >>= (16 - fbi->var.red.length);
green >>= (16 - fbi->var.green.length);
blue >>= (16 - fbi->var.blue.length);
value = (red << fbi->var.red.offset) |
(green << fbi->var.green.offset)|
(blue << fbi->var.blue.offset);
value &= 0xFFFF;
} else if (1 ) {
value = (red & 0xF800)|((green >> 5) &
0x07E0)|((blue >> 11) & 0x001F);
value &= 0xFFFF;
} else if (0 ) {
value = 0x1234;
value &= 0xFFF;
} else {
value = (green >> 12) & 0x000F;
value &= 0xF;
}
palette[regno] = value;
return 0;
}
static int au1200fb_fb_blank(int blank_mode, struct fb_info *fbi)
{
if (noblanking)
return 0;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
case FB_BLANK_NORMAL:
au1200_setpanel(panel);
break;
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
au1200_setpanel(NULL);
break;
default:
break;
}
return (blank_mode == FB_BLANK_NORMAL) ? -EINVAL : 0;
}
static int au1200fb_fb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
unsigned int len;
unsigned long start=0, off;
struct au1200fb_device *fbdev = (struct au1200fb_device *) info;
#ifdef CONFIG_PM
au1xxx_pm_access(LCD_pm_dev);
#endif
if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT)) {
return -EINVAL;
}
start = fbdev->fb_phys & PAGE_MASK;
len = PAGE_ALIGN((start & ~PAGE_MASK) + fbdev->fb_len);
off = vma->vm_pgoff << PAGE_SHIFT;
if ((vma->vm_end - vma->vm_start + off) > len) {
return -EINVAL;
}
off += start;
vma->vm_pgoff = off >> PAGE_SHIFT;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
pgprot_val(vma->vm_page_prot) |= _CACHE_MASK;
vma->vm_flags |= VM_IO;
return io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
vma->vm_end - vma->vm_start,
vma->vm_page_prot);
return 0;
}
static void set_global(u_int cmd, struct au1200_lcd_global_regs_t *pdata)
{
unsigned int hi1, divider;
if (pdata->flags & SCREEN_BACKCOLOR)
lcd->backcolor = pdata->backcolor;
if (pdata->flags & SCREEN_BRIGHTNESS) {
if (pdata->brightness < 30) {
pdata->brightness = 30;
}
divider = (lcd->pwmdiv & 0x3FFFF) + 1;
hi1 = (lcd->pwmhi >> 16) + 1;
hi1 = (((pdata->brightness & 0xFF)+1) * divider >> 8);
lcd->pwmhi &= 0xFFFF;
lcd->pwmhi |= (hi1 << 16);
}
if (pdata->flags & SCREEN_COLORKEY)
lcd->colorkey = pdata->colorkey;
if (pdata->flags & SCREEN_MASK)
lcd->colorkeymsk = pdata->mask;
au_sync();
}
static void get_global(u_int cmd, struct au1200_lcd_global_regs_t *pdata)
{
unsigned int hi1, divider;
pdata->xsize = ((lcd->screen & LCD_SCREEN_SX) >> 19) + 1;
pdata->ysize = ((lcd->screen & LCD_SCREEN_SY) >> 8) + 1;
pdata->backcolor = lcd->backcolor;
pdata->colorkey = lcd->colorkey;
pdata->mask = lcd->colorkeymsk;
hi1 = (lcd->pwmhi >> 16) + 1;
divider = (lcd->pwmdiv & 0x3FFFF) + 1;
pdata->brightness = ((hi1 << 8) / divider) - 1;
au_sync();
}
static void set_window(unsigned int plane,
struct au1200_lcd_window_regs_t *pdata)
{
unsigned int val, bpp;
if (pdata->flags & WIN_POSITION) {
val = lcd->window[plane].winctrl0 & ~(LCD_WINCTRL0_OX |
LCD_WINCTRL0_OY);
val |= ((pdata->xpos << 21) & LCD_WINCTRL0_OX);
val |= ((pdata->ypos << 10) & LCD_WINCTRL0_OY);
lcd->window[plane].winctrl0 = val;
}
if (pdata->flags & WIN_ALPHA_COLOR) {
val = lcd->window[plane].winctrl0 & ~(LCD_WINCTRL0_A);
val |= ((pdata->alpha_color << 2) & LCD_WINCTRL0_A);
lcd->window[plane].winctrl0 = val;
}
if (pdata->flags & WIN_ALPHA_MODE) {
val = lcd->window[plane].winctrl0 & ~(LCD_WINCTRL0_AEN);
val |= ((pdata->alpha_mode << 1) & LCD_WINCTRL0_AEN);
lcd->window[plane].winctrl0 = val;
}
if (pdata->flags & WIN_PRIORITY) {
val = lcd->window[plane].winctrl1 & ~(LCD_WINCTRL1_PRI);
val |= ((pdata->priority << 30) & LCD_WINCTRL1_PRI);
lcd->window[plane].winctrl1 = val;
}
if (pdata->flags & WIN_CHANNEL) {
val = lcd->window[plane].winctrl1 & ~(LCD_WINCTRL1_PIPE);
val |= ((pdata->channel << 29) & LCD_WINCTRL1_PIPE);
lcd->window[plane].winctrl1 = val;
}
if (pdata->flags & WIN_BUFFER_FORMAT) {
val = lcd->window[plane].winctrl1 & ~(LCD_WINCTRL1_FRM);
val |= ((pdata->buffer_format << 25) & LCD_WINCTRL1_FRM);
lcd->window[plane].winctrl1 = val;
}
if (pdata->flags & WIN_COLOR_ORDER) {
val = lcd->window[plane].winctrl1 & ~(LCD_WINCTRL1_CCO);
val |= ((pdata->color_order << 24) & LCD_WINCTRL1_CCO);
lcd->window[plane].winctrl1 = val;
}
if (pdata->flags & WIN_PIXEL_ORDER) {
val = lcd->window[plane].winctrl1 & ~(LCD_WINCTRL1_PO);
val |= ((pdata->pixel_order << 22) & LCD_WINCTRL1_PO);
lcd->window[plane].winctrl1 = val;
}
if (pdata->flags & WIN_SIZE) {
val = lcd->window[plane].winctrl1 & ~(LCD_WINCTRL1_SZX |
LCD_WINCTRL1_SZY);
val |= (((pdata->xsize << 11) - 1) & LCD_WINCTRL1_SZX);
val |= (((pdata->ysize) - 1) & LCD_WINCTRL1_SZY);
lcd->window[plane].winctrl1 = val;
bpp = winbpp(val) / 8;
val = lcd->window[plane].winctrl2 & ~(LCD_WINCTRL2_BX);
val |= (((pdata->xsize * bpp) << 8) & LCD_WINCTRL2_BX);
lcd->window[plane].winctrl2 = val;
}
if (pdata->flags & WIN_COLORKEY_MODE) {
val = lcd->window[plane].winctrl2 & ~(LCD_WINCTRL2_CKMODE);
val |= ((pdata->colorkey_mode << 24) & LCD_WINCTRL2_CKMODE);
lcd->window[plane].winctrl2 = val;
}
if (pdata->flags & WIN_DOUBLE_BUFFER_MODE) {
val = lcd->window[plane].winctrl2 & ~(LCD_WINCTRL2_DBM);
val |= ((pdata->double_buffer_mode << 23) & LCD_WINCTRL2_DBM);
lcd->window[plane].winctrl2 = val;
}
if (pdata->flags & WIN_RAM_ARRAY_MODE) {
val = lcd->window[plane].winctrl2 & ~(LCD_WINCTRL2_RAM);
val |= ((pdata->ram_array_mode << 21) & LCD_WINCTRL2_RAM);
lcd->window[plane].winctrl2 = val;
}
if (pdata->flags & WIN_BUFFER_SCALE) {
val = lcd->window[plane].winctrl2 & ~(LCD_WINCTRL2_SCX |
LCD_WINCTRL2_SCY);
val |= ((pdata->xsize << 11) & LCD_WINCTRL2_SCX);
val |= ((pdata->ysize) & LCD_WINCTRL2_SCY);
lcd->window[plane].winctrl2 = val;
}
if (pdata->flags & WIN_ENABLE) {
val = lcd->winenable;
val &= ~(1<<plane);
val |= (pdata->enable & 1) << plane;
lcd->winenable = val;
}
au_sync();
}
static void get_window(unsigned int plane,
struct au1200_lcd_window_regs_t *pdata)
{
pdata->xpos = (lcd->window[plane].winctrl0 & LCD_WINCTRL0_OX) >> 21;
pdata->ypos = (lcd->window[plane].winctrl0 & LCD_WINCTRL0_OY) >> 10;
pdata->alpha_color = (lcd->window[plane].winctrl0 & LCD_WINCTRL0_A) >> 2;
pdata->alpha_mode = (lcd->window[plane].winctrl0 & LCD_WINCTRL0_AEN) >> 1;
pdata->priority = (lcd->window[plane].winctrl1& LCD_WINCTRL1_PRI) >> 30;
pdata->channel = (lcd->window[plane].winctrl1 & LCD_WINCTRL1_PIPE) >> 29;
pdata->buffer_format = (lcd->window[plane].winctrl1 & LCD_WINCTRL1_FRM) >> 25;
pdata->color_order = (lcd->window[plane].winctrl1 & LCD_WINCTRL1_CCO) >> 24;
pdata->pixel_order = (lcd->window[plane].winctrl1 & LCD_WINCTRL1_PO) >> 22;
pdata->xsize = ((lcd->window[plane].winctrl1 & LCD_WINCTRL1_SZX) >> 11) + 1;
pdata->ysize = (lcd->window[plane].winctrl1 & LCD_WINCTRL1_SZY) + 1;
pdata->colorkey_mode = (lcd->window[plane].winctrl2 & LCD_WINCTRL2_CKMODE) >> 24;
pdata->double_buffer_mode = (lcd->window[plane].winctrl2 & LCD_WINCTRL2_DBM) >> 23;
pdata->ram_array_mode = (lcd->window[plane].winctrl2 & LCD_WINCTRL2_RAM) >> 21;
pdata->enable = (lcd->winenable >> plane) & 1;
au_sync();
}
static int au1200fb_ioctl(struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
int plane;
int val;
#ifdef CONFIG_PM
au1xxx_pm_access(LCD_pm_dev);
#endif
plane = fbinfo2index(info);
print_dbg("au1200fb: ioctl %d on plane %d\n", cmd, plane);
if (cmd == AU1200_LCD_FB_IOCTL) {
struct au1200_lcd_iodata_t iodata;
if (copy_from_user(&iodata, (void __user *) arg, sizeof(iodata)))
return -EFAULT;
print_dbg("FB IOCTL called\n");
switch (iodata.subcmd) {
case AU1200_LCD_SET_SCREEN:
print_dbg("AU1200_LCD_SET_SCREEN\n");
set_global(cmd, &iodata.global);
break;
case AU1200_LCD_GET_SCREEN:
print_dbg("AU1200_LCD_GET_SCREEN\n");
get_global(cmd, &iodata.global);
break;
case AU1200_LCD_SET_WINDOW:
print_dbg("AU1200_LCD_SET_WINDOW\n");
set_window(plane, &iodata.window);
break;
case AU1200_LCD_GET_WINDOW:
print_dbg("AU1200_LCD_GET_WINDOW\n");
get_window(plane, &iodata.window);
break;
case AU1200_LCD_SET_PANEL:
print_dbg("AU1200_LCD_SET_PANEL\n");
if ((iodata.global.panel_choice >= 0) &&
(iodata.global.panel_choice <
NUM_PANELS))
{
struct panel_settings *newpanel;
panel_index = iodata.global.panel_choice;
newpanel = &known_lcd_panels[panel_index];
au1200_setpanel(newpanel);
}
break;
case AU1200_LCD_GET_PANEL:
print_dbg("AU1200_LCD_GET_PANEL\n");
iodata.global.panel_choice = panel_index;
break;
default:
return -EINVAL;
}
val = copy_to_user((void __user *) arg, &iodata, sizeof(iodata));
if (val) {
print_dbg("error: could not copy %d bytes\n", val);
return -EFAULT;
}
}
return 0;
}
static irqreturn_t au1200fb_handle_irq(int irq, void* dev_id)
{
lcd->intstatus = lcd->intstatus;
au_sync();
return IRQ_HANDLED;
}
static int au1200fb_init_fbinfo(struct au1200fb_device *fbdev)
{
struct fb_info *fbi = &fbdev->fb_info;
int bpp;
memset(fbi, 0, sizeof(struct fb_info));
fbi->fbops = &au1200fb_fb_ops;
bpp = winbpp(win->w[fbdev->plane].mode_winctrl1);
memcpy(&fbi->monspecs, &panel->monspecs, sizeof(struct fb_monspecs));
if (!fb_find_mode(&fbi->var,
fbi,
NULL,
fbi->monspecs.modedb,
fbi->monspecs.modedb_len,
fbi->monspecs.modedb,
bpp)) {
print_err("Cannot find valid mode for panel %s", panel->name);
return -EFAULT;
}
fbi->pseudo_palette = kcalloc(16, sizeof(u32), GFP_KERNEL);
if (!fbi->pseudo_palette) {
return -ENOMEM;
}
if (fb_alloc_cmap(&fbi->cmap, AU1200_LCD_NBR_PALETTE_ENTRIES, 0) < 0) {
print_err("Fail to allocate colormap (%d entries)",
AU1200_LCD_NBR_PALETTE_ENTRIES);
kfree(fbi->pseudo_palette);
return -EFAULT;
}
strncpy(fbi->fix.id, "AU1200", sizeof(fbi->fix.id));
fbi->fix.smem_start = fbdev->fb_phys;
fbi->fix.smem_len = fbdev->fb_len;
fbi->fix.type = FB_TYPE_PACKED_PIXELS;
fbi->fix.xpanstep = 0;
fbi->fix.ypanstep = 0;
fbi->fix.mmio_start = 0;
fbi->fix.mmio_len = 0;
fbi->fix.accel = FB_ACCEL_NONE;
fbi->screen_base = (char __iomem *) fbdev->fb_mem;
au1200fb_update_fbinfo(fbi);
return 0;
}
static int au1200fb_drv_probe(struct platform_device *dev)
{
struct au1200fb_device *fbdev;
unsigned long page;
int bpp, plane, ret;
if (!dev)
return -EINVAL;
for (plane = 0; plane < CONFIG_FB_AU1200_DEVS; ++plane) {
bpp = winbpp(win->w[plane].mode_winctrl1);
if (win->w[plane].xres == 0)
win->w[plane].xres = panel->Xres;
if (win->w[plane].yres == 0)
win->w[plane].yres = panel->Yres;
fbdev = &_au1200fb_devices[plane];
memset(fbdev, 0, sizeof(struct au1200fb_device));
fbdev->plane = plane;
fbdev->fb_len = (win->w[plane].xres * win->w[plane].yres * bpp) / 8;
fbdev->fb_mem = dma_alloc_noncoherent(&dev->dev,
PAGE_ALIGN(fbdev->fb_len),
&fbdev->fb_phys, GFP_KERNEL);
if (!fbdev->fb_mem) {
print_err("fail to allocate frambuffer (size: %dK))",
fbdev->fb_len / 1024);
return -ENOMEM;
}
for (page = (unsigned long)fbdev->fb_phys;
page < PAGE_ALIGN((unsigned long)fbdev->fb_phys +
fbdev->fb_len);
page += PAGE_SIZE) {
SetPageReserved(pfn_to_page(page >> PAGE_SHIFT));
}
print_dbg("Framebuffer memory map at %p", fbdev->fb_mem);
print_dbg("phys=0x%08x, size=%dK", fbdev->fb_phys, fbdev->fb_len / 1024);
if ((ret = au1200fb_init_fbinfo(fbdev)) < 0)
goto failed;
if ((ret = register_framebuffer(&fbdev->fb_info)) < 0) {
print_err("cannot register new framebuffer");
goto failed;
}
au1200fb_fb_set_par(&fbdev->fb_info);
#if !defined(CONFIG_FRAMEBUFFER_CONSOLE) && defined(CONFIG_LOGO)
if (plane == 0)
if (fb_prepare_logo(&fbdev->fb_info, FB_ROTATE_UR)) {
fb_set_cmap(&fbdev->fb_info.cmap,
&fbdev->fb_info);
fb_show_logo(&fbdev->fb_info, FB_ROTATE_UR);
}
#endif
}
if ((ret = request_irq(AU1200_LCD_INT, au1200fb_handle_irq,
IRQF_DISABLED | IRQF_SHARED, "lcd", (void *)dev)) < 0) {
print_err("fail to request interrupt line %d (err: %d)",
AU1200_LCD_INT, ret);
goto failed;
}
return 0;
failed:
if (fbdev->fb_mem)
dma_free_noncoherent(dev, PAGE_ALIGN(fbdev->fb_len),
fbdev->fb_mem, fbdev->fb_phys);
if (fbdev->fb_info.cmap.len != 0)
fb_dealloc_cmap(&fbdev->fb_info.cmap);
if (fbdev->fb_info.pseudo_palette)
kfree(fbdev->fb_info.pseudo_palette);
if (plane == 0)
free_irq(AU1200_LCD_INT, (void*)dev);
return ret;
}
static int au1200fb_drv_remove(struct platform_device *dev)
{
struct au1200fb_device *fbdev;
int plane;
if (!dev)
return -ENODEV;
au1200_setpanel(NULL);
for (plane = 0; plane < CONFIG_FB_AU1200_DEVS; ++plane)
{
fbdev = &_au1200fb_devices[plane];
unregister_framebuffer(&fbdev->fb_info);
if (fbdev->fb_mem)
dma_free_noncoherent(&dev->dev,
PAGE_ALIGN(fbdev->fb_len),
fbdev->fb_mem, fbdev->fb_phys);
if (fbdev->fb_info.cmap.len != 0)
fb_dealloc_cmap(&fbdev->fb_info.cmap);
if (fbdev->fb_info.pseudo_palette)
kfree(fbdev->fb_info.pseudo_palette);
}
free_irq(AU1200_LCD_INT, (void *)dev);
return 0;
}
static int au1200fb_drv_suspend(struct platform_device *dev, u32 state)
{
return 0;
}
static int au1200fb_drv_resume(struct platform_device *dev)
{
return 0;
}
static void au1200fb_setup(void)
{
char* options = NULL;
char* this_opt;
int num_panels = ARRAY_SIZE(known_lcd_panels);
int panel_idx = -1;
fb_get_options(DRIVER_NAME, &options);
if (options) {
while ((this_opt = strsep(&options,",")) != NULL) {
if (!strncmp(this_opt, "panel:", 6)) {
int i;
long int li;
char *endptr;
this_opt += 6;
li = simple_strtol(this_opt, &endptr, 0);
if (*endptr == '\0') {
panel_idx = (int)li;
}
else if (strcmp(this_opt, "bs") == 0) {
extern int board_au1200fb_panel(void);
panel_idx = board_au1200fb_panel();
}
else
for (i = 0; i < num_panels; i++) {
if (!strcmp(this_opt, known_lcd_panels[i].name)) {
panel_idx = i;
break;
}
}
if ((panel_idx < 0) || (panel_idx >= num_panels)) {
print_warn("Panel %s not supported!", this_opt);
}
else
panel_index = panel_idx;
}
else if (strncmp(this_opt, "nohwcursor", 10) == 0) {
nohwcursor = 1;
}
else {
print_warn("Unsupported option \"%s\"", this_opt);
}
}
}
}
static int au1200fb_pm_callback(au1xxx_power_dev_t *dev,
au1xxx_request_t request, void *data) {
int retval = -1;
unsigned int d = 0;
unsigned int brightness = 0;
if (request == AU1XXX_PM_SLEEP) {
board_au1200fb_panel_shutdown();
}
else if (request == AU1XXX_PM_WAKEUP) {
if(dev->prev_state == SLEEP_STATE)
{
int plane;
au1200_setpanel(panel);
for (plane = 0; plane < CONFIG_FB_AU1200_DEVS; ++plane) {
struct au1200fb_device *fbdev;
fbdev = &_au1200fb_devices[plane];
au1200fb_fb_set_par(&fbdev->fb_info);
}
}
d = *((unsigned int*)data);
if(d <=10) brightness = 26;
else if(d<=20) brightness = 51;
else if(d<=30) brightness = 77;
else if(d<=40) brightness = 102;
else if(d<=50) brightness = 128;
else if(d<=60) brightness = 153;
else if(d<=70) brightness = 179;
else if(d<=80) brightness = 204;
else if(d<=90) brightness = 230;
else brightness = 255;
set_brightness(brightness);
} else if (request == AU1XXX_PM_GETSTATUS) {
return dev->cur_state;
} else if (request == AU1XXX_PM_ACCESS) {
if (dev->cur_state != SLEEP_STATE)
return retval;
else {
au1200_setpanel(panel);
}
} else if (request == AU1XXX_PM_IDLE) {
} else if (request == AU1XXX_PM_CLEANUP) {
}
return retval;
}
static int __init au1200fb_init(void)
{
print_info("" DRIVER_DESC "");
au1200fb_setup();
panel = &known_lcd_panels[panel_index];
win = &windows[window_index];
printk(DRIVER_NAME ": Panel %d %s\n", panel_index, panel->name);
printk(DRIVER_NAME ": Win %d %s\n", window_index, win->name);
au1200_setpanel(panel);
#ifdef CONFIG_PM
LCD_pm_dev = new_au1xxx_power_device("LCD", &au1200fb_pm_callback, NULL);
if ( LCD_pm_dev == NULL)
printk(KERN_INFO "Unable to create a power management device entry for the au1200fb.\n");
else
printk(KERN_INFO "Power management device entry for the au1200fb loaded.\n");
#endif
return platform_driver_register(&au1200fb_driver);
}
static void __exit au1200fb_cleanup(void)
{
platform_driver_unregister(&au1200fb_driver);
}
