static int au1100fb_fb_blank(int blank_mode, struct fb_info *fbi)
{
struct au1100fb_device *fbdev = to_au1100fb_device(fbi);
print_dbg("fb_blank %d %p", blank_mode, fbi);
switch (blank_mode) {
case VESA_NO_BLANKING:
fbdev->regs->lcd_control |= LCD_CONTROL_GO;
#ifdef CONFIG_MIPS_PB1100
if (drv_info.panel_idx == 1) {
au_writew(au_readw(PB1100_G_CONTROL)
| (PB1100_G_CONTROL_BL | PB1100_G_CONTROL_VDD),
PB1100_G_CONTROL);
}
#endif
au_sync();
break;
case VESA_VSYNC_SUSPEND:
case VESA_HSYNC_SUSPEND:
case VESA_POWERDOWN:
fbdev->regs->lcd_control &= ~LCD_CONTROL_GO;
#ifdef CONFIG_MIPS_PB1100
if (drv_info.panel_idx == 1) {
au_writew(au_readw(PB1100_G_CONTROL)
& ~(PB1100_G_CONTROL_BL | PB1100_G_CONTROL_VDD),
PB1100_G_CONTROL);
}
#endif
au_sync();
break;
default:
break;
}
return 0;
}
int au1100fb_setmode(struct au1100fb_device *fbdev)
{
struct fb_info *info = &fbdev->info;
u32 words;
int index;
if (!fbdev)
return -EINVAL;
if (panel_is_active(fbdev->panel) || panel_is_color(fbdev->panel)) {
if (info->var.bits_per_pixel <= 8) {
info->var.red.offset = 0;
info->var.red.length = info->var.bits_per_pixel;
info->var.red.msb_right = 0;
info->var.green.offset = 0;
info->var.green.length = info->var.bits_per_pixel;
info->var.green.msb_right = 0;
info->var.blue.offset = 0;
info->var.blue.length = info->var.bits_per_pixel;
info->var.blue.msb_right = 0;
info->var.transp.offset = 0;
info->var.transp.length = 0;
info->var.transp.msb_right = 0;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.line_length = info->var.xres_virtual /
(8/info->var.bits_per_pixel);
} else {
index = (fbdev->panel->control_base & LCD_CONTROL_SBPPF_MASK) >> LCD_CONTROL_SBPPF_BIT;
info->var.red = rgb_bitfields[index][0];
info->var.green = rgb_bitfields[index][1];
info->var.blue = rgb_bitfields[index][2];
info->var.transp = rgb_bitfields[index][3];
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->fix.line_length = info->var.xres_virtual << 1;
}
} else {
info->fix.visual = FB_VISUAL_MONO10;
info->fix.line_length = info->var.xres_virtual / 8;
}
info->screen_size = info->fix.line_length * info->var.yres_virtual;
info->var.rotate = ((fbdev->panel->control_base&LCD_CONTROL_SM_MASK) \
>> LCD_CONTROL_SM_BIT) * 90;
fbdev->regs->lcd_control = fbdev->panel->control_base;
fbdev->regs->lcd_horztiming = fbdev->panel->horztiming;
fbdev->regs->lcd_verttiming = fbdev->panel->verttiming;
fbdev->regs->lcd_clkcontrol = fbdev->panel->clkcontrol_base;
fbdev->regs->lcd_intenable = 0;
fbdev->regs->lcd_intstatus = 0;
fbdev->regs->lcd_dmaaddr0 = LCD_DMA_SA_N(fbdev->fb_phys);
if (panel_is_dual(fbdev->panel)) {
if (info->var.yres_virtual >= (info->var.yres << 1)) {
fbdev->regs->lcd_dmaaddr1 = LCD_DMA_SA_N(fbdev->fb_phys +
(info->fix.line_length *
(info->var.yres_virtual >> 1)));
} else {
fbdev->regs->lcd_dmaaddr1 = LCD_DMA_SA_N(fbdev->fb_phys);
}
}
words = info->fix.line_length / sizeof(u32);
if (!info->var.rotate || (info->var.rotate == 180)) {
words *= info->var.yres_virtual;
if (info->var.rotate ) {
words -= (words % 8);
}
}
fbdev->regs->lcd_words = LCD_WRD_WRDS_N(words);
fbdev->regs->lcd_pwmdiv = 0;
fbdev->regs->lcd_pwmhi = 0;
fbdev->regs->lcd_control |= LCD_CONTROL_GO;
mdelay(10);
au1100fb_fb_blank(VESA_NO_BLANKING, info);
return 0;
}
int au1100fb_fb_setcolreg(unsigned regno, unsigned red, unsigned green, unsigned blue, unsigned transp, struct fb_info *fbi)
{
struct au1100fb_device *fbdev;
u32 *palette;
u32 value;
fbdev = to_au1100fb_device(fbi);
palette = fbdev->regs->lcd_pallettebase;
if (regno > (AU1100_LCD_NBR_PALETTE_ENTRIES - 1))
return -EINVAL;
if (fbi->var.grayscale) {
red = green = blue =
(19595 * red + 38470 * green + 7471 * blue) >> 16;
}
if (fbi->fix.visual == FB_VISUAL_TRUECOLOR) {
if (regno > 16)
return -EINVAL;
palette = (u32*)fbi->pseudo_palette;
red >>= (16 - fbi->var.red.length);
green >>= (16 - fbi->var.green.length);
blue >>= (16 - fbi->var.blue.length);
value = (red << fbi->var.red.offset) |
(green << fbi->var.green.offset)|
(blue << fbi->var.blue.offset);
value &= 0xFFFF;
} else if (panel_is_active(fbdev->panel)) {
value = (red & 0xF800)|((green >> 5) & 0x07E0)|((blue >> 11) & 0x001F);
value &= 0xFFFF;
} else if (panel_is_color(fbdev->panel)) {
value = (((panel_swap_rgb(fbdev->panel) ? blue : red) >> 12) & 0x000F) |
((green >> 8) & 0x00F0) |
(((panel_swap_rgb(fbdev->panel) ? red : blue) >> 4) & 0x0F00);
value &= 0xFFF;
} else {
value = (green >> 12) & 0x000F;
value &= 0xF;
}
palette[regno] = value;
return 0;
}
int au1100fb_fb_pan_display(struct fb_var_screeninfo *var, struct fb_info *fbi)
{
struct au1100fb_device *fbdev;
int dy;
fbdev = to_au1100fb_device(fbi);
print_dbg("fb_pan_display %p %p", var, fbi);
if (!var || !fbdev) {
return -EINVAL;
}
if (var->xoffset - fbi->var.xoffset) {
return -EINVAL;
}
print_dbg("fb_pan_display 2 %p %p", var, fbi);
dy = var->yoffset - fbi->var.yoffset;
if (dy) {
u32 dmaaddr;
print_dbg("Panning screen of %d lines", dy);
dmaaddr = fbdev->regs->lcd_dmaaddr0;
dmaaddr += (fbi->fix.line_length * dy);
fbdev->regs->lcd_dmaaddr0 = LCD_DMA_SA_N(dmaaddr);
if (panel_is_dual(fbdev->panel)) {
dmaaddr = fbdev->regs->lcd_dmaaddr1;
dmaaddr += (fbi->fix.line_length * dy);
fbdev->regs->lcd_dmaaddr0 = LCD_DMA_SA_N(dmaaddr);
}
}
print_dbg("fb_pan_display 3 %p %p", var, fbi);
return 0;
}
void au1100fb_fb_rotate(struct fb_info *fbi, int angle)
{
struct au1100fb_device *fbdev = to_au1100fb_device(fbi);
print_dbg("fb_rotate %p %d", fbi, angle);
if (fbdev && (angle > 0) && !(angle % 90)) {
fbdev->regs->lcd_control &= ~LCD_CONTROL_GO;
fbdev->regs->lcd_control &= ~(LCD_CONTROL_SM_MASK);
fbdev->regs->lcd_control |= ((angle/90) << LCD_CONTROL_SM_BIT);
fbdev->regs->lcd_control |= LCD_CONTROL_GO;
}
}
int au1100fb_fb_mmap(struct fb_info *fbi, struct vm_area_struct *vma)
{
struct au1100fb_device *fbdev;
unsigned int len;
unsigned long start=0, off;
fbdev = to_au1100fb_device(fbi);
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
pgprot_val(vma->vm_page_prot) |= (6 << 9);
vma->vm_flags |= VM_IO;
if (io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
vma->vm_end - vma->vm_start,
vma->vm_page_prot)) {
return -EAGAIN;
}
return 0;
}
int au1100fb_fb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
if (nocursor)
return 0;
else
return -EINVAL;
}
static int __devinit au1100fb_drv_probe(struct platform_device *dev)
{
struct au1100fb_device *fbdev = NULL;
struct resource *regs_res;
unsigned long page;
u32 sys_clksrc;
if (!dev)
return -EINVAL;
if (!(fbdev = kzalloc(sizeof(struct au1100fb_device), GFP_KERNEL))) {
print_err("fail to allocate device private record");
return -ENOMEM;
}
fbdev->panel = &known_lcd_panels[drv_info.panel_idx];
platform_set_drvdata(dev, (void *)fbdev);
if (!(regs_res = platform_get_resource(to_platform_device(dev),
IORESOURCE_MEM, 0))) {
print_err("fail to retrieve registers resource");
return -EFAULT;
}
au1100fb_fix.mmio_start = regs_res->start;
au1100fb_fix.mmio_len = resource_size(regs_res);
if (!request_mem_region(au1100fb_fix.mmio_start, au1100fb_fix.mmio_len,
DRIVER_NAME)) {
print_err("fail to lock memory region at 0x%08lx",
au1100fb_fix.mmio_start);
return -EBUSY;
}
fbdev->regs = (struct au1100fb_regs*)KSEG1ADDR(au1100fb_fix.mmio_start);
print_dbg("Register memory map at %p", fbdev->regs);
print_dbg("phys=0x%08x, size=%d", fbdev->regs_phys, fbdev->regs_len);
fbdev->fb_len = fbdev->panel->xres * fbdev->panel->yres *
(fbdev->panel->bpp >> 3) * AU1100FB_NBR_VIDEO_BUFFERS;
fbdev->fb_mem = dma_alloc_coherent(dev, PAGE_ALIGN(fbdev->fb_len),
&fbdev->fb_phys, GFP_KERNEL);
if (!fbdev->fb_mem) {
print_err("fail to allocate frambuffer (size: %dK))",
fbdev->fb_len / 1024);
return -ENOMEM;
}
au1100fb_fix.smem_start = fbdev->fb_phys;
au1100fb_fix.smem_len = fbdev->fb_len;
for (page = (unsigned long)fbdev->fb_mem;
page < PAGE_ALIGN((unsigned long)fbdev->fb_mem + fbdev->fb_len);
page += PAGE_SIZE) {
#if CONFIG_DMA_NONCOHERENT
SetPageReserved(virt_to_page(CAC_ADDR(page)));
#else
SetPageReserved(virt_to_page(page));
#endif
}
print_dbg("Framebuffer memory map at %p", fbdev->fb_mem);
print_dbg("phys=0x%08x, size=%dK", fbdev->fb_phys, fbdev->fb_len / 1024);
sys_clksrc = au_readl(SYS_CLKSRC) & ~(SYS_CS_ML_MASK | SYS_CS_DL | SYS_CS_CL);
au_writel((sys_clksrc | (1 << SYS_CS_ML_BIT)), SYS_CLKSRC);
au1100fb_var.bits_per_pixel = fbdev->panel->bpp;
au1100fb_var.xres = fbdev->panel->xres;
au1100fb_var.xres_virtual = au1100fb_var.xres;
au1100fb_var.yres = fbdev->panel->yres;
au1100fb_var.yres_virtual = au1100fb_var.yres;
fbdev->info.screen_base = fbdev->fb_mem;
fbdev->info.fbops = &au1100fb_ops;
fbdev->info.fix = au1100fb_fix;
if (!(fbdev->info.pseudo_palette = kzalloc(sizeof(u32) * 16, GFP_KERNEL))) {
return -ENOMEM;
}
if (fb_alloc_cmap(&fbdev->info.cmap, AU1100_LCD_NBR_PALETTE_ENTRIES, 0) < 0) {
print_err("Fail to allocate colormap (%d entries)",
AU1100_LCD_NBR_PALETTE_ENTRIES);
kfree(fbdev->info.pseudo_palette);
return -EFAULT;
}
fbdev->info.var = au1100fb_var;
au1100fb_setmode(fbdev);
if (register_framebuffer(&fbdev->info) < 0) {
print_err("cannot register new framebuffer");
goto failed;
}
return 0;
failed:
if (fbdev->regs) {
release_mem_region(fbdev->regs_phys, fbdev->regs_len);
}
if (fbdev->fb_mem) {
dma_free_noncoherent(dev, fbdev->fb_len, fbdev->fb_mem, fbdev->fb_phys);
}
if (fbdev->info.cmap.len != 0) {
fb_dealloc_cmap(&fbdev->info.cmap);
}
kfree(fbdev);
platform_set_drvdata(dev, NULL);
return 0;
}
int au1100fb_drv_remove(struct platform_device *dev)
{
struct au1100fb_device *fbdev = NULL;
if (!dev)
return -ENODEV;
fbdev = (struct au1100fb_device *) platform_get_drvdata(dev);
#if !defined(CONFIG_FRAMEBUFFER_CONSOLE) && defined(CONFIG_LOGO)
au1100fb_fb_blank(VESA_POWERDOWN, &fbdev->info);
#endif
fbdev->regs->lcd_control &= ~LCD_CONTROL_GO;
unregister_framebuffer(&fbdev->info);
release_mem_region(fbdev->regs_phys, fbdev->regs_len);
dma_free_coherent(dev, PAGE_ALIGN(fbdev->fb_len), fbdev->fb_mem, fbdev->fb_phys);
fb_dealloc_cmap(&fbdev->info.cmap);
kfree(fbdev->info.pseudo_palette);
kfree((void*)fbdev);
return 0;
}
int au1100fb_drv_suspend(struct platform_device *dev, pm_message_t state)
{
struct au1100fb_device *fbdev = platform_get_drvdata(dev);
if (!fbdev)
return 0;
sys_clksrc = au_readl(SYS_CLKSRC);
au1100fb_fb_blank(VESA_POWERDOWN, &fbdev->info);
au_writel(sys_clksrc & ~SYS_CS_ML_MASK, SYS_CLKSRC);
memcpy(&fbregs, fbdev->regs, sizeof(struct au1100fb_regs));
return 0;
}
int au1100fb_drv_resume(struct platform_device *dev)
{
struct au1100fb_device *fbdev = platform_get_drvdata(dev);
if (!fbdev)
return 0;
memcpy(fbdev->regs, &fbregs, sizeof(struct au1100fb_regs));
au_writel(sys_clksrc, SYS_CLKSRC);
au1100fb_fb_blank(VESA_NO_BLANKING, &fbdev->info);
return 0;
}
int au1100fb_setup(char *options)
{
char* this_opt;
int num_panels = ARRAY_SIZE(known_lcd_panels);
char* mode = NULL;
int panel_idx = 0;
if (num_panels <= 0) {
print_err("No LCD panels supported by driver!");
return -EFAULT;
}
if (options) {
while ((this_opt = strsep(&options,",")) != NULL) {
if (!strncmp(this_opt, "panel:", 6)) {
int i;
this_opt += 6;
for (i = 0; i < num_panels; i++) {
if (!strncmp(this_opt,
known_lcd_panels[i].name,
strlen(this_opt))) {
panel_idx = i;
break;
}
}
if (i >= num_panels) {
print_warn("Panel %s not supported!", this_opt);
}
}
if (!strncmp(this_opt, "nocursor", 8)) {
this_opt += 8;
nocursor = 1;
print_info("Cursor disabled");
}
else if (isdigit(this_opt[0])) {
mode = kstrdup(this_opt, GFP_KERNEL);
if (!mode) {
print_err("memory allocation failed");
return -ENOMEM;
}
}
else {
print_warn("Unsupported option \"%s\"", this_opt);
}
}
}
drv_info.panel_idx = panel_idx;
drv_info.opt_mode = mode;
print_info("Panel=%s Mode=%s",
known_lcd_panels[drv_info.panel_idx].name,
drv_info.opt_mode ? drv_info.opt_mode : "default");
return 0;
}
int __init au1100fb_init(void)
{
char* options;
int ret;
print_info("" DRIVER_DESC "");
memset(&drv_info, 0, sizeof(drv_info));
if (fb_get_options(DRIVER_NAME, &options))
return -ENODEV;
ret = au1100fb_setup(options);
if (ret < 0) {
print_err("Fail to setup driver");
return ret;
}
return platform_driver_register(&au1100fb_driver);
}
void __exit au1100fb_cleanup(void)
{
platform_driver_unregister(&au1100fb_driver);
kfree(drv_info.opt_mode);
}
