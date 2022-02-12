static inline void pvr2fb_set_pal_type(unsigned int type)
{
struct pvr2fb_par *par = (struct pvr2fb_par *)fb_info->par;
fb_writel(type, par->mmio_base + 0x108);
}
static inline void pvr2fb_set_pal_entry(struct pvr2fb_par *par,
unsigned int regno,
unsigned int val)
{
fb_writel(val, par->mmio_base + 0x1000 + (4 * regno));
}
static int pvr2fb_blank(int blank, struct fb_info *info)
{
do_blank = blank ? blank : -1;
return 0;
}
static inline unsigned long get_line_length(int xres_virtual, int bpp)
{
return (unsigned long)((((xres_virtual*bpp)+31)&~31) >> 3);
}
static void set_color_bitfields(struct fb_var_screeninfo *var)
{
switch (var->bits_per_pixel) {
case 16:
pvr2fb_set_pal_type(PAL_RGB565);
var->red.offset = 11; var->red.length = 5;
var->green.offset = 5; var->green.length = 6;
var->blue.offset = 0; var->blue.length = 5;
var->transp.offset = 0; var->transp.length = 0;
break;
case 24:
var->red.offset = 16; var->red.length = 8;
var->green.offset = 8; var->green.length = 8;
var->blue.offset = 0; var->blue.length = 8;
var->transp.offset = 0; var->transp.length = 0;
break;
case 32:
pvr2fb_set_pal_type(PAL_ARGB8888);
var->red.offset = 16; var->red.length = 8;
var->green.offset = 8; var->green.length = 8;
var->blue.offset = 0; var->blue.length = 8;
var->transp.offset = 24; var->transp.length = 8;
break;
}
}
static int pvr2fb_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
struct pvr2fb_par *par = (struct pvr2fb_par *)info->par;
unsigned int tmp;
if (regno > info->cmap.len)
return 1;
switch (info->var.bits_per_pixel) {
case 16:
tmp = (red & 0xf800) |
((green & 0xfc00) >> 5) |
((blue & 0xf800) >> 11);
pvr2fb_set_pal_entry(par, regno, tmp);
break;
case 24:
red >>= 8; green >>= 8; blue >>= 8;
tmp = (red << 16) | (green << 8) | blue;
break;
case 32:
red >>= 8; green >>= 8; blue >>= 8;
tmp = (transp << 24) | (red << 16) | (green << 8) | blue;
pvr2fb_set_pal_entry(par, regno, tmp);
break;
default:
pr_debug("Invalid bit depth %d?!?\n", info->var.bits_per_pixel);
return 1;
}
if (regno < 16)
((u32*)(info->pseudo_palette))[regno] = tmp;
return 0;
}
static int pvr2fb_set_par(struct fb_info *info)
{
struct pvr2fb_par *par = (struct pvr2fb_par *)info->par;
struct fb_var_screeninfo *var = &info->var;
unsigned long line_length;
unsigned int vtotal;
cable_type = pvr2_init_cable();
if (cable_type == CT_VGA && video_output != VO_VGA)
video_output = VO_VGA;
var->vmode &= FB_VMODE_MASK;
if (var->vmode & FB_VMODE_INTERLACED && video_output != VO_VGA)
par->is_interlaced = 1;
if (var->vmode & FB_VMODE_DOUBLE && video_output == VO_VGA)
par->is_doublescan = 1;
par->hsync_total = var->left_margin + var->xres + var->right_margin +
var->hsync_len;
par->vsync_total = var->upper_margin + var->yres + var->lower_margin +
var->vsync_len;
if (var->sync & FB_SYNC_BROADCAST) {
vtotal = par->vsync_total;
if (par->is_interlaced)
vtotal /= 2;
if (vtotal > (PAL_VTOTAL + NTSC_VTOTAL)/2) {
par->borderstart_h = 116;
par->borderstart_v = 44;
} else {
par->borderstart_h = 126;
par->borderstart_v = 18;
}
} else {
par->borderstart_h = 126;
par->borderstart_v = 40;
}
par->diwstart_h = par->borderstart_h + var->left_margin;
par->diwstart_v = par->borderstart_v + var->upper_margin;
par->borderstop_h = par->diwstart_h + var->xres +
var->right_margin;
par->borderstop_v = par->diwstart_v + var->yres +
var->lower_margin;
if (!par->is_interlaced)
par->borderstop_v /= 2;
if (info->var.xres < 640)
par->is_lowres = 1;
line_length = get_line_length(var->xres_virtual, var->bits_per_pixel);
par->disp_start = info->fix.smem_start + (line_length * var->yoffset) * line_length;
info->fix.line_length = line_length;
return 0;
}
static int pvr2fb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct pvr2fb_par *par = (struct pvr2fb_par *)info->par;
unsigned int vtotal, hsync_total;
unsigned long line_length;
if (var->pixclock != TV_CLK && var->pixclock != VGA_CLK) {
pr_debug("Invalid pixclock value %d\n", var->pixclock);
return -EINVAL;
}
if (var->xres < 320)
var->xres = 320;
if (var->yres < 240)
var->yres = 240;
if (var->xres_virtual < var->xres)
var->xres_virtual = var->xres;
if (var->yres_virtual < var->yres)
var->yres_virtual = var->yres;
if (var->bits_per_pixel <= 16)
var->bits_per_pixel = 16;
else if (var->bits_per_pixel <= 24)
var->bits_per_pixel = 24;
else if (var->bits_per_pixel <= 32)
var->bits_per_pixel = 32;
set_color_bitfields(var);
if (var->vmode & FB_VMODE_YWRAP) {
if (var->xoffset || var->yoffset < 0 ||
var->yoffset >= var->yres_virtual) {
var->xoffset = var->yoffset = 0;
} else {
if (var->xoffset > var->xres_virtual - var->xres ||
var->yoffset > var->yres_virtual - var->yres ||
var->xoffset < 0 || var->yoffset < 0)
var->xoffset = var->yoffset = 0;
}
} else {
var->xoffset = var->yoffset = 0;
}
if (var->yres < 480 && video_output == VO_VGA)
var->vmode |= FB_VMODE_DOUBLE;
if (video_output != VO_VGA) {
var->sync |= FB_SYNC_BROADCAST;
var->vmode |= FB_VMODE_INTERLACED;
} else {
var->sync &= ~FB_SYNC_BROADCAST;
var->vmode &= ~FB_VMODE_INTERLACED;
var->vmode |= FB_VMODE_NONINTERLACED;
}
if ((var->activate & FB_ACTIVATE_MASK) != FB_ACTIVATE_TEST) {
var->right_margin = par->borderstop_h -
(par->diwstart_h + var->xres);
var->left_margin = par->diwstart_h - par->borderstart_h;
var->hsync_len = par->borderstart_h +
(par->hsync_total - par->borderstop_h);
var->upper_margin = par->diwstart_v - par->borderstart_v;
var->lower_margin = par->borderstop_v -
(par->diwstart_v + var->yres);
var->vsync_len = par->borderstop_v +
(par->vsync_total - par->borderstop_v);
}
hsync_total = var->left_margin + var->xres + var->right_margin +
var->hsync_len;
vtotal = var->upper_margin + var->yres + var->lower_margin +
var->vsync_len;
if (var->sync & FB_SYNC_BROADCAST) {
if (var->vmode & FB_VMODE_INTERLACED)
vtotal /= 2;
if (vtotal > (PAL_VTOTAL + NTSC_VTOTAL)/2) {
if (hsync_total != PAL_HTOTAL) {
pr_debug("invalid hsync total for PAL\n");
return -EINVAL;
}
} else {
if (hsync_total != NTSC_HTOTAL) {
pr_debug("invalid hsync total for NTSC\n");
return -EINVAL;
}
}
}
line_length = get_line_length(var->xres_virtual, var->bits_per_pixel);
if (line_length * var->yres_virtual > info->fix.smem_len)
return -ENOMEM;
return 0;
}
static void pvr2_update_display(struct fb_info *info)
{
struct pvr2fb_par *par = (struct pvr2fb_par *) info->par;
struct fb_var_screeninfo *var = &info->var;
fb_writel(par->disp_start, DISP_DIWADDRL);
fb_writel(par->disp_start +
get_line_length(var->xoffset+var->xres, var->bits_per_pixel),
DISP_DIWADDRS);
}
static void pvr2_init_display(struct fb_info *info)
{
struct pvr2fb_par *par = (struct pvr2fb_par *) info->par;
struct fb_var_screeninfo *var = &info->var;
unsigned int diw_height, diw_width, diw_modulo = 1;
unsigned int bytesperpixel = var->bits_per_pixel >> 3;
fb_writel((par->vsync_total << 16) | par->hsync_total, DISP_SYNCSIZE);
if (video_output != VO_VGA && par->is_interlaced)
diw_modulo += info->fix.line_length / 4;
diw_height = (par->is_interlaced ? var->yres / 2 : var->yres);
diw_width = get_line_length(var->xres, var->bits_per_pixel) / 4;
fb_writel((diw_modulo << 20) | (--diw_height << 10) | --diw_width,
DISP_DIWSIZE);
fb_writel(par->disp_start, DISP_DIWADDRL);
fb_writel(par->disp_start +
get_line_length(var->xoffset+var->xres, var->bits_per_pixel),
DISP_DIWADDRS);
fb_writel((par->borderstart_h << 16) | par->borderstop_h, DISP_BRDRHORZ);
fb_writel((par->borderstart_v << 16) | par->borderstop_v, DISP_BRDRVERT);
fb_writel(0, DISP_BRDRCOLR);
fb_writel(par->diwstart_h, DISP_DIWHSTRT);
fb_writel((par->diwstart_v << 16) | par->diwstart_v, DISP_DIWVSTRT);
fb_writel((0x16 << 16) | par->is_lowres, DISP_DIWCONF);
fb_writel(((video_output == VO_VGA) << 23) |
(par->is_doublescan << 1) | 1, DISP_DIWMODE);
fb_writel(fb_readl(DISP_DIWMODE) | (--bytesperpixel << 2), DISP_DIWMODE);
fb_writel(bytesperpixel << 2, DISP_PIXDEPTH);
fb_writel(0x100 | ((par->is_interlaced ) << 4), DISP_SYNCCONF);
}
static void pvr2_do_blank(void)
{
struct pvr2fb_par *par = currentpar;
unsigned long diwconf;
diwconf = fb_readl(DISP_DIWCONF);
if (do_blank > 0)
fb_writel(diwconf | BLANK_BIT, DISP_DIWCONF);
else
fb_writel(diwconf & ~BLANK_BIT, DISP_DIWCONF);
is_blanked = do_blank > 0 ? do_blank : 0;
}
static irqreturn_t pvr2fb_interrupt(int irq, void *dev_id)
{
struct fb_info *info = dev_id;
if (do_vmode_pan || do_vmode_full)
pvr2_update_display(info);
if (do_vmode_full)
pvr2_init_display(info);
if (do_vmode_pan)
do_vmode_pan = 0;
if (do_vmode_full)
do_vmode_full = 0;
if (do_blank) {
pvr2_do_blank();
do_blank = 0;
}
return IRQ_HANDLED;
}
static int pvr2_init_cable(void)
{
if (cable_type < 0) {
fb_writel((fb_readl(PCTRA) & 0xfff0ffff) | 0x000a0000,
PCTRA);
cable_type = (fb_readw(PDTRA) >> 8) & 3;
}
if (cable_type == CT_COMPOSITE)
fb_writel(3 << 8, VOUTC);
else if (cable_type == CT_RGB)
fb_writel(1 << 9, VOUTC);
else
fb_writel(0, VOUTC);
return cable_type;
}
static ssize_t pvr2fb_write(struct fb_info *info, const char *buf,
size_t count, loff_t *ppos)
{
unsigned long dst, start, end, len;
unsigned int nr_pages;
struct page **pages;
int ret, i;
nr_pages = (count + PAGE_SIZE - 1) >> PAGE_SHIFT;
pages = kmalloc(nr_pages * sizeof(struct page *), GFP_KERNEL);
if (!pages)
return -ENOMEM;
down_read(&current->mm->mmap_sem);
ret = get_user_pages(current, current->mm, (unsigned long)buf,
nr_pages, WRITE, 0, pages, NULL);
up_read(&current->mm->mmap_sem);
if (ret < nr_pages) {
nr_pages = ret;
ret = -EINVAL;
goto out_unmap;
}
dma_configure_channel(shdma, 0x12c1);
dst = (unsigned long)fb_info->screen_base + *ppos;
start = (unsigned long)page_address(pages[0]);
end = (unsigned long)page_address(pages[nr_pages]);
len = nr_pages << PAGE_SHIFT;
if (start + len == end) {
if ((*ppos + len) > fb_info->fix.smem_len) {
ret = -ENOSPC;
goto out_unmap;
}
dma_write(shdma, start, 0, len);
dma_write(pvr2dma, 0, dst, len);
dma_wait_for_completion(pvr2dma);
goto out;
}
for (i = 0; i < nr_pages; i++, dst += PAGE_SIZE) {
if ((*ppos + (i << PAGE_SHIFT)) > fb_info->fix.smem_len) {
ret = -ENOSPC;
goto out_unmap;
}
dma_write_page(shdma, (unsigned long)page_address(pages[i]), 0);
dma_write_page(pvr2dma, 0, dst);
dma_wait_for_completion(pvr2dma);
}
out:
*ppos += count;
ret = count;
out_unmap:
for (i = 0; i < nr_pages; i++)
page_cache_release(pages[i]);
kfree(pages);
return ret;
}
static int pvr2fb_common_init(void)
{
struct pvr2fb_par *par = currentpar;
unsigned long modememused, rev;
fb_info->screen_base = ioremap_nocache(pvr2_fix.smem_start,
pvr2_fix.smem_len);
if (!fb_info->screen_base) {
printk(KERN_ERR "pvr2fb: Failed to remap smem space\n");
goto out_err;
}
par->mmio_base = (unsigned long)ioremap_nocache(pvr2_fix.mmio_start,
pvr2_fix.mmio_len);
if (!par->mmio_base) {
printk(KERN_ERR "pvr2fb: Failed to remap mmio space\n");
goto out_err;
}
fb_memset(fb_info->screen_base, 0, pvr2_fix.smem_len);
pvr2_fix.ypanstep = nopan ? 0 : 1;
pvr2_fix.ywrapstep = nowrap ? 0 : 1;
fb_info->fbops = &pvr2fb_ops;
fb_info->fix = pvr2_fix;
fb_info->par = currentpar;
fb_info->pseudo_palette = currentpar->palette;
fb_info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
if (video_output == VO_VGA)
defmode = DEFMODE_VGA;
if (!mode_option)
mode_option = "640x480@60";
if (!fb_find_mode(&fb_info->var, fb_info, mode_option, pvr2_modedb,
NUM_TOTAL_MODES, &pvr2_modedb[defmode], 16))
fb_info->var = pvr2_var;
fb_alloc_cmap(&fb_info->cmap, 256, 0);
if (register_framebuffer(fb_info) < 0)
goto out_err;
pvr2_init_display(fb_info);
modememused = get_line_length(fb_info->var.xres_virtual,
fb_info->var.bits_per_pixel);
modememused *= fb_info->var.yres_virtual;
rev = fb_readl(par->mmio_base + 0x04);
fb_info(fb_info, "%s (rev %ld.%ld) frame buffer device, using %ldk/%ldk of video memory\n",
fb_info->fix.id, (rev >> 4) & 0x0f, rev & 0x0f,
modememused >> 10,
(unsigned long)(fb_info->fix.smem_len >> 10));
fb_info(fb_info, "Mode %dx%d-%d pitch = %ld cable: %s video output: %s\n",
fb_info->var.xres, fb_info->var.yres,
fb_info->var.bits_per_pixel,
get_line_length(fb_info->var.xres, fb_info->var.bits_per_pixel),
(char *)pvr2_get_param(cables, NULL, cable_type, 3),
(char *)pvr2_get_param(outputs, NULL, video_output, 3));
#ifdef CONFIG_SH_STORE_QUEUES
fb_notice(fb_info, "registering with SQ API\n");
pvr2fb_map = sq_remap(fb_info->fix.smem_start, fb_info->fix.smem_len,
fb_info->fix.id, PAGE_SHARED);
fb_notice(fb_info, "Mapped video memory to SQ addr 0x%lx\n",
pvr2fb_map);
#endif
return 0;
out_err:
if (fb_info->screen_base)
iounmap(fb_info->screen_base);
if (par->mmio_base)
iounmap((void *)par->mmio_base);
return -ENXIO;
}
static int __init pvr2fb_dc_init(void)
{
if (!mach_is_dreamcast())
return -ENXIO;
if (pvr2_init_cable() == CT_VGA) {
fb_info->monspecs.hfmin = 30000;
fb_info->monspecs.hfmax = 70000;
fb_info->monspecs.vfmin = 60;
fb_info->monspecs.vfmax = 60;
} else {
fb_info->monspecs.hfmin = 15469;
fb_info->monspecs.hfmax = 15781;
fb_info->monspecs.vfmin = 49;
fb_info->monspecs.vfmax = 51;
}
if (video_output < 0) {
if (cable_type == CT_VGA) {
video_output = VO_VGA;
} else {
video_output = VO_NTSC;
}
}
pvr2_fix.smem_start = 0xa5000000;
pvr2_fix.smem_len = 8 << 20;
pvr2_fix.mmio_start = 0xa05f8000;
pvr2_fix.mmio_len = 0x2000;
if (request_irq(HW_EVENT_VSYNC, pvr2fb_interrupt, IRQF_SHARED,
"pvr2 VBL handler", fb_info)) {
return -EBUSY;
}
#ifdef CONFIG_PVR2_DMA
if (request_dma(pvr2dma, "pvr2") != 0) {
free_irq(HW_EVENT_VSYNC, fb_info);
return -EBUSY;
}
#endif
return pvr2fb_common_init();
}
static void __exit pvr2fb_dc_exit(void)
{
if (fb_info->screen_base) {
iounmap(fb_info->screen_base);
fb_info->screen_base = NULL;
}
if (currentpar->mmio_base) {
iounmap((void *)currentpar->mmio_base);
currentpar->mmio_base = 0;
}
free_irq(HW_EVENT_VSYNC, fb_info);
#ifdef CONFIG_PVR2_DMA
free_dma(pvr2dma);
#endif
}
static int pvr2fb_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int ret;
ret = pci_enable_device(pdev);
if (ret) {
printk(KERN_ERR "pvr2fb: PCI enable failed\n");
return ret;
}
ret = pci_request_regions(pdev, "pvr2fb");
if (ret) {
printk(KERN_ERR "pvr2fb: PCI request regions failed\n");
return ret;
}
pvr2_fix.smem_start = pci_resource_start(pdev, 0);
pvr2_fix.smem_len = pci_resource_len(pdev, 0);
pvr2_fix.mmio_start = pci_resource_start(pdev, 1);
pvr2_fix.mmio_len = pci_resource_len(pdev, 1);
fb_info->device = &pdev->dev;
return pvr2fb_common_init();
}
static void pvr2fb_pci_remove(struct pci_dev *pdev)
{
if (fb_info->screen_base) {
iounmap(fb_info->screen_base);
fb_info->screen_base = NULL;
}
if (currentpar->mmio_base) {
iounmap((void *)currentpar->mmio_base);
currentpar->mmio_base = 0;
}
pci_release_regions(pdev);
}
static int __init pvr2fb_pci_init(void)
{
return pci_register_driver(&pvr2fb_pci_driver);
}
static void __exit pvr2fb_pci_exit(void)
{
pci_unregister_driver(&pvr2fb_pci_driver);
}
static int pvr2_get_param(const struct pvr2_params *p, const char *s, int val,
int size)
{
int i;
for (i = 0 ; i < size ; i++ ) {
if (s != NULL) {
if (!strnicmp(p[i].name, s, strlen(s)))
return p[i].val;
} else {
if (p[i].val == val)
return (int)p[i].name;
}
}
return -1;
}
static int __init pvr2fb_setup(char *options)
{
char *this_opt;
char cable_arg[80];
char output_arg[80];
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ","))) {
if (!*this_opt)
continue;
if (!strcmp(this_opt, "inverse")) {
fb_invert_cmaps();
} else if (!strncmp(this_opt, "cable:", 6)) {
strcpy(cable_arg, this_opt + 6);
} else if (!strncmp(this_opt, "output:", 7)) {
strcpy(output_arg, this_opt + 7);
} else if (!strncmp(this_opt, "nopan", 5)) {
nopan = 1;
} else if (!strncmp(this_opt, "nowrap", 6)) {
nowrap = 1;
} else {
mode_option = this_opt;
}
}
if (*cable_arg)
cable_type = pvr2_get_param(cables, cable_arg, 0, 3);
if (*output_arg)
video_output = pvr2_get_param(outputs, output_arg, 0, 3);
return 0;
}
static int __init pvr2fb_init(void)
{
int i, ret = -ENODEV;
int size;
#ifndef MODULE
char *option = NULL;
if (fb_get_options("pvr2fb", &option))
return -ENODEV;
pvr2fb_setup(option);
#endif
size = sizeof(struct fb_info) + sizeof(struct pvr2fb_par) + 16 * sizeof(u32);
fb_info = framebuffer_alloc(sizeof(struct pvr2fb_par), NULL);
if (!fb_info) {
printk(KERN_ERR "Failed to allocate memory for fb_info\n");
return -ENOMEM;
}
currentpar = fb_info->par;
for (i = 0; i < ARRAY_SIZE(board_driver); i++) {
struct pvr2_board *pvr_board = board_driver + i;
if (!pvr_board->init)
continue;
ret = pvr_board->init();
if (ret != 0) {
printk(KERN_ERR "pvr2fb: Failed init of %s device\n",
pvr_board->name);
framebuffer_release(fb_info);
break;
}
}
return ret;
}
static void __exit pvr2fb_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(board_driver); i++) {
struct pvr2_board *pvr_board = board_driver + i;
if (pvr_board->exit)
pvr_board->exit();
}
#ifdef CONFIG_SH_STORE_QUEUES
sq_unmap(pvr2fb_map);
#endif
unregister_framebuffer(fb_info);
framebuffer_release(fb_info);
}
