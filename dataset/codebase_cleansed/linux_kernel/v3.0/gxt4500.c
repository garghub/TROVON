static int calc_pll(int period_ps, struct gxt4500_par *par)
{
int m, n, pdiv1, pdiv2, postdiv;
int pll_period, best_error, t, intf;
if (period_ps < 3333 || period_ps > 200000)
return -1;
best_error = 1000000;
for (pdiv1 = 1; pdiv1 <= 8; ++pdiv1) {
for (pdiv2 = 1; pdiv2 <= pdiv1; ++pdiv2) {
postdiv = pdiv1 * pdiv2;
pll_period = DIV_ROUND_UP(period_ps, postdiv);
if (pll_period < 1666 || pll_period > 2857)
continue;
for (m = 1; m <= 64; ++m) {
intf = m * par->refclk_ps;
if (intf > 500000)
break;
n = intf * postdiv / period_ps;
if (n < 3 || n > 160)
continue;
t = par->refclk_ps * m * postdiv / n;
t -= period_ps;
if (t >= 0 && t < best_error) {
par->pll_m = m;
par->pll_n = n;
par->pll_pd1 = pdiv1;
par->pll_pd2 = pdiv2;
best_error = t;
}
}
}
}
if (best_error == 1000000)
return -1;
return 0;
}
static int calc_pixclock(struct gxt4500_par *par)
{
return par->refclk_ps * par->pll_m * par->pll_pd1 * par->pll_pd2
/ par->pll_n;
}
static int gxt4500_var_to_par(struct fb_var_screeninfo *var,
struct gxt4500_par *par)
{
if (var->xres + var->xoffset > var->xres_virtual ||
var->yres + var->yoffset > var->yres_virtual ||
var->xres_virtual > 4096)
return -EINVAL;
if ((var->vmode & FB_VMODE_MASK) != FB_VMODE_NONINTERLACED)
return -EINVAL;
if (calc_pll(var->pixclock, par) < 0)
return -EINVAL;
switch (var->bits_per_pixel) {
case 32:
if (var->transp.length)
par->pixfmt = DFA_PIX_32BIT;
else
par->pixfmt = DFA_PIX_24BIT;
break;
case 24:
par->pixfmt = DFA_PIX_24BIT;
break;
case 16:
if (var->green.length == 5)
par->pixfmt = DFA_PIX_16BIT_1555;
else
par->pixfmt = DFA_PIX_16BIT_565;
break;
case 8:
par->pixfmt = DFA_PIX_8BIT;
break;
default:
return -EINVAL;
}
return 0;
}
static void gxt4500_unpack_pixfmt(struct fb_var_screeninfo *var,
int pixfmt)
{
var->bits_per_pixel = pixsize[pixfmt] * 8;
var->red = eightbits;
var->green = eightbits;
var->blue = eightbits;
var->transp = nobits;
switch (pixfmt) {
case DFA_PIX_16BIT_565:
var->red.length = 5;
var->green.length = 6;
var->blue.length = 5;
break;
case DFA_PIX_16BIT_1555:
var->red.length = 5;
var->green.length = 5;
var->blue.length = 5;
var->transp.length = 1;
break;
case DFA_PIX_32BIT:
var->transp.length = 8;
break;
}
if (pixfmt != DFA_PIX_8BIT) {
var->green.offset = var->red.length;
var->blue.offset = var->green.offset + var->green.length;
if (var->transp.length)
var->transp.offset =
var->blue.offset + var->blue.length;
}
}
static int gxt4500_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct gxt4500_par par;
int err;
par = *(struct gxt4500_par *)info->par;
err = gxt4500_var_to_par(var, &par);
if (!err) {
var->pixclock = calc_pixclock(&par);
gxt4500_unpack_pixfmt(var, par.pixfmt);
}
return err;
}
static int gxt4500_set_par(struct fb_info *info)
{
struct gxt4500_par *par = info->par;
struct fb_var_screeninfo *var = &info->var;
int err;
u32 ctrlreg, tmp;
unsigned int dfa_ctl, pixfmt, stride;
unsigned int wid_tiles, i;
unsigned int prefetch_pix, htot;
struct gxt4500_par save_par;
save_par = *par;
err = gxt4500_var_to_par(var, par);
if (err) {
*par = save_par;
return err;
}
ctrlreg = readreg(par, DTG_CONTROL);
ctrlreg &= ~(DTG_CTL_ENABLE | DTG_CTL_SCREEN_REFRESH);
writereg(par, DTG_CONTROL, ctrlreg);
tmp = readreg(par, PLL_C) & ~0x7f;
if (par->pll_n < 38)
tmp |= 0x29;
if (par->pll_n < 69)
tmp |= 0x35;
else if (par->pll_n < 100)
tmp |= 0x76;
else
tmp |= 0x7e;
writereg(par, PLL_C, tmp);
writereg(par, PLL_M, mdivtab[par->pll_m - 1]);
writereg(par, PLL_N, ndivtab[par->pll_n - 2]);
tmp = ((8 - par->pll_pd2) << 3) | (8 - par->pll_pd1);
if (par->pll_pd1 == 8 || par->pll_pd2 == 8) {
writereg(par, PLL_POSTDIV, tmp | 0x9);
udelay(1);
}
writereg(par, PLL_POSTDIV, tmp);
msleep(20);
writereg(par, CURSOR_MODE, CURSOR_MODE_OFF);
writereg(par, CTRL_REG0, CR0_RASTER_RESET | (CR0_RASTER_RESET << 16));
udelay(10);
writereg(par, CTRL_REG0, CR0_RASTER_RESET << 16);
htot = var->xres + var->left_margin + var->right_margin +
var->hsync_len;
writereg(par, DTG_HORIZ_EXTENT, htot - 1);
writereg(par, DTG_HORIZ_DISPLAY, var->xres - 1);
writereg(par, DTG_HSYNC_START, var->xres + var->right_margin - 1);
writereg(par, DTG_HSYNC_END,
var->xres + var->right_margin + var->hsync_len - 1);
writereg(par, DTG_HSYNC_END_COMP,
var->xres + var->right_margin + var->hsync_len - 1);
writereg(par, DTG_VERT_EXTENT,
var->yres + var->upper_margin + var->lower_margin +
var->vsync_len - 1);
writereg(par, DTG_VERT_DISPLAY, var->yres - 1);
writereg(par, DTG_VSYNC_START, var->yres + var->lower_margin - 1);
writereg(par, DTG_VSYNC_END,
var->yres + var->lower_margin + var->vsync_len - 1);
prefetch_pix = 3300000 / var->pixclock;
if (prefetch_pix >= htot)
prefetch_pix = htot - 1;
writereg(par, DTG_VERT_SHORT, htot - prefetch_pix - 1);
ctrlreg |= DTG_CTL_ENABLE | DTG_CTL_SCREEN_REFRESH;
writereg(par, DTG_CONTROL, ctrlreg);
if (var->xres_virtual > 2048) {
stride = 4096;
dfa_ctl = DFA_FB_STRIDE_4k;
} else if (var->xres_virtual > 1024) {
stride = 2048;
dfa_ctl = DFA_FB_STRIDE_2k;
} else {
stride = 1024;
dfa_ctl = DFA_FB_STRIDE_1k;
}
wid_tiles = (var->xres_virtual + 63) >> 6;
writereg(par, FB_AB_CTRL, FB_CTRL_TYPE | (wid_tiles << 16) | 0);
writereg(par, REFRESH_AB_CTRL, FB_CTRL_TYPE | (wid_tiles << 16) | 0);
writereg(par, FB_CD_CTRL, FB_CTRL_TYPE | (wid_tiles << 16) | 0);
writereg(par, REFRESH_CD_CTRL, FB_CTRL_TYPE | (wid_tiles << 16) | 0);
writereg(par, REFRESH_START, (var->xoffset << 16) | var->yoffset);
writereg(par, REFRESH_SIZE, (var->xres << 16) | var->yres);
pixfmt = par->pixfmt;
dfa_ctl |= DFA_FB_ENABLE | pixfmt;
writereg(par, DFA_FB_A, dfa_ctl);
for (i = 0; i < 32; ++i) {
writereg(par, WAT_FMT + (i << 4), watfmt[pixfmt]);
writereg(par, WAT_CMAP_OFFSET + (i << 4), 0);
writereg(par, WAT_CTRL + (i << 4), 0);
writereg(par, WAT_GAMMA_CTRL + (i << 4), WAT_GAMMA_DISABLE);
}
ctrlreg = readreg(par, SYNC_CTL) &
~(SYNC_CTL_SYNC_ON_RGB | SYNC_CTL_HSYNC_INV |
SYNC_CTL_VSYNC_INV);
if (var->sync & FB_SYNC_ON_GREEN)
ctrlreg |= SYNC_CTL_SYNC_ON_RGB;
if (!(var->sync & FB_SYNC_HOR_HIGH_ACT))
ctrlreg |= SYNC_CTL_HSYNC_INV;
if (!(var->sync & FB_SYNC_VERT_HIGH_ACT))
ctrlreg |= SYNC_CTL_VSYNC_INV;
writereg(par, SYNC_CTL, ctrlreg);
info->fix.line_length = stride * pixsize[pixfmt];
info->fix.visual = (pixfmt == DFA_PIX_8BIT)? FB_VISUAL_PSEUDOCOLOR:
FB_VISUAL_DIRECTCOLOR;
return 0;
}
static int gxt4500_setcolreg(unsigned int reg, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
u32 cmap_entry;
struct gxt4500_par *par = info->par;
if (reg > 1023)
return 1;
cmap_entry = ((transp & 0xff00) << 16) | ((red & 0xff00) << 8) |
(green & 0xff00) | (blue >> 8);
writereg(par, CMAP + reg * 4, cmap_entry);
if (reg < 16 && par->pixfmt != DFA_PIX_8BIT) {
u32 *pal = info->pseudo_palette;
u32 val = reg;
switch (par->pixfmt) {
case DFA_PIX_16BIT_565:
val |= (reg << 11) | (reg << 6);
break;
case DFA_PIX_16BIT_1555:
val |= (reg << 10) | (reg << 5);
break;
case DFA_PIX_32BIT:
val |= (reg << 24);
case DFA_PIX_24BIT:
val |= (reg << 16) | (reg << 8);
break;
}
pal[reg] = val;
}
return 0;
}
static int gxt4500_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct gxt4500_par *par = info->par;
if (var->xoffset & 7)
return -EINVAL;
if (var->xoffset + var->xres > var->xres_virtual ||
var->yoffset + var->yres > var->yres_virtual)
return -EINVAL;
writereg(par, REFRESH_START, (var->xoffset << 16) | var->yoffset);
return 0;
}
static int gxt4500_blank(int blank, struct fb_info *info)
{
struct gxt4500_par *par = info->par;
int ctrl, dctl;
ctrl = readreg(par, SYNC_CTL);
ctrl &= ~(SYNC_CTL_SYNC_OFF | SYNC_CTL_HSYNC_OFF | SYNC_CTL_VSYNC_OFF);
dctl = readreg(par, DISP_CTL);
dctl |= DISP_CTL_OFF;
switch (blank) {
case FB_BLANK_UNBLANK:
dctl &= ~DISP_CTL_OFF;
break;
case FB_BLANK_POWERDOWN:
ctrl |= SYNC_CTL_SYNC_OFF;
break;
case FB_BLANK_HSYNC_SUSPEND:
ctrl |= SYNC_CTL_HSYNC_OFF;
break;
case FB_BLANK_VSYNC_SUSPEND:
ctrl |= SYNC_CTL_VSYNC_OFF;
break;
default: ;
}
writereg(par, SYNC_CTL, ctrl);
writereg(par, DISP_CTL, dctl);
return 0;
}
static int __devinit gxt4500_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err;
unsigned long reg_phys, fb_phys;
struct gxt4500_par *par;
struct fb_info *info;
struct fb_var_screeninfo var;
enum gxt_cards cardtype;
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "gxt4500: cannot enable PCI device: %d\n",
err);
return err;
}
reg_phys = pci_resource_start(pdev, 0);
if (!request_mem_region(reg_phys, pci_resource_len(pdev, 0),
"gxt4500 regs")) {
dev_err(&pdev->dev, "gxt4500: cannot get registers\n");
goto err_nodev;
}
fb_phys = pci_resource_start(pdev, 1);
if (!request_mem_region(fb_phys, pci_resource_len(pdev, 1),
"gxt4500 FB")) {
dev_err(&pdev->dev, "gxt4500: cannot get framebuffer\n");
goto err_free_regs;
}
info = framebuffer_alloc(sizeof(struct gxt4500_par), &pdev->dev);
if (!info) {
dev_err(&pdev->dev, "gxt4500: cannot alloc FB info record\n");
goto err_free_fb;
}
par = info->par;
cardtype = ent->driver_data;
par->refclk_ps = cardinfo[cardtype].refclk_ps;
info->fix = gxt4500_fix;
strlcpy(info->fix.id, cardinfo[cardtype].cardname,
sizeof(info->fix.id));
info->pseudo_palette = par->pseudo_palette;
info->fix.mmio_start = reg_phys;
par->regs = pci_ioremap_bar(pdev, 0);
if (!par->regs) {
dev_err(&pdev->dev, "gxt4500: cannot map registers\n");
goto err_free_all;
}
info->fix.smem_start = fb_phys;
info->fix.smem_len = pci_resource_len(pdev, 1);
info->screen_base = pci_ioremap_bar(pdev, 1);
if (!info->screen_base) {
dev_err(&pdev->dev, "gxt4500: cannot map framebuffer\n");
goto err_unmap_regs;
}
pci_set_drvdata(pdev, info);
pci_write_config_dword(pdev, CFG_ENDIAN0, 0x333300);
info->fbops = &gxt4500_ops;
info->flags = FBINFO_FLAG_DEFAULT;
err = fb_alloc_cmap(&info->cmap, 256, 0);
if (err) {
dev_err(&pdev->dev, "gxt4500: cannot allocate cmap\n");
goto err_unmap_all;
}
gxt4500_blank(FB_BLANK_UNBLANK, info);
if (!fb_find_mode(&var, info, mode_option, NULL, 0, &defaultmode, 8)) {
dev_err(&pdev->dev, "gxt4500: cannot find valid video mode\n");
goto err_free_cmap;
}
info->var = var;
if (gxt4500_set_par(info)) {
printk(KERN_ERR "gxt4500: cannot set video mode\n");
goto err_free_cmap;
}
if (register_framebuffer(info) < 0) {
dev_err(&pdev->dev, "gxt4500: cannot register framebuffer\n");
goto err_free_cmap;
}
printk(KERN_INFO "fb%d: %s frame buffer device\n",
info->node, info->fix.id);
return 0;
err_free_cmap:
fb_dealloc_cmap(&info->cmap);
err_unmap_all:
iounmap(info->screen_base);
err_unmap_regs:
iounmap(par->regs);
err_free_all:
framebuffer_release(info);
err_free_fb:
release_mem_region(fb_phys, pci_resource_len(pdev, 1));
err_free_regs:
release_mem_region(reg_phys, pci_resource_len(pdev, 0));
err_nodev:
return -ENODEV;
}
static void __devexit gxt4500_remove(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct gxt4500_par *par;
if (!info)
return;
par = info->par;
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
iounmap(par->regs);
iounmap(info->screen_base);
release_mem_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
release_mem_region(pci_resource_start(pdev, 1),
pci_resource_len(pdev, 1));
framebuffer_release(info);
}
static int __devinit gxt4500_init(void)
{
#ifndef MODULE
if (fb_get_options("gxt4500", &mode_option))
return -ENODEV;
#endif
return pci_register_driver(&gxt4500_driver);
}
static void __exit gxt4500_exit(void)
{
pci_unregister_driver(&gxt4500_driver);
}
