static int platinumfb_check_var (struct fb_var_screeninfo *var, struct fb_info *info)
{
return platinum_var_to_par(var, info->par, 1);
}
static int platinumfb_set_par (struct fb_info *info)
{
struct fb_info_platinum *pinfo = info->par;
struct platinum_regvals *init;
int err, offset = 0x20;
if((err = platinum_var_to_par(&info->var, pinfo, 0))) {
printk (KERN_ERR "platinumfb_set_par: error calling"
" platinum_var_to_par: %d.\n", err);
return err;
}
platinum_set_hardware(pinfo);
init = platinum_reg_init[pinfo->vmode-1];
if ((pinfo->vmode == VMODE_832_624_75) && (pinfo->cmode > CMODE_8))
offset = 0x10;
info->screen_base = pinfo->frame_buffer + init->fb_offset + offset;
mutex_lock(&info->mm_lock);
info->fix.smem_start = (pinfo->frame_buffer_phys) + init->fb_offset + offset;
mutex_unlock(&info->mm_lock);
info->fix.visual = (pinfo->cmode == CMODE_8) ?
FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_DIRECTCOLOR;
info->fix.line_length = vmode_attrs[pinfo->vmode-1].hres * (1<<pinfo->cmode)
+ offset;
printk("line_length: %x\n", info->fix.line_length);
return 0;
}
static int platinumfb_blank(int blank, struct fb_info *fb)
{
return 0;
}
static int platinumfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct fb_info_platinum *pinfo = info->par;
volatile struct cmap_regs __iomem *cmap_regs = pinfo->cmap_regs;
if (regno > 255)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
pinfo->palette[regno].red = red;
pinfo->palette[regno].green = green;
pinfo->palette[regno].blue = blue;
out_8(&cmap_regs->addr, regno);
out_8(&cmap_regs->lut, red);
out_8(&cmap_regs->lut, green);
out_8(&cmap_regs->lut, blue);
if (regno < 16) {
int i;
u32 *pal = info->pseudo_palette;
switch (pinfo->cmode) {
case CMODE_16:
pal[regno] = (regno << 10) | (regno << 5) | regno;
break;
case CMODE_32:
i = (regno << 8) | regno;
pal[regno] = (i << 16) | i;
break;
}
}
return 0;
}
static inline int platinum_vram_reqd(int video_mode, int color_mode)
{
int baseval = vmode_attrs[video_mode-1].hres * (1<<color_mode);
if ((video_mode == VMODE_832_624_75) && (color_mode > CMODE_8))
baseval += 0x10;
else
baseval += 0x20;
return vmode_attrs[video_mode-1].vres * baseval + 0x1000;
}
static void set_platinum_clock(struct fb_info_platinum *pinfo)
{
volatile struct cmap_regs __iomem *cmap_regs = pinfo->cmap_regs;
struct platinum_regvals *init;
init = platinum_reg_init[pinfo->vmode-1];
STORE_D2(6, 0xc6);
out_8(&cmap_regs->addr,3+32);
if (in_8(&cmap_regs->d2) == 2) {
STORE_D2(7, init->clock_params[pinfo->clktype][0]);
STORE_D2(8, init->clock_params[pinfo->clktype][1]);
STORE_D2(3, 3);
} else {
STORE_D2(4, init->clock_params[pinfo->clktype][0]);
STORE_D2(5, init->clock_params[pinfo->clktype][1]);
STORE_D2(3, 2);
}
__delay(5000);
STORE_D2(9, 0xa6);
}
static void platinum_set_hardware(struct fb_info_platinum *pinfo)
{
volatile struct platinum_regs __iomem *platinum_regs = pinfo->platinum_regs;
volatile struct cmap_regs __iomem *cmap_regs = pinfo->cmap_regs;
struct platinum_regvals *init;
int i;
int vmode, cmode;
vmode = pinfo->vmode;
cmode = pinfo->cmode;
init = platinum_reg_init[vmode - 1];
out_be32(&platinum_regs->reg[24].r, 7);
for (i = 0; i < 26; ++i)
out_be32(&platinum_regs->reg[i+32].r, init->regs[i]);
out_be32(&platinum_regs->reg[26+32].r, (pinfo->total_vram == 0x100000 ?
init->offset[cmode] + 4 - cmode :
init->offset[cmode]));
out_be32(&platinum_regs->reg[16].r, (unsigned) pinfo->frame_buffer_phys+init->fb_offset+0x10);
out_be32(&platinum_regs->reg[18].r, init->pitch[cmode]);
out_be32(&platinum_regs->reg[19].r, (pinfo->total_vram == 0x100000 ?
init->mode[cmode+1] :
init->mode[cmode]));
out_be32(&platinum_regs->reg[20].r, (pinfo->total_vram == 0x100000 ? 0x11 : 0x1011));
out_be32(&platinum_regs->reg[21].r, 0x100);
out_be32(&platinum_regs->reg[22].r, 1);
out_be32(&platinum_regs->reg[23].r, 1);
out_be32(&platinum_regs->reg[26].r, 0xc00);
out_be32(&platinum_regs->reg[27].r, 0x235);
STORE_D2(0, (pinfo->total_vram == 0x100000 ?
init->dacula_ctrl[cmode] & 0xf :
init->dacula_ctrl[cmode]));
STORE_D2(1, 4);
STORE_D2(2, 0);
set_platinum_clock(pinfo);
out_be32(&platinum_regs->reg[24].r, 0);
}
static void __devinit platinum_init_info(struct fb_info *info, struct fb_info_platinum *pinfo)
{
info->fbops = &platinumfb_ops;
info->pseudo_palette = pinfo->pseudo_palette;
info->flags = FBINFO_DEFAULT;
info->screen_base = pinfo->frame_buffer + 0x20;
fb_alloc_cmap(&info->cmap, 256, 0);
strcpy(info->fix.id, "platinum");
info->fix.mmio_start = pinfo->platinum_regs_phys;
info->fix.mmio_len = 0x1000;
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.smem_start = pinfo->frame_buffer_phys + 0x20;
info->fix.smem_len = pinfo->total_vram - 0x20;
info->fix.ywrapstep = 0;
info->fix.xpanstep = 0;
info->fix.ypanstep = 0;
info->fix.type_aux = 0;
info->fix.accel = FB_ACCEL_NONE;
}
static int __devinit platinum_init_fb(struct fb_info *info)
{
struct fb_info_platinum *pinfo = info->par;
struct fb_var_screeninfo var;
int sense, rc;
sense = read_platinum_sense(pinfo);
printk(KERN_INFO "platinumfb: Monitor sense value = 0x%x, ", sense);
if (default_vmode == VMODE_NVRAM) {
#ifdef CONFIG_NVRAM
default_vmode = nvram_read_byte(NV_VMODE);
if (default_vmode <= 0 || default_vmode > VMODE_MAX ||
!platinum_reg_init[default_vmode-1])
#endif
default_vmode = VMODE_CHOOSE;
}
if (default_vmode == VMODE_CHOOSE) {
default_vmode = mac_map_monitor_sense(sense);
}
if (default_vmode <= 0 || default_vmode > VMODE_MAX)
default_vmode = VMODE_640_480_60;
#ifdef CONFIG_NVRAM
if (default_cmode == CMODE_NVRAM)
default_cmode = nvram_read_byte(NV_CMODE);
#endif
if (default_cmode < CMODE_8 || default_cmode > CMODE_32)
default_cmode = CMODE_8;
while(default_cmode > CMODE_8 &&
platinum_vram_reqd(default_vmode, default_cmode) > pinfo->total_vram)
default_cmode--;
printk("platinumfb: Using video mode %d and color mode %d.\n", default_vmode, default_cmode);
if (mac_vmode_to_var(default_vmode, default_cmode, &var) < 0) {
printk("mac_vmode_to_var(%d, %d,) failed\n", default_vmode, default_cmode);
try_again:
default_vmode = VMODE_640_480_60;
default_cmode = CMODE_8;
if (mac_vmode_to_var(default_vmode, default_cmode, &var) < 0) {
printk(KERN_ERR "platinumfb: mac_vmode_to_var() failed\n");
return -ENXIO;
}
}
platinum_init_info(info, pinfo);
info->var = var;
var.activate = FB_ACTIVATE_NOW;
rc = fb_set_var(info, &var);
if (rc && (default_vmode != VMODE_640_480_60 || default_cmode != CMODE_8))
goto try_again;
rc = register_framebuffer(info);
if (rc < 0)
return rc;
printk(KERN_INFO "fb%d: Apple Platinum frame buffer device\n", info->node);
return 0;
}
static int read_platinum_sense(struct fb_info_platinum *info)
{
volatile struct platinum_regs __iomem *platinum_regs = info->platinum_regs;
int sense;
out_be32(&platinum_regs->reg[23].r, 7);
__delay(2000);
sense = (~in_be32(&platinum_regs->reg[23].r) & 7) << 8;
out_be32(&platinum_regs->reg[23].r, 3);
__delay(2000);
sense |= (~in_be32(&platinum_regs->reg[23].r) & 3) << 4;
out_be32(&platinum_regs->reg[23].r, 5);
__delay(2000);
sense |= (~in_be32(&platinum_regs->reg[23].r) & 4) << 1;
sense |= (~in_be32(&platinum_regs->reg[23].r) & 1) << 2;
out_be32(&platinum_regs->reg[23].r, 6);
__delay(2000);
sense |= (~in_be32(&platinum_regs->reg[23].r) & 6) >> 1;
out_be32(&platinum_regs->reg[23].r, 7);
return sense;
}
static int platinum_var_to_par(struct fb_var_screeninfo *var,
struct fb_info_platinum *pinfo,
int check_only)
{
int vmode, cmode;
if (mac_var_to_vmode(var, &vmode, &cmode) != 0) {
printk(KERN_ERR "platinum_var_to_par: mac_var_to_vmode unsuccessful.\n");
printk(KERN_ERR "platinum_var_to_par: var->xres = %d\n", var->xres);
printk(KERN_ERR "platinum_var_to_par: var->yres = %d\n", var->yres);
printk(KERN_ERR "platinum_var_to_par: var->xres_virtual = %d\n", var->xres_virtual);
printk(KERN_ERR "platinum_var_to_par: var->yres_virtual = %d\n", var->yres_virtual);
printk(KERN_ERR "platinum_var_to_par: var->bits_per_pixel = %d\n", var->bits_per_pixel);
printk(KERN_ERR "platinum_var_to_par: var->pixclock = %d\n", var->pixclock);
printk(KERN_ERR "platinum_var_to_par: var->vmode = %d\n", var->vmode);
return -EINVAL;
}
if (!platinum_reg_init[vmode-1]) {
printk(KERN_ERR "platinum_var_to_par, vmode %d not valid.\n", vmode);
return -EINVAL;
}
if (platinum_vram_reqd(vmode, cmode) > pinfo->total_vram) {
printk(KERN_ERR "platinum_var_to_par, not enough ram for vmode %d, cmode %d.\n", vmode, cmode);
return -EINVAL;
}
if (mac_vmode_to_var(vmode, cmode, var))
return -EINVAL;
if (check_only)
return 0;
pinfo->vmode = vmode;
pinfo->cmode = cmode;
pinfo->xres = vmode_attrs[vmode-1].hres;
pinfo->yres = vmode_attrs[vmode-1].vres;
pinfo->xoffset = 0;
pinfo->yoffset = 0;
pinfo->vxres = pinfo->xres;
pinfo->vyres = pinfo->yres;
return 0;
}
static int __init platinumfb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "vmode:", 6)) {
int vmode = simple_strtoul(this_opt+6, NULL, 0);
if (vmode > 0 && vmode <= VMODE_MAX)
default_vmode = vmode;
} else if (!strncmp(this_opt, "cmode:", 6)) {
int depth = simple_strtoul(this_opt+6, NULL, 0);
switch (depth) {
case 0:
case 8:
default_cmode = CMODE_8;
break;
case 15:
case 16:
default_cmode = CMODE_16;
break;
case 24:
case 32:
default_cmode = CMODE_32;
break;
}
}
}
return 0;
}
static int __devinit platinumfb_probe(struct platform_device* odev)
{
struct device_node *dp = odev->dev.of_node;
struct fb_info *info;
struct fb_info_platinum *pinfo;
volatile __u8 *fbuffer;
int bank0, bank1, bank2, bank3, rc;
dev_info(&odev->dev, "Found Apple Platinum video hardware\n");
info = framebuffer_alloc(sizeof(*pinfo), &odev->dev);
if (info == NULL) {
dev_err(&odev->dev, "Failed to allocate fbdev !\n");
return -ENOMEM;
}
pinfo = info->par;
if (of_address_to_resource(dp, 0, &pinfo->rsrc_reg) ||
of_address_to_resource(dp, 1, &pinfo->rsrc_fb)) {
dev_err(&odev->dev, "Can't get resources\n");
framebuffer_release(info);
return -ENXIO;
}
dev_dbg(&odev->dev, " registers : 0x%llx...0x%llx\n",
(unsigned long long)pinfo->rsrc_reg.start,
(unsigned long long)pinfo->rsrc_reg.end);
dev_dbg(&odev->dev, " framebuffer: 0x%llx...0x%llx\n",
(unsigned long long)pinfo->rsrc_fb.start,
(unsigned long long)pinfo->rsrc_fb.end);
if (!request_mem_region(pinfo->rsrc_fb.start,
pinfo->rsrc_fb.end - pinfo->rsrc_fb.start + 1,
"platinumfb framebuffer")) {
printk(KERN_ERR "platinumfb: Can't request framebuffer !\n");
framebuffer_release(info);
return -ENXIO;
}
pinfo->frame_buffer_phys = pinfo->rsrc_fb.start;
pinfo->frame_buffer = __ioremap(pinfo->rsrc_fb.start, 0x400000,
_PAGE_WRITETHRU);
pinfo->base_frame_buffer = pinfo->frame_buffer;
pinfo->platinum_regs_phys = pinfo->rsrc_reg.start;
pinfo->platinum_regs = ioremap(pinfo->rsrc_reg.start, 0x1000);
pinfo->cmap_regs_phys = 0xf301b000;
request_mem_region(pinfo->cmap_regs_phys, 0x1000, "platinumfb cmap");
pinfo->cmap_regs = ioremap(pinfo->cmap_regs_phys, 0x1000);
out_be32(&pinfo->platinum_regs->reg[16].r, (unsigned)pinfo->frame_buffer_phys);
out_be32(&pinfo->platinum_regs->reg[20].r, 0x1011);
out_be32(&pinfo->platinum_regs->reg[24].r, 0);
fbuffer = pinfo->base_frame_buffer;
fbuffer[0x100000] = 0x34;
fbuffer[0x100008] = 0x0;
invalidate_cache(&fbuffer[0x100000]);
fbuffer[0x200000] = 0x56;
fbuffer[0x200008] = 0x0;
invalidate_cache(&fbuffer[0x200000]);
fbuffer[0x300000] = 0x78;
fbuffer[0x300008] = 0x0;
invalidate_cache(&fbuffer[0x300000]);
bank0 = 1;
bank1 = fbuffer[0x100000] == 0x34;
bank2 = fbuffer[0x200000] == 0x56;
bank3 = fbuffer[0x300000] == 0x78;
pinfo->total_vram = (bank0 + bank1 + bank2 + bank3) * 0x100000;
printk(KERN_INFO "platinumfb: Total VRAM = %dMB (%d%d%d%d)\n",
(unsigned int) (pinfo->total_vram / 1024 / 1024),
bank3, bank2, bank1, bank0);
out_8(&pinfo->cmap_regs->addr, 0x40);
pinfo->dactype = in_8(&pinfo->cmap_regs->d2);
switch (pinfo->dactype) {
case 0x3c:
pinfo->clktype = 1;
printk(KERN_INFO "platinumfb: DACula type 0x3c\n");
break;
case 0x84:
pinfo->clktype = 0;
printk(KERN_INFO "platinumfb: DACula type 0x84\n");
break;
default:
pinfo->clktype = 0;
printk(KERN_INFO "platinumfb: Unknown DACula type: %x\n", pinfo->dactype);
break;
}
dev_set_drvdata(&odev->dev, info);
rc = platinum_init_fb(info);
if (rc != 0) {
iounmap(pinfo->frame_buffer);
iounmap(pinfo->platinum_regs);
iounmap(pinfo->cmap_regs);
dev_set_drvdata(&odev->dev, NULL);
framebuffer_release(info);
}
return rc;
}
static int __devexit platinumfb_remove(struct platform_device* odev)
{
struct fb_info *info = dev_get_drvdata(&odev->dev);
struct fb_info_platinum *pinfo = info->par;
unregister_framebuffer (info);
iounmap(pinfo->frame_buffer);
iounmap(pinfo->platinum_regs);
iounmap(pinfo->cmap_regs);
release_mem_region(pinfo->rsrc_fb.start,
pinfo->rsrc_fb.end -
pinfo->rsrc_fb.start + 1);
release_mem_region(pinfo->cmap_regs_phys, 0x1000);
framebuffer_release(info);
return 0;
}
static int __init platinumfb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("platinumfb", &option))
return -ENODEV;
platinumfb_setup(option);
#endif
platform_driver_register(&platinum_driver);
return 0;
}
static void __exit platinumfb_exit(void)
{
platform_driver_unregister(&platinum_driver);
}
