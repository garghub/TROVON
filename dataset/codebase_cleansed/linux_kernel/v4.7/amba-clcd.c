static inline void clcdfb_sleep(unsigned int ms)
{
if (in_atomic()) {
mdelay(ms);
} else {
msleep(ms);
}
}
static inline void clcdfb_set_start(struct clcd_fb *fb)
{
unsigned long ustart = fb->fb.fix.smem_start;
unsigned long lstart;
ustart += fb->fb.var.yoffset * fb->fb.fix.line_length;
lstart = ustart + fb->fb.var.yres * fb->fb.fix.line_length / 2;
writel(ustart, fb->regs + CLCD_UBAS);
writel(lstart, fb->regs + CLCD_LBAS);
}
static void clcdfb_disable(struct clcd_fb *fb)
{
u32 val;
if (fb->board->disable)
fb->board->disable(fb);
val = readl(fb->regs + fb->off_cntl);
if (val & CNTL_LCDPWR) {
val &= ~CNTL_LCDPWR;
writel(val, fb->regs + fb->off_cntl);
clcdfb_sleep(20);
}
if (val & CNTL_LCDEN) {
val &= ~CNTL_LCDEN;
writel(val, fb->regs + fb->off_cntl);
}
if (fb->clk_enabled) {
fb->clk_enabled = false;
clk_disable(fb->clk);
}
}
static void clcdfb_enable(struct clcd_fb *fb, u32 cntl)
{
if (!fb->clk_enabled) {
fb->clk_enabled = true;
clk_enable(fb->clk);
}
cntl |= CNTL_LCDEN;
writel(cntl, fb->regs + fb->off_cntl);
clcdfb_sleep(20);
cntl |= CNTL_LCDPWR;
writel(cntl, fb->regs + fb->off_cntl);
if (fb->board->enable)
fb->board->enable(fb);
}
static int
clcdfb_set_bitfields(struct clcd_fb *fb, struct fb_var_screeninfo *var)
{
u32 caps;
int ret = 0;
if (fb->panel->caps && fb->board->caps)
caps = fb->panel->caps & fb->board->caps;
else {
caps = fb->panel->cntl & CNTL_BGR ?
CLCD_CAP_BGR : CLCD_CAP_RGB;
caps &= ~CLCD_CAP_444;
}
if (!(fb->panel->cntl & CNTL_LCDTFT))
caps &= ~CLCD_CAP_888;
memset(&var->transp, 0, sizeof(var->transp));
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
switch (var->bits_per_pixel) {
case 1:
case 2:
case 4:
case 8:
caps &= CLCD_CAP_5551;
if (!caps) {
ret = -EINVAL;
break;
}
var->red.length = var->bits_per_pixel;
var->red.offset = 0;
var->green.length = var->bits_per_pixel;
var->green.offset = 0;
var->blue.length = var->bits_per_pixel;
var->blue.offset = 0;
break;
case 16:
if (!(caps & (CLCD_CAP_444 | CLCD_CAP_5551 | CLCD_CAP_565))) {
ret = -EINVAL;
break;
}
if (var->green.length == 4 && caps & CLCD_CAP_444)
caps &= CLCD_CAP_444;
if (var->green.length == 5 && caps & CLCD_CAP_5551)
caps &= CLCD_CAP_5551;
else if (var->green.length == 6 && caps & CLCD_CAP_565)
caps &= CLCD_CAP_565;
else {
if (caps & CLCD_CAP_565) {
var->green.length = 6;
caps &= CLCD_CAP_565;
} else if (caps & CLCD_CAP_5551) {
var->green.length = 5;
caps &= CLCD_CAP_5551;
} else {
var->green.length = 4;
caps &= CLCD_CAP_444;
}
}
if (var->green.length >= 5) {
var->red.length = 5;
var->blue.length = 5;
} else {
var->red.length = 4;
var->blue.length = 4;
}
break;
case 32:
caps &= CLCD_CAP_888;
if (!caps) {
ret = -EINVAL;
break;
}
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
break;
default:
ret = -EINVAL;
break;
}
if (ret == 0 && var->bits_per_pixel >= 16) {
bool bgr, rgb;
bgr = caps & CLCD_CAP_BGR && var->blue.offset == 0;
rgb = caps & CLCD_CAP_RGB && var->red.offset == 0;
if (!bgr && !rgb)
bgr = caps & CLCD_CAP_BGR;
if (bgr) {
var->blue.offset = 0;
var->green.offset = var->blue.offset + var->blue.length;
var->red.offset = var->green.offset + var->green.length;
} else {
var->red.offset = 0;
var->green.offset = var->red.offset + var->red.length;
var->blue.offset = var->green.offset + var->green.length;
}
}
return ret;
}
static int clcdfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
int ret = -EINVAL;
if (fb->board->check)
ret = fb->board->check(fb, var);
if (ret == 0 &&
var->xres_virtual * var->bits_per_pixel / 8 *
var->yres_virtual > fb->fb.fix.smem_len)
ret = -EINVAL;
if (ret == 0)
ret = clcdfb_set_bitfields(fb, var);
return ret;
}
static int clcdfb_set_par(struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
struct clcd_regs regs;
fb->fb.fix.line_length = fb->fb.var.xres_virtual *
fb->fb.var.bits_per_pixel / 8;
if (fb->fb.var.bits_per_pixel <= 8)
fb->fb.fix.visual = FB_VISUAL_PSEUDOCOLOR;
else
fb->fb.fix.visual = FB_VISUAL_TRUECOLOR;
fb->board->decode(fb, &regs);
clcdfb_disable(fb);
writel(regs.tim0, fb->regs + CLCD_TIM0);
writel(regs.tim1, fb->regs + CLCD_TIM1);
writel(regs.tim2, fb->regs + CLCD_TIM2);
writel(regs.tim3, fb->regs + CLCD_TIM3);
clcdfb_set_start(fb);
clk_set_rate(fb->clk, (1000000000 / regs.pixclock) * 1000);
fb->clcd_cntl = regs.cntl;
clcdfb_enable(fb, regs.cntl);
#ifdef DEBUG
printk(KERN_INFO
"CLCD: Registers set to\n"
" %08x %08x %08x %08x\n"
" %08x %08x %08x %08x\n",
readl(fb->regs + CLCD_TIM0), readl(fb->regs + CLCD_TIM1),
readl(fb->regs + CLCD_TIM2), readl(fb->regs + CLCD_TIM3),
readl(fb->regs + CLCD_UBAS), readl(fb->regs + CLCD_LBAS),
readl(fb->regs + fb->off_ienb), readl(fb->regs + fb->off_cntl));
#endif
return 0;
}
static inline u32 convert_bitfield(int val, struct fb_bitfield *bf)
{
unsigned int mask = (1 << bf->length) - 1;
return (val >> (16 - bf->length) & mask) << bf->offset;
}
static int
clcdfb_setcolreg(unsigned int regno, unsigned int red, unsigned int green,
unsigned int blue, unsigned int transp, struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
if (regno < 16)
fb->cmap[regno] = convert_bitfield(transp, &fb->fb.var.transp) |
convert_bitfield(blue, &fb->fb.var.blue) |
convert_bitfield(green, &fb->fb.var.green) |
convert_bitfield(red, &fb->fb.var.red);
if (fb->fb.fix.visual == FB_VISUAL_PSEUDOCOLOR && regno < 256) {
int hw_reg = CLCD_PALETTE + ((regno * 2) & ~3);
u32 val, mask, newval;
newval = (red >> 11) & 0x001f;
newval |= (green >> 6) & 0x03e0;
newval |= (blue >> 1) & 0x7c00;
if (fb->clcd_cntl & CNTL_BEBO)
regno ^= 1;
if (regno & 1) {
newval <<= 16;
mask = 0x0000ffff;
} else {
mask = 0xffff0000;
}
val = readl(fb->regs + hw_reg) & mask;
writel(val | newval, fb->regs + hw_reg);
}
return regno > 255;
}
static int clcdfb_blank(int blank_mode, struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
if (blank_mode != 0) {
clcdfb_disable(fb);
} else {
clcdfb_enable(fb, fb->clcd_cntl);
}
return 0;
}
static int clcdfb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
struct clcd_fb *fb = to_clcd(info);
unsigned long len, off = vma->vm_pgoff << PAGE_SHIFT;
int ret = -EINVAL;
len = info->fix.smem_len;
if (off <= len && vma->vm_end - vma->vm_start <= len - off &&
fb->board->mmap)
ret = fb->board->mmap(fb, vma);
return ret;
}
static int clcdfb_register(struct clcd_fb *fb)
{
int ret;
if (amba_manf(fb->dev) == 0x41 && amba_part(fb->dev) == 0x111) {
fb->off_ienb = CLCD_PL111_IENB;
fb->off_cntl = CLCD_PL111_CNTL;
} else {
if (of_machine_is_compatible("arm,versatile-ab") ||
of_machine_is_compatible("arm,versatile-pb")) {
fb->off_ienb = CLCD_PL111_IENB;
fb->off_cntl = CLCD_PL111_CNTL;
} else {
fb->off_ienb = CLCD_PL110_IENB;
fb->off_cntl = CLCD_PL110_CNTL;
}
}
fb->clk = clk_get(&fb->dev->dev, NULL);
if (IS_ERR(fb->clk)) {
ret = PTR_ERR(fb->clk);
goto out;
}
ret = clk_prepare(fb->clk);
if (ret)
goto free_clk;
fb->fb.device = &fb->dev->dev;
fb->fb.fix.mmio_start = fb->dev->res.start;
fb->fb.fix.mmio_len = resource_size(&fb->dev->res);
fb->regs = ioremap(fb->fb.fix.mmio_start, fb->fb.fix.mmio_len);
if (!fb->regs) {
printk(KERN_ERR "CLCD: unable to remap registers\n");
ret = -ENOMEM;
goto clk_unprep;
}
fb->fb.fbops = &clcdfb_ops;
fb->fb.flags = FBINFO_FLAG_DEFAULT;
fb->fb.pseudo_palette = fb->cmap;
strncpy(fb->fb.fix.id, clcd_name, sizeof(fb->fb.fix.id));
fb->fb.fix.type = FB_TYPE_PACKED_PIXELS;
fb->fb.fix.type_aux = 0;
fb->fb.fix.xpanstep = 0;
fb->fb.fix.ypanstep = 0;
fb->fb.fix.ywrapstep = 0;
fb->fb.fix.accel = FB_ACCEL_NONE;
fb->fb.var.xres = fb->panel->mode.xres;
fb->fb.var.yres = fb->panel->mode.yres;
fb->fb.var.xres_virtual = fb->panel->mode.xres;
fb->fb.var.yres_virtual = fb->panel->mode.yres;
fb->fb.var.bits_per_pixel = fb->panel->bpp;
fb->fb.var.grayscale = fb->panel->grayscale;
fb->fb.var.pixclock = fb->panel->mode.pixclock;
fb->fb.var.left_margin = fb->panel->mode.left_margin;
fb->fb.var.right_margin = fb->panel->mode.right_margin;
fb->fb.var.upper_margin = fb->panel->mode.upper_margin;
fb->fb.var.lower_margin = fb->panel->mode.lower_margin;
fb->fb.var.hsync_len = fb->panel->mode.hsync_len;
fb->fb.var.vsync_len = fb->panel->mode.vsync_len;
fb->fb.var.sync = fb->panel->mode.sync;
fb->fb.var.vmode = fb->panel->mode.vmode;
fb->fb.var.activate = FB_ACTIVATE_NOW;
fb->fb.var.nonstd = 0;
fb->fb.var.height = fb->panel->height;
fb->fb.var.width = fb->panel->width;
fb->fb.var.accel_flags = 0;
fb->fb.monspecs.hfmin = 0;
fb->fb.monspecs.hfmax = 100000;
fb->fb.monspecs.vfmin = 0;
fb->fb.monspecs.vfmax = 400;
fb->fb.monspecs.dclkmin = 1000000;
fb->fb.monspecs.dclkmax = 100000000;
clcdfb_set_bitfields(fb, &fb->fb.var);
ret = fb_alloc_cmap(&fb->fb.cmap, 256, 0);
if (ret)
goto unmap;
writel(0, fb->regs + fb->off_ienb);
fb_set_var(&fb->fb, &fb->fb.var);
dev_info(&fb->dev->dev, "%s hardware, %s display\n",
fb->board->name, fb->panel->mode.name);
ret = register_framebuffer(&fb->fb);
if (ret == 0)
goto out;
printk(KERN_ERR "CLCD: cannot register framebuffer (%d)\n", ret);
fb_dealloc_cmap(&fb->fb.cmap);
unmap:
iounmap(fb->regs);
clk_unprep:
clk_unprepare(fb->clk);
free_clk:
clk_put(fb->clk);
out:
return ret;
}
static int clcdfb_of_get_dpi_panel_mode(struct device_node *node,
struct fb_videomode *mode)
{
int err;
struct display_timing timing;
struct videomode video;
err = of_get_display_timing(node, "panel-timing", &timing);
if (err)
return err;
videomode_from_timing(&timing, &video);
err = fb_videomode_from_videomode(&video, mode);
if (err)
return err;
return 0;
}
static int clcdfb_snprintf_mode(char *buf, int size, struct fb_videomode *mode)
{
return snprintf(buf, size, "%ux%u@%u", mode->xres, mode->yres,
mode->refresh);
}
static int clcdfb_of_get_mode(struct device *dev, struct device_node *endpoint,
struct fb_videomode *mode)
{
int err;
struct device_node *panel;
char *name;
int len;
panel = of_graph_get_remote_port_parent(endpoint);
if (!panel)
return -ENODEV;
if (of_device_is_compatible(panel, "panel-dpi"))
err = clcdfb_of_get_dpi_panel_mode(panel, mode);
else
err = -ENOENT;
if (err)
return err;
len = clcdfb_snprintf_mode(NULL, 0, mode);
name = devm_kzalloc(dev, len + 1, GFP_KERNEL);
if (!name)
return -ENOMEM;
clcdfb_snprintf_mode(name, len + 1, mode);
mode->name = name;
return 0;
}
static int clcdfb_of_init_tft_panel(struct clcd_fb *fb, u32 r0, u32 g0, u32 b0)
{
static struct {
unsigned int part;
u32 r0, g0, b0;
u32 caps;
} panels[] = {
{ 0x110, 1, 7, 13, CLCD_CAP_5551 },
{ 0x110, 0, 8, 16, CLCD_CAP_888 },
{ 0x111, 4, 14, 20, CLCD_CAP_444 },
{ 0x111, 3, 11, 19, CLCD_CAP_444 | CLCD_CAP_5551 },
{ 0x111, 3, 10, 19, CLCD_CAP_444 | CLCD_CAP_5551 |
CLCD_CAP_565 },
{ 0x111, 0, 8, 16, CLCD_CAP_444 | CLCD_CAP_5551 |
CLCD_CAP_565 | CLCD_CAP_888 },
};
int i;
fb->panel->tim2 = TIM2_BCD | TIM2_IPC;
fb->panel->cntl |= CNTL_LCDTFT | CNTL_LCDVCOMP(1);
fb->panel->caps = 0;
for (i = 0; i < ARRAY_SIZE(panels) && !fb->panel->caps; i++) {
if (amba_part(fb->dev) != panels[i].part)
continue;
if (g0 != panels[i].g0)
continue;
if (r0 == panels[i].r0 && b0 == panels[i].b0)
fb->panel->caps = panels[i].caps;
}
return fb->panel->caps ? 0 : -EINVAL;
}
static int clcdfb_of_init_display(struct clcd_fb *fb)
{
struct device_node *endpoint;
int err;
unsigned int bpp;
u32 max_bandwidth;
u32 tft_r0b0g0[3];
fb->panel = devm_kzalloc(&fb->dev->dev, sizeof(*fb->panel), GFP_KERNEL);
if (!fb->panel)
return -ENOMEM;
endpoint = of_graph_get_next_endpoint(fb->dev->dev.of_node, NULL);
if (!endpoint)
return -ENODEV;
err = clcdfb_of_get_mode(&fb->dev->dev, endpoint, &fb->panel->mode);
if (err)
return err;
err = of_property_read_u32(fb->dev->dev.of_node, "max-memory-bandwidth",
&max_bandwidth);
if (!err) {
bpp = max_bandwidth / (1000 / 8)
/ PICOS2KHZ(fb->panel->mode.pixclock);
bpp = rounddown_pow_of_two(bpp);
if (bpp > 32)
bpp = 32;
} else
bpp = 32;
fb->panel->bpp = bpp;
#ifdef CONFIG_CPU_BIG_ENDIAN
fb->panel->cntl |= CNTL_BEBO;
#endif
fb->panel->width = -1;
fb->panel->height = -1;
if (of_property_read_u32_array(endpoint,
"arm,pl11x,tft-r0g0b0-pads",
tft_r0b0g0, ARRAY_SIZE(tft_r0b0g0)) == 0)
return clcdfb_of_init_tft_panel(fb, tft_r0b0g0[0],
tft_r0b0g0[1], tft_r0b0g0[2]);
return -ENOENT;
}
static int clcdfb_of_vram_setup(struct clcd_fb *fb)
{
int err;
struct device_node *memory;
u64 size;
err = clcdfb_of_init_display(fb);
if (err)
return err;
memory = of_parse_phandle(fb->dev->dev.of_node, "memory-region", 0);
if (!memory)
return -ENODEV;
fb->fb.screen_base = of_iomap(memory, 0);
if (!fb->fb.screen_base)
return -ENOMEM;
fb->fb.fix.smem_start = of_translate_address(memory,
of_get_address(memory, 0, &size, NULL));
fb->fb.fix.smem_len = size;
return 0;
}
static int clcdfb_of_vram_mmap(struct clcd_fb *fb, struct vm_area_struct *vma)
{
unsigned long off, user_size, kernel_size;
off = vma->vm_pgoff << PAGE_SHIFT;
user_size = vma->vm_end - vma->vm_start;
kernel_size = fb->fb.fix.smem_len;
if (off >= kernel_size || user_size > (kernel_size - off))
return -ENXIO;
return remap_pfn_range(vma, vma->vm_start,
__phys_to_pfn(fb->fb.fix.smem_start) + vma->vm_pgoff,
user_size,
pgprot_writecombine(vma->vm_page_prot));
}
static void clcdfb_of_vram_remove(struct clcd_fb *fb)
{
iounmap(fb->fb.screen_base);
}
static int clcdfb_of_dma_setup(struct clcd_fb *fb)
{
unsigned long framesize;
dma_addr_t dma;
int err;
err = clcdfb_of_init_display(fb);
if (err)
return err;
framesize = fb->panel->mode.xres * fb->panel->mode.yres *
fb->panel->bpp / 8;
fb->fb.screen_base = dma_alloc_coherent(&fb->dev->dev, framesize,
&dma, GFP_KERNEL);
if (!fb->fb.screen_base)
return -ENOMEM;
fb->fb.fix.smem_start = dma;
fb->fb.fix.smem_len = framesize;
return 0;
}
static int clcdfb_of_dma_mmap(struct clcd_fb *fb, struct vm_area_struct *vma)
{
return dma_mmap_wc(&fb->dev->dev, vma, fb->fb.screen_base,
fb->fb.fix.smem_start, fb->fb.fix.smem_len);
}
static void clcdfb_of_dma_remove(struct clcd_fb *fb)
{
dma_free_coherent(&fb->dev->dev, fb->fb.fix.smem_len,
fb->fb.screen_base, fb->fb.fix.smem_start);
}
static struct clcd_board *clcdfb_of_get_board(struct amba_device *dev)
{
struct clcd_board *board = devm_kzalloc(&dev->dev, sizeof(*board),
GFP_KERNEL);
struct device_node *node = dev->dev.of_node;
if (!board)
return NULL;
board->name = of_node_full_name(node);
board->caps = CLCD_CAP_ALL;
board->check = clcdfb_check;
board->decode = clcdfb_decode;
if (of_find_property(node, "memory-region", NULL)) {
board->setup = clcdfb_of_vram_setup;
board->mmap = clcdfb_of_vram_mmap;
board->remove = clcdfb_of_vram_remove;
} else {
board->setup = clcdfb_of_dma_setup;
board->mmap = clcdfb_of_dma_mmap;
board->remove = clcdfb_of_dma_remove;
}
return board;
}
static struct clcd_board *clcdfb_of_get_board(struct amba_device *dev)
{
return NULL;
}
static int clcdfb_probe(struct amba_device *dev, const struct amba_id *id)
{
struct clcd_board *board = dev_get_platdata(&dev->dev);
struct clcd_fb *fb;
int ret;
if (!board)
board = clcdfb_of_get_board(dev);
if (!board)
return -EINVAL;
ret = dma_set_mask_and_coherent(&dev->dev, DMA_BIT_MASK(32));
if (ret)
goto out;
ret = amba_request_regions(dev, NULL);
if (ret) {
printk(KERN_ERR "CLCD: unable to reserve regs region\n");
goto out;
}
fb = kzalloc(sizeof(struct clcd_fb), GFP_KERNEL);
if (!fb) {
printk(KERN_INFO "CLCD: could not allocate new clcd_fb struct\n");
ret = -ENOMEM;
goto free_region;
}
fb->dev = dev;
fb->board = board;
dev_info(&fb->dev->dev, "PL%03x rev%u at 0x%08llx\n",
amba_part(dev), amba_rev(dev),
(unsigned long long)dev->res.start);
ret = fb->board->setup(fb);
if (ret)
goto free_fb;
ret = clcdfb_register(fb);
if (ret == 0) {
amba_set_drvdata(dev, fb);
goto out;
}
fb->board->remove(fb);
free_fb:
kfree(fb);
free_region:
amba_release_regions(dev);
out:
return ret;
}
static int clcdfb_remove(struct amba_device *dev)
{
struct clcd_fb *fb = amba_get_drvdata(dev);
clcdfb_disable(fb);
unregister_framebuffer(&fb->fb);
if (fb->fb.cmap.len)
fb_dealloc_cmap(&fb->fb.cmap);
iounmap(fb->regs);
clk_unprepare(fb->clk);
clk_put(fb->clk);
fb->board->remove(fb);
kfree(fb);
amba_release_regions(dev);
return 0;
}
static int __init amba_clcdfb_init(void)
{
if (fb_get_options("ambafb", NULL))
return -ENODEV;
return amba_driver_register(&clcd_driver);
}
static void __exit amba_clcdfb_exit(void)
{
amba_driver_unregister(&clcd_driver);
}
