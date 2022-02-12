static void get_modedb(struct fb_videomode **modedb, unsigned int *size)
{
if (olpc_has_dcon()) {
*modedb = (struct fb_videomode *) olpc_dcon_modedb;
*size = ARRAY_SIZE(olpc_dcon_modedb);
} else {
*modedb = (struct fb_videomode *) geode_modedb;
*size = ARRAY_SIZE(geode_modedb);
}
}
static void get_modedb(struct fb_videomode **modedb, unsigned int *size)
{
*modedb = (struct fb_videomode *) geode_modedb;
*size = ARRAY_SIZE(geode_modedb);
}
static int lxfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
if (var->xres > 1920 || var->yres > 1440)
return -EINVAL;
if (var->bits_per_pixel == 32) {
var->red.offset = 16; var->red.length = 8;
var->green.offset = 8; var->green.length = 8;
var->blue.offset = 0; var->blue.length = 8;
} else if (var->bits_per_pixel == 16) {
var->red.offset = 11; var->red.length = 5;
var->green.offset = 5; var->green.length = 6;
var->blue.offset = 0; var->blue.length = 5;
} else if (var->bits_per_pixel == 8) {
var->red.offset = 0; var->red.length = 8;
var->green.offset = 0; var->green.length = 8;
var->blue.offset = 0; var->blue.length = 8;
} else
return -EINVAL;
var->transp.offset = 0; var->transp.length = 0;
if ((lx_get_pitch(var->xres, var->bits_per_pixel) * var->yres)
> info->fix.smem_len)
return -EINVAL;
return 0;
}
static int lxfb_set_par(struct fb_info *info)
{
if (info->var.bits_per_pixel > 8)
info->fix.visual = FB_VISUAL_TRUECOLOR;
else
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.line_length = lx_get_pitch(info->var.xres,
info->var.bits_per_pixel);
lx_set_mode(info);
return 0;
}
static inline u_int chan_to_field(u_int chan, struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int lxfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
if (info->var.grayscale) {
red = green = blue = (red * 77 + green * 151 + blue * 28) >> 8;
}
if (info->fix.visual == FB_VISUAL_TRUECOLOR) {
u32 *pal = info->pseudo_palette;
u32 v;
if (regno >= 16)
return -EINVAL;
v = chan_to_field(red, &info->var.red);
v |= chan_to_field(green, &info->var.green);
v |= chan_to_field(blue, &info->var.blue);
pal[regno] = v;
} else {
if (regno >= 256)
return -EINVAL;
lx_set_palette_reg(info, regno, red, green, blue);
}
return 0;
}
static int lxfb_blank(int blank_mode, struct fb_info *info)
{
return lx_blank_display(info, blank_mode);
}
static int lxfb_map_video_memory(struct fb_info *info, struct pci_dev *dev)
{
struct lxfb_par *par = info->par;
int ret;
ret = pci_enable_device(dev);
if (ret)
return ret;
ret = pci_request_region(dev, 0, "lxfb-framebuffer");
if (ret)
return ret;
ret = pci_request_region(dev, 1, "lxfb-gp");
if (ret)
return ret;
ret = pci_request_region(dev, 2, "lxfb-vg");
if (ret)
return ret;
ret = pci_request_region(dev, 3, "lxfb-vp");
if (ret)
return ret;
info->fix.smem_start = pci_resource_start(dev, 0);
info->fix.smem_len = vram ? vram : lx_framebuffer_size();
info->screen_base = ioremap(info->fix.smem_start, info->fix.smem_len);
ret = -ENOMEM;
if (info->screen_base == NULL)
return ret;
par->gp_regs = pci_ioremap_bar(dev, 1);
if (par->gp_regs == NULL)
return ret;
par->dc_regs = pci_ioremap_bar(dev, 2);
if (par->dc_regs == NULL)
return ret;
par->vp_regs = pci_ioremap_bar(dev, 3);
if (par->vp_regs == NULL)
return ret;
write_dc(par, DC_UNLOCK, DC_UNLOCK_UNLOCK);
write_dc(par, DC_GLIU0_MEM_OFFSET, info->fix.smem_start & 0xFF000000);
write_dc(par, DC_UNLOCK, DC_UNLOCK_LOCK);
dev_info(&dev->dev, "%d KB of video memory at 0x%lx\n",
info->fix.smem_len / 1024, info->fix.smem_start);
return 0;
}
static struct fb_info *lxfb_init_fbinfo(struct device *dev)
{
struct lxfb_par *par;
struct fb_info *info;
info = framebuffer_alloc(sizeof(struct lxfb_par) + sizeof(u32) * 16,
dev);
if (!info)
return NULL;
par = info->par;
strcpy(info->fix.id, "Geode LX");
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.type_aux = 0;
info->fix.xpanstep = 0;
info->fix.ypanstep = 0;
info->fix.ywrapstep = 0;
info->fix.accel = FB_ACCEL_NONE;
info->var.nonstd = 0;
info->var.activate = FB_ACTIVATE_NOW;
info->var.height = -1;
info->var.width = -1;
info->var.accel_flags = 0;
info->var.vmode = FB_VMODE_NONINTERLACED;
info->fbops = &lxfb_ops;
info->flags = FBINFO_DEFAULT;
info->node = -1;
info->pseudo_palette = (void *)par + sizeof(struct lxfb_par);
if (fb_alloc_cmap(&info->cmap, 256, 0) < 0) {
framebuffer_release(info);
return NULL;
}
info->var.grayscale = 0;
return info;
}
static int lxfb_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct fb_info *info = pci_get_drvdata(pdev);
if (state.event == PM_EVENT_SUSPEND) {
console_lock();
lx_powerdown(info);
fb_set_suspend(info, 1);
console_unlock();
}
return 0;
}
static int lxfb_resume(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
int ret;
console_lock();
ret = lx_powerup(info);
if (ret) {
printk(KERN_ERR "lxfb: power up failed!\n");
return ret;
}
fb_set_suspend(info, 0);
console_unlock();
return 0;
}
static int lxfb_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct lxfb_par *par;
struct fb_info *info;
int ret;
struct fb_videomode *modedb_ptr;
unsigned int modedb_size;
info = lxfb_init_fbinfo(&pdev->dev);
if (info == NULL)
return -ENOMEM;
par = info->par;
ret = lxfb_map_video_memory(info, pdev);
if (ret < 0) {
dev_err(&pdev->dev,
"failed to map frame buffer or controller registers\n");
goto err;
}
par->output = 0;
par->output |= (nopanel) ? 0 : OUTPUT_PANEL;
par->output |= (nocrt) ? 0 : OUTPUT_CRT;
get_modedb(&modedb_ptr, &modedb_size);
ret = fb_find_mode(&info->var, info, mode_option,
modedb_ptr, modedb_size, NULL, 16);
if (ret == 0 || ret == 4) {
dev_err(&pdev->dev, "could not find valid video mode\n");
ret = -EINVAL;
goto err;
}
if (!noclear)
memset_io(info->screen_base, 0, info->fix.smem_len);
lxfb_check_var(&info->var, info);
lxfb_set_par(info);
pm_set_vt_switch(vt_switch);
if (register_framebuffer(info) < 0) {
ret = -EINVAL;
goto err;
}
pci_set_drvdata(pdev, info);
fb_info(info, "%s frame buffer device\n", info->fix.id);
return 0;
err:
if (info->screen_base) {
iounmap(info->screen_base);
pci_release_region(pdev, 0);
}
if (par->gp_regs) {
iounmap(par->gp_regs);
pci_release_region(pdev, 1);
}
if (par->dc_regs) {
iounmap(par->dc_regs);
pci_release_region(pdev, 2);
}
if (par->vp_regs) {
iounmap(par->vp_regs);
pci_release_region(pdev, 3);
}
if (info) {
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
return ret;
}
static void lxfb_remove(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct lxfb_par *par = info->par;
unregister_framebuffer(info);
iounmap(info->screen_base);
pci_release_region(pdev, 0);
iounmap(par->gp_regs);
pci_release_region(pdev, 1);
iounmap(par->dc_regs);
pci_release_region(pdev, 2);
iounmap(par->vp_regs);
pci_release_region(pdev, 3);
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
static int __init lxfb_setup(char *options)
{
char *opt;
if (!options || !*options)
return 0;
while ((opt = strsep(&options, ",")) != NULL) {
if (!*opt)
continue;
if (!strcmp(opt, "noclear"))
noclear = 1;
else if (!strcmp(opt, "nopanel"))
nopanel = 1;
else if (!strcmp(opt, "nocrt"))
nocrt = 1;
else
mode_option = opt;
}
return 0;
}
static int __init lxfb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("lxfb", &option))
return -ENODEV;
lxfb_setup(option);
#endif
return pci_register_driver(&lxfb_driver);
}
static void __exit lxfb_cleanup(void)
{
pci_unregister_driver(&lxfb_driver);
}
