static inline u32 set_hsync_pulse_width(struct mxsfb_info *host, unsigned val)
{
return (val & host->devdata->hs_wdth_mask) <<
host->devdata->hs_wdth_shift;
}
static inline u32 get_hsync_pulse_width(struct mxsfb_info *host, unsigned val)
{
return (val >> host->devdata->hs_wdth_shift) &
host->devdata->hs_wdth_mask;
}
static inline unsigned chan_to_field(unsigned chan, struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int mxsfb_check_var(struct fb_var_screeninfo *var,
struct fb_info *fb_info)
{
struct mxsfb_info *host = to_imxfb_host(fb_info);
const struct fb_bitfield *rgb = NULL;
if (var->xres < MIN_XRES)
var->xres = MIN_XRES;
if (var->yres < MIN_YRES)
var->yres = MIN_YRES;
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
switch (var->bits_per_pixel) {
case 16:
rgb = def_rgb565;
break;
case 32:
switch (host->ld_intf_width) {
case STMLCDIF_8BIT:
pr_debug("Unsupported LCD bus width mapping\n");
break;
case STMLCDIF_16BIT:
case STMLCDIF_18BIT:
case STMLCDIF_24BIT:
rgb = def_rgb888;
break;
}
break;
default:
pr_debug("Unsupported colour depth: %u\n", var->bits_per_pixel);
return -EINVAL;
}
var->red = rgb[RED];
var->green = rgb[GREEN];
var->blue = rgb[BLUE];
var->transp = rgb[TRANSP];
return 0;
}
static void mxsfb_enable_controller(struct fb_info *fb_info)
{
struct mxsfb_info *host = to_imxfb_host(fb_info);
u32 reg;
int ret;
dev_dbg(&host->pdev->dev, "%s\n", __func__);
if (host->reg_lcd) {
ret = regulator_enable(host->reg_lcd);
if (ret) {
dev_err(&host->pdev->dev,
"lcd regulator enable failed: %d\n", ret);
return;
}
}
clk_prepare_enable(host->clk);
clk_set_rate(host->clk, PICOS2KHZ(fb_info->var.pixclock) * 1000U);
writel(CTRL_DOTCLK_MODE, host->base + LCDC_CTRL + REG_SET);
reg = readl(host->base + LCDC_VDCTRL4);
reg |= VDCTRL4_SYNC_SIGNALS_ON;
writel(reg, host->base + LCDC_VDCTRL4);
writel(CTRL_RUN, host->base + LCDC_CTRL + REG_SET);
host->enabled = 1;
}
static void mxsfb_disable_controller(struct fb_info *fb_info)
{
struct mxsfb_info *host = to_imxfb_host(fb_info);
unsigned loop;
u32 reg;
int ret;
dev_dbg(&host->pdev->dev, "%s\n", __func__);
writel(CTRL_DOTCLK_MODE, host->base + LCDC_CTRL + REG_CLR);
loop = 1000;
while (loop) {
reg = readl(host->base + LCDC_CTRL);
if (!(reg & CTRL_RUN))
break;
loop--;
}
reg = readl(host->base + LCDC_VDCTRL4);
writel(reg & ~VDCTRL4_SYNC_SIGNALS_ON, host->base + LCDC_VDCTRL4);
clk_disable_unprepare(host->clk);
host->enabled = 0;
if (host->reg_lcd) {
ret = regulator_disable(host->reg_lcd);
if (ret)
dev_err(&host->pdev->dev,
"lcd regulator disable failed: %d\n", ret);
}
}
static int mxsfb_set_par(struct fb_info *fb_info)
{
struct mxsfb_info *host = to_imxfb_host(fb_info);
u32 ctrl, vdctrl0, vdctrl4;
int line_size, fb_size;
int reenable = 0;
line_size = fb_info->var.xres * (fb_info->var.bits_per_pixel >> 3);
fb_size = fb_info->var.yres_virtual * line_size;
if (fb_size > fb_info->fix.smem_len)
return -ENOMEM;
fb_info->fix.line_length = line_size;
if (host->enabled) {
reenable = 1;
mxsfb_disable_controller(fb_info);
}
writel(CTRL1_FIFO_CLEAR, host->base + LCDC_CTRL1 + REG_SET);
ctrl = CTRL_BYPASS_COUNT | CTRL_MASTER |
CTRL_SET_BUS_WIDTH(host->ld_intf_width);
switch (fb_info->var.bits_per_pixel) {
case 16:
dev_dbg(&host->pdev->dev, "Setting up RGB565 mode\n");
ctrl |= CTRL_SET_WORD_LENGTH(0);
writel(CTRL1_SET_BYTE_PACKAGING(0xf), host->base + LCDC_CTRL1);
break;
case 32:
dev_dbg(&host->pdev->dev, "Setting up RGB888/666 mode\n");
ctrl |= CTRL_SET_WORD_LENGTH(3);
switch (host->ld_intf_width) {
case STMLCDIF_8BIT:
dev_dbg(&host->pdev->dev,
"Unsupported LCD bus width mapping\n");
return -EINVAL;
case STMLCDIF_16BIT:
case STMLCDIF_18BIT:
case STMLCDIF_24BIT:
break;
}
writel(CTRL1_SET_BYTE_PACKAGING(0x7), host->base + LCDC_CTRL1);
break;
default:
dev_dbg(&host->pdev->dev, "Unhandled color depth of %u\n",
fb_info->var.bits_per_pixel);
return -EINVAL;
}
writel(ctrl, host->base + LCDC_CTRL);
writel(TRANSFER_COUNT_SET_VCOUNT(fb_info->var.yres) |
TRANSFER_COUNT_SET_HCOUNT(fb_info->var.xres),
host->base + host->devdata->transfer_count);
vdctrl0 = VDCTRL0_ENABLE_PRESENT |
VDCTRL0_VSYNC_PERIOD_UNIT |
VDCTRL0_VSYNC_PULSE_WIDTH_UNIT |
VDCTRL0_SET_VSYNC_PULSE_WIDTH(fb_info->var.vsync_len);
if (fb_info->var.sync & FB_SYNC_HOR_HIGH_ACT)
vdctrl0 |= VDCTRL0_HSYNC_ACT_HIGH;
if (fb_info->var.sync & FB_SYNC_VERT_HIGH_ACT)
vdctrl0 |= VDCTRL0_VSYNC_ACT_HIGH;
if (host->sync & MXSFB_SYNC_DATA_ENABLE_HIGH_ACT)
vdctrl0 |= VDCTRL0_ENABLE_ACT_HIGH;
if (host->sync & MXSFB_SYNC_DOTCLK_FALLING_ACT)
vdctrl0 |= VDCTRL0_DOTCLK_ACT_FALLING;
writel(vdctrl0, host->base + LCDC_VDCTRL0);
writel(fb_info->var.upper_margin + fb_info->var.vsync_len +
fb_info->var.lower_margin + fb_info->var.yres,
host->base + LCDC_VDCTRL1);
writel(set_hsync_pulse_width(host, fb_info->var.hsync_len) |
VDCTRL2_SET_HSYNC_PERIOD(fb_info->var.left_margin +
fb_info->var.hsync_len + fb_info->var.right_margin +
fb_info->var.xres),
host->base + LCDC_VDCTRL2);
writel(SET_HOR_WAIT_CNT(fb_info->var.left_margin +
fb_info->var.hsync_len) |
SET_VERT_WAIT_CNT(fb_info->var.upper_margin +
fb_info->var.vsync_len),
host->base + LCDC_VDCTRL3);
vdctrl4 = SET_DOTCLK_H_VALID_DATA_CNT(fb_info->var.xres);
if (mxsfb_is_v4(host))
vdctrl4 |= VDCTRL4_SET_DOTCLK_DLY(host->dotclk_delay);
writel(vdctrl4, host->base + LCDC_VDCTRL4);
writel(fb_info->fix.smem_start +
fb_info->fix.line_length * fb_info->var.yoffset,
host->base + host->devdata->next_buf);
if (reenable)
mxsfb_enable_controller(fb_info);
return 0;
}
static int mxsfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *fb_info)
{
unsigned int val;
int ret = -EINVAL;
if (fb_info->var.grayscale)
red = green = blue = (19595 * red + 38470 * green +
7471 * blue) >> 16;
switch (fb_info->fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
u32 *pal = fb_info->pseudo_palette;
val = chan_to_field(red, &fb_info->var.red);
val |= chan_to_field(green, &fb_info->var.green);
val |= chan_to_field(blue, &fb_info->var.blue);
pal[regno] = val;
ret = 0;
}
break;
case FB_VISUAL_STATIC_PSEUDOCOLOR:
case FB_VISUAL_PSEUDOCOLOR:
break;
}
return ret;
}
static int mxsfb_blank(int blank, struct fb_info *fb_info)
{
struct mxsfb_info *host = to_imxfb_host(fb_info);
switch (blank) {
case FB_BLANK_POWERDOWN:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_NORMAL:
if (host->enabled)
mxsfb_disable_controller(fb_info);
break;
case FB_BLANK_UNBLANK:
if (!host->enabled)
mxsfb_enable_controller(fb_info);
break;
}
return 0;
}
static int mxsfb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *fb_info)
{
struct mxsfb_info *host = to_imxfb_host(fb_info);
unsigned offset;
if (var->xoffset != 0)
return -EINVAL;
offset = fb_info->fix.line_length * var->yoffset;
writel(fb_info->fix.smem_start + offset,
host->base + host->devdata->next_buf);
return 0;
}
static int mxsfb_restore_mode(struct mxsfb_info *host)
{
struct fb_info *fb_info = &host->fb_info;
unsigned line_count;
unsigned period;
unsigned long pa, fbsize;
int bits_per_pixel, ofs;
u32 transfer_count, vdctrl0, vdctrl2, vdctrl3, vdctrl4, ctrl;
struct fb_videomode vmode;
ctrl = readl(host->base + LCDC_CTRL);
if (!(ctrl & CTRL_RUN))
return -EINVAL;
vdctrl0 = readl(host->base + LCDC_VDCTRL0);
vdctrl2 = readl(host->base + LCDC_VDCTRL2);
vdctrl3 = readl(host->base + LCDC_VDCTRL3);
vdctrl4 = readl(host->base + LCDC_VDCTRL4);
transfer_count = readl(host->base + host->devdata->transfer_count);
vmode.xres = TRANSFER_COUNT_GET_HCOUNT(transfer_count);
vmode.yres = TRANSFER_COUNT_GET_VCOUNT(transfer_count);
switch (CTRL_GET_WORD_LENGTH(ctrl)) {
case 0:
bits_per_pixel = 16;
break;
case 3:
bits_per_pixel = 32;
case 1:
default:
return -EINVAL;
}
fb_info->var.bits_per_pixel = bits_per_pixel;
vmode.pixclock = KHZ2PICOS(clk_get_rate(host->clk) / 1000U);
vmode.hsync_len = get_hsync_pulse_width(host, vdctrl2);
vmode.left_margin = GET_HOR_WAIT_CNT(vdctrl3) - vmode.hsync_len;
vmode.right_margin = VDCTRL2_GET_HSYNC_PERIOD(vdctrl2) - vmode.hsync_len -
vmode.left_margin - vmode.xres;
vmode.vsync_len = VDCTRL0_GET_VSYNC_PULSE_WIDTH(vdctrl0);
period = readl(host->base + LCDC_VDCTRL1);
vmode.upper_margin = GET_VERT_WAIT_CNT(vdctrl3) - vmode.vsync_len;
vmode.lower_margin = period - vmode.vsync_len - vmode.upper_margin - vmode.yres;
vmode.vmode = FB_VMODE_NONINTERLACED;
vmode.sync = 0;
if (vdctrl0 & VDCTRL0_HSYNC_ACT_HIGH)
vmode.sync |= FB_SYNC_HOR_HIGH_ACT;
if (vdctrl0 & VDCTRL0_VSYNC_ACT_HIGH)
vmode.sync |= FB_SYNC_VERT_HIGH_ACT;
pr_debug("Reconstructed video mode:\n");
pr_debug("%dx%d, hsync: %u left: %u, right: %u, vsync: %u, upper: %u, lower: %u\n",
vmode.xres, vmode.yres,
vmode.hsync_len, vmode.left_margin, vmode.right_margin,
vmode.vsync_len, vmode.upper_margin, vmode.lower_margin);
pr_debug("pixclk: %ldkHz\n", PICOS2KHZ(vmode.pixclock));
fb_add_videomode(&vmode, &fb_info->modelist);
host->ld_intf_width = CTRL_GET_BUS_WIDTH(ctrl);
host->dotclk_delay = VDCTRL4_GET_DOTCLK_DLY(vdctrl4);
fb_info->fix.line_length = vmode.xres * (bits_per_pixel >> 3);
pa = readl(host->base + host->devdata->cur_buf);
fbsize = fb_info->fix.line_length * vmode.yres;
if (pa < fb_info->fix.smem_start)
return -EINVAL;
if (pa + fbsize > fb_info->fix.smem_start + fb_info->fix.smem_len)
return -EINVAL;
ofs = pa - fb_info->fix.smem_start;
if (ofs) {
memmove(fb_info->screen_base, fb_info->screen_base + ofs, fbsize);
writel(fb_info->fix.smem_start, host->base + host->devdata->next_buf);
}
line_count = fb_info->fix.smem_len / fb_info->fix.line_length;
fb_info->fix.ypanstep = 1;
clk_prepare_enable(host->clk);
host->enabled = 1;
return 0;
}
static int mxsfb_init_fbinfo_dt(struct mxsfb_info *host)
{
struct fb_info *fb_info = &host->fb_info;
struct fb_var_screeninfo *var = &fb_info->var;
struct device *dev = &host->pdev->dev;
struct device_node *np = host->pdev->dev.of_node;
struct device_node *display_np;
struct device_node *timings_np;
struct display_timings *timings;
u32 width;
int i;
int ret = 0;
display_np = of_parse_phandle(np, "display", 0);
if (!display_np) {
dev_err(dev, "failed to find display phandle\n");
return -ENOENT;
}
ret = of_property_read_u32(display_np, "bus-width", &width);
if (ret < 0) {
dev_err(dev, "failed to get property bus-width\n");
goto put_display_node;
}
switch (width) {
case 8:
host->ld_intf_width = STMLCDIF_8BIT;
break;
case 16:
host->ld_intf_width = STMLCDIF_16BIT;
break;
case 18:
host->ld_intf_width = STMLCDIF_18BIT;
break;
case 24:
host->ld_intf_width = STMLCDIF_24BIT;
break;
default:
dev_err(dev, "invalid bus-width value\n");
ret = -EINVAL;
goto put_display_node;
}
ret = of_property_read_u32(display_np, "bits-per-pixel",
&var->bits_per_pixel);
if (ret < 0) {
dev_err(dev, "failed to get property bits-per-pixel\n");
goto put_display_node;
}
timings = of_get_display_timings(display_np);
if (!timings) {
dev_err(dev, "failed to get display timings\n");
ret = -ENOENT;
goto put_display_node;
}
timings_np = of_find_node_by_name(display_np,
"display-timings");
if (!timings_np) {
dev_err(dev, "failed to find display-timings node\n");
ret = -ENOENT;
goto put_display_node;
}
for (i = 0; i < of_get_child_count(timings_np); i++) {
struct videomode vm;
struct fb_videomode fb_vm;
ret = videomode_from_timings(timings, &vm, i);
if (ret < 0)
goto put_timings_node;
ret = fb_videomode_from_videomode(&vm, &fb_vm);
if (ret < 0)
goto put_timings_node;
if (vm.flags & DISPLAY_FLAGS_DE_HIGH)
host->sync |= MXSFB_SYNC_DATA_ENABLE_HIGH_ACT;
if (vm.flags & DISPLAY_FLAGS_PIXDATA_NEGEDGE)
host->sync |= MXSFB_SYNC_DOTCLK_FALLING_ACT;
fb_add_videomode(&fb_vm, &fb_info->modelist);
}
put_timings_node:
of_node_put(timings_np);
put_display_node:
of_node_put(display_np);
return ret;
}
static int mxsfb_init_fbinfo(struct mxsfb_info *host)
{
struct fb_info *fb_info = &host->fb_info;
struct fb_var_screeninfo *var = &fb_info->var;
dma_addr_t fb_phys;
void *fb_virt;
unsigned fb_size;
int ret;
fb_info->fbops = &mxsfb_ops;
fb_info->flags = FBINFO_FLAG_DEFAULT | FBINFO_READS_FAST;
strlcpy(fb_info->fix.id, "mxs", sizeof(fb_info->fix.id));
fb_info->fix.type = FB_TYPE_PACKED_PIXELS;
fb_info->fix.ypanstep = 1;
fb_info->fix.visual = FB_VISUAL_TRUECOLOR,
fb_info->fix.accel = FB_ACCEL_NONE;
ret = mxsfb_init_fbinfo_dt(host);
if (ret)
return ret;
var->nonstd = 0;
var->activate = FB_ACTIVATE_NOW;
var->accel_flags = 0;
var->vmode = FB_VMODE_NONINTERLACED;
fb_size = SZ_2M;
fb_virt = alloc_pages_exact(fb_size, GFP_DMA);
if (!fb_virt)
return -ENOMEM;
fb_phys = virt_to_phys(fb_virt);
fb_info->fix.smem_start = fb_phys;
fb_info->screen_base = fb_virt;
fb_info->screen_size = fb_info->fix.smem_len = fb_size;
if (mxsfb_restore_mode(host))
memset(fb_virt, 0, fb_size);
return 0;
}
static void mxsfb_free_videomem(struct mxsfb_info *host)
{
struct fb_info *fb_info = &host->fb_info;
free_pages_exact(fb_info->screen_base, fb_info->fix.smem_len);
}
static int mxsfb_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mxsfb_dt_ids, &pdev->dev);
struct resource *res;
struct mxsfb_info *host;
struct fb_info *fb_info;
struct fb_modelist *modelist;
struct pinctrl *pinctrl;
int ret;
if (of_id)
pdev->id_entry = of_id->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Cannot get memory IO resource\n");
return -ENODEV;
}
fb_info = framebuffer_alloc(sizeof(struct mxsfb_info), &pdev->dev);
if (!fb_info) {
dev_err(&pdev->dev, "Failed to allocate fbdev\n");
return -ENOMEM;
}
host = to_imxfb_host(fb_info);
host->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->base)) {
ret = PTR_ERR(host->base);
goto fb_release;
}
host->pdev = pdev;
platform_set_drvdata(pdev, host);
host->devdata = &mxsfb_devdata[pdev->id_entry->driver_data];
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
ret = PTR_ERR(pinctrl);
goto fb_release;
}
host->clk = devm_clk_get(&host->pdev->dev, NULL);
if (IS_ERR(host->clk)) {
ret = PTR_ERR(host->clk);
goto fb_release;
}
host->reg_lcd = devm_regulator_get(&pdev->dev, "lcd");
if (IS_ERR(host->reg_lcd))
host->reg_lcd = NULL;
fb_info->pseudo_palette = devm_kzalloc(&pdev->dev, sizeof(u32) * 16,
GFP_KERNEL);
if (!fb_info->pseudo_palette) {
ret = -ENOMEM;
goto fb_release;
}
INIT_LIST_HEAD(&fb_info->modelist);
ret = mxsfb_init_fbinfo(host);
if (ret != 0)
goto fb_release;
modelist = list_first_entry(&fb_info->modelist,
struct fb_modelist, list);
fb_videomode_to_var(&fb_info->var, &modelist->mode);
mxsfb_check_var(&fb_info->var, fb_info);
platform_set_drvdata(pdev, fb_info);
ret = register_framebuffer(fb_info);
if (ret != 0) {
dev_err(&pdev->dev,"Failed to register framebuffer\n");
goto fb_destroy;
}
if (!host->enabled) {
writel(0, host->base + LCDC_CTRL);
mxsfb_set_par(fb_info);
mxsfb_enable_controller(fb_info);
}
dev_info(&pdev->dev, "initialized\n");
return 0;
fb_destroy:
if (host->enabled)
clk_disable_unprepare(host->clk);
fb_destroy_modelist(&fb_info->modelist);
fb_release:
framebuffer_release(fb_info);
return ret;
}
static int mxsfb_remove(struct platform_device *pdev)
{
struct fb_info *fb_info = platform_get_drvdata(pdev);
struct mxsfb_info *host = to_imxfb_host(fb_info);
if (host->enabled)
mxsfb_disable_controller(fb_info);
unregister_framebuffer(fb_info);
mxsfb_free_videomem(host);
framebuffer_release(fb_info);
return 0;
}
static void mxsfb_shutdown(struct platform_device *pdev)
{
struct fb_info *fb_info = platform_get_drvdata(pdev);
struct mxsfb_info *host = to_imxfb_host(fb_info);
writel(CTRL_RUN, host->base + LCDC_CTRL + REG_CLR);
}
