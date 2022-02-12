static int chipsfb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
if (var->xres > 800 || var->yres > 600
|| var->xres_virtual > 800 || var->yres_virtual > 600
|| (var->bits_per_pixel != 8 && var->bits_per_pixel != 16)
|| var->nonstd
|| (var->vmode & FB_VMODE_MASK) != FB_VMODE_NONINTERLACED)
return -EINVAL;
var->xres = var->xres_virtual = 800;
var->yres = var->yres_virtual = 600;
return 0;
}
static int chipsfb_set_par(struct fb_info *info)
{
if (info->var.bits_per_pixel == 16) {
write_cr(0x13, 200);
write_xr(0x81, 0x14);
write_xr(0x82, 0x00);
write_xr(0x20, 0x10);
info->fix.line_length = 800*2;
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->var.red.offset = 10;
info->var.green.offset = 5;
info->var.blue.offset = 0;
info->var.red.length = info->var.green.length =
info->var.blue.length = 5;
} else {
write_cr(0x13, 100);
write_xr(0x81, 0x12);
write_xr(0x82, 0x08);
write_xr(0x20, 0x00);
info->fix.line_length = 800;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->var.red.offset = info->var.green.offset =
info->var.blue.offset = 0;
info->var.red.length = info->var.green.length =
info->var.blue.length = 8;
}
return 0;
}
static int chipsfb_blank(int blank, struct fb_info *info)
{
return 1;
}
static int chipsfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
if (regno > 255)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
outb(regno, 0x3c8);
udelay(1);
outb(red, 0x3c9);
outb(green, 0x3c9);
outb(blue, 0x3c9);
return 0;
}
static void __init chips_hw_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(chips_init_xr); ++i)
write_xr(chips_init_xr[i].addr, chips_init_xr[i].data);
outb(0x29, 0x3c2);
for (i = 0; i < ARRAY_SIZE(chips_init_sr); ++i)
write_sr(chips_init_sr[i].addr, chips_init_sr[i].data);
for (i = 0; i < ARRAY_SIZE(chips_init_gr); ++i)
write_gr(chips_init_gr[i].addr, chips_init_gr[i].data);
for (i = 0; i < ARRAY_SIZE(chips_init_ar); ++i)
write_ar(chips_init_ar[i].addr, chips_init_ar[i].data);
for (i = 0; i < ARRAY_SIZE(chips_init_cr); ++i)
write_cr(chips_init_cr[i].addr, chips_init_cr[i].data);
for (i = 0; i < ARRAY_SIZE(chips_init_fr); ++i)
write_fr(chips_init_fr[i].addr, chips_init_fr[i].data);
}
static void init_chips(struct fb_info *p, unsigned long addr)
{
memset(p->screen_base, 0, 0x100000);
p->fix = chipsfb_fix;
p->fix.smem_start = addr;
p->var = chipsfb_var;
p->fbops = &chipsfb_ops;
p->flags = FBINFO_DEFAULT;
fb_alloc_cmap(&p->cmap, 256, 0);
chips_hw_init();
}
static int chipsfb_pci_init(struct pci_dev *dp, const struct pci_device_id *ent)
{
struct fb_info *p;
unsigned long addr, size;
unsigned short cmd;
int rc = -ENODEV;
if (pci_enable_device(dp) < 0) {
dev_err(&dp->dev, "Cannot enable PCI device\n");
goto err_out;
}
if ((dp->resource[0].flags & IORESOURCE_MEM) == 0)
goto err_disable;
addr = pci_resource_start(dp, 0);
size = pci_resource_len(dp, 0);
if (addr == 0)
goto err_disable;
p = framebuffer_alloc(0, &dp->dev);
if (p == NULL) {
dev_err(&dp->dev, "Cannot allocate framebuffer structure\n");
rc = -ENOMEM;
goto err_disable;
}
if (pci_request_region(dp, 0, "chipsfb") != 0) {
dev_err(&dp->dev, "Cannot request framebuffer\n");
rc = -EBUSY;
goto err_release_fb;
}
#ifdef __BIG_ENDIAN
addr += 0x800000;
#endif
pci_read_config_word(dp, PCI_COMMAND, &cmd);
cmd |= 3;
pci_write_config_word(dp, PCI_COMMAND, cmd);
#ifdef CONFIG_PMAC_BACKLIGHT
mutex_lock(&pmac_backlight_mutex);
if (pmac_backlight) {
pmac_backlight->props.power = FB_BLANK_UNBLANK;
backlight_update_status(pmac_backlight);
}
mutex_unlock(&pmac_backlight_mutex);
#endif
#ifdef CONFIG_PPC
p->screen_base = __ioremap(addr, 0x200000, _PAGE_NO_CACHE);
#else
p->screen_base = ioremap(addr, 0x200000);
#endif
if (p->screen_base == NULL) {
dev_err(&dp->dev, "Cannot map framebuffer\n");
rc = -ENOMEM;
goto err_release_pci;
}
pci_set_drvdata(dp, p);
init_chips(p, addr);
if (register_framebuffer(p) < 0) {
dev_err(&dp->dev,"C&T 65550 framebuffer failed to register\n");
goto err_unmap;
}
dev_info(&dp->dev,"fb%d: Chips 65550 frame buffer"
" (%dK RAM detected)\n",
p->node, p->fix.smem_len / 1024);
return 0;
err_unmap:
iounmap(p->screen_base);
err_release_pci:
pci_release_region(dp, 0);
err_release_fb:
framebuffer_release(p);
err_disable:
err_out:
return rc;
}
static void chipsfb_remove(struct pci_dev *dp)
{
struct fb_info *p = pci_get_drvdata(dp);
if (p->screen_base == NULL)
return;
unregister_framebuffer(p);
iounmap(p->screen_base);
p->screen_base = NULL;
pci_release_region(dp, 0);
}
static int chipsfb_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct fb_info *p = pci_get_drvdata(pdev);
if (state.event == pdev->dev.power.power_state.event)
return 0;
if (!(state.event & PM_EVENT_SLEEP))
goto done;
console_lock();
chipsfb_blank(1, p);
fb_set_suspend(p, 1);
console_unlock();
done:
pdev->dev.power.power_state = state;
return 0;
}
static int chipsfb_pci_resume(struct pci_dev *pdev)
{
struct fb_info *p = pci_get_drvdata(pdev);
console_lock();
fb_set_suspend(p, 0);
chipsfb_blank(0, p);
console_unlock();
pdev->dev.power.power_state = PMSG_ON;
return 0;
}
int __init chips_init(void)
{
if (fb_get_options("chipsfb", NULL))
return -ENODEV;
return pci_register_driver(&chipsfb_driver);
}
static void __exit chipsfb_exit(void)
{
pci_unregister_driver(&chipsfb_driver);
}
